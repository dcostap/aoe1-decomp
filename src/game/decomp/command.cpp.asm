// Auto-generated scaffold unit: command.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/Command.cpp
#include "../include/common.h"

// Offset: 0x00433D40
undefined RGE_Command(RGE_Command* this_, RGE_Game_World* param_2, TCommunications_Handler* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Command::RGE_Command(class RGE_Game_World *,class TCommunications_Handler *)   *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Command(RGE_Command * this, RGE_Game_World 
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              RGE_Game_World    Stack[0x4]:4   param_1                   XREF[1]:     00433d46(R)  
    //              TCommunication    Stack[0x8]:4   param_2                   XREF[1]:     00433d40(R)  
    //                               ??0RGE_Command@@QAE@PAVRGE_Game_World@@PAVTCommunications_H  XREF[2]:     TRIBE_Command:0050972f(c), 
    //                               RGE_Command::RGE_Command                                                  command_init:00541d3b(c)  
    //                              Command.cpp:45 (13)
    //         00433d40     MOV        EDX,dword ptr [ESP + param_2]
    //         00433d44     MOV        EAX,this
    //         00433d46     MOV        this,dword ptr [ESP + param_1]
    //         00433d4a     MOV        dword ptr [EAX + 0x4],this
    //                              Command.cpp:46 (14)
    //         00433d4d     XOR        this,this
    //         00433d4f     MOV        dword ptr [EAX + 0x14],EDX
    //         00433d52     MOV        dword ptr [EAX],RGE_Command::`vftable'           = 00434920
    //         00433d58     MOV        dword ptr [EAX + 0x8],this
    //                              Command.cpp:47 (3)
    //         00433d5b     MOV        dword ptr [EAX + 0xc],this
    //                              Command.cpp:48 (3)
    //         00433d5e     RET        0x8
}

// Offset: 0x00433D90
void RGE_Command(RGE_Command* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall RGE_Command::~RGE_Command(void)                                            *
    //                              *********************************************************************************************************
    //                              void __thiscall ~RGE_Command(RGE_Command * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //                               ??1RGE_Command@@UAE@XZ                                       XREF[2]:     `vector_deleting_destructor':00433
    //                               RGE_Command::~RGE_Command                                                 ~RGE_Command:0050975e(T), 
    //                                                                                                         ~TRIBE_Command:00509760(j)  
    //                              Command.cpp:53 (11)
    //         00433d90     XOR        EAX,EAX
    //         00433d92     MOV        dword ptr [this->_padding_],RGE_Command::`vfta   = 00434920
    //         00433d98     MOV        dword ptr [ECX + this->world],EAX
    //                              Command.cpp:55 (3)
    //         00433d9b     MOV        dword ptr [ECX + this->com_hand],EAX
    //                              Command.cpp:56 (7)
    //         00433d9e     MOV        this,dword ptr [ECX + this->last_order]
    //         00433da1     CMP        this,EAX
    //         00433da3     JZ         LAB_00433dae
    //                              Command.cpp:57 (9)
    //         00433da5     PUSH       this
    //         00433da6     CALL       free                                             undefined free()
    //         00433dab     ADD        ESP,0x4
    //                               LAB_00433dae                                                 XREF[1]:     00433da3(j)  
    //                              Command.cpp:58 (1)
    //         00433dae     RET
}

// Offset: 0x00433DB0
void reset_communications(RGE_Command* this_, TCommunications_Handler* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Command::reset_communications(class TCommunications_Handler *)            *
    //                              *********************************************************************************************************
    //                              void __thiscall reset_communications(RGE_Command * this, TCommunicat
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              TCommunication    Stack[0x4]:4   param_1                   XREF[1]:     00433db0(R)  
    //                               ?reset_communications@RGE_Command@@QAEXPAVTCommunications_H  XREF[1]:     reset_communications:00541ea8(c)  
    //                               RGE_Command::reset_communications
    //                              Command.cpp:64 (7)
    //         00433db0     MOV        EAX,dword ptr [ESP + param_1]
    //         00433db4     MOV        dword ptr [ECX + this->com_hand],EAX
    //                              Command.cpp:66 (3)
    //         00433db7     RET        0x4
}

// Offset: 0x00433DC0
RGE_Static_Object* get_obj(RGE_Command* this_, RGE_Obj_Info param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: class RGE_Static_Object * __thiscall RGE_Command::get_obj(struct RGE_Obj_Info)             *
    //                              *********************************************************************************************************
    //                              RGE_Static_Object * __thiscall get_obj(RGE_Command * this, RGE_Obj_I
    //              RGE_Static_Obj    EAX:4          <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              RGE_Obj_Info      Stack[0x4]:4   param_1                   XREF[1]:     00433dc0(R)  
    //                               ?get_obj@RGE_Command@@IAEPAVRGE_Static_Object@@URGE_Obj_Inf  XREF[26]:    do_command_order:00433f45(c), 
    //                               RGE_Command::get_obj                                                      do_command_order:00433f96(c), 
    //                                                                                                         do_command_order:0043408a(c), 
    //                                                                                                         do_command_order:0043420b(c), 
    //                                                                                                         do_command_pause:004342fc(c), 
    //                                                                                                         do_command_work:00434348(c), 
    //                                                                                                         do_command_work:0043436f(c), 
    //                                                                                                         do_command_move:00434429(c), 
    //                                                                                                         do_command_move:0043447a(c), 
    //                                                                                                         do_command_move:00434578(c), 
    //                                                                                                         do_command_move:00434784(c), 
    //                                                                                                         do_command_formation:00434a37(c), 
    //                                                                                                         do_command_formation:00434af9(c), 
    //                                                                                                         do_command_group_ai_order:00434de9
    //                                                                                                         do_command_build_wall:00509fc9(c), 
    //                                                                                                         do_command_explore:0050a177(c), 
    //                                                                                                         do_command_attack_ground:0050a4dd(
    //                                                                                                         do_command_trade_attribute:0050a6b
    //                                                                                                         do_command_repair:0050a6fa(c), 
    //                                                                                                         do_command_repair:0050a70a(c), 
    //                                                                                                         [more]
    //                              Command.cpp:71 (9)
    //         00433dc0     MOV        EAX,dword ptr [ESP + param_1.id]
    //         00433dc4     CMP        EAX,-0x1
    //         00433dc7     JNZ        LAB_00433dce
    //                              Command.cpp:74 (2)
    //         00433dc9     XOR        EAX,EAX
    //                              Command.cpp:115 (3)
    //         00433dcb     RET        0x4
    //                               LAB_00433dce                                                 XREF[1]:     00433dc7(j)  
    //                              Command.cpp:76 (9)
    //         00433dce     MOV        this,dword ptr [ECX + this->world]
    //         00433dd1     PUSH       EAX
    //         00433dd2     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              Command.cpp:115 (3)
    //         00433dd7     RET        0x4
}

// Offset: 0x00433DE0
void do_commands(RGE_Command* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Command::do_commands(void)                                                *
    //                              *********************************************************************************************************
    //                              void __thiscall do_commands(RGE_Command * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //                               ?do_commands@RGE_Command@@QAEXXZ                             XREF[4]:     command_menu:0049c7a0(c), 
    //                               RGE_Command::do_commands                                                  command_save_game:0049cbbd(c), 
    //                                                                                                         command_save_scenario:0049cc4d(c), 
    //                                                                                                         update:00543038(c)  
    //                              Command.cpp:120 (4)
    //         00433de0     PUSH       ESI
    //         00433de1     PUSH       EDI
    //         00433de2     MOV        EDI,this
    //                              Command.cpp:125 (7)
    //         00433de4     MOV        this,dword ptr [EDI + 0x14]
    //         00433de7     TEST       this,this
    //         00433de9     JZ         LAB_00433e1d
    //                              Command.cpp:129 (11)
    //         00433deb     CALL       TCommunications_Handler::get_command             void * get_command(TCommunications_Handler * 
    //         00433df0     MOV        ESI,EAX
    //         00433df2     TEST       ESI,ESI
    //         00433df4     JZ         LAB_00433e1d
    //                              Command.cpp:130 (11)
    //         00433df6     MOV        EAX,dword ptr [EDI]
    //         00433df8     PUSH       EBX
    //         00433df9     MOV        EBX,dword ptr [EAX + 0x8]
    //                               LAB_00433dfc                                                 XREF[1]:     00433e1a(j)  
    //         00433dfc     PUSH       ESI
    //         00433dfd     MOV        this,EDI
    //         00433dff     CALL       EBX
    //                              Command.cpp:131 (4)
    //         00433e01     TEST       ESI,ESI
    //         00433e03     JZ         LAB_00433e0e
    //                              Command.cpp:132 (23)
    //         00433e05     PUSH       ESI
    //         00433e06     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00433e0b     ADD        ESP,0x4
    //                               LAB_00433e0e                                                 XREF[1]:     00433e03(j)  
    //         00433e0e     MOV        this,dword ptr [EDI + 0x14]
    //         00433e11     CALL       TCommunications_Handler::get_command             void * get_command(TCommunications_Handler * 
    //         00433e16     MOV        ESI,EAX
    //         00433e18     TEST       ESI,ESI
    //         00433e1a     JNZ        LAB_00433dfc
    //                              Command.cpp:120 (1)
    //         00433e1c     POP        EBX
    //                               LAB_00433e1d                                                 XREF[2]:     00433de9(j), 00433df4(j)  
    //                              Command.cpp:135 (3)
    //         00433e1d     POP        EDI
    //         00433e1e     POP        ESI
    //         00433e1f     RET
}

// Offset: 0x00433E20
void RGE_Command::do_command(void* param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Command::do_command(void *)                                       *
    //                              *********************************************************************************************************
    //                              void __thiscall do_command(RGE_Command * this, void * param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     00433e20(R)  
    //                               ?do_command@RGE_Command@@UAEXPAX@Z                           XREF[2]:     do_command:00509850(c), 
    //                               RGE_Command::do_command                                                   0056f4c8(*)  
    //                              Command.cpp:140 (24)
    //         00433e20     MOV        EAX,dword ptr [ESP + param_1]
    //         00433e24     XOR        EDX,EDX
    //         00433e26     MOV        DL,byte ptr [EAX]
    //         00433e28     CMP        EDX,0x11
    //         00433e2b     JA         switchD_00433e31::caseD_d
    //                               switchD_00433e31::switchD
    //         00433e31     JMP        dword ptr [EDX*0x4 + switchD_00433e31::switchd   = 00433e38
    //                               switchD_00433e31::caseD_0                                    XREF[2]:     00433e31(j), 00433ed0(*)  
    //                              Command.cpp:152 (6)
    //         00433e38     PUSH       EAX
    //         00433e39     CALL       RGE_Command::do_command_order                    void do_command_order(RGE_Command * this, RGE
    //                              Command.cpp:278 (3)
    //         00433e3e     RET        0x4
    //                               switchD_00433e31::caseD_1                                    XREF[2]:     00433e31(j), 00433ed4(*)  
    //                              Command.cpp:159 (6)
    //         00433e41     PUSH       EAX
    //         00433e42     CALL       RGE_Command::do_command_stop                     void do_command_stop(RGE_Command * this, RGE_
    //                              Command.cpp:278 (3)
    //         00433e47     RET        0x4
    //                               switchD_00433e31::caseD_2                                    XREF[2]:     00433e31(j), 00433ed8(*)  
    //                              Command.cpp:166 (6)
    //         00433e4a     PUSH       EAX
    //         00433e4b     CALL       RGE_Command::do_command_work                     void do_command_work(RGE_Command * this, RGE_
    //                              Command.cpp:278 (3)
    //         00433e50     RET        0x4
    //                               switchD_00433e31::caseD_3                                    XREF[2]:     00433e31(j), 00433edc(*)  
    //                              Command.cpp:173 (6)
    //         00433e53     PUSH       EAX
    //         00433e54     CALL       RGE_Command::do_command_move                     void do_command_move(RGE_Command * this, RGE_
    //                              Command.cpp:278 (3)
    //         00433e59     RET        0x4
    //                               switchD_00433e31::caseD_4                                    XREF[2]:     00433e31(j), 00433ee0(*)  
    //                              Command.cpp:180 (6)
    //         00433e5c     PUSH       EAX
    //         00433e5d     CALL       RGE_Command::do_command_create                   void do_command_create(RGE_Command * this, RG
    //                              Command.cpp:278 (3)
    //         00433e62     RET        0x4
    //                               switchD_00433e31::caseD_5                                    XREF[2]:     00433e31(j), 00433ee4(*)  
    //                              Command.cpp:187 (6)
    //         00433e65     PUSH       EAX
    //         00433e66     CALL       RGE_Command::do_command_add_attribute            void do_command_add_attribute(RGE_Command * t
    //                              Command.cpp:278 (3)
    //         00433e6b     RET        0x4
    //                               switchD_00433e31::caseD_6                                    XREF[2]:     00433e31(j), 00433ee8(*)  
    //                              Command.cpp:194 (6)
    //         00433e6e     PUSH       EAX
    //         00433e6f     CALL       RGE_Command::do_command_formation                void do_command_formation(RGE_Command * this,
    //                              Command.cpp:278 (3)
    //         00433e74     RET        0x4
    //                               switchD_00433e31::caseD_7                                    XREF[2]:     00433e31(j), 00433eec(*)  
    //                              Command.cpp:201 (5)
    //         00433e77     MOV        EDX,dword ptr [this->_padding_]
    //         00433e79     PUSH       EAX
    //         00433e7a     CALL       dword ptr [EDX]
    //                              Command.cpp:278 (3)
    //         00433e7c     RET        0x4
    //                               switchD_00433e31::caseD_8                                    XREF[2]:     00433e31(j), 00433ef0(*)  
    //                              Command.cpp:208 (6)
    //         00433e7f     PUSH       EAX
    //         00433e80     CALL       RGE_Command::do_command_create_group             void do_command_create_group(RGE_Command * th
    //                              Command.cpp:278 (3)
    //         00433e85     RET        0x4
    //                               switchD_00433e31::caseD_9                                    XREF[2]:     00433e31(j), 00433ef4(*)  
    //                              Command.cpp:215 (6)
    //         00433e88     PUSH       EAX
    //         00433e89     CALL       RGE_Command::do_command_destroy_group            void do_command_destroy_group(RGE_Command * t
    //                              Command.cpp:278 (3)
    //         00433e8e     RET        0x4
    //                               switchD_00433e31::caseD_a                                    XREF[2]:     00433e31(j), 00433ef8(*)  
    //                              Command.cpp:222 (6)
    //         00433e91     PUSH       EAX
    //         00433e92     CALL       RGE_Command::do_command_ai_order                 void do_command_ai_order(RGE_Command * this, 
    //                              Command.cpp:278 (3)
    //         00433e97     RET        0x4
    //                               switchD_00433e31::caseD_11                                   XREF[2]:     00433e31(j), 00433f14(*)  
    //                              Command.cpp:229 (6)
    //         00433e9a     PUSH       EAX
    //         00433e9b     CALL       RGE_Command::do_command_group_ai_order           void do_command_group_ai_order(RGE_Command * 
    //                              Command.cpp:278 (3)
    //         00433ea0     RET        0x4
    //                               switchD_00433e31::caseD_b                                    XREF[2]:     00433e31(j), 00433efc(*)  
    //                              Command.cpp:236 (6)
    //         00433ea3     PUSH       EAX
    //         00433ea4     CALL       RGE_Command::do_command_resign                   void do_command_resign(RGE_Command * this, RG
    //                              Command.cpp:278 (3)
    //         00433ea9     RET        0x4
    //                               switchD_00433e31::caseD_c                                    XREF[2]:     00433e31(j), 00433f00(*)  
    //                              Command.cpp:243 (6)
    //         00433eac     PUSH       EAX
    //         00433ead     CALL       RGE_Command::do_command_add_waypoint             void do_command_add_waypoint(RGE_Command * th
    //                              Command.cpp:278 (3)
    //         00433eb2     RET        0x4
    //                               switchD_00433e31::caseD_10                                   XREF[2]:     00433e31(j), 00433f10(*)  
    //                              Command.cpp:250 (6)
    //         00433eb5     PUSH       EAX
    //         00433eb6     CALL       RGE_Command::do_command_group_waypoint           void do_command_group_waypoint(RGE_Command * 
    //                              Command.cpp:278 (3)
    //         00433ebb     RET        0x4
    //                               switchD_00433e31::caseD_e                                    XREF[2]:     00433e31(j), 00433f08(*)  
    //                              Command.cpp:257 (6)
    //         00433ebe     PUSH       EAX
    //         00433ebf     CALL       RGE_Command::do_command_add_to_group             void do_command_add_to_group(RGE_Command * th
    //                              Command.cpp:278 (3)
    //         00433ec4     RET        0x4
    //                               switchD_00433e31::caseD_f                                    XREF[2]:     00433e31(j), 00433f0c(*)  
    //                              Command.cpp:264 (6)
    //         00433ec7     PUSH       EAX
    //         00433ec8     CALL       RGE_Command::do_command_remove_from_group        void do_command_remove_from_group(RGE_Command
    //                               switchD_00433e31::caseD_d                                    XREF[3]:     00433e2b(j), 00433e31(j), 
    //                                                                                                         00433f04(*)  
    //                              Command.cpp:278 (75)
    //         00433ecd     RET        0x4
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00433e31::switchdataD_00433ed0                       XREF[1]:     do_command:00433e31(*)  
}

// Offset: 0x00433F20
void do_command_order(RGE_Command* this_, RGE_Command_Order* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall RGE_Command::do_command_order(struct RGE_Command_Order *)                  *
    //                              *********************************************************************************************************
    //                              void __thiscall do_command_order(RGE_Command * this, RGE_Command_Ord
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              RGE_Command_Or    Stack[0x4]:4   param_1                   XREF[1]:     00433f23(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00433f4d(W)  
    //              RGE_Static_Obj    Stack[-0x8]:4  target                    XREF[1]:     00433f39(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     00433f41(W), 0043401d(R)  
    //              RGE_Obj_Info *    Stack[-0x10]:4 units                     XREF[10]:    00433f69(W), 00433fd0(R), 00433fde(W), 0043403e(R), 
    //                                                                                     00434065(W), 004341cc(R), 004341da(W), 004341f4(W), 
    //                                                                                     0043426e(R), 0043427c(W)  
    //              int               Stack[-0x14]:4 i                         XREF[10]:    00433f71(W), 00433fe7(R), 00433ff5(W), 0043403a(R), 
    //                                                                                     00434081(W), 004341d0(R), 004341de(W), 00434202(W), 
    //                                                                                     00434272(R), 00434280(W)  
    //              float             Stack[-0x18]:4 maxY                      XREF[5]:     00433f81(W), 00433ff9(R), 0043400f(W), 00434057(R), 
    //                                                                                     00434075(W)  
    //              float             Stack[-0x1c]:4 totalY                    XREF[5]:     00433f79(W), 00433ffd(R), 0043400b(W), 0043405b(R), 
    //                                                                                     00434071(W)  
    //              float             Stack[-0x20]:4 totalX                    XREF[2]:     00433f3d(W), 00434053(R)  
    //              int               Stack[-0x24]:4 unit_num                  XREF[4]:     00433f61(W), 00433fbb(R), 00433fc9(W), 00434021(R)  
    //              float             Stack[-0x28]:4 adjustedXLocation         XREF[4]:     00433f59(W), 00433fa4(R), 00433fb2(W), 00434025(R)  
    //              float             Stack[-0x2c]:4 adjustedYLocation
    //                               ?do_command_order@RGE_Command@@IAEXPAURGE_Command_Order@@@Z  XREF[1]:     do_command:00433e39(c)  
    //                               RGE_Command::do_command_order
    //                              Command.cpp:283 (3)
    //         00433f20     SUB        ESP,0x28
    //                              Command.cpp:288 (12)
    //         00433f23     MOV        EAX,dword ptr [ESP + param_1]
    //         00433f27     PUSH       EBX
    //         00433f28     PUSH       EBP
    //         00433f29     XOR        EBX,EBX
    //         00433f2b     MOV        BL,byte ptr [EAX + 0x8]
    //         00433f2e     PUSH       ESI
    //                              Command.cpp:289 (3)
    //         00433f2f     LEA        ESI,[EAX + 0x14]
    //                              Command.cpp:291 (24)
    //         00433f32     MOV        EAX,dword ptr [EAX + 0x4]
    //         00433f35     PUSH       EDI
    //         00433f36     MOV        EDI,this
    //         00433f38     PUSH       EAX
    //         00433f39     MOV        dword ptr [ESP + target],EDI
    //         00433f3d     MOV        dword ptr [ESP + totalX],EBX
    //         00433f41     MOV        dword ptr [ESP + local_c],ESI
    //         00433f45     CALL       RGE_Command::get_obj                             RGE_Static_Object * get_obj(RGE_Command * thi
    //                              Command.cpp:294 (13)
    //         00433f4a     CMP        EBX,0x1
    //         00433f4d     MOV        dword ptr [ESP + local_4],EAX
    //         00433f51     JLE        LAB_004341f2
    //                              Command.cpp:305 (56)
    //         00433f57     TEST       EBX,EBX
    //         00433f59     MOV        dword ptr [ESP + adjustedXLocation],0x461c4000
    //         00433f61     MOV        dword ptr [ESP + unit_num],0x0
    //         00433f69     MOV        dword ptr [ESP + units],0x461c4000
    //         00433f71     MOV        dword ptr [ESP + i],0x0
    //         00433f79     MOV        dword ptr [ESP + totalY],0x0
    //         00433f81     MOV        dword ptr [ESP + maxY],0x0
    //         00433f89     JLE        LAB_00434021
    //                              Command.cpp:420 (2)
    //         00433f8f     MOV        EBP,EBX
    //                               LAB_00433f91                                                 XREF[1]:     00434017(j)  
    //                              Command.cpp:307 (12)
    //         00433f91     MOV        this,dword ptr [ESI]
    //         00433f93     PUSH       this
    //         00433f94     MOV        this,EDI
    //         00433f96     CALL       RGE_Command::get_obj                             RGE_Static_Object * get_obj(RGE_Command * thi
    //         00433f9b     MOV        this,EAX
    //                              Command.cpp:308 (4)
    //         00433f9d     TEST       this,this
    //         00433f9f     JZ         LAB_00434013
    //                              Command.cpp:316 (14)
    //         00433fa1     FLD        float ptr [this->_padding_ + 0x38]
    //         00433fa4     FCOMP      float ptr [ESP + adjustedXLocation]
    //         00433fa8     FNSTSW     AX
    //         00433faa     TEST       AH,0x1
    //         00433fad     JZ         LAB_00433fb8
    //                              Command.cpp:317 (7)
    //         00433faf     MOV        EDX,dword ptr [this->_padding_ + 0x38]
    //         00433fb2     MOV        dword ptr [ESP + adjustedXLocation],EDX
    //                              Command.cpp:318 (16)
    //         00433fb6     JMP        LAB_00433fcd
    //                               LAB_00433fb8                                                 XREF[1]:     00433fad(j)  
    //         00433fb8     FLD        float ptr [this->_padding_ + 0x38]
    //         00433fbb     FCOMP      float ptr [ESP + unit_num]
    //         00433fbf     FNSTSW     AX
    //         00433fc1     TEST       AH,0x41
    //         00433fc4     JNZ        LAB_00433fcd
    //                              Command.cpp:319 (7)
    //         00433fc6     MOV        EAX,dword ptr [this->_padding_ + 0x38]
    //         00433fc9     MOV        dword ptr [ESP + unit_num],EAX
    //                               LAB_00433fcd                                                 XREF[2]:     00433fb6(j), 00433fc4(j)  
    //                              Command.cpp:320 (14)
    //         00433fcd     FLD        float ptr [this->_padding_ + 0x3c]
    //         00433fd0     FCOMP      float ptr [ESP + units]
    //         00433fd4     FNSTSW     AX
    //         00433fd6     TEST       AH,0x1
    //         00433fd9     JZ         LAB_00433fe4
    //                              Command.cpp:321 (7)
    //         00433fdb     MOV        EDX,dword ptr [this->_padding_ + 0x3c]
    //         00433fde     MOV        dword ptr [ESP + units],EDX
    //                              Command.cpp:322 (16)
    //         00433fe2     JMP        LAB_00433ff9
    //                               LAB_00433fe4                                                 XREF[1]:     00433fd9(j)  
    //         00433fe4     FLD        float ptr [this->_padding_ + 0x3c]
    //         00433fe7     FCOMP      float ptr [ESP + i]
    //         00433feb     FNSTSW     AX
    //         00433fed     TEST       AH,0x41
    //         00433ff0     JNZ        LAB_00433ff9
    //                              Command.cpp:323 (7)
    //         00433ff2     MOV        EAX,dword ptr [this->_padding_ + 0x3c]
    //         00433ff5     MOV        dword ptr [ESP + i],EAX
    //                               LAB_00433ff9                                                 XREF[2]:     00433fe2(j), 00433ff0(j)  
    //                              Command.cpp:326 (36)
    //         00433ff9     FLD        float ptr [ESP + maxY]
    //         00433ffd     FLD        float ptr [ESP + totalY]
    //         00434001     FADD       float ptr [this->_padding_ + 0x38]
    //         00434004     FXCH
    //         00434006     FADD       float ptr [this->_padding_ + 0x3c]
    //         00434009     FXCH
    //         0043400b     FSTP       float ptr [ESP + totalY]
    //         0043400f     FSTP       float ptr [ESP + maxY]
    //                               LAB_00434013                                                 XREF[1]:     00433f9f(j)  
    //         00434013     ADD        ESI,0x4
    //         00434016     DEC        EBP
    //         00434017     JNZ        LAB_00433f91
    //                              Command.cpp:305 (4)
    //         0043401d     MOV        ESI,dword ptr [ESP + local_c]
    //                               LAB_00434021                                                 XREF[1]:     00433f89(j)  
    //                              Command.cpp:331 (50)
    //         00434021     FLD        float ptr [ESP + unit_num]
    //         00434025     FSUB       float ptr [ESP + adjustedXLocation]
    //         00434029     FCOMP      double ptr [DAT_0056f4d8]
    //         0043402f     FNSTSW     AX
    //         00434031     TEST       AH,0x41
    //         00434034     JZ         LAB_004341f2
    //         0043403a     FLD        float ptr [ESP + i]
    //         0043403e     FSUB       float ptr [ESP + units]
    //         00434042     FCOMP      double ptr [DAT_0056f4d8]
    //         00434048     FNSTSW     AX
    //         0043404a     TEST       AH,0x41
    //         0043404d     JZ         LAB_004341f2
    //                              Command.cpp:336 (4)
    //         00434053     FILD       dword ptr [ESP + totalX]
    //                              Command.cpp:337 (12)
    //         00434057     FLD        float ptr [ESP + maxY]
    //         0043405b     FLD        float ptr [ESP + totalY]
    //         0043405f     FDIV       ST0,ST2
    //         00434061     FXCH
    //                              Command.cpp:342 (30)
    //         00434063     TEST       EBX,EBX
    //         00434065     MOV        dword ptr [ESP + units],0x0
    //         0043406d     FDIV       ST0,ST2
    //         0043406f     FXCH
    //         00434071     FSTP       float ptr [ESP + totalY]
    //         00434075     FSTP       float ptr [ESP + maxY]
    //         00434079     FSTP       ST0
    //         0043407b     JLE        LAB_00434286
    //                              Command.cpp:420 (4)
    //         00434081     MOV        dword ptr [ESP + i],ESI
    //                               LAB_00434085                                                 XREF[1]:     004341e2(j)  
    //                              Command.cpp:344 (12)
    //         00434085     MOV        this,dword ptr [ESI]
    //         00434087     PUSH       this
    //         00434088     MOV        this,EDI
    //         0043408a     CALL       RGE_Command::get_obj                             RGE_Static_Object * get_obj(RGE_Command * thi
    //         0043408f     MOV        ESI,EAX
    //                              Command.cpp:345 (8)
    //         00434091     TEST       ESI,ESI
    //         00434093     JZ         LAB_004341cc
    //                              Command.cpp:350 (7)
    //         00434099     MOV        this,ESI
    //         0043409b     CALL       RGE_Static_Object::removeAllFromPathingGroup     void removeAllFromPathingGroup(RGE_Static_Obj
    //                              Command.cpp:351 (12)
    //         004340a0     MOV        EBP,dword ptr [ESI]
    //         004340a2     PUSH       0x1
    //         004340a4     MOV        this,ESI
    //         004340a6     CALL       dword ptr [EBP + 0x12c]
    //                              Command.cpp:420 (85)
    //         004340ac     MOV        EBX,dword ptr [ESP + 0x2c]
    //         004340b0     XOR        EDI,EDI
    //                               LAB_004340b2                                                 XREF[1]:     004340cc(j)  
    //         004340b2     CMP        EDI,dword ptr [ESP + 0x28]
    //         004340b6     JZ         LAB_004340c2
    //         004340b8     MOV        EDX,dword ptr [EBX]
    //         004340ba     MOV        this,ESI
    //         004340bc     PUSH       EDX
    //         004340bd     CALL       RGE_Static_Object::addToPathingGroup             void addToPathingGroup(RGE_Static_Object * th
    //                               LAB_004340c2                                                 XREF[1]:     004340b6(j)  
    //         004340c2     MOV        EAX,dword ptr [ESP + 0x18]
    //         004340c6     INC        EDI
    //         004340c7     ADD        EBX,0x4
    //         004340ca     CMP        EDI,EAX
    //         004340cc     JL         LAB_004340b2
    //         004340ce     FLD        float ptr [ESI + 0x38]
    //         004340d1     FSUB       float ptr [ESP + 0x1c]
    //         004340d5     FLD        float ptr [ESI + 0x3c]
    //         004340d8     FSUB       float ptr [ESP + 0x20]
    //         004340dc     FXCH
    //         004340de     MOV        EAX,dword ptr [ESP + 0x3c]
    //         004340e2     FADD       float ptr [EAX + 0xc]
    //         004340e5     FXCH
    //         004340e7     FADD       float ptr [EAX + 0x10]
    //         004340ea     FXCH
    //         004340ec     FST        float ptr [ESP + 0x14]
    //         004340f0     FCOMP      double ptr [DAT_0056f4e0]
    //         004340f6     FSTP       float ptr [ESP + 0x10]
    //         004340fa     FNSTSW     AX
    //         004340fc     TEST       AH,0x1
    //         004340ff     JZ         LAB_0043410b
    //                              Command.cpp:367 (8)
    //         00434101     MOV        dword ptr [ESP + 0x14],0x3f800000
    //                              Command.cpp:368 (27)
    //         00434109     JMP        LAB_00434132
    //                               LAB_0043410b                                                 XREF[1]:     004340ff(j)  
    //         0043410b     MOV        EAX,dword ptr [ESI + 0xc]
    //         0043410e     MOV        this,dword ptr [EAX + 0x3c]
    //         00434111     MOV        EDX,dword ptr [this->_padding_ + 0x28]
    //         00434114     FILD       dword ptr [EDX + 0x8]
    //         00434117     FLD        float ptr [ESP + 0x14]
    //         0043411b     FCOMP
    //         0043411d     FNSTSW     AX
    //         0043411f     TEST       AH,0x1
    //         00434122     JNZ        LAB_00434130
    //                              Command.cpp:369 (12)
    //         00434124     FSUB       float ptr [DAT_0056f4e8]
    //         0043412a     FSTP       float ptr [ESP + 0x14]
    //         0043412e     JMP        LAB_00434132
    //                               LAB_00434130                                                 XREF[1]:     00434122(j)  
    //                              Command.cpp:368 (2)
    //         00434130     FSTP       ST0
    //                               LAB_00434132                                                 XREF[2]:     00434109(j), 0043412e(j)  
    //                              Command.cpp:370 (17)
    //         00434132     FLD        float ptr [ESP + 0x10]
    //         00434136     FCOMP      double ptr [DAT_0056f4e0]
    //         0043413c     FNSTSW     AX
    //         0043413e     TEST       AH,0x1
    //         00434141     JZ         LAB_0043414d
    //                              Command.cpp:371 (8)
    //         00434143     MOV        dword ptr [ESP + 0x10],0x3f800000
    //                              Command.cpp:372 (27)
    //         0043414b     JMP        LAB_00434174
    //                               LAB_0043414d                                                 XREF[1]:     00434141(j)  
    //         0043414d     MOV        EAX,dword ptr [ESI + 0xc]
    //         00434150     MOV        this,dword ptr [EAX + 0x3c]
    //         00434153     MOV        EDX,dword ptr [this->_padding_ + 0x28]
    //         00434156     FILD       dword ptr [EDX + 0xc]
    //         00434159     FLD        float ptr [ESP + 0x10]
    //         0043415d     FCOMP
    //         0043415f     FNSTSW     AX
    //         00434161     TEST       AH,0x1
    //         00434164     JNZ        LAB_00434172
    //                              Command.cpp:373 (12)
    //         00434166     FSUB       float ptr [DAT_0056f4e8]
    //         0043416c     FSTP       float ptr [ESP + 0x10]
    //         00434170     JMP        LAB_00434174
    //                               LAB_00434172                                                 XREF[1]:     00434164(j)  
    //                              Command.cpp:372 (2)
    //         00434172     FSTP       ST0
    //                               LAB_00434174                                                 XREF[2]:     0043414b(j), 00434170(j)  
    //                              Command.cpp:385 (43)
    //         00434174     MOV        this,dword ptr [ESP + 0x34]
    //         00434178     TEST       this,this
    //         0043417a     JZ         LAB_004341ae
    //         0043417c     MOV        EDX,dword ptr [ECX + this->last_order]
    //         0043417f     FLD        float ptr [EDX + 0x30]
    //         00434182     FCOMP      double ptr [DAT_0056f4e0]
    //         00434188     FNSTSW     AX
    //         0043418a     TEST       AH,0x41
    //         0043418d     JZ         LAB_0043419f
    //         0043418f     FLD        float ptr [EDX + 0x34]
    //         00434192     FCOMP      double ptr [DAT_0056f4e0]
    //         00434198     FNSTSW     AX
    //         0043419a     TEST       AH,0x41
    //         0043419d     JNZ        LAB_004341ae
    //                               LAB_0043419f                                                 XREF[1]:     0043418d(j)  
    //                              Command.cpp:386 (13)
    //         0043419f     MOV        EAX,dword ptr [ESP + 0x10]
    //         004341a3     MOV        EDX,dword ptr [ESP + 0x14]
    //         004341a7     PUSH       0x0
    //         004341a9     PUSH       EAX
    //         004341aa     PUSH       EDX
    //         004341ab     PUSH       this
    //                              Command.cpp:387 (2)
    //         004341ac     JMP        LAB_004341bc
    //                               LAB_004341ae                                                 XREF[2]:     0043417a(j), 0043419d(j)  
    //                              Command.cpp:388 (58)
    //         004341ae     MOV        EAX,dword ptr [ESP + 0x10]
    //         004341b2     MOV        this,dword ptr [ESP + 0x14]
    //         004341b6     PUSH       0x0
    //         004341b8     PUSH       EAX
    //         004341b9     PUSH       this
    //         004341ba     PUSH       0x0
    //                               LAB_004341bc                                                 XREF[1]:     004341ac(j)  
    //         004341bc     MOV        this,ESI
    //         004341be     CALL       dword ptr [EBP + 0x98]
    //         004341c4     MOV        EBX,dword ptr [ESP + 0x18]
    //         004341c8     MOV        EDI,dword ptr [ESP + 0x30]
    //                               LAB_004341cc                                                 XREF[1]:     00434093(j)  
    //         004341cc     MOV        EAX,dword ptr [ESP + units]
    //         004341d0     MOV        ESI,dword ptr [ESP + i]
    //         004341d4     INC        EAX
    //         004341d5     ADD        ESI,0x4
    //         004341d8     CMP        EAX,EBX
    //         004341da     MOV        dword ptr [ESP + units],EAX
    //         004341de     MOV        dword ptr [ESP + i],ESI
    //         004341e2     JL         LAB_00434085
    //                              Command.cpp:420 (10)
    //         004341e8     POP        EDI
    //         004341e9     POP        ESI
    //         004341ea     POP        EBP
    //         004341eb     POP        EBX
    //         004341ec     ADD        ESP,0x28
    //         004341ef     RET        0x4
    //                               LAB_004341f2                                                 XREF[3]:     00433f51(j), 00434034(j), 
    //                                                                                                         0043404d(j)  
    //                              Command.cpp:396 (20)
    //         004341f2     TEST       EBX,EBX
    //         004341f4     MOV        dword ptr [ESP + units],0x0
    //         004341fc     JLE        LAB_00434286
    //         00434202     MOV        dword ptr [ESP + i],ESI
    //                               LAB_00434206                                                 XREF[1]:     00434284(j)  
    //                              Command.cpp:398 (12)
    //         00434206     MOV        EDX,dword ptr [ESI]
    //         00434208     MOV        this,EDI
    //         0043420a     PUSH       EDX
    //         0043420b     CALL       RGE_Command::get_obj                             RGE_Static_Object * get_obj(RGE_Command * thi
    //         00434210     MOV        ESI,EAX
    //                              Command.cpp:399 (4)
    //         00434212     TEST       ESI,ESI
    //         00434214     JZ         LAB_0043426e
    //                              Command.cpp:404 (7)
    //         00434216     MOV        this,ESI
    //         00434218     CALL       RGE_Static_Object::removeAllFromPathingGroup     void removeAllFromPathingGroup(RGE_Static_Obj
    //                              Command.cpp:405 (12)
    //         0043421d     MOV        EBP,dword ptr [ESI]
    //         0043421f     PUSH       0x1
    //         00434221     MOV        this,ESI
    //         00434223     CALL       dword ptr [EBP + 0x12c]
    //                              Command.cpp:420 (103)
    //         00434229     MOV        EBX,dword ptr [ESP + 0x2c]
    //         0043422d     XOR        EDI,EDI
    //                               LAB_0043422f                                                 XREF[1]:     00434249(j)  
    //         0043422f     CMP        EDI,dword ptr [ESP + 0x28]
    //         00434233     JZ         LAB_0043423f
    //         00434235     MOV        EAX,dword ptr [EBX]
    //         00434237     MOV        this,ESI
    //         00434239     PUSH       EAX
    //         0043423a     CALL       RGE_Static_Object::addToPathingGroup             void addToPathingGroup(RGE_Static_Object * th
    //                               LAB_0043423f                                                 XREF[1]:     00434233(j)  
    //         0043423f     MOV        EAX,dword ptr [ESP + 0x18]
    //         00434243     INC        EDI
    //         00434244     ADD        EBX,0x4
    //         00434247     CMP        EDI,EAX
    //         00434249     JL         LAB_0043422f
    //         0043424b     MOV        EAX,dword ptr [ESP + 0x3c]
    //         0043424f     PUSH       0x0
    //         00434251     MOV        this,dword ptr [EAX + 0x10]
    //         00434254     MOV        EDX,dword ptr [EAX + 0xc]
    //         00434257     MOV        EAX,dword ptr [ESP + 0x38]
    //         0043425b     PUSH       this
    //         0043425c     PUSH       EDX
    //         0043425d     PUSH       EAX
    //         0043425e     MOV        this,ESI
    //         00434260     CALL       dword ptr [EBP + 0x98]
    //         00434266     MOV        EBX,dword ptr [ESP + 0x18]
    //         0043426a     MOV        EDI,dword ptr [ESP + 0x30]
    //                               LAB_0043426e                                                 XREF[1]:     00434214(j)  
    //         0043426e     MOV        EAX,dword ptr [ESP + units]
    //         00434272     MOV        ESI,dword ptr [ESP + i]
    //         00434276     INC        EAX
    //         00434277     ADD        ESI,0x4
    //         0043427a     CMP        EAX,EBX
    //         0043427c     MOV        dword ptr [ESP + units],EAX
    //         00434280     MOV        dword ptr [ESP + i],ESI
    //         00434284     JL         LAB_00434206
    //                               LAB_00434286                                                 XREF[2]:     0043407b(j), 004341fc(j)  
    //         00434286     POP        EDI
    //         00434287     POP        ESI
    //         00434288     POP        EBP
    //         00434289     POP        EBX
    //         0043428a     ADD        ESP,0x28
    //         0043428d     RET        0x4
}

// Offset: 0x00434290
void do_command_stop(RGE_Command* this_, RGE_Command_Stop* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall RGE_Command::do_command_stop(struct RGE_Command_Stop *)                    *
    //                              *********************************************************************************************************
    //                              void __thiscall do_command_stop(RGE_Command * this, RGE_Command_Stop
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              RGE_Command_St    Stack[0x4]:4   param_1                   XREF[1]:     00434293(R)  
    //                               ?do_command_stop@RGE_Command@@IAEXPAURGE_Command_Stop@@@Z    XREF[1]:     do_command:00433e42(c)  
    //                               RGE_Command::do_command_stop
    //                              Command.cpp:425 (3)
    //         00434290     PUSH       EBX
    //         00434291     MOV        EBX,this
    //                              Command.cpp:428 (10)
    //         00434293     MOV        this,dword ptr [ESP + param_1]
    //         00434297     XOR        EAX,EAX
    //         00434299     PUSH       EDI
    //         0043429a     MOV        AL,byte ptr [ECX + this+0x1]
    //                              Command.cpp:429 (3)
    //         0043429d     LEA        EDI,[ECX + this+0x2]
    //                              Command.cpp:431 (8)
    //         004342a0     TEST       EAX,EAX
    //         004342a2     JLE        LAB_004342d1
    //         004342a4     PUSH       ESI
    //         004342a5     PUSH       EBP
    //         004342a6     MOV        EBP,EAX
    //                               LAB_004342a8                                                 XREF[1]:     004342cd(j)  
    //                              Command.cpp:435 (12)
    //         004342a8     MOV        EAX,dword ptr [EDI]
    //         004342aa     MOV        this,EBX
    //         004342ac     PUSH       EAX
    //         004342ad     CALL       RGE_Command::get_obj                             RGE_Static_Object * get_obj(RGE_Command * thi
    //         004342b2     MOV        ESI,EAX
    //                              Command.cpp:436 (4)
    //         004342b4     TEST       ESI,ESI
    //         004342b6     JZ         LAB_004342c9
    //                              Command.cpp:438 (7)
    //         004342b8     MOV        this,ESI
    //         004342ba     CALL       RGE_Static_Object::removeAllFromPathingGroup     void removeAllFromPathingGroup(RGE_Static_Obj
    //                              Command.cpp:439 (18)
    //         004342bf     MOV        EDX,dword ptr [ESI]
    //         004342c1     MOV        this,ESI
    //         004342c3     CALL       dword ptr [EDX + 0xa4]
    //                               LAB_004342c9                                                 XREF[1]:     004342b6(j)  
    //         004342c9     ADD        EDI,0x4
    //         004342cc     DEC        EBP
    //         004342cd     JNZ        LAB_004342a8
    //         004342cf     POP        EBP
    //         004342d0     POP        ESI
    //                               LAB_004342d1                                                 XREF[1]:     004342a2(j)  
    //                              Command.cpp:442 (5)
    //         004342d1     POP        EDI
    //         004342d2     POP        EBX
    //         004342d3     RET        0x4
}

// Offset: 0x004342E0
void do_command_pause(RGE_Command* this_, RGE_Command_Pause* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall RGE_Command::do_command_pause(struct RGE_Command_Pause *)                  *
    //                              *********************************************************************************************************
    //                              void __thiscall do_command_pause(RGE_Command * this, RGE_Command_Pau
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              RGE_Command_Pa    Stack[0x4]:4   param_1                   XREF[1]:     004342e6(R)  
    //                               ?do_command_pause@RGE_Command@@IAEXPAURGE_Command_Pause@@@Z
    //                               RGE_Command::do_command_pause
    //                              Command.cpp:447 (4)
    //         004342e0     PUSH       ESI
    //         004342e1     PUSH       EDI
    //         004342e2     MOV        EDI,this
    //                              Command.cpp:450 (9)
    //         004342e4     XOR        EAX,EAX
    //         004342e6     MOV        this,dword ptr [ESP + param_1]
    //         004342ea     MOV        AL,byte ptr [ECX + this+0x1]
    //                              Command.cpp:451 (3)
    //         004342ed     LEA        ESI,[ECX + this+0x2]
    //                              Command.cpp:453 (7)
    //         004342f0     TEST       EAX,EAX
    //         004342f2     JLE        LAB_00434316
    //         004342f4     PUSH       EBX
    //         004342f5     MOV        EBX,EAX
    //                               LAB_004342f7                                                 XREF[1]:     00434313(j)  
    //                              Command.cpp:457 (10)
    //         004342f7     MOV        EAX,dword ptr [ESI]
    //         004342f9     MOV        this,EDI
    //         004342fb     PUSH       EAX
    //         004342fc     CALL       RGE_Command::get_obj                             RGE_Static_Object * get_obj(RGE_Command * thi
    //                              Command.cpp:458 (4)
    //         00434301     TEST       EAX,EAX
    //         00434303     JZ         LAB_0043430f
    //                              Command.cpp:459 (16)
    //         00434305     MOV        EDX,dword ptr [EAX]
    //         00434307     MOV        this,EAX
    //         00434309     CALL       dword ptr [EDX + 0x190]
    //                               LAB_0043430f                                                 XREF[1]:     00434303(j)  
    //         0043430f     ADD        ESI,0x4
    //         00434312     DEC        EBX
    //         00434313     JNZ        LAB_004342f7
    //                              Command.cpp:447 (1)
    //         00434315     POP        EBX
    //                               LAB_00434316                                                 XREF[1]:     004342f2(j)  
    //                              Command.cpp:461 (5)
    //         00434316     POP        EDI
    //         00434317     POP        ESI
    //         00434318     RET        0x4
}

// Offset: 0x00434320
void do_command_work(RGE_Command* this_, RGE_Command_Order* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall RGE_Command::do_command_work(struct RGE_Command_Order *)                   *
    //                              *********************************************************************************************************
    //                              void __thiscall do_command_work(RGE_Command * this, RGE_Command_Orde
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              RGE_Command_Or    Stack[0x4]:4   param_1                   XREF[1]:     00434323(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00434344(W)  
    //              RGE_Obj_Info *    Stack[-0x8]:4  units                     XREF[1]:     0043433c(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0043434f(W)  
    //              RGE_Static_Obj    Stack[-0x10]:4 target                    XREF[1]:     00434340(W)  
    //              int               Stack[-0x14]:4 unit_num                  XREF[4]:     00434362(W), 00434366(R), 004343d6(R), 004343e4(W)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[3]:     00434353(W), 004343d2(R), 004343e0(W)  
    //              int               Stack[-0x1c]:4 index
    //                               ?do_command_work@RGE_Command@@IAEXPAURGE_Command_Order@@@Z   XREF[1]:     do_command:00433e4b(c)  
    //                               RGE_Command::do_command_work
    //                              Command.cpp:466 (3)
    //         00434320     SUB        ESP,0x18
    //                              Command.cpp:469 (7)
    //         00434323     MOV        EAX,dword ptr [ESP + param_1]
    //         00434327     PUSH       EBX
    //         00434328     PUSH       EBP
    //         00434329     PUSH       EDI
    //                              Command.cpp:471 (35)
    //         0043432a     MOV        EDX,dword ptr [EAX + 0x4]
    //         0043432d     MOV        EDI,this
    //         0043432f     XOR        this,this
    //         00434331     LEA        EBX,[EAX + 0x14]
    //         00434334     MOV        this,byte ptr [EAX + 0x8]
    //         00434337     PUSH       EDX
    //         00434338     MOV        EBP,this
    //         0043433a     MOV        this,EDI
    //         0043433c     MOV        dword ptr [ESP + units],EDI
    //         00434340     MOV        dword ptr [ESP + target],EBP
    //         00434344     MOV        dword ptr [ESP + local_4],EBX
    //         00434348     CALL       RGE_Command::get_obj                             RGE_Static_Object * get_obj(RGE_Command * thi
    //                              Command.cpp:473 (25)
    //         0043434d     TEST       EBP,EBP
    //         0043434f     MOV        dword ptr [ESP + local_c],EAX
    //         00434353     MOV        dword ptr [ESP + local_18],0x0
    //         0043435b     JLE        LAB_004343ef
    //         00434361     PUSH       ESI
    //         00434362     MOV        dword ptr [ESP + unit_num],EBX
    //                               LAB_00434366                                                 XREF[1]:     004343e8(j)  
    //                              Command.cpp:477 (16)
    //         00434366     MOV        EAX,dword ptr [ESP + unit_num]
    //         0043436a     MOV        this,dword ptr [EAX]
    //         0043436c     PUSH       this
    //         0043436d     MOV        this,EDI
    //         0043436f     CALL       RGE_Command::get_obj                             RGE_Static_Object * get_obj(RGE_Command * thi
    //         00434374     MOV        ESI,EAX
    //                              Command.cpp:478 (4)
    //         00434376     TEST       ESI,ESI
    //         00434378     JZ         LAB_004343d2
    //                              Command.cpp:482 (7)
    //         0043437a     MOV        this,ESI
    //         0043437c     CALL       RGE_Static_Object::removeAllFromPathingGroup     void removeAllFromPathingGroup(RGE_Static_Obj
    //                              Command.cpp:483 (12)
    //         00434381     MOV        EBP,dword ptr [ESI]
    //         00434383     PUSH       0x1
    //         00434385     MOV        this,ESI
    //         00434387     CALL       dword ptr [EBP + 0x12c]
    //                              Command.cpp:484 (2)
    //         0043438d     XOR        EDI,EDI
    //                               LAB_0043438f                                                 XREF[1]:     004343a9(j)  
    //                              Command.cpp:486 (6)
    //         0043438f     CMP        EDI,dword ptr [ESP + 0x10]
    //         00434393     JZ         LAB_0043439f
    //                              Command.cpp:488 (22)
    //         00434395     MOV        EDX,dword ptr [EBX]
    //         00434397     MOV        this,ESI
    //         00434399     PUSH       EDX
    //         0043439a     CALL       RGE_Static_Object::addToPathingGroup             void addToPathingGroup(RGE_Static_Object * th
    //                               LAB_0043439f                                                 XREF[1]:     00434393(j)  
    //         0043439f     MOV        EAX,dword ptr [ESP + 0x18]
    //         004343a3     INC        EDI
    //         004343a4     ADD        EBX,0x4
    //         004343a7     CMP        EDI,EAX
    //         004343a9     JL         LAB_0043438f
    //                              Command.cpp:491 (67)
    //         004343ab     MOV        EAX,dword ptr [ESP + 0x2c]
    //         004343af     PUSH       0x0
    //         004343b1     MOV        this,dword ptr [EAX + 0x10]
    //         004343b4     MOV        EDX,dword ptr [EAX + 0xc]
    //         004343b7     MOV        EAX,dword ptr [ESP + 0x20]
    //         004343bb     PUSH       this=>DAT_fffffff8
    //         004343bc     PUSH       EDX=>DAT_fffffff4
    //         004343bd     PUSH       EAX=>DAT_fffffff0
    //         004343be     MOV        this,ESI
    //         004343c0     CALL       dword ptr [EBP + 0xa0]
    //         004343c6     MOV        EDI,dword ptr [ESP + 0x20]
    //         004343ca     MOV        EBP,dword ptr [ESP + 0x18]
    //         004343ce     MOV        EBX,dword ptr [ESP + 0x24]
    //                               LAB_004343d2                                                 XREF[1]:     00434378(j)  
    //         004343d2     MOV        EAX,dword ptr [ESP + local_18]
    //         004343d6     MOV        EDX,dword ptr [ESP + unit_num]
    //         004343da     INC        EAX
    //         004343db     ADD        EDX,0x4
    //         004343de     CMP        EAX,EBP
    //         004343e0     MOV        dword ptr [ESP + local_18],EAX
    //         004343e4     MOV        dword ptr [ESP + unit_num],EDX
    //         004343e8     JL         LAB_00434366
    //                              Command.cpp:466 (1)
    //         004343ee     POP        ESI
    //                               LAB_004343ef                                                 XREF[1]:     0043435b(j)  
    //                              Command.cpp:494 (9)
    //         004343ef     POP        EDI
    //         004343f0     POP        EBP
    //         004343f1     POP        EBX
    //         004343f2     ADD        ESP,0x18
    //         004343f5     RET        0x4
}

// Offset: 0x00434400
void do_command_move(RGE_Command* this_, RGE_Command_Order* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall RGE_Command::do_command_move(struct RGE_Command_Order *)                   *
    //                              *********************************************************************************************************
    //                              void __thiscall do_command_move(RGE_Command * this, RGE_Command_Orde
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              RGE_Command_Or    Stack[0x4]:4   param_1                   XREF[1]:     00434403(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0043441d(W)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[1]:     00434425(W)  
    //              RGE_Obj_Info *    Stack[-0xc]:4  units                     XREF[10]:    0043444d(W), 004344b4(R), 004344c2(W), 00434522(R), 
    //                                                                                     00434549(W), 00434733(R), 00434745(W), 0043475f(W), 
    //                                                                                     00434878(R), 0043488a(W)  
    //              int               Stack[-0x10]:4 i                         XREF[12]:    00434455(W), 004344cb(R), 004344d9(W), 0043451e(R), 
    //                                                                                     00434565(W), 0043456f(R), 00434737(R), 00434749(W), 
    //                                                                                     0043476d(W), 0043477b(R), 0043487c(R), 0043488e(W)  
    //              float             Stack[-0x14]:4 maxY                      XREF[1]:     00434431(W)  
    //              RGE_Static_Obj    Stack[-0x18]:4 target                    XREF[5]:     00434465(W), 004344dd(R), 004344f3(W), 0043453b(R), 
    //                                                                                     00434559(W)  
    //              float             Stack[-0x1c]:4 totalY                    XREF[5]:     0043445d(W), 004344e1(R), 004344ef(W), 0043453f(R), 
    //                                                                                     00434555(W)  
    //              float             Stack[-0x20]:4 totalX                    XREF[5]:     00434421(W), 00434501(R), 00434537(R), 0043473b(R), 
    //                                                                                     00434880(R)  
    //              int               Stack[-0x24]:4 unit_num                  XREF[4]:     00434445(W), 0043449f(R), 004344ad(W), 00434505(R)  
    //              float             Stack[-0x28]:4 adjustedXLocation         XREF[4]:     0043443d(W), 00434488(R), 00434496(W), 00434509(R)  
    //              float             Stack[-0x2c]:4 adjustedYLocation
    //                               ?do_command_move@RGE_Command@@IAEXPAURGE_Command_Order@@@Z   XREF[1]:     do_command:00433e54(c)  
    //                               RGE_Command::do_command_move
    //                              Command.cpp:499 (3)
    //         00434400     SUB        ESP,0x28
    //                              Command.cpp:504 (8)
    //         00434403     MOV        EAX,dword ptr [ESP + param_1]
    //         00434407     PUSH       EBX
    //         00434408     PUSH       EBP
    //         00434409     MOV        EBP,this
    //                              Command.cpp:507 (35)
    //         0043440b     MOV        EDX,dword ptr [EAX + 0x4]
    //         0043440e     XOR        this,this
    //         00434410     MOV        this,byte ptr [EAX + 0x8]
    //         00434413     PUSH       ESI
    //         00434414     PUSH       EDI
    //         00434415     MOV        EDI,this
    //         00434417     LEA        EBX,[EAX + 0x14]
    //         0043441a     PUSH       EDX
    //         0043441b     MOV        this,EBP
    //         0043441d     MOV        dword ptr [ESP + local_4],EBP
    //         00434421     MOV        dword ptr [ESP + totalX],EDI
    //         00434425     MOV        dword ptr [ESP + local_8],EBX
    //         00434429     CALL       RGE_Command::get_obj                             RGE_Static_Object * get_obj(RGE_Command * thi
    //                              Command.cpp:510 (13)
    //         0043442e     CMP        EDI,0x1
    //         00434431     MOV        dword ptr [ESP + maxY],EAX
    //         00434435     JLE        LAB_0043475d
    //                              Command.cpp:521 (56)
    //         0043443b     TEST       EDI,EDI
    //         0043443d     MOV        dword ptr [ESP + adjustedXLocation],0x461c4000
    //         00434445     MOV        dword ptr [ESP + unit_num],0x0
    //         0043444d     MOV        dword ptr [ESP + units],0x461c4000
    //         00434455     MOV        dword ptr [ESP + i],0x0
    //         0043445d     MOV        dword ptr [ESP + totalY],0x0
    //         00434465     MOV        dword ptr [ESP + target],0x0
    //         0043446d     JLE        LAB_00434505
    //                              Command.cpp:661 (2)
    //         00434473     MOV        ESI,EBX
    //                               LAB_00434475                                                 XREF[1]:     004344fb(j)  
    //                              Command.cpp:523 (12)
    //         00434475     MOV        EAX,dword ptr [ESI]
    //         00434477     MOV        this,EBP
    //         00434479     PUSH       EAX
    //         0043447a     CALL       RGE_Command::get_obj                             RGE_Static_Object * get_obj(RGE_Command * thi
    //         0043447f     MOV        this,EAX
    //                              Command.cpp:524 (4)
    //         00434481     TEST       this,this
    //         00434483     JZ         LAB_004344f7
    //                              Command.cpp:532 (14)
    //         00434485     FLD        float ptr [this->_padding_ + 0x38]
    //         00434488     FCOMP      float ptr [ESP + adjustedXLocation]
    //         0043448c     FNSTSW     AX
    //         0043448e     TEST       AH,0x1
    //         00434491     JZ         LAB_0043449c
    //                              Command.cpp:533 (7)
    //         00434493     MOV        EDX,dword ptr [this->_padding_ + 0x38]
    //         00434496     MOV        dword ptr [ESP + adjustedXLocation],EDX
    //                              Command.cpp:534 (16)
    //         0043449a     JMP        LAB_004344b1
    //                               LAB_0043449c                                                 XREF[1]:     00434491(j)  
    //         0043449c     FLD        float ptr [this->_padding_ + 0x38]
    //         0043449f     FCOMP      float ptr [ESP + unit_num]
    //         004344a3     FNSTSW     AX
    //         004344a5     TEST       AH,0x41
    //         004344a8     JNZ        LAB_004344b1
    //                              Command.cpp:535 (7)
    //         004344aa     MOV        EAX,dword ptr [this->_padding_ + 0x38]
    //         004344ad     MOV        dword ptr [ESP + unit_num],EAX
    //                               LAB_004344b1                                                 XREF[2]:     0043449a(j), 004344a8(j)  
    //                              Command.cpp:536 (14)
    //         004344b1     FLD        float ptr [this->_padding_ + 0x3c]
    //         004344b4     FCOMP      float ptr [ESP + units]
    //         004344b8     FNSTSW     AX
    //         004344ba     TEST       AH,0x1
    //         004344bd     JZ         LAB_004344c8
    //                              Command.cpp:537 (7)
    //         004344bf     MOV        EDX,dword ptr [this->_padding_ + 0x3c]
    //         004344c2     MOV        dword ptr [ESP + units],EDX
    //                              Command.cpp:538 (16)
    //         004344c6     JMP        LAB_004344dd
    //                               LAB_004344c8                                                 XREF[1]:     004344bd(j)  
    //         004344c8     FLD        float ptr [this->_padding_ + 0x3c]
    //         004344cb     FCOMP      float ptr [ESP + i]
    //         004344cf     FNSTSW     AX
    //         004344d1     TEST       AH,0x41
    //         004344d4     JNZ        LAB_004344dd
    //                              Command.cpp:539 (7)
    //         004344d6     MOV        EAX,dword ptr [this->_padding_ + 0x3c]
    //         004344d9     MOV        dword ptr [ESP + i],EAX
    //                               LAB_004344dd                                                 XREF[2]:     004344c6(j), 004344d4(j)  
    //                              Command.cpp:542 (36)
    //         004344dd     FLD        float ptr [ESP + target]
    //         004344e1     FLD        float ptr [ESP + totalY]
    //         004344e5     FADD       float ptr [this->_padding_ + 0x38]
    //         004344e8     FXCH
    //         004344ea     FADD       float ptr [this->_padding_ + 0x3c]
    //         004344ed     FXCH
    //         004344ef     FSTP       float ptr [ESP + totalY]
    //         004344f3     FSTP       float ptr [ESP + target]
    //                               LAB_004344f7                                                 XREF[1]:     00434483(j)  
    //         004344f7     ADD        ESI,0x4
    //         004344fa     DEC        EDI
    //         004344fb     JNZ        LAB_00434475
    //                              Command.cpp:521 (4)
    //         00434501     MOV        EDI,dword ptr [ESP + totalX]
    //                               LAB_00434505                                                 XREF[1]:     0043446d(j)  
    //                              Command.cpp:547 (50)
    //         00434505     FLD        float ptr [ESP + unit_num]
    //         00434509     FSUB       float ptr [ESP + adjustedXLocation]
    //         0043450d     FCOMP      double ptr [DAT_0056f4d8]
    //         00434513     FNSTSW     AX
    //         00434515     TEST       AH,0x41
    //         00434518     JZ         LAB_0043475d
    //         0043451e     FLD        float ptr [ESP + i]
    //         00434522     FSUB       float ptr [ESP + units]
    //         00434526     FCOMP      double ptr [DAT_0056f4d8]
    //         0043452c     FNSTSW     AX
    //         0043452e     TEST       AH,0x41
    //         00434531     JZ         LAB_0043475d
    //                              Command.cpp:552 (4)
    //         00434537     FILD       dword ptr [ESP + totalX]
    //                              Command.cpp:553 (12)
    //         0043453b     FLD        float ptr [ESP + target]
    //         0043453f     FLD        float ptr [ESP + totalY]
    //         00434543     FDIV       ST0,ST2
    //         00434545     FXCH
    //                              Command.cpp:558 (30)
    //         00434547     TEST       EDI,EDI
    //         00434549     MOV        dword ptr [ESP + units],0x0
    //         00434551     FDIV       ST0,ST2
    //         00434553     FXCH
    //         00434555     FSTP       float ptr [ESP + totalY]
    //         00434559     FSTP       float ptr [ESP + target]
    //         0043455d     FSTP       ST0
    //         0043455f     JLE        LAB_00434898
    //                              Command.cpp:661 (10)
    //         00434565     MOV        dword ptr [ESP + i],EBX
    //         00434569     JMP        LAB_0043456f
    //                               LAB_0043456b                                                 XREF[1]:     0043474d(j)  
    //         0043456b     MOV        EBP,dword ptr [ESP + 0x34]
    //                               LAB_0043456f                                                 XREF[1]:     00434569(j)  
    //                              Command.cpp:560 (16)
    //         0043456f     MOV        this,dword ptr [ESP + i]
    //         00434573     MOV        EDX,dword ptr [this->_padding_]
    //         00434575     MOV        this,EBP
    //         00434577     PUSH       EDX
    //         00434578     CALL       RGE_Command::get_obj                             RGE_Static_Object * get_obj(RGE_Command * thi
    //         0043457d     MOV        ESI,EAX
    //                              Command.cpp:561 (8)
    //         0043457f     TEST       ESI,ESI
    //         00434581     JZ         LAB_00434733
    //                              Command.cpp:566 (7)
    //         00434587     MOV        this,ESI
    //         00434589     CALL       RGE_Static_Object::removeAllFromPathingGroup     void removeAllFromPathingGroup(RGE_Static_Obj
    //                              Command.cpp:567 (12)
    //         0043458e     MOV        EBP,dword ptr [ESI]
    //         00434590     PUSH       0x1
    //         00434592     MOV        this,ESI
    //         00434594     CALL       dword ptr [EBP + 0x12c]
    //                              Command.cpp:661 (85)
    //         0043459a     MOV        EBX,dword ptr [ESP + 0x30]
    //         0043459e     XOR        EDI,EDI
    //                               LAB_004345a0                                                 XREF[1]:     004345ba(j)  
    //         004345a0     CMP        EDI,dword ptr [ESP + 0x2c]
    //         004345a4     JZ         LAB_004345b0
    //         004345a6     MOV        EAX,dword ptr [EBX]
    //         004345a8     MOV        this,ESI
    //         004345aa     PUSH       EAX
    //         004345ab     CALL       RGE_Static_Object::addToPathingGroup             void addToPathingGroup(RGE_Static_Object * th
    //                               LAB_004345b0                                                 XREF[1]:     004345a4(j)  
    //         004345b0     MOV        EAX,dword ptr [ESP + 0x18]
    //         004345b4     INC        EDI
    //         004345b5     ADD        EBX,0x4
    //         004345b8     CMP        EDI,EAX
    //         004345ba     JL         LAB_004345a0
    //         004345bc     FLD        float ptr [ESI + 0x38]
    //         004345bf     FSUB       float ptr [ESP + 0x1c]
    //         004345c3     FLD        float ptr [ESI + 0x3c]
    //         004345c6     FSUB       float ptr [ESP + 0x20]
    //         004345ca     FXCH
    //         004345cc     MOV        EAX,dword ptr [ESP + 0x3c]
    //         004345d0     FADD       float ptr [EAX + 0xc]
    //         004345d3     FXCH
    //         004345d5     FADD       float ptr [EAX + 0x10]
    //         004345d8     FXCH
    //         004345da     FST        float ptr [ESP + 0x14]
    //         004345de     FCOMP      double ptr [DAT_0056f4e0]
    //         004345e4     FSTP       float ptr [ESP + 0x10]
    //         004345e8     FNSTSW     AX
    //         004345ea     TEST       AH,0x1
    //         004345ed     JZ         LAB_004345f9
    //                              Command.cpp:583 (8)
    //         004345ef     MOV        dword ptr [ESP + 0x14],0x3f800000
    //                              Command.cpp:584 (27)
    //         004345f7     JMP        LAB_00434620
    //                               LAB_004345f9                                                 XREF[1]:     004345ed(j)  
    //         004345f9     MOV        this,dword ptr [ESI + 0xc]
    //         004345fc     MOV        EDX,dword ptr [this->_padding_ + 0x3c]
    //         004345ff     MOV        EAX,dword ptr [EDX + 0x28]
    //         00434602     FILD       dword ptr [EAX + 0x8]
    //         00434605     FLD        float ptr [ESP + 0x14]
    //         00434609     FCOMP
    //         0043460b     FNSTSW     AX
    //         0043460d     TEST       AH,0x1
    //         00434610     JNZ        LAB_0043461e
    //                              Command.cpp:585 (12)
    //         00434612     FSUB       float ptr [DAT_0056f4e8]
    //         00434618     FSTP       float ptr [ESP + 0x14]
    //         0043461c     JMP        LAB_00434620
    //                               LAB_0043461e                                                 XREF[1]:     00434610(j)  
    //                              Command.cpp:584 (2)
    //         0043461e     FSTP       ST0
    //                               LAB_00434620                                                 XREF[2]:     004345f7(j), 0043461c(j)  
    //                              Command.cpp:586 (17)
    //         00434620     FLD        float ptr [ESP + 0x10]
    //         00434624     FCOMP      double ptr [DAT_0056f4e0]
    //         0043462a     FNSTSW     AX
    //         0043462c     TEST       AH,0x1
    //         0043462f     JZ         LAB_0043463b
    //                              Command.cpp:587 (8)
    //         00434631     MOV        dword ptr [ESP + 0x10],0x3f800000
    //                              Command.cpp:588 (27)
    //         00434639     JMP        LAB_00434662
    //                               LAB_0043463b                                                 XREF[1]:     0043462f(j)  
    //         0043463b     MOV        this,dword ptr [ESI + 0xc]
    //         0043463e     MOV        EDX,dword ptr [this->_padding_ + 0x3c]
    //         00434641     MOV        EAX,dword ptr [EDX + 0x28]
    //         00434644     FILD       dword ptr [EAX + 0xc]
    //         00434647     FLD        float ptr [ESP + 0x10]
    //         0043464b     FCOMP
    //         0043464d     FNSTSW     AX
    //         0043464f     TEST       AH,0x1
    //         00434652     JNZ        LAB_00434660
    //                              Command.cpp:589 (12)
    //         00434654     FSUB       float ptr [DAT_0056f4e8]
    //         0043465a     FSTP       float ptr [ESP + 0x10]
    //         0043465e     JMP        LAB_00434662
    //                               LAB_00434660                                                 XREF[1]:     00434652(j)  
    //                              Command.cpp:588 (2)
    //         00434660     FSTP       ST0
    //                               LAB_00434662                                                 XREF[2]:     00434639(j), 0043465e(j)  
    //                              Command.cpp:604 (43)
    //         00434662     MOV        this,dword ptr [ESP + 0x24]
    //         00434666     TEST       this,this
    //         00434668     JZ         LAB_0043469c
    //         0043466a     MOV        EDX,dword ptr [ECX + this->last_order]
    //         0043466d     FLD        float ptr [EDX + 0x30]
    //         00434670     FCOMP      double ptr [DAT_0056f4e0]
    //         00434676     FNSTSW     AX
    //         00434678     TEST       AH,0x41
    //         0043467b     JZ         LAB_0043468d
    //         0043467d     FLD        float ptr [EDX + 0x34]
    //         00434680     FCOMP      double ptr [DAT_0056f4e0]
    //         00434686     FNSTSW     AX
    //         00434688     TEST       AH,0x41
    //         0043468b     JNZ        LAB_0043469c
    //                               LAB_0043468d                                                 XREF[1]:     0043467b(j)  
    //                              Command.cpp:605 (13)
    //         0043468d     MOV        EDI,dword ptr [ESP + 0x10]
    //         00434691     MOV        EBX,dword ptr [ESP + 0x14]
    //         00434695     PUSH       0x0
    //         00434697     PUSH       EDI=>DAT_fffffff8
    //         00434698     PUSH       EBX=>DAT_fffffff4
    //         00434699     PUSH       this=>DAT_fffffff0
    //                              Command.cpp:606 (2)
    //         0043469a     JMP        LAB_004346aa
    //                               LAB_0043469c                                                 XREF[2]:     00434668(j), 0043468b(j)  
    //                              Command.cpp:607 (22)
    //         0043469c     MOV        EDI,dword ptr [ESP + 0x10]
    //         004346a0     MOV        EBX,dword ptr [ESP + 0x14]
    //         004346a4     PUSH       0x0
    //         004346a6     PUSH       EDI=>DAT_fffffff8
    //         004346a7     PUSH       EBX=>DAT_fffffff4
    //         004346a8     PUSH       0x0=>DAT_fffffff0
    //                               LAB_004346aa                                                 XREF[1]:     0043469a(j)  
    //         004346aa     MOV        this,ESI
    //         004346ac     CALL       dword ptr [EBP + 0x9c]
    //                              Command.cpp:609 (11)
    //         004346b2     MOV        this,ESI
    //         004346b4     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         004346b9     TEST       EAX,EAX
    //         004346bb     JZ         LAB_00434733
    //                              Command.cpp:610 (19)
    //         004346bd     PUSH       0x2c6
    //         004346c2     MOV        this,ESI
    //         004346c4     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         004346c9     MOV        this,EAX
    //         004346cb     CALL       UnitAIModule::setCurrentOrder                    void setCurrentOrder(UnitAIModule * this, int
    //                              Command.cpp:611 (19)
    //         004346d0     PUSH       0x262
    //         004346d5     MOV        this,ESI
    //         004346d7     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         004346dc     MOV        this,EAX
    //         004346de     CALL       UnitAIModule::setCurrentAction                   void setCurrentAction(UnitAIModule * this, in
    //                              Command.cpp:613 (43)
    //         004346e3     MOV        this,dword ptr [ESP + 0x24]
    //         004346e7     TEST       this,this
    //         004346e9     JZ         LAB_0043471d
    //         004346eb     MOV        EDX,dword ptr [ECX + this->last_order]
    //         004346ee     FLD        float ptr [EDX + 0x30]
    //         004346f1     FCOMP      double ptr [DAT_0056f4e0]
    //         004346f7     FNSTSW     AX
    //         004346f9     TEST       AH,0x41
    //         004346fc     JZ         LAB_0043470e
    //         004346fe     FLD        float ptr [EDX + 0x34]
    //         00434701     FCOMP      double ptr [DAT_0056f4e0]
    //         00434707     FNSTSW     AX
    //         00434709     TEST       AH,0x41
    //         0043470c     JNZ        LAB_0043471d
    //                               LAB_0043470e                                                 XREF[1]:     004346fc(j)  
    //                              Command.cpp:615 (13)
    //         0043470e     MOVSX      EDX,word ptr [EDX + 0x14]
    //         00434712     MOV        EAX,dword ptr [ECX + this->world]
    //         00434715     PUSH       0x0
    //         00434717     PUSH       EDI=>DAT_fffffff8
    //         00434718     PUSH       EBX=>DAT_fffffff4
    //         00434719     PUSH       EDX=>DAT_fffffff0
    //         0043471a     PUSH       EAX
    //                              Command.cpp:616 (2)
    //         0043471b     JMP        LAB_00434725
    //                               LAB_0043471d                                                 XREF[2]:     004346e9(j), 0043470c(j)  
    //                              Command.cpp:617 (54)
    //         0043471d     PUSH       0x0
    //         0043471f     PUSH       EDI=>DAT_fffffff8
    //         00434720     PUSH       EBX=>DAT_fffffff4
    //         00434721     PUSH       offset DAT_fffffff0
    //         00434723     PUSH       -0x1
    //                               LAB_00434725                                                 XREF[1]:     0043471b(j)  
    //         00434725     MOV        this,ESI
    //         00434727     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         0043472c     MOV        this,EAX
    //         0043472e     CALL       UnitAIModule::setCurrentTarget                   void setCurrentTarget(UnitAIModule * this, in
    //                               LAB_00434733                                                 XREF[2]:     00434581(j), 004346bb(j)  
    //         00434733     MOV        EAX,dword ptr [ESP + units]
    //         00434737     MOV        EDX,dword ptr [ESP + i]
    //         0043473b     MOV        this,dword ptr [ESP + totalX]
    //         0043473f     INC        EAX
    //         00434740     ADD        EDX,0x4
    //         00434743     CMP        EAX,this
    //         00434745     MOV        dword ptr [ESP + units],EAX
    //         00434749     MOV        dword ptr [ESP + i],EDX
    //         0043474d     JL         LAB_0043456b
    //                              Command.cpp:661 (10)
    //         00434753     POP        EDI
    //         00434754     POP        ESI
    //         00434755     POP        EBP
    //         00434756     POP        EBX
    //         00434757     ADD        ESP,0x28
    //         0043475a     RET        0x4
    //                               LAB_0043475d                                                 XREF[3]:     00434435(j), 00434518(j), 
    //                                                                                                         00434531(j)  
    //                              Command.cpp:625 (30)
    //         0043475d     TEST       EDI,EDI
    //         0043475f     MOV        dword ptr [ESP + units],0x0
    //         00434767     JLE        LAB_00434898
    //         0043476d     MOV        dword ptr [ESP + i],EBX
    //         00434771     JMP        LAB_0043477b
    //                               LAB_00434773                                                 XREF[1]:     00434892(j)  
    //         00434773     MOV        EBX,dword ptr [ESP + 0x30]
    //         00434777     MOV        EBP,dword ptr [ESP + 0x34]
    //                               LAB_0043477b                                                 XREF[1]:     00434771(j)  
    //                              Command.cpp:627 (16)
    //         0043477b     MOV        this,dword ptr [ESP + i]
    //         0043477f     MOV        EDX,dword ptr [this->_padding_]
    //         00434781     MOV        this,EBP
    //         00434783     PUSH       EDX
    //         00434784     CALL       RGE_Command::get_obj                             RGE_Static_Object * get_obj(RGE_Command * thi
    //         00434789     MOV        ESI,EAX
    //                              Command.cpp:628 (8)
    //         0043478b     TEST       ESI,ESI
    //         0043478d     JZ         LAB_00434878
    //                              Command.cpp:633 (7)
    //         00434793     MOV        this,ESI
    //         00434795     CALL       RGE_Static_Object::removeAllFromPathingGroup     void removeAllFromPathingGroup(RGE_Static_Obj
    //                              Command.cpp:634 (12)
    //         0043479a     MOV        EBP,dword ptr [ESI]
    //         0043479c     PUSH       0x1
    //         0043479e     MOV        this,ESI
    //         004347a0     CALL       dword ptr [EBP + 0x12c]
    //                              Command.cpp:635 (2)
    //         004347a6     XOR        EDI,EDI
    //                               LAB_004347a8                                                 XREF[1]:     004347c2(j)  
    //                              Command.cpp:637 (6)
    //         004347a8     CMP        EDI,dword ptr [ESP + 0x2c]
    //         004347ac     JZ         LAB_004347b8
    //                              Command.cpp:639 (22)
    //         004347ae     MOV        EAX,dword ptr [EBX]
    //         004347b0     MOV        this,ESI
    //         004347b2     PUSH       EAX
    //         004347b3     CALL       RGE_Static_Object::addToPathingGroup             void addToPathingGroup(RGE_Static_Object * th
    //                               LAB_004347b8                                                 XREF[1]:     004347ac(j)  
    //         004347b8     MOV        EAX,dword ptr [ESP + 0x18]
    //         004347bc     INC        EDI
    //         004347bd     ADD        EBX,0x4
    //         004347c0     CMP        EDI,EAX
    //         004347c2     JL         LAB_004347a8
    //                              Command.cpp:647 (27)
    //         004347c4     MOV        EAX,dword ptr [ESP + 0x3c]
    //         004347c8     PUSH       0x0
    //         004347ca     MOV        this,dword ptr [EAX + 0x10]
    //         004347cd     MOV        EDX,dword ptr [EAX + 0xc]
    //         004347d0     MOV        EAX,dword ptr [ESP + 0x28]
    //         004347d4     PUSH       this=>DAT_fffffff8
    //         004347d5     PUSH       EDX=>DAT_fffffff4
    //         004347d6     PUSH       EAX=>DAT_fffffff0
    //         004347d7     MOV        this,ESI
    //         004347d9     CALL       dword ptr [EBP + 0x9c]
    //                              Command.cpp:648 (15)
    //         004347df     MOV        this,ESI
    //         004347e1     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         004347e6     TEST       EAX,EAX
    //         004347e8     JZ         LAB_00434878
    //                              Command.cpp:650 (19)
    //         004347ee     PUSH       0x2c6
    //         004347f3     MOV        this,ESI
    //         004347f5     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         004347fa     MOV        this,EAX
    //         004347fc     CALL       UnitAIModule::setCurrentOrder                    void setCurrentOrder(UnitAIModule * this, int
    //                              Command.cpp:651 (19)
    //         00434801     PUSH       0x262
    //         00434806     MOV        this,ESI
    //         00434808     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         0043480d     MOV        this,EAX
    //         0043480f     CALL       UnitAIModule::setCurrentAction                   void setCurrentAction(UnitAIModule * this, in
    //                              Command.cpp:653 (43)
    //         00434814     MOV        this,dword ptr [ESP + 0x24]
    //         00434818     TEST       this,this
    //         0043481a     JZ         LAB_00434858
    //         0043481c     MOV        EDX,dword ptr [ECX + this->last_order]
    //         0043481f     FLD        float ptr [EDX + 0x30]
    //         00434822     FCOMP      double ptr [DAT_0056f4e0]
    //         00434828     FNSTSW     AX
    //         0043482a     TEST       AH,0x41
    //         0043482d     JZ         LAB_0043483f
    //         0043482f     FLD        float ptr [EDX + 0x34]
    //         00434832     FCOMP      double ptr [DAT_0056f4e0]
    //         00434838     FNSTSW     AX
    //         0043483a     TEST       AH,0x41
    //         0043483d     JNZ        LAB_00434858
    //                               LAB_0043483f                                                 XREF[1]:     0043482d(j)  
    //                              Command.cpp:655 (23)
    //         0043483f     MOV        EAX,dword ptr [ESP + 0x3c]
    //         00434843     PUSH       0x0
    //         00434845     MOVSX      EDX,word ptr [EDX + 0x14]
    //         00434849     MOV        EDI,dword ptr [EAX + 0x10]
    //         0043484c     MOV        EAX,dword ptr [EAX + 0xc]
    //         0043484f     PUSH       EDI=>DAT_fffffff8
    //         00434850     PUSH       EAX=>DAT_fffffff4
    //         00434851     MOV        EAX,dword ptr [ECX + this->world]
    //         00434854     PUSH       EDX=>DAT_fffffff0
    //         00434855     PUSH       EAX
    //                              Command.cpp:656 (2)
    //         00434856     JMP        LAB_0043486a
    //                               LAB_00434858                                                 XREF[2]:     0043481a(j), 0043483d(j)  
    //                              Command.cpp:657 (64)
    //         00434858     MOV        EAX,dword ptr [ESP + 0x3c]
    //         0043485c     PUSH       0x0
    //         0043485e     MOV        this,dword ptr [EAX + 0x10]
    //         00434861     MOV        EDX,dword ptr [EAX + 0xc]
    //         00434864     PUSH       this=>DAT_fffffff8
    //         00434865     PUSH       EDX=>DAT_fffffff4
    //         00434866     PUSH       offset DAT_fffffff0
    //         00434868     PUSH       -0x1
    //                               LAB_0043486a                                                 XREF[1]:     00434856(j)  
    //         0043486a     MOV        this,ESI
    //         0043486c     CALL       RGE_Static_Object::unitAI                        UnitAIModule * unitAI(RGE_Static_Object * this)
    //         00434871     MOV        this,EAX
    //         00434873     CALL       UnitAIModule::setCurrentTarget                   void setCurrentTarget(UnitAIModule * this, in
    //                               LAB_00434878                                                 XREF[2]:     0043478d(j), 004347e8(j)  
    //         00434878     MOV        EAX,dword ptr [ESP + units]
    //         0043487c     MOV        EDX,dword ptr [ESP + i]
    //         00434880     MOV        this,dword ptr [ESP + totalX]
    //         00434884     INC        EAX
    //         00434885     ADD        EDX,0x4
    //         00434888     CMP        EAX,this
    //         0043488a     MOV        dword ptr [ESP + units],EAX
    //         0043488e     MOV        dword ptr [ESP + i],EDX
    //         00434892     JL         LAB_00434773
    //                               LAB_00434898                                                 XREF[2]:     0043455f(j), 00434767(j)  
    //                              Command.cpp:661 (10)
    //         00434898     POP        EDI
    //         00434899     POP        ESI
    //         0043489a     POP        EBP
    //         0043489b     POP        EBX
    //         0043489c     ADD        ESP,0x28
    //         0043489f     RET        0x4
}

// Offset: 0x004348B0
void do_command_create(RGE_Command* this_, RGE_Command_Create* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall RGE_Command::do_command_create(struct RGE_Command_Create *)                *
    //                              *********************************************************************************************************
    //                              void __thiscall do_command_create(RGE_Command * this, RGE_Command_Cr
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              RGE_Command_Cr    Stack[0x4]:4   param_1                   XREF[1]:     004348b0(R)  
    //                               ?do_command_create@RGE_Command@@IAEXPAURGE_Command_Create@@@Z XREF[1]:     do_command:00433e5d(c)  
    //                               RGE_Command::do_command_create
    //                              Command.cpp:666 (48)
    //         004348b0     MOV        EAX,dword ptr [ESP + param_1]
    //         004348b4     MOV        this,dword ptr [ECX + this->world]
    //         004348b7     XOR        EDX,EDX
    //         004348b9     PUSH       ESI
    //         004348ba     MOV        DL,byte ptr [EAX + 0x4]
    //         004348bd     MOV        this,dword ptr [this->_padding_ + 0x40]
    //         004348c0     PUSH       EDI
    //         004348c1     MOV        EDI,dword ptr [EAX + 0x10]
    //         004348c4     MOV        EDX,dword ptr [this->_padding_ + EDX*0x4]
    //         004348c7     PUSH       EDI
    //         004348c8     MOVSX      this,word ptr [EAX + 0x2]
    //         004348cc     MOV        ESI,dword ptr [EDX + 0x24]
    //         004348cf     MOV        EDI,dword ptr [EAX + 0xc]
    //         004348d2     MOV        EAX,dword ptr [EAX + 0x8]
    //         004348d5     PUSH       EDI
    //         004348d6     MOV        this,dword ptr [ESI + this->_padding_*0x4]
    //         004348d9     PUSH       EAX
    //         004348da     PUSH       EDX
    //         004348db     MOV        ESI,dword ptr [this->_padding_]
    //         004348dd     CALL       dword ptr [ESI + 0x18]
    //                              Command.cpp:674 (5)
    //         004348e0     POP        EDI
    //         004348e1     POP        ESI
    //         004348e2     RET        0x4
}

// Offset: 0x004348F0
void do_command_add_attribute(RGE_Command* this_, RGE_Command_Add_Attribute* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall RGE_Command::do_command_add_attribute(struct RGE_Command_Add_Attribute *)  *
    //                              *********************************************************************************************************
    //                              void __thiscall do_command_add_attribute(RGE_Command * this, RGE_Com
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              RGE_Command_Ad    Stack[0x4]:4   param_1                   XREF[1]:     004348f0(R)  
    //                               ?do_command_add_attribute@RGE_Command@@IAEXPAURGE_Command_A  XREF[1]:     do_command:00433e66(c)  
    //                               RGE_Command::do_command_add_attribute
    //                              Command.cpp:679 (36)
    //         004348f0     MOV        EAX,dword ptr [ESP + param_1]
    //         004348f4     MOV        this,dword ptr [ECX + this->world]
    //         004348f7     XOR        EDX,EDX
    //         004348f9     PUSH       ESI
    //         004348fa     MOV        DL,byte ptr [EAX + 0x1]
    //         004348fd     MOV        this,dword ptr [this->_padding_ + 0x40]
    //         00434900     MOV        ESI,dword ptr [EAX + 0x4]
    //         00434903     PUSH       0x0
    //         00434905     MOV        this,dword ptr [this->_padding_ + EDX*0x4]
    //         00434908     PUSH       ESI
    //         00434909     MOVZX      AX,byte ptr [EAX + 0x2]
    //         0043490e     MOV        EDX,dword ptr [this->_padding_]
    //         00434910     PUSH       EAX
    //         00434911     CALL       dword ptr [EDX + 0x78]
    //                              Command.cpp:687 (4)
    //         00434914     POP        ESI
    //         00434915     RET        0x4
}

// Offset: 0x00434920
void RGE_Command::do_command_give_attribute(RGE_Command_Give_Attribute* param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual void __thiscall RGE_Command::do_command_give_attribute(struct RGE_Command_Give_... *
    //                              *********************************************************************************************************
    //                              void __thiscall do_command_give_attribute(RGE_Command * this, RGE_Co
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              RGE_Command_Gi    Stack[0x4]:4   param_1                   XREF[1]:     00434924(R)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[1]:     00434964(*)  
    //                               ?do_command_give_attribute@RGE_Command@@MAEXPAURGE_Command_  XREF[2]:     0056f4c0(*), 00576558(*)  
    //                               RGE_Command::do_command_give_attribute
    //                              Command.cpp:692 (4)
    //         00434920     PUSH       EBX
    //         00434921     MOV        EBX,this
    //         00434923     PUSH       ESI
    //                              Command.cpp:694 (49)
    //         00434924     MOV        ESI,dword ptr [ESP + param_1]
    //         00434928     MOV        EAX,dword ptr [EBX + 0x4]
    //         0043492b     XOR        this,this
    //         0043492d     MOV        this,byte ptr [ESI + 0x1]
    //         00434930     PUSH       EDI
    //         00434931     MOV        EDX,dword ptr [EAX + 0x40]
    //         00434934     MOV        this,dword ptr [EDX + this->_padding_*0x4]
    //         00434937     MOV        DL,byte ptr [ESI + 0x3]
    //         0043493a     MOV        EAX,EDX
    //         0043493c     MOV        EDI,dword ptr [this->_padding_ + 0x50]
    //         0043493f     AND        EAX,0xff
    //         00434944     FLD        float ptr [EDI + EAX*0x4]
    //         00434947     FCOMP      float ptr [ESI + 0x4]
    //         0043494a     FNSTSW     AX
    //         0043494c     TEST       AH,0x1
    //         0043494f     JNZ        LAB_004349ec
    //                              Command.cpp:700 (22)
    //         00434955     FLD        float ptr [ESI + 0x4]
    //         00434958     MOV        EAX,dword ptr [this->_padding_]
    //         0043495a     PUSH       EBP
    //         0043495b     PUSH       0x0
    //         0043495d     PUSH       this
    //         0043495e     MOVZX      DX,DL
    //         00434962     FCHS
    //         00434964     FSTP       float ptr [ESP]=>local_18
    //         00434967     PUSH       EDX
    //         00434968     CALL       dword ptr [EAX + 0x78]
    //                              Command.cpp:706 (31)
    //         0043496b     MOV        EAX,dword ptr [EBX + 0x4]
    //         0043496e     XOR        this,this
    //         00434970     MOV        this,byte ptr [ESI + 0x2]
    //         00434973     PUSH       0x0
    //         00434975     MOV        EDX,dword ptr [EAX + 0x40]
    //         00434978     MOV        this,dword ptr [EDX + this->_padding_*0x4]
    //         0043497b     MOV        EDX,dword ptr [ESI + 0x4]
    //         0043497e     PUSH       EDX=>DAT_fffffff8
    //         0043497f     MOVZX      DX,byte ptr [ESI + 0x3]
    //         00434984     MOV        EAX,dword ptr [this->_padding_]
    //         00434986     PUSH       EDX=>DAT_fffffff4
    //         00434987     CALL       dword ptr [EAX + 0x78]
    //                              Command.cpp:710 (42)
    //         0043498a     MOV        EDI,dword ptr [rge_base_game]                    = 00000000
    //         00434990     FLD        float ptr [ESI + 0x4]
    //         00434993     MOV        EBP,dword ptr [EDI]
    //         00434995     CALL       __ftol                                           undefined __ftol()
    //         0043499a     PUSH       EAX
    //         0043499b     XOR        EAX,EAX
    //         0043499d     MOV        AL,byte ptr [ESI + 0x3]
    //         004349a0     XOR        this,this
    //         004349a2     MOV        this,byte ptr [ESI + 0x2]
    //         004349a5     XOR        EDX,EDX
    //         004349a7     MOV        DL,byte ptr [ESI + 0x1]
    //         004349aa     PUSH       EAX=>DAT_fffffff8
    //         004349ab     PUSH       this=>DAT_fffffff4
    //         004349ac     PUSH       EDX=>DAT_fffffff0
    //         004349ad     PUSH       0x7
    //         004349af     MOV        this,EDI
    //         004349b1     CALL       dword ptr [EBP + 0x40]
    //                              Command.cpp:716 (56)
    //         004349b4     MOV        this,dword ptr [EBX + 0x4]
    //         004349b7     XOR        EAX,EAX
    //         004349b9     MOV        AL,byte ptr [ESI + 0x2]
    //         004349bc     PUSH       0x0
    //         004349be     MOV        EDX,dword ptr [this->_padding_ + 0x40]
    //         004349c1     MOV        EDI,EAX
    //         004349c3     FLD        float ptr [ESI + 0x4]
    //         004349c6     MOV        EBX,dword ptr [EDX + EDI*0x4]
    //         004349c9     MOV        EBP,dword ptr [EBX]
    //         004349cb     CALL       __ftol                                           undefined __ftol()
    //         004349d0     PUSH       EAX=>DAT_fffffff8
    //         004349d1     XOR        EAX,EAX
    //         004349d3     MOV        AL,byte ptr [ESI + 0x3]
    //         004349d6     XOR        this,this
    //         004349d8     MOV        this,byte ptr [ESI + 0x1]
    //         004349db     PUSH       EAX=>DAT_fffffff4
    //         004349dc     PUSH       offset DAT_fffffff0
    //         004349e1     PUSH       EDI
    //         004349e2     PUSH       this
    //         004349e3     MOV        this,EBX
    //         004349e5     CALL       dword ptr [EBP + 0xe8]
    //         004349eb     POP        EBP
    //                               LAB_004349ec                                                 XREF[1]:     0043494f(j)  
    //                              Command.cpp:718 (6)
    //         004349ec     POP        EDI
    //         004349ed     POP        ESI
    //         004349ee     POP        EBX
    //         004349ef     RET        0x4
}

// Offset: 0x00434A00
void do_command_formation(RGE_Command* this_, RGE_Command_Formation* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall RGE_Command::do_command_formation(struct RGE_Command_Formation *)          *
    //                              *********************************************************************************************************
    //                              void __thiscall do_command_formation(RGE_Command * this, RGE_Command
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              RGE_Command_Fo    Stack[0x4]:4   param_1                   XREF[1]:     00434a05(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[5]:     00434a66(R), 00434a71(W), 00434aee(W), 00434ce5(R), 
    //                                                                                     00434cf3(W)  
    //              float             Stack[-0x8]:4  distance                  XREF[2]:     00434a1c(W), 00434a85(R)  
    //              RGE_Obj_Info *    Stack[-0xc]:4  units                     XREF[3]:     00434a0b(W), 00434a32(R), 00434af4(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[6]:     00434a48(W), 00434a4c(R), 00434a54(R), 00434ae4(W), 
    //                                                                                     00434ce1(R), 00434cef(W)  
    //              int               Stack[-0x14]:4 i                         XREF[1]:     00434a18(W)  
    //              int               Stack[-0x18]:4 unitNum                   XREF[2]:     00434a2a(W), 00434a75(W)  
    //              RGE_Static_Obj    Stack[-0x1c]:4 referenceUnit             XREF[1]:     00434aa1(W)  
    //              int               Stack[-0x20]:4 tempCount
    //              float             Stack[-0x24]:4 adjustedXLocation
    //              float             Stack[-0x28]:4 adjustedYLocation         XREF[4]:     00434a8e(W), 00434aae(W), 00434ac0(W), 00434ad2(W)  
    //              float             Stack[-0x2c]:4 tempX                     XREF[4]:     00434a99(W), 00434ab6(W), 00434ac8(W), 00434ada(W)  
    //              float             Stack[-0x30]:4 tempY
    //                               ?do_command_formation@RGE_Command@@IAEXPAURGE_Command_Forma  XREF[1]:     do_command:00433e6f(c)  
    //                               RGE_Command::do_command_formation
    //                              Command.cpp:723 (5)
    //         00434a00     SUB        ESP,0x2c
    //         00434a03     PUSH       EBX
    //         00434a04     PUSH       EBP
    //                              Command.cpp:725 (13)
    //         00434a05     MOV        EBP,dword ptr [ESP + param_1]
    //         00434a09     PUSH       ESI
    //         00434a0a     PUSH       EDI
    //         00434a0b     MOV        dword ptr [ESP + units],this
    //         00434a0f     MOV        EBX,dword ptr [EBP + 0x4]
    //                              Command.cpp:727 (3)
    //         00434a12     LEA        EDI,[EBP + 0xc]
    //                              Command.cpp:730 (17)
    //         00434a15     CMP        EBX,0x1
    //         00434a18     MOV        dword ptr [ESP + i],EBX
    //         00434a1c     MOV        dword ptr [ESP + distance],EDI
    //         00434a20     JLE        LAB_00434cfd
    //                              Command.cpp:733 (2)
    //         00434a26     XOR        ESI,ESI
    //                              Command.cpp:735 (8)
    //         00434a28     CMP        EBX,ESI
    //         00434a2a     MOV        dword ptr [ESP + unitNum],ESI
    //         00434a2e     JLE        LAB_00434a8b
    //                               LAB_00434a30                                                 XREF[1]:     00434a83(j)  
    //                              Command.cpp:737 (14)
    //         00434a30     MOV        EAX,dword ptr [EDI]
    //         00434a32     MOV        this,dword ptr [ESP + units]
    //         00434a36     PUSH       EAX
    //         00434a37     CALL       RGE_Command::get_obj                             RGE_Static_Object * get_obj(RGE_Command * thi
    //         00434a3c     MOV        this,EAX
    //                              Command.cpp:738 (4)
    //         00434a3e     TEST       this,this
    //         00434a40     JZ         LAB_00434a7d
    //                              Command.cpp:742 (24)
    //         00434a42     MOV        EDX,dword ptr [this->_padding_ + 0x38]
    //         00434a45     FLD        float ptr [this->_padding_ + 0x3c]
    //         00434a48     MOV        dword ptr [ESP + local_10],EDX
    //         00434a4c     FLD        float ptr [ESP + local_10]
    //         00434a50     FLD        ST1
    //         00434a52     FXCH
    //         00434a54     FMUL       float ptr [ESP + local_10]
    //         00434a58     FXCH
    //                              Command.cpp:746 (23)
    //         00434a5a     FMUL       ST2
    //         00434a5c     TEST       ESI,ESI
    //         00434a5e     FADDP
    //         00434a60     FSQRT
    //         00434a62     FSTP       ST1
    //         00434a64     JZ         LAB_00434a71
    //         00434a66     FCOM       float ptr [ESP + local_4]
    //         00434a6a     FNSTSW     AX
    //         00434a6c     TEST       AH,0x1
    //         00434a6f     JZ         LAB_00434a7b
    //                               LAB_00434a71                                                 XREF[1]:     00434a64(j)  
    //                              Command.cpp:747 (4)
    //         00434a71     FSTP       float ptr [ESP + local_4]
    //                              Command.cpp:748 (6)
    //         00434a75     MOV        dword ptr [ESP + unitNum],this
    //         00434a79     JMP        LAB_00434a7d
    //                               LAB_00434a7b                                                 XREF[1]:     00434a6f(j)  
    //                              Command.cpp:746 (2)
    //         00434a7b     FSTP       ST0
    //                               LAB_00434a7d                                                 XREF[2]:     00434a40(j), 00434a79(j)  
    //                              Command.cpp:735 (14)
    //         00434a7d     INC        ESI
    //         00434a7e     ADD        EDI,0x4
    //         00434a81     CMP        ESI,EBX
    //         00434a83     JL         LAB_00434a30
    //         00434a85     MOV        EDI,dword ptr [ESP + distance]
    //         00434a89     XOR        ESI,ESI
    //                               LAB_00434a8b                                                 XREF[1]:     00434a2e(j)  
    //                              Command.cpp:760 (35)
    //         00434a8b     MOV        EAX,dword ptr [EBP + 0x8]
    //         00434a8e     MOV        dword ptr [ESP + adjustedYLocation],0x3f800000
    //         00434a96     CMP        EAX,0x5
    //         00434a99     MOV        dword ptr [ESP + tempX],0x3f800000
    //         00434aa1     MOV        dword ptr [ESP + referenceUnit],ESI
    //         00434aa5     JA         switchD_00434aa7::default
    //                               switchD_00434aa7::switchD
    //         00434aa7     JMP        dword ptr [EAX*0x4 + switchD_00434aa7::switchd   = 00434aae
    //                               switchD_00434aa7::caseD_0                                    XREF[2]:     00434aa7(j), 00434d08(*)  
    //                              Command.cpp:762 (8)
    //         00434aae     MOV        dword ptr [ESP + adjustedYLocation],0x3f800000
    //                              Command.cpp:763 (8)
    //         00434ab6     MOV        dword ptr [ESP + tempX],0x3f800000
    //                              Command.cpp:768 (2)
    //         00434abe     JMP        switchD_00434aa7::default
    //                               switchD_00434aa7::caseD_3                                    XREF[3]:     00434aa7(j), 00434d10(*), 
    //                               switchD_00434aa7::caseD_2                                                 00434d14(*)  
    //                              Command.cpp:771 (8)
    //         00434ac0     MOV        dword ptr [ESP + adjustedYLocation],0x40000000
    //                              Command.cpp:772 (8)
    //         00434ac8     MOV        dword ptr [ESP + tempX],0x40000000
    //                              Command.cpp:773 (2)
    //         00434ad0     JMP        switchD_00434aa7::default
    //                               switchD_00434aa7::caseD_4                                    XREF[4]:     00434aa7(j), 00434d0c(*), 
    //                               switchD_00434aa7::caseD_5                                                 00434d18(*), 00434d1c(*)  
    //                               switchD_00434aa7::caseD_1
    //                              Command.cpp:779 (8)
    //         00434ad2     MOV        dword ptr [ESP + adjustedYLocation],0x3fc00000
    //                              Command.cpp:780 (8)
    //         00434ada     MOV        dword ptr [ESP + tempX],0x3fc00000
    //                               switchD_00434aa7::default                                    XREF[3]:     00434aa5(j), 00434abe(j), 
    //                                                                                                         00434ad0(j)  
    //                              Command.cpp:784 (16)
    //         00434ae2     CMP        EBX,ESI
    //         00434ae4     MOV        dword ptr [ESP + local_10],ESI
    //         00434ae8     JLE        LAB_00434cfd
    //         00434aee     MOV        dword ptr [ESP + local_4],EDI
    //                               LAB_00434af2                                                 XREF[1]:     00434cf7(j)  
    //                              Command.cpp:787 (14)
    //         00434af2     MOV        EAX,dword ptr [EDI]
    //         00434af4     MOV        this,dword ptr [ESP + units]
    //         00434af8     PUSH       EAX
    //         00434af9     CALL       RGE_Command::get_obj                             RGE_Static_Object * get_obj(RGE_Command * thi
    //         00434afe     MOV        EDI,EAX
    //                              Command.cpp:788 (8)
    //         00434b00     TEST       EDI,EDI
    //         00434b02     JZ         LAB_00434ce1
    //                              Command.cpp:793 (7)
    //         00434b08     MOV        this,EDI
    //         00434b0a     CALL       RGE_Static_Object::removeAllFromPathingGroup     void removeAllFromPathingGroup(RGE_Static_Obj
    //                              Command.cpp:794 (12)
    //         00434b0f     MOV        EBP,dword ptr [EDI]
    //         00434b11     PUSH       0x1
    //         00434b13     MOV        this,EDI
    //         00434b15     CALL       dword ptr [EBP + 0x12c]
    //                              Command.cpp:864 (76)
    //         00434b1b     MOV        EBX,dword ptr [ESP + 0x34]
    //         00434b1f     XOR        ESI,ESI
    //                               LAB_00434b21                                                 XREF[1]:     00434b3b(j)  
    //         00434b21     CMP        ESI,dword ptr [ESP + 0x2c]
    //         00434b25     JZ         LAB_00434b31
    //         00434b27     MOV        this,dword ptr [EBX]
    //         00434b29     PUSH       this
    //         00434b2a     MOV        this,EDI
    //         00434b2c     CALL       RGE_Static_Object::addToPathingGroup             void addToPathingGroup(RGE_Static_Object * th
    //                               LAB_00434b31                                                 XREF[1]:     00434b25(j)  
    //         00434b31     MOV        EAX,dword ptr [ESP + 0x28]
    //         00434b35     INC        ESI
    //         00434b36     ADD        EBX,0x4
    //         00434b39     CMP        ESI,EAX
    //         00434b3b     JL         LAB_00434b21
    //         00434b3d     MOV        EAX,dword ptr [ESP + 0x24]
    //         00434b41     CMP        EDI,EAX
    //         00434b43     JZ         LAB_00434cdd
    //         00434b49     MOV        EDX,dword ptr [EAX + 0x38]
    //         00434b4c     MOV        EAX,dword ptr [EAX + 0x3c]
    //         00434b4f     MOV        this,dword ptr [ESP + 0x40]
    //         00434b53     MOV        dword ptr [ESP + 0x18],EAX
    //         00434b57     MOV        dword ptr [ESP + 0x1c],EDX
    //         00434b5b     MOV        EAX,dword ptr [ECX + this->last_order]
    //         00434b5e     CMP        EAX,0x5
    //         00434b61     JA         switchD_00434b67::default
    //                               switchD_00434b67::switchD
    //                              Command.cpp:808 (7)
    //         00434b67     JMP        dword ptr [EAX*0x4 + switchD_00434b67::switchd   = 00434b6e
    //                               switchD_00434b67::caseD_0                                    XREF[2]:     00434b67(j), 00434d20(*)  
    //                              Command.cpp:810 (4)
    //         00434b6e     FLD        float ptr [ESP + 0x1c]
    //                              Command.cpp:811 (4)
    //         00434b72     FLD        float ptr [ESP + 0x14]
    //                              Command.cpp:812 (4)
    //         00434b76     FLD        float ptr [ESP + 0x18]
    //                              Command.cpp:813 (52)
    //         00434b7a     FLD        float ptr [ESP + 0x10]
    //         00434b7e     FXCH       ST3
    //         00434b80     FADD       float ptr [ESP + 0x14]
    //         00434b84     FXCH       ST2
    //         00434b86     FSUB       float ptr [DAT_0056f4f4]
    //         00434b8c     FXCH
    //         00434b8e     FADD       float ptr [ESP + 0x10]
    //         00434b92     FXCH       ST3
    //         00434b94     FSUB       float ptr [DAT_0056f4f4]
    //         00434b9a     FXCH       ST2
    //         00434b9c     FSTP       float ptr [ESP + 0x1c]
    //         00434ba0     FSTP       float ptr [ESP + 0x14]
    //         00434ba4     FXCH
    //         00434ba6     FSTP       float ptr [ESP + 0x18]
    //         00434baa     FSTP       float ptr [ESP + 0x10]
    //                              Command.cpp:814 (5)
    //         00434bae     JMP        switchD_00434b67::default
    //                               switchD_00434b67::caseD_1                                    XREF[2]:     00434b67(j), 00434d24(*)  
    //                              Command.cpp:816 (4)
    //         00434bb3     FLD        float ptr [ESP + 0x1c]
    //                              Command.cpp:817 (4)
    //         00434bb7     FLD        float ptr [ESP + 0x14]
    //                              Command.cpp:818 (4)
    //         00434bbb     FLD        float ptr [ESP + 0x18]
    //                              Command.cpp:819 (52)
    //         00434bbf     FLD        float ptr [ESP + 0x10]
    //         00434bc3     FXCH       ST3
    //         00434bc5     FADD       float ptr [ESP + 0x14]
    //         00434bc9     FXCH       ST2
    //         00434bcb     FSUB       float ptr [DAT_0056f4f8]
    //         00434bd1     FXCH
    //         00434bd3     FSUB       float ptr [ESP + 0x10]
    //         00434bd7     FXCH       ST3
    //         00434bd9     FSUB       float ptr [DAT_0056f4f8]
    //         00434bdf     FXCH       ST2
    //         00434be1     FSTP       float ptr [ESP + 0x1c]
    //         00434be5     FSTP       float ptr [ESP + 0x14]
    //         00434be9     FXCH
    //         00434beb     FSTP       float ptr [ESP + 0x18]
    //         00434bef     FSTP       float ptr [ESP + 0x10]
    //                              Command.cpp:820 (5)
    //         00434bf3     JMP        switchD_00434b67::default
    //                               switchD_00434b67::caseD_2                                    XREF[2]:     00434b67(j), 00434d28(*)  
    //                              Command.cpp:823 (26)
    //         00434bf8     FLD        float ptr [ESP + 0x14]
    //         00434bfc     FLD        float ptr [ESP + 0x1c]
    //         00434c00     FADD       float ptr [ESP + 0x14]
    //         00434c04     FXCH
    //         00434c06     FSUB       float ptr [DAT_0056f4fc]
    //         00434c0c     FXCH
    //         00434c0e     FSTP       float ptr [ESP + 0x1c]
    //                              Command.cpp:824 (5)
    //         00434c12     JMP        LAB_00434cc0
    //                               switchD_00434b67::caseD_3                                    XREF[2]:     00434b67(j), 00434d2c(*)  
    //                              Command.cpp:827 (30)
    //         00434c17     FLD        float ptr [ESP + 0x10]
    //         00434c1b     FLD        float ptr [ESP + 0x18]
    //         00434c1f     FADD       float ptr [ESP + 0x10]
    //         00434c23     FXCH
    //         00434c25     FSUB       float ptr [DAT_0056f4fc]
    //         00434c2b     FXCH
    //         00434c2d     FSTP       float ptr [ESP + 0x18]
    //         00434c31     FSTP       float ptr [ESP + 0x10]
    //                              Command.cpp:828 (5)
    //         00434c35     JMP        switchD_00434b67::default
    //                               switchD_00434b67::caseD_5                                    XREF[2]:     00434b67(j), 00434d34(*)  
    //                              Command.cpp:830 (8)
    //         00434c3a     FLD        float ptr [ESP + 0x1c]
    //         00434c3e     FSUB       float ptr [ESP + 0x14]
    //                              Command.cpp:831 (10)
    //         00434c42     MOV        EAX,dword ptr [ESP + 0x20]
    //         00434c46     TEST       EAX,EAX
    //         00434c48     FSTP       float ptr [ESP + 0x1c]
    //                              Command.cpp:832 (10)
    //         00434c4c     FLD        float ptr [ESP + 0x18]
    //         00434c50     JNZ        LAB_00434c8e
    //         00434c52     FSUB       float ptr [ESP + 0x10]
    //                              Command.cpp:833 (12)
    //         00434c56     MOV        dword ptr [ESP + 0x20],0x1
    //         00434c5e     FSTP       float ptr [ESP + 0x18]
    //                              Command.cpp:835 (2)
    //         00434c62     JMP        switchD_00434b67::default
    //                               switchD_00434b67::caseD_4                                    XREF[2]:     00434b67(j), 00434d30(*)  
    //                              Command.cpp:843 (8)
    //         00434c64     FLD        float ptr [ESP + 0x1c]
    //         00434c68     FADD       float ptr [ESP + 0x14]
    //                              Command.cpp:844 (10)
    //         00434c6c     MOV        EAX,dword ptr [ESP + 0x20]
    //         00434c70     TEST       EAX,EAX
    //         00434c72     FSTP       float ptr [ESP + 0x1c]
    //                              Command.cpp:845 (10)
    //         00434c76     FLD        float ptr [ESP + 0x18]
    //         00434c7a     JNZ        LAB_00434c8e
    //         00434c7c     FSUB       float ptr [ESP + 0x10]
    //                              Command.cpp:846 (12)
    //         00434c80     MOV        dword ptr [ESP + 0x20],0x1
    //         00434c88     FSTP       float ptr [ESP + 0x18]
    //                              Command.cpp:848 (2)
    //         00434c8c     JMP        switchD_00434b67::default
    //                               LAB_00434c8e                                                 XREF[2]:     00434c50(j), 00434c7a(j)  
    //                              Command.cpp:850 (4)
    //         00434c8e     FLD        float ptr [ESP + 0x10]
    //                              Command.cpp:851 (28)
    //         00434c92     FLD        float ptr [ESP + 0x14]
    //         00434c96     FXCH       ST2
    //         00434c98     FADD       float ptr [ESP + 0x10]
    //         00434c9c     FXCH
    //         00434c9e     FSUB       float ptr [DAT_0056f4f8]
    //         00434ca4     FXCH       ST2
    //         00434ca6     FSUB       float ptr [DAT_0056f4f8]
    //         00434cac     FXCH
    //                              Command.cpp:852 (22)
    //         00434cae     FSTP       float ptr [ESP + 0x18]
    //         00434cb2     FXCH
    //         00434cb4     FSTP       float ptr [ESP + 0x10]
    //         00434cb8     MOV        dword ptr [ESP + 0x20],0x0
    //                               LAB_00434cc0                                                 XREF[1]:     00434c12(j)  
    //         00434cc0     FSTP       float ptr [ESP + 0x14]
    //                               switchD_00434b67::default                                    XREF[6]:     00434b61(j), 00434bae(j), 
    //                                                                                                         00434bf3(j), 00434c35(j), 
    //                                                                                                         00434c62(j), 00434c8c(j)  
    //                              Command.cpp:861 (29)
    //         00434cc4     MOV        EDX,dword ptr [ESP + 0x18]
    //         00434cc8     MOV        EAX,dword ptr [ESP + 0x1c]
    //         00434ccc     PUSH       0x3f800000
    //         00434cd1     PUSH       EDX=>DAT_fffffff8
    //         00434cd2     PUSH       EAX=>DAT_fffffff4
    //         00434cd3     PUSH       0x0=>DAT_fffffff0
    //         00434cd5     MOV        this,EDI
    //         00434cd7     CALL       dword ptr [EBP + 0x9c]
    //                               LAB_00434cdd                                                 XREF[1]:     00434b43(j)  
    //         00434cdd     MOV        EBX,dword ptr [ESP + 0x28]
    //                               LAB_00434ce1                                                 XREF[1]:     00434b02(j)  
    //                              Command.cpp:784 (28)
    //         00434ce1     MOV        EAX,dword ptr [ESP + local_10]
    //         00434ce5     MOV        EDI,dword ptr [ESP + local_4]
    //         00434ce9     INC        EAX
    //         00434cea     ADD        EDI,0x4
    //         00434ced     CMP        EAX,EBX
    //         00434cef     MOV        dword ptr [ESP + local_10],EAX
    //         00434cf3     MOV        dword ptr [ESP + local_4],EDI
    //         00434cf7     JL         LAB_00434af2
    //                               LAB_00434cfd                                                 XREF[2]:     00434a20(j), 00434ae8(j)  
    //                              Command.cpp:864 (59)
    //         00434cfd     POP        EDI
    //         00434cfe     POP        ESI
    //         00434cff     POP        EBP
    //         00434d00     POP        EBX
    //         00434d01     ADD        ESP,0x2c
    //         00434d04     RET        0x4
}

// Offset: 0x00434D40
void do_command_ai_order(RGE_Command* this_, RGE_Command_AI_Order* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall RGE_Command::do_command_ai_order(struct RGE_Command_AI_Order *)            *
    //                              *********************************************************************************************************
    //                              void __thiscall do_command_ai_order(RGE_Command * this, RGE_Command_
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              RGE_Command_AI    Stack[0x4]:4   param_1                   XREF[1]:     00434d41(R)  
    //                               ?do_command_ai_order@RGE_Command@@IAEXPAURGE_Command_AI_Ord  XREF[1]:     do_command:00433e92(c)  
    //                               RGE_Command::do_command_ai_order
    //                              Command.cpp:870 (1)
    //         00434d40     PUSH       ESI
    //                              Command.cpp:878 (19)
    //         00434d41     MOV        ESI,dword ptr [ESP + param_1]
    //         00434d45     PUSH       EDI
    //         00434d46     MOV        EDI,this
    //         00434d48     MOV        EAX,dword ptr [ESI + 0x4]
    //         00434d4b     MOV        this,dword ptr [EDI + 0x4]
    //         00434d4e     PUSH       EAX
    //         00434d4f     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              Command.cpp:879 (4)
    //         00434d54     TEST       EAX,EAX
    //         00434d56     JZ         LAB_00434dad
    //                              Command.cpp:882 (7)
    //         00434d58     MOV        this,EAX
    //         00434d5a     CALL       RGE_Static_Object::removeAllFromPathingGroup     void removeAllFromPathingGroup(RGE_Static_Obj
    //                              Command.cpp:887 (78)
    //         00434d5f     MOV        EDX,dword ptr [EDI + 0x4]
    //         00434d62     XOR        this,this
    //         00434d64     MOV        this,byte ptr [ESI + 0x1]
    //         00434d67     MOV        EAX,dword ptr [EDX + 0x40]
    //         00434d6a     MOV        this,dword ptr [EAX + this->_padding_*0x4]
    //         00434d6d     XOR        EAX,EAX
    //         00434d6f     MOV        AL,byte ptr [ESI + 0xa]
    //         00434d72     PUSH       EAX
    //         00434d73     XOR        EAX,EAX
    //         00434d75     MOV        AL,byte ptr [ESI + 0x25]
    //         00434d78     MOV        EDX,dword ptr [this->_padding_]
    //         00434d7a     PUSH       EAX
    //         00434d7b     XOR        EAX,EAX
    //         00434d7d     MOV        AL,byte ptr [ESI + 0x24]
    //         00434d80     PUSH       EAX
    //         00434d81     MOV        EAX,dword ptr [ESI + 0x20]
    //         00434d84     PUSH       EAX
    //         00434d85     MOV        EAX,dword ptr [ESI + 0x1c]
    //         00434d88     PUSH       EAX
    //         00434d89     MOV        EAX,dword ptr [ESI + 0x18]
    //         00434d8c     PUSH       EAX
    //         00434d8d     MOV        EAX,dword ptr [ESI + 0x14]
    //         00434d90     PUSH       EAX
    //         00434d91     XOR        EAX,EAX
    //         00434d93     MOV        AL,byte ptr [ESI + 0x10]
    //         00434d96     PUSH       EAX
    //         00434d97     MOV        EAX,dword ptr [ESI + 0xc]
    //         00434d9a     PUSH       EAX
    //         00434d9b     MOVSX      EAX,word ptr [ESI + 0x8]
    //         00434d9f     PUSH       EAX
    //         00434da0     MOV        EAX,dword ptr [ESI + 0x4]
    //         00434da3     PUSH       EAX
    //         00434da4     XOR        EAX,EAX
    //         00434da6     MOV        AL,byte ptr [ESI + 0x2]
    //         00434da9     PUSH       EAX
    //         00434daa     CALL       dword ptr [EDX + 0x34]
    //                               LAB_00434dad                                                 XREF[1]:     00434d56(j)  
    //                              Command.cpp:888 (5)
    //         00434dad     POP        EDI
    //         00434dae     POP        ESI
    //         00434daf     RET        0x4
}

// Offset: 0x00434DC0
void do_command_group_ai_order(RGE_Command* this_, RGE_Command_Group_AI_Order* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall RGE_Command::do_command_group_ai_order(struct RGE_Command_Group_AI_Orde... *
    //                              *********************************************************************************************************
    //                              void __thiscall do_command_group_ai_order(RGE_Command * this, RGE_Co
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              RGE_Command_Gr    Stack[0x4]:4   param_1                   XREF[4]:     00434dc7(R), 00434e2e(W), 00434e37(W), 00434e68(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00434ddf(W), 00434e93(R), 00434e9b(W)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     00434e04(W), 00434e0d(W), 00434e72(R)  
    //              float             Stack[-0xc]:4  targetX                   XREF[3]:     00434e18(W), 00434e21(W), 00434e6d(R)  
    //              float             Stack[-0x10]:4 targetY
    //                               ?do_command_group_ai_order@RGE_Command@@IAEXPAURGE_Command_  XREF[1]:     do_command:00433e9b(c)  
    //                               RGE_Command::do_command_group_ai_order
    //                              Command.cpp:894 (3)
    //         00434dc0     SUB        ESP,0xc
    //                              Command.cpp:895 (13)
    //         00434dc3     XOR        EAX,EAX
    //         00434dc5     PUSH       EBX
    //         00434dc6     PUSH       ESI
    //         00434dc7     MOV        ESI,dword ptr [ESP + param_1]
    //         00434dcb     MOV        EBX,this
    //         00434dcd     MOV        AL,byte ptr [ESI + 0x3]
    //                              Command.cpp:896 (3)
    //         00434dd0     LEA        this,[ESI + 0x24]
    //                              Command.cpp:898 (16)
    //         00434dd3     TEST       EAX,EAX
    //         00434dd5     JLE        LAB_00434ea7
    //         00434ddb     PUSH       EDI
    //         00434ddc     PUSH       EBP
    //         00434ddd     MOV        EBP,this
    //         00434ddf     MOV        dword ptr [ESP + local_4],EAX
    //                               LAB_00434de3                                                 XREF[1]:     00434e9f(j)  
    //                              Command.cpp:900 (13)
    //         00434de3     MOV        EAX,dword ptr [EBP]
    //         00434de6     MOV        this,EBX
    //         00434de8     PUSH       EAX
    //         00434de9     CALL       RGE_Command::get_obj                             RGE_Static_Object * get_obj(RGE_Command * thi
    //         00434dee     MOV        EDI,EAX
    //                              Command.cpp:901 (8)
    //         00434df0     TEST       EDI,EDI
    //         00434df2     JZ         LAB_00434e93
    //                              Command.cpp:911 (25)
    //         00434df8     MOV        this,dword ptr [ESI + 0x10]
    //         00434dfb     MOV        EAX,0xbf800000
    //         00434e00     CMP        this,EAX
    //         00434e02     JZ         LAB_00434e0a
    //         00434e04     MOV        dword ptr [ESP + local_8],this
    //         00434e08     JMP        LAB_00434e11
    //                               LAB_00434e0a                                                 XREF[1]:     00434e02(j)  
    //         00434e0a     MOV        EDX,dword ptr [EDI + 0x38]
    //         00434e0d     MOV        dword ptr [ESP + local_8],EDX
    //                               LAB_00434e11                                                 XREF[1]:     00434e08(j)  
    //                              Command.cpp:912 (20)
    //         00434e11     MOV        this,dword ptr [ESI + 0x14]
    //         00434e14     CMP        this,EAX
    //         00434e16     JZ         LAB_00434e1e
    //         00434e18     MOV        dword ptr [ESP + targetX],this
    //         00434e1c     JMP        LAB_00434e25
    //                               LAB_00434e1e                                                 XREF[1]:     00434e16(j)  
    //         00434e1e     MOV        EDX,dword ptr [EDI + 0x3c]
    //         00434e21     MOV        dword ptr [ESP + targetX],EDX
    //                               LAB_00434e25                                                 XREF[1]:     00434e1c(j)  
    //                              Command.cpp:913 (22)
    //         00434e25     MOV        this,dword ptr [ESI + 0x18]
    //         00434e28     CMP        this,EAX
    //         00434e2a     JZ         LAB_00434e34
    //         00434e2c     MOV        EAX,this
    //         00434e2e     MOV        dword ptr [ESP + param_1],EAX
    //         00434e32     JMP        LAB_00434e3b
    //                               LAB_00434e34                                                 XREF[1]:     00434e2a(j)  
    //         00434e34     MOV        this,dword ptr [EDI + 0x40]
    //         00434e37     MOV        dword ptr [ESP + param_1],this
    //                               LAB_00434e3b                                                 XREF[1]:     00434e32(j)  
    //                              Command.cpp:915 (7)
    //         00434e3b     MOV        this,EDI
    //         00434e3d     CALL       RGE_Static_Object::removeAllFromPathingGroup     void removeAllFromPathingGroup(RGE_Static_Obj
    //                              Command.cpp:920 (101)
    //         00434e42     MOV        EAX,dword ptr [EBX + 0x4]
    //         00434e45     XOR        EDX,EDX
    //         00434e47     MOV        DL,byte ptr [ESI + 0x1]
    //         00434e4a     MOV        this,dword ptr [EAX + 0x40]
    //         00434e4d     XOR        EAX,EAX
    //         00434e4f     MOV        AL,byte ptr [ESI + 0x6]
    //         00434e52     PUSH       EAX
    //         00434e53     XOR        EAX,EAX
    //         00434e55     MOV        AL,byte ptr [ESI + 0x21]
    //         00434e58     MOV        this,dword ptr [this->_padding_ + EDX*0x4]
    //         00434e5b     PUSH       EAX
    //         00434e5c     XOR        EAX,EAX
    //         00434e5e     MOV        AL,byte ptr [ESI + 0x20]
    //         00434e61     MOV        EDX,dword ptr [this->_padding_]
    //         00434e63     PUSH       EAX
    //         00434e64     MOV        EAX,dword ptr [ESI + 0x1c]
    //         00434e67     PUSH       EAX
    //         00434e68     MOV        EAX,dword ptr [ESP + param_1]
    //         00434e6c     PUSH       EAX
    //         00434e6d     MOV        EAX,dword ptr [ESP + targetX]
    //         00434e71     PUSH       EAX
    //         00434e72     MOV        EAX,dword ptr [ESP + local_8]
    //         00434e76     PUSH       EAX
    //         00434e77     XOR        EAX,EAX
    //         00434e79     MOV        AL,byte ptr [ESI + 0xc]
    //         00434e7c     PUSH       EAX
    //         00434e7d     MOV        EAX,dword ptr [ESI + 0x8]
    //         00434e80     PUSH       EAX
    //         00434e81     MOVSX      EAX,word ptr [ESI + 0x4]
    //         00434e85     PUSH       EAX
    //         00434e86     MOV        EAX,dword ptr [EDI + 0x4]
    //         00434e89     PUSH       EAX
    //         00434e8a     XOR        EAX,EAX
    //         00434e8c     MOV        AL,byte ptr [ESI + 0x2]
    //         00434e8f     PUSH       EAX
    //         00434e90     CALL       dword ptr [EDX + 0x34]
    //                               LAB_00434e93                                                 XREF[1]:     00434df2(j)  
    //         00434e93     MOV        EAX,dword ptr [ESP + local_4]
    //         00434e97     ADD        EBP,0x4
    //         00434e9a     DEC        EAX
    //         00434e9b     MOV        dword ptr [ESP + local_4],EAX
    //         00434e9f     JNZ        LAB_00434de3
    //         00434ea5     POP        EBP
    //         00434ea6     POP        EDI
    //                               LAB_00434ea7                                                 XREF[1]:     00434dd5(j)  
    //                              Command.cpp:923 (8)
    //         00434ea7     POP        ESI
    //         00434ea8     POP        EBX
    //         00434ea9     ADD        ESP,0xc
    //         00434eac     RET        0x4
}

// Offset: 0x00434EB0
void do_command_resign(RGE_Command* this_, RGE_Command_Resign* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall RGE_Command::do_command_resign(struct RGE_Command_Resign *)                *
    //                              *********************************************************************************************************
    //                              void __thiscall do_command_resign(RGE_Command * this, RGE_Command_Re
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              RGE_Command_Re    Stack[0x4]:4   param_1                   XREF[2]:     00434eca(R), 00434f40(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00434ebd(W), 00434f1b(R)  
    //                               ?do_command_resign@RGE_Command@@IAEXPAURGE_Command_Resign@@@Z XREF[1]:     do_command:00433ea4(c)  
    //                               RGE_Command::do_command_resign
    //                              Command.cpp:929 (6)
    //         00434eb0     PUSH       this
    //         00434eb1     PUSH       EBX
    //         00434eb2     PUSH       EBP
    //         00434eb3     PUSH       ESI
    //         00434eb4     MOV        ESI,this
    //                              Command.cpp:934 (20)
    //         00434eb6     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00434ebc     PUSH       EDI
    //         00434ebd     MOV        dword ptr [ESP + local_4],ESI
    //         00434ec1     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
    //         00434ec6     TEST       EAX,EAX
    //         00434ec8     JZ         LAB_00434f40
    //                              Command.cpp:936 (11)
    //         00434eca     MOV        EBX,dword ptr [ESP + param_1]
    //         00434ece     MOV        EAX,[rge_base_game]                              = 00000000
    //         00434ed3     XOR        this,this
    //                              Command.cpp:939 (5)
    //         00434ed5     XOR        EDI,EDI
    //         00434ed7     MOV        this,byte ptr [EBX + 0x2]
    //                              Command.cpp:940 (2)
    //         00434eda     XOR        EBP,EBP
    //                              Command.cpp:942 (13)
    //         00434edc     MOV        ESI,0x1
    //         00434ee1     MOV        byte ptr [this->_padding_ + EAX*0x1 + 0xa15],0x1
    //                              Command.cpp:944 (27)
    //         00434ee9     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //                               LAB_00434eef                                                 XREF[1]:     00434f15(j)  
    //         00434eef     PUSH       ESI
    //         00434ef0     CALL       RGE_Base_Game::playerID                          int playerID(RGE_Base_Game * this, int param_1)
    //         00434ef5     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00434efb     XOR        EDX,EDX
    //         00434efd     MOV        DL,byte ptr [EBX + 0x1]
    //         00434f00     CMP        EAX,EDX
    //         00434f02     JNZ        LAB_00434f11
    //                              Command.cpp:947 (12)
    //         00434f04     MOV        AL,byte ptr [ESI + this->_padding_*0x1 + 0xa15]
    //         00434f0b     INC        EDI
    //         00434f0c     TEST       AL,AL
    //         00434f0e     JZ         LAB_00434f11
    //                              Command.cpp:948 (1)
    //         00434f10     INC        EBP
    //                               LAB_00434f11                                                 XREF[2]:     00434f02(j), 00434f0e(j)  
    //                              Command.cpp:942 (6)
    //         00434f11     INC        ESI
    //         00434f12     CMP        ESI,0x9
    //         00434f15     JL         LAB_00434eef
    //                              Command.cpp:952 (4)
    //         00434f17     CMP        EDI,EBP
    //         00434f19     JNZ        LAB_00434f5d
    //                              Command.cpp:953 (26)
    //         00434f1b     MOV        EAX,dword ptr [ESP + local_4]
    //         00434f1f     XOR        EDX,EDX
    //         00434f21     MOV        DL,byte ptr [EBX + 0x1]
    //         00434f24     MOV        this,dword ptr [EAX + 0x4]
    //         00434f27     MOV        EAX,dword ptr [this->_padding_ + 0x40]
    //         00434f2a     MOV        this,dword ptr [EAX + EDX*0x4]
    //         00434f2d     XOR        EAX,EAX
    //         00434f2f     MOV        AL,byte ptr [EBX + 0x3]
    //         00434f32     MOV        EDX,dword ptr [this->_padding_]
    //         00434f34     PUSH       EAX
    //                              Command.cpp:956 (3)
    //         00434f35     CALL       dword ptr [EDX + 0x8]
    //                              Command.cpp:958 (8)
    //         00434f38     POP        EDI
    //         00434f39     POP        ESI
    //         00434f3a     POP        EBP
    //         00434f3b     POP        EBX
    //         00434f3c     POP        this
    //         00434f3d     RET        0x4
    //                               LAB_00434f40                                                 XREF[1]:     00434ec8(j)  
    //                              Command.cpp:956 (29)
    //         00434f40     MOV        EAX,dword ptr [ESP + param_1]
    //         00434f44     MOV        EDX,dword ptr [ESI + 0x4]
    //         00434f47     XOR        this,this
    //         00434f49     XOR        EBX,EBX
    //         00434f4b     MOV        this,byte ptr [EAX + 0x1]
    //         00434f4e     MOV        EDX,dword ptr [EDX + 0x40]
    //         00434f51     MOV        BL,byte ptr [EAX + 0x3]
    //         00434f54     MOV        this,dword ptr [EDX + this->_padding_*0x4]
    //         00434f57     PUSH       EBX
    //         00434f58     MOV        EDX,dword ptr [this->_padding_]
    //         00434f5a     CALL       dword ptr [EDX + 0x8]
    //                               LAB_00434f5d                                                 XREF[1]:     00434f19(j)  
    //                              Command.cpp:958 (8)
    //         00434f5d     POP        EDI
    //         00434f5e     POP        ESI
    //         00434f5f     POP        EBP
    //         00434f60     POP        EBX
    //         00434f61     POP        this
    //         00434f62     RET        0x4
}

// Offset: 0x00434F70
void do_command_add_waypoint(RGE_Command* this_, RGE_Command_Add_Waypoint* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall RGE_Command::do_command_add_waypoint(struct RGE_Command_Add_Waypoint *)    *
    //                              *********************************************************************************************************
    //                              void __thiscall do_command_add_waypoint(RGE_Command * this, RGE_Comm
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              RGE_Command_Ad    Stack[0x4]:4   param_1                   XREF[1]:     00434f71(R)  
    //                               ?do_command_add_waypoint@RGE_Command@@IAEXPAURGE_Command_Ad  XREF[1]:     do_command:00433ead(c)  
    //                               RGE_Command::do_command_add_waypoint
    //                              Command.cpp:964 (1)
    //         00434f70     PUSH       ESI
    //                              Command.cpp:973 (19)
    //         00434f71     MOV        ESI,dword ptr [ESP + param_1]
    //         00434f75     PUSH       EDI
    //         00434f76     MOV        EDI,this
    //         00434f78     MOV        EAX,dword ptr [ESI + 0x4]
    //         00434f7b     MOV        this,dword ptr [EDI + 0x4]
    //         00434f7e     PUSH       EAX
    //         00434f7f     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              Command.cpp:974 (4)
    //         00434f84     TEST       EAX,EAX
    //         00434f86     JZ         LAB_00434fa9
    //                              Command.cpp:984 (33)
    //         00434f88     MOV        EDX,dword ptr [EDI + 0x4]
    //         00434f8b     XOR        this,this
    //         00434f8d     MOV        this,byte ptr [ESI + 0x1]
    //         00434f90     MOV        EAX,dword ptr [EDX + 0x40]
    //         00434f93     MOV        this,dword ptr [EAX + this->_padding_*0x4]
    //         00434f96     XOR        EAX,EAX
    //         00434f98     MOV        AL,byte ptr [ESI + 0x8]
    //         00434f9b     MOV        EDX,dword ptr [this->_padding_]
    //         00434f9d     PUSH       EAX
    //         00434f9e     LEA        EAX,[ESI + 0x9]
    //         00434fa1     PUSH       EAX
    //         00434fa2     MOV        EAX,dword ptr [ESI + 0x4]
    //         00434fa5     PUSH       EAX
    //         00434fa6     CALL       dword ptr [EDX + 0x48]
    //                               LAB_00434fa9                                                 XREF[1]:     00434f86(j)  
    //                              Command.cpp:985 (5)
    //         00434fa9     POP        EDI
    //         00434faa     POP        ESI
    //         00434fab     RET        0x4
}

// Offset: 0x00434FB0
void do_command_group_waypoint(RGE_Command* this_, RGE_Command_Group_Waypoint* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall RGE_Command::do_command_group_waypoint(struct RGE_Command_Group_Waypoin... *
    //                              *********************************************************************************************************
    //                              void __thiscall do_command_group_waypoint(RGE_Command * this, RGE_Co
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              RGE_Command_Gr    Stack[0x4]:4   param_1                   XREF[3,2]:   00434fb3(R), 00434fdf(W), 00434fe9(*), 00434fed(W), 
    //                                                                                     00434ff7(W)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00434fc7(W), 00434fff(R), 00435007(W)  
    //                               ?do_command_group_waypoint@RGE_Command@@IAEXPAURGE_Command_  XREF[1]:     do_command:00433eb6(c)  
    //                               RGE_Command::do_command_group_waypoint
    //                              Command.cpp:991 (3)
    //         00434fb0     PUSH       this
    //         00434fb1     PUSH       EBP
    //         00434fb2     PUSH       ESI
    //                              Command.cpp:994 (12)
    //         00434fb3     MOV        ESI,dword ptr [ESP + param_1]
    //         00434fb7     XOR        EAX,EAX
    //         00434fb9     PUSH       EDI
    //         00434fba     MOV        EBP,this
    //         00434fbc     MOV        AL,byte ptr [ESI + 0x1]
    //                              Command.cpp:995 (3)
    //         00434fbf     LEA        EDI,[ESI + 0x4]
    //                              Command.cpp:997 (9)
    //         00434fc2     TEST       EAX,EAX
    //         00434fc4     JLE        LAB_0043500e
    //         00434fc6     PUSH       EBX
    //         00434fc7     MOV        dword ptr [ESP + local_4],EAX
    //                               LAB_00434fcb                                                 XREF[1]:     0043500b(j)  
    //                              Command.cpp:1002 (10)
    //         00434fcb     MOV        EAX,dword ptr [EDI]
    //         00434fcd     MOV        this,EBP
    //         00434fcf     PUSH       EAX
    //         00434fd0     CALL       RGE_Command::get_obj                             RGE_Static_Object * get_obj(RGE_Command * thi
    //                              Command.cpp:1003 (4)
    //         00434fd5     TEST       EAX,EAX
    //         00434fd7     JZ         LAB_00434fff
    //                              Command.cpp:1006 (3)
    //         00434fd9     MOV        this,byte ptr [ESI + 0x2]
    //                              Command.cpp:1007 (7)
    //         00434fdc     MOV        DL,byte ptr [ESI + 0x3]
    //         00434fdf     MOV        byte ptr [ESP + param_1],this
    //                              Command.cpp:1009 (42)
    //         00434fe3     MOV        this,dword ptr [EAX + 0xc]
    //         00434fe6     MOV        EAX,dword ptr [EAX + 0x4]
    //         00434fe9     LEA        EBX=>param_1,[ESP + 0x18]
    //         00434fed     MOV        byte ptr [ESP + param_1+0x1],DL
    //         00434ff1     MOV        EDX,dword ptr [this->_padding_]
    //         00434ff3     PUSH       0x1
    //         00434ff5     PUSH       EBX
    //         00434ff6     PUSH       EAX
    //         00434ff7     MOV        byte ptr [ESP + param_1+0x2],0x0
    //         00434ffc     CALL       dword ptr [EDX + 0x48]
    //                               LAB_00434fff                                                 XREF[1]:     00434fd7(j)  
    //         00434fff     MOV        EAX,dword ptr [ESP + local_4]
    //         00435003     ADD        EDI,0x4
    //         00435006     DEC        EAX
    //         00435007     MOV        dword ptr [ESP + local_4],EAX
    //         0043500b     JNZ        LAB_00434fcb
    //                              Command.cpp:991 (1)
    //         0043500d     POP        EBX
    //                               LAB_0043500e                                                 XREF[1]:     00434fc4(j)  
    //                              Command.cpp:1012 (7)
    //         0043500e     POP        EDI
    //         0043500f     POP        ESI
    //         00435010     POP        EBP
    //         00435011     POP        this
    //         00435012     RET        0x4
}

// Offset: 0x00435020
void do_command_create_group(RGE_Command* this_, RGE_Command_Create_Group* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall RGE_Command::do_command_create_group(struct RGE_Command_Create_Group *)    *
    //                              *********************************************************************************************************
    //                              void __thiscall do_command_create_group(RGE_Command * this, RGE_Comm
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              RGE_Command_Cr    Stack[0x4]:4   param_1                   XREF[1]:     00435024(R)  
    //                               ?do_command_create_group@RGE_Command@@IAEXPAURGE_Command_Cr  XREF[1]:     do_command:00433e80(c)  
    //                               RGE_Command::do_command_create_group
    //                              Command.cpp:1018 (17)
    //         00435020     MOV        this,dword ptr [ECX + this->world]
    //         00435023     PUSH       ESI
    //         00435024     MOV        ESI,dword ptr [ESP + param_1]
    //         00435028     MOV        EAX,dword ptr [ESI + 0x4]
    //         0043502b     PUSH       EAX
    //         0043502c     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              Command.cpp:1021 (18)
    //         00435031     TEST       EAX,EAX
    //         00435033     JZ         LAB_0043505c
    //         00435035     MOVZX      DX,byte ptr [ESI + 0x1]
    //         0043503a     MOV        this,dword ptr [EAX + 0xc]
    //         0043503d     CMP        word ptr [this->_padding_ + 0x4a],DX
    //         00435041     JNZ        LAB_0043505c
    //                              Command.cpp:1026 (25)
    //         00435043     MOV        this,dword ptr [ESI + 0x8]
    //         00435046     MOV        EDX,dword ptr [ESI + 0x4]
    //         00435049     PUSH       this
    //         0043504a     XOR        this,this
    //         0043504c     MOV        this,byte ptr [ESI + 0x70]
    //         0043504f     PUSH       EDX
    //         00435050     ADD        ESI,0xc
    //         00435053     PUSH       this
    //         00435054     PUSH       ESI
    //         00435055     MOV        this,EAX
    //         00435057     CALL       RGE_Static_Object::commanderCreateGroup          int commanderCreateGroup(RGE_Static_Object * 
    //                               LAB_0043505c                                                 XREF[2]:     00435033(j), 00435041(j)  
    //                              Command.cpp:1027 (4)
    //         0043505c     POP        ESI
    //         0043505d     RET        0x4
}

// Offset: 0x00435060
void do_command_add_to_group(RGE_Command* this_, RGE_Command_Add_To_Group* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall RGE_Command::do_command_add_to_group(struct RGE_Command_Add_To_Group *)    *
    //                              *********************************************************************************************************
    //                              void __thiscall do_command_add_to_group(RGE_Command * this, RGE_Comm
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              RGE_Command_Ad    Stack[0x4]:4   param_1                   XREF[1]:     00435064(R)  
    //                               ?do_command_add_to_group@RGE_Command@@IAEXPAURGE_Command_Ad  XREF[1]:     do_command:00433ebf(c)  
    //                               RGE_Command::do_command_add_to_group
    //                              Command.cpp:1033 (17)
    //         00435060     MOV        this,dword ptr [ECX + this->world]
    //         00435063     PUSH       ESI
    //         00435064     MOV        ESI,dword ptr [ESP + param_1]
    //         00435068     MOV        EAX,dword ptr [ESI + 0x4]
    //         0043506b     PUSH       EAX
    //         0043506c     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              Command.cpp:1037 (18)
    //         00435071     TEST       EAX,EAX
    //         00435073     JZ         LAB_00435092
    //         00435075     MOVZX      DX,byte ptr [ESI + 0x1]
    //         0043507a     MOV        this,dword ptr [EAX + 0xc]
    //         0043507d     CMP        word ptr [this->_padding_ + 0x4a],DX
    //         00435081     JNZ        LAB_00435092
    //                              Command.cpp:1038 (15)
    //         00435083     MOV        this,dword ptr [ESI + 0x8]
    //         00435086     MOV        EDX,dword ptr [ESI + 0xc]
    //         00435089     PUSH       this
    //         0043508a     PUSH       EDX
    //         0043508b     MOV        this,EAX
    //         0043508d     CALL       RGE_Static_Object::commanderAddToGroup           int commanderAddToGroup(RGE_Static_Object * t
    //                               LAB_00435092                                                 XREF[2]:     00435073(j), 00435081(j)  
    //                              Command.cpp:1039 (4)
    //         00435092     POP        ESI
    //         00435093     RET        0x4
}

// Offset: 0x004350A0
void do_command_remove_from_group(RGE_Command* this_, RGE_Command_Remove_From_Group* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall RGE_Command::do_command_remove_from_group(struct RGE_Command_Remove_Fro... *
    //                              *********************************************************************************************************
    //                              void __thiscall do_command_remove_from_group(RGE_Command * this, RGE
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              RGE_Command_Re    Stack[0x4]:4   param_1                   XREF[1]:     004350a4(R)  
    //                               ?do_command_remove_from_group@RGE_Command@@IAEXPAURGE_Comma  XREF[1]:     do_command:00433ec8(c)  
    //                               RGE_Command::do_command_remove_from_group
    //                              Command.cpp:1045 (17)
    //         004350a0     MOV        this,dword ptr [ECX + this->world]
    //         004350a3     PUSH       ESI
    //         004350a4     MOV        ESI,dword ptr [ESP + param_1]
    //         004350a8     MOV        EAX,dword ptr [ESI + 0x4]
    //         004350ab     PUSH       EAX
    //         004350ac     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              Command.cpp:1050 (18)
    //         004350b1     TEST       EAX,EAX
    //         004350b3     JZ         LAB_004350ce
    //         004350b5     MOVZX      DX,byte ptr [ESI + 0x1]
    //         004350ba     MOV        this,dword ptr [EAX + 0xc]
    //         004350bd     CMP        word ptr [this->_padding_ + 0x4a],DX
    //         004350c1     JNZ        LAB_004350ce
    //                              Command.cpp:1051 (11)
    //         004350c3     MOV        this,dword ptr [ESI + 0x8]
    //         004350c6     PUSH       this
    //         004350c7     MOV        this,EAX
    //         004350c9     CALL       RGE_Static_Object::commanderRemoveFromGroup      int commanderRemoveFromGroup(RGE_Static_Objec
    //                               LAB_004350ce                                                 XREF[2]:     004350b3(j), 004350c1(j)  
    //                              Command.cpp:1052 (4)
    //         004350ce     POP        ESI
    //         004350cf     RET        0x4
}

// Offset: 0x004350E0
void do_command_destroy_group(RGE_Command* this_, RGE_Command_Destroy_Group* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall RGE_Command::do_command_destroy_group(struct RGE_Command_Destroy_Group *)  *
    //                              *********************************************************************************************************
    //                              void __thiscall do_command_destroy_group(RGE_Command * this, RGE_Com
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              RGE_Command_De    Stack[0x4]:4   param_1                   XREF[1]:     004350e4(R)  
    //                               ?do_command_destroy_group@RGE_Command@@IAEXPAURGE_Command_D  XREF[1]:     do_command:00433e89(c)  
    //                               RGE_Command::do_command_destroy_group
    //                              Command.cpp:1058 (17)
    //         004350e0     MOV        this,dword ptr [ECX + this->world]
    //         004350e3     PUSH       ESI
    //         004350e4     MOV        ESI,dword ptr [ESP + param_1]
    //         004350e8     MOV        EAX,dword ptr [ESI + 0x4]
    //         004350eb     PUSH       EAX
    //         004350ec     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              Command.cpp:1062 (18)
    //         004350f1     TEST       EAX,EAX
    //         004350f3     JZ         LAB_0043510a
    //         004350f5     MOVZX      this,byte ptr [ESI + 0x1]
    //         004350fa     MOV        EDX,dword ptr [EAX + 0xc]
    //         004350fd     CMP        word ptr [EDX + 0x4a],this
    //         00435101     JNZ        LAB_0043510a
    //                              Command.cpp:1063 (7)
    //         00435103     MOV        this,EAX
    //         00435105     CALL       RGE_Static_Object::commanderDestroyGroup         int commanderDestroyGroup(RGE_Static_Object *
    //                               LAB_0043510a                                                 XREF[2]:     004350f3(j), 00435101(j)  
    //                              Command.cpp:1064 (4)
    //         0043510a     POP        ESI
    //         0043510b     RET        0x4
}

// Offset: 0x00435110
uchar duplicate_check_command_order(RGE_Command* this_, RGE_Command_Order* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: unsigned char __thiscall RGE_Command::duplicate_check_command_order(struct RGE_Command_... *
    //                              *********************************************************************************************************
    //                              uchar __thiscall duplicate_check_command_order(RGE_Command * this, R
    //              uchar             AL:1           <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              RGE_Command_Or    Stack[0x4]:4   param_1                   XREF[3]:     00435112(R), 00435130(W), 0043517a(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00435134(W), 0043517e(R)  
    //              RGE_Obj_Info *    Stack[-0x8]:4  last_units
    //                               ?duplicate_check_command_order@RGE_Command@@IAEEPAURGE_Comm  XREF[1]:     close_check_for_duplicate_orders:0
    //                               RGE_Command::duplicate_check_command_order
    //                              Command.cpp:1070 (2)
    //         00435110     PUSH       this
    //         00435111     PUSH       EBX
    //                              Command.cpp:1071 (6)
    //         00435112     MOV        EBX,dword ptr [ESP + param_1]
    //         00435116     PUSH       EBP
    //         00435117     PUSH       ESI
    //                              Command.cpp:1075 (8)
    //         00435118     MOV        ESI,dword ptr [ECX + this->last_order]
    //         0043511b     XOR        EAX,EAX
    //         0043511d     MOV        AL,byte ptr [EBX + 0x8]
    //                              Command.cpp:1077 (24)
    //         00435120     XOR        this,this
    //         00435122     MOV        this,byte ptr [ESI + 0x8]
    //         00435125     PUSH       EDI
    //         00435126     MOV        EDI,EAX
    //         00435128     LEA        EDX,[EBX + 0x14]
    //         0043512b     LEA        EAX,[ESI + 0x14]
    //         0043512e     CMP        EDI,this
    //         00435130     MOV        dword ptr [ESP + param_1],EDX
    //         00435134     MOV        dword ptr [ESP + local_4],EAX
    //                              Command.cpp:1078 (2)
    //         00435138     JNZ        LAB_0043519f
    //                              Command.cpp:1082 (58)
    //         0043513a     FLD        float ptr [EBX + 0xc]
    //         0043513d     CALL       __ftol                                           undefined __ftol()
    //         00435142     FLD        float ptr [ESI + 0xc]
    //         00435145     MOV        BP,AX
    //         00435148     CALL       __ftol                                           undefined __ftol()
    //         0043514d     CMP        AX,BP
    //         00435150     JNZ        LAB_0043519f
    //         00435152     FLD        float ptr [EBX + 0x10]
    //         00435155     CALL       __ftol                                           undefined __ftol()
    //         0043515a     FLD        float ptr [ESI + 0x10]
    //         0043515d     MOV        BP,AX
    //         00435160     CALL       __ftol                                           undefined __ftol()
    //         00435165     CMP        AX,BP
    //         00435168     JNZ        LAB_0043519f
    //         0043516a     MOV        EDX,dword ptr [ESI + 0x4]
    //         0043516d     MOV        EAX,dword ptr [EBX + 0x4]
    //         00435170     CMP        EDX,EAX
    //         00435172     JNZ        LAB_0043519f
    //                              Command.cpp:1085 (6)
    //         00435174     XOR        this,this
    //         00435176     TEST       EDI,EDI
    //         00435178     JLE        LAB_00435195
    //                              Command.cpp:1092 (27)
    //         0043517a     MOV        EAX,dword ptr [ESP + param_1]
    //         0043517e     MOV        EDX,dword ptr [ESP + local_4]
    //         00435182     SUB        EDX,EAX
    //                               LAB_00435184                                                 XREF[1]:     00435193(j)  
    //         00435184     MOV        ESI,dword ptr [EAX]
    //         00435186     MOV        EBX,dword ptr [EDX + EAX*0x1]
    //         00435189     CMP        ESI,EBX
    //         0043518b     JNZ        LAB_0043519f
    //         0043518d     INC        this
    //         0043518e     ADD        EAX,0x4
    //         00435191     CMP        this,EDI
    //         00435193     JL         LAB_00435184
    //                               LAB_00435195                                                 XREF[1]:     00435178(j)  
    //                              Command.cpp:1091 (2)
    //         00435195     MOV        AL,0x1
    //                              Command.cpp:1092 (18)
    //         00435197     POP        EDI
    //         00435198     POP        ESI
    //         00435199     POP        EBP
    //         0043519a     POP        EBX
    //         0043519b     POP        this
    //         0043519c     RET        0x4
    //                               LAB_0043519f                                                 XREF[5]:     00435138(j), 00435150(j), 
    //                                                                                                         00435168(j), 00435172(j), 
    //                                                                                                         0043518b(j)  
    //         0043519f     POP        EDI
    //         004351a0     POP        ESI
    //         004351a1     POP        EBP
    //         004351a2     XOR        AL,AL
    //         004351a4     POP        EBX
    //         004351a5     POP        this
    //         004351a6     RET        0x4
}

// Offset: 0x004351B0
uchar duplicate_check_command_stop(RGE_Command* this_, RGE_Command_Stop* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: unsigned char __thiscall RGE_Command::duplicate_check_command_stop(struct RGE_Command_S... *
    //                              *********************************************************************************************************
    //                              uchar __thiscall duplicate_check_command_stop(RGE_Command * this, RG
    //              uchar             AL:1           <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              RGE_Command_St    Stack[0x4]:4   param_1                   XREF[1]:     004351b0(R)  
    //                               ?duplicate_check_command_stop@RGE_Command@@IAEEPAURGE_Comma  XREF[1]:     close_check_for_duplicate_orders:0
    //                               RGE_Command::duplicate_check_command_stop
    //                              Command.cpp:1098 (4)
    //         004351b0     MOV        EAX,dword ptr [ESP + param_1]
    //                              Command.cpp:1103 (14)
    //         004351b4     MOV        this,dword ptr [ECX + this->last_order]
    //         004351b7     PUSH       EBX
    //         004351b8     PUSH       ESI
    //         004351b9     XOR        EDX,EDX
    //         004351bb     PUSH       EDI
    //         004351bc     MOV        DL,byte ptr [EAX + 0x1]
    //         004351bf     LEA        EDI,[EAX + 0x2]
    //                              Command.cpp:1105 (12)
    //         004351c2     XOR        EAX,EAX
    //         004351c4     LEA        ESI,[ECX + this+0x2]
    //         004351c7     MOV        AL,byte ptr [ECX + this+0x1]
    //         004351ca     CMP        EDX,EAX
    //         004351cc     JZ         LAB_004351d6
    //                              Command.cpp:1106 (2)
    //         004351ce     XOR        AL,AL
    //                              Command.cpp:1115 (6)
    //         004351d0     POP        EDI
    //         004351d1     POP        ESI
    //         004351d2     POP        EBX
    //         004351d3     RET        0x4
    //                               LAB_004351d6                                                 XREF[1]:     004351cc(j)  
    //                              Command.cpp:1108 (6)
    //         004351d6     XOR        this,this
    //         004351d8     TEST       EDX,EDX
    //         004351da     JLE        LAB_00435201
    //                              Command.cpp:1115 (21)
    //         004351dc     MOV        EAX,ESI
    //         004351de     SUB        EDI,ESI
    //                               LAB_004351e0                                                 XREF[1]:     004351ef(j)  
    //         004351e0     MOV        ESI,dword ptr [EDI + EAX*0x1]
    //         004351e3     MOV        EBX,dword ptr [EAX]
    //         004351e5     CMP        ESI,EBX
    //         004351e7     JNZ        LAB_004351f9
    //         004351e9     INC        this
    //         004351ea     ADD        EAX,0x4
    //         004351ed     CMP        this,EDX
    //         004351ef     JL         LAB_004351e0
    //                              Command.cpp:1114 (2)
    //         004351f1     MOV        AL,0x1
    //                              Command.cpp:1115 (6)
    //         004351f3     POP        EDI
    //         004351f4     POP        ESI
    //         004351f5     POP        EBX
    //         004351f6     RET        0x4
    //                               LAB_004351f9                                                 XREF[1]:     004351e7(j)  
    //                              Command.cpp:1111 (2)
    //         004351f9     XOR        AL,AL
    //                              Command.cpp:1115 (14)
    //         004351fb     POP        EDI
    //         004351fc     POP        ESI
    //         004351fd     POP        EBX
    //         004351fe     RET        0x4
    //                               LAB_00435201                                                 XREF[1]:     004351da(j)  
    //         00435201     POP        EDI
    //         00435202     POP        ESI
    //         00435203     MOV        AL,0x1
    //         00435205     POP        EBX
    //         00435206     RET        0x4
}

// Offset: 0x00435210
uchar close_check_for_duplicate_orders(RGE_Command* this_, uchar* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: unsigned char __thiscall RGE_Command::close_check_for_duplicate_orders(unsigned char *)    *
    //                              *********************************************************************************************************
    //                              uchar __thiscall close_check_for_duplicate_orders(RGE_Command * this
    //              uchar             AL:1           <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              uchar *           Stack[0x4]:4   param_1                   XREF[1]:     00435210(R)  
    //                               ?close_check_for_duplicate_orders@RGE_Command@@IAEEPAE@Z     XREF[1]:     check_for_duplicate_orders:004352a
    //                               RGE_Command::close_check_for_duplicate_orders
    //                              Command.cpp:1121 (20)
    //         00435210     MOV        EAX,dword ptr [ESP + param_1]
    //         00435214     XOR        EDX,EDX
    //         00435216     MOV        DL,byte ptr [EAX]
    //         00435218     CMP        EDX,0x3
    //         0043521b     JA         switchD_0043521d::default
    //                               switchD_0043521d::switchD
    //         0043521d     JMP        dword ptr [EDX*0x4 + switchD_0043521d::switchd   = 00435224
    //                               switchD_0043521d::caseD_2                                    XREF[4]:     0043521d(j), 00435248(*), 
    //                               switchD_0043521d::caseD_3                                                 00435250(*), 00435254(*)  
    //                               switchD_0043521d::caseD_0
    //                              Command.cpp:1143 (10)
    //         00435224     PUSH       EAX
    //         00435225     CALL       RGE_Command::duplicate_check_command_order       uchar duplicate_check_command_order(RGE_Comma
    //         0043522a     TEST       AL,AL
    //         0043522c     JZ         switchD_0043521d::default
    //                              Command.cpp:1148 (2)
    //         0043522e     MOV        AL,0x1
    //                              Command.cpp:1163 (3)
    //         00435230     RET        0x4
    //                               switchD_0043521d::caseD_1                                    XREF[2]:     0043521d(j), 0043524c(*)  
    //                              Command.cpp:1152 (10)
    //         00435233     PUSH       EAX
    //         00435234     CALL       RGE_Command::duplicate_check_command_stop        uchar duplicate_check_command_stop(RGE_Comman
    //         00435239     TEST       AL,AL
    //         0043523b     JZ         switchD_0043521d::default
    //                              Command.cpp:1157 (2)
    //         0043523d     MOV        AL,0x1
    //                              Command.cpp:1163 (3)
    //         0043523f     RET        0x4
    //                               switchD_0043521d::default                                    XREF[3]:     0043521b(j), 0043522c(j), 
    //                                                                                                         0043523b(j)  
    //                              Command.cpp:1162 (2)
    //         00435242     XOR        AL,AL
    //                              Command.cpp:1163 (20)
    //         00435244     RET        0x4
}

// Offset: 0x00435260
uchar check_for_duplicate_orders(RGE_Command* this_, uchar* param_2, long param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: unsigned char __thiscall RGE_Command::check_for_duplicate_orders(unsigned char *,long)     *
    //                              *********************************************************************************************************
    //                              uchar __thiscall check_for_duplicate_orders(RGE_Command * this, ucha
    //              uchar             AL:1           <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              uchar *           Stack[0x4]:4   param_1                   XREF[1]:     00435276(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     0043526e(R)  
    //                               ?check_for_duplicate_orders@RGE_Command@@IAEEPAEJ@Z          XREF[1]:     submit:004352cf(c)  
    //                               RGE_Command::check_for_duplicate_orders
    //                              Command.cpp:1169 (4)
    //         00435260     PUSH       ESI
    //         00435261     MOV        ESI,this
    //         00435263     PUSH       EDI
    //                              Command.cpp:1172 (7)
    //         00435264     MOV        EAX,dword ptr [ESI + 0x8]
    //         00435267     TEST       EAX,EAX
    //         00435269     JZ         LAB_004352ab
    //                              Command.cpp:1173 (21)
    //         0043526b     MOV        this,dword ptr [ESI + 0xc]
    //         0043526e     MOV        EDX,dword ptr [ESP + param_2]
    //         00435272     CMP        this,EDX
    //         00435274     JNZ        LAB_004352ab
    //         00435276     MOV        EDI,dword ptr [ESP + param_1]
    //         0043527a     MOV        DL,byte ptr [EAX]
    //         0043527c     CMP        DL,byte ptr [EDI]
    //         0043527e     JNZ        LAB_004352ab
    //                              Command.cpp:1175 (23)
    //         00435280     PUSH       0x497
    //         00435285     PUSH       s_C:\msdev\work\age1_x1\Command.cp               = "C:\\msdev\\work\\age1_x1\\Command.cpp"
    //         0043528a     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         0043528f     MOV        EDX,dword ptr [ESI + 0x10]
    //         00435292     ADD        ESP,0x8
    //         00435295     SUB        EAX,EDX
    //                              Command.cpp:1176 (7)
    //         00435297     CMP        EAX,0x1f4
    //         0043529c     JGE        LAB_004352ab
    //                              Command.cpp:1177 (8)
    //         0043529e     PUSH       EDI
    //         0043529f     MOV        this,ESI
    //         004352a1     CALL       RGE_Command::close_check_for_duplicate_orders    uchar close_check_for_duplicate_orders(RGE_Co
    //                              Command.cpp:1181 (12)
    //         004352a6     POP        EDI
    //         004352a7     POP        ESI
    //         004352a8     RET        0x8
    //                               LAB_004352ab                                                 XREF[4]:     00435269(j), 00435274(j), 
    //                                                                                                         0043527e(j), 0043529c(j)  
    //         004352ab     POP        EDI
    //         004352ac     XOR        AL,AL
    //         004352ae     POP        ESI
    //         004352af     RET        0x8
}

// Offset: 0x004352C0
void submit(RGE_Command* this_, void* param_2, long param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall RGE_Command::submit(void *,long)                                           *
    //                              *********************************************************************************************************
    //                              void __thiscall submit(RGE_Command * this, void * param_1, long para
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     004352c1(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     004352c7(R)  
    //                               ?submit@RGE_Command@@IAEXPAXJ@Z                              XREF[47]:    command_pause:00435609(c), 
    //                               RGE_Command::submit                                                       command_work:00435713(c), 
    //                                                                                                         command_work:004357fa(c), 
    //                                                                                                         command_create:00435a1b(c), 
    //                                                                                                         command_add_attribute:00435a74(c), 
    //                                                                                                         command_add_to_group:00435cb6(c), 
    //                                                                                                         command_ai_order:00435e93(c), 
    //                                                                                                         command_group_ai_order:00435fcc(c)
    //                                                                                                         command_group_waypoint:0043620f(c)
    //                                                                                                         command_make:0050a854(c), 
    //                                                                                                         command_research:0050a934(c), 
    //                                                                                                         command_research:0050a996(c), 
    //                                                                                                         command_build:0050aa7b(c), 
    //                                                                                                         command_build_wall:0050ac57(c), 
    //                                                                                                         command_allied_victory:0050ad5d(c)
    //                                                                                                         command_relation:0050add8(c), 
    //                                                                                                         command_game_speed:0050ae2d(c), 
    //                                                                                                         command_save_game:0050ae75(c), 
    //                                                                                                         command_quick_build:0050af6f(c), 
    //                                                                                                         command_cancel_build:0050b00c(c), 
    //                                                                                                         [more]
    //                              Command.cpp:1187 (1)
    //         004352c0     PUSH       EBX
    //                              Command.cpp:1188 (23)
    //         004352c1     MOV        EBX,dword ptr [ESP + param_1]
    //         004352c5     PUSH       ESI
    //         004352c6     PUSH       EDI
    //         004352c7     MOV        EDI,dword ptr [ESP + param_2]
    //         004352cb     MOV        ESI,this
    //         004352cd     PUSH       EDI
    //         004352ce     PUSH       EBX
    //         004352cf     CALL       RGE_Command::check_for_duplicate_orders          uchar check_for_duplicate_orders(RGE_Command 
    //         004352d4     TEST       AL,AL
    //         004352d6     JNZ        LAB_004352e2
    //                              Command.cpp:1189 (10)
    //         004352d8     MOV        this,dword ptr [ESI + 0x14]
    //         004352db     PUSH       EDI
    //         004352dc     PUSH       EBX
    //         004352dd     CALL       TCommunications_Handler::new_command             uchar new_command(TCommunications_Handler * t
    //                               LAB_004352e2                                                 XREF[1]:     004352d6(j)  
    //                              Command.cpp:1191 (7)
    //         004352e2     MOV        EAX,dword ptr [ESI + 0x8]
    //         004352e5     TEST       EAX,EAX
    //         004352e7     JZ         LAB_004352f2
    //                              Command.cpp:1192 (9)
    //         004352e9     PUSH       EAX
    //         004352ea     CALL       free                                             undefined free()
    //         004352ef     ADD        ESP,0x4
    //                               LAB_004352f2                                                 XREF[1]:     004352e7(j)  
    //                              Command.cpp:1196 (27)
    //         004352f2     PUSH       0x4ac
    //         004352f7     PUSH       s_C:\msdev\work\age1_x1\Command.cp               = "C:\\msdev\\work\\age1_x1\\Command.cpp"
    //         004352fc     MOV        dword ptr [ESI + 0x8],EBX
    //         004352ff     MOV        dword ptr [ESI + 0xc],EDI
    //         00435302     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         00435307     ADD        ESP,0x8
    //         0043530a     MOV        dword ptr [ESI + 0x10],EAX
    //                              Command.cpp:1197 (6)
    //         0043530d     POP        EDI
    //         0043530e     POP        ESI
    //         0043530f     POP        EBX
    //         00435310     RET        0x8
}

// Offset: 0x00435320
void command_order(RGE_Command* this_, RGE_Static_Object** param_2, short param_3, RGE_Static_Object* param_4, float param_5, float param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Command::command_order(class RGE_Static_Object * *,short,class RGE_Sta... *
    //                              *********************************************************************************************************
    //                              void __thiscall command_order(RGE_Command * this, RGE_Static_Object 
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[2]:     0043532d(R), 0043538e(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[3]:     00435322(R), 0043533e(W), 00435406(R)  
    //              RGE_Static_Obj    Stack[0xc]:4   param_3                   XREF[1]:     00435392(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     004353a9(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[1]:     004353ad(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00435338(W), 0043540a(R)  
    //                               ?command_order@RGE_Command@@QAEXPAPAVRGE_Static_Object@@FPA  XREF[2]:     sendGameOrder:0046efd4(c), 
    //                               RGE_Command::command_order                                                command_make_do:00471733(c)  
    //                              Command.cpp:1203 (2)
    //         00435320     PUSH       this
    //         00435321     PUSH       EBX
    //                              Command.cpp:1206 (11)
    //         00435322     MOV        BX,word ptr [ESP + param_2]
    //         00435327     PUSH       EBP
    //         00435328     PUSH       ESI
    //         00435329     MOVSX      EBP,BX
    //         0043532c     PUSH       EDI
    //                              Command.cpp:1220 (37)
    //         0043532d     MOV        EDI,dword ptr [ESP + param_1]
    //         00435331     LEA        EAX,[EBP*0x4 + 0x14]
    //         00435338     MOV        dword ptr [ESP + local_4],this
    //         0043533c     TEST       EDI,EDI
    //         0043533e     MOV        dword ptr [ESP + param_2],EAX
    //         00435342     JZ         LAB_00435418
    //         00435348     CMP        BX,0x1
    //         0043534c     JL         LAB_00435418
    //                              Command.cpp:1224 (13)
    //         00435352     PUSH       EAX
    //         00435353     PUSH       0x1
    //         00435355     CALL       calloc                                           undefined calloc()
    //         0043535a     MOV        ESI,EAX
    //         0043535c     ADD        ESP,0x8
    //                              Command.cpp:1228 (11)
    //         0043535f     TEST       ESI,ESI
    //         00435361     LEA        EAX,[ESI + 0x14]
    //         00435364     JZ         LAB_00435418
    //                              Command.cpp:1231 (4)
    //         0043536a     TEST       EBP,EBP
    //         0043536c     JLE        LAB_00435392
    //                              Command.cpp:1239 (2)
    //         0043536e     MOV        EDX,EDI
    //                              Command.cpp:1267 (18)
    //         00435370     MOV        EDI,EBP
    //         00435372     SUB        EDX,EAX
    //                               LAB_00435374                                                 XREF[1]:     0043538c(j)  
    //         00435374     MOV        this,dword ptr [EDX + EAX*0x1]
    //         00435377     TEST       this,this
    //         00435379     JZ         LAB_00435382
    //         0043537b     MOV        this,dword ptr [ECX + this->world]
    //         0043537e     MOV        dword ptr [EAX],this
    //         00435380     JMP        LAB_00435388
    //                               LAB_00435382                                                 XREF[1]:     00435379(j)  
    //                              Command.cpp:1239 (6)
    //         00435382     MOV        dword ptr [EAX],0xffffffff
    //                               LAB_00435388                                                 XREF[1]:     00435380(j)  
    //                              Command.cpp:1231 (10)
    //         00435388     ADD        EAX,0x4
    //         0043538b     DEC        EDI
    //         0043538c     JNZ        LAB_00435374
    //         0043538e     MOV        EDI,dword ptr [ESP + param_1]
    //                               LAB_00435392                                                 XREF[1]:     0043536c(j)  
    //                              Command.cpp:1244 (8)
    //         00435392     MOV        EAX,dword ptr [ESP + param_3]
    //         00435396     TEST       EAX,EAX
    //         00435398     JZ         LAB_004353a2
    //                              Command.cpp:1246 (6)
    //         0043539a     MOV        EDX,dword ptr [EAX + 0x4]
    //         0043539d     MOV        dword ptr [ESI + 0x4],EDX
    //                              Command.cpp:1249 (2)
    //         004353a0     JMP        LAB_004353a9
    //                               LAB_004353a2                                                 XREF[1]:     00435398(j)  
    //                              Command.cpp:1251 (7)
    //         004353a2     MOV        dword ptr [ESI + 0x4],0xffffffff
    //                               LAB_004353a9                                                 XREF[1]:     004353a0(j)  
    //                              Command.cpp:1258 (4)
    //         004353a9     MOV        this,dword ptr [ESP + param_4]
    //                              Command.cpp:1259 (4)
    //         004353ad     MOV        EDX,dword ptr [ESP + param_5]
    //                              Command.cpp:1262 (85)
    //         004353b1     TEST       EAX,EAX
    //         004353b3     MOV        byte ptr [ESI],0x0
    //         004353b6     MOV        byte ptr [ESI + 0x8],BL
    //         004353b9     MOV        dword ptr [ESI + 0xc],this
    //         004353bc     MOV        dword ptr [ESI + 0x10],EDX
    //         004353bf     JZ         LAB_004353c9
    //         004353c1     MOV        EAX,dword ptr [EAX + 0x8]
    //         004353c4     MOV        EDX,dword ptr [EAX + 0x8]
    //         004353c7     JMP        LAB_004353ce
    //                               LAB_004353c9                                                 XREF[1]:     004353bf(j)  
    //         004353c9     MOV        EDX,s_X                                          = "X"
    //                               LAB_004353ce                                                 XREF[1]:     004353c7(j)  
    //         004353ce     MOV        EAX,dword ptr [EDI]
    //         004353d0     TEST       EAX,EAX
    //         004353d2     JZ         LAB_004353dc
    //         004353d4     MOV        this,dword ptr [EAX + 0x8]
    //         004353d7     MOV        this,dword ptr [ECX + this->last_order]
    //         004353da     JMP        LAB_004353e1
    //                               LAB_004353dc                                                 XREF[1]:     004353d2(j)  
    //         004353dc     MOV        this,s_X                                         = "X"
    //                               LAB_004353e1                                                 XREF[1]:     004353da(j)  
    //         004353e1     TEST       EAX,EAX
    //         004353e3     JZ         LAB_004353ee
    //         004353e5     MOV        EAX,dword ptr [EAX + 0xc]
    //         004353e8     MOVSX      EAX,word ptr [EAX + 0x4a]
    //         004353ec     JMP        LAB_004353f1
    //                               LAB_004353ee                                                 XREF[1]:     004353e3(j)  
    //         004353ee     OR         EAX,0xffffffff
    //                               LAB_004353f1                                                 XREF[1]:     004353ec(j)  
    //         004353f1     PUSH       EDX
    //         004353f2     PUSH       this
    //         004353f3     MOV        this,dword ptr [L]                               = 00000000
    //         004353f9     PUSH       EAX
    //         004353fa     PUSH       EBP
    //         004353fb     PUSH       s_______>SEND_CMD_ORDER_(CNT=%d,OW               = "      >SEND CMD ORDER (CNT=%d,OWN=%d,UNIT=
    //         00435400     PUSH       this
    //         00435401     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //                              Command.cpp:1265 (18)
    //         00435406     MOV        EDX,dword ptr [ESP + param_2]
    //         0043540a     MOV        this,dword ptr [ESP + local_4]
    //         0043540e     ADD        ESP,0x18
    //         00435411     PUSH       EDX
    //         00435412     PUSH       ESI
    //         00435413     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
    //                               LAB_00435418                                                 XREF[3]:     00435342(j), 0043534c(j), 
    //                                                                                                         00435364(j)  
    //                              Command.cpp:1267 (8)
    //         00435418     POP        EDI
    //         00435419     POP        ESI
    //         0043541a     POP        EBP
    //         0043541b     POP        EBX
    //         0043541c     POP        this
    //         0043541d     RET        0x14
}

// Offset: 0x00435420
void command_stop(RGE_Command* this_, RGE_Static_Object** param_2, short param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Command::command_stop(class RGE_Static_Object * *,short)                  *
    //                              *********************************************************************************************************
    //                              void __thiscall command_stop(RGE_Command * this, RGE_Static_Object *
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00435429(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[2]:     00435423(R), 00435490(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0043543a(W), 004354d0(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     00435440(W), 0043548c(R)  
    //              long              Stack[-0xc]:4  size
    //                               ?command_stop@RGE_Command@@QAEXPAPAVRGE_Static_Object@@F@Z   XREF[1]:     command_stop:004717a1(c)  
    //                               RGE_Command::command_stop
    //                              Command.cpp:1273 (3)
    //         00435420     SUB        ESP,0x8
    //                              Command.cpp:1276 (6)
    //         00435423     MOV        AX,word ptr [ESP + param_2]
    //         00435428     PUSH       EBX
    //                              Command.cpp:1285 (43)
    //         00435429     MOV        EBX,dword ptr [ESP + param_1]
    //         0043542d     PUSH       EBP
    //         0043542e     MOVSX      EBP,AX
    //         00435431     PUSH       ESI
    //         00435432     PUSH       EDI
    //         00435433     LEA        ESI,[EBP*0x4 + 0x2]
    //         0043543a     MOV        dword ptr [ESP + local_4],this
    //         0043543e     TEST       EBX,EBX
    //         00435440     MOV        dword ptr [ESP + local_8],ESI
    //         00435444     JZ         LAB_004354de
    //         0043544a     CMP        AX,0x1
    //         0043544e     JL         LAB_004354de
    //                              Command.cpp:1289 (13)
    //         00435454     PUSH       ESI
    //         00435455     PUSH       0x1
    //         00435457     CALL       calloc                                           undefined calloc()
    //         0043545c     MOV        EDI,EAX
    //         0043545e     ADD        ESP,0x8
    //                              Command.cpp:1293 (7)
    //         00435461     TEST       EDI,EDI
    //         00435463     LEA        EAX,[EDI + 0x2]
    //         00435466     JZ         LAB_004354de
    //                              Command.cpp:1296 (4)
    //         00435468     TEST       EBP,EBP
    //         0043546a     JLE        LAB_00435490
    //                              Command.cpp:1304 (2)
    //         0043546c     MOV        EDX,EBX
    //                              Command.cpp:1318 (18)
    //         0043546e     MOV        ESI,EBP
    //         00435470     SUB        EDX,EAX
    //                               LAB_00435472                                                 XREF[1]:     0043548a(j)  
    //         00435472     MOV        this,dword ptr [EDX + EAX*0x1]
    //         00435475     TEST       this,this
    //         00435477     JZ         LAB_00435480
    //         00435479     MOV        this,dword ptr [ECX + this->world]
    //         0043547c     MOV        dword ptr [EAX],this
    //         0043547e     JMP        LAB_00435486
    //                               LAB_00435480                                                 XREF[1]:     00435477(j)  
    //                              Command.cpp:1304 (6)
    //         00435480     MOV        dword ptr [EAX],0xffffffff
    //                               LAB_00435486                                                 XREF[1]:     0043547e(j)  
    //                              Command.cpp:1296 (10)
    //         00435486     ADD        EAX,0x4
    //         00435489     DEC        ESI
    //         0043548a     JNZ        LAB_00435472
    //         0043548c     MOV        ESI,dword ptr [ESP + local_8]
    //                               LAB_00435490                                                 XREF[1]:     0043546a(j)  
    //                              Command.cpp:1310 (10)
    //         00435490     MOV        DL,byte ptr [ESP + param_2]
    //         00435494     MOV        byte ptr [EDI],0x1
    //         00435497     MOV        byte ptr [EDI + 0x1],DL
    //                              Command.cpp:1313 (54)
    //         0043549a     MOV        EAX,dword ptr [EBX]
    //         0043549c     TEST       EAX,EAX
    //         0043549e     JZ         LAB_004354a8
    //         004354a0     MOV        this,dword ptr [EAX + 0x8]
    //         004354a3     MOV        this,dword ptr [ECX + this->last_order]
    //         004354a6     JMP        LAB_004354ad
    //                               LAB_004354a8                                                 XREF[1]:     0043549e(j)  
    //         004354a8     MOV        this,s_X                                         = "X"
    //                               LAB_004354ad                                                 XREF[1]:     004354a6(j)  
    //         004354ad     TEST       EAX,EAX
    //         004354af     JZ         LAB_004354ba
    //         004354b1     MOV        EDX,dword ptr [EAX + 0xc]
    //         004354b4     MOVSX      EAX,word ptr [EDX + 0x4a]
    //         004354b8     JMP        LAB_004354bd
    //                               LAB_004354ba                                                 XREF[1]:     004354af(j)  
    //         004354ba     OR         EAX,0xffffffff
    //                               LAB_004354bd                                                 XREF[1]:     004354b8(j)  
    //         004354bd     PUSH       this
    //         004354be     PUSH       EAX
    //         004354bf     MOV        EAX,[L]                                          = 00000000
    //         004354c4     PUSH       EBP
    //         004354c5     PUSH       s_______>SEND_CMD_STOP_(CNT=%d,OWN               = "      >SEND CMD STOP (CNT=%d,OWN=%d,UNIT=%
    //         004354ca     PUSH       EAX
    //         004354cb     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //                              Command.cpp:1316 (14)
    //         004354d0     MOV        this,dword ptr [ESP + local_4]
    //         004354d4     ADD        ESP,0x14
    //         004354d7     PUSH       ESI
    //         004354d8     PUSH       EDI
    //         004354d9     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
    //                               LAB_004354de                                                 XREF[3]:     00435444(j), 0043544e(j), 
    //                                                                                                         00435466(j)  
    //                              Command.cpp:1318 (10)
    //         004354de     POP        EDI
    //         004354df     POP        ESI
    //         004354e0     POP        EBP
    //         004354e1     POP        EBX
    //         004354e2     ADD        ESP,0x8
    //         004354e5     RET        0x8
}

// Offset: 0x004354F0
void command_stop(RGE_Command* this_, int param_2, int* param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Command::command_stop(int,int *,int)                                      *
    //                              *********************************************************************************************************
    //                              void __thiscall command_stop(RGE_Command * this, int param_1, int * 
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00435570(R)  
    //              int *             Stack[0x8]:4   param_2                   XREF[3]:     004354f5(R), 0043551c(W), 00435546(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     00435505(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004354f9(W), 00435552(R)  
    //                               ?command_stop@RGE_Command@@QAEXHPAHH@Z
    //                               RGE_Command::command_stop
    //                              Command.cpp:1323 (5)
    //         004354f0     PUSH       this
    //         004354f1     PUSH       EBX
    //         004354f2     PUSH       EBP
    //         004354f3     PUSH       ESI
    //         004354f4     PUSH       EDI
    //                              Command.cpp:1325 (29)
    //         004354f5     MOV        EDI,dword ptr [ESP + param_2]
    //         004354f9     MOV        dword ptr [ESP + local_4],this
    //         004354fd     TEST       EDI,EDI
    //         004354ff     JZ         LAB_00435593
    //         00435505     MOV        EBX,dword ptr [ESP + param_3]
    //         00435509     CMP        EBX,0x1
    //         0043550c     JL         LAB_00435593
    //                              Command.cpp:1333 (7)
    //         00435512     LEA        EBP,[EBX*0x4 + 0x2]
    //                              Command.cpp:1334 (17)
    //         00435519     PUSH       EBP
    //         0043551a     PUSH       0x1
    //         0043551c     MOV        dword ptr [ESP + param_2],EBP
    //         00435520     CALL       calloc                                           undefined calloc()
    //         00435525     MOV        ESI,EAX
    //         00435527     ADD        ESP,0x8
    //                              Command.cpp:1339 (7)
    //         0043552a     TEST       ESI,ESI
    //         0043552c     LEA        EAX,[ESI + 0x2]
    //         0043552f     JZ         LAB_00435593
    //                              Command.cpp:1343 (6)
    //         00435531     TEST       EBX,EBX
    //         00435533     JLE        LAB_0043554a
    //         00435535     MOV        this,EDI
    //                              Command.cpp:1359 (15)
    //         00435537     MOV        EDX,EBX
    //         00435539     SUB        this,EAX
    //                               LAB_0043553b                                                 XREF[1]:     00435544(j)  
    //         0043553b     MOV        EBP,dword ptr [this->_padding_ + EAX*0x1]
    //         0043553e     MOV        dword ptr [EAX],EBP
    //         00435540     ADD        EAX,0x4
    //         00435543     DEC        EDX
    //         00435544     JNZ        LAB_0043553b
    //                              Command.cpp:1343 (4)
    //         00435546     MOV        EBP,dword ptr [ESP + param_2]
    //                               LAB_0043554a                                                 XREF[1]:     00435533(j)  
    //                              Command.cpp:1349 (3)
    //         0043554a     MOV        byte ptr [ESI],0x1
    //                              Command.cpp:1350 (3)
    //         0043554d     MOV        byte ptr [ESI + 0x1],BL
    //                              Command.cpp:1354 (15)
    //         00435550     MOV        EAX,dword ptr [EDI]
    //         00435552     MOV        EDI,dword ptr [ESP + local_4]
    //         00435556     PUSH       EAX
    //         00435557     MOV        this,dword ptr [EDI + 0x4]
    //         0043555a     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              Command.cpp:1355 (43)
    //         0043555f     TEST       EAX,EAX
    //         00435561     JZ         LAB_0043556b
    //         00435563     MOV        this,dword ptr [EAX + 0x8]
    //         00435566     MOV        EAX,dword ptr [ECX + this->last_order]
    //         00435569     JMP        LAB_00435570
    //                               LAB_0043556b                                                 XREF[1]:     00435561(j)  
    //         0043556b     MOV        EAX,s_X                                          = "X"
    //                               LAB_00435570                                                 XREF[1]:     00435569(j)  
    //         00435570     MOV        EDX,dword ptr [ESP + param_1]
    //         00435574     PUSH       EAX=>s_X                                         = "X"
    //         00435575     MOV        EAX,[L]                                          = 00000000
    //         0043557a     PUSH       EDX
    //         0043557b     PUSH       EBX
    //         0043557c     PUSH       s_______>SEND_CMD_STOP2_(CNT=%d,OW               = "      >SEND CMD STOP2 (CNT=%d,OWN=%d,UNIT=
    //         00435581     PUSH       EAX
    //         00435582     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00435587     ADD        ESP,0x14
    //                              Command.cpp:1358 (9)
    //         0043558a     MOV        this,EDI
    //         0043558c     PUSH       EBP
    //         0043558d     PUSH       ESI
    //         0043558e     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
    //                               LAB_00435593                                                 XREF[3]:     004354ff(j), 0043550c(j), 
    //                                                                                                         0043552f(j)  
    //                              Command.cpp:1359 (8)
    //         00435593     POP        EDI
    //         00435594     POP        ESI
    //         00435595     POP        EBP
    //         00435596     POP        EBX
    //         00435597     POP        this
    //         00435598     RET        0xc
}

// Offset: 0x004355A0
void command_pause(RGE_Command* this_, int param_2, int* param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Command::command_pause(int,int *,int)                                     *
    //                              *********************************************************************************************************
    //                              void __thiscall command_pause(RGE_Command * this, int param_1, int *
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //              int *             Stack[0x8]:4   param_2                   XREF[1]:     004355a5(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     004355b1(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004355a9(W), 00435600(R)  
    //                               ?command_pause@RGE_Command@@QAEXHPAHH@Z
    //                               RGE_Command::command_pause
    //                              Command.cpp:1364 (5)
    //         004355a0     PUSH       this
    //         004355a1     PUSH       EBX
    //         004355a2     PUSH       EBP
    //         004355a3     PUSH       ESI
    //         004355a4     PUSH       EDI
    //                              Command.cpp:1366 (21)
    //         004355a5     MOV        EDI,dword ptr [ESP + param_2]
    //         004355a9     MOV        dword ptr [ESP + local_4],this
    //         004355ad     TEST       EDI,EDI
    //         004355af     JZ         LAB_0043560e
    //         004355b1     MOV        EBX,dword ptr [ESP + param_3]
    //         004355b5     CMP        EBX,0x1
    //         004355b8     JL         LAB_0043560e
    //                              Command.cpp:1374 (7)
    //         004355ba     LEA        EBP,[EBX*0x4 + 0x2]
    //                              Command.cpp:1375 (13)
    //         004355c1     PUSH       EBP
    //         004355c2     PUSH       0x1
    //         004355c4     CALL       calloc                                           undefined calloc()
    //         004355c9     MOV        ESI,EAX
    //         004355cb     ADD        ESP,0x8
    //                              Command.cpp:1380 (7)
    //         004355ce     TEST       ESI,ESI
    //         004355d0     LEA        EAX,[ESI + 0x2]
    //         004355d3     JZ         LAB_0043560e
    //                              Command.cpp:1384 (6)
    //         004355d5     TEST       EBX,EBX
    //         004355d7     JLE        LAB_004355ea
    //         004355d9     MOV        this,EDI
    //                              Command.cpp:1399 (15)
    //         004355db     MOV        EDX,EBX
    //         004355dd     SUB        this,EAX
    //                               LAB_004355df                                                 XREF[1]:     004355e8(j)  
    //         004355df     MOV        EDI,dword ptr [this->_padding_ + EAX*0x1]
    //         004355e2     MOV        dword ptr [EAX],EDI
    //         004355e4     ADD        EAX,0x4
    //         004355e7     DEC        EDX
    //         004355e8     JNZ        LAB_004355df
    //                               LAB_004355ea                                                 XREF[1]:     004355d7(j)  
    //                              Command.cpp:1390 (3)
    //         004355ea     MOV        byte ptr [ESI],0xd
    //                              Command.cpp:1391 (3)
    //         004355ed     MOV        byte ptr [ESI + 0x1],BL
    //                              Command.cpp:1395 (16)
    //         004355f0     MOV        EAX,[L]                                          = 00000000
    //         004355f5     PUSH       s_______>SEND_CMD_PAUSE                          = "      >SEND CMD PAUSE"
    //         004355fa     PUSH       EAX
    //         004355fb     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //                              Command.cpp:1398 (14)
    //         00435600     MOV        this,dword ptr [ESP + local_4]
    //         00435604     ADD        ESP,0x8
    //         00435607     PUSH       EBP
    //         00435608     PUSH       ESI
    //         00435609     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
    //                               LAB_0043560e                                                 XREF[3]:     004355af(j), 004355b8(j), 
    //                                                                                                         004355d3(j)  
    //                              Command.cpp:1399 (8)
    //         0043560e     POP        EDI
    //         0043560f     POP        ESI
    //         00435610     POP        EBP
    //         00435611     POP        EBX
    //         00435612     POP        this
    //         00435613     RET        0xc
}

// Offset: 0x00435620
void command_work(RGE_Command* this_, RGE_Static_Object** param_2, short param_3, RGE_Static_Object* param_4, float param_5, float param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Command::command_work(class RGE_Static_Object * *,short,class RGE_Stat... *
    //                              *********************************************************************************************************
    //                              void __thiscall command_work(RGE_Command * this, RGE_Static_Object *
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[2]:     0043562d(R), 0043568e(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[3]:     00435622(R), 0043563e(W), 00435706(R)  
    //              RGE_Static_Obj    Stack[0xc]:4   param_3                   XREF[1]:     00435692(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     004356a9(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[1]:     004356ad(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00435638(W), 0043570a(R)  
    //                               ?command_work@RGE_Command@@QAEXPAPAVRGE_Static_Object@@FPAV  XREF[1]:     command_make_work:00471637(c)  
    //                               RGE_Command::command_work
    //                              Command.cpp:1405 (2)
    //         00435620     PUSH       this
    //         00435621     PUSH       EBX
    //                              Command.cpp:1408 (11)
    //         00435622     MOV        BX,word ptr [ESP + param_2]
    //         00435627     PUSH       EBP
    //         00435628     PUSH       ESI
    //         00435629     MOVSX      EBP,BX
    //         0043562c     PUSH       EDI
    //                              Command.cpp:1421 (37)
    //         0043562d     MOV        EDI,dword ptr [ESP + param_1]
    //         00435631     LEA        EAX,[EBP*0x4 + 0x14]
    //         00435638     MOV        dword ptr [ESP + local_4],this
    //         0043563c     TEST       EDI,EDI
    //         0043563e     MOV        dword ptr [ESP + param_2],EAX
    //         00435642     JZ         LAB_00435718
    //         00435648     CMP        BX,0x1
    //         0043564c     JL         LAB_00435718
    //                              Command.cpp:1425 (13)
    //         00435652     PUSH       EAX
    //         00435653     PUSH       0x1
    //         00435655     CALL       calloc                                           undefined calloc()
    //         0043565a     MOV        ESI,EAX
    //         0043565c     ADD        ESP,0x8
    //                              Command.cpp:1429 (11)
    //         0043565f     TEST       ESI,ESI
    //         00435661     LEA        EAX,[ESI + 0x14]
    //         00435664     JZ         LAB_00435718
    //                              Command.cpp:1432 (4)
    //         0043566a     TEST       EBP,EBP
    //         0043566c     JLE        LAB_00435692
    //                              Command.cpp:1440 (2)
    //         0043566e     MOV        EDX,EDI
    //                              Command.cpp:1468 (18)
    //         00435670     MOV        EDI,EBP
    //         00435672     SUB        EDX,EAX
    //                               LAB_00435674                                                 XREF[1]:     0043568c(j)  
    //         00435674     MOV        this,dword ptr [EDX + EAX*0x1]
    //         00435677     TEST       this,this
    //         00435679     JZ         LAB_00435682
    //         0043567b     MOV        this,dword ptr [ECX + this->world]
    //         0043567e     MOV        dword ptr [EAX],this
    //         00435680     JMP        LAB_00435688
    //                               LAB_00435682                                                 XREF[1]:     00435679(j)  
    //                              Command.cpp:1440 (6)
    //         00435682     MOV        dword ptr [EAX],0xffffffff
    //                               LAB_00435688                                                 XREF[1]:     00435680(j)  
    //                              Command.cpp:1432 (10)
    //         00435688     ADD        EAX,0x4
    //         0043568b     DEC        EDI
    //         0043568c     JNZ        LAB_00435674
    //         0043568e     MOV        EDI,dword ptr [ESP + param_1]
    //                               LAB_00435692                                                 XREF[1]:     0043566c(j)  
    //                              Command.cpp:1445 (8)
    //         00435692     MOV        EAX,dword ptr [ESP + param_3]
    //         00435696     TEST       EAX,EAX
    //         00435698     JZ         LAB_004356a2
    //                              Command.cpp:1447 (6)
    //         0043569a     MOV        EDX,dword ptr [EAX + 0x4]
    //         0043569d     MOV        dword ptr [ESI + 0x4],EDX
    //                              Command.cpp:1450 (2)
    //         004356a0     JMP        LAB_004356a9
    //                               LAB_004356a2                                                 XREF[1]:     00435698(j)  
    //                              Command.cpp:1452 (7)
    //         004356a2     MOV        dword ptr [ESI + 0x4],0xffffffff
    //                               LAB_004356a9                                                 XREF[1]:     004356a0(j)  
    //                              Command.cpp:1459 (4)
    //         004356a9     MOV        this,dword ptr [ESP + param_4]
    //                              Command.cpp:1460 (4)
    //         004356ad     MOV        EDX,dword ptr [ESP + param_5]
    //                              Command.cpp:1463 (85)
    //         004356b1     TEST       EAX,EAX
    //         004356b3     MOV        byte ptr [ESI],0x2
    //         004356b6     MOV        byte ptr [ESI + 0x8],BL
    //         004356b9     MOV        dword ptr [ESI + 0xc],this
    //         004356bc     MOV        dword ptr [ESI + 0x10],EDX
    //         004356bf     JZ         LAB_004356c9
    //         004356c1     MOV        EAX,dword ptr [EAX + 0x8]
    //         004356c4     MOV        EDX,dword ptr [EAX + 0x8]
    //         004356c7     JMP        LAB_004356ce
    //                               LAB_004356c9                                                 XREF[1]:     004356bf(j)  
    //         004356c9     MOV        EDX,s_X                                          = "X"
    //                               LAB_004356ce                                                 XREF[1]:     004356c7(j)  
    //         004356ce     MOV        EAX,dword ptr [EDI]
    //         004356d0     TEST       EAX,EAX
    //         004356d2     JZ         LAB_004356dc
    //         004356d4     MOV        this,dword ptr [EAX + 0x8]
    //         004356d7     MOV        this,dword ptr [ECX + this->last_order]
    //         004356da     JMP        LAB_004356e1
    //                               LAB_004356dc                                                 XREF[1]:     004356d2(j)  
    //         004356dc     MOV        this,s_X                                         = "X"
    //                               LAB_004356e1                                                 XREF[1]:     004356da(j)  
    //         004356e1     TEST       EAX,EAX
    //         004356e3     JZ         LAB_004356ee
    //         004356e5     MOV        EAX,dword ptr [EAX + 0xc]
    //         004356e8     MOVSX      EAX,word ptr [EAX + 0x4a]
    //         004356ec     JMP        LAB_004356f1
    //                               LAB_004356ee                                                 XREF[1]:     004356e3(j)  
    //         004356ee     OR         EAX,0xffffffff
    //                               LAB_004356f1                                                 XREF[1]:     004356ec(j)  
    //         004356f1     PUSH       EDX
    //         004356f2     PUSH       this
    //         004356f3     MOV        this,dword ptr [L]                               = 00000000
    //         004356f9     PUSH       EAX
    //         004356fa     PUSH       EBP
    //         004356fb     PUSH       s_______>SEND_CMD_WORK_(CNT=%d,OWN               = "      >SEND CMD WORK (CNT=%d,OWN=%d,UNIT=%
    //         00435700     PUSH       this
    //         00435701     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //                              Command.cpp:1466 (18)
    //         00435706     MOV        EDX,dword ptr [ESP + param_2]
    //         0043570a     MOV        this,dword ptr [ESP + local_4]
    //         0043570e     ADD        ESP,0x18
    //         00435711     PUSH       EDX
    //         00435712     PUSH       ESI
    //         00435713     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
    //                               LAB_00435718                                                 XREF[3]:     00435642(j), 0043564c(j), 
    //                                                                                                         00435664(j)  
    //                              Command.cpp:1468 (8)
    //         00435718     POP        EDI
    //         00435719     POP        ESI
    //         0043571a     POP        EBP
    //         0043571b     POP        EBX
    //         0043571c     POP        this
    //         0043571d     RET        0x14
}

// Offset: 0x00435720
void command_work(RGE_Command* this_, int param_2, int* param_3, int param_4, int param_5, int param_6, float param_7, float param_8) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Command::command_work(int,int *,int,int,int,float,float)                  *
    //                              *********************************************************************************************************
    //                              void __thiscall command_work(RGE_Command * this, int param_1, int * 
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004357de(R)  
    //              int *             Stack[0x8]:4   param_2                   XREF[3]:     00435723(R), 0043574b(W), 004357ef(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     00435734(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0043577e(R)  
    //              int               Stack[0x14]:4  param_5
    //              float             Stack[0x18]:4  param_6                   XREF[1]:     0043577a(R)  
    //              float             Stack[0x1c]:4  param_7                   XREF[1]:     00435782(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0043572a(W), 00435789(R), 004357a6(R)  
    //                               ?command_work@RGE_Command@@QAEXHPAHHHHMM@Z                   XREF[2]:     taskTrader:0051534a(c), 
    //                               RGE_Command::command_work                                                 taskResourceGatherer:0051539a(c)  
    //                              Command.cpp:1474 (3)
    //         00435720     PUSH       this
    //         00435721     PUSH       EBX
    //         00435722     PUSH       EBP
    //                              Command.cpp:1476 (30)
    //         00435723     MOV        EBP,dword ptr [ESP + param_2]
    //         00435727     PUSH       ESI
    //         00435728     TEST       EBP,EBP
    //         0043572a     MOV        dword ptr [ESP + local_4],this
    //         0043572e     JZ         LAB_00435800
    //         00435734     MOV        EBX,dword ptr [ESP + param_3]
    //         00435738     CMP        EBX,0x1
    //         0043573b     JL         LAB_00435800
    //                              Command.cpp:1485 (7)
    //         00435741     LEA        EAX,[EBX*0x4 + 0x14]
    //                              Command.cpp:1486 (17)
    //         00435748     PUSH       EAX
    //         00435749     PUSH       0x1
    //         0043574b     MOV        dword ptr [ESP + param_2],EAX
    //         0043574f     CALL       calloc                                           undefined calloc()
    //         00435754     MOV        ESI,EAX
    //         00435756     ADD        ESP,0x8
    //                              Command.cpp:1491 (11)
    //         00435759     TEST       ESI,ESI
    //         0043575b     LEA        EAX,[ESI + 0x14]
    //         0043575e     JZ         LAB_00435800
    //                              Command.cpp:1495 (7)
    //         00435764     TEST       EBX,EBX
    //         00435766     PUSH       EDI
    //         00435767     JLE        LAB_0043577a
    //         00435769     MOV        this,EBP
    //                              Command.cpp:1516 (15)
    //         0043576b     MOV        EDX,EBX
    //         0043576d     SUB        this,EAX
    //                               LAB_0043576f                                                 XREF[1]:     00435778(j)  
    //         0043576f     MOV        EDI,dword ptr [this->_padding_ + EAX*0x1]
    //         00435772     MOV        dword ptr [EAX],EDI
    //         00435774     ADD        EAX,0x4
    //         00435777     DEC        EDX
    //         00435778     JNZ        LAB_0043576f
    //                               LAB_0043577a                                                 XREF[1]:     00435767(j)  
    //                              Command.cpp:1505 (8)
    //         0043577a     MOV        EAX,dword ptr [ESP + param_6]
    //         0043577e     MOV        EDI,dword ptr [ESP + param_4]
    //                              Command.cpp:1506 (7)
    //         00435782     MOV        this,dword ptr [ESP + param_7]
    //         00435786     MOV        dword ptr [ESI + 0xc],EAX
    //                              Command.cpp:1510 (28)
    //         00435789     MOV        EAX,dword ptr [ESP + local_4]
    //         0043578d     MOV        byte ptr [ESI],0x2
    //         00435790     MOV        byte ptr [ESI + 0x8],BL
    //         00435793     MOV        dword ptr [ESI + 0x4],EDI
    //         00435796     MOV        dword ptr [ESI + 0x10],this
    //         00435799     MOV        EDX,dword ptr [EBP]
    //         0043579c     MOV        this,dword ptr [EAX + 0x4]
    //         0043579f     PUSH       EDX
    //         004357a0     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              Command.cpp:1511 (15)
    //         004357a5     PUSH       EDI
    //         004357a6     MOV        EDI,dword ptr [ESP + local_4]
    //         004357aa     MOV        EBP,EAX
    //         004357ac     MOV        this,dword ptr [EDI + 0x4]
    //         004357af     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              Command.cpp:1512 (59)
    //         004357b4     TEST       EAX,EAX
    //         004357b6     JZ         LAB_004357c0
    //         004357b8     MOV        this,dword ptr [EAX + 0x8]
    //         004357bb     MOV        this,dword ptr [ECX + this->last_order]
    //         004357be     JMP        LAB_004357c5
    //                               LAB_004357c0                                                 XREF[1]:     004357b6(j)  
    //         004357c0     MOV        this,s_X                                         = "X"
    //                               LAB_004357c5                                                 XREF[1]:     004357be(j)  
    //         004357c5     TEST       EBP,EBP
    //         004357c7     JZ         LAB_004357d1
    //         004357c9     MOV        EDX,dword ptr [EBP + 0x8]
    //         004357cc     MOV        EAX,dword ptr [EDX + 0x8]
    //         004357cf     JMP        LAB_004357d6
    //                               LAB_004357d1                                                 XREF[1]:     004357c7(j)  
    //         004357d1     MOV        EAX,s_X                                          = "X"
    //                               LAB_004357d6                                                 XREF[1]:     004357cf(j)  
    //         004357d6     PUSH       this
    //         004357d7     MOV        this,dword ptr [L]                               = 00000000
    //         004357dd     PUSH       EAX=>s_X                                         = "X"
    //         004357de     MOV        EAX,dword ptr [ESP + param_1]
    //         004357e2     PUSH       EAX
    //         004357e3     PUSH       EBX
    //         004357e4     PUSH       s_______>SEND_CMD_WORK2_(CNT=%d,OW               = "      >SEND CMD WORK2 (CNT=%d,OWN=%d,UNIT=
    //         004357e9     PUSH       this
    //         004357ea     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //                              Command.cpp:1515 (17)
    //         004357ef     MOV        EDX,dword ptr [ESP + param_2]
    //         004357f3     ADD        ESP,0x18
    //         004357f6     MOV        this,EDI
    //         004357f8     PUSH       EDX
    //         004357f9     PUSH       ESI
    //         004357fa     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
    //         004357ff     POP        EDI
    //                               LAB_00435800                                                 XREF[3]:     0043572e(j), 0043573b(j), 
    //                                                                                                         0043575e(j)  
    //                              Command.cpp:1516 (7)
    //         00435800     POP        ESI
    //         00435801     POP        EBP
    //         00435802     POP        EBX
    //         00435803     POP        this
    //         00435804     RET        0x1c
}

// Offset: 0x00435810
void command_move(RGE_Command* this_, RGE_Static_Object** param_2, short param_3, RGE_Static_Object* param_4, float param_5, float param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Command::command_move(class RGE_Static_Object * *,short,class RGE_Stat... *
    //                              *********************************************************************************************************
    //                              void __thiscall command_move(RGE_Command * this, RGE_Static_Object *
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[3]:     00435811(R), 0043585e(R), 004358a3(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[3]:     00435825(R), 00435841(W), 00435880(R)  
    //              RGE_Static_Obj    Stack[0xc]:4   param_3                   XREF[1]:     00435884(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     0043589b(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[1]:     0043589f(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0043581b(W), 004358e9(R)  
    //                               ?command_move@RGE_Command@@QAEXPAPAVRGE_Static_Object@@FPAV  XREF[1]:     command_make_move:004715a0(c)  
    //                               RGE_Command::command_move
    //                              Command.cpp:1522 (1)
    //         00435810     PUSH       this
    //                              Command.cpp:1534 (35)
    //         00435811     MOV        EAX,dword ptr [ESP + param_1]
    //         00435815     PUSH       EBX
    //         00435816     PUSH       EBP
    //         00435817     PUSH       ESI
    //         00435818     TEST       EAX,EAX
    //         0043581a     PUSH       EDI
    //         0043581b     MOV        dword ptr [ESP + local_4],this
    //         0043581f     JZ         LAB_004358f7
    //         00435825     MOV        BX,word ptr [ESP + param_2]
    //         0043582a     CMP        BX,0x1
    //         0043582e     JL         LAB_004358f7
    //                              Command.cpp:1538 (10)
    //         00435834     MOVSX      EBP,BX
    //         00435837     LEA        EDI,[EBP*0x4 + 0x14]
    //                              Command.cpp:1539 (17)
    //         0043583e     PUSH       EDI
    //         0043583f     PUSH       0x1
    //         00435841     MOV        dword ptr [ESP + param_2],EDI
    //         00435845     CALL       calloc                                           undefined calloc()
    //         0043584a     MOV        ESI,EAX
    //         0043584c     ADD        ESP,0x8
    //                              Command.cpp:1544 (11)
    //         0043584f     TEST       ESI,ESI
    //         00435851     LEA        EAX,[ESI + 0x14]
    //         00435854     JZ         LAB_004358f7
    //                              Command.cpp:1548 (4)
    //         0043585a     TEST       EBP,EBP
    //         0043585c     JLE        LAB_00435884
    //                              Command.cpp:1554 (4)
    //         0043585e     MOV        EDX,dword ptr [ESP + param_1]
    //                              Command.cpp:1580 (18)
    //         00435862     MOV        EDI,EBP
    //         00435864     SUB        EDX,EAX
    //                               LAB_00435866                                                 XREF[1]:     0043587e(j)  
    //         00435866     MOV        this,dword ptr [EDX + EAX*0x1]
    //         00435869     TEST       this,this
    //         0043586b     JZ         LAB_00435874
    //         0043586d     MOV        this,dword ptr [ECX + this->world]
    //         00435870     MOV        dword ptr [EAX],this
    //         00435872     JMP        LAB_0043587a
    //                               LAB_00435874                                                 XREF[1]:     0043586b(j)  
    //                              Command.cpp:1554 (6)
    //         00435874     MOV        dword ptr [EAX],0xffffffff
    //                               LAB_0043587a                                                 XREF[1]:     00435872(j)  
    //                              Command.cpp:1548 (10)
    //         0043587a     ADD        EAX,0x4
    //         0043587d     DEC        EDI
    //         0043587e     JNZ        LAB_00435866
    //         00435880     MOV        EDI,dword ptr [ESP + param_2]
    //                               LAB_00435884                                                 XREF[1]:     0043585c(j)  
    //                              Command.cpp:1560 (8)
    //         00435884     MOV        EAX,dword ptr [ESP + param_3]
    //         00435888     TEST       EAX,EAX
    //         0043588a     JZ         LAB_00435894
    //                              Command.cpp:1561 (6)
    //         0043588c     MOV        EDX,dword ptr [EAX + 0x4]
    //         0043588f     MOV        dword ptr [ESI + 0x4],EDX
    //                              Command.cpp:1564 (2)
    //         00435892     JMP        LAB_0043589b
    //                               LAB_00435894                                                 XREF[1]:     0043588a(j)  
    //                              Command.cpp:1565 (7)
    //         00435894     MOV        dword ptr [ESI + 0x4],0xffffffff
    //                               LAB_0043589b                                                 XREF[1]:     00435892(j)  
    //                              Command.cpp:1572 (4)
    //         0043589b     MOV        EAX,dword ptr [ESP + param_4]
    //                              Command.cpp:1573 (4)
    //         0043589f     MOV        this,dword ptr [ESP + param_5]
    //                              Command.cpp:1576 (70)
    //         004358a3     MOV        EDX,dword ptr [ESP + param_1]
    //         004358a7     MOV        byte ptr [ESI],0x3
    //         004358aa     MOV        byte ptr [ESI + 0x8],BL
    //         004358ad     MOV        dword ptr [ESI + 0xc],EAX
    //         004358b0     MOV        dword ptr [ESI + 0x10],this
    //         004358b3     MOV        EAX,dword ptr [EDX]
    //         004358b5     TEST       EAX,EAX
    //         004358b7     JZ         LAB_004358c1
    //         004358b9     MOV        this,dword ptr [EAX + 0x8]
    //         004358bc     MOV        this,dword ptr [ECX + this->last_order]
    //         004358bf     JMP        LAB_004358c6
    //                               LAB_004358c1                                                 XREF[1]:     004358b7(j)  
    //         004358c1     MOV        this,s_X                                         = "X"
    //                               LAB_004358c6                                                 XREF[1]:     004358bf(j)  
    //         004358c6     TEST       EAX,EAX
    //         004358c8     JZ         LAB_004358d3
    //         004358ca     MOV        EDX,dword ptr [EAX + 0xc]
    //         004358cd     MOVSX      EAX,word ptr [EDX + 0x4a]
    //         004358d1     JMP        LAB_004358d6
    //                               LAB_004358d3                                                 XREF[1]:     004358c8(j)  
    //         004358d3     OR         EAX,0xffffffff
    //                               LAB_004358d6                                                 XREF[1]:     004358d1(j)  
    //         004358d6     PUSH       this
    //         004358d7     PUSH       EAX
    //         004358d8     MOV        EAX,[L]                                          = 00000000
    //         004358dd     PUSH       EBP
    //         004358de     PUSH       s_______>SEND_CMD_MOVE_(CNT=%d,OWN               = "      >SEND CMD MOVE (CNT=%d,OWN=%d,UNIT=%
    //         004358e3     PUSH       EAX
    //         004358e4     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //                              Command.cpp:1579 (14)
    //         004358e9     MOV        this,dword ptr [ESP + local_4]
    //         004358ed     ADD        ESP,0x14
    //         004358f0     PUSH       EDI
    //         004358f1     PUSH       ESI
    //         004358f2     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
    //                               LAB_004358f7                                                 XREF[3]:     0043581f(j), 0043582e(j), 
    //                                                                                                         00435854(j)  
    //                              Command.cpp:1580 (8)
    //         004358f7     POP        EDI
    //         004358f8     POP        ESI
    //         004358f9     POP        EBP
    //         004358fa     POP        EBX
    //         004358fb     POP        this
    //         004358fc     RET        0x14
}

// Offset: 0x00435900
void command_move(RGE_Command* this_, int param_2, int* param_3, int param_4, int param_5, int param_6, float param_7, float param_8) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Command::command_move(int,int *,int,int,int,float,float)                  *
    //                              *********************************************************************************************************
    //                              void __thiscall command_move(RGE_Command * this, int param_1, int * 
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00435995(R)  
    //              int *             Stack[0x8]:4   param_2                   XREF[3]:     00435905(R), 0043592c(W), 00435956(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     00435915(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0043595a(R)  
    //              int               Stack[0x14]:4  param_5
    //              float             Stack[0x18]:4  param_6                   XREF[1]:     0043595e(R)  
    //              float             Stack[0x1c]:4  param_7                   XREF[1]:     00435962(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00435909(W), 00435977(R)  
    //                               ?command_move@RGE_Command@@QAEXHPAHHHHMM@Z
    //                               RGE_Command::command_move
    //                              Command.cpp:1586 (5)
    //         00435900     PUSH       this
    //         00435901     PUSH       EBX
    //         00435902     PUSH       EBP
    //         00435903     PUSH       ESI
    //         00435904     PUSH       EDI
    //                              Command.cpp:1594 (29)
    //         00435905     MOV        EDI,dword ptr [ESP + param_2]
    //         00435909     MOV        dword ptr [ESP + local_4],this
    //         0043590d     TEST       EDI,EDI
    //         0043590f     JZ         LAB_004359b8
    //         00435915     MOV        EBX,dword ptr [ESP + param_3]
    //         00435919     CMP        EBX,0x1
    //         0043591c     JL         LAB_004359b8
    //                              Command.cpp:1598 (7)
    //         00435922     LEA        EBP,[EBX*0x4 + 0x14]
    //                              Command.cpp:1599 (17)
    //         00435929     PUSH       EBP
    //         0043592a     PUSH       0x1
    //         0043592c     MOV        dword ptr [ESP + param_2],EBP
    //         00435930     CALL       calloc                                           undefined calloc()
    //         00435935     MOV        ESI,EAX
    //         00435937     ADD        ESP,0x8
    //                              Command.cpp:1604 (7)
    //         0043593a     TEST       ESI,ESI
    //         0043593c     LEA        EAX,[ESI + 0x14]
    //         0043593f     JZ         LAB_004359b8
    //                              Command.cpp:1608 (6)
    //         00435941     TEST       EBX,EBX
    //         00435943     JLE        LAB_0043595a
    //         00435945     MOV        this,EDI
    //                              Command.cpp:1628 (15)
    //         00435947     MOV        EDX,EBX
    //         00435949     SUB        this,EAX
    //                               LAB_0043594b                                                 XREF[1]:     00435954(j)  
    //         0043594b     MOV        EBP,dword ptr [this->_padding_ + EAX*0x1]
    //         0043594e     MOV        dword ptr [EAX],EBP
    //         00435950     ADD        EAX,0x4
    //         00435953     DEC        EDX
    //         00435954     JNZ        LAB_0043594b
    //                              Command.cpp:1608 (4)
    //         00435956     MOV        EBP,dword ptr [ESP + param_2]
    //                               LAB_0043595a                                                 XREF[1]:     00435943(j)  
    //                              Command.cpp:1616 (4)
    //         0043595a     MOV        EAX,dword ptr [ESP + param_4]
    //                              Command.cpp:1618 (4)
    //         0043595e     MOV        this,dword ptr [ESP + param_6]
    //                              Command.cpp:1619 (19)
    //         00435962     MOV        EDX,dword ptr [ESP + param_7]
    //         00435966     MOV        byte ptr [ESI],0x3
    //         00435969     MOV        byte ptr [ESI + 0x8],BL
    //         0043596c     MOV        dword ptr [ESI + 0x4],EAX
    //         0043596f     MOV        dword ptr [ESI + 0xc],this
    //         00435972     MOV        dword ptr [ESI + 0x10],EDX
    //                              Command.cpp:1623 (15)
    //         00435975     MOV        EAX,dword ptr [EDI]
    //         00435977     MOV        EDI,dword ptr [ESP + local_4]
    //         0043597b     PUSH       EAX
    //         0043597c     MOV        this,dword ptr [EDI + 0x4]
    //         0043597f     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              Command.cpp:1624 (43)
    //         00435984     TEST       EAX,EAX
    //         00435986     JZ         LAB_00435990
    //         00435988     MOV        this,dword ptr [EAX + 0x8]
    //         0043598b     MOV        EAX,dword ptr [ECX + this->last_order]
    //         0043598e     JMP        LAB_00435995
    //                               LAB_00435990                                                 XREF[1]:     00435986(j)  
    //         00435990     MOV        EAX,s_X                                          = "X"
    //                               LAB_00435995                                                 XREF[1]:     0043598e(j)  
    //         00435995     MOV        EDX,dword ptr [ESP + param_1]
    //         00435999     PUSH       EAX=>s_X                                         = "X"
    //         0043599a     MOV        EAX,[L]                                          = 00000000
    //         0043599f     PUSH       EDX
    //         004359a0     PUSH       EBX
    //         004359a1     PUSH       s_______>SEND_CMD_MOVE2_(CNT=%d,OW               = "      >SEND CMD MOVE2 (CNT=%d,OWN=%d,UNIT=
    //         004359a6     PUSH       EAX
    //         004359a7     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         004359ac     ADD        ESP,0x14
    //                              Command.cpp:1627 (9)
    //         004359af     MOV        this,EDI
    //         004359b1     PUSH       EBP
    //         004359b2     PUSH       ESI
    //         004359b3     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
    //                               LAB_004359b8                                                 XREF[3]:     0043590f(j), 0043591c(j), 
    //                                                                                                         0043593f(j)  
    //                              Command.cpp:1628 (8)
    //         004359b8     POP        EDI
    //         004359b9     POP        ESI
    //         004359ba     POP        EBP
    //         004359bb     POP        EBX
    //         004359bc     POP        this
    //         004359bd     RET        0x1c
}

// Offset: 0x004359C0
void command_create(RGE_Command* this_, short param_2, short param_3, float param_4, float param_5, float param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Command::command_create(short,short,float,float,float)                    *
    //                              *********************************************************************************************************
    //                              void __thiscall command_create(RGE_Command * this, short param_1, sh
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     004359d8(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[1]:     004359d1(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     004359cd(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     004359e3(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[1]:     004359ea(R)  
    //                               ?command_create@RGE_Command@@QAEXFFMMM@Z                     XREF[1]:     command_place_object:00471802(c)  
    //                               RGE_Command::command_create
    //                              Command.cpp:1634 (2)
    //         004359c0     PUSH       ESI
    //         004359c1     PUSH       EDI
    //                              Command.cpp:1642 (11)
    //         004359c2     PUSH       0x14
    //         004359c4     MOV        EDI,this
    //         004359c6     PUSH       0x1
    //         004359c8     CALL       calloc                                           undefined calloc()
    //                              Command.cpp:1648 (22)
    //         004359cd     MOV        EDX,dword ptr [ESP + param_3]
    //         004359d1     MOV        this,word ptr [ESP + param_2]
    //         004359d6     MOV        ESI,EAX
    //         004359d8     MOV        AX,word ptr [ESP + param_1]
    //         004359dd     ADD        ESP,0x8
    //         004359e0     MOV        dword ptr [ESI + 0x8],EDX
    //                              Command.cpp:1649 (7)
    //         004359e3     MOV        EDX,dword ptr [ESP + param_4]
    //         004359e7     MOV        dword ptr [ESI + 0xc],EDX
    //                              Command.cpp:1650 (10)
    //         004359ea     MOV        EDX,dword ptr [ESP + param_5]
    //         004359ee     MOV        byte ptr [ESI + 0x4],this
    //         004359f1     MOV        dword ptr [ESI + 0x10],EDX
    //                              Command.cpp:1653 (34)
    //         004359f4     MOVSX      this,this
    //         004359f7     MOVSX      EDX,AX
    //         004359fa     MOV        byte ptr [ESI],0x4
    //         004359fd     MOV        word ptr [ESI + 0x2],AX
    //         00435a01     MOV        EAX,[L]                                          = 00000000
    //         00435a06     PUSH       this
    //         00435a07     PUSH       EDX
    //         00435a08     PUSH       s_______>SEND_CMD_CREATE_(CAT=%d,P               = "      >SEND CMD CREATE (CAT=%d,PLR=%d)"
    //         00435a0d     PUSH       EAX
    //         00435a0e     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00435a13     ADD        ESP,0x10
    //                              Command.cpp:1656 (10)
    //         00435a16     MOV        this,EDI
    //         00435a18     PUSH       0x14
    //         00435a1a     PUSH       ESI
    //         00435a1b     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
    //                              Command.cpp:1657 (5)
    //         00435a20     POP        EDI
    //         00435a21     POP        ESI
    //         00435a22     RET        0x14
}

// Offset: 0x00435A30
void command_add_attribute(RGE_Command* this_, int param_2, int param_3, float param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Command::command_add_attribute(int,int,float)                             *
    //                              *********************************************************************************************************
    //                              void __thiscall command_add_attribute(RGE_Command * this, int param_
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00435a4a(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00435a3d(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     00435a41(R)  
    //                               ?command_add_attribute@RGE_Command@@QAEXHHM@Z                XREF[1]:     command_add_attribute:0047184b(c)  
    //                               RGE_Command::command_add_attribute
    //                              Command.cpp:1664 (2)
    //         00435a30     PUSH       ESI
    //         00435a31     PUSH       EDI
    //                              Command.cpp:1674 (11)
    //         00435a32     PUSH       0x8
    //         00435a34     MOV        EDI,this
    //         00435a36     PUSH       0x1
    //         00435a38     CALL       calloc                                           undefined calloc()
    //                              Command.cpp:1679 (4)
    //         00435a3d     MOV        this,dword ptr [ESP + param_2]
    //                              Command.cpp:1680 (13)
    //         00435a41     MOV        EDX,dword ptr [ESP + param_3]
    //         00435a45     ADD        ESP,0x8
    //         00435a48     MOV        ESI,EAX
    //         00435a4a     MOV        EAX,dword ptr [ESP + param_1]
    //                              Command.cpp:1683 (33)
    //         00435a4e     PUSH       this
    //         00435a4f     MOV        byte ptr [ESI],0x5
    //         00435a52     MOV        byte ptr [ESI + 0x1],AL
    //         00435a55     MOV        byte ptr [ESI + 0x2],this
    //         00435a58     MOV        dword ptr [ESI + 0x4],EDX
    //         00435a5b     PUSH       EAX
    //         00435a5c     MOV        EAX,[L]                                          = 00000000
    //         00435a61     PUSH       s_______>SEND_CMD_ADD_ATTR_(PLR=%d               = "      >SEND CMD ADD ATTR (PLR=%d,ATT=%d)"
    //         00435a66     PUSH       EAX
    //         00435a67     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00435a6c     ADD        ESP,0x10
    //                              Command.cpp:1686 (10)
    //         00435a6f     MOV        this,EDI
    //         00435a71     PUSH       0x8
    //         00435a73     PUSH       ESI
    //         00435a74     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
    //                              Command.cpp:1687 (5)
    //         00435a79     POP        EDI
    //         00435a7a     POP        ESI
    //         00435a7b     RET        0xc
}

// Offset: 0x00435A80
void RGE_Command::command_give_attribute(int param_1, int param_2, int param_3, float param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Command::command_give_attribute(int,int,int,float)                *
    //                              *********************************************************************************************************
    //                              void __thiscall command_give_attribute(RGE_Command * this, int param
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00435a9f(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00435a92(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     00435a8e(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     00435a96(R)  
    //                               ?command_give_attribute@RGE_Command@@UAEXHHHM@Z              XREF[2]:     0056f4cc(*), 00576564(*)  
    //                               RGE_Command::command_give_attribute
    //                              Command.cpp:1693 (3)
    //         00435a80     PUSH       EBX
    //         00435a81     PUSH       ESI
    //         00435a82     PUSH       EDI
    //                              Command.cpp:1704 (11)
    //         00435a83     PUSH       0x8
    //         00435a85     MOV        EDI,this
    //         00435a87     PUSH       0x1
    //         00435a89     CALL       calloc                                           undefined calloc()
    //                              Command.cpp:1710 (8)
    //         00435a8e     MOV        EDX,dword ptr [ESP + param_3]
    //         00435a92     MOV        this,dword ptr [ESP + param_2]
    //                              Command.cpp:1711 (13)
    //         00435a96     MOV        EBX,dword ptr [ESP + param_4]
    //         00435a9a     ADD        ESP,0x8
    //         00435a9d     MOV        ESI,EAX
    //         00435a9f     MOV        EAX,dword ptr [ESP + param_1]
    //                              Command.cpp:1714 (37)
    //         00435aa3     PUSH       EDX
    //         00435aa4     PUSH       this
    //         00435aa5     MOV        byte ptr [ESI],0x7
    //         00435aa8     MOV        byte ptr [ESI + 0x1],AL
    //         00435aab     MOV        byte ptr [ESI + 0x2],this
    //         00435aae     MOV        byte ptr [ESI + 0x3],DL
    //         00435ab1     MOV        dword ptr [ESI + 0x4],EBX
    //         00435ab4     PUSH       EAX
    //         00435ab5     MOV        EAX,[L]                                          = 00000000
    //         00435aba     PUSH       s_______>SEND_CMD_GIV_ATTR_(FRM=%d               = "      >SEND CMD GIV ATTR (FRM=%d,TO=%d,ATT
    //         00435abf     PUSH       EAX
    //         00435ac0     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00435ac5     ADD        ESP,0x14
    //                              Command.cpp:1717 (10)
    //         00435ac8     MOV        this,EDI
    //         00435aca     PUSH       0x8
    //         00435acc     PUSH       ESI
    //         00435acd     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
    //                              Command.cpp:1718 (6)
    //         00435ad2     POP        EDI
    //         00435ad3     POP        ESI
    //         00435ad4     POP        EBX
    //         00435ad5     RET        0x10
}

// Offset: 0x00435AE0
void command_formation(RGE_Command* this_, RGE_Static_Object** param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Command::command_formation(class RGE_Static_Object * *,int,int)           *
    //                              *********************************************************************************************************
    //                              void __thiscall command_formation(RGE_Command * this, RGE_Static_Obj
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00435ae7(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[3]:     00435ae2(R), 00435afa(W), 00435b49(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     00435b4d(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00435af4(W), 00435b99(R)  
    //                               ?command_formation@RGE_Command@@QAEXPAPAVRGE_Static_Object@  XREF[1]:     command_formation:0047190f(c)  
    //                               RGE_Command::command_formation
    //                              Command.cpp:1724 (2)
    //         00435ae0     PUSH       this
    //         00435ae1     PUSH       EBX
    //                              Command.cpp:1733 (5)
    //         00435ae2     MOV        EBX,dword ptr [ESP + param_2]
    //         00435ae6     PUSH       EBP
    //                              Command.cpp:1736 (38)
    //         00435ae7     MOV        EBP,dword ptr [ESP + param_1]
    //         00435aeb     PUSH       ESI
    //         00435aec     PUSH       EDI
    //         00435aed     LEA        EDI,[EBX*0x4 + 0xc]
    //         00435af4     MOV        dword ptr [ESP + local_4],this
    //         00435af8     TEST       EBP,EBP
    //         00435afa     MOV        dword ptr [ESP + param_2],EDI
    //         00435afe     JZ         LAB_00435ba7
    //         00435b04     CMP        EBX,0x1
    //         00435b07     JL         LAB_00435ba7
    //                              Command.cpp:1740 (13)
    //         00435b0d     PUSH       EDI
    //         00435b0e     PUSH       0x1
    //         00435b10     CALL       calloc                                           undefined calloc()
    //         00435b15     MOV        ESI,EAX
    //         00435b17     ADD        ESP,0x8
    //                              Command.cpp:1744 (11)
    //         00435b1a     TEST       ESI,ESI
    //         00435b1c     LEA        EAX,[ESI + 0xc]
    //         00435b1f     JZ         LAB_00435ba7
    //                              Command.cpp:1746 (4)
    //         00435b25     TEST       EBX,EBX
    //         00435b27     JLE        LAB_00435b4d
    //                              Command.cpp:1752 (2)
    //         00435b29     MOV        EDX,EBP
    //                              Command.cpp:1767 (18)
    //         00435b2b     MOV        EDI,EBX
    //         00435b2d     SUB        EDX,EAX
    //                               LAB_00435b2f                                                 XREF[1]:     00435b47(j)  
    //         00435b2f     MOV        this,dword ptr [EDX + EAX*0x1]
    //         00435b32     TEST       this,this
    //         00435b34     JZ         LAB_00435b3d
    //         00435b36     MOV        this,dword ptr [ECX + this->world]
    //         00435b39     MOV        dword ptr [EAX],this
    //         00435b3b     JMP        LAB_00435b43
    //                               LAB_00435b3d                                                 XREF[1]:     00435b34(j)  
    //                              Command.cpp:1752 (6)
    //         00435b3d     MOV        dword ptr [EAX],0xffffffff
    //                               LAB_00435b43                                                 XREF[1]:     00435b3b(j)  
    //                              Command.cpp:1746 (10)
    //         00435b43     ADD        EAX,0x4
    //         00435b46     DEC        EDI
    //         00435b47     JNZ        LAB_00435b2f
    //         00435b49     MOV        EDI,dword ptr [ESP + param_2]
    //                               LAB_00435b4d                                                 XREF[1]:     00435b27(j)  
    //                              Command.cpp:1759 (21)
    //         00435b4d     MOV        EAX,dword ptr [ESP + param_3]
    //         00435b51     MOV        EDX,EBX
    //         00435b53     AND        EDX,0xff
    //         00435b59     MOV        byte ptr [ESI],0x6
    //         00435b5c     MOV        dword ptr [ESI + 0x4],EDX
    //         00435b5f     MOV        dword ptr [ESI + 0x8],EAX
    //                              Command.cpp:1762 (55)
    //         00435b62     MOV        EAX,dword ptr [EBP]
    //         00435b65     TEST       EAX,EAX
    //         00435b67     JZ         LAB_00435b71
    //         00435b69     MOV        this,dword ptr [EAX + 0x8]
    //         00435b6c     MOV        this,dword ptr [ECX + this->last_order]
    //         00435b6f     JMP        LAB_00435b76
    //                               LAB_00435b71                                                 XREF[1]:     00435b67(j)  
    //         00435b71     MOV        this,s_X                                         = "X"
    //                               LAB_00435b76                                                 XREF[1]:     00435b6f(j)  
    //         00435b76     TEST       EAX,EAX
    //         00435b78     JZ         LAB_00435b83
    //         00435b7a     MOV        EDX,dword ptr [EAX + 0xc]
    //         00435b7d     MOVSX      EAX,word ptr [EDX + 0x4a]
    //         00435b81     JMP        LAB_00435b86
    //                               LAB_00435b83                                                 XREF[1]:     00435b78(j)  
    //         00435b83     OR         EAX,0xffffffff
    //                               LAB_00435b86                                                 XREF[1]:     00435b81(j)  
    //         00435b86     PUSH       this
    //         00435b87     PUSH       EAX
    //         00435b88     MOV        EAX,[L]                                          = 00000000
    //         00435b8d     PUSH       EBX
    //         00435b8e     PUSH       s_______>SEND_CMD_FORMATION_(CNT=%               = "      >SEND CMD FORMATION (CNT=%d,OWN=%d,U
    //         00435b93     PUSH       EAX
    //         00435b94     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //                              Command.cpp:1765 (14)
    //         00435b99     MOV        this,dword ptr [ESP + local_4]
    //         00435b9d     ADD        ESP,0x14
    //         00435ba0     PUSH       EDI
    //         00435ba1     PUSH       ESI
    //         00435ba2     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
    //                               LAB_00435ba7                                                 XREF[3]:     00435afe(j), 00435b07(j), 
    //                                                                                                         00435b1f(j)  
    //                              Command.cpp:1767 (8)
    //         00435ba7     POP        EDI
    //         00435ba8     POP        ESI
    //         00435ba9     POP        EBP
    //         00435baa     POP        EBX
    //         00435bab     POP        this
    //         00435bac     RET        0xc
}

// Offset: 0x00435BB0
void command_create_group(RGE_Command* this_, int param_2, int param_3, int* param_4, int param_5, float param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Command::command_create_group(int,int,int *,int,float)                    *
    //                              *********************************************************************************************************
    //                              void __thiscall command_create_group(RGE_Command * this, int param_1
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[2]:     00435bc9(R), 00435c24(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00435bc3(R)  
    //              int *             Stack[0xc]:4   param_3                   XREF[2]:     00435bdd(R), 00435bf7(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     00435bbf(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[1]:     00435bf3(R)  
    //                               ?command_create_group@RGE_Command@@QAEXHHPAHHM@Z             XREF[1]:     command_create_group:004719ef(c)  
    //                               RGE_Command::command_create_group
    //                              Command.cpp:1774 (4)
    //         00435bb0     PUSH       EBX
    //         00435bb1     PUSH       EBP
    //         00435bb2     PUSH       ESI
    //         00435bb3     PUSH       EDI
    //                              language.dll match for 0x74: "Copperplate Gothic Light"
    //                              Command.cpp:1783 (11)
    //         00435bb4     PUSH       0x74
    //         00435bb6     MOV        EDI,this
    //         00435bb8     PUSH       0x1
    //         00435bba     CALL       calloc                                           undefined calloc()
    //                              Command.cpp:1789 (39)
    //         00435bbf     MOV        EBX,dword ptr [ESP + param_4]
    //         00435bc3     MOV        this,dword ptr [ESP + param_2]
    //         00435bc7     MOV        ESI,EAX
    //         00435bc9     MOV        AL,byte ptr [ESP + param_1]
    //         00435bcd     ADD        ESP,0x8
    //         00435bd0     TEST       EBX,EBX
    //         00435bd2     MOV        byte ptr [ESI],0x8
    //         00435bd5     MOV        byte ptr [ESI + 0x1],AL
    //         00435bd8     MOV        dword ptr [ESI + 0x4],this
    //         00435bdb     JLE        LAB_00435bf3
    //         00435bdd     MOV        EAX,dword ptr [ESP + param_3]
    //         00435be1     LEA        this,[ESI + 0xc]
    //         00435be4     MOV        EDX,EBX
    //                               LAB_00435be6                                                 XREF[1]:     00435bf1(j)  
    //                              Command.cpp:1790 (13)
    //         00435be6     MOV        EBP,dword ptr [EAX]
    //         00435be8     ADD        EAX,0x4
    //         00435beb     MOV        dword ptr [this->_padding_],EBP
    //         00435bed     ADD        this,0x4
    //         00435bf0     DEC        EDX
    //         00435bf1     JNZ        LAB_00435be6
    //                               LAB_00435bf3                                                 XREF[1]:     00435bdb(j)  
    //                              Command.cpp:1792 (4)
    //         00435bf3     MOV        EDX,dword ptr [ESP + param_5]
    //                              Command.cpp:1795 (21)
    //         00435bf7     MOV        EAX,dword ptr [ESP + param_3]
    //         00435bfb     MOV        byte ptr [ESI + 0x70],BL
    //         00435bfe     MOV        dword ptr [ESI + 0x8],EDX
    //         00435c01     MOV        this,dword ptr [EAX]
    //         00435c03     PUSH       this
    //         00435c04     MOV        this,dword ptr [EDI + 0x4]
    //         00435c07     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              Command.cpp:1796 (44)
    //         00435c0c     TEST       EAX,EAX
    //         00435c0e     JZ         LAB_00435c18
    //         00435c10     MOV        EDX,dword ptr [EAX + 0x8]
    //         00435c13     MOV        EAX,dword ptr [EDX + 0x8]
    //         00435c16     JMP        LAB_00435c1d
    //                               LAB_00435c18                                                 XREF[1]:     00435c0e(j)  
    //         00435c18     MOV        EAX,s_X                                          = "X"
    //                               LAB_00435c1d                                                 XREF[1]:     00435c16(j)  
    //         00435c1d     MOV        this,dword ptr [L]                               = 00000000
    //         00435c23     PUSH       EAX=>s_X                                         = "X"
    //         00435c24     MOV        EAX,dword ptr [ESP + param_1]
    //         00435c28     PUSH       EAX
    //         00435c29     PUSH       EBX
    //         00435c2a     PUSH       s_______>SEND_CMD_CRT_GROUP_(CNT=%               = "      >SEND CMD CRT GROUP (CNT=%d,PLR=%d,U
    //         00435c2f     PUSH       this
    //         00435c30     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00435c35     ADD        ESP,0x14
    //                              Command.cpp:1799 (10)
    //         00435c38     MOV        this,EDI
    //                              language.dll match for 0x74: "Copperplate Gothic Light"
    //         00435c3a     PUSH       0x74
    //         00435c3c     PUSH       ESI
    //         00435c3d     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
    //                              Command.cpp:1800 (7)
    //         00435c42     POP        EDI
    //         00435c43     POP        ESI
    //         00435c44     POP        EBP
    //         00435c45     POP        EBX
    //         00435c46     RET        0x14
}

// Offset: 0x00435C50
void command_add_to_group(RGE_Command* this_, int param_2, int param_3, int param_4, float param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Command::command_add_to_group(int,int,int,float)                          *
    //                              *********************************************************************************************************
    //                              void __thiscall command_add_to_group(RGE_Command * this, int param_1
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00435c5e(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00435c68(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     00435c72(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     00435c62(R)  
    //                               ?command_add_to_group@RGE_Command@@QAEXHHHM@Z                XREF[1]:     command_add_to_group:00471a1a(c)  
    //                               RGE_Command::command_add_to_group
    //                              Command.cpp:1807 (3)
    //         00435c50     PUSH       EBX
    //         00435c51     PUSH       ESI
    //         00435c52     PUSH       EDI
    //                              Command.cpp:1816 (11)
    //         00435c53     PUSH       0x10
    //         00435c55     MOV        EDI,this
    //         00435c57     PUSH       0x1
    //         00435c59     CALL       calloc                                           undefined calloc()
    //                              Command.cpp:1820 (4)
    //         00435c5e     MOV        EBX,dword ptr [ESP + param_1]
    //                              Command.cpp:1823 (32)
    //         00435c62     MOV        this,dword ptr [ESP + param_4]
    //         00435c66     MOV        ESI,EAX
    //         00435c68     MOV        EAX,dword ptr [ESP + param_2]
    //         00435c6c     ADD        ESP,0x8
    //         00435c6f     MOV        dword ptr [ESI + 0x4],EAX
    //         00435c72     MOV        EAX,dword ptr [ESP + param_3]
    //         00435c76     MOV        byte ptr [ESI],0xe
    //         00435c79     MOV        byte ptr [ESI + 0x1],BL
    //         00435c7c     MOV        dword ptr [ESI + 0xc],EAX
    //         00435c7f     MOV        dword ptr [ESI + 0x8],this
    //                              Command.cpp:1826 (9)
    //         00435c82     MOV        this,dword ptr [EDI + 0x4]
    //         00435c85     PUSH       EAX
    //         00435c86     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              Command.cpp:1827 (38)
    //         00435c8b     TEST       EAX,EAX
    //         00435c8d     JZ         LAB_00435c97
    //         00435c8f     MOV        EDX,dword ptr [EAX + 0x8]
    //         00435c92     MOV        EAX,dword ptr [EDX + 0x8]
    //         00435c95     JMP        LAB_00435c9c
    //                               LAB_00435c97                                                 XREF[1]:     00435c8d(j)  
    //         00435c97     MOV        EAX,s_X                                          = "X"
    //                               LAB_00435c9c                                                 XREF[1]:     00435c95(j)  
    //         00435c9c     PUSH       EAX=>s_X                                         = "X"
    //         00435c9d     MOV        EAX,[L]                                          = 00000000
    //         00435ca2     PUSH       EBX
    //         00435ca3     PUSH       s_______>SEND_CMD_ADD_GROUP_(PLR=%               = "      >SEND CMD ADD GROUP (PLR=%d,UNIT=%s)"
    //         00435ca8     PUSH       EAX
    //         00435ca9     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00435cae     ADD        ESP,0x10
    //                              Command.cpp:1830 (10)
    //         00435cb1     MOV        this,EDI
    //         00435cb3     PUSH       0x10
    //         00435cb5     PUSH       ESI
    //         00435cb6     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
    //                              Command.cpp:1831 (6)
    //         00435cbb     POP        EDI
    //         00435cbc     POP        ESI
    //         00435cbd     POP        EBX
    //         00435cbe     RET        0x10
}

// Offset: 0x00435CD0
void command_remove_from_group(RGE_Command* this_, int param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Command::command_remove_from_group(int,int,int)                           *
    //                              *********************************************************************************************************
    //                              void __thiscall command_remove_from_group(RGE_Command * this, int pa
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00435cde(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00435ce4(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     00435cee(R)  
    //                               ?command_remove_from_group@RGE_Command@@QAEXHHH@Z            XREF[1]:     command_remove_from_group:00471a45
    //                               RGE_Command::command_remove_from_group
    //                              Command.cpp:1838 (3)
    //         00435cd0     PUSH       EBX
    //         00435cd1     PUSH       ESI
    //         00435cd2     PUSH       EDI
    //                              Command.cpp:1847 (11)
    //         00435cd3     PUSH       0xc
    //         00435cd5     MOV        EDI,this
    //         00435cd7     PUSH       0x1
    //         00435cd9     CALL       calloc                                           undefined calloc()
    //                              Command.cpp:1851 (6)
    //         00435cde     MOV        EBX,dword ptr [ESP + param_1]
    //         00435ce2     MOV        ESI,EAX
    //                              Command.cpp:1852 (10)
    //         00435ce4     MOV        EAX,dword ptr [ESP + param_2]
    //         00435ce8     ADD        ESP,0x8
    //         00435ceb     MOV        dword ptr [ESI + 0x4],EAX
    //                              Command.cpp:1853 (13)
    //         00435cee     MOV        EAX,dword ptr [ESP + param_3]
    //         00435cf2     MOV        byte ptr [ESI],0xf
    //         00435cf5     MOV        byte ptr [ESI + 0x1],BL
    //         00435cf8     MOV        dword ptr [ESI + 0x8],EAX
    //                              Command.cpp:1856 (9)
    //         00435cfb     MOV        this,dword ptr [EDI + 0x4]
    //         00435cfe     PUSH       EAX
    //         00435cff     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              Command.cpp:1857 (39)
    //         00435d04     TEST       EAX,EAX
    //         00435d06     JZ         LAB_00435d10
    //         00435d08     MOV        this,dword ptr [EAX + 0x8]
    //         00435d0b     MOV        EAX,dword ptr [ECX + this->last_order]
    //         00435d0e     JMP        LAB_00435d15
    //                               LAB_00435d10                                                 XREF[1]:     00435d06(j)  
    //         00435d10     MOV        EAX,s_X                                          = "X"
    //                               LAB_00435d15                                                 XREF[1]:     00435d0e(j)  
    //         00435d15     MOV        EDX,dword ptr [L]                                = 00000000
    //         00435d1b     PUSH       EAX=>s_X                                         = "X"
    //         00435d1c     PUSH       EBX
    //         00435d1d     PUSH       s_______>SEND_CMD_REM_GROUP_(PLR=%               = "      >SEND CMD REM GROUP (PLR=%d,UNIT=%s)"
    //         00435d22     PUSH       EDX
    //         00435d23     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00435d28     ADD        ESP,0x10
    //                              Command.cpp:1860 (10)
    //         00435d2b     MOV        this,EDI
    //         00435d2d     PUSH       0xc
    //         00435d2f     PUSH       ESI
    //         00435d30     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
    //                              Command.cpp:1861 (6)
    //         00435d35     POP        EDI
    //         00435d36     POP        ESI
    //         00435d37     POP        EBX
    //         00435d38     RET        0xc
}

// Offset: 0x00435D40
void command_destroy_group(RGE_Command* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Command::command_destroy_group(int,int)                                   *
    //                              *********************************************************************************************************
    //                              void __thiscall command_destroy_group(RGE_Command * this, int param_
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00435d53(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00435d4d(R)  
    //                               ?command_destroy_group@RGE_Command@@QAEXHH@Z                 XREF[1]:     command_destroy_group:00471a60(c)  
    //                               RGE_Command::command_destroy_group
    //                              Command.cpp:1867 (2)
    //         00435d40     PUSH       ESI
    //         00435d41     PUSH       EDI
    //                              Command.cpp:1876 (11)
    //         00435d42     PUSH       0x8
    //         00435d44     MOV        EDI,this
    //         00435d46     PUSH       0x1
    //         00435d48     CALL       calloc                                           undefined calloc()
    //                              Command.cpp:1881 (22)
    //         00435d4d     MOV        this,dword ptr [ESP + param_2]
    //         00435d51     MOV        ESI,EAX
    //         00435d53     MOV        EAX,dword ptr [ESP + param_1]
    //         00435d57     ADD        ESP,0x8
    //         00435d5a     MOV        byte ptr [ESI],0x9
    //         00435d5d     MOV        byte ptr [ESI + 0x1],AL
    //         00435d60     MOV        dword ptr [ESI + 0x4],this
    //                              Command.cpp:1884 (21)
    //         00435d63     MOV        EDX,dword ptr [L]                                = 00000000
    //         00435d69     PUSH       EAX
    //         00435d6a     PUSH       s_______>SEND_CMD_DES_GROUP_(PLR=%               = "      >SEND CMD DES GROUP (PLR=%d)"
    //         00435d6f     PUSH       EDX
    //         00435d70     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00435d75     ADD        ESP,0xc
    //                              Command.cpp:1887 (10)
    //         00435d78     MOV        this,EDI
    //         00435d7a     PUSH       0x8
    //         00435d7c     PUSH       ESI
    //         00435d7d     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
    //                              Command.cpp:1888 (5)
    //         00435d82     POP        EDI
    //         00435d83     POP        ESI
    //         00435d84     RET        0x8
}

// Offset: 0x00435D90
void command_ai_order(RGE_Command* this_, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, float param_8, float param_9, float param_10, float param_11, uchar param_12, uchar param_13, uchar param_14) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Command::command_ai_order(int,int,int,int,int,int,float,float,float,fl... *
    //                              *********************************************************************************************************
    //                              void __thiscall command_ai_order(RGE_Command * this, int param_1, in
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[2]:     00435daa(R), 00435e72(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[2]:     00435d9f(R), 00435e62(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     00435dae(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[2]:     00435da3(R), 00435e6c(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     00435db2(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[1]:     00435dc0(R)  
    //              float             Stack[0x1c]:4  param_7                   XREF[2]:     00435dc8(R), 00435e54(R)  
    //              float             Stack[0x20]:4  param_8                   XREF[2]:     00435dcf(R), 00435e4b(R)  
    //              float             Stack[0x24]:4  param_9                   XREF[1]:     00435dd6(R)  
    //              float             Stack[0x28]:4  param_10                  XREF[1]:     00435ddd(R)  
    //              uchar             Stack[0x2c]:1  param_11                  XREF[6]:     00435de4(R), 00435e11(W), 00435e33(R), 00435e41(W), 
    //                                                                                     00435e47(W), 00435e5e(R)  
    //              uchar             Stack[0x30]:1  param_12                  XREF[1]:     00435deb(R)  
    //              uchar             Stack[0x34]:1  param_13                  XREF[4]:     00435db9(R), 00435e29(W), 00435e2f(W), 00435e67(R)  
    //                               ?command_ai_order@RGE_Command@@QAEXHHHHHHMMMMEEE@Z           XREF[1]:     sendUnitAIOrder:0046ef33(c)  
    //                               RGE_Command::command_ai_order
    //                              Command.cpp:1896 (4)
    //         00435d90     PUSH       EBX
    //         00435d91     PUSH       EBP
    //         00435d92     PUSH       ESI
    //         00435d93     PUSH       EDI
    //                              Command.cpp:1909 (11)
    //         00435d94     PUSH       0x28
    //         00435d96     MOV        EDI,this
    //         00435d98     PUSH       0x1
    //         00435d9a     CALL       calloc                                           undefined calloc()
    //                              Command.cpp:1914 (4)
    //         00435d9f     MOV        this,byte ptr [ESP + param_2]
    //                              Command.cpp:1916 (15)
    //         00435da3     MOV        DX,word ptr [ESP + param_4]
    //         00435da8     MOV        ESI,EAX
    //         00435daa     MOV        AL,byte ptr [ESP + param_1]
    //         00435dae     MOV        EBP,dword ptr [ESP + param_3]
    //                              Command.cpp:1918 (14)
    //         00435db2     MOV        EBX,dword ptr [ESP + param_5]
    //         00435db6     MOV        byte ptr [ESI + 0x1],AL
    //         00435db9     MOV        AL,byte ptr [ESP + param_13]
    //         00435dbd     MOV        byte ptr [ESI + 0x2],this
    //                              Command.cpp:1919 (8)
    //         00435dc0     MOV        this,byte ptr [ESP + param_6]
    //         00435dc4     MOV        word ptr [ESI + 0x8],DX
    //                              Command.cpp:1920 (7)
    //         00435dc8     MOV        EDX,dword ptr [ESP + param_7]
    //         00435dcc     MOV        byte ptr [ESI + 0xa],AL
    //                              Command.cpp:1921 (7)
    //         00435dcf     MOV        EAX,dword ptr [ESP + param_8]
    //         00435dd3     MOV        byte ptr [ESI + 0x10],this
    //                              Command.cpp:1922 (7)
    //         00435dd6     MOV        this,dword ptr [ESP + param_9]
    //         00435dda     MOV        dword ptr [ESI + 0x14],EDX
    //                              Command.cpp:1923 (7)
    //         00435ddd     MOV        EDX,dword ptr [ESP + param_10]
    //         00435de1     MOV        dword ptr [ESI + 0x18],EAX
    //                              Command.cpp:1924 (7)
    //         00435de4     MOV        AL,byte ptr [ESP + param_11]
    //         00435de8     MOV        dword ptr [ESI + 0x1c],this
    //                              Command.cpp:1925 (25)
    //         00435deb     MOV        this,byte ptr [ESP + param_12]
    //         00435def     ADD        ESP,0x8
    //         00435df2     MOV        byte ptr [ESI],0xa
    //         00435df5     MOV        dword ptr [ESI + 0x4],EBP
    //         00435df8     MOV        dword ptr [ESI + 0xc],EBX
    //         00435dfb     MOV        dword ptr [ESI + 0x20],EDX
    //         00435dfe     MOV        byte ptr [ESI + 0x24],AL
    //         00435e01     MOV        byte ptr [ESI + 0x25],this
    //                              Command.cpp:1928 (9)
    //         00435e04     MOV        this,dword ptr [EDI + 0x4]
    //         00435e07     PUSH       EBP
    //         00435e08     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              Command.cpp:1929 (13)
    //         00435e0d     MOV        this,dword ptr [EDI + 0x4]
    //         00435e10     PUSH       EBX
    //         00435e11     MOV        dword ptr [ESP + param_11],EAX
    //         00435e15     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              Command.cpp:1930 (116)
    //         00435e1a     TEST       EAX,EAX
    //         00435e1c     MOV        this,s_X                                         = "X"
    //         00435e21     JZ         LAB_00435e2f
    //         00435e23     MOV        EDX,dword ptr [EAX + 0x8]
    //         00435e26     MOV        EAX,dword ptr [EDX + 0x8]
    //         00435e29     MOV        dword ptr [ESP + param_13],EAX
    //         00435e2d     JMP        LAB_00435e33
    //                               LAB_00435e2f                                                 XREF[1]:     00435e21(j)  
    //         00435e2f     MOV        dword ptr [ESP + param_13],this=>s_X             = "X"
    //                               LAB_00435e33                                                 XREF[1]:     00435e2d(j)  
    //         00435e33     MOV        EAX,dword ptr [ESP + param_11]
    //         00435e37     TEST       EAX,EAX
    //         00435e39     JZ         LAB_00435e47
    //         00435e3b     MOV        this,dword ptr [EAX + 0x8]
    //         00435e3e     MOV        EDX,dword ptr [ECX + this->last_order]
    //         00435e41     MOV        dword ptr [ESP + param_11],EDX
    //         00435e45     JMP        LAB_00435e4b
    //                               LAB_00435e47                                                 XREF[1]:     00435e39(j)  
    //         00435e47     MOV        dword ptr [ESP + param_11],this=>s_X             = "X"
    //                               LAB_00435e4b                                                 XREF[1]:     00435e45(j)  
    //         00435e4b     FLD        float ptr [ESP + param_8]
    //         00435e4f     CALL       __ftol                                           undefined __ftol()
    //         00435e54     FLD        float ptr [ESP + param_7]
    //         00435e58     PUSH       EAX
    //         00435e59     CALL       __ftol                                           undefined __ftol()
    //         00435e5e     MOV        this,dword ptr [ESP + param_11]
    //         00435e62     MOV        EDX,dword ptr [ESP + param_2]
    //         00435e66     PUSH       EAX
    //         00435e67     MOV        EAX,dword ptr [ESP + param_13]
    //         00435e6b     PUSH       EAX
    //         00435e6c     MOV        EAX,dword ptr [ESP + param_4]
    //         00435e70     PUSH       EBX
    //         00435e71     PUSH       this
    //         00435e72     MOV        this,dword ptr [ESP + param_1]
    //         00435e76     PUSH       EBP
    //         00435e77     PUSH       EDX
    //         00435e78     MOV        EDX,dword ptr [L]                                = 00000000
    //         00435e7e     PUSH       EAX
    //         00435e7f     PUSH       this
    //         00435e80     PUSH       s_______>SEND_CMD_AI_ORD_(PLR=%d,_               = "      >SEND CMD AI ORD (PLR=%d, TYP=%d, IS
    //         00435e85     PUSH       EDX
    //         00435e86     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00435e8b     ADD        ESP,0x2c
    //                              Command.cpp:1933 (10)
    //         00435e8e     MOV        this,EDI
    //         00435e90     PUSH       0x28
    //         00435e92     PUSH       ESI
    //         00435e93     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
    //                              Command.cpp:1934 (7)
    //         00435e98     POP        EDI
    //         00435e99     POP        ESI
    //         00435e9a     POP        EBP
    //         00435e9b     POP        EBX
    //         00435e9c     RET        0x34
}

// Offset: 0x00435EA0
void command_group_ai_order(RGE_Command* this_, int param_2, int param_3, RGE_Static_Object** param_4, short param_5, int param_6, int param_7, int param_8, float param_9, float param_10, float param_11, float param_12, uchar param_13, uchar param_14, uchar param_15) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Command::command_group_ai_order(int,int,class RGE_Static_Object * *,sh... *
    //                              *********************************************************************************************************
    //                              void __thiscall command_group_ai_order(RGE_Command * this, int param
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00435f23(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[2]:     00435f10(R), 00435fab(R)  
    //              RGE_Static_Obj    Stack[0xc]:4   param_3                   XREF[2]:     00435ea6(R), 00435f8d(R)  
    //              short             Stack[0x10]:2  param_4                   XREF[2]:     00435eb6(R), 00435f18(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     00435f27(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[1]:     00435f3c(R)  
    //              int               Stack[0x1c]:4  param_7                   XREF[1]:     00435f1f(R)  
    //              float             Stack[0x20]:4  param_8                   XREF[1]:     00435f2e(R)  
    //              float             Stack[0x24]:4  param_9                   XREF[1]:     00435f35(R)  
    //              float             Stack[0x28]:4  param_10                  XREF[1]:     00435f43(R)  
    //              float             Stack[0x2c]:4  param_11                  XREF[1]:     00435f4a(R)  
    //              uchar             Stack[0x30]:1  param_12                  XREF[1]:     00435f54(R)  
    //              uchar             Stack[0x34]:1  param_13                  XREF[1]:     00435f5b(R)  
    //              uchar             Stack[0x38]:1  param_14                  XREF[1]:     00435f14(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00435ed2(W), 00435fbf(R)  
    //              long              Stack[-0x8]:4  size                      XREF[3]:     00435eac(W), 00435f60(R), 00435fc3(R)  
    //                               ?command_group_ai_order@RGE_Command@@QAEXHHPAPAVRGE_Static_  XREF[1]:     command_stand_ground:004719aa(c)  
    //                               RGE_Command::command_group_ai_order
    //                              Command.cpp:1942 (6)
    //         00435ea0     SUB        ESP,0x8
    //         00435ea3     PUSH       EBP
    //         00435ea4     PUSH       ESI
    //         00435ea5     PUSH       EDI
    //                              Command.cpp:1954 (31)
    //         00435ea6     MOV        EDI,dword ptr [ESP + param_3]
    //         00435eaa     TEST       EDI,EDI
    //         00435eac     MOV        dword ptr [ESP + size],this
    //         00435eb0     JZ         LAB_00435fd2
    //         00435eb6     MOV        AX,word ptr [ESP + param_4]
    //         00435ebb     CMP        AX,0x1
    //         00435ebf     JL         LAB_00435fd2
    //                              Command.cpp:1958 (10)
    //         00435ec5     MOVSX      EBP,AX
    //         00435ec8     LEA        EAX,[EBP*0x4 + 0x24]
    //                              Command.cpp:1959 (17)
    //         00435ecf     PUSH       EAX
    //         00435ed0     PUSH       0x1
    //         00435ed2     MOV        dword ptr [ESP + local_4],EAX
    //         00435ed6     CALL       calloc                                           undefined calloc()
    //         00435edb     MOV        ESI,EAX
    //         00435edd     ADD        ESP,0x8
    //                              Command.cpp:1963 (11)
    //         00435ee0     TEST       ESI,ESI
    //         00435ee2     LEA        EAX,[ESI + 0x24]
    //         00435ee5     JZ         LAB_00435fd2
    //                              Command.cpp:1966 (5)
    //         00435eeb     TEST       EBP,EBP
    //         00435eed     PUSH       EBX
    //         00435eee     JLE        LAB_00435f10
    //                              Command.cpp:1971 (2)
    //         00435ef0     MOV        EDX,EDI
    //                              Command.cpp:1997 (18)
    //         00435ef2     MOV        EDI,EBP
    //         00435ef4     SUB        EDX,EAX
    //                               LAB_00435ef6                                                 XREF[1]:     00435f0e(j)  
    //         00435ef6     MOV        this,dword ptr [EDX + EAX*0x1]
    //         00435ef9     TEST       this,this
    //         00435efb     JZ         LAB_00435f04
    //         00435efd     MOV        this,dword ptr [ECX + this->world]
    //         00435f00     MOV        dword ptr [EAX],this
    //         00435f02     JMP        LAB_00435f0a
    //                               LAB_00435f04                                                 XREF[1]:     00435efb(j)  
    //                              Command.cpp:1971 (6)
    //         00435f04     MOV        dword ptr [EAX],0xffffffff
    //                               LAB_00435f0a                                                 XREF[1]:     00435f02(j)  
    //                              Command.cpp:1966 (6)
    //         00435f0a     ADD        EAX,0x4
    //         00435f0d     DEC        EDI
    //         00435f0e     JNZ        LAB_00435ef6
    //                               LAB_00435f10                                                 XREF[1]:     00435eee(j)  
    //                              Command.cpp:1977 (4)
    //         00435f10     MOV        DL,byte ptr [ESP + param_2]
    //                              Command.cpp:1980 (11)
    //         00435f14     MOV        this,byte ptr [ESP + param_14]
    //         00435f18     MOV        AL,byte ptr [ESP + param_4]
    //         00435f1c     MOV        byte ptr [ESI + 0x2],DL
    //                              Command.cpp:1982 (15)
    //         00435f1f     MOV        DL,byte ptr [ESP + param_7]
    //         00435f23     MOV        EBX,dword ptr [ESP + param_1]
    //         00435f27     MOV        EDI,dword ptr [ESP + param_5]
    //         00435f2b     MOV        byte ptr [ESI + 0x6],this
    //                              Command.cpp:1983 (7)
    //         00435f2e     MOV        this,dword ptr [ESP + param_8]
    //         00435f32     MOV        byte ptr [ESI + 0xc],DL
    //                              Command.cpp:1984 (14)
    //         00435f35     MOV        EDX,dword ptr [ESP + param_9]
    //         00435f39     MOV        byte ptr [ESI + 0x3],AL
    //         00435f3c     MOV        EAX,dword ptr [ESP + param_6]
    //         00435f40     MOV        dword ptr [ESI + 0x10],this
    //                              Command.cpp:1985 (7)
    //         00435f43     MOV        this,dword ptr [ESP + param_10]
    //         00435f47     MOV        dword ptr [ESI + 0x14],EDX
    //                              Command.cpp:1986 (10)
    //         00435f4a     MOV        EDX,dword ptr [ESP + param_11]
    //         00435f4e     MOV        dword ptr [ESI + 0x8],EAX
    //         00435f51     MOV        dword ptr [ESI + 0x18],this
    //                              Command.cpp:1987 (7)
    //         00435f54     MOV        this,byte ptr [ESP + param_12]
    //         00435f58     MOV        dword ptr [ESI + 0x1c],EDX
    //                              Command.cpp:1988 (4)
    //         00435f5b     MOV        DL,byte ptr [ESP + param_13]
    //                              Command.cpp:1991 (29)
    //         00435f5f     PUSH       EAX
    //         00435f60     MOV        EAX,dword ptr [ESP + size]
    //         00435f64     MOV        byte ptr [ESI],0x11
    //         00435f67     MOV        byte ptr [ESI + 0x1],BL
    //         00435f6a     MOV        word ptr [ESI + 0x4],DI
    //         00435f6e     MOV        byte ptr [ESI + 0x20],this
    //         00435f71     MOV        byte ptr [ESI + 0x21],DL
    //         00435f74     MOV        this,dword ptr [EAX + 0x4]
    //         00435f77     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              Command.cpp:1992 (67)
    //         00435f7c     TEST       EAX,EAX
    //         00435f7e     JZ         LAB_00435f88
    //         00435f80     MOV        this,dword ptr [EAX + 0x8]
    //         00435f83     MOV        this,dword ptr [ECX + this->last_order]
    //         00435f86     JMP        LAB_00435f8d
    //                               LAB_00435f88                                                 XREF[1]:     00435f7e(j)  
    //         00435f88     MOV        this,s_X                                         = "X"
    //                               LAB_00435f8d                                                 XREF[1]:     00435f86(j)  
    //         00435f8d     MOV        EDX,dword ptr [ESP + param_3]
    //         00435f91     MOV        EAX,dword ptr [EDX]
    //         00435f93     TEST       EAX,EAX
    //         00435f95     JZ         LAB_00435f9f
    //         00435f97     MOV        EAX,dword ptr [EAX + 0x8]
    //         00435f9a     MOV        EAX,dword ptr [EAX + 0x8]
    //         00435f9d     JMP        LAB_00435fa4
    //                               LAB_00435f9f                                                 XREF[1]:     00435f95(j)  
    //         00435f9f     MOV        EAX,s_X                                          = "X"
    //                               LAB_00435fa4                                                 XREF[1]:     00435f9d(j)  
    //         00435fa4     MOV        EDX,dword ptr [L]                                = 00000000
    //         00435faa     PUSH       this
    //         00435fab     MOV        this,dword ptr [ESP + param_2]
    //         00435faf     PUSH       EAX=>s_X                                         = "X"
    //         00435fb0     PUSH       EBP
    //         00435fb1     PUSH       this
    //         00435fb2     PUSH       EDI
    //         00435fb3     PUSH       EBX
    //         00435fb4     PUSH       s_______>SEND_CMD_GRP_AI_ORD_(PLR=               = "      >SEND CMD GRP AI ORD (PLR=%d, TYP=%d
    //         00435fb9     PUSH       EDX
    //         00435fba     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //                              Command.cpp:1995 (19)
    //         00435fbf     MOV        EAX,dword ptr [ESP + local_4]
    //         00435fc3     MOV        this,dword ptr [ESP + size]
    //         00435fc7     ADD        ESP,0x20
    //         00435fca     PUSH       EAX
    //         00435fcb     PUSH       ESI
    //         00435fcc     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
    //         00435fd1     POP        EBX
    //                               LAB_00435fd2                                                 XREF[3]:     00435eb0(j), 00435ebf(j), 
    //                                                                                                         00435ee5(j)  
    //                              Command.cpp:1997 (9)
    //         00435fd2     POP        EDI
    //         00435fd3     POP        ESI
    //         00435fd4     POP        EBP
    //         00435fd5     ADD        ESP,0x8
    //         00435fd8     RET        0x38
}

// Offset: 0x00435FE0
void command_resign(RGE_Command* this_, int param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Command::command_resign(int,int,int)                                      *
    //                              *********************************************************************************************************
    //                              void __thiscall command_resign(RGE_Command * this, int param_1, int 
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00435ff3(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00435fed(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     00435ffd(R)  
    //                               ?command_resign@RGE_Command@@QAEXHHH@Z                       XREF[1]:     command_resign:00471a8f(c)  
    //                               RGE_Command::command_resign
    //                              Command.cpp:2003 (2)
    //         00435fe0     PUSH       ESI
    //         00435fe1     PUSH       EDI
    //                              Command.cpp:2011 (11)
    //         00435fe2     PUSH       0x4
    //         00435fe4     MOV        EDI,this
    //         00435fe6     PUSH       0x1
    //         00435fe8     CALL       calloc                                           undefined calloc()
    //                              Command.cpp:2016 (16)
    //         00435fed     MOV        this,byte ptr [ESP + param_2]
    //         00435ff1     MOV        ESI,EAX
    //         00435ff3     MOV        EAX,dword ptr [ESP + param_1]
    //         00435ff7     ADD        ESP,0x8
    //         00435ffa     MOV        byte ptr [ESI + 0x2],this
    //                              Command.cpp:2017 (13)
    //         00435ffd     MOV        this,dword ptr [ESP + param_3]
    //         00436001     MOV        byte ptr [ESI],0xb
    //         00436004     MOV        byte ptr [ESI + 0x1],AL
    //         00436007     MOV        byte ptr [ESI + 0x3],this
    //                              Command.cpp:2020 (22)
    //         0043600a     MOV        EDX,dword ptr [L]                                = 00000000
    //         00436010     PUSH       this
    //         00436011     PUSH       EAX
    //         00436012     PUSH       s_______>SEND_CMD_RESIGN_(PLR=%d,D               = "      >SEND CMD RESIGN (PLR=%d,DROP=%d)"
    //         00436017     PUSH       EDX
    //         00436018     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0043601d     ADD        ESP,0x10
    //                              Command.cpp:2023 (10)
    //         00436020     MOV        this,EDI
    //         00436022     PUSH       0x4
    //         00436024     PUSH       ESI
    //         00436025     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
    //                              Command.cpp:2024 (5)
    //         0043602a     POP        EDI
    //         0043602b     POP        ESI
    //         0043602c     RET        0xc
}

// Offset: 0x00436030
void command_add_waypoint(RGE_Command* this_, int param_2, int param_3, XYZBYTEPoint* param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Command::command_add_waypoint(int,int,struct XYZBYTEPoint *,int)          *
    //                              *********************************************************************************************************
    //                              void __thiscall command_add_waypoint(RGE_Command * this, int param_1
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[2]:     00436049(R), 004360a0(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00436043(R)  
    //              XYZBYTEPoint *    Stack[0xc]:4   param_3                   XREF[1]:     00436060(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0043603f(R)  
    //                               ?command_add_waypoint@RGE_Command@@QAEXHHPAUXYZBYTEPoint@@H@Z XREF[1]:     sendAddWaypointCommand:0046effa(c)
    //                               RGE_Command::command_add_waypoint
    //                              Command.cpp:2031 (4)
    //         00436030     PUSH       EBX
    //         00436031     PUSH       EBP
    //         00436032     PUSH       ESI
    //         00436033     PUSH       EDI
    //                              Command.cpp:2050 (11)
    //         00436034     PUSH       0x18
    //         00436036     MOV        EBP,this
    //         00436038     PUSH       0x1
    //         0043603a     CALL       calloc                                           undefined calloc()
    //                              Command.cpp:2056 (17)
    //         0043603f     MOV        EDX,dword ptr [ESP + param_4]
    //         00436043     MOV        EBX,dword ptr [ESP + param_2]
    //         00436047     MOV        ESI,EAX
    //         00436049     MOV        AL,byte ptr [ESP + param_1]
    //         0043604d     ADD        ESP,0x8
    //                              Command.cpp:2057 (28)
    //         00436050     TEST       EDX,EDX
    //         00436052     MOV        byte ptr [ESI],0xc
    //         00436055     MOV        byte ptr [ESI + 0x1],AL
    //         00436058     MOV        dword ptr [ESI + 0x4],EBX
    //         0043605b     MOV        byte ptr [ESI + 0x8],DL
    //         0043605e     JLE        LAB_00436086
    //         00436060     MOV        this,dword ptr [ESP + param_3]
    //         00436064     MOV        EDI,EDX
    //         00436066     LEA        EAX,[ECX + this+0x2]
    //         00436069     LEA        this,[ESI + 0xa]
    //                               LAB_0043606c                                                 XREF[1]:     00436084(j)  
    //                              Command.cpp:2059 (9)
    //         0043606c     MOV        DL,byte ptr [EAX + -0x2]
    //         0043606f     ADD        EAX,0x3
    //         00436072     MOV        byte ptr [this->_padding_ + -0x1],DL
    //                              Command.cpp:2060 (5)
    //         00436075     MOV        DL,byte ptr [EAX + -0x4]
    //         00436078     MOV        byte ptr [this->_padding_],DL
    //                              Command.cpp:2061 (12)
    //         0043607a     MOV        DL,byte ptr [EAX + -0x3]
    //         0043607d     MOV        byte ptr [ECX + this+0x1],DL
    //         00436080     ADD        this,0x3
    //         00436083     DEC        EDI
    //         00436084     JNZ        LAB_0043606c
    //                               LAB_00436086                                                 XREF[1]:     0043605e(j)  
    //                              Command.cpp:2065 (9)
    //         00436086     MOV        this,dword ptr [EBP + 0x4]
    //         00436089     PUSH       EBX
    //         0043608a     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              Command.cpp:2066 (43)
    //         0043608f     TEST       EAX,EAX
    //         00436091     JZ         LAB_0043609b
    //         00436093     MOV        EAX,dword ptr [EAX + 0x8]
    //         00436096     MOV        EAX,dword ptr [EAX + 0x8]
    //         00436099     JMP        LAB_004360a0
    //                               LAB_0043609b                                                 XREF[1]:     00436091(j)  
    //         0043609b     MOV        EAX,s_X                                          = "X"
    //                               LAB_004360a0                                                 XREF[1]:     00436099(j)  
    //         004360a0     MOV        this,dword ptr [ESP + param_1]
    //         004360a4     MOV        EDX,dword ptr [L]                                = 00000000
    //         004360aa     PUSH       EAX=>s_X                                         = "X"
    //         004360ab     PUSH       this
    //         004360ac     PUSH       s_______>SEND_CMD_ADD_WAY_(PLR=%d,               = "      >SEND CMD ADD WAY (PLR=%d,REC=%s)"
    //         004360b1     PUSH       EDX
    //         004360b2     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         004360b7     ADD        ESP,0x10
    //                              Command.cpp:2069 (10)
    //         004360ba     MOV        this,EBP
    //         004360bc     PUSH       0x18
    //         004360be     PUSH       ESI
    //         004360bf     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
    //                              Command.cpp:2070 (7)
    //         004360c4     POP        EDI
    //         004360c5     POP        ESI
    //         004360c6     POP        EBP
    //         004360c7     POP        EBX
    //         004360c8     RET        0x10
}

// Offset: 0x004360D0
void command_add_waypoint(RGE_Command* this_, int param_2, int param_3, uchar param_4, uchar param_5, uchar param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Command::command_add_waypoint(int,int,unsigned char,unsigned char,unsi... *
    //                              *********************************************************************************************************
    //                              void __thiscall command_add_waypoint(RGE_Command * this, int param_1
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004360e2(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004360ec(R)  
    //              uchar             Stack[0xc]:1   param_3                   XREF[1]:     004360de(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[1]:     004360e6(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[1]:     004360f6(R)  
    //                               ?command_add_waypoint@RGE_Command@@QAEXHHEEE@Z
    //                               RGE_Command::command_add_waypoint
    //                              Command.cpp:2077 (3)
    //         004360d0     PUSH       EBX
    //         004360d1     PUSH       ESI
    //         004360d2     PUSH       EDI
    //                              Command.cpp:2089 (11)
    //         004360d3     PUSH       0x18
    //         004360d5     MOV        EDI,this
    //         004360d7     PUSH       0x1
    //         004360d9     CALL       calloc                                           undefined calloc()
    //                              Command.cpp:2096 (8)
    //         004360de     MOV        this,byte ptr [ESP + param_3]
    //         004360e2     MOV        EBX,dword ptr [ESP + param_1]
    //                              Command.cpp:2097 (16)
    //         004360e6     MOV        DL,byte ptr [ESP + param_4]
    //         004360ea     MOV        ESI,EAX
    //         004360ec     MOV        EAX,dword ptr [ESP + param_2]
    //         004360f0     ADD        ESP,0x8
    //         004360f3     MOV        byte ptr [ESI + 0x9],this
    //                              Command.cpp:2098 (23)
    //         004360f6     MOV        this,byte ptr [ESP + param_5]
    //         004360fa     MOV        byte ptr [ESI],0xc
    //         004360fd     MOV        byte ptr [ESI + 0x1],BL
    //         00436100     MOV        dword ptr [ESI + 0x4],EAX
    //         00436103     MOV        byte ptr [ESI + 0x8],0x1
    //         00436107     MOV        byte ptr [ESI + 0xa],DL
    //         0043610a     MOV        byte ptr [ESI + 0xb],this
    //                              Command.cpp:2101 (9)
    //         0043610d     MOV        this,dword ptr [EDI + 0x4]
    //         00436110     PUSH       EAX
    //         00436111     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              Command.cpp:2102 (38)
    //         00436116     TEST       EAX,EAX
    //         00436118     JZ         LAB_00436122
    //         0043611a     MOV        EDX,dword ptr [EAX + 0x8]
    //         0043611d     MOV        EAX,dword ptr [EDX + 0x8]
    //         00436120     JMP        LAB_00436127
    //                               LAB_00436122                                                 XREF[1]:     00436118(j)  
    //         00436122     MOV        EAX,s_X                                          = "X"
    //                               LAB_00436127                                                 XREF[1]:     00436120(j)  
    //         00436127     PUSH       EAX=>s_X                                         = "X"
    //         00436128     MOV        EAX,[L]                                          = 00000000
    //         0043612d     PUSH       EBX
    //         0043612e     PUSH       s_______>SEND_CMD_ADD_WAY2_(PLR=%d               = "      >SEND CMD ADD WAY2 (PLR=%d,REC=%s)"
    //         00436133     PUSH       EAX
    //         00436134     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00436139     ADD        ESP,0x10
    //                              Command.cpp:2105 (10)
    //         0043613c     MOV        this,EDI
    //         0043613e     PUSH       0x18
    //         00436140     PUSH       ESI
    //         00436141     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
    //                              Command.cpp:2106 (6)
    //         00436146     POP        EDI
    //         00436147     POP        ESI
    //         00436148     POP        EBX
    //         00436149     RET        0x14
}

// Offset: 0x00436150
void command_group_waypoint(RGE_Command* this_, RGE_Static_Object** param_2, short param_3, uchar param_4, uchar param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Command::command_group_waypoint(class RGE_Static_Object * *,short,unsi... *
    //                              *********************************************************************************************************
    //                              void __thiscall command_group_waypoint(RGE_Command * this, RGE_Stati
    //              void              <VOID>         <RETURN>
    //              RGE_Command *     ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00436158(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[3]:     00436152(R), 0043616e(W), 00436202(R)  
    //              uchar             Stack[0xc]:1   param_3                   XREF[1]:     004361b8(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[1]:     004361bc(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0043616a(W), 0043620a(R)  
    //                               ?command_group_waypoint@RGE_Command@@QAEXPAPAVRGE_Static_Ob  XREF[1]:     command_add_waypoint:00471af5(c)  
    //                               RGE_Command::command_group_waypoint
    //                              Command.cpp:2112 (2)
    //         00436150     PUSH       this
    //         00436151     PUSH       EBX
    //                              Command.cpp:2115 (6)
    //         00436152     MOV        BX,word ptr [ESP + param_2]
    //         00436157     PUSH       EBP
    //                              Command.cpp:2123 (42)
    //         00436158     MOV        EBP,dword ptr [ESP + param_1]
    //         0043615c     PUSH       ESI
    //         0043615d     PUSH       EDI
    //         0043615e     MOVSX      ESI,BX
    //         00436161     TEST       EBP,EBP
    //         00436163     LEA        EAX,[ESI*0x4 + 0x4]
    //         0043616a     MOV        dword ptr [ESP + local_4],this
    //         0043616e     MOV        dword ptr [ESP + param_2],EAX
    //         00436172     JZ         LAB_00436214
    //         00436178     CMP        BX,0x1
    //         0043617c     JL         LAB_00436214
    //                              Command.cpp:2127 (13)
    //         00436182     PUSH       EAX
    //         00436183     PUSH       0x1
    //         00436185     CALL       calloc                                           undefined calloc()
    //         0043618a     MOV        EDI,EAX
    //         0043618c     ADD        ESP,0x8
    //                              Command.cpp:2131 (7)
    //         0043618f     TEST       EDI,EDI
    //         00436191     LEA        EAX,[EDI + 0x4]
    //         00436194     JZ         LAB_00436214
    //                              Command.cpp:2134 (4)
    //         00436196     TEST       ESI,ESI
    //         00436198     JLE        LAB_004361b8
    //                              Command.cpp:2142 (24)
    //         0043619a     MOV        EDX,EBP
    //         0043619c     SUB        EDX,EAX
    //                               LAB_0043619e                                                 XREF[1]:     004361b6(j)  
    //         0043619e     MOV        this,dword ptr [EDX + EAX*0x1]
    //         004361a1     TEST       this,this
    //         004361a3     JZ         LAB_004361ac
    //         004361a5     MOV        this,dword ptr [ECX + this->world]
    //         004361a8     MOV        dword ptr [EAX],this
    //         004361aa     JMP        LAB_004361b2
    //                               LAB_004361ac                                                 XREF[1]:     004361a3(j)  
    //         004361ac     MOV        dword ptr [EAX],0xffffffff
    //                               LAB_004361b2                                                 XREF[1]:     004361aa(j)  
    //                              Command.cpp:2134 (6)
    //         004361b2     ADD        EAX,0x4
    //         004361b5     DEC        ESI
    //         004361b6     JNZ        LAB_0043619e
    //                               LAB_004361b8                                                 XREF[1]:     00436198(j)  
    //                              Command.cpp:2149 (4)
    //         004361b8     MOV        DL,byte ptr [ESP + param_3]
    //                              Command.cpp:2150 (16)
    //         004361bc     MOV        AL,byte ptr [ESP + param_4]
    //         004361c0     MOV        byte ptr [EDI],0x10
    //         004361c3     MOV        byte ptr [EDI + 0x1],BL
    //         004361c6     MOV        byte ptr [EDI + 0x2],DL
    //         004361c9     MOV        byte ptr [EDI + 0x3],AL
    //                              Command.cpp:2153 (54)
    //         004361cc     MOV        EAX,dword ptr [EBP]
    //         004361cf     TEST       EAX,EAX
    //         004361d1     JZ         LAB_004361db
    //         004361d3     MOV        this,dword ptr [EAX + 0x8]
    //         004361d6     MOV        this,dword ptr [ECX + this->last_order]
    //         004361d9     JMP        LAB_004361e0
    //                               LAB_004361db                                                 XREF[1]:     004361d1(j)  
    //         004361db     MOV        this,s_X                                         = "X"
    //                               LAB_004361e0                                                 XREF[1]:     004361d9(j)  
    //         004361e0     TEST       EAX,EAX
    //         004361e2     JZ         LAB_004361ed
    //         004361e4     MOV        EDX,dword ptr [EAX + 0xc]
    //         004361e7     MOVSX      EAX,word ptr [EDX + 0x4a]
    //         004361eb     JMP        LAB_004361f0
    //                               LAB_004361ed                                                 XREF[1]:     004361e2(j)  
    //         004361ed     OR         EAX,0xffffffff
    //                               LAB_004361f0                                                 XREF[1]:     004361eb(j)  
    //         004361f0     PUSH       this
    //         004361f1     PUSH       EAX
    //         004361f2     MOV        EAX,[L]                                          = 00000000
    //         004361f7     PUSH       s_______>SEND_CMD_GRP_WAY_(PLR=%d,               = "      >SEND CMD GRP WAY (PLR=%d,UNIT=%s)"
    //         004361fc     PUSH       EAX
    //         004361fd     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //                              Command.cpp:2156 (18)
    //         00436202     MOV        this,dword ptr [ESP + param_2]
    //         00436206     ADD        ESP,0x10
    //         00436209     PUSH       this
    //         0043620a     MOV        this,dword ptr [ESP + local_4]
    //         0043620e     PUSH       EDI
    //         0043620f     CALL       RGE_Command::submit                              void submit(RGE_Command * this, void * param_
    //                               LAB_00436214                                                 XREF[3]:     00436172(j), 0043617c(j), 
    //                                                                                                         00436194(j)  
    //                              Command.cpp:2158 (8)
    //         00436214     POP        EDI
    //         00436215     POP        ESI
    //         00436216     POP        EBP
    //         00436217     POP        EBX
    //         00436218     POP        this
    //         00436219     RET        0x10
}

