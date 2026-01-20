// Auto-generated scaffold unit: visible.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/visible.cpp
#include "../include/common.h"

// Offset: 0x0053C1B0
undefined RGE_Visible_Map(RGE_Visible_Map* this_, RGE_Map* param_2, RGE_Player* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Visible_Map::RGE_Visible_Map(class RGE_Map *,class RGE_Player *)               *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Visible_Map(RGE_Visible_Map * this, RGE_Map
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Visible_Ma    ECX:4 (auto)   this
    //              RGE_Map *         Stack[0x4]:4   param_1                   XREF[1]:     0053c1bf(R)  
    //              RGE_Player *      Stack[0x8]:4   param_2                   XREF[1]:     0053c1b1(R)  
    //                               ??0RGE_Visible_Map@@QAE@PAVRGE_Map@@PAVRGE_Player@@@Z        XREF[3]:     RGE_Player:0046e9a5(c), 
    //                               RGE_Visible_Map::RGE_Visible_Map                                          remake_visible_map:00471c55(c), 
    //                                                                                                         TRIBE_Player:00511fd6(c)  
    //                              visible.cpp:226 (42)
    //         0053c1b0     PUSH       EBX
    //         0053c1b1     MOV        EBX,dword ptr [ESP + param_2]
    //         0053c1b5     PUSH       ESI
    //         0053c1b6     MOV        ESI,this
    //         0053c1b8     MOV        EAX,dword ptr [EBX + 0x3c]
    //         0053c1bb     PUSH       EDI
    //         0053c1bc     MOV        dword ptr [ESI + 0x4],EAX
    //         0053c1bf     MOV        EAX,dword ptr [ESP + param_1]
    //         0053c1c3     MOV        dword ptr [ESI + 0x8],EBX
    //         0053c1c6     MOV        dword ptr [ESI + 0xc],EAX
    //         0053c1c9     MOV        this,dword ptr [EAX + 0x8]
    //         0053c1cc     MOV        dword ptr [ESI + 0x14],this
    //         0053c1cf     MOV        EDX,dword ptr [EAX + 0xc]
    //         0053c1d2     MOV        EAX,EDX
    //         0053c1d4     MOV        dword ptr [ESI + 0x18],EDX
    //         0053c1d7     IMUL       EAX,this
    //                              visible.cpp:228 (18)
    //         0053c1da     TEST       this,this
    //         0053c1dc     MOV        dword ptr [ESI + 0x1c],0x0
    //         0053c1e3     MOV        dword ptr [ESI + 0x20],EAX
    //         0053c1e6     JLE        LAB_0053c248
    //         0053c1e8     TEST       EDX,EDX
    //         0053c1ea     JLE        LAB_0053c248
    //                              visible.cpp:230 (14)
    //         0053c1ec     PUSH       0x1
    //         0053c1ee     PUSH       EAX
    //         0053c1ef     CALL       calloc                                           undefined calloc()
    //         0053c1f4     ADD        ESP,0x8
    //         0053c1f7     MOV        dword ptr [ESI + 0x10],EAX
    //                              visible.cpp:231 (11)
    //         0053c1fa     MOV        EAX,dword ptr [ESI + 0x18]
    //         0053c1fd     PUSH       0x4
    //         0053c1ff     PUSH       EAX
    //         0053c200     CALL       calloc                                           undefined calloc()
    //                              visible.cpp:233 (14)
    //         0053c205     MOV        this,dword ptr [ESI + 0x18]
    //         0053c208     MOV        dword ptr [ESI],EAX
    //         0053c20a     ADD        ESP,0x8
    //         0053c20d     XOR        EAX,EAX
    //         0053c20f     TEST       this,this
    //         0053c211     JLE        LAB_0053c22b
    //                               LAB_0053c213                                                 XREF[1]:     0053c229(j)  
    //                              visible.cpp:234 (24)
    //         0053c213     MOV        this,EAX
    //         0053c215     MOV        EDI,dword ptr [ESI + 0x10]
    //         0053c218     IMUL       this,dword ptr [ESI + 0x14]
    //         0053c21c     MOV        EDX,dword ptr [ESI]
    //         0053c21e     ADD        this,EDI
    //         0053c220     MOV        dword ptr [EDX + EAX*0x4],this
    //         0053c223     MOV        this,dword ptr [ESI + 0x18]
    //         0053c226     INC        EAX
    //         0053c227     CMP        EAX,this
    //         0053c229     JL         LAB_0053c213
    //                               LAB_0053c22b                                                 XREF[1]:     0053c211(j)  
    //                              visible.cpp:236 (27)
    //         0053c22b     MOV        this,dword ptr [ESI + 0x18]
    //         0053c22e     MOV        EDI,dword ptr [ESI + 0x10]
    //         0053c231     IMUL       this,dword ptr [ESI + 0x14]
    //         0053c235     MOV        EDX,this
    //         0053c237     OR         EAX,0xffffffff
    //         0053c23a     SHR        this,0x2
    //         0053c23d     STOSD.REP  ES:EDI
    //         0053c23f     MOV        this,EDX
    //         0053c241     AND        this,0x3
    //         0053c244     STOSB.REP  ES:EDI
    //                              visible.cpp:238 (2)
    //         0053c246     JMP        LAB_0053c255
    //                               LAB_0053c248                                                 XREF[2]:     0053c1e6(j), 0053c1ea(j)  
    //                              visible.cpp:240 (7)
    //         0053c248     MOV        dword ptr [ESI + 0x10],0x0
    //                              visible.cpp:241 (6)
    //         0053c24f     MOV        dword ptr [ESI],0x0
    //                               LAB_0053c255                                                 XREF[1]:     0053c246(j)  
    //                              visible.cpp:244 (10)
    //         0053c255     MOV        this,byte ptr [EBX + 0x4a]
    //         0053c258     MOV        EAX,0x1
    //         0053c25d     SHL        EAX,this
    //                              visible.cpp:252 (7)
    //         0053c25f     MOV        dword ptr [ESI + 0x34],0x0
    //                              visible.cpp:256 (30)
    //         0053c266     POP        EDI
    //         0053c267     MOV        dword ptr [ESI + 0x24],EAX
    //         0053c26a     NOT        EAX
    //         0053c26c     MOV        dword ptr [ESI + 0x28],EAX
    //         0053c26f     MOV        EAX,dword ptr [ESI + 0x24]
    //         0053c272     SHL        EAX,0x10
    //         0053c275     MOV        dword ptr [ESI + 0x2c],EAX
    //         0053c278     NOT        EAX
    //         0053c27a     MOV        dword ptr [ESI + 0x30],EAX
    //         0053c27d     MOV        EAX,ESI
    //         0053c27f     POP        ESI
    //         0053c280     POP        EBX
    //         0053c281     RET        0x8
}

// Offset: 0x0053C290
undefined RGE_Visible_Map(RGE_Visible_Map* this_, int param_2, RGE_Game_World* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Visible_Map::RGE_Visible_Map(int,class RGE_Game_World *)                       *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Visible_Map(RGE_Visible_Map * this, int par
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Visible_Ma    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[2]:     0053c297(R), 0053c367(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[2]:     0053c291(R), 0053c303(R)  
    //              undefined2        Stack[-0x4]:2  local_4                   XREF[3]:     0053c2ef(*), 0053c30a(R), 0053c385(R)  
    //              short             Stack[-0x8]:2  player_id
    //                               ??0RGE_Visible_Map@@QAE@HPAVRGE_Game_World@@@Z               XREF[2]:     load:0046fb25(c), 
    //                               RGE_Visible_Map::RGE_Visible_Map                                          load:00512965(c)  
    //                              visible.cpp:265 (7)
    //         0053c290     PUSH       this
    //         0053c291     MOV        EAX,dword ptr [ESP + param_2]
    //         0053c295     PUSH       EBX
    //         0053c296     PUSH       EBP
    //                              visible.cpp:268 (39)
    //         0053c297     MOV        EBP,dword ptr [ESP + param_1]
    //         0053c29b     PUSH       ESI
    //         0053c29c     MOV        ESI,this
    //         0053c29e     PUSH       EDI
    //         0053c29f     PUSH       0x4
    //         0053c2a1     LEA        EBX,[ESI + 0x14]
    //         0053c2a4     MOV        dword ptr [ESI + 0x4],EAX
    //         0053c2a7     MOV        EAX,dword ptr [EAX + 0x28]
    //         0053c2aa     PUSH       EBX
    //         0053c2ab     PUSH       EBP
    //         0053c2ac     MOV        dword ptr [ESI + 0xc],EAX
    //         0053c2af     MOV        dword ptr [ESI + 0x1c],0x0
    //         0053c2b6     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0053c2bb     ADD        ESP,0xc
    //                              visible.cpp:269 (12)
    //         0053c2be     LEA        EDI,[ESI + 0x18]
    //         0053c2c1     PUSH       0x4
    //         0053c2c3     PUSH       EDI
    //         0053c2c4     PUSH       EBP
    //         0053c2c5     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              visible.cpp:271 (22)
    //         0053c2ca     FLD        float ptr [save_game_version]                    = 7.23
    //         0053c2d0     FCOMP      float ptr [DAT_005776e0]                         = 66h    f
    //         0053c2d6     ADD        ESP,0xc
    //         0053c2d9     FNSTSW     AX
    //         0053c2db     TEST       AH,0x1
    //         0053c2de     JNZ        LAB_0053c2ef
    //                              visible.cpp:273 (15)
    //         0053c2e0     LEA        EAX,[ESI + 0x1c]
    //         0053c2e3     PUSH       0x4
    //         0053c2e5     PUSH       EAX
    //         0053c2e6     PUSH       EBP
    //         0053c2e7     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0053c2ec     ADD        ESP,0xc
    //                               LAB_0053c2ef                                                 XREF[1]:     0053c2de(j)  
    //                              visible.cpp:275 (13)
    //         0053c2ef     LEA        this=>local_4,[ESP + 0x10]
    //         0053c2f3     PUSH       0x2
    //         0053c2f5     PUSH       this
    //         0053c2f6     PUSH       EBP
    //         0053c2f7     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              visible.cpp:277 (7)
    //         0053c2fc     MOV        EBP,dword ptr [EBX]
    //         0053c2fe     MOV        EAX,dword ptr [EDI]
    //         0053c300     IMUL       EAX,EBP
    //                              visible.cpp:279 (18)
    //         0053c303     MOV        this,dword ptr [ESP + param_2]
    //         0053c307     MOV        dword ptr [ESI + 0x20],EAX
    //         0053c30a     MOVSX      EDX,word ptr [ESP + local_4]
    //         0053c30f     MOV        this,dword ptr [this->map_offsets + 0x40]
    //         0053c312     ADD        ESP,0xc
    //                              visible.cpp:281 (15)
    //         0053c315     TEST       EBP,EBP
    //         0053c317     MOV        EDX,dword ptr [this->map_offsets + EDX*0x4]
    //         0053c31a     MOV        dword ptr [ESI + 0x8],EDX
    //         0053c31d     JLE        LAB_0053c378
    //         0053c31f     CMP        dword ptr [EDI],0x0
    //         0053c322     JLE        LAB_0053c378
    //                              visible.cpp:283 (14)
    //         0053c324     PUSH       0x1
    //         0053c326     PUSH       EAX
    //         0053c327     CALL       calloc                                           undefined calloc()
    //         0053c32c     ADD        ESP,0x8
    //         0053c32f     MOV        dword ptr [ESI + 0x10],EAX
    //                              visible.cpp:284 (10)
    //         0053c332     MOV        EAX,dword ptr [EDI]
    //         0053c334     PUSH       0x4
    //         0053c336     PUSH       EAX
    //         0053c337     CALL       calloc                                           undefined calloc()
    //                              visible.cpp:286 (13)
    //         0053c33c     MOV        this,dword ptr [EDI]
    //         0053c33e     MOV        dword ptr [ESI],EAX
    //         0053c340     ADD        ESP,0x8
    //         0053c343     XOR        EAX,EAX
    //         0053c345     TEST       this,this
    //         0053c347     JLE        LAB_0053c35f
    //                               LAB_0053c349                                                 XREF[1]:     0053c35d(j)  
    //                              visible.cpp:287 (22)
    //         0053c349     MOV        this,EAX
    //         0053c34b     MOV        EBP,dword ptr [ESI + 0x10]
    //         0053c34e     IMUL       this,dword ptr [EBX]
    //         0053c351     MOV        EDX,dword ptr [ESI]
    //         0053c353     ADD        this,EBP
    //         0053c355     MOV        dword ptr [EDX + EAX*0x4],this
    //         0053c358     MOV        this,dword ptr [EDI]
    //         0053c35a     INC        EAX
    //         0053c35b     CMP        EAX,this
    //         0053c35d     JL         LAB_0053c349
    //                               LAB_0053c35f                                                 XREF[1]:     0053c347(j)  
    //                              visible.cpp:289 (23)
    //         0053c35f     MOV        EAX,dword ptr [EBX]
    //         0053c361     MOV        this,dword ptr [ESI + 0x10]
    //         0053c364     IMUL       EAX,dword ptr [EDI]
    //         0053c367     MOV        EDX,dword ptr [ESP + param_1]
    //         0053c36b     PUSH       EAX
    //         0053c36c     PUSH       this
    //         0053c36d     PUSH       EDX
    //         0053c36e     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0053c373     ADD        ESP,0xc
    //                              visible.cpp:291 (2)
    //         0053c376     JMP        LAB_0053c385
    //                               LAB_0053c378                                                 XREF[2]:     0053c31d(j), 0053c322(j)  
    //                              visible.cpp:293 (7)
    //         0053c378     MOV        dword ptr [ESI + 0x10],0x0
    //                              visible.cpp:294 (6)
    //         0053c37f     MOV        dword ptr [ESI],0x0
    //                               LAB_0053c385                                                 XREF[1]:     0053c376(j)  
    //                              visible.cpp:297 (11)
    //         0053c385     MOV        this,byte ptr [ESP + local_4]
    //         0053c389     MOV        EAX,0x1
    //         0053c38e     SHL        EAX,this
    //                              visible.cpp:304 (7)
    //         0053c390     MOV        dword ptr [ESI + 0x34],0x0
    //                              visible.cpp:307 (31)
    //         0053c397     POP        EDI
    //         0053c398     MOV        dword ptr [ESI + 0x24],EAX
    //         0053c39b     MOV        this,EAX
    //         0053c39d     SHL        EAX,0x10
    //         0053c3a0     MOV        dword ptr [ESI + 0x2c],EAX
    //         0053c3a3     NOT        EAX
    //         0053c3a5     NOT        this
    //         0053c3a7     MOV        dword ptr [ESI + 0x30],EAX
    //         0053c3aa     MOV        dword ptr [ESI + 0x28],this
    //         0053c3ad     MOV        EAX,ESI
    //         0053c3af     POP        ESI
    //         0053c3b0     POP        EBP
    //         0053c3b1     POP        EBX
    //         0053c3b2     POP        this
    //         0053c3b3     RET        0x8
}

// Offset: 0x0053C3C0
void RGE_Visible_Map(RGE_Visible_Map* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Visible_Map::~RGE_Visible_Map(void)                                            *
    //                              *********************************************************************************************************
    //                              void __thiscall ~RGE_Visible_Map(RGE_Visible_Map * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Visible_Ma    ECX:4 (auto)   this
    //                               ??1RGE_Visible_Map@@QAE@XZ                                   XREF[2]:     ~RGE_Player:0046ebe6(c), 
    //                               RGE_Visible_Map::~RGE_Visible_Map                                         remake_visible_map:00471c23(c)  
    //                              visible.cpp:313 (3)
    //         0053c3c0     PUSH       ESI
    //         0053c3c1     MOV        ESI,this
    //                              visible.cpp:315 (7)
    //         0053c3c3     MOV        EAX,dword ptr [ESI + 0x10]
    //         0053c3c6     TEST       EAX,EAX
    //         0053c3c8     JZ         LAB_0053c3da
    //                              visible.cpp:317 (9)
    //         0053c3ca     PUSH       EAX
    //         0053c3cb     CALL       free                                             undefined free()
    //         0053c3d0     ADD        ESP,0x4
    //                              visible.cpp:318 (7)
    //         0053c3d3     MOV        dword ptr [ESI + 0x10],0x0
    //                               LAB_0053c3da                                                 XREF[1]:     0053c3c8(j)  
    //                              visible.cpp:321 (6)
    //         0053c3da     MOV        EAX,dword ptr [ESI]
    //         0053c3dc     TEST       EAX,EAX
    //         0053c3de     JZ         LAB_0053c3ef
    //                              visible.cpp:323 (9)
    //         0053c3e0     PUSH       EAX
    //         0053c3e1     CALL       free                                             undefined free()
    //         0053c3e6     ADD        ESP,0x4
    //                              visible.cpp:324 (6)
    //         0053c3e9     MOV        dword ptr [ESI],0x0
    //                               LAB_0053c3ef                                                 XREF[1]:     0053c3de(j)  
    //                              visible.cpp:327 (7)
    //         0053c3ef     MOV        dword ptr [ESI + 0x8],0x0
    //                              visible.cpp:328 (7)
    //         0053c3f6     MOV        dword ptr [ESI + 0xc],0x0
    //                              visible.cpp:329 (2)
    //         0053c3fd     POP        ESI
    //         0053c3fe     RET
}

// Offset: 0x0053C400
void save(RGE_Visible_Map* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Visible_Map::save(int)                                                    *
    //                              *********************************************************************************************************
    //                              void __thiscall save(RGE_Visible_Map * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Visible_Ma    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0053c406(R)  
    //                               ?save@RGE_Visible_Map@@QAEXH@Z                               XREF[1]:     save2:0047041b(c)  
    //                               RGE_Visible_Map::save
    //                              visible.cpp:336 (6)
    //         0053c400     PUSH       EBX
    //         0053c401     PUSH       EBP
    //         0053c402     PUSH       ESI
    //         0053c403     MOV        ESI,this
    //         0053c405     PUSH       EDI
    //                              visible.cpp:337 (19)
    //         0053c406     MOV        EDI,dword ptr [ESP + param_1]
    //         0053c40a     LEA        EBX,[ESI + 0x14]
    //         0053c40d     PUSH       0x4
    //         0053c40f     PUSH       EBX
    //         0053c410     PUSH       EDI
    //         0053c411     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0053c416     ADD        ESP,0xc
    //                              visible.cpp:338 (12)
    //         0053c419     LEA        EBP,[ESI + 0x18]
    //         0053c41c     PUSH       0x4
    //         0053c41e     PUSH       EBP
    //         0053c41f     PUSH       EDI
    //         0053c420     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              visible.cpp:340 (22)
    //         0053c425     FLD        float ptr [save_game_version]                    = 7.23
    //         0053c42b     FCOMP      float ptr [DAT_005776e0]                         = 66h    f
    //         0053c431     ADD        ESP,0xc
    //         0053c434     FNSTSW     AX
    //         0053c436     TEST       AH,0x1
    //         0053c439     JNZ        LAB_0053c44a
    //                              visible.cpp:342 (15)
    //         0053c43b     LEA        EAX,[ESI + 0x1c]
    //         0053c43e     PUSH       0x4
    //         0053c440     PUSH       EAX
    //         0053c441     PUSH       EDI
    //         0053c442     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0053c447     ADD        ESP,0xc
    //                               LAB_0053c44a                                                 XREF[1]:     0053c439(j)  
    //                              visible.cpp:345 (15)
    //         0053c44a     MOV        this,dword ptr [ESI + 0x8]
    //         0053c44d     PUSH       0x2
    //         0053c44f     ADD        this,0x4a
    //         0053c452     PUSH       this
    //         0053c453     PUSH       EDI
    //         0053c454     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              visible.cpp:347 (16)
    //         0053c459     MOV        EBX,dword ptr [EBX]
    //         0053c45b     ADD        ESP,0xc
    //         0053c45e     TEST       EBX,EBX
    //         0053c460     JLE        LAB_0053c47a
    //         0053c462     MOV        EAX,dword ptr [EBP]
    //         0053c465     TEST       EAX,EAX
    //         0053c467     JLE        LAB_0053c47a
    //                              visible.cpp:348 (17)
    //         0053c469     IMUL       EAX,EBX
    //         0053c46c     MOV        EDX,dword ptr [ESI + 0x10]
    //         0053c46f     PUSH       EAX
    //         0053c470     PUSH       EDX
    //         0053c471     PUSH       EDI
    //         0053c472     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0053c477     ADD        ESP,0xc
    //                               LAB_0053c47a                                                 XREF[2]:     0053c460(j), 0053c467(j)  
    //                              visible.cpp:350 (7)
    //         0053c47a     POP        EDI
    //         0053c47b     POP        ESI
    //         0053c47c     POP        EBP
    //         0053c47d     POP        EBX
    //         0053c47e     RET        0x4
}

// Offset: 0x0053C490
uchar get_visible(RGE_Visible_Map* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall RGE_Visible_Map::get_visible(int,int)const                           *
    //                              *********************************************************************************************************
    //                              uchar __thiscall get_visible(RGE_Visible_Map * this, int param_1, in
    //              uchar             AL:1           <RETURN>
    //              RGE_Visible_Ma    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0053c49e(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0053c490(R)  
    //                               ?get_visible@RGE_Visible_Map@@QBEEHH@Z                       XREF[20]:    ready_to_attack:00401c23(c), 
    //                               RGE_Visible_Map::get_visible                                              check_placement:00454052(c), 
    //                                                                                                         update:004d8391(c), 
    //                                                                                                         closestUnexploredTile:004d8e99(c), 
    //                                                                                                         placeDock:004d9c03(c), 
    //                                                                                                         objectToAttack:004dca1c(c), 
    //                                                                                                         objectToAttackByGroup:004dd5ec(c), 
    //                                                                                                         objectToAttackByGroup2:004dde76(c)
    //                                                                                                         findObjectMemoryLimits:004dfec4(c)
    //                                                                                                         findStagingPoint:004e1ef8(c), 
    //                                                                                                         artifactToCapture:004e3ac3(c), 
    //                                                                                                         processNotify:00507a8f(c), 
    //                                                                                                         interface_trade_avail:00513559(c), 
    //                                                                                                         pick_multi:00535bfc(c), 
    //                                                                                                         view_function:0053624e(c), 
    //                                                                                                         view_function:00536276(c), 
    //                                                                                                         mouse_left_up_action:0053f008(c), 
    //                                                                                                         mouse_left_up_action:0053f085(c), 
    //                                                                                                         pick1:0053fcf2(c), 
    //                                                                                                         pick1:0053fe3b(c)  
    //                              visible.cpp:361 (4)
    //         0053c490     MOV        EAX,dword ptr [ESP + param_2]
    //                              visible.cpp:367 (29)
    //         0053c494     MOV        this,dword ptr [ECX + this->player]
    //         0053c497     MOV        EDX,dword ptr [EAX*0x4 + unified_map_offsets]    = 00000000
    //         0053c49e     MOV        EAX,dword ptr [ESP + param_1]
    //         0053c4a2     MOV        EAX,dword ptr [EDX + EAX*0x4]
    //         0053c4a5     MOV        EDX,dword ptr [this->map_offsets + 0xd4]
    //         0053c4ab     TEST       EAX,EDX
    //         0053c4ad     JZ         LAB_0053c4b4
    //         0053c4af     MOV        AL,0xf
    //                              visible.cpp:382 (3)
    //         0053c4b1     RET        0x8
    //                               LAB_0053c4b4                                                 XREF[1]:     0053c4ad(j)  
    //                              visible.cpp:368 (20)
    //         0053c4b4     MOV        this,dword ptr [this->map_offsets + 0xd0]
    //         0053c4ba     AND        this,EAX
    //         0053c4bc     NEG        this
    //         0053c4be     SBB        this,this
    //         0053c4c0     AND        this,0x80
    //         0053c4c6     MOV        AL,this
    //                              visible.cpp:382 (3)
    //         0053c4c8     RET        0x8
}

// Offset: 0x0053C4D0
void set_all(RGE_Visible_Map* this_, uchar param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Visible_Map::set_all(unsigned char)                                       *
    //                              *********************************************************************************************************
    //                              void __thiscall set_all(RGE_Visible_Map * this, uchar param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Visible_Ma    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     0053c4d1(R)  
    //                               ?set_all@RGE_Visible_Map@@QAEXE@Z                            XREF[1]:     set_map_visible:00471bf5(c)  
    //                               RGE_Visible_Map::set_all
    //                              visible.cpp:389 (1)
    //         0053c4d0     PUSH       EBX
    //                              visible.cpp:396 (49)
    //         0053c4d1     MOV        EBX,dword ptr [ESP + param_1]
    //         0053c4d5     PUSH       EBP
    //         0053c4d6     PUSH       ESI
    //         0053c4d7     PUSH       EDI
    //         0053c4d8     MOV        ESI,this
    //         0053c4da     PUSH       0x0
    //         0053c4dc     MOV        EAX,EBX
    //         0053c4de     MOV        this,dword ptr [ESI + 0x8]
    //         0053c4e1     PUSH       0x0
    //         0053c4e3     PUSH       0x0
    //         0053c4e5     AND        EAX,0xff
    //         0053c4ea     MOVSX      EDX,word ptr [this->map_offsets + 0x4a]
    //         0053c4ee     PUSH       0x0
    //         0053c4f0     PUSH       EAX
    //         0053c4f1     MOV        EAX,dword ptr [ESI + 0x4]
    //         0053c4f4     PUSH       0x0
    //         0053c4f6     PUSH       0x5
    //         0053c4f8     PUSH       EDX
    //         0053c4f9     MOV        this,dword ptr [EAX + 0x4]
    //         0053c4fc     PUSH       this
    //         0053c4fd     CALL       log_map_call                                     void log_map_call(int param_1, int param_2, i
    //                              visible.cpp:401 (12)
    //         0053c502     MOV        EAX,dword ptr [ESI + 0x18]
    //         0053c505     ADD        ESP,0x24
    //         0053c508     XOR        this,this
    //         0053c50a     TEST       EAX,EAX
    //         0053c50c     JLE        LAB_0053c530
    //                               LAB_0053c50e                                                 XREF[1]:     0053c52e(j)  
    //                              visible.cpp:402 (9)
    //         0053c50e     MOV        EDX,dword ptr [ESI + 0x14]
    //         0053c511     XOR        EAX,EAX
    //         0053c513     TEST       EDX,EDX
    //         0053c515     JLE        LAB_0053c528
    //                               LAB_0053c517                                                 XREF[1]:     0053c526(j)  
    //                              visible.cpp:403 (17)
    //         0053c517     MOV        EDX,dword ptr [ESI]
    //         0053c519     INC        EAX
    //         0053c51a     MOV        EDX,dword ptr [EDX + this->map_offsets*0x4]
    //         0053c51d     MOV        byte ptr [EDX + EAX*0x1 + -0x1],BL
    //         0053c521     MOV        EDX,dword ptr [ESI + 0x14]
    //         0053c524     CMP        EAX,EDX
    //         0053c526     JL         LAB_0053c517
    //                               LAB_0053c528                                                 XREF[1]:     0053c515(j)  
    //                              visible.cpp:401 (8)
    //         0053c528     MOV        EAX,dword ptr [ESI + 0x18]
    //         0053c52b     INC        this
    //         0053c52c     CMP        this,EAX
    //         0053c52e     JL         LAB_0053c50e
    //                               LAB_0053c530                                                 XREF[1]:     0053c50c(j)  
    //                              visible.cpp:407 (9)
    //         0053c530     CMP        BL,0xff
    //         0053c533     JZ         LAB_0053c573
    //         0053c535     TEST       BL,BL
    //         0053c537     JZ         LAB_0053c573
    //                              visible.cpp:422 (6)
    //         0053c539     MOV        EDI,dword ptr [ESI + 0x2c]
    //         0053c53c     MOV        this,dword ptr [ESI + 0x24]
    //                              visible.cpp:424 (11)
    //         0053c53f     MOV        EAX,dword ptr [ESI + 0x18]
    //         0053c542     OR         EDI,this
    //         0053c544     XOR        EBP,EBP
    //         0053c546     TEST       EAX,EAX
    //         0053c548     JLE        LAB_0053c5ae
    //                              visible.cpp:436 (5)
    //         0053c54a     MOV        EDX,unified_map_offsets                          = 00000000
    //                               LAB_0053c54f                                                 XREF[1]:     0053c56f(j)  
    //                              visible.cpp:425 (11)
    //         0053c54f     MOV        this,dword ptr [ESI + 0x14]
    //         0053c552     XOR        EAX,EAX
    //         0053c554     TEST       this,this
    //         0053c556     JLE        LAB_0053c566
    //                               LAB_0053c558                                                 XREF[1]:     0053c564(j)  
    //         0053c558     MOV        this,dword ptr [EDX]=>unified_map_offsets        = 00000000
    //                              visible.cpp:426 (12)
    //         0053c55a     OR         dword ptr [this->map_offsets + EAX*0x4],EDI
    //         0053c55d     LEA        this,[this->map_offsets + EAX*0x4]
    //         0053c560     INC        EAX
    //         0053c561     CMP        EAX,dword ptr [ESI + 0x14]
    //         0053c564     JL         LAB_0053c558
    //                               LAB_0053c566                                                 XREF[1]:     0053c556(j)  
    //                              visible.cpp:424 (13)
    //         0053c566     MOV        EAX,dword ptr [ESI + 0x18]
    //         0053c569     INC        EBP
    //         0053c56a     ADD        EDX,0x4
    //         0053c56d     CMP        EBP,EAX
    //         0053c56f     JL         LAB_0053c54f
    //         0053c571     JMP        LAB_0053c5ae
    //                               LAB_0053c573                                                 XREF[2]:     0053c533(j), 0053c537(j)  
    //                              visible.cpp:411 (3)
    //         0053c573     MOV        EDI,dword ptr [ESI + 0x28]
    //                              visible.cpp:412 (8)
    //         0053c576     CMP        BL,0xff
    //         0053c579     JNZ        LAB_0053c57e
    //         0053c57b     AND        EDI,dword ptr [ESI + 0x30]
    //                               LAB_0053c57e                                                 XREF[1]:     0053c579(j)  
    //                              visible.cpp:414 (14)
    //         0053c57e     MOV        EAX,dword ptr [ESI + 0x18]
    //         0053c581     XOR        EBP,EBP
    //         0053c583     TEST       EAX,EAX
    //         0053c585     JLE        LAB_0053c5ae
    //         0053c587     MOV        EDX,unified_map_offsets                          = 00000000
    //                               LAB_0053c58c                                                 XREF[1]:     0053c5ac(j)  
    //                              visible.cpp:415 (11)
    //         0053c58c     MOV        this,dword ptr [ESI + 0x14]
    //         0053c58f     XOR        EAX,EAX
    //         0053c591     TEST       this,this
    //         0053c593     JLE        LAB_0053c5a3
    //                               LAB_0053c595                                                 XREF[1]:     0053c5a1(j)  
    //         0053c595     MOV        this,dword ptr [EDX]=>unified_map_offsets        = 00000000
    //                              visible.cpp:416 (12)
    //         0053c597     AND        dword ptr [this->map_offsets + EAX*0x4],EDI
    //         0053c59a     LEA        this,[this->map_offsets + EAX*0x4]
    //         0053c59d     INC        EAX
    //         0053c59e     CMP        EAX,dword ptr [ESI + 0x14]
    //         0053c5a1     JL         LAB_0053c595
    //                               LAB_0053c5a3                                                 XREF[1]:     0053c593(j)  
    //                              visible.cpp:414 (11)
    //         0053c5a3     MOV        EAX,dword ptr [ESI + 0x18]
    //         0053c5a6     INC        EBP
    //         0053c5a7     ADD        EDX,0x4
    //         0053c5aa     CMP        EBP,EAX
    //         0053c5ac     JL         LAB_0053c58c
    //                               LAB_0053c5ae                                                 XREF[3]:     0053c548(j), 0053c571(j), 
    //                                                                                                         0053c585(j)  
    //                              visible.cpp:431 (5)
    //         0053c5ae     CMP        BL,0xff
    //         0053c5b1     JNZ        LAB_0053c5c1
    //                              visible.cpp:432 (7)
    //         0053c5b3     MOV        dword ptr [ESI + 0x1c],0x0
    //                              visible.cpp:436 (7)
    //         0053c5ba     POP        EDI
    //         0053c5bb     POP        ESI
    //         0053c5bc     POP        EBP
    //         0053c5bd     POP        EBX
    //         0053c5be     RET        0x4
    //                               LAB_0053c5c1                                                 XREF[1]:     0053c5b1(j)  
    //                              visible.cpp:434 (3)
    //         0053c5c1     MOV        EDX,dword ptr [ESI + 0x20]
    //                              visible.cpp:436 (10)
    //         0053c5c4     POP        EDI
    //         0053c5c5     MOV        dword ptr [ESI + 0x1c],EDX
    //         0053c5c8     POP        ESI
    //         0053c5c9     POP        EBP
    //         0053c5ca     POP        EBX
    //         0053c5cb     RET        0x4
}

// Offset: 0x0053C5D0
void explore_all(RGE_Visible_Map* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Visible_Map::explore_all(void)                                            *
    //                              *********************************************************************************************************
    //                              void __thiscall explore_all(RGE_Visible_Map * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Visible_Ma    ECX:4 (auto)   this
    //                               ?explore_all@RGE_Visible_Map@@QAEXXZ                         XREF[1]:     create_game:0052778e(c)  
    //                               RGE_Visible_Map::explore_all
    //                              visible.cpp:442 (4)
    //         0053c5d0     PUSH       EBP
    //         0053c5d1     PUSH       ESI
    //         0053c5d2     MOV        ESI,this
    //                              visible.cpp:447 (34)
    //         0053c5d4     PUSH       0x0
    //         0053c5d6     PUSH       0x0
    //         0053c5d8     PUSH       0x0
    //         0053c5da     MOV        EAX,dword ptr [ESI + 0x8]
    //         0053c5dd     MOV        EDX,dword ptr [ESI + 0x4]
    //         0053c5e0     PUSH       0x0
    //         0053c5e2     PUSH       0x0
    //         0053c5e4     MOVSX      this,word ptr [EAX + 0x4a]
    //         0053c5e8     MOV        EAX,dword ptr [EDX + 0x4]
    //         0053c5eb     PUSH       0x0
    //         0053c5ed     PUSH       0x6
    //         0053c5ef     PUSH       this
    //         0053c5f0     PUSH       EAX
    //         0053c5f1     CALL       log_map_call                                     void log_map_call(int param_1, int param_2, i
    //                              visible.cpp:450 (16)
    //         0053c5f6     MOV        EAX,dword ptr [ESI + 0x18]
    //         0053c5f9     ADD        ESP,0x24
    //         0053c5fc     XOR        EBP,EBP
    //         0053c5fe     TEST       EAX,EAX
    //         0053c600     JLE        LAB_0053c65f
    //         0053c602     PUSH       EDI
    //         0053c603     PUSH       EBX
    //         0053c604     XOR        EBX,EBX
    //                               LAB_0053c606                                                 XREF[1]:     0053c65b(j)  
    //                              visible.cpp:452 (9)
    //         0053c606     MOV        EAX,dword ptr [ESI + 0x14]
    //         0053c609     XOR        EDI,EDI
    //         0053c60b     TEST       EAX,EAX
    //         0053c60d     JLE        LAB_0053c652
    //                               LAB_0053c60f                                                 XREF[1]:     0053c650(j)  
    //                              visible.cpp:454 (14)
    //         0053c60f     MOV        this,dword ptr [ESI]
    //         0053c611     MOV        EDX,dword ptr [this->map_offsets + EBX*0x1]
    //         0053c614     LEA        EAX,[this->map_offsets + EBX*0x1]
    //         0053c617     CMP        byte ptr [EDI + EDX*0x1],0xff
    //         0053c61b     JNZ        LAB_0053c64a
    //                              visible.cpp:456 (2)
    //         0053c61d     MOV        EAX,EDX
    //                              visible.cpp:460 (51)
    //         0053c61f     PUSH       EBP
    //         0053c620     PUSH       EDI
    //         0053c621     MOV        byte ptr [EDI + EAX*0x1],0x0
    //         0053c625     MOV        EDX,dword ptr [ESI + 0x1c]
    //         0053c628     INC        EDX
    //         0053c629     MOV        dword ptr [ESI + 0x1c],EDX
    //         0053c62c     MOV        this,dword ptr [EBX + unified_map_offsets]       = 00000000
    //         0053c632     MOV        EDX,dword ptr [ESI + 0x2c]
    //         0053c635     LEA        EAX,[this->map_offsets + EDI*0x4]
    //         0053c638     MOV        this,dword ptr [this->map_offsets + EDI*0x4]
    //         0053c63b     OR         this,EDX
    //         0053c63d     MOV        dword ptr [EAX],this
    //         0053c63f     MOV        this,dword ptr [ESI + 0x8]
    //         0053c642     ADD        this,0x58
    //         0053c645     CALL       RGE_Tile_List::add_node                          void add_node(RGE_Tile_List * this, int param
    //                               LAB_0053c64a                                                 XREF[1]:     0053c61b(j)  
    //         0053c64a     MOV        EAX,dword ptr [ESI + 0x14]
    //         0053c64d     INC        EDI
    //         0053c64e     CMP        EDI,EAX
    //         0053c650     JL         LAB_0053c60f
    //                               LAB_0053c652                                                 XREF[1]:     0053c60d(j)  
    //                              visible.cpp:450 (13)
    //         0053c652     MOV        EAX,dword ptr [ESI + 0x18]
    //         0053c655     INC        EBP
    //         0053c656     ADD        EBX,0x4
    //         0053c659     CMP        EBP,EAX
    //         0053c65b     JL         LAB_0053c606
    //         0053c65d     POP        EBX
    //         0053c65e     POP        EDI
    //                               LAB_0053c65f                                                 XREF[1]:     0053c600(j)  
    //                              visible.cpp:465 (3)
    //         0053c65f     MOV        EAX,dword ptr [ESI + 0x8]
    //                              visible.cpp:467 (10)
    //         0053c662     POP        ESI
    //         0053c663     POP        EBP
    //         0053c664     MOV        dword ptr [EAX + 0x64],0x1
    //         0053c66b     RET
}

// Offset: 0x0053C670
float percentExplored(RGE_Visible_Map* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: float __thiscall RGE_Visible_Map::percentExplored(void)const                                  *
    //                              *********************************************************************************************************
    //                              float __thiscall percentExplored(RGE_Visible_Map * this)
    //              float             ST0:10         <RETURN>
    //              RGE_Visible_Ma    ECX:4 (auto)   this
    //                               ?percentExplored@RGE_Visible_Map@@QBEMXZ                     XREF[6]:     evaluateCivilianDistribution:004f1
    //                               RGE_Visible_Map::percentExplored                                          initialExplorationSatisfied:00501d
    //                                                                                                         update:0051245c(c), 
    //                                                                                                         get_achievement:005193dc(c), 
    //                                                                                                         handle_explore:00532826(c), 
    //                                                                                                         handle_explore:0053285e(c)  
    //                              visible.cpp:474 (6)
    //         0053c670     FILD       dword ptr [ECX + this->numberTilesExploredValue]
    //         0053c673     FIDIV      dword ptr [ECX + this->numberTotalTilesValue]
    //                              visible.cpp:476 (1)
    //         0053c676     RET
}

// Offset: 0x0053C680
void recomputeExplored(RGE_Visible_Map* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Visible_Map::recomputeExplored(void)                                      *
    //                              *********************************************************************************************************
    //                              void __thiscall recomputeExplored(RGE_Visible_Map * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Visible_Ma    ECX:4 (auto)   this
    //                               ?recomputeExplored@RGE_Visible_Map@@QAEXXZ
    //                               RGE_Visible_Map::recomputeExplored
    //                              visible.cpp:483 (1)
    //         0053c680     PUSH       EBX
    //                              visible.cpp:488 (14)
    //         0053c681     MOV        EBX,dword ptr [ECX + this->heightValue]
    //         0053c684     PUSH       EDI
    //         0053c685     XOR        EDI,EDI
    //         0053c687     CMP        EBX,EDI
    //         0053c689     MOV        dword ptr [ECX + this->numberTilesExploredValu
    //         0053c68c     JLE        LAB_0053c6b5
    //         0053c68e     PUSH       ESI
    //                              visible.cpp:490 (15)
    //         0053c68f     MOV        ESI,dword ptr [ECX + this->widthValue]
    //         0053c692     PUSH       EBP
    //                               LAB_0053c693                                                 XREF[1]:     0053c6b1(j)  
    //         0053c693     XOR        EAX,EAX
    //         0053c695     TEST       ESI,ESI
    //         0053c697     JLE        LAB_0053c6ae
    //         0053c699     MOV        EDX,dword ptr [this->map_offsets]
    //         0053c69b     LEA        EDX,[EDX + EDI*0x4]
    //                               LAB_0053c69e                                                 XREF[1]:     0053c6ac(j)  
    //                              visible.cpp:492 (8)
    //         0053c69e     MOV        EBP,dword ptr [EDX]
    //         0053c6a0     CMP        byte ptr [EAX + EBP*0x1],0xff
    //         0053c6a4     JZ         LAB_0053c6a9
    //                              visible.cpp:493 (8)
    //         0053c6a6     INC        dword ptr [ECX + this->numberTilesExploredValue]
    //                               LAB_0053c6a9                                                 XREF[1]:     0053c6a4(j)  
    //         0053c6a9     INC        EAX
    //         0053c6aa     CMP        EAX,ESI
    //         0053c6ac     JL         LAB_0053c69e
    //                               LAB_0053c6ae                                                 XREF[1]:     0053c697(j)  
    //                              visible.cpp:488 (7)
    //         0053c6ae     INC        EDI
    //         0053c6af     CMP        EDI,EBX
    //         0053c6b1     JL         LAB_0053c693
    //         0053c6b3     POP        EBP
    //         0053c6b4     POP        ESI
    //                               LAB_0053c6b5                                                 XREF[1]:     0053c68c(j)  
    //                              visible.cpp:497 (3)
    //         0053c6b5     POP        EDI
    //         0053c6b6     POP        EBX
    //         0053c6b7     RET
}

// Offset: 0x0053C6C0
LOSTBL* get_los_table(RGE_Visible_Map* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: struct LOSTBL * __thiscall RGE_Visible_Map::get_los_table(int,int)                            *
    //                              *********************************************************************************************************
    //                              LOSTBL * __thiscall get_los_table(RGE_Visible_Map * this, int param_
    //              LOSTBL *          EAX:4          <RETURN>
    //              RGE_Visible_Ma    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0053c6c0(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0053c6d4(R)  
    //                               ?get_los_table@RGE_Visible_Map@@QAEPAULOSTBL@@HH@Z           XREF[1]:     get_los_table:004c599d(c)  
    //                               RGE_Visible_Map::get_los_table
    //                              visible.cpp:504 (14)
    //         0053c6c0     MOV        EAX,dword ptr [ESP + param_1]
    //         0053c6c4     CMP        EAX,0x10
    //         0053c6c7     JLE        LAB_0053c6ce
    //         0053c6c9     MOV        EAX,0x10
    //                               LAB_0053c6ce                                                 XREF[1]:     0053c6c7(j)  
    //                              visible.cpp:507 (6)
    //         0053c6ce     TEST       EAX,EAX
    //         0053c6d0     JGE        LAB_0053c6d4
    //         0053c6d2     XOR        EAX,EAX
    //                               LAB_0053c6d4                                                 XREF[1]:     0053c6d0(j)  
    //                              visible.cpp:509 (8)
    //         0053c6d4     MOV        this,dword ptr [ESP + param_2]
    //         0053c6d8     TEST       this,this
    //         0053c6da     JZ         LAB_0053c6e6
    //                              visible.cpp:510 (7)
    //         0053c6dc     MOV        EAX=>Edge_Offsets_T16,dword ptr [EAX*0x4 + 0x5   = 00000000
    //                                                                                  = fffffff0
    //                                                                                  = 0058dc38
    //                                                                                  = 0058e880
    //                              visible.cpp:514 (3)
    //         0053c6e3     RET        0x8
    //                               LAB_0053c6e6                                                 XREF[1]:     0053c6da(j)  
    //                              visible.cpp:512 (7)
    //         0053c6e6     MOV        EAX=>Edge_Offsets_N16,dword ptr [EAX*0x4 + 0x5   = fffffff0
    //                                                                                  = 0058daa0
    //                              visible.cpp:514 (3)
    //         0053c6ed     RET        0x8
}

// Offset: 0x0053C6F0
int explore_terrain(RGE_Visible_Map* this_, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall RGE_Visible_Map::explore_terrain(int,int,int,int,int,int)                      *
    //                              *********************************************************************************************************
    //                              int __thiscall explore_terrain(RGE_Visible_Map * this, int param_1, 
    //              int               EAX:4          <RETURN>
    //              RGE_Visible_Ma    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[3]:     0053c6ff(R), 0053c76f(R), 0053c8ec(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[3]:     0053c6fb(R), 0053c775(R), 0053c7fd(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[7]:     0053c703(R), 0053c77b(R), 0053c7bc(W), 0053c868(W), 
    //                                                                                     0053c8c0(R), 0053c8d2(R), 0053c8e7(W)  
    //              int               Stack[0x10]:4  param_4                   XREF[7]:     0053c709(R), 0053c77e(R), 0053c7d3(R), 0053c84e(W), 
    //                                                                                     0053c865(R), 0053c8ab(R), 0053c8e4(W)  
    //              int               Stack[0x14]:4  param_5                   XREF[2]:     0053c849(R), 0053c8b9(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[9]:     0053c70d(R), 0053c751(W), 0053c75b(R), 0053c781(W), 
    //                                                                                     0053c784(R), 0053c7df(W), 0053c7eb(W), 0053c8ef(R), 
    //                                                                                     0053c8fd(W)  
    //              int               Stack[-0x8]:4  VisibleToCurPlayer        XREF[4]:     0053c7af(W), 0053c7b6(W), 0053c7b9(R), 0053c894(R)  
    //              int               Stack[-0xc]:4  x2                        XREF[4]:     0053c829(W), 0053c82f(W), 0053c86b(R), 0053c8d7(R)  
    //              int               Stack[-0x10]:4 Revealed                  XREF[4]:     0053c725(W), 0053c876(R), 0053c87e(W), 0053c906(R)  
    //              int               Stack[-0x14]:4 y                         XREF[3]:     0053c804(W), 0053c881(R), 0053c89b(R)  
    //              RGE_Player *      Stack[-0x18]:4 curVisPlayer              XREF[5]:     0053c758(W), 0053c769(R), 0053c7c1(W), 0053c7c6(W), 
    //                                                                                     0053c89e(R)  
    //                               ?explore_terrain@RGE_Visible_Map@@QAEHHHHHHH@Z               XREF[1]:     explore_terrain:004c5a16(c)  
    //                               RGE_Visible_Map::explore_terrain
    //                              visible.cpp:521 (6)
    //         0053c6f0     PUSH       EBP
    //         0053c6f1     MOV        EBP,ESP
    //         0053c6f3     SUB        ESP,0x14
    //                              visible.cpp:528 (60)
    //         0053c6f6     MOV        EAX,[Map_Update_Suppresion]
    //         0053c6fb     MOV        EDX,dword ptr [EBP + param_2]
    //         0053c6fe     PUSH       EBX
    //         0053c6ff     MOV        EBX,dword ptr [EBP + param_1]
    //         0053c702     PUSH       ESI
    //         0053c703     MOV        ESI,dword ptr [EBP + param_3]
    //         0053c706     PUSH       EDI
    //         0053c707     MOV        EDI,this
    //         0053c709     MOV        this,dword ptr [EBP + param_4]
    //         0053c70c     PUSH       EAX
    //         0053c70d     MOV        EAX,dword ptr [EBP + param_6]
    //         0053c710     PUSH       this
    //         0053c711     MOV        this,dword ptr [EDI + 0x8]
    //         0053c714     PUSH       ESI
    //         0053c715     PUSH       EDX
    //         0053c716     PUSH       EBX
    //         0053c717     MOVSX      EDX,word ptr [this->map_offsets + 0x4a]
    //         0053c71b     PUSH       EAX
    //         0053c71c     MOV        EAX,dword ptr [EDI + 0x4]
    //         0053c71f     PUSH       0x1
    //         0053c721     PUSH       EDX
    //         0053c722     MOV        this,dword ptr [EAX + 0x4]
    //         0053c725     MOV        dword ptr [EBP + Revealed],0x0
    //         0053c72c     PUSH       this
    //         0053c72d     CALL       log_map_call                                     void log_map_call(int param_1, int param_2, i
    //                              visible.cpp:531 (16)
    //         0053c732     MOV        EAX,[Map_Update_Suppresion]
    //         0053c737     XOR        this,this
    //         0053c739     ADD        ESP,0x24
    //         0053c73c     CMP        EAX,this
    //         0053c73e     JZ         LAB_0053c74b
    //         0053c740     XOR        EAX,EAX
    //                              visible.cpp:658 (9)
    //         0053c742     POP        EDI
    //         0053c743     POP        ESI
    //         0053c744     POP        EBX
    //         0053c745     MOV        ESP,EBP
    //         0053c747     POP        EBP
    //         0053c748     RET        0x18
    //                               LAB_0053c74b                                                 XREF[1]:     0053c73e(j)  
    //                              visible.cpp:535 (3)
    //         0053c74b     MOV        EDX,dword ptr [EDI + 0x34]
    //                              visible.cpp:537 (13)
    //         0053c74e     MOV        EAX,dword ptr [EDI + 0x8]
    //         0053c751     MOV        dword ptr [EBP + param_6],EDX
    //         0053c754     MOVSX      EDX,word ptr [EAX + 0x4a]
    //         0053c758     MOV        dword ptr [EBP + curVisPlayer],EDX
    //                              visible.cpp:541 (3)
    //         0053c75b     MOV        EAX,dword ptr [EBP + param_6]
    //                              visible.cpp:542 (3)
    //         0053c75e     ROL        EAX,0x3
    //                              visible.cpp:543 (5)
    //         0053c761     XOR        EAX,0x1010101
    //                              visible.cpp:544 (3)
    //         0053c766     ROL        EAX,0x2
    //                              visible.cpp:545 (3)
    //         0053c769     XOR        EAX,dword ptr [EBP + curVisPlayer]
    //                              visible.cpp:546 (3)
    //         0053c76c     ROL        EAX,0x3
    //                              visible.cpp:547 (3)
    //         0053c76f     XOR        EAX,dword ptr [EBP + param_1]
    //                              visible.cpp:548 (3)
    //         0053c772     ROL        EAX,0x4
    //                              visible.cpp:549 (3)
    //         0053c775     XOR        EAX,dword ptr [EBP + param_2]
    //                              visible.cpp:550 (3)
    //         0053c778     ROL        EAX,0x3
    //                              visible.cpp:551 (3)
    //         0053c77b     XOR        EAX,dword ptr [EBP + param_3]
    //                              visible.cpp:552 (3)
    //         0053c77e     ADD        EAX,dword ptr [EBP + param_4]
    //                              visible.cpp:553 (3)
    //         0053c781     MOV        dword ptr [EBP + param_6],EAX
    //                              visible.cpp:556 (6)
    //         0053c784     MOV        EAX,dword ptr [EBP + param_6]
    //         0053c787     MOV        dword ptr [EDI + 0x34],EAX
    //                              visible.cpp:569 (17)
    //         0053c78a     MOV        EAX,dword ptr [EDI + 0x4]
    //         0053c78d     MOVSX      EDX,word ptr [EAX + 0x7c]
    //         0053c791     MOV        EAX,dword ptr [EAX + 0x40]
    //         0053c794     MOV        EAX,dword ptr [EAX + EDX*0x4]
    //         0053c797     CMP        EAX,this
    //         0053c799     JZ         LAB_0053c7b6
    //                              visible.cpp:570 (23)
    //         0053c79b     MOV        this,dword ptr [EDI + 0x8]
    //         0053c79e     MOVSX      EDX,word ptr [this->map_offsets + 0x4a]
    //         0053c7a2     XOR        this,this
    //         0053c7a4     CMP        dword ptr [EAX + EDX*0x4 + 0xac],0x1
    //         0053c7ac     SETZ       this
    //         0053c7af     MOV        dword ptr [EBP + VisibleToCurPlayer],this
    //                              visible.cpp:571 (4)
    //         0053c7b2     XOR        this,this
    //         0053c7b4     JMP        LAB_0053c7b9
    //                               LAB_0053c7b6                                                 XREF[1]:     0053c799(j)  
    //                              visible.cpp:572 (3)
    //         0053c7b6     MOV        dword ptr [EBP + VisibleToCurPlayer],this
    //                               LAB_0053c7b9                                                 XREF[1]:     0053c7b4(j)  
    //                              visible.cpp:587 (13)
    //         0053c7b9     MOV        EDX,dword ptr [EBP + VisibleToCurPlayer]
    //         0053c7bc     MOV        dword ptr [EBP + param_3],this
    //         0053c7bf     CMP        EDX,this
    //         0053c7c1     MOV        dword ptr [EBP + curVisPlayer],this
    //         0053c7c4     JZ         LAB_0053c7c9
    //                              visible.cpp:589 (3)
    //         0053c7c6     MOV        dword ptr [EBP + curVisPlayer],EAX
    //                               LAB_0053c7c9                                                 XREF[1]:     0053c7c4(j)  
    //                              visible.cpp:594 (10)
    //         0053c7c9     CMP        ESI,0x10
    //         0053c7cc     JLE        LAB_0053c7d3
    //         0053c7ce     MOV        ESI,0x10
    //                               LAB_0053c7d3                                                 XREF[1]:     0053c7cc(j)  
    //                              visible.cpp:596 (5)
    //         0053c7d3     CMP        dword ptr [EBP + param_4],this
    //         0053c7d6     JZ         LAB_0053c7e4
    //                              visible.cpp:597 (10)
    //         0053c7d8     MOV        this,dword ptr [ESI*0x4 + 0x58ea58]=>->Edge_Of   = 0058dc38
    //                                                                                  = 0058e880
    //         0053c7df     MOV        dword ptr [EBP + param_6],this=>Edge_Offsets_T16 = fffffff0
    //                              visible.cpp:598 (2)
    //         0053c7e2     JMP        LAB_0053c7f0
    //                               LAB_0053c7e4                                                 XREF[1]:     0053c7d6(j)  
    //                              visible.cpp:599 (12)
    //         0053c7e4     MOV        EDX,dword ptr [ESI*0x4 + 0x58ea10]=>->Edge_Off   = 0058daa0
    //         0053c7eb     MOV        dword ptr [EBP + param_6],EDX=>Edge_Offsets_N16  = fffffff0
    //         0053c7ee     MOV        this,EDX
    //                               LAB_0053c7f0                                                 XREF[1]:     0053c7e2(j)  
    //                              visible.cpp:603 (13)
    //         0053c7f0     MOV        EAX,dword ptr [this->map_offsets]=>Edge_Offset   = fffffff0
    //         0053c7f2     CMP        EAX,0x3e7
    //         0053c7f7     JZ         LAB_0053c906
    //                               LAB_0053c7fd                                                 XREF[1]:     0053c900(j)  
    //                              visible.cpp:605 (5)
    //         0053c7fd     MOV        EDX,dword ptr [EBP + param_2]
    //         0053c800     ADD        EDX,EAX
    //                              visible.cpp:609 (20)
    //         0053c802     TEST       EDX,EDX
    //         0053c804     MOV        dword ptr [EBP + y],EDX
    //         0053c807     JL         LAB_0053c8f2
    //         0053c80d     CMP        EDX,dword ptr [EDI + 0x18]
    //         0053c810     JGE        LAB_0053c8f2
    //                              visible.cpp:611 (9)
    //         0053c816     MOV        ESI,dword ptr [ECX + this->world]=>DAT_0058e884  = FFFFFFFDh
    //                                                                                  = FFFFFFFCh
    //                                                                                  = FFFFFFF9h
    //         0053c819     ADD        ESI,EBX
    //         0053c81b     JNS        LAB_0053c81f
    //         0053c81d     XOR        ESI,ESI
    //                               LAB_0053c81f                                                 XREF[1]:     0053c81b(j)  
    //                              visible.cpp:612 (19)
    //         0053c81f     MOV        EAX,dword ptr [ECX + this->player]=>DAT_0058e888 = 00000003h
    //                                                                                  = 00000006h
    //         0053c822     MOV        this,dword ptr [EDI + 0x14]
    //         0053c825     ADD        EAX,EBX
    //         0053c827     CMP        EAX,this
    //         0053c829     MOV        dword ptr [EBP + x2],EAX
    //         0053c82c     JL         LAB_0053c832
    //         0053c82e     DEC        this
    //         0053c82f     MOV        dword ptr [EBP + x2],this
    //                               LAB_0053c832                                                 XREF[1]:     0053c82c(j)  
    //                              visible.cpp:614 (9)
    //         0053c832     MOV        this,dword ptr [EDI]
    //         0053c834     LEA        EAX,[EDX*0x4 + 0x0]
    //                              visible.cpp:615 (14)
    //         0053c83b     MOV        EDX,dword ptr [EAX + unified_map_offsets]        = 00000000
    //         0053c841     MOV        EBX,dword ptr [this->map_offsets + EAX*0x1]
    //         0053c844     ADD        EBX,ESI
    //         0053c846     LEA        this,[EDX + ESI*0x4]
    //                              visible.cpp:617 (34)
    //         0053c849     MOV        EDX,dword ptr [EBP + param_5]
    //         0053c84c     TEST       EDX,EDX
    //         0053c84e     MOV        dword ptr [EBP + param_4],this
    //         0053c851     JZ         LAB_0053c86b
    //         0053c853     MOV        this,dword ptr [EDI + 0xc]
    //         0053c856     MOV        EDX,dword ptr [this->map_offsets + 0x8d8c]
    //         0053c85c     LEA        this,[ESI + ESI*0x2]
    //         0053c85f     MOV        EDX,dword ptr [EDX + EAX*0x1]
    //         0053c862     LEA        EAX,[EDX + this->map_offsets*0x8]
    //         0053c865     MOV        this,dword ptr [EBP + param_4]
    //         0053c868     MOV        dword ptr [EBP + param_3],EAX
    //                               LAB_0053c86b                                                 XREF[1]:     0053c851(j)  
    //                              visible.cpp:621 (5)
    //         0053c86b     CMP        ESI,dword ptr [EBP + x2]
    //         0053c86e     JG         LAB_0053c8ec
    //                               LAB_0053c870                                                 XREF[1]:     0053c8ea(j)  
    //                              visible.cpp:624 (4)
    //         0053c870     MOV        AL,byte ptr [EBX]
    //         0053c872     INC        AL
    //                              visible.cpp:625 (2)
    //         0053c874     JNZ        LAB_0053c8b5
    //                              visible.cpp:627 (3)
    //         0053c876     MOV        this,dword ptr [EBP + Revealed]
    //                              visible.cpp:628 (8)
    //         0053c879     MOV        EAX,dword ptr [EDI + 0x1c]
    //         0053c87c     INC        this
    //         0053c87d     INC        EAX
    //         0053c87e     MOV        dword ptr [EBP + Revealed],this
    //                              visible.cpp:629 (19)
    //         0053c881     MOV        this,dword ptr [EBP + y]
    //         0053c884     PUSH       this
    //         0053c885     MOV        this,dword ptr [EDI + 0x8]
    //         0053c888     PUSH       ESI
    //         0053c889     ADD        this,0x58
    //         0053c88c     MOV        dword ptr [EDI + 0x1c],EAX
    //         0053c88f     CALL       RGE_Tile_List::add_node                          void add_node(RGE_Tile_List * this, int param
    //                              visible.cpp:631 (7)
    //         0053c894     MOV        EAX,dword ptr [EBP + VisibleToCurPlayer]
    //         0053c897     TEST       EAX,EAX
    //         0053c899     JZ         LAB_0053c8ab
    //                              visible.cpp:632 (16)
    //         0053c89b     MOV        EDX,dword ptr [EBP + y]
    //         0053c89e     MOV        EAX,dword ptr [EBP + curVisPlayer]
    //         0053c8a1     PUSH       EDX
    //         0053c8a2     PUSH       ESI
    //         0053c8a3     LEA        this,[EAX + 0x6c]
    //         0053c8a6     CALL       RGE_Tile_List::add_node                          void add_node(RGE_Tile_List * this, int param
    //                               LAB_0053c8ab                                                 XREF[1]:     0053c899(j)  
    //                              visible.cpp:635 (10)
    //         0053c8ab     MOV        this,dword ptr [EBP + param_4]
    //         0053c8ae     MOV        EDX,dword ptr [EDI + 0x2c]
    //         0053c8b1     MOV        AL,0x1
    //         0053c8b3     OR         dword ptr [this->map_offsets],EDX
    //                               LAB_0053c8b5                                                 XREF[1]:     0053c874(j)  
    //                              visible.cpp:637 (4)
    //         0053c8b5     CMP        AL,0x1
    //         0053c8b7     JNZ        LAB_0053c8cc
    //                              visible.cpp:639 (14)
    //         0053c8b9     MOV        EDX,dword ptr [EBP + param_5]
    //         0053c8bc     TEST       EDX,EDX
    //         0053c8be     JZ         LAB_0053c8c7
    //         0053c8c0     MOV        EDX,dword ptr [EBP + param_3]
    //         0053c8c3     MOV        byte ptr [EDX + 0x9],0xf
    //                               LAB_0053c8c7                                                 XREF[1]:     0053c8be(j)  
    //                              visible.cpp:640 (5)
    //         0053c8c7     MOV        EDX,dword ptr [EDI + 0x24]
    //         0053c8ca     OR         dword ptr [this->map_offsets],EDX
    //                               LAB_0053c8cc                                                 XREF[1]:     0053c8b7(j)  
    //                              visible.cpp:643 (6)
    //         0053c8cc     CMP        AL,0xfa
    //         0053c8ce     JNZ        LAB_0053c8d2
    //         0053c8d0     MOV        AL,0xf9
    //                               LAB_0053c8d2                                                 XREF[1]:     0053c8ce(j)  
    //                              visible.cpp:650 (26)
    //         0053c8d2     MOV        EDX,dword ptr [EBP + param_3]
    //         0053c8d5     MOV        byte ptr [EBX],AL
    //         0053c8d7     MOV        EAX,dword ptr [EBP + x2]
    //         0053c8da     INC        EBX
    //         0053c8db     ADD        this,0x4
    //         0053c8de     INC        ESI
    //         0053c8df     ADD        EDX,0x18
    //         0053c8e2     CMP        ESI,EAX
    //         0053c8e4     MOV        dword ptr [EBP + param_4],this
    //         0053c8e7     MOV        dword ptr [EBP + param_3],EDX
    //         0053c8ea     JLE        LAB_0053c870
    //                               LAB_0053c8ec                                                 XREF[1]:     0053c86e(j)  
    //                              visible.cpp:621 (9)
    //         0053c8ec     MOV        EBX,dword ptr [EBP + param_1]
    //         0053c8ef     MOV        this,dword ptr [EBP + param_6]
    //                               LAB_0053c8f2                                                 XREF[2]:     0053c807(j), 0053c810(j)  
    //         0053c8f2     MOV        EAX,dword ptr [ECX + this->map]=>DAT_0058e88c    = FFFFFFF1h
    //                                                                                  = FFFFFFF2h
    //                              visible.cpp:653 (17)
    //         0053c8f5     ADD        this,0xc
    //         0053c8f8     CMP        EAX,0x3e7
    //         0053c8fd     MOV        dword ptr [EBP + param_6],this=>DAT_0058e88c     = FFFFFFF1h
    //                                                                                  = FFFFFFF2h
    //         0053c900     JNZ        LAB_0053c7fd
    //                               LAB_0053c906                                                 XREF[1]:     0053c7f7(j)  
    //                              visible.cpp:656 (3)
    //         0053c906     MOV        EAX,dword ptr [EBP + Revealed]
    //                              visible.cpp:658 (9)
    //         0053c909     POP        EDI
    //         0053c90a     POP        ESI
    //         0053c90b     POP        EBX
    //         0053c90c     MOV        ESP,EBP
    //         0053c90e     POP        EBP
    //         0053c90f     RET        0x18
}

// Offset: 0x0053C920
void unexplore_terrain(RGE_Visible_Map* this_, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Visible_Map::unexplore_terrain(int,int,int,int,int,int)                   *
    //                              *********************************************************************************************************
    //                              void __thiscall unexplore_terrain(RGE_Visible_Map * this, int param_
    //              void              <VOID>         <RETURN>
    //              RGE_Visible_Ma    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[3]:     0053c939(R), 0053c999(R), 0053ca91(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[3]:     0053c92b(R), 0053c99f(R), 0053c9ea(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[4]:     0053c935(R), 0053c9a5(R), 0053ca33(W), 0053ca47(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[7]:     0053c931(R), 0053c9a8(R), 0053c9be(R), 0053c9cc(W), 
    //                                                                                     0053c9d8(W), 0053ca8e(R), 0053ca9f(W)  
    //              int               Stack[0x14]:4  param_5                   XREF[2]:     0053ca2c(R), 0053ca69(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[5]:     0053c93d(R), 0053c97b(W), 0053c985(R), 0053c9ab(W), 
    //                                                                                     0053c9ae(R)  
    //              RGE_Tile *        Stack[-0x8]:4  tile                      XREF[5]:     0053c959(W), 0053ca50(W), 0053ca70(R), 0053ca7c(R), 
    //                                                                                     0053ca89(W)  
    //              int               Stack[-0xc]:4  plNum                     XREF[2]:     0053c982(W), 0053c993(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     0053c955(W), 0053ca4d(R)  
    //                               ?unexplore_terrain@RGE_Visible_Map@@QAEXHHHHHH@Z             XREF[1]:     unexplore_terrain:004c5b06(c)  
    //                               RGE_Visible_Map::unexplore_terrain
    //                              visible.cpp:665 (6)
    //         0053c920     PUSH       EBP
    //         0053c921     MOV        EBP,ESP
    //         0053c923     SUB        ESP,0xc
    //                              visible.cpp:678 (63)
    //         0053c926     MOV        EAX,[Map_Update_Suppresion]
    //         0053c92b     MOV        EDX,dword ptr [EBP + param_2]
    //         0053c92e     PUSH       EBX
    //         0053c92f     MOV        EBX,this
    //         0053c931     MOV        this,dword ptr [EBP + param_4]
    //         0053c934     PUSH       ESI
    //         0053c935     MOV        ESI,dword ptr [EBP + param_3]
    //         0053c938     PUSH       EDI
    //         0053c939     MOV        EDI,dword ptr [EBP + param_1]
    //         0053c93c     PUSH       EAX
    //         0053c93d     MOV        EAX,dword ptr [EBP + param_6]
    //         0053c940     PUSH       this
    //         0053c941     MOV        this,dword ptr [EBX + 0x8]
    //         0053c944     PUSH       ESI
    //         0053c945     PUSH       EDX
    //         0053c946     PUSH       EDI
    //         0053c947     MOVSX      EDX,word ptr [this->map_offsets + 0x4a]
    //         0053c94b     PUSH       EAX
    //         0053c94c     MOV        EAX,dword ptr [EBX + 0x4]
    //         0053c94f     PUSH       0x3
    //         0053c951     PUSH       EDX
    //         0053c952     MOV        this,dword ptr [EAX + 0x4]
    //         0053c955     MOV        dword ptr [EBP + local_10],EBX
    //         0053c958     PUSH       this
    //         0053c959     MOV        dword ptr [EBP + tile],0x0
    //         0053c960     CALL       log_map_call                                     void log_map_call(int param_1, int param_2, i
    //                              visible.cpp:681 (16)
    //         0053c965     MOV        EAX,[Map_Update_Suppresion]
    //         0053c96a     ADD        ESP,0x24
    //         0053c96d     TEST       EAX,EAX
    //         0053c96f     JNZ        LAB_0053caa8
    //                              visible.cpp:687 (16)
    //         0053c975     MOV        EAX,dword ptr [EBX + 0x8]
    //         0053c978     MOV        EDX,dword ptr [EBX + 0x34]
    //         0053c97b     MOV        dword ptr [EBP + param_6],EDX
    //         0053c97e     MOVSX      this,word ptr [EAX + 0x4a]
    //         0053c982     MOV        dword ptr [EBP + plNum],this
    //                              visible.cpp:691 (3)
    //         0053c985     MOV        EAX,dword ptr [EBP + param_6]
    //                              visible.cpp:692 (3)
    //         0053c988     ROL        EAX,0x3
    //                              visible.cpp:693 (5)
    //         0053c98b     XOR        EAX,0x20202020
    //                              visible.cpp:694 (3)
    //         0053c990     ROL        EAX,0x2
    //                              visible.cpp:695 (3)
    //         0053c993     XOR        EAX,dword ptr [EBP + plNum]
    //                              visible.cpp:696 (3)
    //         0053c996     ROL        EAX,0x3
    //                              visible.cpp:697 (3)
    //         0053c999     XOR        EAX,dword ptr [EBP + param_1]
    //                              visible.cpp:698 (3)
    //         0053c99c     ROL        EAX,0x4
    //                              visible.cpp:699 (3)
    //         0053c99f     XOR        EAX,dword ptr [EBP + param_2]
    //                              visible.cpp:700 (3)
    //         0053c9a2     ROL        EAX,0x3
    //                              visible.cpp:701 (3)
    //         0053c9a5     XOR        EAX,dword ptr [EBP + param_3]
    //                              visible.cpp:702 (3)
    //         0053c9a8     ADD        EAX,dword ptr [EBP + param_4]
    //                              visible.cpp:703 (3)
    //         0053c9ab     MOV        dword ptr [EBP + param_6],EAX
    //                              visible.cpp:706 (3)
    //         0053c9ae     MOV        EDX,dword ptr [EBP + param_6]
    //                              visible.cpp:712 (13)
    //         0053c9b1     CMP        ESI,0x10
    //         0053c9b4     MOV        dword ptr [EBX + 0x34],EDX
    //         0053c9b7     JLE        LAB_0053c9be
    //         0053c9b9     MOV        ESI,0x10
    //                               LAB_0053c9be                                                 XREF[1]:     0053c9b7(j)  
    //                              visible.cpp:714 (7)
    //         0053c9be     MOV        EAX,dword ptr [EBP + param_4]
    //         0053c9c1     TEST       EAX,EAX
    //         0053c9c3     JZ         LAB_0053c9d1
    //                              visible.cpp:715 (10)
    //         0053c9c5     MOV        EDX,dword ptr [ESI*0x4 + 0x58ea58]=>->Edge_Off   = 0058dc38
    //                                                                                  = 0058e880
    //         0053c9cc     MOV        dword ptr [EBP + param_4],EDX=>Edge_Offsets_T16  = fffffff0
    //                              visible.cpp:716 (2)
    //         0053c9cf     JMP        LAB_0053c9dd
    //                               LAB_0053c9d1                                                 XREF[1]:     0053c9c3(j)  
    //                              visible.cpp:717 (12)
    //         0053c9d1     MOV        EAX,dword ptr [ESI*0x4 + 0x58ea10]=>->Edge_Off   = 0058daa0
    //         0053c9d8     MOV        dword ptr [EBP + param_4],EAX=>Edge_Offsets_N16  = fffffff0
    //         0053c9db     MOV        EDX,EAX
    //                               LAB_0053c9dd                                                 XREF[1]:     0053c9cf(j)  
    //                              visible.cpp:721 (13)
    //         0053c9dd     MOV        EAX=>Edge_Offsets_N16,dword ptr [EDX]=>Edge_Of   = fffffff0
    //         0053c9df     CMP        EAX,0x3e7
    //         0053c9e4     JZ         LAB_0053caa8
    //                               LAB_0053c9ea                                                 XREF[1]:     0053caa2(j)  
    //                              visible.cpp:723 (5)
    //         0053c9ea     MOV        this,dword ptr [EBP + param_2]
    //         0053c9ed     ADD        EAX,this
    //                              visible.cpp:727 (17)
    //         0053c9ef     TEST       EAX,EAX
    //         0053c9f1     JL         LAB_0053ca94
    //         0053c9f7     CMP        EAX,dword ptr [EBX + 0x18]
    //         0053c9fa     JGE        LAB_0053ca94
    //                              visible.cpp:729 (9)
    //         0053ca00     MOV        this,dword ptr [EDX + 0x4]=>DAT_0058e884         = FFFFFFFDh
    //                                                                                  = FFFFFFFCh
    //                                                                                  = FFFFFFF9h
    //         0053ca03     ADD        this,EDI
    //         0053ca05     JNS        LAB_0053ca09
    //         0053ca07     XOR        this,this
    //                               LAB_0053ca09                                                 XREF[1]:     0053ca05(j)  
    //                              visible.cpp:730 (15)
    //         0053ca09     MOV        EDX,dword ptr [EDX + 0x8]=>DAT_0058e888          = 00000003h
    //                                                                                  = 00000006h
    //         0053ca0c     MOV        ESI,dword ptr [EBX + 0x14]
    //         0053ca0f     ADD        EDX,EDI
    //         0053ca11     CMP        EDX,ESI
    //         0053ca13     JL         LAB_0053ca18
    //         0053ca15     LEA        EDX,[ESI + -0x1]
    //                               LAB_0053ca18                                                 XREF[1]:     0053ca13(j)  
    //                              visible.cpp:732 (9)
    //         0053ca18     LEA        ESI,[EAX*0x4 + 0x0]
    //         0053ca1f     MOV        EAX,dword ptr [EBX]
    //                              visible.cpp:733 (11)
    //         0053ca21     MOV        EDI,dword ptr [ESI + unified_map_offsets]        = 00000000
    //         0053ca27     MOV        EAX,dword ptr [EAX + ESI*0x1]
    //         0053ca2a     ADD        EAX,this
    //                              visible.cpp:735 (39)
    //         0053ca2c     CMP        dword ptr [EBP + param_5],0x0
    //         0053ca30     LEA        EDI,[EDI + this->map_offsets*0x4]
    //         0053ca33     MOV        dword ptr [EBP + param_3],EDI
    //         0053ca36     JZ         LAB_0053ca53
    //         0053ca38     MOV        EDI,dword ptr [EBX + 0xc]
    //         0053ca3b     LEA        EBX,[ECX + ECX*0x2]
    //         0053ca3e     MOV        EDI,dword ptr [EDI + 0x8d8c]
    //         0053ca44     MOV        ESI,dword ptr [EDI + ESI*0x1]
    //         0053ca47     MOV        EDI,dword ptr [EBP + param_3]
    //         0053ca4a     LEA        ESI,[ESI + EBX*0x8]
    //         0053ca4d     MOV        EBX,dword ptr [EBP + local_10]
    //         0053ca50     MOV        dword ptr [EBP + tile],ESI
    //                               LAB_0053ca53                                                 XREF[1]:     0053ca36(j)  
    //                              visible.cpp:739 (7)
    //         0053ca53     CMP        this,EDX
    //         0053ca55     JG         LAB_0053ca8e
    //         0053ca57     SUB        EDX,this
    //         0053ca59     INC        EDX
    //                               LAB_0053ca5a                                                 XREF[1]:     0053ca8c(j)  
    //                              visible.cpp:742 (4)
    //         0053ca5a     MOV        this,byte ptr [EAX]
    //         0053ca5c     DEC        this
    //                              visible.cpp:744 (7)
    //         0053ca5e     CMP        this,0xff
    //         0053ca61     JNZ        LAB_0053ca65
    //         0053ca63     XOR        this,this
    //                               LAB_0053ca65                                                 XREF[1]:     0053ca61(j)  
    //                              visible.cpp:748 (4)
    //         0053ca65     TEST       this,this
    //         0053ca67     JNZ        LAB_0053ca7c
    //                              visible.cpp:750 (14)
    //         0053ca69     MOV        ESI,dword ptr [EBP + param_5]
    //         0053ca6c     TEST       ESI,ESI
    //         0053ca6e     JZ         LAB_0053ca77
    //         0053ca70     MOV        ESI,dword ptr [EBP + tile]
    //         0053ca73     MOV        byte ptr [ESI + 0x9],0x80
    //                               LAB_0053ca77                                                 XREF[1]:     0053ca6e(j)  
    //                              visible.cpp:751 (5)
    //         0053ca77     MOV        ESI,dword ptr [EBX + 0x28]
    //         0053ca7a     AND        dword ptr [EDI],ESI
    //                               LAB_0053ca7c                                                 XREF[1]:     0053ca67(j)  
    //                              visible.cpp:759 (18)
    //         0053ca7c     MOV        ESI,dword ptr [EBP + tile]
    //         0053ca7f     MOV        byte ptr [EAX],this
    //         0053ca81     INC        EAX
    //         0053ca82     ADD        EDI,0x4
    //         0053ca85     ADD        ESI,0x18
    //         0053ca88     DEC        EDX
    //         0053ca89     MOV        dword ptr [EBP + tile],ESI
    //         0053ca8c     JNZ        LAB_0053ca5a
    //                               LAB_0053ca8e                                                 XREF[1]:     0053ca55(j)  
    //                              visible.cpp:739 (9)
    //         0053ca8e     MOV        EDX,dword ptr [EBP + param_4]
    //         0053ca91     MOV        EDI,dword ptr [EBP + param_1]
    //                               LAB_0053ca94                                                 XREF[2]:     0053c9f1(j), 0053c9fa(j)  
    //         0053ca94     MOV        EAX,dword ptr [EDX + 0xc]=>DAT_0058e88c          = FFFFFFF1h
    //                                                                                  = FFFFFFF2h
    //                              visible.cpp:762 (17)
    //         0053ca97     ADD        EDX,0xc
    //         0053ca9a     CMP        EAX,0x3e7
    //         0053ca9f     MOV        dword ptr [EBP + param_4],EDX=>DAT_0058e88c      = FFFFFFF1h
    //                                                                                  = FFFFFFF2h
    //         0053caa2     JNZ        LAB_0053c9ea
    //                               LAB_0053caa8                                                 XREF[2]:     0053c96f(j), 0053c9e4(j)  
    //                              visible.cpp:767 (9)
    //         0053caa8     POP        EDI
    //         0053caa9     POP        ESI
    //         0053caaa     POP        EBX
    //         0053caab     MOV        ESP,EBP
    //         0053caad     POP        EBP
    //         0053caae     RET        0x18
}

// Offset: 0x0053CAC0
int explore_terrain_sq(RGE_Visible_Map* this_, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall RGE_Visible_Map::explore_terrain_sq(int,int,int,int,int,int)                   *
    //                              *********************************************************************************************************
    //                              int __thiscall explore_terrain_sq(RGE_Visible_Map * this, int param_
    //              int               EAX:4          <RETURN>
    //              RGE_Visible_Ma    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[7]:     0053cacf(R), 0053cb54(R), 0053cbb4(W), 0053cbbb(R), 
    //                                                                                     0053cbf2(R), 0053cc17(R), 0053cc2f(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[7]:     0053cad9(R), 0053cb5a(R), 0053cbdd(W), 0053cc50(R), 
    //                                                                                     0053cc68(R), 0053ccbd(R), 0053ccc6(W)  
    //              int               Stack[0xc]:4   param_3                   XREF[7]:     0053cacb(R), 0053cb60(R), 0053cb91(R), 0053cbbe(R), 
    //                                                                                     0053cbc4(W), 0053cc32(R), 0053cca8(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[7]:     0053cad5(R), 0053cb66(R), 0053cba5(R), 0053cbcd(R), 
    //                                                                                     0053cbd3(W), 0053cbd6(R), 0053ccc0(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[2]:     0053cc08(R), 0053cc8a(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[6]:     0053cadd(R), 0053cb3d(W), 0053cc2c(W), 0053cc91(R), 
    //                                                                                     0053cca3(R), 0053ccb8(W)  
    //              uchar *           Stack[-0x8]:4  p                         XREF[8]:     0053cb43(W), 0053cb46(R), 0053cb69(W), 0053cb6c(R), 
    //                                                                                     0053cc0f(W), 0053cc29(R), 0053cc83(R), 0053ccb5(W)  
    //              int               Stack[-0xc]:4  Revealed                  XREF[4]:     0053caf5(W), 0053cc43(R), 0053cc4d(W), 0053cccf(R)  
    //              RGE_Player *      Stack[-0x10]:4 curVisPlayer              XREF[3]:     0053cb40(W), 0053cb83(W), 0053cc6b(R)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[2]:     0053cbed(W), 0053cbf7(R)  
    //              int               Stack[-0x18]:4 isCurPlayer               XREF[2]:     0053cb3a(W), 0053cc61(R)  
    //                               ?explore_terrain_sq@RGE_Visible_Map@@QAEHHHHHHH@Z            XREF[1]:     explore_terrain:004c5a87(c)  
    //                               RGE_Visible_Map::explore_terrain_sq
    //                              visible.cpp:775 (6)
    //         0053cac0     PUSH       EBP
    //         0053cac1     MOV        EBP,ESP
    //         0053cac3     SUB        ESP,0x14
    //                              visible.cpp:781 (60)
    //         0053cac6     MOV        EAX,[Map_Update_Suppresion]
    //         0053cacb     MOV        EDX,dword ptr [EBP + param_3]
    //         0053cace     PUSH       EBX
    //         0053cacf     MOV        EBX,dword ptr [EBP + param_1]
    //         0053cad2     PUSH       ESI
    //         0053cad3     MOV        ESI,this
    //         0053cad5     MOV        this,dword ptr [EBP + param_4]
    //         0053cad8     PUSH       EDI
    //         0053cad9     MOV        EDI,dword ptr [EBP + param_2]
    //         0053cadc     PUSH       EAX
    //         0053cadd     MOV        EAX,dword ptr [EBP + param_6]
    //         0053cae0     PUSH       this
    //         0053cae1     MOV        this,dword ptr [ESI + 0x8]
    //         0053cae4     PUSH       EDX
    //         0053cae5     PUSH       EDI
    //         0053cae6     PUSH       EBX
    //         0053cae7     MOVSX      EDX,word ptr [this->map_offsets + 0x4a]
    //         0053caeb     PUSH       EAX
    //         0053caec     MOV        EAX,dword ptr [ESI + 0x4]
    //         0053caef     PUSH       0x2
    //         0053caf1     PUSH       EDX
    //         0053caf2     MOV        this,dword ptr [EAX + 0x4]
    //         0053caf5     MOV        dword ptr [EBP + Revealed],0x0
    //         0053cafc     PUSH       this
    //         0053cafd     CALL       log_map_call                                     void log_map_call(int param_1, int param_2, i
    //                              visible.cpp:784 (16)
    //         0053cb02     MOV        EAX,[Map_Update_Suppresion]
    //         0053cb07     ADD        ESP,0x24
    //         0053cb0a     TEST       EAX,EAX
    //         0053cb0c     JNZ        LAB_0053ccdb
    //                              visible.cpp:788 (35)
    //         0053cb12     MOV        EAX,dword ptr [ESI + 0x4]
    //         0053cb15     MOV        this,dword ptr [ESI + 0x8]
    //         0053cb18     MOVSX      EDX,word ptr [EAX + 0x7c]
    //         0053cb1c     MOV        EAX,dword ptr [EAX + 0x40]
    //         0053cb1f     MOVSX      this,word ptr [this->map_offsets + 0x4a]
    //         0053cb23     MOV        EDX,dword ptr [EAX + EDX*0x4]
    //         0053cb26     XOR        EAX,EAX
    //         0053cb28     CMP        dword ptr [EDX + this->map_offsets*0x4 + 0xac]
    //         0053cb30     SETZ       AL
    //         0053cb33     MOV        this,EAX
    //                              visible.cpp:800 (17)
    //         0053cb35     MOV        EAX,dword ptr [ESI + 0x34]
    //         0053cb38     XOR        EDX,EDX
    //         0053cb3a     MOV        dword ptr [EBP + isCurPlayer],this
    //         0053cb3d     MOV        dword ptr [EBP + param_6],EDX
    //         0053cb40     MOV        dword ptr [EBP + curVisPlayer],EDX
    //         0053cb43     MOV        dword ptr [EBP + p],EAX
    //                              visible.cpp:804 (3)
    //         0053cb46     MOV        EAX,dword ptr [EBP + p]
    //                              visible.cpp:805 (3)
    //         0053cb49     ROL        EAX,0x3
    //                              visible.cpp:806 (5)
    //         0053cb4c     XOR        EAX,0x34343434
    //                              visible.cpp:807 (3)
    //         0053cb51     ROL        EAX,0x2
    //                              visible.cpp:808 (3)
    //         0053cb54     XOR        EAX,dword ptr [EBP + param_1]
    //                              visible.cpp:809 (3)
    //         0053cb57     ROL        EAX,0x4
    //                              visible.cpp:810 (3)
    //         0053cb5a     XOR        EAX,dword ptr [EBP + param_2]
    //                              visible.cpp:811 (3)
    //         0053cb5d     ROL        EAX,0x3
    //                              visible.cpp:812 (3)
    //         0053cb60     XOR        EAX,dword ptr [EBP + param_3]
    //                              visible.cpp:813 (3)
    //         0053cb63     ROL        EAX,0x3
    //                              visible.cpp:814 (3)
    //         0053cb66     XOR        EAX,dword ptr [EBP + param_4]
    //                              visible.cpp:815 (3)
    //         0053cb69     MOV        dword ptr [EBP + p],EAX
    //                              visible.cpp:818 (3)
    //         0053cb6c     MOV        EAX,dword ptr [EBP + p]
    //                              visible.cpp:825 (7)
    //         0053cb6f     CMP        this,EDX
    //         0053cb71     MOV        dword ptr [ESI + 0x34],EAX
    //         0053cb74     JZ         LAB_0053cb86
    //                              visible.cpp:826 (16)
    //         0053cb76     MOV        EAX,dword ptr [ESI + 0x4]
    //         0053cb79     MOVSX      this,word ptr [EAX + 0x7c]
    //         0053cb7d     MOV        EAX,dword ptr [EAX + 0x40]
    //         0053cb80     MOV        this,dword ptr [EAX + this->map_offsets*0x4]
    //         0053cb83     MOV        dword ptr [EBP + curVisPlayer],this
    //                               LAB_0053cb86                                                 XREF[1]:     0053cb74(j)  
    //                              visible.cpp:828 (20)
    //         0053cb86     MOV        EAX,dword ptr [ESI + 0x14]
    //         0053cb89     CMP        EBX,EAX
    //         0053cb8b     JGE        LAB_0053ccdb
    //         0053cb91     CMP        dword ptr [EBP + param_3],EDX
    //         0053cb94     JL         LAB_0053ccdb
    //                              visible.cpp:829 (22)
    //         0053cb9a     MOV        this,dword ptr [ESI + 0x18]
    //         0053cb9d     CMP        EDI,this
    //         0053cb9f     JGE        LAB_0053ccdb
    //         0053cba5     MOV        EDX,dword ptr [EBP + param_4]
    //         0053cba8     TEST       EDX,EDX
    //         0053cbaa     JL         LAB_0053ccdb
    //                              visible.cpp:831 (14)
    //         0053cbb0     TEST       EBX,EBX
    //         0053cbb2     JGE        LAB_0053cbbe
    //         0053cbb4     MOV        dword ptr [EBP + param_1],0x0
    //         0053cbbb     MOV        EBX,dword ptr [EBP + param_1]
    //                               LAB_0053cbbe                                                 XREF[1]:     0053cbb2(j)  
    //                              visible.cpp:832 (9)
    //         0053cbbe     CMP        dword ptr [EBP + param_3],EAX
    //         0053cbc1     JL         LAB_0053cbc7
    //         0053cbc3     DEC        EAX
    //         0053cbc4     MOV        dword ptr [EBP + param_3],EAX
    //                               LAB_0053cbc7                                                 XREF[1]:     0053cbc1(j)  
    //                              visible.cpp:834 (6)
    //         0053cbc7     TEST       EDI,EDI
    //         0053cbc9     JGE        LAB_0053cbcd
    //         0053cbcb     XOR        EDI,EDI
    //                               LAB_0053cbcd                                                 XREF[1]:     0053cbc9(j)  
    //                              visible.cpp:835 (9)
    //         0053cbcd     CMP        dword ptr [EBP + param_4],this
    //         0053cbd0     JL         LAB_0053cbd6
    //         0053cbd2     DEC        this
    //         0053cbd3     MOV        dword ptr [EBP + param_4],this
    //                               LAB_0053cbd6                                                 XREF[1]:     0053cbd0(j)  
    //                              visible.cpp:838 (16)
    //         0053cbd6     MOV        this,dword ptr [EBP + param_4]
    //         0053cbd9     MOV        EAX,EDI
    //         0053cbdb     CMP        EDI,this
    //         0053cbdd     MOV        dword ptr [EBP + param_2],EAX
    //         0053cbe0     JG         LAB_0053cccf
    //                              visible.cpp:843 (15)
    //         0053cbe6     LEA        EDX,[EBX*0x4 + 0x0]
    //         0053cbed     MOV        dword ptr [EBP + local_14],EDX
    //         0053cbf0     JMP        LAB_0053cbf5
    //                               LAB_0053cbf2                                                 XREF[1]:     0053ccc9(j)  
    //         0053cbf2     MOV        EBX,dword ptr [EBP + param_1]
    //                               LAB_0053cbf5                                                 XREF[1]:     0053cbf0(j)  
    //                              visible.cpp:842 (2)
    //         0053cbf5     MOV        this,dword ptr [ESI]
    //                              visible.cpp:843 (17)
    //         0053cbf7     MOV        EDX,dword ptr [EBP + local_14]
    //         0053cbfa     SHL        EAX,0x2
    //         0053cbfd     MOV        EDI,dword ptr [EAX + unified_map_offsets]        = 00000000
    //         0053cc03     MOV        this,dword ptr [this->map_offsets + EAX*0x1]
    //         0053cc06     ADD        EDI,EDX
    //                              visible.cpp:845 (39)
    //         0053cc08     MOV        EDX,dword ptr [EBP + param_5]
    //         0053cc0b     ADD        this,EBX
    //         0053cc0d     TEST       EDX,EDX
    //         0053cc0f     MOV        dword ptr [EBP + p],this
    //         0053cc12     JZ         LAB_0053cc2f
    //         0053cc14     MOV        EDX,dword ptr [ESI + 0xc]
    //         0053cc17     MOV        this,dword ptr [EBP + param_1]
    //         0053cc1a     MOV        EDX,dword ptr [EDX + 0x8d8c]
    //         0053cc20     LEA        this,[ECX + ECX*0x2]
    //         0053cc23     MOV        EDX,dword ptr [EDX + EAX*0x1]
    //         0053cc26     LEA        EAX,[EDX + this->map_offsets*0x8]
    //         0053cc29     MOV        this,dword ptr [EBP + p]
    //         0053cc2c     MOV        dword ptr [EBP + param_6],EAX
    //                               LAB_0053cc2f                                                 XREF[1]:     0053cc12(j)  
    //                              visible.cpp:847 (14)
    //         0053cc2f     MOV        EDX,dword ptr [EBP + param_1]
    //         0053cc32     MOV        EAX,dword ptr [EBP + param_3]
    //         0053cc35     CMP        EDX,EAX
    //         0053cc37     JG         LAB_0053ccbd
    //                               LAB_0053cc3d                                                 XREF[1]:     0053ccbb(j)  
    //                              visible.cpp:850 (4)
    //         0053cc3d     MOV        AL,byte ptr [this->map_offsets]
    //         0053cc3f     INC        AL
    //                              visible.cpp:851 (2)
    //         0053cc41     JNZ        LAB_0053cc86
    //                              visible.cpp:853 (3)
    //         0053cc43     MOV        EAX,dword ptr [EBP + Revealed]
    //                              visible.cpp:854 (3)
    //         0053cc46     MOV        EDX,dword ptr [ESI + 0x1c]
    //                              visible.cpp:855 (24)
    //         0053cc49     MOV        this,dword ptr [ESI + 0x8]
    //         0053cc4c     INC        EAX
    //         0053cc4d     MOV        dword ptr [EBP + Revealed],EAX
    //         0053cc50     MOV        EAX,dword ptr [EBP + param_2]
    //         0053cc53     INC        EDX
    //         0053cc54     PUSH       EAX
    //         0053cc55     PUSH       EBX
    //         0053cc56     ADD        this,0x58
    //         0053cc59     MOV        dword ptr [ESI + 0x1c],EDX
    //         0053cc5c     CALL       RGE_Tile_List::add_node                          void add_node(RGE_Tile_List * this, int param
    //                              visible.cpp:857 (7)
    //         0053cc61     MOV        EAX,dword ptr [EBP + isCurPlayer]
    //         0053cc64     TEST       EAX,EAX
    //         0053cc66     JZ         LAB_0053cc78
    //                              visible.cpp:858 (16)
    //         0053cc68     MOV        this,dword ptr [EBP + param_2]
    //         0053cc6b     MOV        EDX,dword ptr [EBP + curVisPlayer]
    //         0053cc6e     PUSH       this
    //         0053cc6f     PUSH       EBX
    //         0053cc70     LEA        this,[EDX + 0x6c]
    //         0053cc73     CALL       RGE_Tile_List::add_node                          void add_node(RGE_Tile_List * this, int param
    //                               LAB_0053cc78                                                 XREF[1]:     0053cc66(j)  
    //                              visible.cpp:860 (7)
    //         0053cc78     MOV        EAX,dword ptr [ESI + 0x2c]
    //         0053cc7b     MOV        this,dword ptr [EDI]
    //         0053cc7d     OR         this,EAX
    //                              visible.cpp:862 (7)
    //         0053cc7f     MOV        AL,0x1
    //         0053cc81     MOV        dword ptr [EDI],this
    //         0053cc83     MOV        this,dword ptr [EBP + p]
    //                               LAB_0053cc86                                                 XREF[1]:     0053cc41(j)  
    //                              visible.cpp:864 (4)
    //         0053cc86     CMP        AL,0x1
    //         0053cc88     JNZ        LAB_0053cc9d
    //                              visible.cpp:866 (14)
    //         0053cc8a     MOV        EDX,dword ptr [EBP + param_5]
    //         0053cc8d     TEST       EDX,EDX
    //         0053cc8f     JZ         LAB_0053cc98
    //         0053cc91     MOV        EDX,dword ptr [EBP + param_6]
    //         0053cc94     MOV        byte ptr [EDX + 0x9],0xf
    //                               LAB_0053cc98                                                 XREF[1]:     0053cc8f(j)  
    //                              visible.cpp:867 (5)
    //         0053cc98     MOV        EDX,dword ptr [ESI + 0x24]
    //         0053cc9b     OR         dword ptr [EDI],EDX
    //                               LAB_0053cc9d                                                 XREF[1]:     0053cc88(j)  
    //                              visible.cpp:870 (6)
    //         0053cc9d     CMP        AL,0xfa
    //         0053cc9f     JNZ        LAB_0053cca3
    //         0053cca1     MOV        AL,0xf9
    //                               LAB_0053cca3                                                 XREF[1]:     0053cc9f(j)  
    //                              visible.cpp:877 (26)
    //         0053cca3     MOV        EDX,dword ptr [EBP + param_6]
    //         0053cca6     MOV        byte ptr [this->map_offsets],AL
    //         0053cca8     MOV        EAX,dword ptr [EBP + param_3]
    //         0053ccab     INC        this
    //         0053ccac     ADD        EDI,0x4
    //         0053ccaf     INC        EBX
    //         0053ccb0     ADD        EDX,0x18
    //         0053ccb3     CMP        EBX,EAX
    //         0053ccb5     MOV        dword ptr [EBP + p],this
    //         0053ccb8     MOV        dword ptr [EBP + param_6],EDX
    //         0053ccbb     JLE        LAB_0053cc3d
    //                               LAB_0053ccbd                                                 XREF[1]:     0053cc37(j)  
    //                              visible.cpp:838 (18)
    //         0053ccbd     MOV        EAX,dword ptr [EBP + param_2]
    //         0053ccc0     MOV        this,dword ptr [EBP + param_4]
    //         0053ccc3     INC        EAX
    //         0053ccc4     CMP        EAX,this
    //         0053ccc6     MOV        dword ptr [EBP + param_2],EAX
    //         0053ccc9     JLE        LAB_0053cbf2
    //                               LAB_0053cccf                                                 XREF[1]:     0053cbe0(j)  
    //                              visible.cpp:881 (3)
    //         0053cccf     MOV        EAX,dword ptr [EBP + Revealed]
    //                              visible.cpp:883 (20)
    //         0053ccd2     POP        EDI
    //         0053ccd3     POP        ESI
    //         0053ccd4     POP        EBX
    //         0053ccd5     MOV        ESP,EBP
    //         0053ccd7     POP        EBP
    //         0053ccd8     RET        0x18
    //                               LAB_0053ccdb                                                 XREF[5]:     0053cb0c(j), 0053cb8b(j), 
    //                                                                                                         0053cb94(j), 0053cb9f(j), 
    //                                                                                                         0053cbaa(j)  
    //         0053ccdb     POP        EDI
    //         0053ccdc     POP        ESI
    //         0053ccdd     XOR        EAX,EAX
    //         0053ccdf     POP        EBX
    //         0053cce0     MOV        ESP,EBP
    //         0053cce2     POP        EBP
    //         0053cce3     RET        0x18
}

// Offset: 0x0053CCF0
void unexplore_terrain_sq(RGE_Visible_Map* this_, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Visible_Map::unexplore_terrain_sq(int,int,int,int,int,int)                *
    //                              *********************************************************************************************************
    //                              void __thiscall unexplore_terrain_sq(RGE_Visible_Map * this, int par
    //              void              <VOID>         <RETURN>
    //              RGE_Visible_Ma    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[2]:     0053cd09(R), 0053cd59(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[6]:     0053cd05(R), 0053cd5f(R), 0053cdc4(W), 0053cdcf(R), 
    //                                                                                     0053ce52(R), 0053ce5b(W)  
    //              int               Stack[0xc]:4   param_3                   XREF[6]:     0053ccfb(R), 0053cd65(R), 0053cd82(R), 0053cda9(R), 
    //                                                                                     0053cdaf(W), 0053ce0e(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[7]:     0053cd01(R), 0053cd6b(R), 0053cd98(R), 0053cdb8(R), 
    //                                                                                     0053cdbe(W), 0053cdc1(R), 0053ce55(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[2]:     0053cdef(R), 0053ce27(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[5]:     0053cd0d(R), 0053cd48(W), 0053cd4b(R), 0053cd6e(W), 
    //                                                                                     0053cd71(R)  
    //              RGE_Tile *        Stack[-0x8]:4  tile                      XREF[5]:     0053cd29(W), 0053ce0b(W), 0053ce2e(R), 0053ce42(R), 
    //                                                                                     0053ce4d(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[4]:     0053cd25(W), 0053ce08(R), 0053ce35(R), 0053ce3d(R)  
    //                               ?unexplore_terrain_sq@RGE_Visible_Map@@QAEXHHHHHH@Z          XREF[1]:     unexplore_terrain:004c5b77(c)  
    //                               RGE_Visible_Map::unexplore_terrain_sq
    //                              visible.cpp:891 (6)
    //         0053ccf0     PUSH       EBP
    //         0053ccf1     MOV        EBP,ESP
    //         0053ccf3     SUB        ESP,0x8
    //                              visible.cpp:902 (63)
    //         0053ccf6     MOV        EAX,[Map_Update_Suppresion]
    //         0053ccfb     MOV        EDX,dword ptr [EBP + param_3]
    //         0053ccfe     PUSH       EBX
    //         0053ccff     MOV        EBX,this
    //         0053cd01     MOV        this,dword ptr [EBP + param_4]
    //         0053cd04     PUSH       ESI
    //         0053cd05     MOV        ESI,dword ptr [EBP + param_2]
    //         0053cd08     PUSH       EDI
    //         0053cd09     MOV        EDI,dword ptr [EBP + param_1]
    //         0053cd0c     PUSH       EAX
    //         0053cd0d     MOV        EAX,dword ptr [EBP + param_6]
    //         0053cd10     PUSH       this
    //         0053cd11     MOV        this,dword ptr [EBX + 0x8]
    //         0053cd14     PUSH       EDX
    //         0053cd15     PUSH       ESI
    //         0053cd16     PUSH       EDI
    //         0053cd17     MOVSX      EDX,word ptr [this->map_offsets + 0x4a]
    //         0053cd1b     PUSH       EAX
    //         0053cd1c     MOV        EAX,dword ptr [EBX + 0x4]
    //         0053cd1f     PUSH       0x4
    //         0053cd21     PUSH       EDX
    //         0053cd22     MOV        this,dword ptr [EAX + 0x4]
    //         0053cd25     MOV        dword ptr [EBP + local_c],EBX
    //         0053cd28     PUSH       this
    //         0053cd29     MOV        dword ptr [EBP + tile],0x0
    //         0053cd30     CALL       log_map_call                                     void log_map_call(int param_1, int param_2, i
    //                              visible.cpp:905 (16)
    //         0053cd35     MOV        EAX,[Map_Update_Suppresion]
    //         0053cd3a     ADD        ESP,0x24
    //         0053cd3d     TEST       EAX,EAX
    //         0053cd3f     JNZ        LAB_0053ce64
    //                              visible.cpp:909 (6)
    //         0053cd45     MOV        EDX,dword ptr [EBX + 0x34]
    //         0053cd48     MOV        dword ptr [EBP + param_6],EDX
    //                              visible.cpp:913 (3)
    //         0053cd4b     MOV        EAX,dword ptr [EBP + param_6]
    //                              visible.cpp:914 (3)
    //         0053cd4e     ROL        EAX,0x3
    //                              visible.cpp:915 (5)
    //         0053cd51     XOR        EAX,0x56565656
    //                              visible.cpp:916 (3)
    //         0053cd56     ROL        EAX,0x2
    //                              visible.cpp:917 (3)
    //         0053cd59     XOR        EAX,dword ptr [EBP + param_1]
    //                              visible.cpp:918 (3)
    //         0053cd5c     ROL        EAX,0x4
    //                              visible.cpp:919 (3)
    //         0053cd5f     XOR        EAX,dword ptr [EBP + param_2]
    //                              visible.cpp:920 (3)
    //         0053cd62     ROL        EAX,0x3
    //                              visible.cpp:921 (3)
    //         0053cd65     XOR        EAX,dword ptr [EBP + param_3]
    //                              visible.cpp:922 (3)
    //         0053cd68     ROL        EAX,0x3
    //                              visible.cpp:923 (3)
    //         0053cd6b     XOR        EAX,dword ptr [EBP + param_4]
    //                              visible.cpp:924 (3)
    //         0053cd6e     MOV        dword ptr [EBP + param_6],EAX
    //                              visible.cpp:927 (6)
    //         0053cd71     MOV        EAX,dword ptr [EBP + param_6]
    //         0053cd74     MOV        dword ptr [EBX + 0x34],EAX
    //                              visible.cpp:931 (22)
    //         0053cd77     MOV        EAX,dword ptr [EBX + 0x14]
    //         0053cd7a     CMP        EDI,EAX
    //         0053cd7c     JGE        LAB_0053ce64
    //         0053cd82     MOV        this,dword ptr [EBP + param_3]
    //         0053cd85     TEST       this,this
    //         0053cd87     JL         LAB_0053ce64
    //                              visible.cpp:932 (22)
    //         0053cd8d     MOV        this,dword ptr [EBX + 0x18]
    //         0053cd90     CMP        ESI,this
    //         0053cd92     JGE        LAB_0053ce64
    //         0053cd98     MOV        EDX,dword ptr [EBP + param_4]
    //         0053cd9b     TEST       EDX,EDX
    //         0053cd9d     JL         LAB_0053ce64
    //                              visible.cpp:934 (6)
    //         0053cda3     TEST       EDI,EDI
    //         0053cda5     JGE        LAB_0053cda9
    //         0053cda7     XOR        EDI,EDI
    //                               LAB_0053cda9                                                 XREF[1]:     0053cda5(j)  
    //                              visible.cpp:935 (9)
    //         0053cda9     CMP        dword ptr [EBP + param_3],EAX
    //         0053cdac     JL         LAB_0053cdb2
    //         0053cdae     DEC        EAX
    //         0053cdaf     MOV        dword ptr [EBP + param_3],EAX
    //                               LAB_0053cdb2                                                 XREF[1]:     0053cdac(j)  
    //                              visible.cpp:937 (6)
    //         0053cdb2     TEST       ESI,ESI
    //         0053cdb4     JGE        LAB_0053cdb8
    //         0053cdb6     XOR        ESI,ESI
    //                               LAB_0053cdb8                                                 XREF[1]:     0053cdb4(j)  
    //                              visible.cpp:938 (9)
    //         0053cdb8     CMP        dword ptr [EBP + param_4],this
    //         0053cdbb     JL         LAB_0053cdc1
    //         0053cdbd     DEC        this
    //         0053cdbe     MOV        dword ptr [EBP + param_4],this
    //                               LAB_0053cdc1                                                 XREF[1]:     0053cdbb(j)  
    //                              visible.cpp:940 (17)
    //         0053cdc1     MOV        EAX,dword ptr [EBP + param_4]
    //         0053cdc4     MOV        dword ptr [EBP + param_2],ESI
    //         0053cdc7     CMP        ESI,EAX
    //         0053cdc9     JG         LAB_0053ce64
    //                               LAB_0053cdcf                                                 XREF[1]:     0053ce5e(j)  
    //         0053cdcf     MOV        this,dword ptr [EBP + param_2]
    //                              visible.cpp:943 (12)
    //         0053cdd2     MOV        EDX,dword ptr [EBX]
    //         0053cdd4     MOV        EAX,dword ptr [EDX + this->map_offsets*0x4]
    //         0053cdd7     LEA        ESI,[this->map_offsets*0x4 + 0x0]
    //                              visible.cpp:944 (17)
    //         0053cdde     LEA        this,[EDI*0x4 + 0x0]
    //         0053cde5     ADD        EAX,EDI
    //         0053cde7     MOV        EDX,dword ptr [ESI + unified_map_offsets]        = 00000000
    //         0053cded     ADD        EDX,this
    //                              visible.cpp:946 (31)
    //         0053cdef     MOV        this,dword ptr [EBP + param_5]
    //         0053cdf2     TEST       this,this
    //         0053cdf4     JZ         LAB_0053ce0e
    //         0053cdf6     MOV        this,dword ptr [EBX + 0xc]
    //         0053cdf9     LEA        EBX,[EDI + EDI*0x2]
    //         0053cdfc     MOV        this,dword ptr [this->map_offsets + 0x8d8c]
    //         0053ce02     MOV        this,dword ptr [this->map_offsets + ESI*0x1]
    //         0053ce05     LEA        this,[this->map_offsets + EBX*0x8]
    //         0053ce08     MOV        EBX,dword ptr [EBP + local_c]
    //         0053ce0b     MOV        dword ptr [EBP + tile],this
    //                               LAB_0053ce0e                                                 XREF[1]:     0053cdf4(j)  
    //                              visible.cpp:948 (10)
    //         0053ce0e     MOV        ESI,dword ptr [EBP + param_3]
    //         0053ce11     CMP        EDI,ESI
    //         0053ce13     JG         LAB_0053ce52
    //         0053ce15     SUB        ESI,EDI
    //         0053ce17     INC        ESI
    //                               LAB_0053ce18                                                 XREF[1]:     0053ce50(j)  
    //                              visible.cpp:951 (4)
    //         0053ce18     MOV        this,byte ptr [EAX]
    //         0053ce1a     DEC        this
    //                              visible.cpp:953 (7)
    //         0053ce1c     CMP        this,0xff
    //         0053ce1f     JNZ        LAB_0053ce23
    //         0053ce21     XOR        this,this
    //                               LAB_0053ce23                                                 XREF[1]:     0053ce1f(j)  
    //                              visible.cpp:957 (4)
    //         0053ce23     TEST       this,this
    //         0053ce25     JNZ        LAB_0053ce40
    //                              visible.cpp:959 (14)
    //         0053ce27     MOV        EBX,dword ptr [EBP + param_5]
    //         0053ce2a     TEST       EBX,EBX
    //         0053ce2c     JZ         LAB_0053ce35
    //         0053ce2e     MOV        EBX,dword ptr [EBP + tile]
    //         0053ce31     MOV        byte ptr [EBX + 0x9],0x80
    //                               LAB_0053ce35                                                 XREF[1]:     0053ce2c(j)  
    //                              visible.cpp:960 (11)
    //         0053ce35     MOV        EBX,dword ptr [EBP + local_c]
    //         0053ce38     MOV        EBX,dword ptr [EBX + 0x28]
    //         0053ce3b     AND        dword ptr [EDX],EBX
    //         0053ce3d     MOV        EBX,dword ptr [EBP + local_c]
    //                               LAB_0053ce40                                                 XREF[1]:     0053ce25(j)  
    //                              visible.cpp:964 (2)
    //         0053ce40     MOV        byte ptr [EAX],this
    //                              visible.cpp:969 (16)
    //         0053ce42     MOV        this,dword ptr [EBP + tile]
    //         0053ce45     INC        EAX
    //         0053ce46     ADD        EDX,0x4
    //         0053ce49     ADD        this,0x18
    //         0053ce4c     DEC        ESI
    //         0053ce4d     MOV        dword ptr [EBP + tile],this
    //         0053ce50     JNZ        LAB_0053ce18
    //                               LAB_0053ce52                                                 XREF[1]:     0053ce13(j)  
    //                              visible.cpp:940 (18)
    //         0053ce52     MOV        EAX,dword ptr [EBP + param_2]
    //         0053ce55     MOV        this,dword ptr [EBP + param_4]
    //         0053ce58     INC        EAX
    //         0053ce59     CMP        EAX,this
    //         0053ce5b     MOV        dword ptr [EBP + param_2],EAX
    //         0053ce5e     JLE        LAB_0053cdcf
    //                               LAB_0053ce64                                                 XREF[6]:     0053cd3f(j), 0053cd7c(j), 
    //                                                                                                         0053cd87(j), 0053cd92(j), 
    //                                                                                                         0053cd9d(j), 0053cdc9(j)  
    //                              visible.cpp:975 (9)
    //         0053ce64     POP        EDI
    //         0053ce65     POP        ESI
    //         0053ce66     POP        EBX
    //         0053ce67     MOV        ESP,EBP
    //         0053ce69     POP        EBP
    //         0053ce6a     RET        0x18
}

// Offset: 0x0053CE70
ulong checksum_visible_inputs(RGE_Visible_Map* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned long __thiscall RGE_Visible_Map::checksum_visible_inputs(void)                       *
    //                              *********************************************************************************************************
    //                              ulong __thiscall checksum_visible_inputs(RGE_Visible_Map * this)
    //              ulong             EAX:4          <RETURN>
    //              RGE_Visible_Ma    ECX:4 (auto)   this
    //                               ?checksum_visible_inputs@RGE_Visible_Map@@QAEKXZ
    //                               RGE_Visible_Map::checksum_visible_inputs
    //                              visible.cpp:983 (3)
    //         0053ce70     MOV        EAX,dword ptr [ECX + this->input_csum]
    //                              visible.cpp:987 (7)
    //         0053ce73     MOV        dword ptr [ECX + this->input_csum],0x0
    //                              visible.cpp:990 (1)
    //         0053ce7a     RET
}

// Offset: 0x0053CE80
undefined RGE_Unified_Visible_Map(RGE_Unified_Visible_Map* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Unified_Visible_Map::RGE_Unified_Visible_Map(int,int)                          *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Unified_Visible_Map(RGE_Unified_Visible_Map
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Unified_Vi    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0053ce80(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0053ce89(R)  
    //                               ??0RGE_Unified_Visible_Map@@QAE@HH@Z                         XREF[1]:     new_map:00455ba5(c)  
    //                               RGE_Unified_Visible_Map::RGE_Unified_Visible_Map
    //                              visible.cpp:1005 (7)
    //         0053ce80     MOV        EAX,dword ptr [ESP + param_1]
    //         0053ce84     PUSH       ESI
    //         0053ce85     MOV        ESI,this
    //                              visible.cpp:1011 (17)
    //         0053ce87     XOR        EDX,EDX
    //         0053ce89     MOV        this,dword ptr [ESP + param_2]
    //         0053ce8d     MOV        dword ptr [ESI],EAX
    //         0053ce8f     MOV        dword ptr [ESI + 0x4],this
    //         0053ce92     MOV        dword ptr [Map_Update_Suppresion],EDX
    //                              visible.cpp:1013 (13)
    //         0053ce98     MOV        this,dword ptr [ESI + 0x4]
    //         0053ce9b     CMP        this,EDX
    //         0053ce9d     JLE        LAB_0053cec3
    //         0053ce9f     MOV        EAX,dword ptr [ESI]
    //         0053cea1     CMP        EAX,EDX
    //         0053cea3     JLE        LAB_0053cec3
    //                              visible.cpp:1015 (14)
    //         0053cea5     IMUL       EAX,this
    //         0053cea8     PUSH       0x4
    //         0053ceaa     PUSH       EAX
    //         0053ceab     CALL       calloc                                           undefined calloc()
    //         0053ceb0     ADD        ESP,0x8
    //                              visible.cpp:1024 (10)
    //         0053ceb3     MOV        this,ESI
    //         0053ceb5     MOV        dword ptr [ESI + 0x8],EAX
    //         0053ceb8     CALL       RGE_Unified_Visible_Map::Set_Map_Offsets         void Set_Map_Offsets(RGE_Unified_Visible_Map 
    //                              visible.cpp:1026 (6)
    //         0053cebd     MOV        EAX,ESI
    //         0053cebf     POP        ESI
    //         0053cec0     RET        0x8
    //                               LAB_0053cec3                                                 XREF[2]:     0053ce9d(j), 0053cea3(j)  
    //                              visible.cpp:1024 (15)
    //         0053cec3     MOV        this,ESI
    //         0053cec5     MOV        dword ptr [ESI + 0x8],EDX
    //         0053cec8     MOV        dword ptr [ESI],EDX
    //         0053ceca     MOV        dword ptr [ESI + 0x4],EDX
    //         0053cecd     CALL       RGE_Unified_Visible_Map::Set_Map_Offsets         void Set_Map_Offsets(RGE_Unified_Visible_Map 
    //                              visible.cpp:1026 (6)
    //         0053ced2     MOV        EAX,ESI
    //         0053ced4     POP        ESI
    //         0053ced5     RET        0x8
}

// Offset: 0x0053CEE0
undefined RGE_Unified_Visible_Map(RGE_Unified_Visible_Map* this_, int param_2, RGE_Game_World* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Unified_Visible_Map::RGE_Unified_Visible_Map(int,class RGE_Game_World *)       *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Unified_Visible_Map(RGE_Unified_Visible_Map
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Unified_Vi    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0053cef2(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2
    //                               ??0RGE_Unified_Visible_Map@@QAE@HPAVRGE_Game_World@@@Z
    //                               RGE_Unified_Visible_Map::RGE_Unified_Visible_Map
    //                              visible.cpp:1032 (3)
    //         0053cee0     PUSH       ESI
    //         0053cee1     MOV        ESI,this
    //                              visible.cpp:1034 (5)
    //         0053cee3     XOR        EAX,EAX
    //         0053cee5     MOV        dword ptr [ESI + 0x8],EAX
    //                              visible.cpp:1035 (2)
    //         0053cee8     MOV        dword ptr [ESI],EAX
    //                              visible.cpp:1036 (3)
    //         0053ceea     MOV        dword ptr [ESI + 0x4],EAX
    //                              visible.cpp:1037 (5)
    //         0053ceed     MOV        [Map_Update_Suppresion],EAX
    //                              visible.cpp:1039 (10)
    //         0053cef2     MOV        EAX,dword ptr [ESP + param_1]
    //         0053cef6     PUSH       EAX
    //         0053cef7     CALL       RGE_Unified_Visible_Map::load                    void load(RGE_Unified_Visible_Map * this, int
    //                              visible.cpp:1041 (7)
    //         0053cefc     MOV        this,ESI
    //         0053cefe     CALL       RGE_Unified_Visible_Map::Set_Map_Offsets         void Set_Map_Offsets(RGE_Unified_Visible_Map 
    //                              visible.cpp:1042 (6)
    //         0053cf03     MOV        EAX,ESI
    //         0053cf05     POP        ESI
    //         0053cf06     RET        0x8
}

// Offset: 0x0053CF10
void load(RGE_Unified_Visible_Map* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Unified_Visible_Map::load(int)                                            *
    //                              *********************************************************************************************************
    //                              void __thiscall load(RGE_Unified_Visible_Map * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Unified_Vi    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0053cf12(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0053cf27(W), 0053cf4f(R)  
    //              int               Stack[-0x8]:4  oh
    //                               ?load@RGE_Unified_Visible_Map@@QAEXH@Z                       XREF[2]:     load_map:00457c29(c), 
    //                               RGE_Unified_Visible_Map::load                                             RGE_Unified_Visible_Map:0053cef7(c
    //                              visible.cpp:1046 (2)
    //         0053cf10     PUSH       this
    //         0053cf11     PUSH       EBX
    //                              visible.cpp:1053 (33)
    //         0053cf12     MOV        EBX,dword ptr [ESP + param_1]
    //         0053cf16     PUSH       EBP
    //         0053cf17     PUSH       ESI
    //         0053cf18     MOV        ESI,this
    //         0053cf1a     PUSH       EDI
    //         0053cf1b     PUSH       0x4
    //         0053cf1d     PUSH       ESI
    //         0053cf1e     MOV        EAX,dword ptr [ESI + 0x4]
    //         0053cf21     MOV        EBP,dword ptr [ESI]
    //         0053cf23     LEA        EDI,[ESI + 0x4]
    //         0053cf26     PUSH       EBX
    //         0053cf27     MOV        dword ptr [ESP + local_4],EAX
    //         0053cf2b     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0053cf30     ADD        ESP,0xc
    //                              visible.cpp:1054 (9)
    //         0053cf33     PUSH       0x4
    //         0053cf35     PUSH       EDI
    //         0053cf36     PUSH       EBX
    //         0053cf37     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              visible.cpp:1057 (15)
    //         0053cf3c     MOV        EAX,dword ptr [EDI]
    //         0053cf3e     ADD        ESP,0xc
    //         0053cf41     TEST       EAX,EAX
    //         0053cf43     JLE        LAB_0053cf96
    //         0053cf45     MOV        this,dword ptr [ESI]
    //         0053cf47     TEST       this,this
    //         0053cf49     JLE        LAB_0053cf96
    //                              visible.cpp:1059 (10)
    //         0053cf4b     CMP        EBP,this
    //         0053cf4d     JNZ        LAB_0053cf55
    //         0053cf4f     CMP        dword ptr [ESP + local_4],EAX
    //         0053cf53     JZ         LAB_0053cf78
    //                               LAB_0053cf55                                                 XREF[1]:     0053cf4d(j)  
    //                              visible.cpp:1061 (16)
    //         0053cf55     MOV        EAX,dword ptr [ESI + 0x8]
    //         0053cf58     TEST       EAX,EAX
    //         0053cf5a     JZ         LAB_0053cf65
    //         0053cf5c     PUSH       EAX
    //         0053cf5d     CALL       free                                             undefined free()
    //         0053cf62     ADD        ESP,0x4
    //                               LAB_0053cf65                                                 XREF[1]:     0053cf5a(j)  
    //                              visible.cpp:1062 (19)
    //         0053cf65     MOV        this,dword ptr [ESI]
    //         0053cf67     PUSH       0x4
    //         0053cf69     IMUL       this,dword ptr [EDI]
    //         0053cf6c     PUSH       this
    //         0053cf6d     CALL       calloc                                           undefined calloc()
    //         0053cf72     ADD        ESP,0x8
    //         0053cf75     MOV        dword ptr [ESI + 0x8],EAX
    //                               LAB_0053cf78                                                 XREF[1]:     0053cf53(j)  
    //                              visible.cpp:1065 (22)
    //         0053cf78     MOV        EDX,dword ptr [ESI]
    //         0053cf7a     MOV        EAX,dword ptr [ESI + 0x8]
    //         0053cf7d     IMUL       EDX,dword ptr [EDI]
    //         0053cf80     SHL        EDX,0x2
    //         0053cf83     PUSH       EDX
    //         0053cf84     PUSH       EAX
    //         0053cf85     PUSH       EBX
    //         0053cf86     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0053cf8b     ADD        ESP,0xc
    //                              visible.cpp:1074 (8)
    //         0053cf8e     POP        EDI
    //         0053cf8f     POP        ESI
    //         0053cf90     POP        EBP
    //         0053cf91     POP        EBX
    //         0053cf92     POP        this
    //         0053cf93     RET        0x4
    //                               LAB_0053cf96                                                 XREF[2]:     0053cf43(j), 0053cf49(j)  
    //                              visible.cpp:1070 (13)
    //         0053cf96     MOV        dword ptr [EDI],0x0
    //         0053cf9c     MOV        dword ptr [ESI + 0x8],0x0
    //                              visible.cpp:1071 (6)
    //         0053cfa3     MOV        dword ptr [ESI],0x0
    //                              visible.cpp:1074 (8)
    //         0053cfa9     POP        EDI
    //         0053cfaa     POP        ESI
    //         0053cfab     POP        EBP
    //         0053cfac     POP        EBX
    //         0053cfad     POP        this
    //         0053cfae     RET        0x4
}

// Offset: 0x0053CFC0
void RGE_Unified_Visible_Map(RGE_Unified_Visible_Map* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Unified_Visible_Map::~RGE_Unified_Visible_Map(void)                            *
    //                              *********************************************************************************************************
    //                              void __thiscall ~RGE_Unified_Visible_Map(RGE_Unified_Visible_Map * t
    //              void              <VOID>         <RETURN>
    //              RGE_Unified_Vi    ECX:4 (auto)   this
    //                               ??1RGE_Unified_Visible_Map@@QAE@XZ                           XREF[2]:     ~RGE_Map:00455534(c), 
    //                               RGE_Unified_Visible_Map::~RGE_Unified_Visible_Map                         new_map:00455b71(c)  
    //                              visible.cpp:1079 (3)
    //         0053cfc0     PUSH       ESI
    //         0053cfc1     MOV        ESI,this
    //                              visible.cpp:1080 (7)
    //         0053cfc3     MOV        dword ptr [ESI + 0x4],0x0
    //                              visible.cpp:1081 (5)
    //         0053cfca     CALL       RGE_Unified_Visible_Map::Set_Map_Offsets         void Set_Map_Offsets(RGE_Unified_Visible_Map 
    //                              visible.cpp:1083 (16)
    //         0053cfcf     MOV        ESI,dword ptr [ESI + 0x8]
    //         0053cfd2     TEST       ESI,ESI
    //         0053cfd4     JZ         LAB_0053cfdf
    //         0053cfd6     PUSH       ESI
    //         0053cfd7     CALL       free                                             undefined free()
    //         0053cfdc     ADD        ESP,0x4
    //                               LAB_0053cfdf                                                 XREF[1]:     0053cfd4(j)  
    //                              visible.cpp:1084 (2)
    //         0053cfdf     POP        ESI
    //         0053cfe0     RET
}

// Offset: 0x0053CFF0
void save(RGE_Unified_Visible_Map* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Unified_Visible_Map::save(int)                                            *
    //                              *********************************************************************************************************
    //                              void __thiscall save(RGE_Unified_Visible_Map * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Unified_Vi    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0053cff1(R)  
    //                               ?save@RGE_Unified_Visible_Map@@QAEXH@Z                       XREF[1]:     save_map:00457dd4(c)  
    //                               RGE_Unified_Visible_Map::save
    //                              visible.cpp:1088 (1)
    //         0053cff0     PUSH       EBX
    //                              visible.cpp:1089 (20)
    //         0053cff1     MOV        EBX,dword ptr [ESP + param_1]
    //         0053cff5     PUSH       ESI
    //         0053cff6     PUSH       EDI
    //         0053cff7     MOV        ESI,this
    //         0053cff9     PUSH       0x4
    //         0053cffb     PUSH       ESI
    //         0053cffc     PUSH       EBX
    //         0053cffd     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0053d002     ADD        ESP,0xc
    //                              visible.cpp:1090 (12)
    //         0053d005     LEA        EDI,[ESI + 0x4]
    //         0053d008     PUSH       0x4
    //         0053d00a     PUSH       EDI
    //         0053d00b     PUSH       EBX
    //         0053d00c     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              visible.cpp:1092 (15)
    //         0053d011     MOV        EDI,dword ptr [EDI]
    //         0053d013     ADD        ESP,0xc
    //         0053d016     TEST       EDI,EDI
    //         0053d018     JLE        LAB_0053d034
    //         0053d01a     MOV        EAX,dword ptr [ESI]
    //         0053d01c     TEST       EAX,EAX
    //         0053d01e     JLE        LAB_0053d034
    //                              visible.cpp:1093 (20)
    //         0053d020     IMUL       EAX,EDI
    //         0053d023     SHL        EAX,0x2
    //         0053d026     PUSH       EAX
    //         0053d027     MOV        EAX,dword ptr [ESI + 0x8]
    //         0053d02a     PUSH       EAX
    //         0053d02b     PUSH       EBX
    //         0053d02c     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0053d031     ADD        ESP,0xc
    //                               LAB_0053d034                                                 XREF[2]:     0053d018(j), 0053d01e(j)  
    //                              visible.cpp:1095 (6)
    //         0053d034     POP        EDI
    //         0053d035     POP        ESI
    //         0053d036     POP        EBX
    //         0053d037     RET        0x4
}

// Offset: 0x0053D040
void reset(RGE_Unified_Visible_Map* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Unified_Visible_Map::reset(void)                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall reset(RGE_Unified_Visible_Map * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Unified_Vi    ECX:4 (auto)   this
    //                               ?reset@RGE_Unified_Visible_Map@@QAEXXZ
    //                               RGE_Unified_Visible_Map::reset
    //                              visible.cpp:1099 (3)
    //         0053d040     MOV        EAX,this
    //         0053d042     PUSH       EDI
    //                              visible.cpp:1101 (7)
    //         0053d043     MOV        EDI,dword ptr [EAX + 0x8]
    //         0053d046     TEST       EDI,EDI
    //         0053d048     JZ         LAB_0053d063
    //                              visible.cpp:1103 (25)
    //         0053d04a     MOV        this,dword ptr [EAX + 0x4]
    //         0053d04d     IMUL       this,dword ptr [EAX]
    //         0053d050     SHL        this,0x2
    //         0053d053     MOV        EDX,this
    //         0053d055     XOR        EAX,EAX
    //         0053d057     SHR        this,0x2
    //         0053d05a     STOSD.REP  ES:EDI
    //         0053d05c     MOV        this,EDX
    //         0053d05e     AND        this,0x3
    //         0053d061     STOSB.REP  ES:EDI
    //                               LAB_0053d063                                                 XREF[1]:     0053d048(j)  
    //                              visible.cpp:1106 (2)
    //         0053d063     POP        EDI
    //         0053d064     RET
}

// Offset: 0x0053D070
void Set_Map_Offsets(RGE_Unified_Visible_Map* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * private: void __thiscall RGE_Unified_Visible_Map::Set_Map_Offsets(void)                               *
    //                              *********************************************************************************************************
    //                              void __thiscall Set_Map_Offsets(RGE_Unified_Visible_Map * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Unified_Vi    ECX:4 (auto)   this
    //                               ?Set_Map_Offsets@RGE_Unified_Visible_Map@@AAEXXZ             XREF[4]:     RGE_Unified_Visible_Map:0053ceb8(c
    //                               RGE_Unified_Visible_Map::Set_Map_Offsets                                  RGE_Unified_Visible_Map:0053cecd(c
    //                                                                                                         RGE_Unified_Visible_Map:0053cefe(c
    //                                                                                                         ~RGE_Unified_Visible_Map:0053cfca(
    //                              visible.cpp:1111 (16)
    //         0053d070     MOV        EDX,dword ptr [ECX + this->mapHeight]
    //         0053d073     XOR        EAX,EAX
    //         0053d075     PUSH       ESI
    //         0053d076     PUSH       EDI
    //         0053d077     TEST       EDX,EDX
    //         0053d079     JLE        LAB_0053d099
    //         0053d07b     MOV        EDX,unified_map_offsets                          = 00000000
    //                               LAB_0053d080                                                 XREF[1]:     0053d097(j)  
    //                              visible.cpp:1115 (25)
    //         0053d080     MOV        ESI,dword ptr [this->mapWidth]
    //         0053d082     MOV        EDI,dword ptr [ECX + this->UnifiedVisibleMap]
    //         0053d085     IMUL       ESI,EAX
    //         0053d088     INC        EAX
    //         0053d089     ADD        EDX,0x4
    //         0053d08c     LEA        ESI,[EDI + ESI*0x4]
    //         0053d08f     MOV        dword ptr [EDX + -0x4]=>unified_map_offsets,ESI  = 00000000
    //         0053d092     MOV        ESI,dword ptr [ECX + this->mapHeight]
    //         0053d095     CMP        EAX,ESI
    //         0053d097     JL         LAB_0053d080
    //                               LAB_0053d099                                                 XREF[1]:     0053d079(j)  
    //                              visible.cpp:1117 (28)
    //         0053d099     MOV        EAX,dword ptr [ECX + this->mapHeight]
    //         0053d09c     CMP        EAX,0x100
    //         0053d0a1     JGE        LAB_0053d0b5
    //         0053d0a3     MOV        this,0x100
    //         0053d0a8     LEA        EDI,[EAX*0x4 + unified_map_offsets]              = 00000000
    //         0053d0af     SUB        this,EAX
    //         0053d0b1     XOR        EAX,EAX
    //         0053d0b3     STOSD.REP  ES:EDI=>unified_map_offsets                      = 00000000
    //                               LAB_0053d0b5                                                 XREF[1]:     0053d0a1(j)  
    //                              visible.cpp:1119 (3)
    //         0053d0b5     POP        EDI
    //         0053d0b6     POP        ESI
    //         0053d0b7     RET
}

// Offset: 0x0053D0C0
void suppress_updates(RGE_Unified_Visible_Map* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Unified_Visible_Map::suppress_updates(int)                                *
    //                              *********************************************************************************************************
    //                              void __thiscall suppress_updates(RGE_Unified_Visible_Map * this, int
    //              void              <VOID>         <RETURN>
    //              RGE_Unified_Vi    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0053d0c0(R)  
    //                               ?suppress_updates@RGE_Unified_Visible_Map@@QAEXH@Z           XREF[2]:     load_world:005422b9(c), 
    //                               RGE_Unified_Visible_Map::suppress_updates                                 load_world:005422e4(c)  
    //                              visible.cpp:1123 (9)
    //         0053d0c0     MOV        EAX,dword ptr [ESP + param_1]
    //         0053d0c4     MOV        [Map_Update_Suppresion],EAX
    //                              visible.cpp:1125 (3)
    //         0053d0c9     RET        0x4
}

// Offset: 0x0053D0D0
long checksumVisible(RGE_Visible_Map* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall RGE_Visible_Map::checksumVisible(void)                                        *
    //                              *********************************************************************************************************
    //                              long __thiscall checksumVisible(RGE_Visible_Map * this)
    //              long              EAX:4          <RETURN>
    //              RGE_Visible_Ma    ECX:4 (auto)   this
    //                               ?checksumVisible@RGE_Visible_Map@@QAEJXZ                     XREF[1]:     DoChecksum:00433392(c)  
    //                               RGE_Visible_Map::checksumVisible
    //                              visible.cpp:1132 (13)
    //         0053d0d0     MOV        EDX,dword ptr [ECX + this->heightValue]
    //         0053d0d3     PUSH       EBP
    //         0053d0d4     XOR        EAX,EAX
    //         0053d0d6     XOR        EBP,EBP
    //         0053d0d8     TEST       EDX,EDX
    //         0053d0da     JLE        LAB_0053d104
    //         0053d0dc     PUSH       EDI
    //                              visible.cpp:1136 (16)
    //         0053d0dd     MOV        EDI,dword ptr [ECX + this->widthValue]
    //         0053d0e0     PUSH       ESI
    //         0053d0e1     PUSH       EBX
    //                               LAB_0053d0e2                                                 XREF[1]:     0053d0ff(j)  
    //         0053d0e2     XOR        EDX,EDX
    //         0053d0e4     TEST       EDI,EDI
    //         0053d0e6     JLE        LAB_0053d0f9
    //         0053d0e8     MOV        ESI,dword ptr [this->map_offsets]
    //         0053d0ea     MOV        ESI,dword ptr [ESI + EBP*0x4]
    //                               LAB_0053d0ed                                                 XREF[1]:     0053d0f7(j)  
    //                              visible.cpp:1137 (12)
    //         0053d0ed     XOR        EBX,EBX
    //         0053d0ef     MOV        BL,byte ptr [EDX + ESI*0x1]
    //         0053d0f2     XOR        EAX,EBX
    //         0053d0f4     INC        EDX
    //         0053d0f5     CMP        EDX,EDI
    //         0053d0f7     JL         LAB_0053d0ed
    //                               LAB_0053d0f9                                                 XREF[1]:     0053d0e6(j)  
    //                              visible.cpp:1135 (11)
    //         0053d0f9     MOV        EDX,dword ptr [ECX + this->heightValue]
    //         0053d0fc     INC        EBP
    //         0053d0fd     CMP        EBP,EDX
    //         0053d0ff     JL         LAB_0053d0e2
    //         0053d101     POP        EBX
    //         0053d102     POP        ESI
    //         0053d103     POP        EDI
    //                               LAB_0053d104                                                 XREF[1]:     0053d0da(j)  
    //                              visible.cpp:1140 (2)
    //         0053d104     POP        EBP
    //         0053d105     RET
}

// Offset: 0x0053D110
ulong checksumUnifiedVisible(RGE_Visible_Map* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned long __thiscall RGE_Visible_Map::checksumUnifiedVisible(void)                        *
    //                              *********************************************************************************************************
    //                              ulong __thiscall checksumUnifiedVisible(RGE_Visible_Map * this)
    //              ulong             EAX:4          <RETURN>
    //              RGE_Visible_Ma    ECX:4 (auto)   this
    //                               ?checksumUnifiedVisible@RGE_Visible_Map@@QAEKXZ              XREF[1]:     DoChecksum:00433368(c)  
    //                               RGE_Visible_Map::checksumUnifiedVisible
    //                              visible.cpp:1146 (10)
    //         0053d110     MOV        EDX,dword ptr [ECX + this->heightValue]
    //         0053d113     XOR        EAX,EAX
    //         0053d115     TEST       EDX,EDX
    //         0053d117     JLE        LAB_0053d143
    //         0053d119     PUSH       EDI
    //                              visible.cpp:1150 (21)
    //         0053d11a     MOV        EDI,dword ptr [ECX + this->widthValue]
    //         0053d11d     PUSH       ESI
    //         0053d11e     PUSH       EBP
    //         0053d11f     PUSH       EBX
    //         0053d120     MOV        ESI,unified_map_offsets                          = 00000000
    //         0053d125     MOV        EBX,EDX
    //                               LAB_0053d127                                                 XREF[1]:     0053d13d(j)  
    //         0053d127     TEST       EDI,EDI
    //         0053d129     JLE        LAB_0053d139
    //         0053d12b     MOV        this,dword ptr [ESI]=>unified_map_offsets        = 00000000
    //         0053d12d     MOV        EDX,EDI
    //                               LAB_0053d12f                                                 XREF[1]:     0053d137(j)  
    //                              visible.cpp:1151 (10)
    //         0053d12f     MOV        EBP,dword ptr [this->map_offsets]
    //         0053d131     ADD        this,0x4
    //         0053d134     XOR        EAX,EBP
    //         0053d136     DEC        EDX
    //         0053d137     JNZ        LAB_0053d12f
    //                               LAB_0053d139                                                 XREF[1]:     0053d129(j)  
    //                              visible.cpp:1149 (10)
    //         0053d139     ADD        ESI,0x4
    //         0053d13c     DEC        EBX
    //         0053d13d     JNZ        LAB_0053d127
    //         0053d13f     POP        EBX
    //         0053d140     POP        EBP
    //         0053d141     POP        ESI
    //         0053d142     POP        EDI
    //                               LAB_0053d143                                                 XREF[1]:     0053d117(j)  
    //                              visible.cpp:1154 (1)
    //         0053d143     RET
}

// Offset: 0x0053D150
void log_map_call(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8, int param_9) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * void __cdecl log_map_call(int,int,int,int,int,int,int,int,int)                                        *
    //                              *********************************************************************************************************
    //                              void __cdecl log_map_call(int param_1, int param_2, int param_3, int
    //              void              <VOID>         <RETURN>
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0053d190(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0053d194(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0053d1a9(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0053d1b3(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     0053d1bd(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[1]:     0053d1c7(R)  
    //              int               Stack[0x1c]:4  param_7                   XREF[1]:     0053d1d1(R)  
    //              int               Stack[0x20]:4  param_8                   XREF[1]:     0053d1db(R)  
    //              int               Stack[0x24]:4  param_9                   XREF[1]:     0053d1e5(R)  
    //                               ?log_map_call@@YAXHHHHHHHHH@Z                                XREF[6]:     set_all:0053c4fd(c), 
    //                               log_map_call                                                              explore_all:0053c5f1(c), 
    //                                                                                                         explore_terrain:0053c72d(c), 
    //                                                                                                         unexplore_terrain:0053c960(c), 
    //                                                                                                         explore_terrain_sq:0053cafd(c), 
    //                                                                                                         unexplore_terrain_sq:0053cd30(c)  
    //                              visible.cpp:1162 (6)
    //         0053d150     MOV        EAX,[VCALL_LOG_HEAD]                             = FFFFFFFFh
    //         0053d155     INC        EAX
    //                              visible.cpp:1170 (7)
    //         0053d156     CMP        EAX,0x400
    //         0053d15b     JL         LAB_0053d16b
    //                              visible.cpp:1172 (2)
    //         0053d15d     XOR        EAX,EAX
    //                              visible.cpp:1173 (10)
    //         0053d15f     MOV        dword ptr [VCALL_LOG_TAIL],0x1                   = FFFFFFFFh
    //                              visible.cpp:1175 (2)
    //         0053d169     JMP        LAB_0053d190
    //                               LAB_0053d16b                                                 XREF[1]:     0053d15b(j)  
    //                              visible.cpp:1177 (10)
    //         0053d16b     MOV        ECX,dword ptr [VCALL_LOG_TAIL]                   = FFFFFFFFh
    //         0053d171     TEST       ECX,ECX
    //         0053d173     JL         LAB_0053d190
    //                              visible.cpp:1179 (3)
    //         0053d175     LEA        ECX,[EAX + 0x1]
    //                              visible.cpp:1180 (14)
    //         0053d178     CMP        ECX,0x400
    //         0053d17e     MOV        dword ptr [VCALL_LOG_TAIL],ECX                   = FFFFFFFFh
    //         0053d184     JL         LAB_0053d190
    //                              visible.cpp:1181 (10)
    //         0053d186     MOV        dword ptr [VCALL_LOG_TAIL],0x0                   = FFFFFFFFh
    //                               LAB_0053d190                                                 XREF[3]:     0053d169(j), 0053d173(j), 
    //                                                                                                         0053d184(j)  
    //                              visible.cpp:1186 (4)
    //         0053d190     MOV        ECX,dword ptr [ESP + param_1]
    //                              visible.cpp:1187 (21)
    //         0053d194     MOV        EDX,dword ptr [ESP + param_2]
    //         0053d198     MOV        [VCALL_LOG_HEAD],EAX                             = FFFFFFFFh
    //         0053d19d     LEA        EAX,[EAX + EAX*0x8]
    //         0053d1a0     SHL        EAX,0x2
    //         0053d1a3     MOV        dword ptr [EAX + VCALL_LOG],ECX                  = 00000000
    //                              visible.cpp:1188 (10)
    //         0053d1a9     MOV        ECX,dword ptr [ESP + param_3]
    //         0053d1ad     MOV        dword ptr [EAX + DAT_0087d80c],EDX
    //                              visible.cpp:1189 (10)
    //         0053d1b3     MOV        EDX,dword ptr [ESP + param_4]
    //         0053d1b7     MOV        dword ptr [EAX + DAT_0087d810],ECX
    //                              visible.cpp:1190 (10)
    //         0053d1bd     MOV        ECX,dword ptr [ESP + param_5]
    //         0053d1c1     MOV        dword ptr [EAX + DAT_0087d814],EDX
    //                              visible.cpp:1191 (10)
    //         0053d1c7     MOV        EDX,dword ptr [ESP + param_6]
    //         0053d1cb     MOV        dword ptr [EAX + DAT_0087d818],ECX
    //                              visible.cpp:1192 (10)
    //         0053d1d1     MOV        ECX,dword ptr [ESP + param_7]
    //         0053d1d5     MOV        dword ptr [EAX + DAT_0087d81c],EDX
    //                              visible.cpp:1193 (10)
    //         0053d1db     MOV        EDX,dword ptr [ESP + param_8]
    //         0053d1df     MOV        dword ptr [EAX + DAT_0087d820],ECX
    //                              visible.cpp:1194 (16)
    //         0053d1e5     MOV        ECX,dword ptr [ESP + param_9]
    //         0053d1e9     MOV        dword ptr [EAX + DAT_0087d824],EDX
    //         0053d1ef     MOV        dword ptr [EAX + DAT_0087d828],ECX
    //                              visible.cpp:1196 (1)
    //         0053d1f5     RET
}

// Offset: 0x0053D200
void dump_vismap_log() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * void __cdecl dump_vismap_log(void)                                                                    *
    //                              *********************************************************************************************************
    //                              void __cdecl dump_vismap_log(void)
    //              void              <VOID>         <RETURN>
    //                               ?dump_vismap_log@@YAXXZ                                      XREF[4]:     ~RGE_Base_Game:0041c29a(c), 
    //                               dump_vismap_log                                                           do_command_game:0050a2f4(c), 
    //                                                                                                         quit_game:005241af(c), 
    //                                                                                                         action_user_command:00529d07(c)  
    //                              visible.cpp:1199 (2)
    //         0053d200     PUSH       EBP
    //         0053d201     PUSH       EDI
    //                              visible.cpp:1205 (19)
    //         0053d202     PUSH       s_w                                              = "w"
    //         0053d207     PUSH       s_c:\aoeexlog.txt                                = "c:\\aoeexlog.txt"
    //         0053d20c     XOR        EBP,EBP
    //         0053d20e     CALL       fopen                                            undefined fopen()
    //         0053d213     MOV        EDI,EAX
    //                              visible.cpp:1207 (12)
    //         0053d215     MOV        EAX,[VCALL_LOG_HEAD]                             = FFFFFFFFh
    //         0053d21a     ADD        ESP,0x8
    //         0053d21d     TEST       EAX,EAX
    //         0053d21f     JGE        LAB_0053d23b
    //                              visible.cpp:1208 (14)
    //         0053d221     PUSH       s_NULL_LOG_                                      = "NULL LOG\n"
    //         0053d226     PUSH       EDI
    //         0053d227     CALL       fprintf                                          undefined fprintf()
    //         0053d22c     ADD        ESP,0x8
    //                              visible.cpp:1247 (9)
    //         0053d22f     PUSH       EDI
    //         0053d230     CALL       fclose                                           undefined fclose()
    //         0053d235     ADD        ESP,0x4
    //                              visible.cpp:1249 (3)
    //         0053d238     POP        EDI
    //         0053d239     POP        EBP
    //         0053d23a     RET
    //                               LAB_0053d23b                                                 XREF[1]:     0053d21f(j)  
    //                              visible.cpp:1199 (2)
    //         0053d23b     PUSH       ESI
    //         0053d23c     PUSH       EBX
    //                              visible.cpp:1211 (6)
    //         0053d23d     MOV        EBX,dword ptr [VCALL_LOG_TAIL]                   = FFFFFFFFh
    //                              visible.cpp:1212 (4)
    //         0053d243     TEST       EBX,EBX
    //         0053d245     JGE        LAB_0053d249
    //                              visible.cpp:1213 (2)
    //         0053d247     XOR        EBX,EBX
    //                               LAB_0053d249                                                 XREF[2]:     0053d245(j), 0053d334(j)  
    //                              visible.cpp:1217 (27)
    //         0053d249     LEA        ESI,[EBX + EBX*0x8]
    //         0053d24c     SHL        ESI,0x2
    //         0053d24f     MOV        EAX,dword ptr [ESI + DAT_0087d810]
    //         0053d255     LEA        ECX,[EAX + -0x1]
    //         0053d258     CMP        ECX,0x5
    //         0053d25b     JA         switchD_0053d25d::default
    //                               switchD_0053d25d::switchD
    //         0053d25d     JMP        dword ptr [ECX*0x4 + switchD_0053d25d::switchd   = 0053d264
    //                               switchD_0053d25d::caseD_1                                    XREF[2]:     0053d25d(j), 0053d348(*)  
    //                              visible.cpp:1219 (16)
    //         0053d264     PUSH       s_EXPLORE_____                                   = "EXPLORE     "
    //         0053d269     PUSH       EDI
    //         0053d26a     CALL       fprintf                                          undefined fprintf()
    //         0053d26f     ADD        ESP,0x8
    //         0053d272     JMP        LAB_0053d2d3
    //                               switchD_0053d25d::caseD_2                                    XREF[2]:     0053d25d(j), 0053d34c(*)  
    //                              visible.cpp:1220 (16)
    //         0053d274     PUSH       s_EXPLORE_SQ__                                   = "EXPLORE SQ  "
    //         0053d279     PUSH       EDI
    //         0053d27a     CALL       fprintf                                          undefined fprintf()
    //         0053d27f     ADD        ESP,0x8
    //         0053d282     JMP        LAB_0053d2d3
    //                               switchD_0053d25d::caseD_3                                    XREF[2]:     0053d25d(j), 0053d350(*)  
    //                              visible.cpp:1221 (16)
    //         0053d284     PUSH       s_UNEXPLORE___                                   = "UNEXPLORE   "
    //         0053d289     PUSH       EDI
    //         0053d28a     CALL       fprintf                                          undefined fprintf()
    //         0053d28f     ADD        ESP,0x8
    //         0053d292     JMP        LAB_0053d2d3
    //                               switchD_0053d25d::caseD_4                                    XREF[2]:     0053d25d(j), 0053d354(*)  
    //                              visible.cpp:1222 (16)
    //         0053d294     PUSH       s_UNEXPLORE_SQ                                   = "UNEXPLORE SQ"
    //         0053d299     PUSH       EDI
    //         0053d29a     CALL       fprintf                                          undefined fprintf()
    //         0053d29f     ADD        ESP,0x8
    //         0053d2a2     JMP        LAB_0053d2d3
    //                               switchD_0053d25d::caseD_5                                    XREF[2]:     0053d25d(j), 0053d358(*)  
    //                              visible.cpp:1223 (16)
    //         0053d2a4     PUSH       s_SET_ALL_____                                   = "SET ALL     "
    //         0053d2a9     PUSH       EDI
    //         0053d2aa     CALL       fprintf                                          undefined fprintf()
    //         0053d2af     ADD        ESP,0x8
    //         0053d2b2     JMP        LAB_0053d2d3
    //                               switchD_0053d25d::caseD_6                                    XREF[2]:     0053d25d(j), 0053d35c(*)  
    //                              visible.cpp:1224 (16)
    //         0053d2b4     PUSH       s_EXPLORE_ALL_                                   = "EXPLORE ALL "
    //         0053d2b9     PUSH       EDI
    //         0053d2ba     CALL       fprintf                                          undefined fprintf()
    //         0053d2bf     ADD        ESP,0x8
    //         0053d2c2     JMP        LAB_0053d2d3
    //                               switchD_0053d25d::default                                    XREF[1]:     0053d25b(j)  
    //                              visible.cpp:1226 (15)
    //         0053d2c4     PUSH       EAX
    //         0053d2c5     PUSH       s_*ERROR*_Undef_Action_=_%d_                     = "*ERROR* Undef Action = %d "
    //         0053d2ca     PUSH       EDI
    //         0053d2cb     CALL       fprintf                                          undefined fprintf()
    //         0053d2d0     ADD        ESP,0xc
    //                               LAB_0053d2d3                                                 XREF[6]:     0053d272(j), 0053d282(j), 
    //                                                                                                         0053d292(j), 0053d2a2(j), 
    //                                                                                                         0053d2b2(j), 0053d2c2(j)  
    //                              visible.cpp:1237 (67)
    //         0053d2d3     MOV        EAX,dword ptr [ESI + DAT_0087d828]
    //         0053d2d9     MOV        ECX,dword ptr [ESI + DAT_0087d824]
    //         0053d2df     MOV        EDX,dword ptr [ESI + DAT_0087d820]
    //         0053d2e5     PUSH       EAX
    //         0053d2e6     MOV        EAX,dword ptr [ESI + DAT_0087d81c]
    //         0053d2ec     PUSH       ECX
    //         0053d2ed     MOV        ECX,dword ptr [ESI + DAT_0087d818]
    //         0053d2f3     PUSH       EDX
    //         0053d2f4     MOV        EDX,dword ptr [ESI + DAT_0087d814]
    //         0053d2fa     PUSH       EAX
    //         0053d2fb     MOV        EAX,dword ptr [ESI + DAT_0087d80c]
    //         0053d301     PUSH       ECX
    //         0053d302     MOV        ECX,dword ptr [ESI + VCALL_LOG]                  = 00000000
    //         0053d308     PUSH       EDX
    //         0053d309     PUSH       EAX
    //         0053d30a     PUSH       ECX
    //         0053d30b     PUSH       s__wt_=_%d,_plyr_=_%d,_id_=_%d,_x1               = " wt = %d, plyr = %d, id = %d, x1=%d, y1=%d
    //         0053d310     PUSH       EDI
    //         0053d311     CALL       fprintf                                          undefined fprintf()
    //                              visible.cpp:1241 (17)
    //         0053d316     MOV        EAX,[VCALL_LOG_HEAD]                             = FFFFFFFFh
    //         0053d31b     ADD        ESP,0x28
    //         0053d31e     CMP        EBX,EAX
    //         0053d320     JNZ        LAB_0053d327
    //         0053d322     MOV        EBP,0x1
    //                               LAB_0053d327                                                 XREF[1]:     0053d320(j)  
    //                              visible.cpp:1242 (1)
    //         0053d327     INC        EBX
    //                              visible.cpp:1243 (10)
    //         0053d328     CMP        EBX,0x400
    //         0053d32e     JL         LAB_0053d332
    //         0053d330     XOR        EBX,EBX
    //                               LAB_0053d332                                                 XREF[1]:     0053d32e(j)  
    //                              visible.cpp:1215 (10)
    //         0053d332     TEST       EBP,EBP
    //         0053d334     JZ         LAB_0053d249
    //         0053d33a     POP        EBX
    //         0053d33b     POP        ESI
    //                              visible.cpp:1247 (9)
    //         0053d33c     PUSH       EDI
    //         0053d33d     CALL       fclose                                           undefined fclose()
    //         0053d342     ADD        ESP,0x4
    //                              visible.cpp:1249 (27)
    //         0053d345     POP        EDI
    //         0053d346     POP        EBP
    //         0053d347     RET
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0053d25d::switchdataD_0053d348                       XREF[1]:     dump_vismap_log:0053d25d(*)  
}

