#include "common.h"
#include "obj_list.h"

RGE_Object_List::RGE_Object_List() {
    /* TODO: Stub */
    //                              undefined __thiscall RGE_Object_List(RGE_Object_List * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Object_Lis    ECX:4 (auto)   this
    //                               ??0RGE_Object_List@@QAE@XZ                                   XREF[20]:    RGE_Player:0046e917(c), 
    //                               RGE_Object_List::RGE_Object_List                                          RGE_Player:0046e941(c), 
    //                                                                                                         RGE_Player:0046e96b(c), 
    //                                                                                                         load:0046fb85(c), 
    //                                                                                                         load:0046fbbd(c), 
    //                                                                                                         load:0046fbe9(c), 
    //                                                                                                         create_object_list:004c1d92(c), 
    //                                                                                                         TRIBE_Player:00511f39(c), 
    //                                                                                                         TRIBE_Player:00511f6a(c), 
    //                                                                                                         TRIBE_Player:00511f9b(c), 
    //                                                                                                         load:005129c7(c), 
    //                                                                                                         load:00512a07(c), 
    //                                                                                                         load:00512a45(c), 
    //                                                                                                         RGE_Game_World:005408ac(c), 
    //                                                                                                         RGE_Game_World:005408db(c), 
    //                                                                                                         RGE_Game_World:0054090a(c), 
    //                                                                                                         RGE_Game_World:00540939(c), 
    //                                                                                                         RGE_Game_World:00540968(c), 
    //                                                                                                         RGE_Game_World:00540997(c), 
    //                                                                                                         RGE_Game_World:005409c6(c)  
    //                              obj_list.cpp:42 (2)
    //         00462e80     MOV        EAX,this
    //                              obj_list.cpp:43 (11)
    //         00462e82     XOR        this,this
    //         00462e84     MOV        dword ptr [EAX],RGE_Object_List::`vftable'       = 00463930
    //         00462e8a     MOV        dword ptr [EAX + 0x4],this
    //                              obj_list.cpp:44 (4)
    //         00462e8d     MOV        word ptr [EAX + 0x8],this
    //                              obj_list.cpp:45 (1)
    //         00462e91     RET
    //         00462e92     ??         90h
    //         00462e93     NOP
    //         00462e94     NOP
    //         00462e95     NOP
    //         00462e96     NOP
    //         00462e97     NOP
    //         00462e98     NOP
    //         00462e99     NOP
    //         00462e9a     NOP
    //         00462e9b     NOP
    //         00462e9c     NOP
    //         00462e9d     NOP
    //         00462e9e     NOP
    //         00462e9f     NOP
}

RGE_Object_List::~RGE_Object_List() {
    /* TODO: Stub */
    //                              void __thiscall ~RGE_Object_List(RGE_Object_List * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Object_Lis    ECX:4 (auto)   this
    //                               ??1RGE_Object_List@@QAE@XZ                                   XREF[11]:    ~RGE_Player:0046eb38(c), 
    //                               RGE_Object_List::~RGE_Object_List                                         ~RGE_Player:0046eb4f(c), 
    //                                                                                                         ~RGE_Player:0046eb66(c), 
    //                                                                                                         ~RGE_Static_Object:004c13a0(c), 
    //                                                                                                         ~RGE_Game_World:00540a6f(c), 
    //                                                                                                         ~RGE_Game_World:00540a89(c), 
    //                                                                                                         ~RGE_Game_World:00540aa3(c), 
    //                                                                                                         ~RGE_Game_World:00540abd(c), 
    //                                                                                                         ~RGE_Game_World:00540ad7(c), 
    //                                                                                                         ~RGE_Game_World:00540af1(c), 
    //                                                                                                         ~RGE_Game_World:00540b0b(c)  
    //                              obj_list.cpp:50 (4)
    //         00462ea0     PUSH       ESI
    //         00462ea1     PUSH       EDI
    //         00462ea2     MOV        EDI,this
    //                              obj_list.cpp:56 (13)
    //         00462ea4     MOV        EAX,dword ptr [EDI + 0x4]
    //         00462ea7     MOV        dword ptr [EDI],RGE_Object_List::`vftable'       = 00463930
    //         00462ead     TEST       EAX,EAX
    //         00462eaf     JZ         LAB_00462ec8
    //                               LAB_00462eb1                                                 XREF[1]:     00462ec6(j)  
    //                              obj_list.cpp:58 (3)
    //         00462eb1     MOV        ESI,dword ptr [EAX + 0x4]
    //                              obj_list.cpp:59 (20)
    //         00462eb4     MOV        EAX,dword ptr [EAX]
    //         00462eb6     TEST       EAX,EAX
    //         00462eb8     JZ         LAB_00462ec2
    //         00462eba     MOV        EDX,dword ptr [EAX]
    //         00462ebc     PUSH       0x1
    //         00462ebe     MOV        this,EAX
    //         00462ec0     CALL       dword ptr [EDX]
    //                               LAB_00462ec2                                                 XREF[1]:     00462eb8(j)  
    //         00462ec2     TEST       ESI,ESI
    //         00462ec4     MOV        EAX,ESI
    //         00462ec6     JNZ        LAB_00462eb1
    //                               LAB_00462ec8                                                 XREF[1]:     00462eaf(j)  
    //                              obj_list.cpp:63 (7)
    //         00462ec8     MOV        EAX,dword ptr [EDI + 0x4]
    //         00462ecb     TEST       EAX,EAX
    //         00462ecd     JZ         LAB_00462ee5
    //                               LAB_00462ecf                                                 XREF[1]:     00462ee3(j)  
    //                              obj_list.cpp:65 (6)
    //         00462ecf     MOV        EAX,dword ptr [EDI + 0x4]
    //         00462ed2     MOV        ESI,dword ptr [EAX + 0x4]
    //                              obj_list.cpp:66 (16)
    //         00462ed5     PUSH       ESI
    //         00462ed6     CALL       free                                             undefined free()
    //         00462edb     ADD        ESP,0x4
    //         00462ede     MOV        dword ptr [EDI + 0x4],ESI
    //         00462ee1     TEST       ESI,ESI
    //         00462ee3     JNZ        LAB_00462ecf
    //                               LAB_00462ee5                                                 XREF[1]:     00462ecd(j)  
    //                              obj_list.cpp:69 (6)
    //         00462ee5     MOV        word ptr [EDI + 0x8],0x0
    //                              obj_list.cpp:70 (3)
    //         00462eeb     POP        EDI
    //         00462eec     POP        ESI
    //         00462eed     RET
    //         00462eee     ??         90h
    //         00462eef     NOP
}

void RGE_Object_List::removeAllObjects() {
    /* TODO: Stub */
    //                              void __thiscall removeAllObjects(RGE_Object_List * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Object_Lis    ECX:4 (auto)   this
    //                               ?removeAllObjects@RGE_Object_List@@QAEXXZ                    XREF[10]:    new_map:00455976(c), 
    //                               RGE_Object_List::removeAllObjects                                         new_map:0045598a(c), 
    //                                                                                                         new_map:0045599e(c), 
    //                                                                                                         del_game_info:00541efa(c), 
    //                                                                                                         del_game_info:00541f05(c), 
    //                                                                                                         del_game_info:00541f10(c), 
    //                                                                                                         del_game_info:00541f1b(c), 
    //                                                                                                         del_game_info:00541f26(c), 
    //                                                                                                         del_game_info:00541f31(c), 
    //                                                                                                         del_game_info:00541f3c(c)  
    //                              obj_list.cpp:74 (3)
    //         00462ef0     PUSH       EBX
    //         00462ef1     MOV        EBX,this
    //                              obj_list.cpp:75 (3)
    //         00462ef3     MOV        EAX,dword ptr [EBX + 0x4]
    //                              obj_list.cpp:77 (4)
    //         00462ef6     TEST       EAX,EAX
    //         00462ef8     JZ         LAB_00462f13
    //                              obj_list.cpp:74 (1)
    //         00462efa     PUSH       ESI
    //                               LAB_00462efb                                                 XREF[1]:     00462f10(j)  
    //                              obj_list.cpp:78 (3)
    //         00462efb     MOV        ESI,dword ptr [EAX + 0x4]
    //                              obj_list.cpp:79 (16)
    //         00462efe     MOV        EAX,dword ptr [EAX]
    //         00462f00     TEST       EAX,EAX
    //         00462f02     JZ         LAB_00462f0c
    //         00462f04     MOV        EDX,dword ptr [EAX]
    //         00462f06     PUSH       0x1
    //         00462f08     MOV        this,EAX
    //         00462f0a     CALL       dword ptr [EDX]
    //                               LAB_00462f0c                                                 XREF[1]:     00462f02(j)  
    //         00462f0c     TEST       ESI,ESI
    //                              obj_list.cpp:81 (4)
    //         00462f0e     MOV        EAX,ESI
    //         00462f10     JNZ        LAB_00462efb
    //                              obj_list.cpp:74 (1)
    //         00462f12     POP        ESI
    //                               LAB_00462f13                                                 XREF[1]:     00462ef8(j)  
    //                              obj_list.cpp:84 (7)
    //         00462f13     MOV        dword ptr [EBX + 0x4],0x0
    //                              obj_list.cpp:85 (6)
    //         00462f1a     MOV        word ptr [EBX + 0x8],0x0
    //                              obj_list.cpp:86 (2)
    //         00462f20     POP        EBX
    //         00462f21     RET
    //         00462f22     ??         90h
    //         00462f23     NOP
    //         00462f24     NOP
    //         00462f25     NOP
    //         00462f26     NOP
    //         00462f27     NOP
    //         00462f28     NOP
    //         00462f29     NOP
    //         00462f2a     NOP
    //         00462f2b     NOP
    //         00462f2c     NOP
    //         00462f2d     NOP
    //         00462f2e     NOP
    //         00462f2f     NOP
    return;
}

RGE_Object_Node* RGE_Object_List::add_node(RGE_Static_Object* param_1) {
    /* TODO: Stub */
    //                              RGE_Object_Node * __thiscall add_node(RGE_Object_List * this, RGE_St
    //              RGE_Object_Nod    EAX:4          <RETURN>
    //              RGE_Object_Lis    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00462f56(R)  
    //                               ?add_node@RGE_Object_List@@QAEPAURGE_Object_Node@@PAVRGE_St  XREF[11]:    addObject:00471b4c(c), 
    //                               RGE_Object_List::add_node                                                 setup:004c1cbd(c), 
    //                                                                                                         teleport:004c47eb(c), 
    //                                                                                                         enter_obj:004c593d(c), 
    //                                                                                                         recycle_object_out_of_game:0054609
    //                                                                                                         recycle_object_out_of_game:005460b
    //                                                                                                         recycle_object_out_of_game:005460c
    //                                                                                                         recycle_object_out_of_game:005460d
    //                                                                                                         recycle_object_out_of_game:005460f
    //                                                                                                         recycle_object_out_of_game:0054610
    //                                                                                                         recycle_object_out_of_game:0054611
    //                              obj_list.cpp:91 (1)
    //         00462f30     PUSH       ESI
    //                              obj_list.cpp:95 (11)
    //         00462f31     PUSH       0x10
    //         00462f33     MOV        ESI,this
    //         00462f35     PUSH       0x1
    //         00462f37     CALL       calloc                                           undefined calloc()
    //                              obj_list.cpp:98 (3)
    //         00462f3c     MOV        this,dword ptr [ESI + 0x4]
    //                              obj_list.cpp:99 (10)
    //         00462f3f     MOV        dword ptr [EAX + 0x8],0x0
    //         00462f46     MOV        dword ptr [EAX + 0x4],this
    //                              obj_list.cpp:100 (10)
    //         00462f49     MOV        this,dword ptr [ESI + 0x4]
    //         00462f4c     ADD        ESP,0x8
    //         00462f4f     TEST       this,this
    //         00462f51     JZ         LAB_00462f56
    //                              obj_list.cpp:101 (3)
    //         00462f53     MOV        dword ptr [ECX + this->number_of_objects],EAX
    //                               LAB_00462f56                                                 XREF[1]:     00462f51(j)  
    //                              obj_list.cpp:102 (6)
    //         00462f56     MOV        EDX,dword ptr [ESP + param_1]
    //         00462f5a     MOV        dword ptr [EAX],EDX
    //                              obj_list.cpp:104 (7)
    //         00462f5c     INC        word ptr [ESI + 0x8]
    //         00462f60     MOV        dword ptr [ESI + 0x4],EAX
    //                              obj_list.cpp:113 (4)
    //         00462f63     POP        ESI
    //         00462f64     RET        0x4
    //         00462f67     ??         90h
    //         00462f68     NOP
    //         00462f69     NOP
    //         00462f6a     NOP
    //         00462f6b     NOP
    //         00462f6c     NOP
    //         00462f6d     NOP
    //         00462f6e     NOP
    //         00462f6f     NOP
    //                              * public: void __thiscall RGE_Object_List::remove_node(class RGE_Static_Object *,struct RGE_Object_N... *
    //                              void __thiscall remove_node(RGE_Object_List * this, RGE_Static_Objec
    //              void              <VOID>         <RETURN>
    //              RGE_Object_Lis    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00462f82(R)  
    //              RGE_Object_Nod    Stack[0x8]:4   param_2                   XREF[1]:     00462f7a(R)  
    //                               ?remove_node@RGE_Object_List@@QAEXPAVRGE_Static_Object@@PAU  XREF[15]:    removeObject:00471baf(c), 
    //                               RGE_Object_List::remove_node                                              ~RGE_Static_Object:004c1338(c), 
    //                                                                                                         ~RGE_Static_Object:004c136c(c), 
    //                                                                                                         recycle_out_of_game:004c1627(c), 
    //                                                                                                         recycle_out_of_game:004c163b(c), 
    //                                                                                                         teleport:004c47e2(c), 
    //                                                                                                         enter_obj:004c5924(c), 
    //                                                                                                         exit_obj:004c5970(c), 
    //                                                                                                         recycle_object_in_to_game:005461bd
    //                                                                                                         recycle_object_in_to_game:005461de
    //                                                                                                         recycle_object_in_to_game:005461fb
    //                                                                                                         recycle_object_in_to_game:00546218
    //                                                                                                         recycle_object_in_to_game:00546235
    //                                                                                                         recycle_object_in_to_game:00546252
    //                                                                                                         recycle_object_in_to_game:0054626f
    //                              obj_list.cpp:119 (3)
    //         00462f70     PUSH       ESI
    //         00462f71     MOV        ESI,this
    //                              obj_list.cpp:122 (3)
    //         00462f73     MOV        EAX,dword ptr [ESI + 0x4]
    //                              obj_list.cpp:123 (4)
    //         00462f76     TEST       EAX,EAX
    //         00462f78     JZ         LAB_00462fca
    //                              obj_list.cpp:125 (8)
    //         00462f7a     MOV        this,dword ptr [ESP + param_2]
    //         00462f7e     TEST       this,this
    //         00462f80     JNZ        LAB_00462f99
    //                              obj_list.cpp:127 (10)
    //         00462f82     MOV        this,dword ptr [ESP + param_1]
    //         00462f86     MOV        EDX,dword ptr [EAX]
    //         00462f88     CMP        EDX,this
    //         00462f8a     JZ         LAB_00462f9b
    //                               LAB_00462f8c                                                 XREF[1]:     00462f95(j)  
    //                              obj_list.cpp:129 (3)
    //         00462f8c     MOV        EAX,dword ptr [EAX + 0x4]
    //                              obj_list.cpp:130 (10)
    //         00462f8f     TEST       EAX,EAX
    //         00462f91     JZ         LAB_00462fca
    //         00462f93     CMP        dword ptr [EAX],this
    //         00462f95     JNZ        LAB_00462f8c
    //         00462f97     JMP        LAB_00462f9b
    //                               LAB_00462f99                                                 XREF[1]:     00462f80(j)  
    //                              obj_list.cpp:140 (2)
    //         00462f99     MOV        EAX,this
    //                               LAB_00462f9b                                                 XREF[2]:     00462f8a(j), 00462f97(j)  
    //                              obj_list.cpp:143 (7)
    //         00462f9b     MOV        this,dword ptr [EAX + 0x8]
    //         00462f9e     TEST       this,this
    //         00462fa0     JZ         LAB_00462faa
    //                              obj_list.cpp:144 (6)
    //         00462fa2     MOV        EDX,dword ptr [EAX + 0x4]
    //         00462fa5     MOV        dword ptr [ECX + this->list],EDX
    //                              obj_list.cpp:145 (2)
    //         00462fa8     JMP        LAB_00462fb0
    //                               LAB_00462faa                                                 XREF[1]:     00462fa0(j)  
    //                              obj_list.cpp:146 (6)
    //         00462faa     MOV        this,dword ptr [EAX + 0x4]
    //         00462fad     MOV        dword ptr [ESI + 0x4],this
    //                               LAB_00462fb0                                                 XREF[1]:     00462fa8(j)  
    //                              obj_list.cpp:148 (7)
    //         00462fb0     MOV        this,dword ptr [EAX + 0x4]
    //         00462fb3     TEST       this,this
    //         00462fb5     JZ         LAB_00462fbd
    //                              obj_list.cpp:149 (6)
    //         00462fb7     MOV        EDX,dword ptr [EAX + 0x8]
    //         00462fba     MOV        dword ptr [ECX + this->number_of_objects],EDX
    //                               LAB_00462fbd                                                 XREF[1]:     00462fb5(j)  
    //                              obj_list.cpp:150 (9)
    //         00462fbd     PUSH       EAX
    //         00462fbe     CALL       free                                             undefined free()
    //         00462fc3     ADD        ESP,0x4
    //                              obj_list.cpp:151 (4)
    //         00462fc6     DEC        word ptr [ESI + 0x8]
    //                               LAB_00462fca                                                 XREF[2]:     00462f78(j), 00462f91(j)  
    //                              obj_list.cpp:176 (4)
    //         00462fca     POP        ESI
    //         00462fcb     RET        0x8
    //         00462fce     ??         90h
    //         00462fcf     NOP
    return 0;
}

void RGE_Object_List::invert() {
    /* TODO: Stub */
    //                              void __thiscall invert(RGE_Object_List * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Object_Lis    ECX:4 (auto)   this
    //                               ?invert@RGE_Object_List@@IAEXXZ                              XREF[1]:     load_list:00463902(c)  
    //                               RGE_Object_List::invert
    //                              obj_list.cpp:181 (12)
    //         00462fd0     MOV        EAX,dword ptr [ECX + this->list]
    //         00462fd3     PUSH       ESI
    //         00462fd4     XOR        ESI,ESI
    //         00462fd6     XOR        EDX,EDX
    //         00462fd8     CMP        EAX,ESI
    //         00462fda     JZ         LAB_00462ffa
    //                              obj_list.cpp:181 (1)
    //         00462fdc     PUSH       EDI
    //                               LAB_00462fdd                                                 XREF[1]:     00462ff7(j)  
    //                              obj_list.cpp:190 (3)
    //         00462fdd     MOV        EDI,dword ptr [EAX + 0x4]
    //                              obj_list.cpp:192 (10)
    //         00462fe0     CMP        EDX,ESI
    //         00462fe2     MOV        dword ptr [ECX + this->list],EDI
    //         00462fe5     MOV        dword ptr [EAX + 0x4],EDX
    //         00462fe8     JZ         LAB_00462fed
    //                              obj_list.cpp:193 (3)
    //         00462fea     MOV        dword ptr [EDX + 0x8],EAX
    //                               LAB_00462fed                                                 XREF[1]:     00462fe8(j)  
    //                              obj_list.cpp:194 (2)
    //         00462fed     MOV        EDX,EAX
    //                              obj_list.cpp:195 (10)
    //         00462fef     MOV        dword ptr [EAX + 0x8],ESI
    //         00462ff2     MOV        EAX,dword ptr [ECX + this->list]
    //         00462ff5     CMP        EAX,ESI
    //         00462ff7     JNZ        LAB_00462fdd
    //                              obj_list.cpp:181 (1)
    //         00462ff9     POP        EDI
    //                               LAB_00462ffa                                                 XREF[1]:     00462fda(j)  
    //                              obj_list.cpp:198 (3)
    //         00462ffa     MOV        dword ptr [ECX + this->list],EDX
    //                              obj_list.cpp:199 (2)
    //         00462ffd     POP        ESI
    //         00462ffe     RET
    //         00462fff     ??         90h
    return;
}

void RGE_Object_List::draw(TDrawArea* param_1, short param_2, short param_3, uchar param_4) {
    /* TODO: Stub */
    //                              void __thiscall draw(RGE_Object_List * this, TDrawArea * param_1, sh
    //              void              <VOID>         <RETURN>
    //              RGE_Object_Lis    ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[1]:     00463050(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[1]:     0046304b(R)  
    //              short             Stack[0xc]:2   param_3                   XREF[1]:     00463043(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[1]:     004630a7(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00463007(W), 004630af(R)  
    //                               ?draw@RGE_Object_List@@QAEXPAVTDrawArea@@FFE@Z               XREF[1]:     view_function_terrain:0053747d(c)  
    //                               RGE_Object_List::draw
    //                              obj_list.cpp:205 (2)
    //         00463000     PUSH       this
    //         00463001     PUSH       EDI
    //                              obj_list.cpp:224 (14)
    //         00463002     MOV        EDI,dword ptr [ECX + this->list]
    //         00463005     TEST       EDI,EDI
    //         00463007     MOV        dword ptr [ESP + local_4],this
    //         0046300b     JZ         LAB_00463062
    //         0046300d     PUSH       ESI
    //         0046300e     PUSH       EBP
    //         0046300f     PUSH       EBX
    //                               LAB_00463010                                                 XREF[1]:     0046305d(j)  
    //                              obj_list.cpp:226 (2)
    //         00463010     MOV        this,dword ptr [EDI]
    //                              obj_list.cpp:228 (4)
    //         00463012     TEST       this,this
    //         00463014     JZ         LAB_00463058
    //                              obj_list.cpp:235 (31)
    //         00463016     MOV        EBP,dword ptr [ECX + this->number_of_objects]
    //         00463019     MOV        EAX,dword ptr [ECX + this+0xc]
    //         0046301c     XOR        EDX,EDX
    //         0046301e     MOV        BL,0x1
    //         00463020     MOV        DL,byte ptr [EBP + 0x65]
    //         00463023     MOV        ESI,dword ptr [EAX + 0x108]
    //         00463029     CMP        EDX,0x4
    //         0046302c     JA         switchD_0046302e::caseD_1
    //                               switchD_0046302e::switchD
    //         0046302e     JMP        dword ptr [EDX*0x4 + switchD_0046302e::switchd   = 00463035
    //                               switchD_0046302e::caseD_0                                    XREF[2]:     0046302e(j), 004630e0(*)  
    //                              obj_list.cpp:238 (8)
    //         00463035     MOV        AL,byte ptr [ESP + 0x24]
    //         00463039     TEST       AL,AL
    //         0046303b     JZ         switchD_0046302e::caseD_1
    //                               LAB_0046303d                                                 XREF[2]:     00463075(j), 004630cb(j)  
    //                              obj_list.cpp:268 (2)
    //         0046303d     XOR        BL,BL
    //                               switchD_0046302e::caseD_1                                    XREF[13]:    0046302c(j), 0046302e(j), 
    //                                                                                                         0046303b(j), 0046306d(j), 
    //                                                                                                         00463073(j), 0046307f(j), 
    //                                                                                                         0046309b(j), 004630a5(j), 
    //                                                                                                         004630ad(j), 004630b8(j), 
    //                                                                                                         004630bf(j), 004630d8(j), 
    //                                                                                                         004630e4(*)  
    //                              obj_list.cpp:279 (4)
    //         0046303f     TEST       BL,BL
    //         00463041     JZ         LAB_00463058
    //                              obj_list.cpp:281 (31)
    //         00463043     MOV        EDX,dword ptr [ESP + param_3]
    //         00463047     MOV        EAX,dword ptr [this->_padding_]
    //         00463049     PUSH       ESI
    //         0046304a     PUSH       EDX=>DAT_fffffff8
    //         0046304b     MOV        EDX,dword ptr [ESP + param_2]
    //         0046304f     PUSH       EDX=>DAT_fffffff4
    //         00463050     MOV        EDX,dword ptr [ESP + param_1]
    //         00463054     PUSH       EDX=>DAT_fffffff0
    //         00463055     CALL       dword ptr [EAX + 0xc]
    //                               LAB_00463058                                                 XREF[2]:     00463014(j), 00463041(j)  
    //         00463058     MOV        EDI,dword ptr [EDI + 0x4]
    //         0046305b     TEST       EDI,EDI
    //         0046305d     JNZ        LAB_00463010
    //         0046305f     POP        EBX
    //         00463060     POP        EBP
    //         00463061     POP        ESI
    //                               LAB_00463062                                                 XREF[1]:     0046300b(j)  
    //                              obj_list.cpp:314 (5)
    //         00463062     POP        EDI
    //         00463063     POP        this
    //         00463064     RET        0x10
    //                               switchD_0046302e::caseD_2                                    XREF[2]:     0046302e(j), 004630e8(*)  
    //                              obj_list.cpp:245 (14)
    //         00463067     MOV        AL,byte ptr [ESP + 0x24]
    //         0046306b     TEST       AL,AL
    //         0046306d     JZ         switchD_0046302e::caseD_1
    //         0046306f     CMP        byte ptr [this->_padding_ + 0x48],0x2
    //         00463073     JBE        switchD_0046302e::caseD_1
    //                              obj_list.cpp:246 (2)
    //         00463075     JMP        LAB_0046303d
    //                               switchD_0046302e::caseD_3                                    XREF[2]:     0046302e(j), 004630ec(*)  
    //                              obj_list.cpp:250 (10)
    //         00463077     MOV        DL,byte ptr [ESP + 0x24]
    //         0046307b     XOR        BL,BL
    //         0046307d     TEST       DL,DL
    //         0046307f     JZ         switchD_0046302e::caseD_1
    //                              obj_list.cpp:252 (28)
    //         00463081     MOV        EDX,dword ptr [EAX + 0x3c]
    //         00463084     MOVSX      EAX,word ptr [EAX + 0x4a]
    //         00463088     MOVSX      EBP,word ptr [EDX + 0x7c]
    //         0046308c     MOV        EDX,dword ptr [EDX + 0x40]
    //         0046308f     MOV        EDX,dword ptr [EDX + EBP*0x4]
    //         00463092     MOV        EBP,dword ptr [EDX + EAX*0x4 + 0xac]
    //         00463099     TEST       EBP,EBP
    //         0046309b     JZ         switchD_0046302e::caseD_1
    //                              obj_list.cpp:255 (8)
    //         0046309d     MOV        ESI,dword ptr [this->_padding_ + 0x90]
    //         004630a3     MOV        BL,0x1
    //                              obj_list.cpp:258 (2)
    //         004630a5     JMP        switchD_0046302e::caseD_1
    //                               switchD_0046302e::caseD_4                                    XREF[2]:     0046302e(j), 004630f0(*)  
    //                              obj_list.cpp:261 (19)
    //         004630a7     MOV        AL,byte ptr [ESP + param_4]
    //         004630ab     TEST       AL,AL
    //         004630ad     JZ         switchD_0046302e::caseD_1
    //         004630af     MOV        EAX,dword ptr [ESP + local_4]
    //         004630b3     CMP        word ptr [EAX + 0x8],0x1
    //         004630b8     JLE        switchD_0046302e::caseD_1
    //                              obj_list.cpp:263 (11)
    //         004630ba     MOV        EAX,dword ptr [EAX + 0x4]
    //         004630bd     TEST       EAX,EAX
    //         004630bf     JZ         switchD_0046302e::caseD_1
    //                               LAB_004630c5                                                 XREF[1]:     004630d6(j)  
    //                              obj_list.cpp:266 (24)
    //         004630c5     MOV        EDX,dword ptr [EAX]
    //         004630c7     CMP        byte ptr [EDX + 0x4e],0x19
    //         004630cb     JZ         LAB_0046303d
    //         004630d1     MOV        EAX,dword ptr [EAX + 0x4]
    //         004630d4     TEST       EAX,EAX
    //         004630d6     JNZ        LAB_004630c5
    //         004630d8     JMP        switchD_0046302e::caseD_1
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_004630dd()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_004630dd
    //                              obj_list.cpp:314 (23)
    //         004630dd     NOP
    //         004630de     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0046302e::switchdataD_004630e0                       XREF[1]:     draw:0046302e(*)  
    //         004630e0     addr       switchD_0046302e::caseD_0
    //         004630e4     addr       switchD_0046302e::caseD_1
    //         004630e8     addr       switchD_0046302e::caseD_2
    //         004630ec     addr       switchD_0046302e::caseD_3
    //         004630f0     addr       switchD_0046302e::caseD_4
    //         004630f4     ??         90h
    //         004630f5     ??         90h
    //         004630f6     ??         90h
    //         004630f7     ??         90h
    //         004630f8     ??         90h
    //         004630f9     ??         90h
    //         004630fa     ??         90h
    //         004630fb     ??         90h
    //         004630fc     ??         90h
    //         004630fd     ??         90h
    //         004630fe     ??         90h
    //         004630ff     ??         90h
    //                              * public: void __thiscall RGE_Object_List::shadow_draw(class TDrawArea *,short,short,unsigned char,u... *
    //                              void __thiscall shadow_draw(RGE_Object_List * this, TDrawArea * para
    //              void              <VOID>         <RETURN>
    //              RGE_Object_Lis    ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[2]:     00463113(R), 0046314e(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[2]:     00463117(R), 00463152(R)  
    //              short             Stack[0xc]:2   param_3                   XREF[2]:     0046311b(R), 00463156(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[2]:     0046312f(R), 00463160(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[1]:     00463100(R)  
    //                               ?shadow_draw@RGE_Object_List@@QAEXPAVTDrawArea@@FFEE@Z       XREF[5]:     view_function:00536735(c), 
    //                               RGE_Object_List::shadow_draw                                              view_function:00536768(c), 
    //                                                                                                         view_function:005367c9(c), 
    //                                                                                                         view_function:005367fc(c), 
    //                                                                                                         view_function:00536859(c)  
    //                              obj_list.cpp:320 (7)
    //         00463100     MOV        AL,byte ptr [ESP + param_5]
    //         00463104     PUSH       EBX
    //         00463105     PUSH       EBP
    //         00463106     PUSH       ESI
    //                              obj_list.cpp:325 (24)
    //         00463107     MOV        ESI,dword ptr [ECX + this->list]
    //         0046310a     PUSH       EDI
    //         0046310b     TEST       AL,AL
    //         0046310d     JZ         LAB_0046314a
    //         0046310f     TEST       ESI,ESI
    //         00463111     JZ         LAB_00463174
    //         00463113     MOV        EDI,dword ptr [ESP + param_1]
    //         00463117     MOV        EBX,dword ptr [ESP + param_2]
    //         0046311b     MOV        EBP,dword ptr [ESP + param_3]
    //                               LAB_0046311f                                                 XREF[1]:     00463141(j)  
    //                              obj_list.cpp:326 (16)
    //         0046311f     MOV        this,dword ptr [ESI]
    //         00463121     TEST       this,this
    //         00463123     JZ         LAB_0046313c
    //         00463125     MOV        EAX,dword ptr [ECX + this->number_of_objects]
    //         00463128     MOV        DL,byte ptr [EAX + 0x65]
    //         0046312b     TEST       DL,DL
    //         0046312d     JZ         LAB_0046313c
    //                              obj_list.cpp:327 (20)
    //         0046312f     MOV        EAX,dword ptr [ESP + param_4]
    //         00463133     MOV        EDX,dword ptr [this->_padding_]
    //         00463135     PUSH       EAX
    //         00463136     PUSH       EBP
    //         00463137     PUSH       EBX
    //         00463138     PUSH       EDI
    //         00463139     CALL       dword ptr [EDX + 0x10]
    //                               LAB_0046313c                                                 XREF[2]:     00463123(j), 0046312d(j)  
    //         0046313c     MOV        ESI,dword ptr [ESI + 0x4]
    //         0046313f     TEST       ESI,ESI
    //         00463141     JNZ        LAB_0046311f
    //                              obj_list.cpp:335 (7)
    //         00463143     POP        EDI
    //         00463144     POP        ESI
    //         00463145     POP        EBP
    //         00463146     POP        EBX
    //         00463147     RET        0x14
    //                               LAB_0046314a                                                 XREF[1]:     0046310d(j)  
    //                              obj_list.cpp:331 (16)
    //         0046314a     TEST       ESI,ESI
    //         0046314c     JZ         LAB_00463174
    //         0046314e     MOV        EDI,dword ptr [ESP + param_1]
    //         00463152     MOV        EBX,dword ptr [ESP + param_2]
    //         00463156     MOV        EBP,dword ptr [ESP + param_3]
    //                               LAB_0046315a                                                 XREF[1]:     00463172(j)  
    //                              obj_list.cpp:332 (6)
    //         0046315a     MOV        this,dword ptr [ESI]
    //         0046315c     TEST       this,this
    //         0046315e     JZ         LAB_0046316d
    //                              obj_list.cpp:333 (20)
    //         00463160     MOV        EAX,dword ptr [ESP + param_4]
    //         00463164     MOV        EDX,dword ptr [this->_padding_]
    //         00463166     PUSH       EAX
    //         00463167     PUSH       EBP
    //         00463168     PUSH       EBX
    //         00463169     PUSH       EDI
    //         0046316a     CALL       dword ptr [EDX + 0x10]
    //                               LAB_0046316d                                                 XREF[1]:     0046315e(j)  
    //         0046316d     MOV        ESI,dword ptr [ESI + 0x4]
    //         00463170     TEST       ESI,ESI
    //         00463172     JNZ        LAB_0046315a
    //                               LAB_00463174                                                 XREF[2]:     00463111(j), 0046314c(j)  
    //                              obj_list.cpp:335 (7)
    //         00463174     POP        EDI
    //         00463175     POP        ESI
    //         00463176     POP        EBP
    //         00463177     POP        EBX
    //         00463178     RET        0x14
    //         0046317b     ??         90h
    //         0046317c     NOP
    //         0046317d     NOP
    //         0046317e     NOP
    //         0046317f     NOP
    return;
}

void RGE_Object_List::normal_draw(TDrawArea* param_1, short param_2, short param_3, uchar param_4) {
    /* TODO: Stub */
    //                              void __thiscall normal_draw(RGE_Object_List * this, TDrawArea * para
    //              void              <VOID>         <RETURN>
    //              RGE_Object_Lis    ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[2]:     00463199(R), 004631ca(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[2]:     0046319d(R), 004631ce(R)  
    //              short             Stack[0xc]:2   param_3                   XREF[2]:     004631b1(R), 004631d8(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[1]:     0046318b(R)  
    //                               ?normal_draw@RGE_Object_List@@QAEXPAVTDrawArea@@FFE@Z        XREF[1]:     view_function:0053689a(c)  
    //                               RGE_Object_List::normal_draw
    //                              obj_list.cpp:342 (4)
    //         00463180     PUSH       EBX
    //         00463181     PUSH       EBP
    //         00463182     PUSH       ESI
    //         00463183     PUSH       EDI
    //                              obj_list.cpp:346 (7)
    //         00463184     CALL       RGE_Object_List::sort                            RGE_Object_Node * sort(RGE_Object_List * this)
    //         00463189     MOV        EDI,EAX
    //                              obj_list.cpp:348 (6)
    //         0046318b     MOV        AL,byte ptr [ESP + param_4]
    //         0046318f     TEST       AL,AL
    //                              obj_list.cpp:350 (16)
    //         00463191     MOV        ESI,EDI
    //         00463193     JZ         LAB_004631c6
    //         00463195     TEST       EDI,EDI
    //         00463197     JZ         LAB_00463201
    //         00463199     MOV        EBX,dword ptr [ESP + param_1]
    //         0046319d     MOV        EBP,dword ptr [ESP + param_2]
    //                               LAB_004631a1                                                 XREF[1]:     004631c2(j)  
    //                              obj_list.cpp:351 (16)
    //         004631a1     MOV        this,dword ptr [ESI]
    //         004631a3     TEST       this,this
    //         004631a5     JZ         LAB_004631bd
    //         004631a7     MOV        EAX,dword ptr [ECX + this->number_of_objects]
    //         004631aa     MOV        DL,byte ptr [EAX + 0x65]
    //         004631ad     TEST       DL,DL
    //         004631af     JZ         LAB_004631bd
    //                              obj_list.cpp:352 (19)
    //         004631b1     MOV        EAX,dword ptr [ESP + param_3]
    //         004631b5     MOV        EDX,dword ptr [this->_padding_]
    //         004631b7     PUSH       EAX
    //         004631b8     PUSH       EBP=>DAT_fffffff8
    //         004631b9     PUSH       EBX=>DAT_fffffff4
    //         004631ba     CALL       dword ptr [EDX + 0x14]
    //                               LAB_004631bd                                                 XREF[2]:     004631a5(j), 004631af(j)  
    //         004631bd     MOV        ESI,dword ptr [ESI + 0x4]
    //         004631c0     TEST       ESI,ESI
    //         004631c2     JNZ        LAB_004631a1
    //                              obj_list.cpp:354 (2)
    //         004631c4     JMP        LAB_004631eb
    //                               LAB_004631c6                                                 XREF[1]:     00463193(j)  
    //                              obj_list.cpp:356 (12)
    //         004631c6     TEST       EDI,EDI
    //         004631c8     JZ         LAB_00463201
    //         004631ca     MOV        EBX,dword ptr [ESP + param_1]
    //         004631ce     MOV        EBP,dword ptr [ESP + param_2]
    //                               LAB_004631d2                                                 XREF[1]:     004631e9(j)  
    //                              obj_list.cpp:357 (6)
    //         004631d2     MOV        this,dword ptr [ESI]
    //         004631d4     TEST       this,this
    //         004631d6     JZ         LAB_004631e4
    //                              obj_list.cpp:358 (19)
    //         004631d8     MOV        EAX,dword ptr [ESP + param_3]
    //         004631dc     MOV        EDX,dword ptr [this->_padding_]
    //         004631de     PUSH       EAX
    //         004631df     PUSH       EBP=>DAT_fffffff8
    //         004631e0     PUSH       EBX=>DAT_fffffff4
    //         004631e1     CALL       dword ptr [EDX + 0x14]
    //                               LAB_004631e4                                                 XREF[1]:     004631d6(j)  
    //         004631e4     MOV        ESI,dword ptr [ESI + 0x4]
    //         004631e7     TEST       ESI,ESI
    //         004631e9     JNZ        LAB_004631d2
    //                               LAB_004631eb                                                 XREF[1]:     004631c4(j)  
    //                              obj_list.cpp:362 (4)
    //         004631eb     TEST       EDI,EDI
    //         004631ed     JZ         LAB_00463201
    //                               LAB_004631ef                                                 XREF[1]:     004631ff(j)  
    //                              obj_list.cpp:364 (3)
    //         004631ef     MOV        ESI,dword ptr [EDI + 0x4]
    //                              obj_list.cpp:365 (9)
    //         004631f2     PUSH       EDI
    //         004631f3     CALL       free                                             undefined free()
    //         004631f8     ADD        ESP,0x4
    //                              obj_list.cpp:366 (6)
    //         004631fb     MOV        EDI,ESI
    //         004631fd     TEST       ESI,ESI
    //         004631ff     JNZ        LAB_004631ef
    //                               LAB_00463201                                                 XREF[3]:     00463197(j), 004631c8(j), 
    //                                                                                                         004631ed(j)  
    //                              obj_list.cpp:368 (7)
    //         00463201     POP        EDI
    //         00463202     POP        ESI
    //         00463203     POP        EBP
    //         00463204     POP        EBX
    //         00463205     RET        0x10
    //         00463208     ??         90h
    //         00463209     NOP
    //         0046320a     NOP
    //         0046320b     NOP
    //         0046320c     NOP
    //         0046320d     NOP
    //         0046320e     NOP
    //         0046320f     NOP
    return;
}

void RGE_Object_List::update() {
    /* TODO: Stub */
    //                              void __thiscall update(RGE_Object_List * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Object_Lis    ECX:4 (auto)   this
    //                               ?update@RGE_Object_List@@QAEXXZ                              XREF[3]:     update:0047013c(c), 
    //                               RGE_Object_List::update                                                   update_dopplegangers:00470195(c), 
    //                                                                                                         update:005430eb(c)  
    //                              obj_list.cpp:374 (2)
    //         00463210     PUSH       EBX
    //         00463211     PUSH       ESI
    //                              obj_list.cpp:381 (9)
    //         00463212     MOV        ESI,dword ptr [ECX + this->list]
    //         00463215     XOR        EBX,EBX
    //         00463217     TEST       ESI,ESI
    //         00463219     JZ         LAB_00463253
    //                              obj_list.cpp:374 (1)
    //         0046321b     PUSH       EDI
    //                               LAB_0046321c                                                 XREF[1]:     00463250(j)  
    //                              obj_list.cpp:384 (9)
    //         0046321c     MOV        this,dword ptr [ESI]
    //         0046321e     MOV        EDI,dword ptr [ESI + 0x4]
    //         00463221     TEST       this,this
    //         00463223     JZ         LAB_0046324c
    //                              obj_list.cpp:386 (9)
    //         00463225     MOV        EAX,dword ptr [this->_padding_]
    //         00463227     CALL       dword ptr [EAX + 0x24]
    //         0046322a     TEST       AL,AL
    //         0046322c     JZ         LAB_00463235
    //                              obj_list.cpp:387 (7)
    //         0046322e     MOV        this,dword ptr [ESI]
    //         00463230     MOV        EDX,dword ptr [this->_padding_]
    //         00463232     CALL       dword ptr [EDX + 0x8]
    //                               LAB_00463235                                                 XREF[1]:     0046322c(j)  
    //                              obj_list.cpp:391 (1)
    //         00463235     INC        EBX
    //                              obj_list.cpp:392 (5)
    //         00463236     CMP        EBX,0x9
    //         00463239     JLE        LAB_0046324c
    //                              obj_list.cpp:395 (12)
    //         0046323b     MOV        this,dword ptr [MouseSystem]                     = 00000000
    //         00463241     XOR        EBX,EBX
    //         00463243     TEST       this,this
    //         00463245     JZ         LAB_0046324c
    //                              obj_list.cpp:396 (5)
    //         00463247     CALL       TMousePointer::Poll                              void Poll(TMousePointer * this)
    //                               LAB_0046324c                                                 XREF[3]:     00463223(j), 00463239(j), 
    //                                                                                                         00463245(j)  
    //                              obj_list.cpp:381 (6)
    //         0046324c     TEST       EDI,EDI
    //         0046324e     MOV        ESI,EDI
    //         00463250     JNZ        LAB_0046321c
    //                              obj_list.cpp:374 (1)
    //         00463252     POP        EDI
    //                               LAB_00463253                                                 XREF[1]:     00463219(j)  
    //                              obj_list.cpp:402 (3)
    //         00463253     POP        ESI
    //         00463254     POP        EBX
    //         00463255     RET
    //         00463256     ??         90h
    //         00463257     NOP
    //         00463258     NOP
    //         00463259     NOP
    //         0046325a     NOP
    //         0046325b     NOP
    //         0046325c     NOP
    //         0046325d     NOP
    //         0046325e     NOP
    //         0046325f     NOP
    return;
}

RGE_Object_Node* RGE_Object_List::sort() {
    /* TODO: Stub */
    //                              RGE_Object_Node * __thiscall sort(RGE_Object_List * this)
    //              RGE_Object_Nod    EAX:4          <RETURN>
    //              RGE_Object_Lis    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[7]:     00463269(W), 00463274(*), 004632ad(*), 004632b5(*), 
    //                                                                                     004632c1(*), 004632ca(*), 004632cf(R)  
    //              RGE_Object_Nod    Stack[-0x8]:4  sorted
    //                               ?sort@RGE_Object_List@@QAEPAURGE_Object_Node@@XZ             XREF[2]:     normal_draw:00463184(c), 
    //                               RGE_Object_List::sort                                                     hit_object:00539ee2(c)  
    //                              obj_list.cpp:407 (2)
    //         00463260     PUSH       this
    //         00463261     PUSH       EBX
    //                              obj_list.cpp:409 (5)
    //         00463262     MOV        EBX,dword ptr [ECX + this->list]
    //         00463265     XOR        EAX,EAX
    //                              obj_list.cpp:419 (11)
    //         00463267     TEST       EBX,EBX
    //         00463269     MOV        dword ptr [ESP + local_4],EAX
    //         0046326d     JZ         LAB_004632da
    //         0046326f     PUSH       EDI
    //         00463270     PUSH       ESI
    //         00463271     PUSH       EBP
    //                               LAB_00463272                                                 XREF[1]:     004632d5(j)  
    //                              obj_list.cpp:421 (2)
    //         00463272     MOV        this,dword ptr [EBX]
    //                              obj_list.cpp:424 (4)
    //         00463274     LEA        ESI=>local_4,[ESP + 0x10]
    //                              obj_list.cpp:431 (14)
    //         00463278     TEST       EAX,EAX
    //         0046327a     MOV        BP,word ptr [this->_padding_ + 0x2a]
    //         0046327e     MOV        this,dword ptr [ECX + this->number_of_objects]
    //         00463281     MOV        DL,byte ptr [this->_padding_ + 0x4a]
    //         00463284     JZ         LAB_004632a4
    //                               LAB_00463286                                                 XREF[1]:     004632a2(j)  
    //                              obj_list.cpp:434 (2)
    //         00463286     MOV        EDI,dword ptr [EAX]
    //                              obj_list.cpp:435 (6)
    //         00463288     MOV        this,dword ptr [EDI + 0x8]
    //         0046328b     MOV        this,byte ptr [this->_padding_ + 0x4a]
    //                              obj_list.cpp:437 (12)
    //         0046328e     CMP        this,DL
    //         00463290     JC         LAB_004632a4
    //         00463292     JNZ        LAB_0046329a
    //         00463294     CMP        word ptr [EDI + 0x2a],BP
    //         00463298     JG         LAB_004632a4
    //                               LAB_0046329a                                                 XREF[1]:     00463292(j)  
    //                              obj_list.cpp:439 (10)
    //         0046329a     LEA        ESI,[EAX + 0x4]
    //         0046329d     MOV        EAX,dword ptr [EAX + 0x4]
    //         004632a0     TEST       EAX,EAX
    //         004632a2     JNZ        LAB_00463286
    //                               LAB_004632a4                                                 XREF[3]:     00463284(j), 00463290(j), 
    //                                                                                                         00463298(j)  
    //                              obj_list.cpp:443 (9)
    //         004632a4     PUSH       0x10
    //         004632a6     PUSH       0x1
    //         004632a8     CALL       calloc                                           undefined calloc()
    //                              obj_list.cpp:444 (8)
    //         004632ad     MOV        EDX,dword ptr [ESI]=>local_4
    //         004632af     ADD        ESP,0x8
    //         004632b2     MOV        dword ptr [EAX + 0x4],EDX
    //                              obj_list.cpp:445 (6)
    //         004632b5     MOV        this,dword ptr [ESI]=>local_4
    //         004632b7     TEST       this,this
    //         004632b9     JZ         LAB_004632c6
    //                              obj_list.cpp:447 (6)
    //         004632bb     MOV        this,dword ptr [ECX + this->number_of_objects]
    //         004632be     MOV        dword ptr [EAX + 0x8],this
    //                              obj_list.cpp:448 (5)
    //         004632c1     MOV        EDX,dword ptr [ESI]=>local_4
    //         004632c3     MOV        dword ptr [EDX + 0x8],EAX
    //                               LAB_004632c6                                                 XREF[1]:     004632b9(j)  
    //                              obj_list.cpp:450 (4)
    //         004632c6     MOV        this,dword ptr [EBX]
    //         004632c8     MOV        dword ptr [EAX],this
    //                              obj_list.cpp:451 (2)
    //         004632ca     MOV        dword ptr [ESI]=>local_4,EAX
    //                              obj_list.cpp:453 (14)
    //         004632cc     MOV        EBX,dword ptr [EBX + 0x4]
    //         004632cf     MOV        EAX,dword ptr [ESP + local_4]
    //         004632d3     TEST       EBX,EBX
    //         004632d5     JNZ        LAB_00463272
    //         004632d7     POP        EBP
    //         004632d8     POP        ESI
    //         004632d9     POP        EDI
    //                               LAB_004632da                                                 XREF[1]:     0046326d(j)  
    //                              obj_list.cpp:457 (3)
    //         004632da     POP        EBX
    //         004632db     POP        this
    //         004632dc     RET
    //         004632dd     ??         90h
    //         004632de     NOP
    //         004632df     NOP
    return 0;
}

RGE_Static_Object* RGE_Object_List::find_by_group(long param_1) {
    /* TODO: Stub */
    //                              RGE_Static_Object * __thiscall find_by_group(RGE_Object_List * this,
    //              RGE_Static_Obj    EAX:4          <RETURN>
    //              RGE_Object_Lis    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     004632e7(R)  
    //                               ?find_by_group@RGE_Object_List@@QAEPAVRGE_Static_Object@@J@Z
    //                               RGE_Object_List::find_by_group
    //                              obj_list.cpp:462 (11)
    //         004632e0     MOV        EAX,dword ptr [ECX + this->list]
    //         004632e3     TEST       EAX,EAX
    //         004632e5     JZ         LAB_0046330b
    //         004632e7     MOV        EDX,dword ptr [ESP + param_1]
    //                               LAB_004632eb                                                 XREF[1]:     00463301(j)  
    //                              obj_list.cpp:466 (17)
    //         004632eb     MOV        this,dword ptr [EAX]
    //         004632ed     TEST       this,this
    //         004632ef     JZ         LAB_004632fc
    //         004632f1     MOV        this,dword ptr [ECX + this->number_of_objects]
    //         004632f4     MOVSX      this,word ptr [this->_padding_ + 0x14]
    //         004632f8     CMP        this,EDX
    //         004632fa     JZ         LAB_00463306
    //                               LAB_004632fc                                                 XREF[1]:     004632ef(j)  
    //                              obj_list.cpp:465 (7)
    //         004632fc     MOV        EAX,dword ptr [EAX + 0x4]
    //         004632ff     TEST       EAX,EAX
    //         00463301     JNZ        LAB_004632eb
    //                              obj_list.cpp:469 (3)
    //         00463303     RET        0x4
    //                               LAB_00463306                                                 XREF[1]:     004632fa(j)  
    //                              obj_list.cpp:467 (2)
    //         00463306     MOV        EAX,dword ptr [EAX]
    //                              obj_list.cpp:469 (3)
    //         00463308     RET        0x4
    //                               LAB_0046330b                                                 XREF[1]:     004632e5(j)  
    //                              obj_list.cpp:468 (2)
    //         0046330b     XOR        EAX,EAX
    //                              obj_list.cpp:469 (3)
    //         0046330d     RET        0x4
    //                              * public: class RGE_Static_Object * __thiscall RGE_Object_List::find_by_group(long,float,float,unsig... *
    //                              RGE_Static_Object * __thiscall find_by_group(RGE_Object_List * this,
    //              RGE_Static_Obj    EAX:4          <RETURN>
    //              RGE_Object_Lis    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     00463396(R)  
    //              float             Stack[0x8]:4   param_2                   XREF[4]:     00463310(R), 0046334c(R), 004633b7(R), 0046340e(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[4]:     0046332e(R), 00463343(R), 004633cc(R), 00463408(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[1]:     004633a0(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[1]:     004633a8(R)  
    //              RGE_Static_Obj    Stack[0x18]:4  param_6                   XREF[5]:     0046331e(R), 00463377(W), 0046341a(R), 00463441(R), 
    //                                                                                     0046344e(W)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     0046336d(W), 00463452(W), 00463465(R), 0046347f(R)  
    //              RGE_Static_Obj    Stack[-0x8]:4  found_obj                 XREF[2]:     00463426(W), 0046342e(R)  
    //              float             Stack[-0xc]:4  diff_x
    //                               ?find_by_group@RGE_Object_List@@QAEPAVRGE_Static_Object@@JM
    //                               RGE_Object_List::find_by_group
    //                              obj_list.cpp:474 (51)
    //         00463310     FLD        float ptr [ESP + param_2]
    //         00463314     FCOMP      float ptr [DAT_00570c30]                         = align(2)
    //         0046331a     SUB        ESP,0x8
    //         0046331d     PUSH       EBX
    //         0046331e     MOV        EBX,dword ptr [ESP + param_6]
    //         00463322     FNSTSW     AX
    //         00463324     PUSH       EBP
    //         00463325     PUSH       ESI
    //         00463326     TEST       AH,0x41
    //         00463329     PUSH       EDI
    //         0046332a     MOV        ESI,this
    //         0046332c     JNZ        LAB_00463367
    //         0046332e     FLD        float ptr [ESP + param_3]
    //         00463332     FCOMP      float ptr [DAT_00570c30]                         = align(2)
    //         00463338     FNSTSW     AX
    //         0046333a     TEST       AH,0x41
    //         0046333d     JNZ        LAB_00463367
    //         0046333f     TEST       EBX,EBX
    //         00463341     JZ         LAB_00463367
    //                              obj_list.cpp:484 (34)
    //         00463343     FLD        float ptr [ESP + param_3]
    //         00463347     CALL       __ftol                                           undefined __ftol()
    //         0046334c     FLD        float ptr [ESP + param_2]
    //         00463350     PUSH       EAX
    //         00463351     CALL       __ftol                                           undefined __ftol()
    //         00463356     PUSH       EAX
    //         00463357     MOV        this,EBX
    //         00463359     CALL       RGE_Static_Object::lookupZone                    uchar lookupZone(RGE_Static_Object * this, in
    //         0046335e     AND        EAX,0xff
    //         00463363     MOV        EBP,EAX
    //                              obj_list.cpp:485 (2)
    //         00463365     JMP        LAB_0046336a
    //                               LAB_00463367                                                 XREF[3]:     0046332c(j), 0046333d(j), 
    //                                                                                                         00463341(j)  
    //                              obj_list.cpp:486 (3)
    //         00463367     OR         EBP,0xffffffff
    //                               LAB_0046336a                                                 XREF[1]:     00463365(j)  
    //                              obj_list.cpp:491 (27)
    //         0046336a     MOV        EDI,dword ptr [ESI + 0x4]
    //         0046336d     MOV        dword ptr [ESP + local_4],0x0
    //         00463375     TEST       EDI,EDI
    //         00463377     MOV        dword ptr [ESP + param_6],0xbf800000
    //         0046337f     JZ         LAB_0046347f
    //                               LAB_00463385                                                 XREF[1]:     0046345f(j)  
    //                              obj_list.cpp:493 (50)
    //         00463385     MOV        ESI,dword ptr [EDI]
    //         00463387     TEST       ESI,ESI
    //         00463389     JZ         LAB_0046345a
    //         0046338f     MOV        EAX,dword ptr [ESI + 0x8]
    //         00463392     MOVSX      this,word ptr [EAX + 0x14]
    //         00463396     CMP        this,dword ptr [ESP + param_1]
    //         0046339a     JNZ        LAB_0046345a
    //         004633a0     MOV        AL,byte ptr [ESP + param_4]
    //         004633a4     TEST       AL,AL
    //         004633a6     JZ         LAB_004633b7
    //         004633a8     MOV        DL,byte ptr [ESP + param_5]
    //         004633ac     MOV        AL,byte ptr [ESI + 0x48]
    //         004633af     CMP        AL,DL
    //         004633b1     JNZ        LAB_0046345a
    //                               LAB_004633b7                                                 XREF[1]:     004633a6(j)  
    //                              obj_list.cpp:495 (42)
    //         004633b7     FLD        float ptr [ESP + param_2]
    //         004633bb     FCOMP      float ptr [DAT_00570c30]                         = align(2)
    //         004633c1     FNSTSW     AX
    //         004633c3     TEST       AH,0x40
    //         004633c6     JNZ        LAB_00463473
    //         004633cc     FLD        float ptr [ESP + param_3]
    //         004633d0     FCOMP      float ptr [DAT_00570c30]                         = align(2)
    //         004633d6     FNSTSW     AX
    //         004633d8     TEST       AH,0x40
    //         004633db     JNZ        LAB_00463473
    //                              obj_list.cpp:498 (39)
    //         004633e1     CMP        EBP,-0x1
    //         004633e4     JLE        LAB_00463408
    //         004633e6     FLD        float ptr [ESI + 0x3c]
    //         004633e9     CALL       __ftol                                           undefined __ftol()
    //         004633ee     FLD        float ptr [ESI + 0x38]
    //         004633f1     PUSH       EAX
    //         004633f2     CALL       __ftol                                           undefined __ftol()
    //         004633f7     PUSH       EAX
    //         004633f8     MOV        this,EBX
    //         004633fa     CALL       RGE_Static_Object::lookupZone                    uchar lookupZone(RGE_Static_Object * this, in
    //         004633ff     AND        EAX,0xff
    //         00463404     CMP        EAX,EBP
    //         00463406     JNZ        LAB_0046345a
    //                               LAB_00463408                                                 XREF[1]:     004633e4(j)  
    //                              obj_list.cpp:502 (18)
    //         00463408     FLD        float ptr [ESP + param_3]
    //         0046340c     MOV        this,dword ptr [EDI]
    //         0046340e     FLD        float ptr [ESP + param_2]
    //         00463412     FSUB       float ptr [this->_padding_ + 0x38]
    //         00463415     FXCH
    //         00463417     FSUB       float ptr [this->_padding_ + 0x3c]
    //                              obj_list.cpp:504 (52)
    //         0046341a     FLD        float ptr [ESP + param_6]
    //         0046341e     FCOMP      float ptr [DAT_00570c30]                         = align(2)
    //         00463424     FXCH
    //         00463426     FST        float ptr [ESP + found_obj]
    //         0046342a     FLD        ST1
    //         0046342c     FXCH
    //         0046342e     FMUL       float ptr [ESP + found_obj]
    //         00463432     FXCH
    //         00463434     FMUL       ST2
    //         00463436     FNSTSW     AX
    //         00463438     FADDP
    //         0046343a     TEST       AH,0x40
    //         0046343d     FSTP       ST1
    //         0046343f     JNZ        LAB_0046344e
    //         00463441     FLD        float ptr [ESP + param_6]
    //         00463445     FCOMP
    //         00463447     FNSTSW     AX
    //         00463449     TEST       AH,0x41
    //         0046344c     JNZ        LAB_00463458
    //                               LAB_0046344e                                                 XREF[1]:     0046343f(j)  
    //                              obj_list.cpp:506 (4)
    //         0046344e     FSTP       float ptr [ESP + param_6]
    //                              obj_list.cpp:507 (6)
    //         00463452     MOV        dword ptr [ESP + local_4],this
    //         00463456     JMP        LAB_0046345a
    //                               LAB_00463458                                                 XREF[1]:     0046344c(j)  
    //                              obj_list.cpp:504 (2)
    //         00463458     FSTP       ST0
    //                               LAB_0046345a                                                 XREF[5]:     00463389(j), 0046339a(j), 
    //                                                                                                         004633b1(j), 00463406(j), 
    //                                                                                                         00463456(j)  
    //                              obj_list.cpp:491 (11)
    //         0046345a     MOV        EDI,dword ptr [EDI + 0x4]
    //         0046345d     TEST       EDI,EDI
    //         0046345f     JNZ        LAB_00463385
    //                              obj_list.cpp:511 (4)
    //         00463465     MOV        EAX,dword ptr [ESP + local_4]
    //                              obj_list.cpp:512 (10)
    //         00463469     POP        EDI
    //         0046346a     POP        ESI
    //         0046346b     POP        EBP
    //         0046346c     POP        EBX
    //         0046346d     ADD        ESP,0x8
    //         00463470     RET        0x18
    //                               LAB_00463473                                                 XREF[2]:     004633c6(j), 004633db(j)  
    //                              obj_list.cpp:496 (2)
    //         00463473     MOV        EAX,dword ptr [EDI]
    //                              obj_list.cpp:512 (10)
    //         00463475     POP        EDI
    //         00463476     POP        ESI
    //         00463477     POP        EBP
    //         00463478     POP        EBX
    //         00463479     ADD        ESP,0x8
    //         0046347c     RET        0x18
    //                               LAB_0046347f                                                 XREF[1]:     0046337f(j)  
    //                              obj_list.cpp:511 (4)
    //         0046347f     MOV        EAX,dword ptr [ESP + local_4]
    //                              obj_list.cpp:512 (10)
    //         00463483     POP        EDI
    //         00463484     POP        ESI
    //         00463485     POP        EBP
    //         00463486     POP        EBX
    //         00463487     ADD        ESP,0x8
    //         0046348a     RET        0x18
    //         0046348d     ??         90h
    //         0046348e     NOP
    //         0046348f     NOP
    return 0;
}

RGE_Static_Object* RGE_Object_List::find_by_group(long param_1, float param_2, float param_3, uchar param_4, uchar param_5, RGE_Static_Object* param_6) {
    /* TODO: Stub */
    //                              RGE_Static_Object * __thiscall find_by_group(RGE_Object_List * this,
    //              RGE_Static_Obj    EAX:4          <RETURN>
    //              RGE_Object_Lis    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     004632e7(R)  
    //                               ?find_by_group@RGE_Object_List@@QAEPAVRGE_Static_Object@@J@Z
    //                               RGE_Object_List::find_by_group
    //                              obj_list.cpp:462 (11)
    //         004632e0     MOV        EAX,dword ptr [ECX + this->list]
    //         004632e3     TEST       EAX,EAX
    //         004632e5     JZ         LAB_0046330b
    //         004632e7     MOV        EDX,dword ptr [ESP + param_1]
    //                               LAB_004632eb                                                 XREF[1]:     00463301(j)  
    //                              obj_list.cpp:466 (17)
    //         004632eb     MOV        this,dword ptr [EAX]
    //         004632ed     TEST       this,this
    //         004632ef     JZ         LAB_004632fc
    //         004632f1     MOV        this,dword ptr [ECX + this->number_of_objects]
    //         004632f4     MOVSX      this,word ptr [this->_padding_ + 0x14]
    //         004632f8     CMP        this,EDX
    //         004632fa     JZ         LAB_00463306
    //                               LAB_004632fc                                                 XREF[1]:     004632ef(j)  
    //                              obj_list.cpp:465 (7)
    //         004632fc     MOV        EAX,dword ptr [EAX + 0x4]
    //         004632ff     TEST       EAX,EAX
    //         00463301     JNZ        LAB_004632eb
    //                              obj_list.cpp:469 (3)
    //         00463303     RET        0x4
    //                               LAB_00463306                                                 XREF[1]:     004632fa(j)  
    //                              obj_list.cpp:467 (2)
    //         00463306     MOV        EAX,dword ptr [EAX]
    //                              obj_list.cpp:469 (3)
    //         00463308     RET        0x4
    //                               LAB_0046330b                                                 XREF[1]:     004632e5(j)  
    //                              obj_list.cpp:468 (2)
    //         0046330b     XOR        EAX,EAX
    //                              obj_list.cpp:469 (3)
    //         0046330d     RET        0x4
    //                              * public: class RGE_Static_Object * __thiscall RGE_Object_List::find_by_group(long,float,float,unsig... *
    //                              RGE_Static_Object * __thiscall find_by_group(RGE_Object_List * this,
    //              RGE_Static_Obj    EAX:4          <RETURN>
    //              RGE_Object_Lis    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     00463396(R)  
    //              float             Stack[0x8]:4   param_2                   XREF[4]:     00463310(R), 0046334c(R), 004633b7(R), 0046340e(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[4]:     0046332e(R), 00463343(R), 004633cc(R), 00463408(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[1]:     004633a0(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[1]:     004633a8(R)  
    //              RGE_Static_Obj    Stack[0x18]:4  param_6                   XREF[5]:     0046331e(R), 00463377(W), 0046341a(R), 00463441(R), 
    //                                                                                     0046344e(W)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     0046336d(W), 00463452(W), 00463465(R), 0046347f(R)  
    //              RGE_Static_Obj    Stack[-0x8]:4  found_obj                 XREF[2]:     00463426(W), 0046342e(R)  
    //              float             Stack[-0xc]:4  diff_x
    //                               ?find_by_group@RGE_Object_List@@QAEPAVRGE_Static_Object@@JM
    //                               RGE_Object_List::find_by_group
    //                              obj_list.cpp:474 (51)
    //         00463310     FLD        float ptr [ESP + param_2]
    //         00463314     FCOMP      float ptr [DAT_00570c30]                         = align(2)
    //         0046331a     SUB        ESP,0x8
    //         0046331d     PUSH       EBX
    //         0046331e     MOV        EBX,dword ptr [ESP + param_6]
    //         00463322     FNSTSW     AX
    //         00463324     PUSH       EBP
    //         00463325     PUSH       ESI
    //         00463326     TEST       AH,0x41
    //         00463329     PUSH       EDI
    //         0046332a     MOV        ESI,this
    //         0046332c     JNZ        LAB_00463367
    //         0046332e     FLD        float ptr [ESP + param_3]
    //         00463332     FCOMP      float ptr [DAT_00570c30]                         = align(2)
    //         00463338     FNSTSW     AX
    //         0046333a     TEST       AH,0x41
    //         0046333d     JNZ        LAB_00463367
    //         0046333f     TEST       EBX,EBX
    //         00463341     JZ         LAB_00463367
    //                              obj_list.cpp:484 (34)
    //         00463343     FLD        float ptr [ESP + param_3]
    //         00463347     CALL       __ftol                                           undefined __ftol()
    //         0046334c     FLD        float ptr [ESP + param_2]
    //         00463350     PUSH       EAX
    //         00463351     CALL       __ftol                                           undefined __ftol()
    //         00463356     PUSH       EAX
    //         00463357     MOV        this,EBX
    //         00463359     CALL       RGE_Static_Object::lookupZone                    uchar lookupZone(RGE_Static_Object * this, in
    //         0046335e     AND        EAX,0xff
    //         00463363     MOV        EBP,EAX
    //                              obj_list.cpp:485 (2)
    //         00463365     JMP        LAB_0046336a
    //                               LAB_00463367                                                 XREF[3]:     0046332c(j), 0046333d(j), 
    //                                                                                                         00463341(j)  
    //                              obj_list.cpp:486 (3)
    //         00463367     OR         EBP,0xffffffff
    //                               LAB_0046336a                                                 XREF[1]:     00463365(j)  
    //                              obj_list.cpp:491 (27)
    //         0046336a     MOV        EDI,dword ptr [ESI + 0x4]
    //         0046336d     MOV        dword ptr [ESP + local_4],0x0
    //         00463375     TEST       EDI,EDI
    //         00463377     MOV        dword ptr [ESP + param_6],0xbf800000
    //         0046337f     JZ         LAB_0046347f
    //                               LAB_00463385                                                 XREF[1]:     0046345f(j)  
    //                              obj_list.cpp:493 (50)
    //         00463385     MOV        ESI,dword ptr [EDI]
    //         00463387     TEST       ESI,ESI
    //         00463389     JZ         LAB_0046345a
    //         0046338f     MOV        EAX,dword ptr [ESI + 0x8]
    //         00463392     MOVSX      this,word ptr [EAX + 0x14]
    //         00463396     CMP        this,dword ptr [ESP + param_1]
    //         0046339a     JNZ        LAB_0046345a
    //         004633a0     MOV        AL,byte ptr [ESP + param_4]
    //         004633a4     TEST       AL,AL
    //         004633a6     JZ         LAB_004633b7
    //         004633a8     MOV        DL,byte ptr [ESP + param_5]
    //         004633ac     MOV        AL,byte ptr [ESI + 0x48]
    //         004633af     CMP        AL,DL
    //         004633b1     JNZ        LAB_0046345a
    //                               LAB_004633b7                                                 XREF[1]:     004633a6(j)  
    //                              obj_list.cpp:495 (42)
    //         004633b7     FLD        float ptr [ESP + param_2]
    //         004633bb     FCOMP      float ptr [DAT_00570c30]                         = align(2)
    //         004633c1     FNSTSW     AX
    //         004633c3     TEST       AH,0x40
    //         004633c6     JNZ        LAB_00463473
    //         004633cc     FLD        float ptr [ESP + param_3]
    //         004633d0     FCOMP      float ptr [DAT_00570c30]                         = align(2)
    //         004633d6     FNSTSW     AX
    //         004633d8     TEST       AH,0x40
    //         004633db     JNZ        LAB_00463473
    //                              obj_list.cpp:498 (39)
    //         004633e1     CMP        EBP,-0x1
    //         004633e4     JLE        LAB_00463408
    //         004633e6     FLD        float ptr [ESI + 0x3c]
    //         004633e9     CALL       __ftol                                           undefined __ftol()
    //         004633ee     FLD        float ptr [ESI + 0x38]
    //         004633f1     PUSH       EAX
    //         004633f2     CALL       __ftol                                           undefined __ftol()
    //         004633f7     PUSH       EAX
    //         004633f8     MOV        this,EBX
    //         004633fa     CALL       RGE_Static_Object::lookupZone                    uchar lookupZone(RGE_Static_Object * this, in
    //         004633ff     AND        EAX,0xff
    //         00463404     CMP        EAX,EBP
    //         00463406     JNZ        LAB_0046345a
    //                               LAB_00463408                                                 XREF[1]:     004633e4(j)  
    //                              obj_list.cpp:502 (18)
    //         00463408     FLD        float ptr [ESP + param_3]
    //         0046340c     MOV        this,dword ptr [EDI]
    //         0046340e     FLD        float ptr [ESP + param_2]
    //         00463412     FSUB       float ptr [this->_padding_ + 0x38]
    //         00463415     FXCH
    //         00463417     FSUB       float ptr [this->_padding_ + 0x3c]
    //                              obj_list.cpp:504 (52)
    //         0046341a     FLD        float ptr [ESP + param_6]
    //         0046341e     FCOMP      float ptr [DAT_00570c30]                         = align(2)
    //         00463424     FXCH
    //         00463426     FST        float ptr [ESP + found_obj]
    //         0046342a     FLD        ST1
    //         0046342c     FXCH
    //         0046342e     FMUL       float ptr [ESP + found_obj]
    //         00463432     FXCH
    //         00463434     FMUL       ST2
    //         00463436     FNSTSW     AX
    //         00463438     FADDP
    //         0046343a     TEST       AH,0x40
    //         0046343d     FSTP       ST1
    //         0046343f     JNZ        LAB_0046344e
    //         00463441     FLD        float ptr [ESP + param_6]
    //         00463445     FCOMP
    //         00463447     FNSTSW     AX
    //         00463449     TEST       AH,0x41
    //         0046344c     JNZ        LAB_00463458
    //                               LAB_0046344e                                                 XREF[1]:     0046343f(j)  
    //                              obj_list.cpp:506 (4)
    //         0046344e     FSTP       float ptr [ESP + param_6]
    //                              obj_list.cpp:507 (6)
    //         00463452     MOV        dword ptr [ESP + local_4],this
    //         00463456     JMP        LAB_0046345a
    //                               LAB_00463458                                                 XREF[1]:     0046344c(j)  
    //                              obj_list.cpp:504 (2)
    //         00463458     FSTP       ST0
    //                               LAB_0046345a                                                 XREF[5]:     00463389(j), 0046339a(j), 
    //                                                                                                         004633b1(j), 00463406(j), 
    //                                                                                                         00463456(j)  
    //                              obj_list.cpp:491 (11)
    //         0046345a     MOV        EDI,dword ptr [EDI + 0x4]
    //         0046345d     TEST       EDI,EDI
    //         0046345f     JNZ        LAB_00463385
    //                              obj_list.cpp:511 (4)
    //         00463465     MOV        EAX,dword ptr [ESP + local_4]
    //                              obj_list.cpp:512 (10)
    //         00463469     POP        EDI
    //         0046346a     POP        ESI
    //         0046346b     POP        EBP
    //         0046346c     POP        EBX
    //         0046346d     ADD        ESP,0x8
    //         00463470     RET        0x18
    //                               LAB_00463473                                                 XREF[2]:     004633c6(j), 004633db(j)  
    //                              obj_list.cpp:496 (2)
    //         00463473     MOV        EAX,dword ptr [EDI]
    //                              obj_list.cpp:512 (10)
    //         00463475     POP        EDI
    //         00463476     POP        ESI
    //         00463477     POP        EBP
    //         00463478     POP        EBX
    //         00463479     ADD        ESP,0x8
    //         0046347c     RET        0x18
    //                               LAB_0046347f                                                 XREF[1]:     0046337f(j)  
    //                              obj_list.cpp:511 (4)
    //         0046347f     MOV        EAX,dword ptr [ESP + local_4]
    //                              obj_list.cpp:512 (10)
    //         00463483     POP        EDI
    //         00463484     POP        ESI
    //         00463485     POP        EBP
    //         00463486     POP        EBX
    //         00463487     ADD        ESP,0x8
    //         0046348a     RET        0x18
    //         0046348d     ??         90h
    //         0046348e     NOP
    //         0046348f     NOP
    return 0;
}

RGE_Static_Object* RGE_Object_List::find_by_id(long param_1) {
    /* TODO: Stub */
    //                              RGE_Static_Object * __thiscall find_by_id(RGE_Object_List * this, lo
    //              RGE_Static_Obj    EAX:4          <RETURN>
    //              RGE_Object_Lis    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     00463497(R)  
    //                               ?find_by_id@RGE_Object_List@@QAEPAVRGE_Static_Object@@J@Z    XREF[11]:    get_object_pointer:004c426b(c), 
    //                               RGE_Object_List::find_by_id                                               get_object_pointer:004c427f(c), 
    //                                                                                                         get_object_pointer:004c4293(c), 
    //                                                                                                         get_object_pointer:004c42d2(c), 
    //                                                                                                         get_object_pointer:004c42eb(c), 
    //                                                                                                         get_object_pointer:004c4304(c), 
    //                                                                                                         RGE_Timeline:0050d704(c), 
    //                                                                                                         RGE_Timeline:0050d73b(c), 
    //                                                                                                         RGE_Victory_Conditions:005318ed(c)
    //                                                                                                         RGE_Victory_Conditions:00531935(c)
    //                                                                                                         RGE_Victory_Conditions:0053197c(c)
    //                              obj_list.cpp:517 (11)
    //         00463490     MOV        EAX,dword ptr [ECX + this->list]
    //         00463493     TEST       EAX,EAX
    //         00463495     JZ         LAB_004634b5
    //         00463497     MOV        EDX,dword ptr [ESP + param_1]
    //                               LAB_0046349b                                                 XREF[1]:     004634ab(j)  
    //                              obj_list.cpp:521 (11)
    //         0046349b     MOV        this,dword ptr [EAX]
    //         0046349d     TEST       this,this
    //         0046349f     JZ         LAB_004634a6
    //         004634a1     CMP        dword ptr [ECX + this->list],EDX
    //         004634a4     JZ         LAB_004634b0
    //                               LAB_004634a6                                                 XREF[1]:     0046349f(j)  
    //                              obj_list.cpp:520 (7)
    //         004634a6     MOV        EAX,dword ptr [EAX + 0x4]
    //         004634a9     TEST       EAX,EAX
    //         004634ab     JNZ        LAB_0046349b
    //                              obj_list.cpp:524 (3)
    //         004634ad     RET        0x4
    //                               LAB_004634b0                                                 XREF[1]:     004634a4(j)  
    //                              obj_list.cpp:522 (2)
    //         004634b0     MOV        EAX,dword ptr [EAX]
    //                              obj_list.cpp:524 (3)
    //         004634b2     RET        0x4
    //                               LAB_004634b5                                                 XREF[1]:     00463495(j)  
    //                              obj_list.cpp:523 (2)
    //         004634b5     XOR        EAX,EAX
    //                              obj_list.cpp:524 (3)
    //         004634b7     RET        0x4
    //         004634ba     ??         90h
    //         004634bb     NOP
    //         004634bc     NOP
    //         004634bd     NOP
    //         004634be     NOP
    //         004634bf     NOP
    //                              * public: class RGE_Static_Object * __thiscall RGE_Object_List::find_by_master_id(long,float,float,u... *
    //                              RGE_Static_Object * __thiscall find_by_master_id(RGE_Object_List * t
    //              RGE_Static_Obj    EAX:4          <RETURN>
    //              RGE_Object_Lis    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     00463546(R)  
    //              float             Stack[0x8]:4   param_2                   XREF[4]:     004634c0(R), 004634fc(R), 00463567(R), 004635be(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[4]:     004634de(R), 004634f3(R), 0046357c(R), 004635b8(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[1]:     00463550(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[1]:     00463558(R)  
    //              RGE_Static_Obj    Stack[0x18]:4  param_6                   XREF[5]:     004634ce(R), 00463527(W), 004635ca(R), 004635f1(R), 
    //                                                                                     004635fe(W)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     0046351d(W), 00463602(W), 00463615(R), 0046362f(R)  
    //              RGE_Static_Obj    Stack[-0x8]:4  found_obj                 XREF[2]:     004635d6(W), 004635de(R)  
    //              float             Stack[-0xc]:4  diff_x
    //                               ?find_by_master_id@RGE_Object_List@@QAEPAVRGE_Static_Object  XREF[17]:    TribeDiplomacyDialog:0043d54f(c), 
    //                               RGE_Object_List::find_by_master_id                                        set_object_state:004c89f7(c), 
    //                                                                                                         check:004c8f4a(c), 
    //                                                                                                         check:004c8fae(c), 
    //                                                                                                         check:004c900a(c), 
    //                                                                                                         check:004c9065(c), 
    //                                                                                                         processAICommand:004e6660(c), 
    //                                                                                                         checkForCoopTributeGift:00502956(c
    //                                                                                                         random_start:0051437b(c), 
    //                                                                                                         random_start:00514419(c), 
    //                                                                                                         draw:0051ba7e(c), 
    //                                                                                                         cheat:00530b44(c), 
    //                                                                                                         cheat:00530b92(c), 
    //                                                                                                         cheat:00530ddb(c), 
    //                                                                                                         cheat:00530e55(c), 
    //                                                                                                         cheat:00530ea3(c), 
    //                                                                                                         cheat:0053105c(c)  
    //                              obj_list.cpp:531 (51)
    //         004634c0     FLD        float ptr [ESP + param_2]
    //         004634c4     FCOMP      float ptr [DAT_00570c30]                         = align(2)
    //         004634ca     SUB        ESP,0x8
    //         004634cd     PUSH       EBX
    //         004634ce     MOV        EBX,dword ptr [ESP + param_6]
    //         004634d2     FNSTSW     AX
    //         004634d4     PUSH       EBP
    //         004634d5     PUSH       ESI
    //         004634d6     TEST       AH,0x41
    //         004634d9     PUSH       EDI
    //         004634da     MOV        ESI,this
    //         004634dc     JNZ        LAB_00463517
    //         004634de     FLD        float ptr [ESP + param_3]
    //         004634e2     FCOMP      float ptr [DAT_00570c30]                         = align(2)
    //         004634e8     FNSTSW     AX
    //         004634ea     TEST       AH,0x41
    //         004634ed     JNZ        LAB_00463517
    //         004634ef     TEST       EBX,EBX
    //         004634f1     JZ         LAB_00463517
    //                              obj_list.cpp:541 (34)
    //         004634f3     FLD        float ptr [ESP + param_3]
    //         004634f7     CALL       __ftol                                           undefined __ftol()
    //         004634fc     FLD        float ptr [ESP + param_2]
    //         00463500     PUSH       EAX
    //         00463501     CALL       __ftol                                           undefined __ftol()
    //         00463506     PUSH       EAX
    //         00463507     MOV        this,EBX
    //         00463509     CALL       RGE_Static_Object::lookupZone                    uchar lookupZone(RGE_Static_Object * this, in
    //         0046350e     AND        EAX,0xff
    //         00463513     MOV        EBP,EAX
    //                              obj_list.cpp:542 (2)
    //         00463515     JMP        LAB_0046351a
    //                               LAB_00463517                                                 XREF[3]:     004634dc(j), 004634ed(j), 
    //                                                                                                         004634f1(j)  
    //                              obj_list.cpp:543 (3)
    //         00463517     OR         EBP,0xffffffff
    //                               LAB_0046351a                                                 XREF[1]:     00463515(j)  
    //                              obj_list.cpp:548 (27)
    //         0046351a     MOV        EDI,dword ptr [ESI + 0x4]
    //         0046351d     MOV        dword ptr [ESP + local_4],0x0
    //         00463525     TEST       EDI,EDI
    //         00463527     MOV        dword ptr [ESP + param_6],0xbf800000
    //         0046352f     JZ         LAB_0046362f
    //                               LAB_00463535                                                 XREF[1]:     0046360f(j)  
    //                              obj_list.cpp:550 (50)
    //         00463535     MOV        ESI,dword ptr [EDI]
    //         00463537     TEST       ESI,ESI
    //         00463539     JZ         LAB_0046360a
    //         0046353f     MOV        EAX,dword ptr [ESI + 0x8]
    //         00463542     MOVSX      this,word ptr [EAX + 0x10]
    //         00463546     CMP        this,dword ptr [ESP + param_1]
    //         0046354a     JNZ        LAB_0046360a
    //         00463550     MOV        AL,byte ptr [ESP + param_4]
    //         00463554     TEST       AL,AL
    //         00463556     JZ         LAB_00463567
    //         00463558     MOV        DL,byte ptr [ESP + param_5]
    //         0046355c     MOV        AL,byte ptr [ESI + 0x48]
    //         0046355f     CMP        AL,DL
    //         00463561     JNZ        LAB_0046360a
    //                               LAB_00463567                                                 XREF[1]:     00463556(j)  
    //                              obj_list.cpp:552 (42)
    //         00463567     FLD        float ptr [ESP + param_2]
    //         0046356b     FCOMP      float ptr [DAT_00570c30]                         = align(2)
    //         00463571     FNSTSW     AX
    //         00463573     TEST       AH,0x40
    //         00463576     JNZ        LAB_00463623
    //         0046357c     FLD        float ptr [ESP + param_3]
    //         00463580     FCOMP      float ptr [DAT_00570c30]                         = align(2)
    //         00463586     FNSTSW     AX
    //         00463588     TEST       AH,0x40
    //         0046358b     JNZ        LAB_00463623
    //                              obj_list.cpp:555 (39)
    //         00463591     CMP        EBP,-0x1
    //         00463594     JLE        LAB_004635b8
    //         00463596     FLD        float ptr [ESI + 0x3c]
    //         00463599     CALL       __ftol                                           undefined __ftol()
    //         0046359e     FLD        float ptr [ESI + 0x38]
    //         004635a1     PUSH       EAX
    //         004635a2     CALL       __ftol                                           undefined __ftol()
    //         004635a7     PUSH       EAX
    //         004635a8     MOV        this,EBX
    //         004635aa     CALL       RGE_Static_Object::lookupZone                    uchar lookupZone(RGE_Static_Object * this, in
    //         004635af     AND        EAX,0xff
    //         004635b4     CMP        EAX,EBP
    //         004635b6     JNZ        LAB_0046360a
    //                               LAB_004635b8                                                 XREF[1]:     00463594(j)  
    //                              obj_list.cpp:559 (18)
    //         004635b8     FLD        float ptr [ESP + param_3]
    //         004635bc     MOV        this,dword ptr [EDI]
    //         004635be     FLD        float ptr [ESP + param_2]
    //         004635c2     FSUB       float ptr [this->_padding_ + 0x38]
    //         004635c5     FXCH
    //         004635c7     FSUB       float ptr [this->_padding_ + 0x3c]
    //                              obj_list.cpp:561 (52)
    //         004635ca     FLD        float ptr [ESP + param_6]
    //         004635ce     FCOMP      float ptr [DAT_00570c30]                         = align(2)
    //         004635d4     FXCH
    //         004635d6     FST        float ptr [ESP + found_obj]
    //         004635da     FLD        ST1
    //         004635dc     FXCH
    //         004635de     FMUL       float ptr [ESP + found_obj]
    //         004635e2     FXCH
    //         004635e4     FMUL       ST2
    //         004635e6     FNSTSW     AX
    //         004635e8     FADDP
    //         004635ea     TEST       AH,0x40
    //         004635ed     FSTP       ST1
    //         004635ef     JNZ        LAB_004635fe
    //         004635f1     FLD        float ptr [ESP + param_6]
    //         004635f5     FCOMP
    //         004635f7     FNSTSW     AX
    //         004635f9     TEST       AH,0x41
    //         004635fc     JNZ        LAB_00463608
    //                               LAB_004635fe                                                 XREF[1]:     004635ef(j)  
    //                              obj_list.cpp:563 (4)
    //         004635fe     FSTP       float ptr [ESP + param_6]
    //                              obj_list.cpp:564 (6)
    //         00463602     MOV        dword ptr [ESP + local_4],this
    //         00463606     JMP        LAB_0046360a
    //                               LAB_00463608                                                 XREF[1]:     004635fc(j)  
    //                              obj_list.cpp:561 (2)
    //         00463608     FSTP       ST0
    //                               LAB_0046360a                                                 XREF[5]:     00463539(j), 0046354a(j), 
    //                                                                                                         00463561(j), 004635b6(j), 
    //                                                                                                         00463606(j)  
    //                              obj_list.cpp:548 (11)
    //         0046360a     MOV        EDI,dword ptr [EDI + 0x4]
    //         0046360d     TEST       EDI,EDI
    //         0046360f     JNZ        LAB_00463535
    //                              obj_list.cpp:568 (4)
    //         00463615     MOV        EAX,dword ptr [ESP + local_4]
    //                              obj_list.cpp:569 (10)
    //         00463619     POP        EDI
    //         0046361a     POP        ESI
    //         0046361b     POP        EBP
    //         0046361c     POP        EBX
    //         0046361d     ADD        ESP,0x8
    //         00463620     RET        0x18
    //                               LAB_00463623                                                 XREF[2]:     00463576(j), 0046358b(j)  
    //                              obj_list.cpp:553 (2)
    //         00463623     MOV        EAX,dword ptr [EDI]
    //                              obj_list.cpp:569 (10)
    //         00463625     POP        EDI
    //         00463626     POP        ESI
    //         00463627     POP        EBP
    //         00463628     POP        EBX
    //         00463629     ADD        ESP,0x8
    //         0046362c     RET        0x18
    //                               LAB_0046362f                                                 XREF[1]:     0046352f(j)  
    //                              obj_list.cpp:568 (4)
    //         0046362f     MOV        EAX,dword ptr [ESP + local_4]
    //                              obj_list.cpp:569 (10)
    //         00463633     POP        EDI
    //         00463634     POP        ESI
    //         00463635     POP        EBP
    //         00463636     POP        EBX
    //         00463637     ADD        ESP,0x8
    //         0046363a     RET        0x18
    //         0046363d     ??         90h
    //         0046363e     NOP
    //         0046363f     NOP
    //                              * public: class RGE_Static_Object * __thiscall RGE_Object_List::find_by_master_ids(long,long,float,f... *
    //                              RGE_Static_Object * __thiscall find_by_master_ids(RGE_Object_List * 
    //              RGE_Static_Obj    EAX:4          <RETURN>
    //              RGE_Object_Lis    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     004636c6(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     004636cc(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[4]:     00463651(R), 0046367c(R), 004636ed(R), 00463740(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[4]:     00463662(R), 00463673(R), 004636fe(R), 0046373a(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[1]:     004636d6(R)  
    //              uchar             Stack[0x18]:1  param_6                   XREF[1]:     004636de(R)  
    //              RGE_Static_Obj    Stack[0x1c]:4  param_7                   XREF[5]:     00463644(R), 004636a7(W), 0046374c(R), 00463773(R), 
    //                                                                                     00463780(W)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     0046369d(W), 00463784(W), 00463797(R), 004637b1(R)  
    //              RGE_Static_Obj    Stack[-0x8]:4  found_obj                 XREF[2]:     00463758(W), 00463760(R)  
    //              float             Stack[-0xc]:4  diff_x
    //                               ?find_by_master_ids@RGE_Object_List@@QAEPAVRGE_Static_Objec  XREF[4]:     set_state:004033b9(c), 
    //                               RGE_Object_List::find_by_master_ids                                       set_state:004033ea(c), 
    //                                                                                                         set_state:004cf69e(c), 
    //                                                                                                         set_state:004d2b47(c)  
    //                              obj_list.cpp:575 (4)
    //         00463640     SUB        ESP,0x8
    //         00463643     PUSH       EBX
    //                              obj_list.cpp:585 (47)
    //         00463644     MOV        EBX,dword ptr [ESP + param_7]
    //         00463648     PUSH       EBP
    //         00463649     PUSH       ESI
    //         0046364a     TEST       EBX,EBX
    //         0046364c     PUSH       EDI
    //         0046364d     MOV        ESI,this
    //         0046364f     JZ         LAB_00463697
    //         00463651     FLD        float ptr [ESP + param_3]
    //         00463655     FCOMP      float ptr [DAT_00570c30]                         = align(2)
    //         0046365b     FNSTSW     AX
    //         0046365d     TEST       AH,0x41
    //         00463660     JNZ        LAB_00463697
    //         00463662     FLD        float ptr [ESP + param_4]
    //         00463666     FCOMP      float ptr [DAT_00570c30]                         = align(2)
    //         0046366c     FNSTSW     AX
    //         0046366e     TEST       AH,0x41
    //         00463671     JNZ        LAB_00463697
    //                              obj_list.cpp:586 (34)
    //         00463673     FLD        float ptr [ESP + param_4]
    //         00463677     CALL       __ftol                                           undefined __ftol()
    //         0046367c     FLD        float ptr [ESP + param_3]
    //         00463680     PUSH       EAX
    //         00463681     CALL       __ftol                                           undefined __ftol()
    //         00463686     PUSH       EAX
    //         00463687     MOV        this,EBX
    //         00463689     CALL       RGE_Static_Object::lookupZone                    uchar lookupZone(RGE_Static_Object * this, in
    //         0046368e     AND        EAX,0xff
    //         00463693     MOV        EBP,EAX
    //                              obj_list.cpp:587 (2)
    //         00463695     JMP        LAB_0046369a
    //                               LAB_00463697                                                 XREF[3]:     0046364f(j), 00463660(j), 
    //                                                                                                         00463671(j)  
    //                              obj_list.cpp:588 (3)
    //         00463697     OR         EBP,0xffffffff
    //                               LAB_0046369a                                                 XREF[1]:     00463695(j)  
    //                              obj_list.cpp:593 (27)
    //         0046369a     MOV        EDI,dword ptr [ESI + 0x4]
    //         0046369d     MOV        dword ptr [ESP + local_4],0x0
    //         004636a5     TEST       EDI,EDI
    //         004636a7     MOV        dword ptr [ESP + param_7],0xbf800000
    //         004636af     JZ         LAB_004637b1
    //                               LAB_004636b5                                                 XREF[1]:     00463791(j)  
    //                              obj_list.cpp:595 (2)
    //         004636b5     MOV        ESI,dword ptr [EDI]
    //                              obj_list.cpp:596 (54)
    //         004636b7     TEST       ESI,ESI
    //         004636b9     MOV        EAX,dword ptr [ESI + 0x8]
    //         004636bc     MOVSX      EAX,word ptr [EAX + 0x10]
    //         004636c0     JZ         LAB_0046378c
    //         004636c6     CMP        EAX,dword ptr [ESP + param_1]
    //         004636ca     JZ         LAB_004636d6
    //         004636cc     CMP        EAX,dword ptr [ESP + param_2]
    //         004636d0     JNZ        LAB_0046378c
    //                               LAB_004636d6                                                 XREF[1]:     004636ca(j)  
    //         004636d6     MOV        AL,byte ptr [ESP + param_5]
    //         004636da     TEST       AL,AL
    //         004636dc     JZ         LAB_004636ed
    //         004636de     MOV        this,byte ptr [ESP + param_6]
    //         004636e2     MOV        AL,byte ptr [ESI + 0x48]
    //         004636e5     CMP        AL,this
    //         004636e7     JNZ        LAB_0046378c
    //                               LAB_004636ed                                                 XREF[1]:     004636dc(j)  
    //                              obj_list.cpp:598 (38)
    //         004636ed     FLD        float ptr [ESP + param_3]
    //         004636f1     FCOMP      float ptr [DAT_00570c30]                         = align(2)
    //         004636f7     FNSTSW     AX
    //         004636f9     TEST       AH,0x40
    //         004636fc     JZ         LAB_00463713
    //         004636fe     FLD        float ptr [ESP + param_4]
    //         00463702     FCOMP      float ptr [DAT_00570c30]                         = align(2)
    //         00463708     FNSTSW     AX
    //         0046370a     TEST       AH,0x40
    //         0046370d     JNZ        LAB_004637a5
    //                               LAB_00463713                                                 XREF[1]:     004636fc(j)  
    //                              obj_list.cpp:601 (39)
    //         00463713     CMP        EBP,-0x1
    //         00463716     JLE        LAB_0046373a
    //         00463718     FLD        float ptr [ESI + 0x3c]
    //         0046371b     CALL       __ftol                                           undefined __ftol()
    //         00463720     FLD        float ptr [ESI + 0x38]
    //         00463723     PUSH       EAX
    //         00463724     CALL       __ftol                                           undefined __ftol()
    //         00463729     PUSH       EAX
    //         0046372a     MOV        this,EBX
    //         0046372c     CALL       RGE_Static_Object::lookupZone                    uchar lookupZone(RGE_Static_Object * this, in
    //         00463731     AND        EAX,0xff
    //         00463736     CMP        EAX,EBP
    //         00463738     JNZ        LAB_0046378c
    //                               LAB_0046373a                                                 XREF[1]:     00463716(j)  
    //                              obj_list.cpp:605 (18)
    //         0046373a     FLD        float ptr [ESP + param_4]
    //         0046373e     MOV        this,dword ptr [EDI]
    //         00463740     FLD        float ptr [ESP + param_3]
    //         00463744     FSUB       float ptr [this->_padding_ + 0x38]
    //         00463747     FXCH
    //         00463749     FSUB       float ptr [this->_padding_ + 0x3c]
    //                              obj_list.cpp:607 (52)
    //         0046374c     FLD        float ptr [ESP + param_7]
    //         00463750     FCOMP      float ptr [DAT_00570c30]                         = align(2)
    //         00463756     FXCH
    //         00463758     FST        float ptr [ESP + found_obj]
    //         0046375c     FLD        ST1
    //         0046375e     FXCH
    //         00463760     FMUL       float ptr [ESP + found_obj]
    //         00463764     FXCH
    //         00463766     FMUL       ST2
    //         00463768     FNSTSW     AX
    //         0046376a     FADDP
    //         0046376c     TEST       AH,0x40
    //         0046376f     FSTP       ST1
    //         00463771     JNZ        LAB_00463780
    //         00463773     FLD        float ptr [ESP + param_7]
    //         00463777     FCOMP
    //         00463779     FNSTSW     AX
    //         0046377b     TEST       AH,0x41
    //         0046377e     JNZ        LAB_0046378a
    //                               LAB_00463780                                                 XREF[1]:     00463771(j)  
    //                              obj_list.cpp:609 (4)
    //         00463780     FSTP       float ptr [ESP + param_7]
    //                              obj_list.cpp:610 (6)
    //         00463784     MOV        dword ptr [ESP + local_4],this
    //         00463788     JMP        LAB_0046378c
    //                               LAB_0046378a                                                 XREF[1]:     0046377e(j)  
    //                              obj_list.cpp:607 (2)
    //         0046378a     FSTP       ST0
    //                               LAB_0046378c                                                 XREF[5]:     004636c0(j), 004636d0(j), 
    //                                                                                                         004636e7(j), 00463738(j), 
    //                                                                                                         00463788(j)  
    //                              obj_list.cpp:593 (11)
    //         0046378c     MOV        EDI,dword ptr [EDI + 0x4]
    //         0046378f     TEST       EDI,EDI
    //         00463791     JNZ        LAB_004636b5
    //                              obj_list.cpp:614 (4)
    //         00463797     MOV        EAX,dword ptr [ESP + local_4]
    //                              obj_list.cpp:615 (10)
    //         0046379b     POP        EDI
    //         0046379c     POP        ESI
    //         0046379d     POP        EBP
    //         0046379e     POP        EBX
    //         0046379f     ADD        ESP,0x8
    //         004637a2     RET        0x1c
    //                               LAB_004637a5                                                 XREF[1]:     0046370d(j)  
    //                              obj_list.cpp:599 (2)
    //         004637a5     MOV        EAX,dword ptr [EDI]
    //                              obj_list.cpp:615 (10)
    //         004637a7     POP        EDI
    //         004637a8     POP        ESI
    //         004637a9     POP        EBP
    //         004637aa     POP        EBX
    //         004637ab     ADD        ESP,0x8
    //         004637ae     RET        0x1c
    //                               LAB_004637b1                                                 XREF[1]:     004636af(j)  
    //                              obj_list.cpp:614 (4)
    //         004637b1     MOV        EAX,dword ptr [ESP + local_4]
    //                              obj_list.cpp:615 (10)
    //         004637b5     POP        EDI
    //         004637b6     POP        ESI
    //         004637b7     POP        EBP
    //         004637b8     POP        EBX
    //         004637b9     ADD        ESP,0x8
    //         004637bc     RET        0x1c
    //         004637bf     ??         90h
    //                              * public: class RGE_Static_Object * __thiscall RGE_Object_List::find_by_type(unsigned char,float,flo... *
    //                              RGE_Static_Object * __thiscall find_by_type(RGE_Object_List * this, 
    //              RGE_Static_Obj    EAX:4          <RETURN>
    //              RGE_Object_Lis    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004637e6(R)  
    //              float             Stack[0x8]:4   param_2                   XREF[2]:     004637fc(R), 00463822(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[2]:     0046380d(R), 0046381e(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[1]:     004637ef(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[3]:     004637d8(R), 0046383a(W), 00463842(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     004637ca(W), 0046382e(R), 00463855(R), 00463862(W)  
    //              float             Stack[-0x8]:4  dist
    //                               ?find_by_type@RGE_Object_List@@QAEPAVRGE_Static_Object@@EMM
    //                               RGE_Object_List::find_by_type
    //                              obj_list.cpp:621 (1)
    //         004637c0     PUSH       this
    //                              obj_list.cpp:632 (27)
    //         004637c1     MOV        EDX,dword ptr [ECX + this->list]
    //         004637c4     PUSH       EBX
    //         004637c5     PUSH       ESI
    //         004637c6     XOR        ESI,ESI
    //         004637c8     TEST       EDX,EDX
    //         004637ca     MOV        dword ptr [ESP + local_4],0xbf800000
    //         004637d2     JZ         LAB_00463887
    //         004637d8     MOV        BL,byte ptr [ESP + param_5]
    //                               LAB_004637dc                                                 XREF[1]:     00463871(j)  
    //                              obj_list.cpp:634 (32)
    //         004637dc     MOV        this,dword ptr [EDX]
    //         004637de     TEST       this,this
    //         004637e0     JZ         LAB_0046386c
    //         004637e6     MOV        AL,byte ptr [ESP + param_1]
    //         004637ea     CMP        byte ptr [this->_padding_ + 0x4e],AL
    //         004637ed     JNZ        LAB_0046386c
    //         004637ef     MOV        AL,byte ptr [ESP + param_4]
    //         004637f3     TEST       AL,AL
    //         004637f5     JZ         LAB_004637fc
    //         004637f7     CMP        byte ptr [this->_padding_ + 0x48],BL
    //         004637fa     JNZ        LAB_0046386c
    //                               LAB_004637fc                                                 XREF[1]:     004637f5(j)  
    //                              obj_list.cpp:636 (34)
    //         004637fc     FLD        float ptr [ESP + param_2]
    //         00463800     FCOMP      float ptr [DAT_00570c30]                         = align(2)
    //         00463806     FNSTSW     AX
    //         00463808     TEST       AH,0x40
    //         0046380b     JZ         LAB_0046381e
    //         0046380d     FLD        float ptr [ESP + param_3]
    //         00463811     FCOMP      float ptr [DAT_00570c30]                         = align(2)
    //         00463817     FNSTSW     AX
    //         00463819     TEST       AH,0x40
    //         0046381c     JNZ        LAB_0046387f
    //                               LAB_0046381e                                                 XREF[1]:     0046380b(j)  
    //                              obj_list.cpp:639 (16)
    //         0046381e     FLD        float ptr [ESP + param_3]
    //         00463822     FLD        float ptr [ESP + param_2]
    //         00463826     FSUB       float ptr [this->_padding_ + 0x38]
    //         00463829     FXCH
    //         0046382b     FSUB       float ptr [this->_padding_ + 0x3c]
    //                              obj_list.cpp:641 (52)
    //         0046382e     FLD        float ptr [ESP + local_4]
    //         00463832     FCOMP      float ptr [DAT_00570c30]                         = align(2)
    //         00463838     FXCH
    //         0046383a     FST        float ptr [ESP + param_5]
    //         0046383e     FLD        ST1
    //         00463840     FXCH
    //         00463842     FMUL       float ptr [ESP + param_5]
    //         00463846     FXCH
    //         00463848     FMUL       ST2
    //         0046384a     FNSTSW     AX
    //         0046384c     FADDP
    //         0046384e     TEST       AH,0x40
    //         00463851     FSTP       ST1
    //         00463853     JNZ        LAB_00463862
    //         00463855     FLD        float ptr [ESP + local_4]
    //         00463859     FCOMP
    //         0046385b     FNSTSW     AX
    //         0046385d     TEST       AH,0x41
    //         00463860     JNZ        LAB_0046386a
    //                               LAB_00463862                                                 XREF[1]:     00463853(j)  
    //                              obj_list.cpp:643 (4)
    //         00463862     FSTP       float ptr [ESP + local_4]
    //                              obj_list.cpp:644 (4)
    //         00463866     MOV        ESI,this
    //         00463868     JMP        LAB_0046386c
    //                               LAB_0046386a                                                 XREF[1]:     00463860(j)  
    //                              obj_list.cpp:641 (2)
    //         0046386a     FSTP       ST0
    //                               LAB_0046386c                                                 XREF[4]:     004637e0(j), 004637ed(j), 
    //                                                                                                         004637fa(j), 00463868(j)  
    //                              obj_list.cpp:632 (11)
    //         0046386c     MOV        EDX,dword ptr [EDX + 0x4]
    //         0046386f     TEST       EDX,EDX
    //         00463871     JNZ        LAB_004637dc
    //                              obj_list.cpp:648 (2)
    //         00463877     MOV        EAX,ESI
    //                              obj_list.cpp:649 (6)
    //         00463879     POP        ESI
    //         0046387a     POP        EBX
    //         0046387b     POP        this
    //         0046387c     RET        0x14
    //                               LAB_0046387f                                                 XREF[1]:     0046381c(j)  
    //                              obj_list.cpp:637 (2)
    //         0046387f     MOV        EAX,dword ptr [EDX]
    //                              obj_list.cpp:649 (6)
    //         00463881     POP        ESI
    //         00463882     POP        EBX
    //         00463883     POP        this
    //         00463884     RET        0x14
    //                               LAB_00463887                                                 XREF[1]:     004637d2(j)  
    //                              obj_list.cpp:648 (2)
    //         00463887     MOV        EAX,ESI
    //                              obj_list.cpp:649 (6)
    //         00463889     POP        ESI
    //         0046388a     POP        EBX
    //         0046388b     POP        this
    //         0046388c     RET        0x14
    //         0046388f     ??         90h
    return 0;
}

void RGE_Object_List::save(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall save(RGE_Object_List * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Object_Lis    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00463896(R)  
    //              undefined1        Stack[-0x1]:1  local_1                   XREF[2]:     0046389c(W), 004638b6(*)  
    //              uchar             Stack[-0x5]:1  finished
    //                               ?save@RGE_Object_List@@QAEXH@Z                               XREF[3]:     save2:0047043e(c), 
    //                               RGE_Object_List::save                                                     save2:00470455(c), 
    //                                                                                                         save2:0047046c(c)  
    //                              obj_list.cpp:655 (2)
    //         00463890     PUSH       this
    //         00463891     PUSH       ESI
    //                              obj_list.cpp:659 (17)
    //         00463892     MOV        ESI,dword ptr [ECX + this->list]
    //         00463895     PUSH       EDI
    //         00463896     MOV        EDI,dword ptr [ESP + param_1]
    //         0046389a     TEST       ESI,ESI
    //         0046389c     MOV        byte ptr [ESP + local_1],0x0
    //         004638a1     JZ         LAB_004638b6
    //                               LAB_004638a3                                                 XREF[1]:     004638b4(j)  
    //                              obj_list.cpp:660 (6)
    //         004638a3     MOV        this,dword ptr [ESI]
    //         004638a5     TEST       this,this
    //         004638a7     JZ         LAB_004638af
    //                              obj_list.cpp:661 (13)
    //         004638a9     MOV        EAX,dword ptr [this->_padding_]
    //         004638ab     PUSH       EDI
    //         004638ac     CALL       dword ptr [EAX + 0x30]
    //                               LAB_004638af                                                 XREF[1]:     004638a7(j)  
    //         004638af     MOV        ESI,dword ptr [ESI + 0x4]
    //         004638b2     TEST       ESI,ESI
    //         004638b4     JNZ        LAB_004638a3
    //                               LAB_004638b6                                                 XREF[1]:     004638a1(j)  
    //                              obj_list.cpp:662 (16)
    //         004638b6     LEA        this=>local_1,[ESP + 0xb]
    //         004638ba     PUSH       0x1
    //         004638bc     PUSH       this=>DAT_fffffff8
    //         004638bd     PUSH       EDI=>DAT_fffffff4
    //         004638be     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004638c3     ADD        ESP,0xc
    //                              obj_list.cpp:663 (6)
    //         004638c6     POP        EDI
    //         004638c7     POP        ESI
    //         004638c8     POP        this
    //         004638c9     RET        0x4
    //         004638cc     ??         90h
    //         004638cd     NOP
    //         004638ce     NOP
    //         004638cf     NOP
    return;
}

void RGE_Object_List::load_list(int param_1, RGE_Game_World* param_2) {
    /* TODO: Stub */
    //                              void __thiscall load_list(RGE_Object_List * this, int param_1, RGE_G
    //              void              <VOID>         <RETURN>
    //              RGE_Object_Lis    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004638d6(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[3]:     004638d1(R), 004638dd(*), 004638ea(R)  
    //                               ?load_list@RGE_Object_List@@QAEXHPAVRGE_Game_World@@@Z       XREF[6]:     load:0046fb9c(c), 
    //                               RGE_Object_List::load_list                                                load:0046fc01(c), 
    //                                                                                                         load:0046fc21(c), 
    //                                                                                                         load:005129e4(c), 
    //                                                                                                         load:00512a24(c), 
    //                                                                                                         load:00512a6f(c)  
    //                              obj_list.cpp:668 (13)
    //         004638d0     PUSH       EBX
    //         004638d1     MOV        EBX,dword ptr [ESP + param_2]
    //         004638d5     PUSH       ESI
    //         004638d6     MOV        ESI,dword ptr [ESP + param_1]
    //         004638da     PUSH       EDI
    //         004638db     MOV        EDI,this
    //                               LAB_004638dd                                                 XREF[1]:     004638fe(j)  
    //                              obj_list.cpp:674 (13)
    //         004638dd     LEA        EAX=>param_2,[ESP + 0x14]
    //         004638e1     PUSH       0x1
    //         004638e3     PUSH       EAX=>DAT_fffffff8
    //         004638e4     PUSH       ESI=>DAT_fffffff4
    //         004638e5     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              obj_list.cpp:675 (11)
    //         004638ea     MOV        EAX,dword ptr [ESP + param_2]
    //         004638ee     ADD        ESP,0xc
    //         004638f1     TEST       AL,AL
    //         004638f3     JZ         LAB_00463900
    //                              obj_list.cpp:677 (11)
    //         004638f5     MOV        EDX,dword ptr [EDI]
    //         004638f7     PUSH       EBX
    //         004638f8     PUSH       ESI
    //         004638f9     PUSH       EAX
    //         004638fa     MOV        this,EDI
    //         004638fc     CALL       dword ptr [EDX]
    //         004638fe     JMP        LAB_004638dd
    //                               LAB_00463900                                                 XREF[1]:     004638f3(j)  
    //                              obj_list.cpp:682 (7)
    //         00463900     MOV        this,EDI
    //         00463902     CALL       RGE_Object_List::invert                          void invert(RGE_Object_List * this)
    //                              obj_list.cpp:683 (6)
    //         00463907     POP        EDI
    //         00463908     POP        ESI
    //         00463909     POP        EBX
    //         0046390a     RET        0x8
    //         0046390d     ??         90h
    //         0046390e     NOP
    //         0046390f     NOP
    return;
}

void RGE_Object_List::rehook_list() {
    /* TODO: Stub */
    //                              void __thiscall rehook_list(RGE_Object_List * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Object_Lis    ECX:4 (auto)   this
    //                               ?rehook_list@RGE_Object_List@@QAEXXZ                         XREF[3]:     load_info:0046ff19(c), 
    //                               RGE_Object_List::rehook_list                                              load_info:0046ff21(c), 
    //                                                                                                         load_info:0046ff29(c)  
    //                              obj_list.cpp:688 (1)
    //         00463910     PUSH       ESI
    //                              obj_list.cpp:691 (7)
    //         00463911     MOV        ESI,dword ptr [ECX + this->list]
    //         00463914     TEST       ESI,ESI
    //         00463916     JZ         LAB_00463926
    //                               LAB_00463918                                                 XREF[1]:     00463924(j)  
    //                              obj_list.cpp:692 (14)
    //         00463918     MOV        this,dword ptr [ESI]
    //         0046391a     MOV        EAX,dword ptr [this->_padding_]
    //         0046391c     CALL       dword ptr [EAX + 0x2c]
    //         0046391f     MOV        ESI,dword ptr [ESI + 0x4]
    //         00463922     TEST       ESI,ESI
    //         00463924     JNZ        LAB_00463918
    //                               LAB_00463926                                                 XREF[1]:     00463916(j)  
    //                              obj_list.cpp:693 (2)
    //         00463926     POP        ESI
    //         00463927     RET
    //         00463928     ??         90h
    //         00463929     NOP
    //         0046392a     NOP
    //         0046392b     NOP
    //         0046392c     NOP
    //         0046392d     NOP
    //         0046392e     NOP
    //         0046392f     NOP
    return;
}

void RGE_Object_List::load(uchar param_1, int param_2, RGE_Game_World* param_3) {
    /* TODO: Stub */
    //                              void __thiscall load(RGE_Object_List * this, uchar param_1, int para
    //              void              <VOID>         <RETURN>
    //              RGE_Object_Lis    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[8]:     0046393e(R), 00463976(W), 004639bb(W), 00463a00(W), 
    //                                                                                     00463a45(W), 00463a8a(W), 00463acf(W), 00463b10(W)  
    //              int               Stack[0x8]:4   param_2                   XREF[7]:     0046398e(R), 004639d3(R), 00463a18(R), 00463a5d(R), 
    //                                                                                     00463aa2(R), 00463ae3(R), 00463b24(R)  
    //              RGE_Game_World    Stack[0xc]:4   param_3                   XREF[7]:     0046398a(R), 004639cf(R), 00463a14(R), 00463a59(R), 
    //                                                                                     00463a9e(R), 00463adf(R), 00463b20(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[7]:     0046397c(W), 004639c1(W), 00463a06(W), 00463a4b(W), 
    //                                                                                     00463a90(W), 00463ad5(W), 00463b16(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[7]:     0046399d(*), 004639e2(*), 00463a27(*), 00463a6c(*), 
    //                                                                                     00463ab1(*), 00463af2(*), 00463b33(*)  
    //                               ?load@RGE_Object_List@@MAEXEHPAVRGE_Game_World@@@Z           XREF[2]:     load:00511b2c(c), 00570c2c(*)  
    //                               RGE_Object_List::load
    //                              obj_list.cpp:700 (14)
    //         00463930     MOV        EAX,FS:[0x0]
    //         00463936     PUSH       -0x1
    //         00463938     PUSH       FUN_0055de1d
    //         0046393d     PUSH       EAX
    //                              obj_list.cpp:701 (43)
    //         0046393e     MOV        EAX,dword ptr [ESP + param_1]
    //         00463942     MOV        dword ptr FS:[0x0],ESP
    //         00463949     AND        EAX,0xff
    //         0046394e     ADD        EAX,-0xa
    //         00463951     CMP        EAX,0x32
    //         00463954     JA         switchD_00463962::caseD_b
    //         0046395a     XOR        this,this
    //         0046395c     MOV        this,byte ptr [EAX + 0x463b64]=>PTR_caseD_32_0
    //                               switchD_00463962::switchD
    //         00463962     JMP        dword ptr [this->_padding_*0x4 + switchD_00463   = 00463969
    //                               switchD_00463962::caseD_a                                    XREF[2]:     00463962(j), 00463b44(*)  
    //                              obj_list.cpp:704 (52)
    //         00463969     PUSH       0x88
    //         0046396e     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00463973     ADD        ESP,0x4
    //         00463976     MOV        dword ptr [ESP + param_1],EAX
    //         0046397a     TEST       EAX,EAX
    //         0046397c     MOV        dword ptr [ESP + local_4],0x0
    //         00463984     JZ         switchD_00463962::caseD_b
    //         0046398a     MOV        EDX,dword ptr [ESP + param_3]
    //         0046398e     MOV        this,dword ptr [ESP + param_2]
    //         00463992     PUSH       0x1
    //         00463994     PUSH       EDX
    //         00463995     PUSH       this
    //         00463996     MOV        this,EAX
    //         00463998     CALL       RGE_Static_Object::RGE_Static_Object             undefined RGE_Static_Object(RGE_Static_Object
    //                              obj_list.cpp:729 (17)
    //         0046399d     MOV        this,dword ptr [ESP]=>local_c
    //         004639a1     MOV        dword ptr FS:[0x0],this
    //         004639a8     ADD        ESP,0xc
    //         004639ab     RET        0xc
    //                               switchD_00463962::caseD_14                                   XREF[2]:     00463962(j), 00463b48(*)  
    //                              obj_list.cpp:707 (52)
    //         004639ae     PUSH       0x8c
    //         004639b3     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004639b8     ADD        ESP,0x4
    //         004639bb     MOV        dword ptr [ESP + param_1],EAX
    //         004639bf     TEST       EAX,EAX
    //         004639c1     MOV        dword ptr [ESP + local_4],0x1
    //         004639c9     JZ         switchD_00463962::caseD_b
    //         004639cf     MOV        EDX,dword ptr [ESP + param_3]
    //         004639d3     MOV        this,dword ptr [ESP + param_2]
    //         004639d7     PUSH       0x1
    //         004639d9     PUSH       EDX
    //         004639da     PUSH       this
    //         004639db     MOV        this,EAX
    //         004639dd     CALL       RGE_Animated_Object::RGE_Animated_Object         undefined RGE_Animated_Object(RGE_Animated_Ob
    //                              obj_list.cpp:729 (17)
    //         004639e2     MOV        this,dword ptr [ESP]=>local_c
    //         004639e6     MOV        dword ptr FS:[0x0],this
    //         004639ed     ADD        ESP,0xc
    //         004639f0     RET        0xc
    //                               switchD_00463962::caseD_19                                   XREF[2]:     00463962(j), 00463b4c(*)  
    //                              obj_list.cpp:710 (52)
    //         004639f3     PUSH       0xb0
    //         004639f8     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004639fd     ADD        ESP,0x4
    //         00463a00     MOV        dword ptr [ESP + param_1],EAX
    //         00463a04     TEST       EAX,EAX
    //         00463a06     MOV        dword ptr [ESP + local_4],0x2
    //         00463a0e     JZ         switchD_00463962::caseD_b
    //         00463a14     MOV        EDX,dword ptr [ESP + param_3]
    //         00463a18     MOV        this,dword ptr [ESP + param_2]
    //         00463a1c     PUSH       0x1
    //         00463a1e     PUSH       EDX
    //         00463a1f     PUSH       this
    //         00463a20     MOV        this,EAX
    //         00463a22     CALL       RGE_Doppleganger_Object::RGE_Doppleganger_Object undefined RGE_Doppleganger_Object(RGE_Doppleg
    //                              obj_list.cpp:729 (17)
    //         00463a27     MOV        this,dword ptr [ESP]=>local_c
    //         00463a2b     MOV        dword ptr FS:[0x0],this
    //         00463a32     ADD        ESP,0xc
    //         00463a35     RET        0xc
    //                               switchD_00463962::caseD_1e                                   XREF[2]:     00463962(j), 00463b50(*)  
    //                              obj_list.cpp:713 (52)
    //         00463a38     PUSH       0x180
    //         00463a3d     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00463a42     ADD        ESP,0x4
    //         00463a45     MOV        dword ptr [ESP + param_1],EAX
    //         00463a49     TEST       EAX,EAX
    //         00463a4b     MOV        dword ptr [ESP + local_4],0x3
    //         00463a53     JZ         switchD_00463962::caseD_b
    //         00463a59     MOV        EDX,dword ptr [ESP + param_3]
    //         00463a5d     MOV        this,dword ptr [ESP + param_2]
    //         00463a61     PUSH       0x1
    //         00463a63     PUSH       EDX
    //         00463a64     PUSH       this
    //         00463a65     MOV        this,EAX
    //         00463a67     CALL       RGE_Moving_Object::RGE_Moving_Object             undefined RGE_Moving_Object(RGE_Moving_Object
    //                              obj_list.cpp:729 (17)
    //         00463a6c     MOV        this,dword ptr [ESP]=>local_c
    //         00463a70     MOV        dword ptr FS:[0x0],this
    //         00463a77     ADD        ESP,0xc
    //         00463a7a     RET        0xc
    //                               switchD_00463962::caseD_3c                                   XREF[2]:     00463962(j), 00463b5c(*)  
    //                              obj_list.cpp:716 (52)
    //         00463a7d     PUSH       0x1c8
    //         00463a82     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00463a87     ADD        ESP,0x4
    //         00463a8a     MOV        dword ptr [ESP + param_1],EAX
    //         00463a8e     TEST       EAX,EAX
    //         00463a90     MOV        dword ptr [ESP + local_4],0x4
    //         00463a98     JZ         switchD_00463962::caseD_b
    //         00463a9e     MOV        EDX,dword ptr [ESP + param_3]
    //         00463aa2     MOV        this,dword ptr [ESP + param_2]
    //         00463aa6     PUSH       0x1
    //         00463aa8     PUSH       EDX
    //         00463aa9     PUSH       this
    //         00463aaa     MOV        this,EAX
    //         00463aac     CALL       RGE_Missile_Object::RGE_Missile_Object           undefined RGE_Missile_Object(RGE_Missile_Obje
    //                              obj_list.cpp:729 (17)
    //         00463ab1     MOV        this,dword ptr [ESP]=>local_c
    //         00463ab5     MOV        dword ptr FS:[0x0],this
    //         00463abc     ADD        ESP,0xc
    //         00463abf     RET        0xc
    //                               switchD_00463962::caseD_28                                   XREF[2]:     00463962(j), 00463b54(*)  
    //                              obj_list.cpp:719 (48)
    //         00463ac2     PUSH       0x194
    //         00463ac7     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00463acc     ADD        ESP,0x4
    //         00463acf     MOV        dword ptr [ESP + param_1],EAX
    //         00463ad3     TEST       EAX,EAX
    //         00463ad5     MOV        dword ptr [ESP + local_4],0x5
    //         00463add     JZ         switchD_00463962::caseD_b
    //         00463adf     MOV        EDX,dword ptr [ESP + param_3]
    //         00463ae3     MOV        this,dword ptr [ESP + param_2]
    //         00463ae7     PUSH       0x1
    //         00463ae9     PUSH       EDX
    //         00463aea     PUSH       this
    //         00463aeb     MOV        this,EAX
    //         00463aed     CALL       RGE_Action_Object::RGE_Action_Object             undefined RGE_Action_Object(RGE_Action_Object
    //                              obj_list.cpp:729 (17)
    //         00463af2     MOV        this,dword ptr [ESP]=>local_c
    //         00463af6     MOV        dword ptr FS:[0x0],this
    //         00463afd     ADD        ESP,0xc
    //         00463b00     RET        0xc
    //                               switchD_00463962::caseD_32                                   XREF[2]:     00463962(j), 00463b58(*)  
    //                              obj_list.cpp:722 (48)
    //         00463b03     PUSH       0x1c4
    //         00463b08     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00463b0d     ADD        ESP,0x4
    //         00463b10     MOV        dword ptr [ESP + param_1],EAX
    //         00463b14     TEST       EAX,EAX
    //         00463b16     MOV        dword ptr [ESP + local_4],0x6
    //         00463b1e     JZ         switchD_00463962::caseD_b
    //         00463b20     MOV        EDX,dword ptr [ESP + param_3]
    //         00463b24     MOV        this,dword ptr [ESP + param_2]
    //         00463b28     PUSH       0x1
    //         00463b2a     PUSH       EDX
    //         00463b2b     PUSH       this
    //         00463b2c     MOV        this,EAX
    //         00463b2e     CALL       RGE_Combat_Object::RGE_Combat_Object             undefined RGE_Combat_Object(RGE_Combat_Object
    //                               switchD_00463962::caseD_c                                    XREF[10]:    00463954(j), 00463962(j), 
    //                               switchD_00463962::caseD_d                                                 00463984(j), 004639c9(j), 
    //                               switchD_00463962::caseD_e                                                 00463a0e(j), 00463a53(j), 
    //                               switchD_00463962::caseD_f                                                 00463a98(j), 00463add(j), 
    //                               switchD_00463962::caseD_10                                                00463b1e(j), 00463b60(*)  
    //                               switchD_00463962::caseD_11
    //                               switchD_00463962::caseD_12
    //                               switchD_00463962::caseD_13
    //                               switchD_00463962::caseD_15
    //                               switchD_00463962::caseD_16
    //                               switchD_00463962::caseD_17
    //                               switchD_00463962::caseD_18
    //                               switchD_00463962::caseD_1a
    //                               switchD_00463962::caseD_1b
    //                               switchD_00463962::caseD_1c
    //                               switchD_00463962::caseD_1d
    //                               switchD_00463962::caseD_1f
    //                               switchD_00463962::caseD_20
    //                               switchD_00463962::caseD_21
    //                               switchD_00463962::caseD_22
    //                               switchD_00463962::caseD_23
    //                               switchD_00463962::caseD_24
    //                               switchD_00463962::caseD_25
    //                               switchD_00463962::caseD_26
    //                               switchD_00463962::caseD_27
    //                               switchD_00463962::caseD_29
    //                               switchD_00463962::caseD_2a
    //                               switchD_00463962::caseD_2b
    //                               switchD_00463962::caseD_2c
    //                               switchD_00463962::caseD_2d
    //                               switchD_00463962::caseD_2e
    //                               switchD_00463962::caseD_2f
    //                               switchD_00463962::caseD_30
    //                               switchD_00463962::caseD_31
    //                               switchD_00463962::caseD_33
    //                               switchD_00463962::caseD_34
    //                               switchD_00463962::caseD_35
    //                               switchD_00463962::caseD_36
    //                               switchD_00463962::caseD_37
    //                               switchD_00463962::caseD_38
    //                               switchD_00463962::caseD_39
    //                               switchD_00463962::caseD_3a
    //                               switchD_00463962::caseD_3b
    //                               switchD_00463962::caseD_b
    //                              obj_list.cpp:729 (100)
    //         00463b33     MOV        this,dword ptr [ESP]=>local_c
    //         00463b37     MOV        dword ptr FS:[0x0],this
    //         00463b3e     ADD        ESP,0xc
    //         00463b41     RET        0xc
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00463962::switchdataD_00463b44                       XREF[1]:     load:00463962(*)  
    //         00463b44     addr       switchD_00463962::caseD_a
    //         00463b48     addr       switchD_00463962::caseD_14
    //         00463b4c     addr       switchD_00463962::caseD_19
    //         00463b50     addr       switchD_00463962::caseD_1e
    //         00463b54     addr       switchD_00463962::caseD_28
    //                               PTR_caseD_32_00463b58+2                                      XREF[0,1]:   load:0046395c(*)  
    //         00463b58     addr       switchD_00463962::caseD_32
    //         00463b5c     addr       switchD_00463962::caseD_3c
    //         00463b60     addr       switchD_00463962::caseD_b
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00463962::switchdataD_00463b64
    //         00463b64     db         0h
    //         00463b65     db         7h
    //         00463b66     db         7h
    //         00463b67     db         7h
    //         00463b68     db         7h
    //         00463b69     db         7h
    //         00463b6a     db         7h
    //         00463b6b     db         7h
    //         00463b6c     db         7h
    //         00463b6d     db         7h
    //         00463b6e     db         1h
    //         00463b6f     db         7h
    //         00463b70     db         7h
    //         00463b71     db         7h
    //         00463b72     db         7h
    //         00463b73     db         2h
    //         00463b74     db         7h
    //         00463b75     db         7h
    //         00463b76     db         7h
    //         00463b77     db         7h
    //         00463b78     db         3h
    //         00463b79     db         7h
    //         00463b7a     db         7h
    //         00463b7b     db         7h
    //         00463b7c     db         7h
    //         00463b7d     db         7h
    //         00463b7e     db         7h
    //         00463b7f     db         7h
    //         00463b80     db         7h
    //         00463b81     db         7h
    //         00463b82     db         4h
    //         00463b83     db         7h
    //         00463b84     db         7h
    //         00463b85     db         7h
    //         00463b86     db         7h
    //         00463b87     db         7h
    //         00463b88     db         7h
    //         00463b89     db         7h
    //         00463b8a     db         7h
    //         00463b8b     db         7h
    //         00463b8c     db         5h
    //         00463b8d     db         7h
    //         00463b8e     db         7h
    //         00463b8f     db         7h
    //         00463b90     db         7h
    //         00463b91     db         7h
    //         00463b92     db         7h
    //         00463b93     db         7h
    //         00463b94     db         7h
    //         00463b95     db         7h
    //         00463b96     db         6h
    //         00463b97     ??         90h
    //         00463b98     ??         90h
    //         00463b99     ??         90h
    //         00463b9a     ??         90h
    //         00463b9b     ??         90h
    //         00463b9c     ??         90h
    //         00463b9d     ??         90h
    //         00463b9e     ??         90h
    //         00463b9f     ??         90h
    //                              *                                               FUNCTION                                                *
    //                              undefined $E4()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               $E4
    //         00463ba0     CALL       $E1                                              undefined $E1()
    //         00463ba5     JMP        $E3                                              undefined $E3()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
    //         00463baa     ??         90h
    //         00463bab     NOP
    //         00463bac     NOP
    //         00463bad     NOP
    //         00463bae     NOP
    //         00463baf     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined $E1()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               $E1                                                          XREF[1]:     $E4:00463ba0(c)  
    //                              Panel.cpp:31 (10)
    //         00463bb0     MOV        ECX,panel_system
    //         00463bb5     JMP        TPanelSystem::TPanelSystem                       undefined TPanelSystem(TPanelSystem * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
    //         00463bba     ??         90h
    //         00463bbb     NOP
    //         00463bbc     NOP
    //         00463bbd     NOP
    //         00463bbe     NOP
    //         00463bbf     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined $E3()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               $E3                                                          XREF[1]:     $E4:00463ba5(c)  
    //         00463bc0     PUSH       $E2
    //         00463bc5     CALL       atexit                                           undefined atexit()
    //         00463bca     ADD        ESP,0x4
    //         00463bcd     RET
    //         00463bce     ??         90h
    //         00463bcf     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined $E2()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               $E2                                                          XREF[1]:     $E3:00463bc0(*)  
    //         00463bd0     MOV        ECX,panel_system
    //         00463bd5     JMP        TPanelSystem::~TPanelSystem                      void ~TPanelSystem(TPanelSystem * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
    //         00463bda     ??         90h
    //         00463bdb     NOP
    //         00463bdc     NOP
    //         00463bdd     NOP
    //         00463bde     NOP
    //         00463bdf     NOP
    return;
}

void RGE_Object_List::remove_node(RGE_Static_Object* param_1, RGE_Object_Node* param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

void RGE_Object_List::shadow_draw(TDrawArea* param_1, short param_2, short param_3, uchar param_4, uchar param_5) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

RGE_Static_Object* RGE_Object_List::find_by_master_id(long param_1, float param_2, float param_3, uchar param_4, uchar param_5, RGE_Static_Object* param_6) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

RGE_Static_Object* RGE_Object_List::find_by_master_ids(long param_1, long param_2, float param_3, float param_4, uchar param_5, uchar param_6, RGE_Static_Object* param_7) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

RGE_Static_Object* RGE_Object_List::find_by_type(uchar param_1, float param_2, float param_3, uchar param_4, uchar param_5) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

