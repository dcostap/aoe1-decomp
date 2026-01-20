// Auto-generated scaffold unit: aimodule.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/aimodule.cpp
#include "../include/common.h"

// Offset: 0x004087F0
int InformationAIModule::loadState(char* param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual int __thiscall AIModule::loadState(char *)                                            *
    //                              *********************************************************************************************************
    //                              int __thiscall loadState(AIModule * this, char * param_1)
    //              int               EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1
    //                               ?loadState@AIModule@@UAEHPAD@Z                               XREF[19]:    0056e758(*), 0056e7c0(*), 
    //                               AIModule::loadState                                                       0056e838(*), 0056e878(*), 
    //                                                                                                         0056e8b8(*), 0056e8f8(*), 
    //                                                                                                         0056e950(*), 0056e9a8(*), 
    //                                                                                                         0056e9f8(*), 0056ea38(*), 
    //                                                                                                         0056ea78(*), 0056eab8(*), 
    //                                                                                                         00575460(*), 005754c0(*), 
    //                                                                                                         00575530(*), 005755e8(*), 
    //                                                                                                         00575658(*), 005756b8(*), 
    //                                                                                                         005757a8(*)  
    //                              aimodule.h:156 (5)
    //         004087f0     XOR        EAX,EAX
    //         004087f2     RET        0x4
}

// Offset: 0x00408800
int InformationAIModule::saveState(char* param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual int __thiscall AIModule::saveState(char *)                                            *
    //                              *********************************************************************************************************
    //                              int __thiscall saveState(AIModule * this, char * param_1)
    //              int               EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1
    //                               ?saveState@AIModule@@UAEHPAD@Z                               XREF[19]:    0056e75c(*), 0056e7c4(*), 
    //                               AIModule::saveState                                                       0056e83c(*), 0056e87c(*), 
    //                                                                                                         0056e8bc(*), 0056e8fc(*), 
    //                                                                                                         0056e954(*), 0056e9ac(*), 
    //                                                                                                         0056e9fc(*), 0056ea3c(*), 
    //                                                                                                         0056ea7c(*), 0056eabc(*), 
    //                                                                                                         00575464(*), 005754c4(*), 
    //                                                                                                         00575534(*), 005755ec(*), 
    //                                                                                                         0057565c(*), 005756bc(*), 
    //                                                                                                         005757ac(*)  
    //                              aimodule.h:157 (5)
    //         00408800     XOR        EAX,EAX
    //         00408802     RET        0x4
}

// Offset: 0x00408810
int InformationAIModule::gleanState(int param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual int __thiscall AIModule::gleanState(int)                                              *
    //                              *********************************************************************************************************
    //                              int __thiscall gleanState(AIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //                               ?gleanState@AIModule@@UAEHH@Z                                XREF[19]:    0056e760(*), 0056e7c8(*), 
    //                               AIModule::gleanState                                                      0056e840(*), 0056e880(*), 
    //                                                                                                         0056e8c0(*), 0056e900(*), 
    //                                                                                                         0056e958(*), 0056e9b0(*), 
    //                                                                                                         0056ea00(*), 0056ea40(*), 
    //                                                                                                         0056ea80(*), 0056eac0(*), 
    //                                                                                                         00575468(*), 005754c8(*), 
    //                                                                                                         00575538(*), 005755f0(*), 
    //                                                                                                         00575660(*), 005756c0(*), 
    //                                                                                                         005757b0(*)  
    //                              aimodule.h:158 (5)
    //         00408810     XOR        EAX,EAX
    //         00408812     RET        0x4
}

// Offset: 0x0040DD90
undefined AIModuleID(AIModuleID* this_, char* param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall AIModuleID::AIModuleID(char *,int)                                                 *
    //                              *********************************************************************************************************
    //                              undefined __thiscall AIModuleID(AIModuleID * this, char * param_1, i
    //              undefined         <UNASSIGNED>   <RETURN>
    //              AIModuleID *      ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0040dd9a(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040dd90(R)  
    //                               ??0AIModuleID@@QAE@PADH@Z                                    XREF[8]:     AIModuleMessage:0040dea6(c), 
    //                               AIModuleID::AIModuleID                                                    AIModuleMessage:0040debb(c), 
    //                                                                                                         AIModuleMessage:0040df90(c), 
    //                                                                                                         AIModuleMessage:0040dfad(c), 
    //                                                                                                         AIModuleMessage:0040e078(c), 
    //                                                                                                         AIModuleMessage:0040e099(c), 
    //                                                                                                         AIModule:0040e22f(c), 
    //                                                                                                         AIModule:0040e2e2(c)  
    //                              aimodule.cpp:29 (10)
    //         0040dd90     MOV        EAX,dword ptr [ESP + param_2]
    //         0040dd94     PUSH       EBX
    //         0040dd95     MOV        EBX,this
    //         0040dd97     MOV        dword ptr [EBX + 0x4],EAX
    //                              aimodule.cpp:30 (14)
    //         0040dd9a     MOV        EAX,dword ptr [ESP + param_1]
    //         0040dd9e     TEST       EAX,EAX
    //         0040dda0     MOV        dword ptr [EBX],AIModuleID::`vftable'            = 0040ddf0
    //         0040dda6     JZ         LAB_0040ddbd
    //                              aimodule.cpp:31 (15)
    //         0040dda8     PUSH       0x3f
    //         0040ddaa     LEA        this,[EBX + 0x8]
    //         0040ddad     PUSH       EAX
    //         0040ddae     PUSH       this
    //         0040ddaf     CALL       strncpy                                          undefined strncpy()
    //         0040ddb4     ADD        ESP,0xc
    //                              aimodule.cpp:34 (6)
    //         0040ddb7     MOV        EAX,EBX
    //         0040ddb9     POP        EBX
    //         0040ddba     RET        0x8
    //                               LAB_0040ddbd                                                 XREF[1]:     0040dda6(j)  
    //                              aimodule.cpp:29 (1)
    //         0040ddbd     PUSH       EDI
    //                              aimodule.cpp:33 (33)
    //         0040ddbe     MOV        EDI,s_                                           = ""
    //         0040ddc3     OR         this,0xffffffff
    //         0040ddc6     XOR        EAX,EAX
    //         0040ddc8     SCASB.RE   ES:EDI=>s_                                       = ""
    //         0040ddca     NOT        this
    //         0040ddcc     SUB        EDI,this
    //         0040ddce     PUSH       ESI
    //         0040ddcf     LEA        EDX,[EBX + 0x8]
    //         0040ddd2     MOV        EAX,this
    //         0040ddd4     MOV        ESI,EDI
    //         0040ddd6     MOV        EDI,EDX
    //         0040ddd8     SHR        this,0x2
    //         0040dddb     MOVSD.REP  ES:EDI,ESI
    //         0040dddd     MOV        this,EAX
    //                              aimodule.cpp:34 (13)
    //         0040dddf     MOV        EAX,EBX
    //         0040dde1     AND        this,0x3
    //         0040dde4     MOVSB.REP  ES:EDI,ESI
    //         0040dde6     POP        ESI
    //         0040dde7     POP        EDI
    //         0040dde8     POP        EBX
    //         0040dde9     RET        0x8
}

// Offset: 0x0040DE10
void AIModuleID(AIModuleID* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall AIModuleID::~AIModuleID(void)                                              *
    //                              *********************************************************************************************************
    //                              void __thiscall ~AIModuleID(AIModuleID * this)
    //              void              <VOID>         <RETURN>
    //              AIModuleID *      ECX:4 (auto)   this
    //                               ??1AIModuleID@@UAE@XZ                                        XREF[12]:    `vector_deleting_destructor':0040d
    //                               AIModuleID::~AIModuleID                                                   ~AIModuleMessage:0040e166(c), 
    //                                                                                                         ~AIModuleMessage:0040e179(c), 
    //                                                                                                         ~AIModule:0040e392(c), 
    //                                                                                                         purgeMessages:0040e774(c), 
    //                                                                                                         purgeMessagesWithID:0040e784(c), 
    //                                                                                                         purgeMessagesWithPriorityBelow:004
    //                                                                                                         purgeMessagesWithData:0040e7a4(c), 
    //                                                                                                         purgeCallbacks:0040e7b4(c), 
    //                                                                                                         purgeCallbacksWithID:0040e7c4(c), 
    //                                                                                                         purgeCallbacksWithPriorityBelow:00
    //                                                                                                         purgeCallbacksWithData:0040e7e4(c)
    //                              aimodule.cpp:39 (6)
    //         0040de10     MOV        dword ptr [this->_padding_],AIModuleID::`vftab   = 0040ddf0
    //                              aimodule.cpp:40 (1)
    //         0040de16     RET
}

// Offset: 0x0040DE20
void setID(AIModuleID* this_, int param_2, char* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall AIModuleID::setID(int,char *)                                                 *
    //                              *********************************************************************************************************
    //                              void __thiscall setID(AIModuleID * this, int param_1, char * param_2)
    //              void              <VOID>         <RETURN>
    //              AIModuleID *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040de20(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     0040de27(R)  
    //                               ?setID@AIModuleID@@QAEXHPAD@Z                                XREF[2]:     setSender:0040e1f0(c), 
    //                               AIModuleID::setID                                                         setRecipient:0040e210(c)  
    //                              aimodule.cpp:45 (7)
    //         0040de20     MOV        EAX,dword ptr [ESP + param_1]
    //         0040de24     MOV        dword ptr [ECX + this->id],EAX
    //                              aimodule.cpp:47 (8)
    //         0040de27     MOV        EAX,dword ptr [ESP + param_2]
    //         0040de2b     TEST       EAX,EAX
    //         0040de2d     JZ         LAB_0040de41
    //                              aimodule.cpp:48 (15)
    //         0040de2f     PUSH       0x3f
    //         0040de31     ADD        this,0x8
    //         0040de34     PUSH       EAX
    //         0040de35     PUSH       this
    //         0040de36     CALL       strncpy                                          undefined strncpy()
    //         0040de3b     ADD        ESP,0xc
    //                              aimodule.cpp:51 (3)
    //         0040de3e     RET        0x8
    //                               LAB_0040de41                                                 XREF[1]:     0040de2d(j)  
    //                              aimodule.cpp:45 (1)
    //         0040de41     PUSH       EDI
    //                              aimodule.cpp:50 (40)
    //         0040de42     LEA        EDX,[ECX + this->name[0]]
    //         0040de45     MOV        EDI,s_                                           = ""
    //         0040de4a     OR         this,0xffffffff
    //         0040de4d     XOR        EAX,EAX
    //         0040de4f     PUSH       ESI
    //         0040de50     SCASB.RE   ES:EDI=>s_                                       = ""
    //         0040de52     NOT        this
    //         0040de54     SUB        EDI,this
    //         0040de56     MOV        EAX,this
    //         0040de58     MOV        ESI,EDI
    //         0040de5a     MOV        EDI,EDX
    //         0040de5c     SHR        this,0x2
    //         0040de5f     MOVSD.REP  ES:EDI,ESI
    //         0040de61     MOV        this,EAX
    //         0040de63     AND        this,0x3
    //         0040de66     MOVSB.REP  ES:EDI,ESI
    //         0040de68     POP        ESI
    //         0040de69     POP        EDI
    //                              aimodule.cpp:51 (3)
    //         0040de6a     RET        0x8
}

// Offset: 0x0040DE70
undefined AIModuleMessage(AIModuleMessage* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall AIModuleMessage::AIModuleMessage(void)                                             *
    //                              *********************************************************************************************************
    //                              undefined __thiscall AIModuleMessage(AIModuleMessage * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              AIModuleMessag    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0040deb7(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0040df17(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0040de99(W)  
    //                               ??0AIModuleMessage@@QAE@XZ
    //                               AIModuleMessage::AIModuleMessage
    //                              aimodule.cpp:68 (80)
    //         0040de70     PUSH       -0x1
    //         0040de72     PUSH       FUN_0055c69e
    //         0040de77     MOV        EAX,FS:[0x0]
    //         0040de7d     PUSH       EAX
    //         0040de7e     MOV        dword ptr FS:[0x0],ESP
    //         0040de85     PUSH       this
    //         0040de86     PUSH       EBX
    //         0040de87     PUSH       ESI
    //         0040de88     MOV        EBX,this
    //         0040de8a     XOR        ESI,ESI
    //         0040de8c     PUSH       EDI
    //         0040de8d     PUSH       ESI
    //         0040de8e     PUSH       s_Sender                                         = "Sender"
    //         0040de93     LEA        this,[EBX + 0x8c]
    //         0040de99     MOV        dword ptr [ESP + local_10],EBX
    //         0040de9d     MOV        dword ptr [EBX + 0x4],ESI
    //         0040dea0     MOV        dword ptr [EBX + 0x88],ESI
    //         0040dea6     CALL       AIModuleID::AIModuleID                           undefined AIModuleID(AIModuleID * this, char 
    //         0040deab     PUSH       ESI
    //         0040deac     PUSH       s_Recipient                                      = "Recipient"
    //         0040deb1     LEA        this,[EBX + 0xd4]
    //         0040deb7     MOV        dword ptr [ESP + local_4],ESI
    //         0040debb     CALL       AIModuleID::AIModuleID                           undefined AIModuleID(AIModuleID * this, char 
    //                              aimodule.cpp:69 (80)
    //         0040dec0     MOV        EDI,s_                                           = ""
    //         0040dec5     OR         this,0xffffffff
    //         0040dec8     XOR        EAX,EAX
    //         0040deca     MOV        dword ptr [EBX + 0x11c],ESI
    //         0040ded0     MOV        dword ptr [EBX + 0x120],ESI
    //         0040ded6     MOV        dword ptr [EBX + 0x124],ESI
    //         0040dedc     MOV        dword ptr [EBX + 0x128],ESI
    //         0040dee2     MOV        dword ptr [EBX + 0x12c],ESI
    //         0040dee8     MOV        dword ptr [EBX + 0x130],ESI
    //         0040deee     MOV        dword ptr [EBX + 0x134],ESI
    //         0040def4     MOV        dword ptr [EBX],AIModuleMessage::`vftable'       = 0040df30
    //         0040defa     LEA        EDX,[EBX + 0x8]
    //         0040defd     SCASB.RE   ES:EDI=>s_                                       = ""
    //         0040deff     NOT        this
    //         0040df01     SUB        EDI,this
    //         0040df03     MOV        EAX,this
    //         0040df05     MOV        ESI,EDI
    //         0040df07     MOV        EDI,EDX
    //         0040df09     SHR        this,0x2
    //         0040df0c     MOVSD.REP  ES:EDI,ESI
    //         0040df0e     MOV        this,EAX
    //                              aimodule.cpp:70 (25)
    //         0040df10     MOV        EAX,EBX
    //         0040df12     AND        this,0x3
    //         0040df15     MOVSB.REP  ES:EDI,ESI
    //         0040df17     MOV        this,dword ptr [ESP + local_c]
    //         0040df1b     POP        EDI
    //         0040df1c     POP        ESI
    //         0040df1d     MOV        dword ptr FS:[0x0],this
    //         0040df24     POP        EBX
    //         0040df25     ADD        ESP,0x10
    //         0040df28     RET
}

// Offset: 0x0040DF50
undefined AIModuleMessage(AIModuleMessage* this_, int param_2, int param_3, int param_4, int param_5, long param_6, long param_7, long param_8, AIModuleMessage* param_9, int param_10) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall AIModuleMessage::AIModuleMessage(int,int,int,int,long,long,long,class AIModuleM... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall AIModuleMessage(AIModuleMessage * this, int par
    //              undefined         <UNASSIGNED>   <RETURN>
    //              AIModuleMessag    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040df66(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040df95(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0040df6a(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0040df71(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     0040dfb2(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[1]:     0040dfb6(R)  
    //              long              Stack[0x1c]:4  param_7                   XREF[1]:     0040dfba(R)  
    //              AIModuleMessag    Stack[0x20]:4  param_8                   XREF[1]:     0040dfc4(R)  
    //              int               Stack[0x24]:4  param_9                   XREF[1]:     0040dfce(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0040dfa5(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0040e011(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0040df89(W)  
    //                               ??0AIModuleMessage@@QAE@HHHHJJJPAV0@H@Z
    //                               AIModuleMessage::AIModuleMessage
    //                              aimodule.cpp:85 (142)
    //         0040df50     PUSH       -0x1
    //         0040df52     PUSH       FUN_0055c6be
    //         0040df57     MOV        EAX,FS:[0x0]
    //         0040df5d     PUSH       EAX
    //         0040df5e     MOV        dword ptr FS:[0x0],ESP
    //         0040df65     PUSH       this
    //         0040df66     MOV        EDX,dword ptr [ESP + param_1]
    //         0040df6a     MOV        EAX,dword ptr [ESP + param_3]
    //         0040df6e     PUSH       EBX
    //         0040df6f     MOV        EBX,this
    //         0040df71     MOV        this,dword ptr [ESP + param_4]
    //         0040df75     PUSH       ESI
    //         0040df76     PUSH       EDI
    //         0040df77     MOV        dword ptr [EBX + 0x88],this
    //         0040df7d     PUSH       EDX
    //         0040df7e     PUSH       s_                                               = ""
    //         0040df83     LEA        this,[EBX + 0x8c]
    //         0040df89     MOV        dword ptr [ESP + local_10],EBX
    //         0040df8d     MOV        dword ptr [EBX + 0x4],EAX
    //         0040df90     CALL       AIModuleID::AIModuleID                           undefined AIModuleID(AIModuleID * this, char 
    //         0040df95     MOV        EAX,dword ptr [ESP + param_2]
    //         0040df99     LEA        this,[EBX + 0xd4]
    //         0040df9f     PUSH       EAX
    //         0040dfa0     PUSH       s_                                               = ""
    //         0040dfa5     MOV        dword ptr [ESP + local_4],0x0
    //         0040dfad     CALL       AIModuleID::AIModuleID                           undefined AIModuleID(AIModuleID * this, char 
    //         0040dfb2     MOV        this,dword ptr [ESP + param_5]
    //         0040dfb6     MOV        EDX,dword ptr [ESP + param_6]
    //         0040dfba     MOV        EAX,dword ptr [ESP + param_7]
    //         0040dfbe     MOV        dword ptr [EBX + 0x11c],this
    //         0040dfc4     MOV        this,dword ptr [ESP + param_8]
    //         0040dfc8     MOV        dword ptr [EBX + 0x120],EDX
    //         0040dfce     MOV        EDX,dword ptr [ESP + param_9]
    //         0040dfd2     MOV        dword ptr [EBX + 0x124],EAX
    //         0040dfd8     MOV        dword ptr [EBX + 0x128],this
    //                              aimodule.cpp:86 (44)
    //         0040dfde     MOV        EDI,s_                                           = ""
    //         0040dfe3     OR         this,0xffffffff
    //         0040dfe6     XOR        EAX,EAX
    //         0040dfe8     MOV        dword ptr [EBX + 0x12c],EDX
    //         0040dfee     MOV        dword ptr [EBX],AIModuleMessage::`vftable'       = 0040df30
    //         0040dff4     SCASB.RE   ES:EDI=>s_                                       = ""
    //         0040dff6     NOT        this
    //         0040dff8     SUB        EDI,this
    //         0040dffa     LEA        EDX,[EBX + 0x8]
    //         0040dffd     MOV        EAX,this
    //         0040dfff     MOV        ESI,EDI
    //         0040e001     MOV        EDI,EDX
    //         0040e003     SHR        this,0x2
    //         0040e006     MOVSD.REP  ES:EDI,ESI
    //         0040e008     MOV        this,EAX
    //                              aimodule.cpp:87 (27)
    //         0040e00a     MOV        EAX,EBX
    //         0040e00c     AND        this,0x3
    //         0040e00f     MOVSB.REP  ES:EDI,ESI
    //         0040e011     MOV        this,dword ptr [ESP + local_c]
    //         0040e015     POP        EDI
    //         0040e016     POP        ESI
    //         0040e017     MOV        dword ptr FS:[0x0],this
    //         0040e01e     POP        EBX
    //         0040e01f     ADD        ESP,0x10
    //         0040e022     RET        0x24
}

// Offset: 0x0040E030
undefined AIModuleMessage(AIModuleMessage* this_, AIModuleMessage* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall AIModuleMessage::AIModuleMessage(class AIModuleMessage *)                          *
    //                              *********************************************************************************************************
    //                              undefined __thiscall AIModuleMessage(AIModuleMessage * this, AIModul
    //              undefined         <UNASSIGNED>   <RETURN>
    //              AIModuleMessag    ECX:4 (auto)   this
    //              AIModuleMessag    Stack[0x4]:4   param_1                   XREF[1]:     0040e048(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0040e091(W), 0040e0e0(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0040e104(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0040e04e(W)  
    //                               ??0AIModuleMessage@@QAE@PAV0@@Z
    //                               AIModuleMessage::AIModuleMessage
    //                              aimodule.cpp:103 (116)
    //         0040e030     PUSH       -0x1
    //         0040e032     PUSH       FUN_0055c6ec
    //         0040e037     MOV        EAX,FS:[0x0]
    //         0040e03d     PUSH       EAX
    //         0040e03e     MOV        dword ptr FS:[0x0],ESP
    //         0040e045     PUSH       this
    //         0040e046     PUSH       ESI
    //         0040e047     PUSH       EDI
    //         0040e048     MOV        EDI,dword ptr [ESP + param_1]
    //         0040e04c     MOV        ESI,this
    //         0040e04e     MOV        dword ptr [ESP + local_10],ESI
    //         0040e052     MOV        EAX,dword ptr [EDI + 0x4]
    //         0040e055     MOV        dword ptr [ESI + 0x4],EAX
    //         0040e058     MOV        this,dword ptr [EDI + 0x88]
    //         0040e05e     MOV        dword ptr [ESI + 0x88],this
    //         0040e064     MOV        EDX,dword ptr [EDI + 0x90]
    //         0040e06a     LEA        EAX,[EDI + 0x94]
    //         0040e070     PUSH       EDX
    //         0040e071     PUSH       EAX
    //         0040e072     LEA        this,[ESI + 0x8c]
    //         0040e078     CALL       AIModuleID::AIModuleID                           undefined AIModuleID(AIModuleID * this, char 
    //         0040e07d     MOV        this,dword ptr [EDI + 0xd8]
    //         0040e083     LEA        EDX,[EDI + 0xdc]
    //         0040e089     PUSH       this
    //         0040e08a     PUSH       EDX
    //         0040e08b     LEA        this,[ESI + 0xd4]
    //         0040e091     MOV        dword ptr [ESP + local_4],0x0
    //         0040e099     CALL       AIModuleID::AIModuleID                           undefined AIModuleID(AIModuleID * this, char 
    //         0040e09e     MOV        EAX,dword ptr [EDI + 0x11c]
    //                              aimodule.cpp:104 (96)
    //         0040e0a4     ADD        EDI,0x8
    //         0040e0a7     MOV        dword ptr [ESI + 0x11c],EAX
    //         0040e0ad     MOV        this,dword ptr [EDI + 0x118]
    //         0040e0b3     MOV        dword ptr [ESI + 0x120],this
    //         0040e0b9     MOV        EDX,dword ptr [EDI + 0x11c]
    //         0040e0bf     MOV        dword ptr [ESI + 0x124],EDX
    //         0040e0c5     MOV        EAX,dword ptr [EDI + 0x120]
    //         0040e0cb     MOV        dword ptr [ESI + 0x128],EAX
    //         0040e0d1     MOV        this,dword ptr [EDI + 0x124]
    //         0040e0d7     MOV        dword ptr [ESI + 0x12c],this
    //         0040e0dd     PUSH       EDI
    //         0040e0de     MOV        this,ESI
    //         0040e0e0     MOV        byte ptr [ESP + local_4],0x1
    //         0040e0e5     MOV        dword ptr [ESI + 0x130],0x0
    //         0040e0ef     MOV        dword ptr [ESI + 0x134],0x0
    //         0040e0f9     MOV        dword ptr [ESI],AIModuleMessage::`vftable'       = 0040df30
    //         0040e0ff     CALL       AIModuleMessage::setText                         void setText(AIModuleMessage * this, char * p
    //                              aimodule.cpp:105 (21)
    //         0040e104     MOV        this,dword ptr [ESP + local_c]
    //         0040e108     MOV        EAX,ESI
    //         0040e10a     POP        EDI
    //         0040e10b     MOV        dword ptr FS:[0x0],this
    //         0040e112     POP        ESI
    //         0040e113     ADD        ESP,0x10
    //         0040e116     RET        0x4
}

// Offset: 0x0040E120
void AIModuleMessage(AIModuleMessage* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall AIModuleMessage::~AIModuleMessage(void)                                    *
    //                              *********************************************************************************************************
    //                              void __thiscall ~AIModuleMessage(AIModuleMessage * this)
    //              void              <VOID>         <RETURN>
    //              AIModuleMessag    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0040e149(W), 0040e161(W)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0040e139(W)  
    //                               ??1AIModuleMessage@@UAE@XZ                                   XREF[1]:     `scalar_deleting_destructor':0040d
    //                               AIModuleMessage::~AIModuleMessage
    //                              aimodule.cpp:110 (35)
    //         0040e120     PUSH       -0x1
    //         0040e122     PUSH       FUN_0055c71c
    //         0040e127     MOV        EAX,FS:[0x0]
    //         0040e12d     PUSH       EAX
    //         0040e12e     MOV        dword ptr FS:[0x0],ESP
    //         0040e135     PUSH       this
    //         0040e136     PUSH       ESI
    //         0040e137     MOV        ESI,this
    //         0040e139     MOV        dword ptr [ESP + local_10],ESI
    //         0040e13d     MOV        dword ptr [ESI],AIModuleMessage::`vftable'       = 0040df30
    //                              aimodule.cpp:111 (18)
    //         0040e143     MOV        this,dword ptr [ESI + 0x128]
    //         0040e149     MOV        dword ptr [ESP + local_4],0x1
    //         0040e151     TEST       this,this
    //         0040e153     JZ         LAB_0040e15b
    //                              aimodule.cpp:112 (12)
    //         0040e155     MOV        EAX,dword ptr [this->_padding_]
    //         0040e157     PUSH       0x1
    //         0040e159     CALL       dword ptr [EAX]
    //                               LAB_0040e15b                                                 XREF[1]:     0040e153(j)  
    //         0040e15b     LEA        this,[ESI + 0xd4]
    //                              aimodule.cpp:113 (45)
    //         0040e161     MOV        byte ptr [ESP + local_4],0x0
    //         0040e166     CALL       AIModuleID::~AIModuleID                          void ~AIModuleID(AIModuleID * this)
    //         0040e16b     LEA        this,[ESI + 0x8c]
    //         0040e171     MOV        dword ptr [ESP + 0x10],0xffffffff
    //         0040e179     CALL       AIModuleID::~AIModuleID                          void ~AIModuleID(AIModuleID * this)
    //         0040e17e     MOV        this,dword ptr [ESP + 0x8]
    //         0040e182     POP        ESI
    //         0040e183     MOV        dword ptr FS:[0x0],this
    //         0040e18a     ADD        ESP,0x10
    //         0040e18d     RET
}

// Offset: 0x0040E190
void setText(AIModuleMessage* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall AIModuleMessage::setText(char *)                                              *
    //                              *********************************************************************************************************
    //                              void __thiscall setText(AIModuleMessage * this, char * param_1)
    //              void              <VOID>         <RETURN>
    //              AIModuleMessag    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0040e190(R)  
    //                               ?setText@AIModuleMessage@@QAEXPAD@Z                          XREF[1]:     AIModuleMessage:0040e0ff(c)  
    //                               AIModuleMessage::setText
    //                              aimodule.cpp:118 (8)
    //         0040e190     MOV        EAX,dword ptr [ESP + param_1]
    //         0040e194     TEST       EAX,EAX
    //         0040e196     JZ         LAB_0040e1aa
    //                              language.dll match for 0x7f: "N"
    //                              aimodule.cpp:120 (15)
    //         0040e198     PUSH       0x7f
    //         0040e19a     ADD        this,0x8
    //         0040e19d     PUSH       EAX
    //         0040e19e     PUSH       this
    //         0040e19f     CALL       strncpy                                          undefined strncpy()
    //         0040e1a4     ADD        ESP,0xc
    //                              aimodule.cpp:123 (3)
    //         0040e1a7     RET        0x4
    //                               LAB_0040e1aa                                                 XREF[1]:     0040e196(j)  
    //                              aimodule.cpp:118 (1)
    //         0040e1aa     PUSH       EDI
    //                              aimodule.cpp:122 (40)
    //         0040e1ab     LEA        EDX,[ECX + this->text[0]]
    //         0040e1ae     MOV        EDI,s_                                           = ""
    //         0040e1b3     OR         this,0xffffffff
    //         0040e1b6     XOR        EAX,EAX
    //         0040e1b8     PUSH       ESI
    //         0040e1b9     SCASB.RE   ES:EDI=>s_                                       = ""
    //         0040e1bb     NOT        this
    //         0040e1bd     SUB        EDI,this
    //         0040e1bf     MOV        EAX,this
    //         0040e1c1     MOV        ESI,EDI
    //         0040e1c3     MOV        EDI,EDX
    //         0040e1c5     SHR        this,0x2
    //         0040e1c8     MOVSD.REP  ES:EDI,ESI
    //         0040e1ca     MOV        this,EAX
    //         0040e1cc     AND        this,0x3
    //         0040e1cf     MOVSB.REP  ES:EDI,ESI
    //         0040e1d1     POP        ESI
    //         0040e1d2     POP        EDI
    //                              aimodule.cpp:123 (3)
    //         0040e1d3     RET        0x4
}

// Offset: 0x0040E1E0
void setSender(AIModuleMessage* this_, int param_2, char* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall AIModuleMessage::setSender(int,char *)                                        *
    //                              *********************************************************************************************************
    //                              void __thiscall setSender(AIModuleMessage * this, int param_1, char 
    //              void              <VOID>         <RETURN>
    //              AIModuleMessag    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040e1e4(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     0040e1e0(R)  
    //                               ?setSender@AIModuleMessage@@QAEXHPAD@Z
    //                               AIModuleMessage::setSender
    //                              aimodule.cpp:128 (21)
    //         0040e1e0     MOV        EAX,dword ptr [ESP + param_2]
    //         0040e1e4     MOV        EDX,dword ptr [ESP + param_1]
    //         0040e1e8     PUSH       EAX
    //         0040e1e9     PUSH       EDX
    //         0040e1ea     ADD        this,0x8c
    //         0040e1f0     CALL       AIModuleID::setID                                void setID(AIModuleID * this, int param_1, ch
    //                              aimodule.cpp:130 (3)
    //         0040e1f5     RET        0x8
}

// Offset: 0x0040E200
void setRecipient(AIModuleMessage* this_, int param_2, char* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall AIModuleMessage::setRecipient(int,char *)                                     *
    //                              *********************************************************************************************************
    //                              void __thiscall setRecipient(AIModuleMessage * this, int param_1, ch
    //              void              <VOID>         <RETURN>
    //              AIModuleMessag    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040e204(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     0040e200(R)  
    //                               ?setRecipient@AIModuleMessage@@QAEXHPAD@Z
    //                               AIModuleMessage::setRecipient
    //                              aimodule.cpp:135 (21)
    //         0040e200     MOV        EAX,dword ptr [ESP + param_2]
    //         0040e204     MOV        EDX,dword ptr [ESP + param_1]
    //         0040e208     PUSH       EAX
    //         0040e209     PUSH       EDX
    //         0040e20a     ADD        this,0xd4
    //         0040e210     CALL       AIModuleID::setID                                void setID(AIModuleID * this, int param_1, ch
    //                              aimodule.cpp:137 (3)
    //         0040e215     RET        0x8
}

// Offset: 0x0040E220
undefined AIModule(AIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall AIModule::AIModule(void)                                                           *
    //                              *********************************************************************************************************
    //                              undefined __thiscall AIModule(AIModule * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //                               ??0AIModule@@QAE@XZ
    //                               AIModule::AIModule
    //                              aimodule.cpp:161 (22)
    //         0040e220     PUSH       EBX
    //         0040e221     PUSH       ESI
    //         0040e222     MOV        EBX,this
    //         0040e224     PUSH       EDI
    //         0040e225     PUSH       -0x1
    //         0040e227     PUSH       s_                                               = ""
    //         0040e22c     LEA        this,[EBX + 0x4]
    //         0040e22f     CALL       AIModuleID::AIModuleID                           undefined AIModuleID(AIModuleID * this, char 
    //         0040e234     XOR        EAX,EAX
    //                              aimodule.cpp:164 (99)
    //         0040e236     MOV        EDI,s_Unknown                                    = 55h
    //         0040e23b     OR         this,0xffffffff
    //         0040e23e     MOV        dword ptr [EBX + 0x4c],0xffffffff
    //         0040e245     MOV        dword ptr [EBX + 0x90],EAX
    //         0040e24b     MOV        dword ptr [EBX + 0x94],EAX
    //         0040e251     MOV        dword ptr [EBX + 0x98],EAX
    //         0040e257     MOV        dword ptr [EBX + 0x9c],EAX
    //         0040e25d     MOV        dword ptr [EBX + 0xa0],EAX
    //         0040e263     MOV        dword ptr [EBX + 0xe4],0x5
    //         0040e26d     MOV        dword ptr [EBX + 0xe8],0x32
    //         0040e277     MOV        dword ptr [EBX + 0xec],EAX
    //         0040e27d     MOV        dword ptr [EBX],AIModule::`vftable'              = 0040e2b0
    //         0040e283     LEA        EDX,[EBX + 0x50]
    //         0040e286     SCASB.RE   ES:EDI=>s_Unknown                                = 55h
    //                                                                                  = 6Eh
    //         0040e288     NOT        this
    //         0040e28a     SUB        EDI,this
    //         0040e28c     MOV        EAX,this
    //         0040e28e     MOV        ESI,EDI
    //         0040e290     MOV        EDI,EDX
    //         0040e292     SHR        this,0x2
    //         0040e295     MOVSD.REP  ES:EDI,ESI
    //         0040e297     MOV        this,EAX
    //                              aimodule.cpp:165 (11)
    //         0040e299     MOV        EAX,EBX
    //         0040e29b     AND        this,0x3
    //         0040e29e     MOVSB.REP  ES:EDI,ESI
    //         0040e2a0     POP        EDI
    //         0040e2a1     POP        ESI
    //         0040e2a2     POP        EBX
    //         0040e2a3     RET
}

// Offset: 0x0040E2D0
undefined AIModule(AIModule* this_, char* param_2, int param_3, int param_4, void* param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall AIModule::AIModule(char *,int,int,void *)                                          *
    //                              *********************************************************************************************************
    //                              undefined __thiscall AIModule(AIModule * this, char * param_1, int p
    //              undefined         <UNASSIGNED>   <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0040e2d8(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040e2d0(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0040e2e7(R)  
    //              void *            Stack[0x10]:4  param_4
    //                               ??0AIModule@@QAE@PADHHPAX@Z                                  XREF[20]:    BuildAIModule:004086e5(c), 
    //                               AIModule::AIModule                                                        BuildAIModule:0040887d(c), 
    //                                                                                                         ConstructionAIModule:0040aac6(c), 
    //                                                                                                         ConstructionAIModule:0040abe9(c), 
    //                                                                                                         DiplomacyAIModule:0040beda(c), 
    //                                                                                                         DiplomacyAIModule:0040bf72(c), 
    //                                                                                                         EmotionalAIModule:0040c7db(c), 
    //                                                                                                         EmotionalAIModule:0040c952(c), 
    //                                                                                                         InformationAIModule:0040cda9(c), 
    //                                                                                                         MainDecisionAIModule:0040ce1e(c), 
    //                                                                                                         MainDecisionAIModule:0040cec2(c), 
    //                                                                                                         ResearchAIModule:004116a5(c), 
    //                                                                                                         ResearchAIModule:0041177a(c), 
    //                                                                                                         ResourceAIModule:00412343(c), 
    //                                                                                                         StrategyAIModule:00412b09(c), 
    //                                                                                                         TacticalAIModule:00412b69(c), 
    //                                                                                                         TradeAIModule:00412e59(c), 
    //                                                                                                         TradeAIModule:00412eb4(c), 
    //                                                                                                         TribeResourceAIModule:004e6b59(c), 
    //                                                                                                         TribeResourceAIModule:004e6bce(c)  
    //                              aimodule.cpp:188 (29)
    //         0040e2d0     MOV        EAX,dword ptr [ESP + param_2]
    //         0040e2d4     PUSH       EBX
    //         0040e2d5     MOV        EBX,this
    //         0040e2d7     PUSH       ESI
    //         0040e2d8     MOV        this,dword ptr [ESP + param_1]
    //         0040e2dc     PUSH       EDI
    //         0040e2dd     PUSH       EAX
    //         0040e2de     PUSH       this
    //         0040e2df     LEA        this,[EBX + 0x4]
    //         0040e2e2     CALL       AIModuleID::AIModuleID                           undefined AIModuleID(AIModuleID * this, char 
    //         0040e2e7     MOV        EDX,dword ptr [ESP + param_3]
    //         0040e2eb     XOR        EAX,EAX
    //                              aimodule.cpp:201 (95)
    //         0040e2ed     MOV        EDI,s_Unknown                                    = 55h
    //         0040e2f2     OR         this,0xffffffff
    //         0040e2f5     MOV        dword ptr [EBX + 0x4c],EDX
    //         0040e2f8     MOV        dword ptr [EBX + 0x90],EAX
    //         0040e2fe     MOV        dword ptr [EBX + 0x94],EAX
    //         0040e304     MOV        dword ptr [EBX + 0x98],EAX
    //         0040e30a     MOV        dword ptr [EBX + 0x9c],EAX
    //         0040e310     MOV        dword ptr [EBX + 0xa0],EAX
    //         0040e316     MOV        dword ptr [EBX + 0xe4],0x5
    //         0040e320     MOV        dword ptr [EBX + 0xe8],0x32
    //         0040e32a     MOV        dword ptr [EBX + 0xec],EAX
    //         0040e330     MOV        dword ptr [EBX],AIModule::`vftable'              = 0040e2b0
    //         0040e336     SCASB.RE   ES:EDI=>s_Unknown                                = 55h
    //                                                                                  = 6Eh
    //         0040e338     NOT        this
    //         0040e33a     SUB        EDI,this
    //         0040e33c     LEA        EDX,[EBX + 0x50]
    //         0040e33f     MOV        EAX,this
    //         0040e341     MOV        ESI,EDI
    //         0040e343     MOV        EDI,EDX
    //         0040e345     SHR        this,0x2
    //         0040e348     MOVSD.REP  ES:EDI,ESI
    //         0040e34a     MOV        this,EAX
    //                              aimodule.cpp:202 (13)
    //         0040e34c     MOV        EAX,EBX
    //         0040e34e     AND        this,0x3
    //         0040e351     MOVSB.REP  ES:EDI,ESI
    //         0040e353     POP        EDI
    //         0040e354     POP        ESI
    //         0040e355     POP        EBX
    //         0040e356     RET        0x10
}

// Offset: 0x0040E360
void AIModule(AIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall AIModule::~AIModule(void)                                                  *
    //                              *********************************************************************************************************
    //                              void __thiscall ~AIModule(AIModule * this)
    //              void              <VOID>         <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //                               ??1AIModule@@UAE@XZ                                          XREF[16]:    ~BuildAIModule:00408dd6(c), 
    //                               AIModule::~AIModule                                                       ~ConstructionAIModule:0040b184(c), 
    //                                                                                                         ~DiplomacyAIModule:0040bff6(c), 
    //                                                                                                         ~EmotionalAIModule:0040ca96(c), 
    //                                                                                                         ~InformationAIModule:0040cde6(c), 
    //                                                                                                         ~MainDecisionAIModule:0040d07a(c), 
    //                                                                                                         `scalar_deleting_destructor':0040e
    //                                                                                                         ~ResearchAIModule:00411994(c), 
    //                                                                                                         ~ResourceAIModule:00412526(c), 
    //                                                                                                         ~StrategyAIModule:00412b46(c), 
    //                                                                                                         ~TacticalAIModule:00412ba6(c), 
    //                                                                                                         ~TradeAIModule:00412ed6(c), 
    //                                                                                                         ~TribeResourceAIModule:004e6c26(c)
    //                                                                                                         FUN_0055c460:0055c466(c), 
    //                                                                                                         FUN_0055c540:0055c546(c), 
    //                                                                                                         FUN_0055c670:0055c673(c)  
    //                              aimodule.cpp:207 (3)
    //         0040e360     PUSH       ESI
    //         0040e361     MOV        ESI,this
    //                              aimodule.cpp:210 (25)
    //         0040e363     MOV        EAX,dword ptr [ESI + 0x9c]
    //         0040e369     MOV        dword ptr [ESI],AIModule::`vftable'              = 0040e2b0
    //         0040e36f     TEST       EAX,EAX
    //         0040e371     JZ         LAB_0040e38f
    //         0040e373     MOV        EAX,[commonHistoryLogFile]                       = 00000000
    //         0040e378     TEST       EAX,EAX
    //         0040e37a     JZ         LAB_0040e38f
    //                              aimodule.cpp:211 (9)
    //         0040e37c     PUSH       EAX
    //         0040e37d     CALL       fclose                                           undefined fclose()
    //         0040e382     ADD        ESP,0x4
    //                              aimodule.cpp:212 (18)
    //         0040e385     MOV        dword ptr [commonHistoryLogFile],0x0             = 00000000
    //                               LAB_0040e38f                                                 XREF[2]:     0040e371(j), 0040e37a(j)  
    //         0040e38f     LEA        this,[ESI + 0x4]
    //         0040e392     CALL       AIModuleID::~AIModuleID                          void ~AIModuleID(AIModuleID * this)
    //                              aimodule.cpp:232 (2)
    //         0040e397     POP        ESI
    //         0040e398     RET
}

// Offset: 0x0040E3A0
AIModuleID id(AIModule* this_, AIModuleID* return_storage_ptr) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class AIModuleID __thiscall AIModule::id(void)const                                           *
    //                              *********************************************************************************************************
    //                              AIModuleID __thiscall id(AIModule * this, AIModuleID * __return_stor
    //              AIModuleID        EAX:4 (ptr)    <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              AIModuleID *      Stack[0x4]:4   __return_storage_ptr__    XREF[1]:     0040e3a1(R)  
    //              <NoType>          Stack[0x0]:1   __$ReturnUdt
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0040e3bb(W)  
    //                               ?id@AIModule@@QBE?AVAIModuleID@@XZ
    //                               AIModule::id
    //                              aimodule.cpp:237 (1)
    //         0040e3a0     PUSH       this
    //                              aimodule.cpp:238 (25)
    //         0040e3a1     MOV        EAX,dword ptr [ESP + __return_storage_ptr__]
    //         0040e3a5     MOV        EDX,dword ptr [ECX + this+0x8]
    //         0040e3a8     PUSH       ESI
    //         0040e3a9     PUSH       EDI
    //         0040e3aa     LEA        ESI,[ECX + this+0xc]
    //         0040e3ad     LEA        EDI,[EAX + 0x8]
    //         0040e3b0     MOV        this,0x10
    //         0040e3b5     MOV        dword ptr [EAX + 0x4],EDX
    //         0040e3b8     MOVSD.REP  ES:EDI,ESI
    //                              aimodule.cpp:239 (20)
    //         0040e3ba     POP        EDI
    //         0040e3bb     MOV        dword ptr [ESP + local_4],0x0
    //         0040e3c3     MOV        dword ptr [EAX],AIModuleID::`vftable'            = 0040ddf0
    //         0040e3c9     POP        ESI
    //         0040e3ca     POP        this
    //         0040e3cb     RET        0x4
}

// Offset: 0x0040E3D0
int idNumber(AIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIModule::idNumber(void)const                                                  *
    //                              *********************************************************************************************************
    //                              int __thiscall idNumber(AIModule * this)
    //              int               EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //                               ?idNumber@AIModule@@QBEHXZ
    //                               AIModule::idNumber
    //                              aimodule.cpp:244 (3)
    //         0040e3d0     MOV        EAX,dword ptr [ECX + this+0x8]
    //                              aimodule.cpp:246 (1)
    //         0040e3d3     RET
}

// Offset: 0x0040E3E0
int playerNumber(AIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIModule::playerNumber(void)const                                              *
    //                              *********************************************************************************************************
    //                              int __thiscall playerNumber(AIModule * this)
    //              int               EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //                               ?playerNumber@AIModule@@QBEHXZ
    //                               AIModule::playerNumber
    //                              aimodule.cpp:251 (3)
    //         0040e3e0     MOV        EAX,dword ptr [ECX + this->playerNumberValue]
    //                              aimodule.cpp:253 (1)
    //         0040e3e3     RET
}

// Offset: 0x0040E3F0
char* playerName(AIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: char * __thiscall AIModule::playerName(void)const                                             *
    //                              *********************************************************************************************************
    //                              char * __thiscall playerName(AIModule * this)
    //              char *            EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //                               ?playerName@AIModule@@QBEPADXZ
    //                               AIModule::playerName
    //                              aimodule.cpp:258 (3)
    //         0040e3f0     LEA        EAX,[ECX + this->playerNameValue[0]]
    //                              aimodule.cpp:260 (1)
    //         0040e3f3     RET
}

// Offset: 0x0040E400
void setPlayer(AIModule* this_, int param_2, char* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall AIModule::setPlayer(int,char *)                                               *
    //                              *********************************************************************************************************
    //                              void __thiscall setPlayer(AIModule * this, int param_1, char * param
    //              void              <VOID>         <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040e400(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     0040e407(R)  
    //                               ?setPlayer@AIModule@@QAEXHPAD@Z                              XREF[20]:    TribeMainDecisionAIModule:004e495b
    //                               AIModule::setPlayer                                                       TribeMainDecisionAIModule:004e49e6
    //                                                                                                         TribeMainDecisionAIModule:004e49f3
    //                                                                                                         TribeMainDecisionAIModule:004e4a00
    //                                                                                                         TribeMainDecisionAIModule:004e4a0d
    //                                                                                                         TribeMainDecisionAIModule:004e4a16
    //                                                                                                         TribeMainDecisionAIModule:004e4a23
    //                                                                                                         TribeMainDecisionAIModule:004e4a30
    //                                                                                                         TribeMainDecisionAIModule:004e4a3d
    //                                                                                                         TribeMainDecisionAIModule:004e4a4a
    //                                                                                                         TribeMainDecisionAIModule:004e4c9e
    //                                                                                                         TribeMainDecisionAIModule:004e4d2d
    //                                                                                                         TribeMainDecisionAIModule:004e4d3a
    //                                                                                                         TribeMainDecisionAIModule:004e4d47
    //                                                                                                         TribeMainDecisionAIModule:004e4d54
    //                                                                                                         TribeMainDecisionAIModule:004e4d61
    //                                                                                                         TribeMainDecisionAIModule:004e4d6e
    //                                                                                                         TribeMainDecisionAIModule:004e4d7b
    //                                                                                                         TribeMainDecisionAIModule:004e4d88
    //                                                                                                         TribeMainDecisionAIModule:004e4d95
    //                              aimodule.cpp:265 (7)
    //         0040e400     MOV        EAX,dword ptr [ESP + param_1]
    //         0040e404     MOV        dword ptr [ECX + this->playerNumberValue],EAX
    //                              aimodule.cpp:267 (8)
    //         0040e407     MOV        EAX,dword ptr [ESP + param_2]
    //         0040e40b     TEST       EAX,EAX
    //         0040e40d     JZ         LAB_0040e421
    //                              aimodule.cpp:268 (15)
    //         0040e40f     PUSH       0x3f
    //         0040e411     ADD        this,0x50
    //         0040e414     PUSH       EAX
    //         0040e415     PUSH       this
    //         0040e416     CALL       strncpy                                          undefined strncpy()
    //         0040e41b     ADD        ESP,0xc
    //                              aimodule.cpp:271 (3)
    //         0040e41e     RET        0x8
    //                               LAB_0040e421                                                 XREF[1]:     0040e40d(j)  
    //                              aimodule.cpp:265 (1)
    //         0040e421     PUSH       EDI
    //                              aimodule.cpp:270 (40)
    //         0040e422     LEA        EDX,[ECX + this->playerNameValue[0]]
    //         0040e425     MOV        EDI,s_Unknown                                    = 55h
    //         0040e42a     OR         this,0xffffffff
    //         0040e42d     XOR        EAX,EAX
    //         0040e42f     PUSH       ESI
    //         0040e430     SCASB.RE   ES:EDI=>s_Unknown                                = 55h
    //                                                                                  = 6Eh
    //         0040e432     NOT        this
    //         0040e434     SUB        EDI,this
    //         0040e436     MOV        EAX,this
    //         0040e438     MOV        ESI,EDI
    //         0040e43a     MOV        EDI,EDX
    //         0040e43c     SHR        this,0x2
    //         0040e43f     MOVSD.REP  ES:EDI,ESI
    //         0040e441     MOV        this,EAX
    //         0040e443     AND        this,0x3
    //         0040e446     MOVSB.REP  ES:EDI,ESI
    //         0040e448     POP        ESI
    //         0040e449     POP        EDI
    //                              aimodule.cpp:271 (3)
    //         0040e44a     RET        0x8
}

// Offset: 0x0040E450
void start(AIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall AIModule::start(void)                                                         *
    //                              *********************************************************************************************************
    //                              void __thiscall start(AIModule * this)
    //              void              <VOID>         <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //                               ?start@AIModule@@QAEXXZ
    //                               AIModule::start
    //                              aimodule.cpp:276 (10)
    //         0040e450     MOV        dword ptr [ECX + this->runningValue],0x1
    //                              aimodule.cpp:278 (1)
    //         0040e45a     RET
}

// Offset: 0x0040E460
void stop(AIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall AIModule::stop(void)                                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall stop(AIModule * this)
    //              void              <VOID>         <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //                               ?stop@AIModule@@QAEXXZ
    //                               AIModule::stop
    //                              aimodule.cpp:283 (10)
    //         0040e460     MOV        dword ptr [ECX + this->runningValue],0x0
    //                              aimodule.cpp:285 (1)
    //         0040e46a     RET
}

// Offset: 0x0040E470
void toggleRun(AIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall AIModule::toggleRun(void)                                                     *
    //                              *********************************************************************************************************
    //                              void __thiscall toggleRun(AIModule * this)
    //              void              <VOID>         <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //                               ?toggleRun@AIModule@@QAEXXZ
    //                               AIModule::toggleRun
    //                              aimodule.cpp:290 (19)
    //         0040e470     MOV        EDX,dword ptr [ECX + this->runningValue]
    //         0040e476     XOR        EAX,EAX
    //         0040e478     TEST       EDX,EDX
    //         0040e47a     SETZ       AL
    //         0040e47d     MOV        dword ptr [ECX + this->runningValue],EAX
    //                              aimodule.cpp:292 (1)
    //         0040e483     RET
}

// Offset: 0x0040E490
void togglePause(AIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall AIModule::togglePause(void)                                                   *
    //                              *********************************************************************************************************
    //                              void __thiscall togglePause(AIModule * this)
    //              void              <VOID>         <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //                               ?togglePause@AIModule@@QAEXXZ
    //                               AIModule::togglePause
    //                              aimodule.cpp:297 (19)
    //         0040e490     MOV        EDX,dword ptr [ECX + this->pausedValue]
    //         0040e496     XOR        EAX,EAX
    //         0040e498     TEST       EDX,EDX
    //         0040e49a     SETZ       AL
    //         0040e49d     MOV        dword ptr [ECX + this->pausedValue],EAX
    //                              aimodule.cpp:299 (1)
    //         0040e4a3     RET
}

// Offset: 0x0040E4B0
void step(AIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall AIModule::step(void)                                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall step(AIModule * this)
    //              void              <VOID>         <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //                               ?step@AIModule@@QAEXXZ
    //                               AIModule::step
    //                              aimodule.cpp:304 (1)
    //         0040e4b0     RET
}

// Offset: 0x0040E4C0
int running(AIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIModule::running(void)const                                                   *
    //                              *********************************************************************************************************
    //                              int __thiscall running(AIModule * this)
    //              int               EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //                               ?running@AIModule@@QBEHXZ
    //                               AIModule::running
    //                              aimodule.cpp:310 (6)
    //         0040e4c0     MOV        EAX,dword ptr [ECX + this->runningValue]
    //                              aimodule.cpp:312 (1)
    //         0040e4c6     RET
}

// Offset: 0x0040E4D0
int paused(AIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIModule::paused(void)const                                                    *
    //                              *********************************************************************************************************
    //                              int __thiscall paused(AIModule * this)
    //              int               EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //                               ?paused@AIModule@@QBEHXZ
    //                               AIModule::paused
    //                              aimodule.cpp:317 (6)
    //         0040e4d0     MOV        EAX,dword ptr [ECX + this->pausedValue]
    //                              aimodule.cpp:319 (1)
    //         0040e4d6     RET
}

// Offset: 0x0040E4E0
int InformationAIModule::loggingHistory() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual int __thiscall AIModule::loggingHistory(void)const                                    *
    //                              *********************************************************************************************************
    //                              int __thiscall loggingHistory(AIModule * this)
    //              int               EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //                               ?loggingHistory@AIModule@@UBEHXZ                             XREF[19]:    0056e73c(*), 0056e7a4(*), 
    //                               AIModule::loggingHistory                                                  0056e81c(*), 0056e85c(*), 
    //                                                                                                         0056e89c(*), 0056e8dc(*), 
    //                                                                                                         0056e934(*), 0056e98c(*), 
    //                                                                                                         0056e9dc(*), 0056ea1c(*), 
    //                                                                                                         0056ea5c(*), 0056ea9c(*), 
    //                                                                                                         00575444(*), 005754a4(*), 
    //                                                                                                         00575514(*), 005755cc(*), 
    //                                                                                                         0057563c(*), 0057569c(*), 
    //                                                                                                         0057578c(*)  
    //                              aimodule.cpp:324 (6)
    //         0040e4e0     MOV        EAX,dword ptr [ECX + this->logHistoryValue]
    //                              aimodule.cpp:326 (1)
    //         0040e4e6     RET
}

// Offset: 0x0040E4F0
void InformationAIModule::setLogHistory(int param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall AIModule::setLogHistory(int)                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall setLogHistory(AIModule * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //                               ?setLogHistory@AIModule@@UAEXH@Z                             XREF[17]:    0056e740(*), 0056e7a8(*), 
    //                               AIModule::setLogHistory                                                   0056e820(*), 0056e860(*), 
    //                                                                                                         0056e8a0(*), 0056e938(*), 
    //                                                                                                         0056e990(*), 0056e9e0(*), 
    //                                                                                                         0056ea20(*), 0056ea60(*), 
    //                                                                                                         0056eaa0(*), 00575448(*), 
    //                                                                                                         005754a8(*), 00575518(*), 
    //                                                                                                         00575640(*), 005756a0(*), 
    //                                                                                                         00575790(*)  
    //                              aimodule.cpp:331 (3)
    //         0040e4f0     RET        0x4
}

// Offset: 0x0040E500
void InformationAIModule::toggleLogHistory() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall AIModule::toggleLogHistory(void)                                      *
    //                              *********************************************************************************************************
    //                              void __thiscall toggleLogHistory(AIModule * this)
    //              void              <VOID>         <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //                               ?toggleLogHistory@AIModule@@UAEXXZ                           XREF[19]:    0056e744(*), 0056e7ac(*), 
    //                               AIModule::toggleLogHistory                                                0056e824(*), 0056e864(*), 
    //                                                                                                         0056e8a4(*), 0056e8e4(*), 
    //                                                                                                         0056e93c(*), 0056e994(*), 
    //                                                                                                         0056e9e4(*), 0056ea24(*), 
    //                                                                                                         0056ea64(*), 0056eaa4(*), 
    //                                                                                                         0057544c(*), 005754ac(*), 
    //                                                                                                         0057551c(*), 005755d4(*), 
    //                                                                                                         00575644(*), 005756a4(*), 
    //                                                                                                         00575794(*)  
    //                              aimodule.cpp:351 (1)
    //         0040e500     RET
}

// Offset: 0x0040E510
int InformationAIModule::loggingCommonHistory() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual int __thiscall AIModule::loggingCommonHistory(void)const                              *
    //                              *********************************************************************************************************
    //                              int __thiscall loggingCommonHistory(AIModule * this)
    //              int               EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //                               ?loggingCommonHistory@AIModule@@UBEHXZ                       XREF[19]:    0056e74c(*), 0056e7b4(*), 
    //                               AIModule::loggingCommonHistory                                            0056e82c(*), 0056e86c(*), 
    //                                                                                                         0056e8ac(*), 0056e8ec(*), 
    //                                                                                                         0056e944(*), 0056e99c(*), 
    //                                                                                                         0056e9ec(*), 0056ea2c(*), 
    //                                                                                                         0056ea6c(*), 0056eaac(*), 
    //                                                                                                         00575454(*), 005754b4(*), 
    //                                                                                                         00575524(*), 005755dc(*), 
    //                                                                                                         0057564c(*), 005756ac(*), 
    //                                                                                                         0057579c(*)  
    //                              aimodule.cpp:358 (6)
    //         0040e510     MOV        EAX,dword ptr [ECX + this->logCommonHistoryVal
    //                              aimodule.cpp:360 (1)
    //         0040e516     RET
}

// Offset: 0x0040E520
void InformationAIModule::setLogCommonHistory(int param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall AIModule::setLogCommonHistory(int)                                    *
    //                              *********************************************************************************************************
    //                              void __thiscall setLogCommonHistory(AIModule * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[3]:     0040e520(R), 0040e552(*), 0040e55f(*)  
    //                               ?setLogCommonHistory@AIModule@@UAEXH@Z                       XREF[21]:    TribeMainDecisionAIModule:004e4971
    //                               AIModule::setLogCommonHistory                                             TribeMainDecisionAIModule:004e4cb4
    //                                                                                                         0056e750(*), 0056e7b8(*), 
    //                                                                                                         0056e830(*), 0056e870(*), 
    //                                                                                                         0056e8b0(*), 0056e8f0(*), 
    //                                                                                                         0056e948(*), 0056e9a0(*), 
    //                                                                                                         0056e9f0(*), 0056ea30(*), 
    //                                                                                                         0056ea70(*), 0056eab0(*), 
    //                                                                                                         00575458(*), 005754b8(*), 
    //                                                                                                         00575528(*), 005755e0(*), 
    //                                                                                                         00575650(*), 005756b0(*), [more]
    //                              aimodule.cpp:365 (7)
    //         0040e520     MOV        EAX,dword ptr [ESP + param_1]
    //         0040e524     PUSH       ESI
    //         0040e525     MOV        ESI,this
    //                              aimodule.cpp:367 (20)
    //         0040e527     TEST       EAX,EAX
    //         0040e529     MOV        dword ptr [ESI + 0x9c],EAX
    //         0040e52f     MOV        this,dword ptr [commonHistoryLogFile]            = 00000000
    //         0040e535     JZ         LAB_0040e596
    //         0040e537     TEST       this,this
    //         0040e539     JNZ        LAB_0040e596
    //                              aimodule.cpp:368 (23)
    //         0040e53b     PUSH       s_wa                                             = "wa"
    //         0040e540     PUSH       s_c:\aoeai.txt                                   = "c:\\aoeai.txt"
    //         0040e545     CALL       fopen                                            undefined fopen()
    //         0040e54a     ADD        ESP,0x8
    //         0040e54d     MOV        [commonHistoryLogFile],EAX                       = 00000000
    //                              aimodule.cpp:370 (13)
    //         0040e552     LEA        EAX=>param_1,[ESP + 0x8]
    //         0040e556     PUSH       EAX
    //         0040e557     CALL       time                                             undefined time()
    //         0040e55c     ADD        ESP,0x4
    //                              aimodule.cpp:371 (13)
    //         0040e55f     LEA        this=>param_1,[ESP + 0x8]
    //         0040e563     PUSH       this
    //         0040e564     CALL       localtime                                        undefined localtime()
    //         0040e569     ADD        ESP,0x4
    //                              aimodule.cpp:372 (24)
    //         0040e56c     PUSH       EAX
    //         0040e56d     CALL       asctime                                          undefined asctime()
    //         0040e572     ADD        ESP,0x4
    //         0040e575     PUSH       EAX
    //         0040e576     PUSH       s_Common_AI_History_File_Started_%               = "Common AI History File Started %s"
    //         0040e57b     PUSH       ESI
    //         0040e57c     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
    //         0040e581     ADD        ESP,0xc
    //                              aimodule.cpp:373 (14)
    //         0040e584     PUSH       s_                                               = ""
    //         0040e589     PUSH       ESI
    //         0040e58a     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
    //         0040e58f     ADD        ESP,0x8
    //                              aimodule.cpp:379 (4)
    //         0040e592     POP        ESI
    //         0040e593     RET        0x4
    //                               LAB_0040e596                                                 XREF[2]:     0040e535(j), 0040e539(j)  
    //                              aimodule.cpp:375 (8)
    //         0040e596     TEST       EAX,EAX
    //         0040e598     JNZ        LAB_0040e5b1
    //         0040e59a     TEST       this,this
    //         0040e59c     JZ         LAB_0040e5b1
    //                              aimodule.cpp:376 (9)
    //         0040e59e     PUSH       this
    //         0040e59f     CALL       fclose                                           undefined fclose()
    //         0040e5a4     ADD        ESP,0x4
    //                              aimodule.cpp:377 (10)
    //         0040e5a7     MOV        dword ptr [commonHistoryLogFile],0x0             = 00000000
    //                               LAB_0040e5b1                                                 XREF[2]:     0040e598(j), 0040e59c(j)  
    //                              aimodule.cpp:379 (4)
    //         0040e5b1     POP        ESI
    //         0040e5b2     RET        0x4
}

// Offset: 0x0040E5C0
void InformationAIModule::toggleLogCommonHistory() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall AIModule::toggleLogCommonHistory(void)                                *
    //                              *********************************************************************************************************
    //                              void __thiscall toggleLogCommonHistory(AIModule * this)
    //              void              <VOID>         <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //                               ?toggleLogCommonHistory@AIModule@@UAEXXZ                     XREF[19]:    0056e754(*), 0056e7bc(*), 
    //                               AIModule::toggleLogCommonHistory                                          0056e834(*), 0056e874(*), 
    //                                                                                                         0056e8b4(*), 0056e8f4(*), 
    //                                                                                                         0056e94c(*), 0056e9a4(*), 
    //                                                                                                         0056e9f4(*), 0056ea34(*), 
    //                                                                                                         0056ea74(*), 0056eab4(*), 
    //                                                                                                         0057545c(*), 005754bc(*), 
    //                                                                                                         0057552c(*), 005755e4(*), 
    //                                                                                                         00575654(*), 005756b4(*), 
    //                                                                                                         005757a4(*)  
    //                              aimodule.cpp:384 (1)
    //         0040e5c0     RET
}

// Offset: 0x0040E5D0
void InformationAIModule::setHistoryFilename(char* param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall AIModule::setHistoryFilename(char *)                                  *
    //                              *********************************************************************************************************
    //                              void __thiscall setHistoryFilename(AIModule * this, char * param_1)
    //              void              <VOID>         <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1
    //                               ?setHistoryFilename@AIModule@@UAEXPAD@Z                      XREF[19]:    0056e748(*), 0056e7b0(*), 
    //                               AIModule::setHistoryFilename                                              0056e828(*), 0056e868(*), 
    //                                                                                                         0056e8a8(*), 0056e8e8(*), 
    //                                                                                                         0056e940(*), 0056e998(*), 
    //                                                                                                         0056e9e8(*), 0056ea28(*), 
    //                                                                                                         0056ea68(*), 0056eaa8(*), 
    //                                                                                                         00575450(*), 005754b0(*), 
    //                                                                                                         00575520(*), 005755d8(*), 
    //                                                                                                         00575648(*), 005756a8(*), 
    //                                                                                                         00575798(*)  
    //                              aimodule.cpp:391 (3)
    //         0040e5d0     RET        0x4
}

// Offset: 0x0040E5E0
int intelligenceLevel(AIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIModule::intelligenceLevel(void)const                                         *
    //                              *********************************************************************************************************
    //                              int __thiscall intelligenceLevel(AIModule * this)
    //              int               EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //                               ?intelligenceLevel@AIModule@@QBEHXZ
    //                               AIModule::intelligenceLevel
    //                              aimodule.cpp:412 (6)
    //         0040e5e0     MOV        EAX,dword ptr [ECX + this->intelligenceLevelVa
    //                              aimodule.cpp:414 (1)
    //         0040e5e6     RET
}

// Offset: 0x0040E5F0
int setIntelligenceLevel(AIModule* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIModule::setIntelligenceLevel(int)                                            *
    //                              *********************************************************************************************************
    //                              int __thiscall setIntelligenceLevel(AIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040e5f0(R)  
    //                               ?setIntelligenceLevel@AIModule@@QAEHH@Z
    //                               AIModule::setIntelligenceLevel
    //                              aimodule.cpp:419 (4)
    //         0040e5f0     MOV        EAX,dword ptr [ESP + param_1]
    //                              aimodule.cpp:422 (11)
    //         0040e5f4     CMP        EAX,0x1
    //         0040e5f7     MOV        dword ptr [ECX + this->intelligenceLevelValue]
    //         0040e5fd     JGE        LAB_0040e60e
    //                              aimodule.cpp:423 (10)
    //         0040e5ff     MOV        dword ptr [ECX + this->intelligenceLevelValue]
    //                              aimodule.cpp:424 (2)
    //         0040e609     XOR        EAX,EAX
    //                              aimodule.cpp:431 (3)
    //         0040e60b     RET        0x4
    //                               LAB_0040e60e                                                 XREF[1]:     0040e5fd(j)  
    //                              aimodule.cpp:426 (5)
    //         0040e60e     CMP        EAX,0xa
    //         0040e611     JLE        LAB_0040e622
    //                              aimodule.cpp:427 (10)
    //         0040e613     MOV        dword ptr [ECX + this->intelligenceLevelValue]
    //                              aimodule.cpp:428 (2)
    //         0040e61d     XOR        EAX,EAX
    //                              aimodule.cpp:431 (3)
    //         0040e61f     RET        0x4
    //                               LAB_0040e622                                                 XREF[1]:     0040e611(j)  
    //                              aimodule.cpp:430 (5)
    //         0040e622     MOV        EAX,0x1
    //                              aimodule.cpp:431 (3)
    //         0040e627     RET        0x4
}

// Offset: 0x0040E630
int priority(AIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIModule::priority(void)const                                                  *
    //                              *********************************************************************************************************
    //                              int __thiscall priority(AIModule * this)
    //              int               EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //                               ?priority@AIModule@@QBEHXZ
    //                               AIModule::priority
    //                              aimodule.cpp:436 (6)
    //         0040e630     MOV        EAX,dword ptr [ECX + this->priorityValue]
    //                              aimodule.cpp:438 (1)
    //         0040e636     RET
}

// Offset: 0x0040E640
int setPriority(AIModule* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIModule::setPriority(int)                                                     *
    //                              *********************************************************************************************************
    //                              int __thiscall setPriority(AIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040e640(R)  
    //                               ?setPriority@AIModule@@QAEHH@Z                               XREF[2]:     incrementPriority:0040e68d(c), 
    //                               AIModule::setPriority                                                     decrementPriority:0040e6ad(c)  
    //                              aimodule.cpp:443 (4)
    //         0040e640     MOV        EAX,dword ptr [ESP + param_1]
    //                              aimodule.cpp:446 (11)
    //         0040e644     CMP        EAX,0x1
    //         0040e647     MOV        dword ptr [ECX + this->priorityValue],EAX
    //         0040e64d     JGE        LAB_0040e65e
    //                              aimodule.cpp:447 (10)
    //         0040e64f     MOV        dword ptr [ECX + this->priorityValue],0x1
    //                              aimodule.cpp:448 (2)
    //         0040e659     XOR        EAX,EAX
    //                              aimodule.cpp:455 (3)
    //         0040e65b     RET        0x4
    //                               LAB_0040e65e                                                 XREF[1]:     0040e64d(j)  
    //                              aimodule.cpp:450 (5)
    //         0040e65e     CMP        EAX,0x64
    //         0040e661     JLE        LAB_0040e672
    //                              aimodule.cpp:451 (10)
    //         0040e663     MOV        dword ptr [ECX + this->priorityValue],0x64
    //                              aimodule.cpp:452 (2)
    //         0040e66d     XOR        EAX,EAX
    //                              aimodule.cpp:455 (3)
    //         0040e66f     RET        0x4
    //                               LAB_0040e672                                                 XREF[1]:     0040e661(j)  
    //                              aimodule.cpp:454 (5)
    //         0040e672     MOV        EAX,0x1
    //                              aimodule.cpp:455 (3)
    //         0040e677     RET        0x4
}

// Offset: 0x0040E680
int incrementPriority(AIModule* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIModule::incrementPriority(int)                                               *
    //                              *********************************************************************************************************
    //                              int __thiscall incrementPriority(AIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040e686(R)  
    //                               ?incrementPriority@AIModule@@QAEHH@Z
    //                               AIModule::incrementPriority
    //                              aimodule.cpp:460 (18)
    //         0040e680     MOV        EAX,dword ptr [ECX + this->priorityValue]
    //         0040e686     MOV        EDX,dword ptr [ESP + param_1]
    //         0040e68a     ADD        EAX,EDX
    //         0040e68c     PUSH       EAX
    //         0040e68d     CALL       AIModule::setPriority                            int setPriority(AIModule * this, int param_1)
    //                              aimodule.cpp:462 (3)
    //         0040e692     RET        0x4
}

// Offset: 0x0040E6A0
int decrementPriority(AIModule* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIModule::decrementPriority(int)                                               *
    //                              *********************************************************************************************************
    //                              int __thiscall decrementPriority(AIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040e6a6(R)  
    //                               ?decrementPriority@AIModule@@QAEHH@Z
    //                               AIModule::decrementPriority
    //                              aimodule.cpp:467 (18)
    //         0040e6a0     MOV        EAX,dword ptr [ECX + this->priorityValue]
    //         0040e6a6     MOV        EDX,dword ptr [ESP + param_1]
    //         0040e6aa     SUB        EAX,EDX
    //         0040e6ac     PUSH       EAX
    //         0040e6ad     CALL       AIModule::setPriority                            int setPriority(AIModule * this, int param_1)
    //                              aimodule.cpp:469 (3)
    //         0040e6b2     RET        0x4
}

// Offset: 0x0040E6C0
int sendMessage(AIModule* this_, AIModuleMessage* param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIModule::sendMessage(class AIModuleMessage *,int)                             *
    //                              *********************************************************************************************************
    //                              int __thiscall sendMessage(AIModule * this, AIModuleMessage * param_
    //              int               EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              AIModuleMessag    Stack[0x4]:4   param_1
    //              int               Stack[0x8]:4   param_2
    //                               ?sendMessage@AIModule@@QAEHPAVAIModuleMessage@@H@Z
    //                               AIModule::sendMessage
    //                              aimodule.cpp:474 (2)
    //         0040e6c0     XOR        EAX,EAX
    //                              aimodule.cpp:512 (3)
    //         0040e6c2     RET        0x8
}

// Offset: 0x0040E6D0
void receiveMessage(AIModule* this_, AIModuleMessage* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall AIModule::receiveMessage(class AIModuleMessage *)                             *
    //                              *********************************************************************************************************
    //                              void __thiscall receiveMessage(AIModule * this, AIModuleMessage * pa
    //              void              <VOID>         <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              AIModuleMessag    Stack[0x4]:4   param_1
    //                               ?receiveMessage@AIModule@@QAEXPAVAIModuleMessage@@@Z
    //                               AIModule::receiveMessage
    //                              aimodule.cpp:517 (3)
    //         0040e6d0     RET        0x4
}

// Offset: 0x0040E6E0
int InformationAIModule::processMessage(AIModuleMessage* param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual int __thiscall AIModule::processMessage(class AIModuleMessage *)                      *
    //                              *********************************************************************************************************
    //                              int __thiscall processMessage(AIModule * this, AIModuleMessage * par
    //              int               EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              AIModuleMessag    Stack[0x4]:4   param_1
    //                               ?processMessage@AIModule@@UAEHPAVAIModuleMessage@@@Z         XREF[18]:    0056e764(*), 0056e7cc(*), 
    //                               AIModule::processMessage                                                  0056e844(*), 0056e884(*), 
    //                                                                                                         0056e8c4(*), 0056e904(*), 
    //                                                                                                         0056e95c(*), 0056e9b4(*), 
    //                                                                                                         0056ea44(*), 0056ea84(*), 
    //                                                                                                         0056eac4(*), 0057546c(*), 
    //                                                                                                         005754cc(*), 0057553c(*), 
    //                                                                                                         005755f4(*), 00575664(*), 
    //                                                                                                         005756c4(*), 005757b4(*)  
    //                              aimodule.cpp:556 (2)
    //         0040e6e0     XOR        EAX,EAX
    //                              aimodule.cpp:564 (3)
    //         0040e6e2     RET        0x4
}

// Offset: 0x0040E6F0
int InformationAIModule::update(int param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual int __thiscall AIModule::update(int)                                                  *
    //                              *********************************************************************************************************
    //                              int __thiscall update(AIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //                               ?update@AIModule@@UAEHH@Z                                    XREF[13]:    0056e768(*), 0056e7d0(*), 
    //                               AIModule::update                                                          0056e888(*), 0056e8c8(*), 
    //                                                                                                         0056e908(*), 0056e960(*), 
    //                                                                                                         0056e9b8(*), 0056ea48(*), 
    //                                                                                                         0056ea88(*), 0056eac8(*), 
    //                                                                                                         00575470(*), 005754d0(*), 
    //                                                                                                         00575668(*)  
    //                              aimodule.cpp:569 (2)
    //         0040e6f0     XOR        EAX,EAX
    //                              aimodule.cpp:603 (3)
    //         0040e6f2     RET        0x4
}

// Offset: 0x0040E700
void InformationAIModule::setCallbackMessage(AIModuleMessage* param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall AIModule::setCallbackMessage(class AIModuleMessage *)                 *
    //                              *********************************************************************************************************
    //                              void __thiscall setCallbackMessage(AIModule * this, AIModuleMessage 
    //              void              <VOID>         <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              AIModuleMessag    Stack[0x4]:4   param_1
    //                               ?setCallbackMessage@AIModule@@UAEXPAVAIModuleMessage@@@Z     XREF[18]:    0056e76c(*), 0056e7d4(*), 
    //                               AIModule::setCallbackMessage                                              0056e84c(*), 0056e88c(*), 
    //                                                                                                         0056e8cc(*), 0056e90c(*), 
    //                                                                                                         0056e964(*), 0056e9bc(*), 
    //                                                                                                         0056ea4c(*), 0056ea8c(*), 
    //                                                                                                         0056eacc(*), 00575474(*), 
    //                                                                                                         005754d4(*), 00575544(*), 
    //                                                                                                         005755fc(*), 0057566c(*), 
    //                                                                                                         005756cc(*), 005757bc(*)  
    //                              aimodule.cpp:608 (3)
    //         0040e700     RET        0x4
}

// Offset: 0x0040E710
int messageLimit(AIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIModule::messageLimit(void)                                                   *
    //                              *********************************************************************************************************
    //                              int __thiscall messageLimit(AIModule * this)
    //              int               EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //                               ?messageLimit@AIModule@@QAEHXZ
    //                               AIModule::messageLimit
    //                              aimodule.cpp:646 (2)
    //         0040e710     XOR        EAX,EAX
    //                              aimodule.cpp:649 (1)
    //         0040e712     RET
}

// Offset: 0x0040E720
void setMessageLimit(AIModule* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall AIModule::setMessageLimit(int)                                                *
    //                              *********************************************************************************************************
    //                              void __thiscall setMessageLimit(AIModule * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //                               ?setMessageLimit@AIModule@@QAEXH@Z
    //                               AIModule::setMessageLimit
    //                              aimodule.cpp:654 (3)
    //         0040e720     RET        0x4
}

// Offset: 0x0040E730
int callbackLimit(AIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIModule::callbackLimit(void)                                                  *
    //                              *********************************************************************************************************
    //                              int __thiscall callbackLimit(AIModule * this)
    //              int               EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //                               ?callbackLimit@AIModule@@QAEHXZ
    //                               AIModule::callbackLimit
    //                              aimodule.cpp:662 (2)
    //         0040e730     XOR        EAX,EAX
    //                              aimodule.cpp:665 (1)
    //         0040e732     RET
}

// Offset: 0x0040E740
void setCallbackLimit(AIModule* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall AIModule::setCallbackLimit(int)                                               *
    //                              *********************************************************************************************************
    //                              void __thiscall setCallbackLimit(AIModule * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //                               ?setCallbackLimit@AIModule@@QAEXH@Z
    //                               AIModule::setCallbackLimit
    //                              aimodule.cpp:670 (3)
    //         0040e740     RET        0x4
}

// Offset: 0x0040E750
int messageTimeout(AIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIModule::messageTimeout(void)                                                 *
    //                              *********************************************************************************************************
    //                              int __thiscall messageTimeout(AIModule * this)
    //              int               EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //                               ?messageTimeout@AIModule@@QAEHXZ
    //                               AIModule::messageTimeout
    //                              aimodule.cpp:678 (2)
    //         0040e750     XOR        EAX,EAX
    //                              aimodule.cpp:681 (1)
    //         0040e752     RET
}

// Offset: 0x0040E760
void setMessageTimeout(AIModule* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall AIModule::setMessageTimeout(int)                                              *
    //                              *********************************************************************************************************
    //                              void __thiscall setMessageTimeout(AIModule * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //                               ?setMessageTimeout@AIModule@@QAEXH@Z
    //                               AIModule::setMessageTimeout
    //                              aimodule.cpp:686 (3)
    //         0040e760     RET        0x4
}

// Offset: 0x0040E770
int purgeMessages(AIModule* this_, AIModuleID param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIModule::purgeMessages(class AIModuleID)                                      *
    //                              *********************************************************************************************************
    //                              int __thiscall purgeMessages(AIModule * this, AIModuleID param_1)
    //              int               EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              AIModuleID        Stack[0x4]:72  param_1                   XREF[1]:     0040e770(*)  
    //                               ?purgeMessages@AIModule@@QAEHVAIModuleID@@@Z
    //                               AIModule::purgeMessages
    //                              aimodule.cpp:693 (11)
    //         0040e770     LEA        this=>param_1,[ESP + 0x4]
    //         0040e774     CALL       AIModuleID::~AIModuleID                          void ~AIModuleID(AIModuleID * this)
    //         0040e779     XOR        EAX,EAX
    //                              aimodule.cpp:713 (3)
    //         0040e77b     RET        0x48
}

// Offset: 0x0040E780
int purgeMessagesWithID(AIModule* this_, AIModuleID param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIModule::purgeMessagesWithID(class AIModuleID,int)                            *
    //                              *********************************************************************************************************
    //                              int __thiscall purgeMessagesWithID(AIModule * this, AIModuleID param
    //              int               EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              AIModuleID        Stack[0x4]:72  param_1                   XREF[1]:     0040e780(*)  
    //              int               Stack[0x4c]:4  param_2
    //                               ?purgeMessagesWithID@AIModule@@QAEHVAIModuleID@@H@Z
    //                               AIModule::purgeMessagesWithID
    //                              aimodule.cpp:718 (11)
    //         0040e780     LEA        this=>param_1,[ESP + 0x4]
    //         0040e784     CALL       AIModuleID::~AIModuleID                          void ~AIModuleID(AIModuleID * this)
    //         0040e789     XOR        EAX,EAX
    //                              aimodule.cpp:736 (3)
    //         0040e78b     RET        0x4c
}

// Offset: 0x0040E790
int purgeMessagesWithPriorityBelow(AIModule* this_, AIModuleID param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIModule::purgeMessagesWithPriorityBelow(class AIModuleID,int)                 *
    //                              *********************************************************************************************************
    //                              int __thiscall purgeMessagesWithPriorityBelow(AIModule * this, AIMod
    //              int               EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              AIModuleID        Stack[0x4]:72  param_1                   XREF[1]:     0040e790(*)  
    //              int               Stack[0x4c]:4  param_2
    //                               ?purgeMessagesWithPriorityBelow@AIModule@@QAEHVAIModuleID@@
    //                               AIModule::purgeMessagesWithPriorityBelow
    //                              aimodule.cpp:741 (11)
    //         0040e790     LEA        this=>param_1,[ESP + 0x4]
    //         0040e794     CALL       AIModuleID::~AIModuleID                          void ~AIModuleID(AIModuleID * this)
    //         0040e799     XOR        EAX,EAX
    //                              aimodule.cpp:760 (3)
    //         0040e79b     RET        0x4c
}

// Offset: 0x0040E7A0
int purgeMessagesWithData(AIModule* this_, AIModuleID param_2, int param_3, int param_4, long param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIModule::purgeMessagesWithData(class AIModuleID,int,int,long)                 *
    //                              *********************************************************************************************************
    //                              int __thiscall purgeMessagesWithData(AIModule * this, AIModuleID par
    //              int               EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              AIModuleID        Stack[0x4]:72  param_1                   XREF[1]:     0040e7a0(*)  
    //              int               Stack[0x4c]:4  param_2
    //              int               Stack[0x50]:4  param_3
    //              long              Stack[0x54]:4  param_4
    //                               ?purgeMessagesWithData@AIModule@@QAEHVAIModuleID@@HHJ@Z
    //                               AIModule::purgeMessagesWithData
    //                              aimodule.cpp:765 (11)
    //         0040e7a0     LEA        this=>param_1,[ESP + 0x4]
    //         0040e7a4     CALL       AIModuleID::~AIModuleID                          void ~AIModuleID(AIModuleID * this)
    //         0040e7a9     XOR        EAX,EAX
    //                              aimodule.cpp:788 (3)
    //         0040e7ab     RET        0x54
}

// Offset: 0x0040E7B0
int purgeCallbacks(AIModule* this_, AIModuleID param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIModule::purgeCallbacks(class AIModuleID)                                     *
    //                              *********************************************************************************************************
    //                              int __thiscall purgeCallbacks(AIModule * this, AIModuleID param_1)
    //              int               EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              AIModuleID        Stack[0x4]:72  param_1                   XREF[1]:     0040e7b0(*)  
    //                               ?purgeCallbacks@AIModule@@QAEHVAIModuleID@@@Z
    //                               AIModule::purgeCallbacks
    //                              aimodule.cpp:793 (11)
    //         0040e7b0     LEA        this=>param_1,[ESP + 0x4]
    //         0040e7b4     CALL       AIModuleID::~AIModuleID                          void ~AIModuleID(AIModuleID * this)
    //         0040e7b9     XOR        EAX,EAX
    //                              aimodule.cpp:813 (3)
    //         0040e7bb     RET        0x48
}

// Offset: 0x0040E7C0
int purgeCallbacksWithID(AIModule* this_, AIModuleID param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIModule::purgeCallbacksWithID(class AIModuleID,int)                           *
    //                              *********************************************************************************************************
    //                              int __thiscall purgeCallbacksWithID(AIModule * this, AIModuleID para
    //              int               EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              AIModuleID        Stack[0x4]:72  param_1                   XREF[1]:     0040e7c0(*)  
    //              int               Stack[0x4c]:4  param_2
    //                               ?purgeCallbacksWithID@AIModule@@QAEHVAIModuleID@@H@Z
    //                               AIModule::purgeCallbacksWithID
    //                              aimodule.cpp:818 (11)
    //         0040e7c0     LEA        this=>param_1,[ESP + 0x4]
    //         0040e7c4     CALL       AIModuleID::~AIModuleID                          void ~AIModuleID(AIModuleID * this)
    //         0040e7c9     XOR        EAX,EAX
    //                              aimodule.cpp:836 (3)
    //         0040e7cb     RET        0x4c
}

// Offset: 0x0040E7D0
int purgeCallbacksWithPriorityBelow(AIModule* this_, AIModuleID param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIModule::purgeCallbacksWithPriorityBelow(class AIModuleID,int)                *
    //                              *********************************************************************************************************
    //                              int __thiscall purgeCallbacksWithPriorityBelow(AIModule * this, AIMo
    //              int               EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              AIModuleID        Stack[0x4]:72  param_1                   XREF[1]:     0040e7d0(*)  
    //              int               Stack[0x4c]:4  param_2
    //                               ?purgeCallbacksWithPriorityBelow@AIModule@@QAEHVAIModuleID@
    //                               AIModule::purgeCallbacksWithPriorityBelow
    //                              aimodule.cpp:841 (11)
    //         0040e7d0     LEA        this=>param_1,[ESP + 0x4]
    //         0040e7d4     CALL       AIModuleID::~AIModuleID                          void ~AIModuleID(AIModuleID * this)
    //         0040e7d9     XOR        EAX,EAX
    //                              aimodule.cpp:860 (3)
    //         0040e7db     RET        0x4c
}

// Offset: 0x0040E7E0
int purgeCallbacksWithData(AIModule* this_, AIModuleID param_2, int param_3, int param_4, long param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall AIModule::purgeCallbacksWithData(class AIModuleID,int,int,long)                *
    //                              *********************************************************************************************************
    //                              int __thiscall purgeCallbacksWithData(AIModule * this, AIModuleID pa
    //              int               EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              AIModuleID        Stack[0x4]:72  param_1                   XREF[1]:     0040e7e0(*)  
    //              int               Stack[0x4c]:4  param_2
    //              int               Stack[0x50]:4  param_3
    //              long              Stack[0x54]:4  param_4
    //                               ?purgeCallbacksWithData@AIModule@@QAEHVAIModuleID@@HHJ@Z
    //                               AIModule::purgeCallbacksWithData
    //                              aimodule.cpp:865 (11)
    //         0040e7e0     LEA        this=>param_1,[ESP + 0x4]
    //         0040e7e4     CALL       AIModuleID::~AIModuleID                          void ~AIModuleID(AIModuleID * this)
    //         0040e7e9     XOR        EAX,EAX
    //                              aimodule.cpp:888 (3)
    //         0040e7eb     RET        0x54
}

// Offset: 0x0040E7F0
void checkMessageLimit(AIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall AIModule::checkMessageLimit(void)                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall checkMessageLimit(AIModule * this)
    //              void              <VOID>         <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //                               ?checkMessageLimit@AIModule@@IAEXXZ
    //                               AIModule::checkMessageLimit
    //                              aimodule.cpp:893 (1)
    //         0040e7f0     RET
}

// Offset: 0x0040E800
void checkCallbackLimit(AIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall AIModule::checkCallbackLimit(void)                                         *
    //                              *********************************************************************************************************
    //                              void __thiscall checkCallbackLimit(AIModule * this)
    //              void              <VOID>         <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //                               ?checkCallbackLimit@AIModule@@IAEXXZ
    //                               AIModule::checkCallbackLimit
    //                              aimodule.cpp:915 (1)
    //         0040e800     RET
}

// Offset: 0x0040E810
int InformationAIModule::filterOutMessage(AIModuleMessage* param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual int __thiscall AIModule::filterOutMessage(class AIModuleMessage *)                 *
    //                              *********************************************************************************************************
    //                              int __thiscall filterOutMessage(AIModule * this, AIModuleMessage * p
    //              int               EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              AIModuleMessag    Stack[0x4]:4   param_1
    //                               ?filterOutMessage@AIModule@@MAEHPAVAIModuleMessage@@@Z       XREF[19]:    filterOutMessage:00412965(c), 
    //                               AIModule::filterOutMessage                                                0056e770(*), 0056e7d8(*), 
    //                                                                                                         0056e850(*), 0056e890(*), 
    //                                                                                                         0056e8d0(*), 0056e910(*), 
    //                                                                                                         0056e968(*), 0056e9c0(*), 
    //                                                                                                         0056ea50(*), 0056ea90(*), 
    //                                                                                                         0056ead0(*), 00575478(*), 
    //                                                                                                         005754d8(*), 00575548(*), 
    //                                                                                                         00575600(*), 00575670(*), 
    //                                                                                                         005756d0(*), 005757c0(*)  
    //                              aimodule.cpp:937 (2)
    //         0040e810     XOR        EAX,EAX
    //                              aimodule.cpp:944 (3)
    //         0040e812     RET        0x4
}

// Offset: 0x0040E820
void logHistory(AIModule* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __cdecl AIModule::logHistory(char *,...)                                                 *
    //                              *********************************************************************************************************
    //                              void __thiscall logHistory(AIModule * this, char * param_1, ...)
    //              void              <VOID>         <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1
    //                               ?logHistory@AIModule@@QAAXPADZZ
    //                               AIModule::logHistory
    //                              aimodule.cpp:949 (1)
    //         0040e820     RET
}

// Offset: 0x0040E830
void logCommonHistory(AIModule* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __cdecl AIModule::logCommonHistory(char *,...)                                           *
    //                              *********************************************************************************************************
    //                              void __thiscall logCommonHistory(AIModule * this, char * param_1, ...)
    //              void              <VOID>         <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0040e83f(R)  
    //              char[1024]        Stack[-0x404   textOut                   XREF[0,3]:   0040e866(*), 0040e871(*), 0040e887(*)  
    //                               ?logCommonHistory@AIModule@@QAAXPADZZ                        XREF[115]:   loadConstructionPlan:0040b752(c), 
    //                               AIModule::logCommonHistory                                                loadConstructionPlan:0040b943(c), 
    //                                                                                                         objectGroupThatCanPerformAction:00
    //                                                                                                         setLogCommonHistory:0040e57c(c), 
    //                                                                                                         setLogCommonHistory:0040e58a(c), 
    //                                                                                                         cancelTrainUnit:004d5627(c), 
    //                                                                                                         cancelTrainUnit:004d564f(c), 
    //                                                                                                         cancelTrainUnit:004d5677(c), 
    //                                                                                                         detask:004f61e4(c), 
    //                                                                                                         taskTrain:004fb565(c), 
    //                                                                                                         taskTrain:004fb5d1(c), 
    //                                                                                                         taskTrain:004fb6fe(c), 
    //                                                                                                         displayBoatGroups:004ffeec(c), 
    //                                                                                                         displayBoatGroups:00500029(c), 
    //                                                                                                         displayBoatGroups:0050005f(c), 
    //                                                                                                         displayBoatGroups:0050009c(c), 
    //                                                                                                         displayBoatGroups:005000c9(c), 
    //                                                                                                         addGatherer:00501932(c), 
    //                                                                                                         removeGatherer:005019d4(c), 
    //                                                                                                         logMessage:00515021(c), [more]
    //                              aimodule.cpp:964 (30)
    //         0040e830     MOV        EAX,[specificAIPlayerToLog]                      = FFFFFFFFh
    //         0040e835     SUB        ESP,0x400
    //         0040e83b     CMP        EAX,-0x1
    //         0040e83e     PUSH       ESI
    //         0040e83f     MOV        ESI,dword ptr [ESP + param_1]
    //         0040e846     PUSH       EDI
    //         0040e847     JZ         LAB_0040e84e
    //         0040e849     CMP        EAX,dword ptr [ESI + 0x4c]
    //         0040e84c     JNZ        LAB_0040e8cc
    //                               LAB_0040e84e                                                 XREF[1]:     0040e847(j)  
    //                              aimodule.cpp:970 (9)
    //         0040e84e     MOV        EAX,[commonHistoryLogFile]                       = 00000000
    //         0040e853     TEST       EAX,EAX
    //         0040e855     JZ         LAB_0040e8cc
    //                              aimodule.cpp:974 (26)
    //         0040e857     MOV        this,dword ptr [ESP + Stack[0x8]]
    //         0040e85e     LEA        EAX=>Stack[0xc],[ESP + 0x414]
    //         0040e865     PUSH       EAX
    //         0040e866     LEA        EDX=>textOut[4],[ESP + 0xc]
    //         0040e86a     PUSH       this
    //         0040e86b     PUSH       EDX
    //         0040e86c     CALL       vsprintf                                         undefined vsprintf()
    //                              aimodule.cpp:976 (19)
    //         0040e871     LEA        EDI=>textOut[4],[ESP + 0x14]
    //         0040e875     OR         this,0xffffffff
    //         0040e878     XOR        EAX,EAX
    //         0040e87a     ADD        ESP,0xc
    //         0040e87d     SCASB.RE   ES:EDI
    //         0040e87f     NOT        this
    //         0040e881     DEC        this
    //         0040e882     JZ         LAB_0040e8a6
    //                              aimodule.cpp:980 (32)
    //         0040e884     MOV        EDX,dword ptr [ESI + 0x4c]
    //         0040e887     LEA        EAX=>textOut[4],[ESP + 0x8]
    //         0040e88b     LEA        this,[ESI + 0xc]
    //         0040e88e     PUSH       EAX
    //         0040e88f     MOV        EAX,[commonHistoryLogFile]                       = 00000000
    //         0040e894     PUSH       this
    //         0040e895     PUSH       EDX
    //         0040e896     PUSH       s_P#%d_%s:_%s_                                   = "P#%d %s: %s\n"
    //         0040e89b     PUSH       EAX
    //         0040e89c     CALL       fprintf                                          undefined fprintf()
    //         0040e8a1     ADD        ESP,0x14
    //                              aimodule.cpp:981 (2)
    //         0040e8a4     JMP        LAB_0040e8be
    //                               LAB_0040e8a6                                                 XREF[1]:     0040e882(j)  
    //                              aimodule.cpp:982 (24)
    //         0040e8a6     MOV        this,dword ptr [ESI + 0x4c]
    //         0040e8a9     MOV        EDX,dword ptr [commonHistoryLogFile]             = 00000000
    //         0040e8af     PUSH       this
    //         0040e8b0     PUSH       s_P#%d_                                          = "P#%d\n"
    //         0040e8b5     PUSH       EDX
    //         0040e8b6     CALL       fprintf                                          undefined fprintf()
    //         0040e8bb     ADD        ESP,0xc
    //                               LAB_0040e8be                                                 XREF[1]:     0040e8a4(j)  
    //                              aimodule.cpp:983 (14)
    //         0040e8be     MOV        EAX,[commonHistoryLogFile]                       = 00000000
    //         0040e8c3     PUSH       EAX
    //         0040e8c4     CALL       fflush                                           undefined fflush()
    //         0040e8c9     ADD        ESP,0x4
    //                               LAB_0040e8cc                                                 XREF[2]:     0040e84c(j), 0040e855(j)  
    //                              aimodule.cpp:985 (9)
    //         0040e8cc     POP        EDI
    //         0040e8cd     POP        ESI
    //         0040e8ce     ADD        ESP,0x400
    //         0040e8d4     RET
}

// Offset: 0x0040E8E0
void logDebug(AIModule* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __cdecl AIModule::logDebug(char *,...)                                                   *
    //                              *********************************************************************************************************
    //                              void __thiscall logDebug(AIModule * this, char * param_1, ...)
    //              void              <VOID>         <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1
    //                               ?logDebug@AIModule@@QAAXPADZZ
    //                               AIModule::logDebug
    //                              aimodule.cpp:990 (1)
    //         0040e8e0     RET
}

// Offset: 0x0040E8F0
int processFrame(AIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: int __thiscall AIModule::processFrame(void)                                                *
    //                              *********************************************************************************************************
    //                              int __thiscall processFrame(AIModule * this)
    //              int               EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //                               ?processFrame@AIModule@@IAEHXZ
    //                               AIModule::processFrame
    //                              aimodule.cpp:1004 (6)
    //         0040e8f0     MOV        EAX,dword ptr [ECX + this->processFrameValue]
    //                              aimodule.cpp:1006 (1)
    //         0040e8f6     RET
}

// Offset: 0x0040E900
void incrementProcessFrame(AIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall AIModule::incrementProcessFrame(void)                                      *
    //                              *********************************************************************************************************
    //                              void __thiscall incrementProcessFrame(AIModule * this)
    //              void              <VOID>         <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //                               ?incrementProcessFrame@AIModule@@IAEXXZ
    //                               AIModule::incrementProcessFrame
    //                              aimodule.cpp:1011 (7)
    //         0040e900     MOV        EAX,dword ptr [ECX + this->processFrameValue]
    //         0040e906     INC        EAX
    //                              aimodule.cpp:1013 (13)
    //         0040e907     CMP        EAX,0x7fffffff
    //         0040e90c     MOV        dword ptr [ECX + this->processFrameValue],EAX
    //         0040e912     JNZ        LAB_0040e91e
    //                              aimodule.cpp:1014 (10)
    //         0040e914     MOV        dword ptr [ECX + this->processFrameValue],0x0
    //                               LAB_0040e91e                                                 XREF[1]:     0040e912(j)  
    //                              aimodule.cpp:1015 (1)
    //         0040e91e     RET
}

// Offset: 0x0040E920
int timeDifference(AIModule* this_, AIModuleMessage* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: int __thiscall AIModule::timeDifference(class AIModuleMessage *)                           *
    //                              *********************************************************************************************************
    //                              int __thiscall timeDifference(AIModule * this, AIModuleMessage * par
    //              int               EAX:4          <RETURN>
    //              AIModule *        ECX:4 (auto)   this
    //              AIModuleMessag    Stack[0x4]:4   param_1
    //                               ?timeDifference@AIModule@@IAEHPAVAIModuleMessage@@@Z
    //                               AIModule::timeDifference
    //                              aimodule.cpp:1020 (2)
    //         0040e920     XOR        EAX,EAX
    //                              aimodule.cpp:1032 (3)
    //         0040e922     RET        0x4
}

