#include "common.h"
#include "utmarray.h"

ManagedArray<int>::~ManagedArray<int>() {
    /* TODO: Stub */
    //                              void __thiscall ~ManagedArray<int>(ManagedArray<int> * this)
    //              void              <VOID>         <RETURN>
    //              ManagedArray<i    ECX:4 (auto)   this
    //                               ??1?$ManagedArray@H@@QAE@XZ                                  XREF[8]:     ~TribeTacticalAIModule:004eee0f(c)
    //                               ManagedArray<int>::~ManagedArray<int>                                     FUN_0055c47c:0055c488(c), 
    //                                                                                                         FUN_0055f990:0055f996(c), 
    //                                                                                                         FUN_0055f99b:0055f9a1(c), 
    //                                                                                                         FUN_0055f9b0:0055f9b6(c), 
    //                                                                                                         FUN_0055f9bb:0055f9c1(c), 
    //                                                                                                         FUN_0055f9d0:0055f9d6(c), 
    //                                                                                                         FUN_0055f9db:0055f9e1(c)  
    //                              utmarray.h:52 (3)
    //         00408d20     PUSH       ESI
    //         00408d21     MOV        ESI,this
    //                              utmarray.h:53 (6)
    //         00408d23     MOV        EAX,dword ptr [ESI]
    //         00408d25     TEST       EAX,EAX
    //         00408d27     JZ         LAB_00408d38
    //                              utmarray.h:54 (9)
    //         00408d29     PUSH       EAX
    //         00408d2a     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00408d2f     ADD        ESP,0x4
    //                              utmarray.h:55 (6)
    //         00408d32     MOV        dword ptr [ESI],0x0
    //                               LAB_00408d38                                                 XREF[1]:     00408d27(j)  
    //                              utmarray.h:57 (7)
    //         00408d38     MOV        dword ptr [ESI + 0x4],0x0
    //                              utmarray.h:58 (7)
    //         00408d3f     MOV        dword ptr [ESI + 0x8],0x0
    //                              utmarray.h:59 (7)
    //         00408d46     MOV        dword ptr [ESI + 0xc],0x0
    //                              utmarray.h:60 (2)
    //         00408d4d     POP        ESI
    //         00408d4e     RET
    //         00408d4f     ??         90h
}

int* ManagedArray<int>::operator[](int param_1) {
    /* TODO: Stub */
    //                              int * __thiscall operator[](ManagedArray<int> * this, int param_1)
    //              int *             EAX:4          <RETURN>
    //              ManagedArray<i    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004ea752(R)  
    //                               ??A?$ManagedArray@H@@QAEAAHH@Z                               XREF[4]:     setVictoryCondition:004ea6cb(c), 
    //                               ManagedArray<int>::operator[]                                             setVictoryCondition:004ea6ef(c), 
    //                                                                                                         setVictoryCondition:004ea71a(c), 
    //                                                                                                         setVictoryCondition:004ea72a(c)  
    //                              utmarray.h:63 (2)
    //         004ea750     PUSH       EBX
    //         004ea751     PUSH       EBP
    //                              utmarray.h:64 (16)
    //         004ea752     MOV        EBP,dword ptr [ESP + param_1]
    //         004ea756     PUSH       ESI
    //         004ea757     MOV        ESI,this
    //         004ea759     PUSH       EDI
    //         004ea75a     MOV        EAX,dword ptr [ESI + 0xc]
    //         004ea75d     DEC        EAX
    //         004ea75e     CMP        EBP,EAX
    //         004ea760     JLE        LAB_004ea7aa
    //                              utmarray.h:65 (72)
    //         004ea762     LEA        EBX,[EBP + 0x1]
    //         004ea765     LEA        this,[EBX*0x4 + 0x0]
    //         004ea76c     PUSH       this
    //         004ea76d     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004ea772     MOV        EDI,EAX
    //         004ea774     ADD        ESP,0x4
    //         004ea777     TEST       EDI,EDI
    //         004ea779     JZ         LAB_004ea7aa
    //         004ea77b     MOV        this,dword ptr [ESI + 0xc]
    //         004ea77e     XOR        EAX,EAX
    //         004ea780     TEST       this,this
    //         004ea782     JLE        LAB_004ea79a
    //                               LAB_004ea784                                                 XREF[1]:     004ea798(j)  
    //         004ea784     CMP        EAX,EBX
    //         004ea786     JGE        LAB_004ea79a
    //         004ea788     MOV        EDX,dword ptr [ESI]
    //         004ea78a     INC        EAX
    //         004ea78b     MOV        this,dword ptr [EDX + EAX*0x4 + -0x4]
    //         004ea78f     MOV        dword ptr [EDI + EAX*0x4 + -0x4],this
    //         004ea793     MOV        this,dword ptr [ESI + 0xc]
    //         004ea796     CMP        EAX,this
    //         004ea798     JL         LAB_004ea784
    //                               LAB_004ea79a                                                 XREF[2]:     004ea782(j), 004ea786(j)  
    //         004ea79a     MOV        EDX,dword ptr [ESI]
    //         004ea79c     PUSH       EDX
    //         004ea79d     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004ea7a2     ADD        ESP,0x4
    //         004ea7a5     MOV        dword ptr [ESI],EDI
    //         004ea7a7     MOV        dword ptr [ESI + 0xc],EBX
    //                               LAB_004ea7aa                                                 XREF[2]:     004ea760(j), 004ea779(j)  
    //                              utmarray.h:66 (2)
    //         004ea7aa     MOV        EAX,dword ptr [ESI]
    //                              utmarray.h:67 (10)
    //         004ea7ac     POP        EDI
    //         004ea7ad     POP        ESI
    //         004ea7ae     LEA        EAX,[EAX + EBP*0x4]
    //         004ea7b1     POP        EBP
    //         004ea7b2     POP        EBX
    //         004ea7b3     RET        0x4
    //         004ea7b6     ??         90h
    //         004ea7b7     NOP
    //         004ea7b8     NOP
    //         004ea7b9     NOP
    //         004ea7ba     NOP
    //         004ea7bb     NOP
    //         004ea7bc     NOP
    //         004ea7bd     NOP
    //         004ea7be     NOP
    //         004ea7bf     NOP
    return 0;
}

int ManagedArray<int>::contains(int* param_1) {
    /* TODO: Stub */
    //                              int __thiscall contains(ManagedArray<int> * this, int * param_1)
    //              int               EAX:4          <RETURN>
    //              ManagedArray<i    ECX:4 (auto)   this
    //              int *             Stack[0x4]:4   param_1                   XREF[1]:     004de990(R)  
    //                               ?contains@?$ManagedArray@H@@QAEHABH@Z                        XREF[27]:    checkDefend:004de803(c), 
    //                               ManagedArray<int>::contains                                               checkDefend:004de873(c), 
    //                                                                                                         setVictoryCondition:004ea2ad(c), 
    //                                                                                                         setVictoryCondition:004ea2ed(c), 
    //                                                                                                         setVictoryCondition:004ea32d(c), 
    //                                                                                                         setVictoryCondition:004ea36d(c), 
    //                                                                                                         setVictoryCondition:004ea3ad(c), 
    //                                                                                                         setVictoryCondition:004ea3ed(c), 
    //                                                                                                         setVictoryCondition:004ea42d(c), 
    //                                                                                                         setVictoryCondition:004ea46d(c), 
    //                                                                                                         setVictoryCondition:004ea4ad(c), 
    //                                                                                                         setVictoryCondition:004ea4ed(c), 
    //                                                                                                         setVictoryCondition:004ea52d(c), 
    //                                                                                                         addObject:004f0f63(c), 
    //                                                                                                         addObject:004f0fb2(c), 
    //                                                                                                         addObject:004f1005(c), 
    //                                                                                                         removeObject:004f12ad(c), 
    //                                                                                                         removeObject:004f12c3(c), 
    //                                                                                                         removeObject:004f12e0(c), 
    //                                                                                                         removeObject:004f12fd(c), [more]
    //                              utmarray.h:86 (24)
    //         004de980     MOV        EDX,dword ptr [ECX + this->numberValue]
    //         004de983     PUSH       EBX
    //         004de984     PUSH       EBP
    //         004de985     XOR        EAX,EAX
    //         004de987     PUSH       ESI
    //         004de988     PUSH       EDI
    //         004de989     TEST       EDX,EDX
    //         004de98b     JLE        LAB_004de9bd
    //         004de98d     MOV        EDI,dword ptr [ECX + this->maximumSizeValue]
    //         004de990     MOV        ESI,dword ptr [ESP + param_1]
    //                               LAB_004de994                                                 XREF[1]:     004de9a6(j)  
    //         004de994     CMP        EAX,EDI
    //         004de996     JGE        LAB_004de9bd
    //                              utmarray.h:90 (16)
    //         004de998     MOV        EBX,dword ptr [this->value]
    //         004de99a     MOV        EBP,dword ptr [ESI]
    //         004de99c     MOV        EBX,dword ptr [EBX + EAX*0x4]
    //         004de99f     CMP        EBX,EBP
    //         004de9a1     JZ         LAB_004de9b1
    //         004de9a3     INC        EAX
    //         004de9a4     CMP        EAX,EDX
    //         004de9a6     JL         LAB_004de994
    //                              utmarray.h:92 (2)
    //         004de9a8     XOR        EAX,EAX
    //                              utmarray.h:93 (7)
    //         004de9aa     POP        EDI
    //         004de9ab     POP        ESI
    //         004de9ac     POP        EBP
    //         004de9ad     POP        EBX
    //         004de9ae     RET        0x4
    //                               LAB_004de9b1                                                 XREF[1]:     004de9a1(j)  
    //                              utmarray.h:91 (5)
    //         004de9b1     MOV        EAX,0x1
    //                              utmarray.h:93 (16)
    //         004de9b6     POP        EDI
    //         004de9b7     POP        ESI
    //         004de9b8     POP        EBP
    //         004de9b9     POP        EBX
    //         004de9ba     RET        0x4
    //                               LAB_004de9bd                                                 XREF[2]:     004de98b(j), 004de996(j)  
    //         004de9bd     POP        EDI
    //         004de9be     POP        ESI
    //         004de9bf     POP        EBP
    //         004de9c0     XOR        EAX,EAX
    //         004de9c2     POP        EBX
    //         004de9c3     RET        0x4
    //         004de9c6     ??         90h
    //         004de9c7     NOP
    //         004de9c8     NOP
    //         004de9c9     NOP
    //         004de9ca     NOP
    //         004de9cb     NOP
    //         004de9cc     NOP
    //         004de9cd     NOP
    //         004de9ce     NOP
    //         004de9cf     NOP
    return 0;
}

int ManagedArray<int>::add(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall add(ManagedArray<int> * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              ManagedArray<i    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004de9d2(R)  
    //                               ?add@?$ManagedArray@H@@QAEHH@Z                               XREF[27]:    checkDefend:004de8d1(c), 
    //                               ManagedArray<int>::add                                                    setVictoryCondition:004ea5e2(c), 
    //                                                                                                         setVictoryCondition:004ea5eb(c), 
    //                                                                                                         setVictoryCondition:004ea5f4(c), 
    //                                                                                                         setVictoryCondition:004ea5fd(c), 
    //                                                                                                         setVictoryCondition:004ea606(c), 
    //                                                                                                         setVictoryCondition:004ea60f(c), 
    //                                                                                                         setVictoryCondition:004ea618(c), 
    //                                                                                                         setVictoryCondition:004ea621(c), 
    //                                                                                                         setVictoryCondition:004ea62a(c), 
    //                                                                                                         setVictoryCondition:004ea633(c), 
    //                                                                                                         setVictoryCondition:004ea63c(c), 
    //                                                                                                         setVictoryCondition:004ea645(c), 
    //                                                                                                         setVictoryCondition:004ea64e(c), 
    //                                                                                                         setVictoryCondition:004ea657(c), 
    //                                                                                                         setVictoryCondition:004ea660(c), 
    //                                                                                                         setVictoryCondition:004ea669(c), 
    //                                                                                                         setVictoryCondition:004ea672(c), 
    //                                                                                                         setVictoryCondition:004ea67b(c), 
    //                                                                                                         setVictoryCondition:004ea684(c), 
    //                                                                                                         [more]
    //                              utmarray.h:106 (2)
    //         004de9d0     PUSH       EBX
    //         004de9d1     PUSH       EBP
    //                              utmarray.h:107 (36)
    //         004de9d2     MOV        EBP,dword ptr [ESP + param_1]
    //         004de9d6     PUSH       ESI
    //         004de9d7     MOV        ESI,this
    //         004de9d9     XOR        EAX,EAX
    //         004de9db     PUSH       EDI
    //         004de9dc     MOV        this,dword ptr [ESI + 0x4]
    //         004de9df     TEST       this,this
    //         004de9e1     JLE        LAB_004de9f6
    //         004de9e3     MOV        EDX,dword ptr [ESI + 0xc]
    //                               LAB_004de9e6                                                 XREF[1]:     004de9f4(j)  
    //         004de9e6     CMP        EAX,EDX
    //         004de9e8     JGE        LAB_004de9f6
    //         004de9ea     MOV        EDI,dword ptr [ESI]
    //         004de9ec     CMP        dword ptr [EDI + EAX*0x4],EBP
    //         004de9ef     JZ         LAB_004dea61
    //         004de9f1     INC        EAX
    //         004de9f2     CMP        EAX,this
    //         004de9f4     JL         LAB_004de9e6
    //                               LAB_004de9f6                                                 XREF[2]:     004de9e1(j), 004de9e8(j)  
    //                              utmarray.h:112 (8)
    //         004de9f6     MOV        EAX,dword ptr [ESI + 0xc]
    //         004de9f9     DEC        EAX
    //         004de9fa     CMP        this,EAX
    //         004de9fc     JLE        LAB_004dea46
    //                              utmarray.h:113 (72)
    //         004de9fe     LEA        EBX,[ECX + this+0x1]
    //         004dea01     LEA        this,[EBX*0x4 + 0x0]
    //         004dea08     PUSH       this
    //         004dea09     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004dea0e     MOV        EDI,EAX
    //         004dea10     ADD        ESP,0x4
    //         004dea13     TEST       EDI,EDI
    //         004dea15     JZ         LAB_004dea46
    //         004dea17     MOV        this,dword ptr [ESI + 0xc]
    //         004dea1a     XOR        EAX,EAX
    //         004dea1c     TEST       this,this
    //         004dea1e     JLE        LAB_004dea36
    //                               LAB_004dea20                                                 XREF[1]:     004dea34(j)  
    //         004dea20     CMP        EAX,EBX
    //         004dea22     JGE        LAB_004dea36
    //         004dea24     MOV        EDX,dword ptr [ESI]
    //         004dea26     INC        EAX
    //         004dea27     MOV        this,dword ptr [EDX + EAX*0x4 + -0x4]
    //         004dea2b     MOV        dword ptr [EDI + EAX*0x4 + -0x4],this
    //         004dea2f     MOV        this,dword ptr [ESI + 0xc]
    //         004dea32     CMP        EAX,this
    //         004dea34     JL         LAB_004dea20
    //                               LAB_004dea36                                                 XREF[2]:     004dea1e(j), 004dea22(j)  
    //         004dea36     MOV        EDX,dword ptr [ESI]
    //         004dea38     PUSH       EDX
    //         004dea39     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004dea3e     ADD        ESP,0x4
    //         004dea41     MOV        dword ptr [ESI],EDI
    //         004dea43     MOV        dword ptr [ESI + 0xc],EBX
    //                               LAB_004dea46                                                 XREF[2]:     004de9fc(j), 004dea15(j)  
    //                              utmarray.h:114 (8)
    //         004dea46     MOV        EAX,dword ptr [ESI + 0x4]
    //         004dea49     MOV        this,dword ptr [ESI]
    //         004dea4b     MOV        dword ptr [this->value + EAX*0x4],EBP
    //                              utmarray.h:115 (7)
    //         004dea4e     MOV        EAX,dword ptr [ESI + 0x4]
    //         004dea51     INC        EAX
    //         004dea52     MOV        dword ptr [ESI + 0x4],EAX
    //                              utmarray.h:116 (5)
    //         004dea55     MOV        EAX,0x1
    //                              utmarray.h:117 (16)
    //         004dea5a     POP        EDI
    //         004dea5b     POP        ESI
    //         004dea5c     POP        EBP
    //         004dea5d     POP        EBX
    //         004dea5e     RET        0x4
    //                               LAB_004dea61                                                 XREF[1]:     004de9ef(j)  
    //         004dea61     POP        EDI
    //         004dea62     POP        ESI
    //         004dea63     POP        EBP
    //         004dea64     XOR        EAX,EAX
    //         004dea66     POP        EBX
    //         004dea67     RET        0x4
    //         004dea6a     ??         90h
    //         004dea6b     NOP
    //         004dea6c     NOP
    //         004dea6d     NOP
    //         004dea6e     NOP
    //         004dea6f     NOP
    return 0;
}

int ManagedArray<int>::remove(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall remove(ManagedArray<int> * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              ManagedArray<i    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004f139d(R)  
    //                               ?remove@?$ManagedArray@H@@QAEHH@Z                            XREF[1]:     removeObject:004f130d(c)  
    //                               ManagedArray<int>::remove
    //                              utmarray.h:120 (1)
    //         004f1390     PUSH       ESI
    //                              utmarray.h:123 (28)
    //         004f1391     MOV        ESI,dword ptr [ECX + this->maximumSizeValue]
    //         004f1394     XOR        EAX,EAX
    //         004f1396     TEST       ESI,ESI
    //         004f1398     PUSH       EDI
    //         004f1399     JLE        LAB_004f13ad
    //         004f139b     MOV        EDX,dword ptr [this->value]
    //         004f139d     MOV        EDI,dword ptr [ESP + param_1]
    //                               LAB_004f13a1                                                 XREF[1]:     004f13ab(j)  
    //         004f13a1     CMP        dword ptr [EDX],EDI
    //         004f13a3     JZ         LAB_004f13ad
    //         004f13a5     INC        EAX
    //         004f13a6     ADD        EDX,0x4
    //         004f13a9     CMP        EAX,ESI
    //         004f13ab     JL         LAB_004f13a1
    //                               LAB_004f13ad                                                 XREF[2]:     004f1399(j), 004f13a3(j)  
    //                              utmarray.h:125 (4)
    //         004f13ad     CMP        EAX,ESI
    //         004f13af     JL         LAB_004f13b8
    //                              utmarray.h:126 (2)
    //         004f13b1     XOR        EAX,EAX
    //                              utmarray.h:133 (5)
    //         004f13b3     POP        EDI
    //         004f13b4     POP        ESI
    //         004f13b5     RET        0x4
    //                               LAB_004f13b8                                                 XREF[1]:     004f13af(j)  
    //                              utmarray.h:127 (5)
    //         004f13b8     DEC        ESI
    //         004f13b9     CMP        EAX,ESI
    //         004f13bb     JGE        LAB_004f13cf
    //                               LAB_004f13bd                                                 XREF[1]:     004f13cd(j)  
    //                              utmarray.h:128 (18)
    //         004f13bd     MOV        EDX,dword ptr [this->value]
    //         004f13bf     INC        EAX
    //         004f13c0     MOV        ESI,dword ptr [EDX + EAX*0x4]
    //         004f13c3     MOV        dword ptr [EDX + EAX*0x4 + -0x4],ESI
    //         004f13c7     MOV        EDX,dword ptr [ECX + this->maximumSizeValue]
    //         004f13ca     DEC        EDX
    //         004f13cb     CMP        EAX,EDX
    //         004f13cd     JL         LAB_004f13bd
    //                               LAB_004f13cf                                                 XREF[1]:     004f13bb(j)  
    //                              utmarray.h:129 (7)
    //         004f13cf     MOV        EAX,dword ptr [ECX + this->numberValue]
    //         004f13d2     DEC        EAX
    //         004f13d3     MOV        dword ptr [ECX + this->numberValue],EAX
    //                              utmarray.h:130 (2)
    //         004f13d6     JNS        LAB_004f13df
    //                              utmarray.h:131 (7)
    //         004f13d8     MOV        dword ptr [ECX + this->numberValue],0x0
    //                               LAB_004f13df                                                 XREF[1]:     004f13d6(j)  
    //                              utmarray.h:133 (10)
    //         004f13df     POP        EDI
    //         004f13e0     POP        ESI
    //         004f13e1     MOV        EAX,0x1
    //         004f13e6     RET        0x4
    //         004f13e9     ??         90h
    //         004f13ea     NOP
    //         004f13eb     NOP
    //         004f13ec     NOP
    //         004f13ed     NOP
    //         004f13ee     NOP
    //         004f13ef     NOP
    return 0;
}

int ManagedArray<int>::resize(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall resize(ManagedArray<int> * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              ManagedArray<i    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004147a1(R)  
    //                               ?resize@?$ManagedArray@H@@IAEHH@Z                            XREF[86]:    updateGroup:00414145(c), 
    //                               ManagedArray<int>::resize                                                 selectNewPlayPhase:00414987(c), 
    //                                                                                                         checkDefend:004de820(c), 
    //                                                                                                         checkDefend:004de88c(c), 
    //                                                                                                         numberSoldiersWithPriority:004f75d
    //                                                                                                         numberSoldiersWithPriority:004f762
    //                                                                                                         numberSoldiersWithPriority:004f76a
    //                                                                                                         idleCivilian:004f7ead(c), 
    //                                                                                                         idleCivilian:004f7eee(c), 
    //                                                                                                         idleCivilian:004f7f38(c), 
    //                                                                                                         idleCivilian:004f7f5c(c), 
    //                                                                                                         idleCivilian:004f7ff7(c), 
    //                                                                                                         idleCivilian:004f8038(c), 
    //                                                                                                         idleCivilian:004f8091(c), 
    //                                                                                                         idleCivilian:004f81dd(c), 
    //                                                                                                         idleCivilian:004f821e(c), 
    //                                                                                                         idleCivilian:004f8268(c), 
    //                                                                                                         idleCivilian:004f828c(c), 
    //                                                                                                         idleCivilian:004f8327(c), 
    //                                                                                                         idleCivilian:004f847e(c), [more]
    //                              utmarray.h:183 (1)
    //         004147a0     PUSH       EBX
    //                              utmarray.h:186 (26)
    //         004147a1     MOV        EBX,dword ptr [ESP + param_1]
    //         004147a5     PUSH       ESI
    //         004147a6     PUSH       EDI
    //         004147a7     LEA        EAX,[EBX*0x4 + 0x0]
    //         004147ae     MOV        ESI,this
    //         004147b0     PUSH       EAX
    //         004147b1     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004147b6     MOV        EDI,EAX
    //         004147b8     ADD        ESP,0x4
    //                              utmarray.h:187 (4)
    //         004147bb     TEST       EDI,EDI
    //         004147bd     JNZ        LAB_004147c5
    //                              utmarray.h:195 (6)
    //         004147bf     POP        EDI
    //         004147c0     POP        ESI
    //         004147c1     POP        EBX
    //         004147c2     RET        0x4
    //                               LAB_004147c5                                                 XREF[1]:     004147bd(j)  
    //                              utmarray.h:189 (13)
    //         004147c5     MOV        this,dword ptr [ESI + 0xc]
    //         004147c8     XOR        EAX,EAX
    //         004147ca     TEST       this,this
    //         004147cc     JLE        LAB_004147e4
    //                               LAB_004147ce                                                 XREF[1]:     004147e2(j)  
    //         004147ce     CMP        EAX,EBX
    //         004147d0     JGE        LAB_004147e4
    //                              utmarray.h:190 (18)
    //         004147d2     MOV        this,dword ptr [ESI]
    //         004147d4     INC        EAX
    //         004147d5     MOV        EDX,dword ptr [this->value + EAX*0x4 + -0x4]
    //         004147d9     MOV        dword ptr [EDI + EAX*0x4 + -0x4],EDX
    //         004147dd     MOV        this,dword ptr [ESI + 0xc]
    //         004147e0     CMP        EAX,this
    //         004147e2     JL         LAB_004147ce
    //                               LAB_004147e4                                                 XREF[2]:     004147cc(j), 004147d0(j)  
    //                              utmarray.h:191 (11)
    //         004147e4     MOV        EAX,dword ptr [ESI]
    //         004147e6     PUSH       EAX
    //         004147e7     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004147ec     ADD        ESP,0x4
    //                              utmarray.h:192 (2)
    //         004147ef     MOV        dword ptr [ESI],EDI
    //                              utmarray.h:193 (3)
    //         004147f1     MOV        dword ptr [ESI + 0xc],EBX
    //                              utmarray.h:194 (5)
    //         004147f4     MOV        EAX,0x1
    //                              utmarray.h:195 (6)
    //         004147f9     POP        EDI
    //         004147fa     POP        ESI
    //         004147fb     POP        EBX
    //         004147fc     RET        0x4
    //         004147ff     ??         90h
    return 0;
}

