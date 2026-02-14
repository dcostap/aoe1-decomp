// Auto-generated scaffold unit: timeline.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/Timeline.cpp
#include "../include/common.h"

// Offset: 0x0050D5B0
undefined RGE_Timeline(RGE_Timeline* this_, int param_2, RGE_Game_World* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Timeline::RGE_Timeline(int,class RGE_Game_World *)                             *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Timeline(RGE_Timeline * this, int param_1, 
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Timeline *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[4]:     0050d5b8(R), 0050d6b0(*), 0050d6dc(R), 0050d72c(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[4]:     0050d5f4(R), 0050d60b(W), 0050d74c(R), 0050d757(W)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0050d5cd(W), 0050d750(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     0050d60f(W), 0050d761(R), 0050d76d(W)  
    //              long              Stack[-0xc]:4  index                     XREF[4]:     0050d5c1(W), 0050d6e9(R), 0050d71d(R), 0050d777(R)  
    //              undefined2        Stack[-0xe]:2  local_e                   XREF[2]:     0050d6cf(*), 0050d715(R)  
    //              short             Stack[-0x12]:2 target_player_id
    //                               ??0RGE_Timeline@@QAE@HPAVRGE_Game_World@@@Z                  XREF[1]:     RGE_Scenario:0048af35(c)  
    //                               RGE_Timeline::RGE_Timeline
    //                              Timeline.cpp:25 (8)
    //         0050d5b0     SUB        ESP,0x10
    //         0050d5b3     PUSH       EBX
    //         0050d5b4     PUSH       ESI
    //         0050d5b5     MOV        ESI,this
    //         0050d5b7     PUSH       EDI
    //                              Timeline.cpp:33 (33)
    //         0050d5b8     MOV        EDI,dword ptr [ESP + param_1]
    //         0050d5bc     PUSH       0x2
    //         0050d5be     LEA        EBX,[ESI + 0xc]
    //         0050d5c1     MOV        dword ptr [ESP + index],ESI
    //         0050d5c5     PUSH       EBX
    //         0050d5c6     PUSH       EDI
    //         0050d5c7     MOV        dword ptr [ESI],RGE_Timeline::`vftable'          = 0050d790
    //         0050d5cd     MOV        dword ptr [ESP + local_4],EBX
    //         0050d5d1     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050d5d6     ADD        ESP,0xc
    //                              Timeline.cpp:34 (15)
    //         0050d5d9     LEA        EAX,[ESI + 0xe]
    //         0050d5dc     PUSH       0x2
    //         0050d5de     PUSH       EAX
    //         0050d5df     PUSH       EDI
    //         0050d5e0     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050d5e5     ADD        ESP,0xc
    //                              Timeline.cpp:35 (12)
    //         0050d5e8     LEA        this,[ESI + 0x10]
    //         0050d5eb     PUSH       0x4
    //         0050d5ed     PUSH       this
    //         0050d5ee     PUSH       EDI
    //         0050d5ef     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              Timeline.cpp:37 (4)
    //         0050d5f4     MOV        EDX,dword ptr [ESP + param_2]
    //                              Timeline.cpp:38 (6)
    //         0050d5f8     LEA        EAX,[ESI + 0x8]
    //         0050d5fb     ADD        ESP,0xc
    //                              Timeline.cpp:42 (31)
    //         0050d5fe     CMP        word ptr [EBX],0x0
    //         0050d602     MOV        dword ptr [ESI + 0x4],EDX
    //         0050d605     MOV        dword ptr [EAX],0x0
    //         0050d60b     MOV        dword ptr [ESP + param_2],EAX
    //         0050d60f     MOV        dword ptr [ESP + local_8],0x0
    //         0050d617     JLE        LAB_0050d77c
    //                              Timeline.cpp:25 (1)
    //         0050d61d     PUSH       EBP
    //                               LAB_0050d61e                                                 XREF[1]:     0050d771(j)  
    //                              Timeline.cpp:44 (14)
    //         0050d61e     PUSH       0x30
    //         0050d620     PUSH       0x1
    //         0050d622     CALL       calloc                                           undefined calloc()
    //         0050d627     ADD        ESP,0x8
    //         0050d62a     MOV        ESI,EAX
    //                              Timeline.cpp:45 (12)
    //         0050d62c     PUSH       0x4
    //         0050d62e     PUSH       ESI
    //         0050d62f     PUSH       EDI
    //         0050d630     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050d635     ADD        ESP,0xc
    //                              Timeline.cpp:46 (15)
    //         0050d638     LEA        EAX,[ESI + 0x4]
    //         0050d63b     PUSH       0x1
    //         0050d63d     PUSH       EAX
    //         0050d63e     PUSH       EDI
    //         0050d63f     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050d644     ADD        ESP,0xc
    //                              Timeline.cpp:47 (15)
    //         0050d647     LEA        this,[ESI + 0x6]
    //         0050d64a     PUSH       0x2
    //         0050d64c     PUSH       this
    //         0050d64d     PUSH       EDI
    //         0050d64e     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050d653     ADD        ESP,0xc
    //                              Timeline.cpp:48 (15)
    //         0050d656     LEA        EDX,[ESI + 0x8]
    //         0050d659     PUSH       0x1
    //         0050d65b     PUSH       EDX
    //         0050d65c     PUSH       EDI
    //         0050d65d     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050d662     ADD        ESP,0xc
    //                              Timeline.cpp:49 (15)
    //         0050d665     LEA        EAX,[ESI + 0xc]
    //         0050d668     PUSH       0x4
    //         0050d66a     PUSH       EAX
    //         0050d66b     PUSH       EDI
    //         0050d66c     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050d671     ADD        ESP,0xc
    //                              Timeline.cpp:50 (15)
    //         0050d674     LEA        this,[ESI + 0x10]
    //         0050d677     PUSH       0x4
    //         0050d679     PUSH       this
    //         0050d67a     PUSH       EDI
    //         0050d67b     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050d680     ADD        ESP,0xc
    //                              Timeline.cpp:51 (15)
    //         0050d683     LEA        EDX,[ESI + 0x14]
    //         0050d686     PUSH       0x4
    //         0050d688     PUSH       EDX
    //         0050d689     PUSH       EDI
    //         0050d68a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050d68f     ADD        ESP,0xc
    //                              Timeline.cpp:52 (15)
    //         0050d692     LEA        EAX,[ESI + 0x18]
    //         0050d695     PUSH       0x2
    //         0050d697     PUSH       EAX
    //         0050d698     PUSH       EDI
    //         0050d699     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050d69e     ADD        ESP,0xc
    //                              Timeline.cpp:53 (15)
    //         0050d6a1     LEA        EBX,[ESI + 0x20]
    //         0050d6a4     PUSH       0x2
    //         0050d6a6     PUSH       EBX
    //         0050d6a7     PUSH       EDI
    //         0050d6a8     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050d6ad     ADD        ESP,0xc
    //                              Timeline.cpp:54 (16)
    //         0050d6b0     LEA        this=>param_1,[ESP + 0x24]
    //         0050d6b4     PUSH       0x2
    //         0050d6b6     PUSH       this
    //         0050d6b7     PUSH       EDI
    //         0050d6b8     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050d6bd     ADD        ESP,0xc
    //                              Timeline.cpp:55 (15)
    //         0050d6c0     LEA        EBP,[ESI + 0x28]
    //         0050d6c3     PUSH       0x2
    //         0050d6c5     PUSH       EBP
    //         0050d6c6     PUSH       EDI
    //         0050d6c7     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050d6cc     ADD        ESP,0xc
    //                              Timeline.cpp:56 (13)
    //         0050d6cf     LEA        EDX=>local_e,[ESP + 0x12]
    //         0050d6d3     PUSH       0x2
    //         0050d6d5     PUSH       EDX
    //         0050d6d6     PUSH       EDI
    //         0050d6d7     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              Timeline.cpp:59 (24)
    //         0050d6dc     MOV        AX,word ptr [ESP + param_1]
    //         0050d6e1     ADD        ESP,0xc
    //         0050d6e4     TEST       AX,AX
    //         0050d6e7     JL         LAB_0050d70e
    //         0050d6e9     MOV        this,dword ptr [ESP + index]
    //         0050d6ed     MOV        this,dword ptr [ECX + this->world]
    //         0050d6f0     TEST       this,this
    //         0050d6f2     JZ         LAB_0050d70e
    //                              Timeline.cpp:60 (24)
    //         0050d6f4     MOVSX      EDX,word ptr [EBX]
    //         0050d6f7     MOV        this,dword ptr [this->_padding_ + 0x40]
    //         0050d6fa     PUSH       EDX
    //         0050d6fb     MOVSX      EAX,AX
    //         0050d6fe     MOV        EDX,dword ptr [this->_padding_ + EAX*0x4]
    //         0050d701     MOV        this,dword ptr [EDX + 0x28]
    //         0050d704     CALL       RGE_Object_List::find_by_id                      RGE_Static_Object * find_by_id(RGE_Object_Lis
    //         0050d709     MOV        dword ptr [ESI + 0x1c],EAX
    //                              Timeline.cpp:61 (2)
    //         0050d70c     JMP        LAB_0050d715
    //                               LAB_0050d70e                                                 XREF[2]:     0050d6e7(j), 0050d6f2(j)  
    //                              Timeline.cpp:62 (7)
    //         0050d70e     MOV        dword ptr [ESI + 0x1c],0x0
    //                               LAB_0050d715                                                 XREF[1]:     0050d70c(j)  
    //                              Timeline.cpp:64 (19)
    //         0050d715     CMP        word ptr [ESP + local_e],0x0
    //         0050d71b     JL         LAB_0050d745
    //         0050d71d     MOV        EAX,dword ptr [ESP + index]
    //         0050d721     MOV        EAX,dword ptr [EAX + 0x4]
    //         0050d724     TEST       EAX,EAX
    //         0050d726     JZ         LAB_0050d745
    //                              Timeline.cpp:65 (27)
    //         0050d728     MOVSX      this,word ptr [EBP]
    //         0050d72c     MOVSX      EDX,word ptr [ESP + param_1]
    //         0050d731     MOV        EAX,dword ptr [EAX + 0x40]
    //         0050d734     PUSH       this
    //         0050d735     MOV        this,dword ptr [EAX + EDX*0x4]
    //         0050d738     MOV        this,dword ptr [this->_padding_ + 0x28]
    //         0050d73b     CALL       RGE_Object_List::find_by_id                      RGE_Static_Object * find_by_id(RGE_Object_Lis
    //         0050d740     MOV        dword ptr [ESI + 0x24],EAX
    //                              Timeline.cpp:66 (2)
    //         0050d743     JMP        LAB_0050d74c
    //                               LAB_0050d745                                                 XREF[2]:     0050d71b(j), 0050d726(j)  
    //                              Timeline.cpp:67 (7)
    //         0050d745     MOV        dword ptr [ESI + 0x24],0x0
    //                               LAB_0050d74c                                                 XREF[1]:     0050d743(j)  
    //                              Timeline.cpp:71 (11)
    //         0050d74c     MOV        EDX,dword ptr [ESP + param_2]
    //         0050d750     MOV        this,dword ptr [ESP + local_4]
    //         0050d754     LEA        EAX,[ESI + 0x2c]
    //                              Timeline.cpp:72 (37)
    //         0050d757     MOV        dword ptr [ESP + param_2],EAX
    //         0050d75b     MOV        dword ptr [EAX],0x0
    //         0050d761     MOV        EAX,dword ptr [ESP + local_8]
    //         0050d765     MOV        dword ptr [EDX],ESI
    //         0050d767     INC        EAX
    //         0050d768     MOVSX      EDX,word ptr [this->_padding_]
    //         0050d76b     CMP        EAX,EDX
    //         0050d76d     MOV        dword ptr [ESP + local_8],EAX
    //         0050d771     JL         LAB_0050d61e
    //         0050d777     MOV        ESI,dword ptr [ESP + index]
    //         0050d77b     POP        EBP
    //                               LAB_0050d77c                                                 XREF[1]:     0050d617(j)  
    //                              Timeline.cpp:74 (11)
    //         0050d77c     MOV        EAX,ESI
    //         0050d77e     POP        EDI
    //         0050d77f     POP        ESI
    //         0050d780     POP        EBX
    //         0050d781     ADD        ESP,0x10
    //         0050d784     RET        0x8
}

// Offset: 0x0050D7B0
undefined RGE_Timeline(RGE_Timeline* this_, RGE_Game_World* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Timeline::RGE_Timeline(class RGE_Game_World *)                                 *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Timeline(RGE_Timeline * this, RGE_Game_Worl
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Timeline *    ECX:4 (auto)   this
    //              RGE_Game_World    Stack[0x4]:4   param_1                   XREF[1]:     0050d7b2(R)  
    //                               ??0RGE_Timeline@@QAE@PAVRGE_Game_World@@@Z                   XREF[1]:     RGE_Scenario:0048ada4(c)  
    //                               RGE_Timeline::RGE_Timeline
    //                              Timeline.cpp:79 (2)
    //         0050d7b0     MOV        EAX,this
    //                              Timeline.cpp:80 (7)
    //         0050d7b2     MOV        this,dword ptr [ESP + param_1]
    //         0050d7b6     MOV        dword ptr [EAX + 0x4],this
    //                              Timeline.cpp:81 (11)
    //         0050d7b9     XOR        this,this
    //         0050d7bb     MOV        dword ptr [EAX],RGE_Timeline::`vftable'          = 0050d790
    //         0050d7c1     MOV        dword ptr [EAX + 0x8],this
    //                              Timeline.cpp:82 (4)
    //         0050d7c4     MOV        word ptr [EAX + 0xc],this
    //                              Timeline.cpp:83 (4)
    //         0050d7c8     MOV        word ptr [EAX + 0xe],this
    //                              Timeline.cpp:84 (7)
    //         0050d7cc     MOV        dword ptr [EAX + 0x10],0xbf800000
    //                              Timeline.cpp:85 (3)
    //         0050d7d3     RET        0x4
}

// Offset: 0x0050D7E0
void RGE_Timeline(RGE_Timeline* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall RGE_Timeline::~RGE_Timeline(void)                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall ~RGE_Timeline(RGE_Timeline * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Timeline *    ECX:4 (auto)   this
    //                               ??1RGE_Timeline@@UAE@XZ                                      XREF[1]:     `vector_deleting_destructor':0050d
    //                               RGE_Timeline::~RGE_Timeline
    //                              Timeline.cpp:90 (3)
    //         0050d7e0     PUSH       ESI
    //         0050d7e1     MOV        ESI,this
    //                              Timeline.cpp:93 (13)
    //         0050d7e3     MOV        EAX,dword ptr [ESI + 0x8]
    //         0050d7e6     MOV        dword ptr [ESI],RGE_Timeline::`vftable'          = 0050d790
    //         0050d7ec     TEST       EAX,EAX
    //         0050d7ee     JZ         LAB_0050d80a
    //                              Timeline.cpp:90 (1)
    //         0050d7f0     PUSH       EDI
    //                               LAB_0050d7f1                                                 XREF[1]:     0050d807(j)  
    //                              Timeline.cpp:95 (3)
    //         0050d7f1     MOV        EAX,dword ptr [ESI + 0x8]
    //                              Timeline.cpp:96 (14)
    //         0050d7f4     MOV        this,EAX
    //         0050d7f6     MOV        EDI,dword ptr [EAX + 0x2c]
    //         0050d7f9     PUSH       this
    //         0050d7fa     CALL       free                                             undefined free()
    //         0050d7ff     ADD        ESP,0x4
    //                              Timeline.cpp:97 (7)
    //         0050d802     MOV        dword ptr [ESI + 0x8],EDI
    //         0050d805     TEST       EDI,EDI
    //         0050d807     JNZ        LAB_0050d7f1
    //                              Timeline.cpp:90 (1)
    //         0050d809     POP        EDI
    //                               LAB_0050d80a                                                 XREF[1]:     0050d7ee(j)  
    //                              Timeline.cpp:99 (6)
    //         0050d80a     MOV        word ptr [ESI + 0xe],0x0
    //                              Timeline.cpp:100 (7)
    //         0050d810     MOV        dword ptr [ESI + 0x10],0xbf800000
    //                              Timeline.cpp:101 (7)
    //         0050d817     MOV        dword ptr [ESI + 0x4],0x0
    //                              Timeline.cpp:102 (6)
    //         0050d81e     MOV        word ptr [ESI + 0xc],0x0
    //                              Timeline.cpp:103 (2)
    //         0050d824     POP        ESI
    //         0050d825     RET
}

// Offset: 0x0050D830
void save(RGE_Timeline* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Timeline::save(int)                                                       *
    //                              *********************************************************************************************************
    //                              void __thiscall save(RGE_Timeline * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Timeline *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[4]:     0050d839(R), 0050d899(W), 0050d89f(W), 0050d947(*)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0050d848(W), 0050d973(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0050d844(W), 0050d882(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     0050d8b5(W), 0050d8bb(W), 0050d966(*)  
    //              short             Stack[-0x10]:2 target_player_id
    //                               ?save@RGE_Timeline@@QAEXH@Z                                  XREF[1]:     save:0048c4a9(c)  
    //                               RGE_Timeline::save
    //                              Timeline.cpp:108 (9)
    //         0050d830     SUB        ESP,0xc
    //         0050d833     PUSH       EBX
    //         0050d834     PUSH       EBP
    //         0050d835     PUSH       ESI
    //         0050d836     MOV        ESI,this
    //         0050d838     PUSH       EDI
    //                              Timeline.cpp:115 (27)
    //         0050d839     MOV        EDI,dword ptr [ESP + param_1]
    //         0050d83d     LEA        EBP,[ESI + 0xc]
    //         0050d840     PUSH       0x2
    //         0050d842     PUSH       EBP
    //         0050d843     PUSH       EDI
    //         0050d844     MOV        dword ptr [ESP + local_8],ESI
    //         0050d848     MOV        dword ptr [ESP + local_4],EBP
    //         0050d84c     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050d851     ADD        ESP,0xc
    //                              Timeline.cpp:116 (15)
    //         0050d854     LEA        EAX,[ESI + 0xe]
    //         0050d857     PUSH       0x2
    //         0050d859     PUSH       EAX
    //         0050d85a     PUSH       EDI
    //         0050d85b     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050d860     ADD        ESP,0xc
    //                              Timeline.cpp:117 (12)
    //         0050d863     LEA        this,[ESI + 0x10]
    //         0050d866     PUSH       0x4
    //         0050d868     PUSH       this
    //         0050d869     PUSH       EDI
    //         0050d86a     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              Timeline.cpp:119 (15)
    //         0050d86f     XOR        EBX,EBX
    //         0050d871     ADD        ESP,0xc
    //         0050d874     CMP        word ptr [EBP],BX
    //         0050d878     JLE        LAB_0050d989
    //                              Timeline.cpp:115 (8)
    //         0050d87e     XOR        EBP,EBP
    //         0050d880     JMP        LAB_0050d886
    //                               LAB_0050d882                                                 XREF[1]:     0050d983(j)  
    //         0050d882     MOV        ESI,dword ptr [ESP + local_8]
    //                               LAB_0050d886                                                 XREF[1]:     0050d880(j)  
    //                              Timeline.cpp:121 (5)
    //         0050d886     MOV        ESI,dword ptr [ESI + 0x8]
    //         0050d889     ADD        ESI,EBP
    //                              Timeline.cpp:124 (7)
    //         0050d88b     MOV        EAX,dword ptr [ESI + 0x1c]
    //         0050d88e     TEST       EAX,EAX
    //         0050d890     JZ         LAB_0050d89f
    //                              Timeline.cpp:125 (11)
    //         0050d892     MOV        EDX,dword ptr [EAX + 0xc]
    //         0050d895     MOV        AX,word ptr [EDX + 0x4a]
    //         0050d899     MOV        dword ptr [ESP + param_1],EAX
    //                              Timeline.cpp:126 (2)
    //         0050d89d     JMP        LAB_0050d8a7
    //                               LAB_0050d89f                                                 XREF[1]:     0050d890(j)  
    //                              Timeline.cpp:127 (8)
    //         0050d89f     MOV        dword ptr [ESP + param_1],0xffffffff
    //                               LAB_0050d8a7                                                 XREF[1]:     0050d89d(j)  
    //                              Timeline.cpp:129 (7)
    //         0050d8a7     MOV        EAX,dword ptr [ESI + 0x24]
    //         0050d8aa     TEST       EAX,EAX
    //         0050d8ac     JZ         LAB_0050d8bb
    //                              Timeline.cpp:130 (11)
    //         0050d8ae     MOV        this,dword ptr [EAX + 0xc]
    //         0050d8b1     MOV        DX,word ptr [this->_padding_ + 0x4a]
    //         0050d8b5     MOV        dword ptr [ESP + local_c],EDX
    //                              Timeline.cpp:131 (2)
    //         0050d8b9     JMP        LAB_0050d8c3
    //                               LAB_0050d8bb                                                 XREF[1]:     0050d8ac(j)  
    //                              Timeline.cpp:132 (8)
    //         0050d8bb     MOV        dword ptr [ESP + local_c],0xffffffff
    //                               LAB_0050d8c3                                                 XREF[1]:     0050d8b9(j)  
    //                              Timeline.cpp:135 (12)
    //         0050d8c3     PUSH       0x4
    //         0050d8c5     PUSH       ESI
    //         0050d8c6     PUSH       EDI
    //         0050d8c7     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050d8cc     ADD        ESP,0xc
    //                              Timeline.cpp:136 (15)
    //         0050d8cf     LEA        EAX,[ESI + 0x4]
    //         0050d8d2     PUSH       0x1
    //         0050d8d4     PUSH       EAX
    //         0050d8d5     PUSH       EDI
    //         0050d8d6     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050d8db     ADD        ESP,0xc
    //                              Timeline.cpp:137 (15)
    //         0050d8de     LEA        this,[ESI + 0x6]
    //         0050d8e1     PUSH       0x2
    //         0050d8e3     PUSH       this
    //         0050d8e4     PUSH       EDI
    //         0050d8e5     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050d8ea     ADD        ESP,0xc
    //                              Timeline.cpp:138 (15)
    //         0050d8ed     LEA        EDX,[ESI + 0x8]
    //         0050d8f0     PUSH       0x1
    //         0050d8f2     PUSH       EDX
    //         0050d8f3     PUSH       EDI
    //         0050d8f4     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050d8f9     ADD        ESP,0xc
    //                              Timeline.cpp:139 (15)
    //         0050d8fc     LEA        EAX,[ESI + 0xc]
    //         0050d8ff     PUSH       0x4
    //         0050d901     PUSH       EAX
    //         0050d902     PUSH       EDI
    //         0050d903     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050d908     ADD        ESP,0xc
    //                              Timeline.cpp:140 (15)
    //         0050d90b     LEA        this,[ESI + 0x10]
    //         0050d90e     PUSH       0x4
    //         0050d910     PUSH       this
    //         0050d911     PUSH       EDI
    //         0050d912     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050d917     ADD        ESP,0xc
    //                              Timeline.cpp:141 (15)
    //         0050d91a     LEA        EDX,[ESI + 0x14]
    //         0050d91d     PUSH       0x4
    //         0050d91f     PUSH       EDX
    //         0050d920     PUSH       EDI
    //         0050d921     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050d926     ADD        ESP,0xc
    //                              Timeline.cpp:142 (15)
    //         0050d929     LEA        EAX,[ESI + 0x18]
    //         0050d92c     PUSH       0x2
    //         0050d92e     PUSH       EAX
    //         0050d92f     PUSH       EDI
    //         0050d930     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050d935     ADD        ESP,0xc
    //                              Timeline.cpp:143 (15)
    //         0050d938     LEA        this,[ESI + 0x20]
    //         0050d93b     PUSH       0x2
    //         0050d93d     PUSH       this
    //         0050d93e     PUSH       EDI
    //         0050d93f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050d944     ADD        ESP,0xc
    //                              Timeline.cpp:144 (16)
    //         0050d947     LEA        EDX=>param_1,[ESP + 0x20]
    //         0050d94b     PUSH       0x2
    //         0050d94d     PUSH       EDX
    //         0050d94e     PUSH       EDI
    //         0050d94f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050d954     ADD        ESP,0xc
    //                              Timeline.cpp:145 (15)
    //         0050d957     ADD        ESI,0x28
    //         0050d95a     PUSH       0x2
    //         0050d95c     PUSH       ESI
    //         0050d95d     PUSH       EDI
    //         0050d95e     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050d963     ADD        ESP,0xc
    //                              Timeline.cpp:146 (35)
    //         0050d966     LEA        EAX=>local_c,[ESP + 0x10]
    //         0050d96a     PUSH       0x2
    //         0050d96c     PUSH       EAX
    //         0050d96d     PUSH       EDI
    //         0050d96e     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050d973     MOV        this,dword ptr [ESP + local_4]
    //         0050d977     ADD        ESP,0xc
    //         0050d97a     INC        EBX
    //         0050d97b     ADD        EBP,0x30
    //         0050d97e     MOVSX      EDX,word ptr [this->_padding_]
    //         0050d981     CMP        EBX,EDX
    //         0050d983     JL         LAB_0050d882
    //                               LAB_0050d989                                                 XREF[1]:     0050d878(j)  
    //                              Timeline.cpp:148 (10)
    //         0050d989     POP        EDI
    //         0050d98a     POP        ESI
    //         0050d98b     POP        EBP
    //         0050d98c     POP        EBX
    //         0050d98d     ADD        ESP,0xc
    //         0050d990     RET        0x4
}

// Offset: 0x0050D9A0
void update(RGE_Timeline* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Timeline::update(void)                                                    *
    //                              *********************************************************************************************************
    //                              void __thiscall update(RGE_Timeline * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Timeline *    ECX:4 (auto)   this
    //              undefined8        Stack[-0x8]:8  local_8                   XREF[5,1]:   0050d9b7(W), 0050d9be(R), 0050d9ca(W), 0050da17(R), 
    //                                                                                     0050dae6(R), 0050d9b3(W)  
    //              float             Stack[-0xc]:4  time
    //                               ?update@RGE_Timeline@@QAEXXZ                                 XREF[2]:     update:0048c3d7(c), 
    //                               RGE_Timeline::update                                                      update:0052ba83(c)  
    //                              Timeline.cpp:155 (8)
    //         0050d9a0     SUB        ESP,0x8
    //         0050d9a3     PUSH       EBX
    //         0050d9a4     MOV        EBX,this
    //         0050d9a6     PUSH       EBP
    //         0050d9a7     PUSH       ESI
    //                              Timeline.cpp:161 (19)
    //         0050d9a8     MOV        EAX,dword ptr [EBX + 0x4]
    //         0050d9ab     PUSH       EDI
    //         0050d9ac     XOR        EDI,EDI
    //         0050d9ae     XOR        ESI,ESI
    //         0050d9b0     MOV        this,dword ptr [EAX + 0x4]
    //         0050d9b3     MOV        dword ptr [ESP + local_8+0x4],EDI
    //         0050d9b7     MOV        dword ptr [ESP + local_8],this
    //                              Timeline.cpp:163 (25)
    //         0050d9bb     MOV        this,dword ptr [EBX + 0x8]
    //         0050d9be     FILD       qword ptr [ESP + local_8]
    //         0050d9c2     CMP        this,EDI
    //         0050d9c4     FMUL       float ptr [DAT_005766f8]                         = 6Fh    o
    //         0050d9ca     FSTP       float ptr [ESP + local_8]
    //         0050d9ce     JZ         LAB_0050dae6
    //                              Timeline.cpp:166 (2)
    //         0050d9d4     MOV        DL,0x8
    //                               LAB_0050d9d6                                                 XREF[1]:     0050da0b(j)  
    //                              Timeline.cpp:168 (16)
    //         0050d9d6     CMP        ESI,EDI
    //         0050d9d8     JNZ        LAB_0050d9e8
    //         0050d9da     FLD        float ptr [this->_padding_]
    //         0050d9dc     FCOMP      float ptr [EBX + 0x10]
    //         0050d9df     FNSTSW     AX
    //         0050d9e1     TEST       AH,0x41
    //         0050d9e4     JNZ        LAB_0050d9e8
    //                              Timeline.cpp:169 (2)
    //         0050d9e6     MOV        ESI,this
    //                               LAB_0050d9e8                                                 XREF[2]:     0050d9d8(j), 0050d9e4(j)  
    //                              Timeline.cpp:170 (7)
    //         0050d9e8     MOV        EAX,dword ptr [this->_padding_ + 0x1c]
    //         0050d9eb     CMP        EAX,EDI
    //         0050d9ed     JZ         LAB_0050d9f7
    //                              Timeline.cpp:171 (5)
    //         0050d9ef     CMP        byte ptr [EAX + 0x48],DL
    //         0050d9f2     JC         LAB_0050d9f7
    //                              Timeline.cpp:172 (3)
    //         0050d9f4     MOV        dword ptr [this->_padding_ + 0x1c],EDI
    //                               LAB_0050d9f7                                                 XREF[2]:     0050d9ed(j), 0050d9f2(j)  
    //                              Timeline.cpp:173 (7)
    //         0050d9f7     MOV        EAX,dword ptr [this->_padding_ + 0x24]
    //         0050d9fa     CMP        EAX,EDI
    //         0050d9fc     JZ         LAB_0050da06
    //                              Timeline.cpp:174 (5)
    //         0050d9fe     CMP        byte ptr [EAX + 0x48],DL
    //         0050da01     JC         LAB_0050da06
    //                              Timeline.cpp:175 (3)
    //         0050da03     MOV        dword ptr [this->_padding_ + 0x24],EDI
    //                               LAB_0050da06                                                 XREF[2]:     0050d9fc(j), 0050da01(j)  
    //                              Timeline.cpp:166 (7)
    //         0050da06     MOV        this,dword ptr [this->_padding_ + 0x2c]
    //         0050da09     CMP        this,EDI
    //         0050da0b     JNZ        LAB_0050d9d6
    //                              Timeline.cpp:179 (8)
    //         0050da0d     CMP        ESI,EDI
    //         0050da0f     JZ         LAB_0050dae6
    //                               LAB_0050da15                                                 XREF[1]:     0050dae0(j)  
    //                              Timeline.cpp:182 (17)
    //         0050da15     FLD        float ptr [ESI]
    //         0050da17     FCOMP      float ptr [ESP + local_8]
    //         0050da1b     FNSTSW     AX
    //         0050da1d     TEST       AH,0x41
    //         0050da20     JZ         LAB_0050dae6
    //                              Timeline.cpp:184 (21)
    //         0050da26     XOR        EAX,EAX
    //         0050da28     MOV        AL,byte ptr [ESI + 0x4]
    //         0050da2b     CMP        EAX,0x4
    //         0050da2e     JA         switchD_0050da34::caseD_3
    //                               switchD_0050da34::switchD
    //         0050da34     JMP        dword ptr [EAX*0x4 + switchD_0050da34::switchd   = 0050da3b
    //                               switchD_0050da34::caseD_0                                    XREF[2]:     0050da34(j), 0050daf8(*)  
    //                              Timeline.cpp:188 (22)
    //         0050da3b     MOV        this,dword ptr [ESI + 0x1c]
    //         0050da3e     CMP        this,EDI
    //         0050da40     JZ         switchD_0050da34::caseD_3
    //         0050da46     MOV        EAX,dword ptr [ESI + 0x24]
    //         0050da49     CMP        EAX,EDI
    //         0050da4b     JZ         switchD_0050da34::caseD_3
    //                              Timeline.cpp:189 (9)
    //         0050da51     MOV        EDX,dword ptr [this->_padding_]
    //         0050da53     PUSH       EAX
    //         0050da54     CALL       dword ptr [EDX + 0xa8]
    //                              Timeline.cpp:190 (2)
    //         0050da5a     JMP        switchD_0050da34::caseD_3
    //                               switchD_0050da34::caseD_1                                    XREF[2]:     0050da34(j), 0050dafc(*)  
    //                              Timeline.cpp:193 (24)
    //         0050da5c     MOV        this,dword ptr [EBX + 0x4]
    //         0050da5f     XOR        EAX,EAX
    //         0050da61     MOV        AL,byte ptr [ESI + 0x8]
    //         0050da64     MOV        EDX,dword ptr [this->_padding_ + 0x40]
    //         0050da67     MOVSX      this,word ptr [ESI + 0x6]
    //         0050da6b     MOV        EAX,dword ptr [EDX + EAX*0x4]
    //         0050da6e     MOV        EDX,dword ptr [EAX + 0x24]
    //         0050da71     MOV        this,dword ptr [EDX + this->_padding_*0x4]
    //                              Timeline.cpp:194 (4)
    //         0050da74     CMP        this,EDI
    //         0050da76     JZ         switchD_0050da34::caseD_3
    //                              Timeline.cpp:196 (15)
    //         0050da78     MOV        EBP,dword ptr [ESI + 0x10]
    //         0050da7b     MOV        EDX,dword ptr [this->_padding_]
    //         0050da7d     PUSH       EDI
    //         0050da7e     PUSH       EBP=>DAT_fffffff8
    //         0050da7f     MOV        EBP,dword ptr [ESI + 0xc]
    //         0050da82     PUSH       EBP=>DAT_fffffff4
    //         0050da83     PUSH       EAX=>DAT_fffffff0
    //         0050da84     CALL       dword ptr [EDX + 0x18]
    //                              Timeline.cpp:198 (7)
    //         0050da87     MOV        this,dword ptr [EBX + 0x8]
    //         0050da8a     CMP        this,EDI
    //         0050da8c     JZ         switchD_0050da34::caseD_3
    //                               LAB_0050da8e                                                 XREF[1]:     0050daad(j)  
    //                              Timeline.cpp:200 (13)
    //         0050da8e     MOV        DX,word ptr [ESI + 0x20]
    //         0050da92     CMP        DX,word ptr [this->_padding_ + 0x20]
    //         0050da96     JNZ        LAB_0050da9b
    //         0050da98     MOV        dword ptr [this->_padding_ + 0x1c],EAX
    //                               LAB_0050da9b                                                 XREF[1]:     0050da96(j)  
    //                              Timeline.cpp:201 (13)
    //         0050da9b     MOV        DX,word ptr [ESI + 0x20]
    //         0050da9f     CMP        DX,word ptr [this->_padding_ + 0x28]
    //         0050daa3     JNZ        LAB_0050daa8
    //         0050daa5     MOV        dword ptr [this->_padding_ + 0x24],EAX
    //                               LAB_0050daa8                                                 XREF[1]:     0050daa3(j)  
    //                              Timeline.cpp:198 (7)
    //         0050daa8     MOV        this,dword ptr [this->_padding_ + 0x2c]
    //         0050daab     CMP        this,EDI
    //         0050daad     JNZ        LAB_0050da8e
    //                              Timeline.cpp:204 (2)
    //         0050daaf     JMP        switchD_0050da34::caseD_3
    //                               switchD_0050da34::caseD_2                                    XREF[2]:     0050da34(j), 0050db00(*)  
    //                              Timeline.cpp:207 (7)
    //         0050dab1     MOV        this,dword ptr [ESI + 0x1c]
    //         0050dab4     CMP        this,EDI
    //         0050dab6     JZ         switchD_0050da34::caseD_3
    //                              Timeline.cpp:209 (21)
    //         0050dab8     MOV        EDX,dword ptr [ESI + 0x14]
    //         0050dabb     MOV        EAX,dword ptr [this->_padding_]
    //         0050dabd     PUSH       EDX
    //         0050dabe     MOV        EDX,dword ptr [ESI + 0x10]
    //         0050dac1     PUSH       EDX=>DAT_fffffff8
    //         0050dac2     MOV        EDX,dword ptr [ESI + 0xc]
    //         0050dac5     PUSH       EDX=>DAT_fffffff4
    //         0050dac6     PUSH       EDI=>DAT_fffffff0
    //         0050dac7     CALL       dword ptr [EAX + 0x9c]
    //                              Timeline.cpp:210 (2)
    //         0050dacd     JMP        switchD_0050da34::caseD_3
    //                               switchD_0050da34::caseD_4                                    XREF[2]:     0050da34(j), 0050db08(*)  
    //                              Timeline.cpp:213 (7)
    //         0050dacf     MOV        this,dword ptr [ESI + 0x1c]
    //         0050dad2     CMP        this,EDI
    //         0050dad4     JZ         switchD_0050da34::caseD_3
    //                              Timeline.cpp:215 (16)
    //         0050dad6     MOV        EAX,dword ptr [this->_padding_]
    //         0050dad8     CALL       dword ptr [EAX + 0x68]
    //                               switchD_0050da34::caseD_3                                    XREF[12]:    0050da2e(j), 0050da34(j), 
    //                                                                                                         0050da40(j), 0050da4b(j), 
    //                                                                                                         0050da5a(j), 0050da76(j), 
    //                                                                                                         0050da8c(j), 0050daaf(j), 
    //                                                                                                         0050dab6(j), 0050dacd(j), 
    //                                                                                                         0050dad4(j), 0050db04(*)  
    //         0050dadb     MOV        ESI,dword ptr [ESI + 0x2c]
    //         0050dade     CMP        ESI,EDI
    //         0050dae0     JNZ        LAB_0050da15
    //                               LAB_0050dae6                                                 XREF[3]:     0050d9ce(j), 0050da0f(j), 
    //                                                                                                         0050da20(j)  
    //                              Timeline.cpp:220 (4)
    //         0050dae6     MOV        this,dword ptr [ESP + local_8]
    //                              Timeline.cpp:221 (34)
    //         0050daea     POP        EDI
    //         0050daeb     POP        ESI
    //         0050daec     MOV        dword ptr [EBX + 0x10],this
    //         0050daef     POP        EBP
    //         0050daf0     POP        EBX
    //         0050daf1     ADD        ESP,0x8
    //         0050daf4     RET
}

// Offset: 0x0050DAF5
undefined FUN_0050daf5() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0050daf5()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0050daf5
    //         0050daf5     NOP
    //         0050daf6     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0050da34::switchdataD_0050daf8                       XREF[1]:     update:0050da34(*)  
}

// Offset: 0x0050DB10
void mock_update(RGE_Timeline* this_, float param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Timeline::mock_update(float)                                              *
    //                              *********************************************************************************************************
    //                              void __thiscall mock_update(RGE_Timeline * this, float param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Timeline *    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[4]:     0050db10(R), 0050db5a(R), 0050dc38(R), 0050dc64(R)  
    //                               ?mock_update@RGE_Timeline@@QAEXM@Z
    //                               RGE_Timeline::mock_update
    //                              Timeline.cpp:227 (26)
    //         0050db10     FLD        float ptr [ESP + param_1]
    //         0050db14     PUSH       EBX
    //         0050db15     PUSH       EBP
    //         0050db16     PUSH       ESI
    //         0050db17     PUSH       EDI
    //         0050db18     MOV        EDI,this
    //         0050db1a     XOR        EBX,EBX
    //         0050db1c     FCOMP      float ptr [EDI + 0x10]
    //         0050db1f     FNSTSW     AX
    //         0050db21     TEST       AH,0x1
    //         0050db24     JZ         LAB_0050dc35
    //                              Timeline.cpp:237 (13)
    //         0050db2a     MOV        EDX,dword ptr [EDI + 0x8]
    //         0050db2d     MOV        ESI,EDX
    //         0050db2f     CMP        ESI,EBX
    //         0050db31     JZ         LAB_0050dc35
    //                               LAB_0050db37                                                 XREF[1]:     0050db4e(j)  
    //                              Timeline.cpp:238 (25)
    //         0050db37     MOV        this,dword ptr [ESI + 0x2c]
    //         0050db3a     CMP        this,EBX
    //         0050db3c     JZ         LAB_0050db50
    //         0050db3e     FLD        float ptr [this->_padding_]
    //         0050db40     FCOMP      float ptr [EDI + 0x10]
    //         0050db43     FNSTSW     AX
    //         0050db45     TEST       AH,0x41
    //         0050db48     JZ         LAB_0050db50
    //         0050db4a     MOV        ESI,this
    //         0050db4c     CMP        ESI,EBX
    //         0050db4e     JNZ        LAB_0050db37
    //                               LAB_0050db50                                                 XREF[2]:     0050db3c(j), 0050db48(j)  
    //                              Timeline.cpp:241 (25)
    //         0050db50     CMP        ESI,EBX
    //         0050db52     JZ         LAB_0050dc35
    //                               LAB_0050db58                                                 XREF[1]:     0050dc2f(j)  
    //         0050db58     FLD        float ptr [ESI]
    //         0050db5a     FCOMP      float ptr [ESP + param_1]
    //         0050db5e     FNSTSW     AX
    //         0050db60     TEST       AH,0x41
    //         0050db63     JNZ        LAB_0050dc35
    //                              Timeline.cpp:243 (16)
    //         0050db69     FLD        float ptr [ESI]
    //         0050db6b     FCOMP      float ptr [EDI + 0x10]
    //         0050db6e     FNSTSW     AX
    //         0050db70     TEST       AH,0x41
    //         0050db73     JZ         LAB_0050dc0d
    //                              Timeline.cpp:244 (17)
    //         0050db79     XOR        EAX,EAX
    //         0050db7b     MOV        AL,byte ptr [ESI + 0x4]
    //         0050db7e     DEC        EAX
    //         0050db7f     JZ         LAB_0050dbdf
    //         0050db81     SUB        EAX,0x3
    //         0050db84     JNZ        LAB_0050dc0d
    //                              Timeline.cpp:248 (24)
    //         0050db8a     MOV        this,dword ptr [EDI + 0x4]
    //         0050db8d     XOR        EAX,EAX
    //         0050db8f     MOV        AL,byte ptr [ESI + 0x8]
    //         0050db92     MOV        EDX,dword ptr [this->_padding_ + 0x40]
    //         0050db95     MOVSX      this,word ptr [ESI + 0x6]
    //         0050db99     MOV        EAX,dword ptr [EDX + EAX*0x4]
    //         0050db9c     MOV        EDX,dword ptr [EAX + 0x24]
    //         0050db9f     MOV        this,dword ptr [EDX + this->_padding_*0x4]
    //                              Timeline.cpp:249 (4)
    //         0050dba2     CMP        this,EBX
    //         0050dba4     JZ         LAB_0050dc0d
    //                              Timeline.cpp:251 (15)
    //         0050dba6     MOV        EBP,dword ptr [ESI + 0x10]
    //         0050dba9     MOV        EDX,dword ptr [this->_padding_]
    //         0050dbab     PUSH       EBX
    //         0050dbac     PUSH       EBP
    //         0050dbad     MOV        EBP,dword ptr [ESI + 0xc]
    //         0050dbb0     PUSH       EBP
    //         0050dbb1     PUSH       EAX
    //         0050dbb2     CALL       dword ptr [EDX + 0x18]
    //                              Timeline.cpp:253 (7)
    //         0050dbb5     MOV        this,dword ptr [EDI + 0x8]
    //         0050dbb8     CMP        this,EBX
    //         0050dbba     JZ         LAB_0050dc0d
    //                               LAB_0050dbbc                                                 XREF[1]:     0050dbdb(j)  
    //                              Timeline.cpp:255 (13)
    //         0050dbbc     MOV        DX,word ptr [ESI + 0x20]
    //         0050dbc0     CMP        DX,word ptr [this->_padding_ + 0x20]
    //         0050dbc4     JNZ        LAB_0050dbc9
    //         0050dbc6     MOV        dword ptr [this->_padding_ + 0x1c],EAX
    //                               LAB_0050dbc9                                                 XREF[1]:     0050dbc4(j)  
    //                              Timeline.cpp:256 (13)
    //         0050dbc9     MOV        DX,word ptr [ESI + 0x20]
    //         0050dbcd     CMP        DX,word ptr [this->_padding_ + 0x28]
    //         0050dbd1     JNZ        LAB_0050dbd6
    //         0050dbd3     MOV        dword ptr [this->_padding_ + 0x24],EAX
    //                               LAB_0050dbd6                                                 XREF[1]:     0050dbd1(j)  
    //                              Timeline.cpp:253 (7)
    //         0050dbd6     MOV        this,dword ptr [this->_padding_ + 0x2c]
    //         0050dbd9     CMP        this,EBX
    //         0050dbdb     JNZ        LAB_0050dbbc
    //                              Timeline.cpp:259 (2)
    //         0050dbdd     JMP        LAB_0050dc0d
    //                               LAB_0050dbdf                                                 XREF[1]:     0050db7f(j)  
    //                              Timeline.cpp:262 (7)
    //         0050dbdf     MOV        this,dword ptr [ESI + 0x1c]
    //         0050dbe2     CMP        this,EBX
    //         0050dbe4     JZ         LAB_0050dc0d
    //                              Timeline.cpp:266 (6)
    //         0050dbe6     MOV        EAX,EDX
    //         0050dbe8     CMP        EAX,EBX
    //         0050dbea     JZ         LAB_0050dc03
    //                               LAB_0050dbec                                                 XREF[1]:     0050dc01(j)  
    //                              Timeline.cpp:268 (8)
    //         0050dbec     CMP        this,dword ptr [EAX + 0x1c]
    //         0050dbef     JNZ        LAB_0050dbf4
    //         0050dbf1     MOV        dword ptr [EAX + 0x1c],EBX
    //                               LAB_0050dbf4                                                 XREF[1]:     0050dbef(j)  
    //                              Timeline.cpp:269 (8)
    //         0050dbf4     CMP        this,dword ptr [EAX + 0x24]
    //         0050dbf7     JNZ        LAB_0050dbfc
    //         0050dbf9     MOV        dword ptr [EAX + 0x24],EBX
    //                               LAB_0050dbfc                                                 XREF[1]:     0050dbf7(j)  
    //                              Timeline.cpp:266 (7)
    //         0050dbfc     MOV        EAX,dword ptr [EAX + 0x2c]
    //         0050dbff     CMP        EAX,EBX
    //         0050dc01     JNZ        LAB_0050dbec
    //                               LAB_0050dc03                                                 XREF[1]:     0050dbea(j)  
    //                              Timeline.cpp:271 (10)
    //         0050dc03     CMP        this,EBX
    //         0050dc05     JZ         LAB_0050dc0d
    //         0050dc07     MOV        EAX,dword ptr [this->_padding_]
    //         0050dc09     PUSH       0x1
    //         0050dc0b     CALL       dword ptr [EAX]
    //                               LAB_0050dc0d                                                 XREF[7]:     0050db73(j), 0050db84(j), 
    //                                                                                                         0050dba4(j), 0050dbba(j), 
    //                                                                                                         0050dbdd(j), 0050dbe4(j), 
    //                                                                                                         0050dc05(j)  
    //                              Timeline.cpp:276 (7)
    //         0050dc0d     MOV        EDX,dword ptr [EDI + 0x8]
    //         0050dc10     CMP        ESI,EDX
    //         0050dc12     JNZ        LAB_0050dc18
    //                              Timeline.cpp:277 (2)
    //         0050dc14     XOR        ESI,ESI
    //                              Timeline.cpp:278 (2)
    //         0050dc16     JMP        LAB_0050dc2d
    //                               LAB_0050dc18                                                 XREF[1]:     0050dc12(j)  
    //                              Timeline.cpp:279 (6)
    //         0050dc18     MOV        EAX,EDX
    //         0050dc1a     CMP        EAX,EBX
    //         0050dc1c     JZ         LAB_0050dc2d
    //                               LAB_0050dc1e                                                 XREF[1]:     0050dc2b(j)  
    //                              Timeline.cpp:280 (7)
    //         0050dc1e     MOV        this,dword ptr [EAX + 0x2c]
    //         0050dc21     CMP        this,ESI
    //         0050dc23     JNZ        LAB_0050dc27
    //                              Timeline.cpp:281 (2)
    //         0050dc25     MOV        ESI,EAX
    //                               LAB_0050dc27                                                 XREF[1]:     0050dc23(j)  
    //                              Timeline.cpp:279 (6)
    //         0050dc27     MOV        EAX,this
    //         0050dc29     CMP        EAX,EBX
    //         0050dc2b     JNZ        LAB_0050dc1e
    //                               LAB_0050dc2d                                                 XREF[2]:     0050dc16(j), 0050dc1c(j)  
    //                              Timeline.cpp:241 (8)
    //         0050dc2d     CMP        ESI,EBX
    //         0050dc2f     JNZ        LAB_0050db58
    //                               LAB_0050dc35                                                 XREF[4]:     0050db24(j), 0050db31(j), 
    //                                                                                                         0050db52(j), 0050db63(j)  
    //                              Timeline.cpp:285 (18)
    //         0050dc35     FLD        float ptr [EDI + 0x10]
    //         0050dc38     FCOMP      float ptr [ESP + param_1]
    //         0050dc3c     FNSTSW     AX
    //         0050dc3e     TEST       AH,0x1
    //         0050dc41     JZ         LAB_0050dd13
    //                              Timeline.cpp:286 (11)
    //         0050dc47     MOV        ESI,dword ptr [EDI + 0x8]
    //         0050dc4a     CMP        ESI,EBX
    //         0050dc4c     JZ         LAB_0050dd13
    //                               LAB_0050dc52                                                 XREF[1]:     0050dd0d(j)  
    //                              Timeline.cpp:287 (33)
    //         0050dc52     FLD        float ptr [ESI]
    //         0050dc54     FCOMP      float ptr [EDI + 0x10]
    //         0050dc57     FNSTSW     AX
    //         0050dc59     TEST       AH,0x41
    //         0050dc5c     JNZ        LAB_0050dd08
    //         0050dc62     FLD        float ptr [ESI]
    //         0050dc64     FCOMP      float ptr [ESP + param_1]
    //         0050dc68     FNSTSW     AX
    //         0050dc6a     TEST       AH,0x41
    //         0050dc6d     JZ         LAB_0050dd08
    //                              Timeline.cpp:288 (17)
    //         0050dc73     XOR        EAX,EAX
    //         0050dc75     MOV        AL,byte ptr [ESI + 0x4]
    //         0050dc78     DEC        EAX
    //         0050dc79     JZ         LAB_0050dcb5
    //         0050dc7b     SUB        EAX,0x3
    //         0050dc7e     JNZ        LAB_0050dd08
    //                              Timeline.cpp:306 (7)
    //         0050dc84     MOV        this,dword ptr [ESI + 0x1c]
    //         0050dc87     CMP        this,EBX
    //         0050dc89     JZ         LAB_0050dd08
    //                              Timeline.cpp:310 (7)
    //         0050dc8b     MOV        EAX,dword ptr [EDI + 0x8]
    //         0050dc8e     CMP        EAX,EBX
    //         0050dc90     JZ         LAB_0050dca9
    //                               LAB_0050dc92                                                 XREF[1]:     0050dca7(j)  
    //                              Timeline.cpp:312 (8)
    //         0050dc92     CMP        this,dword ptr [EAX + 0x1c]
    //         0050dc95     JNZ        LAB_0050dc9a
    //         0050dc97     MOV        dword ptr [EAX + 0x1c],EBX
    //                               LAB_0050dc9a                                                 XREF[1]:     0050dc95(j)  
    //                              Timeline.cpp:313 (8)
    //         0050dc9a     CMP        this,dword ptr [EAX + 0x24]
    //         0050dc9d     JNZ        LAB_0050dca2
    //         0050dc9f     MOV        dword ptr [EAX + 0x24],EBX
    //                               LAB_0050dca2                                                 XREF[1]:     0050dc9d(j)  
    //                              Timeline.cpp:310 (7)
    //         0050dca2     MOV        EAX,dword ptr [EAX + 0x2c]
    //         0050dca5     CMP        EAX,EBX
    //         0050dca7     JNZ        LAB_0050dc92
    //                               LAB_0050dca9                                                 XREF[1]:     0050dc90(j)  
    //                              Timeline.cpp:315 (10)
    //         0050dca9     CMP        this,EBX
    //         0050dcab     JZ         LAB_0050dd08
    //         0050dcad     MOV        EDX,dword ptr [this->_padding_]
    //         0050dcaf     PUSH       0x1
    //         0050dcb1     CALL       dword ptr [EDX]
    //                              Timeline.cpp:317 (2)
    //         0050dcb3     JMP        LAB_0050dd08
    //                               LAB_0050dcb5                                                 XREF[1]:     0050dc79(j)  
    //                              Timeline.cpp:292 (24)
    //         0050dcb5     MOV        this,dword ptr [EDI + 0x4]
    //         0050dcb8     XOR        EAX,EAX
    //         0050dcba     MOV        AL,byte ptr [ESI + 0x8]
    //         0050dcbd     MOV        EDX,dword ptr [this->_padding_ + 0x40]
    //         0050dcc0     MOVSX      this,word ptr [ESI + 0x6]
    //         0050dcc4     MOV        EAX,dword ptr [EDX + EAX*0x4]
    //         0050dcc7     MOV        EDX,dword ptr [EAX + 0x24]
    //         0050dcca     MOV        this,dword ptr [EDX + this->_padding_*0x4]
    //                              Timeline.cpp:293 (4)
    //         0050dccd     CMP        this,EBX
    //         0050dccf     JZ         LAB_0050dd08
    //                              Timeline.cpp:295 (15)
    //         0050dcd1     MOV        EBP,dword ptr [ESI + 0x10]
    //         0050dcd4     MOV        EDX,dword ptr [this->_padding_]
    //         0050dcd6     PUSH       EBX
    //         0050dcd7     PUSH       EBP
    //         0050dcd8     MOV        EBP,dword ptr [ESI + 0xc]
    //         0050dcdb     PUSH       EBP
    //         0050dcdc     PUSH       EAX
    //         0050dcdd     CALL       dword ptr [EDX + 0x18]
    //                              Timeline.cpp:297 (7)
    //         0050dce0     MOV        this,dword ptr [EDI + 0x8]
    //         0050dce3     CMP        this,EBX
    //         0050dce5     JZ         LAB_0050dd08
    //                               LAB_0050dce7                                                 XREF[1]:     0050dd06(j)  
    //                              Timeline.cpp:299 (13)
    //         0050dce7     MOV        DX,word ptr [ESI + 0x20]
    //         0050dceb     CMP        DX,word ptr [this->_padding_ + 0x20]
    //         0050dcef     JNZ        LAB_0050dcf4
    //         0050dcf1     MOV        dword ptr [this->_padding_ + 0x1c],EAX
    //                               LAB_0050dcf4                                                 XREF[1]:     0050dcef(j)  
    //                              Timeline.cpp:300 (13)
    //         0050dcf4     MOV        DX,word ptr [ESI + 0x20]
    //         0050dcf8     CMP        DX,word ptr [this->_padding_ + 0x28]
    //         0050dcfc     JNZ        LAB_0050dd01
    //         0050dcfe     MOV        dword ptr [this->_padding_ + 0x24],EAX
    //                               LAB_0050dd01                                                 XREF[1]:     0050dcfc(j)  
    //                              Timeline.cpp:297 (7)
    //         0050dd01     MOV        this,dword ptr [this->_padding_ + 0x2c]
    //         0050dd04     CMP        this,EBX
    //         0050dd06     JNZ        LAB_0050dce7
    //                               LAB_0050dd08                                                 XREF[8]:     0050dc5c(j), 0050dc6d(j), 
    //                                                                                                         0050dc7e(j), 0050dc89(j), 
    //                                                                                                         0050dcab(j), 0050dcb3(j), 
    //                                                                                                         0050dccf(j), 0050dce5(j)  
    //                              Timeline.cpp:286 (11)
    //         0050dd08     MOV        ESI,dword ptr [ESI + 0x2c]
    //         0050dd0b     CMP        ESI,EBX
    //         0050dd0d     JNZ        LAB_0050dc52
    //                               LAB_0050dd13                                                 XREF[2]:     0050dc41(j), 0050dc4c(j)  
    //                              Timeline.cpp:319 (7)
    //         0050dd13     MOV        EAX,dword ptr [ESP + 0x14]
    //         0050dd17     MOV        dword ptr [EDI + 0x10],EAX
    //                              Timeline.cpp:320 (7)
    //         0050dd1a     POP        EDI
    //         0050dd1b     POP        ESI
    //         0050dd1c     POP        EBP
    //         0050dd1d     POP        EBX
    //         0050dd1e     RET        0x4
}

// Offset: 0x0050DD30
short find_id(RGE_Timeline* this_, RGE_Static_Object* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * private: short __thiscall RGE_Timeline::find_id(class RGE_Static_Object *)                            *
    //                              *********************************************************************************************************
    //                              short __thiscall find_id(RGE_Timeline * this, RGE_Static_Object * pa
    //              short             AX:2           <RETURN>
    //              RGE_Timeline *    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     0050dd37(R)  
    //                               ?find_id@RGE_Timeline@@AAEFPAVRGE_Static_Object@@@Z          XREF[3]:     add_attack:0050de28(c), 
    //                               RGE_Timeline::find_id                                                     add_attack:0050de3b(c), 
    //                                                                                                         add_move:0050df17(c)  
    //                              Timeline.cpp:326 (13)
    //         0050dd30     MOV        EAX,dword ptr [ECX + this->time_list]
    //         0050dd33     TEST       EAX,EAX
    //         0050dd35     JZ         LAB_0050dd5c
    //         0050dd37     MOV        this,dword ptr [ESP + param_1]
    //         0050dd3b     MOV        DL,0x1
    //                               LAB_0050dd3d                                                 XREF[1]:     0050dd4c(j)  
    //                              Timeline.cpp:331 (10)
    //         0050dd3d     CMP        byte ptr [EAX + 0x4],DL
    //         0050dd40     JNZ        LAB_0050dd47
    //         0050dd42     CMP        dword ptr [EAX + 0x1c],this
    //         0050dd45     JZ         LAB_0050dd55
    //                               LAB_0050dd47                                                 XREF[1]:     0050dd40(j)  
    //                              Timeline.cpp:330 (7)
    //         0050dd47     MOV        EAX,dword ptr [EAX + 0x2c]
    //         0050dd4a     TEST       EAX,EAX
    //         0050dd4c     JNZ        LAB_0050dd3d
    //                              Timeline.cpp:334 (4)
    //         0050dd4e     OR         AX,0xffff
    //                              Timeline.cpp:335 (3)
    //         0050dd52     RET        0x4
    //                               LAB_0050dd55                                                 XREF[1]:     0050dd45(j)  
    //                              Timeline.cpp:332 (4)
    //         0050dd55     MOV        AX,word ptr [EAX + 0x20]
    //                              Timeline.cpp:335 (3)
    //         0050dd59     RET        0x4
    //                               LAB_0050dd5c                                                 XREF[1]:     0050dd35(j)  
    //                              Timeline.cpp:334 (4)
    //         0050dd5c     OR         AX,0xffff
    //                              Timeline.cpp:335 (3)
    //         0050dd60     RET        0x4
}

// Offset: 0x0050DD70
RGE_Time_Entry* add(RGE_Timeline* this_, float param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: struct RGE_Time_Entry * __thiscall RGE_Timeline::add(float)                                   *
    //                              *********************************************************************************************************
    //                              RGE_Time_Entry * __thiscall add(RGE_Timeline * this, float param_1)
    //              RGE_Time_Entry    EAX:4          <RETURN>
    //              RGE_Timeline *    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[4]:     0050dd88(R), 0050dda1(R), 0050ddbf(R), 0050dde0(R)  
    //                               ?add@RGE_Timeline@@QAEPAURGE_Time_Entry@@M@Z                 XREF[4]:     add_attack:0050de09(c), 
    //                               RGE_Timeline::add                                                         add_create:0050de5d(c), 
    //                                                                                                         add_move:0050def9(c), 
    //                                                                                                         add_delete:0050df5f(c)  
    //                              Timeline.cpp:340 (5)
    //         0050dd70     PUSH       EBX
    //         0050dd71     MOV        EBX,this
    //         0050dd73     PUSH       ESI
    //         0050dd74     PUSH       EDI
    //                              Timeline.cpp:346 (10)
    //         0050dd75     MOV        ESI,dword ptr [EBX + 0x8]
    //         0050dd78     LEA        EDI,[EBX + 0x8]
    //         0050dd7b     TEST       ESI,ESI
    //         0050dd7d     JNZ        LAB_0050dd9f
    //                              Timeline.cpp:348 (9)
    //         0050dd7f     PUSH       0x30
    //         0050dd81     PUSH       0x1
    //         0050dd83     CALL       calloc                                           undefined calloc()
    //                              Timeline.cpp:349 (11)
    //         0050dd88     MOV        this,dword ptr [ESP + param_1]
    //         0050dd8c     MOV        dword ptr [EDI],EAX
    //         0050dd8e     ADD        ESP,0x8
    //         0050dd91     MOV        dword ptr [EAX],this
    //                              Timeline.cpp:350 (4)
    //         0050dd93     INC        word ptr [EBX + 0xc]
    //                              Timeline.cpp:351 (2)
    //         0050dd97     MOV        EAX,dword ptr [EDI]
    //                              Timeline.cpp:378 (6)
    //         0050dd99     POP        EDI
    //         0050dd9a     POP        ESI
    //         0050dd9b     POP        EBX
    //         0050dd9c     RET        0x4
    //                               LAB_0050dd9f                                                 XREF[2]:     0050dd7d(j), 0050ddb4(j)  
    //                              Timeline.cpp:358 (13)
    //         0050dd9f     FLD        float ptr [ESI]
    //         0050dda1     FCOMP      float ptr [ESP + param_1]
    //         0050dda5     FNSTSW     AX
    //         0050dda7     TEST       AH,0x41
    //         0050ddaa     JZ         LAB_0050ddd7
    //                              Timeline.cpp:368 (10)
    //         0050ddac     LEA        EDI,[ESI + 0x2c]
    //         0050ddaf     MOV        ESI,dword ptr [ESI + 0x2c]
    //         0050ddb2     TEST       ESI,ESI
    //         0050ddb4     JNZ        LAB_0050dd9f
    //                              Timeline.cpp:372 (9)
    //         0050ddb6     PUSH       0x30
    //         0050ddb8     PUSH       0x1
    //         0050ddba     CALL       calloc                                           undefined calloc()
    //                              Timeline.cpp:373 (9)
    //         0050ddbf     MOV        this,dword ptr [ESP + param_1]
    //         0050ddc3     ADD        ESP,0x8
    //         0050ddc6     MOV        dword ptr [EAX],this
    //                              Timeline.cpp:374 (3)
    //         0050ddc8     MOV        dword ptr [EAX + 0x2c],ESI
    //                              Timeline.cpp:375 (2)
    //         0050ddcb     MOV        dword ptr [EDI],EAX
    //                              Timeline.cpp:376 (4)
    //         0050ddcd     INC        word ptr [EBX + 0xc]
    //                              Timeline.cpp:378 (6)
    //         0050ddd1     POP        EDI
    //         0050ddd2     POP        ESI
    //         0050ddd3     POP        EBX
    //         0050ddd4     RET        0x4
    //                               LAB_0050ddd7                                                 XREF[1]:     0050ddaa(j)  
    //                              Timeline.cpp:360 (9)
    //         0050ddd7     PUSH       0x30
    //         0050ddd9     PUSH       0x1
    //         0050dddb     CALL       calloc                                           undefined calloc()
    //                              Timeline.cpp:361 (9)
    //         0050dde0     MOV        EDX,dword ptr [ESP + param_1]
    //         0050dde4     ADD        ESP,0x8
    //         0050dde7     MOV        dword ptr [EAX],EDX
    //                              Timeline.cpp:374 (3)
    //         0050dde9     MOV        dword ptr [EAX + 0x2c],ESI
    //                              Timeline.cpp:375 (2)
    //         0050ddec     MOV        dword ptr [EDI],EAX
    //                              Timeline.cpp:376 (4)
    //         0050ddee     INC        word ptr [EBX + 0xc]
    //                              Timeline.cpp:378 (6)
    //         0050ddf2     POP        EDI
    //         0050ddf3     POP        ESI
    //         0050ddf4     POP        EBX
    //         0050ddf5     RET        0x4
}

// Offset: 0x0050DE00
RGE_Time_Entry* add_attack(RGE_Timeline* this_, float param_2, RGE_Static_Object* param_3, RGE_Static_Object* param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: struct RGE_Time_Entry * __thiscall RGE_Timeline::add_attack(float,class RGE_Static_Object ... *
    //                              *********************************************************************************************************
    //                              RGE_Time_Entry * __thiscall add_attack(RGE_Timeline * this, float pa
    //              RGE_Time_Entry    EAX:4          <RETURN>
    //              RGE_Timeline *    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[1]:     0050de00(R)  
    //              RGE_Static_Obj    Stack[0x8]:4   param_2                   XREF[1]:     0050de15(R)  
    //              RGE_Static_Obj    Stack[0xc]:4   param_3                   XREF[1]:     0050de31(R)  
    //                               ?add_attack@RGE_Timeline@@QAEPAURGE_Time_Entry@@MPAVRGE_Sta
    //                               RGE_Timeline::add_attack
    //                              Timeline.cpp:383 (16)
    //         0050de00     MOV        EAX,dword ptr [ESP + param_1]
    //         0050de04     PUSH       EBX
    //         0050de05     PUSH       ESI
    //         0050de06     MOV        EBX,this
    //         0050de08     PUSH       EAX
    //         0050de09     CALL       RGE_Timeline::add                                RGE_Time_Entry * add(RGE_Timeline * this, flo
    //         0050de0e     MOV        ESI,EAX
    //                              Timeline.cpp:388 (5)
    //         0050de10     TEST       ESI,ESI
    //         0050de12     JZ         LAB_0050de49
    //         0050de14     PUSH       EDI
    //                              Timeline.cpp:390 (7)
    //         0050de15     MOV        EDI,dword ptr [ESP + param_2]
    //         0050de19     MOV        dword ptr [ESI + 0x1c],EDI
    //                              Timeline.cpp:392 (21)
    //         0050de1c     PUSH       EDI
    //         0050de1d     MOV        this,dword ptr [EDI + 0xc]
    //         0050de20     MOV        DL,byte ptr [this->_padding_ + 0x4a]
    //         0050de23     MOV        this,EBX
    //         0050de25     MOV        byte ptr [ESI + 0x8],DL
    //         0050de28     CALL       RGE_Timeline::find_id                            short find_id(RGE_Timeline * this, RGE_Static
    //         0050de2d     MOV        word ptr [ESI + 0x20],AX
    //                              Timeline.cpp:393 (4)
    //         0050de31     MOV        EAX,dword ptr [ESP + param_3]
    //                              Timeline.cpp:394 (15)
    //         0050de35     PUSH       EDI
    //         0050de36     MOV        this,EBX
    //         0050de38     MOV        dword ptr [ESI + 0x24],EAX
    //         0050de3b     CALL       RGE_Timeline::find_id                            short find_id(RGE_Timeline * this, RGE_Static
    //         0050de40     MOV        word ptr [ESI + 0x28],AX
    //                              Timeline.cpp:395 (5)
    //         0050de44     MOV        byte ptr [ESI + 0x4],0x0
    //         0050de48     POP        EDI
    //                               LAB_0050de49                                                 XREF[1]:     0050de12(j)  
    //                              Timeline.cpp:398 (2)
    //         0050de49     MOV        EAX,ESI
    //                              Timeline.cpp:399 (5)
    //         0050de4b     POP        ESI
    //         0050de4c     POP        EBX
    //         0050de4d     RET        0xc
}

// Offset: 0x0050DE50
RGE_Time_Entry* add_create(RGE_Timeline* this_, float param_2, short param_3, uchar param_4, float param_5, float param_6, float param_7) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: struct RGE_Time_Entry * __thiscall RGE_Timeline::add_create(float,short,unsigned char,floa... *
    //                              *********************************************************************************************************
    //                              RGE_Time_Entry * __thiscall add_create(RGE_Timeline * this, float pa
    //              RGE_Time_Entry    EAX:4          <RETURN>
    //              RGE_Timeline *    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[1]:     0050de50(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[2]:     0050de77(R), 0050dea8(R)  
    //              uchar             Stack[0xc]:1   param_3                   XREF[2]:     0050de65(R), 0050dea4(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[2]:     0050de8f(R), 0050deb0(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[2]:     0050de86(R), 0050deb8(R)  
    //              float             Stack[0x18]:4  param_6                   XREF[1]:     0050dec7(R)  
    //                               ?add_create@RGE_Timeline@@QAEPAURGE_Time_Entry@@MFEMMM@Z
    //                               RGE_Timeline::add_create
    //                              Timeline.cpp:404 (18)
    //         0050de50     MOV        EAX,dword ptr [ESP + param_1]
    //         0050de54     PUSH       EBX
    //         0050de55     PUSH       EBP
    //         0050de56     PUSH       ESI
    //         0050de57     PUSH       EDI
    //         0050de58     MOV        EDI,this
    //         0050de5a     PUSH       EAX
    //         0050de5b     XOR        EBX,EBX
    //         0050de5d     CALL       RGE_Timeline::add                                RGE_Time_Entry * add(RGE_Timeline * this, flo
    //                              Timeline.cpp:412 (32)
    //         0050de62     MOV        EDX,dword ptr [EDI + 0x4]
    //         0050de65     MOV        this,dword ptr [ESP + param_3]
    //         0050de69     MOV        ESI,EAX
    //         0050de6b     AND        this,0xff
    //         0050de71     MOV        EAX,dword ptr [EDX + 0x40]
    //         0050de74     MOV        EAX,dword ptr [EAX + this->_padding_*0x4]
    //         0050de77     MOVSX      this,word ptr [ESP + param_2]
    //         0050de7c     MOV        EDX,dword ptr [EAX + 0x24]
    //         0050de7f     MOV        EBP,dword ptr [EDX + this->_padding_*0x4]
    //                              Timeline.cpp:413 (4)
    //         0050de82     TEST       EBP,EBP
    //         0050de84     JZ         LAB_0050de9c
    //                              Timeline.cpp:414 (22)
    //         0050de86     MOV        this,dword ptr [ESP + param_5]
    //         0050de8a     MOV        EDX,dword ptr [EBP]
    //         0050de8d     PUSH       EBX
    //         0050de8e     PUSH       this
    //         0050de8f     MOV        this,dword ptr [ESP + param_4]
    //         0050de93     PUSH       this
    //         0050de94     PUSH       EAX
    //         0050de95     MOV        this,EBP
    //         0050de97     CALL       dword ptr [EDX + 0x18]
    //         0050de9a     MOV        EBX,EAX
    //                               LAB_0050de9c                                                 XREF[1]:     0050de84(j)  
    //                              Timeline.cpp:417 (8)
    //         0050de9c     TEST       ESI,ESI
    //         0050de9e     JZ         LAB_0050dedc
    //         0050dea0     TEST       EBP,EBP
    //         0050dea2     JZ         LAB_0050dedc
    //                              Timeline.cpp:419 (4)
    //         0050dea4     MOV        DL,byte ptr [ESP + param_3]
    //                              Timeline.cpp:420 (8)
    //         0050dea8     MOV        AX,word ptr [ESP + param_2]
    //         0050dead     MOV        byte ptr [ESI + 0x8],DL
    //                              Timeline.cpp:424 (8)
    //         0050deb0     MOV        EDX,dword ptr [ESP + param_4]
    //         0050deb4     MOV        word ptr [ESI + 0x6],AX
    //                              Timeline.cpp:425 (15)
    //         0050deb8     MOV        EAX,dword ptr [ESP + param_5]
    //         0050debc     MOV        dword ptr [ESI + 0x1c],EBX
    //         0050debf     MOV        this,word ptr [EDI + 0xe]
    //         0050dec3     MOV        word ptr [ESI + 0x20],this
    //                              Timeline.cpp:426 (17)
    //         0050dec7     MOV        this,dword ptr [ESP + param_6]
    //         0050decb     INC        word ptr [EDI + 0xe]
    //         0050decf     MOV        dword ptr [ESI + 0xc],EDX
    //         0050ded2     MOV        dword ptr [ESI + 0x10],EAX
    //         0050ded5     MOV        dword ptr [ESI + 0x14],this
    //                              Timeline.cpp:427 (4)
    //         0050ded8     MOV        byte ptr [ESI + 0x4],0x1
    //                               LAB_0050dedc                                                 XREF[2]:     0050de9e(j), 0050dea2(j)  
    //                              Timeline.cpp:430 (2)
    //         0050dedc     MOV        EAX,ESI
    //                              Timeline.cpp:431 (7)
    //         0050dede     POP        EDI
    //         0050dedf     POP        ESI
    //         0050dee0     POP        EBP
    //         0050dee1     POP        EBX
    //         0050dee2     RET        0x18
}

// Offset: 0x0050DEF0
RGE_Time_Entry* add_move(RGE_Timeline* this_, float param_2, RGE_Static_Object* param_3, float param_4, float param_5, float param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: struct RGE_Time_Entry * __thiscall RGE_Timeline::add_move(float,class RGE_Static_Object *,... *
    //                              *********************************************************************************************************
    //                              RGE_Time_Entry * __thiscall add_move(RGE_Timeline * this, float para
    //              RGE_Time_Entry    EAX:4          <RETURN>
    //              RGE_Timeline *    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[1]:     0050def0(R)  
    //              RGE_Static_Obj    Stack[0x8]:4   param_2                   XREF[1]:     0050df04(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     0050df28(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     0050df1c(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[1]:     0050df20(R)  
    //                               ?add_move@RGE_Timeline@@QAEPAURGE_Time_Entry@@MPAVRGE_Stati
    //                               RGE_Timeline::add_move
    //                              Timeline.cpp:436 (16)
    //         0050def0     MOV        EAX,dword ptr [ESP + param_1]
    //         0050def4     PUSH       ESI
    //         0050def5     PUSH       EDI
    //         0050def6     MOV        EDI,this
    //         0050def8     PUSH       EAX
    //         0050def9     CALL       RGE_Timeline::add                                RGE_Time_Entry * add(RGE_Timeline * this, flo
    //         0050defe     MOV        ESI,EAX
    //                              Timeline.cpp:442 (4)
    //         0050df00     TEST       ESI,ESI
    //         0050df02     JZ         LAB_0050df39
    //                              Timeline.cpp:444 (4)
    //         0050df04     MOV        EAX,dword ptr [ESP + param_2]
    //                              Timeline.cpp:446 (20)
    //         0050df08     PUSH       EAX
    //         0050df09     MOV        this,dword ptr [EAX + 0xc]
    //         0050df0c     MOV        DL,byte ptr [this->_padding_ + 0x4a]
    //         0050df0f     MOV        this,EDI
    //         0050df11     MOV        byte ptr [ESI + 0x8],DL
    //         0050df14     MOV        dword ptr [ESI + 0x1c],EAX
    //         0050df17     CALL       RGE_Timeline::find_id                            short find_id(RGE_Timeline * this, RGE_Static
    //                              Timeline.cpp:448 (4)
    //         0050df1c     MOV        this,dword ptr [ESP + param_4]
    //                              Timeline.cpp:449 (21)
    //         0050df20     MOV        EDX,dword ptr [ESP + param_5]
    //         0050df24     MOV        word ptr [ESI + 0x20],AX
    //         0050df28     MOV        EAX,dword ptr [ESP + param_3]
    //         0050df2c     MOV        dword ptr [ESI + 0xc],EAX
    //         0050df2f     MOV        dword ptr [ESI + 0x10],this
    //         0050df32     MOV        dword ptr [ESI + 0x14],EDX
    //                              Timeline.cpp:450 (4)
    //         0050df35     MOV        byte ptr [ESI + 0x4],0x2
    //                               LAB_0050df39                                                 XREF[1]:     0050df02(j)  
    //                              Timeline.cpp:453 (2)
    //         0050df39     MOV        EAX,ESI
    //                              Timeline.cpp:454 (5)
    //         0050df3b     POP        EDI
    //         0050df3c     POP        ESI
    //         0050df3d     RET        0x14
}

// Offset: 0x0050DF40
RGE_Time_Entry* add_delete(RGE_Timeline* this_, float param_2, RGE_Static_Object* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: struct RGE_Time_Entry * __thiscall RGE_Timeline::add_delete(float,class RGE_Static_Object *)  *
    //                              *********************************************************************************************************
    //                              RGE_Time_Entry * __thiscall add_delete(RGE_Timeline * this, float pa
    //              RGE_Time_Entry    EAX:4          <RETURN>
    //              RGE_Timeline *    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[1]:     0050df57(R)  
    //              RGE_Static_Obj    Stack[0x8]:4   param_2                   XREF[1]:     0050df42(R)  
    //                               ?add_delete@RGE_Timeline@@QAEPAURGE_Time_Entry@@MPAVRGE_Sta
    //                               RGE_Timeline::add_delete
    //                              Timeline.cpp:459 (2)
    //         0050df40     PUSH       EBP
    //         0050df41     PUSH       ESI
    //                              Timeline.cpp:463 (13)
    //         0050df42     MOV        ESI,dword ptr [ESP + param_2]
    //         0050df46     XOR        EBP,EBP
    //         0050df48     PUSH       EDI
    //         0050df49     CMP        ESI,EBP
    //         0050df4b     MOV        EDI,this
    //         0050df4d     JNZ        LAB_0050df57
    //                              Timeline.cpp:464 (2)
    //         0050df4f     XOR        EAX,EAX
    //                              Timeline.cpp:494 (6)
    //         0050df51     POP        EDI
    //         0050df52     POP        ESI
    //         0050df53     POP        EBP
    //         0050df54     RET        0x8
    //                               LAB_0050df57                                                 XREF[1]:     0050df4d(j)  
    //                              Timeline.cpp:466 (15)
    //         0050df57     MOV        EAX,dword ptr [ESP + param_1]
    //         0050df5b     PUSH       EBX
    //         0050df5c     PUSH       EAX
    //         0050df5d     MOV        this,EDI
    //         0050df5f     CALL       RGE_Timeline::add                                RGE_Time_Entry * add(RGE_Timeline * this, flo
    //         0050df64     MOV        EBX,EAX
    //                              Timeline.cpp:468 (4)
    //         0050df66     CMP        EBX,EBP
    //         0050df68     JZ         LAB_0050dfc7
    //                              Timeline.cpp:471 (12)
    //         0050df6a     MOV        EAX,dword ptr [EDI + 0x8]
    //         0050df6d     MOV        this,0x1
    //         0050df72     CMP        EAX,EBP
    //         0050df74     JZ         LAB_0050df9c
    //                               LAB_0050df76                                                 XREF[1]:     0050df9a(j)  
    //                              Timeline.cpp:473 (5)
    //         0050df76     CMP        ESI,dword ptr [EAX + 0x1c]
    //         0050df79     JNZ        LAB_0050df8d
    //                              Timeline.cpp:476 (10)
    //         0050df7b     MOV        DL,byte ptr [EAX + 0x4]
    //         0050df7e     MOV        dword ptr [EAX + 0x1c],EBP
    //         0050df81     CMP        DL,this
    //         0050df83     JNZ        LAB_0050df8d
    //                              Timeline.cpp:477 (8)
    //         0050df85     MOV        DX,word ptr [EAX + 0x20]
    //         0050df89     MOV        word ptr [EBX + 0x20],DX
    //                               LAB_0050df8d                                                 XREF[2]:     0050df79(j), 0050df83(j)  
    //                              Timeline.cpp:479 (8)
    //         0050df8d     CMP        ESI,dword ptr [EAX + 0x24]
    //         0050df90     JNZ        LAB_0050df95
    //         0050df92     MOV        dword ptr [EAX + 0x24],EBP
    //                               LAB_0050df95                                                 XREF[1]:     0050df90(j)  
    //                              Timeline.cpp:471 (7)
    //         0050df95     MOV        EAX,dword ptr [EAX + 0x2c]
    //         0050df98     CMP        EAX,EBP
    //         0050df9a     JNZ        LAB_0050df76
    //                               LAB_0050df9c                                                 XREF[1]:     0050df74(j)  
    //                              Timeline.cpp:483 (3)
    //         0050df9c     MOV        EAX,dword ptr [ESI + 0xc]
    //                              Timeline.cpp:490 (40)
    //         0050df9f     PUSH       this
    //         0050dfa0     MOV        this,ESI
    //         0050dfa2     MOV        DL,byte ptr [EAX + 0x4a]
    //         0050dfa5     MOV        byte ptr [EBX + 0x8],DL
    //         0050dfa8     MOV        EAX,dword ptr [ESI + 0x8]
    //         0050dfab     MOV        DX,word ptr [EAX + 0x10]
    //         0050dfaf     MOV        byte ptr [EBX + 0x4],0x4
    //         0050dfb3     MOV        word ptr [EBX + 0x6],DX
    //         0050dfb7     MOV        EAX,dword ptr [ESI + 0x38]
    //         0050dfba     MOV        dword ptr [EBX + 0xc],EAX
    //         0050dfbd     MOV        EDX,dword ptr [ESI + 0x3c]
    //         0050dfc0     MOV        EAX,dword ptr [ESI]
    //         0050dfc2     MOV        dword ptr [EBX + 0x10],EDX
    //         0050dfc5     CALL       dword ptr [EAX]
    //                               LAB_0050dfc7                                                 XREF[1]:     0050df68(j)  
    //                              Timeline.cpp:493 (3)
    //         0050dfc7     MOV        EAX,EBX
    //         0050dfc9     POP        EBX
    //                              Timeline.cpp:494 (6)
    //         0050dfca     POP        EDI
    //         0050dfcb     POP        ESI
    //         0050dfcc     POP        EBP
    //         0050dfcd     RET        0x8
}

// Offset: 0x0050DFD0
void sub(RGE_Timeline* this_, RGE_Time_Entry* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Timeline::sub(struct RGE_Time_Entry *)                                    *
    //                              *********************************************************************************************************
    //                              void __thiscall sub(RGE_Timeline * this, RGE_Time_Entry * param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Timeline *    ECX:4 (auto)   this
    //              RGE_Time_Entry    Stack[0x4]:4   param_1                   XREF[2]:     0050dfe4(R), 0050e016(R)  
    //                               ?sub@RGE_Timeline@@QAEXPAURGE_Time_Entry@@@Z                 XREF[1]:     0050e01d(c)  
    //                               RGE_Timeline::sub
    //                              Timeline.cpp:499 (4)
    //         0050dfd0     PUSH       ESI
    //         0050dfd1     PUSH       EDI
    //         0050dfd2     MOV        EDI,this
    //                              Timeline.cpp:504 (10)
    //         0050dfd4     MOV        ESI,dword ptr [EDI + 0x8]
    //         0050dfd7     LEA        this,[EDI + 0x8]
    //         0050dfda     TEST       ESI,ESI
    //         0050dfdc     JZ         LAB_0050e02f
    //                              Timeline.cpp:509 (10)
    //         0050dfde     TEST       ESI,ESI
    //         0050dfe0     MOV        EAX,this
    //         0050dfe2     JZ         LAB_0050e02f
    //         0050dfe4     MOV        EDX,dword ptr [ESP + param_1]
    //                               LAB_0050dfe8                                                 XREF[1]:     0050dff4(j)  
    //                              Timeline.cpp:511 (4)
    //         0050dfe8     CMP        ESI,EDX
    //         0050dfea     JZ         LAB_0050dffb
    //                              Timeline.cpp:528 (10)
    //         0050dfec     LEA        EAX,[ESI + 0x2c]
    //         0050dfef     MOV        ESI,dword ptr [ESI + 0x2c]
    //         0050dff2     TEST       ESI,ESI
    //         0050dff4     JNZ        LAB_0050dfe8
    //                              Timeline.cpp:530 (5)
    //         0050dff6     POP        EDI
    //         0050dff7     POP        ESI
    //         0050dff8     RET        0x4
    //                               LAB_0050dffb                                                 XREF[1]:     0050dfea(j)  
    //                              Timeline.cpp:514 (5)
    //         0050dffb     MOV        EDX,dword ptr [ESI + 0x2c]
    //         0050dffe     MOV        dword ptr [EAX],EDX
    //                              Timeline.cpp:517 (7)
    //         0050e000     MOV        AL,byte ptr [ESI + 0x4]
    //         0050e003     CMP        AL,0x1
    //         0050e005     JNZ        LAB_0050e016
    //                              Timeline.cpp:518 (19)
    //         0050e007     MOV        EAX,dword ptr [this->_padding_]
    //         0050e009     TEST       EAX,EAX
    //         0050e00b     JZ         LAB_0050e01a
    //                               LAB_0050e00d                                                 XREF[1]:     0050e012(j)  
    //         0050e00d     MOV        EAX,dword ptr [EAX + 0x2c]
    //         0050e010     TEST       EAX,EAX
    //         0050e012     JNZ        LAB_0050e00d
    //         0050e014     JMP        LAB_0050e01a
    //                               LAB_0050e016                                                 XREF[1]:     0050e005(j)  
    //         0050e016     MOV        EAX,dword ptr [ESP + param_1]
    //                               LAB_0050e01a                                                 XREF[2]:     0050e00b(j), 0050e014(j)  
    //                              Timeline.cpp:520 (8)
    //         0050e01a     PUSH       EAX
    //         0050e01b     MOV        this,EDI
    //         0050e01d     CALL       RGE_Timeline::sub                                void sub(RGE_Timeline * this, RGE_Time_Entry 
    //                              Timeline.cpp:523 (9)
    //         0050e022     PUSH       ESI
    //         0050e023     CALL       free                                             undefined free()
    //         0050e028     ADD        ESP,0x4
    //                              Timeline.cpp:524 (4)
    //         0050e02b     DEC        word ptr [EDI + 0xc]
    //                               LAB_0050e02f                                                 XREF[2]:     0050dfdc(j), 0050dfe2(j)  
    //                              Timeline.cpp:530 (5)
    //         0050e02f     POP        EDI
    //         0050e030     POP        ESI
    //         0050e031     RET        0x4
}

