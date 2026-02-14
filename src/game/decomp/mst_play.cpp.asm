// Auto-generated scaffold unit: mst_play.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/mst_play.cpp
#include "../include/common.h"

// Offset: 0x00460FD0
undefined RGE_Master_Player(RGE_Master_Player* this_, FILE* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Master_Player::RGE_Master_Player(struct _iobuf *)                              *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Master_Player(RGE_Master_Player * this, _io
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Master_Pla    ECX:4 (auto)   this
    //              _iobuf *          Stack[0x4]:4   param_1                   XREF[4]:     00460fd6(R), 00461020(*), 00461035(R), 00461064(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0046103c(*), 00461056(R)  
    //              float             Stack[-0x8]:4  temp_amount               XREF[2,2]:   00461040(*), 00461051(R), 0046106b(*), 0046107b(R)  
    //              short             Stack[-0xa]:2  temp_culture
    //              short             Stack[-0xc]:2  temp_index
    //                               ??0RGE_Master_Player@@QAE@PAU_iobuf@@@Z                      XREF[2]:     TRIBE_Master_Player:005117c8(c), 
    //                               RGE_Master_Player::RGE_Master_Player                                      data_load_players_type:00541281(c)
    //                              mst_play.cpp:28 (6)
    //         00460fd0     SUB        ESP,0x8
    //         00460fd3     PUSH       EBX
    //         00460fd4     PUSH       EBP
    //         00460fd5     PUSH       ESI
    //                              mst_play.cpp:37 (41)
    //         00460fd6     MOV        EBP,dword ptr [ESP + param_1]
    //         00460fda     MOV        ESI,this
    //         00460fdc     PUSH       EDI
    //         00460fdd     XOR        EBX,EBX
    //         00460fdf     LEA        EDI,[ESI + 0x20]
    //         00460fe2     LEA        EAX,[ESI + 0x2a]
    //         00460fe5     PUSH       EDI
    //         00460fe6     LEA        this,[ESI + 0x4]
    //         00460fe9     PUSH       EAX
    //         00460fea     PUSH       this
    //         00460feb     PUSH       s_%s_%hd_%hd                                     = "%s %hd %hd"
    //         00460ff0     PUSH       EBP
    //         00460ff1     MOV        dword ptr [ESI],RGE_Master_Player::`vftable'     = 004610a0
    //         00460ff7     MOV        byte ptr [ESI + 0x29],BL
    //         00460ffa     CALL       fscanf                                           undefined fscanf()
    //                              mst_play.cpp:39 (11)
    //         00460fff     MOV        DI,word ptr [EDI]
    //         00461002     ADD        ESP,0x14
    //         00461005     CMP        DI,BX
    //         00461008     JLE        LAB_0046101d
    //                              mst_play.cpp:40 (17)
    //         0046100a     MOVSX      EDX,DI
    //         0046100d     PUSH       0x4
    //         0046100f     PUSH       EDX
    //         00461010     CALL       calloc                                           undefined calloc()
    //         00461015     ADD        ESP,0x8
    //         00461018     MOV        dword ptr [ESI + 0x24],EAX
    //                              mst_play.cpp:41 (2)
    //         0046101b     JMP        LAB_00461020
    //                               LAB_0046101d                                                 XREF[1]:     00461008(j)  
    //                              mst_play.cpp:42 (3)
    //         0046101d     MOV        dword ptr [ESI + 0x24],EBX
    //                               LAB_00461020                                                 XREF[1]:     0046101b(j)  
    //                              mst_play.cpp:44 (19)
    //         00461020     LEA        EAX=>param_1,[ESP + 0x1c]
    //         00461024     PUSH       EAX
    //         00461025     PUSH       s_%hd                                            = "%hd"
    //         0046102a     PUSH       EBP
    //         0046102b     CALL       fscanf                                           undefined fscanf()
    //         00461030     ADD        ESP,0xc
    //                              mst_play.cpp:45 (9)
    //         00461033     XOR        EDI,EDI
    //         00461035     CMP        word ptr [ESP + param_1],BX
    //         0046103a     JLE        LAB_0046106b
    //                               LAB_0046103c                                                 XREF[1]:     00461069(j)  
    //                              mst_play.cpp:47 (21)
    //         0046103c     LEA        this=>local_4,[ESP + 0x14]
    //         00461040     LEA        EDX=>temp_amount,[ESP + 0x10]
    //         00461044     PUSH       this
    //         00461045     PUSH       EDX
    //         00461046     PUSH       s_%hd_%f                                         = "%hd %f"
    //         0046104b     PUSH       EBP
    //         0046104c     CALL       fscanf                                           undefined fscanf()
    //                              mst_play.cpp:48 (26)
    //         00461051     MOVSX      EAX,word ptr [ESP + temp_amount]
    //         00461056     FLD        float ptr [ESP + local_4]
    //         0046105a     MOV        this,dword ptr [ESI + 0x24]
    //         0046105d     ADD        ESP,0x10
    //         00461060     INC        EDI
    //         00461061     FSTP       float ptr [this->_padding_ + EAX*0x4]
    //         00461064     CMP        DI,word ptr [ESP + param_1]
    //         00461069     JL         LAB_0046103c
    //                               LAB_0046106b                                                 XREF[1]:     0046103a(j)  
    //                              mst_play.cpp:51 (16)
    //         0046106b     LEA        EDX=>temp_amount+0x2,[ESP + 0x12]
    //         0046106f     PUSH       EDX
    //         00461070     PUSH       s_%hd                                            = "%hd"
    //         00461075     PUSH       EBP
    //         00461076     CALL       fscanf                                           undefined fscanf()
    //                              mst_play.cpp:53 (10)
    //         0046107b     MOV        AL,byte ptr [ESP + temp_amount+0x2]
    //         0046107f     ADD        ESP,0xc
    //         00461082     MOV        byte ptr [ESI + 0x28],AL
    //                              mst_play.cpp:55 (4)
    //         00461085     MOV        word ptr [ESI + 0x18],BX
    //                              mst_play.cpp:56 (3)
    //         00461089     MOV        dword ptr [ESI + 0x1c],EBX
    //                              mst_play.cpp:57 (12)
    //         0046108c     MOV        EAX,ESI
    //         0046108e     POP        EDI
    //         0046108f     POP        ESI
    //         00461090     POP        EBP
    //         00461091     POP        EBX
    //         00461092     ADD        ESP,0x8
    //         00461095     RET        0x4
}

// Offset: 0x004610C0
undefined RGE_Master_Player(RGE_Master_Player* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Master_Player::RGE_Master_Player(int)                                          *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Master_Player(RGE_Master_Player * this, int
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Master_Pla    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004610c5(R)  
    //                               ??0RGE_Master_Player@@QAE@H@Z                                XREF[2]:     TRIBE_Master_Player:00511808(c), 
    //                               RGE_Master_Player::RGE_Master_Player                                      init_player_type:005417b2(c)  
    //                              mst_play.cpp:62 (5)
    //         004610c0     PUSH       EBX
    //         004610c1     PUSH       ESI
    //         004610c2     MOV        ESI,this
    //         004610c4     PUSH       EDI
    //                              mst_play.cpp:63 (25)
    //         004610c5     MOV        EDI,dword ptr [ESP + param_1]
    //         004610c9     PUSH       0x14
    //         004610cb     LEA        EAX,[ESI + 0x4]
    //         004610ce     MOV        dword ptr [ESI],RGE_Master_Player::`vftable'     = 004610a0
    //         004610d4     PUSH       EAX
    //         004610d5     PUSH       EDI
    //         004610d6     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004610db     ADD        ESP,0xc
    //                              mst_play.cpp:64 (15)
    //         004610de     LEA        EBX,[ESI + 0x20]
    //         004610e1     PUSH       0x2
    //         004610e3     PUSH       EBX
    //         004610e4     PUSH       EDI
    //         004610e5     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004610ea     ADD        ESP,0xc
    //                              mst_play.cpp:65 (12)
    //         004610ed     LEA        this,[ESI + 0x2a]
    //         004610f0     PUSH       0x2
    //         004610f2     PUSH       this
    //         004610f3     PUSH       EDI
    //         004610f4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              mst_play.cpp:67 (11)
    //         004610f9     MOV        AX,word ptr [EBX]
    //         004610fc     ADD        ESP,0xc
    //         004610ff     TEST       AX,AX
    //         00461102     JLE        LAB_00461128
    //                              mst_play.cpp:69 (11)
    //         00461104     MOVSX      EDX,AX
    //         00461107     PUSH       0x4
    //         00461109     PUSH       EDX
    //         0046110a     CALL       calloc                                           undefined calloc()
    //                              mst_play.cpp:70 (23)
    //         0046110f     MOVSX      this,word ptr [EBX]
    //         00461112     ADD        ESP,0x8
    //         00461115     MOV        dword ptr [ESI + 0x24],EAX
    //         00461118     SHL        this,0x2
    //         0046111b     PUSH       this
    //         0046111c     PUSH       EAX
    //         0046111d     PUSH       EDI
    //         0046111e     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00461123     ADD        ESP,0xc
    //                              mst_play.cpp:72 (2)
    //         00461126     JMP        LAB_0046112f
    //                               LAB_00461128                                                 XREF[1]:     00461102(j)  
    //                              mst_play.cpp:73 (7)
    //         00461128     MOV        dword ptr [ESI + 0x24],0x0
    //                               LAB_0046112f                                                 XREF[1]:     00461126(j)  
    //                              mst_play.cpp:75 (15)
    //         0046112f     LEA        EDX,[ESI + 0x28]
    //         00461132     PUSH       0x1
    //         00461134     PUSH       EDX
    //         00461135     PUSH       EDI
    //         00461136     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0046113b     ADD        ESP,0xc
    //                              mst_play.cpp:76 (8)
    //         0046113e     MOV        EAX,ESI
    //         00461140     POP        EDI
    //         00461141     POP        ESI
    //         00461142     POP        EBX
    //         00461143     RET        0x4
}

// Offset: 0x00461150
void RGE_Master_Player(RGE_Master_Player* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall RGE_Master_Player::~RGE_Master_Player(void)                                *
    //                              *********************************************************************************************************
    //                              void __thiscall ~RGE_Master_Player(RGE_Master_Player * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Master_Pla    ECX:4 (auto)   this
    //                               ??1RGE_Master_Player@@UAE@XZ                                 XREF[2]:     `vector_deleting_destructor':00461
    //                               RGE_Master_Player::~RGE_Master_Player                                     ~TRIBE_Master_Player:00511826(c)  
    //                              mst_play.cpp:80 (6)
    //         00461150     PUSH       EBX
    //         00461151     PUSH       EBP
    //         00461152     PUSH       ESI
    //         00461153     PUSH       EDI
    //         00461154     MOV        EDI,this
    //                              mst_play.cpp:83 (21)
    //         00461156     XOR        EBP,EBP
    //         00461158     CMP        word ptr [EDI + 0x20],BP
    //         0046115c     MOV        dword ptr [EDI],RGE_Master_Player::`vftable'     = 004610a0
    //         00461162     JLE        LAB_0046117b
    //         00461164     MOV        EAX,dword ptr [EDI + 0x24]
    //         00461167     CMP        EAX,EBP
    //         00461169     JZ         LAB_0046117b
    //                              mst_play.cpp:85 (9)
    //         0046116b     PUSH       EAX
    //         0046116c     CALL       free                                             undefined free()
    //         00461171     ADD        ESP,0x4
    //                              mst_play.cpp:86 (3)
    //         00461174     MOV        dword ptr [EDI + 0x24],EBP
    //                              mst_play.cpp:87 (4)
    //         00461177     MOV        word ptr [EDI + 0x20],BP
    //                               LAB_0046117b                                                 XREF[2]:     00461162(j), 00461169(j)  
    //                              mst_play.cpp:90 (14)
    //         0046117b     MOV        AX,word ptr [EDI + 0x18]
    //         0046117f     CMP        AX,BP
    //         00461182     JLE        LAB_004611c6
    //         00461184     CMP        dword ptr [EDI + 0x1c],EBP
    //         00461187     JZ         LAB_004611c6
    //                              mst_play.cpp:92 (7)
    //         00461189     XOR        EBX,EBX
    //         0046118b     CMP        AX,BP
    //         0046118e     JLE        LAB_004611b3
    //                               LAB_00461190                                                 XREF[1]:     004611b1(j)  
    //                              mst_play.cpp:93 (16)
    //         00461190     MOV        EAX,dword ptr [EDI + 0x1c]
    //         00461193     MOVSX      ESI,BX
    //         00461196     SHL        ESI,0x2
    //         00461199     MOV        this,dword ptr [EAX + ESI*0x1]
    //         0046119c     CMP        this,EBP
    //         0046119e     JZ         LAB_004611ac
    //                              mst_play.cpp:95 (6)
    //         004611a0     MOV        EDX,dword ptr [this->_padding_]
    //         004611a2     PUSH       0x1
    //         004611a4     CALL       dword ptr [EDX]
    //                              mst_play.cpp:96 (13)
    //         004611a6     MOV        EAX,dword ptr [EDI + 0x1c]
    //         004611a9     MOV        dword ptr [EAX + ESI*0x1],EBP
    //                               LAB_004611ac                                                 XREF[1]:     0046119e(j)  
    //         004611ac     INC        EBX
    //         004611ad     CMP        BX,word ptr [EDI + 0x18]
    //         004611b1     JL         LAB_00461190
    //                               LAB_004611b3                                                 XREF[1]:     0046118e(j)  
    //                              mst_play.cpp:99 (12)
    //         004611b3     MOV        this,dword ptr [EDI + 0x1c]
    //         004611b6     PUSH       this
    //         004611b7     CALL       free                                             undefined free()
    //         004611bc     ADD        ESP,0x4
    //                              mst_play.cpp:100 (3)
    //         004611bf     MOV        dword ptr [EDI + 0x1c],EBP
    //                              mst_play.cpp:101 (4)
    //         004611c2     MOV        word ptr [EDI + 0x18],BP
    //                               LAB_004611c6                                                 XREF[2]:     00461182(j), 00461187(j)  
    //                              mst_play.cpp:103 (5)
    //         004611c6     POP        EDI
    //         004611c7     POP        ESI
    //         004611c8     POP        EBP
    //         004611c9     POP        EBX
    //         004611ca     RET
}

// Offset: 0x004611D0
void TRIBE_Master_Player::finish_init(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Master_Player::finish_init(int,class RGE_Sprite * *,class RGE_... *
    //                              *********************************************************************************************************
    //                              void __thiscall finish_init(RGE_Master_Player * this, int param_1, R
    //              void              <VOID>         <RETURN>
    //              RGE_Master_Pla    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[3]:     004611d1(R), 00461229(*), 00461245(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     0046123a(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     00461236(R)  
    //                               ?finish_init@RGE_Master_Player@@UAEXHPAPAVRGE_Sprite@@PAPAV  XREF[2]:     00570c0c(*), 00576804(*)  
    //                               RGE_Master_Player::finish_init
    //                              mst_play.cpp:107 (1)
    //         004611d0     PUSH       EBX
    //                              mst_play.cpp:112 (21)
    //         004611d1     MOV        EBX,dword ptr [ESP + param_1]
    //         004611d5     PUSH       EBP
    //         004611d6     PUSH       ESI
    //         004611d7     MOV        ESI,this
    //         004611d9     PUSH       EDI
    //         004611da     PUSH       0x2
    //         004611dc     LEA        EBP,[ESI + 0x18]
    //         004611df     PUSH       EBP
    //         004611e0     PUSH       EBX
    //         004611e1     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              mst_play.cpp:114 (14)
    //         004611e6     MOV        AX,word ptr [EBP]
    //         004611ea     XOR        EDI,EDI
    //         004611ec     ADD        ESP,0xc
    //         004611ef     CMP        AX,DI
    //         004611f2     JLE        LAB_0046125f
    //                              mst_play.cpp:116 (11)
    //         004611f4     MOVSX      EAX,AX
    //         004611f7     PUSH       0x4
    //         004611f9     PUSH       EAX
    //         004611fa     CALL       calloc                                           undefined calloc()
    //                              mst_play.cpp:118 (24)
    //         004611ff     MOVSX      this,word ptr [EBP]
    //         00461203     ADD        ESP,0x8
    //         00461206     MOV        dword ptr [ESI + 0x1c],EAX
    //         00461209     SHL        this,0x2
    //         0046120c     PUSH       this
    //         0046120d     PUSH       EAX
    //         0046120e     PUSH       EBX
    //         0046120f     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00461214     ADD        ESP,0xc
    //                              mst_play.cpp:119 (6)
    //         00461217     CMP        word ptr [EBP],DI
    //         0046121b     JLE        LAB_00461262
    //                               LAB_0046121d                                                 XREF[1]:     00461256(j)  
    //                              mst_play.cpp:120 (12)
    //         0046121d     MOV        EAX,dword ptr [ESI + 0x1c]
    //         00461220     MOVSX      EDX,DI
    //         00461223     CMP        dword ptr [EAX + EDX*0x4],0x0
    //         00461227     JZ         LAB_00461251
    //                              mst_play.cpp:122 (13)
    //         00461229     LEA        this=>param_1,[ESP + 0x14]
    //         0046122d     PUSH       0x1
    //         0046122f     PUSH       this=>DAT_fffffff8
    //         00461230     PUSH       EBX=>DAT_fffffff4
    //         00461231     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              mst_play.cpp:123 (34)
    //         00461236     MOV        EAX,dword ptr [ESP + param_3]
    //         0046123a     MOV        this,dword ptr [ESP + param_2]
    //         0046123e     MOV        EDX,dword ptr [ESI]
    //         00461240     ADD        ESP,0xc
    //         00461243     PUSH       EDI
    //         00461244     PUSH       EAX
    //         00461245     MOV        EAX,dword ptr [ESP + param_1]
    //         00461249     PUSH       this
    //         0046124a     PUSH       EAX
    //         0046124b     PUSH       EBX
    //         0046124c     MOV        this,ESI
    //         0046124e     CALL       dword ptr [EDX + 0x8]
    //                               LAB_00461251                                                 XREF[1]:     00461227(j)  
    //         00461251     INC        EDI
    //         00461252     CMP        DI,word ptr [EBP]
    //         00461256     JL         LAB_0046121d
    //                              mst_play.cpp:128 (7)
    //         00461258     POP        EDI
    //         00461259     POP        ESI
    //         0046125a     POP        EBP
    //         0046125b     POP        EBX
    //         0046125c     RET        0xc
    //                               LAB_0046125f                                                 XREF[1]:     004611f2(j)  
    //                              mst_play.cpp:127 (3)
    //         0046125f     MOV        dword ptr [ESI + 0x1c],EDI
    //                               LAB_00461262                                                 XREF[1]:     0046121b(j)  
    //                              mst_play.cpp:128 (7)
    //         00461262     POP        EDI
    //         00461263     POP        ESI
    //         00461264     POP        EBP
    //         00461265     POP        EBX
    //         00461266     RET        0xc
}

// Offset: 0x00461270
void RGE_Master_Player::load_master_object(int param_1, uchar param_2, RGE_Sprite** param_3, RGE_Sound** param_4, short param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Master_Player::load_master_object(int,unsigned char,class RGE_... *
    //                              *********************************************************************************************************
    //                              void __thiscall load_master_object(RGE_Master_Player * this, int par
    //              void              <VOID>         <RETURN>
    //              RGE_Master_Pla    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[7]:     004612d8(R), 00461316(R), 0046136c(R), 004613aa(R), 
    //                                                                                     00461400(R), 0046143a(R), 004614ab(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[8]:     0046127e(R), 004612b9(W), 004612f7(W), 0046134d(W), 
    //                                                                                     0046138b(W), 004613e1(W), 0046141f(W), 00461490(W)  
    //              RGE_Sprite * *    Stack[0xc]:4   param_3                   XREF[7]:     004612d1(R), 0046130f(R), 00461365(R), 004613a3(R), 
    //                                                                                     004613f9(R), 00461433(R), 004614a4(R)  
    //              RGE_Sound * *     Stack[0x10]:4  param_4                   XREF[7]:     004612cd(R), 0046130b(R), 00461361(R), 0046139f(R), 
    //                                                                                     004613f5(R), 0046142f(R), 004614a0(R)  
    //              short             Stack[0x14]:2  param_5                   XREF[5]:     00461323(R), 004613b7(R), 00461447(R), 00461464(R), 
    //                                                                                     004614bc(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[7]:     004612bf(W), 004612fd(W), 00461353(W), 00461391(W), 
    //                                                                                     004613e7(W), 00461425(W), 00461496(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[5]:     0046132e(R), 004613c2(R), 00461452(R), 00461471(R), 
    //                                                                                     004614c7(R)  
    //                               ?load_master_object@RGE_Master_Player@@UAEXHEPAPAVRGE_Sprit  XREF[2]:     load_master_object:00511873(c), 
    //                               RGE_Master_Player::load_master_object                                     00570c10(*)  
    //                              mst_play.cpp:132 (14)
    //         00461270     MOV        EAX,FS:[0x0]
    //         00461276     PUSH       -0x1
    //         00461278     PUSH       FUN_0055dd5d
    //         0046127d     PUSH       EAX
    //                              mst_play.cpp:133 (46)
    //         0046127e     MOV        EAX,dword ptr [ESP + param_2]
    //         00461282     MOV        dword ptr FS:[0x0],ESP
    //         00461289     AND        EAX,0xff
    //         0046128e     PUSH       ESI
    //         0046128f     ADD        EAX,-0xa
    //         00461292     MOV        ESI,this
    //         00461294     CMP        EAX,0x32
    //         00461297     JA         switchD_004612a5::caseD_b
    //         0046129d     XOR        this,this
    //         0046129f     MOV        this,byte ptr [EAX + 0x4614fc]=>PTR_caseD_32_0
    //                               switchD_004612a5::switchD
    //         004612a5     JMP        dword ptr [this->_padding_*0x4 + switchD_00461   = 004612ac
    //                               switchD_004612a5::caseD_a                                    XREF[2]:     004612a5(j), 004614dc(*)  
    //                              mst_play.cpp:136 (57)
    //         004612ac     PUSH       0xb8
    //         004612b1     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004612b6     ADD        ESP,0x4
    //         004612b9     MOV        dword ptr [ESP + param_2],EAX
    //         004612bd     TEST       EAX,EAX
    //         004612bf     MOV        dword ptr [ESP + local_4],0x0
    //         004612c7     JZ         LAB_004614ba
    //         004612cd     MOV        EDX,dword ptr [ESP + param_4]
    //         004612d1     MOV        this,dword ptr [ESP + param_3]
    //         004612d5     PUSH       0x1
    //         004612d7     PUSH       EDX
    //         004612d8     MOV        EDX,dword ptr [ESP + param_1]
    //         004612dc     PUSH       this
    //         004612dd     PUSH       EDX
    //         004612de     MOV        this,EAX
    //         004612e0     CALL       RGE_Master_Static_Object::RGE_Master_Static_Ob   undefined RGE_Master_Static_Object(RGE_Master
    //                              mst_play.cpp:137 (5)
    //         004612e5     JMP        LAB_004614bc
    //                               switchD_004612a5::caseD_14                                   XREF[2]:     004612a5(j), 004614e0(*)  
    //                              mst_play.cpp:139 (57)
    //         004612ea     PUSH       0xbc
    //         004612ef     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004612f4     ADD        ESP,0x4
    //         004612f7     MOV        dword ptr [ESP + param_2],EAX
    //         004612fb     TEST       EAX,EAX
    //         004612fd     MOV        dword ptr [ESP + local_4],0x1
    //         00461305     JZ         LAB_00461464
    //         0046130b     MOV        this,dword ptr [ESP + param_4]
    //         0046130f     MOV        EDX,dword ptr [ESP + param_3]
    //         00461313     PUSH       0x1
    //         00461315     PUSH       this
    //         00461316     MOV        this,dword ptr [ESP + param_1]
    //         0046131a     PUSH       EDX
    //         0046131b     PUSH       this
    //         0046131c     MOV        this,EAX
    //         0046131e     CALL       RGE_Master_Animated_Object::RGE_Master_Animate   undefined RGE_Master_Animated_Object(RGE_Mast
    //                              mst_play.cpp:151 (11)
    //         00461323     MOVSX      EDX,word ptr [ESP + param_5]
    //         00461328     MOV        this,dword ptr [ESI + 0x1c]
    //         0046132b     MOV        dword ptr [this->_padding_ + EDX*0x4],EAX
    //                              mst_play.cpp:161 (18)
    //         0046132e     MOV        this,dword ptr [ESP + local_c]
    //         00461332     MOV        dword ptr FS:[0x0],this
    //         00461339     POP        ESI
    //         0046133a     ADD        ESP,0xc
    //         0046133d     RET        0x14
    //                               switchD_004612a5::caseD_1e                                   XREF[2]:     004612a5(j), 004614e8(*)  
    //                              mst_play.cpp:142 (62)
    //         00461340     PUSH       0xd8
    //         00461345     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0046134a     ADD        ESP,0x4
    //         0046134d     MOV        dword ptr [ESP + param_2],EAX
    //         00461351     TEST       EAX,EAX
    //         00461353     MOV        dword ptr [ESP + local_4],0x2
    //         0046135b     JZ         LAB_004614ba
    //         00461361     MOV        EDX,dword ptr [ESP + param_4]
    //         00461365     MOV        this,dword ptr [ESP + param_3]
    //         00461369     PUSH       0x1
    //         0046136b     PUSH       EDX
    //         0046136c     MOV        EDX,dword ptr [ESP + param_1]
    //         00461370     PUSH       this
    //         00461371     PUSH       EDX
    //         00461372     MOV        this,EAX
    //         00461374     CALL       RGE_Master_Moving_Object::RGE_Master_Moving_Ob   undefined RGE_Master_Moving_Object(RGE_Master
    //         00461379     JMP        LAB_004614bc
    //                               switchD_004612a5::caseD_3c                                   XREF[2]:     004612a5(j), 004614f4(*)  
    //                              mst_play.cpp:145 (57)
    //         0046137e     PUSH       0x154
    //         00461383     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00461388     ADD        ESP,0x4
    //         0046138b     MOV        dword ptr [ESP + param_2],EAX
    //         0046138f     TEST       EAX,EAX
    //         00461391     MOV        dword ptr [ESP + local_4],0x3
    //         00461399     JZ         LAB_00461464
    //         0046139f     MOV        this,dword ptr [ESP + param_4]
    //         004613a3     MOV        EDX,dword ptr [ESP + param_3]
    //         004613a7     PUSH       0x1
    //         004613a9     PUSH       this
    //         004613aa     MOV        this,dword ptr [ESP + param_1]
    //         004613ae     PUSH       EDX
    //         004613af     PUSH       this
    //         004613b0     MOV        this,EAX
    //         004613b2     CALL       RGE_Master_Missile_Object::RGE_Master_Missile_   undefined RGE_Master_Missile_Object(RGE_Maste
    //                              mst_play.cpp:151 (11)
    //         004613b7     MOVSX      EDX,word ptr [ESP + param_5]
    //         004613bc     MOV        this,dword ptr [ESI + 0x1c]
    //         004613bf     MOV        dword ptr [this->_padding_ + EDX*0x4],EAX
    //                              mst_play.cpp:161 (18)
    //         004613c2     MOV        this,dword ptr [ESP + local_c]
    //         004613c6     MOV        dword ptr FS:[0x0],this
    //         004613cd     POP        ESI
    //         004613ce     ADD        ESP,0xc
    //         004613d1     RET        0x14
    //                               switchD_004612a5::caseD_28                                   XREF[2]:     004612a5(j), 004614ec(*)  
    //                              mst_play.cpp:148 (62)
    //         004613d4     PUSH       0xfc
    //         004613d9     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004613de     ADD        ESP,0x4
    //         004613e1     MOV        dword ptr [ESP + param_2],EAX
    //         004613e5     TEST       EAX,EAX
    //         004613e7     MOV        dword ptr [ESP + local_4],0x4
    //         004613ef     JZ         LAB_004614ba
    //         004613f5     MOV        EDX,dword ptr [ESP + param_4]
    //         004613f9     MOV        this,dword ptr [ESP + param_3]
    //         004613fd     PUSH       0x1
    //         004613ff     PUSH       EDX
    //         00461400     MOV        EDX,dword ptr [ESP + param_1]
    //         00461404     PUSH       this
    //         00461405     PUSH       EDX
    //         00461406     MOV        this,EAX
    //         00461408     CALL       RGE_Master_Action_Object::RGE_Master_Action_Ob   undefined RGE_Master_Action_Object(RGE_Master
    //         0046140d     JMP        LAB_004614bc
    //                               switchD_004612a5::caseD_32                                   XREF[2]:     004612a5(j), 004614f0(*)  
    //                              mst_play.cpp:151 (64)
    //         00461412     PUSH       0x148
    //         00461417     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0046141c     ADD        ESP,0x4
    //         0046141f     MOV        dword ptr [ESP + param_2],EAX
    //         00461423     TEST       EAX,EAX
    //         00461425     MOV        dword ptr [ESP + local_4],0x5
    //         0046142d     JZ         LAB_00461464
    //         0046142f     MOV        this,dword ptr [ESP + param_4]
    //         00461433     MOV        EDX,dword ptr [ESP + param_3]
    //         00461437     PUSH       0x1
    //         00461439     PUSH       this
    //         0046143a     MOV        this,dword ptr [ESP + param_1]
    //         0046143e     PUSH       EDX
    //         0046143f     PUSH       this
    //         00461440     MOV        this,EAX
    //         00461442     CALL       RGE_Master_Combat_Object::RGE_Master_Combat_Ob   undefined RGE_Master_Combat_Object(RGE_Master
    //         00461447     MOVSX      EDX,word ptr [ESP + param_5]
    //         0046144c     MOV        this,dword ptr [ESI + 0x1c]
    //         0046144f     MOV        dword ptr [this->_padding_ + EDX*0x4],EAX
    //                              mst_play.cpp:161 (18)
    //         00461452     MOV        this,dword ptr [ESP + local_c]
    //         00461456     MOV        dword ptr FS:[0x0],this
    //         0046145d     POP        ESI
    //         0046145e     ADD        ESP,0xc
    //         00461461     RET        0x14
    //                               LAB_00461464                                                 XREF[3]:     00461305(j), 00461399(j), 
    //                                                                                                         0046142d(j)  
    //                              mst_play.cpp:151 (13)
    //         00461464     MOVSX      EDX,word ptr [ESP + param_5]
    //         00461469     MOV        this,dword ptr [ESI + 0x1c]
    //         0046146c     XOR        EAX,EAX
    //         0046146e     MOV        dword ptr [this->_padding_ + EDX*0x4],EAX
    //                              mst_play.cpp:161 (18)
    //         00461471     MOV        this,dword ptr [ESP + local_c]
    //         00461475     MOV        dword ptr FS:[0x0],this
    //         0046147c     POP        ESI
    //         0046147d     ADD        ESP,0xc
    //         00461480     RET        0x14
    //                               switchD_004612a5::caseD_19                                   XREF[2]:     004612a5(j), 004614e4(*)  
    //                              mst_play.cpp:154 (68)
    //         00461483     PUSH       0xbc
    //         00461488     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0046148d     ADD        ESP,0x4
    //         00461490     MOV        dword ptr [ESP + param_2],EAX
    //         00461494     TEST       EAX,EAX
    //         00461496     MOV        dword ptr [ESP + local_4],0x6
    //         0046149e     JZ         LAB_004614ba
    //         004614a0     MOV        EDX,dword ptr [ESP + param_4]
    //         004614a4     MOV        this,dword ptr [ESP + param_3]
    //         004614a8     PUSH       0x1
    //         004614aa     PUSH       EDX
    //         004614ab     MOV        EDX,dword ptr [ESP + param_1]
    //         004614af     PUSH       this
    //         004614b0     PUSH       EDX
    //         004614b1     MOV        this,EAX
    //         004614b3     CALL       RGE_Master_Doppleganger_Object::RGE_Master_Dop   undefined RGE_Master_Doppleganger_Object(RGE_
    //         004614b8     JMP        LAB_004614bc
    //                               LAB_004614ba                                                 XREF[4]:     004612c7(j), 0046135b(j), 
    //                                                                                                         004613ef(j), 0046149e(j)  
    //         004614ba     XOR        EAX,EAX
    //                               LAB_004614bc                                                 XREF[4]:     004612e5(j), 00461379(j), 
    //                                                                                                         0046140d(j), 004614b8(j)  
    //         004614bc     MOVSX      this,word ptr [ESP + param_5]
    //         004614c1     MOV        EDX,dword ptr [ESI + 0x1c]
    //         004614c4     MOV        dword ptr [EDX + this->_padding_*0x4],EAX
    //                               switchD_004612a5::caseD_c                                    XREF[3]:     00461297(j), 004612a5(j), 
    //                               switchD_004612a5::caseD_d                                                 004614f8(*)  
    //                               switchD_004612a5::caseD_e
    //                               switchD_004612a5::caseD_f
    //                               switchD_004612a5::caseD_10
    //                               switchD_004612a5::caseD_11
    //                               switchD_004612a5::caseD_12
    //                               switchD_004612a5::caseD_13
    //                               switchD_004612a5::caseD_15
    //                               switchD_004612a5::caseD_16
    //                               switchD_004612a5::caseD_17
    //                               switchD_004612a5::caseD_18
    //                               switchD_004612a5::caseD_1a
    //                               switchD_004612a5::caseD_1b
    //                               switchD_004612a5::caseD_1c
    //                               switchD_004612a5::caseD_1d
    //                               switchD_004612a5::caseD_1f
    //                               switchD_004612a5::caseD_20
    //                               switchD_004612a5::caseD_21
    //                               switchD_004612a5::caseD_22
    //                               switchD_004612a5::caseD_23
    //                               switchD_004612a5::caseD_24
    //                               switchD_004612a5::caseD_25
    //                               switchD_004612a5::caseD_26
    //                               switchD_004612a5::caseD_27
    //                               switchD_004612a5::caseD_29
    //                               switchD_004612a5::caseD_2a
    //                               switchD_004612a5::caseD_2b
    //                               switchD_004612a5::caseD_2c
    //                               switchD_004612a5::caseD_2d
    //                               switchD_004612a5::caseD_2e
    //                               switchD_004612a5::caseD_2f
    //                               switchD_004612a5::caseD_30
    //                               switchD_004612a5::caseD_31
    //                               switchD_004612a5::caseD_33
    //                               switchD_004612a5::caseD_34
    //                               switchD_004612a5::caseD_35
    //                               switchD_004612a5::caseD_36
    //                               switchD_004612a5::caseD_37
    //                               switchD_004612a5::caseD_38
    //                               switchD_004612a5::caseD_39
    //                               switchD_004612a5::caseD_3a
    //                               switchD_004612a5::caseD_3b
    //                               switchD_004612a5::caseD_b
    //                              mst_play.cpp:161 (104)
    //         004614c7     MOV        this,dword ptr [ESP + local_c]
    //         004614cb     POP        ESI
    //         004614cc     MOV        dword ptr FS:[0x0],this
    //         004614d3     ADD        ESP,0xc
    //         004614d6     RET        0x14
}

// Offset: 0x004614D9
undefined FUN_004614d9() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_004614d9()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_004614d9
    //         004614d9     NOP
    //         004614da     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004612a5::switchdataD_004614dc                       XREF[1]:     load_master_object:004612a5(*)  
}

// Offset: 0x00461530
void TRIBE_Master_Player::create_master_object_space(short param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Master_Player::create_master_object_space(short)                  *
    //                              *********************************************************************************************************
    //                              void __thiscall create_master_object_space(RGE_Master_Player * this,
    //              void              <VOID>         <RETURN>
    //              RGE_Master_Pla    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     00461530(R)  
    //                               ?create_master_object_space@RGE_Master_Player@@UAEXF@Z       XREF[2]:     00570c14(*), 0057680c(*)  
    //                               RGE_Master_Player::create_master_object_space
    //                              mst_play.cpp:166 (8)
    //         00461530     MOV        AX,word ptr [ESP + param_1]
    //         00461535     PUSH       ESI
    //         00461536     MOV        ESI,this
    //                              mst_play.cpp:169 (9)
    //         00461538     TEST       AX,AX
    //         0046153b     MOV        word ptr [ESI + 0x18],AX
    //         0046153f     JLE        LAB_00461552
    //                              mst_play.cpp:170 (17)
    //         00461541     MOVSX      EAX,AX
    //         00461544     PUSH       0x4
    //         00461546     PUSH       EAX
    //         00461547     CALL       calloc                                           undefined calloc()
    //         0046154c     ADD        ESP,0x8
    //         0046154f     MOV        dword ptr [ESI + 0x1c],EAX
    //                               LAB_00461552                                                 XREF[1]:     0046153f(j)  
    //                              mst_play.cpp:171 (4)
    //         00461552     POP        ESI
    //         00461553     RET        0x4
}

// Offset: 0x00461560
void RGE_Master_Player::load_object(FILE* param_1, uchar param_2, RGE_Sprite** param_3, RGE_Sound** param_4, short param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Master_Player::load_object(struct _iobuf *,unsigned char,class... *
    //                              *********************************************************************************************************
    //                              void __thiscall load_object(RGE_Master_Player * this, _iobuf * param
    //              void              <VOID>         <RETURN>
    //              RGE_Master_Pla    ECX:4 (auto)   this
    //              _iobuf *          Stack[0x4]:4   param_1                   XREF[7]:     004615ce(R), 00461611(R), 0046166b(R), 004616ae(R), 
    //                                                                                     00461708(R), 00461747(R), 004617bb(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[8]:     0046156e(R), 004615aa(W), 004615ed(W), 00461647(W), 
    //                                                                                     0046168a(W), 004616e4(W), 00461727(W), 0046179b(W)  
    //              RGE_Sprite * *    Stack[0xc]:4   param_3                   XREF[7]:     004615c6(R), 00461609(R), 00461663(R), 004616a6(R), 
    //                                                                                     00461700(R), 0046173f(R), 004617b3(R)  
    //              RGE_Sound * *     Stack[0x10]:4  param_4                   XREF[7]:     004615c2(R), 00461605(R), 0046165f(R), 004616a2(R), 
    //                                                                                     004616fc(R), 0046173b(R), 004617af(R)  
    //              short             Stack[0x14]:2  param_5                   XREF[7]:     004615ae(R), 004615f1(R), 0046164b(R), 0046168e(R), 
    //                                                                                     004616e8(R), 0046172b(R), 0046179f(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[7]:     004615b2(W), 004615f5(W), 0046164f(W), 00461692(W), 
    //                                                                                     004616ec(W), 0046172f(W), 004617a3(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[5]:     00461627(R), 004616c4(R), 0046175d(R), 0046177b(R), 
    //                                                                                     004617d5(R)  
    //                               ?load_object@RGE_Master_Player@@UAEXPAU_iobuf@@EPAPAVRGE_Sp  XREF[2]:     load_object:005119d4(c), 
    //                               RGE_Master_Player::load_object                                            00570c18(*)  
    //                              mst_play.cpp:176 (14)
    //         00461560     MOV        EAX,FS:[0x0]
    //         00461566     PUSH       -0x1
    //         00461568     PUSH       FUN_0055ddbd
    //         0046156d     PUSH       EAX
    //                              mst_play.cpp:177 (47)
    //         0046156e     MOV        EAX,dword ptr [ESP + param_2]
    //         00461572     MOV        dword ptr FS:[0x0],ESP
    //         00461579     AND        EAX,0xff
    //         0046157e     PUSH       ESI
    //         0046157f     ADD        EAX,-0xa
    //         00461582     PUSH       EDI
    //         00461583     CMP        EAX,0x32
    //         00461586     MOV        EDI,this
    //         00461588     JA         switchD_00461596::caseD_b
    //         0046158e     XOR        this,this
    //         00461590     MOV        this,byte ptr [EAX + 0x461808]=>PTR_caseD_32_0
    //                               switchD_00461596::switchD
    //         00461596     JMP        dword ptr [this->_padding_*0x4 + switchD_00461   = 0046159d
    //                               switchD_00461596::caseD_a                                    XREF[2]:     00461596(j), 004617e8(*)  
    //                              mst_play.cpp:180 (62)
    //         0046159d     PUSH       0xb8
    //         004615a2     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004615a7     ADD        ESP,0x4
    //         004615aa     MOV        dword ptr [ESP + param_2],EAX
    //         004615ae     MOV        ESI,dword ptr [ESP + param_5]
    //         004615b2     MOV        dword ptr [ESP + local_4],0x0
    //         004615ba     TEST       EAX,EAX
    //         004615bc     JZ         LAB_004617ca
    //         004615c2     MOV        EDX,dword ptr [ESP + param_4]
    //         004615c6     MOV        this,dword ptr [ESP + param_3]
    //         004615ca     PUSH       0x1
    //         004615cc     PUSH       ESI
    //         004615cd     PUSH       EDX
    //         004615ce     MOV        EDX,dword ptr [ESP + param_1]
    //         004615d2     PUSH       this
    //         004615d3     PUSH       EDX
    //         004615d4     MOV        this,EAX
    //         004615d6     CALL       RGE_Master_Static_Object::RGE_Master_Static_Ob   undefined RGE_Master_Static_Object(RGE_Master
    //                              mst_play.cpp:181 (5)
    //         004615db     JMP        LAB_004617cc
    //                               switchD_00461596::caseD_14                                   XREF[2]:     00461596(j), 004617ec(*)  
    //                              mst_play.cpp:183 (62)
    //         004615e0     PUSH       0xbc
    //         004615e5     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004615ea     ADD        ESP,0x4
    //         004615ed     MOV        dword ptr [ESP + param_2],EAX
    //         004615f1     MOV        ESI,dword ptr [ESP + param_5]
    //         004615f5     MOV        dword ptr [ESP + local_4],0x1
    //         004615fd     TEST       EAX,EAX
    //         004615ff     JZ         LAB_00461770
    //         00461605     MOV        this,dword ptr [ESP + param_4]
    //         00461609     MOV        EDX,dword ptr [ESP + param_3]
    //         0046160d     PUSH       0x1
    //         0046160f     PUSH       ESI
    //         00461610     PUSH       this
    //         00461611     MOV        this,dword ptr [ESP + param_1]
    //         00461615     PUSH       EDX
    //         00461616     PUSH       this
    //         00461617     MOV        this,EAX
    //         00461619     CALL       RGE_Master_Animated_Object::RGE_Master_Animate   undefined RGE_Master_Animated_Object(RGE_Mast
    //                              mst_play.cpp:195 (9)
    //         0046161e     MOV        this,dword ptr [EDI + 0x1c]
    //         00461621     MOVSX      EDX,SI
    //         00461624     MOV        dword ptr [this->_padding_ + EDX*0x4],EAX
    //                              mst_play.cpp:205 (19)
    //         00461627     MOV        this,dword ptr [ESP + local_c]
    //         0046162b     MOV        dword ptr FS:[0x0],this
    //         00461632     POP        EDI
    //         00461633     POP        ESI
    //         00461634     ADD        ESP,0xc
    //         00461637     RET        0x14
    //                               switchD_00461596::caseD_1e                                   XREF[2]:     00461596(j), 004617f4(*)  
    //                              mst_play.cpp:186 (67)
    //         0046163a     PUSH       0xd8
    //         0046163f     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00461644     ADD        ESP,0x4
    //         00461647     MOV        dword ptr [ESP + param_2],EAX
    //         0046164b     MOV        ESI,dword ptr [ESP + param_5]
    //         0046164f     MOV        dword ptr [ESP + local_4],0x2
    //         00461657     TEST       EAX,EAX
    //         00461659     JZ         LAB_004617ca
    //         0046165f     MOV        EDX,dword ptr [ESP + param_4]
    //         00461663     MOV        this,dword ptr [ESP + param_3]
    //         00461667     PUSH       0x1
    //         00461669     PUSH       ESI
    //         0046166a     PUSH       EDX
    //         0046166b     MOV        EDX,dword ptr [ESP + param_1]
    //         0046166f     PUSH       this
    //         00461670     PUSH       EDX
    //         00461671     MOV        this,EAX
    //         00461673     CALL       RGE_Master_Moving_Object::RGE_Master_Moving_Ob   undefined RGE_Master_Moving_Object(RGE_Master
    //         00461678     JMP        LAB_004617cc
    //                               switchD_00461596::caseD_3c                                   XREF[2]:     00461596(j), 00461800(*)  
    //                              mst_play.cpp:189 (62)
    //         0046167d     PUSH       0x154
    //         00461682     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00461687     ADD        ESP,0x4
    //         0046168a     MOV        dword ptr [ESP + param_2],EAX
    //         0046168e     MOV        ESI,dword ptr [ESP + param_5]
    //         00461692     MOV        dword ptr [ESP + local_4],0x3
    //         0046169a     TEST       EAX,EAX
    //         0046169c     JZ         LAB_00461770
    //         004616a2     MOV        this,dword ptr [ESP + param_4]
    //         004616a6     MOV        EDX,dword ptr [ESP + param_3]
    //         004616aa     PUSH       0x1
    //         004616ac     PUSH       ESI
    //         004616ad     PUSH       this
    //         004616ae     MOV        this,dword ptr [ESP + param_1]
    //         004616b2     PUSH       EDX
    //         004616b3     PUSH       this
    //         004616b4     MOV        this,EAX
    //         004616b6     CALL       RGE_Master_Missile_Object::RGE_Master_Missile_   undefined RGE_Master_Missile_Object(RGE_Maste
    //                              mst_play.cpp:195 (9)
    //         004616bb     MOV        this,dword ptr [EDI + 0x1c]
    //         004616be     MOVSX      EDX,SI
    //         004616c1     MOV        dword ptr [this->_padding_ + EDX*0x4],EAX
    //                              mst_play.cpp:205 (19)
    //         004616c4     MOV        this,dword ptr [ESP + local_c]
    //         004616c8     MOV        dword ptr FS:[0x0],this
    //         004616cf     POP        EDI
    //         004616d0     POP        ESI
    //         004616d1     ADD        ESP,0xc
    //         004616d4     RET        0x14
    //                               switchD_00461596::caseD_28                                   XREF[2]:     00461596(j), 004617f8(*)  
    //                              mst_play.cpp:192 (67)
    //         004616d7     PUSH       0xfc
    //         004616dc     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004616e1     ADD        ESP,0x4
    //         004616e4     MOV        dword ptr [ESP + param_2],EAX
    //         004616e8     MOV        ESI,dword ptr [ESP + param_5]
    //         004616ec     MOV        dword ptr [ESP + local_4],0x4
    //         004616f4     TEST       EAX,EAX
    //         004616f6     JZ         LAB_004617ca
    //         004616fc     MOV        EDX,dword ptr [ESP + param_4]
    //         00461700     MOV        this,dword ptr [ESP + param_3]
    //         00461704     PUSH       0x1
    //         00461706     PUSH       ESI
    //         00461707     PUSH       EDX
    //         00461708     MOV        EDX,dword ptr [ESP + param_1]
    //         0046170c     PUSH       this
    //         0046170d     PUSH       EDX
    //         0046170e     MOV        this,EAX
    //         00461710     CALL       RGE_Master_Action_Object::RGE_Master_Action_Ob   undefined RGE_Master_Action_Object(RGE_Master
    //         00461715     JMP        LAB_004617cc
    //                               switchD_00461596::caseD_32                                   XREF[2]:     00461596(j), 004617fc(*)  
    //                              mst_play.cpp:195 (67)
    //         0046171a     PUSH       0x148
    //         0046171f     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00461724     ADD        ESP,0x4
    //         00461727     MOV        dword ptr [ESP + param_2],EAX
    //         0046172b     MOV        ESI,dword ptr [ESP + param_5]
    //         0046172f     MOV        dword ptr [ESP + local_4],0x5
    //         00461737     TEST       EAX,EAX
    //         00461739     JZ         LAB_00461770
    //         0046173b     MOV        this,dword ptr [ESP + param_4]
    //         0046173f     MOV        EDX,dword ptr [ESP + param_3]
    //         00461743     PUSH       0x1
    //         00461745     PUSH       ESI
    //         00461746     PUSH       this
    //         00461747     MOV        this,dword ptr [ESP + param_1]
    //         0046174b     PUSH       EDX
    //         0046174c     PUSH       this
    //         0046174d     MOV        this,EAX
    //         0046174f     CALL       RGE_Master_Combat_Object::RGE_Master_Combat_Ob   undefined RGE_Master_Combat_Object(RGE_Master
    //         00461754     MOV        this,dword ptr [EDI + 0x1c]
    //         00461757     MOVSX      EDX,SI
    //         0046175a     MOV        dword ptr [this->_padding_ + EDX*0x4],EAX
    //                              mst_play.cpp:205 (19)
    //         0046175d     MOV        this,dword ptr [ESP + local_c]
    //         00461761     MOV        dword ptr FS:[0x0],this
    //         00461768     POP        EDI
    //         00461769     POP        ESI
    //         0046176a     ADD        ESP,0xc
    //         0046176d     RET        0x14
    //                               LAB_00461770                                                 XREF[3]:     004615ff(j), 0046169c(j), 
    //                                                                                                         00461739(j)  
    //                              mst_play.cpp:195 (11)
    //         00461770     MOV        this,dword ptr [EDI + 0x1c]
    //         00461773     XOR        EAX,EAX
    //         00461775     MOVSX      EDX,SI
    //         00461778     MOV        dword ptr [this->_padding_ + EDX*0x4],EAX
    //                              mst_play.cpp:205 (19)
    //         0046177b     MOV        this,dword ptr [ESP + local_c]
    //         0046177f     MOV        dword ptr FS:[0x0],this
    //         00461786     POP        EDI
    //         00461787     POP        ESI
    //         00461788     ADD        ESP,0xc
    //         0046178b     RET        0x14
    //                               switchD_00461596::caseD_19                                   XREF[2]:     00461596(j), 004617f0(*)  
    //                              mst_play.cpp:198 (71)
    //         0046178e     PUSH       0xbc
    //         00461793     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00461798     ADD        ESP,0x4
    //         0046179b     MOV        dword ptr [ESP + param_2],EAX
    //         0046179f     MOV        ESI,dword ptr [ESP + param_5]
    //         004617a3     MOV        dword ptr [ESP + local_4],0x6
    //         004617ab     TEST       EAX,EAX
    //         004617ad     JZ         LAB_004617ca
    //         004617af     MOV        EDX,dword ptr [ESP + param_4]
    //         004617b3     MOV        this,dword ptr [ESP + param_3]
    //         004617b7     PUSH       0x1
    //         004617b9     PUSH       ESI
    //         004617ba     PUSH       EDX
    //         004617bb     MOV        EDX,dword ptr [ESP + param_1]
    //         004617bf     PUSH       this
    //         004617c0     PUSH       EDX
    //         004617c1     MOV        this,EAX
    //         004617c3     CALL       RGE_Master_Doppleganger_Object::RGE_Master_Dop   undefined RGE_Master_Doppleganger_Object(RGE_
    //         004617c8     JMP        LAB_004617cc
    //                               LAB_004617ca                                                 XREF[4]:     004615bc(j), 00461659(j), 
    //                                                                                                         004616f6(j), 004617ad(j)  
    //         004617ca     XOR        EAX,EAX
    //                               LAB_004617cc                                                 XREF[4]:     004615db(j), 00461678(j), 
    //                                                                                                         00461715(j), 004617c8(j)  
    //         004617cc     MOV        EDX,dword ptr [EDI + 0x1c]
    //         004617cf     MOVSX      this,SI
    //         004617d2     MOV        dword ptr [EDX + this->_padding_*0x4],EAX
    //                               switchD_00461596::caseD_c                                    XREF[3]:     00461588(j), 00461596(j), 
    //                               switchD_00461596::caseD_d                                                 00461804(*)  
    //                               switchD_00461596::caseD_e
    //                               switchD_00461596::caseD_f
    //                               switchD_00461596::caseD_10
    //                               switchD_00461596::caseD_11
    //                               switchD_00461596::caseD_12
    //                               switchD_00461596::caseD_13
    //                               switchD_00461596::caseD_15
    //                               switchD_00461596::caseD_16
    //                               switchD_00461596::caseD_17
    //                               switchD_00461596::caseD_18
    //                               switchD_00461596::caseD_1a
    //                               switchD_00461596::caseD_1b
    //                               switchD_00461596::caseD_1c
    //                               switchD_00461596::caseD_1d
    //                               switchD_00461596::caseD_1f
    //                               switchD_00461596::caseD_20
    //                               switchD_00461596::caseD_21
    //                               switchD_00461596::caseD_22
    //                               switchD_00461596::caseD_23
    //                               switchD_00461596::caseD_24
    //                               switchD_00461596::caseD_25
    //                               switchD_00461596::caseD_26
    //                               switchD_00461596::caseD_27
    //                               switchD_00461596::caseD_29
    //                               switchD_00461596::caseD_2a
    //                               switchD_00461596::caseD_2b
    //                               switchD_00461596::caseD_2c
    //                               switchD_00461596::caseD_2d
    //                               switchD_00461596::caseD_2e
    //                               switchD_00461596::caseD_2f
    //                               switchD_00461596::caseD_30
    //                               switchD_00461596::caseD_31
    //                               switchD_00461596::caseD_33
    //                               switchD_00461596::caseD_34
    //                               switchD_00461596::caseD_35
    //                               switchD_00461596::caseD_36
    //                               switchD_00461596::caseD_37
    //                               switchD_00461596::caseD_38
    //                               switchD_00461596::caseD_39
    //                               switchD_00461596::caseD_3a
    //                               switchD_00461596::caseD_3b
    //                               switchD_00461596::caseD_b
    //                              mst_play.cpp:205 (102)
    //         004617d5     MOV        this,dword ptr [ESP + local_c]
    //         004617d9     POP        EDI
    //         004617da     MOV        dword ptr FS:[0x0],this
    //         004617e1     POP        ESI
    //         004617e2     ADD        ESP,0xc
    //         004617e5     RET        0x14
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00461596::switchdataD_004617e8                       XREF[1]:     load_object:00461596(*)  
}

// Offset: 0x00461840
void TRIBE_Master_Player::save(int param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Master_Player::save(int)                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall save(RGE_Master_Player * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Master_Pla    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00461846(R)  
    //                               ?save@RGE_Master_Player@@UAEXH@Z                             XREF[2]:     00570c1c(*), 00576814(*)  
    //                               RGE_Master_Player::save
    //                              mst_play.cpp:210 (6)
    //         00461840     PUSH       EBX
    //         00461841     PUSH       EBP
    //         00461842     PUSH       ESI
    //         00461843     MOV        ESI,this
    //         00461845     PUSH       EDI
    //                              mst_play.cpp:213 (19)
    //         00461846     MOV        EDI,dword ptr [ESP + param_1]
    //         0046184a     LEA        EAX,[ESI + 0x29]
    //         0046184d     PUSH       0x1
    //         0046184f     PUSH       EAX
    //         00461850     PUSH       EDI
    //         00461851     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00461856     ADD        ESP,0xc
    //                              mst_play.cpp:215 (15)
    //         00461859     LEA        this,[ESI + 0x4]
    //         0046185c     PUSH       0x14
    //         0046185e     PUSH       this
    //         0046185f     PUSH       EDI
    //         00461860     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00461865     ADD        ESP,0xc
    //                              mst_play.cpp:216 (15)
    //         00461868     LEA        EBX,[ESI + 0x20]
    //         0046186b     PUSH       0x2
    //         0046186d     PUSH       EBX
    //         0046186e     PUSH       EDI
    //         0046186f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00461874     ADD        ESP,0xc
    //                              mst_play.cpp:217 (12)
    //         00461877     LEA        EDX,[ESI + 0x2a]
    //         0046187a     PUSH       0x2
    //         0046187c     PUSH       EDX
    //         0046187d     PUSH       EDI
    //         0046187e     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              mst_play.cpp:219 (11)
    //         00461883     MOV        BX,word ptr [EBX]
    //         00461886     ADD        ESP,0xc
    //         00461889     TEST       BX,BX
    //         0046188c     JLE        LAB_004618a2
    //                              mst_play.cpp:220 (20)
    //         0046188e     MOV        this,dword ptr [ESI + 0x24]
    //         00461891     MOVSX      EAX,BX
    //         00461894     SHL        EAX,0x2
    //         00461897     PUSH       EAX
    //         00461898     PUSH       this
    //         00461899     PUSH       EDI
    //         0046189a     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0046189f     ADD        ESP,0xc
    //                               LAB_004618a2                                                 XREF[1]:     0046188c(j)  
    //                              mst_play.cpp:222 (15)
    //         004618a2     LEA        EDX,[ESI + 0x28]
    //         004618a5     PUSH       0x1
    //         004618a7     PUSH       EDX
    //         004618a8     PUSH       EDI
    //         004618a9     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004618ae     ADD        ESP,0xc
    //                              mst_play.cpp:224 (12)
    //         004618b1     LEA        EBP,[ESI + 0x18]
    //         004618b4     PUSH       0x2
    //         004618b6     PUSH       EBP
    //         004618b7     PUSH       EDI
    //         004618b8     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              mst_play.cpp:226 (12)
    //         004618bd     MOV        AX,word ptr [EBP]
    //         004618c1     ADD        ESP,0xc
    //         004618c4     TEST       AX,AX
    //         004618c7     JLE        LAB_004618ff
    //                              mst_play.cpp:228 (17)
    //         004618c9     MOV        this,dword ptr [ESI + 0x1c]
    //         004618cc     MOVSX      EAX,AX
    //         004618cf     SHL        EAX,0x2
    //         004618d2     PUSH       EAX
    //         004618d3     PUSH       this
    //         004618d4     PUSH       EDI
    //         004618d5     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              mst_play.cpp:230 (11)
    //         004618da     XOR        EBX,EBX
    //         004618dc     ADD        ESP,0xc
    //         004618df     CMP        word ptr [EBP],BX
    //         004618e3     JLE        LAB_004618ff
    //                               LAB_004618e5                                                 XREF[1]:     004618fd(j)  
    //                              mst_play.cpp:231 (13)
    //         004618e5     MOV        EAX,dword ptr [ESI + 0x1c]
    //         004618e8     MOVSX      EDX,BX
    //         004618eb     MOV        this,dword ptr [EAX + EDX*0x4]
    //         004618ee     TEST       this,this
    //         004618f0     JZ         LAB_004618f8
    //                              mst_play.cpp:232 (13)
    //         004618f2     MOV        EDX,dword ptr [this->_padding_]
    //         004618f4     PUSH       EDI
    //         004618f5     CALL       dword ptr [EDX + 0x14]
    //                               LAB_004618f8                                                 XREF[1]:     004618f0(j)  
    //         004618f8     INC        EBX
    //         004618f9     CMP        BX,word ptr [EBP]
    //         004618fd     JL         LAB_004618e5
    //                               LAB_004618ff                                                 XREF[2]:     004618c7(j), 004618e3(j)  
    //                              mst_play.cpp:234 (7)
    //         004618ff     POP        EDI
    //         00461900     POP        ESI
    //         00461901     POP        EBP
    //         00461902     POP        EBX
    //         00461903     RET        0x4
}

