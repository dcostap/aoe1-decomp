#include "common.h"
#include "scr_sed.h"

TRIBE_Screen_Sed::TRIBE_Screen_Sed(char* param_1, int param_2) {
    /* TODO: Stub */
    //                              undefined __thiscall TRIBE_Screen_Sed(TRIBE_Screen_Sed * this, char 
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1
    //              int               Stack[0x8]:4   param_2
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004a8218(W)  
    //              char[260]         Stack[-0x114   temp_name
    //              char[260]         Stack[-0x218   name                      XREF[1]:     004a8206(W)  
    //                               ??0TRIBE_Screen_Sed@@QAE@PADH@Z                              XREF[1]:     start_scenario_editor:00528e36(c)  
    //                               TRIBE_Screen_Sed::TRIBE_Screen_Sed
    //                              scr_sed.cpp:249 (49)
    //         004a81e0     PUSH       -0x1
    //         004a81e2     PUSH       FUN_0055f453
    //         004a81e7     MOV        EAX,FS:[0x0]
    //         004a81ed     PUSH       EAX
    //         004a81ee     MOV        dword ptr FS:[0x0],ESP
    //         004a81f5     SUB        ESP,0x210
    //         004a81fb     PUSH       EBX
    //         004a81fc     PUSH       EBP
    //         004a81fd     PUSH       ESI
    //         004a81fe     PUSH       EDI
    //         004a81ff     MOV        ESI,this
    //         004a8201     PUSH       s_Scenario_Editor_Screen                         = "Scenario Editor Screen"
    //         004a8206     MOV        dword ptr [ESP + name[0]],ESI
    //         004a820a     CALL       TScreenPanel::TScreenPanel                       undefined TScreenPanel(TScreenPanel * this, c
    //         004a820f     XOR        EBX,EBX
    //                              scr_sed.cpp:265 (5)
    //         004a8211     MOV        EDI,0x1
    //                              scr_sed.cpp:274 (103)
    //         004a8216     MOV        this,ESI
    //         004a8218     MOV        dword ptr [ESP + local_4],EBX
    //         004a821f     MOV        dword ptr [ESI],TRIBE_Screen_Sed::`vftable'      = 004a8750
    //         004a8225     MOV        dword ptr [ESI + 0x478],EBX
    //         004a822b     MOV        dword ptr [ESI + 0x4a4],EBX
    //         004a8231     MOV        dword ptr [ESI + 0x4a8],EBX
    //         004a8237     MOV        dword ptr [ESI + 0x4ac],0x2
    //         004a8241     MOV        dword ptr [ESI + 0x4b0],EBX
    //         004a8247     MOV        dword ptr [ESI + 0x4b4],EBX
    //         004a824d     MOV        word ptr [ESI + 0x4b8],DI
    //         004a8254     MOV        dword ptr [ESI + 0x4bc],EBX
    //         004a825a     MOV        dword ptr [ESI + 0x480],EBX
    //         004a8260     MOV        dword ptr [ESI + 0x484],EBX
    //         004a8266     MOV        dword ptr [ESI + 0x49c],EBX
    //         004a826c     MOV        byte ptr [ESI + 0x4c0],BL
    //         004a8272     MOV        byte ptr [ESI + 0x4c1],BL
    //         004a8278     CALL       TRIBE_Screen_Sed::init_module_variables          void init_module_variables(TRIBE_Screen_Sed *
    //                              scr_sed.cpp:279 (34)
    //         004a827d     PUSH       0x117
    //         004a8282     PUSH       s_C:\msdev\work\age1_x1\scr_sed.cp               = "C:\\msdev\\work\\age1_x1\\scr_sed.cpp"
    //         004a8287     MOV        dword ptr [ESI + 0x92c],0xc8
    //         004a8291     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         004a8296     ADD        ESP,0x8
    //         004a8299     MOV        dword ptr [ESI + 0x930],EAX
    //                              scr_sed.cpp:281 (10)
    //         004a829f     MOV        dword ptr [ESI + 0x934],0x3e8
    //                              scr_sed.cpp:282 (21)
    //         004a82a9     PUSH       0x11a
    //         004a82ae     PUSH       s_C:\msdev\work\age1_x1\scr_sed.cp               = "C:\\msdev\\work\\age1_x1\\scr_sed.cpp"
    //         004a82b3     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         004a82b8     MOV        dword ptr [ESI + 0x938],EAX
    //                              scr_sed.cpp:284 (6)
    //         004a82be     MOV        dword ptr [ESI + 0x940],EBX
    //                              scr_sed.cpp:285 (6)
    //         004a82c4     MOV        dword ptr [ESI + 0x944],EBX
    //                              scr_sed.cpp:286 (6)
    //         004a82ca     MOV        dword ptr [ESI + 0x93c],EBX
    //                              scr_sed.cpp:287 (6)
    //         004a82d0     MOV        dword ptr [ESI + 0x498],EBX
    //                              scr_sed.cpp:290 (16)
    //         004a82d6     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004a82dc     ADD        ESP,0x8
    //         004a82df     MOV        EAX,dword ptr [this->_padding_]
    //         004a82e1     PUSH       0x7
    //         004a82e3     CALL       dword ptr [EAX + 0xc]
    //                              scr_sed.cpp:295 (39)
    //         004a82e6     MOV        this,dword ptr [ESP + 0x234]
    //         004a82ed     MOV        EBP,dword ptr [ESP + 0x230]
    //         004a82f4     PUSH       EDI
    //         004a82f5     PUSH       offset DAT_fffffff8
    //         004a82fa     PUSH       offset DAT_fffffff4
    //         004a82ff     PUSH       EBX=>DAT_fffffff0
    //         004a8300     PUSH       this
    //         004a8301     PUSH       EBP
    //         004a8302     MOV        this,ESI
    //         004a8304     CALL       TRIBE_Screen_Sed::command_new_map                int command_new_map(TRIBE_Screen_Sed * this, 
    //         004a8309     TEST       EAX,EAX
    //         004a830b     JNZ        LAB_004a8318
    //                              scr_sed.cpp:297 (6)
    //         004a830d     MOV        dword ptr [ESI + 0xd8],EDI
    //                              scr_sed.cpp:298 (5)
    //         004a8313     JMP        LAB_004a8728
    //                               LAB_004a8318                                                 XREF[1]:     004a830b(j)  
    //                              scr_sed.cpp:302 (45)
    //         004a8318     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         004a831e     PUSH       s_Game_File_Number                               = "Game File Number"
    //         004a8323     PUSH       EBX=>DAT_fffffff8
    //         004a8324     MOV        this,dword ptr [EDX + 0x1ac]
    //         004a832a     CALL       TRegistry::RegGetInt                             int RegGetInt(TRegistry * this, int param_1, 
    //         004a832f     PUSH       EAX
    //         004a8330     LEA        EAX,[ESP + 0x120]
    //         004a8337     PUSH       s_default%d.scx                                  = "default%d.scx"
    //         004a833c     PUSH       EAX=>DAT_fffffff4
    //         004a833d     CALL       sprintf                                          undefined sprintf()
    //         004a8342     ADD        ESP,0xc
    //                              scr_sed.cpp:303 (58)
    //         004a8345     CMP        EBP,EBX
    //         004a8347     JZ         LAB_004a8386
    //         004a8349     LEA        EDI,[ESP + 0x11c]
    //         004a8350     MOV        EAX,EBP
    //                               LAB_004a8352                                                 XREF[1]:     004a8370(j)  
    //         004a8352     MOV        DL,byte ptr [EAX]
    //         004a8354     MOV        this,DL
    //         004a8356     CMP        DL,byte ptr [EDI]
    //         004a8358     JNZ        LAB_004a8376
    //         004a835a     CMP        this,BL
    //         004a835c     JZ         LAB_004a8372
    //         004a835e     MOV        DL,byte ptr [EAX + 0x1]
    //         004a8361     MOV        this,DL
    //         004a8363     CMP        DL,byte ptr [EDI + 0x1]
    //         004a8366     JNZ        LAB_004a8376
    //         004a8368     ADD        EAX,0x2
    //         004a836b     ADD        EDI,0x2
    //         004a836e     CMP        this,BL
    //         004a8370     JNZ        LAB_004a8352
    //                               LAB_004a8372                                                 XREF[1]:     004a835c(j)  
    //         004a8372     XOR        EAX,EAX
    //         004a8374     JMP        LAB_004a837b
    //                               LAB_004a8376                                                 XREF[2]:     004a8358(j), 004a8366(j)  
    //         004a8376     SBB        EAX,EAX
    //         004a8378     SBB        EAX,-0x1
    //                               LAB_004a837b                                                 XREF[1]:     004a8374(j)  
    //         004a837b     CMP        EAX,EBX
    //         004a837d     JNZ        LAB_004a8386
    //                              scr_sed.cpp:304 (7)
    //         004a837f     MOV        byte ptr [ESI + 0x4c0],0x1
    //                               LAB_004a8386                                                 XREF[2]:     004a8347(j), 004a837d(j)  
    //                              scr_sed.cpp:309 (30)
    //         004a8386     MOV        EAX,[rge_base_game]                              = 00000000
    //         004a838b     PUSH       0x1
    //         004a838d     PUSH       offset DAT_fffffff8
    //         004a8392     PUSH       s_scr5                                           = "scr5"
    //         004a8397     MOV        this,dword ptr [EAX + 0x4c]
    //         004a839a     PUSH       this=>DAT_fffffff0
    //         004a839b     MOV        this,ESI
    //         004a839d     CALL       TScreenPanel::setup                              long setup(TScreenPanel * this, TDrawArea * p
    //         004a83a2     TEST       EAX,EAX
    //                              scr_sed.cpp:312 (6)
    //         004a83a4     JZ         LAB_004a871e
    //                              scr_sed.cpp:315 (8)
    //         004a83aa     PUSH       EBX
    //         004a83ab     MOV        this,ESI
    //         004a83ad     CALL       TEasy_Panel::setup_shadow_area                   void setup_shadow_area(TEasy_Panel * this, in
    //                              scr_sed.cpp:322 (50)
    //         004a83b2     PUSH       0x380
    //         004a83b7     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004a83bc     MOV        EDI,EAX
    //         004a83be     ADD        ESP,0x4
    //         004a83c1     MOV        dword ptr [ESP + 0x10],EDI
    //         004a83c5     CMP        EDI,EBX
    //         004a83c7     MOV        byte ptr [ESP + 0x228],0x1
    //         004a83cf     JZ         LAB_004a83e2
    //         004a83d1     MOV        this,EDI
    //         004a83d3     CALL       RGE_Main_View::RGE_Main_View                     undefined RGE_Main_View(RGE_Main_View * this)
    //         004a83d8     MOV        dword ptr [EDI],TRIBE_Main_View::`vftable'       = 00495470
    //         004a83de     MOV        this,EDI
    //         004a83e0     JMP        LAB_004a83e4
    //                               LAB_004a83e2                                                 XREF[1]:     004a83cf(j)  
    //         004a83e2     XOR        this,this
    //                               LAB_004a83e4                                                 XREF[1]:     004a83e0(j)  
    //                              scr_sed.cpp:323 (33)
    //         004a83e4     CMP        this,EBX
    //         004a83e6     MOV        byte ptr [ESP + 0x228],BL
    //         004a83ed     MOV        dword ptr [ESI + 0x4c8],this
    //         004a83f3     JZ         LAB_004a871e
    //         004a83f9     CMP        dword ptr [ECX + this->_padding_],EBX
    //         004a83ff     JNZ        LAB_004a871e
    //                              scr_sed.cpp:330 (27)
    //         004a8405     MOV        EDX,dword ptr [ESI + 0x20]
    //         004a8408     PUSH       s_bordline                                       = "bordline"
    //         004a840d     PUSH       EBX=>DAT_fffffff8
    //         004a840e     PUSH       offset DAT_fffffff4
    //         004a8413     PUSH       EBX=>DAT_fffffff0
    //         004a8414     PUSH       EBX
    //         004a8415     PUSH       EBX
    //         004a8416     PUSH       EBX
    //         004a8417     PUSH       ESI
    //         004a8418     PUSH       EDX
    //         004a8419     CALL       RGE_View::setup                                  long setup(RGE_View * this, TDrawArea * param
    //         004a841e     TEST       EAX,EAX
    //                              scr_sed.cpp:333 (6)
    //         004a8420     JZ         LAB_004a871e
    //                              scr_sed.cpp:339 (40)
    //         004a8426     PUSH       0x16c
    //         004a842b     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004a8430     ADD        ESP,0x4
    //         004a8433     MOV        dword ptr [ESP + 0x10],EAX
    //         004a8437     CMP        EAX,EBX
    //         004a8439     MOV        byte ptr [ESP + 0x228],0x2
    //         004a8441     JZ         LAB_004a844c
    //         004a8443     MOV        this,EAX
    //         004a8445     CALL       RGE_Diamond_Map_View::RGE_Diamond_Map_View       undefined RGE_Diamond_Map_View(RGE_Diamond_Ma
    //         004a844a     JMP        LAB_004a844e
    //                               LAB_004a844c                                                 XREF[1]:     004a8441(j)  
    //         004a844c     XOR        EAX,EAX
    //                               LAB_004a844e                                                 XREF[1]:     004a844a(j)  
    //                              scr_sed.cpp:340 (33)
    //         004a844e     CMP        EAX,EBX
    //         004a8450     MOV        byte ptr [ESP + 0x228],BL
    //         004a8457     MOV        dword ptr [ESI + 0x4cc],EAX
    //         004a845d     JZ         LAB_004a871e
    //         004a8463     CMP        dword ptr [EAX + 0xd8],EBX
    //         004a8469     JNZ        LAB_004a871e
    //                              scr_sed.cpp:345 (37)
    //         004a846f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004a8475     MOV        EDX,dword ptr [this->_padding_ + 0xa20]
    //         004a847b     MOV        this,dword ptr [ESI + 0x20]
    //         004a847e     PUSH       EDX
    //         004a847f     PUSH       EBX=>DAT_fffffff8
    //         004a8480     PUSH       offset DAT_fffffff4
    //         004a8485     PUSH       EBX=>DAT_fffffff0
    //         004a8486     PUSH       EBX
    //         004a8487     PUSH       EBX
    //         004a8488     PUSH       EBX
    //         004a8489     PUSH       ESI
    //         004a848a     PUSH       this
    //         004a848b     MOV        this,EAX
    //         004a848d     CALL       RGE_Diamond_Map::setup                           long setup(RGE_Diamond_Map * this, TDrawArea 
    //         004a8492     TEST       EAX,EAX
    //                              scr_sed.cpp:348 (6)
    //         004a8494     JZ         LAB_004a871e
    //                              scr_sed.cpp:350 (21)
    //         004a849a     MOV        this,dword ptr [ESI + 0x4cc]
    //         004a84a0     PUSH       0xc4e1
    //         004a84a5     PUSH       s_map640.bmp                                     = "map640.bmp"
    //         004a84aa     CALL       RGE_Diamond_Map::set_bitmap                      int set_bitmap(RGE_Diamond_Map * this, char *
    //                              scr_sed.cpp:352 (12)
    //         004a84af     MOV        this,dword ptr [ESI + 0x4cc]
    //         004a84b5     MOV        EAX,dword ptr [ESI + 0x4c8]
    //                              scr_sed.cpp:354 (39)
    //         004a84bb     PUSH       -0x1
    //         004a84bd     PUSH       offset DAT_fffffff8
    //         004a84bf     MOV        dword ptr [ECX + this->_padding_],EAX
    //         004a84c5     MOV        this,dword ptr [ESI + 0x4c8]
    //         004a84cb     MOV        EAX,dword ptr [ESI + 0x4cc]
    //         004a84d1     MOV        dword ptr [ECX + this->_padding_],EAX
    //         004a84d7     MOV        this,dword ptr [ESI + 0x4c8]
    //         004a84dd     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_sed.cpp:359 (13)
    //         004a84e2     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004a84e8     PUSH       0xb
    //         004a84ea     CALL       RGE_Base_Game::get_font                          RGE_Font * get_font(RGE_Base_Game * this, int
    //                              scr_sed.cpp:360 (53)
    //         004a84ef     PUSH       0x380
    //         004a84f4     MOV        EDI,EAX
    //         004a84f6     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004a84fb     ADD        ESP,0x4
    //         004a84fe     MOV        dword ptr [ESP + 0x10],EAX
    //         004a8502     CMP        EAX,EBX
    //         004a8504     MOV        byte ptr [ESP + 0x228],0x3
    //         004a850c     JZ         LAB_004a8522
    //         004a850e     MOV        EDX,dword ptr [EDI + 0x8]
    //         004a8511     MOV        this,dword ptr [EDI + 0x4]
    //         004a8514     PUSH       EDX
    //         004a8515     MOV        EDX,dword ptr [EDI]
    //         004a8517     PUSH       this=>DAT_fffffff8
    //         004a8518     PUSH       EDX=>DAT_fffffff4
    //         004a8519     MOV        this,EAX
    //         004a851b     CALL       TMessagePanel::TMessagePanel                     undefined TMessagePanel(TMessagePanel * this,
    //         004a8520     JMP        LAB_004a8524
    //                               LAB_004a8522                                                 XREF[1]:     004a850c(j)  
    //         004a8522     XOR        EAX,EAX
    //                               LAB_004a8524                                                 XREF[1]:     004a8520(j)  
    //                              scr_sed.cpp:361 (33)
    //         004a8524     CMP        EAX,EBX
    //         004a8526     MOV        byte ptr [ESP + 0x228],BL
    //         004a852d     MOV        dword ptr [ESI + 0x4d0],EAX
    //         004a8533     JZ         LAB_004a871e
    //         004a8539     CMP        dword ptr [EAX + 0xd8],EBX
    //         004a853f     JNZ        LAB_004a871e
    //                              scr_sed.cpp:366 (25)
    //         004a8545     MOV        this,dword ptr [ESI + 0x4c8]
    //         004a854b     MOV        EDX,dword ptr [EAX]
    //         004a854d     PUSH       EBX
    //         004a854e     PUSH       EBX=>DAT_fffffff8
    //         004a854f     PUSH       EBX=>DAT_fffffff4
    //         004a8550     PUSH       EBX=>DAT_fffffff0
    //         004a8551     PUSH       EBX
    //         004a8552     PUSH       this
    //         004a8553     MOV        this,dword ptr [ESI + 0x20]
    //         004a8556     PUSH       this
    //         004a8557     MOV        this,EAX
    //         004a8559     CALL       dword ptr [EDX + 0x4]
    //         004a855c     TEST       EAX,EAX
    //                              scr_sed.cpp:369 (6)
    //         004a855e     JZ         LAB_004a871e
    //                              scr_sed.cpp:376 (40)
    //         004a8564     PUSH       0xf4
    //         004a8569     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004a856e     ADD        ESP,0x4
    //         004a8571     MOV        dword ptr [ESP + 0x10],EAX
    //         004a8575     CMP        EAX,EBX
    //         004a8577     MOV        byte ptr [ESP + 0x228],0x4
    //         004a857f     JZ         LAB_004a858a
    //         004a8581     MOV        this,EAX
    //         004a8583     CALL       TPanel::TPanel                                   undefined TPanel(TPanel * this)
    //         004a8588     JMP        LAB_004a858c
    //                               LAB_004a858a                                                 XREF[1]:     004a857f(j)  
    //         004a858a     XOR        EAX,EAX
    //                               LAB_004a858c                                                 XREF[1]:     004a8588(j)  
    //                              scr_sed.cpp:377 (33)
    //         004a858c     CMP        EAX,EBX
    //         004a858e     MOV        byte ptr [ESP + 0x228],BL
    //         004a8595     MOV        dword ptr [ESI + 0x4d4],EAX
    //         004a859b     JZ         LAB_004a871e
    //         004a85a1     CMP        dword ptr [EAX + 0xd8],EBX
    //         004a85a7     JNZ        LAB_004a871e
    //                              scr_sed.cpp:382 (19)
    //         004a85ad     MOV        this,dword ptr [ESI + 0x20]
    //         004a85b0     MOV        EDX,dword ptr [EAX]
    //         004a85b2     PUSH       EBX
    //         004a85b3     PUSH       EBX=>DAT_fffffff8
    //         004a85b4     PUSH       EBX=>DAT_fffffff4
    //         004a85b5     PUSH       EBX=>DAT_fffffff0
    //         004a85b6     PUSH       EBX
    //         004a85b7     PUSH       ESI
    //         004a85b8     PUSH       this
    //         004a85b9     MOV        this,EAX
    //         004a85bb     CALL       dword ptr [EDX + 0x4]
    //         004a85be     TEST       EAX,EAX
    //                              scr_sed.cpp:385 (6)
    //         004a85c0     JZ         LAB_004a871e
    //                              scr_sed.cpp:390 (7)
    //         004a85c6     MOV        this,ESI
    //         004a85c8     CALL       TRIBE_Screen_Sed::create_all_buttons_etc         void create_all_buttons_etc(TRIBE_Screen_Sed 
    //                              scr_sed.cpp:395 (17)
    //         004a85cd     CMP        EBP,EBX
    //         004a85cf     JZ         LAB_004a8661
    //         004a85d5     CMP        byte ptr [EBP],BL
    //         004a85d8     JZ         LAB_004a8661
    //                              scr_sed.cpp:412 (36)
    //         004a85de     PUSH       s_.scn                                           = ".scn"
    //         004a85e3     PUSH       EBP=>DAT_fffffff8
    //         004a85e4     CALL       strstr                                           undefined strstr()
    //         004a85e9     ADD        ESP,0x8
    //         004a85ec     TEST       EAX,EAX
    //         004a85ee     JNZ        LAB_004a8602
    //         004a85f0     PUSH       s_.SCN                                           = ".SCN"
    //         004a85f5     PUSH       EBP=>DAT_fffffff8
    //         004a85f6     CALL       strstr                                           undefined strstr()
    //         004a85fb     ADD        ESP,0x8
    //         004a85fe     TEST       EAX,EAX
    //         004a8600     JZ         LAB_004a8642
    //                               LAB_004a8602                                                 XREF[1]:     004a85ee(j)  
    //                              scr_sed.cpp:419 (3)
    //         004a8602     MOV        this,byte ptr [EBP]
    //                              scr_sed.cpp:422 (23)
    //         004a8605     LEA        EDX,[ESP + 0x18]
    //         004a8609     XOR        EDI,EDI
    //         004a860b     MOV        EAX,EBP
    //         004a860d     SUB        EDX,EBP
    //                               LAB_004a860f                                                 XREF[1]:     004a861a(j)  
    //         004a860f     MOV        byte ptr [EDX + EAX*0x1],this
    //         004a8612     MOV        this,byte ptr [EAX + 0x1]
    //         004a8615     INC        EDI
    //         004a8616     INC        EAX
    //         004a8617     CMP        this,0x2e
    //         004a861a     JNZ        LAB_004a860f
    //                              scr_sed.cpp:425 (20)
    //         004a861c     LEA        EDX,[ESP + 0x18]
    //         004a8620     MOV        byte ptr [ESP + EDI*0x1 + 0x18],BL
    //         004a8624     PUSH       EDX
    //         004a8625     PUSH       s_%s.scx                                         = "%s.scx"
    //         004a862a     PUSH       EBP=>DAT_fffffff4
    //         004a862b     CALL       sprintf                                          undefined sprintf()
    //                              scr_sed.cpp:427 (18)
    //         004a8630     MOV        EAX,dword ptr [ESI + 0x928]
    //         004a8636     ADD        ESP,0xc
    //         004a8639     MOV        this,dword ptr [EAX + 0x5c]
    //         004a863c     PUSH       EBP
    //         004a863d     CALL       RGE_Scenario::Set_scenario_name                  void Set_scenario_name(RGE_Scenario * this, c
    //                               LAB_004a8642                                                 XREF[1]:     004a8600(j)  
    //                              scr_sed.cpp:429 (2)
    //         004a8642     XOR        EDI,EDI
    //                               LAB_004a8644                                                 XREF[1]:     004a865b(j)  
    //                              scr_sed.cpp:430 (25)
    //         004a8644     MOV        this,dword ptr [ESI + 0x928]
    //         004a864a     PUSH       EDI
    //         004a864b     MOV        this,dword ptr [ECX + this->_padding_]
    //         004a864e     CALL       RGE_Scenario::Get_player_Active                  int Get_player_Active(RGE_Scenario * this, in
    //         004a8653     TEST       EAX,EAX
    //         004a8655     JZ         LAB_004a865d
    //         004a8657     INC        EDI
    //         004a8658     CMP        EDI,0x8
    //         004a865b     JL         LAB_004a8644
    //                               LAB_004a865d                                                 XREF[1]:     004a8655(j)  
    //                              scr_sed.cpp:433 (4)
    //         004a865d     DEC        EDI
    //         004a865e     PUSH       EDI
    //         004a865f     JMP        LAB_004a8678
    //                               LAB_004a8661                                                 XREF[2]:     004a85cf(j), 004a85d8(j)  
    //                              scr_sed.cpp:400 (10)
    //         004a8661     PUSH       0x1
    //         004a8663     PUSH       EBX=>DAT_fffffff8
    //         004a8664     MOV        this,ESI
    //         004a8666     CALL       TRIBE_Screen_Sed::set_player_active              void set_player_active(TRIBE_Screen_Sed * thi
    //                              scr_sed.cpp:401 (11)
    //         004a866b     PUSH       0x1
    //         004a866d     PUSH       offset DAT_fffffff8
    //         004a866f     MOV        this,ESI
    //         004a8671     CALL       TRIBE_Screen_Sed::set_player_active              void set_player_active(TRIBE_Screen_Sed * thi
    //                              scr_sed.cpp:403 (13)
    //         004a8676     PUSH       0x1
    //                               LAB_004a8678                                                 XREF[1]:     004a865f(j)  
    //         004a8678     MOV        this,dword ptr [ESI + 0x5b8]
    //         004a867e     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
    //                              scr_sed.cpp:404 (7)
    //         004a8683     MOV        this,ESI
    //         004a8685     CALL       TRIBE_Screen_Sed::SavePlayerActiveStatus         void SavePlayerActiveStatus(TRIBE_Screen_Sed 
    //                              scr_sed.cpp:440 (14)
    //         004a868a     MOV        EDX,dword ptr [ESI + 0x4d4]
    //         004a8690     MOV        this,ESI
    //         004a8692     PUSH       EDX
    //         004a8693     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              scr_sed.cpp:441 (7)
    //         004a8698     MOV        this,ESI
    //         004a869a     CALL       TRIBE_Screen_Sed::position_panels                void position_panels(TRIBE_Screen_Sed * this)
    //                              scr_sed.cpp:443 (7)
    //         004a869f     MOV        this,ESI
    //         004a86a1     CALL       TRIBE_Screen_Sed::set_panel_info                 void set_panel_info(TRIBE_Screen_Sed * this)
    //                              scr_sed.cpp:445 (10)
    //         004a86a6     PUSH       EBX
    //         004a86a7     PUSH       offset DAT_fffffff8
    //         004a86a9     MOV        this,ESI
    //         004a86ab     CALL       TRIBE_Screen_Sed::set_map_type                   void set_map_type(TRIBE_Screen_Sed * this, Ma
    //                              scr_sed.cpp:446 (10)
    //         004a86b0     PUSH       EBX
    //         004a86b1     PUSH       offset DAT_fffffff8
    //         004a86b3     MOV        this,ESI
    //         004a86b5     CALL       TRIBE_Screen_Sed::set_mp_victory_type            void set_mp_victory_type(TRIBE_Screen_Sed * t
    //                              scr_sed.cpp:447 (9)
    //         004a86ba     PUSH       0x1
    //         004a86bc     MOV        this,ESI
    //         004a86be     CALL       TRIBE_Screen_Sed::set_brush_size                 void set_brush_size(TRIBE_Screen_Sed * this, 
    //                              scr_sed.cpp:448 (10)
    //         004a86c3     PUSH       EBX
    //         004a86c4     PUSH       offset DAT_fffffff8
    //         004a86c6     MOV        this,ESI
    //         004a86c8     CALL       TRIBE_Screen_Sed::set_paint_type                 void set_paint_type(TRIBE_Screen_Sed * this, 
    //                              scr_sed.cpp:449 (11)
    //         004a86cd     PUSH       EBX
    //         004a86ce     PUSH       EBX=>DAT_fffffff8
    //         004a86cf     PUSH       offset DAT_fffffff4
    //         004a86d1     MOV        this,ESI
    //         004a86d3     CALL       TRIBE_Screen_Sed::set_player                     void set_player(TRIBE_Screen_Sed * this, shor
    //                              scr_sed.cpp:450 (9)
    //         004a86d8     PUSH       0x1
    //         004a86da     MOV        this,ESI
    //         004a86dc     CALL       TRIBE_Screen_Sed::set_unit_player                void set_unit_player(TRIBE_Screen_Sed * this,
    //                              scr_sed.cpp:451 (10)
    //         004a86e1     PUSH       EBX
    //         004a86e2     PUSH       offset DAT_fffffff8
    //         004a86e4     MOV        this,ESI
    //         004a86e6     CALL       TRIBE_Screen_Sed::set_message_type               void set_message_type(TRIBE_Screen_Sed * this
    //                              scr_sed.cpp:453 (9)
    //         004a86eb     PUSH       0x1
    //         004a86ed     MOV        this,ESI
    //         004a86ef     CALL       TRIBE_Screen_Sed::set_scenario_mode              void set_scenario_mode(TRIBE_Screen_Sed * thi
    //                              scr_sed.cpp:457 (9)
    //         004a86f4     PUSH       -0x1
    //         004a86f6     MOV        this,ESI
    //         004a86f8     CALL       TRIBE_Screen_Sed::set_unit                       void set_unit(TRIBE_Screen_Sed * this, short 
    //                              scr_sed.cpp:459 (16)
    //         004a86fd     MOV        EAX,dword ptr [ESI + 0x928]
    //         004a8703     PUSH       0x1
    //         004a8705     MOV        this,dword ptr [EAX + 0x28]
    //         004a8708     CALL       RGE_Map::set_map_visible                         void set_map_visible(RGE_Map * this, uchar pa
    //                              scr_sed.cpp:460 (17)
    //         004a870d     MOV        this,dword ptr [ESI + 0x928]
    //         004a8713     PUSH       EBX
    //         004a8714     MOV        this,dword ptr [ECX + this->_padding_]
    //         004a8717     CALL       RGE_Map::set_map_fog                             void set_map_fog(RGE_Map * this, uchar param_1)
    //         004a871c     JMP        LAB_004a8728
    //                               LAB_004a871e                                                 XREF[13]:    004a83a4(j), 004a83f3(j), 
    //                                                                                                         004a83ff(j), 004a8420(j), 
    //                                                                                                         004a845d(j), 004a8469(j), 
    //                                                                                                         004a8494(j), 004a8533(j), 
    //                                                                                                         004a853f(j), 004a855e(j), 
    //                                                                                                         004a859b(j), 004a85a7(j), 
    //                                                                                                         004a85c0(j)  
    //                              scr_sed.cpp:325 (10)
    //         004a871e     MOV        dword ptr [ESI + 0xd8],0x1
    //                               LAB_004a8728                                                 XREF[2]:     004a8313(j), 004a871c(j)  
    //                              scr_sed.cpp:464 (29)
    //         004a8728     MOV        this,dword ptr [ESP + 0x220]
    //         004a872f     MOV        EAX,ESI
    //         004a8731     POP        EDI
    //         004a8732     POP        ESI
    //         004a8733     POP        EBP
    //         004a8734     MOV        dword ptr FS:[0x0],this
    //         004a873b     POP        EBX
    //         004a873c     ADD        ESP,0x21c
    //         004a8742     RET        0x8
    //         004a8745     ??         90h
    //         004a8746     NOP
    //         004a8747     NOP
    //         004a8748     NOP
    //         004a8749     NOP
    //         004a874a     NOP
    //         004a874b     NOP
    //         004a874c     NOP
    //         004a874d     NOP
    //         004a874e     NOP
    //         004a874f     NOP
}

void TRIBE_Screen_Sed::set_panel_info() {
    /* TODO: Stub */
    //                              void __thiscall set_panel_info(TRIBE_Screen_Sed * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //                               ?set_panel_info@TRIBE_Screen_Sed@@IAEXXZ                     XREF[2]:     TRIBE_Screen_Sed:004a86a1(c), 
    //                               TRIBE_Screen_Sed::set_panel_info                                          action:004ac807(c)  
    //                              scr_sed.cpp:471 (3)
    //         004a8770     PUSH       ESI
    //         004a8771     MOV        ESI,this
    //                              scr_sed.cpp:475 (18)
    //         004a8773     MOV        EAX,dword ptr [ESI + 0x928]
    //         004a8779     MOV        this,dword ptr [ESI + 0x4c8]
    //         004a877f     PUSH       EAX
    //         004a8780     CALL       RGE_View::set_world                              void set_world(RGE_View * this, RGE_Game_Worl
    //                              scr_sed.cpp:476 (23)
    //         004a8785     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004a878b     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004a8790     MOV        this,dword ptr [ESI + 0x4c8]
    //         004a8796     PUSH       EAX
    //         004a8797     CALL       RGE_View::set_player                             void set_player(RGE_View * this, RGE_Player *
    //                              scr_sed.cpp:479 (18)
    //         004a879c     MOV        this,dword ptr [ESI + 0x928]
    //         004a87a2     PUSH       this
    //         004a87a3     MOV        this,dword ptr [ESI + 0x4cc]
    //         004a87a9     CALL       RGE_Diamond_Map::set_world                       void set_world(RGE_Diamond_Map * this, RGE_Ga
    //                              scr_sed.cpp:480 (23)
    //         004a87ae     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004a87b4     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004a87b9     MOV        this,dword ptr [ESI + 0x4cc]
    //         004a87bf     PUSH       EAX
    //         004a87c0     CALL       RGE_Diamond_Map::set_player                      void set_player(RGE_Diamond_Map * this, RGE_P
    //                              scr_sed.cpp:484 (2)
    //         004a87c5     POP        ESI
    //         004a87c6     RET
    //         004a87c7     ??         90h
    //         004a87c8     NOP
    //         004a87c9     NOP
    //         004a87ca     NOP
    //         004a87cb     NOP
    //         004a87cc     NOP
    //         004a87cd     NOP
    //         004a87ce     NOP
    //         004a87cf     NOP
    return;
}

void TRIBE_Screen_Sed::set_string(char* param_1, long param_2, int param_3) {
    /* TODO: Stub */
    //                              void __thiscall set_string(TRIBE_Screen_Sed * this, char * param_1, 
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     004a87d4(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     004a87d9(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     004a87d0(R)  
    //                               ?set_string@TRIBE_Screen_Sed@@IAEXPADJH@Z                    XREF[3]:     create_list:004a9437(c), 
    //                               TRIBE_Screen_Sed::set_string                                              set_unit_player:004ab44c(c), 
    //                                                                                                         command_new_map:004ad49a(c)  
    //                              scr_sed.cpp:490 (20)
    //         004a87d0     MOV        EAX,dword ptr [ESP + param_3]
    //         004a87d4     MOV        EDX,dword ptr [ESP + param_1]
    //         004a87d8     PUSH       EAX
    //         004a87d9     MOV        EAX,dword ptr [ESP + param_2]
    //         004a87dd     PUSH       EDX
    //         004a87de     PUSH       EAX
    //         004a87df     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
    //                              scr_sed.cpp:492 (3)
    //         004a87e4     RET        0xc
    //         004a87e7     ??         90h
    //         004a87e8     NOP
    //         004a87e9     NOP
    //         004a87ea     NOP
    //         004a87eb     NOP
    //         004a87ec     NOP
    //         004a87ed     NOP
    //         004a87ee     NOP
    //         004a87ef     NOP
    //                              * protected: int __thiscall TRIBE_Screen_Sed::create_button(class TPanel *,class TButtonPanel * *,lo... *
    //                              int __thiscall create_button(TRIBE_Screen_Sed * this, TPanel * param
    //              int               EAX:4          <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     004a8813(R)  
    //              TButtonPanel *    Stack[0x8]:4   param_2                   XREF[1]:     004a880c(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     004a87fa(R)  
    //              int               Stack[0x10]:4  param_4
    //              char[120]         Stack[-0x7c]   str1                      XREF[0,2]:   004a87f3(*), 004a881e(*)  
    //                               ?create_button@TRIBE_Screen_Sed@@IAEHPAVTPanel@@PAPAVTButto  XREF[16]:    create_all_buttons_etc:004af6f0(c)
    //                               TRIBE_Screen_Sed::create_button                                           create_all_buttons_etc:004af71d(c)
    //                                                                                                         create_all_buttons_etc:004af749(c)
    //                                                                                                         create_all_buttons_etc:004af775(c)
    //                                                                                                         create_all_buttons_etc:004af7a1(c)
    //                                                                                                         create_all_buttons_etc:004af7cd(c)
    //                                                                                                         create_all_buttons_etc:004af7f9(c)
    //                                                                                                         create_all_buttons_etc:004af825(c)
    //                                                                                                         create_all_buttons_etc:004af851(c)
    //                                                                                                         create_all_buttons_etc:004af87d(c)
    //                                                                                                         create_all_buttons_etc:004af8c9(c)
    //                                                                                                         create_all_buttons_etc:004af8fe(c)
    //                                                                                                         create_all_buttons_etc:004afc0a(c)
    //                                                                                                         create_all_buttons_etc:004b10c5(c)
    //                                                                                                         create_all_buttons_etc:004b10e9(c)
    //                                                                                                         create_all_buttons_etc:004b110d(c)
    //                              scr_sed.cpp:498 (3)
    //         004a87f0     SUB        ESP,0x78
    //                              scr_sed.cpp:501 (25)
    //         004a87f3     LEA        EAX=>str1[4],[ESP]
    //         004a87f7     PUSH       ESI
    //         004a87f8     MOV        ESI,this
    //         004a87fa     MOV        this,dword ptr [ESP + param_3]
    //                              language.dll match for 0x78: "10"
    //         004a8801     PUSH       0x78
    //         004a8803     PUSH       EAX
    //         004a8804     PUSH       this
    //         004a8805     MOV        this,ESI
    //         004a8807     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
    //                              scr_sed.cpp:511 (34)
    //         004a880c     MOV        EAX,dword ptr [ESP + param_2]
    //         004a8813     MOV        this,dword ptr [ESP + param_1]
    //         004a881a     PUSH       0x0
    //         004a881c     PUSH       0x0
    //         004a881e     LEA        EDX=>str1[4],[ESP + 0xc]
    //         004a8822     PUSH       0x0
    //         004a8824     PUSH       EDX
    //         004a8825     PUSH       EAX
    //         004a8826     PUSH       this
    //         004a8827     MOV        this,ESI
    //         004a8829     CALL       TRIBE_Screen_Sed::create_button                  int create_button(TRIBE_Screen_Sed * this, TP
    //                              scr_sed.cpp:512 (7)
    //         004a882e     POP        ESI
    //         004a882f     ADD        ESP,0x78
    //         004a8832     RET        0x10
    //         004a8835     ??         90h
    //         004a8836     NOP
    //         004a8837     NOP
    //         004a8838     NOP
    //         004a8839     NOP
    //         004a883a     NOP
    //         004a883b     NOP
    //         004a883c     NOP
    //         004a883d     NOP
    //         004a883e     NOP
    //         004a883f     NOP
    //                              * protected: int __thiscall TRIBE_Screen_Sed::create_button(class TPanel *,class TButtonPanel * *,ch... *
    //                              int __thiscall create_button(TRIBE_Screen_Sed * this, TPanel * param
    //              int               EAX:4          <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     004a884c(R)  
    //              TButtonPanel *    Stack[0x8]:4   param_2                   XREF[1]:     004a8846(R)  
    //              char *            Stack[0xc]:4   param_3                   XREF[1]:     004a8858(R)  
    //              char *            Stack[0x10]:4  param_4                   XREF[1]:     004a8840(R)  
    //              char *            Stack[0x14]:4  param_5                   XREF[1]:     004a8876(R)  
    //              char *            Stack[0x18]:4  param_6                   XREF[1]:     004a8888(R)  
    //                               ?create_button@TRIBE_Screen_Sed@@IAEHPAVTPanel@@PAPAVTButto  XREF[2]:     create_button:004a8829(c), 
    //                               TRIBE_Screen_Sed::create_button                                           create_all_buttons_etc:004b0f01(c)
    //                              scr_sed.cpp:518 (49)
    //         004a8840     MOV        EAX,dword ptr [ESP + param_4]
    //         004a8844     PUSH       ESI
    //         004a8845     PUSH       EDI
    //         004a8846     MOV        EDI,dword ptr [ESP + param_2]
    //         004a884a     PUSH       0x0
    //         004a884c     MOV        EDX,dword ptr [ESP + param_1]
    //         004a8850     PUSH       0x1
    //         004a8852     PUSH       0xa
    //         004a8854     PUSH       0x0
    //         004a8856     MOV        ESI,this
    //         004a8858     MOV        this,dword ptr [ESP + param_3]
    //         004a885c     PUSH       0x0
    //         004a885e     PUSH       0x0
    //         004a8860     PUSH       0x0
    //         004a8862     PUSH       EAX
    //         004a8863     PUSH       this
    //         004a8864     PUSH       EDI
    //         004a8865     PUSH       EDX
    //         004a8866     MOV        this,ESI
    //         004a8868     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         004a886d     TEST       EAX,EAX
    //         004a886f     JNZ        LAB_004a8876
    //                              scr_sed.cpp:532 (5)
    //         004a8871     POP        EDI
    //         004a8872     POP        ESI
    //         004a8873     RET        0x18
    //                               LAB_004a8876                                                 XREF[1]:     004a886f(j)  
    //                              scr_sed.cpp:522 (18)
    //         004a8876     MOV        EAX,dword ptr [ESP + param_5]
    //         004a887a     TEST       EAX,EAX
    //         004a887c     JZ         LAB_004a8888
    //         004a887e     MOV        this,dword ptr [EDI]
    //         004a8880     PUSH       EAX
    //         004a8881     PUSH       0x2
    //         004a8883     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                               LAB_004a8888                                                 XREF[1]:     004a887c(j)  
    //                              scr_sed.cpp:523 (18)
    //         004a8888     MOV        EAX,dword ptr [ESP + param_6]
    //         004a888c     TEST       EAX,EAX
    //         004a888e     JZ         LAB_004a889a
    //         004a8890     MOV        this,dword ptr [EDI]
    //         004a8892     PUSH       EAX
    //         004a8893     PUSH       0x3
    //         004a8895     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                               LAB_004a889a                                                 XREF[1]:     004a888e(j)  
    //                              scr_sed.cpp:525 (11)
    //         004a889a     MOV        this,dword ptr [EDI]
    //         004a889c     PUSH       0x0
    //         004a889e     PUSH       0x1
    //         004a88a0     CALL       TPanel::set_z_order                              void set_z_order(TPanel * this, uchar param_1
    //                              scr_sed.cpp:526 (9)
    //         004a88a5     MOV        this,dword ptr [EDI]
    //         004a88a7     PUSH       0x0
    //         004a88a9     MOV        EAX,dword ptr [this->_padding_]
    //         004a88ab     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:528 (10)
    //         004a88ae     MOV        EAX,dword ptr [ESI + 0x31c]
    //         004a88b4     TEST       EAX,EAX
    //         004a88b6     JZ         LAB_004a88f7
    //                              scr_sed.cpp:529 (63)
    //         004a88b8     XOR        this,this
    //         004a88ba     XOR        EDX,EDX
    //         004a88bc     MOV        this,byte ptr [ESI + 0x325]
    //         004a88c2     MOV        DL,byte ptr [ESI + 0x324]
    //         004a88c8     XOR        EAX,EAX
    //         004a88ca     PUSH       this
    //         004a88cb     MOV        AL,byte ptr [ESI + 0x323]
    //         004a88d1     PUSH       EDX=>DAT_fffffff8
    //         004a88d2     XOR        this,this
    //         004a88d4     PUSH       EAX=>DAT_fffffff4
    //         004a88d5     MOV        this,byte ptr [ESI + 0x322]
    //         004a88db     XOR        EDX,EDX
    //         004a88dd     MOV        DL,byte ptr [ESI + 0x321]
    //         004a88e3     XOR        EAX,EAX
    //         004a88e5     MOV        AL,byte ptr [ESI + 0x320]
    //         004a88eb     PUSH       this=>DAT_fffffff0
    //         004a88ec     MOV        this,dword ptr [EDI]
    //         004a88ee     PUSH       EDX
    //         004a88ef     PUSH       EAX
    //         004a88f0     PUSH       0x3
    //         004a88f2     CALL       TButtonPanel::set_bevel_info                     void set_bevel_info(TButtonPanel * this, int 
    //                               LAB_004a88f7                                                 XREF[1]:     004a88b6(j)  
    //                              scr_sed.cpp:532 (10)
    //         004a88f7     POP        EDI
    //         004a88f8     MOV        EAX,0x1
    //         004a88fd     POP        ESI
    //         004a88fe     RET        0x18
    //         004a8901     ??         90h
    //         004a8902     NOP
    //         004a8903     NOP
    //         004a8904     NOP
    //         004a8905     NOP
    //         004a8906     NOP
    //         004a8907     NOP
    //         004a8908     NOP
    //         004a8909     NOP
    //         004a890a     NOP
    //         004a890b     NOP
    //         004a890c     NOP
    //         004a890d     NOP
    //         004a890e     NOP
    //         004a890f     NOP
    return;
}

int TRIBE_Screen_Sed::create_text(TPanel* param_1, TTextPanel** param_2, long param_3) {
    /* TODO: Stub */
    //                              int __thiscall create_text(TRIBE_Screen_Sed * this, TPanel * param_1
    //              int               EAX:4          <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     004a891b(R)  
    //              TTextPanel * *    Stack[0x8]:4   param_2                   XREF[1]:     004a8915(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     004a8910(R)  
    //                               ?create_text@TRIBE_Screen_Sed@@IAEHPAVTPanel@@PAPAVTTextPan  XREF[90]:    create_all_buttons_etc:004af92b(c)
    //                               TRIBE_Screen_Sed::create_text                                             create_all_buttons_etc:004af9cf(c)
    //                                                                                                         create_all_buttons_etc:004af9f1(c)
    //                                                                                                         create_all_buttons_etc:004afa13(c)
    //                                                                                                         create_all_buttons_etc:004afa35(c)
    //                                                                                                         create_all_buttons_etc:004afad0(c)
    //                                                                                                         create_all_buttons_etc:004afb1d(c)
    //                                                                                                         create_all_buttons_etc:004afb6a(c)
    //                                                                                                         create_all_buttons_etc:004afbc4(c)
    //                                                                                                         create_all_buttons_etc:004afc51(c)
    //                                                                                                         create_all_buttons_etc:004afc73(c)
    //                                                                                                         create_all_buttons_etc:004afd6d(c)
    //                                                                                                         create_all_buttons_etc:004afd8f(c)
    //                                                                                                         create_all_buttons_etc:004afdb1(c)
    //                                                                                                         create_all_buttons_etc:004afdd3(c)
    //                                                                                                         create_all_buttons_etc:004afdf5(c)
    //                                                                                                         create_all_buttons_etc:004afe17(c)
    //                                                                                                         create_all_buttons_etc:004afeba(c)
    //                                                                                                         create_all_buttons_etc:004afedc(c)
    //                                                                                                         create_all_buttons_etc:004afefe(c)
    //                                                                                                         [more]
    //                              scr_sed.cpp:538 (41)
    //         004a8910     MOV        EAX,dword ptr [ESP + param_3]
    //         004a8914     PUSH       ESI
    //         004a8915     MOV        ESI,dword ptr [ESP + param_2]
    //         004a8919     PUSH       0x0
    //         004a891b     MOV        EDX,dword ptr [ESP + param_1]
    //         004a891f     PUSH       0x0
    //         004a8921     PUSH       0x0
    //         004a8923     PUSH       0xa
    //         004a8925     PUSH       0x0
    //         004a8927     PUSH       0x0
    //         004a8929     PUSH       0x0
    //         004a892b     PUSH       0x0
    //         004a892d     PUSH       EAX
    //         004a892e     PUSH       ESI
    //         004a892f     PUSH       EDX
    //         004a8930     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004a8935     TEST       EAX,EAX
    //         004a8937     JNZ        LAB_004a893d
    //                              scr_sed.cpp:546 (4)
    //         004a8939     POP        ESI
    //         004a893a     RET        0xc
    //                               LAB_004a893d                                                 XREF[1]:     004a8937(j)  
    //                              scr_sed.cpp:542 (11)
    //         004a893d     MOV        this,dword ptr [ESI]
    //         004a893f     PUSH       0x0
    //         004a8941     PUSH       0x1
    //         004a8943     CALL       TPanel::set_z_order                              void set_z_order(TPanel * this, uchar param_1
    //                              scr_sed.cpp:543 (9)
    //         004a8948     MOV        this,dword ptr [ESI]
    //         004a894a     PUSH       0x0
    //         004a894c     MOV        EAX,dword ptr [this->_padding_]
    //         004a894e     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:545 (5)
    //         004a8951     MOV        EAX,0x1
    //                              scr_sed.cpp:546 (4)
    //         004a8956     POP        ESI
    //         004a8957     RET        0xc
    //         004a895a     ??         90h
    //         004a895b     NOP
    //         004a895c     NOP
    //         004a895d     NOP
    //         004a895e     NOP
    //         004a895f     NOP
    return 0;
}

int TRIBE_Screen_Sed::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3) {
    /* TODO: Stub */
    //                              int __thiscall create_text(TRIBE_Screen_Sed * this, TPanel * param_1
    //              int               EAX:4          <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     004a896b(R)  
    //              TTextPanel * *    Stack[0x8]:4   param_2                   XREF[1]:     004a8965(R)  
    //              char *            Stack[0xc]:4   param_3                   XREF[1]:     004a8960(R)  
    //                               ?create_text@TRIBE_Screen_Sed@@IAEHPAVTPanel@@PAPAVTTextPan  XREF[2]:     create_all_buttons_etc:004afbe6(c)
    //                               TRIBE_Screen_Sed::create_text                                             create_all_buttons_etc:004b186a(c)
    //                              scr_sed.cpp:552 (41)
    //         004a8960     MOV        EAX,dword ptr [ESP + param_3]
    //         004a8964     PUSH       ESI
    //         004a8965     MOV        ESI,dword ptr [ESP + param_2]
    //         004a8969     PUSH       0x0
    //         004a896b     MOV        EDX,dword ptr [ESP + param_1]
    //         004a896f     PUSH       0x0
    //         004a8971     PUSH       0x0
    //         004a8973     PUSH       0xa
    //         004a8975     PUSH       0x0
    //         004a8977     PUSH       0x0
    //         004a8979     PUSH       0x0
    //         004a897b     PUSH       0x0
    //         004a897d     PUSH       EAX
    //         004a897e     PUSH       ESI
    //         004a897f     PUSH       EDX
    //         004a8980     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004a8985     TEST       EAX,EAX
    //         004a8987     JNZ        LAB_004a898d
    //                              scr_sed.cpp:560 (4)
    //         004a8989     POP        ESI
    //         004a898a     RET        0xc
    //                               LAB_004a898d                                                 XREF[1]:     004a8987(j)  
    //                              scr_sed.cpp:556 (11)
    //         004a898d     MOV        this,dword ptr [ESI]
    //         004a898f     PUSH       0x0
    //         004a8991     PUSH       0x1
    //         004a8993     CALL       TPanel::set_z_order                              void set_z_order(TPanel * this, uchar param_1
    //                              scr_sed.cpp:557 (9)
    //         004a8998     MOV        this,dword ptr [ESI]
    //         004a899a     PUSH       0x0
    //         004a899c     MOV        EAX,dword ptr [this->_padding_]
    //         004a899e     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:559 (5)
    //         004a89a1     MOV        EAX,0x1
    //                              scr_sed.cpp:560 (4)
    //         004a89a6     POP        ESI
    //         004a89a7     RET        0xc
    //         004a89aa     ??         90h
    //         004a89ab     NOP
    //         004a89ac     NOP
    //         004a89ad     NOP
    //         004a89ae     NOP
    //         004a89af     NOP
    //                              * protected: int __thiscall TRIBE_Screen_Sed::create_input(class TPanel *,class TInputPanel * *,char... *
    //                              int __thiscall create_input(TRIBE_Screen_Sed * this, TPanel * param_
    //              int               EAX:4          <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     004a89cd(R)  
    //              TInputPanel * *   Stack[0x8]:4   param_2                   XREF[1]:     004a89b9(R)  
    //              char *            Stack[0xc]:4   param_3                   XREF[1]:     004a89c8(R)  
    //              short             Stack[0x10]:2  param_4                   XREF[1]:     004a89b4(R)  
    //              FormatType        Stack[0x14]:4  param_5                   XREF[1]:     004a89b0(R)  
    //                               ?create_input@TRIBE_Screen_Sed@@IAEHPAVTPanel@@PAPAVTInputP
    //                               TRIBE_Screen_Sed::create_input
    //                              scr_sed.cpp:566 (45)
    //         004a89b0     MOV        EAX,dword ptr [ESP + param_5]
    //         004a89b4     MOV        EDX,dword ptr [ESP + param_4]
    //         004a89b8     PUSH       ESI
    //         004a89b9     MOV        ESI,dword ptr [ESP + param_2]
    //         004a89bd     PUSH       0xa
    //         004a89bf     PUSH       0x0
    //         004a89c1     PUSH       0x0
    //         004a89c3     PUSH       0x0
    //         004a89c5     PUSH       0x0
    //         004a89c7     PUSH       EAX
    //         004a89c8     MOV        EAX,dword ptr [ESP + param_3]
    //         004a89cc     PUSH       EDX
    //         004a89cd     MOV        EDX,dword ptr [ESP + param_1]
    //         004a89d1     PUSH       EAX
    //         004a89d2     PUSH       ESI
    //         004a89d3     PUSH       EDX
    //         004a89d4     CALL       TEasy_Panel::create_input                        int create_input(TEasy_Panel * this, TPanel *
    //         004a89d9     TEST       EAX,EAX
    //         004a89db     JNZ        LAB_004a89e1
    //                              scr_sed.cpp:574 (4)
    //         004a89dd     POP        ESI
    //         004a89de     RET        0x14
    //                               LAB_004a89e1                                                 XREF[1]:     004a89db(j)  
    //                              scr_sed.cpp:570 (11)
    //         004a89e1     MOV        this,dword ptr [ESI]
    //         004a89e3     PUSH       0x0
    //         004a89e5     PUSH       0x1
    //         004a89e7     CALL       TPanel::set_z_order                              void set_z_order(TPanel * this, uchar param_1
    //                              scr_sed.cpp:571 (9)
    //         004a89ec     MOV        this,dword ptr [ESI]
    //         004a89ee     PUSH       0x0
    //         004a89f0     MOV        EAX,dword ptr [this->_padding_]
    //         004a89f2     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:573 (5)
    //         004a89f5     MOV        EAX,0x1
    //                              scr_sed.cpp:574 (4)
    //         004a89fa     POP        ESI
    //         004a89fb     RET        0x14
    //         004a89fe     ??         90h
    //         004a89ff     NOP
    //                              * protected: int __thiscall TRIBE_Screen_Sed::create_edit(class TPanel *,class TEditPanel * *,char *... *
    //                              int __thiscall create_edit(TRIBE_Screen_Sed * this, TPanel * param_1
    //              int               EAX:4          <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     004a8a27(R)  
    //              TEditPanel * *    Stack[0x8]:4   param_2                   XREF[1]:     004a8a13(R)  
    //              char *            Stack[0xc]:4   param_3                   XREF[1]:     004a8a22(R)  
    //              short             Stack[0x10]:2  param_4                   XREF[1]:     004a8a0f(R)  
    //              FormatType        Stack[0x14]:4  param_5                   XREF[1]:     004a8a0a(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[1]:     004a8a04(R)  
    //              int               Stack[0x1c]:4  param_7                   XREF[1]:     004a8a00(R)  
    //                               ?create_edit@TRIBE_Screen_Sed@@IAEHPAVTPanel@@PAPAVTEditPan  XREF[10]:    create_all_buttons_etc:004afb94(c)
    //                               TRIBE_Screen_Sed::create_edit                                             create_all_buttons_etc:004b045d(c)
    //                                                                                                         create_all_buttons_etc:004b04d8(c)
    //                                                                                                         create_all_buttons_etc:004b09ad(c)
    //                                                                                                         create_all_buttons_etc:004b09e5(c)
    //                                                                                                         create_all_buttons_etc:004b0a1d(c)
    //                                                                                                         create_all_buttons_etc:004b0a55(c)
    //                                                                                                         create_all_buttons_etc:004b0a8d(c)
    //                                                                                                         create_all_buttons_etc:004b11a6(c)
    //                                                                                                         create_all_buttons_etc:004b131f(c)
    //                              scr_sed.cpp:580 (55)
    //         004a8a00     MOV        EAX,dword ptr [ESP + param_7]
    //         004a8a04     MOV        EDX,dword ptr [ESP + param_6]
    //         004a8a08     PUSH       ESI
    //         004a8a09     PUSH       EAX
    //         004a8a0a     MOV        EAX,dword ptr [ESP + param_5]
    //         004a8a0e     PUSH       EDX
    //         004a8a0f     MOV        EDX,dword ptr [ESP + param_4]
    //         004a8a13     MOV        ESI,dword ptr [ESP + param_2]
    //         004a8a17     PUSH       0xa
    //         004a8a19     PUSH       0x0
    //         004a8a1b     PUSH       0x0
    //         004a8a1d     PUSH       0x0
    //         004a8a1f     PUSH       0x0
    //         004a8a21     PUSH       EAX
    //         004a8a22     MOV        EAX,dword ptr [ESP + param_3]
    //         004a8a26     PUSH       EDX
    //         004a8a27     MOV        EDX,dword ptr [ESP + param_1]
    //         004a8a2b     PUSH       EAX
    //         004a8a2c     PUSH       ESI
    //         004a8a2d     PUSH       EDX
    //         004a8a2e     CALL       TEasy_Panel::create_edit                         int create_edit(TEasy_Panel * this, TPanel * 
    //         004a8a33     TEST       EAX,EAX
    //         004a8a35     JNZ        LAB_004a8a3b
    //                              scr_sed.cpp:588 (4)
    //         004a8a37     POP        ESI
    //         004a8a38     RET        0x1c
    //                               LAB_004a8a3b                                                 XREF[1]:     004a8a35(j)  
    //                              scr_sed.cpp:584 (11)
    //         004a8a3b     MOV        this,dword ptr [ESI]
    //         004a8a3d     PUSH       0x0
    //         004a8a3f     PUSH       0x1
    //         004a8a41     CALL       TPanel::set_z_order                              void set_z_order(TPanel * this, uchar param_1
    //                              scr_sed.cpp:585 (9)
    //         004a8a46     MOV        this,dword ptr [ESI]
    //         004a8a48     PUSH       0x0
    //         004a8a4a     MOV        EAX,dword ptr [this->_padding_]
    //         004a8a4c     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:587 (5)
    //         004a8a4f     MOV        EAX,0x1
    //                              scr_sed.cpp:588 (4)
    //         004a8a54     POP        ESI
    //         004a8a55     RET        0x1c
    //         004a8a58     ??         90h
    //         004a8a59     NOP
    //         004a8a5a     NOP
    //         004a8a5b     NOP
    //         004a8a5c     NOP
    //         004a8a5d     NOP
    //         004a8a5e     NOP
    //         004a8a5f     NOP
    return 0;
}

int TRIBE_Screen_Sed::create_drop_down(TPanel* param_1, TDropDownPanel** param_2) {
    /* TODO: Stub */
    //                              int __thiscall create_drop_down(TRIBE_Screen_Sed * this, TPanel * pa
    //              int               EAX:4          <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     004a8bb4(R)  
    //              TDropDownPanel    Stack[0x8]:4   param_2                   XREF[1]:     004a8a6b(R)  
    //              char[256]         Stack[-0x104   str
    //              RGE_Player *      Stack[-0x108   player
    //              int               Stack[-0x10c   end_i
    //                               ?create_drop_down@TRIBE_Screen_Sed@@IAEHPAVTPanel@@PAPAVTDr  XREF[23]:    create_all_buttons_etc:004afa52(c)
    //                               TRIBE_Screen_Sed::create_drop_down                                        create_all_buttons_etc:004afaed(c)
    //                                                                                                         create_all_buttons_etc:004afb3a(c)
    //                                                                                                         create_all_buttons_etc:004b021e(c)
    //                                                                                                         create_all_buttons_etc:004b031d(c)
    //                                                                                                         create_all_buttons_etc:004b0350(c)
    //                                                                                                         create_all_buttons_etc:004b037a(c)
    //                                                                                                         create_all_buttons_etc:004b054b(c)
    //                                                                                                         create_all_buttons_etc:004b0592(c)
    //                                                                                                         create_all_buttons_etc:004b05bd(c)
    //                                                                                                         create_all_buttons_etc:004b05e8(c)
    //                                                                                                         create_all_buttons_etc:004b0cab(c)
    //                                                                                                         create_all_buttons_etc:004b0ded(c)
    //                                                                                                         create_all_buttons_etc:004b0f3c(c)
    //                                                                                                         create_all_buttons_etc:004b0f59(c)
    //                                                                                                         create_all_buttons_etc:004b0f76(c)
    //                                                                                                         create_all_buttons_etc:004b0f93(c)
    //                                                                                                         create_all_buttons_etc:004b0fb0(c)
    //                                                                                                         create_all_buttons_etc:004b0fcd(c)
    //                                                                                                         create_all_buttons_etc:004b0fea(c)
    //                                                                                                         [more]
    //                              scr_sed.cpp:594 (11)
    //         004a8a60     SUB        ESP,0x108
    //         004a8a66     PUSH       EBX
    //         004a8a67     MOV        EBX,this
    //         004a8a69     PUSH       EBP
    //         004a8a6a     PUSH       ESI
    //                              scr_sed.cpp:604 (120)
    //         004a8a6b     MOV        ESI,dword ptr [ESP + param_2]
    //         004a8a72     LEA        EAX,[EBX + 0x738]
    //         004a8a78     CMP        ESI,EAX
    //         004a8a7a     PUSH       EDI
    //         004a8a7b     JZ         LAB_004a8baf
    //         004a8a81     LEA        EAX,[EBX + 0x744]
    //         004a8a87     CMP        ESI,EAX
    //         004a8a89     JZ         LAB_004a8baf
    //         004a8a8f     LEA        this,[EBX + 0x748]
    //         004a8a95     CMP        ESI,this
    //         004a8a97     JZ         LAB_004a8baf
    //         004a8a9d     LEA        EDX,[EBX + 0x74c]
    //         004a8aa3     CMP        ESI,EDX
    //         004a8aa5     JZ         LAB_004a8baf
    //         004a8aab     LEA        EAX,[EBX + 0x600]
    //         004a8ab1     CMP        ESI,EAX
    //         004a8ab3     JZ         LAB_004a8baf
    //         004a8ab9     LEA        this,[EBX + 0x604]
    //         004a8abf     CMP        ESI,this
    //         004a8ac1     JZ         LAB_004a8baf
    //         004a8ac7     LEA        EDX,[EBX + 0x608]
    //         004a8acd     CMP        ESI,EDX
    //         004a8acf     JZ         LAB_004a8baf
    //         004a8ad5     LEA        EAX,[EBX + 0x700]
    //         004a8adb     CMP        ESI,EAX
    //         004a8add     JZ         LAB_004a8baf
    //                              scr_sed.cpp:609 (14)
    //         004a8ae3     LEA        this,[EBX + 0x734]
    //         004a8ae9     CMP        ESI,this
    //         004a8aeb     JZ         LAB_004a8ba8
    //                              scr_sed.cpp:615 (82)
    //         004a8af1     LEA        EDX,[EBX + 0x7b4]
    //         004a8af7     CMP        ESI,EDX
    //         004a8af9     JZ         LAB_004a8ba1
    //         004a8aff     LEA        EAX,[EBX + 0x7b8]
    //         004a8b05     CMP        ESI,EAX
    //         004a8b07     JZ         LAB_004a8ba1
    //         004a8b0d     LEA        this,[EBX + 0x7bc]
    //         004a8b13     CMP        ESI,this
    //         004a8b15     JZ         LAB_004a8ba1
    //         004a8b1b     LEA        EDX,[EBX + 0x7c0]
    //         004a8b21     CMP        ESI,EDX
    //         004a8b23     JZ         LAB_004a8ba1
    //         004a8b25     LEA        EAX,[EBX + 0x528]
    //         004a8b2b     CMP        ESI,EAX
    //         004a8b2d     JZ         LAB_004a8ba1
    //         004a8b2f     LEA        this,[EBX + 0x530]
    //         004a8b35     CMP        ESI,this
    //         004a8b37     JZ         LAB_004a8ba1
    //         004a8b39     LEA        EDX,[EBX + 0x538]
    //         004a8b3f     CMP        ESI,EDX
    //         004a8b41     JZ         LAB_004a8ba1
    //                              scr_sed.cpp:621 (80)
    //         004a8b43     LEA        EAX,[EBX + 0x5bc]
    //         004a8b49     CMP        ESI,EAX
    //         004a8b4b     JZ         LAB_004a8b9a
    //         004a8b4d     LEA        this,[EBX + 0x5b4]
    //         004a8b53     CMP        ESI,this
    //         004a8b55     JZ         LAB_004a8b9a
    //         004a8b57     LEA        EDX,[EBX + 0x5b8]
    //         004a8b5d     CMP        ESI,EDX
    //         004a8b5f     JZ         LAB_004a8b9a
    //         004a8b61     LEA        EAX,[EBX + 0x618]
    //         004a8b67     CMP        ESI,EAX
    //         004a8b69     JZ         LAB_004a8b9a
    //         004a8b6b     LEA        this,[EBX + 0x73c]
    //         004a8b71     CMP        ESI,this
    //         004a8b73     JZ         LAB_004a8b9a
    //         004a8b75     LEA        EDX,[EBX + 0x7cc]
    //         004a8b7b     CMP        ESI,EDX
    //         004a8b7d     JZ         LAB_004a8b9a
    //         004a8b7f     LEA        EAX,[EBX + 0x894]
    //         004a8b85     CMP        ESI,EAX
    //         004a8b87     JZ         LAB_004a8b9a
    //         004a8b89     LEA        this,[EBX + 0x740]
    //         004a8b8f     CMP        ESI,this
    //         004a8b91     JZ         LAB_004a8b9a
    //                              scr_sed.cpp:624 (7)
    //         004a8b93     MOV        EAX,0x82
    //         004a8b98     JMP        LAB_004a8bb4
    //                               LAB_004a8b9a                                                 XREF[8]:     004a8b4b(j), 004a8b55(j), 
    //                                                                                                         004a8b5f(j), 004a8b69(j), 
    //                                                                                                         004a8b73(j), 004a8b7d(j), 
    //                                                                                                         004a8b87(j), 004a8b91(j)  
    //                              scr_sed.cpp:622 (5)
    //         004a8b9a     MOV        EAX,0x96
    //                              scr_sed.cpp:623 (2)
    //         004a8b9f     JMP        LAB_004a8bb4
    //                               LAB_004a8ba1                                                 XREF[7]:     004a8af9(j), 004a8b07(j), 
    //                                                                                                         004a8b15(j), 004a8b23(j), 
    //                                                                                                         004a8b2d(j), 004a8b37(j), 
    //                                                                                                         004a8b41(j)  
    //                              scr_sed.cpp:616 (5)
    //         004a8ba1     MOV        EAX,0xaa
    //                              scr_sed.cpp:617 (2)
    //         004a8ba6     JMP        LAB_004a8bb4
    //                               LAB_004a8ba8                                                 XREF[1]:     004a8aeb(j)  
    //                              scr_sed.cpp:610 (5)
    //         004a8ba8     MOV        EAX,0xb4
    //                              scr_sed.cpp:611 (2)
    //         004a8bad     JMP        LAB_004a8bb4
    //                               LAB_004a8baf                                                 XREF[8]:     004a8a7b(j), 004a8a89(j), 
    //                                                                                                         004a8a97(j), 004a8aa5(j), 
    //                                                                                                         004a8ab3(j), 004a8ac1(j), 
    //                                                                                                         004a8acf(j), 004a8add(j)  
    //                              scr_sed.cpp:605 (5)
    //         004a8baf     MOV        EAX,0xdc
    //                               LAB_004a8bb4                                                 XREF[4]:     004a8b98(j), 004a8b9f(j), 
    //                                                                                                         004a8ba6(j), 004a8bad(j)  
    //                              scr_sed.cpp:626 (32)
    //         004a8bb4     MOV        EDX,dword ptr [ESP + param_1]
    //         004a8bbb     PUSH       0xa
    //         004a8bbd     PUSH       0x16
    //         004a8bbf     PUSH       EAX
    //         004a8bc0     PUSH       0x0
    //         004a8bc2     PUSH       0x0
    //         004a8bc4     PUSH       0x64
    //         004a8bc6     PUSH       EAX
    //         004a8bc7     PUSH       ESI
    //         004a8bc8     PUSH       EDX
    //         004a8bc9     MOV        this,EBX
    //         004a8bcb     CALL       TEasy_Panel::create_drop_down                    int create_drop_down(TEasy_Panel * this, TPan
    //         004a8bd0     TEST       EAX,EAX
    //         004a8bd2     JNZ        LAB_004a8be1
    //                              scr_sed.cpp:831 (13)
    //         004a8bd4     POP        EDI
    //         004a8bd5     POP        ESI
    //         004a8bd6     POP        EBP
    //         004a8bd7     POP        EBX
    //         004a8bd8     ADD        ESP,0x108
    //         004a8bde     RET        0x8
    //                               LAB_004a8be1                                                 XREF[1]:     004a8bd2(j)  
    //                              scr_sed.cpp:629 (11)
    //         004a8be1     MOV        this,dword ptr [ESI]
    //         004a8be3     PUSH       0x0
    //         004a8be5     PUSH       0x1
    //         004a8be7     CALL       TPanel::set_z_order                              void set_z_order(TPanel * this, uchar param_1
    //                              scr_sed.cpp:630 (9)
    //         004a8bec     MOV        this,dword ptr [ESI]
    //         004a8bee     PUSH       0x0
    //         004a8bf0     MOV        EAX,dword ptr [this->_padding_]
    //         004a8bf2     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:631 (7)
    //         004a8bf5     MOV        this,dword ptr [ESI]
    //         004a8bf7     CALL       TDropDownPanel::empty_list                       void empty_list(TDropDownPanel * this)
    //                              scr_sed.cpp:634 (10)
    //         004a8bfc     LEA        EDI,[EBX + 0x530]
    //         004a8c02     CMP        ESI,EDI
    //         004a8c04     JNZ        LAB_004a8c63
    //                              scr_sed.cpp:636 (14)
    //         004a8c06     MOV        this,dword ptr [EDI]
    //         004a8c08     PUSH       0x0
    //                              language.dll match for 0x2973: "Tiny"
    //         004a8c0a     PUSH       offset DAT_fffffff8
    //         004a8c0f     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:637 (14)
    //         004a8c14     MOV        this,dword ptr [EDI]
    //         004a8c16     PUSH       0x0
    //                              language.dll match for 0x2974: "Small"
    //         004a8c18     PUSH       offset DAT_fffffff8
    //         004a8c1d     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:638 (14)
    //         004a8c22     MOV        this,dword ptr [EDI]
    //         004a8c24     PUSH       0x0
    //                              language.dll match for 0x2975: "Medium"
    //         004a8c26     PUSH       offset DAT_fffffff8
    //         004a8c2b     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:639 (14)
    //         004a8c30     MOV        this,dword ptr [EDI]
    //         004a8c32     PUSH       0x0
    //                              language.dll match for 0x2976: "Large"
    //         004a8c34     PUSH       offset DAT_fffffff8
    //         004a8c39     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:640 (14)
    //         004a8c3e     MOV        this,dword ptr [EDI]
    //         004a8c40     PUSH       0x0
    //                              language.dll match for 0x2977: "Huge"
    //         004a8c42     PUSH       offset DAT_fffffff8
    //         004a8c47     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:641 (14)
    //         004a8c4c     MOV        this,dword ptr [EDI]
    //         004a8c4e     PUSH       0x0
    //                              language.dll match for 0x2978: "Gigantic"
    //         004a8c50     PUSH       offset DAT_fffffff8
    //         004a8c55     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:642 (4)
    //         004a8c5a     MOV        this,dword ptr [EDI]
    //         004a8c5c     PUSH       0x3
    //                              scr_sed.cpp:644 (19)
    //         004a8c5e     JMP        LAB_004a92fb
    //                               LAB_004a8c63                                                 XREF[1]:     004a8c04(j)  
    //         004a8c63     LEA        EDI,[EBX + 0x538]
    //         004a8c69     CMP        ESI,EDI
    //         004a8c6b     JNZ        LAB_004a8cf8
    //                              scr_sed.cpp:646 (14)
    //         004a8c71     MOV        this,dword ptr [EDI]
    //         004a8c73     PUSH       0x0
    //                              language.dll match for 0x296a: "Small Islands"
    //         004a8c75     PUSH       offset DAT_fffffff8
    //         004a8c7a     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:647 (14)
    //         004a8c7f     MOV        this,dword ptr [EDI]
    //         004a8c81     PUSH       0x0
    //                              language.dll match for 0x296b: "Large Islands"
    //         004a8c83     PUSH       offset DAT_fffffff8
    //         004a8c88     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:648 (14)
    //         004a8c8d     MOV        this,dword ptr [EDI]
    //         004a8c8f     PUSH       0x0
    //                              language.dll match for 0x296c: "Coastal"
    //         004a8c91     PUSH       offset DAT_fffffff8
    //         004a8c96     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:649 (14)
    //         004a8c9b     MOV        this,dword ptr [EDI]
    //         004a8c9d     PUSH       0x0
    //                              language.dll match for 0x296d: "Inland"
    //         004a8c9f     PUSH       offset DAT_fffffff8
    //         004a8ca4     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:650 (14)
    //         004a8ca9     MOV        this,dword ptr [EDI]
    //         004a8cab     PUSH       0x0
    //                              language.dll match for 0x296e: "Highland"
    //         004a8cad     PUSH       offset DAT_fffffff8
    //         004a8cb2     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:651 (14)
    //         004a8cb7     MOV        this,dword ptr [EDI]
    //         004a8cb9     PUSH       0x0
    //                              language.dll match for 0x296f: "Continental"
    //         004a8cbb     PUSH       offset DAT_fffffff8
    //         004a8cc0     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:652 (14)
    //         004a8cc5     MOV        this,dword ptr [EDI]
    //         004a8cc7     PUSH       0x0
    //                              language.dll match for 0x2970: "Mediterranean"
    //         004a8cc9     PUSH       offset DAT_fffffff8
    //         004a8cce     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:653 (14)
    //         004a8cd3     MOV        this,dword ptr [EDI]
    //         004a8cd5     PUSH       0x0
    //                              language.dll match for 0x2971: "Hill Country"
    //         004a8cd7     PUSH       offset DAT_fffffff8
    //         004a8cdc     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:654 (14)
    //         004a8ce1     MOV        this,dword ptr [EDI]
    //         004a8ce3     PUSH       0x0
    //                              language.dll match for 0x2972: "Narrows"
    //                              language.dll match for 0x2972: "******* SIZE *******"
    //         004a8ce5     PUSH       offset DAT_fffffff8
    //         004a8cea     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:655 (4)
    //         004a8cef     MOV        this,dword ptr [EDI]
    //         004a8cf1     PUSH       0x3
    //                              scr_sed.cpp:657 (15)
    //         004a8cf3     JMP        LAB_004a92fb
    //                               LAB_004a8cf8                                                 XREF[1]:     004a8c6b(j)  
    //         004a8cf8     LEA        EDI,[EBX + 0x5b8]
    //         004a8cfe     CMP        ESI,EDI
    //         004a8d00     JNZ        LAB_004a8d23
    //                              scr_sed.cpp:659 (8)
    //         004a8d02     XOR        ESI,ESI
    //                               LAB_004a8d04                                                 XREF[1]:     004a8d18(j)  
    //         004a8d04     LEA        this,[ESI + 0x2877]
    //                              scr_sed.cpp:660 (16)
    //         004a8d0a     PUSH       0x0
    //         004a8d0c     PUSH       this=>DAT_fffffff8
    //         004a8d0d     MOV        this,dword ptr [EDI]
    //         004a8d0f     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //         004a8d14     INC        ESI
    //         004a8d15     CMP        ESI,0x8
    //         004a8d18     JL         LAB_004a8d04
    //                              scr_sed.cpp:662 (4)
    //         004a8d1a     MOV        this,dword ptr [EDI]
    //         004a8d1c     PUSH       0x0
    //                              scr_sed.cpp:664 (15)
    //         004a8d1e     JMP        LAB_004a92fb
    //                               LAB_004a8d23                                                 XREF[1]:     004a8d00(j)  
    //         004a8d23     LEA        EDI,[EBX + 0x740]
    //         004a8d29     CMP        ESI,EDI
    //         004a8d2b     JNZ        LAB_004a8d4e
    //                              scr_sed.cpp:666 (2)
    //         004a8d2d     XOR        ESI,ESI
    //                               LAB_004a8d2f                                                 XREF[1]:     004a8d43(j)  
    //                              scr_sed.cpp:667 (22)
    //         004a8d2f     MOV        this,dword ptr [EDI]
    //         004a8d31     LEA        EDX,[ESI + 0x2877]
    //         004a8d37     PUSH       0x0
    //         004a8d39     PUSH       EDX=>DAT_fffffff8
    //         004a8d3a     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //         004a8d3f     INC        ESI
    //         004a8d40     CMP        ESI,0x8
    //         004a8d43     JL         LAB_004a8d2f
    //                              scr_sed.cpp:669 (4)
    //         004a8d45     MOV        this,dword ptr [EDI]
    //         004a8d47     PUSH       0x0
    //                              scr_sed.cpp:671 (15)
    //         004a8d49     JMP        LAB_004a92fb
    //                               LAB_004a8d4e                                                 XREF[1]:     004a8d2b(j)  
    //         004a8d4e     LEA        EDI,[EBX + 0x744]
    //         004a8d54     CMP        ESI,EDI
    //         004a8d56     JNZ        LAB_004a8dc3
    //                              scr_sed.cpp:673 (14)
    //         004a8d58     MOV        this,dword ptr [EDI]
    //         004a8d5a     PUSH       0x2b
    //                              language.dll match for 0x2882: "Razings"
    //         004a8d5c     PUSH       offset DAT_fffffff8
    //         004a8d61     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:674 (14)
    //         004a8d66     MOV        this,dword ptr [EDI]
    //         004a8d68     PUSH       0x29
    //                              language.dll match for 0x2883: "Conversions"
    //         004a8d6a     PUSH       offset DAT_fffffff8
    //         004a8d6f     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:675 (14)
    //         004a8d74     MOV        this,dword ptr [EDI]
    //         004a8d76     PUSH       0x2c
    //                              language.dll match for 0x2884: "Kill Ratio"
    //         004a8d78     PUSH       offset DAT_fffffff8
    //         004a8d7d     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:677 (14)
    //         004a8d82     MOV        this,dword ptr [EDI]
    //         004a8d84     PUSH       0x28
    //                              language.dll match for 0x2886: "Military Population"
    //         004a8d86     PUSH       offset DAT_fffffff8
    //         004a8d8b     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:678 (14)
    //         004a8d90     MOV        this,dword ptr [EDI]
    //         004a8d92     PUSH       0x15
    //                              language.dll match for 0x2887: "Technologies"
    //         004a8d94     PUSH       offset DAT_fffffff8
    //         004a8d99     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:679 (14)
    //         004a8d9e     MOV        this,dword ptr [EDI]
    //         004a8da0     PUSH       0x14
    //                              language.dll match for 0x2888: "Kills"
    //         004a8da2     PUSH       offset DAT_fffffff8
    //         004a8da7     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:680 (14)
    //         004a8dac     MOV        this,dword ptr [EDI]
    //         004a8dae     PUSH       0x25
    //                              language.dll match for 0x2889: "Villager Population"
    //         004a8db0     PUSH       offset DAT_fffffff8
    //         004a8db5     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:681 (4)
    //         004a8dba     MOV        this,dword ptr [EDI]
    //         004a8dbc     PUSH       0x0
    //                              scr_sed.cpp:683 (19)
    //         004a8dbe     JMP        LAB_004a92fb
    //                               LAB_004a8dc3                                                 XREF[1]:     004a8d56(j)  
    //         004a8dc3     LEA        EDI,[EBX + 0x528]
    //         004a8dc9     CMP        ESI,EDI
    //         004a8dcb     JNZ        LAB_004a8e58
    //                              scr_sed.cpp:686 (14)
    //         004a8dd1     MOV        this,dword ptr [EDI]
    //         004a8dd3     PUSH       0x0
    //                              language.dll match for 0x297d: "Grass"
    //         004a8dd5     PUSH       offset DAT_fffffff8
    //         004a8dda     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:687 (14)
    //         004a8ddf     MOV        this,dword ptr [EDI]
    //         004a8de1     PUSH       0x0
    //                              language.dll match for 0x297e: "Desert"
    //         004a8de3     PUSH       offset DAT_fffffff8
    //         004a8de8     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:688 (14)
    //         004a8ded     MOV        this,dword ptr [EDI]
    //         004a8def     PUSH       0x0
    //                              language.dll match for 0x297f: "Forest"
    //         004a8df1     PUSH       offset DAT_fffffff8
    //         004a8df6     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:689 (14)
    //         004a8dfb     MOV        this,dword ptr [EDI]
    //         004a8dfd     PUSH       0x0
    //                              language.dll match for 0x2980: "Water"
    //         004a8dff     PUSH       offset DAT_fffffff8
    //         004a8e04     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:690 (14)
    //         004a8e09     MOV        this,dword ptr [EDI]
    //         004a8e0b     PUSH       0x0
    //                              language.dll match for 0x2981: "Palm Desert"
    //         004a8e0d     PUSH       offset DAT_fffffff8
    //         004a8e12     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:691 (14)
    //         004a8e17     MOV        this,dword ptr [EDI]
    //         004a8e19     PUSH       0x0
    //                              language.dll match for 0x2982: "Jungle"
    //         004a8e1b     PUSH       offset DAT_fffffff8
    //         004a8e20     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:692 (14)
    //         004a8e25     MOV        this,dword ptr [EDI]
    //         004a8e27     PUSH       0x0
    //                              language.dll match for 0x2983: "Shallows"
    //         004a8e29     PUSH       offset DAT_fffffff8
    //         004a8e2e     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:693 (14)
    //         004a8e33     MOV        this,dword ptr [EDI]
    //         004a8e35     PUSH       0x0
    //                              language.dll match for 0x2984: "Pine Forest"
    //         004a8e37     PUSH       offset DAT_fffffff8
    //         004a8e3c     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:694 (14)
    //         004a8e41     MOV        this,dword ptr [EDI]
    //         004a8e43     PUSH       0x0
    //                              language.dll match for 0x2985: "Deep Water"
    //         004a8e45     PUSH       offset DAT_fffffff8
    //         004a8e4a     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:695 (4)
    //         004a8e4f     MOV        this,dword ptr [EDI]
    //         004a8e51     PUSH       0x0
    //                              scr_sed.cpp:697 (15)
    //         004a8e53     JMP        LAB_004a92fb
    //                               LAB_004a8e58                                                 XREF[1]:     004a8dcb(j)  
    //         004a8e58     LEA        EDI,[EBX + 0x5f8]
    //         004a8e5e     CMP        ESI,EDI
    //         004a8e60     JNZ        LAB_004a8e87
    //                              scr_sed.cpp:700 (14)
    //         004a8e62     MOV        this,dword ptr [EDI]
    //         004a8e64     PUSH       0x0
    //                              language.dll match for 0x27e3: "Computer"
    //         004a8e66     PUSH       offset DAT_fffffff8
    //         004a8e6b     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:701 (14)
    //         004a8e70     MOV        this,dword ptr [EDI]
    //         004a8e72     PUSH       0x0
    //                              language.dll match for 0x27e4: "Either"
    //         004a8e74     PUSH       offset DAT_fffffff8
    //         004a8e79     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:702 (4)
    //         004a8e7e     MOV        this,dword ptr [EDI]
    //         004a8e80     PUSH       0x0
    //                              scr_sed.cpp:715 (19)
    //         004a8e82     JMP        LAB_004a92fb
    //                               LAB_004a8e87                                                 XREF[1]:     004a8e60(j)  
    //         004a8e87     LEA        EDI,[EBX + 0x734]
    //         004a8e8d     CMP        ESI,EDI
    //         004a8e8f     JNZ        LAB_004a8fa8
    //                              scr_sed.cpp:718 (14)
    //         004a8e95     MOV        this,dword ptr [EDI]
    //         004a8e97     PUSH       0x0
    //                              language.dll match for 0x2851: "         < None >"
    //         004a8e99     PUSH       offset DAT_fffffff8
    //         004a8e9e     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:719 (14)
    //         004a8ea3     MOV        this,dword ptr [EDI]
    //         004a8ea5     PUSH       0x0
    //                              language.dll match for 0x2852: " Bring Object to Object"
    //         004a8ea7     PUSH       offset DAT_fffffff8
    //         004a8eac     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:720 (14)
    //         004a8eb1     MOV        this,dword ptr [EDI]
    //         004a8eb3     PUSH       0x0
    //                              language.dll match for 0x2853: " Bring Object to Area"
    //         004a8eb5     PUSH       offset DAT_fffffff8
    //         004a8eba     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:721 (14)
    //         004a8ebf     MOV        this,dword ptr [EDI]
    //         004a8ec1     PUSH       0x0
    //                              language.dll match for 0x2854: " Create # of Objects"
    //         004a8ec3     PUSH       offset DAT_fffffff8
    //         004a8ec8     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:722 (14)
    //         004a8ecd     MOV        this,dword ptr [EDI]
    //         004a8ecf     PUSH       0x0
    //                              language.dll match for 0x2855: " Create Objects in Area"
    //         004a8ed1     PUSH       offset DAT_fffffff8
    //         004a8ed6     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:723 (14)
    //         004a8edb     MOV        this,dword ptr [EDI]
    //         004a8edd     PUSH       0x0
    //                              language.dll match for 0x2856: " Destroy # of Objects"
    //         004a8edf     PUSH       offset DAT_fffffff8
    //         004a8ee4     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:724 (14)
    //         004a8ee9     MOV        this,dword ptr [EDI]
    //         004a8eeb     PUSH       0x0
    //                              language.dll match for 0x2857: " Destroy Specific Object"
    //         004a8eed     PUSH       offset DAT_fffffff8
    //         004a8ef2     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:725 (14)
    //         004a8ef7     MOV        this,dword ptr [EDI]
    //         004a8ef9     PUSH       0x0
    //                              language.dll match for 0x2858: " Destroy All Objects"
    //         004a8efb     PUSH       offset DAT_fffffff8
    //         004a8f00     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:726 (14)
    //         004a8f05     MOV        this,dword ptr [EDI]
    //         004a8f07     PUSH       0x0
    //                              language.dll match for 0x2859: " Destroy Player"
    //         004a8f09     PUSH       offset DAT_fffffff8
    //         004a8f0e     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:727 (14)
    //         004a8f13     MOV        this,dword ptr [EDI]
    //         004a8f15     PUSH       0x0
    //                              language.dll match for 0x285a: " Capture Object"
    //         004a8f17     PUSH       offset DAT_fffffff8
    //         004a8f1c     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:728 (14)
    //         004a8f21     MOV        this,dword ptr [EDI]
    //         004a8f23     PUSH       0x0
    //                              language.dll match for 0x285b: " Gold Stockpile"
    //         004a8f25     PUSH       offset DAT_fffffff8
    //         004a8f2a     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:729 (14)
    //         004a8f2f     MOV        this,dword ptr [EDI]
    //         004a8f31     PUSH       0x0
    //                              language.dll match for 0x285c: " Food Stockpile"
    //         004a8f33     PUSH       offset DAT_fffffff8
    //         004a8f38     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:730 (14)
    //         004a8f3d     MOV        this,dword ptr [EDI]
    //         004a8f3f     PUSH       0x0
    //                              language.dll match for 0x285d: " Wood Stockpile"
    //         004a8f41     PUSH       offset DAT_fffffff8
    //         004a8f46     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:731 (14)
    //         004a8f4b     MOV        this,dword ptr [EDI]
    //         004a8f4d     PUSH       0x0
    //                              language.dll match for 0x285e: " Stone Stockpile"
    //         004a8f4f     PUSH       offset DAT_fffffff8
    //         004a8f54     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:732 (14)
    //         004a8f59     MOV        this,dword ptr [EDI]
    //         004a8f5b     PUSH       0x0
    //                              language.dll match for 0x285f: " Population"
    //         004a8f5d     PUSH       offset DAT_fffffff8
    //         004a8f62     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:733 (14)
    //         004a8f67     MOV        this,dword ptr [EDI]
    //         004a8f69     PUSH       0x0
    //                              language.dll match for 0x2860: " Age"
    //         004a8f6b     PUSH       offset DAT_fffffff8
    //         004a8f70     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:734 (14)
    //         004a8f75     MOV        this,dword ptr [EDI]
    //         004a8f77     PUSH       0x0
    //                              language.dll match for 0x2861: " Exploration"
    //         004a8f79     PUSH       offset DAT_fffffff8
    //         004a8f7e     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:735 (14)
    //         004a8f83     MOV        this,dword ptr [EDI]
    //         004a8f85     PUSH       0x0
    //                              language.dll match for 0x2862: " Other Attributes"
    //         004a8f87     PUSH       offset DAT_fffffff8
    //         004a8f8c     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:736 (14)
    //         004a8f91     MOV        this,dword ptr [EDI]
    //         004a8f93     PUSH       0x0
    //                              language.dll match for 0x284f: "Technologies"
    //         004a8f95     PUSH       offset DAT_fffffff8
    //         004a8f9a     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:737 (4)
    //         004a8f9f     MOV        this,dword ptr [EDI]
    //         004a8fa1     PUSH       0x0
    //                              scr_sed.cpp:739 (19)
    //         004a8fa3     JMP        LAB_004a92fb
    //                               LAB_004a8fa8                                                 XREF[1]:     004a8e8f(j)  
    //         004a8fa8     LEA        EDI,[EBX + 0x5fc]
    //         004a8fae     CMP        ESI,EDI
    //         004a8fb0     JNZ        LAB_004a909f
    //                              scr_sed.cpp:742 (14)
    //         004a8fb6     MOV        this,dword ptr [EDI]
    //         004a8fb8     PUSH       0x0
    //                              language.dll match for 0x27f7: "Egyptian"
    //         004a8fba     PUSH       offset DAT_fffffff8
    //         004a8fbf     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:743 (14)
    //         004a8fc4     MOV        this,dword ptr [EDI]
    //         004a8fc6     PUSH       0x0
    //                              language.dll match for 0x27f8: "Greek"
    //         004a8fc8     PUSH       offset DAT_fffffff8
    //         004a8fcd     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:744 (14)
    //         004a8fd2     MOV        this,dword ptr [EDI]
    //         004a8fd4     PUSH       0x0
    //                              language.dll match for 0x27f9: "Babylonian"
    //         004a8fd6     PUSH       offset DAT_fffffff8
    //         004a8fdb     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:745 (14)
    //         004a8fe0     MOV        this,dword ptr [EDI]
    //         004a8fe2     PUSH       0x0
    //                              language.dll match for 0x27fa: "Assyrian"
    //         004a8fe4     PUSH       offset DAT_fffffff8
    //         004a8fe9     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:746 (14)
    //         004a8fee     MOV        this,dword ptr [EDI]
    //         004a8ff0     PUSH       0x0
    //                              language.dll match for 0x27fb: "Minoan"
    //         004a8ff2     PUSH       offset DAT_fffffff8
    //         004a8ff7     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:747 (14)
    //         004a8ffc     MOV        this,dword ptr [EDI]
    //         004a8ffe     PUSH       0x0
    //                              language.dll match for 0x27fc: "Hittite"
    //         004a9000     PUSH       offset DAT_fffffff8
    //         004a9005     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:748 (14)
    //         004a900a     MOV        this,dword ptr [EDI]
    //         004a900c     PUSH       0x0
    //                              language.dll match for 0x27fd: "Phoenician"
    //         004a900e     PUSH       offset DAT_fffffff8
    //         004a9013     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:749 (14)
    //         004a9018     MOV        this,dword ptr [EDI]
    //         004a901a     PUSH       0x0
    //                              language.dll match for 0x27fe: "Sumerian"
    //         004a901c     PUSH       offset DAT_fffffff8
    //         004a9021     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:750 (14)
    //         004a9026     MOV        this,dword ptr [EDI]
    //         004a9028     PUSH       0x0
    //                              language.dll match for 0x27ff: "Persian"
    //         004a902a     PUSH       offset DAT_fffffff8
    //         004a902f     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:751 (14)
    //         004a9034     MOV        this,dword ptr [EDI]
    //         004a9036     PUSH       0x0
    //                              language.dll match for 0x2800: "Shang"
    //         004a9038     PUSH       offset DAT_fffffff8
    //         004a903d     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:752 (14)
    //         004a9042     MOV        this,dword ptr [EDI]
    //         004a9044     PUSH       0x0
    //                              language.dll match for 0x2801: "Yamato"
    //         004a9046     PUSH       offset DAT_fffffff8
    //         004a904b     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:753 (14)
    //         004a9050     MOV        this,dword ptr [EDI]
    //         004a9052     PUSH       0x0
    //                              language.dll match for 0x2802: "Choson"
    //         004a9054     PUSH       offset DAT_fffffff8
    //         004a9059     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:754 (14)
    //         004a905e     MOV        this,dword ptr [EDI]
    //         004a9060     PUSH       0x0
    //                              language.dll match for 0x2806: "Roman"
    //         004a9062     PUSH       offset DAT_fffffff8
    //         004a9067     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:755 (14)
    //         004a906c     MOV        this,dword ptr [EDI]
    //         004a906e     PUSH       0x0
    //                              language.dll match for 0x2807: "Carthaginian"
    //         004a9070     PUSH       offset DAT_fffffff8
    //         004a9075     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:756 (14)
    //         004a907a     MOV        this,dword ptr [EDI]
    //         004a907c     PUSH       0x0
    //                              language.dll match for 0x2809: "Palmyran"
    //         004a907e     PUSH       offset DAT_fffffff8
    //         004a9083     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:757 (14)
    //         004a9088     MOV        this,dword ptr [EDI]
    //         004a908a     PUSH       0x0
    //                              language.dll match for 0x2808: "Macedonian"
    //         004a908c     PUSH       offset DAT_fffffff8
    //         004a9091     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:758 (4)
    //         004a9096     MOV        this,dword ptr [EDI]
    //         004a9098     PUSH       0x0
    //                              scr_sed.cpp:760 (15)
    //         004a909a     JMP        LAB_004a92fb
    //                               LAB_004a909f                                                 XREF[1]:     004a8fb0(j)  
    //         004a909f     LEA        EDI,[EBX + 0x748]
    //         004a90a5     CMP        ESI,EDI
    //         004a90a7     JNZ        LAB_004a90ea
    //                              scr_sed.cpp:762 (14)
    //         004a90a9     MOV        this,dword ptr [EDI]
    //         004a90ab     PUSH       0x0
    //                              language.dll match for 0x1069: "Stone Age"
    //         004a90ad     PUSH       offset DAT_fffffff8
    //         004a90b2     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:763 (14)
    //         004a90b7     MOV        this,dword ptr [EDI]
    //         004a90b9     PUSH       0x0
    //                              language.dll match for 0x106a: "Tool Age"
    //         004a90bb     PUSH       offset DAT_fffffff8
    //         004a90c0     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:764 (14)
    //         004a90c5     MOV        this,dword ptr [EDI]
    //         004a90c7     PUSH       0x0
    //                              language.dll match for 0x106b: "Bronze Age"
    //         004a90c9     PUSH       offset DAT_fffffff8
    //         004a90ce     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:765 (14)
    //         004a90d3     MOV        this,dword ptr [EDI]
    //         004a90d5     PUSH       0x0
    //                              language.dll match for 0x106c: "Iron Age"
    //         004a90d7     PUSH       offset DAT_fffffff8
    //         004a90dc     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_sed.cpp:767 (4)
    //         004a90e1     MOV        this,dword ptr [EDI]
    //         004a90e3     PUSH       0x0
    //                              scr_sed.cpp:769 (15)
    //         004a90e5     JMP        LAB_004a92fb
    //                               LAB_004a90ea                                                 XREF[1]:     004a90a7(j)  
    //         004a90ea     LEA        EBP,[EBX + 0x74c]
    //         004a90f0     CMP        ESI,EBP
    //         004a90f2     JNZ        LAB_004a9163
    //                              scr_sed.cpp:771 (10)
    //         004a90f4     MOV        this,dword ptr [EBP]
    //         004a90f7     PUSH       0x1
    //         004a90f9     CALL       TDropDownPanel::set_sorted                       void set_sorted(TDropDownPanel * this, int pa
    //                              scr_sed.cpp:772 (25)
    //         004a90fe     MOV        EAX,[rge_base_game]                              = 00000000
    //         004a9103     XOR        ESI,ESI
    //         004a9105     MOV        this,dword ptr [EAX + 0x3f4]
    //         004a910b     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004a9111     CMP        word ptr [EAX + 0x4],SI
    //         004a9115     JLE        LAB_004a9159
    //                              scr_sed.cpp:831 (2)
    //         004a9117     XOR        EDI,EDI
    //                               LAB_004a9119                                                 XREF[1]:     004a9157(j)  
    //                              scr_sed.cpp:774 (15)
    //         004a9119     MOV        EDX,dword ptr [EAX]
    //         004a911b     MOV        this,EBX
    //         004a911d     MOVSX      EAX,word ptr [EDX + EDI*0x1 + 0x2a]
    //         004a9122     PUSH       EAX
    //         004a9123     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
    //                              scr_sed.cpp:775 (9)
    //         004a9128     TEST       EAX,EAX
    //         004a912a     JZ         LAB_004a913b
    //         004a912c     CMP        byte ptr [EAX],0x0
    //         004a912f     JZ         LAB_004a913b
    //                              scr_sed.cpp:776 (40)
    //         004a9131     MOV        this,dword ptr [EBP]
    //         004a9134     PUSH       ESI
    //         004a9135     PUSH       EAX=>DAT_fffffff8
    //         004a9136     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
    //                               LAB_004a913b                                                 XREF[2]:     004a912a(j), 004a912f(j)  
    //         004a913b     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004a9141     INC        ESI
    //         004a9142     ADD        EDI,0x3c
    //         004a9145     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004a914b     MOV        EAX,dword ptr [EDX + 0x104]
    //         004a9151     MOVSX      this,word ptr [EAX + 0x4]
    //         004a9155     CMP        ESI,this
    //         004a9157     JL         LAB_004a9119
    //                               LAB_004a9159                                                 XREF[1]:     004a9115(j)  
    //                              scr_sed.cpp:778 (5)
    //         004a9159     MOV        this,dword ptr [EBP]
    //         004a915c     PUSH       0x0
    //                              scr_sed.cpp:780 (15)
    //         004a915e     JMP        LAB_004a92fb
    //                               LAB_004a9163                                                 XREF[1]:     004a90f2(j)  
    //         004a9163     LEA        EAX,[EBX + 0x608]
    //         004a9169     CMP        ESI,EAX
    //         004a916b     JNZ        LAB_004a918e
    //                              scr_sed.cpp:782 (28)
    //         004a916d     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         004a9173     PUSH       0x1
    //         004a9175     PUSH       0x0=>DAT_fffffff8
    //         004a9177     PUSH       s_.per                                           = ".per"
    //         004a917c     MOV        this,dword ptr [EDX + 0xc]
    //         004a917f     MOV        EDX,dword ptr [EAX]
    //         004a9181     ADD        this,0x102b
    //         004a9187     PUSH       this=>DAT_fffffff0
    //         004a9188     PUSH       EDX
    //                              scr_sed.cpp:785 (15)
    //         004a9189     JMP        LAB_004a92f0
    //                               LAB_004a918e                                                 XREF[1]:     004a916b(j)  
    //         004a918e     LEA        EAX,[EBX + 0x600]
    //         004a9194     CMP        ESI,EAX
    //         004a9196     JNZ        LAB_004a91a3
    //                              scr_sed.cpp:787 (9)
    //         004a9198     PUSH       0x1
    //         004a919a     PUSH       offset DAT_fffffff8
    //         004a919c     PUSH       s_.ai                                            = ".ai"
    //                              scr_sed.cpp:790 (12)
    //         004a91a1     JMP        LAB_004a91b6
    //                               LAB_004a91a3                                                 XREF[1]:     004a9196(j)  
    //         004a91a3     LEA        EAX,[EBX + 0x604]
    //         004a91a9     CMP        ESI,EAX
    //         004a91ab     JNZ        LAB_004a91ce
    //                              scr_sed.cpp:792 (28)
    //         004a91ad     PUSH       0x0
    //         004a91af     PUSH       offset DAT_fffffff8
    //         004a91b1     PUSH       s_.cty                                           = ".cty"
    //                               LAB_004a91b6                                                 XREF[1]:     004a91a1(j)  
    //         004a91b6     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004a91bc     MOV        EAX,dword ptr [EAX]
    //         004a91be     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004a91c1     ADD        EDX,0x102b
    //         004a91c7     PUSH       EDX=>DAT_fffffff0
    //         004a91c8     PUSH       EAX
    //                              scr_sed.cpp:795 (47)
    //         004a91c9     JMP        LAB_004a92f0
    //                               LAB_004a91ce                                                 XREF[1]:     004a91ab(j)  
    //         004a91ce     LEA        this,[EBX + 0x7b4]
    //         004a91d4     CMP        ESI,this
    //         004a91d6     JZ         LAB_004a92d5
    //         004a91dc     LEA        EDX,[EBX + 0x7b8]
    //         004a91e2     CMP        ESI,EDX
    //         004a91e4     JZ         LAB_004a92d5
    //         004a91ea     LEA        EAX,[EBX + 0x7bc]
    //         004a91f0     CMP        ESI,EAX
    //         004a91f2     JZ         LAB_004a92d5
    //                              scr_sed.cpp:800 (10)
    //         004a91f8     LEA        this,[EBX + 0x7c0]
    //         004a91fe     CMP        ESI,this
    //         004a9200     JNZ        LAB_004a9218
    //                              scr_sed.cpp:802 (17)
    //         004a9202     MOV        EDX,dword ptr [ESI]
    //         004a9204     PUSH       0x0
    //         004a9206     PUSH       offset DAT_fffffff8
    //         004a9208     PUSH       s_.bmp                                           = ".bmp"
    //         004a920d     PUSH       s_                                               = ""
    //         004a9212     PUSH       EDX
    //                              scr_sed.cpp:805 (19)
    //         004a9213     JMP        LAB_004a92f0
    //                               LAB_004a9218                                                 XREF[1]:     004a9200(j)  
    //         004a9218     LEA        EDI,[EBX + 0x738]
    //         004a921e     CMP        ESI,EDI
    //         004a9220     JNZ        LAB_004a9300
    //                              scr_sed.cpp:807 (9)
    //         004a9226     MOV        this,dword ptr [EDI]
    //         004a9228     PUSH       0x1
    //         004a922a     CALL       TDropDownPanel::set_sorted                       void set_sorted(TDropDownPanel * this, int pa
    //                              scr_sed.cpp:808 (7)
    //         004a922f     MOV        this,dword ptr [EDI]
    //         004a9231     CALL       TDropDownPanel::empty_list                       void empty_list(TDropDownPanel * this)
    //                              scr_sed.cpp:811 (6)
    //         004a9236     MOV        EAX,dword ptr [EBX + 0x928]
    //                              scr_sed.cpp:813 (24)
    //         004a923c     XOR        EBP,EBP
    //         004a923e     MOV        this,dword ptr [EAX + 0x40]
    //         004a9241     MOV        ESI,dword ptr [ECX + this->_padding_]
    //         004a9244     MOV        dword ptr [ESP + 0x14],ESI
    //         004a9248     MOVSX      this,word ptr [ESI + 0x22]
    //         004a924c     TEST       this,this
    //         004a924e     MOV        dword ptr [ESP + 0x10],this
    //         004a9252     JLE        LAB_004a92cb
    //                               LAB_004a9254                                                 XREF[1]:     004a92c9(j)  
    //                              scr_sed.cpp:816 (17)
    //         004a9254     MOV        EDX,dword ptr [ESI + 0x24]
    //         004a9257     MOV        EAX,dword ptr [EDX + EBP*0x4]
    //         004a925a     TEST       EAX,EAX
    //         004a925c     JZ         LAB_004a92c6
    //         004a925e     MOV        DL,byte ptr [EAX + 0x4e]
    //         004a9261     TEST       DL,DL
    //         004a9263     JNZ        LAB_004a92c6
    //                              scr_sed.cpp:818 (9)
    //         004a9265     MOV        DX,word ptr [EAX + 0xc]
    //         004a9269     TEST       DX,DX
    //         004a926c     JLE        LAB_004a9289
    //                              scr_sed.cpp:819 (25)
    //         004a926e     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004a9274     LEA        EDI,[ESP + 0x18]
    //         004a9278     MOVSX      EDX,DX
    //         004a927b     MOV        EAX,dword ptr [this->_padding_]
    //         004a927d     PUSH       0x100
    //         004a9282     PUSH       EDI=>DAT_fffffff8
    //         004a9283     PUSH       EDX=>DAT_fffffff4
    //         004a9284     CALL       dword ptr [EAX + 0x20]
    //                              scr_sed.cpp:821 (2)
    //         004a9287     JMP        LAB_004a92b1
    //                               LAB_004a9289                                                 XREF[1]:     004a926c(j)  
    //                              scr_sed.cpp:822 (40)
    //         004a9289     MOV        EDI,dword ptr [EAX + 0x8]
    //         004a928c     OR         this,0xffffffff
    //         004a928f     XOR        EAX,EAX
    //         004a9291     LEA        EDX,[ESP + 0x18]
    //         004a9295     SCASB.RE   ES:EDI
    //         004a9297     NOT        this
    //         004a9299     SUB        EDI,this
    //         004a929b     MOV        EAX,this
    //         004a929d     MOV        ESI,EDI
    //         004a929f     MOV        EDI,EDX
    //         004a92a1     SHR        this,0x2
    //         004a92a4     MOVSD.REP  ES:EDI,ESI
    //         004a92a6     MOV        this,EAX
    //         004a92a8     AND        this,0x3
    //         004a92ab     MOVSB.REP  ES:EDI,ESI
    //         004a92ad     MOV        ESI,dword ptr [ESP + 0x14]
    //                               LAB_004a92b1                                                 XREF[1]:     004a9287(j)  
    //                              scr_sed.cpp:823 (26)
    //         004a92b1     LEA        this,[ESP + 0x18]
    //         004a92b5     PUSH       EBP
    //         004a92b6     PUSH       this=>DAT_fffffff8
    //         004a92b7     MOV        this,dword ptr [EBX + 0x738]
    //         004a92bd     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
    //         004a92c2     MOV        this,dword ptr [ESP + 0x10]
    //                               LAB_004a92c6                                                 XREF[2]:     004a925c(j), 004a9263(j)  
    //         004a92c6     INC        EBP
    //         004a92c7     CMP        EBP,this
    //         004a92c9     JL         LAB_004a9254
    //                               LAB_004a92cb                                                 XREF[1]:     004a9252(j)  
    //                              scr_sed.cpp:827 (10)
    //         004a92cb     MOV        this,dword ptr [EBX + 0x738]
    //         004a92d1     PUSH       0x0
    //         004a92d3     JMP        LAB_004a92fb
    //                               LAB_004a92d5                                                 XREF[3]:     004a91d6(j), 004a91e4(j), 
    //                                                                                                         004a91f2(j)  
    //                              scr_sed.cpp:797 (34)
    //         004a92d5     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         004a92db     MOV        this,dword ptr [ESI]
    //         004a92dd     PUSH       0x0
    //         004a92df     PUSH       offset DAT_fffffff8
    //         004a92e1     MOV        EAX,dword ptr [EDX + 0xc]
    //         004a92e4     PUSH       s_.avi                                           = ".avi"
    //         004a92e9     ADD        EAX,0x1130
    //         004a92ee     PUSH       EAX=>DAT_fffffff0
    //         004a92ef     PUSH       this
    //                               LAB_004a92f0                                                 XREF[3]:     004a9189(j), 004a91c9(j), 
    //                                                                                                         004a9213(j)  
    //         004a92f0     MOV        this,EBX
    //         004a92f2     CALL       TRIBE_Screen_Sed::MakeFileList                   int MakeFileList(TRIBE_Screen_Sed * this, TDr
    //                              scr_sed.cpp:798 (9)
    //         004a92f7     MOV        this,dword ptr [ESI]
    //         004a92f9     PUSH       0x0
    //                               LAB_004a92fb                                                 XREF[12]:    004a8c5e(j), 004a8cf3(j), 
    //                                                                                                         004a8d1e(j), 004a8d49(j), 
    //                                                                                                         004a8dbe(j), 004a8e53(j), 
    //                                                                                                         004a8e82(j), 004a8fa3(j), 
    //                                                                                                         004a909a(j), 004a90e5(j), 
    //                                                                                                         004a915e(j), 004a92d3(j)  
    //         004a92fb     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
    //                               LAB_004a9300                                                 XREF[1]:     004a9220(j)  
    //                              scr_sed.cpp:830 (8)
    //         004a9300     MOV        this,dword ptr [EBX + 0xd8]
    //         004a9306     XOR        EAX,EAX
    //                              scr_sed.cpp:831 (18)
    //         004a9308     POP        EDI
    //         004a9309     POP        ESI
    //         004a930a     TEST       this,this
    //         004a930c     POP        EBP
    //         004a930d     POP        EBX
    //         004a930e     SETZ       AL
    //         004a9311     ADD        ESP,0x108
    //         004a9317     RET        0x8
    //         004a931a     ??         90h
    //         004a931b     NOP
    //         004a931c     NOP
    //         004a931d     NOP
    //         004a931e     NOP
    //         004a931f     NOP
    return 0;
}

int TRIBE_Screen_Sed::SetupListOfTerrain(TListPanel* param_1) {
    /* TODO: Stub */
    //                              int __thiscall SetupListOfTerrain(TRIBE_Screen_Sed * this, TListPane
    //              int               EAX:4          <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              TListPanel *      Stack[0x4]:4   param_1                   XREF[1]:     004a9321(R)  
    //                               ?SetupListOfTerrain@TRIBE_Screen_Sed@@IAEHPAVTListPanel@@@Z  XREF[1]:     create_list:004a948b(c)  
    //                               TRIBE_Screen_Sed::SetupListOfTerrain
    //                              scr_sed.cpp:836 (1)
    //         004a9320     PUSH       ESI
    //                              scr_sed.cpp:837 (11)
    //         004a9321     MOV        ESI,dword ptr [ESP + param_1]
    //         004a9325     MOV        this,ESI
    //         004a9327     CALL       TTextPanel::empty_list                           void empty_list(TTextPanel * this)
    //                              scr_sed.cpp:838 (14)
    //         004a932c     PUSH       0x0
    //                              language.dll match for 0x297d: "Grass"
    //         004a932e     PUSH       0x297d
    //         004a9333     MOV        this,ESI
    //         004a9335     CALL       TTextPanel::append_line                          int append_line(TTextPanel * this, long param
    //                              scr_sed.cpp:839 (14)
    //         004a933a     PUSH       0x0
    //                              language.dll match for 0x297e: "Desert"
    //         004a933c     PUSH       0x297e
    //         004a9341     MOV        this,ESI
    //         004a9343     CALL       TTextPanel::append_line                          int append_line(TTextPanel * this, long param
    //                              scr_sed.cpp:840 (14)
    //         004a9348     PUSH       0x0
    //                              language.dll match for 0x297f: "Forest"
    //         004a934a     PUSH       0x297f
    //         004a934f     MOV        this,ESI
    //         004a9351     CALL       TTextPanel::append_line                          int append_line(TTextPanel * this, long param
    //                              scr_sed.cpp:841 (14)
    //         004a9356     PUSH       0x0
    //                              language.dll match for 0x2980: "Water"
    //         004a9358     PUSH       0x2980
    //         004a935d     MOV        this,ESI
    //         004a935f     CALL       TTextPanel::append_line                          int append_line(TTextPanel * this, long param
    //                              scr_sed.cpp:842 (14)
    //         004a9364     PUSH       0x0
    //                              language.dll match for 0x2981: "Palm Desert"
    //         004a9366     PUSH       0x2981
    //         004a936b     MOV        this,ESI
    //         004a936d     CALL       TTextPanel::append_line                          int append_line(TTextPanel * this, long param
    //                              scr_sed.cpp:843 (14)
    //         004a9372     PUSH       0x0
    //                              language.dll match for 0x2982: "Jungle"
    //         004a9374     PUSH       0x2982
    //         004a9379     MOV        this,ESI
    //         004a937b     CALL       TTextPanel::append_line                          int append_line(TTextPanel * this, long param
    //                              scr_sed.cpp:844 (14)
    //         004a9380     PUSH       0x0
    //                              language.dll match for 0x2983: "Shallows"
    //         004a9382     PUSH       0x2983
    //         004a9387     MOV        this,ESI
    //         004a9389     CALL       TTextPanel::append_line                          int append_line(TTextPanel * this, long param
    //                              scr_sed.cpp:845 (14)
    //         004a938e     PUSH       0x0
    //                              language.dll match for 0x2984: "Pine Forest"
    //         004a9390     PUSH       0x2984
    //         004a9395     MOV        this,ESI
    //         004a9397     CALL       TTextPanel::append_line                          int append_line(TTextPanel * this, long param
    //                              scr_sed.cpp:846 (14)
    //         004a939c     PUSH       0x0
    //                              language.dll match for 0x2985: "Deep Water"
    //         004a939e     PUSH       0x2985
    //         004a93a3     MOV        this,ESI
    //         004a93a5     CALL       TTextPanel::append_line                          int append_line(TTextPanel * this, long param
    //                              scr_sed.cpp:847 (5)
    //         004a93aa     MOV        EAX,0x8
    //                              scr_sed.cpp:848 (4)
    //         004a93af     POP        ESI
    //         004a93b0     RET        0x4
    //         004a93b3     ??         90h
    //         004a93b4     NOP
    //         004a93b5     NOP
    //         004a93b6     NOP
    //         004a93b7     NOP
    //         004a93b8     NOP
    //         004a93b9     NOP
    //         004a93ba     NOP
    //         004a93bb     NOP
    //         004a93bc     NOP
    //         004a93bd     NOP
    //         004a93be     NOP
    //         004a93bf     NOP
    //                              * protected: int __thiscall TRIBE_Screen_Sed::create_list(class TPanel *,class TListPanel * *,class ... *
    //                              int __thiscall create_list(TRIBE_Screen_Sed * this, TPanel * param_1
    //              int               EAX:4          <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     004a93c3(R)  
    //              TListPanel * *    Stack[0x8]:4   param_2                   XREF[1]:     004a93c8(R)  
    //              TScrollBarPane    Stack[0xc]:4   param_3
    //              char[60]          Stack[-0x40]   str2
    //              char[50]          Stack[-0x74]   str1
    //                               ?create_list@TRIBE_Screen_Sed@@IAEHPAVTPanel@@PAPAVTListPan  XREF[3]:     create_all_buttons_etc:004aff22(c)
    //                               TRIBE_Screen_Sed::create_list                                             create_all_buttons_etc:004aff54(c)
    //                                                                                                         create_all_buttons_etc:004b0106(c)
    //                              scr_sed.cpp:854 (3)
    //         004a93c0     SUB        ESP,0x70
    //                              scr_sed.cpp:855 (34)
    //         004a93c3     MOV        EAX,dword ptr [ESP + param_1]
    //         004a93c7     PUSH       EBX
    //         004a93c8     MOV        EBX,dword ptr [ESP + param_2]
    //         004a93cc     PUSH       ESI
    //         004a93cd     PUSH       EDI
    //         004a93ce     PUSH       0xa
    //         004a93d0     PUSH       0x0
    //         004a93d2     PUSH       0x0
    //         004a93d4     PUSH       0x0
    //         004a93d6     PUSH       0x0
    //         004a93d8     PUSH       EBX
    //         004a93d9     MOV        ESI,this
    //         004a93db     PUSH       EAX
    //         004a93dc     CALL       TEasy_Panel::create_list                         int create_list(TEasy_Panel * this, TPanel * 
    //         004a93e1     TEST       EAX,EAX
    //         004a93e3     JNZ        LAB_004a93ee
    //                              scr_sed.cpp:884 (9)
    //         004a93e5     POP        EDI
    //         004a93e6     POP        ESI
    //         004a93e7     POP        EBX
    //         004a93e8     ADD        ESP,0x70
    //         004a93eb     RET        0xc
    //                               LAB_004a93ee                                                 XREF[1]:     004a93e3(j)  
    //                              scr_sed.cpp:858 (9)
    //         004a93ee     MOV        this,dword ptr [EBX]
    //         004a93f0     PUSH       0x0
    //         004a93f2     MOV        EDX,dword ptr [this->_padding_]
    //         004a93f4     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:859 (7)
    //         004a93f7     MOV        this,dword ptr [EBX]
    //         004a93f9     CALL       TTextPanel::empty_list                           void empty_list(TTextPanel * this)
    //                              scr_sed.cpp:861 (24)
    //         004a93fe     MOV        EAX,dword ptr [EBX]
    //         004a9400     MOV        this,dword ptr [ESP + 0x88]
    //         004a9407     PUSH       0x14
    //         004a9409     PUSH       EAX=>DAT_fffffff8
    //         004a940a     PUSH       this=>DAT_fffffff4
    //         004a940b     MOV        this,ESI
    //         004a940d     CALL       TEasy_Panel::create_auto_scrollbar               int create_auto_scrollbar(TEasy_Panel * this,
    //         004a9412     TEST       EAX,EAX
    //         004a9414     JNZ        LAB_004a941f
    //                              scr_sed.cpp:884 (9)
    //         004a9416     POP        EDI
    //         004a9417     POP        ESI
    //         004a9418     POP        EBX
    //         004a9419     ADD        ESP,0x70
    //         004a941c     RET        0xc
    //                               LAB_004a941f                                                 XREF[1]:     004a9414(j)  
    //                              scr_sed.cpp:865 (10)
    //         004a941f     LEA        EDI,[ESI + 0x5a8]
    //         004a9425     CMP        EBX,EDI
    //         004a9427     JNZ        LAB_004a947c
    //                              scr_sed.cpp:870 (19)
    //         004a9429     PUSH       0x32
    //         004a942b     LEA        EDX,[ESP + 0x10]
    //                              language.dll match for 0x2987: "Elevation"
    //         004a942f     PUSH       offset DAT_fffffff8
    //         004a9434     PUSH       EDX=>DAT_fffffff4
    //         004a9435     MOV        this,ESI
    //         004a9437     CALL       TRIBE_Screen_Sed::set_string                     void set_string(TRIBE_Screen_Sed * this, char
    //                              scr_sed.cpp:871 (5)
    //         004a943c     XOR        EAX,EAX
    //                               LAB_004a943e                                                 XREF[1]:     004a946c(j)  
    //         004a943e     LEA        ESI,[EAX + 0x1]
    //                              scr_sed.cpp:873 (21)
    //         004a9441     LEA        EAX,[ESP + 0xc]
    //         004a9445     PUSH       ESI
    //         004a9446     PUSH       EAX=>DAT_fffffff8
    //         004a9447     LEA        this,[ESP + 0x48]
    //         004a944b     PUSH       s_%s_%d                                          = "%s %d"
    //         004a9450     PUSH       this=>DAT_fffffff0
    //         004a9451     CALL       sprintf                                          undefined sprintf()
    //                              scr_sed.cpp:874 (24)
    //         004a9456     MOV        this,dword ptr [EDI]
    //         004a9458     ADD        ESP,0x10
    //         004a945b     LEA        EDX,[ESP + 0x40]
    //         004a945f     PUSH       0x0
    //         004a9461     PUSH       EDX=>DAT_fffffff8
    //         004a9462     CALL       TTextPanel::append_line                          int append_line(TTextPanel * this, char * par
    //         004a9467     MOV        EAX,ESI
    //         004a9469     CMP        EAX,0x7
    //         004a946c     JL         LAB_004a943e
    //                              scr_sed.cpp:883 (5)
    //         004a946e     MOV        EAX,0x1
    //                              scr_sed.cpp:884 (9)
    //         004a9473     POP        EDI
    //         004a9474     POP        ESI
    //         004a9475     POP        EBX
    //         004a9476     ADD        ESP,0x70
    //         004a9479     RET        0xc
    //                               LAB_004a947c                                                 XREF[1]:     004a9427(j)  
    //                              scr_sed.cpp:877 (10)
    //         004a947c     LEA        EAX,[ESI + 0x5a0]
    //         004a9482     CMP        EBX,EAX
    //         004a9484     JNZ        LAB_004a9490
    //                              scr_sed.cpp:880 (10)
    //         004a9486     MOV        EAX,dword ptr [EAX]
    //         004a9488     MOV        this,ESI
    //         004a948a     PUSH       EAX
    //         004a948b     CALL       TRIBE_Screen_Sed::SetupListOfTerrain             int SetupListOfTerrain(TRIBE_Screen_Sed * thi
    //                               LAB_004a9490                                                 XREF[1]:     004a9484(j)  
    //                              scr_sed.cpp:884 (14)
    //         004a9490     POP        EDI
    //         004a9491     POP        ESI
    //         004a9492     MOV        EAX,0x1
    //         004a9497     POP        EBX
    //         004a9498     ADD        ESP,0x70
    //         004a949b     RET        0xc
    //         004a949e     ??         90h
    //         004a949f     NOP
    return 0;
}

TRIBE_Screen_Sed::~TRIBE_Screen_Sed() {
    /* TODO: Stub */
    //                              void __thiscall ~TRIBE_Screen_Sed(TRIBE_Screen_Sed * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004a94d2(W)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004a94bc(W)  
    //                               ??1TRIBE_Screen_Sed@@UAE@XZ                                  XREF[1]:     `vector_deleting_destructor':004a8
    //                               TRIBE_Screen_Sed::~TRIBE_Screen_Sed
    //                              scr_sed.cpp:890 (40)
    //         004a94a0     PUSH       -0x1
    //         004a94a2     PUSH       FUN_0055f468
    //         004a94a7     MOV        EAX,FS:[0x0]
    //         004a94ad     PUSH       EAX
    //         004a94ae     MOV        dword ptr FS:[0x0],ESP
    //         004a94b5     PUSH       this
    //         004a94b6     PUSH       EBX
    //         004a94b7     PUSH       EBP
    //         004a94b8     PUSH       ESI
    //         004a94b9     MOV        ESI,this
    //         004a94bb     PUSH       EDI
    //         004a94bc     MOV        dword ptr [ESP + local_10],ESI
    //         004a94c0     MOV        dword ptr [ESI],TRIBE_Screen_Sed::`vftable'      = 004a8750
    //         004a94c6     XOR        EBP,EBP
    //                              scr_sed.cpp:895 (19)
    //         004a94c8     PUSH       s_QuitSaveDialog                                 = 51h    Q
    //         004a94cd     MOV        this,panel_system
    //         004a94d2     MOV        dword ptr [ESP + local_4],EBP
    //         004a94d6     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_sed.cpp:896 (15)
    //         004a94db     PUSH       s_OpenSaveDialog                                 = 4Fh    O
    //         004a94e0     MOV        this,panel_system
    //         004a94e5     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_sed.cpp:897 (15)
    //         004a94ea     PUSH       s_NewSaveDialog                                  = 4Eh    N
    //         004a94ef     MOV        this,panel_system
    //         004a94f4     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_sed.cpp:898 (15)
    //         004a94f9     PUSH       s_Save_Game_Screen                               = "Save Game Screen"
    //         004a94fe     MOV        this,panel_system
    //         004a9503     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_sed.cpp:899 (15)
    //         004a9508     PUSH       s_Scenario_Menu_Dialog                           = "Scenario Menu Dialog"
    //         004a950d     MOV        this,panel_system
    //         004a9512     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_sed.cpp:902 (25)
    //         004a9517     LEA        EAX,[ESI + 0x520]
    //         004a951d     MOV        this,ESI
    //         004a951f     PUSH       EAX
    //         004a9520     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9525     LEA        EDI,[ESI + 0x514]
    //         004a952b     MOV        EBX,0x3
    //                               LAB_004a9530                                                 XREF[1]:     004a9547(j)  
    //                              scr_sed.cpp:903 (3)
    //         004a9530     LEA        this,[EDI + -0xc]
    //                              scr_sed.cpp:905 (8)
    //         004a9533     PUSH       this
    //         004a9534     MOV        this,ESI
    //         004a9536     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_sed.cpp:906 (14)
    //         004a953b     PUSH       EDI
    //         004a953c     MOV        this,ESI
    //         004a953e     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9543     ADD        EDI,0x4
    //         004a9546     DEC        EBX
    //         004a9547     JNZ        LAB_004a9530
    //                              scr_sed.cpp:908 (14)
    //         004a9549     LEA        EDX,[ESI + 0x524]
    //         004a954f     MOV        this,ESI
    //         004a9551     PUSH       EDX
    //         004a9552     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_sed.cpp:909 (14)
    //         004a9557     LEA        EAX,[ESI + 0x528]
    //         004a955d     MOV        this,ESI
    //         004a955f     PUSH       EAX
    //         004a9560     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_sed.cpp:910 (14)
    //         004a9565     LEA        this,[ESI + 0x52c]
    //         004a956b     PUSH       this
    //         004a956c     MOV        this,ESI
    //         004a956e     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_sed.cpp:911 (14)
    //         004a9573     LEA        EDX,[ESI + 0x530]
    //         004a9579     MOV        this,ESI
    //         004a957b     PUSH       EDX
    //         004a957c     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_sed.cpp:912 (14)
    //         004a9581     LEA        EAX,[ESI + 0x538]
    //         004a9587     MOV        this,ESI
    //         004a9589     PUSH       EAX
    //         004a958a     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_sed.cpp:913 (14)
    //         004a958f     LEA        this,[ESI + 0x534]
    //         004a9595     PUSH       this
    //         004a9596     MOV        this,ESI
    //         004a9598     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_sed.cpp:914 (14)
    //         004a959d     LEA        EDX,[ESI + 0x550]
    //         004a95a3     MOV        this,ESI
    //         004a95a5     PUSH       EDX
    //         004a95a6     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_sed.cpp:915 (14)
    //         004a95ab     LEA        EAX,[ESI + 0x53c]
    //         004a95b1     MOV        this,ESI
    //         004a95b3     PUSH       EAX
    //         004a95b4     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_sed.cpp:916 (14)
    //         004a95b9     LEA        this,[ESI + 0x540]
    //         004a95bf     PUSH       this
    //         004a95c0     MOV        this,ESI
    //         004a95c2     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_sed.cpp:917 (14)
    //         004a95c7     LEA        EDX,[ESI + 0x544]
    //         004a95cd     MOV        this,ESI
    //         004a95cf     PUSH       EDX
    //         004a95d0     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_sed.cpp:918 (14)
    //         004a95d5     LEA        EAX,[ESI + 0x548]
    //         004a95db     MOV        this,ESI
    //         004a95dd     PUSH       EAX
    //         004a95de     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_sed.cpp:919 (14)
    //         004a95e3     LEA        this,[ESI + 0x54c]
    //         004a95e9     PUSH       this
    //         004a95ea     MOV        this,ESI
    //         004a95ec     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_sed.cpp:922 (14)
    //         004a95f1     LEA        EDX,[ESI + 0x554]
    //         004a95f7     MOV        this,ESI
    //         004a95f9     PUSH       EDX
    //         004a95fa     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_sed.cpp:1144 (1727)
    //         004a95ff     LEA        EDI,[ESI + 0x56c]
    //         004a9605     MOV        EBX,0x5
    //                               LAB_004a960a                                                 XREF[1]:     004a9621(j)  
    //         004a960a     LEA        EAX,[EDI + -0x14]
    //         004a960d     MOV        this,ESI
    //         004a960f     PUSH       EAX
    //         004a9610     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9615     PUSH       EDI
    //         004a9616     MOV        this,ESI
    //         004a9618     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a961d     ADD        EDI,0x4
    //         004a9620     DEC        EBX
    //         004a9621     JNZ        LAB_004a960a
    //         004a9623     LEA        this,[ESI + 0x580]
    //         004a9629     PUSH       this
    //         004a962a     MOV        this,ESI
    //         004a962c     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9631     LEA        EDI,[ESI + 0x590]
    //         004a9637     MOV        EBX,0x3
    //                               LAB_004a963c                                                 XREF[1]:     004a9653(j)  
    //         004a963c     LEA        EDX,[EDI + -0xc]
    //         004a963f     MOV        this,ESI
    //         004a9641     PUSH       EDX
    //         004a9642     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9647     PUSH       EDI
    //         004a9648     MOV        this,ESI
    //         004a964a     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a964f     ADD        EDI,0x4
    //         004a9652     DEC        EBX
    //         004a9653     JNZ        LAB_004a963c
    //         004a9655     LEA        EAX,[ESI + 0x59c]
    //         004a965b     MOV        this,ESI
    //         004a965d     PUSH       EAX
    //         004a965e     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9663     LEA        this,[ESI + 0x5a0]
    //         004a9669     PUSH       this
    //         004a966a     MOV        this,ESI
    //         004a966c     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9671     LEA        EDX,[ESI + 0x5a4]
    //         004a9677     MOV        this,ESI
    //         004a9679     PUSH       EDX
    //         004a967a     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a967f     LEA        EAX,[ESI + 0x5a8]
    //         004a9685     MOV        this,ESI
    //         004a9687     PUSH       EAX
    //         004a9688     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a968d     LEA        this,[ESI + 0x5ac]
    //         004a9693     PUSH       this
    //         004a9694     MOV        this,ESI
    //         004a9696     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a969b     LEA        EDX,[ESI + 0x5bc]
    //         004a96a1     MOV        this,ESI
    //         004a96a3     PUSH       EDX
    //         004a96a4     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a96a9     LEA        EAX,[ESI + 0x5b0]
    //         004a96af     MOV        this,ESI
    //         004a96b1     PUSH       EAX
    //         004a96b2     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a96b7     LEA        this,[ESI + 0x5f4]
    //         004a96bd     PUSH       this
    //         004a96be     MOV        this,ESI
    //         004a96c0     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a96c5     LEA        EDX,[ESI + 0x60c]
    //         004a96cb     MOV        this,ESI
    //         004a96cd     PUSH       EDX
    //         004a96ce     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a96d3     LEA        EAX,[ESI + 0x610]
    //         004a96d9     MOV        this,ESI
    //         004a96db     PUSH       EAX
    //         004a96dc     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a96e1     LEA        this,[ESI + 0x614]
    //         004a96e7     PUSH       this
    //         004a96e8     MOV        this,ESI
    //         004a96ea     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a96ef     LEA        EDX,[ESI + 0x5b4]
    //         004a96f5     MOV        this,ESI
    //         004a96f7     PUSH       EDX
    //         004a96f8     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a96fd     LEA        EAX,[ESI + 0x5b8]
    //         004a9703     MOV        this,ESI
    //         004a9705     PUSH       EAX
    //         004a9706     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a970b     LEA        EDI,[ESI + 0x5d8]
    //         004a9711     MOV        EBX,0x5
    //                               LAB_004a9716                                                 XREF[1]:     004a972d(j)  
    //         004a9716     LEA        this,[EDI + -0x14]
    //         004a9719     PUSH       this
    //         004a971a     MOV        this,ESI
    //         004a971c     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9721     PUSH       EDI
    //         004a9722     MOV        this,ESI
    //         004a9724     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9729     ADD        EDI,0x4
    //         004a972c     DEC        EBX
    //         004a972d     JNZ        LAB_004a9716
    //         004a972f     LEA        EDI,[ESI + 0x5f8]
    //         004a9735     MOV        EBX,0x2
    //                               LAB_004a973a                                                 XREF[1]:     004a9751(j)  
    //         004a973a     LEA        EDX,[EDI + -0xc]
    //         004a973d     MOV        this,ESI
    //         004a973f     PUSH       EDX
    //         004a9740     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9745     PUSH       EDI
    //         004a9746     MOV        this,ESI
    //         004a9748     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a974d     ADD        EDI,0x4
    //         004a9750     DEC        EBX
    //         004a9751     JNZ        LAB_004a973a
    //         004a9753     LEA        EAX,[ESI + 0x600]
    //         004a9759     MOV        this,ESI
    //         004a975b     PUSH       EAX
    //         004a975c     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9761     LEA        this,[ESI + 0x604]
    //         004a9767     PUSH       this
    //         004a9768     MOV        this,ESI
    //         004a976a     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a976f     LEA        EDX,[ESI + 0x608]
    //         004a9775     MOV        this,ESI
    //         004a9777     PUSH       EDX
    //         004a9778     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a977d     LEA        EAX,[ESI + 0x618]
    //         004a9783     MOV        this,ESI
    //         004a9785     PUSH       EAX
    //         004a9786     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a978b     LEA        EDI,[ESI + 0x62c]
    //         004a9791     MOV        EBX,0x4
    //                               LAB_004a9796                                                 XREF[1]:     004a97ad(j)  
    //         004a9796     LEA        this,[EDI + -0x10]
    //         004a9799     PUSH       this
    //         004a979a     MOV        this,ESI
    //         004a979c     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a97a1     PUSH       EDI
    //         004a97a2     MOV        this,ESI
    //         004a97a4     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a97a9     ADD        EDI,0x4
    //         004a97ac     DEC        EBX
    //         004a97ad     JNZ        LAB_004a9796
    //         004a97af     LEA        EDX,[ESI + 0x63c]
    //         004a97b5     MOV        this,ESI
    //         004a97b7     PUSH       EDX
    //         004a97b8     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a97bd     LEA        EAX,[ESI + 0x640]
    //         004a97c3     MOV        this,ESI
    //         004a97c5     PUSH       EAX
    //         004a97c6     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a97cb     MOV        EAX,dword ptr [ESI + 0x644]
    //         004a97d1     CMP        EAX,EBP
    //         004a97d3     JZ         LAB_004a97e4
    //         004a97d5     PUSH       EAX
    //         004a97d6     CALL       free                                             undefined free()
    //         004a97db     ADD        ESP,0x4
    //         004a97de     MOV        dword ptr [ESI + 0x644],EBP
    //                               LAB_004a97e4                                                 XREF[1]:     004a97d3(j)  
    //         004a97e4     MOV        this,dword ptr [ESI + 0x660]
    //         004a97ea     CMP        this,EBP
    //         004a97ec     JZ         LAB_004a97fa
    //         004a97ee     MOV        EDX,dword ptr [this->_padding_]
    //         004a97f0     PUSH       0x1
    //         004a97f2     CALL       dword ptr [EDX]
    //         004a97f4     MOV        dword ptr [ESI + 0x660],EBP
    //                               LAB_004a97fa                                                 XREF[1]:     004a97ec(j)  
    //         004a97fa     MOV        EDI,dword ptr [ESI + 0x648]
    //         004a9800     CMP        EDI,EBP
    //         004a9802     JZ         LAB_004a981a
    //         004a9804     MOV        this,EDI
    //         004a9806     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
    //         004a980b     PUSH       EDI
    //         004a980c     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004a9811     ADD        ESP,0x4
    //         004a9814     MOV        dword ptr [ESI + 0x648],EBP
    //                               LAB_004a981a                                                 XREF[1]:     004a9802(j)  
    //         004a981a     LEA        EBX,[ESI + 0x64c]
    //         004a9820     MOV        EBP,0x5
    //                               LAB_004a9825                                                 XREF[1]:     004a9845(j)  
    //         004a9825     MOV        EDI,dword ptr [EBX]
    //         004a9827     TEST       EDI,EDI
    //         004a9829     JZ         LAB_004a9841
    //         004a982b     MOV        this,EDI
    //         004a982d     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
    //         004a9832     PUSH       EDI
    //         004a9833     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004a9838     ADD        ESP,0x4
    //         004a983b     MOV        dword ptr [EBX],0x0
    //                               LAB_004a9841                                                 XREF[1]:     004a9829(j)  
    //         004a9841     ADD        EBX,0x4
    //         004a9844     DEC        EBP
    //         004a9845     JNZ        LAB_004a9825
    //         004a9847     LEA        EDI,[ESI + 0x668]
    //         004a984d     MOV        EBX,0x6
    //                               LAB_004a9852                                                 XREF[1]:     004a985e(j)  
    //         004a9852     PUSH       EDI
    //         004a9853     MOV        this,ESI
    //         004a9855     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a985a     ADD        EDI,0x4
    //         004a985d     DEC        EBX
    //         004a985e     JNZ        LAB_004a9852
    //         004a9860     LEA        EDI,[ESI + 0x694]
    //         004a9866     MOV        EBX,0x2
    //                               LAB_004a986b                                                 XREF[1]:     004a9882(j)  
    //         004a986b     LEA        EAX,[EDI + -0x14]
    //         004a986e     MOV        this,ESI
    //         004a9870     PUSH       EAX
    //         004a9871     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9876     PUSH       EDI
    //         004a9877     MOV        this,ESI
    //         004a9879     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a987e     ADD        EDI,0x4
    //         004a9881     DEC        EBX
    //         004a9882     JNZ        LAB_004a986b
    //         004a9884     LEA        this,[ESI + 0x68c]
    //         004a988a     PUSH       this
    //         004a988b     MOV        this,ESI
    //         004a988d     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9892     LEA        EDX,[ESI + 0x690]
    //         004a9898     MOV        this,ESI
    //         004a989a     PUSH       EDX
    //         004a989b     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a98a0     LEA        EAX,[ESI + 0x688]
    //         004a98a6     MOV        this,ESI
    //         004a98a8     PUSH       EAX
    //         004a98a9     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a98ae     LEA        this,[ESI + 0x69c]
    //         004a98b4     PUSH       this
    //         004a98b5     MOV        this,ESI
    //         004a98b7     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a98bc     LEA        EDX,[ESI + 0x6a0]
    //         004a98c2     MOV        this,ESI
    //         004a98c4     PUSH       EDX
    //         004a98c5     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a98ca     LEA        EAX,[ESI + 0x6a4]
    //         004a98d0     MOV        this,ESI
    //         004a98d2     PUSH       EAX
    //         004a98d3     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a98d8     LEA        this,[ESI + 0x6a8]
    //         004a98de     PUSH       this
    //         004a98df     MOV        this,ESI
    //         004a98e1     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a98e6     LEA        EDX,[ESI + 0x6ac]
    //         004a98ec     MOV        this,ESI
    //         004a98ee     PUSH       EDX
    //         004a98ef     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a98f4     LEA        EAX,[ESI + 0x6b0]
    //         004a98fa     MOV        this,ESI
    //         004a98fc     PUSH       EAX
    //         004a98fd     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9902     LEA        this,[ESI + 0x6b4]
    //         004a9908     PUSH       this
    //         004a9909     MOV        this,ESI
    //         004a990b     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9910     LEA        EDX,[ESI + 0x6b8]
    //         004a9916     MOV        this,ESI
    //         004a9918     PUSH       EDX
    //         004a9919     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a991e     LEA        EAX,[ESI + 0x6bc]
    //         004a9924     MOV        this,ESI
    //         004a9926     PUSH       EAX
    //         004a9927     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a992c     LEA        this,[ESI + 0x6c0]
    //         004a9932     PUSH       this
    //         004a9933     MOV        this,ESI
    //         004a9935     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a993a     LEA        EDX,[ESI + 0x6c4]
    //         004a9940     MOV        this,ESI
    //         004a9942     PUSH       EDX
    //         004a9943     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9948     LEA        EAX,[ESI + 0x6c8]
    //         004a994e     MOV        this,ESI
    //         004a9950     PUSH       EAX
    //         004a9951     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9956     LEA        EDI,[ESI + 0x6e0]
    //         004a995c     MOV        EBX,0x5
    //                               LAB_004a9961                                                 XREF[1]:     004a9978(j)  
    //         004a9961     LEA        this,[EDI + -0x14]
    //         004a9964     PUSH       this
    //         004a9965     MOV        this,ESI
    //         004a9967     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a996c     PUSH       EDI
    //         004a996d     MOV        this,ESI
    //         004a996f     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9974     ADD        EDI,0x4
    //         004a9977     DEC        EBX
    //         004a9978     JNZ        LAB_004a9961
    //         004a997a     LEA        EDX,[ESI + 0x6f4]
    //         004a9980     MOV        this,ESI
    //         004a9982     PUSH       EDX
    //         004a9983     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9988     LEA        EAX,[ESI + 0x6f8]
    //         004a998e     MOV        this,ESI
    //         004a9990     PUSH       EAX
    //         004a9991     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9996     LEA        this,[ESI + 0x6fc]
    //         004a999c     PUSH       this
    //         004a999d     MOV        this,ESI
    //         004a999f     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a99a4     LEA        EDX,[ESI + 0x700]
    //         004a99aa     MOV        this,ESI
    //         004a99ac     PUSH       EDX
    //         004a99ad     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a99b2     LEA        EDI,[ESI + 0x704]
    //         004a99b8     MOV        EBX,0xc
    //                               LAB_004a99bd                                                 XREF[1]:     004a99c9(j)  
    //         004a99bd     PUSH       EDI
    //         004a99be     MOV        this,ESI
    //         004a99c0     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a99c5     ADD        EDI,0x4
    //         004a99c8     DEC        EBX
    //         004a99c9     JNZ        LAB_004a99bd
    //         004a99cb     LEA        EAX,[ESI + 0x734]
    //         004a99d1     MOV        this,ESI
    //         004a99d3     PUSH       EAX
    //         004a99d4     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a99d9     LEA        this,[ESI + 0x738]
    //         004a99df     PUSH       this
    //         004a99e0     MOV        this,ESI
    //         004a99e2     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a99e7     LEA        EDX,[ESI + 0x73c]
    //         004a99ed     MOV        this,ESI
    //         004a99ef     PUSH       EDX
    //         004a99f0     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a99f5     LEA        EAX,[ESI + 0x748]
    //         004a99fb     MOV        this,ESI
    //         004a99fd     PUSH       EAX
    //         004a99fe     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9a03     LEA        this,[ESI + 0x74c]
    //         004a9a09     PUSH       this
    //         004a9a0a     MOV        this,ESI
    //         004a9a0c     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9a11     LEA        EDX,[ESI + 0x750]
    //         004a9a17     MOV        this,ESI
    //         004a9a19     PUSH       EDX
    //         004a9a1a     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9a1f     LEA        EAX,[ESI + 0x754]
    //         004a9a25     MOV        this,ESI
    //         004a9a27     PUSH       EAX
    //         004a9a28     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9a2d     LEA        this,[ESI + 0x758]
    //         004a9a33     PUSH       this
    //         004a9a34     MOV        this,ESI
    //         004a9a36     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9a3b     LEA        EDX,[ESI + 0x75c]
    //         004a9a41     MOV        this,ESI
    //         004a9a43     PUSH       EDX
    //         004a9a44     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9a49     LEA        EAX,[ESI + 0x760]
    //         004a9a4f     MOV        this,ESI
    //         004a9a51     PUSH       EAX
    //         004a9a52     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9a57     LEA        this,[ESI + 0x764]
    //         004a9a5d     PUSH       this
    //         004a9a5e     MOV        this,ESI
    //         004a9a60     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9a65     LEA        EDX,[ESI + 0x76c]
    //         004a9a6b     MOV        this,ESI
    //         004a9a6d     PUSH       EDX
    //         004a9a6e     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9a73     LEA        EAX,[ESI + 0x740]
    //         004a9a79     MOV        this,ESI
    //         004a9a7b     PUSH       EAX
    //         004a9a7c     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9a81     LEA        this,[ESI + 0x744]
    //         004a9a87     PUSH       this
    //         004a9a88     MOV        this,ESI
    //         004a9a8a     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9a8f     LEA        EDX,[ESI + 0x768]
    //         004a9a95     MOV        this,ESI
    //         004a9a97     PUSH       EDX
    //         004a9a98     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9a9d     LEA        EAX,[ESI + 0x770]
    //         004a9aa3     MOV        this,ESI
    //         004a9aa5     PUSH       EAX
    //         004a9aa6     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9aab     LEA        EDI,[ESI + 0x78c]
    //         004a9ab1     MOV        EBX,0x5
    //                               LAB_004a9ab6                                                 XREF[1]:     004a9acd(j)  
    //         004a9ab6     LEA        this,[EDI + -0x14]
    //         004a9ab9     PUSH       this
    //         004a9aba     MOV        this,ESI
    //         004a9abc     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9ac1     PUSH       EDI
    //         004a9ac2     MOV        this,ESI
    //         004a9ac4     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9ac9     ADD        EDI,0x4
    //         004a9acc     DEC        EBX
    //         004a9acd     JNZ        LAB_004a9ab6
    //         004a9acf     LEA        EDX,[ESI + 0x774]
    //         004a9ad5     MOV        this,ESI
    //         004a9ad7     PUSH       EDX
    //         004a9ad8     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9add     LEA        EDI,[ESI + 0x7b4]
    //         004a9ae3     MOV        EBX,0x4
    //                               LAB_004a9ae8                                                 XREF[1]:     004a9aff(j)  
    //         004a9ae8     LEA        EAX,[EDI + -0x10]
    //         004a9aeb     MOV        this,ESI
    //         004a9aed     PUSH       EAX
    //         004a9aee     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9af3     PUSH       EDI
    //         004a9af4     MOV        this,ESI
    //         004a9af6     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9afb     ADD        EDI,0x4
    //         004a9afe     DEC        EBX
    //         004a9aff     JNZ        LAB_004a9ae8
    //         004a9b01     LEA        EDI,[ESI + 0x7c8]
    //         004a9b07     MOV        EBX,0x1
    //                               LAB_004a9b0c                                                 XREF[1]:     004a9b23(j)  
    //         004a9b0c     LEA        this,[EDI + -0x4]
    //         004a9b0f     PUSH       this
    //         004a9b10     MOV        this,ESI
    //         004a9b12     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9b17     PUSH       EDI
    //         004a9b18     MOV        this,ESI
    //         004a9b1a     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9b1f     ADD        EDI,0x4
    //         004a9b22     DEC        EBX
    //         004a9b23     JNZ        LAB_004a9b0c
    //         004a9b25     LEA        EDX,[ESI + 0x7cc]
    //         004a9b2b     MOV        this,ESI
    //         004a9b2d     PUSH       EDX
    //         004a9b2e     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9b33     LEA        EAX,[ESI + 0x7d0]
    //         004a9b39     MOV        this,ESI
    //         004a9b3b     PUSH       EAX
    //         004a9b3c     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9b41     LEA        EDI,[ESI + 0x814]
    //         004a9b47     MOV        EBX,0x10
    //                               LAB_004a9b4c                                                 XREF[1]:     004a9b63(j)  
    //         004a9b4c     LEA        this,[EDI + -0x40]
    //         004a9b4f     PUSH       this
    //         004a9b50     MOV        this,ESI
    //         004a9b52     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9b57     PUSH       EDI
    //         004a9b58     MOV        this,ESI
    //         004a9b5a     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9b5f     ADD        EDI,0x4
    //         004a9b62     DEC        EBX
    //         004a9b63     JNZ        LAB_004a9b4c
    //         004a9b65     LEA        EBX,[ESI + 0x908]
    //         004a9b6b     LEA        EDI,[ESI + 0x8ac]
    //         004a9b71     MOV        EBP,0x8
    //                               LAB_004a9b76                                                 XREF[1]:     004a9bbf(j)  
    //         004a9b76     LEA        EAX,[ESI + 0x894]
    //         004a9b7c     MOV        this,ESI
    //         004a9b7e     PUSH       EAX
    //         004a9b7f     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9b84     LEA        EDX,[EBX + 0xffffff6c]
    //         004a9b8a     MOV        this,ESI
    //         004a9b8c     PUSH       EDX
    //         004a9b8d     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9b92     LEA        EAX,[EDI + -0x4]
    //         004a9b95     MOV        this,ESI
    //         004a9b97     PUSH       EAX
    //         004a9b98     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9b9d     PUSH       EDI
    //         004a9b9e     MOV        this,ESI
    //         004a9ba0     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9ba5     LEA        this,[EDI + 0x4]
    //         004a9ba8     PUSH       this
    //         004a9ba9     MOV        this,ESI
    //         004a9bab     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9bb0     PUSH       EBX
    //         004a9bb1     MOV        this,ESI
    //         004a9bb3     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9bb8     ADD        EBX,0x4
    //         004a9bbb     ADD        EDI,0xc
    //         004a9bbe     DEC        EBP
    //         004a9bbf     JNZ        LAB_004a9b76
    //         004a9bc1     LEA        EDX,[ESI + 0x898]
    //         004a9bc7     MOV        this,ESI
    //         004a9bc9     PUSH       EDX
    //         004a9bca     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9bcf     LEA        EAX,[ESI + 0x89c]
    //         004a9bd5     MOV        this,ESI
    //         004a9bd7     PUSH       EAX
    //         004a9bd8     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9bdd     LEA        this,[ESI + 0x8a0]
    //         004a9be3     PUSH       this
    //         004a9be4     MOV        this,ESI
    //         004a9be6     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9beb     LEA        EDX,[ESI + 0x8a4]
    //         004a9bf1     MOV        this,ESI
    //         004a9bf3     PUSH       EDX
    //         004a9bf4     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9bf9     LEA        EAX,[ESI + 0x500]
    //         004a9bff     MOV        this,ESI
    //         004a9c01     PUSH       EAX
    //         004a9c02     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9c07     LEA        this,[ESI + 0x504]
    //         004a9c0d     PUSH       this
    //         004a9c0e     MOV        this,ESI
    //         004a9c10     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9c15     LEA        EDI,[ESI + 0x4d8]
    //         004a9c1b     MOV        EBX,0xa
    //                               LAB_004a9c20                                                 XREF[1]:     004a9c2c(j)  
    //         004a9c20     PUSH       EDI
    //         004a9c21     MOV        this,ESI
    //         004a9c23     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9c28     ADD        EDI,0x4
    //         004a9c2b     DEC        EBX
    //         004a9c2c     JNZ        LAB_004a9c20
    //         004a9c2e     LEA        EDX,[ESI + 0x4d4]
    //         004a9c34     MOV        this,ESI
    //         004a9c36     PUSH       EDX
    //         004a9c37     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9c3c     LEA        EAX,[ESI + 0x4d0]
    //         004a9c42     MOV        this,ESI
    //         004a9c44     PUSH       EAX
    //         004a9c45     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9c4a     LEA        this,[ESI + 0x4c8]
    //         004a9c50     PUSH       this
    //         004a9c51     MOV        this,ESI
    //         004a9c53     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9c58     LEA        EDX,[ESI + 0x4cc]
    //         004a9c5e     MOV        this,ESI
    //         004a9c60     PUSH       EDX
    //         004a9c61     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a9c66     MOV        EDI,dword ptr [ESI + 0x4c4]
    //         004a9c6c     TEST       EDI,EDI
    //         004a9c6e     JZ         LAB_004a9c8a
    //         004a9c70     MOV        this,EDI
    //         004a9c72     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
    //         004a9c77     PUSH       EDI
    //         004a9c78     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004a9c7d     ADD        ESP,0x4
    //         004a9c80     MOV        dword ptr [ESI + 0x4c4],0x0
    //                               LAB_004a9c8a                                                 XREF[1]:     004a9c6e(j)  
    //         004a9c8a     MOV        this,dword ptr [ESI + 0x928]
    //         004a9c90     TEST       this,this
    //         004a9c92     JZ         LAB_004a9c9c
    //         004a9c94     MOV        EAX,dword ptr [this->_padding_]
    //         004a9c96     CALL       dword ptr [EAX + 0xb8]
    //                               LAB_004a9c9c                                                 XREF[1]:     004a9c92(j)  
    //         004a9c9c     MOV        this,ESI
    //         004a9c9e     MOV        dword ptr [ESP + 0x1c],0xffffffff
    //         004a9ca6     CALL       TScreenPanel::~TScreenPanel                      void ~TScreenPanel(TScreenPanel * this)
    //         004a9cab     MOV        this,dword ptr [ESP + 0x14]
    //         004a9caf     POP        EDI
    //         004a9cb0     POP        ESI
    //         004a9cb1     POP        EBP
    //         004a9cb2     MOV        dword ptr FS:[0x0],this
    //         004a9cb9     POP        EBX
    //         004a9cba     ADD        ESP,0x10
    //         004a9cbd     RET
    //         004a9cbe     ??         90h
    //         004a9cbf     NOP
}

void TRIBE_Screen_Sed::set_scenario_mode(ScenarioMode param_1) {
    /* TODO: Stub */
    //                              void __thiscall set_scenario_mode(TRIBE_Screen_Sed * this, ScenarioM
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              ScenarioMode      Stack[0x4]:4   param_1
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004a9ce8(W), 004a9d00(R)  
    //              ScenarioMode      Stack[-0x8]:4  mode                      XREF[2]:     004a9cc9(W), 004a9cd8(R)  
    //              int               Stack[-0xc]:4  activate_counter          XREF[1]:     004aa31d(W)  
    //              int               Stack[-0x10]:4 i
    //                               ?set_scenario_mode@TRIBE_Screen_Sed@@QAEXW4ScenarioMode@1@@Z XREF[16]:    TRIBE_Screen_Sed:004a86ef(c), 
    //                               TRIBE_Screen_Sed::set_scenario_mode                                       key_down_action:004ab851(c), 
    //                                                                                                         key_down_action:004ab872(c), 
    //                                                                                                         key_down_action:004ab893(c), 
    //                                                                                                         key_down_action:004ab8b4(c), 
    //                                                                                                         key_down_action:004ab8d5(c), 
    //                                                                                                         key_down_action:004ab8f6(c), 
    //                                                                                                         key_down_action:004ab917(c), 
    //                                                                                                         key_down_action:004ab938(c), 
    //                                                                                                         key_down_action:004ab959(c), 
    //                                                                                                         key_down_action:004ab97a(c), 
    //                                                                                                         action:004abf60(c), 
    //                                                                                                         action:004ad064(c), 
    //                                                                                                         command_save:004ad722(c), 
    //                                                                                                         command_save_as:004ad980(c), 
    //                                                                                                         scenario_save_defaulted:004adb15(c
    //                              scr_sed.cpp:1150 (9)
    //         004a9cc0     SUB        ESP,0xc
    //         004a9cc3     PUSH       EBX
    //         004a9cc4     PUSH       EBP
    //         004a9cc5     PUSH       ESI
    //         004a9cc6     MOV        ESI,this
    //         004a9cc8     PUSH       EDI
    //                              scr_sed.cpp:1161 (15)
    //         004a9cc9     MOV        dword ptr [ESP + mode],0x0
    //         004a9cd1     MOV        byte ptr [ESI + 0x4c1],0x0
    //                               LAB_004a9cd8                                                 XREF[1]:     004aa69a(j)  
    //                              scr_sed.cpp:1163 (8)
    //         004a9cd8     MOV        EAX,dword ptr [ESP + mode]
    //         004a9cdc     TEST       EAX,EAX
    //         004a9cde     JNZ        LAB_004a9cee
    //                              scr_sed.cpp:1165 (6)
    //         004a9ce0     MOV        EAX,dword ptr [ESI + 0x4a4]
    //                              scr_sed.cpp:1166 (6)
    //         004a9ce6     XOR        EDI,EDI
    //         004a9ce8     MOV        dword ptr [ESP + local_4],EAX
    //                              scr_sed.cpp:1168 (2)
    //         004a9cec     JMP        LAB_004a9d00
    //                               LAB_004a9cee                                                 XREF[1]:     004a9cde(j)  
    //                              scr_sed.cpp:1171 (9)
    //         004a9cee     MOV        EAX,dword ptr [ESP + 0x20]
    //         004a9cf2     CMP        EAX,0xb
    //         004a9cf5     JZ         LAB_004a9cfb
    //                              scr_sed.cpp:1172 (4)
    //         004a9cf7     MOV        dword ptr [ESP + 0x18],EAX
    //                               LAB_004a9cfb                                                 XREF[1]:     004a9cf5(j)  
    //                              scr_sed.cpp:1173 (5)
    //         004a9cfb     MOV        EDI,0x1
    //                               LAB_004a9d00                                                 XREF[1]:     004a9cec(j)  
    //                              scr_sed.cpp:1176 (23)
    //         004a9d00     MOV        this,dword ptr [ESP + local_4]
    //         004a9d04     LEA        EAX,[this->_padding_ + -0x1]
    //         004a9d07     CMP        EAX,0x9
    //         004a9d0a     JA         switchD_004a9d10::default
    //                               switchD_004a9d10::switchD
    //         004a9d10     JMP        dword ptr [EAX*0x4 + switchD_004a9d10::switchd   = 004a9d17
    //                               switchD_004a9d10::caseD_1                                    XREF[2]:     004a9d10(j), 004aa6e8(*)  
    //                              scr_sed.cpp:1179 (12)
    //         004a9d17     MOV        this,dword ptr [ESI + 0x520]
    //         004a9d1d     PUSH       EDI
    //         004a9d1e     MOV        EDX,dword ptr [this->_padding_]
    //         004a9d20     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1535 (71)
    //         004a9d23     LEA        EBX,[ESI + 0x514]
    //         004a9d29     MOV        EBP,0x3
    //                               LAB_004a9d2e                                                 XREF[1]:     004a9d43(j)  
    //         004a9d2e     MOV        this,dword ptr [EBX + -0xc]
    //         004a9d31     PUSH       EDI
    //         004a9d32     MOV        EAX,dword ptr [this->_padding_]
    //         004a9d34     CALL       dword ptr [EAX + 0x14]
    //         004a9d37     MOV        this,dword ptr [EBX]
    //         004a9d39     PUSH       EDI
    //         004a9d3a     MOV        EDX,dword ptr [this->_padding_]
    //         004a9d3c     CALL       dword ptr [EDX + 0x14]
    //         004a9d3f     ADD        EBX,0x4
    //         004a9d42     DEC        EBP
    //         004a9d43     JNZ        LAB_004a9d2e
    //         004a9d45     MOV        this,dword ptr [ESI + 0x54c]
    //         004a9d4b     PUSH       EDI
    //         004a9d4c     MOV        EAX,dword ptr [this->_padding_]
    //         004a9d4e     CALL       dword ptr [EAX + 0x14]
    //         004a9d51     TEST       EDI,EDI
    //         004a9d53     JZ         LAB_004a9d6a
    //         004a9d55     MOV        this,dword ptr [ESI + 0x4a8]
    //         004a9d5b     PUSH       0x1
    //         004a9d5d     PUSH       this=>DAT_fffffff8
    //         004a9d5e     MOV        this,ESI
    //         004a9d60     CALL       TRIBE_Screen_Sed::set_map_type                   void set_map_type(TRIBE_Screen_Sed * this, Ma
    //         004a9d65     JMP        switchD_004a9d10::default
    //                               LAB_004a9d6a                                                 XREF[1]:     004a9d53(j)  
    //                              scr_sed.cpp:1189 (11)
    //         004a9d6a     PUSH       0x0
    //         004a9d6c     PUSH       0x0=>DAT_fffffff8
    //         004a9d6e     MOV        this,ESI
    //         004a9d70     CALL       TRIBE_Screen_Sed::set_map_type                   void set_map_type(TRIBE_Screen_Sed * this, Ma
    //                              scr_sed.cpp:1190 (5)
    //         004a9d75     JMP        switchD_004a9d10::default
    //                               switchD_004a9d10::caseD_2                                    XREF[2]:     004a9d10(j), 004aa6ec(*)  
    //                              scr_sed.cpp:1193 (12)
    //         004a9d7a     MOV        this,dword ptr [ESI + 0x554]
    //         004a9d80     PUSH       EDI
    //         004a9d81     MOV        EDX,dword ptr [this->_padding_]
    //         004a9d83     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1194 (12)
    //         004a9d86     MOV        this,dword ptr [ESI + 0x580]
    //         004a9d8c     PUSH       EDI
    //         004a9d8d     MOV        EAX,dword ptr [this->_padding_]
    //         004a9d8f     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1195 (12)
    //         004a9d92     MOV        this,dword ptr [ESI + 0x59c]
    //         004a9d98     PUSH       EDI
    //         004a9d99     MOV        EDX,dword ptr [this->_padding_]
    //         004a9d9b     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1535 (68)
    //         004a9d9e     LEA        EBX,[ESI + 0x56c]
    //         004a9da4     MOV        EBP,0x5
    //                               LAB_004a9da9                                                 XREF[1]:     004a9dbe(j)  
    //         004a9da9     MOV        this,dword ptr [EBX + -0x14]
    //         004a9dac     PUSH       EDI
    //         004a9dad     MOV        EAX,dword ptr [this->_padding_]
    //         004a9daf     CALL       dword ptr [EAX + 0x14]
    //         004a9db2     MOV        this,dword ptr [EBX]
    //         004a9db4     PUSH       EDI
    //         004a9db5     MOV        EDX,dword ptr [this->_padding_]
    //         004a9db7     CALL       dword ptr [EDX + 0x14]
    //         004a9dba     ADD        EBX,0x4
    //         004a9dbd     DEC        EBP
    //         004a9dbe     JNZ        LAB_004a9da9
    //         004a9dc0     LEA        EBX,[ESI + 0x590]
    //         004a9dc6     MOV        EBP,0x3
    //                               LAB_004a9dcb                                                 XREF[1]:     004a9de0(j)  
    //         004a9dcb     MOV        this,dword ptr [EBX + -0xc]
    //         004a9dce     PUSH       EDI
    //         004a9dcf     MOV        EAX,dword ptr [this->_padding_]
    //         004a9dd1     CALL       dword ptr [EAX + 0x14]
    //         004a9dd4     MOV        this,dword ptr [EBX]
    //         004a9dd6     PUSH       EDI
    //         004a9dd7     MOV        EDX,dword ptr [this->_padding_]
    //         004a9dd9     CALL       dword ptr [EDX + 0x14]
    //         004a9ddc     ADD        EBX,0x4
    //         004a9ddf     DEC        EBP
    //         004a9de0     JNZ        LAB_004a9dcb
    //                              scr_sed.cpp:1207 (4)
    //         004a9de2     TEST       EDI,EDI
    //         004a9de4     JZ         LAB_004a9e09
    //                              scr_sed.cpp:1209 (14)
    //         004a9de6     MOV        EAX,dword ptr [ESI + 0x4b0]
    //         004a9dec     MOV        this,ESI
    //         004a9dee     PUSH       EAX
    //         004a9def     CALL       TRIBE_Screen_Sed::set_brush_size                 void set_brush_size(TRIBE_Screen_Sed * this, 
    //                              scr_sed.cpp:1210 (16)
    //         004a9df4     MOV        this,dword ptr [ESI + 0x4b4]
    //         004a9dfa     PUSH       0x1
    //         004a9dfc     PUSH       this=>DAT_fffffff8
    //         004a9dfd     MOV        this,ESI
    //         004a9dff     CALL       TRIBE_Screen_Sed::set_paint_type                 void set_paint_type(TRIBE_Screen_Sed * this, 
    //                              scr_sed.cpp:1212 (5)
    //         004a9e04     JMP        switchD_004a9d10::default
    //                               LAB_004a9e09                                                 XREF[1]:     004a9de4(j)  
    //                              scr_sed.cpp:1214 (9)
    //         004a9e09     PUSH       0x0
    //         004a9e0b     MOV        this,ESI
    //         004a9e0d     CALL       TRIBE_Screen_Sed::set_brush_size                 void set_brush_size(TRIBE_Screen_Sed * this, 
    //                              scr_sed.cpp:1215 (11)
    //         004a9e12     PUSH       0x0
    //         004a9e14     PUSH       0x0=>DAT_fffffff8
    //         004a9e16     MOV        this,ESI
    //         004a9e18     CALL       TRIBE_Screen_Sed::set_paint_type                 void set_paint_type(TRIBE_Screen_Sed * this, 
    //                              scr_sed.cpp:1217 (5)
    //         004a9e1d     JMP        switchD_004a9d10::default
    //                               switchD_004a9d10::caseD_3                                    XREF[2]:     004a9d10(j), 004aa6f0(*)  
    //                              scr_sed.cpp:1220 (12)
    //         004a9e22     MOV        this,dword ptr [ESI + 0x5b4]
    //         004a9e28     PUSH       EDI
    //         004a9e29     MOV        EDX,dword ptr [this->_padding_]
    //         004a9e2b     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1221 (12)
    //         004a9e2e     MOV        this,dword ptr [ESI + 0x5b8]
    //         004a9e34     PUSH       EDI
    //         004a9e35     MOV        EAX,dword ptr [this->_padding_]
    //         004a9e37     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1535 (68)
    //         004a9e3a     LEA        EBX,[ESI + 0x5d8]
    //         004a9e40     MOV        EBP,0x5
    //                               LAB_004a9e45                                                 XREF[1]:     004a9e5a(j)  
    //         004a9e45     MOV        this,dword ptr [EBX + -0x14]
    //         004a9e48     PUSH       EDI
    //         004a9e49     MOV        EDX,dword ptr [this->_padding_]
    //         004a9e4b     CALL       dword ptr [EDX + 0x14]
    //         004a9e4e     MOV        this,dword ptr [EBX]
    //         004a9e50     PUSH       EDI
    //         004a9e51     MOV        EAX,dword ptr [this->_padding_]
    //         004a9e53     CALL       dword ptr [EAX + 0x14]
    //         004a9e56     ADD        EBX,0x4
    //         004a9e59     DEC        EBP
    //         004a9e5a     JNZ        LAB_004a9e45
    //         004a9e5c     LEA        EBX,[ESI + 0x5f8]
    //         004a9e62     MOV        EBP,0x2
    //                               LAB_004a9e67                                                 XREF[1]:     004a9e7c(j)  
    //         004a9e67     MOV        this,dword ptr [EBX + -0xc]
    //         004a9e6a     PUSH       EDI
    //         004a9e6b     MOV        EDX,dword ptr [this->_padding_]
    //         004a9e6d     CALL       dword ptr [EDX + 0x14]
    //         004a9e70     MOV        this,dword ptr [EBX]
    //         004a9e72     PUSH       EDI
    //         004a9e73     MOV        EAX,dword ptr [this->_padding_]
    //         004a9e75     CALL       dword ptr [EAX + 0x14]
    //         004a9e78     ADD        EBX,0x4
    //         004a9e7b     DEC        EBP
    //         004a9e7c     JNZ        LAB_004a9e67
    //                              scr_sed.cpp:1235 (4)
    //         004a9e7e     TEST       EDI,EDI
    //         004a9e80     JZ         LAB_004a9ed4
    //                              scr_sed.cpp:1237 (23)
    //         004a9e82     MOVSX      this,word ptr [ESI + 0x4b8]
    //         004a9e89     MOV        EDX,dword ptr [ESI + 0x928]
    //         004a9e8f     DEC        this
    //         004a9e90     PUSH       this
    //         004a9e91     MOV        this,dword ptr [EDX + 0x5c]
    //         004a9e94     CALL       T_Scenario::GetPlayerAge                         int GetPlayerAge(T_Scenario * this, int param
    //                              scr_sed.cpp:1238 (12)
    //         004a9e99     MOV        this,dword ptr [ESI + 0x5bc]
    //         004a9e9f     PUSH       EAX
    //         004a9ea0     CALL       TDropDownPanel::setCurrentLineNumber             void setCurrentLineNumber(TDropDownPanel * th
    //                              scr_sed.cpp:1239 (19)
    //         004a9ea5     MOV        AX,word ptr [ESI + 0x4b8]
    //         004a9eac     PUSH       0x1
    //         004a9eae     PUSH       0x0=>DAT_fffffff8
    //         004a9eb0     PUSH       EAX=>DAT_fffffff4
    //         004a9eb1     MOV        this,ESI
    //         004a9eb3     CALL       TRIBE_Screen_Sed::set_player                     void set_player(TRIBE_Screen_Sed * this, shor
    //                              scr_sed.cpp:1241 (13)
    //         004a9eb8     MOV        this,dword ptr [ESI + 0x4d4]
    //         004a9ebe     PUSH       0x0
    //         004a9ec0     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              scr_sed.cpp:1242 (13)
    //         004a9ec5     MOV        this,dword ptr [ESI + 0x4cc]
    //         004a9ecb     PUSH       0x0
    //         004a9ecd     MOV        EDX,dword ptr [this->_padding_]
    //         004a9ecf     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1244 (2)
    //         004a9ed2     JMP        LAB_004a9efb
    //                               LAB_004a9ed4                                                 XREF[1]:     004a9e80(j)  
    //                              scr_sed.cpp:1246 (19)
    //         004a9ed4     MOV        AX,word ptr [ESI + 0x4b8]
    //         004a9edb     PUSH       0x0
    //         004a9edd     PUSH       offset DAT_fffffff8
    //         004a9edf     PUSH       EAX=>DAT_fffffff4
    //         004a9ee0     MOV        this,ESI
    //         004a9ee2     CALL       TRIBE_Screen_Sed::set_player                     void set_player(TRIBE_Screen_Sed * this, shor
    //                              scr_sed.cpp:1247 (13)
    //         004a9ee7     MOV        this,dword ptr [ESI + 0x4cc]
    //         004a9eed     PUSH       0x1
    //         004a9eef     MOV        EDX,dword ptr [this->_padding_]
    //         004a9ef1     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1248 (7)
    //         004a9ef4     MOV        this,ESI
    //         004a9ef6     CALL       TRIBE_Screen_Sed::SavePlayerActiveStatus         void SavePlayerActiveStatus(TRIBE_Screen_Sed 
    //                               LAB_004a9efb                                                 XREF[1]:     004a9ed2(j)  
    //                              scr_sed.cpp:1251 (12)
    //         004a9efb     MOV        this,dword ptr [ESI + 0x5bc]
    //         004a9f01     PUSH       EDI
    //         004a9f02     MOV        EAX,dword ptr [this->_padding_]
    //         004a9f04     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1252 (12)
    //         004a9f07     MOV        this,dword ptr [ESI + 0x5b0]
    //         004a9f0d     PUSH       EDI
    //         004a9f0e     MOV        EDX,dword ptr [this->_padding_]
    //         004a9f10     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1253 (12)
    //         004a9f13     MOV        this,dword ptr [ESI + 0x5f4]
    //         004a9f19     PUSH       EDI
    //         004a9f1a     MOV        EAX,dword ptr [this->_padding_]
    //         004a9f1c     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1256 (12)
    //         004a9f1f     MOV        this,dword ptr [ESI + 0x60c]
    //         004a9f25     PUSH       EDI
    //         004a9f26     MOV        EDX,dword ptr [this->_padding_]
    //         004a9f28     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1257 (12)
    //         004a9f2b     MOV        this,dword ptr [ESI + 0x610]
    //         004a9f31     PUSH       EDI
    //         004a9f32     MOV        EAX,dword ptr [this->_padding_]
    //         004a9f34     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1258 (12)
    //         004a9f37     MOV        this,dword ptr [ESI + 0x614]
    //         004a9f3d     PUSH       EDI
    //         004a9f3e     MOV        EDX,dword ptr [this->_padding_]
    //         004a9f40     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1259 (12)
    //         004a9f43     MOV        this,dword ptr [ESI + 0x600]
    //         004a9f49     PUSH       EDI
    //         004a9f4a     MOV        EAX,dword ptr [this->_padding_]
    //         004a9f4c     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1260 (12)
    //         004a9f4f     MOV        this,dword ptr [ESI + 0x604]
    //         004a9f55     PUSH       EDI
    //         004a9f56     MOV        EDX,dword ptr [this->_padding_]
    //         004a9f58     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1261 (12)
    //         004a9f5b     MOV        this,dword ptr [ESI + 0x608]
    //         004a9f61     PUSH       EDI
    //         004a9f62     MOV        EAX,dword ptr [this->_padding_]
    //         004a9f64     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1264 (5)
    //         004a9f67     JMP        switchD_004a9d10::default
    //                               switchD_004a9d10::caseD_4                                    XREF[2]:     004a9d10(j), 004aa6f4(*)  
    //                              scr_sed.cpp:1268 (12)
    //         004a9f6c     MOV        this,dword ptr [ESI + 0x618]
    //         004a9f72     PUSH       EDI
    //         004a9f73     MOV        EDX,dword ptr [this->_padding_]
    //         004a9f75     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1269 (12)
    //         004a9f78     MOV        this,dword ptr [ESI + 0x63c]
    //         004a9f7e     PUSH       EDI
    //         004a9f7f     MOV        EAX,dword ptr [this->_padding_]
    //         004a9f81     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1270 (12)
    //         004a9f84     MOV        this,dword ptr [ESI + 0x660]
    //         004a9f8a     PUSH       EDI
    //         004a9f8b     MOV        EDX,dword ptr [this->_padding_]
    //         004a9f8d     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1271 (12)
    //         004a9f90     MOV        this,dword ptr [ESI + 0x61c]
    //         004a9f96     PUSH       EDI
    //         004a9f97     MOV        EAX,dword ptr [this->_padding_]
    //         004a9f99     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1272 (12)
    //         004a9f9c     MOV        this,dword ptr [ESI + 0x620]
    //         004a9fa2     PUSH       EDI
    //         004a9fa3     MOV        EDX,dword ptr [this->_padding_]
    //         004a9fa5     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1273 (12)
    //         004a9fa8     MOV        this,dword ptr [ESI + 0x624]
    //         004a9fae     PUSH       EDI
    //         004a9faf     MOV        EAX,dword ptr [this->_padding_]
    //         004a9fb1     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1274 (12)
    //         004a9fb4     MOV        this,dword ptr [ESI + 0x628]
    //         004a9fba     PUSH       EDI
    //         004a9fbb     MOV        EDX,dword ptr [this->_padding_]
    //         004a9fbd     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1275 (4)
    //         004a9fc0     TEST       EDI,EDI
    //         004a9fc2     JZ         LAB_004a9fcf
    //                              scr_sed.cpp:1276 (11)
    //         004a9fc4     MOV        this,dword ptr [ESI + 0x61c]
    //         004a9fca     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
    //                               LAB_004a9fcf                                                 XREF[1]:     004a9fc2(j)  
    //                              scr_sed.cpp:1277 (12)
    //         004a9fcf     MOV        this,dword ptr [ESI + 0x62c]
    //         004a9fd5     PUSH       EDI
    //         004a9fd6     MOV        EAX,dword ptr [this->_padding_]
    //         004a9fd8     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1278 (12)
    //         004a9fdb     MOV        this,dword ptr [ESI + 0x630]
    //         004a9fe1     PUSH       EDI
    //         004a9fe2     MOV        EDX,dword ptr [this->_padding_]
    //         004a9fe4     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1279 (12)
    //         004a9fe7     MOV        this,dword ptr [ESI + 0x634]
    //         004a9fed     PUSH       EDI
    //         004a9fee     MOV        EAX,dword ptr [this->_padding_]
    //         004a9ff0     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1280 (12)
    //         004a9ff3     MOV        this,dword ptr [ESI + 0x638]
    //         004a9ff9     PUSH       EDI
    //         004a9ffa     MOV        EDX,dword ptr [this->_padding_]
    //         004a9ffc     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1284 (23)
    //         004a9fff     MOV        AX,word ptr [ESI + 0x4b8]
    //         004aa006     TEST       EDI,EDI
    //         004aa008     JZ         LAB_004aa0ca
    //         004aa00e     PUSH       EAX
    //         004aa00f     MOV        this,ESI
    //         004aa011     CALL       TRIBE_Screen_Sed::set_unit_player                void set_unit_player(TRIBE_Screen_Sed * this,
    //                              scr_sed.cpp:1285 (19)
    //         004aa016     MOV        this,dword ptr [ESI + 0x63c]
    //         004aa01c     CALL       TTextPanel::currentLineNumber                    int currentLineNumber(TTextPanel * this)
    //         004aa021     PUSH       EAX
    //         004aa022     MOV        this,ESI
    //         004aa024     CALL       TRIBE_Screen_Sed::set_unit                       void set_unit(TRIBE_Screen_Sed * this, short 
    //                              scr_sed.cpp:1286 (18)
    //         004aa029     MOV        this,dword ptr [ESI + 0x63c]
    //         004aa02f     PUSH       this
    //         004aa030     MOV        this,dword ptr [ESI + 0x4d4]
    //         004aa036     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              scr_sed.cpp:1287 (7)
    //         004aa03b     MOV        this,ESI
    //         004aa03d     CALL       TRIBE_Screen_Sed::set_paint_object_mode          void set_paint_object_mode(TRIBE_Screen_Sed *
    //                              scr_sed.cpp:1288 (20)
    //         004aa042     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004aa048     PUSH       0x4
    //         004aa04a     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004aa050     MOV        EDX,dword ptr [this->_padding_]
    //         004aa052     PUSH       EAX=>DAT_fffffff8
    //         004aa053     CALL       dword ptr [EDX + 0x10]
    //                              scr_sed.cpp:1289 (25)
    //         004aa056     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004aa05c     CMP        word ptr [ECX + this->_padding_],-0x1
    //         004aa064     JZ         LAB_004aa0a9
    //         004aa066     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004aa06b     TEST       EAX,EAX
    //         004aa06d     JZ         LAB_004aa0a9
    //                              scr_sed.cpp:1291 (56)
    //         004aa06f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004aa075     MOV        DI,word ptr [ECX + this->_padding_]
    //         004aa07c     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004aa081     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004aa087     PUSH       EAX
    //         004aa088     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004aa08d     MOV        EDX,dword ptr [ESI + 0x928]
    //         004aa093     MOVSX      this,word ptr [EAX + 0x4a]
    //         004aa097     MOV        EAX,dword ptr [EDX + 0x40]
    //         004aa09a     MOVSX      EDX,DI
    //         004aa09d     MOV        this,dword ptr [EAX + this->_padding_*0x4]
    //         004aa0a0     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004aa0a3     MOV        this,dword ptr [EAX + EDX*0x4]
    //         004aa0a6     PUSH       this=>DAT_fffffff8
    //                              scr_sed.cpp:1292 (2)
    //         004aa0a7     JMP        LAB_004aa0ad
    //                               LAB_004aa0a9                                                 XREF[2]:     004aa064(j), 004aa06d(j)  
    //                              scr_sed.cpp:1293 (15)
    //         004aa0a9     PUSH       0x0
    //         004aa0ab     PUSH       0x0=>DAT_fffffff8
    //                               LAB_004aa0ad                                                 XREF[1]:     004aa0a7(j)  
    //         004aa0ad     MOV        this,dword ptr [ESI + 0x660]
    //         004aa0b3     CALL       TRIBE_Scenario_Editor_Panel_Object::set_master   void set_master_info(TRIBE_Scenario_Editor_Pa
    //                              scr_sed.cpp:1294 (13)
    //         004aa0b8     MOV        this,dword ptr [ESI + 0x660]
    //         004aa0be     PUSH       0x1
    //         004aa0c0     MOV        EDX,dword ptr [this->_padding_]
    //         004aa0c2     CALL       dword ptr [EDX + 0x20]
    //                              scr_sed.cpp:1296 (5)
    //         004aa0c5     JMP        switchD_004a9d10::default
    //                               LAB_004aa0ca                                                 XREF[1]:     004aa008(j)  
    //                              scr_sed.cpp:1298 (12)
    //         004aa0ca     CMP        AX,0x1
    //         004aa0ce     JL         LAB_004aa0d6
    //         004aa0d0     CMP        AX,0x8
    //         004aa0d4     JLE        LAB_004aa0ec
    //                               LAB_004aa0d6                                                 XREF[1]:     004aa0ce(j)  
    //                              scr_sed.cpp:1301 (22)
    //         004aa0d6     PUSH       0x0
    //         004aa0d8     PUSH       0x0=>DAT_fffffff8
    //         004aa0da     PUSH       offset DAT_fffffff4
    //         004aa0dc     MOV        this,ESI
    //         004aa0de     MOV        word ptr [ESI + 0x4b8],0x1
    //         004aa0e7     CALL       TRIBE_Screen_Sed::set_player                     void set_player(TRIBE_Screen_Sed * this, shor
    //                               LAB_004aa0ec                                                 XREF[1]:     004aa0d4(j)  
    //                              scr_sed.cpp:1303 (15)
    //         004aa0ec     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004aa0f2     PUSH       0x0
    //         004aa0f4     PUSH       0x0=>DAT_fffffff8
    //         004aa0f6     MOV        EAX,dword ptr [this->_padding_]
    //         004aa0f8     CALL       dword ptr [EAX + 0x10]
    //                              scr_sed.cpp:1304 (9)
    //         004aa0fb     PUSH       -0x1
    //         004aa0fd     MOV        this,ESI
    //         004aa0ff     CALL       TRIBE_Screen_Sed::set_unit                       void set_unit(TRIBE_Screen_Sed * this, short 
    //                              scr_sed.cpp:1306 (5)
    //         004aa104     JMP        switchD_004a9d10::default
    //                               switchD_004a9d10::caseD_6                                    XREF[2]:     004a9d10(j), 004aa6fc(*)  
    //                              scr_sed.cpp:1310 (8)
    //         004aa109     PUSH       EDI
    //         004aa10a     MOV        this,ESI
    //         004aa10c     CALL       TRIBE_Screen_Sed::activate_victory_panel         void activate_victory_panel(TRIBE_Screen_Sed 
    //                              scr_sed.cpp:1311 (6)
    //         004aa111     XOR        EBX,EBX
    //         004aa113     CMP        EDI,EBX
    //         004aa115     JZ         LAB_004aa13e
    //                              scr_sed.cpp:1313 (14)
    //         004aa117     MOV        this,dword ptr [ESI + 0x498]
    //         004aa11d     PUSH       this
    //         004aa11e     MOV        this,ESI
    //         004aa120     CALL       TRIBE_Screen_Sed::load_victory_cond_from_scena   void load_victory_cond_from_scenario(TRIBE_Sc
    //                              scr_sed.cpp:1314 (20)
    //         004aa125     MOV        this,dword ptr [ESI + 0x734]
    //         004aa12b     PUSH       EDI
    //         004aa12c     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this)
    //         004aa131     PUSH       EAX=>DAT_fffffff8
    //         004aa132     MOV        this,ESI
    //         004aa134     CALL       TRIBE_Screen_Sed::activate_victory_proper_fields void activate_victory_proper_fields(TRIBE_Scr
    //                              scr_sed.cpp:1316 (5)
    //         004aa139     JMP        switchD_004a9d10::default
    //                               LAB_004aa13e                                                 XREF[1]:     004aa115(j)  
    //                              scr_sed.cpp:1318 (14)
    //         004aa13e     MOV        EDX,dword ptr [ESI + 0x498]
    //         004aa144     MOV        this,ESI
    //         004aa146     PUSH       EDX
    //         004aa147     CALL       TRIBE_Screen_Sed::save_victory_cond_in_scenario  void save_victory_cond_in_scenario(TRIBE_Scre
    //                              scr_sed.cpp:1319 (20)
    //         004aa14c     MOV        this,dword ptr [ESI + 0x734]
    //         004aa152     PUSH       EBX
    //         004aa153     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this)
    //         004aa158     PUSH       EAX=>DAT_fffffff8
    //         004aa159     MOV        this,ESI
    //         004aa15b     CALL       TRIBE_Screen_Sed::activate_victory_proper_fields void activate_victory_proper_fields(TRIBE_Scr
    //                              scr_sed.cpp:1320 (6)
    //         004aa160     MOV        dword ptr [ESI + 0x480],EBX
    //                              scr_sed.cpp:1321 (6)
    //         004aa166     MOV        dword ptr [ESI + 0x484],EBX
    //                              scr_sed.cpp:1322 (18)
    //         004aa16c     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004aa172     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004aa177     MOV        this,EAX
    //         004aa179     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
    //                              scr_sed.cpp:1325 (5)
    //         004aa17e     JMP        switchD_004a9d10::default
    //                               switchD_004a9d10::caseD_7                                    XREF[2]:     004a9d10(j), 004aa700(*)  
    //                              scr_sed.cpp:1330 (12)
    //         004aa183     MOV        this,dword ptr [ESI + 0x688]
    //         004aa189     PUSH       EDI
    //         004aa18a     MOV        EAX,dword ptr [this->_padding_]
    //         004aa18c     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1535 (79)
    //         004aa18f     LEA        EBX,[ESI + 0x6e0]
    //         004aa195     MOV        EBP,0x5
    //                               LAB_004aa19a                                                 XREF[1]:     004aa1af(j)  
    //         004aa19a     MOV        this,dword ptr [EBX + -0x14]
    //         004aa19d     PUSH       EDI
    //         004aa19e     MOV        EDX,dword ptr [this->_padding_]
    //         004aa1a0     CALL       dword ptr [EDX + 0x14]
    //         004aa1a3     MOV        this,dword ptr [EBX]
    //         004aa1a5     PUSH       EDI
    //         004aa1a6     MOV        EAX,dword ptr [this->_padding_]
    //         004aa1a8     CALL       dword ptr [EAX + 0x14]
    //         004aa1ab     ADD        EBX,0x4
    //         004aa1ae     DEC        EBP
    //         004aa1af     JNZ        LAB_004aa19a
    //         004aa1b1     TEST       EDI,EDI
    //         004aa1b3     MOV        this,ESI
    //         004aa1b5     JZ         LAB_004aa1de
    //         004aa1b7     CALL       TRIBE_Screen_Sed::load_multi_victory_cond_from   void load_multi_victory_cond_from_scenario(TR
    //         004aa1bc     MOV        this,dword ptr [ESI + 0x4cc]
    //         004aa1c2     PUSH       0x0
    //         004aa1c4     MOV        EDX,dword ptr [this->_padding_]
    //         004aa1c6     CALL       dword ptr [EDX + 0x14]
    //         004aa1c9     MOV        EAX,dword ptr [ESI + 0x4ac]
    //         004aa1cf     PUSH       0x1
    //         004aa1d1     PUSH       EAX=>DAT_fffffff8
    //         004aa1d2     MOV        this,ESI
    //         004aa1d4     CALL       TRIBE_Screen_Sed::set_mp_victory_type            void set_mp_victory_type(TRIBE_Screen_Sed * t
    //         004aa1d9     JMP        switchD_004a9d10::default
    //                               LAB_004aa1de                                                 XREF[1]:     004aa1b5(j)  
    //                              scr_sed.cpp:1345 (5)
    //         004aa1de     CALL       TRIBE_Screen_Sed::save_multi_victory_cond_in_s   void save_multi_victory_cond_in_scenario(TRIB
    //                              scr_sed.cpp:1346 (13)
    //         004aa1e3     MOV        this,dword ptr [ESI + 0x4cc]
    //         004aa1e9     PUSH       0x1
    //         004aa1eb     MOV        EDX,dword ptr [this->_padding_]
    //         004aa1ed     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1347 (11)
    //         004aa1f0     PUSH       0x0
    //         004aa1f2     PUSH       0x0=>DAT_fffffff8
    //         004aa1f4     MOV        this,ESI
    //         004aa1f6     CALL       TRIBE_Screen_Sed::set_mp_victory_type            void set_mp_victory_type(TRIBE_Screen_Sed * t
    //                              scr_sed.cpp:1349 (5)
    //         004aa1fb     JMP        switchD_004a9d10::default
    //                               switchD_004a9d10::caseD_9                                    XREF[2]:     004a9d10(j), 004aa708(*)  
    //                              scr_sed.cpp:1535 (104)
    //         004aa200     LEA        EBX,[ESI + 0x78c]
    //         004aa206     MOV        EBP,0x5
    //                               LAB_004aa20b                                                 XREF[1]:     004aa220(j)  
    //         004aa20b     MOV        this,dword ptr [EBX + -0x14]
    //         004aa20e     PUSH       EDI
    //         004aa20f     MOV        EAX,dword ptr [this->_padding_]
    //         004aa211     CALL       dword ptr [EAX + 0x14]
    //         004aa214     MOV        this,dword ptr [EBX]
    //         004aa216     PUSH       EDI
    //         004aa217     MOV        EDX,dword ptr [this->_padding_]
    //         004aa219     CALL       dword ptr [EDX + 0x14]
    //         004aa21c     ADD        EBX,0x4
    //         004aa21f     DEC        EBP
    //         004aa220     JNZ        LAB_004aa20b
    //         004aa222     MOV        EAX,dword ptr [ESI + 0x7a0]
    //         004aa228     MOV        this,dword ptr [ESI + EAX*0x4 + 0x778]
    //         004aa22f     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
    //         004aa234     MOV        this,dword ptr [ESI + 0x7a0]
    //         004aa23a     TEST       EDI,EDI
    //         004aa23c     PUSH       this
    //         004aa23d     JZ         LAB_004aa2d9
    //         004aa243     MOV        EDX,dword ptr [ESI + 0x928]
    //         004aa249     MOV        this,dword ptr [EDX + 0x5c]
    //         004aa24c     CALL       RGE_Scenario::Get_message                        char * Get_message(RGE_Scenario * this, long 
    //         004aa251     MOV        this,dword ptr [ESI + 0x774]
    //         004aa257     PUSH       EAX
    //         004aa258     CALL       TEditPanel::set_text                             void set_text(TEditPanel * this, char * param
    //         004aa25d     MOV        EAX,dword ptr [ESI + 0x7a0]
    //         004aa263     CMP        EAX,0x4
    //         004aa266     JA         switchD_004aa268::default
    //                               switchD_004aa268::switchD
    //                              scr_sed.cpp:1362 (7)
    //         004aa268     JMP        dword ptr [EAX*0x4 + switchD_004aa268::switchd   = 004aa26f
    //                               switchD_004aa268::caseD_0                                    XREF[2]:     004aa268(j), 004aa710(*)  
    //                              scr_sed.cpp:1365 (7)
    //         004aa26f     PUSH       -0x1
    //         004aa271     PUSH       offset DAT_fffffff8
    //                              scr_sed.cpp:1366 (2)
    //         004aa276     JMP        LAB_004aa29a
    //                               switchD_004aa268::caseD_1                                    XREF[2]:     004aa268(j), 004aa714(*)  
    //                              scr_sed.cpp:1368 (7)
    //         004aa278     PUSH       -0x1
    //         004aa27a     PUSH       offset DAT_fffffff8
    //                              scr_sed.cpp:1369 (2)
    //         004aa27f     JMP        LAB_004aa29a
    //                               switchD_004aa268::caseD_2                                    XREF[2]:     004aa268(j), 004aa718(*)  
    //                              scr_sed.cpp:1371 (7)
    //         004aa281     PUSH       -0x1
    //         004aa283     PUSH       offset DAT_fffffff8
    //                              scr_sed.cpp:1372 (2)
    //         004aa288     JMP        LAB_004aa29a
    //                               switchD_004aa268::caseD_3                                    XREF[2]:     004aa268(j), 004aa71c(*)  
    //                              scr_sed.cpp:1374 (7)
    //         004aa28a     PUSH       -0x1
    //         004aa28c     PUSH       offset DAT_fffffff8
    //                              scr_sed.cpp:1375 (2)
    //         004aa291     JMP        LAB_004aa29a
    //                               switchD_004aa268::caseD_4                                    XREF[2]:     004aa268(j), 004aa720(*)  
    //                              scr_sed.cpp:1377 (18)
    //         004aa293     PUSH       -0x1
    //                              language.dll match for 0x7774: "Type the history text (option
    //         004aa295     PUSH       offset DAT_fffffff8
    //                               LAB_004aa29a                                                 XREF[4]:     004aa276(j), 004aa27f(j), 
    //                                                                                                         004aa288(j), 004aa291(j)  
    //         004aa29a     MOV        this,dword ptr [ESI + 0x774]
    //         004aa2a0     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                               switchD_004aa268::default                                    XREF[1]:     004aa266(j)  
    //                              scr_sed.cpp:1381 (16)
    //         004aa2a5     MOV        EAX,dword ptr [ESI + 0x4bc]
    //         004aa2ab     PUSH       0x1
    //         004aa2ad     PUSH       EAX=>DAT_fffffff8
    //         004aa2ae     MOV        this,ESI
    //         004aa2b0     CALL       TRIBE_Screen_Sed::set_message_type               void set_message_type(TRIBE_Screen_Sed * this
    //                              scr_sed.cpp:1382 (13)
    //         004aa2b5     MOV        this,dword ptr [ESI + 0x4cc]
    //         004aa2bb     PUSH       0x0
    //         004aa2bd     MOV        EDX,dword ptr [this->_padding_]
    //         004aa2bf     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1383 (18)
    //         004aa2c2     MOV        EAX,dword ptr [ESI + 0x774]
    //         004aa2c8     MOV        this,dword ptr [ESI + 0x4d4]
    //         004aa2ce     PUSH       EAX
    //         004aa2cf     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              scr_sed.cpp:1385 (5)
    //         004aa2d4     JMP        switchD_004a9d10::default
    //                               LAB_004aa2d9                                                 XREF[1]:     004aa23d(j)  
    //                              scr_sed.cpp:1388 (26)
    //         004aa2d9     MOV        this,dword ptr [ESI + 0x774]
    //         004aa2df     CALL       TEditPanel::get_input_buffer                     char * get_input_buffer(TEditPanel * this)
    //         004aa2e4     MOV        EDX,dword ptr [ESI + 0x928]
    //         004aa2ea     PUSH       EAX=>DAT_fffffff8
    //         004aa2eb     MOV        this,dword ptr [EDX + 0x5c]
    //         004aa2ee     CALL       RGE_Scenario::Set_message                        void Set_message(RGE_Scenario * this, char * 
    //                              scr_sed.cpp:1389 (11)
    //         004aa2f3     PUSH       0x0
    //         004aa2f5     PUSH       0x0=>DAT_fffffff8
    //         004aa2f7     MOV        this,ESI
    //         004aa2f9     CALL       TRIBE_Screen_Sed::set_message_type               void set_message_type(TRIBE_Screen_Sed * this
    //                              scr_sed.cpp:1390 (13)
    //         004aa2fe     MOV        this,dword ptr [ESI + 0x4cc]
    //         004aa304     PUSH       0x1
    //         004aa306     MOV        EAX,dword ptr [this->_padding_]
    //         004aa308     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1391 (7)
    //         004aa30b     MOV        this,ESI
    //         004aa30d     CALL       TRIBE_Screen_Sed::save_info_in_scenario          void save_info_in_scenario(TRIBE_Screen_Sed *
    //                              scr_sed.cpp:1393 (5)
    //         004aa312     JMP        switchD_004a9d10::default
    //                               switchD_004a9d10::caseD_a                                    XREF[2]:     004a9d10(j), 004aa70c(*)  
    //                              scr_sed.cpp:1535 (280)
    //         004aa317     LEA        EBP,[ESI + 0x7b4]
    //         004aa31d     MOV        dword ptr [ESP + activate_counter],0x4
    //         004aa325     MOV        EBX,EBP
    //                               LAB_004aa327                                                 XREF[1]:     004aa344(j)  
    //         004aa327     MOV        this,dword ptr [EBX + -0x10]
    //         004aa32a     PUSH       EDI
    //         004aa32b     MOV        EDX,dword ptr [this->_padding_]
    //         004aa32d     CALL       dword ptr [EDX + 0x14]
    //         004aa330     MOV        this,dword ptr [EBX]
    //         004aa332     PUSH       EDI
    //         004aa333     MOV        EAX,dword ptr [this->_padding_]
    //         004aa335     CALL       dword ptr [EAX + 0x14]
    //         004aa338     MOV        EAX,dword ptr [ESP + 0x10]
    //         004aa33c     ADD        EBX,0x4
    //         004aa33f     DEC        EAX
    //         004aa340     MOV        dword ptr [ESP + 0x10],EAX
    //         004aa344     JNZ        LAB_004aa327
    //         004aa346     MOV        this,dword ptr [EBP]
    //         004aa349     TEST       EDI,EDI
    //         004aa34b     JZ         LAB_004aa42f
    //         004aa351     PUSH       this
    //         004aa352     MOV        this,dword ptr [ESI + 0x4d4]
    //         004aa358     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //         004aa35d     MOV        EDX,dword ptr [ESI + 0x928]
    //         004aa363     MOV        this,dword ptr [EDX + 0x5c]
    //         004aa366     CALL       RGE_Scenario::Get_Cine_PreGame                   char * Get_Cine_PreGame(RGE_Scenario * this)
    //         004aa36b     MOV        this,dword ptr [EBP]
    //         004aa36e     PUSH       EAX
    //         004aa36f     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this, char * p
    //         004aa374     MOV        this,dword ptr [EBP]
    //         004aa377     PUSH       EAX
    //         004aa378     CALL       TDropDownPanel::setCurrentLineNumber             void setCurrentLineNumber(TDropDownPanel * th
    //         004aa37d     MOV        EAX,dword ptr [ESI + 0x928]
    //         004aa383     MOV        this,dword ptr [EAX + 0x5c]
    //         004aa386     CALL       RGE_Scenario::Get_Cine_Victory                   char * Get_Cine_Victory(RGE_Scenario * this)
    //         004aa38b     MOV        this,dword ptr [ESI + 0x7b8]
    //         004aa391     PUSH       EAX
    //         004aa392     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this, char * p
    //         004aa397     MOV        this,dword ptr [ESI + 0x7b8]
    //         004aa39d     PUSH       EAX
    //         004aa39e     CALL       TDropDownPanel::setCurrentLineNumber             void setCurrentLineNumber(TDropDownPanel * th
    //         004aa3a3     MOV        this,dword ptr [ESI + 0x928]
    //         004aa3a9     MOV        this,dword ptr [ECX + this->_padding_]
    //         004aa3ac     CALL       RGE_Scenario::Get_Cine_Loss                      char * Get_Cine_Loss(RGE_Scenario * this)
    //         004aa3b1     MOV        this,dword ptr [ESI + 0x7bc]
    //         004aa3b7     PUSH       EAX
    //         004aa3b8     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this, char * p
    //         004aa3bd     MOV        this,dword ptr [ESI + 0x7bc]
    //         004aa3c3     PUSH       EAX
    //         004aa3c4     CALL       TDropDownPanel::setCurrentLineNumber             void setCurrentLineNumber(TDropDownPanel * th
    //         004aa3c9     MOV        EDX,dword ptr [ESI + 0x928]
    //         004aa3cf     MOV        this,dword ptr [EDX + 0x5c]
    //         004aa3d2     CALL       RGE_Scenario::Get_Mission_Bmp                    char * Get_Mission_Bmp(RGE_Scenario * this)
    //         004aa3d7     MOV        this,dword ptr [ESI + 0x7c0]
    //         004aa3dd     PUSH       EAX
    //         004aa3de     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this, char * p
    //         004aa3e3     CMP        EAX,-0x1
    //         004aa3e6     JNZ        LAB_004aa41e
    //         004aa3e8     MOV        EAX,dword ptr [ESI + 0x928]
    //         004aa3ee     PUSH       0x0
    //         004aa3f0     MOV        this,dword ptr [EAX + 0x5c]
    //         004aa3f3     CALL       RGE_Scenario::Get_Mission_Bmp                    char * Get_Mission_Bmp(RGE_Scenario * this)
    //         004aa3f8     MOV        this,dword ptr [ESI + 0x7c0]
    //         004aa3fe     PUSH       EAX=>DAT_fffffff8
    //         004aa3ff     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
    //         004aa404     MOV        this,dword ptr [ESI + 0x928]
    //         004aa40a     MOV        this,dword ptr [ECX + this->_padding_]
    //         004aa40d     CALL       RGE_Scenario::Get_Mission_Bmp                    char * Get_Mission_Bmp(RGE_Scenario * this)
    //         004aa412     MOV        this,dword ptr [ESI + 0x7c0]
    //         004aa418     PUSH       EAX
    //         004aa419     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this, char * p
    //                               LAB_004aa41e                                                 XREF[1]:     004aa3e6(j)  
    //         004aa41e     MOV        this,dword ptr [ESI + 0x7c0]
    //         004aa424     PUSH       EAX
    //         004aa425     CALL       TDropDownPanel::setCurrentLineNumber             void setCurrentLineNumber(TDropDownPanel * th
    //         004aa42a     JMP        switchD_004a9d10::default
    //                               LAB_004aa42f                                                 XREF[1]:     004aa34b(j)  
    //                              scr_sed.cpp:1425 (20)
    //         004aa42f     CALL       TDropDownPanel::currentLine                      char * currentLine(TDropDownPanel * this)
    //         004aa434     MOV        EDX,dword ptr [ESI + 0x928]
    //         004aa43a     PUSH       EAX
    //         004aa43b     MOV        this,dword ptr [EDX + 0x5c]
    //         004aa43e     CALL       RGE_Scenario::Set_Cine_PreGame                   void Set_Cine_PreGame(RGE_Scenario * this, ch
    //                              scr_sed.cpp:1426 (26)
    //         004aa443     MOV        this,dword ptr [ESI + 0x7b8]
    //         004aa449     CALL       TDropDownPanel::currentLine                      char * currentLine(TDropDownPanel * this)
    //         004aa44e     PUSH       EAX
    //         004aa44f     MOV        EAX,dword ptr [ESI + 0x928]
    //         004aa455     MOV        this,dword ptr [EAX + 0x5c]
    //         004aa458     CALL       RGE_Scenario::Set_Cine_Victory                   void Set_Cine_Victory(RGE_Scenario * this, ch
    //                              scr_sed.cpp:1427 (26)
    //         004aa45d     MOV        this,dword ptr [ESI + 0x7bc]
    //         004aa463     CALL       TDropDownPanel::currentLine                      char * currentLine(TDropDownPanel * this)
    //         004aa468     MOV        this,dword ptr [ESI + 0x928]
    //         004aa46e     PUSH       EAX
    //         004aa46f     MOV        this,dword ptr [ECX + this->_padding_]
    //         004aa472     CALL       RGE_Scenario::Set_Cine_Loss                      void Set_Cine_Loss(RGE_Scenario * this, char 
    //                              scr_sed.cpp:1428 (26)
    //         004aa477     MOV        this,dword ptr [ESI + 0x7c0]
    //         004aa47d     CALL       TDropDownPanel::currentLine                      char * currentLine(TDropDownPanel * this)
    //         004aa482     MOV        EDX,dword ptr [ESI + 0x928]
    //         004aa488     PUSH       EAX
    //         004aa489     MOV        this,dword ptr [EDX + 0x5c]
    //         004aa48c     CALL       RGE_Scenario::Set_Mission_Bmp                    void Set_Mission_Bmp(RGE_Scenario * this, cha
    //                              scr_sed.cpp:1430 (5)
    //         004aa491     JMP        switchD_004a9d10::default
    //                               switchD_004a9d10::caseD_5                                    XREF[2]:     004a9d10(j), 004aa6f8(*)  
    //                              scr_sed.cpp:1434 (14)
    //         004aa496     MOV        EAX,0x1
    //         004aa49b     CMP        word ptr [ESI + 0x4b8],AX
    //         004aa4a2     JGE        LAB_004aa4ab
    //                              scr_sed.cpp:1435 (7)
    //         004aa4a4     MOV        word ptr [ESI + 0x4b8],AX
    //                               LAB_004aa4ab                                                 XREF[1]:     004aa4a2(j)  
    //                              scr_sed.cpp:1438 (12)
    //         004aa4ab     MOV        this,dword ptr [ESI + 0x894]
    //         004aa4b1     PUSH       EDI
    //         004aa4b2     MOV        EAX,dword ptr [this->_padding_]
    //         004aa4b4     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1439 (35)
    //         004aa4b7     MOV        this,dword ptr [ESI + 0x5b8]
    //         004aa4bd     MOV        dword ptr [ESP + 0x10],0x0
    //         004aa4c5     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this)
    //         004aa4ca     TEST       EAX,EAX
    //         004aa4cc     JL         LAB_004aa53a
    //         004aa4ce     LEA        EBP,[ESI + 0x8ac]
    //         004aa4d4     LEA        EBX,[ESI + 0x908]
    //                               LAB_004aa4da                                                 XREF[1]:     004aa538(j)  
    //                              scr_sed.cpp:1441 (12)
    //         004aa4da     MOV        this,dword ptr [EBX + 0xffffff6c]
    //         004aa4e0     PUSH       EDI
    //         004aa4e1     MOV        EDX,dword ptr [this->_padding_]
    //         004aa4e3     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1442 (14)
    //         004aa4e6     MOVSX      EAX,word ptr [ESI + 0x4b8]
    //         004aa4ed     MOV        this,dword ptr [ESP + 0x10]
    //         004aa4f1     DEC        EAX
    //         004aa4f2     CMP        this,EAX
    //                              scr_sed.cpp:1444 (2)
    //         004aa4f4     MOV        this,dword ptr [EBX]
    //                              scr_sed.cpp:1449 (2)
    //         004aa4f6     JZ         LAB_004aa514
    //                              scr_sed.cpp:1455 (7)
    //         004aa4f8     MOV        EAX,dword ptr [this->_padding_]
    //         004aa4fa     PUSH       0x0
    //         004aa4fc     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1459 (9)
    //         004aa4ff     MOV        this,dword ptr [EBP + -0x4]
    //         004aa502     PUSH       EDI
    //         004aa503     MOV        EDX,dword ptr [this->_padding_]
    //         004aa505     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1460 (9)
    //         004aa508     MOV        this,dword ptr [EBP]
    //         004aa50b     PUSH       EDI
    //         004aa50c     MOV        EAX,dword ptr [this->_padding_]
    //         004aa50e     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1461 (41)
    //         004aa511     MOV        this,dword ptr [EBP + 0x4]
    //                               LAB_004aa514                                                 XREF[1]:     004aa4f6(j)  
    //         004aa514     MOV        EDX,dword ptr [this->_padding_]
    //         004aa516     PUSH       EDI
    //         004aa517     CALL       dword ptr [EDX + 0x14]
    //         004aa51a     MOV        this,dword ptr [ESP + 0x10]
    //         004aa51e     ADD        EBX,0x4
    //         004aa521     INC        this
    //         004aa522     ADD        EBP,0xc
    //         004aa525     MOV        dword ptr [ESP + 0x10],this
    //         004aa529     MOV        this,dword ptr [ESI + 0x5b8]
    //         004aa52f     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this)
    //         004aa534     CMP        dword ptr [ESP + 0x10],EAX
    //         004aa538     JLE        LAB_004aa4da
    //                               LAB_004aa53a                                                 XREF[1]:     004aa4cc(j)  
    //                              scr_sed.cpp:1465 (12)
    //         004aa53a     MOV        this,dword ptr [ESI + 0x898]
    //         004aa540     PUSH       EDI
    //         004aa541     MOV        EAX,dword ptr [this->_padding_]
    //         004aa543     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1466 (12)
    //         004aa546     MOV        this,dword ptr [ESI + 0x89c]
    //         004aa54c     PUSH       EDI
    //         004aa54d     MOV        EDX,dword ptr [this->_padding_]
    //         004aa54f     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1467 (12)
    //         004aa552     MOV        this,dword ptr [ESI + 0x8a0]
    //         004aa558     PUSH       EDI
    //         004aa559     MOV        EAX,dword ptr [this->_padding_]
    //         004aa55b     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1468 (12)
    //         004aa55e     MOV        this,dword ptr [ESI + 0x8a4]
    //         004aa564     PUSH       EDI
    //         004aa565     MOV        EDX,dword ptr [this->_padding_]
    //         004aa567     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1471 (4)
    //         004aa56a     TEST       EDI,EDI
    //         004aa56c     JZ         LAB_004aa583
    //                              scr_sed.cpp:1472 (16)
    //         004aa56e     MOVSX      EAX,word ptr [ESI + 0x4b8]
    //         004aa575     DEC        EAX
    //         004aa576     MOV        this,ESI
    //         004aa578     PUSH       EAX
    //         004aa579     CALL       TRIBE_Screen_Sed::load_diplomacy_from_scenario   void load_diplomacy_from_scenario(TRIBE_Scree
    //                              scr_sed.cpp:1473 (5)
    //         004aa57e     JMP        switchD_004a9d10::default
    //                               LAB_004aa583                                                 XREF[1]:     004aa56c(j)  
    //                              scr_sed.cpp:1474 (16)
    //         004aa583     MOVSX      this,word ptr [ESI + 0x4b8]
    //         004aa58a     DEC        this
    //         004aa58b     PUSH       this
    //         004aa58c     MOV        this,ESI
    //         004aa58e     CALL       TRIBE_Screen_Sed::save_diplomacy_in_scenario     void save_diplomacy_in_scenario(TRIBE_Screen_
    //                              scr_sed.cpp:1476 (5)
    //         004aa593     JMP        switchD_004a9d10::default
    //                               switchD_004a9d10::caseD_8                                    XREF[2]:     004a9d10(j), 004aa704(*)  
    //                              scr_sed.cpp:1481 (17)
    //         004aa598     MOV        this,dword ptr [ESI + 0x4cc]
    //         004aa59e     TEST       EDI,EDI
    //         004aa5a0     JNZ        LAB_004aa5b2
    //         004aa5a2     MOV        EDX,dword ptr [this->_padding_]
    //         004aa5a4     PUSH       0x1
    //         004aa5a6     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1482 (7)
    //         004aa5a9     MOV        this,ESI
    //         004aa5ab     CALL       TRIBE_Screen_Sed::SaveDisabledItemsInScenario    void SaveDisabledItemsInScenario(TRIBE_Screen
    //                              scr_sed.cpp:1484 (2)
    //         004aa5b0     JMP        LAB_004aa605
    //                               LAB_004aa5b2                                                 XREF[1]:     004aa5a0(j)  
    //                              scr_sed.cpp:1486 (7)
    //         004aa5b2     MOV        EAX,dword ptr [this->_padding_]
    //         004aa5b4     PUSH       0x0
    //         004aa5b6     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1487 (37)
    //         004aa5b9     MOV        this,dword ptr [ESI + 0x7c8]
    //         004aa5bf     MOV        EDX,dword ptr [ESI + 0x928]
    //         004aa5c5     PUSH       0x2
    //         004aa5c7     MOV        EBX,dword ptr [this->_padding_]
    //         004aa5c9     MOV        this,dword ptr [EDX + 0x5c]
    //         004aa5cc     CALL       T_Scenario::GetScenarioOption                    int GetScenarioOption(T_Scenario * this, int 
    //         004aa5d1     MOV        this,dword ptr [ESI + 0x7c8]
    //         004aa5d7     PUSH       EAX
    //         004aa5d8     CALL       dword ptr [EBX + 0xe0]
    //                              scr_sed.cpp:1488 (7)
    //         004aa5de     MOV        this,ESI
    //         004aa5e0     CALL       TRIBE_Screen_Sed::LoadDisabledItemsFromScenario  void LoadDisabledItemsFromScenario(TRIBE_Scre
    //                              scr_sed.cpp:1489 (12)
    //         004aa5e5     MOV        AX,word ptr [ESI + 0x4b8]
    //         004aa5ec     TEST       AX,AX
    //         004aa5ef     JZ         LAB_004aa5f8
    //                              scr_sed.cpp:1490 (5)
    //         004aa5f1     MOVSX      EAX,AX
    //         004aa5f4     DEC        EAX
    //         004aa5f5     PUSH       EAX
    //                              scr_sed.cpp:1491 (2)
    //         004aa5f6     JMP        LAB_004aa5fa
    //                               LAB_004aa5f8                                                 XREF[1]:     004aa5ef(j)  
    //                              scr_sed.cpp:1492 (13)
    //         004aa5f8     PUSH       0x0
    //                               LAB_004aa5fa                                                 XREF[1]:     004aa5f6(j)  
    //         004aa5fa     MOV        this,dword ptr [ESI + 0x7cc]
    //         004aa600     CALL       TDropDownPanel::setCurrentLineNumber             void setCurrentLineNumber(TDropDownPanel * th
    //                               LAB_004aa605                                                 XREF[1]:     004aa5b0(j)  
    //                              scr_sed.cpp:1495 (11)
    //         004aa605     LEA        EBX,[ESI + 0x7c8]
    //         004aa60b     MOV        EBP,0x1
    //                               LAB_004aa610                                                 XREF[1]:     004aa625(j)  
    //                              scr_sed.cpp:1497 (9)
    //         004aa610     MOV        this,dword ptr [EBX + -0x4]
    //         004aa613     PUSH       EDI
    //         004aa614     MOV        EDX,dword ptr [this->_padding_]
    //         004aa616     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1498 (14)
    //         004aa619     MOV        this,dword ptr [EBX]
    //         004aa61b     PUSH       EDI
    //         004aa61c     MOV        EAX,dword ptr [this->_padding_]
    //         004aa61e     CALL       dword ptr [EAX + 0x14]
    //         004aa621     ADD        EBX,0x4
    //         004aa624     DEC        EBP
    //         004aa625     JNZ        LAB_004aa610
    //                              scr_sed.cpp:1501 (12)
    //         004aa627     MOV        this,dword ptr [ESI + 0x7cc]
    //         004aa62d     PUSH       EDI
    //         004aa62e     MOV        EDX,dword ptr [this->_padding_]
    //         004aa630     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1502 (4)
    //         004aa633     TEST       EDI,EDI
    //         004aa635     JZ         LAB_004aa64d
    //                              scr_sed.cpp:1503 (20)
    //         004aa637     MOVSX      EAX,word ptr [ESI + 0x4b8]
    //         004aa63e     MOV        this,dword ptr [ESI + 0x7cc]
    //         004aa644     DEC        EAX
    //         004aa645     PUSH       EAX
    //         004aa646     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
    //                              scr_sed.cpp:1504 (2)
    //         004aa64b     JMP        LAB_004aa660
    //                               LAB_004aa64d                                                 XREF[1]:     004aa635(j)  
    //                              scr_sed.cpp:1505 (19)
    //         004aa64d     MOV        this,dword ptr [ESI + 0x7cc]
    //         004aa653     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this)
    //         004aa658     INC        EAX
    //         004aa659     MOV        word ptr [ESI + 0x4b8],AX
    //                               LAB_004aa660                                                 XREF[1]:     004aa64b(j)  
    //                              scr_sed.cpp:1507 (23)
    //         004aa660     MOV        this,dword ptr [ESI + 0x7d0]
    //         004aa666     PUSH       EDI
    //         004aa667     MOV        EDX,dword ptr [this->_padding_]
    //         004aa669     CALL       dword ptr [EDX + 0x14]
    //         004aa66c     LEA        EBX,[ESI + 0x814]
    //         004aa672     MOV        EBP,0x10
    //                               LAB_004aa677                                                 XREF[1]:     004aa68c(j)  
    //                              scr_sed.cpp:1510 (9)
    //         004aa677     MOV        this,dword ptr [EBX + -0x40]
    //         004aa67a     PUSH       EDI
    //         004aa67b     MOV        EAX,dword ptr [this->_padding_]
    //         004aa67d     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1511 (14)
    //         004aa680     MOV        this,dword ptr [EBX]
    //         004aa682     PUSH       EDI
    //         004aa683     MOV        EDX,dword ptr [this->_padding_]
    //         004aa685     CALL       dword ptr [EDX + 0x14]
    //         004aa688     ADD        EBX,0x4
    //         004aa68b     DEC        EBP
    //         004aa68c     JNZ        LAB_004aa677
    //                               switchD_004a9d10::default                                    XREF[18]:    004a9d0a(j), 004a9d65(j), 
    //                                                                                                         004a9d75(j), 004a9e04(j), 
    //                                                                                                         004a9e1d(j), 004a9f67(j), 
    //                                                                                                         004aa0c5(j), 004aa104(j), 
    //                                                                                                         004aa139(j), 004aa17e(j), 
    //                                                                                                         004aa1d9(j), 004aa1fb(j), 
    //                                                                                                         004aa2d4(j), 004aa312(j), 
    //                                                                                                         004aa42a(j), 004aa491(j), 
    //                                                                                                         004aa57e(j), 004aa593(j)  
    //                              scr_sed.cpp:1161 (18)
    //         004aa68e     MOV        EAX,dword ptr [ESP + 0x14]
    //         004aa692     INC        EAX
    //         004aa693     CMP        EAX,0x2
    //         004aa696     MOV        dword ptr [ESP + 0x14],EAX
    //         004aa69a     JL         LAB_004a9cd8
    //                              scr_sed.cpp:1520 (9)
    //         004aa6a0     MOV        EAX,dword ptr [ESP + 0x20]
    //         004aa6a4     CMP        EAX,0xb
    //         004aa6a7     JZ         LAB_004aa6d5
    //                              scr_sed.cpp:1526 (10)
    //         004aa6a9     TEST       EAX,EAX
    //         004aa6ab     MOV        dword ptr [ESI + 0x4a4],EAX
    //         004aa6b1     JZ         LAB_004aa6bf
    //                              scr_sed.cpp:1527 (12)
    //         004aa6b3     MOV        this,dword ptr [ESI + EAX*0x4 + 0x4d4]
    //         004aa6ba     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
    //                               LAB_004aa6bf                                                 XREF[1]:     004aa6b1(j)  
    //                              scr_sed.cpp:1530 (15)
    //         004aa6bf     MOV        EAX,dword ptr [ESI + 0x18]
    //         004aa6c2     MOV        this,dword ptr [ESI + 0x14]
    //         004aa6c5     MOV        EDI,dword ptr [ESI]
    //         004aa6c7     PUSH       EAX
    //         004aa6c8     PUSH       this=>DAT_fffffff8
    //         004aa6c9     MOV        this,ESI
    //         004aa6cb     CALL       dword ptr [EDI + 0x50]
    //                              scr_sed.cpp:1531 (7)
    //         004aa6ce     PUSH       0x1
    //         004aa6d0     MOV        this,ESI
    //         004aa6d2     CALL       dword ptr [EDI + 0x20]
    //                               LAB_004aa6d5                                                 XREF[1]:     004aa6a7(j)  
    //                              scr_sed.cpp:1534 (7)
    //         004aa6d5     MOV        byte ptr [ESI + 0x4c1],0x1
    //                              scr_sed.cpp:1535 (72)
    //         004aa6dc     POP        EDI
    //         004aa6dd     POP        ESI
    //         004aa6de     POP        EBP
    //         004aa6df     POP        EBX
    //         004aa6e0     ADD        ESP,0xc
    //         004aa6e3     RET        0x4
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_004aa6e6()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_004aa6e6
    //         004aa6e6     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004a9d10::switchdataD_004aa6e8                       XREF[1]:     set_scenario_mode:004a9d10(*)  
    //         004aa6e8     addr       switchD_004a9d10::caseD_1
    //         004aa6ec     addr       switchD_004a9d10::caseD_2
    //         004aa6f0     addr       switchD_004a9d10::caseD_3
    //         004aa6f4     addr       switchD_004a9d10::caseD_4
    //         004aa6f8     addr       switchD_004a9d10::caseD_5
    //         004aa6fc     addr       switchD_004a9d10::caseD_6
    //         004aa700     addr       switchD_004a9d10::caseD_7
    //         004aa704     addr       switchD_004a9d10::caseD_8
    //         004aa708     addr       switchD_004a9d10::caseD_9
    //         004aa70c     addr       switchD_004a9d10::caseD_a
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004aa268::switchdataD_004aa710                       XREF[1]:     set_scenario_mode:004aa268(*)  
    //         004aa710     addr       switchD_004aa268::caseD_0
    //         004aa714     addr       switchD_004aa268::caseD_1
    //         004aa718     addr       switchD_004aa268::caseD_2
    //         004aa71c     addr       switchD_004aa268::caseD_3
    //         004aa720     addr       switchD_004aa268::caseD_4
    //         004aa724     ??         90h
    //         004aa725     ??         90h
    //         004aa726     ??         90h
    //         004aa727     ??         90h
    //         004aa728     ??         90h
    //         004aa729     ??         90h
    //         004aa72a     ??         90h
    //         004aa72b     ??         90h
    //         004aa72c     ??         90h
    //         004aa72d     ??         90h
    //         004aa72e     ??         90h
    //         004aa72f     ??         90h
    return;
}

void TRIBE_Screen_Sed::set_paint_object_mode() {
    /* TODO: Stub */
    //                              void __thiscall set_paint_object_mode(TRIBE_Screen_Sed * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //                               ?set_paint_object_mode@TRIBE_Screen_Sed@@IAEXXZ              XREF[4]:     set_scenario_mode:004aa03d(c), 
    //                               TRIBE_Screen_Sed::set_paint_object_mode                                   action:004acb09(c), 
    //                                                                                                         action:004acbd0(c), 
    //                                                                                                         action:004acbfc(c)  
    //                              scr_sed.cpp:1541 (3)
    //         004aa730     MOV        EDX,this
    //         004aa732     PUSH       ESI
    //                              scr_sed.cpp:1545 (16)
    //         004aa733     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004aa739     XOR        ESI,ESI
    //         004aa73b     PUSH       EDI
    //         004aa73c     MOVSX      EAX,word ptr [ECX + this->_padding_]
    //                              scr_sed.cpp:1546 (5)
    //         004aa743     CMP        EAX,-0x1
    //         004aa746     JZ         LAB_004aa77a
    //                              scr_sed.cpp:1548 (25)
    //         004aa748     MOVSX      EDI,word ptr [EDX + 0x4b8]
    //         004aa74f     MOV        EDX,dword ptr [EDX + 0x928]
    //         004aa755     MOV        EDX,dword ptr [EDX + 0x40]
    //         004aa758     MOV        EDX,dword ptr [EDX + EDI*0x4]
    //         004aa75b     MOV        EDX,dword ptr [EDX + 0x24]
    //         004aa75e     MOV        EAX,dword ptr [EDX + EAX*0x4]
    //                              scr_sed.cpp:1549 (10)
    //         004aa761     TEST       EAX,EAX
    //         004aa763     JZ         LAB_004aa77a
    //         004aa765     CMP        byte ptr [EAX + 0x4],0x50
    //         004aa769     JNZ        LAB_004aa77a
    //                              scr_sed.cpp:1551 (10)
    //         004aa76b     MOV        DL,byte ptr [EAX + 0x16c]
    //         004aa771     TEST       DL,DL
    //         004aa773     JZ         LAB_004aa77a
    //                              scr_sed.cpp:1552 (5)
    //         004aa775     MOV        ESI,0x1
    //                               LAB_004aa77a                                                 XREF[4]:     004aa746(j), 004aa763(j), 
    //                                                                                                         004aa769(j), 004aa773(j)  
    //                              scr_sed.cpp:1556 (4)
    //         004aa77a     TEST       ESI,ESI
    //         004aa77c     JZ         LAB_004aa78a
    //                              scr_sed.cpp:1557 (9)
    //         004aa77e     MOV        EAX,dword ptr [this->_padding_]
    //         004aa780     PUSH       0x0
    //         004aa782     PUSH       0x15
    //         004aa784     CALL       dword ptr [EAX + 0x10]
    //                              scr_sed.cpp:1560 (3)
    //         004aa787     POP        EDI
    //         004aa788     POP        ESI
    //         004aa789     RET
    //                               LAB_004aa78a                                                 XREF[1]:     004aa77c(j)  
    //                              scr_sed.cpp:1559 (14)
    //         004aa78a     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004aa790     MOV        EDX,dword ptr [this->_padding_]
    //         004aa792     PUSH       EAX
    //         004aa793     PUSH       0x8
    //         004aa795     CALL       dword ptr [EDX + 0x10]
    //                              scr_sed.cpp:1560 (3)
    //         004aa798     POP        EDI
    //         004aa799     POP        ESI
    //         004aa79a     RET
    //         004aa79b     ??         90h
    //         004aa79c     NOP
    //         004aa79d     NOP
    //         004aa79e     NOP
    //         004aa79f     NOP
    return;
}

void TRIBE_Screen_Sed::set_map_type(MapType param_1, int param_2) {
    /* TODO: Stub */
    //                              void __thiscall set_map_type(TRIBE_Screen_Sed * this, MapType param_
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              MapType           Stack[0x4]:4   param_1                   XREF[1]:     004aa7a1(R)  
    //              int               Stack[0x8]:4   param_2
    //                               ?set_map_type@TRIBE_Screen_Sed@@IAEXW4MapType@1@H@Z          XREF[4]:     TRIBE_Screen_Sed:004a86ab(c), 
    //                               TRIBE_Screen_Sed::set_map_type                                            set_scenario_mode:004a9d60(c), 
    //                                                                                                         set_scenario_mode:004a9d70(c), 
    //                                                                                                         action:004ac4f3(c)  
    //                              scr_sed.cpp:1566 (1)
    //         004aa7a0     PUSH       EBX
    //                              scr_sed.cpp:1572 (11)
    //         004aa7a1     MOV        EBX,dword ptr [ESP + param_1]
    //         004aa7a5     PUSH       EBP
    //         004aa7a6     PUSH       ESI
    //         004aa7a7     PUSH       EDI
    //         004aa7a8     MOV        EDI,this
    //         004aa7aa     XOR        EBP,EBP
    //                               LAB_004aa7ac                                                 XREF[1]:     004aa8c2(j)  
    //                              scr_sed.cpp:1574 (4)
    //         004aa7ac     TEST       EBP,EBP
    //         004aa7ae     JNZ        LAB_004aa7ba
    //                              scr_sed.cpp:1576 (6)
    //         004aa7b0     MOV        EAX,dword ptr [EDI + 0x4a8]
    //                              scr_sed.cpp:1577 (2)
    //         004aa7b6     XOR        ESI,ESI
    //                              scr_sed.cpp:1579 (2)
    //         004aa7b8     JMP        LAB_004aa7d5
    //                               LAB_004aa7ba                                                 XREF[1]:     004aa7ae(j)  
    //                              scr_sed.cpp:1581 (8)
    //         004aa7ba     TEST       EBX,EBX
    //         004aa7bc     JZ         LAB_004aa8e7
    //                              scr_sed.cpp:1583 (12)
    //         004aa7c2     MOV        EAX,dword ptr [ESP + 0x18]
    //         004aa7c6     TEST       EAX,EAX
    //         004aa7c8     JZ         LAB_004aa8c8
    //                              scr_sed.cpp:1585 (2)
    //         004aa7ce     MOV        EAX,EBX
    //                              scr_sed.cpp:1586 (5)
    //         004aa7d0     MOV        ESI,0x1
    //                               LAB_004aa7d5                                                 XREF[1]:     004aa7b8(j)  
    //                              scr_sed.cpp:1589 (17)
    //         004aa7d5     DEC        EAX
    //         004aa7d6     JZ         LAB_004aa88e
    //         004aa7dc     DEC        EAX
    //         004aa7dd     JZ         LAB_004aa84a
    //         004aa7df     DEC        EAX
    //         004aa7e0     JNZ        LAB_004aa8be
    //                              scr_sed.cpp:1611 (12)
    //         004aa7e6     MOV        this,dword ptr [EDI + 0x52c]
    //         004aa7ec     PUSH       ESI
    //         004aa7ed     MOV        EAX,dword ptr [this->_padding_]
    //         004aa7ef     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1612 (12)
    //         004aa7f2     MOV        this,dword ptr [EDI + 0x530]
    //         004aa7f8     PUSH       ESI
    //         004aa7f9     MOV        EDX,dword ptr [this->_padding_]
    //         004aa7fb     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1614 (12)
    //         004aa7fe     MOV        this,dword ptr [EDI + 0x534]
    //         004aa804     PUSH       ESI
    //         004aa805     MOV        EAX,dword ptr [this->_padding_]
    //         004aa807     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1615 (12)
    //         004aa80a     MOV        this,dword ptr [EDI + 0x538]
    //         004aa810     PUSH       ESI
    //         004aa811     MOV        EDX,dword ptr [this->_padding_]
    //         004aa813     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1617 (12)
    //         004aa816     MOV        this,dword ptr [EDI + 0x53c]
    //         004aa81c     PUSH       ESI
    //         004aa81d     MOV        EAX,dword ptr [this->_padding_]
    //         004aa81f     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1618 (12)
    //         004aa822     MOV        this,dword ptr [EDI + 0x540]
    //         004aa828     PUSH       ESI
    //         004aa829     MOV        EDX,dword ptr [this->_padding_]
    //         004aa82b     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1620 (8)
    //         004aa82e     TEST       ESI,ESI
    //         004aa830     JZ         LAB_004aa8be
    //                              scr_sed.cpp:1621 (18)
    //         004aa836     MOV        EAX,dword ptr [EDI + 0x540]
    //         004aa83c     MOV        this,dword ptr [EDI + 0x4d4]
    //         004aa842     PUSH       EAX
    //         004aa843     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              scr_sed.cpp:1622 (2)
    //         004aa848     JMP        LAB_004aa8be
    //                               LAB_004aa84a                                                 XREF[1]:     004aa7dd(j)  
    //                              scr_sed.cpp:1592 (12)
    //         004aa84a     MOV        this,dword ptr [EDI + 0x52c]
    //         004aa850     PUSH       ESI
    //         004aa851     MOV        EDX,dword ptr [this->_padding_]
    //         004aa853     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1593 (12)
    //         004aa856     MOV        this,dword ptr [EDI + 0x530]
    //         004aa85c     PUSH       ESI
    //         004aa85d     MOV        EAX,dword ptr [this->_padding_]
    //         004aa85f     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1595 (12)
    //         004aa862     MOV        this,dword ptr [EDI + 0x534]
    //         004aa868     PUSH       ESI
    //         004aa869     MOV        EDX,dword ptr [this->_padding_]
    //         004aa86b     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1596 (12)
    //         004aa86e     MOV        this,dword ptr [EDI + 0x538]
    //         004aa874     PUSH       ESI
    //         004aa875     MOV        EAX,dword ptr [this->_padding_]
    //         004aa877     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1598 (12)
    //         004aa87a     MOV        this,dword ptr [EDI + 0x544]
    //         004aa880     PUSH       ESI
    //         004aa881     MOV        EDX,dword ptr [this->_padding_]
    //         004aa883     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1599 (6)
    //         004aa886     MOV        this,dword ptr [EDI + 0x548]
    //                              scr_sed.cpp:1600 (2)
    //         004aa88c     JMP        LAB_004aa8b8
    //                               LAB_004aa88e                                                 XREF[1]:     004aa7d6(j)  
    //                              scr_sed.cpp:1603 (12)
    //         004aa88e     MOV        this,dword ptr [EDI + 0x52c]
    //         004aa894     PUSH       ESI
    //         004aa895     MOV        EDX,dword ptr [this->_padding_]
    //         004aa897     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1604 (12)
    //         004aa89a     MOV        this,dword ptr [EDI + 0x530]
    //         004aa8a0     PUSH       ESI
    //         004aa8a1     MOV        EAX,dword ptr [this->_padding_]
    //         004aa8a3     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1606 (12)
    //         004aa8a6     MOV        this,dword ptr [EDI + 0x524]
    //         004aa8ac     PUSH       ESI
    //         004aa8ad     MOV        EDX,dword ptr [this->_padding_]
    //         004aa8af     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1607 (22)
    //         004aa8b2     MOV        this,dword ptr [EDI + 0x528]
    //                               LAB_004aa8b8                                                 XREF[1]:     004aa88c(j)  
    //         004aa8b8     MOV        EAX,dword ptr [this->_padding_]
    //         004aa8ba     PUSH       ESI
    //         004aa8bb     CALL       dword ptr [EAX + 0x14]
    //                               LAB_004aa8be                                                 XREF[3]:     004aa7e0(j), 004aa830(j), 
    //                                                                                                         004aa848(j)  
    //         004aa8be     INC        EBP
    //         004aa8bf     CMP        EBP,0x2
    //         004aa8c2     JL         LAB_004aa7ac
    //                               LAB_004aa8c8                                                 XREF[1]:     004aa7c8(j)  
    //                              scr_sed.cpp:1627 (6)
    //         004aa8c8     MOV        dword ptr [EDI + 0x4a8],EBX
    //                              scr_sed.cpp:1630 (12)
    //         004aa8ce     MOV        this,dword ptr [EDI + EBX*0x4 + 0x504]
    //         004aa8d5     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
    //                              scr_sed.cpp:1633 (13)
    //         004aa8da     MOV        this,dword ptr [EDI + 0x4d4]
    //         004aa8e0     PUSH       0x1
    //         004aa8e2     MOV        EDX,dword ptr [this->_padding_]
    //         004aa8e4     CALL       dword ptr [EDX + 0x20]
    //                               LAB_004aa8e7                                                 XREF[1]:     004aa7bc(j)  
    //                              scr_sed.cpp:1634 (7)
    //         004aa8e7     POP        EDI
    //         004aa8e8     POP        ESI
    //         004aa8e9     POP        EBP
    //         004aa8ea     POP        EBX
    //         004aa8eb     RET        0x8
    //         004aa8ee     ??         90h
    //         004aa8ef     NOP
    //                              * protected: void __thiscall TRIBE_Screen_Sed::set_mp_victory_type(enum TRIBE_Screen_Sed::VictoryTyp... *
    //                              void __thiscall set_mp_victory_type(TRIBE_Screen_Sed * this, Victory
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              VictoryType       Stack[0x4]:4   param_1
    //              int               Stack[0x8]:4   param_2
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004aa8f9(W)  
    //              int               Stack[-0x8]:4  activate_counter
    //                               ?set_mp_victory_type@TRIBE_Screen_Sed@@IAEXW4VictoryType@1@  XREF[4]:     TRIBE_Screen_Sed:004a86b5(c), 
    //                               TRIBE_Screen_Sed::set_mp_victory_type                                     set_scenario_mode:004aa1d4(c), 
    //                                                                                                         set_scenario_mode:004aa1f6(c), 
    //                                                                                                         action:004accac(c)  
    //                              scr_sed.cpp:1640 (4)
    //         004aa8f0     PUSH       this
    //         004aa8f1     PUSH       EBX
    //         004aa8f2     PUSH       EBP
    //         004aa8f3     PUSH       ESI
    //                              scr_sed.cpp:1647 (9)
    //         004aa8f4     XOR        EAX,EAX
    //         004aa8f6     PUSH       EDI
    //         004aa8f7     MOV        EDI,this
    //         004aa8f9     MOV        dword ptr [ESP + local_4],EAX
    //                               LAB_004aa8fd                                                 XREF[1]:     004aaa49(j)  
    //                              scr_sed.cpp:1649 (4)
    //         004aa8fd     TEST       EAX,EAX
    //         004aa8ff     JNZ        LAB_004aa90b
    //                              scr_sed.cpp:1651 (6)
    //         004aa901     MOV        EAX,dword ptr [EDI + 0x4ac]
    //                              scr_sed.cpp:1652 (2)
    //         004aa907     XOR        ESI,ESI
    //                              scr_sed.cpp:1654 (2)
    //         004aa909     JMP        LAB_004aa928
    //                               LAB_004aa90b                                                 XREF[1]:     004aa8ff(j)  
    //                              scr_sed.cpp:1656 (12)
    //         004aa90b     MOV        EAX,dword ptr [ESP + 0x18]
    //         004aa90f     TEST       EAX,EAX
    //         004aa911     JZ         LAB_004aaa74
    //                              scr_sed.cpp:1658 (12)
    //         004aa917     MOV        this,dword ptr [ESP + 0x1c]
    //         004aa91b     TEST       this,this
    //         004aa91d     JZ         LAB_004aaa53
    //                              scr_sed.cpp:1661 (5)
    //         004aa923     MOV        ESI,0x1
    //                               LAB_004aa928                                                 XREF[1]:     004aa909(j)  
    //                              scr_sed.cpp:1664 (17)
    //         004aa928     DEC        EAX
    //         004aa929     CMP        EAX,0x4
    //         004aa92c     JA         switchD_004aa932::caseD_1
    //                               switchD_004aa932::switchD
    //         004aa932     JMP        dword ptr [EAX*0x4 + switchD_004aa932::switchd   = 004aaa3d
    //                               switchD_004aa932::caseD_3                                    XREF[2]:     004aa932(j), 004aaa84(*)  
    //                              scr_sed.cpp:1673 (12)
    //         004aa939     MOV        this,dword ptr [EDI + 0x6f4]
    //         004aa93f     PUSH       ESI
    //         004aa940     MOV        EAX,dword ptr [this->_padding_]
    //         004aa942     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1674 (12)
    //         004aa945     MOV        this,dword ptr [EDI + 0x6f8]
    //         004aa94b     PUSH       ESI
    //         004aa94c     MOV        EDX,dword ptr [this->_padding_]
    //         004aa94e     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1675 (5)
    //         004aa951     JMP        switchD_004aa932::caseD_1
    //                               switchD_004aa932::caseD_4                                    XREF[2]:     004aa932(j), 004aaa88(*)  
    //                              scr_sed.cpp:1678 (12)
    //         004aa956     MOV        this,dword ptr [EDI + 0x6fc]
    //         004aa95c     PUSH       ESI
    //         004aa95d     MOV        EAX,dword ptr [this->_padding_]
    //         004aa95f     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1679 (12)
    //         004aa962     MOV        this,dword ptr [EDI + 0x700]
    //         004aa968     PUSH       ESI
    //         004aa969     MOV        EDX,dword ptr [this->_padding_]
    //         004aa96b     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1680 (5)
    //         004aa96e     JMP        switchD_004aa932::caseD_1
    //                               switchD_004aa932::caseD_5                                    XREF[2]:     004aa932(j), 004aaa8c(*)  
    //                              scr_sed.cpp:1719 (220)
    //         004aa973     LEA        EBX,[EDI + 0x668]
    //         004aa979     MOV        EBP,0x5
    //                               LAB_004aa97e                                                 XREF[1]:     004aa98a(j)  
    //         004aa97e     MOV        this,dword ptr [EBX]
    //         004aa980     PUSH       ESI
    //         004aa981     MOV        EAX,dword ptr [this->_padding_]
    //         004aa983     CALL       dword ptr [EAX + 0x14]
    //         004aa986     ADD        EBX,0x4
    //         004aa989     DEC        EBP
    //         004aa98a     JNZ        LAB_004aa97e
    //         004aa98c     LEA        EBX,[EDI + 0x694]
    //         004aa992     MOV        EBP,0x2
    //                               LAB_004aa997                                                 XREF[1]:     004aa9ac(j)  
    //         004aa997     MOV        this,dword ptr [EBX + -0x14]
    //         004aa99a     PUSH       ESI
    //         004aa99b     MOV        EDX,dword ptr [this->_padding_]
    //         004aa99d     CALL       dword ptr [EDX + 0x14]
    //         004aa9a0     MOV        this,dword ptr [EBX]
    //         004aa9a2     PUSH       ESI
    //         004aa9a3     MOV        EAX,dword ptr [this->_padding_]
    //         004aa9a5     CALL       dword ptr [EAX + 0x14]
    //         004aa9a8     ADD        EBX,0x4
    //         004aa9ab     DEC        EBP
    //         004aa9ac     JNZ        LAB_004aa997
    //         004aa9ae     MOV        this,dword ptr [EDI + 0x68c]
    //         004aa9b4     PUSH       ESI
    //         004aa9b5     MOV        EDX,dword ptr [this->_padding_]
    //         004aa9b7     CALL       dword ptr [EDX + 0x14]
    //         004aa9ba     MOV        this,dword ptr [EDI + 0x69c]
    //         004aa9c0     PUSH       ESI
    //         004aa9c1     MOV        EAX,dword ptr [this->_padding_]
    //         004aa9c3     CALL       dword ptr [EAX + 0x14]
    //         004aa9c6     MOV        this,dword ptr [EDI + 0x6a0]
    //         004aa9cc     PUSH       ESI
    //         004aa9cd     MOV        EDX,dword ptr [this->_padding_]
    //         004aa9cf     CALL       dword ptr [EDX + 0x14]
    //         004aa9d2     MOV        this,dword ptr [EDI + 0x6a8]
    //         004aa9d8     PUSH       ESI
    //         004aa9d9     MOV        EAX,dword ptr [this->_padding_]
    //         004aa9db     CALL       dword ptr [EAX + 0x14]
    //         004aa9de     MOV        this,dword ptr [EDI + 0x6ac]
    //         004aa9e4     PUSH       ESI
    //         004aa9e5     MOV        EDX,dword ptr [this->_padding_]
    //         004aa9e7     CALL       dword ptr [EDX + 0x14]
    //         004aa9ea     MOV        this,dword ptr [EDI + 0x6b0]
    //         004aa9f0     PUSH       ESI
    //         004aa9f1     MOV        EAX,dword ptr [this->_padding_]
    //         004aa9f3     CALL       dword ptr [EAX + 0x14]
    //         004aa9f6     MOV        this,dword ptr [EDI + 0x6b8]
    //         004aa9fc     PUSH       ESI
    //         004aa9fd     MOV        EDX,dword ptr [this->_padding_]
    //         004aa9ff     CALL       dword ptr [EDX + 0x14]
    //         004aaa02     MOV        this,dword ptr [EDI + 0x6bc]
    //         004aaa08     PUSH       ESI
    //         004aaa09     MOV        EAX,dword ptr [this->_padding_]
    //         004aaa0b     CALL       dword ptr [EAX + 0x14]
    //         004aaa0e     MOV        this,dword ptr [EDI + 0x6c0]
    //         004aaa14     PUSH       ESI
    //         004aaa15     MOV        EDX,dword ptr [this->_padding_]
    //         004aaa17     CALL       dword ptr [EDX + 0x14]
    //         004aaa1a     MOV        this,dword ptr [EDI + 0x6c4]
    //         004aaa20     PUSH       ESI
    //         004aaa21     MOV        EAX,dword ptr [this->_padding_]
    //         004aaa23     CALL       dword ptr [EAX + 0x14]
    //         004aaa26     CMP        ESI,0x1
    //         004aaa29     JNZ        switchD_004aa932::caseD_1
    //         004aaa2b     MOV        this,dword ptr [EDI + 0x6b8]
    //         004aaa31     PUSH       this
    //         004aaa32     MOV        this,dword ptr [EDI + 0x4d4]
    //         004aaa38     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                               switchD_004aa932::caseD_2                                    XREF[7]:     004aa92c(j), 004aa932(j), 
    //                               switchD_004aa932::caseD_1                                                 004aa951(j), 004aa96e(j), 
    //                                                                                                         004aaa29(j), 004aaa7c(*), 
    //                                                                                                         004aaa80(*)  
    //         004aaa3d     MOV        EAX,dword ptr [ESP + 0x10]
    //         004aaa41     INC        EAX
    //         004aaa42     CMP        EAX,0x2
    //         004aaa45     MOV        dword ptr [ESP + 0x10],EAX
    //         004aaa49     JL         LAB_004aa8fd
    //                              scr_sed.cpp:1647 (4)
    //         004aaa4f     MOV        EAX,dword ptr [ESP + 0x18]
    //                               LAB_004aaa53                                                 XREF[1]:     004aa91d(j)  
    //                              scr_sed.cpp:1712 (6)
    //         004aaa53     MOV        dword ptr [EDI + 0x4ac],EAX
    //                              scr_sed.cpp:1715 (12)
    //         004aaa59     MOV        this,dword ptr [EDI + EAX*0x4 + 0x6dc]
    //         004aaa60     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
    //                              scr_sed.cpp:1718 (15)
    //         004aaa65     MOV        EDI,dword ptr [EDI + 0x4d4]
    //         004aaa6b     PUSH       0x1
    //         004aaa6d     MOV        this,EDI
    //         004aaa6f     MOV        EDX,dword ptr [EDI]
    //         004aaa71     CALL       dword ptr [EDX + 0x20]
    //                               LAB_004aaa74                                                 XREF[1]:     004aa911(j)  
    //                              scr_sed.cpp:1719 (28)
    //         004aaa74     POP        EDI
    //         004aaa75     POP        ESI
    //         004aaa76     POP        EBP
    //         004aaa77     POP        EBX
    //         004aaa78     POP        this
    //         004aaa79     RET        0x8
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004aa932::switchdataD_004aaa7c                       XREF[1]:     set_mp_victory_type:004aa932(*)  
    //         004aaa7c     addr       switchD_004aa932::caseD_1
    //         004aaa80     addr       switchD_004aa932::caseD_1
    //         004aaa84     addr       switchD_004aa932::caseD_3
    //         004aaa88     addr       switchD_004aa932::caseD_4
    //         004aaa8c     addr       switchD_004aa932::caseD_5
    return;
}

void TRIBE_Screen_Sed::set_brush_size(BrushSize param_1) {
    /* TODO: Stub */
    //                              void __thiscall set_brush_size(TRIBE_Screen_Sed * this, BrushSize pa
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              BrushSize         Stack[0x4]:4   param_1                   XREF[1]:     004aaa90(R)  
    //                               ?set_brush_size@TRIBE_Screen_Sed@@IAEXW4BrushSize@1@@Z       XREF[4]:     TRIBE_Screen_Sed:004a86be(c), 
    //                               TRIBE_Screen_Sed::set_brush_size                                          set_scenario_mode:004a9def(c), 
    //                                                                                                         set_scenario_mode:004a9e0d(c), 
    //                                                                                                         action:004ac8ba(c)  
    //                              scr_sed.cpp:1725 (15)
    //         004aaa90     MOV        EAX,dword ptr [ESP + param_1]
    //         004aaa94     PUSH       ESI
    //         004aaa95     TEST       EAX,EAX
    //         004aaa97     MOV        ESI,this
    //         004aaa99     JZ         LAB_004aab46
    //                              scr_sed.cpp:1732 (6)
    //         004aaa9f     MOV        dword ptr [ESI + 0x4b0],EAX
    //                              scr_sed.cpp:1735 (12)
    //         004aaaa5     MOV        this,dword ptr [ESI + EAX*0x4 + 0x554]
    //         004aaaac     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
    //                              scr_sed.cpp:1737 (21)
    //         004aaab1     MOV        ESI,dword ptr [ESI + 0x4b0]
    //         004aaab7     LEA        EAX,[ESI + -0x1]
    //         004aaaba     CMP        EAX,0x4
    //         004aaabd     JA         switchD_004aaabf::default
    //                               switchD_004aaabf::switchD
    //         004aaabf     JMP        dword ptr [EAX*0x4 + switchD_004aaabf::switchd   = 004aaac6
    //                               switchD_004aaabf::caseD_1                                    XREF[2]:     004aaabf(j), 004aab4c(*)  
    //                              scr_sed.cpp:1746 (18)
    //         004aaac6     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004aaacc     MOV        EAX,0x1
    //         004aaad1     MOV        word ptr [ECX + this+0x402],AX
    //                              scr_sed.cpp:1749 (4)
    //         004aaad8     POP        ESI
    //         004aaad9     RET        0x4
    //                               switchD_004aaabf::caseD_2                                    XREF[2]:     004aaabf(j), 004aab50(*)  
    //                              scr_sed.cpp:1746 (18)
    //         004aaadc     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004aaae2     MOV        EAX,0x3
    //         004aaae7     MOV        word ptr [ECX + this+0x402],AX
    //                              scr_sed.cpp:1749 (4)
    //         004aaaee     POP        ESI
    //         004aaaef     RET        0x4
    //                               switchD_004aaabf::caseD_3                                    XREF[2]:     004aaabf(j), 004aab54(*)  
    //                              scr_sed.cpp:1746 (18)
    //         004aaaf2     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004aaaf8     MOV        EAX,0x5
    //         004aaafd     MOV        word ptr [ECX + this+0x402],AX
    //                              scr_sed.cpp:1749 (4)
    //         004aab04     POP        ESI
    //         004aab05     RET        0x4
    //                               switchD_004aaabf::caseD_4                                    XREF[2]:     004aaabf(j), 004aab58(*)  
    //                              scr_sed.cpp:1746 (18)
    //         004aab08     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004aab0e     MOV        EAX,0x7
    //         004aab13     MOV        word ptr [ECX + this+0x402],AX
    //                              scr_sed.cpp:1749 (4)
    //         004aab1a     POP        ESI
    //         004aab1b     RET        0x4
    //                               switchD_004aaabf::caseD_5                                    XREF[2]:     004aaabf(j), 004aab5c(*)  
    //                              scr_sed.cpp:1746 (18)
    //         004aab1e     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004aab24     MOV        EAX,0x9
    //         004aab29     MOV        word ptr [ECX + this+0x402],AX
    //                              scr_sed.cpp:1749 (4)
    //         004aab30     POP        ESI
    //         004aab31     RET        0x4
    //                               switchD_004aaabf::default                                    XREF[1]:     004aaabd(j)  
    //                              scr_sed.cpp:1746 (18)
    //         004aab34     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004aab3a     MOV        EAX,0x2
    //         004aab3f     MOV        word ptr [ECX + this+0x402],AX
    //                               LAB_004aab46                                                 XREF[1]:     004aaa99(j)  
    //                              scr_sed.cpp:1749 (26)
    //         004aab46     POP        ESI
    //         004aab47     RET        0x4
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_004aab4a()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_004aab4a
    //         004aab4a     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004aaabf::switchdataD_004aab4c                       XREF[1]:     set_brush_size:004aaabf(*)  
    //         004aab4c     addr       switchD_004aaabf::caseD_1
    //         004aab50     addr       switchD_004aaabf::caseD_2
    //         004aab54     addr       switchD_004aaabf::caseD_3
    //         004aab58     addr       switchD_004aaabf::caseD_4
    //         004aab5c     addr       switchD_004aaabf::caseD_5
    return;
}

void TRIBE_Screen_Sed::set_paint_type(PaintType param_1, int param_2) {
    /* TODO: Stub */
    //                              void __thiscall set_paint_type(TRIBE_Screen_Sed * this, PaintType pa
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              PaintType         Stack[0x4]:4   param_1
    //              int               Stack[0x8]:4   param_2
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004aab81(W)  
    //              PaintType         Stack[-0x8]:4  val                       XREF[2]:     004aab69(W), 004aab71(R)  
    //              int               Stack[-0xc]:4  activate_counter
    //                               ?set_paint_type@TRIBE_Screen_Sed@@IAEXW4PaintType@1@H@Z      XREF[4]:     TRIBE_Screen_Sed:004a86c8(c), 
    //                               TRIBE_Screen_Sed::set_paint_type                                          set_scenario_mode:004a9dff(c), 
    //                                                                                                         set_scenario_mode:004a9e18(c), 
    //                                                                                                         action:004ac8e4(c)  
    //                              scr_sed.cpp:1755 (9)
    //         004aab60     SUB        ESP,0x8
    //         004aab63     PUSH       EBX
    //         004aab64     PUSH       EBP
    //         004aab65     PUSH       ESI
    //         004aab66     PUSH       EDI
    //         004aab67     MOV        ESI,this
    //                              scr_sed.cpp:1761 (8)
    //         004aab69     MOV        dword ptr [ESP + val],0x0
    //                               LAB_004aab71                                                 XREF[1]:     004aad11(j)  
    //                              scr_sed.cpp:1763 (8)
    //         004aab71     MOV        EAX,dword ptr [ESP + val]
    //         004aab75     TEST       EAX,EAX
    //         004aab77     JNZ        LAB_004aab87
    //                              scr_sed.cpp:1765 (6)
    //         004aab79     MOV        EAX,dword ptr [ESI + 0x4b4]
    //                              scr_sed.cpp:1766 (6)
    //         004aab7f     XOR        EDI,EDI
    //         004aab81     MOV        dword ptr [ESP + local_4],EAX
    //                              scr_sed.cpp:1768 (2)
    //         004aab85     JMP        LAB_004aaba8
    //                               LAB_004aab87                                                 XREF[1]:     004aab77(j)  
    //                              scr_sed.cpp:1770 (12)
    //         004aab87     MOV        EAX,dword ptr [ESP + 0x1c]
    //         004aab8b     TEST       EAX,EAX
    //         004aab8d     JZ         LAB_004aad3c
    //                              scr_sed.cpp:1772 (12)
    //         004aab93     MOV        this,dword ptr [ESP + 0x20]
    //         004aab97     TEST       this,this
    //         004aab99     JZ         LAB_004aad1b
    //                              scr_sed.cpp:1774 (4)
    //         004aab9f     MOV        dword ptr [ESP + 0x14],EAX
    //                              scr_sed.cpp:1775 (5)
    //         004aaba3     MOV        EDI,0x1
    //                               LAB_004aaba8                                                 XREF[1]:     004aab85(j)  
    //                              scr_sed.cpp:1777 (23)
    //         004aaba8     MOV        this,dword ptr [ESI + 0x554]
    //         004aabae     PUSH       EDI
    //         004aabaf     MOV        EDX,dword ptr [this->_padding_]
    //         004aabb1     CALL       dword ptr [EDX + 0x14]
    //         004aabb4     LEA        EBX,[ESI + 0x56c]
    //         004aabba     MOV        EBP,0x5
    //                               LAB_004aabbf                                                 XREF[1]:     004aabd4(j)  
    //                              scr_sed.cpp:1780 (9)
    //         004aabbf     MOV        this,dword ptr [EBX + -0x14]
    //         004aabc2     PUSH       EDI
    //         004aabc3     MOV        EAX,dword ptr [this->_padding_]
    //         004aabc5     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1781 (14)
    //         004aabc8     MOV        this,dword ptr [EBX]
    //         004aabca     PUSH       EDI
    //         004aabcb     MOV        EDX,dword ptr [this->_padding_]
    //         004aabcd     CALL       dword ptr [EDX + 0x14]
    //         004aabd0     ADD        EBX,0x4
    //         004aabd3     DEC        EBP
    //         004aabd4     JNZ        LAB_004aabbf
    //                              scr_sed.cpp:1783 (25)
    //         004aabd6     MOV        EAX,dword ptr [ESP + 0x14]
    //         004aabda     DEC        EAX
    //         004aabdb     JZ         LAB_004aacb6
    //         004aabe1     DEC        EAX
    //         004aabe2     JZ         LAB_004aac76
    //         004aabe8     DEC        EAX
    //         004aabe9     JNZ        LAB_004aad05
    //                              scr_sed.cpp:1810 (13)
    //         004aabef     MOV        this,dword ptr [ESI + 0x5a8]
    //         004aabf5     PUSH       0x0
    //         004aabf7     MOV        EAX,dword ptr [this->_padding_]
    //         004aabf9     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1811 (13)
    //         004aabfc     MOV        this,dword ptr [ESI + 0x5a0]
    //         004aac02     PUSH       0x0
    //         004aac04     MOV        EDX,dword ptr [this->_padding_]
    //         004aac06     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1812 (13)
    //         004aac09     MOV        this,dword ptr [ESI + 0x59c]
    //         004aac0f     PUSH       0x0
    //         004aac11     MOV        EAX,dword ptr [this->_padding_]
    //         004aac13     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1813 (13)
    //         004aac16     MOV        this,dword ptr [ESI + 0x554]
    //         004aac1c     PUSH       0x0
    //         004aac1e     MOV        EDX,dword ptr [this->_padding_]
    //         004aac20     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1838 (36)
    //         004aac23     LEA        EBX,[ESI + 0x56c]
    //         004aac29     MOV        EBP,0x5
    //                               LAB_004aac2e                                                 XREF[1]:     004aac45(j)  
    //         004aac2e     MOV        this,dword ptr [EBX + -0x14]
    //         004aac31     PUSH       0x0
    //         004aac33     MOV        EAX,dword ptr [this->_padding_]
    //         004aac35     CALL       dword ptr [EAX + 0x14]
    //         004aac38     MOV        this,dword ptr [EBX]
    //         004aac3a     PUSH       0x0
    //         004aac3c     MOV        EDX,dword ptr [this->_padding_]
    //         004aac3e     CALL       dword ptr [EDX + 0x14]
    //         004aac41     ADD        EBX,0x4
    //         004aac44     DEC        EBP
    //         004aac45     JNZ        LAB_004aac2e
    //                              scr_sed.cpp:1819 (8)
    //         004aac47     TEST       EDI,EDI
    //         004aac49     JZ         LAB_004aacf6
    //                              scr_sed.cpp:1821 (19)
    //         004aac4f     MOV        this,dword ptr [ESI + 0x5a8]
    //         004aac55     CALL       TTextPanel::currentLineNumber                    int currentLineNumber(TTextPanel * this)
    //         004aac5a     PUSH       EAX
    //         004aac5b     MOV        this,ESI
    //         004aac5d     CALL       TRIBE_Screen_Sed::set_elevation                  void set_elevation(TRIBE_Screen_Sed * this, s
    //                              scr_sed.cpp:1822 (20)
    //         004aac62     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004aac68     PUSH       0x0
    //         004aac6a     PUSH       0x13
    //         004aac6c     MOV        EAX,dword ptr [this->_padding_]
    //         004aac6e     CALL       dword ptr [EAX + 0x10]
    //         004aac71     JMP        LAB_004aad05
    //                               LAB_004aac76                                                 XREF[1]:     004aabe2(j)  
    //                              scr_sed.cpp:1798 (12)
    //         004aac76     MOV        this,dword ptr [ESI + 0x5a8]
    //         004aac7c     PUSH       EDI
    //         004aac7d     MOV        EAX,dword ptr [this->_padding_]
    //         004aac7f     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1799 (12)
    //         004aac82     MOV        this,dword ptr [ESI + 0x59c]
    //         004aac88     PUSH       EDI
    //         004aac89     MOV        EDX,dword ptr [this->_padding_]
    //         004aac8b     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1800 (4)
    //         004aac8e     TEST       EDI,EDI
    //         004aac90     JZ         LAB_004aacf6
    //                              scr_sed.cpp:1802 (19)
    //         004aac92     MOV        this,dword ptr [ESI + 0x5a8]
    //         004aac98     CALL       TTextPanel::currentLineNumber                    int currentLineNumber(TTextPanel * this)
    //         004aac9d     PUSH       EAX
    //         004aac9e     MOV        this,ESI
    //         004aaca0     CALL       TRIBE_Screen_Sed::set_elevation                  void set_elevation(TRIBE_Screen_Sed * this, s
    //                              scr_sed.cpp:1803 (17)
    //         004aaca5     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004aacab     PUSH       0x0
    //         004aacad     PUSH       0xa
    //         004aacaf     MOV        EAX,dword ptr [this->_padding_]
    //         004aacb1     CALL       dword ptr [EAX + 0x10]
    //         004aacb4     JMP        LAB_004aad05
    //                               LAB_004aacb6                                                 XREF[1]:     004aabdb(j)  
    //                              scr_sed.cpp:1786 (12)
    //         004aacb6     MOV        this,dword ptr [ESI + 0x5a0]
    //         004aacbc     PUSH       EDI
    //         004aacbd     MOV        EAX,dword ptr [this->_padding_]
    //         004aacbf     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1787 (12)
    //         004aacc2     MOV        this,dword ptr [ESI + 0x59c]
    //         004aacc8     PUSH       EDI
    //         004aacc9     MOV        EDX,dword ptr [this->_padding_]
    //         004aaccb     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:1788 (4)
    //         004aacce     TEST       EDI,EDI
    //         004aacd0     JZ         LAB_004aacf6
    //                              scr_sed.cpp:1790 (19)
    //         004aacd2     MOV        this,dword ptr [ESI + 0x5a0]
    //         004aacd8     CALL       TTextPanel::currentLineNumber                    int currentLineNumber(TTextPanel * this)
    //         004aacdd     PUSH       EAX
    //         004aacde     MOV        this,ESI
    //         004aace0     CALL       TRIBE_Screen_Sed::set_terrain                    void set_terrain(TRIBE_Screen_Sed * this, sho
    //                              scr_sed.cpp:1791 (15)
    //         004aace5     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004aaceb     PUSH       0x0
    //         004aaced     PUSH       0x9
    //         004aacef     MOV        EAX,dword ptr [this->_padding_]
    //         004aacf1     CALL       dword ptr [EAX + 0x10]
    //                              scr_sed.cpp:1793 (2)
    //         004aacf4     JMP        LAB_004aad05
    //                               LAB_004aacf6                                                 XREF[3]:     004aac49(j), 004aac90(j), 
    //                                                                                                         004aacd0(j)  
    //                              scr_sed.cpp:1794 (33)
    //         004aacf6     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004aacfc     PUSH       0x0
    //         004aacfe     PUSH       0x0
    //         004aad00     MOV        EDX,dword ptr [this->_padding_]
    //         004aad02     CALL       dword ptr [EDX + 0x10]
    //                               LAB_004aad05                                                 XREF[4]:     004aabe9(j), 004aac71(j), 
    //                                                                                                         004aacb4(j), 004aacf4(j)  
    //         004aad05     MOV        EAX,dword ptr [ESP + 0x10]
    //         004aad09     INC        EAX
    //         004aad0a     CMP        EAX,0x2
    //         004aad0d     MOV        dword ptr [ESP + 0x10],EAX
    //         004aad11     JL         LAB_004aab71
    //                              scr_sed.cpp:1761 (4)
    //         004aad17     MOV        EAX,dword ptr [ESP + 0x1c]
    //                               LAB_004aad1b                                                 XREF[1]:     004aab99(j)  
    //                              scr_sed.cpp:1831 (6)
    //         004aad1b     MOV        dword ptr [ESI + 0x4b4],EAX
    //                              scr_sed.cpp:1834 (12)
    //         004aad21     MOV        this,dword ptr [ESI + EAX*0x4 + 0x580]
    //         004aad28     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
    //                              scr_sed.cpp:1837 (15)
    //         004aad2d     MOV        ESI,dword ptr [ESI + 0x4d4]
    //         004aad33     PUSH       0x1
    //         004aad35     MOV        this,ESI
    //         004aad37     MOV        EAX,dword ptr [ESI]
    //         004aad39     CALL       dword ptr [EAX + 0x20]
    //                               LAB_004aad3c                                                 XREF[1]:     004aab8d(j)  
    //                              scr_sed.cpp:1838 (10)
    //         004aad3c     POP        EDI
    //         004aad3d     POP        ESI
    //         004aad3e     POP        EBP
    //         004aad3f     POP        EBX
    //         004aad40     ADD        ESP,0x8
    //         004aad43     RET        0x8
    //         004aad46     ??         90h
    //         004aad47     NOP
    //         004aad48     NOP
    //         004aad49     NOP
    //         004aad4a     NOP
    //         004aad4b     NOP
    //         004aad4c     NOP
    //         004aad4d     NOP
    //         004aad4e     NOP
    //         004aad4f     NOP
    return;
}

void TRIBE_Screen_Sed::set_terrain(short param_1) {
    /* TODO: Stub */
    //                              void __thiscall set_terrain(TRIBE_Screen_Sed * this, short param_1)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     004aad51(R)  
    //                               ?set_terrain@TRIBE_Screen_Sed@@IAEXF@Z                       XREF[2]:     set_paint_type:004aace0(c), 
    //                               TRIBE_Screen_Sed::set_terrain                                             action:004ac851(c)  
    //                              scr_sed.cpp:1844 (1)
    //         004aad50     PUSH       ESI
    //                              scr_sed.cpp:1846 (19)
    //         004aad51     MOV        ESI,dword ptr [ESP + param_1]
    //         004aad55     MOVSX      EAX,SI
    //         004aad58     CMP        EAX,0x8
    //         004aad5b     JA         switchD_004aad5d::caseD_0
    //                               switchD_004aad5d::switchD
    //         004aad5d     JMP        dword ptr [EAX*0x4 + switchD_004aad5d::switchd   = 004aad9c
    //                               switchD_004aad5d::caseD_1                                    XREF[2]:     004aad5d(j), 004aadc4(*)  
    //                              scr_sed.cpp:1849 (7)
    //         004aad64     MOV        EAX,0x6
    //         004aad69     JMP        LAB_004aad9e
    //                               switchD_004aad5d::caseD_2                                    XREF[2]:     004aad5d(j), 004aadc8(*)  
    //                              scr_sed.cpp:1850 (7)
    //         004aad6b     MOV        EAX,0xa
    //         004aad70     JMP        LAB_004aad9e
    //                               switchD_004aad5d::caseD_3                                    XREF[2]:     004aad5d(j), 004aadcc(*)  
    //                              scr_sed.cpp:1851 (7)
    //         004aad72     MOV        EAX,0x1
    //         004aad77     JMP        LAB_004aad9e
    //                               switchD_004aad5d::caseD_4                                    XREF[2]:     004aad5d(j), 004aadd0(*)  
    //                              scr_sed.cpp:1852 (7)
    //         004aad79     MOV        EAX,0xd
    //         004aad7e     JMP        LAB_004aad9e
    //                               switchD_004aad5d::caseD_5                                    XREF[2]:     004aad5d(j), 004aadd4(*)  
    //                              scr_sed.cpp:1853 (7)
    //         004aad80     MOV        EAX,0x14
    //         004aad85     JMP        LAB_004aad9e
    //                               switchD_004aad5d::caseD_6                                    XREF[2]:     004aad5d(j), 004aadd8(*)  
    //                              scr_sed.cpp:1854 (7)
    //         004aad87     MOV        EAX,0x4
    //         004aad8c     JMP        LAB_004aad9e
    //                               switchD_004aad5d::caseD_7                                    XREF[2]:     004aad5d(j), 004aaddc(*)  
    //                              scr_sed.cpp:1855 (7)
    //         004aad8e     MOV        EAX,0x13
    //         004aad93     JMP        LAB_004aad9e
    //                               switchD_004aad5d::caseD_8                                    XREF[2]:     004aad5d(j), 004aade0(*)  
    //                              scr_sed.cpp:1856 (7)
    //         004aad95     MOV        EAX,0x16
    //         004aad9a     JMP        LAB_004aad9e
    //                               switchD_004aad5d::caseD_0                                    XREF[3]:     004aad5b(j), 004aad5d(j), 
    //                                                                                                         004aadc0(*)  
    //                              scr_sed.cpp:1857 (2)
    //         004aad9c     XOR        EAX,EAX
    //                               LAB_004aad9e                                                 XREF[8]:     004aad69(j), 004aad70(j), 
    //                                                                                                         004aad77(j), 004aad7e(j), 
    //                                                                                                         004aad85(j), 004aad8c(j), 
    //                                                                                                         004aad93(j), 004aad9a(j)  
    //                              scr_sed.cpp:1859 (6)
    //         004aad9e     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //                              scr_sed.cpp:1861 (23)
    //         004aada4     PUSH       0x1
    //         004aada6     PUSH       ESI
    //         004aada7     PUSH       0x1
    //         004aada9     MOV        word ptr [EDX + 0x3fe],AX
    //         004aadb0     MOV        this,dword ptr [ECX + this->paint_terrain_list]
    //         004aadb6     CALL       TListPanel::scroll_cur_line                      void scroll_cur_line(TListPanel * this, uchar
    //                              scr_sed.cpp:1862 (41)
    //         004aadbb     POP        ESI
    //         004aadbc     RET        0x4
    //         004aadbf     ??         90h
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004aad5d::switchdataD_004aadc0                       XREF[1]:     set_terrain:004aad5d(*)  
    //         004aadc0     addr       switchD_004aad5d::caseD_0
    //         004aadc4     addr       switchD_004aad5d::caseD_1
    //         004aadc8     addr       switchD_004aad5d::caseD_2
    //         004aadcc     addr       switchD_004aad5d::caseD_3
    //         004aadd0     addr       switchD_004aad5d::caseD_4
    //         004aadd4     addr       switchD_004aad5d::caseD_5
    //         004aadd8     addr       switchD_004aad5d::caseD_6
    //         004aaddc     addr       switchD_004aad5d::caseD_7
    //         004aade0     addr       switchD_004aad5d::caseD_8
    //         004aade4     ??         90h
    //         004aade5     ??         90h
    //         004aade6     ??         90h
    //         004aade7     ??         90h
    //         004aade8     ??         90h
    //         004aade9     ??         90h
    //         004aadea     ??         90h
    //         004aadeb     ??         90h
    //         004aadec     ??         90h
    //         004aaded     ??         90h
    //         004aadee     ??         90h
    //         004aadef     ??         90h
    return;
}

void TRIBE_Screen_Sed::set_elevation(short param_1) {
    /* TODO: Stub */
    //                              void __thiscall set_elevation(TRIBE_Screen_Sed * this, short param_1)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     004aadf5(R)  
    //                               ?set_elevation@TRIBE_Screen_Sed@@IAEXF@Z                     XREF[3]:     set_paint_type:004aac5d(c), 
    //                               TRIBE_Screen_Sed::set_elevation                                           set_paint_type:004aaca0(c), 
    //                                                                                                         action:004ac87c(c)  
    //                              scr_sed.cpp:1868 (9)
    //         004aadf0     MOV        EAX,[rge_base_game]                              = 00000000
    //         004aadf5     MOV        EDX,dword ptr [ESP + param_1]
    //                              scr_sed.cpp:1871 (23)
    //         004aadf9     PUSH       0x1
    //         004aadfb     PUSH       EDX
    //         004aadfc     MOV        word ptr [EAX + 0x400],DX
    //         004aae03     MOV        this,dword ptr [ECX + this->paint_elevation_li
    //         004aae09     PUSH       0x1
    //         004aae0b     CALL       TListPanel::scroll_cur_line                      void scroll_cur_line(TListPanel * this, uchar
    //                              scr_sed.cpp:1872 (3)
    //         004aae10     RET        0x4
    //         004aae13     ??         90h
    //         004aae14     NOP
    //         004aae15     NOP
    //         004aae16     NOP
    //         004aae17     NOP
    //         004aae18     NOP
    //         004aae19     NOP
    //         004aae1a     NOP
    //         004aae1b     NOP
    //         004aae1c     NOP
    //         004aae1d     NOP
    //         004aae1e     NOP
    //         004aae1f     NOP
    return;
}

void TRIBE_Screen_Sed::set_player(short param_1, uchar param_2, uchar param_3) {
    /* TODO: Stub */
    //                              void __thiscall set_player(TRIBE_Screen_Sed * this, short param_1, u
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     004ab00e(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[9]:     004aae46(R), 004aae66(W), 004aae87(R), 004aaeaa(W), 
    //                                                                                     004aaecb(R), 004aaeef(W), 004aaf10(R), 004aaf34(W), 
    //                                                                                     004aaf55(R)  
    //              uchar             Stack[0xc]:1   param_3
    //              char[30]          Stack[-0x24]   str
    //                               ?set_player@TRIBE_Screen_Sed@@IAEXFEE@Z                      XREF[10]:    TRIBE_Screen_Sed:004a86d3(c), 
    //                               TRIBE_Screen_Sed::set_player                                              set_scenario_mode:004a9eb3(c), 
    //                                                                                                         set_scenario_mode:004a9ee2(c), 
    //                                                                                                         set_scenario_mode:004aa0e7(c), 
    //                                                                                                         key_down_action:004aba30(c), 
    //                                                                                                         key_down_action:004abb3f(c), 
    //                                                                                                         action:004ac993(c), 
    //                                                                                                         action:004ac9d4(c), 
    //                                                                                                         action:004ac9ee(c), 
    //                                                                                                         SavePlayerActiveStatus:004b2d63(c)
    //                              scr_sed.cpp:1878 (8)
    //         004aae20     SUB        ESP,0x20
    //         004aae23     PUSH       EBX
    //         004aae24     PUSH       ESI
    //         004aae25     MOV        ESI,this
    //         004aae27     PUSH       EDI
    //                              scr_sed.cpp:1886 (8)
    //         004aae28     MOVSX      EDI,word ptr [ESI + 0x4b8]
    //         004aae2f     DEC        EDI
    //                              scr_sed.cpp:1887 (2)
    //         004aae30     JNS        LAB_004aae34
    //                              scr_sed.cpp:1888 (2)
    //         004aae32     XOR        EDI,EDI
    //                               LAB_004aae34                                                 XREF[1]:     004aae30(j)  
    //                              scr_sed.cpp:1890 (18)
    //         004aae34     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004aae3a     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004aae3f     MOV        this,EAX
    //         004aae41     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
    //                              scr_sed.cpp:1895 (12)
    //         004aae46     MOV        AL,byte ptr [ESP + param_2]
    //         004aae4a     TEST       AL,AL
    //         004aae4c     JZ         LAB_004ab00e
    //                              scr_sed.cpp:1897 (24)
    //         004aae52     MOV        this,dword ptr [ESI + 0x5d8]
    //         004aae58     CALL       TEditPanel::currentLine                          char * currentLine(TEditPanel * this)
    //         004aae5d     PUSH       EAX
    //         004aae5e     CALL       atoi                                             undefined atoi()
    //         004aae63     ADD        ESP,0x4
    //         004aae66     MOV        dword ptr [ESP + param_2],EAX
    //                              scr_sed.cpp:1898 (16)
    //         004aae6a     PUSH       EAX
    //         004aae6b     MOV        EAX,dword ptr [ESI + 0x928]
    //         004aae71     PUSH       EDI
    //         004aae72     MOV        this,dword ptr [EAX + 0x5c]
    //         004aae75     CALL       T_Scenario::Set_player_Food                      void Set_player_Food(T_Scenario * this, int p
    //                              scr_sed.cpp:1899 (28)
    //         004aae7a     MOV        EDX,dword ptr [ESI + 0x928]
    //         004aae80     MOVSX      this,word ptr [ESI + 0x4b8]
    //         004aae87     FILD       dword ptr [ESP + param_2]
    //         004aae8b     MOV        EAX,dword ptr [EDX + 0x40]
    //         004aae8e     MOV        this,dword ptr [EAX + this->_padding_*0x4]
    //         004aae91     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004aae94     FSTP       float ptr [EDX]
    //                              scr_sed.cpp:1901 (24)
    //         004aae96     MOV        this,dword ptr [ESI + 0x5dc]
    //         004aae9c     CALL       TEditPanel::currentLine                          char * currentLine(TEditPanel * this)
    //         004aaea1     PUSH       EAX
    //         004aaea2     CALL       atoi                                             undefined atoi()
    //         004aaea7     ADD        ESP,0x4
    //         004aaeaa     MOV        dword ptr [ESP + param_2],EAX
    //                              scr_sed.cpp:1902 (16)
    //         004aaeae     PUSH       EAX
    //         004aaeaf     MOV        EAX,dword ptr [ESI + 0x928]
    //         004aaeb5     PUSH       EDI
    //         004aaeb6     MOV        this,dword ptr [EAX + 0x5c]
    //         004aaeb9     CALL       T_Scenario::Set_player_Wood                      void Set_player_Wood(T_Scenario * this, int p
    //                              scr_sed.cpp:1903 (29)
    //         004aaebe     MOV        EDX,dword ptr [ESI + 0x928]
    //         004aaec4     MOVSX      this,word ptr [ESI + 0x4b8]
    //         004aaecb     FILD       dword ptr [ESP + param_2]
    //         004aaecf     MOV        EAX,dword ptr [EDX + 0x40]
    //         004aaed2     MOV        this,dword ptr [EAX + this->_padding_*0x4]
    //         004aaed5     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004aaed8     FSTP       float ptr [EDX + 0x4]
    //                              scr_sed.cpp:1905 (24)
    //         004aaedb     MOV        this,dword ptr [ESI + 0x5e0]
    //         004aaee1     CALL       TEditPanel::currentLine                          char * currentLine(TEditPanel * this)
    //         004aaee6     PUSH       EAX
    //         004aaee7     CALL       atoi                                             undefined atoi()
    //         004aaeec     ADD        ESP,0x4
    //         004aaeef     MOV        dword ptr [ESP + param_2],EAX
    //                              scr_sed.cpp:1906 (16)
    //         004aaef3     PUSH       EAX
    //         004aaef4     MOV        EAX,dword ptr [ESI + 0x928]
    //         004aaefa     PUSH       EDI
    //         004aaefb     MOV        this,dword ptr [EAX + 0x5c]
    //         004aaefe     CALL       T_Scenario::Set_player_Stone                     void Set_player_Stone(T_Scenario * this, int 
    //                              scr_sed.cpp:1907 (29)
    //         004aaf03     MOV        EDX,dword ptr [ESI + 0x928]
    //         004aaf09     MOVSX      this,word ptr [ESI + 0x4b8]
    //         004aaf10     FILD       dword ptr [ESP + param_2]
    //         004aaf14     MOV        EAX,dword ptr [EDX + 0x40]
    //         004aaf17     MOV        this,dword ptr [EAX + this->_padding_*0x4]
    //         004aaf1a     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004aaf1d     FSTP       float ptr [EDX + 0x8]
    //                              scr_sed.cpp:1909 (24)
    //         004aaf20     MOV        this,dword ptr [ESI + 0x5e4]
    //         004aaf26     CALL       TEditPanel::currentLine                          char * currentLine(TEditPanel * this)
    //         004aaf2b     PUSH       EAX
    //         004aaf2c     CALL       atoi                                             undefined atoi()
    //         004aaf31     ADD        ESP,0x4
    //         004aaf34     MOV        dword ptr [ESP + param_2],EAX
    //                              scr_sed.cpp:1910 (16)
    //         004aaf38     PUSH       EAX
    //         004aaf39     MOV        EAX,dword ptr [ESI + 0x928]
    //         004aaf3f     PUSH       EDI
    //         004aaf40     MOV        this,dword ptr [EAX + 0x5c]
    //         004aaf43     CALL       T_Scenario::Set_player_Gold                      void Set_player_Gold(T_Scenario * this, int p
    //                              scr_sed.cpp:1911 (29)
    //         004aaf48     MOV        EDX,dword ptr [ESI + 0x928]
    //         004aaf4e     MOVSX      this,word ptr [ESI + 0x4b8]
    //         004aaf55     FILD       dword ptr [ESP + param_2]
    //         004aaf59     MOV        EAX,dword ptr [EDX + 0x40]
    //         004aaf5c     MOV        this,dword ptr [EAX + this->_padding_*0x4]
    //         004aaf5f     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004aaf62     FSTP       float ptr [EDX + 0xc]
    //                              scr_sed.cpp:1913 (27)
    //         004aaf65     MOV        this,dword ptr [ESI + 0x5e8]
    //         004aaf6b     CALL       TEditPanel::currentLine                          char * currentLine(TEditPanel * this)
    //         004aaf70     PUSH       EAX
    //         004aaf71     MOV        EAX,dword ptr [ESI + 0x928]
    //         004aaf77     PUSH       EDI
    //         004aaf78     MOV        this,dword ptr [EAX + 0x5c]
    //         004aaf7b     CALL       RGE_Scenario::SetPlayerName                      void SetPlayerName(RGE_Scenario * this, int p
    //                              scr_sed.cpp:1916 (11)
    //         004aaf80     MOV        this,dword ptr [ESI + 0x5f8]
    //         004aaf86     CALL       TDropDownPanel::currentLineNumber                int currentLineNumber(TDropDownPanel * this)
    //                              scr_sed.cpp:1917 (16)
    //         004aaf8b     MOV        this,dword ptr [ESI + 0x928]
    //         004aaf91     PUSH       EAX
    //         004aaf92     PUSH       EDI
    //         004aaf93     MOV        this,dword ptr [ECX + this->_padding_]
    //         004aaf96     CALL       RGE_Scenario::Set_player_Type                    void Set_player_Type(RGE_Scenario * this, int
    //                              scr_sed.cpp:1920 (11)
    //         004aaf9b     MOV        this,dword ptr [ESI + 0x5fc]
    //         004aafa1     CALL       TDropDownPanel::currentLineNumber                int currentLineNumber(TDropDownPanel * this)
    //                              scr_sed.cpp:1921 (17)
    //         004aafa6     MOV        EDX,dword ptr [ESI + 0x928]
    //         004aafac     INC        EAX
    //         004aafad     PUSH       EAX
    //         004aafae     PUSH       EDI
    //         004aafaf     MOV        this,dword ptr [EDX + 0x5c]
    //         004aafb2     CALL       RGE_Scenario::Set_player_Civ                     void Set_player_Civ(RGE_Scenario * this, int 
    //                              scr_sed.cpp:1925 (29)
    //         004aafb7     MOV        this,dword ptr [ESI + 0x608]
    //         004aafbd     PUSH       0x0
    //         004aafbf     CALL       TDropDownPanel::currentLine                      char * currentLine(TDropDownPanel * this)
    //         004aafc4     PUSH       EAX
    //         004aafc5     MOV        EAX,dword ptr [ESI + 0x928]
    //         004aafcb     PUSH       EDI
    //         004aafcc     MOV        this,dword ptr [EAX + 0x5c]
    //         004aafcf     CALL       RGE_Scenario::Set_player_AI                      void Set_player_AI(RGE_Scenario * this, int p
    //                              scr_sed.cpp:1926 (29)
    //         004aafd4     MOV        this,dword ptr [ESI + 0x600]
    //         004aafda     PUSH       0x0
    //         004aafdc     CALL       TDropDownPanel::currentLine                      char * currentLine(TDropDownPanel * this)
    //         004aafe1     MOV        this,dword ptr [ESI + 0x928]
    //         004aafe7     PUSH       EAX
    //         004aafe8     PUSH       EDI
    //         004aafe9     MOV        this,dword ptr [ECX + this->_padding_]
    //         004aafec     CALL       RGE_Scenario::Set_BuildList                      void Set_BuildList(RGE_Scenario * this, int p
    //                              scr_sed.cpp:1927 (29)
    //         004aaff1     MOV        this,dword ptr [ESI + 0x604]
    //         004aaff7     PUSH       0x0
    //         004aaff9     CALL       TDropDownPanel::currentLine                      char * currentLine(TDropDownPanel * this)
    //         004aaffe     MOV        EDX,dword ptr [ESI + 0x928]
    //         004ab004     PUSH       EAX
    //         004ab005     PUSH       EDI
    //         004ab006     MOV        this,dword ptr [EDX + 0x5c]
    //         004ab009     CALL       RGE_Scenario::Set_CityPlan                       void Set_CityPlan(RGE_Scenario * this, int pa
    //                               LAB_004ab00e                                                 XREF[1]:     004aae4c(j)  
    //                              scr_sed.cpp:1931 (4)
    //         004ab00e     MOV        EBX,dword ptr [ESP + param_1]
    //                              scr_sed.cpp:1932 (11)
    //         004ab012     MOVSX      EDI,BX
    //         004ab015     DEC        EDI
    //         004ab016     MOV        word ptr [ESI + 0x4b8],BX
    //                              scr_sed.cpp:1934 (9)
    //         004ab01d     TEST       BX,BX
    //         004ab020     JZ         LAB_004ab2a1
    //                              scr_sed.cpp:1938 (12)
    //         004ab026     MOV        this,dword ptr [ESI + 0x5b4]
    //         004ab02c     PUSH       EDI
    //         004ab02d     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
    //                              scr_sed.cpp:1939 (12)
    //         004ab032     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ab038     PUSH       EBX
    //         004ab039     MOV        EAX,dword ptr [this->_padding_]
    //         004ab03b     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:1940 (11)
    //         004ab03e     CMP        byte ptr [ESP + 0x38],0x1
    //         004ab043     JNZ        LAB_004ab2a1
    //                              scr_sed.cpp:1944 (31)
    //         004ab049     MOV        this,dword ptr [ESI + 0x928]
    //         004ab04f     PUSH       EDI
    //         004ab050     MOV        this,dword ptr [ECX + this->_padding_]
    //         004ab053     CALL       T_Scenario::Get_player_Food                      int Get_player_Food(T_Scenario * this, int pa
    //         004ab058     PUSH       EAX
    //         004ab059     LEA        EDX,[ESP + 0x10]
    //         004ab05d     PUSH       s_%d                                             = 6425h
    //         004ab062     PUSH       EDX=>DAT_fffffff4
    //         004ab063     CALL       sprintf                                          undefined sprintf()
    //                              scr_sed.cpp:1945 (19)
    //         004ab068     MOV        this,dword ptr [ESI + 0x5d8]
    //         004ab06e     ADD        ESP,0xc
    //         004ab071     LEA        EAX,[ESP + 0xc]
    //         004ab075     PUSH       EAX
    //         004ab076     CALL       TEditPanel::set_text                             void set_text(TEditPanel * this, char * param
    //                              scr_sed.cpp:1947 (31)
    //         004ab07b     MOV        this,dword ptr [ESI + 0x928]
    //         004ab081     PUSH       EDI
    //         004ab082     MOV        this,dword ptr [ECX + this->_padding_]
    //         004ab085     CALL       T_Scenario::Get_player_Wood                      int Get_player_Wood(T_Scenario * this, int pa
    //         004ab08a     PUSH       EAX
    //         004ab08b     LEA        EDX,[ESP + 0x10]
    //         004ab08f     PUSH       s_%d                                             = 6425h
    //         004ab094     PUSH       EDX=>DAT_fffffff4
    //         004ab095     CALL       sprintf                                          undefined sprintf()
    //                              scr_sed.cpp:1948 (19)
    //         004ab09a     MOV        this,dword ptr [ESI + 0x5dc]
    //         004ab0a0     ADD        ESP,0xc
    //         004ab0a3     LEA        EAX,[ESP + 0xc]
    //         004ab0a7     PUSH       EAX
    //         004ab0a8     CALL       TEditPanel::set_text                             void set_text(TEditPanel * this, char * param
    //                              scr_sed.cpp:1950 (31)
    //         004ab0ad     MOV        this,dword ptr [ESI + 0x928]
    //         004ab0b3     PUSH       EDI
    //         004ab0b4     MOV        this,dword ptr [ECX + this->_padding_]
    //         004ab0b7     CALL       T_Scenario::Get_player_Stone                     int Get_player_Stone(T_Scenario * this, int p
    //         004ab0bc     PUSH       EAX
    //         004ab0bd     LEA        EDX,[ESP + 0x10]
    //         004ab0c1     PUSH       s_%d                                             = 6425h
    //         004ab0c6     PUSH       EDX=>DAT_fffffff4
    //         004ab0c7     CALL       sprintf                                          undefined sprintf()
    //                              scr_sed.cpp:1951 (19)
    //         004ab0cc     MOV        this,dword ptr [ESI + 0x5e0]
    //         004ab0d2     ADD        ESP,0xc
    //         004ab0d5     LEA        EAX,[ESP + 0xc]
    //         004ab0d9     PUSH       EAX
    //         004ab0da     CALL       TEditPanel::set_text                             void set_text(TEditPanel * this, char * param
    //                              scr_sed.cpp:1953 (31)
    //         004ab0df     MOV        this,dword ptr [ESI + 0x928]
    //         004ab0e5     PUSH       EDI
    //         004ab0e6     MOV        this,dword ptr [ECX + this->_padding_]
    //         004ab0e9     CALL       T_Scenario::Get_player_Gold                      int Get_player_Gold(T_Scenario * this, int pa
    //         004ab0ee     PUSH       EAX
    //         004ab0ef     LEA        EDX,[ESP + 0x10]
    //         004ab0f3     PUSH       s_%d                                             = 6425h
    //         004ab0f8     PUSH       EDX=>DAT_fffffff4
    //         004ab0f9     CALL       sprintf                                          undefined sprintf()
    //                              scr_sed.cpp:1954 (19)
    //         004ab0fe     MOV        this,dword ptr [ESI + 0x5e4]
    //         004ab104     ADD        ESP,0xc
    //         004ab107     LEA        EAX,[ESP + 0xc]
    //         004ab10b     PUSH       EAX
    //         004ab10c     CALL       TEditPanel::set_text                             void set_text(TEditPanel * this, char * param
    //                              scr_sed.cpp:1956 (27)
    //         004ab111     MOV        this,dword ptr [ESI + 0x928]
    //         004ab117     PUSH       EDI
    //         004ab118     MOV        this,dword ptr [ECX + this->_padding_]
    //         004ab11b     CALL       RGE_Scenario::GetPlayerName                      char * GetPlayerName(RGE_Scenario * this, int
    //         004ab120     MOV        this,dword ptr [ESI + 0x5e8]
    //         004ab126     PUSH       EAX
    //         004ab127     CALL       TEditPanel::set_text                             void set_text(TEditPanel * this, char * param
    //                              scr_sed.cpp:1959 (15)
    //         004ab12c     MOV        EDX,dword ptr [ESI + 0x928]
    //         004ab132     PUSH       EDI
    //         004ab133     MOV        this,dword ptr [EDX + 0x5c]
    //         004ab136     CALL       RGE_Scenario::Get_player_Type                    int Get_player_Type(RGE_Scenario * this, int 
    //                              scr_sed.cpp:1960 (12)
    //         004ab13b     MOV        this,dword ptr [ESI + 0x5f8]
    //         004ab141     PUSH       EAX
    //         004ab142     CALL       TDropDownPanel::setCurrentLineNumber             void setCurrentLineNumber(TDropDownPanel * th
    //                              scr_sed.cpp:1963 (15)
    //         004ab147     MOV        EAX,dword ptr [ESI + 0x928]
    //         004ab14d     PUSH       EDI
    //         004ab14e     MOV        this,dword ptr [EAX + 0x5c]
    //         004ab151     CALL       RGE_Scenario::Get_player_Civ                     int Get_player_Civ(RGE_Scenario * this, int p
    //                              scr_sed.cpp:1964 (13)
    //         004ab156     MOV        this,dword ptr [ESI + 0x5fc]
    //         004ab15c     DEC        EAX
    //         004ab15d     PUSH       EAX
    //         004ab15e     CALL       TDropDownPanel::setCurrentLineNumber             void setCurrentLineNumber(TDropDownPanel * th
    //                              scr_sed.cpp:1970 (29)
    //         004ab163     MOV        this,dword ptr [ESI + 0x928]
    //         004ab169     PUSH       0x0
    //         004ab16b     PUSH       EDI=>DAT_fffffff8
    //         004ab16c     MOV        this,dword ptr [ECX + this->_padding_]
    //         004ab16f     CALL       RGE_Scenario::Get_player_AI                      char * Get_player_AI(RGE_Scenario * this, int
    //         004ab174     MOV        this,dword ptr [ESI + 0x608]
    //         004ab17a     PUSH       EAX
    //         004ab17b     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this, char * p
    //                              scr_sed.cpp:1971 (5)
    //         004ab180     CMP        EAX,-0x1
    //         004ab183     JNZ        LAB_004ab1c1
    //                              scr_sed.cpp:1974 (31)
    //         004ab185     MOV        EDX,dword ptr [ESI + 0x928]
    //         004ab18b     PUSH       0x0
    //         004ab18d     PUSH       0x0=>DAT_fffffff8
    //         004ab18f     PUSH       EDI=>DAT_fffffff4
    //         004ab190     MOV        this,dword ptr [EDX + 0x5c]
    //         004ab193     CALL       RGE_Scenario::Get_player_AI                      char * Get_player_AI(RGE_Scenario * this, int
    //         004ab198     MOV        this,dword ptr [ESI + 0x608]
    //         004ab19e     PUSH       EAX=>DAT_fffffff8
    //         004ab19f     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
    //                              scr_sed.cpp:1975 (29)
    //         004ab1a4     MOV        EAX,dword ptr [ESI + 0x928]
    //         004ab1aa     PUSH       0x0
    //         004ab1ac     PUSH       EDI=>DAT_fffffff8
    //         004ab1ad     MOV        this,dword ptr [EAX + 0x5c]
    //         004ab1b0     CALL       RGE_Scenario::Get_player_AI                      char * Get_player_AI(RGE_Scenario * this, int
    //         004ab1b5     MOV        this,dword ptr [ESI + 0x608]
    //         004ab1bb     PUSH       EAX
    //         004ab1bc     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this, char * p
    //                               LAB_004ab1c1                                                 XREF[1]:     004ab183(j)  
    //                              scr_sed.cpp:1980 (12)
    //         004ab1c1     MOV        this,dword ptr [ESI + 0x608]
    //         004ab1c7     PUSH       EAX
    //         004ab1c8     CALL       TDropDownPanel::setCurrentLineNumber             void setCurrentLineNumber(TDropDownPanel * th
    //                              scr_sed.cpp:1982 (29)
    //         004ab1cd     MOV        this,dword ptr [ESI + 0x928]
    //         004ab1d3     PUSH       0x0
    //         004ab1d5     PUSH       EDI=>DAT_fffffff8
    //         004ab1d6     MOV        this,dword ptr [ECX + this->_padding_]
    //         004ab1d9     CALL       RGE_Scenario::Get_BuildList                      char * Get_BuildList(RGE_Scenario * this, int
    //         004ab1de     MOV        this,dword ptr [ESI + 0x600]
    //         004ab1e4     PUSH       EAX
    //         004ab1e5     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this, char * p
    //                              scr_sed.cpp:1983 (5)
    //         004ab1ea     CMP        EAX,-0x1
    //         004ab1ed     JNZ        LAB_004ab22b
    //                              scr_sed.cpp:1986 (31)
    //         004ab1ef     MOV        EDX,dword ptr [ESI + 0x928]
    //         004ab1f5     PUSH       0x0
    //         004ab1f7     PUSH       0x0=>DAT_fffffff8
    //         004ab1f9     PUSH       EDI=>DAT_fffffff4
    //         004ab1fa     MOV        this,dword ptr [EDX + 0x5c]
    //         004ab1fd     CALL       RGE_Scenario::Get_BuildList                      char * Get_BuildList(RGE_Scenario * this, int
    //         004ab202     MOV        this,dword ptr [ESI + 0x600]
    //         004ab208     PUSH       EAX=>DAT_fffffff8
    //         004ab209     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
    //                              scr_sed.cpp:1987 (29)
    //         004ab20e     MOV        EAX,dword ptr [ESI + 0x928]
    //         004ab214     PUSH       0x0
    //         004ab216     PUSH       EDI=>DAT_fffffff8
    //         004ab217     MOV        this,dword ptr [EAX + 0x5c]
    //         004ab21a     CALL       RGE_Scenario::Get_BuildList                      char * Get_BuildList(RGE_Scenario * this, int
    //         004ab21f     MOV        this,dword ptr [ESI + 0x600]
    //         004ab225     PUSH       EAX
    //         004ab226     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this, char * p
    //                               LAB_004ab22b                                                 XREF[1]:     004ab1ed(j)  
    //                              scr_sed.cpp:1992 (12)
    //         004ab22b     MOV        this,dword ptr [ESI + 0x600]
    //         004ab231     PUSH       EAX
    //         004ab232     CALL       TDropDownPanel::setCurrentLineNumber             void setCurrentLineNumber(TDropDownPanel * th
    //                              scr_sed.cpp:1994 (29)
    //         004ab237     MOV        this,dword ptr [ESI + 0x928]
    //         004ab23d     PUSH       0x0
    //         004ab23f     PUSH       EDI=>DAT_fffffff8
    //         004ab240     MOV        this,dword ptr [ECX + this->_padding_]
    //         004ab243     CALL       RGE_Scenario::Get_CityPlan                       char * Get_CityPlan(RGE_Scenario * this, int 
    //         004ab248     MOV        this,dword ptr [ESI + 0x604]
    //         004ab24e     PUSH       EAX
    //         004ab24f     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this, char * p
    //                              scr_sed.cpp:1995 (5)
    //         004ab254     CMP        EAX,-0x1
    //         004ab257     JNZ        LAB_004ab295
    //                              scr_sed.cpp:1998 (31)
    //         004ab259     MOV        EDX,dword ptr [ESI + 0x928]
    //         004ab25f     PUSH       0x0
    //         004ab261     PUSH       0x0=>DAT_fffffff8
    //         004ab263     PUSH       EDI=>DAT_fffffff4
    //         004ab264     MOV        this,dword ptr [EDX + 0x5c]
    //         004ab267     CALL       RGE_Scenario::Get_CityPlan                       char * Get_CityPlan(RGE_Scenario * this, int 
    //         004ab26c     MOV        this,dword ptr [ESI + 0x604]
    //         004ab272     PUSH       EAX=>DAT_fffffff8
    //         004ab273     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
    //                              scr_sed.cpp:1999 (29)
    //         004ab278     MOV        EAX,dword ptr [ESI + 0x928]
    //         004ab27e     PUSH       0x0
    //         004ab280     PUSH       EDI=>DAT_fffffff8
    //         004ab281     MOV        this,dword ptr [EAX + 0x5c]
    //         004ab284     CALL       RGE_Scenario::Get_CityPlan                       char * Get_CityPlan(RGE_Scenario * this, int 
    //         004ab289     MOV        this,dword ptr [ESI + 0x604]
    //         004ab28f     PUSH       EAX
    //         004ab290     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this, char * p
    //                               LAB_004ab295                                                 XREF[1]:     004ab257(j)  
    //                              scr_sed.cpp:2004 (12)
    //         004ab295     MOV        this,dword ptr [ESI + 0x604]
    //         004ab29b     PUSH       EAX
    //         004ab29c     CALL       TDropDownPanel::setCurrentLineNumber             void setCurrentLineNumber(TDropDownPanel * th
    //                               LAB_004ab2a1                                                 XREF[2]:     004ab020(j), 004ab043(j)  
    //                              scr_sed.cpp:2008 (9)
    //         004ab2a1     POP        EDI
    //         004ab2a2     POP        ESI
    //         004ab2a3     POP        EBX
    //         004ab2a4     ADD        ESP,0x20
    //         004ab2a7     RET        0xc
    //         004ab2aa     ??         90h
    //         004ab2ab     NOP
    //         004ab2ac     NOP
    //         004ab2ad     NOP
    //         004ab2ae     NOP
    //         004ab2af     NOP
    return;
}

void TRIBE_Screen_Sed::set_player_active(short param_1, int param_2) {
    /* TODO: Stub */
    //                              void __thiscall set_player_active(TRIBE_Screen_Sed * this, short par
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     004ab2b4(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004ab2b0(R)  
    //                               ?set_player_active@TRIBE_Screen_Sed@@IAEXFH@Z                XREF[2]:     TRIBE_Screen_Sed:004a8666(c), 
    //                               TRIBE_Screen_Sed::set_player_active                                       TRIBE_Screen_Sed:004a8671(c)  
    //                              scr_sed.cpp:2014 (25)
    //         004ab2b0     MOV        EAX,dword ptr [ESP + param_2]
    //         004ab2b4     MOVSX      EDX,word ptr [ESP + param_1]
    //         004ab2b9     PUSH       EAX
    //         004ab2ba     MOV        EAX,dword ptr [ECX + this->world]
    //         004ab2c0     PUSH       EDX
    //         004ab2c1     MOV        this,dword ptr [EAX + 0x5c]
    //         004ab2c4     CALL       RGE_Scenario::Set_player_Active                  void Set_player_Active(RGE_Scenario * this, i
    //                              scr_sed.cpp:2024 (3)
    //         004ab2c9     RET        0x8
    //         004ab2cc     ??         90h
    //         004ab2cd     NOP
    //         004ab2ce     NOP
    //         004ab2cf     NOP
    //                              * int __cdecl TRIBE_Screen_Sed_unit_list_compare(void const *,void const *)                             *
    //                              int __cdecl TRIBE_Screen_Sed_unit_list_compare(void * param_1, void 
    //              int               EAX:4          <RETURN>
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     004ab2d4(R)  
    //              void *            Stack[0x8]:4   param_2                   XREF[1]:     004ab2d0(R)  
    //                               ?TRIBE_Screen_Sed_unit_list_compare@@YAHPBX0@Z               XREF[1]:     set_unit_player:004ab523(*)  
    //                               TRIBE_Screen_Sed_unit_list_compare
    //                              scr_sed.cpp:2030 (27)
    //         004ab2d0     MOV        EAX,dword ptr [ESP + param_2]
    //         004ab2d4     MOV        ECX,dword ptr [ESP + param_1]
    //         004ab2d8     PUSH       -0x1
    //         004ab2da     PUSH       EAX
    //         004ab2db     PUSH       -0x1
    //         004ab2dd     PUSH       ECX
    //         004ab2de     PUSH       0x1
    //         004ab2e0     PUSH       0x400
    //         004ab2e5     CALL       dword ptr [->KERNEL32.DLL::CompareStringA]       = 0048abe4
    //                              scr_sed.cpp:2034 (5)
    //         004ab2eb     CMP        EAX,0x1
    //         004ab2ee     JNZ        LAB_004ab2f4
    //                              scr_sed.cpp:2035 (3)
    //         004ab2f0     OR         EAX,0xffffffff
    //                              scr_sed.cpp:2042 (1)
    //         004ab2f3     RET
    //                               LAB_004ab2f4                                                 XREF[1]:     004ab2ee(j)  
    //                              scr_sed.cpp:2036 (10)
    //         004ab2f4     XOR        EDX,EDX
    //         004ab2f6     CMP        EAX,0x3
    //         004ab2f9     SETZ       DL
    //         004ab2fc     MOV        EAX,EDX
    //                              scr_sed.cpp:2042 (1)
    //         004ab2fe     RET
    //         004ab2ff     ??         90h
    return;
}

void TRIBE_Screen_Sed::set_unit_player(short param_1) {
    /* TODO: Stub */
    //                              void __thiscall set_unit_player(TRIBE_Screen_Sed * this, short param
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     004ab327(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004ab33c(W)  
    //              short             Stack[-0x8]:2  end_i                     XREF[1]:     004ab332(W)  
    //              float             Stack[-0xc]:4  save_view_x               XREF[1]:     004ab341(W)  
    //              int               Stack[-0x10]:4 is_error
    //                               ?set_unit_player@TRIBE_Screen_Sed@@IAEXF@Z                   XREF[3]:     TRIBE_Screen_Sed:004a86dc(c), 
    //                               TRIBE_Screen_Sed::set_unit_player                                         set_scenario_mode:004aa011(c), 
    //                                                                                                         action:004aca6c(c)  
    //                              scr_sed.cpp:2048 (8)
    //         004ab300     SUB        ESP,0xc
    //         004ab303     PUSH       EBX
    //         004ab304     PUSH       EBP
    //         004ab305     MOV        EBX,this
    //         004ab307     PUSH       ESI
    //                              scr_sed.cpp:2063 (12)
    //         004ab308     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ab30e     PUSH       EDI
    //         004ab30f     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //                              scr_sed.cpp:2064 (6)
    //         004ab314     MOV        this,dword ptr [EAX + 0x114]
    //                              scr_sed.cpp:2065 (6)
    //         004ab31a     MOV        EDX,dword ptr [EAX + 0x118]
    //                              scr_sed.cpp:2066 (7)
    //         004ab320     MOV        DI,word ptr [EAX + 0x11c]
    //                              scr_sed.cpp:2070 (36)
    //         004ab327     MOV        ESI,dword ptr [ESP + param_1]
    //         004ab32b     MOV        AX,word ptr [EAX + 0x11e]
    //         004ab332     MOV        dword ptr [ESP + end_i],this
    //         004ab336     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ab33c     MOV        dword ptr [ESP + local_4],EDX
    //         004ab340     PUSH       ESI
    //         004ab341     MOV        word ptr [ESP + save_view_x],AX
    //         004ab346     MOV        EDX,dword ptr [this->_padding_]
    //         004ab348     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:2071 (7)
    //         004ab34b     MOV        word ptr [EBX + 0x4b8],SI
    //                              scr_sed.cpp:2074 (11)
    //         004ab352     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ab358     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //                              scr_sed.cpp:2076 (19)
    //         004ab35d     MOV        this,dword ptr [ESP + 0x14]
    //         004ab361     MOV        EBP,EAX
    //         004ab363     MOV        EAX,dword ptr [ESP + 0x18]
    //         004ab367     PUSH       EAX
    //         004ab368     PUSH       this=>DAT_fffffff8
    //         004ab369     MOV        this,EBP
    //         004ab36b     CALL       RGE_Player::set_view_loc                         void set_view_loc(RGE_Player * this, float pa
    //                              scr_sed.cpp:2077 (13)
    //         004ab370     MOV        EDX,dword ptr [ESP + 0x10]
    //         004ab374     MOV        this,EBP
    //         004ab376     PUSH       EDX
    //         004ab377     PUSH       EDI=>DAT_fffffff8
    //         004ab378     CALL       RGE_Player::set_map_loc                          void set_map_loc(RGE_Player * this, short par
    //                              scr_sed.cpp:2080 (12)
    //         004ab37d     MOV        this,dword ptr [EBX + 0x4c8]
    //         004ab383     PUSH       EBP
    //         004ab384     CALL       RGE_View::set_player                             void set_player(RGE_View * this, RGE_Player *
    //                              scr_sed.cpp:2081 (12)
    //         004ab389     MOV        this,dword ptr [EBX + 0x4cc]
    //         004ab38f     PUSH       EBP
    //         004ab390     CALL       RGE_Diamond_Map::set_player                      void set_player(RGE_Diamond_Map * this, RGE_P
    //                              scr_sed.cpp:2084 (15)
    //         004ab395     MOV        this,dword ptr [EBX + 0x618]
    //         004ab39b     MOVSX      EAX,SI
    //         004ab39e     PUSH       EAX
    //         004ab39f     CALL       TDropDownPanel::setCurrentLineNumber             void setCurrentLineNumber(TDropDownPanel * th
    //                              scr_sed.cpp:2087 (11)
    //         004ab3a4     MOV        this,dword ptr [EBX + 0x63c]
    //         004ab3aa     CALL       TTextPanel::empty_list                           void empty_list(TTextPanel * this)
    //                              scr_sed.cpp:2089 (12)
    //         004ab3af     MOV        EAX,dword ptr [EBX + 0x644]
    //         004ab3b5     XOR        ESI,ESI
    //         004ab3b7     CMP        EAX,ESI
    //         004ab3b9     JZ         LAB_004ab3ca
    //                              scr_sed.cpp:2091 (9)
    //         004ab3bb     PUSH       EAX
    //         004ab3bc     CALL       free                                             undefined free()
    //         004ab3c1     ADD        ESP,0x4
    //                              scr_sed.cpp:2092 (6)
    //         004ab3c4     MOV        dword ptr [EBX + 0x644],ESI
    //                               LAB_004ab3ca                                                 XREF[1]:     004ab3b9(j)  
    //                              scr_sed.cpp:2095 (8)
    //         004ab3ca     CMP        EBP,ESI
    //         004ab3cc     JZ         LAB_004ab665
    //                              scr_sed.cpp:2099 (9)
    //         004ab3d2     MOV        word ptr [EBX + 0x664],0x1
    //                              scr_sed.cpp:2100 (4)
    //         004ab3db     MOV        DI,word ptr [EBP + 0x22]
    //                              scr_sed.cpp:2101 (9)
    //         004ab3df     CMP        DI,SI
    //         004ab3e2     MOV        dword ptr [ESP + 0x18],EDI
    //         004ab3e6     JLE        LAB_004ab40a
    //                              scr_sed.cpp:2172 (15)
    //         004ab3e8     XOR        this,this
    //         004ab3ea     MOVSX      EDX,DI
    //                               LAB_004ab3ed                                                 XREF[1]:     004ab408(j)  
    //         004ab3ed     MOV        EAX,dword ptr [EBP + 0x24]
    //         004ab3f0     MOV        EAX,dword ptr [this->_padding_ + EAX*0x1]
    //         004ab3f3     CMP        EAX,ESI
    //         004ab3f5     JZ         LAB_004ab404
    //                              scr_sed.cpp:2103 (6)
    //         004ab3f7     CMP        byte ptr [EAX + 0x4e],0x0
    //         004ab3fb     JNZ        LAB_004ab404
    //                              scr_sed.cpp:2104 (7)
    //         004ab3fd     INC        word ptr [EBX + 0x664]
    //                               LAB_004ab404                                                 XREF[2]:     004ab3f5(j), 004ab3fb(j)  
    //                              scr_sed.cpp:2101 (6)
    //         004ab404     ADD        this,0x4
    //         004ab407     DEC        EDX
    //         004ab408     JNZ        LAB_004ab3ed
    //                               LAB_004ab40a                                                 XREF[1]:     004ab3e6(j)  
    //                              scr_sed.cpp:2107 (16)
    //         004ab40a     MOV        AX,word ptr [EBX + 0x664]
    //         004ab411     CMP        AX,SI
    //         004ab414     JZ         LAB_004ab665
    //                              scr_sed.cpp:2111 (14)
    //         004ab41a     MOVSX      this,AX
    //                              language.dll match for 0x66: "Copperplate Gothic Light"
    //         004ab41d     PUSH       0x66
    //         004ab41f     PUSH       this=>DAT_fffffff8
    //         004ab420     CALL       calloc                                           undefined calloc()
    //         004ab425     ADD        ESP,0x8
    //                              scr_sed.cpp:2112 (14)
    //         004ab428     CMP        EAX,ESI
    //         004ab42a     MOV        dword ptr [EBX + 0x644],EAX
    //         004ab430     JZ         LAB_004ab665
    //                              scr_sed.cpp:2115 (6)
    //         004ab436     MOV        word ptr [EAX + 0x64],0xffff
    //                              scr_sed.cpp:2116 (21)
    //         004ab43c     MOV        EDX,dword ptr [EBX + 0x644]
    //         004ab442     PUSH       0x14
    //                              language.dll match for 0x2775: " <None> "
    //         004ab444     PUSH       offset DAT_fffffff8
    //         004ab449     PUSH       EDX=>DAT_fffffff4
    //         004ab44a     MOV        this,EBX
    //         004ab44c     CALL       TRIBE_Screen_Sed::set_string                     void set_string(TRIBE_Screen_Sed * this, char
    //                              scr_sed.cpp:2118 (21)
    //         004ab451     TEST       DI,DI
    //         004ab454     MOV        dword ptr [ESP + 0x10],0x1
    //         004ab45c     MOV        dword ptr [ESP + 0x20],ESI
    //         004ab460     JLE        LAB_004ab516
    //                              scr_sed.cpp:2172 (96)
    //         004ab466     XOR        EDI,EDI
    //         004ab468     MOV        dword ptr [ESP + 0x14],EDI
    //                               LAB_004ab46c                                                 XREF[1]:     004ab510(j)  
    //         004ab46c     MOV        EAX,dword ptr [EBP + 0x24]
    //         004ab46f     MOV        EAX,dword ptr [EDI + EAX*0x1]
    //         004ab472     TEST       EAX,EAX
    //         004ab474     JZ         LAB_004ab4ff
    //         004ab47a     MOV        this,byte ptr [EAX + 0x4e]
    //         004ab47d     TEST       this,this
    //         004ab47f     JNZ        LAB_004ab4ff
    //         004ab481     MOVSX      this,word ptr [ESP + 0x10]
    //         004ab486     MOV        EAX,this
    //         004ab488     SHL        EAX,0x4
    //         004ab48b     ADD        EAX,this
    //         004ab48d     MOV        this,dword ptr [EBX + 0x644]
    //         004ab493     LEA        EDX,[EAX + EAX*0x2]
    //         004ab496     SHL        EDX,0x1
    //         004ab498     MOV        word ptr [EDX + this->_padding_*0x1 + 0x64],SI
    //         004ab49d     MOV        EAX,dword ptr [EBP + 0x24]
    //         004ab4a0     MOV        EAX,dword ptr [EDI + EAX*0x1]
    //         004ab4a3     MOV        SI,word ptr [EAX + 0xc]
    //         004ab4a7     TEST       SI,SI
    //         004ab4aa     JLE        LAB_004ab4c6
    //         004ab4ac     ADD        EDX,dword ptr [EBX + 0x644]
    //         004ab4b2     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ab4b8     PUSH       0x64
    //         004ab4ba     MOV        EAX,dword ptr [this->_padding_]
    //         004ab4bc     PUSH       EDX=>DAT_fffffff8
    //         004ab4bd     MOVSX      EDX,SI
    //         004ab4c0     PUSH       EDX=>DAT_fffffff4
    //         004ab4c1     CALL       dword ptr [EAX + 0x20]
    //         004ab4c4     JMP        LAB_004ab4f2
    //                               LAB_004ab4c6                                                 XREF[1]:     004ab4aa(j)  
    //                              scr_sed.cpp:2128 (44)
    //         004ab4c6     MOV        this,dword ptr [EBX + 0x644]
    //         004ab4cc     MOV        EDI,dword ptr [EAX + 0x8]
    //         004ab4cf     ADD        EDX,this
    //         004ab4d1     OR         this,0xffffffff
    //         004ab4d4     XOR        EAX,EAX
    //         004ab4d6     SCASB.RE   ES:EDI
    //         004ab4d8     NOT        this
    //         004ab4da     SUB        EDI,this
    //         004ab4dc     MOV        EAX,this
    //         004ab4de     MOV        ESI,EDI
    //         004ab4e0     MOV        EDI,EDX
    //         004ab4e2     SHR        this,0x2
    //         004ab4e5     MOVSD.REP  ES:EDI,ESI
    //         004ab4e7     MOV        this,EAX
    //         004ab4e9     AND        this,0x3
    //         004ab4ec     MOVSB.REP  ES:EDI,ESI
    //         004ab4ee     MOV        EDI,dword ptr [ESP + 0x14]
    //                               LAB_004ab4f2                                                 XREF[1]:     004ab4c4(j)  
    //                              scr_sed.cpp:2130 (36)
    //         004ab4f2     MOV        EAX,dword ptr [ESP + 0x10]
    //         004ab4f6     MOV        ESI,dword ptr [ESP + 0x20]
    //         004ab4fa     INC        EAX
    //         004ab4fb     MOV        dword ptr [ESP + 0x10],EAX
    //                               LAB_004ab4ff                                                 XREF[2]:     004ab474(j), 004ab47f(j)  
    //         004ab4ff     INC        ESI
    //         004ab500     ADD        EDI,0x4
    //         004ab503     CMP        SI,word ptr [ESP + 0x18]
    //         004ab508     MOV        dword ptr [ESP + 0x20],ESI
    //         004ab50c     MOV        dword ptr [ESP + 0x14],EDI
    //         004ab510     JL         LAB_004ab46c
    //                               LAB_004ab516                                                 XREF[1]:     004ab460(j)  
    //                              scr_sed.cpp:2135 (27)
    //         004ab516     MOVSX      this,word ptr [EBX + 0x664]
    //         004ab51d     MOV        EDX,dword ptr [EBX + 0x644]
    //         004ab523     PUSH       TRIBE_Screen_Sed_unit_list_compare
    //                              language.dll match for 0x66: "Copperplate Gothic Light"
    //         004ab528     PUSH       offset DAT_fffffff8
    //         004ab52a     PUSH       this=>DAT_fffffff4
    //         004ab52b     PUSH       EDX=>DAT_fffffff0
    //         004ab52c     CALL       qsort                                            undefined qsort()
    //                              scr_sed.cpp:2138 (20)
    //         004ab531     MOVSX      EAX,word ptr [EBX + 0x664]
    //         004ab538     ADD        ESP,0x10
    //         004ab53b     PUSH       0x4
    //         004ab53d     PUSH       EAX=>DAT_fffffff8
    //         004ab53e     CALL       calloc                                           undefined calloc()
    //         004ab543     MOV        ESI,EAX
    //                              scr_sed.cpp:2139 (17)
    //         004ab545     XOR        EAX,EAX
    //         004ab547     ADD        ESP,0x8
    //         004ab54a     CMP        ESI,EAX
    //         004ab54c     MOV        dword ptr [ESP + 0x14],ESI
    //         004ab550     JZ         LAB_004ab665
    //                              scr_sed.cpp:2144 (25)
    //         004ab556     CMP        word ptr [EBX + 0x664],AX
    //         004ab55d     MOV        dword ptr [ESP + 0x10],EAX
    //         004ab561     MOV        dword ptr [ESP + 0x18],EAX
    //         004ab565     MOV        dword ptr [ESP + 0x20],EAX
    //         004ab569     JLE        LAB_004ab601
    //                               LAB_004ab56f                                                 XREF[1]:     004ab5f1(j)  
    //                              scr_sed.cpp:2146 (19)
    //         004ab56f     PUSH       0x1
    //         004ab571     PUSH       offset DAT_fffffff8
    //         004ab573     CALL       calloc                                           undefined calloc()
    //         004ab578     MOVSX      this,word ptr [ESP + 0x28]
    //         004ab57d     MOV        EBP,EAX
    //         004ab57f     ADD        ESP,0x8
    //                              scr_sed.cpp:2147 (7)
    //         004ab582     TEST       EBP,EBP
    //         004ab584     MOV        dword ptr [ESI + this->_padding_*0x4],EBP
    //         004ab587     JZ         LAB_004ab5f9
    //                              scr_sed.cpp:2152 (51)
    //         004ab589     MOV        EAX,this
    //         004ab58b     SHL        EAX,0x4
    //         004ab58e     ADD        EAX,this
    //         004ab590     OR         this,0xffffffff
    //         004ab593     LEA        EDX,[EAX + EAX*0x2]
    //         004ab596     MOV        EAX,dword ptr [EBX + 0x644]
    //         004ab59c     SHL        EDX,0x1
    //         004ab59e     MOV        EDI,EDX
    //         004ab5a0     ADD        EDI,EAX
    //         004ab5a2     XOR        EAX,EAX
    //         004ab5a4     SCASB.RE   ES:EDI
    //         004ab5a6     NOT        this
    //         004ab5a8     SUB        EDI,this
    //         004ab5aa     MOV        EAX,this
    //         004ab5ac     MOV        ESI,EDI
    //         004ab5ae     MOV        EDI,EBP
    //         004ab5b0     SHR        this,0x2
    //         004ab5b3     MOVSD.REP  ES:EDI,ESI
    //         004ab5b5     MOV        this,EAX
    //         004ab5b7     AND        this,0x3
    //         004ab5ba     MOVSB.REP  ES:EDI,ESI
    //                              scr_sed.cpp:2153 (25)
    //         004ab5bc     MOV        this,dword ptr [EBX + 0x644]
    //         004ab5c2     MOV        EAX,[rge_base_game]                              = 00000000
    //         004ab5c7     MOV        DX,word ptr [EDX + this->_padding_*0x1 + 0x64]
    //         004ab5cc     CMP        DX,word ptr [EAX + 0x3fc]
    //         004ab5d3     JNZ        LAB_004ab5dd
    //                              scr_sed.cpp:2154 (36)
    //         004ab5d5     MOV        this,dword ptr [ESP + 0x20]
    //         004ab5d9     MOV        dword ptr [ESP + 0x18],this
    //                               LAB_004ab5dd                                                 XREF[1]:     004ab5d3(j)  
    //         004ab5dd     MOV        EAX,dword ptr [ESP + 0x20]
    //         004ab5e1     MOV        ESI,dword ptr [ESP + 0x14]
    //         004ab5e5     INC        EAX
    //         004ab5e6     CMP        AX,word ptr [EBX + 0x664]
    //         004ab5ed     MOV        dword ptr [ESP + 0x20],EAX
    //         004ab5f1     JL         LAB_004ab56f
    //         004ab5f7     JMP        LAB_004ab601
    //                               LAB_004ab5f9                                                 XREF[1]:     004ab587(j)  
    //                              scr_sed.cpp:2149 (8)
    //         004ab5f9     MOV        dword ptr [ESP + 0x10],0x1
    //                               LAB_004ab601                                                 XREF[2]:     004ab569(j), 004ab5f7(j)  
    //                              scr_sed.cpp:2157 (8)
    //         004ab601     MOV        EAX,dword ptr [ESP + 0x10]
    //         004ab605     TEST       EAX,EAX
    //         004ab607     JNZ        LAB_004ab634
    //                              scr_sed.cpp:2159 (23)
    //         004ab609     MOV        this,dword ptr [EBX + 0x63c]
    //         004ab60f     MOV        AX,word ptr [EBX + 0x664]
    //         004ab616     PUSH       EAX
    //         004ab617     PUSH       ESI=>DAT_fffffff8
    //         004ab618     MOV        EDX,dword ptr [this->_padding_]
    //         004ab61a     CALL       dword ptr [EDX + 0xe0]
    //                              scr_sed.cpp:2160 (20)
    //         004ab620     MOV        this,dword ptr [ESP + 0x18]
    //         004ab624     PUSH       0x1
    //         004ab626     PUSH       this=>DAT_fffffff8
    //         004ab627     MOV        this,dword ptr [EBX + 0x63c]
    //         004ab62d     PUSH       offset DAT_fffffff4
    //         004ab62f     CALL       TListPanel::scroll_cur_line                      void scroll_cur_line(TListPanel * this, uchar
    //                               LAB_004ab634                                                 XREF[1]:     004ab607(j)  
    //                              scr_sed.cpp:2165 (11)
    //         004ab634     XOR        EDI,EDI
    //         004ab636     CMP        word ptr [EBX + 0x664],DI
    //         004ab63d     JLE        LAB_004ab65c
    //                               LAB_004ab63f                                                 XREF[1]:     004ab65a(j)  
    //                              scr_sed.cpp:2167 (10)
    //         004ab63f     MOVSX      EDX,DI
    //         004ab642     MOV        EAX,dword ptr [ESI + EDX*0x4]
    //         004ab645     TEST       EAX,EAX
    //         004ab647     JZ         LAB_004ab652
    //                              scr_sed.cpp:2168 (19)
    //         004ab649     PUSH       EAX
    //         004ab64a     CALL       free                                             undefined free()
    //         004ab64f     ADD        ESP,0x4
    //                               LAB_004ab652                                                 XREF[1]:     004ab647(j)  
    //         004ab652     INC        EDI
    //         004ab653     CMP        DI,word ptr [EBX + 0x664]
    //         004ab65a     JL         LAB_004ab63f
    //                               LAB_004ab65c                                                 XREF[1]:     004ab63d(j)  
    //                              scr_sed.cpp:2170 (9)
    //         004ab65c     PUSH       ESI
    //         004ab65d     CALL       free                                             undefined free()
    //         004ab662     ADD        ESP,0x4
    //                               LAB_004ab665                                                 XREF[4]:     004ab3cc(j), 004ab414(j), 
    //                                                                                                         004ab430(j), 004ab550(j)  
    //                              scr_sed.cpp:2172 (10)
    //         004ab665     POP        EDI
    //         004ab666     POP        ESI
    //         004ab667     POP        EBP
    //         004ab668     POP        EBX
    //         004ab669     ADD        ESP,0xc
    //         004ab66c     RET        0x4
    //         004ab66f     ??         90h
    return;
}

void TRIBE_Screen_Sed::set_unit(short param_1) {
    /* TODO: Stub */
    //                              void __thiscall set_unit(TRIBE_Screen_Sed * this, short param_1)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     004ab671(R)  
    //                               ?set_unit@TRIBE_Screen_Sed@@IAEXF@Z                          XREF[4]:     TRIBE_Screen_Sed:004a86f8(c), 
    //                               TRIBE_Screen_Sed::set_unit                                                set_scenario_mode:004aa024(c), 
    //                                                                                                         set_scenario_mode:004aa0ff(c), 
    //                                                                                                         action:004acb46(c)  
    //                              scr_sed.cpp:2178 (1)
    //         004ab670     PUSH       EDI
    //                              scr_sed.cpp:2179 (15)
    //         004ab671     MOV        EDI,dword ptr [ESP + param_1]
    //         004ab675     CMP        DI,-0x1
    //         004ab679     JNZ        LAB_004ab69b
    //         004ab67b     MOV        EAX,[rge_base_game]                              = 00000000
    //                              scr_sed.cpp:2182 (23)
    //         004ab680     PUSH       0x1
    //         004ab682     PUSH       EDI
    //         004ab683     PUSH       0x1
    //         004ab685     MOV        word ptr [EAX + 0x3fc],DI
    //         004ab68c     MOV        this,dword ptr [ECX + this->unit_list]
    //         004ab692     CALL       TListPanel::scroll_cur_line                      void scroll_cur_line(TListPanel * this, uchar
    //                              scr_sed.cpp:2183 (4)
    //         004ab697     POP        EDI
    //         004ab698     RET        0x4
    //                               LAB_004ab69b                                                 XREF[1]:     004ab679(j)  
    //                              scr_sed.cpp:2180 (38)
    //         004ab69b     MOVSX      EDX,DI
    //         004ab69e     MOV        EAX,EDX
    //         004ab6a0     PUSH       ESI
    //         004ab6a1     MOV        ESI,dword ptr [rge_base_game]                    = 00000000
    //         004ab6a7     SHL        EAX,0x4
    //         004ab6aa     ADD        EAX,EDX
    //         004ab6ac     MOV        EDX,dword ptr [ECX + this->unit_list_info]
    //         004ab6b2     LEA        EAX,[EAX + EAX*0x2]
    //         004ab6b5     MOV        AX,word ptr [EDX + EAX*0x2 + 0x64]
    //         004ab6ba     MOV        word ptr [ESI + 0x3fc],AX
    //                              scr_sed.cpp:2182 (17)
    //         004ab6c1     MOV        this,dword ptr [ECX + this->unit_list]
    //         004ab6c7     POP        ESI
    //         004ab6c8     PUSH       0x1
    //         004ab6ca     PUSH       EDI
    //         004ab6cb     PUSH       0x1
    //         004ab6cd     CALL       TListPanel::scroll_cur_line                      void scroll_cur_line(TListPanel * this, uchar
    //                              scr_sed.cpp:2183 (4)
    //         004ab6d2     POP        EDI
    //         004ab6d3     RET        0x4
    //         004ab6d6     ??         90h
    //         004ab6d7     NOP
    //         004ab6d8     NOP
    //         004ab6d9     NOP
    //         004ab6da     NOP
    //         004ab6db     NOP
    //         004ab6dc     NOP
    //         004ab6dd     NOP
    //         004ab6de     NOP
    //         004ab6df     NOP
    return;
}

void TRIBE_Screen_Sed::set_message_type(MessageType param_1, int param_2) {
    /* TODO: Stub */
    //                              void __thiscall set_message_type(TRIBE_Screen_Sed * this, MessageTyp
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              MessageType       Stack[0x4]:4   param_1
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004ab6e0(R)  
    //                               ?set_message_type@TRIBE_Screen_Sed@@IAEXW4MessageType@1@H@Z  XREF[3]:     TRIBE_Screen_Sed:004a86e6(c), 
    //                               TRIBE_Screen_Sed::set_message_type                                        set_scenario_mode:004aa2b0(c), 
    //                                                                                                         set_scenario_mode:004aa2f9(c)  
    //                              scr_sed.cpp:2189 (19)
    //         004ab6e0     MOV        EDX,dword ptr [ESP + param_2]
    //         004ab6e4     PUSH       ESI
    //         004ab6e5     MOV        ESI,this
    //         004ab6e7     PUSH       EDX
    //         004ab6e8     MOV        this,dword ptr [ESI + 0x774]
    //         004ab6ee     MOV        EAX,dword ptr [this->_padding_]
    //         004ab6f0     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:2194 (13)
    //         004ab6f3     MOV        this,dword ptr [ESI + 0x4d4]
    //         004ab6f9     PUSH       0x1
    //         004ab6fb     MOV        EAX,dword ptr [this->_padding_]
    //         004ab6fd     CALL       dword ptr [EAX + 0x20]
    //                              scr_sed.cpp:2195 (4)
    //         004ab700     POP        ESI
    //         004ab701     RET        0x8
    //         004ab704     ??         90h
    //         004ab705     NOP
    //         004ab706     NOP
    //         004ab707     NOP
    //         004ab708     NOP
    //         004ab709     NOP
    //         004ab70a     NOP
    //         004ab70b     NOP
    //         004ab70c     NOP
    //         004ab70d     NOP
    //         004ab70e     NOP
    //         004ab70f     NOP
    return;
}

long TRIBE_Screen_Sed::handle_size(long param_1, long param_2) {
    /* TODO: Stub */
    //                              long __thiscall handle_size(TRIBE_Screen_Sed * this, long param_1, l
    //              long              EAX:4          <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     004ab711(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     004ab717(R)  
    //                               ?handle_size@TRIBE_Screen_Sed@@UAEJJJ@Z                      XREF[1]:     00573a10(*)  
    //                               TRIBE_Screen_Sed::handle_size
    //                              scr_sed.cpp:2201 (1)
    //         004ab710     PUSH       EBX
    //                              scr_sed.cpp:2203 (19)
    //         004ab711     MOV        EBX,dword ptr [ESP + param_1]
    //         004ab715     PUSH       ESI
    //         004ab716     PUSH       EDI
    //         004ab717     MOV        EDI,dword ptr [ESP + param_2]
    //         004ab71b     MOV        ESI,this
    //         004ab71d     PUSH       EDI
    //         004ab71e     PUSH       EBX
    //         004ab71f     CALL       TPanel::handle_size                              long handle_size(TPanel * this, long param_1,
    //                              scr_sed.cpp:2206 (7)
    //         004ab724     MOV        this,ESI
    //         004ab726     CALL       TRIBE_Screen_Sed::position_panels                void position_panels(TRIBE_Screen_Sed * this)
    //                              scr_sed.cpp:2210 (9)
    //         004ab72b     PUSH       EDI
    //         004ab72c     PUSH       EBX
    //         004ab72d     MOV        this,ESI
    //         004ab72f     CALL       TPanel::handle_size                              long handle_size(TPanel * this, long param_1,
    //                              scr_sed.cpp:2213 (8)
    //         004ab734     POP        EDI
    //         004ab735     POP        ESI
    //         004ab736     XOR        EAX,EAX
    //         004ab738     POP        EBX
    //         004ab739     RET        0x8
    //         004ab73c     ??         90h
    //         004ab73d     NOP
    //         004ab73e     NOP
    //         004ab73f     NOP
    return 0;
}

long TRIBE_Screen_Sed::handle_idle() {
    /* TODO: Stub */
    //                              long __thiscall handle_idle(TRIBE_Screen_Sed * this)
    //              long              EAX:4          <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //                               ?handle_idle@TRIBE_Screen_Sed@@UAEJXZ                        XREF[1]:     00573a0c(*)  
    //                               TRIBE_Screen_Sed::handle_idle
    //                              scr_sed.cpp:2219 (18)
    //         004ab740     MOV        EAX,[rge_base_game]                              = 00000000
    //         004ab745     PUSH       ESI
    //         004ab746     MOV        ESI,this
    //         004ab748     PUSH       EDI
    //         004ab749     CMP        dword ptr [EAX + 0x1b0],0x7
    //         004ab750     JNZ        LAB_004ab7b8
    //                              scr_sed.cpp:2225 (15)
    //         004ab752     PUSH       0x8b1
    //         004ab757     PUSH       s_C:\msdev\work\age1_x1\scr_sed.cp               = "C:\\msdev\\work\\age1_x1\\scr_sed.cpp"
    //         004ab75c     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //                              scr_sed.cpp:2226 (23)
    //         004ab761     MOV        this,dword ptr [ESI + 0x930]
    //         004ab767     MOV        EDI,EAX
    //         004ab769     MOV        EAX,dword ptr [ESI + 0x92c]
    //         004ab76f     SUB        this,EDI
    //         004ab771     ADD        ESP,0x8
    //         004ab774     CMP        this,EAX
    //         004ab776     JC         LAB_004ab7b8
    //                              scr_sed.cpp:2228 (14)
    //         004ab778     MOV        this,panel_system
    //         004ab77d     CALL       TPanelSystem::modalPanel                         TPanel * modalPanel(TPanelSystem * this)
    //         004ab782     TEST       EAX,EAX
    //         004ab784     JNZ        LAB_004ab7b8
    //                              scr_sed.cpp:2230 (13)
    //         004ab786     MOV        this,dword ptr [ESI + 0x4c8]
    //         004ab78c     PUSH       0x1
    //         004ab78e     MOV        EDX,dword ptr [this->_padding_]
    //         004ab790     CALL       dword ptr [EDX + 0x20]
    //                              scr_sed.cpp:2233 (18)
    //         004ab793     MOV        EAX,dword ptr [ESI + 0x938]
    //         004ab799     MOV        this,dword ptr [ESI + 0x934]
    //         004ab79f     SUB        EAX,EDI
    //         004ab7a1     CMP        EAX,this
    //         004ab7a3     JC         LAB_004ab7b8
    //                              scr_sed.cpp:2235 (13)
    //         004ab7a5     MOV        this,dword ptr [ESI + 0x4cc]
    //         004ab7ab     PUSH       0x1
    //         004ab7ad     MOV        EDX,dword ptr [this->_padding_]
    //         004ab7af     CALL       dword ptr [EDX + 0x20]
    //                              scr_sed.cpp:2236 (6)
    //         004ab7b2     MOV        dword ptr [ESI + 0x938],EDI
    //                               LAB_004ab7b8                                                 XREF[4]:     004ab750(j), 004ab776(j), 
    //                                                                                                         004ab784(j), 004ab7a3(j)  
    //                              scr_sed.cpp:2242 (7)
    //         004ab7b8     MOV        this,ESI
    //         004ab7ba     CALL       TPanel::handle_idle                              long handle_idle(TPanel * this)
    //                              scr_sed.cpp:2243 (3)
    //         004ab7bf     POP        EDI
    //         004ab7c0     POP        ESI
    //         004ab7c1     RET
    //         004ab7c2     ??         90h
    //         004ab7c3     NOP
    //         004ab7c4     NOP
    //         004ab7c5     NOP
    //         004ab7c6     NOP
    //         004ab7c7     NOP
    //         004ab7c8     NOP
    //         004ab7c9     NOP
    //         004ab7ca     NOP
    //         004ab7cb     NOP
    //         004ab7cc     NOP
    //         004ab7cd     NOP
    //         004ab7ce     NOP
    //         004ab7cf     NOP
    return 0;
}

long TRIBE_Screen_Sed::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) {
    /* TODO: Stub */
    //                              long __thiscall key_down_action(TRIBE_Screen_Sed * this, long param_
    //              long              EAX:4          <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[2]:     004ab7f5(R), 004ab9cf(R)  
    //              short             Stack[0x8]:2   param_2
    //              int               Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     004ab7e7(R)  
    //              int               Stack[0x14]:4  param_5
    //                               ?key_down_action@TRIBE_Screen_Sed@@UAEJJFHHH@Z               XREF[1]:     00573a6c(*)  
    //                               TRIBE_Screen_Sed::key_down_action
    //                              scr_sed.cpp:2249 (5)
    //         004ab7d0     PUSH       EBX
    //         004ab7d1     PUSH       ESI
    //         004ab7d2     MOV        ESI,this
    //         004ab7d4     PUSH       EDI
    //                              scr_sed.cpp:2255 (12)
    //         004ab7d5     MOV        this,panel_system
    //         004ab7da     CALL       TPanelSystem::modalPanel                         TPanel * modalPanel(TPanelSystem * this)
    //         004ab7df     TEST       EAX,EAX
    //                              scr_sed.cpp:2256 (6)
    //         004ab7e1     JNZ        switchD_004ab80d::caseD_45
    //                              scr_sed.cpp:2259 (14)
    //         004ab7e7     MOV        EAX,dword ptr [ESP + param_4]
    //         004ab7eb     XOR        EBX,EBX
    //         004ab7ed     CMP        EAX,EBX
    //         004ab7ef     JZ         LAB_004ab9cf
    //                              scr_sed.cpp:2261 (31)
    //         004ab7f5     MOV        EAX,dword ptr [ESP + param_1]
    //         004ab7f9     ADD        EAX,-0x41
    //         004ab7fc     CMP        EAX,0x16
    //         004ab7ff     JA         switchD_004ab80d::caseD_45
    //         004ab805     XOR        this,this
    //         004ab807     MOV        this,byte ptr [EAX + switchD_004ab80d::switchd
    //                               switchD_004ab80d::switchD
    //         004ab80d     JMP        dword ptr [this->_padding_*0x4 + switchD_004ab   = 004ab814
    //                               switchD_004ab80d::caseD_41                                   XREF[2]:     004ab80d(j), 004abc34(*)  
    //                              scr_sed.cpp:2264 (12)
    //         004ab814     MOV        EAX,[rge_base_game]                              = 00000000
    //         004ab819     MOV        this,0x3
    //         004ab81b     CMP        byte ptr [EAX + 0x50],this
    //         004ab81e     JZ         LAB_004ab82e
    //                              scr_sed.cpp:2265 (3)
    //         004ab820     MOV        byte ptr [EAX + 0x50],this
    //                              scr_sed.cpp:2481 (5)
    //         004ab823     MOV        EAX,0x1
    //                              scr_sed.cpp:2503 (6)
    //         004ab828     POP        EDI
    //         004ab829     POP        ESI
    //         004ab82a     POP        EBX
    //         004ab82b     RET        0x14
    //                               LAB_004ab82e                                                 XREF[1]:     004ab81e(j)  
    //                              scr_sed.cpp:2267 (4)
    //         004ab82e     MOV        byte ptr [EAX + 0x50],0x0
    //                              scr_sed.cpp:2268 (5)
    //         004ab832     MOV        EAX,0x1
    //                              scr_sed.cpp:2503 (6)
    //         004ab837     POP        EDI
    //         004ab838     POP        ESI
    //         004ab839     POP        EBX
    //         004ab83a     RET        0x14
    //                               switchD_004ab80d::caseD_4d                                   XREF[2]:     004ab80d(j), 004abc48(*)  
    //                              scr_sed.cpp:2275 (16)
    //         004ab83d     MOV        this,dword ptr [ESI + 0x4d8]
    //         004ab843     PUSH       0x1
    //         004ab845     MOV        EDX,dword ptr [this->_padding_]
    //         004ab847     CALL       dword ptr [EDX + 0xe0]
    //                              scr_sed.cpp:2276 (9)
    //         004ab84d     PUSH       0x1
    //         004ab84f     MOV        this,ESI
    //         004ab851     CALL       TRIBE_Screen_Sed::set_scenario_mode              void set_scenario_mode(TRIBE_Screen_Sed * thi
    //                              scr_sed.cpp:2502 (2)
    //         004ab856     XOR        EAX,EAX
    //                              scr_sed.cpp:2503 (6)
    //         004ab858     POP        EDI
    //         004ab859     POP        ESI
    //         004ab85a     POP        EBX
    //         004ab85b     RET        0x14
    //                               switchD_004ab80d::caseD_54                                   XREF[2]:     004ab80d(j), 004abc54(*)  
    //                              scr_sed.cpp:2280 (16)
    //         004ab85e     MOV        this,dword ptr [ESI + 0x4dc]
    //         004ab864     PUSH       0x1
    //         004ab866     MOV        EAX,dword ptr [this->_padding_]
    //         004ab868     CALL       dword ptr [EAX + 0xe0]
    //                              scr_sed.cpp:2281 (9)
    //         004ab86e     PUSH       0x2
    //         004ab870     MOV        this,ESI
    //         004ab872     CALL       TRIBE_Screen_Sed::set_scenario_mode              void set_scenario_mode(TRIBE_Screen_Sed * thi
    //                              scr_sed.cpp:2502 (2)
    //         004ab877     XOR        EAX,EAX
    //                              scr_sed.cpp:2503 (6)
    //         004ab879     POP        EDI
    //         004ab87a     POP        ESI
    //         004ab87b     POP        EBX
    //         004ab87c     RET        0x14
    //                               switchD_004ab80d::caseD_50                                   XREF[2]:     004ab80d(j), 004abc50(*)  
    //                              scr_sed.cpp:2285 (16)
    //         004ab87f     MOV        this,dword ptr [ESI + 0x4e0]
    //         004ab885     PUSH       0x1
    //         004ab887     MOV        EDX,dword ptr [this->_padding_]
    //         004ab889     CALL       dword ptr [EDX + 0xe0]
    //                              scr_sed.cpp:2286 (9)
    //         004ab88f     PUSH       0x3
    //         004ab891     MOV        this,ESI
    //         004ab893     CALL       TRIBE_Screen_Sed::set_scenario_mode              void set_scenario_mode(TRIBE_Screen_Sed * thi
    //                              scr_sed.cpp:2502 (2)
    //         004ab898     XOR        EAX,EAX
    //                              scr_sed.cpp:2503 (6)
    //         004ab89a     POP        EDI
    //         004ab89b     POP        ESI
    //         004ab89c     POP        EBX
    //         004ab89d     RET        0x14
    //                               switchD_004ab80d::caseD_55                                   XREF[2]:     004ab80d(j), 004abc58(*)  
    //                              scr_sed.cpp:2290 (16)
    //         004ab8a0     MOV        this,dword ptr [ESI + 0x4e4]
    //         004ab8a6     PUSH       0x1
    //         004ab8a8     MOV        EAX,dword ptr [this->_padding_]
    //         004ab8aa     CALL       dword ptr [EAX + 0xe0]
    //                              scr_sed.cpp:2291 (9)
    //         004ab8b0     PUSH       0x4
    //         004ab8b2     MOV        this,ESI
    //         004ab8b4     CALL       TRIBE_Screen_Sed::set_scenario_mode              void set_scenario_mode(TRIBE_Screen_Sed * thi
    //                              scr_sed.cpp:2502 (2)
    //         004ab8b9     XOR        EAX,EAX
    //                              scr_sed.cpp:2503 (6)
    //         004ab8bb     POP        EDI
    //         004ab8bc     POP        ESI
    //         004ab8bd     POP        EBX
    //         004ab8be     RET        0x14
    //                               switchD_004ab80d::caseD_44                                   XREF[2]:     004ab80d(j), 004abc40(*)  
    //                              scr_sed.cpp:2295 (16)
    //         004ab8c1     MOV        this,dword ptr [ESI + 0x4e8]
    //         004ab8c7     PUSH       0x1
    //         004ab8c9     MOV        EDX,dword ptr [this->_padding_]
    //         004ab8cb     CALL       dword ptr [EDX + 0xe0]
    //                              scr_sed.cpp:2296 (9)
    //         004ab8d1     PUSH       0x5
    //         004ab8d3     MOV        this,ESI
    //         004ab8d5     CALL       TRIBE_Screen_Sed::set_scenario_mode              void set_scenario_mode(TRIBE_Screen_Sed * thi
    //                              scr_sed.cpp:2502 (2)
    //         004ab8da     XOR        EAX,EAX
    //                              scr_sed.cpp:2503 (6)
    //         004ab8dc     POP        EDI
    //         004ab8dd     POP        ESI
    //         004ab8de     POP        EBX
    //         004ab8df     RET        0x14
    //                               switchD_004ab80d::caseD_49                                   XREF[2]:     004ab80d(j), 004abc44(*)  
    //                              scr_sed.cpp:2300 (16)
    //         004ab8e2     MOV        this,dword ptr [ESI + 0x4ec]
    //         004ab8e8     PUSH       0x1
    //         004ab8ea     MOV        EAX,dword ptr [this->_padding_]
    //         004ab8ec     CALL       dword ptr [EAX + 0xe0]
    //                              scr_sed.cpp:2301 (9)
    //         004ab8f2     PUSH       0x6
    //         004ab8f4     MOV        this,ESI
    //         004ab8f6     CALL       TRIBE_Screen_Sed::set_scenario_mode              void set_scenario_mode(TRIBE_Screen_Sed * thi
    //                              scr_sed.cpp:2502 (2)
    //         004ab8fb     XOR        EAX,EAX
    //                              scr_sed.cpp:2503 (6)
    //         004ab8fd     POP        EDI
    //         004ab8fe     POP        ESI
    //         004ab8ff     POP        EBX
    //         004ab900     RET        0x14
    //                               switchD_004ab80d::caseD_56                                   XREF[2]:     004ab80d(j), 004abc5c(*)  
    //                              scr_sed.cpp:2305 (16)
    //         004ab903     MOV        this,dword ptr [ESI + 0x4f0]
    //         004ab909     PUSH       0x1
    //         004ab90b     MOV        EDX,dword ptr [this->_padding_]
    //         004ab90d     CALL       dword ptr [EDX + 0xe0]
    //                              scr_sed.cpp:2306 (9)
    //         004ab913     PUSH       0x7
    //         004ab915     MOV        this,ESI
    //         004ab917     CALL       TRIBE_Screen_Sed::set_scenario_mode              void set_scenario_mode(TRIBE_Screen_Sed * thi
    //                              scr_sed.cpp:2502 (2)
    //         004ab91c     XOR        EAX,EAX
    //                              scr_sed.cpp:2503 (6)
    //         004ab91e     POP        EDI
    //         004ab91f     POP        ESI
    //         004ab920     POP        EBX
    //         004ab921     RET        0x14
    //                               switchD_004ab80d::caseD_4f                                   XREF[2]:     004ab80d(j), 004abc4c(*)  
    //                              scr_sed.cpp:2310 (16)
    //         004ab924     MOV        this,dword ptr [ESI + 0x4f4]
    //         004ab92a     PUSH       0x1
    //         004ab92c     MOV        EAX,dword ptr [this->_padding_]
    //         004ab92e     CALL       dword ptr [EAX + 0xe0]
    //                              scr_sed.cpp:2311 (9)
    //         004ab934     PUSH       0x8
    //         004ab936     MOV        this,ESI
    //         004ab938     CALL       TRIBE_Screen_Sed::set_scenario_mode              void set_scenario_mode(TRIBE_Screen_Sed * thi
    //                              scr_sed.cpp:2502 (2)
    //         004ab93d     XOR        EAX,EAX
    //                              scr_sed.cpp:2503 (6)
    //         004ab93f     POP        EDI
    //         004ab940     POP        ESI
    //         004ab941     POP        EBX
    //         004ab942     RET        0x14
    //                               switchD_004ab80d::caseD_57                                   XREF[2]:     004ab80d(j), 004abc60(*)  
    //                              scr_sed.cpp:2315 (16)
    //         004ab945     MOV        this,dword ptr [ESI + 0x4f8]
    //         004ab94b     PUSH       0x1
    //         004ab94d     MOV        EDX,dword ptr [this->_padding_]
    //         004ab94f     CALL       dword ptr [EDX + 0xe0]
    //                              scr_sed.cpp:2316 (9)
    //         004ab955     PUSH       0x9
    //         004ab957     MOV        this,ESI
    //         004ab959     CALL       TRIBE_Screen_Sed::set_scenario_mode              void set_scenario_mode(TRIBE_Screen_Sed * thi
    //                              scr_sed.cpp:2502 (2)
    //         004ab95e     XOR        EAX,EAX
    //                              scr_sed.cpp:2503 (6)
    //         004ab960     POP        EDI
    //         004ab961     POP        ESI
    //         004ab962     POP        EBX
    //         004ab963     RET        0x14
    //                               switchD_004ab80d::caseD_43                                   XREF[2]:     004ab80d(j), 004abc3c(*)  
    //                              scr_sed.cpp:2320 (16)
    //         004ab966     MOV        this,dword ptr [ESI + 0x4fc]
    //         004ab96c     PUSH       0x1
    //         004ab96e     MOV        EAX,dword ptr [this->_padding_]
    //         004ab970     CALL       dword ptr [EAX + 0xe0]
    //                              scr_sed.cpp:2321 (9)
    //         004ab976     PUSH       0xa
    //         004ab978     MOV        this,ESI
    //         004ab97a     CALL       TRIBE_Screen_Sed::set_scenario_mode              void set_scenario_mode(TRIBE_Screen_Sed * thi
    //                              scr_sed.cpp:2502 (2)
    //         004ab97f     XOR        EAX,EAX
    //                              scr_sed.cpp:2503 (6)
    //         004ab981     POP        EDI
    //         004ab982     POP        ESI
    //         004ab983     POP        EBX
    //         004ab984     RET        0x14
    //                               switchD_004ab80d::caseD_42                                   XREF[2]:     004ab80d(j), 004abc38(*)  
    //                              scr_sed.cpp:2325 (6)
    //         004ab987     MOV        EDX,dword ptr [View_Grid_Mode]
    //                              scr_sed.cpp:2326 (20)
    //         004ab98d     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ab993     INC        EDX
    //         004ab994     MOV        dword ptr [View_Grid_Mode],EDX
    //         004ab99a     CALL       RGE_Base_Game::gameDeveloperMode                 int gameDeveloperMode(RGE_Base_Game * this)
    //         004ab99f     TEST       EAX,EAX
    //                              scr_sed.cpp:2328 (12)
    //         004ab9a1     MOV        EAX,[View_Grid_Mode]
    //         004ab9a6     JZ         LAB_004ab9af
    //         004ab9a8     CMP        EAX,0x4
    //         004ab9ab     JLE        LAB_004ab9ba
    //                              scr_sed.cpp:2330 (2)
    //         004ab9ad     JMP        LAB_004ab9b4
    //                               LAB_004ab9af                                                 XREF[1]:     004ab9a6(j)  
    //                              scr_sed.cpp:2332 (11)
    //         004ab9af     CMP        EAX,0x1
    //         004ab9b2     JLE        LAB_004ab9ba
    //                               LAB_004ab9b4                                                 XREF[1]:     004ab9ad(j)  
    //         004ab9b4     MOV        dword ptr [View_Grid_Mode],EBX
    //                               LAB_004ab9ba                                                 XREF[2]:     004ab9ab(j), 004ab9b2(j)  
    //                              scr_sed.cpp:2334 (13)
    //         004ab9ba     MOV        this,dword ptr [ESI + 0x4c8]
    //         004ab9c0     PUSH       0x2
    //         004ab9c2     MOV        EDX,dword ptr [this->_padding_]
    //         004ab9c4     CALL       dword ptr [EDX + 0x20]
    //                              scr_sed.cpp:2502 (2)
    //         004ab9c7     XOR        EAX,EAX
    //                              scr_sed.cpp:2503 (6)
    //         004ab9c9     POP        EDI
    //         004ab9ca     POP        ESI
    //         004ab9cb     POP        EBX
    //         004ab9cc     RET        0x14
    //                               LAB_004ab9cf                                                 XREF[1]:     004ab7ef(j)  
    //                              scr_sed.cpp:2380 (31)
    //         004ab9cf     MOV        EDI,dword ptr [ESP + param_1]
    //         004ab9d3     LEA        EAX,[EDI + -0x9]
    //         004ab9d6     CMP        EAX,0x2f
    //         004ab9d9     JA         switchD_004ab80d::caseD_45
    //         004ab9df     XOR        this,this
    //         004ab9e1     MOV        this,byte ptr [EAX + 0x4abc94]=>PTR_caseD_2e_0
    //                               switchD_004ab9e7::switchD
    //         004ab9e7     JMP        dword ptr [this->_padding_*0x4 + switchD_004ab   = 004abb53
    //                               switchD_004ab9e7::caseD_31                                   XREF[2]:     004ab9e7(j), 004abc8c(*)  
    //                               switchD_004ab9e7::caseD_32
    //                               switchD_004ab9e7::caseD_33
    //                               switchD_004ab9e7::caseD_34
    //                               switchD_004ab9e7::caseD_35
    //                               switchD_004ab9e7::caseD_36
    //                               switchD_004ab9e7::caseD_37
    //                               switchD_004ab9e7::caseD_38
    //                               switchD_004ab9e7::caseD_30
    //                              scr_sed.cpp:2395 (18)
    //         004ab9ee     MOV        EAX,dword ptr [ESI + 0x4a4]
    //         004ab9f4     ADD        EDI,-0x30
    //         004ab9f7     CMP        EAX,0x8
    //         004ab9fa     JNZ        LAB_004aba4b
    //         004ab9fc     CMP        EDI,EBX
    //         004ab9fe     JLE        LAB_004aba4b
    //                              scr_sed.cpp:2397 (7)
    //         004aba00     MOV        this,ESI
    //         004aba02     CALL       TRIBE_Screen_Sed::SaveDisabledItemsInScenario    void SaveDisabledItemsInScenario(TRIBE_Screen
    //                              scr_sed.cpp:2398 (15)
    //         004aba07     MOV        this,dword ptr [ESI + 0x7cc]
    //         004aba0d     LEA        EDX,[EDI + -0x1]
    //         004aba10     PUSH       EDX
    //         004aba11     CALL       TDropDownPanel::setCurrentLineNumber             void setCurrentLineNumber(TDropDownPanel * th
    //                              scr_sed.cpp:2399 (21)
    //         004aba16     MOV        this,dword ptr [ESI + 0x7cc]
    //         004aba1c     MOV        EAX,dword ptr [ESI]
    //         004aba1e     PUSH       EBX
    //         004aba1f     PUSH       EBX
    //         004aba20     PUSH       0x3
    //         004aba22     PUSH       this
    //         004aba23     MOV        this,ESI
    //         004aba25     CALL       dword ptr [EAX + 0xb4]
    //                              scr_sed.cpp:2400 (10)
    //         004aba2b     PUSH       EBX
    //         004aba2c     PUSH       EBX=>DAT_fffffff8
    //         004aba2d     PUSH       EDI=>DAT_fffffff4
    //         004aba2e     MOV        this,ESI
    //         004aba30     CALL       TRIBE_Screen_Sed::set_player                     void set_player(TRIBE_Screen_Sed * this, shor
    //                              scr_sed.cpp:2402 (14)
    //         004aba35     MOV        this,ESI
    //         004aba37     MOV        word ptr [ESI + 0x4b8],DI
    //         004aba3e     CALL       TRIBE_Screen_Sed::LoadDisabledItemsFromScenario  void LoadDisabledItemsFromScenario(TRIBE_Scre
    //                              scr_sed.cpp:2502 (2)
    //         004aba43     XOR        EAX,EAX
    //                              scr_sed.cpp:2503 (6)
    //         004aba45     POP        EDI
    //         004aba46     POP        ESI
    //         004aba47     POP        EBX
    //         004aba48     RET        0x14
    //                               LAB_004aba4b                                                 XREF[2]:     004ab9fa(j), 004ab9fe(j)  
    //                              scr_sed.cpp:2404 (9)
    //         004aba4b     CMP        EAX,0x3
    //         004aba4e     JNZ        LAB_004aba8c
    //         004aba50     CMP        EDI,EBX
    //         004aba52     JLE        LAB_004aba8c
    //                              scr_sed.cpp:2406 (15)
    //         004aba54     MOV        EDX,dword ptr [ESI + 0x4d4]
    //         004aba5a     CMP        dword ptr [EDX + 0x3c],EBX
    //         004aba5d     JNZ        switchD_004ab80d::caseD_45
    //                              scr_sed.cpp:2409 (13)
    //         004aba63     MOV        this,dword ptr [ESI + 0x5b4]
    //         004aba69     DEC        EDI
    //         004aba6a     PUSH       EDI
    //         004aba6b     CALL       TDropDownPanel::setCurrentLineNumber             void setCurrentLineNumber(TDropDownPanel * th
    //                              scr_sed.cpp:2410 (20)
    //         004aba70     MOV        this,dword ptr [ESI + 0x5b4]
    //         004aba76     MOV        EAX,dword ptr [ESI]
    //         004aba78     PUSH       EBX
    //         004aba79     PUSH       EBX
    //         004aba7a     PUSH       EBX
    //         004aba7b     PUSH       this
    //         004aba7c     MOV        this,ESI
    //         004aba7e     CALL       dword ptr [EAX + 0xb4]
    //                              scr_sed.cpp:2502 (2)
    //         004aba84     XOR        EAX,EAX
    //                              scr_sed.cpp:2503 (6)
    //         004aba86     POP        EDI
    //         004aba87     POP        ESI
    //         004aba88     POP        EBX
    //         004aba89     RET        0x14
    //                               LAB_004aba8c                                                 XREF[2]:     004aba4e(j), 004aba52(j)  
    //                              scr_sed.cpp:2415 (5)
    //         004aba8c     CMP        EAX,0x4
    //         004aba8f     JNZ        LAB_004abab9
    //                              scr_sed.cpp:2417 (12)
    //         004aba91     MOV        this,dword ptr [ESI + 0x618]
    //         004aba97     PUSH       EDI
    //         004aba98     CALL       TDropDownPanel::setCurrentLineNumber             void setCurrentLineNumber(TDropDownPanel * th
    //                              scr_sed.cpp:2418 (20)
    //         004aba9d     MOV        EAX,dword ptr [ESI + 0x618]
    //         004abaa3     MOV        EDX,dword ptr [ESI]
    //         004abaa5     PUSH       EBX
    //         004abaa6     PUSH       EBX
    //         004abaa7     PUSH       EBX
    //         004abaa8     PUSH       EAX
    //         004abaa9     MOV        this,ESI
    //         004abaab     CALL       dword ptr [EDX + 0xb4]
    //                              scr_sed.cpp:2502 (2)
    //         004abab1     XOR        EAX,EAX
    //                              scr_sed.cpp:2503 (6)
    //         004abab3     POP        EDI
    //         004abab4     POP        ESI
    //         004abab5     POP        EBX
    //         004abab6     RET        0x14
    //                               LAB_004abab9                                                 XREF[1]:     004aba8f(j)  
    //                              scr_sed.cpp:2420 (9)
    //         004abab9     CMP        EAX,0x6
    //         004ababc     JNZ        LAB_004abafb
    //         004ababe     CMP        EDI,EBX
    //         004abac0     JLE        LAB_004abafb
    //                              scr_sed.cpp:2422 (15)
    //         004abac2     MOV        this,dword ptr [ESI + 0x4d4]
    //         004abac8     CMP        dword ptr [ECX + this->_padding_],EBX
    //         004abacb     JNZ        switchD_004ab80d::caseD_45
    //                              scr_sed.cpp:2425 (13)
    //         004abad1     MOV        this,dword ptr [ESI + 0x73c]
    //         004abad7     DEC        EDI
    //         004abad8     PUSH       EDI
    //         004abad9     CALL       TDropDownPanel::setCurrentLineNumber             void setCurrentLineNumber(TDropDownPanel * th
    //                              scr_sed.cpp:2426 (21)
    //         004abade     MOV        EAX,dword ptr [ESI + 0x73c]
    //         004abae4     MOV        EDX,dword ptr [ESI]
    //         004abae6     PUSH       EBX
    //         004abae7     PUSH       EBX
    //         004abae8     PUSH       0x1
    //         004abaea     PUSH       EAX
    //         004abaeb     MOV        this,ESI
    //         004abaed     CALL       dword ptr [EDX + 0xb4]
    //                              scr_sed.cpp:2502 (2)
    //         004abaf3     XOR        EAX,EAX
    //                              scr_sed.cpp:2503 (6)
    //         004abaf5     POP        EDI
    //         004abaf6     POP        ESI
    //         004abaf7     POP        EBX
    //         004abaf8     RET        0x14
    //                               LAB_004abafb                                                 XREF[2]:     004ababc(j), 004abac0(j)  
    //                              scr_sed.cpp:2429 (13)
    //         004abafb     CMP        EAX,0x5
    //         004abafe     JNZ        LAB_004abb32
    //         004abb00     CMP        EDI,EBX
    //         004abb02     JLE        switchD_004ab80d::caseD_45
    //                              scr_sed.cpp:2434 (13)
    //         004abb08     MOV        this,dword ptr [ESI + 0x894]
    //         004abb0e     DEC        EDI
    //         004abb0f     PUSH       EDI
    //         004abb10     CALL       TDropDownPanel::setCurrentLineNumber             void setCurrentLineNumber(TDropDownPanel * th
    //                              scr_sed.cpp:2435 (21)
    //         004abb15     MOV        EAX,dword ptr [ESI + 0x894]
    //         004abb1b     MOV        EDX,dword ptr [ESI]
    //         004abb1d     PUSH       EBX
    //         004abb1e     PUSH       EBX
    //         004abb1f     PUSH       0x1
    //         004abb21     PUSH       EAX
    //         004abb22     MOV        this,ESI
    //         004abb24     CALL       dword ptr [EDX + 0xb4]
    //                              scr_sed.cpp:2502 (2)
    //         004abb2a     XOR        EAX,EAX
    //                              scr_sed.cpp:2503 (6)
    //         004abb2c     POP        EDI
    //         004abb2d     POP        ESI
    //         004abb2e     POP        EBX
    //         004abb2f     RET        0x14
    //                               LAB_004abb32                                                 XREF[1]:     004abafe(j)  
    //                              scr_sed.cpp:2437 (8)
    //         004abb32     CMP        EDI,EBX
    //         004abb34     JLE        switchD_004ab80d::caseD_45
    //                              scr_sed.cpp:2439 (10)
    //         004abb3a     PUSH       EBX
    //         004abb3b     PUSH       EBX
    //         004abb3c     PUSH       EDI
    //         004abb3d     MOV        this,ESI
    //         004abb3f     CALL       TRIBE_Screen_Sed::set_player                     void set_player(TRIBE_Screen_Sed * this, shor
    //                              scr_sed.cpp:2440 (7)
    //         004abb44     MOV        word ptr [ESI + 0x4b8],DI
    //                              scr_sed.cpp:2502 (2)
    //         004abb4b     XOR        EAX,EAX
    //                              scr_sed.cpp:2503 (6)
    //         004abb4d     POP        EDI
    //         004abb4e     POP        ESI
    //         004abb4f     POP        EBX
    //         004abb50     RET        0x14
    //                               switchD_004ab9e7::caseD_9                                    XREF[2]:     004ab9e7(j), 004abc80(*)  
    //                              scr_sed.cpp:2445 (11)
    //         004abb53     MOV        EAX,dword ptr [ESI + 0x4a4]
    //         004abb59     CMP        EAX,0x3
    //         004abb5c     JNZ        LAB_004abb81
    //                              scr_sed.cpp:2447 (15)
    //         004abb5e     MOV        this,dword ptr [ESI + 0x4d4]
    //         004abb64     CMP        dword ptr [ECX + this->_padding_],EBX
    //         004abb67     JNZ        switchD_004ab80d::caseD_45
    //                              scr_sed.cpp:2448 (12)
    //         004abb6d     MOV        EDX,dword ptr [ESI + 0x5d8]
    //         004abb73     PUSH       EDX
    //         004abb74     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              scr_sed.cpp:2502 (2)
    //         004abb79     XOR        EAX,EAX
    //                              scr_sed.cpp:2503 (6)
    //         004abb7b     POP        EDI
    //         004abb7c     POP        ESI
    //         004abb7d     POP        EBX
    //         004abb7e     RET        0x14
    //                               LAB_004abb81                                                 XREF[1]:     004abb5c(j)  
    //                              scr_sed.cpp:2450 (9)
    //         004abb81     CMP        EAX,0x6
    //         004abb84     JNZ        switchD_004ab80d::caseD_45
    //                              scr_sed.cpp:2452 (30)
    //         004abb8a     MOV        this,dword ptr [ESI + 0x4d4]
    //         004abb90     CMP        dword ptr [ECX + this->_padding_],EBX
    //         004abb93     JNZ        switchD_004ab80d::caseD_45
    //         004abb99     MOV        ESI,dword ptr [ESI + 0x76c]
    //         004abb9f     CMP        dword ptr [ESI + 0x6c],EBX
    //         004abba2     JZ         switchD_004ab80d::caseD_45
    //                              scr_sed.cpp:2453 (6)
    //         004abba8     PUSH       ESI
    //         004abba9     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              scr_sed.cpp:2502 (2)
    //         004abbae     XOR        EAX,EAX
    //                              scr_sed.cpp:2503 (6)
    //         004abbb0     POP        EDI
    //         004abbb1     POP        ESI
    //         004abbb2     POP        EBX
    //         004abbb3     RET        0x14
    //                               switchD_004ab9e7::caseD_1b                                   XREF[2]:     004ab9e7(j), 004abc84(*)  
    //                              scr_sed.cpp:2459 (7)
    //         004abbb6     MOV        this,ESI
    //         004abbb8     CALL       TRIBE_Screen_Sed::command_cancel                 void command_cancel(TRIBE_Screen_Sed * this)
    //                              scr_sed.cpp:2502 (2)
    //         004abbbd     XOR        EAX,EAX
    //                              scr_sed.cpp:2503 (6)
    //         004abbbf     POP        EDI
    //         004abbc0     POP        ESI
    //         004abbc1     POP        EBX
    //         004abbc2     RET        0x14
    //                               switchD_004ab9e7::caseD_2e                                   XREF[2]:     004ab9e7(j), 004abc88(*)  
    //                              scr_sed.cpp:2463 (9)
    //         004abbc5     CMP        dword ptr [ESI + 0x4a4],0x4
    //         004abbcc     JNZ        switchD_004ab80d::caseD_45
    //                              scr_sed.cpp:2465 (17)
    //         004abbce     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004abbd4     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004abbd9     MOV        EDI,dword ptr [EAX + 0x130]
    //                              scr_sed.cpp:2466 (4)
    //         004abbdf     CMP        EDI,EBX
    //         004abbe1     JZ         LAB_004abc1e
    //                              scr_sed.cpp:2468 (7)
    //         004abbe3     MOV        this,dword ptr [EDI + 0x18]
    //         004abbe6     CMP        this,EBX
    //         004abbe8     JZ         LAB_004abbf3
    //                              scr_sed.cpp:2469 (7)
    //         004abbea     CALL       RGE_Active_Sprite_List::get_lowest_draw_level    uchar get_lowest_draw_level(RGE_Active_Sprite
    //         004abbef     MOV        BL,AL
    //                              scr_sed.cpp:2470 (9)
    //         004abbf1     JMP        LAB_004abc05
    //                               LAB_004abbf3                                                 XREF[1]:     004abbe8(j)  
    //         004abbf3     MOV        this,dword ptr [EDI + 0x10]
    //         004abbf6     CMP        this,EBX
    //         004abbf8     JZ         LAB_004abc03
    //                              scr_sed.cpp:2471 (7)
    //         004abbfa     CALL       RGE_Sprite::get_lowest_draw_level                uchar get_lowest_draw_level(RGE_Sprite * this)
    //         004abbff     MOV        BL,AL
    //                              scr_sed.cpp:2472 (2)
    //         004abc01     JMP        LAB_004abc05
    //                               LAB_004abc03                                                 XREF[1]:     004abbf8(j)  
    //                              scr_sed.cpp:2473 (2)
    //         004abc03     MOV        BL,0x14
    //                               LAB_004abc05                                                 XREF[2]:     004abbf1(j), 004abc01(j)  
    //                              scr_sed.cpp:2476 (8)
    //         004abc05     MOV        EAX,dword ptr [EDI]
    //         004abc07     PUSH       0x1
    //         004abc09     MOV        this,EDI
    //         004abc0b     CALL       dword ptr [EAX]
    //                              scr_sed.cpp:2478 (4)
    //         004abc0d     TEST       BL,BL
    //         004abc0f     JNZ        LAB_004abc1e
    //                              scr_sed.cpp:2479 (13)
    //         004abc11     MOV        this,dword ptr [ESI + 0x4c8]
    //         004abc17     PUSH       0x2
    //         004abc19     MOV        EDX,dword ptr [this->_padding_]
    //         004abc1b     CALL       dword ptr [EDX + 0x20]
    //                               LAB_004abc1e                                                 XREF[2]:     004abbe1(j), 004abc0f(j)  
    //                              scr_sed.cpp:2481 (5)
    //         004abc1e     MOV        EAX,0x1
    //                              scr_sed.cpp:2503 (161)
    //         004abc23     POP        EDI
    //         004abc24     POP        ESI
    //         004abc25     POP        EBX
    //         004abc26     RET        0x14
    //                               switchD_004ab80d::caseD_46                                   XREF[16]:    004ab7e1(j), 004ab7ff(j), 
    //                               switchD_004ab80d::caseD_47                                                004ab80d(j), 004ab9d9(j), 
    //                               switchD_004ab80d::caseD_48                                                004ab9e7(j), 004aba5d(j), 
    //                               switchD_004ab80d::caseD_4a                                                004abacb(j), 004abb02(j), 
    //                               switchD_004ab80d::caseD_4b                                                004abb34(j), 004abb67(j), 
    //                               switchD_004ab80d::caseD_4c                                                004abb84(j), 004abb93(j), 
    //                               switchD_004ab80d::caseD_4e                                                004abba2(j), 004abbcc(j), 
    //                               switchD_004ab80d::caseD_51                                                004abc64(*), 004abc90(*)  
    //                               switchD_004ab80d::caseD_52
    //                               switchD_004ab80d::caseD_53
    //                               switchD_004ab9e7::caseD_a
    //                               switchD_004ab9e7::caseD_b
    //                               switchD_004ab9e7::caseD_c
    //                               switchD_004ab9e7::caseD_d
    //                               switchD_004ab9e7::caseD_e
    //                               switchD_004ab9e7::caseD_f
    //                               switchD_004ab9e7::caseD_10
    //                               switchD_004ab9e7::caseD_11
    //                               switchD_004ab9e7::caseD_12
    //                               switchD_004ab9e7::caseD_13
    //                               switchD_004ab9e7::caseD_14
    //                               switchD_004ab9e7::caseD_15
    //                               switchD_004ab9e7::caseD_16
    //                               switchD_004ab9e7::caseD_17
    //                               switchD_004ab9e7::caseD_18
    //                               switchD_004ab9e7::caseD_19
    //                               switchD_004ab9e7::caseD_1a
    //                               switchD_004ab9e7::caseD_1c
    //                               switchD_004ab9e7::caseD_1d
    //                               switchD_004ab9e7::caseD_1e
    //                               switchD_004ab9e7::caseD_1f
    //                               switchD_004ab9e7::caseD_20
    //                               switchD_004ab9e7::caseD_21
    //                               switchD_004ab9e7::caseD_22
    //                               switchD_004ab9e7::caseD_23
    //                               switchD_004ab9e7::caseD_24
    //                               switchD_004ab9e7::caseD_25
    //                               switchD_004ab9e7::caseD_26
    //                               switchD_004ab9e7::caseD_27
    //                               switchD_004ab9e7::caseD_28
    //                               switchD_004ab9e7::caseD_29
    //                               switchD_004ab9e7::caseD_2a
    //                               switchD_004ab9e7::caseD_2b
    //                               switchD_004ab9e7::caseD_2c
    //                               switchD_004ab9e7::caseD_2d
    //                               switchD_004ab9e7::caseD_2f
    //                               switchD_004ab80d::caseD_45
    //         004abc29     POP        EDI
    //         004abc2a     POP        ESI
    //         004abc2b     XOR        EAX,EAX
    //         004abc2d     POP        EBX
    //         004abc2e     RET        0x14
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_004abc31()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_004abc31
    //         004abc31     NOP
    //         004abc32     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004ab80d::switchdataD_004abc34                       XREF[1]:     key_down_action:004ab80d(*)  
    //         004abc34     addr       switchD_004ab80d::caseD_41
    //         004abc38     addr       switchD_004ab80d::caseD_42
    //         004abc3c     addr       switchD_004ab80d::caseD_43
    //         004abc40     addr       switchD_004ab80d::caseD_44
    //         004abc44     addr       switchD_004ab80d::caseD_49
    //         004abc48     addr       switchD_004ab80d::caseD_4d
    //         004abc4c     addr       switchD_004ab80d::caseD_4f
    //         004abc50     addr       switchD_004ab80d::caseD_50
    //         004abc54     addr       switchD_004ab80d::caseD_54
    //         004abc58     addr       switchD_004ab80d::caseD_55
    //         004abc5c     addr       switchD_004ab80d::caseD_56
    //         004abc60     addr       switchD_004ab80d::caseD_57
    //         004abc64     addr       switchD_004ab80d::caseD_45
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004ab80d::switchdataD_004abc68                       XREF[1]:     key_down_action:004ab807(*)  
    //         004abc68     db         0h
    //         004abc69     db         1h
    //         004abc6a     db         2h
    //         004abc6b     db         3h
    //         004abc6c     db         Ch
    //         004abc6d     db         Ch
    //         004abc6e     db         Ch
    //         004abc6f     db         Ch
    //         004abc70     db         4h
    //         004abc71     db         Ch
    //         004abc72     db         Ch
    //         004abc73     db         Ch
    //         004abc74     db         5h
    //         004abc75     db         Ch
    //         004abc76     db         6h
    //         004abc77     db         7h
    //         004abc78     db         Ch
    //         004abc79     db         Ch
    //         004abc7a     db         Ch
    //         004abc7b     db         8h
    //         004abc7c     db         9h
    //         004abc7d     db         Ah
    //         004abc7e     db         Bh
    //         004abc7f     ??         90h
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004ab9e7::switchdataD_004abc80                       XREF[1]:     key_down_action:004ab9e7(*)  
    //         004abc80     addr       switchD_004ab9e7::caseD_9
    //         004abc84     addr       switchD_004ab9e7::caseD_1b
    //                               PTR_caseD_2e_004abc88+3                                      XREF[0,1]:   key_down_action:004ab9e1(*)  
    //         004abc88     addr       switchD_004ab9e7::caseD_2e
    //         004abc8c     addr       switchD_004ab9e7::caseD_30
    //         004abc90     addr       switchD_004ab80d::caseD_45
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004ab9e7::switchdataD_004abc94
    //         004abc94     db         0h
    //         004abc95     db         4h
    //         004abc96     db         4h
    //         004abc97     db         4h
    //         004abc98     db         4h
    //         004abc99     db         4h
    //         004abc9a     db         4h
    //         004abc9b     db         4h
    //         004abc9c     db         4h
    //         004abc9d     db         4h
    //         004abc9e     db         4h
    //         004abc9f     db         4h
    //         004abca0     db         4h
    //         004abca1     db         4h
    //         004abca2     db         4h
    //         004abca3     db         4h
    //         004abca4     db         4h
    //         004abca5     db         4h
    //         004abca6     db         1h
    //         004abca7     db         4h
    //         004abca8     db         4h
    //         004abca9     db         4h
    //         004abcaa     db         4h
    //         004abcab     db         4h
    //         004abcac     db         4h
    //         004abcad     db         4h
    //         004abcae     db         4h
    //         004abcaf     db         4h
    //         004abcb0     db         4h
    //         004abcb1     db         4h
    //         004abcb2     db         4h
    //         004abcb3     db         4h
    //         004abcb4     db         4h
    //         004abcb5     db         4h
    //         004abcb6     db         4h
    //         004abcb7     db         4h
    //         004abcb8     db         4h
    //         004abcb9     db         2h
    //         004abcba     db         4h
    //         004abcbb     db         3h
    //         004abcbc     db         3h
    //         004abcbd     db         3h
    //         004abcbe     db         3h
    //         004abcbf     db         3h
    //         004abcc0     db         3h
    //         004abcc1     db         3h
    //         004abcc2     db         3h
    //         004abcc3     db         3h
    //         004abcc4     ??         90h
    //         004abcc5     ??         90h
    //         004abcc6     ??         90h
    //         004abcc7     ??         90h
    //         004abcc8     ??         90h
    //         004abcc9     ??         90h
    //         004abcca     ??         90h
    //         004abccb     ??         90h
    //         004abccc     ??         90h
    //         004abccd     ??         90h
    //         004abcce     ??         90h
    //         004abccf     ??         90h
    //                              * public: virtual long __thiscall TRIBE_Screen_Sed::action(class TPanel *,long,unsigned long,unsigne... *
    //                              long __thiscall action(TRIBE_Screen_Sed * this, TPanel * param_1, lo
    //              long              EAX:4          <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     004abcea(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     004abd43(R)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[1]:     004abdf2(R)  
    //              ulong             Stack[0x10]:4  param_4
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004abe5f(R)  
    //              char[24]          Stack[-0x28]   random_val
    //              long              Stack[-0x2c]:4 y2
    //              long              Stack[-0x30]:4 y1
    //              long              Stack[-0x34]:4 x1
    //              long              Stack[-0x38]:4 x2
    //                               ?action@TRIBE_Screen_Sed@@UAEJPAVTPanel@@JKK@Z               XREF[1]:     00573a74(*)  
    //                               TRIBE_Screen_Sed::action
    //                              scr_sed.cpp:2509 (26)
    //         004abcd0     MOV        EAX,FS:[0x0]
    //         004abcd6     PUSH       -0x1
    //         004abcd8     PUSH       FUN_0055f48b
    //         004abcdd     PUSH       EAX
    //         004abcde     MOV        dword ptr FS:[0x0],ESP
    //         004abce5     SUB        ESP,0x28
    //         004abce8     PUSH       EBX
    //         004abce9     PUSH       EBP
    //                              scr_sed.cpp:2514 (12)
    //         004abcea     MOV        EBP,dword ptr [ESP + param_1]
    //         004abcee     PUSH       ESI
    //         004abcef     TEST       EBP,EBP
    //         004abcf1     PUSH       EDI
    //         004abcf2     MOV        ESI,this
    //         004abcf4     JNZ        LAB_004abcfd
    //                              scr_sed.cpp:2515 (7)
    //         004abcf6     XOR        EAX,EAX
    //         004abcf8     JMP        LAB_004abe5f
    //                               LAB_004abcfd                                                 XREF[1]:     004abcf4(j)  
    //                              scr_sed.cpp:2517 (8)
    //         004abcfd     CMP        EBP,dword ptr [ESI + 0x4c8]
    //         004abd03     JZ         LAB_004abd43
    //                              scr_sed.cpp:2519 (10)
    //         004abd05     MOV        EAX,dword ptr [ESI + 0x480]
    //         004abd0b     TEST       EAX,EAX
    //         004abd0d     JZ         LAB_004abd24
    //                              scr_sed.cpp:2520 (21)
    //         004abd0f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004abd15     PUSH       0x0
    //         004abd17     PUSH       EAX
    //         004abd18     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004abd1d     MOV        this,EAX
    //         004abd1f     CALL       RGE_Player::select_one_object                    int select_one_object(RGE_Player * this, RGE_
    //                               LAB_004abd24                                                 XREF[1]:     004abd0d(j)  
    //                              scr_sed.cpp:2522 (10)
    //         004abd24     MOV        EAX,dword ptr [ESI + 0x484]
    //         004abd2a     TEST       EAX,EAX
    //         004abd2c     JZ         LAB_004abd43
    //                              scr_sed.cpp:2523 (21)
    //         004abd2e     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004abd34     PUSH       0x0
    //         004abd36     PUSH       EAX
    //         004abd37     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004abd3c     MOV        this,EAX
    //         004abd3e     CALL       RGE_Player::select_one_object                    int select_one_object(RGE_Player * this, RGE_
    //                               LAB_004abd43                                                 XREF[2]:     004abd03(j), 004abd2c(j)  
    //                              scr_sed.cpp:2526 (8)
    //         004abd43     MOV        EBX,dword ptr [ESP + param_2]
    //         004abd47     TEST       EBX,EBX
    //         004abd49     JNZ        LAB_004abdc2
    //                              scr_sed.cpp:2540 (112)
    //         004abd4b     CMP        EBP,dword ptr [ESI + 0x540]
    //         004abd51     JZ         LAB_004abdbb
    //         004abd53     CMP        EBP,dword ptr [ESI + 0x5d8]
    //         004abd59     JZ         LAB_004abdbb
    //         004abd5b     CMP        EBP,dword ptr [ESI + 0x5dc]
    //         004abd61     JZ         LAB_004abdbb
    //         004abd63     CMP        EBP,dword ptr [ESI + 0x5e0]
    //         004abd69     JZ         LAB_004abdbb
    //         004abd6b     CMP        EBP,dword ptr [ESI + 0x5e4]
    //         004abd71     JZ         LAB_004abdbb
    //         004abd73     CMP        EBP,dword ptr [ESI + 0x5e8]
    //         004abd79     JZ         LAB_004abdbb
    //         004abd7b     CMP        EBP,dword ptr [ESI + 0x5ec]
    //         004abd81     JZ         LAB_004abdbb
    //         004abd83     CMP        EBP,dword ptr [ESI + 0x6b8]
    //         004abd89     JZ         LAB_004abdbb
    //         004abd8b     CMP        EBP,dword ptr [ESI + 0x6bc]
    //         004abd91     JZ         LAB_004abdbb
    //         004abd93     CMP        EBP,dword ptr [ESI + 0x6c0]
    //         004abd99     JZ         LAB_004abdbb
    //         004abd9b     CMP        EBP,dword ptr [ESI + 0x6c4]
    //         004abda1     JZ         LAB_004abdbb
    //         004abda3     CMP        EBP,dword ptr [ESI + 0x6c8]
    //         004abda9     JZ         LAB_004abdbb
    //         004abdab     CMP        EBP,dword ptr [ESI + 0x76c]
    //         004abdb1     JZ         LAB_004abdbb
    //         004abdb3     CMP        EBP,dword ptr [ESI + 0x774]
    //         004abdb9     JNZ        LAB_004abdc2
    //                               LAB_004abdbb                                                 XREF[13]:    004abd51(j), 004abd59(j), 
    //                                                                                                         004abd61(j), 004abd69(j), 
    //                                                                                                         004abd71(j), 004abd79(j), 
    //                                                                                                         004abd81(j), 004abd89(j), 
    //                                                                                                         004abd91(j), 004abd99(j), 
    //                                                                                                         004abda1(j), 004abda9(j), 
    //                                                                                                         004abdb1(j)  
    //                              scr_sed.cpp:2541 (7)
    //         004abdbb     MOV        byte ptr [ESI + 0x4c0],0x1
    //                               LAB_004abdc2                                                 XREF[2]:     004abd49(j), 004abdb9(j)  
    //                              scr_sed.cpp:2544 (12)
    //         004abdc2     CMP        EBP,dword ptr [ESI + 0x4c8]
    //         004abdc8     JNZ        LAB_004abe90
    //                              scr_sed.cpp:2546 (9)
    //         004abdce     CMP        EBX,0x10
    //         004abdd1     JNZ        LAB_004abe74
    //                              scr_sed.cpp:2548 (18)
    //         004abdd7     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004abddd     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004abde2     MOV        this,EAX
    //         004abde4     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
    //                              scr_sed.cpp:2550 (15)
    //         004abde9     MOV        EAX,dword ptr [ESI + 0x4a0]
    //         004abdef     CMP        EAX,0x1
    //         004abdf2     MOV        EAX,dword ptr [ESP + param_3]
    //         004abdf6     JNZ        LAB_004abdfe
    //                              scr_sed.cpp:2551 (6)
    //         004abdf8     MOV        dword ptr [ESI + 0x480],EAX
    //                               LAB_004abdfe                                                 XREF[1]:     004abdf6(j)  
    //                              scr_sed.cpp:2553 (9)
    //         004abdfe     CMP        dword ptr [ESI + 0x4a0],0x2
    //         004abe05     JNZ        LAB_004abe0d
    //                              scr_sed.cpp:2554 (6)
    //         004abe07     MOV        dword ptr [ESI + 0x484],EAX
    //                               LAB_004abe0d                                                 XREF[1]:     004abe05(j)  
    //                              scr_sed.cpp:2556 (10)
    //         004abe0d     MOV        EAX,dword ptr [ESI + 0x480]
    //         004abe13     TEST       EAX,EAX
    //         004abe15     JZ         LAB_004abe2c
    //                              scr_sed.cpp:2557 (21)
    //         004abe17     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004abe1d     PUSH       0x0
    //         004abe1f     PUSH       EAX
    //         004abe20     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004abe25     MOV        this,EAX
    //         004abe27     CALL       RGE_Player::select_one_object                    int select_one_object(RGE_Player * this, RGE_
    //                               LAB_004abe2c                                                 XREF[1]:     004abe15(j)  
    //                              scr_sed.cpp:2559 (10)
    //         004abe2c     MOV        ESI,dword ptr [ESI + 0x484]
    //         004abe32     TEST       ESI,ESI
    //         004abe34     JZ         LAB_004abe4b
    //                              scr_sed.cpp:2560 (21)
    //         004abe36     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004abe3c     PUSH       0x0
    //         004abe3e     PUSH       ESI
    //         004abe3f     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004abe44     MOV        this,EAX
    //         004abe46     CALL       RGE_Player::select_one_object                    int select_one_object(RGE_Player * this, RGE_
    //                               LAB_004abe4b                                                 XREF[1]:     004abe34(j)  
    //                              scr_sed.cpp:2562 (15)
    //         004abe4b     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004abe51     PUSH       0x0
    //         004abe53     PUSH       0x0
    //         004abe55     MOV        EAX,dword ptr [this->_padding_]
    //         004abe57     CALL       dword ptr [EAX + 0x10]
    //                               LAB_004abe5a                                                 XREF[35]:    004abebd(j), 004abece(j), 
    //                                                                                                         004abeda(j), 004abeef(j), 
    //                                                                                                         004abefb(j), 004abf47(j), 
    //                                                                                                         004abf65(j), 004ac167(j), 
    //                                                                                                         004ac26a(j), 004ac2aa(j), 
    //                                                                                                         004acebc(j), 004acec4(j), 
    //                                                                                                         004acee4(j), 004acef8(j), 
    //                                                                                                         004acf72(j), 004acf7a(j), 
    //                                                                                                         004acfbd(j), 004ad037(j), 
    //                                                                                                         004ad03f(j), 004ad054(j), [more]
    //                              scr_sed.cpp:2608 (5)
    //         004abe5a     MOV        EAX,0x1
    //                               LAB_004abe5f                                                 XREF[2]:     004abcf8(j), 004ad05b(j)  
    //                              scr_sed.cpp:3233 (21)
    //         004abe5f     MOV        this,dword ptr [ESP + local_c]
    //         004abe63     POP        EDI
    //         004abe64     POP        ESI
    //         004abe65     POP        EBP
    //         004abe66     MOV        dword ptr FS:[0x0],this
    //         004abe6d     POP        EBX
    //         004abe6e     ADD        ESP,0x34
    //         004abe71     RET        0x10
    //                               LAB_004abe74                                                 XREF[1]:     004abdd1(j)  
    //                              scr_sed.cpp:2566 (19)
    //         004abe74     CMP        EBX,0x11
    //         004abe77     JNZ        LAB_004abe90
    //         004abe79     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004abe7f     CMP        dword ptr [ECX + this->_padding_],EBX
    //         004abe85     JNZ        LAB_004abe90
    //                              scr_sed.cpp:2567 (9)
    //         004abe87     MOV        EDX,dword ptr [this->_padding_]
    //         004abe89     PUSH       0x0
    //         004abe8b     PUSH       0x0
    //         004abe8d     CALL       dword ptr [EDX + 0x10]
    //                               LAB_004abe90                                                 XREF[3]:     004abdc8(j), 004abe77(j), 
    //                                                                                                         004abe85(j)  
    //                              scr_sed.cpp:2571 (5)
    //         004abe90     CMP        EBX,0x1
    //         004abe93     JNZ        LAB_004abed0
    //                              scr_sed.cpp:2576 (2)
    //         004abe95     XOR        EAX,EAX
    //                              scr_sed.cpp:3233 (40)
    //         004abe97     LEA        this,[ESI + 0x4d8]
    //                               LAB_004abe9d                                                 XREF[1]:     004abeac(j)  
    //         004abe9d     CMP        EBP,dword ptr [this->_padding_]
    //         004abe9f     JZ         LAB_004ad060
    //         004abea5     INC        EAX
    //         004abea6     ADD        this,0x4
    //         004abea9     CMP        EAX,0xa
    //         004abeac     JL         LAB_004abe9d
    //         004abeae     CMP        EBP,dword ptr [ESI + 0x500]
    //         004abeb4     JNZ        LAB_004abebf
    //         004abeb6     MOV        this,ESI
    //         004abeb8     CALL       TRIBE_Screen_Sed::command_menu                   int command_menu(TRIBE_Screen_Sed * this)
    //         004abebd     JMP        LAB_004abe5a
    //                               LAB_004abebf                                                 XREF[1]:     004abeb4(j)  
    //                              scr_sed.cpp:2592 (8)
    //         004abebf     CMP        EBP,dword ptr [ESI + 0x504]
    //         004abec5     JNZ        LAB_004abf01
    //                              scr_sed.cpp:2594 (7)
    //         004abec7     MOV        this,ESI
    //         004abec9     CALL       TEasy_Panel::setup_popup_help                    void setup_popup_help(TEasy_Panel * this)
    //                              scr_sed.cpp:2595 (2)
    //         004abece     JMP        LAB_004abe5a
    //                               LAB_004abed0                                                 XREF[1]:     004abe93(j)  
    //                              scr_sed.cpp:2600 (2)
    //         004abed0     XOR        EAX,EAX
    //                              scr_sed.cpp:3233 (47)
    //         004abed2     LEA        this,[ESI + 0x4d8]
    //                               LAB_004abed8                                                 XREF[1]:     004abee7(j)  
    //         004abed8     CMP        EBP,dword ptr [this->_padding_]
    //         004abeda     JZ         LAB_004abe5a
    //         004abee0     INC        EAX
    //         004abee1     ADD        this,0x4
    //         004abee4     CMP        EAX,0xa
    //         004abee7     JL         LAB_004abed8
    //         004abee9     CMP        EBP,dword ptr [ESI + 0x500]
    //         004abeef     JZ         LAB_004abe5a
    //         004abef5     CMP        EBP,dword ptr [ESI + 0x504]
    //         004abefb     JZ         LAB_004abe5a
    //                               LAB_004abf01                                                 XREF[1]:     004abec5(j)  
    //                              scr_sed.cpp:2612 (68)
    //         004abf01     MOV        this,EBP
    //         004abf03     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //         004abf08     TEST       EAX,EAX
    //         004abf0a     JZ         LAB_004abf6a
    //         004abf0c     MOV        this,EBP
    //         004abf0e     MOV        EDI,s_OKDialog                                   = 4Fh
    //         004abf13     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //                               LAB_004abf18                                                 XREF[1]:     004abf36(j)  
    //         004abf18     MOV        DL,byte ptr [EAX]
    //         004abf1a     MOV        this,DL
    //         004abf1c     CMP        DL,byte ptr [EDI]=>s_OKDialog                    = 4Fh
    //                                                                                  = 44h
    //         004abf1e     JNZ        LAB_004abf3c
    //         004abf20     TEST       this,this
    //         004abf22     JZ         LAB_004abf38
    //         004abf24     MOV        DL,byte ptr [EAX + 0x1]
    //         004abf27     MOV        this,DL
    //         004abf29     CMP        DL,byte ptr [EDI + 0x1]=>DAT_00584eb5            = 4Bh
    //                                                                                  = "ialog"
    //         004abf2c     JNZ        LAB_004abf3c
    //         004abf2e     ADD        EAX,0x2
    //         004abf31     ADD        EDI,0x2
    //         004abf34     TEST       this,this
    //         004abf36     JNZ        LAB_004abf18
    //                               LAB_004abf38                                                 XREF[1]:     004abf22(j)  
    //         004abf38     XOR        EAX,EAX
    //         004abf3a     JMP        LAB_004abf41
    //                               LAB_004abf3c                                                 XREF[2]:     004abf1e(j), 004abf2c(j)  
    //         004abf3c     SBB        EAX,EAX
    //         004abf3e     SBB        EAX,-0x1
    //                               LAB_004abf41                                                 XREF[1]:     004abf3a(j)  
    //         004abf41     TEST       EAX,EAX
    //         004abf43     JNZ        LAB_004abf6a
    //                              scr_sed.cpp:2614 (8)
    //         004abf45     TEST       EBX,EBX
    //         004abf47     JNZ        LAB_004abe5a
    //                              scr_sed.cpp:2616 (15)
    //         004abf4d     PUSH       s_OKDialog                                       = 4Fh
    //         004abf52     MOV        this,panel_system
    //         004abf57     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_sed.cpp:2617 (9)
    //         004abf5c     PUSH       0x3
    //         004abf5e     MOV        this,ESI
    //         004abf60     CALL       TRIBE_Screen_Sed::set_scenario_mode              void set_scenario_mode(TRIBE_Screen_Sed * thi
    //                              scr_sed.cpp:2619 (5)
    //         004abf65     JMP        LAB_004abe5a
    //                               LAB_004abf6a                                                 XREF[2]:     004abf0a(j), 004abf43(j)  
    //                              scr_sed.cpp:2623 (23)
    //         004abf6a     MOV        EAX,dword ptr [ESI + 0x4a4]
    //         004abf70     DEC        EAX
    //         004abf71     CMP        EAX,0x8
    //         004abf74     JA         switchD_004abf7a::default
    //                               switchD_004abf7a::switchD
    //         004abf7a     JMP        dword ptr [EAX*0x4 + switchD_004abf7a::switchd   = 004ac4bc
    //                               switchD_004abf7a::caseD_9                                    XREF[2]:     004abf7a(j), 004ad090(*)  
    //                              scr_sed.cpp:2627 (10)
    //         004abf81     MOV        AL,byte ptr [ESI + 0x4c1]
    //         004abf87     TEST       AL,AL
    //         004abf89     JZ         LAB_004abf92
    //                              scr_sed.cpp:2628 (7)
    //         004abf8b     MOV        byte ptr [ESI + 0x4c0],0x1
    //                               LAB_004abf92                                                 XREF[1]:     004abf89(j)  
    //                              scr_sed.cpp:2629 (9)
    //         004abf92     CMP        EBX,0x1
    //         004abf95     JNZ        switchD_004abf7a::default
    //                              scr_sed.cpp:2631 (33)
    //         004abf9b     MOV        EAX,dword ptr [ESI + 0x7a0]
    //         004abfa1     MOV        this,dword ptr [ESI + 0x774]
    //         004abfa7     PUSH       EAX
    //         004abfa8     CALL       TEditPanel::get_input_buffer                     char * get_input_buffer(TEditPanel * this)
    //         004abfad     MOV        this,dword ptr [ESI + 0x928]
    //         004abfb3     PUSH       EAX
    //         004abfb4     MOV        this,dword ptr [ECX + this->_padding_]
    //         004abfb7     CALL       RGE_Scenario::Set_message                        void Set_message(RGE_Scenario * this, char * 
    //                              scr_sed.cpp:2632 (2)
    //         004abfbc     XOR        EAX,EAX
    //                              scr_sed.cpp:3233 (21)
    //         004abfbe     LEA        this,[ESI + 0x778]
    //                               LAB_004abfc4                                                 XREF[1]:     004abfcf(j)  
    //         004abfc4     CMP        EBP,dword ptr [this->_padding_]
    //         004abfc6     JZ         LAB_004abfd3
    //         004abfc8     INC        EAX
    //         004abfc9     ADD        this,0x4
    //         004abfcc     CMP        EAX,0x5
    //         004abfcf     JL         LAB_004abfc4
    //         004abfd1     JMP        LAB_004abfd9
    //                               LAB_004abfd3                                                 XREF[1]:     004abfc6(j)  
    //                              scr_sed.cpp:2635 (6)
    //         004abfd3     MOV        dword ptr [ESI + 0x7a0],EAX
    //                               LAB_004abfd9                                                 XREF[1]:     004abfd1(j)  
    //                              scr_sed.cpp:2638 (33)
    //         004abfd9     MOV        EAX,dword ptr [ESI + 0x928]
    //         004abfdf     MOV        EDX,dword ptr [ESI + 0x7a0]
    //         004abfe5     PUSH       EDX
    //         004abfe6     MOV        this,dword ptr [EAX + 0x5c]
    //         004abfe9     CALL       RGE_Scenario::Get_message                        char * Get_message(RGE_Scenario * this, long 
    //         004abfee     MOV        this,dword ptr [ESI + 0x774]
    //         004abff4     PUSH       EAX
    //         004abff5     CALL       TEditPanel::set_text                             void set_text(TEditPanel * this, char * param
    //                              scr_sed.cpp:2639 (22)
    //         004abffa     MOV        EAX,dword ptr [ESI + 0x7a0]
    //         004ac000     CMP        EAX,0x4
    //         004ac003     JA         switchD_004abf7a::default
    //                               switchD_004ac009::switchD
    //         004ac009     JMP        dword ptr [EAX*0x4 + switchD_004ac009::switchd   = 004ac010
    //                               switchD_004ac009::caseD_0                                    XREF[2]:     004ac009(j), 004ad094(*)  
    //                              scr_sed.cpp:2642 (18)
    //         004ac010     MOV        this,dword ptr [ESI + 0x774]
    //         004ac016     PUSH       -0x1
    //                              language.dll match for 0x7770: "Type the scenario instruction
    //         004ac018     PUSH       0x7770
    //         004ac01d     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_sed.cpp:2643 (5)
    //         004ac022     JMP        switchD_004abf7a::default
    //                               switchD_004ac009::caseD_1                                    XREF[2]:     004ac009(j), 004ad098(*)  
    //                              scr_sed.cpp:2645 (18)
    //         004ac027     MOV        this,dword ptr [ESI + 0x774]
    //         004ac02d     PUSH       -0x1
    //                              language.dll match for 0x7771: "Type the hints (optional)."
    //         004ac02f     PUSH       0x7771
    //         004ac034     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_sed.cpp:2646 (5)
    //         004ac039     JMP        switchD_004abf7a::default
    //                               switchD_004ac009::caseD_2                                    XREF[2]:     004ac009(j), 004ad09c(*)  
    //                              scr_sed.cpp:2648 (18)
    //         004ac03e     MOV        this,dword ptr [ESI + 0x774]
    //         004ac044     PUSH       -0x1
    //                              language.dll match for 0x7772: "Type the victory message (opt
    //         004ac046     PUSH       0x7772
    //         004ac04b     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_sed.cpp:2649 (5)
    //         004ac050     JMP        switchD_004abf7a::default
    //                               switchD_004ac009::caseD_3                                    XREF[2]:     004ac009(j), 004ad0a0(*)  
    //                              scr_sed.cpp:2651 (18)
    //         004ac055     MOV        this,dword ptr [ESI + 0x774]
    //         004ac05b     PUSH       -0x1
    //                              language.dll match for 0x7773: "Type the loss message (option
    //         004ac05d     PUSH       0x7773
    //         004ac062     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_sed.cpp:2652 (5)
    //         004ac067     JMP        switchD_004abf7a::default
    //                               switchD_004ac009::caseD_4                                    XREF[2]:     004ac009(j), 004ad0a4(*)  
    //                              scr_sed.cpp:2654 (18)
    //         004ac06c     MOV        this,dword ptr [ESI + 0x774]
    //         004ac072     PUSH       -0x1
    //                              language.dll match for 0x7774: "Type the history text (option
    //         004ac074     PUSH       0x7774
    //         004ac079     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_sed.cpp:2659 (5)
    //         004ac07e     JMP        switchD_004abf7a::default
    //                               switchD_004abf7a::caseD_6                                    XREF[2]:     004abf7a(j), 004ad084(*)  
    //                              scr_sed.cpp:2662 (10)
    //         004ac083     MOV        AL,byte ptr [ESI + 0x4c1]
    //         004ac089     TEST       AL,AL
    //         004ac08b     JZ         LAB_004ac094
    //                              scr_sed.cpp:2663 (7)
    //         004ac08d     MOV        byte ptr [ESI + 0x4c0],0x1
    //                               LAB_004ac094                                                 XREF[1]:     004ac08b(j)  
    //                              scr_sed.cpp:2665 (13)
    //         004ac094     TEST       EBX,EBX
    //         004ac096     JZ         LAB_004ac0a1
    //         004ac098     CMP        EBX,0x1
    //         004ac09b     JNZ        LAB_004ac122
    //                               LAB_004ac0a1                                                 XREF[1]:     004ac096(j)  
    //                              scr_sed.cpp:2666 (8)
    //         004ac0a1     CMP        EBP,dword ptr [ESI + 0x73c]
    //         004ac0a7     JNZ        LAB_004ac122
    //                              scr_sed.cpp:2670 (14)
    //         004ac0a9     MOV        this,dword ptr [ESI + 0x498]
    //         004ac0af     PUSH       this
    //         004ac0b0     MOV        this,ESI
    //         004ac0b2     CALL       TRIBE_Screen_Sed::save_victory_cond_in_scenario  void save_victory_cond_in_scenario(TRIBE_Scre
    //                              scr_sed.cpp:2671 (9)
    //         004ac0b7     PUSH       0x0
    //         004ac0b9     MOV        this,ESI
    //         004ac0bb     CALL       TRIBE_Screen_Sed::activate_victory_panel         void activate_victory_panel(TRIBE_Screen_Sed 
    //                              scr_sed.cpp:2672 (11)
    //         004ac0c0     PUSH       0x0
    //         004ac0c2     PUSH       0x0
    //         004ac0c4     MOV        this,ESI
    //         004ac0c6     CALL       TRIBE_Screen_Sed::activate_victory_proper_fields void activate_victory_proper_fields(TRIBE_Scr
    //                              scr_sed.cpp:2673 (12)
    //         004ac0cb     MOV        this,dword ptr [ESI + 0x73c]
    //         004ac0d1     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this)
    //         004ac0d6     INC        EAX
    //                              scr_sed.cpp:2674 (26)
    //         004ac0d7     MOVSX      EDX,AX
    //         004ac0da     MOV        word ptr [ESI + 0x4b8],AX
    //         004ac0e1     MOV        EAX,dword ptr [ESI + 0x928]
    //         004ac0e7     DEC        EDX
    //         004ac0e8     MOV        this,dword ptr [EAX + 0x5c]
    //         004ac0eb     PUSH       EDX
    //         004ac0ec     CALL       T_Scenario::SetSPWhich                           void SetSPWhich(T_Scenario * this, int param_1)
    //                              scr_sed.cpp:2677 (19)
    //         004ac0f1     PUSH       0x0
    //         004ac0f3     MOV        this,ESI
    //         004ac0f5     MOV        dword ptr [ESI + 0x498],0x0
    //         004ac0ff     CALL       TRIBE_Screen_Sed::load_victory_cond_from_scena   void load_victory_cond_from_scenario(TRIBE_Sc
    //                              scr_sed.cpp:2678 (9)
    //         004ac104     PUSH       0x1
    //         004ac106     MOV        this,ESI
    //         004ac108     CALL       TRIBE_Screen_Sed::activate_victory_panel         void activate_victory_panel(TRIBE_Screen_Sed 
    //                              scr_sed.cpp:2679 (21)
    //         004ac10d     MOV        this,dword ptr [ESI + 0x734]
    //         004ac113     PUSH       0x1
    //         004ac115     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this)
    //         004ac11a     PUSH       EAX
    //         004ac11b     MOV        this,ESI
    //         004ac11d     CALL       TRIBE_Screen_Sed::activate_victory_proper_fields void activate_victory_proper_fields(TRIBE_Scr
    //                               LAB_004ac122                                                 XREF[2]:     004ac09b(j), 004ac0a7(j)  
    //                              scr_sed.cpp:2682 (4)
    //         004ac122     TEST       EBX,EBX
    //         004ac124     JNZ        LAB_004ac13a
    //                              scr_sed.cpp:2683 (8)
    //         004ac126     CMP        EBP,dword ptr [ESI + 0x76c]
    //         004ac12c     JNZ        LAB_004ac13a
    //                              scr_sed.cpp:2684 (12)
    //         004ac12e     MOV        this,dword ptr [ESI + 0x4d4]
    //         004ac134     PUSH       EBX
    //         004ac135     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                               LAB_004ac13a                                                 XREF[2]:     004ac124(j), 004ac12c(j)  
    //                              scr_sed.cpp:2686 (15)
    //         004ac13a     CMP        EBX,0x2
    //         004ac13d     JNZ        LAB_004ac158
    //         004ac13f     MOV        this,dword ptr [ESI + 0x734]
    //         004ac145     CMP        EBP,this
    //         004ac147     JNZ        LAB_004ac158
    //                              scr_sed.cpp:2687 (15)
    //         004ac149     PUSH       0x1
    //         004ac14b     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this)
    //         004ac150     PUSH       EAX
    //         004ac151     MOV        this,ESI
    //         004ac153     CALL       TRIBE_Screen_Sed::activate_victory_proper_fields void activate_victory_proper_fields(TRIBE_Scr
    //                               LAB_004ac158                                                 XREF[2]:     004ac13d(j), 004ac147(j)  
    //                              scr_sed.cpp:2689 (9)
    //         004ac158     CMP        EBX,0x1
    //         004ac15b     JNZ        switchD_004abf7a::default
    //                              scr_sed.cpp:2693 (6)
    //         004ac161     CMP        EBP,dword ptr [ESI + 0x76c]
    //                              scr_sed.cpp:2694 (6)
    //         004ac167     JZ         LAB_004abe5a
    //                              scr_sed.cpp:2698 (13)
    //         004ac16d     MOV        this,dword ptr [ESI + 0x734]
    //         004ac173     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this)
    //         004ac178     MOV        EDI,EAX
    //                              scr_sed.cpp:2700 (10)
    //         004ac17a     MOV        EAX,dword ptr [ESI + 0x734]
    //         004ac180     CMP        EBP,EAX
    //         004ac182     JNZ        LAB_004ac1b3
    //                              scr_sed.cpp:2702 (15)
    //         004ac184     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ac18a     XOR        EBX,EBX
    //         004ac18c     PUSH       EBX
    //         004ac18d     PUSH       EBX
    //         004ac18e     MOV        EDX,dword ptr [this->_padding_]
    //         004ac190     CALL       dword ptr [EDX + 0x10]
    //                              scr_sed.cpp:2703 (12)
    //         004ac193     MOV        dword ptr [ESI + 0x484],EBX
    //         004ac199     MOV        dword ptr [ESI + 0x480],EBX
    //                              scr_sed.cpp:2704 (22)
    //         004ac19f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ac1a5     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004ac1aa     MOV        this,EAX
    //         004ac1ac     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
    //         004ac1b1     JMP        LAB_004ac1b5
    //                               LAB_004ac1b3                                                 XREF[1]:     004ac182(j)  
    //         004ac1b3     XOR        EBX,EBX
    //                               LAB_004ac1b5                                                 XREF[1]:     004ac1b1(j)  
    //                              scr_sed.cpp:2708 (5)
    //         004ac1b5     CMP        EDI,0x2
    //         004ac1b8     JNZ        LAB_004ac1d2
    //                              scr_sed.cpp:2710 (6)
    //         004ac1ba     MOV        dword ptr [ESI + 0x484],EBX
    //                              scr_sed.cpp:2711 (18)
    //         004ac1c0     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ac1c6     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004ac1cb     MOV        this,EAX
    //         004ac1cd     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
    //                               LAB_004ac1d2                                                 XREF[1]:     004ac1b8(j)  
    //                              scr_sed.cpp:2714 (8)
    //         004ac1d2     CMP        EBP,dword ptr [ESI + 0x750]
    //         004ac1d8     JNZ        LAB_004ac20f
    //                              scr_sed.cpp:2716 (10)
    //         004ac1da     MOV        dword ptr [ESI + 0x4a0],0x1
    //                              scr_sed.cpp:2717 (14)
    //         004ac1e4     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ac1ea     PUSH       EBX
    //         004ac1eb     PUSH       0x10
    //         004ac1ed     MOV        EAX,dword ptr [this->_padding_]
    //         004ac1ef     CALL       dword ptr [EAX + 0x10]
    //                              scr_sed.cpp:2718 (18)
    //         004ac1f2     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ac1f8     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004ac1fd     MOV        this,EAX
    //         004ac1ff     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
    //                              scr_sed.cpp:2719 (6)
    //         004ac204     MOV        ESI,dword ptr [ESI + 0x484]
    //                              scr_sed.cpp:2720 (5)
    //         004ac20a     JMP        LAB_004ac2a8
    //                               LAB_004ac20f                                                 XREF[1]:     004ac1d8(j)  
    //                              scr_sed.cpp:2724 (19)
    //         004ac20f     MOV        EAX,dword ptr [ESI + 0x754]
    //         004ac215     CMP        EBP,EAX
    //         004ac217     JNZ        LAB_004ac2c9
    //         004ac21d     CMP        EDI,0x1
    //         004ac220     JZ         LAB_004ac26f
    //                              scr_sed.cpp:2726 (10)
    //         004ac222     MOV        dword ptr [ESI + 0x4a0],0x3
    //                              scr_sed.cpp:2727 (18)
    //         004ac22c     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ac232     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004ac237     MOV        this,EAX
    //         004ac239     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
    //                              scr_sed.cpp:2728 (10)
    //         004ac23e     MOV        ESI,dword ptr [ESI + 0x480]
    //         004ac244     CMP        ESI,EBX
    //         004ac246     JZ         LAB_004ac25c
    //                              scr_sed.cpp:2729 (20)
    //         004ac248     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ac24e     PUSH       EBX
    //         004ac24f     PUSH       ESI
    //         004ac250     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004ac255     MOV        this,EAX
    //         004ac257     CALL       RGE_Player::select_one_object                    int select_one_object(RGE_Player * this, RGE_
    //                               LAB_004ac25c                                                 XREF[1]:     004ac246(j)  
    //                              scr_sed.cpp:2730 (14)
    //         004ac25c     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ac262     PUSH       EBX
    //         004ac263     PUSH       0x11
    //         004ac265     MOV        EDX,dword ptr [this->_padding_]
    //         004ac267     CALL       dword ptr [EDX + 0x10]
    //                              scr_sed.cpp:2731 (5)
    //         004ac26a     JMP        LAB_004abe5a
    //                               LAB_004ac26f                                                 XREF[1]:     004ac220(j)  
    //                              scr_sed.cpp:2735 (9)
    //         004ac26f     CMP        EBP,EAX
    //         004ac271     JNZ        LAB_004ac2c9
    //         004ac273     CMP        EDI,0x1
    //         004ac276     JNZ        LAB_004ac2c9
    //                              scr_sed.cpp:2737 (10)
    //         004ac278     MOV        dword ptr [ESI + 0x4a0],0x2
    //                              scr_sed.cpp:2738 (14)
    //         004ac282     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ac288     PUSH       EBX
    //         004ac289     PUSH       0x10
    //         004ac28b     MOV        EAX,dword ptr [this->_padding_]
    //         004ac28d     CALL       dword ptr [EAX + 0x10]
    //                              scr_sed.cpp:2739 (18)
    //         004ac290     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ac296     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004ac29b     MOV        this,EAX
    //         004ac29d     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
    //                              scr_sed.cpp:2740 (14)
    //         004ac2a2     MOV        ESI,dword ptr [ESI + 0x480]
    //                               LAB_004ac2a8                                                 XREF[1]:     004ac20a(j)  
    //         004ac2a8     CMP        ESI,EBX
    //         004ac2aa     JZ         LAB_004abe5a
    //                              scr_sed.cpp:2741 (20)
    //         004ac2b0     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ac2b6     PUSH       EBX
    //         004ac2b7     PUSH       ESI
    //         004ac2b8     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004ac2bd     MOV        this,EAX
    //         004ac2bf     CALL       RGE_Player::select_one_object                    int select_one_object(RGE_Player * this, RGE_
    //                              scr_sed.cpp:2742 (5)
    //         004ac2c4     JMP        LAB_004abe5a
    //                               LAB_004ac2c9                                                 XREF[3]:     004ac217(j), 004ac271(j), 
    //                                                                                                         004ac276(j)  
    //                              scr_sed.cpp:2745 (21)
    //         004ac2c9     CMP        EBP,dword ptr [ESI + 0x758]
    //         004ac2cf     JNZ        LAB_004ac3ca
    //         004ac2d5     CMP        EDI,0x1
    //         004ac2d8     JZ         LAB_004ac3ca
    //                              scr_sed.cpp:2750 (33)
    //         004ac2de     MOV        this,dword ptr [ESI + 0x4c8]
    //         004ac2e4     LEA        EDX,[ESP + 0x1c]
    //         004ac2e8     PUSH       0x1
    //         004ac2ea     LEA        EAX,[ESP + 0x14]
    //         004ac2ee     PUSH       EDX
    //         004ac2ef     LEA        EDX,[ESP + 0x20]
    //         004ac2f3     PUSH       EAX
    //         004ac2f4     LEA        EAX,[ESP + 0x20]
    //         004ac2f8     PUSH       EDX
    //         004ac2f9     PUSH       EAX
    //         004ac2fa     CALL       RGE_View::get_selection_area                     int get_selection_area(RGE_View * this, long 
    //                              scr_sed.cpp:2751 (12)
    //         004ac2ff     FILD       dword ptr [ESP + 0x10]
    //         004ac303     FILD       dword ptr [ESP + 0x14]
    //         004ac307     FILD       dword ptr [ESP + 0x18]
    //                              scr_sed.cpp:2753 (73)
    //         004ac30b     FLD        ST2
    //         004ac30d     FCOMP      float ptr [DAT_00573ae8]                         = align(2)
    //         004ac313     FILD       dword ptr [ESP + 0x1c]
    //         004ac317     FLD        ST3
    //         004ac319     FLD        ST3
    //         004ac31b     FXCH       ST3
    //         004ac31d     FST        float ptr [ESP + 0x48]
    //         004ac321     FXCH       ST2
    //         004ac323     FST        float ptr [ESP + 0x4c]
    //         004ac327     FXCH       ST3
    //         004ac329     FSTP       float ptr [ESI + 0x488]
    //         004ac32f     FXCH
    //         004ac331     FSTP       float ptr [ESI + 0x48c]
    //         004ac337     FNSTSW     AX
    //         004ac339     MOV        dword ptr [ESI + 0x4a0],EBX
    //         004ac33f     FSTP       float ptr [ESI + 0x490]
    //         004ac345     TEST       AH,0x40
    //         004ac348     FSTP       float ptr [ESI + 0x494]
    //         004ac34e     JZ         LAB_004ac359
    //         004ac350     FSTP       ST0
    //         004ac352     FSTP       ST0
    //                              scr_sed.cpp:2754 (5)
    //         004ac354     JMP        LAB_004abe5a
    //                               LAB_004ac359                                                 XREF[1]:     004ac34e(j)  
    //                              scr_sed.cpp:2756 (16)
    //         004ac359     FLD        ST1
    //         004ac35b     FSUB       ST0,ST1
    //         004ac35d     FMUL       float ptr [DAT_00573aec]
    //         004ac363     FSUBR      ST0,ST2
    //         004ac365     FSTP       float ptr [ESP + 0x50]
    //                              scr_sed.cpp:2758 (54)
    //         004ac369     MOV        EDX,dword ptr [ESP + 0x50]
    //         004ac36d     FSTP       ST0
    //         004ac36f     FSTP       ST0
    //         004ac371     FLD        float ptr [ESP + 0x4c]
    //         004ac375     FSUB       float ptr [ESP + 0x48]
    //         004ac379     FMUL       float ptr [DAT_00573aec]
    //         004ac37f     FSUBR      float ptr [ESP + 0x4c]
    //         004ac383     FSTP       float ptr [ESP + 0x4c]
    //         004ac387     MOV        this,dword ptr [ESP + 0x4c]
    //         004ac38b     PUSH       this
    //         004ac38c     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ac392     PUSH       EDX
    //         004ac393     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004ac398     MOV        this,EAX
    //         004ac39a     CALL       RGE_Player::set_view_loc                         void set_view_loc(RGE_Player * this, float pa
    //                              scr_sed.cpp:2759 (38)
    //         004ac39f     FLD        float ptr [ESP + 0x4c]
    //         004ac3a3     CALL       __ftol                                           undefined __ftol()
    //         004ac3a8     FLD        float ptr [ESP + 0x50]
    //         004ac3ac     PUSH       EAX
    //         004ac3ad     CALL       __ftol                                           undefined __ftol()
    //         004ac3b2     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ac3b8     PUSH       EAX
    //         004ac3b9     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004ac3be     MOV        this,EAX
    //         004ac3c0     CALL       RGE_Player::set_map_loc                          void set_map_loc(RGE_Player * this, short par
    //                              scr_sed.cpp:2760 (5)
    //         004ac3c5     JMP        LAB_004abe5a
    //                               LAB_004ac3ca                                                 XREF[2]:     004ac2cf(j), 004ac2d8(j)  
    //                              scr_sed.cpp:2764 (10)
    //         004ac3ca     MOV        this,dword ptr [ESI + 0x734]
    //         004ac3d0     CMP        EBP,this
    //         004ac3d2     JNZ        LAB_004ac3e2
    //                              scr_sed.cpp:2766 (14)
    //         004ac3d4     PUSH       EBX
    //         004ac3d5     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this)
    //         004ac3da     PUSH       EAX
    //         004ac3db     MOV        this,ESI
    //         004ac3dd     CALL       TRIBE_Screen_Sed::activate_victory_proper_fields void activate_victory_proper_fields(TRIBE_Scr
    //                               LAB_004ac3e2                                                 XREF[1]:     004ac3d2(j)  
    //                              scr_sed.cpp:2769 (8)
    //         004ac3e2     XOR        EDI,EDI
    //         004ac3e4     LEA        EBX,[ESI + 0x704]
    //                               LAB_004ac3ea                                                 XREF[1]:     004ac4ad(j)  
    //                              scr_sed.cpp:2771 (20)
    //         004ac3ea     CMP        EBP,dword ptr [EBX]
    //         004ac3ec     JNZ        LAB_004ac4a6
    //         004ac3f2     CMP        dword ptr [ESI + 0x498],EDI
    //         004ac3f8     JZ         LAB_004ac4a6
    //                              scr_sed.cpp:2773 (21)
    //         004ac3fe     MOV        this,dword ptr [ESI + 0x734]
    //         004ac404     PUSH       0x0
    //         004ac406     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this)
    //         004ac40b     PUSH       EAX
    //         004ac40c     MOV        this,ESI
    //         004ac40e     CALL       TRIBE_Screen_Sed::activate_victory_proper_fields void activate_victory_proper_fields(TRIBE_Scr
    //                              scr_sed.cpp:2774 (14)
    //         004ac413     MOV        EAX,dword ptr [ESI + 0x498]
    //         004ac419     MOV        this,ESI
    //         004ac41b     PUSH       EAX
    //         004ac41c     CALL       TRIBE_Screen_Sed::save_victory_cond_in_scenario  void save_victory_cond_in_scenario(TRIBE_Scre
    //                              scr_sed.cpp:2775 (9)
    //         004ac421     PUSH       0x0
    //         004ac423     MOV        this,ESI
    //         004ac425     CALL       TRIBE_Screen_Sed::activate_victory_panel         void activate_victory_panel(TRIBE_Screen_Sed 
    //                              scr_sed.cpp:2776 (18)
    //         004ac42a     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ac430     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004ac435     MOV        this,EAX
    //         004ac437     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
    //                              scr_sed.cpp:2779 (14)
    //         004ac43c     PUSH       EDI
    //         004ac43d     MOV        this,ESI
    //         004ac43f     MOV        dword ptr [ESI + 0x498],EDI
    //         004ac445     CALL       TRIBE_Screen_Sed::load_victory_cond_from_scena   void load_victory_cond_from_scenario(TRIBE_Sc
    //                              scr_sed.cpp:2780 (9)
    //         004ac44a     PUSH       0x1
    //         004ac44c     MOV        this,ESI
    //         004ac44e     CALL       TRIBE_Screen_Sed::activate_victory_panel         void activate_victory_panel(TRIBE_Screen_Sed 
    //                              scr_sed.cpp:2781 (21)
    //         004ac453     MOV        this,dword ptr [ESI + 0x734]
    //         004ac459     PUSH       0x1
    //         004ac45b     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this)
    //         004ac460     PUSH       EAX
    //         004ac461     MOV        this,ESI
    //         004ac463     CALL       TRIBE_Screen_Sed::activate_victory_proper_fields void activate_victory_proper_fields(TRIBE_Scr
    //                              scr_sed.cpp:2782 (10)
    //         004ac468     MOV        EAX,dword ptr [ESI + 0x480]
    //         004ac46e     TEST       EAX,EAX
    //         004ac470     JZ         LAB_004ac487
    //                              scr_sed.cpp:2783 (21)
    //         004ac472     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ac478     PUSH       0x0
    //         004ac47a     PUSH       EAX
    //         004ac47b     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004ac480     MOV        this,EAX
    //         004ac482     CALL       RGE_Player::select_one_object                    int select_one_object(RGE_Player * this, RGE_
    //                               LAB_004ac487                                                 XREF[1]:     004ac470(j)  
    //                              scr_sed.cpp:2784 (10)
    //         004ac487     MOV        EAX,dword ptr [ESI + 0x484]
    //         004ac48d     TEST       EAX,EAX
    //         004ac48f     JZ         LAB_004ac4a6
    //                              scr_sed.cpp:2785 (34)
    //         004ac491     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ac497     PUSH       0x0
    //         004ac499     PUSH       EAX
    //         004ac49a     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004ac49f     MOV        this,EAX
    //         004ac4a1     CALL       RGE_Player::select_one_object                    int select_one_object(RGE_Player * this, RGE_
    //                               LAB_004ac4a6                                                 XREF[3]:     004ac3ec(j), 004ac3f8(j), 
    //                                                                                                         004ac48f(j)  
    //         004ac4a6     INC        EDI
    //         004ac4a7     ADD        EBX,0x4
    //         004ac4aa     CMP        EDI,0xc
    //         004ac4ad     JL         LAB_004ac3ea
    //                              scr_sed.cpp:2790 (9)
    //         004ac4b3     MOV        EBX,dword ptr [ESP + 0x4c]
    //         004ac4b7     JMP        switchD_004abf7a::default
    //                               switchD_004abf7a::caseD_1                                    XREF[2]:     004abf7a(j), 004ad070(*)  
    //                              scr_sed.cpp:2794 (10)
    //         004ac4bc     MOV        AL,byte ptr [ESI + 0x4c1]
    //         004ac4c2     TEST       AL,AL
    //         004ac4c4     JZ         LAB_004ac4cd
    //                              scr_sed.cpp:2795 (7)
    //         004ac4c6     MOV        byte ptr [ESI + 0x4c0],0x1
    //                               LAB_004ac4cd                                                 XREF[1]:     004ac4c4(j)  
    //                              scr_sed.cpp:2796 (9)
    //         004ac4cd     CMP        EBX,0x1
    //         004ac4d0     JNZ        switchD_004abf7a::default
    //                              scr_sed.cpp:2798 (2)
    //         004ac4d6     XOR        EAX,EAX
    //                              scr_sed.cpp:3233 (21)
    //         004ac4d8     LEA        this,[ESI + 0x508]
    //                               LAB_004ac4de                                                 XREF[1]:     004ac4e9(j)  
    //         004ac4de     CMP        EBP,dword ptr [this->_padding_]
    //         004ac4e0     JZ         LAB_004ac4ed
    //         004ac4e2     INC        EAX
    //         004ac4e3     ADD        this,0x4
    //         004ac4e6     CMP        EAX,0x3
    //         004ac4e9     JL         LAB_004ac4de
    //         004ac4eb     JMP        LAB_004ac4fd
    //                               LAB_004ac4ed                                                 XREF[1]:     004ac4e0(j)  
    //                              scr_sed.cpp:2801 (11)
    //         004ac4ed     INC        EAX
    //         004ac4ee     PUSH       0x1
    //         004ac4f0     PUSH       EAX
    //         004ac4f1     MOV        this,ESI
    //         004ac4f3     CALL       TRIBE_Screen_Sed::set_map_type                   void set_map_type(TRIBE_Screen_Sed * this, Ma
    //                              scr_sed.cpp:2802 (5)
    //         004ac4f8     JMP        LAB_004abe5a
    //                               LAB_004ac4fd                                                 XREF[1]:     004ac4eb(j)  
    //                              scr_sed.cpp:2805 (12)
    //         004ac4fd     CMP        EBP,dword ptr [ESI + 0x54c]
    //         004ac503     JNZ        switchD_004abf7a::default
    //                              scr_sed.cpp:2807 (13)
    //         004ac509     MOV        this,dword ptr [ESI + 0x550]
    //         004ac50f     PUSH       0x1
    //         004ac511     MOV        EDX,dword ptr [this->_padding_]
    //         004ac513     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:2808 (9)
    //         004ac516     MOV        EAX,dword ptr [ESI]
    //         004ac518     PUSH       0x2
    //         004ac51a     MOV        this,ESI
    //         004ac51c     CALL       dword ptr [EAX + 0x20]
    //                              scr_sed.cpp:2809 (20)
    //         004ac51f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ac525     PUSH       0x0
    //         004ac527     PUSH       0x0
    //         004ac529     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004ac52c     PUSH       EDX
    //         004ac52d     CALL       dword ptr [->USER32.DLL::InvalidateRect]         = 0048af16
    //                              scr_sed.cpp:2810 (11)
    //         004ac533     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ac539     CALL       RGE_Base_Game::draw_window                       void draw_window(RGE_Base_Game * this)
    //                              scr_sed.cpp:2812 (11)
    //         004ac53e     MOV        this,dword ptr [ESI + 0x530]
    //         004ac544     CALL       TDropDownPanel::currentLineNumber                int currentLineNumber(TDropDownPanel * this)
    //                              scr_sed.cpp:2813 (13)
    //         004ac549     MOV        this,dword ptr [ESI + 0x538]
    //         004ac54f     MOV        EDI,EAX
    //         004ac551     CALL       TDropDownPanel::currentLineNumber                int currentLineNumber(TDropDownPanel * this)
    //                              scr_sed.cpp:2816 (16)
    //         004ac556     CMP        EDI,0x5
    //         004ac559     MOV        dword ptr [ESP + 0x4c],EAX
    //         004ac55d     JA         LAB_004ac590
    //                               switchD_004ac55f::switchD
    //         004ac55f     JMP        dword ptr [EDI*0x4 + switchD_004ac55f::switchd   = 004ac566
    //                               switchD_004ac55f::caseD_0                                    XREF[2]:     004ac55f(j), 004ad0a8(*)  
    //                              scr_sed.cpp:2819 (5)
    //         004ac566     MOV        EDI,0x48
    //                              scr_sed.cpp:2820 (2)
    //         004ac56b     JMP        switchD_004ac55f::default
    //                               switchD_004ac55f::caseD_1                                    XREF[2]:     004ac55f(j), 004ad0ac(*)  
    //                              scr_sed.cpp:2822 (5)
    //         004ac56d     MOV        EDI,0x60
    //                              scr_sed.cpp:2823 (2)
    //         004ac572     JMP        switchD_004ac55f::default
    //                              language.dll match for 0x78: "10"
    //                               switchD_004ac55f::caseD_2                                    XREF[2]:     004ac55f(j), 004ad0b0(*)  
    //                              scr_sed.cpp:2825 (5)
    //         004ac574     MOV        EDI,0x78
    //                              scr_sed.cpp:2826 (2)
    //         004ac579     JMP        switchD_004ac55f::default
    //                               switchD_004ac55f::caseD_3                                    XREF[2]:     004ac55f(j), 004ad0b4(*)  
    //                              scr_sed.cpp:2828 (5)
    //         004ac57b     MOV        EDI,0x90
    //                              scr_sed.cpp:2829 (2)
    //         004ac580     JMP        switchD_004ac55f::default
    //                               switchD_004ac55f::caseD_4                                    XREF[2]:     004ac55f(j), 004ad0b8(*)  
    //                              scr_sed.cpp:2831 (5)
    //         004ac582     MOV        EDI,0xc8
    //                              scr_sed.cpp:2832 (2)
    //         004ac587     JMP        switchD_004ac55f::default
    //                               switchD_004ac55f::caseD_5                                    XREF[2]:     004ac55f(j), 004ad0bc(*)  
    //                              scr_sed.cpp:2834 (11)
    //         004ac589     MOV        EDI,0xfa
    //         004ac58e     JMP        switchD_004ac55f::default
    //                               LAB_004ac590                                                 XREF[1]:     004ac55d(j)  
    //         004ac590     MOV        EDI,dword ptr [ESP + 0x4c]
    //                               switchD_004ac55f::default                                    XREF[6]:     004ac56b(j), 004ac572(j), 
    //                                                                                                         004ac579(j), 004ac580(j), 
    //                                                                                                         004ac587(j), 004ac58e(j)  
    //                              scr_sed.cpp:2838 (13)
    //         004ac594     MOV        this,dword ptr [ESI + 0x5b8]
    //         004ac59a     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this)
    //         004ac59f     MOV        EBX,EAX
    //                              scr_sed.cpp:2840 (16)
    //         004ac5a1     MOV        EAX,dword ptr [ESI + 0x4a8]
    //         004ac5a7     INC        EBX
    //         004ac5a8     CMP        EAX,0x1
    //         004ac5ab     JNZ        LAB_004ac6da
    //                              scr_sed.cpp:2842 (27)
    //         004ac5b1     MOV        this,dword ptr [ESI + 0x528]
    //         004ac5b7     CALL       TDropDownPanel::currentLineNumber                int currentLineNumber(TDropDownPanel * this)
    //         004ac5bc     CMP        EAX,0x8
    //         004ac5bf     JA         switchD_004ac5c5::default
    //                               switchD_004ac5c5::switchD
    //         004ac5c5     JMP        dword ptr [EAX*0x4 + switchD_004ac5c5::switchd   = 004ac5cc
    //                               switchD_004ac5c5::caseD_0                                    XREF[2]:     004ac5c5(j), 004ad0c0(*)  
    //                              scr_sed.cpp:2845 (25)
    //         004ac5cc     MOV        EAX,dword ptr [ESI + 0x928]
    //         004ac5d2     PUSH       EDI
    //         004ac5d3     PUSH       EDI
    //         004ac5d4     PUSH       0x0
    //         004ac5d6     MOV        this,dword ptr [EAX + 0x40]
    //         004ac5d9     PUSH       EAX
    //         004ac5da     MOV        EDX,dword ptr [this->_padding_]
    //         004ac5dc     MOV        this,dword ptr [EAX + 0x28]
    //         004ac5df     PUSH       EDX
    //         004ac5e0     CALL       RGE_Map::clear_map                               void clear_map(RGE_Map * this, RGE_Player * p
    //                              scr_sed.cpp:2846 (5)
    //         004ac5e5     JMP        switchD_004ac5c5::default
    //                               switchD_004ac5c5::caseD_1                                    XREF[2]:     004ac5c5(j), 004ad0c4(*)  
    //                              scr_sed.cpp:2848 (25)
    //         004ac5ea     MOV        EAX,dword ptr [ESI + 0x928]
    //         004ac5f0     PUSH       EDI
    //         004ac5f1     PUSH       EDI
    //         004ac5f2     PUSH       0x6
    //         004ac5f4     MOV        this,dword ptr [EAX + 0x40]
    //         004ac5f7     PUSH       EAX
    //         004ac5f8     MOV        EDX,dword ptr [this->_padding_]
    //         004ac5fa     MOV        this,dword ptr [EAX + 0x28]
    //         004ac5fd     PUSH       EDX
    //         004ac5fe     CALL       RGE_Map::clear_map                               void clear_map(RGE_Map * this, RGE_Player * p
    //                              scr_sed.cpp:2849 (5)
    //         004ac603     JMP        switchD_004ac5c5::default
    //                               switchD_004ac5c5::caseD_2                                    XREF[2]:     004ac5c5(j), 004ad0c8(*)  
    //                              scr_sed.cpp:2851 (25)
    //         004ac608     MOV        EAX,dword ptr [ESI + 0x928]
    //         004ac60e     PUSH       EDI
    //         004ac60f     PUSH       EDI
    //         004ac610     PUSH       0xa
    //         004ac612     MOV        this,dword ptr [EAX + 0x40]
    //         004ac615     PUSH       EAX
    //         004ac616     MOV        EDX,dword ptr [this->_padding_]
    //         004ac618     MOV        this,dword ptr [EAX + 0x28]
    //         004ac61b     PUSH       EDX
    //         004ac61c     CALL       RGE_Map::clear_map                               void clear_map(RGE_Map * this, RGE_Player * p
    //                              scr_sed.cpp:2852 (5)
    //         004ac621     JMP        switchD_004ac5c5::default
    //                               switchD_004ac5c5::caseD_3                                    XREF[2]:     004ac5c5(j), 004ad0cc(*)  
    //                              scr_sed.cpp:2854 (25)
    //         004ac626     MOV        EAX,dword ptr [ESI + 0x928]
    //         004ac62c     PUSH       EDI
    //         004ac62d     PUSH       EDI
    //         004ac62e     PUSH       0x1
    //         004ac630     MOV        this,dword ptr [EAX + 0x40]
    //         004ac633     PUSH       EAX
    //         004ac634     MOV        EDX,dword ptr [this->_padding_]
    //         004ac636     MOV        this,dword ptr [EAX + 0x28]
    //         004ac639     PUSH       EDX
    //         004ac63a     CALL       RGE_Map::clear_map                               void clear_map(RGE_Map * this, RGE_Player * p
    //                              scr_sed.cpp:2855 (5)
    //         004ac63f     JMP        switchD_004ac5c5::default
    //                               switchD_004ac5c5::caseD_4                                    XREF[2]:     004ac5c5(j), 004ad0d0(*)  
    //                              scr_sed.cpp:2857 (25)
    //         004ac644     MOV        EAX,dword ptr [ESI + 0x928]
    //         004ac64a     PUSH       EDI
    //         004ac64b     PUSH       EDI
    //         004ac64c     PUSH       0xd
    //         004ac64e     MOV        this,dword ptr [EAX + 0x40]
    //         004ac651     PUSH       EAX
    //         004ac652     MOV        EDX,dword ptr [this->_padding_]
    //         004ac654     MOV        this,dword ptr [EAX + 0x28]
    //         004ac657     PUSH       EDX
    //         004ac658     CALL       RGE_Map::clear_map                               void clear_map(RGE_Map * this, RGE_Player * p
    //                              scr_sed.cpp:2858 (5)
    //         004ac65d     JMP        switchD_004ac5c5::default
    //                               switchD_004ac5c5::caseD_5                                    XREF[2]:     004ac5c5(j), 004ad0d4(*)  
    //                              scr_sed.cpp:2860 (25)
    //         004ac662     MOV        EAX,dword ptr [ESI + 0x928]
    //         004ac668     PUSH       EDI
    //         004ac669     PUSH       EDI
    //         004ac66a     PUSH       0x14
    //         004ac66c     MOV        this,dword ptr [EAX + 0x40]
    //         004ac66f     PUSH       EAX
    //         004ac670     MOV        EDX,dword ptr [this->_padding_]
    //         004ac672     MOV        this,dword ptr [EAX + 0x28]
    //         004ac675     PUSH       EDX
    //         004ac676     CALL       RGE_Map::clear_map                               void clear_map(RGE_Map * this, RGE_Player * p
    //                              scr_sed.cpp:2861 (5)
    //         004ac67b     JMP        switchD_004ac5c5::default
    //                               switchD_004ac5c5::caseD_6                                    XREF[2]:     004ac5c5(j), 004ad0d8(*)  
    //                              scr_sed.cpp:2863 (25)
    //         004ac680     MOV        EAX,dword ptr [ESI + 0x928]
    //         004ac686     PUSH       EDI
    //         004ac687     PUSH       EDI
    //         004ac688     PUSH       0x4
    //         004ac68a     MOV        this,dword ptr [EAX + 0x40]
    //         004ac68d     PUSH       EAX
    //         004ac68e     MOV        EDX,dword ptr [this->_padding_]
    //         004ac690     MOV        this,dword ptr [EAX + 0x28]
    //         004ac693     PUSH       EDX
    //         004ac694     CALL       RGE_Map::clear_map                               void clear_map(RGE_Map * this, RGE_Player * p
    //                              scr_sed.cpp:2864 (5)
    //         004ac699     JMP        switchD_004ac5c5::default
    //                               switchD_004ac5c5::caseD_7                                    XREF[2]:     004ac5c5(j), 004ad0dc(*)  
    //                              scr_sed.cpp:2866 (25)
    //         004ac69e     MOV        EAX,dword ptr [ESI + 0x928]
    //         004ac6a4     PUSH       EDI
    //         004ac6a5     PUSH       EDI
    //         004ac6a6     PUSH       0x13
    //         004ac6a8     MOV        this,dword ptr [EAX + 0x40]
    //         004ac6ab     PUSH       EAX
    //         004ac6ac     MOV        EDX,dword ptr [this->_padding_]
    //         004ac6ae     MOV        this,dword ptr [EAX + 0x28]
    //         004ac6b1     PUSH       EDX
    //         004ac6b2     CALL       RGE_Map::clear_map                               void clear_map(RGE_Map * this, RGE_Player * p
    //                              scr_sed.cpp:2867 (5)
    //         004ac6b7     JMP        switchD_004ac5c5::default
    //                               switchD_004ac5c5::caseD_8                                    XREF[2]:     004ac5c5(j), 004ad0e0(*)  
    //                              scr_sed.cpp:2869 (25)
    //         004ac6bc     MOV        EAX,dword ptr [ESI + 0x928]
    //         004ac6c2     PUSH       EDI
    //         004ac6c3     PUSH       EDI
    //         004ac6c4     PUSH       0x16
    //         004ac6c6     MOV        this,dword ptr [EAX + 0x40]
    //         004ac6c9     PUSH       EAX
    //         004ac6ca     MOV        EDX,dword ptr [this->_padding_]
    //         004ac6cc     MOV        this,dword ptr [EAX + 0x28]
    //         004ac6cf     PUSH       EDX
    //         004ac6d0     CALL       RGE_Map::clear_map                               void clear_map(RGE_Map * this, RGE_Player * p
    //                              scr_sed.cpp:2873 (5)
    //         004ac6d5     JMP        switchD_004ac5c5::default
    //                               LAB_004ac6da                                                 XREF[1]:     004ac5ab(j)  
    //                              scr_sed.cpp:2875 (6)
    //         004ac6da     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //                              scr_sed.cpp:2877 (12)
    //         004ac6e0     CMP        EAX,0x3
    //         004ac6e3     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004ac6e6     MOV        dword ptr [ESP + 0x48],EDX
    //         004ac6ea     JNZ        LAB_004ac70b
    //                              scr_sed.cpp:2879 (11)
    //         004ac6ec     MOV        this,dword ptr [ESI + 0x540]
    //         004ac6f2     CALL       TEditPanel::currentLine                          char * currentLine(TEditPanel * this)
    //                              scr_sed.cpp:2880 (6)
    //         004ac6f7     PUSH       EAX
    //         004ac6f8     CALL       atoi                                             undefined atoi()
    //                              scr_sed.cpp:2882 (12)
    //         004ac6fd     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ac703     ADD        ESP,0x4
    //         004ac706     MOV        dword ptr [ECX + this->_padding_],EAX
    //                              scr_sed.cpp:2884 (2)
    //         004ac709     JMP        LAB_004ac712
    //                               LAB_004ac70b                                                 XREF[1]:     004ac6ea(j)  
    //                              scr_sed.cpp:2888 (7)
    //         004ac70b     MOV        dword ptr [ECX + this->_padding_],0xffffffff
    //                               LAB_004ac712                                                 XREF[1]:     004ac709(j)  
    //                              scr_sed.cpp:2893 (2)
    //         004ac712     XOR        EBP,EBP
    //                               LAB_004ac714                                                 XREF[1]:     004ac72b(j)  
    //                              scr_sed.cpp:2894 (25)
    //         004ac714     MOV        EAX,dword ptr [ESI + 0x928]
    //         004ac71a     MOV        this,dword ptr [EAX + 0x40]
    //         004ac71d     MOV        this,dword ptr [this->_padding_ + EBP*0x1]
    //         004ac720     CALL       RGE_Player::reset_selected                       void reset_selected(RGE_Player * this)
    //         004ac725     ADD        EBP,0x4
    //         004ac728     CMP        EBP,0x24
    //         004ac72b     JL         LAB_004ac714
    //                              scr_sed.cpp:2896 (23)
    //         004ac72d     MOV        EAX,dword ptr [ESI + 0x928]
    //         004ac733     PUSH       EBX
    //         004ac734     MOV        EBX,dword ptr [ESP + 0x50]
    //         004ac738     MOV        this,dword ptr [EAX + 0x28]
    //         004ac73b     PUSH       EBX
    //         004ac73c     PUSH       EDI
    //         004ac73d     PUSH       EDI
    //         004ac73e     MOV        EDX,dword ptr [this->_padding_]
    //         004ac740     PUSH       EAX
    //         004ac741     CALL       dword ptr [EDX + 0x28]
    //                              scr_sed.cpp:2898 (9)
    //         004ac744     MOV        EAX,[rge_base_game]                              = 00000000
    //         004ac749     MOV        this,dword ptr [ESP + 0x48]
    //                              scr_sed.cpp:2901 (24)
    //         004ac74d     LEA        EDX,[ESP + 0x20]
    //         004ac751     PUSH       0xa
    //         004ac753     MOV        dword ptr [EAX + 0x2c],this
    //         004ac756     MOV        EAX,[rge_base_game]                              = 00000000
    //         004ac75b     PUSH       EDX
    //         004ac75c     MOV        this,dword ptr [EAX + 0x34]
    //         004ac75f     PUSH       this
    //         004ac760     CALL       itoa                                             undefined itoa()
    //                              scr_sed.cpp:2902 (22)
    //         004ac765     MOV        this,dword ptr [ESI + 0x548]
    //         004ac76b     ADD        ESP,0xc
    //         004ac76e     LEA        EAX,[ESP + 0x20]
    //         004ac772     MOV        EDX,dword ptr [this->_padding_]
    //         004ac774     PUSH       EAX
    //         004ac775     CALL       dword ptr [EDX + 0xe8]
    //                              scr_sed.cpp:2904 (18)
    //         004ac77b     PUSH       0xb58
    //         004ac780     PUSH       s_C:\msdev\work\age1_x1\scr_sed.cp               = "C:\\msdev\\work\\age1_x1\\scr_sed.cpp"
    //         004ac785     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         004ac78a     ADD        ESP,0x8
    //                               switchD_004ac5c5::default                                    XREF[10]:    004ac5bf(j), 004ac5e5(j), 
    //                                                                                                         004ac603(j), 004ac621(j), 
    //                                                                                                         004ac63f(j), 004ac65d(j), 
    //                                                                                                         004ac67b(j), 004ac699(j), 
    //                                                                                                         004ac6b7(j), 004ac6d5(j)  
    //                              scr_sed.cpp:2910 (73)
    //         004ac78d     MOV        EAX,EDI
    //         004ac78f     CDQ
    //         004ac790     SUB        EAX,EDX
    //         004ac792     MOV        EBP,EAX
    //         004ac794     SAR        EBP,0x1
    //         004ac796     MOV        dword ptr [ESP + 0x4c],EBP
    //         004ac79a     XOR        EDI,EDI
    //         004ac79c     FILD       dword ptr [ESP + 0x4c]
    //         004ac7a0     FSTP       float ptr [ESP + 0x4c]
    //         004ac7a4     MOV        EBX,dword ptr [ESP + 0x4c]
    //                               LAB_004ac7a8                                                 XREF[1]:     004ac7d4(j)  
    //         004ac7a8     MOV        this,dword ptr [ESI + 0x928]
    //         004ac7ae     PUSH       EBP
    //         004ac7af     PUSH       EBP
    //         004ac7b0     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004ac7b3     MOV        this,dword ptr [EDX + EDI*0x1]
    //         004ac7b6     CALL       RGE_Player::set_map_loc                          void set_map_loc(RGE_Player * this, short par
    //         004ac7bb     MOV        EAX,dword ptr [ESI + 0x928]
    //         004ac7c1     PUSH       EBX
    //         004ac7c2     PUSH       EBX
    //         004ac7c3     MOV        this,dword ptr [EAX + 0x40]
    //         004ac7c6     MOV        this,dword ptr [this->_padding_ + EDI*0x1]
    //         004ac7c9     CALL       RGE_Player::set_view_loc                         void set_view_loc(RGE_Player * this, float pa
    //         004ac7ce     ADD        EDI,0x4
    //         004ac7d1     CMP        EDI,0x20
    //         004ac7d4     JL         LAB_004ac7a8
    //                              scr_sed.cpp:3233 (2)
    //         004ac7d6     XOR        EDI,EDI
    //                               LAB_004ac7d8                                                 XREF[1]:     004ac803(j)  
    //                              scr_sed.cpp:2915 (20)
    //         004ac7d8     MOV        EDX,dword ptr [ESI + 0x928]
    //         004ac7de     MOV        EAX,dword ptr [EDX + 0x40]
    //         004ac7e1     MOV        this,dword ptr [EAX + EDI*0x1]
    //         004ac7e4     ADD        this,0x58
    //         004ac7e7     CALL       RGE_Tile_List::del_list                          void del_list(RGE_Tile_List * this)
    //                              scr_sed.cpp:2916 (25)
    //         004ac7ec     MOV        this,dword ptr [ESI + 0x928]
    //         004ac7f2     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004ac7f5     MOV        this,dword ptr [EDX + EDI*0x1]
    //         004ac7f8     CALL       RGE_Player::set_map_visible                      void set_map_visible(RGE_Player * this)
    //         004ac7fd     ADD        EDI,0x4
    //         004ac800     CMP        EDI,0x20
    //         004ac803     JL         LAB_004ac7d8
    //                              scr_sed.cpp:2919 (7)
    //         004ac805     MOV        this,ESI
    //         004ac807     CALL       TRIBE_Screen_Sed::set_panel_info                 void set_panel_info(TRIBE_Screen_Sed * this)
    //                              scr_sed.cpp:2927 (15)
    //         004ac80c     MOV        ESI,dword ptr [ESI + 0x550]
    //         004ac812     PUSH       0x0
    //         004ac814     MOV        this,ESI
    //         004ac816     MOV        EAX,dword ptr [ESI]
    //         004ac818     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:2930 (5)
    //         004ac81b     JMP        LAB_004abe5a
    //                               switchD_004abf7a::caseD_2                                    XREF[2]:     004abf7a(j), 004ad074(*)  
    //                              scr_sed.cpp:2938 (10)
    //         004ac820     MOV        AL,byte ptr [ESI + 0x4c1]
    //         004ac826     TEST       AL,AL
    //         004ac828     JZ         LAB_004ac831
    //                              scr_sed.cpp:2939 (7)
    //         004ac82a     MOV        byte ptr [ESI + 0x4c0],0x1
    //                               LAB_004ac831                                                 XREF[1]:     004ac828(j)  
    //                              scr_sed.cpp:2940 (14)
    //         004ac831     CMP        EBX,0x2
    //         004ac834     JZ         LAB_004ac83f
    //         004ac836     CMP        EBX,0x1
    //         004ac839     JNZ        switchD_004abf7a::default
    //                               LAB_004ac83f                                                 XREF[1]:     004ac834(j)  
    //                              scr_sed.cpp:2942 (10)
    //         004ac83f     MOV        this,dword ptr [ESI + 0x5a0]
    //         004ac845     CMP        EBP,this
    //         004ac847     JNZ        LAB_004ac86a
    //                              scr_sed.cpp:2944 (13)
    //         004ac849     CALL       TTextPanel::currentLineNumber                    int currentLineNumber(TTextPanel * this)
    //         004ac84e     PUSH       EAX
    //         004ac84f     MOV        this,ESI
    //         004ac851     CALL       TRIBE_Screen_Sed::set_terrain                    void set_terrain(TRIBE_Screen_Sed * this, sho
    //                              scr_sed.cpp:2945 (15)
    //         004ac856     MOV        ESI,dword ptr [ESI + 0x558]
    //         004ac85c     PUSH       0x1
    //         004ac85e     MOV        this,ESI
    //         004ac860     MOV        EDX,dword ptr [ESI]
    //         004ac862     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:2946 (5)
    //         004ac865     JMP        LAB_004abe5a
    //                               LAB_004ac86a                                                 XREF[1]:     004ac847(j)  
    //                              scr_sed.cpp:2949 (10)
    //         004ac86a     MOV        this,dword ptr [ESI + 0x5a8]
    //         004ac870     CMP        EBP,this
    //         004ac872     JNZ        LAB_004ac886
    //                              scr_sed.cpp:2951 (13)
    //         004ac874     CALL       TTextPanel::currentLineNumber                    int currentLineNumber(TTextPanel * this)
    //         004ac879     PUSH       EAX
    //         004ac87a     MOV        this,ESI
    //         004ac87c     CALL       TRIBE_Screen_Sed::set_elevation                  void set_elevation(TRIBE_Screen_Sed * this, s
    //                              scr_sed.cpp:2952 (5)
    //         004ac881     JMP        LAB_004abe5a
    //                               LAB_004ac886                                                 XREF[1]:     004ac872(j)  
    //                              scr_sed.cpp:2956 (9)
    //         004ac886     CMP        EBX,0x1
    //         004ac889     JNZ        switchD_004abf7a::default
    //                              scr_sed.cpp:2958 (10)
    //         004ac88f     MOV        AL,byte ptr [ESI + 0x4c1]
    //         004ac895     TEST       AL,AL
    //         004ac897     JZ         LAB_004ac89f
    //                              scr_sed.cpp:2959 (6)
    //         004ac899     MOV        byte ptr [ESI + 0x4c0],BL
    //                               LAB_004ac89f                                                 XREF[1]:     004ac897(j)  
    //                              scr_sed.cpp:2961 (8)
    //         004ac89f     XOR        EAX,EAX
    //         004ac8a1     LEA        this,[ESI + 0x558]
    //                               LAB_004ac8a7                                                 XREF[1]:     004ac8b2(j)  
    //                              scr_sed.cpp:2962 (15)
    //         004ac8a7     CMP        EBP,dword ptr [this->_padding_]
    //         004ac8a9     JZ         LAB_004ac8b6
    //         004ac8ab     INC        EAX
    //         004ac8ac     ADD        this,0x4
    //         004ac8af     CMP        EAX,0x5
    //         004ac8b2     JL         LAB_004ac8a7
    //         004ac8b4     JMP        LAB_004ac8c4
    //                               LAB_004ac8b6                                                 XREF[1]:     004ac8a9(j)  
    //                              scr_sed.cpp:2964 (9)
    //         004ac8b6     INC        EAX
    //         004ac8b7     MOV        this,ESI
    //         004ac8b9     PUSH       EAX
    //         004ac8ba     CALL       TRIBE_Screen_Sed::set_brush_size                 void set_brush_size(TRIBE_Screen_Sed * this, 
    //                              scr_sed.cpp:2965 (5)
    //         004ac8bf     JMP        LAB_004abe5a
    //                               LAB_004ac8c4                                                 XREF[1]:     004ac8b4(j)  
    //                              scr_sed.cpp:2968 (8)
    //         004ac8c4     XOR        EAX,EAX
    //         004ac8c6     LEA        this,[ESI + 0x584]
    //                               LAB_004ac8cc                                                 XREF[1]:     004ac8d7(j)  
    //                              scr_sed.cpp:2969 (18)
    //         004ac8cc     CMP        EBP,dword ptr [this->_padding_]
    //         004ac8ce     JZ         LAB_004ac8de
    //         004ac8d0     INC        EAX
    //         004ac8d1     ADD        this,0x4
    //         004ac8d4     CMP        EAX,0x3
    //         004ac8d7     JL         LAB_004ac8cc
    //         004ac8d9     JMP        switchD_004abf7a::default
    //                               LAB_004ac8de                                                 XREF[1]:     004ac8ce(j)  
    //                              scr_sed.cpp:2971 (11)
    //         004ac8de     INC        EAX
    //         004ac8df     PUSH       0x1
    //         004ac8e1     PUSH       EAX
    //         004ac8e2     MOV        this,ESI
    //         004ac8e4     CALL       TRIBE_Screen_Sed::set_paint_type                 void set_paint_type(TRIBE_Screen_Sed * this, 
    //                              scr_sed.cpp:2972 (5)
    //         004ac8e9     JMP        LAB_004abe5a
    //                               switchD_004abf7a::caseD_3                                    XREF[2]:     004abf7a(j), 004ad078(*)  
    //                              scr_sed.cpp:2979 (10)
    //         004ac8ee     MOV        AL,byte ptr [ESI + 0x4c1]
    //         004ac8f4     TEST       AL,AL
    //         004ac8f6     JZ         LAB_004ac8ff
    //                              scr_sed.cpp:2980 (7)
    //         004ac8f8     MOV        byte ptr [ESI + 0x4c0],0x1
    //                               LAB_004ac8ff                                                 XREF[1]:     004ac8f6(j)  
    //                              scr_sed.cpp:2981 (8)
    //         004ac8ff     TEST       EBX,EBX
    //         004ac901     JNZ        LAB_004ac9f3
    //                              scr_sed.cpp:2983 (2)
    //         004ac907     XOR        EAX,EAX
    //                              scr_sed.cpp:3233 (21)
    //         004ac909     LEA        this,[ESI + 0x5d8]
    //                               LAB_004ac90f                                                 XREF[1]:     004ac91a(j)  
    //         004ac90f     CMP        EBP,dword ptr [this->_padding_]
    //         004ac911     JZ         LAB_004ac91e
    //         004ac913     INC        EAX
    //         004ac914     ADD        this,0x4
    //         004ac917     CMP        EAX,0x5
    //         004ac91a     JL         LAB_004ac90f
    //         004ac91c     JMP        LAB_004ac92b
    //                               LAB_004ac91e                                                 XREF[1]:     004ac911(j)  
    //                              scr_sed.cpp:2986 (13)
    //         004ac91e     MOV        this,dword ptr [ESI + 0x4d4]
    //         004ac924     PUSH       0x0
    //         004ac926     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                               LAB_004ac92b                                                 XREF[1]:     004ac91c(j)  
    //                              scr_sed.cpp:2991 (8)
    //         004ac92b     TEST       EBX,EBX
    //         004ac92d     JNZ        LAB_004ac9f3
    //                              scr_sed.cpp:2993 (10)
    //         004ac933     MOV        AL,byte ptr [ESI + 0x4c1]
    //         004ac939     TEST       AL,AL
    //         004ac93b     JZ         LAB_004ac944
    //                              scr_sed.cpp:2994 (7)
    //         004ac93d     MOV        byte ptr [ESI + 0x4c0],0x1
    //                               LAB_004ac944                                                 XREF[1]:     004ac93b(j)  
    //                              scr_sed.cpp:2996 (10)
    //         004ac944     MOV        this,dword ptr [ESI + 0x5bc]
    //         004ac94a     CMP        EBP,this
    //         004ac94c     JNZ        LAB_004ac97c
    //                              scr_sed.cpp:2998 (10)
    //         004ac94e     MOV        AL,byte ptr [ESI + 0x4c1]
    //         004ac954     TEST       AL,AL
    //         004ac956     JZ         LAB_004ac95f
    //                              scr_sed.cpp:2999 (7)
    //         004ac958     MOV        byte ptr [ESI + 0x4c0],0x1
    //                               LAB_004ac95f                                                 XREF[1]:     004ac956(j)  
    //                              scr_sed.cpp:3001 (5)
    //         004ac95f     CALL       TDropDownPanel::currentLineNumber                int currentLineNumber(TDropDownPanel * this)
    //                              scr_sed.cpp:3003 (24)
    //         004ac964     MOV        this,dword ptr [ESI + 0x928]
    //         004ac96a     PUSH       EAX
    //         004ac96b     MOVSX      EAX,word ptr [ESI + 0x4b8]
    //         004ac972     MOV        this,dword ptr [ECX + this->_padding_]
    //         004ac975     DEC        EAX
    //         004ac976     PUSH       EAX
    //         004ac977     CALL       T_Scenario::SetPlayerAge                         void SetPlayerAge(T_Scenario * this, int para
    //                               LAB_004ac97c                                                 XREF[1]:     004ac94c(j)  
    //                              scr_sed.cpp:3006 (10)
    //         004ac97c     MOV        this,dword ptr [ESI + 0x5b4]
    //         004ac982     CMP        EBP,this
    //         004ac984     JNZ        LAB_004ac9be
    //                              scr_sed.cpp:3008 (18)
    //         004ac986     PUSH       0x1
    //         004ac988     PUSH       0x1
    //         004ac98a     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this)
    //         004ac98f     INC        EAX
    //         004ac990     MOV        this,ESI
    //         004ac992     PUSH       EAX
    //         004ac993     CALL       TRIBE_Screen_Sed::set_player                     void set_player(TRIBE_Screen_Sed * this, shor
    //                              scr_sed.cpp:3009 (26)
    //         004ac998     MOV        this,dword ptr [ESI + 0x5b4]
    //         004ac99e     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this)
    //         004ac9a3     MOV        EDX,dword ptr [ESI + 0x928]
    //         004ac9a9     PUSH       EAX
    //         004ac9aa     MOV        this,dword ptr [EDX + 0x5c]
    //         004ac9ad     CALL       T_Scenario::GetPlayerAge                         int GetPlayerAge(T_Scenario * this, int param
    //                              scr_sed.cpp:3010 (12)
    //         004ac9b2     MOV        this,dword ptr [ESI + 0x5bc]
    //         004ac9b8     PUSH       EAX
    //         004ac9b9     CALL       TDropDownPanel::setCurrentLineNumber             void setCurrentLineNumber(TDropDownPanel * th
    //                               LAB_004ac9be                                                 XREF[1]:     004ac984(j)  
    //                              scr_sed.cpp:3013 (8)
    //         004ac9be     CMP        EBP,dword ptr [ESI + 0x5b8]
    //         004ac9c4     JNZ        LAB_004ac9f3
    //                              scr_sed.cpp:3015 (19)
    //         004ac9c6     MOV        AX,word ptr [ESI + 0x4b8]
    //         004ac9cd     PUSH       0x0
    //         004ac9cf     PUSH       0x1
    //         004ac9d1     PUSH       EAX
    //         004ac9d2     MOV        this,ESI
    //         004ac9d4     CALL       TRIBE_Screen_Sed::set_player                     void set_player(TRIBE_Screen_Sed * this, shor
    //                              scr_sed.cpp:3016 (7)
    //         004ac9d9     MOV        this,ESI
    //         004ac9db     CALL       TRIBE_Screen_Sed::SavePlayerActiveStatus         void SavePlayerActiveStatus(TRIBE_Screen_Sed 
    //                              scr_sed.cpp:3017 (19)
    //         004ac9e0     MOV        this,word ptr [ESI + 0x4b8]
    //         004ac9e7     PUSH       0x1
    //         004ac9e9     PUSH       0x0
    //         004ac9eb     PUSH       this
    //         004ac9ec     MOV        this,ESI
    //         004ac9ee     CALL       TRIBE_Screen_Sed::set_player                     void set_player(TRIBE_Screen_Sed * this, shor
    //                               LAB_004ac9f3                                                 XREF[3]:     004ac901(j), 004ac92d(j), 
    //                                                                                                         004ac9c4(j)  
    //                              scr_sed.cpp:3040 (9)
    //         004ac9f3     CMP        EBX,0x1
    //         004ac9f6     JNZ        switchD_004abf7a::default
    //                              scr_sed.cpp:3042 (14)
    //         004ac9fc     MOV        this,dword ptr [ESI + 0x5bc]
    //         004aca02     CMP        EBP,this
    //         004aca04     JNZ        switchD_004abf7a::default
    //                              scr_sed.cpp:3044 (5)
    //         004aca0a     CALL       TDropDownPanel::currentLineNumber                int currentLineNumber(TDropDownPanel * this)
    //                              scr_sed.cpp:3046 (24)
    //         004aca0f     MOVSX      EDX,word ptr [ESI + 0x4b8]
    //         004aca16     PUSH       EAX
    //         004aca17     MOV        EAX,dword ptr [ESI + 0x928]
    //         004aca1d     DEC        EDX
    //         004aca1e     MOV        this,dword ptr [EAX + 0x5c]
    //         004aca21     PUSH       EDX
    //         004aca22     CALL       T_Scenario::SetPlayerAge                         void SetPlayerAge(T_Scenario * this, int para
    //                              scr_sed.cpp:3049 (5)
    //         004aca27     JMP        switchD_004abf7a::default
    //                               switchD_004abf7a::caseD_4                                    XREF[2]:     004abf7a(j), 004ad07c(*)  
    //                              scr_sed.cpp:3053 (10)
    //         004aca2c     MOV        AL,byte ptr [ESI + 0x4c1]
    //         004aca32     TEST       AL,AL
    //         004aca34     JZ         LAB_004aca3d
    //                              scr_sed.cpp:3054 (7)
    //         004aca36     MOV        byte ptr [ESI + 0x4c0],0x1
    //                               LAB_004aca3d                                                 XREF[1]:     004aca34(j)  
    //                              scr_sed.cpp:3055 (8)
    //         004aca3d     TEST       EBX,EBX
    //         004aca3f     JNZ        LAB_004acb22
    //                              scr_sed.cpp:3057 (10)
    //         004aca45     MOV        AL,byte ptr [ESI + 0x4c1]
    //         004aca4b     TEST       AL,AL
    //         004aca4d     JZ         LAB_004aca56
    //                              scr_sed.cpp:3058 (7)
    //         004aca4f     MOV        byte ptr [ESI + 0x4c0],0x1
    //                               LAB_004aca56                                                 XREF[1]:     004aca4d(j)  
    //                              scr_sed.cpp:3060 (14)
    //         004aca56     MOV        this,dword ptr [ESI + 0x618]
    //         004aca5c     CMP        EBP,this
    //         004aca5e     JNZ        LAB_004acb22
    //                              scr_sed.cpp:3062 (13)
    //         004aca64     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this)
    //         004aca69     PUSH       EAX
    //         004aca6a     MOV        this,ESI
    //         004aca6c     CALL       TRIBE_Screen_Sed::set_unit_player                void set_unit_player(TRIBE_Screen_Sed * this,
    //                              scr_sed.cpp:3063 (11)
    //         004aca71     MOV        this,dword ptr [ESI + 0x618]
    //         004aca77     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this)
    //                              scr_sed.cpp:3064 (24)
    //         004aca7c     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004aca82     TEST       EAX,EAX
    //         004aca84     MOV        EDX,dword ptr [this->_padding_]
    //         004aca86     JNZ        LAB_004aca99
    //         004aca88     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004aca8e     PUSH       0x3
    //         004aca90     PUSH       EAX
    //         004aca91     CALL       dword ptr [EDX + 0x10]
    //                              scr_sed.cpp:3065 (5)
    //         004aca94     JMP        LAB_004acb22
    //                               LAB_004aca99                                                 XREF[1]:     004aca86(j)  
    //                              scr_sed.cpp:3067 (12)
    //         004aca99     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004aca9f     PUSH       0x4
    //         004acaa1     PUSH       EAX
    //         004acaa2     CALL       dword ptr [EDX + 0x10]
    //                              scr_sed.cpp:3069 (25)
    //         004acaa5     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004acaab     CMP        word ptr [ECX + this->_padding_],-0x1
    //         004acab3     JZ         LAB_004acaf8
    //         004acab5     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004acaba     TEST       EAX,EAX
    //         004acabc     JZ         LAB_004acaf8
    //                              scr_sed.cpp:3071 (56)
    //         004acabe     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004acac4     MOV        DI,word ptr [ECX + this->_padding_]
    //         004acacb     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004acad0     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004acad6     PUSH       EAX
    //         004acad7     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004acadc     MOV        EDX,dword ptr [ESI + 0x928]
    //         004acae2     MOVSX      this,word ptr [EAX + 0x4a]
    //         004acae6     MOV        EAX,dword ptr [EDX + 0x40]
    //         004acae9     MOVSX      EDX,DI
    //         004acaec     MOV        this,dword ptr [EAX + this->_padding_*0x4]
    //         004acaef     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004acaf2     MOV        this,dword ptr [EAX + EDX*0x4]
    //         004acaf5     PUSH       this
    //                              scr_sed.cpp:3072 (2)
    //         004acaf6     JMP        LAB_004acafc
    //                               LAB_004acaf8                                                 XREF[2]:     004acab3(j), 004acabc(j)  
    //                              scr_sed.cpp:3073 (15)
    //         004acaf8     PUSH       0x0
    //         004acafa     PUSH       0x0
    //                               LAB_004acafc                                                 XREF[1]:     004acaf6(j)  
    //         004acafc     MOV        this,dword ptr [ESI + 0x660]
    //         004acb02     CALL       TRIBE_Scenario_Editor_Panel_Object::set_master   void set_master_info(TRIBE_Scenario_Editor_Pa
    //                              scr_sed.cpp:3074 (7)
    //         004acb07     MOV        this,ESI
    //         004acb09     CALL       TRIBE_Screen_Sed::set_paint_object_mode          void set_paint_object_mode(TRIBE_Screen_Sed *
    //                              scr_sed.cpp:3075 (15)
    //         004acb0e     MOV        ESI,dword ptr [ESI + 0x660]
    //         004acb14     PUSH       0x2
    //         004acb16     MOV        this,ESI
    //         004acb18     MOV        EDX,dword ptr [ESI]
    //         004acb1a     CALL       dword ptr [EDX + 0x20]
    //                              scr_sed.cpp:3076 (5)
    //         004acb1d     JMP        LAB_004abe5a
    //                               LAB_004acb22                                                 XREF[3]:     004aca3f(j), 004aca5e(j), 
    //                                                                                                         004aca94(j)  
    //                              scr_sed.cpp:3081 (14)
    //         004acb22     CMP        EBX,0x2
    //         004acb25     JZ         LAB_004acb30
    //         004acb27     CMP        EBX,0x1
    //         004acb2a     JNZ        switchD_004abf7a::default
    //                               LAB_004acb30                                                 XREF[1]:     004acb25(j)  
    //                              scr_sed.cpp:3083 (14)
    //         004acb30     MOV        this,dword ptr [ESI + 0x63c]
    //         004acb36     CMP        EBP,this
    //         004acb38     JNZ        LAB_004acbe9
    //                              scr_sed.cpp:3085 (13)
    //         004acb3e     CALL       TTextPanel::currentLineNumber                    int currentLineNumber(TTextPanel * this)
    //         004acb43     PUSH       EAX
    //         004acb44     MOV        this,ESI
    //         004acb46     CALL       TRIBE_Screen_Sed::set_unit                       void set_unit(TRIBE_Screen_Sed * this, short 
    //                              scr_sed.cpp:3086 (22)
    //         004acb4b     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004acb51     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004acb57     CMP        EAX,0x8
    //         004acb5a     JZ         LAB_004acb72
    //         004acb5c     CMP        EAX,0x15
    //         004acb5f     JZ         LAB_004acb72
    //                              scr_sed.cpp:3089 (17)
    //         004acb61     MOV        this,dword ptr [ESI + 0x61c]
    //         004acb67     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
    //         004acb6c     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //                               LAB_004acb72                                                 XREF[2]:     004acb5a(j), 004acb5f(j)  
    //                              scr_sed.cpp:3092 (19)
    //         004acb72     CMP        word ptr [ECX + this->_padding_],-0x1
    //         004acb7a     JZ         LAB_004acbbf
    //         004acb7c     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004acb81     TEST       EAX,EAX
    //         004acb83     JZ         LAB_004acbbf
    //                              scr_sed.cpp:3094 (56)
    //         004acb85     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004acb8b     MOV        DI,word ptr [ECX + this->_padding_]
    //         004acb92     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004acb97     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004acb9d     PUSH       EAX
    //         004acb9e     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004acba3     MOV        this,dword ptr [ESI + 0x928]
    //         004acba9     MOVSX      EAX,word ptr [EAX + 0x4a]
    //         004acbad     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004acbb0     MOVSX      this,DI
    //         004acbb3     MOV        EAX,dword ptr [EDX + EAX*0x4]
    //         004acbb6     MOV        EDX,dword ptr [EAX + 0x24]
    //         004acbb9     MOV        EAX,dword ptr [EDX + this->_padding_*0x4]
    //         004acbbc     PUSH       EAX
    //                              scr_sed.cpp:3095 (2)
    //         004acbbd     JMP        LAB_004acbc3
    //                               LAB_004acbbf                                                 XREF[2]:     004acb7a(j), 004acb83(j)  
    //                              scr_sed.cpp:3096 (15)
    //         004acbbf     PUSH       0x0
    //         004acbc1     PUSH       0x0
    //                               LAB_004acbc3                                                 XREF[1]:     004acbbd(j)  
    //         004acbc3     MOV        this,dword ptr [ESI + 0x660]
    //         004acbc9     CALL       TRIBE_Scenario_Editor_Panel_Object::set_master   void set_master_info(TRIBE_Scenario_Editor_Pa
    //                              scr_sed.cpp:3097 (7)
    //         004acbce     MOV        this,ESI
    //         004acbd0     CALL       TRIBE_Screen_Sed::set_paint_object_mode          void set_paint_object_mode(TRIBE_Screen_Sed *
    //                              scr_sed.cpp:3098 (15)
    //         004acbd5     MOV        ESI,dword ptr [ESI + 0x660]
    //         004acbdb     PUSH       0x1
    //         004acbdd     MOV        this,ESI
    //         004acbdf     MOV        EDX,dword ptr [ESI]
    //         004acbe1     CALL       dword ptr [EDX + 0x20]
    //                              scr_sed.cpp:3099 (5)
    //         004acbe4     JMP        LAB_004abe5a
    //                               LAB_004acbe9                                                 XREF[1]:     004acb38(j)  
    //                              scr_sed.cpp:3103 (9)
    //         004acbe9     CMP        EBX,0x1
    //         004acbec     JNZ        switchD_004abf7a::default
    //                              scr_sed.cpp:3105 (8)
    //         004acbf2     CMP        EBP,dword ptr [ESI + 0x61c]
    //         004acbf8     JNZ        LAB_004acc06
    //                              scr_sed.cpp:3106 (7)
    //         004acbfa     MOV        this,ESI
    //         004acbfc     CALL       TRIBE_Screen_Sed::set_paint_object_mode          void set_paint_object_mode(TRIBE_Screen_Sed *
    //                              scr_sed.cpp:3107 (13)
    //         004acc01     JMP        switchD_004abf7a::default
    //                               LAB_004acc06                                                 XREF[1]:     004acbf8(j)  
    //         004acc06     CMP        EBP,dword ptr [ESI + 0x620]
    //         004acc0c     JNZ        LAB_004acc34
    //                              scr_sed.cpp:3109 (18)
    //         004acc0e     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004acc14     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004acc19     MOV        this,EAX
    //         004acc1b     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
    //                              scr_sed.cpp:3110 (15)
    //         004acc20     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004acc26     PUSH       0x0
    //         004acc28     PUSH       0xe
    //         004acc2a     MOV        EAX,dword ptr [this->_padding_]
    //         004acc2c     CALL       dword ptr [EAX + 0x10]
    //                              scr_sed.cpp:3112 (13)
    //         004acc2f     JMP        switchD_004abf7a::default
    //                               LAB_004acc34                                                 XREF[1]:     004acc0c(j)  
    //         004acc34     CMP        EBP,dword ptr [ESI + 0x624]
    //         004acc3a     JNZ        LAB_004acc50
    //                              scr_sed.cpp:3113 (15)
    //         004acc3c     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004acc42     PUSH       0x0
    //         004acc44     PUSH       0xf
    //         004acc46     MOV        EDX,dword ptr [this->_padding_]
    //         004acc48     CALL       dword ptr [EDX + 0x10]
    //                              scr_sed.cpp:3114 (17)
    //         004acc4b     JMP        switchD_004abf7a::default
    //                               LAB_004acc50                                                 XREF[1]:     004acc3a(j)  
    //         004acc50     CMP        EBP,dword ptr [ESI + 0x628]
    //         004acc56     JNZ        switchD_004abf7a::default
    //                              scr_sed.cpp:3115 (15)
    //         004acc5c     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004acc62     PUSH       0x0
    //         004acc64     PUSH       0x14
    //         004acc66     MOV        EAX,dword ptr [this->_padding_]
    //         004acc68     CALL       dword ptr [EAX + 0x10]
    //                              scr_sed.cpp:3117 (5)
    //         004acc6b     JMP        switchD_004abf7a::default
    //                               switchD_004abf7a::caseD_7                                    XREF[2]:     004abf7a(j), 004ad088(*)  
    //                              scr_sed.cpp:3121 (10)
    //         004acc70     MOV        AL,byte ptr [ESI + 0x4c1]
    //         004acc76     TEST       AL,AL
    //         004acc78     JZ         LAB_004acc81
    //                              scr_sed.cpp:3122 (7)
    //         004acc7a     MOV        byte ptr [ESI + 0x4c0],0x1
    //                               LAB_004acc81                                                 XREF[1]:     004acc78(j)  
    //                              scr_sed.cpp:3123 (9)
    //         004acc81     CMP        EBX,0x1
    //         004acc84     JNZ        switchD_004abf7a::default
    //                              scr_sed.cpp:3125 (2)
    //         004acc8a     XOR        EDI,EDI
    //                              scr_sed.cpp:3233 (24)
    //         004acc8c     LEA        EAX,[ESI + 0x6e0]
    //                               LAB_004acc92                                                 XREF[1]:     004acc9d(j)  
    //         004acc92     CMP        EBP,dword ptr [EAX]
    //         004acc94     JZ         LAB_004acca4
    //         004acc96     INC        EDI
    //         004acc97     ADD        EAX,0x4
    //         004acc9a     CMP        EDI,0x5
    //         004acc9d     JL         LAB_004acc92
    //         004acc9f     JMP        switchD_004abf7a::default
    //                               LAB_004acca4                                                 XREF[1]:     004acc94(j)  
    //                              scr_sed.cpp:3128 (13)
    //         004acca4     LEA        this,[EDI + 0x1]
    //         004acca7     PUSH       0x1
    //         004acca9     PUSH       this
    //         004accaa     MOV        this,ESI
    //         004accac     CALL       TRIBE_Screen_Sed::set_mp_victory_type            void set_mp_victory_type(TRIBE_Screen_Sed * t
    //                              scr_sed.cpp:3131 (9)
    //         004accb1     CMP        EDI,0x4
    //         004accb4     JZ         LAB_004abe5a
    //                              scr_sed.cpp:3133 (16)
    //         004accba     MOV        EDX,dword ptr [ESI + 0x928]
    //         004accc0     PUSH       0x1
    //         004accc2     MOV        this,dword ptr [EDX + 0x5c]
    //         004accc5     CALL       T_Scenario::Set_Multi_Conquest                   void Set_Multi_Conquest(T_Scenario * this, in
    //                              scr_sed.cpp:3134 (18)
    //         004accca     MOV        ESI,dword ptr [ESI + 0x668]
    //         004accd0     PUSH       0x1
    //         004accd2     MOV        this,ESI
    //         004accd4     MOV        EAX,dword ptr [ESI]
    //         004accd6     CALL       dword ptr [EAX + 0xe0]
    //                              scr_sed.cpp:3137 (5)
    //         004accdc     JMP        LAB_004abe5a
    //                               switchD_004abf7a::caseD_5                                    XREF[2]:     004abf7a(j), 004ad080(*)  
    //                              scr_sed.cpp:3145 (10)
    //         004acce1     MOV        AL,byte ptr [ESI + 0x4c1]
    //         004acce7     TEST       AL,AL
    //         004acce9     JZ         LAB_004accf2
    //                              scr_sed.cpp:3146 (7)
    //         004acceb     MOV        byte ptr [ESI + 0x4c0],0x1
    //                               LAB_004accf2                                                 XREF[1]:     004acce9(j)  
    //                              scr_sed.cpp:3147 (13)
    //         004accf2     TEST       EBX,EBX
    //         004accf4     JZ         LAB_004accff
    //         004accf6     CMP        EBX,0x1
    //         004accf9     JNZ        switchD_004abf7a::default
    //                               LAB_004accff                                                 XREF[1]:     004accf4(j)  
    //                              scr_sed.cpp:3148 (12)
    //         004accff     CMP        EBP,dword ptr [ESI + 0x894]
    //         004acd05     JNZ        LAB_004acde9
    //                              scr_sed.cpp:3150 (24)
    //         004acd0b     MOVSX      EAX,word ptr [ESI + 0x4b8]
    //         004acd12     PUSH       0x1
    //         004acd14     LEA        this,[EAX + EAX*0x2]
    //         004acd17     MOV        this,dword ptr [ESI + this->_padding_*0x4 + 0x
    //         004acd1e     MOV        EDX,dword ptr [this->_padding_]
    //         004acd20     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:3151 (25)
    //         004acd23     MOVSX      EAX,word ptr [ESI + 0x4b8]
    //         004acd2a     ADD        EAX,0xb8
    //         004acd2f     PUSH       0x1
    //         004acd31     LEA        EAX,[EAX + EAX*0x2]
    //         004acd34     MOV        this,dword ptr [ESI + EAX*0x4]
    //         004acd37     MOV        EDX,dword ptr [this->_padding_]
    //         004acd39     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:3152 (24)
    //         004acd3c     MOVSX      EAX,word ptr [ESI + 0x4b8]
    //         004acd43     PUSH       0x1
    //         004acd45     LEA        EAX,[EAX + EAX*0x2]
    //         004acd48     MOV        this,dword ptr [ESI + EAX*0x4 + 0x8a4]
    //         004acd4f     MOV        EDX,dword ptr [this->_padding_]
    //         004acd51     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:3153 (21)
    //         004acd54     MOVSX      EAX,word ptr [ESI + 0x4b8]
    //         004acd5b     PUSH       0x0
    //         004acd5d     MOV        this,dword ptr [ESI + EAX*0x4 + 0x904]
    //         004acd64     MOV        EDX,dword ptr [this->_padding_]
    //         004acd66     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:3155 (12)
    //         004acd69     MOV        this,dword ptr [ESI + 0x894]
    //         004acd6f     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this)
    //         004acd74     INC        EAX
    //                              scr_sed.cpp:3157 (27)
    //         004acd75     PUSH       0x0
    //         004acd77     MOV        word ptr [ESI + 0x4b8],AX
    //         004acd7e     MOVSX      EAX,AX
    //         004acd81     LEA        EAX,[EAX + EAX*0x2]
    //         004acd84     MOV        this,dword ptr [ESI + EAX*0x4 + 0x89c]
    //         004acd8b     MOV        EDX,dword ptr [this->_padding_]
    //         004acd8d     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:3158 (25)
    //         004acd90     MOVSX      EAX,word ptr [ESI + 0x4b8]
    //         004acd97     ADD        EAX,0xb8
    //         004acd9c     PUSH       0x0
    //         004acd9e     LEA        EAX,[EAX + EAX*0x2]
    //         004acda1     MOV        this,dword ptr [ESI + EAX*0x4]
    //         004acda4     MOV        EDX,dword ptr [this->_padding_]
    //         004acda6     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:3159 (24)
    //         004acda9     MOVSX      EAX,word ptr [ESI + 0x4b8]
    //         004acdb0     PUSH       0x0
    //         004acdb2     LEA        EAX,[EAX + EAX*0x2]
    //         004acdb5     MOV        this,dword ptr [ESI + EAX*0x4 + 0x8a4]
    //         004acdbc     MOV        EDX,dword ptr [this->_padding_]
    //         004acdbe     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:3160 (21)
    //         004acdc1     MOVSX      EAX,word ptr [ESI + 0x4b8]
    //         004acdc8     PUSH       0x1
    //         004acdca     MOV        this,dword ptr [ESI + EAX*0x4 + 0x904]
    //         004acdd1     MOV        EDX,dword ptr [this->_padding_]
    //         004acdd3     CALL       dword ptr [EDX + 0x14]
    //                              scr_sed.cpp:3162 (19)
    //         004acdd6     MOV        this,dword ptr [ESI + 0x894]
    //         004acddc     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this)
    //         004acde1     PUSH       EAX
    //         004acde2     MOV        this,ESI
    //         004acde4     CALL       TRIBE_Screen_Sed::load_diplomacy_from_scenario   void load_diplomacy_from_scenario(TRIBE_Scree
    //                               LAB_004acde9                                                 XREF[1]:     004acd05(j)  
    //                              scr_sed.cpp:3165 (5)
    //         004acde9     CMP        EBX,0x1
    //         004acdec     JNZ        switchD_004abf7a::default
    //                              scr_sed.cpp:3168 (16)
    //         004acdee     MOVSX      EAX,word ptr [ESI + 0x4b8]
    //         004acdf5     DEC        EAX
    //         004acdf6     MOV        this,ESI
    //         004acdf8     PUSH       EAX
    //         004acdf9     CALL       TRIBE_Screen_Sed::save_diplomacy_in_scenario     void save_diplomacy_in_scenario(TRIBE_Screen_
    //                              scr_sed.cpp:3169 (5)
    //         004acdfe     JMP        LAB_004abe5a
    //                               switchD_004abf7a::caseD_8                                    XREF[2]:     004abf7a(j), 004ad08c(*)  
    //                              scr_sed.cpp:3175 (10)
    //         004ace03     MOV        AL,byte ptr [ESI + 0x4c1]
    //         004ace09     TEST       AL,AL
    //         004ace0b     JZ         LAB_004ace14
    //                              scr_sed.cpp:3176 (7)
    //         004ace0d     MOV        byte ptr [ESI + 0x4c0],0x1
    //                               LAB_004ace14                                                 XREF[1]:     004ace0b(j)  
    //                              scr_sed.cpp:3177 (5)
    //         004ace14     CMP        EBX,0x1
    //         004ace17     JNZ        switchD_004abf7a::default
    //                              scr_sed.cpp:3179 (7)
    //         004ace19     MOV        this,ESI
    //         004ace1b     CALL       TRIBE_Screen_Sed::SaveDisabledItemsInScenario    void SaveDisabledItemsInScenario(TRIBE_Screen
    //                              scr_sed.cpp:3180 (7)
    //         004ace20     MOV        this,ESI
    //         004ace22     CALL       TRIBE_Screen_Sed::LoadDisabledItemsFromScenario  void LoadDisabledItemsFromScenario(TRIBE_Scre
    //                              scr_sed.cpp:3181 (10)
    //         004ace27     MOV        this,dword ptr [ESI + 0x7c8]
    //         004ace2d     CMP        EBP,this
    //         004ace2f     JNZ        switchD_004abf7a::default
    //                              scr_sed.cpp:3182 (22)
    //         004ace31     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
    //         004ace36     MOV        this,dword ptr [ESI + 0x928]
    //         004ace3c     PUSH       EAX
    //         004ace3d     PUSH       0x2
    //         004ace3f     MOV        this,dword ptr [ECX + this->_padding_]
    //         004ace42     CALL       T_Scenario::SetScenarioOption                    void SetScenarioOption(T_Scenario * this, int
    //                               switchD_004ac009::default                                    XREF[31]:    004abf74(j), 004abf95(j), 
    //                               switchD_004abf7a::default                                                 004ac003(j), 004ac15b(j), 
    //                                                                                                         004ac4b7(j), 004ac4d0(j), 
    //                                                                                                         004ac503(j), 004ac839(j), 
    //                                                                                                         004ac889(j), 004ac8d9(j), 
    //                                                                                                         004ac9f6(j), 004aca04(j), 
    //                                                                                                         004aca27(j), 004acb2a(j), 
    //                                                                                                         004acbec(j), 004acc01(j), 
    //                                                                                                         004acc2f(j), 004acc4b(j), 
    //                                                                                                         004acc56(j), 004acc6b(j), [more]
    //                              scr_sed.cpp:3189 (72)
    //         004ace47     MOV        this,EBP
    //         004ace49     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //         004ace4e     TEST       EAX,EAX
    //         004ace50     JZ         LAB_004acefd
    //         004ace56     MOV        this,EBP
    //         004ace58     MOV        EDI,s_QuitSaveDialog                             = 51h    Q
    //         004ace5d     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //                               LAB_004ace62                                                 XREF[1]:     004ace80(j)  
    //         004ace62     MOV        DL,byte ptr [EAX]
    //         004ace64     MOV        this,DL
    //         004ace66     CMP        DL,byte ptr [EDI]=>s_QuitSaveDialog              = 51h    Q
    //                                                                                  = 69h
    //         004ace68     JNZ        LAB_004ace86
    //         004ace6a     TEST       this,this
    //         004ace6c     JZ         LAB_004ace82
    //         004ace6e     MOV        DL,byte ptr [EAX + 0x1]
    //         004ace71     MOV        this,DL
    //         004ace73     CMP        DL,byte ptr [EDI + 0x1]=>DAT_00586d19            = 75h
    //                                                                                  = "tSaveDialog"
    //         004ace76     JNZ        LAB_004ace86
    //         004ace78     ADD        EAX,0x2
    //         004ace7b     ADD        EDI,0x2
    //         004ace7e     TEST       this,this
    //         004ace80     JNZ        LAB_004ace62
    //                               LAB_004ace82                                                 XREF[1]:     004ace6c(j)  
    //         004ace82     XOR        EAX,EAX
    //         004ace84     JMP        LAB_004ace8b
    //                               LAB_004ace86                                                 XREF[2]:     004ace68(j), 004ace76(j)  
    //         004ace86     SBB        EAX,EAX
    //         004ace88     SBB        EAX,-0x1
    //                               LAB_004ace8b                                                 XREF[1]:     004ace84(j)  
    //         004ace8b     TEST       EAX,EAX
    //         004ace8d     JNZ        LAB_004acefd
    //                              scr_sed.cpp:3191 (16)
    //         004ace8f     PUSH       EAX
    //         004ace90     PUSH       s_Scenario_Editor_Screen                         = "Scenario Editor Screen"
    //         004ace95     MOV        this,panel_system
    //         004ace9a     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_sed.cpp:3192 (15)
    //         004ace9f     PUSH       s_QuitSaveDialog                                 = 51h    Q
    //         004acea4     MOV        this,panel_system
    //         004acea9     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_sed.cpp:3193 (4)
    //         004aceae     TEST       EBX,EBX
    //         004aceb0     JNZ        LAB_004acec1
    //                              scr_sed.cpp:3194 (10)
    //         004aceb2     PUSH       0x1
    //         004aceb4     PUSH       EBX
    //         004aceb5     MOV        this,ESI
    //         004aceb7     CALL       TRIBE_Screen_Sed::command_save                   void command_save(TRIBE_Screen_Sed * this, uc
    //                              scr_sed.cpp:3195 (14)
    //         004acebc     JMP        LAB_004abe5a
    //                               LAB_004acec1                                                 XREF[1]:     004aceb0(j)  
    //         004acec1     CMP        EBX,0x1
    //         004acec4     JNZ        LAB_004abe5a
    //                              scr_sed.cpp:3197 (15)
    //         004aceca     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004aced0     CALL       TRIBE_Game::start_menu                           int start_menu(TRIBE_Game * this)
    //         004aced5     TEST       EAX,EAX
    //         004aced7     JNZ        LAB_004acee9
    //                              scr_sed.cpp:3198 (11)
    //         004aced9     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004acedf     CALL       RGE_Base_Game::close                             void close(RGE_Base_Game * this)
    //                              scr_sed.cpp:3199 (5)
    //         004acee4     JMP        LAB_004abe5a
    //                               LAB_004acee9                                                 XREF[1]:     004aced7(j)  
    //                              scr_sed.cpp:3200 (15)
    //         004acee9     PUSH       s_Scenario_Editor_Screen                         = "Scenario Editor Screen"
    //         004aceee     MOV        this,panel_system
    //         004acef3     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_sed.cpp:3202 (5)
    //         004acef8     JMP        LAB_004abe5a
    //                               LAB_004acefd                                                 XREF[2]:     004ace50(j), 004ace8d(j)  
    //                              scr_sed.cpp:3206 (72)
    //         004acefd     MOV        this,EBP
    //         004aceff     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //         004acf04     TEST       EAX,EAX
    //         004acf06     JZ         LAB_004acfc2
    //         004acf0c     MOV        this,EBP
    //         004acf0e     MOV        EDI,s_OpenSaveDialog                             = 4Fh    O
    //         004acf13     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //                               LAB_004acf18                                                 XREF[1]:     004acf36(j)  
    //         004acf18     MOV        DL,byte ptr [EAX]
    //         004acf1a     MOV        this,DL
    //         004acf1c     CMP        DL,byte ptr [EDI]=>s_OpenSaveDialog              = 4Fh    O
    //                                                                                  = 65h
    //         004acf1e     JNZ        LAB_004acf3c
    //         004acf20     TEST       this,this
    //         004acf22     JZ         LAB_004acf38
    //         004acf24     MOV        DL,byte ptr [EAX + 0x1]
    //         004acf27     MOV        this,DL
    //         004acf29     CMP        DL,byte ptr [EDI + 0x1]=>DAT_00586d09            = 70h
    //                                                                                  = "nSaveDialog"
    //         004acf2c     JNZ        LAB_004acf3c
    //         004acf2e     ADD        EAX,0x2
    //         004acf31     ADD        EDI,0x2
    //         004acf34     TEST       this,this
    //         004acf36     JNZ        LAB_004acf18
    //                               LAB_004acf38                                                 XREF[1]:     004acf22(j)  
    //         004acf38     XOR        EAX,EAX
    //         004acf3a     JMP        LAB_004acf41
    //                               LAB_004acf3c                                                 XREF[2]:     004acf1e(j), 004acf2c(j)  
    //         004acf3c     SBB        EAX,EAX
    //         004acf3e     SBB        EAX,-0x1
    //                               LAB_004acf41                                                 XREF[1]:     004acf3a(j)  
    //         004acf41     TEST       EAX,EAX
    //         004acf43     JNZ        LAB_004acfc2
    //                              scr_sed.cpp:3208 (16)
    //         004acf45     PUSH       EAX
    //         004acf46     PUSH       s_Scenario_Editor_Screen                         = "Scenario Editor Screen"
    //         004acf4b     MOV        this,panel_system
    //         004acf50     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_sed.cpp:3209 (15)
    //         004acf55     PUSH       s_OpenSaveDialog                                 = 4Fh    O
    //         004acf5a     MOV        this,panel_system
    //         004acf5f     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_sed.cpp:3210 (4)
    //         004acf64     TEST       EBX,EBX
    //         004acf66     JNZ        LAB_004acf77
    //                              scr_sed.cpp:3211 (10)
    //         004acf68     PUSH       0x2
    //         004acf6a     PUSH       EBX
    //         004acf6b     MOV        this,ESI
    //         004acf6d     CALL       TRIBE_Screen_Sed::command_save                   void command_save(TRIBE_Screen_Sed * this, uc
    //                              scr_sed.cpp:3212 (14)
    //         004acf72     JMP        LAB_004abe5a
    //                               LAB_004acf77                                                 XREF[1]:     004acf66(j)  
    //         004acf77     CMP        EBX,0x1
    //         004acf7a     JNZ        LAB_004abe5a
    //                              scr_sed.cpp:3214 (36)
    //         004acf80     PUSH       0x490
    //         004acf85     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004acf8a     ADD        ESP,0x4
    //         004acf8d     MOV        dword ptr [ESP + 0x4c],EAX
    //         004acf91     TEST       EAX,EAX
    //         004acf93     MOV        dword ptr [ESP + 0x40],0x0
    //         004acf9b     JZ         LAB_004acfa4
    //         004acf9d     MOV        this,EAX
    //         004acf9f     CALL       TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open     undefined TRIBE_Screen_Sed_Open(TRIBE_Screen_
    //                               LAB_004acfa4                                                 XREF[1]:     004acf9b(j)  
    //                              scr_sed.cpp:3215 (25)
    //         004acfa4     PUSH       0x0
    //         004acfa6     PUSH       s_Scenario_Editor_Open                           = "Scenario Editor Open"
    //         004acfab     MOV        this,panel_system
    //         004acfb0     MOV        dword ptr [ESP + 0x48],0xffffffff
    //         004acfb8     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_sed.cpp:3217 (5)
    //         004acfbd     JMP        LAB_004abe5a
    //                               LAB_004acfc2                                                 XREF[2]:     004acf06(j), 004acf43(j)  
    //                              scr_sed.cpp:3221 (72)
    //         004acfc2     MOV        this,EBP
    //         004acfc4     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //         004acfc9     TEST       EAX,EAX
    //         004acfcb     JZ         LAB_004ad059
    //         004acfd1     MOV        this,EBP
    //         004acfd3     MOV        EDI,s_NewSaveDialog                              = 4Eh    N
    //         004acfd8     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //                               LAB_004acfdd                                                 XREF[1]:     004acffb(j)  
    //         004acfdd     MOV        DL,byte ptr [EAX]
    //         004acfdf     MOV        this,DL
    //         004acfe1     CMP        DL,byte ptr [EDI]=>s_NewSaveDialog               = 4Eh    N
    //                                                                                  = 77h
    //         004acfe3     JNZ        LAB_004ad001
    //         004acfe5     TEST       this,this
    //         004acfe7     JZ         LAB_004acffd
    //         004acfe9     MOV        DL,byte ptr [EAX + 0x1]
    //         004acfec     MOV        this,DL
    //         004acfee     CMP        DL,byte ptr [EDI + 0x1]=>DAT_00586cf9            = 65h
    //                                                                                  = "SaveDialog"
    //         004acff1     JNZ        LAB_004ad001
    //         004acff3     ADD        EAX,0x2
    //         004acff6     ADD        EDI,0x2
    //         004acff9     TEST       this,this
    //         004acffb     JNZ        LAB_004acfdd
    //                               LAB_004acffd                                                 XREF[1]:     004acfe7(j)  
    //         004acffd     XOR        EAX,EAX
    //         004acfff     JMP        LAB_004ad006
    //                               LAB_004ad001                                                 XREF[2]:     004acfe3(j), 004acff1(j)  
    //         004ad001     SBB        EAX,EAX
    //         004ad003     SBB        EAX,-0x1
    //                               LAB_004ad006                                                 XREF[1]:     004acfff(j)  
    //         004ad006     TEST       EAX,EAX
    //         004ad008     JNZ        LAB_004ad059
    //                              scr_sed.cpp:3223 (16)
    //         004ad00a     PUSH       EAX
    //         004ad00b     PUSH       s_Scenario_Editor_Screen                         = "Scenario Editor Screen"
    //         004ad010     MOV        this,panel_system
    //         004ad015     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_sed.cpp:3224 (15)
    //         004ad01a     PUSH       s_NewSaveDialog                                  = 4Eh    N
    //         004ad01f     MOV        this,panel_system
    //         004ad024     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_sed.cpp:3225 (4)
    //         004ad029     TEST       EBX,EBX
    //         004ad02b     JNZ        LAB_004ad03c
    //                              scr_sed.cpp:3226 (10)
    //         004ad02d     PUSH       0x3
    //         004ad02f     PUSH       EBX
    //         004ad030     MOV        this,ESI
    //         004ad032     CALL       TRIBE_Screen_Sed::command_save                   void command_save(TRIBE_Screen_Sed * this, uc
    //                              scr_sed.cpp:3227 (14)
    //         004ad037     JMP        LAB_004abe5a
    //                               LAB_004ad03c                                                 XREF[1]:     004ad02b(j)  
    //         004ad03c     CMP        EBX,0x1
    //         004ad03f     JNZ        LAB_004abe5a
    //                              scr_sed.cpp:3228 (15)
    //         004ad045     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ad04b     PUSH       0x0
    //         004ad04d     PUSH       0x0
    //         004ad04f     CALL       TRIBE_Game::start_scenario_editor                int start_scenario_editor(TRIBE_Game * this, 
    //                              scr_sed.cpp:3229 (5)
    //         004ad054     JMP        LAB_004abe5a
    //                               LAB_004ad059                                                 XREF[2]:     004acfcb(j), 004ad008(j)  
    //                              scr_sed.cpp:3232 (7)
    //         004ad059     XOR        EAX,EAX
    //         004ad05b     JMP        LAB_004abe5f
    //                               LAB_004ad060                                                 XREF[1]:     004abe9f(j)  
    //                              scr_sed.cpp:2579 (9)
    //         004ad060     INC        EAX
    //         004ad061     MOV        this,ESI
    //         004ad063     PUSH       EAX
    //         004ad064     CALL       TRIBE_Screen_Sed::set_scenario_mode              void set_scenario_mode(TRIBE_Screen_Sed * thi
    //                              scr_sed.cpp:2580 (5)
    //         004ad069     JMP        LAB_004abe5a
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_004ad06e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_004ad06e
    //                              scr_sed.cpp:3233 (118)
    //         004ad06e     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004abf7a::switchdataD_004ad070                       XREF[1]:     action:004abf7a(*)  
    //         004ad070     addr       switchD_004abf7a::caseD_1
    //         004ad074     addr       switchD_004abf7a::caseD_2
    //         004ad078     addr       switchD_004abf7a::caseD_3
    //         004ad07c     addr       switchD_004abf7a::caseD_4
    //         004ad080     addr       switchD_004abf7a::caseD_5
    //         004ad084     addr       switchD_004abf7a::caseD_6
    //         004ad088     addr       switchD_004abf7a::caseD_7
    //         004ad08c     addr       switchD_004abf7a::caseD_8
    //         004ad090     addr       switchD_004abf7a::caseD_9
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004ac009::switchdataD_004ad094                       XREF[1]:     action:004ac009(*)  
    //         004ad094     addr       switchD_004ac009::caseD_0
    //         004ad098     addr       switchD_004ac009::caseD_1
    //         004ad09c     addr       switchD_004ac009::caseD_2
    //         004ad0a0     addr       switchD_004ac009::caseD_3
    //         004ad0a4     addr       switchD_004ac009::caseD_4
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004ac55f::switchdataD_004ad0a8                       XREF[1]:     action:004ac55f(*)  
    //         004ad0a8     addr       switchD_004ac55f::caseD_0
    //         004ad0ac     addr       switchD_004ac55f::caseD_1
    //         004ad0b0     addr       switchD_004ac55f::caseD_2
    //         004ad0b4     addr       switchD_004ac55f::caseD_3
    //         004ad0b8     addr       switchD_004ac55f::caseD_4
    //         004ad0bc     addr       switchD_004ac55f::caseD_5
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004ac5c5::switchdataD_004ad0c0                       XREF[1]:     action:004ac5c5(*)  
    //         004ad0c0     addr       switchD_004ac5c5::caseD_0
    //         004ad0c4     addr       switchD_004ac5c5::caseD_1
    //         004ad0c8     addr       switchD_004ac5c5::caseD_2
    //         004ad0cc     addr       switchD_004ac5c5::caseD_3
    //         004ad0d0     addr       switchD_004ac5c5::caseD_4
    //         004ad0d4     addr       switchD_004ac5c5::caseD_5
    //         004ad0d8     addr       switchD_004ac5c5::caseD_6
    //         004ad0dc     addr       switchD_004ac5c5::caseD_7
    //         004ad0e0     addr       switchD_004ac5c5::caseD_8
    //         004ad0e4     ??         90h
    //         004ad0e5     ??         90h
    //         004ad0e6     ??         90h
    //         004ad0e7     ??         90h
    //         004ad0e8     ??         90h
    //         004ad0e9     ??         90h
    //         004ad0ea     ??         90h
    //         004ad0eb     ??         90h
    //         004ad0ec     ??         90h
    //         004ad0ed     ??         90h
    //         004ad0ee     ??         90h
    //         004ad0ef     ??         90h
    return 0;
}

void TRIBE_Screen_Sed::draw() {
    /* TODO: Stub */
    //                              void __thiscall draw(TRIBE_Screen_Sed * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              tagRECT           Stack[-0x14]   rect
    //                               ?draw@TRIBE_Screen_Sed@@UAEXXZ                               XREF[1]:     005739f0(*)  
    //                               TRIBE_Screen_Sed::draw
    //                              scr_sed.cpp:3239 (6)
    //         004ad0f0     SUB        ESP,0x10
    //         004ad0f3     PUSH       ESI
    //         004ad0f4     MOV        ESI,this
    //                              scr_sed.cpp:3240 (5)
    //         004ad0f6     CALL       TEasy_Panel::draw                                void draw(TEasy_Panel * this)
    //                              scr_sed.cpp:3243 (28)
    //         004ad0fb     MOV        EAX,dword ptr [ESI + 0x31c]
    //         004ad101     TEST       EAX,EAX
    //         004ad103     JZ         LAB_004ad22d
    //         004ad109     MOV        EAX,dword ptr [ESI + 0x4c8]
    //         004ad10f     TEST       EAX,EAX
    //         004ad111     JZ         LAB_004ad22d
    //                              scr_sed.cpp:3249 (69)
    //         004ad117     MOV        EAX,dword ptr [ESI + 0x8c]
    //         004ad11d     MOV        this,dword ptr [ESI + 0x24]
    //         004ad120     CMP        EAX,this
    //         004ad122     JNZ        LAB_004ad22d
    //         004ad128     MOV        this,dword ptr [ESI + 0x90]
    //         004ad12e     MOV        EAX,dword ptr [ESI + 0x28]
    //         004ad131     CMP        this,EAX
    //         004ad133     JNZ        LAB_004ad22d
    //         004ad139     MOV        EDX,dword ptr [ESI + 0x94]
    //         004ad13f     MOV        EAX,dword ptr [ESI + 0x2c]
    //         004ad142     CMP        EDX,EAX
    //         004ad144     JNZ        LAB_004ad22d
    //         004ad14a     MOV        EAX,dword ptr [ESI + 0x98]
    //         004ad150     MOV        this,dword ptr [ESI + 0x30]
    //         004ad153     CMP        EAX,this
    //         004ad155     JNZ        LAB_004ad22d
    //         004ad15b     PUSH       EBX
    //                              scr_sed.cpp:3251 (9)
    //         004ad15c     MOV        EBX,dword ptr [ESI]
    //         004ad15e     PUSH       0x0
    //         004ad160     MOV        this,ESI
    //         004ad162     CALL       dword ptr [EBX + 0x28]
    //                              scr_sed.cpp:3252 (23)
    //         004ad165     MOV        this,dword ptr [ESI + 0x20]
    //         004ad168     PUSH       0x1
    //         004ad16a     PUSH       s_scr_sed::draw                                  = "scr_sed::draw"
    //         004ad16f     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
    //         004ad174     TEST       EAX,EAX
    //         004ad176     JZ         LAB_004ad227
    //                              scr_sed.cpp:3255 (22)
    //         004ad17c     MOV        this,dword ptr [ESI + 0x4c8]
    //         004ad182     PUSH       EDI
    //         004ad183     ADD        this,0x8c
    //         004ad189     MOV        EDX,dword ptr [this->_padding_]
    //         004ad18b     MOV        dword ptr [ESP + 0xc],EDX
    //         004ad18f     MOV        EAX,dword ptr [ECX + this->_padding_]
    //                              scr_sed.cpp:3256 (71)
    //         004ad192     DEC        EAX
    //         004ad193     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004ad196     MOV        dword ptr [ESP + 0x14],EDX
    //         004ad19a     MOV        DL,byte ptr [ESI + 0x324]
    //         004ad1a0     MOV        EDI,dword ptr [ECX + this->_padding_]
    //         004ad1a3     MOV        this,byte ptr [ESI + 0x325]
    //         004ad1a9     PUSH       this
    //         004ad1aa     MOV        this,byte ptr [ESI + 0x323]
    //         004ad1b0     PUSH       EDX
    //         004ad1b1     MOV        DL,byte ptr [ESI + 0x322]
    //         004ad1b7     PUSH       this
    //         004ad1b8     MOV        this,byte ptr [ESI + 0x321]
    //         004ad1be     PUSH       EDX
    //         004ad1bf     MOV        DL,byte ptr [ESI + 0x320]
    //         004ad1c5     PUSH       this
    //         004ad1c6     PUSH       EDX
    //         004ad1c7     MOV        this,dword ptr [ESI + 0x20]
    //         004ad1ca     PUSH       EAX
    //         004ad1cb     MOV        EAX,dword ptr [ESI + 0x14]
    //         004ad1ce     DEC        EAX
    //         004ad1cf     PUSH       EAX
    //         004ad1d0     PUSH       0x0
    //         004ad1d2     PUSH       0x0
    //         004ad1d4     CALL       TDrawArea::DrawBevel3                            void DrawBevel3(TDrawArea * this, long param_
    //                              scr_sed.cpp:3257 (64)
    //         004ad1d9     MOV        this,byte ptr [ESI + 0x325]
    //         004ad1df     MOV        DL,byte ptr [ESI + 0x324]
    //         004ad1e5     MOV        AL,byte ptr [ESI + 0x323]
    //         004ad1eb     PUSH       this
    //         004ad1ec     MOV        this,byte ptr [ESI + 0x322]
    //         004ad1f2     PUSH       EDX
    //         004ad1f3     MOV        DL,byte ptr [ESI + 0x321]
    //         004ad1f9     PUSH       EAX
    //         004ad1fa     MOV        AL,byte ptr [ESI + 0x320]
    //         004ad200     PUSH       this
    //         004ad201     MOV        this,dword ptr [ESI + 0x18]
    //         004ad204     PUSH       EDX
    //         004ad205     MOV        EDX,dword ptr [ESI + 0x14]
    //         004ad208     DEC        this
    //         004ad209     PUSH       EAX
    //         004ad20a     DEC        EDX
    //         004ad20b     PUSH       this
    //         004ad20c     MOV        this,dword ptr [ESI + 0x20]
    //         004ad20f     INC        EDI
    //         004ad210     PUSH       EDX
    //         004ad211     PUSH       EDI
    //         004ad212     PUSH       0x0
    //         004ad214     CALL       TDrawArea::DrawBevel3                            void DrawBevel3(TDrawArea * this, long param_
    //                              scr_sed.cpp:3258 (14)
    //         004ad219     MOV        this,dword ptr [ESI + 0x20]
    //         004ad21c     PUSH       s_scr_sed::draw                                  = "scr_sed::draw"
    //         004ad221     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
    //         004ad226     POP        EDI
    //                               LAB_004ad227                                                 XREF[1]:     004ad176(j)  
    //                              scr_sed.cpp:3260 (6)
    //         004ad227     MOV        this,ESI
    //         004ad229     CALL       dword ptr [EBX + 0x2c]
    //         004ad22c     POP        EBX
    //                               LAB_004ad22d                                                 XREF[6]:     004ad103(j), 004ad111(j), 
    //                                                                                                         004ad122(j), 004ad133(j), 
    //                                                                                                         004ad144(j), 004ad155(j)  
    //                              scr_sed.cpp:3263 (5)
    //         004ad22d     POP        ESI
    //         004ad22e     ADD        ESP,0x10
    //         004ad231     RET
    //         004ad232     ??         90h
    //         004ad233     NOP
    //         004ad234     NOP
    //         004ad235     NOP
    //         004ad236     NOP
    //         004ad237     NOP
    //         004ad238     NOP
    //         004ad239     NOP
    //         004ad23a     NOP
    //         004ad23b     NOP
    //         004ad23c     NOP
    //         004ad23d     NOP
    //         004ad23e     NOP
    //         004ad23f     NOP
    return;
}

void TRIBE_Screen_Sed::command_cancel() {
    /* TODO: Stub */
    //                              void __thiscall command_cancel(TRIBE_Screen_Sed * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //                               ?command_cancel@TRIBE_Screen_Sed@@QAEXXZ                     XREF[1]:     key_down_action:004abbb8(c)  
    //                               TRIBE_Screen_Sed::command_cancel
    //                              scr_sed.cpp:3269 (18)
    //         004ad240     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ad246     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004ad24b     MOV        this,EAX
    //         004ad24d     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
    //                              scr_sed.cpp:3271 (18)
    //         004ad252     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ad258     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         004ad25d     MOV        this,EAX
    //         004ad25f     JMP        RGE_Player::unselect_area                        void unselect_area(RGE_Player * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
    //         004ad264     ??         90h
    //         004ad265     NOP
    //         004ad266     NOP
    //         004ad267     NOP
    //         004ad268     NOP
    //         004ad269     NOP
    //         004ad26a     NOP
    //         004ad26b     NOP
    //         004ad26c     NOP
    //         004ad26d     NOP
    //         004ad26e     NOP
    //         004ad26f     NOP
    return;
}

int TRIBE_Screen_Sed::command_menu() {
    /* TODO: Stub */
    //                              int __thiscall command_menu(TRIBE_Screen_Sed * this)
    //              int               EAX:4          <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004ad29c(W), 004ad2b4(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004ad2e2(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004ad296(W)  
    //                               ?command_menu@TRIBE_Screen_Sed@@QAEHXZ                       XREF[1]:     action:004abeb8(c)  
    //                               TRIBE_Screen_Sed::command_menu
    //                              scr_sed.cpp:3278 (25)
    //         004ad270     PUSH       -0x1
    //         004ad272     PUSH       FUN_0055f4ab
    //         004ad277     MOV        EAX,FS:[0x0]
    //         004ad27d     PUSH       EAX
    //         004ad27e     MOV        dword ptr FS:[0x0],ESP
    //         004ad285     PUSH       this
    //         004ad286     PUSH       ESI
    //         004ad287     MOV        ESI,this
    //                              language.dll match for 0x4b4: "Waiting"
    //                              scr_sed.cpp:3281 (41)
    //         004ad289     PUSH       0x4b4
    //         004ad28e     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004ad293     ADD        ESP,0x4
    //         004ad296     MOV        dword ptr [ESP + local_10],EAX
    //         004ad29a     TEST       EAX,EAX
    //         004ad29c     MOV        dword ptr [ESP + local_4],0x0
    //         004ad2a4     JZ         LAB_004ad2b0
    //         004ad2a6     PUSH       ESI
    //         004ad2a7     MOV        this,EAX
    //         004ad2a9     CALL       TRIBE_Dialog_Sed_Menu::TRIBE_Dialog_Sed_Menu     undefined TRIBE_Dialog_Sed_Menu(TRIBE_Dialog_
    //         004ad2ae     JMP        LAB_004ad2b2
    //                               LAB_004ad2b0                                                 XREF[1]:     004ad2a4(j)  
    //         004ad2b0     XOR        EAX,EAX
    //                               LAB_004ad2b2                                                 XREF[1]:     004ad2ae(j)  
    //                              scr_sed.cpp:3282 (22)
    //         004ad2b2     TEST       EAX,EAX
    //         004ad2b4     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004ad2bc     JZ         LAB_004ad2e2
    //         004ad2be     MOV        this,dword ptr [EAX + 0xd8]
    //         004ad2c4     TEST       this,this
    //         004ad2c6     JZ         LAB_004ad2e2
    //                              scr_sed.cpp:3284 (8)
    //         004ad2c8     MOV        EDX,dword ptr [EAX]
    //         004ad2ca     PUSH       0x1
    //         004ad2cc     MOV        this,EAX
    //         004ad2ce     CALL       dword ptr [EDX]
    //                              scr_sed.cpp:3286 (2)
    //         004ad2d0     XOR        EAX,EAX
    //                              scr_sed.cpp:3290 (37)
    //         004ad2d2     MOV        this,dword ptr [ESP + 0x8]
    //         004ad2d6     MOV        dword ptr FS:[0x0],this
    //         004ad2dd     POP        ESI
    //         004ad2de     ADD        ESP,0x10
    //         004ad2e1     RET
    //                               LAB_004ad2e2                                                 XREF[2]:     004ad2bc(j), 004ad2c6(j)  
    //         004ad2e2     MOV        this,dword ptr [ESP + local_c]
    //         004ad2e6     MOV        EAX,0x1
    //         004ad2eb     MOV        dword ptr FS:[0x0],this
    //         004ad2f2     POP        ESI
    //         004ad2f3     ADD        ESP,0x10
    //         004ad2f6     RET
    //         004ad2f7     ??         90h
    //         004ad2f8     NOP
    //         004ad2f9     NOP
    //         004ad2fa     NOP
    //         004ad2fb     NOP
    //         004ad2fc     NOP
    //         004ad2fd     NOP
    //         004ad2fe     NOP
    //         004ad2ff     NOP
    return 0;
}

void TRIBE_Screen_Sed::command_new() {
    /* TODO: Stub */
    //                              void __thiscall command_new(TRIBE_Screen_Sed * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //                               ?command_new@TRIBE_Screen_Sed@@QAEXXZ                        XREF[1]:     action:00440544(c)  
    //                               TRIBE_Screen_Sed::command_new
    //                              scr_sed.cpp:3296 (3)
    //         004ad300     PUSH       ESI
    //         004ad301     MOV        ESI,this
    //                              scr_sed.cpp:3297 (9)
    //         004ad303     CALL       TRIBE_Screen_Sed::need_to_save                   uchar need_to_save(TRIBE_Screen_Sed * this)
    //         004ad308     TEST       AL,AL
    //         004ad30a     JZ         LAB_004ad326
    //                              scr_sed.cpp:3298 (24)
    //         004ad30c     PUSH       0x64
    //         004ad30e     PUSH       0x1c2
    //         004ad313     PUSH       s_NewSaveDialog                                  = 4Eh    N
    //                              language.dll match for 0x2447: "Do you want to save your chan
    //         004ad318     PUSH       0x2447
    //         004ad31d     MOV        this,ESI
    //         004ad31f     CALL       TEasy_Panel::popupYesNoCancelDialog              void popupYesNoCancelDialog(TEasy_Panel * thi
    //                              scr_sed.cpp:3301 (2)
    //         004ad324     POP        ESI
    //         004ad325     RET
    //                               LAB_004ad326                                                 XREF[1]:     004ad30a(j)  
    //                              scr_sed.cpp:3300 (15)
    //         004ad326     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ad32c     PUSH       0x0
    //         004ad32e     PUSH       0x0
    //         004ad330     CALL       TRIBE_Game::start_scenario_editor                int start_scenario_editor(TRIBE_Game * this, 
    //                              scr_sed.cpp:3301 (2)
    //         004ad335     POP        ESI
    //         004ad336     RET
    //         004ad337     ??         90h
    //         004ad338     NOP
    //         004ad339     NOP
    //         004ad33a     NOP
    //         004ad33b     NOP
    //         004ad33c     NOP
    //         004ad33d     NOP
    //         004ad33e     NOP
    //         004ad33f     NOP
    return;
}

int TRIBE_Screen_Sed::command_new_map(char* param_1, int param_2, int param_3, int param_4, int param_5, int param_6) {
    /* TODO: Stub */
    //                              int __thiscall command_new_map(TRIBE_Screen_Sed * this, char * param
    //              int               EAX:4          <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     004ad3bf(R)  
    //              int               Stack[0x8]:4   param_2
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     004ad4ee(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     004ad3f1(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     004ad407(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[1]:     004ad34b(R)  
    //              RGE_Map_Gen_In    Stack[-0x524   map_info                  XREF[0,2]:   004ad3f9(*), 004ad4d5(W)  
    //              RGE_Player_Info   Stack[-0x7d0   player_info               XREF[2,15]:  004ad45e(W), 004ad487(R), 004ad45a(*), 004ad4f6(*), 
    //                                                                                     004ad42b(*), 004ad48b(*), 004ad453(*), 004ad4b2(*), 
    //                                                                                     004ad44c(*), 004ad4b8(*), 004ad4ce(*), 004ad43e(W), 
    //                                                                                     004ad41f(W), 004ad400(W), 004ad40f(W), 004ad417(W), 
    //                                                                                     004ad436(W)  
    //              undefined4        Stack[-0x7d4   local_7d4                 XREF[5]:     004ad448(W), 004ad46e(R), 004ad479(W), 004ad47f(W), 
    //                                                                                     004ad49f(R)  
    //              int               Stack[-0x7d8   tribe                     XREF[5]:     004ad360(W), 004ad3b3(R), 004ad3ed(R), 004ad464(R), 
    //                                                                                     004ad4ea(R)  
    //                               ?command_new_map@TRIBE_Screen_Sed@@QAEHPADHHHHH@Z            XREF[1]:     TRIBE_Screen_Sed:004a8304(c)  
    //                               TRIBE_Screen_Sed::command_new_map
    //                              scr_sed.cpp:3308 (11)
    //         004ad340     SUB        ESP,0x7d8
    //         004ad346     MOV        EAX,this
    //         004ad348     PUSH       EBX
    //         004ad349     PUSH       EBP
    //         004ad34a     PUSH       ESI
    //                              scr_sed.cpp:3318 (35)
    //         004ad34b     MOV        ESI,dword ptr [ESP + param_6]
    //         004ad352     MOV        byte ptr [EAX + 0x4c0],0x0
    //         004ad359     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ad35f     PUSH       EDI
    //         004ad360     MOV        dword ptr [ESP + tribe],EAX
    //         004ad364     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004ad36a     TEST       EDX,EDX
    //         004ad36c     JNZ        LAB_004ad3b7
    //                              scr_sed.cpp:3320 (4)
    //         004ad36e     TEST       ESI,ESI
    //         004ad370     JZ         LAB_004ad386
    //                              scr_sed.cpp:3321 (20)
    //         004ad372     PUSH       -0x1
    //         004ad374     PUSH       0x0
    //                              language.dll match for 0x44d: "Loading game data..."
    //         004ad376     PUSH       0x44d
    //         004ad37b     CALL       TRIBE_Game::show_status_message                  void show_status_message(TRIBE_Game * this, i
    //         004ad380     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //                               LAB_004ad386                                                 XREF[1]:     004ad370(j)  
    //                              scr_sed.cpp:3323 (9)
    //         004ad386     CALL       TRIBE_Game::load_game_data                       int load_game_data(TRIBE_Game * this)
    //         004ad38b     TEST       EAX,EAX
    //         004ad38d     JNZ        LAB_004ad3ad
    //                              scr_sed.cpp:3325 (4)
    //         004ad38f     TEST       ESI,ESI
    //         004ad391     JZ         LAB_004ad39e
    //                              scr_sed.cpp:3326 (11)
    //         004ad393     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ad399     CALL       TRIBE_Game::close_status_message                 void close_status_message(TRIBE_Game * this)
    //                               LAB_004ad39e                                                 XREF[1]:     004ad391(j)  
    //                              scr_sed.cpp:3327 (2)
    //         004ad39e     XOR        EAX,EAX
    //                              scr_sed.cpp:3408 (13)
    //         004ad3a0     POP        EDI
    //         004ad3a1     POP        ESI
    //         004ad3a2     POP        EBP
    //         004ad3a3     POP        EBX
    //         004ad3a4     ADD        ESP,0x7d8
    //         004ad3aa     RET        0x18
    //                               LAB_004ad3ad                                                 XREF[1]:     004ad38d(j)  
    //                              scr_sed.cpp:3327 (10)
    //         004ad3ad     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ad3b3     MOV        EAX,dword ptr [ESP + tribe]
    //                               LAB_004ad3b7                                                 XREF[1]:     004ad36c(j)  
    //                              scr_sed.cpp:3330 (6)
    //         004ad3b7     MOV        this,dword ptr [ECX + this->_padding_]
    //                              scr_sed.cpp:3332 (17)
    //         004ad3bd     TEST       ESI,ESI
    //         004ad3bf     MOV        ESI,dword ptr [ESP + param_1]
    //         004ad3c6     MOV        dword ptr [EAX + 0x928],this
    //         004ad3cc     JZ         LAB_004ad3f1
    //                              scr_sed.cpp:3334 (2)
    //         004ad3ce     TEST       ESI,ESI
    //                              scr_sed.cpp:3335 (11)
    //         004ad3d0     PUSH       -0x1
    //         004ad3d2     PUSH       0x0
    //         004ad3d4     JNZ        LAB_004ad3dd
    //         004ad3d6     PUSH       0x44e
    //                              scr_sed.cpp:3336 (2)
    //         004ad3db     JMP        LAB_004ad3e2
    //                              language.dll match for 0x44f: "Loading scenario..."
    //                               LAB_004ad3dd                                                 XREF[1]:     004ad3d4(j)  
    //                              scr_sed.cpp:3337 (20)
    //         004ad3dd     PUSH       0x44f
    //                               LAB_004ad3e2                                                 XREF[1]:     004ad3db(j)  
    //         004ad3e2     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ad3e8     CALL       TRIBE_Game::show_status_message                  void show_status_message(TRIBE_Game * this, i
    //         004ad3ed     MOV        EAX,dword ptr [ESP + tribe]
    //                               LAB_004ad3f1                                                 XREF[1]:     004ad3cc(j)  
    //                              scr_sed.cpp:3352 (22)
    //         004ad3f1     MOV        this,word ptr [ESP + param_4]
    //         004ad3f9     LEA        EDX=>map_info.land,[ESP + 0x2c8]
    //         004ad400     MOV        dword ptr [ESP + player_info.map_type],EDX
    //                              scr_sed.cpp:3353 (31)
    //         004ad407     MOV        DX,word ptr [ESP + param_5]
    //         004ad40f     MOV        word ptr [ESP + player_info.ai_info],this
    //         004ad417     MOV        word ptr [ESP + player_info.campaign],DX
    //         004ad41f     MOV        dword ptr [ESP + player_info.map_info],ESI
    //                              scr_sed.cpp:3365 (66)
    //         004ad426     MOV        this,0x2865
    //         004ad42b     LEA        EDX=>player_info+0x24d,[ESP + 0x265]
    //         004ad432     XOR        ESI,ESI
    //         004ad434     SUB        this,EDX
    //         004ad436     MOV        word ptr [ESP + player_info+0x2aa],SI
    //         004ad43e     MOV        word ptr [ESP + player_info.scenario],0x8
    //         004ad448     MOV        dword ptr [ESP + local_7d4],ESI
    //         004ad44c     LEA        EBX=>player_info+0x274,[ESP + 0x28c]
    //         004ad453     LEA        EBP=>player_info+0x260,[ESP + 0x278]
    //         004ad45a     LEA        EDI=>player_info+0x4,[ESP + 0x1c]
    //         004ad45e     MOV        dword ptr [ESP + player_info.name[0][0]],this
    //         004ad462     JMP        LAB_004ad468
    //                               LAB_004ad464                                                 XREF[1]:     004ad4c7(j)  
    //         004ad464     MOV        EAX,dword ptr [ESP + tribe]
    //                               LAB_004ad468                                                 XREF[1]:     004ad462(j)  
    //                              scr_sed.cpp:3362 (23)
    //         004ad468     MOV        EDX,dword ptr [EAX + 0x928]
    //         004ad46e     MOV        this,dword ptr [ESP + local_7d4]
    //         004ad472     INC        this
    //         004ad473     MOVSX      EDX,word ptr [EDX + 0x44]
    //         004ad477     CMP        this,EDX
    //         004ad479     MOV        dword ptr [ESP + local_7d4],this
    //         004ad47d     JL         LAB_004ad487
    //                              scr_sed.cpp:3363 (8)
    //         004ad47f     MOV        dword ptr [ESP + local_7d4],0x1
    //                               LAB_004ad487                                                 XREF[1]:     004ad47d(j)  
    //                              scr_sed.cpp:3364 (24)
    //         004ad487     MOV        EDX,dword ptr [ESP + player_info.name[0][0]]
    //         004ad48b     LEA        this=>player_info+0x24d,[ESP + ESI*0x1 + 0x265]
    //         004ad492     ADD        this,EDX
    //         004ad494     PUSH       0x41
    //         004ad496     PUSH       this
    //         004ad497     PUSH       EDI
    //         004ad498     MOV        this,EAX
    //         004ad49a     CALL       TRIBE_Screen_Sed::set_string                     void set_string(TRIBE_Screen_Sed * this, char
    //                              scr_sed.cpp:3366 (19)
    //         004ad49f     MOV        DL,byte ptr [ESP + local_7d4]
    //         004ad4a3     MOV        byte ptr [ESP + ESI*0x1 + 0x265],0x0
    //         004ad4ab     MOV        byte ptr [ESP + ESI*0x1 + 0x26e],DL
    //                              scr_sed.cpp:3367 (6)
    //         004ad4b2     MOV        word ptr [EBP]=>player_info+0x260,0xffff
    //                              scr_sed.cpp:3368 (17)
    //         004ad4b8     MOV        dword ptr [EBX]=>player_info+0x274,ESI
    //         004ad4ba     INC        ESI
    //         004ad4bb     ADD        EDI,0x41
    //         004ad4be     ADD        EBP,0x2
    //         004ad4c1     ADD        EBX,0x4
    //         004ad4c4     CMP        ESI,0x8
    //         004ad4c7     JL         LAB_004ad464
    //                              scr_sed.cpp:3380 (29)
    //         004ad4c9     MOV        EAX,[rge_base_game]                              = 00000000
    //         004ad4ce     MOV        dword ptr [ESP + ESI*0x4 + player_info+0x278],
    //         004ad4d5     MOV        word ptr [ESP + map_info.land.clump_num],0x0
    //         004ad4df     MOV        EAX,dword ptr [EAX + 0x60]
    //         004ad4e2     TEST       EAX,EAX
    //         004ad4e4     JZ         LAB_004ad4ea
    //                              scr_sed.cpp:3381 (4)
    //         004ad4e6     MOV        byte ptr [EAX + 0x1],0x1
    //                               LAB_004ad4ea                                                 XREF[1]:     004ad4e4(j)  
    //                              scr_sed.cpp:3383 (38)
    //         004ad4ea     MOV        EDI,dword ptr [ESP + tribe]
    //         004ad4ee     MOV        EAX,dword ptr [ESP + param_3]
    //         004ad4f5     PUSH       EAX
    //         004ad4f6     LEA        EAX=>player_info+0x4,[ESP + 0x20]
    //         004ad4fa     MOV        this,dword ptr [EDI + 0x928]
    //         004ad500     PUSH       EAX
    //         004ad501     MOV        EDX,dword ptr [this->_padding_]
    //         004ad503     CALL       dword ptr [EDX + 0xd4]
    //         004ad509     AND        EAX,0xff
    //         004ad50e     MOV        EBX,EAX
    //                              scr_sed.cpp:3384 (15)
    //         004ad510     JZ         LAB_004ad529
    //         004ad512     MOV        this,dword ptr [EDI + 0x928]
    //         004ad518     CMP        word ptr [ECX + this->_padding_],0x8
    //         004ad51d     JGE        LAB_004ad529
    //                              scr_sed.cpp:3387 (10)
    //         004ad51f     MOV        EDX,dword ptr [this->_padding_]
    //         004ad521     XOR        EBX,EBX
    //         004ad523     CALL       dword ptr [EDX + 0xb8]
    //                               LAB_004ad529                                                 XREF[2]:     004ad510(j), 004ad51d(j)  
    //                              scr_sed.cpp:3389 (12)
    //         004ad529     MOV        EAX,[rge_base_game]                              = 00000000
    //         004ad52e     MOV        EAX,dword ptr [EAX + 0x60]
    //         004ad531     TEST       EAX,EAX
    //         004ad533     JZ         LAB_004ad539
    //                              scr_sed.cpp:3390 (4)
    //         004ad535     MOV        byte ptr [EAX + 0x1],0x0
    //                               LAB_004ad539                                                 XREF[1]:     004ad533(j)  
    //                              scr_sed.cpp:3396 (14)
    //         004ad539     TEST       EBX,EBX
    //         004ad53b     JZ         LAB_004ad57f
    //         004ad53d     MOV        EAX,dword ptr [EDI + 0x5b8]
    //         004ad543     TEST       EAX,EAX
    //         004ad545     JZ         LAB_004ad57f
    //                              scr_sed.cpp:3398 (2)
    //         004ad547     XOR        ESI,ESI
    //                               LAB_004ad549                                                 XREF[1]:     004ad560(j)  
    //                              scr_sed.cpp:3399 (25)
    //         004ad549     MOV        this,dword ptr [EDI + 0x928]
    //         004ad54f     PUSH       ESI
    //         004ad550     MOV        this,dword ptr [ECX + this->_padding_]
    //         004ad553     CALL       RGE_Scenario::Get_player_Active                  int Get_player_Active(RGE_Scenario * this, in
    //         004ad558     TEST       EAX,EAX
    //         004ad55a     JZ         LAB_004ad562
    //         004ad55c     INC        ESI
    //         004ad55d     CMP        ESI,0x8
    //         004ad560     JL         LAB_004ad549
    //                               LAB_004ad562                                                 XREF[1]:     004ad55a(j)  
    //                              scr_sed.cpp:3402 (9)
    //         004ad562     CMP        ESI,0x8
    //         004ad565     JGE        LAB_004ad578
    //         004ad567     TEST       ESI,ESI
    //         004ad569     JLE        LAB_004ad578
    //                              scr_sed.cpp:3403 (13)
    //         004ad56b     MOV        this,dword ptr [EDI + 0x5b8]
    //         004ad571     DEC        ESI
    //         004ad572     PUSH       ESI
    //         004ad573     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
    //                               LAB_004ad578                                                 XREF[2]:     004ad565(j), 004ad569(j)  
    //                              scr_sed.cpp:3404 (7)
    //         004ad578     MOV        this,EDI
    //         004ad57a     CALL       TRIBE_Screen_Sed::SavePlayerActiveStatus         void SavePlayerActiveStatus(TRIBE_Screen_Sed 
    //                               LAB_004ad57f                                                 XREF[2]:     004ad53b(j), 004ad545(j)  
    //                              scr_sed.cpp:3408 (15)
    //         004ad57f     POP        EDI
    //         004ad580     POP        ESI
    //         004ad581     MOV        EAX,EBX
    //         004ad583     POP        EBP
    //         004ad584     POP        EBX
    //         004ad585     ADD        ESP,0x7d8
    //         004ad58b     RET        0x18
    //         004ad58e     ??         90h
    //         004ad58f     NOP
    return 0;
}

void TRIBE_Screen_Sed::command_open() {
    /* TODO: Stub */
    //                              void __thiscall command_open(TRIBE_Screen_Sed * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004ad5ed(W), 004ad60a(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     004ad5ca(R), 004ad617(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004ad5e7(W)  
    //                               ?command_open@TRIBE_Screen_Sed@@QAEXXZ                       XREF[1]:     action:0044050b(c)  
    //                               TRIBE_Screen_Sed::command_open
    //                              scr_sed.cpp:3414 (25)
    //         004ad590     PUSH       -0x1
    //         004ad592     PUSH       FUN_0055f4cb
    //         004ad597     MOV        EAX,FS:[0x0]
    //         004ad59d     PUSH       EAX
    //         004ad59e     MOV        dword ptr FS:[0x0],ESP
    //         004ad5a5     PUSH       this
    //         004ad5a6     PUSH       ESI
    //         004ad5a7     MOV        ESI,this
    //                              scr_sed.cpp:3415 (9)
    //         004ad5a9     CALL       TRIBE_Screen_Sed::need_to_save                   uchar need_to_save(TRIBE_Screen_Sed * this)
    //         004ad5ae     TEST       AL,AL
    //         004ad5b0     JZ         LAB_004ad5da
    //                              scr_sed.cpp:3416 (24)
    //         004ad5b2     PUSH       0x64
    //         004ad5b4     PUSH       0x1c2
    //         004ad5b9     PUSH       s_OpenSaveDialog                                 = 4Fh    O
    //                              language.dll match for 0x2447: "Do you want to save your chan
    //         004ad5be     PUSH       0x2447
    //         004ad5c3     MOV        this,ESI
    //         004ad5c5     CALL       TEasy_Panel::popupYesNoCancelDialog              void popupYesNoCancelDialog(TEasy_Panel * thi
    //                              scr_sed.cpp:3422 (16)
    //         004ad5ca     MOV        this,dword ptr [ESP + local_c]
    //         004ad5ce     MOV        dword ptr FS:[0x0],this
    //         004ad5d5     POP        ESI
    //         004ad5d6     ADD        ESP,0x10
    //         004ad5d9     RET
    //                               LAB_004ad5da                                                 XREF[1]:     004ad5b0(j)  
    //                              scr_sed.cpp:3419 (36)
    //         004ad5da     PUSH       0x490
    //         004ad5df     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004ad5e4     ADD        ESP,0x4
    //         004ad5e7     MOV        dword ptr [ESP + local_10],EAX
    //         004ad5eb     TEST       EAX,EAX
    //         004ad5ed     MOV        dword ptr [ESP + local_4],0x0
    //         004ad5f5     JZ         LAB_004ad5fe
    //         004ad5f7     MOV        this,EAX
    //         004ad5f9     CALL       TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open     undefined TRIBE_Screen_Sed_Open(TRIBE_Screen_
    //                               LAB_004ad5fe                                                 XREF[1]:     004ad5f5(j)  
    //                              scr_sed.cpp:3420 (25)
    //         004ad5fe     PUSH       0x0
    //         004ad600     PUSH       s_Scenario_Editor_Open                           = "Scenario Editor Open"
    //         004ad605     MOV        this,panel_system
    //         004ad60a     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004ad612     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_sed.cpp:3422 (16)
    //         004ad617     MOV        this,dword ptr [ESP + local_c]
    //         004ad61b     POP        ESI
    //         004ad61c     MOV        dword ptr FS:[0x0],this
    //         004ad623     ADD        ESP,0x10
    //         004ad626     RET
    //         004ad627     ??         90h
    //         004ad628     NOP
    //         004ad629     NOP
    //         004ad62a     NOP
    //         004ad62b     NOP
    //         004ad62c     NOP
    //         004ad62d     NOP
    //         004ad62e     NOP
    //         004ad62f     NOP
    return;
}

void TRIBE_Screen_Sed::command_outline() {
    /* TODO: Stub */
    //                              void __thiscall command_outline(TRIBE_Screen_Sed * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004ad63a(*), 004ad63e(*)  
    //              uchar             Stack[-0x8]:1  outline_type
    //                               ?command_outline@TRIBE_Screen_Sed@@QAEXXZ
    //                               TRIBE_Screen_Sed::command_outline
    //                              scr_sed.cpp:3428 (1)
    //         004ad630     PUSH       this
    //                              scr_sed.cpp:3431 (13)
    //         004ad631     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         004ad637     MOV        this,byte ptr [EDX + 0x50]
    //         004ad63a     MOV        byte ptr [ESP]=>local_4,this
    //                              scr_sed.cpp:3433 (21)
    //         004ad63e     MOV        EAX,dword ptr [ESP]=>local_4
    //         004ad642     AND        EAX,0xff
    //         004ad647     CMP        EAX,0x3
    //         004ad64a     JA         switchD_004ad64c::default
    //                               switchD_004ad64c::switchD
    //         004ad64c     JMP        dword ptr [EAX*0x4 + switchD_004ad64c::switchd   = 004ad653
    //                               switchD_004ad64c::caseD_3                                    XREF[3]:     004ad64c(j), 004ad668(*), 
    //                               switchD_004ad64c::caseD_0                                                 004ad674(*)  
    //                              scr_sed.cpp:3437 (2)
    //         004ad653     MOV        this,0x2
    //                              scr_sed.cpp:3449 (3)
    //         004ad655     MOV        byte ptr [EDX + 0x50],this
    //                              scr_sed.cpp:3450 (2)
    //         004ad658     POP        this
    //         004ad659     RET
    //                               switchD_004ad64c::caseD_2                                    XREF[2]:     004ad64c(j), 004ad670(*)  
    //                              scr_sed.cpp:3441 (2)
    //         004ad65a     MOV        this,0x1
    //                              scr_sed.cpp:3449 (3)
    //         004ad65c     MOV        byte ptr [EDX + 0x50],this
    //                              scr_sed.cpp:3450 (2)
    //         004ad65f     POP        this
    //         004ad660     RET
    //                               switchD_004ad64c::caseD_1                                    XREF[2]:     004ad64c(j), 004ad66c(*)  
    //                              scr_sed.cpp:3445 (2)
    //         004ad661     XOR        this,this
    //                               switchD_004ad64c::default                                    XREF[1]:     004ad64a(j)  
    //                              scr_sed.cpp:3449 (3)
    //         004ad663     MOV        byte ptr [EDX + 0x50],this
    //                              scr_sed.cpp:3450 (18)
    //         004ad666     POP        this
    //         004ad667     RET
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004ad64c::switchdataD_004ad668                       XREF[1]:     command_outline:004ad64c(*)  
    //         004ad668     addr       switchD_004ad64c::caseD_0
    //         004ad66c     addr       switchD_004ad64c::caseD_1
    //         004ad670     addr       switchD_004ad64c::caseD_2
    //         004ad674     addr       switchD_004ad64c::caseD_0
    //         004ad678     ??         90h
    //         004ad679     ??         90h
    //         004ad67a     ??         90h
    //         004ad67b     ??         90h
    //         004ad67c     ??         90h
    //         004ad67d     ??         90h
    //         004ad67e     ??         90h
    //         004ad67f     ??         90h
    return;
}

void TRIBE_Screen_Sed::command_player(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall command_player(TRIBE_Screen_Sed * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004ad686(R)  
    //                               ?command_player@TRIBE_Screen_Sed@@QAEXH@Z
    //                               TRIBE_Screen_Sed::command_player
    //                              scr_sed.cpp:3456 (16)
    //         004ad680     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ad686     MOV        EDX,dword ptr [ESP + param_1]
    //         004ad68a     PUSH       EDX
    //         004ad68b     MOV        EAX,dword ptr [this->_padding_]
    //         004ad68d     CALL       dword ptr [EAX + 0x14]
    //                              scr_sed.cpp:3458 (3)
    //         004ad690     RET        0x4
    //         004ad693     ??         90h
    //         004ad694     NOP
    //         004ad695     NOP
    //         004ad696     NOP
    //         004ad697     NOP
    //         004ad698     NOP
    //         004ad699     NOP
    //         004ad69a     NOP
    //         004ad69b     NOP
    //         004ad69c     NOP
    //         004ad69d     NOP
    //         004ad69e     NOP
    //         004ad69f     NOP
    return;
}

void TRIBE_Screen_Sed::command_quit() {
    /* TODO: Stub */
    //                              void __thiscall command_quit(TRIBE_Screen_Sed * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //                               ?command_quit@TRIBE_Screen_Sed@@QAEXXZ                       XREF[1]:     action:0044045a(c)  
    //                               TRIBE_Screen_Sed::command_quit
    //                              scr_sed.cpp:3464 (3)
    //         004ad6a0     PUSH       ESI
    //         004ad6a1     MOV        ESI,this
    //                              scr_sed.cpp:3465 (9)
    //         004ad6a3     CALL       TRIBE_Screen_Sed::need_to_save                   uchar need_to_save(TRIBE_Screen_Sed * this)
    //         004ad6a8     TEST       AL,AL
    //         004ad6aa     JZ         LAB_004ad6c6
    //                              scr_sed.cpp:3466 (24)
    //         004ad6ac     PUSH       0x64
    //         004ad6ae     PUSH       0x1c2
    //         004ad6b3     PUSH       s_QuitSaveDialog                                 = 51h    Q
    //                              language.dll match for 0x2447: "Do you want to save your chan
    //         004ad6b8     PUSH       0x2447
    //         004ad6bd     MOV        this,ESI
    //         004ad6bf     CALL       TEasy_Panel::popupYesNoCancelDialog              void popupYesNoCancelDialog(TEasy_Panel * thi
    //                              scr_sed.cpp:3474 (2)
    //         004ad6c4     POP        ESI
    //         004ad6c5     RET
    //                               LAB_004ad6c6                                                 XREF[1]:     004ad6aa(j)  
    //                              scr_sed.cpp:3469 (15)
    //         004ad6c6     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ad6cc     CALL       TRIBE_Game::start_menu                           int start_menu(TRIBE_Game * this)
    //         004ad6d1     TEST       EAX,EAX
    //         004ad6d3     JNZ        LAB_004ad6e2
    //                              scr_sed.cpp:3470 (11)
    //         004ad6d5     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ad6db     CALL       RGE_Base_Game::close                             void close(RGE_Base_Game * this)
    //                              scr_sed.cpp:3474 (2)
    //         004ad6e0     POP        ESI
    //         004ad6e1     RET
    //                               LAB_004ad6e2                                                 XREF[1]:     004ad6d3(j)  
    //                              scr_sed.cpp:3472 (15)
    //         004ad6e2     PUSH       s_Scenario_Editor_Screen                         = "Scenario Editor Screen"
    //         004ad6e7     MOV        this,panel_system
    //         004ad6ec     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_sed.cpp:3474 (2)
    //         004ad6f1     POP        ESI
    //         004ad6f2     RET
    //         004ad6f3     ??         90h
    //         004ad6f4     NOP
    //         004ad6f5     NOP
    //         004ad6f6     NOP
    //         004ad6f7     NOP
    //         004ad6f8     NOP
    //         004ad6f9     NOP
    //         004ad6fa     NOP
    //         004ad6fb     NOP
    //         004ad6fc     NOP
    //         004ad6fd     NOP
    //         004ad6fe     NOP
    //         004ad6ff     NOP
    return;
}

void TRIBE_Screen_Sed::command_save(uchar param_1, uchar param_2) {
    /* TODO: Stub */
    //                              void __thiscall command_save(TRIBE_Screen_Sed * this, uchar param_1,
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004ad7ec(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     004ad7c4(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004ad93b(R)  
    //              char[260]         Stack[-0x114   temp_name
    //                               ?command_save@TRIBE_Screen_Sed@@QAEXEE@Z                     XREF[5]:     action:00440497(c), 
    //                               TRIBE_Screen_Sed::command_save                                            action:004aceb7(c), 
    //                                                                                                         action:004acf6d(c), 
    //                                                                                                         action:004ad032(c), 
    //                                                                                                         command_quick_save:004adafe(c)  
    //                              scr_sed.cpp:3480 (32)
    //         004ad700     MOV        EAX,FS:[0x0]
    //         004ad706     PUSH       -0x1
    //         004ad708     PUSH       FUN_0055f4ee
    //         004ad70d     PUSH       EAX
    //         004ad70e     MOV        dword ptr FS:[0x0],ESP
    //         004ad715     SUB        ESP,0x108
    //         004ad71b     PUSH       EBP
    //         004ad71c     PUSH       ESI
    //         004ad71d     PUSH       EDI
    //         004ad71e     MOV        EBP,this
    //                              scr_sed.cpp:3485 (7)
    //         004ad720     PUSH       0xb
    //         004ad722     CALL       TRIBE_Screen_Sed::set_scenario_mode              void set_scenario_mode(TRIBE_Screen_Sed * thi
    //                              scr_sed.cpp:3486 (16)
    //         004ad727     MOV        EAX,dword ptr [EBP + 0x928]
    //         004ad72d     PUSH       0x1
    //         004ad72f     MOV        this,dword ptr [EAX + 0x5c]
    //         004ad732     CALL       T_Scenario::Save_victory_conditions_into_players void Save_victory_conditions_into_players(T_S
    //                              scr_sed.cpp:3488 (19)
    //         004ad737     MOV        this,dword ptr [EBP + 0x928]
    //         004ad73d     MOV        this,dword ptr [ECX + this->_padding_]
    //         004ad740     CALL       RGE_Scenario::active_player_count                int active_player_count(RGE_Scenario * this)
    //         004ad745     CMP        EAX,0x1
    //         004ad748     JGE        LAB_004ad773
    //                              scr_sed.cpp:3490 (15)
    //         004ad74a     PUSH       s_Scenario_Menu_Dialog                           = "Scenario Menu Dialog"
    //         004ad74f     MOV        this,panel_system
    //         004ad754     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_sed.cpp:3491 (21)
    //         004ad759     PUSH       0x64
    //         004ad75b     PUSH       0x1c2
    //         004ad760     PUSH       0x0
    //                              language.dll match for 0x2742: "You need to make at least one
    //         004ad762     PUSH       0x2742
    //         004ad767     MOV        this,EBP
    //         004ad769     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
    //                              scr_sed.cpp:3492 (5)
    //         004ad76e     JMP        LAB_004ad93b
    //                               LAB_004ad773                                                 XREF[1]:     004ad748(j)  
    //                              scr_sed.cpp:3495 (19)
    //         004ad773     MOV        EDX,dword ptr [EBP + 0x928]
    //         004ad779     MOV        this,dword ptr [EDX + 0x5c]
    //         004ad77c     CALL       RGE_Scenario::any_player_count                   int any_player_count(RGE_Scenario * this)
    //         004ad781     CMP        EAX,0x1
    //         004ad784     JGE        LAB_004ad7af
    //                              scr_sed.cpp:3497 (15)
    //         004ad786     PUSH       s_Scenario_Menu_Dialog                           = "Scenario Menu Dialog"
    //         004ad78b     MOV        this,panel_system
    //         004ad790     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_sed.cpp:3498 (21)
    //         004ad795     PUSH       0x64
    //         004ad797     PUSH       0x1c2
    //         004ad79c     PUSH       0x0
    //                              language.dll match for 0x2743: "One or more civilizations mus
    //         004ad79e     PUSH       0x2743
    //         004ad7a3     MOV        this,EBP
    //         004ad7a5     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
    //                              scr_sed.cpp:3499 (5)
    //         004ad7aa     JMP        LAB_004ad93b
    //                               LAB_004ad7af                                                 XREF[1]:     004ad784(j)  
    //                              scr_sed.cpp:3502 (16)
    //         004ad7af     MOV        EAX,dword ptr [EBP + 0x928]
    //         004ad7b5     MOV        this,dword ptr [EAX + 0x5c]
    //         004ad7b8     CALL       RGE_Scenario::Get_scenario_name                  char * Get_scenario_name(RGE_Scenario * this)
    //         004ad7bd     MOV        EDI,EAX
    //                              scr_sed.cpp:3503 (5)
    //         004ad7bf     CMP        byte ptr [EDI],0x0
    //         004ad7c2     JNZ        LAB_004ad7d8
    //                              scr_sed.cpp:3505 (15)
    //         004ad7c4     MOV        this,dword ptr [ESP + param_2]
    //         004ad7cb     PUSH       this
    //         004ad7cc     MOV        this,EBP
    //         004ad7ce     CALL       TRIBE_Screen_Sed::command_save_as                void command_save_as(TRIBE_Screen_Sed * this,
    //                              scr_sed.cpp:3506 (5)
    //         004ad7d3     JMP        LAB_004ad93b
    //                               LAB_004ad7d8                                                 XREF[1]:     004ad7c2(j)  
    //                              scr_sed.cpp:3509 (20)
    //         004ad7d8     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ad7de     PUSH       -0x1
    //         004ad7e0     PUSH       0x0
    //                              language.dll match for 0x450: "Saving scenario..."
    //         004ad7e2     PUSH       0x450
    //         004ad7e7     CALL       TRIBE_Game::show_status_message                  void show_status_message(TRIBE_Game * this, i
    //                              scr_sed.cpp:3511 (11)
    //         004ad7ec     MOV        AL,byte ptr [ESP + param_1]
    //         004ad7f3     TEST       AL,AL
    //         004ad7f5     JZ         LAB_004ad806
    //                              scr_sed.cpp:3512 (15)
    //         004ad7f7     PUSH       s_Scenario_Menu_Dialog                           = "Scenario Menu Dialog"
    //         004ad7fc     MOV        this,panel_system
    //         004ad801     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                               LAB_004ad806                                                 XREF[1]:     004ad7f5(j)  
    //                              scr_sed.cpp:3514 (15)
    //         004ad806     MOV        this,dword ptr [EBP + 0x928]
    //         004ad80c     PUSH       EDI
    //         004ad80d     MOV        EDX,dword ptr [this->_padding_]
    //         004ad80f     CALL       dword ptr [EDX + 0xe4]
    //                              scr_sed.cpp:3516 (15)
    //         004ad815     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ad81b     TEST       AL,AL
    //         004ad81d     JNZ        LAB_004ad83e
    //         004ad81f     CALL       TRIBE_Game::close_status_message                 void close_status_message(TRIBE_Game * this)
    //                              scr_sed.cpp:3517 (21)
    //         004ad824     PUSH       0x64
    //         004ad826     PUSH       offset DAT_fffffff8
    //         004ad82b     PUSH       0x0=>DAT_fffffff4
    //                              language.dll match for 0x963: "The scenario could not be save
    //         004ad82d     PUSH       offset DAT_fffffff0
    //         004ad832     MOV        this,EBP
    //         004ad834     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
    //                              scr_sed.cpp:3518 (5)
    //         004ad839     JMP        LAB_004ad93b
    //                               LAB_004ad83e                                                 XREF[1]:     004ad81d(j)  
    //                              scr_sed.cpp:3521 (5)
    //         004ad83e     CALL       TRIBE_Game::close_status_message                 void close_status_message(TRIBE_Game * this)
    //                              scr_sed.cpp:3524 (42)
    //         004ad843     MOV        EAX,[rge_base_game]                              = 00000000
    //         004ad848     PUSH       s_Game_File_Number                               = "Game File Number"
    //         004ad84d     PUSH       0x0=>DAT_fffffff8
    //         004ad84f     MOV        this,dword ptr [EAX + 0x1ac]
    //         004ad855     CALL       TRegistry::RegGetInt                             int RegGetInt(TRegistry * this, int param_1, 
    //         004ad85a     PUSH       EAX
    //         004ad85b     LEA        this,[ESP + 0x14]
    //         004ad85f     PUSH       s_default%d                                      = "default%d"
    //         004ad864     PUSH       this=>DAT_fffffff4
    //         004ad865     CALL       sprintf                                          undefined sprintf()
    //         004ad86a     ADD        ESP,0xc
    //                              scr_sed.cpp:3525 (51)
    //         004ad86d     LEA        ESI,[ESP + 0x10]
    //         004ad871     MOV        EAX,EDI
    //                               LAB_004ad873                                                 XREF[1]:     004ad891(j)  
    //         004ad873     MOV        DL,byte ptr [EAX]
    //         004ad875     MOV        this,DL
    //         004ad877     CMP        DL,byte ptr [ESI]
    //         004ad879     JNZ        LAB_004ad897
    //         004ad87b     TEST       this,this
    //         004ad87d     JZ         LAB_004ad893
    //         004ad87f     MOV        DL,byte ptr [EAX + 0x1]
    //         004ad882     MOV        this,DL
    //         004ad884     CMP        DL,byte ptr [ESI + 0x1]
    //         004ad887     JNZ        LAB_004ad897
    //         004ad889     ADD        EAX,0x2
    //         004ad88c     ADD        ESI,0x2
    //         004ad88f     TEST       this,this
    //         004ad891     JNZ        LAB_004ad873
    //                               LAB_004ad893                                                 XREF[1]:     004ad87d(j)  
    //         004ad893     XOR        EAX,EAX
    //         004ad895     JMP        LAB_004ad89c
    //                               LAB_004ad897                                                 XREF[2]:     004ad879(j), 004ad887(j)  
    //         004ad897     SBB        EAX,EAX
    //         004ad899     SBB        EAX,-0x1
    //                               LAB_004ad89c                                                 XREF[1]:     004ad895(j)  
    //         004ad89c     TEST       EAX,EAX
    //         004ad89e     JZ         LAB_004ad8a7
    //                              scr_sed.cpp:3526 (7)
    //         004ad8a0     MOV        byte ptr [EBP + 0x4c0],0x0
    //                               LAB_004ad8a7                                                 XREF[1]:     004ad89e(j)  
    //                              scr_sed.cpp:3528 (11)
    //         004ad8a7     MOV        AL,byte ptr [ESP + 0x128]
    //         004ad8ae     CMP        AL,0x1
    //         004ad8b0     JNZ        LAB_004ad8df
    //                              scr_sed.cpp:3530 (15)
    //         004ad8b2     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ad8b8     CALL       TRIBE_Game::start_menu                           int start_menu(TRIBE_Game * this)
    //         004ad8bd     TEST       EAX,EAX
    //         004ad8bf     JNZ        LAB_004ad8ce
    //                              scr_sed.cpp:3531 (11)
    //         004ad8c1     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ad8c7     CALL       RGE_Base_Game::close                             void close(RGE_Base_Game * this)
    //                              scr_sed.cpp:3532 (2)
    //         004ad8cc     JMP        LAB_004ad93b
    //                               LAB_004ad8ce                                                 XREF[1]:     004ad8bf(j)  
    //                              scr_sed.cpp:3533 (15)
    //         004ad8ce     PUSH       s_Scenario_Editor_Screen                         = "Scenario Editor Screen"
    //         004ad8d3     MOV        this,panel_system
    //         004ad8d8     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_sed.cpp:3535 (6)
    //         004ad8dd     JMP        LAB_004ad93b
    //                               LAB_004ad8df                                                 XREF[1]:     004ad8b0(j)  
    //         004ad8df     CMP        AL,0x2
    //         004ad8e1     JNZ        LAB_004ad928
    //                              scr_sed.cpp:3537 (39)
    //         004ad8e3     PUSH       0x490
    //         004ad8e8     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004ad8ed     ADD        ESP,0x4
    //         004ad8f0     MOV        dword ptr [ESP + 0xc],EAX
    //         004ad8f4     TEST       EAX,EAX
    //         004ad8f6     MOV        dword ptr [ESP + 0x11c],0x0
    //         004ad901     JZ         LAB_004ad90a
    //         004ad903     MOV        this,EAX
    //         004ad905     CALL       TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open     undefined TRIBE_Screen_Sed_Open(TRIBE_Screen_
    //                               LAB_004ad90a                                                 XREF[1]:     004ad901(j)  
    //                              scr_sed.cpp:3538 (28)
    //         004ad90a     PUSH       0x0
    //         004ad90c     PUSH       s_Scenario_Editor_Open                           = "Scenario Editor Open"
    //         004ad911     MOV        this,panel_system
    //         004ad916     MOV        dword ptr [ESP + 0x124],0xffffffff
    //         004ad921     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_sed.cpp:3540 (6)
    //         004ad926     JMP        LAB_004ad93b
    //                               LAB_004ad928                                                 XREF[1]:     004ad8e1(j)  
    //         004ad928     CMP        AL,0x3
    //         004ad92a     JNZ        LAB_004ad93b
    //                              scr_sed.cpp:3541 (15)
    //         004ad92c     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ad932     PUSH       0x0
    //         004ad934     PUSH       0x0=>DAT_fffffff8
    //         004ad936     CALL       TRIBE_Game::start_scenario_editor                int start_scenario_editor(TRIBE_Game * this, 
    //                               LAB_004ad93b                                                 XREF[8]:     004ad76e(j), 004ad7aa(j), 
    //                                                                                                         004ad7d3(j), 004ad839(j), 
    //                                                                                                         004ad8cc(j), 004ad8dd(j), 
    //                                                                                                         004ad926(j), 004ad92a(j)  
    //                              scr_sed.cpp:3542 (26)
    //         004ad93b     MOV        this,dword ptr [ESP + local_c]
    //         004ad942     POP        EDI
    //         004ad943     POP        ESI
    //         004ad944     MOV        dword ptr FS:[0x0],this
    //         004ad94b     POP        EBP
    //         004ad94c     ADD        ESP,0x114
    //         004ad952     RET        0x8
    //         004ad955     ??         90h
    //         004ad956     NOP
    //         004ad957     NOP
    //         004ad958     NOP
    //         004ad959     NOP
    //         004ad95a     NOP
    //         004ad95b     NOP
    //         004ad95c     NOP
    //         004ad95d     NOP
    //         004ad95e     NOP
    //         004ad95f     NOP
    return;
}

void TRIBE_Screen_Sed::command_save_as(uchar param_1) {
    /* TODO: Stub */
    //                              void __thiscall command_save_as(TRIBE_Screen_Sed * this, uchar param
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004ada11(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004ada04(W), 004ada39(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004ada58(R)  
    //              char[224]         Stack[-0xf0]   scenario_name             XREF[1,2]:   004ad9fe(W), 004ad9f1(W), 004ada18(*)  
    //                               ?command_save_as@TRIBE_Screen_Sed@@QAEXE@Z                   XREF[2]:     action:004404d2(c), 
    //                               TRIBE_Screen_Sed::command_save_as                                         command_save:004ad7ce(c)  
    //                              scr_sed.cpp:3548 (30)
    //         004ad960     MOV        EAX,FS:[0x0]
    //         004ad966     PUSH       -0x1
    //         004ad968     PUSH       FUN_0055f50e
    //         004ad96d     PUSH       EAX
    //         004ad96e     MOV        dword ptr FS:[0x0],ESP
    //         004ad975     SUB        ESP,0xe4
    //         004ad97b     PUSH       ESI
    //         004ad97c     MOV        ESI,this
    //                              scr_sed.cpp:3553 (7)
    //         004ad97e     PUSH       0xb
    //         004ad980     CALL       TRIBE_Screen_Sed::set_scenario_mode              void set_scenario_mode(TRIBE_Screen_Sed * thi
    //                              scr_sed.cpp:3554 (16)
    //         004ad985     MOV        EAX,dword ptr [ESI + 0x928]
    //         004ad98b     PUSH       0x1
    //         004ad98d     MOV        this,dword ptr [EAX + 0x5c]
    //         004ad990     CALL       T_Scenario::Save_victory_conditions_into_players void Save_victory_conditions_into_players(T_S
    //                              scr_sed.cpp:3556 (19)
    //         004ad995     MOV        this,dword ptr [ESI + 0x928]
    //         004ad99b     MOV        this,dword ptr [ECX + this->_padding_]
    //         004ad99e     CALL       RGE_Scenario::active_player_count                int active_player_count(RGE_Scenario * this)
    //         004ad9a3     CMP        EAX,0x1
    //         004ad9a6     JGE        LAB_004ad9c2
    //                              scr_sed.cpp:3558 (21)
    //         004ad9a8     PUSH       0x64
    //         004ad9aa     PUSH       0x1c2
    //         004ad9af     PUSH       0x0
    //                              language.dll match for 0x2742: "You need to make at least one
    //         004ad9b1     PUSH       0x2742
    //         004ad9b6     MOV        this,ESI
    //         004ad9b8     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
    //                              scr_sed.cpp:3559 (5)
    //         004ad9bd     JMP        LAB_004ada58
    //                               LAB_004ad9c2                                                 XREF[1]:     004ad9a6(j)  
    //                              scr_sed.cpp:3562 (19)
    //         004ad9c2     MOV        EDX,dword ptr [ESI + 0x928]
    //         004ad9c8     MOV        this,dword ptr [EDX + 0x5c]
    //         004ad9cb     CALL       RGE_Scenario::any_player_count                   int any_player_count(RGE_Scenario * this)
    //         004ad9d0     CMP        EAX,0x1
    //         004ad9d3     JGE        LAB_004ad9ec
    //                              scr_sed.cpp:3564 (21)
    //         004ad9d5     PUSH       0x64
    //         004ad9d7     PUSH       0x1c2
    //         004ad9dc     PUSH       0x0
    //                              language.dll match for 0x2743: "One or more civilizations mus
    //         004ad9de     PUSH       0x2743
    //         004ad9e3     MOV        this,ESI
    //         004ad9e5     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
    //                              scr_sed.cpp:3565 (2)
    //         004ad9ea     JMP        LAB_004ada58
    //                               LAB_004ad9ec                                                 XREF[1]:     004ad9d3(j)  
    //                              scr_sed.cpp:3577 (65)
    //         004ad9ec     PUSH       0x6a4
    //         004ad9f1     MOV        byte ptr [ESP + scenario_name[4]],0x0
    //         004ad9f6     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004ad9fb     ADD        ESP,0x4
    //         004ad9fe     MOV        dword ptr [ESP + scenario_name[0]],EAX
    //         004ada02     TEST       EAX,EAX
    //         004ada04     MOV        dword ptr [ESP + local_4],0x0
    //         004ada0f     JZ         LAB_004ada2d
    //         004ada11     MOV        this,dword ptr [ESP + param_1]
    //         004ada18     LEA        EDX=>scenario_name[4],[ESP + 0x8]
    //         004ada1c     AND        this,0xff
    //         004ada22     PUSH       this
    //         004ada23     PUSH       EDX
    //         004ada24     PUSH       0x2
    //         004ada26     MOV        this,EAX
    //         004ada28     CALL       TribeSaveGameScreen::TribeSaveGameScreen         undefined TribeSaveGameScreen(TribeSaveGameSc
    //                               LAB_004ada2d                                                 XREF[1]:     004ada0f(j)  
    //                              scr_sed.cpp:3578 (28)
    //         004ada2d     PUSH       0x0
    //         004ada2f     PUSH       s_Save_Game_Screen                               = "Save Game Screen"
    //         004ada34     MOV        this,panel_system
    //         004ada39     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004ada44     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_sed.cpp:3579 (15)
    //         004ada49     PUSH       s_Scenario_Menu_Dialog                           = "Scenario Menu Dialog"
    //         004ada4e     MOV        this,panel_system
    //         004ada53     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                               LAB_004ada58                                                 XREF[2]:     004ad9bd(j), 004ad9ea(j)  
    //                              scr_sed.cpp:3580 (24)
    //         004ada58     MOV        this,dword ptr [ESP + local_c]
    //         004ada5f     POP        ESI
    //         004ada60     MOV        dword ptr FS:[0x0],this
    //         004ada67     ADD        ESP,0xf0
    //         004ada6d     RET        0x4
    return;
}

char* TRIBE_Screen_Sed::scenario_get_default_name() {
    /* TODO: Stub */
    //                              char * __thiscall scenario_get_default_name(TRIBE_Screen_Sed * this)
    //              char *            EAX:4          <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              char[260]         Stack[-0x108   temp_name                 XREF[0,2]:   004adaa9(*), 004adac1(*)  
    //                               ?scenario_get_default_name@TRIBE_Screen_Sed@@QAEPADXZ        XREF[1]:     command_quick_save:004adaf3(c)  
    //                               TRIBE_Screen_Sed::scenario_get_default_name
    //                              scr_sed.cpp:3586 (9)
    //         004ada70     SUB        ESP,0x104
    //         004ada76     PUSH       ESI
    //         004ada77     MOV        ESI,this
    //                              scr_sed.cpp:3589 (14)
    //         004ada79     MOV        EAX,dword ptr [ESI + 0x928]
    //         004ada7f     MOV        this,dword ptr [EAX + 0x5c]
    //         004ada82     CALL       RGE_Scenario::Get_scenario_name                  char * Get_scenario_name(RGE_Scenario * this)
    //                              scr_sed.cpp:3591 (9)
    //         004ada87     TEST       EAX,EAX
    //         004ada89     JZ         LAB_004ada90
    //         004ada8b     CMP        byte ptr [EAX],0x0
    //         004ada8e     JNZ        LAB_004adace
    //                               LAB_004ada90                                                 XREF[1]:     004ada89(j)  
    //                              scr_sed.cpp:3594 (40)
    //         004ada90     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004ada96     PUSH       s_Game_File_Number                               = "Game File Number"
    //         004ada9b     PUSH       0x0
    //         004ada9d     MOV        this,dword ptr [ECX + this->_padding_]
    //         004adaa3     CALL       TRegistry::RegGetInt                             int RegGetInt(TRegistry * this, int param_1, 
    //         004adaa8     PUSH       EAX
    //         004adaa9     LEA        EDX=>temp_name[4],[ESP + 0x8]
    //         004adaad     PUSH       s_default%d.scx                                  = "default%d.scx"
    //         004adab2     PUSH       EDX
    //         004adab3     CALL       sprintf                                          undefined sprintf()
    //                              scr_sed.cpp:3595 (22)
    //         004adab8     MOV        this,dword ptr [ESI + 0x928]
    //         004adabe     ADD        ESP,0xc
    //         004adac1     LEA        EAX=>temp_name[4],[ESP + 0x4]
    //         004adac5     MOV        this,dword ptr [ECX + this->_padding_]
    //         004adac8     PUSH       EAX
    //         004adac9     CALL       RGE_Scenario::Set_scenario_name                  void Set_scenario_name(RGE_Scenario * this, c
    //                               LAB_004adace                                                 XREF[1]:     004ada8e(j)  
    //                              scr_sed.cpp:3598 (14)
    //         004adace     MOV        EDX,dword ptr [ESI + 0x928]
    //         004adad4     MOV        this,dword ptr [EDX + 0x5c]
    //         004adad7     CALL       RGE_Scenario::Get_scenario_name                  char * Get_scenario_name(RGE_Scenario * this)
    //                              scr_sed.cpp:3599 (8)
    //         004adadc     POP        ESI
    //         004adadd     ADD        ESP,0x104
    //         004adae3     RET
    //         004adae4     ??         90h
    //         004adae5     NOP
    //         004adae6     NOP
    //         004adae7     NOP
    //         004adae8     NOP
    //         004adae9     NOP
    //         004adaea     NOP
    //         004adaeb     NOP
    //         004adaec     NOP
    //         004adaed     NOP
    //         004adaee     NOP
    //         004adaef     NOP
    return 0;
}

void TRIBE_Screen_Sed::command_quick_save() {
    /* TODO: Stub */
    //                              void __thiscall command_quick_save(TRIBE_Screen_Sed * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //                               ?command_quick_save@TRIBE_Screen_Sed@@QAEXXZ                 XREF[2]:     action:00440656(c), 
    //                               TRIBE_Screen_Sed::command_quick_save                                      action:0044070b(c)  
    //                              scr_sed.cpp:3605 (3)
    //         004adaf0     PUSH       ESI
    //         004adaf1     MOV        ESI,this
    //                              scr_sed.cpp:3606 (5)
    //         004adaf3     CALL       TRIBE_Screen_Sed::scenario_get_default_name      char * scenario_get_default_name(TRIBE_Screen
    //                              scr_sed.cpp:3608 (11)
    //         004adaf8     PUSH       0x0
    //         004adafa     PUSH       0x0
    //         004adafc     MOV        this,ESI
    //         004adafe     CALL       TRIBE_Screen_Sed::command_save                   void command_save(TRIBE_Screen_Sed * this, uc
    //                              scr_sed.cpp:3609 (2)
    //         004adb03     POP        ESI
    //         004adb04     RET
    //         004adb05     ??         90h
    //         004adb06     NOP
    //         004adb07     NOP
    //         004adb08     NOP
    //         004adb09     NOP
    //         004adb0a     NOP
    //         004adb0b     NOP
    //         004adb0c     NOP
    //         004adb0d     NOP
    //         004adb0e     NOP
    //         004adb0f     NOP
    return;
}

char* TRIBE_Screen_Sed::scenario_save_defaulted() {
    /* TODO: Stub */
    //                              char * __thiscall scenario_save_defaulted(TRIBE_Screen_Sed * this)
    //              char *            EAX:4          <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //                               ?scenario_save_defaulted@TRIBE_Screen_Sed@@QAEPADXZ          XREF[1]:     action:0044057d(c)  
    //                               TRIBE_Screen_Sed::scenario_save_defaulted
    //                              scr_sed.cpp:3615 (3)
    //         004adb10     PUSH       ESI
    //         004adb11     MOV        ESI,this
    //                              scr_sed.cpp:3618 (7)
    //         004adb13     PUSH       0xb
    //         004adb15     CALL       TRIBE_Screen_Sed::set_scenario_mode              void set_scenario_mode(TRIBE_Screen_Sed * thi
    //                              scr_sed.cpp:3619 (16)
    //         004adb1a     MOV        EAX,dword ptr [ESI + 0x928]
    //         004adb20     PUSH       0x1
    //         004adb22     MOV        this,dword ptr [EAX + 0x5c]
    //         004adb25     CALL       T_Scenario::Save_victory_conditions_into_players void Save_victory_conditions_into_players(T_S
    //                              scr_sed.cpp:3621 (19)
    //         004adb2a     MOV        this,dword ptr [ESI + 0x928]
    //         004adb30     MOV        this,dword ptr [ECX + this->_padding_]
    //         004adb33     CALL       RGE_Scenario::active_player_count                int active_player_count(RGE_Scenario * this)
    //         004adb38     CMP        EAX,0x1
    //         004adb3b     JGE        LAB_004adb56
    //                              scr_sed.cpp:3623 (21)
    //         004adb3d     PUSH       0x64
    //         004adb3f     PUSH       0x1c2
    //         004adb44     PUSH       0x0
    //                              language.dll match for 0x2742: "You need to make at least one
    //         004adb46     PUSH       0x2742
    //         004adb4b     MOV        this,ESI
    //         004adb4d     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
    //                              scr_sed.cpp:3624 (2)
    //         004adb52     XOR        EAX,EAX
    //                              scr_sed.cpp:3648 (2)
    //         004adb54     POP        ESI
    //         004adb55     RET
    //                               LAB_004adb56                                                 XREF[1]:     004adb3b(j)  
    //                              scr_sed.cpp:3627 (19)
    //         004adb56     MOV        EDX,dword ptr [ESI + 0x928]
    //         004adb5c     MOV        this,dword ptr [EDX + 0x5c]
    //         004adb5f     CALL       RGE_Scenario::any_player_count                   int any_player_count(RGE_Scenario * this)
    //         004adb64     CMP        EAX,0x1
    //         004adb67     JGE        LAB_004adb82
    //                              scr_sed.cpp:3629 (21)
    //         004adb69     PUSH       0x64
    //         004adb6b     PUSH       0x1c2
    //         004adb70     PUSH       0x0
    //                              language.dll match for 0x2743: "One or more civilizations mus
    //         004adb72     PUSH       0x2743
    //         004adb77     MOV        this,ESI
    //         004adb79     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
    //                              scr_sed.cpp:3630 (2)
    //         004adb7e     XOR        EAX,EAX
    //                              scr_sed.cpp:3648 (2)
    //         004adb80     POP        ESI
    //         004adb81     RET
    //                               LAB_004adb82                                                 XREF[1]:     004adb67(j)  
    //                              scr_sed.cpp:3635 (20)
    //         004adb82     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004adb88     PUSH       -0x1
    //         004adb8a     PUSH       0x0
    //                              language.dll match for 0x450: "Saving scenario..."
    //         004adb8c     PUSH       0x450
    //         004adb91     CALL       TRIBE_Game::show_status_message                  void show_status_message(TRIBE_Game * this, i
    //                              scr_sed.cpp:3637 (39)
    //         004adb96     MOV        EAX,[rge_base_game]                              = 00000000
    //         004adb9b     PUSH       s_Game_File_Number                               = "Game File Number"
    //         004adba0     PUSH       0x0
    //         004adba2     MOV        this,dword ptr [EAX + 0x1ac]
    //         004adba8     CALL       TRegistry::RegGetInt                             int RegGetInt(TRegistry * this, int param_1, 
    //         004adbad     PUSH       EAX
    //         004adbae     PUSH       s_default%d.scx                                  = "default%d.scx"
    //         004adbb3     PUSH       null_0086bad8                                    = align(260)
    //         004adbb8     CALL       sprintf                                          undefined sprintf()
    //                              scr_sed.cpp:3638 (26)
    //         004adbbd     MOV        this,dword ptr [ESI + 0x928]
    //         004adbc3     ADD        ESP,0xc
    //         004adbc6     MOV        EDX,dword ptr [this->_padding_]
    //         004adbc8     PUSH       null_0086bad8                                    = align(260)
    //         004adbcd     CALL       dword ptr [EDX + 0xe4]
    //         004adbd3     TEST       AL,AL
    //         004adbd5     JNZ        LAB_004adbfb
    //                              scr_sed.cpp:3640 (11)
    //         004adbd7     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004adbdd     CALL       TRIBE_Game::close_status_message                 void close_status_message(TRIBE_Game * this)
    //                              scr_sed.cpp:3641 (21)
    //         004adbe2     PUSH       0x64
    //         004adbe4     PUSH       offset DAT_fffffff8
    //         004adbe9     PUSH       0x0=>DAT_fffffff4
    //                              language.dll match for 0x963: "The scenario could not be save
    //         004adbeb     PUSH       offset DAT_fffffff0
    //         004adbf0     MOV        this,ESI
    //         004adbf2     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
    //                              scr_sed.cpp:3642 (2)
    //         004adbf7     XOR        EAX,EAX
    //                              scr_sed.cpp:3648 (2)
    //         004adbf9     POP        ESI
    //         004adbfa     RET
    //                               LAB_004adbfb                                                 XREF[1]:     004adbd5(j)  
    //                              scr_sed.cpp:3645 (42)
    //         004adbfb     MOV        EAX,[rge_base_game]                              = 00000000
    //         004adc00     PUSH       s_Game_File_Number                               = "Game File Number"
    //         004adc05     PUSH       0x0=>DAT_fffffff8
    //         004adc07     MOV        this,dword ptr [EAX + 0x1ac]
    //         004adc0d     CALL       TRegistry::RegGetInt                             int RegGetInt(TRegistry * this, int param_1, 
    //         004adc12     PUSH       EAX
    //         004adc13     PUSH       s_default%d                                      = "default%d"
    //         004adc18     PUSH       null_0086bad8                                    = align(260)
    //         004adc1d     CALL       sprintf                                          undefined sprintf()
    //         004adc22     ADD        ESP,0xc
    //                              scr_sed.cpp:3647 (5)
    //         004adc25     MOV        EAX,null_0086bad8                                = align(260)
    //                              scr_sed.cpp:3648 (2)
    //         004adc2a     POP        ESI
    //         004adc2b     RET
    //         004adc2c     ??         90h
    //         004adc2d     NOP
    //         004adc2e     NOP
    //         004adc2f     NOP
    return 0;
}

uchar TRIBE_Screen_Sed::need_to_save() {
    /* TODO: Stub */
    //                              uchar __thiscall need_to_save(TRIBE_Screen_Sed * this)
    //              uchar             AL:1           <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //                               ?need_to_save@TRIBE_Screen_Sed@@QAEEXZ                       XREF[3]:     command_new:004ad303(c), 
    //                               TRIBE_Screen_Sed::need_to_save                                            command_open:004ad5a9(c), 
    //                                                                                                         command_quit:004ad6a3(c)  
    //                              scr_sed.cpp:3654 (6)
    //         004adc30     MOV        AL,byte ptr [ECX + this->need_to_save_flag]
    //                              scr_sed.cpp:3656 (1)
    //         004adc36     RET
    //         004adc37     ??         90h
    //         004adc38     NOP
    //         004adc39     NOP
    //         004adc3a     NOP
    //         004adc3b     NOP
    //         004adc3c     NOP
    //         004adc3d     NOP
    //         004adc3e     NOP
    //         004adc3f     NOP
    return 0;
}

void TRIBE_Screen_Sed::set_focus(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall set_focus(TRIBE_Screen_Sed * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004adc40(R)  
    //                               ?set_focus@TRIBE_Screen_Sed@@MAEXH@Z                         XREF[1]:     00573a80(*)  
    //                               TRIBE_Screen_Sed::set_focus
    //                              scr_sed.cpp:3664 (13)
    //         004adc40     MOV        EAX,dword ptr [ESP + param_1]
    //         004adc44     PUSH       ESI
    //         004adc45     MOV        ESI,this
    //         004adc47     PUSH       EAX
    //         004adc48     CALL       TScreenPanel::set_focus                          void set_focus(TScreenPanel * this, int param
    //                              scr_sed.cpp:3666 (7)
    //         004adc4d     MOV        EAX,dword ptr [ESI + 0x78]
    //         004adc50     TEST       EAX,EAX
    //         004adc52     JZ         LAB_004adc65
    //                              scr_sed.cpp:3669 (13)
    //         004adc54     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004adc5a     PUSH       0x0
    //         004adc5c     CALL       RGE_Base_Game::set_windows_mouse                 void set_windows_mouse(RGE_Base_Game * this, 
    //                              scr_sed.cpp:3670 (4)
    //         004adc61     POP        ESI
    //         004adc62     RET        0x4
    //                               LAB_004adc65                                                 XREF[1]:     004adc52(j)  
    //                              scr_sed.cpp:3669 (13)
    //         004adc65     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004adc6b     PUSH       0x1
    //         004adc6d     CALL       RGE_Base_Game::set_windows_mouse                 void set_windows_mouse(RGE_Base_Game * this, 
    //                              scr_sed.cpp:3670 (4)
    //         004adc72     POP        ESI
    //         004adc73     RET        0x4
    //         004adc76     ??         90h
    //         004adc77     NOP
    //         004adc78     NOP
    //         004adc79     NOP
    //         004adc7a     NOP
    //         004adc7b     NOP
    //         004adc7c     NOP
    //         004adc7d     NOP
    //         004adc7e     NOP
    //         004adc7f     NOP
    return;
}

int TRIBE_Screen_Sed::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, int param_4) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int TRIBE_Screen_Sed::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, char* param_5, char* param_6) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int TRIBE_Screen_Sed::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int TRIBE_Screen_Sed::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, int param_6, int param_7) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int TRIBE_Screen_Sed::create_list(TPanel* param_1, TListPanel** param_2, TScrollBarPanel** param_3) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

void TRIBE_Screen_Sed::set_mp_victory_type(VictoryType param_1, int param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

long TRIBE_Screen_Sed::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int TRIBE_Screen_Sed::MakeFileList(TDropDownPanel* param_1, char* param_2, char* param_3, uchar param_4, uchar param_5) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int TRIBE_Screen_Sed::create_radio_button(TPanel* param_1, TButtonPanel** param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

