#include "../common.h"
#include "tvw_dmap.h"

TRIBE_Diamond_Map_View::TRIBE_Diamond_Map_View() {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Diamond_Map_View(TRIBE_Diamond_Map_View *
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Diamond_    ECX:4 (auto)   this
//                               ??0TRIBE_Diamond_Map_View@@QAE@XZ                            XREF[1]:     TRIBE_Screen_Game:00494342(c)
//                               TRIBE_Diamond_Map_View::TRIBE_Diamond_Map_View
//                              tvw_dmap.cpp:38 (8)
//         0052c9e0     PUSH       ESI
//         0052c9e1     MOV        ESI,this
//         0052c9e3     CALL       RGE_Diamond_Map_View::RGE_Diamond_Map_View       undefined RGE_Diamond_Map_View(RGE_Diamond_Ma
//                              tvw_dmap.cpp:39 (14)
//         0052c9e8     XOR        EAX,EAX
//         0052c9ea     MOV        dword ptr [ESI],TRIBE_Diamond_Map_View::`vftab   = 0052ca00
//         0052c9f0     MOV        dword ptr [ESI + 0x16c],EAX
//                              tvw_dmap.cpp:40 (6)
//         0052c9f6     MOV        dword ptr [ESI + 0x170],EAX
//                              tvw_dmap.cpp:41 (4)
//         0052c9fc     MOV        EAX,ESI
//         0052c9fe     POP        ESI
//         0052c9ff     RET
}

void TRIBE_Diamond_Map_View::set_redraw(RedrawMode param_1) {
    /* TODO: Stub */
//                              void __thiscall set_redraw(TRIBE_Diamond_Map_View * this, RedrawMode
//              void              <VOID>         <RETURN>
//              TRIBE_Diamond_    ECX:4 (auto)   this
//              RedrawMode        Stack[0x4]:4   param_1                   XREF[1]:     0052ca32(R)
//                               ?set_redraw@TRIBE_Diamond_Map_View@@UAEXW4RedrawMode@TPanel  XREF[1]:     00577370(*)
//                               TRIBE_Diamond_Map_View::set_redraw
//                              tvw_dmap.cpp:47 (2)
//         0052ca30     PUSH       ESI
//         0052ca31     PUSH       EDI
//                              tvw_dmap.cpp:48 (12)
//         0052ca32     MOV        EDI,dword ptr [ESP + param_1]
//         0052ca36     MOV        ESI,this
//         0052ca38     PUSH       EDI
//         0052ca39     CALL       RGE_Diamond_Map::set_redraw                      void set_redraw(RGE_Diamond_Map * this, Redra
//                              tvw_dmap.cpp:52 (18)
//         0052ca3e     TEST       EDI,EDI
//         0052ca40     JZ         LAB_0052ca59
//         0052ca42     MOV        EAX,dword ptr [ESI + 0x70]
//         0052ca45     TEST       EAX,EAX
//         0052ca47     JZ         LAB_0052ca59
//         0052ca49     MOV        EAX,dword ptr [ESI + 0x6c]
//         0052ca4c     TEST       EAX,EAX
//         0052ca4e     JZ         LAB_0052ca59
//                              tvw_dmap.cpp:53 (9)
//         0052ca50     MOV        this,dword ptr [ESI + 0x40]
//         0052ca53     PUSH       EDI
//         0052ca54     CALL       TRIBE_Screen_Game::set_map_buttons_redraw        void set_map_buttons_redraw(TRIBE_Screen_Game
//                               LAB_0052ca59                                                 XREF[3]:     0052ca40(j), 0052ca47(j),
//                                                                                                         0052ca4e(j)
//                              tvw_dmap.cpp:54 (5)
//         0052ca59     POP        EDI
//         0052ca5a     POP        ESI
//         0052ca5b     RET        0x4
//         0052ca5e     ??         90h
//         0052ca5f     NOP
    return;
}

void TRIBE_Diamond_Map_View::draw_objects() {
    /* TODO: Stub */
//                              void __thiscall draw_objects(TRIBE_Diamond_Map_View * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Diamond_    ECX:4 (auto)   this
//                               ?draw_objects@TRIBE_Diamond_Map_View@@MAEXXZ                 XREF[1]:     00577434(*)
//                               TRIBE_Diamond_Map_View::draw_objects
//                              tvw_dmap.cpp:60 (1)
//         0052ca60     PUSH       ESI
//                              tvw_dmap.cpp:64 (14)
//         0052ca61     PUSH       0x40
//         0052ca63     MOV        ESI,this
//         0052ca65     PUSH       s_C:\msdev\work\age1_x1\tvw_dmap.c               = "C:\\msdev\\work\\age1_x1\\tvw_dmap.cpp"
//         0052ca6a     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//                              tvw_dmap.cpp:66 (21)
//         0052ca6f     MOV        EDX,dword ptr [ESI + 0x16c]
//         0052ca75     MOV        this,EAX
//         0052ca77     SUB        this,EDX
//         0052ca79     ADD        ESP,0x8
//         0052ca7c     CMP        this,0x14d
//         0052ca82     JC         LAB_0052ca9d
//                              tvw_dmap.cpp:68 (19)
//         0052ca84     MOV        this,dword ptr [ESI + 0x170]
//         0052ca8a     XOR        EDX,EDX
//         0052ca8c     TEST       this,this
//         0052ca8e     SETZ       DL
//         0052ca91     MOV        dword ptr [ESI + 0x170],EDX
//                              tvw_dmap.cpp:69 (6)
//         0052ca97     MOV        dword ptr [ESI + 0x16c],EAX
//                               LAB_0052ca9d                                                 XREF[1]:     0052ca82(j)
//                              tvw_dmap.cpp:72 (7)
//         0052ca9d     MOV        this,ESI
//         0052ca9f     CALL       RGE_Diamond_Map::draw_objects                    void draw_objects(RGE_Diamond_Map * this)
//                              tvw_dmap.cpp:73 (2)
//         0052caa4     POP        ESI
//         0052caa5     RET
//         0052caa6     ??         90h
//         0052caa7     NOP
//         0052caa8     NOP
//         0052caa9     NOP
//         0052caaa     NOP
//         0052caab     NOP
//         0052caac     NOP
//         0052caad     NOP
//         0052caae     NOP
//         0052caaf     NOP
    return;
}

void TRIBE_Diamond_Map_View::draw_object(short param_1, short param_2, uchar param_3, short param_4, RGE_Static_Object* param_5) {
    /* TODO: Stub */
//                              void __thiscall draw_object(TRIBE_Diamond_Map_View * this, short par
//              void              <VOID>         <RETURN>
//              TRIBE_Diamond_    ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     0052cade(R)
//              short             Stack[0x8]:2   param_2                   XREF[1]:     0052cad9(R)
//              uchar             Stack[0xc]:1   param_3                   XREF[2]:     0052cac7(W), 0052cad4(R)
//              short             Stack[0x10]:2  param_4                   XREF[1]:     0052cacf(R)
//              RGE_Static_Obj    Stack[0x14]:4  param_5                   XREF[1]:     0052cacb(R)
//                               ?draw_object@TRIBE_Diamond_Map_View@@MAEXFFEFPAVRGE_Static_  XREF[1]:     0057743c(*)
//                               TRIBE_Diamond_Map_View::draw_object
//                              tvw_dmap.cpp:79 (9)
//         0052cab0     CMP        dword ptr [ECX + this->_padding_],0x4
//         0052cab7     JNZ        LAB_0052cacb
//                              tvw_dmap.cpp:82 (18)
//         0052cab9     MOV        EAX,dword ptr [ECX + this->flash_on]
//         0052cabf     NEG        EAX
//         0052cac1     SBB        AL,AL
//         0052cac3     AND        AL,0x57
//         0052cac5     DEC        AL
//         0052cac7     MOV        byte ptr [ESP + param_3],AL
//                               LAB_0052cacb                                                 XREF[1]:     0052cab7(j)
//                              tvw_dmap.cpp:94 (30)
//         0052cacb     MOV        EDX,dword ptr [ESP + param_5]
//         0052cacf     MOV        EAX,dword ptr [ESP + param_4]
//         0052cad3     PUSH       EDX
//         0052cad4     MOV        EDX,dword ptr [ESP + param_3]
//         0052cad8     PUSH       EAX
//         0052cad9     MOV        EAX,dword ptr [ESP + param_2]
//         0052cadd     PUSH       EDX
//         0052cade     MOV        EDX,dword ptr [ESP + param_1]
//         0052cae2     PUSH       EAX
//         0052cae3     PUSH       EDX
//         0052cae4     CALL       RGE_Diamond_Map::draw_object                     void draw_object(RGE_Diamond_Map * this, shor
//                              tvw_dmap.cpp:95 (3)
//         0052cae9     RET        0x14
//         0052caec     ??         90h
//         0052caed     NOP
//         0052caee     NOP
//         0052caef     NOP
    return;
}

TRIBE_Diamond_Map_View::~TRIBE_Diamond_Map_View() {
    /* TODO: Stub */
//                              void __thiscall ~TRIBE_Diamond_Map_View(TRIBE_Diamond_Map_View * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Diamond_    ECX:4 (auto)   this
//                               ??1TRIBE_Diamond_Map_View@@UAE@XZ                            XREF[1]:     `scalar_deleting_destructor':0052c
//                               TRIBE_Diamond_Map_View::~TRIBE_Diamond_Map_View
//         0052ca20     JMP        RGE_Diamond_Map::~RGE_Diamond_Map
//         0052ca25     ??         90h
//         0052ca26     NOP
//         0052ca27     NOP
//         0052ca28     NOP
//         0052ca29     NOP
//         0052ca2a     NOP
//         0052ca2b     NOP
//         0052ca2c     NOP
//         0052ca2d     NOP
//         0052ca2e     NOP
//         0052ca2f     NOP
}

