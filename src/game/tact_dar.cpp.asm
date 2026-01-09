#include "common.h"
#include "tact_dar.h"

TRIBE_Action_Discovery_Artifact::~TRIBE_Action_Discovery_Artifact() {
    /* TODO: Stub */
    //                              void __thiscall ~TRIBE_Action_Discovery_Artifact(TRIBE_Action_Discov
    //              void              <VOID>         <RETURN>
    //              TRIBE_Action_D    ECX:4 (auto)   this
    //                               ??1TRIBE_Action_Discovery_Artifact@@UAE@XZ                   XREF[1]:     `vector_deleting_destructor':004ce
    //                               TRIBE_Action_Discovery_Artifact::~TRIBE_Action_Discovery_Ar
    //         004ce5e0     JMP        RGE_Action::~RGE_Action
    //         004ce5e5     ??         90h
    //         004ce5e6     NOP
    //         004ce5e7     NOP
    //         004ce5e8     NOP
    //         004ce5e9     NOP
    //         004ce5ea     NOP
    //         004ce5eb     NOP
    //         004ce5ec     NOP
    //         004ce5ed     NOP
    //         004ce5ee     NOP
    //         004ce5ef     NOP
    //                              * public: __thiscall TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(class RGE_Acti... *
    //                              undefined __thiscall TRIBE_Action_Discovery_Artifact(TRIBE_Action_Di
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Action_D    ECX:4 (auto)   this
    //              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004ce606(R)  
    //              RGE_Task *        Stack[0x8]:4   param_2                   XREF[1]:     004ce619(R)  
    //              RGE_Static_Obj    Stack[0xc]:4   param_3                   XREF[1]:     004ce61d(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004ce627(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004ce655(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004ce610(W)  
    //                               ??0TRIBE_Action_Discovery_Artifact@@QAE@PAVRGE_Action_Objec  XREF[1]:     create_task_action:004d08c0(c)  
    //                               TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Art
    //                              tact_dar.cpp:42 (41)
    //         004ce5f0     PUSH       -0x1
    //         004ce5f2     PUSH       FUN_0055fe48
    //         004ce5f7     MOV        EAX,FS:[0x0]
    //         004ce5fd     PUSH       EAX
    //         004ce5fe     MOV        dword ptr FS:[0x0],ESP
    //         004ce605     PUSH       this
    //         004ce606     MOV        EAX,dword ptr [ESP + param_1]
    //         004ce60a     PUSH       ESI
    //         004ce60b     MOV        ESI,this
    //         004ce60d     PUSH       0x1
    //         004ce60f     PUSH       EAX
    //         004ce610     MOV        dword ptr [ESP + local_10],ESI
    //         004ce614     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, RGE_A
    //                              tact_dar.cpp:45 (4)
    //         004ce619     MOV        this,dword ptr [ESP + param_2]
    //                              tact_dar.cpp:46 (35)
    //         004ce61d     MOV        EDX,dword ptr [ESP + param_3]
    //         004ce621     MOV        dword ptr [ESI + 0x30],this
    //         004ce624     PUSH       EDX
    //         004ce625     MOV        this,ESI
    //         004ce627     MOV        dword ptr [ESP + local_4],0x0
    //         004ce62f     MOV        dword ptr [ESI],TRIBE_Action_Discovery_Artifac   = 004ce5c0
    //         004ce635     MOV        word ptr [ESI + 0x4],0x6c
    //         004ce63b     CALL       RGE_Action::set_target_obj                       void set_target_obj(RGE_Action * this, RGE_St
    //                              tact_dar.cpp:47 (21)
    //         004ce640     MOV        EAX,dword ptr [ESI + 0x8]
    //         004ce643     PUSH       0x1
    //         004ce645     MOV        this,dword ptr [EAX + 0xc]
    //         004ce648     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004ce64b     MOVSX      EAX,word ptr [EDX + 0x3c]
    //         004ce64f     PUSH       EAX
    //         004ce650     CALL       calloc                                           undefined calloc()
    //                              tact_dar.cpp:48 (26)
    //         004ce655     MOV        this,dword ptr [ESP + local_c]
    //         004ce659     ADD        ESP,0x8
    //         004ce65c     MOV        dword ptr [ESI + 0x40],EAX
    //         004ce65f     MOV        EAX,ESI
    //         004ce661     MOV        dword ptr FS:[0x0],this
    //         004ce668     POP        ESI
    //         004ce669     ADD        ESP,0x10
    //         004ce66c     RET        0xc
    //         004ce66f     ??         90h
    //                              * public: __thiscall TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(class RGE_Acti... *
    //                              undefined __thiscall TRIBE_Action_Discovery_Artifact(TRIBE_Action_Di
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Action_D    ECX:4 (auto)   this
    //              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004ce670(R)  
    //              RGE_Task *        Stack[0x8]:4   param_2                   XREF[1]:     004ce67f(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     004ce683(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     004ce687(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[1]:     004ce68e(R)  
    //                               ??0TRIBE_Action_Discovery_Artifact@@QAE@PAVRGE_Action_Objec  XREF[1]:     create_task_action:004d090b(c)  
    //                               TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Art
    //                              tact_dar.cpp:53 (15)
    //         004ce670     MOV        EAX,dword ptr [ESP + param_1]
    //         004ce674     PUSH       ESI
    //         004ce675     PUSH       0x1
    //         004ce677     MOV        ESI,this
    //         004ce679     PUSH       EAX
    //         004ce67a     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, RGE_A
    //                              tact_dar.cpp:56 (4)
    //         004ce67f     MOV        this,dword ptr [ESP + param_2]
    //                              tact_dar.cpp:57 (4)
    //         004ce683     MOV        EDX,dword ptr [ESP + param_3]
    //                              tact_dar.cpp:58 (7)
    //         004ce687     MOV        EAX,dword ptr [ESP + param_4]
    //         004ce68b     MOV        dword ptr [ESI + 0x30],this
    //                              tact_dar.cpp:59 (7)
    //         004ce68e     MOV        this,dword ptr [ESP + param_5]
    //         004ce692     MOV        dword ptr [ESI + 0x20],EDX
    //                              tact_dar.cpp:60 (45)
    //         004ce695     MOV        EDX,dword ptr [ESI + 0x8]
    //         004ce698     MOV        dword ptr [ESI],TRIBE_Action_Discovery_Artifac   = 004ce5c0
    //         004ce69e     MOV        word ptr [ESI + 0x4],0x6c
    //         004ce6a4     MOV        dword ptr [ESI + 0x24],EAX
    //         004ce6a7     MOV        dword ptr [ESI + 0x28],this
    //         004ce6aa     MOV        EAX,dword ptr [EDX + 0xc]
    //         004ce6ad     PUSH       0x1
    //         004ce6af     MOV        this,dword ptr [EAX + 0x3c]
    //         004ce6b2     MOVSX      EDX,word ptr [ECX + this->_padding_]
    //         004ce6b6     PUSH       EDX
    //         004ce6b7     CALL       calloc                                           undefined calloc()
    //         004ce6bc     ADD        ESP,0x8
    //         004ce6bf     MOV        dword ptr [ESI + 0x40],EAX
    //                              tact_dar.cpp:61 (6)
    //         004ce6c2     MOV        EAX,ESI
    //         004ce6c4     POP        ESI
    //         004ce6c5     RET        0x14
    //         004ce6c8     ??         90h
    //         004ce6c9     NOP
    //         004ce6ca     NOP
    //         004ce6cb     NOP
    //         004ce6cc     NOP
    //         004ce6cd     NOP
    //         004ce6ce     NOP
    //         004ce6cf     NOP
}

void TRIBE_Action_Discovery_Artifact::save(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall save(TRIBE_Action_Discovery_Artifact * this, int par
    //              void              <VOID>         <RETURN>
    //              TRIBE_Action_D    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004ce6d2(R)  
    //                               ?save@TRIBE_Action_Discovery_Artifact@@UAEXH@Z               XREF[1]:     00575024(*)  
    //                               TRIBE_Action_Discovery_Artifact::save
    //                              tact_dar.cpp:65 (2)
    //         004ce6d0     PUSH       ESI
    //         004ce6d1     PUSH       EDI
    //                              tact_dar.cpp:66 (12)
    //         004ce6d2     MOV        EDI,dword ptr [ESP + param_1]
    //         004ce6d6     MOV        ESI,this
    //         004ce6d8     PUSH       EDI
    //         004ce6d9     CALL       RGE_Action::save                                 void save(RGE_Action * this, int param_1)
    //                              tact_dar.cpp:68 (27)
    //         004ce6de     MOV        EAX,dword ptr [ESI + 0x8]
    //         004ce6e1     MOV        this,dword ptr [EAX + 0xc]
    //         004ce6e4     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004ce6e7     MOV        this,dword ptr [ESI + 0x40]
    //         004ce6ea     MOVSX      EAX,word ptr [EDX + 0x3c]
    //         004ce6ee     PUSH       EAX
    //         004ce6ef     PUSH       this
    //         004ce6f0     PUSH       EDI
    //         004ce6f1     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004ce6f6     ADD        ESP,0xc
    //                              tact_dar.cpp:69 (5)
    //         004ce6f9     POP        EDI
    //         004ce6fa     POP        ESI
    //         004ce6fb     RET        0x4
    //         004ce6fe     ??         90h
    //         004ce6ff     NOP
    return;
}

void TRIBE_Action_Discovery_Artifact::first_in_stack(uchar param_1) {
    /* TODO: Stub */
    //                              void __thiscall first_in_stack(TRIBE_Action_Discovery_Artifact * thi
    //              void              <VOID>         <RETURN>
    //              TRIBE_Action_D    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004ce700(R)  
    //                               ?first_in_stack@TRIBE_Action_Discovery_Artifact@@UAEXE@Z     XREF[1]:     0057502c(*)  
    //                               TRIBE_Action_Discovery_Artifact::first_in_stack
    //                              tact_dar.cpp:73 (8)
    //         004ce700     MOV        AL,byte ptr [ESP + param_1]
    //         004ce704     TEST       AL,AL
    //         004ce706     JZ         LAB_004ce70f
    //                              tact_dar.cpp:75 (7)
    //         004ce708     MOV        EAX,dword ptr [this->_padding_]
    //         004ce70a     PUSH       0x6
    //         004ce70c     CALL       dword ptr [EAX + 0x5c]
    //                               LAB_004ce70f                                                 XREF[1]:     004ce706(j)  
    //                              tact_dar.cpp:76 (3)
    //         004ce70f     RET        0x4
    //         004ce712     ??         90h
    //         004ce713     NOP
    //         004ce714     NOP
    //         004ce715     NOP
    //         004ce716     NOP
    //         004ce717     NOP
    //         004ce718     NOP
    //         004ce719     NOP
    //         004ce71a     NOP
    //         004ce71b     NOP
    //         004ce71c     NOP
    //         004ce71d     NOP
    //         004ce71e     NOP
    //         004ce71f     NOP
    return;
}

void TRIBE_Action_Discovery_Artifact::set_state(uchar param_1) {
    /* TODO: Stub */
    //                              void __thiscall set_state(TRIBE_Action_Discovery_Artifact * this, uc
    //              void              <VOID>         <RETURN>
    //              TRIBE_Action_D    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004ce720(R)  
    //                               ?set_state@TRIBE_Action_Discovery_Artifact@@MAEXE@Z          XREF[1]:     0057506c(*)  
    //                               TRIBE_Action_Discovery_Artifact::set_state
    //                              tact_dar.cpp:80 (4)
    //         004ce720     MOV        AL,byte ptr [ESP + param_1]
    //                              tact_dar.cpp:86 (7)
    //         004ce724     CMP        AL,0xa
    //         004ce726     MOV        byte ptr [ECX + this->_padding_],AL
    //         004ce729     JNZ        LAB_004ce732
    //                              tact_dar.cpp:89 (7)
    //         004ce72b     MOV        dword ptr [ECX + this->_padding_],0x40400000
    //                               LAB_004ce732                                                 XREF[1]:     004ce729(j)  
    //                              tact_dar.cpp:92 (3)
    //         004ce732     RET        0x4
    //         004ce735     ??         90h
    //         004ce736     NOP
    //         004ce737     NOP
    //         004ce738     NOP
    //         004ce739     NOP
    //         004ce73a     NOP
    //         004ce73b     NOP
    //         004ce73c     NOP
    //         004ce73d     NOP
    //         004ce73e     NOP
    //         004ce73f     NOP
    return;
}

uchar TRIBE_Action_Discovery_Artifact::update() {
    /* TODO: Stub */
    //                              uchar __thiscall update(TRIBE_Action_Discovery_Artifact * this)
    //              uchar             AL:1           <RETURN>
    //              TRIBE_Action_D    ECX:4 (auto)   this
    //                               ?update@TRIBE_Action_Discovery_Artifact@@UAEEXZ              XREF[1]:     00575038(*)  
    //                               TRIBE_Action_Discovery_Artifact::update
    //                              tact_dar.cpp:96 (3)
    //         004ce740     PUSH       ESI
    //         004ce741     MOV        ESI,this
    //                              tact_dar.cpp:103 (18)
    //         004ce743     XOR        EAX,EAX
    //         004ce745     MOV        AL,byte ptr [ESI + 0xc]
    //         004ce748     DEC        EAX
    //         004ce749     JZ         LAB_004ce798
    //         004ce74b     SUB        EAX,0x5
    //         004ce74e     JZ         LAB_004ce784
    //         004ce750     SUB        EAX,0x4
    //         004ce753     JNZ        LAB_004ce794
    //                              tact_dar.cpp:106 (18)
    //         004ce755     MOV        EAX,dword ptr [ESI + 0x8]
    //         004ce758     FLD        float ptr [ESI + 0x2c]
    //         004ce75b     MOV        this,dword ptr [EAX + 0xc]
    //         004ce75e     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004ce761     FSUB       float ptr [EDX + 0x84]
    //                              tact_dar.cpp:107 (16)
    //         004ce767     FCOM       double ptr [DAT_00575070]                        = align(10)
    //         004ce76d     FSTP       float ptr [ESI + 0x2c]
    //         004ce770     FNSTSW     AX
    //         004ce772     TEST       AH,0x41
    //         004ce775     JZ         LAB_004ce794
    //                              tact_dar.cpp:108 (9)
    //         004ce777     MOV        EAX,dword ptr [ESI]
    //         004ce779     PUSH       0x6
    //         004ce77b     MOV        this,ESI
    //         004ce77d     CALL       dword ptr [EAX + 0x5c]
    //                              tact_dar.cpp:120 (2)
    //         004ce780     XOR        AL,AL
    //                              tact_dar.cpp:121 (2)
    //         004ce782     POP        ESI
    //         004ce783     RET
    //                               LAB_004ce784                                                 XREF[1]:     004ce74e(j)  
    //                              tact_dar.cpp:112 (7)
    //         004ce784     MOV        this,ESI
    //         004ce786     CALL       TRIBE_Action_Discovery_Artifact::check_objects   void check_objects(TRIBE_Action_Discovery_Art
    //                              tact_dar.cpp:113 (9)
    //         004ce78b     MOV        EDX,dword ptr [ESI]
    //         004ce78d     PUSH       0xa
    //         004ce78f     MOV        this,ESI
    //         004ce791     CALL       dword ptr [EDX + 0x5c]
    //                               LAB_004ce794                                                 XREF[2]:     004ce753(j), 004ce775(j)  
    //                              tact_dar.cpp:120 (2)
    //         004ce794     XOR        AL,AL
    //                              tact_dar.cpp:121 (2)
    //         004ce796     POP        ESI
    //         004ce797     RET
    //                               LAB_004ce798                                                 XREF[1]:     004ce749(j)  
    //                              tact_dar.cpp:117 (2)
    //         004ce798     MOV        AL,0x1
    //                              tact_dar.cpp:121 (2)
    //         004ce79a     POP        ESI
    //         004ce79b     RET
    //         004ce79c     ??         90h
    //         004ce79d     NOP
    //         004ce79e     NOP
    //         004ce79f     NOP
    return 0;
}

void TRIBE_Action_Discovery_Artifact::check_objects() {
    /* TODO: Stub */
    //                              void __thiscall check_objects(TRIBE_Action_Discovery_Artifact * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Action_D    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004ce810(W)  
    //              RGE_Map *         Stack[-0x8]:4  map                       XREF[1]:     004ce7a9(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004ce866(W)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004ce88a(W)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[2]:     004ce862(W), 004ce894(R)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[4]:     004ce7f2(W), 004ce825(R), 004ce835(W), 004ce86e(R)  
    //              short             Stack[-0x1c]:2 x1                        XREF[4]:     004ce7cd(W), 004ce804(R), 004ce816(W), 004ce86a(R)  
    //              short             Stack[-0x20]:2 x0
    //                               ?check_objects@TRIBE_Action_Discovery_Artifact@@IAEXXZ       XREF[1]:     update:004ce786(c)  
    //                               TRIBE_Action_Discovery_Artifact::check_objects
    //                              tact_dar.cpp:125 (13)
    //         004ce7a0     SUB        ESP,0x1c
    //         004ce7a3     PUSH       EBX
    //         004ce7a4     PUSH       EBP
    //         004ce7a5     MOV        EBP,this
    //         004ce7a7     PUSH       ESI
    //         004ce7a8     PUSH       EDI
    //         004ce7a9     MOV        dword ptr [ESP + map],EBP
    //                              tact_dar.cpp:126 (23)
    //         004ce7ad     MOV        ESI,dword ptr [EBP + 0x8]
    //         004ce7b0     FLD        float ptr [ESI + 0x38]
    //         004ce7b3     FSUB       float ptr [null_00575078]                        = align(2)
    //         004ce7b9     MOV        EDI,dword ptr [ESI + 0x8]
    //         004ce7bc     FSUB       float ptr [EDI + 0x30]
    //         004ce7bf     CALL       __ftol                                           undefined __ftol()
    //                              tact_dar.cpp:127 (21)
    //         004ce7c4     FLD        float ptr [ESI + 0x3c]
    //         004ce7c7     FSUB       float ptr [null_00575078]                        = align(2)
    //         004ce7cd     MOV        dword ptr [ESP + x1],EAX
    //         004ce7d1     FSUB       float ptr [EDI + 0x34]
    //         004ce7d4     CALL       __ftol                                           undefined __ftol()
    //                              tact_dar.cpp:128 (19)
    //         004ce7d9     FLD        float ptr [EDI + 0x30]
    //         004ce7dc     FADD       float ptr [ESI + 0x38]
    //         004ce7df     MOV        EBX,EAX
    //         004ce7e1     FSUB       float ptr [DAT_0057507c]
    //         004ce7e7     CALL       __ftol                                           undefined __ftol()
    //                              tact_dar.cpp:129 (21)
    //         004ce7ec     FLD        float ptr [EDI + 0x34]
    //         004ce7ef     FADD       float ptr [ESI + 0x3c]
    //         004ce7f2     MOV        dword ptr [ESP + local_18],EAX
    //         004ce7f6     FSUB       float ptr [DAT_0057507c]
    //         004ce7fc     CALL       __ftol                                           undefined __ftol()
    //                              tact_dar.cpp:134 (3)
    //         004ce801     MOV        this,dword ptr [ESI + 0xc]
    //                              tact_dar.cpp:143 (26)
    //         004ce804     CMP        word ptr [ESP + x1],0x0
    //         004ce80a     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004ce80d     MOV        EDX,dword ptr [EDX + 0x28]
    //         004ce810     MOV        dword ptr [ESP + local_4],EDX
    //         004ce814     JGE        LAB_004ce81e
    //         004ce816     MOV        dword ptr [ESP + x1],0x0
    //                               LAB_004ce81e                                                 XREF[1]:     004ce814(j)  
    //                              tact_dar.cpp:144 (7)
    //         004ce81e     TEST       BX,BX
    //         004ce821     JGE        LAB_004ce825
    //         004ce823     XOR        EBX,EBX
    //                               LAB_004ce825                                                 XREF[1]:     004ce821(j)  
    //                              tact_dar.cpp:145 (20)
    //         004ce825     MOVSX      this,word ptr [ESP + local_18]
    //         004ce82a     CMP        this,dword ptr [EDX + 0x8]
    //         004ce82d     JL         LAB_004ce839
    //         004ce82f     MOV        this,word ptr [EDX + 0x8]
    //         004ce833     DEC        this
    //         004ce835     MOV        dword ptr [ESP + local_18],this
    //                               LAB_004ce839                                                 XREF[1]:     004ce82d(j)  
    //                              tact_dar.cpp:146 (16)
    //         004ce839     MOV        ESI,dword ptr [EDX + 0xc]
    //         004ce83c     MOVSX      this,AX
    //         004ce83f     CMP        this,ESI
    //         004ce841     JL         LAB_004ce849
    //         004ce843     MOV        AX,word ptr [EDX + 0xc]
    //         004ce847     DEC        AX
    //                               LAB_004ce849                                                 XREF[1]:     004ce841(j)  
    //                              tact_dar.cpp:149 (33)
    //         004ce849     CMP        BX,AX
    //         004ce84c     JG         LAB_004ce91a
    //         004ce852     MOVSX      this,BX
    //         004ce855     MOVSX      EAX,AX
    //         004ce858     SUB        EAX,this
    //         004ce85a     LEA        ESI,[this->_padding_*0x4 + 0x0]
    //         004ce861     INC        EAX
    //         004ce862     MOV        dword ptr [ESP + local_14],ESI
    //         004ce866     MOV        dword ptr [ESP + local_c],EAX
    //                               LAB_004ce86a                                                 XREF[1]:     004ce914(j)  
    //                              tact_dar.cpp:150 (36)
    //         004ce86a     MOV        EAX,dword ptr [ESP + x1]
    //         004ce86e     MOV        this,dword ptr [ESP + local_18]
    //         004ce872     CMP        AX,this
    //         004ce875     JG         LAB_004ce900
    //         004ce87b     MOVSX      EAX,AX
    //         004ce87e     MOVSX      this,this
    //         004ce881     LEA        EDI,[EAX + EAX*0x2]
    //         004ce884     SUB        this,EAX
    //         004ce886     SHL        EDI,0x3
    //         004ce889     INC        this
    //         004ce88a     MOV        dword ptr [ESP + local_10],this
    //                               LAB_004ce88e                                                 XREF[1]:     004ce8fe(j)  
    //                              tact_dar.cpp:151 (21)
    //         004ce88e     MOV        EAX,dword ptr [EDX + 0x8d8c]
    //         004ce894     MOV        ESI,dword ptr [ESP + local_14]
    //         004ce898     MOV        EAX,dword ptr [ESI + EAX*0x1]
    //         004ce89b     MOV        ESI,dword ptr [EAX + EDI*0x1 + 0x10]
    //         004ce89f     TEST       ESI,ESI
    //         004ce8a1     JZ         LAB_004ce8f6
    //                               LAB_004ce8a3                                                 XREF[1]:     004ce8ec(j)  
    //                              tact_dar.cpp:152 (15)
    //         004ce8a3     MOV        this,dword ptr [ESI]
    //         004ce8a5     MOV        EDX,dword ptr [EBP + 0x8]
    //         004ce8a8     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004ce8ab     MOV        this,dword ptr [EDX + 0xc]
    //         004ce8ae     CMP        EAX,this
    //         004ce8b0     JZ         LAB_004ce8e7
    //                              tact_dar.cpp:153 (14)
    //         004ce8b2     MOVSX      EAX,word ptr [EAX + 0x4a]
    //         004ce8b6     MOV        this,dword ptr [EBP + 0x40]
    //         004ce8b9     ADD        EAX,this
    //         004ce8bb     CMP        byte ptr [EAX],0x0
    //         004ce8be     JNZ        LAB_004ce8e7
    //                              tact_dar.cpp:156 (3)
    //         004ce8c0     MOV        byte ptr [EAX],0x1
    //                              tact_dar.cpp:157 (61)
    //         004ce8c3     MOV        EAX,dword ptr [ESI]
    //         004ce8c5     MOV        EDX,dword ptr [EAX + 0xc]
    //         004ce8c8     MOV        EBP,dword ptr [EAX + 0x40]
    //         004ce8cb     PUSH       EBP
    //         004ce8cc     MOV        EBP,dword ptr [EAX + 0x3c]
    //         004ce8cf     MOV        this,dword ptr [EDX + 0x24]
    //         004ce8d2     MOV        EAX,dword ptr [EAX + 0x38]
    //         004ce8d5     PUSH       EBP
    //         004ce8d6     PUSH       EAX
    //         004ce8d7     MOV        this,dword ptr [this->_padding_ + 0x288]
    //         004ce8dd     PUSH       EDX
    //         004ce8de     MOV        EBX,dword ptr [this->_padding_]
    //         004ce8e0     CALL       dword ptr [EBX + 0x18]
    //         004ce8e3     MOV        EBP,dword ptr [ESP + 0x24]
    //                               LAB_004ce8e7                                                 XREF[2]:     004ce8b0(j), 004ce8be(j)  
    //         004ce8e7     MOV        ESI,dword ptr [ESI + 0x4]
    //         004ce8ea     TEST       ESI,ESI
    //         004ce8ec     JNZ        LAB_004ce8a3
    //         004ce8ee     MOV        this,dword ptr [ESP + 0x1c]
    //         004ce8f2     MOV        EDX,dword ptr [ESP + 0x28]
    //                               LAB_004ce8f6                                                 XREF[1]:     004ce8a1(j)  
    //         004ce8f6     ADD        EDI,0x18
    //         004ce8f9     DEC        this
    //         004ce8fa     MOV        dword ptr [ESP + 0x1c],this
    //         004ce8fe     JNZ        LAB_004ce88e
    //                               LAB_004ce900                                                 XREF[1]:     004ce875(j)  
    //                              tact_dar.cpp:149 (26)
    //         004ce900     MOV        this,dword ptr [ESP + 0x18]
    //         004ce904     MOV        EAX,dword ptr [ESP + 0x20]
    //         004ce908     ADD        this,0x4
    //         004ce90b     DEC        EAX
    //         004ce90c     MOV        dword ptr [ESP + 0x18],this
    //         004ce910     MOV        dword ptr [ESP + 0x20],EAX
    //         004ce914     JNZ        LAB_004ce86a
    //                               LAB_004ce91a                                                 XREF[1]:     004ce84c(j)  
    //                              tact_dar.cpp:165 (8)
    //         004ce91a     POP        EDI
    //         004ce91b     POP        ESI
    //         004ce91c     POP        EBP
    //         004ce91d     POP        EBX
    //         004ce91e     ADD        ESP,0x1c
    //         004ce921     RET
    //         004ce922     ??         90h
    //         004ce923     NOP
    //         004ce924     NOP
    //         004ce925     NOP
    //         004ce926     NOP
    //         004ce927     NOP
    //         004ce928     NOP
    //         004ce929     NOP
    //         004ce92a     NOP
    //         004ce92b     NOP
    //         004ce92c     NOP
    //         004ce92d     NOP
    //         004ce92e     NOP
    //         004ce92f     NOP
    return;
}

TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(int param_1, RGE_Action_Object* param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

