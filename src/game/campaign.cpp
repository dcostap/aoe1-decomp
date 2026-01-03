#include "../common.h"
#include "campaign.h"

RGE_Campaign::RGE_Campaign(char* param_1) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Campaign(RGE_Campaign * this, char * param_1)
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Campaign *    ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     00423230(R)
//                               ??0RGE_Campaign@@QAE@PAD@Z                                   XREF[3]:     find_campaigns:0044d609(c),
//                               RGE_Campaign::RGE_Campaign                                                find_campaigns:0044d69d(c),
//                                                                                                         load_campaign:0049007a(c)
//                              campaign.cpp:22 (45)
//         00423230     MOV        EAX,dword ptr [ESP + param_1]
//         00423234     PUSH       EBX
//         00423235     MOV        EBX,this
//         00423237     PUSH       ESI
//         00423238     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0042323e     PUSH       EAX
//         0042323f     LEA        ESI,[EBX + 0x10c]
//         00423245     MOV        EDX,dword ptr [ECX + this+0xc]
//         00423248     ADD        EDX,0xd1c
//         0042324e     PUSH       EDX
//         0042324f     PUSH       s_%s%s                                           = "%s%s"
//         00423254     PUSH       ESI
//         00423255     CALL       sprintf                                          undefined sprintf()
//         0042325a     ADD        ESP,0x10
//                              campaign.cpp:29 (16)
//         0042325d     PUSH       0x8000
//         00423262     PUSH       ESI
//         00423263     CALL       __open                                           undefined __open()
//         00423268     MOV        ESI,EAX
//         0042326a     ADD        ESP,0x8
//                              campaign.cpp:30 (4)
//         0042326d     TEST       ESI,ESI
//         0042326f     JL         LAB_004232e3
//                              campaign.cpp:33 (12)
//         00423271     PUSH       0x108
//         00423276     PUSH       EBX
//         00423277     PUSH       ESI
//         00423278     CALL       read                                             undefined read()
//                              campaign.cpp:36 (13)
//         0042327d     MOV        EAX,dword ptr [EBX + 0x104]
//         00423283     ADD        ESP,0xc
//         00423286     TEST       EAX,EAX
//         00423288     JLE        LAB_004232c9
//                              campaign.cpp:38 (11)
//         0042328a     PUSH       0x208
//         0042328f     PUSH       EAX
//         00423290     CALL       calloc                                           undefined calloc()
//                              campaign.cpp:39 (36)
//         00423295     MOV        this,dword ptr [EBX + 0x104]
//         0042329b     ADD        ESP,0x8
//         0042329e     MOV        EDX,this
//         004232a0     MOV        dword ptr [EBX + 0x108],EAX
//         004232a6     SHL        EDX,0x6
//         004232a9     ADD        EDX,this
//         004232ab     SHL        EDX,0x3
//         004232ae     PUSH       EDX
//         004232af     PUSH       EAX
//         004232b0     PUSH       ESI
//         004232b1     CALL       read                                             undefined read()
//         004232b6     ADD        ESP,0xc
//                              campaign.cpp:45 (9)
//         004232b9     PUSH       ESI
//         004232ba     CALL       close                                            undefined close()
//         004232bf     ADD        ESP,0x4
//                              campaign.cpp:54 (7)
//         004232c2     MOV        EAX,EBX
//         004232c4     POP        ESI
//         004232c5     POP        EBX
//         004232c6     RET        0x4
//                               LAB_004232c9                                                 XREF[1]:     00423288(j)
//                              campaign.cpp:45 (19)
//         004232c9     PUSH       ESI
//         004232ca     MOV        dword ptr [EBX + 0x108],0x0
//         004232d4     CALL       close                                            undefined close()
//         004232d9     ADD        ESP,0x4
//                              campaign.cpp:54 (7)
//         004232dc     MOV        EAX,EBX
//         004232de     POP        ESI
//         004232df     POP        EBX
//         004232e0     RET        0x4
//                               LAB_004232e3                                                 XREF[1]:     0042326f(j)
//                              campaign.cpp:22 (1)
//         004232e3     PUSH       EDI
//                              campaign.cpp:49 (32)
//         004232e4     MOV        EDI,s_FILE_NOT_FOUND                             = 46h
//         004232e9     OR         this,0xffffffff
//         004232ec     XOR        EAX,EAX
//         004232ee     SCASB.RE   ES:EDI=>s_FILE_NOT_FOUND                         = 46h
//                                                                                  = "ILE NOT FOUND"
//         004232f0     NOT        this
//         004232f2     SUB        EDI,this
//         004232f4     LEA        EDX,[EBX + 0x4]
//         004232f7     MOV        EAX,this
//         004232f9     MOV        ESI,EDI
//         004232fb     MOV        EDI,EDX
//         004232fd     SHR        this,0x2
//         00423300     MOVSD.REP  ES:EDI,ESI
//         00423302     MOV        this,EAX
//                              campaign.cpp:54 (39)
//         00423304     MOV        EAX,EBX
//         00423306     AND        this,0x3
//         00423309     MOVSB.REP  ES:EDI,ESI
//         0042330b     POP        EDI
//         0042330c     MOV        dword ptr [EBX + 0x104],0x0
//         00423316     MOV        dword ptr [EBX],0x0
//         0042331c     MOV        dword ptr [EBX + 0x108],0x0
//         00423326     POP        ESI
//         00423327     POP        EBX
//         00423328     RET        0x4
//         0042332b     ??         90h
//         0042332c     NOP
//         0042332d     NOP
//         0042332e     NOP
//         0042332f     NOP
}

RGE_Campaign::RGE_Campaign(char* param_1, char* param_2, long param_3, char** param_4, char** param_5) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Campaign(RGE_Campaign * this, char * param_
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Campaign *    ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[4]:     00423331(R), 004233c6(W), 0042343b(R), 00423445(W)
//              char *            Stack[0x8]:4   param_2                   XREF[3]:     00423362(R), 004233ca(W), 004233d0(R)
//              long              Stack[0xc]:4   param_3                   XREF[5]:     0042338e(R), 004233ef(W), 004233f7(R), 00423422(W),
//                                                                                     0042342a(R)
//              char * *          Stack[0x10]:4  param_4                   XREF[1]:     004233bc(R)
//              char * *          Stack[0x14]:4  param_5                   XREF[1]:     004233c0(R)
//                               ??0RGE_Campaign@@QAE@PAD0JPAPAD1@Z                           XREF[1]:     make_campaign:00490298(c)
//                               RGE_Campaign::RGE_Campaign
//                              campaign.cpp:65 (1)
//         00423330     PUSH       EBX
//                              campaign.cpp:69 (43)
//         00423331     MOV        EAX,dword ptr [ESP + param_1]
//         00423335     PUSH       EBP
//         00423336     MOV        EBP,this
//         00423338     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0042333e     PUSH       ESI
//         0042333f     PUSH       EDI
//         00423340     PUSH       EAX
//         00423341     MOV        EDX,dword ptr [ECX + this+0xc]
//         00423344     LEA        EAX,[EBP + 0x10c]
//         0042334a     ADD        EDX,0xd1c
//         00423350     PUSH       EDX
//         00423351     PUSH       s_%s%s                                           = "%s%s"
//         00423356     PUSH       EAX
//         00423357     CALL       sprintf                                          undefined sprintf()
//                              campaign.cpp:72 (6)
//         0042335c     MOV        this,dword ptr [s_1.00]                          = "1.00"
//                              campaign.cpp:73 (30)
//         00423362     MOV        EDI,dword ptr [ESP + param_2]
//         00423366     MOV        dword ptr [EBP],this
//         00423369     OR         this,0xffffffff
//         0042336c     XOR        EAX,EAX
//         0042336e     ADD        ESP,0x10
//         00423371     SCASB.RE   ES:EDI
//         00423373     NOT        this
//         00423375     SUB        EDI,this
//         00423377     LEA        EDX,[EBP + 0x4]
//         0042337a     MOV        EAX,this
//         0042337c     MOV        ESI,EDI
//         0042337e     MOV        EDI,EDX
//                              campaign.cpp:77 (32)
//         00423380     XOR        EBX,EBX
//         00423382     SHR        this,0x2
//         00423385     MOVSD.REP  ES:EDI,ESI
//         00423387     MOV        this,EAX
//         00423389     AND        this,0x3
//         0042338c     MOVSB.REP  ES:EDI,ESI
//         0042338e     MOV        ESI,dword ptr [ESP + param_3]
//         00423392     CMP        ESI,EBX
//         00423394     MOV        dword ptr [EBP + 0x104],ESI
//         0042339a     JLE        LAB_0042345b
//                              campaign.cpp:79 (14)
//         004233a0     PUSH       0x208
//         004233a5     PUSH       ESI
//         004233a6     CALL       calloc                                           undefined calloc()
//         004233ab     ADD        ESP,0x8
//                              campaign.cpp:80 (14)
//         004233ae     CMP        ESI,EBX
//         004233b0     MOV        dword ptr [EBP + 0x108],EAX
//         004233b6     JLE        LAB_00423461
//                              campaign.cpp:90 (24)
//         004233bc     MOV        EDX,dword ptr [ESP + param_4]
//         004233c0     MOV        EAX,dword ptr [ESP + param_5]
//         004233c4     SUB        EAX,EDX
//         004233c6     MOV        dword ptr [ESP + param_1],ESI
//         004233ca     MOV        dword ptr [ESP + param_2],EAX
//         004233ce     JMP        LAB_004233d4
//                               LAB_004233d0                                                 XREF[1]:     00423449(j)
//         004233d0     MOV        EAX,dword ptr [ESP + param_2]
//                               LAB_004233d4                                                 XREF[1]:     004233ce(j)
//                              campaign.cpp:82 (46)
//         004233d4     MOV        this,dword ptr [EBP + 0x108]
//         004233da     MOV        EDI,dword ptr [EAX + EDX*0x1]
//         004233dd     XOR        EAX,EAX
//         004233df     ADD        EDX,0x4
//         004233e2     LEA        ESI,[ECX + EBX*0x1 + this+0x8]
//         004233e6     OR         this,0xffffffff
//         004233e9     SCASB.RE   ES:EDI
//         004233eb     NOT        this
//         004233ed     SUB        EDI,this
//         004233ef     MOV        dword ptr [ESP + param_3],ESI
//         004233f3     MOV        EAX,this
//         004233f5     MOV        ESI,EDI
//         004233f7     MOV        EDI,dword ptr [ESP + param_3]
//         004233fb     SHR        this,0x2
//         004233fe     MOVSD.REP  ES:EDI,ESI
//         00423400     MOV        this,EAX
//                              campaign.cpp:83 (73)
//         00423402     XOR        EAX,EAX
//         00423404     AND        this,0x3
//         00423407     MOVSB.REP  ES:EDI,ESI
//         00423409     MOV        this,dword ptr [EBP + 0x108]
//         0042340f     MOV        EDI,dword ptr [EDX + -0x4]
//         00423412     LEA        ESI,[ECX + EBX*0x1 + this+0x107]
//         00423419     OR         this,0xffffffff
//         0042341c     SCASB.RE   ES:EDI
//         0042341e     NOT        this
//         00423420     SUB        EDI,this
//         00423422     MOV        dword ptr [ESP + param_3],ESI
//         00423426     MOV        EAX,this
//         00423428     MOV        ESI,EDI
//         0042342a     MOV        EDI,dword ptr [ESP + param_3]
//         0042342e     ADD        EBX,0x208
//         00423434     SHR        this,0x2
//         00423437     MOVSD.REP  ES:EDI,ESI
//         00423439     MOV        this,EAX
//         0042343b     MOV        EAX,dword ptr [ESP + param_1]
//         0042343f     AND        this,0x3
//         00423442     DEC        EAX
//         00423443     MOVSB.REP  ES:EDI,ESI
//         00423445     MOV        dword ptr [ESP + param_1],EAX
//         00423449     JNZ        LAB_004233d0
//                              campaign.cpp:89 (7)
//         0042344b     MOV        this,EBP
//         0042344d     CALL       RGE_Campaign::create_file                        void create_file(RGE_Campaign * this)
//                              campaign.cpp:90 (9)
//         00423452     MOV        EAX,EBP
//         00423454     POP        EDI
//         00423455     POP        ESI
//         00423456     POP        EBP
//         00423457     POP        EBX
//         00423458     RET        0x14
//                               LAB_0042345b                                                 XREF[1]:     0042339a(j)
//                              campaign.cpp:87 (6)
//         0042345b     MOV        dword ptr [EBP + 0x108],EBX
//                               LAB_00423461                                                 XREF[1]:     004233b6(j)
//                              campaign.cpp:89 (7)
//         00423461     MOV        this,EBP
//         00423463     CALL       RGE_Campaign::create_file                        void create_file(RGE_Campaign * this)
//                              campaign.cpp:90 (9)
//         00423468     POP        EDI
//         00423469     MOV        EAX,EBP
//         0042346b     POP        ESI
//         0042346c     POP        EBP
//         0042346d     POP        EBX
//         0042346e     RET        0x14
//         00423471     ??         90h
//         00423472     NOP
//         00423473     NOP
//         00423474     NOP
//         00423475     NOP
//         00423476     NOP
//         00423477     NOP
//         00423478     NOP
//         00423479     NOP
//         0042347a     NOP
//         0042347b     NOP
//         0042347c     NOP
//         0042347d     NOP
//         0042347e     NOP
//         0042347f     NOP
}

RGE_Campaign::~RGE_Campaign() {
    /* TODO: Stub */
//                              void __thiscall ~RGE_Campaign(RGE_Campaign * this)
//              void              <VOID>         <RETURN>
//              RGE_Campaign *    ECX:4 (auto)   this
//                               ??1RGE_Campaign@@QAE@XZ                                      XREF[4]:     ~RGE_Game_Info:0044d333(c),
//                               RGE_Campaign::~RGE_Campaign                                               find_campaigns:0044d4ad(c),
//                                                                                                         load_campaign:004900b7(c),
//                                                                                                         make_campaign:004902ba(c)
//                              campaign.cpp:94 (3)
//         00423480     PUSH       ESI
//         00423481     MOV        ESI,this
//                              campaign.cpp:95 (10)
//         00423483     MOV        EAX,dword ptr [ESI + 0x108]
//         00423489     TEST       EAX,EAX
//         0042348b     JZ         LAB_004234a0
//                              campaign.cpp:97 (9)
//         0042348d     PUSH       EAX
//         0042348e     CALL       free                                             undefined free()
//         00423493     ADD        ESP,0x4
//                              campaign.cpp:98 (10)
//         00423496     MOV        dword ptr [ESI + 0x108],0x0
//                               LAB_004234a0                                                 XREF[1]:     0042348b(j)
//                              campaign.cpp:100 (2)
//         004234a0     POP        ESI
//         004234a1     RET
//         004234a2     ??         90h
//         004234a3     NOP
//         004234a4     NOP
//         004234a5     NOP
//         004234a6     NOP
//         004234a7     NOP
//         004234a8     NOP
//         004234a9     NOP
//         004234aa     NOP
//         004234ab     NOP
//         004234ac     NOP
//         004234ad     NOP
//         004234ae     NOP
//         004234af     NOP
}

void RGE_Campaign::create_file() {
    /* TODO: Stub */
//                              void __thiscall create_file(RGE_Campaign * this)
//              void              <VOID>         <RETURN>
//              RGE_Campaign *    ECX:4 (auto)   this
//              char[300]         Stack[-0x130   tempname                  XREF[3,2]:   00423536(W), 004235e8(R), 004235ff(W), 0042355c(*),
//                                                                                     00423578(*)
//              long              Stack[-0x134   current_offset            XREF[3]:     00423524(W), 00423618(R), 0042362f(W)
//              long              Stack[-0x138   index                     XREF[3]:     004234da(W), 004235cf(R), 00423611(R)
//              int               Stack[-0x13c   handle                    XREF[5]:     00423541(W), 0042354b(R), 004235e4(R), 0042361c(R),
//                                                                                     00423633(W)
//                               ?create_file@RGE_Campaign@@QAEXXZ                            XREF[2]:     RGE_Campaign:0042344d(c),
//                               RGE_Campaign::create_file                                                 RGE_Campaign:00423463(c)
//                              campaign.cpp:104 (11)
//         004234b0     SUB        ESP,0x13c
//         004234b6     PUSH       EBP
//         004234b7     MOV        EBP,this
//         004234b9     PUSH       ESI
//         004234ba     PUSH       EDI
//                              campaign.cpp:113 (24)
//         004234bb     PUSH       0x180
//         004234c0     LEA        EAX,[EBP + 0x10c]
//         004234c6     PUSH       0x8301
//         004234cb     PUSH       EAX
//         004234cc     CALL       __open                                           undefined __open()
//         004234d1     MOV        EDI,EAX
//                              campaign.cpp:114 (17)
//         004234d3     XOR        ESI,ESI
//         004234d5     ADD        ESP,0xc
//         004234d8     CMP        EDI,ESI
//         004234da     MOV        dword ptr [ESP + index],EDI
//         004234de     JL         LAB_00423678
//                              campaign.cpp:117 (12)
//         004234e4     PUSH       0x108
//         004234e9     PUSH       EBP
//         004234ea     PUSH       EDI
//         004234eb     CALL       write                                            undefined write()
//                              campaign.cpp:119 (17)
//         004234f0     MOV        EAX,dword ptr [EBP + 0x104]
//         004234f6     ADD        ESP,0xc
//         004234f9     CMP        EAX,ESI
//         004234fb     JLE        LAB_0042366f
//                              campaign.cpp:122 (24)
//         00423501     MOV        EDX,dword ptr [EBP + 0x108]
//         00423507     MOV        this,EAX
//         00423509     SHL        this,0x6
//         0042350c     ADD        this,EAX
//         0042350e     SHL        this,0x3
//         00423511     PUSH       this
//         00423512     PUSH       EDX
//         00423513     PUSH       EDI
//         00423514     CALL       write                                            undefined write()
//                              campaign.cpp:126 (11)
//         00423519     MOV        EAX,dword ptr [EBP + 0x104]
//         0042351f     ADD        ESP,0xc
//         00423522     MOV        this,EAX
//                              campaign.cpp:127 (29)
//         00423524     MOV        dword ptr [ESP + current_offset],ESI
//         00423528     SHL        this,0x6
//         0042352b     ADD        this,EAX
//         0042352d     CMP        EAX,ESI
//         0042352f     LEA        EDX,[this->campaign_header.version*0x8 + 0x108]
//         00423536     MOV        dword ptr [ESP + tempname[0]],EDX
//         0042353a     JLE        LAB_0042363e
//         00423540     PUSH       EBX
//                              campaign.cpp:169 (252)
//         00423541     MOV        dword ptr [ESP + handle],ESI
//                               LAB_00423545                                                 XREF[1]:     00423637(j)
//         00423545     MOV        EAX,dword ptr [EBP + 0x108]
//         0042354b     MOV        this,dword ptr [ESP + handle]
//         0042354f     LEA        EDX,[EAX + this->campaign_header.version*0x1 +
//         00423556     MOV        EAX,[rge_base_game]                              = 00000000
//         0042355b     PUSH       EDX
//         0042355c     LEA        EDX=>tempname[4],[ESP + 0x24]
//         00423560     MOV        this,dword ptr [EAX + 0xc]
//         00423563     ADD        this,0xc17
//         00423569     PUSH       this
//         0042356a     PUSH       s_%s%s                                           = "%s%s"
//         0042356f     PUSH       EDX
//         00423570     CALL       sprintf                                          undefined sprintf()
//         00423575     ADD        ESP,0x10
//         00423578     LEA        EAX=>tempname[4],[ESP + 0x20]
//         0042357c     PUSH       0x8000
//         00423581     PUSH       EAX
//         00423582     CALL       __open                                           undefined __open()
//         00423587     MOV        ESI,EAX
//         00423589     ADD        ESP,0x8
//         0042358c     CMP        ESI,-0x1
//         0042358f     JLE        LAB_00423618
//         00423595     PUSH       0x2
//         00423597     PUSH       0x0
//         00423599     PUSH       ESI
//         0042359a     CALL       lseek                                            undefined lseek()
//         0042359f     ADD        ESP,0xc
//         004235a2     PUSH       ESI
//         004235a3     CALL       __tell                                           undefined __tell()
//         004235a8     ADD        ESP,0x4
//         004235ab     MOV        EDI,EAX
//         004235ad     PUSH       0x1
//         004235af     PUSH       EDI
//         004235b0     CALL       calloc                                           undefined calloc()
//         004235b5     ADD        ESP,0x8
//         004235b8     MOV        EBX,EAX
//         004235ba     PUSH       0x0
//         004235bc     PUSH       0x0
//         004235be     PUSH       ESI
//         004235bf     CALL       lseek                                            undefined lseek()
//         004235c4     ADD        ESP,0xc
//         004235c7     PUSH       EDI
//         004235c8     PUSH       EBX
//         004235c9     PUSH       ESI
//         004235ca     CALL       read                                             undefined read()
//         004235cf     MOV        this,dword ptr [ESP + index]
//         004235d3     ADD        ESP,0xc
//         004235d6     PUSH       EDI
//         004235d7     PUSH       EBX
//         004235d8     PUSH       this
//         004235d9     CALL       write                                            undefined write()
//         004235de     MOV        EDX,dword ptr [EBP + 0x108]
//         004235e4     MOV        EAX,dword ptr [ESP + handle]
//         004235e8     MOV        this,dword ptr [ESP + tempname[0]]
//         004235ec     ADD        ESP,0xc
//         004235ef     MOV        dword ptr [EDX + EAX*0x1 + 0x4],this
//         004235f3     MOV        EDX,dword ptr [EBP + 0x108]
//         004235f9     ADD        this,EDI
//         004235fb     PUSH       EBX
//         004235fc     MOV        dword ptr [EDX + EAX*0x1],EDI
//         004235ff     MOV        dword ptr [ESP + tempname[0]],this
//         00423603     CALL       free                                             undefined free()
//         00423608     ADD        ESP,0x4
//         0042360b     PUSH       ESI
//         0042360c     CALL       close                                            undefined close()
//         00423611     MOV        EDI,dword ptr [ESP + index]
//         00423615     ADD        ESP,0x4
//                               LAB_00423618                                                 XREF[1]:     0042358f(j)
//         00423618     MOV        EAX,dword ptr [ESP + current_offset]
//         0042361c     MOV        EDX,dword ptr [ESP + handle]
//         00423620     MOV        this,dword ptr [EBP + 0x104]
//         00423626     INC        EAX
//         00423627     ADD        EDX,0x208
//         0042362d     CMP        EAX,this
//         0042362f     MOV        dword ptr [ESP + current_offset],EAX
//         00423633     MOV        dword ptr [ESP + handle],EDX
//         00423637     JL         LAB_00423545
//                              campaign.cpp:104 (1)
//         0042363d     POP        EBX
//                               LAB_0042363e                                                 XREF[1]:     0042353a(j)
//                              campaign.cpp:163 (13)
//         0042363e     PUSH       0x0
//         00423640     PUSH       0x108
//         00423645     PUSH       EDI
//         00423646     CALL       lseek                                            undefined lseek()
//                              campaign.cpp:164 (36)
//         0042364b     MOV        EAX,dword ptr [EBP + 0x104]
//         00423651     MOV        EDX,dword ptr [EBP + 0x108]
//         00423657     MOV        this,EAX
//         00423659     ADD        ESP,0xc
//         0042365c     SHL        this,0x6
//         0042365f     ADD        this,EAX
//         00423661     SHL        this,0x3
//         00423664     PUSH       this
//         00423665     PUSH       EDX
//         00423666     PUSH       EDI
//         00423667     CALL       write                                            undefined write()
//         0042366c     ADD        ESP,0xc
//                               LAB_0042366f                                                 XREF[1]:     004234fb(j)
//                              campaign.cpp:167 (9)
//         0042366f     PUSH       EDI
//         00423670     CALL       close                                            undefined close()
//         00423675     ADD        ESP,0x4
//                               LAB_00423678                                                 XREF[1]:     004234de(j)
//                              campaign.cpp:169 (10)
//         00423678     POP        EDI
//         00423679     POP        ESI
//         0042367a     POP        EBP
//         0042367b     ADD        ESP,0x13c
//         00423681     RET
//         00423682     ??         90h
//         00423683     NOP
//         00423684     NOP
//         00423685     NOP
//         00423686     NOP
//         00423687     NOP
//         00423688     NOP
//         00423689     NOP
//         0042368a     NOP
//         0042368b     NOP
//         0042368c     NOP
//         0042368d     NOP
//         0042368e     NOP
//         0042368f     NOP
    return;
}

int RGE_Campaign::open_scenario(long param_1) {
    /* TODO: Stub */
//                              int __thiscall open_scenario(RGE_Campaign * this, long param_1)
//              int               EAX:4          <RETURN>
//              RGE_Campaign *    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00423692(R)
//                               ?open_scenario@RGE_Campaign@@QAEHJ@Z                         XREF[1]:     open_scenario:0044cc32(c)
//                               RGE_Campaign::open_scenario
//                              campaign.cpp:175 (2)
//         00423690     PUSH       EBX
//         00423691     PUSH       EBP
//                              campaign.cpp:179 (20)
//         00423692     MOV        EBP,dword ptr [ESP + param_1]
//         00423696     PUSH       ESI
//         00423697     TEST       EBP,EBP
//         00423699     PUSH       EDI
//         0042369a     MOV        EBX,this
//         0042369c     JL         LAB_004236fc
//         0042369e     CMP        EBP,dword ptr [EBX + 0x104]
//         004236a4     JGE        LAB_004236fc
//                              campaign.cpp:182 (22)
//         004236a6     LEA        EAX,[EBX + 0x10c]
//         004236ac     PUSH       0x8000
//         004236b1     PUSH       EAX
//         004236b2     CALL       __open                                           undefined __open()
//         004236b7     MOV        EDI,EAX
//         004236b9     ADD        ESP,0x8
//                              campaign.cpp:183 (4)
//         004236bc     TEST       EDI,EDI
//         004236be     JL         LAB_004236fc
//                              campaign.cpp:186 (29)
//         004236c0     MOV        this,dword ptr [EBX + 0x108]
//         004236c6     MOV        ESI,EBP
//         004236c8     SHL        ESI,0x6
//         004236cb     ADD        ESI,EBP
//         004236cd     PUSH       0x0
//         004236cf     SHL        ESI,0x3
//         004236d2     MOV        EDX,dword ptr [ECX + ESI*0x1 + this+0x4]
//         004236d6     PUSH       EDX
//         004236d7     PUSH       EDI
//         004236d8     CALL       lseek                                            undefined lseek()
//                              campaign.cpp:188 (22)
//         004236dd     MOV        EAX,dword ptr [EBX + 0x108]
//         004236e3     ADD        ESP,0xc
//         004236e6     MOV        this,dword ptr [EAX + ESI*0x1]
//         004236e9     PUSH       this
//         004236ea     PUSH       EDI
//         004236eb     CALL       rge_fake_open                                    int rge_fake_open(int param_1, int param_2)
//         004236f0     ADD        ESP,0x8
//                              campaign.cpp:189 (2)
//         004236f3     MOV        EAX,EDI
//                              campaign.cpp:193 (17)
//         004236f5     POP        EDI
//         004236f6     POP        ESI
//         004236f7     POP        EBP
//         004236f8     POP        EBX
//         004236f9     RET        0x4
//                               LAB_004236fc                                                 XREF[3]:     0042369c(j), 004236a4(j),
//                                                                                                         004236be(j)
//         004236fc     POP        EDI
//         004236fd     POP        ESI
//         004236fe     POP        EBP
//         004236ff     OR         EAX,0xffffffff
//         00423702     POP        EBX
//         00423703     RET        0x4
//         00423706     ??         90h
//         00423707     NOP
//         00423708     NOP
//         00423709     NOP
//         0042370a     NOP
//         0042370b     NOP
//         0042370c     NOP
//         0042370d     NOP
//         0042370e     NOP
//         0042370f     NOP
    return 0;
}

char* RGE_Campaign::get_name() {
    /* TODO: Stub */
//                              char * __thiscall get_name(RGE_Campaign * this)
//              char *            EAX:4          <RETURN>
//              RGE_Campaign *    ECX:4 (auto)   this
//                               ?get_name@RGE_Campaign@@QAEPADXZ                             XREF[6]:     RGE_Campaign_Info:0044c63f(c),
//                               RGE_Campaign::get_name                                                    RGE_Campaign_Info:0044c79a(c),
//                                                                                                         rehook_campaigns:0044c95d(c),
//                                                                                                         set_current_campaign:0044cf4f(c),
//                                                                                                         get_current_campaign:0044d07b(c),
//                                                                                                         get_campaign_list:0044d8f5(c)
//                              campaign.cpp:198 (3)
//         00423710     LEA        EAX,[ECX + this+0x4]
//                              campaign.cpp:200 (1)
//         00423713     RET
//         00423714     ??         90h
//         00423715     NOP
//         00423716     NOP
//         00423717     NOP
//         00423718     NOP
//         00423719     NOP
//         0042371a     NOP
//         0042371b     NOP
//         0042371c     NOP
//         0042371d     NOP
//         0042371e     NOP
//         0042371f     NOP
    return 0;
}

long RGE_Campaign::scenario_number() {
    /* TODO: Stub */
//                              long __thiscall scenario_number(RGE_Campaign * this)
//              long              EAX:4          <RETURN>
//              RGE_Campaign *    ECX:4 (auto)   this
//                               ?scenario_number@RGE_Campaign@@QAEJXZ                        XREF[12]:    RGE_Campaign_Info:0044c681(c),
//                               RGE_Campaign::scenario_number                                             RGE_Campaign_Info:0044c698(c),
//                                                                                                         RGE_Campaign_Info:0044c6ad(c),
//                                                                                                         RGE_Campaign_Info:0044c6c9(c),
//                                                                                                         RGE_Campaign_Info:0044c6ed(c),
//                                                                                                         RGE_Campaign_Info:0044c729(c),
//                                                                                                         RGE_Campaign_Info:0044c7c4(c),
//                                                                                                         rehook_campaigns:0044c9a2(c),
//                                                                                                         rehook_campaigns:0044c9b7(c),
//                                                                                                         rehook_campaigns:0044c9d3(c),
//                                                                                                         rehook_campaigns:0044c9f7(c),
//                                                                                                         rehook_campaigns:0044ca33(c)
//                              campaign.cpp:205 (6)
//         00423720     MOV        EAX,dword ptr [ECX + this+0x104]
//                              campaign.cpp:207 (1)
//         00423726     RET
//         00423727     ??         90h
//         00423728     NOP
//         00423729     NOP
//         0042372a     NOP
//         0042372b     NOP
//         0042372c     NOP
//         0042372d     NOP
//         0042372e     NOP
//         0042372f     NOP
    return 0;
}

long RGE_Campaign::scenario_info(char*** param_1) {
    /* TODO: Stub */
//                              long __thiscall scenario_info(RGE_Campaign * this, char * * * param_1)
//              long              EAX:4          <RETURN>
//              RGE_Campaign *    ECX:4 (auto)   this
//              char * * *        Stack[0x4]:4   param_1                   XREF[1]:     00423743(R)
//                               ?scenario_info@RGE_Campaign@@QAEJPAPAPAD@Z                   XREF[1]:     fill_campaign_scenario_list:0048fe
//                               RGE_Campaign::scenario_info
//                              campaign.cpp:212 (5)
//         00423730     PUSH       EBP
//         00423731     PUSH       ESI
//         00423732     PUSH       EDI
//         00423733     MOV        EDI,this
//                              campaign.cpp:216 (21)
//         00423735     PUSH       0x4
//         00423737     MOV        EAX,dword ptr [EDI + 0x104]
//         0042373d     PUSH       EAX
//         0042373e     CALL       calloc                                           undefined calloc()
//         00423743     MOV        EBP,dword ptr [ESP + param_1]
//         00423747     ADD        ESP,0x8
//                              campaign.cpp:219 (18)
//         0042374a     XOR        ESI,ESI
//         0042374c     MOV        dword ptr [EBP],EAX
//         0042374f     MOV        EAX,dword ptr [EDI + 0x104]
//         00423755     TEST       EAX,EAX
//         00423757     JLE        LAB_00423788
//         00423759     PUSH       EBX
//         0042375a     XOR        EBX,EBX
//                               LAB_0042375c                                                 XREF[1]:     00423785(j)
//                              campaign.cpp:220 (43)
//         0042375c     MOV        this,dword ptr [EDI + 0x108]
//         00423762     MOV        EAX,dword ptr [EBP]
//         00423765     LEA        EDX,[ECX + EBX*0x1 + this+0x8]
//         00423769     LEA        this,[EAX + ESI*0x4]
//         0042376c     PUSH       EDX
//         0042376d     PUSH       this
//         0042376e     CALL       getstring                                        void getstring(char * * param_1, char * param
//         00423773     MOV        EAX,dword ptr [EDI + 0x104]
//         00423779     ADD        ESP,0x8
//         0042377c     INC        ESI
//         0042377d     ADD        EBX,0x208
//         00423783     CMP        ESI,EAX
//         00423785     JL         LAB_0042375c
//                              campaign.cpp:212 (1)
//         00423787     POP        EBX
//                               LAB_00423788                                                 XREF[1]:     00423757(j)
//                              campaign.cpp:222 (6)
//         00423788     MOV        EAX,dword ptr [EDI + 0x104]
//                              campaign.cpp:223 (6)
//         0042378e     POP        EDI
//         0042378f     POP        ESI
//         00423790     POP        EBP
//         00423791     RET        0x4
//         00423794     ??         90h
//         00423795     NOP
//         00423796     NOP
//         00423797     NOP
//         00423798     NOP
//         00423799     NOP
//         0042379a     NOP
//         0042379b     NOP
//         0042379c     NOP
//         0042379d     NOP
//         0042379e     NOP
//         0042379f     NOP
    return 0;
}

char* RGE_Campaign::get_scenario_name(long param_1) {
    /* TODO: Stub */
//                              char * __thiscall get_scenario_name(RGE_Campaign * this, long param_1)
//              char *            EAX:4          <RETURN>
//              RGE_Campaign *    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     004237a0(R)
//                               ?get_scenario_name@RGE_Campaign@@QAEPADJ@Z                   XREF[1]:     get_scenario_list:0044cb5a(c)
//                               RGE_Campaign::get_scenario_name
//                              campaign.cpp:227 (21)
//         004237a0     MOV        EAX,dword ptr [ESP + param_1]
//         004237a4     MOV        EDX,EAX
//         004237a6     SHL        EDX,0x6
//         004237a9     ADD        EDX,EAX
//         004237ab     MOV        EAX,dword ptr [ECX + this->scenario_offsets]
//         004237b1     LEA        EAX,[EAX + EDX*0x8 + 0x8]
//                              campaign.cpp:229 (3)
//         004237b5     RET        0x4
//         004237b8     ??         90h
//         004237b9     NOP
//         004237ba     NOP
//         004237bb     NOP
//         004237bc     NOP
//         004237bd     NOP
//         004237be     NOP
//         004237bf     NOP
    return 0;
}

