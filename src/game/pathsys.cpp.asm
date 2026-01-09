#include "common.h"
#include "pathsys.h"

PathingSystem::PathingSystem(int param_1, int param_2, int param_3, RGE_Map* param_4, RGE_Game_World* param_5) {
    /* TODO: Stub */
    //                              undefined __thiscall PathingSystem(PathingSystem * this, int param_1
    //              undefined         <UNASSIGNED>   <RETURN>
    //              PathingSystem *   ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0046b15a(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0046b170(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[5]:     0046b144(R), 0046b1fe(W), 0046b207(R), 0046b222(R), 
    //                                                                                     0046b232(W)  
    //              RGE_Map *         Stack[0x10]:4  param_4                   XREF[1]:     0046b14c(R)  
    //              RGE_Game_World    Stack[0x14]:4  param_5                   XREF[1]:     0046b148(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0046b128(W), 0046b179(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0046b238(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0046b10c(W)  
    //                               ??0PathingSystem@@QAE@HHHPAVRGE_Map@@PAVRGE_Game_World@@@Z   XREF[2]:     $E9:0046b075(c), $E14:0046b0c5(c)  
    //                               PathingSystem::PathingSystem
    //                              pathsys.cpp:104 (84)
    //         0046b0f0     PUSH       -0x1
    //         0046b0f2     PUSH       FUN_0055e1ec
    //         0046b0f7     MOV        EAX,FS:[0x0]
    //         0046b0fd     PUSH       EAX
    //         0046b0fe     MOV        dword ptr FS:[0x0],ESP
    //         0046b105     PUSH       this
    //         0046b106     PUSH       ESI
    //         0046b107     PUSH       EDI
    //         0046b108     MOV        ESI,this
    //         0046b10a     XOR        EDI,EDI
    //         0046b10c     MOV        dword ptr [ESP + local_10],ESI
    //         0046b110     MOV        dword ptr [ESI + 0x11dc64],EDI
    //         0046b116     MOV        dword ptr [ESI + 0x11dc68],EDI
    //         0046b11c     MOV        dword ptr [ESI + 0x11dc6c],EDI
    //         0046b122     MOV        dword ptr [ESI + 0x11dc70],EDI
    //         0046b128     MOV        dword ptr [ESP + local_4],EDI
    //         0046b12c     MOV        dword ptr [ESI + 0x11dce4],EDI
    //         0046b132     MOV        dword ptr [ESI + 0x11dce8],EDI
    //         0046b138     MOV        dword ptr [ESI + 0x11dcec],EDI
    //         0046b13e     MOV        dword ptr [ESI + 0x11dcf0],EDI
    //                              pathsys.cpp:105 (4)
    //         0046b144     MOV        EAX,dword ptr [ESP + param_3]
    //                              pathsys.cpp:128 (167)
    //         0046b148     MOV        this,dword ptr [ESP + param_5]
    //         0046b14c     MOV        EDX,dword ptr [ESP + param_4]
    //         0046b150     MOV        dword ptr [ESI + 0x11dcf4],EAX
    //         0046b156     OR         EAX,0xffffffff
    //         0046b159     PUSH       this
    //         0046b15a     MOV        this,dword ptr [ESP + param_1]
    //         0046b15e     MOV        dword ptr [ESI + 0x4],EAX
    //         0046b161     MOV        dword ptr [ESI + 0x8],EAX
    //         0046b164     MOV        dword ptr [ESI + 0x11dc5c],EAX
    //         0046b16a     MOV        dword ptr [ESI + 0x11dc60],EAX
    //         0046b170     MOV        EAX,dword ptr [ESP + param_2]
    //         0046b174     PUSH       EDX
    //         0046b175     PUSH       EAX
    //         0046b176     PUSH       this
    //         0046b177     MOV        this,ESI
    //         0046b179     MOV        byte ptr [ESP + local_4],0x1
    //         0046b17e     MOV        dword ptr [ESI],PathingSystem::`vftable'         = 0046b250
    //         0046b184     MOV        dword ptr [ESI + 0x11dc2c],EDI
    //         0046b18a     MOV        dword ptr [ESI + 0x11dc38],EDI
    //         0046b190     MOV        dword ptr [ESI + 0x11dc3c],EDI
    //         0046b196     MOV        dword ptr [ESI + 0x11dc40],EDI
    //         0046b19c     MOV        dword ptr [ESI + 0x11dc44],EDI
    //         0046b1a2     MOV        dword ptr [ESI + 0x11dca4],EDI
    //         0046b1a8     MOV        dword ptr [ESI + 0x11dca8],EDI
    //         0046b1ae     MOV        dword ptr [ESI + 0x11dcac],EDI
    //         0046b1b4     MOV        dword ptr [ESI + 0x11dccc],EDI
    //         0046b1ba     MOV        dword ptr [ESI + 0x11dcb0],EDI
    //         0046b1c0     MOV        dword ptr [ESI + 0x11dcb4],EDI
    //         0046b1c6     MOV        dword ptr [ESI + 0x11dcb8],EDI
    //         0046b1cc     MOV        dword ptr [ESI + 0x11dcbc],EDI
    //         0046b1d2     MOV        dword ptr [ESI + 0x11dcc0],EDI
    //         0046b1d8     MOV        dword ptr [ESI + 0x11dcc4],EDI
    //         0046b1de     MOV        dword ptr [ESI + 0x11dcd0],EDI
    //         0046b1e4     MOV        dword ptr [ESI + 0x11dcd4],EDI
    //         0046b1ea     CALL       PathingSystem::initialize                        int initialize(PathingSystem * this, int para
    //                              pathsys.cpp:129 (8)
    //         0046b1ef     PUSH       EDI
    //         0046b1f0     MOV        this,ESI
    //         0046b1f2     CALL       PathingSystem::initMisc                          void initMisc(PathingSystem * this, uchar par
    //                              pathsys.cpp:130 (7)
    //         0046b1f7     MOV        this,ESI
    //         0046b1f9     CALL       PathingSystem::zeroObstructionMap                void zeroObstructionMap(PathingSystem * this)
    //                              pathsys.cpp:132 (9)
    //         0046b1fe     MOV        dword ptr [ESP + param_3],EDI
    //         0046b202     MOV        EDI,DiagionalDistance                            = 00000000
    //                               LAB_0046b207                                                 XREF[1]:     0046b236(j)  
    //                              pathsys.cpp:134 (49)
    //         0046b207     FILD       dword ptr [ESP + param_3]
    //         0046b20b     FMUL       float ptr [DAT_00570e48]                         = 81h
    //         0046b211     FMUL       float ptr [DAT_00570e4c]
    //         0046b217     FSUBR      float ptr [DAT_00570e50]
    //         0046b21d     CALL       __ftol                                           undefined __ftol()
    //         0046b222     MOV        EDX,dword ptr [ESP + param_3]
    //         0046b226     MOV        dword ptr [EDI]=>DiagionalDistance,EAX           = 00000000
    //         0046b228     ADD        EDI,0x4
    //         0046b22b     INC        EDX
    //         0046b22c     CMP        EDI,pathSystem
    //         0046b232     MOV        dword ptr [ESP + param_3],EDX
    //         0046b236     JL         LAB_0046b207
    //                              pathsys.cpp:136 (21)
    //         0046b238     MOV        this,dword ptr [ESP + local_c]
    //         0046b23c     MOV        EAX,ESI
    //         0046b23e     POP        EDI
    //         0046b23f     MOV        dword ptr FS:[0x0],this
    //         0046b246     POP        ESI
    //         0046b247     ADD        ESP,0x10
    //         0046b24a     RET        0x14
    //         0046b24d     ??         90h
    //         0046b24e     NOP
    //         0046b24f     NOP
}

PathingSystem::~PathingSystem() {
    /* TODO: Stub */
    //                              void __thiscall ~PathingSystem(PathingSystem * this)
    //              void              <VOID>         <RETURN>
    //              PathingSystem *   ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0046b299(W), 0046b2c8(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0046b2e1(R)  
    //                               ??1PathingSystem@@UAE@XZ                                     XREF[3]:     $E10:0046b095(c), 
    //                               PathingSystem::~PathingSystem                                             $E15:0046b0e5(c), 
    //                                                                                                         `vector_deleting_destructor':0046b
    //                              pathsys.cpp:142 (80)
    //         0046b270     MOV        EAX,FS:[0x0]
    //         0046b276     PUSH       -0x1
    //         0046b278     PUSH       FUN_0055e20e
    //         0046b27d     PUSH       EAX
    //         0046b27e     MOV        dword ptr FS:[0x0],ESP
    //         0046b285     PUSH       ESI
    //         0046b286     MOV        ESI,this
    //         0046b288     PUSH       EDI
    //         0046b289     MOV        dword ptr [ESI],PathingSystem::`vftable'         = 0046b250
    //         0046b28f     MOV        EAX,dword ptr [ESI + 0x11dce4]
    //         0046b295     XOR        EDI,EDI
    //         0046b297     CMP        EAX,EDI
    //         0046b299     MOV        dword ptr [ESP + local_4],EDI
    //         0046b29d     JZ         LAB_0046b2ae
    //         0046b29f     PUSH       EAX
    //         0046b2a0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0046b2a5     ADD        ESP,0x4
    //         0046b2a8     MOV        dword ptr [ESI + 0x11dce4],EDI
    //                               LAB_0046b2ae                                                 XREF[1]:     0046b29d(j)  
    //         0046b2ae     MOV        dword ptr [ESI + 0x11dce8],EDI
    //         0046b2b4     MOV        dword ptr [ESI + 0x11dcec],EDI
    //         0046b2ba     MOV        dword ptr [ESI + 0x11dcf0],EDI
    //                              pathsys.cpp:144 (68)
    //         0046b2c0     MOV        EAX,dword ptr [ESI + 0x11dc64]
    //         0046b2c6     CMP        EAX,EDI
    //         0046b2c8     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0046b2d0     JZ         LAB_0046b2e1
    //         0046b2d2     PUSH       EAX
    //         0046b2d3     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0046b2d8     ADD        ESP,0x4
    //         0046b2db     MOV        dword ptr [ESI + 0x11dc64],EDI
    //                               LAB_0046b2e1                                                 XREF[1]:     0046b2d0(j)  
    //         0046b2e1     MOV        this,dword ptr [ESP + local_c]
    //         0046b2e5     MOV        dword ptr [ESI + 0x11dc68],EDI
    //         0046b2eb     MOV        dword ptr [ESI + 0x11dc6c],EDI
    //         0046b2f1     MOV        dword ptr [ESI + 0x11dc70],EDI
    //         0046b2f7     POP        EDI
    //         0046b2f8     MOV        dword ptr FS:[0x0],this
    //         0046b2ff     POP        ESI
    //         0046b300     ADD        ESP,0xc
    //         0046b303     RET
    //         0046b304     ??         90h
    //         0046b305     NOP
    //         0046b306     NOP
    //         0046b307     NOP
    //         0046b308     NOP
    //         0046b309     NOP
    //         0046b30a     NOP
    //         0046b30b     NOP
    //         0046b30c     NOP
    //         0046b30d     NOP
    //         0046b30e     NOP
    //         0046b30f     NOP
}

int PathingSystem::initialize(int param_1, int param_2, RGE_Map* param_3, RGE_Game_World* param_4) {
    /* TODO: Stub */
    //                              int __thiscall initialize(PathingSystem * this, int param_1, int par
    //              int               EAX:4          <RETURN>
    //              PathingSystem *   ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0046b347(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0046b343(R)  
    //              RGE_Map *         Stack[0xc]:4   param_3                   XREF[1]:     0046b310(R)  
    //              RGE_Game_World    Stack[0x10]:4  param_4                   XREF[1]:     0046b314(R)  
    //                               ?initialize@PathingSystem@@QAEHHHPAVRGE_Map@@PAVRGE_Game_Wo  XREF[3]:     PathingSystem:0046b1ea(c), 
    //                               PathingSystem::initialize                                                 initializePathingSystem:0054604b(c
    //                                                                                                         initializePathingSystem:00546062(c
    //                              pathsys.cpp:150 (4)
    //         0046b310     MOV        EAX,dword ptr [ESP + param_3]
    //                              pathsys.cpp:152 (4)
    //         0046b314     MOV        EDX,dword ptr [ESP + param_4]
    //                              pathsys.cpp:153 (16)
    //         0046b318     TEST       EAX,EAX
    //         0046b31a     MOV        dword ptr [ECX + this->mapValue],EAX
    //         0046b320     MOV        dword ptr [ECX + this->worldValue],EDX
    //         0046b326     JZ         LAB_0046b343
    //                              pathsys.cpp:155 (6)
    //         0046b328     MOV        EDX,dword ptr [EAX + 0x8]
    //         0046b32b     MOV        dword ptr [ECX + this->xSizeValue],EDX
    //                              pathsys.cpp:156 (3)
    //         0046b32e     MOV        EAX,dword ptr [EAX + 0xc]
    //                              pathsys.cpp:161 (3)
    //         0046b331     MOV        dword ptr [ECX + this->ySizeValue],EAX
    //                              pathsys.cpp:164 (7)
    //         0046b334     MOV        byte ptr [ECX + this->CurrentFacetMask],0xf0
    //                              pathsys.cpp:166 (5)
    //         0046b33b     MOV        EAX,0x1
    //                              pathsys.cpp:167 (3)
    //         0046b340     RET        0x10
    //                               LAB_0046b343                                                 XREF[1]:     0046b326(j)  
    //                              pathsys.cpp:161 (14)
    //         0046b343     MOV        EAX,dword ptr [ESP + param_2]
    //         0046b347     MOV        EDX,dword ptr [ESP + param_1]
    //         0046b34b     MOV        dword ptr [ECX + this->ySizeValue],EAX
    //         0046b34e     MOV        dword ptr [ECX + this->xSizeValue],EDX
    //                              pathsys.cpp:164 (7)
    //         0046b351     MOV        byte ptr [ECX + this->CurrentFacetMask],0xf0
    //                              pathsys.cpp:166 (5)
    //         0046b358     MOV        EAX,0x1
    //                              pathsys.cpp:167 (3)
    //         0046b35d     RET        0x10
    return 0;
}

void PathingSystem::printToFile(char* param_1) {
    /* TODO: Stub */
    //                              void __thiscall printToFile(PathingSystem * this, char * param_1)
    //              void              <VOID>         <RETURN>
    //              PathingSystem *   ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0046b363(R)  
    //                               ?printToFile@PathingSystem@@QAEXPAD@Z
    //                               PathingSystem::printToFile
    //                              pathsys.cpp:172 (3)
    //         0046b360     PUSH       EBP
    //         0046b361     PUSH       ESI
    //         0046b362     PUSH       EDI
    //                              pathsys.cpp:173 (14)
    //         0046b363     MOV        EDI,dword ptr [ESP + param_1]
    //         0046b367     TEST       EDI,EDI
    //         0046b369     MOV        EBP,this
    //         0046b36b     JZ         LAB_0046b540
    //                              pathsys.cpp:175 (16)
    //         0046b371     PUSH       s_wa                                             = "wa"
    //         0046b376     PUSH       EDI
    //         0046b377     CALL       fopen                                            undefined fopen()
    //         0046b37c     MOV        ESI,EAX
    //         0046b37e     ADD        ESP,0x8
    //                              pathsys.cpp:176 (9)
    //         0046b381     TEST       ESI,ESI
    //         0046b383     JZ         LAB_0046b540
    //         0046b389     PUSH       EBX
    //                              pathsys.cpp:180 (12)
    //         0046b38a     PUSH       EDI
    //         0046b38b     PUSH       s_FILENAME:_%s_                                  = "FILENAME: %s\n"
    //         0046b390     PUSH       ESI
    //         0046b391     CALL       fprintf                                          undefined fprintf()
    //                              pathsys.cpp:181 (31)
    //         0046b396     MOV        EAX,dword ptr [EBP + 0x8]
    //         0046b399     MOV        this,dword ptr [EBP + 0x4]
    //         0046b39c     ADD        ESP,0xc
    //         0046b39f     SHL        EAX,0x2
    //         0046b3a2     SHL        this,0x2
    //         0046b3a5     PUSH       EAX
    //         0046b3a6     PUSH       this
    //         0046b3a7     PUSH       s___Dimensions:_%d_X_%d_                         = "  Dimensions: %d X %d\n"
    //         0046b3ac     PUSH       ESI
    //         0046b3ad     CALL       fprintf                                          undefined fprintf()
    //         0046b3b2     ADD        ESP,0x10
    //                              pathsys.cpp:182 (14)
    //         0046b3b5     PUSH       s__                                              = 0Ah
    //         0046b3ba     PUSH       ESI
    //         0046b3bb     CALL       fprintf                                          undefined fprintf()
    //         0046b3c0     ADD        ESP,0x8
    //                              pathsys.cpp:185 (11)
    //         0046b3c3     PUSH       s________                                        = "       "
    //         0046b3c8     PUSH       ESI
    //         0046b3c9     CALL       fprintf                                          undefined fprintf()
    //                              pathsys.cpp:186 (12)
    //         0046b3ce     MOV        EAX,dword ptr [EBP + 0x4]
    //         0046b3d1     ADD        ESP,0x8
    //         0046b3d4     XOR        EDI,EDI
    //         0046b3d6     TEST       EAX,EAX
    //         0046b3d8     JLE        LAB_0046b3f1
    //                               LAB_0046b3da                                                 XREF[1]:     0046b3ef(j)  
    //                              pathsys.cpp:187 (23)
    //         0046b3da     PUSH       EDI
    //         0046b3db     PUSH       s_%04d_                                          = "%04d "
    //         0046b3e0     PUSH       ESI
    //         0046b3e1     CALL       fprintf                                          undefined fprintf()
    //         0046b3e6     MOV        EAX,dword ptr [EBP + 0x4]
    //         0046b3e9     ADD        ESP,0xc
    //         0046b3ec     INC        EDI
    //         0046b3ed     CMP        EDI,EAX
    //         0046b3ef     JL         LAB_0046b3da
    //                               LAB_0046b3f1                                                 XREF[1]:     0046b3d8(j)  
    //                              pathsys.cpp:189 (14)
    //         0046b3f1     PUSH       s__                                              = 0Ah
    //         0046b3f6     PUSH       ESI
    //         0046b3f7     CALL       fprintf                                          undefined fprintf()
    //         0046b3fc     ADD        ESP,0x8
    //                              pathsys.cpp:190 (11)
    //         0046b3ff     PUSH       s________                                        = "       "
    //         0046b404     PUSH       ESI
    //         0046b405     CALL       fprintf                                          undefined fprintf()
    //                              pathsys.cpp:191 (12)
    //         0046b40a     MOV        EAX,dword ptr [EBP + 0x4]
    //         0046b40d     ADD        ESP,0x8
    //         0046b410     XOR        EDI,EDI
    //         0046b412     TEST       EAX,EAX
    //         0046b414     JLE        LAB_0046b42d
    //                               LAB_0046b416                                                 XREF[1]:     0046b42b(j)  
    //                              pathsys.cpp:192 (23)
    //         0046b416     PUSH       EDI
    //         0046b417     PUSH       s_----_                                          = "---- "
    //         0046b41c     PUSH       ESI
    //         0046b41d     CALL       fprintf                                          undefined fprintf()
    //         0046b422     MOV        EAX,dword ptr [EBP + 0x4]
    //         0046b425     ADD        ESP,0xc
    //         0046b428     INC        EDI
    //         0046b429     CMP        EDI,EAX
    //         0046b42b     JL         LAB_0046b416
    //                               LAB_0046b42d                                                 XREF[1]:     0046b414(j)  
    //                              pathsys.cpp:194 (11)
    //         0046b42d     PUSH       s__                                              = 0Ah
    //         0046b432     PUSH       ESI
    //         0046b433     CALL       fprintf                                          undefined fprintf()
    //                              pathsys.cpp:197 (19)
    //         0046b438     MOV        EDX,dword ptr [EBP + 0x8]
    //         0046b43b     ADD        ESP,0x8
    //         0046b43e     SHL        EDX,0x2
    //         0046b441     XOR        EDI,EDI
    //         0046b443     TEST       EDX,EDX
    //         0046b445     JLE        LAB_0046b528
    //                               LAB_0046b44b                                                 XREF[1]:     0046b522(j)  
    //                              pathsys.cpp:198 (16)
    //         0046b44b     MOV        EAX,EDI
    //         0046b44d     CDQ
    //         0046b44e     XOR        EAX,EDX
    //         0046b450     SUB        EAX,EDX
    //         0046b452     AND        EAX,0x3
    //         0046b455     XOR        EAX,EDX
    //         0046b457     SUB        EAX,EDX
    //         0046b459     JNZ        LAB_0046b477
    //                              pathsys.cpp:199 (26)
    //         0046b45b     MOV        EAX,EDI
    //         0046b45d     CDQ
    //         0046b45e     AND        EDX,0x3
    //         0046b461     ADD        EAX,EDX
    //         0046b463     SAR        EAX,0x2
    //         0046b466     PUSH       EAX
    //         0046b467     PUSH       s_R%03d:_                                        = "R%03d: "
    //         0046b46c     PUSH       ESI
    //         0046b46d     CALL       fprintf                                          undefined fprintf()
    //         0046b472     ADD        ESP,0xc
    //                              pathsys.cpp:200 (2)
    //         0046b475     JMP        LAB_0046b485
    //                               LAB_0046b477                                                 XREF[1]:     0046b459(j)  
    //                              pathsys.cpp:201 (14)
    //         0046b477     PUSH       s_______                                         = "      "
    //         0046b47c     PUSH       ESI
    //         0046b47d     CALL       fprintf                                          undefined fprintf()
    //         0046b482     ADD        ESP,0x8
    //                               LAB_0046b485                                                 XREF[1]:     0046b475(j)  
    //                              pathsys.cpp:203 (12)
    //         0046b485     MOV        EAX,dword ptr [EBP + 0x4]
    //         0046b488     XOR        EBX,EBX
    //         0046b48a     SHL        EAX,0x2
    //         0046b48d     TEST       EAX,EAX
    //         0046b48f     JLE        LAB_0046b4db
    //                               LAB_0046b491                                                 XREF[1]:     0046b4d9(j)  
    //                              pathsys.cpp:204 (2)
    //         0046b491     MOV        EAX,EBX
    //                              pathsys.cpp:205 (34)
    //         0046b493     PUSH       EDI
    //         0046b494     CDQ
    //         0046b495     XOR        EAX,EDX
    //         0046b497     PUSH       EBX
    //         0046b498     SUB        EAX,EDX
    //         0046b49a     MOV        this,EBP
    //         0046b49c     AND        EAX,0x3
    //         0046b49f     XOR        EAX,EDX
    //         0046b4a1     SUB        EAX,EDX
    //         0046b4a3     JNZ        LAB_0046b4b7
    //         0046b4a5     CALL       PathingSystem::obstruction                       uchar obstruction(PathingSystem * this, int p
    //         0046b4aa     AND        EAX,0xff
    //         0046b4af     PUSH       EAX
    //         0046b4b0     PUSH       s__%1d                                           = " %1d"
    //                              pathsys.cpp:206 (2)
    //         0046b4b5     JMP        LAB_0046b4c7
    //                               LAB_0046b4b7                                                 XREF[1]:     0046b4a3(j)  
    //                              pathsys.cpp:207 (36)
    //         0046b4b7     CALL       PathingSystem::obstruction                       uchar obstruction(PathingSystem * this, int p
    //         0046b4bc     AND        EAX,0xff
    //         0046b4c1     PUSH       EAX
    //         0046b4c2     PUSH       s_%1d                                            = "%1d"
    //                               LAB_0046b4c7                                                 XREF[1]:     0046b4b5(j)  
    //         0046b4c7     PUSH       ESI
    //         0046b4c8     CALL       fprintf                                          undefined fprintf()
    //         0046b4cd     MOV        this,dword ptr [EBP + 0x4]
    //         0046b4d0     ADD        ESP,0xc
    //         0046b4d3     INC        EBX
    //         0046b4d4     SHL        this,0x2
    //         0046b4d7     CMP        EBX,this
    //         0046b4d9     JL         LAB_0046b491
    //                               LAB_0046b4db                                                 XREF[1]:     0046b48f(j)  
    //                              pathsys.cpp:197 (3)
    //         0046b4db     LEA        EBX,[EDI + 0x1]
    //                              pathsys.cpp:210 (14)
    //         0046b4de     MOV        EAX,EBX
    //         0046b4e0     CDQ
    //         0046b4e1     XOR        EAX,EDX
    //         0046b4e3     SUB        EAX,EDX
    //         0046b4e5     AND        EAX,0x3
    //         0046b4e8     XOR        EAX,EDX
    //         0046b4ea     SUB        EAX,EDX
    //                              pathsys.cpp:211 (19)
    //         0046b4ec     MOV        EAX,EDI
    //         0046b4ee     CDQ
    //         0046b4ef     JNZ        LAB_0046b501
    //         0046b4f1     AND        EDX,0x3
    //         0046b4f4     ADD        EAX,EDX
    //         0046b4f6     SAR        EAX,0x2
    //         0046b4f9     PUSH       EAX
    //         0046b4fa     PUSH       s___:R%03d__                                     = "  :R%03d\n\n"
    //                              pathsys.cpp:212 (2)
    //         0046b4ff     JMP        LAB_0046b50f
    //                               LAB_0046b501                                                 XREF[1]:     0046b4ef(j)  
    //                              pathsys.cpp:213 (39)
    //         0046b501     AND        EDX,0x3
    //         0046b504     ADD        EAX,EDX
    //         0046b506     SAR        EAX,0x2
    //         0046b509     PUSH       EAX
    //         0046b50a     PUSH       s__                                              = 0Ah
    //                               LAB_0046b50f                                                 XREF[1]:     0046b4ff(j)  
    //         0046b50f     PUSH       ESI
    //         0046b510     CALL       fprintf                                          undefined fprintf()
    //         0046b515     MOV        EDX,dword ptr [EBP + 0x8]
    //         0046b518     MOV        EDI,EBX
    //         0046b51a     SHL        EDX,0x2
    //         0046b51d     ADD        ESP,0xc
    //         0046b520     CMP        EDI,EDX
    //         0046b522     JL         LAB_0046b44b
    //                               LAB_0046b528                                                 XREF[1]:     0046b445(j)  
    //                              pathsys.cpp:215 (14)
    //         0046b528     PUSH       s__                                              = 0Ah
    //         0046b52d     PUSH       ESI
    //         0046b52e     CALL       fprintf                                          undefined fprintf()
    //         0046b533     ADD        ESP,0x8
    //                              pathsys.cpp:218 (10)
    //         0046b536     PUSH       ESI
    //         0046b537     CALL       fclose                                           undefined fclose()
    //         0046b53c     ADD        ESP,0x4
    //         0046b53f     POP        EBX
    //                               LAB_0046b540                                                 XREF[2]:     0046b36b(j), 0046b383(j)  
    //                              pathsys.cpp:219 (6)
    //         0046b540     POP        EDI
    //         0046b541     POP        ESI
    //         0046b542     POP        EBP
    //         0046b543     RET        0x4
    //         0046b546     ??         90h
    //         0046b547     NOP
    //         0046b548     NOP
    //         0046b549     NOP
    //         0046b54a     NOP
    //         0046b54b     NOP
    //         0046b54c     NOP
    //         0046b54d     NOP
    //         0046b54e     NOP
    //         0046b54f     NOP
    return;
}

uchar PathingSystem::lookupMisc(int param_1, int param_2) {
    /* TODO: Stub */
    //                              uchar __thiscall lookupMisc(PathingSystem * this, int param_1, int p
    //              uchar             AL:1           <RETURN>
    //              PathingSystem *   ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0046b550(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0046b55b(R)  
    //                               ?lookupMisc@PathingSystem@@QAEEHH@Z                          XREF[2]:     addEnemyInfluences:004da2cd(c), 
    //                               PathingSystem::lookupMisc                                                 addEnemyInfluences:004da3ab(c)  
    //                              pathsys.cpp:407 (24)
    //         0046b550     MOV        EAX,dword ptr [ESP + param_1]
    //         0046b554     MOV        EDX,EAX
    //         0046b556     SHL        EDX,0x8
    //         0046b559     SUB        EDX,EAX
    //         0046b55b     MOV        EAX,dword ptr [ESP + param_2]
    //         0046b55f     ADD        EAX,EDX
    //         0046b561     MOV        AL,byte ptr [ECX + EAX*0x1 + this->miscValue[0
    //                              pathsys.cpp:410 (3)
    //         0046b568     RET        0x8
    //         0046b56b     ??         90h
    //         0046b56c     NOP
    //         0046b56d     NOP
    //         0046b56e     NOP
    //         0046b56f     NOP
    return 0;
}

void PathingSystem::setMisc(int param_1, int param_2, uchar param_3) {
    /* TODO: Stub */
    //                              void __thiscall setMisc(PathingSystem * this, int param_1, int param
    //              void              <VOID>         <RETURN>
    //              PathingSystem *   ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0046b570(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0046b581(R)  
    //              uchar             Stack[0xc]:1   param_3                   XREF[1]:     0046b57b(R)  
    //                               ?setMisc@PathingSystem@@QAEXHHE@Z                            XREF[4]:     addEnemyInfluences:004da2ee(c), 
    //                               PathingSystem::setMisc                                                    addEnemyInfluences:004da3cc(c), 
    //                                                                                                         addPriorAttackInfluences:004da4e1(
    //                                                                                                         addPriorAttackInfluences:004da55e(
    //                              pathsys.cpp:423 (28)
    //         0046b570     MOV        EAX,dword ptr [ESP + param_1]
    //         0046b574     MOV        EDX,EAX
    //         0046b576     SHL        EDX,0x8
    //         0046b579     SUB        EDX,EAX
    //         0046b57b     MOV        AL,byte ptr [ESP + param_3]
    //         0046b57f     ADD        EDX,this
    //         0046b581     MOV        this,dword ptr [ESP + param_2]
    //         0046b585     MOV        byte ptr [EDX + this->_padding_*0x1 + 0x10de28
    //                              pathsys.cpp:426 (3)
    //         0046b58c     RET        0xc
    //         0046b58f     ??         90h
    return;
}

void PathingSystem::initMisc(uchar param_1) {
    /* TODO: Stub */
    //                              void __thiscall initMisc(PathingSystem * this, uchar param_1)
    //              void              <VOID>         <RETURN>
    //              PathingSystem *   ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     0046b590(R)  
    //                               ?initMisc@PathingSystem@@QAEXE@Z                             XREF[2]:     findAvoidancePath:00460d12(c), 
    //                               PathingSystem::initMisc                                                   PathingSystem:0046b1f2(c)  
    //                              pathsys.cpp:431 (38)
    //         0046b590     MOV        EAX,dword ptr [ESP + param_1]
    //         0046b594     MOV        EDX,this
    //         0046b596     PUSH       EDI
    //         0046b597     AND        EAX,0xff
    //         0046b59c     LEA        EDI,[EDX + 0x10de28]
    //         0046b5a2     MOV        DL,AL
    //         0046b5a4     MOV        DH,DL
    //         0046b5a6     MOV        this,0x3f80
    //         0046b5ab     MOV        EAX,EDX
    //         0046b5ad     SHL        EAX,0x10
    //         0046b5b0     MOV        AX,DX
    //         0046b5b3     STOSD.REP  ES:EDI
    //         0046b5b5     STOSB      ES:EDI
    //                              pathsys.cpp:433 (4)
    //         0046b5b6     POP        EDI
    //         0046b5b7     RET        0x4
    //         0046b5ba     ??         90h
    //         0046b5bb     NOP
    //         0046b5bc     NOP
    //         0046b5bd     NOP
    //         0046b5be     NOP
    //         0046b5bf     NOP
    return;
}

void PathingSystem::zeroObstructionMap() {
    /* TODO: Stub */
    //                              void __thiscall zeroObstructionMap(PathingSystem * this)
    //              void              <VOID>         <RETURN>
    //              PathingSystem *   ECX:4 (auto)   this
    //                               ?zeroObstructionMap@PathingSystem@@QAEXXZ                    XREF[3]:     PathingSystem:0046b1f9(c), 
    //                               PathingSystem::zeroObstructionMap                                         new_game:00542769(c), 
    //                                                                                                         new_game:00542773(c)  
    //                              pathsys.cpp:624 (3)
    //         0046b5c0     MOV        EDX,this
    //         0046b5c2     PUSH       EDI
    //                              pathsys.cpp:626 (15)
    //         0046b5c3     MOV        this,0xfe01
    //         0046b5c8     XOR        EAX,EAX
    //         0046b5ca     LEA        EDI,[EDX + 0xce624]
    //         0046b5d0     STOSD.REP  ES:EDI
    //                              pathsys.cpp:627 (2)
    //         0046b5d2     POP        EDI
    //         0046b5d3     RET
    //         0046b5d4     ??         90h
    //         0046b5d5     NOP
    //         0046b5d6     NOP
    //         0046b5d7     NOP
    //         0046b5d8     NOP
    //         0046b5d9     NOP
    //         0046b5da     NOP
    //         0046b5db     NOP
    //         0046b5dc     NOP
    //         0046b5dd     NOP
    //         0046b5de     NOP
    //         0046b5df     NOP
    return;
}

uchar PathingSystem::obstruction(int param_1, int param_2) {
    /* TODO: Stub */
    //                              uchar __thiscall obstruction(PathingSystem * this, int param_1, int 
    //              uchar             AL:1           <RETURN>
    //              PathingSystem *   ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0046b5e4(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0046b5e0(R)  
    //                               ?obstruction@PathingSystem@@QAEEHH@Z                         XREF[3]:     printToFile:0046b4a5(c), 
    //                               PathingSystem::obstruction                                                printToFile:0046b4b7(c), 
    //                                                                                                         draw_terrain_obstruction_map:00538
    //                              pathsys.cpp:632 (36)
    //         0046b5e0     MOV        EDX,dword ptr [ESP + param_2]
    //         0046b5e4     MOV        EAX,dword ptr [ESP + param_1]
    //         0046b5e8     PUSH       ESI
    //         0046b5e9     PUSH       EDI
    //         0046b5ea     MOV        ESI,EDX
    //         0046b5ec     MOV        EDI,EAX
    //         0046b5ee     SAR        ESI,0x2
    //         0046b5f1     SHL        EDI,0x8
    //         0046b5f4     SUB        EDI,EAX
    //         0046b5f6     ADD        this,ESI
    //         0046b5f8     XOR        EAX,EAX
    //         0046b5fa     AND        EDX,0x3
    //         0046b5fd     MOV        AL,byte ptr [EDI + this->_padding_*0x1 + 0xce6
    //                              pathsys.cpp:635 (16)
    //         0046b604     POP        EDI
    //         0046b605     MOV        this,byte ptr [EDX + ObstructionValueShift]      = 06040200
    //         0046b60b     POP        ESI
    //         0046b60c     SHR        EAX,this
    //         0046b60e     AND        EAX,0x3
    //         0046b611     RET        0x8
    //         0046b614     ??         90h
    //         0046b615     NOP
    //         0046b616     NOP
    //         0046b617     NOP
    //         0046b618     NOP
    //         0046b619     NOP
    //         0046b61a     NOP
    //         0046b61b     NOP
    //         0046b61c     NOP
    //         0046b61d     NOP
    //         0046b61e     NOP
    //         0046b61f     NOP
    return 0;
}

void PathingSystem::incrementObstruction(int param_1, int param_2) {
    /* TODO: Stub */
    //                              void __thiscall incrementObstruction(PathingSystem * this, int param
    //              void              <VOID>         <RETURN>
    //              PathingSystem *   ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0046b624(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0046b620(R)  
    //                               ?incrementObstruction@PathingSystem@@QAEXHH@Z                XREF[2]:     addToObstructionMap:004c6c41(c), 
    //                               PathingSystem::incrementObstruction                                       addToObstructionMap:004c6c51(c)  
    //                              pathsys.cpp:641 (54)
    //         0046b620     MOV        EDX,dword ptr [ESP + param_2]
    //         0046b624     MOV        EAX,dword ptr [ESP + param_1]
    //         0046b628     PUSH       EBX
    //         0046b629     PUSH       ESI
    //         0046b62a     PUSH       EDI
    //         0046b62b     MOV        ESI,EDX
    //         0046b62d     MOV        EDI,EAX
    //         0046b62f     AND        EDX,0x3
    //         0046b632     SAR        ESI,0x2
    //         0046b635     SHL        EDI,0x8
    //         0046b638     SUB        EDI,EAX
    //         0046b63a     ADD        this,ESI
    //         0046b63c     MOV        BL,byte ptr [EDI + this->_padding_*0x1 + 0xce6
    //         0046b643     LEA        ESI,[EDI + this->_padding_*0x1 + 0xce624]
    //         0046b64a     MOV        this,byte ptr [EDX + ObstructionValueShift]      = 06040200
    //         0046b650     MOV        AL,BL
    //         0046b652     SHR        AL,this
    //         0046b654     AND        AL,0x3
    //                              pathsys.cpp:645 (4)
    //         0046b656     CMP        AL,0x3
    //         0046b658     JNC        LAB_0046b670
    //                              pathsys.cpp:648 (22)
    //         0046b65a     MOV        DL,byte ptr [EDX + ObstructionValueMask]         = 3fcff3fc
    //         0046b660     AND        this,0xff
    //         0046b666     AND        DL,BL
    //         0046b668     INC        AL
    //         0046b66a     SHL        AL,this
    //         0046b66c     OR         DL,AL
    //         0046b66e     MOV        byte ptr [ESI],DL
    //                               LAB_0046b670                                                 XREF[1]:     0046b658(j)  
    //                              pathsys.cpp:652 (6)
    //         0046b670     POP        EDI
    //         0046b671     POP        ESI
    //         0046b672     POP        EBX
    //         0046b673     RET        0x8
    //         0046b676     ??         90h
    //         0046b677     NOP
    //         0046b678     NOP
    //         0046b679     NOP
    //         0046b67a     NOP
    //         0046b67b     NOP
    //         0046b67c     NOP
    //         0046b67d     NOP
    //         0046b67e     NOP
    //         0046b67f     NOP
    return;
}

void PathingSystem::decrementObstruction(int param_1, int param_2) {
    /* TODO: Stub */
    //                              void __thiscall decrementObstruction(PathingSystem * this, int param
    //              void              <VOID>         <RETURN>
    //              PathingSystem *   ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0046b680(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0046b684(R)  
    //                               ?decrementObstruction@PathingSystem@@QAEXHH@Z                XREF[2]:     removeFromObstructionMap:004c6d52(
    //                               PathingSystem::decrementObstruction                                       removeFromObstructionMap:004c6d62(
    //                              pathsys.cpp:658 (53)
    //         0046b680     MOV        EAX,dword ptr [ESP + param_1]
    //         0046b684     MOV        EDX,dword ptr [ESP + param_2]
    //         0046b688     PUSH       EBX
    //         0046b689     PUSH       ESI
    //         0046b68a     MOV        ESI,EAX
    //         0046b68c     SHL        ESI,0x8
    //         0046b68f     SUB        ESI,EAX
    //         0046b691     MOV        EAX,EDX
    //         0046b693     SAR        EAX,0x2
    //         0046b696     ADD        this,ESI
    //         0046b698     AND        EDX,0x3
    //         0046b69b     MOV        BL,byte ptr [EAX + this->_padding_*0x1 + 0xce6
    //         0046b6a2     LEA        ESI,[EAX + this->_padding_*0x1 + 0xce624]
    //         0046b6a9     MOV        this,byte ptr [EDX + ObstructionValueShift]      = 06040200
    //         0046b6af     MOV        AL,BL
    //         0046b6b1     SHR        AL,this
    //         0046b6b3     AND        AL,0x3
    //                              pathsys.cpp:661 (2)
    //         0046b6b5     JBE        LAB_0046b6cd
    //                              pathsys.cpp:664 (22)
    //         0046b6b7     MOV        DL,byte ptr [EDX + ObstructionValueMask]         = 3fcff3fc
    //         0046b6bd     AND        this,0xff
    //         0046b6c3     AND        DL,BL
    //         0046b6c5     DEC        AL
    //         0046b6c7     SHL        AL,this
    //         0046b6c9     OR         DL,AL
    //         0046b6cb     MOV        byte ptr [ESI],DL
    //                               LAB_0046b6cd                                                 XREF[1]:     0046b6b5(j)  
    //                              pathsys.cpp:668 (5)
    //         0046b6cd     POP        ESI
    //         0046b6ce     POP        EBX
    //         0046b6cf     RET        0x8
    //         0046b6d2     ??         90h
    //         0046b6d3     NOP
    //         0046b6d4     NOP
    //         0046b6d5     NOP
    //         0046b6d6     NOP
    //         0046b6d7     NOP
    //         0046b6d8     NOP
    //         0046b6d9     NOP
    //         0046b6da     NOP
    //         0046b6db     NOP
    //         0046b6dc     NOP
    //         0046b6dd     NOP
    //         0046b6de     NOP
    //         0046b6df     NOP
    //                              * public: int __thiscall PathingSystem::findTilePath(int,int,int,int,class RGE_Moving_Object *,float... *
    //                              int __thiscall findTilePath(PathingSystem * this, int param_1, int p
    //              int               EAX:4          <RETURN>
    //              PathingSystem *   ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[36]:    0046b6eb(R), 0046b757(R), 0046bc49(R), 0046bca5(R), 
    //                                                                                     0046bcd9(R), 0046bd61(W), 0046bd9f(R), 0046bdb0(R), 
    //                                                                                     0046bdbf(W), 0046be14(R), 0046c09b(W), 0046c11d(R), 
    //                                                                                     0046c23d(W), 0046c2c7(R), 0046c355(W), 0046c386(W), 
    //                                                                                     0046c3b7(W), 0046c3e9(W), 0046c435(W), 0046c48f(W)  
    //              int               Stack[0x8]:4   param_2                   XREF[43]:    0046b6f6(R), 0046b75a(R), 0046bc46(R), 0046bca8(R), 
    //                                                                                     0046bcdc(R), 0046be32(R), 0046be57(W), 0046be5d(R), 
    //                                                                                     0046be60(W), 0046be63(R), 0046bfa8(W), 0046bfd7(W), 
    //                                                                                     0046bfdd(R), 0046bfe0(W), 0046bfe6(R), 0046c092(W), 
    //                                                                                     0046c11a(R), 0046c21c(W), 0046c222(R), 0046c225(W)  
    //              int               Stack[0xc]:4   param_3                   XREF[11]:    0046b714(R), 0046b751(R), 0046b8f0(R), 0046bc9f(R), 
    //                                                                                     0046be3c(R), 0046bf71(R), 0046bfb7(R), 0046c24a(R), 
    //                                                                                     0046c284(R), 0046cf4a(W), 0046cfa3(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[27]:    0046b71f(R), 0046b754(R), 0046b8f3(R), 0046bca2(R), 
    //                                                                                     0046be42(R), 0046bf74(R), 0046bfba(R), 0046c24d(R), 
    //                                                                                     0046c287(R), 0046cb36(W), 0046cb46(R), 0046cb6d(R), 
    //                                                                                     0046cc20(W), 0046cc30(R), 0046cc57(R), 0046cd2d(W), 
    //                                                                                     0046cd5f(R), 0046ce19(W), 0046ce4b(R), 0046cf47(W)  
    //              RGE_Moving_Obj    Stack[0x14]:4  param_5                   XREF[6]:     0046b743(R), 0046b7b7(R), 0046caea(R), 0046ccdd(R), 
    //                                                                                     0046cfdb(R), 0046d1d2(R)  
    //              float             Stack[0x18]:4  param_6                   XREF[25]:    0046b73a(R), 0046b78e(R), 0046bcea(R), 0046bd35(R), 
    //                                                                                     0046bd66(W), 0046bdcd(R), 0046c042(W), 0046c0b0(R), 
    //                                                                                     0046c0de(R), 0046c0e8(W), 0046c112(R), 0046c3f5(W), 
    //                                                                                     0046c49b(W), 0046c4d8(W), 0046c509(W), 0046c536(R), 
    //                                                                                     0046c53e(W), 0046c699(R), 0046c80d(R), 0046c841(W)  
    //              int               Stack[0x1c]:4  param_7                   XREF[13]:    0046b8f6(R), 0046bb48(W), 0046bb5a(R), 0046bdf4(W), 
    //                                                                                     0046c34c(R), 0046c37d(R), 0046c3ae(R), 0046c3e0(R), 
    //                                                                                     0046c42c(R), 0046c461(R), 0046c486(R), 0046c4c3(R), 
    //                                                                                     0046c4ef(R)  
    //              int               Stack[0x20]:4  param_8                   XREF[6]:     0046b7ad(R), 0046b807(R), 0046cacd(R), 0046ccc0(R), 
    //                                                                                     0046cfbe(R), 0046d1cc(R)  
    //              float *           Stack[0x24]:4  param_9                   XREF[5]:     0046b7a0(R), 0046b7fa(R), 0046cbd6(R), 0046cdc8(R), 
    //                                                                                     0046d0c7(R)  
    //              int               Stack[0x28]:4  param_10                  XREF[1]:     0046bf17(R)  
    //              int               Stack[0x2c]:4  param_11                  XREF[10]:    0046b9b8(R), 0046be2a(W), 0046c358(R), 0046c389(R), 
    //                                                                                     0046c3ba(R), 0046c3ec(R), 0046c438(R), 0046c492(R), 
    //                                                                                     0046c4cf(R), 0046c500(R)  
    //              int               Stack[0x30]:4  param_12                  XREF[1]:     0046c68d(R)  
    //              int               Stack[0x34]:4  param_13                  XREF[29]:    0046bcdf(R), 0046bd2d(R), 0046c15f(R), 0046c171(R), 
    //                                                                                     0046c179(R), 0046c183(R), 0046c190(R), 0046c198(R), 
    //                                                                                     0046cad7(R), 0046cb10(W), 0046cb53(R), 0046cbc5(W), 
    //                                                                                     0046cbfa(W), 0046cc3d(R), 0046ccaf(W), 0046ccca(R), 
    //                                                                                     0046cd03(W), 0046cd45(R), 0046cdb7(W), 0046cdef(W)  
    //              int               Stack[0x38]:4  param_14                  XREF[38]:    0046b860(R), 0046ba94(W), 0046bad2(R), 0046bb32(W), 
    //                                                                                     0046bb3d(R), 0046bb83(W), 0046bcd6(W), 0046bce2(R), 
    //                                                                                     0046bda2(W), 0046bdfc(R), 0046c0ad(W), 0046c0b6(R), 
    //                                                                                     0046c106(W), 0046c349(W), 0046c37a(W), 0046c3ab(W), 
    //                                                                                     0046c3dd(W), 0046c429(W), 0046c45e(W), 0046c483(W)  
    //              int               Stack[0x3c]:4  param_15                  XREF[12]:    0046b86f(R), 0046bab5(W), 0046bac5(R), 0046baec(R), 
    //                                                                                     0046c0a0(W), 0046c0d0(R), 0046c127(R), 0046c520(W), 
    //                                                                                     0046c696(R), 0046c805(R), 0046c89f(W), 0046c906(R)  
    //              int               Stack[-0x8]:4  xDeltaRight4              XREF[5]:     0046be0c(W), 0046c3f8(R), 0046c49e(R), 0046c4db(R), 
    //                                                                                     0046c50c(R)  
    //              int               Stack[-0xc]:4  yDeltaDown4               XREF[4]:     0046be3f(W), 0046c404(R), 0046c4e7(R), 0046c518(R)  
    //              int               Stack[-0x10]:4 xDeltaLeft                XREF[9]:     0046bd7d(W), 0046c32f(R), 0046c363(R), 0046c391(R), 
    //                                                                                     0046c3bf(R), 0046c40c(R), 0046c440(R), 0046c466(R), 
    //                                                                                     0046c4a3(R)  
    //              int               Stack[-0x14]:4 yDeltaUp                  XREF[9]:     0046bdbc(W), 0046c337(R), 0046c360(R), 0046c399(R), 
    //                                                                                     0046c3c8(R), 0046c40f(R), 0046c443(R), 0046c469(R), 
    //                                                                                     0046c4a6(R)  
    //              int               Stack[-0x18]:4 xDeltaRight               XREF[9]:     0046bd9c(W), 0046c33c(R), 0046c36b(R), 0046c39e(R), 
    //                                                                                     0046c3d0(R), 0046c41c(R), 0046c451(R), 0046c476(R), 
    //                                                                                     0046c4b3(R)  
    //              int               Stack[-0x1c]:4 yDeltaDown                XREF[9]:     0046bdd9(W), 0046c341(R), 0046c372(R), 0046c3a3(R), 
    //                                                                                     0046c3d5(R), 0046c421(R), 0046c456(R), 0046c47b(R), 
    //                                                                                     0046c4b8(R)  
    //              int               Stack[-0x20]:4 numberIterationCap        XREF[4]:     0046beb8(W), 0046beca(W), 0046befd(W), 0046bf1d(R)  
    //              undefined4        Stack[-0x24]:4 local_24                  XREF[3]:     0046c66e(W), 0046c674(W), 0046c678(R)  
    //              int               Stack[-0x28]:4 i                         XREF[5]:     0046c146(W), 0046c31c(R), 0046c981(R), 0046ca8e(R), 
    //                                                                                     0046ca9d(W)  
    //              int               Stack[-0x2c]:4 iterations                XREF[5]:     0046be4b(W), 0046bf20(R), 0046bf2b(R), 0046caa9(R), 
    //                                                                                     0046cabf(W)  
    //              undefined4        Stack[-0x30]:4 local_30                  XREF[4]:     0046c5a2(W), 0046c5bd(R), 0046c645(R), 0046c652(W)  
    //              undefined4        Stack[-0x34]:4 local_34                  XREF[4]:     0046c56d(W), 0046c591(R), 0046c65b(R), 0046c665(W)  
    //              undefined4        Stack[-0x38]:4 local_38                  XREF[4]:     0046c150(W), 0046c1a3(R), 0046c23a(R), 0046c95f(R)  
    //              int               Stack[-0x3c]:4 SkipBit                   XREF[4]:     0046c149(W), 0046c1c1(R), 0046ca94(R), 0046caa0(W)  
    //              int               Stack[-0x40]:4 MGP_goalTolerance         XREF[2]:     0046bd43(W), 0046c00d(R)  
    //              undefined4        Stack[-0x44]:4 local_44                  XREF[3]:     0046c5b5(W), 0046c642(R), 0046c64d(W)  
    //              undefined4        Stack[-0x48]:4 local_48                  XREF[3]:     0046c2e2(W), 0046c30c(R), 0046c929(R)  
    //              float             Stack[-0x4c]:4 unobstructibleObjectHitp  XREF[3]:     0046c848(W), 0046c903(W), 0046c947(R)  
    //              undefined4        Stack[-0x50]:4 local_50                  XREF[5]:     0046b788(W), 0046b78b(R), 0046c975(W), 0046c97a(W), 
    //                                                                                     0046c97e(R)  
    //              undefined4        Stack[-0x54]:4 local_54                  XREF[2]:     0046c2bb(W), 0046c2be(R)  
    //              undefined4        Stack[-0x58]:4 local_58                  XREF[2]:     0046c281(W), 0046c2c1(R)  
    //              undefined4        Stack[-0x5c]:4 local_5c                  XREF[2]:     0046c57e(W), 0046c594(R)  
    //              undefined4        Stack[-0x60]:4 local_60                  XREF[2]:     0046c58e(W), 0046c597(R)  
    //              undefined4        Stack[-0x64]:4 local_64                  XREF[4]:     0046c59f(W), 0046c5ba(R), 0046c876(W), 0046c911(R)  
    //              undefined4        Stack[-0x68]:4 local_68                  XREF[2]:     0046c5e1(W), 0046c5e4(R)  
    //              int               Stack[-0x6c]:4 newTotal                  XREF[2]:     0046c2d8(W), 0046c937(R)  
    //              undefined4        Stack[-0x70]:4 local_70                  XREF[2]:     0046c2e9(W), 0046c995(R)  
    //              XYPoint           Stack[-0x78]:8 temp                      XREF[15,21]: 0046bfe3(W), 0046c169(W), 0046c174(W), 0046c193(W), 
    //                                                                                     0046c28a(R), 0046c2d3(R), 0046c346(R), 0046c3f2(R), 
    //                                                                                     0046c480(R), 0046c4bd(R), 0046c4ec(R), 0046c506(R), 
    //                                                                                     0046c862(R), 0046c9ba(R), 0046ca91(R), 0046bfcb(W), 
    //                                                                                     0046c162(R), 0046c16c(W), 0046c17c(R), 0046c186(R)  
    //              XYPoint           Stack[-0x80]:8 bestPathPoint             XREF[12,23]: 0046bf52(W), 0046bf77(R), 0046c250(R), 0046c377(R), 
    //                                                                                     0046c3a8(R), 0046c3da(R), 0046c426(R), 0046c45b(R), 
    //                                                                                     0046c498(R), 0046c4d5(R), 0046ca8b(R), 0046cdcf(R), 
    //                                                                                     0046bf55(W), 0046bf7a(R), 0046c138(R), 0046c20e(R), 
    //                                                                                     0046c253(R), 0046c332(R), 0046c366(R), 0046c394(R)  
    //                               ?findTilePath@PathingSystem@@QAEHHHHHPAVRGE_Moving_Object@@  XREF[16]:    findPath:0045d8c9(c), 
    //                               PathingSystem::findTilePath                                               doMove:0045e0d7(c), 
    //                                                                                                         doMove:0045e5ec(c), 
    //                                                                                                         doTrivialMove:0045efeb(c), 
    //                                                                                                         canPath:0045f95b(c), 
    //                                                                                                         canPath:0045f9ae(c), 
    //                                                                                                         canPath:0045fb46(c), 
    //                                                                                                         canPath:0045fba8(c), 
    //                                                                                                         canBidirectionPath:0045fd56(c), 
    //                                                                                                         canBidirectionPath:0045fdcb(c), 
    //                                                                                                         canBidirectionPath:0045fe34(c), 
    //                                                                                                         canBidirectionPath:0045fea9(c), 
    //                                                                                                         canPathWithObstructions:0046004d(c
    //                                                                                                         canPathWithObstructions:004600b8(c
    //                                                                                                         canPathWithAdditionalPassability:0
    //                                                                                                         findAvoidancePath:00460cff(c)  
    //                              pathsys.cpp:855 (11)
    //         0046b6e0     PUSH       EBP
    //         0046b6e1     MOV        EBP,ESP
    //         0046b6e3     SUB        ESP,0x7c
    //         0046b6e6     PUSH       EBX
    //         0046b6e7     PUSH       ESI
    //         0046b6e8     MOV        ESI,this
    //         0046b6ea     PUSH       EDI
    //                              pathsys.cpp:864 (79)
    //         0046b6eb     MOV        this,dword ptr [EBP + param_1]
    //         0046b6ee     TEST       this,this
    //         0046b6f0     JL         LAB_0046d1cc
    //         0046b6f6     MOV        EDX,dword ptr [EBP + param_2]
    //         0046b6f9     TEST       EDX,EDX
    //         0046b6fb     JL         LAB_0046d1cc
    //         0046b701     MOV        EAX,dword ptr [ESI + 0x4]
    //         0046b704     CMP        this,EAX
    //         0046b706     JG         LAB_0046d1cc
    //         0046b70c     CMP        EDX,EAX
    //         0046b70e     JG         LAB_0046d1cc
    //         0046b714     MOV        EDX,dword ptr [EBP + param_3]
    //         0046b717     TEST       EDX,EDX
    //         0046b719     JL         LAB_0046d1cc
    //         0046b71f     MOV        this,dword ptr [EBP + param_4]
    //         0046b722     TEST       this,this
    //         0046b724     JL         LAB_0046d1cc
    //         0046b72a     CMP        EDX,EAX
    //         0046b72c     JG         LAB_0046d1cc
    //         0046b732     CMP        this,EAX
    //         0046b734     JG         LAB_0046d1cc
    //                              pathsys.cpp:879 (23)
    //         0046b73a     FLD        float ptr [EBP + param_6]
    //         0046b73d     FCOMP      float ptr [DAT_00570e54]
    //         0046b743     MOV        EDI,dword ptr [EBP + param_5]
    //         0046b746     FNSTSW     AX
    //         0046b748     TEST       AH,0x41
    //         0046b74b     JNZ        LAB_0046b83b
    //                              pathsys.cpp:863 (3)
    //         0046b751     MOV        EAX,dword ptr [EBP + param_3]
    //                              pathsys.cpp:864 (3)
    //         0046b754     MOV        EBX,dword ptr [EBP + param_4]
    //                              pathsys.cpp:865 (3)
    //         0046b757     MOV        this,dword ptr [EBP + param_1]
    //                              pathsys.cpp:866 (3)
    //         0046b75a     MOV        EDX,dword ptr [EBP + param_2]
    //                              pathsys.cpp:868 (2)
    //         0046b75d     CMP        EAX,this
    //                              pathsys.cpp:869 (2)
    //         0046b75f     JGE        LAB_0046b762
    //                              pathsys.cpp:870 (1)
    //         0046b761     XCHG       EAX,this
    //                               LAB_0046b762                                                 XREF[1]:     0046b75f(j)  
    //                              pathsys.cpp:872 (2)
    //         0046b762     CMP        EBX,EDX
    //                              pathsys.cpp:873 (2)
    //         0046b764     JGE        LAB_0046b768
    //                              pathsys.cpp:874 (2)
    //         0046b766     XCHG       EDX,EBX
    //                               LAB_0046b768                                                 XREF[1]:     0046b764(j)  
    //                              pathsys.cpp:877 (2)
    //         0046b768     SUB        EAX,this
    //                              pathsys.cpp:878 (2)
    //         0046b76a     SUB        EBX,EDX
    //                              pathsys.cpp:880 (2)
    //         0046b76c     CMP        EAX,EBX
    //                              pathsys.cpp:882 (2)
    //         0046b76e     JL         LAB_0046b775
    //                              pathsys.cpp:888 (2)
    //         0046b770     SUB        EAX,EBX
    //                              pathsys.cpp:889 (1)
    //         0046b772     XCHG       EAX,EBX
    //                              pathsys.cpp:890 (2)
    //         0046b773     JMP        LAB_0046b777
    //                               LAB_0046b775                                                 XREF[1]:     0046b76e(j)  
    //                              pathsys.cpp:894 (2)
    //         0046b775     SUB        EBX,EAX
    //                               LAB_0046b777                                                 XREF[1]:     0046b773(j)  
    //                              pathsys.cpp:900 (5)
    //         0046b777     AND        EAX,0xff
    //                              pathsys.cpp:901 (3)
    //         0046b77c     SHL        EBX,0x4
    //                              pathsys.cpp:902 (7)
    //         0046b77f     MOV        EAX,dword ptr [EAX*0x4 + DiagionalDistance]      = 00000000
    //                              pathsys.cpp:903 (2)
    //         0046b786     ADD        EAX,EBX
    //                              pathsys.cpp:905 (3)
    //         0046b788     MOV        dword ptr [EBP + local_50],EAX
    //                              pathsys.cpp:881 (21)
    //         0046b78b     FILD       dword ptr [EBP + local_50]
    //         0046b78e     FLD        float ptr [EBP + param_6]
    //         0046b791     FMUL       float ptr [DAT_00570e58]
    //         0046b797     FCOMPP
    //         0046b799     FNSTSW     AX
    //         0046b79b     TEST       AH,0x41
    //         0046b79e     JNZ        LAB_0046b7e3
    //                              pathsys.cpp:884 (7)
    //         0046b7a0     MOV        EAX,dword ptr [EBP + param_9]
    //         0046b7a3     TEST       EAX,EAX
    //         0046b7a5     JZ         LAB_0046b7ad
    //                              pathsys.cpp:886 (6)
    //         0046b7a7     MOV        dword ptr [EAX],0x0
    //                               LAB_0046b7ad                                                 XREF[1]:     0046b7a5(j)  
    //                              pathsys.cpp:890 (10)
    //         0046b7ad     CMP        dword ptr [EBP + param_8],0x1
    //         0046b7b1     JNZ        LAB_0046ced1
    //                              pathsys.cpp:893 (11)
    //         0046b7b7     MOV        EAX,dword ptr [EBP + param_5]
    //         0046b7ba     MOV        this,byte ptr [EAX + 0x154]
    //         0046b7c0     TEST       this,this
    //                              pathsys.cpp:894 (8)
    //         0046b7c2     LEA        this,[EAX + 0xa4]
    //         0046b7c8     JZ         LAB_0046b7d0
    //                              pathsys.cpp:896 (11)
    //         0046b7ca     LEA        this,[EAX + 0xd8]
    //                               LAB_0046b7d0                                                 XREF[1]:     0046b7c8(j)  
    //         0046b7d0     CALL       Path::killPath                                   void killPath(Path * this)
    //                              pathsys.cpp:898 (5)
    //         0046b7d5     MOV        EAX,0x1
    //                              pathsys.cpp:1896 (9)
    //         0046b7da     POP        EDI
    //         0046b7db     POP        ESI
    //         0046b7dc     POP        EBX
    //         0046b7dd     MOV        ESP,EBP
    //         0046b7df     POP        EBP
    //         0046b7e0     RET        0x3c
    //                               LAB_0046b7e3                                                 XREF[1]:     0046b79e(j)  
    //                              pathsys.cpp:903 (23)
    //         0046b7e3     MOV        EAX,dword ptr [EDI]
    //         0046b7e5     MOV        this,EDI
    //         0046b7e7     CALL       dword ptr [EAX + 0xfc]
    //         0046b7ed     FCOMP      float ptr [DAT_00570e5c]
    //         0046b7f3     FNSTSW     AX
    //         0046b7f5     TEST       AH,0x40
    //         0046b7f8     JZ         LAB_0046b83b
    //                              pathsys.cpp:906 (7)
    //         0046b7fa     MOV        EAX,dword ptr [EBP + param_9]
    //         0046b7fd     TEST       EAX,EAX
    //         0046b7ff     JZ         LAB_0046b807
    //                              pathsys.cpp:907 (6)
    //         0046b801     MOV        dword ptr [EAX],0x0
    //                               LAB_0046b807                                                 XREF[1]:     0046b7ff(j)  
    //                              pathsys.cpp:910 (10)
    //         0046b807     CMP        dword ptr [EBP + param_8],0x1
    //         0046b80b     JNZ        LAB_0046d1f0
    //                              pathsys.cpp:913 (6)
    //         0046b811     MOV        AL,byte ptr [EDI + 0x154]
    //                              pathsys.cpp:914 (14)
    //         0046b817     LEA        this,[EDI + 0xa4]
    //         0046b81d     TEST       AL,AL
    //         0046b81f     JZ         LAB_0046d1eb
    //                              pathsys.cpp:916 (13)
    //         0046b825     LEA        this,[EDI + 0xd8]
    //         0046b82b     CALL       Path::killPath                                   void killPath(Path * this)
    //         0046b830     XOR        EAX,EAX
    //                              pathsys.cpp:1896 (9)
    //         0046b832     POP        EDI
    //         0046b833     POP        ESI
    //         0046b834     POP        EBX
    //         0046b835     MOV        ESP,EBP
    //         0046b837     POP        EBP
    //         0046b838     RET        0x3c
    //                               LAB_0046b83b                                                 XREF[2]:     0046b74b(j), 0046b7f8(j)  
    //                              pathsys.cpp:929 (6)
    //         0046b83b     MOV        dword ptr [ESI + 0x11dc44],EDI
    //                              pathsys.cpp:931 (25)
    //         0046b841     MOV        this,dword ptr [EDI + 0x8]
    //         0046b844     MOV        EAX,dword ptr [ESI + 0x11dc40]
    //         0046b84a     MOVSX      EDX,word ptr [ECX + this+0x66]
    //         0046b84e     MOV        this,dword ptr [EAX + 0x54]
    //         0046b851     MOV        EDX,dword ptr [this->_padding_ + EDX*0x4]
    //         0046b854     MOV        dword ptr [ESI + 0x11dc50],EDX
    //                              pathsys.cpp:932 (6)
    //         0046b85a     MOV        EAX,dword ptr [EDI + 0x14c]
    //                              pathsys.cpp:934 (15)
    //         0046b860     MOV        EDX,dword ptr [EBP + param_14]
    //         0046b863     MOV        dword ptr [ESI + 0x11dc5c],EAX
    //         0046b869     MOV        this,dword ptr [EDI + 0x150]
    //                              pathsys.cpp:935 (21)
    //         0046b86f     MOV        EAX,dword ptr [EBP + param_15]
    //         0046b872     MOV        dword ptr [ESI + 0x11dc60],this
    //         0046b878     MOV        dword ptr [ESI + 0x11dce0],EDX
    //         0046b87e     MOV        dword ptr [ESI + 0x11dcdc],EAX
    //                              pathsys.cpp:937 (10)
    //         0046b884     MOV        dword ptr [ESI + 0x11dce8],0x0
    //                              pathsys.cpp:940 (9)
    //         0046b88e     MOV        EAX,[MapPathsDisplay]
    //         0046b893     TEST       EAX,EAX
    //         0046b895     JZ         LAB_0046b8f0
    //                              pathsys.cpp:942 (15)
    //         0046b897     MOV        EDX,dword ptr [ESI + 0x11dc3c]
    //         0046b89d     XOR        EBX,EBX
    //         0046b89f     MOV        EAX,dword ptr [EDX + 0xc]
    //         0046b8a2     TEST       EAX,EAX
    //         0046b8a4     JLE        LAB_0046b8dc
    //                               LAB_0046b8a6                                                 XREF[1]:     0046b8da(j)  
    //                              pathsys.cpp:944 (9)
    //         0046b8a6     MOV        this,dword ptr [EDX + 0x8d8c]
    //         0046b8ac     MOV        EAX,dword ptr [this->_padding_ + EBX*0x4]
    //                              pathsys.cpp:945 (7)
    //         0046b8af     XOR        this,this
    //         0046b8b1     CMP        dword ptr [EDX + 0x8],this
    //         0046b8b4     JLE        LAB_0046b8d0
    //                              pathsys.cpp:944 (3)
    //         0046b8b6     ADD        EAX,0xa
    //                               LAB_0046b8b9                                                 XREF[1]:     0046b8ce(j)  
    //                              pathsys.cpp:947 (2)
    //         0046b8b9     MOV        DL,byte ptr [EAX]
    //                              pathsys.cpp:948 (21)
    //         0046b8bb     ADD        EAX,0x18
    //         0046b8be     AND        DL,0x70
    //         0046b8c1     INC        this
    //         0046b8c2     MOV        byte ptr [EAX + -0x18],DL
    //         0046b8c5     MOV        EDX,dword ptr [ESI + 0x11dc3c]
    //         0046b8cb     CMP        this,dword ptr [EDX + 0x8]
    //         0046b8ce     JL         LAB_0046b8b9
    //                               LAB_0046b8d0                                                 XREF[1]:     0046b8b4(j)  
    //                              pathsys.cpp:942 (12)
    //         0046b8d0     MOV        EDX,dword ptr [ESI + 0x11dc3c]
    //         0046b8d6     INC        EBX
    //         0046b8d7     CMP        EBX,dword ptr [EDX + 0xc]
    //         0046b8da     JL         LAB_0046b8a6
    //                               LAB_0046b8dc                                                 XREF[1]:     0046b8a4(j)  
    //                              pathsys.cpp:951 (20)
    //         0046b8dc     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0046b8e2     MOV        EAX,dword ptr [this->_padding_]
    //         0046b8e4     CALL       dword ptr [EAX + 0x2c]
    //         0046b8e7     MOV        EDX,dword ptr [EAX]
    //         0046b8e9     PUSH       0x2
    //         0046b8eb     MOV        this,EAX
    //         0046b8ed     CALL       dword ptr [EDX + 0x20]
    //                               LAB_0046b8f0                                                 XREF[1]:     0046b895(j)  
    //                              pathsys.cpp:955 (194)
    //         0046b8f0     MOV        EAX,dword ptr [EBP + param_3]
    //         0046b8f3     MOV        this,dword ptr [EBP + param_4]
    //         0046b8f6     MOV        EDX,dword ptr [EBP + param_7]
    //         0046b8f9     SHL        EAX,0x2
    //         0046b8fc     SHL        this,0x2
    //         0046b8ff     MOV        dword ptr [ESI + 0x11dc84],EAX
    //         0046b905     MOV        dword ptr [ESI + 0x11dc88],this
    //         0046b90b     ADD        EAX,0x3
    //         0046b90e     ADD        this,0x3
    //         0046b911     CMP        EDX,-0x1
    //         0046b914     MOV        dword ptr [ESI + 0x11dc4c],EDX
    //         0046b91a     MOV        dword ptr [ESI + 0x11dc8c],EAX
    //         0046b920     MOV        dword ptr [ESI + 0x11dc90],this
    //         0046b926     JZ         LAB_0046b9b2
    //         0046b92c     MOV        this,dword ptr [ESI + 0x11dc40]
    //         0046b932     PUSH       EDX
    //         0046b933     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         0046b938     MOV        EBX,EAX
    //         0046b93a     TEST       EBX,EBX
    //         0046b93c     JZ         LAB_0046b9a8
    //         0046b93e     MOV        EDX,dword ptr [EBX + 0x8]
    //         0046b941     FLD        float ptr [EBX + 0x38]
    //         0046b944     FSUB       float ptr [EDX + 0x30]
    //         0046b947     FMUL       float ptr [DAT_00570e60]
    //         0046b94d     CALL       __ftol                                           undefined __ftol()
    //         0046b952     MOV        dword ptr [ESI + 0x11dc84],EAX
    //         0046b958     MOV        EAX,dword ptr [EBX + 0x8]
    //         0046b95b     FLD        float ptr [EBX + 0x3c]
    //         0046b95e     FSUB       float ptr [EAX + 0x34]
    //         0046b961     FMUL       float ptr [DAT_00570e60]
    //         0046b967     CALL       __ftol                                           undefined __ftol()
    //         0046b96c     MOV        dword ptr [ESI + 0x11dc88],EAX
    //         0046b972     MOV        this,dword ptr [EBX + 0x8]
    //         0046b975     FLD        float ptr [ECX + this+0x30]
    //         0046b978     FADD       float ptr [EBX + 0x38]
    //         0046b97b     FMUL       float ptr [DAT_00570e60]
    //         0046b981     CALL       __ftol                                           undefined __ftol()
    //         0046b986     MOV        dword ptr [ESI + 0x11dc8c],EAX
    //         0046b98c     MOV        EDX,dword ptr [EBX + 0x8]
    //         0046b98f     FLD        float ptr [EDX + 0x34]
    //         0046b992     FADD       float ptr [EBX + 0x3c]
    //         0046b995     FMUL       float ptr [DAT_00570e60]
    //         0046b99b     CALL       __ftol                                           undefined __ftol()
    //         0046b9a0     MOV        dword ptr [ESI + 0x11dc90],EAX
    //         0046b9a6     JMP        LAB_0046b9b2
    //                               LAB_0046b9a8                                                 XREF[1]:     0046b93c(j)  
    //         0046b9a8     MOV        dword ptr [ESI + 0x11dc4c],0xffffffff
    //                               LAB_0046b9b2                                                 XREF[2]:     0046b926(j), 0046b9a6(j)  
    //                              pathsys.cpp:962 (37)
    //         0046b9b2     MOV        this,dword ptr [ESI + 0x11dcf4]
    //         0046b9b8     MOV        EAX,dword ptr [EBP + param_11]
    //         0046b9bb     PUSH       this
    //         0046b9bc     MOV        this,dword ptr [ESI + 0x11dc44]
    //         0046b9c2     MOV        dword ptr [ESI + 0x11dc74],0x1
    //         0046b9cc     MOV        dword ptr [ESI + 0x11dc78],EAX
    //         0046b9d2     CALL       RGE_Static_Object::removeFromObstructionMap      int removeFromObstructionMap(RGE_Static_Objec
    //                              pathsys.cpp:971 (92)
    //         0046b9d7     MOV        EDX,dword ptr [ESI + 0x11dc44]
    //         0046b9dd     PUSH       0x1
    //         0046b9df     MOV        dword ptr [ESI + 0x11dc48],EAX
    //         0046b9e5     SUB        ESP,0x8
    //         0046b9e8     FLD        float ptr [EDX + 0x3c]
    //         0046b9eb     FSTP       double ptr [ESP]=>DAT_fffffff4
    //         0046b9ee     CALL       floor                                            undefined floor()
    //         0046b9f3     FSUB       float ptr [DAT_00570e64]
    //         0046b9f9     MOV        EAX,dword ptr [ESI + 0x11dc44]
    //         0046b9ff     ADD        ESP,0x8
    //         0046ba02     PUSH       this=>DAT_fffffff8
    //         0046ba03     FSTP       float ptr [ESP]=>DAT_fffffff8
    //         0046ba06     FLD        float ptr [EAX + 0x38]
    //         0046ba09     SUB        ESP,0x8
    //         0046ba0c     FSTP       double ptr [ESP]=>DAT_fffffff0
    //         0046ba0f     CALL       floor                                            undefined floor()
    //         0046ba14     FSUB       float ptr [DAT_00570e64]
    //         0046ba1a     ADD        ESP,0x8
    //         0046ba1d     PUSH       this=>DAT_fffffff4
    //         0046ba1e     MOV        this,dword ptr [ESI + 0x11dc44]
    //         0046ba24     FSTP       float ptr [ESP]=>DAT_fffffff4
    //         0046ba27     PUSH       this=>DAT_fffffff0
    //         0046ba28     MOV        this,ESI
    //         0046ba2a     CALL       PathingSystem::passable                          int passable(PathingSystem * this, RGE_Moving
    //         0046ba2f     TEST       EAX,EAX
    //         0046ba31     JZ         LAB_0046ba46
    //                              pathsys.cpp:973 (11)
    //         0046ba33     MOV        EAX,0x3f000000
    //         0046ba38     MOV        dword ptr [ESI + 0x11dc54],EAX
    //                              pathsys.cpp:974 (6)
    //         0046ba3e     MOV        dword ptr [ESI + 0x11dc58],EAX
    //                              pathsys.cpp:976 (2)
    //         0046ba44     JMP        LAB_0046ba7a
    //                               LAB_0046ba46                                                 XREF[1]:     0046ba31(j)  
    //                              pathsys.cpp:978 (20)
    //         0046ba46     FLD        float ptr [EDI + 0x38]
    //         0046ba49     SUB        ESP,0x8
    //         0046ba4c     FSTP       double ptr [ESP]=>DAT_fffffff8
    //         0046ba4f     CALL       floor                                            undefined floor()
    //         0046ba54     FSUBR      float ptr [EDI + 0x38]
    //         0046ba57     ADD        ESP,0x8
    //                              pathsys.cpp:979 (32)
    //         0046ba5a     SUB        ESP,0x8
    //         0046ba5d     FSTP       float ptr [ESI + 0x11dc54]
    //         0046ba63     FLD        float ptr [EDI + 0x3c]
    //         0046ba66     FSTP       double ptr [ESP]=>DAT_fffffff8
    //         0046ba69     CALL       floor                                            undefined floor()
    //         0046ba6e     FSUBR      float ptr [EDI + 0x3c]
    //         0046ba71     ADD        ESP,0x8
    //         0046ba74     FSTP       float ptr [ESI + 0x11dc58]
    //                               LAB_0046ba7a                                                 XREF[1]:     0046ba44(j)  
    //                              pathsys.cpp:986 (277)
    //         0046ba7a     MOV        EBX,dword ptr [ESI + 0x11dc44]
    //         0046ba80     CMP        dword ptr [EBX + 0x144],0xa
    //         0046ba87     JL         LAB_0046bb8f
    //         0046ba8d     MOV        EAX,dword ptr [EBX + 0x58]
    //         0046ba90     XOR        EDI,EDI
    //         0046ba92     TEST       EAX,EAX
    //         0046ba94     MOV        dword ptr [EBP + param_14],EDI
    //         0046ba97     JLE        LAB_0046bb8f
    //                               LAB_0046ba9d                                                 XREF[1]:     0046bb89(j)  
    //         0046ba9d     MOV        EDX,dword ptr [EBX + 0x60]
    //         0046baa0     DEC        EDX
    //         0046baa1     CMP        EDI,EDX
    //         0046baa3     JLE        LAB_0046bafb
    //         0046baa5     LEA        EAX,[EDI*0x4 + 0x4]
    //         0046baac     PUSH       EAX
    //         0046baad     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0046bab2     ADD        ESP,0x4
    //         0046bab5     MOV        dword ptr [EBP + param_15],EAX
    //         0046bab8     TEST       EAX,EAX
    //         0046baba     JZ         LAB_0046bafb
    //         0046babc     MOV        this,dword ptr [EBX + 0x60]
    //         0046babf     XOR        EAX,EAX
    //         0046bac1     TEST       this,this
    //         0046bac3     JLE        LAB_0046bae3
    //         0046bac5     MOV        EDX,dword ptr [EBP + param_15]
    //                               LAB_0046bac8                                                 XREF[1]:     0046bae1(j)  
    //         0046bac8     LEA        this,[EDI + 0x1]
    //         0046bacb     CMP        EAX,this
    //         0046bacd     JGE        LAB_0046bae3
    //         0046bacf     MOV        this,dword ptr [EBX + 0x54]
    //         0046bad2     MOV        EDI,dword ptr [EBP + param_14]
    //         0046bad5     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         0046bad8     MOV        dword ptr [EDX + EAX*0x4],this
    //         0046badb     MOV        this,dword ptr [EBX + 0x60]
    //         0046bade     INC        EAX
    //         0046badf     CMP        EAX,this
    //         0046bae1     JL         LAB_0046bac8
    //                               LAB_0046bae3                                                 XREF[2]:     0046bac3(j), 0046bacd(j)  
    //         0046bae3     MOV        EDX,dword ptr [EBX + 0x54]
    //         0046bae6     PUSH       EDX
    //         0046bae7     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0046baec     MOV        EAX,dword ptr [EBP + param_15]
    //         0046baef     ADD        ESP,0x4
    //         0046baf2     MOV        dword ptr [EBX + 0x54],EAX
    //         0046baf5     LEA        EAX,[EDI + 0x1]
    //         0046baf8     MOV        dword ptr [EBX + 0x60],EAX
    //                               LAB_0046bafb                                                 XREF[2]:     0046baa3(j), 0046baba(j)  
    //         0046bafb     MOV        this,dword ptr [EBX + 0x54]
    //         0046bafe     MOV        EDX,dword ptr [this->_padding_ + EDI*0x4]
    //         0046bb01     MOV        this,dword ptr [ESI + 0x11dc40]
    //         0046bb07     PUSH       EDX
    //         0046bb08     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         0046bb0d     MOV        EBX,EAX
    //         0046bb0f     TEST       EBX,EBX
    //         0046bb11     JZ         LAB_0046bb7c
    //         0046bb13     MOV        EAX,dword ptr [ESI + 0x11dc44]
    //         0046bb19     MOV        this,dword ptr [EBX + 0x4]
    //         0046bb1c     CMP        this,dword ptr [EAX + 0x4]
    //         0046bb1f     JZ         LAB_0046bb7c
    //         0046bb21     MOV        EAX,dword ptr [EBX]
    //         0046bb23     MOV        this,EBX
    //         0046bb25     CALL       dword ptr [EAX + 0x130]
    //         0046bb2b     AND        EAX,0xff
    //         0046bb30     MOV        this,EBX
    //         0046bb32     MOV        dword ptr [EBP + param_14],EAX
    //         0046bb35     MOV        EAX,dword ptr [EBX]
    //         0046bb37     CALL       dword ptr [EAX + 0xf4]
    //         0046bb3d     MOV        EAX,dword ptr [EBP + param_14]
    //         0046bb40     MOV        EDX,dword ptr [EBX + 0x130]
    //         0046bb46     TEST       EAX,EAX
    //         0046bb48     MOV        dword ptr [EBP + param_7],EDX
    //         0046bb4b     JNZ        LAB_0046bb6c
    //         0046bb4d     FCOMP      float ptr [DAT_00570e5c]
    //         0046bb53     FNSTSW     AX
    //         0046bb55     TEST       AH,0x40
    //         0046bb58     JZ         LAB_0046bb6e
    //         0046bb5a     FLD        float ptr [EBP + param_7]
    //         0046bb5d     FCOMP      float ptr [DAT_00570e5c]
    //         0046bb63     FNSTSW     AX
    //         0046bb65     TEST       AH,0x41
    //         0046bb68     JNZ        LAB_0046bb7c
    //         0046bb6a     JMP        LAB_0046bb6e
    //                               LAB_0046bb6c                                                 XREF[1]:     0046bb4b(j)  
    //         0046bb6c     FSTP       ST0
    //                               LAB_0046bb6e                                                 XREF[2]:     0046bb58(j), 0046bb6a(j)  
    //         0046bb6e     MOV        EAX,dword ptr [ESI + 0x11dcf4]
    //         0046bb74     MOV        this,EBX
    //         0046bb76     PUSH       EAX
    //         0046bb77     CALL       RGE_Static_Object::removeFromObstructionMap      int removeFromObstructionMap(RGE_Static_Objec
    //                               LAB_0046bb7c                                                 XREF[3]:     0046bb11(j), 0046bb1f(j), 
    //                                                                                                         0046bb68(j)  
    //         0046bb7c     MOV        EBX,dword ptr [ESI + 0x11dc44]
    //         0046bb82     INC        EDI
    //         0046bb83     MOV        dword ptr [EBP + param_14],EDI
    //         0046bb86     CMP        EDI,dword ptr [EBX + 0x58]
    //         0046bb89     JL         LAB_0046ba9d
    //                               LAB_0046bb8f                                                 XREF[2]:     0046ba87(j), 0046ba97(j)  
    //                              pathsys.cpp:991 (183)
    //         0046bb8f     MOV        EDI,dword ptr [ESI + 0x11dc44]
    //         0046bb95     MOV        this,dword ptr [EDI + 0x8]
    //         0046bb98     FLD        float ptr [EDI + 0x38]
    //         0046bb9b     FSUB       float ptr [ECX + this+0x30]
    //         0046bb9e     FMUL       float ptr [DAT_00570e60]
    //         0046bba4     CALL       __ftol                                           undefined __ftol()
    //         0046bba9     TEST       EAX,EAX
    //         0046bbab     MOV        dword ptr [ESI + 0x11dc94],EAX
    //         0046bbb1     JGE        LAB_0046bbbd
    //         0046bbb3     MOV        dword ptr [ESI + 0x11dc94],0x0
    //                               LAB_0046bbbd                                                 XREF[1]:     0046bbb1(j)  
    //         0046bbbd     MOV        EDX,dword ptr [EDI + 0x8]
    //         0046bbc0     FLD        float ptr [EDI + 0x3c]
    //         0046bbc3     FSUB       float ptr [EDX + 0x34]
    //         0046bbc6     FMUL       float ptr [DAT_00570e60]
    //         0046bbcc     CALL       __ftol                                           undefined __ftol()
    //         0046bbd1     TEST       EAX,EAX
    //         0046bbd3     MOV        dword ptr [ESI + 0x11dc98],EAX
    //         0046bbd9     JGE        LAB_0046bbe5
    //         0046bbdb     MOV        dword ptr [ESI + 0x11dc98],0x0
    //                               LAB_0046bbe5                                                 XREF[1]:     0046bbd9(j)  
    //         0046bbe5     MOV        EAX,dword ptr [EDI + 0x8]
    //         0046bbe8     FLD        float ptr [EAX + 0x30]
    //         0046bbeb     FADD       float ptr [EDI + 0x38]
    //         0046bbee     FMUL       float ptr [DAT_00570e60]
    //         0046bbf4     CALL       __ftol                                           undefined __ftol()
    //         0046bbf9     MOV        this,dword ptr [ESI + 0x4]
    //         0046bbfc     LEA        EBX,[ESI + 0x11dc9c]
    //         0046bc02     SHL        this,0x2
    //         0046bc05     CMP        EAX,this
    //         0046bc07     MOV        dword ptr [EBX],EAX
    //         0046bc09     JLE        LAB_0046bc0d
    //         0046bc0b     MOV        dword ptr [EBX],this
    //                               LAB_0046bc0d                                                 XREF[1]:     0046bc09(j)  
    //         0046bc0d     MOV        this,dword ptr [EDI + 0x8]
    //         0046bc10     FLD        float ptr [ECX + this+0x34]
    //         0046bc13     FADD       float ptr [EDI + 0x3c]
    //         0046bc16     FMUL       float ptr [DAT_00570e60]
    //         0046bc1c     CALL       __ftol                                           undefined __ftol()
    //         0046bc21     MOV        this,dword ptr [ESI + 0x8]
    //         0046bc24     MOV        dword ptr [ESI + 0x11dca0],EAX
    //         0046bc2a     SHL        this,0x2
    //         0046bc2d     CMP        EAX,this
    //         0046bc2f     JLE        LAB_0046bc37
    //         0046bc31     MOV        dword ptr [ESI + 0x11dca0],this
    //                               LAB_0046bc37                                                 XREF[1]:     0046bc2f(j)  
    //         0046bc37     LEA        EAX,[ESI + 0x11dc94]
    //         0046bc3d     PUSH       EBX
    //         0046bc3e     PUSH       EAX=>DAT_fffffff8
    //         0046bc3f     MOV        this,EDI
    //         0046bc41     CALL       RGE_Moving_Object::setInitialPoints              void setInitialPoints(RGE_Moving_Object * thi
    //                              pathsys.cpp:994 (12)
    //         0046bc46     MOV        EAX,dword ptr [EBP + param_2]
    //         0046bc49     MOV        EDX,dword ptr [EBP + param_1]
    //         0046bc4c     MOV        dword ptr [ESI + 0x11dc80],EAX
    //                              pathsys.cpp:1009 (26)
    //         0046bc52     MOV        AL,byte ptr [ESI + 0x11dcd8]
    //         0046bc58     CMP        AL,0xf0
    //         0046bc5a     MOV        dword ptr [ESI + 0x11dc7c],EDX
    //         0046bc60     MOV        dword ptr [ESI + 0x11dcc8],0xffffffff
    //         0046bc6a     JC         LAB_0046bc83
    //                              pathsys.cpp:1012 (21)
    //         0046bc6c     MOV        this,0x3f80
    //         0046bc71     OR         EAX,0xffffffff
    //         0046bc74     LEA        EDI,[ESI + 0xc]
    //         0046bc77     MOV        byte ptr [ESI + 0x11dcd8],0x0
    //         0046bc7e     STOSD.REP  ES:EDI
    //         0046bc80     STOSB      ES:EDI
    //                              pathsys.cpp:1014 (2)
    //         0046bc81     JMP        LAB_0046bc8b
    //                               LAB_0046bc83                                                 XREF[1]:     0046bc6a(j)  
    //                              pathsys.cpp:1016 (8)
    //         0046bc83     ADD        AL,0x8
    //         0046bc85     MOV        byte ptr [ESI + 0x11dcd8],AL
    //                               LAB_0046bc8b                                                 XREF[1]:     0046bc81(j)  
    //                              pathsys.cpp:1021 (10)
    //         0046bc8b     MOV        dword ptr [ESI + 0x11dc2c],0x1
    //                              pathsys.cpp:1022 (10)
    //         0046bc95     MOV        dword ptr [ESI + 0x11dc38],0x0
    //                              pathsys.cpp:863 (3)
    //         0046bc9f     MOV        EAX,dword ptr [EBP + param_3]
    //                              pathsys.cpp:864 (3)
    //         0046bca2     MOV        EBX,dword ptr [EBP + param_4]
    //                              pathsys.cpp:865 (3)
    //         0046bca5     MOV        this,dword ptr [EBP + param_1]
    //                              pathsys.cpp:866 (3)
    //         0046bca8     MOV        EDX,dword ptr [EBP + param_2]
    //                              pathsys.cpp:868 (2)
    //         0046bcab     CMP        EAX,this
    //                              pathsys.cpp:869 (2)
    //         0046bcad     JGE        LAB_0046bcb0
    //                              pathsys.cpp:870 (1)
    //         0046bcaf     XCHG       EAX,this
    //                               LAB_0046bcb0                                                 XREF[1]:     0046bcad(j)  
    //                              pathsys.cpp:872 (2)
    //         0046bcb0     CMP        EBX,EDX
    //                              pathsys.cpp:873 (2)
    //         0046bcb2     JGE        LAB_0046bcb6
    //                              pathsys.cpp:874 (2)
    //         0046bcb4     XCHG       EDX,EBX
    //                               LAB_0046bcb6                                                 XREF[1]:     0046bcb2(j)  
    //                              pathsys.cpp:877 (2)
    //         0046bcb6     SUB        EAX,this
    //                              pathsys.cpp:878 (2)
    //         0046bcb8     SUB        EBX,EDX
    //                              pathsys.cpp:880 (2)
    //         0046bcba     CMP        EAX,EBX
    //                              pathsys.cpp:882 (2)
    //         0046bcbc     JL         LAB_0046bcc3
    //                              pathsys.cpp:888 (2)
    //         0046bcbe     SUB        EAX,EBX
    //                              pathsys.cpp:889 (1)
    //         0046bcc0     XCHG       EAX,EBX
    //                              pathsys.cpp:890 (2)
    //         0046bcc1     JMP        LAB_0046bcc5
    //                               LAB_0046bcc3                                                 XREF[1]:     0046bcbc(j)  
    //                              pathsys.cpp:894 (2)
    //         0046bcc3     SUB        EBX,EAX
    //                               LAB_0046bcc5                                                 XREF[1]:     0046bcc1(j)  
    //                              pathsys.cpp:900 (5)
    //         0046bcc5     AND        EAX,0xff
    //                              pathsys.cpp:901 (3)
    //         0046bcca     SHL        EBX,0x4
    //                              pathsys.cpp:902 (7)
    //         0046bccd     MOV        EAX,dword ptr [EAX*0x4 + DiagionalDistance]      = 00000000
    //                              pathsys.cpp:903 (2)
    //         0046bcd4     ADD        EAX,EBX
    //                              pathsys.cpp:905 (3)
    //         0046bcd6     MOV        dword ptr [EBP + param_14],EAX
    //                              pathsys.cpp:1029 (6)
    //         0046bcd9     MOV        EBX,dword ptr [EBP + param_1]
    //         0046bcdc     MOV        this,dword ptr [EBP + param_2]
    //                              pathsys.cpp:1052 (78)
    //         0046bcdf     FILD       dword ptr [EBP + param_13]
    //         0046bce2     MOV        EAX,dword ptr [EBP + param_14]
    //         0046bce5     MOV        EDX,EBX
    //         0046bce7     SHL        EDX,0x8
    //         0046bcea     FCOMP      float ptr [EBP + param_6]
    //         0046bced     SUB        EDX,EBX
    //         0046bcef     ADD        EDX,this
    //         0046bcf1     MOV        dword ptr [ESI + EDX*0x4 + 0xfe10],EAX
    //         0046bcf8     MOV        dword ptr [ESI + 0x4f620],EAX
    //         0046bcfe     MOV        dword ptr [ESI + 0x11dc34],EAX
    //         0046bd04     MOV        byte ptr [ESI + 0x4f61c],BL
    //         0046bd0a     FNSTSW     AX
    //         0046bd0c     MOV        byte ptr [ESI + 0x4f61d],this
    //         0046bd12     MOV        dword ptr [ESI + 0x4f618],0x88ca6c00
    //         0046bd1c     TEST       AH,0x41
    //         0046bd1f     MOV        byte ptr [ESI + 0x11dc30],BL
    //         0046bd25     MOV        byte ptr [ESI + 0x11dc31],this
    //         0046bd2b     JNZ        LAB_0046bd35
    //                              pathsys.cpp:1053 (6)
    //         0046bd2d     MOV        EAX,dword ptr [EBP + param_13]
    //         0046bd30     SHL        EAX,0x4
    //                              pathsys.cpp:1054 (2)
    //         0046bd33     JMP        LAB_0046bd43
    //                               LAB_0046bd35                                                 XREF[1]:     0046bd2b(j)  
    //                              pathsys.cpp:1055 (17)
    //         0046bd35     FLD        float ptr [EBP + param_6]
    //         0046bd38     FMUL       float ptr [DAT_00570e58]
    //         0046bd3e     CALL       __ftol                                           undefined __ftol()
    //                               LAB_0046bd43                                                 XREF[1]:     0046bd33(j)  
    //         0046bd43     MOV        dword ptr [EBP + MGP_goalTolerance],EAX
    //                              pathsys.cpp:1058 (12)
    //         0046bd46     MOV        EAX,dword ptr [ESI + 0x11dc44]
    //         0046bd4c     MOV        EAX,dword ptr [EAX + 0x8]
    //         0046bd4f     FLD        float ptr [EAX + 0x30]
    //                              pathsys.cpp:1072 (34)
    //         0046bd52     FLD        float ptr [ESI + 0x11dc54]
    //         0046bd58     FSUB       float ptr [DAT_00570e68]
    //         0046bd5e     MOV        EAX,dword ptr [EAX + 0x34]
    //         0046bd61     MOV        dword ptr [EBP + param_1],EAX
    //         0046bd64     FSUB       ST0,ST1
    //         0046bd66     FST        float ptr [EBP + param_6]
    //         0046bd69     FSUB       float ptr [DAT_00570e6c]                         = 17h
    //         0046bd6f     CALL       __ftol                                           undefined __ftol()
    //                              pathsys.cpp:1073 (25)
    //         0046bd74     FADD       float ptr [ESI + 0x11dc54]
    //         0046bd7a     SUB        EAX,0x64
    //         0046bd7d     MOV        dword ptr [EBP + xDeltaLeft],EAX
    //         0046bd80     FLD        ST0
    //         0046bd82     FSUB       float ptr [DAT_00570e70]                         = 07h
    //         0046bd88     CALL       __ftol                                           undefined __ftol()
    //                              pathsys.cpp:1074 (35)
    //         0046bd8d     FLD        float ptr [ESI + 0x11dc58]
    //         0046bd93     FSUB       float ptr [DAT_00570e68]
    //         0046bd99     SUB        EAX,0x64
    //         0046bd9c     MOV        dword ptr [EBP + xDeltaRight],EAX
    //         0046bd9f     FSUB       float ptr [EBP + param_1]
    //         0046bda2     FST        float ptr [EBP + param_14]
    //         0046bda5     FSUB       float ptr [DAT_00570e6c]                         = 17h
    //         0046bdab     CALL       __ftol                                           undefined __ftol()
    //                              pathsys.cpp:1075 (29)
    //         0046bdb0     FLD        float ptr [EBP + param_1]
    //         0046bdb3     FADD       float ptr [ESI + 0x11dc58]
    //         0046bdb9     SUB        EAX,0x64
    //         0046bdbc     MOV        dword ptr [EBP + yDeltaUp],EAX
    //         0046bdbf     FST        float ptr [EBP + param_1]
    //         0046bdc2     FSUB       float ptr [DAT_00570e70]                         = 07h
    //         0046bdc8     CALL       __ftol                                           undefined __ftol()
    //                              pathsys.cpp:1077 (20)
    //         0046bdcd     FLD        float ptr [EBP + param_6]
    //         0046bdd0     FMUL       float ptr [DAT_00570e74]
    //         0046bdd6     SUB        EAX,0x64
    //         0046bdd9     MOV        dword ptr [EBP + yDeltaDown],EAX
    //         0046bddc     CALL       __ftol                                           undefined __ftol()
    //                              pathsys.cpp:1078 (27)
    //         0046bde1     FSUB       float ptr [DAT_00570e68]
    //         0046bde7     MOV        this,0xfffffe70
    //         0046bdec     SUB        this,EAX
    //         0046bdee     FMUL       float ptr [DAT_00570e74]
    //         0046bdf4     MOV        dword ptr [EBP + param_7],this
    //         0046bdf7     CALL       __ftol                                           undefined __ftol()
    //                              pathsys.cpp:1079 (24)
    //         0046bdfc     FLD        float ptr [EBP + param_14]
    //         0046bdff     FMUL       float ptr [DAT_00570e74]
    //         0046be05     MOV        this,0xfffffe70
    //         0046be0a     SUB        this,EAX
    //         0046be0c     MOV        dword ptr [EBP + xDeltaRight4],this
    //         0046be0f     CALL       __ftol                                           undefined __ftol()
    //                              pathsys.cpp:1080 (30)
    //         0046be14     FLD        float ptr [EBP + param_1]
    //         0046be17     FSUB       float ptr [DAT_00570e68]
    //         0046be1d     MOV        this,0xfffffe70
    //         0046be22     SUB        this,EAX
    //         0046be24     FMUL       float ptr [DAT_00570e74]
    //         0046be2a     MOV        dword ptr [EBP + param_11],this
    //         0046be2d     CALL       __ftol                                           undefined __ftol()
    //                              pathsys.cpp:1092 (78)
    //         0046be32     MOV        EDX,dword ptr [EBP + param_2]
    //         0046be35     MOV        this,0xfffffe70
    //         0046be3a     SUB        this,EAX
    //         0046be3c     MOV        EAX,dword ptr [EBP + param_3]
    //         0046be3f     MOV        dword ptr [EBP + yDeltaDown4],this
    //         0046be42     MOV        this,dword ptr [EBP + param_4]
    //         0046be45     SUB        EAX,EBX
    //         0046be47     SUB        this,EDX
    //         0046be49     MOV        EDX,EAX
    //         0046be4b     MOV        dword ptr [EBP + iterations],0x0
    //         0046be52     IMUL       EDX,EAX
    //         0046be55     MOV        EAX,this
    //         0046be57     MOV        dword ptr [EBP + param_2],EDX
    //         0046be5a     IMUL       EAX,this
    //         0046be5d     FILD       dword ptr [EBP + param_2]
    //         0046be60     MOV        dword ptr [EBP + param_2],EAX
    //         0046be63     FILD       dword ptr [EBP + param_2]
    //         0046be66     FADDP
    //         0046be68     FSQRT
    //         0046be6a     FMUL       double ptr [DAT_00570e78]
    //         0046be70     CALL       __ftol                                           undefined __ftol()
    //         0046be75     CDQ
    //         0046be76     AND        EDX,0xf
    //         0046be79     ADD        EAX,EDX
    //         0046be7b     MOV        EDI,EAX
    //         0046be7d     SAR        EDI,0x4
    //                              pathsys.cpp:1094 (9)
    //         0046be80     MOV        this,EDI
    //         0046be82     IMUL       this,dword ptr [numberPathingIterations]         = 9C4h
    //                              pathsys.cpp:1095 (5)
    //         0046be89     CMP        EDI,0xa
    //         0046be8c     JG         LAB_0046bea1
    //                              pathsys.cpp:1096 (17)
    //         0046be8e     MOV        EAX,0x66666667
    //         0046be93     IMUL       this
    //         0046be95     SAR        EDX,0x2
    //         0046be98     MOV        this,EDX
    //         0046be9a     SHR        this,0x1f
    //         0046be9d     ADD        EDX,this
    //                              pathsys.cpp:1097 (2)
    //         0046be9f     JMP        LAB_0046beb2
    //                               LAB_0046bea1                                                 XREF[1]:     0046be8c(j)  
    //                              pathsys.cpp:1098 (17)
    //         0046bea1     MOV        EAX,0x51eb851f
    //         0046bea6     IMUL       this
    //         0046bea8     SAR        EDX,0x5
    //         0046beab     MOV        EAX,EDX
    //         0046bead     SHR        EAX,0x1f
    //         0046beb0     ADD        EDX,EAX
    //                               LAB_0046beb2                                                 XREF[1]:     0046be9f(j)  
    //                              pathsys.cpp:1104 (24)
    //         0046beb2     MOV        EAX,dword ptr [ESI + 0x11dc44]
    //         0046beb8     MOV        dword ptr [EBP + numberIterationCap],EDX
    //         0046bebb     MOV        EAX,dword ptr [EAX + 0xc]
    //         0046bebe     CMP        word ptr [EAX + 0x4a],0x0
    //         0046bec3     JNZ        LAB_0046bed1
    //         0046bec5     CMP        EDX,0x64
    //         0046bec8     JLE        LAB_0046bed1
    //                              pathsys.cpp:1105 (7)
    //         0046beca     MOV        dword ptr [EBP + numberIterationCap],0x64
    //                               LAB_0046bed1                                                 XREF[2]:     0046bec3(j), 0046bec8(j)  
    //                              pathsys.cpp:1107 (12)
    //         0046bed1     MOV        this,EAX
    //         0046bed3     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         0046bed8     CMP        EAX,0x1
    //         0046bedb     JNZ        LAB_0046bf00
    //                              pathsys.cpp:1108 (35)
    //         0046bedd     LEA        this,[EDI + EDI*0x2]
    //         0046bee0     LEA        EDI,[EDI + this->_padding_*0x8]
    //         0046bee3     LEA        EAX,[EDI + EDI*0x4]
    //         0046bee6     LEA        this,[EAX + EAX*0x4]
    //         0046bee9     MOV        EAX,0x51eb851f
    //         0046beee     SHL        this,0x2
    //         0046bef1     IMUL       this
    //         0046bef3     SAR        EDX,0x5
    //         0046bef6     MOV        EAX,EDX
    //         0046bef8     SHR        EAX,0x1f
    //         0046befb     ADD        EDX,EAX
    //         0046befd     MOV        dword ptr [EBP + numberIterationCap],EDX
    //                               LAB_0046bf00                                                 XREF[1]:     0046bedb(j)  
    //                              pathsys.cpp:1113 (14)
    //         0046bf00     MOV        EAX,dword ptr [ESI + 0x11dc2c]
    //         0046bf06     TEST       EAX,EAX
    //         0046bf08     JLE        LAB_0046cedf
    //                               LAB_0046bf0e                                                 XREF[1]:     0046cac2(j)  
    //                              pathsys.cpp:1120 (29)
    //         0046bf0e     CMP        dword ptr [numberPathingIterations],-0x1         = 9C4h
    //         0046bf15     JZ         LAB_0046bf2b
    //         0046bf17     CMP        dword ptr [EBP + param_10],0x1
    //         0046bf1b     JNZ        LAB_0046bf2b
    //         0046bf1d     MOV        this,dword ptr [EBP + numberIterationCap]
    //         0046bf20     MOV        EAX,dword ptr [EBP + iterations]
    //         0046bf23     CMP        EAX,this
    //         0046bf25     JG         LAB_0046cedf
    //                               LAB_0046bf2b                                                 XREF[2]:     0046bf15(j), 0046bf1b(j)  
    //                              pathsys.cpp:1122 (13)
    //         0046bf2b     CMP        dword ptr [EBP + iterations],0x4e20
    //         0046bf32     JG         LAB_0046cedf
    //                              pathsys.cpp:1130 (34)
    //         0046bf38     MOV        this,dword ptr [MapPathsDisplay]
    //         0046bf3e     XOR        EDX,EDX
    //         0046bf40     MOV        DL,byte ptr [ESI + 0x4f61c]
    //         0046bf46     XOR        EAX,EAX
    //         0046bf48     MOV        AL,byte ptr [ESI + 0x4f61d]
    //         0046bf4e     MOV        EDI,EDX
    //         0046bf50     TEST       this,this
    //         0046bf52     MOV        dword ptr [EBP + bestPathPoint.x],EDI
    //         0046bf55     MOV        dword ptr [EBP + bestPathPoint.y],EAX
    //         0046bf58     JZ         LAB_0046bf71
    //                              pathsys.cpp:1133 (23)
    //         0046bf5a     MOV        this,dword ptr [ESI + 0x11dc3c]
    //         0046bf60     MOV        EDX,dword ptr [ECX + this+0x8d8c]
    //         0046bf66     LEA        this,[EDI + EDI*0x2]
    //         0046bf69     MOV        EDX,dword ptr [EDX + EAX*0x4]
    //         0046bf6c     MOV        byte ptr [EDX + this->_padding_*0x8 + 0xa],0x81
    //                               LAB_0046bf71                                                 XREF[1]:     0046bf58(j)  
    //                              pathsys.cpp:863 (3)
    //         0046bf71     MOV        EAX,dword ptr [EBP + param_3]
    //                              pathsys.cpp:864 (3)
    //         0046bf74     MOV        EBX,dword ptr [EBP + param_4]
    //                              pathsys.cpp:865 (3)
    //         0046bf77     MOV        this,dword ptr [EBP + bestPathPoint.x]
    //                              pathsys.cpp:866 (3)
    //         0046bf7a     MOV        EDX,dword ptr [EBP + bestPathPoint.y]
    //                              pathsys.cpp:868 (2)
    //         0046bf7d     CMP        EAX,this
    //                              pathsys.cpp:869 (2)
    //         0046bf7f     JGE        LAB_0046bf82
    //                              pathsys.cpp:870 (1)
    //         0046bf81     XCHG       EAX,this
    //                               LAB_0046bf82                                                 XREF[1]:     0046bf7f(j)  
    //                              pathsys.cpp:872 (2)
    //         0046bf82     CMP        EBX,EDX
    //                              pathsys.cpp:873 (2)
    //         0046bf84     JGE        LAB_0046bf88
    //                              pathsys.cpp:874 (2)
    //         0046bf86     XCHG       EDX,EBX
    //                               LAB_0046bf88                                                 XREF[1]:     0046bf84(j)  
    //                              pathsys.cpp:877 (2)
    //         0046bf88     SUB        EAX,this
    //                              pathsys.cpp:878 (2)
    //         0046bf8a     SUB        EBX,EDX
    //                              pathsys.cpp:880 (2)
    //         0046bf8c     CMP        EAX,EBX
    //                              pathsys.cpp:882 (2)
    //         0046bf8e     JL         LAB_0046bf95
    //                              pathsys.cpp:888 (2)
    //         0046bf90     SUB        EAX,EBX
    //                              pathsys.cpp:889 (1)
    //         0046bf92     XCHG       EAX,EBX
    //                              pathsys.cpp:890 (2)
    //         0046bf93     JMP        LAB_0046bf97
    //                               LAB_0046bf95                                                 XREF[1]:     0046bf8e(j)  
    //                              pathsys.cpp:894 (2)
    //         0046bf95     SUB        EBX,EAX
    //                               LAB_0046bf97                                                 XREF[1]:     0046bf93(j)  
    //                              pathsys.cpp:900 (5)
    //         0046bf97     AND        EAX,0xff
    //                              pathsys.cpp:901 (3)
    //         0046bf9c     SHL        EBX,0x4
    //                              pathsys.cpp:902 (7)
    //         0046bf9f     MOV        EAX,dword ptr [EAX*0x4 + DiagionalDistance]      = 00000000
    //                              pathsys.cpp:903 (2)
    //         0046bfa6     ADD        EAX,EBX
    //                              pathsys.cpp:905 (3)
    //         0046bfa8     MOV        dword ptr [EBP + param_2],EAX
    //                              pathsys.cpp:1148 (6)
    //         0046bfab     MOV        EBX,dword ptr [ESI + 0x4f61c]
    //                              pathsys.cpp:1149 (6)
    //         0046bfb1     MOV        EDX,dword ptr [ESI + 0x4f61d]
    //                              pathsys.cpp:1153 (65)
    //         0046bfb7     MOV        EAX,dword ptr [EBP + param_3]
    //         0046bfba     MOV        this,dword ptr [EBP + param_4]
    //         0046bfbd     AND        EBX,0xff
    //         0046bfc3     AND        EDX,0xff
    //         0046bfc9     SUB        EAX,EBX
    //         0046bfcb     MOV        dword ptr [EBP + temp.y],EDX
    //         0046bfce     SUB        this,EDX
    //         0046bfd0     MOV        EDX,EAX
    //         0046bfd2     IMUL       EDX,EAX
    //         0046bfd5     MOV        EAX,this
    //         0046bfd7     MOV        dword ptr [EBP + param_2],EDX
    //         0046bfda     IMUL       EAX,this
    //         0046bfdd     FILD       dword ptr [EBP + param_2]
    //         0046bfe0     MOV        dword ptr [EBP + param_2],EAX
    //         0046bfe3     MOV        dword ptr [EBP + temp.x],EBX
    //         0046bfe6     FILD       dword ptr [EBP + param_2]
    //         0046bfe9     FADDP
    //         0046bfeb     FSQRT
    //         0046bfed     FMUL       double ptr [DAT_00570e78]
    //         0046bff3     CALL       __ftol                                           undefined __ftol()
    //                              pathsys.cpp:1155 (15)
    //         0046bff8     MOV        this,dword ptr [ESI + 0x11dcc8]
    //         0046bffe     CMP        this,-0x1
    //         0046c001     JZ         LAB_0046c007
    //         0046c003     CMP        EAX,this
    //         0046c005     JGE        LAB_0046c00d
    //                               LAB_0046c007                                                 XREF[1]:     0046c001(j)  
    //                              pathsys.cpp:1156 (6)
    //         0046c007     MOV        dword ptr [ESI + 0x11dcc8],EAX
    //                               LAB_0046c00d                                                 XREF[1]:     0046c005(j)  
    //                              pathsys.cpp:1162 (9)
    //         0046c00d     CMP        EAX,dword ptr [EBP + MGP_goalTolerance]
    //         0046c010     JL         LAB_0046cacd
    //                              pathsys.cpp:1226 (8)
    //         0046c016     CMP        EAX,dword ptr [ESI + 0x11dc34]
    //         0046c01c     JGE        LAB_0046c03c
    //                              pathsys.cpp:1228 (6)
    //         0046c01e     MOV        this,byte ptr [ESI + 0x4f61c]
    //                              pathsys.cpp:1230 (24)
    //         0046c024     MOV        dword ptr [ESI + 0x11dc34],EAX
    //         0046c02a     MOV        byte ptr [ESI + 0x11dc30],this
    //         0046c030     MOV        this,byte ptr [ESI + 0x4f61d]
    //         0046c036     MOV        byte ptr [ESI + 0x11dc31],this
    //                               LAB_0046c03c                                                 XREF[1]:     0046c01c(j)  
    //                              pathsys.cpp:1237 (6)
    //         0046c03c     MOV        EAX,dword ptr [ESI + 0x11dc38]
    //                              pathsys.cpp:1248 (246)
    //         0046c042     MOV        dword ptr [EBP + param_6],0x1
    //         0046c049     INC        EAX
    //         0046c04a     MOV        dword ptr [ESI + 0x11dc38],EAX
    //         0046c050     MOV        EAX,dword ptr [ESI + 0x11dc2c]
    //         0046c056     MOV        this,byte ptr [ESI + EAX*0x8 + 0x4f614]
    //         0046c05d     MOV        byte ptr [ESI + 0x4f61c],this
    //         0046c063     MOV        DL,byte ptr [ESI + EAX*0x8 + 0x4f615]
    //         0046c06a     MOV        byte ptr [ESI + 0x4f61d],DL
    //         0046c070     MOV        this,dword ptr [ESI + EAX*0x8 + 0x4f618]
    //         0046c077     MOV        dword ptr [ESI + 0x4f620],this
    //         0046c07d     LEA        this,[EAX + -0x1]
    //         0046c080     MOV        dword ptr [ESI + 0x11dc2c],this
    //         0046c086     MOV        DL,byte ptr [ESI + 0x4f61c]
    //         0046c08c     MOV        AL,byte ptr [ESI + 0x4f61d]
    //         0046c092     MOV        byte ptr [EBP + param_2],DL
    //         0046c095     MOV        EDX,dword ptr [ESI + 0x4f620]
    //         0046c09b     MOV        byte ptr [EBP + param_1],AL
    //         0046c09e     MOV        EAX,this
    //         0046c0a0     MOV        dword ptr [EBP + param_15],EDX
    //         0046c0a3     CDQ
    //         0046c0a4     SUB        EAX,EDX
    //         0046c0a6     SAR        EAX,0x1
    //         0046c0a8     CMP        EAX,0x1
    //         0046c0ab     JLE        LAB_0046c112
    //         0046c0ad     MOV        dword ptr [EBP + param_14],this
    //                               LAB_0046c0b0                                                 XREF[1]:     0046c110(j)  
    //         0046c0b0     MOV        EAX,dword ptr [EBP + param_6]
    //         0046c0b3     LEA        this,[EAX + EAX*0x1]
    //         0046c0b6     MOV        EAX,dword ptr [EBP + param_14]
    //         0046c0b9     CMP        this,EAX
    //         0046c0bb     JGE        LAB_0046c0d0
    //         0046c0bd     MOV        EDX,dword ptr [ESI + this->_padding_*0x8 + 0x4
    //         0046c0c4     MOV        EAX,dword ptr [ESI + this->_padding_*0x8 + 0x4
    //         0046c0cb     CMP        EDX,EAX
    //         0046c0cd     JLE        LAB_0046c0d0
    //         0046c0cf     INC        this
    //                               LAB_0046c0d0                                                 XREF[2]:     0046c0bb(j), 0046c0cd(j)  
    //         0046c0d0     MOV        EAX,dword ptr [EBP + param_15]
    //         0046c0d3     MOV        EDX,dword ptr [ESI + this->_padding_*0x8 + 0x4
    //         0046c0da     CMP        EAX,EDX
    //         0046c0dc     JL         LAB_0046c112
    //         0046c0de     MOV        EAX,dword ptr [EBP + param_6]
    //         0046c0e1     MOV        EDX,dword ptr [ESI + this->_padding_*0x8 + 0x4
    //         0046c0e8     MOV        dword ptr [EBP + param_6],this
    //         0046c0eb     MOV        dword ptr [ESI + EAX*0x8 + 0x4f614],EDX
    //         0046c0f2     MOV        EDX,dword ptr [ESI + this->_padding_*0x8 + 0x4
    //         0046c0f9     MOV        dword ptr [ESI + EAX*0x8 + 0x4f618],EDX
    //         0046c100     MOV        EAX,dword ptr [ESI + 0x11dc2c]
    //         0046c106     MOV        dword ptr [EBP + param_14],EAX
    //         0046c109     CDQ
    //         0046c10a     SUB        EAX,EDX
    //         0046c10c     SAR        EAX,0x1
    //         0046c10e     CMP        this,EAX
    //         0046c110     JL         LAB_0046c0b0
    //                               LAB_0046c112                                                 XREF[2]:     0046c0ab(j), 0046c0dc(j)  
    //         0046c112     MOV        EAX,dword ptr [EBP + param_6]
    //         0046c115     CMP        EAX,0x1
    //         0046c118     JZ         LAB_0046c138
    //         0046c11a     MOV        this,byte ptr [EBP + param_2]
    //         0046c11d     MOV        DL,byte ptr [EBP + param_1]
    //         0046c120     MOV        byte ptr [ESI + EAX*0x8 + 0x4f614],this
    //         0046c127     MOV        this,dword ptr [EBP + param_15]
    //         0046c12a     MOV        byte ptr [ESI + EAX*0x8 + 0x4f615],DL
    //         0046c131     MOV        dword ptr [ESI + EAX*0x8 + 0x4f618],this
    //                               LAB_0046c138                                                 XREF[1]:     0046c118(j)  
    //                              pathsys.cpp:1310 (27)
    //         0046c138     MOV        EAX,dword ptr [EBP + bestPathPoint.y]
    //         0046c13b     MOV        EDX,EDI
    //         0046c13d     SHL        EDX,0x8
    //         0046c140     SUB        EDX,EDI
    //         0046c142     XOR        this,this
    //         0046c144     ADD        EDX,EAX
    //         0046c146     MOV        dword ptr [EBP + i],this
    //         0046c149     MOV        dword ptr [EBP + SkipBit],0x1
    //         0046c150     MOV        dword ptr [EBP + local_38],EDX
    //                               LAB_0046c153                                                 XREF[1]:     0046caa3(j)  
    //                              pathsys.cpp:1266 (12)
    //         0046c153     CMP        this,0x7
    //         0046c156     JA         switchD_0046c158::default
    //                               switchD_0046c158::switchD
    //         0046c158     JMP        dword ptr [this->_padding_*0x4 + ->switchD_004   = 0046c15f
    //                               switchD_0046c158::caseD_0                                    XREF[2]:     0046c158(j), 0046d204(*)  
    //                              pathsys.cpp:1269 (3)
    //         0046c15f     MOV        EAX,dword ptr [EBP + param_13]
    //                              pathsys.cpp:1270 (13)
    //         0046c162     MOV        EDX,dword ptr [EBP + temp.y]
    //         0046c165     SUB        EBX,EAX
    //         0046c167     SUB        EDX,EAX
    //         0046c169     MOV        dword ptr [EBP + temp.x],EBX
    //         0046c16c     MOV        dword ptr [EBP + temp.y],EDX
    //                              pathsys.cpp:1271 (2)
    //         0046c16f     JMP        switchD_0046c158::default
    //                               switchD_0046c158::caseD_2                                    XREF[3]:     0046c158(j), 0046d208(*), 
    //                               switchD_0046c158::caseD_1                                                 0046d20c(*)  
    //                              pathsys.cpp:1276 (6)
    //         0046c171     ADD        EBX,dword ptr [EBP + param_13]
    //         0046c174     MOV        dword ptr [EBP + temp.x],EBX
    //                              pathsys.cpp:1277 (2)
    //         0046c177     JMP        switchD_0046c158::default
    //                               switchD_0046c158::caseD_3                                    XREF[2]:     0046c158(j), 0046d210(*)  
    //                              pathsys.cpp:1279 (8)
    //         0046c179     MOV        EDX,dword ptr [EBP + param_13]
    //         0046c17c     MOV        EAX,dword ptr [EBP + temp.y]
    //         0046c17f     ADD        EAX,EDX
    //                              pathsys.cpp:1280 (2)
    //         0046c181     JMP        LAB_0046c1a0
    //                               switchD_0046c158::caseD_4                                    XREF[2]:     0046c158(j), 0046d214(*)  
    //                              pathsys.cpp:1282 (11)
    //         0046c183     MOV        EAX,dword ptr [EBP + param_13]
    //         0046c186     MOV        EDX,dword ptr [EBP + temp.y]
    //         0046c189     ADD        EDX,EAX
    //         0046c18b     MOV        dword ptr [EBP + temp.y],EDX
    //                              pathsys.cpp:1283 (2)
    //         0046c18e     JMP        switchD_0046c158::default
    //                               switchD_0046c158::caseD_6                                    XREF[3]:     0046c158(j), 0046d218(*), 
    //                               switchD_0046c158::caseD_5                                                 0046d21c(*)  
    //                              pathsys.cpp:1288 (6)
    //         0046c190     SUB        EBX,dword ptr [EBP + param_13]
    //         0046c193     MOV        dword ptr [EBP + temp.x],EBX
    //                              pathsys.cpp:1289 (2)
    //         0046c196     JMP        switchD_0046c158::default
    //                               switchD_0046c158::caseD_7                                    XREF[2]:     0046c158(j), 0046d220(*)  
    //                              pathsys.cpp:1291 (11)
    //         0046c198     MOV        EDX,dword ptr [EBP + param_13]
    //         0046c19b     MOV        EAX,dword ptr [EBP + temp.y]
    //         0046c19e     SUB        EAX,EDX
    //                               LAB_0046c1a0                                                 XREF[1]:     0046c181(j)  
    //         0046c1a0     MOV        dword ptr [EBP + temp.y],EAX
    //                               switchD_0046c158::default                                    XREF[5]:     0046c156(j), 0046c16f(j), 
    //                                                                                                         0046c177(j), 0046c18e(j), 
    //                                                                                                         0046c196(j)  
    //                              pathsys.cpp:1310 (46)
    //         0046c1a3     MOV        EAX,dword ptr [EBP + local_38]
    //         0046c1a6     MOV        AL,byte ptr [ESI + EAX*0x1 + 0xc]
    //         0046c1aa     MOV        DL,AL
    //         0046c1ac     AND        DL,0xf8
    //         0046c1af     CMP        DL,byte ptr [ESI + 0x11dcd8]
    //         0046c1b5     JNZ        LAB_0046c1bc
    //         0046c1b7     AND        EAX,0x7
    //         0046c1ba     JMP        LAB_0046c1c1
    //                               LAB_0046c1bc                                                 XREF[1]:     0046c1b5(j)  
    //         0046c1bc     MOV        EAX,0x8
    //                               LAB_0046c1c1                                                 XREF[1]:     0046c1ba(j)  
    //         0046c1c1     MOV        EDX,dword ptr [EBP + SkipBit]
    //         0046c1c4     TEST       dword ptr [EAX*0x4 + FacetSkipMask],EDX          = 00000038
    //         0046c1cb     JNZ        LAB_0046ca94
    //                              pathsys.cpp:1314 (37)
    //         0046c1d1     TEST       EBX,EBX
    //         0046c1d3     JL         LAB_0046ca94
    //         0046c1d9     MOV        EDX,dword ptr [EBP + temp.y]
    //         0046c1dc     TEST       EDX,EDX
    //         0046c1de     JL         LAB_0046ca94
    //         0046c1e4     CMP        EBX,dword ptr [ESI + 0x4]
    //         0046c1e7     JGE        LAB_0046ca94
    //         0046c1ed     CMP        EDX,dword ptr [ESI + 0x8]
    //         0046c1f0     JGE        LAB_0046ca94
    //                              pathsys.cpp:1329 (20)
    //         0046c1f6     CMP        EBX,dword ptr [ESI + 0x11dc7c]
    //         0046c1fc     JNZ        LAB_0046c20a
    //         0046c1fe     CMP        EDX,dword ptr [ESI + 0x11dc80]
    //         0046c204     JZ         LAB_0046ca94
    //                               LAB_0046c20a                                                 XREF[1]:     0046c1fc(j)  
    //                              pathsys.cpp:1339 (48)
    //         0046c20a     MOV        EAX,EBX
    //         0046c20c     MOV        this,EDX
    //         0046c20e     MOV        EDX,dword ptr [EBP + bestPathPoint.y]
    //         0046c211     SUB        EAX,EDI
    //         0046c213     SUB        this,EDX
    //         0046c215     MOV        EDX,EAX
    //         0046c217     IMUL       EDX,EAX
    //         0046c21a     MOV        EAX,this
    //         0046c21c     MOV        dword ptr [EBP + param_2],EDX
    //         0046c21f     IMUL       EAX,this
    //         0046c222     FILD       dword ptr [EBP + param_2]
    //         0046c225     MOV        dword ptr [EBP + param_2],EAX
    //         0046c228     FILD       dword ptr [EBP + param_2]
    //         0046c22b     FADDP
    //         0046c22d     FSQRT
    //         0046c22f     FMUL       double ptr [DAT_00570e78]
    //         0046c235     CALL       __ftol                                           undefined __ftol()
    //                              pathsys.cpp:1340 (16)
    //         0046c23a     MOV        this,dword ptr [EBP + local_38]
    //         0046c23d     MOV        dword ptr [EBP + param_1],EAX
    //         0046c240     MOV        EDX,dword ptr [ESI + this->_padding_*0x4 + 0xf
    //         0046c247     MOV        dword ptr [EBP + param_2],EDX
    //                              pathsys.cpp:863 (3)
    //         0046c24a     MOV        EAX,dword ptr [EBP + param_3]
    //                              pathsys.cpp:864 (3)
    //         0046c24d     MOV        EBX,dword ptr [EBP + param_4]
    //                              pathsys.cpp:865 (3)
    //         0046c250     MOV        this,dword ptr [EBP + bestPathPoint.x]
    //                              pathsys.cpp:866 (3)
    //         0046c253     MOV        EDX,dword ptr [EBP + bestPathPoint.y]
    //                              pathsys.cpp:868 (2)
    //         0046c256     CMP        EAX,this
    //                              pathsys.cpp:869 (2)
    //         0046c258     JGE        LAB_0046c25b
    //                              pathsys.cpp:870 (1)
    //         0046c25a     XCHG       EAX,this
    //                               LAB_0046c25b                                                 XREF[1]:     0046c258(j)  
    //                              pathsys.cpp:872 (2)
    //         0046c25b     CMP        EBX,EDX
    //                              pathsys.cpp:873 (2)
    //         0046c25d     JGE        LAB_0046c261
    //                              pathsys.cpp:874 (2)
    //         0046c25f     XCHG       EDX,EBX
    //                               LAB_0046c261                                                 XREF[1]:     0046c25d(j)  
    //                              pathsys.cpp:877 (2)
    //         0046c261     SUB        EAX,this
    //                              pathsys.cpp:878 (2)
    //         0046c263     SUB        EBX,EDX
    //                              pathsys.cpp:880 (2)
    //         0046c265     CMP        EAX,EBX
    //                              pathsys.cpp:882 (2)
    //         0046c267     JL         LAB_0046c26e
    //                              pathsys.cpp:888 (2)
    //         0046c269     SUB        EAX,EBX
    //                              pathsys.cpp:889 (1)
    //         0046c26b     XCHG       EAX,EBX
    //                              pathsys.cpp:890 (2)
    //         0046c26c     JMP        LAB_0046c270
    //                               LAB_0046c26e                                                 XREF[1]:     0046c267(j)  
    //                              pathsys.cpp:894 (2)
    //         0046c26e     SUB        EBX,EAX
    //                               LAB_0046c270                                                 XREF[1]:     0046c26c(j)  
    //                              pathsys.cpp:900 (5)
    //         0046c270     AND        EAX,0xff
    //                              pathsys.cpp:901 (3)
    //         0046c275     SHL        EBX,0x4
    //                              pathsys.cpp:902 (7)
    //         0046c278     MOV        EAX,dword ptr [EAX*0x4 + DiagionalDistance]      = 00000000
    //                              pathsys.cpp:903 (2)
    //         0046c27f     ADD        EAX,EBX
    //                              pathsys.cpp:905 (3)
    //         0046c281     MOV        dword ptr [EBP + local_58],EAX
    //                              pathsys.cpp:863 (3)
    //         0046c284     MOV        EAX,dword ptr [EBP + param_3]
    //                              pathsys.cpp:864 (3)
    //         0046c287     MOV        EBX,dword ptr [EBP + param_4]
    //                              pathsys.cpp:865 (3)
    //         0046c28a     MOV        this,dword ptr [EBP + temp.x]
    //                              pathsys.cpp:866 (3)
    //         0046c28d     MOV        EDX,dword ptr [EBP + temp.y]
    //                              pathsys.cpp:868 (2)
    //         0046c290     CMP        EAX,this
    //                              pathsys.cpp:869 (2)
    //         0046c292     JGE        LAB_0046c295
    //                              pathsys.cpp:870 (1)
    //         0046c294     XCHG       EAX,this
    //                               LAB_0046c295                                                 XREF[1]:     0046c292(j)  
    //                              pathsys.cpp:872 (2)
    //         0046c295     CMP        EBX,EDX
    //                              pathsys.cpp:873 (2)
    //         0046c297     JGE        LAB_0046c29b
    //                              pathsys.cpp:874 (2)
    //         0046c299     XCHG       EDX,EBX
    //                               LAB_0046c29b                                                 XREF[1]:     0046c297(j)  
    //                              pathsys.cpp:877 (2)
    //         0046c29b     SUB        EAX,this
    //                              pathsys.cpp:878 (2)
    //         0046c29d     SUB        EBX,EDX
    //                              pathsys.cpp:880 (2)
    //         0046c29f     CMP        EAX,EBX
    //                              pathsys.cpp:882 (2)
    //         0046c2a1     JL         LAB_0046c2a8
    //                              pathsys.cpp:888 (2)
    //         0046c2a3     SUB        EAX,EBX
    //                              pathsys.cpp:889 (1)
    //         0046c2a5     XCHG       EAX,EBX
    //                              pathsys.cpp:890 (2)
    //         0046c2a6     JMP        LAB_0046c2aa
    //                               LAB_0046c2a8                                                 XREF[1]:     0046c2a1(j)  
    //                              pathsys.cpp:894 (2)
    //         0046c2a8     SUB        EBX,EAX
    //                               LAB_0046c2aa                                                 XREF[1]:     0046c2a6(j)  
    //                              pathsys.cpp:900 (5)
    //         0046c2aa     AND        EAX,0xff
    //                              pathsys.cpp:901 (3)
    //         0046c2af     SHL        EBX,0x4
    //                              pathsys.cpp:902 (7)
    //         0046c2b2     MOV        EAX,dword ptr [EAX*0x4 + DiagionalDistance]      = 00000000
    //                              pathsys.cpp:903 (2)
    //         0046c2b9     ADD        EAX,EBX
    //                              pathsys.cpp:905 (3)
    //         0046c2bb     MOV        dword ptr [EBP + local_54],EAX
    //                              pathsys.cpp:1343 (14)
    //         0046c2be     MOV        EDX,dword ptr [EBP + local_54]
    //         0046c2c1     MOV        EAX,dword ptr [EBP + local_58]
    //         0046c2c4     MOV        EBX,dword ptr [EBP + param_2]
    //         0046c2c7     MOV        this,dword ptr [EBP + param_1]
    //         0046c2ca     SUB        EDX,EAX
    //                              pathsys.cpp:1354 (59)
    //         0046c2cc     MOV        EAX,dword ptr [EBP + temp.y]
    //         0046c2cf     ADD        EDX,EBX
    //         0046c2d1     ADD        EDX,this
    //         0046c2d3     MOV        this,dword ptr [EBP + temp.x]
    //         0046c2d6     MOV        EBX,this
    //         0046c2d8     MOV        dword ptr [EBP + newTotal],EDX
    //         0046c2db     SHL        EBX,0x8
    //         0046c2de     SUB        EBX,this
    //         0046c2e0     ADD        EBX,EAX
    //         0046c2e2     MOV        dword ptr [EBP + local_48],EBX
    //         0046c2e5     LEA        EBX,[ESI + EBX*0x1 + 0xc]
    //         0046c2e9     MOV        dword ptr [EBP + local_70],EBX
    //         0046c2ec     MOV        BL,byte ptr [EBX]
    //         0046c2ee     MOV        byte ptr [EBP + param_2],BL
    //         0046c2f1     AND        BL,0xf8
    //         0046c2f4     CMP        BL,byte ptr [ESI + 0x11dcd8]
    //         0046c2fa     JNZ        LAB_0046c304
    //         0046c2fc     MOV        BL,byte ptr [EBP + param_2]
    //         0046c2ff     AND        BL,0x7
    //         0046c302     JMP        LAB_0046c307
    //                               LAB_0046c304                                                 XREF[1]:     0046c2fa(j)  
    //         0046c304     OR         BL,0xff
    //                               LAB_0046c307                                                 XREF[1]:     0046c302(j)  
    //                              pathsys.cpp:1355 (5)
    //         0046c307     CMP        BL,0x8
    //         0046c30a     JNC        LAB_0046c31c
    //                              pathsys.cpp:1362 (16)
    //         0046c30c     MOV        EBX,dword ptr [EBP + local_48]
    //         0046c30f     CMP        dword ptr [ESI + EBX*0x4 + 0xfe10],EDX
    //         0046c316     JLE        LAB_0046ca8e
    //                               LAB_0046c31c                                                 XREF[1]:     0046c30a(j)  
    //                              pathsys.cpp:1395 (19)
    //         0046c31c     MOV        EDX,dword ptr [EBP + i]
    //         0046c31f     CMP        EDX,0x7
    //         0046c322     JA         switchD_0046c328::default
    //                               switchD_0046c328::switchD
    //         0046c328     JMP        dword ptr [EDX*0x4 + switchD_0046c328::switchd   = 0046c32f
    //                               switchD_0046c328::caseD_0                                    XREF[2]:     0046c328(j), 0046d224(*)  
    //                              pathsys.cpp:1405 (3)
    //         0046c32f     MOV        EDX,dword ptr [EBP + xDeltaLeft]
    //                              pathsys.cpp:1408 (20)
    //         0046c332     MOV        EBX,dword ptr [EBP + bestPathPoint.y]
    //         0046c335     ADD        EDX,this
    //         0046c337     MOV        this,dword ptr [EBP + yDeltaUp]
    //         0046c33a     ADD        EAX,this
    //         0046c33c     MOV        this,dword ptr [EBP + xDeltaRight]
    //         0046c33f     ADD        this,EDI
    //         0046c341     MOV        EDI,dword ptr [EBP + yDeltaDown]
    //         0046c344     ADD        EDI,EBX
    //                              pathsys.cpp:1410 (12)
    //         0046c346     MOV        EBX,dword ptr [EBP + temp.x]
    //         0046c349     MOV        dword ptr [EBP + param_14],EDI
    //         0046c34c     MOV        EDI,dword ptr [EBP + param_7]
    //         0046c34f     LEA        EDI,[EDI + EBX*0x4]
    //                              pathsys.cpp:1411 (9)
    //         0046c352     MOV        EBX,dword ptr [EBP + temp.y]
    //         0046c355     MOV        dword ptr [EBP + param_1],EDI
    //         0046c358     MOV        EDI,dword ptr [EBP + param_11]
    //                              pathsys.cpp:1415 (5)
    //         0046c35b     JMP        LAB_0046c4d2
    //                               switchD_0046c328::caseD_1                                    XREF[2]:     0046c328(j), 0046d228(*)  
    //                              pathsys.cpp:1426 (6)
    //         0046c360     MOV        this,dword ptr [EBP + yDeltaUp]
    //         0046c363     MOV        EDX,dword ptr [EBP + xDeltaLeft]
    //                              pathsys.cpp:1428 (17)
    //         0046c366     MOV        EBX,dword ptr [EBP + bestPathPoint.y]
    //         0046c369     ADD        EAX,this
    //         0046c36b     MOV        this,dword ptr [EBP + xDeltaRight]
    //         0046c36e     ADD        EDX,EDI
    //         0046c370     ADD        this,EDI
    //         0046c372     MOV        EDI,dword ptr [EBP + yDeltaDown]
    //         0046c375     ADD        EDI,EBX
    //                              pathsys.cpp:1430 (12)
    //         0046c377     MOV        EBX,dword ptr [EBP + bestPathPoint.x]
    //         0046c37a     MOV        dword ptr [EBP + param_14],EDI
    //         0046c37d     MOV        EDI,dword ptr [EBP + param_7]
    //         0046c380     LEA        EDI,[EDI + EBX*0x4]
    //                              pathsys.cpp:1431 (9)
    //         0046c383     MOV        EBX,dword ptr [EBP + temp.y]
    //         0046c386     MOV        dword ptr [EBP + param_1],EDI
    //         0046c389     MOV        EDI,dword ptr [EBP + param_11]
    //                              pathsys.cpp:1435 (5)
    //         0046c38c     JMP        LAB_0046c4d2
    //                               switchD_0046c328::caseD_2                                    XREF[2]:     0046c328(j), 0046d22c(*)  
    //                              pathsys.cpp:1445 (3)
    //         0046c391     MOV        EDX,dword ptr [EBP + xDeltaLeft]
    //                              pathsys.cpp:1448 (20)
    //         0046c394     MOV        EBX,dword ptr [EBP + bestPathPoint.y]
    //         0046c397     ADD        EDX,EDI
    //         0046c399     MOV        EDI,dword ptr [EBP + yDeltaUp]
    //         0046c39c     ADD        EAX,EDI
    //         0046c39e     MOV        EDI,dword ptr [EBP + xDeltaRight]
    //         0046c3a1     ADD        this,EDI
    //         0046c3a3     MOV        EDI,dword ptr [EBP + yDeltaDown]
    //         0046c3a6     ADD        EDI,EBX
    //                              pathsys.cpp:1450 (12)
    //         0046c3a8     MOV        EBX,dword ptr [EBP + bestPathPoint.x]
    //         0046c3ab     MOV        dword ptr [EBP + param_14],EDI
    //         0046c3ae     MOV        EDI,dword ptr [EBP + param_7]
    //         0046c3b1     LEA        EDI,[EDI + EBX*0x4]
    //                              pathsys.cpp:1451 (9)
    //         0046c3b4     MOV        EBX,dword ptr [EBP + temp.y]
    //         0046c3b7     MOV        dword ptr [EBP + param_1],EDI
    //         0046c3ba     MOV        EDI,dword ptr [EBP + param_11]
    //                              pathsys.cpp:1455 (2)
    //         0046c3bd     JMP        LAB_0046c3ef
    //                               switchD_0046c328::caseD_3                                    XREF[2]:     0046c328(j), 0046d230(*)  
    //                              pathsys.cpp:1465 (3)
    //         0046c3bf     MOV        EAX,dword ptr [EBP + xDeltaLeft]
    //                              pathsys.cpp:1468 (24)
    //         0046c3c2     MOV        EBX,dword ptr [EBP + bestPathPoint.y]
    //         0046c3c5     LEA        EDX,[EAX + EDI*0x1]
    //         0046c3c8     MOV        EAX,dword ptr [EBP + yDeltaUp]
    //         0046c3cb     MOV        EDI,dword ptr [EBP + bestPathPoint.y]
    //         0046c3ce     ADD        EAX,EDI
    //         0046c3d0     MOV        EDI,dword ptr [EBP + xDeltaRight]
    //         0046c3d3     ADD        this,EDI
    //         0046c3d5     MOV        EDI,dword ptr [EBP + yDeltaDown]
    //         0046c3d8     ADD        EDI,EBX
    //                              pathsys.cpp:1470 (12)
    //         0046c3da     MOV        EBX,dword ptr [EBP + bestPathPoint.x]
    //         0046c3dd     MOV        dword ptr [EBP + param_14],EDI
    //         0046c3e0     MOV        EDI,dword ptr [EBP + param_7]
    //         0046c3e3     LEA        EDI,[EDI + EBX*0x4]
    //                              pathsys.cpp:1471 (12)
    //         0046c3e6     MOV        EBX,dword ptr [EBP + bestPathPoint.y]
    //         0046c3e9     MOV        dword ptr [EBP + param_1],EDI
    //         0046c3ec     MOV        EDI,dword ptr [EBP + param_11]
    //                               LAB_0046c3ef                                                 XREF[1]:     0046c3bd(j)  
    //         0046c3ef     LEA        EDI,[EDI + EBX*0x4]
    //                              pathsys.cpp:1472 (12)
    //         0046c3f2     MOV        EBX,dword ptr [EBP + temp.x]
    //         0046c3f5     MOV        dword ptr [EBP + param_6],EDI
    //         0046c3f8     MOV        EDI,dword ptr [EBP + xDeltaRight4]
    //         0046c3fb     LEA        EDI,[EDI + EBX*0x4]
    //                              pathsys.cpp:1473 (9)
    //         0046c3fe     MOV        EBX,dword ptr [EBP + bestPathPoint.y]
    //         0046c401     MOV        dword ptr [EBP + param_2],EDI
    //         0046c404     MOV        EDI,dword ptr [EBP + yDeltaDown4]
    //                              pathsys.cpp:1475 (5)
    //         0046c407     JMP        LAB_0046c51b
    //                               switchD_0046c328::caseD_4                                    XREF[2]:     0046c328(j), 0046d234(*)  
    //                              pathsys.cpp:1485 (3)
    //         0046c40c     MOV        EDX,dword ptr [EBP + xDeltaLeft]
    //                              pathsys.cpp:1486 (3)
    //         0046c40f     MOV        EAX,dword ptr [EBP + yDeltaUp]
    //                              pathsys.cpp:1488 (20)
    //         0046c412     MOV        EBX,dword ptr [EBP + temp.y]
    //         0046c415     ADD        EDX,EDI
    //         0046c417     MOV        EDI,dword ptr [EBP + bestPathPoint.y]
    //         0046c41a     ADD        EAX,EDI
    //         0046c41c     MOV        EDI,dword ptr [EBP + xDeltaRight]
    //         0046c41f     ADD        this,EDI
    //         0046c421     MOV        EDI,dword ptr [EBP + yDeltaDown]
    //         0046c424     ADD        EDI,EBX
    //                              pathsys.cpp:1490 (12)
    //         0046c426     MOV        EBX,dword ptr [EBP + bestPathPoint.x]
    //         0046c429     MOV        dword ptr [EBP + param_14],EDI
    //         0046c42c     MOV        EDI,dword ptr [EBP + param_7]
    //         0046c42f     LEA        EDI,[EDI + EBX*0x4]
    //                              pathsys.cpp:1491 (9)
    //         0046c432     MOV        EBX,dword ptr [EBP + bestPathPoint.y]
    //         0046c435     MOV        dword ptr [EBP + param_1],EDI
    //         0046c438     MOV        EDI,dword ptr [EBP + param_11]
    //                              pathsys.cpp:1495 (5)
    //         0046c43b     JMP        LAB_0046c503
    //                               switchD_0046c328::caseD_5                                    XREF[2]:     0046c328(j), 0046d238(*)  
    //                              pathsys.cpp:1505 (3)
    //         0046c440     MOV        this,dword ptr [EBP + xDeltaLeft]
    //                              pathsys.cpp:1506 (3)
    //         0046c443     MOV        EAX,dword ptr [EBP + yDeltaUp]
    //                              pathsys.cpp:1508 (21)
    //         0046c446     MOV        EBX,dword ptr [EBP + temp.y]
    //         0046c449     LEA        EDX,[this->_padding_ + EDI*0x1]
    //         0046c44c     MOV        this,dword ptr [EBP + bestPathPoint.y]
    //         0046c44f     ADD        EAX,this
    //         0046c451     MOV        this,dword ptr [EBP + xDeltaRight]
    //         0046c454     ADD        this,EDI
    //         0046c456     MOV        EDI,dword ptr [EBP + yDeltaDown]
    //         0046c459     ADD        EDI,EBX
    //                              pathsys.cpp:1510 (9)
    //         0046c45b     MOV        EBX,dword ptr [EBP + bestPathPoint.x]
    //         0046c45e     MOV        dword ptr [EBP + param_14],EDI
    //         0046c461     MOV        EDI,dword ptr [EBP + param_7]
    //                              pathsys.cpp:1515 (2)
    //         0046c464     JMP        LAB_0046c489
    //                               switchD_0046c328::caseD_6                                    XREF[2]:     0046c328(j), 0046d23c(*)  
    //                              pathsys.cpp:1525 (3)
    //         0046c466     MOV        EDX,dword ptr [EBP + xDeltaLeft]
    //                              pathsys.cpp:1526 (3)
    //         0046c469     MOV        EAX,dword ptr [EBP + yDeltaUp]
    //                              pathsys.cpp:1528 (20)
    //         0046c46c     MOV        EBX,dword ptr [EBP + temp.y]
    //         0046c46f     ADD        EDX,this
    //         0046c471     MOV        this,dword ptr [EBP + bestPathPoint.y]
    //         0046c474     ADD        EAX,this
    //         0046c476     MOV        this,dword ptr [EBP + xDeltaRight]
    //         0046c479     ADD        this,EDI
    //         0046c47b     MOV        EDI,dword ptr [EBP + yDeltaDown]
    //         0046c47e     ADD        EDI,EBX
    //                              pathsys.cpp:1530 (12)
    //         0046c480     MOV        EBX,dword ptr [EBP + temp.x]
    //         0046c483     MOV        dword ptr [EBP + param_14],EDI
    //         0046c486     MOV        EDI,dword ptr [EBP + param_7]
    //                               LAB_0046c489                                                 XREF[1]:     0046c464(j)  
    //         0046c489     LEA        EDI,[EDI + EBX*0x4]
    //                              pathsys.cpp:1531 (12)
    //         0046c48c     MOV        EBX,dword ptr [EBP + bestPathPoint.y]
    //         0046c48f     MOV        dword ptr [EBP + param_1],EDI
    //         0046c492     MOV        EDI,dword ptr [EBP + param_11]
    //         0046c495     LEA        EDI,[EDI + EBX*0x4]
    //                              pathsys.cpp:1532 (9)
    //         0046c498     MOV        EBX,dword ptr [EBP + bestPathPoint.x]
    //         0046c49b     MOV        dword ptr [EBP + param_6],EDI
    //         0046c49e     MOV        EDI,dword ptr [EBP + xDeltaRight4]
    //                              pathsys.cpp:1535 (2)
    //         0046c4a1     JMP        LAB_0046c50f
    //                               switchD_0046c328::caseD_7                                    XREF[2]:     0046c328(j), 0046d240(*)  
    //                              pathsys.cpp:1545 (3)
    //         0046c4a3     MOV        EDX,dword ptr [EBP + xDeltaLeft]
    //                              pathsys.cpp:1546 (3)
    //         0046c4a6     MOV        EAX,dword ptr [EBP + yDeltaUp]
    //                              pathsys.cpp:1548 (20)
    //         0046c4a9     MOV        EBX,dword ptr [EBP + bestPathPoint.y]
    //         0046c4ac     ADD        EDX,this
    //         0046c4ae     MOV        this,dword ptr [EBP + bestPathPoint.y]
    //         0046c4b1     ADD        EAX,this
    //         0046c4b3     MOV        this,dword ptr [EBP + xDeltaRight]
    //         0046c4b6     ADD        this,EDI
    //         0046c4b8     MOV        EDI,dword ptr [EBP + yDeltaDown]
    //         0046c4bb     ADD        EDI,EBX
    //                              pathsys.cpp:1550 (12)
    //         0046c4bd     MOV        EBX,dword ptr [EBP + temp.x]
    //         0046c4c0     MOV        dword ptr [EBP + param_14],EDI
    //         0046c4c3     MOV        EDI,dword ptr [EBP + param_7]
    //         0046c4c6     LEA        EDI,[EDI + EBX*0x4]
    //                              pathsys.cpp:1551 (12)
    //         0046c4c9     MOV        EBX,dword ptr [EBP + bestPathPoint.y]
    //         0046c4cc     MOV        dword ptr [EBP + param_1],EDI
    //         0046c4cf     MOV        EDI,dword ptr [EBP + param_11]
    //                               LAB_0046c4d2                                                 XREF[2]:     0046c35b(j), 0046c38c(j)  
    //         0046c4d2     LEA        EDI,[EDI + EBX*0x4]
    //                              pathsys.cpp:1552 (12)
    //         0046c4d5     MOV        EBX,dword ptr [EBP + bestPathPoint.x]
    //         0046c4d8     MOV        dword ptr [EBP + param_6],EDI
    //         0046c4db     MOV        EDI,dword ptr [EBP + xDeltaRight4]
    //         0046c4de     LEA        EDI,[EDI + EBX*0x4]
    //                              pathsys.cpp:1553 (9)
    //         0046c4e1     MOV        EBX,dword ptr [EBP + bestPathPoint.y]
    //         0046c4e4     MOV        dword ptr [EBP + param_2],EDI
    //         0046c4e7     MOV        EDI,dword ptr [EBP + yDeltaDown4]
    //                              pathsys.cpp:1555 (2)
    //         0046c4ea     JMP        LAB_0046c51b
    //                               switchD_0046c328::default                                    XREF[1]:     0046c322(j)  
    //                              pathsys.cpp:1567 (14)
    //         0046c4ec     MOV        EDI,dword ptr [EBP + temp.x]
    //         0046c4ef     MOV        EBX,dword ptr [EBP + param_7]
    //         0046c4f2     MOV        EDX,this
    //         0046c4f4     MOV        dword ptr [EBP + param_14],EAX
    //         0046c4f7     LEA        EDI,[EBX + EDI*0x4]
    //                              pathsys.cpp:1568 (12)
    //         0046c4fa     MOV        EBX,dword ptr [EBP + temp.y]
    //         0046c4fd     MOV        dword ptr [EBP + param_1],EDI
    //         0046c500     MOV        EDI,dword ptr [EBP + param_11]
    //                               LAB_0046c503                                                 XREF[1]:     0046c43b(j)  
    //         0046c503     LEA        EDI,[EDI + EBX*0x4]
    //                              pathsys.cpp:1569 (12)
    //         0046c506     MOV        EBX,dword ptr [EBP + temp.x]
    //         0046c509     MOV        dword ptr [EBP + param_6],EDI
    //         0046c50c     MOV        EDI,dword ptr [EBP + xDeltaRight4]
    //                               LAB_0046c50f                                                 XREF[1]:     0046c4a1(j)  
    //         0046c50f     LEA        EDI,[EDI + EBX*0x4]
    //                              pathsys.cpp:1570 (12)
    //         0046c512     MOV        EBX,dword ptr [EBP + temp.y]
    //         0046c515     MOV        dword ptr [EBP + param_2],EDI
    //         0046c518     MOV        EDI,dword ptr [EBP + yDeltaDown4]
    //                               LAB_0046c51b                                                 XREF[2]:     0046c407(j), 0046c4ea(j)  
    //         0046c51b     LEA        EDI,[EDI + EBX*0x4]
    //                              pathsys.cpp:1585 (8)
    //         0046c51e     TEST       EDX,EDX
    //         0046c520     MOV        dword ptr [EBP + param_15],EDI
    //         0046c523     JGE        LAB_0046c526
    //         0046c525     INC        EDX
    //                               LAB_0046c526                                                 XREF[1]:     0046c523(j)  
    //                              pathsys.cpp:1586 (5)
    //         0046c526     TEST       EAX,EAX
    //         0046c528     JGE        LAB_0046c52b
    //         0046c52a     INC        EAX
    //                               LAB_0046c52b                                                 XREF[1]:     0046c528(j)  
    //                              pathsys.cpp:1587 (11)
    //         0046c52b     MOV        EDI,dword ptr [EBP + param_1]
    //         0046c52e     TEST       EDI,EDI
    //         0046c530     JGE        LAB_0046c536
    //         0046c532     INC        EDI
    //         0046c533     MOV        dword ptr [EBP + param_1],EDI
    //                               LAB_0046c536                                                 XREF[1]:     0046c530(j)  
    //                              pathsys.cpp:1588 (11)
    //         0046c536     MOV        EDI,dword ptr [EBP + param_6]
    //         0046c539     TEST       EDI,EDI
    //         0046c53b     JGE        LAB_0046c541
    //         0046c53d     INC        EDI
    //         0046c53e     MOV        dword ptr [EBP + param_6],EDI
    //                               LAB_0046c541                                                 XREF[1]:     0046c53b(j)  
    //                              pathsys.cpp:1590 (320)
    //         0046c541     MOV        EDI,dword ptr [ESI + 0x11dc3c]
    //         0046c547     MOV        EBX,this
    //         0046c549     AND        EBX,0xff
    //         0046c54f     CMP        EBX,dword ptr [EDI + 0x8]
    //         0046c552     JGE        LAB_0046c674
    //         0046c558     MOV        EBX,dword ptr [EBP + param_14]
    //         0046c55b     AND        EBX,0xff
    //         0046c561     CMP        EBX,dword ptr [EDI + 0xc]
    //         0046c564     JGE        LAB_0046c674
    //         0046c56a     MOV        BL,byte ptr [EBP + param_14]
    //         0046c56d     MOV        byte ptr [EBP + local_34],AL
    //         0046c570     CMP        AL,BL
    //         0046c572     JA         LAB_0046c66e
    //         0046c578     MOV        EAX,dword ptr [EDI + 0x8d8c]
    //         0046c57e     MOV        dword ptr [EBP + local_5c],EAX
    //         0046c581     MOV        EAX,EDX
    //         0046c583     AND        EAX,0xff
    //         0046c588     LEA        EAX,[EAX + EAX*0x2]
    //         0046c58b     SHL        EAX,0x3
    //         0046c58e     MOV        dword ptr [EBP + local_60],EAX
    //                               LAB_0046c591                                                 XREF[1]:     0046c668(j)  
    //         0046c591     MOV        EAX,dword ptr [EBP + local_34]
    //         0046c594     MOV        EDI,dword ptr [EBP + local_5c]
    //         0046c597     MOV        EBX,dword ptr [EBP + local_60]
    //         0046c59a     AND        EAX,0xff
    //         0046c59f     MOV        dword ptr [EBP + local_64],EAX
    //         0046c5a2     MOV        byte ptr [EBP + local_30],DL
    //         0046c5a5     MOV        EDI,dword ptr [EDI + EAX*0x4]
    //         0046c5a8     ADD        EDI,EBX
    //         0046c5aa     CMP        DL,this
    //         0046c5ac     JA         LAB_0046c65b
    //         0046c5b2     LEA        EBX,[EDI + 0x6]
    //         0046c5b5     MOV        dword ptr [EBP + local_44],EBX
    //         0046c5b8     JMP        LAB_0046c5bd
    //                               LAB_0046c5ba                                                 XREF[1]:     0046c655(j)  
    //         0046c5ba     MOV        EAX,dword ptr [EBP + local_64]
    //                               LAB_0046c5bd                                                 XREF[1]:     0046c5b8(j)  
    //         0046c5bd     MOV        EDI,dword ptr [EBP + local_30]
    //         0046c5c0     AND        EDI,0xff
    //         0046c5c6     CMP        dword ptr [ESI + 0x11dc7c],EDI
    //         0046c5cc     JNZ        LAB_0046c5d6
    //         0046c5ce     CMP        dword ptr [ESI + 0x11dc80],EAX
    //         0046c5d4     JZ         LAB_0046c645
    //                               LAB_0046c5d6                                                 XREF[1]:     0046c5cc(j)  
    //         0046c5d6     MOV        AL,byte ptr [EBX + -0x1]
    //         0046c5d9     MOV        EDI,dword ptr [ESI + 0x11dc50]
    //         0046c5df     AND        AL,0x1f
    //         0046c5e1     MOV        byte ptr [EBP + local_68],AL
    //         0046c5e4     MOV        EAX,dword ptr [EBP + local_68]
    //         0046c5e7     AND        EAX,0xff
    //         0046c5ec     CMP        EAX,dword ptr [ESI + 0x11dc5c]
    //         0046c5f2     FLD        float ptr [EDI + EAX*0x4]
    //         0046c5f5     JZ         LAB_0046d1fb
    //         0046c5fb     CMP        EAX,dword ptr [ESI + 0x11dc60]
    //         0046c601     JZ         LAB_0046d1fb
    //         0046c607     FCOMP      double ptr [DAT_00570e80]
    //         0046c60d     FNSTSW     AX
    //         0046c60f     TEST       AH,0x41
    //         0046c612     JZ         LAB_0046c645
    //         0046c614     MOV        AL,byte ptr [EBX]
    //         0046c616     AND        EAX,0xf
    //         0046c619     JZ         LAB_0046c674
    //         0046c61b     LEA        EAX,[EAX + EAX*0x4]
    //         0046c61e     LEA        EBX,[EAX + EAX*0x8]
    //         0046c621     MOV        EAX,dword ptr [ESI + 0x11dc3c]
    //         0046c627     SHL        EBX,0x5
    //         0046c62a     MOVSX      EAX,word ptr [EBX + EAX*0x1 + 0x3928]
    //         0046c632     FLD        float ptr [EDI + EAX*0x4]
    //         0046c635     FCOMP      double ptr [DAT_00570e80]
    //         0046c63b     FNSTSW     AX
    //         0046c63d     TEST       AH,0x41
    //         0046c640     JNZ        LAB_0046c674
    //         0046c642     MOV        EBX,dword ptr [EBP + local_44]
    //                               LAB_0046c645                                                 XREF[3]:     0046c5d4(j), 0046c612(j), 
    //                                                                                                         0046d1fd(j)  
    //         0046c645     MOV        AL,byte ptr [EBP + local_30]
    //         0046c648     ADD        EBX,0x18
    //         0046c64b     INC        AL
    //         0046c64d     MOV        dword ptr [EBP + local_44],EBX
    //         0046c650     CMP        AL,this
    //         0046c652     MOV        byte ptr [EBP + local_30],AL
    //         0046c655     JBE        LAB_0046c5ba
    //                               LAB_0046c65b                                                 XREF[1]:     0046c5ac(j)  
    //         0046c65b     MOV        AL,byte ptr [EBP + local_34]
    //         0046c65e     MOV        BL,byte ptr [EBP + param_14]
    //         0046c661     INC        AL
    //         0046c663     CMP        AL,BL
    //         0046c665     MOV        byte ptr [EBP + local_34],AL
    //         0046c668     JBE        LAB_0046c591
    //                               LAB_0046c66e                                                 XREF[1]:     0046c572(j)  
    //         0046c66e     MOV        byte ptr [EBP + local_24],0x1
    //         0046c672     JMP        LAB_0046c678
    //                               LAB_0046c674                                                 XREF[4]:     0046c552(j), 0046c564(j), 
    //                                                                                                         0046c619(j), 0046c640(j)  
    //         0046c674     MOV        byte ptr [EBP + local_24],0xfe
    //                               LAB_0046c678                                                 XREF[1]:     0046c672(j)  
    //         0046c678     MOV        EDX,dword ptr [EBP + local_24]
    //         0046c67b     AND        EDX,0xff
    //                              pathsys.cpp:1606 (21)
    //         0046c681     CMP        EDX,0x1
    //         0046c684     MOV        dword ptr [EBP + param_14],EDX
    //         0046c687     JNZ        LAB_0046c83b
    //         0046c68d     CMP        dword ptr [EBP + param_12],EDX
    //         0046c690     JNZ        LAB_0046c83b
    //                              pathsys.cpp:1608 (122)
    //         0046c696     MOV        EDX,dword ptr [EBP + param_15]
    //         0046c699     MOV        EBX,dword ptr [EBP + param_6]
    //         0046c69c     MOV        EAX,EDX
    //         0046c69e     MOV        dword ptr [EBP + param_14],0x0
    //         0046c6a5     SUB        EAX,EBX
    //         0046c6a7     DEC        EAX
    //         0046c6a8     JNS        LAB_0046c6b4
    //         0046c6aa     MOV        EDX,0x1
    //         0046c6af     JMP        LAB_0046c838
    //                               LAB_0046c6b4                                                 XREF[1]:     0046c6a8(j)  
    //         0046c6b4     MOV        this,dword ptr [EBP + param_1]
    //         0046c6b7     CMP        EAX,0x18
    //         0046c6ba     JGE        LAB_0046c795
    //         0046c6c0     CMP        this,dword ptr [ESI + 0x11dc8c]
    //         0046c6c6     JG         LAB_0046c6e7
    //         0046c6c8     CMP        EBX,dword ptr [ESI + 0x11dc90]
    //         0046c6ce     JG         LAB_0046c6e7
    //         0046c6d0     MOV        EDI,dword ptr [EBP + param_2]
    //         0046c6d3     CMP        EDI,dword ptr [ESI + 0x11dc84]
    //         0046c6d9     JL         LAB_0046c6e7
    //         0046c6db     CMP        EDX,dword ptr [ESI + 0x11dc88]
    //         0046c6e1     JGE        LAB_0046c795
    //                               LAB_0046c6e7                                                 XREF[3]:     0046c6c6(j), 0046c6ce(j), 
    //                                                                                                         0046c6d9(j)  
    //         0046c6e7     MOV        EDX,EBX
    //         0046c6e9     AND        EDX,0x3
    //         0046c6ec     SAR        EBX,0x2
    //         0046c6ef     LEA        EAX,[EDX + EAX*0x4]
    //         0046c6f2     MOV        EDI,EBX
    //         0046c6f4     SHL        EAX,0x1
    //         0046c6f6     MOV        EDX,dword ptr [EAX*0x4 + ObstructionMasks]       = 00000003
    //         0046c6fd     MOV        EAX,dword ptr [EAX*0x4 + DAT_00584f24]           = align(4)
    //         0046c704     TEST       EAX,EAX
    //         0046c706     MOV        dword ptr [EBP + param_1],EDX
    //         0046c709     JNZ        LAB_0046c744
    //         0046c70b     CMP        this,dword ptr [EBP + param_2]
    //         0046c70e     JGE        LAB_0046c735
    //                              pathsys.cpp:1896 (37)
    //         0046c710     MOV        EAX,this
    //         0046c712     SHL        EAX,0x8
    //         0046c715     SUB        EAX,this
    //         0046c717     ADD        EAX,EDI
    //         0046c719     MOV        EDI,dword ptr [EBP + param_2]
    //         0046c71c     LEA        EAX,[EAX + ESI*0x1 + 0xce624]
    //                               LAB_0046c723                                                 XREF[1]:     0046c733(j)  
    //         0046c723     TEST       dword ptr [EAX],EDX
    //         0046c725     JNZ        LAB_0046c826
    //         0046c72b     INC        this
    //         0046c72c     ADD        EAX,0xff
    //         0046c731     CMP        this,EDI
    //         0046c733     JL         LAB_0046c723
    //                               LAB_0046c735                                                 XREF[2]:     0046c70e(j), 0046c74b(j)  
    //                              pathsys.cpp:1608 (24)
    //         0046c735     MOV        dword ptr [EBP + param_14],0x1
    //         0046c73c     MOV        EDX,dword ptr [EBP + param_14]
    //         0046c73f     JMP        LAB_0046c83b
    //                               LAB_0046c744                                                 XREF[1]:     0046c709(j)  
    //         0046c744     MOV        EBX,dword ptr [EBP + param_2]
    //         0046c747     MOV        EDX,this
    //         0046c749     CMP        this,EBX
    //         0046c74b     JGE        LAB_0046c735
    //                              pathsys.cpp:1896 (22)
    //         0046c74d     MOV        EBX,this
    //         0046c74f     SHL        EBX,0x8
    //         0046c752     SUB        EBX,this
    //         0046c754     ADD        EBX,EDI
    //         0046c756     MOV        EDI,dword ptr [EBP + param_2]
    //         0046c759     LEA        this,[EBX + ESI*0x1 + 0xce624]
    //         0046c760     MOV        EBX,dword ptr [EBP + param_1]
    //                               LAB_0046c763                                                 XREF[1]:     0046c775(j)  
    //                              pathsys.cpp:1608 (216)
    //         0046c763     TEST       dword ptr [this->_padding_],EBX
    //         0046c765     JNZ        LAB_0046c786
    //         0046c767     TEST       dword ptr [ECX + this->xSizeValue],EAX
    //         0046c76a     JNZ        LAB_0046c786
    //         0046c76c     INC        EDX
    //         0046c76d     ADD        this,0xff
    //         0046c773     CMP        EDX,EDI
    //         0046c775     JL         LAB_0046c763
    //         0046c777     MOV        dword ptr [EBP + param_14],0x1
    //         0046c77e     MOV        EDX,dword ptr [EBP + param_14]
    //         0046c781     JMP        LAB_0046c83b
    //                               LAB_0046c786                                                 XREF[2]:     0046c765(j), 0046c76a(j)  
    //         0046c786     MOV        dword ptr [EBP + param_14],0xfe
    //         0046c78d     MOV        EDX,dword ptr [EBP + param_14]
    //         0046c790     JMP        LAB_0046c83b
    //                               LAB_0046c795                                                 XREF[2]:     0046c6ba(j), 0046c6e1(j)  
    //         0046c795     MOV        EAX,dword ptr [EBP + param_2]
    //         0046c798     MOV        EDI,this
    //         0046c79a     CMP        this,EAX
    //         0046c79c     JGE        LAB_0046c82d
    //         0046c7a2     MOV        EAX,this
    //         0046c7a4     SHL        EAX,0x8
    //         0046c7a7     SUB        EAX,this
    //         0046c7a9     MOV        dword ptr [EBP + param_1],EAX
    //                               LAB_0046c7ac                                                 XREF[1]:     0046c822(j)  
    //         0046c7ac     CMP        EBX,EDX
    //         0046c7ae     MOV        EAX,EBX
    //         0046c7b0     JGE        LAB_0046c810
    //                               LAB_0046c7b2                                                 XREF[1]:     0046c80b(j)  
    //         0046c7b2     MOV        EBX,dword ptr [EBP + param_1]
    //         0046c7b5     MOV        this,EAX
    //         0046c7b7     SAR        this,0x2
    //         0046c7ba     MOV        EDX,EAX
    //         0046c7bc     ADD        this,ESI
    //         0046c7be     AND        EDX,0x3
    //         0046c7c1     MOV        BL,byte ptr [ECX + EBX*0x1 + this->obstruction
    //         0046c7c8     MOV        this,byte ptr [EDX + ObstructionValueShift]      = 06040200
    //         0046c7ce     SHR        BL,this
    //         0046c7d0     TEST       BL,0x3
    //         0046c7d3     JBE        LAB_0046c805
    //         0046c7d5     CMP        dword ptr [ESI + 0x11dc4c],-0x1
    //         0046c7dc     JZ         LAB_0046c826
    //         0046c7de     CMP        dword ptr [ESI + 0x11dc84],EDI
    //         0046c7e4     JG         LAB_0046c826
    //         0046c7e6     CMP        EDI,dword ptr [ESI + 0x11dc8c]
    //         0046c7ec     JG         LAB_0046c826
    //         0046c7ee     CMP        dword ptr [ESI + 0x11dc88],EAX
    //         0046c7f4     JG         LAB_0046c826
    //         0046c7f6     CMP        EAX,dword ptr [ESI + 0x11dc90]
    //         0046c7fc     JG         LAB_0046c826
    //         0046c7fe     MOV        dword ptr [EBP + param_14],0x1
    //                               LAB_0046c805                                                 XREF[1]:     0046c7d3(j)  
    //         0046c805     MOV        EDX,dword ptr [EBP + param_15]
    //         0046c808     INC        EAX
    //         0046c809     CMP        EAX,EDX
    //         0046c80b     JL         LAB_0046c7b2
    //         0046c80d     MOV        EBX,dword ptr [EBP + param_6]
    //                               LAB_0046c810                                                 XREF[1]:     0046c7b0(j)  
    //         0046c810     MOV        this,dword ptr [EBP + param_1]
    //         0046c813     MOV        EAX,dword ptr [EBP + param_2]
    //         0046c816     INC        EDI
    //         0046c817     ADD        this,0xff
    //         0046c81d     CMP        EDI,EAX
    //         0046c81f     MOV        dword ptr [EBP + param_1],this
    //         0046c822     JL         LAB_0046c7ac
    //         0046c824     JMP        LAB_0046c82d
    //                               LAB_0046c826                                                 XREF[6]:     0046c725(j), 0046c7dc(j), 
    //                                                                                                         0046c7e4(j), 0046c7ec(j), 
    //                                                                                                         0046c7f4(j), 0046c7fc(j)  
    //         0046c826     MOV        EDX,0xfe
    //         0046c82b     JMP        LAB_0046c838
    //                               LAB_0046c82d                                                 XREF[2]:     0046c79c(j), 0046c824(j)  
    //         0046c82d     MOV        EAX,dword ptr [EBP + param_14]
    //         0046c830     XOR        EDX,EDX
    //         0046c832     CMP        EAX,0x1
    //         0046c835     SETNZ      DL
    //                               LAB_0046c838                                                 XREF[2]:     0046c6af(j), 0046c82b(j)  
    //         0046c838     MOV        dword ptr [EBP + param_14],EDX
    //                               LAB_0046c83b                                                 XREF[5]:     0046c687(j), 0046c690(j), 
    //                                                                                                         0046c73f(j), 0046c781(j), 
    //                                                                                                         0046c790(j)  
    //                              pathsys.cpp:1629 (26)
    //         0046c83b     CMP        EDX,0xfe
    //         0046c841     MOV        dword ptr [EBP + param_6],0x0
    //         0046c848     MOV        dword ptr [EBP + unobstructibleObjectHitpoints
    //         0046c84f     JNZ        LAB_0046c929
    //                              pathsys.cpp:1632 (13)
    //         0046c855     CMP        dword ptr [ESI + 0x11dcdc],-0x1
    //         0046c85c     JZ         LAB_0046ca8b
    //                              pathsys.cpp:1644 (6)
    //         0046c862     MOV        EAX,dword ptr [EBP + temp.x]
    //         0046c865     LEA        EBX,[EAX + -0x1]
    //                              pathsys.cpp:1645 (4)
    //         0046c868     TEST       EBX,EBX
    //         0046c86a     JGE        LAB_0046c86e
    //                              pathsys.cpp:1646 (2)
    //         0046c86c     XOR        EBX,EBX
    //                               LAB_0046c86e                                                 XREF[1]:     0046c86a(j)  
    //                              pathsys.cpp:1647 (2)
    //         0046c86e     XOR        this,this
    //                              pathsys.cpp:1648 (32)
    //         0046c870     INC        EAX
    //         0046c871     CMP        EBX,EAX
    //         0046c873     MOV        dword ptr [EBP + param_2],this
    //         0046c876     MOV        dword ptr [EBP + local_64],EAX
    //         0046c879     JG         LAB_0046c91d
    //                               LAB_0046c87f                                                 XREF[1]:     0046c917(j)  
    //         0046c87f     CMP        EBX,dword ptr [ESI + 0x4]
    //         0046c882     JGE        LAB_0046c91d
    //         0046c888     TEST       this,this
    //         0046c88a     JNZ        LAB_0046c91d
    //                              pathsys.cpp:1650 (6)
    //         0046c890     MOV        EAX,dword ptr [EBP + temp.y]
    //         0046c893     LEA        EDI,[EAX + -0x1]
    //                              pathsys.cpp:1651 (4)
    //         0046c896     TEST       EDI,EDI
    //         0046c898     JGE        LAB_0046c89c
    //                              pathsys.cpp:1652 (2)
    //         0046c89a     XOR        EDI,EDI
    //                               LAB_0046c89c                                                 XREF[1]:     0046c898(j)  
    //                              pathsys.cpp:1653 (17)
    //         0046c89c     INC        EAX
    //         0046c89d     CMP        EDI,EAX
    //         0046c89f     MOV        dword ptr [EBP + param_15],EAX
    //         0046c8a2     JG         LAB_0046c911
    //                               LAB_0046c8a4                                                 XREF[1]:     0046c90f(j)  
    //         0046c8a4     CMP        EDI,dword ptr [ESI + 0x8]
    //         0046c8a7     JGE        LAB_0046c911
    //         0046c8a9     TEST       this,this
    //         0046c8ab     JNZ        LAB_0046c911
    //                              pathsys.cpp:1656 (34)
    //         0046c8ad     MOV        EDX,dword ptr [ESI + 0x11dce0]
    //         0046c8b3     LEA        EAX=>param_1,[EBP + 0x8]
    //         0046c8b6     MOV        dword ptr [EBP + param_1],this
    //         0046c8b9     MOV        this,dword ptr [ESI + 0x11dcdc]
    //         0046c8bf     PUSH       EAX
    //         0046c8c0     PUSH       EDI=>DAT_fffffff8
    //         0046c8c1     PUSH       EBX=>DAT_fffffff4
    //         0046c8c2     PUSH       this=>DAT_fffffff0
    //         0046c8c3     MOV        this,dword ptr [ESI + 0x11dc40]
    //         0046c8c9     PUSH       EDX
    //         0046c8ca     CALL       RGE_Game_World::objectGroupOnTile                int objectGroupOnTile(RGE_Game_World * this, 
    //                              pathsys.cpp:1657 (12)
    //         0046c8cf     CMP        EAX,-0x1
    //         0046c8d2     JNZ        LAB_0046c8e9
    //         0046c8d4     MOV        this,dword ptr [EBP + param_1]
    //         0046c8d7     TEST       this,this
    //         0046c8d9     JLE        LAB_0046c8e4
    //                              pathsys.cpp:1662 (7)
    //         0046c8db     MOV        dword ptr [EBP + param_2],0x1
    //                              pathsys.cpp:1664 (7)
    //         0046c8e2     JMP        LAB_0046c906
    //                               LAB_0046c8e4                                                 XREF[1]:     0046c8d9(j)  
    //         0046c8e4     CMP        EAX,-0x1
    //         0046c8e7     JZ         LAB_0046c906
    //                               LAB_0046c8e9                                                 XREF[1]:     0046c8d2(j)  
    //                              pathsys.cpp:1666 (12)
    //         0046c8e9     MOV        this,dword ptr [ESI + 0x11dc40]
    //         0046c8ef     PUSH       EAX
    //         0046c8f0     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              pathsys.cpp:1667 (4)
    //         0046c8f5     TEST       EAX,EAX
    //         0046c8f7     JZ         LAB_0046c906
    //                              pathsys.cpp:1670 (24)
    //         0046c8f9     MOV        EAX,dword ptr [EAX + 0x30]
    //         0046c8fc     MOV        dword ptr [EBP + param_6],0x1
    //         0046c903     MOV        dword ptr [EBP + unobstructibleObjectHitpoints
    //                               LAB_0046c906                                                 XREF[3]:     0046c8e2(j), 0046c8e7(j), 
    //                                                                                                         0046c8f7(j)  
    //         0046c906     MOV        EAX,dword ptr [EBP + param_15]
    //         0046c909     MOV        this,dword ptr [EBP + param_2]
    //         0046c90c     INC        EDI
    //         0046c90d     CMP        EDI,EAX
    //         0046c90f     JLE        LAB_0046c8a4
    //                               LAB_0046c911                                                 XREF[3]:     0046c8a2(j), 0046c8a7(j), 
    //                                                                                                         0046c8ab(j)  
    //                              pathsys.cpp:1648 (12)
    //         0046c911     MOV        EAX,dword ptr [EBP + local_64]
    //         0046c914     INC        EBX
    //         0046c915     CMP        EBX,EAX
    //         0046c917     JLE        LAB_0046c87f
    //                               LAB_0046c91d                                                 XREF[3]:     0046c879(j), 0046c882(j), 
    //                                                                                                         0046c88a(j)  
    //                              pathsys.cpp:1675 (12)
    //         0046c91d     CMP        this,0x1
    //         0046c920     JZ         LAB_0046ca8b
    //         0046c926     MOV        EDX,dword ptr [EBP + param_14]
    //                               LAB_0046c929                                                 XREF[1]:     0046c84f(j)  
    //                              pathsys.cpp:1687 (22)
    //         0046c929     MOV        EDI,dword ptr [EBP + local_48]
    //         0046c92c     XOR        this,this
    //         0046c92e     MOV        this,byte ptr [ESI + EDI*0x1 + 0x10de28]
    //         0046c935     MOV        EAX,this
    //         0046c937     MOV        this,dword ptr [EBP + newTotal]
    //         0046c93a     SHL        EAX,0x4
    //         0046c93d     ADD        this,EAX
    //                              pathsys.cpp:1692 (8)
    //         0046c93f     MOV        EAX,dword ptr [EBP + param_6]
    //         0046c942     CMP        EAX,0x1
    //         0046c945     JNZ        LAB_0046c95f
    //                              pathsys.cpp:1697 (16)
    //         0046c947     FLD        float ptr [EBP + unobstructibleObjectHitpoints]
    //         0046c94a     FCOMP      float ptr [DAT_00570e88]
    //         0046c950     FNSTSW     AX
    //         0046c952     TEST       AH,0x1
    //         0046c955     JNZ        LAB_0046c95c
    //                              pathsys.cpp:1698 (3)
    //         0046c957     ADD        this,0x3c
    //                              pathsys.cpp:1699 (2)
    //         0046c95a     JMP        LAB_0046c95f
    //                               LAB_0046c95c                                                 XREF[1]:     0046c955(j)  
    //                              pathsys.cpp:1700 (3)
    //         0046c95c     ADD        this,0x10
    //                               LAB_0046c95f                                                 XREF[2]:     0046c945(j), 0046c95a(j)  
    //                              pathsys.cpp:1711 (47)
    //         0046c95f     MOV        EAX,dword ptr [EBP + local_38]
    //         0046c962     MOV        AL,byte ptr [ESI + EAX*0x1 + 0xc]
    //         0046c966     MOV        BL,AL
    //         0046c968     AND        BL,0xf8
    //         0046c96b     CMP        BL,byte ptr [ESI + 0x11dcd8]
    //         0046c971     JNZ        LAB_0046c97a
    //         0046c973     AND        AL,0x7
    //         0046c975     MOV        byte ptr [EBP + local_50],AL
    //         0046c978     JMP        LAB_0046c97e
    //                               LAB_0046c97a                                                 XREF[1]:     0046c971(j)  
    //         0046c97a     MOV        byte ptr [EBP + local_50],0xff
    //                               LAB_0046c97e                                                 XREF[1]:     0046c978(j)  
    //         0046c97e     MOV        EBX,dword ptr [EBP + local_50]
    //         0046c981     MOV        EAX,dword ptr [EBP + i]
    //         0046c984     AND        EBX,0xff
    //         0046c98a     CMP        EAX,EBX
    //         0046c98c     JZ         LAB_0046c98f
    //                              pathsys.cpp:1712 (1)
    //         0046c98e     INC        this
    //                               LAB_0046c98f                                                 XREF[1]:     0046c98c(j)  
    //                              pathsys.cpp:1716 (4)
    //         0046c98f     TEST       EDX,EDX
    //         0046c991     JNZ        LAB_0046c995
    //                              pathsys.cpp:1721 (2)
    //         0046c993     XOR        this,this
    //                               LAB_0046c995                                                 XREF[1]:     0046c991(j)  
    //                              pathsys.cpp:1735 (22)
    //         0046c995     MOV        EDX,dword ptr [EBP + local_70]
    //         0046c998     MOV        dword ptr [ESI + EDI*0x4 + 0xfe10],this
    //         0046c99f     MOV        BL,byte ptr [ESI + 0x11dcd8]
    //         0046c9a5     AND        AL,0x7
    //         0046c9a7     OR         AL,BL
    //         0046c9a9     MOV        byte ptr [EDX],AL
    //                              pathsys.cpp:1743 (15)
    //         0046c9ab     MOV        EDX,dword ptr [ESI + 0x11dc2c]
    //         0046c9b1     INC        EDX
    //         0046c9b2     MOV        dword ptr [ESI + 0x11dc2c],EDX
    //         0046c9b8     MOV        EAX,EDX
    //                              pathsys.cpp:1744 (10)
    //         0046c9ba     MOV        DL,byte ptr [EBP + temp.x]
    //         0046c9bd     MOV        byte ptr [ESI + EAX*0x8 + 0x4f614],DL
    //                              pathsys.cpp:1745 (16)
    //         0046c9c4     MOV        EAX,dword ptr [ESI + 0x11dc2c]
    //         0046c9ca     MOV        DL,byte ptr [EBP + temp.y]
    //         0046c9cd     MOV        byte ptr [ESI + EAX*0x8 + 0x4f615],DL
    //                              pathsys.cpp:1746 (13)
    //         0046c9d4     MOV        EAX,dword ptr [ESI + 0x11dc2c]
    //         0046c9da     MOV        dword ptr [ESI + EAX*0x8 + 0x4f618],this
    //                              pathsys.cpp:1748 (159)
    //         0046c9e1     MOV        EBX,dword ptr [ESI + 0x11dc2c]
    //         0046c9e7     CMP        EBX,0x1
    //         0046c9ea     MOV        EDI,EBX
    //         0046c9ec     JL         LAB_0046ca80
    //         0046c9f2     MOV        EAX,EBX
    //         0046c9f4     CDQ
    //         0046c9f5     SUB        EAX,EDX
    //         0046c9f7     MOV        DL,byte ptr [ESI + EBX*0x8 + 0x4f614]
    //         0046c9fe     MOV        this,EAX
    //         0046ca00     MOV        AL,byte ptr [ESI + EBX*0x8 + 0x4f615]
    //         0046ca07     SAR        this,0x1
    //         0046ca09     MOV        byte ptr [EBP + param_2],DL
    //         0046ca0c     MOV        byte ptr [EBP + param_1],AL
    //         0046ca0f     MOV        EAX,dword ptr [ESI + EBX*0x8 + 0x4f618]
    //         0046ca16     MOV        EDX,dword ptr [ESI + this->_padding_*0x8 + 0x4
    //         0046ca1d     CMP        EAX,EDX
    //         0046ca1f     MOV        dword ptr [EBP + param_6],EAX
    //         0046ca22     JGE        LAB_0046ca5e
    //                               LAB_0046ca24                                                 XREF[1]:     0046ca5c(j)  
    //         0046ca24     MOV        EDX,dword ptr [ESI + this->_padding_*0x8 + 0x4
    //         0046ca2b     MOV        dword ptr [ESI + EDI*0x8 + 0x4f614],EDX
    //         0046ca32     MOV        EAX,dword ptr [ESI + this->_padding_*0x8 + 0x4
    //         0046ca39     MOV        dword ptr [ESI + EDI*0x8 + 0x4f618],EAX
    //         0046ca40     MOV        EAX,EDI
    //         0046ca42     CDQ
    //         0046ca43     SUB        EAX,EDX
    //         0046ca45     SAR        EAX,0x1
    //         0046ca47     MOV        EDI,EAX
    //         0046ca49     MOV        EAX,this
    //         0046ca4b     CDQ
    //         0046ca4c     SUB        EAX,EDX
    //         0046ca4e     MOV        EDX,dword ptr [EBP + param_6]
    //         0046ca51     SAR        EAX,0x1
    //         0046ca53     MOV        this,EAX
    //         0046ca55     CMP        EDX,dword ptr [ESI + this->_padding_*0x8 + 0x4
    //         0046ca5c     JL         LAB_0046ca24
    //                               LAB_0046ca5e                                                 XREF[1]:     0046ca22(j)  
    //         0046ca5e     CMP        EDI,EBX
    //         0046ca60     JZ         LAB_0046ca80
    //         0046ca62     MOV        AL,byte ptr [EBP + param_2]
    //         0046ca65     MOV        this,byte ptr [EBP + param_1]
    //         0046ca68     MOV        EDX,dword ptr [EBP + param_6]
    //         0046ca6b     MOV        byte ptr [ESI + EDI*0x8 + 0x4f614],AL
    //         0046ca72     MOV        byte ptr [ESI + EDI*0x8 + 0x4f615],this
    //         0046ca79     MOV        dword ptr [ESI + EDI*0x8 + 0x4f618],EDX
    //                               LAB_0046ca80                                                 XREF[2]:     0046c9ec(j), 0046ca60(j)  
    //                              pathsys.cpp:1754 (41)
    //         0046ca80     MOV        EAX,dword ptr [EBP + param_14]
    //         0046ca83     TEST       EAX,EAX
    //         0046ca85     JZ         LAB_0046ccc0
    //                               LAB_0046ca8b                                                 XREF[2]:     0046c85c(j), 0046c920(j)  
    //         0046ca8b     MOV        EDI,dword ptr [EBP + bestPathPoint.x]
    //                               LAB_0046ca8e                                                 XREF[1]:     0046c316(j)  
    //         0046ca8e     MOV        this,dword ptr [EBP + i]
    //         0046ca91     MOV        EBX,dword ptr [EBP + temp.x]
    //                               LAB_0046ca94                                                 XREF[6]:     0046c1cb(j), 0046c1d3(j), 
    //                                                                                                         0046c1de(j), 0046c1e7(j), 
    //                                                                                                         0046c1f0(j), 0046c204(j)  
    //         0046ca94     MOV        EDX,dword ptr [EBP + SkipBit]
    //         0046ca97     INC        this
    //         0046ca98     SHL        EDX,0x1
    //         0046ca9a     CMP        this,0x8
    //         0046ca9d     MOV        dword ptr [EBP + i],this
    //         0046caa0     MOV        dword ptr [EBP + SkipBit],EDX
    //         0046caa3     JL         LAB_0046c153
    //                              pathsys.cpp:1826 (36)
    //         0046caa9     MOV        this,dword ptr [EBP + iterations]
    //         0046caac     MOV        EAX,dword ptr [ESI + 0x11dc2c]
    //         0046cab2     INC        this
    //         0046cab3     MOV        dword ptr [ESI + 0x11dc74],0x0
    //         0046cabd     TEST       EAX,EAX
    //         0046cabf     MOV        dword ptr [EBP + iterations],this
    //         0046cac2     JG         LAB_0046bf0e
    //         0046cac8     JMP        LAB_0046cedf
    //                               LAB_0046cacd                                                 XREF[1]:     0046c010(j)  
    //                              pathsys.cpp:1165 (10)
    //         0046cacd     CMP        dword ptr [EBP + param_8],0x1
    //         0046cad1     JNZ        LAB_0046cbd6
    //                              pathsys.cpp:1167 (19)
    //         0046cad7     MOV        EAX,dword ptr [EBP + param_13]
    //         0046cada     MOV        this,ESI
    //         0046cadc     PUSH       EAX
    //         0046cadd     CALL       PathingSystem::copyPath                          int copyPath(PathingSystem * this, int param_1)
    //         0046cae2     TEST       EAX,EAX
    //         0046cae4     JNZ        LAB_0046cbd6
    //                              pathsys.cpp:1173 (11)
    //         0046caea     MOV        EAX,dword ptr [EBP + param_5]
    //         0046caed     MOV        this,byte ptr [EAX + 0x154]
    //         0046caf3     TEST       this,this
    //                              pathsys.cpp:1174 (8)
    //         0046caf5     LEA        this,[EAX + 0xa4]
    //         0046cafb     JZ         LAB_0046cb03
    //                              pathsys.cpp:1176 (11)
    //         0046cafd     LEA        this,[EAX + 0xd8]
    //                               LAB_0046cb03                                                 XREF[1]:     0046cafb(j)  
    //         0046cb03     CALL       Path::killPath                                   void killPath(Path * this)
    //                              pathsys.cpp:1178 (201)
    //         0046cb08     MOV        EDI,dword ptr [ESI + 0x11dc44]
    //         0046cb0e     XOR        EBX,EBX
    //         0046cb10     MOV        dword ptr [EBP + param_13],EBX
    //         0046cb13     MOV        EAX,dword ptr [EDI + 0x58]
    //         0046cb16     TEST       EAX,EAX
    //         0046cb18     JLE        LAB_0046d19f
    //                               LAB_0046cb1e                                                 XREF[1]:     0046cbcb(j)  
    //         0046cb1e     MOV        this,dword ptr [EDI + 0x60]
    //         0046cb21     DEC        this
    //         0046cb22     CMP        EBX,this
    //         0046cb24     JLE        LAB_0046cb7c
    //         0046cb26     LEA        EDX,[EBX*0x4 + 0x4]
    //         0046cb2d     PUSH       EDX
    //         0046cb2e     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0046cb33     ADD        ESP,0x4
    //         0046cb36     MOV        dword ptr [EBP + param_4],EAX
    //         0046cb39     TEST       EAX,EAX
    //         0046cb3b     JZ         LAB_0046cb7c
    //         0046cb3d     MOV        this,dword ptr [EDI + 0x60]
    //         0046cb40     XOR        EAX,EAX
    //         0046cb42     TEST       this,this
    //         0046cb44     JLE        LAB_0046cb64
    //         0046cb46     MOV        EDX,dword ptr [EBP + param_4]
    //                               LAB_0046cb49                                                 XREF[1]:     0046cb62(j)  
    //         0046cb49     LEA        this,[EBX + 0x1]
    //         0046cb4c     CMP        EAX,this
    //         0046cb4e     JGE        LAB_0046cb64
    //         0046cb50     MOV        this,dword ptr [EDI + 0x54]
    //         0046cb53     MOV        EBX,dword ptr [EBP + param_13]
    //         0046cb56     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         0046cb59     MOV        dword ptr [EDX + EAX*0x4],this
    //         0046cb5c     MOV        this,dword ptr [EDI + 0x60]
    //         0046cb5f     INC        EAX
    //         0046cb60     CMP        EAX,this
    //         0046cb62     JL         LAB_0046cb49
    //                               LAB_0046cb64                                                 XREF[2]:     0046cb44(j), 0046cb4e(j)  
    //         0046cb64     MOV        EDX,dword ptr [EDI + 0x54]
    //         0046cb67     PUSH       EDX
    //         0046cb68     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0046cb6d     MOV        EAX,dword ptr [EBP + param_4]
    //         0046cb70     ADD        ESP,0x4
    //         0046cb73     MOV        dword ptr [EDI + 0x54],EAX
    //         0046cb76     LEA        EAX,[EBX + 0x1]
    //         0046cb79     MOV        dword ptr [EDI + 0x60],EAX
    //                               LAB_0046cb7c                                                 XREF[2]:     0046cb24(j), 0046cb3b(j)  
    //         0046cb7c     MOV        this,dword ptr [EDI + 0x54]
    //         0046cb7f     MOV        EDX,dword ptr [this->_padding_ + EBX*0x4]
    //         0046cb82     MOV        this,dword ptr [ESI + 0x11dc40]
    //         0046cb88     PUSH       EDX
    //         0046cb89     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         0046cb8e     TEST       EAX,EAX
    //         0046cb90     JZ         LAB_0046cbbe
    //         0046cb92     MOV        this,dword ptr [ESI + 0x11dc44]
    //         0046cb98     MOV        EDX,dword ptr [EAX + 0x4]
    //         0046cb9b     CMP        EDX,dword ptr [ECX + this->xSizeValue]
    //         0046cb9e     JZ         LAB_0046cbbe
    //         0046cba0     CMP        byte ptr [EAX + 0x85],0x1
    //         0046cba7     JNZ        LAB_0046cbbe
    //         0046cba9     MOV        this,dword ptr [EAX + 0x20]
    //         0046cbac     TEST       this,this
    //         0046cbae     JNZ        LAB_0046cbbe
    //         0046cbb0     MOV        this,dword ptr [ESI + 0x11dcf4]
    //         0046cbb6     PUSH       this
    //         0046cbb7     MOV        this,EAX
    //         0046cbb9     CALL       RGE_Static_Object::addToObstructionMap           int addToObstructionMap(RGE_Static_Object * t
    //                               LAB_0046cbbe                                                 XREF[4]:     0046cb90(j), 0046cb9e(j), 
    //                                                                                                         0046cba7(j), 0046cbae(j)  
    //         0046cbbe     MOV        EDI,dword ptr [ESI + 0x11dc44]
    //         0046cbc4     INC        EBX
    //         0046cbc5     MOV        dword ptr [EBP + param_13],EBX
    //         0046cbc8     CMP        EBX,dword ptr [EDI + 0x58]
    //         0046cbcb     JL         LAB_0046cb1e
    //                              pathsys.cpp:1179 (5)
    //         0046cbd1     JMP        LAB_0046d19f
    //                               LAB_0046cbd6                                                 XREF[2]:     0046cad1(j), 0046cae4(j)  
    //                              pathsys.cpp:1184 (7)
    //         0046cbd6     MOV        EAX,dword ptr [EBP + param_9]
    //         0046cbd9     TEST       EAX,EAX
    //         0046cbdb     JZ         LAB_0046cbf2
    //                              pathsys.cpp:1185 (21)
    //         0046cbdd     MOV        EDX,dword ptr [EBP + bestPathPoint.y]
    //         0046cbe0     MOV        this,EDI
    //         0046cbe2     SHL        this,0x8
    //         0046cbe5     SUB        this,EDI
    //         0046cbe7     ADD        this,EDX
    //         0046cbe9     FILD       dword ptr [ESI + this->_padding_*0x4 + 0xfe10]
    //         0046cbf0     FSTP       float ptr [EAX]
    //                               LAB_0046cbf2                                                 XREF[1]:     0046cbdb(j)  
    //                              pathsys.cpp:1213 (201)
    //         0046cbf2     MOV        EDI,dword ptr [ESI + 0x11dc44]
    //         0046cbf8     XOR        EBX,EBX
    //         0046cbfa     MOV        dword ptr [EBP + param_13],EBX
    //         0046cbfd     MOV        EAX,dword ptr [EDI + 0x58]
    //         0046cc00     TEST       EAX,EAX
    //         0046cc02     JLE        LAB_0046ceaf
    //                               LAB_0046cc08                                                 XREF[1]:     0046ccb5(j)  
    //         0046cc08     MOV        EDX,dword ptr [EDI + 0x60]
    //         0046cc0b     DEC        EDX
    //         0046cc0c     CMP        EBX,EDX
    //         0046cc0e     JLE        LAB_0046cc66
    //         0046cc10     LEA        EAX,[EBX*0x4 + 0x4]
    //         0046cc17     PUSH       EAX
    //         0046cc18     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0046cc1d     ADD        ESP,0x4
    //         0046cc20     MOV        dword ptr [EBP + param_4],EAX
    //         0046cc23     TEST       EAX,EAX
    //         0046cc25     JZ         LAB_0046cc66
    //         0046cc27     MOV        this,dword ptr [EDI + 0x60]
    //         0046cc2a     XOR        EAX,EAX
    //         0046cc2c     TEST       this,this
    //         0046cc2e     JLE        LAB_0046cc4e
    //         0046cc30     MOV        EDX,dword ptr [EBP + param_4]
    //                               LAB_0046cc33                                                 XREF[1]:     0046cc4c(j)  
    //         0046cc33     LEA        this,[EBX + 0x1]
    //         0046cc36     CMP        EAX,this
    //         0046cc38     JGE        LAB_0046cc4e
    //         0046cc3a     MOV        this,dword ptr [EDI + 0x54]
    //         0046cc3d     MOV        EBX,dword ptr [EBP + param_13]
    //         0046cc40     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         0046cc43     MOV        dword ptr [EDX + EAX*0x4],this
    //         0046cc46     MOV        this,dword ptr [EDI + 0x60]
    //         0046cc49     INC        EAX
    //         0046cc4a     CMP        EAX,this
    //         0046cc4c     JL         LAB_0046cc33
    //                               LAB_0046cc4e                                                 XREF[2]:     0046cc2e(j), 0046cc38(j)  
    //         0046cc4e     MOV        EDX,dword ptr [EDI + 0x54]
    //         0046cc51     PUSH       EDX
    //         0046cc52     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0046cc57     MOV        EAX,dword ptr [EBP + param_4]
    //         0046cc5a     ADD        ESP,0x4
    //         0046cc5d     MOV        dword ptr [EDI + 0x54],EAX
    //         0046cc60     LEA        EAX,[EBX + 0x1]
    //         0046cc63     MOV        dword ptr [EDI + 0x60],EAX
    //                               LAB_0046cc66                                                 XREF[2]:     0046cc0e(j), 0046cc25(j)  
    //         0046cc66     MOV        this,dword ptr [EDI + 0x54]
    //         0046cc69     MOV        EDX,dword ptr [this->_padding_ + EBX*0x4]
    //         0046cc6c     MOV        this,dword ptr [ESI + 0x11dc40]
    //         0046cc72     PUSH       EDX
    //         0046cc73     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         0046cc78     TEST       EAX,EAX
    //         0046cc7a     JZ         LAB_0046cca8
    //         0046cc7c     MOV        this,dword ptr [ESI + 0x11dc44]
    //         0046cc82     MOV        EDX,dword ptr [EAX + 0x4]
    //         0046cc85     CMP        EDX,dword ptr [ECX + this->xSizeValue]
    //         0046cc88     JZ         LAB_0046cca8
    //         0046cc8a     CMP        byte ptr [EAX + 0x85],0x1
    //         0046cc91     JNZ        LAB_0046cca8
    //         0046cc93     MOV        this,dword ptr [EAX + 0x20]
    //         0046cc96     TEST       this,this
    //         0046cc98     JNZ        LAB_0046cca8
    //         0046cc9a     MOV        this,dword ptr [ESI + 0x11dcf4]
    //         0046cca0     PUSH       this
    //         0046cca1     MOV        this,EAX
    //         0046cca3     CALL       RGE_Static_Object::addToObstructionMap           int addToObstructionMap(RGE_Static_Object * t
    //                               LAB_0046cca8                                                 XREF[4]:     0046cc7a(j), 0046cc88(j), 
    //                                                                                                         0046cc91(j), 0046cc98(j)  
    //         0046cca8     MOV        EDI,dword ptr [ESI + 0x11dc44]
    //         0046ccae     INC        EBX
    //         0046ccaf     MOV        dword ptr [EBP + param_13],EBX
    //         0046ccb2     CMP        EBX,dword ptr [EDI + 0x58]
    //         0046ccb5     JL         LAB_0046cc08
    //                              pathsys.cpp:1220 (5)
    //         0046ccbb     JMP        LAB_0046ceaf
    //                               LAB_0046ccc0                                                 XREF[1]:     0046ca85(j)  
    //                              pathsys.cpp:1761 (10)
    //         0046ccc0     CMP        dword ptr [EBP + param_8],0x1
    //         0046ccc4     JNZ        LAB_0046cdc8
    //                              pathsys.cpp:1763 (19)
    //         0046ccca     MOV        EAX,dword ptr [EBP + param_13]
    //         0046cccd     MOV        this,ESI
    //         0046cccf     PUSH       EAX
    //         0046ccd0     CALL       PathingSystem::copyPath                          int copyPath(PathingSystem * this, int param_1)
    //         0046ccd5     TEST       EAX,EAX
    //         0046ccd7     JNZ        LAB_0046cdc8
    //                              pathsys.cpp:1769 (11)
    //         0046ccdd     MOV        EAX,dword ptr [EBP + param_5]
    //         0046cce0     MOV        this,byte ptr [EAX + 0x154]
    //         0046cce6     TEST       this,this
    //                              pathsys.cpp:1770 (8)
    //         0046cce8     LEA        this,[EAX + 0xa4]
    //         0046ccee     JZ         LAB_0046ccf6
    //                              pathsys.cpp:1772 (11)
    //         0046ccf0     LEA        this,[EAX + 0xd8]
    //                               LAB_0046ccf6                                                 XREF[1]:     0046ccee(j)  
    //         0046ccf6     CALL       Path::killPath                                   void killPath(Path * this)
    //                              pathsys.cpp:1774 (200)
    //         0046ccfb     MOV        EDI,dword ptr [ESI + 0x11dc44]
    //         0046cd01     XOR        EBX,EBX
    //         0046cd03     MOV        dword ptr [EBP + param_13],EBX
    //         0046cd06     MOV        EAX,dword ptr [EDI + 0x58]
    //         0046cd09     TEST       EAX,EAX
    //         0046cd0b     JLE        LAB_0046d19f
    //                               LAB_0046cd11                                                 XREF[1]:     0046cdbd(j)  
    //         0046cd11     MOV        this,dword ptr [EDI + 0x60]
    //         0046cd14     DEC        this
    //         0046cd15     CMP        EBX,this
    //         0046cd17     JLE        LAB_0046cd6e
    //         0046cd19     LEA        EDX,[EBX*0x4 + 0x4]
    //         0046cd20     PUSH       EDX
    //         0046cd21     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0046cd26     MOV        EDX,EAX
    //         0046cd28     ADD        ESP,0x4
    //         0046cd2b     TEST       EDX,EDX
    //         0046cd2d     MOV        dword ptr [EBP + param_4],EDX
    //         0046cd30     JZ         LAB_0046cd6e
    //         0046cd32     MOV        this,dword ptr [EDI + 0x60]
    //         0046cd35     XOR        EAX,EAX
    //         0046cd37     TEST       this,this
    //         0046cd39     JLE        LAB_0046cd56
    //                               LAB_0046cd3b                                                 XREF[1]:     0046cd54(j)  
    //         0046cd3b     LEA        this,[EBX + 0x1]
    //         0046cd3e     CMP        EAX,this
    //         0046cd40     JGE        LAB_0046cd56
    //         0046cd42     MOV        this,dword ptr [EDI + 0x54]
    //         0046cd45     MOV        EBX,dword ptr [EBP + param_13]
    //         0046cd48     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         0046cd4b     MOV        dword ptr [EDX + EAX*0x4],this
    //         0046cd4e     MOV        this,dword ptr [EDI + 0x60]
    //         0046cd51     INC        EAX
    //         0046cd52     CMP        EAX,this
    //         0046cd54     JL         LAB_0046cd3b
    //                               LAB_0046cd56                                                 XREF[2]:     0046cd39(j), 0046cd40(j)  
    //         0046cd56     MOV        EDX,dword ptr [EDI + 0x54]
    //         0046cd59     PUSH       EDX
    //         0046cd5a     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0046cd5f     MOV        EAX,dword ptr [EBP + param_4]
    //         0046cd62     ADD        ESP,0x4
    //         0046cd65     MOV        dword ptr [EDI + 0x54],EAX
    //         0046cd68     LEA        EAX,[EBX + 0x1]
    //         0046cd6b     MOV        dword ptr [EDI + 0x60],EAX
    //                               LAB_0046cd6e                                                 XREF[2]:     0046cd17(j), 0046cd30(j)  
    //         0046cd6e     MOV        this,dword ptr [EDI + 0x54]
    //         0046cd71     MOV        EDX,dword ptr [this->_padding_ + EBX*0x4]
    //         0046cd74     MOV        this,dword ptr [ESI + 0x11dc40]
    //         0046cd7a     PUSH       EDX
    //         0046cd7b     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         0046cd80     TEST       EAX,EAX
    //         0046cd82     JZ         LAB_0046cdb0
    //         0046cd84     MOV        this,dword ptr [ESI + 0x11dc44]
    //         0046cd8a     MOV        EDX,dword ptr [EAX + 0x4]
    //         0046cd8d     CMP        EDX,dword ptr [ECX + this->xSizeValue]
    //         0046cd90     JZ         LAB_0046cdb0
    //         0046cd92     CMP        byte ptr [EAX + 0x85],0x1
    //         0046cd99     JNZ        LAB_0046cdb0
    //         0046cd9b     MOV        this,dword ptr [EAX + 0x20]
    //         0046cd9e     TEST       this,this
    //         0046cda0     JNZ        LAB_0046cdb0
    //         0046cda2     MOV        this,dword ptr [ESI + 0x11dcf4]
    //         0046cda8     PUSH       this
    //         0046cda9     MOV        this,EAX
    //         0046cdab     CALL       RGE_Static_Object::addToObstructionMap           int addToObstructionMap(RGE_Static_Object * t
    //                               LAB_0046cdb0                                                 XREF[4]:     0046cd82(j), 0046cd90(j), 
    //                                                                                                         0046cd99(j), 0046cda0(j)  
    //         0046cdb0     MOV        EDI,dword ptr [ESI + 0x11dc44]
    //         0046cdb6     INC        EBX
    //         0046cdb7     MOV        dword ptr [EBP + param_13],EBX
    //         0046cdba     CMP        EBX,dword ptr [EDI + 0x58]
    //         0046cdbd     JL         LAB_0046cd11
    //                              pathsys.cpp:1775 (5)
    //         0046cdc3     JMP        LAB_0046d19f
    //                               LAB_0046cdc8                                                 XREF[2]:     0046ccc4(j), 0046ccd7(j)  
    //                              pathsys.cpp:1780 (7)
    //         0046cdc8     MOV        EAX,dword ptr [EBP + param_9]
    //         0046cdcb     TEST       EAX,EAX
    //         0046cdcd     JZ         LAB_0046cde7
    //                              pathsys.cpp:1781 (24)
    //         0046cdcf     MOV        this,dword ptr [EBP + bestPathPoint.x]
    //         0046cdd2     MOV        EDX,this
    //         0046cdd4     SHL        EDX,0x8
    //         0046cdd7     SUB        EDX,this
    //         0046cdd9     MOV        this,dword ptr [EBP + bestPathPoint.y]
    //         0046cddc     ADD        EDX,this
    //         0046cdde     FILD       dword ptr [ESI + EDX*0x4 + 0xfe10]
    //         0046cde5     FSTP       float ptr [EAX]
    //                               LAB_0046cde7                                                 XREF[1]:     0046cdcd(j)  
    //                              pathsys.cpp:1805 (234)
    //         0046cde7     MOV        EDI,dword ptr [ESI + 0x11dc44]
    //         0046cded     XOR        EBX,EBX
    //         0046cdef     MOV        dword ptr [EBP + param_13],EBX
    //         0046cdf2     MOV        EAX,dword ptr [EDI + 0x58]
    //         0046cdf5     TEST       EAX,EAX
    //         0046cdf7     JLE        LAB_0046ceaf
    //                               LAB_0046cdfd                                                 XREF[1]:     0046cea9(j)  
    //         0046cdfd     MOV        EAX,dword ptr [EDI + 0x60]
    //         0046ce00     DEC        EAX
    //         0046ce01     CMP        EBX,EAX
    //         0046ce03     JLE        LAB_0046ce5a
    //         0046ce05     LEA        this,[EBX*0x4 + 0x4]
    //         0046ce0c     PUSH       this
    //         0046ce0d     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0046ce12     MOV        EDX,EAX
    //         0046ce14     ADD        ESP,0x4
    //         0046ce17     TEST       EDX,EDX
    //         0046ce19     MOV        dword ptr [EBP + param_4],EDX
    //         0046ce1c     JZ         LAB_0046ce5a
    //         0046ce1e     MOV        this,dword ptr [EDI + 0x60]
    //         0046ce21     XOR        EAX,EAX
    //         0046ce23     TEST       this,this
    //         0046ce25     JLE        LAB_0046ce42
    //                               LAB_0046ce27                                                 XREF[1]:     0046ce40(j)  
    //         0046ce27     LEA        this,[EBX + 0x1]
    //         0046ce2a     CMP        EAX,this
    //         0046ce2c     JGE        LAB_0046ce42
    //         0046ce2e     MOV        this,dword ptr [EDI + 0x54]
    //         0046ce31     MOV        EBX,dword ptr [EBP + param_13]
    //         0046ce34     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         0046ce37     MOV        dword ptr [EDX + EAX*0x4],this
    //         0046ce3a     MOV        this,dword ptr [EDI + 0x60]
    //         0046ce3d     INC        EAX
    //         0046ce3e     CMP        EAX,this
    //         0046ce40     JL         LAB_0046ce27
    //                               LAB_0046ce42                                                 XREF[2]:     0046ce25(j), 0046ce2c(j)  
    //         0046ce42     MOV        EDX,dword ptr [EDI + 0x54]
    //         0046ce45     PUSH       EDX
    //         0046ce46     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0046ce4b     MOV        EAX,dword ptr [EBP + param_4]
    //         0046ce4e     ADD        ESP,0x4
    //         0046ce51     MOV        dword ptr [EDI + 0x54],EAX
    //         0046ce54     LEA        EAX,[EBX + 0x1]
    //         0046ce57     MOV        dword ptr [EDI + 0x60],EAX
    //                               LAB_0046ce5a                                                 XREF[2]:     0046ce03(j), 0046ce1c(j)  
    //         0046ce5a     MOV        this,dword ptr [EDI + 0x54]
    //         0046ce5d     MOV        EDX,dword ptr [this->_padding_ + EBX*0x4]
    //         0046ce60     MOV        this,dword ptr [ESI + 0x11dc40]
    //         0046ce66     PUSH       EDX
    //         0046ce67     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         0046ce6c     TEST       EAX,EAX
    //         0046ce6e     JZ         LAB_0046ce9c
    //         0046ce70     MOV        this,dword ptr [ESI + 0x11dc44]
    //         0046ce76     MOV        EDX,dword ptr [EAX + 0x4]
    //         0046ce79     CMP        EDX,dword ptr [ECX + this->xSizeValue]
    //         0046ce7c     JZ         LAB_0046ce9c
    //         0046ce7e     CMP        byte ptr [EAX + 0x85],0x1
    //         0046ce85     JNZ        LAB_0046ce9c
    //         0046ce87     MOV        this,dword ptr [EAX + 0x20]
    //         0046ce8a     TEST       this,this
    //         0046ce8c     JNZ        LAB_0046ce9c
    //         0046ce8e     MOV        this,dword ptr [ESI + 0x11dcf4]
    //         0046ce94     PUSH       this
    //         0046ce95     MOV        this,EAX
    //         0046ce97     CALL       RGE_Static_Object::addToObstructionMap           int addToObstructionMap(RGE_Static_Object * t
    //                               LAB_0046ce9c                                                 XREF[4]:     0046ce6e(j), 0046ce7c(j), 
    //                                                                                                         0046ce85(j), 0046ce8c(j)  
    //         0046ce9c     MOV        EDI,dword ptr [ESI + 0x11dc44]
    //         0046cea2     INC        EBX
    //         0046cea3     MOV        dword ptr [EBP + param_13],EBX
    //         0046cea6     CMP        EBX,dword ptr [EDI + 0x58]
    //         0046cea9     JL         LAB_0046cdfd
    //                               LAB_0046ceaf                                                 XREF[3]:     0046cc02(j), 0046ccbb(j), 
    //                                                                                                         0046cdf7(j)  
    //         0046ceaf     CMP        dword ptr [ESI + 0x11dc48],0x1
    //         0046ceb6     JNZ        LAB_0046ced1
    //         0046ceb8     MOV        this,dword ptr [ESI + 0x11dc44]
    //         0046cebe     MOV        EAX,dword ptr [ECX + this+0x20]
    //         0046cec1     TEST       EAX,EAX
    //         0046cec3     JNZ        LAB_0046ced1
    //         0046cec5     MOV        EDX,dword ptr [ESI + 0x11dcf4]
    //         0046cecb     PUSH       EDX
    //         0046cecc     CALL       RGE_Static_Object::addToObstructionMap           int addToObstructionMap(RGE_Static_Object * t
    //                               LAB_0046ced1                                                 XREF[3]:     0046b7b1(j), 0046ceb6(j), 
    //                                                                                                         0046cec3(j)  
    //                              pathsys.cpp:1812 (5)
    //         0046ced1     MOV        EAX,0x1
    //                              pathsys.cpp:1896 (9)
    //         0046ced6     POP        EDI
    //         0046ced7     POP        ESI
    //         0046ced8     POP        EBX
    //         0046ced9     MOV        ESP,EBP
    //         0046cedb     POP        EBP
    //         0046cedc     RET        0x3c
    //                               LAB_0046cedf                                                 XREF[4]:     0046bf08(j), 0046bf25(j), 
    //                                                                                                         0046bf32(j), 0046cac8(j)  
    //                              pathsys.cpp:1831 (15)
    //         0046cedf     MOV        this,dword ptr [ESI + 0x11dc2c]
    //         0046cee5     INC        this
    //         0046cee6     MOV        dword ptr [ESI + 0x11dc2c],this
    //         0046ceec     MOV        EAX,this
    //                              pathsys.cpp:1832 (13)
    //         0046ceee     MOV        this,byte ptr [ESI + 0x11dc30]
    //         0046cef4     MOV        byte ptr [ESI + EAX*0x8 + 0x4f614],this
    //                              pathsys.cpp:1833 (19)
    //         0046cefb     MOV        EDX,dword ptr [ESI + 0x11dc2c]
    //         0046cf01     MOV        AL,byte ptr [ESI + 0x11dc31]
    //         0046cf07     MOV        byte ptr [ESI + EDX*0x8 + 0x4f615],AL
    //                              pathsys.cpp:1834 (17)
    //         0046cf0e     MOV        this,dword ptr [ESI + 0x11dc2c]
    //         0046cf14     MOV        dword ptr [ESI + this->_padding_*0x8 + 0x4f618
    //                              pathsys.cpp:1836 (159)
    //         0046cf1f     MOV        EBX,dword ptr [ESI + 0x11dc2c]
    //         0046cf25     CMP        EBX,0x1
    //         0046cf28     MOV        EDI,EBX
    //         0046cf2a     JL         LAB_0046cfbe
    //         0046cf30     MOV        EAX,EBX
    //         0046cf32     CDQ
    //         0046cf33     SUB        EAX,EDX
    //         0046cf35     MOV        DL,byte ptr [ESI + EBX*0x8 + 0x4f614]
    //         0046cf3c     MOV        this,EAX
    //         0046cf3e     MOV        AL,byte ptr [ESI + EBX*0x8 + 0x4f615]
    //         0046cf45     SAR        this,0x1
    //         0046cf47     MOV        byte ptr [EBP + param_4],DL
    //         0046cf4a     MOV        byte ptr [EBP + param_3],AL
    //         0046cf4d     MOV        EAX,dword ptr [ESI + EBX*0x8 + 0x4f618]
    //         0046cf54     MOV        EDX,dword ptr [ESI + this->_padding_*0x8 + 0x4
    //         0046cf5b     CMP        EAX,EDX
    //         0046cf5d     MOV        dword ptr [EBP + param_2],EAX
    //         0046cf60     JGE        LAB_0046cf9c
    //                               LAB_0046cf62                                                 XREF[1]:     0046cf9a(j)  
    //         0046cf62     MOV        EDX,dword ptr [ESI + this->_padding_*0x8 + 0x4
    //         0046cf69     MOV        dword ptr [ESI + EDI*0x8 + 0x4f614],EDX
    //         0046cf70     MOV        EAX,dword ptr [ESI + this->_padding_*0x8 + 0x4
    //         0046cf77     MOV        dword ptr [ESI + EDI*0x8 + 0x4f618],EAX
    //         0046cf7e     MOV        EAX,EDI
    //         0046cf80     CDQ
    //         0046cf81     SUB        EAX,EDX
    //         0046cf83     SAR        EAX,0x1
    //         0046cf85     MOV        EDI,EAX
    //         0046cf87     MOV        EAX,this
    //         0046cf89     CDQ
    //         0046cf8a     SUB        EAX,EDX
    //         0046cf8c     MOV        EDX,dword ptr [EBP + param_2]
    //         0046cf8f     SAR        EAX,0x1
    //         0046cf91     MOV        this,EAX
    //         0046cf93     CMP        EDX,dword ptr [ESI + this->_padding_*0x8 + 0x4
    //         0046cf9a     JL         LAB_0046cf62
    //                               LAB_0046cf9c                                                 XREF[1]:     0046cf60(j)  
    //         0046cf9c     CMP        EDI,EBX
    //         0046cf9e     JZ         LAB_0046cfbe
    //         0046cfa0     MOV        AL,byte ptr [EBP + param_4]
    //         0046cfa3     MOV        this,byte ptr [EBP + param_3]
    //         0046cfa6     MOV        EDX,dword ptr [EBP + param_2]
    //         0046cfa9     MOV        byte ptr [ESI + EDI*0x8 + 0x4f614],AL
    //         0046cfb0     MOV        byte ptr [ESI + EDI*0x8 + 0x4f615],this
    //         0046cfb7     MOV        dword ptr [ESI + EDI*0x8 + 0x4f618],EDX
    //                               LAB_0046cfbe                                                 XREF[2]:     0046cf2a(j), 0046cf9e(j)  
    //                              pathsys.cpp:1839 (10)
    //         0046cfbe     CMP        dword ptr [EBP + param_8],0x1
    //         0046cfc2     JNZ        LAB_0046d0c7
    //                              pathsys.cpp:1841 (19)
    //         0046cfc8     MOV        EAX,dword ptr [EBP + param_13]
    //         0046cfcb     MOV        this,ESI
    //         0046cfcd     PUSH       EAX
    //         0046cfce     CALL       PathingSystem::copyPath                          int copyPath(PathingSystem * this, int param_1)
    //         0046cfd3     TEST       EAX,EAX
    //         0046cfd5     JNZ        LAB_0046d0c7
    //                              pathsys.cpp:1847 (11)
    //         0046cfdb     MOV        EAX,dword ptr [EBP + param_5]
    //         0046cfde     MOV        this,byte ptr [EAX + 0x154]
    //         0046cfe4     TEST       this,this
    //                              pathsys.cpp:1848 (8)
    //         0046cfe6     LEA        this,[EAX + 0xa4]
    //         0046cfec     JZ         LAB_0046cff4
    //                              pathsys.cpp:1850 (11)
    //         0046cfee     LEA        this,[EAX + 0xd8]
    //                               LAB_0046cff4                                                 XREF[1]:     0046cfec(j)  
    //         0046cff4     CALL       Path::killPath                                   void killPath(Path * this)
    //                              pathsys.cpp:1852 (201)
    //         0046cff9     MOV        EDI,dword ptr [ESI + 0x11dc44]
    //         0046cfff     XOR        EBX,EBX
    //         0046d001     MOV        dword ptr [EBP + param_13],EBX
    //         0046d004     MOV        EAX,dword ptr [EDI + 0x58]
    //         0046d007     TEST       EAX,EAX
    //         0046d009     JLE        LAB_0046d19f
    //                               LAB_0046d00f                                                 XREF[1]:     0046d0bc(j)  
    //         0046d00f     MOV        this,dword ptr [EDI + 0x60]
    //         0046d012     DEC        this
    //         0046d013     CMP        EBX,this
    //         0046d015     JLE        LAB_0046d06d
    //         0046d017     LEA        EDX,[EBX*0x4 + 0x4]
    //         0046d01e     PUSH       EDX
    //         0046d01f     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0046d024     ADD        ESP,0x4
    //         0046d027     MOV        dword ptr [EBP + param_4],EAX
    //         0046d02a     TEST       EAX,EAX
    //         0046d02c     JZ         LAB_0046d06d
    //         0046d02e     MOV        this,dword ptr [EDI + 0x60]
    //         0046d031     XOR        EAX,EAX
    //         0046d033     TEST       this,this
    //         0046d035     JLE        LAB_0046d055
    //         0046d037     MOV        EDX,dword ptr [EBP + param_4]
    //                               LAB_0046d03a                                                 XREF[1]:     0046d053(j)  
    //         0046d03a     LEA        this,[EBX + 0x1]
    //         0046d03d     CMP        EAX,this
    //         0046d03f     JGE        LAB_0046d055
    //         0046d041     MOV        this,dword ptr [EDI + 0x54]
    //         0046d044     MOV        EBX,dword ptr [EBP + param_13]
    //         0046d047     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         0046d04a     MOV        dword ptr [EDX + EAX*0x4],this
    //         0046d04d     MOV        this,dword ptr [EDI + 0x60]
    //         0046d050     INC        EAX
    //         0046d051     CMP        EAX,this
    //         0046d053     JL         LAB_0046d03a
    //                               LAB_0046d055                                                 XREF[2]:     0046d035(j), 0046d03f(j)  
    //         0046d055     MOV        EDX,dword ptr [EDI + 0x54]
    //         0046d058     PUSH       EDX
    //         0046d059     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0046d05e     MOV        EAX,dword ptr [EBP + param_4]
    //         0046d061     ADD        ESP,0x4
    //         0046d064     MOV        dword ptr [EDI + 0x54],EAX
    //         0046d067     LEA        EAX,[EBX + 0x1]
    //         0046d06a     MOV        dword ptr [EDI + 0x60],EAX
    //                               LAB_0046d06d                                                 XREF[2]:     0046d015(j), 0046d02c(j)  
    //         0046d06d     MOV        this,dword ptr [EDI + 0x54]
    //         0046d070     MOV        EDX,dword ptr [this->_padding_ + EBX*0x4]
    //         0046d073     MOV        this,dword ptr [ESI + 0x11dc40]
    //         0046d079     PUSH       EDX
    //         0046d07a     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         0046d07f     TEST       EAX,EAX
    //         0046d081     JZ         LAB_0046d0af
    //         0046d083     MOV        this,dword ptr [ESI + 0x11dc44]
    //         0046d089     MOV        EDX,dword ptr [EAX + 0x4]
    //         0046d08c     CMP        EDX,dword ptr [ECX + this->xSizeValue]
    //         0046d08f     JZ         LAB_0046d0af
    //         0046d091     CMP        byte ptr [EAX + 0x85],0x1
    //         0046d098     JNZ        LAB_0046d0af
    //         0046d09a     MOV        this,dword ptr [EAX + 0x20]
    //         0046d09d     TEST       this,this
    //         0046d09f     JNZ        LAB_0046d0af
    //         0046d0a1     MOV        this,dword ptr [ESI + 0x11dcf4]
    //         0046d0a7     PUSH       this
    //         0046d0a8     MOV        this,EAX
    //         0046d0aa     CALL       RGE_Static_Object::addToObstructionMap           int addToObstructionMap(RGE_Static_Object * t
    //                               LAB_0046d0af                                                 XREF[4]:     0046d081(j), 0046d08f(j), 
    //                                                                                                         0046d098(j), 0046d09f(j)  
    //         0046d0af     MOV        EDI,dword ptr [ESI + 0x11dc44]
    //         0046d0b5     INC        EBX
    //         0046d0b6     MOV        dword ptr [EBP + param_13],EBX
    //         0046d0b9     CMP        EBX,dword ptr [EDI + 0x58]
    //         0046d0bc     JL         LAB_0046d00f
    //                              pathsys.cpp:1853 (5)
    //         0046d0c2     JMP        LAB_0046d19f
    //                               LAB_0046d0c7                                                 XREF[2]:     0046cfc2(j), 0046cfd5(j)  
    //                              pathsys.cpp:1858 (7)
    //         0046d0c7     MOV        EAX,dword ptr [EBP + param_9]
    //         0046d0ca     TEST       EAX,EAX
    //         0046d0cc     JZ         LAB_0046d0d6
    //                              pathsys.cpp:1859 (8)
    //         0046d0ce     FILD       dword ptr [ESI + 0x11dc34]
    //         0046d0d4     FSTP       float ptr [EAX]
    //                               LAB_0046d0d6                                                 XREF[1]:     0046d0cc(j)  
    //                              pathsys.cpp:1888 (237)
    //         0046d0d6     MOV        EDI,dword ptr [ESI + 0x11dc44]
    //         0046d0dc     XOR        EBX,EBX
    //         0046d0de     MOV        dword ptr [EBP + param_13],EBX
    //         0046d0e1     MOV        EAX,dword ptr [EDI + 0x58]
    //         0046d0e4     TEST       EAX,EAX
    //         0046d0e6     JLE        LAB_0046d19f
    //                               LAB_0046d0ec                                                 XREF[1]:     0046d199(j)  
    //         0046d0ec     MOV        EAX,dword ptr [EDI + 0x60]
    //         0046d0ef     DEC        EAX
    //         0046d0f0     CMP        EBX,EAX
    //         0046d0f2     JLE        LAB_0046d14a
    //         0046d0f4     LEA        this,[EBX*0x4 + 0x4]
    //         0046d0fb     PUSH       this
    //         0046d0fc     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0046d101     ADD        ESP,0x4
    //         0046d104     MOV        dword ptr [EBP + param_4],EAX
    //         0046d107     TEST       EAX,EAX
    //         0046d109     JZ         LAB_0046d14a
    //         0046d10b     MOV        this,dword ptr [EDI + 0x60]
    //         0046d10e     XOR        EAX,EAX
    //         0046d110     TEST       this,this
    //         0046d112     JLE        LAB_0046d132
    //         0046d114     MOV        EDX,dword ptr [EBP + param_4]
    //                               LAB_0046d117                                                 XREF[1]:     0046d130(j)  
    //         0046d117     LEA        this,[EBX + 0x1]
    //         0046d11a     CMP        EAX,this
    //         0046d11c     JGE        LAB_0046d132
    //         0046d11e     MOV        this,dword ptr [EDI + 0x54]
    //         0046d121     MOV        EBX,dword ptr [EBP + param_13]
    //         0046d124     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         0046d127     MOV        dword ptr [EDX + EAX*0x4],this
    //         0046d12a     MOV        this,dword ptr [EDI + 0x60]
    //         0046d12d     INC        EAX
    //         0046d12e     CMP        EAX,this
    //         0046d130     JL         LAB_0046d117
    //                               LAB_0046d132                                                 XREF[2]:     0046d112(j), 0046d11c(j)  
    //         0046d132     MOV        EDX,dword ptr [EDI + 0x54]
    //         0046d135     PUSH       EDX
    //         0046d136     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0046d13b     MOV        EAX,dword ptr [EBP + param_4]
    //         0046d13e     ADD        ESP,0x4
    //         0046d141     MOV        dword ptr [EDI + 0x54],EAX
    //         0046d144     LEA        EAX,[EBX + 0x1]
    //         0046d147     MOV        dword ptr [EDI + 0x60],EAX
    //                               LAB_0046d14a                                                 XREF[2]:     0046d0f2(j), 0046d109(j)  
    //         0046d14a     MOV        this,dword ptr [EDI + 0x54]
    //         0046d14d     MOV        EDX,dword ptr [this->_padding_ + EBX*0x4]
    //         0046d150     MOV        this,dword ptr [ESI + 0x11dc40]
    //         0046d156     PUSH       EDX
    //         0046d157     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         0046d15c     TEST       EAX,EAX
    //         0046d15e     JZ         LAB_0046d18c
    //         0046d160     MOV        this,dword ptr [ESI + 0x11dc44]
    //         0046d166     MOV        EDX,dword ptr [EAX + 0x4]
    //         0046d169     CMP        EDX,dword ptr [ECX + this->xSizeValue]
    //         0046d16c     JZ         LAB_0046d18c
    //         0046d16e     CMP        byte ptr [EAX + 0x85],0x1
    //         0046d175     JNZ        LAB_0046d18c
    //         0046d177     MOV        this,dword ptr [EAX + 0x20]
    //         0046d17a     TEST       this,this
    //         0046d17c     JNZ        LAB_0046d18c
    //         0046d17e     MOV        this,dword ptr [ESI + 0x11dcf4]
    //         0046d184     PUSH       this
    //         0046d185     MOV        this,EAX
    //         0046d187     CALL       RGE_Static_Object::addToObstructionMap           int addToObstructionMap(RGE_Static_Object * t
    //                               LAB_0046d18c                                                 XREF[4]:     0046d15e(j), 0046d16c(j), 
    //                                                                                                         0046d175(j), 0046d17c(j)  
    //         0046d18c     MOV        EDI,dword ptr [ESI + 0x11dc44]
    //         0046d192     INC        EBX
    //         0046d193     MOV        dword ptr [EBP + param_13],EBX
    //         0046d196     CMP        EBX,dword ptr [EDI + 0x58]
    //         0046d199     JL         LAB_0046d0ec
    //                               LAB_0046d19f                                                 XREF[7]:     0046cb18(j), 0046cbd1(j), 
    //                                                                                                         0046cd0b(j), 0046cdc3(j), 
    //                                                                                                         0046d009(j), 0046d0c2(j), 
    //                                                                                                         0046d0e6(j)  
    //         0046d19f     CMP        dword ptr [ESI + 0x11dc48],0x1
    //         0046d1a6     JNZ        LAB_0046d1f0
    //         0046d1a8     MOV        this,dword ptr [ESI + 0x11dc44]
    //         0046d1ae     MOV        EAX,dword ptr [ECX + this+0x20]
    //         0046d1b1     TEST       EAX,EAX
    //         0046d1b3     JNZ        LAB_0046d1f0
    //         0046d1b5     MOV        EDX,dword ptr [ESI + 0x11dcf4]
    //         0046d1bb     PUSH       EDX
    //         0046d1bc     CALL       RGE_Static_Object::addToObstructionMap           int addToObstructionMap(RGE_Static_Object * t
    //         0046d1c1     XOR        EAX,EAX
    //                              pathsys.cpp:1896 (9)
    //         0046d1c3     POP        EDI
    //         0046d1c4     POP        ESI
    //         0046d1c5     POP        EBX
    //         0046d1c6     MOV        ESP,EBP
    //         0046d1c8     POP        EBP
    //         0046d1c9     RET        0x3c
    //                               LAB_0046d1cc                                                 XREF[8]:     0046b6f0(j), 0046b6fb(j), 
    //                                                                                                         0046b706(j), 0046b70e(j), 
    //                                                                                                         0046b719(j), 0046b724(j), 
    //                                                                                                         0046b72c(j), 0046b734(j)  
    //                              pathsys.cpp:867 (6)
    //         0046d1cc     CMP        dword ptr [EBP + param_8],0x1
    //         0046d1d0     JNZ        LAB_0046d1f0
    //                              pathsys.cpp:870 (11)
    //         0046d1d2     MOV        EAX,dword ptr [EBP + param_5]
    //         0046d1d5     MOV        this,byte ptr [EAX + 0x154]
    //         0046d1db     TEST       this,this
    //                              pathsys.cpp:871 (8)
    //         0046d1dd     LEA        this,[EAX + 0xa4]
    //         0046d1e3     JZ         LAB_0046d1eb
    //                              pathsys.cpp:873 (11)
    //         0046d1e5     LEA        this,[EAX + 0xd8]
    //                               LAB_0046d1eb                                                 XREF[2]:     0046b81f(j), 0046d1e3(j)  
    //         0046d1eb     CALL       Path::killPath                                   void killPath(Path * this)
    //                               LAB_0046d1f0                                                 XREF[4]:     0046b80b(j), 0046d1a6(j), 
    //                                                                                                         0046d1b3(j), 0046d1d0(j)  
    //                              pathsys.cpp:1896 (11)
    //         0046d1f0     POP        EDI
    //         0046d1f1     POP        ESI
    //         0046d1f2     XOR        EAX,EAX
    //         0046d1f4     POP        EBX
    //         0046d1f5     MOV        ESP,EBP
    //         0046d1f7     POP        EBP
    //         0046d1f8     RET        0x3c
    //                               LAB_0046d1fb                                                 XREF[2]:     0046c5f5(j), 0046c601(j)  
    //                              pathsys.cpp:1590 (7)
    //         0046d1fb     FSTP       ST0
    //         0046d1fd     JMP        LAB_0046c645
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_0046d202()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0046d202
    //                              pathsys.cpp:1896 (66)
    //         0046d202     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0046c158::switchdataD_0046d204                       XREF[1]:     findTilePath:0046c158(R)  
    //         0046d204     addr       switchD_0046c158::caseD_0
    //         0046d208     addr       switchD_0046c158::caseD_1
    //         0046d20c     addr       switchD_0046c158::caseD_1
    //         0046d210     addr       switchD_0046c158::caseD_3
    //         0046d214     addr       switchD_0046c158::caseD_4
    //         0046d218     addr       switchD_0046c158::caseD_5
    //         0046d21c     addr       switchD_0046c158::caseD_5
    //         0046d220     addr       switchD_0046c158::caseD_7
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0046c328::switchdataD_0046d224                       XREF[1]:     findTilePath:0046c328(*)  
    //         0046d224     addr       switchD_0046c328::caseD_0
    //         0046d228     addr       switchD_0046c328::caseD_1
    //         0046d22c     addr       switchD_0046c328::caseD_2
    //         0046d230     addr       switchD_0046c328::caseD_3
    //         0046d234     addr       switchD_0046c328::caseD_4
    //         0046d238     addr       switchD_0046c328::caseD_5
    //         0046d23c     addr       switchD_0046c328::caseD_6
    //         0046d240     addr       switchD_0046c328::caseD_7
    //         0046d244     ??         90h
    //         0046d245     ??         90h
    //         0046d246     ??         90h
    //         0046d247     ??         90h
    //         0046d248     ??         90h
    //         0046d249     ??         90h
    //         0046d24a     ??         90h
    //         0046d24b     ??         90h
    //         0046d24c     ??         90h
    //         0046d24d     ??         90h
    //         0046d24e     ??         90h
    //         0046d24f     ??         90h
    return;
}

void PathingSystem::incrementInitialPaths() {
    /* TODO: Stub */
    //                              void __thiscall incrementInitialPaths(PathingSystem * this)
    //              void              <VOID>         <RETURN>
    //              PathingSystem *   ECX:4 (auto)   this
    //                               ?incrementInitialPaths@PathingSystem@@QAEXXZ                 XREF[1]:     findPath:0045d834(c)  
    //                               PathingSystem::incrementInitialPaths
    //                              pathsys.cpp:2027 (6)
    //         0046d250     INC        dword ptr [ECX + this->numInitialPathsValue]
    //                              pathsys.cpp:2029 (1)
    //         0046d256     RET
    //         0046d257     ??         90h
    //         0046d258     NOP
    //         0046d259     NOP
    //         0046d25a     NOP
    //         0046d25b     NOP
    //         0046d25c     NOP
    //         0046d25d     NOP
    //         0046d25e     NOP
    //         0046d25f     NOP
    return;
}

void PathingSystem::incrementContinuePaths() {
    /* TODO: Stub */
    //                              void __thiscall incrementContinuePaths(PathingSystem * this)
    //              void              <VOID>         <RETURN>
    //              PathingSystem *   ECX:4 (auto)   this
    //                               ?incrementContinuePaths@PathingSystem@@QAEXXZ                XREF[3]:     doMove:0045e042(c), 
    //                               PathingSystem::incrementContinuePaths                                     doMove:0045e557(c), 
    //                                                                                                         doTrivialMove:0045ef5a(c)  
    //                              pathsys.cpp:2034 (6)
    //         0046d260     INC        dword ptr [ECX + this->numContinuePathsValue]
    //                              pathsys.cpp:2036 (1)
    //         0046d266     RET
    //         0046d267     ??         90h
    //         0046d268     NOP
    //         0046d269     NOP
    //         0046d26a     NOP
    //         0046d26b     NOP
    //         0046d26c     NOP
    //         0046d26d     NOP
    //         0046d26e     NOP
    //         0046d26f     NOP
    return;
}

void PathingSystem::incrementCanPaths() {
    /* TODO: Stub */
    //                              void __thiscall incrementCanPaths(PathingSystem * this)
    //              void              <VOID>         <RETURN>
    //              PathingSystem *   ECX:4 (auto)   this
    //                               ?incrementCanPaths@PathingSystem@@QAEXXZ                     XREF[10]:    canPath:0045f919(c), 
    //                               PathingSystem::incrementCanPaths                                          canPath:0045f96c(c), 
    //                                                                                                         canPath:0045faf8(c), 
    //                                                                                                         canPath:0045fb5a(c), 
    //                                                                                                         canBidirectionPath:0045fd08(c), 
    //                                                                                                         canBidirectionPath:0045fde6(c), 
    //                                                                                                         canPathWithObstructions:0045ffff(c
    //                                                                                                         canPathWithObstructions:0046006a(c
    //                                                                                                         canPathWithAdditionalPassability:0
    //                                                                                                         canPathWithAdditionalPassability:0
    //                              pathsys.cpp:2041 (6)
    //         0046d270     INC        dword ptr [ECX + this->numCanPathsValue]
    //                              pathsys.cpp:2043 (1)
    //         0046d276     RET
    //         0046d277     ??         90h
    //         0046d278     NOP
    //         0046d279     NOP
    //         0046d27a     NOP
    //         0046d27b     NOP
    //         0046d27c     NOP
    //         0046d27d     NOP
    //         0046d27e     NOP
    //         0046d27f     NOP
    return;
}

int PathingSystem::passable(RGE_Moving_Object* param_1, float param_2, float param_3, int param_4) {
    /* TODO: Stub */
    //                              int __thiscall passable(PathingSystem * this, RGE_Moving_Object * pa
    //              int               EAX:4          <RETURN>
    //              PathingSystem *   ECX:4 (auto)   this
    //              RGE_Moving_Obj    Stack[0x4]:4   param_1                   XREF[4]:     0046d287(R), 0046d55c(R), 0046d6df(R), 0046d70a(R)  
    //              float             Stack[0x8]:4   param_2                   XREF[12]:    0046d28d(R), 0046d2e2(R), 0046d30c(R), 0046d343(W), 
    //                                                                                     0046d3c2(W), 0046d43d(R), 0046d512(R), 0046d549(R), 
    //                                                                                     0046d5cc(W), 0046d626(R), 0046d673(W), 0046d67d(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[10]:    0046d2f0(R), 0046d302(R), 0046d335(R), 0046d3a0(W), 
    //                                                                                     0046d3df(R), 0046d595(R), 0046d5d2(R), 0046d608(R), 
    //                                                                                     0046d64d(R), 0046d6c2(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[7]:     0046d3d3(R), 0046d3e8(W), 0046d3ee(R), 0046d516(R), 
    //                                                                                     0046d56d(W), 0046d6b1(W), 0046d6d0(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0046d4a1(W), 0046d4ab(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0046d44c(W), 0046d452(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[6]:     0046d40c(W), 0046d41a(R), 0046d535(R), 0046d567(W), 
    //                                                                                     0046d6d7(R), 0046d702(R)  
    //              int               Stack[-0x10]:4 inObMap                   XREF[3]:     0046d410(W), 0046d439(R), 0046d52b(R)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[3]:     0046d466(W), 0046d480(R), 0046d521(W)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[6]:     0046d2ec(W), 0046d319(R), 0046d368(R), 0046d3bb(W), 
    //                                                                                     0046d54d(R), 0046d6b9(R)  
    //              int               Stack[-0x1c]:4 maxY                      XREF[7]:     0046d310(W), 0046d359(R), 0046d38c(R), 0046d42f(W), 
    //                                                                                     0046d45c(R), 0046d531(R), 0046d53d(W)  
    //              float             Stack[-0x20]:4 yRadius                   XREF[4]:     0046d37d(W), 0046d3c6(R), 0046d3cf(W), 0046d551(R)  
    //              int               Stack[-0x24]:4 minY
    //              undefined8        Stack[-0x38]:8 local_38                  XREF[2]:     0046d2aa(*), 0046d2f4(*)  
    //                               ?passable@PathingSystem@@QAEHPAVRGE_Moving_Object@@MMH@Z     XREF[12]:    findPath:0045da09(c), 
    //                               PathingSystem::passable                                                   doMove:0045ddf8(c), 
    //                                                                                                         doMove:0045e212(c), 
    //                                                                                                         doMove:0045e723(c), 
    //                                                                                                         doTrivialMove:0045eca8(c), 
    //                                                                                                         doTrivialMove:0045edba(c), 
    //                                                                                                         doTrivialMove:0045eec2(c), 
    //                                                                                                         doTrivialMove:0045f12d(c), 
    //                                                                                                         doTrivialMove:0045f49c(c), 
    //                                                                                                         doTrivialMove:0045f661(c), 
    //                                                                                                         passableTile:0045f80f(c), 
    //                                                                                                         findTilePath:0046ba2a(c)  
    //                              pathsys.cpp:2049 (7)
    //         0046d280     SUB        ESP,0x20
    //         0046d283     PUSH       EBX
    //         0046d284     PUSH       EBP
    //         0046d285     PUSH       ESI
    //         0046d286     PUSH       EDI
    //                              pathsys.cpp:2058 (6)
    //         0046d287     MOV        EDI,dword ptr [ESP + param_1]
    //         0046d28b     MOV        ESI,this
    //                              pathsys.cpp:2096 (92)
    //         0046d28d     FLD        float ptr [ESP + param_2]
    //         0046d291     MOV        EAX,dword ptr [ESI + 0x11dc40]
    //         0046d297     MOV        dword ptr [ESI + 0x11dc44],EDI
    //         0046d29d     MOV        this,dword ptr [EDI + 0x8]
    //         0046d2a0     SUB        ESP,0x8
    //         0046d2a3     MOV        EAX,dword ptr [EAX + 0x54]
    //         0046d2a6     MOVSX      EDX,word ptr [ECX + this+0x66]
    //         0046d2aa     FSTP       double ptr [ESP]=>local_38
    //         0046d2ad     MOV        this,dword ptr [EAX + EDX*0x4]
    //         0046d2b0     OR         EAX,0xffffffff
    //         0046d2b3     MOV        dword ptr [ESI + 0x11dc50],this
    //         0046d2b9     MOV        dword ptr [ESI + 0x11dc7c],EAX
    //         0046d2bf     MOV        dword ptr [ESI + 0x11dc80],EAX
    //         0046d2c5     MOV        dword ptr [ESI + 0x11dc94],EAX
    //         0046d2cb     MOV        dword ptr [ESI + 0x11dc98],EAX
    //         0046d2d1     MOV        dword ptr [ESI + 0x11dc9c],EAX
    //         0046d2d7     MOV        dword ptr [ESI + 0x11dca0],EAX
    //         0046d2dd     CALL       floor                                            undefined floor()
    //         0046d2e2     FSUBR      float ptr [ESP + param_2]
    //         0046d2e6     ADD        ESP,0x8
    //                              pathsys.cpp:2097 (19)
    //         0046d2e9     SUB        ESP,0x8
    //         0046d2ec     FSTP       float ptr [ESP + local_18]
    //         0046d2f0     FLD        float ptr [ESP + param_3]
    //         0046d2f4     FSTP       double ptr [ESP]=>local_38
    //         0046d2f7     CALL       floor                                            undefined floor()
    //                              pathsys.cpp:2099 (13)
    //         0046d2fc     MOV        EAX,dword ptr [EDI + 0x8]
    //         0046d2ff     ADD        ESP,0x8
    //         0046d302     FSUBR      float ptr [ESP + param_3]
    //         0046d306     FLD        float ptr [EAX + 0x30]
    //                              pathsys.cpp:2100 (3)
    //         0046d309     MOV        EDX,dword ptr [EAX + 0x34]
    //                              pathsys.cpp:2119 (41)
    //         0046d30c     FLD        float ptr [ESP + param_2]
    //         0046d310     MOV        dword ptr [ESP + maxY],EDX
    //         0046d314     CALL       __ftol                                           undefined __ftol()
    //         0046d319     FLD        float ptr [ESP + local_18]
    //         0046d31d     FSUB       float ptr [DAT_00570e68]
    //         0046d323     MOV        EDI,EAX
    //         0046d325     SHL        EDI,0x2
    //         0046d328     FSUB       ST0,ST1
    //         0046d32a     FMUL       float ptr [DAT_00570e74]
    //         0046d330     CALL       __ftol                                           undefined __ftol()
    //                              pathsys.cpp:2121 (51)
    //         0046d335     FLD        float ptr [ESP + param_3]
    //         0046d339     MOV        EBP,EDI
    //         0046d33b     SUB        EBP,EAX
    //         0046d33d     SUB        EBP,0x190
    //         0046d343     MOV        dword ptr [ESP + param_2],EBP
    //         0046d347     CALL       __ftol                                           undefined __ftol()
    //         0046d34c     FLD        ST1
    //         0046d34e     FSUB       float ptr [DAT_00570e68]
    //         0046d354     MOV        EBX,EAX
    //         0046d356     SHL        EBX,0x2
    //         0046d359     FSUB       float ptr [ESP + maxY]
    //         0046d35d     FMUL       float ptr [DAT_00570e74]
    //         0046d363     CALL       __ftol                                           undefined __ftol()
    //                              pathsys.cpp:2123 (36)
    //         0046d368     FADD       float ptr [ESP + local_18]
    //         0046d36c     MOV        this,EAX
    //         0046d36e     MOV        EAX,EBX
    //         0046d370     SUB        EAX,this
    //         0046d372     FSUB       float ptr [DAT_00570e68]
    //         0046d378     SUB        EAX,0x190
    //         0046d37d     MOV        dword ptr [ESP + yRadius],EAX
    //         0046d381     FMUL       float ptr [DAT_00570e74]
    //         0046d387     CALL       __ftol                                           undefined __ftol()
    //                              pathsys.cpp:2125 (45)
    //         0046d38c     FLD        float ptr [ESP + maxY]
    //         0046d390     FADD       ST0,ST1
    //         0046d392     SUB        EDI,EAX
    //         0046d394     SUB        EDI,0x190
    //         0046d39a     FSUB       float ptr [DAT_00570e68]
    //         0046d3a0     MOV        dword ptr [ESP + param_3],EDI
    //         0046d3a4     FMUL       float ptr [DAT_00570e74]
    //         0046d3aa     CALL       __ftol                                           undefined __ftol()
    //         0046d3af     FSTP       ST0
    //         0046d3b1     SUB        EBX,EAX
    //         0046d3b3     SUB        EBX,0x190
    //                              pathsys.cpp:2127 (13)
    //         0046d3b9     TEST       EBP,EBP
    //         0046d3bb     MOV        dword ptr [ESP + local_18],EBX
    //         0046d3bf     JGE        LAB_0046d3c6
    //         0046d3c1     INC        EBP
    //         0046d3c2     MOV        dword ptr [ESP + param_2],EBP
    //                               LAB_0046d3c6                                                 XREF[1]:     0046d3bf(j)  
    //                              pathsys.cpp:2128 (13)
    //         0046d3c6     MOV        EDI,dword ptr [ESP + yRadius]
    //         0046d3ca     TEST       EDI,EDI
    //         0046d3cc     JGE        LAB_0046d3d3
    //         0046d3ce     INC        EDI
    //         0046d3cf     MOV        dword ptr [ESP + yRadius],EDI
    //                               LAB_0046d3d3                                                 XREF[1]:     0046d3cc(j)  
    //                              pathsys.cpp:2141 (386)
    //         0046d3d3     MOV        EAX,dword ptr [ESP + param_4]
    //         0046d3d7     TEST       EAX,EAX
    //         0046d3d9     JZ         LAB_0046d555
    //         0046d3df     MOV        EDX,dword ptr [ESP + param_3]
    //         0046d3e3     MOV        this,EBX
    //         0046d3e5     SAR        EDX,0x2
    //         0046d3e8     MOV        byte ptr [ESP + param_4],DL
    //         0046d3ec     MOV        EBX,EBP
    //         0046d3ee     MOV        EBP,dword ptr [ESP + param_4]
    //         0046d3f2     MOV        EAX,EDI
    //         0046d3f4     MOV        EDI,dword ptr [ESI + 0x11dc3c]
    //         0046d3fa     AND        EBP,0xff
    //         0046d400     SAR        this,0x2
    //         0046d403     SAR        EAX,0x2
    //         0046d406     SAR        EBX,0x2
    //         0046d409     CMP        EBP,dword ptr [EDI + 0x8]
    //         0046d40c     MOV        byte ptr [ESP + local_c],this
    //         0046d410     MOV        byte ptr [ESP + inObMap],BL
    //         0046d414     JGE        LAB_0046d6f6
    //         0046d41a     MOV        EBP,dword ptr [ESP + local_c]
    //         0046d41e     AND        EBP,0xff
    //         0046d424     CMP        EBP,dword ptr [EDI + 0xc]
    //         0046d427     JGE        LAB_0046d6f6
    //         0046d42d     CMP        AL,this
    //         0046d42f     MOV        byte ptr [ESP + maxY],AL
    //         0046d433     JA         LAB_0046d549
    //         0046d439     MOV        EAX,dword ptr [ESP + inObMap]
    //         0046d43d     MOV        EBP,dword ptr [ESP + param_2]
    //         0046d441     AND        EAX,0xff
    //         0046d446     LEA        this,[EAX + EAX*0x2]
    //         0046d449     SHL        this,0x3
    //         0046d44c     MOV        dword ptr [ESP + local_8],this
    //         0046d450     JMP        LAB_0046d456
    //                               LAB_0046d452                                                 XREF[1]:     0046d541(j)  
    //         0046d452     MOV        this,dword ptr [ESP + local_8]
    //                               LAB_0046d456                                                 XREF[1]:     0046d450(j)  
    //         0046d456     MOV        EAX,dword ptr [ESI + 0x11dc3c]
    //         0046d45c     MOV        EDI,dword ptr [ESP + maxY]
    //         0046d460     AND        EDI,0xff
    //         0046d466     MOV        byte ptr [ESP + local_14],BL
    //         0046d46a     MOV        EAX,dword ptr [EAX + 0x8d8c]
    //         0046d470     MOV        EAX,dword ptr [EAX + EDI*0x4]
    //         0046d473     ADD        EAX,this
    //         0046d475     CMP        BL,DL
    //         0046d477     JA         LAB_0046d531
    //         0046d47d     LEA        EDX,[EAX + 0x6]
    //                               LAB_0046d480                                                 XREF[1]:     0046d525(j)  
    //         0046d480     MOV        EAX,dword ptr [ESP + local_14]
    //         0046d484     MOV        this,dword ptr [ESI + 0x11dc7c]
    //         0046d48a     AND        EAX,0xff
    //         0046d48f     CMP        this,EAX
    //         0046d491     JNZ        LAB_0046d49b
    //         0046d493     CMP        dword ptr [ESI + 0x11dc80],EDI
    //         0046d499     JZ         LAB_0046d516
    //                               LAB_0046d49b                                                 XREF[1]:     0046d491(j)  
    //         0046d49b     MOV        this,byte ptr [EDX + -0x1]
    //         0046d49e     AND        this,0x1f
    //         0046d4a1     MOV        byte ptr [ESP + local_4],this
    //         0046d4a5     MOV        this,dword ptr [ESI + 0x11dc50]
    //         0046d4ab     MOV        EAX,dword ptr [ESP + local_4]
    //         0046d4af     AND        EAX,0xff
    //         0046d4b4     CMP        EAX,dword ptr [ESI + 0x11dc5c]
    //         0046d4ba     FLD        float ptr [this->_padding_ + EAX*0x4]
    //         0046d4bd     JZ         LAB_0046d730
    //         0046d4c3     CMP        EAX,dword ptr [ESI + 0x11dc60]
    //         0046d4c9     JZ         LAB_0046d730
    //         0046d4cf     FCOMP      double ptr [DAT_00570e80]
    //         0046d4d5     FNSTSW     AX
    //         0046d4d7     TEST       AH,0x41
    //         0046d4da     JZ         LAB_0046d516
    //         0046d4dc     MOV        AL,byte ptr [EDX]
    //         0046d4de     AND        EAX,0xf
    //         0046d4e1     JZ         LAB_0046d6f6
    //         0046d4e7     LEA        EAX,[EAX + EAX*0x4]
    //         0046d4ea     LEA        EBP,[EAX + EAX*0x8]
    //         0046d4ed     MOV        EAX,dword ptr [ESI + 0x11dc3c]
    //         0046d4f3     SHL        EBP,0x5
    //         0046d4f6     MOVSX      EAX,word ptr [EBP + EAX*0x1 + 0x3928]
    //         0046d4fe     FLD        float ptr [this->_padding_ + EAX*0x4]
    //         0046d501     FCOMP      double ptr [DAT_00570e80]
    //         0046d507     FNSTSW     AX
    //         0046d509     TEST       AH,0x41
    //         0046d50c     JNZ        LAB_0046d6f6
    //         0046d512     MOV        EBP,dword ptr [ESP + param_2]
    //                               LAB_0046d516                                                 XREF[3]:     0046d499(j), 0046d4da(j), 
    //                                                                                                         0046d732(j)  
    //         0046d516     MOV        AL,byte ptr [ESP + param_4]
    //         0046d51a     ADD        EDX,0x18
    //         0046d51d     INC        BL
    //         0046d51f     CMP        BL,AL
    //         0046d521     MOV        byte ptr [ESP + local_14],BL
    //         0046d525     JBE        LAB_0046d480
    //         0046d52b     MOV        BL,byte ptr [ESP + inObMap]
    //         0046d52f     MOV        DL,AL
    //                               LAB_0046d531                                                 XREF[1]:     0046d477(j)  
    //         0046d531     MOV        AL,byte ptr [ESP + maxY]
    //         0046d535     MOV        this,byte ptr [ESP + local_c]
    //         0046d539     INC        AL
    //         0046d53b     CMP        AL,this
    //         0046d53d     MOV        byte ptr [ESP + maxY],AL
    //         0046d541     JBE        LAB_0046d452
    //         0046d547     JMP        LAB_0046d54d
    //                               LAB_0046d549                                                 XREF[1]:     0046d433(j)  
    //         0046d549     MOV        EBP,dword ptr [ESP + param_2]
    //                               LAB_0046d54d                                                 XREF[1]:     0046d547(j)  
    //         0046d54d     MOV        EBX,dword ptr [ESP + local_18]
    //         0046d551     MOV        EDI,dword ptr [ESP + yRadius]
    //                               LAB_0046d555                                                 XREF[1]:     0046d3d9(j)  
    //                              pathsys.cpp:2167 (16)
    //         0046d555     MOV        this,dword ptr [ESI + 0x11dcf4]
    //         0046d55b     PUSH       this
    //         0046d55c     MOV        this,dword ptr [ESP + param_1]
    //         0046d560     CALL       RGE_Static_Object::removeFromObstructionMap      int removeFromObstructionMap(RGE_Static_Objec
    //                              pathsys.cpp:2169 (123)
    //         0046d565     MOV        this,EBX
    //         0046d567     MOV        dword ptr [ESP + local_c],EAX
    //         0046d56b     SUB        this,EDI
    //         0046d56d     MOV        dword ptr [ESP + param_4],0x0
    //         0046d575     DEC        this
    //         0046d576     JS         LAB_0046d702
    //         0046d57c     CMP        this,0x18
    //         0046d57f     JGE        LAB_0046d64d
    //         0046d585     CMP        EBP,dword ptr [ESI + 0x11dc8c]
    //         0046d58b     JG         LAB_0046d5af
    //         0046d58d     CMP        EDI,dword ptr [ESI + 0x11dc90]
    //         0046d593     JG         LAB_0046d5af
    //         0046d595     MOV        EDX,dword ptr [ESP + param_3]
    //         0046d599     MOV        EAX,dword ptr [ESI + 0x11dc84]
    //         0046d59f     CMP        EDX,EAX
    //         0046d5a1     JL         LAB_0046d5af
    //         0046d5a3     CMP        EBX,dword ptr [ESI + 0x11dc88]
    //         0046d5a9     JGE        LAB_0046d64d
    //                               LAB_0046d5af                                                 XREF[3]:     0046d58b(j), 0046d593(j), 
    //                                                                                                         0046d5a1(j)  
    //         0046d5af     MOV        EAX,EDI
    //         0046d5b1     AND        EAX,0x3
    //         0046d5b4     SAR        EDI,0x2
    //         0046d5b7     LEA        this,[EAX + this->_padding_*0x4]
    //         0046d5ba     SHL        this,0x1
    //         0046d5bc     MOV        EAX,dword ptr [this->_padding_*0x4 + DAT_00584   = align(4)
    //         0046d5c3     MOV        EBX,dword ptr [this->_padding_*0x4 + Obstructi   = 00000003
    //         0046d5ca     TEST       EAX,EAX
    //         0046d5cc     MOV        dword ptr [ESP + param_2],EBX
    //         0046d5d0     JNZ        LAB_0046d608
    //         0046d5d2     MOV        EAX,dword ptr [ESP + param_3]
    //         0046d5d6     MOV        this,EBP
    //         0046d5d8     CMP        EBP,EAX
    //         0046d5da     JGE        LAB_0046d702
    //                              pathsys.cpp:2217 (40)
    //         0046d5e0     MOV        EDX,EBP
    //         0046d5e2     SHL        EDX,0x8
    //         0046d5e5     SUB        EDX,EBP
    //         0046d5e7     ADD        EDX,EDI
    //         0046d5e9     LEA        EDX,[EDX + ESI*0x1 + 0xce624]
    //                               LAB_0046d5f0                                                 XREF[1]:     0046d601(j)  
    //         0046d5f0     TEST       dword ptr [EDX],EBX
    //         0046d5f2     JNZ        LAB_0046d6d7
    //         0046d5f8     INC        this
    //         0046d5f9     ADD        EDX,0xff
    //         0046d5ff     CMP        this,EAX
    //         0046d601     JL         LAB_0046d5f0
    //         0046d603     JMP        LAB_0046d702
    //                               LAB_0046d608                                                 XREF[1]:     0046d5d0(j)  
    //                              pathsys.cpp:2169 (14)
    //         0046d608     MOV        EBX,dword ptr [ESP + param_3]
    //         0046d60c     MOV        EDX,EBP
    //         0046d60e     CMP        EBP,EBX
    //         0046d610     JGE        LAB_0046d702
    //                              pathsys.cpp:2217 (55)
    //         0046d616     MOV        this,EBP
    //         0046d618     SHL        this,0x8
    //         0046d61b     SUB        this,EBP
    //         0046d61d     ADD        this,EDI
    //         0046d61f     LEA        this,[ECX + ESI*0x1 + this->obstructionValue[0
    //                               LAB_0046d626                                                 XREF[1]:     0046d646(j)  
    //         0046d626     MOV        EDI,dword ptr [ESP + param_2]
    //         0046d62a     MOV        EBP,dword ptr [this->_padding_]
    //         0046d62c     TEST       EBP,EDI
    //         0046d62e     JNZ        LAB_0046d6d7
    //         0046d634     TEST       dword ptr [ECX + this->xSizeValue],EAX
    //         0046d637     JNZ        LAB_0046d6d7
    //         0046d63d     INC        EDX
    //         0046d63e     ADD        this,0xff
    //         0046d644     CMP        EDX,EBX
    //         0046d646     JL         LAB_0046d626
    //         0046d648     JMP        LAB_0046d702
    //                               LAB_0046d64d                                                 XREF[2]:     0046d57f(j), 0046d5a9(j)  
    //                              pathsys.cpp:2169 (138)
    //         0046d64d     CMP        EBP,dword ptr [ESP + param_3]
    //         0046d651     JGE        LAB_0046d6d0
    //         0046d653     MOV        EAX,EBP
    //         0046d655     SHL        EAX,0x8
    //         0046d658     SUB        EAX,EBP
    //                               LAB_0046d65a                                                 XREF[1]:     0046d6ce(j)  
    //         0046d65a     CMP        EDI,EBX
    //         0046d65c     MOV        EDX,EDI
    //         0046d65e     JGE        LAB_0046d6c2
    //                               LAB_0046d660                                                 XREF[1]:     0046d6c0(j)  
    //         0046d660     MOV        this,EDX
    //         0046d662     MOV        EBX,EDX
    //         0046d664     SAR        this,0x2
    //         0046d667     ADD        this,ESI
    //         0046d669     AND        EBX,0x3
    //         0046d66c     MOV        this,byte ptr [ECX + EAX*0x1 + this->obstructi
    //         0046d673     MOV        byte ptr [ESP + param_2],this
    //         0046d677     MOV        this,byte ptr [EBX + ObstructionValueShift]      = 06040200
    //         0046d67d     MOV        BL,byte ptr [ESP + param_2]
    //         0046d681     SHR        BL,this
    //         0046d683     TEST       BL,0x3
    //         0046d686     JBE        LAB_0046d6b9
    //         0046d688     CMP        dword ptr [ESI + 0x11dc4c],-0x1
    //         0046d68f     JZ         LAB_0046d6d7
    //         0046d691     CMP        dword ptr [ESI + 0x11dc84],EBP
    //         0046d697     JG         LAB_0046d6d7
    //         0046d699     CMP        EBP,dword ptr [ESI + 0x11dc8c]
    //         0046d69f     JG         LAB_0046d6d7
    //         0046d6a1     CMP        dword ptr [ESI + 0x11dc88],EDX
    //         0046d6a7     JG         LAB_0046d6d7
    //         0046d6a9     CMP        EDX,dword ptr [ESI + 0x11dc90]
    //         0046d6af     JG         LAB_0046d6d7
    //         0046d6b1     MOV        dword ptr [ESP + param_4],0x1
    //                               LAB_0046d6b9                                                 XREF[1]:     0046d686(j)  
    //         0046d6b9     MOV        EBX,dword ptr [ESP + local_18]
    //         0046d6bd     INC        EDX
    //         0046d6be     CMP        EDX,EBX
    //         0046d6c0     JL         LAB_0046d660
    //                               LAB_0046d6c2                                                 XREF[1]:     0046d65e(j)  
    //         0046d6c2     MOV        this,dword ptr [ESP + param_3]
    //         0046d6c6     INC        EBP
    //         0046d6c7     ADD        EAX,0xff
    //         0046d6cc     CMP        EBP,this
    //         0046d6ce     JL         LAB_0046d65a
    //                               LAB_0046d6d0                                                 XREF[1]:     0046d651(j)  
    //         0046d6d0     CMP        dword ptr [ESP + param_4],0x1
    //         0046d6d5     JNZ        LAB_0046d702
    //                               LAB_0046d6d7                                                 XREF[8]:     0046d5f2(j), 0046d62e(j), 
    //                                                                                                         0046d637(j), 0046d68f(j), 
    //                                                                                                         0046d697(j), 0046d69f(j), 
    //                                                                                                         0046d6a7(j), 0046d6af(j)  
    //                              pathsys.cpp:2174 (19)
    //         0046d6d7     MOV        EAX,dword ptr [ESP + local_c]
    //         0046d6db     TEST       EAX,EAX
    //         0046d6dd     JZ         LAB_0046d6f6
    //         0046d6df     MOV        this,dword ptr [ESP + param_1]
    //         0046d6e3     MOV        EAX,dword ptr [ECX + this+0x20]
    //         0046d6e6     TEST       EAX,EAX
    //         0046d6e8     JNZ        LAB_0046d6f6
    //                              pathsys.cpp:2175 (12)
    //         0046d6ea     MOV        EDX,dword ptr [ESI + 0x11dcf4]
    //         0046d6f0     PUSH       EDX
    //         0046d6f1     CALL       RGE_Static_Object::addToObstructionMap           int addToObstructionMap(RGE_Static_Object * t
    //                               LAB_0046d6f6                                                 XREF[6]:     0046d414(j), 0046d427(j), 
    //                                                                                                         0046d4e1(j), 0046d50c(j), 
    //                                                                                                         0046d6dd(j), 0046d6e8(j)  
    //                              pathsys.cpp:2193 (2)
    //         0046d6f6     XOR        EAX,EAX
    //                              pathsys.cpp:2217 (10)
    //         0046d6f8     POP        EDI
    //         0046d6f9     POP        ESI
    //         0046d6fa     POP        EBP
    //         0046d6fb     POP        EBX
    //         0046d6fc     ADD        ESP,0x20
    //         0046d6ff     RET        0x10
    //                               LAB_0046d702                                                 XREF[6]:     0046d576(j), 0046d5da(j), 
    //                                                                                                         0046d603(j), 0046d610(j), 
    //                                                                                                         0046d648(j), 0046d6d5(j)  
    //                              pathsys.cpp:2197 (19)
    //         0046d702     MOV        EAX,dword ptr [ESP + local_c]
    //         0046d706     TEST       EAX,EAX
    //         0046d708     JZ         LAB_0046d721
    //         0046d70a     MOV        this,dword ptr [ESP + param_1]
    //         0046d70e     MOV        EAX,dword ptr [ECX + this+0x20]
    //         0046d711     TEST       EAX,EAX
    //         0046d713     JNZ        LAB_0046d721
    //                              pathsys.cpp:2198 (12)
    //         0046d715     MOV        EAX,dword ptr [ESI + 0x11dcf4]
    //         0046d71b     PUSH       EAX
    //         0046d71c     CALL       RGE_Static_Object::addToObstructionMap           int addToObstructionMap(RGE_Static_Object * t
    //                               LAB_0046d721                                                 XREF[2]:     0046d708(j), 0046d713(j)  
    //                              pathsys.cpp:2217 (15)
    //         0046d721     POP        EDI
    //         0046d722     POP        ESI
    //         0046d723     POP        EBP
    //         0046d724     MOV        EAX,0x1
    //         0046d729     POP        EBX
    //         0046d72a     ADD        ESP,0x20
    //         0046d72d     RET        0x10
    //                               LAB_0046d730                                                 XREF[2]:     0046d4bd(j), 0046d4c9(j)  
    //                              pathsys.cpp:2141 (7)
    //         0046d730     FSTP       ST0
    //         0046d732     JMP        LAB_0046d516
    //         0046d737     ??         90h
    //         0046d738     NOP
    //         0046d739     NOP
    //         0046d73a     NOP
    //         0046d73b     NOP
    //         0046d73c     NOP
    //         0046d73d     NOP
    //         0046d73e     NOP
    //         0046d73f     NOP
    return 0;
}

long PathingSystem::checksum() {
    /* TODO: Stub */
    //                              long __thiscall checksum(PathingSystem * this)
    //              long              EAX:4          <RETURN>
    //              PathingSystem *   ECX:4 (auto)   this
    //                               ?checksum@PathingSystem@@QAEJXZ                              XREF[1]:     DoChecksum:004333be(c)  
    //                               PathingSystem::checksum
    //                              pathsys.cpp:2222 (2)
    //         0046d740     PUSH       ESI
    //         0046d741     PUSH       EDI
    //                              pathsys.cpp:2223 (13)
    //         0046d742     XOR        ESI,ESI
    //         0046d744     LEA        EDX,[ECX + this->obstructionValue[0][0]]
    //         0046d74a     MOV        EDI,0x3fc
    //                               LAB_0046d74f                                                 XREF[1]:     0046d768(j)  
    //                              pathsys.cpp:2225 (2)
    //         0046d74f     XOR        this,this
    //                               LAB_0046d751                                                 XREF[1]:     0046d75f(j)  
    //                              pathsys.cpp:2226 (25)
    //         0046d751     XOR        EAX,EAX
    //         0046d753     MOV        AL,byte ptr [this->_padding_ + EDX*0x1]
    //         0046d756     XOR        ESI,EAX
    //         0046d758     INC        this
    //         0046d759     CMP        this,0xff
    //         0046d75f     JL         LAB_0046d751
    //         0046d761     ADD        EDX,0xff
    //         0046d767     DEC        EDI
    //         0046d768     JNZ        LAB_0046d74f
    //                              pathsys.cpp:2227 (2)
    //         0046d76a     MOV        EAX,ESI
    //                              pathsys.cpp:2228 (3)
    //         0046d76c     POP        EDI
    //         0046d76d     POP        ESI
    //         0046d76e     RET
    //         0046d76f     ??         90h
    return 0;
}

void PathingSystem::printState(RGE_Moving_Object* param_1) {
    /* TODO: Stub */
    //                              void __thiscall printState(PathingSystem * this, RGE_Moving_Object *
    //              void              <VOID>         <RETURN>
    //              PathingSystem *   ECX:4 (auto)   this
    //              RGE_Moving_Obj    Stack[0x4]:4   param_1                   XREF[1]:     0046d775(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0046d798(W)  
    //                               ?printState@PathingSystem@@IAEXPAVRGE_Moving_Object@@@Z
    //                               PathingSystem::printState
    //                              pathsys.cpp:2233 (5)
    //         0046d770     SUB        ESP,0x8
    //         0046d773     PUSH       EBP
    //         0046d774     PUSH       ESI
    //                              pathsys.cpp:2235 (44)
    //         0046d775     MOV        ESI,dword ptr [ESP + param_1]
    //         0046d779     MOV        EBP,this
    //         0046d77b     PUSH       EDI
    //         0046d77c     MOV        this,dword ptr [EBP + 0x11dc38]
    //         0046d782     MOV        EAX,dword ptr [ESI]
    //         0046d784     MOV        EDX,dword ptr [EBP + 0x11dc2c]
    //         0046d78a     PUSH       this
    //         0046d78b     MOV        EDI,dword ptr [EAX + 0x144]
    //         0046d791     PUSH       EDX
    //         0046d792     PUSH       s_____There_are_%d_open_paths_and_               = "    There are %d open paths and %d travers
    //         0046d797     PUSH       ESI
    //         0046d798     MOV        dword ptr [ESP + local_4],EDI
    //         0046d79c     CALL       EDI
    //         0046d79e     ADD        ESP,0x10
    //                              pathsys.cpp:2236 (8)
    //         0046d7a1     PUSH       s_____The_open_paths:                            = "    The open paths:"
    //         0046d7a6     PUSH       ESI
    //         0046d7a7     CALL       EDI
    //                              pathsys.cpp:2237 (25)
    //         0046d7a9     MOV        EAX,dword ptr [EBP + 0x11dc2c]
    //         0046d7af     MOV        EDI,0x1
    //         0046d7b4     ADD        ESP,0x8
    //         0046d7b7     CMP        EAX,EDI
    //         0046d7b9     JL         LAB_0046d825
    //         0046d7bb     PUSH       EBX
    //         0046d7bc     LEA        ESI,[EBP + 0x4f61d]
    //                               LAB_0046d7c2                                                 XREF[1]:     0046d822(j)  
    //                              pathsys.cpp:2241 (98)
    //         0046d7c2     XOR        EAX,EAX
    //         0046d7c4     XOR        this,this
    //         0046d7c6     MOV        AL,byte ptr [ESI + -0x1]
    //         0046d7c9     MOV        this,byte ptr [ESI]
    //         0046d7cb     MOV        EDX,EAX
    //         0046d7cd     SHL        EDX,0x8
    //         0046d7d0     SUB        EDX,EAX
    //         0046d7d2     ADD        EDX,EBP
    //         0046d7d4     MOV        DL,byte ptr [EDX + this->_padding_*0x1 + 0xc]
    //         0046d7d8     MOV        BL,DL
    //         0046d7da     AND        BL,0xf8
    //         0046d7dd     CMP        BL,byte ptr [EBP + 0x11dcd8]
    //         0046d7e3     JNZ        LAB_0046d7ee
    //         0046d7e5     AND        DL,0x7
    //         0046d7e8     MOV        byte ptr [ESP + 0x10],DL
    //         0046d7ec     JMP        LAB_0046d7f3
    //                               LAB_0046d7ee                                                 XREF[1]:     0046d7e3(j)  
    //         0046d7ee     MOV        byte ptr [ESP + 0x10],0xff
    //                               LAB_0046d7f3                                                 XREF[1]:     0046d7ec(j)  
    //         0046d7f3     MOV        EDX,dword ptr [ESP + 0x10]
    //         0046d7f7     AND        EDX,0xff
    //         0046d7fd     PUSH       EDX
    //         0046d7fe     MOV        EDX,dword ptr [ESI + 0x3]
    //         0046d801     PUSH       EDX
    //         0046d802     PUSH       this=>DAT_fffffff8
    //         0046d803     PUSH       EAX=>DAT_fffffff4
    //         0046d804     MOV        EAX,dword ptr [ESP + 0x2c]
    //         0046d808     PUSH       EDI=>DAT_fffffff0
    //         0046d809     PUSH       s_______%5d:_(%d,_%d),_total=%d,_f               = "      %5d: (%d, %d), total=%d, facet=%d."
    //         0046d80e     PUSH       EAX
    //         0046d80f     CALL       dword ptr [ESP + 0x30]
    //         0046d813     MOV        EAX,dword ptr [EBP + 0x11dc2c]
    //         0046d819     ADD        ESP,0x1c
    //         0046d81c     INC        EDI
    //         0046d81d     ADD        ESI,0x8
    //         0046d820     CMP        EDI,EAX
    //         0046d822     JLE        LAB_0046d7c2
    //                              pathsys.cpp:2233 (1)
    //         0046d824     POP        EBX
    //                               LAB_0046d825                                                 XREF[1]:     0046d7b9(j)  
    //                              pathsys.cpp:2242 (9)
    //         0046d825     POP        EDI
    //         0046d826     POP        ESI
    //         0046d827     POP        EBP
    //         0046d828     ADD        ESP,0x8
    //         0046d82b     RET        0x4
    //         0046d82e     ??         90h
    //         0046d82f     NOP
    return;
}

int PathingSystem::copyPath(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall copyPath(PathingSystem * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              PathingSystem *   ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[8]:     0046db0e(R), 0046db2b(R), 0046db3b(R), 0046db55(R), 
    //                                                                                     0046db65(R), 0046db7f(R), 0046db8f(R), 0046dba9(R)  
    //              undefined1        Stack[-0x4]:1  local_4                   XREF[2]:     0046d8e3(W), 0046dc0c(W)  
    //              Waypoint          Stack[-0x14]   wp                        XREF[0,9]:   0046d8d8(W), 0046d930(*), 0046d94a(*), 0046dc20(W), 
    //                                                                                     0046dc3d(*), 0046dc5b(*), 0046d8dc(W), 0046dc24(W), 
    //                                                                                     0046d8e7(W)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[15,15]: 0046d866(W), 0046d86e(R), 0046db12(R), 0046db1e(W), 
    //                                                                                     0046db3f(R), 0046db4b(W), 0046db59(R), 0046db5f(W), 
    //                                                                                     0046db69(R), 0046db75(W), 0046db93(R), 0046db9f(W), 
    //                                                                                     0046dbad(R), 0046dbb3(W), 0046dbb7(R), 0046d86a(W), 
    //                                                                                     0046d872(R), 0046db16(R), 0046db22(W), 0046db2f(R)  
    //              BYTEPoint         Stack[-0x1c]:2 temp                      XREF[2]:     0046d9ef(*), 0046d9f3(W)  
    //              int               Stack[-0x20]:4 objectCountOnTile         XREF[3]:     0046d9db(W), 0046dabb(R), 0046dad6(W)  
    //              int               Stack[-0x24]:4 fooY                      XREF[8]:     0046d88c(W), 0046d8ba(R), 0046d9c5(W), 0046d9e5(R), 
    //                                                                                     0046dae0(R), 0046daeb(W), 0046dbde(W), 0046dc04(R)  
    //              int               Stack[-0x28]:4 fooX                      XREF[8]:     0046d892(W), 0046d8b6(R), 0046d997(W), 0046d9a2(W), 
    //                                                                                     0046d9b9(W), 0046d9d1(R), 0046dbe2(W), 0046dc00(R)  
    //              int               Stack[-0x2c]:4 tWY1                      XREF[5]:     0046d975(W), 0046d97e(W), 0046d98d(W), 0046d9c1(R), 
    //                                                                                     0046dae4(R)  
    //              int               Stack[-0x30]:4 tWX2                      XREF[5]:     0046d99b(W), 0046d9aa(W), 0046d9bd(W), 0046d9d5(R), 
    //                                                                                     0046dacf(R)  
    //              int               Stack[-0x34]:4 tWY2                      XREF[9]:     0046d8ab(W), 0046d8b1(W), 0046d8c4(R), 0046d91a(R), 
    //                                                                                     0046daf5(R), 0046dbd8(R), 0046dbf5(W), 0046dbfb(W), 
    //                                                                                     0046dc08(R)  
    //              uchar             Stack[-0x38]:1 currentFacet
    //                               ?copyPath@PathingSystem@@IAEHH@Z                             XREF[3]:     findTilePath:0046cadd(c), 
    //                               PathingSystem::copyPath                                                   findTilePath:0046ccd0(c), 
    //                                                                                                         findTilePath:0046cfce(c)  
    //                              pathsys.cpp:2249 (9)
    //         0046d830     SUB        ESP,0x34
    //         0046d833     PUSH       EBX
    //         0046d834     PUSH       EBP
    //         0046d835     PUSH       ESI
    //         0046d836     MOV        ESI,this
    //         0046d838     PUSH       EDI
    //                              pathsys.cpp:2255 (14)
    //         0046d839     MOV        EAX,dword ptr [ESI + 0x11dc44]
    //         0046d83f     MOV        this,byte ptr [EAX + 0x154]
    //         0046d845     TEST       this,this
    //                              pathsys.cpp:2256 (8)
    //         0046d847     LEA        this,[EAX + 0xa4]
    //         0046d84d     JZ         LAB_0046d855
    //                              pathsys.cpp:2258 (11)
    //         0046d84f     LEA        this,[EAX + 0xd8]
    //                               LAB_0046d855                                                 XREF[1]:     0046d84d(j)  
    //         0046d855     CALL       Path::killPath                                   void killPath(Path * this)
    //                              pathsys.cpp:2262 (6)
    //         0046d85a     MOV        AL,byte ptr [ESI + 0x4f61c]
    //                              pathsys.cpp:2263 (14)
    //         0046d860     MOV        this,byte ptr [ESI + 0x4f61d]
    //         0046d866     MOV        byte ptr [ESP + local_18],AL
    //         0046d86a     MOV        byte ptr [ESP + local_18+0x1],this
    //                              pathsys.cpp:2266 (72)
    //         0046d86e     MOV        EDI,dword ptr [ESP + local_18]
    //         0046d872     MOV        EBP,dword ptr [ESP + local_18+0x1]
    //         0046d876     AND        EDI,0xff
    //         0046d87c     AND        EBP,0xff
    //         0046d882     MOV        EDX,EDI
    //         0046d884     OR         BL,0xff
    //         0046d887     SHL        EDX,0x8
    //         0046d88a     SUB        EDX,EDI
    //         0046d88c     MOV        dword ptr [ESP + fooY],EDI
    //         0046d890     ADD        EDX,ESI
    //         0046d892     MOV        dword ptr [ESP + fooX],EBP
    //         0046d896     MOV        AL,byte ptr [EDX + EBP*0x1 + 0xc]
    //         0046d89a     MOV        DL,byte ptr [ESI + 0x11dcd8]
    //         0046d8a0     MOV        this,AL
    //         0046d8a2     AND        this,0xf8
    //         0046d8a5     CMP        this,DL
    //         0046d8a7     JNZ        LAB_0046d8b1
    //         0046d8a9     AND        AL,0x7
    //         0046d8ab     MOV        byte ptr [ESP + tWY2],AL
    //         0046d8af     JMP        LAB_0046d8b6
    //                               LAB_0046d8b1                                                 XREF[1]:     0046d8a7(j)  
    //         0046d8b1     MOV        byte ptr [ESP + tWY2],0xff
    //                               LAB_0046d8b6                                                 XREF[1]:     0046d8af(j)  
    //                              pathsys.cpp:2275 (8)
    //         0046d8b6     FILD       dword ptr [ESP + fooX]
    //         0046d8ba     FILD       dword ptr [ESP + fooY]
    //                              pathsys.cpp:2276 (6)
    //         0046d8be     MOV        EAX,dword ptr [ESI + 0x11dc44]
    //                              pathsys.cpp:2277 (39)
    //         0046d8c4     MOV        this,byte ptr [ESP + tWY2]
    //         0046d8c8     FADD       float ptr [ESI + 0x11dc54]
    //         0046d8ce     FXCH
    //         0046d8d0     FADD       float ptr [ESI + 0x11dc58]
    //         0046d8d6     FXCH
    //         0046d8d8     FSTP       float ptr [ESP + wp.y]
    //         0046d8dc     FSTP       float ptr [ESP + wp.z]
    //         0046d8e0     MOV        EDX,dword ptr [EAX + 0x40]
    //         0046d8e3     MOV        byte ptr [ESP + local_4],this
    //         0046d8e7     MOV        dword ptr [ESP + wp.facetToNextWaypoint],EDX
    //                              pathsys.cpp:2279 (8)
    //         0046d8eb     MOV        this,byte ptr [EAX + 0x154]
    //         0046d8f1     TEST       this,this
    //                              pathsys.cpp:2280 (8)
    //         0046d8f3     LEA        this,[EAX + 0xa4]
    //         0046d8f9     JZ         LAB_0046d901
    //                              pathsys.cpp:2282 (11)
    //         0046d8fb     LEA        this,[EAX + 0xd8]
    //                               LAB_0046d901                                                 XREF[1]:     0046d8f9(j)  
    //         0046d901     CALL       Path::initToStart                                void initToStart(Path * this)
    //                               LAB_0046d906                                                 XREF[1]:     0046dc28(j)  
    //                              pathsys.cpp:2284 (20)
    //         0046d906     CMP        dword ptr [ESI + 0x11dc7c],EDI
    //         0046d90c     JNZ        LAB_0046d91a
    //         0046d90e     CMP        dword ptr [ESI + 0x11dc80],EBP
    //         0046d914     JZ         LAB_0046dc2d
    //                               LAB_0046d91a                                                 XREF[1]:     0046d90c(j)  
    //                              pathsys.cpp:2289 (6)
    //         0046d91a     CMP        byte ptr [ESP + tWY2],BL
    //         0046d91e     JZ         LAB_0046d962
    //                              pathsys.cpp:2295 (16)
    //         0046d920     MOV        EAX,dword ptr [ESI + 0x11dc44]
    //         0046d926     MOV        this,byte ptr [EAX + 0x154]
    //         0046d92c     TEST       this,this
    //         0046d92e     JNZ        LAB_0046d94a
    //                              pathsys.cpp:2297 (24)
    //         0046d930     LEA        EDX=>wp.y,[ESP + 0x34]
    //         0046d934     LEA        this,[EAX + 0xa4]
    //         0046d93a     PUSH       EDX
    //         0046d93b     CALL       Path::insertAtCurrent                            int insertAtCurrent(Path * this, Waypoint * p
    //         0046d940     TEST       EAX,EAX
    //         0046d942     JZ         LAB_0046dc7e
    //                              pathsys.cpp:2300 (2)
    //         0046d948     JMP        LAB_0046d962
    //                               LAB_0046d94a                                                 XREF[1]:     0046d92e(j)  
    //                              pathsys.cpp:2302 (24)
    //         0046d94a     LEA        this=>wp.y,[ESP + 0x34]
    //         0046d94e     PUSH       this
    //         0046d94f     LEA        this,[EAX + 0xd8]
    //         0046d955     CALL       Path::insertAtCurrent                            int insertAtCurrent(Path * this, Waypoint * p
    //         0046d95a     TEST       EAX,EAX
    //         0046d95c     JZ         LAB_0046dc7e
    //                               LAB_0046d962                                                 XREF[2]:     0046d91e(j), 0046d948(j)  
    //                              pathsys.cpp:2309 (13)
    //         0046d962     CMP        dword ptr [ESI + 0x11dcdc],-0x1
    //         0046d969     JZ         LAB_0046daf5
    //                              pathsys.cpp:2312 (3)
    //         0046d96f     LEA        EAX,[EDI + -0x1]
    //                              pathsys.cpp:2313 (1)
    //         0046d972     INC        EDI
    //                              pathsys.cpp:2317 (8)
    //         0046d973     TEST       EAX,EAX
    //         0046d975     MOV        dword ptr [ESP + tWY1],EDI
    //         0046d979     JGE        LAB_0046d984
    //                              pathsys.cpp:2320 (2)
    //         0046d97b     XOR        EAX,EAX
    //                              pathsys.cpp:2321 (5)
    //         0046d97d     INC        EDI
    //         0046d97e     MOV        dword ptr [ESP + tWY1],EDI
    //                              pathsys.cpp:2326 (9)
    //         0046d982     JMP        LAB_0046d991
    //                               LAB_0046d984                                                 XREF[1]:     0046d979(j)  
    //         0046d984     MOV        this,dword ptr [ESI + 0x4]
    //         0046d987     CMP        EDI,this
    //         0046d989     JL         LAB_0046d991
    //                              pathsys.cpp:2329 (1)
    //         0046d98b     DEC        EAX
    //                              pathsys.cpp:2330 (5)
    //         0046d98c     DEC        this
    //         0046d98d     MOV        dword ptr [ESP + tWY1],this
    //                               LAB_0046d991                                                 XREF[2]:     0046d982(j), 0046d989(j)  
    //                              pathsys.cpp:2335 (3)
    //         0046d991     LEA        EDX,[EBP + -0x1]
    //                              pathsys.cpp:2336 (1)
    //         0046d994     INC        EBP
    //                              pathsys.cpp:2340 (12)
    //         0046d995     TEST       EDX,EDX
    //         0046d997     MOV        dword ptr [ESP + fooX],EDX
    //         0046d99b     MOV        dword ptr [ESP + tWX2],EBP
    //         0046d99f     JGE        LAB_0046d9b0
    //                              pathsys.cpp:2344 (13)
    //         0046d9a1     INC        EBP
    //         0046d9a2     MOV        dword ptr [ESP + fooX],0x0
    //         0046d9aa     MOV        dword ptr [ESP + tWX2],EBP
    //                              pathsys.cpp:2349 (9)
    //         0046d9ae     JMP        LAB_0046d9c1
    //                               LAB_0046d9b0                                                 XREF[1]:     0046d99f(j)  
    //         0046d9b0     MOV        this,dword ptr [ESI + 0x8]
    //         0046d9b3     CMP        EBP,this
    //         0046d9b5     JL         LAB_0046d9c1
    //                              pathsys.cpp:2352 (1)
    //         0046d9b7     DEC        EDX
    //                              pathsys.cpp:2353 (9)
    //         0046d9b8     DEC        this
    //         0046d9b9     MOV        dword ptr [ESP + fooX],EDX
    //         0046d9bd     MOV        dword ptr [ESP + tWX2],this
    //                               LAB_0046d9c1                                                 XREF[2]:     0046d9ae(j), 0046d9b5(j)  
    //                              pathsys.cpp:2364 (16)
    //         0046d9c1     MOV        this,dword ptr [ESP + tWY1]
    //         0046d9c5     MOV        dword ptr [ESP + fooY],EAX
    //         0046d9c9     CMP        EAX,this
    //         0046d9cb     JG         LAB_0046daf5
    //                               LAB_0046d9d1                                                 XREF[1]:     0046daef(j)  
    //                              pathsys.cpp:2365 (20)
    //         0046d9d1     MOV        EDI,dword ptr [ESP + fooX]
    //         0046d9d5     MOV        EAX,dword ptr [ESP + tWX2]
    //         0046d9d9     CMP        EDI,EAX
    //         0046d9db     MOV        dword ptr [ESP + objectCountOnTile],EDI
    //         0046d9df     JG         LAB_0046dae0
    //                               LAB_0046d9e5                                                 XREF[1]:     0046dada(j)  
    //                              pathsys.cpp:2368 (46)
    //         0046d9e5     MOV        EAX,dword ptr [ESP + fooY]
    //         0046d9e9     MOV        this,dword ptr [ESI + 0x11dcdc]
    //         0046d9ef     LEA        EDX=>temp,[ESP + 0x28]
    //         0046d9f3     MOV        dword ptr [ESP + temp.x],0x0
    //         0046d9fb     PUSH       EDX
    //         0046d9fc     MOV        EDX,dword ptr [ESI + 0x11dce0]
    //         0046da02     PUSH       EDI
    //         0046da03     PUSH       EAX
    //         0046da04     PUSH       this
    //         0046da05     MOV        this,dword ptr [ESI + 0x11dc40]
    //         0046da0b     PUSH       EDX
    //         0046da0c     CALL       RGE_Game_World::objectGroupOnTile                int objectGroupOnTile(RGE_Game_World * this, 
    //         0046da11     MOV        EBX,EAX
    //                              pathsys.cpp:2372 (9)
    //         0046da13     CMP        EBX,-0x1
    //         0046da16     JZ         LAB_0046dacf
    //                              pathsys.cpp:2373 (196)
    //         0046da1c     MOV        this,dword ptr [ESI + 0x11dce8]
    //         0046da22     XOR        EAX,EAX
    //         0046da24     TEST       this,this
    //         0046da26     JLE        LAB_0046da47
    //         0046da28     MOV        EDX,dword ptr [ESI + 0x11dcf0]
    //                               LAB_0046da2e                                                 XREF[1]:     0046da45(j)  
    //         0046da2e     CMP        EAX,EDX
    //         0046da30     JGE        LAB_0046da47
    //         0046da32     MOV        EBP,dword ptr [ESI + 0x11dce4]
    //         0046da38     CMP        dword ptr [EBP + EAX*0x4],EBX
    //         0046da3c     JZ         LAB_0046dacf
    //         0046da42     INC        EAX
    //         0046da43     CMP        EAX,this
    //         0046da45     JL         LAB_0046da2e
    //                               LAB_0046da47                                                 XREF[2]:     0046da26(j), 0046da30(j)  
    //         0046da47     MOV        EAX,dword ptr [ESI + 0x11dcf0]
    //         0046da4d     DEC        EAX
    //         0046da4e     CMP        this,EAX
    //         0046da50     JLE        LAB_0046daaf
    //         0046da52     LEA        EBP,[ECX + this+0x1]
    //         0046da55     LEA        this,[EBP*0x4 + 0x0]
    //         0046da5c     PUSH       this
    //         0046da5d     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0046da62     MOV        EDI,EAX
    //         0046da64     ADD        ESP,0x4
    //         0046da67     TEST       EDI,EDI
    //         0046da69     JZ         LAB_0046daaf
    //         0046da6b     MOV        this,dword ptr [ESI + 0x11dcf0]
    //         0046da71     XOR        EAX,EAX
    //         0046da73     TEST       this,this
    //         0046da75     JLE        LAB_0046da94
    //                               LAB_0046da77                                                 XREF[1]:     0046da92(j)  
    //         0046da77     CMP        EAX,EBP
    //         0046da79     JGE        LAB_0046da94
    //         0046da7b     MOV        EDX,dword ptr [ESI + 0x11dce4]
    //         0046da81     INC        EAX
    //         0046da82     MOV        this,dword ptr [EDX + EAX*0x4 + -0x4]
    //         0046da86     MOV        dword ptr [EDI + EAX*0x4 + -0x4],this
    //         0046da8a     MOV        this,dword ptr [ESI + 0x11dcf0]
    //         0046da90     CMP        EAX,this
    //         0046da92     JL         LAB_0046da77
    //                               LAB_0046da94                                                 XREF[2]:     0046da75(j), 0046da79(j)  
    //         0046da94     MOV        EDX,dword ptr [ESI + 0x11dce4]
    //         0046da9a     PUSH       EDX
    //         0046da9b     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0046daa0     ADD        ESP,0x4
    //         0046daa3     MOV        dword ptr [ESI + 0x11dce4],EDI
    //         0046daa9     MOV        dword ptr [ESI + 0x11dcf0],EBP
    //                               LAB_0046daaf                                                 XREF[2]:     0046da50(j), 0046da69(j)  
    //         0046daaf     MOV        EAX,dword ptr [ESI + 0x11dce8]
    //         0046dab5     MOV        this,dword ptr [ESI + 0x11dce4]
    //         0046dabb     MOV        EDI,dword ptr [ESP + objectCountOnTile]
    //         0046dabf     MOV        dword ptr [this->_padding_ + EAX*0x4],EBX
    //         0046dac2     MOV        EAX,dword ptr [ESI + 0x11dce8]
    //         0046dac8     INC        EAX
    //         0046dac9     MOV        dword ptr [ESI + 0x11dce8],EAX
    //                               LAB_0046dacf                                                 XREF[2]:     0046da16(j), 0046da3c(j)  
    //         0046dacf     MOV        EAX,dword ptr [ESP + tWX2]
    //         0046dad3     INC        EDI
    //         0046dad4     CMP        EDI,EAX
    //         0046dad6     MOV        dword ptr [ESP + objectCountOnTile],EDI
    //         0046dada     JLE        LAB_0046d9e5
    //                               LAB_0046dae0                                                 XREF[1]:     0046d9df(j)  
    //                              pathsys.cpp:2364 (21)
    //         0046dae0     MOV        EAX,dword ptr [ESP + fooY]
    //         0046dae4     MOV        this,dword ptr [ESP + tWY1]
    //         0046dae8     INC        EAX
    //         0046dae9     CMP        EAX,this
    //         0046daeb     MOV        dword ptr [ESP + fooY],EAX
    //         0046daef     JLE        LAB_0046d9d1
    //                               LAB_0046daf5                                                 XREF[2]:     0046d969(j), 0046d9cb(j)  
    //                              pathsys.cpp:2380 (25)
    //         0046daf5     MOV        EAX,dword ptr [ESP + tWY2]
    //         0046daf9     AND        EAX,0xff
    //         0046dafe     CMP        EAX,0x7
    //         0046db01     JA         switchD_0046db07::default
    //                               switchD_0046db07::switchD
    //         0046db07     JMP        dword ptr [EAX*0x4 + switchD_0046db07::switchd   = 0046db0e
    //                               switchD_0046db07::caseD_0                                    XREF[2]:     0046db07(j), 0046dc8c(*)  
    //                              pathsys.cpp:2382 (29)
    //         0046db0e     MOV        AL,byte ptr [ESP + param_1]
    //         0046db12     MOV        DL,byte ptr [ESP + local_18]
    //         0046db16     MOV        this,byte ptr [ESP + local_18+0x1]
    //         0046db1a     ADD        DL,AL
    //         0046db1c     ADD        this,AL
    //         0046db1e     MOV        byte ptr [ESP + local_18],DL
    //         0046db22     MOV        byte ptr [ESP + local_18+0x1],this
    //         0046db26     JMP        switchD_0046db07::default
    //                               switchD_0046db07::caseD_1                                    XREF[2]:     0046db07(j), 0046dc90(*)  
    //                              pathsys.cpp:2383 (16)
    //         0046db2b     MOV        DL,byte ptr [ESP + param_1]
    //         0046db2f     MOV        AL,byte ptr [ESP + local_18+0x1]
    //         0046db33     ADD        AL,DL
    //         0046db35     MOV        byte ptr [ESP + local_18+0x1],AL
    //         0046db39     JMP        switchD_0046db07::default
    //                               switchD_0046db07::caseD_2                                    XREF[2]:     0046db07(j), 0046dc94(*)  
    //                              pathsys.cpp:2384 (26)
    //         0046db3b     MOV        AL,byte ptr [ESP + param_1]
    //         0046db3f     MOV        DL,byte ptr [ESP + local_18]
    //         0046db43     MOV        this,byte ptr [ESP + local_18+0x1]
    //         0046db47     SUB        DL,AL
    //         0046db49     ADD        this,AL
    //         0046db4b     MOV        byte ptr [ESP + local_18],DL
    //         0046db4f     MOV        byte ptr [ESP + local_18+0x1],this
    //         0046db53     JMP        switchD_0046db07::default
    //                               switchD_0046db07::caseD_3                                    XREF[2]:     0046db07(j), 0046dc98(*)  
    //                              pathsys.cpp:2385 (16)
    //         0046db55     MOV        AL,byte ptr [ESP + param_1]
    //         0046db59     MOV        this,byte ptr [ESP + local_18]
    //         0046db5d     SUB        this,AL
    //         0046db5f     MOV        byte ptr [ESP + local_18],this
    //         0046db63     JMP        switchD_0046db07::default
    //                               switchD_0046db07::caseD_4                                    XREF[2]:     0046db07(j), 0046dc9c(*)  
    //                              pathsys.cpp:2386 (26)
    //         0046db65     MOV        AL,byte ptr [ESP + param_1]
    //         0046db69     MOV        DL,byte ptr [ESP + local_18]
    //         0046db6d     MOV        this,byte ptr [ESP + local_18+0x1]
    //         0046db71     SUB        DL,AL
    //         0046db73     SUB        this,AL
    //         0046db75     MOV        byte ptr [ESP + local_18],DL
    //         0046db79     MOV        byte ptr [ESP + local_18+0x1],this
    //         0046db7d     JMP        switchD_0046db07::default
    //                               switchD_0046db07::caseD_5                                    XREF[2]:     0046db07(j), 0046dca0(*)  
    //                              pathsys.cpp:2387 (16)
    //         0046db7f     MOV        this,byte ptr [ESP + param_1]
    //         0046db83     MOV        AL,byte ptr [ESP + local_18+0x1]
    //         0046db87     SUB        AL,this
    //         0046db89     MOV        byte ptr [ESP + local_18+0x1],AL
    //         0046db8d     JMP        switchD_0046db07::default
    //                               switchD_0046db07::caseD_6                                    XREF[2]:     0046db07(j), 0046dca4(*)  
    //                              pathsys.cpp:2388 (26)
    //         0046db8f     MOV        AL,byte ptr [ESP + param_1]
    //         0046db93     MOV        DL,byte ptr [ESP + local_18]
    //         0046db97     MOV        this,byte ptr [ESP + local_18+0x1]
    //         0046db9b     ADD        DL,AL
    //         0046db9d     SUB        this,AL
    //         0046db9f     MOV        byte ptr [ESP + local_18],DL
    //         0046dba3     MOV        byte ptr [ESP + local_18+0x1],this
    //         0046dba7     JMP        switchD_0046db07::default
    //                               switchD_0046db07::caseD_7                                    XREF[2]:     0046db07(j), 0046dca8(*)  
    //                              pathsys.cpp:2389 (14)
    //         0046dba9     MOV        DL,byte ptr [ESP + param_1]
    //         0046dbad     MOV        AL,byte ptr [ESP + local_18]
    //         0046dbb1     ADD        AL,DL
    //         0046dbb3     MOV        byte ptr [ESP + local_18],AL
    //                               switchD_0046db07::default                                    XREF[8]:     0046db01(j), 0046db26(j), 
    //                                                                                                         0046db39(j), 0046db53(j), 
    //                                                                                                         0046db63(j), 0046db7d(j), 
    //                                                                                                         0046db8d(j), 0046dba7(j)  
    //                              pathsys.cpp:2393 (73)
    //         0046dbb7     MOV        EDI,dword ptr [ESP + local_18]
    //         0046dbbb     MOV        EBP,dword ptr [ESP + local_18+0x1]
    //         0046dbbf     AND        EDI,0xff
    //         0046dbc5     MOV        DL,byte ptr [ESI + 0x11dcd8]
    //         0046dbcb     MOV        EAX,EDI
    //         0046dbcd     AND        EBP,0xff
    //         0046dbd3     SHL        EAX,0x8
    //         0046dbd6     SUB        EAX,EDI
    //         0046dbd8     MOV        BL,byte ptr [ESP + tWY2]
    //         0046dbdc     ADD        EAX,ESI
    //         0046dbde     MOV        dword ptr [ESP + fooY],EDI
    //         0046dbe2     MOV        dword ptr [ESP + fooX],EBP
    //         0046dbe6     MOV        AL,byte ptr [EAX + EBP*0x1 + 0xc]
    //         0046dbea     MOV        this,AL
    //         0046dbec     AND        this,0xf8
    //         0046dbef     CMP        this,DL
    //         0046dbf1     JNZ        LAB_0046dbfb
    //         0046dbf3     AND        AL,0x7
    //         0046dbf5     MOV        byte ptr [ESP + tWY2],AL
    //         0046dbf9     JMP        LAB_0046dc00
    //                               LAB_0046dbfb                                                 XREF[1]:     0046dbf1(j)  
    //         0046dbfb     MOV        byte ptr [ESP + tWY2],0xff
    //                               LAB_0046dc00                                                 XREF[1]:     0046dbf9(j)  
    //                              pathsys.cpp:2396 (8)
    //         0046dc00     FILD       dword ptr [ESP + fooX]
    //         0046dc04     FILD       dword ptr [ESP + fooY]
    //                              pathsys.cpp:2398 (32)
    //         0046dc08     MOV        DL,byte ptr [ESP + tWY2]
    //         0046dc0c     MOV        byte ptr [ESP + local_4],DL
    //         0046dc10     FADD       float ptr [ESI + 0x11dc54]
    //         0046dc16     FXCH
    //         0046dc18     FADD       float ptr [ESI + 0x11dc58]
    //         0046dc1e     FXCH
    //         0046dc20     FSTP       float ptr [ESP + wp.y]
    //         0046dc24     FSTP       float ptr [ESP + wp.z]
    //                              pathsys.cpp:2403 (5)
    //         0046dc28     JMP        LAB_0046d906
    //                               LAB_0046dc2d                                                 XREF[1]:     0046d914(j)  
    //                              pathsys.cpp:2409 (16)
    //         0046dc2d     MOV        ESI,dword ptr [ESI + 0x11dc44]
    //         0046dc33     MOV        AL,byte ptr [ESI + 0x154]
    //         0046dc39     TEST       AL,AL
    //         0046dc3b     JNZ        LAB_0046dc5b
    //                              pathsys.cpp:2411 (20)
    //         0046dc3d     LEA        EAX=>wp.y,[ESP + 0x34]
    //         0046dc41     LEA        this,[ESI + 0xa4]
    //         0046dc47     PUSH       EAX
    //         0046dc48     CALL       Path::insertAtCurrent                            int insertAtCurrent(Path * this, Waypoint * p
    //         0046dc4d     TEST       EAX,EAX
    //         0046dc4f     JNZ        LAB_0046dc6f
    //                              pathsys.cpp:2421 (10)
    //         0046dc51     POP        EDI
    //         0046dc52     POP        ESI
    //         0046dc53     POP        EBP
    //         0046dc54     POP        EBX
    //         0046dc55     ADD        ESP,0x34
    //         0046dc58     RET        0x4
    //                               LAB_0046dc5b                                                 XREF[1]:     0046dc3b(j)  
    //                              pathsys.cpp:2416 (18)
    //         0046dc5b     LEA        this=>wp.y,[ESP + 0x34]
    //         0046dc5f     PUSH       this
    //         0046dc60     LEA        this,[ESI + 0xd8]
    //         0046dc66     CALL       Path::insertAtCurrent                            int insertAtCurrent(Path * this, Waypoint * p
    //         0046dc6b     TEST       EAX,EAX
    //                              pathsys.cpp:2417 (2)
    //         0046dc6d     JZ         LAB_0046dc7e
    //                               LAB_0046dc6f                                                 XREF[1]:     0046dc4f(j)  
    //                              pathsys.cpp:2420 (5)
    //         0046dc6f     MOV        EAX,0x1
    //                              pathsys.cpp:2421 (56)
    //         0046dc74     POP        EDI
    //         0046dc75     POP        ESI
    //         0046dc76     POP        EBP
    //         0046dc77     POP        EBX
    //         0046dc78     ADD        ESP,0x34
    //         0046dc7b     RET        0x4
    //                               LAB_0046dc7e                                                 XREF[3]:     0046d942(j), 0046d95c(j), 
    //                                                                                                         0046dc6d(j)  
    //         0046dc7e     POP        EDI
    //         0046dc7f     POP        ESI
    //         0046dc80     POP        EBP
    //         0046dc81     XOR        EAX,EAX
    //         0046dc83     POP        EBX
    //         0046dc84     ADD        ESP,0x34
    //         0046dc87     RET        0x4
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_0046dc8a()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0046dc8a
    //         0046dc8a     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0046db07::switchdataD_0046dc8c                       XREF[1]:     copyPath:0046db07(*)  
    //         0046dc8c     addr       switchD_0046db07::caseD_0
    //         0046dc90     addr       switchD_0046db07::caseD_1
    //         0046dc94     addr       switchD_0046db07::caseD_2
    //         0046dc98     addr       switchD_0046db07::caseD_3
    //         0046dc9c     addr       switchD_0046db07::caseD_4
    //         0046dca0     addr       switchD_0046db07::caseD_5
    //         0046dca4     addr       switchD_0046db07::caseD_6
    //         0046dca8     addr       switchD_0046db07::caseD_7
    //         0046dcac     ??         90h
    //         0046dcad     ??         90h
    //         0046dcae     ??         90h
    //         0046dcaf     ??         90h
    return 0;
}

void PathingSystem::copyUnobstructibles(ManagedArray<int>* param_1) {
    /* TODO: Stub */
    //                              void __thiscall copyUnobstructibles(PathingSystem * this, ManagedArr
    //              void              <VOID>         <RETURN>
    //              PathingSystem *   ECX:4 (auto)   this
    //              ManagedArray<i    Stack[0x4]:4   param_1                   XREF[3]:     0046dcc8(R), 0046dd49(W), 0046ddb1(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     0046dcbd(W), 0046dd35(R), 0046ddb5(R), 0046ddc9(W)  
    //              int               Stack[-0x8]:4  i
    //                               ?copyUnobstructibles@PathingSystem@@QAEXAAV?$ManagedArray@H  XREF[1]:     canPathWithObstructions:004600ce(c
    //                               PathingSystem::copyUnobstructibles
    //                              pathsys.cpp:2427 (5)
    //         0046dcb0     PUSH       this
    //         0046dcb1     PUSH       EBX
    //         0046dcb2     MOV        EBX,this
    //         0046dcb4     PUSH       EDI
    //                              pathsys.cpp:2430 (19)
    //         0046dcb5     MOV        EDI,dword ptr [EBX + 0x11dce8]
    //         0046dcbb     TEST       EDI,EDI
    //         0046dcbd     MOV        dword ptr [ESP + local_4],EDI
    //         0046dcc1     JL         LAB_0046ddd5
    //         0046dcc7     PUSH       ESI
    //                              pathsys.cpp:2431 (269)
    //         0046dcc8     MOV        ESI,dword ptr [ESP + param_1]
    //         0046dccc     PUSH       EBP
    //                               LAB_0046dccd                                                 XREF[1]:     0046ddcd(j)  
    //         0046dccd     MOV        EAX,dword ptr [EBX + 0x11dcf0]
    //         0046dcd3     DEC        EAX
    //         0046dcd4     CMP        EDI,EAX
    //         0046dcd6     JLE        LAB_0046dd39
    //         0046dcd8     LEA        this,[EDI*0x4 + 0x4]
    //         0046dcdf     LEA        EBP,[EDI + 0x1]
    //         0046dce2     PUSH       this
    //         0046dce3     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0046dce8     MOV        EDI,EAX
    //         0046dcea     ADD        ESP,0x4
    //         0046dced     TEST       EDI,EDI
    //         0046dcef     JZ         LAB_0046dd35
    //         0046dcf1     MOV        this,dword ptr [EBX + 0x11dcf0]
    //         0046dcf7     XOR        EAX,EAX
    //         0046dcf9     TEST       this,this
    //         0046dcfb     JLE        LAB_0046dd1a
    //                               LAB_0046dcfd                                                 XREF[1]:     0046dd18(j)  
    //         0046dcfd     CMP        EAX,EBP
    //         0046dcff     JGE        LAB_0046dd1a
    //         0046dd01     MOV        EDX,dword ptr [EBX + 0x11dce4]
    //         0046dd07     INC        EAX
    //         0046dd08     MOV        this,dword ptr [EDX + EAX*0x4 + -0x4]
    //         0046dd0c     MOV        dword ptr [EDI + EAX*0x4 + -0x4],this
    //         0046dd10     MOV        this,dword ptr [EBX + 0x11dcf0]
    //         0046dd16     CMP        EAX,this
    //         0046dd18     JL         LAB_0046dcfd
    //                               LAB_0046dd1a                                                 XREF[2]:     0046dcfb(j), 0046dcff(j)  
    //         0046dd1a     MOV        EDX,dword ptr [EBX + 0x11dce4]
    //         0046dd20     PUSH       EDX
    //         0046dd21     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0046dd26     ADD        ESP,0x4
    //         0046dd29     MOV        dword ptr [EBX + 0x11dce4],EDI
    //         0046dd2f     MOV        dword ptr [EBX + 0x11dcf0],EBP
    //                               LAB_0046dd35                                                 XREF[1]:     0046dcef(j)  
    //         0046dd35     MOV        EDI,dword ptr [ESP + local_4]
    //                               LAB_0046dd39                                                 XREF[1]:     0046dcd6(j)  
    //         0046dd39     MOV        EAX,dword ptr [EBX + 0x11dce4]
    //         0046dd3f     MOV        this,dword ptr [ESI + 0x4]
    //         0046dd42     MOV        EDX,dword ptr [EAX + EDI*0x4]
    //         0046dd45     XOR        EAX,EAX
    //         0046dd47     TEST       this,this
    //         0046dd49     MOV        dword ptr [ESP + param_1],EDX
    //         0046dd4d     JLE        LAB_0046dd61
    //                               LAB_0046dd4f                                                 XREF[1]:     0046dd5f(j)  
    //         0046dd4f     CMP        EAX,dword ptr [ESI + 0xc]
    //         0046dd52     JGE        LAB_0046dd61
    //         0046dd54     MOV        EBP,dword ptr [ESI]
    //         0046dd56     CMP        dword ptr [EBP + EAX*0x4],EDX
    //         0046dd5a     JZ         LAB_0046ddc8
    //         0046dd5c     INC        EAX
    //         0046dd5d     CMP        EAX,this
    //         0046dd5f     JL         LAB_0046dd4f
    //                               LAB_0046dd61                                                 XREF[2]:     0046dd4d(j), 0046dd52(j)  
    //         0046dd61     MOV        EAX,dword ptr [ESI + 0xc]
    //         0046dd64     DEC        EAX
    //         0046dd65     CMP        this,EAX
    //         0046dd67     JLE        LAB_0046ddb9
    //         0046dd69     LEA        EBP,[ECX + this+0x1]
    //         0046dd6c     LEA        this,[EBP*0x4 + 0x0]
    //         0046dd73     PUSH       this
    //         0046dd74     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0046dd79     MOV        EDI,EAX
    //         0046dd7b     ADD        ESP,0x4
    //         0046dd7e     TEST       EDI,EDI
    //         0046dd80     JZ         LAB_0046ddb1
    //         0046dd82     MOV        this,dword ptr [ESI + 0xc]
    //         0046dd85     XOR        EAX,EAX
    //         0046dd87     TEST       this,this
    //         0046dd89     JLE        LAB_0046dda1
    //                               LAB_0046dd8b                                                 XREF[1]:     0046dd9f(j)  
    //         0046dd8b     CMP        EAX,EBP
    //         0046dd8d     JGE        LAB_0046dda1
    //         0046dd8f     MOV        EDX,dword ptr [ESI]
    //         0046dd91     INC        EAX
    //         0046dd92     MOV        this,dword ptr [EDX + EAX*0x4 + -0x4]
    //         0046dd96     MOV        dword ptr [EDI + EAX*0x4 + -0x4],this
    //         0046dd9a     MOV        this,dword ptr [ESI + 0xc]
    //         0046dd9d     CMP        EAX,this
    //         0046dd9f     JL         LAB_0046dd8b
    //                               LAB_0046dda1                                                 XREF[2]:     0046dd89(j), 0046dd8d(j)  
    //         0046dda1     MOV        EDX,dword ptr [ESI]
    //         0046dda3     PUSH       EDX
    //         0046dda4     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0046dda9     ADD        ESP,0x4
    //         0046ddac     MOV        dword ptr [ESI],EDI
    //         0046ddae     MOV        dword ptr [ESI + 0xc],EBP
    //                               LAB_0046ddb1                                                 XREF[1]:     0046dd80(j)  
    //         0046ddb1     MOV        EDX,dword ptr [ESP + param_1]
    //         0046ddb5     MOV        EDI,dword ptr [ESP + local_4]
    //                               LAB_0046ddb9                                                 XREF[1]:     0046dd67(j)  
    //         0046ddb9     MOV        EAX,dword ptr [ESI + 0x4]
    //         0046ddbc     MOV        this,dword ptr [ESI]
    //         0046ddbe     MOV        dword ptr [this->_padding_ + EAX*0x4],EDX
    //         0046ddc1     MOV        EAX,dword ptr [ESI + 0x4]
    //         0046ddc4     INC        EAX
    //         0046ddc5     MOV        dword ptr [ESI + 0x4],EAX
    //                               LAB_0046ddc8                                                 XREF[1]:     0046dd5a(j)  
    //         0046ddc8     DEC        EDI
    //         0046ddc9     MOV        dword ptr [ESP + local_4],EDI
    //         0046ddcd     JNS        LAB_0046dccd
    //         0046ddd3     POP        EBP
    //         0046ddd4     POP        ESI
    //                               LAB_0046ddd5                                                 XREF[1]:     0046dcc1(j)  
    //                              pathsys.cpp:2432 (6)
    //         0046ddd5     POP        EDI
    //         0046ddd6     POP        EBX
    //         0046ddd7     POP        this
    //         0046ddd8     RET        0x4
    //         0046dddb     ??         90h
    //         0046dddc     NOP
    //         0046dddd     NOP
    //         0046ddde     NOP
    //         0046dddf     NOP
    return;
}

int PathingSystem::findTilePath(int param_1, int param_2, int param_3, int param_4, RGE_Moving_Object* param_5, float param_6, int param_7, int param_8, float* param_9, int param_10, int param_11, int param_12, int param_13, int param_14, int param_15) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

