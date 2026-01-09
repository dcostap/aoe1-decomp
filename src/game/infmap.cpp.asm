#include "common.h"
#include "infmap.h"

InfluenceMap::InfluenceMap(int param_1, int param_2, uchar param_3) {
    /* TODO: Stub */
    //                              undefined __thiscall InfluenceMap(InfluenceMap * this, int param_1, 
    //              undefined         <UNASSIGNED>   <RETURN>
    //              InfluenceMap *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0044df88(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0044df80(R)  
    //              uchar             Stack[0xc]:1   param_3                   XREF[1]:     0044dfb4(R)  
    //                               ??0InfluenceMap@@QAE@HHE@Z                                   XREF[5]:     $E9:004d6ae1(c), $E14:004d6b2b(c), 
    //                               InfluenceMap::InfluenceMap                                                $E19:004d6b7b(c), 
    //                                                                                                         TribeInformationAIModule:004d6c9e(
    //                                                                                                         TribeInformationAIModule:004d713b(
    //                              infmap.cpp:26 (16)
    //         0044df80     MOV        EAX,dword ptr [ESP + param_2]
    //         0044df84     PUSH       EBX
    //         0044df85     PUSH       ESI
    //         0044df86     MOV        ESI,this
    //         0044df88     MOV        this,dword ptr [ESP + param_1]
    //         0044df8c     PUSH       EDI
    //         0044df8d     MOV        dword ptr [ESI + 0x8],EAX
    //                              infmap.cpp:27 (8)
    //         0044df90     IMUL       EAX,this
    //         0044df93     MOV        EBX,EAX
    //         0044df95     MOV        dword ptr [ESI + 0x4],this
    //                              infmap.cpp:28 (28)
    //         0044df98     PUSH       EBX
    //         0044df99     MOV        dword ptr [ESI + 0xc],0x0
    //         0044dfa0     MOV        dword ptr [ESI + 0x10],0x0
    //         0044dfa7     MOV        dword ptr [ESI],InfluenceMap::`vftable'          = 0044e030
    //         0044dfad     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0044dfb2     MOV        EDI,EAX
    //                              infmap.cpp:29 (43)
    //         0044dfb4     MOV        EAX,dword ptr [ESP + param_3]
    //         0044dfb8     AND        EAX,0xff
    //         0044dfbd     MOV        this,EBX
    //         0044dfbf     MOV        BL,AL
    //         0044dfc1     MOV        EDX,this
    //         0044dfc3     MOV        BH,BL
    //         0044dfc5     MOV        dword ptr [ESI + 0x14],EDI
    //         0044dfc8     MOV        EAX,EBX
    //         0044dfca     ADD        ESP,0x4
    //         0044dfcd     SHL        EAX,0x10
    //         0044dfd0     MOV        AX,BX
    //         0044dfd3     SHR        this,0x2
    //         0044dfd6     STOSD.REP  ES:EDI
    //         0044dfd8     MOV        this,EDX
    //         0044dfda     AND        this,0x3
    //         0044dfdd     STOSB.REP  ES:EDI
    //                              infmap.cpp:30 (18)
    //         0044dfdf     MOV        EAX,dword ptr [ESI + 0x8]
    //         0044dfe2     SHL        EAX,0x2
    //         0044dfe5     PUSH       EAX
    //         0044dfe6     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0044dfeb     ADD        ESP,0x4
    //         0044dfee     MOV        dword ptr [ESI + 0x18],EAX
    //                              infmap.cpp:31 (4)
    //         0044dff1     TEST       EAX,EAX
    //         0044dff3     JZ         LAB_0044e01a
    //                              infmap.cpp:32 (11)
    //         0044dff5     MOV        EDX,dword ptr [ESI + 0x8]
    //         0044dff8     XOR        EAX,EAX
    //         0044dffa     XOR        this,this
    //         0044dffc     TEST       EDX,EDX
    //         0044dffe     JLE        LAB_0044e01a
    //                               LAB_0044e000                                                 XREF[1]:     0044e018(j)  
    //                              infmap.cpp:33 (26)
    //         0044e000     MOV        EDI,dword ptr [ESI + 0x14]
    //         0044e003     MOV        EDX,this
    //         0044e005     ADD        EDX,EDI
    //         0044e007     MOV        EDI,dword ptr [ESI + 0x18]
    //         0044e00a     MOV        dword ptr [EDI + EAX*0x4],EDX
    //         0044e00d     MOV        EDI,dword ptr [ESI + 0x4]
    //         0044e010     MOV        EDX,dword ptr [ESI + 0x8]
    //         0044e013     INC        EAX
    //         0044e014     ADD        this,EDI
    //         0044e016     CMP        EAX,EDX
    //         0044e018     JL         LAB_0044e000
    //                               LAB_0044e01a                                                 XREF[2]:     0044dff3(j), 0044dffe(j)  
    //                              infmap.cpp:36 (8)
    //         0044e01a     MOV        EAX,ESI
    //         0044e01c     POP        EDI
    //         0044e01d     POP        ESI
    //         0044e01e     POP        EBX
    //         0044e01f     RET        0xc
    //         0044e022     ??         90h
    //         0044e023     NOP
    //         0044e024     NOP
    //         0044e025     NOP
    //         0044e026     NOP
    //         0044e027     NOP
    //         0044e028     NOP
    //         0044e029     NOP
    //         0044e02a     NOP
    //         0044e02b     NOP
    //         0044e02c     NOP
    //         0044e02d     NOP
    //         0044e02e     NOP
    //         0044e02f     NOP
}

InfluenceMap::InfluenceMap(int param_1) {
    /* TODO: Stub */
    //                              undefined __thiscall InfluenceMap(InfluenceMap * this, int param_1)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              InfluenceMap *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0044e06a(R)  
    //                               ??0InfluenceMap@@QAE@H@Z
    //                               InfluenceMap::InfluenceMap
    //                              infmap.cpp:45 (26)
    //         0044e050     PUSH       ESI
    //         0044e051     MOV        ESI,this
    //         0044e053     OR         EAX,0xffffffff
    //         0044e056     MOV        dword ptr [ESI + 0x4],EAX
    //         0044e059     MOV        dword ptr [ESI + 0x8],EAX
    //         0044e05c     XOR        EAX,EAX
    //         0044e05e     MOV        dword ptr [ESI],InfluenceMap::`vftable'          = 0044e030
    //         0044e064     MOV        dword ptr [ESI + 0xc],EAX
    //         0044e067     MOV        dword ptr [ESI + 0x10],EAX
    //                              infmap.cpp:46 (10)
    //         0044e06a     MOV        EAX,dword ptr [ESP + param_1]
    //         0044e06e     PUSH       EAX
    //         0044e06f     CALL       InfluenceMap::load                               void load(InfluenceMap * this, int param_1)
    //                              infmap.cpp:47 (6)
    //         0044e074     MOV        EAX,ESI
    //         0044e076     POP        ESI
    //         0044e077     RET        0x4
    //         0044e07a     ??         90h
    //         0044e07b     NOP
    //         0044e07c     NOP
    //         0044e07d     NOP
    //         0044e07e     NOP
    //         0044e07f     NOP
}

InfluenceMap::~InfluenceMap() {
    /* TODO: Stub */
    //                              void __thiscall ~InfluenceMap(InfluenceMap * this)
    //              void              <VOID>         <RETURN>
    //              InfluenceMap *    ECX:4 (auto)   this
    //                               ??1InfluenceMap@@UAE@XZ                                      XREF[5]:     `scalar_deleting_destructor':0044e
    //                               InfluenceMap::~InfluenceMap                                               $E10:004d6b05(c), 
    //                                                                                                         $E15:004d6b55(c), 
    //                                                                                                         $E20:004d6ba5(c), 
    //                                                                                                         ~TribeInformationAIModule:004d8159
    //                              infmap.cpp:52 (3)
    //         0044e080     PUSH       ESI
    //         0044e081     MOV        ESI,this
    //                              infmap.cpp:53 (13)
    //         0044e083     MOV        EAX,dword ptr [ESI + 0x14]
    //         0044e086     MOV        dword ptr [ESI],InfluenceMap::`vftable'          = 0044e030
    //         0044e08c     TEST       EAX,EAX
    //         0044e08e     JZ         LAB_0044e099
    //                              infmap.cpp:54 (9)
    //         0044e090     PUSH       EAX
    //         0044e091     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0044e096     ADD        ESP,0x4
    //                               LAB_0044e099                                                 XREF[1]:     0044e08e(j)  
    //                              infmap.cpp:55 (7)
    //         0044e099     MOV        ESI,dword ptr [ESI + 0x18]
    //         0044e09c     TEST       ESI,ESI
    //         0044e09e     JZ         LAB_0044e0a9
    //                              infmap.cpp:56 (9)
    //         0044e0a0     PUSH       ESI
    //         0044e0a1     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0044e0a6     ADD        ESP,0x4
    //                               LAB_0044e0a9                                                 XREF[1]:     0044e09e(j)  
    //                              infmap.cpp:57 (2)
    //         0044e0a9     POP        ESI
    //         0044e0aa     RET
    //         0044e0ab     ??         90h
    //         0044e0ac     NOP
    //         0044e0ad     NOP
    //         0044e0ae     NOP
    //         0044e0af     NOP
}

int InfluenceMap::initialize(uchar param_1) {
    /* TODO: Stub */
    //                              int __thiscall initialize(InfluenceMap * this, uchar param_1)
    //              int               EAX:4          <RETURN>
    //              InfluenceMap *    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     0044e0b0(R)  
    //                               ?initialize@InfluenceMap@@QAEHE@Z                            XREF[3]:     setupInfluenceMap:004deea0(c), 
    //                               InfluenceMap::initialize                                                  setupLOSMap:004e21f3(c), 
    //                                                                                                         setupAttackMap:004e22fb(c)  
    //                              infmap.cpp:62 (49)
    //         0044e0b0     MOV        EAX,dword ptr [ESP + param_1]
    //         0044e0b4     MOV        EDX,this
    //         0044e0b6     AND        EAX,0xff
    //         0044e0bb     PUSH       EBX
    //         0044e0bc     MOV        this,dword ptr [EDX + 0x8]
    //         0044e0bf     MOV        BL,AL
    //         0044e0c1     IMUL       this,dword ptr [EDX + 0x4]
    //         0044e0c5     MOV        BH,BL
    //         0044e0c7     PUSH       EDI
    //         0044e0c8     MOV        EDI,dword ptr [EDX + 0x14]
    //         0044e0cb     MOV        EAX,EBX
    //         0044e0cd     MOV        EDX,this
    //         0044e0cf     SHL        EAX,0x10
    //         0044e0d2     MOV        AX,BX
    //         0044e0d5     SHR        this,0x2
    //         0044e0d8     STOSD.REP  ES:EDI
    //         0044e0da     MOV        this,EDX
    //         0044e0dc     AND        this,0x3
    //         0044e0df     STOSB.REP  ES:EDI
    //                              infmap.cpp:66 (10)
    //         0044e0e1     POP        EDI
    //         0044e0e2     MOV        EAX,0x1
    //         0044e0e7     POP        EBX
    //         0044e0e8     RET        0x4
    //         0044e0eb     ??         90h
    //         0044e0ec     NOP
    //         0044e0ed     NOP
    //         0044e0ee     NOP
    //         0044e0ef     NOP
    return 0;
}

void InfluenceMap::save(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall save(InfluenceMap * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              InfluenceMap *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[5]:     0044e0f1(R), 0044e149(W), 0044e15f(R), 0044e17c(R), 
    //                                                                                     0044e186(W)  
    //                               ?save@InfluenceMap@@QAEXH@Z                                  XREF[1]:     save:004d8ac5(c)  
    //                               InfluenceMap::save
    //                              infmap.cpp:71 (1)
    //         0044e0f0     PUSH       EBX
    //                              infmap.cpp:73 (24)
    //         0044e0f1     MOV        EBX,dword ptr [ESP + param_1]
    //         0044e0f5     PUSH       EBP
    //         0044e0f6     PUSH       ESI
    //         0044e0f7     PUSH       EDI
    //         0044e0f8     MOV        EDI,this
    //         0044e0fa     PUSH       0x4
    //         0044e0fc     LEA        EBP,[EDI + 0x4]
    //         0044e0ff     PUSH       EBP
    //         0044e100     PUSH       EBX
    //         0044e101     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0044e106     ADD        ESP,0xc
    //                              infmap.cpp:74 (15)
    //         0044e109     LEA        ESI,[EDI + 0x8]
    //         0044e10c     PUSH       0x4
    //         0044e10e     PUSH       ESI
    //         0044e10f     PUSH       EBX
    //         0044e110     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0044e115     ADD        ESP,0xc
    //                              infmap.cpp:75 (15)
    //         0044e118     LEA        EAX,[EDI + 0xc]
    //         0044e11b     PUSH       0x4
    //         0044e11d     PUSH       EAX
    //         0044e11e     PUSH       EBX
    //         0044e11f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0044e124     ADD        ESP,0xc
    //                              infmap.cpp:76 (15)
    //         0044e127     LEA        this,[EDI + 0x10]
    //         0044e12a     PUSH       0x4
    //         0044e12c     PUSH       this
    //         0044e12d     PUSH       EBX
    //         0044e12e     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0044e133     ADD        ESP,0xc
    //                              infmap.cpp:77 (12)
    //         0044e136     LEA        EDX,[EDI + 0x24]
    //         0044e139     PUSH       0x1
    //         0044e13b     PUSH       EDX
    //         0044e13c     PUSH       EBX
    //         0044e13d     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              infmap.cpp:78 (17)
    //         0044e142     MOV        EAX,dword ptr [ESI]
    //         0044e144     ADD        ESP,0xc
    //         0044e147     TEST       EAX,EAX
    //         0044e149     MOV        dword ptr [ESP + param_1],0x0
    //         0044e151     JLE        LAB_0044e18c
    //                               LAB_0044e153                                                 XREF[1]:     0044e18a(j)  
    //                              infmap.cpp:79 (9)
    //         0044e153     MOV        EAX,dword ptr [EBP]
    //         0044e156     XOR        ESI,ESI
    //         0044e158     TEST       EAX,EAX
    //         0044e15a     JLE        LAB_0044e17c
    //                               LAB_0044e15c                                                 XREF[1]:     0044e17a(j)  
    //                              infmap.cpp:80 (32)
    //         0044e15c     MOV        EAX,dword ptr [EDI + 0x18]
    //         0044e15f     MOV        this,dword ptr [ESP + param_1]
    //         0044e163     PUSH       0x1
    //         0044e165     MOV        EDX,dword ptr [EAX + this->_padding_*0x4]
    //         0044e168     ADD        EDX,ESI
    //         0044e16a     PUSH       EDX
    //         0044e16b     PUSH       EBX
    //         0044e16c     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0044e171     MOV        EAX,dword ptr [EBP]
    //         0044e174     ADD        ESP,0xc
    //         0044e177     INC        ESI
    //         0044e178     CMP        ESI,EAX
    //         0044e17a     JL         LAB_0044e15c
    //                               LAB_0044e17c                                                 XREF[1]:     0044e15a(j)  
    //                              infmap.cpp:78 (16)
    //         0044e17c     MOV        EAX,dword ptr [ESP + param_1]
    //         0044e180     MOV        this,dword ptr [EDI + 0x8]
    //         0044e183     INC        EAX
    //         0044e184     CMP        EAX,this
    //         0044e186     MOV        dword ptr [ESP + param_1],EAX
    //         0044e18a     JL         LAB_0044e153
    //                               LAB_0044e18c                                                 XREF[1]:     0044e151(j)  
    //                              infmap.cpp:81 (7)
    //         0044e18c     POP        EDI
    //         0044e18d     POP        ESI
    //         0044e18e     POP        EBP
    //         0044e18f     POP        EBX
    //         0044e190     RET        0x4
    //         0044e193     ??         90h
    //         0044e194     NOP
    //         0044e195     NOP
    //         0044e196     NOP
    //         0044e197     NOP
    //         0044e198     NOP
    //         0044e199     NOP
    //         0044e19a     NOP
    //         0044e19b     NOP
    //         0044e19c     NOP
    //         0044e19d     NOP
    //         0044e19e     NOP
    //         0044e19f     NOP
    return;
}

void InfluenceMap::load(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall load(InfluenceMap * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              InfluenceMap *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[3]:     0044e1a2(R), 0044e20d(*), 0044e228(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     0044e1fa(W), 0044e21d(R), 0044e237(R), 0044e241(W)  
    //              int               Stack[-0x8]:4  j
    //                               ?load@InfluenceMap@@QAEXH@Z                                  XREF[2]:     InfluenceMap:0044e06f(c), 
    //                               InfluenceMap::load                                                        TribeInformationAIModule:004d7a1b(
    //                              infmap.cpp:86 (2)
    //         0044e1a0     PUSH       this
    //         0044e1a1     PUSH       EBX
    //                              infmap.cpp:88 (24)
    //         0044e1a2     MOV        EBX,dword ptr [ESP + param_1]
    //         0044e1a6     PUSH       EBP
    //         0044e1a7     PUSH       ESI
    //         0044e1a8     PUSH       EDI
    //         0044e1a9     MOV        EDI,this
    //         0044e1ab     PUSH       0x4
    //         0044e1ad     LEA        EBP,[EDI + 0x4]
    //         0044e1b0     PUSH       EBP
    //         0044e1b1     PUSH       EBX
    //         0044e1b2     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0044e1b7     ADD        ESP,0xc
    //                              infmap.cpp:89 (15)
    //         0044e1ba     LEA        ESI,[EDI + 0x8]
    //         0044e1bd     PUSH       0x4
    //         0044e1bf     PUSH       ESI
    //         0044e1c0     PUSH       EBX
    //         0044e1c1     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0044e1c6     ADD        ESP,0xc
    //                              infmap.cpp:90 (15)
    //         0044e1c9     LEA        EAX,[EDI + 0xc]
    //         0044e1cc     PUSH       0x4
    //         0044e1ce     PUSH       EAX
    //         0044e1cf     PUSH       EBX
    //         0044e1d0     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0044e1d5     ADD        ESP,0xc
    //                              infmap.cpp:91 (15)
    //         0044e1d8     LEA        this,[EDI + 0x10]
    //         0044e1db     PUSH       0x4
    //         0044e1dd     PUSH       this
    //         0044e1de     PUSH       EBX
    //         0044e1df     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0044e1e4     ADD        ESP,0xc
    //                              infmap.cpp:92 (12)
    //         0044e1e7     LEA        EDX,[EDI + 0x24]
    //         0044e1ea     PUSH       0x1
    //         0044e1ec     PUSH       EDX
    //         0044e1ed     PUSH       EBX
    //         0044e1ee     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              infmap.cpp:94 (17)
    //         0044e1f3     MOV        EAX,dword ptr [ESI]
    //         0044e1f5     ADD        ESP,0xc
    //         0044e1f8     TEST       EAX,EAX
    //         0044e1fa     MOV        dword ptr [ESP + local_4],0x0
    //         0044e202     JLE        LAB_0044e247
    //                               LAB_0044e204                                                 XREF[1]:     0044e245(j)  
    //                              infmap.cpp:95 (9)
    //         0044e204     MOV        EAX,dword ptr [EBP]
    //         0044e207     XOR        ESI,ESI
    //         0044e209     TEST       EAX,EAX
    //         0044e20b     JLE        LAB_0044e237
    //                               LAB_0044e20d                                                 XREF[1]:     0044e235(j)  
    //                              infmap.cpp:96 (13)
    //         0044e20d     LEA        EAX=>param_1,[ESP + 0x18]
    //         0044e211     PUSH       0x1
    //         0044e213     PUSH       EAX
    //         0044e214     PUSH       EBX
    //         0044e215     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              infmap.cpp:97 (29)
    //         0044e21a     MOV        this,dword ptr [EDI + 0x18]
    //         0044e21d     MOV        EDX,dword ptr [ESP + local_4]
    //         0044e221     ADD        ESP,0xc
    //         0044e224     INC        ESI
    //         0044e225     MOV        EAX,dword ptr [this->_padding_ + EDX*0x4]
    //         0044e228     MOV        this,byte ptr [ESP + param_1]
    //         0044e22c     MOV        byte ptr [EAX + ESI*0x1 + -0x1],this
    //         0044e230     MOV        EAX,dword ptr [EBP]
    //         0044e233     CMP        ESI,EAX
    //         0044e235     JL         LAB_0044e20d
    //                               LAB_0044e237                                                 XREF[1]:     0044e20b(j)  
    //                              infmap.cpp:94 (16)
    //         0044e237     MOV        EAX,dword ptr [ESP + local_4]
    //         0044e23b     MOV        this,dword ptr [EDI + 0x8]
    //         0044e23e     INC        EAX
    //         0044e23f     CMP        EAX,this
    //         0044e241     MOV        dword ptr [ESP + local_4],EAX
    //         0044e245     JL         LAB_0044e204
    //                               LAB_0044e247                                                 XREF[1]:     0044e202(j)  
    //                              infmap.cpp:100 (8)
    //         0044e247     POP        EDI
    //         0044e248     POP        ESI
    //         0044e249     POP        EBP
    //         0044e24a     POP        EBX
    //         0044e24b     POP        this
    //         0044e24c     RET        0x4
    //         0044e24f     ??         90h
    return;
}

void InfluenceMap::printToFile(char* param_1) {
    /* TODO: Stub */
    //                              void __thiscall printToFile(InfluenceMap * this, char * param_1)
    //              void              <VOID>         <RETURN>
    //              InfluenceMap *    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[4]:     0044e253(R), 0044e36c(W), 0044e3bd(R), 0044e3f7(W)  
    //                               ?printToFile@InfluenceMap@@QAEXPAD@Z
    //                               InfluenceMap::printToFile
    //                              infmap.cpp:105 (3)
    //         0044e250     PUSH       EBX
    //         0044e251     PUSH       ESI
    //         0044e252     PUSH       EDI
    //                              infmap.cpp:106 (14)
    //         0044e253     MOV        EDI,dword ptr [ESP + param_1]
    //         0044e257     TEST       EDI,EDI
    //         0044e259     MOV        EBX,this
    //         0044e25b     JZ         LAB_0044e4ad
    //                              infmap.cpp:108 (16)
    //         0044e261     PUSH       s_wa                                             = "wa"
    //         0044e266     PUSH       EDI
    //         0044e267     CALL       fopen                                            undefined fopen()
    //         0044e26c     MOV        ESI,EAX
    //         0044e26e     ADD        ESP,0x8
    //                              infmap.cpp:109 (9)
    //         0044e271     TEST       ESI,ESI
    //         0044e273     JZ         LAB_0044e4ad
    //         0044e279     PUSH       EBP
    //                              infmap.cpp:113 (12)
    //         0044e27a     PUSH       EDI
    //         0044e27b     PUSH       s_FILENAME:_%s_                                  = "FILENAME: %s\n"
    //         0044e280     PUSH       ESI
    //         0044e281     CALL       fprintf                                          undefined fprintf()
    //                              infmap.cpp:114 (22)
    //         0044e286     MOV        EAX,dword ptr [EBX + 0x8]
    //         0044e289     MOV        this,dword ptr [EBX + 0x4]
    //         0044e28c     ADD        ESP,0xc
    //         0044e28f     PUSH       EAX
    //         0044e290     PUSH       this
    //         0044e291     PUSH       s___Dimensions:_%d_X_%d_                         = "  Dimensions: %d X %d\n"
    //         0044e296     PUSH       ESI
    //         0044e297     CALL       fprintf                                          undefined fprintf()
    //                              infmap.cpp:116 (25)
    //         0044e29c     MOV        EDX,dword ptr [EBX + 0x10]
    //         0044e29f     MOV        EAX,dword ptr [EBX + 0xc]
    //         0044e2a2     ADD        ESP,0x10
    //         0044e2a5     PUSH       EDX
    //         0044e2a6     PUSH       EAX
    //         0044e2a7     PUSH       s___Reference_Point:_(%d,_%d)_                   = "  Reference Point: (%d, %d)\n"
    //         0044e2ac     PUSH       ESI
    //         0044e2ad     CALL       fprintf                                          undefined fprintf()
    //         0044e2b2     ADD        ESP,0x10
    //                              infmap.cpp:117 (14)
    //         0044e2b5     PUSH       s__                                              = 0Ah
    //         0044e2ba     PUSH       ESI
    //         0044e2bb     CALL       fprintf                                          undefined fprintf()
    //         0044e2c0     ADD        ESP,0x8
    //                              infmap.cpp:120 (11)
    //         0044e2c3     PUSH       s_______                                         = "      "
    //         0044e2c8     PUSH       ESI
    //         0044e2c9     CALL       fprintf                                          undefined fprintf()
    //                              infmap.cpp:121 (12)
    //         0044e2ce     MOV        EAX,dword ptr [EBX + 0x4]
    //         0044e2d1     ADD        ESP,0x8
    //         0044e2d4     XOR        EDI,EDI
    //         0044e2d6     TEST       EAX,EAX
    //         0044e2d8     JLE        LAB_0044e306
    //                               LAB_0044e2da                                                 XREF[1]:     0044e304(j)  
    //                              infmap.cpp:122 (10)
    //         0044e2da     MOV        EAX,EDI
    //         0044e2dc     MOV        this,0x5
    //         0044e2e1     CDQ
    //         0044e2e2     IDIV       this
    //                              infmap.cpp:123 (10)
    //         0044e2e4     PUSH       EDI
    //         0044e2e5     TEST       EDX,EDX
    //         0044e2e7     JNZ        LAB_0044e2f0
    //         0044e2e9     PUSH       s__%03d_                                         = " %03d "
    //                              infmap.cpp:124 (2)
    //         0044e2ee     JMP        LAB_0044e2f5
    //                               LAB_0044e2f0                                                 XREF[1]:     0044e2e7(j)  
    //                              infmap.cpp:125 (22)
    //         0044e2f0     PUSH       s_%03d_                                          = "%03d "
    //                               LAB_0044e2f5                                                 XREF[1]:     0044e2ee(j)  
    //         0044e2f5     PUSH       ESI
    //         0044e2f6     CALL       fprintf                                          undefined fprintf()
    //         0044e2fb     MOV        EAX,dword ptr [EBX + 0x4]
    //         0044e2fe     ADD        ESP,0xc
    //         0044e301     INC        EDI
    //         0044e302     CMP        EDI,EAX
    //         0044e304     JL         LAB_0044e2da
    //                               LAB_0044e306                                                 XREF[1]:     0044e2d8(j)  
    //                              infmap.cpp:127 (14)
    //         0044e306     PUSH       s__                                              = 0Ah
    //         0044e30b     PUSH       ESI
    //         0044e30c     CALL       fprintf                                          undefined fprintf()
    //         0044e311     ADD        ESP,0x8
    //                              infmap.cpp:128 (11)
    //         0044e314     PUSH       s_______                                         = "      "
    //         0044e319     PUSH       ESI
    //         0044e31a     CALL       fprintf                                          undefined fprintf()
    //                              infmap.cpp:129 (12)
    //         0044e31f     MOV        EAX,dword ptr [EBX + 0x4]
    //         0044e322     ADD        ESP,0x8
    //         0044e325     XOR        EDI,EDI
    //         0044e327     TEST       EAX,EAX
    //         0044e329     JLE        LAB_0044e357
    //                               LAB_0044e32b                                                 XREF[1]:     0044e355(j)  
    //                              infmap.cpp:130 (10)
    //         0044e32b     MOV        EAX,EDI
    //         0044e32d     MOV        this,0x5
    //         0044e332     CDQ
    //         0044e333     IDIV       this
    //                              infmap.cpp:131 (10)
    //         0044e335     PUSH       EDI
    //         0044e336     TEST       EDX,EDX
    //         0044e338     JNZ        LAB_0044e341
    //         0044e33a     PUSH       s__---_                                          = " --- "
    //                              infmap.cpp:132 (2)
    //         0044e33f     JMP        LAB_0044e346
    //                               LAB_0044e341                                                 XREF[1]:     0044e338(j)  
    //                              infmap.cpp:133 (22)
    //         0044e341     PUSH       s_---_                                           = "--- "
    //                               LAB_0044e346                                                 XREF[1]:     0044e33f(j)  
    //         0044e346     PUSH       ESI
    //         0044e347     CALL       fprintf                                          undefined fprintf()
    //         0044e34c     MOV        EAX,dword ptr [EBX + 0x4]
    //         0044e34f     ADD        ESP,0xc
    //         0044e352     INC        EDI
    //         0044e353     CMP        EDI,EAX
    //         0044e355     JL         LAB_0044e32b
    //                               LAB_0044e357                                                 XREF[1]:     0044e329(j)  
    //                              infmap.cpp:135 (11)
    //         0044e357     PUSH       s__                                              = 0Ah
    //         0044e35c     PUSH       ESI
    //         0044e35d     CALL       fprintf                                          undefined fprintf()
    //                              infmap.cpp:138 (20)
    //         0044e362     MOV        EAX,dword ptr [EBX + 0x8]
    //         0044e365     ADD        ESP,0x8
    //         0044e368     XOR        EBP,EBP
    //         0044e36a     TEST       EAX,EAX
    //         0044e36c     MOV        dword ptr [ESP + param_1],EBP
    //         0044e370     JLE        LAB_0044e401
    //                               LAB_0044e376                                                 XREF[1]:     0044e3fb(j)  
    //                              infmap.cpp:139 (12)
    //         0044e376     PUSH       EBP
    //         0044e377     PUSH       s_R%03d:_                                        = "R%03d: "
    //         0044e37c     PUSH       ESI
    //         0044e37d     CALL       fprintf                                          undefined fprintf()
    //                              infmap.cpp:140 (12)
    //         0044e382     MOV        EAX,dword ptr [EBX + 0x4]
    //         0044e385     ADD        ESP,0xc
    //         0044e388     XOR        EDI,EDI
    //         0044e38a     TEST       EAX,EAX
    //         0044e38c     JLE        LAB_0044e3c9
    //                               LAB_0044e38e                                                 XREF[1]:     0044e3c7(j)  
    //                              infmap.cpp:141 (8)
    //         0044e38e     MOV        EDX,dword ptr [EBX + 0x18]
    //         0044e391     XOR        this,this
    //         0044e393     MOV        EAX,dword ptr [EDX + EBP*0x4]
    //                              infmap.cpp:142 (13)
    //         0044e396     MOV        EBP,0x5
    //         0044e39b     MOV        this,byte ptr [EAX + EDI*0x1]
    //         0044e39e     MOV        EAX,EDI
    //         0044e3a0     CDQ
    //         0044e3a1     IDIV       EBP
    //                              infmap.cpp:143 (10)
    //         0044e3a3     PUSH       this
    //         0044e3a4     TEST       EDX,EDX
    //         0044e3a6     JNZ        LAB_0044e3af
    //         0044e3a8     PUSH       s__%03d_                                         = " %03d "
    //                              infmap.cpp:144 (2)
    //         0044e3ad     JMP        LAB_0044e3b4
    //                               LAB_0044e3af                                                 XREF[1]:     0044e3a6(j)  
    //                              infmap.cpp:145 (26)
    //         0044e3af     PUSH       s_%03d_                                          = "%03d "
    //                               LAB_0044e3b4                                                 XREF[1]:     0044e3ad(j)  
    //         0044e3b4     PUSH       ESI
    //         0044e3b5     CALL       fprintf                                          undefined fprintf()
    //         0044e3ba     MOV        EAX,dword ptr [EBX + 0x4]
    //         0044e3bd     MOV        EBP,dword ptr [ESP + param_1]
    //         0044e3c1     ADD        ESP,0xc
    //         0044e3c4     INC        EDI
    //         0044e3c5     CMP        EDI,EAX
    //         0044e3c7     JL         LAB_0044e38e
    //                               LAB_0044e3c9                                                 XREF[1]:     0044e38c(j)  
    //                              infmap.cpp:138 (3)
    //         0044e3c9     LEA        EDI,[EBP + 0x1]
    //                              infmap.cpp:147 (7)
    //         0044e3cc     MOV        this,0x5
    //         0044e3d1     MOV        EAX,EDI
    //                              infmap.cpp:148 (13)
    //         0044e3d3     PUSH       EBP
    //         0044e3d4     CDQ
    //         0044e3d5     IDIV       this
    //         0044e3d7     TEST       EDX,EDX
    //         0044e3d9     JNZ        LAB_0044e3e2
    //         0044e3db     PUSH       s_:R%03d__                                       = ":R%03d\n\n"
    //                              infmap.cpp:149 (2)
    //         0044e3e0     JMP        LAB_0044e3e7
    //                               LAB_0044e3e2                                                 XREF[1]:     0044e3d9(j)  
    //                              infmap.cpp:150 (31)
    //         0044e3e2     PUSH       s_:R%03d_                                        = ":R%03d\n"
    //                               LAB_0044e3e7                                                 XREF[1]:     0044e3e0(j)  
    //         0044e3e7     PUSH       ESI
    //         0044e3e8     CALL       fprintf                                          undefined fprintf()
    //         0044e3ed     MOV        EAX,dword ptr [EBX + 0x8]
    //         0044e3f0     MOV        EBP,EDI
    //         0044e3f2     ADD        ESP,0xc
    //         0044e3f5     CMP        EBP,EAX
    //         0044e3f7     MOV        dword ptr [ESP + param_1],EBP
    //         0044e3fb     JL         LAB_0044e376
    //                               LAB_0044e401                                                 XREF[1]:     0044e370(j)  
    //                              infmap.cpp:154 (11)
    //         0044e401     PUSH       s_______                                         = "      "
    //         0044e406     PUSH       ESI
    //         0044e407     CALL       fprintf                                          undefined fprintf()
    //                              infmap.cpp:155 (12)
    //         0044e40c     MOV        EAX,dword ptr [EBX + 0x4]
    //         0044e40f     ADD        ESP,0x8
    //         0044e412     XOR        EDI,EDI
    //         0044e414     TEST       EAX,EAX
    //         0044e416     JLE        LAB_0044e444
    //                               LAB_0044e418                                                 XREF[1]:     0044e442(j)  
    //                              infmap.cpp:156 (10)
    //         0044e418     MOV        EAX,EDI
    //         0044e41a     MOV        this,0x5
    //         0044e41f     CDQ
    //         0044e420     IDIV       this
    //                              infmap.cpp:157 (10)
    //         0044e422     PUSH       EDI
    //         0044e423     TEST       EDX,EDX
    //         0044e425     JNZ        LAB_0044e42e
    //         0044e427     PUSH       s__---_                                          = " --- "
    //                              infmap.cpp:158 (2)
    //         0044e42c     JMP        LAB_0044e433
    //                               LAB_0044e42e                                                 XREF[1]:     0044e425(j)  
    //                              infmap.cpp:159 (22)
    //         0044e42e     PUSH       s_---_                                           = "--- "
    //                               LAB_0044e433                                                 XREF[1]:     0044e42c(j)  
    //         0044e433     PUSH       ESI
    //         0044e434     CALL       fprintf                                          undefined fprintf()
    //         0044e439     MOV        EAX,dword ptr [EBX + 0x4]
    //         0044e43c     ADD        ESP,0xc
    //         0044e43f     INC        EDI
    //         0044e440     CMP        EDI,EAX
    //         0044e442     JL         LAB_0044e418
    //                               LAB_0044e444                                                 XREF[1]:     0044e416(j)  
    //                              infmap.cpp:161 (14)
    //         0044e444     PUSH       s__                                              = 0Ah
    //         0044e449     PUSH       ESI
    //         0044e44a     CALL       fprintf                                          undefined fprintf()
    //         0044e44f     ADD        ESP,0x8
    //                              infmap.cpp:162 (11)
    //         0044e452     PUSH       s_______                                         = "      "
    //         0044e457     PUSH       ESI
    //         0044e458     CALL       fprintf                                          undefined fprintf()
    //                              infmap.cpp:163 (12)
    //         0044e45d     MOV        EAX,dword ptr [EBX + 0x4]
    //         0044e460     ADD        ESP,0x8
    //         0044e463     XOR        EDI,EDI
    //         0044e465     TEST       EAX,EAX
    //         0044e467     JLE        LAB_0044e495
    //                               LAB_0044e469                                                 XREF[1]:     0044e493(j)  
    //                              infmap.cpp:164 (10)
    //         0044e469     MOV        EAX,EDI
    //         0044e46b     MOV        this,0x5
    //         0044e470     CDQ
    //         0044e471     IDIV       this
    //                              infmap.cpp:165 (10)
    //         0044e473     PUSH       EDI
    //         0044e474     TEST       EDX,EDX
    //         0044e476     JNZ        LAB_0044e47f
    //         0044e478     PUSH       s__%03d_                                         = " %03d "
    //                              infmap.cpp:166 (2)
    //         0044e47d     JMP        LAB_0044e484
    //                               LAB_0044e47f                                                 XREF[1]:     0044e476(j)  
    //                              infmap.cpp:167 (22)
    //         0044e47f     PUSH       s_%03d_                                          = "%03d "
    //                               LAB_0044e484                                                 XREF[1]:     0044e47d(j)  
    //         0044e484     PUSH       ESI
    //         0044e485     CALL       fprintf                                          undefined fprintf()
    //         0044e48a     MOV        EAX,dword ptr [EBX + 0x4]
    //         0044e48d     ADD        ESP,0xc
    //         0044e490     INC        EDI
    //         0044e491     CMP        EDI,EAX
    //         0044e493     JL         LAB_0044e469
    //                               LAB_0044e495                                                 XREF[1]:     0044e467(j)  
    //                              infmap.cpp:169 (14)
    //         0044e495     PUSH       s__                                              = 0Ah
    //         0044e49a     PUSH       ESI
    //         0044e49b     CALL       fprintf                                          undefined fprintf()
    //         0044e4a0     ADD        ESP,0x8
    //                              infmap.cpp:172 (10)
    //         0044e4a3     PUSH       ESI
    //         0044e4a4     CALL       fclose                                           undefined fclose()
    //         0044e4a9     ADD        ESP,0x4
    //         0044e4ac     POP        EBP
    //                               LAB_0044e4ad                                                 XREF[2]:     0044e25b(j), 0044e273(j)  
    //                              infmap.cpp:173 (6)
    //         0044e4ad     POP        EDI
    //         0044e4ae     POP        ESI
    //         0044e4af     POP        EBX
    //         0044e4b0     RET        0x4
    //         0044e4b3     ??         90h
    //         0044e4b4     NOP
    //         0044e4b5     NOP
    //         0044e4b6     NOP
    //         0044e4b7     NOP
    //         0044e4b8     NOP
    //         0044e4b9     NOP
    //         0044e4ba     NOP
    //         0044e4bb     NOP
    //         0044e4bc     NOP
    //         0044e4bd     NOP
    //         0044e4be     NOP
    //         0044e4bf     NOP
    return;
}

void InfluenceMap::setReferencePoint(int param_1, int param_2) {
    /* TODO: Stub */
    //                              void __thiscall setReferencePoint(InfluenceMap * this, int param_1, 
    //              void              <VOID>         <RETURN>
    //              InfluenceMap *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0044e4c0(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0044e4c4(R)  
    //                               ?setReferencePoint@InfluenceMap@@QAEXHH@Z                    XREF[2]:     setupLOSMap:004e2207(c), 
    //                               InfluenceMap::setReferencePoint                                           setupAttackMap:004e230f(c)  
    //                              infmap.cpp:178 (4)
    //         0044e4c0     MOV        EAX,dword ptr [ESP + param_1]
    //                              infmap.cpp:180 (10)
    //         0044e4c4     MOV        EDX,dword ptr [ESP + param_2]
    //         0044e4c8     MOV        dword ptr [ECX + this->xReferencePointValue],EAX
    //         0044e4cb     MOV        dword ptr [ECX + this->yReferencePointValue],EDX
    //                              infmap.cpp:181 (3)
    //         0044e4ce     RET        0x8
    //         0044e4d1     ??         90h
    //         0044e4d2     NOP
    //         0044e4d3     NOP
    //         0044e4d4     NOP
    //         0044e4d5     NOP
    //         0044e4d6     NOP
    //         0044e4d7     NOP
    //         0044e4d8     NOP
    //         0044e4d9     NOP
    //         0044e4da     NOP
    //         0044e4db     NOP
    //         0044e4dc     NOP
    //         0044e4dd     NOP
    //         0044e4de     NOP
    //         0044e4df     NOP
    return;
}

int InfluenceMap::lookupValue(int param_1, int param_2) {
    /* TODO: Stub */
    //                              int __thiscall lookupValue(InfluenceMap * this, int param_1, int par
    //              int               EAX:4          <RETURN>
    //              InfluenceMap *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0044e4f4(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0044e4e0(R)  
    //                               ?lookupValue@InfluenceMap@@QAEHHH@Z                          XREF[7]:     blotExploredMap:004d8ce3(c), 
    //                               InfluenceMap::lookupValue                                                 closestUnexploredTile:004d8e8c(c), 
    //                                                                                                         tileUncovered:004d91c8(c), 
    //                                                                                                         influencePlaceStructure:004dbc48(c
    //                                                                                                         findGatherPosition:004dedf4(c), 
    //                                                                                                         findStagingPoint:004e210b(c), 
    //                                                                                                         findStagingPoint:004e213b(c)  
    //                              infmap.cpp:186 (31)
    //         0044e4e0     MOV        EAX,dword ptr [ESP + param_2]
    //         0044e4e4     MOV        EDX,dword ptr [ECX + this->yReferencePointValue]
    //         0044e4e7     SUB        EAX,EDX
    //         0044e4e9     MOV        EDX,dword ptr [ECX + this->rowValue]
    //         0044e4ec     MOV        EAX,dword ptr [EDX + EAX*0x4]
    //         0044e4ef     MOV        EDX,dword ptr [ECX + this->xReferencePointValue]
    //         0044e4f2     SUB        EAX,EDX
    //         0044e4f4     MOV        EDX,dword ptr [ESP + param_1]
    //         0044e4f8     XOR        this,this
    //         0044e4fa     MOV        this,byte ptr [EAX + EDX*0x1]
    //         0044e4fd     MOV        EAX,this
    //                              infmap.cpp:188 (3)
    //         0044e4ff     RET        0x8
    //         0044e502     ??         90h
    //         0044e503     NOP
    //         0044e504     NOP
    //         0044e505     NOP
    //         0044e506     NOP
    //         0044e507     NOP
    //         0044e508     NOP
    //         0044e509     NOP
    //         0044e50a     NOP
    //         0044e50b     NOP
    //         0044e50c     NOP
    //         0044e50d     NOP
    //         0044e50e     NOP
    //         0044e50f     NOP
    return 0;
}

int InfluenceMap::setValue(int param_1, int param_2, uchar param_3) {
    /* TODO: Stub */
    //                              int __thiscall setValue(InfluenceMap * this, int param_1, int param_
    //              int               EAX:4          <RETURN>
    //              InfluenceMap *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0044e510(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0044e51d(R)  
    //              uchar             Stack[0xc]:1   param_3                   XREF[1]:     0044e53b(R)  
    //                               ?setValue@InfluenceMap@@QAEHHHE@Z                            XREF[11]:    update:004d8401(c), 
    //                               InfluenceMap::setValue                                                    blotExploredMap:004d8cf3(c), 
    //                                                                                                         closestUnexploredTile:004d8f92(c), 
    //                                                                                                         closestUnexploredTile:004d90c9(c), 
    //                                                                                                         setTileExplored:004d921a(c), 
    //                                                                                                         setupInfluenceMap:004df0b6(c), 
    //                                                                                                         setupInfluenceMap:004dfac7(c), 
    //                                                                                                         setupInfluenceMap:004dfcba(c), 
    //                                                                                                         unexploredPlayerLocation:004e18e3(
    //                                                                                                         unexploredPlayerLocation:004e1903(
    //                                                                                                         lookAtMap:004e40e8(c)  
    //                              infmap.cpp:203 (8)
    //         0044e510     MOV        EAX,dword ptr [ESP + param_1]
    //         0044e514     MOV        EDX,dword ptr [ECX + this->xReferencePointValue]
    //         0044e517     PUSH       ESI
    //                              infmap.cpp:207 (11)
    //         0044e518     MOV        ESI,dword ptr [ECX + this->yReferencePointValue]
    //         0044e51b     SUB        EAX,EDX
    //         0044e51d     MOV        EDX,dword ptr [ESP + param_2]
    //         0044e521     SUB        EDX,ESI
    //                              infmap.cpp:209 (18)
    //         0044e523     TEST       EAX,EAX
    //         0044e525     JL         LAB_0044e54b
    //         0044e527     TEST       EDX,EDX
    //         0044e529     JL         LAB_0044e54b
    //         0044e52b     CMP        EAX,dword ptr [ECX + this->xSizeValue]
    //         0044e52e     JGE        LAB_0044e54b
    //         0044e530     CMP        EDX,dword ptr [ECX + this->ySizeValue]
    //         0044e533     JGE        LAB_0044e54b
    //                              infmap.cpp:211 (13)
    //         0044e535     MOV        this,dword ptr [ECX + this->rowValue]
    //         0044e538     MOV        EDX,dword ptr [this->_padding_ + EDX*0x4]
    //         0044e53b     MOV        this,byte ptr [ESP + param_3]
    //         0044e53f     MOV        byte ptr [EDX + EAX*0x1],this
    //                              infmap.cpp:212 (5)
    //         0044e542     MOV        EAX,0x1
    //                              infmap.cpp:213 (4)
    //         0044e547     POP        ESI
    //         0044e548     RET        0xc
    //                               LAB_0044e54b                                                 XREF[4]:     0044e525(j), 0044e529(j), 
    //                                                                                                         0044e52e(j), 0044e533(j)  
    //                              infmap.cpp:210 (2)
    //         0044e54b     XOR        EAX,EAX
    //                              infmap.cpp:213 (4)
    //         0044e54d     POP        ESI
    //         0044e54e     RET        0xc
    //         0044e551     ??         90h
    //         0044e552     NOP
    //         0044e553     NOP
    //         0044e554     NOP
    //         0044e555     NOP
    //         0044e556     NOP
    //         0044e557     NOP
    //         0044e558     NOP
    //         0044e559     NOP
    //         0044e55a     NOP
    //         0044e55b     NOP
    //         0044e55c     NOP
    //         0044e55d     NOP
    //         0044e55e     NOP
    //         0044e55f     NOP
    return 0;
}

int InfluenceMap::setValue(int param_1, int param_2, int param_3, int param_4, uchar param_5) {
    /* TODO: Stub */
    //                              int __thiscall setValue(InfluenceMap * this, int param_1, int param_
    //              int               EAX:4          <RETURN>
    //              InfluenceMap *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[4]:     0044e573(R), 0044e5b0(W), 0044e5d7(R), 0044e5de(W)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0044e563(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0044e56e(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[3]:     0044e569(R), 0044e584(W), 0044e5d3(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[1]:     0044e5b6(R)  
    //                               ?setValue@InfluenceMap@@QAEHHHHHE@Z                          XREF[4]:     setupInfluenceMap:004df09b(c), 
    //                               InfluenceMap::setValue                                                    setupInfluenceMap:004df67d(c), 
    //                                                                                                         setGroupInfluences:00500ef2(c), 
    //                                                                                                         setGroupInfluences:005010be(c)  
    //                              infmap.cpp:219 (3)
    //         0044e560     MOV        EAX,dword ptr [ECX + this->xReferencePointValue]
    //                              infmap.cpp:224 (6)
    //         0044e563     MOV        EDX,dword ptr [ESP + param_2]
    //         0044e567     PUSH       EBX
    //         0044e568     PUSH       EBP
    //                              infmap.cpp:225 (25)
    //         0044e569     MOV        EBP,dword ptr [ESP + param_4]
    //         0044e56d     PUSH       ESI
    //         0044e56e     MOV        ESI,dword ptr [ESP + param_3]
    //         0044e572     PUSH       EDI
    //         0044e573     MOV        EDI,dword ptr [ESP + param_1]
    //         0044e577     SUB        ESI,EAX
    //         0044e579     SUB        EDI,EAX
    //         0044e57b     MOV        EAX,dword ptr [ECX + this->yReferencePointValue]
    //         0044e57e     SUB        EDX,EAX
    //         0044e580     SUB        EBP,EAX
    //                              infmap.cpp:227 (26)
    //         0044e582     TEST       EDI,EDI
    //         0044e584     MOV        dword ptr [ESP + param_4],EBP
    //         0044e588     JL         LAB_0044e5f0
    //         0044e58a     TEST       EDX,EDX
    //         0044e58c     JL         LAB_0044e5f0
    //         0044e58e     MOV        EBX,dword ptr [ECX + this->xSizeValue]
    //         0044e591     CMP        EDI,EBX
    //         0044e593     JGE        LAB_0044e5f0
    //         0044e595     MOV        EAX,dword ptr [ECX + this->ySizeValue]
    //         0044e598     CMP        EDX,EAX
    //         0044e59a     JGE        LAB_0044e5f0
    //                              infmap.cpp:229 (16)
    //         0044e59c     TEST       ESI,ESI
    //         0044e59e     JL         LAB_0044e5f0
    //         0044e5a0     TEST       EBP,EBP
    //         0044e5a2     JL         LAB_0044e5f0
    //         0044e5a4     CMP        ESI,EBX
    //         0044e5a6     JGE        LAB_0044e5f0
    //         0044e5a8     CMP        EBP,EAX
    //         0044e5aa     JGE        LAB_0044e5f0
    //                              infmap.cpp:231 (14)
    //         0044e5ac     MOV        EBX,EDX
    //         0044e5ae     CMP        EDX,EBP
    //         0044e5b0     MOV        dword ptr [ESP + param_1],EBX
    //         0044e5b4     JG         LAB_0044e5e4
    //         0044e5b6     MOV        DL,byte ptr [ESP + param_5]
    //                               LAB_0044e5ba                                                 XREF[1]:     0044e5e2(j)  
    //                              infmap.cpp:232 (6)
    //         0044e5ba     CMP        EDI,ESI
    //         0044e5bc     MOV        EAX,EDI
    //         0044e5be     JG         LAB_0044e5db
    //                              infmap.cpp:231 (3)
    //         0044e5c0     SHL        EBX,0x2
    //                               LAB_0044e5c3                                                 XREF[1]:     0044e5d1(j)  
    //                              infmap.cpp:233 (33)
    //         0044e5c3     MOV        EBP,dword ptr [ECX + this->rowValue]
    //         0044e5c6     INC        EAX
    //         0044e5c7     CMP        EAX,ESI
    //         0044e5c9     MOV        EBP,dword ptr [EBP + EBX*0x1]
    //         0044e5cd     MOV        byte ptr [EBP + EAX*0x1 + -0x1],DL
    //         0044e5d1     JLE        LAB_0044e5c3
    //         0044e5d3     MOV        EBP,dword ptr [ESP + param_4]
    //         0044e5d7     MOV        EBX,dword ptr [ESP + param_1]
    //                               LAB_0044e5db                                                 XREF[1]:     0044e5be(j)  
    //         0044e5db     INC        EBX
    //         0044e5dc     CMP        EBX,EBP
    //         0044e5de     MOV        dword ptr [ESP + param_1],EBX
    //         0044e5e2     JLE        LAB_0044e5ba
    //                               LAB_0044e5e4                                                 XREF[1]:     0044e5b4(j)  
    //                              infmap.cpp:234 (5)
    //         0044e5e4     MOV        EAX,0x1
    //                              infmap.cpp:235 (16)
    //         0044e5e9     POP        EDI
    //         0044e5ea     POP        ESI
    //         0044e5eb     POP        EBP
    //         0044e5ec     POP        EBX
    //         0044e5ed     RET        0x14
    //                               LAB_0044e5f0                                                 XREF[8]:     0044e588(j), 0044e58c(j), 
    //                                                                                                         0044e593(j), 0044e59a(j), 
    //                                                                                                         0044e59e(j), 0044e5a2(j), 
    //                                                                                                         0044e5a6(j), 0044e5aa(j)  
    //         0044e5f0     POP        EDI
    //         0044e5f1     POP        ESI
    //         0044e5f2     POP        EBP
    //         0044e5f3     XOR        EAX,EAX
    //         0044e5f5     POP        EBX
    //         0044e5f6     RET        0x14
    //         0044e5f9     ??         90h
    //         0044e5fa     NOP
    //         0044e5fb     NOP
    //         0044e5fc     NOP
    //         0044e5fd     NOP
    //         0044e5fe     NOP
    //         0044e5ff     NOP
    return 0;
}

int InfluenceMap::incrementValue(int param_1, int param_2, uchar param_3) {
    /* TODO: Stub */
    //                              int __thiscall incrementValue(InfluenceMap * this, int param_1, int 
    //              int               EAX:4          <RETURN>
    //              InfluenceMap *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0044e600(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0044e60d(R)  
    //              uchar             Stack[0xc]:1   param_3                   XREF[1]:     0044e641(R)  
    //                               ?incrementValue@InfluenceMap@@QAEHHHE@Z                      XREF[3]:     changeInfluenceMap:004c6fda(c), 
    //                               InfluenceMap::incrementValue                                              changeInfluenceMap:004c6fef(c), 
    //                                                                                                         setupInfluenceMap:004dfb0c(c)  
    //                              infmap.cpp:240 (8)
    //         0044e600     MOV        EAX,dword ptr [ESP + param_1]
    //         0044e604     MOV        EDX,dword ptr [ECX + this->xReferencePointValue]
    //         0044e607     PUSH       ESI
    //                              infmap.cpp:244 (11)
    //         0044e608     MOV        ESI,dword ptr [ECX + this->yReferencePointValue]
    //         0044e60b     SUB        EAX,EDX
    //         0044e60d     MOV        EDX,dword ptr [ESP + param_2]
    //         0044e611     SUB        EDX,ESI
    //                              infmap.cpp:246 (18)
    //         0044e613     TEST       EAX,EAX
    //         0044e615     JL         LAB_0044e675
    //         0044e617     TEST       EDX,EDX
    //         0044e619     JL         LAB_0044e675
    //         0044e61b     CMP        EAX,dword ptr [ECX + this->xSizeValue]
    //         0044e61e     JGE        LAB_0044e675
    //         0044e620     CMP        EDX,dword ptr [ECX + this->ySizeValue]
    //         0044e623     JGE        LAB_0044e675
    //                              infmap.cpp:248 (19)
    //         0044e625     MOV        ESI,dword ptr [ECX + this->rowValue]
    //         0044e628     MOV        this,byte ptr [ECX + this->unchangeableLimitVa
    //         0044e62b     MOV        EDX,dword ptr [ESI + EDX*0x4]
    //         0044e62e     LEA        ESI,[EDX + EAX*0x1]
    //         0044e631     MOV        AL,byte ptr [EDX + EAX*0x1]
    //         0044e634     CMP        AL,this
    //         0044e636     JC         LAB_0044e641
    //                              infmap.cpp:249 (5)
    //         0044e638     MOV        EAX,0x1
    //                              infmap.cpp:257 (4)
    //         0044e63d     POP        ESI
    //         0044e63e     RET        0xc
    //                               LAB_0044e641                                                 XREF[1]:     0044e636(j)  
    //                              infmap.cpp:251 (17)
    //         0044e641     MOV        EDX,dword ptr [ESP + param_3]
    //         0044e645     AND        EAX,0xff
    //         0044e64a     AND        EDX,0xff
    //         0044e650     ADD        EDX,EAX
    //                              infmap.cpp:252 (11)
    //         0044e652     MOV        EAX,this
    //         0044e654     AND        EAX,0xff
    //         0044e659     CMP        EDX,EAX
    //         0044e65b     JL         LAB_0044e66a
    //                              infmap.cpp:253 (2)
    //         0044e65d     DEC        this
    //                              infmap.cpp:256 (7)
    //         0044e65f     MOV        EAX,0x1
    //         0044e664     MOV        byte ptr [ESI],this
    //                              infmap.cpp:257 (4)
    //         0044e666     POP        ESI
    //         0044e667     RET        0xc
    //                               LAB_0044e66a                                                 XREF[1]:     0044e65b(j)  
    //                              infmap.cpp:255 (2)
    //         0044e66a     MOV        byte ptr [ESI],DL
    //                              infmap.cpp:256 (5)
    //         0044e66c     MOV        EAX,0x1
    //                              infmap.cpp:257 (4)
    //         0044e671     POP        ESI
    //         0044e672     RET        0xc
    //                               LAB_0044e675                                                 XREF[4]:     0044e615(j), 0044e619(j), 
    //                                                                                                         0044e61e(j), 0044e623(j)  
    //                              infmap.cpp:247 (2)
    //         0044e675     XOR        EAX,EAX
    //                              infmap.cpp:257 (4)
    //         0044e677     POP        ESI
    //         0044e678     RET        0xc
    //         0044e67b     ??         90h
    //         0044e67c     NOP
    //         0044e67d     NOP
    //         0044e67e     NOP
    //         0044e67f     NOP
    return 0;
}

int InfluenceMap::incrementValue(int param_1, int param_2, int param_3, int param_4, uchar param_5) {
    /* TODO: Stub */
    //                              int __thiscall incrementValue(InfluenceMap * this, int param_1, int 
    //              int               EAX:4          <RETURN>
    //              InfluenceMap *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[4]:     0044e695(R), 0044e6a0(W), 0044e6be(W), 0044e75d(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[5]:     0044e681(R), 0044e70a(W), 0044e71d(R), 0044e761(R), 
    //                                                                                     0044e76d(W)  
    //              int               Stack[0xc]:4   param_3                   XREF[4]:     0044e690(R), 0044e6aa(W), 0044e6e6(W), 0044e754(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[4]:     0044e688(R), 0044e70e(W), 0044e765(R), 0044e771(W)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[1]:     0044e712(R)  
    //                               ?incrementValue@InfluenceMap@@QAEHHHHHE@Z                    XREF[10]:    setupInfluenceMap:004df185(c), 
    //                               InfluenceMap::incrementValue                                              setupInfluenceMap:004df1e5(c), 
    //                                                                                                         setupInfluenceMap:004df335(c), 
    //                                                                                                         setupInfluenceMap:004df7a9(c), 
    //                                                                                                         setupInfluenceMap:004df812(c), 
    //                                                                                                         setupInfluenceMap:004df882(c), 
    //                                                                                                         setupInfluenceMap:004df9ab(c), 
    //                                                                                                         setupInfluenceMap:004dfc04(c), 
    //                                                                                                         setupLOSMap:004e22ae(c), 
    //                                                                                                         setupAttackMap:004e2371(c)  
    //                              infmap.cpp:263 (1)
    //         0044e680     PUSH       EBX
    //                              infmap.cpp:267 (7)
    //         0044e681     MOV        EDX,dword ptr [ESP + param_2]
    //         0044e685     PUSH       EBP
    //         0044e686     MOV        EBP,this
    //                              infmap.cpp:268 (32)
    //         0044e688     MOV        this,dword ptr [ESP + param_4]
    //         0044e68c     PUSH       ESI
    //         0044e68d     MOV        EAX,dword ptr [EBP + 0xc]
    //         0044e690     MOV        ESI,dword ptr [ESP + param_3]
    //         0044e694     PUSH       EDI
    //         0044e695     MOV        EDI,dword ptr [ESP + param_1]
    //         0044e699     SUB        EDI,EAX
    //         0044e69b     SUB        ESI,EAX
    //         0044e69d     MOV        EAX,dword ptr [EBP + 0x10]
    //         0044e6a0     MOV        dword ptr [ESP + param_1],EDI
    //         0044e6a4     SUB        EDX,EAX
    //         0044e6a6     SUB        this,EAX
    //                              infmap.cpp:270 (8)
    //         0044e6a8     TEST       EDI,EDI
    //         0044e6aa     MOV        dword ptr [ESP + param_3],ESI
    //         0044e6ae     JGE        LAB_0044e6b4
    //                              infmap.cpp:271 (2)
    //         0044e6b0     XOR        EDI,EDI
    //                              infmap.cpp:272 (9)
    //         0044e6b2     JMP        LAB_0044e6be
    //                               LAB_0044e6b4                                                 XREF[1]:     0044e6ae(j)  
    //         0044e6b4     MOV        EAX,dword ptr [EBP + 0x4]
    //         0044e6b7     CMP        EDI,EAX
    //         0044e6b9     JL         LAB_0044e6c2
    //                              infmap.cpp:273 (7)
    //         0044e6bb     LEA        EDI,[EAX + -0x1]
    //                               LAB_0044e6be                                                 XREF[1]:     0044e6b2(j)  
    //         0044e6be     MOV        dword ptr [ESP + param_1],EDI
    //                               LAB_0044e6c2                                                 XREF[1]:     0044e6b9(j)  
    //                              infmap.cpp:274 (4)
    //         0044e6c2     TEST       EDX,EDX
    //         0044e6c4     JGE        LAB_0044e6ca
    //                              infmap.cpp:275 (2)
    //         0044e6c6     XOR        EDX,EDX
    //                              infmap.cpp:276 (9)
    //         0044e6c8     JMP        LAB_0044e6d4
    //                               LAB_0044e6ca                                                 XREF[1]:     0044e6c4(j)  
    //         0044e6ca     MOV        EAX,dword ptr [EBP + 0x4]
    //         0044e6cd     CMP        EDX,EAX
    //         0044e6cf     JL         LAB_0044e6d4
    //                              infmap.cpp:277 (3)
    //         0044e6d1     LEA        EDX,[EAX + -0x1]
    //                               LAB_0044e6d4                                                 XREF[2]:     0044e6c8(j), 0044e6cf(j)  
    //                              infmap.cpp:278 (4)
    //         0044e6d4     TEST       ESI,ESI
    //         0044e6d6     JGE        LAB_0044e6dc
    //                              infmap.cpp:279 (2)
    //         0044e6d8     XOR        ESI,ESI
    //                              infmap.cpp:280 (9)
    //         0044e6da     JMP        LAB_0044e6e6
    //                               LAB_0044e6dc                                                 XREF[1]:     0044e6d6(j)  
    //         0044e6dc     MOV        EAX,dword ptr [EBP + 0x4]
    //         0044e6df     CMP        ESI,EAX
    //         0044e6e1     JL         LAB_0044e6ea
    //                              infmap.cpp:281 (7)
    //         0044e6e3     LEA        ESI,[EAX + -0x1]
    //                               LAB_0044e6e6                                                 XREF[1]:     0044e6da(j)  
    //         0044e6e6     MOV        dword ptr [ESP + param_3],ESI
    //                               LAB_0044e6ea                                                 XREF[1]:     0044e6e1(j)  
    //                              infmap.cpp:282 (4)
    //         0044e6ea     TEST       this,this
    //         0044e6ec     JGE        LAB_0044e6f2
    //                              infmap.cpp:283 (2)
    //         0044e6ee     XOR        this,this
    //                              infmap.cpp:284 (9)
    //         0044e6f0     JMP        LAB_0044e6fc
    //                               LAB_0044e6f2                                                 XREF[1]:     0044e6ec(j)  
    //         0044e6f2     MOV        EAX,dword ptr [EBP + 0x4]
    //         0044e6f5     CMP        this,EAX
    //         0044e6f7     JL         LAB_0044e6fc
    //                              infmap.cpp:285 (3)
    //         0044e6f9     LEA        this,[EAX + -0x1]
    //                               LAB_0044e6fc                                                 XREF[2]:     0044e6f0(j), 0044e6f7(j)  
    //                              infmap.cpp:287 (26)
    //         0044e6fc     CMP        EDX,this
    //         0044e6fe     JG         LAB_0044e777
    //         0044e700     SUB        this,EDX
    //         0044e702     LEA        EAX,[EDX*0x4 + 0x0]
    //         0044e709     INC        this
    //         0044e70a     MOV        dword ptr [ESP + param_2],EAX
    //         0044e70e     MOV        dword ptr [ESP + param_4],this
    //         0044e712     MOV        this,dword ptr [ESP + param_5]
    //                               LAB_0044e716                                                 XREF[1]:     0044e775(j)  
    //                              infmap.cpp:288 (4)
    //         0044e716     CMP        EDI,ESI
    //         0044e718     JG         LAB_0044e761
    //                               LAB_0044e71a                                                 XREF[1]:     0044e75b(j)  
    //                              infmap.cpp:289 (19)
    //         0044e71a     MOV        EDX,dword ptr [EBP + 0x18]
    //         0044e71d     MOV        EAX,dword ptr [ESP + param_2]
    //         0044e721     ADD        EAX,EDX
    //         0044e723     MOV        DL,byte ptr [EBP + 0x24]
    //         0044e726     MOV        ESI,dword ptr [EAX]
    //         0044e728     CMP        byte ptr [EDI + ESI*0x1],DL
    //         0044e72b     JNC        LAB_0044e754
    //                              infmap.cpp:292 (19)
    //         0044e72d     MOV        EAX,ESI
    //         0044e72f     XOR        EBX,EBX
    //         0044e731     MOV        BL,byte ptr [EDI + EAX*0x1]
    //         0044e734     LEA        ESI,[EDI + EAX*0x1]
    //         0044e737     MOV        EAX,this
    //         0044e739     AND        EAX,0xff
    //         0044e73e     ADD        EAX,EBX
    //                              infmap.cpp:293 (12)
    //         0044e740     MOV        EBX,EDX
    //         0044e742     AND        EBX,0xff
    //         0044e748     CMP        EAX,EBX
    //         0044e74a     JL         LAB_0044e752
    //                              infmap.cpp:294 (4)
    //         0044e74c     DEC        DL
    //         0044e74e     MOV        byte ptr [ESI],DL
    //                              infmap.cpp:295 (2)
    //         0044e750     JMP        LAB_0044e754
    //                               LAB_0044e752                                                 XREF[1]:     0044e74a(j)  
    //                              infmap.cpp:296 (2)
    //         0044e752     MOV        byte ptr [ESI],AL
    //                               LAB_0044e754                                                 XREF[2]:     0044e72b(j), 0044e750(j)  
    //                              infmap.cpp:288 (13)
    //         0044e754     MOV        ESI,dword ptr [ESP + param_3]
    //         0044e758     INC        EDI
    //         0044e759     CMP        EDI,ESI
    //         0044e75b     JLE        LAB_0044e71a
    //         0044e75d     MOV        EDI,dword ptr [ESP + param_1]
    //                               LAB_0044e761                                                 XREF[1]:     0044e718(j)  
    //                              infmap.cpp:287 (22)
    //         0044e761     MOV        EDX,dword ptr [ESP + param_2]
    //         0044e765     MOV        EAX,dword ptr [ESP + param_4]
    //         0044e769     ADD        EDX,0x4
    //         0044e76c     DEC        EAX
    //         0044e76d     MOV        dword ptr [ESP + param_2],EDX
    //         0044e771     MOV        dword ptr [ESP + param_4],EAX
    //         0044e775     JNZ        LAB_0044e716
    //                               LAB_0044e777                                                 XREF[1]:     0044e6fe(j)  
    //                              infmap.cpp:299 (12)
    //         0044e777     POP        EDI
    //         0044e778     POP        ESI
    //         0044e779     POP        EBP
    //         0044e77a     MOV        EAX,0x1
    //         0044e77f     POP        EBX
    //         0044e780     RET        0x14
    //         0044e783     ??         90h
    //         0044e784     NOP
    //         0044e785     NOP
    //         0044e786     NOP
    //         0044e787     NOP
    //         0044e788     NOP
    //         0044e789     NOP
    //         0044e78a     NOP
    //         0044e78b     NOP
    //         0044e78c     NOP
    //         0044e78d     NOP
    //         0044e78e     NOP
    //         0044e78f     NOP
    return 0;
}

int InfluenceMap::decrementValue(int param_1, int param_2, uchar param_3) {
    /* TODO: Stub */
    //                              int __thiscall decrementValue(InfluenceMap * this, int param_1, int 
    //              int               EAX:4          <RETURN>
    //              InfluenceMap *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0044e790(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0044e79e(R)  
    //              uchar             Stack[0xc]:1   param_3                   XREF[1]:     0044e7d1(R)  
    //                               ?decrementValue@InfluenceMap@@QAEHHHE@Z                      XREF[2]:     changeInfluenceMap:004c6ff6(c), 
    //                               InfluenceMap::decrementValue                                              setupInfluenceMap:004def40(c)  
    //                              infmap.cpp:304 (9)
    //         0044e790     MOV        EAX,dword ptr [ESP + param_1]
    //         0044e794     MOV        EDX,dword ptr [ECX + this->xReferencePointValue]
    //         0044e797     PUSH       EBX
    //         0044e798     PUSH       ESI
    //                              infmap.cpp:307 (11)
    //         0044e799     MOV        ESI,dword ptr [ECX + this->yReferencePointValue]
    //         0044e79c     SUB        EAX,EDX
    //         0044e79e     MOV        EDX,dword ptr [ESP + param_2]
    //         0044e7a2     SUB        EDX,ESI
    //                              infmap.cpp:309 (18)
    //         0044e7a4     TEST       EAX,EAX
    //         0044e7a6     JL         LAB_0044e7f4
    //         0044e7a8     TEST       EDX,EDX
    //         0044e7aa     JL         LAB_0044e7f4
    //         0044e7ac     CMP        EAX,dword ptr [ECX + this->xSizeValue]
    //         0044e7af     JGE        LAB_0044e7f4
    //         0044e7b1     CMP        EDX,dword ptr [ECX + this->ySizeValue]
    //         0044e7b4     JGE        LAB_0044e7f4
    //                              infmap.cpp:312 (17)
    //         0044e7b6     MOV        ESI,dword ptr [ECX + this->rowValue]
    //         0044e7b9     MOV        BL,byte ptr [ECX + this->unchangeableLimitValue]
    //         0044e7bc     MOV        EDX,dword ptr [ESI + EDX*0x4]
    //         0044e7bf     ADD        EDX,EAX
    //         0044e7c1     MOV        AL,byte ptr [EDX]
    //         0044e7c3     CMP        AL,BL
    //         0044e7c5     JC         LAB_0044e7d1
    //                              infmap.cpp:313 (5)
    //         0044e7c7     MOV        EAX,0x1
    //                              infmap.cpp:321 (5)
    //         0044e7cc     POP        ESI
    //         0044e7cd     POP        EBX
    //         0044e7ce     RET        0xc
    //                               LAB_0044e7d1                                                 XREF[1]:     0044e7c5(j)  
    //                              infmap.cpp:315 (17)
    //         0044e7d1     MOV        this,dword ptr [ESP + param_3]
    //         0044e7d5     AND        EAX,0xff
    //         0044e7da     AND        this,0xff
    //         0044e7e0     SUB        EAX,this
    //                              infmap.cpp:316 (6)
    //         0044e7e2     SETS       this
    //         0044e7e5     DEC        this
    //         0044e7e6     AND        this,EAX
    //                              infmap.cpp:320 (7)
    //         0044e7e8     MOV        EAX,0x1
    //         0044e7ed     MOV        byte ptr [EDX],this
    //                              infmap.cpp:321 (12)
    //         0044e7ef     POP        ESI
    //         0044e7f0     POP        EBX
    //         0044e7f1     RET        0xc
    //                               LAB_0044e7f4                                                 XREF[4]:     0044e7a6(j), 0044e7aa(j), 
    //                                                                                                         0044e7af(j), 0044e7b4(j)  
    //         0044e7f4     POP        ESI
    //         0044e7f5     XOR        EAX,EAX
    //         0044e7f7     POP        EBX
    //         0044e7f8     RET        0xc
    //         0044e7fb     ??         90h
    //         0044e7fc     NOP
    //         0044e7fd     NOP
    //         0044e7fe     NOP
    //         0044e7ff     NOP
    return 0;
}

int InfluenceMap::decrementValue(int param_1, int param_2, int param_3, int param_4, uchar param_5) {
    /* TODO: Stub */
    //                              int __thiscall decrementValue(InfluenceMap * this, int param_1, int 
    //              int               EAX:4          <RETURN>
    //              InfluenceMap *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[5]:     0044e801(R), 0044e822(W), 0044e832(W), 0044e840(W), 
    //                                                                                     0044e894(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[4]:     0044e80b(R), 0044e890(W), 0044e8d8(R), 0044e8e0(W)  
    //              int               Stack[0xc]:4   param_3                   XREF[6]:     0044e807(R), 0044e82c(W), 0044e85a(W), 0044e868(W), 
    //                                                                                     0044e898(R), 0044e8cf(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0044e812(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[1]:     0044e882(R)  
    //                               ?decrementValue@InfluenceMap@@QAEHHHHHE@Z                    XREF[7]:     setupInfluenceMap:004df2bc(c), 
    //                               InfluenceMap::decrementValue                                              setupInfluenceMap:004df72e(c), 
    //                                                                                                         setupInfluenceMap:004df917(c), 
    //                                                                                                         setupInfluenceMap:004df9cd(c), 
    //                                                                                                         setupInfluenceMap:004dfae7(c), 
    //                                                                                                         setGroupInfluences:00500f9d(c), 
    //                                                                                                         setGroupInfluences:00501166(c)  
    //                              infmap.cpp:327 (1)
    //         0044e800     PUSH       EBX
    //                              infmap.cpp:329 (6)
    //         0044e801     MOV        EBX,dword ptr [ESP + param_1]
    //         0044e805     PUSH       EBP
    //         0044e806     PUSH       ESI
    //                              infmap.cpp:330 (4)
    //         0044e807     MOV        ESI,dword ptr [ESP + param_3]
    //                              infmap.cpp:331 (7)
    //         0044e80b     MOV        EDX,dword ptr [ESP + param_2]
    //         0044e80f     PUSH       EDI
    //         0044e810     MOV        EDI,this
    //                              infmap.cpp:332 (4)
    //         0044e812     MOV        this,dword ptr [ESP + param_4]
    //                              infmap.cpp:334 (28)
    //         0044e816     XOR        EBP,EBP
    //         0044e818     MOV        EAX,dword ptr [EDI + 0xc]
    //         0044e81b     SUB        EBX,EAX
    //         0044e81d     SUB        ESI,EAX
    //         0044e81f     MOV        EAX,dword ptr [EDI + 0x10]
    //         0044e822     MOV        dword ptr [ESP + param_1],EBX
    //         0044e826     SUB        EDX,EAX
    //         0044e828     SUB        this,EAX
    //         0044e82a     CMP        EBX,EBP
    //         0044e82c     MOV        dword ptr [ESP + param_3],ESI
    //         0044e830     JGE        LAB_0044e838
    //                              infmap.cpp:335 (4)
    //         0044e832     MOV        dword ptr [ESP + param_1],EBP
    //                              infmap.cpp:336 (9)
    //         0044e836     JMP        LAB_0044e844
    //                               LAB_0044e838                                                 XREF[1]:     0044e830(j)  
    //         0044e838     MOV        EAX,dword ptr [EDI + 0x4]
    //         0044e83b     CMP        EBX,EAX
    //         0044e83d     JL         LAB_0044e844
    //                              infmap.cpp:337 (5)
    //         0044e83f     DEC        EAX
    //         0044e840     MOV        dword ptr [ESP + param_1],EAX
    //                               LAB_0044e844                                                 XREF[2]:     0044e836(j), 0044e83d(j)  
    //                              infmap.cpp:338 (4)
    //         0044e844     CMP        EDX,EBP
    //         0044e846     JGE        LAB_0044e84c
    //                              infmap.cpp:339 (2)
    //         0044e848     XOR        EDX,EDX
    //                              infmap.cpp:340 (9)
    //         0044e84a     JMP        LAB_0044e856
    //                               LAB_0044e84c                                                 XREF[1]:     0044e846(j)  
    //         0044e84c     MOV        EAX,dword ptr [EDI + 0x4]
    //         0044e84f     CMP        EDX,EAX
    //         0044e851     JL         LAB_0044e856
    //                              infmap.cpp:341 (3)
    //         0044e853     LEA        EDX,[EAX + -0x1]
    //                               LAB_0044e856                                                 XREF[2]:     0044e84a(j), 0044e851(j)  
    //                              infmap.cpp:342 (4)
    //         0044e856     CMP        ESI,EBP
    //         0044e858     JGE        LAB_0044e860
    //                              infmap.cpp:343 (4)
    //         0044e85a     MOV        dword ptr [ESP + param_3],EBP
    //                              infmap.cpp:344 (9)
    //         0044e85e     JMP        LAB_0044e86c
    //                               LAB_0044e860                                                 XREF[1]:     0044e858(j)  
    //         0044e860     MOV        EAX,dword ptr [EDI + 0x4]
    //         0044e863     CMP        ESI,EAX
    //         0044e865     JL         LAB_0044e86c
    //                              infmap.cpp:345 (5)
    //         0044e867     DEC        EAX
    //         0044e868     MOV        dword ptr [ESP + param_3],EAX
    //                               LAB_0044e86c                                                 XREF[2]:     0044e85e(j), 0044e865(j)  
    //                              infmap.cpp:346 (4)
    //         0044e86c     CMP        this,EBP
    //         0044e86e     JGE        LAB_0044e874
    //                              infmap.cpp:347 (2)
    //         0044e870     XOR        this,this
    //                              infmap.cpp:348 (9)
    //         0044e872     JMP        LAB_0044e87e
    //                               LAB_0044e874                                                 XREF[1]:     0044e86e(j)  
    //         0044e874     MOV        EAX,dword ptr [EDI + 0x4]
    //         0044e877     CMP        this,EAX
    //         0044e879     JL         LAB_0044e87e
    //                              infmap.cpp:349 (3)
    //         0044e87b     LEA        this,[EAX + -0x1]
    //                               LAB_0044e87e                                                 XREF[2]:     0044e872(j), 0044e879(j)  
    //                              infmap.cpp:351 (22)
    //         0044e87e     CMP        EDX,this
    //         0044e880     JG         LAB_0044e8e6
    //         0044e882     MOV        EBP,dword ptr [ESP + param_5]
    //         0044e886     SUB        this,EDX
    //         0044e888     INC        this
    //         0044e889     LEA        EBX,[EDX*0x4 + 0x0]
    //         0044e890     MOV        dword ptr [ESP + param_2],this
    //                               LAB_0044e894                                                 XREF[1]:     0044e8e4(j)  
    //                              infmap.cpp:352 (14)
    //         0044e894     MOV        ESI,dword ptr [ESP + param_1]
    //         0044e898     MOV        this,dword ptr [ESP + param_3]
    //         0044e89c     MOV        EAX,ESI
    //         0044e89e     CMP        EAX,this
    //         0044e8a0     JG         LAB_0044e8d8
    //                               LAB_0044e8a2                                                 XREF[1]:     0044e8d6(j)  
    //                              infmap.cpp:353 (19)
    //         0044e8a2     MOV        this,dword ptr [EDI + 0x18]
    //         0044e8a5     MOV        EDX,dword ptr [this->_padding_ + EBX*0x1]
    //         0044e8a8     LEA        EAX,[this->_padding_ + EBX*0x1]
    //         0044e8ab     MOV        this,byte ptr [ESI + EDX*0x1]
    //         0044e8ae     MOV        DL,byte ptr [EDI + 0x24]
    //         0044e8b1     CMP        this,DL
    //         0044e8b3     JNC        LAB_0044e8cf
    //                              infmap.cpp:356 (18)
    //         0044e8b5     MOV        EDX,dword ptr [EAX]
    //         0044e8b7     MOV        this,EBP
    //         0044e8b9     ADD        EDX,ESI
    //         0044e8bb     XOR        EAX,EAX
    //         0044e8bd     AND        this,0xff
    //         0044e8c3     MOV        AL,byte ptr [EDX]
    //         0044e8c5     SUB        EAX,this
    //                              infmap.cpp:357 (17)
    //         0044e8c7     SETS       this
    //         0044e8ca     DEC        this
    //         0044e8cb     AND        this,EAX
    //         0044e8cd     MOV        byte ptr [EDX],this
    //                               LAB_0044e8cf                                                 XREF[1]:     0044e8b3(j)  
    //         0044e8cf     MOV        EAX,dword ptr [ESP + param_3]
    //         0044e8d3     INC        ESI
    //         0044e8d4     CMP        ESI,EAX
    //         0044e8d6     JLE        LAB_0044e8a2
    //                               LAB_0044e8d8                                                 XREF[1]:     0044e8a0(j)  
    //                              infmap.cpp:351 (14)
    //         0044e8d8     MOV        EAX,dword ptr [ESP + param_2]
    //         0044e8dc     ADD        EBX,0x4
    //         0044e8df     DEC        EAX
    //         0044e8e0     MOV        dword ptr [ESP + param_2],EAX
    //         0044e8e4     JNZ        LAB_0044e894
    //                               LAB_0044e8e6                                                 XREF[1]:     0044e880(j)  
    //                              infmap.cpp:363 (12)
    //         0044e8e6     POP        EDI
    //         0044e8e7     POP        ESI
    //         0044e8e8     POP        EBP
    //         0044e8e9     MOV        EAX,0x1
    //         0044e8ee     POP        EBX
    //         0044e8ef     RET        0x14
    //         0044e8f2     ??         90h
    //         0044e8f3     NOP
    //         0044e8f4     NOP
    //         0044e8f5     NOP
    //         0044e8f6     NOP
    //         0044e8f7     NOP
    //         0044e8f8     NOP
    //         0044e8f9     NOP
    //         0044e8fa     NOP
    //         0044e8fb     NOP
    //         0044e8fc     NOP
    //         0044e8fd     NOP
    //         0044e8fe     NOP
    //         0044e8ff     NOP
    //                              * public: int __thiscall InfluenceMap::setCoverageCount(struct XYPoint const &,struct XYPoint const ... *
    //                              int __thiscall setCoverageCount(InfluenceMap * this, XYPoint * param
    //              int               EAX:4          <RETURN>
    //              InfluenceMap *    ECX:4 (auto)   this
    //              XYPoint *         Stack[0x4]:4   param_1                   XREF[2]:     0044e907(R), 0044e9b0(R)  
    //              XYPoint *         Stack[0x8]:4   param_2                   XREF[3]:     0044e93f(R), 0044e99d(R), 0044e9b4(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0044e98e(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0044e960(W), 0044e9ac(R), 0044e9be(W)  
    //              int               Stack[-0x8]:4  i                         XREF[2]:     0044e912(W), 0044e994(R)  
    //                               ?setCoverageCount@InfluenceMap@@QAEHABUXYPoint@@0H@Z
    //                               InfluenceMap::setCoverageCount
    //                              infmap.cpp:369 (7)
    //         0044e900     SUB        ESP,0x8
    //         0044e903     PUSH       EBX
    //         0044e904     PUSH       EBP
    //         0044e905     PUSH       ESI
    //         0044e906     PUSH       EDI
    //                              infmap.cpp:377 (87)
    //         0044e907     MOV        EDI,dword ptr [ESP + param_1]
    //         0044e90b     MOV        dword ptr [ECX + this->coverageCountValue],0x0
    //         0044e912     MOV        dword ptr [ESP + i],this
    //         0044e916     MOV        ESI,dword ptr [EDI]
    //         0044e918     TEST       ESI,ESI
    //         0044e91a     JL         LAB_0044e9d1
    //         0044e920     MOV        EAX,dword ptr [EDI + 0x4]
    //         0044e923     TEST       EAX,EAX
    //         0044e925     JL         LAB_0044e9d1
    //         0044e92b     MOV        EBX,dword ptr [ECX + this->xSizeValue]
    //         0044e92e     CMP        ESI,EBX
    //         0044e930     JGE        LAB_0044e9d1
    //         0044e936     CMP        EAX,dword ptr [ECX + this->ySizeValue]
    //         0044e939     JGE        LAB_0044e9d1
    //         0044e93f     MOV        EBP,dword ptr [ESP + param_2]
    //         0044e943     MOV        EDX,dword ptr [EBP]
    //         0044e946     TEST       EDX,EDX
    //         0044e948     JL         LAB_0044e9d1
    //         0044e94e     MOV        EAX,dword ptr [EBP + 0x4]
    //         0044e951     TEST       EAX,EAX
    //         0044e953     JL         LAB_0044e9d1
    //         0044e955     CMP        EDX,EBX
    //         0044e957     JGE        LAB_0044e9d1
    //         0044e959     CMP        EAX,dword ptr [ECX + this->ySizeValue]
    //         0044e95c     JGE        LAB_0044e9d1
    //                              infmap.cpp:380 (8)
    //         0044e95e     CMP        ESI,EDX
    //         0044e960     MOV        dword ptr [ESP + local_4],ESI
    //         0044e964     JG         LAB_0044e9c4
    //                               LAB_0044e966                                                 XREF[1]:     0044e9c2(j)  
    //                              infmap.cpp:381 (7)
    //         0044e966     MOV        EBX,dword ptr [EDI + 0x4]
    //         0044e969     CMP        EBX,EAX
    //         0044e96b     JG         LAB_0044e9b8
    //                              infmap.cpp:382 (39)
    //         0044e96d     MOV        EDX,dword ptr [ECX + this->xReferencePointValue]
    //         0044e970     MOV        EDI,dword ptr [ECX + this->yReferencePointValue]
    //         0044e973     MOV        EBP,dword ptr [ECX + this->rowValue]
    //         0044e976     SUB        ESI,EDX
    //         0044e978     LEA        EDX,[EBX*0x4 + 0x0]
    //         0044e97f     SHL        EDI,0x2
    //                               LAB_0044e982                                                 XREF[1]:     0044e9aa(j)  
    //         0044e982     MOV        EAX,EDX
    //         0044e984     XOR        this,this
    //         0044e986     SUB        EAX,EDI
    //         0044e988     MOV        EAX,dword ptr [EAX + EBP*0x1]
    //         0044e98b     MOV        this,byte ptr [EAX + ESI*0x1]
    //         0044e98e     MOV        EAX,dword ptr [ESP + param_3]
    //         0044e992     CMP        this,EAX
    //                              infmap.cpp:383 (48)
    //         0044e994     MOV        this,dword ptr [ESP + i]
    //         0044e998     JL         LAB_0044e99d
    //         0044e99a     INC        dword ptr [ECX + this->coverageCountValue]
    //                               LAB_0044e99d                                                 XREF[1]:     0044e998(j)  
    //         0044e99d     MOV        EAX,dword ptr [ESP + param_2]
    //         0044e9a1     INC        EBX
    //         0044e9a2     ADD        EDX,0x4
    //         0044e9a5     MOV        EAX,dword ptr [EAX + 0x4]
    //         0044e9a8     CMP        EBX,EAX
    //         0044e9aa     JLE        LAB_0044e982
    //         0044e9ac     MOV        ESI,dword ptr [ESP + local_4]
    //         0044e9b0     MOV        EDI,dword ptr [ESP + param_1]
    //         0044e9b4     MOV        EBP,dword ptr [ESP + param_2]
    //                               LAB_0044e9b8                                                 XREF[1]:     0044e96b(j)  
    //         0044e9b8     MOV        EDX,dword ptr [EBP]
    //         0044e9bb     INC        ESI
    //         0044e9bc     CMP        ESI,EDX
    //         0044e9be     MOV        dword ptr [ESP + local_4],ESI
    //         0044e9c2     JLE        LAB_0044e966
    //                               LAB_0044e9c4                                                 XREF[1]:     0044e964(j)  
    //                              infmap.cpp:386 (3)
    //         0044e9c4     MOV        EAX,dword ptr [ECX + this->coverageCountValue]
    //                              infmap.cpp:387 (22)
    //         0044e9c7     POP        EDI
    //         0044e9c8     POP        ESI
    //         0044e9c9     POP        EBP
    //         0044e9ca     POP        EBX
    //         0044e9cb     ADD        ESP,0x8
    //         0044e9ce     RET        0xc
    //                               LAB_0044e9d1                                                 XREF[8]:     0044e91a(j), 0044e925(j), 
    //                                                                                                         0044e930(j), 0044e939(j), 
    //                                                                                                         0044e948(j), 0044e953(j), 
    //                                                                                                         0044e957(j), 0044e95c(j)  
    //         0044e9d1     POP        EDI
    //         0044e9d2     POP        ESI
    //         0044e9d3     POP        EBP
    //         0044e9d4     XOR        EAX,EAX
    //         0044e9d6     POP        EBX
    //         0044e9d7     ADD        ESP,0x8
    //         0044e9da     RET        0xc
    //         0044e9dd     ??         90h
    //         0044e9de     NOP
    //         0044e9df     NOP
    //                              * public: int __thiscall InfluenceMap::setConnectionCount(struct XYPoint const &,struct XYPoint cons... *
    //                              int __thiscall setConnectionCount(InfluenceMap * this, XYPoint * par
    //              int               EAX:4          <RETURN>
    //              InfluenceMap *    ECX:4 (auto)   this
    //              XYPoint *         Stack[0x4]:4   param_1                   XREF[2]:     0044e9e3(R), 0044ea61(R)  
    //              XYPoint *         Stack[0x8]:4   param_2                   XREF[2]:     0044ea2b(R), 0044eb65(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[2]:     0044eaad(R), 0044eb19(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0044eb23(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     0044eb3d(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[1]:     0044ead6(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0044ea90(W), 0044eb71(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0044ea80(W), 0044eb0d(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0044ea21(W), 0044eafc(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     0044ea12(W), 0044eaf2(R)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[3]:     0044ea57(W), 0044eb6d(R), 0044eb9a(W)  
    //              int               Stack[-0x18]:4 i                         XREF[3]:     0044ea7a(W), 0044ea9f(R), 0044eb02(R)  
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[4]:     0044ea6a(W), 0044eab9(R), 0044eb79(R), 0044eb8a(W)  
    //              int               Stack[-0x20]:4 j                         XREF[5]:     0044ea94(W), 0044ea9b(R), 0044eabf(R), 0044eb75(R), 
    //                                                                                     0044eb81(W)  
    //              undefined4        Stack[-0x24]:4 local_24                  XREF[3]:     0044e9ed(W), 0044eb54(R), 0044eb69(R)  
    //                               ?setConnectionCount@InfluenceMap@@QAEHABUXYPoint@@0HHHH@Z    XREF[1]:     setupInfluenceMap:004dfc6b(c)  
    //                               InfluenceMap::setConnectionCount
    //                              infmap.cpp:394 (3)
    //         0044e9e0     SUB        ESP,0x24
    //                              infmap.cpp:402 (114)
    //         0044e9e3     MOV        EAX,dword ptr [ESP + param_1]
    //         0044e9e7     PUSH       EBX
    //         0044e9e8     PUSH       EBP
    //         0044e9e9     PUSH       ESI
    //         0044e9ea     PUSH       EDI
    //         0044e9eb     MOV        EDI,this
    //         0044e9ed     MOV        dword ptr [ESP + local_24],EDI
    //         0044e9f1     MOV        dword ptr [EDI + 0x20],0x0
    //         0044e9f8     MOV        ESI,dword ptr [EAX]
    //         0044e9fa     TEST       ESI,ESI
    //         0044e9fc     JL         LAB_0044ebb1
    //         0044ea02     MOV        EAX,dword ptr [EAX + 0x4]
    //         0044ea05     TEST       EAX,EAX
    //         0044ea07     JL         LAB_0044ebb1
    //         0044ea0d     MOV        EBX,dword ptr [EDI + 0x4]
    //         0044ea10     CMP        ESI,EBX
    //         0044ea12     MOV        dword ptr [ESP + local_10],EBX
    //         0044ea16     JGE        LAB_0044ebb1
    //         0044ea1c     MOV        this,dword ptr [EDI + 0x8]
    //         0044ea1f     CMP        EAX,this
    //         0044ea21     MOV        dword ptr [ESP + local_c],this
    //         0044ea25     JGE        LAB_0044ebb1
    //         0044ea2b     MOV        EBP,dword ptr [ESP + param_2]
    //         0044ea2f     MOV        EDX,dword ptr [EBP]
    //         0044ea32     TEST       EDX,EDX
    //         0044ea34     JL         LAB_0044ebb1
    //         0044ea3a     MOV        EAX,dword ptr [EBP + 0x4]
    //         0044ea3d     TEST       EAX,EAX
    //         0044ea3f     JL         LAB_0044ebb1
    //         0044ea45     CMP        EDX,EBX
    //         0044ea47     JGE        LAB_0044ebb1
    //         0044ea4d     CMP        EAX,this
    //         0044ea4f     JGE        LAB_0044ebb1
    //                              infmap.cpp:405 (12)
    //         0044ea55     CMP        ESI,EDX
    //         0044ea57     MOV        dword ptr [ESP + local_14],ESI
    //         0044ea5b     JG         LAB_0044eba4
    //                               LAB_0044ea61                                                 XREF[1]:     0044eb9e(j)  
    //                              infmap.cpp:406 (19)
    //         0044ea61     MOV        this,dword ptr [ESP + param_1]
    //         0044ea65     MOV        this,dword ptr [ECX + this->xSizeValue]
    //         0044ea68     CMP        this,EAX
    //         0044ea6a     MOV        dword ptr [ESP + local_1c],this
    //         0044ea6e     JG         LAB_0044eb94
    //                              infmap.cpp:412 (69)
    //         0044ea74     MOV        EDX,dword ptr [EDI + 0x18]
    //         0044ea77     MOV        EAX,dword ptr [EDI + 0xc]
    //         0044ea7a     MOV        dword ptr [ESP + i],EDX
    //         0044ea7e     MOV        EDX,ESI
    //         0044ea80     MOV        dword ptr [ESP + local_8],EAX
    //         0044ea84     SUB        EDX,EAX
    //         0044ea86     LEA        EAX,[this->_padding_*0x4 + 0x0]
    //         0044ea8d     MOV        this,dword ptr [EDI + 0x10]
    //         0044ea90     MOV        dword ptr [ESP + local_4],EDX
    //         0044ea94     MOV        dword ptr [ESP + j],EAX
    //         0044ea98     SHL        this,0x2
    //                               LAB_0044ea9b                                                 XREF[1]:     0044eb8e(j)  
    //         0044ea9b     MOV        EAX,dword ptr [ESP + j]
    //         0044ea9f     MOV        EBX,dword ptr [ESP + i]
    //         0044eaa3     SUB        EAX,this
    //         0044eaa5     MOV        EAX,dword ptr [EAX + EBX*0x1]
    //         0044eaa8     XOR        EBX,EBX
    //         0044eaaa     MOV        BL,byte ptr [EAX + EDX*0x1]
    //         0044eaad     MOV        EAX,dword ptr [ESP + param_3]
    //         0044eab1     CMP        EBX,EAX
    //         0044eab3     JL         LAB_0044eb75
    //                              infmap.cpp:422 (6)
    //         0044eab9     MOV        EBX,dword ptr [ESP + local_1c]
    //         0044eabd     MOV        EDI,ESI
    //                              infmap.cpp:458 (6)
    //         0044eabf     MOV        ESI,dword ptr [ESP + j]
    //         0044eac3     XOR        EBP,EBP
    //                               LAB_0044eac5                                                 XREF[1]:     0044eb5f(j)  
    //                              infmap.cpp:425 (12)
    //         0044eac5     CMP        EBP,0x7
    //         0044eac8     JA         switchD_0044eaca::default
    //                               switchD_0044eaca::switchD
    //         0044eaca     JMP        dword ptr [EBP*0x4 + ->switchD_0044eaca::caseD   = 0044ead1
    //                                                                                  = 0044ebbd
    //                               switchD_0044eaca::caseD_0                                    XREF[2]:     0044eaca(j), 0044ebd4(*)  
    //                              infmap.cpp:426 (1)
    //         0044ead1     DEC        EDI
    //                               switchD_0044eaca::caseD_7                                    XREF[2]:     0044eaca(j), 0044ebf0(*)  
    //                              infmap.cpp:433 (4)
    //         0044ead2     DEC        EBX
    //         0044ead3     SUB        ESI,0x4
    //                               switchD_0044eaca::default                                    XREF[4]:     0044eac8(j), 0044ebbe(j), 
    //                                                                                                         0044ebc7(j), 0044ebcd(j)  
    //                              infmap.cpp:435 (24)
    //         0044ead6     MOV        EAX,dword ptr [ESP + param_6]
    //         0044eada     TEST       EAX,EAX
    //         0044eadc     JNZ        LAB_0044eaee
    //         0044eade     MOV        EAX,EBP
    //         0044eae0     CDQ
    //         0044eae1     XOR        EAX,EDX
    //         0044eae3     SUB        EAX,EDX
    //         0044eae5     AND        EAX,0x1
    //         0044eae8     XOR        EAX,EDX
    //         0044eaea     SUB        EAX,EDX
    //         0044eaec     JZ         LAB_0044eb5b
    //                               LAB_0044eaee                                                 XREF[1]:     0044eadc(j)  
    //                              infmap.cpp:438 (20)
    //         0044eaee     TEST       EDI,EDI
    //         0044eaf0     JL         LAB_0044eb23
    //         0044eaf2     CMP        EDI,dword ptr [ESP + local_10]
    //         0044eaf6     JGE        LAB_0044eb23
    //         0044eaf8     TEST       EBX,EBX
    //         0044eafa     JL         LAB_0044eb23
    //         0044eafc     CMP        EBX,dword ptr [ESP + local_c]
    //         0044eb00     JGE        LAB_0044eb23
    //                              infmap.cpp:449 (33)
    //         0044eb02     MOV        EDX,dword ptr [ESP + i]
    //         0044eb06     MOV        EAX,ESI
    //         0044eb08     SUB        EAX,this
    //         0044eb0a     MOV        EAX,dword ptr [EAX + EDX*0x1]
    //         0044eb0d     MOV        EDX,dword ptr [ESP + local_8]
    //         0044eb11     ADD        EAX,EDI
    //         0044eb13     SUB        EAX,EDX
    //         0044eb15     XOR        EDX,EDX
    //         0044eb17     MOV        DL,byte ptr [EAX]
    //         0044eb19     MOV        EAX,dword ptr [ESP + param_3]
    //         0044eb1d     CMP        EDX,EAX
    //         0044eb1f     JL         LAB_0044eb5b
    //         0044eb21     JMP        LAB_0044eb54
    //                               LAB_0044eb23                                                 XREF[4]:     0044eaf0(j), 0044eaf6(j), 
    //                                                                                                         0044eafa(j), 0044eb00(j)  
    //                              infmap.cpp:440 (24)
    //         0044eb23     CMP        dword ptr [ESP + param_4],0x1
    //         0044eb28     JNZ        LAB_0044eb3d
    //         0044eb2a     MOV        EAX,EBP
    //         0044eb2c     CDQ
    //         0044eb2d     XOR        EAX,EDX
    //         0044eb2f     SUB        EAX,EDX
    //         0044eb31     AND        EAX,0x1
    //         0044eb34     XOR        EAX,EDX
    //         0044eb36     SUB        EAX,EDX
    //         0044eb38     CMP        EAX,0x1
    //                              infmap.cpp:442 (2)
    //         0044eb3b     JZ         LAB_0044eb54
    //                               LAB_0044eb3d                                                 XREF[1]:     0044eb28(j)  
    //                              infmap.cpp:443 (23)
    //         0044eb3d     CMP        dword ptr [ESP + param_5],0x1
    //         0044eb42     JNZ        LAB_0044eb5b
    //         0044eb44     MOV        EAX,EBP
    //         0044eb46     CDQ
    //         0044eb47     XOR        EAX,EDX
    //         0044eb49     SUB        EAX,EDX
    //         0044eb4b     AND        EAX,0x1
    //         0044eb4e     XOR        EAX,EDX
    //         0044eb50     SUB        EAX,EDX
    //         0044eb52     JNZ        LAB_0044eb5b
    //                               LAB_0044eb54                                                 XREF[2]:     0044eb21(j), 0044eb3b(j)  
    //                              infmap.cpp:444 (64)
    //         0044eb54     MOV        EAX,dword ptr [ESP + local_24]
    //         0044eb58     INC        dword ptr [EAX + 0x20]
    //                               LAB_0044eb5b                                                 XREF[4]:     0044eaec(j), 0044eb1f(j), 
    //                                                                                                         0044eb42(j), 0044eb52(j)  
    //         0044eb5b     INC        EBP
    //         0044eb5c     CMP        EBP,0x8
    //         0044eb5f     JL         LAB_0044eac5
    //         0044eb65     MOV        EBP,dword ptr [ESP + param_2]
    //         0044eb69     MOV        EDI,dword ptr [ESP + local_24]
    //         0044eb6d     MOV        ESI,dword ptr [ESP + local_14]
    //         0044eb71     MOV        EDX,dword ptr [ESP + local_4]
    //                               LAB_0044eb75                                                 XREF[1]:     0044eab3(j)  
    //         0044eb75     MOV        EAX,dword ptr [ESP + j]
    //         0044eb79     MOV        EBX,dword ptr [ESP + local_1c]
    //         0044eb7d     ADD        EAX,0x4
    //         0044eb80     INC        EBX
    //         0044eb81     MOV        dword ptr [ESP + j],EAX
    //         0044eb85     MOV        EAX,dword ptr [EBP + 0x4]
    //         0044eb88     CMP        EBX,EAX
    //         0044eb8a     MOV        dword ptr [ESP + local_1c],EBX
    //         0044eb8e     JLE        LAB_0044ea9b
    //                               LAB_0044eb94                                                 XREF[1]:     0044ea6e(j)  
    //                              infmap.cpp:405 (16)
    //         0044eb94     MOV        this,dword ptr [EBP]
    //         0044eb97     INC        ESI
    //         0044eb98     CMP        ESI,this
    //         0044eb9a     MOV        dword ptr [ESP + local_14],ESI
    //         0044eb9e     JLE        LAB_0044ea61
    //                               LAB_0044eba4                                                 XREF[1]:     0044ea5b(j)  
    //                              infmap.cpp:457 (3)
    //         0044eba4     MOV        EAX,dword ptr [EDI + 0x20]
    //                              infmap.cpp:458 (22)
    //         0044eba7     POP        EDI
    //         0044eba8     POP        ESI
    //         0044eba9     POP        EBP
    //         0044ebaa     POP        EBX
    //         0044ebab     ADD        ESP,0x24
    //         0044ebae     RET        0x18
    //                               LAB_0044ebb1                                                 XREF[8]:     0044e9fc(j), 0044ea07(j), 
    //                                                                                                         0044ea16(j), 0044ea25(j), 
    //                                                                                                         0044ea34(j), 0044ea3f(j), 
    //                                                                                                         0044ea47(j), 0044ea4f(j)  
    //         0044ebb1     POP        EDI
    //         0044ebb2     POP        ESI
    //         0044ebb3     POP        EBP
    //         0044ebb4     XOR        EAX,EAX
    //         0044ebb6     POP        EBX
    //         0044ebb7     ADD        ESP,0x24
    //         0044ebba     RET        0x18
    //                               switchD_0044eaca::caseD_2                                    XREF[3]:     0044eaca(j), 0044ebd8(*), 
    //                               switchD_0044eaca::caseD_1                                                 0044ebdc(*)  
    //                              infmap.cpp:428 (6)
    //         0044ebbd     INC        EDI
    //         0044ebbe     JMP        switchD_0044eaca::default
    //                               switchD_0044eaca::caseD_4                                    XREF[3]:     0044eaca(j), 0044ebe0(*), 
    //                               switchD_0044eaca::caseD_3                                                 0044ebe4(*)  
    //                              infmap.cpp:430 (9)
    //         0044ebc3     INC        EBX
    //         0044ebc4     ADD        ESI,0x4
    //         0044ebc7     JMP        switchD_0044eaca::default
    //                               switchD_0044eaca::caseD_6                                    XREF[3]:     0044eaca(j), 0044ebe8(*), 
    //                               switchD_0044eaca::caseD_5                                                 0044ebec(*)  
    //                              infmap.cpp:432 (6)
    //         0044ebcc     DEC        EDI
    //         0044ebcd     JMP        switchD_0044eaca::default
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_0044ebd2()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0044ebd2
    //                              infmap.cpp:458 (34)
    //         0044ebd2     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0044eaca::switchdataD_0044ebd4                       XREF[1]:     setConnectionCount:0044eaca(R)  
    //         0044ebd4     addr       switchD_0044eaca::caseD_0
    //                               PTR_caseD_1_0044ebd8                                         XREF[1]:     setConnectionCount:0044eaca(R)  
    //         0044ebd8     addr       switchD_0044eaca::caseD_1
    //         0044ebdc     addr       switchD_0044eaca::caseD_1
    //         0044ebe0     addr       switchD_0044eaca::caseD_3
    //         0044ebe4     addr       switchD_0044eaca::caseD_3
    //         0044ebe8     addr       switchD_0044eaca::caseD_5
    //         0044ebec     addr       switchD_0044eaca::caseD_5
    //         0044ebf0     addr       switchD_0044eaca::caseD_7
    //         0044ebf4     ??         90h
    //         0044ebf5     ??         90h
    //         0044ebf6     ??         90h
    //         0044ebf7     ??         90h
    //         0044ebf8     ??         90h
    //         0044ebf9     ??         90h
    //         0044ebfa     ??         90h
    //         0044ebfb     ??         90h
    //         0044ebfc     ??         90h
    //         0044ebfd     ??         90h
    //         0044ebfe     ??         90h
    //         0044ebff     ??         90h
    //                              * public: int __thiscall InfluenceMap::coverageIncluding(struct XYPoint const &,struct XYPoint const... *
    //                              int __thiscall coverageIncluding(InfluenceMap * this, XYPoint * para
    //              int               EAX:4          <RETURN>
    //              InfluenceMap *    ECX:4 (auto)   this
    //              XYPoint *         Stack[0x4]:4   param_1                   XREF[4]:     0044ec0b(R), 0044ec78(W), 0044ece0(R), 0044ecf3(W)  
    //              XYPoint *         Stack[0x8]:4   param_2                   XREF[3]:     0044ec45(R), 0044ec4d(W), 0044ece8(R)  
    //              uchar             Stack[0xc]:1   param_3                   XREF[2]:     0044eca4(R), 0044ecc4(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[1]:     0044ecb8(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0044ec5c(W), 0044ecec(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0044ec25(W), 0044ece4(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0044ec16(W), 0044ecdc(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[3]:     0044ec07(W), 0044ecd2(RW), 0044ecf9(R)  
    //              int               Stack[-0x14]:4 rVal
    //                               ?coverageIncluding@InfluenceMap@@QAEHABUXYPoint@@0EE@Z
    //                               InfluenceMap::coverageIncluding
    //                              infmap.cpp:464 (3)
    //         0044ec00     SUB        ESP,0x10
    //                              infmap.cpp:465 (8)
    //         0044ec03     MOV        EAX,dword ptr [ECX + this->coverageCountValue]
    //         0044ec06     PUSH       EBX
    //         0044ec07     MOV        dword ptr [ESP + local_10],EAX
    //                              infmap.cpp:469 (107)
    //         0044ec0b     MOV        EAX,dword ptr [ESP + param_1]
    //         0044ec0f     PUSH       EBP
    //         0044ec10     PUSH       ESI
    //         0044ec11     MOV        ESI,dword ptr [EAX]
    //         0044ec13     PUSH       EDI
    //         0044ec14     TEST       ESI,ESI
    //         0044ec16     MOV        dword ptr [ESP + local_c],this
    //         0044ec1a     JL         LAB_0044ed07
    //         0044ec20     MOV        EDX,dword ptr [EAX + 0x4]
    //         0044ec23     TEST       EDX,EDX
    //         0044ec25     MOV        dword ptr [ESP + local_8],EDX
    //         0044ec29     JL         LAB_0044ed07
    //         0044ec2f     MOV        EBP,dword ptr [ECX + this->xSizeValue]
    //         0044ec32     CMP        ESI,EBP
    //         0044ec34     JGE        LAB_0044ed07
    //         0044ec3a     MOV        EBX,dword ptr [ECX + this->ySizeValue]
    //         0044ec3d     CMP        EDX,EBX
    //         0044ec3f     JGE        LAB_0044ed07
    //         0044ec45     MOV        EAX,dword ptr [ESP + param_2]
    //         0044ec49     MOV        EDI,dword ptr [EAX]
    //         0044ec4b     TEST       EDI,EDI
    //         0044ec4d     MOV        dword ptr [ESP + param_2],EDI
    //         0044ec51     JL         LAB_0044ed07
    //         0044ec57     MOV        EAX,dword ptr [EAX + 0x4]
    //         0044ec5a     TEST       EAX,EAX
    //         0044ec5c     MOV        dword ptr [ESP + local_4],EAX
    //         0044ec60     JL         LAB_0044ed07
    //         0044ec66     CMP        EDI,EBP
    //         0044ec68     JGE        LAB_0044ed07
    //         0044ec6e     CMP        EAX,EBX
    //         0044ec70     JGE        LAB_0044ed07
    //                              infmap.cpp:475 (8)
    //         0044ec76     CMP        ESI,EDI
    //         0044ec78     MOV        dword ptr [ESP + param_1],ESI
    //         0044ec7c     JG         LAB_0044ecf9
    //                               LAB_0044ec7e                                                 XREF[1]:     0044ecf7(j)  
    //                              infmap.cpp:476 (4)
    //         0044ec7e     CMP        EDX,EAX
    //         0044ec80     JG         LAB_0044ecf0
    //                              infmap.cpp:478 (42)
    //         0044ec82     MOV        EDI,dword ptr [ECX + this->xReferencePointValue]
    //         0044ec85     MOV        EBP,dword ptr [ECX + this->rowValue]
    //         0044ec88     SUB        ESI,EDI
    //         0044ec8a     MOV        EDI,dword ptr [ECX + this->yReferencePointValue]
    //         0044ec8d     SUB        EAX,EDX
    //         0044ec8f     LEA        EBX,[EDX*0x4 + 0x0]
    //         0044ec96     SHL        EDI,0x2
    //         0044ec99     INC        EAX
    //                               LAB_0044ec9a                                                 XREF[1]:     0044ecda(j)  
    //         0044ec9a     MOV        EDX,EBX
    //         0044ec9c     SUB        EDX,EDI
    //         0044ec9e     MOV        this,dword ptr [EDX + EBP*0x1]
    //         0044eca1     MOV        DL,byte ptr [this->_padding_ + ESI*0x1]
    //         0044eca4     MOV        this,byte ptr [ESP + param_3]
    //         0044eca8     CMP        DL,this
    //         0044ecaa     JNC        LAB_0044ecd6
    //                              infmap.cpp:482 (38)
    //         0044ecac     MOV        EDX,EBX
    //         0044ecae     SUB        EDX,EDI
    //         0044ecb0     MOV        this,dword ptr [EDX + EBP*0x1]
    //         0044ecb3     XOR        EDX,EDX
    //         0044ecb5     MOV        DL,byte ptr [this->_padding_ + ESI*0x1]
    //         0044ecb8     MOV        this,dword ptr [ESP + param_4]
    //         0044ecbc     AND        this,0xff
    //         0044ecc2     ADD        EDX,this
    //         0044ecc4     MOV        this,dword ptr [ESP + param_3]
    //         0044ecc8     AND        this,0xff
    //         0044ecce     CMP        EDX,this
    //         0044ecd0     JL         LAB_0044ecd6
    //                              infmap.cpp:483 (39)
    //         0044ecd2     INC        dword ptr [ESP + local_10]
    //                               LAB_0044ecd6                                                 XREF[2]:     0044ecaa(j), 0044ecd0(j)  
    //         0044ecd6     ADD        EBX,0x4
    //         0044ecd9     DEC        EAX
    //         0044ecda     JNZ        LAB_0044ec9a
    //         0044ecdc     MOV        this,dword ptr [ESP + local_c]
    //         0044ece0     MOV        ESI,dword ptr [ESP + param_1]
    //         0044ece4     MOV        EDX,dword ptr [ESP + local_8]
    //         0044ece8     MOV        EDI,dword ptr [ESP + param_2]
    //         0044ecec     MOV        EAX,dword ptr [ESP + local_4]
    //                               LAB_0044ecf0                                                 XREF[1]:     0044ec80(j)  
    //         0044ecf0     INC        ESI
    //         0044ecf1     CMP        ESI,EDI
    //         0044ecf3     MOV        dword ptr [ESP + param_1],ESI
    //         0044ecf7     JLE        LAB_0044ec7e
    //                               LAB_0044ecf9                                                 XREF[1]:     0044ec7c(j)  
    //                              infmap.cpp:487 (4)
    //         0044ecf9     MOV        EAX,dword ptr [ESP + local_10]
    //                              infmap.cpp:488 (22)
    //         0044ecfd     POP        EDI
    //         0044ecfe     POP        ESI
    //         0044ecff     POP        EBP
    //         0044ed00     POP        EBX
    //         0044ed01     ADD        ESP,0x10
    //         0044ed04     RET        0x10
    //                               LAB_0044ed07                                                 XREF[8]:     0044ec1a(j), 0044ec29(j), 
    //                                                                                                         0044ec34(j), 0044ec3f(j), 
    //                                                                                                         0044ec51(j), 0044ec60(j), 
    //                                                                                                         0044ec68(j), 0044ec70(j)  
    //         0044ed07     POP        EDI
    //         0044ed08     POP        ESI
    //         0044ed09     POP        EBP
    //         0044ed0a     XOR        EAX,EAX
    //         0044ed0c     POP        EBX
    //         0044ed0d     ADD        ESP,0x10
    //         0044ed10     RET        0x10
    //         0044ed13     ??         90h
    //         0044ed14     NOP
    //         0044ed15     NOP
    //         0044ed16     NOP
    //         0044ed17     NOP
    //         0044ed18     NOP
    //         0044ed19     NOP
    //         0044ed1a     NOP
    //         0044ed1b     NOP
    //         0044ed1c     NOP
    //         0044ed1d     NOP
    //         0044ed1e     NOP
    //         0044ed1f     NOP
    //                              * public: int __thiscall InfluenceMap::connectionsIncluding(struct XYPoint const &,struct XYPoint co... *
    //                              int __thiscall connectionsIncluding(InfluenceMap * this, XYPoint * p
    //              int               EAX:4          <RETURN>
    //              InfluenceMap *    ECX:4 (auto)   this
    //              XYPoint *         Stack[0x4]:4   param_1                   XREF[6]:     0044ed23(R), 0044edb6(W), 0044ee3d(R), 0044eec1(R), 
    //                                                                                     0044ef8e(R), 0044ef9c(W)  
    //              XYPoint *         Stack[0x8]:4   param_2                   XREF[6]:     0044ed6f(R), 0044edf8(W), 0044ee1f(R), 0044eec5(R), 
    //                                                                                     0044ef92(R), 0044efa0(W)  
    //              uchar             Stack[0xc]:1   param_3                   XREF[3]:     0044ede1(R), 0044ee27(R), 0044ef29(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[1]:     0044edd0(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[2]:     0044ee7d(R), 0044ef3a(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[2]:     0044ee97(R), 0044ef54(R)  
    //              int               Stack[0x1c]:4  param_7                   XREF[2]:     0044ee51(R), 0044eeea(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0044edd4(W), 0044ef8a(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0044ed86(W), 0044ef86(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0044ed34(W), 0044ef7e(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     0044edca(W), 0044ef21(R)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[2]:     0044edea(W), 0044ee13(R)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[2]:     0044eddd(W), 0044ee0d(R)  
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[2]:     0044ed47(W), 0044edb0(R)  
    //              undefined4        Stack[-0x20]:4 local_20                  XREF[3]:     0044ed77(W), 0044ed90(R), 0044efaa(R)  
    //              undefined4        Stack[-0x24]:4 local_24                  XREF[3]:     0044ed65(W), 0044ee77(R), 0044ef10(R)  
    //              undefined4        Stack[-0x28]:4 local_28                  XREF[3]:     0044ed56(W), 0044ee6d(R), 0044ef06(R)  
    //              undefined4        Stack[-0x2c]:4 local_2c                  XREF[4]:     0044edc3(W), 0044edff(R), 0044ee23(R), 0044ef16(R)  
    //              undefined4        Stack[-0x30]:4 local_30                  XREF[5]:     0044eda6(W), 0044ee39(R), 0044eebd(R), 0044efae(R), 
    //                                                                                     0044efb5(W)  
    //              int               Stack[-0x34]:4 i                         XREF[6]:     0044ed38(W), 0044eeb9(W), 0044ef31(R), 0044ef6b(R), 
    //                                                                                     0044ef70(W), 0044ef82(R)  
    //              int               Stack[-0x38]:4 rVal
    //                               ?connectionsIncluding@InfluenceMap@@QAEHABUXYPoint@@0EEHHH@Z XREF[1]:     influencePlaceStructure:004dbcab(c
    //                               InfluenceMap::connectionsIncluding
    //                              infmap.cpp:495 (3)
    //         0044ed20     SUB        ESP,0x34
    //                              infmap.cpp:500 (129)
    //         0044ed23     MOV        EAX,dword ptr [ESP + param_1]
    //         0044ed27     PUSH       EBX
    //         0044ed28     PUSH       EBP
    //         0044ed29     PUSH       ESI
    //         0044ed2a     MOV        EDX,dword ptr [EAX]
    //         0044ed2c     MOV        ESI,this
    //         0044ed2e     TEST       EDX,EDX
    //         0044ed30     MOV        EBP,dword ptr [ESI + 0x20]
    //         0044ed33     PUSH       EDI
    //         0044ed34     MOV        dword ptr [ESP + local_c],ESI
    //         0044ed38     MOV        dword ptr [ESP + i],EBP
    //         0044ed3c     JL         LAB_0044efcb
    //         0044ed42     MOV        EAX,dword ptr [EAX + 0x4]
    //         0044ed45     TEST       EAX,EAX
    //         0044ed47     MOV        dword ptr [ESP + local_1c],EAX
    //         0044ed4b     JL         LAB_0044efcb
    //         0044ed51     MOV        EBX,dword ptr [ESI + 0x4]
    //         0044ed54     CMP        EDX,EBX
    //         0044ed56     MOV        dword ptr [ESP + local_28],EBX
    //         0044ed5a     JGE        LAB_0044efcb
    //         0044ed60     MOV        this,dword ptr [ESI + 0x8]
    //         0044ed63     CMP        EAX,this
    //         0044ed65     MOV        dword ptr [ESP + local_24],this
    //         0044ed69     JGE        LAB_0044efcb
    //         0044ed6f     MOV        EAX,dword ptr [ESP + param_2]
    //         0044ed73     MOV        EDI,dword ptr [EAX]
    //         0044ed75     TEST       EDI,EDI
    //         0044ed77     MOV        dword ptr [ESP + local_20],EDI
    //         0044ed7b     JL         LAB_0044efcb
    //         0044ed81     MOV        EDI,dword ptr [EAX + 0x4]
    //         0044ed84     TEST       EDI,EDI
    //         0044ed86     MOV        dword ptr [ESP + local_8],EDI
    //         0044ed8a     JL         LAB_0044efcb
    //         0044ed90     MOV        EAX,dword ptr [ESP + local_20]
    //         0044ed94     CMP        EAX,EBX
    //         0044ed96     JGE        LAB_0044efcb
    //         0044ed9c     CMP        EDI,this
    //         0044ed9e     JGE        LAB_0044efcb
    //                              infmap.cpp:503 (12)
    //         0044eda4     CMP        EDX,EAX
    //         0044eda6     MOV        dword ptr [ESP + local_30],EDX
    //         0044edaa     JG         LAB_0044efbf
    //                               LAB_0044edb0                                                 XREF[1]:     0044efb9(j)  
    //                              infmap.cpp:504 (16)
    //         0044edb0     MOV        this,dword ptr [ESP + local_1c]
    //         0044edb4     CMP        this,EDI
    //         0044edb6     MOV        dword ptr [ESP + param_1],this
    //         0044edba     JG         LAB_0044efb2
    //                              infmap.cpp:507 (95)
    //         0044edc0     MOV        EAX,dword ptr [ESI + 0x18]
    //         0044edc3     MOV        dword ptr [ESP + local_2c],EAX
    //         0044edc7     MOV        EAX,dword ptr [ESI + 0xc]
    //         0044edca     MOV        dword ptr [ESP + local_10],EAX
    //         0044edce     SUB        EDX,EAX
    //         0044edd0     MOV        EAX,dword ptr [ESP + param_4]
    //         0044edd4     MOV        dword ptr [ESP + local_4],EDX
    //         0044edd8     AND        EAX,0xff
    //         0044eddd     MOV        dword ptr [ESP + local_18],EAX
    //         0044ede1     MOV        EAX,dword ptr [ESP + param_3]
    //         0044ede5     AND        EAX,0xff
    //         0044edea     MOV        dword ptr [ESP + local_14],EAX
    //         0044edee     LEA        EAX,[this->_padding_*0x4 + 0x0]
    //         0044edf5     MOV        this,dword ptr [ESI + 0x10]
    //         0044edf8     MOV        dword ptr [ESP + param_2],EAX
    //         0044edfc     SHL        this,0x2
    //                               LAB_0044edff                                                 XREF[1]:     0044efa4(j)  
    //         0044edff     MOV        EBX,dword ptr [ESP + local_2c]
    //         0044ee03     SUB        EAX,this
    //         0044ee05     MOV        EAX,dword ptr [EAX + EBX*0x1]
    //         0044ee08     XOR        EBX,EBX
    //         0044ee0a     MOV        BL,byte ptr [EAX + EDX*0x1]
    //         0044ee0d     MOV        EAX,dword ptr [ESP + local_18]
    //         0044ee11     ADD        EBX,EAX
    //         0044ee13     MOV        EAX,dword ptr [ESP + local_14]
    //         0044ee17     CMP        EBX,EAX
    //         0044ee19     JL         LAB_0044ef8e
    //                              infmap.cpp:514 (26)
    //         0044ee1f     MOV        EAX,dword ptr [ESP + param_2]
    //         0044ee23     MOV        ESI,dword ptr [ESP + local_2c]
    //         0044ee27     MOV        BL,byte ptr [ESP + param_3]
    //         0044ee2b     SUB        EAX,this
    //         0044ee2d     MOV        EAX,dword ptr [EAX + ESI*0x1]
    //         0044ee30     CMP        byte ptr [EAX + EDX*0x1],BL
    //         0044ee33     JC         LAB_0044eebd
    //                              infmap.cpp:515 (4)
    //         0044ee39     MOV        EDI,dword ptr [ESP + local_30]
    //                              infmap.cpp:516 (4)
    //         0044ee3d     MOV        EBX,dword ptr [ESP + param_1]
    //                              infmap.cpp:518 (2)
    //         0044ee41     XOR        ESI,ESI
    //                               LAB_0044ee43                                                 XREF[1]:     0044eeb7(j)  
    //                              infmap.cpp:519 (12)
    //         0044ee43     CMP        ESI,0x7
    //         0044ee46     JA         switchD_0044ee48::default
    //                               switchD_0044ee48::switchD
    //         0044ee48     JMP        dword ptr [ESI*0x4 + ->switchD_0044ee48::caseD   = 0044ee4f
    //                                                                                  = 0044efd7
    //                               switchD_0044ee48::caseD_0                                    XREF[2]:     0044ee48(j), 0044efec(*)  
    //                              infmap.cpp:520 (1)
    //         0044ee4f     DEC        EDI
    //                               switchD_0044ee48::caseD_7                                    XREF[2]:     0044ee48(j), 0044f008(*)  
    //                              infmap.cpp:527 (1)
    //         0044ee50     DEC        EBX
    //                               switchD_0044ee48::default                                    XREF[4]:     0044ee46(j), 0044efd8(j), 
    //                                                                                                         0044efde(j), 0044efe4(j)  
    //                              infmap.cpp:529 (24)
    //         0044ee51     MOV        EAX,dword ptr [ESP + param_7]
    //         0044ee55     TEST       EAX,EAX
    //         0044ee57     JNZ        LAB_0044ee69
    //         0044ee59     MOV        EAX,ESI
    //         0044ee5b     CDQ
    //         0044ee5c     XOR        EAX,EDX
    //         0044ee5e     SUB        EAX,EDX
    //         0044ee60     AND        EAX,0x1
    //         0044ee63     XOR        EAX,EDX
    //         0044ee65     SUB        EAX,EDX
    //         0044ee67     JZ         LAB_0044eeb3
    //                               LAB_0044ee69                                                 XREF[1]:     0044ee57(j)  
    //                              infmap.cpp:532 (20)
    //         0044ee69     TEST       EDI,EDI
    //         0044ee6b     JL         LAB_0044ee7d
    //         0044ee6d     CMP        EDI,dword ptr [ESP + local_28]
    //         0044ee71     JGE        LAB_0044ee7d
    //         0044ee73     TEST       EBX,EBX
    //         0044ee75     JL         LAB_0044ee7d
    //         0044ee77     CMP        EBX,dword ptr [ESP + local_24]
    //         0044ee7b     JL         LAB_0044eeaf
    //                               LAB_0044ee7d                                                 XREF[3]:     0044ee6b(j), 0044ee71(j), 
    //                                                                                                         0044ee75(j)  
    //                              infmap.cpp:534 (24)
    //         0044ee7d     CMP        dword ptr [ESP + param_5],0x1
    //         0044ee82     JNZ        LAB_0044ee97
    //         0044ee84     MOV        EAX,ESI
    //         0044ee86     CDQ
    //         0044ee87     XOR        EAX,EDX
    //         0044ee89     SUB        EAX,EDX
    //         0044ee8b     AND        EAX,0x1
    //         0044ee8e     XOR        EAX,EDX
    //         0044ee90     SUB        EAX,EDX
    //         0044ee92     CMP        EAX,0x1
    //                              infmap.cpp:536 (2)
    //         0044ee95     JZ         LAB_0044eeae
    //                               LAB_0044ee97                                                 XREF[1]:     0044ee82(j)  
    //                              infmap.cpp:537 (23)
    //         0044ee97     CMP        dword ptr [ESP + param_6],0x1
    //         0044ee9c     JNZ        LAB_0044eeaf
    //         0044ee9e     MOV        EAX,ESI
    //         0044eea0     CDQ
    //         0044eea1     XOR        EAX,EDX
    //         0044eea3     SUB        EAX,EDX
    //         0044eea5     AND        EAX,0x1
    //         0044eea8     XOR        EAX,EDX
    //         0044eeaa     SUB        EAX,EDX
    //         0044eeac     JNZ        LAB_0044eeaf
    //                               LAB_0044eeae                                                 XREF[1]:     0044ee95(j)  
    //                              infmap.cpp:538 (1)
    //         0044eeae     DEC        EBP
    //                               LAB_0044eeaf                                                 XREF[3]:     0044ee7b(j), 0044ee9c(j), 
    //                                                                                                         0044eeac(j)  
    //                              infmap.cpp:542 (4)
    //         0044eeaf     TEST       EBP,EBP
    //         0044eeb1     JLE        LAB_0044eeb9
    //                               LAB_0044eeb3                                                 XREF[1]:     0044ee67(j)  
    //                              infmap.cpp:518 (6)
    //         0044eeb3     INC        ESI
    //         0044eeb4     CMP        ESI,0x8
    //         0044eeb7     JL         LAB_0044ee43
    //                               LAB_0044eeb9                                                 XREF[1]:     0044eeb1(j)  
    //                              infmap.cpp:535 (4)
    //         0044eeb9     MOV        dword ptr [ESP + i],EBP
    //                               LAB_0044eebd                                                 XREF[1]:     0044ee33(j)  
    //                              infmap.cpp:550 (4)
    //         0044eebd     MOV        EDI,dword ptr [ESP + local_30]
    //                              infmap.cpp:551 (8)
    //         0044eec1     MOV        EBX,dword ptr [ESP + param_1]
    //         0044eec5     MOV        ESI,dword ptr [ESP + param_2]
    //                              infmap.cpp:553 (2)
    //         0044eec9     XOR        EBP,EBP
    //                               LAB_0044eecb                                                 XREF[1]:     0044ef78(j)  
    //                              infmap.cpp:554 (12)
    //         0044eecb     CMP        EBP,0x7
    //         0044eece     JA         switchD_0044eed0::default
    //                               switchD_0044eed0::switchD
    //         0044eed0     JMP        dword ptr [EBP*0x4 + ->switchD_0044eed0::caseD   = 0044eed7
    //                                                                                  = 0044eeda
    //                               switchD_0044eed0::caseD_0                                    XREF[2]:     0044eed0(j), 0044f00c(*)  
    //                              infmap.cpp:555 (3)
    //         0044eed7     DEC        EDI
    //         0044eed8     JMP        switchD_0044eed0::caseD_7
    //                               switchD_0044eed0::caseD_2                                    XREF[3]:     0044eed0(j), 0044f010(*), 
    //                               switchD_0044eed0::caseD_1                                                 0044f014(*)  
    //                              infmap.cpp:557 (3)
    //         0044eeda     INC        EDI
    //         0044eedb     JMP        switchD_0044eed0::default
    //                               switchD_0044eed0::caseD_4                                    XREF[3]:     0044eed0(j), 0044f018(*), 
    //                               switchD_0044eed0::caseD_3                                                 0044f01c(*)  
    //                              infmap.cpp:559 (6)
    //         0044eedd     INC        EBX
    //         0044eede     ADD        ESI,0x4
    //         0044eee1     JMP        switchD_0044eed0::default
    //                               switchD_0044eed0::caseD_6                                    XREF[3]:     0044eed0(j), 0044f020(*), 
    //                               switchD_0044eed0::caseD_5                                                 0044f024(*)  
    //                              infmap.cpp:561 (3)
    //         0044eee3     DEC        EDI
    //         0044eee4     JMP        switchD_0044eed0::default
    //                               switchD_0044eed0::caseD_7                                    XREF[3]:     0044eed0(j), 0044eed8(j), 
    //                                                                                                         0044f028(*)  
    //                              infmap.cpp:562 (4)
    //         0044eee6     DEC        EBX
    //         0044eee7     SUB        ESI,0x4
    //                               switchD_0044eed0::default                                    XREF[4]:     0044eece(j), 0044eedb(j), 
    //                                                                                                         0044eee1(j), 0044eee4(j)  
    //                              infmap.cpp:564 (24)
    //         0044eeea     MOV        EAX,dword ptr [ESP + param_7]
    //         0044eeee     TEST       EAX,EAX
    //         0044eef0     JNZ        LAB_0044ef02
    //         0044eef2     MOV        EAX,EBP
    //         0044eef4     CDQ
    //         0044eef5     XOR        EAX,EDX
    //         0044eef7     SUB        EAX,EDX
    //         0044eef9     AND        EAX,0x1
    //         0044eefc     XOR        EAX,EDX
    //         0044eefe     SUB        EAX,EDX
    //         0044ef00     JZ         LAB_0044ef74
    //                               LAB_0044ef02                                                 XREF[1]:     0044eef0(j)  
    //                              infmap.cpp:570 (20)
    //         0044ef02     TEST       EDI,EDI
    //         0044ef04     JL         LAB_0044ef3a
    //         0044ef06     CMP        EDI,dword ptr [ESP + local_28]
    //         0044ef0a     JGE        LAB_0044ef3a
    //         0044ef0c     TEST       EBX,EBX
    //         0044ef0e     JL         LAB_0044ef3a
    //         0044ef10     CMP        EBX,dword ptr [ESP + local_24]
    //         0044ef14     JGE        LAB_0044ef3a
    //                              infmap.cpp:578 (27)
    //         0044ef16     MOV        EDX,dword ptr [ESP + local_2c]
    //         0044ef1a     MOV        EAX,ESI
    //         0044ef1c     SUB        EAX,this
    //         0044ef1e     MOV        EAX,dword ptr [EAX + EDX*0x1]
    //         0044ef21     MOV        EDX,dword ptr [ESP + local_10]
    //         0044ef25     ADD        EAX,EDI
    //         0044ef27     SUB        EAX,EDX
    //         0044ef29     MOV        DL,byte ptr [ESP + param_3]
    //         0044ef2d     CMP        byte ptr [EAX],DL
    //         0044ef2f     JC         LAB_0044ef74
    //                              infmap.cpp:579 (9)
    //         0044ef31     MOV        EAX,dword ptr [ESP + i]
    //         0044ef35     ADD        EAX,0x2
    //         0044ef38     JMP        LAB_0044ef70
    //                               LAB_0044ef3a                                                 XREF[4]:     0044ef04(j), 0044ef0a(j), 
    //                                                                                                         0044ef0e(j), 0044ef14(j)  
    //                              infmap.cpp:572 (24)
    //         0044ef3a     CMP        dword ptr [ESP + param_5],0x1
    //         0044ef3f     JNZ        LAB_0044ef54
    //         0044ef41     MOV        EAX,EBP
    //         0044ef43     CDQ
    //         0044ef44     XOR        EAX,EDX
    //         0044ef46     SUB        EAX,EDX
    //         0044ef48     AND        EAX,0x1
    //         0044ef4b     XOR        EAX,EDX
    //         0044ef4d     SUB        EAX,EDX
    //         0044ef4f     CMP        EAX,0x1
    //                              infmap.cpp:574 (2)
    //         0044ef52     JZ         LAB_0044ef6b
    //                               LAB_0044ef54                                                 XREF[1]:     0044ef3f(j)  
    //                              infmap.cpp:575 (23)
    //         0044ef54     CMP        dword ptr [ESP + param_6],0x1
    //         0044ef59     JNZ        LAB_0044ef74
    //         0044ef5b     MOV        EAX,EBP
    //         0044ef5d     CDQ
    //         0044ef5e     XOR        EAX,EDX
    //         0044ef60     SUB        EAX,EDX
    //         0044ef62     AND        EAX,0x1
    //         0044ef65     XOR        EAX,EDX
    //         0044ef67     SUB        EAX,EDX
    //         0044ef69     JNZ        LAB_0044ef74
    //                               LAB_0044ef6b                                                 XREF[1]:     0044ef52(j)  
    //                              infmap.cpp:576 (9)
    //         0044ef6b     MOV        EAX,dword ptr [ESP + i]
    //         0044ef6f     DEC        EAX
    //                               LAB_0044ef70                                                 XREF[1]:     0044ef38(j)  
    //         0044ef70     MOV        dword ptr [ESP + i],EAX
    //                               LAB_0044ef74                                                 XREF[4]:     0044ef00(j), 0044ef2f(j), 
    //                                                                                                         0044ef59(j), 0044ef69(j)  
    //                              infmap.cpp:553 (75)
    //         0044ef74     INC        EBP
    //         0044ef75     CMP        EBP,0x8
    //         0044ef78     JL         LAB_0044eecb
    //         0044ef7e     MOV        ESI,dword ptr [ESP + local_c]
    //         0044ef82     MOV        EBP,dword ptr [ESP + i]
    //         0044ef86     MOV        EDI,dword ptr [ESP + local_8]
    //         0044ef8a     MOV        EDX,dword ptr [ESP + local_4]
    //                               LAB_0044ef8e                                                 XREF[1]:     0044ee19(j)  
    //         0044ef8e     MOV        EBX,dword ptr [ESP + param_1]
    //         0044ef92     MOV        EAX,dword ptr [ESP + param_2]
    //         0044ef96     INC        EBX
    //         0044ef97     ADD        EAX,0x4
    //         0044ef9a     CMP        EBX,EDI
    //         0044ef9c     MOV        dword ptr [ESP + param_1],EBX
    //         0044efa0     MOV        dword ptr [ESP + param_2],EAX
    //         0044efa4     JLE        LAB_0044edff
    //         0044efaa     MOV        EAX,dword ptr [ESP + local_20]
    //         0044efae     MOV        EDX,dword ptr [ESP + local_30]
    //                               LAB_0044efb2                                                 XREF[1]:     0044edba(j)  
    //         0044efb2     INC        EDX
    //         0044efb3     CMP        EDX,EAX
    //         0044efb5     MOV        dword ptr [ESP + local_30],EDX
    //         0044efb9     JLE        LAB_0044edb0
    //                               LAB_0044efbf                                                 XREF[1]:     0044edaa(j)  
    //                              infmap.cpp:584 (2)
    //         0044efbf     MOV        EAX,EBP
    //                              infmap.cpp:585 (22)
    //         0044efc1     POP        EDI
    //         0044efc2     POP        ESI
    //         0044efc3     POP        EBP
    //         0044efc4     POP        EBX
    //         0044efc5     ADD        ESP,0x34
    //         0044efc8     RET        0x1c
    //                               LAB_0044efcb                                                 XREF[8]:     0044ed3c(j), 0044ed4b(j), 
    //                                                                                                         0044ed5a(j), 0044ed69(j), 
    //                                                                                                         0044ed7b(j), 0044ed8a(j), 
    //                                                                                                         0044ed96(j), 0044ed9e(j)  
    //         0044efcb     POP        EDI
    //         0044efcc     POP        ESI
    //         0044efcd     POP        EBP
    //         0044efce     XOR        EAX,EAX
    //         0044efd0     POP        EBX
    //         0044efd1     ADD        ESP,0x34
    //         0044efd4     RET        0x1c
    //                               switchD_0044ee48::caseD_2                                    XREF[3]:     0044ee48(j), 0044eff0(*), 
    //                               switchD_0044ee48::caseD_1                                                 0044eff4(*)  
    //                              infmap.cpp:522 (6)
    //         0044efd7     INC        EDI
    //         0044efd8     JMP        switchD_0044ee48::default
    //                               switchD_0044ee48::caseD_4                                    XREF[3]:     0044ee48(j), 0044eff8(*), 
    //                               switchD_0044ee48::caseD_3                                                 0044effc(*)  
    //                              infmap.cpp:524 (6)
    //         0044efdd     INC        EBX
    //         0044efde     JMP        switchD_0044ee48::default
    //                               switchD_0044ee48::caseD_6                                    XREF[3]:     0044ee48(j), 0044f000(*), 
    //                               switchD_0044ee48::caseD_5                                                 0044f004(*)  
    //                              infmap.cpp:526 (6)
    //         0044efe3     DEC        EDI
    //         0044efe4     JMP        switchD_0044ee48::default
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_0044efe9()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0044efe9
    //                              infmap.cpp:585 (67)
    //         0044efe9     NOP
    //         0044efea     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0044ee48::switchdataD_0044efec                       XREF[1]:     connectionsIncluding:0044ee48(R)  
    //         0044efec     addr       switchD_0044ee48::caseD_0
    //                               PTR_caseD_1_0044eff0                                         XREF[1]:     connectionsIncluding:0044ee48(R)  
    //         0044eff0     addr       switchD_0044ee48::caseD_1
    //         0044eff4     addr       switchD_0044ee48::caseD_1
    //         0044eff8     addr       switchD_0044ee48::caseD_3
    //         0044effc     addr       switchD_0044ee48::caseD_3
    //         0044f000     addr       switchD_0044ee48::caseD_5
    //         0044f004     addr       switchD_0044ee48::caseD_5
    //         0044f008     addr       switchD_0044ee48::caseD_7
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0044eed0::switchdataD_0044f00c                       XREF[1]:     connectionsIncluding:0044eed0(R)  
    //         0044f00c     addr       switchD_0044eed0::caseD_0
    //                               PTR_caseD_1_0044f010                                         XREF[1]:     connectionsIncluding:0044eed0(R)  
    //         0044f010     addr       switchD_0044eed0::caseD_1
    //         0044f014     addr       switchD_0044eed0::caseD_1
    //         0044f018     addr       switchD_0044eed0::caseD_3
    //         0044f01c     addr       switchD_0044eed0::caseD_3
    //         0044f020     addr       switchD_0044eed0::caseD_5
    //         0044f024     addr       switchD_0044eed0::caseD_5
    //         0044f028     addr       switchD_0044eed0::caseD_7
    //         0044f02c     ??         90h
    //         0044f02d     ??         90h
    //         0044f02e     ??         90h
    //         0044f02f     ??         90h
    return 0;
}

void InfluenceMap::setUnchangeableLimit(uchar param_1) {
    /* TODO: Stub */
    //                              void __thiscall setUnchangeableLimit(InfluenceMap * this, uchar para
    //              void              <VOID>         <RETURN>
    //              InfluenceMap *    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     0044f030(R)  
    //                               ?setUnchangeableLimit@InfluenceMap@@QAEXE@Z                  XREF[1]:     setupInfluenceMap:004deeaf(c)  
    //                               InfluenceMap::setUnchangeableLimit
    //                              infmap.cpp:590 (8)
    //         0044f030     MOV        AL,byte ptr [ESP + param_1]
    //         0044f034     TEST       AL,AL
    //         0044f036     JBE        LAB_0044f03b
    //                              infmap.cpp:593 (3)
    //         0044f038     MOV        byte ptr [ECX + this->unchangeableLimitValue],AL
    //                               LAB_0044f03b                                                 XREF[1]:     0044f036(j)  
    //                              infmap.cpp:594 (3)
    //         0044f03b     RET        0x4
    //         0044f03e     ??         90h
    //         0044f03f     NOP
    return;
}

int InfluenceMap::maxValue() {
    /* TODO: Stub */
    //                              int __thiscall maxValue(InfluenceMap * this)
    //              int               EAX:4          <RETURN>
    //              InfluenceMap *    ECX:4 (auto)   this
    //                               ?maxValue@InfluenceMap@@QAEHXZ                               XREF[2]:     setupLOSMap:004e22e0(c), 
    //                               InfluenceMap::maxValue                                                    setupAttackMap:004e238b(c)  
    //                              infmap.cpp:599 (1)
    //         0044f040     PUSH       ESI
    //                              infmap.cpp:600 (8)
    //         0044f041     MOV        ESI,dword ptr [ECX + this->xSizeValue]
    //         0044f044     IMUL       ESI,dword ptr [ECX + this->ySizeValue]
    //         0044f048     PUSH       EDI
    //                              infmap.cpp:601 (5)
    //         0044f049     MOV        EDI,dword ptr [ECX + this->valueValue]
    //         0044f04c     XOR        EAX,EAX
    //                              infmap.cpp:602 (8)
    //         0044f04e     XOR        EDX,EDX
    //         0044f050     MOV        AL,byte ptr [EDI]
    //         0044f052     TEST       ESI,ESI
    //         0044f054     JLE        LAB_0044f066
    //                               LAB_0044f056                                                 XREF[1]:     0044f064(j)  
    //                              infmap.cpp:603 (9)
    //         0044f056     XOR        this,this
    //         0044f058     MOV        this,byte ptr [EDX + EDI*0x1]
    //         0044f05b     CMP        this,EAX
    //         0044f05d     JLE        LAB_0044f061
    //                              infmap.cpp:604 (2)
    //         0044f05f     MOV        EAX,this
    //                               LAB_0044f061                                                 XREF[1]:     0044f05d(j)  
    //                              infmap.cpp:602 (5)
    //         0044f061     INC        EDX
    //         0044f062     CMP        EDX,ESI
    //         0044f064     JL         LAB_0044f056
    //                               LAB_0044f066                                                 XREF[1]:     0044f054(j)  
    //                              infmap.cpp:607 (3)
    //         0044f066     POP        EDI
    //         0044f067     POP        ESI
    //         0044f068     RET
    //         0044f069     ??         90h
    //         0044f06a     NOP
    //         0044f06b     NOP
    //         0044f06c     NOP
    //         0044f06d     NOP
    //         0044f06e     NOP
    //         0044f06f     NOP
    //                              * public: __thiscall RGE_Master_Action_Object::RGE_Master_Action_Object(class RGE_Master_Action_Obje... *
    //                              undefined __thiscall RGE_Master_Action_Object(RGE_Master_Action_Obje
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Master_Act    ECX:4 (auto)   this
    //              RGE_Master_Act    Stack[0x4]:4   param_1                   XREF[1]:     0044f088(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0044f09a(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0044f09e(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0044f0b8(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0044f091(W)  
    //                               ??0RGE_Master_Action_Object@@QAE@PAV0@H@Z                    XREF[2]:     make_new_master:0044f6ab(c), 
    //                               RGE_Master_Action_Object::RGE_Master_Action_Object                        RGE_Master_Combat_Object:0044fe65(
    //                              m_ac_obj.cpp:29 (42)
    //         0044f070     PUSH       -0x1
    //         0044f072     PUSH       FUN_0055d638
    //         0044f077     MOV        EAX,FS:[0x0]
    //         0044f07d     PUSH       EAX
    //         0044f07e     MOV        dword ptr FS:[0x0],ESP
    //         0044f085     PUSH       this
    //         0044f086     PUSH       ESI
    //         0044f087     PUSH       EDI
    //         0044f088     MOV        EDI,dword ptr [ESP + param_1]
    //         0044f08c     MOV        ESI,this
    //         0044f08e     PUSH       0x0
    //         0044f090     PUSH       EDI
    //         0044f091     MOV        dword ptr [ESP + local_10],ESI
    //         0044f095     CALL       RGE_Master_Moving_Object::RGE_Master_Moving_Ob   undefined RGE_Master_Moving_Object(RGE_Master
    //                              m_ac_obj.cpp:30 (22)
    //         0044f09a     MOV        EAX,dword ptr [ESP + param_2]
    //         0044f09e     MOV        dword ptr [ESP + local_4],0x0
    //         0044f0a6     TEST       EAX,EAX
    //         0044f0a8     MOV        dword ptr [ESI],RGE_Master_Action_Object::`vft   = 0044f0d0
    //         0044f0ae     JZ         LAB_0044f0b8
    //                              m_ac_obj.cpp:31 (8)
    //         0044f0b0     PUSH       EDI
    //         0044f0b1     MOV        this,ESI
    //         0044f0b3     CALL       RGE_Master_Action_Object::setup                  int setup(RGE_Master_Action_Object * this, RG
    //                               LAB_0044f0b8                                                 XREF[1]:     0044f0ae(j)  
    //                              m_ac_obj.cpp:32 (21)
    //         0044f0b8     MOV        this,dword ptr [ESP + local_c]
    //         0044f0bc     MOV        EAX,ESI
    //         0044f0be     POP        EDI
    //         0044f0bf     MOV        dword ptr FS:[0x0],this
    //         0044f0c6     POP        ESI
    //         0044f0c7     ADD        ESP,0x10
    //         0044f0ca     RET        0x8
    //         0044f0cd     ??         90h
    //         0044f0ce     NOP
    //         0044f0cf     NOP
    //                              * public: virtual void * __thiscall RGE_Master_Action_Object::`vector deleting destructor'(unsigned ... *
    //                              void * __thiscall `vector_deleting_destructor'(RGE_Master_Action_Obj
    //              void *            EAX:4          <RETURN>
    //              RGE_Master_Act    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0044f0d8(R)  
    //                               ??_GRGE_Master_Action_Object@@UAEPAXI@Z                      XREF[1]:     00570448(*)  
    //                               ??_ERGE_Master_Action_Object@@UAEPAXI@Z
    //                               RGE_Master_Action_Object::`vector_deleting_destructor'
    //         0044f0d0     PUSH       ESI
    //         0044f0d1     MOV        ESI,this
    //         0044f0d3     CALL       RGE_Master_Action_Object::~RGE_Master_Action_O   void ~RGE_Master_Action_Object(RGE_Master_Act
    //         0044f0d8     TEST       byte ptr [ESP + param_1],0x1
    //         0044f0dd     JZ         LAB_0044f0e8
    //         0044f0df     PUSH       ESI
    //         0044f0e0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0044f0e5     ADD        ESP,0x4
    //                               LAB_0044f0e8                                                 XREF[1]:     0044f0dd(j)  
    //         0044f0e8     MOV        EAX,ESI
    //         0044f0ea     POP        ESI
    //         0044f0eb     RET        0x4
    //         0044f0ee     ??         90h
    //         0044f0ef     NOP
    //                              * public: __thiscall RGE_Master_Action_Object::RGE_Master_Action_Object(int,class RGE_Sprite * *,cla... *
    //                              undefined __thiscall RGE_Master_Action_Object(RGE_Master_Action_Obje
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Master_Act    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0044f10c(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     0044f107(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     0044f112(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0044f126(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0044f12a(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0044f146(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0044f11d(W)  
    //                               ??0RGE_Master_Action_Object@@QAE@HPAPAVRGE_Sprite@@PAPAVRGE  XREF[3]:     RGE_Master_Combat_Object:0044fef1(
    //                               RGE_Master_Action_Object::RGE_Master_Action_Object                        load_master_object:00461408(c), 
    //                                                                                                         load_master_object:0046fdd8(c)  
    //                              m_ac_obj.cpp:38 (54)
    //         0044f0f0     PUSH       -0x1
    //         0044f0f2     PUSH       FUN_0055d658
    //         0044f0f7     MOV        EAX,FS:[0x0]
    //         0044f0fd     PUSH       EAX
    //         0044f0fe     MOV        dword ptr FS:[0x0],ESP
    //         0044f105     PUSH       this
    //         0044f106     PUSH       EBX
    //         0044f107     MOV        EBX,dword ptr [ESP + param_2]
    //         0044f10b     PUSH       EBP
    //         0044f10c     MOV        EBP,dword ptr [ESP + param_1]
    //         0044f110     PUSH       ESI
    //         0044f111     PUSH       EDI
    //         0044f112     MOV        EDI,dword ptr [ESP + param_3]
    //         0044f116     PUSH       0x0
    //         0044f118     PUSH       EDI
    //         0044f119     MOV        ESI,this
    //         0044f11b     PUSH       EBX
    //         0044f11c     PUSH       EBP
    //         0044f11d     MOV        dword ptr [ESP + local_10],ESI
    //         0044f121     CALL       RGE_Master_Moving_Object::RGE_Master_Moving_Ob   undefined RGE_Master_Moving_Object(RGE_Master
    //                              m_ac_obj.cpp:39 (22)
    //         0044f126     MOV        EAX,dword ptr [ESP + param_4]
    //         0044f12a     MOV        dword ptr [ESP + local_4],0x0
    //         0044f132     TEST       EAX,EAX
    //         0044f134     MOV        dword ptr [ESI],RGE_Master_Action_Object::`vft   = 0044f0d0
    //         0044f13a     JZ         LAB_0044f146
    //                              m_ac_obj.cpp:40 (10)
    //         0044f13c     PUSH       EDI
    //         0044f13d     PUSH       EBX
    //         0044f13e     PUSH       EBP
    //         0044f13f     MOV        this,ESI
    //         0044f141     CALL       RGE_Master_Action_Object::setup                  int setup(RGE_Master_Action_Object * this, in
    //                               LAB_0044f146                                                 XREF[1]:     0044f13a(j)  
    //                              m_ac_obj.cpp:41 (23)
    //         0044f146     MOV        this,dword ptr [ESP + local_c]
    //         0044f14a     MOV        EAX,ESI
    //         0044f14c     POP        EDI
    //         0044f14d     POP        ESI
    //         0044f14e     POP        EBP
    //         0044f14f     MOV        dword ptr FS:[0x0],this
    //         0044f156     POP        EBX
    //         0044f157     ADD        ESP,0x10
    //         0044f15a     RET        0x10
    //         0044f15d     ??         90h
    //         0044f15e     NOP
    //         0044f15f     NOP
    //                              * public: __thiscall RGE_Master_Action_Object::RGE_Master_Action_Object(struct _iobuf *,class RGE_Sp... *
    //                              undefined __thiscall RGE_Master_Action_Object(RGE_Master_Action_Obje
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Master_Act    ECX:4 (auto)   this
    //              _iobuf *          Stack[0x4]:4   param_1                   XREF[2]:     0044f176(R), 0044f1b1(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     0044f180(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     0044f17b(R)  
    //              short             Stack[0x10]:2  param_4                   XREF[1]:     0044f186(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     0044f19b(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0044f19f(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0044f1c0(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0044f192(W)  
    //                               ??0RGE_Master_Action_Object@@QAE@PAU_iobuf@@PAPAVRGE_Sprite  XREF[2]:     RGE_Master_Combat_Object:0044ff66(
    //                               RGE_Master_Action_Object::RGE_Master_Action_Object                        load_object:00461710(c)  
    //                              m_ac_obj.cpp:47 (59)
    //         0044f160     PUSH       -0x1
    //         0044f162     PUSH       FUN_0055d678
    //         0044f167     MOV        EAX,FS:[0x0]
    //         0044f16d     PUSH       EAX
    //         0044f16e     MOV        dword ptr FS:[0x0],ESP
    //         0044f175     PUSH       this
    //         0044f176     MOV        EAX,dword ptr [ESP + param_1]
    //         0044f17a     PUSH       EBX
    //         0044f17b     MOV        EBX,dword ptr [ESP + param_3]
    //         0044f17f     PUSH       EBP
    //         0044f180     MOV        EBP,dword ptr [ESP + param_2]
    //         0044f184     PUSH       ESI
    //         0044f185     PUSH       EDI
    //         0044f186     MOV        EDI,dword ptr [ESP + param_4]
    //         0044f18a     PUSH       0x0
    //         0044f18c     PUSH       EDI
    //         0044f18d     PUSH       EBX
    //         0044f18e     MOV        ESI,this
    //         0044f190     PUSH       EBP
    //         0044f191     PUSH       EAX
    //         0044f192     MOV        dword ptr [ESP + local_10],ESI
    //         0044f196     CALL       RGE_Master_Moving_Object::RGE_Master_Moving_Ob   undefined RGE_Master_Moving_Object(RGE_Master
    //                              m_ac_obj.cpp:48 (22)
    //         0044f19b     MOV        EAX,dword ptr [ESP + param_5]
    //         0044f19f     MOV        dword ptr [ESP + local_4],0x0
    //         0044f1a7     TEST       EAX,EAX
    //         0044f1a9     MOV        dword ptr [ESI],RGE_Master_Action_Object::`vft   = 0044f0d0
    //         0044f1af     JZ         LAB_0044f1c0
    //                              m_ac_obj.cpp:49 (15)
    //         0044f1b1     MOV        this,dword ptr [ESP + param_1]
    //         0044f1b5     PUSH       EDI
    //         0044f1b6     PUSH       EBX
    //         0044f1b7     PUSH       EBP
    //         0044f1b8     PUSH       this
    //         0044f1b9     MOV        this,ESI
    //         0044f1bb     CALL       RGE_Master_Action_Object::setup                  int setup(RGE_Master_Action_Object * this, _i
    //                               LAB_0044f1c0                                                 XREF[1]:     0044f1af(j)  
    //                              m_ac_obj.cpp:50 (23)
    //         0044f1c0     MOV        this,dword ptr [ESP + local_c]
    //         0044f1c4     MOV        EAX,ESI
    //         0044f1c6     POP        EDI
    //         0044f1c7     POP        ESI
    //         0044f1c8     POP        EBP
    //         0044f1c9     MOV        dword ptr FS:[0x0],this
    //         0044f1d0     POP        EBX
    //         0044f1d1     ADD        ESP,0x10
    //         0044f1d4     RET        0x14
    //         0044f1d7     ??         90h
    //         0044f1d8     NOP
    //         0044f1d9     NOP
    //         0044f1da     NOP
    //         0044f1db     NOP
    //         0044f1dc     NOP
    //         0044f1dd     NOP
    //         0044f1de     NOP
    //         0044f1df     NOP
    return 0;
}

int InfluenceMap::setCoverageCount(XYPoint* param_1, XYPoint* param_2, int param_3) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int InfluenceMap::setConnectionCount(XYPoint* param_1, XYPoint* param_2, int param_3, int param_4, int param_5, int param_6) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int InfluenceMap::coverageIncluding(XYPoint* param_1, XYPoint* param_2, uchar param_3, uchar param_4) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int InfluenceMap::connectionsIncluding(XYPoint* param_1, XYPoint* param_2, uchar param_3, uchar param_4, int param_5, int param_6, int param_7) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

