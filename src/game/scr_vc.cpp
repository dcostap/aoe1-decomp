#include "../common.h"
#include "scr_vc.h"

TRIBE_Mission_Screen::TRIBE_Mission_Screen(char* param_1, uchar param_2, TPicture* param_3) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Mission_Screen(TRIBE_Mission_Screen * thi
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Mission_    ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     004b82b6(R)
//              uchar             Stack[0x8]:1   param_2                   XREF[1]:     004b812f(R)
//              TPicture *        Stack[0xc]:4   param_3
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004b813e(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004b878e(R)
//              char[260]         Stack[-0x114   info_file                 XREF[0,2]:   004b8194(*), 004b81c3(*)
//              char[260]         Stack[-0x218   adjusted_name             XREF[1,4]:   004b8126(W), 004b8226(*), 004b8253(*), 004b8273(*),
//                                                                                     004b82a0(*)
//              undefined4        Stack[-0x21c   local_21c                 XREF[2]:     004b8230(W), 004b8238(R)
//              undefined1        Stack[-0x21d   local_21d                 XREF[1]:     004b8145(W)
//              uchar             Stack[-0x221   starting_description
//                               ??0TRIBE_Mission_Screen@@QAE@PADEPAVTPicture@@@Z             XREF[2]:     action:0043fb40(c),
//                               TRIBE_Mission_Screen::TRIBE_Mission_Screen                                stop_video:00523d2e(c)
//                              scr_vc.cpp:45 (47)
//         004b8100     PUSH       -0x1
//         004b8102     PUSH       FUN_0055f85b
//         004b8107     MOV        EAX,FS:[0x0]
//         004b810d     PUSH       EAX
//         004b810e     MOV        dword ptr FS:[0x0],ESP
//         004b8115     SUB        ESP,0x214
//         004b811b     PUSH       EBX
//         004b811c     PUSH       EBP
//         004b811d     PUSH       ESI
//         004b811e     PUSH       EDI
//         004b811f     MOV        EBP,this
//         004b8121     PUSH       s_Mission_Dialog                                 = "Mission Dialog"
//         004b8126     MOV        dword ptr [ESP + adjusted_name[0]],EBP
//         004b812a     CALL       TScreenPanel::TScreenPanel                       undefined TScreenPanel(TScreenPanel * this, c
//                              scr_vc.cpp:51 (26)
//         004b812f     MOV        this,byte ptr [ESP + param_2]
//         004b8136     XOR        EAX,EAX
//         004b8138     LEA        EBX,[EBP + 0x488]
//         004b813e     MOV        dword ptr [ESP + local_4],EAX
//         004b8145     MOV        byte ptr [ESP + local_21d],AL
//                              scr_vc.cpp:54 (6)
//         004b8149     MOV        dword ptr [EBP + 0x478],EAX
//                              scr_vc.cpp:55 (6)
//         004b814f     MOV        dword ptr [EBP + 0x484],EAX
//                              scr_vc.cpp:56 (6)
//         004b8155     MOV        dword ptr [EBP + 0x47c],EAX
//                              scr_vc.cpp:57 (6)
//         004b815b     MOV        dword ptr [EBP + 0x480],EAX
//                              scr_vc.cpp:58 (6)
//         004b8161     MOV        dword ptr [EBP + 0x498],EAX
//                              scr_vc.cpp:62 (19)
//         004b8167     MOV        EAX,EBX
//         004b8169     XOR        EDX,EDX
//         004b816b     MOV        dword ptr [EBP],TRIBE_Mission_Screen::`vftable'  = 004b87b0
//         004b8172     MOV        byte ptr [EBP + 0x494],this
//         004b8178     MOV        dword ptr [EAX],EDX
//                              scr_vc.cpp:67 (16)
//         004b817a     MOV        this,panel_system
//         004b817f     MOV        dword ptr [EAX + 0x4],EDX
//         004b8182     MOV        dword ptr [EAX + 0x8],EDX
//         004b8185     CALL       TPanelSystem::currentPanel                       TPanel * currentPanel(TPanelSystem * this)
//                              scr_vc.cpp:71 (23)
//         004b818a     MOV        EDI,s_scr9                                       = 73h    s
//         004b818f     OR         this,0xffffffff
//         004b8192     XOR        EAX,EAX
//         004b8194     LEA        EDX=>info_file[4],[ESP + 0x120]
//         004b819b     SCASB.RE   ES:EDI=>s_scr9                                   = 73h    s
//                                                                                  = 63h
//         004b819d     NOT        this
//         004b819f     SUB        EDI,this
//                              scr_vc.cpp:74 (54)
//         004b81a1     PUSH       0x1
//         004b81a3     MOV        EAX,this
//         004b81a5     MOV        ESI,EDI
//         004b81a7     MOV        EDI,EDX
//         004b81a9     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         004b81af     SHR        this,0x2
//         004b81b2     MOVSD.REP  ES:EDI,ESI
//         004b81b4     MOV        this,EAX
//         004b81b6     PUSH       0xc38c
//         004b81bb     AND        this,0x3
//         004b81be     MOVSB.REP  ES:EDI,ESI
//         004b81c0     MOV        EAX,dword ptr [EDX + 0x4c]
//         004b81c3     LEA        this=>info_file[4],[ESP + 0x128]
//         004b81ca     PUSH       this
//         004b81cb     PUSH       EAX
//         004b81cc     MOV        this,EBP
//         004b81ce     CALL       TScreenPanel::setup                              long setup(TScreenPanel * this, TDrawArea * p
//         004b81d3     TEST       EAX,EAX
//         004b81d5     JNZ        LAB_004b81e6
//                              scr_vc.cpp:76 (10)
//         004b81d7     MOV        dword ptr [EBP + 0xd8],0x1
//                              scr_vc.cpp:77 (5)
//         004b81e1     JMP        LAB_004b878e
//                               LAB_004b81e6                                                 XREF[1]:     004b81d5(j)
//                              scr_vc.cpp:80 (9)
//         004b81e6     PUSH       0x0
//         004b81e8     MOV        this,EBP
//         004b81ea     CALL       TEasy_Panel::setup_shadow_area                   void setup_shadow_area(TEasy_Panel * this, in
//                              scr_vc.cpp:81 (17)
//         004b81ef     PUSH       0x1e0
//         004b81f4     PUSH       0x280
//         004b81f9     MOV        this,EBP
//         004b81fb     CALL       TEasy_Panel::set_ideal_size                      void set_ideal_size(TEasy_Panel * this, long
//                              scr_vc.cpp:85 (22)
//         004b8200     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004b8206     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004b820c     MOV        this,dword ptr [EDX + 0x5c]
//         004b820f     CALL       RGE_Scenario::Get_scenario_name                  char * Get_scenario_name(RGE_Scenario * this)
//         004b8214     MOV        EDX,EAX
//                              scr_vc.cpp:86 (9)
//         004b8216     TEST       EDX,EDX
//         004b8218     JZ         LAB_004b8260
//         004b821a     CMP        byte ptr [EDX],0x0
//         004b821d     JZ         LAB_004b8260
//                              scr_vc.cpp:93 (36)
//         004b821f     MOV        EDI,EDX
//         004b8221     OR         this,0xffffffff
//         004b8224     XOR        EAX,EAX
//         004b8226     LEA        ESI=>adjusted_name[4],[ESP + 0x1c]
//         004b822a     SCASB.RE   ES:EDI
//         004b822c     NOT        this
//         004b822e     SUB        EDI,this
//         004b8230     MOV        dword ptr [ESP + local_21c],ESI
//         004b8234     MOV        EAX,this
//         004b8236     MOV        ESI,EDI
//         004b8238     MOV        EDI,dword ptr [ESP + local_21c]
//         004b823c     SHR        this,0x2
//         004b823f     MOVSD.REP  ES:EDI,ESI
//         004b8241     MOV        this,EAX
//                              scr_vc.cpp:94 (29)
//         004b8243     XOR        EAX,EAX
//         004b8245     AND        this,0x3
//         004b8248     MOVSB.REP  ES:EDI,ESI
//         004b824a     MOV        EDI,EDX
//         004b824c     OR         this,0xffffffff
//         004b824f     SCASB.RE   ES:EDI
//         004b8251     NOT        this
//         004b8253     LEA        EDX=>adjusted_name[4],[ESP + 0x1c]
//         004b8257     DEC        this
//         004b8258     SUB        EDX,0x4
//         004b825b     MOV        byte ptr [this->_padding_ + EDX*0x1],AL
//         004b825e     JMP        LAB_004b828f
//                              language.dll match for 0x2655: "Instructions"
//                               LAB_004b8260                                                 XREF[2]:     004b8218(j), 004b821d(j)
//                              scr_vc.cpp:88 (12)
//         004b8260     PUSH       0x2655
//         004b8265     MOV        this,EBP
//         004b8267     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//                              scr_vc.cpp:89 (35)
//         004b826c     MOV        EDI,EAX
//         004b826e     OR         this,0xffffffff
//         004b8271     XOR        EAX,EAX
//         004b8273     LEA        EDX=>adjusted_name[4],[ESP + 0x1c]
//         004b8277     SCASB.RE   ES:EDI
//         004b8279     NOT        this
//         004b827b     SUB        EDI,this
//         004b827d     MOV        EAX,this
//         004b827f     MOV        ESI,EDI
//         004b8281     MOV        EDI,EDX
//         004b8283     SHR        this,0x2
//         004b8286     MOVSD.REP  ES:EDI,ESI
//         004b8288     MOV        this,EAX
//         004b828a     AND        this,0x3
//         004b828d     MOVSB.REP  ES:EDI,ESI
//                               LAB_004b828f                                                 XREF[1]:     004b825e(j)
//                              scr_vc.cpp:96 (39)
//         004b828f     PUSH       0x0
//         004b8291     PUSH       0x1
//         004b8293     PUSH       0x1
//         004b8295     PUSH       0x4
//         004b8297     PUSH       0x14
//         004b8299     PUSH       0x26c
//         004b829e     PUSH       0xf
//         004b82a0     LEA        this=>adjusted_name[4],[ESP + 0x38]
//         004b82a4     PUSH       0xa
//         004b82a6     LEA        EAX,[EBP + 0x478]
//         004b82ac     PUSH       this
//         004b82ad     PUSH       EAX
//         004b82ae     PUSH       EBP
//         004b82af     MOV        this,EBP
//         004b82b1     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//                              scr_vc.cpp:99 (45)
//         004b82b6     MOV        EDX,dword ptr [ESP + param_1]
//         004b82bd     PUSH       0x1
//         004b82bf     PUSH       0x0
//         004b82c1     PUSH       0x0
//         004b82c3     PUSH       0xb
//         004b82c5     PUSH       0x154
//         004b82ca     PUSH       0x12c
//         004b82cf     PUSH       0x46
//         004b82d1     PUSH       0xf
//         004b82d3     LEA        ESI,[EBP + 0x47c]
//         004b82d9     PUSH       EDX
//         004b82da     PUSH       ESI
//         004b82db     PUSH       EBP
//         004b82dc     MOV        this,EBP
//         004b82de     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//                              scr_vc.cpp:100 (19)
//         004b82e3     MOV        EAX,dword ptr [ESI]
//         004b82e5     PUSH       0x14
//         004b82e7     PUSH       EAX
//         004b82e8     LEA        EAX,[EBP + 0x480]
//         004b82ee     PUSH       EAX
//         004b82ef     MOV        this,EBP
//         004b82f1     CALL       TEasy_Panel::create_auto_scrollbar               int create_auto_scrollbar(TEasy_Panel * this,
//                              scr_vc.cpp:102 (10)
//         004b82f6     MOV        EAX,dword ptr [EBP + 0x31c]
//         004b82fc     TEST       EAX,EAX
//         004b82fe     JZ         LAB_004b8342
//                              scr_vc.cpp:103 (66)
//         004b8300     XOR        EAX,EAX
//         004b8302     MOV        this,dword ptr [ESI]
//         004b8304     MOV        AL,byte ptr [EBP + 0x325]
//         004b830a     PUSH       EAX
//         004b830b     XOR        EAX,EAX
//         004b830d     MOV        AL,byte ptr [EBP + 0x324]
//         004b8313     MOV        EDX,dword ptr [this->_padding_]
//         004b8315     PUSH       EAX
//         004b8316     XOR        EAX,EAX
//         004b8318     MOV        AL,byte ptr [EBP + 0x323]
//         004b831e     PUSH       EAX
//         004b831f     XOR        EAX,EAX
//         004b8321     MOV        AL,byte ptr [EBP + 0x322]
//         004b8327     PUSH       EAX
//         004b8328     XOR        EAX,EAX
//         004b832a     MOV        AL,byte ptr [EBP + 0x321]
//         004b8330     PUSH       EAX
//         004b8331     XOR        EAX,EAX
//         004b8333     MOV        AL,byte ptr [EBP + 0x320]
//         004b8339     PUSH       EAX
//         004b833a     PUSH       0x3
//         004b833c     CALL       dword ptr [EDX + 0xec]
//                               LAB_004b8342                                                 XREF[1]:     004b82fe(j)
//                              scr_vc.cpp:106 (45)
//         004b8342     PUSH       0x0
//         004b8344     PUSH       0x0
//         004b8346     PUSH       0x0
//         004b8348     PUSH       0x1e
//         004b834a     PUSH       0xf0
//         004b834f     PUSH       0x1b8
//         004b8354     PUSH       0xc8
//         004b8359     PUSH       0x0
//         004b835b     LEA        EAX,[EBP + 0x484]
//                              language.dll match for 0xfa1: "OK"
//         004b8361     PUSH       0xfa1
//         004b8366     PUSH       EAX
//         004b8367     PUSH       EBP
//         004b8368     MOV        this,EBP
//         004b836a     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//                              scr_vc.cpp:108 (39)
//         004b836f     PUSH       0x0
//         004b8371     PUSH       -0x1
//         004b8373     PUSH       0x0
//         004b8375     PUSH       0x1e
//         004b8377     PUSH       0xb4
//         004b837c     PUSH       0x13c
//         004b8381     PUSH       0x145
//         004b8386     PUSH       0x0
//                              language.dll match for 0x2a31: "History"
//         004b8388     PUSH       0x2a31
//         004b838d     PUSH       EBX
//         004b838e     PUSH       EBP
//         004b838f     MOV        this,EBP
//         004b8391     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//                              scr_vc.cpp:109 (45)
//         004b8396     PUSH       0x0
//         004b8398     PUSH       -0x1
//         004b839a     PUSH       0x0
//         004b839c     PUSH       0x1e
//         004b839e     PUSH       0xb4
//         004b83a3     PUSH       0x15c
//         004b83a8     PUSH       0x145
//         004b83ad     LEA        ESI,[EBP + 0x48c]
//         004b83b3     PUSH       0x0
//                              language.dll match for 0x2a32: "Instructions"
//         004b83b5     PUSH       0x2a32
//         004b83ba     PUSH       ESI
//         004b83bb     PUSH       EBP
//         004b83bc     MOV        this,EBP
//         004b83be     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//                              scr_vc.cpp:110 (55)
//         004b83c3     PUSH       0x0
//         004b83c5     PUSH       -0x1
//         004b83c7     PUSH       0x0
//         004b83c9     PUSH       0x1e
//         004b83cb     PUSH       0xb4
//         004b83d0     PUSH       0x17c
//         004b83d5     PUSH       0x145
//         004b83da     LEA        EAX,[EBP + 0x490]
//         004b83e0     PUSH       0x0
//                              language.dll match for 0x2a37: "Hints"
//         004b83e2     PUSH       0x2a37
//         004b83e7     PUSH       EAX
//         004b83e8     PUSH       EBP
//         004b83e9     MOV        this,EBP
//         004b83eb     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//         004b83f0     MOV        EDI,EBX
//         004b83f2     MOV        dword ptr [ESP + 0x14],0x3
//                               LAB_004b83fa                                                 XREF[1]:     004b8410(j)
//                              scr_vc.cpp:113 (24)
//         004b83fa     MOV        this,dword ptr [EDI]
//         004b83fc     PUSH       0x3
//         004b83fe     PUSH       EBX
//         004b83ff     CALL       TButtonPanel::set_radio_info                     void set_radio_info(TButtonPanel * this, TBut
//         004b8404     MOV        EAX,dword ptr [ESP + 0x14]
//         004b8408     ADD        EDI,0x4
//         004b840b     DEC        EAX
//         004b840c     MOV        dword ptr [ESP + 0x14],EAX
//         004b8410     JNZ        LAB_004b83fa
//                              scr_vc.cpp:115 (14)
//         004b8412     MOV        EAX,dword ptr [EBP + 0x14]
//         004b8415     CMP        EAX,0x280
//         004b841a     JG         LAB_004b84b3
//                              scr_vc.cpp:117 (22)
//         004b8420     MOV        this,dword ptr [EBP + 0x478]
//         004b8426     PUSH       0x14
//         004b8428     PUSH       0x27a
//         004b842d     PUSH       0xf
//         004b842f     MOV        EDX,dword ptr [this->_padding_]
//         004b8431     PUSH       0x3
//         004b8433     CALL       dword ptr [EDX + 0x1c]
//                              scr_vc.cpp:118 (22)
//         004b8436     MOV        this,dword ptr [EBP + 0x47c]
//                              language.dll match for 0x73: "B"
//         004b843c     PUSH       0x73
//         004b843e     PUSH       0x258
//         004b8443     PUSH       0x32
//         004b8445     MOV        EAX,dword ptr [this->_padding_]
//         004b8447     PUSH       0x14
//         004b8449     CALL       dword ptr [EAX + 0x1c]
//                              scr_vc.cpp:119 (21)
//         004b844c     MOV        this,dword ptr [EBX]
//         004b844e     PUSH       0x1e
//         004b8450     PUSH       0x96
//         004b8455     PUSH       0x1bd
//         004b845a     MOV        EDX,dword ptr [this->_padding_]
//         004b845c     PUSH       0x5
//         004b845e     CALL       dword ptr [EDX + 0x1c]
//                              scr_vc.cpp:120 (24)
//         004b8461     MOV        this,dword ptr [ESI]
//         004b8463     PUSH       0x1e
//         004b8465     PUSH       0x96
//         004b846a     PUSH       0x1bd
//         004b846f     MOV        EAX,dword ptr [this->_padding_]
//         004b8471     PUSH       0xa5
//         004b8476     CALL       dword ptr [EAX + 0x1c]
//                              scr_vc.cpp:121 (28)
//         004b8479     MOV        this,dword ptr [EBP + 0x490]
//         004b847f     PUSH       0x1e
//         004b8481     PUSH       0x96
//         004b8486     PUSH       0x1bd
//         004b848b     MOV        EDX,dword ptr [this->_padding_]
//         004b848d     PUSH       0x145
//         004b8492     CALL       dword ptr [EDX + 0x1c]
//                              scr_vc.cpp:122 (25)
//         004b8495     MOV        this,dword ptr [EBP + 0x484]
//         004b849b     PUSH       0x1e
//         004b849d     PUSH       0x96
//         004b84a2     PUSH       0x1bd
//         004b84a7     MOV        EAX,dword ptr [this->_padding_]
//         004b84a9     PUSH       0x1e5
//                              scr_vc.cpp:124 (16)
//         004b84ae     JMP        LAB_004b8607
//                               LAB_004b84b3                                                 XREF[1]:     004b841a(j)
//         004b84b3     CMP        EAX,0x320
//         004b84b8     JG         LAB_004b8565
//                              scr_vc.cpp:126 (17)
//         004b84be     PUSH       0x280
//         004b84c3     PUSH       0x320
//         004b84c8     MOV        this,EBP
//         004b84ca     CALL       TEasy_Panel::set_ideal_size                      void set_ideal_size(TEasy_Panel * this, long
//                              scr_vc.cpp:127 (22)
//         004b84cf     MOV        this,dword ptr [EBP + 0x478]
//         004b84d5     PUSH       0x14
//         004b84d7     PUSH       0x31a
//         004b84dc     PUSH       0xf
//         004b84de     MOV        EDX,dword ptr [this->_padding_]
//         004b84e0     PUSH       0x3
//         004b84e2     CALL       dword ptr [EDX + 0x1c]
//                              scr_vc.cpp:128 (25)
//         004b84e5     MOV        this,dword ptr [EBP + 0x47c]
//         004b84eb     PUSH       0xe6
//         004b84f0     PUSH       0x2e4
//         004b84f5     PUSH       0x2d
//         004b84f7     MOV        EAX,dword ptr [this->_padding_]
//         004b84f9     PUSH       0x1e
//         004b84fb     CALL       dword ptr [EAX + 0x1c]
//                              scr_vc.cpp:129 (21)
//         004b84fe     MOV        this,dword ptr [EBX]
//         004b8500     PUSH       0x1e
//         004b8502     PUSH       0xbe
//         004b8507     PUSH       0x235
//         004b850c     MOV        EDX,dword ptr [this->_padding_]
//         004b850e     PUSH       0x5
//         004b8510     CALL       dword ptr [EDX + 0x1c]
//                              scr_vc.cpp:130 (24)
//         004b8513     MOV        this,dword ptr [ESI]
//         004b8515     PUSH       0x1e
//         004b8517     PUSH       0xbe
//         004b851c     PUSH       0x235
//         004b8521     MOV        EAX,dword ptr [this->_padding_]
//         004b8523     PUSH       0xcd
//         004b8528     CALL       dword ptr [EAX + 0x1c]
//                              scr_vc.cpp:131 (28)
//         004b852b     MOV        this,dword ptr [EBP + 0x490]
//         004b8531     PUSH       0x1e
//         004b8533     PUSH       0xbe
//         004b8538     PUSH       0x235
//         004b853d     MOV        EDX,dword ptr [this->_padding_]
//         004b853f     PUSH       0x195
//         004b8544     CALL       dword ptr [EDX + 0x1c]
//                              scr_vc.cpp:132 (25)
//         004b8547     MOV        this,dword ptr [EBP + 0x484]
//         004b854d     PUSH       0x1e
//         004b854f     PUSH       0xbe
//         004b8554     PUSH       0x235
//         004b8559     MOV        EAX,dword ptr [this->_padding_]
//         004b855b     PUSH       0x25d
//                              scr_vc.cpp:134 (5)
//         004b8560     JMP        LAB_004b8607
//                               LAB_004b8565                                                 XREF[1]:     004b84b8(j)
//                              scr_vc.cpp:136 (17)
//         004b8565     PUSH       0x300
//         004b856a     PUSH       0x400
//         004b856f     MOV        this,EBP
//         004b8571     CALL       TEasy_Panel::set_ideal_size                      void set_ideal_size(TEasy_Panel * this, long
//                              scr_vc.cpp:137 (22)
//         004b8576     MOV        this,dword ptr [EBP + 0x478]
//         004b857c     PUSH       0x14
//         004b857e     PUSH       0x3fa
//         004b8583     PUSH       0xf
//         004b8585     MOV        EDX,dword ptr [this->_padding_]
//         004b8587     PUSH       0x3
//         004b8589     CALL       dword ptr [EDX + 0x1c]
//                              scr_vc.cpp:138 (25)
//         004b858c     MOV        this,dword ptr [EBP + 0x47c]
//         004b8592     PUSH       0x136
//         004b8597     PUSH       0x3b0
//         004b859c     PUSH       0x41
//         004b859e     MOV        EAX,dword ptr [this->_padding_]
//         004b85a0     PUSH       0x28
//         004b85a2     CALL       dword ptr [EAX + 0x1c]
//                              scr_vc.cpp:139 (21)
//         004b85a5     MOV        this,dword ptr [EBX]
//         004b85a7     PUSH       0x32
//         004b85a9     PUSH       0xf0
//         004b85ae     PUSH       0x2b2
//         004b85b3     MOV        EDX,dword ptr [this->_padding_]
//         004b85b5     PUSH       0xa
//         004b85b7     CALL       dword ptr [EDX + 0x1c]
//                              scr_vc.cpp:140 (24)
//         004b85ba     MOV        this,dword ptr [ESI]
//         004b85bc     PUSH       0x32
//         004b85be     PUSH       0xf0
//         004b85c3     PUSH       0x2b2
//         004b85c8     MOV        EAX,dword ptr [this->_padding_]
//         004b85ca     PUSH       0x10a
//         004b85cf     CALL       dword ptr [EAX + 0x1c]
//                              scr_vc.cpp:141 (28)
//         004b85d2     MOV        this,dword ptr [EBP + 0x490]
//         004b85d8     PUSH       0x32
//         004b85da     PUSH       0xf0
//         004b85df     PUSH       0x2b2
//         004b85e4     MOV        EDX,dword ptr [this->_padding_]
//         004b85e6     PUSH       0x20a
//         004b85eb     CALL       dword ptr [EDX + 0x1c]
//                              scr_vc.cpp:142 (28)
//         004b85ee     MOV        this,dword ptr [EBP + 0x484]
//         004b85f4     PUSH       0x32
//         004b85f6     PUSH       0xf0
//         004b85fb     PUSH       0x2b2
//         004b8600     MOV        EAX,dword ptr [this->_padding_]
//         004b8602     PUSH       0x306
//                               LAB_004b8607                                                 XREF[2]:     004b84ae(j), 004b8560(j)
//         004b8607     CALL       dword ptr [EAX + 0x1c]
//                              scr_vc.cpp:145 (26)
//         004b860a     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004b8610     PUSH       0x0
//         004b8612     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004b8618     MOV        this,dword ptr [EDX + 0x5c]
//         004b861b     CALL       RGE_Scenario::Get_message                        char * Get_message(RGE_Scenario * this, long
//         004b8620     TEST       EAX,EAX
//         004b8622     JZ         LAB_004b865d
//                              scr_vc.cpp:147 (43)
//         004b8624     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004b862a     MOV        EAX,dword ptr [EBP + 0x47c]
//         004b8630     PUSH       0x0
//         004b8632     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004b8638     MOV        EDI,dword ptr [EAX]
//         004b863a     MOV        this,dword ptr [EDX + 0x5c]
//         004b863d     CALL       RGE_Scenario::Get_message                        char * Get_message(RGE_Scenario * this, long
//         004b8642     MOV        this,dword ptr [EBP + 0x47c]
//         004b8648     PUSH       EAX
//         004b8649     CALL       dword ptr [EDI + 0xe8]
//                              scr_vc.cpp:148 (7)
//         004b864f     MOV        this,dword ptr [ESI]
//         004b8651     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
//                              scr_vc.cpp:149 (5)
//         004b8656     MOV        byte ptr [ESP + 0x13],0x1
//                              scr_vc.cpp:151 (2)
//         004b865b     JMP        LAB_004b8666
//                               LAB_004b865d                                                 XREF[1]:     004b8622(j)
//                              scr_vc.cpp:152 (9)
//         004b865d     MOV        this,dword ptr [ESI]
//         004b865f     PUSH       0x0
//         004b8661     MOV        EAX,dword ptr [this->_padding_]
//         004b8663     CALL       dword ptr [EAX + 0x14]
//                               LAB_004b8666                                                 XREF[1]:     004b865b(j)
//                              scr_vc.cpp:154 (26)
//         004b8666     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004b866c     PUSH       0x4
//         004b866e     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004b8674     MOV        this,dword ptr [EDX + 0x5c]
//         004b8677     CALL       RGE_Scenario::Get_message                        char * Get_message(RGE_Scenario * this, long
//         004b867c     TEST       EAX,EAX
//         004b867e     JZ         LAB_004b86c0
//                              scr_vc.cpp:156 (8)
//         004b8680     MOV        AL,byte ptr [ESP + 0x13]
//         004b8684     TEST       AL,AL
//         004b8686     JNZ        LAB_004b86ba
//                              scr_vc.cpp:158 (43)
//         004b8688     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004b868e     MOV        EAX,dword ptr [EBP + 0x47c]
//         004b8694     PUSH       0x4
//         004b8696     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004b869c     MOV        EDI,dword ptr [EAX]
//         004b869e     MOV        this,dword ptr [EDX + 0x5c]
//         004b86a1     CALL       RGE_Scenario::Get_message                        char * Get_message(RGE_Scenario * this, long
//         004b86a6     MOV        this,dword ptr [EBP + 0x47c]
//         004b86ac     PUSH       EAX
//         004b86ad     CALL       dword ptr [EDI + 0xe8]
//                              scr_vc.cpp:159 (7)
//         004b86b3     MOV        this,dword ptr [EBX]
//         004b86b5     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
//                               LAB_004b86ba                                                 XREF[1]:     004b8686(j)
//                              scr_vc.cpp:161 (4)
//         004b86ba     INC        byte ptr [ESP + 0x13]
//                              scr_vc.cpp:163 (2)
//         004b86be     JMP        LAB_004b86c9
//                               LAB_004b86c0                                                 XREF[1]:     004b867e(j)
//                              scr_vc.cpp:164 (9)
//         004b86c0     MOV        this,dword ptr [EBX]
//         004b86c2     PUSH       0x0
//         004b86c4     MOV        EAX,dword ptr [this->_padding_]
//         004b86c6     CALL       dword ptr [EAX + 0x14]
//                               LAB_004b86c9                                                 XREF[1]:     004b86be(j)
//                              scr_vc.cpp:166 (26)
//         004b86c9     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004b86cf     PUSH       0x1
//         004b86d1     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004b86d7     MOV        this,dword ptr [EDX + 0x5c]
//         004b86da     CALL       RGE_Scenario::Get_message                        char * Get_message(RGE_Scenario * this, long
//         004b86df     TEST       EAX,EAX
//         004b86e1     JZ         LAB_004b8727
//                              scr_vc.cpp:168 (8)
//         004b86e3     MOV        AL,byte ptr [ESP + 0x13]
//         004b86e7     TEST       AL,AL
//         004b86e9     JNZ        LAB_004b8721
//                              scr_vc.cpp:170 (43)
//         004b86eb     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004b86f1     MOV        EAX,dword ptr [EBP + 0x47c]
//         004b86f7     PUSH       0x1
//         004b86f9     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004b86ff     MOV        EDI,dword ptr [EAX]
//         004b8701     MOV        this,dword ptr [EDX + 0x5c]
//         004b8704     CALL       RGE_Scenario::Get_message                        char * Get_message(RGE_Scenario * this, long
//         004b8709     MOV        this,dword ptr [EBP + 0x47c]
//         004b870f     PUSH       EAX
//         004b8710     CALL       dword ptr [EDI + 0xe8]
//                              scr_vc.cpp:171 (11)
//         004b8716     MOV        this,dword ptr [EBP + 0x490]
//         004b871c     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
//                               LAB_004b8721                                                 XREF[1]:     004b86e9(j)
//                              scr_vc.cpp:173 (4)
//         004b8721     INC        byte ptr [ESP + 0x13]
//                              scr_vc.cpp:175 (2)
//         004b8725     JMP        LAB_004b8749
//                               LAB_004b8727                                                 XREF[1]:     004b86e1(j)
//                              scr_vc.cpp:177 (13)
//         004b8727     MOV        this,dword ptr [EBP + 0x490]
//         004b872d     PUSH       0x0
//         004b872f     MOV        EAX,dword ptr [this->_padding_]
//         004b8731     CALL       dword ptr [EAX + 0x14]
//                              scr_vc.cpp:178 (8)
//         004b8734     MOV        AL,byte ptr [ESP + 0x13]
//         004b8738     TEST       AL,AL
//         004b873a     JNZ        LAB_004b8749
//                              scr_vc.cpp:179 (13)
//         004b873c     MOV        this,dword ptr [EBP + 0x47c]
//         004b8742     PUSH       0x0
//         004b8744     MOV        EDX,dword ptr [this->_padding_]
//         004b8746     CALL       dword ptr [EDX + 0x14]
//                               LAB_004b8749                                                 XREF[2]:     004b8725(j), 004b873a(j)
//                              scr_vc.cpp:182 (7)
//         004b8749     CMP        byte ptr [ESP + 0x13],0x1
//         004b874e     JNZ        LAB_004b8773
//                              scr_vc.cpp:184 (11)
//         004b8750     MOV        EBX,dword ptr [EBX]
//         004b8752     PUSH       0x0
//         004b8754     MOV        this,EBX
//         004b8756     MOV        EAX,dword ptr [EBX]
//         004b8758     CALL       dword ptr [EAX + 0x14]
//                              scr_vc.cpp:185 (11)
//         004b875b     MOV        ESI,dword ptr [ESI]
//         004b875d     PUSH       0x0
//         004b875f     MOV        this,ESI
//         004b8761     MOV        EDX,dword ptr [ESI]
//         004b8763     CALL       dword ptr [EDX + 0x14]
//                              scr_vc.cpp:186 (13)
//         004b8766     MOV        this,dword ptr [EBP + 0x490]
//         004b876c     PUSH       0x0
//         004b876e     MOV        EAX,dword ptr [this->_padding_]
//         004b8770     CALL       dword ptr [EAX + 0x14]
//                               LAB_004b8773                                                 XREF[1]:     004b874e(j)
//                              scr_vc.cpp:189 (14)
//         004b8773     MOV        this,dword ptr [EBP + 0x484]
//         004b8779     PUSH       this
//         004b877a     MOV        this,EBP
//         004b877c     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                              scr_vc.cpp:193 (13)
//         004b8781     MOV        EDX,dword ptr [ESP + 0x23c]
//         004b8788     MOV        dword ptr [EBP + 0x498],EDX
//                               LAB_004b878e                                                 XREF[1]:     004b81e1(j)
//                              scr_vc.cpp:194 (29)
//         004b878e     MOV        this,dword ptr [ESP + local_c]
//         004b8795     POP        EDI
//         004b8796     MOV        EAX,EBP
//         004b8798     POP        ESI
//         004b8799     POP        EBP
//         004b879a     MOV        dword ptr FS:[0x0],this
//         004b87a1     POP        EBX
//         004b87a2     ADD        ESP,0x220
//         004b87a8     RET        0xc
//         004b87ab     ??         90h
//         004b87ac     NOP
//         004b87ad     NOP
//         004b87ae     NOP
//         004b87af     NOP
}

TRIBE_Mission_Screen::~TRIBE_Mission_Screen() {
    /* TODO: Stub */
//                              void __thiscall ~TRIBE_Mission_Screen(TRIBE_Mission_Screen * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Mission_    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004b87fb(W)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004b87eb(W)
//                               ??1TRIBE_Mission_Screen@@UAE@XZ                              XREF[1]:     `vector_deleting_destructor':004b8
//                               TRIBE_Mission_Screen::~TRIBE_Mission_Screen
//                              scr_vc.cpp:200 (37)
//         004b87d0     PUSH       -0x1
//         004b87d2     PUSH       FUN_0055f878
//         004b87d7     MOV        EAX,FS:[0x0]
//         004b87dd     PUSH       EAX
//         004b87de     MOV        dword ptr FS:[0x0],ESP
//         004b87e5     PUSH       this
//         004b87e6     PUSH       EBX
//         004b87e7     MOV        EBX,this
//         004b87e9     PUSH       ESI
//         004b87ea     PUSH       EDI
//         004b87eb     MOV        dword ptr [ESP + local_10],EBX
//         004b87ef     MOV        dword ptr [EBX],TRIBE_Mission_Screen::`vftable'  = 004b87b0
//                              scr_vc.cpp:203 (43)
//         004b87f5     MOV        AL,byte ptr [EBX + 0x494]
//         004b87fb     MOV        dword ptr [ESP + local_4],0x0
//         004b8803     TEST       AL,AL
//         004b8805     JNZ        LAB_004b8825
//         004b8807     MOV        EAX,[rge_base_game]                              = 00000000
//         004b880c     MOV        this,dword ptr [EAX + 0xc]
//         004b880f     MOV        EDX,dword ptr [this->_padding_ + 0x8a8]
//         004b8815     TEST       EDX,EDX
//         004b8817     JZ         LAB_004b8825
//         004b8819     MOV        this,dword ptr [EAX + 0x60]
//         004b881c     TEST       this,this
//         004b881e     JZ         LAB_004b8825
//                              scr_vc.cpp:204 (5)
//         004b8820     CALL       TSound_Driver::stop_stream                       int stop_stream(TSound_Driver * this)
//                               LAB_004b8825                                                 XREF[3]:     004b8805(j), 004b8817(j),
//                                                                                                         004b881e(j)
//                              scr_vc.cpp:206 (16)
//         004b8825     MOV        this,dword ptr [EBX + 0x478]
//         004b882b     TEST       this,this
//         004b882d     JZ         LAB_004b8835
//         004b882f     MOV        EDX,dword ptr [this->_padding_]
//         004b8831     PUSH       0x1
//         004b8833     CALL       dword ptr [EDX]
//                               LAB_004b8835                                                 XREF[1]:     004b882d(j)
//                              scr_vc.cpp:207 (16)
//         004b8835     MOV        this,dword ptr [EBX + 0x47c]
//         004b883b     TEST       this,this
//         004b883d     JZ         LAB_004b8845
//         004b883f     MOV        EAX,dword ptr [this->_padding_]
//         004b8841     PUSH       0x1
//         004b8843     CALL       dword ptr [EAX]
//                               LAB_004b8845                                                 XREF[1]:     004b883d(j)
//                              scr_vc.cpp:208 (16)
//         004b8845     MOV        this,dword ptr [EBX + 0x480]
//         004b884b     TEST       this,this
//         004b884d     JZ         LAB_004b8855
//         004b884f     MOV        EDX,dword ptr [this->_padding_]
//         004b8851     PUSH       0x1
//         004b8853     CALL       dword ptr [EDX]
//                               LAB_004b8855                                                 XREF[1]:     004b884d(j)
//                              scr_vc.cpp:209 (16)
//         004b8855     MOV        this,dword ptr [EBX + 0x484]
//         004b885b     TEST       this,this
//         004b885d     JZ         LAB_004b8865
//         004b885f     MOV        EAX,dword ptr [this->_padding_]
//         004b8861     PUSH       0x1
//         004b8863     CALL       dword ptr [EAX]
//                               LAB_004b8865                                                 XREF[1]:     004b885d(j)
//                              scr_vc.cpp:211 (11)
//         004b8865     LEA        ESI,[EBX + 0x488]
//         004b886b     MOV        EDI,0x3
//                               LAB_004b8870                                                 XREF[1]:     004b8880(j)
//                              scr_vc.cpp:213 (6)
//         004b8870     MOV        this,dword ptr [ESI]
//         004b8872     TEST       this,this
//         004b8874     JZ         LAB_004b887c
//                              scr_vc.cpp:214 (14)
//         004b8876     MOV        EDX,dword ptr [this->_padding_]
//         004b8878     PUSH       0x1
//         004b887a     CALL       dword ptr [EDX]
//                               LAB_004b887c                                                 XREF[1]:     004b8874(j)
//         004b887c     ADD        ESI,0x4
//         004b887f     DEC        EDI
//         004b8880     JNZ        LAB_004b8870
//         004b8882     MOV        this,EBX
//                              scr_vc.cpp:219 (31)
//         004b8884     MOV        dword ptr [ESP + 0x18],0xffffffff
//         004b888c     CALL       TScreenPanel::~TScreenPanel                      void ~TScreenPanel(TScreenPanel * this)
//         004b8891     MOV        this,dword ptr [ESP + 0x10]
//         004b8895     POP        EDI
//         004b8896     POP        ESI
//         004b8897     MOV        dword ptr FS:[0x0],this
//         004b889e     POP        EBX
//         004b889f     ADD        ESP,0x10
//         004b88a2     RET
//         004b88a3     ??         90h
//         004b88a4     NOP
//         004b88a5     NOP
//         004b88a6     NOP
//         004b88a7     NOP
//         004b88a8     NOP
//         004b88a9     NOP
//         004b88aa     NOP
//         004b88ab     NOP
//         004b88ac     NOP
//         004b88ad     NOP
//         004b88ae     NOP
//         004b88af     NOP
}

long TRIBE_Mission_Screen::handle_idle() {
    /* TODO: Stub */
//                              long __thiscall handle_idle(TRIBE_Mission_Screen * this)
//              long              EAX:4          <RETURN>
//              TRIBE_Mission_    ECX:4 (auto)   this
//                               ?handle_idle@TRIBE_Mission_Screen@@UAEJXZ                    XREF[1]:     00574364(*)
//                               TRIBE_Mission_Screen::handle_idle
//                              scr_vc.cpp:225 (3)
//         004b88b0     PUSH       ESI
//         004b88b1     MOV        ESI,this
//                              scr_vc.cpp:226 (16)
//         004b88b3     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004b88b9     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004b88bf     TEST       EAX,EAX
//         004b88c1     JNZ        LAB_004b88c8
//                              scr_vc.cpp:227 (5)
//         004b88c3     CALL       RGE_Base_Game::enable_input                      void enable_input(RGE_Base_Game * this)
//                               LAB_004b88c8                                                 XREF[1]:     004b88c1(j)
//                              scr_vc.cpp:229 (7)
//         004b88c8     MOV        this,ESI
//         004b88ca     CALL       TPanel::handle_idle                              long handle_idle(TPanel * this)
//                              scr_vc.cpp:230 (2)
//         004b88cf     POP        ESI
//         004b88d0     RET
//         004b88d1     ??         90h
//         004b88d2     NOP
//         004b88d3     NOP
//         004b88d4     NOP
//         004b88d5     NOP
//         004b88d6     NOP
//         004b88d7     NOP
//         004b88d8     NOP
//         004b88d9     NOP
//         004b88da     NOP
//         004b88db     NOP
//         004b88dc     NOP
//         004b88dd     NOP
//         004b88de     NOP
//         004b88df     NOP
    return 0;
}

void TRIBE_Mission_Screen::draw() {
    /* TODO: Stub */
//                              void __thiscall draw(TRIBE_Mission_Screen * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Mission_    ECX:4 (auto)   this
//                               ?draw@TRIBE_Mission_Screen@@UAEXXZ                           XREF[1]:     00574348(*)
//                               TRIBE_Mission_Screen::draw
//                              scr_vc.cpp:236 (3)
//         004b88e0     PUSH       ESI
//         004b88e1     MOV        ESI,this
//                              scr_vc.cpp:237 (5)
//         004b88e3     CALL       TScreenPanel::draw                               void draw(TScreenPanel * this)
//                              scr_vc.cpp:239 (15)
//         004b88e8     MOV        EAX,dword ptr [ESI + 0x498]
//         004b88ee     TEST       EAX,EAX
//         004b88f0     JZ         LAB_004b899d
//         004b88f6     PUSH       EDI
//                              scr_vc.cpp:242 (9)
//         004b88f7     MOV        EDI,dword ptr [ESI]
//         004b88f9     PUSH       0x0
//         004b88fb     MOV        this,ESI
//         004b88fd     CALL       dword ptr [EDI + 0x28]
//                              scr_vc.cpp:244 (6)
//         004b8900     CMP        dword ptr [ESI + 0x38],0x2
//         004b8904     JNZ        LAB_004b891b
//                              scr_vc.cpp:245 (21)
//         004b8906     XOR        EAX,EAX
//         004b8908     LEA        this,[ESI + 0x24]
//         004b890b     MOV        AL,byte ptr [ESI + 0x454]
//         004b8911     PUSH       EAX
//         004b8912     PUSH       this=>DAT_fffffff8
//         004b8913     MOV        this,dword ptr [ESI + 0x20]
//         004b8916     CALL       TDrawArea::Clear                                 void Clear(TDrawArea * this, tagRECT * param_
//                               LAB_004b891b                                                 XREF[1]:     004b8904(j)
//                              scr_vc.cpp:247 (19)
//         004b891b     MOV        this,dword ptr [ESI + 0x20]
//         004b891e     PUSH       0x1
//         004b8920     PUSH       s_scr_vc::draw                                   = "scr_vc::draw"
//         004b8925     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
//         004b892a     TEST       EAX,EAX
//         004b892c     JZ         LAB_004b8997
//                              scr_vc.cpp:249 (10)
//         004b892e     MOV        EAX,dword ptr [ESI + 0x14]
//         004b8931     CMP        EAX,0x280
//         004b8936     JG         LAB_004b894e
//                              scr_vc.cpp:250 (20)
//         004b8938     MOV        EDX,dword ptr [ESI + 0x10]
//         004b893b     MOV        EAX,dword ptr [ESI + 0xc]
//         004b893e     PUSH       0x0
//         004b8940     ADD        EDX,0xa6
//         004b8946     PUSH       0x0=>DAT_fffffff8
//         004b8948     PUSH       EDX=>DAT_fffffff4
//         004b8949     ADD        EAX,0x7
//                              scr_vc.cpp:251 (2)
//         004b894c     JMP        LAB_004b897a
//                               LAB_004b894e                                                 XREF[1]:     004b8936(j)
//                              scr_vc.cpp:252 (27)
//         004b894e     MOV        EDX,dword ptr [ESI + 0x10]
//         004b8951     CMP        EAX,0x320
//         004b8956     PUSH       0x0
//         004b8958     PUSH       0x0=>DAT_fffffff8
//         004b895a     JG         LAB_004b896b
//         004b895c     MOV        EAX,dword ptr [ESI + 0xc]
//         004b895f     ADD        EDX,0x118
//         004b8965     PUSH       EDX=>DAT_fffffff4
//         004b8966     ADD        EAX,0x53
//                              scr_vc.cpp:253 (2)
//         004b8969     JMP        LAB_004b897a
//                               LAB_004b896b                                                 XREF[1]:     004b895a(j)
//                              scr_vc.cpp:254 (31)
//         004b896b     MOV        EAX,dword ptr [ESI + 0xc]
//         004b896e     ADD        EDX,0x16b
//         004b8974     PUSH       EDX=>DAT_fffffff4
//         004b8975     ADD        EAX,0xc5
//                               LAB_004b897a                                                 XREF[2]:     004b894c(j), 004b8969(j)
//         004b897a     MOV        this,dword ptr [ESI + 0x20]
//         004b897d     PUSH       EAX=>DAT_fffffff0
//         004b897e     PUSH       this
//         004b897f     MOV        this,dword ptr [ESI + 0x498]
//         004b8985     CALL       TPicture::Draw                                   void Draw(TPicture * this, TDrawArea * param_
//                              scr_vc.cpp:256 (13)
//         004b898a     MOV        this,dword ptr [ESI + 0x20]
//         004b898d     PUSH       s_scr_vc::draw                                   = "scr_vc::draw"
//         004b8992     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
//                               LAB_004b8997                                                 XREF[1]:     004b892c(j)
//                              scr_vc.cpp:259 (6)
//         004b8997     MOV        this,ESI
//         004b8999     CALL       dword ptr [EDI + 0x2c]
//         004b899c     POP        EDI
//                               LAB_004b899d                                                 XREF[1]:     004b88f0(j)
//                              scr_vc.cpp:260 (2)
//         004b899d     POP        ESI
//         004b899e     RET
//         004b899f     ??         90h
    return;
}

long TRIBE_Mission_Screen::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    /* TODO: Stub */
//                              long __thiscall action(TRIBE_Mission_Screen * this, TPanel * param_1
//              long              EAX:4          <RETURN>
//              TRIBE_Mission_    ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     004b89a8(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     004b89a1(R)
//              ulong             Stack[0xc]:4   param_3                   XREF[1]:     004b8ac8(R)
//              ulong             Stack[0x10]:4  param_4                   XREF[1]:     004b8ac4(R)
//                               ?action@TRIBE_Mission_Screen@@UAEJPAVTPanel@@JKK@Z           XREF[1]:     005743cc(*)
//                               TRIBE_Mission_Screen::action
//                              scr_vc.cpp:266 (1)
//         004b89a0     PUSH       EBX
//                              scr_vc.cpp:267 (22)
//         004b89a1     MOV        EBX,dword ptr [ESP + param_2]
//         004b89a5     PUSH       EBP
//         004b89a6     PUSH       ESI
//         004b89a7     PUSH       EDI
//         004b89a8     MOV        EDI,dword ptr [ESP + param_1]
//         004b89ac     CMP        EBX,0x1
//         004b89af     MOV        ESI,this
//         004b89b1     JNZ        LAB_004b8ac4
//                              scr_vc.cpp:269 (8)
//         004b89b7     CMP        EDI,dword ptr [ESI + 0x488]
//         004b89bd     JNZ        LAB_004b89ea
//                              scr_vc.cpp:270 (43)
//         004b89bf     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004b89c5     MOV        EAX,dword ptr [ESI + 0x47c]
//         004b89cb     PUSH       0x4
//         004b89cd     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004b89d3     MOV        EBP,dword ptr [EAX]
//         004b89d5     MOV        this,dword ptr [EDX + 0x5c]
//         004b89d8     CALL       RGE_Scenario::Get_message                        char * Get_message(RGE_Scenario * this, long
//         004b89dd     MOV        this,dword ptr [ESI + 0x47c]
//         004b89e3     PUSH       EAX
//         004b89e4     CALL       dword ptr [EBP + 0xe8]
//                               LAB_004b89ea                                                 XREF[1]:     004b89bd(j)
//                              scr_vc.cpp:271 (8)
//         004b89ea     CMP        EDI,dword ptr [ESI + 0x48c]
//         004b89f0     JNZ        LAB_004b8a1d
//                              scr_vc.cpp:272 (43)
//         004b89f2     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004b89f8     MOV        EAX,dword ptr [ESI + 0x47c]
//         004b89fe     PUSH       0x0
//         004b8a00     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004b8a06     MOV        EBP,dword ptr [EAX]
//         004b8a08     MOV        this,dword ptr [EDX + 0x5c]
//         004b8a0b     CALL       RGE_Scenario::Get_message                        char * Get_message(RGE_Scenario * this, long
//         004b8a10     MOV        this,dword ptr [ESI + 0x47c]
//         004b8a16     PUSH       EAX
//         004b8a17     CALL       dword ptr [EBP + 0xe8]
//                               LAB_004b8a1d                                                 XREF[1]:     004b89f0(j)
//                              scr_vc.cpp:273 (8)
//         004b8a1d     CMP        EDI,dword ptr [ESI + 0x490]
//         004b8a23     JNZ        LAB_004b8a50
//                              scr_vc.cpp:274 (43)
//         004b8a25     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004b8a2b     MOV        EAX,dword ptr [ESI + 0x47c]
//         004b8a31     PUSH       0x1
//         004b8a33     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004b8a39     MOV        EBP,dword ptr [EAX]
//         004b8a3b     MOV        this,dword ptr [EDX + 0x5c]
//         004b8a3e     CALL       RGE_Scenario::Get_message                        char * Get_message(RGE_Scenario * this, long
//         004b8a43     MOV        this,dword ptr [ESI + 0x47c]
//         004b8a49     PUSH       EAX
//         004b8a4a     CALL       dword ptr [EBP + 0xe8]
//                               LAB_004b8a50                                                 XREF[1]:     004b8a23(j)
//                              scr_vc.cpp:275 (8)
//         004b8a50     CMP        EDI,dword ptr [ESI + 0x484]
//         004b8a56     JNZ        LAB_004b8ac4
//                              scr_vc.cpp:277 (10)
//         004b8a58     MOV        AL,byte ptr [ESI + 0x494]
//         004b8a5e     TEST       AL,AL
//         004b8a60     JZ         LAB_004b8a9e
//                              scr_vc.cpp:279 (17)
//         004b8a62     PUSH       0x0
//         004b8a64     PUSH       s_Game_Screen                                    = "Game Screen"
//         004b8a69     MOV        this,panel_system
//         004b8a6e     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
//                              scr_vc.cpp:280 (32)
//         004b8a73     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004b8a79     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
//         004b8a7e     CMP        EAX,0x1
//         004b8a81     JNZ        LAB_004b8aa9
//         004b8a83     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004b8a89     MOV        EAX,dword ptr [this->_padding_ + 0xa00]
//         004b8a8f     TEST       EAX,EAX
//         004b8a91     JNZ        LAB_004b8aa9
//                              scr_vc.cpp:281 (9)
//         004b8a93     PUSH       0x0
//         004b8a95     PUSH       0x0=>DAT_fffffff8
//         004b8a97     CALL       RGE_Base_Game::set_paused                        void set_paused(RGE_Base_Game * this, int par
//                              scr_vc.cpp:284 (2)
//         004b8a9c     JMP        LAB_004b8aa9
//                               LAB_004b8a9e                                                 XREF[1]:     004b8a60(j)
//                              scr_vc.cpp:286 (11)
//         004b8a9e     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004b8aa4     CALL       TRIBE_Game::create_game_screen                   int create_game_screen(TRIBE_Game * this)
//                               LAB_004b8aa9                                                 XREF[3]:     004b8a81(j), 004b8a91(j),
//                                                                                                         004b8a9c(j)
//                              scr_vc.cpp:287 (15)
//         004b8aa9     PUSH       s_Mission_Dialog                                 = "Mission Dialog"
//         004b8aae     MOV        this,panel_system
//         004b8ab3     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              scr_vc.cpp:289 (5)
//         004b8ab8     MOV        EAX,0x1
//                              scr_vc.cpp:293 (7)
//         004b8abd     POP        EDI
//         004b8abe     POP        ESI
//         004b8abf     POP        EBP
//         004b8ac0     POP        EBX
//         004b8ac1     RET        0x10
//                               LAB_004b8ac4                                                 XREF[2]:     004b89b1(j), 004b8a56(j)
//                              scr_vc.cpp:292 (19)
//         004b8ac4     MOV        EAX,dword ptr [ESP + param_4]
//         004b8ac8     MOV        this,dword ptr [ESP + param_3]
//         004b8acc     PUSH       EAX
//         004b8acd     PUSH       this=>DAT_fffffff8
//         004b8ace     PUSH       EBX=>DAT_fffffff4
//         004b8acf     PUSH       EDI=>DAT_fffffff0
//         004b8ad0     MOV        this,ESI
//         004b8ad2     CALL       TEasy_Panel::action                              long action(TEasy_Panel * this, TPanel * para
//                              scr_vc.cpp:293 (7)
//         004b8ad7     POP        EDI
//         004b8ad8     POP        ESI
//         004b8ad9     POP        EBP
//         004b8ada     POP        EBX
//         004b8adb     RET        0x10
//         004b8ade     ??         90h
//         004b8adf     NOP
    return 0;
}

long TRIBE_Mission_Screen::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) {
    /* TODO: Stub */
//                              long __thiscall key_down_action(TRIBE_Mission_Screen * this, long pa
//              long              EAX:4          <RETURN>
//              TRIBE_Mission_    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     004b8ae8(R)
//              short             Stack[0x8]:2   param_2
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4                   XREF[1]:     004b8ae0(R)
//              int               Stack[0x14]:4  param_5
//                               ?key_down_action@TRIBE_Mission_Screen@@UAEJJFHHH@Z           XREF[1]:     005743c4(*)
//                               TRIBE_Mission_Screen::key_down_action
//                              scr_vc.cpp:299 (15)
//         004b8ae0     MOV        EAX,dword ptr [ESP + param_4]
//         004b8ae4     TEST       EAX,EAX
//         004b8ae6     JZ         LAB_004b8b28
//         004b8ae8     CMP        dword ptr [ESP + param_1],0x56
//         004b8aed     JNZ        LAB_004b8b28
//                              scr_vc.cpp:302 (35)
//         004b8aef     MOV        AL,byte ptr [ECX + this->game_flag]
//         004b8af5     TEST       AL,AL
//         004b8af7     JNZ        LAB_004b8b20
//         004b8af9     MOV        EAX,[rge_base_game]                              = 00000000
//         004b8afe     MOV        this,dword ptr [EAX + 0xc]
//         004b8b01     MOV        EDX,dword ptr [this->_padding_ + 0x8a8]
//         004b8b07     TEST       EDX,EDX
//         004b8b09     JZ         LAB_004b8b20
//         004b8b0b     MOV        this,dword ptr [EAX + 0x60]
//         004b8b0e     TEST       this,this
//         004b8b10     JZ         LAB_004b8b20
//                              scr_vc.cpp:303 (14)
//         004b8b12     PUSH       0x0
//         004b8b14     PUSH       0x0
//         004b8b16     PUSH       s_voice.wav                                      = "voice.wav"
//         004b8b1b     CALL       TSound_Driver::stream_file                       int stream_file(TSound_Driver * this, char *
//                               LAB_004b8b20                                                 XREF[3]:     004b8af7(j), 004b8b09(j),
//                                                                                                         004b8b10(j)
//                              scr_vc.cpp:304 (5)
//         004b8b20     MOV        EAX,0x1
//                              scr_vc.cpp:307 (3)
//         004b8b25     RET        0x14
//                               LAB_004b8b28                                                 XREF[2]:     004b8ae6(j), 004b8aed(j)
//                              scr_vc.cpp:306 (2)
//         004b8b28     XOR        EAX,EAX
//                              scr_vc.cpp:307 (3)
//         004b8b2a     RET        0x14
//         004b8b2d     ??         90h
//         004b8b2e     NOP
//         004b8b2f     NOP
    return 0;
}

