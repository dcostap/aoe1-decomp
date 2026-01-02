#include "../common.h"
#include "tvw_main.h"

void TRIBE_Main_View::draw_multi_object_outline() {
    /* TODO: Stub */
//                              void __thiscall draw_multi_object_outline(TRIBE_Main_View * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Main_Vie    ECX:4 (auto)   this
//              RGE_Pick_Info     Stack[-0x18]   pick_info                 XREF[1]:     0052cb6b(R)
//              tagPOINT          Stack[-0x20]:8 point                     XREF[0,2]:   0052cb61(*), 0052cb6f(R)
//              int               Stack[-0x24]:4 start_row                 XREF[2]:     0052cb41(*), 0052cbf4(R)
//              long              Stack[-0x28]:4 calc_row1                 XREF[1]:     0052cc03(W)
//              int               Stack[-0x2c]:4 main_col                  XREF[1]:     0052cc07(W)
//              int               Stack[-0x30]:4 main_row                  XREF[2]:     0052cb3c(*), 0052cbfc(R)
//              long              Stack[-0x34]:4 calc_col2
//              int               Stack[-0x38]:4 start_col                 XREF[2]:     0052cb46(*), 0052cbf8(R)
//              long              Stack[-0x3c]:4 calc_col1
//              int               Stack[-0x40]:4 end_row
//              int               Stack[-0x44]:4 end_col                   XREF[1]:     0052cb20(W)
//              TRIBE_Master_B    Stack[-0x48]:4 master_bldg               XREF[2]:     0052cb36(*), 0052cc0b(R)
//              long              Stack[-0x4c]:4 calc_row2
//                               ?draw_multi_object_outline@TRIBE_Main_View@@UAEXXZ           XREF[1]:     00572ba0(*)
//                               TRIBE_Main_View::draw_multi_object_outline
//                              tvw_main.cpp:39 (18)
//         0052caf0     MOV        EAX,[rge_base_game]                              = 00000000
//         0052caf5     SUB        ESP,0x48
//         0052caf8     MOV        AX,word ptr [EAX + 0x3fc]
//         0052caff     PUSH       EBX
//         0052cb00     PUSH       EBP
//         0052cb01     PUSH       ESI
//                              tvw_main.cpp:49 (13)
//         0052cb02     CMP        AX,0xffff
//         0052cb06     PUSH       EDI
//         0052cb07     MOV        EBP,this
//         0052cb09     JZ         LAB_0052d051
//                              tvw_main.cpp:51 (15)
//         0052cb0f     MOV        this,dword ptr [EBP + 0x100]
//         0052cb15     MOVSX      EDX,AX
//         0052cb18     MOV        EAX,dword ptr [ECX + this->field36_0x24]
//         0052cb1b     MOV        EAX,dword ptr [EAX + EDX*0x4]
//                              tvw_main.cpp:52 (12)
//         0052cb1e     TEST       EAX,EAX
//         0052cb20     MOV        dword ptr [ESP + end_col],EAX
//         0052cb24     JZ         LAB_0052d051
//                              tvw_main.cpp:55 (12)
//         0052cb2a     LEA        this,[EBP + 0x24]
//         0052cb2d     PUSH       this
//         0052cb2e     MOV        this,dword ptr [EBP + 0x20]
//         0052cb31     CALL       TDrawArea::SetClipRect                           void SetClipRect(TDrawArea * this, tagRECT *
//                              tvw_main.cpp:57 (37)
//         0052cb36     LEA        EDX=>master_bldg,[ESP + 0x10]
//         0052cb3a     PUSH       0x0
//         0052cb3c     LEA        EAX=>main_row,[ESP + 0x2c]
//         0052cb40     PUSH       EDX
//         0052cb41     LEA        this=>start_row,[ESP + 0x3c]
//         0052cb45     PUSH       EAX
//         0052cb46     LEA        EDX=>start_col,[ESP + 0x2c]
//         0052cb4a     PUSH       this
//         0052cb4b     PUSH       EDX
//         0052cb4c     MOV        this,EBP
//         0052cb4e     CALL       RGE_View::get_selection_area                     int get_selection_area(RGE_View * this, long
//         0052cb53     TEST       EAX,EAX
//         0052cb55     JNZ        LAB_0052cbf4
//                              tvw_main.cpp:59 (16)
//         0052cb5b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052cb61     LEA        EAX=>point.y,[ESP + 0x3c]
//         0052cb65     PUSH       EAX
//         0052cb66     CALL       RGE_Base_Game::get_mouse_pos                     void get_mouse_pos(RGE_Base_Game * this, tagP
//                              tvw_main.cpp:60 (29)
//         0052cb6b     MOV        EAX,dword ptr [ESP + pick_info.x]
//         0052cb6f     MOV        this,dword ptr [ESP + point.y]
//         0052cb73     MOV        EDX,dword ptr [EBP]
//         0052cb76     PUSH       EAX
//         0052cb77     PUSH       this
//         0052cb78     MOV        this,EBP
//         0052cb7a     CALL       dword ptr [EDX + 0xbc]
//         0052cb80     TEST       EAX,EAX
//         0052cb82     JZ         LAB_0052d051
//                              tvw_main.cpp:62 (54)
//         0052cb88     MOV        EAX,dword ptr [ESP + 0x40]
//         0052cb8c     MOV        this,dword ptr [ESP + 0x3c]
//         0052cb90     MOV        EBX,dword ptr [EBP + 0x8c]
//         0052cb96     PUSH       0x1
//         0052cb98     LEA        EDX,[ESP + 0x48]
//         0052cb9c     PUSH       0x0=>DAT_fffffff8
//         0052cb9e     PUSH       EDX=>DAT_fffffff4
//         0052cb9f     MOV        EDX,dword ptr [EBP + 0x90]
//         0052cba5     SUB        EAX,EDX
//         0052cba7     SUB        this,EBX
//         0052cba9     PUSH       EAX=>DAT_fffffff0
//         0052cbaa     PUSH       this
//         0052cbab     PUSH       0x0
//         0052cbad     PUSH       0x28
//         0052cbaf     MOV        this,EBP
//         0052cbb1     CALL       RGE_Main_View::pick1                             uchar pick1(RGE_Main_View * this, uchar param
//         0052cbb6     CMP        AL,0x33
//         0052cbb8     JNZ        LAB_0052d051
//                              tvw_main.cpp:64 (12)
//         0052cbbe     LEA        EDX,[ESP + 0x44]
//         0052cbc2     MOV        this,EBP
//         0052cbc4     PUSH       EDX
//         0052cbc5     CALL       RGE_Main_View::fixup_pick_info                   void fixup_pick_info(RGE_Main_View * this, RG
//                              tvw_main.cpp:65 (9)
//         0052cbca     FLD        float ptr [ESP + 0x44]
//         0052cbce     CALL       __ftol                                           undefined __ftol()
//                              tvw_main.cpp:66 (17)
//         0052cbd3     FLD        float ptr [ESP + 0x48]
//         0052cbd7     MOV        EBX,EAX
//         0052cbd9     MOV        dword ptr [ESP + 0x20],EBX
//         0052cbdd     CALL       __ftol                                           undefined __ftol()
//         0052cbe2     MOV        this,EAX
//                              tvw_main.cpp:67 (10)
//         0052cbe4     MOV        EDI,EBX
//         0052cbe6     MOV        dword ptr [ESP + 0x34],this
//         0052cbea     MOV        dword ptr [ESP + 0x28],EDI
//                              tvw_main.cpp:68 (18)
//         0052cbee     MOV        dword ptr [ESP + 0x10],this
//         0052cbf2     JMP        LAB_0052cc00
//                               LAB_0052cbf4                                                 XREF[1]:     0052cb55(j)
//         0052cbf4     MOV        this,dword ptr [ESP + start_row]
//         0052cbf8     MOV        EBX,dword ptr [ESP + start_col]
//         0052cbfc     MOV        EDI,dword ptr [ESP + main_row]
//                               LAB_0052cc00                                                 XREF[1]:     0052cbf2(j)
//                              tvw_main.cpp:71 (7)
//         0052cc00     OR         EAX,0xffffffff
//         0052cc03     MOV        dword ptr [ESP + calc_row1],EAX
//                              tvw_main.cpp:74 (4)
//         0052cc07     MOV        dword ptr [ESP + main_col],EAX
//                              tvw_main.cpp:77 (30)
//         0052cc0b     MOV        EAX,dword ptr [ESP + master_bldg]
//         0052cc0f     SUB        EAX,this
//         0052cc11     CDQ
//         0052cc12     MOV        ESI,EAX
//         0052cc14     MOV        EAX,EDI
//         0052cc16     XOR        ESI,EDX
//         0052cc18     SUB        EAX,EBX
//         0052cc1a     SUB        ESI,EDX
//         0052cc1c     CDQ
//         0052cc1d     XOR        EAX,EDX
//         0052cc1f     SUB        EAX,EDX
//         0052cc21     CMP        ESI,EAX
//         0052cc23     JNZ        LAB_0052cd0d
//                              tvw_main.cpp:79 (12)
//         0052cc29     CMP        EDI,EBX
//         0052cc2b     JGE        LAB_0052cc9f
//         0052cc2d     MOV        EAX,dword ptr [ESP + 0x10]
//         0052cc31     CMP        EAX,this
//         0052cc33     JGE        LAB_0052cc65
//                              tvw_main.cpp:82 (8)
//         0052cc35     MOV        EBX,dword ptr [ESP + 0x14]
//         0052cc39     MOV        ESI,EDI
//         0052cc3b     MOV        EDI,EAX
//                               LAB_0052cc3d                                                 XREF[1]:     0052cc51(j)
//                              tvw_main.cpp:83 (22)
//         0052cc3d     PUSH       0x2
//         0052cc3f     PUSH       EBX=>DAT_fffffff8
//         0052cc40     PUSH       EDI=>DAT_fffffff4
//         0052cc41     PUSH       ESI=>DAT_fffffff0
//         0052cc42     MOV        this,EBP
//         0052cc44     CALL       TRIBE_Main_View::draw_wall_outline               int draw_wall_outline(TRIBE_Main_View * this,
//         0052cc49     MOV        EAX,dword ptr [ESP + 0x20]
//         0052cc4d     INC        ESI
//         0052cc4e     INC        EDI
//         0052cc4f     CMP        ESI,EAX
//         0052cc51     JLE        LAB_0052cc3d
//                              tvw_main.cpp:209 (10)
//         0052cc53     MOV        this,dword ptr [EBP + 0x20]
//         0052cc56     PUSH       0x0
//         0052cc58     CALL       TDrawArea::SetClipRect                           void SetClipRect(TDrawArea * this, tagRECT *
//                              tvw_main.cpp:210 (8)
//         0052cc5d     POP        EDI
//         0052cc5e     POP        ESI
//         0052cc5f     POP        EBP
//         0052cc60     POP        EBX
//         0052cc61     ADD        ESP,0x48
//         0052cc64     RET
//                               LAB_0052cc65                                                 XREF[1]:     0052cc33(j)
//                              tvw_main.cpp:85 (4)
//         0052cc65     CMP        EDI,EBX
//         0052cc67     JGE        LAB_0052cc9f
//                              tvw_main.cpp:88 (14)
//         0052cc69     CMP        EBX,EDI
//         0052cc6b     MOV        ESI,this
//         0052cc6d     JL         LAB_0052d047
//         0052cc73     MOV        EDI,dword ptr [ESP + 0x14]
//                               LAB_0052cc77                                                 XREF[1]:     0052cc8b(j)
//                              tvw_main.cpp:89 (22)
//         0052cc77     PUSH       0x2
//         0052cc79     PUSH       EDI=>DAT_fffffff8
//         0052cc7a     PUSH       ESI=>DAT_fffffff4
//         0052cc7b     PUSH       EBX=>DAT_fffffff0
//         0052cc7c     MOV        this,EBP
//         0052cc7e     CALL       TRIBE_Main_View::draw_wall_outline               int draw_wall_outline(TRIBE_Main_View * this,
//         0052cc83     MOV        EAX,dword ptr [ESP + 0x28]
//         0052cc87     DEC        EBX
//         0052cc88     INC        ESI
//         0052cc89     CMP        EBX,EAX
//         0052cc8b     JGE        LAB_0052cc77
//                              tvw_main.cpp:209 (10)
//         0052cc8d     MOV        this,dword ptr [EBP + 0x20]
//         0052cc90     PUSH       0x0
//         0052cc92     CALL       TDrawArea::SetClipRect                           void SetClipRect(TDrawArea * this, tagRECT *
//                              tvw_main.cpp:210 (8)
//         0052cc97     POP        EDI
//         0052cc98     POP        ESI
//         0052cc99     POP        EBP
//         0052cc9a     POP        EBX
//         0052cc9b     ADD        ESP,0x48
//         0052cc9e     RET
//                               LAB_0052cc9f                                                 XREF[2]:     0052cc2b(j), 0052cc67(j)
//                              tvw_main.cpp:91 (8)
//         0052cc9f     MOV        EAX,dword ptr [ESP + 0x10]
//         0052cca3     CMP        EAX,this
//         0052cca5     JGE        LAB_0052ccd7
//                              tvw_main.cpp:94 (8)
//         0052cca7     MOV        EBX,dword ptr [ESP + 0x14]
//         0052ccab     MOV        ESI,EDI
//         0052ccad     MOV        EDI,EAX
//                               LAB_0052ccaf                                                 XREF[1]:     0052ccc3(j)
//                              tvw_main.cpp:95 (22)
//         0052ccaf     PUSH       0x2
//         0052ccb1     PUSH       EBX=>DAT_fffffff8
//         0052ccb2     PUSH       EDI=>DAT_fffffff4
//         0052ccb3     PUSH       ESI=>DAT_fffffff0
//         0052ccb4     MOV        this,EBP
//         0052ccb6     CALL       TRIBE_Main_View::draw_wall_outline               int draw_wall_outline(TRIBE_Main_View * this,
//         0052ccbb     MOV        EAX,dword ptr [ESP + 0x20]
//         0052ccbf     DEC        ESI
//         0052ccc0     INC        EDI
//         0052ccc1     CMP        ESI,EAX
//         0052ccc3     JGE        LAB_0052ccaf
//                              tvw_main.cpp:209 (10)
//         0052ccc5     MOV        this,dword ptr [EBP + 0x20]
//         0052ccc8     PUSH       0x0
//         0052ccca     CALL       TDrawArea::SetClipRect                           void SetClipRect(TDrawArea * this, tagRECT *
//                              tvw_main.cpp:210 (8)
//         0052cccf     POP        EDI
//         0052ccd0     POP        ESI
//         0052ccd1     POP        EBP
//         0052ccd2     POP        EBX
//         0052ccd3     ADD        ESP,0x48
//         0052ccd6     RET
//                               LAB_0052ccd7                                                 XREF[1]:     0052cca5(j)
//                              tvw_main.cpp:100 (14)
//         0052ccd7     CMP        EBX,EDI
//         0052ccd9     MOV        ESI,this
//         0052ccdb     JG         LAB_0052d047
//         0052cce1     MOV        EDI,dword ptr [ESP + 0x14]
//                               LAB_0052cce5                                                 XREF[1]:     0052ccf9(j)
//                              tvw_main.cpp:101 (22)
//         0052cce5     PUSH       0x2
//         0052cce7     PUSH       EDI=>DAT_fffffff8
//         0052cce8     PUSH       ESI=>DAT_fffffff4
//         0052cce9     PUSH       EBX=>DAT_fffffff0
//         0052ccea     MOV        this,EBP
//         0052ccec     CALL       TRIBE_Main_View::draw_wall_outline               int draw_wall_outline(TRIBE_Main_View * this,
//         0052ccf1     MOV        EAX,dword ptr [ESP + 0x28]
//         0052ccf5     INC        EBX
//         0052ccf6     INC        ESI
//         0052ccf7     CMP        EBX,EAX
//         0052ccf9     JLE        LAB_0052cce5
//                              tvw_main.cpp:209 (10)
//         0052ccfb     MOV        this,dword ptr [EBP + 0x20]
//         0052ccfe     PUSH       0x0
//         0052cd00     CALL       TDrawArea::SetClipRect                           void SetClipRect(TDrawArea * this, tagRECT *
//                              tvw_main.cpp:210 (8)
//         0052cd05     POP        EDI
//         0052cd06     POP        ESI
//         0052cd07     POP        EBP
//         0052cd08     POP        EBX
//         0052cd09     ADD        ESP,0x48
//         0052cd0c     RET
//                               LAB_0052cd0d                                                 XREF[1]:     0052cc23(j)
//                              tvw_main.cpp:104 (6)
//         0052cd0d     JL         LAB_0052ceb9
//                              tvw_main.cpp:108 (12)
//         0052cd13     MOV        EAX,dword ptr [ESP + 0x10]
//         0052cd17     MOV        dword ptr [ESP + 0x30],EBX
//         0052cd1b     CMP        EAX,this
//         0052cd1d     JLE        LAB_0052cd2b
//                              tvw_main.cpp:110 (2)
//         0052cd1f     MOV        ESI,this
//                              tvw_main.cpp:111 (8)
//         0052cd21     MOV        dword ptr [ESP + 0x1c],EAX
//         0052cd25     MOV        dword ptr [ESP + 0x38],ESI
//                              tvw_main.cpp:113 (2)
//         0052cd29     JMP        LAB_0052cd35
//                               LAB_0052cd2b                                                 XREF[1]:     0052cd1d(j)
//                              tvw_main.cpp:115 (4)
//         0052cd2b     MOV        dword ptr [ESP + 0x38],EAX
//                              tvw_main.cpp:116 (6)
//         0052cd2f     MOV        dword ptr [ESP + 0x1c],this
//         0052cd33     MOV        ESI,EAX
//                               LAB_0052cd35                                                 XREF[1]:     0052cd29(j)
//                              tvw_main.cpp:119 (4)
//         0052cd35     CMP        EBX,EDI
//         0052cd37     JGE        LAB_0052cd4c
//                              tvw_main.cpp:122 (4)
//         0052cd39     MOV        dword ptr [ESP + 0x2c],EAX
//                              tvw_main.cpp:123 (2)
//         0052cd3d     MOV        EAX,EDI
//                              tvw_main.cpp:124 (11)
//         0052cd3f     LEA        EDX,[EBX + 0x1]
//         0052cd42     MOV        dword ptr [ESP + 0x24],EAX
//         0052cd46     MOV        dword ptr [ESP + 0x18],EDX
//                              tvw_main.cpp:126 (4)
//         0052cd4a     JMP        LAB_0052cd63
//                               LAB_0052cd4c                                                 XREF[1]:     0052cd37(j)
//         0052cd4c     JLE        LAB_0052cd5f
//                              tvw_main.cpp:129 (4)
//         0052cd4e     MOV        dword ptr [ESP + 0x2c],EAX
//                              tvw_main.cpp:130 (7)
//         0052cd52     LEA        EAX,[EBX + -0x1]
//         0052cd55     MOV        dword ptr [ESP + 0x24],EAX
//                              tvw_main.cpp:131 (10)
//         0052cd59     MOV        dword ptr [ESP + 0x18],EDI
//         0052cd5d     JMP        LAB_0052cd63
//                               LAB_0052cd5f                                                 XREF[1]:     0052cd4c(j)
//         0052cd5f     MOV        EAX,dword ptr [ESP + 0x24]
//                               LAB_0052cd63                                                 XREF[2]:     0052cd4a(j), 0052cd5d(j)
//                              tvw_main.cpp:134 (19)
//         0052cd63     CMP        dword ptr [ESP + 0x2c],-0x1
//         0052cd68     JZ         LAB_0052ce0f
//         0052cd6e     CMP        EAX,EBX
//         0052cd70     JL         LAB_0052ce0f
//                              tvw_main.cpp:149 (18)
//         0052cd76     MOV        EDX,dword ptr [ESP + 0x18]
//         0052cd7a     MOV        EDI,EAX
//         0052cd7c     CMP        EAX,EDX
//         0052cd7e     JL         LAB_0052cdb7
//         0052cd80     MOV        ESI,EDX
//         0052cd82     JMP        LAB_0052cd88
//                               LAB_0052cd84                                                 XREF[1]:     0052cdb1(j)
//         0052cd84     MOV        EBX,dword ptr [ESP + 0x20]
//                               LAB_0052cd88                                                 XREF[1]:     0052cd82(j)
//                              tvw_main.cpp:150 (43)
//         0052cd88     CMP        EDI,EBX
//         0052cd8a     JZ         LAB_0052cd96
//         0052cd8c     CMP        EDI,dword ptr [ESP + 0x28]
//         0052cd90     JZ         LAB_0052cd96
//         0052cd92     XOR        EAX,EAX
//         0052cd94     JMP        LAB_0052cd9b
//                               LAB_0052cd96                                                 XREF[2]:     0052cd8a(j), 0052cd90(j)
//         0052cd96     MOV        EAX,0x2
//                               LAB_0052cd9b                                                 XREF[1]:     0052cd94(j)
//         0052cd9b     MOV        this,dword ptr [ESP + 0x2c]
//         0052cd9f     PUSH       EAX
//         0052cda0     MOV        EAX,dword ptr [ESP + 0x18]
//         0052cda4     PUSH       EAX=>DAT_fffffff8
//         0052cda5     PUSH       this=>DAT_fffffff4
//         0052cda6     PUSH       EDI=>DAT_fffffff0
//         0052cda7     MOV        this,EBP
//         0052cda9     CALL       TRIBE_Main_View::draw_wall_outline               int draw_wall_outline(TRIBE_Main_View * this,
//         0052cdae     DEC        EDI
//         0052cdaf     CMP        EDI,ESI
//         0052cdb1     JGE        LAB_0052cd84
//                              tvw_main.cpp:149 (4)
//         0052cdb3     MOV        this,dword ptr [ESP + 0x34]
//                               LAB_0052cdb7                                                 XREF[1]:     0052cd7e(j)
//                              tvw_main.cpp:152 (28)
//         0052cdb7     MOV        ESI,dword ptr [ESP + 0x38]
//         0052cdbb     MOV        EAX,dword ptr [ESP + 0x1c]
//         0052cdbf     CMP        ESI,EAX
//         0052cdc1     JG         LAB_0052d047
//         0052cdc7     MOV        EBX,dword ptr [ESP + 0x30]
//         0052cdcb     MOV        EDI,EAX
//         0052cdcd     JMP        LAB_0052cdd3
//                               LAB_0052cdcf                                                 XREF[1]:     0052cdfb(j)
//         0052cdcf     MOV        this,dword ptr [ESP + 0x34]
//                               LAB_0052cdd3                                                 XREF[1]:     0052cdcd(j)
//                              tvw_main.cpp:153 (42)
//         0052cdd3     CMP        ESI,this
//         0052cdd5     JZ         LAB_0052cde4
//         0052cdd7     MOV        EAX,dword ptr [ESP + 0x10]
//         0052cddb     CMP        ESI,EAX
//         0052cddd     MOV        EAX,0x1
//         0052cde2     JNZ        LAB_0052cde9
//                               LAB_0052cde4                                                 XREF[1]:     0052cdd5(j)
//         0052cde4     MOV        EAX,0x2
//                               LAB_0052cde9                                                 XREF[1]:     0052cde2(j)
//         0052cde9     MOV        EDX,dword ptr [ESP + 0x14]
//         0052cded     PUSH       EAX
//         0052cdee     PUSH       EDX=>DAT_fffffff8
//         0052cdef     PUSH       ESI=>DAT_fffffff4
//         0052cdf0     PUSH       EBX=>DAT_fffffff0
//         0052cdf1     MOV        this,EBP
//         0052cdf3     CALL       TRIBE_Main_View::draw_wall_outline               int draw_wall_outline(TRIBE_Main_View * this,
//         0052cdf8     INC        ESI
//         0052cdf9     CMP        ESI,EDI
//         0052cdfb     JLE        LAB_0052cdcf
//                              tvw_main.cpp:209 (10)
//         0052cdfd     MOV        this,dword ptr [EBP + 0x20]
//         0052ce00     PUSH       0x0
//         0052ce02     CALL       TDrawArea::SetClipRect                           void SetClipRect(TDrawArea * this, tagRECT *
//                              tvw_main.cpp:210 (8)
//         0052ce07     POP        EDI
//         0052ce08     POP        ESI
//         0052ce09     POP        EBP
//         0052ce0a     POP        EBX
//         0052ce0b     ADD        ESP,0x48
//         0052ce0e     RET
//                               LAB_0052ce0f                                                 XREF[2]:     0052cd68(j), 0052cd70(j)
//                              tvw_main.cpp:137 (20)
//         0052ce0f     MOV        EAX,dword ptr [ESP + 0x1c]
//         0052ce13     CMP        ESI,EAX
//         0052ce15     JG         LAB_0052ce55
//         0052ce17     MOV        EBX,dword ptr [ESP + 0x30]
//         0052ce1b     MOV        EDI,EAX
//         0052ce1d     JMP        LAB_0052ce23
//                               LAB_0052ce1f                                                 XREF[1]:     0052ce4b(j)
//         0052ce1f     MOV        this,dword ptr [ESP + 0x34]
//                               LAB_0052ce23                                                 XREF[1]:     0052ce1d(j)
//                              tvw_main.cpp:138 (50)
//         0052ce23     CMP        ESI,this
//         0052ce25     JZ         LAB_0052ce34
//         0052ce27     MOV        EAX,dword ptr [ESP + 0x10]
//         0052ce2b     CMP        ESI,EAX
//         0052ce2d     MOV        EAX,0x1
//         0052ce32     JNZ        LAB_0052ce39
//                               LAB_0052ce34                                                 XREF[1]:     0052ce25(j)
//         0052ce34     MOV        EAX,0x2
//                               LAB_0052ce39                                                 XREF[1]:     0052ce32(j)
//         0052ce39     PUSH       EAX
//         0052ce3a     MOV        EAX,dword ptr [ESP + 0x18]
//         0052ce3e     PUSH       EAX=>DAT_fffffff8
//         0052ce3f     PUSH       ESI=>DAT_fffffff4
//         0052ce40     PUSH       EBX=>DAT_fffffff0
//         0052ce41     MOV        this,EBP
//         0052ce43     CALL       TRIBE_Main_View::draw_wall_outline               int draw_wall_outline(TRIBE_Main_View * this,
//         0052ce48     INC        ESI
//         0052ce49     CMP        ESI,EDI
//         0052ce4b     JLE        LAB_0052ce1f
//         0052ce4d     MOV        EBX,dword ptr [ESP + 0x20]
//         0052ce51     MOV        EDI,dword ptr [ESP + 0x28]
//                               LAB_0052ce55                                                 XREF[1]:     0052ce15(j)
//                              tvw_main.cpp:140 (11)
//         0052ce55     CMP        dword ptr [ESP + 0x2c],-0x1
//         0052ce5a     JZ         LAB_0052d047
//                              tvw_main.cpp:142 (26)
//         0052ce60     MOV        ESI,dword ptr [ESP + 0x24]
//         0052ce64     MOV        EAX,dword ptr [ESP + 0x18]
//         0052ce68     CMP        ESI,EAX
//         0052ce6a     JL         LAB_0052d047
//         0052ce70     JMP        LAB_0052ce7a
//                               LAB_0052ce72                                                 XREF[1]:     0052cea5(j)
//         0052ce72     MOV        EBX,dword ptr [ESP + 0x20]
//         0052ce76     MOV        EDI,dword ptr [ESP + 0x28]
//                               LAB_0052ce7a                                                 XREF[1]:     0052ce70(j)
//                              tvw_main.cpp:143 (45)
//         0052ce7a     CMP        ESI,EBX
//         0052ce7c     JZ         LAB_0052ce86
//         0052ce7e     CMP        ESI,EDI
//         0052ce80     JZ         LAB_0052ce86
//         0052ce82     XOR        EAX,EAX
//         0052ce84     JMP        LAB_0052ce8b
//                               LAB_0052ce86                                                 XREF[2]:     0052ce7c(j), 0052ce80(j)
//         0052ce86     MOV        EAX,0x2
//                               LAB_0052ce8b                                                 XREF[1]:     0052ce84(j)
//         0052ce8b     MOV        this,dword ptr [ESP + 0x14]
//         0052ce8f     MOV        EDX,dword ptr [ESP + 0x2c]
//         0052ce93     PUSH       EAX
//         0052ce94     PUSH       this=>DAT_fffffff8
//         0052ce95     PUSH       EDX=>DAT_fffffff4
//         0052ce96     PUSH       ESI=>DAT_fffffff0
//         0052ce97     MOV        this,EBP
//         0052ce99     CALL       TRIBE_Main_View::draw_wall_outline               int draw_wall_outline(TRIBE_Main_View * this,
//         0052ce9e     MOV        EAX,dword ptr [ESP + 0x18]
//         0052cea2     DEC        ESI
//         0052cea3     CMP        ESI,EAX
//         0052cea5     JGE        LAB_0052ce72
//                              tvw_main.cpp:209 (10)
//         0052cea7     MOV        this,dword ptr [EBP + 0x20]
//         0052ceaa     PUSH       0x0
//         0052ceac     CALL       TDrawArea::SetClipRect                           void SetClipRect(TDrawArea * this, tagRECT *
//                              tvw_main.cpp:210 (8)
//         0052ceb1     POP        EDI
//         0052ceb2     POP        ESI
//         0052ceb3     POP        EBP
//         0052ceb4     POP        EBX
//         0052ceb5     ADD        ESP,0x48
//         0052ceb8     RET
//                               LAB_0052ceb9                                                 XREF[1]:     0052cd0d(j)
//                              tvw_main.cpp:160 (8)
//         0052ceb9     CMP        EDI,EBX
//         0052cebb     MOV        dword ptr [ESP + 0x2c],this
//         0052cebf     JLE        LAB_0052cecb
//                              tvw_main.cpp:162 (4)
//         0052cec1     MOV        dword ptr [ESP + 0x24],EDI
//                              tvw_main.cpp:163 (4)
//         0052cec5     MOV        dword ptr [ESP + 0x18],EBX
//                              tvw_main.cpp:165 (2)
//         0052cec9     JMP        LAB_0052ced3
//                               LAB_0052cecb                                                 XREF[1]:     0052cebf(j)
//                              tvw_main.cpp:167 (4)
//         0052cecb     MOV        dword ptr [ESP + 0x24],EBX
//                              tvw_main.cpp:168 (4)
//         0052cecf     MOV        dword ptr [ESP + 0x18],EDI
//                               LAB_0052ced3                                                 XREF[1]:     0052cec9(j)
//                              tvw_main.cpp:171 (8)
//         0052ced3     MOV        EDX,dword ptr [ESP + 0x10]
//         0052ced7     CMP        this,EDX
//         0052ced9     JGE        LAB_0052ceec
//                              tvw_main.cpp:175 (11)
//         0052cedb     LEA        EAX,[ECX + this->field1_0x1]
//         0052cede     MOV        dword ptr [ESP + 0x30],EDI
//         0052cee2     MOV        dword ptr [ESP + 0x38],EAX
//                              tvw_main.cpp:176 (4)
//         0052cee6     MOV        dword ptr [ESP + 0x1c],EDX
//                              tvw_main.cpp:178 (4)
//         0052ceea     JMP        LAB_0052cf05
//                               LAB_0052ceec                                                 XREF[1]:     0052ced9(j)
//         0052ceec     JLE        LAB_0052cf01
//                              tvw_main.cpp:182 (2)
//         0052ceee     MOV        EAX,EDX
//                              tvw_main.cpp:183 (21)
//         0052cef0     LEA        EDX,[this->field0_0x0 + -0x1]
//         0052cef3     MOV        dword ptr [ESP + 0x30],EDI
//         0052cef7     MOV        dword ptr [ESP + 0x38],EAX
//         0052cefb     MOV        dword ptr [ESP + 0x1c],EDX
//         0052ceff     JMP        LAB_0052cf05
//                               LAB_0052cf01                                                 XREF[1]:     0052ceec(j)
//         0052cf01     MOV        EAX,dword ptr [ESP + 0x38]
//                               LAB_0052cf05                                                 XREF[2]:     0052ceea(j), 0052ceff(j)
//                              tvw_main.cpp:186 (19)
//         0052cf05     CMP        dword ptr [ESP + 0x30],-0x1
//         0052cf0a     JZ         LAB_0052cfb3
//         0052cf10     CMP        EAX,this
//         0052cf12     JG         LAB_0052cfb3
//                              tvw_main.cpp:201 (22)
//         0052cf18     MOV        EDX,dword ptr [ESP + 0x1c]
//         0052cf1c     MOV        EDI,EAX
//         0052cf1e     CMP        EAX,EDX
//         0052cf20     JG         LAB_0052cf5c
//         0052cf22     MOV        ESI,dword ptr [ESP + 0x30]
//         0052cf26     MOV        EBX,EDX
//         0052cf28     JMP        LAB_0052cf2e
//                               LAB_0052cf2a                                                 XREF[1]:     0052cf56(j)
//         0052cf2a     MOV        this,dword ptr [ESP + 0x34]
//                               LAB_0052cf2e                                                 XREF[1]:     0052cf28(j)
//                              tvw_main.cpp:202 (42)
//         0052cf2e     CMP        EDI,this
//         0052cf30     JZ         LAB_0052cf3f
//         0052cf32     MOV        EAX,dword ptr [ESP + 0x10]
//         0052cf36     CMP        EDI,EAX
//         0052cf38     MOV        EAX,0x1
//         0052cf3d     JNZ        LAB_0052cf44
//                               LAB_0052cf3f                                                 XREF[1]:     0052cf30(j)
//         0052cf3f     MOV        EAX,0x2
//                               LAB_0052cf44                                                 XREF[1]:     0052cf3d(j)
//         0052cf44     PUSH       EAX
//         0052cf45     MOV        EAX,dword ptr [ESP + 0x18]
//         0052cf49     PUSH       EAX=>DAT_fffffff8
//         0052cf4a     PUSH       EDI=>DAT_fffffff4
//         0052cf4b     PUSH       ESI=>DAT_fffffff0
//         0052cf4c     MOV        this,EBP
//         0052cf4e     CALL       TRIBE_Main_View::draw_wall_outline               int draw_wall_outline(TRIBE_Main_View * this,
//         0052cf53     INC        EDI
//         0052cf54     CMP        EDI,EBX
//         0052cf56     JLE        LAB_0052cf2a
//                              tvw_main.cpp:201 (4)
//         0052cf58     MOV        EBX,dword ptr [ESP + 0x20]
//                               LAB_0052cf5c                                                 XREF[1]:     0052cf20(j)
//                              tvw_main.cpp:204 (26)
//         0052cf5c     MOV        ESI,dword ptr [ESP + 0x24]
//         0052cf60     MOV        EAX,dword ptr [ESP + 0x18]
//         0052cf64     MOV        this,ESI
//         0052cf66     CMP        this,EAX
//         0052cf68     JL         LAB_0052d047
//         0052cf6e     MOV        EDI,EAX
//         0052cf70     JMP        LAB_0052cf76
//                               LAB_0052cf72                                                 XREF[1]:     0052cf9f(j)
//         0052cf72     MOV        EBX,dword ptr [ESP + 0x20]
//                               LAB_0052cf76                                                 XREF[1]:     0052cf70(j)
//                              tvw_main.cpp:205 (43)
//         0052cf76     CMP        ESI,EBX
//         0052cf78     JZ         LAB_0052cf84
//         0052cf7a     CMP        ESI,dword ptr [ESP + 0x28]
//         0052cf7e     JZ         LAB_0052cf84
//         0052cf80     XOR        EAX,EAX
//         0052cf82     JMP        LAB_0052cf89
//                               LAB_0052cf84                                                 XREF[2]:     0052cf78(j), 0052cf7e(j)
//         0052cf84     MOV        EAX,0x2
//                               LAB_0052cf89                                                 XREF[1]:     0052cf82(j)
//         0052cf89     MOV        EDX,dword ptr [ESP + 0x14]
//         0052cf8d     PUSH       EAX
//         0052cf8e     MOV        EAX,dword ptr [ESP + 0x30]
//         0052cf92     PUSH       EDX=>DAT_fffffff8
//         0052cf93     PUSH       EAX=>DAT_fffffff4
//         0052cf94     PUSH       ESI=>DAT_fffffff0
//         0052cf95     MOV        this,EBP
//         0052cf97     CALL       TRIBE_Main_View::draw_wall_outline               int draw_wall_outline(TRIBE_Main_View * this,
//         0052cf9c     DEC        ESI
//         0052cf9d     CMP        ESI,EDI
//         0052cf9f     JGE        LAB_0052cf72
//                              tvw_main.cpp:209 (10)
//         0052cfa1     MOV        this,dword ptr [EBP + 0x20]
//         0052cfa4     PUSH       0x0
//         0052cfa6     CALL       TDrawArea::SetClipRect                           void SetClipRect(TDrawArea * this, tagRECT *
//                              tvw_main.cpp:210 (8)
//         0052cfab     POP        EDI
//         0052cfac     POP        ESI
//         0052cfad     POP        EBP
//         0052cfae     POP        EBX
//         0052cfaf     ADD        ESP,0x48
//         0052cfb2     RET
//                               LAB_0052cfb3                                                 XREF[2]:     0052cf0a(j), 0052cf12(j)
//                              tvw_main.cpp:189 (24)
//         0052cfb3     MOV        ESI,dword ptr [ESP + 0x24]
//         0052cfb7     MOV        EAX,dword ptr [ESP + 0x18]
//         0052cfbb     MOV        EDX,ESI
//         0052cfbd     CMP        EDX,EAX
//         0052cfbf     JL         LAB_0052cffc
//         0052cfc1     JMP        LAB_0052cfcb
//                               LAB_0052cfc3                                                 XREF[1]:     0052cff6(j)
//         0052cfc3     MOV        EBX,dword ptr [ESP + 0x20]
//         0052cfc7     MOV        EDI,dword ptr [ESP + 0x28]
//                               LAB_0052cfcb                                                 XREF[1]:     0052cfc1(j)
//                              tvw_main.cpp:190 (45)
//         0052cfcb     CMP        ESI,EBX
//         0052cfcd     JZ         LAB_0052cfd7
//         0052cfcf     CMP        ESI,EDI
//         0052cfd1     JZ         LAB_0052cfd7
//         0052cfd3     XOR        EAX,EAX
//         0052cfd5     JMP        LAB_0052cfdc
//                               LAB_0052cfd7                                                 XREF[2]:     0052cfcd(j), 0052cfd1(j)
//         0052cfd7     MOV        EAX,0x2
//                               LAB_0052cfdc                                                 XREF[1]:     0052cfd5(j)
//         0052cfdc     MOV        this,dword ptr [ESP + 0x2c]
//         0052cfe0     PUSH       EAX
//         0052cfe1     MOV        EAX,dword ptr [ESP + 0x18]
//         0052cfe5     PUSH       EAX=>DAT_fffffff8
//         0052cfe6     PUSH       this=>DAT_fffffff4
//         0052cfe7     PUSH       ESI=>DAT_fffffff0
//         0052cfe8     MOV        this,EBP
//         0052cfea     CALL       TRIBE_Main_View::draw_wall_outline               int draw_wall_outline(TRIBE_Main_View * this,
//         0052cfef     MOV        EAX,dword ptr [ESP + 0x18]
//         0052cff3     DEC        ESI
//         0052cff4     CMP        ESI,EAX
//         0052cff6     JGE        LAB_0052cfc3
//                              tvw_main.cpp:189 (4)
//         0052cff8     MOV        this,dword ptr [ESP + 0x34]
//                               LAB_0052cffc                                                 XREF[1]:     0052cfbf(j)
//                              tvw_main.cpp:192 (7)
//         0052cffc     CMP        dword ptr [ESP + 0x30],-0x1
//         0052d001     JZ         LAB_0052d047
//                              tvw_main.cpp:194 (18)
//         0052d003     MOV        ESI,dword ptr [ESP + 0x38]
//         0052d007     MOV        EAX,dword ptr [ESP + 0x1c]
//         0052d00b     CMP        ESI,EAX
//         0052d00d     JG         LAB_0052d047
//         0052d00f     JMP        LAB_0052d015
//                               LAB_0052d011                                                 XREF[1]:     0052d045(j)
//         0052d011     MOV        this,dword ptr [ESP + 0x34]
//                               LAB_0052d015                                                 XREF[1]:     0052d00f(j)
//                              tvw_main.cpp:195 (50)
//         0052d015     CMP        ESI,this
//         0052d017     JZ         LAB_0052d026
//         0052d019     MOV        EAX,dword ptr [ESP + 0x10]
//         0052d01d     CMP        ESI,EAX
//         0052d01f     MOV        EAX,0x1
//         0052d024     JNZ        LAB_0052d02b
//                               LAB_0052d026                                                 XREF[1]:     0052d017(j)
//         0052d026     MOV        EAX,0x2
//                               LAB_0052d02b                                                 XREF[1]:     0052d024(j)
//         0052d02b     MOV        EDX,dword ptr [ESP + 0x14]
//         0052d02f     PUSH       EAX
//         0052d030     MOV        EAX,dword ptr [ESP + 0x34]
//         0052d034     PUSH       EDX=>DAT_fffffff8
//         0052d035     PUSH       ESI=>DAT_fffffff4
//         0052d036     PUSH       EAX=>DAT_fffffff0
//         0052d037     MOV        this,EBP
//         0052d039     CALL       TRIBE_Main_View::draw_wall_outline               int draw_wall_outline(TRIBE_Main_View * this,
//         0052d03e     MOV        EAX,dword ptr [ESP + 0x1c]
//         0052d042     INC        ESI
//         0052d043     CMP        ESI,EAX
//         0052d045     JLE        LAB_0052d011
//                               LAB_0052d047                                                 XREF[8]:     0052cc6d(j), 0052ccdb(j),
//                                                                                                         0052cdc1(j), 0052ce5a(j),
//                                                                                                         0052ce6a(j), 0052cf68(j),
//                                                                                                         0052d001(j), 0052d00d(j)
//                              tvw_main.cpp:209 (10)
//         0052d047     MOV        this,dword ptr [EBP + 0x20]
//         0052d04a     PUSH       0x0
//         0052d04c     CALL       TDrawArea::SetClipRect                           void SetClipRect(TDrawArea * this, tagRECT *
//                               LAB_0052d051                                                 XREF[4]:     0052cb09(j), 0052cb24(j),
//                                                                                                         0052cb82(j), 0052cbb8(j)
//                              tvw_main.cpp:210 (8)
//         0052d051     POP        EDI
//         0052d052     POP        ESI
//         0052d053     POP        EBP
//         0052d054     POP        EBX
//         0052d055     ADD        ESP,0x48
//         0052d058     RET
//         0052d059     ??         90h
//         0052d05a     NOP
//         0052d05b     NOP
//         0052d05c     NOP
//         0052d05d     NOP
//         0052d05e     NOP
//         0052d05f     NOP
    return;
}

int TRIBE_Main_View::draw_wall_outline(long param_1, long param_2, TRIBE_Master_Building_Object* param_3, long param_4) {
    /* TODO: Stub */
//                              int __thiscall draw_wall_outline(TRIBE_Main_View * this, long param_
//              int               EAX:4          <RETURN>
//              TRIBE_Main_Vie    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[5]:     0052d078(R), 0052d08e(R), 0052d0b4(W), 0052d0cc(R),
//                                                                                     0052d0f1(R)
//              long              Stack[0x8]:4   param_2                   XREF[4]:     0052d063(R), 0052d0b8(R), 0052d0dc(W), 0052d0e0(R)
//              TRIBE_Master_B    Stack[0xc]:4   param_3                   XREF[1]:     0052d0aa(R)
//              long              Stack[0x10]:4  param_4
//              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     0052d092(*)
//              short             Stack[-0x8]:2  y4                        XREF[1]:     0052d0a6(*)
//              short             Stack[-0xc]:2  x3                        XREF[1]:     0052d073(*)
//              short             Stack[-0x10]:2 scr_x                     XREF[1]:     0052d067(*)
//              undefined         Stack[-0x12]:1 local_12                  XREF[1]:     0052d0c1(*)
//              short             Stack[-0x14]:2 scr_y                     XREF[1]:     0052d0bc(*)
//              short             Stack[-0x16]:2 y1                        XREF[1]:     0052d09b(*)
//              short             Stack[-0x18]:2 x2                        XREF[1]:     0052d096(*)
//              short             Stack[-0x1a]:2 y3                        XREF[1]:     0052d0af(*)
//              short             Stack[-0x1c]:2 x4                        XREF[1]:     0052d0d0(*)
//              short             Stack[-0x1e]:2 y2
//              short             Stack[-0x20]:2 x1
//                               ?draw_wall_outline@TRIBE_Main_View@@IAEHJJPAVTRIBE_Master_B  XREF[12]:    draw_multi_object_outline:0052cc44
//                               TRIBE_Main_View::draw_wall_outline                                        draw_multi_object_outline:0052cc7e
//                                                                                                         draw_multi_object_outline:0052ccb6
//                                                                                                         draw_multi_object_outline:0052ccec
//                                                                                                         draw_multi_object_outline:0052cda9
//                                                                                                         draw_multi_object_outline:0052cdf3
//                                                                                                         draw_multi_object_outline:0052ce43
//                                                                                                         draw_multi_object_outline:0052ce99
//                                                                                                         draw_multi_object_outline:0052cf4e
//                                                                                                         draw_multi_object_outline:0052cf97
//                                                                                                         draw_multi_object_outline:0052cfea
//                                                                                                         draw_multi_object_outline:0052d039
//                              tvw_main.cpp:216 (3)
//         0052d060     SUB        ESP,0x1c
//                              tvw_main.cpp:229 (43)
//         0052d063     MOV        EDX,dword ptr [ESP + param_2]
//         0052d067     LEA        EAX=>scr_x,[ESP + 0xc]
//         0052d06b     PUSH       EBX
//         0052d06c     PUSH       EBP
//         0052d06d     PUSH       ESI
//         0052d06e     PUSH       EDI
//         0052d06f     MOV        EDI,this
//         0052d071     PUSH       0x0
//         0052d073     LEA        this=>x3,[ESP + 0x24]
//         0052d077     PUSH       EAX
//         0052d078     MOV        EAX,dword ptr [ESP + param_1]
//         0052d07c     PUSH       this
//         0052d07d     PUSH       EDX
//         0052d07e     PUSH       EAX
//         0052d07f     MOV        this,EDI
//         0052d081     CALL       RGE_View::get_tile_screen_coords                 int get_tile_screen_coords(RGE_View * this, s
//         0052d086     TEST       EAX,EAX
//         0052d088     JZ         LAB_0052d1ce
//                              tvw_main.cpp:231 (4)
//         0052d08e     FILD       dword ptr [ESP + param_1]
//                              tvw_main.cpp:233 (92)
//         0052d092     LEA        this=>local_4,[ESP + 0x28]
//         0052d096     LEA        EDX=>x2,[ESP + 0x14]
//         0052d09a     PUSH       this
//         0052d09b     LEA        EAX=>y1,[ESP + 0x1a]
//         0052d09f     FSUB       float ptr [DAT_00577450]                         = align(3)
//         0052d0a5     PUSH       EDX
//         0052d0a6     LEA        this=>y4,[ESP + 0x2c]
//         0052d0aa     MOV        ESI,dword ptr [ESP + param_3]
//         0052d0ae     PUSH       EAX
//         0052d0af     LEA        EDX=>y3,[ESP + 0x1e]
//         0052d0b3     PUSH       this
//         0052d0b4     FSTP       float ptr [ESP + param_1]
//         0052d0b8     FILD       dword ptr [ESP + param_2]
//         0052d0bc     LEA        EAX=>scr_y,[ESP + 0x28]
//         0052d0c0     PUSH       EDX
//         0052d0c1     LEA        this=>local_12,[ESP + 0x2e]
//         0052d0c5     PUSH       EAX
//         0052d0c6     FSUB       float ptr [DAT_00577450]                         = align(3)
//         0052d0cc     MOV        EAX,dword ptr [ESP + param_1]
//         0052d0d0     LEA        EDX=>x4,[ESP + 0x28]
//         0052d0d4     PUSH       this
//         0052d0d5     MOV        this,dword ptr [EDI + 0xfc]
//         0052d0db     PUSH       EDX
//         0052d0dc     FSTP       float ptr [ESP + param_2]
//         0052d0e0     MOV        EBP,dword ptr [ESP + param_2]
//         0052d0e4     PUSH       EBP
//         0052d0e5     PUSH       EAX
//         0052d0e6     PUSH       this
//         0052d0e7     MOV        this,ESI
//         0052d0e9     CALL       RGE_Master_Static_Object::alignment_box          uchar alignment_box(RGE_Master_Static_Object
//                              tvw_main.cpp:234 (36)
//         0052d0ee     MOV        DL,byte ptr [ESI + 0x64]
//         0052d0f1     MOV        EAX,dword ptr [ESP + param_1]
//         0052d0f5     MOV        this,dword ptr [EDI + 0x100]
//         0052d0fb     PUSH       0x1
//         0052d0fd     MOV        EBX,dword ptr [ESI]
//         0052d0ff     PUSH       0x1
//         0052d101     PUSH       0x1
//         0052d103     PUSH       0x0
//         0052d105     PUSH       EDX
//         0052d106     PUSH       0x1
//         0052d108     PUSH       0x0
//         0052d10a     PUSH       EBP
//         0052d10b     PUSH       EAX
//         0052d10c     PUSH       this
//         0052d10d     MOV        this,ESI
//         0052d10f     CALL       dword ptr [EBX + 0x20]
//                              tvw_main.cpp:238 (4)
//         0052d112     TEST       AL,AL
//         0052d114     JNZ        LAB_0052d122
//                              tvw_main.cpp:241 (10)
//         0052d116     MOV        dword ptr [fog_next_shape],0x5
//                              tvw_main.cpp:244 (2)
//         0052d120     JMP        LAB_0052d14e
//                               LAB_0052d122                                                 XREF[1]:     0052d114(j)
//                              tvw_main.cpp:246 (15)
//         0052d122     MOV        EDX,dword ptr [EDI + 0xfc]
//         0052d128     MOV        EAX,dword ptr [EDX + 0x4]
//         0052d12b     SHR        EAX,0x7
//         0052d12e     AND        EAX,0x7
//                              tvw_main.cpp:247 (19)
//         0052d131     CMP        EAX,0x4
//         0052d134     JNC        LAB_0052d13b
//         0052d136     ADD        EAX,0x24
//         0052d139     JMP        LAB_0052d144
//                               LAB_0052d13b                                                 XREF[1]:     0052d134(j)
//         0052d13b     MOV        this,0x2c
//         0052d140     SUB        this,EAX
//         0052d142     MOV        EAX,this
//                               LAB_0052d144                                                 XREF[1]:     0052d139(j)
//                              tvw_main.cpp:248 (10)
//         0052d144     SHL        EAX,0x4
//         0052d147     OR         AL,0x9
//         0052d149     MOV        [fog_next_shape],EAX
//                               LAB_0052d14e                                                 XREF[1]:     0052d120(j)
//                              tvw_main.cpp:254 (7)
//         0052d14e     MOV        EAX,dword ptr [ESI + 0x18]
//         0052d151     TEST       EAX,EAX
//         0052d153     JZ         LAB_0052d1ce
//                              tvw_main.cpp:259 (4)
//         0052d155     MOV        this,dword ptr [ESP + 0x24]
//                              tvw_main.cpp:264 (117)
//         0052d159     PUSH       0x0
//         0052d15b     MOVSX      EAX,word ptr [ESP + 0x14]
//         0052d160     MOVSX      EDX,this
//         0052d163     SUB        EAX,EDX
//         0052d165     PUSH       0x0=>DAT_fffffff8
//         0052d167     CDQ
//         0052d168     SUB        EAX,EDX
//         0052d16a     PUSH       0x0=>DAT_fffffff4
//         0052d16c     SAR        EAX,0x1
//         0052d16e     ADD        EAX,this
//         0052d170     MOV        this,dword ptr [ESP + 0x2c]
//         0052d174     ADD        this,EAX
//         0052d176     MOVSX      EAX,word ptr [ESP + 0x1e]
//         0052d17b     MOV        dword ptr [ESP + 0x2c],this
//         0052d17f     MOV        this,dword ptr [ESP + 0x34]
//         0052d183     MOVSX      EDX,this
//         0052d186     SUB        EAX,EDX
//         0052d188     CDQ
//         0052d189     SUB        EAX,EDX
//         0052d18b     MOV        EDX,EAX
//         0052d18d     MOV        EAX,dword ptr [ESP + 0x28]
//         0052d191     SAR        EDX,0x1
//         0052d193     ADD        EDX,this
//         0052d195     MOV        this,dword ptr [ESP + 0x48]
//         0052d199     ADD        EAX,EDX
//         0052d19b     INC        this
//         0052d19c     MOV        dword ptr [ESP + 0x28],EAX
//         0052d1a0     PUSH       this=>DAT_fffffff0
//         0052d1a1     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052d1a7     MOVSX      EAX,AX
//         0052d1aa     MOV        [SDI_Draw_Line],EAX
//         0052d1af     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
//         0052d1b4     MOV        EDX,dword ptr [EAX + 0x108]
//         0052d1ba     MOV        EAX,dword ptr [ESP + 0x2c]
//         0052d1be     MOV        this,dword ptr [ESP + 0x30]
//         0052d1c2     PUSH       EDX
//         0052d1c3     MOV        EDX,dword ptr [EDI + 0x20]
//         0052d1c6     PUSH       EAX
//         0052d1c7     PUSH       this
//         0052d1c8     PUSH       EDX
//         0052d1c9     MOV        this,ESI
//         0052d1cb     CALL       dword ptr [EBX + 0x34]
//                               LAB_0052d1ce                                                 XREF[2]:     0052d088(j), 0052d153(j)
//                              tvw_main.cpp:275 (25)
//         0052d1ce     POP        EDI
//         0052d1cf     POP        ESI
//         0052d1d0     POP        EBP
//         0052d1d1     MOV        dword ptr [fog_next_shape],0x0
//         0052d1db     MOV        EAX,0x1
//         0052d1e0     POP        EBX
//         0052d1e1     ADD        ESP,0x1c
//         0052d1e4     RET        0x10
//         0052d1e7     ??         90h
//         0052d1e8     NOP
//         0052d1e9     NOP
//         0052d1ea     NOP
//         0052d1eb     NOP
//         0052d1ec     NOP
//         0052d1ed     NOP
//         0052d1ee     NOP
//         0052d1ef     NOP
    return 0;
}

int TRIBE_Main_View::command_place_object(long param_1, long param_2, int param_3) {
    /* TODO: Stub */
//                              int __thiscall command_place_object(TRIBE_Main_View * this, long par
//              int               EAX:4          <RETURN>
//              TRIBE_Main_Vie    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[2]:     0052d21a(R), 0052d235(R)
//              long              Stack[0x8]:4   param_2                   XREF[2]:     0052d216(R), 0052d231(R)
//              int               Stack[0xc]:4   param_3
//              RGE_Pick_Info     Stack[-0x18]   pick_info                 XREF[0,4]:   0052d239(*), 0052d255(*), 0052d29a(*), 0052d295(*)
//                               ?command_place_object@TRIBE_Main_View@@UAEHJJH@Z             XREF[1]:     00572ba4(*)
//                               TRIBE_Main_View::command_place_object
//                              tvw_main.cpp:281 (16)
//         0052d1f0     MOV        EAX,[allow_user_commands]                        = 1h
//         0052d1f5     SUB        ESP,0x14
//         0052d1f8     TEST       EAX,EAX
//         0052d1fa     PUSH       EBX
//         0052d1fb     PUSH       EBP
//         0052d1fc     PUSH       ESI
//         0052d1fd     PUSH       EDI
//         0052d1fe     MOV        EDI,this
//                              tvw_main.cpp:288 (6)
//         0052d200     JZ         LAB_0052d314
//                              tvw_main.cpp:290 (5)
//         0052d206     MOV        EAX,[rge_base_game]                              = 00000000
//                              tvw_main.cpp:291 (28)
//         0052d20b     PUSH       0x1
//         0052d20d     CMP        dword ptr [EAX + 0x1b4],0x7
//         0052d214     JZ         LAB_0052d231
//         0052d216     MOV        this,dword ptr [ESP + param_2]
//         0052d21a     MOV        EDX,dword ptr [ESP + param_1]
//         0052d21e     PUSH       this
//         0052d21f     PUSH       EDX
//         0052d220     MOV        this,EDI
//         0052d222     CALL       RGE_Main_View::command_place_object              int command_place_object(RGE_Main_View * this
//                              tvw_main.cpp:313 (10)
//         0052d227     POP        EDI
//         0052d228     POP        ESI
//         0052d229     POP        EBP
//         0052d22a     POP        EBX
//         0052d22b     ADD        ESP,0x14
//         0052d22e     RET        0xc
//                               LAB_0052d231                                                 XREF[1]:     0052d214(j)
//                              tvw_main.cpp:293 (28)
//         0052d231     MOV        this,dword ptr [ESP + param_2]
//         0052d235     MOV        EDX,dword ptr [ESP + param_1]
//         0052d239     LEA        EAX=>pick_info.y,[ESP + 0x14]
//         0052d23d     PUSH       0x0
//         0052d23f     PUSH       EAX
//         0052d240     PUSH       this
//         0052d241     PUSH       EDX
//         0052d242     PUSH       0x0
//         0052d244     PUSH       0x28
//         0052d246     MOV        this,EDI
//         0052d248     CALL       RGE_Main_View::pick1                             uchar pick1(RGE_Main_View * this, uchar param
//                              tvw_main.cpp:294 (8)
//         0052d24d     CMP        AL,0x33
//         0052d24f     JNZ        LAB_0052d314
//                              tvw_main.cpp:296 (12)
//         0052d255     LEA        EAX=>pick_info.y,[ESP + 0x10]
//         0052d259     MOV        this,EDI
//         0052d25b     PUSH       EAX
//         0052d25c     CALL       RGE_Main_View::fixup_pick_info                   void fixup_pick_info(RGE_Main_View * this, RG
//                              tvw_main.cpp:297 (13)
//         0052d261     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052d267     MOVSX      EBP,word ptr [this->field0_0x0 + 0x3fc]
//                              tvw_main.cpp:298 (29)
//         0052d26e     CMP        EBP,-0x1
//         0052d271     JZ         LAB_0052d314
//         0052d277     MOV        EDX,dword ptr [EDI + 0x100]
//         0052d27d     MOV        EAX,dword ptr [EDX + 0x24]
//         0052d280     MOV        ESI,dword ptr [EAX + EBP*0x4]
//         0052d283     TEST       ESI,ESI
//         0052d285     JZ         LAB_0052d314
//                              tvw_main.cpp:301 (26)
//         0052d28b     MOV        this,dword ptr [EDI + 0xfc]
//         0052d291     MOV        EBX,dword ptr [ESI]
//         0052d293     PUSH       0x0
//         0052d295     LEA        EDX=>pick_info.scr_x,[ESP + 0x18]
//         0052d299     PUSH       this
//         0052d29a     LEA        EAX=>pick_info.y,[ESP + 0x18]
//         0052d29e     PUSH       EDX
//         0052d29f     PUSH       EAX
//         0052d2a0     MOV        this,ESI
//         0052d2a2     CALL       dword ptr [EBX + 0x24]
//                              tvw_main.cpp:302 (42)
//         0052d2a5     MOV        this,byte ptr [ESI + 0x64]
//         0052d2a8     MOV        EDX,dword ptr [ESP + 0x14]
//         0052d2ac     MOV        EAX,dword ptr [ESP + 0x10]
//         0052d2b0     PUSH       0x1
//         0052d2b2     PUSH       offset DAT_fffffff8
//         0052d2b4     PUSH       offset DAT_fffffff4
//         0052d2b6     PUSH       0x0=>DAT_fffffff0
//         0052d2b8     PUSH       this
//         0052d2b9     MOV        this,dword ptr [EDI + 0x100]
//         0052d2bf     PUSH       0x1
//         0052d2c1     PUSH       0x0
//         0052d2c3     PUSH       EDX
//         0052d2c4     PUSH       EAX
//         0052d2c5     PUSH       this
//         0052d2c6     MOV        this,ESI
//         0052d2c8     CALL       dword ptr [EBX + 0x20]
//         0052d2cb     TEST       AL,AL
//         0052d2cd     JNZ        LAB_0052d314
//                              tvw_main.cpp:304 (13)
//         0052d2cf     MOV        EAX,dword ptr [ESP + 0x30]
//         0052d2d3     TEST       EAX,EAX
//         0052d2d5     JNZ        LAB_0052d2dc
//         0052d2d7     CMP        EBP,0x6d
//         0052d2da     JNZ        LAB_0052d2eb
//                               LAB_0052d2dc                                                 XREF[1]:     0052d2d5(j)
//                              tvw_main.cpp:305 (15)
//         0052d2dc     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052d2e2     PUSH       0x0
//         0052d2e4     PUSH       0x0=>DAT_fffffff8
//         0052d2e6     MOV        EDX,dword ptr [this->field0_0x0]
//         0052d2e8     CALL       dword ptr [EDX + 0x10]
//                               LAB_0052d2eb                                                 XREF[1]:     0052d2da(j)
//                              tvw_main.cpp:306 (26)
//         0052d2eb     MOV        EAX,dword ptr [ESP + 0x14]
//         0052d2ef     MOV        this,dword ptr [ESP + 0x10]
//         0052d2f3     PUSH       EAX
//         0052d2f4     PUSH       this=>DAT_fffffff8
//         0052d2f5     MOV        this,dword ptr [EDI + 0x100]
//         0052d2fb     PUSH       EBP=>DAT_fffffff4
//         0052d2fc     CALL       TRIBE_Player::command_make_building              uchar command_make_building(TRIBE_Player * th
//         0052d301     TEST       AL,AL
//         0052d303     JZ         LAB_0052d314
//                              tvw_main.cpp:307 (5)
//         0052d305     MOV        EAX,0x1
//                              tvw_main.cpp:313 (22)
//         0052d30a     POP        EDI
//         0052d30b     POP        ESI
//         0052d30c     POP        EBP
//         0052d30d     POP        EBX
//         0052d30e     ADD        ESP,0x14
//         0052d311     RET        0xc
//                               LAB_0052d314                                                 XREF[6]:     0052d200(j), 0052d24f(j),
//                                                                                                         0052d271(j), 0052d285(j),
//                                                                                                         0052d2cd(j), 0052d303(j)
//         0052d314     POP        EDI
//         0052d315     POP        ESI
//         0052d316     POP        EBP
//         0052d317     XOR        EAX,EAX
//         0052d319     POP        EBX
//         0052d31a     ADD        ESP,0x14
//         0052d31d     RET        0xc
    return 0;
}

int TRIBE_Main_View::command_place_multi_object(long param_1, long param_2, long param_3, long param_4, int param_5) {
    /* TODO: Stub */
//                              int __thiscall command_place_multi_object(TRIBE_Main_View * this, lo
//              int               EAX:4          <RETURN>
//              TRIBE_Main_Vie    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[3]:     0052d389(R), 0052d3c9(R), 0052d49a(R)
//              long              Stack[0x8]:4   param_2                   XREF[2]:     0052d37d(R), 0052d495(R)
//              long              Stack[0xc]:4   param_3                   XREF[2]:     0052d383(R), 0052d490(R)
//              long              Stack[0x10]:4  param_4                   XREF[4]:     0052d379(R), 0052d392(W), 0052d39f(R), 0052d48b(R)
//              int               Stack[0x14]:4  param_5                   XREF[8]:     0052d36f(W), 0052d3b2(R), 0052d3d1(R), 0052d400(R),
//                                                                                     0052d417(R), 0052d432(R), 0052d458(R), 0052d4b4(R)
//                               ?command_place_multi_object@TRIBE_Main_View@@UAEHJJJJH@Z     XREF[1]:     00572bb4(*)
//                               TRIBE_Main_View::command_place_multi_object
//                              tvw_main.cpp:319 (15)
//         0052d320     MOV        EAX,[allow_user_commands]                        = 1h
//         0052d325     PUSH       ESI
//         0052d326     PUSH       EDI
//         0052d327     XOR        EDI,EDI
//         0052d329     TEST       EAX,EAX
//         0052d32b     MOV        ESI,this
//         0052d32d     JNZ        LAB_0052d336
//                              tvw_main.cpp:324 (2)
//         0052d32f     XOR        EAX,EAX
//                              tvw_main.cpp:376 (5)
//         0052d331     POP        EDI
//         0052d332     POP        ESI
//         0052d333     RET        0x14
//                               LAB_0052d336                                                 XREF[1]:     0052d32d(j)
//                              tvw_main.cpp:326 (8)
//         0052d336     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         0052d33c     PUSH       EBP
//         0052d33d     PUSH       EBX
//                              tvw_main.cpp:328 (22)
//         0052d33e     MOV        this,dword ptr [EDX + 0x1b0]
//         0052d344     MOV        AX,word ptr [EDX + 0x3fc]
//         0052d34b     CMP        this,0x7
//         0052d34e     JNZ        LAB_0052d472
//                              tvw_main.cpp:330 (37)
//         0052d354     CMP        AX,0xffff
//         0052d358     JZ         LAB_0052d4c7
//         0052d35e     MOV        this,dword ptr [ESI + 0x100]
//         0052d364     MOVSX      EAX,AX
//         0052d367     MOV        this,dword ptr [ECX + this->field36_0x24]
//         0052d36a     MOV        EAX,dword ptr [this->field0_0x0 + EAX*0x4]
//         0052d36d     TEST       EAX,EAX
//         0052d36f     MOV        dword ptr [ESP + param_5],EAX
//         0052d373     JZ         LAB_0052d4c7
//                              tvw_main.cpp:334 (46)
//         0052d379     MOV        EDI,dword ptr [ESP + param_4]
//         0052d37d     MOV        EBP,dword ptr [ESP + param_2]
//         0052d381     MOV        EAX,EDI
//         0052d383     MOV        EBX,dword ptr [ESP + param_3]
//         0052d387     SUB        EAX,EBP
//         0052d389     MOV        this,dword ptr [ESP + param_1]
//         0052d38d     CDQ
//         0052d38e     XOR        EAX,EDX
//         0052d390     SUB        EAX,EDX
//         0052d392     MOV        dword ptr [ESP + param_4],EAX
//         0052d396     MOV        EAX,EBX
//         0052d398     SUB        EAX,this
//         0052d39a     CDQ
//         0052d39b     XOR        EAX,EDX
//         0052d39d     SUB        EAX,EDX
//         0052d39f     MOV        EDX,dword ptr [ESP + param_4]
//         0052d3a3     CMP        EDX,EAX
//         0052d3a5     JNZ        LAB_0052d3b0
//                              tvw_main.cpp:337 (4)
//         0052d3a7     PUSH       EDI
//         0052d3a8     PUSH       EBX
//         0052d3a9     PUSH       EBP
//         0052d3aa     PUSH       this
//                              tvw_main.cpp:339 (7)
//         0052d3ab     JMP        LAB_0052d458
//                               LAB_0052d3b0                                                 XREF[1]:     0052d3a5(j)
//         0052d3b0     JL         LAB_0052d417
//                              tvw_main.cpp:342 (23)
//         0052d3b2     MOV        EAX,dword ptr [ESP + param_5]
//         0052d3b6     PUSH       EDI
//         0052d3b7     PUSH       this
//         0052d3b8     PUSH       EBP
//         0052d3b9     PUSH       this
//         0052d3ba     PUSH       EAX
//         0052d3bb     MOV        EAX,dword ptr [ESI + 0x100]
//         0052d3c1     MOV        this,ESI
//         0052d3c3     PUSH       EAX
//         0052d3c4     CALL       TRIBE_Main_View::place_line_of_walls             void place_line_of_walls(TRIBE_Main_View * th
//                              tvw_main.cpp:343 (8)
//         0052d3c9     MOV        EAX,dword ptr [ESP + param_1]
//         0052d3cd     CMP        EAX,EBX
//         0052d3cf     JGE        LAB_0052d3f3
//                              tvw_main.cpp:344 (17)
//         0052d3d1     MOV        this,dword ptr [ESP + param_5]
//         0052d3d5     MOV        EDX,dword ptr [ESI + 0x100]
//         0052d3db     PUSH       EDI
//         0052d3dc     PUSH       EBX
//         0052d3dd     INC        EAX
//         0052d3de     PUSH       EDI
//         0052d3df     PUSH       EAX
//         0052d3e0     PUSH       this
//         0052d3e1     PUSH       EDX
//                              tvw_main.cpp:355 (7)
//         0052d3e2     MOV        this,ESI
//         0052d3e4     CALL       TRIBE_Main_View::place_line_of_walls             void place_line_of_walls(TRIBE_Main_View * th
//                              tvw_main.cpp:358 (5)
//         0052d3e9     MOV        EDI,0x1
//                              tvw_main.cpp:361 (5)
//         0052d3ee     JMP        LAB_0052d4c7
//                               LAB_0052d3f3                                                 XREF[1]:     0052d3cf(j)
//                              tvw_main.cpp:345 (2)
//         0052d3f3     JLE        LAB_0052d46b
//                              tvw_main.cpp:346 (17)
//         0052d3f5     MOV        this,dword ptr [ESI + 0x100]
//         0052d3fb     PUSH       EDI
//         0052d3fc     PUSH       EBX
//         0052d3fd     DEC        EAX
//         0052d3fe     PUSH       EDI
//         0052d3ff     PUSH       EAX
//         0052d400     MOV        EAX,dword ptr [ESP + param_5]
//         0052d404     PUSH       EAX
//         0052d405     PUSH       this
//                              tvw_main.cpp:355 (7)
//         0052d406     MOV        this,ESI
//         0052d408     CALL       TRIBE_Main_View::place_line_of_walls             void place_line_of_walls(TRIBE_Main_View * th
//                              tvw_main.cpp:358 (5)
//         0052d40d     MOV        EDI,0x1
//                              tvw_main.cpp:361 (5)
//         0052d412     JMP        LAB_0052d4c7
//                               LAB_0052d417                                                 XREF[1]:     0052d3b0(j)
//                              tvw_main.cpp:351 (23)
//         0052d417     MOV        EDX,dword ptr [ESP + param_5]
//         0052d41b     MOV        EAX,dword ptr [ESI + 0x100]
//         0052d421     PUSH       EBP
//         0052d422     PUSH       EBX
//         0052d423     PUSH       EBP
//         0052d424     PUSH       this
//         0052d425     PUSH       EDX
//         0052d426     PUSH       EAX
//         0052d427     MOV        this,ESI
//         0052d429     CALL       TRIBE_Main_View::place_line_of_walls             void place_line_of_walls(TRIBE_Main_View * th
//                              tvw_main.cpp:352 (4)
//         0052d42e     CMP        EBP,EDI
//         0052d430     JGE        LAB_0052d451
//                              tvw_main.cpp:353 (17)
//         0052d432     MOV        EAX,dword ptr [ESP + param_5]
//         0052d436     MOV        this,dword ptr [ESI + 0x100]
//         0052d43c     PUSH       EDI
//         0052d43d     INC        EBP
//         0052d43e     PUSH       EBX
//         0052d43f     PUSH       EBP
//         0052d440     PUSH       EBX
//         0052d441     PUSH       EAX
//         0052d442     PUSH       this
//                              tvw_main.cpp:355 (7)
//         0052d443     MOV        this,ESI
//         0052d445     CALL       TRIBE_Main_View::place_line_of_walls             void place_line_of_walls(TRIBE_Main_View * th
//                              tvw_main.cpp:358 (5)
//         0052d44a     MOV        EDI,0x1
//                              tvw_main.cpp:361 (2)
//         0052d44f     JMP        LAB_0052d4c7
//                               LAB_0052d451                                                 XREF[1]:     0052d430(j)
//                              tvw_main.cpp:354 (2)
//         0052d451     JLE        LAB_0052d46b
//                              tvw_main.cpp:355 (24)
//         0052d453     PUSH       EDI
//         0052d454     DEC        EBP
//         0052d455     PUSH       EBX
//         0052d456     PUSH       EBP
//         0052d457     PUSH       EBX
//                               LAB_0052d458                                                 XREF[1]:     0052d3ab(j)
//         0052d458     MOV        EDX,dword ptr [ESP + param_5]
//         0052d45c     MOV        EAX,dword ptr [ESI + 0x100]
//         0052d462     PUSH       EDX
//         0052d463     PUSH       EAX
//         0052d464     MOV        this,ESI
//         0052d466     CALL       TRIBE_Main_View::place_line_of_walls             void place_line_of_walls(TRIBE_Main_View * th
//                               LAB_0052d46b                                                 XREF[2]:     0052d3f3(j), 0052d451(j)
//                              tvw_main.cpp:358 (5)
//         0052d46b     MOV        EDI,0x1
//                              tvw_main.cpp:361 (2)
//         0052d470     JMP        LAB_0052d4c7
//                               LAB_0052d472                                                 XREF[1]:     0052d34e(j)
//                              tvw_main.cpp:363 (25)
//         0052d472     CMP        AX,0xffff
//         0052d476     JZ         LAB_0052d4b4
//         0052d478     MOV        this,dword ptr [ESI + 0x100]
//         0052d47e     MOVSX      EBX,AX
//         0052d481     MOV        EBP,dword ptr [ECX + this->field36_0x24]
//         0052d484     CMP        dword ptr [EBP + EBX*0x4],0x0
//         0052d489     JZ         LAB_0052d4b4
//                              tvw_main.cpp:365 (30)
//         0052d48b     MOV        EDX,dword ptr [ESP + param_4]
//         0052d48f     PUSH       EDX
//         0052d490     MOV        EDX,dword ptr [ESP + param_3]
//         0052d494     PUSH       EDX
//         0052d495     MOV        EDX,dword ptr [ESP + param_2]
//         0052d499     PUSH       EDX
//         0052d49a     MOV        EDX,dword ptr [ESP + param_1]
//         0052d49e     PUSH       EDX
//         0052d49f     PUSH       EAX
//         0052d4a0     CALL       TRIBE_Player::command_make_wall                  uchar command_make_wall(TRIBE_Player * this,
//         0052d4a5     TEST       AL,AL
//         0052d4a7     JZ         LAB_0052d4ae
//                              tvw_main.cpp:366 (11)
//         0052d4a9     MOV        EDI,0x1
//                               LAB_0052d4ae                                                 XREF[1]:     0052d4a7(j)
//         0052d4ae     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//                               LAB_0052d4b4                                                 XREF[2]:     0052d476(j), 0052d489(j)
//                              tvw_main.cpp:368 (8)
//         0052d4b4     MOV        EAX,dword ptr [ESP + param_5]
//         0052d4b8     TEST       EAX,EAX
//         0052d4ba     JZ         LAB_0052d4c7
//                              tvw_main.cpp:369 (11)
//         0052d4bc     MOV        EAX,dword ptr [EDX]
//         0052d4be     PUSH       0x0
//         0052d4c0     PUSH       0x0
//         0052d4c2     MOV        this,EDX
//         0052d4c4     CALL       dword ptr [EAX + 0x10]
//                               LAB_0052d4c7                                                 XREF[7]:     0052d358(j), 0052d373(j),
//                                                                                                         0052d3ee(j), 0052d412(j),
//                                                                                                         0052d44f(j), 0052d470(j),
//                                                                                                         0052d4ba(j)
//                              tvw_main.cpp:372 (15)
//         0052d4c7     PUSH       -0x1
//         0052d4c9     PUSH       -0x1
//         0052d4cb     PUSH       -0x1
//         0052d4cd     PUSH       -0x1
//         0052d4cf     MOV        this,ESI
//         0052d4d1     CALL       RGE_View::set_selection_area                     void set_selection_area(RGE_View * this, long
//                              tvw_main.cpp:373 (10)
//         0052d4d6     MOV        EDX,dword ptr [ESI]
//         0052d4d8     PUSH       0x1
//         0052d4da     MOV        this,ESI
//         0052d4dc     CALL       dword ptr [EDX + 0x20]
//         0052d4df     POP        EBX
//                              tvw_main.cpp:375 (3)
//         0052d4e0     MOV        EAX,EDI
//         0052d4e2     POP        EBP
//                              tvw_main.cpp:376 (5)
//         0052d4e3     POP        EDI
//         0052d4e4     POP        ESI
//         0052d4e5     RET        0x14
//         0052d4e8     ??         90h
//         0052d4e9     NOP
//         0052d4ea     NOP
//         0052d4eb     NOP
//         0052d4ec     NOP
//         0052d4ed     NOP
//         0052d4ee     NOP
//         0052d4ef     NOP
    return 0;
}

void TRIBE_Main_View::place_line_of_walls(TRIBE_Player* param_1, TRIBE_Master_Building_Object* param_2, int param_3, int param_4, int param_5, int param_6) {
    /* TODO: Stub */
//                              void __thiscall place_line_of_walls(TRIBE_Main_View * this, TRIBE_Pl
//              void              <VOID>         <RETURN>
//              TRIBE_Main_Vie    ECX:4 (auto)   this
//              TRIBE_Player *    Stack[0x4]:4   param_1                   XREF[3]:     0052d547(R), 0052d578(W), 0052d580(R)
//              TRIBE_Master_B    Stack[0x8]:4   param_2                   XREF[3]:     0052d543(R), 0052d58a(W), 0052d58e(R)
//              int               Stack[0xc]:4   param_3                   XREF[3]:     0052d4f0(R), 0052d54b(W), 0052d57c(R)
//              int               Stack[0x10]:4  param_4                   XREF[3]:     0052d51d(R), 0052d54f(W), 0052d55c(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     0052d4f4(R)
//              int               Stack[0x18]:4  param_6                   XREF[1]:     0052d521(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0052d558(W), 0052d595(R)
//              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0052d529(W), 0052d53f(W)
//              int               Stack[-0xc]:4  y_skip                    XREF[2]:     0052d503(W), 0052d519(W)
//              int               Stack[-0x10]:4 x_skip
//                               ?place_line_of_walls@TRIBE_Main_View@@IAEXPAVTRIBE_Player@@  XREF[6]:     command_place_multi_object:0052d3c
//                               TRIBE_Main_View::place_line_of_walls                                      command_place_multi_object:0052d3e
//                                                                                                         command_place_multi_object:0052d40
//                                                                                                         command_place_multi_object:0052d42
//                                                                                                         command_place_multi_object:0052d44
//                                                                                                         command_place_multi_object:0052d46
//                              tvw_main.cpp:382 (19)
//         0052d4f0     MOV        this,dword ptr [ESP + param_3]
//         0052d4f4     MOV        EAX,dword ptr [ESP + param_5]
//         0052d4f8     SUB        ESP,0xc
//         0052d4fb     CMP        this,EAX
//         0052d4fd     PUSH       EBX
//         0052d4fe     PUSH       EBP
//         0052d4ff     PUSH       ESI
//         0052d500     PUSH       EDI
//         0052d501     JNZ        LAB_0052d50d
//                              tvw_main.cpp:388 (8)
//         0052d503     MOV        dword ptr [ESP + y_skip],0x0
//                              tvw_main.cpp:389 (18)
//         0052d50b     JMP        LAB_0052d51d
//                               LAB_0052d50d                                                 XREF[1]:     0052d501(j)
//         0052d50d     XOR        EDX,EDX
//         0052d50f     CMP        EAX,this
//         0052d511     SETLE      DL
//         0052d514     DEC        EDX
//         0052d515     AND        EDX,0x2
//         0052d518     DEC        EDX
//         0052d519     MOV        dword ptr [ESP + y_skip],EDX
//                               LAB_0052d51d                                                 XREF[1]:     0052d50b(j)
//                              tvw_main.cpp:394 (12)
//         0052d51d     MOV        EAX,dword ptr [ESP + param_4]
//         0052d521     MOV        ESI,dword ptr [ESP + param_6]
//         0052d525     CMP        EAX,ESI
//         0052d527     JNZ        LAB_0052d533
//                              tvw_main.cpp:395 (8)
//         0052d529     MOV        dword ptr [ESP + local_8],0x0
//                              tvw_main.cpp:396 (18)
//         0052d531     JMP        LAB_0052d543
//                               LAB_0052d533                                                 XREF[1]:     0052d527(j)
//         0052d533     XOR        EDX,EDX
//         0052d535     CMP        ESI,EAX
//         0052d537     SETLE      DL
//         0052d53a     DEC        EDX
//         0052d53b     AND        EDX,0x2
//         0052d53e     DEC        EDX
//         0052d53f     MOV        dword ptr [ESP + local_8],EDX
//                               LAB_0052d543                                                 XREF[1]:     0052d531(j)
//                              tvw_main.cpp:409 (90)
//         0052d543     MOV        ESI,dword ptr [ESP + param_2]
//         0052d547     MOV        EDI,dword ptr [ESP + param_1]
//         0052d54b     MOV        dword ptr [ESP + param_3],EAX
//         0052d54f     MOV        dword ptr [ESP + param_4],this
//         0052d553     MOV        EAX,dword ptr [ESI]
//         0052d555     MOV        this,dword ptr [EAX + 0x20]
//         0052d558     MOV        dword ptr [ESP + local_4],this
//                               LAB_0052d55c                                                 XREF[1]:     0052d5e2(j)
//         0052d55c     FILD       dword ptr [ESP + param_4]
//         0052d560     MOV        DL,byte ptr [ESI + 0x64]
//         0052d563     PUSH       0x1
//         0052d565     PUSH       offset DAT_fffffff8
//         0052d567     PUSH       offset DAT_fffffff4
//         0052d569     FSUB       float ptr [DAT_00577450]                         = align(3)
//         0052d56f     PUSH       0x0=>DAT_fffffff0
//         0052d571     PUSH       EDX
//         0052d572     PUSH       0x1
//         0052d574     PUSH       0x0
//         0052d576     MOV        this,ESI
//         0052d578     FSTP       float ptr [ESP + param_1]
//         0052d57c     FILD       dword ptr [ESP + param_3]
//         0052d580     MOV        EBP,dword ptr [ESP + param_1]
//         0052d584     FSUB       float ptr [DAT_00577450]                         = align(3)
//         0052d58a     FSTP       float ptr [ESP + param_2]
//         0052d58e     MOV        EBX,dword ptr [ESP + param_2]
//         0052d592     PUSH       EBX
//         0052d593     PUSH       EBP
//         0052d594     PUSH       EDI
//         0052d595     CALL       dword ptr [ESP + local_4]
//         0052d599     TEST       AL,AL
//         0052d59b     JNZ        LAB_0052d5b2
//                              tvw_main.cpp:410 (21)
//         0052d59d     MOVSX      this,word ptr [ESI + 0x10]
//         0052d5a1     MOV        EAX,dword ptr [EDI]
//         0052d5a3     PUSH       0x1
//         0052d5a5     PUSH       0x0=>DAT_fffffff8
//         0052d5a7     PUSH       EBX=>DAT_fffffff4
//         0052d5a8     PUSH       EBP=>DAT_fffffff0
//         0052d5a9     PUSH       this
//         0052d5aa     MOV        this,EDI
//         0052d5ac     CALL       dword ptr [EAX + 0x94]
//                               LAB_0052d5b2                                                 XREF[1]:     0052d59b(j)
//                              tvw_main.cpp:412 (24)
//         0052d5b2     MOV        EAX,dword ptr [ESP + 0x2c]
//         0052d5b6     MOV        this,dword ptr [ESP + 0x30]
//         0052d5ba     CMP        EAX,this
//         0052d5bc     JNZ        LAB_0052d5ca
//         0052d5be     MOV        EDX,dword ptr [ESP + 0x28]
//         0052d5c2     MOV        this,dword ptr [ESP + 0x34]
//         0052d5c6     CMP        EDX,this
//         0052d5c8     JZ         LAB_0052d5e7
//                               LAB_0052d5ca                                                 XREF[1]:     0052d5bc(j)
//                              tvw_main.cpp:415 (4)
//         0052d5ca     MOV        EDX,dword ptr [ESP + 0x10]
//                              tvw_main.cpp:416 (25)
//         0052d5ce     MOV        this,dword ptr [ESP + 0x28]
//         0052d5d2     ADD        EAX,EDX
//         0052d5d4     MOV        dword ptr [ESP + 0x2c],EAX
//         0052d5d8     MOV        EAX,dword ptr [ESP + 0x14]
//         0052d5dc     ADD        this,EAX
//         0052d5de     MOV        dword ptr [ESP + 0x28],this
//         0052d5e2     JMP        LAB_0052d55c
//                               LAB_0052d5e7                                                 XREF[1]:     0052d5c8(j)
//                              tvw_main.cpp:418 (10)
//         0052d5e7     POP        EDI
//         0052d5e8     POP        ESI
//         0052d5e9     POP        EBP
//         0052d5ea     POP        EBX
//         0052d5eb     ADD        ESP,0xc
//         0052d5ee     RET        0x18
//         0052d5f1     ??         90h
//         0052d5f2     NOP
//         0052d5f3     NOP
//         0052d5f4     NOP
//         0052d5f5     NOP
//         0052d5f6     NOP
//         0052d5f7     NOP
//         0052d5f8     NOP
//         0052d5f9     NOP
//         0052d5fa     NOP
//         0052d5fb     NOP
//         0052d5fc     NOP
//         0052d5fd     NOP
//         0052d5fe     NOP
//         0052d5ff     NOP
    return;
}

long TRIBE_Main_View::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              long __thiscall mouse_left_up_action(TRIBE_Main_View * this, long pa
//              long              EAX:4          <RETURN>
//              TRIBE_Main_Vie    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[7]:     0052d67b(R), 0052d728(R), 0052d777(R), 0052d7a7(R),
//                                                                                     0052d806(R), 0052d844(R), 0052d8b9(R)
//              long              Stack[0x8]:4   param_2                   XREF[7]:     0052d677(R), 0052d724(R), 0052d772(R), 0052d7a3(R),
//                                                                                     0052d802(R), 0052d840(R), 0052d8b5(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0052d76e(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0052d76a(R)
//              RGE_Pick_Info     Stack[-0x18]   pick_info                 XREF[0,8]:   0052d681(*), 0052d69d(*), 0052d6ad(R), 0052d8bf(*),
//                                                                                     0052d8db(*), 0052d8eb(R), 0052d6a9(R), 0052d8e7(R)
//                               ?mouse_left_up_action@TRIBE_Main_View@@UAEJJJHH@Z            XREF[1]:     00572b38(*)
//                               TRIBE_Main_View::mouse_left_up_action
//                              tvw_main.cpp:424 (8)
//         0052d600     SUB        ESP,0x14
//         0052d603     PUSH       EBX
//         0052d604     PUSH       ESI
//         0052d605     MOV        ESI,this
//         0052d607     PUSH       EDI
//                              tvw_main.cpp:427 (32)
//         0052d608     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052d60e     MOV        EAX,dword ptr [ECX + this->field432_0x1b0]
//         0052d614     CMP        EAX,0x4
//         0052d617     JZ         LAB_0052d633
//         0052d619     CMP        EAX,0x6
//         0052d61c     JZ         LAB_0052d633
//         0052d61e     CMP        EAX,0x7
//         0052d621     JZ         LAB_0052d633
//         0052d623     CMP        EAX,0x5
//         0052d626     JZ         LAB_0052d633
//                              tvw_main.cpp:428 (2)
//         0052d628     XOR        EAX,EAX
//                              tvw_main.cpp:534 (9)
//         0052d62a     POP        EDI
//         0052d62b     POP        ESI
//         0052d62c     POP        EBX
//         0052d62d     ADD        ESP,0x14
//         0052d630     RET        0x10
//                               LAB_0052d633                                                 XREF[4]:     0052d617(j), 0052d61c(j),
//                                                                                                         0052d621(j), 0052d626(j)
//                              tvw_main.cpp:430 (13)
//         0052d633     CALL       RGE_Base_Game::get_paused                        int get_paused(RGE_Base_Game * this)
//         0052d638     TEST       EAX,EAX
//         0052d63a     JNZ        switchD_0052d657::default
//                              tvw_main.cpp:432 (30)
//         0052d640     MOV        EAX,[rge_base_game]                              = 00000000
//         0052d645     MOV        EAX,dword ptr [EAX + 0x1b4]
//         0052d64b     ADD        EAX,-0x64
//         0052d64e     CMP        EAX,0x5
//         0052d651     JA         switchD_0052d657::default
//                               switchD_0052d657::switchD
//         0052d657     JMP        dword ptr [EAX*0x4 + switchD_0052d657::switchd   = 0052d65e
//                               switchD_0052d657::caseD_64                                   XREF[2]:     0052d657(j), 0052d94c(*)
//                              tvw_main.cpp:435 (7)
//         0052d65e     MOV        this,ESI
//         0052d660     CALL       TPanel::release_mouse                            void release_mouse(TPanel * this)
//                              tvw_main.cpp:436 (18)
//         0052d665     MOV        AL,byte ptr [ESI + 0xec]
//         0052d66b     CMP        AL,0x1
//         0052d66d     JZ         LAB_0052d677
//         0052d66f     CMP        AL,0x2
//         0052d671     JNZ        LAB_0052d75c
//                               LAB_0052d677                                                 XREF[1]:     0052d66d(j)
//                              tvw_main.cpp:438 (38)
//         0052d677     MOV        EDI,dword ptr [ESP + param_2]
//         0052d67b     MOV        EBX,dword ptr [ESP + param_1]
//         0052d67f     PUSH       0x1
//         0052d681     LEA        this=>pick_info.y,[ESP + 0x10]
//         0052d685     PUSH       0x0
//         0052d687     PUSH       this
//         0052d688     PUSH       EDI
//         0052d689     PUSH       EBX
//         0052d68a     PUSH       0x0
//         0052d68c     PUSH       0x28
//         0052d68e     MOV        this,ESI
//         0052d690     CALL       RGE_Main_View::pick1                             uchar pick1(RGE_Main_View * this, uchar param
//         0052d695     CMP        AL,0x33
//         0052d697     JNZ        LAB_0052d7bf
//                              tvw_main.cpp:440 (12)
//         0052d69d     LEA        EDX=>pick_info.y,[ESP + 0xc]
//         0052d6a1     MOV        this,ESI
//         0052d6a3     PUSH       EDX
//         0052d6a4     CALL       RGE_Main_View::fixup_pick_info                   void fixup_pick_info(RGE_Main_View * this, RG
//                              tvw_main.cpp:441 (23)
//         0052d6a9     MOV        EAX,dword ptr [ESP + pick_info.scr_x]
//         0052d6ad     MOV        this,dword ptr [ESP + pick_info.y]
//         0052d6b1     PUSH       EAX
//         0052d6b2     PUSH       this
//         0052d6b3     MOV        this,dword ptr [ESI + 0x100]
//         0052d6b9     CALL       TRIBE_Player::command_attack_ground              uchar command_attack_ground(TRIBE_Player * th
//         0052d6be     TEST       AL,AL
//                              tvw_main.cpp:443 (6)
//         0052d6c0     JZ         LAB_0052d7bf
//                              tvw_main.cpp:445 (9)
//         0052d6c6     PUSH       0x2
//         0052d6c8     MOV        this,ESI
//         0052d6ca     CALL       RGE_Main_View::reset_display_object_selection    void reset_display_object_selection(RGE_Main_
//                              tvw_main.cpp:446 (50)
//         0052d6cf     MOV        EDX,dword ptr [ESI + 0x134]
//         0052d6d5     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052d6db     MOV        EAX,dword ptr [ESI + 0x130]
//                              language.dll match for 0x7d: "Arial"
//         0052d6e1     PUSH       0x7d
//         0052d6e3     PUSH       0x2
//         0052d6e5     PUSH       0x0
//         0052d6e7     PUSH       0xf
//         0052d6e9     ADD        EDX,EDI
//         0052d6eb     PUSH       0x0
//         0052d6ed     PUSH       EDX
//         0052d6ee     MOV        EDX,dword ptr [ECX + this->field92_0x5c]
//         0052d6f1     ADD        EAX,EBX
//         0052d6f3     PUSH       EAX
//         0052d6f4     PUSH       0x0
//         0052d6f6     MOV        EAX,dword ptr [EDX + 0x8]
//         0052d6f9     MOV        this,ESI
//         0052d6fb     PUSH       EAX
//         0052d6fc     CALL       RGE_View::add_overlay_sprite                     void add_overlay_sprite(RGE_View * this, TSha
//                              tvw_main.cpp:447 (9)
//         0052d701     MOV        EDX,dword ptr [ESI]
//         0052d703     PUSH       0x1
//         0052d705     MOV        this,ESI
//         0052d707     CALL       dword ptr [EDX + 0x20]
//                              tvw_main.cpp:450 (5)
//         0052d70a     JMP        LAB_0052d7cc
//                               switchD_0052d657::caseD_66                                   XREF[2]:     0052d657(j), 0052d954(*)
//                              tvw_main.cpp:457 (7)
//         0052d70f     MOV        this,ESI
//         0052d711     CALL       TPanel::release_mouse                            void release_mouse(TPanel * this)
//                              tvw_main.cpp:458 (14)
//         0052d716     MOV        AL,byte ptr [ESI + 0xec]
//         0052d71c     CMP        AL,0x1
//         0052d71e     JZ         LAB_0052d724
//         0052d720     CMP        AL,0x2
//         0052d722     JNZ        LAB_0052d75c
//                               LAB_0052d724                                                 XREF[1]:     0052d71e(j)
//                              tvw_main.cpp:460 (28)
//         0052d724     MOV        EAX,dword ptr [ESP + param_2]
//         0052d728     MOV        this,dword ptr [ESP + param_1]
//         0052d72c     MOV        EDX,dword ptr [ESI]
//         0052d72e     PUSH       0x69
//         0052d730     PUSH       0x0
//         0052d732     PUSH       EAX
//         0052d733     PUSH       this
//         0052d734     MOV        this,ESI
//         0052d736     CALL       dword ptr [EDX + 0x100]
//         0052d73c     TEST       EAX,EAX
//         0052d73e     JNZ        LAB_0052d74d
//                               LAB_0052d740                                                 XREF[5]:     0052d822(j), 0052d859(j),
//                                                                                                         0052d86d(j), 0052d8d5(j),
//                                                                                                         0052d8fe(j)
//                              tvw_main.cpp:526 (13)
//         0052d740     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052d746     PUSH       0x3
//         0052d748     CALL       RGE_Base_Game::play_sound                        int play_sound(RGE_Base_Game * this, int para
//                               LAB_0052d74d                                                 XREF[4]:     0052d73e(j), 0052d81c(j),
//                                                                                                         0052d897(j), 0052d947(j)
//                              tvw_main.cpp:527 (15)
//         0052d74d     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052d753     PUSH       0x0
//         0052d755     PUSH       0x0=>DAT_fffffff8
//         0052d757     MOV        EDX,dword ptr [this->field0_0x0]
//         0052d759     CALL       dword ptr [EDX + 0x10]
//                               LAB_0052d75c                                                 XREF[6]:     0052d671(j), 0052d722(j),
//                                                                                                         0052d7a1(j), 0052d7fc(j),
//                                                                                                         0052d83a(j), 0052d8af(j)
//                              tvw_main.cpp:529 (5)
//         0052d75c     MOV        EAX,0x1
//                              tvw_main.cpp:534 (9)
//         0052d761     POP        EDI
//         0052d762     POP        ESI
//         0052d763     POP        EBX
//         0052d764     ADD        ESP,0x14
//         0052d767     RET        0x10
//                               switchD_0052d657::default                                    XREF[2]:     0052d63a(j), 0052d651(j)
//                              tvw_main.cpp:533 (27)
//         0052d76a     MOV        EAX,dword ptr [ESP + param_4]
//         0052d76e     MOV        this,dword ptr [ESP + param_3]
//         0052d772     MOV        EDX,dword ptr [ESP + param_2]
//         0052d776     PUSH       EAX
//         0052d777     MOV        EAX,dword ptr [ESP + param_1]
//         0052d77b     PUSH       this
//         0052d77c     PUSH       EDX
//         0052d77d     PUSH       EAX
//         0052d77e     MOV        this,ESI
//         0052d780     CALL       RGE_Main_View::mouse_left_up_action              long mouse_left_up_action(RGE_Main_View * thi
//                              tvw_main.cpp:534 (9)
//         0052d785     POP        EDI
//         0052d786     POP        ESI
//         0052d787     POP        EBX
//         0052d788     ADD        ESP,0x14
//         0052d78b     RET        0x10
//                               switchD_0052d657::caseD_65                                   XREF[2]:     0052d657(j), 0052d950(*)
//                              tvw_main.cpp:467 (7)
//         0052d78e     MOV        this,ESI
//         0052d790     CALL       TPanel::release_mouse                            void release_mouse(TPanel * this)
//                              tvw_main.cpp:468 (14)
//         0052d795     MOV        AL,byte ptr [ESI + 0xec]
//         0052d79b     CMP        AL,0x1
//         0052d79d     JZ         LAB_0052d7a3
//         0052d79f     CMP        AL,0x2
//         0052d7a1     JNZ        LAB_0052d75c
//                               LAB_0052d7a3                                                 XREF[1]:     0052d79d(j)
//                              tvw_main.cpp:470 (28)
//         0052d7a3     MOV        this,dword ptr [ESP + param_2]
//         0052d7a7     MOV        EDX,dword ptr [ESP + param_1]
//         0052d7ab     MOV        EAX,dword ptr [ESI]
//                              language.dll match for 0x68: "Arial"
//         0052d7ad     PUSH       0x68
//         0052d7af     PUSH       0x0
//         0052d7b1     PUSH       this
//         0052d7b2     PUSH       EDX
//         0052d7b3     MOV        this,ESI
//         0052d7b5     CALL       dword ptr [EAX + 0x100]
//         0052d7bb     TEST       EAX,EAX
//         0052d7bd     JNZ        LAB_0052d7cc
//                               LAB_0052d7bf                                                 XREF[2]:     0052d697(j), 0052d6c0(j)
//                              tvw_main.cpp:471 (13)
//         0052d7bf     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052d7c5     PUSH       0x3
//         0052d7c7     CALL       RGE_Base_Game::play_sound                        int play_sound(RGE_Base_Game * this, int para
//                               LAB_0052d7cc                                                 XREF[2]:     0052d70a(j), 0052d7bd(j)
//                              tvw_main.cpp:472 (15)
//         0052d7cc     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052d7d2     PUSH       0x0
//         0052d7d4     PUSH       0x0=>DAT_fffffff8
//         0052d7d6     MOV        EAX,dword ptr [this->field0_0x0]
//         0052d7d8     CALL       dword ptr [EAX + 0x10]
//                              tvw_main.cpp:534 (14)
//         0052d7db     POP        EDI
//         0052d7dc     POP        ESI
//         0052d7dd     MOV        EAX,0x1
//         0052d7e2     POP        EBX
//         0052d7e3     ADD        ESP,0x14
//         0052d7e6     RET        0x10
//                               switchD_0052d657::caseD_67                                   XREF[2]:     0052d657(j), 0052d958(*)
//                              tvw_main.cpp:477 (7)
//         0052d7e9     MOV        this,ESI
//         0052d7eb     CALL       TPanel::release_mouse                            void release_mouse(TPanel * this)
//                              tvw_main.cpp:478 (18)
//         0052d7f0     MOV        AL,byte ptr [ESI + 0xec]
//         0052d7f6     CMP        AL,0x1
//         0052d7f8     JZ         LAB_0052d802
//         0052d7fa     CMP        AL,0x2
//         0052d7fc     JNZ        LAB_0052d75c
//                               LAB_0052d802                                                 XREF[1]:     0052d7f8(j)
//                              tvw_main.cpp:480 (32)
//         0052d802     MOV        EAX,dword ptr [ESP + param_2]
//         0052d806     MOV        this,dword ptr [ESP + param_1]
//         0052d80a     MOV        EDX,dword ptr [ESI]
//         0052d80c     PUSH       0x7
//         0052d80e     PUSH       0x0
//         0052d810     PUSH       EAX
//         0052d811     PUSH       this
//         0052d812     MOV        this,ESI
//         0052d814     CALL       dword ptr [EDX + 0x100]
//         0052d81a     TEST       EAX,EAX
//         0052d81c     JNZ        LAB_0052d74d
//                              tvw_main.cpp:484 (5)
//         0052d822     JMP        LAB_0052d740
//                               switchD_0052d657::caseD_68                                   XREF[2]:     0052d657(j), 0052d95c(*)
//                              tvw_main.cpp:487 (7)
//         0052d827     MOV        this,ESI
//         0052d829     CALL       TPanel::release_mouse                            void release_mouse(TPanel * this)
//                              tvw_main.cpp:488 (18)
//         0052d82e     MOV        AL,byte ptr [ESI + 0xec]
//         0052d834     CMP        AL,0x1
//         0052d836     JZ         LAB_0052d840
//         0052d838     CMP        AL,0x2
//         0052d83a     JNZ        LAB_0052d75c
//                               LAB_0052d840                                                 XREF[1]:     0052d836(j)
//                              tvw_main.cpp:491 (23)
//         0052d840     MOV        EAX,dword ptr [ESP + param_2]
//         0052d844     MOV        this,dword ptr [ESP + param_1]
//         0052d848     PUSH       -0x1
//         0052d84a     PUSH       0x0
//         0052d84c     PUSH       EAX
//         0052d84d     PUSH       this
//         0052d84e     MOV        this,ESI
//         0052d850     CALL       RGE_Main_View::pick_best_target                  RGE_Static_Object * pick_best_target(RGE_Main
//         0052d855     MOV        EDI,EAX
//                              tvw_main.cpp:492 (8)
//         0052d857     TEST       EDI,EDI
//         0052d859     JZ         LAB_0052d740
//                              tvw_main.cpp:494 (14)
//         0052d85f     MOV        this,dword ptr [ESI + 0x100]
//         0052d865     PUSH       EDI
//         0052d866     CALL       TRIBE_Player::command_make_repair                uchar command_make_repair(TRIBE_Player * this
//         0052d86b     TEST       AL,AL
//                              tvw_main.cpp:496 (6)
//         0052d86d     JZ         LAB_0052d740
//                              tvw_main.cpp:498 (20)
//         0052d873     MOV        EDX,dword ptr [EDI + 0x4]
//         0052d876     PUSH       0x2
//         0052d878     PUSH       0x2
//         0052d87a     PUSH       0x5dc
//         0052d87f     PUSH       EDX
//         0052d880     MOV        this,ESI
//         0052d882     CALL       RGE_View::display_object_selection               void display_object_selection(RGE_View * this
//                              tvw_main.cpp:499 (7)
//         0052d887     MOV        this,ESI
//         0052d889     CALL       RGE_View::reset_overlay_sprites                  void reset_overlay_sprites(RGE_View * this)
//                              tvw_main.cpp:522 (9)
//         0052d88e     MOV        EAX,dword ptr [ESI]
//         0052d890     PUSH       0x1
//         0052d892     MOV        this,ESI
//         0052d894     CALL       dword ptr [EAX + 0x20]
//                              tvw_main.cpp:525 (5)
//         0052d897     JMP        LAB_0052d74d
//                               switchD_0052d657::caseD_69                                   XREF[2]:     0052d657(j), 0052d960(*)
//                              tvw_main.cpp:510 (7)
//         0052d89c     MOV        this,ESI
//         0052d89e     CALL       TPanel::release_mouse                            void release_mouse(TPanel * this)
//                              tvw_main.cpp:511 (18)
//         0052d8a3     MOV        AL,byte ptr [ESI + 0xec]
//         0052d8a9     CMP        AL,0x1
//         0052d8ab     JZ         LAB_0052d8b5
//         0052d8ad     CMP        AL,0x2
//         0052d8af     JNZ        LAB_0052d75c
//                               LAB_0052d8b5                                                 XREF[1]:     0052d8ab(j)
//                              tvw_main.cpp:513 (38)
//         0052d8b5     MOV        EDI,dword ptr [ESP + param_2]
//         0052d8b9     MOV        EBX,dword ptr [ESP + param_1]
//         0052d8bd     PUSH       0x1
//         0052d8bf     LEA        EAX=>pick_info.y,[ESP + 0x10]
//         0052d8c3     PUSH       0x0
//         0052d8c5     PUSH       EAX
//         0052d8c6     PUSH       EDI
//         0052d8c7     PUSH       EBX
//         0052d8c8     PUSH       0x0
//         0052d8ca     PUSH       0x28
//         0052d8cc     MOV        this,ESI
//         0052d8ce     CALL       RGE_Main_View::pick1                             uchar pick1(RGE_Main_View * this, uchar param
//         0052d8d3     CMP        AL,0x33
//         0052d8d5     JNZ        LAB_0052d740
//                              tvw_main.cpp:515 (12)
//         0052d8db     LEA        this=>pick_info.y,[ESP + 0xc]
//         0052d8df     PUSH       this
//         0052d8e0     MOV        this,ESI
//         0052d8e2     CALL       RGE_Main_View::fixup_pick_info                   void fixup_pick_info(RGE_Main_View * this, RG
//                              tvw_main.cpp:516 (23)
//         0052d8e7     MOV        EDX,dword ptr [ESP + pick_info.scr_x]
//         0052d8eb     MOV        EAX,dword ptr [ESP + pick_info.y]
//         0052d8ef     MOV        this,dword ptr [ESI + 0x100]
//         0052d8f5     PUSH       EDX
//         0052d8f6     PUSH       EAX
//         0052d8f7     CALL       TRIBE_Player::command_make_unload                uchar command_make_unload(TRIBE_Player * this
//         0052d8fc     TEST       AL,AL
//                              tvw_main.cpp:518 (6)
//         0052d8fe     JZ         LAB_0052d740
//                              tvw_main.cpp:520 (9)
//         0052d904     PUSH       0x2
//         0052d906     MOV        this,ESI
//         0052d908     CALL       RGE_Main_View::reset_display_object_selection    void reset_display_object_selection(RGE_Main_
//                              tvw_main.cpp:521 (49)
//         0052d90d     MOV        this,dword ptr [ESI + 0x134]
//         0052d913     MOV        EAX,[rge_base_game]                              = 00000000
//         0052d918     MOV        EDX,dword ptr [ESI + 0x130]
//                              language.dll match for 0x7d: "Arial"
//         0052d91e     PUSH       0x7d
//         0052d920     PUSH       0x2
//         0052d922     PUSH       0x0
//         0052d924     PUSH       0xf
//         0052d926     ADD        this,EDI
//         0052d928     PUSH       0x0
//         0052d92a     PUSH       this
//         0052d92b     MOV        this,dword ptr [EAX + 0x5c]
//         0052d92e     ADD        EDX,EBX
//         0052d930     PUSH       EDX
//         0052d931     PUSH       0x0
//         0052d933     MOV        EDX,dword ptr [ECX + this->field8_0x8]
//         0052d936     MOV        this,ESI
//         0052d938     PUSH       EDX
//         0052d939     CALL       RGE_View::add_overlay_sprite                     void add_overlay_sprite(RGE_View * this, TSha
//                              tvw_main.cpp:522 (9)
//         0052d93e     MOV        EAX,dword ptr [ESI]
//         0052d940     PUSH       0x1
//         0052d942     MOV        this,ESI
//         0052d944     CALL       dword ptr [EAX + 0x20]
//                              tvw_main.cpp:525 (5)
//         0052d947     JMP        LAB_0052d74d
//                              Symbol Ref: No symbol: NONAME
//                               switchD_0052d657::switchdataD_0052d94c                       XREF[1]:     mouse_left_up_action:0052d657(*)
//                              tvw_main.cpp:534 (24)
//         0052d94c     addr       switchD_0052d657::caseD_64
//         0052d950     addr       switchD_0052d657::caseD_65
//         0052d954     addr       switchD_0052d657::caseD_66
//         0052d958     addr       switchD_0052d657::caseD_67
//         0052d95c     addr       switchD_0052d657::caseD_68
//         0052d960     addr       switchD_0052d657::caseD_69
//         0052d964     ??         90h
//         0052d965     ??         90h
//         0052d966     ??         90h
//         0052d967     ??         90h
//         0052d968     ??         90h
//         0052d969     ??         90h
//         0052d96a     ??         90h
//         0052d96b     ??         90h
//         0052d96c     ??         90h
//         0052d96d     ??         90h
//         0052d96e     ??         90h
//         0052d96f     ??         90h
    return 0;
}

long TRIBE_Main_View::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              long __thiscall mouse_right_up_action(TRIBE_Main_View * this, long p
//              long              EAX:4          <RETURN>
//              TRIBE_Main_Vie    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[7]:     0052d9eb(R), 0052da98(R), 0052dae7(R), 0052db17(R),
//                                                                                     0052db76(R), 0052dbb4(R), 0052dc29(R)
//              long              Stack[0x8]:4   param_2                   XREF[7]:     0052d9e7(R), 0052da94(R), 0052dae2(R), 0052db13(R),
//                                                                                     0052db72(R), 0052dbb0(R), 0052dc25(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0052dade(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0052dada(R)
//              RGE_Pick_Info     Stack[-0x18]   pick_info                 XREF[0,8]:   0052d9f1(*), 0052da0d(*), 0052da1d(R), 0052dc2f(*),
//                                                                                     0052dc4b(*), 0052dc5b(R), 0052da19(R), 0052dc57(R)
//                               ?mouse_right_up_action@TRIBE_Main_View@@UAEJJJHH@Z           XREF[1]:     00572b4c(*)
//                               TRIBE_Main_View::mouse_right_up_action
//                              tvw_main.cpp:540 (8)
//         0052d970     SUB        ESP,0x14
//         0052d973     PUSH       EBX
//         0052d974     PUSH       ESI
//         0052d975     MOV        ESI,this
//         0052d977     PUSH       EDI
//                              tvw_main.cpp:543 (32)
//         0052d978     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052d97e     MOV        EAX,dword ptr [ECX + this->field432_0x1b0]
//         0052d984     CMP        EAX,0x4
//         0052d987     JZ         LAB_0052d9a3
//         0052d989     CMP        EAX,0x6
//         0052d98c     JZ         LAB_0052d9a3
//         0052d98e     CMP        EAX,0x7
//         0052d991     JZ         LAB_0052d9a3
//         0052d993     CMP        EAX,0x5
//         0052d996     JZ         LAB_0052d9a3
//                              tvw_main.cpp:544 (2)
//         0052d998     XOR        EAX,EAX
//                              tvw_main.cpp:650 (9)
//         0052d99a     POP        EDI
//         0052d99b     POP        ESI
//         0052d99c     POP        EBX
//         0052d99d     ADD        ESP,0x14
//         0052d9a0     RET        0x10
//                               LAB_0052d9a3                                                 XREF[4]:     0052d987(j), 0052d98c(j),
//                                                                                                         0052d991(j), 0052d996(j)
//                              tvw_main.cpp:546 (13)
//         0052d9a3     CALL       RGE_Base_Game::get_paused                        int get_paused(RGE_Base_Game * this)
//         0052d9a8     TEST       EAX,EAX
//         0052d9aa     JNZ        switchD_0052d9c7::default
//                              tvw_main.cpp:548 (30)
//         0052d9b0     MOV        EAX,[rge_base_game]                              = 00000000
//         0052d9b5     MOV        EAX,dword ptr [EAX + 0x1b4]
//         0052d9bb     ADD        EAX,-0x64
//         0052d9be     CMP        EAX,0x5
//         0052d9c1     JA         switchD_0052d9c7::default
//                               switchD_0052d9c7::switchD
//         0052d9c7     JMP        dword ptr [EAX*0x4 + switchD_0052d9c7::switchd   = 0052d9ce
//                               switchD_0052d9c7::caseD_64                                   XREF[2]:     0052d9c7(j), 0052dcbc(*)
//                              tvw_main.cpp:551 (7)
//         0052d9ce     MOV        this,ESI
//         0052d9d0     CALL       TPanel::release_mouse                            void release_mouse(TPanel * this)
//                              tvw_main.cpp:552 (18)
//         0052d9d5     MOV        AL,byte ptr [ESI + 0xec]
//         0052d9db     CMP        AL,0x1
//         0052d9dd     JZ         LAB_0052d9e7
//         0052d9df     CMP        AL,0x2
//         0052d9e1     JNZ        LAB_0052dacc
//                               LAB_0052d9e7                                                 XREF[1]:     0052d9dd(j)
//                              tvw_main.cpp:554 (38)
//         0052d9e7     MOV        EDI,dword ptr [ESP + param_2]
//         0052d9eb     MOV        EBX,dword ptr [ESP + param_1]
//         0052d9ef     PUSH       0x1
//         0052d9f1     LEA        this=>pick_info.y,[ESP + 0x10]
//         0052d9f5     PUSH       0x0
//         0052d9f7     PUSH       this
//         0052d9f8     PUSH       EDI
//         0052d9f9     PUSH       EBX
//         0052d9fa     PUSH       0x0
//         0052d9fc     PUSH       0x28
//         0052d9fe     MOV        this,ESI
//         0052da00     CALL       RGE_Main_View::pick1                             uchar pick1(RGE_Main_View * this, uchar param
//         0052da05     CMP        AL,0x33
//         0052da07     JNZ        LAB_0052db2f
//                              tvw_main.cpp:556 (12)
//         0052da0d     LEA        EDX=>pick_info.y,[ESP + 0xc]
//         0052da11     MOV        this,ESI
//         0052da13     PUSH       EDX
//         0052da14     CALL       RGE_Main_View::fixup_pick_info                   void fixup_pick_info(RGE_Main_View * this, RG
//                              tvw_main.cpp:557 (23)
//         0052da19     MOV        EAX,dword ptr [ESP + pick_info.scr_x]
//         0052da1d     MOV        this,dword ptr [ESP + pick_info.y]
//         0052da21     PUSH       EAX
//         0052da22     PUSH       this
//         0052da23     MOV        this,dword ptr [ESI + 0x100]
//         0052da29     CALL       TRIBE_Player::command_attack_ground              uchar command_attack_ground(TRIBE_Player * th
//         0052da2e     TEST       AL,AL
//                              tvw_main.cpp:559 (6)
//         0052da30     JZ         LAB_0052db2f
//                              tvw_main.cpp:561 (9)
//         0052da36     PUSH       0x2
//         0052da38     MOV        this,ESI
//         0052da3a     CALL       RGE_Main_View::reset_display_object_selection    void reset_display_object_selection(RGE_Main_
//                              tvw_main.cpp:562 (50)
//         0052da3f     MOV        EDX,dword ptr [ESI + 0x134]
//         0052da45     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052da4b     MOV        EAX,dword ptr [ESI + 0x130]
//                              language.dll match for 0x7d: "Arial"
//         0052da51     PUSH       0x7d
//         0052da53     PUSH       0x2
//         0052da55     PUSH       0x0
//         0052da57     PUSH       0xf
//         0052da59     ADD        EDX,EDI
//         0052da5b     PUSH       0x0
//         0052da5d     PUSH       EDX
//         0052da5e     MOV        EDX,dword ptr [ECX + this->field92_0x5c]
//         0052da61     ADD        EAX,EBX
//         0052da63     PUSH       EAX
//         0052da64     PUSH       0x0
//         0052da66     MOV        EAX,dword ptr [EDX + 0x8]
//         0052da69     MOV        this,ESI
//         0052da6b     PUSH       EAX
//         0052da6c     CALL       RGE_View::add_overlay_sprite                     void add_overlay_sprite(RGE_View * this, TSha
//                              tvw_main.cpp:563 (9)
//         0052da71     MOV        EDX,dword ptr [ESI]
//         0052da73     PUSH       0x1
//         0052da75     MOV        this,ESI
//         0052da77     CALL       dword ptr [EDX + 0x20]
//                              tvw_main.cpp:566 (5)
//         0052da7a     JMP        LAB_0052db3c
//                               switchD_0052d9c7::caseD_66                                   XREF[2]:     0052d9c7(j), 0052dcc4(*)
//                              tvw_main.cpp:573 (7)
//         0052da7f     MOV        this,ESI
//         0052da81     CALL       TPanel::release_mouse                            void release_mouse(TPanel * this)
//                              tvw_main.cpp:574 (14)
//         0052da86     MOV        AL,byte ptr [ESI + 0xec]
//         0052da8c     CMP        AL,0x1
//         0052da8e     JZ         LAB_0052da94
//         0052da90     CMP        AL,0x2
//         0052da92     JNZ        LAB_0052dacc
//                               LAB_0052da94                                                 XREF[1]:     0052da8e(j)
//                              tvw_main.cpp:576 (28)
//         0052da94     MOV        EAX,dword ptr [ESP + param_2]
//         0052da98     MOV        this,dword ptr [ESP + param_1]
//         0052da9c     MOV        EDX,dword ptr [ESI]
//         0052da9e     PUSH       0x69
//         0052daa0     PUSH       0x0
//         0052daa2     PUSH       EAX
//         0052daa3     PUSH       this
//         0052daa4     MOV        this,ESI
//         0052daa6     CALL       dword ptr [EDX + 0x100]
//         0052daac     TEST       EAX,EAX
//         0052daae     JNZ        LAB_0052dabd
//                               LAB_0052dab0                                                 XREF[5]:     0052db92(j), 0052dbc9(j),
//                                                                                                         0052dbdd(j), 0052dc45(j),
//                                                                                                         0052dc6e(j)
//                              tvw_main.cpp:642 (13)
//         0052dab0     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052dab6     PUSH       0x3
//         0052dab8     CALL       RGE_Base_Game::play_sound                        int play_sound(RGE_Base_Game * this, int para
//                               LAB_0052dabd                                                 XREF[4]:     0052daae(j), 0052db8c(j),
//                                                                                                         0052dc07(j), 0052dcb7(j)
//                              tvw_main.cpp:643 (15)
//         0052dabd     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052dac3     PUSH       0x0
//         0052dac5     PUSH       0x0
//         0052dac7     MOV        EDX,dword ptr [this->field0_0x0]
//         0052dac9     CALL       dword ptr [EDX + 0x10]
//                               LAB_0052dacc                                                 XREF[6]:     0052d9e1(j), 0052da92(j),
//                                                                                                         0052db11(j), 0052db6c(j),
//                                                                                                         0052dbaa(j), 0052dc1f(j)
//                              tvw_main.cpp:645 (5)
//         0052dacc     MOV        EAX,0x1
//                              tvw_main.cpp:650 (9)
//         0052dad1     POP        EDI
//         0052dad2     POP        ESI
//         0052dad3     POP        EBX
//         0052dad4     ADD        ESP,0x14
//         0052dad7     RET        0x10
//                               switchD_0052d9c7::default                                    XREF[2]:     0052d9aa(j), 0052d9c1(j)
//                              tvw_main.cpp:649 (27)
//         0052dada     MOV        EAX,dword ptr [ESP + param_4]
//         0052dade     MOV        this,dword ptr [ESP + param_3]
//         0052dae2     MOV        EDX,dword ptr [ESP + param_2]
//         0052dae6     PUSH       EAX
//         0052dae7     MOV        EAX,dword ptr [ESP + param_1]
//         0052daeb     PUSH       this
//         0052daec     PUSH       EDX
//         0052daed     PUSH       EAX
//         0052daee     MOV        this,ESI
//         0052daf0     CALL       RGE_Main_View::mouse_right_up_action             long mouse_right_up_action(RGE_Main_View * th
//                              tvw_main.cpp:650 (9)
//         0052daf5     POP        EDI
//         0052daf6     POP        ESI
//         0052daf7     POP        EBX
//         0052daf8     ADD        ESP,0x14
//         0052dafb     RET        0x10
//                               switchD_0052d9c7::caseD_65                                   XREF[2]:     0052d9c7(j), 0052dcc0(*)
//                              tvw_main.cpp:583 (7)
//         0052dafe     MOV        this,ESI
//         0052db00     CALL       TPanel::release_mouse                            void release_mouse(TPanel * this)
//                              tvw_main.cpp:584 (14)
//         0052db05     MOV        AL,byte ptr [ESI + 0xec]
//         0052db0b     CMP        AL,0x1
//         0052db0d     JZ         LAB_0052db13
//         0052db0f     CMP        AL,0x2
//         0052db11     JNZ        LAB_0052dacc
//                               LAB_0052db13                                                 XREF[1]:     0052db0d(j)
//                              tvw_main.cpp:586 (28)
//         0052db13     MOV        this,dword ptr [ESP + param_2]
//         0052db17     MOV        EDX,dword ptr [ESP + param_1]
//         0052db1b     MOV        EAX,dword ptr [ESI]
//                              language.dll match for 0x68: "Arial"
//         0052db1d     PUSH       0x68
//         0052db1f     PUSH       0x0
//         0052db21     PUSH       this
//         0052db22     PUSH       EDX
//         0052db23     MOV        this,ESI
//         0052db25     CALL       dword ptr [EAX + 0x100]
//         0052db2b     TEST       EAX,EAX
//         0052db2d     JNZ        LAB_0052db3c
//                               LAB_0052db2f                                                 XREF[2]:     0052da07(j), 0052da30(j)
//                              tvw_main.cpp:587 (13)
//         0052db2f     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052db35     PUSH       0x3
//         0052db37     CALL       RGE_Base_Game::play_sound                        int play_sound(RGE_Base_Game * this, int para
//                               LAB_0052db3c                                                 XREF[2]:     0052da7a(j), 0052db2d(j)
//                              tvw_main.cpp:588 (15)
//         0052db3c     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052db42     PUSH       0x0
//         0052db44     PUSH       0x0
//         0052db46     MOV        EAX,dword ptr [this->field0_0x0]
//         0052db48     CALL       dword ptr [EAX + 0x10]
//                              tvw_main.cpp:650 (14)
//         0052db4b     POP        EDI
//         0052db4c     POP        ESI
//         0052db4d     MOV        EAX,0x1
//         0052db52     POP        EBX
//         0052db53     ADD        ESP,0x14
//         0052db56     RET        0x10
//                               switchD_0052d9c7::caseD_67                                   XREF[2]:     0052d9c7(j), 0052dcc8(*)
//                              tvw_main.cpp:593 (7)
//         0052db59     MOV        this,ESI
//         0052db5b     CALL       TPanel::release_mouse                            void release_mouse(TPanel * this)
//                              tvw_main.cpp:594 (18)
//         0052db60     MOV        AL,byte ptr [ESI + 0xec]
//         0052db66     CMP        AL,0x1
//         0052db68     JZ         LAB_0052db72
//         0052db6a     CMP        AL,0x2
//         0052db6c     JNZ        LAB_0052dacc
//                               LAB_0052db72                                                 XREF[1]:     0052db68(j)
//                              tvw_main.cpp:596 (32)
//         0052db72     MOV        EAX,dword ptr [ESP + param_2]
//         0052db76     MOV        this,dword ptr [ESP + param_1]
//         0052db7a     MOV        EDX,dword ptr [ESI]
//         0052db7c     PUSH       0x7
//         0052db7e     PUSH       0x0
//         0052db80     PUSH       EAX
//         0052db81     PUSH       this
//         0052db82     MOV        this,ESI
//         0052db84     CALL       dword ptr [EDX + 0x100]
//         0052db8a     TEST       EAX,EAX
//         0052db8c     JNZ        LAB_0052dabd
//                              tvw_main.cpp:600 (5)
//         0052db92     JMP        LAB_0052dab0
//                               switchD_0052d9c7::caseD_68                                   XREF[2]:     0052d9c7(j), 0052dccc(*)
//                              tvw_main.cpp:603 (7)
//         0052db97     MOV        this,ESI
//         0052db99     CALL       TPanel::release_mouse                            void release_mouse(TPanel * this)
//                              tvw_main.cpp:604 (18)
//         0052db9e     MOV        AL,byte ptr [ESI + 0xec]
//         0052dba4     CMP        AL,0x1
//         0052dba6     JZ         LAB_0052dbb0
//         0052dba8     CMP        AL,0x2
//         0052dbaa     JNZ        LAB_0052dacc
//                               LAB_0052dbb0                                                 XREF[1]:     0052dba6(j)
//                              tvw_main.cpp:607 (23)
//         0052dbb0     MOV        EAX,dword ptr [ESP + param_2]
//         0052dbb4     MOV        this,dword ptr [ESP + param_1]
//         0052dbb8     PUSH       -0x1
//         0052dbba     PUSH       0x0
//         0052dbbc     PUSH       EAX
//         0052dbbd     PUSH       this
//         0052dbbe     MOV        this,ESI
//         0052dbc0     CALL       RGE_Main_View::pick_best_target                  RGE_Static_Object * pick_best_target(RGE_Main
//         0052dbc5     MOV        EDI,EAX
//                              tvw_main.cpp:608 (8)
//         0052dbc7     TEST       EDI,EDI
//         0052dbc9     JZ         LAB_0052dab0
//                              tvw_main.cpp:610 (14)
//         0052dbcf     MOV        this,dword ptr [ESI + 0x100]
//         0052dbd5     PUSH       EDI
//         0052dbd6     CALL       TRIBE_Player::command_make_repair                uchar command_make_repair(TRIBE_Player * this
//         0052dbdb     TEST       AL,AL
//                              tvw_main.cpp:612 (6)
//         0052dbdd     JZ         LAB_0052dab0
//                              tvw_main.cpp:614 (20)
//         0052dbe3     MOV        EDX,dword ptr [EDI + 0x4]
//         0052dbe6     PUSH       0x2
//         0052dbe8     PUSH       0x2
//         0052dbea     PUSH       0x5dc
//         0052dbef     PUSH       EDX
//         0052dbf0     MOV        this,ESI
//         0052dbf2     CALL       RGE_View::display_object_selection               void display_object_selection(RGE_View * this
//                              tvw_main.cpp:615 (7)
//         0052dbf7     MOV        this,ESI
//         0052dbf9     CALL       RGE_View::reset_overlay_sprites                  void reset_overlay_sprites(RGE_View * this)
//                              tvw_main.cpp:638 (9)
//         0052dbfe     MOV        EAX,dword ptr [ESI]
//         0052dc00     PUSH       0x1
//         0052dc02     MOV        this,ESI
//         0052dc04     CALL       dword ptr [EAX + 0x20]
//                              tvw_main.cpp:641 (5)
//         0052dc07     JMP        LAB_0052dabd
//                               switchD_0052d9c7::caseD_69                                   XREF[2]:     0052d9c7(j), 0052dcd0(*)
//                              tvw_main.cpp:626 (7)
//         0052dc0c     MOV        this,ESI
//         0052dc0e     CALL       TPanel::release_mouse                            void release_mouse(TPanel * this)
//                              tvw_main.cpp:627 (18)
//         0052dc13     MOV        AL,byte ptr [ESI + 0xec]
//         0052dc19     CMP        AL,0x1
//         0052dc1b     JZ         LAB_0052dc25
//         0052dc1d     CMP        AL,0x2
//         0052dc1f     JNZ        LAB_0052dacc
//                               LAB_0052dc25                                                 XREF[1]:     0052dc1b(j)
//                              tvw_main.cpp:629 (38)
//         0052dc25     MOV        EDI,dword ptr [ESP + param_2]
//         0052dc29     MOV        EBX,dword ptr [ESP + param_1]
//         0052dc2d     PUSH       0x1
//         0052dc2f     LEA        EAX=>pick_info.y,[ESP + 0x10]
//         0052dc33     PUSH       0x0
//         0052dc35     PUSH       EAX
//         0052dc36     PUSH       EDI
//         0052dc37     PUSH       EBX
//         0052dc38     PUSH       0x0
//         0052dc3a     PUSH       0x28
//         0052dc3c     MOV        this,ESI
//         0052dc3e     CALL       RGE_Main_View::pick1                             uchar pick1(RGE_Main_View * this, uchar param
//         0052dc43     CMP        AL,0x33
//         0052dc45     JNZ        LAB_0052dab0
//                              tvw_main.cpp:631 (12)
//         0052dc4b     LEA        this=>pick_info.y,[ESP + 0xc]
//         0052dc4f     PUSH       this
//         0052dc50     MOV        this,ESI
//         0052dc52     CALL       RGE_Main_View::fixup_pick_info                   void fixup_pick_info(RGE_Main_View * this, RG
//                              tvw_main.cpp:632 (23)
//         0052dc57     MOV        EDX,dword ptr [ESP + pick_info.scr_x]
//         0052dc5b     MOV        EAX,dword ptr [ESP + pick_info.y]
//         0052dc5f     MOV        this,dword ptr [ESI + 0x100]
//         0052dc65     PUSH       EDX
//         0052dc66     PUSH       EAX
//         0052dc67     CALL       TRIBE_Player::command_make_unload                uchar command_make_unload(TRIBE_Player * this
//         0052dc6c     TEST       AL,AL
//                              tvw_main.cpp:634 (6)
//         0052dc6e     JZ         LAB_0052dab0
//                              tvw_main.cpp:636 (9)
//         0052dc74     PUSH       0x2
//         0052dc76     MOV        this,ESI
//         0052dc78     CALL       RGE_Main_View::reset_display_object_selection    void reset_display_object_selection(RGE_Main_
//                              tvw_main.cpp:637 (49)
//         0052dc7d     MOV        this,dword ptr [ESI + 0x134]
//         0052dc83     MOV        EAX,[rge_base_game]                              = 00000000
//         0052dc88     MOV        EDX,dword ptr [ESI + 0x130]
//                              language.dll match for 0x7d: "Arial"
//         0052dc8e     PUSH       0x7d
//         0052dc90     PUSH       0x2
//         0052dc92     PUSH       0x0
//         0052dc94     PUSH       0xf
//         0052dc96     ADD        this,EDI
//         0052dc98     PUSH       0x0
//         0052dc9a     PUSH       this
//         0052dc9b     MOV        this,dword ptr [EAX + 0x5c]
//         0052dc9e     ADD        EDX,EBX
//         0052dca0     PUSH       EDX
//         0052dca1     PUSH       0x0
//         0052dca3     MOV        EDX,dword ptr [ECX + this->field8_0x8]
//         0052dca6     MOV        this,ESI
//         0052dca8     PUSH       EDX
//         0052dca9     CALL       RGE_View::add_overlay_sprite                     void add_overlay_sprite(RGE_View * this, TSha
//                              tvw_main.cpp:638 (9)
//         0052dcae     MOV        EAX,dword ptr [ESI]
//         0052dcb0     PUSH       0x1
//         0052dcb2     MOV        this,ESI
//         0052dcb4     CALL       dword ptr [EAX + 0x20]
//                              tvw_main.cpp:641 (5)
//         0052dcb7     JMP        LAB_0052dabd
//                              Symbol Ref: No symbol: NONAME
//                               switchD_0052d9c7::switchdataD_0052dcbc                       XREF[1]:     mouse_right_up_action:0052d9c7(*)
//                              tvw_main.cpp:650 (24)
//         0052dcbc     addr       switchD_0052d9c7::caseD_64
//         0052dcc0     addr       switchD_0052d9c7::caseD_65
//         0052dcc4     addr       switchD_0052d9c7::caseD_66
//         0052dcc8     addr       switchD_0052d9c7::caseD_67
//         0052dccc     addr       switchD_0052d9c7::caseD_68
//         0052dcd0     addr       switchD_0052d9c7::caseD_69
//         0052dcd4     ??         90h
//         0052dcd5     ??         90h
//         0052dcd6     ??         90h
//         0052dcd7     ??         90h
//         0052dcd8     ??         90h
//         0052dcd9     ??         90h
//         0052dcda     ??         90h
//         0052dcdb     ??         90h
//         0052dcdc     ??         90h
//         0052dcdd     ??         90h
//         0052dcde     ??         90h
//         0052dcdf     ??         90h
    return 0;
}

int TRIBE_Main_View::pick_through_fog(RGE_Static_Object* param_1) {
    /* TODO: Stub */
//                              int __thiscall pick_through_fog(TRIBE_Main_View * this, RGE_Static_O
//              int               EAX:4          <RETURN>
//              TRIBE_Main_Vie    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     0052dce0(R)
//                               ?pick_through_fog@TRIBE_Main_View@@UAEHPAVRGE_Static_Object  XREF[1]:     00572b88(*)
//                               TRIBE_Main_View::pick_through_fog
//                              tvw_main.cpp:656 (18)
//         0052dce0     MOV        EAX,dword ptr [ESP + param_1]
//         0052dce4     TEST       EAX,EAX
//         0052dce6     JZ         LAB_0052dcfa
//         0052dce8     MOV        EDX,dword ptr [EAX + 0x8]
//         0052dceb     CMP        word ptr [EDX + 0x10],0x2d
//         0052dcf0     JNZ        LAB_0052dcfa
//                              tvw_main.cpp:658 (5)
//         0052dcf2     MOV        EAX,0x1
//                              tvw_main.cpp:661 (3)
//         0052dcf7     RET        0x4
//                               LAB_0052dcfa                                                 XREF[2]:     0052dce6(j), 0052dcf0(j)
//                              tvw_main.cpp:660 (6)
//         0052dcfa     PUSH       EAX
//         0052dcfb     CALL       RGE_View::pick_through_fog                       int pick_through_fog(RGE_View * this, RGE_Sta
//                              tvw_main.cpp:661 (3)
//         0052dd00     RET        0x4
//         0052dd03     ??         90h
//         0052dd04     NOP
//         0052dd05     NOP
//         0052dd06     NOP
//         0052dd07     NOP
//         0052dd08     NOP
//         0052dd09     NOP
//         0052dd0a     NOP
//         0052dd0b     NOP
//         0052dd0c     NOP
//         0052dd0d     NOP
//         0052dd0e     NOP
//         0052dd0f     NOP
    return 0;
}

int TRIBE_Main_View::pick_weight(RGE_Static_Object* param_1, int param_2) {
    /* TODO: Stub */
//                              int __thiscall pick_weight(TRIBE_Main_View * this, RGE_Static_Object
//              int               EAX:4          <RETURN>
//              TRIBE_Main_Vie    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[4]:     0052dd11(R), 0052dd26(W), 0052dd3e(W), 0052dd63(R)
//              int               Stack[0x8]:4   param_2                   XREF[3]:     0052dd90(R), 0052ddc5(R), 0052ddf4(R)
//                               ?pick_weight@TRIBE_Main_View@@UAEHPAVRGE_Static_Object@@H@Z  XREF[1]:     00572b8c(*)
//                               TRIBE_Main_View::pick_weight
//                              tvw_main.cpp:667 (1)
//         0052dd10     PUSH       ESI
//                              tvw_main.cpp:673 (13)
//         0052dd11     MOV        ESI,dword ptr [ESP + param_1]
//         0052dd15     MOV        EAX,dword ptr [ESI + 0x8]
//         0052dd18     MOV        DL,byte ptr [EAX + 0x8d]
//                              tvw_main.cpp:675 (4)
//         0052dd1e     MOV        AX,word ptr [EAX + 0x10]
//                              tvw_main.cpp:679 (28)
//         0052dd22     CMP        AX,0x4f
//         0052dd26     MOV        byte ptr [ESP + param_1],DL
//         0052dd2a     JZ         LAB_0052dd3e
//         0052dd2c     CMP        AX,0xc7
//         0052dd30     JZ         LAB_0052dd3e
//         0052dd32     CMP        AX,0x45
//         0052dd36     JZ         LAB_0052dd3e
//         0052dd38     CMP        AX,0x116
//         0052dd3c     JNZ        LAB_0052dd43
//                               LAB_0052dd3e                                                 XREF[3]:     0052dd2a(j), 0052dd30(j),
//                                                                                                         0052dd36(j)
//                              tvw_main.cpp:680 (5)
//         0052dd3e     MOV        byte ptr [ESP + param_1],0x3
//                               LAB_0052dd43                                                 XREF[1]:     0052dd3c(j)
//                              tvw_main.cpp:682 (32)
//         0052dd43     MOV        EAX,dword ptr [ECX + this->field828_0x33c]
//         0052dd49     TEST       EAX,EAX
//         0052dd4b     JZ         LAB_0052dd61
//         0052dd4d     MOV        EAX,dword ptr [ECX + this->field832_0x340]
//         0052dd53     MOV        this,dword ptr [ESI + 0x4]
//         0052dd56     CMP        EAX,this
//         0052dd58     JNZ        LAB_0052dd61
//         0052dd5a     MOV        EDX,0x1
//         0052dd5f     JMP        LAB_0052dd63
//                               LAB_0052dd61                                                 XREF[2]:     0052dd4b(j), 0052dd58(j)
//         0052dd61     XOR        EDX,EDX
//                               LAB_0052dd63                                                 XREF[1]:     0052dd5f(j)
//                              tvw_main.cpp:686 (23)
//         0052dd63     MOV        this,dword ptr [ESP + param_1]
//         0052dd67     XOR        EAX,EAX
//         0052dd69     AND        this,0xff
//         0052dd6f     SUB        this,0x2
//         0052dd72     JZ         LAB_0052dde7
//         0052dd74     DEC        this
//         0052dd75     JZ         LAB_0052ddb8
//         0052dd77     DEC        this
//         0052dd78     JZ         LAB_0052dd83
//                              tvw_main.cpp:718 (5)
//         0052dd7a     MOV        EAX,0x1
//                              tvw_main.cpp:723 (4)
//         0052dd7f     POP        ESI
//         0052dd80     RET        0x8
//                               LAB_0052dd83                                                 XREF[1]:     0052dd78(j)
//                              tvw_main.cpp:689 (4)
//         0052dd83     TEST       EDX,EDX
//         0052dd85     JZ         LAB_0052dd90
//                              tvw_main.cpp:690 (5)
//         0052dd87     MOV        EAX,0x5
//                              tvw_main.cpp:723 (4)
//         0052dd8c     POP        ESI
//         0052dd8d     RET        0x8
//                               LAB_0052dd90                                                 XREF[1]:     0052dd85(j)
//                              tvw_main.cpp:691 (14)
//         0052dd90     MOV        EAX,dword ptr [ESP + param_2]
//         0052dd94     CMP        EAX,0x1
//         0052dd97     JZ         LAB_0052ddaf
//         0052dd99     CMP        EAX,0x2
//         0052dd9c     JZ         LAB_0052ddaf
//                              tvw_main.cpp:693 (13)
//         0052dd9e     XOR        this,this
//         0052dda0     CMP        EAX,0x3
//         0052dda3     SETZ       this
//         0052dda6     ADD        this,0x2
//         0052dda9     MOV        EAX,this
//                              tvw_main.cpp:723 (4)
//         0052ddab     POP        ESI
//         0052ddac     RET        0x8
//                               LAB_0052ddaf                                                 XREF[2]:     0052dd97(j), 0052dd9c(j)
//                              tvw_main.cpp:692 (5)
//         0052ddaf     MOV        EAX,0x4
//                              tvw_main.cpp:723 (4)
//         0052ddb4     POP        ESI
//         0052ddb5     RET        0x8
//                               LAB_0052ddb8                                                 XREF[1]:     0052dd75(j)
//                              tvw_main.cpp:700 (4)
//         0052ddb8     TEST       EDX,EDX
//         0052ddba     JZ         LAB_0052ddc5
//                              tvw_main.cpp:701 (5)
//         0052ddbc     MOV        EAX,0x5
//                              tvw_main.cpp:723 (4)
//         0052ddc1     POP        ESI
//         0052ddc2     RET        0x8
//                               LAB_0052ddc5                                                 XREF[1]:     0052ddba(j)
//                              tvw_main.cpp:702 (14)
//         0052ddc5     MOV        this,dword ptr [ESP + param_2]
//         0052ddc9     CMP        this,0x1
//         0052ddcc     JZ         LAB_0052de10
//         0052ddce     CMP        this,0x2
//         0052ddd1     JZ         LAB_0052de10
//                              tvw_main.cpp:704 (11)
//         0052ddd3     CMP        this,0x3
//         0052ddd6     JNZ        LAB_0052de15
//         0052ddd8     CMP        byte ptr [ESI + 0x48],0x2
//         0052dddc     JNC        LAB_0052de15
//                              tvw_main.cpp:714 (5)
//         0052ddde     MOV        EAX,0x2
//                              tvw_main.cpp:723 (4)
//         0052dde3     POP        ESI
//         0052dde4     RET        0x8
//                               LAB_0052dde7                                                 XREF[1]:     0052dd72(j)
//                              tvw_main.cpp:709 (4)
//         0052dde7     TEST       EDX,EDX
//         0052dde9     JZ         LAB_0052ddf4
//                              tvw_main.cpp:710 (5)
//         0052ddeb     MOV        EAX,0x5
//                              tvw_main.cpp:723 (4)
//         0052ddf0     POP        ESI
//         0052ddf1     RET        0x8
//                               LAB_0052ddf4                                                 XREF[1]:     0052dde9(j)
//                              tvw_main.cpp:711 (14)
//         0052ddf4     MOV        this,dword ptr [ESP + param_2]
//         0052ddf8     CMP        this,0x1
//         0052ddfb     JZ         LAB_0052de10
//         0052ddfd     CMP        this,0x2
//         0052de00     JZ         LAB_0052de10
//                              tvw_main.cpp:713 (5)
//         0052de02     CMP        this,0x3
//         0052de05     JNZ        LAB_0052de15
//                              tvw_main.cpp:714 (5)
//         0052de07     MOV        EAX,0x2
//                              tvw_main.cpp:723 (4)
//         0052de0c     POP        ESI
//         0052de0d     RET        0x8
//                               LAB_0052de10                                                 XREF[4]:     0052ddcc(j), 0052ddd1(j),
//                                                                                                         0052ddfb(j), 0052de00(j)
//                              tvw_main.cpp:712 (5)
//         0052de10     MOV        EAX,0x3
//                               LAB_0052de15                                                 XREF[3]:     0052ddd6(j), 0052dddc(j),
//                                                                                                         0052de05(j)
//                              tvw_main.cpp:723 (4)
//         0052de15     POP        ESI
//         0052de16     RET        0x8
//         0052de19     ??         90h
//         0052de1a     NOP
//         0052de1b     NOP
//         0052de1c     NOP
//         0052de1d     NOP
//         0052de1e     NOP
//         0052de1f     NOP
    return 0;
}

int TRIBE_Main_View::command_make_do(long param_1, long param_2, int param_3, short param_4) {
    /* TODO: Stub */
//                              int __thiscall command_make_do(TRIBE_Main_View * this, long param_1,
//              int               EAX:4          <RETURN>
//              TRIBE_Main_Vie    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0052de2e(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0052de29(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0052de24(R)
//              short             Stack[0x10]:2  param_4                   XREF[1]:     0052de20(R)
//                               ?command_make_do@TRIBE_Main_View@@UAEHJJHF@Z                 XREF[1]:     00572ba8(*)
//                               TRIBE_Main_View::command_make_do
//                              tvw_main.cpp:731 (25)
//         0052de20     MOV        EAX,dword ptr [ESP + param_4]
//         0052de24     MOV        EDX,dword ptr [ESP + param_3]
//         0052de28     PUSH       EAX
//         0052de29     MOV        EAX,dword ptr [ESP + param_2]
//         0052de2d     PUSH       EDX
//         0052de2e     MOV        EDX,dword ptr [ESP + param_1]
//         0052de32     PUSH       EAX
//         0052de33     PUSH       EDX
//         0052de34     CALL       RGE_Main_View::command_make_do                   int command_make_do(RGE_Main_View * this, lon
//                              tvw_main.cpp:769 (3)
//         0052de39     RET        0x10
//         0052de3c     ??         90h
//         0052de3d     NOP
//         0052de3e     NOP
//         0052de3f     NOP
    return 0;
}

long TRIBE_Main_View::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              long __thiscall mouse_left_dbl_click_action(TRIBE_Main_View * this,
//              long              EAX:4          <RETURN>
//              TRIBE_Main_Vie    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0052de43(R)
//              long              Stack[0x8]:4   param_2                   XREF[4]:     0052de53(R), 0052dece(W), 0052ded4(W), 0052def5(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0052de94(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0052de9c(R)
//              RGE_Pick_Info     Stack[-0x18]   pick_info                 XREF[0,5]:   0052de47(*), 0052de6f(R), 0052dea9(R), 0052debb(R),
//                                                                                     0052df29(R)
//                               ?mouse_left_dbl_click_action@TRIBE_Main_View@@UAEJJJHH@Z     XREF[1]:     00572b3c(*)
//                               TRIBE_Main_View::mouse_left_dbl_click_action
//                              tvw_main.cpp:776 (3)
//         0052de40     SUB        ESP,0x14
//                              tvw_main.cpp:780 (44)
//         0052de43     MOV        EDX,dword ptr [ESP + param_1]
//         0052de47     LEA        EAX=>pick_info.y,[ESP]
//         0052de4b     PUSH       EBX
//         0052de4c     PUSH       EBP
//         0052de4d     PUSH       ESI
//         0052de4e     PUSH       EDI
//         0052de4f     MOV        EDI,this
//         0052de51     PUSH       0x1
//         0052de53     MOV        this,dword ptr [ESP + param_2]
//         0052de57     PUSH       0x0
//         0052de59     PUSH       EAX
//         0052de5a     PUSH       this
//         0052de5b     PUSH       EDX
//         0052de5c     PUSH       0x1
//         0052de5e     PUSH       0x29
//         0052de60     MOV        this,EDI
//         0052de62     CALL       RGE_Main_View::pick1                             uchar pick1(RGE_Main_View * this, uchar param
//         0052de67     CMP        AL,0x34
//         0052de69     JNZ        LAB_0052df4a
//                              tvw_main.cpp:782 (37)
//         0052de6f     MOV        EAX,dword ptr [ESP + pick_info.tile]
//         0052de73     MOV        this,dword ptr [EAX + 0x8]
//         0052de76     CMP        byte ptr [ECX + this->field141_0x8d],0x4
//         0052de7d     JNZ        LAB_0052df4a
//         0052de83     MOV        this,dword ptr [EDI + 0x100]
//         0052de89     MOV        EDX,dword ptr [EAX + 0xc]
//         0052de8c     CMP        EDX,this
//         0052de8e     JNZ        LAB_0052df4a
//                              tvw_main.cpp:784 (16)
//         0052de94     MOV        EDX,dword ptr [ESP + param_3]
//         0052de98     TEST       EDX,EDX
//         0052de9a     JNZ        LAB_0052dead
//         0052de9c     MOV        EDX,dword ptr [ESP + param_4]
//         0052dea0     TEST       EDX,EDX
//         0052dea2     JNZ        LAB_0052dead
//                              tvw_main.cpp:785 (9)
//         0052dea4     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
//         0052dea9     MOV        EAX,dword ptr [ESP + pick_info.tile]
//                               LAB_0052dead                                                 XREF[2]:     0052de9a(j), 0052dea2(j)
//                              tvw_main.cpp:787 (14)
//         0052dead     MOV        this,dword ptr [EDI + 0x100]
//         0052deb3     PUSH       0x0
//         0052deb5     PUSH       EAX
//         0052deb6     CALL       RGE_Player::select_one_object                    int select_one_object(RGE_Player * this, RGE_
//                              tvw_main.cpp:792 (11)
//         0052debb     MOV        EDX,dword ptr [ESP + pick_info.tile]
//         0052debf     MOV        EAX,dword ptr [EDX + 0x8]
//         0052dec2     MOV        BX,word ptr [EAX + 0x10]
//                              tvw_main.cpp:793 (6)
//         0052dec6     MOV        AL,byte ptr [EAX + 0x8f]
//                              tvw_main.cpp:795 (8)
//         0052decc     CMP        AL,0x3
//         0052dece     MOV        byte ptr [ESP + param_2],AL
//         0052ded2     JZ         LAB_0052ded9
//                              tvw_main.cpp:796 (5)
//         0052ded4     MOV        byte ptr [ESP + param_2],0xff
//                               LAB_0052ded9                                                 XREF[1]:     0052ded2(j)
//                              tvw_main.cpp:798 (16)
//         0052ded9     MOV        EAX,dword ptr [EDI + 0x100]
//         0052dedf     MOV        this,dword ptr [EAX + 0x28]
//         0052dee2     MOV        EBP,dword ptr [ECX + this->field4_0x4]
//         0052dee5     TEST       EBP,EBP
//         0052dee7     JZ         LAB_0052df29
//                               LAB_0052dee9                                                 XREF[1]:     0052df27(j)
//                              tvw_main.cpp:800 (3)
//         0052dee9     MOV        ESI,dword ptr [EBP]
//                              tvw_main.cpp:802 (40)
//         0052deec     MOV        EAX,dword ptr [ESI + 0x8]
//         0052deef     CMP        word ptr [EAX + 0x10],BX
//         0052def3     JZ         LAB_0052df03
//         0052def5     MOV        DL,byte ptr [ESP + param_2]
//         0052def9     MOV        this,byte ptr [EAX + 0x8f]
//         0052deff     CMP        this,DL
//         0052df01     JNZ        LAB_0052df22
//                               LAB_0052df03                                                 XREF[1]:     0052def3(j)
//         0052df03     MOV        EAX,dword ptr [ESI + 0x4]
//         0052df06     PUSH       0x0
//         0052df08     PUSH       EAX
//         0052df09     MOV        this,EDI
//         0052df0b     CALL       RGE_View::Object_Was_Displayed                   bool Object_Was_Displayed(RGE_View * this, in
//         0052df10     TEST       AL,AL
//         0052df12     JZ         LAB_0052df22
//                              tvw_main.cpp:806 (21)
//         0052df14     MOV        this,dword ptr [EDI + 0x100]
//         0052df1a     PUSH       0x0
//         0052df1c     PUSH       ESI
//         0052df1d     CALL       RGE_Player::select_one_object                    int select_one_object(RGE_Player * this, RGE_
//                               LAB_0052df22                                                 XREF[2]:     0052df01(j), 0052df12(j)
//         0052df22     MOV        EBP,dword ptr [EBP + 0x4]
//         0052df25     TEST       EBP,EBP
//         0052df27     JNZ        LAB_0052dee9
//                               LAB_0052df29                                                 XREF[1]:     0052dee7(j)
//                              tvw_main.cpp:810 (18)
//         0052df29     MOV        this,dword ptr [ESP + pick_info.tile]
//         0052df2d     PUSH       0x0
//         0052df2f     PUSH       this
//         0052df30     MOV        this,dword ptr [EDI + 0x100]
//         0052df36     CALL       RGE_Player::select_one_object                    int select_one_object(RGE_Player * this, RGE_
//                              tvw_main.cpp:812 (5)
//         0052df3b     MOV        EAX,0x1
//                              tvw_main.cpp:817 (22)
//         0052df40     POP        EDI
//         0052df41     POP        ESI
//         0052df42     POP        EBP
//         0052df43     POP        EBX
//         0052df44     ADD        ESP,0x14
//         0052df47     RET        0x10
//                               LAB_0052df4a                                                 XREF[3]:     0052de69(j), 0052de7d(j),
//                                                                                                         0052de8e(j)
//         0052df4a     POP        EDI
//         0052df4b     POP        ESI
//         0052df4c     POP        EBP
//         0052df4d     XOR        EAX,EAX
//         0052df4f     POP        EBX
//         0052df50     ADD        ESP,0x14
//         0052df53     RET        0x10
//         0052df56     ??         90h
//         0052df57     NOP
//         0052df58     NOP
//         0052df59     NOP
//         0052df5a     NOP
//         0052df5b     NOP
//         0052df5c     NOP
//         0052df5d     NOP
//         0052df5e     NOP
//         0052df5f     NOP
    return 0;
}

TRIBE_Main_View::~TRIBE_Main_View() {
    /* TODO: Stub */
//                              void __thiscall ~TRIBE_Main_View(TRIBE_Main_View * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Main_Vie    ECX:4 (auto)   this
//                               ??1TRIBE_Main_View@@UAE@XZ                                   XREF[1]:     `scalar_deleting_destructor':00495
//                               TRIBE_Main_View::~TRIBE_Main_View
//         00495490     JMP        RGE_View::~RGE_View
//         00495495     ??         90h
//         00495496     NOP
//         00495497     NOP
//         00495498     NOP
//         00495499     NOP
//         0049549a     NOP
//         0049549b     NOP
//         0049549c     NOP
//         0049549d     NOP
//         0049549e     NOP
//         0049549f     NOP
}

