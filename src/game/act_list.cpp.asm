#include "common.h"
#include "act_list.h"

RGE_Action_List::RGE_Action_List(RGE_Action_Object* param_1) {
    /* TODO: Stub */
    //                              undefined __thiscall RGE_Action_List(RGE_Action_List * this, RGE_Act
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Action_Lis    ECX:4 (auto)   this
    //              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00403ea2(R)  
    //                               ??0RGE_Action_List@@QAE@PAVRGE_Action_Object@@@Z             XREF[3]:     create_action_list:004061d6(c), 
    //                               RGE_Action_List::RGE_Action_List                                          create_action_list:00407709(c), 
    //                                                                                                         TRIBE_Action_List:004d0158(c)  
    //                              act_list.cpp:41 (2)
    //         00403ea0     MOV        EAX,this
    //                              act_list.cpp:42 (13)
    //         00403ea2     MOV        this,dword ptr [ESP + param_1]
    //         00403ea6     MOV        dword ptr [EAX],RGE_Action_List::`vftable'       = 00403fc0
    //         00403eac     MOV        dword ptr [EAX + 0x4],this
    //                              act_list.cpp:43 (7)
    //         00403eaf     MOV        dword ptr [EAX + 0x8],0x0
    //                              act_list.cpp:44 (3)
    //         00403eb6     RET        0x4
    //         00403eb9     ??         90h
    //         00403eba     NOP
    //         00403ebb     NOP
    //         00403ebc     NOP
    //         00403ebd     NOP
    //         00403ebe     NOP
    //         00403ebf     NOP
}

RGE_Action_List::~RGE_Action_List() {
    /* TODO: Stub */
    //                              void __thiscall ~RGE_Action_List(RGE_Action_List * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Lis    ECX:4 (auto)   this
    //                               ??1RGE_Action_List@@QAE@XZ                                   XREF[3]:     ~RGE_Action_Object:00406048(c), 
    //                               RGE_Action_List::~RGE_Action_List                                         ~RGE_Action:00407513(c), 
    //                                                                                                         ~TRIBE_Building_Object:004c82e4(c)
    //                              act_list.cpp:49 (6)
    //         00403ec0     MOV        dword ptr [this->_padding_],RGE_Action_List::`   = 00403fc0
    //                              act_list.cpp:50 (5)
    //         00403ec6     JMP        RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
    //         00403ecb     ??         90h
    //         00403ecc     NOP
    //         00403ecd     NOP
    //         00403ece     NOP
    //         00403ecf     NOP
}

void RGE_Action_List::load(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall load(RGE_Action_List * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Lis    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00403ee3(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00403ee9(*), 00403ef6(R)  
    //              short             Stack[-0x8]:2  action_type
    //                               ?load@RGE_Action_List@@QAEXH@Z                               XREF[3]:     setup:0040618a(c), 
    //                               RGE_Action_List::load                                                     setup:00407645(c), 
    //                                                                                                         setup:004c85b2(c)  
    //                              act_list.cpp:56 (7)
    //         00403ed0     PUSH       this
    //         00403ed1     PUSH       EBX
    //         00403ed2     PUSH       EBP
    //         00403ed3     PUSH       ESI
    //         00403ed4     PUSH       EDI
    //         00403ed5     MOV        EDI,this
    //                              act_list.cpp:62 (7)
    //         00403ed7     MOV        EAX,dword ptr [EDI + 0x8]
    //         00403eda     TEST       EAX,EAX
    //         00403edc     JZ         LAB_00403ee3
    //                              act_list.cpp:63 (5)
    //         00403ede     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
    //                               LAB_00403ee3                                                 XREF[1]:     00403edc(j)  
    //                              act_list.cpp:65 (6)
    //         00403ee3     MOV        EBP,dword ptr [ESP + param_1]
    //         00403ee7     XOR        EBX,EBX
    //                               LAB_00403ee9                                                 XREF[2]:     00403f2a(j), 00403f31(j)  
    //                              act_list.cpp:69 (13)
    //         00403ee9     LEA        EAX=>local_4,[ESP + 0x10]
    //         00403eed     PUSH       0x2
    //         00403eef     PUSH       EAX=>DAT_fffffff8
    //         00403ef0     PUSH       EBP=>DAT_fffffff4
    //         00403ef1     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              act_list.cpp:70 (12)
    //         00403ef6     MOV        EAX,dword ptr [ESP + local_4]
    //         00403efa     ADD        ESP,0xc
    //         00403efd     TEST       AX,AX
    //         00403f00     JZ         LAB_00403f33
    //                              act_list.cpp:73 (8)
    //         00403f02     MOV        EDX,dword ptr [EDI]
    //         00403f04     PUSH       EAX
    //         00403f05     PUSH       EBP
    //         00403f06     MOV        this,EDI
    //         00403f08     CALL       dword ptr [EDX]
    //                              act_list.cpp:75 (14)
    //         00403f0a     PUSH       0x8
    //         00403f0c     PUSH       offset DAT_fffffff8
    //         00403f0e     MOV        ESI,EAX
    //         00403f10     CALL       calloc                                           undefined calloc()
    //         00403f15     ADD        ESP,0x8
    //                              act_list.cpp:76 (2)
    //         00403f18     MOV        dword ptr [EAX],ESI
    //                              act_list.cpp:79 (11)
    //         00403f1a     TEST       EBX,EBX
    //         00403f1c     MOV        dword ptr [EAX + 0x4],0x0
    //         00403f23     JZ         LAB_00403f2c
    //                              act_list.cpp:80 (3)
    //         00403f25     MOV        dword ptr [EBX + 0x4],EAX
    //                              act_list.cpp:83 (4)
    //         00403f28     MOV        EBX,EAX
    //         00403f2a     JMP        LAB_00403ee9
    //                               LAB_00403f2c                                                 XREF[1]:     00403f23(j)  
    //                              act_list.cpp:82 (3)
    //         00403f2c     MOV        dword ptr [EDI + 0x8],EAX
    //                              act_list.cpp:83 (4)
    //         00403f2f     MOV        EBX,EAX
    //         00403f31     JMP        LAB_00403ee9
    //                               LAB_00403f33                                                 XREF[1]:     00403f00(j)  
    //                              act_list.cpp:85 (8)
    //         00403f33     POP        EDI
    //         00403f34     POP        ESI
    //         00403f35     POP        EBP
    //         00403f36     POP        EBX
    //         00403f37     POP        this
    //         00403f38     RET        0x4
    //         00403f3b     ??         90h
    //         00403f3c     NOP
    //         00403f3d     NOP
    //         00403f3e     NOP
    //         00403f3f     NOP
    return;
}

void RGE_Action_List::rehook() {
    /* TODO: Stub */
    //                              void __thiscall rehook(RGE_Action_List * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Lis    ECX:4 (auto)   this
    //                               ?rehook@RGE_Action_List@@QAEXXZ                              XREF[3]:     rehook:0040620e(c), 
    //                               RGE_Action_List::rehook                                                   rehook:00407784(c), 
    //                                                                                                         rehook:004c8a6e(c)  
    //                              act_list.cpp:89 (1)
    //         00403f40     PUSH       ESI
    //                              act_list.cpp:92 (3)
    //         00403f41     MOV        ESI,dword ptr [ECX + this->list]
    //                              act_list.cpp:93 (4)
    //         00403f44     TEST       ESI,ESI
    //         00403f46     JZ         LAB_00403f56
    //                               LAB_00403f48                                                 XREF[1]:     00403f54(j)  
    //                              act_list.cpp:95 (7)
    //         00403f48     MOV        this,dword ptr [ESI]
    //         00403f4a     MOV        EAX,dword ptr [this->_padding_]
    //         00403f4c     CALL       dword ptr [EAX + 0x10]
    //                              act_list.cpp:96 (7)
    //         00403f4f     MOV        ESI,dword ptr [ESI + 0x4]
    //         00403f52     TEST       ESI,ESI
    //         00403f54     JNZ        LAB_00403f48
    //                               LAB_00403f56                                                 XREF[1]:     00403f46(j)  
    //                              act_list.cpp:98 (2)
    //         00403f56     POP        ESI
    //         00403f57     RET
    //         00403f58     ??         90h
    //         00403f59     NOP
    //         00403f5a     NOP
    //         00403f5b     NOP
    //         00403f5c     NOP
    //         00403f5d     NOP
    //         00403f5e     NOP
    //         00403f5f     NOP
    return;
}

void RGE_Action_List::save(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall save(RGE_Action_List * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Lis    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[3]:     00403f65(R), 00403f7c(*), 00403f84(W)  
    //                               ?save@RGE_Action_List@@QAEXH@Z                               XREF[3]:     save:00406259(c), 
    //                               RGE_Action_List::save                                                     save:00407895(c), 
    //                                                                                                         save:004c8c9e(c)  
    //                              act_list.cpp:103 (1)
    //         00403f60     PUSH       ESI
    //                              act_list.cpp:107 (4)
    //         00403f61     MOV        ESI,dword ptr [ECX + this->list]
    //         00403f64     PUSH       EDI
    //                              act_list.cpp:108 (8)
    //         00403f65     MOV        EDI,dword ptr [ESP + param_1]
    //         00403f69     TEST       ESI,ESI
    //         00403f6b     JZ         LAB_00403f7c
    //                               LAB_00403f6d                                                 XREF[1]:     00403f7a(j)  
    //                              act_list.cpp:110 (8)
    //         00403f6d     MOV        this,dword ptr [ESI]
    //         00403f6f     PUSH       EDI
    //         00403f70     MOV        EAX,dword ptr [this->_padding_]
    //         00403f72     CALL       dword ptr [EAX + 0x14]
    //                              act_list.cpp:111 (7)
    //         00403f75     MOV        ESI,dword ptr [ESI + 0x4]
    //         00403f78     TEST       ESI,ESI
    //         00403f7a     JNZ        LAB_00403f6d
    //                               LAB_00403f7c                                                 XREF[1]:     00403f6b(j)  
    //                              act_list.cpp:115 (24)
    //         00403f7c     LEA        this=>param_1,[ESP + 0xc]
    //         00403f80     PUSH       0x2
    //         00403f82     PUSH       this=>DAT_fffffff8
    //         00403f83     PUSH       EDI=>DAT_fffffff4
    //         00403f84     MOV        dword ptr [ESP + param_1],0x0
    //         00403f8c     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00403f91     ADD        ESP,0xc
    //                              act_list.cpp:116 (5)
    //         00403f94     POP        EDI
    //         00403f95     POP        ESI
    //         00403f96     RET        0x4
    //         00403f99     ??         90h
    //         00403f9a     NOP
    //         00403f9b     NOP
    //         00403f9c     NOP
    //         00403f9d     NOP
    //         00403f9e     NOP
    //         00403f9f     NOP
    return;
}

void RGE_Action_List::delete_list() {
    /* TODO: Stub */
    //                              void __thiscall delete_list(RGE_Action_List * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Lis    ECX:4 (auto)   this
    //                               ?delete_list@RGE_Action_List@@QAEXXZ                         XREF[44]:    set_state:004020dc(c), 
    //                               RGE_Action_List::delete_list                                              load:00403ede(c), 
    //                                                                                                         recycle_out_of_game:0040608d(c), 
    //                                                                                                         transform:00406283(c), 
    //                                                                                                         destroy_obj:00406299(c), 
    //                                                                                                         set_only_action:00406a09(c), 
    //                                                                                                         stop:00406a68(c), 
    //                                                                                                         update:00406b24(c), 
    //                                                                                                         attack:00430a61(c), 
    //                                                                                                         attack:00430bdc(c), 
    //                                                                                                         enter:00431227(c), 
    //                                                                                                         recycle_out_of_game:004c8380(c), 
    //                                                                                                         change_ownership:004c8d84(c), 
    //                                                                                                         remove_from_production_queue:004c9
    //                                                                                                         empty_production_queue:004c9d6c(c)
    //                                                                                                         heal:004cb423(c), 
    //                                                                                                         build:004cb6e3(c), 
    //                                                                                                         update:004cce07(c), 
    //                                                                                                         set_state:004cd32c(c), 
    //                                                                                                         set_state:004cf31d(c), [more]
    //                              act_list.cpp:121 (3)
    //         00403fa0     PUSH       ESI
    //         00403fa1     MOV        ESI,this
    //                              act_list.cpp:122 (7)
    //         00403fa3     MOV        EAX,dword ptr [ESI + 0x8]
    //         00403fa6     TEST       EAX,EAX
    //         00403fa8     JZ         LAB_00403fb8
    //                               LAB_00403faa                                                 XREF[1]:     00403fb6(j)  
    //                              act_list.cpp:123 (14)
    //         00403faa     MOV        this,ESI
    //         00403fac     CALL       RGE_Action_List::remove_action                   void remove_action(RGE_Action_List * this)
    //         00403fb1     MOV        EAX,dword ptr [ESI + 0x8]
    //         00403fb4     TEST       EAX,EAX
    //         00403fb6     JNZ        LAB_00403faa
    //                               LAB_00403fb8                                                 XREF[1]:     00403fa8(j)  
    //                              act_list.cpp:124 (2)
    //         00403fb8     POP        ESI
    //         00403fb9     RET
    //         00403fba     ??         90h
    //         00403fbb     NOP
    //         00403fbc     NOP
    //         00403fbd     NOP
    //         00403fbe     NOP
    //         00403fbf     NOP
    return;
}

RGE_Action* RGE_Action_List::create_action(int param_1, short param_2) {
    /* TODO: Stub */
    //                              RGE_Action * __thiscall create_action(RGE_Action_List * this, int pa
    //              RGE_Action *      EAX:4          <RETURN>
    //              RGE_Action_Lis    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[7]:     00404017(R), 00404057(R), 00404097(R), 004040d7(R), 
    //                                                                                     00404117(R), 00404153(R), 0040418f(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[8]:     00403fce(R), 00404000(W), 00404040(W), 00404080(W), 
    //                                                                                     004040c0(W), 00404100(W), 00404140(W), 0040417c(W)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[7]:     00404006(W), 00404046(W), 00404086(W), 004040c6(W), 
    //                                                                                     00404106(W), 00404146(W), 00404182(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[8]:     00404024(R), 00404064(R), 004040a4(R), 004040e4(R), 
    //                                                                                     00404124(R), 00404160(R), 0040419c(R), 004041ae(R)  
    //                               ?create_action@RGE_Action_List@@UAEPAVRGE_Action@@HF@Z       XREF[2]:     create_action:004d0500(c), 
    //                               RGE_Action_List::create_action                                            0056e298(*)  
    //                              act_list.cpp:131 (14)
    //         00403fc0     MOV        EAX,FS:[0x0]
    //         00403fc6     PUSH       -0x1
    //         00403fc8     PUSH       FUN_0055c24d
    //         00403fcd     PUSH       EAX
    //                              act_list.cpp:132 (40)
    //         00403fce     MOVSX      EAX,word ptr [ESP + param_2]
    //         00403fd3     DEC        EAX
    //         00403fd4     MOV        dword ptr FS:[0x0],ESP
    //         00403fdb     PUSH       ESI
    //         00403fdc     CMP        EAX,0x14
    //         00403fdf     MOV        ESI,this
    //         00403fe1     JA         switchD_00403fef::caseD_2
    //         00403fe7     XOR        this,this
    //         00403fe9     MOV        this,byte ptr [EAX + 0x4041e4]=>PTR_caseD_2_00
    //                               switchD_00403fef::switchD
    //         00403fef     JMP        dword ptr [this->_padding_*0x4 + switchD_00403   = 00404136
    //                               switchD_00403fef::caseD_9                                    XREF[2]:     00403fef(j), 004041d4(*)  
    //                              act_list.cpp:135 (46)
    //         00403ff6     PUSH       0x5c
    //         00403ff8     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00403ffd     ADD        ESP,0x4
    //         00404000     MOV        dword ptr [ESP + param_2],EAX
    //         00404004     TEST       EAX,EAX
    //         00404006     MOV        dword ptr [ESP + local_4],0x0
    //         0040400e     JZ         switchD_00403fef::caseD_2
    //         00404014     MOV        EDX,dword ptr [ESI + 0x4]
    //         00404017     MOV        this,dword ptr [ESP + param_1]
    //         0040401b     PUSH       EDX
    //         0040401c     PUSH       this
    //         0040401d     MOV        this,EAX
    //         0040401f     CALL       RGE_Action_Attack::RGE_Action_Attack             undefined RGE_Action_Attack(RGE_Action_Attack
    //                              act_list.cpp:158 (18)
    //         00404024     MOV        this,dword ptr [ESP + local_c]
    //         00404028     MOV        dword ptr FS:[0x0],this
    //         0040402f     POP        ESI
    //         00404030     ADD        ESP,0xc
    //         00404033     RET        0x8
    //                               switchD_00403fef::caseD_a                                    XREF[2]:     00403fef(j), 004041d8(*)  
    //                              act_list.cpp:138 (46)
    //         00404036     PUSH       0x40
    //         00404038     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0040403d     ADD        ESP,0x4
    //         00404040     MOV        dword ptr [ESP + param_2],EAX
    //         00404044     TEST       EAX,EAX
    //         00404046     MOV        dword ptr [ESP + local_4],0x1
    //         0040404e     JZ         switchD_00403fef::caseD_2
    //         00404054     MOV        EDX,dword ptr [ESI + 0x4]
    //         00404057     MOV        this,dword ptr [ESP + param_1]
    //         0040405b     PUSH       EDX
    //         0040405c     PUSH       this
    //         0040405d     MOV        this,EAX
    //         0040405f     CALL       RGE_Action_Bird::RGE_Action_Bird                 undefined RGE_Action_Bird(RGE_Action_Bird * t
    //                              act_list.cpp:158 (18)
    //         00404064     MOV        this,dword ptr [ESP + local_c]
    //         00404068     MOV        dword ptr FS:[0x0],this
    //         0040406f     POP        ESI
    //         00404070     ADD        ESP,0xc
    //         00404073     RET        0x8
    //                               switchD_00403fef::caseD_4                                    XREF[2]:     00403fef(j), 004041c8(*)  
    //                              act_list.cpp:141 (46)
    //         00404076     PUSH       0x40
    //         00404078     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0040407d     ADD        ESP,0x4
    //         00404080     MOV        dword ptr [ESP + param_2],EAX
    //         00404084     TEST       EAX,EAX
    //         00404086     MOV        dword ptr [ESP + local_4],0x2
    //         0040408e     JZ         switchD_00403fef::caseD_2
    //         00404094     MOV        EDX,dword ptr [ESI + 0x4]
    //         00404097     MOV        this,dword ptr [ESP + param_1]
    //         0040409b     PUSH       EDX
    //         0040409c     PUSH       this
    //         0040409d     MOV        this,EAX
    //         0040409f     CALL       RGE_Action_Explore::RGE_Action_Explore           undefined RGE_Action_Explore(RGE_Action_Explo
    //                              act_list.cpp:158 (18)
    //         004040a4     MOV        this,dword ptr [ESP + local_c]
    //         004040a8     MOV        dword ptr FS:[0x0],this
    //         004040af     POP        ESI
    //         004040b0     ADD        ESP,0xc
    //         004040b3     RET        0x8
    //                               switchD_00403fef::caseD_5                                    XREF[2]:     00403fef(j), 004041cc(*)  
    //                              act_list.cpp:144 (46)
    //         004040b6     PUSH       0x44
    //         004040b8     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004040bd     ADD        ESP,0x4
    //         004040c0     MOV        dword ptr [ESP + param_2],EAX
    //         004040c4     TEST       EAX,EAX
    //         004040c6     MOV        dword ptr [ESP + local_4],0x3
    //         004040ce     JZ         switchD_00403fef::caseD_2
    //         004040d4     MOV        EDX,dword ptr [ESI + 0x4]
    //         004040d7     MOV        this,dword ptr [ESP + param_1]
    //         004040db     PUSH       EDX
    //         004040dc     PUSH       this
    //         004040dd     MOV        this,EAX
    //         004040df     CALL       RGE_Action_Gather::RGE_Action_Gather             undefined RGE_Action_Gather(RGE_Action_Gather
    //                              act_list.cpp:158 (18)
    //         004040e4     MOV        this,dword ptr [ESP + local_c]
    //         004040e8     MOV        dword ptr FS:[0x0],this
    //         004040ef     POP        ESI
    //         004040f0     ADD        ESP,0xc
    //         004040f3     RET        0x8
    //                               switchD_00403fef::caseD_8                                    XREF[2]:     00403fef(j), 004041d0(*)  
    //                              act_list.cpp:147 (46)
    //         004040f6     PUSH       0x54
    //         004040f8     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004040fd     ADD        ESP,0x4
    //         00404100     MOV        dword ptr [ESP + param_2],EAX
    //         00404104     TEST       EAX,EAX
    //         00404106     MOV        dword ptr [ESP + local_4],0x4
    //         0040410e     JZ         switchD_00403fef::caseD_2
    //         00404114     MOV        EDX,dword ptr [ESI + 0x4]
    //         00404117     MOV        this,dword ptr [ESP + param_1]
    //         0040411b     PUSH       EDX
    //         0040411c     PUSH       this
    //         0040411d     MOV        this,EAX
    //         0040411f     CALL       RGE_Action_Missile::RGE_Action_Missile           undefined RGE_Action_Missile(RGE_Action_Missi
    //                              act_list.cpp:158 (18)
    //         00404124     MOV        this,dword ptr [ESP + local_c]
    //         00404128     MOV        dword ptr FS:[0x0],this
    //         0040412f     POP        ESI
    //         00404130     ADD        ESP,0xc
    //         00404133     RET        0x8
    //                               switchD_00403fef::caseD_1                                    XREF[2]:     00403fef(j), 004041c4(*)  
    //                              act_list.cpp:150 (42)
    //         00404136     PUSH       0x44
    //         00404138     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0040413d     ADD        ESP,0x4
    //         00404140     MOV        dword ptr [ESP + param_2],EAX
    //         00404144     TEST       EAX,EAX
    //         00404146     MOV        dword ptr [ESP + local_4],0x5
    //         0040414e     JZ         switchD_00403fef::caseD_2
    //         00404150     MOV        EDX,dword ptr [ESI + 0x4]
    //         00404153     MOV        this,dword ptr [ESP + param_1]
    //         00404157     PUSH       EDX
    //         00404158     PUSH       this
    //         00404159     MOV        this,EAX
    //         0040415b     CALL       RGE_Action_Move_To::RGE_Action_Move_To           undefined RGE_Action_Move_To(RGE_Action_Move_
    //                              act_list.cpp:158 (18)
    //         00404160     MOV        this,dword ptr [ESP + local_c]
    //         00404164     MOV        dword ptr FS:[0x0],this
    //         0040416b     POP        ESI
    //         0040416c     ADD        ESP,0xc
    //         0040416f     RET        0x8
    //                               switchD_00403fef::caseD_15                                   XREF[2]:     00403fef(j), 004041dc(*)  
    //                              act_list.cpp:153 (42)
    //         00404172     PUSH       0x40
    //         00404174     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00404179     ADD        ESP,0x4
    //         0040417c     MOV        dword ptr [ESP + param_2],EAX
    //         00404180     TEST       EAX,EAX
    //         00404182     MOV        dword ptr [ESP + local_4],0x6
    //         0040418a     JZ         switchD_00403fef::caseD_2
    //         0040418c     MOV        EDX,dword ptr [ESI + 0x4]
    //         0040418f     MOV        this,dword ptr [ESP + param_1]
    //         00404193     PUSH       EDX
    //         00404194     PUSH       this
    //         00404195     MOV        this,EAX
    //         00404197     CALL       RGE_Action_Make::RGE_Action_Make                 undefined RGE_Action_Make(RGE_Action_Make * t
    //                              act_list.cpp:158 (93)
    //         0040419c     MOV        this,dword ptr [ESP + local_c]
    //         004041a0     MOV        dword ptr FS:[0x0],this
    //         004041a7     POP        ESI
    //         004041a8     ADD        ESP,0xc
    //         004041ab     RET        0x8
    //                               switchD_00403fef::caseD_3                                    XREF[10]:    00403fe1(j), 00403fef(j), 
    //                               switchD_00403fef::caseD_6                                                 0040400e(j), 0040404e(j), 
    //                               switchD_00403fef::caseD_7                                                 0040408e(j), 004040ce(j), 
    //                               switchD_00403fef::caseD_b                                                 0040410e(j), 0040414e(j), 
    //                               switchD_00403fef::caseD_c                                                 0040418a(j), 004041e0(*)  
    //                               switchD_00403fef::caseD_d
    //                               switchD_00403fef::caseD_e
    //                               switchD_00403fef::caseD_f
    //                               switchD_00403fef::caseD_10
    //                               switchD_00403fef::caseD_11
    //                               switchD_00403fef::caseD_12
    //                               switchD_00403fef::caseD_13
    //                               switchD_00403fef::caseD_14
    //                               switchD_00403fef::caseD_2
    //         004041ae     MOV        this,dword ptr [ESP + local_c]
    //         004041b2     XOR        EAX,EAX
    //         004041b4     MOV        dword ptr FS:[0x0],this
    //         004041bb     POP        ESI
    //         004041bc     ADD        ESP,0xc
    //         004041bf     RET        0x8
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_004041c2()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_004041c2
    //         004041c2     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00403fef::switchdataD_004041c4                       XREF[1]:     create_action:00403fef(*)  
    //         004041c4     addr       switchD_00403fef::caseD_1
    //         004041c8     addr       switchD_00403fef::caseD_4
    //         004041cc     addr       switchD_00403fef::caseD_5
    //         004041d0     addr       switchD_00403fef::caseD_8
    //         004041d4     addr       switchD_00403fef::caseD_9
    //         004041d8     addr       switchD_00403fef::caseD_a
    //         004041dc     addr       switchD_00403fef::caseD_15
    //                               PTR_caseD_2_004041e0+3                                       XREF[0,1]:   create_action:00403fe9(*)  
    //         004041e0     addr       switchD_00403fef::caseD_2
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00403fef::switchdataD_004041e4
    //         004041e4     db         0h
    //         004041e5     db         7h
    //         004041e6     db         7h
    //         004041e7     db         1h
    //         004041e8     db         2h
    //         004041e9     db         7h
    //         004041ea     db         7h
    //         004041eb     db         3h
    //         004041ec     db         4h
    //         004041ed     db         5h
    //         004041ee     db         7h
    //         004041ef     db         7h
    //         004041f0     db         7h
    //         004041f1     db         7h
    //         004041f2     db         7h
    //         004041f3     db         7h
    //         004041f4     db         7h
    //         004041f5     db         7h
    //         004041f6     db         7h
    //         004041f7     db         7h
    //         004041f8     db         6h
    //         004041f9     ??         90h
    //         004041fa     ??         90h
    //         004041fb     ??         90h
    //         004041fc     ??         90h
    //         004041fd     ??         90h
    //         004041fe     ??         90h
    //         004041ff     ??         90h
    //                              * public: virtual class RGE_Action * __thiscall RGE_Action_List::create_task_action(class RGE_Task *... *
    //                              RGE_Action * __thiscall create_task_action(RGE_Action_List * this, R
    //              RGE_Action *      EAX:4          <RETURN>
    //              RGE_Action_Lis    ECX:4 (auto)   this
    //              RGE_Task *        Stack[0x4]:4   param_1                   XREF[1]:     00404218(R)  
    //              RGE_Static_Obj    Stack[0x8]:4   param_2                   XREF[5]:     00404248(W), 00404288(R), 0040439a(W), 004043ce(R), 
    //                                                                                     00404407(W)  
    //              float             Stack[0xc]:4   param_3                   XREF[5]:     00404265(R), 004042be(R), 0040437c(R), 004043b7(R), 
    //                                                                                     00404420(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[8]:     00404260(R), 004042ba(R), 004042e4(W), 00404377(R), 
    //                                                                                     004043b2(R), 004043e0(W), 0040441b(R), 0040443e(W)  
    //              float             Stack[0x14]:4  param_5                   XREF[5]:     0040425c(R), 00404284(R), 00404339(W), 004043ae(R), 
    //                                                                                     00404417(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[7]:     0040424e(W), 004042ea(W), 0040433f(W), 004043a0(W), 
    //                                                                                     004043e6(W), 0040440d(W), 00404444(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0040445e(R)  
    //                               ?create_task_action@RGE_Action_List@@UAEPAVRGE_Action@@PAVR  XREF[2]:     create_task_action:004d0b8f(c), 
    //                               RGE_Action_List::create_task_action                                       0056e29c(*)  
    //                              act_list.cpp:167 (24)
    //         00404200     MOV        EAX,FS:[0x0]
    //         00404206     PUSH       -0x1
    //         00404208     PUSH       FUN_0055c2ad
    //         0040420d     PUSH       EAX
    //         0040420e     MOV        dword ptr FS:[0x0],ESP
    //         00404215     PUSH       EBX
    //         00404216     PUSH       EBP
    //         00404217     PUSH       ESI
    //                              act_list.cpp:168 (38)
    //         00404218     MOV        ESI,dword ptr [ESP + param_1]
    //         0040421c     PUSH       EDI
    //         0040421d     MOV        EDI,this
    //         0040421f     MOVSX      EAX,word ptr [ESI + 0x6]
    //         00404223     ADD        EAX,-0x4
    //         00404226     CMP        EAX,0x11
    //         00404229     JA         switchD_00404237::caseD_6
    //         0040422f     XOR        this,this
    //         00404231     MOV        this,byte ptr [EAX + 0x40448c]=>PTR_caseD_6_00   = 0040445c
    //                               switchD_00404237::switchD
    //         00404237     JMP        dword ptr [this->_padding_*0x4 + switchD_00404   = 00404390
    //                               switchD_00404237::caseD_a                                    XREF[2]:     00404237(j), 00404480(*)  
    //                              act_list.cpp:171 (62)
    //         0040423e     PUSH       0x40
    //         00404240     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00404245     ADD        ESP,0x4
    //         00404248     MOV        dword ptr [ESP + param_2],EAX
    //         0040424c     TEST       EAX,EAX
    //         0040424e     MOV        dword ptr [ESP + local_4],0x0
    //         00404256     JZ         switchD_00404237::caseD_6
    //         0040425c     MOV        EDX,dword ptr [ESP + param_5]
    //         00404260     MOV        this,dword ptr [ESP + param_4]
    //         00404264     PUSH       EDX
    //         00404265     MOV        EDX,dword ptr [ESP + param_3]
    //         00404269     PUSH       this
    //         0040426a     MOV        this,dword ptr [EDI + 0x4]
    //         0040426d     PUSH       EDX
    //         0040426e     PUSH       ESI
    //         0040426f     PUSH       this
    //         00404270     MOV        this,EAX
    //         00404272     CALL       RGE_Action_Bird::RGE_Action_Bird                 undefined RGE_Action_Bird(RGE_Action_Bird * t
    //         00404277     JMP        LAB_0040445e
    //                               switchD_00404237::caseD_7                                    XREF[2]:     00404237(j), 0040447c(*)  
    //                              act_list.cpp:176 (20)
    //         0040427c     MOV        this,dword ptr [EDI + 0x4]
    //         0040427f     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         00404284     MOV        EBP,dword ptr [ESP + param_5]
    //         00404288     MOV        EBX,dword ptr [ESP + param_2]
    //         0040428c     TEST       EAX,EAX
    //         0040428e     JZ         LAB_004042d6
    //                              act_list.cpp:182 (20)
    //         00404290     MOV        this,dword ptr [EDI + 0x4]
    //         00404293     PUSH       0x258
    //         00404298     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         0040429d     MOV        this,EAX
    //         0040429f     CALL       UnitAIModule::setCurrentAction                   void setCurrentAction(UnitAIModule * this, in
    //                              act_list.cpp:184 (4)
    //         004042a4     TEST       EBX,EBX
    //         004042a6     JZ         LAB_004042ba
    //                              act_list.cpp:187 (16)
    //         004042a8     MOV        EDX,dword ptr [EBX + 0x40]
    //         004042ab     MOV        EAX,dword ptr [EBX + 0x3c]
    //         004042ae     MOV        this,dword ptr [EBX + 0x38]
    //         004042b1     PUSH       EDX
    //         004042b2     MOV        EDX,dword ptr [EBX + 0x4]
    //         004042b5     PUSH       EAX
    //         004042b6     PUSH       this
    //         004042b7     PUSH       EDX
    //                              act_list.cpp:188 (2)
    //         004042b8     JMP        LAB_004042c7
    //                               LAB_004042ba                                                 XREF[1]:     004042a6(j)  
    //                              act_list.cpp:189 (28)
    //         004042ba     MOV        EAX,dword ptr [ESP + param_4]
    //         004042be     MOV        this,dword ptr [ESP + param_3]
    //         004042c2     PUSH       EBP
    //         004042c3     PUSH       EAX
    //         004042c4     PUSH       this
    //         004042c5     PUSH       -0x1
    //                               LAB_004042c7                                                 XREF[1]:     004042b8(j)  
    //         004042c7     MOV        this,dword ptr [EDI + 0x4]
    //         004042ca     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         004042cf     MOV        this,EAX
    //         004042d1     CALL       UnitAIModule::setCurrentTarget                   void setCurrentTarget(UnitAIModule * this, in
    //                               LAB_004042d6                                                 XREF[1]:     0040428e(j)  
    //                              act_list.cpp:191 (2)
    //         004042d6     TEST       EBX,EBX
    //                              act_list.cpp:196 (89)
    //         004042d8     PUSH       0x5c
    //         004042da     JZ         LAB_00404331
    //         004042dc     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004042e1     ADD        ESP,0x4
    //         004042e4     MOV        dword ptr [ESP + param_4],EAX
    //         004042e8     TEST       EAX,EAX
    //         004042ea     MOV        dword ptr [ESP + local_4],0x1
    //         004042f2     JZ         switchD_00404237::caseD_6
    //         004042f8     MOV        EDI,dword ptr [EDI + 0x4]
    //         004042fb     MOV        EDX,dword ptr [EDI + 0x8]
    //         004042fe     MOV        this,word ptr [EDX + 0x12a]
    //         00404305     PUSH       this
    //         00404306     MOV        this,word ptr [EDX + 0x124]
    //         0040430d     MOV        EDX,dword ptr [EDX + 0x138]
    //         00404313     PUSH       this
    //         00404314     MOV        this,dword ptr [ESI + 0x24]
    //         00404317     PUSH       EDX
    //         00404318     MOV        EDX,dword ptr [ESI + 0x38]
    //         0040431b     PUSH       this
    //         0040431c     MOV        this,dword ptr [ESI + 0x34]
    //         0040431f     PUSH       0x0
    //         00404321     PUSH       EDX
    //         00404322     PUSH       this
    //         00404323     PUSH       EBX
    //         00404324     PUSH       EDI
    //         00404325     MOV        this,EAX
    //         00404327     CALL       RGE_Action_Attack::RGE_Action_Attack             undefined RGE_Action_Attack(RGE_Action_Attack
    //         0040432c     JMP        LAB_0040445e
    //                               LAB_00404331                                                 XREF[1]:     004042da(j)  
    //                              act_list.cpp:202 (95)
    //         00404331     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00404336     ADD        ESP,0x4
    //         00404339     MOV        dword ptr [ESP + param_5],EAX
    //         0040433d     TEST       EAX,EAX
    //         0040433f     MOV        dword ptr [ESP + local_4],0x2
    //         00404347     JZ         switchD_00404237::caseD_6
    //         0040434d     MOV        EDI,dword ptr [EDI + 0x4]
    //         00404350     MOV        EDX,dword ptr [EDI + 0x8]
    //         00404353     MOV        this,word ptr [EDX + 0x12a]
    //         0040435a     PUSH       this
    //         0040435b     MOV        this,word ptr [EDX + 0x124]
    //         00404362     MOV        EDX,dword ptr [EDX + 0x138]
    //         00404368     PUSH       this
    //         00404369     MOV        this,dword ptr [ESI + 0x24]
    //         0040436c     PUSH       EDX
    //         0040436d     MOV        EDX,dword ptr [ESI + 0x38]
    //         00404370     PUSH       this
    //         00404371     MOV        this,dword ptr [ESI + 0x34]
    //         00404374     PUSH       0x0
    //         00404376     PUSH       EDX
    //         00404377     MOV        EDX,dword ptr [ESP + param_4]
    //         0040437b     PUSH       this
    //         0040437c     MOV        this,dword ptr [ESP + param_3]
    //         00404380     PUSH       EBP
    //         00404381     PUSH       EDX
    //         00404382     PUSH       this
    //         00404383     PUSH       EDI
    //         00404384     MOV        this,EAX
    //         00404386     CALL       RGE_Action_Attack::RGE_Action_Attack             undefined RGE_Action_Attack(RGE_Action_Attack
    //         0040438b     JMP        LAB_0040445e
    //                               switchD_00404237::caseD_4                                    XREF[2]:     00404237(j), 00404474(*)  
    //                              act_list.cpp:205 (62)
    //         00404390     PUSH       0x40
    //         00404392     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00404397     ADD        ESP,0x4
    //         0040439a     MOV        dword ptr [ESP + param_2],EAX
    //         0040439e     TEST       EAX,EAX
    //         004043a0     MOV        dword ptr [ESP + local_4],0x3
    //         004043a8     JZ         switchD_00404237::caseD_6
    //         004043ae     MOV        EDX,dword ptr [ESP + param_5]
    //         004043b2     MOV        this,dword ptr [ESP + param_4]
    //         004043b6     PUSH       EDX
    //         004043b7     MOV        EDX,dword ptr [ESP + param_3]
    //         004043bb     PUSH       this
    //         004043bc     MOV        this,dword ptr [EDI + 0x4]
    //         004043bf     PUSH       EDX
    //         004043c0     PUSH       ESI
    //         004043c1     PUSH       this
    //         004043c2     MOV        this,EAX
    //         004043c4     CALL       RGE_Action_Explore::RGE_Action_Explore           undefined RGE_Action_Explore(RGE_Action_Explo
    //         004043c9     JMP        LAB_0040445e
    //                               switchD_00404237::caseD_5                                    XREF[2]:     00404237(j), 00404478(*)  
    //                              act_list.cpp:208 (4)
    //         004043ce     MOV        EBX,dword ptr [ESP + param_2]
    //                              act_list.cpp:209 (45)
    //         004043d2     PUSH       0x44
    //         004043d4     TEST       EBX,EBX
    //         004043d6     JZ         LAB_004043ff
    //         004043d8     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004043dd     ADD        ESP,0x4
    //         004043e0     MOV        dword ptr [ESP + param_4],EAX
    //         004043e4     TEST       EAX,EAX
    //         004043e6     MOV        dword ptr [ESP + local_4],0x4
    //         004043ee     JZ         switchD_00404237::caseD_6
    //         004043f0     MOV        EDX,dword ptr [EDI + 0x4]
    //         004043f3     PUSH       EBX
    //         004043f4     PUSH       ESI
    //         004043f5     PUSH       EDX
    //         004043f6     MOV        this,EAX
    //         004043f8     CALL       RGE_Action_Gather::RGE_Action_Gather             undefined RGE_Action_Gather(RGE_Action_Gather
    //         004043fd     JMP        LAB_0040445e
    //                               LAB_004043ff                                                 XREF[1]:     004043d6(j)  
    //                              act_list.cpp:211 (53)
    //         004043ff     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00404404     ADD        ESP,0x4
    //         00404407     MOV        dword ptr [ESP + param_2],EAX
    //         0040440b     TEST       EAX,EAX
    //         0040440d     MOV        dword ptr [ESP + local_4],0x5
    //         00404415     JZ         switchD_00404237::caseD_6
    //         00404417     MOV        this,dword ptr [ESP + param_5]
    //         0040441b     MOV        EDX,dword ptr [ESP + param_4]
    //         0040441f     PUSH       this
    //         00404420     MOV        this,dword ptr [ESP + param_3]
    //         00404424     PUSH       EDX
    //         00404425     MOV        EDX,dword ptr [EDI + 0x4]
    //         00404428     PUSH       this
    //         00404429     PUSH       ESI
    //         0040442a     PUSH       EDX
    //         0040442b     MOV        this,EAX
    //         0040442d     CALL       RGE_Action_Gather::RGE_Action_Gather             undefined RGE_Action_Gather(RGE_Action_Gather
    //         00404432     JMP        LAB_0040445e
    //                               switchD_00404237::caseD_15                                   XREF[2]:     00404237(j), 00404484(*)  
    //                              act_list.cpp:214 (40)
    //         00404434     PUSH       0x40
    //         00404436     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0040443b     ADD        ESP,0x4
    //         0040443e     MOV        dword ptr [ESP + param_4],EAX
    //         00404442     TEST       EAX,EAX
    //         00404444     MOV        dword ptr [ESP + local_4],0x6
    //         0040444c     JZ         switchD_00404237::caseD_6
    //         0040444e     MOV        this,dword ptr [EDI + 0x4]
    //         00404451     PUSH       ESI
    //         00404452     PUSH       this
    //         00404453     MOV        this,EAX
    //         00404455     CALL       RGE_Action_Make::RGE_Action_Make                 undefined RGE_Action_Make(RGE_Action_Make * t
    //         0040445a     JMP        LAB_0040445e
    //                               switchD_00404237::caseD_8                                    XREF[10]:    00404229(j), 00404237(j), 
    //                               switchD_00404237::caseD_9                                                 00404256(j), 004042f2(j), 
    //                               switchD_00404237::caseD_b                                                 00404347(j), 004043a8(j), 
    //                               switchD_00404237::caseD_c                                                 004043ee(j), 00404415(j), 
    //                               switchD_00404237::caseD_d                                                 0040444c(j), 00404488(*)  
    //                               switchD_00404237::caseD_e
    //                               switchD_00404237::caseD_f
    //                               switchD_00404237::caseD_10
    //                               switchD_00404237::caseD_11
    //                               switchD_00404237::caseD_12
    //                               switchD_00404237::caseD_13
    //                               switchD_00404237::caseD_14
    //                               switchD_00404237::caseD_6
    //                              act_list.cpp:217 (2)
    //         0040445c     XOR        EAX,EAX
    //                               LAB_0040445e                                                 XREF[7]:     00404277(j), 0040432c(j), 
    //                                                                                                         0040438b(j), 004043c9(j), 
    //                                                                                                         004043fd(j), 00404432(j), 
    //                                                                                                         0040445a(j)  
    //                              act_list.cpp:218 (64)
    //         0040445e     MOV        this,dword ptr [ESP + local_c]
    //         00404462     POP        EDI
    //         00404463     POP        ESI
    //         00404464     POP        EBP
    //         00404465     MOV        dword ptr FS:[0x0],this
    //         0040446c     POP        EBX
    //         0040446d     ADD        ESP,0xc
    //         00404470     RET        0x14
    //         00404473     ??         90h
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00404237::switchdataD_00404474                       XREF[1]:     create_task_action:00404237(*)  
    //         00404474     addr       switchD_00404237::caseD_4
    //         00404478     addr       switchD_00404237::caseD_5
    //         0040447c     addr       switchD_00404237::caseD_7
    //         00404480     addr       switchD_00404237::caseD_a
    //         00404484     addr       switchD_00404237::caseD_15
    //                               PTR_caseD_6_00404488                                         XREF[1]:     create_task_action:00404231(*)  
    //         00404488     addr       switchD_00404237::caseD_6
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00404237::switchdataD_0040448c
    //         0040448c     db         0h
    //         0040448d     db         1h
    //         0040448e     db         5h
    //         0040448f     db         2h
    //         00404490     db         5h
    //         00404491     db         5h
    //         00404492     db         3h
    //         00404493     db         5h
    //         00404494     db         5h
    //         00404495     db         5h
    //         00404496     db         5h
    //         00404497     db         5h
    //         00404498     db         5h
    //         00404499     db         5h
    //         0040449a     db         5h
    //         0040449b     db         5h
    //         0040449c     db         5h
    //         0040449d     db         4h
    //         0040449e     ??         90h
    //         0040449f     ??         90h
    return 0;
}

uchar RGE_Action_List::inside_obj_update() {
    /* TODO: Stub */
    //                              uchar __thiscall inside_obj_update(RGE_Action_List * this)
    //              uchar             AL:1           <RETURN>
    //              RGE_Action_Lis    ECX:4 (auto)   this
    //                               ?inside_obj_update@RGE_Action_List@@UAEEXZ                   XREF[2]:     0056e2a0(*), 00575178(*)  
    //                               RGE_Action_List::inside_obj_update
    //                              act_list.cpp:222 (3)
    //         004044a0     PUSH       EDI
    //         004044a1     MOV        EDI,this
    //                              act_list.cpp:226 (7)
    //         004044a3     MOV        EAX,dword ptr [EDI + 0x8]
    //         004044a6     TEST       EAX,EAX
    //         004044a8     JNZ        LAB_004044ae
    //                              act_list.cpp:227 (2)
    //         004044aa     MOV        AL,0x1
    //                              act_list.cpp:240 (2)
    //         004044ac     POP        EDI
    //         004044ad     RET
    //                               LAB_004044ae                                                 XREF[1]:     004044a8(j)  
    //                              act_list.cpp:229 (9)
    //         004044ae     MOV        this,dword ptr [EAX]
    //         004044b0     PUSH       ESI
    //         004044b1     PUSH       EBX
    //         004044b2     MOV        EAX,dword ptr [this->_padding_]
    //         004044b4     CALL       dword ptr [EAX + 0x20]
    //                              act_list.cpp:230 (12)
    //         004044b7     MOV        this,dword ptr [EDI + 0x8]
    //         004044ba     MOV        BL,AL
    //         004044bc     MOV        ESI,dword ptr [ECX + this->obj]
    //         004044bf     TEST       ESI,ESI
    //         004044c1     JZ         LAB_004044d1
    //                               LAB_004044c3                                                 XREF[1]:     004044cf(j)  
    //                              act_list.cpp:231 (14)
    //         004044c3     MOV        this,dword ptr [ESI]
    //         004044c5     MOV        EDX,dword ptr [this->_padding_]
    //         004044c7     CALL       dword ptr [EDX + 0x24]
    //         004044ca     MOV        ESI,dword ptr [ESI + 0x4]
    //         004044cd     TEST       ESI,ESI
    //         004044cf     JNZ        LAB_004044c3
    //                               LAB_004044d1                                                 XREF[1]:     004044c1(j)  
    //                              act_list.cpp:233 (5)
    //         004044d1     CMP        BL,0x1
    //         004044d4     JNZ        LAB_004044dd
    //                              act_list.cpp:235 (7)
    //         004044d6     MOV        this,EDI
    //         004044d8     CALL       RGE_Action_List::remove_action                   void remove_action(RGE_Action_List * this)
    //                               LAB_004044dd                                                 XREF[1]:     004044d4(j)  
    //                              act_list.cpp:239 (4)
    //         004044dd     MOV        AL,BL
    //         004044df     POP        EBX
    //         004044e0     POP        ESI
    //                              act_list.cpp:240 (2)
    //         004044e1     POP        EDI
    //         004044e2     RET
    //         004044e3     ??         90h
    //         004044e4     NOP
    //         004044e5     NOP
    //         004044e6     NOP
    //         004044e7     NOP
    //         004044e8     NOP
    //         004044e9     NOP
    //         004044ea     NOP
    //         004044eb     NOP
    //         004044ec     NOP
    //         004044ed     NOP
    //         004044ee     NOP
    //         004044ef     NOP
    return 0;
}

uchar RGE_Action_List::update() {
    /* TODO: Stub */
    //                              uchar __thiscall update(RGE_Action_List * this)
    //              uchar             AL:1           <RETURN>
    //              RGE_Action_Lis    ECX:4 (auto)   this
    //                               ?update@RGE_Action_List@@UAEEXZ                              XREF[2]:     0056e2a4(*), 0057517c(*)  
    //                               RGE_Action_List::update
    //                              act_list.cpp:244 (5)
    //         004044f0     PUSH       EBX
    //         004044f1     PUSH       ESI
    //         004044f2     PUSH       EDI
    //         004044f3     MOV        EDI,this
    //                              act_list.cpp:252 (7)
    //         004044f5     MOV        EAX,dword ptr [EDI + 0x8]
    //         004044f8     TEST       EAX,EAX
    //         004044fa     JNZ        LAB_00404502
    //                              act_list.cpp:257 (2)
    //         004044fc     MOV        AL,0x1
    //                              act_list.cpp:314 (4)
    //         004044fe     POP        EDI
    //         004044ff     POP        ESI
    //         00404500     POP        EBX
    //         00404501     RET
    //                               LAB_00404502                                                 XREF[1]:     004044fa(j)  
    //                              act_list.cpp:268 (9)
    //         00404502     MOV        this,dword ptr [EAX]
    //         00404504     MOV        EAX,dword ptr [this->_padding_]
    //         00404506     CALL       dword ptr [EAX + 0x28]
    //         00404509     MOV        BL,AL
    //                              act_list.cpp:286 (5)
    //         0040450b     MOV        EAX,dword ptr [EDI + 0x8]
    //         0040450e     TEST       EAX,EAX
    //                              act_list.cpp:291 (2)
    //         00404510     JZ         LAB_00404533
    //                              act_list.cpp:294 (7)
    //         00404512     MOV        ESI,dword ptr [EAX + 0x4]
    //         00404515     TEST       ESI,ESI
    //         00404517     JZ         LAB_00404527
    //                               LAB_00404519                                                 XREF[1]:     00404525(j)  
    //                              act_list.cpp:299 (14)
    //         00404519     MOV        this,dword ptr [ESI]
    //         0040451b     MOV        EDX,dword ptr [this->_padding_]
    //         0040451d     CALL       dword ptr [EDX + 0x24]
    //         00404520     MOV        ESI,dword ptr [ESI + 0x4]
    //         00404523     TEST       ESI,ESI
    //         00404525     JNZ        LAB_00404519
    //                               LAB_00404527                                                 XREF[1]:     00404517(j)  
    //                              act_list.cpp:302 (5)
    //         00404527     CMP        BL,0x1
    //         0040452a     JNZ        LAB_00404533
    //                              act_list.cpp:307 (7)
    //         0040452c     MOV        this,EDI
    //         0040452e     CALL       RGE_Action_List::remove_action                   void remove_action(RGE_Action_List * this)
    //                               LAB_00404533                                                 XREF[2]:     00404510(j), 0040452a(j)  
    //                              act_list.cpp:314 (6)
    //         00404533     POP        EDI
    //         00404534     MOV        AL,BL
    //         00404536     POP        ESI
    //         00404537     POP        EBX
    //         00404538     RET
    //         00404539     ??         90h
    //         0040453a     NOP
    //         0040453b     NOP
    //         0040453c     NOP
    //         0040453d     NOP
    //         0040453e     NOP
    //         0040453f     NOP
    return 0;
}

void RGE_Action_List::add_action(RGE_Action* param_1) {
    /* TODO: Stub */
    //                              void __thiscall add_action(RGE_Action_List * this, RGE_Action * para
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Lis    ECX:4 (auto)   this
    //              RGE_Action *      Stack[0x4]:4   param_1                   XREF[2]:     0040454c(R), 00404567(R)  
    //                               ?add_action@RGE_Action_List@@QAEXPAVRGE_Action@@@Z           XREF[25]:    set_state:0040167f(c), 
    //                               RGE_Action_List::add_action                                               update:00402354(c), 
    //                                                                                                         set_state:004026c4(c), 
    //                                                                                                         set_state:00402d4f(c), 
    //                                                                                                         set_state:00403249(c), 
    //                                                                                                         set_state:00403477(c), 
    //                                                                                                         set_action:004069ef(c), 
    //                                                                                                         set_only_action:00406a1d(c), 
    //                                                                                                         set_state:00406f47(c), 
    //                                                                                                         init_missile:0045a9b8(c), 
    //                                                                                                         init_missile:0045aa48(c), 
    //                                                                                                         update_production_queue:004c9f51(c
    //                                                                                                         set_state:004ccdc8(c), 
    //                                                                                                         set_state:004cd48b(c), 
    //                                                                                                         set_state:004cd522(c), 
    //                                                                                                         set_state:004cdf01(c), 
    //                                                                                                         set_state:004cdf94(c), 
    //                                                                                                         set_state:004ceba7(c), 
    //                                                                                                         set_state:004cec3b(c), 
    //                                                                                                         set_state:004cf45e(c), [more]
    //                              act_list.cpp:319 (3)
    //         00404540     PUSH       ESI
    //         00404541     MOV        ESI,this
    //                              act_list.cpp:323 (9)
    //         00404543     MOV        EAX,dword ptr [ESI + 0x4]
    //         00404546     CMP        byte ptr [EAX + 0x48],0x2
    //         0040454a     JBE        LAB_0040455e
    //                              act_list.cpp:325 (14)
    //         0040454c     MOV        this,dword ptr [ESP + param_1]
    //         00404550     TEST       this,this
    //         00404552     JZ         LAB_00404580
    //         00404554     MOV        EDX,dword ptr [this->_padding_]
    //         00404556     PUSH       0x1
    //         00404558     CALL       dword ptr [EDX]
    //                              act_list.cpp:337 (4)
    //         0040455a     POP        ESI
    //         0040455b     RET        0x4
    //                               LAB_0040455e                                                 XREF[1]:     0040454a(j)  
    //                              act_list.cpp:329 (9)
    //         0040455e     PUSH       0x8
    //         00404560     PUSH       0x1
    //         00404562     CALL       calloc                                           undefined calloc()
    //                              act_list.cpp:331 (9)
    //         00404567     MOV        this,dword ptr [ESP + param_1]
    //         0040456b     ADD        ESP,0x8
    //         0040456e     MOV        dword ptr [EAX],this
    //                              act_list.cpp:332 (6)
    //         00404570     MOV        EDX,dword ptr [ESI + 0x8]
    //         00404573     MOV        dword ptr [EAX + 0x4],EDX
    //                              act_list.cpp:334 (3)
    //         00404576     MOV        dword ptr [ESI + 0x8],EAX
    //                              act_list.cpp:336 (7)
    //         00404579     MOV        EAX,dword ptr [this->_padding_]
    //         0040457b     PUSH       0x1
    //         0040457d     CALL       dword ptr [EAX + 0x1c]
    //                               LAB_00404580                                                 XREF[1]:     00404552(j)  
    //                              act_list.cpp:337 (4)
    //         00404580     POP        ESI
    //         00404581     RET        0x4
    //         00404584     ??         90h
    //         00404585     NOP
    //         00404586     NOP
    //         00404587     NOP
    //         00404588     NOP
    //         00404589     NOP
    //         0040458a     NOP
    //         0040458b     NOP
    //         0040458c     NOP
    //         0040458d     NOP
    //         0040458e     NOP
    //         0040458f     NOP
    return;
}

void RGE_Action_List::add_action_at_end(RGE_Action* param_1) {
    /* TODO: Stub */
    //                              void __thiscall add_action_at_end(RGE_Action_List * this, RGE_Action
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Lis    ECX:4 (auto)   this
    //              RGE_Action *      Stack[0x4]:4   param_1                   XREF[2]:     0040459c(R), 004045b7(R)  
    //                               ?add_action_at_end@RGE_Action_List@@QAEXPAVRGE_Action@@@Z    XREF[1]:     set_end_action:00406a3f(c)  
    //                               RGE_Action_List::add_action_at_end
    //                              act_list.cpp:342 (3)
    //         00404590     PUSH       ESI
    //         00404591     MOV        ESI,this
    //                              act_list.cpp:347 (9)
    //         00404593     MOV        EAX,dword ptr [ESI + 0x4]
    //         00404596     CMP        byte ptr [EAX + 0x48],0x2
    //         0040459a     JBE        LAB_004045ae
    //                              act_list.cpp:349 (14)
    //         0040459c     MOV        this,dword ptr [ESP + param_1]
    //         004045a0     TEST       this,this
    //         004045a2     JZ         LAB_004045fe
    //         004045a4     MOV        EDX,dword ptr [this->_padding_]
    //         004045a6     PUSH       0x1
    //         004045a8     CALL       dword ptr [EDX]
    //                              act_list.cpp:372 (4)
    //         004045aa     POP        ESI
    //         004045ab     RET        0x4
    //                               LAB_004045ae                                                 XREF[1]:     0040459a(j)  
    //                              act_list.cpp:353 (9)
    //         004045ae     PUSH       0x8
    //         004045b0     PUSH       0x1
    //         004045b2     CALL       calloc                                           undefined calloc()
    //                              act_list.cpp:355 (4)
    //         004045b7     MOV        this,dword ptr [ESP + param_1]
    //                              act_list.cpp:356 (9)
    //         004045bb     MOV        dword ptr [EAX + 0x4],0x0
    //         004045c2     MOV        dword ptr [EAX],this
    //                              act_list.cpp:359 (10)
    //         004045c4     MOV        EDX,dword ptr [ESI + 0x8]
    //         004045c7     ADD        ESP,0x8
    //         004045ca     TEST       EDX,EDX
    //         004045cc     JZ         LAB_004045f4
    //                               LAB_004045ce                                                 XREF[1]:     004045d9(j)  
    //                              act_list.cpp:362 (13)
    //         004045ce     MOV        ESI,dword ptr [EDX + 0x4]
    //         004045d1     TEST       ESI,ESI
    //         004045d3     JZ         LAB_004045e6
    //         004045d5     MOV        EDX,ESI
    //         004045d7     TEST       EDX,EDX
    //         004045d9     JNZ        LAB_004045ce
    //                              act_list.cpp:371 (7)
    //         004045db     MOV        EAX,dword ptr [this->_padding_]
    //         004045dd     PUSH       0x1
    //         004045df     CALL       dword ptr [EAX + 0x1c]
    //                              act_list.cpp:372 (4)
    //         004045e2     POP        ESI
    //         004045e3     RET        0x4
    //                               LAB_004045e6                                                 XREF[1]:     004045d3(j)  
    //                              act_list.cpp:364 (3)
    //         004045e6     MOV        dword ptr [EDX + 0x4],EAX
    //                              act_list.cpp:371 (7)
    //         004045e9     MOV        EAX,dword ptr [this->_padding_]
    //         004045eb     PUSH       0x1
    //         004045ed     CALL       dword ptr [EAX + 0x1c]
    //                              act_list.cpp:372 (4)
    //         004045f0     POP        ESI
    //         004045f1     RET        0x4
    //                               LAB_004045f4                                                 XREF[1]:     004045cc(j)  
    //                              act_list.cpp:369 (3)
    //         004045f4     MOV        dword ptr [ESI + 0x8],EAX
    //                              act_list.cpp:371 (7)
    //         004045f7     MOV        EAX,dword ptr [this->_padding_]
    //         004045f9     PUSH       0x1
    //         004045fb     CALL       dword ptr [EAX + 0x1c]
    //                               LAB_004045fe                                                 XREF[1]:     004045a2(j)  
    //                              act_list.cpp:372 (4)
    //         004045fe     POP        ESI
    //         004045ff     RET        0x4
    //         00404602     ??         90h
    //         00404603     NOP
    //         00404604     NOP
    //         00404605     NOP
    //         00404606     NOP
    //         00404607     NOP
    //         00404608     NOP
    //         00404609     NOP
    //         0040460a     NOP
    //         0040460b     NOP
    //         0040460c     NOP
    //         0040460d     NOP
    //         0040460e     NOP
    //         0040460f     NOP
    return;
}

void RGE_Action_List::add_action_at_end_of_action_queue(RGE_Action* param_1) {
    /* TODO: Stub */
    //                              void __thiscall add_action_at_end_of_action_queue(RGE_Action_List * 
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Lis    ECX:4 (auto)   this
    //              RGE_Action *      Stack[0x4]:4   param_1                   XREF[2]:     00404620(R), 00404643(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0040464c(W)  
    //              RGE_Action_Nod    Stack[-0x8]:4  node
    //                               ?add_action_at_end_of_action_queue@RGE_Action_List@@QAEXPAV
    //                               RGE_Action_List::add_action_at_end_of_action_queue
    //                              act_list.cpp:377 (7)
    //         00404610     PUSH       this
    //         00404611     PUSH       EBX
    //         00404612     PUSH       EBP
    //         00404613     PUSH       ESI
    //         00404614     MOV        ESI,this
    //         00404616     PUSH       EDI
    //                              act_list.cpp:382 (9)
    //         00404617     MOV        EAX,dword ptr [ESI + 0x4]
    //         0040461a     CMP        byte ptr [EAX + 0x48],0x2
    //         0040461e     JBE        LAB_0040463a
    //                              act_list.cpp:384 (18)
    //         00404620     MOV        this,dword ptr [ESP + param_1]
    //         00404624     TEST       this,this
    //         00404626     JZ         LAB_004046fa
    //         0040462c     MOV        EDX,dword ptr [this->_padding_]
    //         0040462e     PUSH       0x1
    //         00404630     CALL       dword ptr [EDX]
    //                              act_list.cpp:410 (8)
    //         00404632     POP        EDI
    //         00404633     POP        ESI
    //         00404634     POP        EBP
    //         00404635     POP        EBX
    //         00404636     POP        this
    //         00404637     RET        0x4
    //                               LAB_0040463a                                                 XREF[1]:     0040461e(j)  
    //                              act_list.cpp:388 (9)
    //         0040463a     PUSH       0x8
    //         0040463c     PUSH       0x1
    //         0040463e     CALL       calloc                                           undefined calloc()
    //                              act_list.cpp:390 (15)
    //         00404643     MOV        EBX,dword ptr [ESP + param_1]
    //         00404647     MOV        this,EAX
    //         00404649     ADD        ESP,0x8
    //         0040464c     MOV        dword ptr [ESP + local_4],this
    //         00404650     MOV        dword ptr [this->_padding_],EBX
    //                              act_list.cpp:393 (47)
    //         00404652     MOV        EAX,dword ptr [ESI + 0x8]
    //         00404655     TEST       EAX,EAX
    //         00404657     JZ         LAB_004046e8
    //         0040465d     MOV        EDI,dword ptr [EAX]
    //         0040465f     MOV        EAX,dword ptr [EBX]
    //         00404661     MOV        this,EBX
    //         00404663     MOV        EBP,dword ptr [EAX + 0x18]
    //         00404666     CALL       EBP
    //         00404668     MOV        DX,AX
    //         0040466b     MOV        EAX,dword ptr [EDI]
    //         0040466d     MOV        this,EDI
    //         0040466f     MOV        word ptr [ESP + 0x18],DX
    //         00404674     CALL       dword ptr [EAX + 0x18]
    //         00404677     MOV        this,word ptr [ESP + 0x18]
    //         0040467c     CMP        AX,this
    //         0040467f     JNZ        LAB_004046e4
    //                              act_list.cpp:394 (7)
    //         00404681     MOV        EDI,dword ptr [ESI + 0x8]
    //         00404684     TEST       EDI,EDI
    //         00404686     JZ         LAB_004046f1
    //                               LAB_00404688                                                 XREF[1]:     004046b3(j)  
    //                              act_list.cpp:396 (45)
    //         00404688     MOV        EAX,dword ptr [EDI + 0x4]
    //         0040468b     TEST       EAX,EAX
    //         0040468d     JZ         LAB_004046c6
    //         0040468f     MOV        ESI,dword ptr [EAX]
    //         00404691     MOV        this,EBX
    //         00404693     CALL       EBP
    //         00404695     MOV        DX,AX
    //         00404698     MOV        EAX,dword ptr [ESI]
    //         0040469a     MOV        this,ESI
    //         0040469c     MOV        word ptr [ESP + 0x18],DX
    //         004046a1     CALL       dword ptr [EAX + 0x18]
    //         004046a4     MOV        this,word ptr [ESP + 0x18]
    //         004046a9     CMP        AX,this
    //         004046ac     JNZ        LAB_004046c6
    //         004046ae     MOV        EDI,dword ptr [EDI + 0x4]
    //         004046b1     TEST       EDI,EDI
    //         004046b3     JNZ        LAB_00404688
    //                              act_list.cpp:409 (9)
    //         004046b5     MOV        EDX,dword ptr [EBX]
    //         004046b7     PUSH       0x1
    //         004046b9     MOV        this,EBX
    //         004046bb     CALL       dword ptr [EDX + 0x1c]
    //                              act_list.cpp:410 (8)
    //         004046be     POP        EDI
    //         004046bf     POP        ESI
    //         004046c0     POP        EBP
    //         004046c1     POP        EBX
    //         004046c2     POP        this
    //         004046c3     RET        0x4
    //                               LAB_004046c6                                                 XREF[2]:     0040468d(j), 004046ac(j)  
    //                              act_list.cpp:398 (7)
    //         004046c6     MOV        EAX,dword ptr [ESP + 0x10]
    //         004046ca     MOV        EDX,dword ptr [EDI + 0x4]
    //                              act_list.cpp:409 (15)
    //         004046cd     PUSH       0x1
    //         004046cf     MOV        this,EBX
    //         004046d1     MOV        dword ptr [EAX + 0x4],EDX
    //         004046d4     MOV        EDX,dword ptr [EBX]
    //         004046d6     MOV        dword ptr [EDI + 0x4],EAX
    //         004046d9     CALL       dword ptr [EDX + 0x1c]
    //                              act_list.cpp:410 (8)
    //         004046dc     POP        EDI
    //         004046dd     POP        ESI
    //         004046de     POP        EBP
    //         004046df     POP        EBX
    //         004046e0     POP        this
    //         004046e1     RET        0x4
    //                               LAB_004046e4                                                 XREF[1]:     0040467f(j)  
    //                              act_list.cpp:403 (4)
    //         004046e4     MOV        this,dword ptr [ESP + 0x10]
    //                               LAB_004046e8                                                 XREF[1]:     00404657(j)  
    //                              act_list.cpp:405 (6)
    //         004046e8     MOV        EAX,dword ptr [ESI + 0x8]
    //         004046eb     MOV        dword ptr [ECX + this->obj],EAX
    //                              act_list.cpp:406 (3)
    //         004046ee     MOV        dword ptr [ESI + 0x8],this
    //                               LAB_004046f1                                                 XREF[1]:     00404686(j)  
    //                              act_list.cpp:409 (9)
    //         004046f1     MOV        EDX,dword ptr [EBX]
    //         004046f3     PUSH       0x1
    //         004046f5     MOV        this,EBX
    //         004046f7     CALL       dword ptr [EDX + 0x1c]
    //                               LAB_004046fa                                                 XREF[1]:     00404626(j)  
    //                              act_list.cpp:410 (8)
    //         004046fa     POP        EDI
    //         004046fb     POP        ESI
    //         004046fc     POP        EBP
    //         004046fd     POP        EBX
    //         004046fe     POP        this
    //         004046ff     RET        0x4
    //         00404702     ??         90h
    //         00404703     NOP
    //         00404704     NOP
    //         00404705     NOP
    //         00404706     NOP
    //         00404707     NOP
    //         00404708     NOP
    //         00404709     NOP
    //         0040470a     NOP
    //         0040470b     NOP
    //         0040470c     NOP
    //         0040470d     NOP
    //         0040470e     NOP
    //         0040470f     NOP
    return;
}

void RGE_Action_List::remove_action() {
    /* TODO: Stub */
    //                              void __thiscall remove_action(RGE_Action_List * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Lis    ECX:4 (auto)   this
    //                               ?remove_action@RGE_Action_List@@QAEXXZ                       XREF[5]:     delete_list:00403fac(c), 
    //                               RGE_Action_List::remove_action                                            inside_obj_update:004044d8(c), 
    //                                                                                                         update:0040452e(c), 
    //                                                                                                         update:00406b80(c), 
    //                                                                                                         update_production_queue:004c9f73(c
    //                              act_list.cpp:416 (4)
    //         00404710     PUSH       ESI
    //         00404711     PUSH       EDI
    //         00404712     MOV        EDI,this
    //                              act_list.cpp:419 (7)
    //         00404714     MOV        ESI,dword ptr [EDI + 0x8]
    //         00404717     TEST       ESI,ESI
    //         00404719     JZ         LAB_00404751
    //                              act_list.cpp:422 (6)
    //         0040471b     MOV        EAX,dword ptr [ESI + 0x4]
    //         0040471e     MOV        dword ptr [EDI + 0x8],EAX
    //                              act_list.cpp:423 (12)
    //         00404721     MOV        this,dword ptr [ESI]
    //         00404723     TEST       this,this
    //         00404725     JZ         LAB_0040472d
    //         00404727     MOV        EDX,dword ptr [this->_padding_]
    //         00404729     PUSH       0x1
    //         0040472b     CALL       dword ptr [EDX]
    //                               LAB_0040472d                                                 XREF[1]:     00404725(j)  
    //                              act_list.cpp:424 (6)
    //         0040472d     PUSH       ESI
    //         0040472e     CALL       free                                             undefined free()
    //                              act_list.cpp:427 (19)
    //         00404733     MOV        EAX,dword ptr [EDI + 0x8]
    //         00404736     ADD        ESP,0x4
    //         00404739     TEST       EAX,EAX
    //         0040473b     JZ         LAB_00404751
    //         0040473d     MOV        this,dword ptr [EDI + 0x4]
    //         00404740     CMP        byte ptr [this->_padding_ + 0x48],0x3
    //         00404744     JNC        LAB_00404751
    //                              act_list.cpp:428 (11)
    //         00404746     MOV        EAX,dword ptr [EAX]
    //         00404748     PUSH       0x0
    //         0040474a     MOV        this,EAX
    //         0040474c     MOV        EDX,dword ptr [EAX]
    //         0040474e     CALL       dword ptr [EDX + 0x1c]
    //                               LAB_00404751                                                 XREF[3]:     00404719(j), 0040473b(j), 
    //                                                                                                         00404744(j)  
    //                              act_list.cpp:430 (3)
    //         00404751     POP        EDI
    //         00404752     POP        ESI
    //         00404753     RET
    //         00404754     ??         90h
    //         00404755     NOP
    //         00404756     NOP
    //         00404757     NOP
    //         00404758     NOP
    //         00404759     NOP
    //         0040475a     NOP
    //         0040475b     NOP
    //         0040475c     NOP
    //         0040475d     NOP
    //         0040475e     NOP
    //         0040475f     NOP
    return;
}

uchar RGE_Action_List::have_action() {
    /* TODO: Stub */
    //                              uchar __thiscall have_action(RGE_Action_List * this)
    //              uchar             AL:1           <RETURN>
    //              RGE_Action_Lis    ECX:4 (auto)   this
    //                               ?have_action@RGE_Action_List@@QAEEXZ                         XREF[38]:    update:00406a88(c), 
    //                               RGE_Action_List::have_action                                              have_action:00406bf6(c), 
    //                                                                                                         update:00413ae7(c), 
    //                                                                                                         attack:00430910(c), 
    //                                                                                                         attack:0043096d(c), 
    //                                                                                                         attack:00430abb(c), 
    //                                                                                                         gather:00430f13(c), 
    //                                                                                                         gather:00430f54(c), 
    //                                                                                                         enter:00431193(c), 
    //                                                                                                         transport:00431272(c), 
    //                                                                                                         currentTargetID:004315c9(c), 
    //                                                                                                         currentTargetX:00431619(c), 
    //                                                                                                         currentTargetY:00431649(c), 
    //                                                                                                         currentTargetZ:00431679(c), 
    //                                                                                                         heal:004cb343(c), 
    //                                                                                                         heal:004cb384(c), 
    //                                                                                                         repair:004cb493(c), 
    //                                                                                                         repair:004cb4d4(c), 
    //                                                                                                         build:004cb603(c), 
    //                                                                                                         build:004cb644(c), [more]
    //                              act_list.cpp:434 (8)
    //         00404760     MOV        EAX,dword ptr [ECX + this->list]
    //         00404763     TEST       EAX,EAX
    //         00404765     SETNZ      AL
    //                              act_list.cpp:439 (1)
    //         00404768     RET
    //         00404769     ??         90h
    //         0040476a     NOP
    //         0040476b     NOP
    //         0040476c     NOP
    //         0040476d     NOP
    //         0040476e     NOP
    //         0040476f     NOP
    return 0;
}

int RGE_Action_List::action_stop() {
    /* TODO: Stub */
    //                              int __thiscall action_stop(RGE_Action_List * this)
    //              int               EAX:4          <RETURN>
    //              RGE_Action_Lis    ECX:4 (auto)   this
    //                               ?action_stop@RGE_Action_List@@QAEHXZ                         XREF[2]:     stop:00406a59(c), 
    //                               RGE_Action_List::action_stop                                              remove_from_production_queue:004c9
    //                              act_list.cpp:444 (7)
    //         00404770     MOV        EAX,dword ptr [ECX + this->list]
    //         00404773     TEST       EAX,EAX
    //         00404775     JZ         LAB_0040477e
    //                              act_list.cpp:446 (7)
    //         00404777     MOV        this,dword ptr [EAX]
    //         00404779     MOV        EAX,dword ptr [this->_padding_]
    //         0040477b     JMP        dword ptr [EAX + 0x2c]
    //                               LAB_0040477e                                                 XREF[1]:     00404775(j)  
    //                              act_list.cpp:448 (2)
    //         0040477e     XOR        EAX,EAX
    //                              act_list.cpp:449 (1)
    //         00404780     RET
    //         00404781     ??         90h
    //         00404782     NOP
    //         00404783     NOP
    //         00404784     NOP
    //         00404785     NOP
    //         00404786     NOP
    //         00404787     NOP
    //         00404788     NOP
    //         00404789     NOP
    //         0040478a     NOP
    //         0040478b     NOP
    //         0040478c     NOP
    //         0040478d     NOP
    //         0040478e     NOP
    //         0040478f     NOP
    return 0;
}

int RGE_Action_List::action_move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    /* TODO: Stub */
    //                              int __thiscall action_move_to(RGE_Action_List * this, RGE_Static_Obj
    //              int               EAX:4          <RETURN>
    //              RGE_Action_Lis    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004047aa(R)  
    //              float             Stack[0x8]:4   param_2                   XREF[1]:     004047a5(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     0040479e(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     00404797(R)  
    //                               ?action_move_to@RGE_Action_List@@QAEHPAVRGE_Static_Object@@  XREF[1]:     move_to:0040633d(c)  
    //                               RGE_Action_List::action_move_to
    //                              act_list.cpp:454 (7)
    //         00404790     MOV        EAX,dword ptr [ECX + this->list]
    //         00404793     TEST       EAX,EAX
    //         00404795     JZ         LAB_004047b5
    //                              act_list.cpp:456 (27)
    //         00404797     MOV        EDX,dword ptr [ESP + param_4]
    //         0040479b     MOV        this,dword ptr [EAX]
    //         0040479d     PUSH       EDX
    //         0040479e     MOV        EDX,dword ptr [ESP + param_3]
    //         004047a2     MOV        EAX,dword ptr [this->_padding_]
    //         004047a4     PUSH       EDX
    //         004047a5     MOV        EDX,dword ptr [ESP + param_2]
    //         004047a9     PUSH       EDX
    //         004047aa     MOV        EDX,dword ptr [ESP + param_1]
    //         004047ae     PUSH       EDX
    //         004047af     CALL       dword ptr [EAX + 0x30]
    //                              act_list.cpp:459 (3)
    //         004047b2     RET        0x10
    //                               LAB_004047b5                                                 XREF[1]:     00404795(j)  
    //                              act_list.cpp:458 (2)
    //         004047b5     XOR        EAX,EAX
    //                              act_list.cpp:459 (3)
    //         004047b7     RET        0x10
    //         004047ba     ??         90h
    //         004047bb     NOP
    //         004047bc     NOP
    //         004047bd     NOP
    //         004047be     NOP
    //         004047bf     NOP
    return 0;
}

int RGE_Action_List::action_work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    /* TODO: Stub */
    //                              int __thiscall action_work(RGE_Action_List * this, RGE_Static_Object
    //              int               EAX:4          <RETURN>
    //              RGE_Action_Lis    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004047da(R)  
    //              float             Stack[0x8]:4   param_2                   XREF[1]:     004047d5(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     004047ce(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     004047c7(R)  
    //                               ?action_work@RGE_Action_List@@QAEHPAVRGE_Static_Object@@MMM@Z XREF[2]:     work2:00406572(c), 
    //                               RGE_Action_List::action_work                                              do_repair:004cc667(c)  
    //                              act_list.cpp:464 (7)
    //         004047c0     MOV        EAX,dword ptr [ECX + this->list]
    //         004047c3     TEST       EAX,EAX
    //         004047c5     JZ         LAB_004047e5
    //                              act_list.cpp:466 (27)
    //         004047c7     MOV        EDX,dword ptr [ESP + param_4]
    //         004047cb     MOV        this,dword ptr [EAX]
    //         004047cd     PUSH       EDX
    //         004047ce     MOV        EDX,dword ptr [ESP + param_3]
    //         004047d2     MOV        EAX,dword ptr [this->_padding_]
    //         004047d4     PUSH       EDX
    //         004047d5     MOV        EDX,dword ptr [ESP + param_2]
    //         004047d9     PUSH       EDX
    //         004047da     MOV        EDX,dword ptr [ESP + param_1]
    //         004047de     PUSH       EDX
    //         004047df     CALL       dword ptr [EAX + 0x34]
    //                              act_list.cpp:469 (3)
    //         004047e2     RET        0x10
    //                               LAB_004047e5                                                 XREF[1]:     004047c5(j)  
    //                              act_list.cpp:468 (2)
    //         004047e5     XOR        EAX,EAX
    //                              act_list.cpp:469 (3)
    //         004047e7     RET        0x10
    //         004047ea     ??         90h
    //         004047eb     NOP
    //         004047ec     NOP
    //         004047ed     NOP
    //         004047ee     NOP
    //         004047ef     NOP
    return 0;
}

int RGE_Action_List::attack_response(RGE_Static_Object* param_1) {
    /* TODO: Stub */
    //                              int __thiscall attack_response(RGE_Action_List * this, RGE_Static_Ob
    //              int               EAX:4          <RETURN>
    //              RGE_Action_Lis    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004047f9(R)  
    //                               ?attack_response@RGE_Action_List@@QAEHPAVRGE_Static_Object@
    //                               RGE_Action_List::attack_response
    //                              act_list.cpp:474 (7)
    //         004047f0     MOV        EAX,dword ptr [ECX + this->list]
    //         004047f3     TEST       EAX,EAX
    //         004047f5     JZ         LAB_0040480b
    //                              act_list.cpp:476 (17)
    //         004047f7     MOV        this,dword ptr [EAX]
    //         004047f9     MOV        EDX,dword ptr [ESP + param_1]
    //         004047fd     PUSH       EDX
    //         004047fe     MOV        EAX,dword ptr [this->_padding_]
    //         00404800     CALL       dword ptr [EAX + 0x38]
    //         00404803     AND        EAX,0xff
    //                              act_list.cpp:479 (3)
    //         00404808     RET        0x4
    //                               LAB_0040480b                                                 XREF[1]:     004047f5(j)  
    //                              act_list.cpp:478 (2)
    //         0040480b     XOR        EAX,EAX
    //                              act_list.cpp:479 (3)
    //         0040480d     RET        0x4
    return 0;
}

int RGE_Action_List::relation_response(long param_1, uchar param_2) {
    /* TODO: Stub */
    //                              int __thiscall relation_response(RGE_Action_List * this, long param_
    //              int               EAX:4          <RETURN>
    //              RGE_Action_Lis    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     0040481e(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     00404817(R)  
    //                               ?relation_response@RGE_Action_List@@QAEHJE@Z
    //                               RGE_Action_List::relation_response
    //                              act_list.cpp:484 (7)
    //         00404810     MOV        EAX,dword ptr [ECX + this->list]
    //         00404813     TEST       EAX,EAX
    //         00404815     JZ         LAB_00404830
    //                              act_list.cpp:486 (22)
    //         00404817     MOV        EDX,dword ptr [ESP + param_2]
    //         0040481b     MOV        this,dword ptr [EAX]
    //         0040481d     PUSH       EDX
    //         0040481e     MOV        EDX,dword ptr [ESP + param_1]
    //         00404822     MOV        EAX,dword ptr [this->_padding_]
    //         00404824     PUSH       EDX
    //         00404825     CALL       dword ptr [EAX + 0x3c]
    //         00404828     AND        EAX,0xff
    //                              act_list.cpp:489 (3)
    //         0040482d     RET        0x8
    //                               LAB_00404830                                                 XREF[1]:     00404815(j)  
    //                              act_list.cpp:488 (2)
    //         00404830     XOR        EAX,EAX
    //                              act_list.cpp:489 (3)
    //         00404832     RET        0x8
    //         00404835     ??         90h
    //         00404836     NOP
    //         00404837     NOP
    //         00404838     NOP
    //         00404839     NOP
    //         0040483a     NOP
    //         0040483b     NOP
    //         0040483c     NOP
    //         0040483d     NOP
    //         0040483e     NOP
    //         0040483f     NOP
    return 0;
}

RGE_Action* RGE_Action_List::get_action() {
    /* TODO: Stub */
    //                              RGE_Action * __thiscall get_action(RGE_Action_List * this)
    //              RGE_Action *      EAX:4          <RETURN>
    //              RGE_Action_Lis    ECX:4 (auto)   this
    //                               ?get_action@RGE_Action_List@@QAEPAVRGE_Action@@XZ            XREF[91]:    RGE_Action_Enter:004024cf(c), 
    //                               RGE_Action_List::get_action                                               RGE_Action_Enter:004025b2(c), 
    //                                                                                                         RGE_Action_Enter:004025c7(c), 
    //                                                                                                         update:00406a97(c), 
    //                                                                                                         update:00406aac(c), 
    //                                                                                                         get_target_obj:00406c16(c), 
    //                                                                                                         enter:004311a2(c), 
    //                                                                                                         enter:004311b8(c), 
    //                                                                                                         currentTargetX:00431628(c), 
    //                                                                                                         currentTargetY:00431658(c), 
    //                                                                                                         currentTargetZ:00431688(c), 
    //                                                                                                         work_status:004c9626(c), 
    //                                                                                                         production_queue_status:004ca04d(c
    //                                                                                                         build:004cb612(c), 
    //                                                                                                         build:004cb628(c), 
    //                                                                                                         build:004cb653(c), 
    //                                                                                                         build:004cb66b(c), 
    //                                                                                                         wonderToAttack:004e3705(c), 
    //                                                                                                         wonderToAttack:004e3721(c), 
    //                                                                                                         wonderToAttack:004e3733(c), [more]
    //                              act_list.cpp:493 (7)
    //         00404840     MOV        EAX,dword ptr [ECX + this->list]
    //         00404843     TEST       EAX,EAX
    //         00404845     JZ         LAB_0040484a
    //                              act_list.cpp:495 (2)
    //         00404847     MOV        EAX,dword ptr [EAX]
    //                              act_list.cpp:498 (1)
    //         00404849     RET
    //                               LAB_0040484a                                                 XREF[1]:     00404845(j)  
    //                              act_list.cpp:497 (2)
    //         0040484a     XOR        EAX,EAX
    //                              act_list.cpp:498 (1)
    //         0040484c     RET
    //         0040484d     ??         90h
    //         0040484e     NOP
    //         0040484f     NOP
    return 0;
}

RGE_Task* RGE_Action_List::get_task() {
    /* TODO: Stub */
    //                              RGE_Task * __thiscall get_task(RGE_Action_List * this)
    //              RGE_Task *        EAX:4          <RETURN>
    //              RGE_Action_Lis    ECX:4 (auto)   this
    //                               ?get_task@RGE_Action_List@@QAEPAVRGE_Task@@XZ                XREF[2]:     work2:00406543(c), 
    //                               RGE_Action_List::get_task                                                 do_repair:004cc641(c)  
    //                              act_list.cpp:502 (7)
    //         00404850     MOV        EAX,dword ptr [ECX + this->list]
    //         00404853     TEST       EAX,EAX
    //         00404855     JZ         LAB_0040485d
    //                              act_list.cpp:504 (5)
    //         00404857     MOV        EAX,dword ptr [EAX]
    //         00404859     MOV        EAX,dword ptr [EAX + 0x30]
    //                              act_list.cpp:507 (1)
    //         0040485c     RET
    //                               LAB_0040485d                                                 XREF[1]:     00404855(j)  
    //                              act_list.cpp:506 (2)
    //         0040485d     XOR        EAX,EAX
    //                              act_list.cpp:507 (1)
    //         0040485f     RET
    return 0;
}

void RGE_Action_List::copy_obj(RGE_Master_Action_Object* param_1) {
    /* TODO: Stub */
    //                              void __thiscall copy_obj(RGE_Action_List * this, RGE_Master_Action_O
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Lis    ECX:4 (auto)   this
    //              RGE_Master_Act    Stack[0x4]:4   param_1                   XREF[1]:     00404869(R)  
    //                               ?copy_obj@RGE_Action_List@@UAEXPAVRGE_Master_Action_Object@  XREF[2]:     0056e2ac(*), 00575184(*)  
    //                               RGE_Action_List::copy_obj
    //                              act_list.cpp:511 (1)
    //         00404860     PUSH       ESI
    //                              act_list.cpp:514 (12)
    //         00404861     MOV        ESI,dword ptr [ECX + this->list]
    //         00404864     TEST       ESI,ESI
    //         00404866     JZ         LAB_0040487d
    //         00404868     PUSH       EDI
    //         00404869     MOV        EDI,dword ptr [ESP + param_1]
    //                               LAB_0040486d                                                 XREF[1]:     0040487a(j)  
    //                              act_list.cpp:515 (15)
    //         0040486d     MOV        this,dword ptr [ESI]
    //         0040486f     PUSH       EDI
    //         00404870     MOV        EAX,dword ptr [this->_padding_]
    //         00404872     CALL       dword ptr [EAX + 0x40]
    //         00404875     MOV        ESI,dword ptr [ESI + 0x4]
    //         00404878     TEST       ESI,ESI
    //         0040487a     JNZ        LAB_0040486d
    //                              act_list.cpp:511 (1)
    //         0040487c     POP        EDI
    //                               LAB_0040487d                                                 XREF[1]:     00404866(j)  
    //                              act_list.cpp:516 (4)
    //         0040487d     POP        ESI
    //         0040487e     RET        0x4
    //         00404881     ??         90h
    //         00404882     NOP
    //         00404883     NOP
    //         00404884     NOP
    //         00404885     NOP
    //         00404886     NOP
    //         00404887     NOP
    //         00404888     NOP
    //         00404889     NOP
    //         0040488a     NOP
    //         0040488b     NOP
    //         0040488c     NOP
    //         0040488d     NOP
    //         0040488e     NOP
    //         0040488f     NOP
    //                              * public: virtual void __thiscall RGE_Action_List::copy_obj_sprites(class RGE_Master_Action_Object *... *
    //                              void __thiscall copy_obj_sprites(RGE_Action_List * this, RGE_Master_
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Lis    ECX:4 (auto)   this
    //              RGE_Master_Act    Stack[0x4]:4   param_1                   XREF[1]:     0040489e(R)  
    //              RGE_Task *        Stack[0x8]:4   param_2                   XREF[1]:     004048a3(R)  
    //              RGE_Task *        Stack[0xc]:4   param_3                   XREF[1]:     00404899(R)  
    //                               ?copy_obj_sprites@RGE_Action_List@@UAEXPAVRGE_Master_Action  XREF[2]:     0056e2b0(*), 00575188(*)  
    //                               RGE_Action_List::copy_obj_sprites
    //                              act_list.cpp:520 (1)
    //         00404890     PUSH       ESI
    //                              act_list.cpp:523 (22)
    //         00404891     MOV        ESI,dword ptr [ECX + this->list]
    //         00404894     TEST       ESI,ESI
    //         00404896     JZ         LAB_004048bb
    //         00404898     PUSH       EDI
    //         00404899     MOV        EDI,dword ptr [ESP + param_3]
    //         0040489d     PUSH       EBP
    //         0040489e     MOV        EBP,dword ptr [ESP + param_1]
    //         004048a2     PUSH       EBX
    //         004048a3     MOV        EBX,dword ptr [ESP + param_2]
    //                               LAB_004048a7                                                 XREF[1]:     004048b6(j)  
    //                              act_list.cpp:524 (20)
    //         004048a7     MOV        this,dword ptr [ESI]
    //         004048a9     PUSH       EDI
    //         004048aa     PUSH       EBX=>DAT_fffffff8
    //         004048ab     PUSH       EBP=>DAT_fffffff4
    //         004048ac     MOV        EAX,dword ptr [this->_padding_]
    //         004048ae     CALL       dword ptr [EAX + 0x44]
    //         004048b1     MOV        ESI,dword ptr [ESI + 0x4]
    //         004048b4     TEST       ESI,ESI
    //         004048b6     JNZ        LAB_004048a7
    //         004048b8     POP        EBX
    //         004048b9     POP        EBP
    //         004048ba     POP        EDI
    //                               LAB_004048bb                                                 XREF[1]:     00404896(j)  
    //                              act_list.cpp:525 (4)
    //         004048bb     POP        ESI
    //         004048bc     RET        0xc
    //         004048bf     ??         90h
    return;
}

void RGE_Action_List::get_action_name(char* param_1) {
    /* TODO: Stub */
    //                              void __thiscall get_action_name(RGE_Action_List * this, char * param
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Lis    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[2]:     00404930(R), 00404959(R)  
    //                               ?get_action_name@RGE_Action_List@@UAEXPAD@Z                  XREF[2]:     get_action_name:004d0d1e(c), 
    //                               RGE_Action_List::get_action_name                                          0056e2a8(*)  
    //                              act_list.cpp:529 (9)
    //         004048c0     MOV        EAX,dword ptr [ECX + this->list]
    //         004048c3     PUSH       ESI
    //         004048c4     TEST       EAX,EAX
    //         004048c6     PUSH       EDI
    //         004048c7     JNZ        LAB_004048d0
    //                              act_list.cpp:532 (5)
    //         004048c9     MOV        EDI,s_None                                       = 4Eh
    //                              act_list.cpp:533 (2)
    //         004048ce     JMP        LAB_0040494a
    //                               LAB_004048d0                                                 XREF[1]:     004048c7(j)  
    //                              act_list.cpp:536 (27)
    //         004048d0     MOV        this,dword ptr [EAX]
    //         004048d2     MOVSX      EAX,word ptr [ECX + this->obj]
    //         004048d6     DEC        EAX
    //         004048d7     CMP        EAX,0x14
    //         004048da     JA         switchD_004048e4::caseD_2
    //         004048dc     XOR        EDX,EDX
    //         004048de     MOV        DL,byte ptr [EAX + 0x404994]=>PTR_caseD_2_0040
    //                               switchD_004048e4::switchD
    //         004048e4     JMP        dword ptr [EDX*0x4 + switchD_004048e4::switchd   = 0040490e
    //                               switchD_004048e4::caseD_9                                    XREF[2]:     004048e4(j), 00404980(*)  
    //                              act_list.cpp:538 (7)
    //         004048eb     MOV        EDI,s_Attack                                     = 41h
    //         004048f0     JMP        LAB_0040494a
    //                               switchD_004048e4::caseD_a                                    XREF[2]:     004048e4(j), 00404984(*)  
    //                              act_list.cpp:539 (7)
    //         004048f2     MOV        EDI,s_Bird                                       = "Bird"
    //         004048f7     JMP        LAB_00404921
    //                               switchD_004048e4::caseD_4                                    XREF[2]:     004048e4(j), 00404974(*)  
    //                              act_list.cpp:540 (7)
    //         004048f9     MOV        EDI,s_Explore                                    = "Explore"
    //         004048fe     JMP        LAB_0040494a
    //                               switchD_004048e4::caseD_5                                    XREF[2]:     004048e4(j), 00404978(*)  
    //                              act_list.cpp:541 (7)
    //         00404900     MOV        EDI,s_Gather                                     = 47h
    //         00404905     JMP        LAB_00404921
    //                               switchD_004048e4::caseD_8                                    XREF[2]:     004048e4(j), 0040497c(*)  
    //                              act_list.cpp:542 (7)
    //         00404907     MOV        EDI,s_Missile                                    = "Missile"
    //         0040490c     JMP        LAB_0040494a
    //                               switchD_004048e4::caseD_1                                    XREF[2]:     004048e4(j), 00404970(*)  
    //                              act_list.cpp:543 (7)
    //         0040490e     MOV        EDI,s_MoveTo                                     = "MoveTo"
    //         00404913     JMP        LAB_00404921
    //                               switchD_004048e4::caseD_14                                   XREF[2]:     004048e4(j), 00404988(*)  
    //                              act_list.cpp:544 (7)
    //         00404915     MOV        EDI,s_RunAway                                    = "RunAway"
    //         0040491a     JMP        LAB_0040494a
    //                               switchD_004048e4::caseD_15                                   XREF[2]:     004048e4(j), 0040498c(*)  
    //                              act_list.cpp:545 (31)
    //         0040491c     MOV        EDI,s_Make                                       = 4Dh
    //                               LAB_00404921                                                 XREF[3]:     004048f7(j), 00404905(j), 
    //                                                                                                         00404913(j)  
    //         00404921     OR         this,0xffffffff
    //         00404924     XOR        EAX,EAX
    //         00404926     SCASB.RE   ES:EDI=>s_Make                                   = 4Dh
    //                                                                                  = 00656b61
    //                                                                                  = "MoveTo"
    //                                                                                  = 47h
    //                                                                                  = "Bird"
    //         00404928     NOT        this
    //         0040492a     SUB        EDI,this
    //         0040492c     MOV        EDX,this
    //         0040492e     MOV        ESI,EDI
    //         00404930     MOV        EDI,dword ptr [ESP + param_1]
    //         00404934     SHR        this,0x2
    //         00404937     MOVSD.REP  ES:EDI,ESI
    //         00404939     MOV        this,EDX
    //                              act_list.cpp:546 (5)
    //         0040493b     AND        this,0x3
    //         0040493e     MOVSB.REP  ES:EDI,ESI
    //                              act_list.cpp:548 (5)
    //         00404940     POP        EDI
    //         00404941     POP        ESI
    //         00404942     RET        0x4
    //                               switchD_004048e4::caseD_3                                    XREF[3]:     004048da(j), 004048e4(j), 
    //                               switchD_004048e4::caseD_6                                                 00404990(*)  
    //                               switchD_004048e4::caseD_7
    //                               switchD_004048e4::caseD_b
    //                               switchD_004048e4::caseD_c
    //                               switchD_004048e4::caseD_d
    //                               switchD_004048e4::caseD_e
    //                               switchD_004048e4::caseD_f
    //                               switchD_004048e4::caseD_10
    //                               switchD_004048e4::caseD_11
    //                               switchD_004048e4::caseD_12
    //                               switchD_004048e4::caseD_13
    //                               switchD_004048e4::caseD_2
    //                              act_list.cpp:546 (36)
    //         00404945     MOV        EDI,s_Unknown                                    = 55h
    //                               LAB_0040494a                                                 XREF[5]:     004048ce(j), 004048f0(j), 
    //                                                                                                         004048fe(j), 0040490c(j), 
    //                                                                                                         0040491a(j)  
    //         0040494a     OR         this,0xffffffff
    //         0040494d     XOR        EAX,EAX
    //         0040494f     SCASB.RE   ES:EDI=>s_None                                   = 55h
    //                                                                                  = "RunAway"
    //                                                                                  = "Missile"
    //                                                                                  = "Explore"
    //                                                                                  = 41h
    //                                                                                  = 4Eh
    //         00404951     NOT        this
    //         00404953     SUB        EDI,this
    //         00404955     MOV        EAX,this
    //         00404957     MOV        ESI,EDI
    //         00404959     MOV        EDI,dword ptr [ESP + param_1]
    //         0040495d     SHR        this,0x2
    //         00404960     MOVSD.REP  ES:EDI,ESI
    //         00404962     MOV        this,EAX
    //         00404964     AND        this,0x3
    //         00404967     MOVSB.REP  ES:EDI,ESI
    //                              act_list.cpp:548 (64)
    //         00404969     POP        EDI
    //         0040496a     POP        ESI
    //         0040496b     RET        0x4
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_0040496e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0040496e
    //         0040496e     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004048e4::switchdataD_00404970                       XREF[1]:     get_action_name:004048e4(*)  
    //         00404970     addr       switchD_004048e4::caseD_1
    //         00404974     addr       switchD_004048e4::caseD_4
    //         00404978     addr       switchD_004048e4::caseD_5
    //         0040497c     addr       switchD_004048e4::caseD_8
    //         00404980     addr       switchD_004048e4::caseD_9
    //         00404984     addr       switchD_004048e4::caseD_a
    //         00404988     addr       switchD_004048e4::caseD_14
    //         0040498c     addr       switchD_004048e4::caseD_15
    //                               PTR_caseD_2_00404990+3                                       XREF[0,1]:   get_action_name:004048de(*)  
    //         00404990     addr       switchD_004048e4::caseD_2
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004048e4::switchdataD_00404994
    //         00404994     db         0h
    //         00404995     db         8h
    //         00404996     db         8h
    //         00404997     db         1h
    //         00404998     db         2h
    //         00404999     db         8h
    //         0040499a     db         8h
    //         0040499b     db         3h
    //         0040499c     db         4h
    //         0040499d     db         5h
    //         0040499e     db         8h
    //         0040499f     db         8h
    //         004049a0     db         8h
    //         004049a1     db         8h
    //         004049a2     db         8h
    //         004049a3     db         8h
    //         004049a4     db         8h
    //         004049a5     db         8h
    //         004049a6     db         8h
    //         004049a7     db         6h
    //         004049a8     db         7h
    //         004049a9     ??         90h
    //         004049aa     ??         90h
    //         004049ab     ??         90h
    //         004049ac     ??         90h
    //         004049ad     ??         90h
    //         004049ae     ??         90h
    //         004049af     ??         90h
    return;
}

RGE_Action* RGE_Action_List::create_task_action(RGE_Task* param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

void RGE_Action_List::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

