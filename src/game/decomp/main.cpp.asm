// Auto-generated scaffold unit: main.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/main.cpp
#include "../include/common.h"

// Offset: 0x004549E0
undefined WinMain_16() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined _WinMain@16()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00454f2e(W), 00454f4c(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00454fd2(R)  
    //              char[256]         Stack[-0x110   msg
    //              char[256]         Stack[-0x210   title
    //              RGE_Prog_Info     Stack[-0x144   info                      XREF[1,66]:  00454f28(W), 00454a0d(*), 00454a56(*), 00454f37(*), 
    //                                                                                     00454a1d(*), 00454a43(*), 00454a79(*), 00454a86(*), 
    //                                                                                     00454bb3(*), 00454c82(W), 00454c89(W), 00454c90(W), 
    //                                                                                     00454bfd(W), 00454bf6(W), 00454aaf(*), 00454adb(*), 
    //                                                                                     00454c10(W), 00454b06(*), 00454b2c(*), 00454b55(*)  
    //              int               Stack[-0x144   error_code                XREF[20]:    00454d8a(W), 00454d98(R), 00454dc0(W), 00454dc6(R), 
    //                                                                                     00454dee(W), 00454df4(R), 00454e1c(W), 00454e22(R), 
    //                                                                                     00454e4a(W), 00454e50(R), 00454e76(W), 00454e7e(R), 
    //                                                                                     00454eab(W), 00454eb1(R), 00454ed9(W), 00454edf(R), 
    //                                                                                     00454f07(W), 00454f0d(R), 00454f18(W), 00454fd9(R)  
    //              int               Stack[-0x145   retval
    //                               _WinMain@16                                                  XREF[1]:     entry:0054f9aa(c)  
    //                              main.cpp:66 (35)
    //         004549e0     PUSH       -0x1
    //         004549e2     MOV        EAX,FS:[0x0]
    //         004549e8     PUSH       FUN_0055da7e
    //         004549ed     PUSH       EAX
    //                              language.dll match for 0x1440: "Axeman"
    //         004549ee     MOV        EAX,0x1440
    //         004549f3     MOV        dword ptr FS:[0x0],ESP
    //         004549fa     CALL       __alloca_probe                                   undefined __alloca_probe()
    //         004549ff     PUSH       EBX
    //         00454a00     PUSH       EBP
    //         00454a01     PUSH       ESI
    //         00454a02     PUSH       EDI
    //                              main.cpp:74 (26)
    //         00454a03     MOV        EDI,s_Age_of_Empires,_Roman_Expansion            = 41h
    //         00454a08     OR         ECX,0xffffffff
    //         00454a0b     XOR        EAX,EAX
    //         00454a0d     LEA        EDX=>info+0x4,[ESP + 0x18]
    //         00454a11     SCASB.RE   ES:EDI=>s_Age_of_Empires,_Roman_Expansion        = 41h
    //                                                                                  = "ge of Empires, Roman Expansion"
    //         00454a13     NOT        ECX
    //         00454a15     SUB        EDI,ECX
    //         00454a17     MOV        EAX,ECX
    //         00454a19     MOV        ESI,EDI
    //         00454a1b     MOV        EDI,EDX
    //                              main.cpp:75 (38)
    //         00454a1d     LEA        EDX=>info+0x69,[ESP + 0x7d]
    //         00454a21     SHR        ECX,0x2
    //         00454a24     MOVSD.REP  ES:EDI,ESI
    //         00454a26     MOV        ECX,EAX
    //         00454a28     XOR        EAX,EAX
    //         00454a2a     AND        ECX,0x3
    //         00454a2d     MOVSB.REP  ES:EDI,ESI
    //         00454a2f     MOV        EDI,s_00.03.01.0717                              = 30h
    //         00454a34     OR         ECX,0xffffffff
    //         00454a37     SCASB.RE   ES:EDI=>s_00.03.01.0717                          = 30h
    //                                                                                  = "0.03.01.0717"
    //         00454a39     NOT        ECX
    //         00454a3b     SUB        EDI,ECX
    //         00454a3d     MOV        EAX,ECX
    //         00454a3f     MOV        ESI,EDI
    //         00454a41     MOV        EDI,EDX
    //                              main.cpp:76 (35)
    //         00454a43     LEA        EDX=>info+0x7e,[ESP + 0x92]
    //         00454a4a     SHR        ECX,0x2
    //         00454a4d     MOVSD.REP  ES:EDI,ESI
    //         00454a4f     MOV        ECX,EAX
    //         00454a51     AND        ECX,0x3
    //         00454a54     MOVSB.REP  ES:EDI,ESI
    //         00454a56     LEA        ECX=>info+0x4,[ESP + 0x18]
    //         00454a5a     PUSH       ECX
    //         00454a5b     PUSH       s_%s                                             = "%s"
    //         00454a60     PUSH       EDX
    //         00454a61     CALL       sprintf                                          undefined sprintf()
    //                              main.cpp:77 (32)
    //         00454a66     MOV        EDI,s_tr_wrld.txt                                = 74h
    //         00454a6b     OR         ECX,0xffffffff
    //         00454a6e     XOR        EAX,EAX
    //         00454a70     ADD        ESP,0xc
    //         00454a73     SCASB.RE   ES:EDI=>s_tr_wrld.txt                            = 74h
    //                                                                                  = "r_wrld.txt"
    //         00454a75     NOT        ECX
    //         00454a77     SUB        EDI,ECX
    //         00454a79     LEA        EDX=>info+0xf7,[ESP + 0x10b]
    //         00454a80     MOV        EAX,ECX
    //         00454a82     MOV        ESI,EDI
    //         00454a84     MOV        EDI,EDX
    //                              main.cpp:78 (41)
    //         00454a86     LEA        EDX=>info+0x1fc,[ESP + 0x210]
    //         00454a8d     SHR        ECX,0x2
    //         00454a90     MOVSD.REP  ES:EDI,ESI
    //         00454a92     MOV        ECX,EAX
    //         00454a94     XOR        EAX,EAX
    //         00454a96     AND        ECX,0x3
    //         00454a99     MOVSB.REP  ES:EDI,ESI
    //         00454a9b     MOV        EDI,s_data2\empires.dat                          = 64h
    //         00454aa0     OR         ECX,0xffffffff
    //         00454aa3     SCASB.RE   ES:EDI=>s_data2\empires.dat                      = 64h
    //                                                                                  = "ata2\\empires.dat"
    //         00454aa5     NOT        ECX
    //         00454aa7     SUB        EDI,ECX
    //         00454aa9     MOV        EAX,ECX
    //         00454aab     MOV        ESI,EDI
    //         00454aad     MOV        EDI,EDX
    //                              main.cpp:83 (44)
    //         00454aaf     LEA        EDX=>info+0x41c,[ESP + 0x430]
    //         00454ab6     SHR        ECX,0x2
    //         00454ab9     MOVSD.REP  ES:EDI,ESI
    //         00454abb     MOV        ECX,EAX
    //         00454abd     AND        ECX,0x3
    //         00454ac0     MOVSB.REP  ES:EDI,ESI
    //         00454ac2     OR         ECX,0xffffffff
    //         00454ac5     MOV        EDI,s_Software\Microsoft\Games\Age_of_           = 53h
    //         00454aca     XOR        EAX,EAX
    //         00454acc     SCASB.RE   ES:EDI=>s_Software\Microsoft\Games\Age_of_       = 53h
    //                                                                                  = "oftware\\Microsoft\\Games\\Age of Empires\
    //         00454ace     NOT        ECX
    //         00454ad0     SUB        EDI,ECX
    //         00454ad2     MOV        EAX,ECX
    //         00454ad4     MOV        ESI,EDI
    //         00454ad6     SHR        ECX,0x2
    //         00454ad9     MOV        EDI,EDX
    //                              main.cpp:86 (43)
    //         00454adb     LEA        EDX=>info+0x51c,[ESP + 0x530]
    //         00454ae2     MOVSD.REP  ES:EDI,ESI
    //         00454ae4     MOV        ECX,EAX
    //         00454ae6     XOR        EAX,EAX
    //         00454ae8     AND        ECX,0x3
    //         00454aeb     MOVSB.REP  ES:EDI,ESI
    //         00454aed     MOV        EDI,dword ptr [ESP + Stack[0xc]]
    //         00454af4     OR         ECX,0xffffffff
    //         00454af7     SCASB.RE   ES:EDI
    //         00454af9     NOT        ECX
    //         00454afb     SUB        EDI,ECX
    //         00454afd     MOV        EAX,ECX
    //         00454aff     MOV        ESI,EDI
    //         00454b01     SHR        ECX,0x2
    //         00454b04     MOV        EDI,EDX
    //                              main.cpp:88 (38)
    //         00454b06     LEA        EDX=>info+0x620,[ESP + 0x634]
    //         00454b0d     MOVSD.REP  ES:EDI,ESI
    //         00454b0f     MOV        ECX,EAX
    //         00454b11     XOR        EAX,EAX
    //         00454b13     AND        ECX,0x3
    //         00454b16     MOVSB.REP  ES:EDI,ESI
    //         00454b18     OR         ECX,0xffffffff
    //         00454b1b     MOV        EDI,s_AppIcon                                    = 41h
    //         00454b20     SCASB.RE   ES:EDI=>s_AppIcon                                = 41h
    //                                                                                  = "ppIcon"
    //         00454b22     NOT        ECX
    //         00454b24     SUB        EDI,ECX
    //         00454b26     MOV        EAX,ECX
    //         00454b28     MOV        ESI,EDI
    //         00454b2a     MOV        EDI,EDX
    //                              main.cpp:89 (41)
    //         00454b2c     LEA        EDX=>info+0x649,[ESP + 0x65d]
    //         00454b33     SHR        ECX,0x2
    //         00454b36     MOVSD.REP  ES:EDI,ESI
    //         00454b38     MOV        ECX,EAX
    //         00454b3a     XOR        EAX,EAX
    //         00454b3c     AND        ECX,0x3
    //         00454b3f     MOVSB.REP  ES:EDI,ESI
    //         00454b41     MOV        EDI,s_                                           = ""
    //         00454b46     OR         ECX,0xffffffff
    //         00454b49     SCASB.RE   ES:EDI=>s_                                       = ""
    //         00454b4b     NOT        ECX
    //         00454b4d     SUB        EDI,ECX
    //         00454b4f     MOV        EAX,ECX
    //         00454b51     MOV        ESI,EDI
    //         00454b53     MOV        EDI,EDX
    //                              main.cpp:90 (41)
    //         00454b55     LEA        EDX=>info+0x672,[ESP + 0x686]
    //         00454b5c     SHR        ECX,0x2
    //         00454b5f     MOVSD.REP  ES:EDI,ESI
    //         00454b61     MOV        ECX,EAX
    //         00454b63     XOR        EAX,EAX
    //         00454b65     AND        ECX,0x3
    //         00454b68     MOVSB.REP  ES:EDI,ESI
    //         00454b6a     MOV        EDI,s_palette                                    = 70h
    //         00454b6f     OR         ECX,0xffffffff
    //         00454b72     SCASB.RE   ES:EDI=>s_palette                                = 70h
    //                                                                                  = "alette"
    //         00454b74     NOT        ECX
    //         00454b76     SUB        EDI,ECX
    //         00454b78     MOV        EAX,ECX
    //         00454b7a     MOV        ESI,EDI
    //         00454b7c     MOV        EDI,EDX
    //                              main.cpp:91 (48)
    //         00454b7e     LEA        EDX=>info+0x777,[ESP + 0x78b]
    //         00454b85     SHR        ECX,0x2
    //         00454b88     MOVSD.REP  ES:EDI,ESI
    //         00454b8a     MOV        ECX,EAX
    //         00454b8c     XOR        EAX,EAX
    //         00454b8e     AND        ECX,0x3
    //         00454b91     MOVSB.REP  ES:EDI,ESI
    //         00454b93     MOV        EDI,s_mcursors                                   = 6Dh
    //         00454b98     OR         ECX,0xffffffff
    //         00454b9b     SCASB.RE   ES:EDI=>s_mcursors                               = 6Dh
    //                                                                                  = "cursors"
    //         00454b9d     NOT        ECX
    //         00454b9f     SUB        EDI,ECX
    //         00454ba1     MOV        ESI,EDI
    //         00454ba3     MOV        EAX,ECX
    //         00454ba5     MOV        EDI,EDX
    //         00454ba7     SHR        ECX,0x2
    //         00454baa     MOVSD.REP  ES:EDI,ESI
    //         00454bac     MOV        ECX,EAX
    //                              main.cpp:99 (28)
    //         00454bae     XOR        EAX,EAX
    //         00454bb0     AND        ECX,0x3
    //         00454bb3     LEA        EDX=>info+0x301,[ESP + 0x315]
    //         00454bba     MOVSB.REP  ES:EDI,ESI
    //         00454bbc     MOV        EDI,s_AOE                                        = 41h
    //         00454bc1     OR         ECX,0xffffffff
    //         00454bc4     SCASB.RE   ES:EDI=>s_AOE                                    = 41h
    //                                                                                  = 4Fh
    //         00454bc6     NOT        ECX
    //         00454bc8     SUB        EDI,ECX
    //                              main.cpp:100 (8)
    //         00454bca     XOR        EBX,EBX
    //         00454bcc     MOV        EAX,ECX
    //         00454bce     MOV        ESI,EDI
    //         00454bd0     MOV        EDI,EDX
    //                              main.cpp:101 (12)
    //         00454bd2     MOV        EBP,0x1
    //         00454bd7     SHR        ECX,0x2
    //         00454bda     MOVSD.REP  ES:EDI,ESI
    //         00454bdc     MOV        ECX,EAX
    //                              main.cpp:107 (38)
    //         00454bde     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         00454be5     AND        ECX,0x3
    //         00454be8     MOV        EDX,0x3
    //         00454bed     MOVSB.REP  ES:EDI,ESI
    //         00454bef     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00454bf6     MOV        dword ptr [ESP + info.registry_key[0]],EAX
    //         00454bfd     MOV        dword ptr [ESP + info.prev_instance],ECX
    //                              main.cpp:108 (7)
    //         00454c04     MOV        ECX,dword ptr [ESP + Stack[0x10]]
    //                              main.cpp:134 (12)
    //         00454c0b     MOV        EAX,0x54
    //         00454c10     MOV        dword ptr [ESP + info.icon_name[0]],ECX
    //                              main.cpp:153 (57)
    //         00454c17     MOV        ECX,dword ptr [DAT_00570654]                     = 11D1EBE2h
    //         00454c1d     MOV        dword ptr [ESP + info.mouse_scroll_max_dist],EAX
    //         00454c24     MOV        dword ptr [ESP + info.key_scroll_max_dist],EAX
    //         00454c2b     MOV        EAX,[_TRIBE_GUID]                                = F2E846A8h
    //         00454c30     MOV        dword ptr [ESP + info+0x8f0],ECX
    //         00454c37     MOV        ECX,dword ptr [DAT_0057065c]                     = 08F50797h
    //         00454c3d     MOV        dword ptr [ESP + info+0x8ec],EAX
    //         00454c44     MOV        EAX,[DAT_00570658]                               = 60009B83h
    //         00454c49     MOV        dword ptr [ESP + info.zone_guid.Data1],ECX
    //                              main.cpp:154 (297)
    //         00454c50     MOV        ECX,dword ptr [DAT_00570664]                     = 11D1EBE2h
    //         00454c56     MOV        dword ptr [ESP + info+0x8f4],EAX
    //         00454c5d     MOV        EAX,[_ZONE_GUID]                                 = F2E846AAh
    //         00454c62     MOV        dword ptr [ESP + info+0x900],ECX
    //         00454c69     MOV        ECX,dword ptr [DAT_0057066c]                     = 08F50797h
    //         00454c6f     MOV        dword ptr [ESP + info+0x8fc],EAX
    //         00454c76     MOV        EAX,[DAT_00570668]                               = 60009B83h
    //         00454c7b     MOV        dword ptr [ESP + info.data_dir[0]],ECX
    //         00454c82     MOV        dword ptr [ESP + info.verify_cd],EBX
    //         00454c89     MOV        dword ptr [ESP + info.max_players_per_cd],EBP
    //         00454c90     MOV        dword ptr [ESP + info.instance],EDX
    //         00454c97     MOV        dword ptr [ESP + info.check_expiration],0x8
    //         00454ca2     MOV        dword ptr [ESP + info.expire_month],EBX
    //         00454ca9     MOV        word ptr [ESP + info.expire_year],BX
    //         00454cb1     MOV        word ptr [ESP + info+0x886],BX
    //         00454cb9     MOV        word ptr [ESP + info.update_interval],BX
    //         00454cc1     MOV        dword ptr [ESP + info.check_multi_copies],EBP
    //         00454cc8     MOV        dword ptr [ESP + info.skip_startup],EBP
    //         00454ccf     MOV        dword ptr [ESP + info.full_screen],EBX
    //         00454cd6     MOV        dword ptr [ESP + info.fixed_window_size],EBP
    //         00454cdd     MOV        dword ptr [ESP + info.use_dir_draw],EBP
    //         00454ce4     MOV        dword ptr [ESP + info.use_sys_mem],EBP
    //         00454ceb     MOV        dword ptr [ESP + info.use_music],EBX
    //         00454cf2     MOV        dword ptr [ESP + info.use_sound],EBP
    //         00454cf9     MOV        dword ptr [ESP + info.use_cd_audio],EBP
    //         00454d00     MOV        dword ptr [ESP + info.auto_scroll],EBP
    //         00454d07     MOV        dword ptr [ESP + info.mouse_scroll_edge],EBP
    //         00454d0e     MOV        dword ptr [ESP + info.mouse_scroll_interval],EDX
    //         00454d15     MOV        dword ptr [ESP + info.key_scroll_interval],0x4
    //         00454d20     MOV        dword ptr [ESP + info.key_scroll_object_move],
    //         00454d2b     MOV        dword ptr [ESP + info.interface_style],0x3d4cc
    //         00454d36     MOV        word ptr [ESP + info.main_wid],0x2
    //         00454d40     MOV        dword ptr [ESP + info.use_ima],EBX
    //         00454d47     MOV        dword ptr [ESP + info.use_midi],EBX
    //         00454d4e     MOV        dword ptr [ESP + info.use_wave_music],EBX
    //         00454d55     MOV        dword ptr [ESP + info.fast_view],EBX
    //         00454d5c     MOV        dword ptr [ESP + info.main_hgt],0x320
    //         00454d67     MOV        dword ptr [ESP + info.game_guid.Data1],0x258
    //         00454d72     MOV        dword ptr [ESP + info+0x904],EAX
    //                              main.cpp:156 (42)
    //         00454d79     LEA        ESI=>info+0x90c,[ESP + 0x920]
    //         00454d80     MOV        EDI,s_data2\                                     = 64h
    //         00454d85     OR         ECX,0xffffffff
    //         00454d88     XOR        EAX,EAX
    //         00454d8a     MOV        dword ptr [ESP + error_code],ESI
    //         00454d8e     SCASB.RE   ES:EDI=>s_data2\                                 = 64h
    //                                                                                  = "ata2\\"
    //         00454d90     NOT        ECX
    //         00454d92     SUB        EDI,ECX
    //         00454d94     MOV        EAX,ECX
    //         00454d96     MOV        ESI,EDI
    //         00454d98     MOV        EDI,dword ptr [ESP + error_code]
    //         00454d9c     SHR        ECX,0x2
    //         00454d9f     MOVSD.REP  ES:EDI,ESI=>s_data2\                             = 64h
    //         00454da1     MOV        ECX,EAX
    //                              main.cpp:157 (46)
    //         00454da3     XOR        EAX,EAX
    //         00454da5     AND        ECX,EDX
    //         00454da7     MOVSB.REP  ES:EDI,ESI=>s_data2\                             = 64h
    //         00454da9     OR         ECX,0xffffffff
    //         00454dac     MOV        EDI,s_sound\                                     = 73h
    //         00454db1     SCASB.RE   ES:EDI=>s_sound\                                 = 73h
    //                                                                                  = "ound\\"
    //         00454db3     NOT        ECX
    //         00454db5     SUB        EDI,ECX
    //         00454db7     LEA        ESI=>info+0xe25,[ESP + 0xe39]
    //         00454dbe     MOV        EAX,ECX
    //         00454dc0     MOV        dword ptr [ESP + error_code],ESI
    //         00454dc4     MOV        ESI,EDI
    //         00454dc6     MOV        EDI,dword ptr [ESP + error_code]
    //         00454dca     SHR        ECX,0x2
    //         00454dcd     MOVSD.REP  ES:EDI,ESI=>s_sound\                             = 73h
    //         00454dcf     MOV        ECX,EAX
    //                              main.cpp:158 (46)
    //         00454dd1     XOR        EAX,EAX
    //         00454dd3     AND        ECX,EDX
    //         00454dd5     MOVSB.REP  ES:EDI,ESI=>s_sound\                             = 73h
    //         00454dd7     MOV        EDI,s_                                           = ""
    //         00454ddc     OR         ECX,0xffffffff
    //         00454ddf     SCASB.RE   ES:EDI=>s_                                       = ""
    //         00454de1     NOT        ECX
    //         00454de3     SUB        EDI,ECX
    //         00454de5     LEA        ESI=>info+0xa11,[ESP + 0xa25]
    //         00454dec     MOV        EAX,ECX
    //         00454dee     MOV        dword ptr [ESP + error_code],ESI
    //         00454df2     MOV        ESI,EDI
    //         00454df4     MOV        EDI,dword ptr [ESP + error_code]
    //         00454df8     SHR        ECX,0x2
    //         00454dfb     MOVSD.REP  ES:EDI,ESI=>s_                                   = ""
    //         00454dfd     MOV        ECX,EAX
    //                              main.cpp:159 (46)
    //         00454dff     XOR        EAX,EAX
    //         00454e01     AND        ECX,EDX
    //         00454e03     MOVSB.REP  ES:EDI,ESI=>s_                                   = ""
    //         00454e05     MOV        EDI,s_savegame\                                  = 73h
    //         00454e0a     OR         ECX,0xffffffff
    //         00454e0d     SCASB.RE   ES:EDI=>s_savegame\                              = 73h
    //                                                                                  = "avegame\\"
    //         00454e0f     NOT        ECX
    //         00454e11     LEA        ESI=>info+0xb16,[ESP + 0xb2a]
    //         00454e18     SUB        EDI,ECX
    //         00454e1a     MOV        EAX,ECX
    //         00454e1c     MOV        dword ptr [ESP + error_code],ESI
    //         00454e20     MOV        ESI,EDI
    //         00454e22     MOV        EDI,dword ptr [ESP + error_code]
    //         00454e26     SHR        ECX,0x2
    //         00454e29     MOVSD.REP  ES:EDI,ESI=>s_savegame\                          = 73h
    //         00454e2b     MOV        ECX,EAX
    //                              main.cpp:160 (50)
    //         00454e2d     XOR        EAX,EAX
    //         00454e2f     AND        ECX,EDX
    //         00454e31     MOVSB.REP  ES:EDI,ESI=>s_savegame\                          = 73h
    //         00454e33     MOV        EDI,s_scenario\                                  = 73h
    //         00454e38     OR         ECX,0xffffffff
    //         00454e3b     SCASB.RE   ES:EDI=>s_scenario\                              = 73h
    //                                                                                  = "cenario\\"
    //         00454e3d     NOT        ECX
    //         00454e3f     LEA        ESI=>info+0xc1b,[ESP + 0xc2f]
    //         00454e46     SUB        EDI,ECX
    //         00454e48     MOV        EAX,ECX
    //         00454e4a     MOV        dword ptr [ESP + error_code],ESI
    //         00454e4e     MOV        ESI,EDI
    //         00454e50     MOV        EDI,dword ptr [ESP + error_code]
    //         00454e54     SHR        ECX,0x2
    //         00454e57     MOVSD.REP  ES:EDI,ESI=>s_scenario\                          = 73h
    //         00454e59     MOV        ECX,EAX
    //         00454e5b     AND        ECX,EDX
    //         00454e5d     MOVSB.REP  ES:EDI,ESI=>s_scenario\                          = 73h
    //                              main.cpp:161 (35)
    //         00454e5f     OR         ECX,0xffffffff
    //         00454e62     LEA        ESI=>info+0xd20,[ESP + 0xd34]
    //         00454e69     MOV        EDI,s_campaign\                                  = 63h
    //         00454e6e     XOR        EAX,EAX
    //         00454e70     SCASB.RE   ES:EDI=>s_campaign\                              = 63h
    //                                                                                  = "ampaign\\"
    //         00454e72     NOT        ECX
    //         00454e74     SUB        EDI,ECX
    //         00454e76     MOV        dword ptr [ESP + error_code],ESI
    //         00454e7a     MOV        EAX,ECX
    //         00454e7c     MOV        ESI,EDI
    //         00454e7e     MOV        EDI,dword ptr [ESP + error_code]
    //                              main.cpp:168 (200)
    //         00454e82     PUSH       0x1254
    //         00454e87     SHR        ECX,0x2
    //         00454e8a     MOVSD.REP  ES:EDI,ESI=>s_campaign\                          = 63h
    //         00454e8c     MOV        ECX,EAX
    //         00454e8e     XOR        EAX,EAX
    //         00454e90     AND        ECX,EDX
    //         00454e92     MOVSB.REP  ES:EDI,ESI=>s_campaign\                          = 63h
    //         00454e94     MOV        EDI,s_data2\                                     = 64h
    //         00454e99     OR         ECX,0xffffffff
    //         00454e9c     SCASB.RE   ES:EDI=>s_data2\                                 = 64h
    //                                                                                  = "ata2\\"
    //         00454e9e     NOT        ECX
    //         00454ea0     SUB        EDI,ECX
    //         00454ea2     LEA        ESI=>info+0xf2a,[ESP + 0xf42]
    //         00454ea9     MOV        EAX,ECX
    //         00454eab     MOV        dword ptr [ESP + error_code],ESI
    //         00454eaf     MOV        ESI,EDI
    //         00454eb1     MOV        EDI,dword ptr [ESP + error_code]
    //         00454eb5     SHR        ECX,0x2
    //         00454eb8     MOVSD.REP  ES:EDI,ESI=>s_data2\                             = 64h
    //         00454eba     MOV        ECX,EAX
    //         00454ebc     XOR        EAX,EAX
    //         00454ebe     AND        ECX,EDX
    //         00454ec0     MOVSB.REP  ES:EDI,ESI=>s_data2\                             = 64h
    //         00454ec2     MOV        EDI,s_data2\                                     = 64h
    //         00454ec7     OR         ECX,0xffffffff
    //         00454eca     SCASB.RE   ES:EDI=>s_data2\                                 = 64h
    //                                                                                  = "ata2\\"
    //         00454ecc     NOT        ECX
    //         00454ece     LEA        ESI=>info+0x102f,[ESP + 0x1047]
    //         00454ed5     SUB        EDI,ECX
    //         00454ed7     MOV        EAX,ECX
    //         00454ed9     MOV        dword ptr [ESP + error_code],ESI
    //         00454edd     MOV        ESI,EDI
    //         00454edf     MOV        EDI,dword ptr [ESP + error_code]
    //         00454ee3     SHR        ECX,0x2
    //         00454ee6     MOVSD.REP  ES:EDI,ESI=>s_data2\                             = 64h
    //         00454ee8     MOV        ECX,EAX
    //         00454eea     XOR        EAX,EAX
    //         00454eec     AND        ECX,EDX
    //         00454eee     MOVSB.REP  ES:EDI,ESI=>s_data2\                             = 64h
    //         00454ef0     MOV        EDI,s_avi\                                       = 61h
    //         00454ef5     OR         ECX,0xffffffff
    //         00454ef8     SCASB.RE   ES:EDI=>s_avi\                                   = 61h
    //                                                                                  = 005c6976
    //         00454efa     NOT        ECX
    //         00454efc     LEA        ESI=>info+0x1134,[ESP + 0x114c]
    //         00454f03     SUB        EDI,ECX
    //         00454f05     MOV        EAX,ECX
    //         00454f07     MOV        dword ptr [ESP + error_code],ESI
    //         00454f0b     MOV        ESI,EDI
    //         00454f0d     MOV        EDI,dword ptr [ESP + error_code]
    //         00454f11     SHR        ECX,0x2
    //         00454f14     MOVSD.REP  ES:EDI,ESI=>s_avi\                               = 61h
    //         00454f16     MOV        ECX,EAX
    //         00454f18     MOV        dword ptr [ESP + error_code],EBX
    //         00454f1c     AND        ECX,EDX
    //         00454f1e     MOVSB.REP  ES:EDI,ESI=>s_avi\                               = 61h
    //         00454f20     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00454f25     ADD        ESP,0x4
    //         00454f28     MOV        dword ptr [ESP + info.prog_name[0]],EAX
    //         00454f2c     CMP        EAX,EBX
    //         00454f2e     MOV        dword ptr [ESP + local_4],EBX
    //         00454f35     JZ         LAB_00454f48
    //         00454f37     LEA        ECX=>info+0x4,[ESP + 0x18]
    //         00454f3b     PUSH       EBP
    //         00454f3c     PUSH       ECX
    //         00454f3d     MOV        ECX,EAX
    //         00454f3f     CALL       TRIBE_Game::TRIBE_Game                           undefined TRIBE_Game(TRIBE_Game * this, RGE_P
    //         00454f44     MOV        ESI,EAX
    //         00454f46     JMP        LAB_00454f4a
    //                               LAB_00454f48                                                 XREF[1]:     00454f35(j)  
    //         00454f48     XOR        ESI,ESI
    //                               LAB_00454f4a                                                 XREF[1]:     00454f46(j)  
    //                              main.cpp:169 (15)
    //         00454f4a     CMP        ESI,EBX
    //         00454f4c     MOV        dword ptr [ESP + local_4],0xffffffff
    //         00454f57     JZ         LAB_00454fd2
    //                              main.cpp:171 (9)
    //         00454f59     MOV        EDI,dword ptr [ESI]
    //         00454f5b     MOV        ECX,ESI
    //         00454f5d     MOV        EAX,dword ptr [EDI + 0x18]
    //         00454f60     CALL       EAX
    //                              main.cpp:172 (8)
    //         00454f62     CMP        EAX,EBX
    //         00454f64     MOV        dword ptr [ESP + 0x14],EAX
    //         00454f68     JNZ        LAB_00454f7f
    //                              main.cpp:174 (5)
    //         00454f6a     MOV        ECX,ESI
    //         00454f6c     CALL       dword ptr [EDI + 0x4]
    //                              main.cpp:175 (9)
    //         00454f6f     MOV        ECX,ESI
    //         00454f71     MOV        dword ptr [ESP + 0x10],EAX
    //         00454f75     CALL       dword ptr [EDI + 0x18]
    //                              main.cpp:176 (5)
    //         00454f78     PUSH       EBP
    //         00454f79     MOV        ECX,ESI
    //         00454f7b     CALL       dword ptr [EDI]
    //                              main.cpp:179 (7)
    //         00454f7d     JMP        LAB_00454fd2
    //                               LAB_00454f7f                                                 XREF[1]:     00454f68(j)  
    //         00454f7f     CMP        EAX,0x4
    //         00454f82     JZ         LAB_00454fd2
    //                              main.cpp:181 (23)
    //         00454f84     LEA        EDX,[ESP + 0x1250]
    //         00454f8b     PUSH       0x100
    //         00454f90     PUSH       EDX=>DAT_fffffff8
    //                              language.dll match for 0x7d1: "Error"
    //         00454f91     PUSH       offset DAT_fffffff4
    //         00454f96     MOV        ECX,ESI
    //         00454f98     CALL       dword ptr [EDI + 0x20]
    //                              main.cpp:182 (25)
    //         00454f9b     LEA        EAX,[ESP + 0x1350]
    //         00454fa2     PUSH       0x100
    //         00454fa7     MOV        ECX,dword ptr [ESP + 0x18]
    //         00454fab     PUSH       EAX=>DAT_fffffff8
    //         00454fac     PUSH       EBX=>DAT_fffffff4
    //         00454fad     PUSH       ECX=>DAT_fffffff0
    //         00454fae     PUSH       EBP
    //         00454faf     MOV        ECX,ESI
    //         00454fb1     CALL       dword ptr [EDI + 0x28]
    //                              main.cpp:184 (5)
    //         00454fb4     PUSH       EBP
    //         00454fb5     MOV        ECX,ESI
    //         00454fb7     CALL       dword ptr [EDI]
    //                              main.cpp:187 (25)
    //         00454fb9     LEA        EDX,[ESP + 0x1250]
    //         00454fc0     PUSH       0x10
    //         00454fc2     LEA        EAX,[ESP + 0x1354]
    //         00454fc9     PUSH       EDX=>DAT_fffffff8
    //         00454fca     PUSH       EAX=>DAT_fffffff4
    //         00454fcb     PUSH       EBX=>DAT_fffffff0
    //         00454fcc     CALL       dword ptr [->USER32.DLL::MessageBoxA]            = 0048b00c
    //                               LAB_00454fd2                                                 XREF[3]:     00454f57(j), 00454f7d(j), 
    //                                                                                                         00454f82(j)  
    //                              main.cpp:192 (31)
    //         00454fd2     MOV        ECX,dword ptr [ESP + local_c]
    //         00454fd9     MOV        EAX,dword ptr [ESP + error_code]
    //         00454fdd     POP        EDI
    //         00454fde     POP        ESI
    //         00454fdf     POP        EBP
    //         00454fe0     MOV        dword ptr FS:[0x0],ECX
    //         00454fe7     POP        EBX
    //         00454fe8     ADD        ESP,0x144c
    //         00454fee     RET        0x10
}

