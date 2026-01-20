// Auto-generated scaffold unit: spanlist.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/spanlist.cpp
#include "../include/common.h"

// Offset: 0x004BD5E0
undefined TSpan_Node_List(TSpan_Node_List* this_, int param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TSpan_Node_List::TSpan_Node_List(int,int,int)                                      *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TSpan_Node_List(TSpan_Node_List * this, int par
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TSpan_Node_Lis    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004bd624(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004bd603(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     004bd5ee(R)  
    //                               ??0TSpan_Node_List@@QAE@HHH@Z                                XREF[1]:     TSpan_List_Manager:004bd8ef(c)  
    //                               TSpan_Node_List::TSpan_Node_List
    //                              spanlist.cpp:41 (3)
    //         004bd5e0     PUSH       ESI
    //         004bd5e1     MOV        ESI,this
    //                              spanlist.cpp:52 (8)
    //         004bd5e3     OR         this,0xffffffff
    //         004bd5e6     XOR        EAX,EAX
    //         004bd5e8     MOV        dword ptr [ESI + 0x14],this
    //                              spanlist.cpp:53 (3)
    //         004bd5eb     MOV        dword ptr [ESI + 0x18],this
    //                              spanlist.cpp:59 (28)
    //         004bd5ee     MOV        this,dword ptr [ESP + param_3]
    //         004bd5f2     MOV        dword ptr [ESI],EAX
    //         004bd5f4     MOV        dword ptr [ESI + 0x4],EAX
    //         004bd5f7     MOV        dword ptr [ESI + 0x8],EAX
    //         004bd5fa     MOV        dword ptr [ESI + 0x10],EAX
    //         004bd5fd     MOV        dword ptr [ESI + 0x1c],EAX
    //         004bd600     MOV        dword ptr [ESI + 0x20],EAX
    //         004bd603     MOV        EAX,dword ptr [ESP + param_2]
    //         004bd607     MOV        dword ptr [ESI + 0x28],this
    //                              spanlist.cpp:61 (17)
    //         004bd60a     MOV        this,ESI
    //         004bd60c     MOV        dword ptr [ESI + 0xc],0x8
    //         004bd613     MOV        dword ptr [ESI + 0x24],EAX
    //         004bd616     CALL       TSpan_Node_List::ResetStats                      void ResetStats(TSpan_Node_List * this)
    //                              spanlist.cpp:65 (9)
    //         004bd61b     PUSH       0x8
    //         004bd61d     MOV        this,ESI
    //         004bd61f     CALL       TSpan_Node_List::SetNumZones                     void SetNumZones(TSpan_Node_List * this, int 
    //                              spanlist.cpp:67 (12)
    //         004bd624     MOV        EDX,dword ptr [ESP + param_1]
    //         004bd628     MOV        this,ESI
    //         004bd62a     PUSH       EDX
    //         004bd62b     CALL       TSpan_Node_List::InitNewZone                     void InitNewZone(TSpan_Node_List * this, int 
    //                              spanlist.cpp:69 (6)
    //         004bd630     MOV        EAX,ESI
    //         004bd632     POP        ESI
    //         004bd633     RET        0xc
}

// Offset: 0x004BD640
void TSpan_Node_List(TSpan_Node_List* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TSpan_Node_List::~TSpan_Node_List(void)                                            *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TSpan_Node_List(TSpan_Node_List * this)
    //              void              <VOID>         <RETURN>
    //              TSpan_Node_Lis    ECX:4 (auto)   this
    //                               ??1TSpan_Node_List@@QAE@XZ                                   XREF[1]:     ~TSpan_List_Manager:004bd9f5(c)  
    //                               TSpan_Node_List::~TSpan_Node_List
    //                              spanlist.cpp:77 (4)
    //         004bd640     PUSH       ESI
    //         004bd641     MOV        ESI,this
    //         004bd643     PUSH       EDI
    //                              spanlist.cpp:82 (9)
    //         004bd644     XOR        EDI,EDI
    //         004bd646     MOV        EAX,dword ptr [ESI + 0x8]
    //         004bd649     TEST       EAX,EAX
    //         004bd64b     JLE        LAB_004bd667
    //                               LAB_004bd64d                                                 XREF[1]:     004bd665(j)  
    //                              spanlist.cpp:84 (26)
    //         004bd64d     MOV        EAX,dword ptr [ESI]
    //         004bd64f     MOV        EAX,dword ptr [EAX + EDI*0x4]
    //         004bd652     TEST       EAX,EAX
    //         004bd654     JZ         LAB_004bd65f
    //         004bd656     PUSH       EAX
    //         004bd657     CALL       free                                             undefined free()
    //         004bd65c     ADD        ESP,0x4
    //                               LAB_004bd65f                                                 XREF[1]:     004bd654(j)  
    //         004bd65f     MOV        EAX,dword ptr [ESI + 0x8]
    //         004bd662     INC        EDI
    //         004bd663     CMP        EDI,EAX
    //         004bd665     JL         LAB_004bd64d
    //                               LAB_004bd667                                                 XREF[1]:     004bd64b(j)  
    //                              spanlist.cpp:87 (15)
    //         004bd667     MOV        EAX,dword ptr [ESI]
    //         004bd669     TEST       EAX,EAX
    //         004bd66b     JZ         LAB_004bd676
    //         004bd66d     PUSH       EAX
    //         004bd66e     CALL       free                                             undefined free()
    //         004bd673     ADD        ESP,0x4
    //                               LAB_004bd676                                                 XREF[1]:     004bd66b(j)  
    //                              spanlist.cpp:88 (16)
    //         004bd676     MOV        ESI,dword ptr [ESI + 0x4]
    //         004bd679     TEST       ESI,ESI
    //         004bd67b     JZ         LAB_004bd686
    //         004bd67d     PUSH       ESI
    //         004bd67e     CALL       free                                             undefined free()
    //         004bd683     ADD        ESP,0x4
    //                               LAB_004bd686                                                 XREF[1]:     004bd67b(j)  
    //                              spanlist.cpp:90 (3)
    //         004bd686     POP        EDI
    //         004bd687     POP        ESI
    //         004bd688     RET
}

// Offset: 0x004BD690
void SetNumZones(TSpan_Node_List* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * private: void __thiscall TSpan_Node_List::SetNumZones(int)                                            *
    //                              *********************************************************************************************************
    //                              void __thiscall SetNumZones(TSpan_Node_List * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TSpan_Node_Lis    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[3]:     004bd691(R), 004bd6ac(W), 004bd6ed(R)  
    //                               ?SetNumZones@TSpan_Node_List@@AAEXH@Z                        XREF[2]:     TSpan_Node_List:004bd61f(c), 
    //                               TSpan_Node_List::SetNumZones                                              InitNewZone:004bd735(c)  
    //                              spanlist.cpp:96 (1)
    //         004bd690     PUSH       EBX
    //                              spanlist.cpp:102 (14)
    //         004bd691     MOV        EBX,dword ptr [ESP + param_1]
    //         004bd695     PUSH       ESI
    //         004bd696     MOV        ESI,this
    //         004bd698     CMP        EBX,dword ptr [ESI + 0xc]
    //         004bd69b     JL         LAB_004bd712
    //         004bd69d     PUSH       EDI
    //         004bd69e     PUSH       EBP
    //                              spanlist.cpp:106 (17)
    //         004bd69f     PUSH       0x4
    //         004bd6a1     PUSH       EBX
    //         004bd6a2     CALL       calloc                                           undefined calloc()
    //         004bd6a7     ADD        ESP,0x8
    //         004bd6aa     MOV        EBP,EAX
    //         004bd6ac     MOV        dword ptr [ESP + param_1],EBP
    //                              spanlist.cpp:109 (10)
    //         004bd6b0     PUSH       0x4
    //         004bd6b2     PUSH       EBX
    //         004bd6b3     CALL       calloc                                           undefined calloc()
    //         004bd6b8     MOV        EDI,EAX
    //                              spanlist.cpp:114 (9)
    //         004bd6ba     MOV        EAX,dword ptr [ESI]
    //         004bd6bc     ADD        ESP,0x8
    //         004bd6bf     TEST       EAX,EAX
    //         004bd6c1     JZ         LAB_004bd708
    //                              spanlist.cpp:116 (13)
    //         004bd6c3     MOV        this,dword ptr [ESI + 0x8]
    //         004bd6c6     XOR        EAX,EAX
    //         004bd6c8     TEST       this,this
    //         004bd6ca     JLE        LAB_004bd6f1
    //         004bd6cc     MOV        EDX,EBP
    //         004bd6ce     SUB        EDX,EDI
    //                               LAB_004bd6d0                                                 XREF[1]:     004bd6eb(j)  
    //                              spanlist.cpp:118 (13)
    //         004bd6d0     MOV        EBP,dword ptr [ESI]
    //         004bd6d2     LEA        this,[EDI + EAX*0x4]
    //         004bd6d5     MOV        EBP,dword ptr [EBP + EAX*0x4]
    //         004bd6d9     INC        EAX
    //         004bd6da     MOV        dword ptr [EDX + this->Zone_Ptrs*0x1],EBP
    //                              spanlist.cpp:119 (16)
    //         004bd6dd     MOV        EBP,dword ptr [ESI + 0x4]
    //         004bd6e0     MOV        EBP,dword ptr [EBP + EAX*0x4 + -0x4]
    //         004bd6e4     MOV        dword ptr [this->Zone_Ptrs],EBP
    //         004bd6e6     MOV        this,dword ptr [ESI + 0x8]
    //         004bd6e9     CMP        EAX,this
    //         004bd6eb     JL         LAB_004bd6d0
    //                              spanlist.cpp:116 (4)
    //         004bd6ed     MOV        EBP,dword ptr [ESP + param_1]
    //                               LAB_004bd6f1                                                 XREF[1]:     004bd6ca(j)  
    //                              spanlist.cpp:121 (8)
    //         004bd6f1     MOV        EAX,dword ptr [ESI]
    //         004bd6f3     PUSH       EAX
    //         004bd6f4     CALL       free                                             undefined free()
    //                              spanlist.cpp:122 (15)
    //         004bd6f9     MOV        this,dword ptr [ESI + 0x4]
    //         004bd6fc     ADD        ESP,0x4
    //         004bd6ff     PUSH       this
    //         004bd700     CALL       free                                             undefined free()
    //         004bd705     ADD        ESP,0x4
    //                               LAB_004bd708                                                 XREF[1]:     004bd6c1(j)  
    //                              spanlist.cpp:127 (2)
    //         004bd708     MOV        dword ptr [ESI],EBP
    //                              spanlist.cpp:128 (4)
    //         004bd70a     MOV        dword ptr [ESI + 0x4],EDI
    //         004bd70d     POP        EBP
    //                              spanlist.cpp:130 (4)
    //         004bd70e     MOV        dword ptr [ESI + 0xc],EBX
    //         004bd711     POP        EDI
    //                               LAB_004bd712                                                 XREF[1]:     004bd69b(j)  
    //                              spanlist.cpp:132 (5)
    //         004bd712     POP        ESI
    //         004bd713     POP        EBX
    //         004bd714     RET        0x4
}

// Offset: 0x004BD720
void InitNewZone(TSpan_Node_List* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * private: void __thiscall TSpan_Node_List::InitNewZone(int)                                            *
    //                              *********************************************************************************************************
    //                              void __thiscall InitNewZone(TSpan_Node_List * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TSpan_Node_Lis    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004bd73d(R)  
    //                               ?InitNewZone@TSpan_Node_List@@AAEXH@Z                        XREF[2]:     TSpan_Node_List:004bd62b(c), 
    //                               TSpan_Node_List::InitNewZone                                              GetNode:004bd79f(c)  
    //                              spanlist.cpp:139 (5)
    //         004bd720     PUSH       EBX
    //         004bd721     PUSH       ESI
    //         004bd722     MOV        ESI,this
    //         004bd724     PUSH       EDI
    //                              spanlist.cpp:145 (21)
    //         004bd725     MOV        EAX,dword ptr [ESI + 0x8]
    //         004bd728     MOV        this,dword ptr [ESI + 0xc]
    //         004bd72b     CMP        EAX,this
    //         004bd72d     JNZ        LAB_004bd73a
    //         004bd72f     ADD        EAX,0x4
    //         004bd732     MOV        this,ESI
    //         004bd734     PUSH       EAX
    //         004bd735     CALL       TSpan_Node_List::SetNumZones                     void SetNumZones(TSpan_Node_List * this, int 
    //                               LAB_004bd73a                                                 XREF[1]:     004bd72d(j)  
    //                              spanlist.cpp:147 (3)
    //         004bd73a     MOV        EBX,dword ptr [ESI + 0x8]
    //                              spanlist.cpp:152 (4)
    //         004bd73d     MOV        EDI,dword ptr [ESP + param_1]
    //                              spanlist.cpp:154 (15)
    //         004bd741     MOV        this,dword ptr [ESI + 0x4]
    //         004bd744     LEA        EAX,[EBX + 0x1]
    //         004bd747     MOV        dword ptr [ESI + 0x8],EAX
    //         004bd74a     MOV        EAX,dword ptr [ESI + 0x28]
    //         004bd74d     IMUL       EAX,EDI
    //                              spanlist.cpp:155 (17)
    //         004bd750     PUSH       EAX
    //         004bd751     MOV        dword ptr [this->Zone_Ptrs + EBX*0x4],EDI
    //         004bd754     CALL       malloc                                           undefined malloc()
    //         004bd759     MOV        EDX,dword ptr [ESI]
    //         004bd75b     ADD        ESP,0x4
    //         004bd75e     MOV        dword ptr [EDX + EBX*0x4],EAX
    //                              spanlist.cpp:160 (3)
    //         004bd761     MOV        EAX,dword ptr [ESI + 0x34]
    //                              spanlist.cpp:161 (3)
    //         004bd764     MOV        EDX,dword ptr [ESI + 0x1c]
    //                              spanlist.cpp:162 (9)
    //         004bd767     MOV        this,dword ptr [ESI + 0x20]
    //         004bd76a     INC        EAX
    //         004bd76b     ADD        EDX,EDI
    //         004bd76d     MOV        dword ptr [ESI + 0x34],EAX
    //                              spanlist.cpp:164 (16)
    //         004bd770     MOV        EAX,dword ptr [ESI + 0x14]
    //         004bd773     ADD        this,EDI
    //         004bd775     CMP        EAX,-0x1
    //         004bd778     MOV        dword ptr [ESI + 0x1c],EDX
    //         004bd77b     MOV        dword ptr [ESI + 0x20],this
    //         004bd77e     JNZ        LAB_004bd78a
    //                              spanlist.cpp:166 (3)
    //         004bd780     MOV        dword ptr [ESI + 0x14],EBX
    //                              spanlist.cpp:167 (7)
    //         004bd783     MOV        dword ptr [ESI + 0x18],0x0
    //                               LAB_004bd78a                                                 XREF[1]:     004bd77e(j)  
    //                              spanlist.cpp:170 (6)
    //         004bd78a     POP        EDI
    //         004bd78b     POP        ESI
    //         004bd78c     POP        EBX
    //         004bd78d     RET        0x4
}

// Offset: 0x004BD790
VSpan_Node* GetNode(TSpan_Node_List* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: struct VSpan_Node * __thiscall TSpan_Node_List::GetNode(void)                                 *
    //                              *********************************************************************************************************
    //                              VSpan_Node * __thiscall GetNode(TSpan_Node_List * this)
    //              VSpan_Node *      EAX:4          <RETURN>
    //              TSpan_Node_Lis    ECX:4 (auto)   this
    //                               ?GetNode@TSpan_Node_List@@QAEPAUVSpan_Node@@XZ               XREF[5]:     AddSpan:004bdb6d(c), 
    //                               TSpan_Node_List::GetNode                                                  AddSpan:004bdbcd(c), 
    //                                                                                                         AddSpan:004bdcdd(c), 
    //                                                                                                         AddSpan:004bddb4(c), 
    //                                                                                                         DeleteSpan:004be3aa(c)  
    //                              spanlist.cpp:177 (4)
    //         004bd790     PUSH       ESI
    //         004bd791     MOV        ESI,this
    //         004bd793     PUSH       EDI
    //                              spanlist.cpp:180 (7)
    //         004bd794     MOV        EAX,dword ptr [ESI + 0x20]
    //         004bd797     TEST       EAX,EAX
    //         004bd799     JNZ        LAB_004bd7a4
    //                              spanlist.cpp:182 (9)
    //         004bd79b     MOV        EAX,dword ptr [ESI + 0x24]
    //         004bd79e     PUSH       EAX
    //         004bd79f     CALL       TSpan_Node_List::InitNewZone                     void InitNewZone(TSpan_Node_List * this, int 
    //                               LAB_004bd7a4                                                 XREF[1]:     004bd799(j)  
    //                              spanlist.cpp:187 (7)
    //         004bd7a4     MOV        EAX,dword ptr [ESI + 0x10]
    //         004bd7a7     TEST       EAX,EAX
    //         004bd7a9     JZ         LAB_004bd7ba
    //                              spanlist.cpp:190 (5)
    //         004bd7ab     MOV        this,dword ptr [EAX]
    //         004bd7ad     MOV        dword ptr [ESI + 0x10],this
    //                              spanlist.cpp:191 (7)
    //         004bd7b0     MOV        this,dword ptr [ESI + 0x20]
    //         004bd7b3     DEC        this
    //         004bd7b4     MOV        dword ptr [ESI + 0x20],this
    //                              spanlist.cpp:228 (3)
    //         004bd7b7     POP        EDI
    //         004bd7b8     POP        ESI
    //         004bd7b9     RET
    //                               LAB_004bd7ba                                                 XREF[1]:     004bd7a9(j)  
    //                              spanlist.cpp:204 (18)
    //         004bd7ba     MOV        this,dword ptr [ESI + 0x18]
    //         004bd7bd     MOV        EDX,dword ptr [ESI + 0x14]
    //         004bd7c0     MOV        EAX,dword ptr [ESI]
    //         004bd7c2     MOV        EDI,this
    //         004bd7c4     SHL        EDI,0x4
    //         004bd7c7     MOV        EAX,dword ptr [EAX + EDX*0x4]
    //         004bd7ca     ADD        EAX,EDI
    //                              spanlist.cpp:206 (4)
    //         004bd7cc     MOV        EDI,dword ptr [ESI + 0x20]
    //         004bd7cf     DEC        EDI
    //                              spanlist.cpp:210 (4)
    //         004bd7d0     INC        this
    //         004bd7d1     MOV        dword ptr [ESI + 0x20],EDI
    //                              spanlist.cpp:211 (11)
    //         004bd7d4     MOV        EDI,dword ptr [ESI + 0x4]
    //         004bd7d7     MOV        dword ptr [ESI + 0x18],this
    //         004bd7da     CMP        this,dword ptr [EDI + EDX*0x4]
    //         004bd7dd     JNZ        LAB_004bd7fa
    //                              spanlist.cpp:213 (3)
    //         004bd7df     LEA        this,[EDX + 0x1]
    //                              spanlist.cpp:215 (17)
    //         004bd7e2     MOV        EDX,dword ptr [ESI + 0x8]
    //         004bd7e5     CMP        this,EDX
    //         004bd7e7     MOV        dword ptr [ESI + 0x14],this
    //         004bd7ea     MOV        dword ptr [ESI + 0x18],0x0
    //         004bd7f1     JNZ        LAB_004bd7fa
    //                              spanlist.cpp:217 (7)
    //         004bd7f3     MOV        dword ptr [ESI + 0x14],0xffffffff
    //                               LAB_004bd7fa                                                 XREF[2]:     004bd7dd(j), 004bd7f1(j)  
    //                              spanlist.cpp:228 (3)
    //         004bd7fa     POP        EDI
    //         004bd7fb     POP        ESI
    //         004bd7fc     RET
}

// Offset: 0x004BD800
void FreeNode(TSpan_Node_List* this_, VSpan_Node* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TSpan_Node_List::FreeNode(struct VSpan_Node *)                                *
    //                              *********************************************************************************************************
    //                              void __thiscall FreeNode(TSpan_Node_List * this, VSpan_Node * param_1)
    //              void              <VOID>         <RETURN>
    //              TSpan_Node_Lis    ECX:4 (auto)   this
    //              VSpan_Node *      Stack[0x4]:4   param_1                   XREF[1]:     004bd800(R)  
    //                               ?FreeNode@TSpan_Node_List@@QAEXPAUVSpan_Node@@@Z             XREF[7]:     AddSpan:004bdc8f(c), 
    //                               TSpan_Node_List::FreeNode                                                 AddSpan:004bdd4f(c), 
    //                                                                                                         AddSpan:004bde34(c), 
    //                                                                                                         AddSpan:004bde66(c), 
    //                                                                                                         DeleteSpan:004be447(c), 
    //                                                                                                         AlignamizeSpans:004be6ff(c), 
    //                                                                                                         ScrollSpansHorizontally:004be829(c
    //                              spanlist.cpp:233 (9)
    //         004bd800     MOV        EAX,dword ptr [ESP + param_1]
    //         004bd804     MOV        EDX,dword ptr [ECX + this->Free_Head]
    //         004bd807     MOV        dword ptr [EAX],EDX
    //                              spanlist.cpp:237 (7)
    //         004bd809     MOV        dword ptr [EAX + 0x4],0x0
    //                              spanlist.cpp:238 (3)
    //         004bd810     MOV        dword ptr [ECX + this->Free_Head],EAX
    //                              spanlist.cpp:239 (7)
    //         004bd813     MOV        EAX,dword ptr [ECX + this->Free_Blocks]
    //         004bd816     INC        EAX
    //         004bd817     MOV        dword ptr [ECX + this->Free_Blocks],EAX
    //                              spanlist.cpp:241 (3)
    //         004bd81a     RET        0x4
}

// Offset: 0x004BD820
int FreeThread(TSpan_Node_List* this_, VSpan_Node* param_2, VSpan_Node* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TSpan_Node_List::FreeThread(struct VSpan_Node *,struct VSpan_Node *)           *
    //                              *********************************************************************************************************
    //                              int __thiscall FreeThread(TSpan_Node_List * this, VSpan_Node * param
    //              int               EAX:4          <RETURN>
    //              TSpan_Node_Lis    ECX:4 (auto)   this
    //              VSpan_Node *      Stack[0x4]:4   param_1                   XREF[1]:     004bd821(R)  
    //              VSpan_Node *      Stack[0x8]:4   param_2                   XREF[1]:     004bd832(R)  
    //                               ?FreeThread@TSpan_Node_List@@QAEHPAUVSpan_Node@@0@Z          XREF[3]:     AddSpan:004bdc1a(c), 
    //                               TSpan_Node_List::FreeThread                                               DeleteSpan:004be33a(c), 
    //                                                                                                         ScrollSpansVertically:004be8d0(c)  
    //                              spanlist.cpp:251 (1)
    //         004bd820     PUSH       EDI
    //                              spanlist.cpp:252 (4)
    //         004bd821     MOV        EDI,dword ptr [ESP + param_1]
    //                              spanlist.cpp:253 (4)
    //         004bd825     XOR        EAX,EAX
    //         004bd827     MOV        EDX,EDI
    //                              spanlist.cpp:255 (4)
    //         004bd829     TEST       EDI,EDI
    //         004bd82b     JNZ        LAB_004bd831
    //                              spanlist.cpp:285 (4)
    //         004bd82d     POP        EDI
    //         004bd82e     RET        0x8
    //                               LAB_004bd831                                                 XREF[1]:     004bd82b(j)  
    //                              spanlist.cpp:251 (1)
    //         004bd831     PUSH       ESI
    //                              spanlist.cpp:259 (9)
    //         004bd832     MOV        ESI,dword ptr [ESP + param_2]
    //         004bd836     TEST       ESI,ESI
    //         004bd838     PUSH       EBX
    //         004bd839     JNZ        LAB_004bd859
    //                               LAB_004bd83b                                                 XREF[1]:     004bd849(j)  
    //                              spanlist.cpp:264 (6)
    //         004bd83b     MOV        EBX,dword ptr [ECX + this->Free_Blocks]
    //         004bd83e     MOV        ESI,EDX
    //         004bd840     INC        EBX
    //                              spanlist.cpp:265 (4)
    //         004bd841     INC        EAX
    //         004bd842     MOV        dword ptr [ECX + this->Free_Blocks],EBX
    //                              spanlist.cpp:266 (6)
    //         004bd845     MOV        EDX,dword ptr [EDX]
    //         004bd847     TEST       EDX,EDX
    //         004bd849     JNZ        LAB_004bd83b
    //                              spanlist.cpp:281 (6)
    //         004bd84b     MOV        EDX,dword ptr [ECX + this->Free_Head]
    //         004bd84e     POP        EBX
    //         004bd84f     MOV        dword ptr [ESI],EDX
    //                              spanlist.cpp:282 (4)
    //         004bd851     MOV        dword ptr [ECX + this->Free_Head],EDI
    //         004bd854     POP        ESI
    //                              spanlist.cpp:285 (4)
    //         004bd855     POP        EDI
    //         004bd856     RET        0x8
    //                               LAB_004bd859                                                 XREF[2]:     004bd839(j), 004bd86d(j)  
    //                              spanlist.cpp:273 (4)
    //         004bd859     MOV        EBX,dword ptr [ECX + this->Free_Blocks]
    //         004bd85c     INC        EBX
    //                              spanlist.cpp:274 (1)
    //         004bd85d     INC        EAX
    //                              spanlist.cpp:275 (13)
    //         004bd85e     CMP        EDX,ESI
    //         004bd860     MOV        dword ptr [ECX + this->Free_Blocks],EBX
    //         004bd863     JZ         LAB_004bd869
    //         004bd865     MOV        EDX,dword ptr [EDX]
    //         004bd867     JMP        LAB_004bd86b
    //                               LAB_004bd869                                                 XREF[1]:     004bd863(j)  
    //         004bd869     XOR        EDX,EDX
    //                               LAB_004bd86b                                                 XREF[1]:     004bd867(j)  
    //                              spanlist.cpp:276 (4)
    //         004bd86b     TEST       EDX,EDX
    //         004bd86d     JNZ        LAB_004bd859
    //                              spanlist.cpp:281 (6)
    //         004bd86f     MOV        EDX,dword ptr [ECX + this->Free_Head]
    //         004bd872     POP        EBX
    //         004bd873     MOV        dword ptr [ESI],EDX
    //                              spanlist.cpp:282 (4)
    //         004bd875     MOV        dword ptr [ECX + this->Free_Head],EDI
    //         004bd878     POP        ESI
    //                              spanlist.cpp:285 (4)
    //         004bd879     POP        EDI
    //         004bd87a     RET        0x8
}

// Offset: 0x004BD880
void ReclaimAllNodes(TSpan_Node_List* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TSpan_Node_List::ReclaimAllNodes(void)                                        *
    //                              *********************************************************************************************************
    //                              void __thiscall ReclaimAllNodes(TSpan_Node_List * this)
    //              void              <VOID>         <RETURN>
    //              TSpan_Node_Lis    ECX:4 (auto)   this
    //                               ?ReclaimAllNodes@TSpan_Node_List@@QAEXXZ                     XREF[1]:     ResetAll:004bda74(c)  
    //                               TSpan_Node_List::ReclaimAllNodes
    //                              spanlist.cpp:292 (5)
    //         004bd880     XOR        EAX,EAX
    //         004bd882     MOV        dword ptr [ECX + this->Free_Head],EAX
    //                              spanlist.cpp:295 (3)
    //         004bd885     MOV        dword ptr [ECX + this->Free_Pool_Zone],EAX
    //                              spanlist.cpp:296 (3)
    //         004bd888     MOV        dword ptr [ECX + this->Free_Pool_Index],EAX
    //                              spanlist.cpp:297 (6)
    //         004bd88b     MOV        EAX,dword ptr [ECX + this->Total_Blocks]
    //         004bd88e     MOV        dword ptr [ECX + this->Free_Blocks],EAX
    //                              spanlist.cpp:299 (7)
    //         004bd891     MOV        EAX,dword ptr [ECX + this->Reset_Count]
    //         004bd894     INC        EAX
    //         004bd895     MOV        dword ptr [ECX + this->Reset_Count],EAX
    //                              spanlist.cpp:300 (1)
    //         004bd898     RET
}

// Offset: 0x004BD8A0
void ResetStats(TSpan_Node_List* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TSpan_Node_List::ResetStats(void)                                             *
    //                              *********************************************************************************************************
    //                              void __thiscall ResetStats(TSpan_Node_List * this)
    //              void              <VOID>         <RETURN>
    //              TSpan_Node_Lis    ECX:4 (auto)   this
    //                               ?ResetStats@TSpan_Node_List@@QAEXXZ                          XREF[1]:     TSpan_Node_List:004bd616(c)  
    //                               TSpan_Node_List::ResetStats
    //                              spanlist.cpp:308 (5)
    //         004bd8a0     XOR        EAX,EAX
    //         004bd8a2     MOV        dword ptr [ECX + this->Alloc_Count],EAX
    //                              spanlist.cpp:310 (3)
    //         004bd8a5     MOV        dword ptr [ECX + this->Dealloc_Count],EAX
    //                              spanlist.cpp:311 (3)
    //         004bd8a8     MOV        dword ptr [ECX + this->NewZone_Count],EAX
    //                              spanlist.cpp:312 (3)
    //         004bd8ab     MOV        dword ptr [ECX + this->Reset_Count],EAX
    //                              spanlist.cpp:313 (1)
    //         004bd8ae     RET
}

// Offset: 0x004BD8B0
undefined TSpan_List_Manager(TSpan_List_Manager* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TSpan_List_Manager::TSpan_List_Manager(int,int)                                    *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TSpan_List_Manager(TSpan_List_Manager * this, i
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TSpan_List_Man    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004bd8c7(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004bd8cd(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004bd8f7(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004bd97e(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004bd8e2(W)  
    //                               ??0TSpan_List_Manager@@QAE@HH@Z                              XREF[5]:     SetSize:00444619(c), 
    //                               TSpan_List_Manager::TSpan_List_Manager                                    SetClipRect:00444cc5(c), 
    //                                                                                                         set_rect:00534031(c), 
    //                                                                                                         set_rect:00534065(c), 
    //                                                                                                         set_rect:00534096(c)  
    //                              spanlist.cpp:334 (68)
    //         004bd8b0     PUSH       -0x1
    //         004bd8b2     PUSH       FUN_0055f8d8
    //         004bd8b7     MOV        EAX,FS:[0x0]
    //         004bd8bd     PUSH       EAX
    //         004bd8be     MOV        dword ptr FS:[0x0],ESP
    //         004bd8c5     PUSH       this
    //         004bd8c6     PUSH       EBX
    //         004bd8c7     MOV        EBX,dword ptr [ESP + param_1]
    //         004bd8cb     PUSH       ESI
    //         004bd8cc     PUSH       EDI
    //         004bd8cd     MOV        EDI,dword ptr [ESP + param_2]
    //         004bd8d1     PUSH       0x10
    //         004bd8d3     MOV        EAX,EDI
    //         004bd8d5     MOV        ESI,this
    //         004bd8d7     SHL        EAX,0x4
    //         004bd8da     PUSH       EAX
    //         004bd8db     LEA        EAX,[EBX + 0x1f]
    //         004bd8de     CDQ
    //         004bd8df     AND        EDX,0x1f
    //         004bd8e2     MOV        dword ptr [ESP + local_10],ESI
    //         004bd8e6     ADD        EAX,EDX
    //         004bd8e8     SAR        EAX,0x5
    //         004bd8eb     IMUL       EAX,EDI
    //         004bd8ee     PUSH       EAX
    //         004bd8ef     CALL       TSpan_Node_List::TSpan_Node_List                 undefined TSpan_Node_List(TSpan_Node_List * t
    //                              spanlist.cpp:337 (23)
    //         004bd8f4     CMP        EDI,0x10
    //         004bd8f7     MOV        dword ptr [ESP + local_4],0x0
    //         004bd8ff     MOV        dword ptr [ESI + 0x50],EDI
    //         004bd902     JGE        LAB_004bd90b
    //         004bd904     MOV        dword ptr [ESI + 0x50],0x10
    //                               LAB_004bd90b                                                 XREF[1]:     004bd902(j)  
    //                              spanlist.cpp:340 (15)
    //         004bd90b     CMP        EBX,0x10
    //         004bd90e     MOV        dword ptr [ESI + 0x54],EBX
    //         004bd911     JGE        LAB_004bd91a
    //         004bd913     MOV        dword ptr [ESI + 0x54],0x10
    //                               LAB_004bd91a                                                 XREF[1]:     004bd911(j)  
    //                              spanlist.cpp:342 (21)
    //         004bd91a     MOV        this,dword ptr [ESI + 0x50]
    //         004bd91d     MOV        EDX,dword ptr [ESI + 0x54]
    //         004bd920     DEC        this
    //         004bd921     DEC        EDX
    //         004bd922     PUSH       this
    //         004bd923     PUSH       EDX
    //         004bd924     PUSH       0x0
    //         004bd926     PUSH       0x0
    //         004bd928     MOV        this,ESI
    //         004bd92a     CALL       TSpan_List_Manager::SetSpanRegions               void SetSpanRegions(TSpan_List_Manager * this
    //                              spanlist.cpp:344 (11)
    //         004bd92f     MOV        EAX,dword ptr [ESI + 0x50]
    //         004bd932     PUSH       0x4
    //         004bd934     PUSH       EAX
    //         004bd935     CALL       calloc                                           undefined calloc()
    //                              spanlist.cpp:345 (17)
    //         004bd93a     MOV        this,dword ptr [ESI + 0x50]
    //         004bd93d     ADD        ESP,0x8
    //         004bd940     MOV        dword ptr [ESI + 0x3c],EAX
    //         004bd943     PUSH       0x4
    //         004bd945     PUSH       this
    //         004bd946     CALL       calloc                                           undefined calloc()
    //                              spanlist.cpp:347 (23)
    //         004bd94b     MOV        EDX,dword ptr [ESI + 0x50]
    //         004bd94e     ADD        ESP,0x8
    //         004bd951     MOV        dword ptr [ESI + 0x40],EAX
    //         004bd954     PUSH       0x4
    //         004bd956     PUSH       EDX
    //         004bd957     CALL       calloc                                           undefined calloc()
    //         004bd95c     ADD        ESP,0x8
    //         004bd95f     MOV        dword ptr [ESI + 0x44],EAX
    //                              spanlist.cpp:348 (11)
    //         004bd962     MOV        EAX,dword ptr [ESI + 0x50]
    //         004bd965     PUSH       0x4
    //         004bd967     PUSH       EAX
    //         004bd968     CALL       calloc                                           undefined calloc()
    //                              spanlist.cpp:349 (17)
    //         004bd96d     MOV        this,dword ptr [ESI + 0x50]
    //         004bd970     ADD        ESP,0x8
    //         004bd973     MOV        dword ptr [ESI + 0x48],EAX
    //         004bd976     PUSH       0x4
    //         004bd978     PUSH       this
    //         004bd979     CALL       calloc                                           undefined calloc()
    //                              spanlist.cpp:351 (28)
    //         004bd97e     MOV        this,dword ptr [ESP + local_c]
    //         004bd982     ADD        ESP,0x8
    //         004bd985     MOV        dword ptr [ESI + 0x4c],EAX
    //         004bd988     MOV        EAX,ESI
    //         004bd98a     POP        EDI
    //         004bd98b     POP        ESI
    //         004bd98c     MOV        dword ptr FS:[0x0],this
    //         004bd993     POP        EBX
    //         004bd994     ADD        ESP,0x10
    //         004bd997     RET        0x8
}

// Offset: 0x004BD9A0
void TSpan_List_Manager(TSpan_List_Manager* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TSpan_List_Manager::~TSpan_List_Manager(void)                                      *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TSpan_List_Manager(TSpan_List_Manager * this)
    //              void              <VOID>         <RETURN>
    //              TSpan_List_Man    ECX:4 (auto)   this
    //                               ??1TSpan_List_Manager@@QAE@XZ                                XREF[9]:     ~TDrawArea:00444010(c), 
    //                               TSpan_List_Manager::~TSpan_List_Manager                                   SetSize:004445ec(c), 
    //                                                                                                         SetClipRect:00444c7f(c), 
    //                                                                                                         ~RGE_View:005337f2(c), 
    //                                                                                                         ~RGE_View:0053380c(c), 
    //                                                                                                         ~RGE_View:00533826(c), 
    //                                                                                                         set_rect:00533fd1(c), 
    //                                                                                                         set_rect:00533feb(c), 
    //                                                                                                         set_rect:00534005(c)  
    //                              spanlist.cpp:358 (3)
    //         004bd9a0     PUSH       ESI
    //         004bd9a1     MOV        ESI,this
    //                              spanlist.cpp:360 (16)
    //         004bd9a3     MOV        EAX,dword ptr [ESI + 0x3c]
    //         004bd9a6     TEST       EAX,EAX
    //         004bd9a8     JZ         LAB_004bd9b3
    //         004bd9aa     PUSH       EAX
    //         004bd9ab     CALL       free                                             undefined free()
    //         004bd9b0     ADD        ESP,0x4
    //                               LAB_004bd9b3                                                 XREF[1]:     004bd9a8(j)  
    //                              spanlist.cpp:361 (16)
    //         004bd9b3     MOV        EAX,dword ptr [ESI + 0x40]
    //         004bd9b6     TEST       EAX,EAX
    //         004bd9b8     JZ         LAB_004bd9c3
    //         004bd9ba     PUSH       EAX
    //         004bd9bb     CALL       free                                             undefined free()
    //         004bd9c0     ADD        ESP,0x4
    //                               LAB_004bd9c3                                                 XREF[1]:     004bd9b8(j)  
    //                              spanlist.cpp:363 (16)
    //         004bd9c3     MOV        EAX,dword ptr [ESI + 0x44]
    //         004bd9c6     TEST       EAX,EAX
    //         004bd9c8     JZ         LAB_004bd9d3
    //         004bd9ca     PUSH       EAX
    //         004bd9cb     CALL       free                                             undefined free()
    //         004bd9d0     ADD        ESP,0x4
    //                               LAB_004bd9d3                                                 XREF[1]:     004bd9c8(j)  
    //                              spanlist.cpp:364 (16)
    //         004bd9d3     MOV        EAX,dword ptr [ESI + 0x48]
    //         004bd9d6     TEST       EAX,EAX
    //         004bd9d8     JZ         LAB_004bd9e3
    //         004bd9da     PUSH       EAX
    //         004bd9db     CALL       free                                             undefined free()
    //         004bd9e0     ADD        ESP,0x4
    //                               LAB_004bd9e3                                                 XREF[1]:     004bd9d8(j)  
    //                              spanlist.cpp:365 (23)
    //         004bd9e3     MOV        EAX,dword ptr [ESI + 0x4c]
    //         004bd9e6     TEST       EAX,EAX
    //         004bd9e8     JZ         LAB_004bd9f3
    //         004bd9ea     PUSH       EAX
    //         004bd9eb     CALL       free                                             undefined free()
    //         004bd9f0     ADD        ESP,0x4
    //                               LAB_004bd9f3                                                 XREF[1]:     004bd9e8(j)  
    //         004bd9f3     MOV        this,ESI
    //         004bd9f5     CALL       TSpan_Node_List::~TSpan_Node_List                void ~TSpan_Node_List(TSpan_Node_List * this)
    //                              spanlist.cpp:367 (2)
    //         004bd9fa     POP        ESI
    //         004bd9fb     RET
}

// Offset: 0x004BDA00
void SetSpanRegions(TSpan_List_Manager* this_, int param_2, int param_3, int param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TSpan_List_Manager::SetSpanRegions(int,int,int,int)                           *
    //                              *********************************************************************************************************
    //                              void __thiscall SetSpanRegions(TSpan_List_Manager * this, int param_
    //              void              <VOID>         <RETURN>
    //              TSpan_List_Man    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004bda06(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004bda15(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     004bda01(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     004bda19(R)  
    //                               ?SetSpanRegions@TSpan_List_Manager@@QAEXHHHH@Z               XREF[12]:    SetClipRect:00444cfd(c), 
    //                               TSpan_List_Manager::SetSpanRegions                                        TSpan_List_Manager:004bd92a(c), 
    //                                                                                                         view_function_terrain:005370cf(c), 
    //                                                                                                         view_function_terrain:005370f6(c), 
    //                                                                                                         view_function_terrain:00537126(c), 
    //                                                                                                         view_function_terrain:0053714d(c), 
    //                                                                                                         view_function_terrain:0053717d(c), 
    //                                                                                                         view_function_terrain:005371a4(c), 
    //                                                                                                         view_function_terrain:0053725f(c), 
    //                                                                                                         view_function_terrain:00537286(c), 
    //                                                                                                         view_function_terrain:00537815(c), 
    //                                                                                                         view_function_terrain:0053783c(c)  
    //                              spanlist.cpp:371 (1)
    //         004bda00     PUSH       EBX
    //                              spanlist.cpp:377 (20)
    //         004bda01     MOV        EBX,dword ptr [ESP + param_3]
    //         004bda05     PUSH       ESI
    //         004bda06     MOV        ESI,dword ptr [ESP + param_1]
    //         004bda0a     CMP        ESI,EBX
    //         004bda0c     PUSH       EDI
    //         004bda0d     JLE        LAB_004bda15
    //         004bda0f     MOV        EAX,ESI
    //         004bda11     MOV        ESI,EBX
    //         004bda13     MOV        EBX,EAX
    //                               LAB_004bda15                                                 XREF[1]:     004bda0d(j)  
    //                              spanlist.cpp:378 (18)
    //         004bda15     MOV        EAX,dword ptr [ESP + param_2]
    //         004bda19     MOV        EDI,dword ptr [ESP + param_4]
    //         004bda1d     CMP        EAX,EDI
    //         004bda1f     JLE        LAB_004bda27
    //         004bda21     MOV        EDX,EAX
    //         004bda23     MOV        EAX,EDI
    //         004bda25     MOV        EDI,EDX
    //                               LAB_004bda27                                                 XREF[1]:     004bda1f(j)  
    //                              spanlist.cpp:382 (6)
    //         004bda27     TEST       EAX,EAX
    //         004bda29     JGE        LAB_004bda2d
    //         004bda2b     XOR        EAX,EAX
    //                               LAB_004bda2d                                                 XREF[1]:     004bda29(j)  
    //                              spanlist.cpp:383 (4)
    //         004bda2d     TEST       EDI,EDI
    //         004bda2f     JL         LAB_004bda63
    //                              spanlist.cpp:385 (7)
    //         004bda31     MOV        EDX,dword ptr [ECX + this->Num_Lines]
    //         004bda34     CMP        EAX,EDX
    //         004bda36     JGE        LAB_004bda63
    //                              spanlist.cpp:386 (7)
    //         004bda38     CMP        EDI,EDX
    //         004bda3a     JL         LAB_004bda3f
    //         004bda3c     LEA        EDI,[EDX + -0x1]
    //                               LAB_004bda3f                                                 XREF[1]:     004bda3a(j)  
    //                              spanlist.cpp:388 (6)
    //         004bda3f     TEST       ESI,ESI
    //         004bda41     JGE        LAB_004bda45
    //         004bda43     XOR        ESI,ESI
    //                               LAB_004bda45                                                 XREF[1]:     004bda41(j)  
    //                              spanlist.cpp:389 (4)
    //         004bda45     TEST       EBX,EBX
    //         004bda47     JL         LAB_004bda63
    //                              spanlist.cpp:391 (7)
    //         004bda49     MOV        EDX,dword ptr [ECX + this->Num_Pixels]
    //         004bda4c     CMP        ESI,EDX
    //         004bda4e     JGE        LAB_004bda63
    //                              spanlist.cpp:392 (7)
    //         004bda50     CMP        EBX,EDX
    //         004bda52     JL         LAB_004bda57
    //         004bda54     LEA        EBX,[EDX + -0x1]
    //                               LAB_004bda57                                                 XREF[1]:     004bda52(j)  
    //                              spanlist.cpp:394 (3)
    //         004bda57     MOV        dword ptr [ECX + this->Min_Line],EAX
    //                              spanlist.cpp:395 (3)
    //         004bda5a     MOV        dword ptr [ECX + this->Max_Line],EDI
    //                              spanlist.cpp:397 (3)
    //         004bda5d     MOV        dword ptr [ECX + this->Min_Span_Px],ESI
    //                              spanlist.cpp:398 (3)
    //         004bda60     MOV        dword ptr [ECX + this->Max_Span_Px],EBX
    //                               LAB_004bda63                                                 XREF[4]:     004bda2f(j), 004bda36(j), 
    //                                                                                                         004bda47(j), 004bda4e(j)  
    //                              spanlist.cpp:400 (6)
    //         004bda63     POP        EDI
    //         004bda64     POP        ESI
    //         004bda65     POP        EBX
    //         004bda66     RET        0x10
}

// Offset: 0x004BDA70
void ResetAll(TSpan_List_Manager* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TSpan_List_Manager::ResetAll(void)                                            *
    //                              *********************************************************************************************************
    //                              void __thiscall ResetAll(TSpan_List_Manager * this)
    //              void              <VOID>         <RETURN>
    //              TSpan_List_Man    ECX:4 (auto)   this
    //                               ?ResetAll@TSpan_List_Manager@@QAEXXZ                         XREF[7]:     SetClipRect:00444ce2(c), 
    //                               TSpan_List_Manager::ResetAll                                              Merge_n_Align:004be5f6(c), 
    //                                                                                                         ScrollSpansHorizontally:004be786(c
    //                                                                                                         ScrollSpansVertically:004be89d(c), 
    //                                                                                                         draw:00534b82(c), 
    //                                                                                                         draw:00534b8d(c), 
    //                                                                                                         draw:00534b98(c)  
    //                              spanlist.cpp:407 (4)
    //         004bda70     PUSH       ESI
    //         004bda71     PUSH       EDI
    //         004bda72     MOV        ESI,this
    //                              spanlist.cpp:408 (5)
    //         004bda74     CALL       TSpan_Node_List::ReclaimAllNodes                 void ReclaimAllNodes(TSpan_Node_List * this)
    //                              spanlist.cpp:410 (25)
    //         004bda79     MOV        this,dword ptr [ESI + 0x50]
    //         004bda7c     MOV        EDI,dword ptr [ESI + 0x3c]
    //         004bda7f     SHL        this,0x2
    //         004bda82     MOV        EDX,this
    //         004bda84     XOR        EAX,EAX
    //         004bda86     SHR        this,0x2
    //         004bda89     STOSD.REP  ES:EDI
    //         004bda8b     MOV        this,EDX
    //         004bda8d     AND        this,0x3
    //         004bda90     STOSB.REP  ES:EDI
    //                              spanlist.cpp:411 (25)
    //         004bda92     MOV        this,dword ptr [ESI + 0x50]
    //         004bda95     MOV        EDI,dword ptr [ESI + 0x40]
    //         004bda98     SHL        this,0x2
    //         004bda9b     MOV        EDX,this
    //         004bda9d     XOR        EAX,EAX
    //         004bda9f     SHR        this,0x2
    //         004bdaa2     STOSD.REP  ES:EDI
    //         004bdaa4     MOV        this,EDX
    //         004bdaa6     AND        this,0x3
    //         004bdaa9     STOSB.REP  ES:EDI
    //                              spanlist.cpp:413 (25)
    //         004bdaab     MOV        this,dword ptr [ESI + 0x50]
    //         004bdaae     MOV        EDI,dword ptr [ESI + 0x44]
    //         004bdab1     SHL        this,0x2
    //         004bdab4     MOV        EDX,this
    //         004bdab6     XOR        EAX,EAX
    //         004bdab8     SHR        this,0x2
    //         004bdabb     STOSD.REP  ES:EDI
    //         004bdabd     MOV        this,EDX
    //         004bdabf     AND        this,0x3
    //         004bdac2     STOSB.REP  ES:EDI
    //                              spanlist.cpp:414 (25)
    //         004bdac4     MOV        this,dword ptr [ESI + 0x50]
    //         004bdac7     MOV        EDI,dword ptr [ESI + 0x48]
    //         004bdaca     SHL        this,0x2
    //         004bdacd     MOV        EDX,this
    //         004bdacf     XOR        EAX,EAX
    //         004bdad1     SHR        this,0x2
    //         004bdad4     STOSD.REP  ES:EDI
    //         004bdad6     MOV        this,EDX
    //         004bdad8     AND        this,0x3
    //         004bdadb     STOSB.REP  ES:EDI
    //                              spanlist.cpp:415 (25)
    //         004bdadd     MOV        this,dword ptr [ESI + 0x50]
    //         004bdae0     MOV        EDI,dword ptr [ESI + 0x4c]
    //         004bdae3     SHL        this,0x2
    //         004bdae6     MOV        EDX,this
    //         004bdae8     XOR        EAX,EAX
    //         004bdaea     SHR        this,0x2
    //         004bdaed     STOSD.REP  ES:EDI
    //         004bdaef     MOV        this,EDX
    //         004bdaf1     AND        this,0x3
    //         004bdaf4     STOSB.REP  ES:EDI
    //                              spanlist.cpp:417 (3)
    //         004bdaf6     POP        EDI
    //         004bdaf7     POP        ESI
    //         004bdaf8     RET
}

// Offset: 0x004BDB00
void AddSpan(TSpan_List_Manager* this_, int param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TSpan_List_Manager::AddSpan(int,int,int)                                      *
    //                              *********************************************************************************************************
    //                              void __thiscall AddSpan(TSpan_List_Manager * this, int param_1, int 
    //              void              <VOID>         <RETURN>
    //              TSpan_List_Man    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[11]:    004bdb20(R), 004bdb2c(W), 004bdb50(W), 004bdb72(R), 
    //                                                                                     004bdbb6(R), 004bdbd2(R), 004bdc27(R), 004bdc6b(R), 
    //                                                                                     004bdce2(R), 004bdd2e(R), 004bddc1(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[16]:    004bdb1c(R), 004bdb28(W), 004bdb32(R), 004bdb58(W), 
    //                                                                                     004bdbc2(R), 004bdc13(W), 004bdc1f(R), 004bdc6f(R), 
    //                                                                                     004bdccc(R), 004bdcf5(R), 004bdd16(R), 004bdd70(R), 
    //                                                                                     004bdd7e(R), 004bdda0(R), 004bddcd(R), 004bde01(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[3]:     004bdb06(R), 004bddac(W), 004bde05(R)  
    //                               ?AddSpan@TSpan_List_Manager@@QAEXHHH@Z                       XREF[22]:    SetSize:00444642(c), 
    //                               TSpan_List_Manager::AddSpan                                               SetClipRect:00444d1b(c), 
    //                                                                                                         AddShape:004bdf2d(c), 
    //                                                                                                         AddShape_Align:004be019(c), 
    //                                                                                                         AddShape_Align:004be071(c), 
    //                                                                                                         AddLine_Align:004be0cd(c), 
    //                                                                                                         AddLine_Align:004be0f5(c), 
    //                                                                                                         AddLine_Align:004be167(c), 
    //                                                                                                         AddLine_Align:004be190(c), 
    //                                                                                                         AddLine_Align:004be1b5(c), 
    //                                                                                                         AddMiniList:004be226(c), 
    //                                                                                                         Merge_n_Align:004be657(c), 
    //                                                                                                         Merge_n_Align:004be673(c), 
    //                                                                                                         view_function_terrain:00537c24(c), 
    //                                                                                                         view_function_terrain:00537c9b(c), 
    //                                                                                                         view_function_terrain:00537ce4(c), 
    //                                                                                                         Add_GDI_Clip_Mask:00538355(c), 
    //                                                                                                         Add_GDI_Clip_Mask:005383b4(c), 
    //                                                                                                         Add_GDI_Clip_Mask:005383c2(c), 
    //                                                                                                         Add_GDI_Clip_Mask:005383db(c), 
    //                                                                                                         [more]
    //                              spanlist.cpp:424 (6)
    //         004bdb00     PUSH       EBX
    //         004bdb01     PUSH       EBP
    //         004bdb02     PUSH       ESI
    //         004bdb03     MOV        ESI,this
    //         004bdb05     PUSH       EDI
    //                              spanlist.cpp:434 (22)
    //         004bdb06     MOV        EDI,dword ptr [ESP + param_3]
    //         004bdb0a     CMP        EDI,dword ptr [ESI + 0x60]
    //         004bdb0d     JL         LAB_004bde8d
    //         004bdb13     CMP        EDI,dword ptr [ESI + 0x64]
    //         004bdb16     JG         LAB_004bde8d
    //                              spanlist.cpp:445 (26)
    //         004bdb1c     MOV        EBP,dword ptr [ESP + param_2]
    //         004bdb20     MOV        EAX,dword ptr [ESP + param_1]
    //         004bdb24     CMP        EAX,EBP
    //         004bdb26     JLE        LAB_004bdb36
    //         004bdb28     MOV        dword ptr [ESP + param_2],EAX
    //         004bdb2c     MOV        dword ptr [ESP + param_1],EBP
    //         004bdb30     MOV        EAX,EBP
    //         004bdb32     MOV        EBP,dword ptr [ESP + param_2]
    //                               LAB_004bdb36                                                 XREF[1]:     004bdb26(j)  
    //                              spanlist.cpp:447 (22)
    //         004bdb36     MOV        this,dword ptr [ESI + 0x58]
    //         004bdb39     CMP        EBP,this
    //         004bdb3b     JL         LAB_004bde8d
    //         004bdb41     MOV        EDX,dword ptr [ESI + 0x5c]
    //         004bdb44     CMP        EAX,EDX
    //         004bdb46     JG         LAB_004bde8d
    //                              spanlist.cpp:449 (8)
    //         004bdb4c     CMP        EAX,this
    //         004bdb4e     JGE        LAB_004bdb54
    //         004bdb50     MOV        dword ptr [ESP + param_1],this
    //                               LAB_004bdb54                                                 XREF[1]:     004bdb4e(j)  
    //                              spanlist.cpp:450 (10)
    //         004bdb54     CMP        EBP,EDX
    //         004bdb56     JLE        LAB_004bdb5e
    //         004bdb58     MOV        dword ptr [ESP + param_2],EDX
    //         004bdb5c     MOV        EBP,EDX
    //                               LAB_004bdb5e                                                 XREF[1]:     004bdb56(j)  
    //                              spanlist.cpp:454 (13)
    //         004bdb5e     MOV        EAX,dword ptr [ESI + 0x3c]
    //         004bdb61     SHL        EDI,0x2
    //         004bdb64     MOV        EBX,dword ptr [EDI + EAX*0x1]
    //         004bdb67     TEST       EBX,EBX
    //         004bdb69     JNZ        LAB_004bdba7
    //                              spanlist.cpp:460 (7)
    //         004bdb6b     MOV        this,ESI
    //         004bdb6d     CALL       TSpan_Node_List::GetNode                         VSpan_Node * GetNode(TSpan_Node_List * this)
    //                              spanlist.cpp:464 (12)
    //         004bdb72     MOV        this,dword ptr [ESP + param_1]
    //         004bdb76     MOV        dword ptr [EAX + 0x4],EBX
    //         004bdb79     MOV        dword ptr [EAX],EBX
    //         004bdb7b     MOV        dword ptr [EAX + 0x8],this
    //                              spanlist.cpp:465 (3)
    //         004bdb7e     MOV        dword ptr [EAX + 0xc],EBP
    //                              spanlist.cpp:467 (6)
    //         004bdb81     MOV        EDX,dword ptr [ESI + 0x3c]
    //         004bdb84     MOV        dword ptr [EDI + EDX*0x1],EAX
    //                              spanlist.cpp:468 (6)
    //         004bdb87     MOV        EDX,dword ptr [ESI + 0x40]
    //         004bdb8a     MOV        dword ptr [EDX + EDI*0x1],EAX
    //                              spanlist.cpp:469 (6)
    //         004bdb8d     MOV        EAX,dword ptr [ESI + 0x44]
    //         004bdb90     MOV        dword ptr [EAX + EDI*0x1],this
    //                              spanlist.cpp:470 (6)
    //         004bdb93     MOV        this,dword ptr [ESI + 0x48]
    //         004bdb96     MOV        dword ptr [this->VSList.Zone_Ptrs + EDI*0x1],EBP
    //                              spanlist.cpp:472 (7)
    //         004bdb99     MOV        EDX,dword ptr [ESI + 0x4c]
    //         004bdb9c     ADD        EDI,EDX
    //         004bdb9e     INC        dword ptr [EDI]
    //                              spanlist.cpp:821 (7)
    //         004bdba0     POP        EDI
    //         004bdba1     POP        ESI
    //         004bdba2     POP        EBP
    //         004bdba3     POP        EBX
    //         004bdba4     RET        0xc
    //                               LAB_004bdba7                                                 XREF[1]:     004bdb69(j)  
    //                              spanlist.cpp:481 (27)
    //         004bdba7     MOV        this,dword ptr [ESI + 0x44]
    //         004bdbaa     MOV        EAX,dword ptr [ESI + 0x40]
    //         004bdbad     MOV        EBP,dword ptr [EAX + EDI*0x1]
    //         004bdbb0     MOV        EAX,dword ptr [this->VSList.Zone_Ptrs + EDI*0x1]
    //         004bdbb3     LEA        EDX,[this->VSList.Zone_Ptrs + EDI*0x1]
    //         004bdbb6     MOV        this,dword ptr [ESP + param_1]
    //         004bdbba     CMP        this,EAX
    //         004bdbbc     JG         LAB_004bdcc5
    //                              spanlist.cpp:486 (9)
    //         004bdbc2     MOV        EBP,dword ptr [ESP + param_2]
    //         004bdbc6     DEC        EAX
    //         004bdbc7     CMP        EBP,EAX
    //         004bdbc9     JGE        LAB_004bdc02
    //                              spanlist.cpp:488 (7)
    //         004bdbcb     MOV        this,ESI
    //         004bdbcd     CALL       TSpan_Node_List::GetNode                         VSpan_Node * GetNode(TSpan_Node_List * this)
    //                              spanlist.cpp:494 (19)
    //         004bdbd2     MOV        this,dword ptr [ESP + param_1]
    //         004bdbd6     MOV        dword ptr [EAX + 0x4],0x0
    //         004bdbdd     MOV        dword ptr [EAX],EBX
    //         004bdbdf     MOV        dword ptr [EBX + 0x4],EAX
    //         004bdbe2     MOV        dword ptr [EAX + 0x8],this
    //                              spanlist.cpp:495 (3)
    //         004bdbe5     MOV        dword ptr [EAX + 0xc],EBP
    //                              spanlist.cpp:497 (6)
    //         004bdbe8     MOV        EDX,dword ptr [ESI + 0x44]
    //         004bdbeb     MOV        dword ptr [EDX + EDI*0x1],this
    //                              spanlist.cpp:499 (6)
    //         004bdbee     MOV        this,dword ptr [ESI + 0x3c]
    //         004bdbf1     MOV        dword ptr [EDI + this->VSList.Zone_Ptrs*0x1],EAX
    //                              spanlist.cpp:500 (7)
    //         004bdbf4     MOV        EDX,dword ptr [ESI + 0x4c]
    //         004bdbf7     ADD        EDI,EDX
    //         004bdbf9     INC        dword ptr [EDI]
    //                              spanlist.cpp:821 (7)
    //         004bdbfb     POP        EDI
    //         004bdbfc     POP        ESI
    //         004bdbfd     POP        EBP
    //         004bdbfe     POP        EBX
    //         004bdbff     RET        0xc
    //                               LAB_004bdc02                                                 XREF[1]:     004bdbc9(j)  
    //                              spanlist.cpp:507 (8)
    //         004bdc02     MOV        EAX,dword ptr [ESI + 0x48]
    //         004bdc05     CMP        EBP,dword ptr [EAX + EDI*0x1]
    //         004bdc08     JL         LAB_004bdc59
    //                              spanlist.cpp:509 (29)
    //         004bdc0a     MOV        this,dword ptr [ESI + 0x4c]
    //         004bdc0d     MOV        EDX,dword ptr [EBX]
    //         004bdc0f     ADD        this,EDI
    //         004bdc11     PUSH       0x0
    //         004bdc13     MOV        dword ptr [ESP + param_2],this
    //         004bdc17     PUSH       EDX
    //         004bdc18     MOV        this,ESI
    //         004bdc1a     CALL       TSpan_Node_List::FreeThread                      int FreeThread(TSpan_Node_List * this, VSpan_
    //         004bdc1f     MOV        this,dword ptr [ESP + param_2]
    //         004bdc23     MOV        EDX,dword ptr [this->VSList.Zone_Ptrs]
    //         004bdc25     SUB        EDX,EAX
    //                              spanlist.cpp:513 (22)
    //         004bdc27     MOV        EAX,dword ptr [ESP + param_1]
    //         004bdc2b     MOV        dword ptr [this->VSList.Zone_Ptrs],EDX
    //         004bdc2d     MOV        dword ptr [EBX + 0x4],0x0
    //         004bdc34     MOV        dword ptr [EBX],0x0
    //         004bdc3a     MOV        dword ptr [EBX + 0x8],EAX
    //                              spanlist.cpp:514 (3)
    //         004bdc3d     MOV        dword ptr [EBX + 0xc],EBP
    //                              spanlist.cpp:516 (6)
    //         004bdc40     MOV        this,dword ptr [ESI + 0x40]
    //         004bdc43     MOV        dword ptr [this->VSList.Zone_Ptrs + EDI*0x1],EBX
    //                              spanlist.cpp:517 (6)
    //         004bdc46     MOV        EDX,dword ptr [ESI + 0x48]
    //         004bdc49     MOV        dword ptr [EDX + EDI*0x1],EBP
    //                              spanlist.cpp:518 (6)
    //         004bdc4c     MOV        this,dword ptr [ESI + 0x44]
    //         004bdc4f     MOV        dword ptr [this->VSList.Zone_Ptrs + EDI*0x1],EAX
    //                              spanlist.cpp:821 (7)
    //         004bdc52     POP        EDI
    //         004bdc53     POP        ESI
    //         004bdc54     POP        EBP
    //         004bdc55     POP        EBX
    //         004bdc56     RET        0xc
    //                               LAB_004bdc59                                                 XREF[1]:     004bdc08(j)  
    //                              spanlist.cpp:528 (2)
    //         004bdc59     MOV        dword ptr [EDX],this
    //                              spanlist.cpp:530 (20)
    //         004bdc5b     MOV        EDX,dword ptr [EBX + 0x8]
    //         004bdc5e     INC        EBP
    //         004bdc5f     MOV        EAX,EBX
    //         004bdc61     CMP        EBP,EDX
    //         004bdc63     JL         LAB_004bde8d
    //         004bdc69     JMP        LAB_004bdc6f
    //                               LAB_004bdc6b                                                 XREF[1]:     004bdca5(j)  
    //         004bdc6b     MOV        this,dword ptr [ESP + param_1]
    //                               LAB_004bdc6f                                                 XREF[1]:     004bdc69(j)  
    //                              spanlist.cpp:534 (9)
    //         004bdc6f     MOV        EDX,dword ptr [ESP + param_2]
    //         004bdc73     CMP        EDX,dword ptr [EBX + 0xc]
    //         004bdc76     JLE        LAB_004bdcae
    //                              spanlist.cpp:552 (2)
    //         004bdc78     MOV        EBX,dword ptr [EBX]
    //                              spanlist.cpp:554 (5)
    //         004bdc7a     CMP        EBP,dword ptr [EBX + 0x8]
    //         004bdc7d     JL         LAB_004bdcb8
    //                              spanlist.cpp:573 (3)
    //         004bdc7f     MOV        EDX,dword ptr [ESI + 0x3c]
    //                              spanlist.cpp:575 (18)
    //         004bdc82     PUSH       EAX
    //         004bdc83     MOV        this,ESI
    //         004bdc85     MOV        dword ptr [EDI + EDX*0x1],EBX
    //         004bdc88     MOV        dword ptr [EBX + 0x4],0x0
    //         004bdc8f     CALL       TSpan_Node_List::FreeNode                        void FreeNode(TSpan_Node_List * this, VSpan_N
    //                              spanlist.cpp:576 (15)
    //         004bdc94     MOV        EAX,dword ptr [ESI + 0x4c]
    //         004bdc97     ADD        EAX,EDI
    //         004bdc99     MOV        EDX,dword ptr [EAX]
    //         004bdc9b     DEC        EDX
    //         004bdc9c     MOV        dword ptr [EAX],EDX
    //         004bdc9e     MOV        this,dword ptr [EBX + 0x8]
    //         004bdca1     CMP        EBP,this
    //                              spanlist.cpp:577 (4)
    //         004bdca3     MOV        EAX,EBX
    //         004bdca5     JGE        LAB_004bdc6b
    //                              spanlist.cpp:821 (7)
    //         004bdca7     POP        EDI
    //         004bdca8     POP        ESI
    //         004bdca9     POP        EBP
    //         004bdcaa     POP        EBX
    //         004bdcab     RET        0xc
    //                               LAB_004bdcae                                                 XREF[1]:     004bdc76(j)  
    //                              spanlist.cpp:536 (3)
    //         004bdcae     MOV        dword ptr [EAX + 0x8],this
    //                              spanlist.cpp:821 (7)
    //         004bdcb1     POP        EDI
    //         004bdcb2     POP        ESI
    //         004bdcb3     POP        EBP
    //         004bdcb4     POP        EBX
    //         004bdcb5     RET        0xc
    //                               LAB_004bdcb8                                                 XREF[1]:     004bdc7d(j)  
    //                              spanlist.cpp:556 (3)
    //         004bdcb8     MOV        dword ptr [EAX + 0x8],this
    //                              spanlist.cpp:557 (3)
    //         004bdcbb     MOV        dword ptr [EAX + 0xc],EDX
    //                              spanlist.cpp:821 (7)
    //         004bdcbe     POP        EDI
    //         004bdcbf     POP        ESI
    //         004bdcc0     POP        EBP
    //         004bdcc1     POP        EBX
    //         004bdcc2     RET        0xc
    //                               LAB_004bdcc5                                                 XREF[1]:     004bdbbc(j)  
    //                              spanlist.cpp:593 (17)
    //         004bdcc5     MOV        EDX,dword ptr [ESI + 0x48]
    //         004bdcc8     ADD        EDX,EDI
    //         004bdcca     MOV        EAX,dword ptr [EDX]
    //         004bdccc     CMP        dword ptr [ESP + param_2],EAX
    //         004bdcd0     JL         LAB_004bdd8f
    //                              spanlist.cpp:598 (5)
    //         004bdcd6     INC        EAX
    //         004bdcd7     CMP        this,EAX
    //         004bdcd9     JLE        LAB_004bdd16
    //                              spanlist.cpp:600 (7)
    //         004bdcdb     MOV        this,ESI
    //         004bdcdd     CALL       TSpan_Node_List::GetNode                         VSpan_Node * GetNode(TSpan_Node_List * this)
    //                              spanlist.cpp:606 (19)
    //         004bdce2     MOV        this,dword ptr [ESP + param_1]
    //         004bdce6     MOV        dword ptr [EAX + 0x4],EBP
    //         004bdce9     MOV        dword ptr [EAX],0x0
    //         004bdcef     MOV        dword ptr [EBP],EAX
    //         004bdcf2     MOV        dword ptr [EAX + 0x8],this
    //                              spanlist.cpp:607 (7)
    //         004bdcf5     MOV        this,dword ptr [ESP + param_2]
    //         004bdcf9     MOV        dword ptr [EAX + 0xc],this
    //                              spanlist.cpp:609 (6)
    //         004bdcfc     MOV        EDX,dword ptr [ESI + 0x48]
    //         004bdcff     MOV        dword ptr [EDX + EDI*0x1],this
    //                              spanlist.cpp:611 (6)
    //         004bdd02     MOV        this,dword ptr [ESI + 0x40]
    //         004bdd05     MOV        dword ptr [this->VSList.Zone_Ptrs + EDI*0x1],EAX
    //                              spanlist.cpp:612 (7)
    //         004bdd08     MOV        EDX,dword ptr [ESI + 0x4c]
    //         004bdd0b     ADD        EDI,EDX
    //         004bdd0d     INC        dword ptr [EDI]
    //                              spanlist.cpp:821 (7)
    //         004bdd0f     POP        EDI
    //         004bdd10     POP        ESI
    //         004bdd11     POP        EBP
    //         004bdd12     POP        EBX
    //         004bdd13     RET        0xc
    //                               LAB_004bdd16                                                 XREF[1]:     004bdcd9(j)  
    //                              spanlist.cpp:622 (8)
    //         004bdd16     MOV        EBX,dword ptr [ESP + param_2]
    //         004bdd1a     MOV        EAX,EBP
    //         004bdd1c     MOV        dword ptr [EDX],EBX
    //                              spanlist.cpp:624 (20)
    //         004bdd1e     MOV        EDX,dword ptr [EBP + 0xc]
    //         004bdd21     LEA        EBX,[this->VSList.Zone_Ptrs + -0x1]
    //         004bdd24     CMP        EBX,EDX
    //         004bdd26     JG         LAB_004bde8d
    //         004bdd2c     JMP        LAB_004bdd32
    //                               LAB_004bdd2e                                                 XREF[1]:     004bdd67(j)  
    //         004bdd2e     MOV        this,dword ptr [ESP + param_1]
    //                               LAB_004bdd32                                                 XREF[1]:     004bdd2c(j)  
    //                              spanlist.cpp:628 (5)
    //         004bdd32     CMP        this,dword ptr [EBP + 0x8]
    //         004bdd35     JGE        LAB_004bdd70
    //                              spanlist.cpp:647 (3)
    //         004bdd37     MOV        EBP,dword ptr [EBP + 0x4]
    //                              spanlist.cpp:649 (5)
    //         004bdd3a     CMP        EBX,dword ptr [EBP + 0xc]
    //         004bdd3d     JG         LAB_004bdd7e
    //                              spanlist.cpp:668 (3)
    //         004bdd3f     MOV        this,dword ptr [ESI + 0x40]
    //                              spanlist.cpp:670 (18)
    //         004bdd42     PUSH       EAX
    //         004bdd43     MOV        dword ptr [this->VSList.Zone_Ptrs + EDI*0x1],EBP
    //         004bdd46     MOV        this,ESI
    //         004bdd48     MOV        dword ptr [EBP],0x0
    //         004bdd4f     CALL       TSpan_Node_List::FreeNode                        void FreeNode(TSpan_Node_List * this, VSpan_N
    //                              spanlist.cpp:671 (17)
    //         004bdd54     MOV        EDX,dword ptr [ESI + 0x4c]
    //         004bdd57     LEA        EAX,[EDX + EDI*0x1]
    //         004bdd5a     MOV        EDX,dword ptr [EDX + EDI*0x1]
    //         004bdd5d     DEC        EDX
    //         004bdd5e     MOV        dword ptr [EAX],EDX
    //         004bdd60     MOV        this,dword ptr [EBP + 0xc]
    //         004bdd63     CMP        EBX,this
    //                              spanlist.cpp:672 (4)
    //         004bdd65     MOV        EAX,EBP
    //         004bdd67     JLE        LAB_004bdd2e
    //                              spanlist.cpp:821 (7)
    //         004bdd69     POP        EDI
    //         004bdd6a     POP        ESI
    //         004bdd6b     POP        EBP
    //         004bdd6c     POP        EBX
    //         004bdd6d     RET        0xc
    //                               LAB_004bdd70                                                 XREF[1]:     004bdd35(j)  
    //                              spanlist.cpp:631 (7)
    //         004bdd70     MOV        this,dword ptr [ESP + param_2]
    //         004bdd74     MOV        dword ptr [EAX + 0xc],this
    //                              spanlist.cpp:821 (7)
    //         004bdd77     POP        EDI
    //         004bdd78     POP        ESI
    //         004bdd79     POP        EBP
    //         004bdd7a     POP        EBX
    //         004bdd7b     RET        0xc
    //                               LAB_004bdd7e                                                 XREF[1]:     004bdd3d(j)  
    //                              spanlist.cpp:652 (10)
    //         004bdd7e     MOV        EDX,dword ptr [ESP + param_2]
    //         004bdd82     MOV        dword ptr [EAX + 0x8],this
    //         004bdd85     MOV        dword ptr [EAX + 0xc],EDX
    //                              spanlist.cpp:821 (7)
    //         004bdd88     POP        EDI
    //         004bdd89     POP        ESI
    //         004bdd8a     POP        EBP
    //         004bdd8b     POP        EBX
    //         004bdd8c     RET        0xc
    //                               LAB_004bdd8f                                                 XREF[1]:     004bdcd0(j)  
    //                              spanlist.cpp:694 (17)
    //         004bdd8f     MOV        EDX,dword ptr [EBX + 0xc]
    //         004bdd92     LEA        EAX,[this->VSList.Zone_Ptrs + -0x1]
    //         004bdd95     CMP        EDX,EAX
    //         004bdd97     JGE        LAB_004bdda0
    //                               LAB_004bdd99                                                 XREF[1]:     004bdd9e(j)  
    //         004bdd99     MOV        EBX,dword ptr [EBX]
    //         004bdd9b     CMP        dword ptr [EBX + 0xc],EAX
    //         004bdd9e     JL         LAB_004bdd99
    //                               LAB_004bdda0                                                 XREF[1]:     004bdd97(j)  
    //                              spanlist.cpp:706 (18)
    //         004bdda0     MOV        EDX,dword ptr [ESP + param_2]
    //         004bdda4     MOV        EBP,dword ptr [EBX + 0x8]
    //         004bdda7     LEA        EAX,[EDX + 0x1]
    //         004bddaa     CMP        EBP,EAX
    //         004bddac     MOV        dword ptr [ESP + param_3],EAX
    //         004bddb0     JLE        LAB_004bdde5
    //                              spanlist.cpp:708 (7)
    //         004bddb2     MOV        this,ESI
    //         004bddb4     CALL       TSpan_Node_List::GetNode                         VSpan_Node * GetNode(TSpan_Node_List * this)
    //                              spanlist.cpp:710 (3)
    //         004bddb9     MOV        this,dword ptr [EBX + 0x4]
    //                              spanlist.cpp:711 (5)
    //         004bddbc     MOV        dword ptr [EAX],EBX
    //         004bddbe     MOV        dword ptr [EAX + 0x4],this
    //                              spanlist.cpp:715 (12)
    //         004bddc1     MOV        this,dword ptr [ESP + param_1]
    //         004bddc5     MOV        dword ptr [EBX + 0x4],EAX
    //         004bddc8     MOV        EDX,dword ptr [EAX + 0x4]
    //         004bddcb     MOV        dword ptr [EDX],EAX
    //                              spanlist.cpp:716 (10)
    //         004bddcd     MOV        EDX,dword ptr [ESP + param_2]
    //         004bddd1     MOV        dword ptr [EAX + 0x8],this
    //         004bddd4     MOV        dword ptr [EAX + 0xc],EDX
    //                              spanlist.cpp:718 (7)
    //         004bddd7     MOV        EAX,dword ptr [ESI + 0x4c]
    //         004bddda     ADD        EAX,EDI
    //         004bdddc     INC        dword ptr [EAX]
    //                              spanlist.cpp:821 (7)
    //         004bddde     POP        EDI
    //         004bdddf     POP        ESI
    //         004bdde0     POP        EBP
    //         004bdde1     POP        EBX
    //         004bdde2     RET        0xc
    //                               LAB_004bdde5                                                 XREF[1]:     004bddb0(j)  
    //                              spanlist.cpp:735 (7)
    //         004bdde5     CMP        this,EBP
    //         004bdde7     JGE        LAB_004bddec
    //         004bdde9     MOV        dword ptr [EBX + 0x8],this
    //                               LAB_004bddec                                                 XREF[1]:     004bdde7(j)  
    //                              spanlist.cpp:740 (9)
    //         004bddec     CMP        dword ptr [EBX + 0xc],EDX
    //         004bddef     JGE        LAB_004bde8d
    //                              spanlist.cpp:753 (2)
    //         004bddf5     MOV        EBP,dword ptr [EBX]
    //                              spanlist.cpp:755 (18)
    //         004bddf7     TEST       EBP,EBP
    //         004bddf9     JZ         LAB_004bde8d
    //         004bddff     JMP        LAB_004bde09
    //                               LAB_004bde01                                                 XREF[1]:     004bde45(j)  
    //         004bde01     MOV        EDX,dword ptr [ESP + param_2]
    //         004bde05     MOV        EAX,dword ptr [ESP + param_3]
    //                               LAB_004bde09                                                 XREF[1]:     004bddff(j)  
    //                              spanlist.cpp:759 (5)
    //         004bde09     CMP        EAX,dword ptr [EBP + 0x8]
    //         004bde0c     JL         LAB_004bde4e
    //                              spanlist.cpp:776 (5)
    //         004bde0e     CMP        EDX,dword ptr [EBP + 0xc]
    //         004bde11     JLE        LAB_004bde58
    //                              spanlist.cpp:806 (12)
    //         004bde13     MOV        EAX,dword ptr [EBP + 0x4]
    //         004bde16     TEST       EAX,EAX
    //         004bde18     JZ         LAB_004bde1f
    //         004bde1a     MOV        this,dword ptr [EBP]
    //         004bde1d     MOV        dword ptr [EAX],this
    //                               LAB_004bde1f                                                 XREF[1]:     004bde18(j)  
    //                              spanlist.cpp:807 (13)
    //         004bde1f     MOV        EAX,dword ptr [EBP]
    //         004bde22     TEST       EAX,EAX
    //         004bde24     JZ         LAB_004bde2c
    //         004bde26     MOV        EDX,dword ptr [EBP + 0x4]
    //         004bde29     MOV        dword ptr [EAX + 0x4],EDX
    //                               LAB_004bde2c                                                 XREF[1]:     004bde24(j)  
    //                              spanlist.cpp:809 (2)
    //         004bde2c     MOV        EAX,EBP
    //                              spanlist.cpp:810 (3)
    //         004bde2e     MOV        EBP,dword ptr [EBP]
    //                              spanlist.cpp:811 (8)
    //         004bde31     PUSH       EAX
    //         004bde32     MOV        this,ESI
    //         004bde34     CALL       TSpan_Node_List::FreeNode                        void FreeNode(TSpan_Node_List * this, VSpan_N
    //                              spanlist.cpp:812 (14)
    //         004bde39     MOV        EAX,dword ptr [ESI + 0x4c]
    //         004bde3c     ADD        EAX,EDI
    //         004bde3e     MOV        this,dword ptr [EAX]
    //         004bde40     DEC        this
    //         004bde41     TEST       EBP,EBP
    //         004bde43     MOV        dword ptr [EAX],this
    //         004bde45     JNZ        LAB_004bde01
    //                              spanlist.cpp:821 (7)
    //         004bde47     POP        EDI
    //         004bde48     POP        ESI
    //         004bde49     POP        EBP
    //         004bde4a     POP        EBX
    //         004bde4b     RET        0xc
    //                               LAB_004bde4e                                                 XREF[1]:     004bde0c(j)  
    //                              spanlist.cpp:761 (3)
    //         004bde4e     MOV        dword ptr [EBX + 0xc],EDX
    //                              spanlist.cpp:821 (7)
    //         004bde51     POP        EDI
    //         004bde52     POP        ESI
    //         004bde53     POP        EBP
    //         004bde54     POP        EBX
    //         004bde55     RET        0xc
    //                               LAB_004bde58                                                 XREF[1]:     004bde11(j)  
    //                              spanlist.cpp:778 (3)
    //         004bde58     MOV        this,dword ptr [EBP + 0xc]
    //                              spanlist.cpp:780 (16)
    //         004bde5b     PUSH       EBP
    //         004bde5c     MOV        dword ptr [EBX + 0xc],this
    //         004bde5f     MOV        EDX,dword ptr [EBP]
    //         004bde62     MOV        this,ESI
    //         004bde64     MOV        dword ptr [EBX],EDX
    //         004bde66     CALL       TSpan_Node_List::FreeNode                        void FreeNode(TSpan_Node_List * this, VSpan_N
    //                              spanlist.cpp:781 (10)
    //         004bde6b     MOV        EAX,dword ptr [ESI + 0x4c]
    //         004bde6e     ADD        EAX,EDI
    //         004bde70     MOV        this,dword ptr [EAX]
    //         004bde72     DEC        this
    //         004bde73     MOV        dword ptr [EAX],this
    //                              spanlist.cpp:782 (6)
    //         004bde75     MOV        EAX,dword ptr [EBX]
    //         004bde77     TEST       EAX,EAX
    //         004bde79     JZ         LAB_004bde87
    //                              spanlist.cpp:784 (5)
    //         004bde7b     MOV        this,EAX
    //         004bde7d     MOV        dword ptr [ECX + this+0x4],EBX
    //                              spanlist.cpp:821 (7)
    //         004bde80     POP        EDI
    //         004bde81     POP        ESI
    //         004bde82     POP        EBP
    //         004bde83     POP        EBX
    //         004bde84     RET        0xc
    //                               LAB_004bde87                                                 XREF[1]:     004bde79(j)  
    //                              spanlist.cpp:788 (6)
    //         004bde87     MOV        EDX,dword ptr [ESI + 0x40]
    //         004bde8a     MOV        dword ptr [EDX + EDI*0x1],EBX
    //                               LAB_004bde8d                                                 XREF[8]:     004bdb0d(j), 004bdb16(j), 
    //                                                                                                         004bdb3b(j), 004bdb46(j), 
    //                                                                                                         004bdc63(j), 004bdd26(j), 
    //                                                                                                         004bddef(j), 004bddf9(j)  
    //                              spanlist.cpp:821 (7)
    //         004bde8d     POP        EDI
    //         004bde8e     POP        ESI
    //         004bde8f     POP        EBP
    //         004bde90     POP        EBX
    //         004bde91     RET        0xc
}

// Offset: 0x004BDEA0
void AddShape(TSpan_List_Manager* this_, TShape* param_2, int param_3, int param_4, int param_5, int param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TSpan_List_Manager::AddShape(class TShape *,int,int,int,int)                  *
    //                              *********************************************************************************************************
    //                              void __thiscall AddShape(TSpan_List_Manager * this, TShape * param_1
    //              void              <VOID>         <RETURN>
    //              TSpan_List_Man    ECX:4 (auto)   this
    //              TShape *          Stack[0x4]:4   param_1                   XREF[4]:     004bdea6(R), 004bdee0(W), 004bdf16(R), 004bdf6b(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004bdebd(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[3]:     004bdec7(R), 004bdf26(R), 004bdf7b(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[3]:     004bdee4(R), 004bdf32(R), 004bdf87(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     004bded9(R)  
    //                               ?AddShape@TSpan_List_Manager@@QAEXPAVTShape@@HHHH@Z
    //                               TSpan_List_Manager::AddShape
    //                              spanlist.cpp:827 (6)
    //         004bdea0     PUSH       EBX
    //         004bdea1     PUSH       EBP
    //         004bdea2     PUSH       ESI
    //         004bdea3     PUSH       EDI
    //         004bdea4     MOV        EDI,this
    //                              spanlist.cpp:832 (12)
    //         004bdea6     MOV        this,dword ptr [ESP + param_1]
    //         004bdeaa     TEST       this,this
    //         004bdeac     JZ         LAB_004bdf97
    //                              spanlist.cpp:834 (11)
    //         004bdeb2     MOV        EAX,dword ptr [ECX + this+0x18]
    //         004bdeb5     TEST       EAX,EAX
    //         004bdeb7     JZ         LAB_004bdf97
    //                              spanlist.cpp:843 (10)
    //         004bdebd     MOV        EDX,dword ptr [ESP + param_2]
    //         004bdec1     MOV        EBP,dword ptr [ECX + this+0x1c]
    //         004bdec4     SHL        EDX,0x5
    //                              spanlist.cpp:847 (18)
    //         004bdec7     MOV        this,dword ptr [ESP + param_3]
    //         004bdecb     ADD        EBP,EDX
    //         004bdecd     MOV        ESI,dword ptr [EBP + 0x4]
    //         004bded0     ADD        ESI,EAX
    //         004bded2     MOV        EAX,dword ptr [EBP + 0x10]
    //         004bded5     LEA        EDX,[EAX + this->VSList.Zone_Ptrs*0x1 + -0x1]
    //                              spanlist.cpp:850 (4)
    //         004bded9     MOV        EAX,dword ptr [ESP + param_5]
    //                              spanlist.cpp:852 (29)
    //         004bdedd     MOV        this,dword ptr [EBP + 0x14]
    //         004bdee0     MOV        dword ptr [ESP + param_1],EDX
    //         004bdee4     MOV        EDX,dword ptr [ESP + param_4]
    //         004bdee8     TEST       EAX,EAX
    //         004bdeea     MOV        EBX,EDX
    //         004bdeec     MOV        EAX,EDX
    //         004bdeee     JNZ        LAB_004bdf49
    //         004bdef0     ADD        EAX,this
    //         004bdef2     CMP        EDX,EAX
    //         004bdef4     JGE        LAB_004bdf97
    //                               LAB_004bdefa                                                 XREF[1]:     004bdf40(j)  
    //                              spanlist.cpp:854 (3)
    //         004bdefa     MOV        AX,word ptr [ESI]
    //                              spanlist.cpp:855 (10)
    //         004bdefd     MOV        this,word ptr [ESI + 0x2]
    //         004bdf01     ADD        ESI,0x2
    //         004bdf04     ADD        ESI,0x2
    //                              spanlist.cpp:857 (10)
    //         004bdf07     CMP        EBX,dword ptr [EDI + 0x60]
    //         004bdf0a     JL         LAB_004bdf36
    //         004bdf0c     CMP        EBX,dword ptr [EDI + 0x64]
    //         004bdf0f     JG         LAB_004bdf36
    //                              spanlist.cpp:859 (9)
    //         004bdf11     TEST       AH,0x80
    //         004bdf14     JNZ        LAB_004bdf36
    //         004bdf16     MOV        EDX,dword ptr [ESP + param_1]
    //                              spanlist.cpp:861 (40)
    //         004bdf1a     PUSH       EBX
    //         004bdf1b     MOVSX      this,this
    //         004bdf1e     SUB        EDX,this
    //         004bdf20     MOV        this,EDI
    //         004bdf22     MOVSX      EAX,AX
    //         004bdf25     PUSH       EDX
    //         004bdf26     MOV        EDX,dword ptr [ESP + param_3]
    //         004bdf2a     ADD        EAX,EDX
    //         004bdf2c     PUSH       EAX
    //         004bdf2d     CALL       TSpan_List_Manager::AddSpan                      void AddSpan(TSpan_List_Manager * this, int p
    //         004bdf32     MOV        EDX,dword ptr [ESP + param_4]
    //                               LAB_004bdf36                                                 XREF[3]:     004bdf0a(j), 004bdf0f(j), 
    //                                                                                                         004bdf14(j)  
    //         004bdf36     MOV        EAX,dword ptr [EBP + 0x14]
    //         004bdf39     MOV        this,EDX
    //         004bdf3b     INC        EBX
    //         004bdf3c     ADD        this,EAX
    //         004bdf3e     CMP        EBX,this
    //         004bdf40     JL         LAB_004bdefa
    //                              spanlist.cpp:893 (7)
    //         004bdf42     POP        EDI
    //         004bdf43     POP        ESI
    //         004bdf44     POP        EBP
    //         004bdf45     POP        EBX
    //         004bdf46     RET        0x14
    //                               LAB_004bdf49                                                 XREF[1]:     004bdeee(j)  
    //                              spanlist.cpp:873 (6)
    //         004bdf49     ADD        EAX,this
    //         004bdf4b     CMP        EDX,EAX
    //         004bdf4d     JGE        LAB_004bdf97
    //                               LAB_004bdf4f                                                 XREF[1]:     004bdf95(j)  
    //                              spanlist.cpp:875 (3)
    //         004bdf4f     MOV        this,word ptr [ESI]
    //                              spanlist.cpp:876 (10)
    //         004bdf52     MOV        AX,word ptr [ESI + 0x2]
    //         004bdf56     ADD        ESI,0x2
    //         004bdf59     ADD        ESI,0x2
    //                              spanlist.cpp:878 (10)
    //         004bdf5c     CMP        EBX,dword ptr [EDI + 0x60]
    //         004bdf5f     JL         LAB_004bdf8b
    //         004bdf61     CMP        EBX,dword ptr [EDI + 0x64]
    //         004bdf64     JG         LAB_004bdf8b
    //                              spanlist.cpp:880 (9)
    //         004bdf66     TEST       AH,0x80
    //         004bdf69     JNZ        LAB_004bdf8b
    //         004bdf6b     MOV        EDX,dword ptr [ESP + param_1]
    //                              spanlist.cpp:882 (40)
    //         004bdf6f     PUSH       EBX
    //         004bdf70     MOVSX      this,this
    //         004bdf73     SUB        EDX,this
    //         004bdf75     MOV        this,EDI
    //         004bdf77     MOVSX      EAX,AX
    //         004bdf7a     PUSH       EDX
    //         004bdf7b     MOV        EDX,dword ptr [ESP + param_3]
    //         004bdf7f     ADD        EAX,EDX
    //         004bdf81     PUSH       EAX
    //         004bdf82     CALL       TSpan_List_Manager::AddSpan                      void AddSpan(TSpan_List_Manager * this, int p
    //         004bdf87     MOV        EDX,dword ptr [ESP + param_4]
    //                               LAB_004bdf8b                                                 XREF[3]:     004bdf5f(j), 004bdf64(j), 
    //                                                                                                         004bdf69(j)  
    //         004bdf8b     MOV        EAX,dword ptr [EBP + 0x14]
    //         004bdf8e     MOV        this,EDX
    //         004bdf90     INC        EBX
    //         004bdf91     ADD        this,EAX
    //         004bdf93     CMP        EBX,this
    //         004bdf95     JL         LAB_004bdf4f
    //                               LAB_004bdf97                                                 XREF[4]:     004bdeac(j), 004bdeb7(j), 
    //                                                                                                         004bdef4(j), 004bdf4d(j)  
    //                              spanlist.cpp:893 (7)
    //         004bdf97     POP        EDI
    //         004bdf98     POP        ESI
    //         004bdf99     POP        EBP
    //         004bdf9a     POP        EBX
    //         004bdf9b     RET        0x14
}

// Offset: 0x004BDFA0
void AddShape_Align(TSpan_List_Manager* this_, uchar* param_2, Shape_Info* param_3, int param_4, int param_5, int param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TSpan_List_Manager::AddShape_Align(unsigned char *,struct Shape_Info *,int... *
    //                              *********************************************************************************************************
    //                              void __thiscall AddShape_Align(TSpan_List_Manager * this, uchar * pa
    //              void              <VOID>         <RETURN>
    //              TSpan_List_Man    ECX:4 (auto)   this
    //              uchar *           Stack[0x4]:4   param_1                   XREF[4]:     004bdfb5(R), 004bdfce(W), 004be001(R), 004be059(R)  
    //              Shape_Info *      Stack[0x8]:4   param_2                   XREF[3]:     004bdfa0(R), 004be01e(R), 004be076(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     004bdfbc(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[3]:     004bdfc0(R), 004be022(R), 004be07a(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     004bdfca(R)  
    //                               ?AddShape_Align@TSpan_List_Manager@@QAEXPAEPAUShape_Info@@H  XREF[2]:     view_function_terrain:00537db5(c), 
    //                               TSpan_List_Manager::AddShape_Align                                        view_function_terrain:00537e89(c)  
    //                              spanlist.cpp:900 (18)
    //         004bdfa0     MOV        EDX,dword ptr [ESP + param_2]
    //         004bdfa4     PUSH       EBX
    //         004bdfa5     PUSH       EBP
    //         004bdfa6     PUSH       ESI
    //         004bdfa7     PUSH       EDI
    //         004bdfa8     MOV        EDI,this
    //         004bdfaa     TEST       EDX,EDX
    //         004bdfac     JZ         LAB_004be088
    //                              spanlist.cpp:907 (7)
    //         004bdfb2     MOV        ESI,dword ptr [EDX + 0x4]
    //         004bdfb5     MOV        this,dword ptr [ESP + param_1]
    //                              spanlist.cpp:909 (7)
    //         004bdfb9     MOV        EAX,dword ptr [EDX + 0x10]
    //         004bdfbc     MOV        EBP,dword ptr [ESP + param_3]
    //                              spanlist.cpp:914 (37)
    //         004bdfc0     MOV        EBX,dword ptr [ESP + param_4]
    //         004bdfc4     ADD        ESI,this
    //         004bdfc6     LEA        this,[EAX + EBP*0x1 + -0x1]
    //         004bdfca     MOV        EAX,dword ptr [ESP + param_5]
    //         004bdfce     MOV        dword ptr [ESP + param_1],this
    //         004bdfd2     MOV        this,dword ptr [EDX + 0x14]
    //         004bdfd5     TEST       EAX,EAX
    //         004bdfd7     MOV        EAX,EBX
    //         004bdfd9     JNZ        LAB_004be037
    //         004bdfdb     ADD        EAX,this
    //         004bdfdd     CMP        EBX,EAX
    //         004bdfdf     JGE        LAB_004be088
    //                               LAB_004bdfe5                                                 XREF[1]:     004be02e(j)  
    //                              spanlist.cpp:916 (3)
    //         004bdfe5     MOV        AX,word ptr [ESI]
    //                              spanlist.cpp:917 (10)
    //         004bdfe8     MOV        this,word ptr [ESI + 0x2]
    //         004bdfec     ADD        ESI,0x2
    //         004bdfef     ADD        ESI,0x2
    //                              spanlist.cpp:919 (10)
    //         004bdff2     CMP        EBX,dword ptr [EDI + 0x60]
    //         004bdff5     JL         LAB_004be022
    //         004bdff7     CMP        EBX,dword ptr [EDI + 0x64]
    //         004bdffa     JG         LAB_004be022
    //                              spanlist.cpp:921 (9)
    //         004bdffc     TEST       AH,0x80
    //         004bdfff     JNZ        LAB_004be022
    //         004be001     MOV        EDX,dword ptr [ESP + param_1]
    //                              spanlist.cpp:923 (43)
    //         004be005     PUSH       EBX
    //         004be006     MOVSX      this,this
    //         004be009     MOVSX      EAX,AX
    //         004be00c     SUB        EDX,this
    //         004be00e     ADD        EAX,EBP
    //         004be010     OR         EDX,0x3
    //         004be013     AND        AL,0xfc
    //         004be015     PUSH       EDX
    //         004be016     PUSH       EAX
    //         004be017     MOV        this,EDI
    //         004be019     CALL       TSpan_List_Manager::AddSpan                      void AddSpan(TSpan_List_Manager * this, int p
    //         004be01e     MOV        EDX,dword ptr [ESP + param_2]
    //                               LAB_004be022                                                 XREF[3]:     004bdff5(j), 004bdffa(j), 
    //                                                                                                         004bdfff(j)  
    //         004be022     MOV        this,dword ptr [ESP + param_4]
    //         004be026     MOV        EAX,dword ptr [EDX + 0x14]
    //         004be029     INC        EBX
    //         004be02a     ADD        this,EAX
    //         004be02c     CMP        EBX,this
    //         004be02e     JL         LAB_004bdfe5
    //                              spanlist.cpp:953 (7)
    //         004be030     POP        EDI
    //         004be031     POP        ESI
    //         004be032     POP        EBP
    //         004be033     POP        EBX
    //         004be034     RET        0x14
    //                               LAB_004be037                                                 XREF[1]:     004bdfd9(j)  
    //                              spanlist.cpp:934 (6)
    //         004be037     ADD        EAX,this
    //         004be039     CMP        EBX,EAX
    //         004be03b     JGE        LAB_004be088
    //                               LAB_004be03d                                                 XREF[1]:     004be086(j)  
    //                              spanlist.cpp:936 (3)
    //         004be03d     MOV        this,word ptr [ESI]
    //                              spanlist.cpp:937 (10)
    //         004be040     MOV        AX,word ptr [ESI + 0x2]
    //         004be044     ADD        ESI,0x2
    //         004be047     ADD        ESI,0x2
    //                              spanlist.cpp:939 (10)
    //         004be04a     CMP        EBX,dword ptr [EDI + 0x60]
    //         004be04d     JL         LAB_004be07a
    //         004be04f     CMP        EBX,dword ptr [EDI + 0x64]
    //         004be052     JG         LAB_004be07a
    //                              spanlist.cpp:941 (9)
    //         004be054     TEST       AH,0x80
    //         004be057     JNZ        LAB_004be07a
    //         004be059     MOV        EDX,dword ptr [ESP + param_1]
    //                              spanlist.cpp:943 (43)
    //         004be05d     PUSH       EBX
    //         004be05e     MOVSX      this,this
    //         004be061     MOVSX      EAX,AX
    //         004be064     SUB        EDX,this
    //         004be066     ADD        EAX,EBP
    //         004be068     OR         EDX,0x3
    //         004be06b     AND        AL,0xfc
    //         004be06d     PUSH       EDX
    //         004be06e     PUSH       EAX
    //         004be06f     MOV        this,EDI
    //         004be071     CALL       TSpan_List_Manager::AddSpan                      void AddSpan(TSpan_List_Manager * this, int p
    //         004be076     MOV        EDX,dword ptr [ESP + param_2]
    //                               LAB_004be07a                                                 XREF[3]:     004be04d(j), 004be052(j), 
    //                                                                                                         004be057(j)  
    //         004be07a     MOV        this,dword ptr [ESP + param_4]
    //         004be07e     MOV        EAX,dword ptr [EDX + 0x14]
    //         004be081     INC        EBX
    //         004be082     ADD        this,EAX
    //         004be084     CMP        EBX,this
    //         004be086     JL         LAB_004be03d
    //                               LAB_004be088                                                 XREF[3]:     004bdfac(j), 004bdfdf(j), 
    //                                                                                                         004be03b(j)  
    //                              spanlist.cpp:953 (7)
    //         004be088     POP        EDI
    //         004be089     POP        ESI
    //         004be08a     POP        EBP
    //         004be08b     POP        EBX
    //         004be08c     RET        0x14
}

// Offset: 0x004BE090
void AddLine_Align(TSpan_List_Manager* this_, int param_2, int param_3, int param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TSpan_List_Manager::AddLine_Align(int,int,int,int)                            *
    //                              *********************************************************************************************************
    //                              void __thiscall AddLine_Align(TSpan_List_Manager * this, int param_1
    //              void              <VOID>         <RETURN>
    //              TSpan_List_Man    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004be091(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[6]:     004be0a7(R), 004be0df(R), 004be12c(W), 004be13d(W), 
    //                                                                                     004be170(R), 004be1c6(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[8]:     004be097(R), 004be110(W), 004be149(R), 004be17b(R), 
    //                                                                                     004be19d(W), 004be1c2(R), 004be1ce(W), 004be1d7(W)  
    //              int               Stack[0x10]:4  param_4                   XREF[6]:     004be0ab(R), 004be0e3(R), 004be121(W), 004be134(W), 
    //                                                                                     004be16c(R), 004be1db(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[5]:     004be0a1(W), 004be0c6(R), 004be162(R), 004be184(R), 
    //                                                                                     004be1a5(R)  
    //                               ?AddLine_Align@TSpan_List_Manager@@QAEXHHHH@Z                XREF[4]:     Add_GDI_Clip_Mask:005382ad(c), 
    //                               TSpan_List_Manager::AddLine_Align                                         Add_GDI_Clip_Mask:005382c8(c), 
    //                                                                                                         Add_GDI_Clip_Mask:005382e3(c), 
    //                                                                                                         Add_GDI_Clip_Mask:005382fe(c)  
    //                              spanlist.cpp:961 (1)
    //         004be090     PUSH       this
    //                              spanlist.cpp:965 (22)
    //         004be091     MOV        EAX,dword ptr [ESP + param_1]
    //         004be095     PUSH       EBX
    //         004be096     PUSH       EBP
    //         004be097     MOV        EBP,dword ptr [ESP + param_3]
    //         004be09b     MOV        EDX,this
    //         004be09d     PUSH       ESI
    //         004be09e     CMP        EAX,EBP
    //         004be0a0     PUSH       EDI
    //         004be0a1     MOV        dword ptr [ESP + local_4],EDX
    //         004be0a5     JNZ        LAB_004be0df
    //                              spanlist.cpp:967 (18)
    //         004be0a7     MOV        ESI,dword ptr [ESP + param_2]
    //         004be0ab     MOV        EBP,dword ptr [ESP + param_4]
    //         004be0af     CMP        ESI,EBP
    //         004be0b1     JLE        LAB_004be0b9
    //         004be0b3     MOV        this,ESI
    //         004be0b5     MOV        ESI,EBP
    //         004be0b7     MOV        EBP,this
    //                               LAB_004be0b9                                                 XREF[1]:     004be0b1(j)  
    //                              spanlist.cpp:969 (2)
    //         004be0b9     MOV        EDI,EAX
    //                              spanlist.cpp:970 (5)
    //         004be0bb     OR         AL,0x3
    //         004be0bd     AND        EDI,0xfffffffc
    //                              spanlist.cpp:972 (6)
    //         004be0c0     CMP        ESI,EBP
    //         004be0c2     MOV        EBX,EAX
    //         004be0c4     JG         LAB_004be0d7
    //                               LAB_004be0c6                                                 XREF[1]:     004be0d5(j)  
    //                              spanlist.cpp:973 (17)
    //         004be0c6     MOV        this,dword ptr [ESP + local_4]
    //         004be0ca     PUSH       ESI
    //         004be0cb     PUSH       EBX
    //         004be0cc     PUSH       EDI
    //         004be0cd     CALL       TSpan_List_Manager::AddSpan                      void AddSpan(TSpan_List_Manager * this, int p
    //         004be0d2     INC        ESI
    //         004be0d3     CMP        ESI,EBP
    //         004be0d5     JLE        LAB_004be0c6
    //                               LAB_004be0d7                                                 XREF[2]:     004be0c4(j), 004be1bc(j)  
    //                              spanlist.cpp:1053 (8)
    //         004be0d7     POP        EDI
    //         004be0d8     POP        ESI
    //         004be0d9     POP        EBP
    //         004be0da     POP        EBX
    //         004be0db     POP        this
    //         004be0dc     RET        0x10
    //                               LAB_004be0df                                                 XREF[1]:     004be0a5(j)  
    //                              spanlist.cpp:978 (12)
    //         004be0df     MOV        this,dword ptr [ESP + param_2]
    //         004be0e3     MOV        EBX,dword ptr [ESP + param_4]
    //         004be0e7     CMP        this,EBX
    //         004be0e9     JNZ        LAB_004be102
    //                              spanlist.cpp:980 (15)
    //         004be0eb     OR         EBP,0x3
    //         004be0ee     PUSH       this
    //         004be0ef     AND        AL,0xfc
    //         004be0f1     PUSH       EBP
    //         004be0f2     PUSH       EAX
    //         004be0f3     MOV        this,EDX
    //         004be0f5     CALL       TSpan_List_Manager::AddSpan                      void AddSpan(TSpan_List_Manager * this, int p
    //                              spanlist.cpp:1053 (8)
    //         004be0fa     POP        EDI
    //         004be0fb     POP        ESI
    //         004be0fc     POP        EBP
    //         004be0fd     POP        EBX
    //         004be0fe     POP        this
    //         004be0ff     RET        0x10
    //                               LAB_004be102                                                 XREF[1]:     004be0e9(j)  
    //                              spanlist.cpp:986 (4)
    //         004be102     CMP        EBP,EAX
    //         004be104     JGE        LAB_004be116
    //                              spanlist.cpp:988 (6)
    //         004be106     MOV        EDX,this
    //         004be108     MOV        this,EBX
    //         004be10a     MOV        EBX,EDX
    //                              spanlist.cpp:989 (10)
    //         004be10c     MOV        EDX,EAX
    //         004be10e     MOV        EAX,EBP
    //         004be110     MOV        dword ptr [ESP + param_3],EDX
    //         004be114     MOV        EBP,EDX
    //                               LAB_004be116                                                 XREF[1]:     004be104(j)  
    //                              spanlist.cpp:994 (2)
    //         004be116     SUB        EBP,EAX
    //                              spanlist.cpp:995 (3)
    //         004be118     MOV        ESI,this
    //         004be11a     INC        EBP
    //                              spanlist.cpp:997 (4)
    //         004be11b     CMP        this,EBX
    //         004be11d     JGE        LAB_004be132
    //                              spanlist.cpp:999 (2)
    //         004be11f     MOV        EDX,EBX
    //                              spanlist.cpp:1000 (15)
    //         004be121     MOV        dword ptr [ESP + param_4],0x1
    //         004be129     SUB        EDX,this
    //         004be12b     INC        EDX
    //         004be12c     MOV        dword ptr [ESP + param_2],EDX
    //                              spanlist.cpp:1002 (2)
    //         004be130     JMP        LAB_004be143
    //                               LAB_004be132                                                 XREF[1]:     004be11d(j)  
    //                              spanlist.cpp:1004 (2)
    //         004be132     SUB        this,EBX
    //                              spanlist.cpp:1005 (15)
    //         004be134     MOV        dword ptr [ESP + param_4],0xffffffff
    //         004be13c     INC        this
    //         004be13d     MOV        dword ptr [ESP + param_2],this
    //         004be141     MOV        EDX,this
    //                               LAB_004be143                                                 XREF[1]:     004be130(j)  
    //                              spanlist.cpp:1008 (2)
    //         004be143     CMP        EBP,EDX
    //                              spanlist.cpp:1011 (4)
    //         004be145     MOV        EDI,EAX
    //         004be147     JL         LAB_004be19d
    //                              spanlist.cpp:1014 (10)
    //         004be149     MOV        this,dword ptr [ESP + param_3]
    //         004be14d     XOR        EBX,EBX
    //         004be14f     CMP        EAX,this
    //         004be151     JGE        LAB_004be184
    //                               LAB_004be153                                                 XREF[1]:     004be182(j)  
    //                              spanlist.cpp:1016 (2)
    //         004be153     ADD        EBX,EDX
    //                              spanlist.cpp:1017 (4)
    //         004be155     CMP        EBX,EBP
    //         004be157     JL         LAB_004be17b
    //                              spanlist.cpp:1019 (19)
    //         004be159     MOV        this,EDI
    //         004be15b     PUSH       ESI
    //         004be15c     OR         this,0x3
    //         004be15f     AND        AL,0xfc
    //         004be161     PUSH       this
    //         004be162     MOV        this,dword ptr [ESP + local_4]
    //         004be166     PUSH       EAX
    //         004be167     CALL       TSpan_List_Manager::AddSpan                      void AddSpan(TSpan_List_Manager * this, int p
    //                              spanlist.cpp:1020 (4)
    //         004be16c     MOV        this,dword ptr [ESP + param_4]
    //                              spanlist.cpp:1022 (15)
    //         004be170     MOV        EDX,dword ptr [ESP + param_2]
    //         004be174     ADD        ESI,this
    //         004be176     SUB        EBX,EBP
    //         004be178     LEA        EAX,[EDI + 0x1]
    //                               LAB_004be17b                                                 XREF[1]:     004be157(j)  
    //         004be17b     MOV        this,dword ptr [ESP + param_3]
    //                              spanlist.cpp:1025 (5)
    //         004be17f     INC        EDI
    //         004be180     CMP        EDI,this
    //         004be182     JL         LAB_004be153
    //                               LAB_004be184                                                 XREF[1]:     004be151(j)  
    //                              spanlist.cpp:1027 (17)
    //         004be184     MOV        this,dword ptr [ESP + local_4]
    //         004be188     OR         EDI,0x3
    //         004be18b     PUSH       ESI
    //         004be18c     AND        AL,0xfc
    //         004be18e     PUSH       EDI
    //         004be18f     PUSH       EAX
    //         004be190     CALL       TSpan_List_Manager::AddSpan                      void AddSpan(TSpan_List_Manager * this, int p
    //                              spanlist.cpp:1053 (8)
    //         004be195     POP        EDI
    //         004be196     POP        ESI
    //         004be197     POP        EBP
    //         004be198     POP        EBX
    //         004be199     POP        this
    //         004be19a     RET        0x10
    //                               LAB_004be19d                                                 XREF[1]:     004be147(j)  
    //                              spanlist.cpp:1035 (8)
    //         004be19d     MOV        dword ptr [ESP + param_3],0x0
    //                               LAB_004be1a5                                                 XREF[1]:     004be1df(j)  
    //                              spanlist.cpp:1039 (21)
    //         004be1a5     MOV        this,dword ptr [ESP + local_4]
    //         004be1a9     MOV        EDX,EDI
    //         004be1ab     MOV        EAX,EDI
    //         004be1ad     OR         EDX,0x3
    //         004be1b0     PUSH       ESI
    //         004be1b1     AND        AL,0xfc
    //         004be1b3     PUSH       EDX
    //         004be1b4     PUSH       EAX
    //         004be1b5     CALL       TSpan_List_Manager::AddSpan                      void AddSpan(TSpan_List_Manager * this, int p
    //                              spanlist.cpp:1041 (8)
    //         004be1ba     CMP        ESI,EBX
    //         004be1bc     JZ         LAB_004be0d7
    //                              spanlist.cpp:1043 (4)
    //         004be1c2     MOV        this,dword ptr [ESP + param_3]
    //                              spanlist.cpp:1045 (14)
    //         004be1c6     MOV        EAX,dword ptr [ESP + param_2]
    //         004be1ca     ADD        this,EBP
    //         004be1cc     CMP        this,EAX
    //         004be1ce     MOV        dword ptr [ESP + param_3],this
    //         004be1d2     JL         LAB_004be1db
    //                              spanlist.cpp:1047 (1)
    //         004be1d4     INC        EDI
    //                              spanlist.cpp:1048 (6)
    //         004be1d5     SUB        this,EAX
    //         004be1d7     MOV        dword ptr [ESP + param_3],this
    //                               LAB_004be1db                                                 XREF[1]:     004be1d2(j)  
    //                              spanlist.cpp:1050 (6)
    //         004be1db     ADD        ESI,dword ptr [ESP + param_4]
    //         004be1df     JMP        LAB_004be1a5
}

// Offset: 0x004BE1F0
void AddMiniList(TSpan_List_Manager* this_, VSpanMiniList* param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TSpan_List_Manager::AddMiniList(struct VSpanMiniList *,int,int)               *
    //                              *********************************************************************************************************
    //                              void __thiscall AddMiniList(TSpan_List_Manager * this, VSpanMiniList
    //              void              <VOID>         <RETURN>
    //              TSpan_List_Man    ECX:4 (auto)   this
    //              VSpanMiniList *   Stack[0x4]:4   param_1                   XREF[1]:     004be1f3(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004be202(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     004be1fe(R)  
    //                               ?AddMiniList@TSpan_List_Manager@@QAEXPAUVSpanMiniList@@HH@Z  XREF[4]:     view_function_terrain:005371ca(c), 
    //                               TSpan_List_Manager::AddMiniList                                           view_function_terrain:005371e8(c), 
    //                                                                                                         view_function_terrain:005372ac(c), 
    //                                                                                                         view_function_terrain:005372c6(c)  
    //                              spanlist.cpp:1060 (3)
    //         004be1f0     PUSH       EBX
    //         004be1f1     PUSH       EBP
    //         004be1f2     PUSH       ESI
    //                              spanlist.cpp:1065 (19)
    //         004be1f3     MOV        ESI,dword ptr [ESP + param_1]
    //         004be1f7     TEST       ESI,ESI
    //         004be1f9     PUSH       EDI
    //         004be1fa     MOV        EBP,this
    //         004be1fc     JZ         LAB_004be230
    //         004be1fe     MOV        EBX,dword ptr [ESP + param_3]
    //         004be202     MOV        EDI,dword ptr [ESP + param_2]
    //                               LAB_004be206                                                 XREF[1]:     004be22e(j)  
    //                              spanlist.cpp:1067 (4)
    //         004be206     XOR        EAX,EAX
    //         004be208     MOV        AL,byte ptr [ESI]
    //                              spanlist.cpp:1068 (7)
    //         004be20a     CMP        EAX,0xff
    //         004be20f     JZ         LAB_004be230
    //                              spanlist.cpp:1073 (26)
    //         004be211     ADD        EAX,EBX
    //         004be213     XOR        this,this
    //         004be215     MOV        this,byte ptr [ESI + 0x1]
    //         004be218     PUSH       EAX
    //         004be219     XOR        EAX,EAX
    //         004be21b     ADD        this,EDI
    //         004be21d     MOV        AL,byte ptr [ESI + 0x2]
    //         004be220     ADD        EAX,EDI
    //         004be222     PUSH       EAX
    //         004be223     PUSH       this
    //         004be224     MOV        this,EBP
    //         004be226     CALL       TSpan_List_Manager::AddSpan                      void AddSpan(TSpan_List_Manager * this, int p
    //                              spanlist.cpp:1074 (5)
    //         004be22b     ADD        ESI,0x3
    //         004be22e     JNZ        LAB_004be206
    //                               LAB_004be230                                                 XREF[2]:     004be1fc(j), 004be20f(j)  
    //                              spanlist.cpp:1156 (7)
    //         004be230     POP        EDI
    //         004be231     POP        ESI
    //         004be232     POP        EBP
    //         004be233     POP        EBX
    //         004be234     RET        0xc
}

// Offset: 0x004BE240
void SubtractMiniList(TSpan_List_Manager* this_, VSpanMiniList* param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TSpan_List_Manager::SubtractMiniList(struct VSpanMiniList *,int,int)          *
    //                              *********************************************************************************************************
    //                              void __thiscall SubtractMiniList(TSpan_List_Manager * this, VSpanMin
    //              void              <VOID>         <RETURN>
    //              TSpan_List_Man    ECX:4 (auto)   this
    //              VSpanMiniList *   Stack[0x4]:4   param_1                   XREF[1]:     004be243(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004be252(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     004be24e(R)  
    //                               ?SubtractMiniList@TSpan_List_Manager@@QAEXPAUVSpanMiniList@  XREF[4]:     view_function_terrain:0053720e(c), 
    //                               TSpan_List_Manager::SubtractMiniList                                      view_function_terrain:0053722c(c), 
    //                                                                                                         view_function_terrain:005372e8(c), 
    //                                                                                                         view_function_terrain:00537302(c)  
    //                              spanlist.cpp:1164 (3)
    //         004be240     PUSH       EBX
    //         004be241     PUSH       EBP
    //         004be242     PUSH       ESI
    //                              spanlist.cpp:1167 (19)
    //         004be243     MOV        ESI,dword ptr [ESP + param_1]
    //         004be247     TEST       ESI,ESI
    //         004be249     PUSH       EDI
    //         004be24a     MOV        EBP,this
    //         004be24c     JZ         LAB_004be280
    //         004be24e     MOV        EBX,dword ptr [ESP + param_3]
    //         004be252     MOV        EDI,dword ptr [ESP + param_2]
    //                               LAB_004be256                                                 XREF[1]:     004be27e(j)  
    //                              spanlist.cpp:1169 (4)
    //         004be256     XOR        EAX,EAX
    //         004be258     MOV        AL,byte ptr [ESI]
    //                              spanlist.cpp:1170 (7)
    //         004be25a     CMP        EAX,0xff
    //         004be25f     JZ         LAB_004be280
    //                              spanlist.cpp:1175 (26)
    //         004be261     ADD        EAX,EBX
    //         004be263     XOR        this,this
    //         004be265     MOV        this,byte ptr [ESI + 0x1]
    //         004be268     PUSH       EAX
    //         004be269     XOR        EAX,EAX
    //         004be26b     ADD        this,EDI
    //         004be26d     MOV        AL,byte ptr [ESI + 0x2]
    //         004be270     ADD        EAX,EDI
    //         004be272     PUSH       EAX
    //         004be273     PUSH       this
    //         004be274     MOV        this,EBP
    //         004be276     CALL       TSpan_List_Manager::DeleteSpan                   void DeleteSpan(TSpan_List_Manager * this, in
    //                              spanlist.cpp:1176 (5)
    //         004be27b     ADD        ESI,0x3
    //         004be27e     JNZ        LAB_004be256
    //                               LAB_004be280                                                 XREF[2]:     004be24c(j), 004be25f(j)  
    //                              spanlist.cpp:1179 (7)
    //         004be280     POP        EDI
    //         004be281     POP        ESI
    //         004be282     POP        EBP
    //         004be283     POP        EBX
    //         004be284     RET        0xc
}

// Offset: 0x004BE290
void DeleteSpan(TSpan_List_Manager* this_, int param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TSpan_List_Manager::DeleteSpan(int,int,int)                                   *
    //                              *********************************************************************************************************
    //                              void __thiscall DeleteSpan(TSpan_List_Manager * this, int param_1, i
    //              void              <VOID>         <RETURN>
    //              TSpan_List_Man    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[4]:     004be2af(R), 004be2bf(W), 004be2e3(W), 004be402(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[7]:     004be2b3(R), 004be2bb(W), 004be2c5(R), 004be2ed(W), 
    //                                                                                     004be3ce(R), 004be406(R), 004be464(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[6]:     004be296(R), 004be38a(W), 004be3c1(R), 004be41e(R), 
    //                                                                                     004be427(W), 004be47f(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     004be380(W), 004be41a(W), 004be458(R)  
    //              VSpan_Node *      Stack[-0x8]:4  L
    //                               ?DeleteSpan@TSpan_List_Manager@@QAEXHHH@Z                    XREF[3]:     SubtractMiniList:004be276(c), 
    //                               TSpan_List_Manager::DeleteSpan                                            DeleteShape:004be536(c), 
    //                                                                                                         DeleteShape:004be587(c)  
    //                              spanlist.cpp:1187 (6)
    //         004be290     PUSH       this
    //         004be291     PUSH       EBX
    //         004be292     MOV        EBX,this
    //         004be294     PUSH       EBP
    //         004be295     PUSH       ESI
    //                              spanlist.cpp:1194 (25)
    //         004be296     MOV        ESI,dword ptr [ESP + param_3]
    //         004be29a     MOV        EAX,dword ptr [EBX + 0x60]
    //         004be29d     CMP        ESI,EAX
    //         004be29f     PUSH       EDI
    //         004be2a0     JL         LAB_004be49b
    //         004be2a6     CMP        ESI,dword ptr [EBX + 0x64]
    //         004be2a9     JG         LAB_004be49b
    //                              spanlist.cpp:1205 (26)
    //         004be2af     MOV        EDI,dword ptr [ESP + param_1]
    //         004be2b3     MOV        EDX,dword ptr [ESP + param_2]
    //         004be2b7     CMP        EDI,EDX
    //         004be2b9     JLE        LAB_004be2c9
    //         004be2bb     MOV        dword ptr [ESP + param_2],EDI
    //         004be2bf     MOV        dword ptr [ESP + param_1],EDX
    //         004be2c3     MOV        EDI,EDX
    //         004be2c5     MOV        EDX,dword ptr [ESP + param_2]
    //                               LAB_004be2c9                                                 XREF[1]:     004be2b9(j)  
    //                              spanlist.cpp:1207 (22)
    //         004be2c9     MOV        EAX,dword ptr [EBX + 0x58]
    //         004be2cc     CMP        EDX,EAX
    //         004be2ce     JL         LAB_004be49b
    //         004be2d4     MOV        this,dword ptr [EBX + 0x5c]
    //         004be2d7     CMP        EDI,this
    //         004be2d9     JG         LAB_004be49b
    //                              spanlist.cpp:1209 (10)
    //         004be2df     CMP        EDI,EAX
    //         004be2e1     JGE        LAB_004be2e9
    //         004be2e3     MOV        dword ptr [ESP + param_1],EAX
    //         004be2e7     MOV        EDI,EAX
    //                               LAB_004be2e9                                                 XREF[1]:     004be2e1(j)  
    //                              spanlist.cpp:1210 (10)
    //         004be2e9     CMP        EDX,this
    //         004be2eb     JLE        LAB_004be2f3
    //         004be2ed     MOV        dword ptr [ESP + param_2],this
    //         004be2f1     MOV        EDX,this
    //                               LAB_004be2f3                                                 XREF[1]:     004be2eb(j)  
    //                              spanlist.cpp:1214 (22)
    //         004be2f3     MOV        EAX,dword ptr [EBX + 0x3c]
    //         004be2f6     LEA        EBP,[ESI*0x4 + 0x0]
    //         004be2fd     MOV        EAX,dword ptr [EBP + EAX*0x1]
    //         004be301     TEST       EAX,EAX
    //         004be303     JZ         LAB_004be49b
    //                              spanlist.cpp:1218 (15)
    //         004be309     MOV        this,dword ptr [EBX + 0x44]
    //         004be30c     MOV        ESI,dword ptr [EBP + this->VSList.Zone_Ptrs*0x1]
    //         004be310     CMP        EDX,ESI
    //         004be312     JL         LAB_004be49b
    //                              spanlist.cpp:1219 (15)
    //         004be318     MOV        this,dword ptr [EBX + 0x48]
    //         004be31b     MOV        this,dword ptr [EBP + this->VSList.Zone_Ptrs*0
    //         004be31f     CMP        EDI,this
    //         004be321     JG         LAB_004be49b
    //                              spanlist.cpp:1223 (8)
    //         004be327     CMP        EDI,ESI
    //         004be329     JG         LAB_004be37d
    //         004be32b     CMP        EDX,this
    //         004be32d     JL         LAB_004be37d
    //                              spanlist.cpp:1225 (16)
    //         004be32f     MOV        EDX,dword ptr [EBX + 0x40]
    //         004be332     MOV        this,dword ptr [EBP + EDX*0x1]
    //         004be336     PUSH       this
    //         004be337     PUSH       EAX
    //         004be338     MOV        this,EBX
    //         004be33a     CALL       TSpan_Node_List::FreeThread                      int FreeThread(TSpan_Node_List * this, VSpan_
    //                              spanlist.cpp:1227 (11)
    //         004be33f     MOV        EDX,dword ptr [EBX + 0x3c]
    //         004be342     MOV        dword ptr [EBP + EDX*0x1],0x0
    //                              spanlist.cpp:1228 (11)
    //         004be34a     MOV        EAX,dword ptr [EBX + 0x40]
    //         004be34d     MOV        dword ptr [EBP + EAX*0x1],0x0
    //                              spanlist.cpp:1229 (10)
    //         004be355     MOV        this,dword ptr [EBX + 0x4c]
    //         004be358     MOV        dword ptr [this->VSList.Zone_Ptrs + EBP*0x1],0x0
    //                              spanlist.cpp:1230 (11)
    //         004be35f     MOV        EDX,dword ptr [EBX + 0x44]
    //         004be362     MOV        dword ptr [EBP + EDX*0x1],0x0
    //                              spanlist.cpp:1231 (11)
    //         004be36a     MOV        EAX,dword ptr [EBX + 0x48]
    //         004be36d     MOV        dword ptr [EBP + EAX*0x1],0x0
    //                              spanlist.cpp:1345 (8)
    //         004be375     POP        EDI
    //         004be376     POP        ESI
    //         004be377     POP        EBP
    //         004be378     POP        EBX
    //         004be379     POP        this
    //         004be37a     RET        0xc
    //                               LAB_004be37d                                                 XREF[2]:     004be329(j), 004be32d(j)  
    //                              spanlist.cpp:1245 (7)
    //         004be37d     MOV        this,dword ptr [EBX + 0x40]
    //         004be380     MOV        dword ptr [ESP + local_4],EAX
    //                              spanlist.cpp:1246 (10)
    //         004be384     MOV        ESI,EAX
    //         004be386     MOV        this,dword ptr [EBP + this->VSList.Zone_Ptrs*0
    //         004be38a     MOV        dword ptr [ESP + param_3],this
    //                              spanlist.cpp:1250 (7)
    //         004be38e     MOV        this,dword ptr [EAX + 0xc]
    //         004be391     CMP        this,EDI
    //         004be393     JGE        LAB_004be39c
    //                               LAB_004be395                                                 XREF[1]:     004be39a(j)  
    //                              spanlist.cpp:1252 (7)
    //         004be395     MOV        ESI,dword ptr [ESI]
    //         004be397     CMP        dword ptr [ESI + 0xc],EDI
    //         004be39a     JL         LAB_004be395
    //                               LAB_004be39c                                                 XREF[1]:     004be393(j)  
    //                              spanlist.cpp:1257 (12)
    //         004be39c     MOV        this,dword ptr [ESI + 0x8]
    //         004be39f     CMP        EDI,this
    //         004be3a1     JLE        LAB_004be3fc
    //         004be3a3     CMP        EDX,dword ptr [ESI + 0xc]
    //         004be3a6     JGE        LAB_004be3f0
    //                              spanlist.cpp:1259 (7)
    //         004be3a8     MOV        this,EBX
    //         004be3aa     CALL       TSpan_Node_List::GetNode                         VSpan_Node * GetNode(TSpan_Node_List * this)
    //                              spanlist.cpp:1261 (3)
    //         004be3af     MOV        dword ptr [EAX + 0x4],ESI
    //                              spanlist.cpp:1262 (4)
    //         004be3b2     MOV        EDX,dword ptr [ESI]
    //         004be3b4     MOV        dword ptr [EAX],EDX
    //                              spanlist.cpp:1263 (2)
    //         004be3b6     MOV        dword ptr [ESI],EAX
    //                              spanlist.cpp:1264 (9)
    //         004be3b8     MOV        this,dword ptr [EAX]
    //         004be3ba     TEST       this,this
    //         004be3bc     JZ         LAB_004be3c1
    //         004be3be     MOV        dword ptr [ECX + this+0x4],EAX
    //                               LAB_004be3c1                                                 XREF[1]:     004be3bc(j)  
    //                              spanlist.cpp:1268 (13)
    //         004be3c1     CMP        ESI,dword ptr [ESP + param_3]
    //         004be3c5     JNZ        LAB_004be3ce
    //         004be3c7     MOV        this,dword ptr [EBX + 0x40]
    //         004be3ca     MOV        dword ptr [EBP + this->VSList.Zone_Ptrs*0x1],EAX
    //                               LAB_004be3ce                                                 XREF[1]:     004be3c5(j)  
    //                              spanlist.cpp:1270 (5)
    //         004be3ce     MOV        EDX,dword ptr [ESP + param_2]
    //         004be3d2     INC        EDX
    //                              spanlist.cpp:1272 (13)
    //         004be3d3     DEC        EDI
    //         004be3d4     MOV        dword ptr [EAX + 0x8],EDX
    //         004be3d7     MOV        this,dword ptr [ESI + 0xc]
    //         004be3da     MOV        dword ptr [EAX + 0xc],this
    //         004be3dd     MOV        dword ptr [ESI + 0xc],EDI
    //                              spanlist.cpp:1274 (8)
    //         004be3e0     MOV        EDX,dword ptr [EBX + 0x4c]
    //         004be3e3     ADD        EBP,EDX
    //         004be3e5     INC        dword ptr [EBP]
    //                              spanlist.cpp:1345 (8)
    //         004be3e8     POP        EDI
    //         004be3e9     POP        ESI
    //         004be3ea     POP        EBP
    //         004be3eb     POP        EBX
    //         004be3ec     POP        this
    //         004be3ed     RET        0xc
    //                               LAB_004be3f0                                                 XREF[1]:     004be3a6(j)  
    //                              spanlist.cpp:1280 (4)
    //         004be3f0     CMP        EDI,this
    //         004be3f2     JLE        LAB_004be3fc
    //                              spanlist.cpp:1282 (6)
    //         004be3f4     LEA        this,[EDI + -0x1]
    //         004be3f7     MOV        dword ptr [ESI + 0xc],this
    //                              spanlist.cpp:1283 (2)
    //         004be3fa     MOV        ESI,dword ptr [ESI]
    //                               LAB_004be3fc                                                 XREF[2]:     004be3a1(j), 004be3f2(j)  
    //                              spanlist.cpp:1289 (14)
    //         004be3fc     TEST       ESI,ESI
    //         004be3fe     JZ         LAB_004be475
    //         004be400     JMP        LAB_004be40a
    //                               LAB_004be402                                                 XREF[1]:     004be462(j)  
    //         004be402     MOV        EDI,dword ptr [ESP + param_1]
    //         004be406     MOV        EDX,dword ptr [ESP + param_2]
    //                               LAB_004be40a                                                 XREF[1]:     004be400(j)  
    //                              spanlist.cpp:1291 (10)
    //         004be40a     CMP        EDI,dword ptr [ESI + 0x8]
    //         004be40d     JG         LAB_004be45e
    //         004be40f     CMP        EDX,dword ptr [ESI + 0xc]
    //         004be412     JL         LAB_004be45e
    //                              spanlist.cpp:1295 (10)
    //         004be414     CMP        ESI,EAX
    //         004be416     JNZ        LAB_004be41e
    //         004be418     MOV        EDX,dword ptr [ESI]
    //         004be41a     MOV        dword ptr [ESP + local_4],EDX
    //                               LAB_004be41e                                                 XREF[1]:     004be416(j)  
    //                              spanlist.cpp:1299 (13)
    //         004be41e     CMP        ESI,dword ptr [ESP + param_3]
    //         004be422     JNZ        LAB_004be42b
    //         004be424     MOV        EAX,dword ptr [ESI + 0x4]
    //         004be427     MOV        dword ptr [ESP + param_3],EAX
    //                               LAB_004be42b                                                 XREF[1]:     004be422(j)  
    //                              spanlist.cpp:1303 (7)
    //         004be42b     MOV        EAX,dword ptr [ESI + 0x4]
    //         004be42e     TEST       EAX,EAX
    //         004be430     JZ         LAB_004be436
    //                              spanlist.cpp:1305 (4)
    //         004be432     MOV        this,dword ptr [ESI]
    //         004be434     MOV        dword ptr [EAX],this
    //                               LAB_004be436                                                 XREF[1]:     004be430(j)  
    //                              spanlist.cpp:1308 (6)
    //         004be436     MOV        EAX,dword ptr [ESI]
    //         004be438     TEST       EAX,EAX
    //         004be43a     JZ         LAB_004be442
    //                              spanlist.cpp:1310 (6)
    //         004be43c     MOV        EDX,dword ptr [ESI + 0x4]
    //         004be43f     MOV        dword ptr [EAX + 0x4],EDX
    //                               LAB_004be442                                                 XREF[1]:     004be43a(j)  
    //                              spanlist.cpp:1315 (2)
    //         004be442     MOV        EDI,dword ptr [ESI]
    //                              spanlist.cpp:1316 (8)
    //         004be444     PUSH       ESI
    //         004be445     MOV        this,EBX
    //         004be447     CALL       TSpan_Node_List::FreeNode                        void FreeNode(TSpan_Node_List * this, VSpan_N
    //                              spanlist.cpp:1317 (3)
    //         004be44c     MOV        EAX,dword ptr [EBX + 0x4c]
    //                              spanlist.cpp:1318 (9)
    //         004be44f     MOV        ESI,EDI
    //         004be451     ADD        EAX,EBP
    //         004be453     MOV        this,dword ptr [EAX]
    //         004be455     DEC        this
    //         004be456     MOV        dword ptr [EAX],this
    //                              spanlist.cpp:1320 (6)
    //         004be458     MOV        EAX,dword ptr [ESP + local_4]
    //         004be45c     JMP        LAB_004be460
    //                               LAB_004be45e                                                 XREF[2]:     004be40d(j), 004be412(j)  
    //                              spanlist.cpp:1322 (2)
    //         004be45e     XOR        EDI,EDI
    //                               LAB_004be460                                                 XREF[1]:     004be45c(j)  
    //                              spanlist.cpp:1289 (8)
    //         004be460     TEST       EDI,EDI
    //         004be462     JNZ        LAB_004be402
    //         004be464     MOV        EDX,dword ptr [ESP + param_2]
    //                              spanlist.cpp:1328 (4)
    //         004be468     TEST       ESI,ESI
    //         004be46a     JZ         LAB_004be475
    //                              spanlist.cpp:1330 (5)
    //         004be46c     CMP        EDX,dword ptr [ESI + 0x8]
    //         004be46f     JL         LAB_004be475
    //                              spanlist.cpp:1332 (4)
    //         004be471     INC        EDX
    //         004be472     MOV        dword ptr [ESI + 0x8],EDX
    //                               LAB_004be475                                                 XREF[3]:     004be3fe(j), 004be46a(j), 
    //                                                                                                         004be46f(j)  
    //                              spanlist.cpp:1338 (7)
    //         004be475     MOV        this,dword ptr [EBX + 0x3c]
    //         004be478     MOV        dword ptr [EBP + this->VSList.Zone_Ptrs*0x1],EAX
    //                              spanlist.cpp:1339 (11)
    //         004be47c     MOV        EDX,dword ptr [EBX + 0x40]
    //         004be47f     MOV        this,dword ptr [ESP + param_3]
    //         004be483     MOV        dword ptr [EBP + EDX*0x1],this
    //                              spanlist.cpp:1340 (10)
    //         004be487     MOV        EDX,dword ptr [EBX + 0x44]
    //         004be48a     MOV        EAX,dword ptr [EAX + 0x8]
    //         004be48d     MOV        dword ptr [EBP + EDX*0x1],EAX
    //                              spanlist.cpp:1341 (10)
    //         004be491     MOV        EDX,dword ptr [EBX + 0x48]
    //         004be494     MOV        EAX,dword ptr [ECX + this+0xc]
    //         004be497     MOV        dword ptr [EBP + EDX*0x1],EAX
    //                               LAB_004be49b                                                 XREF[7]:     004be2a0(j), 004be2a9(j), 
    //                                                                                                         004be2ce(j), 004be2d9(j), 
    //                                                                                                         004be303(j), 004be312(j), 
    //                                                                                                         004be321(j)  
    //                              spanlist.cpp:1345 (8)
    //         004be49b     POP        EDI
    //         004be49c     POP        ESI
    //         004be49d     POP        EBP
    //         004be49e     POP        EBX
    //         004be49f     POP        this
    //         004be4a0     RET        0xc
}

// Offset: 0x004BE4B0
void DeleteShape(TSpan_List_Manager* this_, TShape* param_2, int param_3, int param_4, int param_5, int param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TSpan_List_Manager::DeleteShape(class TShape *,int,int,int,int)               *
    //                              *********************************************************************************************************
    //                              void __thiscall DeleteShape(TSpan_List_Manager * this, TShape * para
    //              void              <VOID>         <RETURN>
    //              TSpan_List_Man    ECX:4 (auto)   this
    //              TShape *          Stack[0x4]:4   param_1                   XREF[4]:     004be4b6(R), 004be4f8(W), 004be51f(R), 004be573(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004be4d0(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     004be4da(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[3]:     004be4e0(R), 004be53b(R), 004be58c(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     004be4f2(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     004be4b1(*), 004be532(R), 004be580(R)  
    //                               ?DeleteShape@TSpan_List_Manager@@QAEXPAVTShape@@HHHH@Z
    //                               TSpan_List_Manager::DeleteShape
    //                              spanlist.cpp:1352 (6)
    //         004be4b0     PUSH       this
    //         004be4b1     MOV        dword ptr [ESP]=>local_4,this
    //         004be4b5     PUSH       EBX
    //                              spanlist.cpp:1357 (15)
    //         004be4b6     MOV        this,dword ptr [ESP + param_1]
    //         004be4ba     PUSH       EBP
    //         004be4bb     PUSH       ESI
    //         004be4bc     PUSH       EDI
    //         004be4bd     TEST       this,this
    //         004be4bf     JZ         LAB_004be59c
    //                              spanlist.cpp:1359 (11)
    //         004be4c5     MOV        EAX,dword ptr [ECX + this+0x18]
    //         004be4c8     TEST       EAX,EAX
    //         004be4ca     JZ         LAB_004be59c
    //                              spanlist.cpp:1368 (10)
    //         004be4d0     MOV        EBX,dword ptr [ESP + param_2]
    //         004be4d4     MOV        EDX,dword ptr [ECX + this+0x1c]
    //         004be4d7     SHL        EBX,0x5
    //                              spanlist.cpp:1372 (6)
    //         004be4da     MOV        EBP,dword ptr [ESP + param_3]
    //         004be4de     ADD        EBX,EDX
    //                              spanlist.cpp:1376 (45)
    //         004be4e0     MOV        EDX,dword ptr [ESP + param_4]
    //         004be4e4     MOV        ESI,dword ptr [EBX + 0x4]
    //         004be4e7     MOV        EDI,EDX
    //         004be4e9     ADD        ESI,EAX
    //         004be4eb     MOV        EAX,dword ptr [EBX + 0x10]
    //         004be4ee     LEA        this,[EAX + EBP*0x1 + -0x1]
    //         004be4f2     MOV        EAX,dword ptr [ESP + param_5]
    //         004be4f6     TEST       EAX,EAX
    //         004be4f8     MOV        dword ptr [ESP + param_1],this
    //         004be4fc     JNZ        LAB_004be553
    //         004be4fe     MOV        this,dword ptr [EBX + 0x14]
    //         004be501     MOV        EAX,EDX
    //         004be503     ADD        EAX,this
    //         004be505     CMP        EDX,EAX
    //         004be507     JGE        LAB_004be59c
    //                               LAB_004be50d                                                 XREF[1]:     004be549(j)  
    //                              spanlist.cpp:1378 (3)
    //         004be50d     MOV        AX,word ptr [ESI]
    //                              spanlist.cpp:1379 (10)
    //         004be510     MOV        this,word ptr [ESI + 0x2]
    //         004be514     ADD        ESI,0x2
    //         004be517     ADD        ESI,0x2
    //                              spanlist.cpp:1381 (9)
    //         004be51a     TEST       AH,0x80
    //         004be51d     JNZ        LAB_004be53f
    //         004be51f     MOV        EDX,dword ptr [ESP + param_1]
    //                              spanlist.cpp:1383 (40)
    //         004be523     PUSH       EDI
    //         004be524     MOVSX      this,this
    //         004be527     MOVSX      EAX,AX
    //         004be52a     SUB        EDX,this
    //         004be52c     MOV        this,EBP
    //         004be52e     ADD        this,EAX
    //         004be530     PUSH       EDX
    //         004be531     PUSH       this
    //         004be532     MOV        this,dword ptr [ESP + local_4]
    //         004be536     CALL       TSpan_List_Manager::DeleteSpan                   void DeleteSpan(TSpan_List_Manager * this, in
    //         004be53b     MOV        EDX,dword ptr [ESP + param_4]
    //                               LAB_004be53f                                                 XREF[1]:     004be51d(j)  
    //         004be53f     MOV        this,dword ptr [EBX + 0x14]
    //         004be542     MOV        EAX,EDX
    //         004be544     INC        EDI
    //         004be545     ADD        EAX,this
    //         004be547     CMP        EDI,EAX
    //         004be549     JL         LAB_004be50d
    //                              spanlist.cpp:1402 (8)
    //         004be54b     POP        EDI
    //         004be54c     POP        ESI
    //         004be54d     POP        EBP
    //         004be54e     POP        EBX
    //         004be54f     POP        this
    //         004be550     RET        0x14
    //                               LAB_004be553                                                 XREF[1]:     004be4fc(j)  
    //                              spanlist.cpp:1389 (11)
    //         004be553     MOV        EAX,dword ptr [EBX + 0x14]
    //         004be556     MOV        this,EDX
    //         004be558     ADD        this,EAX
    //         004be55a     CMP        EDX,this
    //         004be55c     JGE        LAB_004be59c
    //                               LAB_004be55e                                                 XREF[1]:     004be59a(j)  
    //                              spanlist.cpp:1391 (3)
    //         004be55e     MOV        this,word ptr [ESI]
    //                              spanlist.cpp:1392 (10)
    //         004be561     MOV        AX,word ptr [ESI + 0x2]
    //         004be565     ADD        ESI,0x2
    //         004be568     ADD        ESI,0x2
    //                              spanlist.cpp:1394 (5)
    //         004be56b     TEST       AH,0x80
    //         004be56e     JNZ        LAB_004be590
    //                              spanlist.cpp:1396 (44)
    //         004be570     MOVSX      EDX,this
    //         004be573     MOV        this,dword ptr [ESP + param_1]
    //         004be577     PUSH       EDI
    //         004be578     SUB        this,EDX
    //         004be57a     MOVSX      EDX,AX
    //         004be57d     MOV        EAX,EBP
    //         004be57f     PUSH       this
    //         004be580     MOV        this,dword ptr [ESP + local_4]
    //         004be584     ADD        EAX,EDX
    //         004be586     PUSH       EAX
    //         004be587     CALL       TSpan_List_Manager::DeleteSpan                   void DeleteSpan(TSpan_List_Manager * this, in
    //         004be58c     MOV        EDX,dword ptr [ESP + param_4]
    //                               LAB_004be590                                                 XREF[1]:     004be56e(j)  
    //         004be590     MOV        EAX,dword ptr [EBX + 0x14]
    //         004be593     MOV        this,EDX
    //         004be595     INC        EDI
    //         004be596     ADD        this,EAX
    //         004be598     CMP        EDI,this
    //         004be59a     JL         LAB_004be55e
    //                               LAB_004be59c                                                 XREF[4]:     004be4bf(j), 004be4ca(j), 
    //                                                                                                         004be507(j), 004be55c(j)  
    //                              spanlist.cpp:1402 (8)
    //         004be59c     POP        EDI
    //         004be59d     POP        ESI
    //         004be59e     POP        EBP
    //         004be59f     POP        EBX
    //         004be5a0     POP        this
    //         004be5a1     RET        0x14
}

// Offset: 0x004BE5B0
int PointVisible(TSpan_List_Manager* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TSpan_List_Manager::PointVisible(int,int)                                      *
    //                              *********************************************************************************************************
    //                              int __thiscall PointVisible(TSpan_List_Manager * this, int param_1, 
    //              int               EAX:4          <RETURN>
    //              TSpan_List_Man    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004be5c7(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004be5b0(R)  
    //                               ?PointVisible@TSpan_List_Manager@@QAEHHH@Z
    //                               TSpan_List_Manager::PointVisible
    //                              spanlist.cpp:1410 (13)
    //         004be5b0     MOV        EAX,dword ptr [ESP + param_2]
    //         004be5b4     TEST       EAX,EAX
    //         004be5b6     JL         LAB_004be5e6
    //         004be5b8     CMP        EAX,dword ptr [ECX + this->Num_Lines]
    //         004be5bb     JGE        LAB_004be5e6
    //                              spanlist.cpp:1416 (14)
    //         004be5bd     MOV        this,dword ptr [ECX + this->Line_Head_Ptrs]
    //         004be5c0     MOV        EAX,dword ptr [this->VSList.Zone_Ptrs + EAX*0x4]
    //         004be5c3     TEST       EAX,EAX
    //         004be5c5     JZ         LAB_004be5e6
    //         004be5c7     MOV        this,dword ptr [ESP + param_1]
    //                               LAB_004be5cb                                                 XREF[1]:     004be5d9(j)  
    //                              spanlist.cpp:1421 (10)
    //         004be5cb     CMP        this,dword ptr [EAX + 0x8]
    //         004be5ce     JL         LAB_004be5d5
    //         004be5d0     CMP        this,dword ptr [EAX + 0xc]
    //         004be5d3     JLE        LAB_004be5de
    //                               LAB_004be5d5                                                 XREF[1]:     004be5ce(j)  
    //                              spanlist.cpp:1422 (6)
    //         004be5d5     MOV        EAX,dword ptr [EAX]
    //         004be5d7     TEST       EAX,EAX
    //         004be5d9     JNZ        LAB_004be5cb
    //                              spanlist.cpp:1426 (3)
    //         004be5db     RET        0x8
    //                               LAB_004be5de                                                 XREF[1]:     004be5d3(j)  
    //                              spanlist.cpp:1421 (5)
    //         004be5de     MOV        EAX,0x1
    //                              spanlist.cpp:1426 (3)
    //         004be5e3     RET        0x8
    //                               LAB_004be5e6                                                 XREF[3]:     004be5b6(j), 004be5bb(j), 
    //                                                                                                         004be5c5(j)  
    //                              spanlist.cpp:1413 (2)
    //         004be5e6     XOR        EAX,EAX
    //                              spanlist.cpp:1426 (3)
    //         004be5e8     RET        0x8
}

// Offset: 0x004BE5F0
void Merge_n_Align(TSpan_List_Manager* this_, TSpan_List_Manager* param_2, TSpan_List_Manager* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TSpan_List_Manager::Merge_n_Align(class TSpan_List_Manager *,class TSpan_L... *
    //                              *********************************************************************************************************
    //                              void __thiscall Merge_n_Align(TSpan_List_Manager * this, TSpan_List_
    //              void              <VOID>         <RETURN>
    //              TSpan_List_Man    ECX:4 (auto)   this
    //              TSpan_List_Man    Stack[0x4]:4   param_1                   XREF[2]:     004be5fb(R), 004be62b(R)  
    //              TSpan_List_Man    Stack[0x8]:4   param_2                   XREF[2]:     004be607(R), 004be627(R)  
    //                               ?Merge_n_Align@TSpan_List_Manager@@QAEXPAV1@0@Z              XREF[1]:     view_function_terrain:00537c59(c)  
    //                               TSpan_List_Manager::Merge_n_Align
    //                              spanlist.cpp:1436 (6)
    //         004be5f0     PUSH       EBX
    //         004be5f1     PUSH       EBP
    //         004be5f2     PUSH       ESI
    //         004be5f3     PUSH       EDI
    //         004be5f4     MOV        EBP,this
    //                              spanlist.cpp:1442 (5)
    //         004be5f6     CALL       TSpan_List_Manager::ResetAll                     void ResetAll(TSpan_List_Manager * this)
    //                              spanlist.cpp:1446 (21)
    //         004be5fb     MOV        EDX,dword ptr [ESP + param_1]
    //         004be5ff     MOV        EAX,dword ptr [EBP + 0x50]
    //         004be602     CMP        EAX,dword ptr [EDX + 0x50]
    //         004be605     JNZ        LAB_004be684
    //         004be607     MOV        ESI,dword ptr [ESP + param_2]
    //         004be60b     CMP        EAX,dword ptr [ESI + 0x50]
    //         004be60e     JNZ        LAB_004be684
    //                              spanlist.cpp:1447 (15)
    //         004be610     MOV        this,dword ptr [EBP + 0x54]
    //         004be613     MOV        EDI,dword ptr [EDX + 0x54]
    //         004be616     CMP        this,EDI
    //         004be618     JNZ        LAB_004be684
    //         004be61a     CMP        this,dword ptr [ESI + 0x54]
    //         004be61d     JNZ        LAB_004be684
    //                              spanlist.cpp:1451 (16)
    //         004be61f     XOR        EBX,EBX
    //         004be621     TEST       EAX,EAX
    //         004be623     JLE        LAB_004be684
    //         004be625     JMP        LAB_004be62f
    //                               LAB_004be627                                                 XREF[1]:     004be682(j)  
    //         004be627     MOV        ESI,dword ptr [ESP + param_2]
    //         004be62b     MOV        EDX,dword ptr [ESP + param_1]
    //                               LAB_004be62f                                                 XREF[1]:     004be625(j)  
    //                              spanlist.cpp:1453 (3)
    //         004be62f     MOV        EAX,dword ptr [EDX + 0x3c]
    //                              spanlist.cpp:1454 (9)
    //         004be632     MOV        this,dword ptr [ESI + 0x3c]
    //         004be635     MOV        EDI,dword ptr [EAX + EBX*0x4]
    //         004be638     MOV        ESI,dword ptr [this->VSList.Zone_Ptrs + EBX*0x4]
    //                               LAB_004be63b                                                 XREF[2]:     004be660(j), 004be67a(j)  
    //                              spanlist.cpp:1456 (8)
    //         004be63b     TEST       EDI,EDI
    //         004be63d     JNZ        LAB_004be647
    //         004be63f     TEST       ESI,ESI
    //         004be641     JZ         LAB_004be67c
    //                              spanlist.cpp:1458 (4)
    //         004be643     TEST       EDI,EDI
    //         004be645     JZ         LAB_004be65e
    //                               LAB_004be647                                                 XREF[1]:     004be63d(j)  
    //                              spanlist.cpp:1462 (21)
    //         004be647     MOV        EDX,dword ptr [EDI + 0xc]
    //         004be64a     MOV        EAX,dword ptr [EDI + 0x8]
    //         004be64d     OR         EDX,0x3
    //         004be650     PUSH       EBX
    //         004be651     AND        AL,0xfc
    //         004be653     PUSH       EDX
    //         004be654     PUSH       EAX
    //         004be655     MOV        this,EBP
    //         004be657     CALL       TSpan_List_Manager::AddSpan                      void AddSpan(TSpan_List_Manager * this, int p
    //                              spanlist.cpp:1463 (2)
    //         004be65c     MOV        EDI,dword ptr [EDI]
    //                               LAB_004be65e                                                 XREF[1]:     004be645(j)  
    //                              spanlist.cpp:1466 (4)
    //         004be65e     TEST       ESI,ESI
    //         004be660     JZ         LAB_004be63b
    //                              spanlist.cpp:1470 (22)
    //         004be662     MOV        this,dword ptr [ESI + 0xc]
    //         004be665     MOV        EDX,dword ptr [ESI + 0x8]
    //         004be668     OR         this,0x3
    //         004be66b     PUSH       EBX
    //         004be66c     AND        EDX,0xfffffffc
    //         004be66f     PUSH       this
    //         004be670     PUSH       EDX
    //         004be671     MOV        this,EBP
    //         004be673     CALL       TSpan_List_Manager::AddSpan                      void AddSpan(TSpan_List_Manager * this, int p
    //                              spanlist.cpp:1471 (2)
    //         004be678     MOV        ESI,dword ptr [ESI]
    //                              spanlist.cpp:1473 (2)
    //         004be67a     JMP        LAB_004be63b
    //                               LAB_004be67c                                                 XREF[1]:     004be641(j)  
    //                              spanlist.cpp:1451 (8)
    //         004be67c     MOV        EAX,dword ptr [EBP + 0x50]
    //         004be67f     INC        EBX
    //         004be680     CMP        EBX,EAX
    //         004be682     JL         LAB_004be627
    //                               LAB_004be684                                                 XREF[5]:     004be605(j), 004be60e(j), 
    //                                                                                                         004be618(j), 004be61d(j), 
    //                                                                                                         004be623(j)  
    //                              spanlist.cpp:1477 (7)
    //         004be684     POP        EDI
    //         004be685     POP        ESI
    //         004be686     POP        EBP
    //         004be687     POP        EBX
    //         004be688     RET        0x8
}

// Offset: 0x004BE690
void AlignamizeSpans(TSpan_List_Manager* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TSpan_List_Manager::AlignamizeSpans(void)                                     *
    //                              *********************************************************************************************************
    //                              void __thiscall AlignamizeSpans(TSpan_List_Manager * this)
    //              void              <VOID>         <RETURN>
    //              TSpan_List_Man    ECX:4 (auto)   this
    //                               ?AlignamizeSpans@TSpan_List_Manager@@QAEXXZ
    //                               TSpan_List_Manager::AlignamizeSpans
    //                              spanlist.cpp:1485 (4)
    //         004be690     PUSH       EBX
    //         004be691     PUSH       EDI
    //         004be692     MOV        EDI,this
    //                              spanlist.cpp:1490 (15)
    //         004be694     XOR        EBX,EBX
    //         004be696     MOV        EAX,dword ptr [EDI + 0x50]
    //         004be699     TEST       EAX,EAX
    //         004be69b     JLE        LAB_004be74b
    //         004be6a1     PUSH       ESI
    //         004be6a2     PUSH       EBP
    //                              spanlist.cpp:1530 (15)
    //         004be6a3     MOV        EBP,0xfffffffc
    //                               LAB_004be6a8                                                 XREF[1]:     004be743(j)  
    //         004be6a8     MOV        EAX,dword ptr [EDI + 0x3c]
    //         004be6ab     MOV        ESI,dword ptr [EAX + EBX*0x4]
    //         004be6ae     TEST       ESI,ESI
    //         004be6b0     JZ         LAB_004be71c
    //                               LAB_004be6b2                                                 XREF[1]:     004be71a(j)  
    //                              spanlist.cpp:1498 (3)
    //         004be6b2     MOV        this,dword ptr [ESI + 0x8]
    //                              spanlist.cpp:1502 (13)
    //         004be6b5     MOV        EAX,dword ptr [ESI]
    //         004be6b7     AND        this,EBP
    //         004be6b9     MOV        dword ptr [ESI + 0x8],this
    //         004be6bc     MOV        this,dword ptr [ESI + 0xc]
    //         004be6bf     OR         this,0x3
    //                              spanlist.cpp:1503 (7)
    //         004be6c2     TEST       EAX,EAX
    //         004be6c4     MOV        dword ptr [ESI + 0xc],this
    //         004be6c7     JZ         LAB_004be716
    //                              spanlist.cpp:1505 (14)
    //         004be6c9     MOV        EDX,dword ptr [EAX + 0x8]
    //         004be6cc     AND        EDX,0x7ffffffc
    //         004be6d2     DEC        EDX
    //         004be6d3     CMP        this,EDX
    //         004be6d5     JL         LAB_004be712
    //                              spanlist.cpp:1507 (9)
    //         004be6d7     MOV        this,dword ptr [EAX + 0xc]
    //         004be6da     OR         this,0x3
    //         004be6dd     MOV        dword ptr [ESI + 0xc],this
    //                              spanlist.cpp:1508 (7)
    //         004be6e0     MOV        EDX,dword ptr [EAX]
    //         004be6e2     MOV        dword ptr [ESI],EDX
    //         004be6e4     MOV        this,dword ptr [EDI + 0x40]
    //                              spanlist.cpp:1510 (12)
    //         004be6e7     MOV        EDX,dword ptr [this->VSList.Zone_Ptrs + EBX*0x4]
    //         004be6ea     LEA        this,[this->VSList.Zone_Ptrs + EBX*0x4]
    //         004be6ed     CMP        EAX,EDX
    //         004be6ef     JNZ        LAB_004be6f3
    //         004be6f1     MOV        dword ptr [this->VSList.Zone_Ptrs],ESI
    //                               LAB_004be6f3                                                 XREF[1]:     004be6ef(j)  
    //                              spanlist.cpp:1512 (9)
    //         004be6f3     MOV        this,dword ptr [EAX]
    //         004be6f5     TEST       this,this
    //         004be6f7     JZ         LAB_004be6fc
    //         004be6f9     MOV        dword ptr [ECX + this+0x4],ESI
    //                               LAB_004be6fc                                                 XREF[1]:     004be6f7(j)  
    //                              spanlist.cpp:1513 (11)
    //         004be6fc     PUSH       EAX
    //         004be6fd     MOV        this,EDI
    //         004be6ff     CALL       TSpan_Node_List::FreeNode                        void FreeNode(TSpan_Node_List * this, VSpan_N
    //         004be704     MOV        EDX,dword ptr [EDI + 0x4c]
    //                              spanlist.cpp:1514 (9)
    //         004be707     MOV        this,dword ptr [EDX + EBX*0x4]
    //         004be70a     LEA        EAX,[EDX + EBX*0x4]
    //         004be70d     DEC        this
    //         004be70e     MOV        dword ptr [EAX],this
    //                              spanlist.cpp:1518 (2)
    //         004be710     JMP        LAB_004be718
    //                               LAB_004be712                                                 XREF[1]:     004be6d5(j)  
    //                              spanlist.cpp:1520 (2)
    //         004be712     MOV        ESI,dword ptr [ESI]
    //                              spanlist.cpp:1523 (2)
    //         004be714     JMP        LAB_004be718
    //                               LAB_004be716                                                 XREF[1]:     004be6c7(j)  
    //                              spanlist.cpp:1525 (2)
    //         004be716     XOR        ESI,ESI
    //                               LAB_004be718                                                 XREF[2]:     004be710(j), 004be714(j)  
    //                              spanlist.cpp:1496 (4)
    //         004be718     TEST       ESI,ESI
    //         004be71a     JNZ        LAB_004be6b2
    //                               LAB_004be71c                                                 XREF[1]:     004be6b0(j)  
    //                              spanlist.cpp:1530 (17)
    //         004be71c     MOV        EAX,dword ptr [EDI + 0x3c]
    //         004be71f     MOV        EDX,dword ptr [EDI + 0x44]
    //         004be722     MOV        this,dword ptr [EAX + EBX*0x4]
    //         004be725     INC        EBX
    //         004be726     MOV        EAX,dword ptr [ECX + this+0x8]
    //         004be729     MOV        dword ptr [EDX + EBX*0x4 + -0x4],EAX
    //                              spanlist.cpp:1531 (30)
    //         004be72d     MOV        this,dword ptr [EDI + 0x40]
    //         004be730     MOV        EAX,dword ptr [EDI + 0x48]
    //         004be733     MOV        EDX,dword ptr [this->VSList.Zone_Ptrs + EBX*0x
    //         004be737     MOV        this,dword ptr [EDX + 0xc]
    //         004be73a     MOV        dword ptr [EAX + EBX*0x4 + -0x4],this
    //         004be73e     MOV        EAX,dword ptr [EDI + 0x50]
    //         004be741     CMP        EBX,EAX
    //         004be743     JL         LAB_004be6a8
    //         004be749     POP        EBP
    //         004be74a     POP        ESI
    //                               LAB_004be74b                                                 XREF[1]:     004be69b(j)  
    //                              spanlist.cpp:1536 (3)
    //         004be74b     POP        EDI
    //         004be74c     POP        EBX
    //         004be74d     RET
}

// Offset: 0x004BE750
void ScrollSpansHorizontally(TSpan_List_Manager* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TSpan_List_Manager::ScrollSpansHorizontally(int,int)                          *
    //                              *********************************************************************************************************
    //                              void __thiscall ScrollSpansHorizontally(TSpan_List_Manager * this, i
    //              void              <VOID>         <RETURN>
    //              TSpan_List_Man    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[3]:     004be756(R), 004be7ae(R), 004be7fb(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[2]:     004be769(R), 004be7b8(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     004be79c(W), 004be7f7(R), 004be805(W), 004be831(R)  
    //              int               Stack[-0x8]:4  y                         XREF[3]:     004be75f(W), 004be7e3(R), 004be815(R)  
    //                               ?ScrollSpansHorizontally@TSpan_List_Manager@@QAEXHH@Z
    //                               TSpan_List_Manager::ScrollSpansHorizontally
    //                              spanlist.cpp:1544 (6)
    //         004be750     SUB        ESP,0x8
    //         004be753     PUSH       EBX
    //         004be754     MOV        EBX,this
    //                              spanlist.cpp:1549 (19)
    //         004be756     MOV        this,dword ptr [ESP + param_1]
    //         004be75a     PUSH       EBP
    //         004be75b     PUSH       ESI
    //         004be75c     PUSH       EDI
    //         004be75d     TEST       this,this
    //         004be75f     MOV        dword ptr [ESP + y],EBX
    //         004be763     JZ         LAB_004be80b
    //                              spanlist.cpp:1553 (8)
    //         004be769     MOV        EAX,dword ptr [ESP + param_2]
    //         004be76d     TEST       EAX,EAX
    //         004be76f     JZ         LAB_004be795
    //                              spanlist.cpp:1555 (19)
    //         004be771     MOV        EAX,this
    //         004be773     MOV        EDI,dword ptr [EBX + 0x58]
    //         004be776     CDQ
    //         004be777     XOR        EAX,EDX
    //         004be779     SUB        EAX,EDX
    //         004be77b     MOV        EDX,dword ptr [EBX + 0x5c]
    //         004be77e     SUB        EDX,EDI
    //         004be780     CMP        EAX,EDX
    //         004be782     JLE        LAB_004be795
    //                              spanlist.cpp:1557 (7)
    //         004be784     MOV        this,EBX
    //         004be786     CALL       TSpan_List_Manager::ResetAll                     void ResetAll(TSpan_List_Manager * this)
    //                              spanlist.cpp:1608 (10)
    //         004be78b     POP        EDI
    //         004be78c     POP        ESI
    //         004be78d     POP        EBP
    //         004be78e     POP        EBX
    //         004be78f     ADD        ESP,0x8
    //         004be792     RET        0x8
    //                               LAB_004be795                                                 XREF[2]:     004be76f(j), 004be782(j)  
    //                              spanlist.cpp:1564 (13)
    //         004be795     MOV        EAX,dword ptr [EBX + 0x50]
    //         004be798     XOR        EDX,EDX
    //         004be79a     TEST       EAX,EAX
    //         004be79c     MOV        dword ptr [ESP + local_4],EDX
    //         004be7a0     JLE        LAB_004be80b
    //                               LAB_004be7a2                                                 XREF[1]:     004be809(j)  
    //                              spanlist.cpp:1566 (6)
    //         004be7a2     MOV        EAX,dword ptr [EBX + 0x3c]
    //         004be7a5     MOV        EAX,dword ptr [EAX + EDX*0x4]
    //                              spanlist.cpp:1568 (10)
    //         004be7a8     TEST       EAX,EAX
    //         004be7aa     JZ         LAB_004be7ff
    //         004be7ac     JMP        LAB_004be7b2
    //                               LAB_004be7ae                                                 XREF[1]:     004be7f5(j)  
    //         004be7ae     MOV        this,dword ptr [ESP + param_1]
    //                               LAB_004be7b2                                                 XREF[1]:     004be7ac(j)  
    //                              spanlist.cpp:1570 (3)
    //         004be7b2     MOV        EDI,dword ptr [EAX + 0x8]
    //                              spanlist.cpp:1571 (3)
    //         004be7b5     MOV        ESI,dword ptr [EAX + 0xc]
    //                              spanlist.cpp:1575 (17)
    //         004be7b8     MOV        EDX,dword ptr [ESP + param_2]
    //         004be7bc     MOV        EBP,dword ptr [EAX]
    //         004be7be     ADD        EDI,this
    //         004be7c0     ADD        ESI,this
    //         004be7c2     MOV        this,dword ptr [EAX + 0x4]
    //         004be7c5     TEST       EDX,EDX
    //         004be7c7     JZ         LAB_004be7e7
    //                              spanlist.cpp:1579 (14)
    //         004be7c9     MOV        EDX,dword ptr [EBX + 0x58]
    //         004be7cc     CMP        ESI,EDX
    //         004be7ce     JL         LAB_004be819
    //         004be7d0     MOV        EBX,dword ptr [EBX + 0x5c]
    //         004be7d3     CMP        EDI,EBX
    //         004be7d5     JG         LAB_004be815
    //                              spanlist.cpp:1594 (6)
    //         004be7d7     CMP        EDI,EDX
    //         004be7d9     JGE        LAB_004be7dd
    //         004be7db     MOV        EDI,EDX
    //                               LAB_004be7dd                                                 XREF[1]:     004be7d9(j)  
    //                              spanlist.cpp:1595 (6)
    //         004be7dd     CMP        ESI,EBX
    //         004be7df     JLE        LAB_004be7e3
    //         004be7e1     MOV        ESI,EBX
    //                               LAB_004be7e3                                                 XREF[1]:     004be7df(j)  
    //                              spanlist.cpp:1590 (4)
    //         004be7e3     MOV        EBX,dword ptr [ESP + y]
    //                               LAB_004be7e7                                                 XREF[2]:     004be7c7(j), 004be840(j)  
    //                              spanlist.cpp:1599 (4)
    //         004be7e7     TEST       EAX,EAX
    //         004be7e9     JZ         LAB_004be7f1
    //                              spanlist.cpp:1601 (3)
    //         004be7eb     MOV        dword ptr [EAX + 0x8],EDI
    //                              spanlist.cpp:1602 (5)
    //         004be7ee     MOV        dword ptr [EAX + 0xc],ESI
    //                               LAB_004be7f1                                                 XREF[1]:     004be7e9(j)  
    //         004be7f1     TEST       EBP,EBP
    //                              spanlist.cpp:1605 (24)
    //         004be7f3     MOV        EAX,EBP
    //         004be7f5     JNZ        LAB_004be7ae
    //         004be7f7     MOV        EDX,dword ptr [ESP + local_4]
    //         004be7fb     MOV        this,dword ptr [ESP + param_1]
    //                               LAB_004be7ff                                                 XREF[1]:     004be7aa(j)  
    //         004be7ff     MOV        EAX,dword ptr [EBX + 0x50]
    //         004be802     INC        EDX
    //         004be803     CMP        EDX,EAX
    //         004be805     MOV        dword ptr [ESP + local_4],EDX
    //         004be809     JL         LAB_004be7a2
    //                               LAB_004be80b                                                 XREF[2]:     004be763(j), 004be7a0(j)  
    //                              spanlist.cpp:1608 (10)
    //         004be80b     POP        EDI
    //         004be80c     POP        ESI
    //         004be80d     POP        EBP
    //         004be80e     POP        EBX
    //         004be80f     ADD        ESP,0x8
    //         004be812     RET        0x8
    //                               LAB_004be815                                                 XREF[1]:     004be7d5(j)  
    //                              spanlist.cpp:1595 (4)
    //         004be815     MOV        EBX,dword ptr [ESP + y]
    //                               LAB_004be819                                                 XREF[1]:     004be7ce(j)  
    //                              spanlist.cpp:1583 (6)
    //         004be819     TEST       this,this
    //         004be81b     JZ         LAB_004be81f
    //         004be81d     MOV        dword ptr [this->VSList.Zone_Ptrs],EBP
    //                               LAB_004be81f                                                 XREF[1]:     004be81b(j)  
    //                              spanlist.cpp:1584 (7)
    //         004be81f     TEST       EBP,EBP
    //         004be821     JZ         LAB_004be826
    //         004be823     MOV        dword ptr [EBP + 0x4],this
    //                               LAB_004be826                                                 XREF[1]:     004be821(j)  
    //                              spanlist.cpp:1588 (18)
    //         004be826     PUSH       EAX
    //         004be827     MOV        this,EBX
    //         004be829     CALL       TSpan_Node_List::FreeNode                        void FreeNode(TSpan_Node_List * this, VSpan_N
    //         004be82e     MOV        this,dword ptr [EBX + 0x4c]
    //         004be831     MOV        EDX,dword ptr [ESP + local_4]
    //         004be835     LEA        EAX,[this->VSList.Zone_Ptrs + EDX*0x4]
    //                              spanlist.cpp:1589 (6)
    //         004be838     MOV        this,dword ptr [this->VSList.Zone_Ptrs + EDX*0
    //         004be83b     DEC        this
    //         004be83c     MOV        dword ptr [EAX],this
    //                              spanlist.cpp:1590 (4)
    //         004be83e     XOR        EAX,EAX
    //         004be840     JMP        LAB_004be7e7
}

// Offset: 0x004BE850
void ScrollSpansVertically(TSpan_List_Manager* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TSpan_List_Manager::ScrollSpansVertically(int,int)                            *
    //                              *********************************************************************************************************
    //                              void __thiscall ScrollSpansVertically(TSpan_List_Manager * this, int
    //              void              <VOID>         <RETURN>
    //              TSpan_List_Man    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[8]:     004be852(R), 004be870(W), 004be87d(W), 004be888(R), 
    //                                                                                     004be8ba(R), 004be921(W), 004be93b(W), 004be98b(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[7]:     004be864(R), 004be874(W), 004be882(W), 004be891(R), 
    //                                                                                     004be8c0(R), 004be941(W), 004be98f(R)  
    //                               ?ScrollSpansVertically@TSpan_List_Manager@@QAEXHH@Z
    //                               TSpan_List_Manager::ScrollSpansVertically
    //                              spanlist.cpp:1617 (2)
    //         004be850     PUSH       EBX
    //         004be851     PUSH       EBP
    //                              spanlist.cpp:1624 (18)
    //         004be852     MOV        EBP,dword ptr [ESP + param_1]
    //         004be856     PUSH       ESI
    //         004be857     PUSH       EDI
    //         004be858     XOR        EDI,EDI
    //         004be85a     CMP        EBP,EDI
    //         004be85c     MOV        ESI,this
    //         004be85e     JZ         LAB_004be9d3
    //                              spanlist.cpp:1628 (6)
    //         004be864     CMP        dword ptr [ESP + param_2],EDI
    //         004be868     JZ         LAB_004be87a
    //                              spanlist.cpp:1630 (3)
    //         004be86a     MOV        EAX,dword ptr [ESI + 0x60]
    //                              spanlist.cpp:1631 (11)
    //         004be86d     MOV        this,dword ptr [ESI + 0x64]
    //         004be870     MOV        dword ptr [ESP + param_1],EAX
    //         004be874     MOV        dword ptr [ESP + param_2],this
    //                              spanlist.cpp:1633 (2)
    //         004be878     JMP        LAB_004be886
    //                               LAB_004be87a                                                 XREF[1]:     004be868(j)  
    //                              spanlist.cpp:1636 (12)
    //         004be87a     MOV        EAX,dword ptr [ESI + 0x50]
    //         004be87d     MOV        dword ptr [ESP + param_1],EDI
    //         004be881     DEC        EAX
    //         004be882     MOV        dword ptr [ESP + param_2],EAX
    //                               LAB_004be886                                                 XREF[1]:     004be878(j)  
    //                              spanlist.cpp:1641 (21)
    //         004be886     MOV        EAX,EBP
    //         004be888     MOV        EBX,dword ptr [ESP + param_1]
    //         004be88c     CDQ
    //         004be88d     XOR        EAX,EDX
    //         004be88f     SUB        EAX,EDX
    //         004be891     MOV        EDX,dword ptr [ESP + param_2]
    //         004be895     SUB        EDX,EBX
    //         004be897     CMP        EAX,EDX
    //         004be899     JLE        LAB_004be8a9
    //                              spanlist.cpp:1643 (7)
    //         004be89b     MOV        this,ESI
    //         004be89d     CALL       TSpan_List_Manager::ResetAll                     void ResetAll(TSpan_List_Manager * this)
    //                              spanlist.cpp:1710 (7)
    //         004be8a2     POP        EDI
    //         004be8a3     POP        ESI
    //         004be8a4     POP        EBP
    //         004be8a5     POP        EBX
    //         004be8a6     RET        0x8
    //                               LAB_004be8a9                                                 XREF[1]:     004be899(j)  
    //                              spanlist.cpp:1650 (5)
    //         004be8a9     CMP        dword ptr [ESI + 0x50],EDI
    //         004be8ac     JLE        LAB_004be910
    //                              spanlist.cpp:1710 (2)
    //         004be8ae     MOV        EBX,EBP
    //                               LAB_004be8b0                                                 XREF[1]:     004be90e(j)  
    //                              spanlist.cpp:1652 (10)
    //         004be8b0     MOV        EAX,dword ptr [ESI + 0x3c]
    //         004be8b3     MOV        EAX,dword ptr [EAX + EDI*0x4]
    //         004be8b6     TEST       EAX,EAX
    //         004be8b8     JZ         LAB_004be907
    //                              spanlist.cpp:1655 (12)
    //         004be8ba     CMP        EBX,dword ptr [ESP + param_1]
    //         004be8be     JL         LAB_004be8c6
    //         004be8c0     CMP        EBX,dword ptr [ESP + param_2]
    //         004be8c4     JLE        LAB_004be907
    //                               LAB_004be8c6                                                 XREF[1]:     004be8be(j)  
    //                              spanlist.cpp:1657 (15)
    //         004be8c6     MOV        this,dword ptr [ESI + 0x40]
    //         004be8c9     MOV        EDX,dword ptr [this->VSList.Zone_Ptrs + EDI*0x4]
    //         004be8cc     MOV        this,ESI
    //         004be8ce     PUSH       EDX
    //         004be8cf     PUSH       EAX
    //         004be8d0     CALL       TSpan_Node_List::FreeThread                      int FreeThread(TSpan_Node_List * this, VSpan_
    //                              spanlist.cpp:1658 (10)
    //         004be8d5     MOV        EAX,dword ptr [ESI + 0x3c]
    //         004be8d8     MOV        dword ptr [EAX + EDI*0x4],0x0
    //                              spanlist.cpp:1659 (10)
    //         004be8df     MOV        this,dword ptr [ESI + 0x40]
    //         004be8e2     MOV        dword ptr [this->VSList.Zone_Ptrs + EDI*0x4],0x0
    //                              spanlist.cpp:1660 (10)
    //         004be8e9     MOV        EDX,dword ptr [ESI + 0x4c]
    //         004be8ec     MOV        dword ptr [EDX + EDI*0x4],0x0
    //                              spanlist.cpp:1661 (10)
    //         004be8f3     MOV        EAX,dword ptr [ESI + 0x44]
    //         004be8f6     MOV        dword ptr [EAX + EDI*0x4],0x0
    //                              spanlist.cpp:1662 (19)
    //         004be8fd     MOV        this,dword ptr [ESI + 0x48]
    //         004be900     MOV        dword ptr [this->VSList.Zone_Ptrs + EDI*0x4],0x0
    //                               LAB_004be907                                                 XREF[2]:     004be8b8(j), 004be8c4(j)  
    //         004be907     MOV        EAX,dword ptr [ESI + 0x50]
    //         004be90a     INC        EDI
    //         004be90b     INC        EBX
    //         004be90c     CMP        EDI,EAX
    //         004be90e     JL         LAB_004be8b0
    //                               LAB_004be910                                                 XREF[1]:     004be8ac(j)  
    //                              spanlist.cpp:1669 (4)
    //         004be910     TEST       EBP,EBP
    //         004be912     JLE        LAB_004be92a
    //                              spanlist.cpp:1671 (3)
    //         004be914     MOV        this,dword ptr [ESI + 0x50]
    //                              spanlist.cpp:1672 (4)
    //         004be917     XOR        EBX,EBX
    //         004be919     SUB        this,EBP
    //                              spanlist.cpp:1673 (4)
    //         004be91b     OR         EDI,0xffffffff
    //         004be91e     DEC        this
    //                              spanlist.cpp:1674 (6)
    //         004be91f     XOR        EAX,EAX
    //         004be921     MOV        dword ptr [ESP + param_1],EAX
    //                              spanlist.cpp:1675 (3)
    //         004be925     LEA        EDX,[EBP + -0x1]
    //                              spanlist.cpp:1677 (2)
    //         004be928     JMP        LAB_004be93f
    //                               LAB_004be92a                                                 XREF[1]:     004be912(j)  
    //                              spanlist.cpp:1680 (5)
    //         004be92a     MOV        EDX,dword ptr [ESI + 0x50]
    //         004be92d     MOV        this,EBP
    //                              spanlist.cpp:1682 (16)
    //         004be92f     MOV        EAX,EDX
    //         004be931     MOV        EDI,0x1
    //         004be936     SUB        EAX,EBP
    //         004be938     LEA        EBX,[EDX + -0x1]
    //         004be93b     MOV        dword ptr [ESP + param_1],EAX
    //                               LAB_004be93f                                                 XREF[1]:     004be928(j)  
    //                              spanlist.cpp:1688 (16)
    //         004be93f     ADD        EBX,EDI
    //         004be941     MOV        dword ptr [ESP + param_2],EDX
    //         004be945     CMP        this,EBX
    //         004be947     JZ         LAB_004be993
    //         004be949     LEA        EAX,[this->VSList.Zone_Ptrs + EBP*0x1]
    //         004be94c     SHL        EAX,0x2
    //                               LAB_004be94f                                                 XREF[1]:     004be989(j)  
    //                              spanlist.cpp:1692 (9)
    //         004be94f     MOV        EDX,dword ptr [ESI + 0x3c]
    //         004be952     MOV        EBP,dword ptr [EDX + this->VSList.Zone_Ptrs*0x4]
    //         004be955     MOV        dword ptr [EAX + EDX*0x1],EBP
    //                              spanlist.cpp:1693 (9)
    //         004be958     MOV        EDX,dword ptr [ESI + 0x40]
    //         004be95b     MOV        EBP,dword ptr [EDX + this->VSList.Zone_Ptrs*0x4]
    //         004be95e     MOV        dword ptr [EAX + EDX*0x1],EBP
    //                              spanlist.cpp:1694 (9)
    //         004be961     MOV        EDX,dword ptr [ESI + 0x4c]
    //         004be964     MOV        EBP,dword ptr [EDX + this->VSList.Zone_Ptrs*0x4]
    //         004be967     MOV        dword ptr [EAX + EDX*0x1],EBP
    //                              spanlist.cpp:1695 (9)
    //         004be96a     MOV        EDX,dword ptr [ESI + 0x44]
    //         004be96d     MOV        EBP,dword ptr [EDX + this->VSList.Zone_Ptrs*0x4]
    //         004be970     MOV        dword ptr [EAX + EDX*0x1],EBP
    //                              spanlist.cpp:1696 (32)
    //         004be973     MOV        EDX,dword ptr [ESI + 0x48]
    //         004be976     MOV        EBP,dword ptr [EDX + this->VSList.Zone_Ptrs*0x4]
    //         004be979     ADD        this,EDI
    //         004be97b     MOV        dword ptr [EAX + EDX*0x1],EBP
    //         004be97e     LEA        EDX,[EDI*0x4 + 0x0]
    //         004be985     ADD        EAX,EDX
    //         004be987     CMP        this,EBX
    //         004be989     JNZ        LAB_004be94f
    //         004be98b     MOV        EAX,dword ptr [ESP + param_1]
    //         004be98f     MOV        EDX,dword ptr [ESP + param_2]
    //                               LAB_004be993                                                 XREF[1]:     004be947(j)  
    //                              spanlist.cpp:1701 (4)
    //         004be993     CMP        EAX,EDX
    //         004be995     JG         LAB_004be9d3
    //                               LAB_004be997                                                 XREF[1]:     004be9d1(j)  
    //                              spanlist.cpp:1703 (14)
    //         004be997     MOV        this,dword ptr [ESI + 0x3c]
    //         004be99a     INC        EAX
    //         004be99b     CMP        EAX,EDX
    //         004be99d     MOV        dword ptr [this->VSList.Zone_Ptrs + EAX*0x4 + 
    //                              spanlist.cpp:1704 (11)
    //         004be9a5     MOV        this,dword ptr [ESI + 0x40]
    //         004be9a8     MOV        dword ptr [this->VSList.Zone_Ptrs + EAX*0x4 + 
    //                              spanlist.cpp:1705 (11)
    //         004be9b0     MOV        this,dword ptr [ESI + 0x4c]
    //         004be9b3     MOV        dword ptr [this->VSList.Zone_Ptrs + EAX*0x4 + 
    //                              spanlist.cpp:1706 (11)
    //         004be9bb     MOV        this,dword ptr [ESI + 0x44]
    //         004be9be     MOV        dword ptr [this->VSList.Zone_Ptrs + EAX*0x4 + 
    //                              spanlist.cpp:1707 (13)
    //         004be9c6     MOV        this,dword ptr [ESI + 0x48]
    //         004be9c9     MOV        dword ptr [this->VSList.Zone_Ptrs + EAX*0x4 + 
    //         004be9d1     JLE        LAB_004be997
    //                               LAB_004be9d3                                                 XREF[2]:     004be85e(j), 004be995(j)  
    //                              spanlist.cpp:1710 (7)
    //         004be9d3     POP        EDI
    //         004be9d4     POP        ESI
    //         004be9d5     POP        EBP
    //         004be9d6     POP        EBX
    //         004be9d7     RET        0x8
}

// Offset: 0x004BE9E0
int ValidateSpan(TSpan_List_Manager* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TSpan_List_Manager::ValidateSpan(int)                                          *
    //                              *********************************************************************************************************
    //                              int __thiscall ValidateSpan(TSpan_List_Manager * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              TSpan_List_Man    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[3]:     004be9e0(R), 004bea50(W), 004bea61(R)  
    //                               ?ValidateSpan@TSpan_List_Manager@@QAEHH@Z
    //                               TSpan_List_Manager::ValidateSpan
    //                              spanlist.cpp:1717 (29)
    //         004be9e0     MOV        EAX,dword ptr [ESP + param_1]
    //         004be9e4     PUSH       EBX
    //         004be9e5     PUSH       EBP
    //         004be9e6     XOR        EBP,EBP
    //         004be9e8     XOR        EBX,EBX
    //         004be9ea     PUSH       ESI
    //         004be9eb     TEST       EAX,EAX
    //         004be9ed     PUSH       EDI
    //         004be9ee     JL         LAB_004beab8
    //         004be9f4     CMP        EAX,dword ptr [ECX + this->Num_Lines]
    //         004be9f7     JGE        LAB_004beab8
    //                              spanlist.cpp:1726 (17)
    //         004be9fd     LEA        EDI,[EAX*0x4 + 0x0]
    //         004bea04     MOV        EAX,dword ptr [ECX + this->Line_Head_Ptrs]
    //         004bea07     MOV        EAX,dword ptr [EAX + EDI*0x1]
    //         004bea0a     TEST       EAX,EAX
    //         004bea0c     JNZ        LAB_004bea4a
    //                              spanlist.cpp:1729 (13)
    //         004bea0e     MOV        EDX,dword ptr [ECX + this->Line_Tail_Ptrs]
    //         004bea11     CMP        dword ptr [EDX + EDI*0x1],0x0
    //         004bea15     JNZ        LAB_004beab8
    //                              spanlist.cpp:1730 (13)
    //         004bea1b     MOV        EAX,dword ptr [ECX + this->Span_Count]
    //         004bea1e     CMP        dword ptr [EAX + EDI*0x1],0x0
    //         004bea22     JNZ        LAB_004beab8
    //                              spanlist.cpp:1731 (13)
    //         004bea28     MOV        EDX,dword ptr [ECX + this->LeftMostPx]
    //         004bea2b     CMP        dword ptr [EDX + EDI*0x1],0x0
    //         004bea2f     JNZ        LAB_004beab8
    //                              spanlist.cpp:1732 (14)
    //         004bea35     MOV        EAX,dword ptr [ECX + this->RightMostPx]
    //         004bea38     XOR        this,this
    //         004bea3a     CMP        dword ptr [EAX + EDI*0x1],0x0
    //         004bea3e     SETZ       this
    //         004bea41     MOV        EAX,this
    //                              spanlist.cpp:1781 (7)
    //         004bea43     POP        EDI
    //         004bea44     POP        ESI
    //         004bea45     POP        EBP
    //         004bea46     POP        EBX
    //         004bea47     RET        0x4
    //                               LAB_004bea4a                                                 XREF[1]:     004bea0c(j)  
    //                              spanlist.cpp:1737 (2)
    //         004bea4a     XOR        EDX,EDX
    //                               LAB_004bea4c                                                 XREF[1]:     004bea85(j)  
    //                              spanlist.cpp:1741 (1)
    //         004bea4c     INC        EBP
    //                              spanlist.cpp:1745 (9)
    //         004bea4d     CMP        EBP,0x1
    //         004bea50     MOV        dword ptr [ESP + param_1],EBP
    //         004bea54     JNZ        LAB_004bea65
    //                              spanlist.cpp:1747 (15)
    //         004bea56     MOV        ESI,dword ptr [ECX + this->LeftMostPx]
    //         004bea59     MOV        EBP,dword ptr [EAX + 0x8]
    //         004bea5c     CMP        EBP,dword ptr [ESI + EDI*0x1]
    //         004bea5f     JNZ        LAB_004beab8
    //         004bea61     MOV        EBP,dword ptr [ESP + param_1]
    //                               LAB_004bea65                                                 XREF[1]:     004bea54(j)  
    //                              spanlist.cpp:1752 (5)
    //         004bea65     CMP        dword ptr [EAX + 0x4],EDX
    //         004bea68     JNZ        LAB_004beab8
    //                              spanlist.cpp:1756 (10)
    //         004bea6a     MOV        ESI,dword ptr [EAX + 0x8]
    //         004bea6d     MOV        EDX,dword ptr [EAX + 0xc]
    //         004bea70     CMP        ESI,EDX
    //         004bea72     JG         LAB_004beab8
    //                              spanlist.cpp:1758 (5)
    //         004bea74     CMP        EBP,0x1
    //         004bea77     JLE        LAB_004bea7d
    //                              spanlist.cpp:1760 (4)
    //         004bea79     CMP        ESI,EBX
    //         004bea7b     JLE        LAB_004beab8
    //                               LAB_004bea7d                                                 XREF[1]:     004bea77(j)  
    //                              spanlist.cpp:1763 (2)
    //         004bea7d     MOV        EBX,EDX
    //                              spanlist.cpp:1765 (2)
    //         004bea7f     MOV        EDX,EAX
    //                              spanlist.cpp:1766 (6)
    //         004bea81     MOV        EAX,dword ptr [EAX]
    //         004bea83     TEST       EAX,EAX
    //         004bea85     JNZ        LAB_004bea4c
    //                              spanlist.cpp:1771 (8)
    //         004bea87     MOV        EAX,dword ptr [ECX + this->Span_Count]
    //         004bea8a     CMP        dword ptr [EAX + EDI*0x1],EBP
    //         004bea8d     JNZ        LAB_004beab8
    //                              spanlist.cpp:1773 (8)
    //         004bea8f     MOV        EAX,dword ptr [ECX + this->Line_Tail_Ptrs]
    //         004bea92     CMP        dword ptr [EAX + EDI*0x1],EDX
    //         004bea95     JNZ        LAB_004beab8
    //                              spanlist.cpp:1775 (13)
    //         004bea97     MOV        EAX,dword ptr [ECX + this->RightMostPx]
    //         004bea9a     MOV        ESI,dword ptr [EDX + 0xc]
    //         004bea9d     MOV        EAX,dword ptr [EAX + EDI*0x1]
    //         004beaa0     CMP        ESI,EAX
    //         004beaa2     JNZ        LAB_004beab8
    //                              spanlist.cpp:1777 (13)
    //         004beaa4     MOV        this,dword ptr [ECX + this->LeftMostPx]
    //         004beaa7     XOR        EDX,EDX
    //         004beaa9     CMP        dword ptr [this->VSList.Zone_Ptrs + EDI*0x1],EAX
    //         004beaac     SETLE      DL
    //         004beaaf     MOV        EAX,EDX
    //                              spanlist.cpp:1781 (16)
    //         004beab1     POP        EDI
    //         004beab2     POP        ESI
    //         004beab3     POP        EBP
    //         004beab4     POP        EBX
    //         004beab5     RET        0x4
    //                               LAB_004beab8                                                 XREF[12]:    004be9ee(j), 004be9f7(j), 
    //                                                                                                         004bea15(j), 004bea22(j), 
    //                                                                                                         004bea2f(j), 004bea5f(j), 
    //                                                                                                         004bea68(j), 004bea72(j), 
    //                                                                                                         004bea7b(j), 004bea8d(j), 
    //                                                                                                         004bea95(j), 004beaa2(j)  
    //         004beab8     POP        EDI
    //         004beab9     POP        ESI
    //         004beaba     POP        EBP
    //         004beabb     XOR        EAX,EAX
    //         004beabd     POP        EBX
    //         004beabe     RET        0x4
}

// Offset: 0x004BEAD0
int DecodeLine(TSpan_List_Manager* this_, uchar* param_2, int param_3, uchar param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TSpan_List_Manager::DecodeLine(unsigned char *,int,unsigned char,int)          *
    //                              *********************************************************************************************************
    //                              int __thiscall DecodeLine(TSpan_List_Manager * this, uchar * param_1
    //              int               EAX:4          <RETURN>
    //              TSpan_List_Man    ECX:4 (auto)   this
    //              uchar *           Stack[0x4]:4   param_1                   XREF[1]:     004beae2(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004bead3(R)  
    //              uchar             Stack[0xc]:1   param_3                   XREF[1]:     004beae7(R)  
    //              int               Stack[0x10]:4  param_4
    //                               ?DecodeLine@TSpan_List_Manager@@QAEHPAEHEH@Z                 XREF[2]:     take_snapshot:004bed27(c), 
    //                               TSpan_List_Manager::DecodeLine                                            take_snapshot:004bed61(c)  
    //                              spanlist.cpp:1787 (13)
    //         004bead0     MOV        this,dword ptr [ECX + this->Line_Head_Ptrs]
    //         004bead3     MOV        EDX,dword ptr [ESP + param_2]
    //         004bead7     PUSH       ESI
    //         004bead8     XOR        EAX,EAX
    //         004beada     MOV        ESI,dword ptr [this->VSList.Zone_Ptrs + EDX*0x4]
    //                              spanlist.cpp:1797 (14)
    //         004beadd     TEST       ESI,ESI
    //         004beadf     JZ         LAB_004beb06
    //         004beae1     PUSH       EDI
    //         004beae2     MOV        EDI,dword ptr [ESP + param_1]
    //         004beae6     PUSH       EBX
    //         004beae7     MOV        BL,byte ptr [ESP + param_3]
    //                               LAB_004beaeb                                                 XREF[1]:     004beb02(j)  
    //                              spanlist.cpp:1799 (3)
    //         004beaeb     MOV        this,dword ptr [ESI + 0x8]
    //                              spanlist.cpp:1800 (3)
    //         004beaee     MOV        EDX,dword ptr [ESI + 0xc]
    //                              spanlist.cpp:1802 (12)
    //         004beaf1     CMP        this,EDX
    //         004beaf3     JG         LAB_004beafd
    //                               LAB_004beaf5                                                 XREF[1]:     004beafb(j)  
    //         004beaf5     ADD        byte ptr [this->VSList.Zone_Ptrs + EDI*0x1],BL
    //         004beaf8     INC        this
    //         004beaf9     CMP        this,EDX
    //         004beafb     JLE        LAB_004beaf5
    //                               LAB_004beafd                                                 XREF[1]:     004beaf3(j)  
    //                              spanlist.cpp:1804 (9)
    //         004beafd     MOV        ESI,dword ptr [ESI]
    //         004beaff     INC        EAX
    //         004beb00     TEST       ESI,ESI
    //         004beb02     JNZ        LAB_004beaeb
    //         004beb04     POP        EBX
    //         004beb05     POP        EDI
    //                               LAB_004beb06                                                 XREF[1]:     004beadf(j)  
    //                              spanlist.cpp:1809 (4)
    //         004beb06     POP        ESI
    //         004beb07     RET        0x10
}

// Offset: 0x004BEB10
void take_snapshot(TSpan_List_Manager* this_, char* param_2, int* param_3, TDrawArea* param_4, int param_5, TSpan_List_Manager** param_6, int* param_7, int param_8) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TSpan_List_Manager::take_snapshot(char *,int &,class TDrawArea *,int,class... *
    //                              *********************************************************************************************************
    //                              void __thiscall take_snapshot(TSpan_List_Manager * this, char * para
    //              void              <VOID>         <RETURN>
    //              TSpan_List_Man    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     004bec24(R)  
    //              int *             Stack[0x8]:4   param_2                   XREF[1]:     004bec13(R)  
    //              TDrawArea *       Stack[0xc]:4   param_3                   XREF[1]:     004beb76(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     004bed18(R)  
    //              TSpan_List_Man    Stack[0x14]:4  param_5                   XREF[2]:     004beb31(R), 004bed37(R)  
    //              int *             Stack[0x18]:4  param_6                   XREF[1]:     004bed3e(R)  
    //              int               Stack[0x1c]:4  param_7                   XREF[3]:     004beb19(R), 004bed2c(R), 004bed45(R)  
    //              tagPALETTEENTR    Stack[-0x404   thePal                    XREF[0,1]:   004beb61(*)  
    //              tagRGBQUAD[256]   Stack[-0x804   bmPAL                     XREF[0,1]:   004becdb(*)  
    //              char[60]          Stack[-0x840   BMPFile                   XREF[1,4]:   004bebcc(W), 004bec32(*), 004bec42(*), 004bec51(*), 
    //                                                                                     004bec93(*)  
    //              tagBITMAPINFOH    Stack[-0x868   bmIH                      XREF[0,11]:  004beb9e(W), 004beccb(*), 004beba6(W), 004beb57(W), 
    //                                                                                     004bebaa(W), 004bebb1(W), 004bebb8(W), 004bebbc(W), 
    //                                                                                     004bebc0(W), 004bebc4(W), 004bebc8(W)  
    //              tagBITMAPFILEH    Stack[-0x878   bmFH                      XREF[2,5]:   004beb25(W), 004bed21(R), 004beb85(W), 004becbb(*), 
    //                                                                                     004beb72(W), 004beb8c(W), 004beb91(W)  
    //              undefined4        Stack[-0x87c   local_87c                 XREF[2]:     004beb81(W), 004bed74(R)  
    //              int               Stack[-0x880   bmWide                    XREF[3]:     004becb1(W), 004bed78(R), 004bed8e(R)  
    //              int               Stack[-0x884   infile                    XREF[3]:     004beb7d(W), 004bed14(R), 004bed54(R)  
    //              int               Stack[-0x888   Width                     XREF[5]:     004beb50(W), 004becee(R), 004bed50(W), 004bed66(R), 
    //                                                                                     004bed6e(W)  
    //              int               Stack[-0x88c   Height
    //                               ?take_snapshot@TSpan_List_Manager@@QAEXPADAAHPAVTDrawArea@@
    //                               TSpan_List_Manager::take_snapshot
    //                              spanlist.cpp:1817 (9)
    //         004beb10     SUB        ESP,0x888
    //         004beb16     PUSH       EBX
    //         004beb17     PUSH       EBP
    //         004beb18     PUSH       ESI
    //                              spanlist.cpp:1836 (18)
    //         004beb19     MOV        ESI,dword ptr [ESP + param_7]
    //         004beb20     XOR        EBX,EBX
    //         004beb22     PUSH       EDI
    //         004beb23     CMP        ESI,EBX
    //         004beb25     MOV        dword ptr [ESP + bmFH.bfType],this
    //         004beb29     JLE        LAB_004beb48
    //                              spanlist.cpp:1838 (6)
    //         004beb2b     XOR        EAX,EAX
    //         004beb2d     CMP        ESI,EBX
    //         004beb2f     JLE        LAB_004beb48
    //                              spanlist.cpp:1950 (7)
    //         004beb31     MOV        EDX,dword ptr [ESP + param_5]
    //                               LAB_004beb38                                                 XREF[1]:     004beb46(j)  
    //                              spanlist.cpp:1839 (16)
    //         004beb38     CMP        dword ptr [EDX],EBX
    //         004beb3a     JZ         LAB_004beda4
    //         004beb40     INC        EAX
    //         004beb41     ADD        EDX,0x4
    //         004beb44     CMP        EAX,ESI
    //         004beb46     JL         LAB_004beb38
    //                               LAB_004beb48                                                 XREF[2]:     004beb29(j), 004beb2f(j)  
    //                              spanlist.cpp:1845 (6)
    //         004beb48     MOV        EAX,dword ptr [ECX + this->Num_Pixels]
    //         004beb4b     MOV        EDX,dword ptr [ECX + this->Num_Lines]
    //                              spanlist.cpp:1853 (9)
    //         004beb4e     MOV        this,EDX
    //         004beb50     MOV        dword ptr [ESP + Width],EDX
    //         004beb54     LEA        ESI,[EAX + 0x3]
    //                              spanlist.cpp:1862 (10)
    //         004beb57     MOV        dword ptr [ESP + bmIH.biPlanes],EDX
    //         004beb5b     AND        ESI,0xfffc
    //                              spanlist.cpp:1874 (116)
    //         004beb61     LEA        EDX=>thePal[1],[ESP + 0x498]
    //         004beb68     IMUL       this,ESI
    //         004beb6b     ADD        this,0x436
    //         004beb71     PUSH       EDX
    //         004beb72     MOV        dword ptr [ESP + bmFH.bfReserved1],this
    //         004beb76     MOV        this,dword ptr [ESP + param_3]
    //         004beb7d     MOV        dword ptr [ESP + infile],EAX
    //         004beb81     MOV        dword ptr [ESP + local_87c],ESI
    //         004beb85     MOV        word ptr [ESP + bmFH+0x4],0x4d42
    //         004beb8c     MOV        word ptr [ESP + bmFH.bfOffBits],BX
    //         004beb91     MOV        word ptr [ESP + bmFH+0xc],BX
    //         004beb96     MOV        dword ptr [ESP + Stack[-0x86a]],0x436
    //         004beb9e     MOV        dword ptr [ESP + bmIH.biWidth],0x28
    //         004beba6     MOV        dword ptr [ESP + bmIH.biHeight],EAX
    //         004bebaa     MOV        word ptr [ESP + bmIH.biCompression],0x1
    //         004bebb1     MOV        word ptr [ESP + bmIH+0x12],0x8
    //         004bebb8     MOV        dword ptr [ESP + bmIH.biSizeImage],EBX
    //         004bebbc     MOV        dword ptr [ESP + bmIH.biXPelsPerMeter],EBX
    //         004bebc0     MOV        dword ptr [ESP + bmIH.biYPelsPerMeter],EBX
    //         004bebc4     MOV        dword ptr [ESP + bmIH.biClrUsed],EBX
    //         004bebc8     MOV        dword ptr [ESP + bmIH.biClrImportant],EBX
    //         004bebcc     MOV        dword ptr [ESP + BMPFile[0]],EBX
    //         004bebd0     CALL       TDrawArea::GetPalette                            void GetPalette(TDrawArea * this, tagPALETTEE
    //                              spanlist.cpp:1878 (9)
    //         004bebd5     XOR        EAX,EAX
    //                               LAB_004bebd7                                                 XREF[1]:     004bec11(j)  
    //         004bebd7     MOV        this,byte ptr [ESP + EAX*0x1 + 0x49a]
    //                              spanlist.cpp:1879 (14)
    //         004bebde     MOV        DL,byte ptr [ESP + EAX*0x1 + 0x499]
    //         004bebe5     MOV        byte ptr [ESP + EAX*0x1 + 0x98],this
    //                              spanlist.cpp:1880 (21)
    //         004bebec     MOV        this,byte ptr [ESP + EAX*0x1 + 0x498]
    //         004bebf3     MOV        byte ptr [ESP + EAX*0x1 + 0x99],DL
    //         004bebfa     MOV        byte ptr [ESP + EAX*0x1 + 0x9a],this
    //                              spanlist.cpp:1881 (18)
    //         004bec01     MOV        byte ptr [ESP + EAX*0x1 + 0x9b],0x0
    //         004bec09     ADD        EAX,0x4
    //         004bec0c     CMP        EAX,0x400
    //         004bec11     JL         LAB_004bebd7
    //                              spanlist.cpp:1888 (17)
    //         004bec13     MOV        EBP,dword ptr [ESP + param_2]
    //         004bec1a     XOR        EDI,EDI
    //         004bec1c     CMP        dword ptr [EBP],EBX
    //         004bec1f     JGE        LAB_004bec24
    //         004bec21     MOV        dword ptr [EBP],EBX
    //                               LAB_004bec24                                                 XREF[2]:     004bec1f(j), 004bec7b(j)  
    //                              spanlist.cpp:1892 (11)
    //         004bec24     MOV        EAX,dword ptr [ESP + param_1]
    //         004bec2b     CMP        EAX,EBX
    //         004bec2d     JNZ        LAB_004bec3f
    //                              spanlist.cpp:1893 (14)
    //         004bec2f     MOV        EDX,dword ptr [EBP]
    //         004bec32     LEA        EAX=>BMPFile[4],[ESP + 0x5c]
    //         004bec36     PUSH       EDX
    //         004bec37     PUSH       s_C:\AOE_%03d.BMP                                = "C:\\AOE_%03d.BMP"
    //         004bec3c     PUSH       EAX
    //                              spanlist.cpp:1894 (2)
    //         004bec3d     JMP        LAB_004bec49
    //                               LAB_004bec3f                                                 XREF[1]:     004bec2d(j)  
    //                              spanlist.cpp:1895 (18)
    //         004bec3f     MOV        this,dword ptr [EBP]
    //         004bec42     LEA        EDX=>BMPFile[4],[ESP + 0x5c]
    //         004bec46     PUSH       this
    //         004bec47     PUSH       EAX
    //         004bec48     PUSH       EDX
    //                               LAB_004bec49                                                 XREF[1]:     004bec3d(j)  
    //         004bec49     CALL       sprintf                                          undefined sprintf()
    //         004bec4e     ADD        ESP,0xc
    //                              spanlist.cpp:1899 (20)
    //         004bec51     LEA        EAX=>BMPFile[4],[ESP + 0x5c]
    //         004bec55     INC        EDI
    //         004bec56     PUSH       EBX
    //         004bec57     PUSH       EAX
    //         004bec58     CALL       __open                                           undefined __open()
    //         004bec5d     ADD        ESP,0x8
    //         004bec60     CMP        EAX,-0x1
    //         004bec63     JZ         LAB_004bec8a
    //                              spanlist.cpp:1901 (3)
    //         004bec65     MOV        this,dword ptr [EBP]
    //                              spanlist.cpp:1902 (13)
    //         004bec68     PUSH       EAX
    //         004bec69     INC        this
    //         004bec6a     MOV        dword ptr [EBP],this
    //         004bec6d     CALL       close                                            undefined close()
    //         004bec72     ADD        ESP,0x4
    //                              spanlist.cpp:1907 (8)
    //         004bec75     CMP        EDI,0x3e8
    //         004bec7b     JLE        LAB_004bec24
    //                              spanlist.cpp:1950 (13)
    //         004bec7d     POP        EDI
    //         004bec7e     POP        ESI
    //         004bec7f     POP        EBP
    //         004bec80     POP        EBX
    //         004bec81     ADD        ESP,0x888
    //         004bec87     RET        0x1c
    //                               LAB_004bec8a                                                 XREF[1]:     004bec63(j)  
    //                              spanlist.cpp:1912 (9)
    //         004bec8a     PUSH       ESI
    //         004bec8b     CALL       malloc                                           undefined malloc()
    //         004bec90     ADD        ESP,0x4
    //                              spanlist.cpp:1914 (40)
    //         004bec93     LEA        this=>BMPFile[4],[ESP + 0x5c]
    //         004bec97     MOV        EBP,EAX
    //         004bec99     PUSH       0x180
    //         004bec9e     PUSH       0x8301
    //         004beca3     PUSH       this
    //         004beca4     CALL       __open                                           undefined __open()
    //         004beca9     MOV        EDI,EAX
    //         004becab     ADD        ESP,0xc
    //         004becae     CMP        EDI,-0x1
    //         004becb1     MOV        dword ptr [ESP + bmWide],EDI
    //         004becb5     JZ         LAB_004bed9b
    //                              spanlist.cpp:1916 (16)
    //         004becbb     LEA        EDX=>bmFH+0x4,[ESP + 0x24]
    //         004becbf     PUSH       0xe
    //         004becc1     PUSH       EDX
    //         004becc2     PUSH       EDI
    //         004becc3     CALL       write                                            undefined write()
    //         004becc8     ADD        ESP,0xc
    //                              spanlist.cpp:1917 (16)
    //         004beccb     LEA        EAX=>bmIH.biWidth,[ESP + 0x34]
    //         004beccf     PUSH       0x28
    //         004becd1     PUSH       EAX
    //         004becd2     PUSH       EDI
    //         004becd3     CALL       write                                            undefined write()
    //         004becd8     ADD        ESP,0xc
    //                              spanlist.cpp:1918 (19)
    //         004becdb     LEA        this=>bmPAL[1],[ESP + 0x98]
    //         004bece2     PUSH       0x400
    //         004bece7     PUSH       this
    //         004bece8     PUSH       EDI
    //         004bece9     CALL       write                                            undefined write()
    //                              spanlist.cpp:1922 (18)
    //         004becee     MOV        EDX,dword ptr [ESP + Width]
    //         004becf2     ADD        ESP,0xc
    //         004becf5     LEA        EBX,[EDX + -0x1]
    //         004becf8     TEST       EBX,EBX
    //         004becfa     JL         LAB_004bed92
    //                               LAB_004bed00                                                 XREF[1]:     004bed88(j)  
    //                              spanlist.cpp:1924 (20)
    //         004bed00     MOV        this,ESI
    //         004bed02     XOR        EAX,EAX
    //         004bed04     MOV        EDX,this
    //         004bed06     MOV        EDI,EBP
    //         004bed08     SHR        this,0x2
    //         004bed0b     STOSD.REP  ES:EDI
    //         004bed0d     MOV        this,EDX
    //         004bed0f     AND        this,0x3
    //         004bed12     STOSB.REP  ES:EDI
    //                              spanlist.cpp:1928 (24)
    //         004bed14     MOV        EAX,dword ptr [ESP + infile]
    //         004bed18     MOV        this,dword ptr [ESP + param_4]
    //         004bed1f     PUSH       EAX
    //         004bed20     PUSH       this
    //         004bed21     MOV        this,dword ptr [ESP + bmFH.bfType]
    //         004bed25     PUSH       EBX
    //         004bed26     PUSH       EBP
    //         004bed27     CALL       TSpan_List_Manager::DecodeLine                   int DecodeLine(TSpan_List_Manager * this, uch
    //                              spanlist.cpp:1932 (11)
    //         004bed2c     MOV        EAX,dword ptr [ESP + param_7]
    //         004bed33     TEST       EAX,EAX
    //         004bed35     JLE        LAB_004bed78
    //                              spanlist.cpp:1950 (61)
    //         004bed37     MOV        ESI,dword ptr [ESP + param_5]
    //         004bed3e     MOV        EDI,dword ptr [ESP + param_6]
    //         004bed45     MOV        EDX,dword ptr [ESP + param_7]
    //         004bed4c     MOV        EAX,ESI
    //         004bed4e     SUB        EDI,EAX
    //         004bed50     MOV        dword ptr [ESP + Width],EDX
    //                               LAB_004bed54                                                 XREF[1]:     004bed72(j)  
    //         004bed54     MOV        EAX,dword ptr [ESP + infile]
    //         004bed58     MOV        this,byte ptr [EDI + ESI*0x1]
    //         004bed5b     PUSH       EAX
    //         004bed5c     PUSH       this
    //         004bed5d     MOV        this,dword ptr [ESI]
    //         004bed5f     PUSH       EBX
    //         004bed60     PUSH       EBP
    //         004bed61     CALL       TSpan_List_Manager::DecodeLine                   int DecodeLine(TSpan_List_Manager * this, uch
    //         004bed66     MOV        EAX,dword ptr [ESP + Width]
    //         004bed6a     ADD        ESI,0x4
    //         004bed6d     DEC        EAX
    //         004bed6e     MOV        dword ptr [ESP + Width],EAX
    //         004bed72     JNZ        LAB_004bed54
    //                              spanlist.cpp:1934 (4)
    //         004bed74     MOV        ESI,dword ptr [ESP + local_87c]
    //                               LAB_004bed78                                                 XREF[1]:     004bed35(j)  
    //                              spanlist.cpp:1940 (22)
    //         004bed78     MOV        EDX,dword ptr [ESP + bmWide]
    //         004bed7c     PUSH       ESI
    //         004bed7d     PUSH       EBP
    //         004bed7e     PUSH       EDX
    //         004bed7f     CALL       write                                            undefined write()
    //         004bed84     ADD        ESP,0xc
    //         004bed87     DEC        EBX
    //         004bed88     JNS        LAB_004bed00
    //                              spanlist.cpp:1922 (4)
    //         004bed8e     MOV        EDI,dword ptr [ESP + bmWide]
    //                               LAB_004bed92                                                 XREF[1]:     004becfa(j)  
    //                              spanlist.cpp:1943 (9)
    //         004bed92     PUSH       EDI
    //         004bed93     CALL       close                                            undefined close()
    //         004bed98     ADD        ESP,0x4
    //                               LAB_004bed9b                                                 XREF[1]:     004becb5(j)  
    //                              spanlist.cpp:1946 (9)
    //         004bed9b     PUSH       EBP
    //         004bed9c     CALL       free                                             undefined free()
    //         004beda1     ADD        ESP,0x4
    //                               LAB_004beda4                                                 XREF[1]:     004beb3a(j)  
    //                              spanlist.cpp:1950 (13)
    //         004beda4     POP        EDI
    //         004beda5     POP        ESI
    //         004beda6     POP        EBP
    //         004beda7     POP        EBX
    //         004beda8     ADD        ESP,0x888
    //         004bedae     RET        0x1c
}

