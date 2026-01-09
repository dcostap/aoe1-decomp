#include "common.h"
#include "airesmod.h"

ResourceAIModule::ResourceAIModule(void* param_1, int param_2, int param_3, int param_4, int param_5, int param_6) {
    /* TODO: Stub */
    //                              undefined __thiscall ResourceAIModule(ResourceAIModule * this, void 
    //              undefined         <UNASSIGNED>   <RETURN>
    //              ResourceAIModu    ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     00412326(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0041232e(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     00412348(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     004123f5(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     004123f0(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[1]:     004123ec(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0041234c(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00412441(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00412332(W)  
    //                               ??0ResourceAIModule@@QAE@PAXHHHHH@Z
    //                               ResourceAIModule::ResourceAIModule
    //                              airesmod.cpp:26 (84)
    //         00412310     PUSH       -0x1
    //         00412312     PUSH       FUN_0055c808
    //         00412317     MOV        EAX,FS:[0x0]
    //         0041231d     PUSH       EAX
    //         0041231e     MOV        dword ptr FS:[0x0],ESP
    //         00412325     PUSH       this
    //         00412326     MOV        EAX,dword ptr [ESP + param_1]
    //         0041232a     PUSH       ESI
    //         0041232b     MOV        ESI,this
    //         0041232d     PUSH       EAX
    //         0041232e     MOV        this,dword ptr [ESP + param_2]
    //         00412332     MOV        dword ptr [ESP + local_10],ESI
    //         00412336     PUSH       this
    //         00412337     PUSH       0x3ef
    //         0041233c     PUSH       s_Resource_AI                                    = "Resource AI"
    //         00412341     MOV        this,ESI
    //         00412343     CALL       AIModule::AIModule                               undefined AIModule(AIModule * this, char * pa
    //         00412348     MOV        EAX,dword ptr [ESP + param_3]
    //         0041234c     MOV        dword ptr [ESP + local_4],0x0
    //         00412354     MOV        dword ptr [ESI + 0xf0],0x0
    //         0041235e     MOV        dword ptr [ESI + 0xf4],EAX
    //                              airesmod.cpp:31 (25)
    //         00412364     LEA        EDX,[EAX*0x4 + 0x0]
    //         0041236b     MOV        dword ptr [ESI],ResourceAIModule::`vftable'      = 00412460
    //         00412371     PUSH       EDX
    //         00412372     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00412377     MOV        dword ptr [ESI + 0xf8],EAX
    //                              airesmod.cpp:32 (18)
    //         0041237d     MOV        EAX,dword ptr [ESI + 0xf4]
    //         00412383     ADD        ESP,0x4
    //         00412386     SHL        EAX,0x2
    //         00412389     PUSH       EAX
    //         0041238a     CALL       operator_new                                     void * operator_new(uint param_1)
    //                              airesmod.cpp:33 (24)
    //         0041238f     MOV        this,dword ptr [ESI + 0xf4]
    //         00412395     ADD        ESP,0x4
    //         00412398     SHL        this,0x2
    //         0041239b     PUSH       this
    //         0041239c     MOV        dword ptr [ESI + 0xfc],EAX
    //         004123a2     CALL       operator_new                                     void * operator_new(uint param_1)
    //                              airesmod.cpp:34 (30)
    //         004123a7     MOV        EDX,dword ptr [ESI + 0xf4]
    //         004123ad     ADD        ESP,0x4
    //         004123b0     SHL        EDX,0x2
    //         004123b3     PUSH       EDX
    //         004123b4     MOV        dword ptr [ESI + 0x100],EAX
    //         004123ba     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004123bf     MOV        dword ptr [ESI + 0x104],EAX
    //                              airesmod.cpp:35 (18)
    //         004123c5     MOV        EAX,dword ptr [ESI + 0xf4]
    //         004123cb     ADD        ESP,0x4
    //         004123ce     SHL        EAX,0x2
    //         004123d1     PUSH       EAX
    //         004123d2     CALL       operator_new                                     void * operator_new(uint param_1)
    //                              airesmod.cpp:37 (35)
    //         004123d7     MOV        this,dword ptr [ESI + 0xf4]
    //         004123dd     MOV        dword ptr [ESI + 0x108],EAX
    //         004123e3     ADD        ESP,0x4
    //         004123e6     XOR        EAX,EAX
    //         004123e8     TEST       this,this
    //         004123ea     JLE        LAB_00412441
    //         004123ec     MOV        this,dword ptr [ESP + param_6]
    //         004123f0     MOV        EDX,dword ptr [ESP + param_5]
    //         004123f4     PUSH       EDI
    //         004123f5     MOV        EDI,dword ptr [ESP + param_4]
    //         004123f9     PUSH       EBP
    //                               LAB_004123fa                                                 XREF[1]:     0041243d(j)  
    //                              airesmod.cpp:38 (11)
    //         004123fa     MOV        EBP,dword ptr [ESI + 0xf8]
    //         00412400     INC        EAX
    //         00412401     MOV        dword ptr [EBP + EAX*0x4 + -0x4],EDI
    //                              airesmod.cpp:39 (10)
    //         00412405     MOV        EBP,dword ptr [ESI + 0xfc]
    //         0041240b     MOV        dword ptr [EBP + EAX*0x4 + -0x4],EDX
    //                              airesmod.cpp:40 (10)
    //         0041240f     MOV        EBP,dword ptr [ESI + 0x100]
    //         00412415     MOV        dword ptr [EBP + EAX*0x4 + -0x4],this
    //                              airesmod.cpp:41 (14)
    //         00412419     MOV        EBP,dword ptr [ESI + 0x108]
    //         0041241f     MOV        dword ptr [EBP + EAX*0x4 + -0x4],0x0
    //                              airesmod.cpp:42 (26)
    //         00412427     MOV        EBP,dword ptr [ESI + 0x104]
    //         0041242d     MOV        dword ptr [EBP + EAX*0x4 + -0x4],0x0
    //         00412435     MOV        EBP,dword ptr [ESI + 0xf4]
    //         0041243b     CMP        EAX,EBP
    //         0041243d     JL         LAB_004123fa
    //         0041243f     POP        EBP
    //         00412440     POP        EDI
    //                               LAB_00412441                                                 XREF[1]:     004123ea(j)  
    //                              airesmod.cpp:44 (20)
    //         00412441     MOV        this,dword ptr [ESP + local_c]
    //         00412445     MOV        EAX,ESI
    //         00412447     MOV        dword ptr FS:[0x0],this
    //         0041244e     POP        ESI
    //         0041244f     ADD        ESP,0x10
    //         00412452     RET        0x18
    //         00412455     ??         90h
    //         00412456     NOP
    //         00412457     NOP
    //         00412458     NOP
    //         00412459     NOP
    //         0041245a     NOP
    //         0041245b     NOP
    //         0041245c     NOP
    //         0041245d     NOP
    //         0041245e     NOP
    //         0041245f     NOP
}

ResourceAIModule::~ResourceAIModule() {
    /* TODO: Stub */
    //                              void __thiscall ~ResourceAIModule(ResourceAIModule * this)
    //              void              <VOID>         <RETURN>
    //              ResourceAIModu    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004124ad(W), 0041251e(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0041252b(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0041249a(W)  
    //                               ??1ResourceAIModule@@UAE@XZ                                  XREF[1]:     `vector_deleting_destructor':00412
    //                               ResourceAIModule::~ResourceAIModule
    //                              airesmod.cpp:49 (36)
    //         00412480     PUSH       -0x1
    //         00412482     PUSH       FUN_0055c828
    //         00412487     MOV        EAX,FS:[0x0]
    //         0041248d     PUSH       EAX
    //         0041248e     MOV        dword ptr FS:[0x0],ESP
    //         00412495     PUSH       this
    //         00412496     PUSH       ESI
    //         00412497     MOV        ESI,this
    //         00412499     PUSH       EDI
    //         0041249a     MOV        dword ptr [ESP + local_10],ESI
    //         0041249e     MOV        dword ptr [ESI],ResourceAIModule::`vftable'      = 00412460
    //                              airesmod.cpp:51 (18)
    //         004124a4     MOV        EAX,dword ptr [ESI + 0xf8]
    //         004124aa     XOR        EDI,EDI
    //         004124ac     PUSH       EAX
    //         004124ad     MOV        dword ptr [ESP + local_4],EDI
    //         004124b1     CALL       operator_delete                                  void operator_delete(void * param_1)
    //                              airesmod.cpp:52 (15)
    //         004124b6     MOV        this,dword ptr [ESI + 0xfc]
    //         004124bc     ADD        ESP,0x4
    //         004124bf     PUSH       this
    //         004124c0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //                              airesmod.cpp:53 (15)
    //         004124c5     MOV        EDX,dword ptr [ESI + 0x100]
    //         004124cb     ADD        ESP,0x4
    //         004124ce     PUSH       EDX
    //         004124cf     CALL       operator_delete                                  void operator_delete(void * param_1)
    //                              airesmod.cpp:54 (13)
    //         004124d4     MOV        EAX,dword ptr [ESI + 0xf4]
    //         004124da     ADD        ESP,0x4
    //         004124dd     CMP        EAX,EDI
    //         004124df     JLE        LAB_004124fe
    //                               LAB_004124e1                                                 XREF[1]:     004124fc(j)  
    //                              airesmod.cpp:55 (29)
    //         004124e1     MOV        EAX,dword ptr [ESI + 0x104]
    //         004124e7     MOV        this,dword ptr [EAX + EDI*0x4]
    //         004124ea     PUSH       this
    //         004124eb     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004124f0     MOV        EAX,dword ptr [ESI + 0xf4]
    //         004124f6     ADD        ESP,0x4
    //         004124f9     INC        EDI
    //         004124fa     CMP        EDI,EAX
    //         004124fc     JL         LAB_004124e1
    //                               LAB_004124fe                                                 XREF[1]:     004124df(j)  
    //                              airesmod.cpp:56 (12)
    //         004124fe     MOV        EDX,dword ptr [ESI + 0x104]
    //         00412504     PUSH       EDX
    //         00412505     CALL       operator_delete                                  void operator_delete(void * param_1)
    //                              airesmod.cpp:57 (20)
    //         0041250a     MOV        EAX,dword ptr [ESI + 0x108]
    //         00412510     ADD        ESP,0x4
    //         00412513     PUSH       EAX
    //         00412514     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00412519     ADD        ESP,0x4
    //         0041251c     MOV        this,ESI
    //                              airesmod.cpp:58 (30)
    //         0041251e     MOV        dword ptr [ESP + local_4],0xffffffff
    //         00412526     CALL       AIModule::~AIModule                              void ~AIModule(AIModule * this)
    //         0041252b     MOV        this,dword ptr [ESP + local_c]
    //         0041252f     POP        EDI
    //         00412530     MOV        dword ptr FS:[0x0],this
    //         00412537     POP        ESI
    //         00412538     ADD        ESP,0x10
    //         0041253b     RET
    //         0041253c     ??         90h
    //         0041253d     NOP
    //         0041253e     NOP
    //         0041253f     NOP
}

int ResourceAIModule::processMessage(AIModuleMessage* param_1) {
    /* TODO: Stub */
    //                              int __thiscall processMessage(ResourceAIModule * this, AIModuleMessa
    //              int               EAX:4          <RETURN>
    //              ResourceAIModu    ECX:4 (auto)   this
    //              AIModuleMessag    Stack[0x4]:4   param_1
    //                               ?processMessage@ResourceAIModule@@UAEHPAVAIModuleMessage@@@Z XREF[1]:     0056ea04(*)  
    //                               ResourceAIModule::processMessage
    //                              airesmod.cpp:63 (2)
    //         00412540     XOR        EAX,EAX
    //                              airesmod.cpp:104 (3)
    //         00412542     RET        0x4
    //         00412545     ??         90h
    //         00412546     NOP
    //         00412547     NOP
    //         00412548     NOP
    //         00412549     NOP
    //         0041254a     NOP
    //         0041254b     NOP
    //         0041254c     NOP
    //         0041254d     NOP
    //         0041254e     NOP
    //         0041254f     NOP
    return 0;
}

int ResourceAIModule::update(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall update(ResourceAIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              ResourceAIModu    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //                               ?update@ResourceAIModule@@UAEHH@Z                            XREF[1]:     0056ea08(*)  
    //                               ResourceAIModule::update
    //                              airesmod.cpp:109 (2)
    //         00412550     XOR        EAX,EAX
    //                              airesmod.cpp:174 (3)
    //         00412552     RET        0x4
    //         00412555     ??         90h
    //         00412556     NOP
    //         00412557     NOP
    //         00412558     NOP
    //         00412559     NOP
    //         0041255a     NOP
    //         0041255b     NOP
    //         0041255c     NOP
    //         0041255d     NOP
    //         0041255e     NOP
    //         0041255f     NOP
    return 0;
}

void ResourceAIModule::setCallbackMessage(AIModuleMessage* param_1) {
    /* TODO: Stub */
    //                              void __thiscall setCallbackMessage(ResourceAIModule * this, AIModule
    //              void              <VOID>         <RETURN>
    //              ResourceAIModu    ECX:4 (auto)   this
    //              AIModuleMessag    Stack[0x4]:4   param_1
    //                               ?setCallbackMessage@ResourceAIModule@@UAEXPAVAIModuleMessag  XREF[1]:     0056ea0c(*)  
    //                               ResourceAIModule::setCallbackMessage
    //                              airesmod.cpp:179 (3)
    //         00412560     RET        0x4
    //         00412563     ??         90h
    //         00412564     NOP
    //         00412565     NOP
    //         00412566     NOP
    //         00412567     NOP
    //         00412568     NOP
    //         00412569     NOP
    //         0041256a     NOP
    //         0041256b     NOP
    //         0041256c     NOP
    //         0041256d     NOP
    //         0041256e     NOP
    //         0041256f     NOP
    return;
}

void ResourceAIModule::setMainDecisionAI(MainDecisionAIModule* param_1) {
    /* TODO: Stub */
    //                              void __thiscall setMainDecisionAI(ResourceAIModule * this, MainDecis
    //              void              <VOID>         <RETURN>
    //              ResourceAIModu    ECX:4 (auto)   this
    //              MainDecisionAI    Stack[0x4]:4   param_1                   XREF[1]:     00412570(R)  
    //                               ?setMainDecisionAI@ResourceAIModule@@QAEXPAVMainDecisionAIM
    //                               ResourceAIModule::setMainDecisionAI
    //                              airesmod.cpp:240 (10)
    //         00412570     MOV        EAX,dword ptr [ESP + param_1]
    //         00412574     MOV        dword ptr [ECX + this->md],EAX
    //                              airesmod.cpp:242 (3)
    //         0041257a     RET        0x4
    //         0041257d     ??         90h
    //         0041257e     NOP
    //         0041257f     NOP
    //                              * public: int __thiscall ResourceAIModule::numberResources(void)const                                   *
    //                              int __thiscall numberResources(ResourceAIModule * this)
    //              int               EAX:4          <RETURN>
    //              ResourceAIModu    ECX:4 (auto)   this
    //                               ?numberResources@ResourceAIModule@@QBEHXZ
    //                               ResourceAIModule::numberResources
    //                              airesmod.cpp:247 (6)
    //         00412580     MOV        EAX,dword ptr [ECX + this->numberResourcesValue]
    //                              airesmod.cpp:249 (1)
    //         00412586     RET
    //         00412587     ??         90h
    //         00412588     NOP
    //         00412589     NOP
    //         0041258a     NOP
    //         0041258b     NOP
    //         0041258c     NOP
    //         0041258d     NOP
    //         0041258e     NOP
    //         0041258f     NOP
    //                              * public: int __thiscall ResourceAIModule::resource(int)const                                           *
    //                              int __thiscall resource(ResourceAIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              ResourceAIModu    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00412590(R)  
    //                               ?resource@ResourceAIModule@@QBEHH@Z
    //                               ResourceAIModule::resource
    //                              airesmod.cpp:254 (16)
    //         00412590     MOV        EAX,dword ptr [ESP + param_1]
    //         00412594     TEST       EAX,EAX
    //         00412596     JL         LAB_004125ac
    //         00412598     CMP        EAX,dword ptr [ECX + this->numberResourcesValue]
    //         0041259e     JGE        LAB_004125ac
    //                              airesmod.cpp:257 (9)
    //         004125a0     MOV        this,dword ptr [ECX + this->resourceValue]
    //         004125a6     MOV        EAX,dword ptr [this->_padding_ + EAX*0x4]
    //                              airesmod.cpp:258 (3)
    //         004125a9     RET        0x4
    //                               LAB_004125ac                                                 XREF[2]:     00412596(j), 0041259e(j)  
    //                              airesmod.cpp:256 (3)
    //         004125ac     OR         EAX,0xffffffff
    //                              airesmod.cpp:258 (3)
    //         004125af     RET        0x4
    //         004125b2     ??         90h
    //         004125b3     NOP
    //         004125b4     NOP
    //         004125b5     NOP
    //         004125b6     NOP
    //         004125b7     NOP
    //         004125b8     NOP
    //         004125b9     NOP
    //         004125ba     NOP
    //         004125bb     NOP
    //         004125bc     NOP
    //         004125bd     NOP
    //         004125be     NOP
    //         004125bf     NOP
    return;
}

int ResourceAIModule::resourcesAvailable(ResourceItem* param_1) {
    /* TODO: Stub */
    //                              int __thiscall resourcesAvailable(ResourceAIModule * this, ResourceI
    //              int               EAX:4          <RETURN>
    //              ResourceAIModu    ECX:4 (auto)   this
    //              ResourceItem *    Stack[0x4]:4   param_1                   XREF[1]:     004125c3(R)  
    //                               ?resourcesAvailable@ResourceAIModule@@QAEHPAVResourceItem@@@Z
    //                               ResourceAIModule::resourcesAvailable
    //                              airesmod.cpp:263 (3)
    //         004125c0     PUSH       EBX
    //         004125c1     PUSH       ESI
    //         004125c2     PUSH       EDI
    //                              airesmod.cpp:264 (10)
    //         004125c3     MOV        EDI,dword ptr [ESP + param_1]
    //         004125c7     TEST       EDI,EDI
    //         004125c9     MOV        EBX,this
    //         004125cb     JNZ        LAB_004125d5
    //                              airesmod.cpp:265 (2)
    //         004125cd     XOR        EAX,EAX
    //                              airesmod.cpp:278 (6)
    //         004125cf     POP        EDI
    //         004125d0     POP        ESI
    //         004125d1     POP        EBX
    //         004125d2     RET        0x4
    //                               LAB_004125d5                                                 XREF[1]:     004125cb(j)  
    //                              airesmod.cpp:268 (15)
    //         004125d5     MOV        this,EDI
    //         004125d7     CALL       ResourceItem::number                             int number(ResourceItem * this)
    //         004125dc     CMP        dword ptr [EBX + 0xf4],EAX
    //         004125e2     JZ         LAB_004125ec
    //                              airesmod.cpp:269 (2)
    //         004125e4     XOR        EAX,EAX
    //                              airesmod.cpp:278 (6)
    //         004125e6     POP        EDI
    //         004125e7     POP        ESI
    //         004125e8     POP        EBX
    //         004125e9     RET        0x4
    //                               LAB_004125ec                                                 XREF[1]:     004125e2(j)  
    //                              airesmod.cpp:274 (13)
    //         004125ec     MOV        this,EDI
    //         004125ee     XOR        ESI,ESI
    //         004125f0     CALL       ResourceItem::number                             int number(ResourceItem * this)
    //         004125f5     TEST       EAX,EAX
    //         004125f7     JLE        LAB_0041262b
    //                               LAB_004125f9                                                 XREF[1]:     00412616(j)  
    //                              airesmod.cpp:275 (31)
    //         004125f9     PUSH       ESI
    //         004125fa     MOV        this,EDI
    //         004125fc     CALL       ResourceItem::value                              int value(ResourceItem * this, int param_1)
    //         00412601     MOV        this,dword ptr [EBX + 0xf8]
    //         00412607     CMP        dword ptr [this->_padding_ + ESI*0x4],EAX
    //         0041260a     JL         LAB_00412623
    //         0041260c     MOV        this,EDI
    //         0041260e     INC        ESI
    //         0041260f     CALL       ResourceItem::number                             int number(ResourceItem * this)
    //         00412614     CMP        ESI,EAX
    //         00412616     JL         LAB_004125f9
    //                              airesmod.cpp:277 (5)
    //         00412618     MOV        EAX,0x1
    //                              airesmod.cpp:278 (6)
    //         0041261d     POP        EDI
    //         0041261e     POP        ESI
    //         0041261f     POP        EBX
    //         00412620     RET        0x4
    //                               LAB_00412623                                                 XREF[1]:     0041260a(j)  
    //                              airesmod.cpp:276 (2)
    //         00412623     XOR        EAX,EAX
    //                              airesmod.cpp:278 (17)
    //         00412625     POP        EDI
    //         00412626     POP        ESI
    //         00412627     POP        EBX
    //         00412628     RET        0x4
    //                               LAB_0041262b                                                 XREF[1]:     004125f7(j)  
    //         0041262b     POP        EDI
    //         0041262c     POP        ESI
    //         0041262d     MOV        EAX,0x1
    //         00412632     POP        EBX
    //         00412633     RET        0x4
    //         00412636     ??         90h
    //         00412637     NOP
    //         00412638     NOP
    //         00412639     NOP
    //         0041263a     NOP
    //         0041263b     NOP
    //         0041263c     NOP
    //         0041263d     NOP
    //         0041263e     NOP
    //         0041263f     NOP
    return 0;
}

int ResourceAIModule::unavailableResource(ResourceItem* param_1) {
    /* TODO: Stub */
    //                              int __thiscall unavailableResource(ResourceAIModule * this, Resource
    //              int               EAX:4          <RETURN>
    //              ResourceAIModu    ECX:4 (auto)   this
    //              ResourceItem *    Stack[0x4]:4   param_1                   XREF[1]:     00412643(R)  
    //                               ?unavailableResource@ResourceAIModule@@QAEHPAVResourceItem@
    //                               ResourceAIModule::unavailableResource
    //                              airesmod.cpp:283 (3)
    //         00412640     PUSH       EBX
    //         00412641     PUSH       ESI
    //         00412642     PUSH       EDI
    //                              airesmod.cpp:284 (10)
    //         00412643     MOV        EDI,dword ptr [ESP + param_1]
    //         00412647     TEST       EDI,EDI
    //         00412649     MOV        EBX,this
    //         0041264b     JNZ        LAB_00412655
    //                              airesmod.cpp:285 (2)
    //         0041264d     XOR        EAX,EAX
    //                              airesmod.cpp:296 (6)
    //         0041264f     POP        EDI
    //         00412650     POP        ESI
    //         00412651     POP        EBX
    //         00412652     RET        0x4
    //                               LAB_00412655                                                 XREF[1]:     0041264b(j)  
    //                              airesmod.cpp:288 (13)
    //         00412655     MOV        this,EDI
    //         00412657     CALL       ResourceItem::number                             int number(ResourceItem * this)
    //         0041265c     CMP        dword ptr [EBX + 0xf4],EAX
    //                              airesmod.cpp:289 (2)
    //         00412662     JNZ        LAB_004126a1
    //                              airesmod.cpp:292 (13)
    //         00412664     MOV        this,EDI
    //         00412666     XOR        ESI,ESI
    //         00412668     CALL       ResourceItem::number                             int number(ResourceItem * this)
    //         0041266d     TEST       EAX,EAX
    //         0041266f     JLE        LAB_004126a1
    //                               LAB_00412671                                                 XREF[1]:     0041268e(j)  
    //                              airesmod.cpp:293 (31)
    //         00412671     PUSH       ESI
    //         00412672     MOV        this,EDI
    //         00412674     CALL       ResourceItem::value                              int value(ResourceItem * this, int param_1)
    //         00412679     MOV        this,dword ptr [EBX + 0xf8]
    //         0041267f     CMP        dword ptr [this->_padding_ + ESI*0x4],EAX
    //         00412682     JL         LAB_00412699
    //         00412684     MOV        this,EDI
    //         00412686     INC        ESI
    //         00412687     CALL       ResourceItem::number                             int number(ResourceItem * this)
    //         0041268c     CMP        ESI,EAX
    //         0041268e     JL         LAB_00412671
    //                              airesmod.cpp:295 (3)
    //         00412690     OR         EAX,0xffffffff
    //                              airesmod.cpp:296 (6)
    //         00412693     POP        EDI
    //         00412694     POP        ESI
    //         00412695     POP        EBX
    //         00412696     RET        0x4
    //                               LAB_00412699                                                 XREF[1]:     00412682(j)  
    //                              airesmod.cpp:294 (2)
    //         00412699     MOV        EAX,ESI
    //                              airesmod.cpp:296 (15)
    //         0041269b     POP        EDI
    //         0041269c     POP        ESI
    //         0041269d     POP        EBX
    //         0041269e     RET        0x4
    //                               LAB_004126a1                                                 XREF[2]:     00412662(j), 0041266f(j)  
    //         004126a1     POP        EDI
    //         004126a2     POP        ESI
    //         004126a3     OR         EAX,0xffffffff
    //         004126a6     POP        EBX
    //         004126a7     RET        0x4
    //         004126aa     ??         90h
    //         004126ab     NOP
    //         004126ac     NOP
    //         004126ad     NOP
    //         004126ae     NOP
    //         004126af     NOP
    //                              * public: int __thiscall ResourceAIModule::minValueOfResource(int)const                                 *
    //                              int __thiscall minValueOfResource(ResourceAIModule * this, int param
    //              int               EAX:4          <RETURN>
    //              ResourceAIModu    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004126b0(R)  
    //                               ?minValueOfResource@ResourceAIModule@@QBEHH@Z
    //                               ResourceAIModule::minValueOfResource
    //                              airesmod.cpp:301 (16)
    //         004126b0     MOV        EAX,dword ptr [ESP + param_1]
    //         004126b4     TEST       EAX,EAX
    //         004126b6     JL         LAB_004126cc
    //         004126b8     CMP        EAX,dword ptr [ECX + this->numberResourcesValue]
    //         004126be     JGE        LAB_004126cc
    //                              airesmod.cpp:304 (9)
    //         004126c0     MOV        this,dword ptr [ECX + this->minValue]
    //         004126c6     MOV        EAX,dword ptr [this->_padding_ + EAX*0x4]
    //                              airesmod.cpp:305 (3)
    //         004126c9     RET        0x4
    //                               LAB_004126cc                                                 XREF[2]:     004126b6(j), 004126be(j)  
    //                              airesmod.cpp:303 (3)
    //         004126cc     OR         EAX,0xffffffff
    //                              airesmod.cpp:305 (3)
    //         004126cf     RET        0x4
    //         004126d2     ??         90h
    //         004126d3     NOP
    //         004126d4     NOP
    //         004126d5     NOP
    //         004126d6     NOP
    //         004126d7     NOP
    //         004126d8     NOP
    //         004126d9     NOP
    //         004126da     NOP
    //         004126db     NOP
    //         004126dc     NOP
    //         004126dd     NOP
    //         004126de     NOP
    //         004126df     NOP
    //                              * public: int __thiscall ResourceAIModule::maxValueOfResource(int)const                                 *
    //                              int __thiscall maxValueOfResource(ResourceAIModule * this, int param
    //              int               EAX:4          <RETURN>
    //              ResourceAIModu    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004126e0(R)  
    //                               ?maxValueOfResource@ResourceAIModule@@QBEHH@Z
    //                               ResourceAIModule::maxValueOfResource
    //                              airesmod.cpp:310 (16)
    //         004126e0     MOV        EAX,dword ptr [ESP + param_1]
    //         004126e4     TEST       EAX,EAX
    //         004126e6     JL         LAB_004126fc
    //         004126e8     CMP        EAX,dword ptr [ECX + this->numberResourcesValue]
    //         004126ee     JGE        LAB_004126fc
    //                              airesmod.cpp:313 (9)
    //         004126f0     MOV        this,dword ptr [ECX + this->maxValue]
    //         004126f6     MOV        EAX,dword ptr [this->_padding_ + EAX*0x4]
    //                              airesmod.cpp:314 (3)
    //         004126f9     RET        0x4
    //                               LAB_004126fc                                                 XREF[2]:     004126e6(j), 004126ee(j)  
    //                              airesmod.cpp:312 (3)
    //         004126fc     OR         EAX,0xffffffff
    //                              airesmod.cpp:314 (3)
    //         004126ff     RET        0x4
    //         00412702     ??         90h
    //         00412703     NOP
    //         00412704     NOP
    //         00412705     NOP
    //         00412706     NOP
    //         00412707     NOP
    //         00412708     NOP
    //         00412709     NOP
    //         0041270a     NOP
    //         0041270b     NOP
    //         0041270c     NOP
    //         0041270d     NOP
    //         0041270e     NOP
    //         0041270f     NOP
    return 0;
}

void ResourceAIModule::setResource(int param_1, int param_2) {
    /* TODO: Stub */
    //                              void __thiscall setResource(ResourceAIModule * this, int param_1, in
    //              void              <VOID>         <RETURN>
    //              ResourceAIModu    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00412717(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00412711(R)  
    //                               ?setResource@ResourceAIModule@@QAEXHH@Z                      XREF[1]:     setResources:004127a5(c)  
    //                               ResourceAIModule::setResource
    //                              airesmod.cpp:319 (1)
    //         00412710     PUSH       EBX
    //                              airesmod.cpp:320 (28)
    //         00412711     MOV        EBX,dword ptr [ESP + param_2]
    //         00412715     PUSH       ESI
    //         00412716     PUSH       EDI
    //         00412717     MOV        EDI,dword ptr [ESP + param_1]
    //         0041271b     PUSH       EBX
    //         0041271c     MOV        ESI,this
    //         0041271e     PUSH       EDI
    //         0041271f     PUSH       s_setResource:_n=%d,_v=%d.                       = "setResource: n=%d, v=%d."
    //         00412724     PUSH       ESI
    //         00412725     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
    //         0041272a     ADD        ESP,0x10
    //                              airesmod.cpp:321 (12)
    //         0041272d     TEST       EDI,EDI
    //         0041272f     JL         LAB_0041275b
    //         00412731     CMP        EDI,dword ptr [ESI + 0xf4]
    //         00412737     JGE        LAB_0041275b
    //                              airesmod.cpp:322 (9)
    //         00412739     MOV        EAX,dword ptr [ESI + 0xf8]
    //         0041273f     MOV        dword ptr [EAX + EDI*0x4],EBX
    //                              airesmod.cpp:323 (25)
    //         00412742     MOV        this,dword ptr [ESI + 0xf8]
    //         00412748     MOV        EDX,dword ptr [this->_padding_ + EDI*0x4]
    //         0041274b     PUSH       EDX
    //         0041274c     PUSH       EDI
    //         0041274d     PUSH       s___setResource:_r[%d]=%d.                       = "  setResource: r[%d]=%d."
    //         00412752     PUSH       ESI
    //         00412753     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
    //         00412758     ADD        ESP,0x10
    //                               LAB_0041275b                                                 XREF[2]:     0041272f(j), 00412737(j)  
    //                              airesmod.cpp:325 (6)
    //         0041275b     POP        EDI
    //         0041275c     POP        ESI
    //         0041275d     POP        EBX
    //         0041275e     RET        0x8
    //         00412761     ??         90h
    //         00412762     NOP
    //         00412763     NOP
    //         00412764     NOP
    //         00412765     NOP
    //         00412766     NOP
    //         00412767     NOP
    //         00412768     NOP
    //         00412769     NOP
    //         0041276a     NOP
    //         0041276b     NOP
    //         0041276c     NOP
    //         0041276d     NOP
    //         0041276e     NOP
    //         0041276f     NOP
    return;
}

void ResourceAIModule::setResources(ResourceItem* param_1) {
    /* TODO: Stub */
    //                              void __thiscall setResources(ResourceAIModule * this, ResourceItem *
    //              void              <VOID>         <RETURN>
    //              ResourceAIModu    ECX:4 (auto)   this
    //              ResourceItem *    Stack[0x4]:4   param_1                   XREF[1]:     00412773(R)  
    //                               ?setResources@ResourceAIModule@@QAEXPAVResourceItem@@@Z
    //                               ResourceAIModule::setResources
    //                              airesmod.cpp:330 (3)
    //         00412770     PUSH       EBX
    //         00412771     PUSH       ESI
    //         00412772     PUSH       EDI
    //                              airesmod.cpp:331 (10)
    //         00412773     MOV        EDI,dword ptr [ESP + param_1]
    //         00412777     TEST       EDI,EDI
    //         00412779     MOV        EBX,this
    //         0041277b     JZ         LAB_004127b6
    //                              airesmod.cpp:335 (15)
    //         0041277d     MOV        this,EDI
    //         0041277f     CALL       ResourceItem::number                             int number(ResourceItem * this)
    //         00412784     CMP        dword ptr [EBX + 0xf4],EAX
    //         0041278a     JNZ        LAB_004127b6
    //                              airesmod.cpp:337 (13)
    //         0041278c     MOV        this,EDI
    //         0041278e     XOR        ESI,ESI
    //         00412790     CALL       ResourceItem::number                             int number(ResourceItem * this)
    //         00412795     TEST       EAX,EAX
    //         00412797     JLE        LAB_004127b6
    //                               LAB_00412799                                                 XREF[1]:     004127b4(j)  
    //                              airesmod.cpp:338 (29)
    //         00412799     PUSH       ESI
    //         0041279a     MOV        this,EDI
    //         0041279c     CALL       ResourceItem::value                              int value(ResourceItem * this, int param_1)
    //         004127a1     PUSH       EAX
    //         004127a2     PUSH       ESI
    //         004127a3     MOV        this,EBX
    //         004127a5     CALL       ResourceAIModule::setResource                    void setResource(ResourceAIModule * this, int
    //         004127aa     MOV        this,EDI
    //         004127ac     INC        ESI
    //         004127ad     CALL       ResourceItem::number                             int number(ResourceItem * this)
    //         004127b2     CMP        ESI,EAX
    //         004127b4     JL         LAB_00412799
    //                               LAB_004127b6                                                 XREF[3]:     0041277b(j), 0041278a(j), 
    //                                                                                                         00412797(j)  
    //                              airesmod.cpp:339 (6)
    //         004127b6     POP        EDI
    //         004127b7     POP        ESI
    //         004127b8     POP        EBX
    //         004127b9     RET        0x4
    //         004127bc     ??         90h
    //         004127bd     NOP
    //         004127be     NOP
    //         004127bf     NOP
    return;
}

void ResourceAIModule::incrementResource(int param_1, int param_2) {
    /* TODO: Stub */
    //                              void __thiscall incrementResource(ResourceAIModule * this, int param
    //              void              <VOID>         <RETURN>
    //              ResourceAIModu    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004127c7(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004127c1(R)  
    //                               ?incrementResource@ResourceAIModule@@QAEXHH@Z                XREF[1]:     incrementResources:00412855(c)  
    //                               ResourceAIModule::incrementResource
    //                              airesmod.cpp:344 (1)
    //         004127c0     PUSH       EBX
    //                              airesmod.cpp:345 (28)
    //         004127c1     MOV        EBX,dword ptr [ESP + param_2]
    //         004127c5     PUSH       ESI
    //         004127c6     PUSH       EDI
    //         004127c7     MOV        EDI,dword ptr [ESP + param_1]
    //         004127cb     PUSH       EBX
    //         004127cc     MOV        ESI,this
    //         004127ce     PUSH       EDI
    //         004127cf     PUSH       s_incrementResource:_n=%d,_v=%d.                 = "incrementResource: n=%d, v=%d."
    //         004127d4     PUSH       ESI
    //         004127d5     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
    //         004127da     ADD        ESP,0x10
    //                              airesmod.cpp:346 (12)
    //         004127dd     TEST       EDI,EDI
    //         004127df     JL         LAB_00412816
    //         004127e1     CMP        EDI,dword ptr [ESI + 0xf4]
    //         004127e7     JGE        LAB_00412816
    //                              airesmod.cpp:347 (14)
    //         004127e9     MOV        EAX,dword ptr [ESI + 0xf8]
    //         004127ef     MOV        this,dword ptr [EAX + EDI*0x4]
    //         004127f2     LEA        EAX,[EAX + EDI*0x4]
    //         004127f5     ADD        this,EBX
    //                              airesmod.cpp:348 (6)
    //         004127f7     TEST       EBX,EBX
    //         004127f9     MOV        dword ptr [EAX],this
    //         004127fb     JZ         LAB_00412816
    //                              airesmod.cpp:349 (25)
    //         004127fd     MOV        this,dword ptr [ESI + 0xf8]
    //         00412803     MOV        EDX,dword ptr [this->_padding_ + EDI*0x4]
    //         00412806     PUSH       EDX
    //         00412807     PUSH       EDI
    //         00412808     PUSH       s___incrementResource:_r[%d]=%d.                 = "  incrementResource: r[%d]=%d."
    //         0041280d     PUSH       ESI
    //         0041280e     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
    //         00412813     ADD        ESP,0x10
    //                               LAB_00412816                                                 XREF[3]:     004127df(j), 004127e7(j), 
    //                                                                                                         004127fb(j)  
    //                              airesmod.cpp:351 (6)
    //         00412816     POP        EDI
    //         00412817     POP        ESI
    //         00412818     POP        EBX
    //         00412819     RET        0x8
    //         0041281c     ??         90h
    //         0041281d     NOP
    //         0041281e     NOP
    //         0041281f     NOP
    return;
}

void ResourceAIModule::incrementResources(ResourceItem* param_1) {
    /* TODO: Stub */
    //                              void __thiscall incrementResources(ResourceAIModule * this, Resource
    //              void              <VOID>         <RETURN>
    //              ResourceAIModu    ECX:4 (auto)   this
    //              ResourceItem *    Stack[0x4]:4   param_1                   XREF[1]:     00412823(R)  
    //                               ?incrementResources@ResourceAIModule@@QAEXPAVResourceItem@@@Z
    //                               ResourceAIModule::incrementResources
    //                              airesmod.cpp:356 (3)
    //         00412820     PUSH       EBX
    //         00412821     PUSH       ESI
    //         00412822     PUSH       EDI
    //                              airesmod.cpp:357 (10)
    //         00412823     MOV        EDI,dword ptr [ESP + param_1]
    //         00412827     TEST       EDI,EDI
    //         00412829     MOV        EBX,this
    //         0041282b     JZ         LAB_00412866
    //                              airesmod.cpp:361 (15)
    //         0041282d     MOV        this,EDI
    //         0041282f     CALL       ResourceItem::number                             int number(ResourceItem * this)
    //         00412834     CMP        dword ptr [EBX + 0xf4],EAX
    //         0041283a     JNZ        LAB_00412866
    //                              airesmod.cpp:363 (13)
    //         0041283c     MOV        this,EDI
    //         0041283e     XOR        ESI,ESI
    //         00412840     CALL       ResourceItem::number                             int number(ResourceItem * this)
    //         00412845     TEST       EAX,EAX
    //         00412847     JLE        LAB_00412866
    //                               LAB_00412849                                                 XREF[1]:     00412864(j)  
    //                              airesmod.cpp:364 (29)
    //         00412849     PUSH       ESI
    //         0041284a     MOV        this,EDI
    //         0041284c     CALL       ResourceItem::value                              int value(ResourceItem * this, int param_1)
    //         00412851     PUSH       EAX
    //         00412852     PUSH       ESI
    //         00412853     MOV        this,EBX
    //         00412855     CALL       ResourceAIModule::incrementResource              void incrementResource(ResourceAIModule * thi
    //         0041285a     MOV        this,EDI
    //         0041285c     INC        ESI
    //         0041285d     CALL       ResourceItem::number                             int number(ResourceItem * this)
    //         00412862     CMP        ESI,EAX
    //         00412864     JL         LAB_00412849
    //                               LAB_00412866                                                 XREF[3]:     0041282b(j), 0041283a(j), 
    //                                                                                                         00412847(j)  
    //                              airesmod.cpp:365 (6)
    //         00412866     POP        EDI
    //         00412867     POP        ESI
    //         00412868     POP        EBX
    //         00412869     RET        0x4
    //         0041286c     ??         90h
    //         0041286d     NOP
    //         0041286e     NOP
    //         0041286f     NOP
    return;
}

void ResourceAIModule::decrementResource(int param_1, int param_2) {
    /* TODO: Stub */
    //                              void __thiscall decrementResource(ResourceAIModule * this, int param
    //              void              <VOID>         <RETURN>
    //              ResourceAIModu    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00412877(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00412871(R)  
    //                               ?decrementResource@ResourceAIModule@@QAEXHH@Z                XREF[1]:     decrementResources:00412905(c)  
    //                               ResourceAIModule::decrementResource
    //                              airesmod.cpp:370 (1)
    //         00412870     PUSH       EBX
    //                              airesmod.cpp:371 (28)
    //         00412871     MOV        EBX,dword ptr [ESP + param_2]
    //         00412875     PUSH       ESI
    //         00412876     PUSH       EDI
    //         00412877     MOV        EDI,dword ptr [ESP + param_1]
    //         0041287b     PUSH       EBX
    //         0041287c     MOV        ESI,this
    //         0041287e     PUSH       EDI
    //         0041287f     PUSH       s_decrementResource:_n=%d,_v=%d.                 = "decrementResource: n=%d, v=%d."
    //         00412884     PUSH       ESI
    //         00412885     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
    //         0041288a     ADD        ESP,0x10
    //                              airesmod.cpp:372 (12)
    //         0041288d     TEST       EDI,EDI
    //         0041288f     JL         LAB_004128c6
    //         00412891     CMP        EDI,dword ptr [ESI + 0xf4]
    //         00412897     JGE        LAB_004128c6
    //                              airesmod.cpp:373 (14)
    //         00412899     MOV        EAX,dword ptr [ESI + 0xf8]
    //         0041289f     MOV        this,dword ptr [EAX + EDI*0x4]
    //         004128a2     LEA        EAX,[EAX + EDI*0x4]
    //         004128a5     SUB        this,EBX
    //                              airesmod.cpp:374 (6)
    //         004128a7     TEST       EBX,EBX
    //         004128a9     MOV        dword ptr [EAX],this
    //         004128ab     JZ         LAB_004128c6
    //                              airesmod.cpp:375 (25)
    //         004128ad     MOV        this,dword ptr [ESI + 0xf8]
    //         004128b3     MOV        EDX,dword ptr [this->_padding_ + EDI*0x4]
    //         004128b6     PUSH       EDX
    //         004128b7     PUSH       EDI
    //         004128b8     PUSH       s___decrementResource:_r[%d]=%d.                 = "  decrementResource: r[%d]=%d."
    //         004128bd     PUSH       ESI
    //         004128be     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
    //         004128c3     ADD        ESP,0x10
    //                               LAB_004128c6                                                 XREF[3]:     0041288f(j), 00412897(j), 
    //                                                                                                         004128ab(j)  
    //                              airesmod.cpp:377 (6)
    //         004128c6     POP        EDI
    //         004128c7     POP        ESI
    //         004128c8     POP        EBX
    //         004128c9     RET        0x8
    //         004128cc     ??         90h
    //         004128cd     NOP
    //         004128ce     NOP
    //         004128cf     NOP
    return;
}

void ResourceAIModule::decrementResources(ResourceItem* param_1) {
    /* TODO: Stub */
    //                              void __thiscall decrementResources(ResourceAIModule * this, Resource
    //              void              <VOID>         <RETURN>
    //              ResourceAIModu    ECX:4 (auto)   this
    //              ResourceItem *    Stack[0x4]:4   param_1                   XREF[1]:     004128d3(R)  
    //                               ?decrementResources@ResourceAIModule@@QAEXPAVResourceItem@@@Z
    //                               ResourceAIModule::decrementResources
    //                              airesmod.cpp:382 (3)
    //         004128d0     PUSH       EBX
    //         004128d1     PUSH       ESI
    //         004128d2     PUSH       EDI
    //                              airesmod.cpp:383 (10)
    //         004128d3     MOV        EDI,dword ptr [ESP + param_1]
    //         004128d7     TEST       EDI,EDI
    //         004128d9     MOV        EBX,this
    //         004128db     JZ         LAB_00412916
    //                              airesmod.cpp:387 (15)
    //         004128dd     MOV        this,EDI
    //         004128df     CALL       ResourceItem::number                             int number(ResourceItem * this)
    //         004128e4     CMP        dword ptr [EBX + 0xf4],EAX
    //         004128ea     JNZ        LAB_00412916
    //                              airesmod.cpp:389 (13)
    //         004128ec     MOV        this,EDI
    //         004128ee     XOR        ESI,ESI
    //         004128f0     CALL       ResourceItem::number                             int number(ResourceItem * this)
    //         004128f5     TEST       EAX,EAX
    //         004128f7     JLE        LAB_00412916
    //                               LAB_004128f9                                                 XREF[1]:     00412914(j)  
    //                              airesmod.cpp:390 (29)
    //         004128f9     PUSH       ESI
    //         004128fa     MOV        this,EDI
    //         004128fc     CALL       ResourceItem::value                              int value(ResourceItem * this, int param_1)
    //         00412901     PUSH       EAX
    //         00412902     PUSH       ESI
    //         00412903     MOV        this,EBX
    //         00412905     CALL       ResourceAIModule::decrementResource              void decrementResource(ResourceAIModule * thi
    //         0041290a     MOV        this,EDI
    //         0041290c     INC        ESI
    //         0041290d     CALL       ResourceItem::number                             int number(ResourceItem * this)
    //         00412912     CMP        ESI,EAX
    //         00412914     JL         LAB_004128f9
    //                               LAB_00412916                                                 XREF[3]:     004128db(j), 004128ea(j), 
    //                                                                                                         004128f7(j)  
    //                              airesmod.cpp:391 (6)
    //         00412916     POP        EDI
    //         00412917     POP        ESI
    //         00412918     POP        EBX
    //         00412919     RET        0x4
    //         0041291c     ??         90h
    //         0041291d     NOP
    //         0041291e     NOP
    //         0041291f     NOP
    return;
}

void ResourceAIModule::setResourceMin(int param_1, int param_2) {
    /* TODO: Stub */
    //                              void __thiscall setResourceMin(ResourceAIModule * this, int param_1,
    //              void              <VOID>         <RETURN>
    //              ResourceAIModu    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00412920(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00412936(R)  
    //                               ?setResourceMin@ResourceAIModule@@QAEXHH@Z
    //                               ResourceAIModule::setResourceMin
    //                              airesmod.cpp:396 (16)
    //         00412920     MOV        EAX,dword ptr [ESP + param_1]
    //         00412924     TEST       EAX,EAX
    //         00412926     JL         LAB_0041293d
    //         00412928     CMP        EAX,dword ptr [ECX + this->numberResourcesValue]
    //         0041292e     JGE        LAB_0041293d
    //                              airesmod.cpp:398 (13)
    //         00412930     MOV        this,dword ptr [ECX + this->minValue]
    //         00412936     MOV        EDX,dword ptr [ESP + param_2]
    //         0041293a     MOV        dword ptr [this->_padding_ + EAX*0x4],EDX
    //                               LAB_0041293d                                                 XREF[2]:     00412926(j), 0041292e(j)  
    //                              airesmod.cpp:399 (3)
    //         0041293d     RET        0x8
    return;
}

void ResourceAIModule::setResourceMax(int param_1, int param_2) {
    /* TODO: Stub */
    //                              void __thiscall setResourceMax(ResourceAIModule * this, int param_1,
    //              void              <VOID>         <RETURN>
    //              ResourceAIModu    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00412940(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00412956(R)  
    //                               ?setResourceMax@ResourceAIModule@@QAEXHH@Z
    //                               ResourceAIModule::setResourceMax
    //                              airesmod.cpp:404 (16)
    //         00412940     MOV        EAX,dword ptr [ESP + param_1]
    //         00412944     TEST       EAX,EAX
    //         00412946     JL         LAB_0041295d
    //         00412948     CMP        EAX,dword ptr [ECX + this->numberResourcesValue]
    //         0041294e     JGE        LAB_0041295d
    //                              airesmod.cpp:406 (13)
    //         00412950     MOV        this,dword ptr [ECX + this->maxValue]
    //         00412956     MOV        EDX,dword ptr [ESP + param_2]
    //         0041295a     MOV        dword ptr [this->_padding_ + EAX*0x4],EDX
    //                               LAB_0041295d                                                 XREF[2]:     00412946(j), 0041294e(j)  
    //                              airesmod.cpp:407 (3)
    //         0041295d     RET        0x8
    return;
}

int ResourceAIModule::filterOutMessage(AIModuleMessage* param_1) {
    /* TODO: Stub */
    //                              int __thiscall filterOutMessage(ResourceAIModule * this, AIModuleMes
    //              int               EAX:4          <RETURN>
    //              ResourceAIModu    ECX:4 (auto)   this
    //              AIModuleMessag    Stack[0x4]:4   param_1                   XREF[1]:     00412960(R)  
    //                               ?filterOutMessage@ResourceAIModule@@MAEHPAVAIModuleMessage@  XREF[1]:     0056ea10(*)  
    //                               ResourceAIModule::filterOutMessage
    //                              airesmod.cpp:412 (10)
    //         00412960     MOV        EAX,dword ptr [ESP + param_1]
    //         00412964     PUSH       EAX
    //         00412965     CALL       AIModule::filterOutMessage                       int filterOutMessage(AIModule * this, AIModul
    //                              airesmod.cpp:414 (3)
    //         0041296a     RET        0x4
    //         0041296d     ??         90h
    //         0041296e     NOP
    //         0041296f     NOP
    return 0;
}

void ResourceAIModule::addResourceType(int param_1, int param_2) {
    /* TODO: Stub */
    //                              void __thiscall addResourceType(ResourceAIModule * this, int param_1
    //              void              <VOID>         <RETURN>
    //              ResourceAIModu    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00412970(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004129c6(R)  
    //                               ?addResourceType@ResourceAIModule@@QAEXHH@Z
    //                               ResourceAIModule::addResourceType
    //                              airesmod.cpp:419 (38)
    //         00412970     MOV        EAX,dword ptr [ESP + param_1]
    //         00412974     PUSH       EBX
    //         00412975     PUSH       ESI
    //         00412976     MOV        ESI,this
    //         00412978     PUSH       EDI
    //         00412979     LEA        EDI,[EAX*0x4 + 0x0]
    //         00412980     MOV        this,dword ptr [ESI + 0x108]
    //         00412986     MOV        EDX,dword ptr [this->_padding_ + EDI*0x1]
    //         00412989     LEA        EAX,[EDX*0x4 + 0x4]
    //         00412990     PUSH       EAX
    //         00412991     CALL       operator_new                                     void * operator_new(uint param_1)
    //                              airesmod.cpp:426 (19)
    //         00412996     MOV        this,dword ptr [ESI + 0x108]
    //         0041299c     MOV        EBX,EAX
    //         0041299e     ADD        ESP,0x4
    //         004129a1     XOR        EAX,EAX
    //         004129a3     CMP        dword ptr [this->_padding_ + EDI*0x1],0x0
    //         004129a7     JLE        LAB_004129c6
    //                               LAB_004129a9                                                 XREF[1]:     004129c4(j)  
    //                              airesmod.cpp:428 (29)
    //         004129a9     MOV        EDX,dword ptr [ESI + 0x104]
    //         004129af     INC        EAX
    //         004129b0     MOV        this,dword ptr [EDX + EDI*0x1]
    //         004129b3     MOV        EDX,dword ptr [this->_padding_ + EAX*0x4 + -0x4]
    //         004129b7     MOV        dword ptr [EBX + EAX*0x4 + -0x4],EDX
    //         004129bb     MOV        this,dword ptr [ESI + 0x108]
    //         004129c1     CMP        EAX,dword ptr [this->_padding_ + EDI*0x1]
    //         004129c4     JL         LAB_004129a9
    //                               LAB_004129c6                                                 XREF[1]:     004129a7(j)  
    //                              airesmod.cpp:430 (7)
    //         004129c6     MOV        EDX,dword ptr [ESP + param_2]
    //         004129ca     MOV        dword ptr [EBX + EAX*0x4],EDX
    //                              airesmod.cpp:432 (13)
    //         004129cd     MOV        EAX,dword ptr [ESI + 0x104]
    //         004129d3     MOV        EAX,dword ptr [EAX + EDI*0x1]
    //         004129d6     TEST       EAX,EAX
    //         004129d8     JZ         LAB_004129e3
    //                              airesmod.cpp:433 (9)
    //         004129da     PUSH       EAX
    //         004129db     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004129e0     ADD        ESP,0x4
    //                               LAB_004129e3                                                 XREF[1]:     004129d8(j)  
    //                              airesmod.cpp:434 (9)
    //         004129e3     MOV        this,dword ptr [ESI + 0x104]
    //         004129e9     MOV        dword ptr [this->_padding_ + EDI*0x1],EBX
    //                              airesmod.cpp:435 (13)
    //         004129ec     MOV        EDX,dword ptr [ESI + 0x108]
    //         004129f2     MOV        this,dword ptr [EDX + EDI*0x1]
    //         004129f5     LEA        EAX,[EDX + EDI*0x1]
    //         004129f8     INC        this
    //                              airesmod.cpp:437 (8)
    //         004129f9     POP        EDI
    //         004129fa     POP        ESI
    //         004129fb     MOV        dword ptr [EAX],this
    //         004129fd     POP        EBX
    //         004129fe     RET        0x8
    //         00412a01     ??         90h
    //         00412a02     NOP
    //         00412a03     NOP
    //         00412a04     NOP
    //         00412a05     NOP
    //         00412a06     NOP
    //         00412a07     NOP
    //         00412a08     NOP
    //         00412a09     NOP
    //         00412a0a     NOP
    //         00412a0b     NOP
    //         00412a0c     NOP
    //         00412a0d     NOP
    //         00412a0e     NOP
    //         00412a0f     NOP
    return;
}

int ResourceAIModule::isResourceType(int param_1, int param_2) {
    /* TODO: Stub */
    //                              int __thiscall isResourceType(ResourceAIModule * this, int param_1, 
    //              int               EAX:4          <RETURN>
    //              ResourceAIModu    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00412a11(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00412a16(R)  
    //                               ?isResourceType@ResourceAIModule@@QAEHHH@Z
    //                               ResourceAIModule::isResourceType
    //                              airesmod.cpp:442 (1)
    //         00412a10     PUSH       EBX
    //                              airesmod.cpp:443 (26)
    //         00412a11     MOV        EBX,dword ptr [ESP + param_1]
    //         00412a15     PUSH       EBP
    //         00412a16     MOV        EBP,dword ptr [ESP + param_2]
    //         00412a1a     PUSH       ESI
    //         00412a1b     PUSH       EDI
    //         00412a1c     PUSH       EBP
    //         00412a1d     MOV        ESI,this
    //         00412a1f     PUSH       EBX
    //         00412a20     PUSH       s_Entering_isResourceType:_r=%d,_t               = "Entering isResourceType: r=%d, t=%d."
    //         00412a25     PUSH       ESI
    //         00412a26     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
    //                              airesmod.cpp:445 (32)
    //         00412a2b     MOV        EAX,dword ptr [ESI + 0x108]
    //         00412a31     LEA        EDI,[EBX*0x4 + 0x0]
    //         00412a38     ADD        ESP,0x10
    //         00412a3b     MOV        this,dword ptr [EAX + EDI*0x1]
    //         00412a3e     PUSH       EBX
    //         00412a3f     PUSH       this
    //         00412a40     PUSH       s___There_are_%d_resource_types_fo               = "  There are %d resource types for resource
    //         00412a45     PUSH       ESI
    //         00412a46     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
    //                              airesmod.cpp:446 (17)
    //         00412a4b     MOV        EDX,dword ptr [ESI + 0x108]
    //         00412a51     ADD        ESP,0x10
    //         00412a54     XOR        EBX,EBX
    //         00412a56     CMP        dword ptr [EDX + EDI*0x1],0x0
    //         00412a5a     JLE        LAB_00412a91
    //                              airesmod.cpp:447 (24)
    //         00412a5c     MOV        EAX,dword ptr [ESI + 0x104]
    //         00412a62     MOV        EAX,dword ptr [EAX + EDI*0x1]
    //                               LAB_00412a65                                                 XREF[1]:     00412a8f(j)  
    //         00412a65     MOV        this,dword ptr [EAX + EBX*0x4]
    //         00412a68     PUSH       this
    //         00412a69     PUSH       s_____Checking_against_type_%d.                  = "    Checking against type %d."
    //         00412a6e     PUSH       ESI
    //         00412a6f     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
    //                              airesmod.cpp:448 (29)
    //         00412a74     MOV        EDX,dword ptr [ESI + 0x104]
    //         00412a7a     ADD        ESP,0xc
    //         00412a7d     MOV        EAX,dword ptr [EDX + EDI*0x1]
    //         00412a80     CMP        dword ptr [EAX + EBX*0x4],EBP
    //         00412a83     JZ         LAB_00412aa8
    //         00412a85     MOV        this,dword ptr [ESI + 0x108]
    //         00412a8b     INC        EBX
    //         00412a8c     CMP        EBX,dword ptr [this->_padding_ + EDI*0x1]
    //         00412a8f     JL         LAB_00412a65
    //                               LAB_00412a91                                                 XREF[1]:     00412a5a(j)  
    //                              airesmod.cpp:453 (14)
    //         00412a91     PUSH       s___No_match!__Returning_FALSE.                  = "  No match!  Returning FALSE."
    //         00412a96     PUSH       ESI
    //         00412a97     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
    //         00412a9c     ADD        ESP,0x8
    //                              airesmod.cpp:454 (2)
    //         00412a9f     XOR        EAX,EAX
    //                              airesmod.cpp:455 (7)
    //         00412aa1     POP        EDI
    //         00412aa2     POP        ESI
    //         00412aa3     POP        EBP
    //         00412aa4     POP        EBX
    //         00412aa5     RET        0x8
    //                               LAB_00412aa8                                                 XREF[1]:     00412a83(j)  
    //                              airesmod.cpp:449 (14)
    //         00412aa8     PUSH       s_______Match!__Returning_TRUE.                  = "      Match!  Returning TRUE."
    //         00412aad     PUSH       ESI
    //         00412aae     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
    //         00412ab3     ADD        ESP,0x8
    //                              airesmod.cpp:450 (5)
    //         00412ab6     MOV        EAX,0x1
    //                              airesmod.cpp:455 (7)
    //         00412abb     POP        EDI
    //         00412abc     POP        ESI
    //         00412abd     POP        EBP
    //         00412abe     POP        EBX
    //         00412abf     RET        0x8
    //         00412ac2     ??         90h
    //         00412ac3     NOP
    //         00412ac4     NOP
    //         00412ac5     NOP
    //         00412ac6     NOP
    //         00412ac7     NOP
    //         00412ac8     NOP
    //         00412ac9     NOP
    //         00412aca     NOP
    //         00412acb     NOP
    //         00412acc     NOP
    //         00412acd     NOP
    //         00412ace     NOP
    //         00412acf     NOP
    return 0;
}

int ResourceAIModule::numberResourceTypes(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall numberResourceTypes(ResourceAIModule * this, int para
    //              int               EAX:4          <RETURN>
    //              ResourceAIModu    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00412ad6(R)  
    //                               ?numberResourceTypes@ResourceAIModule@@QAEHH@Z
    //                               ResourceAIModule::numberResourceTypes
    //                              airesmod.cpp:460 (13)
    //         00412ad0     MOV        EAX,dword ptr [ECX + this->numberResourceTypes
    //         00412ad6     MOV        this,dword ptr [ESP + param_1]
    //         00412ada     MOV        EAX,dword ptr [EAX + this->_padding_*0x4]
    //                              airesmod.cpp:462 (3)
    //         00412add     RET        0x4
    //                              * public: int __thiscall ResourceAIModule::lowestResourceType(void)const                                *
    //                              int __thiscall lowestResourceType(ResourceAIModule * this)
    //              int               EAX:4          <RETURN>
    //              ResourceAIModu    ECX:4 (auto)   this
    //                               ?lowestResourceType@ResourceAIModule@@QBEHXZ
    //                               ResourceAIModule::lowestResourceType
    //                              airesmod.cpp:467 (5)
    //         00412ae0     MOV        EAX,0x1
    //                              airesmod.cpp:469 (1)
    //         00412ae5     RET
    //         00412ae6     ??         90h
    //         00412ae7     NOP
    //         00412ae8     NOP
    //         00412ae9     NOP
    //         00412aea     NOP
    //         00412aeb     NOP
    //         00412aec     NOP
    //         00412aed     NOP
    //         00412aee     NOP
    //         00412aef     NOP
    return 0;
}

int ResourceAIModule::numberResources() {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int ResourceAIModule::resource(int param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int ResourceAIModule::minValueOfResource(int param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int ResourceAIModule::maxValueOfResource(int param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int ResourceAIModule::lowestResourceType() {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

