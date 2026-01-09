#include "common.h"
#include "sceninfo.h"

RGE_Scenario_File_Info::RGE_Scenario_File_Info(char* param_1) {
    /* TODO: Stub */
    //                              undefined __thiscall RGE_Scenario_File_Info(RGE_Scenario_File_Info *
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Scenario_F    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0048cea6(R)  
    //                               ??0RGE_Scenario_File_Info@@QAE@PAD@Z                         XREF[1]:     setup:0041c123(c)  
    //                               RGE_Scenario_File_Info::RGE_Scenario_File_Info
    //                              sceninfo.cpp:26 (6)
    //         0048cea0     PUSH       EBX
    //         0048cea1     PUSH       EBP
    //         0048cea2     PUSH       ESI
    //         0048cea3     MOV        EBX,this
    //         0048cea5     PUSH       EDI
    //                              sceninfo.cpp:30 (15)
    //         0048cea6     MOV        EDI,dword ptr [ESP + param_1]
    //         0048ceaa     OR         this,0xffffffff
    //         0048cead     XOR        EAX,EAX
    //         0048ceaf     SCASB.RE   ES:EDI
    //         0048ceb1     NOT        this
    //         0048ceb3     SUB        EDI,this
    //                              sceninfo.cpp:32 (34)
    //         0048ceb5     PUSH       0x8000
    //         0048ceba     MOV        EAX,this
    //         0048cebc     MOV        ESI,EDI
    //         0048cebe     MOV        EDI,EBX
    //         0048cec0     PUSH       EBX
    //         0048cec1     SHR        this,0x2
    //         0048cec4     MOVSD.REP  ES:EDI,ESI
    //         0048cec6     MOV        this,EAX
    //         0048cec8     AND        this,0x3
    //         0048cecb     MOVSB.REP  ES:EDI,ESI
    //         0048cecd     CALL       rge_open                                         int rge_open(char * param_1, int param_2)
    //         0048ced2     MOV        EDI,EAX
    //         0048ced4     ADD        ESP,0x8
    //                              sceninfo.cpp:33 (9)
    //         0048ced7     CMP        EDI,-0x1
    //         0048ceda     JZ         LAB_0048cfa6
    //                              sceninfo.cpp:35 (15)
    //         0048cee0     LEA        ESI,[EBX + 0x104]
    //         0048cee6     PUSH       0x4
    //         0048cee8     PUSH       ESI
    //         0048cee9     PUSH       EDI
    //         0048ceea     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void 
    //                              sceninfo.cpp:37 (15)
    //         0048ceef     MOV        EAX,dword ptr [ESI]
    //         0048cef1     XOR        EBP,EBP
    //         0048cef3     ADD        ESP,0xc
    //         0048cef6     CMP        EAX,EBP
    //         0048cef8     JLE        LAB_0048cf87
    //                              sceninfo.cpp:39 (17)
    //         0048cefe     PUSH       0x10c
    //         0048cf03     PUSH       EAX
    //         0048cf04     CALL       calloc                                           undefined calloc()
    //         0048cf09     MOV        dword ptr [EBX + 0x108],EAX
    //                              sceninfo.cpp:41 (9)
    //         0048cf0f     MOV        EAX,dword ptr [ESI]
    //         0048cf11     ADD        ESP,0x8
    //         0048cf14     CMP        EAX,EBP
    //         0048cf16     JLE        LAB_0048cf8d
    //                              sceninfo.cpp:61 (2)
    //         0048cf18     XOR        ESI,ESI
    //                               LAB_0048cf1a                                                 XREF[1]:     0048cf6c(j)  
    //                              sceninfo.cpp:43 (17)
    //         0048cf1a     MOV        this,dword ptr [EBX + 0x108]
    //         0048cf20     PUSH       0x4
    //         0048cf22     ADD        this,ESI
    //         0048cf24     PUSH       this
    //         0048cf25     PUSH       EDI
    //         0048cf26     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void 
    //                              sceninfo.cpp:44 (25)
    //         0048cf2b     MOV        EDX,dword ptr [EBX + 0x108]
    //         0048cf31     ADD        ESP,0xc
    //         0048cf34     LEA        EAX,[EDX + ESI*0x1 + 0x8]
    //         0048cf38     PUSH       0x104
    //         0048cf3d     PUSH       EAX
    //         0048cf3e     PUSH       EDI
    //         0048cf3f     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void 
    //                              sceninfo.cpp:46 (42)
    //         0048cf44     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048cf4a     ADD        ESP,0xc
    //         0048cf4d     MOV        EDX,dword ptr [this->filename[0]]
    //         0048cf4f     PUSH       EDI
    //         0048cf50     CALL       dword ptr [EDX + 0x38]
    //         0048cf53     MOV        this,dword ptr [EBX + 0x108]
    //         0048cf59     INC        EBP
    //         0048cf5a     MOV        dword ptr [ECX + ESI*0x1 + this+0x4],EAX
    //         0048cf5e     MOV        EAX,dword ptr [EBX + 0x104]
    //         0048cf64     ADD        ESI,0x10c
    //         0048cf6a     CMP        EBP,EAX
    //         0048cf6c     JL         LAB_0048cf1a
    //                              sceninfo.cpp:52 (9)
    //         0048cf6e     PUSH       EDI
    //         0048cf6f     CALL       rge_close                                        int rge_close(int param_1)
    //         0048cf74     ADD        ESP,0x4
    //                              sceninfo.cpp:60 (7)
    //         0048cf77     MOV        this,EBX
    //         0048cf79     CALL       RGE_Scenario_File_Info::reload_scenarios         void reload_scenarios(RGE_Scenario_File_Info 
    //                              sceninfo.cpp:61 (9)
    //         0048cf7e     MOV        EAX,EBX
    //         0048cf80     POP        EDI
    //         0048cf81     POP        ESI
    //         0048cf82     POP        EBP
    //         0048cf83     POP        EBX
    //         0048cf84     RET        0x4
    //                               LAB_0048cf87                                                 XREF[1]:     0048cef8(j)  
    //                              sceninfo.cpp:50 (6)
    //         0048cf87     MOV        dword ptr [EBX + 0x108],EBP
    //                               LAB_0048cf8d                                                 XREF[1]:     0048cf16(j)  
    //                              sceninfo.cpp:52 (9)
    //         0048cf8d     PUSH       EDI
    //         0048cf8e     CALL       rge_close                                        int rge_close(int param_1)
    //         0048cf93     ADD        ESP,0x4
    //                              sceninfo.cpp:60 (7)
    //         0048cf96     MOV        this,EBX
    //         0048cf98     CALL       RGE_Scenario_File_Info::reload_scenarios         void reload_scenarios(RGE_Scenario_File_Info 
    //                              sceninfo.cpp:61 (9)
    //         0048cf9d     MOV        EAX,EBX
    //         0048cf9f     POP        EDI
    //         0048cfa0     POP        ESI
    //         0048cfa1     POP        EBP
    //         0048cfa2     POP        EBX
    //         0048cfa3     RET        0x4
    //                               LAB_0048cfa6                                                 XREF[1]:     0048ceda(j)  
    //                              sceninfo.cpp:56 (2)
    //         0048cfa6     XOR        EBP,EBP
    //                              sceninfo.cpp:60 (19)
    //         0048cfa8     MOV        this,EBX
    //         0048cfaa     MOV        dword ptr [EBX + 0x104],EBP
    //         0048cfb0     MOV        dword ptr [EBX + 0x108],EBP
    //         0048cfb6     CALL       RGE_Scenario_File_Info::reload_scenarios         void reload_scenarios(RGE_Scenario_File_Info 
    //                              sceninfo.cpp:61 (9)
    //         0048cfbb     POP        EDI
    //         0048cfbc     POP        ESI
    //         0048cfbd     MOV        EAX,EBX
    //         0048cfbf     POP        EBP
    //         0048cfc0     POP        EBX
    //         0048cfc1     RET        0x4
    //         0048cfc4     ??         90h
    //         0048cfc5     NOP
    //         0048cfc6     NOP
    //         0048cfc7     NOP
    //         0048cfc8     NOP
    //         0048cfc9     NOP
    //         0048cfca     NOP
    //         0048cfcb     NOP
    //         0048cfcc     NOP
    //         0048cfcd     NOP
    //         0048cfce     NOP
    //         0048cfcf     NOP
}

RGE_Scenario_File_Info::~RGE_Scenario_File_Info() {
    /* TODO: Stub */
    //                              void __thiscall ~RGE_Scenario_File_Info(RGE_Scenario_File_Info * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Scenario_F    ECX:4 (auto)   this
    //                               ??1RGE_Scenario_File_Info@@QAE@XZ                            XREF[1]:     ~RGE_Base_Game:0041c3eb(c)  
    //                               RGE_Scenario_File_Info::~RGE_Scenario_File_Info
    //                              sceninfo.cpp:67 (3)
    //         0048cfd0     PUSH       ESI
    //         0048cfd1     MOV        ESI,this
    //                              sceninfo.cpp:70 (5)
    //         0048cfd3     CALL       RGE_Scenario_File_Info::save                     void save(RGE_Scenario_File_Info * this)
    //                              sceninfo.cpp:72 (11)
    //         0048cfd8     MOV        EAX,dword ptr [ESI + 0x104]
    //         0048cfde     TEST       EAX,EAX
    //         0048cfe0     JLE        LAB_0048d03c
    //         0048cfe2     PUSH       EBP
    //                              sceninfo.cpp:74 (8)
    //         0048cfe3     XOR        EBP,EBP
    //         0048cfe5     TEST       EAX,EAX
    //         0048cfe7     JLE        LAB_0048d01e
    //         0048cfe9     PUSH       EDI
    //         0048cfea     PUSH       EBX
    //                              sceninfo.cpp:80 (83)
    //         0048cfeb     XOR        EBX,EBX
    //                               LAB_0048cfed                                                 XREF[1]:     0048d01a(j)  
    //         0048cfed     MOV        EAX,dword ptr [ESI + 0x108]
    //         0048cff3     MOV        EDI,dword ptr [EAX + EBX*0x1 + 0x4]
    //         0048cff7     TEST       EDI,EDI
    //         0048cff9     JZ         LAB_0048d00b
    //         0048cffb     MOV        this,EDI
    //         0048cffd     CALL       RGE_Scenario_Header::~RGE_Scenario_Header        void ~RGE_Scenario_Header(RGE_Scenario_Header
    //         0048d002     PUSH       EDI
    //         0048d003     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0048d008     ADD        ESP,0x4
    //                               LAB_0048d00b                                                 XREF[1]:     0048cff9(j)  
    //         0048d00b     MOV        EAX,dword ptr [ESI + 0x104]
    //         0048d011     INC        EBP
    //         0048d012     ADD        EBX,0x10c
    //         0048d018     CMP        EBP,EAX
    //         0048d01a     JL         LAB_0048cfed
    //         0048d01c     POP        EBX
    //         0048d01d     POP        EDI
    //                               LAB_0048d01e                                                 XREF[1]:     0048cfe7(j)  
    //         0048d01e     MOV        this,dword ptr [ESI + 0x108]
    //         0048d024     PUSH       this
    //         0048d025     CALL       free                                             undefined free()
    //         0048d02a     ADD        ESP,0x4
    //         0048d02d     XOR        EAX,EAX
    //         0048d02f     MOV        dword ptr [ESI + 0x108],EAX
    //         0048d035     MOV        dword ptr [ESI + 0x104],EAX
    //         0048d03b     POP        EBP
    //                               LAB_0048d03c                                                 XREF[1]:     0048cfe0(j)  
    //         0048d03c     POP        ESI
    //         0048d03d     RET
    //         0048d03e     ??         90h
    //         0048d03f     NOP
}

void RGE_Scenario_File_Info::save() {
    /* TODO: Stub */
    //                              void __thiscall save(RGE_Scenario_File_Info * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Scenario_F    ECX:4 (auto)   this
    //                               ?save@RGE_Scenario_File_Info@@QAEXXZ                         XREF[1]:     ~RGE_Scenario_File_Info:0048cfd3(c
    //                               RGE_Scenario_File_Info::save
    //                              sceninfo.cpp:86 (4)
    //         0048d040     PUSH       EBX
    //         0048d041     PUSH       EDI
    //         0048d042     MOV        EBX,this
    //                              sceninfo.cpp:90 (21)
    //         0048d044     PUSH       0x180
    //         0048d049     PUSH       0x8301
    //         0048d04e     PUSH       EBX
    //         0048d04f     CALL       rge_open                                         int rge_open(char * param_1, int param_2, int
    //         0048d054     MOV        EDI,EAX
    //         0048d056     ADD        ESP,0xc
    //                              sceninfo.cpp:91 (7)
    //         0048d059     CMP        EDI,-0x1
    //         0048d05c     JZ         LAB_0048d0d5
    //         0048d05e     PUSH       ESI
    //         0048d05f     PUSH       EBP
    //                              sceninfo.cpp:93 (15)
    //         0048d060     LEA        ESI,[EBX + 0x104]
    //         0048d066     PUSH       0x4
    //         0048d068     PUSH       ESI
    //         0048d069     PUSH       EDI
    //         0048d06a     CALL       rge_write_uncompressed                           void rge_write_uncompressed(int param_1, void
    //                              sceninfo.cpp:95 (11)
    //         0048d06f     MOV        EAX,dword ptr [ESI]
    //         0048d071     ADD        ESP,0xc
    //         0048d074     XOR        EBP,EBP
    //         0048d076     TEST       EAX,EAX
    //         0048d078     JLE        LAB_0048d0ca
    //                              sceninfo.cpp:105 (2)
    //         0048d07a     XOR        ESI,ESI
    //                               LAB_0048d07c                                                 XREF[1]:     0048d0c8(j)  
    //                              sceninfo.cpp:97 (17)
    //         0048d07c     MOV        EAX,dword ptr [EBX + 0x108]
    //         0048d082     PUSH       0x4
    //         0048d084     ADD        EAX,ESI
    //         0048d086     PUSH       EAX=>DAT_fffffff8
    //         0048d087     PUSH       EDI=>DAT_fffffff4
    //         0048d088     CALL       rge_write_uncompressed                           void rge_write_uncompressed(int param_1, void
    //                              sceninfo.cpp:98 (25)
    //         0048d08d     MOV        this,dword ptr [EBX + 0x108]
    //         0048d093     ADD        ESP,0xc
    //         0048d096     LEA        EDX,[ECX + ESI*0x1 + this+0x8]
    //         0048d09a     PUSH       0x104
    //         0048d09f     PUSH       EDX
    //         0048d0a0     PUSH       EDI
    //         0048d0a1     CALL       rge_write_uncompressed                           void rge_write_uncompressed(int param_1, void
    //                              sceninfo.cpp:100 (36)
    //         0048d0a6     MOV        EAX,dword ptr [EBX + 0x108]
    //         0048d0ac     ADD        ESP,0xc
    //         0048d0af     MOV        this,dword ptr [EAX + ESI*0x1 + 0x4]
    //         0048d0b3     PUSH       EDI
    //         0048d0b4     MOV        EDX,dword ptr [this->filename[0]]
    //         0048d0b6     CALL       dword ptr [EDX + 0x4]
    //         0048d0b9     MOV        EAX,dword ptr [EBX + 0x104]
    //         0048d0bf     INC        EBP
    //         0048d0c0     ADD        ESI,0x10c
    //         0048d0c6     CMP        EBP,EAX
    //         0048d0c8     JL         LAB_0048d07c
    //                               LAB_0048d0ca                                                 XREF[1]:     0048d078(j)  
    //                              sceninfo.cpp:103 (11)
    //         0048d0ca     PUSH       EDI
    //         0048d0cb     CALL       rge_close                                        int rge_close(int param_1)
    //         0048d0d0     ADD        ESP,0x4
    //         0048d0d3     POP        EBP
    //         0048d0d4     POP        ESI
    //                               LAB_0048d0d5                                                 XREF[1]:     0048d05c(j)  
    //                              sceninfo.cpp:105 (3)
    //         0048d0d5     POP        EDI
    //         0048d0d6     POP        EBX
    //         0048d0d7     RET
    //         0048d0d8     ??         90h
    //         0048d0d9     NOP
    //         0048d0da     NOP
    //         0048d0db     NOP
    //         0048d0dc     NOP
    //         0048d0dd     NOP
    //         0048d0de     NOP
    //         0048d0df     NOP
    return;
}

void RGE_Scenario_File_Info::reload_scenarios() {
    /* TODO: Stub */
    //                              void __thiscall reload_scenarios(RGE_Scenario_File_Info * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Scenario_F    ECX:4 (auto)   this
    //              _finddata_t       Stack[-0x11c   file_info                 XREF[0,15]:  0048d118(*), 0048d134(*), 0048d170(*), 0048d18c(*), 
    //                                                                                     0048d1d0(*), 0048d20f(*), 0048d3dd(*), 0048d426(*), 
    //                                                                                     0048d2bf(R), 0048d371(R), 0048d26f(*), 0048d27a(*), 
    //                                                                                     0048d33e(*), 0048d359(*), 0048d287(R)  
    //              char[256]         Stack[-0x21c   file_name                 XREF[1,12]:  0048d3b1(*), 0048d0fb(*), 0048d11f(*), 0048d154(*), 
    //                                                                                     0048d177(*), 0048d1ac(*), 0048d1d7(*), 0048d1f4(*), 
    //                                                                                     0048d216(*), 0048d36b(*), 0048d398(*), 0048d40b(*), 
    //                                                                                     0048d42d(*)  
    //              long              Stack[-0x220   version                   XREF[2]:     0048d246(W), 0048d4a4(R)  
    //              RGE_Scenario_F    Stack[-0x224   new_scenarios             XREF[4]:     0048d107(W), 0048d14b(W), 0048d1a3(W), 0048d4a8(R)  
    //              long              Stack[-0x228   count                     XREF[5]:     0048d1e8(W), 0048d224(W), 0048d22d(R), 0048d3d9(R), 
    //                                                                                     0048d43e(W)  
    //              long              Stack[-0x22c   handle                    XREF[5]:     0048d26b(W), 0048d2a3(R), 0048d2b5(W), 0048d2ee(W), 
    //                                                                                     0048d2f6(R)  
    //              undefined1        Stack[-0x22d   local_22d                 XREF[3]:     0048d257(W), 0048d2fa(W), 0048d332(R)  
    //              undefined1        Stack[-0x22e   local_22e                 XREF[4]:     0048d10b(W), 0048d228(W), 0048d3fd(R), 0048d444(W)  
    //              uchar             Stack[-0x231   found_in_list
    //              uchar             Stack[-0x232   looped
    //                               ?reload_scenarios@RGE_Scenario_File_Info@@QAEXXZ             XREF[6]:     reload_scenarios_info:00422fd3(c), 
    //                               RGE_Scenario_File_Info::reload_scenarios                                  RGE_Scenario_File_Info:0048cf79(c)
    //                                                                                                         RGE_Scenario_File_Info:0048cf98(c)
    //                                                                                                         RGE_Scenario_File_Info:0048cfb6(c)
    //                                                                                                         fillScenarios:004b450a(c), 
    //                                                                                                         fillScenarios:004b5e4f(c)  
    //                              sceninfo.cpp:111 (6)
    //         0048d0e0     SUB        ESP,0x230
    //                              sceninfo.cpp:126 (50)
    //         0048d0e6     MOV        EAX,[rge_base_game]                              = 00000000
    //         0048d0eb     PUSH       EBX
    //         0048d0ec     MOV        EBX,this
    //         0048d0ee     PUSH       EBP
    //         0048d0ef     MOV        this,dword ptr [EAX + 0xc]
    //         0048d0f2     PUSH       ESI
    //         0048d0f3     ADD        this,0xc17
    //         0048d0f9     PUSH       EDI
    //         0048d0fa     PUSH       this
    //         0048d0fb     LEA        EDX=>file_name[4],[ESP + 0x2c]
    //         0048d0ff     XOR        EDI,EDI
    //         0048d101     PUSH       s_%s*.scn                                        = "%s*.scn"
    //         0048d106     PUSH       EDX
    //         0048d107     MOV        dword ptr [ESP + new_scenarios],EDI
    //         0048d10b     MOV        byte ptr [ESP + local_22e],0x0
    //         0048d110     CALL       sprintf                                          undefined sprintf()
    //         0048d115     ADD        ESP,0xc
    //                              sceninfo.cpp:127 (23)
    //         0048d118     LEA        EAX=>file_info.time_create,[ESP + 0x128]
    //         0048d11f     LEA        this=>file_name[4],[ESP + 0x28]
    //         0048d123     PUSH       EAX
    //         0048d124     PUSH       this
    //         0048d125     CALL       __findfirst                                      undefined __findfirst()
    //         0048d12a     MOV        ESI,EAX
    //         0048d12c     ADD        ESP,0x8
    //                              sceninfo.cpp:128 (5)
    //         0048d12f     CMP        ESI,-0x1
    //         0048d132     JZ         LAB_0048d14f
    //                               LAB_0048d134                                                 XREF[1]:     0048d149(j)  
    //                              sceninfo.cpp:131 (23)
    //         0048d134     LEA        EDX=>file_info.time_create,[ESP + 0x128]
    //         0048d13b     INC        EDI
    //         0048d13c     PUSH       EDX
    //         0048d13d     PUSH       ESI
    //         0048d13e     CALL       __findnext                                       undefined __findnext()
    //         0048d143     ADD        ESP,0x8
    //         0048d146     CMP        EAX,-0x1
    //         0048d149     JNZ        LAB_0048d134
    //                              sceninfo.cpp:130 (4)
    //         0048d14b     MOV        dword ptr [ESP + new_scenarios],EDI
    //                               LAB_0048d14f                                                 XREF[1]:     0048d132(j)  
    //                              sceninfo.cpp:133 (33)
    //         0048d14f     MOV        EAX,[rge_base_game]                              = 00000000
    //         0048d154     LEA        EDX=>file_name[4],[ESP + 0x28]
    //         0048d158     MOV        this,dword ptr [EAX + 0xc]
    //         0048d15b     ADD        this,0xc17
    //         0048d161     PUSH       this
    //         0048d162     PUSH       s_%s*.scx                                        = "%s*.scx"
    //         0048d167     PUSH       EDX
    //         0048d168     CALL       sprintf                                          undefined sprintf()
    //         0048d16d     ADD        ESP,0xc
    //                              sceninfo.cpp:134 (23)
    //         0048d170     LEA        EAX=>file_info.time_create,[ESP + 0x128]
    //         0048d177     LEA        this=>file_name[4],[ESP + 0x28]
    //         0048d17b     PUSH       EAX
    //         0048d17c     PUSH       this
    //         0048d17d     CALL       __findfirst                                      undefined __findfirst()
    //         0048d182     MOV        ESI,EAX
    //         0048d184     ADD        ESP,0x8
    //                              sceninfo.cpp:135 (5)
    //         0048d187     CMP        ESI,-0x1
    //         0048d18a     JZ         LAB_0048d1a7
    //                               LAB_0048d18c                                                 XREF[1]:     0048d1a1(j)  
    //                              sceninfo.cpp:138 (23)
    //         0048d18c     LEA        EDX=>file_info.time_create,[ESP + 0x128]
    //         0048d193     INC        EDI
    //         0048d194     PUSH       EDX
    //         0048d195     PUSH       ESI
    //         0048d196     CALL       __findnext                                       undefined __findnext()
    //         0048d19b     ADD        ESP,0x8
    //         0048d19e     CMP        EAX,-0x1
    //         0048d1a1     JNZ        LAB_0048d18c
    //                              sceninfo.cpp:137 (4)
    //         0048d1a3     MOV        dword ptr [ESP + new_scenarios],EDI
    //                               LAB_0048d1a7                                                 XREF[1]:     0048d18a(j)  
    //                              sceninfo.cpp:140 (33)
    //         0048d1a7     MOV        EAX,[rge_base_game]                              = 00000000
    //         0048d1ac     LEA        EDX=>file_name[4],[ESP + 0x28]
    //         0048d1b0     MOV        this,dword ptr [EAX + 0xc]
    //         0048d1b3     ADD        this,0xc17
    //         0048d1b9     PUSH       this
    //         0048d1ba     PUSH       s_%s*.scn                                        = "%s*.scn"
    //         0048d1bf     PUSH       EDX
    //         0048d1c0     CALL       sprintf                                          undefined sprintf()
    //         0048d1c5     ADD        ESP,0xc
    //                              sceninfo.cpp:141 (8)
    //         0048d1c8     TEST       EDI,EDI
    //         0048d1ca     JLE        LAB_0048d4b8
    //                              sceninfo.cpp:143 (21)
    //         0048d1d0     LEA        EAX=>file_info.time_create,[ESP + 0x128]
    //         0048d1d7     LEA        this=>file_name[4],[ESP + 0x28]
    //         0048d1db     PUSH       EAX
    //         0048d1dc     PUSH       this
    //         0048d1dd     CALL       __findfirst                                      undefined __findfirst()
    //         0048d1e2     ADD        ESP,0x8
    //                              sceninfo.cpp:144 (9)
    //         0048d1e5     CMP        EAX,-0x1
    //         0048d1e8     MOV        dword ptr [ESP + count],EAX
    //         0048d1ec     JNZ        LAB_0048d22d
    //                              sceninfo.cpp:146 (33)
    //         0048d1ee     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         0048d1f4     LEA        this=>file_name[4],[ESP + 0x28]
    //         0048d1f8     MOV        EAX,dword ptr [EDX + 0xc]
    //         0048d1fb     ADD        EAX,0xc17
    //         0048d200     PUSH       EAX
    //         0048d201     PUSH       s_%s*.scx                                        = "%s*.scx"
    //         0048d206     PUSH       this
    //         0048d207     CALL       sprintf                                          undefined sprintf()
    //         0048d20c     ADD        ESP,0xc
    //                              sceninfo.cpp:147 (25)
    //         0048d20f     LEA        EDX=>file_info.time_create,[ESP + 0x128]
    //         0048d216     LEA        EAX=>file_name[4],[ESP + 0x28]
    //         0048d21a     PUSH       EDX
    //         0048d21b     PUSH       EAX
    //         0048d21c     CALL       __findfirst                                      undefined __findfirst()
    //         0048d221     ADD        ESP,0x8
    //         0048d224     MOV        dword ptr [ESP + count],EAX
    //                              sceninfo.cpp:148 (5)
    //         0048d228     MOV        byte ptr [ESP + local_22e],0x1
    //                               LAB_0048d22d                                                 XREF[1]:     0048d1ec(j)  
    //                              sceninfo.cpp:151 (11)
    //         0048d22d     CMP        dword ptr [ESP + count],-0x1
    //         0048d232     JZ         LAB_0048d4b8
    //                              sceninfo.cpp:153 (18)
    //         0048d238     PUSH       0x10c
    //         0048d23d     PUSH       EDI
    //         0048d23e     CALL       calloc                                           undefined calloc()
    //         0048d243     ADD        ESP,0x8
    //         0048d246     MOV        dword ptr [ESP + version],EAX
    //                              sceninfo.cpp:230 (37)
    //         0048d24a     LEA        EBP,[EAX + 0x4]
    //                               LAB_0048d24d                                                 XREF[2]:     0048d3f7(j), 0048d449(j)  
    //         0048d24d     MOV        EAX,dword ptr [EBX + 0x104]
    //         0048d253     XOR        EDI,EDI
    //         0048d255     TEST       EAX,EAX
    //         0048d257     MOV        byte ptr [ESP + local_22d],0x0
    //         0048d25c     JLE        LAB_0048d332
    //         0048d262     MOV        EAX,dword ptr [EBX + 0x108]
    //         0048d268     ADD        EAX,0x8
    //         0048d26b     MOV        dword ptr [ESP + handle],EAX
    //                               LAB_0048d26f                                                 XREF[1]:     0048d2b9(j)  
    //                              sceninfo.cpp:161 (78)
    //         0048d26f     LEA        ESI=>file_info+0x18,[ESP + 0x13c]
    //                               LAB_0048d276                                                 XREF[1]:     0048d294(j)  
    //         0048d276     MOV        DL,byte ptr [EAX]
    //         0048d278     MOV        this,DL
    //         0048d27a     CMP        DL,byte ptr [ESI]=>file_info+0x18
    //         0048d27c     JNZ        LAB_0048d29a
    //         0048d27e     TEST       this,this
    //         0048d280     JZ         LAB_0048d296
    //         0048d282     MOV        DL,byte ptr [EAX + 0x1]
    //         0048d285     MOV        this,DL
    //         0048d287     CMP        DL,byte ptr [ESI + file_info+0x19]
    //         0048d28a     JNZ        LAB_0048d29a
    //         0048d28c     ADD        EAX,0x2
    //         0048d28f     ADD        ESI,0x2
    //         0048d292     TEST       this,this
    //         0048d294     JNZ        LAB_0048d276
    //                               LAB_0048d296                                                 XREF[1]:     0048d280(j)  
    //         0048d296     XOR        EAX,EAX
    //         0048d298     JMP        LAB_0048d29f
    //                               LAB_0048d29a                                                 XREF[2]:     0048d27c(j), 0048d28a(j)  
    //         0048d29a     SBB        EAX,EAX
    //         0048d29c     SBB        EAX,-0x1
    //                               LAB_0048d29f                                                 XREF[1]:     0048d298(j)  
    //         0048d29f     TEST       EAX,EAX
    //         0048d2a1     JZ         LAB_0048d2bd
    //         0048d2a3     MOV        EAX,dword ptr [ESP + handle]
    //         0048d2a7     MOV        this,dword ptr [EBX + 0x104]
    //         0048d2ad     INC        EDI
    //         0048d2ae     ADD        EAX,0x10c
    //         0048d2b3     CMP        EDI,this
    //         0048d2b5     MOV        dword ptr [ESP + handle],EAX
    //         0048d2b9     JL         LAB_0048d26f
    //         0048d2bb     JMP        LAB_0048d332
    //                               LAB_0048d2bd                                                 XREF[1]:     0048d2a1(j)  
    //                              sceninfo.cpp:164 (31)
    //         0048d2bd     MOV        EAX,EDI
    //         0048d2bf     MOV        this,dword ptr [ESP + file_info.size]
    //         0048d2c6     SHL        EAX,0x5
    //         0048d2c9     ADD        EAX,EDI
    //         0048d2cb     LEA        EDX,[EDI + EAX*0x2]
    //         0048d2ce     MOV        EAX,dword ptr [EBX + 0x108]
    //         0048d2d4     SHL        EDX,0x2
    //         0048d2d7     CMP        this,dword ptr [EAX + EDX*0x1]
    //         0048d2da     JG         LAB_0048d332
    //                              sceninfo.cpp:168 (9)
    //         0048d2dc     LEA        EDI,[EAX + EDX*0x1 + 0x8]
    //         0048d2e0     OR         this,0xffffffff
    //         0048d2e3     XOR        EAX,EAX
    //                              sceninfo.cpp:208 (361)
    //         0048d2e5     LEA        ESI,[EBP + 0x4]
    //         0048d2e8     SCASB.RE   ES:EDI
    //         0048d2ea     NOT        this
    //         0048d2ec     SUB        EDI,this
    //         0048d2ee     MOV        dword ptr [ESP + handle],ESI
    //         0048d2f2     MOV        EAX,this
    //         0048d2f4     MOV        ESI,EDI
    //         0048d2f6     MOV        EDI,dword ptr [ESP + handle]
    //         0048d2fa     MOV        byte ptr [ESP + local_22d],0x1
    //         0048d2ff     SHR        this,0x2
    //         0048d302     MOVSD.REP  ES:EDI,ESI
    //         0048d304     MOV        this,EAX
    //         0048d306     AND        this,0x3
    //         0048d309     MOVSB.REP  ES:EDI,ESI
    //         0048d30b     MOV        this,dword ptr [EBX + 0x108]
    //         0048d311     MOV        EAX,dword ptr [EDX + this->filename[0]*0x1]
    //         0048d314     MOV        dword ptr [EBP + -0x4],EAX
    //         0048d317     MOV        this,dword ptr [EBX + 0x108]
    //         0048d31d     MOV        EAX,dword ptr [EDX + this->filename[0]*0x1 + 0
    //         0048d321     MOV        dword ptr [EBP],EAX
    //         0048d324     MOV        this,dword ptr [EBX + 0x108]
    //         0048d32a     MOV        dword ptr [EDX + this->filename[0]*0x1 + 0x4],
    //                               LAB_0048d332                                                 XREF[3]:     0048d25c(j), 0048d2bb(j), 
    //                                                                                                         0048d2da(j)  
    //         0048d332     MOV        AL,byte ptr [ESP + local_22d]
    //         0048d336     TEST       AL,AL
    //         0048d338     JNZ        LAB_0048d3d9
    //         0048d33e     LEA        EDI=>file_info+0x18,[ESP + 0x13c]
    //         0048d345     OR         this,0xffffffff
    //         0048d348     XOR        EAX,EAX
    //         0048d34a     LEA        EDX,[EBP + 0x4]
    //         0048d34d     SCASB.RE   ES:EDI
    //         0048d34f     NOT        this
    //         0048d351     SUB        EDI,this
    //         0048d353     MOV        EAX,this
    //         0048d355     MOV        ESI,EDI
    //         0048d357     MOV        EDI,EDX
    //         0048d359     LEA        EDX=>file_info+0x18,[ESP + 0x13c]
    //         0048d360     SHR        this,0x2
    //         0048d363     MOVSD.REP  ES:EDI,ESI
    //         0048d365     MOV        this,EAX
    //         0048d367     PUSH       EDX
    //         0048d368     AND        this,0x3
    //         0048d36b     LEA        EDX=>file_name[4],[ESP + 0x2c]
    //         0048d36f     MOVSB.REP  ES:EDI,ESI
    //         0048d371     MOV        this,dword ptr [ESP + file_info.size]
    //         0048d378     MOV        dword ptr [EBP + -0x4],this
    //         0048d37b     MOV        EAX,[rge_base_game]                              = 00000000
    //         0048d380     MOV        this,dword ptr [EAX + 0xc]
    //         0048d383     ADD        this,0xc17
    //         0048d389     PUSH       this
    //         0048d38a     PUSH       s_%s%s                                           = "%s%s"
    //         0048d38f     PUSH       EDX
    //         0048d390     CALL       sprintf                                          undefined sprintf()
    //         0048d395     ADD        ESP,0x10
    //         0048d398     LEA        EAX=>file_name[4],[ESP + 0x28]
    //         0048d39c     PUSH       0x8000
    //         0048d3a1     PUSH       EAX
    //         0048d3a2     CALL       rge_open                                         int rge_open(char * param_1, int param_2)
    //         0048d3a7     MOV        ESI,EAX
    //         0048d3a9     ADD        ESP,0x8
    //         0048d3ac     CMP        ESI,-0x1
    //         0048d3af     JLE        LAB_0048d3d9
    //         0048d3b1     LEA        this=>file_name,[ESP + 0x24]
    //         0048d3b5     PUSH       0x4
    //         0048d3b7     PUSH       this
    //         0048d3b8     PUSH       ESI
    //         0048d3b9     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void 
    //         0048d3be     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048d3c4     ADD        ESP,0xc
    //         0048d3c7     MOV        EDX,dword ptr [this->filename[0]]
    //         0048d3c9     PUSH       ESI
    //         0048d3ca     CALL       dword ptr [EDX + 0x38]
    //         0048d3cd     PUSH       ESI
    //         0048d3ce     MOV        dword ptr [EBP],EAX
    //         0048d3d1     CALL       rge_close                                        int rge_close(int param_1)
    //         0048d3d6     ADD        ESP,0x4
    //                               LAB_0048d3d9                                                 XREF[2]:     0048d338(j), 0048d3af(j)  
    //         0048d3d9     MOV        this,dword ptr [ESP + count]
    //         0048d3dd     LEA        EAX=>file_info.time_create,[ESP + 0x128]
    //         0048d3e4     PUSH       EAX
    //         0048d3e5     PUSH       this=>DAT_fffffff8
    //         0048d3e6     ADD        EBP,0x10c
    //         0048d3ec     CALL       __findnext                                       undefined __findnext()
    //         0048d3f1     ADD        ESP,0x8
    //         0048d3f4     CMP        EAX,-0x1
    //         0048d3f7     JNZ        LAB_0048d24d
    //         0048d3fd     MOV        AL,byte ptr [ESP + local_22e]
    //         0048d401     TEST       AL,AL
    //         0048d403     JNZ        LAB_0048d44e
    //         0048d405     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         0048d40b     LEA        this=>file_name[4],[ESP + 0x28]
    //         0048d40f     MOV        EAX,dword ptr [EDX + 0xc]
    //         0048d412     ADD        EAX,0xc17
    //         0048d417     PUSH       EAX
    //         0048d418     PUSH       s_%s*.scx                                        = "%s*.scx"
    //         0048d41d     PUSH       this
    //         0048d41e     CALL       sprintf                                          undefined sprintf()
    //         0048d423     ADD        ESP,0xc
    //         0048d426     LEA        EDX=>file_info.time_create,[ESP + 0x128]
    //         0048d42d     LEA        EAX=>file_name[4],[ESP + 0x28]
    //         0048d431     PUSH       EDX
    //         0048d432     PUSH       EAX
    //         0048d433     CALL       __findfirst                                      undefined __findfirst()
    //         0048d438     ADD        ESP,0x8
    //         0048d43b     CMP        EAX,-0x1
    //         0048d43e     MOV        dword ptr [ESP + count],EAX
    //         0048d442     JZ         LAB_0048d44e
    //         0048d444     MOV        byte ptr [ESP + local_22e],0x1
    //         0048d449     JMP        LAB_0048d24d
    //                               LAB_0048d44e                                                 XREF[2]:     0048d403(j), 0048d442(j)  
    //                              sceninfo.cpp:215 (10)
    //         0048d44e     MOV        EAX,dword ptr [EBX + 0x108]
    //         0048d454     TEST       EAX,EAX
    //         0048d456     JZ         LAB_0048d4a4
    //                              sceninfo.cpp:217 (12)
    //         0048d458     MOV        EAX,dword ptr [EBX + 0x104]
    //         0048d45e     XOR        EBP,EBP
    //         0048d460     TEST       EAX,EAX
    //         0048d462     JLE        LAB_0048d495
    //                              sceninfo.cpp:230 (2)
    //         0048d464     XOR        EDI,EDI
    //                               LAB_0048d466                                                 XREF[1]:     0048d493(j)  
    //                              sceninfo.cpp:219 (14)
    //         0048d466     MOV        this,dword ptr [EBX + 0x108]
    //         0048d46c     MOV        ESI,dword ptr [EDI + this->filename[0]*0x1 + 0
    //         0048d470     TEST       ESI,ESI
    //         0048d472     JZ         LAB_0048d484
    //                              sceninfo.cpp:220 (33)
    //         0048d474     MOV        this,ESI
    //         0048d476     CALL       RGE_Scenario_Header::~RGE_Scenario_Header        void ~RGE_Scenario_Header(RGE_Scenario_Header
    //         0048d47b     PUSH       ESI
    //         0048d47c     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0048d481     ADD        ESP,0x4
    //                               LAB_0048d484                                                 XREF[1]:     0048d472(j)  
    //         0048d484     MOV        EAX,dword ptr [EBX + 0x104]
    //         0048d48a     INC        EBP
    //         0048d48b     ADD        EDI,0x10c
    //         0048d491     CMP        EBP,EAX
    //         0048d493     JL         LAB_0048d466
    //                               LAB_0048d495                                                 XREF[1]:     0048d462(j)  
    //                              sceninfo.cpp:222 (15)
    //         0048d495     MOV        EDX,dword ptr [EBX + 0x108]
    //         0048d49b     PUSH       EDX
    //         0048d49c     CALL       free                                             undefined free()
    //         0048d4a1     ADD        ESP,0x4
    //                               LAB_0048d4a4                                                 XREF[1]:     0048d456(j)  
    //                              sceninfo.cpp:226 (4)
    //         0048d4a4     MOV        EAX,dword ptr [ESP + version]
    //                              sceninfo.cpp:227 (16)
    //         0048d4a8     MOV        this,dword ptr [ESP + new_scenarios]
    //         0048d4ac     MOV        dword ptr [EBX + 0x108],EAX
    //         0048d4b2     MOV        dword ptr [EBX + 0x104],this
    //                               LAB_0048d4b8                                                 XREF[2]:     0048d1ca(j), 0048d232(j)  
    //                              sceninfo.cpp:230 (11)
    //         0048d4b8     POP        EDI
    //         0048d4b9     POP        ESI
    //         0048d4ba     POP        EBP
    //         0048d4bb     POP        EBX
    //         0048d4bc     ADD        ESP,0x230
    //         0048d4c2     RET
    //         0048d4c3     ??         90h
    //         0048d4c4     NOP
    //         0048d4c5     NOP
    //         0048d4c6     NOP
    //         0048d4c7     NOP
    //         0048d4c8     NOP
    //         0048d4c9     NOP
    //         0048d4ca     NOP
    //         0048d4cb     NOP
    //         0048d4cc     NOP
    //         0048d4cd     NOP
    //         0048d4ce     NOP
    //         0048d4cf     NOP
    return;
}

char* RGE_Scenario_File_Info::get_scenario_name(long param_1) {
    /* TODO: Stub */
    //                              char * __thiscall get_scenario_name(RGE_Scenario_File_Info * this, l
    //              char *            EAX:4          <RETURN>
    //              RGE_Scenario_F    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     0048d4d0(R)  
    //                               ?get_scenario_name@RGE_Scenario_File_Info@@QAEPADJ@Z         XREF[2]:     fillScenarios:004b453d(c), 
    //                               RGE_Scenario_File_Info::get_scenario_name                                 fillScenarios:004b5e75(c)  
    //                              sceninfo.cpp:236 (18)
    //         0048d4d0     MOV        EAX,dword ptr [ESP + param_1]
    //         0048d4d4     MOV        EDX,dword ptr [ECX + this->scenario_num]
    //         0048d4da     CMP        EAX,EDX
    //         0048d4dc     JGE        LAB_0048d4f9
    //         0048d4de     TEST       EAX,EAX
    //         0048d4e0     JL         LAB_0048d4f9
    //                              sceninfo.cpp:238 (20)
    //         0048d4e2     MOV        this,dword ptr [ECX + this->scenarios]
    //         0048d4e8     MOV        EDX,EAX
    //         0048d4ea     SHL        EDX,0x5
    //         0048d4ed     ADD        EDX,EAX
    //         0048d4ef     LEA        EAX,[EAX + EDX*0x2]
    //         0048d4f2     LEA        EAX,[ECX + EAX*0x4 + this+0x8]
    //                              sceninfo.cpp:240 (3)
    //         0048d4f6     RET        0x4
    //                               LAB_0048d4f9                                                 XREF[2]:     0048d4dc(j), 0048d4e0(j)  
    //                              sceninfo.cpp:239 (2)
    //         0048d4f9     XOR        EAX,EAX
    //                              sceninfo.cpp:240 (3)
    //         0048d4fb     RET        0x4
    //         0048d4fe     ??         90h
    //         0048d4ff     NOP
    return 0;
}

RGE_Scenario_Header* RGE_Scenario_File_Info::get_scenario_info(long param_1) {
    /* TODO: Stub */
    //                              RGE_Scenario_Header * __thiscall get_scenario_info(RGE_Scenario_File
    //              RGE_Scenario_H    EAX:4          <RETURN>
    //              RGE_Scenario_F    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     0048d500(R)  
    //                               ?get_scenario_info@RGE_Scenario_File_Info@@QAEPAVRGE_Scenar  XREF[2]:     fillScenarios:004b45f9(c), 
    //                               RGE_Scenario_File_Info::get_scenario_info                                 fillScenarios:004b5f87(c)  
    //                              sceninfo.cpp:246 (18)
    //         0048d500     MOV        EAX,dword ptr [ESP + param_1]
    //         0048d504     MOV        EDX,dword ptr [ECX + this->scenario_num]
    //         0048d50a     CMP        EAX,EDX
    //         0048d50c     JGE        LAB_0048d529
    //         0048d50e     TEST       EAX,EAX
    //         0048d510     JL         LAB_0048d529
    //                              sceninfo.cpp:248 (20)
    //         0048d512     MOV        this,dword ptr [ECX + this->scenarios]
    //         0048d518     MOV        EDX,EAX
    //         0048d51a     SHL        EDX,0x5
    //         0048d51d     ADD        EDX,EAX
    //         0048d51f     LEA        EAX,[EAX + EDX*0x2]
    //         0048d522     MOV        EAX,dword ptr [ECX + EAX*this+0x4 + 0x4]
    //                              sceninfo.cpp:250 (3)
    //         0048d526     RET        0x4
    //                               LAB_0048d529                                                 XREF[2]:     0048d50c(j), 0048d510(j)  
    //                              sceninfo.cpp:249 (2)
    //         0048d529     XOR        EAX,EAX
    //                              sceninfo.cpp:250 (3)
    //         0048d52b     RET        0x4
    //         0048d52e     ??         90h
    //         0048d52f     NOP
    return 0;
}

