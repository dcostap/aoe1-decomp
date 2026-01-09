#include "common.h"
#include "scenario.h"

RGE_Scenario_Header::RGE_Scenario_Header(RGE_Scenario* param_1) {
    /* TODO: Stub */
    //                              undefined __thiscall RGE_Scenario_Header(RGE_Scenario_Header * this,
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Scenario_H    ECX:4 (auto)   this
    //              RGE_Scenario *    Stack[0x4]:4   param_1                   XREF[2]:     0048ab2f(R), 0048ab68(R)  
    //                               ??0RGE_Scenario_Header@@QAE@PAVRGE_Scenario@@@Z              XREF[2]:     new_scenario_header:0041ce97(c), 
    //                               RGE_Scenario_Header::RGE_Scenario_Header                                  TRIBE_Scenario_Header:0052a9b3(c)  
    //                              scenario.cpp:29 (6)
    //         0048ab10     PUSH       EBX
    //         0048ab11     PUSH       EBP
    //         0048ab12     PUSH       ESI
    //         0048ab13     PUSH       EDI
    //         0048ab14     MOV        EBP,this
    //                              scenario.cpp:32 (2)
    //         0048ab16     XOR        EDI,EDI
    //                              scenario.cpp:36 (23)
    //         0048ab18     PUSH       EDI
    //         0048ab19     MOV        dword ptr [EBP],RGE_Scenario_Header::`vftable'   = 0048aca0
    //         0048ab20     MOV        dword ptr [EBP + 0x4],EDI
    //         0048ab23     MOV        dword ptr [EBP + 0x8],0x2
    //         0048ab2a     CALL       time                                             undefined time()
    //                              scenario.cpp:38 (21)
    //         0048ab2f     MOV        ESI,dword ptr [ESP + param_1]
    //         0048ab33     ADD        ESP,0x4
    //         0048ab36     MOV        this,ESI
    //         0048ab38     MOV        dword ptr [EBP + 0xc],EAX
    //         0048ab3b     CALL       RGE_Scenario::Get_description                    char * Get_description(RGE_Scenario * this)
    //         0048ab40     TEST       EAX,EAX
    //         0048ab42     JZ         LAB_0048ab68
    //                              scenario.cpp:40 (22)
    //         0048ab44     MOV        this,ESI
    //         0048ab46     CALL       RGE_Scenario::Get_description                    char * Get_description(RGE_Scenario * this)
    //         0048ab4b     MOV        EDI,EAX
    //         0048ab4d     OR         this,0xffffffff
    //         0048ab50     XOR        EAX,EAX
    //         0048ab52     SCASB.RE   ES:EDI
    //         0048ab54     NOT        this
    //         0048ab56     DEC        this
    //         0048ab57     MOV        EBX,this
    //         0048ab59     INC        EBX
    //                              scenario.cpp:41 (12)
    //         0048ab5a     PUSH       EBX
    //         0048ab5b     CALL       malloc                                           undefined malloc()
    //         0048ab60     ADD        ESP,0x4
    //         0048ab63     MOV        dword ptr [EBP + 0x10],EAX
    //                              scenario.cpp:43 (2)
    //         0048ab66     JMP        LAB_0048ab6f
    //                               LAB_0048ab68                                                 XREF[1]:     0048ab42(j)  
    //                              scenario.cpp:44 (7)
    //         0048ab68     MOV        EBX,dword ptr [ESP + param_1]
    //         0048ab6c     MOV        dword ptr [EBP + 0x10],EDI
    //                               LAB_0048ab6f                                                 XREF[1]:     0048ab66(j)  
    //                              scenario.cpp:45 (7)
    //         0048ab6f     MOV        EAX,dword ptr [EBP + 0x10]
    //         0048ab72     TEST       EAX,EAX
    //         0048ab74     JZ         LAB_0048aba5
    //                              scenario.cpp:47 (39)
    //         0048ab76     MOV        this,ESI
    //         0048ab78     CALL       RGE_Scenario::Get_description                    char * Get_description(RGE_Scenario * this)
    //         0048ab7d     MOV        EDI,EAX
    //         0048ab7f     OR         this,0xffffffff
    //         0048ab82     XOR        EAX,EAX
    //         0048ab84     SCASB.RE   ES:EDI
    //         0048ab86     NOT        this
    //         0048ab88     SUB        EDI,this
    //         0048ab8a     MOV        EAX,this
    //         0048ab8c     MOV        ESI,EDI
    //         0048ab8e     MOV        EDI,dword ptr [EBP + 0x10]
    //         0048ab91     SHR        this,0x2
    //         0048ab94     MOVSD.REP  ES:EDI,ESI
    //         0048ab96     MOV        this,EAX
    //         0048ab98     AND        this,0x3
    //         0048ab9b     MOVSB.REP  ES:EDI,ESI
    //                              scenario.cpp:48 (8)
    //         0048ab9d     MOV        this,dword ptr [EBP + 0x10]
    //         0048aba0     MOV        byte ptr [EBX + this->_padding_*0x1 + -0x1],0x0
    //                               LAB_0048aba5                                                 XREF[1]:     0048ab74(j)  
    //                              scenario.cpp:50 (9)
    //         0048aba5     POP        EDI
    //         0048aba6     MOV        EAX,EBP
    //         0048aba8     POP        ESI
    //         0048aba9     POP        EBP
    //         0048abaa     POP        EBX
    //         0048abab     RET        0x4
    //         0048abae     ??         90h
    //         0048abaf     NOP
}

RGE_Scenario_Header::RGE_Scenario_Header(int param_1) {
    /* TODO: Stub */
    //                              undefined __thiscall RGE_Scenario_Header(RGE_Scenario_Header * this,
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Scenario_H    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[4]:     0048abb6(R), 0048ac03(*), 0048ac10(R), 0048ac3c(R)  
    //              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     0048abd0(*)  
    //              long              Stack[-0x8]:4  header_size
    //                               ??0RGE_Scenario_Header@@QAE@H@Z                              XREF[2]:     new_scenario_header:0041ce37(c), 
    //                               RGE_Scenario_Header::RGE_Scenario_Header                                  TRIBE_Scenario_Header:0052aa14(c)  
    //                              scenario.cpp:58 (6)
    //         0048abb0     PUSH       this
    //         0048abb1     PUSH       EBX
    //         0048abb2     PUSH       EBP
    //         0048abb3     PUSH       ESI
    //         0048abb4     MOV        ESI,this
    //                              scenario.cpp:67 (46)
    //         0048abb6     MOV        EBX,dword ptr [ESP + param_1]
    //         0048abba     PUSH       EDI
    //         0048abbb     LEA        EDI,[ESI + 0x8]
    //         0048abbe     LEA        EBP,[ESI + 0xc]
    //         0048abc1     XOR        EAX,EAX
    //         0048abc3     PUSH       0x4
    //         0048abc5     MOV        dword ptr [ESI + 0x4],EAX
    //         0048abc8     MOV        dword ptr [EDI],EAX
    //         0048abca     MOV        dword ptr [EBP],EAX
    //         0048abcd     MOV        dword ptr [ESI + 0x10],EAX
    //         0048abd0     LEA        EAX=>local_4,[ESP + 0x14]
    //         0048abd4     MOV        dword ptr [ESI],RGE_Scenario_Header::`vftable'   = 0048aca0
    //         0048abda     PUSH       EAX
    //         0048abdb     PUSH       EBX
    //         0048abdc     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void 
    //         0048abe1     ADD        ESP,0xc
    //                              scenario.cpp:69 (9)
    //         0048abe4     PUSH       0x4
    //         0048abe6     PUSH       EDI
    //         0048abe7     PUSH       EBX
    //         0048abe8     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void 
    //                              scenario.cpp:71 (10)
    //         0048abed     MOV        EAX,dword ptr [EDI]
    //         0048abef     ADD        ESP,0xc
    //         0048abf2     CMP        EAX,0x2
    //         0048abf5     JL         LAB_0048ac03
    //                              scenario.cpp:72 (12)
    //         0048abf7     PUSH       0x4
    //         0048abf9     PUSH       EBP
    //         0048abfa     PUSH       EBX
    //         0048abfb     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void 
    //         0048ac00     ADD        ESP,0xc
    //                               LAB_0048ac03                                                 XREF[1]:     0048abf5(j)  
    //                              scenario.cpp:74 (13)
    //         0048ac03     LEA        this=>param_1,[ESP + 0x18]
    //         0048ac07     PUSH       0x4
    //         0048ac09     PUSH       this
    //         0048ac0a     PUSH       EBX
    //         0048ac0b     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void 
    //                              scenario.cpp:75 (11)
    //         0048ac10     MOV        EAX,dword ptr [ESP + param_1]
    //         0048ac14     ADD        ESP,0xc
    //         0048ac17     TEST       EAX,EAX
    //         0048ac19     JLE        LAB_0048ac55
    //                              scenario.cpp:77 (12)
    //         0048ac1b     PUSH       EAX
    //         0048ac1c     CALL       malloc                                           undefined malloc()
    //         0048ac21     ADD        ESP,0x4
    //         0048ac24     MOV        dword ptr [ESI + 0x10],EAX
    //                              scenario.cpp:78 (4)
    //         0048ac27     TEST       EAX,EAX
    //         0048ac29     JNZ        LAB_0048ac3c
    //                              scenario.cpp:79 (7)
    //         0048ac2b     MOV        dword ptr [ESI + 0x4],0x1
    //                              scenario.cpp:85 (10)
    //         0048ac32     MOV        EAX,ESI
    //         0048ac34     POP        EDI
    //         0048ac35     POP        ESI
    //         0048ac36     POP        EBP
    //         0048ac37     POP        EBX
    //         0048ac38     POP        this
    //         0048ac39     RET        0x4
    //                               LAB_0048ac3c                                                 XREF[1]:     0048ac29(j)  
    //                              scenario.cpp:81 (15)
    //         0048ac3c     MOV        EDX,dword ptr [ESP + param_1]
    //         0048ac40     PUSH       EDX
    //         0048ac41     PUSH       EAX
    //         0048ac42     PUSH       EBX
    //         0048ac43     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void 
    //         0048ac48     ADD        ESP,0xc
    //                              scenario.cpp:85 (10)
    //         0048ac4b     MOV        EAX,ESI
    //         0048ac4d     POP        EDI
    //         0048ac4e     POP        ESI
    //         0048ac4f     POP        EBP
    //         0048ac50     POP        EBX
    //         0048ac51     POP        this
    //         0048ac52     RET        0x4
    //                               LAB_0048ac55                                                 XREF[1]:     0048ac19(j)  
    //                              scenario.cpp:84 (7)
    //         0048ac55     MOV        dword ptr [ESI + 0x10],0x0
    //                              scenario.cpp:85 (10)
    //         0048ac5c     MOV        EAX,ESI
    //         0048ac5e     POP        EDI
    //         0048ac5f     POP        ESI
    //         0048ac60     POP        EBP
    //         0048ac61     POP        EBX
    //         0048ac62     POP        this
    //         0048ac63     RET        0x4
    //         0048ac66     ??         90h
    //         0048ac67     NOP
    //         0048ac68     NOP
    //         0048ac69     NOP
    //         0048ac6a     NOP
    //         0048ac6b     NOP
    //         0048ac6c     NOP
    //         0048ac6d     NOP
    //         0048ac6e     NOP
    //         0048ac6f     NOP
}

RGE_Static_Object* RGE_Scenario::get_object_pointer(int param_1) {
    /* TODO: Stub */
    //                              RGE_Static_Object * __thiscall get_object_pointer(RGE_Scenario * thi
    //              RGE_Static_Obj    EAX:4          <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //                               ?get_object_pointer@RGE_Scenario@@MAEPAVRGE_Static_Object@@  XREF[1]:     00572128(*)  
    //                               RGE_Scenario::get_object_pointer
    //                              scenario.h:59 (5)
    //         0048b580     XOR        EAX,EAX
    //         0048b582     RET        0x4
    //         0048b585     ??         90h
    //         0048b586     NOP
    //         0048b587     NOP
    //         0048b588     NOP
    //         0048b589     NOP
    //         0048b58a     NOP
    //         0048b58b     NOP
    //         0048b58c     NOP
    //         0048b58d     NOP
    //         0048b58e     NOP
    //         0048b58f     NOP
    return 0;
}

RGE_Scenario_Header::~RGE_Scenario_Header() {
    /* TODO: Stub */
    //                              void __thiscall ~RGE_Scenario_Header(RGE_Scenario_Header * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Scenario_H    ECX:4 (auto)   this
    //                               ??1RGE_Scenario_Header@@QAE@XZ                               XREF[4]:     write_scenario_header:0041cdc5(c), 
    //                               RGE_Scenario_Header::~RGE_Scenario_Header                                 get_scenario_checksum:00422d3d(c), 
    //                                                                                                         ~RGE_Scenario_File_Info:0048cffd(c
    //                                                                                                         reload_scenarios:0048d476(c)  
    //                              scenario.cpp:89 (3)
    //         0048ac70     PUSH       ESI
    //         0048ac71     MOV        ESI,this
    //                              scenario.cpp:90 (13)
    //         0048ac73     MOV        EAX,dword ptr [ESI + 0x10]
    //         0048ac76     MOV        dword ptr [ESI],RGE_Scenario_Header::`vftable'   = 0048aca0
    //         0048ac7c     TEST       EAX,EAX
    //         0048ac7e     JZ         LAB_0048ac90
    //                              scenario.cpp:92 (9)
    //         0048ac80     PUSH       EAX
    //         0048ac81     CALL       free                                             undefined free()
    //         0048ac86     ADD        ESP,0x4
    //                              scenario.cpp:93 (7)
    //         0048ac89     MOV        dword ptr [ESI + 0x10],0x0
    //                               LAB_0048ac90                                                 XREF[1]:     0048ac7e(j)  
    //                              scenario.cpp:95 (2)
    //         0048ac90     POP        ESI
    //         0048ac91     RET
    //         0048ac92     ??         90h
    //         0048ac93     NOP
    //         0048ac94     NOP
    //         0048ac95     NOP
    //         0048ac96     NOP
    //         0048ac97     NOP
    //         0048ac98     NOP
    //         0048ac99     NOP
    //         0048ac9a     NOP
    //         0048ac9b     NOP
    //         0048ac9c     NOP
    //         0048ac9d     NOP
    //         0048ac9e     NOP
    //         0048ac9f     NOP
}

long RGE_Scenario_Header::get_size() {
    /* TODO: Stub */
    //                              long __thiscall get_size(RGE_Scenario_Header * this)
    //              long              EAX:4          <RETURN>
    //              RGE_Scenario_H    ECX:4 (auto)   this
    //                               ?get_size@RGE_Scenario_Header@@UAEJXZ                        XREF[2]:     get_size:0052aa70(c), 00572120(*)  
    //                               RGE_Scenario_Header::get_size
    //                              scenario.cpp:99 (1)
    //         0048aca0     PUSH       EDI
    //                              scenario.cpp:103 (7)
    //         0048aca1     MOV        EDI,dword ptr [ECX + this->description]
    //         0048aca4     TEST       EDI,EDI
    //         0048aca6     JZ         LAB_0048acb6
    //                              scenario.cpp:104 (9)
    //         0048aca8     OR         this,0xffffffff
    //         0048acab     XOR        EAX,EAX
    //         0048acad     SCASB.RE   ES:EDI
    //         0048acaf     NOT        this
    //                              scenario.cpp:113 (3)
    //         0048acb1     LEA        EAX,[ECX + this->checksum]
    //                              scenario.cpp:114 (2)
    //         0048acb4     POP        EDI
    //         0048acb5     RET
    //                               LAB_0048acb6                                                 XREF[1]:     0048aca6(j)  
    //                              scenario.cpp:106 (2)
    //         0048acb6     XOR        this,this
    //                              scenario.cpp:114 (5)
    //         0048acb8     POP        EDI
    //         0048acb9     LEA        EAX,[ECX + this->checksum]
    //         0048acbc     RET
    //         0048acbd     ??         90h
    //         0048acbe     NOP
    //         0048acbf     NOP
    return 0;
}

void RGE_Scenario_Header::save(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall save(RGE_Scenario_Header * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Scenario_H    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //              long              Stack[-0x8]:4  header_size
    //              long              Stack[-0xc]:4  desc_size
    //                               ?save@RGE_Scenario_Header@@UAEXH@Z                           XREF[1]:     save:0052aa89(c)  
    //                               RGE_Scenario_Header::save
    //                              scenario.cpp:118 (8)
    //         0048acc0     SUB        ESP,0x8
    //         0048acc3     PUSH       EBX
    //         0048acc4     PUSH       ESI
    //         0048acc5     MOV        ESI,this
    //         0048acc7     PUSH       EDI
    //                              scenario.cpp:122 (4)
    //         0048acc8     MOV        EAX,dword ptr [ESI]
    //         0048acca     CALL       dword ptr [EAX]
    //                              scenario.cpp:123 (24)
    //         0048accc     MOV        EBX,dword ptr [ESP + 0x18]
    //         0048acd0     LEA        this,[ESP + 0x10]
    //         0048acd4     PUSH       0x4
    //         0048acd6     PUSH       this=>DAT_fffffff8
    //         0048acd7     PUSH       EBX=>DAT_fffffff4
    //         0048acd8     MOV        dword ptr [ESP + 0x1c],EAX
    //         0048acdc     CALL       rge_write_uncompressed                           void rge_write_uncompressed(int param_1, void
    //         0048ace1     ADD        ESP,0xc
    //                              scenario.cpp:125 (12)
    //         0048ace4     LEA        EDI,[ESI + 0x8]
    //         0048ace7     PUSH       0x4
    //         0048ace9     PUSH       EDI=>DAT_fffffff8
    //         0048acea     PUSH       EBX=>DAT_fffffff4
    //         0048aceb     CALL       rge_write_uncompressed                           void rge_write_uncompressed(int param_1, void
    //                              scenario.cpp:127 (10)
    //         0048acf0     MOV        EAX,dword ptr [EDI]
    //         0048acf2     ADD        ESP,0xc
    //         0048acf5     CMP        EAX,0x2
    //         0048acf8     JL         LAB_0048ad09
    //                              scenario.cpp:128 (15)
    //         0048acfa     LEA        EDX,[ESI + 0xc]
    //         0048acfd     PUSH       0x4
    //         0048acff     PUSH       EDX=>DAT_fffffff8
    //         0048ad00     PUSH       EBX=>DAT_fffffff4
    //         0048ad01     CALL       rge_write_uncompressed                           void rge_write_uncompressed(int param_1, void
    //         0048ad06     ADD        ESP,0xc
    //                               LAB_0048ad09                                                 XREF[1]:     0048acf8(j)  
    //                              scenario.cpp:130 (7)
    //         0048ad09     MOV        EDI,dword ptr [ESI + 0x10]
    //         0048ad0c     TEST       EDI,EDI
    //         0048ad0e     JZ         LAB_0048ad1f
    //                              scenario.cpp:131 (13)
    //         0048ad10     OR         this,0xffffffff
    //         0048ad13     XOR        EAX,EAX
    //         0048ad15     SCASB.RE   ES:EDI
    //         0048ad17     NOT        this
    //         0048ad19     MOV        dword ptr [ESP + 0xc],this
    //                              scenario.cpp:132 (2)
    //         0048ad1d     JMP        LAB_0048ad27
    //                               LAB_0048ad1f                                                 XREF[1]:     0048ad0e(j)  
    //                              scenario.cpp:133 (8)
    //         0048ad1f     MOV        dword ptr [ESP + 0xc],0x0
    //                               LAB_0048ad27                                                 XREF[1]:     0048ad1d(j)  
    //                              scenario.cpp:134 (13)
    //         0048ad27     LEA        EAX,[ESP + 0xc]
    //         0048ad2b     PUSH       0x4
    //         0048ad2d     PUSH       EAX=>DAT_fffffff8
    //         0048ad2e     PUSH       EBX=>DAT_fffffff4
    //         0048ad2f     CALL       rge_write_uncompressed                           void rge_write_uncompressed(int param_1, void
    //                              scenario.cpp:136 (10)
    //         0048ad34     MOV        ESI,dword ptr [ESI + 0x10]
    //         0048ad37     ADD        ESP,0xc
    //         0048ad3a     TEST       ESI,ESI
    //         0048ad3c     JZ         LAB_0048ad4d
    //                              scenario.cpp:137 (15)
    //         0048ad3e     MOV        this,dword ptr [ESP + 0xc]
    //         0048ad42     PUSH       this
    //         0048ad43     PUSH       ESI=>DAT_fffffff8
    //         0048ad44     PUSH       EBX=>DAT_fffffff4
    //         0048ad45     CALL       rge_write_uncompressed                           void rge_write_uncompressed(int param_1, void
    //         0048ad4a     ADD        ESP,0xc
    //                               LAB_0048ad4d                                                 XREF[1]:     0048ad3c(j)  
    //                              scenario.cpp:138 (9)
    //         0048ad4d     POP        EDI
    //         0048ad4e     POP        ESI
    //         0048ad4f     POP        EBX
    //         0048ad50     ADD        ESP,0x8
    //         0048ad53     RET        0x4
    //         0048ad56     ??         90h
    //         0048ad57     NOP
    //         0048ad58     NOP
    //         0048ad59     NOP
    //         0048ad5a     NOP
    //         0048ad5b     NOP
    //         0048ad5c     NOP
    //         0048ad5d     NOP
    //         0048ad5e     NOP
    //         0048ad5f     NOP
    return;
}

void RGE_Scenario::rehook() {
    /* TODO: Stub */
    //                              void __thiscall rehook(RGE_Scenario * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //                               ?rehook@RGE_Scenario@@UAEXXZ                                 XREF[1]:     00572130(*)  
    //                               RGE_Scenario::rehook
    //                              scenario.h:148 (1)
    //         0048b590     RET
    //         0048b591     ??         90h
    //         0048b592     NOP
    //         0048b593     NOP
    //         0048b594     NOP
    //         0048b595     NOP
    //         0048b596     NOP
    //         0048b597     NOP
    //         0048b598     NOP
    //         0048b599     NOP
    //         0048b59a     NOP
    //         0048b59b     NOP
    //         0048b59c     NOP
    //         0048b59d     NOP
    //         0048b59e     NOP
    //         0048b59f     NOP
    return;
}

RGE_Scenario::RGE_Scenario(RGE_Game_World* param_1) {
    /* TODO: Stub */
    //                              undefined __thiscall RGE_Scenario(RGE_Scenario * this, RGE_Game_Worl
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //              RGE_Game_World    Stack[0x4]:4   param_1                   XREF[2]:     0048ad6e(R), 0048ad90(W)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0048ad98(W), 0048adaf(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0048add5(R)  
    //                               ??0RGE_Scenario@@QAE@PAVRGE_Game_World@@@Z                   XREF[2]:     T_Scenario:0052aae3(c), 
    //                               RGE_Scenario::RGE_Scenario                                                scenario_init:00541bfd(c)  
    //                              scenario.cpp:152 (14)
    //         0048ad60     MOV        EAX,FS:[0x0]
    //         0048ad66     PUSH       -0x1
    //         0048ad68     PUSH       FUN_0055e7bb
    //         0048ad6d     PUSH       EAX
    //                              scenario.cpp:153 (15)
    //         0048ad6e     MOV        EAX,dword ptr [ESP + param_1]
    //         0048ad72     MOV        dword ptr FS:[0x0],ESP
    //         0048ad79     PUSH       ESI
    //         0048ad7a     MOV        ESI,this
    //         0048ad7c     PUSH       EDI
    //                              scenario.cpp:154 (48)
    //         0048ad7d     PUSH       0x14
    //         0048ad7f     MOV        dword ptr [ESI],RGE_Scenario::`vftable'          = 0048b580
    //         0048ad85     MOV        dword ptr [ESI + 0x8],EAX
    //         0048ad88     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0048ad8d     ADD        ESP,0x4
    //         0048ad90     MOV        dword ptr [ESP + param_1],EAX
    //         0048ad94     XOR        EDI,EDI
    //         0048ad96     CMP        EAX,EDI
    //         0048ad98     MOV        dword ptr [ESP + local_4],EDI
    //         0048ad9c     JZ         LAB_0048adab
    //         0048ad9e     MOV        this,dword ptr [ESI + 0x8]
    //         0048ada1     PUSH       this
    //         0048ada2     MOV        this,EAX
    //         0048ada4     CALL       RGE_Timeline::RGE_Timeline                       undefined RGE_Timeline(RGE_Timeline * this, R
    //         0048ada9     JMP        LAB_0048adad
    //                               LAB_0048adab                                                 XREF[1]:     0048ad9c(j)  
    //         0048adab     XOR        EAX,EAX
    //                               LAB_0048adad                                                 XREF[1]:     0048ada9(j)  
    //                              scenario.cpp:156 (18)
    //         0048adad     MOV        this,ESI
    //         0048adaf     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0048adb7     MOV        dword ptr [ESI + 0x4],EAX
    //         0048adba     CALL       RGE_Scenario::InitializeTextValues               void InitializeTextValues(RGE_Scenario * this)
    //                              scenario.cpp:158 (9)
    //         0048adbf     MOV        dword ptr [ESI + 0x198c],EDI
    //         0048adc5     LEA        EDI,[ESI + 0xd]
    //                              scenario.cpp:160 (13)
    //         0048adc8     MOV        this,0x400
    //         0048adcd     XOR        EAX,EAX
    //         0048adcf     MOV        byte ptr [ESI + 0xc],0x1
    //         0048add3     STOSD.REP  ES:EDI
    //                              scenario.cpp:161 (21)
    //         0048add5     MOV        this,dword ptr [ESP + local_c]
    //         0048add9     MOV        EAX,ESI
    //         0048addb     POP        EDI
    //         0048addc     MOV        dword ptr FS:[0x0],this
    //         0048ade3     POP        ESI
    //         0048ade4     ADD        ESP,0xc
    //         0048ade7     RET        0x4
    //         0048adea     ??         90h
    //         0048adeb     NOP
    //         0048adec     NOP
    //         0048aded     NOP
    //         0048adee     NOP
    //         0048adef     NOP
}

RGE_Scenario::RGE_Scenario(int param_1, RGE_Game_World* param_2) {
    /* TODO: Stub */
    //                              undefined __thiscall RGE_Scenario(RGE_Scenario * this, int param_1, 
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0048ae43(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     0048ae1e(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[5]:     0048af25(W), 0048af4c(W), 0048b31b(W), 0048b332(W), 
    //                                                                                     0048b343(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0048b562(R)  
    //              char[224]         Stack[-0xf0]   text                      XREF[2,3]:   0048b543(W), 0048b552(*), 0048b186(*), 0048b1b2(*), 
    //                                                                                     0048b1de(*)  
    //              int               Stack[-0xf4]:4 val                       XREF[5]:     0048af1d(W), 0048b315(W), 0048b44c(W), 0048b525(R), 
    //                                                                                     0048b52d(W)  
    //              undefined2        Stack[-0xf6]:2 local_f6                  XREF[49]:    0048af41(*), 0048af58(R), 0048af76(R), 0048af84(*), 
    //                                                                                     0048af98(R), 0048afb0(R), 0048afc6(R), 0048aff8(*), 
    //                                                                                     0048b005(R), 0048b01d(R), 0048b033(R), 0048b04e(*), 
    //                                                                                     0048b05b(R), 0048b073(R), 0048b089(R), 0048b0a4(*), 
    //                                                                                     0048b0b1(R), 0048b0c9(R), 0048b0df(R), 0048b0fa(*)  
    //              short             Stack[-0xfa]:2 length
    //                               ??0RGE_Scenario@@QAE@HPAVRGE_Game_World@@@Z                  XREF[3]:     new_scenario_info:0041cefc(c), 
    //                               RGE_Scenario::RGE_Scenario                                                T_Scenario:0052abba(c), 
    //                                                                                                         scenario_init:00541ba2(c)  
    //                              scenario.cpp:167 (14)
    //         0048ae10     MOV        EAX,FS:[0x0]
    //         0048ae16     PUSH       -0x1
    //         0048ae18     PUSH       FUN_0055e7ec
    //         0048ae1d     PUSH       EAX
    //                              scenario.cpp:171 (32)
    //         0048ae1e     MOV        EAX,dword ptr [ESP + param_2]
    //         0048ae22     MOV        dword ptr FS:[0x0],ESP
    //         0048ae29     SUB        ESP,0xec
    //         0048ae2f     PUSH       EBX
    //         0048ae30     PUSH       EBP
    //         0048ae31     MOV        EBX,this
    //         0048ae33     PUSH       ESI
    //         0048ae34     PUSH       EDI
    //         0048ae35     MOV        dword ptr [EBX],RGE_Scenario::`vftable'          = 0048b580
    //         0048ae3b     MOV        dword ptr [EBX + 0x8],EAX
    //                              scenario.cpp:173 (5)
    //         0048ae3e     CALL       RGE_Scenario::InitializeTextValues               void InitializeTextValues(RGE_Scenario * this)
    //                              scenario.cpp:175 (22)
    //         0048ae43     MOV        ESI,dword ptr [ESP + param_1]
    //         0048ae4a     LEA        EDI,[EBX + 0x1888]
    //         0048ae50     PUSH       0x4
    //         0048ae52     PUSH       EDI
    //         0048ae53     PUSH       ESI
    //         0048ae54     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              scenario.cpp:177 (18)
    //         0048ae59     FLD        float ptr [EDI]
    //         0048ae5b     FCOMP      float ptr [DAT_00572138]                         = D7h
    //         0048ae61     ADD        ESP,0xc
    //         0048ae64     FNSTSW     AX
    //         0048ae66     TEST       AH,0x41
    //         0048ae69     JNZ        LAB_0048ae8b
    //                              scenario.cpp:369 (32)
    //         0048ae6b     LEA        EDI,[EBX + 0xd]
    //         0048ae6e     MOV        EBP,0x10
    //                               LAB_0048ae73                                                 XREF[1]:     0048ae89(j)  
    //         0048ae73     PUSH       0x100
    //         0048ae78     PUSH       EDI
    //         0048ae79     PUSH       ESI
    //         0048ae7a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0048ae7f     ADD        ESP,0xc
    //         0048ae82     ADD        EDI,0x100
    //         0048ae88     DEC        EBP
    //         0048ae89     JNZ        LAB_0048ae73
    //                               LAB_0048ae8b                                                 XREF[1]:     0048ae69(j)  
    //                              scenario.cpp:181 (19)
    //         0048ae8b     FLD        float ptr [EBX + 0x1888]
    //         0048ae91     FCOMP      double ptr [DAT_00572140]                        = 14h
    //         0048ae97     FNSTSW     AX
    //         0048ae99     TEST       AH,0x41
    //         0048ae9c     JNZ        LAB_0048aeeb
    //                              scenario.cpp:369 (77)
    //         0048ae9e     LEA        EDI,[EBX + 0x18cc]
    //         0048aea4     MOV        EBP,0x10
    //                               LAB_0048aea9                                                 XREF[1]:     0048aee9(j)  
    //         0048aea9     LEA        this,[EDI + 0x80]
    //         0048aeaf     PUSH       0x4
    //         0048aeb1     PUSH       this
    //         0048aeb2     PUSH       ESI
    //         0048aeb3     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0048aeb8     ADD        ESP,0xc
    //         0048aebb     PUSH       0x4
    //         0048aebd     PUSH       EDI
    //         0048aebe     PUSH       ESI
    //         0048aebf     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0048aec4     ADD        ESP,0xc
    //         0048aec7     LEA        EDX,[EDI + 0x40]
    //         0048aeca     PUSH       0x4
    //         0048aecc     PUSH       EDX
    //         0048aecd     PUSH       ESI
    //         0048aece     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0048aed3     ADD        ESP,0xc
    //         0048aed6     LEA        EAX,[EDI + -0x40]
    //         0048aed9     PUSH       0x4
    //         0048aedb     PUSH       EAX
    //         0048aedc     PUSH       ESI
    //         0048aedd     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0048aee2     ADD        ESP,0xc
    //         0048aee5     ADD        EDI,0x4
    //         0048aee8     DEC        EBP
    //         0048aee9     JNZ        LAB_0048aea9
    //                               LAB_0048aeeb                                                 XREF[1]:     0048ae9c(j)  
    //                              scenario.cpp:190 (19)
    //         0048aeeb     FLD        float ptr [EBX + 0x1888]
    //         0048aef1     FCOMP      double ptr [DAT_00572148]                        = 1Fh
    //         0048aef7     FNSTSW     AX
    //         0048aef9     TEST       AH,0x1
    //         0048aefc     JNZ        LAB_0048af0f
    //                              scenario.cpp:191 (15)
    //         0048aefe     LEA        this,[EBX + 0xc]
    //         0048af01     PUSH       0x1
    //         0048af03     PUSH       this
    //         0048af04     PUSH       ESI
    //         0048af05     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0048af0a     ADD        ESP,0xc
    //                              scenario.cpp:192 (2)
    //         0048af0d     JMP        LAB_0048af13
    //                               LAB_0048af0f                                                 XREF[1]:     0048aefc(j)  
    //                              scenario.cpp:193 (4)
    //         0048af0f     MOV        byte ptr [EBX + 0xc],0x1
    //                               LAB_0048af13                                                 XREF[1]:     0048af0d(j)  
    //                              scenario.cpp:195 (46)
    //         0048af13     PUSH       0x14
    //         0048af15     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0048af1a     ADD        ESP,0x4
    //         0048af1d     MOV        dword ptr [ESP + val],EAX
    //         0048af21     XOR        EDI,EDI
    //         0048af23     CMP        EAX,EDI
    //         0048af25     MOV        dword ptr [ESP + local_4],EDI
    //         0048af2c     JZ         LAB_0048af3c
    //         0048af2e     MOV        EDX,dword ptr [EBX + 0x8]
    //         0048af31     MOV        this,EAX
    //         0048af33     PUSH       EDX
    //         0048af34     PUSH       ESI
    //         0048af35     CALL       RGE_Timeline::RGE_Timeline                       undefined RGE_Timeline(RGE_Timeline * this, i
    //         0048af3a     JMP        LAB_0048af3e
    //                               LAB_0048af3c                                                 XREF[1]:     0048af2c(j)  
    //         0048af3c     XOR        EAX,EAX
    //                               LAB_0048af3e                                                 XREF[1]:     0048af3a(j)  
    //         0048af3e     MOV        dword ptr [EBX + 0x4],EAX
    //                              scenario.cpp:197 (23)
    //         0048af41     LEA        EAX=>local_f6,[ESP + 0x12]
    //         0048af45     PUSH       0x2
    //         0048af47     OR         EBP,0xffffffff
    //         0048af4a     PUSH       EAX
    //         0048af4b     PUSH       ESI
    //         0048af4c     MOV        dword ptr [ESP + local_4],EBP
    //         0048af53     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              scenario.cpp:198 (13)
    //         0048af58     MOV        AX,word ptr [ESP + local_f6]
    //         0048af5d     ADD        ESP,0xc
    //         0048af60     CMP        AX,DI
    //         0048af63     JLE        LAB_0048af7e
    //                              scenario.cpp:199 (25)
    //         0048af65     MOV        EDX,dword ptr [EBX + 0x1010]
    //         0048af6b     MOVSX      this,AX
    //         0048af6e     PUSH       this
    //         0048af6f     PUSH       EDX
    //         0048af70     PUSH       ESI
    //         0048af71     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0048af76     MOV        AX,word ptr [ESP + local_f6]
    //         0048af7b     ADD        ESP,0xc
    //                               LAB_0048af7e                                                 XREF[1]:     0048af63(j)  
    //                              scenario.cpp:200 (6)
    //         0048af7e     MOV        this,dword ptr [EBX + 0x1010]
    //                              scenario.cpp:202 (20)
    //         0048af84     LEA        EDX=>local_f6,[ESP + 0x12]
    //         0048af88     MOVSX      EAX,AX
    //         0048af8b     PUSH       0x2
    //         0048af8d     PUSH       EDX
    //         0048af8e     PUSH       ESI
    //         0048af8f     MOV        byte ptr [this->_padding_ + EAX*0x1],0x0
    //         0048af93     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              scenario.cpp:203 (13)
    //         0048af98     MOV        AX,word ptr [ESP + local_f6]
    //         0048af9d     ADD        ESP,0xc
    //         0048afa0     CMP        AX,DI
    //         0048afa3     JLE        LAB_0048afdb
    //                              scenario.cpp:205 (11)
    //         0048afa5     MOVSX      EAX,AX
    //         0048afa8     PUSH       0x1
    //         0048afaa     PUSH       EAX
    //         0048afab     CALL       calloc                                           undefined calloc()
    //                              scenario.cpp:206 (22)
    //         0048afb0     MOVSX      this,word ptr [ESP + local_f6]
    //         0048afb5     ADD        ESP,0x8
    //         0048afb8     MOV        dword ptr [EBX + 0x1014],EAX
    //         0048afbe     PUSH       this
    //         0048afbf     PUSH       EAX
    //         0048afc0     PUSH       ESI
    //         0048afc1     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              scenario.cpp:207 (19)
    //         0048afc6     MOVSX      EDX,word ptr [ESP + local_f6]
    //         0048afcb     MOV        EAX,dword ptr [EBX + 0x1014]
    //         0048afd1     ADD        ESP,0xc
    //         0048afd4     MOV        byte ptr [EDX + EAX*0x1 + -0x1],0x0
    //                              scenario.cpp:209 (2)
    //         0048afd9     JMP        LAB_0048afe1
    //                               LAB_0048afdb                                                 XREF[1]:     0048afa3(j)  
    //                              scenario.cpp:210 (6)
    //         0048afdb     MOV        dword ptr [EBX + 0x1014],EDI
    //                               LAB_0048afe1                                                 XREF[1]:     0048afd9(j)  
    //                              scenario.cpp:212 (23)
    //         0048afe1     FLD        float ptr [EBX + 0x1888]
    //         0048afe7     FCOMP      double ptr [DAT_00572150]                        = C3h
    //         0048afed     FNSTSW     AX
    //         0048afef     TEST       AH,0x1
    //         0048aff2     JNZ        LAB_0048b13a
    //                              scenario.cpp:214 (13)
    //         0048aff8     LEA        this=>local_f6,[ESP + 0x12]
    //         0048affc     PUSH       0x2
    //         0048affe     PUSH       this
    //         0048afff     PUSH       ESI
    //         0048b000     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              scenario.cpp:215 (13)
    //         0048b005     MOV        AX,word ptr [ESP + local_f6]
    //         0048b00a     ADD        ESP,0xc
    //         0048b00d     CMP        AX,DI
    //         0048b010     JLE        LAB_0048b048
    //                              scenario.cpp:217 (11)
    //         0048b012     MOVSX      EDX,AX
    //         0048b015     PUSH       0x1
    //         0048b017     PUSH       EDX
    //         0048b018     CALL       calloc                                           undefined calloc()
    //                              scenario.cpp:218 (22)
    //         0048b01d     MOVSX      this,word ptr [ESP + local_f6]
    //         0048b022     ADD        ESP,0x8
    //         0048b025     MOV        dword ptr [EBX + 0x1018],EAX
    //         0048b02b     PUSH       this
    //         0048b02c     PUSH       EAX
    //         0048b02d     PUSH       ESI
    //         0048b02e     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              scenario.cpp:219 (19)
    //         0048b033     MOVSX      EDX,word ptr [ESP + local_f6]
    //         0048b038     MOV        EAX,dword ptr [EBX + 0x1018]
    //         0048b03e     ADD        ESP,0xc
    //         0048b041     MOV        byte ptr [EDX + EAX*0x1 + -0x1],0x0
    //                              scenario.cpp:221 (2)
    //         0048b046     JMP        LAB_0048b04e
    //                               LAB_0048b048                                                 XREF[1]:     0048b010(j)  
    //                              scenario.cpp:222 (6)
    //         0048b048     MOV        dword ptr [EBX + 0x1018],EDI
    //                               LAB_0048b04e                                                 XREF[1]:     0048b046(j)  
    //                              scenario.cpp:224 (13)
    //         0048b04e     LEA        this=>local_f6,[ESP + 0x12]
    //         0048b052     PUSH       0x2
    //         0048b054     PUSH       this
    //         0048b055     PUSH       ESI
    //         0048b056     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              scenario.cpp:225 (13)
    //         0048b05b     MOV        AX,word ptr [ESP + local_f6]
    //         0048b060     ADD        ESP,0xc
    //         0048b063     CMP        AX,DI
    //         0048b066     JLE        LAB_0048b09e
    //                              scenario.cpp:227 (11)
    //         0048b068     MOVSX      EDX,AX
    //         0048b06b     PUSH       0x1
    //         0048b06d     PUSH       EDX
    //         0048b06e     CALL       calloc                                           undefined calloc()
    //                              scenario.cpp:228 (22)
    //         0048b073     MOVSX      this,word ptr [ESP + local_f6]
    //         0048b078     ADD        ESP,0x8
    //         0048b07b     MOV        dword ptr [EBX + 0x101c],EAX
    //         0048b081     PUSH       this
    //         0048b082     PUSH       EAX
    //         0048b083     PUSH       ESI
    //         0048b084     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              scenario.cpp:229 (19)
    //         0048b089     MOVSX      EDX,word ptr [ESP + local_f6]
    //         0048b08e     MOV        EAX,dword ptr [EBX + 0x101c]
    //         0048b094     ADD        ESP,0xc
    //         0048b097     MOV        byte ptr [EDX + EAX*0x1 + -0x1],0x0
    //                              scenario.cpp:231 (2)
    //         0048b09c     JMP        LAB_0048b0a4
    //                               LAB_0048b09e                                                 XREF[1]:     0048b066(j)  
    //                              scenario.cpp:232 (6)
    //         0048b09e     MOV        dword ptr [EBX + 0x101c],EDI
    //                               LAB_0048b0a4                                                 XREF[1]:     0048b09c(j)  
    //                              scenario.cpp:234 (13)
    //         0048b0a4     LEA        this=>local_f6,[ESP + 0x12]
    //         0048b0a8     PUSH       0x2
    //         0048b0aa     PUSH       this
    //         0048b0ab     PUSH       ESI
    //         0048b0ac     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              scenario.cpp:235 (13)
    //         0048b0b1     MOV        AX,word ptr [ESP + local_f6]
    //         0048b0b6     ADD        ESP,0xc
    //         0048b0b9     CMP        AX,DI
    //         0048b0bc     JLE        LAB_0048b0f4
    //                              scenario.cpp:237 (11)
    //         0048b0be     MOVSX      EDX,AX
    //         0048b0c1     PUSH       0x1
    //         0048b0c3     PUSH       EDX
    //         0048b0c4     CALL       calloc                                           undefined calloc()
    //                              scenario.cpp:238 (22)
    //         0048b0c9     MOVSX      this,word ptr [ESP + local_f6]
    //         0048b0ce     ADD        ESP,0x8
    //         0048b0d1     MOV        dword ptr [EBX + 0x1020],EAX
    //         0048b0d7     PUSH       this
    //         0048b0d8     PUSH       EAX
    //         0048b0d9     PUSH       ESI
    //         0048b0da     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              scenario.cpp:239 (19)
    //         0048b0df     MOVSX      EDX,word ptr [ESP + local_f6]
    //         0048b0e4     MOV        EAX,dword ptr [EBX + 0x1020]
    //         0048b0ea     ADD        ESP,0xc
    //         0048b0ed     MOV        byte ptr [EDX + EAX*0x1 + -0x1],0x0
    //                              scenario.cpp:241 (2)
    //         0048b0f2     JMP        LAB_0048b0fa
    //                               LAB_0048b0f4                                                 XREF[1]:     0048b0bc(j)  
    //                              scenario.cpp:242 (6)
    //         0048b0f4     MOV        dword ptr [EBX + 0x1020],EDI
    //                               LAB_0048b0fa                                                 XREF[1]:     0048b0f2(j)  
    //                              scenario.cpp:245 (13)
    //         0048b0fa     LEA        this=>local_f6,[ESP + 0x12]
    //         0048b0fe     PUSH       0x2
    //         0048b100     PUSH       this
    //         0048b101     PUSH       ESI
    //         0048b102     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              scenario.cpp:246 (13)
    //         0048b107     MOV        AX,word ptr [ESP + local_f6]
    //         0048b10c     ADD        ESP,0xc
    //         0048b10f     CMP        AX,DI
    //         0048b112     JLE        LAB_0048b14c
    //                              scenario.cpp:248 (11)
    //         0048b114     MOVSX      EDX,AX
    //         0048b117     PUSH       0x1
    //         0048b119     PUSH       EDX
    //         0048b11a     CALL       calloc                                           undefined calloc()
    //                              scenario.cpp:249 (25)
    //         0048b11f     MOVSX      this,word ptr [ESP + local_f6]
    //         0048b124     ADD        ESP,0x8
    //         0048b127     MOV        dword ptr [EBX + 0x1024],EAX
    //         0048b12d     PUSH       this
    //         0048b12e     PUSH       EAX
    //         0048b12f     PUSH       ESI
    //         0048b130     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0048b135     ADD        ESP,0xc
    //                              scenario.cpp:252 (2)
    //         0048b138     JMP        LAB_0048b152
    //                               LAB_0048b13a                                                 XREF[1]:     0048aff2(j)  
    //                              scenario.cpp:258 (6)
    //         0048b13a     MOV        dword ptr [EBX + 0x1018],EDI
    //                              scenario.cpp:259 (6)
    //         0048b140     MOV        dword ptr [EBX + 0x101c],EDI
    //                              scenario.cpp:260 (6)
    //         0048b146     MOV        dword ptr [EBX + 0x1020],EDI
    //                               LAB_0048b14c                                                 XREF[1]:     0048b112(j)  
    //                              scenario.cpp:261 (6)
    //         0048b14c     MOV        dword ptr [EBX + 0x1024],EDI
    //                               LAB_0048b152                                                 XREF[1]:     0048b138(j)  
    //                              scenario.cpp:264 (23)
    //         0048b152     FLD        float ptr [EBX + 0x1888]
    //         0048b158     FCOMP      float ptr [DAT_00572158]                         = 0Ah
    //         0048b15e     FNSTSW     AX
    //         0048b160     TEST       AH,0x1
    //         0048b163     JZ         LAB_0048b1ed
    //                              scenario.cpp:267 (13)
    //         0048b169     LEA        EDX=>local_f6,[ESP + 0x12]
    //         0048b16d     PUSH       0x2
    //         0048b16f     PUSH       EDX
    //         0048b170     PUSH       ESI
    //         0048b171     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              scenario.cpp:268 (13)
    //         0048b176     MOV        AX,word ptr [ESP + local_f6]
    //         0048b17b     ADD        ESP,0xc
    //         0048b17e     CMP        AX,DI
    //         0048b181     JLE        LAB_0048b195
    //                              scenario.cpp:269 (18)
    //         0048b183     MOVSX      EAX,AX
    //         0048b186     LEA        this=>text[4],[ESP + 0x1c]
    //         0048b18a     PUSH       EAX
    //         0048b18b     PUSH       this
    //         0048b18c     PUSH       ESI
    //         0048b18d     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0048b192     ADD        ESP,0xc
    //                               LAB_0048b195                                                 XREF[1]:     0048b181(j)  
    //                              scenario.cpp:271 (13)
    //         0048b195     LEA        EDX=>local_f6,[ESP + 0x12]
    //         0048b199     PUSH       0x2
    //         0048b19b     PUSH       EDX
    //         0048b19c     PUSH       ESI
    //         0048b19d     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              scenario.cpp:272 (13)
    //         0048b1a2     MOV        AX,word ptr [ESP + local_f6]
    //         0048b1a7     ADD        ESP,0xc
    //         0048b1aa     CMP        AX,DI
    //         0048b1ad     JLE        LAB_0048b1c1
    //                              scenario.cpp:273 (18)
    //         0048b1af     MOVSX      EAX,AX
    //         0048b1b2     LEA        this=>text[4],[ESP + 0x1c]
    //         0048b1b6     PUSH       EAX
    //         0048b1b7     PUSH       this
    //         0048b1b8     PUSH       ESI
    //         0048b1b9     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0048b1be     ADD        ESP,0xc
    //                               LAB_0048b1c1                                                 XREF[1]:     0048b1ad(j)  
    //                              scenario.cpp:275 (13)
    //         0048b1c1     LEA        EDX=>local_f6,[ESP + 0x12]
    //         0048b1c5     PUSH       0x2
    //         0048b1c7     PUSH       EDX
    //         0048b1c8     PUSH       ESI
    //         0048b1c9     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              scenario.cpp:276 (13)
    //         0048b1ce     MOV        AX,word ptr [ESP + local_f6]
    //         0048b1d3     ADD        ESP,0xc
    //         0048b1d6     CMP        AX,DI
    //         0048b1d9     JLE        LAB_0048b1ed
    //                              scenario.cpp:277 (18)
    //         0048b1db     MOVSX      EAX,AX
    //         0048b1de     LEA        this=>text[4],[ESP + 0x1c]
    //         0048b1e2     PUSH       EAX
    //         0048b1e3     PUSH       this
    //         0048b1e4     PUSH       ESI
    //         0048b1e5     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0048b1ea     ADD        ESP,0xc
    //                               LAB_0048b1ed                                                 XREF[2]:     0048b163(j), 0048b1d9(j)  
    //                              scenario.cpp:281 (13)
    //         0048b1ed     LEA        EDX=>local_f6,[ESP + 0x12]
    //         0048b1f1     PUSH       0x2
    //         0048b1f3     PUSH       EDX
    //         0048b1f4     PUSH       ESI
    //         0048b1f5     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              scenario.cpp:282 (13)
    //         0048b1fa     MOV        AX,word ptr [ESP + local_f6]
    //         0048b1ff     ADD        ESP,0xc
    //         0048b202     CMP        AX,DI
    //         0048b205     JLE        LAB_0048b220
    //                              scenario.cpp:283 (25)
    //         0048b207     MOVSX      EAX,AX
    //         0048b20a     LEA        this,[EBX + 0x1508]
    //         0048b210     PUSH       EAX
    //         0048b211     PUSH       this
    //         0048b212     PUSH       ESI
    //         0048b213     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0048b218     MOV        AX,word ptr [ESP + local_f6]
    //         0048b21d     ADD        ESP,0xc
    //                               LAB_0048b220                                                 XREF[1]:     0048b205(j)  
    //                              scenario.cpp:284 (3)
    //         0048b220     MOVSX      EDX,AX
    //                              scenario.cpp:286 (21)
    //         0048b223     LEA        EAX=>local_f6,[ESP + 0x12]
    //         0048b227     PUSH       0x2
    //         0048b229     PUSH       EAX
    //         0048b22a     PUSH       ESI
    //         0048b22b     MOV        byte ptr [EDX + EBX*0x1 + 0x1508],0x0
    //         0048b233     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              scenario.cpp:287 (13)
    //         0048b238     MOV        AX,word ptr [ESP + local_f6]
    //         0048b23d     ADD        ESP,0xc
    //         0048b240     CMP        AX,DI
    //         0048b243     JLE        LAB_0048b25e
    //                              scenario.cpp:288 (25)
    //         0048b245     MOVSX      this,AX
    //         0048b248     LEA        EDX,[EBX + 0x15e8]
    //         0048b24e     PUSH       this
    //         0048b24f     PUSH       EDX
    //         0048b250     PUSH       ESI
    //         0048b251     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0048b256     MOV        AX,word ptr [ESP + local_f6]
    //         0048b25b     ADD        ESP,0xc
    //                               LAB_0048b25e                                                 XREF[1]:     0048b243(j)  
    //                              scenario.cpp:289 (3)
    //         0048b25e     MOVSX      EAX,AX
    //                              scenario.cpp:291 (21)
    //         0048b261     LEA        this=>local_f6,[ESP + 0x12]
    //         0048b265     PUSH       0x2
    //         0048b267     PUSH       this
    //         0048b268     PUSH       ESI
    //         0048b269     MOV        byte ptr [EAX + EBX*0x1 + 0x15e8],0x0
    //         0048b271     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              scenario.cpp:292 (13)
    //         0048b276     MOV        AX,word ptr [ESP + local_f6]
    //         0048b27b     ADD        ESP,0xc
    //         0048b27e     CMP        AX,DI
    //         0048b281     JLE        LAB_0048b29c
    //                              scenario.cpp:293 (25)
    //         0048b283     MOVSX      EDX,AX
    //         0048b286     LEA        EAX,[EBX + 0x16c8]
    //         0048b28c     PUSH       EDX
    //         0048b28d     PUSH       EAX
    //         0048b28e     PUSH       ESI
    //         0048b28f     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0048b294     MOV        AX,word ptr [ESP + local_f6]
    //         0048b299     ADD        ESP,0xc
    //                               LAB_0048b29c                                                 XREF[1]:     0048b281(j)  
    //                              scenario.cpp:294 (11)
    //         0048b29c     MOVSX      this,AX
    //         0048b29f     MOV        byte ptr [ECX + EBX*0x1 + this->Cine_Loss[0]],
    //                              scenario.cpp:296 (19)
    //         0048b2a7     FLD        float ptr [EBX + 0x1888]
    //         0048b2ad     FCOMP      double ptr [DAT_00572160]                        = 71h    q
    //         0048b2b3     FNSTSW     AX
    //         0048b2b5     TEST       AH,0x1
    //         0048b2b8     JNZ        LAB_0048b2f8
    //                              scenario.cpp:298 (13)
    //         0048b2ba     LEA        EDX=>local_f6,[ESP + 0x12]
    //         0048b2be     PUSH       0x2
    //         0048b2c0     PUSH       EDX
    //         0048b2c1     PUSH       ESI
    //         0048b2c2     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              scenario.cpp:299 (13)
    //         0048b2c7     MOV        AX,word ptr [ESP + local_f6]
    //         0048b2cc     ADD        ESP,0xc
    //         0048b2cf     CMP        AX,DI
    //         0048b2d2     JLE        LAB_0048b2ed
    //                              scenario.cpp:300 (25)
    //         0048b2d4     MOVSX      EAX,AX
    //         0048b2d7     LEA        this,[EBX + 0x17a8]
    //         0048b2dd     PUSH       EAX
    //         0048b2de     PUSH       this
    //         0048b2df     PUSH       ESI
    //         0048b2e0     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0048b2e5     MOV        AX,word ptr [ESP + local_f6]
    //         0048b2ea     ADD        ESP,0xc
    //                               LAB_0048b2ed                                                 XREF[1]:     0048b2d2(j)  
    //                              scenario.cpp:301 (11)
    //         0048b2ed     MOVSX      EDX,AX
    //         0048b2f0     MOV        byte ptr [EDX + EBX*0x1 + 0x17a8],0x0
    //                               LAB_0048b2f8                                                 XREF[1]:     0048b2b8(j)  
    //                              scenario.cpp:304 (19)
    //         0048b2f8     FLD        float ptr [EBX + 0x1888]
    //         0048b2fe     FCOMP      double ptr [DAT_00572168]                        = 9Ah
    //         0048b304     FNSTSW     AX
    //         0048b306     TEST       AH,0x1
    //         0048b309     JNZ        LAB_0048b352
    //                              scenario.cpp:305 (52)
    //         0048b30b     PUSH       0x20
    //         0048b30d     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0048b312     ADD        ESP,0x4
    //         0048b315     MOV        dword ptr [ESP + val],EAX
    //         0048b319     CMP        EAX,EDI
    //         0048b31b     MOV        dword ptr [ESP + local_4],0x1
    //         0048b326     JZ         LAB_0048b341
    //         0048b328     PUSH       0x1
    //         0048b32a     PUSH       ESI
    //         0048b32b     MOV        this,EAX
    //         0048b32d     CALL       TPicture::TPicture                               undefined TPicture(TPicture * this, int param
    //         0048b332     MOV        dword ptr [ESP + local_4],EBP
    //         0048b339     MOV        dword ptr [EBX + 0x198c],EAX
    //                              scenario.cpp:306 (2)
    //         0048b33f     JMP        LAB_0048b358
    //                               LAB_0048b341                                                 XREF[1]:     0048b326(j)  
    //                              scenario.cpp:305 (15)
    //         0048b341     XOR        EAX,EAX
    //         0048b343     MOV        dword ptr [ESP + local_4],EBP
    //         0048b34a     MOV        dword ptr [EBX + 0x198c],EAX
    //                              scenario.cpp:306 (2)
    //         0048b350     JMP        LAB_0048b358
    //                               LAB_0048b352                                                 XREF[1]:     0048b309(j)  
    //                              scenario.cpp:307 (6)
    //         0048b352     MOV        dword ptr [EBX + 0x198c],EDI
    //                               LAB_0048b358                                                 XREF[2]:     0048b33f(j), 0048b350(j)  
    //                              scenario.cpp:309 (11)
    //         0048b358     LEA        EDI,[EBX + 0x12c8]
    //         0048b35e     MOV        EBP,0x10
    //                               LAB_0048b363                                                 XREF[1]:     0048b39f(j)  
    //                              scenario.cpp:311 (13)
    //         0048b363     LEA        EAX=>local_f6,[ESP + 0x12]
    //         0048b367     PUSH       0x2
    //         0048b369     PUSH       EAX
    //         0048b36a     PUSH       ESI
    //         0048b36b     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              scenario.cpp:312 (13)
    //         0048b370     MOV        AX,word ptr [ESP + local_f6]
    //         0048b375     ADD        ESP,0xc
    //         0048b378     TEST       AX,AX
    //         0048b37b     JLE        LAB_0048b392
    //                              scenario.cpp:313 (21)
    //         0048b37d     MOV        EDX,dword ptr [EDI]
    //         0048b37f     MOVSX      this,AX
    //         0048b382     PUSH       this
    //         0048b383     PUSH       EDX
    //         0048b384     PUSH       ESI
    //         0048b385     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0048b38a     MOV        AX,word ptr [ESP + local_f6]
    //         0048b38f     ADD        ESP,0xc
    //                               LAB_0048b392                                                 XREF[1]:     0048b37b(j)  
    //                              scenario.cpp:314 (15)
    //         0048b392     MOV        this,dword ptr [EDI]
    //         0048b394     ADD        EDI,0x4
    //         0048b397     MOVSX      EAX,AX
    //         0048b39a     DEC        EBP
    //         0048b39b     MOV        byte ptr [EAX + this->_padding_*0x1],0x0
    //         0048b39f     JNZ        LAB_0048b363
    //                              scenario.cpp:369 (165)
    //         0048b3a1     LEA        EDI,[EBX + 0x1308]
    //         0048b3a7     MOV        EBP,0x10
    //                               LAB_0048b3ac                                                 XREF[1]:     0048b3e8(j)  
    //         0048b3ac     LEA        EDX=>local_f6,[ESP + 0x12]
    //         0048b3b0     PUSH       0x2
    //         0048b3b2     PUSH       EDX
    //         0048b3b3     PUSH       ESI
    //         0048b3b4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0048b3b9     MOV        AX,word ptr [ESP + local_f6]
    //         0048b3be     ADD        ESP,0xc
    //         0048b3c1     TEST       AX,AX
    //         0048b3c4     JLE        LAB_0048b3db
    //         0048b3c6     MOV        this,dword ptr [EDI]
    //         0048b3c8     MOVSX      EAX,AX
    //         0048b3cb     PUSH       EAX
    //         0048b3cc     PUSH       this
    //         0048b3cd     PUSH       ESI
    //         0048b3ce     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0048b3d3     MOV        AX,word ptr [ESP + local_f6]
    //         0048b3d8     ADD        ESP,0xc
    //                               LAB_0048b3db                                                 XREF[1]:     0048b3c4(j)  
    //         0048b3db     MOVSX      EDX,AX
    //         0048b3de     MOV        EAX,dword ptr [EDI]
    //         0048b3e0     ADD        EDI,0x4
    //         0048b3e3     DEC        EBP
    //         0048b3e4     MOV        byte ptr [EDX + EAX*0x1],0x0
    //         0048b3e8     JNZ        LAB_0048b3ac
    //         0048b3ea     FLD        float ptr [EBX + 0x1888]
    //         0048b3f0     FCOMP      double ptr [DAT_00572170]                        = 48h    H
    //         0048b3f6     FNSTSW     AX
    //         0048b3f8     TEST       AH,0x1
    //         0048b3fb     JNZ        LAB_0048b446
    //         0048b3fd     LEA        EDI,[EBX + 0x1348]
    //         0048b403     MOV        EBP,0x10
    //                               LAB_0048b408                                                 XREF[1]:     0048b444(j)  
    //         0048b408     LEA        this=>local_f6,[ESP + 0x12]
    //         0048b40c     PUSH       0x2
    //         0048b40e     PUSH       this
    //         0048b40f     PUSH       ESI
    //         0048b410     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0048b415     MOV        AX,word ptr [ESP + local_f6]
    //         0048b41a     ADD        ESP,0xc
    //         0048b41d     TEST       AX,AX
    //         0048b420     JLE        LAB_0048b437
    //         0048b422     MOVSX      EDX,AX
    //         0048b425     MOV        EAX,dword ptr [EDI]
    //         0048b427     PUSH       EDX
    //         0048b428     PUSH       EAX
    //         0048b429     PUSH       ESI
    //         0048b42a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0048b42f     MOV        AX,word ptr [ESP + local_f6]
    //         0048b434     ADD        ESP,0xc
    //                               LAB_0048b437                                                 XREF[1]:     0048b420(j)  
    //         0048b437     MOV        EDX,dword ptr [EDI]
    //         0048b439     ADD        EDI,0x4
    //         0048b43c     MOVSX      this,AX
    //         0048b43f     DEC        EBP
    //         0048b440     MOV        byte ptr [this->_padding_ + EDX*0x1],0x0
    //         0048b444     JNZ        LAB_0048b408
    //                               LAB_0048b446                                                 XREF[1]:     0048b3fb(j)  
    //                              scenario.cpp:334 (14)
    //         0048b446     LEA        EDI,[EBX + 0x1448]
    //         0048b44c     MOV        dword ptr [ESP + val],0x10
    //                               LAB_0048b454                                                 XREF[1]:     0048b531(j)  
    //                              scenario.cpp:336 (12)
    //         0048b454     PUSH       0x4
    //         0048b456     PUSH       EDI
    //         0048b457     PUSH       ESI
    //         0048b458     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0048b45d     ADD        ESP,0xc
    //                              scenario.cpp:341 (60)
    //         0048b460     LEA        EBP,[EDI + 0x40]
    //         0048b463     PUSH       0x4
    //         0048b465     PUSH       EBP
    //         0048b466     PUSH       ESI
    //         0048b467     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0048b46c     FLD        float ptr [EBX + 0x1888]
    //         0048b472     FCOMP      double ptr [DAT_00572170]                        = 48h    H
    //         0048b478     ADD        ESP,0xc
    //         0048b47b     FNSTSW     AX
    //         0048b47d     TEST       AH,0x1
    //         0048b480     JNZ        LAB_0048b494
    //         0048b482     LEA        EAX,[EDI + 0x80]
    //         0048b488     PUSH       0x4
    //         0048b48a     PUSH       EAX
    //         0048b48b     PUSH       ESI
    //         0048b48c     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0048b491     ADD        ESP,0xc
    //                               LAB_0048b494                                                 XREF[1]:     0048b480(j)  
    //         0048b494     XOR        this,this
    //         0048b496     MOV        dword ptr [EDI + 0xffffff40],this
    //                              scenario.cpp:342 (3)
    //         0048b49c     MOV        dword ptr [EDI + -0x80],this
    //                              scenario.cpp:343 (3)
    //         0048b49f     MOV        dword ptr [EDI + -0x40],this
    //                              scenario.cpp:344 (19)
    //         0048b4a2     FLD        float ptr [EBX + 0x1888]
    //         0048b4a8     FCOMP      float ptr [DAT_00572178]                         = 33h    3
    //         0048b4ae     FNSTSW     AX
    //         0048b4b0     TEST       AH,0x1
    //         0048b4b3     JNZ        LAB_0048b525
    //                              scenario.cpp:346 (6)
    //         0048b4b5     MOV        EAX,dword ptr [EDI]
    //         0048b4b7     CMP        EAX,this
    //         0048b4b9     JLE        LAB_0048b4d9
    //                              scenario.cpp:348 (17)
    //         0048b4bb     PUSH       0x1
    //         0048b4bd     PUSH       EAX
    //         0048b4be     CALL       calloc                                           undefined calloc()
    //         0048b4c3     ADD        ESP,0x8
    //         0048b4c6     MOV        dword ptr [EDI + 0xffffff40],EAX
    //                              scenario.cpp:349 (13)
    //         0048b4cc     MOV        this,dword ptr [EDI]
    //         0048b4ce     PUSH       this
    //         0048b4cf     PUSH       EAX
    //         0048b4d0     PUSH       ESI
    //         0048b4d1     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0048b4d6     ADD        ESP,0xc
    //                               LAB_0048b4d9                                                 XREF[1]:     0048b4b9(j)  
    //                              scenario.cpp:352 (7)
    //         0048b4d9     MOV        EAX,dword ptr [EBP]
    //         0048b4dc     TEST       EAX,EAX
    //         0048b4de     JLE        LAB_0048b4fc
    //                              scenario.cpp:354 (14)
    //         0048b4e0     PUSH       0x1
    //         0048b4e2     PUSH       EAX
    //         0048b4e3     CALL       calloc                                           undefined calloc()
    //         0048b4e8     ADD        ESP,0x8
    //         0048b4eb     MOV        dword ptr [EDI + -0x80],EAX
    //                              scenario.cpp:355 (14)
    //         0048b4ee     MOV        EDX,dword ptr [EBP]
    //         0048b4f1     PUSH       EDX
    //         0048b4f2     PUSH       EAX
    //         0048b4f3     PUSH       ESI
    //         0048b4f4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0048b4f9     ADD        ESP,0xc
    //                               LAB_0048b4fc                                                 XREF[1]:     0048b4de(j)  
    //                              scenario.cpp:358 (10)
    //         0048b4fc     MOV        EAX,dword ptr [EDI + 0x80]
    //         0048b502     TEST       EAX,EAX
    //         0048b504     JLE        LAB_0048b525
    //                              scenario.cpp:360 (14)
    //         0048b506     PUSH       0x1
    //         0048b508     PUSH       EAX
    //         0048b509     CALL       calloc                                           undefined calloc()
    //         0048b50e     ADD        ESP,0x8
    //         0048b511     MOV        dword ptr [EDI + -0x40],EAX
    //                              scenario.cpp:361 (35)
    //         0048b514     MOV        this,dword ptr [EDI + 0x80]
    //         0048b51a     PUSH       this
    //         0048b51b     PUSH       EAX
    //         0048b51c     PUSH       ESI
    //         0048b51d     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0048b522     ADD        ESP,0xc
    //                               LAB_0048b525                                                 XREF[2]:     0048b4b3(j), 0048b504(j)  
    //         0048b525     MOV        EAX,dword ptr [ESP + val]
    //         0048b529     ADD        EDI,0x4
    //         0048b52c     DEC        EAX
    //         0048b52d     MOV        dword ptr [ESP + val],EAX
    //         0048b531     JNZ        LAB_0048b454
    //                              scenario.cpp:367 (27)
    //         0048b537     FLD        float ptr [EBX + 0x1888]
    //         0048b53d     FCOMP      float ptr [DAT_0057217c]                         = 5Ch    \
    //         0048b543     MOV        dword ptr [ESP + text[0]],0x0
    //         0048b54b     FNSTSW     AX
    //         0048b54d     TEST       AH,0x41
    //         0048b550     JNZ        LAB_0048b562
    //                              scenario.cpp:368 (16)
    //         0048b552     LEA        EDX=>text,[ESP + 0x18]
    //         0048b556     PUSH       0x4
    //         0048b558     PUSH       EDX
    //         0048b559     PUSH       ESI
    //         0048b55a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0048b55f     ADD        ESP,0xc
    //                               LAB_0048b562                                                 XREF[1]:     0048b550(j)  
    //                              scenario.cpp:369 (29)
    //         0048b562     MOV        this,dword ptr [ESP + local_c]
    //         0048b569     POP        EDI
    //         0048b56a     POP        ESI
    //         0048b56b     MOV        EAX,EBX
    //         0048b56d     POP        EBP
    //         0048b56e     MOV        dword ptr FS:[0x0],this
    //         0048b575     POP        EBX
    //         0048b576     ADD        ESP,0xf8
    //         0048b57c     RET        0x8
    //         0048b57f     ??         90h
}

RGE_Scenario::~RGE_Scenario() {
    /* TODO: Stub */
    //                              void __thiscall ~RGE_Scenario(RGE_Scenario * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //                               ??1RGE_Scenario@@UAE@XZ                                      XREF[2]:     `scalar_deleting_destructor':0048a
    //                               RGE_Scenario::~RGE_Scenario                                               ~RGE_Scenario:0052ab7e(T), 
    //                                                                                                         ~T_Scenario:0052ab80(j)  
    //                              scenario.cpp:374 (4)
    //         0048b5a0     PUSH       ESI
    //         0048b5a1     MOV        ESI,this
    //         0048b5a3     PUSH       EDI
    //                              scenario.cpp:375 (13)
    //         0048b5a4     MOV        this,dword ptr [ESI + 0x4]
    //         0048b5a7     MOV        dword ptr [ESI],RGE_Scenario::`vftable'          = 0048b580
    //         0048b5ad     TEST       this,this
    //         0048b5af     JZ         LAB_0048b5be
    //                              scenario.cpp:377 (6)
    //         0048b5b1     MOV        EAX,dword ptr [this->_padding_]
    //         0048b5b3     PUSH       0x1
    //         0048b5b5     CALL       dword ptr [EAX]
    //                              scenario.cpp:378 (7)
    //         0048b5b7     MOV        dword ptr [ESI + 0x4],0x0
    //                               LAB_0048b5be                                                 XREF[1]:     0048b5af(j)  
    //                              scenario.cpp:381 (10)
    //         0048b5be     MOV        EAX,dword ptr [ESI + 0x1014]
    //         0048b5c4     TEST       EAX,EAX
    //         0048b5c6     JZ         LAB_0048b5d1
    //                              scenario.cpp:382 (9)
    //         0048b5c8     PUSH       EAX
    //         0048b5c9     CALL       free                                             undefined free()
    //         0048b5ce     ADD        ESP,0x4
    //                               LAB_0048b5d1                                                 XREF[1]:     0048b5c6(j)  
    //                              scenario.cpp:384 (10)
    //         0048b5d1     MOV        EAX,dword ptr [ESI + 0x1018]
    //         0048b5d7     TEST       EAX,EAX
    //         0048b5d9     JZ         LAB_0048b5e4
    //                              scenario.cpp:385 (9)
    //         0048b5db     PUSH       EAX
    //         0048b5dc     CALL       free                                             undefined free()
    //         0048b5e1     ADD        ESP,0x4
    //                               LAB_0048b5e4                                                 XREF[1]:     0048b5d9(j)  
    //                              scenario.cpp:387 (10)
    //         0048b5e4     MOV        EAX,dword ptr [ESI + 0x101c]
    //         0048b5ea     TEST       EAX,EAX
    //         0048b5ec     JZ         LAB_0048b5f7
    //                              scenario.cpp:388 (9)
    //         0048b5ee     PUSH       EAX
    //         0048b5ef     CALL       free                                             undefined free()
    //         0048b5f4     ADD        ESP,0x4
    //                               LAB_0048b5f7                                                 XREF[1]:     0048b5ec(j)  
    //                              scenario.cpp:390 (10)
    //         0048b5f7     MOV        EAX,dword ptr [ESI + 0x1020]
    //         0048b5fd     TEST       EAX,EAX
    //         0048b5ff     JZ         LAB_0048b60a
    //                              scenario.cpp:391 (9)
    //         0048b601     PUSH       EAX
    //         0048b602     CALL       free                                             undefined free()
    //         0048b607     ADD        ESP,0x4
    //                               LAB_0048b60a                                                 XREF[1]:     0048b5ff(j)  
    //                              scenario.cpp:393 (10)
    //         0048b60a     MOV        EAX,dword ptr [ESI + 0x1024]
    //         0048b610     TEST       EAX,EAX
    //         0048b612     JZ         LAB_0048b61d
    //                              scenario.cpp:394 (9)
    //         0048b614     PUSH       EAX
    //         0048b615     CALL       free                                             undefined free()
    //         0048b61a     ADD        ESP,0x4
    //                               LAB_0048b61d                                                 XREF[1]:     0048b612(j)  
    //                              scenario.cpp:396 (12)
    //         0048b61d     MOV        this,dword ptr [ESI + 0x1010]
    //         0048b623     PUSH       this
    //         0048b624     CALL       operator_delete                                  void operator_delete(void * param_1)
    //                              scenario.cpp:398 (13)
    //         0048b629     MOV        EDI,dword ptr [ESI + 0x198c]
    //         0048b62f     ADD        ESP,0x4
    //         0048b632     TEST       EDI,EDI
    //         0048b634     JZ         LAB_0048b650
    //                              scenario.cpp:400 (16)
    //         0048b636     MOV        this,EDI
    //         0048b638     CALL       TPicture::~TPicture                              void ~TPicture(TPicture * this)
    //         0048b63d     PUSH       EDI
    //         0048b63e     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0048b643     ADD        ESP,0x4
    //                              scenario.cpp:401 (10)
    //         0048b646     MOV        dword ptr [ESI + 0x198c],0x0
    //                               LAB_0048b650                                                 XREF[1]:     0048b634(j)  
    //                              scenario.cpp:404 (11)
    //         0048b650     ADD        ESI,0x1308
    //         0048b656     MOV        EDI,0x10
    //                               LAB_0048b65b                                                 XREF[1]:     0048b6bb(j)  
    //                              scenario.cpp:406 (9)
    //         0048b65b     MOV        EDX,dword ptr [ESI + -0x40]
    //         0048b65e     PUSH       EDX
    //         0048b65f     CALL       operator_delete                                  void operator_delete(void * param_1)
    //                              scenario.cpp:407 (11)
    //         0048b664     MOV        EAX,dword ptr [ESI]
    //         0048b666     ADD        ESP,0x4
    //         0048b669     PUSH       EAX
    //         0048b66a     CALL       operator_delete                                  void operator_delete(void * param_1)
    //                              scenario.cpp:408 (12)
    //         0048b66f     MOV        this,dword ptr [ESI + 0x40]
    //         0048b672     ADD        ESP,0x4
    //         0048b675     PUSH       this
    //         0048b676     CALL       operator_delete                                  void operator_delete(void * param_1)
    //                              scenario.cpp:410 (13)
    //         0048b67b     MOV        EAX,dword ptr [ESI + 0x80]
    //         0048b681     ADD        ESP,0x4
    //         0048b684     TEST       EAX,EAX
    //         0048b686     JZ         LAB_0048b691
    //                              scenario.cpp:411 (9)
    //         0048b688     PUSH       EAX
    //         0048b689     CALL       free                                             undefined free()
    //         0048b68e     ADD        ESP,0x4
    //                               LAB_0048b691                                                 XREF[1]:     0048b686(j)  
    //                              scenario.cpp:413 (10)
    //         0048b691     MOV        EAX,dword ptr [ESI + 0xc0]
    //         0048b697     TEST       EAX,EAX
    //         0048b699     JZ         LAB_0048b6a4
    //                              scenario.cpp:414 (9)
    //         0048b69b     PUSH       EAX
    //         0048b69c     CALL       free                                             undefined free()
    //         0048b6a1     ADD        ESP,0x4
    //                               LAB_0048b6a4                                                 XREF[1]:     0048b699(j)  
    //                              scenario.cpp:416 (10)
    //         0048b6a4     MOV        EAX,dword ptr [ESI + 0x100]
    //         0048b6aa     TEST       EAX,EAX
    //         0048b6ac     JZ         LAB_0048b6b7
    //                              scenario.cpp:417 (15)
    //         0048b6ae     PUSH       EAX
    //         0048b6af     CALL       free                                             undefined free()
    //         0048b6b4     ADD        ESP,0x4
    //                               LAB_0048b6b7                                                 XREF[1]:     0048b6ac(j)  
    //         0048b6b7     ADD        ESI,0x4
    //         0048b6ba     DEC        EDI
    //         0048b6bb     JNZ        LAB_0048b65b
    //                              scenario.cpp:419 (3)
    //         0048b6bd     POP        EDI
    //         0048b6be     POP        ESI
    //         0048b6bf     RET
}

void RGE_Scenario::InitializeTextValues() {
    /* TODO: Stub */
    //                              void __thiscall InitializeTextValues(RGE_Scenario * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //              char[30]          Stack[-0x24]   default_string
    //              char[30]          Stack[-0x44]   none_string               XREF[0,1]:   0048b6cf(*)  
    //                               ?InitializeTextValues@RGE_Scenario@@QAEXXZ                   XREF[2]:     RGE_Scenario:0048adba(c), 
    //                               RGE_Scenario::InitializeTextValues                                        RGE_Scenario:0048ae3e(c)  
    //                              scenario.cpp:424 (8)
    //         0048b6c0     SUB        ESP,0x48
    //         0048b6c3     PUSH       EBX
    //         0048b6c4     PUSH       EBP
    //         0048b6c5     MOV        EBP,this
    //         0048b6c7     PUSH       ESI
    //                              scenario.cpp:431 (24)
    //         0048b6c8     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048b6ce     PUSH       EDI
    //         0048b6cf     LEA        EDX=>none_string[4],[ESP + 0x18]
    //         0048b6d3     PUSH       0x1e
    //         0048b6d5     MOV        EAX,dword ptr [this->_padding_]
    //         0048b6d7     PUSH       EDX
    //                              language.dll match for 0x2775: " <None> "
    //         0048b6d8     PUSH       0x2775
    //         0048b6dd     CALL       dword ptr [EAX + 0x20]
    //                              scenario.cpp:432 (23)
    //         0048b6e0     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048b6e6     LEA        EDX,[ESP + 0x38]
    //         0048b6ea     PUSH       0x1e
    //         0048b6ec     PUSH       EDX
    //         0048b6ed     MOV        EAX,dword ptr [this->_padding_]
    //                              language.dll match for 0x277b: "Random"
    //         0048b6ef     PUSH       0x277b
    //         0048b6f4     CALL       dword ptr [EAX + 0x20]
    //                              scenario.cpp:434 (2)
    //         0048b6f7     XOR        EBX,EBX
    //                              scenario.cpp:439 (42)
    //         0048b6f9     PUSH       0xe0
    //         0048b6fe     MOV        dword ptr [EBP + 0x1014],EBX
    //         0048b704     MOV        dword ptr [EBP + 0x1018],EBX
    //         0048b70a     MOV        dword ptr [EBP + 0x101c],EBX
    //         0048b710     MOV        dword ptr [EBP + 0x1020],EBX
    //         0048b716     MOV        dword ptr [EBP + 0x1024],EBX
    //         0048b71c     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0048b721     MOV        EDI,EAX
    //                              scenario.cpp:441 (15)
    //         0048b723     MOV        this,0x38
    //         0048b728     XOR        EAX,EAX
    //         0048b72a     MOV        dword ptr [EBP + 0x1010],EDI
    //         0048b730     STOSD.REP  ES:EDI
    //                              scenario.cpp:443 (28)
    //         0048b732     LEA        EDI,[ESP + 0x1c]
    //         0048b736     OR         this,0xffffffff
    //         0048b739     ADD        ESP,0x4
    //         0048b73c     LEA        EDX,[EBP + 0x1508]
    //         0048b742     SCASB.RE   ES:EDI
    //         0048b744     NOT        this
    //         0048b746     SUB        EDI,this
    //         0048b748     MOV        EAX,this
    //         0048b74a     MOV        ESI,EDI
    //         0048b74c     MOV        EDI,EDX
    //                              scenario.cpp:444 (39)
    //         0048b74e     LEA        EDX,[EBP + 0x15e8]
    //         0048b754     SHR        this,0x2
    //         0048b757     MOVSD.REP  ES:EDI,ESI
    //         0048b759     MOV        this,EAX
    //         0048b75b     XOR        EAX,EAX
    //         0048b75d     AND        this,0x3
    //         0048b760     MOVSB.REP  ES:EDI,ESI
    //         0048b762     LEA        EDI,[ESP + 0x18]
    //         0048b766     OR         this,0xffffffff
    //         0048b769     SCASB.RE   ES:EDI
    //         0048b76b     NOT        this
    //         0048b76d     SUB        EDI,this
    //         0048b76f     MOV        EAX,this
    //         0048b771     MOV        ESI,EDI
    //         0048b773     MOV        EDI,EDX
    //                              scenario.cpp:445 (39)
    //         0048b775     LEA        EDX,[EBP + 0x16c8]
    //         0048b77b     SHR        this,0x2
    //         0048b77e     MOVSD.REP  ES:EDI,ESI
    //         0048b780     MOV        this,EAX
    //         0048b782     XOR        EAX,EAX
    //         0048b784     AND        this,0x3
    //         0048b787     MOVSB.REP  ES:EDI,ESI
    //         0048b789     LEA        EDI,[ESP + 0x18]
    //         0048b78d     OR         this,0xffffffff
    //         0048b790     SCASB.RE   ES:EDI
    //         0048b792     NOT        this
    //         0048b794     SUB        EDI,this
    //         0048b796     MOV        EAX,this
    //         0048b798     MOV        ESI,EDI
    //         0048b79a     MOV        EDI,EDX
    //                              scenario.cpp:446 (72)
    //         0048b79c     LEA        EDX,[EBP + 0x17a8]
    //         0048b7a2     SHR        this,0x2
    //         0048b7a5     MOVSD.REP  ES:EDI,ESI
    //         0048b7a7     MOV        this,EAX
    //         0048b7a9     AND        this,0x3
    //         0048b7ac     MOVSB.REP  ES:EDI,ESI
    //         0048b7ae     OR         this,0xffffffff
    //         0048b7b1     LEA        EDI,[ESP + 0x18]
    //         0048b7b5     XOR        EAX,EAX
    //         0048b7b7     SCASB.RE   ES:EDI
    //         0048b7b9     NOT        this
    //         0048b7bb     SUB        EDI,this
    //         0048b7bd     MOV        dword ptr [ESP + 0x14],0x10
    //         0048b7c5     MOV        EAX,this
    //         0048b7c7     MOV        ESI,EDI
    //         0048b7c9     MOV        EDI,EDX
    //         0048b7cb     SHR        this,0x2
    //         0048b7ce     MOVSD.REP  ES:EDI,ESI
    //         0048b7d0     MOV        this,EAX
    //         0048b7d2     AND        this,0x3
    //         0048b7d5     MOVSB.REP  ES:EDI,ESI
    //         0048b7d7     LEA        this,[EBP + 0xd]
    //         0048b7da     ADD        EBP,0x18cc
    //         0048b7e0     MOV        dword ptr [ESP + 0x10],this
    //                               LAB_0048b7e4                                                 XREF[1]:     0048b8fa(j)  
    //                              scenario.cpp:456 (19)
    //         0048b7e4     MOV        EDX,dword ptr [ESP + 0x10]
    //         0048b7e8     MOV        dword ptr [EBP + -0x40],EBX
    //         0048b7eb     MOV        dword ptr [EBP],EBX
    //         0048b7ee     MOV        dword ptr [EBP + 0x40],EBX
    //         0048b7f1     MOV        dword ptr [EBP + 0x80],EBX
    //                              scenario.cpp:458 (14)
    //         0048b7f7     PUSH       0xe0
    //         0048b7fc     MOV        byte ptr [EDX],BL
    //         0048b7fe     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0048b803     MOV        EDI,EAX
    //                              scenario.cpp:459 (15)
    //         0048b805     MOV        this,0x38
    //         0048b80a     XOR        EAX,EAX
    //         0048b80c     MOV        dword ptr [EBP + 0xfffff9fc],EDI
    //         0048b812     STOSD.REP  ES:EDI
    //                              scenario.cpp:460 (16)
    //         0048b814     LEA        EDI,[ESP + 0x3c]
    //         0048b818     OR         this,0xffffffff
    //         0048b81b     ADD        ESP,0x4
    //         0048b81e     SCASB.RE   ES:EDI
    //         0048b820     NOT        this
    //         0048b822     SUB        EDI,this
    //                              scenario.cpp:462 (34)
    //         0048b824     PUSH       0xe0
    //         0048b829     MOV        EAX,this
    //         0048b82b     MOV        ESI,EDI
    //         0048b82d     MOV        EDI,dword ptr [EBP + 0xfffff9fc]
    //         0048b833     SHR        this,0x2
    //         0048b836     MOVSD.REP  ES:EDI,ESI
    //         0048b838     MOV        this,EAX
    //         0048b83a     AND        this,0x3
    //         0048b83d     MOVSB.REP  ES:EDI,ESI
    //         0048b83f     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0048b844     MOV        EDI,EAX
    //                              scenario.cpp:463 (15)
    //         0048b846     MOV        this,0x38
    //         0048b84b     XOR        EAX,EAX
    //         0048b84d     MOV        dword ptr [EBP + 0xfffffa3c],EDI
    //         0048b853     STOSD.REP  ES:EDI
    //                              scenario.cpp:464 (16)
    //         0048b855     LEA        EDI,[ESP + 0x1c]
    //         0048b859     OR         this,0xffffffff
    //         0048b85c     ADD        ESP,0x4
    //         0048b85f     SCASB.RE   ES:EDI
    //         0048b861     NOT        this
    //         0048b863     SUB        EDI,this
    //                              scenario.cpp:466 (34)
    //         0048b865     PUSH       0xe0
    //         0048b86a     MOV        EDX,this
    //         0048b86c     MOV        ESI,EDI
    //         0048b86e     MOV        EDI,dword ptr [EBP + 0xfffffa3c]
    //         0048b874     SHR        this,0x2
    //         0048b877     MOVSD.REP  ES:EDI,ESI
    //         0048b879     MOV        this,EDX
    //         0048b87b     AND        this,0x3
    //         0048b87e     MOVSB.REP  ES:EDI,ESI
    //         0048b880     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0048b885     MOV        EDI,EAX
    //                              scenario.cpp:467 (15)
    //         0048b887     MOV        this,0x38
    //         0048b88c     XOR        EAX,EAX
    //         0048b88e     MOV        dword ptr [EBP + 0xfffffa7c],EDI
    //         0048b894     STOSD.REP  ES:EDI
    //                              scenario.cpp:468 (49)
    //         0048b896     LEA        EDI,[ESP + 0x3c]
    //         0048b89a     OR         this,0xffffffff
    //         0048b89d     ADD        ESP,0x4
    //         0048b8a0     ADD        EBP,0x4
    //         0048b8a3     SCASB.RE   ES:EDI
    //         0048b8a5     NOT        this
    //         0048b8a7     SUB        EDI,this
    //         0048b8a9     MOV        EAX,this
    //         0048b8ab     MOV        ESI,EDI
    //         0048b8ad     MOV        EDI,dword ptr [EBP + 0xfffffa78]
    //         0048b8b3     SHR        this,0x2
    //         0048b8b6     MOVSD.REP  ES:EDI,ESI
    //         0048b8b8     MOV        this,EAX
    //         0048b8ba     MOV        EAX,dword ptr [ESP + 0x14]
    //         0048b8be     AND        this,0x3
    //         0048b8c1     MOVSB.REP  ES:EDI,ESI
    //         0048b8c3     MOV        this,dword ptr [ESP + 0x10]
    //                              scenario.cpp:470 (6)
    //         0048b8c7     MOV        dword ptr [EBP + 0xfffffab8],EBX
    //                              scenario.cpp:471 (6)
    //         0048b8cd     MOV        dword ptr [EBP + 0xfffffaf8],EBX
    //                              scenario.cpp:472 (6)
    //         0048b8d3     MOV        dword ptr [EBP + 0xfffffb38],EBX
    //                              scenario.cpp:474 (6)
    //         0048b8d9     MOV        dword ptr [EBP + 0xfffffb78],EBX
    //                              scenario.cpp:475 (6)
    //         0048b8df     MOV        dword ptr [EBP + 0xfffffbb8],EBX
    //                              scenario.cpp:476 (17)
    //         0048b8e5     MOV        dword ptr [EBP + 0xfffffbf8],EBX
    //         0048b8eb     ADD        this,0x100
    //         0048b8f1     MOV        dword ptr [ESP + 0x10],this
    //         0048b8f5     DEC        EAX
    //                              scenario.cpp:448 (10)
    //         0048b8f6     MOV        dword ptr [ESP + 0x14],EAX
    //         0048b8fa     JNZ        LAB_0048b7e4
    //                              scenario.cpp:478 (8)
    //         0048b900     POP        EDI
    //         0048b901     POP        ESI
    //         0048b902     POP        EBP
    //         0048b903     POP        EBX
    //         0048b904     ADD        ESP,0x48
    //         0048b907     RET
    //         0048b908     ??         90h
    //         0048b909     NOP
    //         0048b90a     NOP
    //         0048b90b     NOP
    //         0048b90c     NOP
    //         0048b90d     NOP
    //         0048b90e     NOP
    //         0048b90f     NOP
    return;
}

void RGE_Scenario::Set_scenario_name(char* param_1) {
    /* TODO: Stub */
    //                              void __thiscall Set_scenario_name(RGE_Scenario * this, char * param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0048b911(R)  
    //                               ?Set_scenario_name@RGE_Scenario@@QAEXPAD@Z                   XREF[4]:     save_for_scenario_editor:004a80a3(
    //                               RGE_Scenario::Set_scenario_name                                           TRIBE_Screen_Sed:004a863d(c), 
    //                                                                                                         scenario_get_default_name:004adac9
    //                                                                                                         new_game:0052eff4(c)  
    //                              scenario.cpp:483 (1)
    //         0048b910     PUSH       EDI
    //                              scenario.cpp:484 (10)
    //         0048b911     MOV        EDI,dword ptr [ESP + param_1]
    //         0048b915     TEST       EDI,EDI
    //         0048b917     MOV        EDX,this
    //         0048b919     JZ         LAB_0048b942
    //                              scenario.cpp:485 (35)
    //         0048b91b     OR         this,0xffffffff
    //         0048b91e     XOR        EAX,EAX
    //         0048b920     SCASB.RE   ES:EDI
    //         0048b922     NOT        this
    //         0048b924     SUB        EDI,this
    //         0048b926     PUSH       ESI
    //         0048b927     MOV        EAX,this
    //         0048b929     MOV        ESI,EDI
    //         0048b92b     MOV        EDI,dword ptr [EDX + 0x1010]
    //         0048b931     SHR        this,0x2
    //         0048b934     MOVSD.REP  ES:EDI,ESI
    //         0048b936     MOV        this,EAX
    //         0048b938     AND        this,0x3
    //         0048b93b     MOVSB.REP  ES:EDI,ESI
    //         0048b93d     POP        ESI
    //                              scenario.cpp:488 (4)
    //         0048b93e     POP        EDI
    //         0048b93f     RET        0x4
    //                               LAB_0048b942                                                 XREF[1]:     0048b919(j)  
    //                              scenario.cpp:487 (6)
    //         0048b942     MOV        this,dword ptr [EDX + 0x1010]
    //                              scenario.cpp:488 (7)
    //         0048b948     POP        EDI
    //         0048b949     MOV        byte ptr [this->_padding_],0x0
    //         0048b94c     RET        0x4
    //         0048b94f     ??         90h
    return;
}

void RGE_Scenario::Set_description(char* param_1) {
    /* TODO: Stub */
    //                              void __thiscall Set_description(RGE_Scenario * this, char * param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0048b950(R)  
    //                               ?Set_description@RGE_Scenario@@QAEXPAD@Z
    //                               RGE_Scenario::Set_description
    //                              scenario.cpp:492 (12)
    //         0048b950     MOV        EAX,dword ptr [ESP + param_1]
    //         0048b954     PUSH       0x0
    //         0048b956     PUSH       EAX
    //         0048b957     CALL       RGE_Scenario::Set_message                        void Set_message(RGE_Scenario * this, char * 
    //                              scenario.cpp:494 (3)
    //         0048b95c     RET        0x4
    //         0048b95f     ??         90h
    return;
}

void RGE_Scenario::Set_Cine_PreGame(char* param_1) {
    /* TODO: Stub */
    //                              void __thiscall Set_Cine_PreGame(RGE_Scenario * this, char * param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0048b961(R)  
    //                               ?Set_Cine_PreGame@RGE_Scenario@@QAEXPAD@Z                    XREF[1]:     set_scenario_mode:004aa43e(c)  
    //                               RGE_Scenario::Set_Cine_PreGame
    //                              scenario.cpp:499 (1)
    //         0048b960     PUSH       EDI
    //                              scenario.cpp:500 (8)
    //         0048b961     MOV        EDI,dword ptr [ESP + param_1]
    //         0048b965     TEST       EDI,EDI
    //         0048b967     JZ         LAB_0048b992
    //                              scenario.cpp:501 (37)
    //         0048b969     LEA        EDX,[ECX + this->Cine_PreGame[0]]
    //         0048b96f     OR         this,0xffffffff
    //         0048b972     XOR        EAX,EAX
    //         0048b974     PUSH       ESI
    //         0048b975     SCASB.RE   ES:EDI
    //         0048b977     NOT        this
    //         0048b979     SUB        EDI,this
    //         0048b97b     MOV        EAX,this
    //         0048b97d     MOV        ESI,EDI
    //         0048b97f     MOV        EDI,EDX
    //         0048b981     SHR        this,0x2
    //         0048b984     MOVSD.REP  ES:EDI,ESI
    //         0048b986     MOV        this,EAX
    //         0048b988     AND        this,0x3
    //         0048b98b     MOVSB.REP  ES:EDI,ESI
    //         0048b98d     POP        ESI
    //                              scenario.cpp:504 (4)
    //         0048b98e     POP        EDI
    //         0048b98f     RET        0x4
    //                               LAB_0048b992                                                 XREF[1]:     0048b967(j)  
    //                              scenario.cpp:503 (7)
    //         0048b992     MOV        byte ptr [ECX + this->Cine_PreGame[0]],0x0
    //                              scenario.cpp:504 (4)
    //         0048b999     POP        EDI
    //         0048b99a     RET        0x4
    //         0048b99d     ??         90h
    //         0048b99e     NOP
    //         0048b99f     NOP
    return;
}

void RGE_Scenario::Set_Cine_Victory(char* param_1) {
    /* TODO: Stub */
    //                              void __thiscall Set_Cine_Victory(RGE_Scenario * this, char * param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0048b9a1(R)  
    //                               ?Set_Cine_Victory@RGE_Scenario@@QAEXPAD@Z                    XREF[1]:     set_scenario_mode:004aa458(c)  
    //                               RGE_Scenario::Set_Cine_Victory
    //                              scenario.cpp:508 (1)
    //         0048b9a0     PUSH       EDI
    //                              scenario.cpp:509 (8)
    //         0048b9a1     MOV        EDI,dword ptr [ESP + param_1]
    //         0048b9a5     TEST       EDI,EDI
    //         0048b9a7     JZ         LAB_0048b9d2
    //                              scenario.cpp:510 (37)
    //         0048b9a9     LEA        EDX,[ECX + this->Cine_Victory[0]]
    //         0048b9af     OR         this,0xffffffff
    //         0048b9b2     XOR        EAX,EAX
    //         0048b9b4     PUSH       ESI
    //         0048b9b5     SCASB.RE   ES:EDI
    //         0048b9b7     NOT        this
    //         0048b9b9     SUB        EDI,this
    //         0048b9bb     MOV        EAX,this
    //         0048b9bd     MOV        ESI,EDI
    //         0048b9bf     MOV        EDI,EDX
    //         0048b9c1     SHR        this,0x2
    //         0048b9c4     MOVSD.REP  ES:EDI,ESI
    //         0048b9c6     MOV        this,EAX
    //         0048b9c8     AND        this,0x3
    //         0048b9cb     MOVSB.REP  ES:EDI,ESI
    //         0048b9cd     POP        ESI
    //                              scenario.cpp:513 (4)
    //         0048b9ce     POP        EDI
    //         0048b9cf     RET        0x4
    //                               LAB_0048b9d2                                                 XREF[1]:     0048b9a7(j)  
    //                              scenario.cpp:512 (7)
    //         0048b9d2     MOV        byte ptr [ECX + this->Cine_Victory[0]],0x0
    //                              scenario.cpp:513 (4)
    //         0048b9d9     POP        EDI
    //         0048b9da     RET        0x4
    //         0048b9dd     ??         90h
    //         0048b9de     NOP
    //         0048b9df     NOP
    return;
}

void RGE_Scenario::Set_Cine_Loss(char* param_1) {
    /* TODO: Stub */
    //                              void __thiscall Set_Cine_Loss(RGE_Scenario * this, char * param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0048b9e1(R)  
    //                               ?Set_Cine_Loss@RGE_Scenario@@QAEXPAD@Z                       XREF[1]:     set_scenario_mode:004aa472(c)  
    //                               RGE_Scenario::Set_Cine_Loss
    //                              scenario.cpp:517 (1)
    //         0048b9e0     PUSH       EDI
    //                              scenario.cpp:518 (8)
    //         0048b9e1     MOV        EDI,dword ptr [ESP + param_1]
    //         0048b9e5     TEST       EDI,EDI
    //         0048b9e7     JZ         LAB_0048ba12
    //                              scenario.cpp:519 (37)
    //         0048b9e9     LEA        EDX,[ECX + this->Cine_Loss[0]]
    //         0048b9ef     OR         this,0xffffffff
    //         0048b9f2     XOR        EAX,EAX
    //         0048b9f4     PUSH       ESI
    //         0048b9f5     SCASB.RE   ES:EDI
    //         0048b9f7     NOT        this
    //         0048b9f9     SUB        EDI,this
    //         0048b9fb     MOV        EAX,this
    //         0048b9fd     MOV        ESI,EDI
    //         0048b9ff     MOV        EDI,EDX
    //         0048ba01     SHR        this,0x2
    //         0048ba04     MOVSD.REP  ES:EDI,ESI
    //         0048ba06     MOV        this,EAX
    //         0048ba08     AND        this,0x3
    //         0048ba0b     MOVSB.REP  ES:EDI,ESI
    //         0048ba0d     POP        ESI
    //                              scenario.cpp:522 (4)
    //         0048ba0e     POP        EDI
    //         0048ba0f     RET        0x4
    //                               LAB_0048ba12                                                 XREF[1]:     0048b9e7(j)  
    //                              scenario.cpp:521 (7)
    //         0048ba12     MOV        byte ptr [ECX + this->Cine_Loss[0]],0x0
    //                              scenario.cpp:522 (4)
    //         0048ba19     POP        EDI
    //         0048ba1a     RET        0x4
    //         0048ba1d     ??         90h
    //         0048ba1e     NOP
    //         0048ba1f     NOP
    return;
}

void RGE_Scenario::Set_Mission_Bmp(char* param_1) {
    /* TODO: Stub */
    //                              void __thiscall Set_Mission_Bmp(RGE_Scenario * this, char * param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0048ba21(R)  
    //                               ?Set_Mission_Bmp@RGE_Scenario@@QAEXPAD@Z                     XREF[1]:     set_scenario_mode:004aa48c(c)  
    //                               RGE_Scenario::Set_Mission_Bmp
    //                              scenario.cpp:526 (1)
    //         0048ba20     PUSH       EDI
    //                              scenario.cpp:527 (8)
    //         0048ba21     MOV        EDI,dword ptr [ESP + param_1]
    //         0048ba25     TEST       EDI,EDI
    //         0048ba27     JZ         LAB_0048ba52
    //                              scenario.cpp:528 (37)
    //         0048ba29     LEA        EDX,[ECX + this->Mission_Bmp[0]]
    //         0048ba2f     OR         this,0xffffffff
    //         0048ba32     XOR        EAX,EAX
    //         0048ba34     PUSH       ESI
    //         0048ba35     SCASB.RE   ES:EDI
    //         0048ba37     NOT        this
    //         0048ba39     SUB        EDI,this
    //         0048ba3b     MOV        EAX,this
    //         0048ba3d     MOV        ESI,EDI
    //         0048ba3f     MOV        EDI,EDX
    //         0048ba41     SHR        this,0x2
    //         0048ba44     MOVSD.REP  ES:EDI,ESI
    //         0048ba46     MOV        this,EAX
    //         0048ba48     AND        this,0x3
    //         0048ba4b     MOVSB.REP  ES:EDI,ESI
    //         0048ba4d     POP        ESI
    //                              scenario.cpp:531 (4)
    //         0048ba4e     POP        EDI
    //         0048ba4f     RET        0x4
    //                               LAB_0048ba52                                                 XREF[1]:     0048ba27(j)  
    //                              scenario.cpp:530 (7)
    //         0048ba52     MOV        byte ptr [ECX + this->Mission_Bmp[0]],0x0
    //                              scenario.cpp:531 (4)
    //         0048ba59     POP        EDI
    //         0048ba5a     RET        0x4
    //         0048ba5d     ??         90h
    //         0048ba5e     NOP
    //         0048ba5f     NOP
    return;
}

void RGE_Scenario::Set_BuildList(int param_1, char* param_2, int param_3) {
    /* TODO: Stub */
    //                              void __thiscall Set_BuildList(RGE_Scenario * this, int param_1, char
    //              void              <VOID>         <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[2]:     0048ba6b(R), 0048ba97(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     0048ba61(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0048baac(R)  
    //                               ?Set_BuildList@RGE_Scenario@@QAEXHPADH@Z                     XREF[1]:     set_player:004aafec(c)  
    //                               RGE_Scenario::Set_BuildList
    //                              scenario.cpp:535 (1)
    //         0048ba60     PUSH       EBX
    //                              scenario.cpp:536 (10)
    //         0048ba61     MOV        EBX,dword ptr [ESP + param_2]
    //         0048ba65     PUSH       ESI
    //         0048ba66     PUSH       EDI
    //         0048ba67     TEST       EBX,EBX
    //         0048ba69     JZ         LAB_0048ba97
    //                              scenario.cpp:537 (42)
    //         0048ba6b     MOV        EAX,dword ptr [ESP + param_1]
    //         0048ba6f     MOV        EDI,EBX
    //         0048ba71     LEA        EDX,[ECX + EAX*0x4 + this->BuildList[0]]
    //         0048ba78     OR         this,0xffffffff
    //         0048ba7b     XOR        EAX,EAX
    //         0048ba7d     SCASB.RE   ES:EDI
    //         0048ba7f     NOT        this
    //         0048ba81     SUB        EDI,this
    //         0048ba83     MOV        EAX,this
    //         0048ba85     MOV        ESI,EDI
    //         0048ba87     MOV        EDI,dword ptr [EDX]
    //         0048ba89     SHR        this,0x2
    //         0048ba8c     MOVSD.REP  ES:EDI,ESI
    //         0048ba8e     MOV        this,EAX
    //         0048ba90     AND        this,0x3
    //         0048ba93     MOVSB.REP  ES:EDI,ESI
    //                              scenario.cpp:538 (2)
    //         0048ba95     JMP        LAB_0048baac
    //                               LAB_0048ba97                                                 XREF[1]:     0048ba69(j)  
    //                              scenario.cpp:539 (21)
    //         0048ba97     MOV        EDX,dword ptr [ESP + param_1]
    //         0048ba9b     MOV        EAX,dword ptr [ECX + EDX*0x4 + this->BuildList
    //         0048baa2     LEA        EDX,[ECX + EDX*0x4 + this->BuildList[0]]
    //         0048baa9     MOV        byte ptr [EAX],0x0
    //                               LAB_0048baac                                                 XREF[1]:     0048ba95(j)  
    //                              scenario.cpp:541 (25)
    //         0048baac     CMP        dword ptr [ESP + param_3],0x1
    //         0048bab1     JNZ        LAB_0048bac5
    //         0048bab3     MOV        EDI,EBX
    //         0048bab5     OR         this,0xffffffff
    //         0048bab8     XOR        EAX,EAX
    //         0048baba     MOV        EDX,dword ptr [EDX]
    //         0048babc     SCASB.RE   ES:EDI
    //         0048babe     NOT        this
    //         0048bac0     DEC        this
    //         0048bac1     MOV        byte ptr [this->_padding_ + EDX*0x1 + -0x4],AL
    //                               LAB_0048bac5                                                 XREF[1]:     0048bab1(j)  
    //                              scenario.cpp:542 (6)
    //         0048bac5     POP        EDI
    //         0048bac6     POP        ESI
    //         0048bac7     POP        EBX
    //         0048bac8     RET        0xc
    //         0048bacb     ??         90h
    //         0048bacc     NOP
    //         0048bacd     NOP
    //         0048bace     NOP
    //         0048bacf     NOP
    return;
}

void RGE_Scenario::Set_CityPlan(int param_1, char* param_2, int param_3) {
    /* TODO: Stub */
    //                              void __thiscall Set_CityPlan(RGE_Scenario * this, int param_1, char 
    //              void              <VOID>         <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[2]:     0048badb(R), 0048bb07(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     0048bad1(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0048bb1c(R)  
    //                               ?Set_CityPlan@RGE_Scenario@@QAEXHPADH@Z                      XREF[1]:     set_player:004ab009(c)  
    //                               RGE_Scenario::Set_CityPlan
    //                              scenario.cpp:546 (1)
    //         0048bad0     PUSH       EBX
    //                              scenario.cpp:547 (10)
    //         0048bad1     MOV        EBX,dword ptr [ESP + param_2]
    //         0048bad5     PUSH       ESI
    //         0048bad6     PUSH       EDI
    //         0048bad7     TEST       EBX,EBX
    //         0048bad9     JZ         LAB_0048bb07
    //                              scenario.cpp:548 (42)
    //         0048badb     MOV        EAX,dword ptr [ESP + param_1]
    //         0048badf     MOV        EDI,EBX
    //         0048bae1     LEA        EDX,[ECX + EAX*0x4 + this->CityPlan[0]]
    //         0048bae8     OR         this,0xffffffff
    //         0048baeb     XOR        EAX,EAX
    //         0048baed     SCASB.RE   ES:EDI
    //         0048baef     NOT        this
    //         0048baf1     SUB        EDI,this
    //         0048baf3     MOV        EAX,this
    //         0048baf5     MOV        ESI,EDI
    //         0048baf7     MOV        EDI,dword ptr [EDX]
    //         0048baf9     SHR        this,0x2
    //         0048bafc     MOVSD.REP  ES:EDI,ESI
    //         0048bafe     MOV        this,EAX
    //         0048bb00     AND        this,0x3
    //         0048bb03     MOVSB.REP  ES:EDI,ESI
    //                              scenario.cpp:549 (2)
    //         0048bb05     JMP        LAB_0048bb1c
    //                               LAB_0048bb07                                                 XREF[1]:     0048bad9(j)  
    //                              scenario.cpp:550 (21)
    //         0048bb07     MOV        EDX,dword ptr [ESP + param_1]
    //         0048bb0b     MOV        EAX,dword ptr [ECX + EDX*0x4 + this->CityPlan[
    //         0048bb12     LEA        EDX,[ECX + EDX*0x4 + this->CityPlan[0]]
    //         0048bb19     MOV        byte ptr [EAX],0x0
    //                               LAB_0048bb1c                                                 XREF[1]:     0048bb05(j)  
    //                              scenario.cpp:551 (25)
    //         0048bb1c     CMP        dword ptr [ESP + param_3],0x1
    //         0048bb21     JNZ        LAB_0048bb35
    //         0048bb23     MOV        EDI,EBX
    //         0048bb25     OR         this,0xffffffff
    //         0048bb28     XOR        EAX,EAX
    //         0048bb2a     MOV        EDX,dword ptr [EDX]
    //         0048bb2c     SCASB.RE   ES:EDI
    //         0048bb2e     NOT        this
    //         0048bb30     DEC        this
    //         0048bb31     MOV        byte ptr [this->_padding_ + EDX*0x1 + -0x4],AL
    //                               LAB_0048bb35                                                 XREF[1]:     0048bb21(j)  
    //                              scenario.cpp:552 (6)
    //         0048bb35     POP        EDI
    //         0048bb36     POP        ESI
    //         0048bb37     POP        EBX
    //         0048bb38     RET        0xc
    //         0048bb3b     ??         90h
    //         0048bb3c     NOP
    //         0048bb3d     NOP
    //         0048bb3e     NOP
    //         0048bb3f     NOP
    return;
}

void RGE_Scenario::Set_player_AI(int param_1, char* param_2, int param_3) {
    /* TODO: Stub */
    //                              void __thiscall Set_player_AI(RGE_Scenario * this, int param_1, char
    //              void              <VOID>         <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[2]:     0048bb4b(R), 0048bb77(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     0048bb41(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0048bb8c(R)  
    //                               ?Set_player_AI@RGE_Scenario@@QAEXHPADH@Z                     XREF[1]:     set_player:004aafcf(c)  
    //                               RGE_Scenario::Set_player_AI
    //                              scenario.cpp:556 (1)
    //         0048bb40     PUSH       EBX
    //                              scenario.cpp:557 (10)
    //         0048bb41     MOV        EBX,dword ptr [ESP + param_2]
    //         0048bb45     PUSH       ESI
    //         0048bb46     PUSH       EDI
    //         0048bb47     TEST       EBX,EBX
    //         0048bb49     JZ         LAB_0048bb77
    //                              scenario.cpp:558 (42)
    //         0048bb4b     MOV        EAX,dword ptr [ESP + param_1]
    //         0048bb4f     MOV        EDI,EBX
    //         0048bb51     LEA        EDX,[ECX + EAX*0x4 + this->AiRules[0]]
    //         0048bb58     OR         this,0xffffffff
    //         0048bb5b     XOR        EAX,EAX
    //         0048bb5d     SCASB.RE   ES:EDI
    //         0048bb5f     NOT        this
    //         0048bb61     SUB        EDI,this
    //         0048bb63     MOV        EAX,this
    //         0048bb65     MOV        ESI,EDI
    //         0048bb67     MOV        EDI,dword ptr [EDX]
    //         0048bb69     SHR        this,0x2
    //         0048bb6c     MOVSD.REP  ES:EDI,ESI
    //         0048bb6e     MOV        this,EAX
    //         0048bb70     AND        this,0x3
    //         0048bb73     MOVSB.REP  ES:EDI,ESI
    //                              scenario.cpp:559 (2)
    //         0048bb75     JMP        LAB_0048bb8c
    //                               LAB_0048bb77                                                 XREF[1]:     0048bb49(j)  
    //                              scenario.cpp:560 (21)
    //         0048bb77     MOV        EDX,dword ptr [ESP + param_1]
    //         0048bb7b     MOV        EAX,dword ptr [ECX + EDX*0x4 + this->AiRules[0]]
    //         0048bb82     LEA        EDX,[ECX + EDX*0x4 + this->AiRules[0]]
    //         0048bb89     MOV        byte ptr [EAX],0x0
    //                               LAB_0048bb8c                                                 XREF[1]:     0048bb75(j)  
    //                              scenario.cpp:562 (7)
    //         0048bb8c     CMP        dword ptr [ESP + param_3],0x1
    //         0048bb91     JNZ        LAB_0048bba5
    //                              scenario.cpp:563 (18)
    //         0048bb93     MOV        EDI,EBX
    //         0048bb95     OR         this,0xffffffff
    //         0048bb98     XOR        EAX,EAX
    //         0048bb9a     MOV        EDX,dword ptr [EDX]
    //         0048bb9c     SCASB.RE   ES:EDI
    //         0048bb9e     NOT        this
    //         0048bba0     DEC        this
    //         0048bba1     MOV        byte ptr [this->_padding_ + EDX*0x1 + -0x4],AL
    //                               LAB_0048bba5                                                 XREF[1]:     0048bb91(j)  
    //                              scenario.cpp:564 (6)
    //         0048bba5     POP        EDI
    //         0048bba6     POP        ESI
    //         0048bba7     POP        EBX
    //         0048bba8     RET        0xc
    //         0048bbab     ??         90h
    //         0048bbac     NOP
    //         0048bbad     NOP
    //         0048bbae     NOP
    //         0048bbaf     NOP
    return;
}

void RGE_Scenario::Set_Version(float param_1) {
    /* TODO: Stub */
    //                              void __thiscall Set_Version(RGE_Scenario * this, float param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[1]:     0048bbb0(R)  
    //                               ?Set_Version@RGE_Scenario@@QAEXM@Z
    //                               RGE_Scenario::Set_Version
    //                              scenario.cpp:568 (10)
    //         0048bbb0     MOV        EAX,dword ptr [ESP + param_1]
    //         0048bbb4     MOV        dword ptr [ECX + this->Version],EAX
    //                              scenario.cpp:570 (3)
    //         0048bbba     RET        0x4
    //         0048bbbd     ??         90h
    //         0048bbbe     NOP
    //         0048bbbf     NOP
    return;
}

void RGE_Scenario::Set_player_Type(int param_1, int param_2) {
    /* TODO: Stub */
    //                              void __thiscall Set_player_Type(RGE_Scenario * this, int param_1, in
    //              void              <VOID>         <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0048bbc0(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0048bbcd(R)  
    //                               ?Set_player_Type@RGE_Scenario@@QAEXHH@Z                      XREF[1]:     set_player:004aaf96(c)  
    //                               RGE_Scenario::Set_player_Type
    //                              scenario.cpp:574 (13)
    //         0048bbc0     MOV        EAX,dword ptr [ESP + param_1]
    //         0048bbc4     TEST       EAX,EAX
    //         0048bbc6     JL         LAB_0048bbd8
    //         0048bbc8     CMP        EAX,0x10
    //         0048bbcb     JGE        LAB_0048bbd8
    //                              scenario.cpp:576 (11)
    //         0048bbcd     MOV        EDX,dword ptr [ESP + param_2]
    //         0048bbd1     MOV        dword ptr [ECX + EAX*0x4 + this->PlType[0]],EDX
    //                               LAB_0048bbd8                                                 XREF[2]:     0048bbc6(j), 0048bbcb(j)  
    //                              scenario.cpp:577 (3)
    //         0048bbd8     RET        0x8
    //         0048bbdb     ??         90h
    //         0048bbdc     NOP
    //         0048bbdd     NOP
    //         0048bbde     NOP
    //         0048bbdf     NOP
    return;
}

void RGE_Scenario::Set_player_Civ(int param_1, int param_2) {
    /* TODO: Stub */
    //                              void __thiscall Set_player_Civ(RGE_Scenario * this, int param_1, int
    //              void              <VOID>         <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0048bbe0(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0048bbed(R)  
    //                               ?Set_player_Civ@RGE_Scenario@@QAEXHH@Z                       XREF[1]:     set_player:004aafb2(c)  
    //                               RGE_Scenario::Set_player_Civ
    //                              scenario.cpp:581 (13)
    //         0048bbe0     MOV        EAX,dword ptr [ESP + param_1]
    //         0048bbe4     TEST       EAX,EAX
    //         0048bbe6     JL         LAB_0048bbf8
    //         0048bbe8     CMP        EAX,0x10
    //         0048bbeb     JGE        LAB_0048bbf8
    //                              scenario.cpp:583 (11)
    //         0048bbed     MOV        EDX,dword ptr [ESP + param_2]
    //         0048bbf1     MOV        dword ptr [ECX + EAX*0x4 + this->PlCivilizatio
    //                               LAB_0048bbf8                                                 XREF[2]:     0048bbe6(j), 0048bbeb(j)  
    //                              scenario.cpp:584 (3)
    //         0048bbf8     RET        0x8
    //         0048bbfb     ??         90h
    //         0048bbfc     NOP
    //         0048bbfd     NOP
    //         0048bbfe     NOP
    //         0048bbff     NOP
    return;
}

void RGE_Scenario::Set_player_Active(int param_1, int param_2) {
    /* TODO: Stub */
    //                              void __thiscall Set_player_Active(RGE_Scenario * this, int param_1, 
    //              void              <VOID>         <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0048bc00(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0048bc0d(R)  
    //                               ?Set_player_Active@RGE_Scenario@@QAEXHH@Z                    XREF[3]:     set_player_active:004ab2c4(c), 
    //                               RGE_Scenario::Set_player_Active                                           SavePlayerActiveStatus:004b2c80(c)
    //                                                                                                         save_scenario:005247e6(c)  
    //                              scenario.cpp:588 (13)
    //         0048bc00     MOV        EAX,dword ptr [ESP + param_1]
    //         0048bc04     TEST       EAX,EAX
    //         0048bc06     JL         LAB_0048bc18
    //         0048bc08     CMP        EAX,0x10
    //         0048bc0b     JGE        LAB_0048bc18
    //                              scenario.cpp:590 (11)
    //         0048bc0d     MOV        EDX,dword ptr [ESP + param_2]
    //         0048bc11     MOV        dword ptr [ECX + EAX*0x4 + this->PlActive[0]],
    //                               LAB_0048bc18                                                 XREF[2]:     0048bc06(j), 0048bc0b(j)  
    //                              scenario.cpp:591 (3)
    //         0048bc18     RET        0x8
    //         0048bc1b     ??         90h
    //         0048bc1c     NOP
    //         0048bc1d     NOP
    //         0048bc1e     NOP
    //         0048bc1f     NOP
    return;
}

void RGE_Scenario::SetPlayerName(int param_1, char* param_2) {
    /* TODO: Stub */
    //                              void __thiscall SetPlayerName(RGE_Scenario * this, int param_1, char
    //              void              <VOID>         <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0048bc31(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     0048bc21(R)  
    //                               ?SetPlayerName@RGE_Scenario@@QAEXHPAD@Z                      XREF[1]:     set_player:004aaf7b(c)  
    //                               RGE_Scenario::SetPlayerName
    //                              scenario.cpp:595 (1)
    //         0048bc20     PUSH       ESI
    //                              scenario.cpp:596 (43)
    //         0048bc21     MOV        ESI,dword ptr [ESP + param_2]
    //         0048bc25     MOV        EDX,this
    //         0048bc27     PUSH       EDI
    //         0048bc28     MOV        EDI,ESI
    //         0048bc2a     OR         this,0xffffffff
    //         0048bc2d     XOR        EAX,EAX
    //         0048bc2f     SCASB.RE   ES:EDI
    //         0048bc31     MOV        EAX,dword ptr [ESP + param_1]
    //         0048bc35     SHL        EAX,0x8
    //         0048bc38     NOT        this
    //         0048bc3a     LEA        EDI,[EAX + EDX*0x1 + 0xd]
    //         0048bc3e     MOV        EDX,this
    //         0048bc40     SHR        this,0x2
    //         0048bc43     MOVSD.REP  ES:EDI,ESI
    //         0048bc45     MOV        this,EDX
    //         0048bc47     AND        this,0x3
    //         0048bc4a     MOVSB.REP  ES:EDI,ESI
    //                              scenario.cpp:597 (5)
    //         0048bc4c     POP        EDI
    //         0048bc4d     POP        ESI
    //         0048bc4e     RET        0x8
    //         0048bc51     ??         90h
    //         0048bc52     NOP
    //         0048bc53     NOP
    //         0048bc54     NOP
    //         0048bc55     NOP
    //         0048bc56     NOP
    //         0048bc57     NOP
    //         0048bc58     NOP
    //         0048bc59     NOP
    //         0048bc5a     NOP
    //         0048bc5b     NOP
    //         0048bc5c     NOP
    //         0048bc5d     NOP
    //         0048bc5e     NOP
    //         0048bc5f     NOP
    return;
}

char* RGE_Scenario::Get_scenario_name() {
    /* TODO: Stub */
    //                              char * __thiscall Get_scenario_name(RGE_Scenario * this)
    //              char *            EAX:4          <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //                               ?Get_scenario_name@RGE_Scenario@@QAEPADXZ                    XREF[5]:     command_save:004ad7b8(c), 
    //                               RGE_Scenario::Get_scenario_name                                           scenario_get_default_name:004ada82
    //                                                                                                         scenario_get_default_name:004adad7
    //                                                                                                         TRIBE_Mission_Screen:004b820f(c), 
    //                                                                                                         send_zone_score_info:005313c0(c)  
    //                              scenario.cpp:602 (6)
    //         0048bc60     MOV        EAX,dword ptr [ECX + this->scenario_name]
    //                              scenario.cpp:604 (1)
    //         0048bc66     RET
    //         0048bc67     ??         90h
    //         0048bc68     NOP
    //         0048bc69     NOP
    //         0048bc6a     NOP
    //         0048bc6b     NOP
    //         0048bc6c     NOP
    //         0048bc6d     NOP
    //         0048bc6e     NOP
    //         0048bc6f     NOP
    return 0;
}

char* RGE_Scenario::Get_description() {
    /* TODO: Stub */
    //                              char * __thiscall Get_description(RGE_Scenario * this)
    //              char *            EAX:4          <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //                               ?Get_description@RGE_Scenario@@QAEPADXZ                      XREF[4]:     RGE_Scenario_Header:0048ab3b(c), 
    //                               RGE_Scenario::Get_description                                             RGE_Scenario_Header:0048ab46(c), 
    //                                                                                                         RGE_Scenario_Header:0048ab78(c), 
    //                                                                                                         stop_video:00523cbc(c)  
    //                              scenario.cpp:608 (6)
    //         0048bc70     MOV        EAX,dword ptr [ECX + this->description]
    //                              scenario.cpp:610 (1)
    //         0048bc76     RET
    //         0048bc77     ??         90h
    //         0048bc78     NOP
    //         0048bc79     NOP
    //         0048bc7a     NOP
    //         0048bc7b     NOP
    //         0048bc7c     NOP
    //         0048bc7d     NOP
    //         0048bc7e     NOP
    //         0048bc7f     NOP
    return 0;
}

char* RGE_Scenario::Get_Cine_PreGame() {
    /* TODO: Stub */
    //                              char * __thiscall Get_Cine_PreGame(RGE_Scenario * this)
    //              char *            EAX:4          <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //                               ?Get_Cine_PreGame@RGE_Scenario@@QAEPADXZ                     XREF[1]:     set_scenario_mode:004aa366(c)  
    //                               RGE_Scenario::Get_Cine_PreGame
    //                              scenario.cpp:614 (6)
    //         0048bc80     LEA        EAX,[ECX + this->Cine_PreGame[0]]
    //                              scenario.cpp:616 (1)
    //         0048bc86     RET
    //         0048bc87     ??         90h
    //         0048bc88     NOP
    //         0048bc89     NOP
    //         0048bc8a     NOP
    //         0048bc8b     NOP
    //         0048bc8c     NOP
    //         0048bc8d     NOP
    //         0048bc8e     NOP
    //         0048bc8f     NOP
    return 0;
}

char* RGE_Scenario::Get_Cine_Victory() {
    /* TODO: Stub */
    //                              char * __thiscall Get_Cine_Victory(RGE_Scenario * this)
    //              char *            EAX:4          <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //                               ?Get_Cine_Victory@RGE_Scenario@@QAEPADXZ                     XREF[1]:     set_scenario_mode:004aa386(c)  
    //                               RGE_Scenario::Get_Cine_Victory
    //                              scenario.cpp:620 (6)
    //         0048bc90     LEA        EAX,[ECX + this->Cine_Victory[0]]
    //                              scenario.cpp:622 (1)
    //         0048bc96     RET
    //         0048bc97     ??         90h
    //         0048bc98     NOP
    //         0048bc99     NOP
    //         0048bc9a     NOP
    //         0048bc9b     NOP
    //         0048bc9c     NOP
    //         0048bc9d     NOP
    //         0048bc9e     NOP
    //         0048bc9f     NOP
    return 0;
}

char* RGE_Scenario::Get_Cine_Loss() {
    /* TODO: Stub */
    //                              char * __thiscall Get_Cine_Loss(RGE_Scenario * this)
    //              char *            EAX:4          <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //                               ?Get_Cine_Loss@RGE_Scenario@@QAEPADXZ                        XREF[1]:     set_scenario_mode:004aa3ac(c)  
    //                               RGE_Scenario::Get_Cine_Loss
    //                              scenario.cpp:626 (6)
    //         0048bca0     LEA        EAX,[ECX + this->Cine_Loss[0]]
    //                              scenario.cpp:628 (1)
    //         0048bca6     RET
    //         0048bca7     ??         90h
    //         0048bca8     NOP
    //         0048bca9     NOP
    //         0048bcaa     NOP
    //         0048bcab     NOP
    //         0048bcac     NOP
    //         0048bcad     NOP
    //         0048bcae     NOP
    //         0048bcaf     NOP
    return 0;
}

char* RGE_Scenario::Get_Mission_Bmp() {
    /* TODO: Stub */
    //                              char * __thiscall Get_Mission_Bmp(RGE_Scenario * this)
    //              char *            EAX:4          <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //                               ?Get_Mission_Bmp@RGE_Scenario@@QAEPADXZ                      XREF[3]:     set_scenario_mode:004aa3d2(c), 
    //                               RGE_Scenario::Get_Mission_Bmp                                             set_scenario_mode:004aa3f3(c), 
    //                                                                                                         set_scenario_mode:004aa40d(c)  
    //                              scenario.cpp:632 (6)
    //         0048bcb0     LEA        EAX,[ECX + this->Mission_Bmp[0]]
    //                              scenario.cpp:634 (1)
    //         0048bcb6     RET
    //         0048bcb7     ??         90h
    //         0048bcb8     NOP
    //         0048bcb9     NOP
    //         0048bcba     NOP
    //         0048bcbb     NOP
    //         0048bcbc     NOP
    //         0048bcbd     NOP
    //         0048bcbe     NOP
    //         0048bcbf     NOP
    return 0;
}

char* RGE_Scenario::Get_BuildList(int param_1, int param_2) {
    /* TODO: Stub */
    //                              char * __thiscall Get_BuildList(RGE_Scenario * this, int param_1, in
    //              char *            EAX:4          <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //              int               Stack[0x8]:4   param_2
    //              char[260]         Stack[-0x108   temp_path
    //              char[50]          Stack[-0x13c   none_str
    //              char[50]          Stack[-0x170   random_str                XREF[0,1]:   0048bcc6(*)  
    //                               ?Get_BuildList@RGE_Scenario@@QAEPADHH@Z                      XREF[12]:    set_player:004ab1d9(c), 
    //                               RGE_Scenario::Get_BuildList                                               set_player:004ab1fd(c), 
    //                                                                                                         set_player:004ab21a(c), 
    //                                                                                                         InitializeAIInformation:0052b151(c
    //                                                                                                         load_scenario1:00544586(c), 
    //                                                                                                         load_scenario2:00544856(c), 
    //                                                                                                         load_scenario3:00544b68(c), 
    //                                                                                                         load_scenario4:00544e3b(c), 
    //                                                                                                         load_scenario5:00545176(c), 
    //                                                                                                         load_scenario6:005454a6(c), 
    //                                                                                                         load_scenario7:005457d6(c), 
    //                                                                                                         load_scenario8:00545b06(c)  
    //                              scenario.cpp:640 (6)
    //         0048bcc0     SUB        ESP,0x16c
    //                              scenario.cpp:646 (32)
    //         0048bcc6     LEA        EDX=>random_str[4],[ESP]
    //         0048bcca     PUSH       EBX
    //         0048bccb     PUSH       EBP
    //         0048bccc     MOV        EBP,this
    //         0048bcce     PUSH       ESI
    //         0048bccf     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048bcd5     PUSH       EDI
    //         0048bcd6     PUSH       0x32
    //         0048bcd8     PUSH       EDX
    //         0048bcd9     MOV        EAX,dword ptr [this->_padding_]
    //                              language.dll match for 0x277b: "Random"
    //         0048bcdb     PUSH       0x277b
    //         0048bce0     OR         EBX,0xffffffff
    //         0048bce3     CALL       dword ptr [EAX + 0x20]
    //                              scenario.cpp:647 (23)
    //         0048bce6     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048bcec     LEA        EDX,[ESP + 0x44]
    //         0048bcf0     PUSH       0x32
    //         0048bcf2     PUSH       EDX=>DAT_fffffff8
    //         0048bcf3     MOV        EAX,dword ptr [this->_padding_]
    //                              language.dll match for 0x2775: " <None> "
    //         0048bcf5     PUSH       offset DAT_fffffff4
    //         0048bcfa     CALL       dword ptr [EAX + 0x20]
    //                              scenario.cpp:649 (20)
    //         0048bcfd     LEA        EAX,[ESP + 0x78]
    //         0048bd01     PUSH       EAX
    //         0048bd02     PUSH       offset DAT_fffffff8
    //         0048bd07     CALL       dword ptr [->KERNEL32.DLL::GetTempPathA]         = 0048ac50
    //         0048bd0d     TEST       EAX,EAX
    //         0048bd0f     JNZ        LAB_0048bd35
    //                              scenario.cpp:650 (36)
    //         0048bd11     MOV        EDI,s_.                                          = 2Eh
    //         0048bd16     OR         this,0xffffffff
    //         0048bd19     SCASB.RE   ES:EDI=>s_.                                      = 2Eh
    //         0048bd1b     NOT        this
    //         0048bd1d     SUB        EDI,this
    //         0048bd1f     LEA        EDX,[ESP + 0x78]
    //         0048bd23     MOV        EAX,this
    //         0048bd25     MOV        ESI,EDI
    //         0048bd27     MOV        EDI,EDX
    //         0048bd29     SHR        this,0x2
    //         0048bd2c     MOVSD.REP  ES:EDI,ESI
    //         0048bd2e     MOV        this,EAX
    //         0048bd30     AND        this,0x3
    //         0048bd33     MOVSB.REP  ES:EDI,ESI
    //                               LAB_0048bd35                                                 XREF[1]:     0048bd0f(j)  
    //                              scenario.cpp:652 (41)
    //         0048bd35     MOV        EDI,dword ptr [ESP + 0x184]
    //         0048bd3c     MOV        EAX,dword ptr [ESP + 0x180]
    //         0048bd43     CMP        EDI,0x1
    //         0048bd46     JNZ        LAB_0048bd96
    //         0048bd48     MOV        this,dword ptr [EBP + EAX*0x4 + 0x1448]
    //         0048bd4f     TEST       this,this
    //         0048bd51     JLE        LAB_0048bd96
    //         0048bd53     MOV        this,dword ptr [EBP + EAX*0x4 + 0x1388]
    //         0048bd5a     TEST       this,this
    //         0048bd5c     JZ         LAB_0048bd96
    //                              scenario.cpp:655 (28)
    //         0048bd5e     MOV        this,EAX
    //         0048bd60     LEA        EDX,[ESP + 0x78]
    //         0048bd64     PUSH       this
    //         0048bd65     LEA        ESI,[EBP + 0x1028]
    //         0048bd6b     PUSH       EDX=>DAT_fffffff8
    //         0048bd6c     PUSH       s_%stemp_buildlist%d.tmp                         = "%stemp_buildlist%d.tmp"
    //         0048bd71     PUSH       ESI=>DAT_fffffff0
    //         0048bd72     CALL       sprintf                                          undefined sprintf()
    //         0048bd77     ADD        ESP,0x10
    //                              scenario.cpp:656 (28)
    //         0048bd7a     PUSH       0x180
    //         0048bd7f     PUSH       offset DAT_fffffff8
    //         0048bd84     PUSH       ESI=>DAT_fffffff4
    //         0048bd85     CALL       __open                                           undefined __open()
    //         0048bd8a     MOV        EBX,EAX
    //         0048bd8c     MOV        EAX,dword ptr [ESP + 0x18c]
    //         0048bd93     ADD        ESP,0xc
    //                               LAB_0048bd96                                                 XREF[3]:     0048bd46(j), 0048bd51(j), 
    //                                                                                                         0048bd5c(j)  
    //                              scenario.cpp:659 (5)
    //         0048bd96     CMP        EBX,-0x1
    //         0048bd99     JZ         LAB_0048bdd0
    //                              scenario.cpp:661 (25)
    //         0048bd9b     MOV        this,dword ptr [EBP + EAX*0x4 + 0x1448]
    //         0048bda2     MOV        EDX,dword ptr [EBP + EAX*0x4 + 0x1388]
    //         0048bda9     PUSH       this
    //         0048bdaa     PUSH       EDX=>DAT_fffffff8
    //         0048bdab     PUSH       EBX=>DAT_fffffff4
    //         0048bdac     CALL       write                                            undefined write()
    //         0048bdb1     ADD        ESP,0xc
    //                              scenario.cpp:662 (9)
    //         0048bdb4     PUSH       EBX
    //         0048bdb5     CALL       close                                            undefined close()
    //         0048bdba     ADD        ESP,0x4
    //                              scenario.cpp:673 (6)
    //         0048bdbd     LEA        EAX,[EBP + 0x1028]
    //                              scenario.cpp:683 (13)
    //         0048bdc3     POP        EDI
    //         0048bdc4     POP        ESI
    //         0048bdc5     POP        EBP
    //         0048bdc6     POP        EBX
    //         0048bdc7     ADD        ESP,0x16c
    //         0048bdcd     RET        0x8
    //                               LAB_0048bdd0                                                 XREF[1]:     0048bd99(j)  
    //                              scenario.cpp:667 (126)
    //         0048bdd0     CMP        EDI,0x1
    //         0048bdd3     JNZ        LAB_0048be8c
    //         0048bdd9     MOV        EDI,dword ptr [EBP + EAX*0x4 + 0x12c8]
    //         0048bde0     LEA        ESI,[ESP + 0x44]
    //         0048bde4     MOV        EAX,EDI
    //                               LAB_0048bde6                                                 XREF[1]:     0048be08(j)  
    //         0048bde6     MOV        DL,byte ptr [EAX]
    //         0048bde8     MOV        BL,byte ptr [ESI]
    //         0048bdea     MOV        this,DL
    //         0048bdec     CMP        DL,BL
    //         0048bdee     JNZ        LAB_0048be0e
    //         0048bdf0     TEST       this,this
    //         0048bdf2     JZ         LAB_0048be0a
    //         0048bdf4     MOV        DL,byte ptr [EAX + 0x1]
    //         0048bdf7     MOV        BL,byte ptr [ESI + 0x1]
    //         0048bdfa     MOV        this,DL
    //         0048bdfc     CMP        DL,BL
    //         0048bdfe     JNZ        LAB_0048be0e
    //         0048be00     ADD        EAX,0x2
    //         0048be03     ADD        ESI,0x2
    //         0048be06     TEST       this,this
    //         0048be08     JNZ        LAB_0048bde6
    //                               LAB_0048be0a                                                 XREF[1]:     0048bdf2(j)  
    //         0048be0a     XOR        EAX,EAX
    //         0048be0c     JMP        LAB_0048be13
    //                               LAB_0048be0e                                                 XREF[2]:     0048bdee(j), 0048bdfe(j)  
    //         0048be0e     SBB        EAX,EAX
    //         0048be10     SBB        EAX,-0x1
    //                               LAB_0048be13                                                 XREF[1]:     0048be0c(j)  
    //         0048be13     TEST       EAX,EAX
    //         0048be15     JZ         LAB_0048be85
    //         0048be17     LEA        ESI,[ESP + 0x10]
    //         0048be1b     MOV        EAX,EDI
    //                               LAB_0048be1d                                                 XREF[1]:     0048be3f(j)  
    //         0048be1d     MOV        DL,byte ptr [EAX]
    //         0048be1f     MOV        BL,byte ptr [ESI]
    //         0048be21     MOV        this,DL
    //         0048be23     CMP        DL,BL
    //         0048be25     JNZ        LAB_0048be45
    //         0048be27     TEST       this,this
    //         0048be29     JZ         LAB_0048be41
    //         0048be2b     MOV        DL,byte ptr [EAX + 0x1]
    //         0048be2e     MOV        BL,byte ptr [ESI + 0x1]
    //         0048be31     MOV        this,DL
    //         0048be33     CMP        DL,BL
    //         0048be35     JNZ        LAB_0048be45
    //         0048be37     ADD        EAX,0x2
    //         0048be3a     ADD        ESI,0x2
    //         0048be3d     TEST       this,this
    //         0048be3f     JNZ        LAB_0048be1d
    //                               LAB_0048be41                                                 XREF[1]:     0048be29(j)  
    //         0048be41     XOR        EAX,EAX
    //         0048be43     JMP        LAB_0048be4a
    //                               LAB_0048be45                                                 XREF[2]:     0048be25(j), 0048be35(j)  
    //         0048be45     SBB        EAX,EAX
    //         0048be47     SBB        EAX,-0x1
    //                               LAB_0048be4a                                                 XREF[1]:     0048be43(j)  
    //         0048be4a     TEST       EAX,EAX
    //         0048be4c     JZ         LAB_0048be85
    //                              scenario.cpp:668 (36)
    //         0048be4e     MOV        EAX,[rge_base_game]                              = 00000000
    //         0048be53     PUSH       EDI
    //         0048be54     LEA        EDX,[EBP + 0x1028]
    //         0048be5a     MOV        this,dword ptr [EAX + 0xc]
    //         0048be5d     ADD        this,0x102b
    //         0048be63     PUSH       this=>DAT_fffffff8
    //         0048be64     PUSH       s_%s%s.ai                                        = "%s%s.ai"
    //         0048be69     PUSH       EDX=>DAT_fffffff0
    //         0048be6a     CALL       sprintf                                          undefined sprintf()
    //         0048be6f     ADD        ESP,0x10
    //                              scenario.cpp:673 (6)
    //         0048be72     LEA        EAX,[EBP + 0x1028]
    //                              scenario.cpp:683 (13)
    //         0048be78     POP        EDI
    //         0048be79     POP        ESI
    //         0048be7a     POP        EBP
    //         0048be7b     POP        EBX
    //         0048be7c     ADD        ESP,0x16c
    //         0048be82     RET        0x8
    //                               LAB_0048be85                                                 XREF[2]:     0048be15(j), 0048be4c(j)  
    //                              scenario.cpp:667 (7)
    //         0048be85     MOV        EAX,dword ptr [ESP + 0x180]
    //                               LAB_0048be8c                                                 XREF[1]:     0048bdd3(j)  
    //                              scenario.cpp:670 (28)
    //         0048be8c     MOV        EAX,dword ptr [EBP + EAX*0x4 + 0x12c8]
    //         0048be93     LEA        this,[EBP + 0x1028]
    //         0048be99     PUSH       EAX
    //         0048be9a     PUSH       s_%s                                             = "%s"
    //         0048be9f     PUSH       this=>DAT_fffffff4
    //         0048bea0     CALL       sprintf                                          undefined sprintf()
    //         0048bea5     ADD        ESP,0xc
    //                              scenario.cpp:673 (6)
    //         0048bea8     LEA        EAX,[EBP + 0x1028]
    //                              scenario.cpp:683 (13)
    //         0048beae     POP        EDI
    //         0048beaf     POP        ESI
    //         0048beb0     POP        EBP
    //         0048beb1     POP        EBX
    //         0048beb2     ADD        ESP,0x16c
    //         0048beb8     RET        0x8
    //         0048bebb     ??         90h
    //         0048bebc     NOP
    //         0048bebd     NOP
    //         0048bebe     NOP
    //         0048bebf     NOP
    return 0;
}

char* RGE_Scenario::Get_CityPlan(int param_1, int param_2) {
    /* TODO: Stub */
    //                              char * __thiscall Get_CityPlan(RGE_Scenario * this, int param_1, int
    //              char *            EAX:4          <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //              int               Stack[0x8]:4   param_2
    //              char[260]         Stack[-0x108   temp_path
    //              char[50]          Stack[-0x13c   none_str
    //              char[50]          Stack[-0x170   random_str                XREF[0,1]:   0048bec6(*)  
    //                               ?Get_CityPlan@RGE_Scenario@@QAEPADHH@Z                       XREF[12]:    set_player:004ab243(c), 
    //                               RGE_Scenario::Get_CityPlan                                                set_player:004ab267(c), 
    //                                                                                                         set_player:004ab284(c), 
    //                                                                                                         InitializeAIInformation:0052b146(c
    //                                                                                                         load_scenario1:0054457a(c), 
    //                                                                                                         load_scenario2:0054484a(c), 
    //                                                                                                         load_scenario3:00544b5c(c), 
    //                                                                                                         load_scenario4:00544e2f(c), 
    //                                                                                                         load_scenario5:0054516a(c), 
    //                                                                                                         load_scenario6:0054549a(c), 
    //                                                                                                         load_scenario7:005457ca(c), 
    //                                                                                                         load_scenario8:00545afa(c)  
    //                              scenario.cpp:687 (6)
    //         0048bec0     SUB        ESP,0x16c
    //                              scenario.cpp:693 (32)
    //         0048bec6     LEA        EDX=>random_str[4],[ESP]
    //         0048beca     PUSH       EBX
    //         0048becb     PUSH       EBP
    //         0048becc     MOV        EBP,this
    //         0048bece     PUSH       ESI
    //         0048becf     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048bed5     PUSH       EDI
    //         0048bed6     PUSH       0x32
    //         0048bed8     PUSH       EDX
    //         0048bed9     MOV        EAX,dword ptr [this->_padding_]
    //                              language.dll match for 0x277b: "Random"
    //         0048bedb     PUSH       0x277b
    //         0048bee0     OR         EBX,0xffffffff
    //         0048bee3     CALL       dword ptr [EAX + 0x20]
    //                              scenario.cpp:694 (23)
    //         0048bee6     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048beec     LEA        EDX,[ESP + 0x44]
    //         0048bef0     PUSH       0x32
    //         0048bef2     PUSH       EDX=>DAT_fffffff8
    //         0048bef3     MOV        EAX,dword ptr [this->_padding_]
    //                              language.dll match for 0x2775: " <None> "
    //         0048bef5     PUSH       offset DAT_fffffff4
    //         0048befa     CALL       dword ptr [EAX + 0x20]
    //                              scenario.cpp:696 (20)
    //         0048befd     LEA        EAX,[ESP + 0x78]
    //         0048bf01     PUSH       EAX
    //         0048bf02     PUSH       offset DAT_fffffff8
    //         0048bf07     CALL       dword ptr [->KERNEL32.DLL::GetTempPathA]         = 0048ac50
    //         0048bf0d     TEST       EAX,EAX
    //         0048bf0f     JNZ        LAB_0048bf35
    //                              scenario.cpp:697 (36)
    //         0048bf11     MOV        EDI,s_.                                          = 2Eh
    //         0048bf16     OR         this,0xffffffff
    //         0048bf19     SCASB.RE   ES:EDI=>s_.                                      = 2Eh
    //         0048bf1b     NOT        this
    //         0048bf1d     SUB        EDI,this
    //         0048bf1f     LEA        EDX,[ESP + 0x78]
    //         0048bf23     MOV        EAX,this
    //         0048bf25     MOV        ESI,EDI
    //         0048bf27     MOV        EDI,EDX
    //         0048bf29     SHR        this,0x2
    //         0048bf2c     MOVSD.REP  ES:EDI,ESI
    //         0048bf2e     MOV        this,EAX
    //         0048bf30     AND        this,0x3
    //         0048bf33     MOVSB.REP  ES:EDI,ESI
    //                               LAB_0048bf35                                                 XREF[1]:     0048bf0f(j)  
    //                              scenario.cpp:699 (41)
    //         0048bf35     MOV        EDI,dword ptr [ESP + 0x184]
    //         0048bf3c     MOV        EAX,dword ptr [ESP + 0x180]
    //         0048bf43     CMP        EDI,0x1
    //         0048bf46     JNZ        LAB_0048bf96
    //         0048bf48     MOV        this,dword ptr [EBP + EAX*0x4 + 0x1488]
    //         0048bf4f     TEST       this,this
    //         0048bf51     JLE        LAB_0048bf96
    //         0048bf53     MOV        this,dword ptr [EBP + EAX*0x4 + 0x13c8]
    //         0048bf5a     TEST       this,this
    //         0048bf5c     JZ         LAB_0048bf96
    //                              scenario.cpp:701 (28)
    //         0048bf5e     MOV        this,EAX
    //         0048bf60     LEA        EDX,[ESP + 0x78]
    //         0048bf64     PUSH       this
    //         0048bf65     LEA        ESI,[EBP + 0x1108]
    //         0048bf6b     PUSH       EDX=>DAT_fffffff8
    //         0048bf6c     PUSH       s_%stemp_CityPlan%d.tmp                          = "%stemp_CityPlan%d.tmp"
    //         0048bf71     PUSH       ESI=>DAT_fffffff0
    //         0048bf72     CALL       sprintf                                          undefined sprintf()
    //         0048bf77     ADD        ESP,0x10
    //                              scenario.cpp:702 (28)
    //         0048bf7a     PUSH       0x180
    //         0048bf7f     PUSH       offset DAT_fffffff8
    //         0048bf84     PUSH       ESI=>DAT_fffffff4
    //         0048bf85     CALL       __open                                           undefined __open()
    //         0048bf8a     MOV        EBX,EAX
    //         0048bf8c     MOV        EAX,dword ptr [ESP + 0x18c]
    //         0048bf93     ADD        ESP,0xc
    //                               LAB_0048bf96                                                 XREF[3]:     0048bf46(j), 0048bf51(j), 
    //                                                                                                         0048bf5c(j)  
    //                              scenario.cpp:705 (5)
    //         0048bf96     CMP        EBX,-0x1
    //         0048bf99     JZ         LAB_0048bfd0
    //                              scenario.cpp:707 (25)
    //         0048bf9b     MOV        this,dword ptr [EBP + EAX*0x4 + 0x1488]
    //         0048bfa2     MOV        EDX,dword ptr [EBP + EAX*0x4 + 0x13c8]
    //         0048bfa9     PUSH       this
    //         0048bfaa     PUSH       EDX=>DAT_fffffff8
    //         0048bfab     PUSH       EBX=>DAT_fffffff4
    //         0048bfac     CALL       write                                            undefined write()
    //         0048bfb1     ADD        ESP,0xc
    //                              scenario.cpp:708 (9)
    //         0048bfb4     PUSH       EBX
    //         0048bfb5     CALL       close                                            undefined close()
    //         0048bfba     ADD        ESP,0x4
    //                              scenario.cpp:719 (6)
    //         0048bfbd     LEA        EAX,[EBP + 0x1108]
    //                              scenario.cpp:730 (13)
    //         0048bfc3     POP        EDI
    //         0048bfc4     POP        ESI
    //         0048bfc5     POP        EBP
    //         0048bfc6     POP        EBX
    //         0048bfc7     ADD        ESP,0x16c
    //         0048bfcd     RET        0x8
    //                               LAB_0048bfd0                                                 XREF[1]:     0048bf99(j)  
    //                              scenario.cpp:713 (126)
    //         0048bfd0     CMP        EDI,0x1
    //         0048bfd3     JNZ        LAB_0048c09a
    //         0048bfd9     MOV        EDI,dword ptr [EBP + EAX*0x4 + 0x12c8]
    //         0048bfe0     LEA        ESI,[ESP + 0x44]
    //         0048bfe4     MOV        EAX,EDI
    //                               LAB_0048bfe6                                                 XREF[1]:     0048c008(j)  
    //         0048bfe6     MOV        DL,byte ptr [EAX]
    //         0048bfe8     MOV        BL,byte ptr [ESI]
    //         0048bfea     MOV        this,DL
    //         0048bfec     CMP        DL,BL
    //         0048bfee     JNZ        LAB_0048c00e
    //         0048bff0     TEST       this,this
    //         0048bff2     JZ         LAB_0048c00a
    //         0048bff4     MOV        DL,byte ptr [EAX + 0x1]
    //         0048bff7     MOV        BL,byte ptr [ESI + 0x1]
    //         0048bffa     MOV        this,DL
    //         0048bffc     CMP        DL,BL
    //         0048bffe     JNZ        LAB_0048c00e
    //         0048c000     ADD        EAX,0x2
    //         0048c003     ADD        ESI,0x2
    //         0048c006     TEST       this,this
    //         0048c008     JNZ        LAB_0048bfe6
    //                               LAB_0048c00a                                                 XREF[1]:     0048bff2(j)  
    //         0048c00a     XOR        EAX,EAX
    //         0048c00c     JMP        LAB_0048c013
    //                               LAB_0048c00e                                                 XREF[2]:     0048bfee(j), 0048bffe(j)  
    //         0048c00e     SBB        EAX,EAX
    //         0048c010     SBB        EAX,-0x1
    //                               LAB_0048c013                                                 XREF[1]:     0048c00c(j)  
    //         0048c013     TEST       EAX,EAX
    //         0048c015     JZ         LAB_0048c093
    //         0048c017     LEA        ESI,[ESP + 0x10]
    //         0048c01b     MOV        EAX,EDI
    //                               LAB_0048c01d                                                 XREF[1]:     0048c03f(j)  
    //         0048c01d     MOV        DL,byte ptr [EAX]
    //         0048c01f     MOV        BL,byte ptr [ESI]
    //         0048c021     MOV        this,DL
    //         0048c023     CMP        DL,BL
    //         0048c025     JNZ        LAB_0048c045
    //         0048c027     TEST       this,this
    //         0048c029     JZ         LAB_0048c041
    //         0048c02b     MOV        DL,byte ptr [EAX + 0x1]
    //         0048c02e     MOV        BL,byte ptr [ESI + 0x1]
    //         0048c031     MOV        this,DL
    //         0048c033     CMP        DL,BL
    //         0048c035     JNZ        LAB_0048c045
    //         0048c037     ADD        EAX,0x2
    //         0048c03a     ADD        ESI,0x2
    //         0048c03d     TEST       this,this
    //         0048c03f     JNZ        LAB_0048c01d
    //                               LAB_0048c041                                                 XREF[1]:     0048c029(j)  
    //         0048c041     XOR        EAX,EAX
    //         0048c043     JMP        LAB_0048c04a
    //                               LAB_0048c045                                                 XREF[2]:     0048c025(j), 0048c035(j)  
    //         0048c045     SBB        EAX,EAX
    //         0048c047     SBB        EAX,-0x1
    //                               LAB_0048c04a                                                 XREF[1]:     0048c043(j)  
    //         0048c04a     TEST       EAX,EAX
    //         0048c04c     JZ         LAB_0048c093
    //                              scenario.cpp:714 (50)
    //         0048c04e     MOV        EAX,dword ptr [ESP + 0x180]
    //         0048c055     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         0048c05b     MOV        this,dword ptr [EBP + EAX*0x4 + 0x1308]
    //         0048c062     MOV        EAX,dword ptr [EDX + 0xc]
    //         0048c065     ADD        EAX,0x102b
    //         0048c06a     PUSH       this
    //         0048c06b     PUSH       EAX=>DAT_fffffff8
    //         0048c06c     LEA        this,[EBP + 0x1108]
    //         0048c072     PUSH       s_%s%s.cty                                       = "%s%s.cty"
    //         0048c077     PUSH       this=>DAT_fffffff0
    //         0048c078     CALL       sprintf                                          undefined sprintf()
    //         0048c07d     ADD        ESP,0x10
    //                              scenario.cpp:719 (6)
    //         0048c080     LEA        EAX,[EBP + 0x1108]
    //                              scenario.cpp:730 (13)
    //         0048c086     POP        EDI
    //         0048c087     POP        ESI
    //         0048c088     POP        EBP
    //         0048c089     POP        EBX
    //         0048c08a     ADD        ESP,0x16c
    //         0048c090     RET        0x8
    //                               LAB_0048c093                                                 XREF[2]:     0048c015(j), 0048c04c(j)  
    //                              scenario.cpp:715 (7)
    //         0048c093     MOV        EAX,dword ptr [ESP + 0x180]
    //                               LAB_0048c09a                                                 XREF[1]:     0048bfd3(j)  
    //                              scenario.cpp:716 (28)
    //         0048c09a     MOV        EDX,dword ptr [EBP + EAX*0x4 + 0x1308]
    //         0048c0a1     LEA        EAX,[EBP + 0x1108]
    //         0048c0a7     PUSH       EDX
    //         0048c0a8     PUSH       s_%s                                             = "%s"
    //         0048c0ad     PUSH       EAX=>DAT_fffffff4
    //         0048c0ae     CALL       sprintf                                          undefined sprintf()
    //         0048c0b3     ADD        ESP,0xc
    //                              scenario.cpp:719 (6)
    //         0048c0b6     LEA        EAX,[EBP + 0x1108]
    //                              scenario.cpp:730 (13)
    //         0048c0bc     POP        EDI
    //         0048c0bd     POP        ESI
    //         0048c0be     POP        EBP
    //         0048c0bf     POP        EBX
    //         0048c0c0     ADD        ESP,0x16c
    //         0048c0c6     RET        0x8
    //         0048c0c9     ??         90h
    //         0048c0ca     NOP
    //         0048c0cb     NOP
    //         0048c0cc     NOP
    //         0048c0cd     NOP
    //         0048c0ce     NOP
    //         0048c0cf     NOP
    return 0;
}

float RGE_Scenario::Get_Version() {
    /* TODO: Stub */
    //                              float __thiscall Get_Version(RGE_Scenario * this)
    //              float             ST0:10         <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //                               ?Get_Version@RGE_Scenario@@QAEMXZ                            XREF[1]:     save:0048c40b(c)  
    //                               RGE_Scenario::Get_Version
    //                              scenario.cpp:734 (6)
    //         0048c0d0     FLD        float ptr [DAT_00572178]                         = 33h    3
    //                              scenario.cpp:736 (1)
    //         0048c0d6     RET
    //         0048c0d7     ??         90h
    //         0048c0d8     NOP
    //         0048c0d9     NOP
    //         0048c0da     NOP
    //         0048c0db     NOP
    //         0048c0dc     NOP
    //         0048c0dd     NOP
    //         0048c0de     NOP
    //         0048c0df     NOP
    return 0;
}

char* RGE_Scenario::Get_player_AI(int param_1, int param_2) {
    /* TODO: Stub */
    //                              char * __thiscall Get_player_AI(RGE_Scenario * this, int param_1, in
    //              char *            EAX:4          <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //              int               Stack[0x8]:4   param_2
    //              char[260]         Stack[-0x108   temp_path
    //              char[50]          Stack[-0x13c   none_str
    //              char[50]          Stack[-0x170   random_str                XREF[0,1]:   0048c0e6(*)  
    //                               ?Get_player_AI@RGE_Scenario@@QAEPADHH@Z                      XREF[12]:    set_player:004ab16f(c), 
    //                               RGE_Scenario::Get_player_AI                                               set_player:004ab193(c), 
    //                                                                                                         set_player:004ab1b0(c), 
    //                                                                                                         InitializeAIInformation:0052b13b(c
    //                                                                                                         load_scenario1:0054456e(c), 
    //                                                                                                         load_scenario2:0054483e(c), 
    //                                                                                                         load_scenario3:00544b50(c), 
    //                                                                                                         load_scenario4:00544e23(c), 
    //                                                                                                         load_scenario5:0054515e(c), 
    //                                                                                                         load_scenario6:0054548e(c), 
    //                                                                                                         load_scenario7:005457be(c), 
    //                                                                                                         load_scenario8:00545aee(c)  
    //                              scenario.cpp:740 (6)
    //         0048c0e0     SUB        ESP,0x16c
    //                              scenario.cpp:746 (32)
    //         0048c0e6     LEA        EDX=>random_str[4],[ESP]
    //         0048c0ea     PUSH       EBX
    //         0048c0eb     PUSH       EBP
    //         0048c0ec     MOV        EBP,this
    //         0048c0ee     PUSH       ESI
    //         0048c0ef     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048c0f5     PUSH       EDI
    //         0048c0f6     PUSH       0x32
    //         0048c0f8     PUSH       EDX
    //         0048c0f9     MOV        EAX,dword ptr [this->_padding_]
    //                              language.dll match for 0x277b: "Random"
    //         0048c0fb     PUSH       0x277b
    //         0048c100     OR         EBX,0xffffffff
    //         0048c103     CALL       dword ptr [EAX + 0x20]
    //                              scenario.cpp:747 (23)
    //         0048c106     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048c10c     LEA        EDX,[ESP + 0x44]
    //         0048c110     PUSH       0x32
    //         0048c112     PUSH       EDX=>DAT_fffffff8
    //         0048c113     MOV        EAX,dword ptr [this->_padding_]
    //                              language.dll match for 0x2775: " <None> "
    //         0048c115     PUSH       offset DAT_fffffff4
    //         0048c11a     CALL       dword ptr [EAX + 0x20]
    //                              scenario.cpp:749 (20)
    //         0048c11d     LEA        EAX,[ESP + 0x78]
    //         0048c121     PUSH       EAX
    //         0048c122     PUSH       offset DAT_fffffff8
    //         0048c127     CALL       dword ptr [->KERNEL32.DLL::GetTempPathA]         = 0048ac50
    //         0048c12d     TEST       EAX,EAX
    //         0048c12f     JNZ        LAB_0048c155
    //                              scenario.cpp:750 (36)
    //         0048c131     MOV        EDI,s_.                                          = 2Eh
    //         0048c136     OR         this,0xffffffff
    //         0048c139     SCASB.RE   ES:EDI=>s_.                                      = 2Eh
    //         0048c13b     NOT        this
    //         0048c13d     SUB        EDI,this
    //         0048c13f     LEA        EDX,[ESP + 0x78]
    //         0048c143     MOV        EAX,this
    //         0048c145     MOV        ESI,EDI
    //         0048c147     MOV        EDI,EDX
    //         0048c149     SHR        this,0x2
    //         0048c14c     MOVSD.REP  ES:EDI,ESI
    //         0048c14e     MOV        this,EAX
    //         0048c150     AND        this,0x3
    //         0048c153     MOVSB.REP  ES:EDI,ESI
    //                               LAB_0048c155                                                 XREF[1]:     0048c12f(j)  
    //                              scenario.cpp:752 (41)
    //         0048c155     MOV        EDI,dword ptr [ESP + 0x184]
    //         0048c15c     MOV        EAX,dword ptr [ESP + 0x180]
    //         0048c163     CMP        EDI,0x1
    //         0048c166     JNZ        LAB_0048c1b6
    //         0048c168     MOV        this,dword ptr [EBP + EAX*0x4 + 0x14c8]
    //         0048c16f     TEST       this,this
    //         0048c171     JLE        LAB_0048c1b6
    //         0048c173     MOV        this,dword ptr [EBP + EAX*0x4 + 0x1408]
    //         0048c17a     TEST       this,this
    //         0048c17c     JZ         LAB_0048c1b6
    //                              scenario.cpp:754 (28)
    //         0048c17e     MOV        this,EAX
    //         0048c180     LEA        EDX,[ESP + 0x78]
    //         0048c184     PUSH       this
    //         0048c185     LEA        ESI,[EBP + 0x11e8]
    //         0048c18b     PUSH       EDX=>DAT_fffffff8
    //         0048c18c     PUSH       s_%stemp_AiRules%d.tmp                           = "%stemp_AiRules%d.tmp"
    //         0048c191     PUSH       ESI=>DAT_fffffff0
    //         0048c192     CALL       sprintf                                          undefined sprintf()
    //         0048c197     ADD        ESP,0x10
    //                              scenario.cpp:755 (28)
    //         0048c19a     PUSH       0x180
    //         0048c19f     PUSH       offset DAT_fffffff8
    //         0048c1a4     PUSH       ESI=>DAT_fffffff4
    //         0048c1a5     CALL       __open                                           undefined __open()
    //         0048c1aa     MOV        EBX,EAX
    //         0048c1ac     MOV        EAX,dword ptr [ESP + 0x18c]
    //         0048c1b3     ADD        ESP,0xc
    //                               LAB_0048c1b6                                                 XREF[3]:     0048c166(j), 0048c171(j), 
    //                                                                                                         0048c17c(j)  
    //                              scenario.cpp:758 (5)
    //         0048c1b6     CMP        EBX,-0x1
    //         0048c1b9     JZ         LAB_0048c1f0
    //                              scenario.cpp:760 (25)
    //         0048c1bb     MOV        this,dword ptr [EBP + EAX*0x4 + 0x14c8]
    //         0048c1c2     MOV        EDX,dword ptr [EBP + EAX*0x4 + 0x1408]
    //         0048c1c9     PUSH       this
    //         0048c1ca     PUSH       EDX=>DAT_fffffff8
    //         0048c1cb     PUSH       EBX=>DAT_fffffff4
    //         0048c1cc     CALL       write                                            undefined write()
    //         0048c1d1     ADD        ESP,0xc
    //                              scenario.cpp:761 (9)
    //         0048c1d4     PUSH       EBX
    //         0048c1d5     CALL       close                                            undefined close()
    //         0048c1da     ADD        ESP,0x4
    //                              scenario.cpp:772 (6)
    //         0048c1dd     LEA        EAX,[EBP + 0x11e8]
    //                              scenario.cpp:783 (13)
    //         0048c1e3     POP        EDI
    //         0048c1e4     POP        ESI
    //         0048c1e5     POP        EBP
    //         0048c1e6     POP        EBX
    //         0048c1e7     ADD        ESP,0x16c
    //         0048c1ed     RET        0x8
    //                               LAB_0048c1f0                                                 XREF[1]:     0048c1b9(j)  
    //                              scenario.cpp:766 (126)
    //         0048c1f0     CMP        EDI,0x1
    //         0048c1f3     JNZ        LAB_0048c2ba
    //         0048c1f9     MOV        EDI,dword ptr [EBP + EAX*0x4 + 0x12c8]
    //         0048c200     LEA        ESI,[ESP + 0x44]
    //         0048c204     MOV        EAX,EDI
    //                               LAB_0048c206                                                 XREF[1]:     0048c228(j)  
    //         0048c206     MOV        DL,byte ptr [EAX]
    //         0048c208     MOV        BL,byte ptr [ESI]
    //         0048c20a     MOV        this,DL
    //         0048c20c     CMP        DL,BL
    //         0048c20e     JNZ        LAB_0048c22e
    //         0048c210     TEST       this,this
    //         0048c212     JZ         LAB_0048c22a
    //         0048c214     MOV        DL,byte ptr [EAX + 0x1]
    //         0048c217     MOV        BL,byte ptr [ESI + 0x1]
    //         0048c21a     MOV        this,DL
    //         0048c21c     CMP        DL,BL
    //         0048c21e     JNZ        LAB_0048c22e
    //         0048c220     ADD        EAX,0x2
    //         0048c223     ADD        ESI,0x2
    //         0048c226     TEST       this,this
    //         0048c228     JNZ        LAB_0048c206
    //                               LAB_0048c22a                                                 XREF[1]:     0048c212(j)  
    //         0048c22a     XOR        EAX,EAX
    //         0048c22c     JMP        LAB_0048c233
    //                               LAB_0048c22e                                                 XREF[2]:     0048c20e(j), 0048c21e(j)  
    //         0048c22e     SBB        EAX,EAX
    //         0048c230     SBB        EAX,-0x1
    //                               LAB_0048c233                                                 XREF[1]:     0048c22c(j)  
    //         0048c233     TEST       EAX,EAX
    //         0048c235     JZ         LAB_0048c2b3
    //         0048c237     LEA        ESI,[ESP + 0x10]
    //         0048c23b     MOV        EAX,EDI
    //                               LAB_0048c23d                                                 XREF[1]:     0048c25f(j)  
    //         0048c23d     MOV        DL,byte ptr [EAX]
    //         0048c23f     MOV        BL,byte ptr [ESI]
    //         0048c241     MOV        this,DL
    //         0048c243     CMP        DL,BL
    //         0048c245     JNZ        LAB_0048c265
    //         0048c247     TEST       this,this
    //         0048c249     JZ         LAB_0048c261
    //         0048c24b     MOV        DL,byte ptr [EAX + 0x1]
    //         0048c24e     MOV        BL,byte ptr [ESI + 0x1]
    //         0048c251     MOV        this,DL
    //         0048c253     CMP        DL,BL
    //         0048c255     JNZ        LAB_0048c265
    //         0048c257     ADD        EAX,0x2
    //         0048c25a     ADD        ESI,0x2
    //         0048c25d     TEST       this,this
    //         0048c25f     JNZ        LAB_0048c23d
    //                               LAB_0048c261                                                 XREF[1]:     0048c249(j)  
    //         0048c261     XOR        EAX,EAX
    //         0048c263     JMP        LAB_0048c26a
    //                               LAB_0048c265                                                 XREF[2]:     0048c245(j), 0048c255(j)  
    //         0048c265     SBB        EAX,EAX
    //         0048c267     SBB        EAX,-0x1
    //                               LAB_0048c26a                                                 XREF[1]:     0048c263(j)  
    //         0048c26a     TEST       EAX,EAX
    //         0048c26c     JZ         LAB_0048c2b3
    //                              scenario.cpp:767 (50)
    //         0048c26e     MOV        EAX,dword ptr [ESP + 0x180]
    //         0048c275     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         0048c27b     MOV        this,dword ptr [EBP + EAX*0x4 + 0x1348]
    //         0048c282     MOV        EAX,dword ptr [EDX + 0xc]
    //         0048c285     ADD        EAX,0x102b
    //         0048c28a     PUSH       this
    //         0048c28b     PUSH       EAX=>DAT_fffffff8
    //         0048c28c     LEA        this,[EBP + 0x11e8]
    //         0048c292     PUSH       s_%s%s.per                                       = "%s%s.per"
    //         0048c297     PUSH       this=>DAT_fffffff0
    //         0048c298     CALL       sprintf                                          undefined sprintf()
    //         0048c29d     ADD        ESP,0x10
    //                              scenario.cpp:772 (6)
    //         0048c2a0     LEA        EAX,[EBP + 0x11e8]
    //                              scenario.cpp:783 (13)
    //         0048c2a6     POP        EDI
    //         0048c2a7     POP        ESI
    //         0048c2a8     POP        EBP
    //         0048c2a9     POP        EBX
    //         0048c2aa     ADD        ESP,0x16c
    //         0048c2b0     RET        0x8
    //                               LAB_0048c2b3                                                 XREF[2]:     0048c235(j), 0048c26c(j)  
    //                              scenario.cpp:768 (7)
    //         0048c2b3     MOV        EAX,dword ptr [ESP + 0x180]
    //                               LAB_0048c2ba                                                 XREF[1]:     0048c1f3(j)  
    //                              scenario.cpp:769 (28)
    //         0048c2ba     MOV        EDX,dword ptr [EBP + EAX*0x4 + 0x1348]
    //         0048c2c1     LEA        EAX,[EBP + 0x11e8]
    //         0048c2c7     PUSH       EDX
    //         0048c2c8     PUSH       s_%s                                             = "%s"
    //         0048c2cd     PUSH       EAX=>DAT_fffffff4
    //         0048c2ce     CALL       sprintf                                          undefined sprintf()
    //         0048c2d3     ADD        ESP,0xc
    //                              scenario.cpp:772 (6)
    //         0048c2d6     LEA        EAX,[EBP + 0x11e8]
    //                              scenario.cpp:783 (13)
    //         0048c2dc     POP        EDI
    //         0048c2dd     POP        ESI
    //         0048c2de     POP        EBP
    //         0048c2df     POP        EBX
    //         0048c2e0     ADD        ESP,0x16c
    //         0048c2e6     RET        0x8
    //         0048c2e9     ??         90h
    //         0048c2ea     NOP
    //         0048c2eb     NOP
    //         0048c2ec     NOP
    //         0048c2ed     NOP
    //         0048c2ee     NOP
    //         0048c2ef     NOP
    return 0;
}

int RGE_Scenario::GetPlayerPosture(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall GetPlayerPosture(RGE_Scenario * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0048c2f0(R)  
    //                               ?GetPlayerPosture@RGE_Scenario@@QAEHH@Z                      XREF[8]:     load_scenario1:00544562(c), 
    //                               RGE_Scenario::GetPlayerPosture                                            load_scenario2:00544832(c), 
    //                                                                                                         load_scenario3:00544b44(c), 
    //                                                                                                         load_scenario4:00544e17(c), 
    //                                                                                                         load_scenario5:00545152(c), 
    //                                                                                                         load_scenario6:00545482(c), 
    //                                                                                                         load_scenario7:005457b2(c), 
    //                                                                                                         load_scenario8:00545ae2(c)  
    //                              scenario.cpp:794 (13)
    //         0048c2f0     MOV        EAX,dword ptr [ESP + param_1]
    //         0048c2f4     TEST       EAX,EAX
    //         0048c2f6     JL         switchD_0048c309::caseD_0
    //         0048c2f8     CMP        EAX,0x9
    //         0048c2fb     JGE        switchD_0048c309::caseD_0
    //                              scenario.cpp:797 (19)
    //         0048c2fd     MOV        EAX,dword ptr [ECX + EAX*0x4 + this->PlayerPos
    //         0048c304     CMP        EAX,0x5
    //         0048c307     JA         switchD_0048c309::caseD_0
    //                               switchD_0048c309::switchD
    //         0048c309     JMP        dword ptr [EAX*0x4 + switchD_0048c309::switchd   = 0048c338
    //                               switchD_0048c309::caseD_1                                    XREF[2]:     0048c309(j), 0048c344(*)  
    //                              scenario.cpp:803 (5)
    //         0048c310     MOV        EAX,0x1
    //                              scenario.cpp:820 (3)
    //         0048c315     RET        0x4
    //                               switchD_0048c309::caseD_2                                    XREF[2]:     0048c309(j), 0048c348(*)  
    //                              scenario.cpp:806 (5)
    //         0048c318     MOV        EAX,0x2
    //                              scenario.cpp:820 (3)
    //         0048c31d     RET        0x4
    //                               switchD_0048c309::caseD_3                                    XREF[2]:     0048c309(j), 0048c34c(*)  
    //                              scenario.cpp:809 (5)
    //         0048c320     MOV        EAX,0x3
    //                              scenario.cpp:820 (3)
    //         0048c325     RET        0x4
    //                               switchD_0048c309::caseD_4                                    XREF[2]:     0048c309(j), 0048c350(*)  
    //                              scenario.cpp:812 (5)
    //         0048c328     MOV        EAX,0x4
    //                              scenario.cpp:820 (3)
    //         0048c32d     RET        0x4
    //                               switchD_0048c309::caseD_5                                    XREF[2]:     0048c309(j), 0048c354(*)  
    //                              scenario.cpp:815 (5)
    //         0048c330     MOV        EAX,0x5
    //                              scenario.cpp:820 (3)
    //         0048c335     RET        0x4
    //                               switchD_0048c309::caseD_0                                    XREF[5]:     0048c2f6(j), 0048c2fb(j), 
    //                                                                                                         0048c307(j), 0048c309(j), 
    //                                                                                                         0048c340(*)  
    //                              scenario.cpp:795 (2)
    //         0048c338     XOR        EAX,EAX
    //                              scenario.cpp:820 (30)
    //         0048c33a     RET        0x4
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_0048c33d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0048c33d
    //         0048c33d     NOP
    //         0048c33e     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0048c309::switchdataD_0048c340                       XREF[1]:     GetPlayerPosture:0048c309(*)  
    //         0048c340     addr       switchD_0048c309::caseD_0
    //         0048c344     addr       switchD_0048c309::caseD_1
    //         0048c348     addr       switchD_0048c309::caseD_2
    //         0048c34c     addr       switchD_0048c309::caseD_3
    //         0048c350     addr       switchD_0048c309::caseD_4
    //         0048c354     addr       switchD_0048c309::caseD_5
    //         0048c358     ??         90h
    //         0048c359     ??         90h
    //         0048c35a     ??         90h
    //         0048c35b     ??         90h
    //         0048c35c     ??         90h
    //         0048c35d     ??         90h
    //         0048c35e     ??         90h
    //         0048c35f     ??         90h
    return 0;
}

char* RGE_Scenario::GetPlayerName(int param_1) {
    /* TODO: Stub */
    //                              char * __thiscall GetPlayerName(RGE_Scenario * this, int param_1)
    //              char *            EAX:4          <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0048c360(R)  
    //                               ?GetPlayerName@RGE_Scenario@@QAEPADH@Z                       XREF[3]:     set_player:004ab11b(c), 
    //                               RGE_Scenario::GetPlayerName                                               draw:0051b44e(c), 
    //                                                                                                         create_game:00527596(c)  
    //                              scenario.cpp:824 (11)
    //         0048c360     MOV        EAX,dword ptr [ESP + param_1]
    //         0048c364     SHL        EAX,0x8
    //         0048c367     LEA        EAX,[EAX + this->_padding_*0x1 + 0xd]
    //                              scenario.cpp:826 (3)
    //         0048c36b     RET        0x4
    //         0048c36e     ??         90h
    //         0048c36f     NOP
    return 0;
}

int RGE_Scenario::Get_player_Type(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall Get_player_Type(RGE_Scenario * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0048c370(R)  
    //                               ?Get_player_Type@RGE_Scenario@@QAEHH@Z                       XREF[8]:     any_player_count:0048cc68(c), 
    //                               RGE_Scenario::Get_player_Type                                             computer_player_count:0048cc98(c), 
    //                                                                                                         startGame:0049151f(c), 
    //                                                                                                         updateSummary:004a4376(c), 
    //                                                                                                         setupSinglePlayerPlayers:004a529a(
    //                                                                                                         fillPlayerColors:004a551c(c), 
    //                                                                                                         set_player:004ab136(c), 
    //                                                                                                         start_scenario:00526091(c)  
    //                              scenario.cpp:830 (13)
    //         0048c370     MOV        EAX,dword ptr [ESP + param_1]
    //         0048c374     TEST       EAX,EAX
    //         0048c376     JL         LAB_0048c387
    //         0048c378     CMP        EAX,0x10
    //         0048c37b     JGE        LAB_0048c387
    //                              scenario.cpp:832 (7)
    //         0048c37d     MOV        EAX,dword ptr [ECX + EAX*0x4 + this->PlType[0]]
    //                              scenario.cpp:833 (3)
    //         0048c384     RET        0x4
    //                               LAB_0048c387                                                 XREF[2]:     0048c376(j), 0048c37b(j)  
    //                              scenario.cpp:831 (2)
    //         0048c387     XOR        EAX,EAX
    //                              scenario.cpp:833 (3)
    //         0048c389     RET        0x4
    //         0048c38c     ??         90h
    //         0048c38d     NOP
    //         0048c38e     NOP
    //         0048c38f     NOP
    return 0;
}

int RGE_Scenario::Get_player_Civ(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall Get_player_Civ(RGE_Scenario * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0048c390(R)  
    //                               ?Get_player_Civ@RGE_Scenario@@QAEHH@Z                        XREF[5]:     setupSinglePlayerPlayers:004a5271(
    //                               RGE_Scenario::Get_player_Civ                                              setupSinglePlayerPlayers:004a52b6(
    //                                                                                                         set_player:004ab151(c), 
    //                                                                                                         start_scenario:00526056(c), 
    //                                                                                                         create_game:005274e7(c)  
    //                              scenario.cpp:837 (13)
    //         0048c390     MOV        EAX,dword ptr [ESP + param_1]
    //         0048c394     TEST       EAX,EAX
    //         0048c396     JL         LAB_0048c3a7
    //         0048c398     CMP        EAX,0x10
    //         0048c39b     JGE        LAB_0048c3a7
    //                              scenario.cpp:839 (7)
    //         0048c39d     MOV        EAX,dword ptr [ECX + EAX*0x4 + this->PlCiviliz
    //                              scenario.cpp:840 (3)
    //         0048c3a4     RET        0x4
    //                               LAB_0048c3a7                                                 XREF[2]:     0048c396(j), 0048c39b(j)  
    //                              scenario.cpp:838 (2)
    //         0048c3a7     XOR        EAX,EAX
    //                              scenario.cpp:840 (3)
    //         0048c3a9     RET        0x4
    //         0048c3ac     ??         90h
    //         0048c3ad     NOP
    //         0048c3ae     NOP
    //         0048c3af     NOP
    return 0;
}

int RGE_Scenario::Get_player_Active(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall Get_player_Active(RGE_Scenario * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0048c3b0(R)  
    //                               ?Get_player_Active@RGE_Scenario@@QAEHH@Z                     XREF[13]:    active_player_count:0048cc2c(c), 
    //                               RGE_Scenario::Get_player_Active                                           any_player_count:0048cc5c(c), 
    //                                                                                                         computer_player_count:0048cc8c(c), 
    //                                                                                                         startGame:004914e0(c), 
    //                                                                                                         action:004a1f38(c), 
    //                                                                                                         updateSummary:004a431e(c), 
    //                                                                                                         updateSummary:004a43cc(c), 
    //                                                                                                         setupSinglePlayerPlayers:004a5254(
    //                                                                                                         fillPlayerColors:004a54f9(c), 
    //                                                                                                         TRIBE_Screen_Sed:004a864e(c), 
    //                                                                                                         command_new_map:004ad553(c), 
    //                                                                                                         start_scenario:00526041(c), 
    //                                                                                                         any_sp_victory:0052c1ea(c)  
    //                              scenario.cpp:844 (13)
    //         0048c3b0     MOV        EAX,dword ptr [ESP + param_1]
    //         0048c3b4     TEST       EAX,EAX
    //         0048c3b6     JL         LAB_0048c3c7
    //         0048c3b8     CMP        EAX,0x10
    //         0048c3bb     JGE        LAB_0048c3c7
    //                              scenario.cpp:846 (7)
    //         0048c3bd     MOV        EAX,dword ptr [ECX + EAX*0x4 + this->PlActive[
    //                              scenario.cpp:847 (3)
    //         0048c3c4     RET        0x4
    //                               LAB_0048c3c7                                                 XREF[2]:     0048c3b6(j), 0048c3bb(j)  
    //                              scenario.cpp:845 (2)
    //         0048c3c7     XOR        EAX,EAX
    //                              scenario.cpp:847 (3)
    //         0048c3c9     RET        0x4
    //         0048c3cc     ??         90h
    //         0048c3cd     NOP
    //         0048c3ce     NOP
    //         0048c3cf     NOP
    return 0;
}

void RGE_Scenario::update() {
    /* TODO: Stub */
    //                              void __thiscall update(RGE_Scenario * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //                               ?update@RGE_Scenario@@QAEXXZ                                 XREF[1]:     update:00543040(c)  
    //                               RGE_Scenario::update
    //                              scenario.cpp:852 (7)
    //         0048c3d0     MOV        this,dword ptr [ECX + this->time_line]
    //         0048c3d3     TEST       this,this
    //         0048c3d5     JZ         LAB_0048c3dc
    //                              scenario.cpp:854 (5)
    //         0048c3d7     JMP        RGE_Timeline::update                             void update(RGE_Timeline * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
    //                               LAB_0048c3dc                                                 XREF[1]:     0048c3d5(j)  
    //                              scenario.cpp:855 (1)
    //         0048c3dc     RET
    //         0048c3dd     ??         90h
    //         0048c3de     NOP
    //         0048c3df     NOP
    return;
}

void RGE_Scenario::save(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall save(RGE_Scenario * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0048c410(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0048c78d(W), 0048c7b2(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0048cbfe(R)  
    //              char[224]         Stack[-0xf0]   file_name                 XREF[0,2]:   0048c766(*), 0048c799(*)  
    //              char[224]         Stack[-0x1d0   temp_file_name            XREF[2,6]:   0048cbe9(*), 0048cbf1(W), 0048c92a(*), 0048c946(*), 
    //                                                                                     0048c9e3(*), 0048c9ff(*), 0048ca9d(*), 0048cab8(*)  
    //              int               Stack[-0x1d4   val                       XREF[3]:     0048c407(W), 0048c8b0(R), 0048cb65(R)  
    //              undefined4        Stack[-0x1d8   local_1d8                 XREF[3]:     0048c785(W), 0048c865(W), 0048c90d(R)  
    //              undefined4        Stack[-0x1dc   local_1dc                 XREF[9]:     0048c808(W), 0048c849(R), 0048c851(W), 0048c85d(W), 
    //                                                                                     0048c8a2(R), 0048c8aa(W), 0048c911(W), 0048cbd7(R), 
    //                                                                                     0048cbdf(W)  
    //              undefined4        Stack[-0x1e0   local_1e0                 XREF[45]:    0048c4c2(W), 0048c4c8(W), 0048c4d0(*), 0048c4dd(R), 
    //                                                                                     0048c512(W), 0048c518(W), 0048c51c(*), 0048c529(R), 
    //                                                                                     0048c55c(W), 0048c562(W), 0048c566(*), 0048c573(R), 
    //                                                                                     0048c5a6(W), 0048c5ac(W), 0048c5b0(*), 0048c5bd(R), 
    //                                                                                     0048c5f0(W), 0048c5f6(W), 0048c5fa(*), 0048c607(R)  
    //              short             Stack[-0x1e4   length
    //                               ?save@RGE_Scenario@@UAEXH@Z                                  XREF[2]:     save:0052af3b(c), 00572134(*)  
    //                               RGE_Scenario::save
    //                              scenario.cpp:860 (33)
    //         0048c3e0     PUSH       -0x1
    //         0048c3e2     PUSH       FUN_0055e80e
    //         0048c3e7     MOV        EAX,FS:[0x0]
    //         0048c3ed     PUSH       EAX
    //         0048c3ee     MOV        dword ptr FS:[0x0],ESP
    //         0048c3f5     SUB        ESP,0x1d4
    //         0048c3fb     PUSH       EBX
    //         0048c3fc     PUSH       EBP
    //         0048c3fd     MOV        EBP,this
    //         0048c3ff     PUSH       ESI
    //         0048c400     PUSH       EDI
    //                              scenario.cpp:866 (15)
    //         0048c401     LEA        ESI,[EBP + 0x1888]
    //         0048c407     MOV        dword ptr [ESP + val],ESI
    //         0048c40b     CALL       RGE_Scenario::Get_Version                        float Get_Version(RGE_Scenario * this)
    //                              scenario.cpp:868 (29)
    //         0048c410     MOV        EBX,dword ptr [ESP + param_1]
    //         0048c417     PUSH       0x4
    //         0048c419     FSTP       float ptr [ESI]
    //         0048c41b     PUSH       ESI
    //         0048c41c     PUSH       EBX
    //         0048c41d     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0048c422     ADD        ESP,0xc
    //         0048c425     LEA        ESI,[EBP + 0xd]
    //         0048c428     MOV        EDI,0x10
    //                               LAB_0048c42d                                                 XREF[1]:     0048c443(j)  
    //                              scenario.cpp:871 (24)
    //         0048c42d     PUSH       0x100
    //         0048c432     PUSH       ESI
    //         0048c433     PUSH       EBX
    //         0048c434     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0048c439     ADD        ESP,0xc
    //         0048c43c     ADD        ESI,0x100
    //         0048c442     DEC        EDI
    //         0048c443     JNZ        LAB_0048c42d
    //                              scenario.cpp:1078 (131)
    //         0048c445     LEA        ESI,[EBP + 0x18cc]
    //         0048c44b     MOV        EDI,0x10
    //                               LAB_0048c450                                                 XREF[1]:     0048c490(j)  
    //         0048c450     LEA        EAX,[ESI + 0x80]
    //         0048c456     PUSH       0x4
    //         0048c458     PUSH       EAX
    //         0048c459     PUSH       EBX
    //         0048c45a     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0048c45f     ADD        ESP,0xc
    //         0048c462     PUSH       0x4
    //         0048c464     PUSH       ESI
    //         0048c465     PUSH       EBX
    //         0048c466     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0048c46b     ADD        ESP,0xc
    //         0048c46e     LEA        this,[ESI + 0x40]
    //         0048c471     PUSH       0x4
    //         0048c473     PUSH       this
    //         0048c474     PUSH       EBX
    //         0048c475     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0048c47a     ADD        ESP,0xc
    //         0048c47d     LEA        EDX,[ESI + -0x40]
    //         0048c480     PUSH       0x4
    //         0048c482     PUSH       EDX
    //         0048c483     PUSH       EBX
    //         0048c484     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0048c489     ADD        ESP,0xc
    //         0048c48c     ADD        ESI,0x4
    //         0048c48f     DEC        EDI
    //         0048c490     JNZ        LAB_0048c450
    //         0048c492     LEA        EAX,[EBP + 0xc]
    //         0048c495     PUSH       0x1
    //         0048c497     PUSH       EAX
    //         0048c498     PUSH       EBX
    //         0048c499     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0048c49e     MOV        this,dword ptr [EBP + 0x4]
    //         0048c4a1     ADD        ESP,0xc
    //         0048c4a4     TEST       this,this
    //         0048c4a6     JZ         LAB_0048c4ae
    //         0048c4a8     PUSH       EBX
    //         0048c4a9     CALL       RGE_Timeline::save                               void save(RGE_Timeline * this, int param_1)
    //                               LAB_0048c4ae                                                 XREF[1]:     0048c4a6(j)  
    //         0048c4ae     MOV        EDI,dword ptr [EBP + 0x1010]
    //         0048c4b4     TEST       EDI,EDI
    //         0048c4b6     JZ         LAB_0048c4c8
    //         0048c4b8     OR         this,0xffffffff
    //         0048c4bb     XOR        EAX,EAX
    //         0048c4bd     SCASB.RE   ES:EDI
    //         0048c4bf     NOT        this
    //         0048c4c1     DEC        this
    //         0048c4c2     MOV        dword ptr [ESP + local_1e0],this
    //         0048c4c6     JMP        LAB_0048c4d0
    //                               LAB_0048c4c8                                                 XREF[1]:     0048c4b6(j)  
    //                              scenario.cpp:888 (8)
    //         0048c4c8     MOV        dword ptr [ESP + local_1e0],0x0
    //                               LAB_0048c4d0                                                 XREF[1]:     0048c4c6(j)  
    //                              scenario.cpp:890 (13)
    //         0048c4d0     LEA        this=>local_1e0,[ESP + 0x10]
    //         0048c4d4     PUSH       0x2
    //         0048c4d6     PUSH       this
    //         0048c4d7     PUSH       EBX
    //         0048c4d8     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              scenario.cpp:892 (34)
    //         0048c4dd     MOV        EAX,dword ptr [ESP + local_1e0]
    //         0048c4e1     XOR        ESI,ESI
    //         0048c4e3     ADD        ESP,0xc
    //         0048c4e6     CMP        AX,SI
    //         0048c4e9     JLE        LAB_0048c4ff
    //         0048c4eb     MOVSX      EDX,AX
    //         0048c4ee     MOV        EAX,dword ptr [EBP + 0x1010]
    //         0048c4f4     PUSH       EDX
    //         0048c4f5     PUSH       EAX
    //         0048c4f6     PUSH       EBX
    //         0048c4f7     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0048c4fc     ADD        ESP,0xc
    //                               LAB_0048c4ff                                                 XREF[1]:     0048c4e9(j)  
    //                              scenario.cpp:895 (29)
    //         0048c4ff     MOV        EDI,dword ptr [EBP + 0x1014]
    //         0048c505     CMP        EDI,ESI
    //         0048c507     JZ         LAB_0048c518
    //         0048c509     OR         this,0xffffffff
    //         0048c50c     XOR        EAX,EAX
    //         0048c50e     SCASB.RE   ES:EDI
    //         0048c510     NOT        this
    //         0048c512     MOV        dword ptr [ESP + local_1e0],this
    //         0048c516     JMP        LAB_0048c51c
    //                               LAB_0048c518                                                 XREF[1]:     0048c507(j)  
    //         0048c518     MOV        dword ptr [ESP + local_1e0],ESI
    //                               LAB_0048c51c                                                 XREF[1]:     0048c516(j)  
    //                              scenario.cpp:896 (13)
    //         0048c51c     LEA        this=>local_1e0,[ESP + 0x10]
    //         0048c520     PUSH       0x2
    //         0048c522     PUSH       this
    //         0048c523     PUSH       EBX
    //         0048c524     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              scenario.cpp:897 (12)
    //         0048c529     MOV        EAX,dword ptr [ESP + local_1e0]
    //         0048c52d     ADD        ESP,0xc
    //         0048c530     CMP        AX,SI
    //         0048c533     JLE        LAB_0048c549
    //                              scenario.cpp:898 (20)
    //         0048c535     MOVSX      EDX,AX
    //         0048c538     MOV        EAX,dword ptr [EBP + 0x1014]
    //         0048c53e     PUSH       EDX
    //         0048c53f     PUSH       EAX
    //         0048c540     PUSH       EBX
    //         0048c541     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0048c546     ADD        ESP,0xc
    //                               LAB_0048c549                                                 XREF[1]:     0048c533(j)  
    //                              scenario.cpp:900 (29)
    //         0048c549     MOV        EDI,dword ptr [EBP + 0x1018]
    //         0048c54f     CMP        EDI,ESI
    //         0048c551     JZ         LAB_0048c562
    //         0048c553     OR         this,0xffffffff
    //         0048c556     XOR        EAX,EAX
    //         0048c558     SCASB.RE   ES:EDI
    //         0048c55a     NOT        this
    //         0048c55c     MOV        dword ptr [ESP + local_1e0],this
    //         0048c560     JMP        LAB_0048c566
    //                               LAB_0048c562                                                 XREF[1]:     0048c551(j)  
    //         0048c562     MOV        dword ptr [ESP + local_1e0],ESI
    //                               LAB_0048c566                                                 XREF[1]:     0048c560(j)  
    //                              scenario.cpp:901 (13)
    //         0048c566     LEA        this=>local_1e0,[ESP + 0x10]
    //         0048c56a     PUSH       0x2
    //         0048c56c     PUSH       this
    //         0048c56d     PUSH       EBX
    //         0048c56e     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              scenario.cpp:902 (12)
    //         0048c573     MOV        EAX,dword ptr [ESP + local_1e0]
    //         0048c577     ADD        ESP,0xc
    //         0048c57a     CMP        AX,SI
    //         0048c57d     JLE        LAB_0048c593
    //                              scenario.cpp:903 (20)
    //         0048c57f     MOVSX      EDX,AX
    //         0048c582     MOV        EAX,dword ptr [EBP + 0x1018]
    //         0048c588     PUSH       EDX
    //         0048c589     PUSH       EAX
    //         0048c58a     PUSH       EBX
    //         0048c58b     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0048c590     ADD        ESP,0xc
    //                               LAB_0048c593                                                 XREF[1]:     0048c57d(j)  
    //                              scenario.cpp:905 (29)
    //         0048c593     MOV        EDI,dword ptr [EBP + 0x101c]
    //         0048c599     CMP        EDI,ESI
    //         0048c59b     JZ         LAB_0048c5ac
    //         0048c59d     OR         this,0xffffffff
    //         0048c5a0     XOR        EAX,EAX
    //         0048c5a2     SCASB.RE   ES:EDI
    //         0048c5a4     NOT        this
    //         0048c5a6     MOV        dword ptr [ESP + local_1e0],this
    //         0048c5aa     JMP        LAB_0048c5b0
    //                               LAB_0048c5ac                                                 XREF[1]:     0048c59b(j)  
    //         0048c5ac     MOV        dword ptr [ESP + local_1e0],ESI
    //                               LAB_0048c5b0                                                 XREF[1]:     0048c5aa(j)  
    //                              scenario.cpp:906 (13)
    //         0048c5b0     LEA        this=>local_1e0,[ESP + 0x10]
    //         0048c5b4     PUSH       0x2
    //         0048c5b6     PUSH       this
    //         0048c5b7     PUSH       EBX
    //         0048c5b8     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              scenario.cpp:907 (12)
    //         0048c5bd     MOV        EAX,dword ptr [ESP + local_1e0]
    //         0048c5c1     ADD        ESP,0xc
    //         0048c5c4     CMP        AX,SI
    //         0048c5c7     JLE        LAB_0048c5dd
    //                              scenario.cpp:908 (20)
    //         0048c5c9     MOVSX      EDX,AX
    //         0048c5cc     MOV        EAX,dword ptr [EBP + 0x101c]
    //         0048c5d2     PUSH       EDX
    //         0048c5d3     PUSH       EAX
    //         0048c5d4     PUSH       EBX
    //         0048c5d5     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0048c5da     ADD        ESP,0xc
    //                               LAB_0048c5dd                                                 XREF[1]:     0048c5c7(j)  
    //                              scenario.cpp:910 (29)
    //         0048c5dd     MOV        EDI,dword ptr [EBP + 0x1020]
    //         0048c5e3     CMP        EDI,ESI
    //         0048c5e5     JZ         LAB_0048c5f6
    //         0048c5e7     OR         this,0xffffffff
    //         0048c5ea     XOR        EAX,EAX
    //         0048c5ec     SCASB.RE   ES:EDI
    //         0048c5ee     NOT        this
    //         0048c5f0     MOV        dword ptr [ESP + local_1e0],this
    //         0048c5f4     JMP        LAB_0048c5fa
    //                               LAB_0048c5f6                                                 XREF[1]:     0048c5e5(j)  
    //         0048c5f6     MOV        dword ptr [ESP + local_1e0],ESI
    //                               LAB_0048c5fa                                                 XREF[1]:     0048c5f4(j)  
    //                              scenario.cpp:911 (13)
    //         0048c5fa     LEA        this=>local_1e0,[ESP + 0x10]
    //         0048c5fe     PUSH       0x2
    //         0048c600     PUSH       this
    //         0048c601     PUSH       EBX
    //         0048c602     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              scenario.cpp:912 (12)
    //         0048c607     MOV        EAX,dword ptr [ESP + local_1e0]
    //         0048c60b     ADD        ESP,0xc
    //         0048c60e     CMP        AX,SI
    //         0048c611     JLE        LAB_0048c627
    //                              scenario.cpp:913 (20)
    //         0048c613     MOVSX      EDX,AX
    //         0048c616     MOV        EAX,dword ptr [EBP + 0x1020]
    //         0048c61c     PUSH       EDX
    //         0048c61d     PUSH       EAX
    //         0048c61e     PUSH       EBX
    //         0048c61f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0048c624     ADD        ESP,0xc
    //                               LAB_0048c627                                                 XREF[1]:     0048c611(j)  
    //                              scenario.cpp:915 (29)
    //         0048c627     MOV        EDI,dword ptr [EBP + 0x1024]
    //         0048c62d     CMP        EDI,ESI
    //         0048c62f     JZ         LAB_0048c640
    //         0048c631     OR         this,0xffffffff
    //         0048c634     XOR        EAX,EAX
    //         0048c636     SCASB.RE   ES:EDI
    //         0048c638     NOT        this
    //         0048c63a     MOV        dword ptr [ESP + local_1e0],this
    //         0048c63e     JMP        LAB_0048c644
    //                               LAB_0048c640                                                 XREF[1]:     0048c62f(j)  
    //         0048c640     MOV        dword ptr [ESP + local_1e0],ESI
    //                               LAB_0048c644                                                 XREF[1]:     0048c63e(j)  
    //                              scenario.cpp:916 (13)
    //         0048c644     LEA        this=>local_1e0,[ESP + 0x10]
    //         0048c648     PUSH       0x2
    //         0048c64a     PUSH       this
    //         0048c64b     PUSH       EBX
    //         0048c64c     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              scenario.cpp:917 (12)
    //         0048c651     MOV        EAX,dword ptr [ESP + local_1e0]
    //         0048c655     ADD        ESP,0xc
    //         0048c658     CMP        AX,SI
    //         0048c65b     JLE        LAB_0048c671
    //                              scenario.cpp:918 (20)
    //         0048c65d     MOVSX      EDX,AX
    //         0048c660     MOV        EAX,dword ptr [EBP + 0x1024]
    //         0048c666     PUSH       EDX
    //         0048c667     PUSH       EAX
    //         0048c668     PUSH       EBX
    //         0048c669     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0048c66e     ADD        ESP,0xc
    //                               LAB_0048c671                                                 XREF[1]:     0048c65b(j)  
    //                              scenario.cpp:922 (18)
    //         0048c671     LEA        ESI,[EBP + 0x1508]
    //         0048c677     OR         this,0xffffffff
    //         0048c67a     MOV        EDI,ESI
    //         0048c67c     XOR        EAX,EAX
    //         0048c67e     SCASB.RE   ES:EDI
    //         0048c680     NOT        this
    //         0048c682     DEC        this
    //                              scenario.cpp:924 (17)
    //         0048c683     PUSH       0x2
    //         0048c685     MOV        dword ptr [ESP + local_1e0],this
    //         0048c689     LEA        this=>local_1e0,[ESP + 0x14]
    //         0048c68d     PUSH       this
    //         0048c68e     PUSH       EBX
    //         0048c68f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              scenario.cpp:925 (26)
    //         0048c694     MOV        EAX,dword ptr [ESP + local_1e0]
    //         0048c698     ADD        ESP,0xc
    //         0048c69b     TEST       AX,AX
    //         0048c69e     JLE        LAB_0048c6ae
    //         0048c6a0     MOVSX      EDX,AX
    //         0048c6a3     PUSH       EDX
    //         0048c6a4     PUSH       ESI
    //         0048c6a5     PUSH       EBX
    //         0048c6a6     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0048c6ab     ADD        ESP,0xc
    //                               LAB_0048c6ae                                                 XREF[1]:     0048c69e(j)  
    //                              scenario.cpp:928 (17)
    //         0048c6ae     LEA        ESI,[EBP + 0x15e8]
    //         0048c6b4     OR         this,0xffffffff
    //         0048c6b7     MOV        EDI,ESI
    //         0048c6b9     XOR        EAX,EAX
    //         0048c6bb     SCASB.RE   ES:EDI
    //         0048c6bd     NOT        this
    //                              scenario.cpp:930 (18)
    //         0048c6bf     LEA        EAX=>local_1e0,[ESP + 0x10]
    //         0048c6c3     PUSH       0x2
    //         0048c6c5     DEC        this
    //         0048c6c6     PUSH       EAX
    //         0048c6c7     PUSH       EBX
    //         0048c6c8     MOV        dword ptr [ESP + local_1e0],this
    //         0048c6cc     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              scenario.cpp:931 (26)
    //         0048c6d1     MOV        EAX,dword ptr [ESP + local_1e0]
    //         0048c6d5     ADD        ESP,0xc
    //         0048c6d8     TEST       AX,AX
    //         0048c6db     JLE        LAB_0048c6eb
    //         0048c6dd     MOVSX      this,AX
    //         0048c6e0     PUSH       this
    //         0048c6e1     PUSH       ESI
    //         0048c6e2     PUSH       EBX
    //         0048c6e3     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0048c6e8     ADD        ESP,0xc
    //                               LAB_0048c6eb                                                 XREF[1]:     0048c6db(j)  
    //                              scenario.cpp:934 (17)
    //         0048c6eb     LEA        ESI,[EBP + 0x16c8]
    //         0048c6f1     OR         this,0xffffffff
    //         0048c6f4     MOV        EDI,ESI
    //         0048c6f6     XOR        EAX,EAX
    //         0048c6f8     SCASB.RE   ES:EDI
    //         0048c6fa     NOT        this
    //                              scenario.cpp:936 (18)
    //         0048c6fc     LEA        EDX=>local_1e0,[ESP + 0x10]
    //         0048c700     PUSH       0x2
    //         0048c702     DEC        this
    //         0048c703     PUSH       EDX
    //         0048c704     PUSH       EBX
    //         0048c705     MOV        dword ptr [ESP + local_1e0],this
    //         0048c709     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              scenario.cpp:937 (26)
    //         0048c70e     MOV        EAX,dword ptr [ESP + local_1e0]
    //         0048c712     ADD        ESP,0xc
    //         0048c715     TEST       AX,AX
    //         0048c718     JLE        LAB_0048c728
    //         0048c71a     MOVSX      EAX,AX
    //         0048c71d     PUSH       EAX
    //         0048c71e     PUSH       ESI
    //         0048c71f     PUSH       EBX
    //         0048c720     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0048c725     ADD        ESP,0xc
    //                               LAB_0048c728                                                 XREF[1]:     0048c718(j)  
    //                              scenario.cpp:939 (18)
    //         0048c728     LEA        ESI,[EBP + 0x17a8]
    //         0048c72e     OR         this,0xffffffff
    //         0048c731     MOV        EDI,ESI
    //         0048c733     XOR        EAX,EAX
    //         0048c735     SCASB.RE   ES:EDI
    //         0048c737     NOT        this
    //         0048c739     DEC        this
    //                              scenario.cpp:941 (17)
    //         0048c73a     PUSH       0x2
    //         0048c73c     MOV        dword ptr [ESP + local_1e0],this
    //         0048c740     LEA        this=>local_1e0,[ESP + 0x14]
    //         0048c744     PUSH       this
    //         0048c745     PUSH       EBX
    //         0048c746     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              scenario.cpp:942 (12)
    //         0048c74b     MOV        EAX,dword ptr [ESP + local_1e0]
    //         0048c74f     ADD        ESP,0xc
    //         0048c752     TEST       AX,AX
    //         0048c755     JLE        LAB_0048c765
    //                              scenario.cpp:943 (14)
    //         0048c757     MOVSX      EDX,AX
    //         0048c75a     PUSH       EDX
    //         0048c75b     PUSH       ESI
    //         0048c75c     PUSH       EBX
    //         0048c75d     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0048c762     ADD        ESP,0xc
    //                               LAB_0048c765                                                 XREF[1]:     0048c755(j)  
    //                              scenario.cpp:945 (22)
    //         0048c765     PUSH       ESI
    //         0048c766     LEA        EAX=>file_name[4],[ESP + 0x108]
    //         0048c76d     PUSH       s_%s.bmp                                         = "%s.bmp"
    //         0048c772     PUSH       EAX
    //         0048c773     CALL       sprintf                                          undefined sprintf()
    //         0048c778     ADD        ESP,0xc
    //                              scenario.cpp:947 (49)
    //         0048c77b     PUSH       0x20
    //         0048c77d     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0048c782     ADD        ESP,0x4
    //         0048c785     MOV        dword ptr [ESP + local_1d8],EAX
    //         0048c789     XOR        EDI,EDI
    //         0048c78b     CMP        EAX,EDI
    //         0048c78d     MOV        dword ptr [ESP + local_4],EDI
    //         0048c794     JZ         LAB_0048c7ac
    //         0048c796     PUSH       EDI
    //         0048c797     PUSH       EDI
    //         0048c798     PUSH       EDI
    //         0048c799     LEA        this=>file_name[4],[ESP + 0x110]
    //         0048c7a0     PUSH       -0x1
    //         0048c7a2     PUSH       this
    //         0048c7a3     MOV        this,EAX
    //         0048c7a5     CALL       TPicture::TPicture                               undefined TPicture(TPicture * this, char * pa
    //         0048c7aa     MOV        EDI,EAX
    //                               LAB_0048c7ac                                                 XREF[1]:     0048c794(j)  
    //                              scenario.cpp:949 (26)
    //         0048c7ac     MOV        ESI,dword ptr [EBP + 0x198c]
    //         0048c7b2     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0048c7bd     TEST       ESI,ESI
    //         0048c7bf     JZ         LAB_0048c7f0
    //         0048c7c1     CMP        dword ptr [EDI],0x0
    //         0048c7c4     JNZ        LAB_0048c7dc
    //                              scenario.cpp:956 (22)
    //         0048c7c6     TEST       EDI,EDI
    //         0048c7c8     JZ         LAB_0048c7f6
    //         0048c7ca     MOV        this,EDI
    //         0048c7cc     CALL       TPicture::~TPicture                              void ~TPicture(TPicture * this)
    //         0048c7d1     PUSH       EDI
    //         0048c7d2     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0048c7d7     ADD        ESP,0x4
    //         0048c7da     JMP        LAB_0048c7f6
    //                               LAB_0048c7dc                                                 XREF[1]:     0048c7c4(j)  
    //                              scenario.cpp:951 (4)
    //         0048c7dc     TEST       ESI,ESI
    //         0048c7de     JZ         LAB_0048c7f0
    //                              scenario.cpp:952 (16)
    //         0048c7e0     MOV        this,ESI
    //         0048c7e2     CALL       TPicture::~TPicture                              void ~TPicture(TPicture * this)
    //         0048c7e7     PUSH       ESI
    //         0048c7e8     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0048c7ed     ADD        ESP,0x4
    //                               LAB_0048c7f0                                                 XREF[2]:     0048c7bf(j), 0048c7de(j)  
    //                              scenario.cpp:953 (6)
    //         0048c7f0     MOV        dword ptr [EBP + 0x198c],EDI
    //                               LAB_0048c7f6                                                 XREF[2]:     0048c7c8(j), 0048c7da(j)  
    //                              scenario.cpp:958 (26)
    //         0048c7f6     MOV        this,dword ptr [EBP + 0x198c]
    //         0048c7fc     PUSH       EBX
    //         0048c7fd     CALL       TPicture::Save                                   void Save(TPicture * this, int param_1)
    //         0048c802     LEA        ESI,[EBP + 0x12c8]
    //         0048c808     MOV        dword ptr [ESP + local_1dc],0x10
    //                               LAB_0048c810                                                 XREF[1]:     0048c855(j)  
    //                              scenario.cpp:962 (7)
    //         0048c810     MOV        EDI,dword ptr [ESI]
    //         0048c812     OR         this,0xffffffff
    //         0048c815     XOR        EAX,EAX
    //                              scenario.cpp:963 (22)
    //         0048c817     LEA        EDX=>local_1e0,[ESP + 0x10]
    //         0048c81b     SCASB.RE   ES:EDI
    //         0048c81d     NOT        this
    //         0048c81f     PUSH       0x2
    //         0048c821     DEC        this
    //         0048c822     PUSH       EDX
    //         0048c823     PUSH       EBX
    //         0048c824     MOV        dword ptr [ESP + local_1e0],this
    //         0048c828     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              scenario.cpp:964 (12)
    //         0048c82d     MOV        EAX,dword ptr [ESP + local_1e0]
    //         0048c831     ADD        ESP,0xc
    //         0048c834     TEST       AX,AX
    //         0048c837     JLE        LAB_0048c849
    //                              scenario.cpp:965 (30)
    //         0048c839     MOV        this,dword ptr [ESI]
    //         0048c83b     MOVSX      EAX,AX
    //         0048c83e     PUSH       EAX
    //         0048c83f     PUSH       this
    //         0048c840     PUSH       EBX
    //         0048c841     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0048c846     ADD        ESP,0xc
    //                               LAB_0048c849                                                 XREF[1]:     0048c837(j)  
    //         0048c849     MOV        EAX,dword ptr [ESP + local_1dc]
    //         0048c84d     ADD        ESI,0x4
    //         0048c850     DEC        EAX
    //         0048c851     MOV        dword ptr [ESP + local_1dc],EAX
    //         0048c855     JNZ        LAB_0048c810
    //                              scenario.cpp:1078 (182)
    //         0048c857     LEA        ESI,[EBP + 0x1308]
    //         0048c85d     MOV        dword ptr [ESP + local_1dc],0x10
    //         0048c865     MOV        dword ptr [ESP + local_1d8],ESI
    //                               LAB_0048c869                                                 XREF[1]:     0048c8ae(j)  
    //         0048c869     MOV        EDI,dword ptr [ESI]
    //         0048c86b     OR         this,0xffffffff
    //         0048c86e     XOR        EAX,EAX
    //         0048c870     LEA        EDX=>local_1e0,[ESP + 0x10]
    //         0048c874     SCASB.RE   ES:EDI
    //         0048c876     NOT        this
    //         0048c878     PUSH       0x2
    //         0048c87a     DEC        this
    //         0048c87b     PUSH       EDX
    //         0048c87c     PUSH       EBX
    //         0048c87d     MOV        dword ptr [ESP + local_1e0],this
    //         0048c881     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0048c886     MOV        EAX,dword ptr [ESP + local_1e0]
    //         0048c88a     ADD        ESP,0xc
    //         0048c88d     TEST       AX,AX
    //         0048c890     JLE        LAB_0048c8a2
    //         0048c892     MOV        this,dword ptr [ESI]
    //         0048c894     MOVSX      EAX,AX
    //         0048c897     PUSH       EAX
    //         0048c898     PUSH       this
    //         0048c899     PUSH       EBX
    //         0048c89a     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0048c89f     ADD        ESP,0xc
    //                               LAB_0048c8a2                                                 XREF[1]:     0048c890(j)  
    //         0048c8a2     MOV        EAX,dword ptr [ESP + local_1dc]
    //         0048c8a6     ADD        ESI,0x4
    //         0048c8a9     DEC        EAX
    //         0048c8aa     MOV        dword ptr [ESP + local_1dc],EAX
    //         0048c8ae     JNZ        LAB_0048c869
    //         0048c8b0     MOV        EDX,dword ptr [ESP + val]
    //         0048c8b4     FLD        float ptr [EDX]
    //         0048c8b6     FCOMP      double ptr [DAT_00572170]                        = 48h    H
    //         0048c8bc     FNSTSW     AX
    //         0048c8be     TEST       AH,0x1
    //         0048c8c1     JNZ        LAB_0048c90d
    //         0048c8c3     LEA        ESI,[EBP + 0x1348]
    //         0048c8c9     MOV        EBP,0x10
    //                               LAB_0048c8ce                                                 XREF[1]:     0048c90b(j)  
    //         0048c8ce     MOV        EDI,dword ptr [ESI]
    //         0048c8d0     OR         this,0xffffffff
    //         0048c8d3     XOR        EAX,EAX
    //         0048c8d5     PUSH       0x2
    //         0048c8d7     SCASB.RE   ES:EDI
    //         0048c8d9     NOT        this
    //         0048c8db     LEA        EAX=>local_1e0,[ESP + 0x14]
    //         0048c8df     DEC        this
    //         0048c8e0     PUSH       EAX
    //         0048c8e1     PUSH       EBX
    //         0048c8e2     MOV        dword ptr [ESP + local_1e0],this
    //         0048c8e6     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0048c8eb     MOV        EAX,dword ptr [ESP + local_1e0]
    //         0048c8ef     ADD        ESP,0xc
    //         0048c8f2     TEST       AX,AX
    //         0048c8f5     JLE        LAB_0048c907
    //         0048c8f7     MOV        EDX,dword ptr [ESI]
    //         0048c8f9     MOVSX      this,AX
    //         0048c8fc     PUSH       this
    //         0048c8fd     PUSH       EDX
    //         0048c8fe     PUSH       EBX
    //         0048c8ff     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0048c904     ADD        ESP,0xc
    //                               LAB_0048c907                                                 XREF[1]:     0048c8f5(j)  
    //         0048c907     ADD        ESI,0x4
    //         0048c90a     DEC        EBP
    //         0048c90b     JNZ        LAB_0048c8ce
    //                               LAB_0048c90d                                                 XREF[1]:     0048c8c1(j)  
    //                              scenario.cpp:985 (12)
    //         0048c90d     MOV        ESI,dword ptr [ESP + local_1d8]
    //         0048c911     MOV        dword ptr [ESP + local_1dc],0x10
    //                               LAB_0048c919                                                 XREF[1]:     0048cbe3(j)  
    //                              scenario.cpp:988 (11)
    //         0048c919     MOV        EAX,dword ptr [ESI + -0x40]
    //         0048c91c     TEST       EAX,EAX
    //         0048c91e     JZ         LAB_0048c9d2
    //                              scenario.cpp:991 (34)
    //         0048c924     PUSH       EAX
    //         0048c925     MOV        EAX,[rge_base_game]                              = 00000000
    //         0048c92a     LEA        EDX=>temp_file_name[4],[ESP + 0x28]
    //         0048c92e     MOV        this,dword ptr [EAX + 0xc]
    //         0048c931     ADD        this,0x102b
    //         0048c937     PUSH       this
    //         0048c938     PUSH       s_%s%s.ai                                        = "%s%s.ai"
    //         0048c93d     PUSH       EDX
    //         0048c93e     CALL       sprintf                                          undefined sprintf()
    //         0048c943     ADD        ESP,0x10
    //                              scenario.cpp:992 (20)
    //         0048c946     LEA        EAX=>temp_file_name[4],[ESP + 0x24]
    //         0048c94a     PUSH       0x8000
    //         0048c94f     PUSH       EAX
    //         0048c950     CALL       __open                                           undefined __open()
    //         0048c955     MOV        EDI,EAX
    //         0048c957     ADD        ESP,0x8
    //                              scenario.cpp:993 (5)
    //         0048c95a     CMP        EDI,-0x1
    //         0048c95d     JLE        LAB_0048c9d2
    //                              scenario.cpp:996 (13)
    //         0048c95f     PUSH       0x2
    //         0048c961     PUSH       0x0
    //         0048c963     PUSH       EDI
    //         0048c964     CALL       lseek                                            undefined lseek()
    //         0048c969     ADD        ESP,0xc
    //                              scenario.cpp:997 (12)
    //         0048c96c     PUSH       EDI
    //         0048c96d     CALL       __tell                                           undefined __tell()
    //         0048c972     MOV        dword ptr [ESI + 0x140],EAX
    //                              scenario.cpp:1000 (13)
    //         0048c978     MOV        EAX,dword ptr [ESI + 0x80]
    //         0048c97e     ADD        ESP,0x4
    //         0048c981     TEST       EAX,EAX
    //         0048c983     JZ         LAB_0048c98e
    //                              scenario.cpp:1001 (9)
    //         0048c985     PUSH       EAX
    //         0048c986     CALL       free                                             undefined free()
    //         0048c98b     ADD        ESP,0x4
    //                               LAB_0048c98e                                                 XREF[1]:     0048c983(j)  
    //                              scenario.cpp:1002 (23)
    //         0048c98e     MOV        this,dword ptr [ESI + 0x140]
    //         0048c994     PUSH       0x1
    //         0048c996     PUSH       this
    //         0048c997     CALL       calloc                                           undefined calloc()
    //         0048c99c     ADD        ESP,0x8
    //         0048c99f     MOV        dword ptr [ESI + 0x80],EAX
    //                              scenario.cpp:1005 (10)
    //         0048c9a5     PUSH       0x0
    //         0048c9a7     PUSH       0x0
    //         0048c9a9     PUSH       EDI
    //         0048c9aa     CALL       lseek                                            undefined lseek()
    //                              scenario.cpp:1006 (26)
    //         0048c9af     MOV        EDX,dword ptr [ESI + 0x140]
    //         0048c9b5     MOV        EAX,dword ptr [ESI + 0x80]
    //         0048c9bb     ADD        ESP,0xc
    //         0048c9be     PUSH       EDX
    //         0048c9bf     PUSH       EAX
    //         0048c9c0     PUSH       EDI
    //         0048c9c1     CALL       read                                             undefined read()
    //         0048c9c6     ADD        ESP,0xc
    //                              scenario.cpp:1007 (9)
    //         0048c9c9     PUSH       EDI
    //         0048c9ca     CALL       close                                            undefined close()
    //         0048c9cf     ADD        ESP,0x4
    //                               LAB_0048c9d2                                                 XREF[2]:     0048c91e(j), 0048c95d(j)  
    //                              scenario.cpp:1012 (10)
    //         0048c9d2     MOV        EAX,dword ptr [ESI]
    //         0048c9d4     TEST       EAX,EAX
    //         0048c9d6     JZ         LAB_0048ca8b
    //                              scenario.cpp:1015 (35)
    //         0048c9dc     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048c9e2     PUSH       EAX
    //         0048c9e3     LEA        EAX=>temp_file_name[4],[ESP + 0x28]
    //         0048c9e7     MOV        EDX,dword ptr [ECX + this->victory_conquest]
    //         0048c9ea     ADD        EDX,0x102b
    //         0048c9f0     PUSH       EDX
    //         0048c9f1     PUSH       s_%s%s.cty                                       = "%s%s.cty"
    //         0048c9f6     PUSH       EAX
    //         0048c9f7     CALL       sprintf                                          undefined sprintf()
    //         0048c9fc     ADD        ESP,0x10
    //                              scenario.cpp:1016 (20)
    //         0048c9ff     LEA        this=>temp_file_name[4],[ESP + 0x24]
    //         0048ca03     PUSH       0x8000
    //         0048ca08     PUSH       this
    //         0048ca09     CALL       __open                                           undefined __open()
    //         0048ca0e     MOV        EDI,EAX
    //         0048ca10     ADD        ESP,0x8
    //                              scenario.cpp:1017 (5)
    //         0048ca13     CMP        EDI,-0x1
    //         0048ca16     JLE        LAB_0048ca8b
    //                              scenario.cpp:1020 (13)
    //         0048ca18     PUSH       0x2
    //         0048ca1a     PUSH       0x0
    //         0048ca1c     PUSH       EDI
    //         0048ca1d     CALL       lseek                                            undefined lseek()
    //         0048ca22     ADD        ESP,0xc
    //                              scenario.cpp:1021 (12)
    //         0048ca25     PUSH       EDI
    //         0048ca26     CALL       __tell                                           undefined __tell()
    //         0048ca2b     MOV        dword ptr [ESI + 0x180],EAX
    //                              scenario.cpp:1024 (13)
    //         0048ca31     MOV        EAX,dword ptr [ESI + 0xc0]
    //         0048ca37     ADD        ESP,0x4
    //         0048ca3a     TEST       EAX,EAX
    //         0048ca3c     JZ         LAB_0048ca47
    //                              scenario.cpp:1025 (9)
    //         0048ca3e     PUSH       EAX
    //         0048ca3f     CALL       free                                             undefined free()
    //         0048ca44     ADD        ESP,0x4
    //                               LAB_0048ca47                                                 XREF[1]:     0048ca3c(j)  
    //                              scenario.cpp:1026 (23)
    //         0048ca47     MOV        EDX,dword ptr [ESI + 0x180]
    //         0048ca4d     PUSH       0x1
    //         0048ca4f     PUSH       EDX
    //         0048ca50     CALL       calloc                                           undefined calloc()
    //         0048ca55     ADD        ESP,0x8
    //         0048ca58     MOV        dword ptr [ESI + 0xc0],EAX
    //                              scenario.cpp:1029 (10)
    //         0048ca5e     PUSH       0x0
    //         0048ca60     PUSH       0x0
    //         0048ca62     PUSH       EDI
    //         0048ca63     CALL       lseek                                            undefined lseek()
    //                              scenario.cpp:1030 (26)
    //         0048ca68     MOV        EAX,dword ptr [ESI + 0x180]
    //         0048ca6e     MOV        this,dword ptr [ESI + 0xc0]
    //         0048ca74     ADD        ESP,0xc
    //         0048ca77     PUSH       EAX
    //         0048ca78     PUSH       this
    //         0048ca79     PUSH       EDI
    //         0048ca7a     CALL       read                                             undefined read()
    //         0048ca7f     ADD        ESP,0xc
    //                              scenario.cpp:1031 (9)
    //         0048ca82     PUSH       EDI
    //         0048ca83     CALL       close                                            undefined close()
    //         0048ca88     ADD        ESP,0x4
    //                               LAB_0048ca8b                                                 XREF[2]:     0048c9d6(j), 0048ca16(j)  
    //                              scenario.cpp:1036 (11)
    //         0048ca8b     MOV        EAX,dword ptr [ESI + 0x40]
    //         0048ca8e     TEST       EAX,EAX
    //         0048ca90     JZ         LAB_0048cb44
    //                              scenario.cpp:1039 (34)
    //         0048ca96     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         0048ca9c     PUSH       EAX
    //         0048ca9d     LEA        this=>temp_file_name[4],[ESP + 0x28]
    //         0048caa1     MOV        EAX,dword ptr [EDX + 0xc]
    //         0048caa4     ADD        EAX,0x102b
    //         0048caa9     PUSH       EAX
    //         0048caaa     PUSH       s_%s%s.per                                       = "%s%s.per"
    //         0048caaf     PUSH       this
    //         0048cab0     CALL       sprintf                                          undefined sprintf()
    //         0048cab5     ADD        ESP,0x10
    //                              scenario.cpp:1040 (20)
    //         0048cab8     LEA        EDX=>temp_file_name[4],[ESP + 0x24]
    //         0048cabc     PUSH       0x8000
    //         0048cac1     PUSH       EDX
    //         0048cac2     CALL       __open                                           undefined __open()
    //         0048cac7     MOV        EDI,EAX
    //         0048cac9     ADD        ESP,0x8
    //                              scenario.cpp:1041 (5)
    //         0048cacc     CMP        EDI,-0x1
    //         0048cacf     JLE        LAB_0048cb44
    //                              scenario.cpp:1044 (13)
    //         0048cad1     PUSH       0x2
    //         0048cad3     PUSH       0x0
    //         0048cad5     PUSH       EDI
    //         0048cad6     CALL       lseek                                            undefined lseek()
    //         0048cadb     ADD        ESP,0xc
    //                              scenario.cpp:1045 (12)
    //         0048cade     PUSH       EDI
    //         0048cadf     CALL       __tell                                           undefined __tell()
    //         0048cae4     MOV        dword ptr [ESI + 0x1c0],EAX
    //                              scenario.cpp:1048 (13)
    //         0048caea     MOV        EAX,dword ptr [ESI + 0x100]
    //         0048caf0     ADD        ESP,0x4
    //         0048caf3     TEST       EAX,EAX
    //         0048caf5     JZ         LAB_0048cb00
    //                              scenario.cpp:1049 (9)
    //         0048caf7     PUSH       EAX
    //         0048caf8     CALL       free                                             undefined free()
    //         0048cafd     ADD        ESP,0x4
    //                               LAB_0048cb00                                                 XREF[1]:     0048caf5(j)  
    //                              scenario.cpp:1050 (23)
    //         0048cb00     MOV        EAX,dword ptr [ESI + 0x1c0]
    //         0048cb06     PUSH       0x1
    //         0048cb08     PUSH       EAX
    //         0048cb09     CALL       calloc                                           undefined calloc()
    //         0048cb0e     ADD        ESP,0x8
    //         0048cb11     MOV        dword ptr [ESI + 0x100],EAX
    //                              scenario.cpp:1053 (10)
    //         0048cb17     PUSH       0x0
    //         0048cb19     PUSH       0x0
    //         0048cb1b     PUSH       EDI
    //         0048cb1c     CALL       lseek                                            undefined lseek()
    //                              scenario.cpp:1054 (26)
    //         0048cb21     MOV        this,dword ptr [ESI + 0x1c0]
    //         0048cb27     MOV        EDX,dword ptr [ESI + 0x100]
    //         0048cb2d     ADD        ESP,0xc
    //         0048cb30     PUSH       this
    //         0048cb31     PUSH       EDX
    //         0048cb32     PUSH       EDI
    //         0048cb33     CALL       read                                             undefined read()
    //         0048cb38     ADD        ESP,0xc
    //                              scenario.cpp:1055 (15)
    //         0048cb3b     PUSH       EDI
    //         0048cb3c     CALL       close                                            undefined close()
    //         0048cb41     ADD        ESP,0x4
    //                               LAB_0048cb44                                                 XREF[2]:     0048ca90(j), 0048cacf(j)  
    //         0048cb44     LEA        EDI,[ESI + 0x140]
    //                              scenario.cpp:1060 (18)
    //         0048cb4a     PUSH       0x4
    //         0048cb4c     PUSH       EDI
    //         0048cb4d     PUSH       EBX
    //         0048cb4e     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0048cb53     ADD        ESP,0xc
    //         0048cb56     LEA        EBP,[ESI + 0x180]
    //                              scenario.cpp:1061 (9)
    //         0048cb5c     PUSH       0x4
    //         0048cb5e     PUSH       EBP
    //         0048cb5f     PUSH       EBX
    //         0048cb60     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              scenario.cpp:1062 (28)
    //         0048cb65     MOV        EAX,dword ptr [ESP + val]
    //         0048cb69     ADD        ESP,0xc
    //         0048cb6c     FLD        float ptr [EAX]
    //         0048cb6e     FCOMP      double ptr [DAT_00572170]                        = 48h    H
    //         0048cb74     FNSTSW     AX
    //         0048cb76     TEST       AH,0x1
    //         0048cb79     JNZ        LAB_0048cb8d
    //         0048cb7b     LEA        this,[ESI + 0x1c0]
    //                              scenario.cpp:1063 (12)
    //         0048cb81     PUSH       0x4
    //         0048cb83     PUSH       this
    //         0048cb84     PUSH       EBX
    //         0048cb85     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0048cb8a     ADD        ESP,0xc
    //                               LAB_0048cb8d                                                 XREF[1]:     0048cb79(j)  
    //                              scenario.cpp:1066 (10)
    //         0048cb8d     MOV        EAX,dword ptr [ESI + 0x80]
    //         0048cb93     TEST       EAX,EAX
    //         0048cb95     JZ         LAB_0048cba4
    //                              scenario.cpp:1067 (13)
    //         0048cb97     MOV        EDX,dword ptr [EDI]
    //         0048cb99     PUSH       EDX
    //         0048cb9a     PUSH       EAX
    //         0048cb9b     PUSH       EBX
    //         0048cb9c     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0048cba1     ADD        ESP,0xc
    //                               LAB_0048cba4                                                 XREF[1]:     0048cb95(j)  
    //                              scenario.cpp:1069 (10)
    //         0048cba4     MOV        EAX,dword ptr [ESI + 0xc0]
    //         0048cbaa     TEST       EAX,EAX
    //         0048cbac     JZ         LAB_0048cbbc
    //                              scenario.cpp:1070 (14)
    //         0048cbae     MOV        this,dword ptr [EBP]
    //         0048cbb1     PUSH       this
    //         0048cbb2     PUSH       EAX
    //         0048cbb3     PUSH       EBX
    //         0048cbb4     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0048cbb9     ADD        ESP,0xc
    //                               LAB_0048cbbc                                                 XREF[1]:     0048cbac(j)  
    //                              scenario.cpp:1072 (10)
    //         0048cbbc     MOV        EAX,dword ptr [ESI + 0x100]
    //         0048cbc2     TEST       EAX,EAX
    //         0048cbc4     JZ         LAB_0048cbd7
    //                              scenario.cpp:1073 (35)
    //         0048cbc6     MOV        EDX,dword ptr [ESI + 0x1c0]
    //         0048cbcc     PUSH       EDX
    //         0048cbcd     PUSH       EAX
    //         0048cbce     PUSH       EBX
    //         0048cbcf     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0048cbd4     ADD        ESP,0xc
    //                               LAB_0048cbd7                                                 XREF[1]:     0048cbc4(j)  
    //         0048cbd7     MOV        EAX,dword ptr [ESP + local_1dc]
    //         0048cbdb     ADD        ESI,0x4
    //         0048cbde     DEC        EAX
    //         0048cbdf     MOV        dword ptr [ESP + local_1dc],EAX
    //         0048cbe3     JNZ        LAB_0048c919
    //                              scenario.cpp:1077 (21)
    //         0048cbe9     LEA        EAX=>temp_file_name,[ESP + 0x20]
    //         0048cbed     PUSH       0x4
    //         0048cbef     PUSH       EAX
    //         0048cbf0     PUSH       EBX
    //         0048cbf1     MOV        dword ptr [ESP + temp_file_name[0]],0xffffff9d
    //         0048cbf9     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              scenario.cpp:1078 (30)
    //         0048cbfe     MOV        this,dword ptr [ESP + local_c]
    //         0048cc05     ADD        ESP,0xc
    //         0048cc08     MOV        dword ptr FS:[0x0],this
    //         0048cc0f     POP        EDI
    //         0048cc10     POP        ESI
    //         0048cc11     POP        EBP
    //         0048cc12     POP        EBX
    //         0048cc13     ADD        ESP,0x1e0
    //         0048cc19     RET        0x4
    //         0048cc1c     ??         90h
    //         0048cc1d     NOP
    //         0048cc1e     NOP
    //         0048cc1f     NOP
    return;
}

int RGE_Scenario::active_player_count() {
    /* TODO: Stub */
    //                              int __thiscall active_player_count(RGE_Scenario * this)
    //              int               EAX:4          <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //                               ?active_player_count@RGE_Scenario@@QAEHXZ                    XREF[4]:     command_save:004ad740(c), 
    //                               RGE_Scenario::active_player_count                                         command_save_as:004ad99e(c), 
    //                                                                                                         scenario_save_defaulted:004adb33(c
    //                                                                                                         TRIBE_Scenario_Header:0052a9d2(c)  
    //                              scenario.cpp:1084 (3)
    //         0048cc20     PUSH       EBX
    //         0048cc21     PUSH       ESI
    //         0048cc22     PUSH       EDI
    //                              scenario.cpp:1086 (4)
    //         0048cc23     XOR        EBX,EBX
    //         0048cc25     MOV        EDI,this
    //                              scenario.cpp:1088 (2)
    //         0048cc27     XOR        ESI,ESI
    //                               LAB_0048cc29                                                 XREF[1]:     0048cc3a(j)  
    //                              scenario.cpp:1090 (12)
    //         0048cc29     PUSH       ESI
    //         0048cc2a     MOV        this,EDI
    //         0048cc2c     CALL       RGE_Scenario::Get_player_Active                  int Get_player_Active(RGE_Scenario * this, in
    //         0048cc31     TEST       EAX,EAX
    //         0048cc33     JZ         LAB_0048cc36
    //                              scenario.cpp:1091 (1)
    //         0048cc35     INC        EBX
    //                               LAB_0048cc36                                                 XREF[1]:     0048cc33(j)  
    //                              scenario.cpp:1088 (6)
    //         0048cc36     INC        ESI
    //         0048cc37     CMP        ESI,0x10
    //         0048cc3a     JL         LAB_0048cc29
    //                              scenario.cpp:1095 (6)
    //         0048cc3c     POP        EDI
    //         0048cc3d     MOV        EAX,EBX
    //         0048cc3f     POP        ESI
    //         0048cc40     POP        EBX
    //         0048cc41     RET
    //         0048cc42     ??         90h
    //         0048cc43     NOP
    //         0048cc44     NOP
    //         0048cc45     NOP
    //         0048cc46     NOP
    //         0048cc47     NOP
    //         0048cc48     NOP
    //         0048cc49     NOP
    //         0048cc4a     NOP
    //         0048cc4b     NOP
    //         0048cc4c     NOP
    //         0048cc4d     NOP
    //         0048cc4e     NOP
    //         0048cc4f     NOP
    return 0;
}

int RGE_Scenario::any_player_count() {
    /* TODO: Stub */
    //                              int __thiscall any_player_count(RGE_Scenario * this)
    //              int               EAX:4          <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //                               ?any_player_count@RGE_Scenario@@QAEHXZ                       XREF[3]:     command_save:004ad77c(c), 
    //                               RGE_Scenario::any_player_count                                            command_save_as:004ad9cb(c), 
    //                                                                                                         scenario_save_defaulted:004adb5f(c
    //                              scenario.cpp:1101 (3)
    //         0048cc50     PUSH       EBX
    //         0048cc51     PUSH       ESI
    //         0048cc52     PUSH       EDI
    //                              scenario.cpp:1103 (4)
    //         0048cc53     XOR        EBX,EBX
    //         0048cc55     MOV        EDI,this
    //                              scenario.cpp:1105 (2)
    //         0048cc57     XOR        ESI,ESI
    //                               LAB_0048cc59                                                 XREF[1]:     0048cc77(j)  
    //                              scenario.cpp:1107 (12)
    //         0048cc59     PUSH       ESI
    //         0048cc5a     MOV        this,EDI
    //         0048cc5c     CALL       RGE_Scenario::Get_player_Active                  int Get_player_Active(RGE_Scenario * this, in
    //         0048cc61     TEST       EAX,EAX
    //         0048cc63     JZ         LAB_0048cc73
    //                              scenario.cpp:1109 (13)
    //         0048cc65     PUSH       ESI
    //         0048cc66     MOV        this,EDI
    //         0048cc68     CALL       RGE_Scenario::Get_player_Type                    int Get_player_Type(RGE_Scenario * this, int 
    //         0048cc6d     CMP        EAX,0x1
    //         0048cc70     JNZ        LAB_0048cc73
    //                              scenario.cpp:1110 (1)
    //         0048cc72     INC        EBX
    //                               LAB_0048cc73                                                 XREF[2]:     0048cc63(j), 0048cc70(j)  
    //                              scenario.cpp:1105 (6)
    //         0048cc73     INC        ESI
    //         0048cc74     CMP        ESI,0x10
    //         0048cc77     JL         LAB_0048cc59
    //                              scenario.cpp:1115 (6)
    //         0048cc79     POP        EDI
    //         0048cc7a     MOV        EAX,EBX
    //         0048cc7c     POP        ESI
    //         0048cc7d     POP        EBX
    //         0048cc7e     RET
    //         0048cc7f     ??         90h
    return 0;
}

int RGE_Scenario::computer_player_count() {
    /* TODO: Stub */
    //                              int __thiscall computer_player_count(RGE_Scenario * this)
    //              int               EAX:4          <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //                               ?computer_player_count@RGE_Scenario@@QAEHXZ
    //                               RGE_Scenario::computer_player_count
    //                              scenario.cpp:1121 (3)
    //         0048cc80     PUSH       EBX
    //         0048cc81     PUSH       ESI
    //         0048cc82     PUSH       EDI
    //                              scenario.cpp:1123 (4)
    //         0048cc83     XOR        EBX,EBX
    //         0048cc85     MOV        EDI,this
    //                              scenario.cpp:1125 (2)
    //         0048cc87     XOR        ESI,ESI
    //                               LAB_0048cc89                                                 XREF[1]:     0048cca6(j)  
    //                              scenario.cpp:1127 (12)
    //         0048cc89     PUSH       ESI
    //         0048cc8a     MOV        this,EDI
    //         0048cc8c     CALL       RGE_Scenario::Get_player_Active                  int Get_player_Active(RGE_Scenario * this, in
    //         0048cc91     TEST       EAX,EAX
    //         0048cc93     JZ         LAB_0048cca2
    //                              scenario.cpp:1129 (12)
    //         0048cc95     PUSH       ESI
    //         0048cc96     MOV        this,EDI
    //         0048cc98     CALL       RGE_Scenario::Get_player_Type                    int Get_player_Type(RGE_Scenario * this, int 
    //         0048cc9d     TEST       EAX,EAX
    //         0048cc9f     JNZ        LAB_0048cca2
    //                              scenario.cpp:1130 (1)
    //         0048cca1     INC        EBX
    //                               LAB_0048cca2                                                 XREF[2]:     0048cc93(j), 0048cc9f(j)  
    //                              scenario.cpp:1125 (6)
    //         0048cca2     INC        ESI
    //         0048cca3     CMP        ESI,0x10
    //         0048cca6     JL         LAB_0048cc89
    //                              scenario.cpp:1135 (6)
    //         0048cca8     POP        EDI
    //         0048cca9     MOV        EAX,EBX
    //         0048ccab     POP        ESI
    //         0048ccac     POP        EBX
    //         0048ccad     RET
    //         0048ccae     ??         90h
    //         0048ccaf     NOP
    return 0;
}

void RGE_Scenario::Set_conquest_victory(uchar param_1) {
    /* TODO: Stub */
    //                              void __thiscall Set_conquest_victory(RGE_Scenario * this, uchar para
    //              void              <VOID>         <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     0048ccb0(R)  
    //                               ?Set_conquest_victory@RGE_Scenario@@QAEXE@Z                  XREF[2]:     Set_Multi_Conquest:0052b414(c), 
    //                               RGE_Scenario::Set_conquest_victory                                        Set_Multi_Conquest:0052b428(c)  
    //                              scenario.cpp:1139 (7)
    //         0048ccb0     MOV        AL,byte ptr [ESP + param_1]
    //         0048ccb4     MOV        byte ptr [ECX + this->victory_conquest],AL
    //                              scenario.cpp:1141 (3)
    //         0048ccb7     RET        0x4
    //         0048ccba     ??         90h
    //         0048ccbb     NOP
    //         0048ccbc     NOP
    //         0048ccbd     NOP
    //         0048ccbe     NOP
    //         0048ccbf     NOP
    return;
}

uchar RGE_Scenario::Get_conquest_victory() {
    /* TODO: Stub */
    //                              uchar __thiscall Get_conquest_victory(RGE_Scenario * this)
    //              uchar             AL:1           <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //                               ?Get_conquest_victory@RGE_Scenario@@QAEEXZ                   XREF[1]:     check_game_state:0054348e(c)  
    //                               RGE_Scenario::Get_conquest_victory
    //                              scenario.cpp:1145 (3)
    //         0048ccc0     MOV        AL,byte ptr [ECX + this->victory_conquest]
    //                              scenario.cpp:1147 (1)
    //         0048ccc3     RET
    //         0048ccc4     ??         90h
    //         0048ccc5     NOP
    //         0048ccc6     NOP
    //         0048ccc7     NOP
    //         0048ccc8     NOP
    //         0048ccc9     NOP
    //         0048ccca     NOP
    //         0048cccb     NOP
    //         0048cccc     NOP
    //         0048cccd     NOP
    //         0048ccce     NOP
    //         0048cccf     NOP
    return 0;
}

void RGE_Scenario::add_description(char* param_1) {
    /* TODO: Stub */
    //                              void __thiscall add_description(RGE_Scenario * this, char * param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[2]:     0048cce0(R), 0048ccf1(R)  
    //                               ?add_description@RGE_Scenario@@QAEXPAD@Z                     XREF[1]:     new_game:0052f760(c)  
    //                               RGE_Scenario::add_description
    //                              scenario.cpp:1151 (16)
    //         0048ccd0     LEA        EAX,[ECX + this->description]
    //         0048ccd6     MOV        this,dword ptr [ECX + this->description]
    //         0048ccdc     TEST       this,this
    //         0048ccde     JNZ        LAB_0048ccf1
    //                              scenario.cpp:1153 (14)
    //         0048cce0     MOV        this,dword ptr [ESP + param_1]
    //         0048cce4     PUSH       this
    //         0048cce5     PUSH       EAX
    //         0048cce6     CALL       getstring                                        void getstring(char * * param_1, char * param
    //         0048cceb     ADD        ESP,0x8
    //                              scenario.cpp:1156 (3)
    //         0048ccee     RET        0x4
    //                               LAB_0048ccf1                                                 XREF[1]:     0048ccde(j)  
    //                              scenario.cpp:1155 (15)
    //         0048ccf1     MOV        EDX,dword ptr [ESP + param_1]
    //         0048ccf5     PUSH       EDX
    //         0048ccf6     PUSH       this
    //         0048ccf7     PUSH       EAX
    //         0048ccf8     CALL       addstring                                        void addstring(char * * param_1, char * param
    //         0048ccfd     ADD        ESP,0xc
    //                              scenario.cpp:1156 (3)
    //         0048cd00     RET        0x4
    //         0048cd03     ??         90h
    //         0048cd04     NOP
    //         0048cd05     NOP
    //         0048cd06     NOP
    //         0048cd07     NOP
    //         0048cd08     NOP
    //         0048cd09     NOP
    //         0048cd0a     NOP
    //         0048cd0b     NOP
    //         0048cd0c     NOP
    //         0048cd0d     NOP
    //         0048cd0e     NOP
    //         0048cd0f     NOP
    return;
}

void RGE_Scenario::Set_message(char* param_1, long param_2) {
    /* TODO: Stub */
    //                              void __thiscall Set_message(RGE_Scenario * this, char * param_1, lon
    //              void              <VOID>         <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0048cd13(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     0048cd53(R)  
    //                               ?Set_message@RGE_Scenario@@QAEXPADJ@Z                        XREF[3]:     Set_description:0048b957(c), 
    //                               RGE_Scenario::Set_message                                                 set_scenario_mode:004aa2ee(c), 
    //                                                                                                         action:004abfb7(c)  
    //                              scenario.cpp:1160 (3)
    //         0048cd10     PUSH       EBX
    //         0048cd11     PUSH       EBP
    //         0048cd12     PUSH       ESI
    //                              scenario.cpp:1164 (30)
    //         0048cd13     MOV        ESI,dword ptr [ESP + param_1]
    //         0048cd17     TEST       ESI,ESI
    //         0048cd19     PUSH       EDI
    //         0048cd1a     MOV        EBX,this
    //         0048cd1c     JNZ        LAB_0048cd22
    //         0048cd1e     XOR        EDI,EDI
    //         0048cd20     JMP        LAB_0048cd31
    //                               LAB_0048cd22                                                 XREF[1]:     0048cd1c(j)  
    //         0048cd22     MOV        EDI,ESI
    //         0048cd24     OR         this,0xffffffff
    //         0048cd27     XOR        EAX,EAX
    //         0048cd29     SCASB.RE   ES:EDI
    //         0048cd2b     NOT        this
    //         0048cd2d     DEC        this
    //         0048cd2e     MOV        EDI,this
    //         0048cd30     INC        EDI
    //                               LAB_0048cd31                                                 XREF[1]:     0048cd20(j)  
    //                              scenario.cpp:1165 (21)
    //         0048cd31     TEST       EDI,EDI
    //         0048cd33     JLE        LAB_0048cd44
    //         0048cd35     PUSH       0x1
    //         0048cd37     PUSH       EDI
    //         0048cd38     CALL       calloc                                           undefined calloc()
    //         0048cd3d     ADD        ESP,0x8
    //         0048cd40     MOV        EBP,EAX
    //         0048cd42     JMP        LAB_0048cd46
    //                               LAB_0048cd44                                                 XREF[1]:     0048cd33(j)  
    //         0048cd44     XOR        EBP,EBP
    //                               LAB_0048cd46                                                 XREF[1]:     0048cd42(j)  
    //                              scenario.cpp:1166 (13)
    //         0048cd46     MOV        this,EDI
    //         0048cd48     MOV        EDI,EBP
    //         0048cd4a     MOV        EAX,this
    //         0048cd4c     SHR        this,0x2
    //         0048cd4f     MOVSD.REP  ES:EDI,ESI
    //         0048cd51     MOV        this,EAX
    //                              scenario.cpp:1168 (25)
    //         0048cd53     MOV        EAX,dword ptr [ESP + param_2]
    //         0048cd57     AND        this,0x3
    //         0048cd5a     CMP        EAX,0x4
    //         0048cd5d     MOVSB.REP  ES:EDI,ESI
    //         0048cd5f     JA         switchD_0048cd65::default
    //                               switchD_0048cd65::switchD
    //         0048cd65     JMP        dword ptr [EAX*0x4 + switchD_0048cd65::switchd   = 0048cd6c
    //                               switchD_0048cd65::caseD_0                                    XREF[2]:     0048cd65(j), 0048ce24(*)  
    //                              scenario.cpp:1171 (10)
    //         0048cd6c     MOV        EAX,dword ptr [EBX + 0x1014]
    //         0048cd72     TEST       EAX,EAX
    //         0048cd74     JZ         LAB_0048cd7f
    //                              scenario.cpp:1172 (9)
    //         0048cd76     PUSH       EAX
    //         0048cd77     CALL       free                                             undefined free()
    //         0048cd7c     ADD        ESP,0x4
    //                               LAB_0048cd7f                                                 XREF[1]:     0048cd74(j)  
    //                              scenario.cpp:1173 (6)
    //         0048cd7f     MOV        dword ptr [EBX + 0x1014],EBP
    //                              scenario.cpp:1199 (7)
    //         0048cd85     POP        EDI
    //         0048cd86     POP        ESI
    //         0048cd87     POP        EBP
    //         0048cd88     POP        EBX
    //         0048cd89     RET        0x8
    //                               switchD_0048cd65::caseD_1                                    XREF[2]:     0048cd65(j), 0048ce28(*)  
    //                              scenario.cpp:1176 (10)
    //         0048cd8c     MOV        EAX,dword ptr [EBX + 0x1018]
    //         0048cd92     TEST       EAX,EAX
    //         0048cd94     JZ         LAB_0048cd9f
    //                              scenario.cpp:1177 (9)
    //         0048cd96     PUSH       EAX
    //         0048cd97     CALL       free                                             undefined free()
    //         0048cd9c     ADD        ESP,0x4
    //                               LAB_0048cd9f                                                 XREF[1]:     0048cd94(j)  
    //                              scenario.cpp:1178 (6)
    //         0048cd9f     MOV        dword ptr [EBX + 0x1018],EBP
    //                              scenario.cpp:1199 (7)
    //         0048cda5     POP        EDI
    //         0048cda6     POP        ESI
    //         0048cda7     POP        EBP
    //         0048cda8     POP        EBX
    //         0048cda9     RET        0x8
    //                               switchD_0048cd65::caseD_2                                    XREF[2]:     0048cd65(j), 0048ce2c(*)  
    //                              scenario.cpp:1181 (10)
    //         0048cdac     MOV        EAX,dword ptr [EBX + 0x101c]
    //         0048cdb2     TEST       EAX,EAX
    //         0048cdb4     JNZ        LAB_0048cdc0
    //                              scenario.cpp:1182 (10)
    //         0048cdb6     PUSH       0x0
    //         0048cdb8     CALL       free                                             undefined free()
    //         0048cdbd     ADD        ESP,0x4
    //                               LAB_0048cdc0                                                 XREF[1]:     0048cdb4(j)  
    //                              scenario.cpp:1183 (6)
    //         0048cdc0     MOV        dword ptr [EBX + 0x101c],EBP
    //                              scenario.cpp:1199 (7)
    //         0048cdc6     POP        EDI
    //         0048cdc7     POP        ESI
    //         0048cdc8     POP        EBP
    //         0048cdc9     POP        EBX
    //         0048cdca     RET        0x8
    //                               switchD_0048cd65::caseD_3                                    XREF[2]:     0048cd65(j), 0048ce30(*)  
    //                              scenario.cpp:1186 (10)
    //         0048cdcd     MOV        EAX,dword ptr [EBX + 0x1020]
    //         0048cdd3     TEST       EAX,EAX
    //         0048cdd5     JZ         LAB_0048cde0
    //                              scenario.cpp:1187 (9)
    //         0048cdd7     PUSH       EAX
    //         0048cdd8     CALL       free                                             undefined free()
    //         0048cddd     ADD        ESP,0x4
    //                               LAB_0048cde0                                                 XREF[1]:     0048cdd5(j)  
    //                              scenario.cpp:1188 (6)
    //         0048cde0     MOV        dword ptr [EBX + 0x1020],EBP
    //                              scenario.cpp:1199 (7)
    //         0048cde6     POP        EDI
    //         0048cde7     POP        ESI
    //         0048cde8     POP        EBP
    //         0048cde9     POP        EBX
    //         0048cdea     RET        0x8
    //                               switchD_0048cd65::caseD_4                                    XREF[2]:     0048cd65(j), 0048ce34(*)  
    //                              scenario.cpp:1191 (10)
    //         0048cded     MOV        EAX,dword ptr [EBX + 0x1024]
    //         0048cdf3     TEST       EAX,EAX
    //         0048cdf5     JZ         LAB_0048ce00
    //                              scenario.cpp:1192 (9)
    //         0048cdf7     PUSH       EAX
    //         0048cdf8     CALL       free                                             undefined free()
    //         0048cdfd     ADD        ESP,0x4
    //                               LAB_0048ce00                                                 XREF[1]:     0048cdf5(j)  
    //                              scenario.cpp:1193 (6)
    //         0048ce00     MOV        dword ptr [EBX + 0x1024],EBP
    //                              scenario.cpp:1199 (7)
    //         0048ce06     POP        EDI
    //         0048ce07     POP        ESI
    //         0048ce08     POP        EBP
    //         0048ce09     POP        EBX
    //         0048ce0a     RET        0x8
    //                               switchD_0048cd65::default                                    XREF[1]:     0048cd5f(j)  
    //                              scenario.cpp:1196 (4)
    //         0048ce0d     TEST       EBP,EBP
    //         0048ce0f     JZ         LAB_0048ce1a
    //                              scenario.cpp:1197 (9)
    //         0048ce11     PUSH       EBP
    //         0048ce12     CALL       free                                             undefined free()
    //         0048ce17     ADD        ESP,0x4
    //                               LAB_0048ce1a                                                 XREF[1]:     0048ce0f(j)  
    //                              scenario.cpp:1199 (30)
    //         0048ce1a     POP        EDI
    //         0048ce1b     POP        ESI
    //         0048ce1c     POP        EBP
    //         0048ce1d     POP        EBX
    //         0048ce1e     RET        0x8
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_0048ce21()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0048ce21
    //         0048ce21     NOP
    //         0048ce22     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0048cd65::switchdataD_0048ce24                       XREF[1]:     Set_message:0048cd65(*)  
    //         0048ce24     addr       switchD_0048cd65::caseD_0
    //         0048ce28     addr       switchD_0048cd65::caseD_1
    //         0048ce2c     addr       switchD_0048cd65::caseD_2
    //         0048ce30     addr       switchD_0048cd65::caseD_3
    //         0048ce34     addr       switchD_0048cd65::caseD_4
    //         0048ce38     ??         90h
    //         0048ce39     ??         90h
    //         0048ce3a     ??         90h
    //         0048ce3b     ??         90h
    //         0048ce3c     ??         90h
    //         0048ce3d     ??         90h
    //         0048ce3e     ??         90h
    //         0048ce3f     ??         90h
    return;
}

char* RGE_Scenario::Get_message(long param_1) {
    /* TODO: Stub */
    //                              char * __thiscall Get_message(RGE_Scenario * this, long param_1)
    //              char *            EAX:4          <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     0048ce40(R)  
    //                               ?Get_message@RGE_Scenario@@QAEPADJ@Z                         XREF[12]:    TribeAchievementsScreen:0048d8a9(c
    //                               RGE_Scenario::Get_message                                                 set_scenario_mode:004aa24c(c), 
    //                                                                                                         action:004abfe9(c), 
    //                                                                                                         TRIBE_Mission_Screen:004b861b(c), 
    //                                                                                                         TRIBE_Mission_Screen:004b863d(c), 
    //                                                                                                         TRIBE_Mission_Screen:004b8677(c), 
    //                                                                                                         TRIBE_Mission_Screen:004b86a1(c), 
    //                                                                                                         TRIBE_Mission_Screen:004b86da(c), 
    //                                                                                                         TRIBE_Mission_Screen:004b8704(c), 
    //                                                                                                         action:004b89d8(c), 
    //                                                                                                         action:004b8a0b(c), 
    //                                                                                                         action:004b8a3e(c)  
    //                              scenario.cpp:1203 (16)
    //         0048ce40     MOV        EAX,dword ptr [ESP + param_1]
    //         0048ce44     CMP        EAX,0x4
    //         0048ce47     JA         switchD_0048ce49::default
    //                               switchD_0048ce49::switchD
    //         0048ce49     JMP        dword ptr [EAX*0x4 + switchD_0048ce49::switchd   = 0048ce50
    //                               switchD_0048ce49::caseD_0                                    XREF[2]:     0048ce49(j), 0048ce84(*)  
    //                              scenario.cpp:1207 (6)
    //         0048ce50     MOV        EAX,dword ptr [ECX + this->description]
    //                              scenario.cpp:1223 (3)
    //         0048ce56     RET        0x4
    //                               switchD_0048ce49::caseD_1                                    XREF[2]:     0048ce49(j), 0048ce88(*)  
    //                              scenario.cpp:1210 (6)
    //         0048ce59     MOV        EAX,dword ptr [ECX + this->hints]
    //                              scenario.cpp:1223 (3)
    //         0048ce5f     RET        0x4
    //                               switchD_0048ce49::caseD_2                                    XREF[2]:     0048ce49(j), 0048ce8c(*)  
    //                              scenario.cpp:1213 (6)
    //         0048ce62     MOV        EAX,dword ptr [ECX + this->win_message]
    //                              scenario.cpp:1223 (3)
    //         0048ce68     RET        0x4
    //                               switchD_0048ce49::caseD_3                                    XREF[2]:     0048ce49(j), 0048ce90(*)  
    //                              scenario.cpp:1216 (6)
    //         0048ce6b     MOV        EAX,dword ptr [ECX + this->loss_message]
    //                              scenario.cpp:1223 (3)
    //         0048ce71     RET        0x4
    //                               switchD_0048ce49::caseD_4                                    XREF[2]:     0048ce49(j), 0048ce94(*)  
    //                              scenario.cpp:1219 (6)
    //         0048ce74     MOV        EAX,dword ptr [ECX + this->historicle_notes]
    //                              scenario.cpp:1223 (3)
    //         0048ce7a     RET        0x4
    //                               switchD_0048ce49::default                                    XREF[1]:     0048ce47(j)  
    //                              scenario.cpp:1222 (2)
    //         0048ce7d     XOR        EAX,EAX
    //                              scenario.cpp:1223 (25)
    //         0048ce7f     RET        0x4
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_0048ce82()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0048ce82
    //         0048ce82     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0048ce49::switchdataD_0048ce84                       XREF[1]:     Get_message:0048ce49(*)  
    //         0048ce84     addr       switchD_0048ce49::caseD_0
    //         0048ce88     addr       switchD_0048ce49::caseD_1
    //         0048ce8c     addr       switchD_0048ce49::caseD_2
    //         0048ce90     addr       switchD_0048ce49::caseD_3
    //         0048ce94     addr       switchD_0048ce49::caseD_4
    //         0048ce98     ??         90h
    //         0048ce99     ??         90h
    //         0048ce9a     ??         90h
    //         0048ce9b     ??         90h
    //         0048ce9c     ??         90h
    //         0048ce9d     ??         90h
    //         0048ce9e     ??         90h
    //         0048ce9f     ??         90h
    return 0;
}

