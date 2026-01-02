#include "../common.h"
#include "aibldmod.h"

BuildAIModule::BuildAIModule(void* param_1, int param_2) {
    /* TODO: Stub */
//                              undefined __thiscall BuildAIModule(BuildAIModule * this, int param_1
//              undefined         <UNASSIGNED>   <RETURN>
//              BuildAIModule *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0040885b(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     004088bc(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     00408888(W), 004088c7(W), 00408bd9(W), 00408c40(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00408cfb(R)
//              char[257]         Stack[-0x114   name                      XREF[1,2]:   00408bd3(W), 00408a20(*), 00408c0d(*)
//              undefined4        Stack[-0x118   local_118                 XREF[1]:     00408876(W)
//              undefined4        Stack[-0x11c   local_11c                 XREF[2]:     00408b1b(*), 00408c06(R)
//              int               Stack[-0x120   buildFrom                 XREF[2]:     00408b5b(*), 00408be3(R)
//              int               Stack[-0x124   placeOnElevation          XREF[2]:     00408b2b(*), 00408bf1(R)
//              int               Stack[-0x128   terrainSet                XREF[2]:     00408bb6(*), 00408cc5(R)
//              uchar             Stack[-0x12c   permanentSkip             XREF[2]:     00408a33(*), 00408c1a(R)
//              int               Stack[-0x130   typeID                    XREF[2]:     00408ba6(*), 00408cb9(R)
//              int               Stack[-0x134   numberSkipCycles          XREF[2]:     00408aab(*), 00408bfb(R)
//              float             Stack[-0x138   ySize                     XREF[2]:     00408b6b(*), 00408ca1(R)
//              int               Stack[-0x13c   numberBuilds              XREF[2]:     00408b4b(*), 00408be7(R)
//              int               Stack[-0x140   terrainAdjTwo             XREF[2]:     00408a8b(*), 00408c95(R)
//              float             Stack[-0x144   z                         XREF[2]:     00408adb(*), 00408c26(R)
//              int               Stack[-0x148   buildCategory             XREF[2]:     00408a7b(*), 00408c89(R)
//              float             Stack[-0x14c   y                         XREF[2]:     00408a5b(*), 00408c15(R)
//              int               Stack[-0x150   uniqueID                  XREF[2]:     00408a6b(*), 00408c7d(R)
//              float             Stack[-0x154   x                         XREF[2]:     00408a9b(*), 00408c00(R)
//              float             Stack[-0x158   xSize                     XREF[2]:     00408a4b(*), 00408c71(R)
//              int               Stack[-0x15c   gameID                    XREF[2]:     00408abb(*), 00408bf6(R)
//              float             Stack[-0x160   zSize                     XREF[2]:     00408acb(*), 00408c65(R)
//              int               Stack[-0x164   skipValue                 XREF[2]:     00408b3b(*), 00408bec(R)
//              int               Stack[-0x168   terrainAdjOne             XREF[2]:     00408b0b(*), 00408c59(R)
//              int               Stack[-0x16c   buildAttemptsValue        XREF[2]:     00408aeb(*), 00408c4d(R)
//              int               Stack[-0x170   inProgressValue           XREF[2]:     00408afb(*), 00408c39(R)
//              int               Stack[-0x174   builtValue                XREF[3]:     00408b87(W), 00408b96(*), 00408cad(R)
//              int               Stack[-0x178   buildCap                  XREF[15]:    004088e9(*), 004088f6(R), 0040890b(R), 00408912(*),
//                                                                                     00408927(R), 0040893c(R), 00408943(*), 00408958(R),
//                                                                                     0040896d(R), 0040898f(*), 0040899c(R), 004089b1(R),
//                                                                                     00408a0c(*), 00408a19(R), 00408a2c(R)
//              int               Stack[-0x17c   tempInt
//                               ??0BuildAIModule@@QAE@HH@Z                                   XREF[1]:     TribeBuildAIModule:004d3adf(c)
//                               BuildAIModule::BuildAIModule
//                              aibldmod.cpp:50 (124)
//         00408840     PUSH       -0x1
//         00408842     PUSH       FUN_0055c49b
//         00408847     MOV        EAX,FS:[0x0]
//         0040884d     PUSH       EAX
//         0040884e     MOV        dword ptr FS:[0x0],ESP
//         00408855     SUB        ESP,0x16c
//         0040885b     MOV        EAX,dword ptr [ESP + param_1]
//         00408862     PUSH       EBX
//         00408863     PUSH       EBP
//         00408864     PUSH       ESI
//         00408865     PUSH       EDI
//         00408866     XOR        EDI,EDI
//         00408868     PUSH       EDI
//         00408869     PUSH       EAX
//         0040886a     MOV        EBX,this
//                              language.dll match for 0x3e9: "Age of Empires"
//         0040886c     PUSH       0x3e9
//         00408871     PUSH       s_Build_AI                                       = "Build AI"
//         00408876     MOV        dword ptr [ESP + local_118],EBX
//         0040887d     CALL       AIModule::AIModule                               undefined AIModule(AIModule * this, char * pa
//         00408882     LEA        ESI,[EBX + 0xf0]
//         00408888     MOV        dword ptr [ESP + local_4],EDI
//         0040888f     MOV        this,ESI
//         00408891     CALL       BuildItem::BuildItem                             undefined BuildItem(BuildItem * this)
//         00408896     LEA        EAX,[EBX + 0x1a0]
//         0040889c     MOV        dword ptr [EBX + 0x5a8],EDI
//         004088a2     MOV        dword ptr [EAX],EDI
//         004088a4     MOV        dword ptr [EBX + 0x5ac],EDI
//         004088aa     MOV        dword ptr [EBX + 0x5b0],EDI
//         004088b0     MOV        dword ptr [EBX + 0x5b4],EDI
//         004088b6     MOV        dword ptr [EBX + 0x5b8],EDI
//                              aibldmod.cpp:56 (45)
//         004088bc     MOV        EBP,dword ptr [ESP + param_2]
//         004088c3     PUSH       0x4
//         004088c5     PUSH       EAX
//         004088c6     PUSH       EBP
//         004088c7     MOV        byte ptr [ESP + local_4],0x2
//         004088cf     MOV        dword ptr [EBX],BuildAIModule::`vftable'         = 00408820
//         004088d5     MOV        dword ptr [EBX + 0x15c],ESI
//         004088db     MOV        dword ptr [EBX + 0x160],ESI
//         004088e1     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         004088e6     ADD        ESP,0xc
//                              aibldmod.cpp:59 (13)
//         004088e9     LEA        this=>buildCap,[ESP + 0x10]
//         004088ed     PUSH       0x4
//         004088ef     PUSH       this
//         004088f0     PUSH       EBP
//         004088f1     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              aibldmod.cpp:60 (21)
//         004088f6     MOV        EDX,dword ptr [ESP + buildCap]
//         004088fa     ADD        ESP,0xc
//         004088fd     LEA        EAX,[EBX + 0x1a4]
//         00408903     PUSH       EDX
//         00408904     PUSH       EAX
//         00408905     PUSH       EBP
//         00408906     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              aibldmod.cpp:61 (7)
//         0040890b     MOV        this,dword ptr [ESP + buildCap]
//         0040890f     ADD        ESP,0xc
//                              aibldmod.cpp:63 (21)
//         00408912     LEA        EDX=>buildCap,[ESP + 0x10]
//         00408916     PUSH       0x4
//         00408918     PUSH       EDX
//         00408919     PUSH       EBP
//         0040891a     MOV        byte ptr [ECX + EBX*0x1 + this->buildListNameV
//         00408922     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              aibldmod.cpp:64 (21)
//         00408927     MOV        EAX,dword ptr [ESP + buildCap]
//         0040892b     ADD        ESP,0xc
//         0040892e     LEA        this,[EBX + 0x2a5]
//         00408934     PUSH       EAX
//         00408935     PUSH       this
//         00408936     PUSH       EBP
//         00408937     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              aibldmod.cpp:65 (7)
//         0040893c     MOV        EDX,dword ptr [ESP + buildCap]
//         00408940     ADD        ESP,0xc
//                              aibldmod.cpp:67 (21)
//         00408943     LEA        EAX=>buildCap,[ESP + 0x10]
//         00408947     PUSH       0x4
//         00408949     PUSH       EAX
//         0040894a     PUSH       EBP
//         0040894b     MOV        byte ptr [EDX + EBX*0x1 + 0x2a5],0x0
//         00408953     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              aibldmod.cpp:68 (21)
//         00408958     MOV        this,dword ptr [ESP + buildCap]
//         0040895c     ADD        ESP,0xc
//         0040895f     LEA        EDX,[EBX + 0x3a6]
//         00408965     PUSH       this
//         00408966     PUSH       EDX
//         00408967     PUSH       EBP
//         00408968     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              aibldmod.cpp:69 (15)
//         0040896d     MOV        EAX,dword ptr [ESP + buildCap]
//         00408971     ADD        ESP,0xc
//         00408974     MOV        byte ptr [EAX + EBX*0x1 + 0x3a6],0x0
//                              aibldmod.cpp:71 (19)
//         0040897c     FLD        float ptr [save_game_version]                    = 7.23
//         00408982     FCOMP      float ptr [DAT_0056e784]                         = 66h    f
//         00408988     FNSTSW     AX
//         0040898a     TEST       AH,0x1
//         0040898d     JNZ        LAB_004089c2
//                              aibldmod.cpp:72 (13)
//         0040898f     LEA        this=>buildCap,[ESP + 0x10]
//         00408993     PUSH       0x4
//         00408995     PUSH       this
//         00408996     PUSH       EBP
//         00408997     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              aibldmod.cpp:73 (21)
//         0040899c     MOV        EDX,dword ptr [ESP + buildCap]
//         004089a0     ADD        ESP,0xc
//         004089a3     LEA        EAX,[EBX + 0x4a7]
//         004089a9     PUSH       EDX
//         004089aa     PUSH       EAX
//         004089ab     PUSH       EBP
//         004089ac     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              aibldmod.cpp:74 (15)
//         004089b1     MOV        this,dword ptr [ESP + buildCap]
//         004089b5     ADD        ESP,0xc
//         004089b8     MOV        byte ptr [ECX + EBX*0x1 + this->nextBuildItemR
//                              aibldmod.cpp:76 (2)
//         004089c0     JMP        LAB_004089ec
//                               LAB_004089c2                                                 XREF[1]:     0040898d(j)
//                              aibldmod.cpp:77 (42)
//         004089c2     MOV        EDI,s_None                                       = 4Eh
//         004089c7     OR         this,0xffffffff
//         004089ca     XOR        EAX,EAX
//         004089cc     LEA        EDX,[EBX + 0x4a7]
//         004089d2     SCASB.RE   ES:EDI=>s_None                                   = 4Eh
//                                                                                  = 00656e6f
//         004089d4     NOT        this
//         004089d6     SUB        EDI,this
//         004089d8     MOV        EAX,this
//         004089da     MOV        ESI,EDI
//         004089dc     MOV        EDI,EDX
//         004089de     SHR        this,0x2
//         004089e1     MOVSD.REP  ES:EDI,ESI
//         004089e3     MOV        this,EAX
//         004089e5     AND        this,0x3
//         004089e8     MOVSB.REP  ES:EDI,ESI
//         004089ea     XOR        EDI,EDI
//                               LAB_004089ec                                                 XREF[1]:     004089c0(j)
//                              aibldmod.cpp:80 (15)
//         004089ec     LEA        EAX,[EBX + 0x5a8]
//         004089f2     PUSH       0x4
//         004089f4     PUSH       EAX
//         004089f5     PUSH       EBP
//         004089f6     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              aibldmod.cpp:82 (17)
//         004089fb     MOV        EAX,dword ptr [EBX + 0x1a0]
//         00408a01     ADD        ESP,0xc
//         00408a04     TEST       EAX,EAX
//         00408a06     JLE        LAB_00408cfb
//                               LAB_00408a0c                                                 XREF[1]:     00408cf5(j)
//                              aibldmod.cpp:85 (13)
//         00408a0c     LEA        this=>buildCap,[ESP + 0x10]
//         00408a10     PUSH       0x4
//         00408a12     PUSH       this
//         00408a13     PUSH       EBP
//         00408a14     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              aibldmod.cpp:86 (19)
//         00408a19     MOV        EDX,dword ptr [ESP + buildCap]
//         00408a1d     ADD        ESP,0xc
//         00408a20     LEA        EAX=>name[4],[ESP + 0x78]
//         00408a24     PUSH       EDX
//         00408a25     PUSH       EAX
//         00408a26     PUSH       EBP
//         00408a27     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              aibldmod.cpp:87 (7)
//         00408a2c     MOV        this,dword ptr [ESP + buildCap]
//         00408a30     ADD        ESP,0xc
//                              aibldmod.cpp:89 (24)
//         00408a33     LEA        EDX=>permanentSkip,[ESP + 0x5c]
//         00408a37     PUSH       0x4
//         00408a39     PUSH       EDX
//         00408a3a     PUSH       EBP
//         00408a3b     MOV        byte ptr [ESP + this->_padding_*0x1 + 0x84],0x0
//         00408a43     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408a48     ADD        ESP,0xc
//                              aibldmod.cpp:91 (16)
//         00408a4b     LEA        EAX=>xSize,[ESP + 0x30]
//         00408a4f     PUSH       0x4
//         00408a51     PUSH       EAX
//         00408a52     PUSH       EBP
//         00408a53     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408a58     ADD        ESP,0xc
//                              aibldmod.cpp:93 (16)
//         00408a5b     LEA        this=>y,[ESP + 0x3c]
//         00408a5f     PUSH       0x4
//         00408a61     PUSH       this
//         00408a62     PUSH       EBP
//         00408a63     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408a68     ADD        ESP,0xc
//                              aibldmod.cpp:95 (16)
//         00408a6b     LEA        EDX=>uniqueID,[ESP + 0x38]
//         00408a6f     PUSH       0x4
//         00408a71     PUSH       EDX
//         00408a72     PUSH       EBP
//         00408a73     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408a78     ADD        ESP,0xc
//                              aibldmod.cpp:97 (16)
//         00408a7b     LEA        EAX=>buildCategory,[ESP + 0x40]
//         00408a7f     PUSH       0x4
//         00408a81     PUSH       EAX
//         00408a82     PUSH       EBP
//         00408a83     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408a88     ADD        ESP,0xc
//                              aibldmod.cpp:99 (16)
//         00408a8b     LEA        this=>terrainAdjTwo,[ESP + 0x48]
//         00408a8f     PUSH       0x4
//         00408a91     PUSH       this
//         00408a92     PUSH       EBP
//         00408a93     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408a98     ADD        ESP,0xc
//                              aibldmod.cpp:101 (16)
//         00408a9b     LEA        EDX=>x,[ESP + 0x34]
//         00408a9f     PUSH       0x4
//         00408aa1     PUSH       EDX
//         00408aa2     PUSH       EBP
//         00408aa3     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408aa8     ADD        ESP,0xc
//                              aibldmod.cpp:103 (16)
//         00408aab     LEA        EAX=>numberSkipCycles,[ESP + 0x54]
//         00408aaf     PUSH       0x4
//         00408ab1     PUSH       EAX
//         00408ab2     PUSH       EBP
//         00408ab3     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408ab8     ADD        ESP,0xc
//                              aibldmod.cpp:105 (16)
//         00408abb     LEA        this=>gameID,[ESP + 0x2c]
//         00408abf     PUSH       0x4
//         00408ac1     PUSH       this
//         00408ac2     PUSH       EBP
//         00408ac3     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408ac8     ADD        ESP,0xc
//                              aibldmod.cpp:107 (16)
//         00408acb     LEA        EDX=>zSize,[ESP + 0x28]
//         00408acf     PUSH       0x4
//         00408ad1     PUSH       EDX
//         00408ad2     PUSH       EBP
//         00408ad3     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408ad8     ADD        ESP,0xc
//                              aibldmod.cpp:112 (16)
//         00408adb     LEA        EAX=>z,[ESP + 0x44]
//         00408adf     PUSH       0x4
//         00408ae1     PUSH       EAX
//         00408ae2     PUSH       EBP
//         00408ae3     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408ae8     ADD        ESP,0xc
//                              aibldmod.cpp:114 (16)
//         00408aeb     LEA        this=>buildAttemptsValue,[ESP + 0x1c]
//         00408aef     PUSH       0x4
//         00408af1     PUSH       this
//         00408af2     PUSH       EBP
//         00408af3     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408af8     ADD        ESP,0xc
//                              aibldmod.cpp:116 (16)
//         00408afb     LEA        EDX=>inProgressValue,[ESP + 0x18]
//         00408aff     PUSH       0x4
//         00408b01     PUSH       EDX
//         00408b02     PUSH       EBP
//         00408b03     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408b08     ADD        ESP,0xc
//                              aibldmod.cpp:118 (16)
//         00408b0b     LEA        EAX=>terrainAdjOne,[ESP + 0x20]
//         00408b0f     PUSH       0x4
//         00408b11     PUSH       EAX
//         00408b12     PUSH       EBP
//         00408b13     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408b18     ADD        ESP,0xc
//                              aibldmod.cpp:120 (16)
//         00408b1b     LEA        this=>local_11c,[ESP + 0x6c]
//         00408b1f     PUSH       0x4
//         00408b21     PUSH       this
//         00408b22     PUSH       EBP
//         00408b23     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408b28     ADD        ESP,0xc
//                              aibldmod.cpp:122 (16)
//         00408b2b     LEA        EDX=>placeOnElevation,[ESP + 0x64]
//         00408b2f     PUSH       0x4
//         00408b31     PUSH       EDX
//         00408b32     PUSH       EBP
//         00408b33     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408b38     ADD        ESP,0xc
//                              aibldmod.cpp:124 (16)
//         00408b3b     LEA        EAX=>skipValue,[ESP + 0x24]
//         00408b3f     PUSH       0x4
//         00408b41     PUSH       EAX
//         00408b42     PUSH       EBP
//         00408b43     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408b48     ADD        ESP,0xc
//                              aibldmod.cpp:126 (16)
//         00408b4b     LEA        this=>numberBuilds,[ESP + 0x4c]
//         00408b4f     PUSH       0x4
//         00408b51     PUSH       this
//         00408b52     PUSH       EBP
//         00408b53     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408b58     ADD        ESP,0xc
//                              aibldmod.cpp:128 (16)
//         00408b5b     LEA        EDX=>buildFrom,[ESP + 0x68]
//         00408b5f     PUSH       0x4
//         00408b61     PUSH       EDX
//         00408b62     PUSH       EBP
//         00408b63     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408b68     ADD        ESP,0xc
//                              aibldmod.cpp:130 (13)
//         00408b6b     LEA        EAX=>ySize,[ESP + 0x50]
//         00408b6f     PUSH       0x4
//         00408b71     PUSH       EAX
//         00408b72     PUSH       EBP
//         00408b73     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              aibldmod.cpp:132 (30)
//         00408b78     FLD        float ptr [save_game_version]                    = 7.23
//         00408b7e     FCOMP      float ptr [DAT_0056e788]                         = CDh
//         00408b84     ADD        ESP,0xc
//         00408b87     MOV        dword ptr [ESP + builtValue],0xffffffff
//         00408b8f     FNSTSW     AX
//         00408b91     TEST       AH,0x1
//         00408b94     JNZ        LAB_00408ba6
//                              aibldmod.cpp:133 (16)
//         00408b96     LEA        this=>builtValue,[ESP + 0x14]
//         00408b9a     PUSH       0x4
//         00408b9c     PUSH       this
//         00408b9d     PUSH       EBP
//         00408b9e     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408ba3     ADD        ESP,0xc
//                               LAB_00408ba6                                                 XREF[1]:     00408b94(j)
//                              aibldmod.cpp:135 (16)
//         00408ba6     LEA        EDX=>typeID,[ESP + 0x58]
//         00408baa     PUSH       0x4
//         00408bac     PUSH       EDX
//         00408bad     PUSH       EBP
//         00408bae     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408bb3     ADD        ESP,0xc
//                              aibldmod.cpp:137 (16)
//         00408bb6     LEA        EAX=>terrainSet,[ESP + 0x60]
//         00408bba     PUSH       0x1
//         00408bbc     PUSH       EAX
//         00408bbd     PUSH       EBP
//         00408bbe     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408bc3     ADD        ESP,0xc
//                              aibldmod.cpp:142 (115)
//         00408bc6     PUSH       0xb0
//         00408bcb     CALL       operator_new                                     void * operator_new(uint param_1)
//         00408bd0     ADD        ESP,0x4
//         00408bd3     MOV        dword ptr [ESP + name[0]],EAX
//         00408bd7     TEST       EAX,EAX
//         00408bd9     MOV        byte ptr [ESP + local_4],0x3
//         00408be1     JZ         LAB_00408c37
//         00408be3     MOV        this,dword ptr [ESP + buildFrom]
//         00408be7     MOV        EDX,dword ptr [ESP + numberBuilds]
//         00408beb     PUSH       this
//         00408bec     MOV        this,dword ptr [ESP + skipValue]
//         00408bf0     PUSH       EDX
//         00408bf1     MOV        EDX,dword ptr [ESP + placeOnElevation]
//         00408bf5     PUSH       this
//         00408bf6     MOV        this,dword ptr [ESP + gameID]
//         00408bfa     PUSH       EDX
//         00408bfb     MOV        EDX,dword ptr [ESP + numberSkipCycles]
//         00408bff     PUSH       this
//         00408c00     MOV        this,dword ptr [ESP + x]
//         00408c04     PUSH       EDX
//         00408c05     PUSH       this
//         00408c06     MOV        this,dword ptr [ESP + local_11c]
//         00408c0d     LEA        EDX=>name[4],[ESP + 0x94]
//         00408c14     PUSH       EDX
//         00408c15     MOV        EDX,dword ptr [ESP + y]
//         00408c19     PUSH       this
//         00408c1a     MOV        this,dword ptr [ESP + permanentSkip]
//         00408c21     PUSH       0x0
//         00408c23     PUSH       0x1
//         00408c25     PUSH       EDX
//         00408c26     MOV        EDX,dword ptr [ESP + z]
//         00408c2a     PUSH       this
//         00408c2b     PUSH       EDX
//         00408c2c     MOV        this,EAX
//         00408c2e     CALL       BuildItem::BuildItem                             undefined BuildItem(BuildItem * this, int par
//         00408c33     MOV        ESI,EAX
//         00408c35     JMP        LAB_00408c39
//                               LAB_00408c37                                                 XREF[1]:     00408be1(j)
//         00408c37     XOR        ESI,ESI
//                               LAB_00408c39                                                 XREF[1]:     00408c35(j)
//                              aibldmod.cpp:143 (20)
//         00408c39     MOV        EAX,dword ptr [ESP + inProgressValue]
//         00408c3d     MOV        this,ESI
//         00408c3f     PUSH       EAX
//         00408c40     MOV        byte ptr [ESP + local_4],0x2
//         00408c48     CALL       BuildItem::setBuilt                              void setBuilt(BuildItem * this, int param_1)
//                              aibldmod.cpp:144 (12)
//         00408c4d     MOV        this,dword ptr [ESP + buildAttemptsValue]
//         00408c51     PUSH       this
//         00408c52     MOV        this,ESI
//         00408c54     CALL       BuildItem::setInProgress                         void setInProgress(BuildItem * this, int para
//                              aibldmod.cpp:145 (12)
//         00408c59     MOV        EDX,dword ptr [ESP + terrainAdjOne]
//         00408c5d     MOV        this,ESI
//         00408c5f     PUSH       EDX
//         00408c60     CALL       BuildItem::setBuildAttempts                      void setBuildAttempts(BuildItem * this, int p
//                              aibldmod.cpp:146 (12)
//         00408c65     MOV        EAX,dword ptr [ESP + zSize]
//         00408c69     MOV        this,ESI
//         00408c6b     PUSH       EAX
//         00408c6c     CALL       BaseItem::setSkip                                void setSkip(BaseItem * this, int param_1)
//                              aibldmod.cpp:147 (12)
//         00408c71     MOV        this,dword ptr [ESP + xSize]
//         00408c75     PUSH       this
//         00408c76     MOV        this,ESI
//         00408c78     CALL       BaseItem::setGameID                              void setGameID(BaseItem * this, int param_1)
//                              aibldmod.cpp:148 (12)
//         00408c7d     MOV        EDX,dword ptr [ESP + uniqueID]
//         00408c81     MOV        this,ESI
//         00408c83     PUSH       EDX
//         00408c84     CALL       BaseItem::setX                                   void setX(BaseItem * this, float param_1)
//                              aibldmod.cpp:149 (12)
//         00408c89     MOV        EAX,dword ptr [ESP + buildCategory]
//         00408c8d     MOV        this,ESI
//         00408c8f     PUSH       EAX
//         00408c90     CALL       BaseItem::setY                                   void setY(BaseItem * this, float param_1)
//                              aibldmod.cpp:150 (12)
//         00408c95     MOV        this,dword ptr [ESP + terrainAdjTwo]
//         00408c99     PUSH       this
//         00408c9a     MOV        this,ESI
//         00408c9c     CALL       BaseItem::setZ                                   void setZ(BaseItem * this, float param_1)
//                              aibldmod.cpp:151 (12)
//         00408ca1     MOV        EDX,dword ptr [ESP + ySize]
//         00408ca5     MOV        this,ESI
//         00408ca7     PUSH       EDX
//         00408ca8     CALL       BuildItem::setNumberBuilds                       void setNumberBuilds(BuildItem * this, int pa
//                              aibldmod.cpp:152 (12)
//         00408cad     MOV        EAX,dword ptr [ESP + builtValue]
//         00408cb1     MOV        this,ESI
//         00408cb3     PUSH       EAX
//         00408cb4     CALL       BuildItem::setBuildCap                           void setBuildCap(BuildItem * this, int param_1)
//                              aibldmod.cpp:153 (12)
//         00408cb9     MOV        this,dword ptr [ESP + typeID]
//         00408cbd     PUSH       this
//         00408cbe     MOV        this,ESI
//         00408cc0     CALL       BuildItem::setSkipCycles                         void setSkipCycles(BuildItem * this, int para
//                              aibldmod.cpp:154 (12)
//         00408cc5     MOV        EDX,dword ptr [ESP + terrainSet]
//         00408cc9     MOV        this,ESI
//         00408ccb     PUSH       EDX
//         00408ccc     CALL       BuildItem::setPermanentSkip                      void setPermanentSkip(BuildItem * this, uchar
//                              aibldmod.cpp:157 (10)
//         00408cd1     LEA        EAX,[EBX + 0xf0]
//         00408cd7     INC        EDI
//         00408cd8     MOV        dword ptr [ESI + 0x6c],EAX
//                              aibldmod.cpp:158 (9)
//         00408cdb     MOV        EAX,dword ptr [EBX + 0x160]
//         00408ce1     MOV        dword ptr [ESI + 0x70],EAX
//                              aibldmod.cpp:159 (11)
//         00408ce4     MOV        dword ptr [EAX + 0x6c],ESI
//         00408ce7     MOV        EAX,dword ptr [EBX + 0x1a0]
//         00408ced     CMP        EDI,EAX
//                              aibldmod.cpp:160 (12)
//         00408cef     MOV        dword ptr [EBX + 0x160],ESI
//         00408cf5     JL         LAB_00408a0c
//                               LAB_00408cfb                                                 XREF[1]:     00408a06(j)
//                              aibldmod.cpp:175 (29)
//         00408cfb     MOV        this,dword ptr [ESP + local_c]
//         00408d02     POP        EDI
//         00408d03     POP        ESI
//         00408d04     MOV        EAX,EBX
//         00408d06     POP        EBP
//         00408d07     MOV        dword ptr FS:[0x0],this
//         00408d0e     POP        EBX
//         00408d0f     ADD        ESP,0x178
//         00408d15     RET        0x8
//         00408d18     ??         90h
//         00408d19     NOP
//         00408d1a     NOP
//         00408d1b     NOP
//         00408d1c     NOP
//         00408d1d     NOP
//         00408d1e     NOP
//         00408d1f     NOP
}

BuildAIModule::BuildAIModule(int param_1, int param_2) {
    /* TODO: Stub */
//                              undefined __thiscall BuildAIModule(BuildAIModule * this, int param_1
//              undefined         <UNASSIGNED>   <RETURN>
//              BuildAIModule *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0040885b(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     004088bc(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     00408888(W), 004088c7(W), 00408bd9(W), 00408c40(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00408cfb(R)
//              char[257]         Stack[-0x114   name                      XREF[1,2]:   00408bd3(W), 00408a20(*), 00408c0d(*)
//              undefined4        Stack[-0x118   local_118                 XREF[1]:     00408876(W)
//              undefined4        Stack[-0x11c   local_11c                 XREF[2]:     00408b1b(*), 00408c06(R)
//              int               Stack[-0x120   buildFrom                 XREF[2]:     00408b5b(*), 00408be3(R)
//              int               Stack[-0x124   placeOnElevation          XREF[2]:     00408b2b(*), 00408bf1(R)
//              int               Stack[-0x128   terrainSet                XREF[2]:     00408bb6(*), 00408cc5(R)
//              uchar             Stack[-0x12c   permanentSkip             XREF[2]:     00408a33(*), 00408c1a(R)
//              int               Stack[-0x130   typeID                    XREF[2]:     00408ba6(*), 00408cb9(R)
//              int               Stack[-0x134   numberSkipCycles          XREF[2]:     00408aab(*), 00408bfb(R)
//              float             Stack[-0x138   ySize                     XREF[2]:     00408b6b(*), 00408ca1(R)
//              int               Stack[-0x13c   numberBuilds              XREF[2]:     00408b4b(*), 00408be7(R)
//              int               Stack[-0x140   terrainAdjTwo             XREF[2]:     00408a8b(*), 00408c95(R)
//              float             Stack[-0x144   z                         XREF[2]:     00408adb(*), 00408c26(R)
//              int               Stack[-0x148   buildCategory             XREF[2]:     00408a7b(*), 00408c89(R)
//              float             Stack[-0x14c   y                         XREF[2]:     00408a5b(*), 00408c15(R)
//              int               Stack[-0x150   uniqueID                  XREF[2]:     00408a6b(*), 00408c7d(R)
//              float             Stack[-0x154   x                         XREF[2]:     00408a9b(*), 00408c00(R)
//              float             Stack[-0x158   xSize                     XREF[2]:     00408a4b(*), 00408c71(R)
//              int               Stack[-0x15c   gameID                    XREF[2]:     00408abb(*), 00408bf6(R)
//              float             Stack[-0x160   zSize                     XREF[2]:     00408acb(*), 00408c65(R)
//              int               Stack[-0x164   skipValue                 XREF[2]:     00408b3b(*), 00408bec(R)
//              int               Stack[-0x168   terrainAdjOne             XREF[2]:     00408b0b(*), 00408c59(R)
//              int               Stack[-0x16c   buildAttemptsValue        XREF[2]:     00408aeb(*), 00408c4d(R)
//              int               Stack[-0x170   inProgressValue           XREF[2]:     00408afb(*), 00408c39(R)
//              int               Stack[-0x174   builtValue                XREF[3]:     00408b87(W), 00408b96(*), 00408cad(R)
//              int               Stack[-0x178   buildCap                  XREF[15]:    004088e9(*), 004088f6(R), 0040890b(R), 00408912(*),
//                                                                                     00408927(R), 0040893c(R), 00408943(*), 00408958(R),
//                                                                                     0040896d(R), 0040898f(*), 0040899c(R), 004089b1(R),
//                                                                                     00408a0c(*), 00408a19(R), 00408a2c(R)
//              int               Stack[-0x17c   tempInt
//                               ??0BuildAIModule@@QAE@HH@Z                                   XREF[1]:     TribeBuildAIModule:004d3adf(c)
//                               BuildAIModule::BuildAIModule
//                              aibldmod.cpp:50 (124)
//         00408840     PUSH       -0x1
//         00408842     PUSH       FUN_0055c49b
//         00408847     MOV        EAX,FS:[0x0]
//         0040884d     PUSH       EAX
//         0040884e     MOV        dword ptr FS:[0x0],ESP
//         00408855     SUB        ESP,0x16c
//         0040885b     MOV        EAX,dword ptr [ESP + param_1]
//         00408862     PUSH       EBX
//         00408863     PUSH       EBP
//         00408864     PUSH       ESI
//         00408865     PUSH       EDI
//         00408866     XOR        EDI,EDI
//         00408868     PUSH       EDI
//         00408869     PUSH       EAX
//         0040886a     MOV        EBX,this
//                              language.dll match for 0x3e9: "Age of Empires"
//         0040886c     PUSH       0x3e9
//         00408871     PUSH       s_Build_AI                                       = "Build AI"
//         00408876     MOV        dword ptr [ESP + local_118],EBX
//         0040887d     CALL       AIModule::AIModule                               undefined AIModule(AIModule * this, char * pa
//         00408882     LEA        ESI,[EBX + 0xf0]
//         00408888     MOV        dword ptr [ESP + local_4],EDI
//         0040888f     MOV        this,ESI
//         00408891     CALL       BuildItem::BuildItem                             undefined BuildItem(BuildItem * this)
//         00408896     LEA        EAX,[EBX + 0x1a0]
//         0040889c     MOV        dword ptr [EBX + 0x5a8],EDI
//         004088a2     MOV        dword ptr [EAX],EDI
//         004088a4     MOV        dword ptr [EBX + 0x5ac],EDI
//         004088aa     MOV        dword ptr [EBX + 0x5b0],EDI
//         004088b0     MOV        dword ptr [EBX + 0x5b4],EDI
//         004088b6     MOV        dword ptr [EBX + 0x5b8],EDI
//                              aibldmod.cpp:56 (45)
//         004088bc     MOV        EBP,dword ptr [ESP + param_2]
//         004088c3     PUSH       0x4
//         004088c5     PUSH       EAX
//         004088c6     PUSH       EBP
//         004088c7     MOV        byte ptr [ESP + local_4],0x2
//         004088cf     MOV        dword ptr [EBX],BuildAIModule::`vftable'         = 00408820
//         004088d5     MOV        dword ptr [EBX + 0x15c],ESI
//         004088db     MOV        dword ptr [EBX + 0x160],ESI
//         004088e1     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         004088e6     ADD        ESP,0xc
//                              aibldmod.cpp:59 (13)
//         004088e9     LEA        this=>buildCap,[ESP + 0x10]
//         004088ed     PUSH       0x4
//         004088ef     PUSH       this
//         004088f0     PUSH       EBP
//         004088f1     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              aibldmod.cpp:60 (21)
//         004088f6     MOV        EDX,dword ptr [ESP + buildCap]
//         004088fa     ADD        ESP,0xc
//         004088fd     LEA        EAX,[EBX + 0x1a4]
//         00408903     PUSH       EDX
//         00408904     PUSH       EAX
//         00408905     PUSH       EBP
//         00408906     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              aibldmod.cpp:61 (7)
//         0040890b     MOV        this,dword ptr [ESP + buildCap]
//         0040890f     ADD        ESP,0xc
//                              aibldmod.cpp:63 (21)
//         00408912     LEA        EDX=>buildCap,[ESP + 0x10]
//         00408916     PUSH       0x4
//         00408918     PUSH       EDX
//         00408919     PUSH       EBP
//         0040891a     MOV        byte ptr [ECX + EBX*0x1 + this->buildListNameV
//         00408922     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              aibldmod.cpp:64 (21)
//         00408927     MOV        EAX,dword ptr [ESP + buildCap]
//         0040892b     ADD        ESP,0xc
//         0040892e     LEA        this,[EBX + 0x2a5]
//         00408934     PUSH       EAX
//         00408935     PUSH       this
//         00408936     PUSH       EBP
//         00408937     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              aibldmod.cpp:65 (7)
//         0040893c     MOV        EDX,dword ptr [ESP + buildCap]
//         00408940     ADD        ESP,0xc
//                              aibldmod.cpp:67 (21)
//         00408943     LEA        EAX=>buildCap,[ESP + 0x10]
//         00408947     PUSH       0x4
//         00408949     PUSH       EAX
//         0040894a     PUSH       EBP
//         0040894b     MOV        byte ptr [EDX + EBX*0x1 + 0x2a5],0x0
//         00408953     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              aibldmod.cpp:68 (21)
//         00408958     MOV        this,dword ptr [ESP + buildCap]
//         0040895c     ADD        ESP,0xc
//         0040895f     LEA        EDX,[EBX + 0x3a6]
//         00408965     PUSH       this
//         00408966     PUSH       EDX
//         00408967     PUSH       EBP
//         00408968     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              aibldmod.cpp:69 (15)
//         0040896d     MOV        EAX,dword ptr [ESP + buildCap]
//         00408971     ADD        ESP,0xc
//         00408974     MOV        byte ptr [EAX + EBX*0x1 + 0x3a6],0x0
//                              aibldmod.cpp:71 (19)
//         0040897c     FLD        float ptr [save_game_version]                    = 7.23
//         00408982     FCOMP      float ptr [DAT_0056e784]                         = 66h    f
//         00408988     FNSTSW     AX
//         0040898a     TEST       AH,0x1
//         0040898d     JNZ        LAB_004089c2
//                              aibldmod.cpp:72 (13)
//         0040898f     LEA        this=>buildCap,[ESP + 0x10]
//         00408993     PUSH       0x4
//         00408995     PUSH       this
//         00408996     PUSH       EBP
//         00408997     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              aibldmod.cpp:73 (21)
//         0040899c     MOV        EDX,dword ptr [ESP + buildCap]
//         004089a0     ADD        ESP,0xc
//         004089a3     LEA        EAX,[EBX + 0x4a7]
//         004089a9     PUSH       EDX
//         004089aa     PUSH       EAX
//         004089ab     PUSH       EBP
//         004089ac     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              aibldmod.cpp:74 (15)
//         004089b1     MOV        this,dword ptr [ESP + buildCap]
//         004089b5     ADD        ESP,0xc
//         004089b8     MOV        byte ptr [ECX + EBX*0x1 + this->nextBuildItemR
//                              aibldmod.cpp:76 (2)
//         004089c0     JMP        LAB_004089ec
//                               LAB_004089c2                                                 XREF[1]:     0040898d(j)
//                              aibldmod.cpp:77 (42)
//         004089c2     MOV        EDI,s_None                                       = 4Eh
//         004089c7     OR         this,0xffffffff
//         004089ca     XOR        EAX,EAX
//         004089cc     LEA        EDX,[EBX + 0x4a7]
//         004089d2     SCASB.RE   ES:EDI=>s_None                                   = 4Eh
//                                                                                  = 00656e6f
//         004089d4     NOT        this
//         004089d6     SUB        EDI,this
//         004089d8     MOV        EAX,this
//         004089da     MOV        ESI,EDI
//         004089dc     MOV        EDI,EDX
//         004089de     SHR        this,0x2
//         004089e1     MOVSD.REP  ES:EDI,ESI
//         004089e3     MOV        this,EAX
//         004089e5     AND        this,0x3
//         004089e8     MOVSB.REP  ES:EDI,ESI
//         004089ea     XOR        EDI,EDI
//                               LAB_004089ec                                                 XREF[1]:     004089c0(j)
//                              aibldmod.cpp:80 (15)
//         004089ec     LEA        EAX,[EBX + 0x5a8]
//         004089f2     PUSH       0x4
//         004089f4     PUSH       EAX
//         004089f5     PUSH       EBP
//         004089f6     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              aibldmod.cpp:82 (17)
//         004089fb     MOV        EAX,dword ptr [EBX + 0x1a0]
//         00408a01     ADD        ESP,0xc
//         00408a04     TEST       EAX,EAX
//         00408a06     JLE        LAB_00408cfb
//                               LAB_00408a0c                                                 XREF[1]:     00408cf5(j)
//                              aibldmod.cpp:85 (13)
//         00408a0c     LEA        this=>buildCap,[ESP + 0x10]
//         00408a10     PUSH       0x4
//         00408a12     PUSH       this
//         00408a13     PUSH       EBP
//         00408a14     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              aibldmod.cpp:86 (19)
//         00408a19     MOV        EDX,dword ptr [ESP + buildCap]
//         00408a1d     ADD        ESP,0xc
//         00408a20     LEA        EAX=>name[4],[ESP + 0x78]
//         00408a24     PUSH       EDX
//         00408a25     PUSH       EAX
//         00408a26     PUSH       EBP
//         00408a27     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              aibldmod.cpp:87 (7)
//         00408a2c     MOV        this,dword ptr [ESP + buildCap]
//         00408a30     ADD        ESP,0xc
//                              aibldmod.cpp:89 (24)
//         00408a33     LEA        EDX=>permanentSkip,[ESP + 0x5c]
//         00408a37     PUSH       0x4
//         00408a39     PUSH       EDX
//         00408a3a     PUSH       EBP
//         00408a3b     MOV        byte ptr [ESP + this->_padding_*0x1 + 0x84],0x0
//         00408a43     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408a48     ADD        ESP,0xc
//                              aibldmod.cpp:91 (16)
//         00408a4b     LEA        EAX=>xSize,[ESP + 0x30]
//         00408a4f     PUSH       0x4
//         00408a51     PUSH       EAX
//         00408a52     PUSH       EBP
//         00408a53     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408a58     ADD        ESP,0xc
//                              aibldmod.cpp:93 (16)
//         00408a5b     LEA        this=>y,[ESP + 0x3c]
//         00408a5f     PUSH       0x4
//         00408a61     PUSH       this
//         00408a62     PUSH       EBP
//         00408a63     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408a68     ADD        ESP,0xc
//                              aibldmod.cpp:95 (16)
//         00408a6b     LEA        EDX=>uniqueID,[ESP + 0x38]
//         00408a6f     PUSH       0x4
//         00408a71     PUSH       EDX
//         00408a72     PUSH       EBP
//         00408a73     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408a78     ADD        ESP,0xc
//                              aibldmod.cpp:97 (16)
//         00408a7b     LEA        EAX=>buildCategory,[ESP + 0x40]
//         00408a7f     PUSH       0x4
//         00408a81     PUSH       EAX
//         00408a82     PUSH       EBP
//         00408a83     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408a88     ADD        ESP,0xc
//                              aibldmod.cpp:99 (16)
//         00408a8b     LEA        this=>terrainAdjTwo,[ESP + 0x48]
//         00408a8f     PUSH       0x4
//         00408a91     PUSH       this
//         00408a92     PUSH       EBP
//         00408a93     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408a98     ADD        ESP,0xc
//                              aibldmod.cpp:101 (16)
//         00408a9b     LEA        EDX=>x,[ESP + 0x34]
//         00408a9f     PUSH       0x4
//         00408aa1     PUSH       EDX
//         00408aa2     PUSH       EBP
//         00408aa3     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408aa8     ADD        ESP,0xc
//                              aibldmod.cpp:103 (16)
//         00408aab     LEA        EAX=>numberSkipCycles,[ESP + 0x54]
//         00408aaf     PUSH       0x4
//         00408ab1     PUSH       EAX
//         00408ab2     PUSH       EBP
//         00408ab3     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408ab8     ADD        ESP,0xc
//                              aibldmod.cpp:105 (16)
//         00408abb     LEA        this=>gameID,[ESP + 0x2c]
//         00408abf     PUSH       0x4
//         00408ac1     PUSH       this
//         00408ac2     PUSH       EBP
//         00408ac3     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408ac8     ADD        ESP,0xc
//                              aibldmod.cpp:107 (16)
//         00408acb     LEA        EDX=>zSize,[ESP + 0x28]
//         00408acf     PUSH       0x4
//         00408ad1     PUSH       EDX
//         00408ad2     PUSH       EBP
//         00408ad3     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408ad8     ADD        ESP,0xc
//                              aibldmod.cpp:112 (16)
//         00408adb     LEA        EAX=>z,[ESP + 0x44]
//         00408adf     PUSH       0x4
//         00408ae1     PUSH       EAX
//         00408ae2     PUSH       EBP
//         00408ae3     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408ae8     ADD        ESP,0xc
//                              aibldmod.cpp:114 (16)
//         00408aeb     LEA        this=>buildAttemptsValue,[ESP + 0x1c]
//         00408aef     PUSH       0x4
//         00408af1     PUSH       this
//         00408af2     PUSH       EBP
//         00408af3     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408af8     ADD        ESP,0xc
//                              aibldmod.cpp:116 (16)
//         00408afb     LEA        EDX=>inProgressValue,[ESP + 0x18]
//         00408aff     PUSH       0x4
//         00408b01     PUSH       EDX
//         00408b02     PUSH       EBP
//         00408b03     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408b08     ADD        ESP,0xc
//                              aibldmod.cpp:118 (16)
//         00408b0b     LEA        EAX=>terrainAdjOne,[ESP + 0x20]
//         00408b0f     PUSH       0x4
//         00408b11     PUSH       EAX
//         00408b12     PUSH       EBP
//         00408b13     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408b18     ADD        ESP,0xc
//                              aibldmod.cpp:120 (16)
//         00408b1b     LEA        this=>local_11c,[ESP + 0x6c]
//         00408b1f     PUSH       0x4
//         00408b21     PUSH       this
//         00408b22     PUSH       EBP
//         00408b23     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408b28     ADD        ESP,0xc
//                              aibldmod.cpp:122 (16)
//         00408b2b     LEA        EDX=>placeOnElevation,[ESP + 0x64]
//         00408b2f     PUSH       0x4
//         00408b31     PUSH       EDX
//         00408b32     PUSH       EBP
//         00408b33     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408b38     ADD        ESP,0xc
//                              aibldmod.cpp:124 (16)
//         00408b3b     LEA        EAX=>skipValue,[ESP + 0x24]
//         00408b3f     PUSH       0x4
//         00408b41     PUSH       EAX
//         00408b42     PUSH       EBP
//         00408b43     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408b48     ADD        ESP,0xc
//                              aibldmod.cpp:126 (16)
//         00408b4b     LEA        this=>numberBuilds,[ESP + 0x4c]
//         00408b4f     PUSH       0x4
//         00408b51     PUSH       this
//         00408b52     PUSH       EBP
//         00408b53     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408b58     ADD        ESP,0xc
//                              aibldmod.cpp:128 (16)
//         00408b5b     LEA        EDX=>buildFrom,[ESP + 0x68]
//         00408b5f     PUSH       0x4
//         00408b61     PUSH       EDX
//         00408b62     PUSH       EBP
//         00408b63     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408b68     ADD        ESP,0xc
//                              aibldmod.cpp:130 (13)
//         00408b6b     LEA        EAX=>ySize,[ESP + 0x50]
//         00408b6f     PUSH       0x4
//         00408b71     PUSH       EAX
//         00408b72     PUSH       EBP
//         00408b73     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              aibldmod.cpp:132 (30)
//         00408b78     FLD        float ptr [save_game_version]                    = 7.23
//         00408b7e     FCOMP      float ptr [DAT_0056e788]                         = CDh
//         00408b84     ADD        ESP,0xc
//         00408b87     MOV        dword ptr [ESP + builtValue],0xffffffff
//         00408b8f     FNSTSW     AX
//         00408b91     TEST       AH,0x1
//         00408b94     JNZ        LAB_00408ba6
//                              aibldmod.cpp:133 (16)
//         00408b96     LEA        this=>builtValue,[ESP + 0x14]
//         00408b9a     PUSH       0x4
//         00408b9c     PUSH       this
//         00408b9d     PUSH       EBP
//         00408b9e     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408ba3     ADD        ESP,0xc
//                               LAB_00408ba6                                                 XREF[1]:     00408b94(j)
//                              aibldmod.cpp:135 (16)
//         00408ba6     LEA        EDX=>typeID,[ESP + 0x58]
//         00408baa     PUSH       0x4
//         00408bac     PUSH       EDX
//         00408bad     PUSH       EBP
//         00408bae     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408bb3     ADD        ESP,0xc
//                              aibldmod.cpp:137 (16)
//         00408bb6     LEA        EAX=>terrainSet,[ESP + 0x60]
//         00408bba     PUSH       0x1
//         00408bbc     PUSH       EAX
//         00408bbd     PUSH       EBP
//         00408bbe     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00408bc3     ADD        ESP,0xc
//                              aibldmod.cpp:142 (115)
//         00408bc6     PUSH       0xb0
//         00408bcb     CALL       operator_new                                     void * operator_new(uint param_1)
//         00408bd0     ADD        ESP,0x4
//         00408bd3     MOV        dword ptr [ESP + name[0]],EAX
//         00408bd7     TEST       EAX,EAX
//         00408bd9     MOV        byte ptr [ESP + local_4],0x3
//         00408be1     JZ         LAB_00408c37
//         00408be3     MOV        this,dword ptr [ESP + buildFrom]
//         00408be7     MOV        EDX,dword ptr [ESP + numberBuilds]
//         00408beb     PUSH       this
//         00408bec     MOV        this,dword ptr [ESP + skipValue]
//         00408bf0     PUSH       EDX
//         00408bf1     MOV        EDX,dword ptr [ESP + placeOnElevation]
//         00408bf5     PUSH       this
//         00408bf6     MOV        this,dword ptr [ESP + gameID]
//         00408bfa     PUSH       EDX
//         00408bfb     MOV        EDX,dword ptr [ESP + numberSkipCycles]
//         00408bff     PUSH       this
//         00408c00     MOV        this,dword ptr [ESP + x]
//         00408c04     PUSH       EDX
//         00408c05     PUSH       this
//         00408c06     MOV        this,dword ptr [ESP + local_11c]
//         00408c0d     LEA        EDX=>name[4],[ESP + 0x94]
//         00408c14     PUSH       EDX
//         00408c15     MOV        EDX,dword ptr [ESP + y]
//         00408c19     PUSH       this
//         00408c1a     MOV        this,dword ptr [ESP + permanentSkip]
//         00408c21     PUSH       0x0
//         00408c23     PUSH       0x1
//         00408c25     PUSH       EDX
//         00408c26     MOV        EDX,dword ptr [ESP + z]
//         00408c2a     PUSH       this
//         00408c2b     PUSH       EDX
//         00408c2c     MOV        this,EAX
//         00408c2e     CALL       BuildItem::BuildItem                             undefined BuildItem(BuildItem * this, int par
//         00408c33     MOV        ESI,EAX
//         00408c35     JMP        LAB_00408c39
//                               LAB_00408c37                                                 XREF[1]:     00408be1(j)
//         00408c37     XOR        ESI,ESI
//                               LAB_00408c39                                                 XREF[1]:     00408c35(j)
//                              aibldmod.cpp:143 (20)
//         00408c39     MOV        EAX,dword ptr [ESP + inProgressValue]
//         00408c3d     MOV        this,ESI
//         00408c3f     PUSH       EAX
//         00408c40     MOV        byte ptr [ESP + local_4],0x2
//         00408c48     CALL       BuildItem::setBuilt                              void setBuilt(BuildItem * this, int param_1)
//                              aibldmod.cpp:144 (12)
//         00408c4d     MOV        this,dword ptr [ESP + buildAttemptsValue]
//         00408c51     PUSH       this
//         00408c52     MOV        this,ESI
//         00408c54     CALL       BuildItem::setInProgress                         void setInProgress(BuildItem * this, int para
//                              aibldmod.cpp:145 (12)
//         00408c59     MOV        EDX,dword ptr [ESP + terrainAdjOne]
//         00408c5d     MOV        this,ESI
//         00408c5f     PUSH       EDX
//         00408c60     CALL       BuildItem::setBuildAttempts                      void setBuildAttempts(BuildItem * this, int p
//                              aibldmod.cpp:146 (12)
//         00408c65     MOV        EAX,dword ptr [ESP + zSize]
//         00408c69     MOV        this,ESI
//         00408c6b     PUSH       EAX
//         00408c6c     CALL       BaseItem::setSkip                                void setSkip(BaseItem * this, int param_1)
//                              aibldmod.cpp:147 (12)
//         00408c71     MOV        this,dword ptr [ESP + xSize]
//         00408c75     PUSH       this
//         00408c76     MOV        this,ESI
//         00408c78     CALL       BaseItem::setGameID                              void setGameID(BaseItem * this, int param_1)
//                              aibldmod.cpp:148 (12)
//         00408c7d     MOV        EDX,dword ptr [ESP + uniqueID]
//         00408c81     MOV        this,ESI
//         00408c83     PUSH       EDX
//         00408c84     CALL       BaseItem::setX                                   void setX(BaseItem * this, float param_1)
//                              aibldmod.cpp:149 (12)
//         00408c89     MOV        EAX,dword ptr [ESP + buildCategory]
//         00408c8d     MOV        this,ESI
//         00408c8f     PUSH       EAX
//         00408c90     CALL       BaseItem::setY                                   void setY(BaseItem * this, float param_1)
//                              aibldmod.cpp:150 (12)
//         00408c95     MOV        this,dword ptr [ESP + terrainAdjTwo]
//         00408c99     PUSH       this
//         00408c9a     MOV        this,ESI
//         00408c9c     CALL       BaseItem::setZ                                   void setZ(BaseItem * this, float param_1)
//                              aibldmod.cpp:151 (12)
//         00408ca1     MOV        EDX,dword ptr [ESP + ySize]
//         00408ca5     MOV        this,ESI
//         00408ca7     PUSH       EDX
//         00408ca8     CALL       BuildItem::setNumberBuilds                       void setNumberBuilds(BuildItem * this, int pa
//                              aibldmod.cpp:152 (12)
//         00408cad     MOV        EAX,dword ptr [ESP + builtValue]
//         00408cb1     MOV        this,ESI
//         00408cb3     PUSH       EAX
//         00408cb4     CALL       BuildItem::setBuildCap                           void setBuildCap(BuildItem * this, int param_1)
//                              aibldmod.cpp:153 (12)
//         00408cb9     MOV        this,dword ptr [ESP + typeID]
//         00408cbd     PUSH       this
//         00408cbe     MOV        this,ESI
//         00408cc0     CALL       BuildItem::setSkipCycles                         void setSkipCycles(BuildItem * this, int para
//                              aibldmod.cpp:154 (12)
//         00408cc5     MOV        EDX,dword ptr [ESP + terrainSet]
//         00408cc9     MOV        this,ESI
//         00408ccb     PUSH       EDX
//         00408ccc     CALL       BuildItem::setPermanentSkip                      void setPermanentSkip(BuildItem * this, uchar
//                              aibldmod.cpp:157 (10)
//         00408cd1     LEA        EAX,[EBX + 0xf0]
//         00408cd7     INC        EDI
//         00408cd8     MOV        dword ptr [ESI + 0x6c],EAX
//                              aibldmod.cpp:158 (9)
//         00408cdb     MOV        EAX,dword ptr [EBX + 0x160]
//         00408ce1     MOV        dword ptr [ESI + 0x70],EAX
//                              aibldmod.cpp:159 (11)
//         00408ce4     MOV        dword ptr [EAX + 0x6c],ESI
//         00408ce7     MOV        EAX,dword ptr [EBX + 0x1a0]
//         00408ced     CMP        EDI,EAX
//                              aibldmod.cpp:160 (12)
//         00408cef     MOV        dword ptr [EBX + 0x160],ESI
//         00408cf5     JL         LAB_00408a0c
//                               LAB_00408cfb                                                 XREF[1]:     00408a06(j)
//                              aibldmod.cpp:175 (29)
//         00408cfb     MOV        this,dword ptr [ESP + local_c]
//         00408d02     POP        EDI
//         00408d03     POP        ESI
//         00408d04     MOV        EAX,EBX
//         00408d06     POP        EBP
//         00408d07     MOV        dword ptr FS:[0x0],this
//         00408d0e     POP        EBX
//         00408d0f     ADD        ESP,0x178
//         00408d15     RET        0x8
//         00408d18     ??         90h
//         00408d19     NOP
//         00408d1a     NOP
//         00408d1b     NOP
//         00408d1c     NOP
//         00408d1d     NOP
//         00408d1e     NOP
//         00408d1f     NOP
}

BuildAIModule::~BuildAIModule() {
    /* TODO: Stub */
//                              void __thiscall ~BuildAIModule(BuildAIModule * this)
//              void              <VOID>         <RETURN>
//              BuildAIModule *   ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     00408d7e(W), 00408d93(W), 00408dc3(W), 00408dce(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00408ddb(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00408d6a(W)
//                               ??1BuildAIModule@@UAE@XZ                                     XREF[2]:     `scalar_deleting_destructor':00408
//                               BuildAIModule::~BuildAIModule                                             ~TribeBuildAIModule:004d3b06(c)
//                              aibldmod.cpp:180 (36)
//         00408d50     PUSH       -0x1
//         00408d52     PUSH       FUN_0055c4d4
//         00408d57     MOV        EAX,FS:[0x0]
//         00408d5d     PUSH       EAX
//         00408d5e     MOV        dword ptr FS:[0x0],ESP
//         00408d65     PUSH       this
//         00408d66     PUSH       EBX
//         00408d67     PUSH       ESI
//         00408d68     MOV        ESI,this
//         00408d6a     MOV        dword ptr [ESP + local_10],ESI
//         00408d6e     MOV        dword ptr [ESI],BuildAIModule::`vftable'         = 00408820
//                              aibldmod.cpp:181 (20)
//         00408d74     MOV        EAX,dword ptr [ESI + 0x1a0]
//         00408d7a     XOR        EBX,EBX
//         00408d7c     CMP        EAX,EBX
//         00408d7e     MOV        dword ptr [ESP + local_4],0x2
//         00408d86     JLE        LAB_00408d8d
//                              aibldmod.cpp:182 (5)
//         00408d88     CALL       BuildAIModule::removeOldList                     void removeOldList(BuildAIModule * this)
//                               LAB_00408d8d                                                 XREF[1]:     00408d86(j)
//                              aibldmod.cpp:183 (95)
//         00408d8d     MOV        EAX,dword ptr [ESI + 0x5ac]
//         00408d93     MOV        byte ptr [ESP + local_4],0x1
//         00408d98     CMP        EAX,EBX
//         00408d9a     JZ         LAB_00408dab
//         00408d9c     PUSH       EAX
//         00408d9d     CALL       operator_delete                                  void operator_delete(void * param_1)
//         00408da2     ADD        ESP,0x4
//         00408da5     MOV        dword ptr [ESI + 0x5ac],EBX
//                               LAB_00408dab                                                 XREF[1]:     00408d9a(j)
//         00408dab     LEA        this,[ESI + 0xf0]
//         00408db1     MOV        dword ptr [ESI + 0x5b0],EBX
//         00408db7     MOV        dword ptr [ESI + 0x5b4],EBX
//         00408dbd     MOV        dword ptr [ESI + 0x5b8],EBX
//         00408dc3     MOV        byte ptr [ESP + local_4],BL
//         00408dc7     CALL       BuildItem::~BuildItem                            void ~BuildItem(BuildItem * this)
//         00408dcc     MOV        this,ESI
//         00408dce     MOV        dword ptr [ESP + local_4],0xffffffff
//         00408dd6     CALL       AIModule::~AIModule                              void ~AIModule(AIModule * this)
//         00408ddb     MOV        this,dword ptr [ESP + local_c]
//         00408ddf     POP        ESI
//         00408de0     MOV        dword ptr FS:[0x0],this
//         00408de7     POP        EBX
//         00408de8     ADD        ESP,0x10
//         00408deb     RET
//         00408dec     ??         90h
//         00408ded     NOP
//         00408dee     NOP
//         00408def     NOP
}

int BuildAIModule::save(int param_1) {
    /* TODO: Stub */
//                              int __thiscall save(BuildAIModule * this, int param_1)
//              int               EAX:4          <RETURN>
//              BuildAIModule *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00408dfa(R)
//              char[257]         Stack[-0x108   tempString                XREF[4,20]:  00408e0d(W), 00408fc0(R), 00408fd5(W), 004092c1(R),
//                                                                                     00408e2a(*), 00408e44(*), 00408e5f(*), 00408e70(*),
//                                                                                     00408e90(*), 00408eaa(*), 00408ec8(*), 00408ed1(*),
//                                                                                     00408ef6(*), 00408f10(*), 00408f2b(*), 00408f3c(*),
//                                                                                     00408f5c(*), 00408f76(*), 00408f94(*), 00408fa2(*)
//              undefined         Stack[-0x109   local_109                 XREF[2]:     004092ad(*), 004092b5(W)
//              uchar             Stack[-0x10d   tempBYTE
//              int               Stack[-0x114   tempBOOL                  XREF[12]:    004090a8(W), 004090ac(*), 004090c3(W), 004090c7(*),
//                                                                                     004090de(W), 004090e2(*), 004090f9(W), 004090fd(*),
//                                                                                     00409114(W), 00409118(*), 0040912f(W), 00409133(*)
//              float             Stack[-0x118   tempFloat                 XREF[34]:    00408e50(W), 00408e54(*), 00408eb6(W), 00408eba(*),
//                                                                                     00408f1c(W), 00408f20(*), 00408f82(W), 00408f86(*),
//                                                                                     00409021(W), 00409025(*), 00409057(W), 0040905b(*),
//                                                                                     00409072(*), 0040907a(W), 0040908d(*), 00409095(W),
//                                                                                     00409165(*), 0040916d(W), 004091b6(W), 004091ba(*)
//              int               Stack[-0x11c   tempInt
//                               ?save@BuildAIModule@@UAEHH@Z                                 XREF[2]:     0056e774(*), 0057547c(*)
//                               BuildAIModule::save
//                              aibldmod.cpp:188 (10)
//         00408df0     SUB        ESP,0x118
//         00408df6     PUSH       EBX
//         00408df7     MOV        EBX,this
//         00408df9     PUSH       EBP
//                              aibldmod.cpp:195 (28)
//         00408dfa     MOV        EBP,dword ptr [ESP + param_1]
//         00408e01     PUSH       ESI
//         00408e02     PUSH       EDI
//         00408e03     LEA        EAX,[EBX + 0x1a0]
//         00408e09     PUSH       0x4
//         00408e0b     PUSH       EAX
//         00408e0c     PUSH       EBP
//         00408e0d     MOV        dword ptr [ESP + tempString[0]],EBX
//         00408e11     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              aibldmod.cpp:198 (30)
//         00408e16     LEA        EDI,[EBX + 0x1a4]
//         00408e1c     OR         this,0xffffffff
//         00408e1f     XOR        EAX,EAX
//         00408e21     ADD        ESP,0xc
//         00408e24     SCASB.RE   ES:EDI
//         00408e26     NOT        this
//         00408e28     SUB        EDI,this
//         00408e2a     LEA        EDX=>tempString[4],[ESP + 0x24]
//         00408e2e     MOV        EAX,this
//         00408e30     MOV        ESI,EDI
//         00408e32     MOV        EDI,EDX
//                              aibldmod.cpp:200 (43)
//         00408e34     PUSH       0x4
//         00408e36     SHR        this,0x2
//         00408e39     MOVSD.REP  ES:EDI,ESI
//         00408e3b     MOV        this,EAX
//         00408e3d     XOR        EAX,EAX
//         00408e3f     AND        this,0x3
//         00408e42     MOVSB.REP  ES:EDI,ESI
//         00408e44     LEA        EDI=>tempString[4],[ESP + 0x28]
//         00408e48     OR         this,0xffffffff
//         00408e4b     SCASB.RE   ES:EDI
//         00408e4d     NOT        this
//         00408e4f     DEC        this
//         00408e50     MOV        dword ptr [ESP + tempFloat],this
//         00408e54     LEA        this=>tempFloat,[ESP + 0x14]
//         00408e58     PUSH       this
//         00408e59     PUSH       EBP
//         00408e5a     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              aibldmod.cpp:201 (29)
//         00408e5f     LEA        EDI=>tempString[4],[ESP + 0x30]
//         00408e63     OR         this,0xffffffff
//         00408e66     XOR        EAX,EAX
//         00408e68     ADD        ESP,0xc
//         00408e6b     SCASB.RE   ES:EDI
//         00408e6d     NOT        this
//         00408e6f     DEC        this
//         00408e70     LEA        EDX=>tempString[4],[ESP + 0x24]
//         00408e74     PUSH       this
//         00408e75     PUSH       EDX
//         00408e76     PUSH       EBP
//         00408e77     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              aibldmod.cpp:203 (30)
//         00408e7c     LEA        EDI,[EBX + 0x2a5]
//         00408e82     OR         this,0xffffffff
//         00408e85     XOR        EAX,EAX
//         00408e87     ADD        ESP,0xc
//         00408e8a     SCASB.RE   ES:EDI
//         00408e8c     NOT        this
//         00408e8e     SUB        EDI,this
//         00408e90     LEA        EDX=>tempString[4],[ESP + 0x24]
//         00408e94     MOV        EAX,this
//         00408e96     MOV        ESI,EDI
//         00408e98     MOV        EDI,EDX
//                              aibldmod.cpp:205 (46)
//         00408e9a     PUSH       0x4
//         00408e9c     SHR        this,0x2
//         00408e9f     MOVSD.REP  ES:EDI,ESI
//         00408ea1     MOV        this,EAX
//         00408ea3     XOR        EAX,EAX
//         00408ea5     AND        this,0x3
//         00408ea8     MOVSB.REP  ES:EDI,ESI
//         00408eaa     LEA        EDI=>tempString[4],[ESP + 0x28]
//         00408eae     OR         this,0xffffffff
//         00408eb1     SCASB.RE   ES:EDI
//         00408eb3     NOT        this
//         00408eb5     DEC        this
//         00408eb6     MOV        dword ptr [ESP + tempFloat],this
//         00408eba     LEA        this=>tempFloat,[ESP + 0x14]
//         00408ebe     PUSH       this
//         00408ebf     PUSH       EBP
//         00408ec0     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00408ec5     ADD        ESP,0xc
//                              aibldmod.cpp:206 (26)
//         00408ec8     LEA        EDI=>tempString[4],[ESP + 0x24]
//         00408ecc     OR         this,0xffffffff
//         00408ecf     XOR        EAX,EAX
//         00408ed1     LEA        EDX=>tempString[4],[ESP + 0x24]
//         00408ed5     SCASB.RE   ES:EDI
//         00408ed7     NOT        this
//         00408ed9     DEC        this
//         00408eda     PUSH       this
//         00408edb     PUSH       EDX
//         00408edc     PUSH       EBP
//         00408edd     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              aibldmod.cpp:208 (30)
//         00408ee2     LEA        EDI,[EBX + 0x3a6]
//         00408ee8     OR         this,0xffffffff
//         00408eeb     XOR        EAX,EAX
//         00408eed     ADD        ESP,0xc
//         00408ef0     SCASB.RE   ES:EDI
//         00408ef2     NOT        this
//         00408ef4     SUB        EDI,this
//         00408ef6     LEA        EDX=>tempString[4],[ESP + 0x24]
//         00408efa     MOV        EAX,this
//         00408efc     MOV        ESI,EDI
//         00408efe     MOV        EDI,EDX
//                              aibldmod.cpp:210 (43)
//         00408f00     PUSH       0x4
//         00408f02     SHR        this,0x2
//         00408f05     MOVSD.REP  ES:EDI,ESI
//         00408f07     MOV        this,EAX
//         00408f09     XOR        EAX,EAX
//         00408f0b     AND        this,0x3
//         00408f0e     MOVSB.REP  ES:EDI,ESI
//         00408f10     LEA        EDI=>tempString[4],[ESP + 0x28]
//         00408f14     OR         this,0xffffffff
//         00408f17     SCASB.RE   ES:EDI
//         00408f19     NOT        this
//         00408f1b     DEC        this
//         00408f1c     MOV        dword ptr [ESP + tempFloat],this
//         00408f20     LEA        this=>tempFloat,[ESP + 0x14]
//         00408f24     PUSH       this
//         00408f25     PUSH       EBP
//         00408f26     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              aibldmod.cpp:211 (29)
//         00408f2b     LEA        EDI=>tempString[4],[ESP + 0x30]
//         00408f2f     OR         this,0xffffffff
//         00408f32     XOR        EAX,EAX
//         00408f34     ADD        ESP,0xc
//         00408f37     SCASB.RE   ES:EDI
//         00408f39     NOT        this
//         00408f3b     DEC        this
//         00408f3c     LEA        EDX=>tempString[4],[ESP + 0x24]
//         00408f40     PUSH       this
//         00408f41     PUSH       EDX
//         00408f42     PUSH       EBP
//         00408f43     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              aibldmod.cpp:213 (30)
//         00408f48     LEA        EDI,[EBX + 0x4a7]
//         00408f4e     OR         this,0xffffffff
//         00408f51     XOR        EAX,EAX
//         00408f53     ADD        ESP,0xc
//         00408f56     SCASB.RE   ES:EDI
//         00408f58     NOT        this
//         00408f5a     SUB        EDI,this
//         00408f5c     LEA        EDX=>tempString[4],[ESP + 0x24]
//         00408f60     MOV        EAX,this
//         00408f62     MOV        ESI,EDI
//         00408f64     MOV        EDI,EDX
//                              aibldmod.cpp:215 (46)
//         00408f66     PUSH       0x4
//         00408f68     SHR        this,0x2
//         00408f6b     MOVSD.REP  ES:EDI,ESI
//         00408f6d     MOV        this,EAX
//         00408f6f     XOR        EAX,EAX
//         00408f71     AND        this,0x3
//         00408f74     MOVSB.REP  ES:EDI,ESI
//         00408f76     LEA        EDI=>tempString[4],[ESP + 0x28]
//         00408f7a     OR         this,0xffffffff
//         00408f7d     SCASB.RE   ES:EDI
//         00408f7f     NOT        this
//         00408f81     DEC        this
//         00408f82     MOV        dword ptr [ESP + tempFloat],this
//         00408f86     LEA        this=>tempFloat,[ESP + 0x14]
//         00408f8a     PUSH       this
//         00408f8b     PUSH       EBP
//         00408f8c     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00408f91     ADD        ESP,0xc
//                              aibldmod.cpp:216 (29)
//         00408f94     LEA        EDI=>tempString[4],[ESP + 0x24]
//         00408f98     OR         this,0xffffffff
//         00408f9b     XOR        EAX,EAX
//         00408f9d     SCASB.RE   ES:EDI
//         00408f9f     NOT        this
//         00408fa1     DEC        this
//         00408fa2     LEA        EDX=>tempString[4],[ESP + 0x24]
//         00408fa6     PUSH       this
//         00408fa7     PUSH       EDX
//         00408fa8     PUSH       EBP
//         00408fa9     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00408fae     ADD        ESP,0xc
//                              aibldmod.cpp:218 (15)
//         00408fb1     LEA        EAX,[EBX + 0x5a8]
//         00408fb7     PUSH       0x4
//         00408fb9     PUSH       EAX
//         00408fba     PUSH       EBP
//         00408fbb     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              aibldmod.cpp:224 (39)
//         00408fc0     MOV        this,dword ptr [ESP + tempString[0]]
//         00408fc4     MOV        EBX,dword ptr [EBX + 0x15c]
//         00408fca     ADD        ESP,0xc
//         00408fcd     LEA        EAX,[ECX + this->buildList._padding_]
//         00408fd3     CMP        EBX,EAX
//         00408fd5     MOV        dword ptr [ESP + tempString[0]],EAX
//         00408fd9     JZ         LAB_004092d0
//                               LAB_00408fdf                                                 XREF[1]:     004092ca(j)
//         00408fdf     TEST       EBX,EBX
//         00408fe1     JZ         LAB_004092d0
//                              aibldmod.cpp:226 (24)
//         00408fe7     MOV        this,EBX
//         00408fe9     CALL       BaseItem::name                                   char * name(BaseItem * this)
//         00408fee     MOV        EDI,EAX
//         00408ff0     OR         this,0xffffffff
//         00408ff3     XOR        EAX,EAX
//         00408ff5     LEA        EDX=>tempString[4],[ESP + 0x24]
//         00408ff9     SCASB.RE   ES:EDI
//         00408ffb     NOT        this
//         00408ffd     SUB        EDI,this
//                              aibldmod.cpp:228 (49)
//         00408fff     PUSH       0x4
//         00409001     MOV        EAX,this
//         00409003     MOV        ESI,EDI
//         00409005     MOV        EDI,EDX
//         00409007     SHR        this,0x2
//         0040900a     MOVSD.REP  ES:EDI,ESI
//         0040900c     MOV        this,EAX
//         0040900e     XOR        EAX,EAX
//         00409010     AND        this,0x3
//         00409013     MOVSB.REP  ES:EDI,ESI
//         00409015     LEA        EDI=>tempString[4],[ESP + 0x28]
//         00409019     OR         this,0xffffffff
//         0040901c     SCASB.RE   ES:EDI
//         0040901e     NOT        this
//         00409020     DEC        this
//         00409021     MOV        dword ptr [ESP + tempFloat],this
//         00409025     LEA        this=>tempFloat,[ESP + 0x14]
//         00409029     PUSH       this
//         0040902a     PUSH       EBP
//         0040902b     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              aibldmod.cpp:229 (32)
//         00409030     LEA        EDI=>tempString[4],[ESP + 0x30]
//         00409034     OR         this,0xffffffff
//         00409037     XOR        EAX,EAX
//         00409039     ADD        ESP,0xc
//         0040903c     SCASB.RE   ES:EDI
//         0040903e     NOT        this
//         00409040     DEC        this
//         00409041     LEA        EDX=>tempString[4],[ESP + 0x24]
//         00409045     PUSH       this
//         00409046     PUSH       EDX
//         00409047     PUSH       EBP
//         00409048     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0040904d     ADD        ESP,0xc
//                              aibldmod.cpp:230 (11)
//         00409050     MOV        this,EBX
//         00409052     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
//         00409057     MOV        dword ptr [ESP + tempFloat],EAX
//                              aibldmod.cpp:231 (16)
//         0040905b     LEA        EAX=>tempFloat,[ESP + 0x10]
//         0040905f     PUSH       0x4
//         00409061     PUSH       EAX
//         00409062     PUSH       EBP
//         00409063     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00409068     ADD        ESP,0xc
//                              aibldmod.cpp:232 (7)
//         0040906b     MOV        this,EBX
//         0040906d     CALL       BaseItem::gameID                                 int gameID(BaseItem * this)
//                              aibldmod.cpp:233 (20)
//         00409072     LEA        this=>tempFloat,[ESP + 0x10]
//         00409076     PUSH       0x4
//         00409078     PUSH       this
//         00409079     PUSH       EBP
//         0040907a     MOV        dword ptr [ESP + tempFloat],EAX
//         0040907e     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00409083     ADD        ESP,0xc
//                              aibldmod.cpp:234 (7)
//         00409086     MOV        this,EBX
//         00409088     CALL       BaseItem::uniqueID                               int uniqueID(BaseItem * this)
//                              aibldmod.cpp:235 (20)
//         0040908d     LEA        EDX=>tempFloat,[ESP + 0x10]
//         00409091     PUSH       0x4
//         00409093     PUSH       EDX
//         00409094     PUSH       EBP
//         00409095     MOV        dword ptr [ESP + tempFloat],EAX
//         00409099     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0040909e     ADD        ESP,0xc
//                              aibldmod.cpp:236 (11)
//         004090a1     MOV        this,EBX
//         004090a3     CALL       BaseItem::x                                      float x(BaseItem * this)
//         004090a8     FSTP       float ptr [ESP + tempBOOL]
//                              aibldmod.cpp:237 (16)
//         004090ac     LEA        EAX=>tempBOOL,[ESP + 0x14]
//         004090b0     PUSH       0x4
//         004090b2     PUSH       EAX
//         004090b3     PUSH       EBP
//         004090b4     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004090b9     ADD        ESP,0xc
//                              aibldmod.cpp:238 (11)
//         004090bc     MOV        this,EBX
//         004090be     CALL       BaseItem::y                                      float y(BaseItem * this)
//         004090c3     FSTP       float ptr [ESP + tempBOOL]
//                              aibldmod.cpp:239 (16)
//         004090c7     LEA        this=>tempBOOL,[ESP + 0x14]
//         004090cb     PUSH       0x4
//         004090cd     PUSH       this
//         004090ce     PUSH       EBP
//         004090cf     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004090d4     ADD        ESP,0xc
//                              aibldmod.cpp:240 (11)
//         004090d7     MOV        this,EBX
//         004090d9     CALL       BaseItem::z                                      float z(BaseItem * this)
//         004090de     FSTP       float ptr [ESP + tempBOOL]
//                              aibldmod.cpp:241 (16)
//         004090e2     LEA        EDX=>tempBOOL,[ESP + 0x14]
//         004090e6     PUSH       0x4
//         004090e8     PUSH       EDX
//         004090e9     PUSH       EBP
//         004090ea     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004090ef     ADD        ESP,0xc
//                              aibldmod.cpp:242 (11)
//         004090f2     MOV        this,EBX
//         004090f4     CALL       BaseItem::xSize                                  float xSize(BaseItem * this)
//         004090f9     FSTP       float ptr [ESP + tempBOOL]
//                              aibldmod.cpp:243 (16)
//         004090fd     LEA        EAX=>tempBOOL,[ESP + 0x14]
//         00409101     PUSH       0x4
//         00409103     PUSH       EAX
//         00409104     PUSH       EBP
//         00409105     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0040910a     ADD        ESP,0xc
//                              aibldmod.cpp:244 (11)
//         0040910d     MOV        this,EBX
//         0040910f     CALL       BaseItem::ySize                                  float ySize(BaseItem * this)
//         00409114     FSTP       float ptr [ESP + tempBOOL]
//                              aibldmod.cpp:245 (16)
//         00409118     LEA        this=>tempBOOL,[ESP + 0x14]
//         0040911c     PUSH       0x4
//         0040911e     PUSH       this
//         0040911f     PUSH       EBP
//         00409120     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00409125     ADD        ESP,0xc
//                              aibldmod.cpp:246 (11)
//         00409128     MOV        this,EBX
//         0040912a     CALL       BaseItem::zSize                                  float zSize(BaseItem * this)
//         0040912f     FSTP       float ptr [ESP + tempBOOL]
//                              aibldmod.cpp:247 (16)
//         00409133     LEA        EDX=>tempBOOL,[ESP + 0x14]
//         00409137     PUSH       0x4
//         00409139     PUSH       EDX
//         0040913a     PUSH       EBP
//         0040913b     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00409140     ADD        ESP,0xc
//                              aibldmod.cpp:248 (11)
//         00409143     MOV        this,EBX
//         00409145     CALL       BaseItem::skip                                   int skip(BaseItem * this)
//         0040914a     MOV        dword ptr [ESP + Stack[-0x110]],EAX
//                              aibldmod.cpp:249 (16)
//         0040914e     LEA        EAX=>Stack[-0x110],[ESP + 0x18]
//         00409152     PUSH       0x4
//         00409154     PUSH       EAX
//         00409155     PUSH       EBP
//         00409156     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0040915b     ADD        ESP,0xc
//                              aibldmod.cpp:252 (7)
//         0040915e     MOV        this,EBX
//         00409160     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
//                              aibldmod.cpp:253 (20)
//         00409165     LEA        this=>tempFloat,[ESP + 0x10]
//         00409169     PUSH       0x4
//         0040916b     PUSH       this
//         0040916c     PUSH       EBP
//         0040916d     MOV        dword ptr [ESP + tempFloat],EAX
//         00409171     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00409176     ADD        ESP,0xc
//                              aibldmod.cpp:254 (7)
//         00409179     MOV        this,EBX
//         0040917b     CALL       BuildItem::inProgress                            int inProgress(BuildItem * this)
//                              aibldmod.cpp:255 (20)
//         00409180     LEA        EDX=>Stack[-0x110],[ESP + 0x18]
//         00409184     PUSH       0x4
//         00409186     PUSH       EDX
//         00409187     PUSH       EBP
//         00409188     MOV        dword ptr [ESP + Stack[-0x110]],EAX
//         0040918c     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00409191     ADD        ESP,0xc
//                              aibldmod.cpp:256 (11)
//         00409194     MOV        this,EBX
//         00409196     CALL       BuildItem::built                                 int built(BuildItem * this)
//         0040919b     MOV        dword ptr [ESP + Stack[-0x110]],EAX
//                              aibldmod.cpp:257 (16)
//         0040919f     LEA        EAX=>Stack[-0x110],[ESP + 0x18]
//         004091a3     PUSH       0x4
//         004091a5     PUSH       EAX
//         004091a6     PUSH       EBP
//         004091a7     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004091ac     ADD        ESP,0xc
//                              aibldmod.cpp:258 (11)
//         004091af     MOV        this,EBX
//         004091b1     CALL       BuildItem::buildAttempts                         int buildAttempts(BuildItem * this)
//         004091b6     MOV        dword ptr [ESP + tempFloat],EAX
//                              aibldmod.cpp:259 (16)
//         004091ba     LEA        this=>tempFloat,[ESP + 0x10]
//         004091be     PUSH       0x4
//         004091c0     PUSH       this
//         004091c1     PUSH       EBP
//         004091c2     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004091c7     ADD        ESP,0xc
//                              aibldmod.cpp:260 (7)
//         004091ca     MOV        this,EBX
//         004091cc     CALL       BuildItem::buildFrom                             int buildFrom(BuildItem * this)
//                              aibldmod.cpp:261 (20)
//         004091d1     LEA        EDX=>tempFloat,[ESP + 0x10]
//         004091d5     PUSH       0x4
//         004091d7     PUSH       EDX
//         004091d8     PUSH       EBP
//         004091d9     MOV        dword ptr [ESP + tempFloat],EAX
//         004091dd     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004091e2     ADD        ESP,0xc
//                              aibldmod.cpp:262 (11)
//         004091e5     MOV        this,EBX
//         004091e7     CALL       BuildItem::terrainSet                            int terrainSet(BuildItem * this)
//         004091ec     MOV        dword ptr [ESP + tempFloat],EAX
//                              aibldmod.cpp:263 (16)
//         004091f0     LEA        EAX=>tempFloat,[ESP + 0x10]
//         004091f4     PUSH       0x4
//         004091f6     PUSH       EAX
//         004091f7     PUSH       EBP
//         004091f8     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004091fd     ADD        ESP,0xc
//                              aibldmod.cpp:264 (9)
//         00409200     MOV        this,EBX
//         00409202     PUSH       0x1
//         00409204     CALL       BuildItem::terrainAdjacency                      int terrainAdjacency(BuildItem * this, int pa
//                              aibldmod.cpp:265 (20)
//         00409209     LEA        this=>tempFloat,[ESP + 0x10]
//         0040920d     PUSH       0x4
//         0040920f     PUSH       this
//         00409210     PUSH       EBP
//         00409211     MOV        dword ptr [ESP + tempFloat],EAX
//         00409215     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0040921a     ADD        ESP,0xc
//                              aibldmod.cpp:266 (9)
//         0040921d     MOV        this,EBX
//         0040921f     PUSH       0x2
//         00409221     CALL       BuildItem::terrainAdjacency                      int terrainAdjacency(BuildItem * this, int pa
//                              aibldmod.cpp:267 (20)
//         00409226     LEA        EDX=>tempFloat,[ESP + 0x10]
//         0040922a     PUSH       0x4
//         0040922c     PUSH       EDX
//         0040922d     PUSH       EBP
//         0040922e     MOV        dword ptr [ESP + tempFloat],EAX
//         00409232     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00409237     ADD        ESP,0xc
//                              aibldmod.cpp:268 (11)
//         0040923a     MOV        this,EBX
//         0040923c     CALL       BuildItem::placeOnElevation                      int placeOnElevation(BuildItem * this)
//         00409241     MOV        dword ptr [ESP + Stack[-0x110]],EAX
//                              aibldmod.cpp:269 (16)
//         00409245     LEA        EAX=>Stack[-0x110],[ESP + 0x18]
//         00409249     PUSH       0x4
//         0040924b     PUSH       EAX
//         0040924c     PUSH       EBP
//         0040924d     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00409252     ADD        ESP,0xc
//                              aibldmod.cpp:270 (7)
//         00409255     MOV        this,EBX
//         00409257     CALL       BuildItem::numberBuilds                          int numberBuilds(BuildItem * this)
//                              aibldmod.cpp:271 (20)
//         0040925c     LEA        this=>tempFloat,[ESP + 0x10]
//         00409260     PUSH       0x4
//         00409262     PUSH       this
//         00409263     PUSH       EBP
//         00409264     MOV        dword ptr [ESP + tempFloat],EAX
//         00409268     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0040926d     ADD        ESP,0xc
//                              aibldmod.cpp:272 (7)
//         00409270     MOV        this,EBX
//         00409272     CALL       BuildItem::buildCap                              int buildCap(BuildItem * this)
//                              aibldmod.cpp:273 (20)
//         00409277     LEA        EDX=>tempFloat,[ESP + 0x10]
//         0040927b     PUSH       0x4
//         0040927d     PUSH       EDX
//         0040927e     PUSH       EBP
//         0040927f     MOV        dword ptr [ESP + tempFloat],EAX
//         00409283     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00409288     ADD        ESP,0xc
//                              aibldmod.cpp:274 (11)
//         0040928b     MOV        this,EBX
//         0040928d     CALL       BuildItem::skipCycles                            int skipCycles(BuildItem * this)
//         00409292     MOV        dword ptr [ESP + tempFloat],EAX
//                              aibldmod.cpp:275 (16)
//         00409296     LEA        EAX=>tempFloat,[ESP + 0x10]
//         0040929a     PUSH       0x4
//         0040929c     PUSH       EAX
//         0040929d     PUSH       EBP
//         0040929e     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004092a3     ADD        ESP,0xc
//                              aibldmod.cpp:276 (7)
//         004092a6     MOV        this,EBX
//         004092a8     CALL       BuildItem::permanentSkip                         uchar permanentSkip(BuildItem * this)
//                              aibldmod.cpp:277 (17)
//         004092ad     LEA        this=>local_109,[ESP + 0x1f]
//         004092b1     PUSH       0x1
//         004092b3     PUSH       this
//         004092b4     PUSH       EBP
//         004092b5     MOV        byte ptr [ESP + local_109],AL
//         004092b9     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              aibldmod.cpp:280 (18)
//         004092be     MOV        EBX,dword ptr [EBX + 0x6c]
//         004092c1     MOV        EAX,dword ptr [ESP + tempString[0]]
//         004092c5     ADD        ESP,0xc
//         004092c8     CMP        EBX,EAX
//         004092ca     JNZ        LAB_00408fdf
//                               LAB_004092d0                                                 XREF[2]:     00408fd9(j), 00408fe1(j)
//                              aibldmod.cpp:283 (18)
//         004092d0     POP        EDI
//         004092d1     POP        ESI
//         004092d2     POP        EBP
//         004092d3     MOV        EAX,0x1
//         004092d8     POP        EBX
//         004092d9     ADD        ESP,0x118
//         004092df     RET        0x4
//         004092e2     ??         90h
//         004092e3     NOP
//         004092e4     NOP
//         004092e5     NOP
//         004092e6     NOP
//         004092e7     NOP
//         004092e8     NOP
//         004092e9     NOP
//         004092ea     NOP
//         004092eb     NOP
//         004092ec     NOP
//         004092ed     NOP
//         004092ee     NOP
//         004092ef     NOP
    return 0;
}

void BuildAIModule::displayBuildList() {
    /* TODO: Stub */
//                              void __thiscall displayBuildList(BuildAIModule * this)
//              void              <VOID>         <RETURN>
//              BuildAIModule *   ECX:4 (auto)   this
//                               ?displayBuildList@BuildAIModule@@UAEXXZ                      XREF[2]:     0056e778(*), 00575480(*)
//                               BuildAIModule::displayBuildList
//                              aibldmod.cpp:288 (5)
//         004092f0     PUSH       EBX
//         004092f1     PUSH       ESI
//         004092f2     PUSH       EDI
//         004092f3     MOV        EDI,this
//                              aibldmod.cpp:289 (18)
//         004092f5     LEA        EAX,[EDI + 0x1a4]
//         004092fb     PUSH       EAX
//         004092fc     PUSH       s_Build_list_'%s':                               = "Build list '%s':"
//         00409301     PUSH       EDI
//         00409302     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//                              aibldmod.cpp:290 (6)
//         00409307     MOV        ESI,dword ptr [EDI + 0x15c]
//                              aibldmod.cpp:291 (25)
//         0040930d     LEA        EBX,[EDI + 0xf0]
//         00409313     ADD        ESP,0xc
//         00409316     CMP        ESI,EBX
//         00409318     JZ         LAB_0040942a
//                               LAB_0040931e                                                 XREF[1]:     00409424(j)
//         0040931e     TEST       ESI,ESI
//         00409320     JZ         LAB_0040942a
//                              aibldmod.cpp:292 (10)
//         00409326     MOV        this,ESI
//         00409328     CALL       BuildItem::built                                 int built(BuildItem * this)
//         0040932d     CMP        EAX,0x1
//                              aibldmod.cpp:298 (116)
//         00409330     MOV        this,ESI
//         00409332     JNZ        LAB_004093a6
//         00409334     CALL       BuildItem::skipCycles                            int skipCycles(BuildItem * this)
//         00409339     PUSH       EAX
//         0040933a     MOV        this,ESI
//         0040933c     CALL       BuildItem::permanentSkip                         uchar permanentSkip(BuildItem * this)
//         00409341     AND        EAX,0xff
//         00409346     MOV        this,ESI
//         00409348     PUSH       EAX
//         00409349     CALL       BuildItem::buildFrom                             int buildFrom(BuildItem * this)
//         0040934e     PUSH       EAX
//         0040934f     MOV        this,ESI
//         00409351     CALL       BuildItem::buildCap                              int buildCap(BuildItem * this)
//         00409356     PUSH       EAX
//         00409357     MOV        this,ESI
//         00409359     CALL       BuildItem::numberBuilds                          int numberBuilds(BuildItem * this)
//         0040935e     PUSH       EAX
//         0040935f     MOV        this,ESI
//         00409361     CALL       BaseItem::skip                                   int skip(BaseItem * this)
//         00409366     PUSH       EAX
//         00409367     MOV        this,ESI
//         00409369     CALL       BuildItem::buildAttempts                         int buildAttempts(BuildItem * this)
//         0040936e     PUSH       EAX
//         0040936f     MOV        this,ESI
//         00409371     CALL       BuildItem::inProgress                            int inProgress(BuildItem * this)
//         00409376     PUSH       EAX
//         00409377     MOV        this,ESI
//         00409379     CALL       BaseItem::uniqueID                               int uniqueID(BaseItem * this)
//         0040937e     PUSH       EAX
//         0040937f     MOV        this,ESI
//         00409381     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
//         00409386     PUSH       EAX
//         00409387     MOV        this,ESI
//         00409389     CALL       BaseItem::gameID                                 int gameID(BaseItem * this)
//         0040938e     PUSH       EAX
//         0040938f     MOV        this,ESI
//         00409391     CALL       BaseItem::name                                   char * name(BaseItem * this)
//         00409396     PUSH       EAX
//         00409397     MOV        this,ESI
//         00409399     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
//         0040939e     PUSH       EAX
//         0040939f     PUSH       s_BLT_Type=%-4d_%-20s_gID=%-4d_Cat               = "BLT Type=%-4d %-20s gID=%-4d Cat=%d uID=%-
//                              aibldmod.cpp:299 (2)
//         004093a4     JMP        LAB_00409416
//                               LAB_004093a6                                                 XREF[1]:     00409332(j)
//                              aibldmod.cpp:305 (118)
//         004093a6     CALL       BuildItem::skipCycles                            int skipCycles(BuildItem * this)
//         004093ab     PUSH       EAX
//         004093ac     MOV        this,ESI
//         004093ae     CALL       BuildItem::permanentSkip                         uchar permanentSkip(BuildItem * this)
//         004093b3     AND        EAX,0xff
//         004093b8     MOV        this,ESI
//         004093ba     PUSH       EAX
//         004093bb     CALL       BuildItem::buildFrom                             int buildFrom(BuildItem * this)
//         004093c0     PUSH       EAX
//         004093c1     MOV        this,ESI
//         004093c3     CALL       BuildItem::buildCap                              int buildCap(BuildItem * this)
//         004093c8     PUSH       EAX
//         004093c9     MOV        this,ESI
//         004093cb     CALL       BuildItem::numberBuilds                          int numberBuilds(BuildItem * this)
//         004093d0     PUSH       EAX
//         004093d1     MOV        this,ESI
//         004093d3     CALL       BaseItem::skip                                   int skip(BaseItem * this)
//         004093d8     PUSH       EAX
//         004093d9     MOV        this,ESI
//         004093db     CALL       BuildItem::buildAttempts                         int buildAttempts(BuildItem * this)
//         004093e0     PUSH       EAX
//         004093e1     MOV        this,ESI
//         004093e3     CALL       BuildItem::inProgress                            int inProgress(BuildItem * this)
//         004093e8     PUSH       EAX
//         004093e9     MOV        this,ESI
//         004093eb     CALL       BaseItem::uniqueID                               int uniqueID(BaseItem * this)
//         004093f0     PUSH       EAX
//         004093f1     MOV        this,ESI
//         004093f3     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
//         004093f8     PUSH       EAX
//         004093f9     MOV        this,ESI
//         004093fb     CALL       BaseItem::gameID                                 int gameID(BaseItem * this)
//         00409400     PUSH       EAX
//         00409401     MOV        this,ESI
//         00409403     CALL       BaseItem::name                                   char * name(BaseItem * this)
//         00409408     PUSH       EAX
//         00409409     MOV        this,ESI
//         0040940b     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
//         00409410     PUSH       EAX
//         00409411     PUSH       s_____Type=%-4d_%-20s_gID=%-4d_Cat               = "    Type=%-4d %-20s gID=%-4d Cat=%d uID=%-
//                               LAB_00409416                                                 XREF[1]:     004093a4(j)
//         00409416     PUSH       EDI
//         00409417     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//                              aibldmod.cpp:306 (14)
//         0040941c     MOV        ESI,dword ptr [ESI + 0x6c]
//         0040941f     ADD        ESP,0x3c
//         00409422     CMP        ESI,EBX
//         00409424     JNZ        LAB_0040931e
//                               LAB_0040942a                                                 XREF[2]:     00409318(j), 00409320(j)
//                              aibldmod.cpp:308 (4)
//         0040942a     POP        EDI
//         0040942b     POP        ESI
//         0040942c     POP        EBX
//         0040942d     RET
//         0040942e     ??         90h
//         0040942f     NOP
    return;
}

int BuildAIModule::loadBuildList(char* param_1, RGE_Player* param_2) {
    /* TODO: Stub */
//                              int __thiscall loadBuildList(BuildAIModule * this, char * param_1, R
//              int               EAX:4          <RETURN>
//              BuildAIModule *   ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     0040944c(R)
//              RGE_Player *      Stack[0x8]:4   param_2                   XREF[1]:     00409697(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004096fc(W), 00409747(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0040980c(R)
//              char[256]         Stack[-0x110   temp                      XREF[0,8]:   004094d3(*), 004094e6(*), 00409537(*), 00409565(*),
//                                                                                     004095be(*), 004095fb(*), 0040962b(*), 0040978a(*)
//              char[64]          Stack[-0x150   name                      XREF[1,2]:   004096f4(W), 004095ae(*), 0040971b(*)
//              undefined4        Stack[-0x154   local_154                 XREF[2]:     004094fc(W), 00409786(R)
//              _iobuf *          Stack[-0x158   fileIn                    XREF[2]:     004095a5(*), 00409717(R)
//              int               Stack[-0x15c   buildFrom                 XREF[3]:     004095a9(*), 004096ce(R), 00409773(R)
//              int               Stack[-0x160   quantity                  XREF[3]:     004095b3(*), 00409658(R), 00409727(R)
//              int               Stack[-0x164   typeID                    XREF[4]:     00409582(W), 004095f7(*), 00409627(*), 00409769(R)
//              int               Stack[-0x168   buildCap                  XREF[4]:     00409572(W), 004096bc(R), 004096d9(W), 00409709(R)
//              float             Stack[-0x16c   xSize                     XREF[4]:     00409462(W), 004094a6(R), 004097a5(R), 004097cf(R)
//              undefined4        Stack[-0x170   local_170                 XREF[5]:     0040957a(W), 004096b6(W), 004096c0(R), 004096dd(W),
//                                                                                     00409705(R)
//              float             Stack[-0x174   ySize                     XREF[0,6]:   0040955b(*), 0040959a(R), 004095b8(*), 004095d0(R),
//                                                                                     0040955f(*), 0040958f(R)
//              char              Stack[-0x175   commentTemp1
//              char              Stack[-0x176   buildCategoryAsChar
//              char              Stack[-0x177   commentTemp2
//                               ?loadBuildList@BuildAIModule@@UAEHPADPAVRGE_Player@@@Z       XREF[2]:     loadBuildList:004d3d4a(c),
//                               BuildAIModule::loadBuildList                                              0056e77c(*)
//                              aibldmod.cpp:313 (28)
//         00409430     PUSH       -0x1
//         00409432     PUSH       FUN_0055c4ee
//         00409437     MOV        EAX,FS:[0x0]
//         0040943d     PUSH       EAX
//         0040943e     MOV        dword ptr FS:[0x0],ESP
//         00409445     SUB        ESP,0x168
//         0040944b     PUSH       EBX
//                              aibldmod.cpp:316 (34)
//         0040944c     MOV        EBX,dword ptr [ESP + param_1]
//         00409453     PUSH       EBP
//         00409454     MOV        EBP,this
//         00409456     PUSH       ESI
//         00409457     PUSH       EDI
//         00409458     LEA        EDI,[EBP + 0x1a4]
//         0040945e     PUSH       0x3f
//         00409460     PUSH       EBX
//         00409461     PUSH       EDI
//         00409462     MOV        dword ptr [ESP + xSize],EDI
//         00409466     CALL       strncpy                                          undefined strncpy()
//         0040946b     ADD        ESP,0xc
//                              aibldmod.cpp:319 (86)
//         0040946e     MOV        ESI,s_NONE                                       = 4Eh
//         00409473     MOV        EAX,EDI
//                               LAB_00409475                                                 XREF[1]:     00409493(j)
//         00409475     MOV        DL,byte ptr [EAX]
//         00409477     MOV        this,DL
//         00409479     CMP        DL,byte ptr [ESI]=>s_NONE                        = 4Eh
//         0040947b     JNZ        LAB_00409499
//         0040947d     TEST       this,this
//         0040947f     JZ         LAB_00409495
//         00409481     MOV        DL,byte ptr [EAX + 0x1]
//         00409484     MOV        this,DL
//         00409486     CMP        DL,byte ptr [ESI + 0x1]=>DAT_0057f351            = 4Fh
//                                                                                  = 45h
//         00409489     JNZ        LAB_00409499
//         0040948b     ADD        EAX,0x2
//         0040948e     ADD        ESI,0x2
//         00409491     TEST       this,this
//         00409493     JNZ        LAB_00409475
//                               LAB_00409495                                                 XREF[1]:     0040947f(j)
//         00409495     XOR        EAX,EAX
//         00409497     JMP        LAB_0040949e
//                               LAB_00409499                                                 XREF[2]:     0040947b(j), 00409489(j)
//         00409499     SBB        EAX,EAX
//         0040949b     SBB        EAX,-0x1
//                               LAB_0040949e                                                 XREF[1]:     00409497(j)
//         0040949e     TEST       EAX,EAX
//         004094a0     JZ         LAB_004097cf
//         004094a6     MOV        ESI,dword ptr [ESP + xSize]
//         004094aa     TEST       ESI,ESI
//         004094ac     JZ         LAB_004097cf
//         004094b2     MOV        EDI,ESI
//         004094b4     OR         this,0xffffffff
//         004094b7     XOR        EAX,EAX
//         004094b9     SCASB.RE   ES:EDI
//         004094bb     NOT        this
//         004094bd     DEC        this
//         004094be     JZ         LAB_004097cf
//                              aibldmod.cpp:326 (15)
//         004094c4     PUSH       EBX
//         004094c5     PUSH       s_Trying_to_load_build_list_in_fil               = "Trying to load build list in file '%s'."
//         004094ca     PUSH       EBP
//         004094cb     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//         004094d0     ADD        ESP,0xc
//                              aibldmod.cpp:328 (19)
//         004094d3     LEA        EAX=>temp[4],[ESP + 0x78]
//         004094d7     PUSH       ESI
//         004094d8     PUSH       s_%s                                             = "%s"
//         004094dd     PUSH       EAX
//         004094de     CALL       sprintf                                          undefined sprintf()
//         004094e3     ADD        ESP,0xc
//                              aibldmod.cpp:329 (20)
//         004094e6     LEA        this=>temp[4],[ESP + 0x78]
//         004094ea     PUSH       s_r                                              = "r"
//         004094ef     PUSH       this
//         004094f0     CALL       fopen                                            undefined fopen()
//         004094f5     MOV        EDI,EAX
//         004094f7     ADD        ESP,0x8
//                              aibldmod.cpp:330 (8)
//         004094fa     TEST       EDI,EDI
//         004094fc     MOV        dword ptr [ESP + local_154],EDI
//         00409500     JNZ        LAB_00409517
//                              aibldmod.cpp:331 (14)
//         00409502     PUSH       s___I_cannot_do_it_cap'n!                        = "  I cannot do it cap'n!"
//         00409507     PUSH       EBP
//         00409508     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//         0040950d     ADD        ESP,0x8
//                              aibldmod.cpp:332 (7)
//         00409510     XOR        EAX,EAX
//         00409512     JMP        LAB_0040980c
//                               LAB_00409517                                                 XREF[1]:     00409500(j)
//                              aibldmod.cpp:336 (11)
//         00409517     PUSH       s___File_open_successful,_nuking_a               = "  File open successful, nuking any old ite
//         0040951c     PUSH       EBP
//         0040951d     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//                              aibldmod.cpp:337 (13)
//         00409522     MOV        EAX,dword ptr [EBP + 0x1a0]
//         00409528     ADD        ESP,0x8
//         0040952b     TEST       EAX,EAX
//         0040952d     JLE        LAB_00409536
//                              aibldmod.cpp:338 (7)
//         0040952f     MOV        this,EBP
//         00409531     CALL       BuildAIModule::removeOldList                     void removeOldList(BuildAIModule * this)
//                               LAB_00409536                                                 XREF[1]:     0040952d(j)
//                              aibldmod.cpp:341 (37)
//         00409536     PUSH       EDI
//         00409537     LEA        EDX=>temp[4],[ESP + 0x7c]
//         0040953b     PUSH       0x100
//         00409540     PUSH       EDX
//         00409541     MOV        dword ptr [EBP + 0x1a0],0x0
//         0040954b     CALL       fgets                                            undefined fgets()
//         00409550     ADD        ESP,0xc
//         00409553     TEST       EAX,EAX
//         00409555     JZ         LAB_004097a9
//                               LAB_0040955b                                                 XREF[1]:     0040979f(j)
//                              aibldmod.cpp:360 (52)
//         0040955b     LEA        EAX=>ySize+0x1,[ESP + 0x11]
//         0040955f     LEA        this=>ySize+0x3,[ESP + 0x13]
//         00409563     PUSH       EAX
//         00409564     PUSH       this
//         00409565     LEA        EDX=>temp[4],[ESP + 0x80]
//         0040956c     PUSH       s__%c%c                                          = " %c%c"
//         00409571     PUSH       EDX
//         00409572     MOV        dword ptr [ESP + buildCap],0x3fc00000
//         0040957a     MOV        dword ptr [ESP + local_170],0x3fc00000
//         00409582     MOV        dword ptr [ESP + typeID],0xffffffff
//         0040958a     CALL       sscanf                                           undefined sscanf()
//                              aibldmod.cpp:361 (22)
//         0040958f     MOV        AL,byte ptr [ESP + ySize+0x3]
//         00409593     ADD        ESP,0x10
//         00409596     CMP        AL,0x2f
//         00409598     JNZ        LAB_004095a5
//         0040959a     CMP        byte ptr [ESP + ySize+0x1],0x2f
//         0040959f     JZ         switchD_004095ec::caseD_a
//                               LAB_004095a5                                                 XREF[1]:     00409598(j)
//                              aibldmod.cpp:368 (43)
//         004095a5     LEA        EAX=>fileIn,[ESP + 0x2c]
//         004095a9     LEA        this=>buildFrom,[ESP + 0x28]
//         004095ad     PUSH       EAX
//         004095ae     LEA        EDX=>name[4],[ESP + 0x3c]
//         004095b2     PUSH       this
//         004095b3     LEA        EAX=>quantity,[ESP + 0x2c]
//         004095b7     PUSH       EDX
//         004095b8     LEA        this=>ySize+0x2,[ESP + 0x1e]
//         004095bc     PUSH       EAX
//         004095bd     PUSH       this
//         004095be     LEA        EDX=>temp[4],[ESP + 0x8c]
//         004095c5     PUSH       s_%c%d_%s_%d_%d_                                 = "%c%d %s %d %d "
//         004095ca     PUSH       EDX
//         004095cb     CALL       sscanf                                           undefined sscanf()
//                              aibldmod.cpp:369 (35)
//         004095d0     MOVSX      EAX,byte ptr [ESP + ySize+0x2]
//         004095d5     ADD        EAX,-0xa
//         004095d8     ADD        ESP,0x1c
//         004095db     CMP        EAX,0x4b
//         004095de     JA         switchD_004095ec::caseD_a
//         004095e4     XOR        this,this
//         004095e6     MOV        this,byte ptr [EAX + 0x409854]=>PTR_caseD_54_0
//                               switchD_004095ec::switchD
//         004095ec     JMP        dword ptr [this->_padding_*0x4 + switchD_00409   = 00409786
//                               switchD_004095ec::caseD_42                                   XREF[2]:     004095ec(j), 00409830(*)
//                              aibldmod.cpp:372 (2)
//         004095f3     XOR        EDI,EDI
//                              aibldmod.cpp:373 (2)
//         004095f5     JMP        LAB_00409658
//                               switchD_004095ec::caseD_41                                   XREF[2]:     004095ec(j), 0040982c(*)
//                              aibldmod.cpp:377 (25)
//         004095f7     LEA        EDX=>typeID,[ESP + 0x20]
//         004095fb     LEA        EAX=>temp[4],[ESP + 0x78]
//         004095ff     PUSH       EDX
//         00409600     PUSH       s_%*c%*d_%*s_%*d_%*d_%d_                         = "%*c%*d %*s %*d %*d %d "
//         00409605     PUSH       EAX
//         00409606     XOR        EDI,EDI
//         00409608     CALL       sscanf                                           undefined sscanf()
//         0040960d     ADD        ESP,0xc
//                              aibldmod.cpp:378 (2)
//         00409610     JMP        LAB_00409658
//                               switchD_004095ec::caseD_52                                   XREF[2]:     004095ec(j), 00409844(*)
//                              aibldmod.cpp:381 (5)
//         00409612     MOV        EDI,0x1
//                              aibldmod.cpp:382 (2)
//         00409617     JMP        LAB_00409658
//                               switchD_004095ec::caseD_43                                   XREF[2]:     004095ec(j), 00409834(*)
//                              aibldmod.cpp:385 (5)
//         00409619     MOV        EDI,0x4
//                              aibldmod.cpp:386 (2)
//         0040961e     JMP        LAB_00409658
//                               switchD_004095ec::caseD_55                                   XREF[2]:     004095ec(j), 0040984c(*)
//                              aibldmod.cpp:389 (5)
//         00409620     MOV        EDI,0x2
//                              aibldmod.cpp:390 (2)
//         00409625     JMP        LAB_00409658
//                               switchD_004095ec::caseD_54                                   XREF[2]:     004095ec(j), 00409848(*)
//                              aibldmod.cpp:394 (28)
//         00409627     LEA        this=>typeID,[ESP + 0x20]
//         0040962b     LEA        EDX=>temp[4],[ESP + 0x78]
//         0040962f     PUSH       this
//         00409630     PUSH       s_%*c%*d_%*s_%*d_%*d_%d_                         = "%*c%*d %*s %*d %*d %d "
//         00409635     PUSH       EDX
//         00409636     MOV        EDI,0x2
//         0040963b     CALL       sscanf                                           undefined sscanf()
//         00409640     ADD        ESP,0xc
//                              aibldmod.cpp:395 (2)
//         00409643     JMP        LAB_00409658
//                               switchD_004095ec::caseD_4c                                   XREF[2]:     004095ec(j), 00409840(*)
//                              aibldmod.cpp:398 (5)
//         00409645     MOV        EDI,0x3
//                              aibldmod.cpp:399 (2)
//         0040964a     JMP        LAB_00409658
//                               switchD_004095ec::caseD_45                                   XREF[2]:     004095ec(j), 00409838(*)
//                              aibldmod.cpp:402 (5)
//         0040964c     MOV        EDI,0x5
//                              aibldmod.cpp:403 (2)
//         00409651     JMP        LAB_00409658
//                               switchD_004095ec::caseD_47                                   XREF[2]:     004095ec(j), 0040983c(*)
//                              aibldmod.cpp:406 (5)
//         00409653     MOV        EDI,0x6
//                               LAB_00409658                                                 XREF[8]:     004095f5(j), 00409610(j),
//                                                                                                         00409617(j), 0040961e(j),
//                                                                                                         00409625(j), 00409643(j),
//                                                                                                         0040964a(j), 00409651(j)
//                              aibldmod.cpp:420 (50)
//         00409658     MOV        EDX,dword ptr [ESP + quantity]
//         0040965c     TEST       EDI,EDI
//         0040965e     JNZ        LAB_0040968a
//         00409660     MOV        this,dword ptr [EBP + 0x5b0]
//         00409666     XOR        EAX,EAX
//         00409668     TEST       this,this
//         0040966a     JLE        LAB_0040968a
//         0040966c     MOV        EBX,dword ptr [EBP + 0x5b8]
//                               LAB_00409672                                                 XREF[1]:     00409688(j)
//         00409672     CMP        EAX,EBX
//         00409674     JGE        LAB_0040968a
//         00409676     MOV        ESI,dword ptr [EBP + 0x5ac]
//         0040967c     CMP        dword ptr [ESI + EAX*0x4],EDX
//         0040967f     JZ         switchD_004095ec::caseD_a
//         00409685     INC        EAX
//         00409686     CMP        EAX,this
//         00409688     JL         LAB_00409672
//                               LAB_0040968a                                                 XREF[3]:     0040965e(j), 0040966a(j),
//                                                                                                         00409674(j)
//                              aibldmod.cpp:429 (38)
//         0040968a     TEST       EDI,EDI
//         0040968c     JZ         LAB_00409693
//         0040968e     CMP        EDI,0x2
//         00409691     JNZ        LAB_004096bc
//                               LAB_00409693                                                 XREF[1]:     0040968c(j)
//         00409693     TEST       EDX,EDX
//         00409695     JL         LAB_004096bc
//         00409697     MOV        EAX,dword ptr [ESP + param_2]
//         0040969e     MOVSX      this,word ptr [EAX + 0x22]
//         004096a2     CMP        EDX,this
//         004096a4     JGE        LAB_004096bc
//         004096a6     MOV        EAX,dword ptr [EAX + 0x24]
//         004096a9     MOV        EAX,dword ptr [EAX + EDX*0x4]
//         004096ac     TEST       EAX,EAX
//         004096ae     JZ         LAB_004096bc
//                              aibldmod.cpp:431 (16)
//         004096b0     MOV        this,dword ptr [EAX + 0x34]
//         004096b3     FLD        float ptr [EAX + 0x30]
//         004096b6     MOV        dword ptr [ESP + local_170],this
//         004096ba     JMP        LAB_004096c0
//                               LAB_004096bc                                                 XREF[4]:     00409691(j), 00409695(j),
//                                                                                                         004096a4(j), 004096ae(j)
//         004096bc     FLD        float ptr [ESP + buildCap]
//                               LAB_004096c0                                                 XREF[1]:     004096ba(j)
//                              aibldmod.cpp:436 (10)
//         004096c0     FLD        float ptr [ESP + local_170]
//         004096c4     FXCH
//         004096c6     FADD       ST0,ST0
//         004096c8     FXCH
//                              aibldmod.cpp:444 (29)
//         004096ca     FADD       ST0,ST0
//         004096cc     FXCH
//         004096ce     MOV        EAX,dword ptr [ESP + buildFrom]
//         004096d2     MOV        EBX,0x0
//         004096d7     TEST       EAX,EAX
//         004096d9     FSTP       float ptr [ESP + buildCap]
//         004096dd     FSTP       float ptr [ESP + local_170]
//         004096e1     JLE        switchD_004095ec::caseD_a
//                               LAB_004096e7                                                 XREF[1]:     00409780(j)
//                              aibldmod.cpp:448 (83)
//         004096e7     PUSH       0xb0
//         004096ec     CALL       operator_new                                     void * operator_new(uint param_1)
//         004096f1     ADD        ESP,0x4
//         004096f4     MOV        dword ptr [ESP + name[0]],EAX
//         004096f8     XOR        ESI,ESI
//         004096fa     CMP        EAX,ESI
//         004096fc     MOV        dword ptr [ESP + local_4],ESI
//         00409703     JZ         LAB_0040973a
//         00409705     MOV        EDX,dword ptr [ESP + local_170]
//         00409709     MOV        this,dword ptr [ESP + buildCap]
//         0040970d     PUSH       ESI
//         0040970e     PUSH       -0x1
//         00409710     PUSH       -0x1
//         00409712     PUSH       -0x1
//         00409714     PUSH       ESI
//         00409715     PUSH       EDX
//         00409716     PUSH       this
//         00409717     MOV        this,dword ptr [ESP + fileIn]
//         0040971b     LEA        EDX=>name[4],[ESP + 0x54]
//         0040971f     PUSH       EDX
//         00409720     MOV        EDX,dword ptr [EBP + 0x1a0]
//         00409726     PUSH       this
//         00409727     MOV        this,dword ptr [ESP + quantity]
//         0040972b     PUSH       ESI
//         0040972c     PUSH       0x1
//         0040972e     PUSH       EDX
//         0040972f     PUSH       this
//         00409730     PUSH       EDI
//         00409731     MOV        this,EAX
//         00409733     CALL       BuildItem::BuildItem                             undefined BuildItem(BuildItem * this, int par
//         00409738     MOV        ESI,EAX
//                               LAB_0040973a                                                 XREF[1]:     00409703(j)
//                              aibldmod.cpp:449 (6)
//         0040973a     MOV        this,dword ptr [EBP + 0x1a0]
//                              aibldmod.cpp:452 (27)
//         00409740     LEA        EAX,[EBP + 0xf0]
//         00409746     INC        this
//         00409747     MOV        dword ptr [ESP + local_4],0xffffffff
//         00409752     MOV        dword ptr [EBP + 0x1a0],this
//         00409758     MOV        dword ptr [ESI + 0x6c],EAX
//                              aibldmod.cpp:453 (6)
//         0040975b     MOV        EAX,dword ptr [EBP + 0x160]
//                              aibldmod.cpp:455 (25)
//         00409761     MOV        this,ESI
//         00409763     MOV        dword ptr [ESI + 0x70],EAX
//         00409766     MOV        dword ptr [EAX + 0x6c],ESI
//         00409769     MOV        EDX,dword ptr [ESP + typeID]
//         0040976d     PUSH       EDX
//         0040976e     CALL       BuildItem::setBuildCap                           void setBuildCap(BuildItem * this, int param_1)
//         00409773     MOV        EAX,dword ptr [ESP + buildFrom]
//         00409777     INC        EBX
//         00409778     CMP        EBX,EAX
//                              aibldmod.cpp:456 (12)
//         0040977a     MOV        dword ptr [EBP + 0x160],ESI
//         00409780     JL         LAB_004096e7
//                               switchD_004095ec::caseD_b                                    XREF[7]:     0040959f(j), 004095de(j),
//                               switchD_004095ec::caseD_c                                                 004095ec(j), 0040967f(j),
//                               switchD_004095ec::caseD_d                                                 004096e1(j), 00409828(*),
//                               switchD_004095ec::caseD_e                                                 00409850(*)
//                               switchD_004095ec::caseD_f
//                               switchD_004095ec::caseD_10
//                               switchD_004095ec::caseD_11
//                               switchD_004095ec::caseD_12
//                               switchD_004095ec::caseD_13
//                               switchD_004095ec::caseD_14
//                               switchD_004095ec::caseD_15
//                               switchD_004095ec::caseD_16
//                               switchD_004095ec::caseD_17
//                               switchD_004095ec::caseD_18
//                               switchD_004095ec::caseD_19
//                               switchD_004095ec::caseD_1a
//                               switchD_004095ec::caseD_1b
//                               switchD_004095ec::caseD_1c
//                               switchD_004095ec::caseD_1d
//                               switchD_004095ec::caseD_1e
//                               switchD_004095ec::caseD_1f
//                               switchD_004095ec::caseD_20
//                               switchD_004095ec::caseD_21
//                               switchD_004095ec::caseD_22
//                               switchD_004095ec::caseD_23
//                               switchD_004095ec::caseD_24
//                               switchD_004095ec::caseD_25
//                               switchD_004095ec::caseD_26
//                               switchD_004095ec::caseD_27
//                               switchD_004095ec::caseD_28
//                               switchD_004095ec::caseD_29
//                               switchD_004095ec::caseD_2a
//                               switchD_004095ec::caseD_2b
//                               switchD_004095ec::caseD_2c
//                               switchD_004095ec::caseD_2d
//                               switchD_004095ec::caseD_2e
//                               switchD_004095ec::caseD_2f
//                               switchD_004095ec::caseD_30
//                               switchD_004095ec::caseD_31
//                               switchD_004095ec::caseD_32
//                               switchD_004095ec::caseD_33
//                               switchD_004095ec::caseD_34
//                               switchD_004095ec::caseD_35
//                               switchD_004095ec::caseD_36
//                               switchD_004095ec::caseD_37
//                               switchD_004095ec::caseD_38
//                               switchD_004095ec::caseD_39
//                               switchD_004095ec::caseD_3a
//                               switchD_004095ec::caseD_3b
//                               switchD_004095ec::caseD_3c
//                               switchD_004095ec::caseD_3d
//                               switchD_004095ec::caseD_3e
//                               switchD_004095ec::caseD_3f
//                               switchD_004095ec::caseD_40
//                               switchD_004095ec::caseD_44
//                               switchD_004095ec::caseD_46
//                               switchD_004095ec::caseD_48
//                               switchD_004095ec::caseD_49
//                               switchD_004095ec::caseD_4a
//                               switchD_004095ec::caseD_4b
//                               switchD_004095ec::caseD_4d
//                               switchD_004095ec::caseD_4e
//                               switchD_004095ec::caseD_4f
//                               switchD_004095ec::caseD_50
//                               switchD_004095ec::caseD_51
//                               switchD_004095ec::caseD_53
//                               switchD_004095ec::caseD_a
//                              aibldmod.cpp:341 (35)
//         00409786     MOV        EDI,dword ptr [ESP + local_154]
//         0040978a     LEA        EAX=>temp[4],[ESP + 0x78]
//         0040978e     PUSH       EDI
//         0040978f     PUSH       0x100
//         00409794     PUSH       EAX
//         00409795     CALL       fgets                                            undefined fgets()
//         0040979a     ADD        ESP,0xc
//         0040979d     TEST       EAX,EAX
//         0040979f     JNZ        LAB_0040955b
//         004097a5     MOV        ESI,dword ptr [ESP + xSize]
//                               LAB_004097a9                                                 XREF[1]:     00409555(j)
//                              aibldmod.cpp:475 (9)
//         004097a9     PUSH       EDI
//         004097aa     CALL       fclose                                           undefined fclose()
//         004097af     ADD        ESP,0x4
//                              aibldmod.cpp:477 (18)
//         004097b2     PUSH       s_.tmp                                           = ".tmp"
//         004097b7     PUSH       ESI
//         004097b8     CALL       strstr                                           undefined strstr()
//         004097bd     ADD        ESP,0x8
//         004097c0     TEST       EAX,EAX
//         004097c2     JZ         LAB_00409807
//                              aibldmod.cpp:478 (9)
//         004097c4     PUSH       ESI
//         004097c5     CALL       __unlink                                         undefined __unlink()
//         004097ca     ADD        ESP,0x4
//                              aibldmod.cpp:479 (2)
//         004097cd     JMP        LAB_00409807
//                               LAB_004097cf                                                 XREF[3]:     004094a0(j), 004094ac(j),
//                                                                                                         004094be(j)
//                              aibldmod.cpp:320 (8)
//         004097cf     MOV        EAX,dword ptr [ESP + xSize]
//         004097d3     TEST       EAX,EAX
//         004097d5     JNZ        LAB_004097f9
//                              aibldmod.cpp:321 (34)
//         004097d7     MOV        EDI,s_NULL                                       = 4Eh
//         004097dc     OR         this,0xffffffff
//         004097df     XOR        EAX,EAX
//         004097e1     SCASB.RE   ES:EDI=>s_NULL                                   = 4Eh
//                                                                                  = 55h
//         004097e3     NOT        this
//         004097e5     SUB        EDI,this
//         004097e7     MOV        EDX,this
//         004097e9     MOV        ESI,EDI
//         004097eb     XOR        EDI,EDI
//         004097ed     SHR        this,0x2
//         004097f0     MOVSD.REP  ES:EDI,ESI
//         004097f2     MOV        this,EDX
//         004097f4     AND        this,0x3
//         004097f7     MOVSB.REP  ES:EDI,ESI
//                               LAB_004097f9                                                 XREF[1]:     004097d5(j)
//                              aibldmod.cpp:322 (14)
//         004097f9     PUSH       s_There_is_no_build_list_to_load.                = "There is no build list to load."
//         004097fe     PUSH       EBP
//         004097ff     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
//         00409804     ADD        ESP,0x8
//                               LAB_00409807                                                 XREF[2]:     004097c2(j), 004097cd(j)
//                              aibldmod.cpp:323 (5)
//         00409807     MOV        EAX,0x1
//                               LAB_0040980c                                                 XREF[1]:     00409512(j)
//                              aibldmod.cpp:480 (148)
//         0040980c     MOV        this,dword ptr [ESP + local_c]
//         00409813     POP        EDI
//         00409814     POP        ESI
//         00409815     POP        EBP
//         00409816     MOV        dword ptr FS:[0x0],this
//         0040981d     POP        EBX
//         0040981e     ADD        ESP,0x174
//         00409824     RET        0x8
//         00409827     ??         90h
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004095ec::switchdataD_00409828                       XREF[1]:     loadBuildList:004095ec(*)
//         00409828     addr       switchD_004095ec::caseD_a
//         0040982c     addr       switchD_004095ec::caseD_41
//         00409830     addr       switchD_004095ec::caseD_42
//         00409834     addr       switchD_004095ec::caseD_43
//         00409838     addr       switchD_004095ec::caseD_45
//         0040983c     addr       switchD_004095ec::caseD_47
//         00409840     addr       switchD_004095ec::caseD_4c
//         00409844     addr       switchD_004095ec::caseD_52
//                               PTR_caseD_54_00409848+2                                      XREF[0,1]:   loadBuildList:004095e6(*)
//         00409848     addr       switchD_004095ec::caseD_54
//         0040984c     addr       switchD_004095ec::caseD_55
//         00409850     addr       switchD_004095ec::caseD_a
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004095ec::switchdataD_00409854
//         00409854     db         0h
//         00409855     db         Ah
//         00409856     db         Ah
//         00409857     db         Ah
//         00409858     db         Ah
//         00409859     db         Ah
//         0040985a     db         Ah
//         0040985b     db         Ah
//         0040985c     db         Ah
//         0040985d     db         Ah
//         0040985e     db         Ah
//         0040985f     db         Ah
//         00409860     db         Ah
//         00409861     db         Ah
//         00409862     db         Ah
//         00409863     db         Ah
//         00409864     db         Ah
//         00409865     db         Ah
//         00409866     db         Ah
//         00409867     db         Ah
//         00409868     db         Ah
//         00409869     db         Ah
//         0040986a     db         Ah
//         0040986b     db         Ah
//         0040986c     db         Ah
//         0040986d     db         Ah
//         0040986e     db         Ah
//         0040986f     db         Ah
//         00409870     db         Ah
//         00409871     db         Ah
//         00409872     db         Ah
//         00409873     db         Ah
//         00409874     db         Ah
//         00409875     db         Ah
//         00409876     db         Ah
//         00409877     db         Ah
//         00409878     db         Ah
//         00409879     db         Ah
//         0040987a     db         Ah
//         0040987b     db         Ah
//         0040987c     db         Ah
//         0040987d     db         Ah
//         0040987e     db         Ah
//         0040987f     db         Ah
//         00409880     db         Ah
//         00409881     db         Ah
//         00409882     db         Ah
//         00409883     db         Ah
//         00409884     db         Ah
//         00409885     db         Ah
//         00409886     db         Ah
//         00409887     db         Ah
//         00409888     db         Ah
//         00409889     db         Ah
//         0040988a     db         Ah
//         0040988b     db         1h
//         0040988c     db         2h
//         0040988d     db         3h
//         0040988e     db         Ah
//         0040988f     db         4h
//         00409890     db         Ah
//         00409891     db         5h
//         00409892     db         Ah
//         00409893     db         Ah
//         00409894     db         Ah
//         00409895     db         Ah
//         00409896     db         6h
//         00409897     db         Ah
//         00409898     db         Ah
//         00409899     db         Ah
//         0040989a     db         Ah
//         0040989b     db         Ah
//         0040989c     db         7h
//         0040989d     db         Ah
//         0040989e     db         8h
//         0040989f     db         9h
    return 0;
}

int BuildAIModule::buildListLength() {
    /* TODO: Stub */
//                              int __thiscall buildListLength(BuildAIModule * this)
//              int               EAX:4          <RETURN>
//              BuildAIModule *   ECX:4 (auto)   this
//                               ?buildListLength@BuildAIModule@@QBEHXZ                       XREF[6]:     doSomething:004f03d7(c),
//                               BuildAIModule::buildListLength                                            doSomething:004f0449(c),
//                                                                                                         doSomething:004f049e(c),
//                                                                                                         taskActiveSoldiers:004f39be(c),
//                                                                                                         aiStatus:005147c0(c),
//                                                                                                         logStatus:005191b5(c)
//                              aibldmod.cpp:485 (6)
//         004098a0     MOV        EAX,dword ptr [ECX + this->buildListLengthValue]
//                              aibldmod.cpp:487 (1)
//         004098a6     RET
//         004098a7     ??         90h
//         004098a8     NOP
//         004098a9     NOP
//         004098aa     NOP
//         004098ab     NOP
//         004098ac     NOP
//         004098ad     NOP
//         004098ae     NOP
//         004098af     NOP
    return 0;
}

char* BuildAIModule::buildListName() {
    /* TODO: Stub */
//                              char * __thiscall buildListName(BuildAIModule * this)
//              char *            EAX:4          <RETURN>
//              BuildAIModule *   ECX:4 (auto)   this
//                               ?buildListName@BuildAIModule@@QAEPADXZ                       XREF[2]:     aiStatus:0051482c(c),
//                               BuildAIModule::buildListName                                              logStatus:00518f94(c)
//                              aibldmod.cpp:492 (6)
//         004098b0     LEA        EAX,[ECX + this->buildListNameValue[0]]
//                              aibldmod.cpp:494 (1)
//         004098b6     RET
//         004098b7     ??         90h
//         004098b8     NOP
//         004098b9     NOP
//         004098ba     NOP
//         004098bb     NOP
//         004098bc     NOP
//         004098bd     NOP
//         004098be     NOP
//         004098bf     NOP
    return 0;
}

int BuildAIModule::haveBuildList() {
    /* TODO: Stub */
//                              int __thiscall haveBuildList(BuildAIModule * this)
//              int               EAX:4          <RETURN>
//              BuildAIModule *   ECX:4 (auto)   this
//                               ?haveBuildList@BuildAIModule@@QBEHXZ                         XREF[2]:     evaluateBuildListInsertions:004f5f
//                               BuildAIModule::haveBuildList                                              evaluateBuildListInsertions:004f60
//                              aibldmod.cpp:499 (3)
//         004098c0     PUSH       EBX
//         004098c1     PUSH       ESI
//         004098c2     PUSH       EDI
//                              aibldmod.cpp:502 (122)
//         004098c3     LEA        EDI,[ECX + this->buildListNameValue[0]]
//         004098c9     TEST       EDI,EDI
//         004098cb     JZ         LAB_00409946
//         004098cd     MOV        ESI,s_NONE                                       = 4Eh
//         004098d2     MOV        EAX,EDI
//                               LAB_004098d4                                                 XREF[1]:     004098f6(j)
//         004098d4     MOV        DL,byte ptr [EAX]
//         004098d6     MOV        BL,byte ptr [ESI]=>s_NONE                        = 4Eh
//         004098d8     MOV        this,DL
//         004098da     CMP        DL,BL
//         004098dc     JNZ        LAB_004098fc
//         004098de     TEST       this,this
//         004098e0     JZ         LAB_004098f8
//         004098e2     MOV        DL,byte ptr [EAX + 0x1]
//         004098e5     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0057f351            = 4Fh
//                                                                                  = 45h
//         004098e8     MOV        this,DL
//         004098ea     CMP        DL,BL
//         004098ec     JNZ        LAB_004098fc
//         004098ee     ADD        EAX,0x2
//         004098f1     ADD        ESI,0x2
//         004098f4     TEST       this,this
//         004098f6     JNZ        LAB_004098d4
//                               LAB_004098f8                                                 XREF[1]:     004098e0(j)
//         004098f8     XOR        EAX,EAX
//         004098fa     JMP        LAB_00409901
//                               LAB_004098fc                                                 XREF[2]:     004098dc(j), 004098ec(j)
//         004098fc     SBB        EAX,EAX
//         004098fe     SBB        EAX,-0x1
//                               LAB_00409901                                                 XREF[1]:     004098fa(j)
//         00409901     TEST       EAX,EAX
//         00409903     JZ         LAB_00409946
//         00409905     MOV        ESI,s_NULL                                       = 4Eh
//         0040990a     MOV        EAX,EDI
//                               LAB_0040990c                                                 XREF[1]:     0040992e(j)
//         0040990c     MOV        DL,byte ptr [EAX]
//         0040990e     MOV        BL,byte ptr [ESI]=>s_NULL                        = 4Eh
//                                                                                  = 4Ch
//         00409910     MOV        this,DL
//         00409912     CMP        DL,BL
//         00409914     JNZ        LAB_00409934
//         00409916     TEST       this,this
//         00409918     JZ         LAB_00409930
//         0040991a     MOV        DL,byte ptr [EAX + 0x1]
//         0040991d     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0057f299            = 55h
//                                                                                  = 4Ch
//         00409920     MOV        this,DL
//         00409922     CMP        DL,BL
//         00409924     JNZ        LAB_00409934
//         00409926     ADD        EAX,0x2
//         00409929     ADD        ESI,0x2
//         0040992c     TEST       this,this
//         0040992e     JNZ        LAB_0040990c
//                               LAB_00409930                                                 XREF[1]:     00409918(j)
//         00409930     XOR        EAX,EAX
//         00409932     JMP        LAB_00409939
//                               LAB_00409934                                                 XREF[2]:     00409914(j), 00409924(j)
//         00409934     SBB        EAX,EAX
//         00409936     SBB        EAX,-0x1
//                               LAB_00409939                                                 XREF[1]:     00409932(j)
//         00409939     TEST       EAX,EAX
//         0040993b     JZ         LAB_00409946
//                              aibldmod.cpp:504 (5)
//         0040993d     MOV        EAX,0x1
//                              aibldmod.cpp:505 (10)
//         00409942     POP        EDI
//         00409943     POP        ESI
//         00409944     POP        EBX
//         00409945     RET
//                               LAB_00409946                                                 XREF[3]:     004098cb(j), 00409903(j),
//                                                                                                         0040993b(j)
//         00409946     POP        EDI
//         00409947     POP        ESI
//         00409948     XOR        EAX,EAX
//         0040994a     POP        EBX
//         0040994b     RET
//         0040994c     ??         90h
//         0040994d     NOP
//         0040994e     NOP
//         0040994f     NOP
    return 0;
}

int BuildAIModule::insertItem(RGE_Player* param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7) {
    /* TODO: Stub */
//                              int __thiscall insertItem(BuildAIModule * this, RGE_Player * param_1
//              int               EAX:4          <RETURN>
//              BuildAIModule *   ECX:4 (auto)   this
//              RGE_Player *      Stack[0x4]:4   param_1                   XREF[4]:     004099b0(R), 004099e3(W), 00409a15(W), 00409a5e(R)
//              int               Stack[0x8]:4   param_2                   XREF[2]:     004099ac(R), 00409a7c(R)
//              int               Stack[0xc]:4   param_3                   XREF[2]:     00409a28(R), 00409b44(R)
//              int               Stack[0x10]:4  param_4                   XREF[2]:     004099a5(R), 00409a84(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     00409a70(R)
//              int               Stack[0x18]:4  param_6                   XREF[1]:     00409b04(R)
//              int               Stack[0x1c]:4  param_7                   XREF[4]:     00409968(R), 004099ec(W), 00409a1d(W), 00409a57(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00409a51(W), 00409a9c(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00409b55(R)
//              char[64]          Stack[-0x50]   name                      XREF[1,4]:   00409a49(W), 004099ca(*), 004099f5(*), 00409a03(*),
//                                                                                     00409a77(*)
//              undefined4        Stack[-0x54]:4 local_54                  XREF[2]:     00409978(W), 00409b2f(R)
//                               ?insertItem@BuildAIModule@@QAEHPAVRGE_Player@@HHHHHH@Z       XREF[5]:     insert:004d5916(c),
//                               BuildAIModule::insertItem                                                 insert:004d5943(c),
//                                                                                                         insertResearch:004d5b42(c),
//                                                                                                         insertResearch:004d5b67(c),
//                                                                                                         insertGathererPercentage:004d5ba2(
//                              aibldmod.cpp:513 (24)
//         00409950     PUSH       -0x1
//         00409952     PUSH       FUN_0055c50b
//         00409957     MOV        EAX,FS:[0x0]
//         0040995d     PUSH       EAX
//         0040995e     MOV        dword ptr FS:[0x0],ESP
//         00409965     SUB        ESP,0x48
//                              aibldmod.cpp:515 (24)
//         00409968     MOV        EDX,dword ptr [ESP + param_7]
//         0040996c     PUSH       EBX
//         0040996d     MOV        EBX,this
//         0040996f     PUSH       EBP
//         00409970     PUSH       ESI
//         00409971     PUSH       EDI
//         00409972     MOV        EAX,dword ptr [EBX + 0x1a0]
//         00409978     MOV        dword ptr [ESP + local_54],EBX
//         0040997c     CMP        EDX,EAX
//         0040997e     JLE        LAB_00409987
//                              aibldmod.cpp:516 (7)
//         00409980     XOR        EAX,EAX
//         00409982     JMP        LAB_00409b55
//                               LAB_00409987                                                 XREF[1]:     0040997e(j)
//                              aibldmod.cpp:518 (6)
//         00409987     MOV        EDI,dword ptr [EBX + 0x15c]
//                              aibldmod.cpp:520 (16)
//         0040998d     LEA        this,[EBX + 0xf0]
//         00409993     XOR        EAX,EAX
//         00409995     CMP        EDI,this
//         00409997     JZ         LAB_004099a5
//                               LAB_00409999                                                 XREF[1]:     004099a3(j)
//         00409999     CMP        EAX,EDX
//         0040999b     JGE        LAB_004099a5
//                              aibldmod.cpp:521 (3)
//         0040999d     MOV        EDI,dword ptr [EDI + 0x6c]
//                              aibldmod.cpp:522 (5)
//         004099a0     INC        EAX
//         004099a1     CMP        EDI,this
//         004099a3     JNZ        LAB_00409999
//                               LAB_004099a5                                                 XREF[2]:     00409997(j), 0040999b(j)
//                              aibldmod.cpp:529 (7)
//         004099a5     CMP        dword ptr [ESP + param_4],0x6
//         004099aa     JZ         LAB_00409a01
//                              aibldmod.cpp:530 (8)
//         004099ac     MOV        EAX,dword ptr [ESP + param_2]
//         004099b0     MOV        ESI,dword ptr [ESP + param_1]
//                              aibldmod.cpp:531 (33)
//         004099b4     PUSH       0x3f
//         004099b6     MOV        this,dword ptr [ESI + 0x24]
//         004099b9     LEA        EBP,[EAX*0x4 + 0x0]
//         004099c0     MOV        EAX,dword ptr [this->_padding_ + EAX*0x4]
//         004099c3     TEST       EAX,EAX
//         004099c5     JZ         LAB_004099f5
//         004099c7     MOV        EDX,dword ptr [EAX + 0x8]
//         004099ca     LEA        EAX=>name[4],[ESP + 0x1c]
//         004099ce     PUSH       EDX
//         004099cf     PUSH       EAX
//         004099d0     CALL       strncpy                                          undefined strncpy()
//                              aibldmod.cpp:532 (18)
//         004099d5     MOV        this,dword ptr [ESI + 0x24]
//         004099d8     ADD        ESP,0xc
//         004099db     MOV        EAX,dword ptr [this->_padding_ + EBP*0x1]
//         004099de     FLD        float ptr [EAX + 0x30]
//         004099e1     FADD       ST0,ST0
//         004099e3     FSTP       float ptr [ESP + param_1]
//                              aibldmod.cpp:533 (12)
//         004099e7     FLD        float ptr [EAX + 0x34]
//         004099ea     FADD       ST0,ST0
//         004099ec     FSTP       float ptr [ESP + param_7]
//                              aibldmod.cpp:535 (2)
//         004099f3     JMP        LAB_00409a28
//                               LAB_004099f5                                                 XREF[1]:     004099c5(j)
//                              aibldmod.cpp:536 (10)
//         004099f5     LEA        EDX=>name[4],[ESP + 0x1c]
//         004099f9     PUSH       s_AddedBuildListItem                             = "AddedBuildListItem"
//         004099fe     PUSH       EDX
//                              aibldmod.cpp:541 (2)
//         004099ff     JMP        LAB_00409a0d
//                               LAB_00409a01                                                 XREF[1]:     004099aa(j)
//                              aibldmod.cpp:542 (20)
//         00409a01     PUSH       0x3f
//         00409a03     LEA        EAX=>name[4],[ESP + 0x1c]
//         00409a07     PUSH       s_SetGatherPercentage                            = "SetGatherPercentage"
//         00409a0c     PUSH       EAX
//                               LAB_00409a0d                                                 XREF[1]:     004099ff(j)
//         00409a0d     CALL       strncpy                                          undefined strncpy()
//         00409a12     ADD        ESP,0xc
//                              aibldmod.cpp:543 (8)
//         00409a15     MOV        dword ptr [ESP + param_1],0x40400000
//                              aibldmod.cpp:544 (11)
//         00409a1d     MOV        dword ptr [ESP + param_7],0x40400000
//                               LAB_00409a28                                                 XREF[1]:     004099f3(j)
//                              aibldmod.cpp:548 (20)
//         00409a28     MOV        EAX,dword ptr [ESP + param_3]
//         00409a2c     MOV        EBX,dword ptr [EBX + 0x1a0]
//         00409a32     XOR        EBP,EBP
//         00409a34     TEST       EAX,EAX
//         00409a36     JLE        LAB_00409b50
//                               LAB_00409a3c                                                 XREF[1]:     00409b4a(j)
//                              aibldmod.cpp:551 (94)
//         00409a3c     PUSH       0xb0
//         00409a41     CALL       operator_new                                     void * operator_new(uint param_1)
//         00409a46     ADD        ESP,0x4
//         00409a49     MOV        dword ptr [ESP + name[0]],EAX
//         00409a4d     XOR        ESI,ESI
//         00409a4f     CMP        EAX,ESI
//         00409a51     MOV        dword ptr [ESP + local_4],ESI
//         00409a55     JZ         LAB_00409a9a
//         00409a57     MOV        this,dword ptr [ESP + param_7]
//         00409a5e     MOV        EDX,dword ptr [ESP + param_1]
//         00409a62     PUSH       ESI
//         00409a63     PUSH       -0x1
//         00409a65     PUSH       -0x1
//         00409a67     PUSH       -0x1
//         00409a69     PUSH       0x3f800000
//         00409a6e     PUSH       this
//         00409a6f     PUSH       EDX
//         00409a70     MOV        EDX,dword ptr [ESP + param_5]
//         00409a77     LEA        this=>name[4],[ESP + 0x34]
//         00409a7b     PUSH       this
//         00409a7c     MOV        this,dword ptr [ESP + param_2]
//         00409a83     PUSH       EDX
//         00409a84     MOV        EDX,dword ptr [ESP + param_4]
//         00409a8b     PUSH       ESI
//         00409a8c     PUSH       0x1
//         00409a8e     PUSH       EBX
//         00409a8f     PUSH       this
//         00409a90     PUSH       EDX
//         00409a91     MOV        this,EAX
//         00409a93     CALL       BuildItem::BuildItem                             undefined BuildItem(BuildItem * this, int par
//         00409a98     MOV        ESI,EAX
//                               LAB_00409a9a                                                 XREF[1]:     00409a55(j)
//                              aibldmod.cpp:552 (16)
//         00409a9a     TEST       ESI,ESI
//         00409a9c     MOV        dword ptr [ESP + local_4],0xffffffff
//         00409aa4     JZ         LAB_00409b6a
//                              aibldmod.cpp:563 (9)
//         00409aaa     PUSH       0x0
//         00409aac     MOV        this,ESI
//         00409aae     CALL       BuildItem::setBuilt                              void setBuilt(BuildItem * this, int param_1)
//                              aibldmod.cpp:564 (9)
//         00409ab3     PUSH       0x0
//         00409ab5     MOV        this,ESI
//         00409ab7     CALL       BuildItem::setInProgress                         void setInProgress(BuildItem * this, int para
//                              aibldmod.cpp:565 (9)
//         00409abc     PUSH       0x0
//         00409abe     MOV        this,ESI
//         00409ac0     CALL       BuildItem::setBuildAttempts                      void setBuildAttempts(BuildItem * this, int p
//                              aibldmod.cpp:566 (9)
//         00409ac5     PUSH       0x0
//         00409ac7     MOV        this,ESI
//         00409ac9     CALL       BaseItem::setSkip                                void setSkip(BaseItem * this, int param_1)
//                              aibldmod.cpp:567 (9)
//         00409ace     PUSH       -0x1
//         00409ad0     MOV        this,ESI
//         00409ad2     CALL       BaseItem::setGameID                              void setGameID(BaseItem * this, int param_1)
//                              aibldmod.cpp:568 (12)
//         00409ad7     PUSH       0xbf800000
//         00409adc     MOV        this,ESI
//         00409ade     CALL       BaseItem::setX                                   void setX(BaseItem * this, float param_1)
//                              aibldmod.cpp:569 (12)
//         00409ae3     PUSH       0xbf800000
//         00409ae8     MOV        this,ESI
//         00409aea     CALL       BaseItem::setY                                   void setY(BaseItem * this, float param_1)
//                              aibldmod.cpp:570 (12)
//         00409aef     PUSH       0xbf800000
//         00409af4     MOV        this,ESI
//         00409af6     CALL       BaseItem::setZ                                   void setZ(BaseItem * this, float param_1)
//                              aibldmod.cpp:571 (9)
//         00409afb     PUSH       0x0
//         00409afd     MOV        this,ESI
//         00409aff     CALL       BuildItem::setNumberBuilds                       void setNumberBuilds(BuildItem * this, int pa
//                              aibldmod.cpp:572 (12)
//         00409b04     MOV        EAX,dword ptr [ESP + param_6]
//         00409b08     MOV        this,ESI
//         00409b0a     PUSH       EAX
//         00409b0b     CALL       BuildItem::setBuildCap                           void setBuildCap(BuildItem * this, int param_1)
//                              aibldmod.cpp:573 (9)
//         00409b10     PUSH       0x0
//         00409b12     MOV        this,ESI
//         00409b14     CALL       BuildItem::setSkipCycles                         void setSkipCycles(BuildItem * this, int para
//                              aibldmod.cpp:574 (9)
//         00409b19     PUSH       0x0
//         00409b1b     MOV        this,ESI
//         00409b1d     CALL       BuildItem::setPermanentSkip                      void setPermanentSkip(BuildItem * this, uchar
//                              aibldmod.cpp:577 (3)
//         00409b22     MOV        dword ptr [ESI + 0x70],EDI
//                              aibldmod.cpp:578 (6)
//         00409b25     MOV        EAX,dword ptr [EDI + 0x6c]
//         00409b28     MOV        dword ptr [ESI + 0x6c],EAX
//                              aibldmod.cpp:583 (4)
//         00409b2b     INC        EBX
//         00409b2c     MOV        dword ptr [EAX + 0x70],ESI
//                              aibldmod.cpp:584 (33)
//         00409b2f     MOV        EAX,dword ptr [ESP + local_54]
//         00409b33     MOV        dword ptr [EDI + 0x6c],ESI
//         00409b36     MOV        EDX,dword ptr [EAX + 0x1a0]
//         00409b3c     INC        EDX
//         00409b3d     INC        EBP
//         00409b3e     MOV        dword ptr [EAX + 0x1a0],EDX
//         00409b44     MOV        EAX,dword ptr [ESP + param_3]
//         00409b48     CMP        EBP,EAX
//         00409b4a     JL         LAB_00409a3c
//                               LAB_00409b50                                                 XREF[1]:     00409a36(j)
//                              aibldmod.cpp:591 (5)
//         00409b50     MOV        EAX,0x1
//                               LAB_00409b55                                                 XREF[2]:     00409982(j), 00409b6c(j)
//                              aibldmod.cpp:592 (21)
//         00409b55     MOV        this,dword ptr [ESP + local_c]
//         00409b59     POP        EDI
//         00409b5a     POP        ESI
//         00409b5b     POP        EBP
//         00409b5c     MOV        dword ptr FS:[0x0],this
//         00409b63     POP        EBX
//         00409b64     ADD        ESP,0x54
//         00409b67     RET        0x1c
//                               LAB_00409b6a                                                 XREF[1]:     00409aa4(j)
//                              aibldmod.cpp:556 (4)
//         00409b6a     XOR        EAX,EAX
//         00409b6c     JMP        LAB_00409b55
//         00409b6e     ??         90h
//         00409b6f     NOP
    return 0;
}

int BuildAIModule::numberItemsBuilt() {
    /* TODO: Stub */
//                              int __thiscall numberItemsBuilt(BuildAIModule * this)
//              int               EAX:4          <RETURN>
//              BuildAIModule *   ECX:4 (auto)   this
//                               ?numberItemsBuilt@BuildAIModule@@QBEHXZ
//                               BuildAIModule::numberItemsBuilt
//                              aibldmod.cpp:597 (2)
//         00409b70     PUSH       EBX
//         00409b71     PUSH       ESI
//                              aibldmod.cpp:601 (7)
//         00409b72     MOV        ESI,dword ptr [ECX + this+0x15c]
//         00409b78     PUSH       EDI
//                              aibldmod.cpp:602 (16)
//         00409b79     LEA        EDI,[ECX + this->buildList._padding_]
//         00409b7f     XOR        EBX,EBX
//         00409b81     CMP        ESI,EDI
//         00409b83     JZ         LAB_00409b9d
//                               LAB_00409b85                                                 XREF[1]:     00409b9b(j)
//         00409b85     TEST       ESI,ESI
//         00409b87     JZ         LAB_00409b9d
//                              aibldmod.cpp:603 (12)
//         00409b89     MOV        this,ESI
//         00409b8b     CALL       BuildItem::built                                 int built(BuildItem * this)
//         00409b90     CMP        EAX,0x1
//         00409b93     JNZ        LAB_00409b96
//                              aibldmod.cpp:604 (1)
//         00409b95     INC        EBX
//                               LAB_00409b96                                                 XREF[1]:     00409b93(j)
//                              aibldmod.cpp:605 (7)
//         00409b96     MOV        ESI,dword ptr [ESI + 0x6c]
//         00409b99     CMP        ESI,EDI
//         00409b9b     JNZ        LAB_00409b85
//                               LAB_00409b9d                                                 XREF[2]:     00409b83(j), 00409b87(j)
//                              aibldmod.cpp:608 (6)
//         00409b9d     POP        EDI
//         00409b9e     MOV        EAX,EBX
//         00409ba0     POP        ESI
//         00409ba1     POP        EBX
//         00409ba2     RET
//         00409ba3     ??         90h
//         00409ba4     NOP
//         00409ba5     NOP
//         00409ba6     NOP
//         00409ba7     NOP
//         00409ba8     NOP
//         00409ba9     NOP
//         00409baa     NOP
//         00409bab     NOP
//         00409bac     NOP
//         00409bad     NOP
//         00409bae     NOP
//         00409baf     NOP
    return 0;
}

int BuildAIModule::numberItemsInProgress() {
    /* TODO: Stub */
//                              int __thiscall numberItemsInProgress(BuildAIModule * this)
//              int               EAX:4          <RETURN>
//              BuildAIModule *   ECX:4 (auto)   this
//                               ?numberItemsInProgress@BuildAIModule@@QBEHXZ
//                               BuildAIModule::numberItemsInProgress
//                              aibldmod.cpp:613 (2)
//         00409bb0     PUSH       EBX
//         00409bb1     PUSH       ESI
//                              aibldmod.cpp:617 (7)
//         00409bb2     MOV        ESI,dword ptr [ECX + this+0x15c]
//         00409bb8     PUSH       EDI
//                              aibldmod.cpp:618 (16)
//         00409bb9     LEA        EDI,[ECX + this->buildList._padding_]
//         00409bbf     XOR        EBX,EBX
//         00409bc1     CMP        ESI,EDI
//         00409bc3     JZ         LAB_00409bdd
//                               LAB_00409bc5                                                 XREF[1]:     00409bdb(j)
//         00409bc5     TEST       ESI,ESI
//         00409bc7     JZ         LAB_00409bdd
//                              aibldmod.cpp:619 (12)
//         00409bc9     MOV        this,ESI
//         00409bcb     CALL       BuildItem::inProgress                            int inProgress(BuildItem * this)
//         00409bd0     CMP        EAX,0x1
//         00409bd3     JNZ        LAB_00409bd6
//                              aibldmod.cpp:620 (1)
//         00409bd5     INC        EBX
//                               LAB_00409bd6                                                 XREF[1]:     00409bd3(j)
//                              aibldmod.cpp:621 (7)
//         00409bd6     MOV        ESI,dword ptr [ESI + 0x6c]
//         00409bd9     CMP        ESI,EDI
//         00409bdb     JNZ        LAB_00409bc5
//                               LAB_00409bdd                                                 XREF[2]:     00409bc3(j), 00409bc7(j)
//                              aibldmod.cpp:624 (6)
//         00409bdd     POP        EDI
//         00409bde     MOV        EAX,EBX
//         00409be0     POP        ESI
//         00409be1     POP        EBX
//         00409be2     RET
//         00409be3     ??         90h
//         00409be4     NOP
//         00409be5     NOP
//         00409be6     NOP
//         00409be7     NOP
//         00409be8     NOP
//         00409be9     NOP
//         00409bea     NOP
//         00409beb     NOP
//         00409bec     NOP
//         00409bed     NOP
//         00409bee     NOP
//         00409bef     NOP
    return 0;
}

int BuildAIModule::numberItemsBuiltOrInProgress() {
    /* TODO: Stub */
//                              int __thiscall numberItemsBuiltOrInProgress(BuildAIModule * this)
//              int               EAX:4          <RETURN>
//              BuildAIModule *   ECX:4 (auto)   this
//                               ?numberItemsBuiltOrInProgress@BuildAIModule@@QBEHXZ
//                               BuildAIModule::numberItemsBuiltOrInProgress
//                              aibldmod.cpp:629 (2)
//         00409bf0     PUSH       EBX
//         00409bf1     PUSH       ESI
//                              aibldmod.cpp:633 (7)
//         00409bf2     MOV        ESI,dword ptr [ECX + this+0x15c]
//         00409bf8     PUSH       EDI
//                              aibldmod.cpp:634 (16)
//         00409bf9     LEA        EDI,[ECX + this->buildList._padding_]
//         00409bff     XOR        EBX,EBX
//         00409c01     CMP        ESI,EDI
//         00409c03     JZ         LAB_00409c29
//                               LAB_00409c05                                                 XREF[1]:     00409c27(j)
//         00409c05     TEST       ESI,ESI
//         00409c07     JZ         LAB_00409c29
//                              aibldmod.cpp:635 (24)
//         00409c09     MOV        this,ESI
//         00409c0b     CALL       BuildItem::inProgress                            int inProgress(BuildItem * this)
//         00409c10     CMP        EAX,0x1
//         00409c13     JZ         LAB_00409c21
//         00409c15     MOV        this,ESI
//         00409c17     CALL       BuildItem::built                                 int built(BuildItem * this)
//         00409c1c     CMP        EAX,0x1
//         00409c1f     JNZ        LAB_00409c22
//                               LAB_00409c21                                                 XREF[1]:     00409c13(j)
//                              aibldmod.cpp:636 (1)
//         00409c21     INC        EBX
//                               LAB_00409c22                                                 XREF[1]:     00409c1f(j)
//                              aibldmod.cpp:637 (7)
//         00409c22     MOV        ESI,dword ptr [ESI + 0x6c]
//         00409c25     CMP        ESI,EDI
//         00409c27     JNZ        LAB_00409c05
//                               LAB_00409c29                                                 XREF[2]:     00409c03(j), 00409c07(j)
//                              aibldmod.cpp:640 (6)
//         00409c29     POP        EDI
//         00409c2a     MOV        EAX,EBX
//         00409c2c     POP        ESI
//         00409c2d     POP        EBX
//         00409c2e     RET
//         00409c2f     ??         90h
    return 0;
}

int BuildAIModule::numberItemsIntoBuildList() {
    /* TODO: Stub */
//                              int __thiscall numberItemsIntoBuildList(BuildAIModule * this)
//              int               EAX:4          <RETURN>
//              BuildAIModule *   ECX:4 (auto)   this
//                               ?numberItemsIntoBuildList@BuildAIModule@@QBEHXZ              XREF[2]:     aiStatus:005147d2(c),
//                               BuildAIModule::numberItemsIntoBuildList                                   logStatus:005191c7(c)
//                              aibldmod.cpp:645 (6)
//         00409c30     MOV        EAX,dword ptr [ECX + this->numberItemsIntoBuil
//                              aibldmod.cpp:647 (1)
//         00409c36     RET
//         00409c37     ??         90h
//         00409c38     NOP
//         00409c39     NOP
//         00409c3a     NOP
//         00409c3b     NOP
//         00409c3c     NOP
//         00409c3d     NOP
//         00409c3e     NOP
//         00409c3f     NOP
    return 0;
}

char* BuildAIModule::lastBuildItemRequested() {
    /* TODO: Stub */
//                              char * __thiscall lastBuildItemRequested(BuildAIModule * this)
//              char *            EAX:4          <RETURN>
//              BuildAIModule *   ECX:4 (auto)   this
//                               ?lastBuildItemRequested@BuildAIModule@@QBEPADXZ              XREF[2]:     aiStatus:005147e4(c),
//                               BuildAIModule::lastBuildItemRequested                                     logStatus:005191d9(c)
//                              aibldmod.cpp:652 (6)
//         00409c40     LEA        EAX,[ECX + this->lastBuildItemRequestedValue[0]]
//                              aibldmod.cpp:654 (1)
//         00409c46     RET
//         00409c47     ??         90h
//         00409c48     NOP
//         00409c49     NOP
//         00409c4a     NOP
//         00409c4b     NOP
//         00409c4c     NOP
//         00409c4d     NOP
//         00409c4e     NOP
//         00409c4f     NOP
    return 0;
}

char* BuildAIModule::currentBuildItemRequested() {
    /* TODO: Stub */
//                              char * __thiscall currentBuildItemRequested(BuildAIModule * this)
//              char *            EAX:4          <RETURN>
//              BuildAIModule *   ECX:4 (auto)   this
//                               ?currentBuildItemRequested@BuildAIModule@@QBEPADXZ           XREF[2]:     aiStatus:00514808(c),
//                               BuildAIModule::currentBuildItemRequested                                  logStatus:005191eb(c)
//                              aibldmod.cpp:659 (6)
//         00409c50     LEA        EAX,[ECX + this->currentBuildItemRequestedValu
//                              aibldmod.cpp:661 (1)
//         00409c56     RET
//         00409c57     ??         90h
//         00409c58     NOP
//         00409c59     NOP
//         00409c5a     NOP
//         00409c5b     NOP
//         00409c5c     NOP
//         00409c5d     NOP
//         00409c5e     NOP
//         00409c5f     NOP
    return 0;
}

char* BuildAIModule::nextBuildItemRequested() {
    /* TODO: Stub */
//                              char * __thiscall nextBuildItemRequested(BuildAIModule * this)
//              char *            EAX:4          <RETURN>
//              BuildAIModule *   ECX:4 (auto)   this
//                               ?nextBuildItemRequested@BuildAIModule@@QBEPADXZ              XREF[1]:     aiStatus:005147f6(c)
//                               BuildAIModule::nextBuildItemRequested
//                              aibldmod.cpp:666 (6)
//         00409c60     LEA        EAX,[ECX + this->nextBuildItemRequestedValue[0]]
//                              aibldmod.cpp:668 (1)
//         00409c66     RET
//         00409c67     ??         90h
//         00409c68     NOP
//         00409c69     NOP
//         00409c6a     NOP
//         00409c6b     NOP
//         00409c6c     NOP
//         00409c6d     NOP
//         00409c6e     NOP
//         00409c6f     NOP
    return 0;
}

int BuildAIModule::numberItemsOfType(int param_1, int param_2) {
    /* TODO: Stub */
//                              int __thiscall numberItemsOfType(BuildAIModule * this, int param_1,
//              int               EAX:4          <RETURN>
//              BuildAIModule *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00409c91(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00409c8d(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00409c83(W), 00409caf(RW), 00409cba(R)
//              int               Stack[-0x8]:4  count
//                               ?numberItemsOfType@BuildAIModule@@QAEHHH@Z                   XREF[4]:     numberAvailableStoragePits:00501c1
//                               BuildAIModule::numberItemsOfType                                          numberAvailableStoragePits:00501c4
//                                                                                                         numberAvailableGranaries:00501cdb(
//                                                                                                         numberAvailableGranaries:00501d03(
//                              aibldmod.cpp:673 (4)
//         00409c70     PUSH       this
//         00409c71     PUSH       EBX
//         00409c72     PUSH       EBP
//         00409c73     PUSH       ESI
//                              aibldmod.cpp:675 (7)
//         00409c74     MOV        ESI,dword ptr [ECX + this+0x15c]
//         00409c7a     PUSH       EDI
//                              aibldmod.cpp:676 (30)
//         00409c7b     LEA        EDI,[ECX + this->buildList._padding_]
//         00409c81     CMP        ESI,EDI
//         00409c83     MOV        dword ptr [ESP + local_4],0x0
//         00409c8b     JZ         LAB_00409cba
//         00409c8d     MOV        EBX,dword ptr [ESP + param_2]
//         00409c91     MOV        EBP,dword ptr [ESP + param_1]
//                               LAB_00409c95                                                 XREF[1]:     00409cb8(j)
//         00409c95     TEST       ESI,ESI
//         00409c97     JZ         LAB_00409cba
//                              aibldmod.cpp:677 (22)
//         00409c99     MOV        this,ESI
//         00409c9b     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
//         00409ca0     CMP        EAX,EBP
//         00409ca2     JNZ        LAB_00409cb3
//         00409ca4     MOV        this,ESI
//         00409ca6     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
//         00409cab     CMP        EAX,EBX
//         00409cad     JNZ        LAB_00409cb3
//                              aibldmod.cpp:678 (4)
//         00409caf     INC        dword ptr [ESP + local_4]
//                               LAB_00409cb3                                                 XREF[2]:     00409ca2(j), 00409cad(j)
//                              aibldmod.cpp:679 (7)
//         00409cb3     MOV        ESI,dword ptr [ESI + 0x6c]
//         00409cb6     CMP        ESI,EDI
//         00409cb8     JNZ        LAB_00409c95
//                               LAB_00409cba                                                 XREF[2]:     00409c8b(j), 00409c97(j)
//                              aibldmod.cpp:681 (4)
//         00409cba     MOV        EAX,dword ptr [ESP + local_4]
//                              aibldmod.cpp:682 (8)
//         00409cbe     POP        EDI
//         00409cbf     POP        ESI
//         00409cc0     POP        EBP
//         00409cc1     POP        EBX
//         00409cc2     POP        this
//         00409cc3     RET        0x8
//         00409cc6     ??         90h
//         00409cc7     NOP
//         00409cc8     NOP
//         00409cc9     NOP
//         00409cca     NOP
//         00409ccb     NOP
//         00409ccc     NOP
//         00409ccd     NOP
//         00409cce     NOP
//         00409ccf     NOP
    return 0;
}

int BuildAIModule::numberBuiltItemsOfType(int param_1, int param_2) {
    /* TODO: Stub */
//                              int __thiscall numberBuiltItemsOfType(BuildAIModule * this, int para
//              int               EAX:4          <RETURN>
//              BuildAIModule *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00409cf1(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00409ced(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00409ce3(W), 00409d1b(RW), 00409d26(R)
//              int               Stack[-0x8]:4  count
//                               ?numberBuiltItemsOfType@BuildAIModule@@QAEHHH@Z              XREF[2]:     setupInfluenceMap:004deec5(c),
//                               BuildAIModule::numberBuiltItemsOfType                                     setupInfluenceMap:004deed9(c)
//                              aibldmod.cpp:687 (4)
//         00409cd0     PUSH       this
//         00409cd1     PUSH       EBX
//         00409cd2     PUSH       EBP
//         00409cd3     PUSH       ESI
//                              aibldmod.cpp:689 (7)
//         00409cd4     MOV        ESI,dword ptr [ECX + this+0x15c]
//         00409cda     PUSH       EDI
//                              aibldmod.cpp:690 (30)
//         00409cdb     LEA        EDI,[ECX + this->buildList._padding_]
//         00409ce1     CMP        ESI,EDI
//         00409ce3     MOV        dword ptr [ESP + local_4],0x0
//         00409ceb     JZ         LAB_00409d26
//         00409ced     MOV        EBX,dword ptr [ESP + param_2]
//         00409cf1     MOV        EBP,dword ptr [ESP + param_1]
//                               LAB_00409cf5                                                 XREF[1]:     00409d24(j)
//         00409cf5     TEST       ESI,ESI
//         00409cf7     JZ         LAB_00409d26
//                              aibldmod.cpp:692 (34)
//         00409cf9     MOV        this,ESI
//         00409cfb     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
//         00409d00     CMP        EAX,EBP
//         00409d02     JNZ        LAB_00409d1f
//         00409d04     MOV        this,ESI
//         00409d06     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
//         00409d0b     CMP        EAX,EBX
//         00409d0d     JNZ        LAB_00409d1f
//         00409d0f     MOV        this,ESI
//         00409d11     CALL       BuildItem::built                                 int built(BuildItem * this)
//         00409d16     CMP        EAX,0x1
//         00409d19     JNZ        LAB_00409d1f
//                              aibldmod.cpp:693 (4)
//         00409d1b     INC        dword ptr [ESP + local_4]
//                               LAB_00409d1f                                                 XREF[3]:     00409d02(j), 00409d0d(j),
//                                                                                                         00409d19(j)
//                              aibldmod.cpp:694 (7)
//         00409d1f     MOV        ESI,dword ptr [ESI + 0x6c]
//         00409d22     CMP        ESI,EDI
//         00409d24     JNZ        LAB_00409cf5
//                               LAB_00409d26                                                 XREF[2]:     00409ceb(j), 00409cf7(j)
//                              aibldmod.cpp:696 (4)
//         00409d26     MOV        EAX,dword ptr [ESP + local_4]
//                              aibldmod.cpp:697 (8)
//         00409d2a     POP        EDI
//         00409d2b     POP        ESI
//         00409d2c     POP        EBP
//         00409d2d     POP        EBX
//         00409d2e     POP        this
//         00409d2f     RET        0x8
//         00409d32     ??         90h
//         00409d33     NOP
//         00409d34     NOP
//         00409d35     NOP
//         00409d36     NOP
//         00409d37     NOP
//         00409d38     NOP
//         00409d39     NOP
//         00409d3a     NOP
//         00409d3b     NOP
//         00409d3c     NOP
//         00409d3d     NOP
//         00409d3e     NOP
//         00409d3f     NOP
    return 0;
}

int BuildAIModule::numberUnbuiltItemsOfType(int param_1, int param_2) {
    /* TODO: Stub */
//                              int __thiscall numberUnbuiltItemsOfType(BuildAIModule * this, int pa
//              int               EAX:4          <RETURN>
//              BuildAIModule *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00409d61(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00409d5d(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00409d53(W), 00409d8a(RW), 00409d95(R)
//              int               Stack[-0x8]:4  count
//                               ?numberUnbuiltItemsOfType@BuildAIModule@@QAEHHH@Z            XREF[2]:     numberAvailableStoragePits:00501ba
//                               BuildAIModule::numberUnbuiltItemsOfType                                   numberAvailableGranaries:00501c84(
//                              aibldmod.cpp:702 (4)
//         00409d40     PUSH       this
//         00409d41     PUSH       EBX
//         00409d42     PUSH       EBP
//         00409d43     PUSH       ESI
//                              aibldmod.cpp:704 (7)
//         00409d44     MOV        ESI,dword ptr [ECX + this+0x15c]
//         00409d4a     PUSH       EDI
//                              aibldmod.cpp:705 (30)
//         00409d4b     LEA        EDI,[ECX + this->buildList._padding_]
//         00409d51     CMP        ESI,EDI
//         00409d53     MOV        dword ptr [ESP + local_4],0x0
//         00409d5b     JZ         LAB_00409d95
//         00409d5d     MOV        EBX,dword ptr [ESP + param_2]
//         00409d61     MOV        EBP,dword ptr [ESP + param_1]
//                               LAB_00409d65                                                 XREF[1]:     00409d93(j)
//         00409d65     TEST       ESI,ESI
//         00409d67     JZ         LAB_00409d95
//                              aibldmod.cpp:707 (33)
//         00409d69     MOV        this,ESI
//         00409d6b     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
//         00409d70     CMP        EAX,EBP
//         00409d72     JNZ        LAB_00409d8e
//         00409d74     MOV        this,ESI
//         00409d76     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
//         00409d7b     CMP        EAX,EBX
//         00409d7d     JNZ        LAB_00409d8e
//         00409d7f     MOV        this,ESI
//         00409d81     CALL       BuildItem::built                                 int built(BuildItem * this)
//         00409d86     TEST       EAX,EAX
//         00409d88     JNZ        LAB_00409d8e
//                              aibldmod.cpp:708 (4)
//         00409d8a     INC        dword ptr [ESP + local_4]
//                               LAB_00409d8e                                                 XREF[3]:     00409d72(j), 00409d7d(j),
//                                                                                                         00409d88(j)
//                              aibldmod.cpp:709 (7)
//         00409d8e     MOV        ESI,dword ptr [ESI + 0x6c]
//         00409d91     CMP        ESI,EDI
//         00409d93     JNZ        LAB_00409d65
//                               LAB_00409d95                                                 XREF[2]:     00409d5b(j), 00409d67(j)
//                              aibldmod.cpp:711 (4)
//         00409d95     MOV        EAX,dword ptr [ESP + local_4]
//                              aibldmod.cpp:712 (8)
//         00409d99     POP        EDI
//         00409d9a     POP        ESI
//         00409d9b     POP        EBP
//         00409d9c     POP        EBX
//         00409d9d     POP        this
//         00409d9e     RET        0x8
//         00409da1     ??         90h
//         00409da2     NOP
//         00409da3     NOP
//         00409da4     NOP
//         00409da5     NOP
//         00409da6     NOP
//         00409da7     NOP
//         00409da8     NOP
//         00409da9     NOP
//         00409daa     NOP
//         00409dab     NOP
//         00409dac     NOP
//         00409dad     NOP
//         00409dae     NOP
//         00409daf     NOP
    return 0;
}

int BuildAIModule::numberBuiltOrInProgressItemsOfType(int param_1, int param_2) {
    /* TODO: Stub */
//                              int __thiscall numberBuiltOrInProgressItemsOfType(BuildAIModule * th
//              int               EAX:4          <RETURN>
//              BuildAIModule *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00409dd1(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00409dcd(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00409dc3(W), 00409e07(RW), 00409e12(R)
//              int               Stack[-0x8]:4  count
//                               ?numberBuiltOrInProgressItemsOfType@BuildAIModule@@UAEHHH@Z  XREF[2]:     numberBuiltOrInProgressItemsOfType
//                               BuildAIModule::numberBuiltOrInProgressItemsOfType                         0056e780(*)
//                              aibldmod.cpp:717 (4)
//         00409db0     PUSH       this
//         00409db1     PUSH       EBX
//         00409db2     PUSH       EBP
//         00409db3     PUSH       ESI
//                              aibldmod.cpp:719 (7)
//         00409db4     MOV        ESI,dword ptr [ECX + this+0x15c]
//         00409dba     PUSH       EDI
//                              aibldmod.cpp:720 (30)
//         00409dbb     LEA        EDI,[ECX + this->buildList._padding_]
//         00409dc1     CMP        ESI,EDI
//         00409dc3     MOV        dword ptr [ESP + local_4],0x0
//         00409dcb     JZ         LAB_00409e12
//         00409dcd     MOV        EBX,dword ptr [ESP + param_2]
//         00409dd1     MOV        EBP,dword ptr [ESP + param_1]
//                               LAB_00409dd5                                                 XREF[1]:     00409e10(j)
//         00409dd5     TEST       ESI,ESI
//         00409dd7     JZ         LAB_00409e12
//                              aibldmod.cpp:722 (46)
//         00409dd9     MOV        this,ESI
//         00409ddb     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
//         00409de0     CMP        EAX,EBP
//         00409de2     JNZ        LAB_00409e0b
//         00409de4     MOV        this,ESI
//         00409de6     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
//         00409deb     CMP        EAX,EBX
//         00409ded     JNZ        LAB_00409e0b
//         00409def     MOV        this,ESI
//         00409df1     CALL       BuildItem::built                                 int built(BuildItem * this)
//         00409df6     CMP        EAX,0x1
//         00409df9     JZ         LAB_00409e07
//         00409dfb     MOV        this,ESI
//         00409dfd     CALL       BuildItem::inProgress                            int inProgress(BuildItem * this)
//         00409e02     CMP        EAX,0x1
//         00409e05     JNZ        LAB_00409e0b
//                               LAB_00409e07                                                 XREF[1]:     00409df9(j)
//                              aibldmod.cpp:723 (4)
//         00409e07     INC        dword ptr [ESP + local_4]
//                               LAB_00409e0b                                                 XREF[3]:     00409de2(j), 00409ded(j),
//                                                                                                         00409e05(j)
//                              aibldmod.cpp:724 (7)
//         00409e0b     MOV        ESI,dword ptr [ESI + 0x6c]
//         00409e0e     CMP        ESI,EDI
//         00409e10     JNZ        LAB_00409dd5
//                               LAB_00409e12                                                 XREF[2]:     00409dcb(j), 00409dd7(j)
//                              aibldmod.cpp:726 (4)
//         00409e12     MOV        EAX,dword ptr [ESP + local_4]
//                              aibldmod.cpp:727 (8)
//         00409e16     POP        EDI
//         00409e17     POP        ESI
//         00409e18     POP        EBP
//         00409e19     POP        EBX
//         00409e1a     POP        this
//         00409e1b     RET        0x8
//         00409e1e     ??         90h
//         00409e1f     NOP
    return 0;
}

int BuildAIModule::numberInProgressItemsOfType(int param_1, int param_2) {
    /* TODO: Stub */
//                              int __thiscall numberInProgressItemsOfType(BuildAIModule * this, int
//              int               EAX:4          <RETURN>
//              BuildAIModule *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00409e41(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00409e3d(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00409e33(W), 00409e6b(RW), 00409e76(R)
//              int               Stack[-0x8]:4  count
//                               ?numberInProgressItemsOfType@BuildAIModule@@QAEHHH@Z         XREF[1]:     numberBuiltOrInProgressItemsOfType
//                               BuildAIModule::numberInProgressItemsOfType
//                              aibldmod.cpp:732 (4)
//         00409e20     PUSH       this
//         00409e21     PUSH       EBX
//         00409e22     PUSH       EBP
//         00409e23     PUSH       ESI
//                              aibldmod.cpp:734 (7)
//         00409e24     MOV        ESI,dword ptr [ECX + this+0x15c]
//         00409e2a     PUSH       EDI
//                              aibldmod.cpp:735 (30)
//         00409e2b     LEA        EDI,[ECX + this->buildList._padding_]
//         00409e31     CMP        ESI,EDI
//         00409e33     MOV        dword ptr [ESP + local_4],0x0
//         00409e3b     JZ         LAB_00409e76
//         00409e3d     MOV        EBX,dword ptr [ESP + param_2]
//         00409e41     MOV        EBP,dword ptr [ESP + param_1]
//                               LAB_00409e45                                                 XREF[1]:     00409e74(j)
//         00409e45     TEST       ESI,ESI
//         00409e47     JZ         LAB_00409e76
//                              aibldmod.cpp:737 (34)
//         00409e49     MOV        this,ESI
//         00409e4b     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
//         00409e50     CMP        EAX,EBP
//         00409e52     JNZ        LAB_00409e6f
//         00409e54     MOV        this,ESI
//         00409e56     CALL       BuildItem::buildCategory                         int buildCategory(BuildItem * this)
//         00409e5b     CMP        EAX,EBX
//         00409e5d     JNZ        LAB_00409e6f
//         00409e5f     MOV        this,ESI
//         00409e61     CALL       BuildItem::inProgress                            int inProgress(BuildItem * this)
//         00409e66     CMP        EAX,0x1
//         00409e69     JNZ        LAB_00409e6f
//                              aibldmod.cpp:738 (4)
//         00409e6b     INC        dword ptr [ESP + local_4]
//                               LAB_00409e6f                                                 XREF[3]:     00409e52(j), 00409e5d(j),
//                                                                                                         00409e69(j)
//                              aibldmod.cpp:739 (7)
//         00409e6f     MOV        ESI,dword ptr [ESI + 0x6c]
//         00409e72     CMP        ESI,EDI
//         00409e74     JNZ        LAB_00409e45
//                               LAB_00409e76                                                 XREF[2]:     00409e3b(j), 00409e47(j)
//                              aibldmod.cpp:741 (4)
//         00409e76     MOV        EAX,dword ptr [ESP + local_4]
//                              aibldmod.cpp:742 (8)
//         00409e7a     POP        EDI
//         00409e7b     POP        ESI
//         00409e7c     POP        EBP
//         00409e7d     POP        EBX
//         00409e7e     POP        this
//         00409e7f     RET        0x8
//         00409e82     ??         90h
//         00409e83     NOP
//         00409e84     NOP
//         00409e85     NOP
//         00409e86     NOP
//         00409e87     NOP
//         00409e88     NOP
//         00409e89     NOP
//         00409e8a     NOP
//         00409e8b     NOP
//         00409e8c     NOP
//         00409e8d     NOP
//         00409e8e     NOP
//         00409e8f     NOP
    return 0;
}

void BuildAIModule::removeOldList() {
    /* TODO: Stub */
//                              void __thiscall removeOldList(BuildAIModule * this)
//              void              <VOID>         <RETURN>
//              BuildAIModule *   ECX:4 (auto)   this
//                               ?removeOldList@BuildAIModule@@IAEXXZ                         XREF[2]:     ~BuildAIModule:00408d88(c),
//                               BuildAIModule::removeOldList                                              loadBuildList:00409531(c)
//                              aibldmod.cpp:747 (5)
//         00409e90     PUSH       EBX
//         00409e91     MOV        EBX,this
//         00409e93     PUSH       ESI
//         00409e94     PUSH       EDI
//                              aibldmod.cpp:748 (6)
//         00409e95     MOV        this,dword ptr [EBX + 0x15c]
//                              aibldmod.cpp:750 (14)
//         00409e9b     LEA        EDI,[EBX + 0xf0]
//         00409ea1     CMP        this,EDI
//         00409ea3     JZ         LAB_00409eb8
//                               LAB_00409ea5                                                 XREF[1]:     00409eb6(j)
//         00409ea5     TEST       this,this
//         00409ea7     JZ         LAB_00409eb8
//                              aibldmod.cpp:752 (11)
//         00409ea9     MOV        EAX,dword ptr [this->_padding_]
//         00409eab     MOV        ESI,dword ptr [ECX + this->_padding_]
//         00409eae     PUSH       0x1
//         00409eb0     CALL       dword ptr [EAX]
//         00409eb2     CMP        ESI,EDI
//                              aibldmod.cpp:753 (4)
//         00409eb4     MOV        this,ESI
//         00409eb6     JNZ        LAB_00409ea5
//                               LAB_00409eb8                                                 XREF[2]:     00409ea3(j), 00409ea7(j)
//                              aibldmod.cpp:755 (6)
//         00409eb8     MOV        dword ptr [EBX + 0x15c],EDI
//                              aibldmod.cpp:756 (6)
//         00409ebe     MOV        dword ptr [EBX + 0x160],EDI
//                              aibldmod.cpp:758 (14)
//         00409ec4     POP        EDI
//         00409ec5     MOV        dword ptr [EBX + 0x1a0],0x0
//         00409ecf     POP        ESI
//         00409ed0     POP        EBX
//         00409ed1     RET
//         00409ed2     ??         90h
//         00409ed3     NOP
//         00409ed4     NOP
//         00409ed5     NOP
//         00409ed6     NOP
//         00409ed7     NOP
//         00409ed8     NOP
//         00409ed9     NOP
//         00409eda     NOP
//         00409edb     NOP
//         00409edc     NOP
//         00409edd     NOP
//         00409ede     NOP
//         00409edf     NOP
    return;
}

BuildItem* BuildAIModule::anyBuildListItem(int param_1, int param_2, int param_3) {
    /* TODO: Stub */
//                              BuildItem * __thiscall anyBuildListItem(BuildAIModule * this, int pa
//              BuildItem *       EAX:4          <RETURN>
//              BuildAIModule *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00409f07(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00409ef8(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     00409ef4(R)
//                               ?anyBuildListItem@BuildAIModule@@IAEPAVBuildItem@@HHH@Z
//                               BuildAIModule::anyBuildListItem
//                              aibldmod.cpp:764 (3)
//         00409ee0     PUSH       EBX
//         00409ee1     PUSH       EBP
//         00409ee2     PUSH       ESI
//                              aibldmod.cpp:768 (6)
//         00409ee3     MOV        ESI,dword ptr [ECX + this+0x15c]
//                              aibldmod.cpp:769 (23)
//         00409ee9     LEA        EBX,[ECX + this->buildList._padding_]
//         00409eef     PUSH       EDI
//         00409ef0     CMP        ESI,EBX
//         00409ef2     JZ         LAB_00409f3a
//         00409ef4     MOV        EBP,dword ptr [ESP + param_3]
//         00409ef8     MOV        EDI,dword ptr [ESP + param_2]
//                               LAB_00409efc                                                 XREF[1]:     00409f26(j)
//         00409efc     TEST       ESI,ESI
//         00409efe     JZ         LAB_00409f3a
//                              aibldmod.cpp:772 (33)
//         00409f00     MOV        this,ESI
//         00409f02     CALL       BaseItem::typeID                                 int typeID(BaseItem * this)
//         00409f07     CMP        EAX,dword ptr [ESP + param_1]
//         00409f0b     JNZ        LAB_00409f21
//         00409f0d     TEST       EDI,EDI
//         00409f0f     JZ         LAB_00409f31
//         00409f11     CMP        EDI,0x1
//         00409f14     JNZ        LAB_00409f21
//         00409f16     MOV        this,ESI
//         00409f18     CALL       BuildItem::built                                 int built(BuildItem * this)
//         00409f1d     CMP        EAX,EBP
//         00409f1f     JZ         LAB_00409f31
//                               LAB_00409f21                                                 XREF[2]:     00409f0b(j), 00409f14(j)
//                              aibldmod.cpp:774 (7)
//         00409f21     MOV        ESI,dword ptr [ESI + 0x6c]
//         00409f24     CMP        ESI,EBX
//         00409f26     JNZ        LAB_00409efc
//                              aibldmod.cpp:776 (2)
//         00409f28     XOR        EAX,EAX
//                              aibldmod.cpp:777 (7)
//         00409f2a     POP        EDI
//         00409f2b     POP        ESI
//         00409f2c     POP        EBP
//         00409f2d     POP        EBX
//         00409f2e     RET        0xc
//                               LAB_00409f31                                                 XREF[2]:     00409f0f(j), 00409f1f(j)
//                              aibldmod.cpp:773 (2)
//         00409f31     MOV        EAX,ESI
//                              aibldmod.cpp:777 (16)
//         00409f33     POP        EDI
//         00409f34     POP        ESI
//         00409f35     POP        EBP
//         00409f36     POP        EBX
//         00409f37     RET        0xc
//                               LAB_00409f3a                                                 XREF[2]:     00409ef2(j), 00409efe(j)
//         00409f3a     POP        EDI
//         00409f3b     POP        ESI
//         00409f3c     POP        EBP
//         00409f3d     XOR        EAX,EAX
//         00409f3f     POP        EBX
//         00409f40     RET        0xc
//         00409f43     ??         90h
//         00409f44     NOP
//         00409f45     NOP
//         00409f46     NOP
//         00409f47     NOP
//         00409f48     NOP
//         00409f49     NOP
//         00409f4a     NOP
//         00409f4b     NOP
//         00409f4c     NOP
//         00409f4d     NOP
//         00409f4e     NOP
//         00409f4f     NOP
    return 0;
}

BuildItem* BuildAIModule::specificBuildListItem(int param_1) {
    /* TODO: Stub */
//                              BuildItem * __thiscall specificBuildListItem(BuildAIModule * this, i
//              BuildItem *       EAX:4          <RETURN>
//              BuildAIModule *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00409f63(R)
//                               ?specificBuildListItem@BuildAIModule@@IAEPAVBuildItem@@H@Z   XREF[5]:     cancelBuildItem:004d54f6(c),
//                               BuildAIModule::specificBuildListItem                                      addTrainedUnit:004d5599(c),
//                                                                                                         cancelTrainUnit:004d5636(c),
//                                                                                                         addResearch:004d5699(c),
//                                                                                                         cancelResearch:004d5726(c)
//                              aibldmod.cpp:782 (2)
//         00409f50     PUSH       EBX
//         00409f51     PUSH       ESI
//                              aibldmod.cpp:785 (7)
//         00409f52     MOV        ESI,dword ptr [ECX + this+0x15c]
//         00409f58     PUSH       EDI
//                              aibldmod.cpp:786 (18)
//         00409f59     LEA        EDI,[ECX + this->buildList._padding_]
//         00409f5f     CMP        ESI,EDI
//         00409f61     JZ         LAB_00409f8d
//         00409f63     MOV        EBX,dword ptr [ESP + param_1]
//                               LAB_00409f67                                                 XREF[1]:     00409f7b(j)
//         00409f67     TEST       ESI,ESI
//         00409f69     JZ         LAB_00409f8d
//                              aibldmod.cpp:787 (11)
//         00409f6b     MOV        this,ESI
//         00409f6d     CALL       BaseItem::uniqueID                               int uniqueID(BaseItem * this)
//         00409f72     CMP        EAX,EBX
//         00409f74     JZ         LAB_00409f85
//                              aibldmod.cpp:789 (7)
//         00409f76     MOV        ESI,dword ptr [ESI + 0x6c]
//         00409f79     CMP        ESI,EDI
//         00409f7b     JNZ        LAB_00409f67
//                              aibldmod.cpp:791 (2)
//         00409f7d     XOR        EAX,EAX
//                              aibldmod.cpp:792 (6)
//         00409f7f     POP        EDI
//         00409f80     POP        ESI
//         00409f81     POP        EBX
//         00409f82     RET        0x4
//                               LAB_00409f85                                                 XREF[1]:     00409f74(j)
//                              aibldmod.cpp:788 (2)
//         00409f85     MOV        EAX,ESI
//                              aibldmod.cpp:792 (14)
//         00409f87     POP        EDI
//         00409f88     POP        ESI
//         00409f89     POP        EBX
//         00409f8a     RET        0x4
//                               LAB_00409f8d                                                 XREF[2]:     00409f61(j), 00409f69(j)
//         00409f8d     POP        EDI
//         00409f8e     POP        ESI
//         00409f8f     XOR        EAX,EAX
//         00409f91     POP        EBX
//         00409f92     RET        0x4
//         00409f95     ??         90h
//         00409f96     NOP
//         00409f97     NOP
//         00409f98     NOP
//         00409f99     NOP
//         00409f9a     NOP
//         00409f9b     NOP
//         00409f9c     NOP
//         00409f9d     NOP
//         00409f9e     NOP
//         00409f9f     NOP
    return 0;
}

