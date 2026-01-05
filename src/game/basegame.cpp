#include "../common.h"
#include "basegame.h"
#include <cstdio>
#include <io.h>   // _findfirst, _finddata_t
#include <new>    // std::nothrow

// --- Global Variable Definitions ---
// These are declared as 'extern' in basegame.h. We define them here.

// Logging and Debugging
int do_draw_log;
int safe_draw_log;
char draw_log_name[256];
FILE* draw_log;
class TDebuggingLog* L;

// Application State
HWND AppWnd;
HINSTANCE AppInst;
HMODULE StringTable;
RGE_Base_Game* rge_base_game;

// Subsystems
class TChat* chat;
class TCommunications_Handler* comm;
class TRegistry* Regs;
class TSound_Driver* sound_driver;
class DriveInformation* driveInfo;

// --- Constants ---
#ifndef SPI_GETSCREENSAVEACTIVE
#define SPI_GETSCREENSAVEACTIVE 0x0010
#endif
#ifndef SPI_SETSCREENSAVEACTIVE
#define SPI_SETSCREENSAVEACTIVE 0x0011
#endif
#ifndef SPI_GETPOWEROFFACTIVE
#define SPI_GETPOWEROFFACTIVE 0x0054
#endif
#ifndef SPI_SETPOWEROFFACTIVE
#define SPI_SETPOWEROFFACTIVE 0x0055
#endif

// --- Helper for VTable Calls ---
// Allows calling functions by raw vtable offset as seen in ASM
template<typename FuncSig>
FuncSig get_vfunc(void* this_ptr, int offset) {
    // Dereference the vptr (first 4 bytes), add offset, cast to function pointer
    return (FuncSig)(*(*(int**)this_ptr + (offset / 4)));
}


FILE* fps_log = nullptr;
int do_fps_log = 0;

int do_debug_random = 0;
int wrote_debug_random_log = 0;

int debugActions = 0;
FILE* actionFile = nullptr;

// Constants (from original data segment)
float GAME_SPEED_TO_FLOAT = 0.1f;   // DAT_0056f014 = 0x3DCCCCCD
float FLOAT_TO_GAME_SPEED = 10.0f;  // Likely inverse (not used in setup)


// --- Function Implementations ---

void write_draw_log(char* param_1) {
    // If the draw log file is open...
    if (draw_log) {
        // ...write the provided string to it.
        fprintf(draw_log, "%s", param_1);
        // and flush the buffer to ensure it's written to disk.
        fflush(draw_log);
    }
}

void write_draw_log2(char* param_1) {
    // If the draw log file is open...
    if (draw_log) {
        // ...write the string to it.
        fprintf(draw_log, "%s", param_1);
        // Close the file.
        fclose(draw_log);
        // Re-open the file in append+update mode ("a+"), effectively committing the previous write
        // and preparing for the next one.
        draw_log = fopen(draw_log_name, "a+");
    }
}

void debug_random_reset() {
    /* TODO: Stub */
//                              void __cdecl debug_random_reset(void)
//              void              <VOID>         <RETURN>
//                               ?debug_random_reset@@YAXXZ                                   XREF[1]:     new_game:0054279a(c)
//                               debug_random_reset
//                              basegame.cpp:6172 (5)
//         00423010     MOV        EAX,debug_random_log                             = 00000000
//                               LAB_00423015                                                 XREF[1]:     00423020(j)
//                              basegame.cpp:6174 (13)
//         00423015     MOV        byte ptr [EAX]=>debug_random_log,0x0             = 00000000
//         00423018     ADD        EAX=>null_005b2440,0x64                          = align(499800)
//         0042301b     CMP        EAX,do_draw_log
//         00423020     JL         LAB_00423015
//                              basegame.cpp:6175 (10)
//         00423022     MOV        dword ptr [debug_random_index],0xffffffff
//                              basegame.cpp:6176 (1)
//         0042302c     RET
//         0042302d     ??         90h
//         0042302e     NOP
//         0042302f     NOP
    return;
}

void debug_random_write() {
    /* TODO: Stub */
//                              void __cdecl debug_random_write(void)
//              void              <VOID>         <RETURN>
//                               ?debug_random_write@@YAXXZ                                   XREF[4]:     ~RGE_Base_Game:0041c295(c),
//                               debug_random_write                                                        do_command_game:0050a2ef(c),
//                                                                                                         quit_game:005241aa(c),
//                                                                                                         action_user_command:00529d02(c)
//                              basegame.cpp:6182 (1)
//         00423030     PUSH       EBX
//                              basegame.cpp:6183 (20)
//         00423031     PUSH       s_w                                              = "w"
//         00423036     PUSH       s_c:\aoerand.txt                                 = "c:\\aoerand.txt"
//         0042303b     CALL       fopen                                            undefined fopen()
//         00423040     MOV        EBX,EAX
//         00423042     ADD        ESP,0x8
//                              basegame.cpp:6184 (6)
//         00423045     TEST       EBX,EBX
//         00423047     JZ         LAB_00423097
//         00423049     PUSH       EDI
//         0042304a     PUSH       ESI
//                              basegame.cpp:6186 (2)
//         0042304b     XOR        EDI,EDI
//                              basegame.cpp:6191 (19)
//         0042304d     MOV        ESI,debug_random_log                             = 00000000
//                               LAB_00423052                                                 XREF[1]:     00423080(j)
//         00423052     MOV        EAX,[debug_random_index]
//         00423057     CMP        EDI,EAX
//         00423059     MOV        EAX,s_>                                          = 3Eh
//         0042305e     JZ         LAB_00423065
//                              basegame.cpp:6187 (34)
//         00423060     MOV        EAX,s__                                          = 20h
//                               LAB_00423065                                                 XREF[1]:     0042305e(j)
//         00423065     PUSH       ESI=>debug_random_log                            = 00000000
//         00423066     PUSH       EDI
//         00423067     PUSH       EAX=>s__                                         = 20h
//                                                                                  = 3Eh
//         00423068     PUSH       s_%s%d_-_%s_                                     = "%s%d - %s\n"
//         0042306d     PUSH       EBX
//         0042306e     CALL       fprintf                                          undefined fprintf()
//         00423073     ADD        ESP,0x14
//         00423076     ADD        ESI,0x64
//         00423079     INC        EDI
//         0042307a     CMP        ESI,do_draw_log
//         00423080     JL         LAB_00423052
//                              basegame.cpp:6188 (9)
//         00423082     PUSH       EBX
//         00423083     CALL       fclose                                           undefined fclose()
//         00423088     ADD        ESP,0x4
//                              basegame.cpp:6189 (12)
//         0042308b     MOV        dword ptr [wrote_debug_random_log],0x1
//         00423095     POP        ESI
//         00423096     POP        EDI
//                               LAB_00423097                                                 XREF[1]:     00423047(j)
//                              basegame.cpp:6191 (2)
//         00423097     POP        EBX
//         00423098     RET
//         00423099     ??         90h
//         0042309a     NOP
//         0042309b     NOP
//         0042309c     NOP
//         0042309d     NOP
//         0042309e     NOP
//         0042309f     NOP
    return;
}

int debug_rand(char* param_1, int param_2) {
    /* TODO: Stub */
//                              int __cdecl debug_rand(char * param_1, int param_2)
//              int               EAX:4          <RETURN>
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     004230bd(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     004230f7(R)
//              char[9]           Stack[-0x10]:9 temp_name                 XREF[0,4]:   004230c5(*), 004230d7(*), 00423103(*), 004230e8(*)
//                               ?debug_rand@@YAHPADH@Z                                       XREF[245]:   closestUndiscoveredTile:00416024(c
//                               debug_rand                                                                create_terrain_object:00458a19(c),
//                                                                                                         create_terrain_object:00458a52(c),
//                                                                                                         create_terrain_object:00458a88(c),
//                                                                                                         place_terrain_object:00458dac(c),
//                                                                                                         place_terrain_object:00458de3(c),
//                                                                                                         place_terrain_object:00458e19(c),
//                                                                                                         place_terrain_object:00458f13(c),
//                                                                                                         place_terrain_object:00458f4a(c),
//                                                                                                         base_land_generate:004857f9(c),
//                                                                                                         base_land_generate:004858d8(c),
//                                                                                                         base_land_generate:00485963(c),
//                                                                                                         base_land_generate:004859e2(c),
//                                                                                                         base_land_generate:00485a65(c),
//                                                                                                         make_placement_stack:00486072(c),
//                                                                                                         make_placement_stack:004860a0(c),
//                                                                                                         place_group:00486aa7(c),
//                                                                                                         play:004bc331(c),
//                                                                                                         objectToAttack:004dcbc2(c),
//                                                                                                         make_new_cliff:00510182(c), [more]
//                              basegame.cpp:6197 (4)
//         004230a0     SUB        ESP,0xc
//         004230a3     PUSH       EDI
//                              basegame.cpp:6200 (7)
//         004230a4     CALL       rand                                             undefined rand()
//         004230a9     MOV        EDI,EAX
//                              basegame.cpp:6202 (18)
//         004230ab     MOV        EAX,[do_debug_random]
//         004230b0     TEST       EAX,EAX
//         004230b2     JZ         LAB_00423133
//         004230b4     MOV        EAX,[debug_random_on]
//         004230b9     TEST       EAX,EAX
//         004230bb     JZ         LAB_00423133
//                              basegame.cpp:6206 (12)
//         004230bd     MOV        EAX,dword ptr [ESP + param_1]
//         004230c1     PUSH       ESI
//         004230c2     ADD        EAX,0xa
//         004230c5     LEA        EDX=>temp_name[4],[ESP + 0x8]
//                              basegame.cpp:6208 (14)
//         004230c9     MOV        CL,byte ptr [EAX]
//         004230cb     LEA        ESI,[EAX + 0x8]
//         004230ce     CMP        CL,0x2e
//         004230d1     JZ         LAB_004230e3
//                               LAB_004230d3                                                 XREF[1]:     004230e1(j)
//         004230d3     CMP        EAX,ESI
//         004230d5     JNC        LAB_004230e3
//                              basegame.cpp:6210 (5)
//         004230d7     MOV        byte ptr [EDX]=>temp_name[4],CL
//         004230d9     MOV        CL,byte ptr [EAX + 0x1]
//                              basegame.cpp:6211 (1)
//         004230dc     INC        EDX
//                              basegame.cpp:6212 (6)
//         004230dd     INC        EAX
//         004230de     CMP        CL,0x2e
//         004230e1     JNZ        LAB_004230d3
//                               LAB_004230e3                                                 XREF[2]:     004230d1(j), 004230d5(j)
//                              basegame.cpp:6216 (15)
//         004230e3     MOV        EAX,[debug_random_index]
//         004230e8     MOV        byte ptr [EDX]=>temp_name[5],0x0
//         004230eb     CMP        EAX,0x1387
//         004230f0     JGE        LAB_004230f5
//                              basegame.cpp:6217 (1)
//         004230f2     INC        EAX
//                              basegame.cpp:6218 (2)
//         004230f3     JMP        LAB_004230f7
//                               LAB_004230f5                                                 XREF[1]:     004230f0(j)
//                              basegame.cpp:6219 (2)
//         004230f5     XOR        EAX,EAX
//                               LAB_004230f7                                                 XREF[1]:     004230f3(j)
//                              basegame.cpp:6221 (60)
//         004230f7     MOV        ECX,dword ptr [ESP + param_2]
//         004230fb     PUSH       EDI
//         004230fc     PUSH       ECX
//         004230fd     MOV        ECX,dword ptr [rge_base_game]                    = 00000000
//         00423103     LEA        EDX=>temp_name[4],[ESP + 0x10]
//         00423107     MOV        [debug_random_index],EAX
//         0042310c     PUSH       EDX
//         0042310d     MOV        EDX,dword ptr [ECX + 0x3f4]
//         00423113     LEA        EAX,[EAX + EAX*0x4]
//         00423116     MOV        ECX,dword ptr [EDX + 0x4]
//         00423119     LEA        EDX,[EAX + EAX*0x4]
//         0042311c     PUSH       ECX
//         0042311d     PUSH       s_t%d,%s,l%d,r%d                                 = "t%d,%s,l%d,r%d"
//         00423122     LEA        EAX,[EDX*0x4 + debug_random_log]                 = 00000000
//         00423129     PUSH       EAX=>debug_random_log                            = 00000000
//         0042312a     CALL       sprintf                                          undefined sprintf()
//         0042312f     ADD        ESP,0x18
//         00423132     POP        ESI
//                               LAB_00423133                                                 XREF[2]:     004230b2(j), 004230bb(j)
//                              basegame.cpp:6224 (2)
//         00423133     MOV        EAX,EDI
//                              basegame.cpp:6225 (5)
//         00423135     POP        EDI
//         00423136     ADD        ESP,0xc
//         00423139     RET
//         0042313a     ??         90h
//         0042313b     NOP
//         0042313c     NOP
//         0042313d     NOP
//         0042313e     NOP
//         0042313f     NOP
    return 0;
}

void debug_srand(char* param_1, int param_2, uint param_3) {
    /* TODO: Stub */
//                              void __cdecl debug_srand(char * param_1, int param_2, uint param_3)
//              void              <VOID>         <RETURN>
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     0042315a(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00423194(R)
//              uint              Stack[0xc]:4   param_3                   XREF[1]:     0042314b(R)
//              char[9]           Stack[-0x10]:9 temp_name                 XREF[0,4]:   00423162(*), 00423174(*), 004231a0(*), 00423185(*)
//                               ?debug_srand@@YAXPADHI@Z                                     XREF[20]:    setup:0041bade(c),
//                               debug_srand                                                               SetRandomSeed:0042ca50(c),
//                                                                                                         GetRandomSeed:0042caba(c),
//                                                                                                         map_generate2:0045790d(c),
//                                                                                                         map_generate2:0045793a(c),
//                                                                                                         map_generate2:00457966(c),
//                                                                                                         init_vars:004a109a(c),
//                                                                                                         recycle_in_to_game:004c157a(c),
//                                                                                                         setup:004c182a(c),
//                                                                                                         update:004c3e53(c),
//                                                                                                         set_object_state:004c87c5(c),
//                                                                                                         update:00512601(c),
//                                                                                                         loadAIInformation:005159a5(c),
//                                                                                                         notify:00515ab1(c),
//                                                                                                         notify:00515b78(c),
//                                                                                                         create_game:00527173(c),
//                                                                                                         new_game:00542805(c),
//                                                                                                         new_scenario:00542c2d(c),
//                                                                                                         update:00542f7b(c),
//                                                                                                         update:00543127(c)
//                              basegame.cpp:6231 (26)
//         00423140     MOV        EAX,[do_debug_random]
//         00423145     SUB        ESP,0xc
//         00423148     TEST       EAX,EAX
//         0042314a     PUSH       EDI
//         0042314b     MOV        EDI,dword ptr [ESP + param_3]
//         0042314f     JZ         LAB_004231d0
//         00423151     MOV        EAX,[debug_random_on]
//         00423156     TEST       EAX,EAX
//         00423158     JZ         LAB_004231d0
//                              basegame.cpp:6238 (12)
//         0042315a     MOV        EAX,dword ptr [ESP + param_1]
//         0042315e     PUSH       ESI
//         0042315f     ADD        EAX,0xa
//         00423162     LEA        EDX=>temp_name[4],[ESP + 0x8]
//                              basegame.cpp:6240 (14)
//         00423166     MOV        CL,byte ptr [EAX]
//         00423168     LEA        ESI,[EAX + 0x8]
//         0042316b     CMP        CL,0x2e
//         0042316e     JZ         LAB_00423180
//                               LAB_00423170                                                 XREF[1]:     0042317e(j)
//         00423170     CMP        EAX,ESI
//         00423172     JNC        LAB_00423180
//                              basegame.cpp:6242 (5)
//         00423174     MOV        byte ptr [EDX]=>temp_name[4],CL
//         00423176     MOV        CL,byte ptr [EAX + 0x1]
//                              basegame.cpp:6243 (1)
//         00423179     INC        EDX
//                              basegame.cpp:6244 (6)
//         0042317a     INC        EAX
//         0042317b     CMP        CL,0x2e
//         0042317e     JNZ        LAB_00423170
//                               LAB_00423180                                                 XREF[2]:     0042316e(j), 00423172(j)
//                              basegame.cpp:6248 (15)
//         00423180     MOV        EAX,[debug_random_index]
//         00423185     MOV        byte ptr [EDX]=>temp_name[5],0x0
//         00423188     CMP        EAX,0x1387
//         0042318d     JGE        LAB_00423192
//                              basegame.cpp:6249 (1)
//         0042318f     INC        EAX
//                              basegame.cpp:6250 (2)
//         00423190     JMP        LAB_00423194
//                               LAB_00423192                                                 XREF[1]:     0042318d(j)
//                              basegame.cpp:6251 (2)
//         00423192     XOR        EAX,EAX
//                               LAB_00423194                                                 XREF[1]:     00423190(j)
//                              basegame.cpp:6253 (60)
//         00423194     MOV        ECX,dword ptr [ESP + param_2]
//         00423198     PUSH       EDI
//         00423199     PUSH       ECX
//         0042319a     MOV        ECX,dword ptr [rge_base_game]                    = 00000000
//         004231a0     LEA        EDX=>temp_name[4],[ESP + 0x10]
//         004231a4     MOV        [debug_random_index],EAX
//         004231a9     PUSH       EDX
//         004231aa     MOV        EDX,dword ptr [ECX + 0x3f4]
//         004231b0     LEA        EAX,[EAX + EAX*0x4]
//         004231b3     MOV        ECX,dword ptr [EDX + 0x4]
//         004231b6     LEA        EDX,[EAX + EAX*0x4]
//         004231b9     PUSH       ECX
//         004231ba     PUSH       s_t%d,%s,l%d,s%u                                 = "t%d,%s,l%d,s%u"
//         004231bf     LEA        EAX,[EDX*0x4 + debug_random_log]                 = 00000000
//         004231c6     PUSH       EAX=>debug_random_log                            = 00000000
//         004231c7     CALL       sprintf                                          undefined sprintf()
//         004231cc     ADD        ESP,0x18
//         004231cf     POP        ESI
//                               LAB_004231d0                                                 XREF[2]:     0042314f(j), 00423158(j)
//                              basegame.cpp:6256 (9)
//         004231d0     PUSH       EDI
//         004231d1     CALL       srand                                            undefined srand()
//         004231d6     ADD        ESP,0x4
//                              basegame.cpp:6257 (5)
//         004231d9     POP        EDI
//         004231da     ADD        ESP,0xc
//         004231dd     RET
//         004231de     ??         90h
//         004231df     NOP
    return;
}

ulong debug_timeGetTime(char* param_1, int param_2) {
    /* TODO: Stub */
//                              ulong __cdecl debug_timeGetTime(char * param_1, int param_2)
//              ulong             EAX:4          <RETURN>
//              char *            Stack[0x4]:4   param_1
//              int               Stack[0x8]:4   param_2
//                               ?debug_timeGetTime@@YAKPADH@Z                                XREF[228]:   StoreForResend:0042a517(c),
//                               debug_timeGetTime                                                         CommOut:0042b54b(c),
//                                                                                                         CommOut:0042b580(c),
//                                                                                                         CommOut:0042b67f(c),
//                                                                                                         CommOut:0042b6b8(c),
//                                                                                                         CommOut:0042b78b(c),
//                                                                                                         check_for_duplicate_orders:0043528
//                                                                                                         submit:00435302(c),
//                                                                                                         Time:004363ae(c),
//                                                                                                         OpenLog:004364de(c),
//                                                                                                         handle_idle:0046579d(c),
//                                                                                                         handle_idle:00476f44(c),
//                                                                                                         handle_idle:00476f84(c),
//                                                                                                         show_message:00479357(c),
//                                                                                                         Skip:0048051a(c),
//                                                                                                         Skip:00480529(c),
//                                                                                                         handle_idle:004ab75c(c),
//                                                                                                         play:004bc448(c),
//                                                                                                         shape_hit_test:004c0dd8(c),
//                                                                                                         shape_hit_test:004c0e25(c), [more]
//                              basegame.cpp:6263 (18)
//         004231e0     MOV        EAX,[do_debug_timeGetTime]
//         004231e5     TEST       EAX,EAX
//         004231e7     JZ         LAB_00423222
//         004231e9     MOV        EAX,[debug_timeGetTime_on]
//         004231ee     TEST       EAX,EAX
//         004231f0     JZ         LAB_00423222
//                              basegame.cpp:6269 (5)
//         004231f2     MOV        EAX,[debug_timeGetTime_cnt]
//                              basegame.cpp:6270 (16)
//         004231f7     MOV        ECX,dword ptr [debug_timeGetTime_interval]       = 5h
//         004231fd     INC        EAX
//         004231fe     CMP        EAX,ECX
//         00423200     MOV        [debug_timeGetTime_cnt],EAX
//         00423205     JNZ        LAB_0042321c
//                              basegame.cpp:6272 (5)
//         00423207     MOV        EAX,[debug_timeGetTime_time]
//                              basegame.cpp:6273 (16)
//         0042320c     MOV        dword ptr [debug_timeGetTime_cnt],0x0
//         00423216     INC        EAX
//         00423217     MOV        [debug_timeGetTime_time],EAX
//                               LAB_0042321c                                                 XREF[1]:     00423205(j)
//                              basegame.cpp:6277 (5)
//         0042321c     MOV        EAX,[debug_timeGetTime_time]
//                              basegame.cpp:6281 (1)
//         00423221     RET
//                               LAB_00423222                                                 XREF[2]:     004231e7(j), 004231f0(j)
//                              basegame.cpp:6280 (6)
//         00423222     JMP        dword ptr [->WINMM.DLL::timeGetTime]
//         00423228     ??         90h
//         00423229     NOP
//         0042322a     NOP
//         0042322b     NOP
//         0042322c     NOP
//         0042322d     NOP
//         0042322e     NOP
//         0042322f     NOP
    return 0;
}

RGE_Base_Game::RGE_Base_Game(RGE_Prog_Info* param_1, int param_2) {
    // The constructor logic is extensive. We will initialize members and globals
    // in the same order as the original assembly code.

    // Initialize member variables. The compiler will handle setting the vftable.
    this->player_game_info = nullptr;
    this->random_game_seed = -1;
    this->random_map_seed = -1;
    this->save_random_game_seed = -1;
    this->save_random_map_seed = -1;
    this->quick_build = 0;

    // Initialize logging globals
    do_draw_log = 0;
    safe_draw_log = 0;
    draw_log_name[0] = '\0';
    draw_log = nullptr;

    // Call setters to establish default game options
    this->setVersion(1.0f);
    this->setScenarioGame(0);
    this->setCampaignGame(0);
    this->setSavedGame(0);
    this->setSinglePlayerGame(1);
    this->setMultiplayerGame(0);
    this->setMapSize(96, 96, 8); // 0x60, 0x60, 0x8
    this->setAllowCheatCodes(0);
    this->setCheatNotification(1);
    this->setFullVisibility(0);
    this->setFogOfWar(1);
    this->setColoredChat(1);
    this->setGameDeveloperMode(0);
    this->setDifficulty(0);

    // Loop to initialize per-player settings (9 players max)
    for (int i = 0; i < 9; ++i) {
        this->setPlayerCDAndVersion(i, 0);
        this->setPlayerHasCD(i, 0);
        this->setPlayerVersion(i, 0);
        this->setPlayerTeam(i, 1);
    }

    // Set more game options
    this->setPathFinding(0);
    this->setMpPathFinding(0);
    this->setNumberPlayers(4);
    this->setScenarioName((char*)"");

    // Set the static global instance pointer to this object
    rge_base_game = this;

    // Initialize a large block of member variables
    this->prog_info = param_1;
    this->prog_window = nullptr;
    this->prog_ready = 0;
    this->prog_active = 1;
    this->prog_palette = nullptr;
    // prog_mutex (0x20) is not initialized here in the assembly
    this->window_style = 0;
    this->screen_saver_enabled = 0;
    // low_power_enabled (0x3C) is not initialized
    this->error_code = 0;
    this->is_timer = 0;
    this->draw_system = nullptr;
    this->draw_area = nullptr;
    this->outline_type = 2;
    this->custom_mouse = 0;
    // shape_num (0x58) is not initialized
    this->shapes = nullptr;
    this->sound_system = nullptr;
    this->music_system = nullptr;
    this->sound_num = 0;
    this->sounds = nullptr;
    this->save_music_type = 0;
    this->save_music_track_from = 0;
    this->save_music_track_to = 0;
    this->save_music_cur_track = 0;
    this->save_music_file[0] = '\0';
    this->save_music_loop = 0;
    this->save_music_pos = 0;
    this->comm_handler = nullptr;
    this->comm_syncstop = 0;
    this->comm_droppackets = 0;
    this->comm_syncmsg = 0;
    this->comm_stepmode = 0;
    this->comm_speed = 1;
    this->debugLog = nullptr;
    this->log_comm = 0;
    this->registry = nullptr;
    this->prog_mode = 0;
    this->game_mode = 0;
    this->sub_game_mode = 0;
    this->paused = 0;
    this->mouse_pointer = nullptr;
    this->erase_mouse = 0;
    this->mouse_blit_sync = 0;
    this->is_mouse_on = 1;
    this->windows_mouse = 1;
    this->input_enabled = 1; // Based on ESI=1 being used for other "on" values
    // input_disabled_window (0x1DC) not initialized
    this->font_num = 0;
    this->fonts = nullptr;
    this->world = nullptr;
    this->render_all = 1;
    this->master_obj_id = -1;
    this->terrain_id = -1;
    this->elevation_height = -1;
    this->brush_size = 1;
    this->timing_text[0] = '\0';
    this->frame_count = 0;
    this->world_update_count = 0;
    this->view_update_count = 0;
    this->last_frame_count = 0;
    this->last_world_update_count = 0;
    this->last_view_update_count = 0;
    this->fps = 0;
    this->world_update_fps = 0;
    this->view_update_fps = 0;
    this->do_show_timings = 0;
    this->do_show_comm = 0;
    this->do_show_ai = 0;
    this->last_view_time = 0;
    this->save_check_for_cd = 1;
    // This is weirdly out of order in the asm, but belongs to the block
    this->scenario_info = nullptr; 

    // Windows API Calls
    this->mouse_cursor = LoadCursorA(NULL, IDC_ARROW);
    GetCurrentDirectoryA(sizeof(this->work_dir), this->work_dir);
    strcpy_s(this->string_dll_name, sizeof(this->string_dll_name), "language.dll");

    // Initialize timing structures
    memset(this->timings, 0, sizeof(this->timings));

    // Initialize more global variables
    L = nullptr;
    StringTable = nullptr; // Note: StringTable is an HMODULE
    // AppWnd is set to NULL/0 in assembly
    AppWnd = nullptr;
    if (this->prog_info) {
        AppInst = (HINSTANCE)this->prog_info->instance;
    } else {
        AppInst = nullptr;
    }
    chat = nullptr;
    comm = nullptr;
    Regs = nullptr;
    sound_driver = nullptr;
    driveInfo = nullptr;

    // Loop to initialize more per-player members
    for (int i = 0; i < 9; ++i) {
        this->playerIDValue[i] = 0;
        this->resigned[i] = 0;
    }

    // Final member initializations
    this->auto_paused = 0;
    this->rollover = 1;
    this->map_save_area = nullptr;
    this->game_speed = 1.0f;
    this->single_player_difficulty = 2;

    // Perform initial setup and handle errors
    if (!this->setup_registry()) {
        this->error_code = 14;
        return;
    }

    Regs = this->registry;

    if (!this->setup_debugging_log()) {
        this->error_code = 15;
        return;
    }

    L = this->debugLog;

    // The second parameter to the constructor is a flag to run setup immediately
    if (param_2 != 0) {
        if (!this->setup()) {
            // Only set error code 1 if no other error has occurred
            if (this->error_code == 0) {
                this->error_code = 1;
            }
        }
    }

    this->display_selected_ids = 0;
}

int RGE_Base_Game::setup() {
    // Match original debug calls (they used the hardcoded source path/line).
    static const char* const kBasegamePath = "C:\\msdev\\work\\age1_x1\\basegame.cpp";
    const ulong seed = debug_timeGetTime((char*)kBasegamePath, 0x20A);
    debug_srand((char*)kBasegamePath, 0x20A, seed);

    // --- Read registry settings ---

    // Screen Size: allowed values in asm: 640, 800, 1024, 1280 (width),
    // with height paired to 480, 600, 768, 1024 respectively.
    {
        int screenW = this->registry->RegGetInt(1, (char*)"Screen Size");
        if (screenW == 0x280) { // 640
            this->prog_info->main_wid = 0x280;
            this->prog_info->main_hgt = 0x1E0; // 480
        } else if (screenW == 0x320) { // 800
            this->prog_info->main_wid = 0x320;
            this->prog_info->main_hgt = 0x258; // 600
        } else if (screenW == 0x400) { // 1024
            this->prog_info->main_wid = 0x400;
            this->prog_info->main_hgt = 0x300; // 768
        } else if (screenW == 0x500) { // 1280
            this->prog_info->main_wid = 0x500;
            this->prog_info->main_hgt = 0x400; // 1024
        }
    }

    // Rollover Text: if == 2 => rollover = 0, else rollover = 1
    {
        int roll = this->registry->RegGetInt(1, (char*)"Rollover Text");
        this->rollover = (roll == 2) ? 0 : 1;
    }

    // Mouse Style: if == 2 => interface_style = 2, else if == 1 => 1
    {
        int ms = this->registry->RegGetInt(1, (char*)"Mouse Style");
        if (ms == 2) {
            this->prog_info->interface_style = 2;
        } else if (ms == 1) {
            this->prog_info->interface_style = 1;
        }
    }

    // Game Speed: if not -1 => game_speed = value * 0.1
    {
        int gs = this->registry->RegGetInt(1, (char*)"Game Speed");
        if (gs != -1) {
            this->game_speed = (float)gs * GAME_SPEED_TO_FLOAT;
        }
    }

    // Difficulty: if not -1 => set single_player_difficulty
    {
        int diff = this->registry->RegGetInt(1, (char*)"Difficulty");
        if (diff != -1) {
            this->single_player_difficulty = diff;
        }
    }

    // Path Finding: allowed 1..3, stored internally as 0..2 (value-1)
    {
        int pf = this->registry->RegGetInt(1, (char*)"Path Finding");
        if (pf >= 1 && pf <= 3) {
            this->setPathFinding((uchar)(pf - 1));
        }
    }

    // MP Path Finding: allowed 1..3, stored internally as 0..2 (value-1)
    {
        int mp = this->registry->RegGetInt(1, (char*)"MP Path Finding");
        if (mp >= 1 && mp <= 3) {
            this->setMpPathFinding((uchar)(mp - 1));
        }
    }

    // Scroll Speed: if not -1 and within [10..200], copy into both intervals
    {
        int ss = this->registry->RegGetInt(1, (char*)"Scroll Speed");
        if (ss != -1 && ss >= 10 && ss <= 200) {
            this->prog_info->mouse_scroll_interval = (ulong)ss;
            this->prog_info->key_scroll_interval   = (ulong)ss;
        }
    }

    // --- Verify empires.exe exists ---
    {
        _finddata_t file_info;
        intptr_t h = _findfirst("empires.exe", &file_info);
        if (h == -1) {
            this->error_code = 0x17;
            return 0;
        }
        // Original code does not _findclose(h); keep behavior.
    }

    // --- Call vtable function at offset 0x64; if fails => error 2 ---
    // We cannot reliably map this to a named virtual without the exact MSVC vftable layout.
    {
        // TODO: Resolve VTable Index 0x19 (Offset 0x64)
        int ok = (*((int(__thiscall **)(RGE_Base_Game*))(*(int*)this + 0x64)))(this);
        if (ok == 0) {
            this->error_code = 2;
            return 0;
        }
    }

    // --- Load language DLL ---
    StringTable = LoadLibraryA(this->string_dll_name);
    if (!StringTable) {
        this->error_code = 1;
        return 0;
    }

    // --- Memory sanity check ---
    {
        MEMORYSTATUS ms;
        ms.dwLength = sizeof(ms);
        GlobalMemoryStatus(&ms);

        const DWORD totalPageFile = ms.dwTotalPageFile;
        const DWORD totalVirtual  = ms.dwTotalVirtual;

        // This matches the (slightly odd) original threshold logic exactly.
        const bool lowMem =
            (((totalPageFile < 0x01400000) || (totalVirtual < 0x00A00000)) &&
             ((totalPageFile < 0x00A00000) || (totalVirtual < 0x01400000)) &&
             (totalVirtual < 0x01E00000));

        if (lowMem) {
            this->error_code = 0x16;
            return 0;
        }
    }

    // --- vtable call at 0x140 (no return checked) ---
    {
        // TODO: Resolve VTable Index 0x50 (Offset 0x140)
        (*((void(__thiscall **)(RGE_Base_Game*))(*(int*)this + 0x140)))(this);
    }

    // --- Optional action logging ---
    if (debugActions == 1) {
        actionFile = fopen("c:\\aoeact.txt", "w");
    }

    // --- Expiration / multicopy checks (gated by prog_info flags) ---
    if (this->prog_info->check_expiration) {
        if (this->check_expiration() == 0) {
            this->error_code = 3;
            return 0;
        }
    }

    if (this->prog_info->check_multi_copies) {
        if (this->check_multi_copies() == 0) {
            this->error_code = 4;
            return 0;
        }
    }

    // --- DirectX version check (unless NODXCHECK argument present) ---
    if (this->check_prog_argument((char*)"NODXCHECK") == 0) {
        ulong dxVersion = 0;
        ulong dxPlatform = 0;

        // Based on the assembly push order, DXVersion appears to be the primary value checked.
        GetDXVersion(&dxVersion, &dxPlatform);

        if (dxVersion < 0x501) {
            this->error_code = 0x14;
            return 0;
        }
    }

    // --- Disable screen saver / low power if enabled ---
    SystemParametersInfoA(0x10, 0, &this->screen_saver_enabled, 0); // SPI_GETSCREENSAVEACTIVE
    if (this->screen_saver_enabled) {
        SystemParametersInfoA(0x11, 0, 0, 2); // SPI_SETSCREENSAVEACTIVE (disable), SPIF_SENDCHANGE
    }

    SystemParametersInfoA(0x53, 0, &this->low_power_enabled, 0); // SPI_GETLOWPOWERACTIVE
    if (this->low_power_enabled) {
        SystemParametersInfoA(0x55, 0, 0, 2); // SPI_SETLOWPOWERACTIVE (disable), SPIF_SENDCHANGE
    }

    // --- Check for CD (saved) ---
    this->save_check_for_cd = this->check_for_cd(0);

    // --- Big setup chain (all via vtable offsets) ---
    // Error codes match original assembly.
    {
        // TODO: Resolve VTable Index 0x1A (Offset 0x68)
        int ok = (*((int(__thiscall **)(RGE_Base_Game*))(*(int*)this + 0x68)))(this);
        if (!ok) { this->error_code = 5; return 0; }

        // TODO: Resolve VTable Index 0x1B (Offset 0x6C)
        ok = (*((int(__thiscall **)(RGE_Base_Game*))(*(int*)this + 0x6C)))(this);
        if (!ok) { this->error_code = 6; return 0; }

        // TODO: Resolve VTable Index 0x1C (Offset 0x70)
        ok = (*((int(__thiscall **)(RGE_Base_Game*))(*(int*)this + 0x70)))(this);
        if (!ok) {
            // If some other code already set an error, keep it; otherwise set 7.
            if (this->error_code == 0) {
                this->error_code = 7;
            }
            return 0;
        }

        // TODO: Resolve VTable Index 0x1D (Offset 0x74)
        ok = (*((int(__thiscall **)(RGE_Base_Game*))(*(int*)this + 0x74)))(this);
        if (!ok) { this->error_code = 0x11; return 0; }

        // TODO: Resolve VTable Index 0x26 (Offset 0x98)
        ok = (*((int(__thiscall **)(RGE_Base_Game*))(*(int*)this + 0x98)))(this);
        if (!ok) { this->error_code = 7; return 0; }

        // TODO: Resolve VTable Index 0x4F (Offset 0x13C)
        ok = (*((int(__thiscall **)(RGE_Base_Game*))(*(int*)this + 0x13C)))(this);
        if (!ok) { this->error_code = 7; return 0; }

        // TODO: Resolve VTable Index 0x1E (Offset 0x78)
        ok = (*((int(__thiscall **)(RGE_Base_Game*))(*(int*)this + 0x78)))(this);
        if (!ok) { this->error_code = 8; return 0; }

        // TODO: Resolve VTable Index 0x23 (Offset 0x8C)
        ok = (*((int(__thiscall **)(RGE_Base_Game*))(*(int*)this + 0x8C)))(this);
        if (!ok) { this->error_code = 0x0A; return 0; }

        // TODO: Resolve VTable Index 0x21 (Offset 0x84)
        ok = (*((int(__thiscall **)(RGE_Base_Game*))(*(int*)this + 0x84)))(this);
        if (!ok) { this->error_code = 0x10; return 0; }

        // TODO: Resolve VTable Index 0x22 (Offset 0x88)
        ok = (*((int(__thiscall **)(RGE_Base_Game*))(*(int*)this + 0x88)))(this);
        if (!ok) { this->error_code = 9; return 0; }

        // TODO: Resolve VTable Index 0x24 (Offset 0x90)
        ok = (*((int(__thiscall **)(RGE_Base_Game*))(*(int*)this + 0x90)))(this);
        if (!ok) { this->error_code = 0x0B; return 0; }

        // TODO: Resolve VTable Index 0x25 (Offset 0x94)
        ok = (*((int(__thiscall **)(RGE_Base_Game*))(*(int*)this + 0x94)))(this);
        if (!ok) { this->error_code = 0x0C; return 0; }
    }

    // --- Drive information object (global) ---
    driveInfo = new (std::nothrow) DriveInformation();
    if (!driveInfo) {
        // Original simply bails out without setting a specific error.
        return 0;
    }

    // TODO: Resolve VTable Index 0x27 (Offset 0x9C)
    {
        int ok = (*((int(__thiscall **)(RGE_Base_Game*))(*(int*)this + 0x9C)))(this);
        if (!ok) {
            this->error_code = 0x0D;
            return 0;
        }
    }

    // TODO: Resolve VTable Index 0x03 (Offset 0x0C) — takes an int argument (0)
    (*((void(__thiscall **)(RGE_Base_Game*, int))(*(int*)this + 0x0C)))(this, 0);

    // TODO: Resolve VTable Index 0x28 (Offset 0xA0)
    (*((void(__thiscall **)(RGE_Base_Game*))(*(int*)this + 0xA0)))(this);

    // TODO: Resolve VTable Index 0x39 (Offset 0xE4) — called with (prog_window,0,0,0)
    (*((void(__thiscall **)(RGE_Base_Game*, void*, int, int, int))(*(int*)this + 0xE4)))(
        this, this->prog_window, 0, 0, 0);

    // --- Final window/timer bring-up ---
    this->prog_ready = 1;
    ShowWindow((HWND)this->prog_window, 5);
    SetFocus((HWND)this->prog_window);
    this->mouse_on();

    this->is_timer = (int)SetTimer((HWND)this->prog_window, 1, 0x32, 0);

    // --- Create player_game_info (game%d.nfo) ---
    {
        _finddata_t file_info;

        int regNum = this->registry->RegGetInt(0, (char*)"Game File Number");
        char filename[260];

        if (regNum >= 0) {
            // Original re-reads the value.
            int n = this->registry->RegGetInt(0, (char*)"Game File Number");
            sprintf(filename, "game%d.nfo", n);

            this->player_game_info = new (std::nothrow) RGE_Game_Info(filename);
        } else {
            // Find first unused in [0..9998]
            for (int i = 0; i < 9999; ++i) {
                sprintf(filename, "game%d.nfo", i);
                intptr_t h = _findfirst(filename, &file_info);
                if (h == -1) {
                    this->registry->RegSetInt(0, (char*)"Game File Number", i);
                    this->player_game_info = new (std::nothrow) RGE_Game_Info(filename);
                    break;
                }
                // Original does not _findclose(h); keep behavior.
            }
        }
    }

    // --- Create scenario_info (%sscenario.inf) ---
    {
        char filename[260];
        sprintf(filename, "%sscenario.inf", this->prog_info->scenario_dir);
        this->scenario_info = new (std::nothrow) RGE_Scenario_File_Info(filename);
    }

    // --- Draw logging setup (optional) ---
    if (do_draw_log) {
        if (draw_log_name[0] == '\0') {
            _OFSTRUCT of;
            char s[256];

            for (int i = 0; i < 1000; ++i) {
                sprintf(s, "drawlog%d.txt", i);

                // OpenFile with OF_EXIST (0x4000). Returns HFILE_ERROR (-1) if not found.
                HFILE hf = OpenFile(s, &of, 0x4000);
                if (hf == (HFILE)-1) {
                    draw_log = fopen(s, "w");

                    // Assembly does a raw byte copy into draw_log_name.
                    // Keep it simple but safe.
                    strncpy(draw_log_name, s, sizeof(draw_log_name) - 1);
                    draw_log_name[sizeof(draw_log_name) - 1] = '\0';
                    break;
                }
            }
        } else {
            draw_log = fopen(draw_log_name, "w");
        }
    }

    // --- FPS logging setup (optional) ---
    if (do_fps_log) {
        fps_log = fopen("c:\\fps.txt", "w");
        if (!fps_log) {
            do_fps_log = 0;
        }
    }

    return 1;
}


RGE_Base_Game::~RGE_Base_Game() {
    /* TODO: Stub */
//                              void __thiscall ~RGE_Base_Game(RGE_Base_Game * this)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              char[256]         Stack[-0x104   str
//              char[13]          Stack[-0x114   filename                  XREF[0,2]:   0041c428(*), 0041c43a(*)
//                               ??1RGE_Base_Game@@UAE@XZ                                     XREF[2]:     `vector_deleting_destructor':0041b
//                               RGE_Base_Game::~RGE_Base_Game                                             ~TRIBE_Game:005215fb(c)
//                              basegame.cpp:877 (11)
//         0041c270     SUB        ESP,0x110
//         0041c276     PUSH       EBX
//         0041c277     PUSH       EBP
//         0041c278     PUSH       ESI
//         0041c279     MOV        ESI,this
//                              basegame.cpp:882 (26)
//         0041c27b     XOR        EBX,EBX
//         0041c27d     PUSH       EDI
//         0041c27e     MOV        dword ptr [ESI],RGE_Base_Game::`vftable'         = 0041ba80
//         0041c284     MOV        EAX,[do_debug_random]
//         0041c289     CMP        EAX,EBX
//         0041c28b     JZ         LAB_0041c29f
//         0041c28d     CMP        dword ptr [wrote_debug_random_log],EBX
//         0041c293     JNZ        LAB_0041c29f
//                              basegame.cpp:884 (5)
//         0041c295     CALL       debug_random_write                               void debug_random_write(void)
//                              basegame.cpp:885 (5)
//         0041c29a     CALL       dump_vismap_log                                  void dump_vismap_log(void)
//                               LAB_0041c29f                                                 XREF[2]:     0041c28b(j), 0041c293(j)
//                              basegame.cpp:891 (7)
//         0041c29f     MOV        EAX,dword ptr [ESI + 0x48]
//         0041c2a2     CMP        EAX,EBX
//         0041c2a4     JZ         LAB_0041c2bc
//                              basegame.cpp:892 (22)
//         0041c2a6     MOV        EAX,dword ptr [EAX + 0x2c]
//         0041c2a9     MOV        this,dword ptr [ESI + 0x1ac]
//         0041c2af     PUSH       EAX
//         0041c2b0     PUSH       s_Screen_Size                                    = "Screen Size"
//         0041c2b5     PUSH       0x1
//         0041c2b7     CALL       TRegistry::RegSetInt                             int RegSetInt(TRegistry * this, int param_1,
//                               LAB_0041c2bc                                                 XREF[1]:     0041c2a4(j)
//                              basegame.cpp:896 (32)
//         0041c2bc     MOV        this,dword ptr [ESI + 0xa08]
//         0041c2c2     NEG        this
//         0041c2c4     SBB        this,this
//         0041c2c6     ADD        this,0x2
//         0041c2c9     PUSH       this
//         0041c2ca     MOV        this,dword ptr [ESI + 0x1ac]
//         0041c2d0     PUSH       s_Rollover_Text                                  = "Rollover Text"
//         0041c2d5     PUSH       0x1
//         0041c2d7     CALL       TRegistry::RegSetInt                             int RegSetInt(TRegistry * this, int param_1,
//                              basegame.cpp:899 (13)
//         0041c2dc     MOV        EDX,dword ptr [ESI + 0xc]
//         0041c2df     CMP        word ptr [EDX + 0x8dc],0x2
//         0041c2e7     JNZ        LAB_0041c2ed
//                              basegame.cpp:900 (2)
//         0041c2e9     PUSH       0x2
//                              basegame.cpp:901 (2)
//         0041c2eb     JMP        LAB_0041c2ef
//                               LAB_0041c2ed                                                 XREF[1]:     0041c2e7(j)
//                              basegame.cpp:902 (20)
//         0041c2ed     PUSH       0x1
//                               LAB_0041c2ef                                                 XREF[1]:     0041c2eb(j)
//         0041c2ef     MOV        this,dword ptr [ESI + 0x1ac]
//         0041c2f5     PUSH       s_Mouse_Style                                    = "Mouse Style"
//         0041c2fa     PUSH       0x1
//         0041c2fc     CALL       TRegistry::RegSetInt                             int RegSetInt(TRegistry * this, int param_1,
//                              basegame.cpp:908 (36)
//         0041c301     FLD        float ptr [ESI + 0xa0c]
//         0041c307     FMUL       float ptr [DAT_0056f018]
//         0041c30d     CALL       __ftol                                           undefined __ftol()
//         0041c312     MOV        this,dword ptr [ESI + 0x1ac]
//         0041c318     PUSH       EAX
//         0041c319     PUSH       s_Game_Speed                                     = "Game Speed"
//         0041c31e     PUSH       0x1
//         0041c320     CALL       TRegistry::RegSetInt                             int RegSetInt(TRegistry * this, int param_1,
//                              basegame.cpp:910 (25)
//         0041c325     MOV        EAX,dword ptr [ESI + 0xa10]
//         0041c32b     MOV        this,dword ptr [ESI + 0x1ac]
//         0041c331     PUSH       EAX
//         0041c332     PUSH       s_Difficulty                                     = "Difficulty"
//         0041c337     PUSH       0x1
//         0041c339     CALL       TRegistry::RegSetInt                             int RegSetInt(TRegistry * this, int param_1,
//                              basegame.cpp:912 (32)
//         0041c33e     MOV        this,ESI
//         0041c340     CALL       RGE_Base_Game::pathFinding                       uchar pathFinding(RGE_Base_Game * this)
//         0041c345     MOV        this,dword ptr [ESI + 0x1ac]
//         0041c34b     AND        EAX,0xff
//         0041c350     INC        EAX
//         0041c351     PUSH       EAX
//         0041c352     PUSH       s_Path_Finding                                   = "Path Finding"
//         0041c357     PUSH       0x1
//         0041c359     CALL       TRegistry::RegSetInt                             int RegSetInt(TRegistry * this, int param_1,
//                              basegame.cpp:913 (32)
//         0041c35e     MOV        this,ESI
//         0041c360     CALL       RGE_Base_Game::mpPathFinding                     uchar mpPathFinding(RGE_Base_Game * this)
//         0041c365     MOV        this,dword ptr [ESI + 0x1ac]
//         0041c36b     AND        EAX,0xff
//         0041c370     INC        EAX
//         0041c371     PUSH       EAX
//         0041c372     PUSH       s_MP_Path_Finding                                = "MP Path Finding"
//         0041c377     PUSH       0x1
//         0041c379     CALL       TRegistry::RegSetInt                             int RegSetInt(TRegistry * this, int param_1,
//                              basegame.cpp:915 (28)
//         0041c37e     MOV        this,dword ptr [ESI + 0xc]
//         0041c381     MOV        EDX,dword ptr [ECX + this+0x8c8]
//         0041c387     MOV        this,dword ptr [ESI + 0x1ac]
//         0041c38d     PUSH       EDX
//         0041c38e     PUSH       s_Scroll_Speed                                   = "Scroll Speed"
//         0041c393     PUSH       0x1
//         0041c395     CALL       TRegistry::RegSetInt                             int RegSetInt(TRegistry * this, int param_1,
//                              basegame.cpp:920 (9)
//         0041c39a     MOV        EAX,[actionFile]                                 = 00000000
//         0041c39f     CMP        EAX,EBX
//         0041c3a1     JZ         LAB_0041c3b2
//                              basegame.cpp:922 (9)
//         0041c3a3     PUSH       EAX
//         0041c3a4     CALL       fclose                                           undefined fclose()
//         0041c3a9     ADD        ESP,0x4
//                              basegame.cpp:923 (6)
//         0041c3ac     MOV        dword ptr [actionFile],EBX                       = 00000000
//                               LAB_0041c3b2                                                 XREF[1]:     0041c3a1(j)
//                              basegame.cpp:927 (9)
//         0041c3b2     MOV        EAX,[fps_log]                                    = 00000000
//         0041c3b7     CMP        EAX,EBX
//         0041c3b9     JZ         LAB_0041c3ca
//                              basegame.cpp:929 (9)
//         0041c3bb     PUSH       EAX
//         0041c3bc     CALL       fclose                                           undefined fclose()
//         0041c3c1     ADD        ESP,0x4
//                              basegame.cpp:930 (6)
//         0041c3c4     MOV        dword ptr [fps_log],EBX                          = 00000000
//                               LAB_0041c3ca                                                 XREF[1]:     0041c3b9(j)
//                              basegame.cpp:933 (9)
//         0041c3ca     MOV        EAX,[draw_log]                                   = 00000000
//         0041c3cf     CMP        EAX,EBX
//         0041c3d1     JZ         LAB_0041c3e2
//                              basegame.cpp:935 (9)
//         0041c3d3     PUSH       EAX
//         0041c3d4     CALL       fclose                                           undefined fclose()
//         0041c3d9     ADD        ESP,0x4
//                              basegame.cpp:936 (6)
//         0041c3dc     MOV        dword ptr [draw_log],EBX                         = 00000000
//                               LAB_0041c3e2                                                 XREF[1]:     0041c3d1(j)
//                              basegame.cpp:939 (7)
//         0041c3e2     MOV        EDI,dword ptr [ESI + 0x8]
//         0041c3e5     CMP        EDI,EBX
//         0041c3e7     JZ         LAB_0041c3fc
//                              basegame.cpp:941 (16)
//         0041c3e9     MOV        this,EDI
//         0041c3eb     CALL       RGE_Scenario_File_Info::~RGE_Scenario_File_Info  void ~RGE_Scenario_File_Info(RGE_Scenario_Fil
//         0041c3f0     PUSH       EDI
//         0041c3f1     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0041c3f6     ADD        ESP,0x4
//                              basegame.cpp:942 (3)
//         0041c3f9     MOV        dword ptr [ESI + 0x8],EBX
//                               LAB_0041c3fc                                                 XREF[1]:     0041c3e7(j)
//                              basegame.cpp:945 (5)
//         0041c3fc     CMP        dword ptr [ESI + 0x4],EBX
//         0041c3ff     JZ         LAB_0041c461
//                              basegame.cpp:947 (21)
//         0041c401     MOV        this,dword ptr [ESI + 0x1ac]
//         0041c407     PUSH       s_Game_File_Number                               = "Game File Number"
//         0041c40c     PUSH       EBX
//         0041c40d     CALL       TRegistry::RegGetInt                             int RegGetInt(TRegistry * this, int param_1,
//         0041c412     TEST       EAX,EAX
//         0041c414     JL         LAB_0041c447
//                              basegame.cpp:949 (36)
//         0041c416     MOV        this,dword ptr [ESI + 0x1ac]
//         0041c41c     PUSH       s_Game_File_Number                               = "Game File Number"
//         0041c421     PUSH       EBX
//         0041c422     CALL       TRegistry::RegGetInt                             int RegGetInt(TRegistry * this, int param_1,
//         0041c427     PUSH       EAX
//         0041c428     LEA        EAX=>filename[4],[ESP + 0x14]
//         0041c42c     PUSH       s_game%d.nfo                                     = "game%d.nfo"
//         0041c431     PUSH       EAX
//         0041c432     CALL       sprintf                                          undefined sprintf()
//         0041c437     ADD        ESP,0xc
//                              basegame.cpp:950 (13)
//         0041c43a     LEA        this=>filename[4],[ESP + 0x10]
//         0041c43e     PUSH       this
//         0041c43f     MOV        this,dword ptr [ESI + 0x4]
//         0041c442     CALL       RGE_Game_Info::save                              void save(RGE_Game_Info * this, char * param_1)
//                               LAB_0041c447                                                 XREF[1]:     0041c414(j)
//                              basegame.cpp:952 (23)
//         0041c447     MOV        EDI,dword ptr [ESI + 0x4]
//         0041c44a     CMP        EDI,EBX
//         0041c44c     JZ         LAB_0041c45e
//         0041c44e     MOV        this,EDI
//         0041c450     CALL       RGE_Game_Info::~RGE_Game_Info                    void ~RGE_Game_Info(RGE_Game_Info * this)
//         0041c455     PUSH       EDI
//         0041c456     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0041c45b     ADD        ESP,0x4
//                               LAB_0041c45e                                                 XREF[1]:     0041c44c(j)
//                              basegame.cpp:953 (3)
//         0041c45e     MOV        dword ptr [ESI + 0x4],EBX
//                               LAB_0041c461                                                 XREF[1]:     0041c3ff(j)
//                              basegame.cpp:958 (16)
//         0041c461     MOV        this,dword ptr [ESI + 0x3f4]
//         0041c467     MOV        dword ptr [ESI + 0x1b0],EBX
//         0041c46d     CMP        this,EBX
//         0041c46f     JZ         LAB_0041c481
//                              basegame.cpp:960 (10)
//         0041c471     MOV        EDX,dword ptr [this->_padding_]
//         0041c473     PUSH       0x1
//         0041c475     CALL       dword ptr [EDX + 0xa0]
//                              basegame.cpp:961 (6)
//         0041c47b     MOV        dword ptr [ESI + 0x3f4],EBX
//                               LAB_0041c481                                                 XREF[1]:     0041c46f(j)
//                              basegame.cpp:964 (10)
//         0041c481     MOV        EDI,dword ptr [ESI + 0xa20]
//         0041c487     CMP        EDI,EBX
//         0041c489     JZ         LAB_0041c4a1
//                              basegame.cpp:966 (16)
//         0041c48b     MOV        this,EDI
//         0041c48d     CALL       TDrawArea::~TDrawArea                            void ~TDrawArea(TDrawArea * this)
//         0041c492     PUSH       EDI
//         0041c493     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0041c498     ADD        ESP,0x4
//                              basegame.cpp:967 (6)
//         0041c49b     MOV        dword ptr [ESI + 0xa20],EBX
//                               LAB_0041c4a1                                                 XREF[1]:     0041c489(j)
//                              basegame.cpp:970 (10)
//         0041c4a1     MOV        EDI,dword ptr [ESI + 0x1c0]
//         0041c4a7     CMP        EDI,EBX
//         0041c4a9     JZ         LAB_0041c4c1
//                              basegame.cpp:972 (16)
//         0041c4ab     MOV        this,EDI
//         0041c4ad     CALL       TMousePointer::~TMousePointer                    void ~TMousePointer(TMousePointer * this)
//         0041c4b2     PUSH       EDI
//         0041c4b3     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0041c4b8     ADD        ESP,0x4
//                              basegame.cpp:973 (6)
//         0041c4bb     MOV        dword ptr [ESI + 0x1c0],EBX
//                               LAB_0041c4c1                                                 XREF[1]:     0041c4a9(j)
//                              basegame.cpp:976 (9)
//         0041c4c1     MOV        EAX,[driveInfo]                                  = 00000000
//         0041c4c6     CMP        EAX,EBX
//         0041c4c8     JZ         LAB_0041c4d9
//                              basegame.cpp:978 (9)
//         0041c4ca     PUSH       EAX
//         0041c4cb     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0041c4d0     ADD        ESP,0x4
//                              basegame.cpp:979 (6)
//         0041c4d3     MOV        dword ptr [driveInfo],EBX                        = 00000000
//                               LAB_0041c4d9                                                 XREF[1]:     0041c4c8(j)
//                              basegame.cpp:982 (10)
//         0041c4d9     MOV        EDI,dword ptr [ESI + 0x18c]
//         0041c4df     CMP        EDI,EBX
//         0041c4e1     JZ         LAB_0041c4f9
//                              basegame.cpp:984 (16)
//         0041c4e3     MOV        this,EDI
//         0041c4e5     CALL       TCommunications_Handler::~TCommunications_Hand   void ~TCommunications_Handler(TCommunications
//         0041c4ea     PUSH       EDI
//         0041c4eb     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0041c4f0     ADD        ESP,0x4
//                              basegame.cpp:985 (6)
//         0041c4f3     MOV        dword ptr [ESI + 0x18c],EBX
//                               LAB_0041c4f9                                                 XREF[1]:     0041c4e1(j)
//                              basegame.cpp:988 (10)
//         0041c4f9     MOV        EDI,dword ptr [chat]                             = 00000000
//         0041c4ff     CMP        EDI,EBX
//         0041c501     JZ         LAB_0041c519
//                              basegame.cpp:990 (16)
//         0041c503     MOV        this,EDI
//         0041c505     CALL       TChat::~TChat                                    void ~TChat(TChat * this)
//         0041c50a     PUSH       EDI
//         0041c50b     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0041c510     ADD        ESP,0x4
//                              basegame.cpp:991 (6)
//         0041c513     MOV        dword ptr [chat],EBX                             = 00000000
//                               LAB_0041c519                                                 XREF[1]:     0041c501(j)
//                              basegame.cpp:994 (8)
//         0041c519     CMP        dword ptr [ESI + 0x1e4],EBX
//         0041c51f     JZ         LAB_0041c56a
//                              basegame.cpp:996 (11)
//         0041c521     XOR        EBP,EBP
//         0041c523     CMP        word ptr [ESI + 0x1e0],BX
//         0041c52a     JLE        LAB_0041c555
//                              basegame.cpp:1083 (39)
//         0041c52c     MOV        EBX,dword ptr [->GDI32.DLL::DeleteObject]        = 0048b160
//         0041c532     XOR        EDI,EDI
//                               LAB_0041c534                                                 XREF[1]:     0041c551(j)
//         0041c534     MOV        EAX,dword ptr [ESI + 0x1e4]
//         0041c53a     MOV        EAX,dword ptr [EAX + EDI*0x1]
//         0041c53d     TEST       EAX,EAX
//         0041c53f     JZ         LAB_0041c544
//         0041c541     PUSH       EAX
//         0041c542     CALL       EBX=>GDI32.DLL::DeleteObject
//                               LAB_0041c544                                                 XREF[1]:     0041c53f(j)
//         0041c544     MOVSX      this,word ptr [ESI + 0x1e0]
//         0041c54b     INC        EBP
//         0041c54c     ADD        EDI,0xc
//         0041c54f     CMP        EBP,this
//         0041c551     JL         LAB_0041c534
//                              basegame.cpp:996 (2)
//         0041c553     XOR        EBX,EBX
//                               LAB_0041c555                                                 XREF[1]:     0041c52a(j)
//                              basegame.cpp:1001 (15)
//         0041c555     MOV        EDX,dword ptr [ESI + 0x1e4]
//         0041c55b     PUSH       EDX
//         0041c55c     CALL       free                                             undefined free()
//         0041c561     ADD        ESP,0x4
//                              basegame.cpp:1002 (6)
//         0041c564     MOV        dword ptr [ESI + 0x1e4],EBX
//                               LAB_0041c56a                                                 XREF[1]:     0041c51f(j)
//                              basegame.cpp:1005 (7)
//         0041c56a     MOV        this,ESI
//         0041c56c     CALL       RGE_Base_Game::stop_sound_system                 void stop_sound_system(RGE_Base_Game * this)
//                              basegame.cpp:1007 (15)
//         0041c571     PUSH       s_Blank_Screen                                   = "Blank Screen"
//         0041c576     MOV        this,panel_system
//         0041c57b     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              basegame.cpp:1009 (7)
//         0041c580     MOV        EDI,dword ptr [ESI + 0x48]
//         0041c583     CMP        EDI,EBX
//         0041c585     JZ         LAB_0041c59d
//                              basegame.cpp:1011 (16)
//         0041c587     MOV        this,EDI
//         0041c589     CALL       TDrawSystem::~TDrawSystem                        void ~TDrawSystem(TDrawSystem * this)
//         0041c58e     PUSH       EDI
//         0041c58f     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0041c594     ADD        ESP,0x4
//                              basegame.cpp:1012 (3)
//         0041c597     MOV        dword ptr [ESI + 0x48],EBX
//                              basegame.cpp:1013 (3)
//         0041c59a     MOV        dword ptr [ESI + 0x4c],EBX
//                               LAB_0041c59d                                                 XREF[1]:     0041c585(j)
//                              basegame.cpp:1017 (13)
//         0041c59d     MOV        EAX,dword ptr [ESI + 0x38]
//         0041c5a0     MOV        EDI,dword ptr [->USER32.DLL::SystemParametersI   = 0048acf0
//         0041c5a6     CMP        EAX,EBX
//         0041c5a8     JZ         LAB_0041c5b3
//                              basegame.cpp:1018 (9)
//         0041c5aa     PUSH       0x2
//         0041c5ac     PUSH       EBX=>DAT_fffffff8
//         0041c5ad     PUSH       offset DAT_fffffff4
//         0041c5af     PUSH       offset DAT_fffffff0
//         0041c5b1     CALL       EDI=>USER32.DLL::SystemParametersInfoA
//                               LAB_0041c5b3                                                 XREF[1]:     0041c5a8(j)
//                              basegame.cpp:1020 (5)
//         0041c5b3     CMP        dword ptr [ESI + 0x3c],EBX
//         0041c5b6     JZ         LAB_0041c5c1
//                              basegame.cpp:1021 (9)
//         0041c5b8     PUSH       0x2
//         0041c5ba     PUSH       EBX=>DAT_fffffff8
//         0041c5bb     PUSH       offset DAT_fffffff4
//         0041c5bd     PUSH       offset DAT_fffffff0
//         0041c5bf     CALL       EDI=>USER32.DLL::SystemParametersInfoA
//                               LAB_0041c5c1                                                 XREF[1]:     0041c5b6(j)
//                              basegame.cpp:1023 (7)
//         0041c5c1     MOV        EAX,dword ptr [ESI + 0x1c]
//         0041c5c4     CMP        EAX,EBX
//         0041c5c6     JZ         LAB_0041c5d6
//                              basegame.cpp:1025 (11)
//         0041c5c8     PUSH       EAX
//         0041c5c9     MOV        this,panel_system
//         0041c5ce     CALL       TPanelSystem::release_palette                    void release_palette(TPanelSystem * this, voi
//                              basegame.cpp:1027 (3)
//         0041c5d3     MOV        dword ptr [ESI + 0x1c],EBX
//                               LAB_0041c5d6                                                 XREF[1]:     0041c5c6(j)
//                              basegame.cpp:1030 (10)
//         0041c5d6     MOV        EDI,dword ptr [ESI + 0x1ac]
//         0041c5dc     CMP        EDI,EBX
//         0041c5de     JZ         LAB_0041c5f6
//                              basegame.cpp:1032 (16)
//         0041c5e0     MOV        this,EDI
//         0041c5e2     CALL       TRegistry::~TRegistry                            void ~TRegistry(TRegistry * this)
//         0041c5e7     PUSH       EDI
//         0041c5e8     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0041c5ed     ADD        ESP,0x4
//                              basegame.cpp:1033 (6)
//         0041c5f0     MOV        dword ptr [ESI + 0x1ac],EBX
//                               LAB_0041c5f6                                                 XREF[1]:     0041c5de(j)
//                              basegame.cpp:1036 (7)
//         0041c5f6     MOV        EAX,dword ptr [ESI + 0x20]
//         0041c5f9     CMP        EAX,EBX
//         0041c5fb     JZ         LAB_0041c607
//                              basegame.cpp:1038 (7)
//         0041c5fd     PUSH       EAX
//         0041c5fe     CALL       dword ptr [->KERNEL32.DLL::CloseHandle]          = 0048aa26
//                              basegame.cpp:1039 (3)
//         0041c604     MOV        dword ptr [ESI + 0x20],EBX
//                               LAB_0041c607                                                 XREF[1]:     0041c5fb(j)
//                              basegame.cpp:1042 (6)
//         0041c607     MOV        dword ptr [rge_base_game],EBX                    = 00000000
//                              basegame.cpp:1044 (7)
//         0041c60d     MOV        EAX,dword ptr [ESI + 0x10]
//         0041c610     CMP        EAX,EBX
//         0041c612     JZ         LAB_0041c61b
//                              basegame.cpp:1045 (7)
//         0041c614     PUSH       EAX
//         0041c615     CALL       dword ptr [->USER32.DLL::DestroyWindow]          = 0048ad26
//                               LAB_0041c61b                                                 XREF[1]:     0041c612(j)
//                              basegame.cpp:1048 (22)
//         0041c61b     LEA        EAX,[ESP + 0x20]
//         0041c61f     PUSH       0x100
//         0041c624     PUSH       EAX=>DAT_fffffff8
//                              language.dll match for 0x3eb: "Age of Empires Help"
//         0041c625     PUSH       offset DAT_fffffff4
//         0041c62a     MOV        this,ESI
//         0041c62c     CALL       RGE_Base_Game::get_string                        char * get_string(RGE_Base_Game * this, long
//                              basegame.cpp:1049 (8)
//         0041c631     MOV        AL,byte ptr [ESP + 0x20]
//         0041c635     TEST       AL,AL
//         0041c637     JZ         LAB_0041c658
//                              basegame.cpp:1051 (16)
//         0041c639     LEA        this,[ESP + 0x20]
//         0041c63d     PUSH       this
//         0041c63e     PUSH       s_MS_WINHELP                                     = "MS_WINHELP"
//         0041c643     CALL       dword ptr [->USER32.DLL::FindWindowA]            = 0048ad18
//                              basegame.cpp:1052 (4)
//         0041c649     CMP        EAX,EBX
//         0041c64b     JZ         LAB_0041c658
//                              basegame.cpp:1053 (11)
//         0041c64d     PUSH       EBX
//         0041c64e     PUSH       EBX=>DAT_fffffff8
//         0041c64f     PUSH       offset DAT_fffffff4
//         0041c651     PUSH       EAX=>DAT_fffffff0
//         0041c652     CALL       dword ptr [->USER32.DLL::SendMessageA]           = 0048ad08
//                               LAB_0041c658                                                 XREF[2]:     0041c637(j), 0041c64b(j)
//                              basegame.cpp:1056 (20)
//         0041c658     MOV        EAX,[StringTable]                                = 00000000
//         0041c65d     CMP        EAX,EBX
//         0041c65f     JZ         LAB_0041c679
//         0041c661     MOV        EDX,dword ptr [ESI + 0xc]
//         0041c664     CMP        EAX,dword ptr [EDX + 0x410]
//         0041c66a     JZ         LAB_0041c679
//                              basegame.cpp:1058 (7)
//         0041c66c     PUSH       EAX
//         0041c66d     CALL       dword ptr [->KERNEL32.DLL::FreeLibrary]          = 0048aa18
//                              basegame.cpp:1059 (6)
//         0041c673     MOV        dword ptr [StringTable],EBX                      = 00000000
//                               LAB_0041c679                                                 XREF[2]:     0041c65f(j), 0041c66a(j)
//                              basegame.cpp:1062 (10)
//         0041c679     MOV        EDI,dword ptr [ESI + 0x1a4]
//         0041c67f     CMP        EDI,EBX
//         0041c681     JZ         LAB_0041c699
//                              basegame.cpp:1064 (16)
//         0041c683     MOV        this,EDI
//         0041c685     CALL       TDebuggingLog::~TDebuggingLog                    void ~TDebuggingLog(TDebuggingLog * this)
//         0041c68a     PUSH       EDI
//         0041c68b     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0041c690     ADD        ESP,0x4
//                              basegame.cpp:1065 (6)
//         0041c693     MOV        dword ptr [ESI + 0x1a4],EBX
//                               LAB_0041c699                                                 XREF[1]:     0041c681(j)
//                              basegame.cpp:1068 (5)
//         0041c699     CMP        dword ptr [ESI + 0x5c],EBX
//         0041c69c     JZ         LAB_0041c6d5
//                              basegame.cpp:1070 (8)
//         0041c69e     XOR        EBP,EBP
//         0041c6a0     CMP        word ptr [ESI + 0x58],BX
//         0041c6a4     JLE        LAB_0041c6c9
//                               LAB_0041c6a6                                                 XREF[1]:     0041c6c7(j)
//                              basegame.cpp:1071 (10)
//         0041c6a6     MOV        EAX,dword ptr [ESI + 0x5c]
//         0041c6a9     MOV        EDI,dword ptr [EAX + EBP*0x4]
//         0041c6ac     CMP        EDI,EBX
//         0041c6ae     JZ         LAB_0041c6c0
//                              basegame.cpp:1072 (25)
//         0041c6b0     MOV        this,EDI
//         0041c6b2     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
//         0041c6b7     PUSH       EDI
//         0041c6b8     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0041c6bd     ADD        ESP,0x4
//                               LAB_0041c6c0                                                 XREF[1]:     0041c6ae(j)
//         0041c6c0     MOVSX      this,word ptr [ESI + 0x58]
//         0041c6c4     INC        EBP
//         0041c6c5     CMP        EBP,this
//         0041c6c7     JL         LAB_0041c6a6
//                               LAB_0041c6c9                                                 XREF[1]:     0041c6a4(j)
//                              basegame.cpp:1074 (12)
//         0041c6c9     MOV        EDX,dword ptr [ESI + 0x5c]
//         0041c6cc     PUSH       EDX
//         0041c6cd     CALL       free                                             undefined free()
//         0041c6d2     ADD        ESP,0x4
//                               LAB_0041c6d5                                                 XREF[1]:     0041c69c(j)
//                              basegame.cpp:1083 (11)
//         0041c6d5     POP        EDI
//         0041c6d6     POP        ESI
//         0041c6d7     POP        EBP
//         0041c6d8     POP        EBX
//         0041c6d9     ADD        ESP,0x110
//         0041c6df     RET
}

void RGE_Base_Game::reset_timings() {
    /* TODO: Stub */
//                              void __thiscall reset_timings(RGE_Base_Game * this)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?reset_timings@RGE_Base_Game@@QAEXXZ                         XREF[1]:     let_game_begin:00528cde(c)
//                               RGE_Base_Game::reset_timings
//                              basegame.cpp:1089 (14)
//         0041c7d0     XOR        EDX,EDX
//         0041c7d2     LEA        EAX,[ECX + this+0x52c]
//         0041c7d8     MOV        dword ptr [ECX + this->frame_count],EDX
//                              basegame.cpp:1093 (6)
//         0041c7de     MOV        dword ptr [ECX + this->world_update_count],EDX
//                              basegame.cpp:1094 (6)
//         0041c7e4     MOV        dword ptr [ECX + this->view_update_count],EDX
//                              basegame.cpp:1095 (6)
//         0041c7ea     MOV        dword ptr [ECX + this->last_frame_count],EDX
//                              basegame.cpp:1096 (6)
//         0041c7f0     MOV        dword ptr [ECX + this->last_world_update_count
//                              basegame.cpp:1097 (6)
//         0041c7f6     MOV        dword ptr [ECX + this->last_view_update_count]
//                              basegame.cpp:1098 (6)
//         0041c7fc     MOV        dword ptr [ECX + this->fps],EDX
//                              basegame.cpp:1099 (6)
//         0041c802     MOV        dword ptr [ECX + this->world_update_fps],EDX
//                              basegame.cpp:1100 (11)
//         0041c808     MOV        dword ptr [ECX + this->view_update_fps],EDX
//         0041c80e     MOV        this,0x1e
//                               LAB_0041c813                                                 XREF[1]:     0041c828(j)
//                              basegame.cpp:1104 (3)
//         0041c813     MOV        dword ptr [EAX + -0x4],EDX
//                              basegame.cpp:1105 (2)
//         0041c816     MOV        dword ptr [EAX],EDX
//                              basegame.cpp:1106 (3)
//         0041c818     MOV        dword ptr [EAX + 0x4],EDX
//                              basegame.cpp:1107 (3)
//         0041c81b     MOV        dword ptr [EAX + 0x10],EDX
//                              basegame.cpp:1108 (3)
//         0041c81e     MOV        dword ptr [EAX + 0x14],EDX
//                              basegame.cpp:1109 (9)
//         0041c821     MOV        dword ptr [EAX + 0x18],EDX
//         0041c824     ADD        EAX,0x20
//         0041c827     DEC        this
//         0041c828     JNZ        LAB_0041c813
//                              basegame.cpp:1111 (1)
//         0041c82a     RET
//         0041c82b     ??         90h
//         0041c82c     NOP
//         0041c82d     NOP
//         0041c82e     NOP
//         0041c82f     NOP
    return;
}

void RGE_Base_Game::add_to_timing(int param_1, ulong param_2) {
    /* TODO: Stub */
//                              void __thiscall add_to_timing(RGE_Base_Game * this, int param_1, ulo
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0041c831(R)
//              ulong             Stack[0x8]:4   param_2                   XREF[1]:     0041c835(R)
//                               ?add_to_timing@RGE_Base_Game@@QAEXHK@Z                       XREF[16]:    handle_paint:0042142a(c),
//                               RGE_Base_Game::add_to_timing                                              handle_paint:00421535(c),
//                                                                                                         handle_paint:00421677(c),
//                                                                                                         handle_paint:004216df(c),
//                                                                                                         handle_paint:00421742(c),
//                                                                                                         handle_paint:004966e0(c),
//                                                                                                         handle_game_update:00496aa1(c),
//                                                                                                         do_draw:004c026b(c),
//                                                                                                         get_size:004c08f7(c),
//                                                                                                         get_frame:004c0a11(c),
//                                                                                                         shape_hit_test:004c0e38(c),
//                                                                                                         draw:0053d8cc(c),
//                                                                                                         handle_mouse_up:0053e2d7(c),
//                                                                                                         draw:0053f7d1(c),
//                                                                                                         draw:0053f7ea(c),
//                                                                                                         update:00542f2c(c)
//                              basegame.cpp:1117 (1)
//         0041c830     PUSH       ESI
//                              basegame.cpp:1118 (16)
//         0041c831     MOV        ESI,dword ptr [ESP + param_1]
//         0041c835     MOV        EDX,dword ptr [ESP + param_2]
//         0041c839     MOV        EAX,ESI
//         0041c83b     SHL        EAX,0x5
//         0041c83e     ADD        EAX,this
//         0041c840     PUSH       EDI
//                              basegame.cpp:1120 (36)
//         0041c841     ADD        ESI,0x2a
//         0041c844     MOV        EDI,dword ptr [EAX + 0x528]
//         0041c84a     ADD        EDI,EDX
//         0041c84c     SHL        ESI,0x5
//         0041c84f     MOV        dword ptr [EAX + 0x528],EDI
//         0041c855     MOV        dword ptr [EAX + 0x53c],EDX
//         0041c85b     LEA        EAX,[ESI + this->_padding_*0x1]
//         0041c85e     MOV        this,dword ptr [ESI + this->_padding_*0x1]
//         0041c861     CMP        EDX,this
//         0041c863     JBE        LAB_0041c867
//                              basegame.cpp:1121 (2)
//         0041c865     MOV        dword ptr [EAX],EDX
//                               LAB_0041c867                                                 XREF[1]:     0041c863(j)
//                              basegame.cpp:1122 (5)
//         0041c867     POP        EDI
//         0041c868     POP        ESI
//         0041c869     RET        0x8
//         0041c86c     ??         90h
//         0041c86d     NOP
//         0041c86e     NOP
//         0041c86f     NOP
    return;
}

void RGE_Base_Game::increment_world_update_count() {
    /* TODO: Stub */
//                              void __thiscall increment_world_update_count(RGE_Base_Game * this)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?increment_world_update_count@RGE_Base_Game@@QAEXXZ          XREF[1]:     handle_game_update:00496aac(c)
//                               RGE_Base_Game::increment_world_update_count
//                              basegame.cpp:1128 (6)
//         0041c870     INC        dword ptr [ECX + this->world_update_count]
//                              basegame.cpp:1130 (1)
//         0041c876     RET
//         0041c877     ??         90h
//         0041c878     NOP
//         0041c879     NOP
//         0041c87a     NOP
//         0041c87b     NOP
//         0041c87c     NOP
//         0041c87d     NOP
//         0041c87e     NOP
//         0041c87f     NOP
    return;
}

void RGE_Base_Game::increment_view_update_count() {
    /* TODO: Stub */
//                              void __thiscall increment_view_update_count(RGE_Base_Game * this)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?increment_view_update_count@RGE_Base_Game@@QAEXXZ           XREF[1]:     draw:0053f7dc(c)
//                               RGE_Base_Game::increment_view_update_count
//                              basegame.cpp:1136 (6)
//         0041c880     INC        dword ptr [ECX + this->view_update_count]
//                              basegame.cpp:1138 (1)
//         0041c886     RET
//         0041c887     ??         90h
//         0041c888     NOP
//         0041c889     NOP
//         0041c88a     NOP
//         0041c88b     NOP
//         0041c88c     NOP
//         0041c88d     NOP
//         0041c88e     NOP
//         0041c88f     NOP
    return;
}

void RGE_Base_Game::set_last_single_time(int param_1, ulong param_2) {
    /* TODO: Stub */
//                              void __thiscall set_last_single_time(RGE_Base_Game * this, int param
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0041c890(R)
//              ulong             Stack[0x8]:4   param_2                   XREF[1]:     0041c894(R)
//                               ?set_last_single_time@RGE_Base_Game@@QAEXHK@Z                XREF[2]:     handle_game_update:0049695b(c),
//                               RGE_Base_Game::set_last_single_time                                       handle_game_update:0049696a(c)
//                              basegame.cpp:1144 (18)
//         0041c890     MOV        EAX,dword ptr [ESP + param_1]
//         0041c894     MOV        EDX,dword ptr [ESP + param_2]
//         0041c898     SHL        EAX,0x5
//         0041c89b     MOV        dword ptr [EAX + this->_padding_*0x1 + 0x53c],
//                              basegame.cpp:1146 (3)
//         0041c8a2     RET        0x8
//         0041c8a5     ??         90h
//         0041c8a6     NOP
//         0041c8a7     NOP
//         0041c8a8     NOP
//         0041c8a9     NOP
//         0041c8aa     NOP
//         0041c8ab     NOP
//         0041c8ac     NOP
//         0041c8ad     NOP
//         0041c8ae     NOP
//         0041c8af     NOP
    return;
}

ulong RGE_Base_Game::get_last_time(int param_1) {
    /* TODO: Stub */
//                              ulong __thiscall get_last_time(RGE_Base_Game * this, int param_1)
//              ulong             EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0041c8b0(R)
//                               ?get_last_time@RGE_Base_Game@@QAEKH@Z                        XREF[1]:     handle_game_update:004968d4(c)
//                               RGE_Base_Game::get_last_time
//                              basegame.cpp:1152 (14)
//         0041c8b0     MOV        EAX,dword ptr [ESP + param_1]
//         0041c8b4     SHL        EAX,0x5
//         0041c8b7     MOV        EAX,dword ptr [ECX + EAX*0x1 + this+0x52c]
//                              basegame.cpp:1154 (3)
//         0041c8be     RET        0x4
//         0041c8c1     ??         90h
//         0041c8c2     NOP
//         0041c8c3     NOP
//         0041c8c4     NOP
//         0041c8c5     NOP
//         0041c8c6     NOP
//         0041c8c7     NOP
//         0041c8c8     NOP
//         0041c8c9     NOP
//         0041c8ca     NOP
//         0041c8cb     NOP
//         0041c8cc     NOP
//         0041c8cd     NOP
//         0041c8ce     NOP
//         0041c8cf     NOP
    return 0;
}

ulong RGE_Base_Game::get_last_single_time(int param_1) {
    /* TODO: Stub */
//                              ulong __thiscall get_last_single_time(RGE_Base_Game * this, int para
//              ulong             EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0041c8d0(R)
//                               ?get_last_single_time@RGE_Base_Game@@QAEKH@Z                 XREF[2]:     handle_game_update:0049689a(c),
//                               RGE_Base_Game::get_last_single_time                                       handle_game_update:004968a9(c)
//                              basegame.cpp:1160 (14)
//         0041c8d0     MOV        EAX,dword ptr [ESP + param_1]
//         0041c8d4     SHL        EAX,0x5
//         0041c8d7     MOV        EAX,dword ptr [ECX + EAX*0x1 + this+0x53c]
//                              basegame.cpp:1162 (3)
//         0041c8de     RET        0x4
//         0041c8e1     ??         90h
//         0041c8e2     NOP
//         0041c8e3     NOP
//         0041c8e4     NOP
//         0041c8e5     NOP
//         0041c8e6     NOP
//         0041c8e7     NOP
//         0041c8e8     NOP
//         0041c8e9     NOP
//         0041c8ea     NOP
//         0041c8eb     NOP
//         0041c8ec     NOP
//         0041c8ed     NOP
//         0041c8ee     NOP
//         0041c8ef     NOP
    return 0;
}

ulong RGE_Base_Game::get_accum_time(int param_1) {
    /* TODO: Stub */
//                              ulong __thiscall get_accum_time(RGE_Base_Game * this, int param_1)
//              ulong             EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0041c8f0(R)
//                               ?get_accum_time@RGE_Base_Game@@QAEKH@Z                       XREF[2]:     draw:0053f712(c),
//                               RGE_Base_Game::get_accum_time                                             draw:0053f7a9(c)
//                              basegame.cpp:1168 (14)
//         0041c8f0     MOV        EAX,dword ptr [ESP + param_1]
//         0041c8f4     SHL        EAX,0x5
//         0041c8f7     MOV        EAX,dword ptr [ECX + EAX*0x1 + this->timings[0
//                              basegame.cpp:1170 (3)
//         0041c8fe     RET        0x4
//         0041c901     ??         90h
//         0041c902     NOP
//         0041c903     NOP
//         0041c904     NOP
//         0041c905     NOP
//         0041c906     NOP
//         0041c907     NOP
//         0041c908     NOP
//         0041c909     NOP
//         0041c90a     NOP
//         0041c90b     NOP
//         0041c90c     NOP
//         0041c90d     NOP
//         0041c90e     NOP
//         0041c90f     NOP
    return 0;
}

ulong RGE_Base_Game::get_max_time(int param_1) {
    /* TODO: Stub */
//                              ulong __thiscall get_max_time(RGE_Base_Game * this, int param_1)
//              ulong             EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0041c910(R)
//                               ?get_max_time@RGE_Base_Game@@QAEKH@Z
//                               RGE_Base_Game::get_max_time
//                              basegame.cpp:1176 (14)
//         0041c910     MOV        EAX,dword ptr [ESP + param_1]
//         0041c914     SHL        EAX,0x5
//         0041c917     MOV        EAX,dword ptr [ECX + EAX*0x1 + this+0x540]
//                              basegame.cpp:1178 (3)
//         0041c91e     RET        0x4
//         0041c921     ??         90h
//         0041c922     NOP
//         0041c923     NOP
//         0041c924     NOP
//         0041c925     NOP
//         0041c926     NOP
//         0041c927     NOP
//         0041c928     NOP
//         0041c929     NOP
//         0041c92a     NOP
//         0041c92b     NOP
//         0041c92c     NOP
//         0041c92d     NOP
//         0041c92e     NOP
//         0041c92f     NOP
    return 0;
}

ulong RGE_Base_Game::get_last_max_time(int param_1) {
    /* TODO: Stub */
//                              ulong __thiscall get_last_max_time(RGE_Base_Game * this, int param_1)
//              ulong             EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0041c930(R)
//                               ?get_last_max_time@RGE_Base_Game@@QAEKH@Z
//                               RGE_Base_Game::get_last_max_time
//                              basegame.cpp:1184 (14)
//         0041c930     MOV        EAX,dword ptr [ESP + param_1]
//         0041c934     SHL        EAX,0x5
//         0041c937     MOV        EAX,dword ptr [ECX + EAX*0x1 + this+0x544]
//                              basegame.cpp:1186 (3)
//         0041c93e     RET        0x4
//         0041c941     ??         90h
//         0041c942     NOP
//         0041c943     NOP
//         0041c944     NOP
//         0041c945     NOP
//         0041c946     NOP
//         0041c947     NOP
//         0041c948     NOP
//         0041c949     NOP
//         0041c94a     NOP
//         0041c94b     NOP
//         0041c94c     NOP
//         0041c94d     NOP
//         0041c94e     NOP
//         0041c94f     NOP
    return 0;
}

ulong RGE_Base_Game::get_last_world_update_count() {
    /* TODO: Stub */
//                              ulong __thiscall get_last_world_update_count(RGE_Base_Game * this)
//              ulong             EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?get_last_world_update_count@RGE_Base_Game@@QAEKXZ           XREF[2]:     handle_game_update:004968b6(c),
//                               RGE_Base_Game::get_last_world_update_count                                handle_game_update:004968c5(c)
//                              basegame.cpp:1192 (6)
//         0041c950     MOV        EAX,dword ptr [ECX + this->last_world_update_c
//                              basegame.cpp:1194 (1)
//         0041c956     RET
//         0041c957     ??         90h
//         0041c958     NOP
//         0041c959     NOP
//         0041c95a     NOP
//         0041c95b     NOP
//         0041c95c     NOP
//         0041c95d     NOP
//         0041c95e     NOP
//         0041c95f     NOP
    return 0;
}

ulong RGE_Base_Game::get_last_view_update_count() {
    /* TODO: Stub */
//                              ulong __thiscall get_last_view_update_count(RGE_Base_Game * this)
//              ulong             EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?get_last_view_update_count@RGE_Base_Game@@QAEKXZ
//                               RGE_Base_Game::get_last_view_update_count
//                              basegame.cpp:1200 (6)
//         0041c960     MOV        EAX,dword ptr [ECX + this->last_view_update_co
//                              basegame.cpp:1202 (1)
//         0041c966     RET
//         0041c967     ??         90h
//         0041c968     NOP
//         0041c969     NOP
//         0041c96a     NOP
//         0041c96b     NOP
//         0041c96c     NOP
//         0041c96d     NOP
//         0041c96e     NOP
//         0041c96f     NOP
    return 0;
}

ulong RGE_Base_Game::get_world_update_count() {
    /* TODO: Stub */
//                              ulong __thiscall get_world_update_count(RGE_Base_Game * this)
//              ulong             EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?get_world_update_count@RGE_Base_Game@@QAEKXZ
//                               RGE_Base_Game::get_world_update_count
//                              basegame.cpp:1208 (6)
//         0041c970     MOV        EAX,dword ptr [ECX + this->world_update_count]
//                              basegame.cpp:1210 (1)
//         0041c976     RET
//         0041c977     ??         90h
//         0041c978     NOP
//         0041c979     NOP
//         0041c97a     NOP
//         0041c97b     NOP
//         0041c97c     NOP
//         0041c97d     NOP
//         0041c97e     NOP
//         0041c97f     NOP
    return 0;
}

ulong RGE_Base_Game::get_view_update_count() {
    /* TODO: Stub */
//                              ulong __thiscall get_view_update_count(RGE_Base_Game * this)
//              ulong             EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?get_view_update_count@RGE_Base_Game@@QAEKXZ
//                               RGE_Base_Game::get_view_update_count
//                              basegame.cpp:1216 (6)
//         0041c980     MOV        EAX,dword ptr [ECX + this->view_update_count]
//                              basegame.cpp:1218 (1)
//         0041c986     RET
//         0041c987     ??         90h
//         0041c988     NOP
//         0041c989     NOP
//         0041c98a     NOP
//         0041c98b     NOP
//         0041c98c     NOP
//         0041c98d     NOP
//         0041c98e     NOP
//         0041c98f     NOP
    return 0;
}

int RGE_Base_Game::get_error_code() {
    /* TODO: Stub */
//                              int __thiscall get_error_code(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?get_error_code@RGE_Base_Game@@UAEHXZ                        XREF[2]:     0056eee8(*), 005771c0(*)
//                               RGE_Base_Game::get_error_code
//                              basegame.cpp:1224 (3)
//         0041c990     MOV        EAX,dword ptr [ECX + this->error_code]
//                              basegame.cpp:1226 (1)
//         0041c993     RET
//         0041c994     ??         90h
//         0041c995     NOP
//         0041c996     NOP
//         0041c997     NOP
//         0041c998     NOP
//         0041c999     NOP
//         0041c99a     NOP
//         0041c99b     NOP
//         0041c99c     NOP
//         0041c99d     NOP
//         0041c99e     NOP
//         0041c99f     NOP
    return 0;
}

char* RGE_Base_Game::get_string(long param_1) {
    /* TODO: Stub */
//                              char * __thiscall get_string(RGE_Base_Game * this, long param_1)
//              char *            EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0041c9a0(R)
//                               ?get_string@RGE_Base_Game@@UAEPADJ@Z                         XREF[2]:     0056eef4(*), 005771cc(*)
//                               RGE_Base_Game::get_string
//                              basegame.cpp:1232 (20)
//         0041c9a0     MOV        EDX,dword ptr [ESP + param_1]
//         0041c9a4     MOV        EAX,dword ptr [this->_padding_]
//         0041c9a6     PUSH       0x200
//         0041c9ab     PUSH       DAT_005b2168                                     = align(512)
//         0041c9b0     PUSH       EDX
//         0041c9b1     CALL       dword ptr [EAX + 0x20]
//                              basegame.cpp:1234 (5)
//         0041c9b4     MOV        EAX,DAT_005b2168                                 = align(512)
//                              basegame.cpp:1235 (3)
//         0041c9b9     RET        0x4
//         0041c9bc     ??         90h
//         0041c9bd     NOP
//         0041c9be     NOP
//         0041c9bf     NOP
    return 0;
}

char* RGE_Base_Game::get_string(long param_1, char* param_2, int param_3) {
    /* TODO: Stub */
//                              char * __thiscall get_string(RGE_Base_Game * this, long param_1, cha
//              char *            EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0041c9c0(R)
//              char *            Stack[0x8]:4   param_2                   XREF[1]:     0041c9cb(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0041c9d0(R)
//                               ?get_string@RGE_Base_Game@@UAEPADJPADH@Z                     XREF[3]:     ~RGE_Base_Game:0041c62c(c),
//                               RGE_Base_Game::get_string                                                 get_string:0052290a(c),
//                                                                                                         0056eef0(*)
//                              basegame.cpp:1241 (34)
//         0041c9c0     MOV        EAX,dword ptr [ESP + param_1]
//         0041c9c4     MOV        this,dword ptr [StringTable]                     = 00000000
//         0041c9ca     PUSH       ESI
//         0041c9cb     MOV        ESI,dword ptr [ESP + param_2]
//         0041c9cf     PUSH       EDI
//         0041c9d0     MOV        EDI,dword ptr [ESP + param_3]
//         0041c9d4     PUSH       EDI
//         0041c9d5     PUSH       ESI
//         0041c9d6     PUSH       EAX
//         0041c9d7     PUSH       this
//         0041c9d8     CALL       dword ptr [->USER32.DLL::LoadStringA]            = 0048ad36
//         0041c9de     TEST       EAX,EAX
//         0041c9e0     JNZ        LAB_0041c9e4
//                              basegame.cpp:1247 (2)
//         0041c9e2     MOV        byte ptr [ESI],AL
//                               LAB_0041c9e4                                                 XREF[1]:     0041c9e0(j)
//                              basegame.cpp:1248 (5)
//         0041c9e4     MOV        byte ptr [EDI + ESI*0x1 + -0x1],0x0
//                              basegame.cpp:1249 (2)
//         0041c9e9     MOV        EAX,ESI
//                              basegame.cpp:1250 (5)
//         0041c9eb     POP        EDI
//         0041c9ec     POP        ESI
//         0041c9ed     RET        0xc
    return 0;
}

char* RGE_Base_Game::get_string(int param_1, long param_2, char* param_3, int param_4) {
    /* TODO: Stub */
//                              char * __thiscall get_string(RGE_Base_Game * this, int param_1, long
//              char *            EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0041ca03(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0041c9fc(R)
//              char *            Stack[0xc]:4   param_3                   XREF[1]:     0041c9f7(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0041c9f0(R)
//                               ?get_string@RGE_Base_Game@@UAEPADHJPADH@Z                    XREF[2]:     0056eeec(*), 005771c4(*)
//                               RGE_Base_Game::get_string
//                              basegame.cpp:1257 (27)
//         0041c9f0     MOV        EDX,dword ptr [ESP + param_4]
//         0041c9f4     MOV        EAX,dword ptr [this->_padding_]
//         0041c9f6     PUSH       EDX
//         0041c9f7     MOV        EDX,dword ptr [ESP + param_3]
//         0041c9fb     PUSH       EDX
//         0041c9fc     MOV        EDX,dword ptr [ESP + param_2]
//         0041ca00     PUSH       0x0
//         0041ca02     PUSH       EDX
//         0041ca03     MOV        EDX,dword ptr [ESP + param_1]
//         0041ca07     PUSH       EDX
//         0041ca08     CALL       dword ptr [EAX + 0x28]
//                              basegame.cpp:1259 (3)
//         0041ca0b     RET        0x10
//         0041ca0e     ??         90h
//         0041ca0f     NOP
    return 0;
}

char* RGE_Base_Game::get_string2(int param_1, long param_2, long param_3, char* param_4, int param_5) {
    /* TODO: Stub */
//                              char * __thiscall get_string2(RGE_Base_Game * this, int param_1, lon
//              char *            EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0041ca14(R)
//              long              Stack[0x8]:4   param_2                   XREF[2]:     0041ca2e(R), 0041ca3a(R)
//              long              Stack[0xc]:4   param_3
//              char *            Stack[0x10]:4  param_4                   XREF[1]:     0041ca10(R)
//              int               Stack[0x14]:4  param_5                   XREF[12]:    0041ca26(R), 0041ca4f(R), 0041ca63(R), 0041ca77(R),
//                                                                                     0041ca8b(R), 0041ca9f(R), 0041cab3(R), 0041cac7(R),
//                                                                                     0041cadb(R), 0041caef(R), 0041cb03(R), 0041cb17(R)
//                               ?get_string2@RGE_Base_Game@@UAEPADHJJPADH@Z                  XREF[3]:     get_string2:00522f79(c),
//                               RGE_Base_Game::get_string2                                                get_string2:00523214(c),
//                                                                                                         0056eef8(*)
//                              basegame.cpp:1265 (4)
//         0041ca10     MOV        EAX,dword ptr [ESP + param_4]
//                              basegame.cpp:1268 (18)
//         0041ca14     MOV        EDX,dword ptr [ESP + param_1]
//         0041ca18     DEC        EDX
//         0041ca19     PUSH       ESI
//         0041ca1a     MOV        byte ptr [EAX],0x0
//         0041ca1d     JZ         LAB_0041ca3a
//         0041ca1f     DEC        EDX
//         0041ca20     JNZ        switchD_0041ca48::default
//                              basegame.cpp:1271 (16)
//         0041ca26     MOV        ESI,dword ptr [ESP + param_5]
//         0041ca2a     MOV        EDX,dword ptr [this->_padding_]
//         0041ca2c     PUSH       ESI
//         0041ca2d     PUSH       EAX
//         0041ca2e     MOV        EAX,dword ptr [ESP + param_2]
//         0041ca32     PUSH       EAX
//         0041ca33     CALL       dword ptr [EDX + 0x20]
//                              basegame.cpp:1325 (4)
//         0041ca36     POP        ESI
//         0041ca37     RET        0x14
//                               LAB_0041ca3a                                                 XREF[1]:     0041ca1d(j)
//                              basegame.cpp:1274 (21)
//         0041ca3a     MOV        EDX,dword ptr [ESP + param_2]
//         0041ca3e     DEC        EDX
//         0041ca3f     CMP        EDX,0x16
//         0041ca42     JA         switchD_0041ca48::default
//                               switchD_0041ca48::switchD
//         0041ca48     JMP        dword ptr [EDX*0x4 + switchD_0041ca48::switchd   = 0041ca4f
//                               switchD_0041ca48::caseD_2                                    XREF[9]:     0041ca48(j), 0041cb24(*),
//                               switchD_0041ca48::caseD_3                                                 0041cb28(*), 0041cb2c(*),
//                               switchD_0041ca48::caseD_4                                                 0041cb30(*), 0041cb34(*),
//                               switchD_0041ca48::caseD_5                                                 0041cb38(*), 0041cb58(*),
//                               switchD_0041ca48::caseD_6                                                 0041cb5c(*)
//                               switchD_0041ca48::caseD_e
//                               switchD_0041ca48::caseD_f
//                               switchD_0041ca48::caseD_1
//                              basegame.cpp:1284 (16)
//         0041ca4f     MOV        ESI,dword ptr [ESP + param_5]
//         0041ca53     MOV        EDX,dword ptr [this->_padding_]
//         0041ca55     PUSH       ESI
//         0041ca56     PUSH       EAX
//                              language.dll match for 0x7d2: "Could not initialize program.
//         0041ca57     PUSH       0x7d2
//         0041ca5c     CALL       dword ptr [EDX + 0x20]
//                              basegame.cpp:1325 (4)
//         0041ca5f     POP        ESI
//         0041ca60     RET        0x14
//                               switchD_0041ca48::caseD_8                                    XREF[6]:     0041ca48(j), 0041cb3c(*),
//                               switchD_0041ca48::caseD_b                                                 0041cb40(*), 0041cb4c(*),
//                               switchD_0041ca48::caseD_d                                                 0041cb54(*), 0041cb64(*)
//                               switchD_0041ca48::caseD_11
//                               switchD_0041ca48::caseD_7
//                              basegame.cpp:1291 (16)
//         0041ca63     MOV        ESI,dword ptr [ESP + param_5]
//         0041ca67     MOV        EDX,dword ptr [this->_padding_]
//         0041ca69     PUSH       ESI
//         0041ca6a     PUSH       EAX
//                              language.dll match for 0x7d3: "Could not initialize graphics
//         0041ca6b     PUSH       0x7d3
//         0041ca70     CALL       dword ptr [EDX + 0x20]
//                              basegame.cpp:1325 (4)
//         0041ca73     POP        ESI
//         0041ca74     RET        0x14
//                               switchD_0041ca48::caseD_13                                   XREF[2]:     0041ca48(j), 0041cb6c(*)
//                              basegame.cpp:1294 (16)
//         0041ca77     MOV        ESI,dword ptr [ESP + param_5]
//         0041ca7b     MOV        EDX,dword ptr [this->_padding_]
//         0041ca7d     PUSH       ESI
//         0041ca7e     PUSH       EAX
//                              language.dll match for 0x7db: "Age of Empires requires a colo
//         0041ca7f     PUSH       0x7db
//         0041ca84     CALL       dword ptr [EDX + 0x20]
//                              basegame.cpp:1325 (4)
//         0041ca87     POP        ESI
//         0041ca88     RET        0x14
//                               switchD_0041ca48::caseD_10                                   XREF[3]:     0041ca48(j), 0041cb44(*),
//                               switchD_0041ca48::caseD_9                                                 0041cb60(*)
//                              basegame.cpp:1298 (16)
//         0041ca8b     MOV        ESI,dword ptr [ESP + param_5]
//         0041ca8f     MOV        EDX,dword ptr [this->_padding_]
//         0041ca91     PUSH       ESI
//         0041ca92     PUSH       EAX
//                              language.dll match for 0x7d5: "Could not initialize communica
//         0041ca93     PUSH       0x7d5
//         0041ca98     CALL       dword ptr [EDX + 0x20]
//                              basegame.cpp:1325 (4)
//         0041ca9b     POP        ESI
//         0041ca9c     RET        0x14
//                               switchD_0041ca48::caseD_c                                    XREF[3]:     0041ca48(j), 0041cb48(*),
//                               switchD_0041ca48::caseD_a                                                 0041cb50(*)
//                              basegame.cpp:1302 (16)
//         0041ca9f     MOV        ESI,dword ptr [ESP + param_5]
//         0041caa3     MOV        EDX,dword ptr [this->_padding_]
//         0041caa5     PUSH       ESI
//         0041caa6     PUSH       EAX
//                              language.dll match for 0x7d4: "Could not initialize sound sys
//         0041caa7     PUSH       0x7d4
//         0041caac     CALL       dword ptr [EDX + 0x20]
//                              basegame.cpp:1325 (4)
//         0041caaf     POP        ESI
//         0041cab0     RET        0x14
//                               switchD_0041ca48::caseD_12                                   XREF[2]:     0041ca48(j), 0041cb68(*)
//                              basegame.cpp:1305 (16)
//         0041cab3     MOV        ESI,dword ptr [ESP + param_5]
//         0041cab7     MOV        EDX,dword ptr [this->_padding_]
//         0041cab9     PUSH       ESI
//         0041caba     PUSH       EAX
//                              language.dll match for 0x7dc: "Game stopped because it was ou
//         0041cabb     PUSH       0x7dc
//         0041cac0     CALL       dword ptr [EDX + 0x20]
//                              basegame.cpp:1325 (4)
//         0041cac3     POP        ESI
//         0041cac4     RET        0x14
//                               switchD_0041ca48::caseD_14                                   XREF[2]:     0041ca48(j), 0041cb70(*)
//                              basegame.cpp:1308 (16)
//         0041cac7     MOV        ESI,dword ptr [ESP + param_5]
//         0041cacb     MOV        EDX,dword ptr [this->_padding_]
//         0041cacd     PUSH       ESI
//         0041cace     PUSH       EAX
//                              language.dll match for 0x7dd: "Age of Empires could not initi
//                              language.dll match for 0x7dd: "Age of Empires requires Direct
//         0041cacf     PUSH       0x7dd
//         0041cad4     CALL       dword ptr [EDX + 0x20]
//                              basegame.cpp:1325 (4)
//         0041cad7     POP        ESI
//         0041cad8     RET        0x14
//                               switchD_0041ca48::caseD_15                                   XREF[2]:     0041ca48(j), 0041cb74(*)
//                              basegame.cpp:1311 (16)
//         0041cadb     MOV        ESI,dword ptr [ESP + param_5]
//         0041cadf     MOV        EDX,dword ptr [this->_padding_]
//         0041cae1     PUSH       ESI
//         0041cae2     PUSH       EAX
//                              language.dll match for 0x7de: "Age of Empires requires Micros
//         0041cae3     PUSH       0x7de
//         0041cae8     CALL       dword ptr [EDX + 0x20]
//                              basegame.cpp:1325 (4)
//         0041caeb     POP        ESI
//         0041caec     RET        0x14
//                               switchD_0041ca48::caseD_16                                   XREF[2]:     0041ca48(j), 0041cb78(*)
//                              basegame.cpp:1314 (16)
//         0041caef     MOV        ESI,dword ptr [ESP + param_5]
//         0041caf3     MOV        EDX,dword ptr [this->_padding_]
//         0041caf5     PUSH       ESI
//         0041caf6     PUSH       EAX
//                              language.dll match for 0x7df: "Not enough memory or swap file
//         0041caf7     PUSH       0x7df
//         0041cafc     CALL       dword ptr [EDX + 0x20]
//                              basegame.cpp:1325 (4)
//         0041caff     POP        ESI
//         0041cb00     RET        0x14
//                               switchD_0041ca48::caseD_17                                   XREF[2]:     0041ca48(j), 0041cb7c(*)
//                              basegame.cpp:1317 (16)
//         0041cb03     MOV        ESI,dword ptr [ESP + param_5]
//         0041cb07     MOV        EDX,dword ptr [this->_padding_]
//         0041cb09     PUSH       ESI
//         0041cb0a     PUSH       EAX
//                              language.dll match for 0x7e0: "Age of Empires Expansion requi
//         0041cb0b     PUSH       0x7e0
//         0041cb10     CALL       dword ptr [EDX + 0x20]
//                              basegame.cpp:1325 (4)
//         0041cb13     POP        ESI
//         0041cb14     RET        0x14
//                               switchD_0041ca48::default                                    XREF[2]:     0041ca20(j), 0041ca42(j)
//                              basegame.cpp:1322 (4)
//         0041cb17     MOV        this,dword ptr [ESP + param_5]
//                              basegame.cpp:1325 (101)
//         0041cb1b     POP        ESI
//         0041cb1c     MOV        byte ptr [this->_padding_ + EAX*0x1 + -0x1],0x0
//         0041cb21     RET        0x14
//                              Symbol Ref: No symbol: NONAME
//                               switchD_0041ca48::switchdataD_0041cb24                       XREF[1]:     get_string2:0041ca48(*)
//         0041cb24     addr       switchD_0041ca48::caseD_1
//         0041cb28     addr       switchD_0041ca48::caseD_1
//         0041cb2c     addr       switchD_0041ca48::caseD_1
//         0041cb30     addr       switchD_0041ca48::caseD_1
//         0041cb34     addr       switchD_0041ca48::caseD_1
//         0041cb38     addr       switchD_0041ca48::caseD_1
//         0041cb3c     addr       switchD_0041ca48::caseD_7
//         0041cb40     addr       switchD_0041ca48::caseD_7
//         0041cb44     addr       switchD_0041ca48::caseD_9
//         0041cb48     addr       switchD_0041ca48::caseD_a
//         0041cb4c     addr       switchD_0041ca48::caseD_7
//         0041cb50     addr       switchD_0041ca48::caseD_a
//         0041cb54     addr       switchD_0041ca48::caseD_7
//         0041cb58     addr       switchD_0041ca48::caseD_1
//         0041cb5c     addr       switchD_0041ca48::caseD_1
//         0041cb60     addr       switchD_0041ca48::caseD_9
//         0041cb64     addr       switchD_0041ca48::caseD_7
//         0041cb68     addr       switchD_0041ca48::caseD_12
//         0041cb6c     addr       switchD_0041ca48::caseD_13
//         0041cb70     addr       switchD_0041ca48::caseD_14
//         0041cb74     addr       switchD_0041ca48::caseD_15
//         0041cb78     addr       switchD_0041ca48::caseD_16
//         0041cb7c     addr       switchD_0041ca48::caseD_17
    return 0;
}

RGE_Scenario* RGE_Base_Game::get_scenario_info(char* param_1, int param_2) {
    /* TODO: Stub */
//                              RGE_Scenario * __thiscall get_scenario_info(RGE_Base_Game * this, ch
//              RGE_Scenario *    EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     0041cb8a(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0041cbab(R)
//              char[300]         Stack[-0x130   temp_name                 XREF[1,2]:   0041cc62(*), 0041cb9c(*), 0041cbd5(*)
//              long              Stack[-0x134   obj_id                    XREF[1]:     0041cbfc(*)
//              long              Stack[-0x138   version                   XREF[3]:     0041cc0c(*), 0041cc19(R), 0041cc4a(R)
//              long              Stack[-0x13c   header_size
//                               ?get_scenario_info@RGE_Base_Game@@QAEPAVRGE_Scenario@@PADH@Z XREF[4]:     startGame:004914ac(c),
//                               RGE_Base_Game::get_scenario_info                                          updateSummary:004a42be(c),
//                                                                                                         start_scenario:0052601b(c),
//                                                                                                         create_game:005272bd(c)
//                              basegame.cpp:1336 (10)
//         0041cb80     SUB        ESP,0x138
//         0041cb86     PUSH       EBX
//         0041cb87     MOV        EBX,this
//         0041cb89     PUSH       ESI
//                              basegame.cpp:1345 (33)
//         0041cb8a     MOV        ESI,dword ptr [ESP + param_1]
//         0041cb91     MOV        EAX,dword ptr [EBX + 0xc]
//         0041cb94     PUSH       EDI
//         0041cb95     ADD        EAX,0xc17
//         0041cb9a     PUSH       ESI
//         0041cb9b     PUSH       EAX
//         0041cb9c     LEA        this=>temp_name[4],[ESP + 0x20]
//         0041cba0     PUSH       s_%s%s                                           = "%s%s"
//         0041cba5     PUSH       this
//         0041cba6     CALL       sprintf                                          undefined sprintf()
//                              basegame.cpp:1348 (14)
//         0041cbab     MOV        EAX,dword ptr [ESP + param_2]
//         0041cbb2     ADD        ESP,0x10
//         0041cbb5     TEST       EAX,EAX
//         0041cbb7     JZ         LAB_0041cbc3
//                              basegame.cpp:1349 (8)
//         0041cbb9     MOV        this,dword ptr [EBX + 0x4]
//         0041cbbc     CALL       RGE_Game_Info::open_scenario                     int open_scenario(RGE_Game_Info * this)
//                              basegame.cpp:1350 (2)
//         0041cbc1     JMP        LAB_0041cbe7
//                               LAB_0041cbc3                                                 XREF[1]:     0041cbb7(j)
//                              basegame.cpp:1352 (4)
//         0041cbc3     TEST       ESI,ESI
//         0041cbc5     JNZ        LAB_0041cbd5
//                              basegame.cpp:1353 (2)
//         0041cbc7     XOR        EAX,EAX
//                              basegame.cpp:1422 (12)
//         0041cbc9     POP        EDI
//         0041cbca     POP        ESI
//         0041cbcb     POP        EBX
//         0041cbcc     ADD        ESP,0x138
//         0041cbd2     RET        0x8
//                               LAB_0041cbd5                                                 XREF[1]:     0041cbc5(j)
//                              basegame.cpp:1354 (20)
//         0041cbd5     LEA        EDX=>temp_name[4],[ESP + 0x18]
//         0041cbd9     PUSH       0x8000
//         0041cbde     PUSH       EDX
//         0041cbdf     CALL       rge_open                                         int rge_open(char * param_1, int param_2)
//         0041cbe4     ADD        ESP,0x8
//                               LAB_0041cbe7                                                 XREF[1]:     0041cbc1(j)
//         0041cbe7     MOV        ESI,EAX
//                              basegame.cpp:1356 (5)
//         0041cbe9     CMP        ESI,-0x1
//         0041cbec     JNZ        LAB_0041cbfc
//                              basegame.cpp:1357 (2)
//         0041cbee     XOR        EAX,EAX
//                              basegame.cpp:1422 (12)
//         0041cbf0     POP        EDI
//         0041cbf1     POP        ESI
//         0041cbf2     POP        EBX
//         0041cbf3     ADD        ESP,0x138
//         0041cbf9     RET        0x8
//                               LAB_0041cbfc                                                 XREF[1]:     0041cbec(j)
//                              basegame.cpp:1360 (16)
//         0041cbfc     LEA        EAX=>obj_id,[ESP + 0x10]
//         0041cc00     PUSH       0x4
//         0041cc02     PUSH       EAX
//         0041cc03     PUSH       ESI
//         0041cc04     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void
//         0041cc09     ADD        ESP,0xc
//                              basegame.cpp:1399 (13)
//         0041cc0c     LEA        this=>version,[ESP + 0xc]
//         0041cc10     PUSH       0x4
//         0041cc12     PUSH       this
//         0041cc13     PUSH       ESI
//         0041cc14     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void
//                              basegame.cpp:1400 (11)
//         0041cc19     MOV        EAX,dword ptr [ESP + version]
//         0041cc1d     ADD        ESP,0xc
//         0041cc20     TEST       EAX,EAX
//         0041cc22     JLE        LAB_0041cc62
//                              basegame.cpp:1402 (11)
//         0041cc24     PUSH       EAX
//         0041cc25     CALL       malloc                                           undefined malloc()
//         0041cc2a     MOV        EDI,EAX
//         0041cc2c     ADD        ESP,0x4
//                              basegame.cpp:1403 (4)
//         0041cc2f     TEST       EDI,EDI
//         0041cc31     JNZ        LAB_0041cc4a
//                              basegame.cpp:1405 (9)
//         0041cc33     PUSH       ESI
//         0041cc34     CALL       rge_close                                        int rge_close(int param_1)
//         0041cc39     ADD        ESP,0x4
//                              basegame.cpp:1406 (2)
//         0041cc3c     XOR        EAX,EAX
//                              basegame.cpp:1422 (12)
//         0041cc3e     POP        EDI
//         0041cc3f     POP        ESI
//         0041cc40     POP        EBX
//         0041cc41     ADD        ESP,0x138
//         0041cc47     RET        0x8
//                               LAB_0041cc4a                                                 XREF[1]:     0041cc31(j)
//                              basegame.cpp:1408 (15)
//         0041cc4a     MOV        EDX,dword ptr [ESP + version]
//         0041cc4e     PUSH       EDX
//         0041cc4f     PUSH       EDI
//         0041cc50     PUSH       ESI
//         0041cc51     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void
//         0041cc56     ADD        ESP,0xc
//                              basegame.cpp:1409 (9)
//         0041cc59     PUSH       EDI
//         0041cc5a     CALL       free                                             undefined free()
//         0041cc5f     ADD        ESP,0x4
//                               LAB_0041cc62                                                 XREF[1]:     0041cc22(j)
//                              basegame.cpp:1414 (13)
//         0041cc62     LEA        EAX=>temp_name,[ESP + 0x14]
//         0041cc66     PUSH       0x4
//         0041cc68     PUSH       EAX
//         0041cc69     PUSH       ESI
//         0041cc6a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              basegame.cpp:1417 (11)
//         0041cc6f     MOV        EDX,dword ptr [EBX]
//         0041cc71     ADD        ESP,0xc
//         0041cc74     MOV        this,EBX
//         0041cc76     PUSH       ESI
//         0041cc77     CALL       dword ptr [EDX + 0x3c]
//                              basegame.cpp:1419 (11)
//         0041cc7a     PUSH       ESI
//         0041cc7b     MOV        EDI,EAX
//         0041cc7d     CALL       rge_close                                        int rge_close(int param_1)
//         0041cc82     ADD        ESP,0x4
//                              basegame.cpp:1421 (2)
//         0041cc85     MOV        EAX,EDI
//                              basegame.cpp:1422 (12)
//         0041cc87     POP        EDI
//         0041cc88     POP        ESI
//         0041cc89     POP        EBX
//         0041cc8a     ADD        ESP,0x138
//         0041cc90     RET        0x8
//         0041cc93     ??         90h
//         0041cc94     NOP
//         0041cc95     NOP
//         0041cc96     NOP
//         0041cc97     NOP
//         0041cc98     NOP
//         0041cc99     NOP
//         0041cc9a     NOP
//         0041cc9b     NOP
//         0041cc9c     NOP
//         0041cc9d     NOP
//         0041cc9e     NOP
//         0041cc9f     NOP
    return 0;
}

RGE_Scenario_Header* RGE_Base_Game::get_scenario_header(char* param_1, int param_2) {
    /* TODO: Stub */
//                              RGE_Scenario_Header * __thiscall get_scenario_header(RGE_Base_Game *
//              RGE_Scenario_H    EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     0041cca8(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0041cccb(R)
//              char[300]         Stack[-0x130   temp_name                 XREF[2,2]:   0041cd1c(*), 0041cd29(R), 0041ccb3(*), 0041ccf5(*)
//              long              Stack[-0x134   version
//                               ?get_scenario_header@RGE_Base_Game@@QAEPAVRGE_Scenario_Head  XREF[1]:     get_scenario_checksum:00422d28(c)
//                               RGE_Base_Game::get_scenario_header
//                              basegame.cpp:1431 (8)
//         0041cca0     SUB        ESP,0x130
//         0041cca6     PUSH       EBX
//         0041cca7     PUSH       ESI
//                              basegame.cpp:1439 (35)
//         0041cca8     MOV        ESI,dword ptr [ESP + param_1]
//         0041ccaf     PUSH       EDI
//         0041ccb0     MOV        EDI,this
//         0041ccb2     PUSH       ESI
//         0041ccb3     LEA        this=>temp_name[4],[ESP + 0x14]
//         0041ccb7     MOV        EAX,dword ptr [EDI + 0xc]
//         0041ccba     ADD        EAX,0xc17
//         0041ccbf     PUSH       EAX
//         0041ccc0     PUSH       s_%s%s                                           = "%s%s"
//         0041ccc5     PUSH       this
//         0041ccc6     CALL       sprintf                                          undefined sprintf()
//                              basegame.cpp:1442 (14)
//         0041cccb     MOV        EAX,dword ptr [ESP + param_2]
//         0041ccd2     ADD        ESP,0x10
//         0041ccd5     TEST       EAX,EAX
//         0041ccd7     JZ         LAB_0041cce3
//                              basegame.cpp:1443 (8)
//         0041ccd9     MOV        this,dword ptr [EDI + 0x4]
//         0041ccdc     CALL       RGE_Game_Info::open_scenario                     int open_scenario(RGE_Game_Info * this)
//                              basegame.cpp:1444 (2)
//         0041cce1     JMP        LAB_0041cd07
//                               LAB_0041cce3                                                 XREF[1]:     0041ccd7(j)
//                              basegame.cpp:1446 (4)
//         0041cce3     TEST       ESI,ESI
//         0041cce5     JNZ        LAB_0041ccf5
//                              basegame.cpp:1447 (2)
//         0041cce7     XOR        EAX,EAX
//                              basegame.cpp:1494 (12)
//         0041cce9     POP        EDI
//         0041ccea     POP        ESI
//         0041cceb     POP        EBX
//         0041ccec     ADD        ESP,0x130
//         0041ccf2     RET        0x8
//                               LAB_0041ccf5                                                 XREF[1]:     0041cce5(j)
//                              basegame.cpp:1448 (20)
//         0041ccf5     LEA        EDX=>temp_name[4],[ESP + 0x10]
//         0041ccf9     PUSH       0x8000
//         0041ccfe     PUSH       EDX
//         0041ccff     CALL       rge_open                                         int rge_open(char * param_1, int param_2)
//         0041cd04     ADD        ESP,0x8
//                               LAB_0041cd07                                                 XREF[1]:     0041cce1(j)
//         0041cd07     MOV        ESI,EAX
//                              basegame.cpp:1450 (5)
//         0041cd09     CMP        ESI,-0x1
//         0041cd0c     JNZ        LAB_0041cd1c
//                              basegame.cpp:1451 (2)
//         0041cd0e     XOR        EAX,EAX
//                              basegame.cpp:1494 (12)
//         0041cd10     POP        EDI
//         0041cd11     POP        ESI
//         0041cd12     POP        EBX
//         0041cd13     ADD        ESP,0x130
//         0041cd19     RET        0x8
//                               LAB_0041cd1c                                                 XREF[1]:     0041cd0c(j)
//                              basegame.cpp:1454 (13)
//         0041cd1c     LEA        EAX=>temp_name,[ESP + 0xc]
//         0041cd20     PUSH       0x4
//         0041cd22     PUSH       EAX
//         0041cd23     PUSH       ESI
//         0041cd24     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void
//                              basegame.cpp:1489 (83)
//         0041cd29     MOV        EAX,dword ptr [ESP + temp_name[0]]
//         0041cd2d     MOV        this,dword ptr [s_1.03]                          = "1.03"
//         0041cd33     ADD        ESP,0xc
//         0041cd36     XOR        EBX,EBX
//         0041cd38     CMP        EAX,this
//         0041cd3a     JZ         LAB_0041cd7c
//         0041cd3c     CMP        EAX,dword ptr [s_1.04]                           = "1.04"
//         0041cd42     JZ         LAB_0041cd7c
//         0041cd44     CMP        EAX,dword ptr [s_1.05]                           = "1.05"
//         0041cd4a     JZ         LAB_0041cd7c
//         0041cd4c     CMP        EAX,dword ptr [s_1.06]                           = "1.06"
//         0041cd52     JZ         LAB_0041cd7c
//         0041cd54     CMP        EAX,dword ptr [s_1.07]                           = "1.07"
//         0041cd5a     JZ         LAB_0041cd7c
//         0041cd5c     CMP        EAX,dword ptr [s_1.08]                           = "1.08"
//         0041cd62     JZ         LAB_0041cd7c
//         0041cd64     CMP        EAX,dword ptr [s_1.09]                           = "1.09"
//         0041cd6a     JZ         LAB_0041cd7c
//         0041cd6c     CMP        EAX,dword ptr [s_1.10]                           = "1.10"
//         0041cd72     JZ         LAB_0041cd7c
//         0041cd74     CMP        EAX,dword ptr [s_1.11]                           = "1.11"
//         0041cd7a     JNZ        LAB_0041cd86
//                               LAB_0041cd7c                                                 XREF[8]:     0041cd3a(j), 0041cd42(j),
//                                                                                                         0041cd4a(j), 0041cd52(j),
//                                                                                                         0041cd5a(j), 0041cd62(j),
//                                                                                                         0041cd6a(j), 0041cd72(j)
//                              basegame.cpp:1490 (10)
//         0041cd7c     MOV        EDX,dword ptr [EDI]
//         0041cd7e     PUSH       ESI
//         0041cd7f     MOV        this,EDI
//         0041cd81     CALL       dword ptr [EDX + 0x38]
//         0041cd84     MOV        EBX,EAX
//                               LAB_0041cd86                                                 XREF[1]:     0041cd7a(j)
//                              basegame.cpp:1492 (9)
//         0041cd86     PUSH       ESI
//         0041cd87     CALL       rge_close                                        int rge_close(int param_1)
//         0041cd8c     ADD        ESP,0x4
//                              basegame.cpp:1493 (2)
//         0041cd8f     MOV        EAX,EBX
//                              basegame.cpp:1494 (12)
//         0041cd91     POP        EDI
//         0041cd92     POP        ESI
//         0041cd93     POP        EBX
//         0041cd94     ADD        ESP,0x130
//         0041cd9a     RET        0x8
//         0041cd9d     ??         90h
//         0041cd9e     NOP
//         0041cd9f     NOP
    return 0;
}

void RGE_Base_Game::write_scenario_header(int param_1) {
    /* TODO: Stub */
//                              void __thiscall write_scenario_header(RGE_Base_Game * this, int para
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              long              Stack[-0x8]:4  header_size
//                               ?write_scenario_header@RGE_Base_Game@@QAEXH@Z                XREF[1]:     save_scenario:00543af4(c)
//                               RGE_Base_Game::write_scenario_header
//                              basegame.cpp:1503 (1)
//         0041cda0     PUSH       this
//                              basegame.cpp:1507 (18)
//         0041cda1     MOV        EDX,dword ptr [ECX + this->world]
//         0041cda7     MOV        EAX,dword ptr [this->_padding_]
//         0041cda9     PUSH       ESI
//         0041cdaa     MOV        EDX,dword ptr [EDX + 0x5c]
//         0041cdad     PUSH       EDX
//         0041cdae     CALL       dword ptr [EAX + 0x34]
//         0041cdb1     MOV        ESI,EAX
//                              basegame.cpp:1508 (4)
//         0041cdb3     TEST       ESI,ESI
//         0041cdb5     JZ         LAB_0041cdd8
//                              basegame.cpp:1510 (12)
//         0041cdb7     MOV        this,dword ptr [ESP + 0xc]
//         0041cdbb     MOV        EAX,dword ptr [ESI]
//         0041cdbd     PUSH       this
//         0041cdbe     MOV        this,ESI
//         0041cdc0     CALL       dword ptr [EAX + 0x4]
//                              basegame.cpp:1511 (16)
//         0041cdc3     MOV        this,ESI
//         0041cdc5     CALL       RGE_Scenario_Header::~RGE_Scenario_Header        void ~RGE_Scenario_Header(RGE_Scenario_Header
//         0041cdca     PUSH       ESI
//         0041cdcb     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0041cdd0     ADD        ESP,0x4
//                              basegame.cpp:1518 (5)
//         0041cdd3     POP        ESI
//         0041cdd4     POP        this
//         0041cdd5     RET        0x4
//                               LAB_0041cdd8                                                 XREF[1]:     0041cdb5(j)
//                              basegame.cpp:1516 (28)
//         0041cdd8     MOV        EAX,dword ptr [ESP + 0xc]
//         0041cddc     LEA        EDX,[ESP + 0x4]
//         0041cde0     PUSH       0x4
//         0041cde2     PUSH       EDX=>DAT_fffffff8
//         0041cde3     PUSH       EAX=>DAT_fffffff4
//         0041cde4     MOV        dword ptr [ESP + 0x10],0x0
//         0041cdec     CALL       rge_write_uncompressed                           void rge_write_uncompressed(int param_1, void
//         0041cdf1     ADD        ESP,0xc
//                              basegame.cpp:1518 (5)
//         0041cdf4     POP        ESI
//         0041cdf5     POP        this
//         0041cdf6     RET        0x4
//         0041cdf9     ??         90h
//         0041cdfa     NOP
//         0041cdfb     NOP
//         0041cdfc     NOP
//         0041cdfd     NOP
//         0041cdfe     NOP
//         0041cdff     NOP
    return;
}

RGE_Scenario_Header* RGE_Base_Game::new_scenario_header(int param_1) {
    /* TODO: Stub */
//                              RGE_Scenario_Header * __thiscall new_scenario_header(RGE_Base_Game *
//              RGE_Scenario_H    EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0041ce30(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0041ce26(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0041ce3c(R), 0041ce4d(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0041ce20(*)
//                               ?new_scenario_header@RGE_Base_Game@@UAEPAVRGE_Scenario_Head  XREF[1]:     0056ef08(*)
//                               RGE_Base_Game::new_scenario_header
//                              basegame.cpp:1524 (22)
//         0041ce00     PUSH       -0x1
//         0041ce02     PUSH       FUN_0055ca1b
//         0041ce07     MOV        EAX,FS:[0x0]
//         0041ce0d     PUSH       EAX
//         0041ce0e     MOV        dword ptr FS:[0x0],ESP
//         0041ce15     PUSH       this
//                              basegame.cpp:1525 (38)
//         0041ce16     PUSH       0x14
//         0041ce18     CALL       operator_new                                     void * operator_new(uint param_1)
//         0041ce1d     ADD        ESP,0x4
//         0041ce20     MOV        dword ptr [ESP]=>local_10,EAX
//         0041ce24     TEST       EAX,EAX
//         0041ce26     MOV        dword ptr [ESP + local_4],0x0
//         0041ce2e     JZ         LAB_0041ce4d
//         0041ce30     MOV        this,dword ptr [ESP + param_1]
//         0041ce34     PUSH       this
//         0041ce35     MOV        this,EAX
//         0041ce37     CALL       RGE_Scenario_Header::RGE_Scenario_Header         undefined RGE_Scenario_Header(RGE_Scenario_He
//                              basegame.cpp:1526 (36)
//         0041ce3c     MOV        this,dword ptr [ESP + local_c]
//         0041ce40     MOV        dword ptr FS:[0x0],this
//         0041ce47     ADD        ESP,0x10
//         0041ce4a     RET        0x4
//                               LAB_0041ce4d                                                 XREF[1]:     0041ce2e(j)
//         0041ce4d     MOV        this,dword ptr [ESP + local_c]
//         0041ce51     XOR        EAX,EAX
//         0041ce53     MOV        dword ptr FS:[0x0],this
//         0041ce5a     ADD        ESP,0x10
//         0041ce5d     RET        0x4
    return 0;
}

RGE_Scenario_Header* RGE_Base_Game::new_scenario_header(RGE_Scenario* param_1) {
    /* TODO: Stub */
//                              RGE_Scenario_Header * __thiscall new_scenario_header(RGE_Base_Game *
//              RGE_Scenario_H    EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              RGE_Scenario *    Stack[0x4]:4   param_1                   XREF[1]:     0041ce90(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0041ce86(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0041ce9c(R), 0041cead(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0041ce80(*)
//                               ?new_scenario_header@RGE_Base_Game@@UAEPAVRGE_Scenario_Head  XREF[1]:     0056ef04(*)
//                               RGE_Base_Game::new_scenario_header
//                              basegame.cpp:1532 (22)
//         0041ce60     PUSH       -0x1
//         0041ce62     PUSH       FUN_0055ca3b
//         0041ce67     MOV        EAX,FS:[0x0]
//         0041ce6d     PUSH       EAX
//         0041ce6e     MOV        dword ptr FS:[0x0],ESP
//         0041ce75     PUSH       this
//                              basegame.cpp:1533 (38)
//         0041ce76     PUSH       0x14
//         0041ce78     CALL       operator_new                                     void * operator_new(uint param_1)
//         0041ce7d     ADD        ESP,0x4
//         0041ce80     MOV        dword ptr [ESP]=>local_10,EAX
//         0041ce84     TEST       EAX,EAX
//         0041ce86     MOV        dword ptr [ESP + local_4],0x0
//         0041ce8e     JZ         LAB_0041cead
//         0041ce90     MOV        this,dword ptr [ESP + param_1]
//         0041ce94     PUSH       this
//         0041ce95     MOV        this,EAX
//         0041ce97     CALL       RGE_Scenario_Header::RGE_Scenario_Header         undefined RGE_Scenario_Header(RGE_Scenario_He
//                              basegame.cpp:1534 (36)
//         0041ce9c     MOV        this,dword ptr [ESP + local_c]
//         0041cea0     MOV        dword ptr FS:[0x0],this
//         0041cea7     ADD        ESP,0x10
//         0041ceaa     RET        0x4
//                               LAB_0041cead                                                 XREF[1]:     0041ce8e(j)
//         0041cead     MOV        this,dword ptr [ESP + local_c]
//         0041ceb1     XOR        EAX,EAX
//         0041ceb3     MOV        dword ptr FS:[0x0],this
//         0041ceba     ADD        ESP,0x10
//         0041cebd     RET        0x4
    return 0;
}

RGE_Scenario* RGE_Base_Game::new_scenario_info(int param_1) {
    /* TODO: Stub */
//                              RGE_Scenario * __thiscall new_scenario_info(RGE_Base_Game * this, in
//              RGE_Scenario *    EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0041cef3(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0041cee9(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0041cf01(R), 0041cf12(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0041cee3(*)
//                               ?new_scenario_info@RGE_Base_Game@@UAEPAVRGE_Scenario@@H@Z    XREF[1]:     0056ef0c(*)
//                               RGE_Base_Game::new_scenario_info
//                              basegame.cpp:1540 (22)
//         0041cec0     PUSH       -0x1
//         0041cec2     PUSH       FUN_0055ca5b
//         0041cec7     MOV        EAX,FS:[0x0]
//         0041cecd     PUSH       EAX
//         0041cece     MOV        dword ptr FS:[0x0],ESP
//         0041ced5     PUSH       this
//                              basegame.cpp:1541 (43)
//         0041ced6     PUSH       0x1990
//         0041cedb     CALL       operator_new                                     void * operator_new(uint param_1)
//         0041cee0     ADD        ESP,0x4
//         0041cee3     MOV        dword ptr [ESP]=>local_10,EAX
//         0041cee7     TEST       EAX,EAX
//         0041cee9     MOV        dword ptr [ESP + local_4],0x0
//         0041cef1     JZ         LAB_0041cf12
//         0041cef3     MOV        this,dword ptr [ESP + param_1]
//         0041cef7     PUSH       0x0
//         0041cef9     PUSH       this
//         0041cefa     MOV        this,EAX
//         0041cefc     CALL       RGE_Scenario::RGE_Scenario                       undefined RGE_Scenario(RGE_Scenario * this, i
//                              basegame.cpp:1542 (36)
//         0041cf01     MOV        this,dword ptr [ESP + local_c]
//         0041cf05     MOV        dword ptr FS:[0x0],this
//         0041cf0c     ADD        ESP,0x10
//         0041cf0f     RET        0x4
//                               LAB_0041cf12                                                 XREF[1]:     0041cef1(j)
//         0041cf12     MOV        this,dword ptr [ESP + local_c]
//         0041cf16     XOR        EAX,EAX
//         0041cf18     MOV        dword ptr FS:[0x0],this
//         0041cf1f     ADD        ESP,0x10
//         0041cf22     RET        0x4
//         0041cf25     ??         90h
//         0041cf26     NOP
//         0041cf27     NOP
//         0041cf28     NOP
//         0041cf29     NOP
//         0041cf2a     NOP
//         0041cf2b     NOP
//         0041cf2c     NOP
//         0041cf2d     NOP
//         0041cf2e     NOP
//         0041cf2f     NOP
    return 0;
}

void RGE_Base_Game::get_campaign_info(long* param_1, long* param_2, long* param_3) {
    /* TODO: Stub */
//                              void __thiscall get_campaign_info(RGE_Base_Game * this, long * param
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              long *            Stack[0x4]:4   param_1                   XREF[1]:     0041cf3b(R)
//              long *            Stack[0x8]:4   param_2                   XREF[1]:     0041cf49(R)
//              long *            Stack[0xc]:4   param_3                   XREF[1]:     0041cf57(R)
//                               ?get_campaign_info@RGE_Base_Game@@QAEXAAJ00@Z                XREF[1]:     load_scenario:00544222(c)
//                               RGE_Base_Game::get_campaign_info
//                              basegame.cpp:1548 (3)
//         0041cf30     PUSH       ESI
//         0041cf31     MOV        ESI,this
//                              basegame.cpp:1549 (14)
//         0041cf33     MOV        this,dword ptr [ESI + 0x4]
//         0041cf36     CALL       RGE_Game_Info::get_current_campaign              long get_current_campaign(RGE_Game_Info * this)
//         0041cf3b     MOV        this,dword ptr [ESP + param_1]
//         0041cf3f     MOV        dword ptr [this->_padding_],EAX
//                              basegame.cpp:1550 (14)
//         0041cf41     MOV        this,dword ptr [ESI + 0x4]
//         0041cf44     CALL       RGE_Game_Info::get_current_player                long get_current_player(RGE_Game_Info * this)
//         0041cf49     MOV        EDX,dword ptr [ESP + param_2]
//         0041cf4d     MOV        dword ptr [EDX],EAX
//                              basegame.cpp:1551 (12)
//         0041cf4f     MOV        this,dword ptr [ESI + 0x4]
//         0041cf52     CALL       RGE_Game_Info::get_current_scenario              long get_current_scenario(RGE_Game_Info * this)
//         0041cf57     MOV        this,dword ptr [ESP + param_3]
//                              basegame.cpp:1552 (6)
//         0041cf5b     POP        ESI
//         0041cf5c     MOV        dword ptr [this->_padding_],EAX
//         0041cf5e     RET        0xc
//         0041cf61     ??         90h
//         0041cf62     NOP
//         0041cf63     NOP
//         0041cf64     NOP
//         0041cf65     NOP
//         0041cf66     NOP
//         0041cf67     NOP
//         0041cf68     NOP
//         0041cf69     NOP
//         0041cf6a     NOP
//         0041cf6b     NOP
//         0041cf6c     NOP
//         0041cf6d     NOP
//         0041cf6e     NOP
//         0041cf6f     NOP
    return;
}

uchar RGE_Base_Game::set_campaign_info(long param_1, long param_2, long param_3) {
    /* TODO: Stub */
//                              uchar __thiscall set_campaign_info(RGE_Base_Game * this, long param_
//              uchar             AL:1           <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0041cf70(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0041cf84(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     0041cf95(R)
//                               ?set_campaign_info@RGE_Base_Game@@QAEEJJJ@Z                  XREF[1]:     check_game_state:005434f7(c)
//                               RGE_Base_Game::set_campaign_info
//                              basegame.cpp:1558 (20)
//         0041cf70     MOV        EAX,dword ptr [ESP + param_1]
//         0041cf74     PUSH       ESI
//         0041cf75     MOV        ESI,this
//         0041cf77     PUSH       EAX
//         0041cf78     MOV        this,dword ptr [ESI + 0x4]
//         0041cf7b     CALL       RGE_Game_Info::set_current_campaign              uchar set_current_campaign(RGE_Game_Info * th
//         0041cf80     TEST       AL,AL
//         0041cf82     JZ         LAB_0041cfac
//                              basegame.cpp:1560 (17)
//         0041cf84     MOV        this,dword ptr [ESP + param_2]
//         0041cf88     PUSH       this
//         0041cf89     MOV        this,dword ptr [ESI + 0x4]
//         0041cf8c     CALL       RGE_Game_Info::set_current_person                uchar set_current_person(RGE_Game_Info * this
//         0041cf91     TEST       AL,AL
//         0041cf93     JZ         LAB_0041cfac
//                              basegame.cpp:1561 (17)
//         0041cf95     MOV        EDX,dword ptr [ESP + param_3]
//         0041cf99     MOV        this,dword ptr [ESI + 0x4]
//         0041cf9c     PUSH       EDX
//         0041cf9d     CALL       RGE_Game_Info::set_current_scenario              uchar set_current_scenario(RGE_Game_Info * th
//         0041cfa2     TEST       AL,AL
//         0041cfa4     JZ         LAB_0041cfac
//                              basegame.cpp:1562 (2)
//         0041cfa6     MOV        AL,0x1
//                              basegame.cpp:1564 (4)
//         0041cfa8     POP        ESI
//         0041cfa9     RET        0xc
//                               LAB_0041cfac                                                 XREF[3]:     0041cf82(j), 0041cf93(j),
//                                                                                                         0041cfa4(j)
//                              basegame.cpp:1563 (2)
//         0041cfac     XOR        AL,AL
//                              basegame.cpp:1564 (4)
//         0041cfae     POP        ESI
//         0041cfaf     RET        0xc
//         0041cfb2     ??         90h
//         0041cfb3     NOP
//         0041cfb4     NOP
//         0041cfb5     NOP
//         0041cfb6     NOP
//         0041cfb7     NOP
//         0041cfb8     NOP
//         0041cfb9     NOP
//         0041cfba     NOP
//         0041cfbb     NOP
//         0041cfbc     NOP
//         0041cfbd     NOP
//         0041cfbe     NOP
//         0041cfbf     NOP
    return 0;
}

void RGE_Base_Game::set_campaign_win() {
    /* TODO: Stub */
//                              void __thiscall set_campaign_win(RGE_Base_Game * this)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?set_campaign_win@RGE_Base_Game@@QAEXXZ                      XREF[1]:     check_game_state:00543519(c)
//                               RGE_Base_Game::set_campaign_win
//                              basegame.cpp:1570 (8)
//         0041cfc0     MOV        this,dword ptr [ECX + this->player_game_info]
//         0041cfc3     JMP        RGE_Game_Info::notify_of_scenario_complete       void notify_of_scenario_complete(RGE_Game_Inf
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//         0041cfc8     ??         90h
//         0041cfc9     NOP
//         0041cfca     NOP
//         0041cfcb     NOP
//         0041cfcc     NOP
//         0041cfcd     NOP
//         0041cfce     NOP
//         0041cfcf     NOP
    return;
}

int RGE_Base_Game::run() {
    /* TODO: Stub */
//                              int __thiscall run(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              tagMSG            Stack[-0x20]   msg                       XREF[0,5]:   0041d01b(*), 0041d031(*), 0041d062(*), 0041d028(R),
//                                                                                     0041d086(R)
//                               ?run@RGE_Base_Game@@UAEHXZ                                   XREF[2]:     0056eed4(*), 005771ac(*)
//                               RGE_Base_Game::run
//                              basegame.cpp:1578 (4)
//         0041cfd0     SUB        ESP,0x1c
//         0041cfd3     PUSH       EBX
//                              basegame.cpp:1608 (65)
//         0041cfd4     MOV        EBX,dword ptr [->USER32.DLL::DispatchMessageA]   = 0048ad76
//         0041cfda     PUSH       EBP
//         0041cfdb     MOV        EBP,dword ptr [->USER32.DLL::PeekMessageA]       = 0048ad66
//         0041cfe1     PUSH       ESI
//         0041cfe2     PUSH       EDI
//         0041cfe3     MOV        EDI,dword ptr [->USER32.DLL::TranslateMessage]   = 0048ad52
//         0041cfe9     MOV        ESI,this
//                               LAB_0041cfeb                                                 XREF[4]:     0041d040(j), 0041d050(j),
//                                                                                                         0041d05c(j), 0041d081(j)
//         0041cfeb     MOV        EAX,dword ptr [ESI + 0x18]
//         0041cfee     TEST       EAX,EAX
//         0041cff0     JZ         LAB_0041d05e
//         0041cff2     MOV        EAX,dword ptr [ESI + 0x1b0]
//         0041cff8     CMP        EAX,0x4
//         0041cffb     JZ         LAB_0041d002
//         0041cffd     CMP        EAX,0x2
//         0041d000     JNZ        LAB_0041d05e
//                               LAB_0041d002                                                 XREF[1]:     0041cffb(j)
//         0041d002     MOV        this,dword ptr [ESI + 0x18c]
//         0041d008     TEST       this,this
//         0041d00a     JZ         LAB_0041d015
//         0041d00c     CALL       TCommunications_Handler::IsPaused                int IsPaused(TCommunications_Handler * this)
//         0041d011     TEST       EAX,EAX
//         0041d013     JNZ        LAB_0041d05e
//                               LAB_0041d015                                                 XREF[1]:     0041d00a(j)
//                              basegame.cpp:1623 (19)
//         0041d015     PUSH       0x1
//         0041d017     PUSH       0x0=>DAT_fffffff8
//         0041d019     PUSH       0x0=>DAT_fffffff4
//         0041d01b     LEA        EAX=>msg.message,[ESP + 0x1c]
//         0041d01f     PUSH       0x0=>DAT_fffffff0
//         0041d021     PUSH       EAX
//         0041d022     CALL       EBP=>USER32.DLL::PeekMessageA
//         0041d024     TEST       EAX,EAX
//         0041d026     JZ         LAB_0041d052
//                              basegame.cpp:1625 (7)
//         0041d028     CMP        dword ptr [ESP + msg.wParam],0x12
//         0041d02d     JZ         LAB_0041d086
//                              basegame.cpp:1628 (19)
//         0041d02f     MOV        EDX,dword ptr [ESI]
//         0041d031     LEA        EAX=>msg.message,[ESP + 0x10]
//         0041d035     PUSH       EAX
//         0041d036     MOV        this,ESI
//         0041d038     CALL       dword ptr [EDX + 0xb8]
//         0041d03e     TEST       EAX,EAX
//         0041d040     JZ         LAB_0041cfeb
//                              basegame.cpp:1630 (7)
//         0041d042     LEA        this,[ESP + 0x10]
//         0041d046     PUSH       this
//         0041d047     CALL       EDI=>USER32.DLL::TranslateMessage
//                              basegame.cpp:1631 (7)
//         0041d049     LEA        EDX,[ESP + 0x10]
//         0041d04d     PUSH       EDX
//         0041d04e     CALL       EBX=>USER32.DLL::DispatchMessageA
//                              basegame.cpp:1634 (2)
//         0041d050     JMP        LAB_0041cfeb
//                               LAB_0041d052                                                 XREF[1]:     0041d026(j)
//                              basegame.cpp:1635 (12)
//         0041d052     MOV        EAX,dword ptr [ESI]
//         0041d054     MOV        this,ESI
//         0041d056     CALL       dword ptr [EAX + 0xbc]
//         0041d05c     JMP        LAB_0041cfeb
//                               LAB_0041d05e                                                 XREF[3]:     0041cff0(j), 0041d000(j),
//                                                                                                         0041d013(j)
//                              basegame.cpp:1611 (21)
//         0041d05e     PUSH       0x0
//         0041d060     PUSH       0x0=>DAT_fffffff8
//         0041d062     LEA        this=>msg.message,[ESP + 0x18]
//         0041d066     PUSH       0x0=>DAT_fffffff4
//         0041d068     PUSH       this=>DAT_fffffff0
//         0041d069     CALL       dword ptr [->USER32.DLL::GetMessageA]            = 0048ad44
//         0041d06f     TEST       EAX,EAX
//         0041d071     JZ         LAB_0041d086
//                              basegame.cpp:1615 (7)
//         0041d073     LEA        EDX,[ESP + 0x10]
//         0041d077     PUSH       EDX
//         0041d078     CALL       EDI=>USER32.DLL::TranslateMessage
//                              basegame.cpp:1616 (12)
//         0041d07a     LEA        EAX,[ESP + 0x10]
//         0041d07e     PUSH       EAX
//         0041d07f     CALL       EBX=>USER32.DLL::DispatchMessageA
//         0041d081     JMP        LAB_0041cfeb
//                               LAB_0041d086                                                 XREF[2]:     0041d02d(j), 0041d071(j)
//                              basegame.cpp:1639 (4)
//         0041d086     MOV        EAX,dword ptr [ESP + msg.lParam]
//                              basegame.cpp:1640 (8)
//         0041d08a     POP        EDI
//         0041d08b     POP        ESI
//         0041d08c     POP        EBP
//         0041d08d     POP        EBX
//         0041d08e     ADD        ESP,0x1c
//         0041d091     RET
//         0041d092     ??         90h
//         0041d093     NOP
//         0041d094     NOP
//         0041d095     NOP
//         0041d096     NOP
//         0041d097     NOP
//         0041d098     NOP
//         0041d099     NOP
//         0041d09a     NOP
//         0041d09b     NOP
//         0041d09c     NOP
//         0041d09d     NOP
//         0041d09e     NOP
//         0041d09f     NOP
    return 0;
}

int RGE_Base_Game::setup_cmd_options() {
    /* TODO: Stub */
//                              int __thiscall setup_cmd_options(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              uchar[256]        Stack[-0x104   temp_str                  XREF[0,1]:   0041d0ce(W)
//              char[256]         Stack[-0x204   cmd_line                  XREF[0,2]:   0041d0b4(*), 0041d0c7(*)
//                               ?setup_cmd_options@RGE_Base_Game@@MAEHXZ                     XREF[2]:     setup_cmd_options:005221e6(c),
//                               RGE_Base_Game::setup_cmd_options                                          0056ef34(*)
//                              basegame.cpp:1646 (12)
//         0041d0a0     SUB        ESP,0x200
//         0041d0a6     PUSH       EBX
//         0041d0a7     PUSH       EBP
//         0041d0a8     MOV        EBP,this
//         0041d0aa     PUSH       ESI
//         0041d0ab     PUSH       EDI
//                              basegame.cpp:1651 (27)
//         0041d0ac     PUSH       0xff
//         0041d0b1     MOV        EAX,dword ptr [EBP + 0xc]
//         0041d0b4     LEA        this=>cmd_line[4],[ESP + 0x14]
//         0041d0b8     ADD        EAX,0x518
//         0041d0bd     PUSH       EAX
//         0041d0be     PUSH       this
//         0041d0bf     CALL       strncpy                                          undefined strncpy()
//         0041d0c4     ADD        ESP,0xc
//                              basegame.cpp:1654 (20)
//         0041d0c7     LEA        EDX=>cmd_line[4],[ESP + 0x10]
//         0041d0cb     XOR        EBX,EBX
//         0041d0cd     PUSH       EDX
//         0041d0ce     MOV        byte ptr [ESP + temp_str[3]],BL
//         0041d0d5     CALL       dword ptr [->USER32.DLL::CharUpperA]             = 0048ad8a
//                              basegame.cpp:1657 (71)
//         0041d0db     LEA        EAX,[ESP + 0x10]
//         0041d0df     PUSH       s_NOSTARTUP                                      = "NOSTARTUP"
//         0041d0e4     PUSH       EAX=>DAT_fffffff8
//         0041d0e5     CALL       strstr                                           undefined strstr()
//         0041d0ea     ADD        ESP,0x8
//         0041d0ed     MOV        EDI,0x1
//         0041d0f2     TEST       EAX,EAX
//         0041d0f4     JNZ        LAB_0041d122
//         0041d0f6     LEA        this,[ESP + 0x10]
//         0041d0fa     PUSH       s_NO_STARTUP                                     = "NO STARTUP"
//         0041d0ff     PUSH       this=>DAT_fffffff8
//         0041d100     CALL       strstr                                           undefined strstr()
//         0041d105     ADD        ESP,0x8
//         0041d108     TEST       EAX,EAX
//         0041d10a     JNZ        LAB_0041d122
//         0041d10c     LEA        EDX,[ESP + 0x10]
//         0041d110     PUSH       s_NO_STARTUP                                     = "NO_STARTUP"
//         0041d115     PUSH       EDX=>DAT_fffffff8
//         0041d116     CALL       strstr                                           undefined strstr()
//         0041d11b     ADD        ESP,0x8
//         0041d11e     TEST       EAX,EAX
//         0041d120     JZ         LAB_0041d12b
//                               LAB_0041d122                                                 XREF[2]:     0041d0f4(j), 0041d10a(j)
//                              basegame.cpp:1658 (9)
//         0041d122     MOV        EAX,dword ptr [EBP + 0xc]
//         0041d125     MOV        dword ptr [EAX + 0x890],EDI
//                               LAB_0041d12b                                                 XREF[1]:     0041d120(j)
//                              basegame.cpp:1660 (66)
//         0041d12b     LEA        this,[ESP + 0x10]
//         0041d12f     PUSH       s_SYSTEMMEMORY                                   = "SYSTEMMEMORY"
//         0041d134     PUSH       this=>DAT_fffffff8
//         0041d135     CALL       strstr                                           undefined strstr()
//         0041d13a     ADD        ESP,0x8
//         0041d13d     TEST       EAX,EAX
//         0041d13f     JNZ        LAB_0041d16d
//         0041d141     LEA        EDX,[ESP + 0x10]
//         0041d145     PUSH       s_SYSTEM_MEMORY                                  = "SYSTEM MEMORY"
//         0041d14a     PUSH       EDX=>DAT_fffffff8
//         0041d14b     CALL       strstr                                           undefined strstr()
//         0041d150     ADD        ESP,0x8
//         0041d153     TEST       EAX,EAX
//         0041d155     JNZ        LAB_0041d16d
//         0041d157     LEA        EAX,[ESP + 0x10]
//         0041d15b     PUSH       s_SYSTEM_MEMORY                                  = "SYSTEM_MEMORY"
//         0041d160     PUSH       EAX=>DAT_fffffff8
//         0041d161     CALL       strstr                                           undefined strstr()
//         0041d166     ADD        ESP,0x8
//         0041d169     TEST       EAX,EAX
//         0041d16b     JZ         LAB_0041d176
//                               LAB_0041d16d                                                 XREF[2]:     0041d13f(j), 0041d155(j)
//                              basegame.cpp:1661 (9)
//         0041d16d     MOV        this,dword ptr [EBP + 0xc]
//         0041d170     MOV        dword ptr [ECX + this+0x8a0],EDI
//                               LAB_0041d176                                                 XREF[1]:     0041d16b(j)
//                              basegame.cpp:1663 (66)
//         0041d176     LEA        EDX,[ESP + 0x10]
//         0041d17a     PUSH       s_MIDIMUSIC                                      = "MIDIMUSIC"
//         0041d17f     PUSH       EDX=>DAT_fffffff8
//         0041d180     CALL       strstr                                           undefined strstr()
//         0041d185     ADD        ESP,0x8
//         0041d188     TEST       EAX,EAX
//         0041d18a     JNZ        LAB_0041d1b8
//         0041d18c     LEA        EAX,[ESP + 0x10]
//         0041d190     PUSH       s_MIDI_MUSIC                                     = "MIDI MUSIC"
//         0041d195     PUSH       EAX=>DAT_fffffff8
//         0041d196     CALL       strstr                                           undefined strstr()
//         0041d19b     ADD        ESP,0x8
//         0041d19e     TEST       EAX,EAX
//         0041d1a0     JNZ        LAB_0041d1b8
//         0041d1a2     LEA        this,[ESP + 0x10]
//         0041d1a6     PUSH       s_MIDI_MUSIC                                     = "MIDI_MUSIC"
//         0041d1ab     PUSH       this=>DAT_fffffff8
//         0041d1ac     CALL       strstr                                           undefined strstr()
//         0041d1b1     ADD        ESP,0x8
//         0041d1b4     TEST       EAX,EAX
//         0041d1b6     JZ         LAB_0041d1e5
//                               LAB_0041d1b8                                                 XREF[2]:     0041d18a(j), 0041d1a0(j)
//                              basegame.cpp:1665 (9)
//         0041d1b8     MOV        EDX,dword ptr [EBP + 0xc]
//         0041d1bb     MOV        dword ptr [EDX + 0x8a4],EDI
//                              basegame.cpp:1666 (9)
//         0041d1c1     MOV        EAX,dword ptr [EBP + 0xc]
//         0041d1c4     MOV        dword ptr [EAX + 0x8ac],EBX
//                              basegame.cpp:1667 (9)
//         0041d1ca     MOV        this,dword ptr [EBP + 0xc]
//         0041d1cd     MOV        dword ptr [ECX + this+0x8b0],EBX
//                              basegame.cpp:1668 (9)
//         0041d1d3     MOV        EDX,dword ptr [EBP + 0xc]
//         0041d1d6     MOV        dword ptr [EDX + 0x8b4],EDI
//                              basegame.cpp:1669 (9)
//         0041d1dc     MOV        EAX,dword ptr [EBP + 0xc]
//         0041d1df     MOV        dword ptr [EAX + 0x8b8],EBX
//                               LAB_0041d1e5                                                 XREF[1]:     0041d1b6(j)
//                              basegame.cpp:1672 (22)
//         0041d1e5     LEA        this,[ESP + 0x10]
//         0041d1e9     PUSH       s_MSYNC                                          = "MSYNC"
//         0041d1ee     PUSH       this=>DAT_fffffff8
//         0041d1ef     CALL       strstr                                           undefined strstr()
//         0041d1f4     ADD        ESP,0x8
//         0041d1f7     TEST       EAX,EAX
//         0041d1f9     JZ         LAB_0041d201
//                              basegame.cpp:1673 (6)
//         0041d1fb     MOV        dword ptr [EBP + 0x1c8],EDI
//                               LAB_0041d201                                                 XREF[1]:     0041d1f9(j)
//                              basegame.cpp:1675 (22)
//         0041d201     LEA        EDX,[ESP + 0x10]
//         0041d205     PUSH       s_MFILL                                          = "MFILL"
//         0041d20a     PUSH       EDX=>DAT_fffffff8
//         0041d20b     CALL       strstr                                           undefined strstr()
//         0041d210     ADD        ESP,0x8
//         0041d213     NEG        EAX
//         0041d215     SBB        EAX,EAX
//                              basegame.cpp:1680 (72)
//         0041d217     PUSH       s_NOSOUND                                        = "NOSOUND"
//         0041d21c     INC        EAX
//         0041d21d     MOV        [DDSys_CanColorFill],EAX                         = 1h
//         0041d222     LEA        EAX,[ESP + 0x14]
//         0041d226     PUSH       EAX=>DAT_fffffff8
//         0041d227     CALL       strstr                                           undefined strstr()
//         0041d22c     ADD        ESP,0x8
//         0041d22f     TEST       EAX,EAX
//         0041d231     JNZ        LAB_0041d25f
//         0041d233     LEA        this,[ESP + 0x10]
//         0041d237     PUSH       s_NO_SOUND                                       = "NO SOUND"
//         0041d23c     PUSH       this=>DAT_fffffff8
//         0041d23d     CALL       strstr                                           undefined strstr()
//         0041d242     ADD        ESP,0x8
//         0041d245     TEST       EAX,EAX
//         0041d247     JNZ        LAB_0041d25f
//         0041d249     LEA        EDX,[ESP + 0x10]
//         0041d24d     PUSH       s_NO_SOUND                                       = "NO_SOUND"
//         0041d252     PUSH       EDX=>DAT_fffffff8
//         0041d253     CALL       strstr                                           undefined strstr()
//         0041d258     ADD        ESP,0x8
//         0041d25b     TEST       EAX,EAX
//         0041d25d     JZ         LAB_0041d268
//                               LAB_0041d25f                                                 XREF[2]:     0041d231(j), 0041d247(j)
//                              basegame.cpp:1681 (9)
//         0041d25f     MOV        EAX,dword ptr [EBP + 0xc]
//         0041d262     MOV        dword ptr [EAX + 0x8a8],EBX
//                               LAB_0041d268                                                 XREF[1]:     0041d25d(j)
//                              basegame.cpp:1683 (22)
//         0041d268     LEA        this,[ESP + 0x10]
//         0041d26c     PUSH       s_640                                            = "640"
//         0041d271     PUSH       this=>DAT_fffffff8
//         0041d272     CALL       strstr                                           undefined strstr()
//         0041d277     ADD        ESP,0x8
//         0041d27a     TEST       EAX,EAX
//         0041d27c     JZ         LAB_0041d298
//                              basegame.cpp:1685 (13)
//         0041d27e     MOV        EDX,dword ptr [EBP + 0xc]
//         0041d281     MOV        dword ptr [EDX + 0x8e0],0x280
//                              basegame.cpp:1686 (13)
//         0041d28b     MOV        EAX,dword ptr [EBP + 0xc]
//         0041d28e     MOV        dword ptr [EAX + 0x8e4],0x1e0
//                               LAB_0041d298                                                 XREF[1]:     0041d27c(j)
//                              basegame.cpp:1689 (22)
//         0041d298     LEA        this,[ESP + 0x10]
//         0041d29c     PUSH       s_800                                            = "800"
//         0041d2a1     PUSH       this=>DAT_fffffff8
//         0041d2a2     CALL       strstr                                           undefined strstr()
//         0041d2a7     ADD        ESP,0x8
//         0041d2aa     TEST       EAX,EAX
//         0041d2ac     JZ         LAB_0041d2c8
//                              basegame.cpp:1691 (13)
//         0041d2ae     MOV        EDX,dword ptr [EBP + 0xc]
//         0041d2b1     MOV        dword ptr [EDX + 0x8e0],0x320
//                              basegame.cpp:1692 (13)
//         0041d2bb     MOV        EAX,dword ptr [EBP + 0xc]
//         0041d2be     MOV        dword ptr [EAX + 0x8e4],0x258
//                               LAB_0041d2c8                                                 XREF[1]:     0041d2ac(j)
//                              basegame.cpp:1695 (22)
//         0041d2c8     LEA        this,[ESP + 0x10]
//         0041d2cc     PUSH       s_1024                                           = "1024"
//         0041d2d1     PUSH       this=>DAT_fffffff8
//         0041d2d2     CALL       strstr                                           undefined strstr()
//         0041d2d7     ADD        ESP,0x8
//         0041d2da     TEST       EAX,EAX
//         0041d2dc     JZ         LAB_0041d2f8
//                              basegame.cpp:1697 (13)
//         0041d2de     MOV        EDX,dword ptr [EBP + 0xc]
//         0041d2e1     MOV        dword ptr [EDX + 0x8e0],0x400
//                              basegame.cpp:1698 (13)
//         0041d2eb     MOV        EAX,dword ptr [EBP + 0xc]
//         0041d2ee     MOV        dword ptr [EAX + 0x8e4],0x300
//                               LAB_0041d2f8                                                 XREF[1]:     0041d2dc(j)
//                              basegame.cpp:1702 (22)
//         0041d2f8     LEA        this,[ESP + 0x10]
//         0041d2fc     PUSH       s_ALLCP                                          = "ALLCP"
//         0041d301     PUSH       this=>DAT_fffffff8
//         0041d302     CALL       strstr                                           undefined strstr()
//         0041d307     ADD        ESP,0x8
//         0041d30a     TEST       EAX,EAX
//         0041d30c     JZ         LAB_0041d340
//                              basegame.cpp:1704 (6)
//         0041d30e     MOV        dword ptr [all_cp],EDI
//                              basegame.cpp:1705 (6)
//         0041d314     MOV        dword ptr [do_run_log],EDI
//                              basegame.cpp:1706 (6)
//         0041d31a     MOV        dword ptr [EBP + 0x1a0],EBX
//                              basegame.cpp:1707 (6)
//         0041d320     MOV        dword ptr [do_debug_timeGetTime],EDI
//                              basegame.cpp:1708 (10)
//         0041d326     MOV        dword ptr [debug_timeGetTime_interval],0xa       = 5h
//                              basegame.cpp:1709 (6)
//         0041d330     MOV        dword ptr [do_fixed_update],EDI
//                              basegame.cpp:1710 (10)
//         0041d336     MOV        dword ptr [fixed_update_time],0x14               = 64h
//                               LAB_0041d340                                                 XREF[1]:     0041d30c(j)
//                              basegame.cpp:1715 (18)
//         0041d340     LEA        EDX,[ESP + 0x10]
//         0041d344     PUSH       s_RESEND1=                                       = "RESEND1="
//         0041d349     PUSH       EDX=>DAT_fffffff8
//         0041d34a     CALL       __mbsstr                                         undefined __mbsstr()
//         0041d34f     ADD        ESP,0x8
//                              basegame.cpp:1716 (8)
//         0041d352     CMP        EAX,EBX
//         0041d354     JZ         LAB_0041d3de
//                              basegame.cpp:1718 (5)
//         0041d35a     CMP        byte ptr [EAX],0x3d
//         0041d35d     JZ         LAB_0041d370
//                               LAB_0041d35f                                                 XREF[1]:     0041d36e(j)
//                              basegame.cpp:1719 (17)
//         0041d35f     PUSH       EDI
//         0041d360     PUSH       EAX=>DAT_fffffff8
//         0041d361     CALL       __mbsninc                                        undefined __mbsninc()
//         0041d366     MOV        this,byte ptr [EAX]
//         0041d368     ADD        ESP,0x8
//         0041d36b     CMP        this,0x3d
//         0041d36e     JNZ        LAB_0041d35f
//                               LAB_0041d370                                                 XREF[1]:     0041d35d(j)
//                              basegame.cpp:1720 (9)
//         0041d370     PUSH       EDI
//         0041d371     PUSH       EAX=>DAT_fffffff8
//         0041d372     CALL       __mbsninc                                        undefined __mbsninc()
//         0041d377     MOV        ESI,EAX
//                              basegame.cpp:1722 (33)
//         0041d379     XOR        EAX,EAX
//         0041d37b     ADD        ESP,0x8
//         0041d37e     MOV        byte ptr [ESP + 0x110],0x0
//         0041d386     MOV        AL,byte ptr [ESI]
//         0041d388     PUSH       EAX
//         0041d389     CALL       __ismbcspace                                     undefined __ismbcspace()
//         0041d38e     ADD        ESP,0x4
//         0041d391     TEST       EAX,EAX
//         0041d393     JNZ        LAB_0041d3c9
//                               LAB_0041d395                                                 XREF[1]:     0041d3c7(j)
//         0041d395     CMP        byte ptr [ESI],0x0
//         0041d398     JZ         LAB_0041d3c9
//                              basegame.cpp:1724 (18)
//         0041d39a     PUSH       EDI
//         0041d39b     LEA        this,[ESP + 0x114]
//         0041d3a2     PUSH       ESI=>DAT_fffffff8
//         0041d3a3     PUSH       this=>DAT_fffffff4
//         0041d3a4     CALL       __mbsncat                                        undefined __mbsncat()
//         0041d3a9     ADD        ESP,0xc
//                              basegame.cpp:1725 (29)
//         0041d3ac     PUSH       EDI
//         0041d3ad     PUSH       ESI=>DAT_fffffff8
//         0041d3ae     CALL       __mbsninc                                        undefined __mbsninc()
//         0041d3b3     MOV        ESI,EAX
//         0041d3b5     XOR        EDX,EDX
//         0041d3b7     ADD        ESP,0x8
//         0041d3ba     MOV        DL,byte ptr [ESI]
//         0041d3bc     PUSH       EDX
//         0041d3bd     CALL       __ismbcspace                                     undefined __ismbcspace()
//         0041d3c2     ADD        ESP,0x4
//         0041d3c5     TEST       EAX,EAX
//         0041d3c7     JZ         LAB_0041d395
//                               LAB_0041d3c9                                                 XREF[2]:     0041d393(j), 0041d398(j)
//                              basegame.cpp:1727 (21)
//         0041d3c9     LEA        EAX,[ESP + 0x110]
//         0041d3d0     PUSH       EAX
//         0041d3d1     CALL       atol                                             undefined atol()
//         0041d3d6     ADD        ESP,0x4
//         0041d3d9     MOV        [resend_adj1],EAX
//                               LAB_0041d3de                                                 XREF[1]:     0041d354(j)
//                              basegame.cpp:1730 (18)
//         0041d3de     LEA        this,[ESP + 0x10]
//         0041d3e2     PUSH       s_RESEND2=                                       = "RESEND2="
//         0041d3e7     PUSH       this=>DAT_fffffff8
//         0041d3e8     CALL       __mbsstr                                         undefined __mbsstr()
//         0041d3ed     ADD        ESP,0x8
//                              basegame.cpp:1731 (8)
//         0041d3f0     CMP        EAX,EBX
//         0041d3f2     JZ         LAB_0041d47c
//                              basegame.cpp:1733 (5)
//         0041d3f8     CMP        byte ptr [EAX],0x3d
//         0041d3fb     JZ         LAB_0041d40e
//                               LAB_0041d3fd                                                 XREF[1]:     0041d40c(j)
//                              basegame.cpp:1734 (17)
//         0041d3fd     PUSH       EDI
//         0041d3fe     PUSH       EAX=>DAT_fffffff8
//         0041d3ff     CALL       __mbsninc                                        undefined __mbsninc()
//         0041d404     MOV        this,byte ptr [EAX]
//         0041d406     ADD        ESP,0x8
//         0041d409     CMP        this,0x3d
//         0041d40c     JNZ        LAB_0041d3fd
//                               LAB_0041d40e                                                 XREF[1]:     0041d3fb(j)
//                              basegame.cpp:1735 (9)
//         0041d40e     PUSH       EDI
//         0041d40f     PUSH       EAX=>DAT_fffffff8
//         0041d410     CALL       __mbsninc                                        undefined __mbsninc()
//         0041d415     MOV        ESI,EAX
//                              basegame.cpp:1737 (33)
//         0041d417     XOR        EDX,EDX
//         0041d419     ADD        ESP,0x8
//         0041d41c     MOV        byte ptr [ESP + 0x110],0x0
//         0041d424     MOV        DL,byte ptr [ESI]
//         0041d426     PUSH       EDX
//         0041d427     CALL       __ismbcspace                                     undefined __ismbcspace()
//         0041d42c     ADD        ESP,0x4
//         0041d42f     TEST       EAX,EAX
//         0041d431     JNZ        LAB_0041d467
//                               LAB_0041d433                                                 XREF[1]:     0041d465(j)
//         0041d433     CMP        byte ptr [ESI],0x0
//         0041d436     JZ         LAB_0041d467
//                              basegame.cpp:1739 (18)
//         0041d438     PUSH       EDI
//         0041d439     LEA        EAX,[ESP + 0x114]
//         0041d440     PUSH       ESI=>DAT_fffffff8
//         0041d441     PUSH       EAX=>DAT_fffffff4
//         0041d442     CALL       __mbsncat                                        undefined __mbsncat()
//         0041d447     ADD        ESP,0xc
//                              basegame.cpp:1740 (29)
//         0041d44a     PUSH       EDI
//         0041d44b     PUSH       ESI=>DAT_fffffff8
//         0041d44c     CALL       __mbsninc                                        undefined __mbsninc()
//         0041d451     MOV        ESI,EAX
//         0041d453     XOR        this,this
//         0041d455     ADD        ESP,0x8
//         0041d458     MOV        this,byte ptr [ESI]
//         0041d45a     PUSH       this
//         0041d45b     CALL       __ismbcspace                                     undefined __ismbcspace()
//         0041d460     ADD        ESP,0x4
//         0041d463     TEST       EAX,EAX
//         0041d465     JZ         LAB_0041d433
//                               LAB_0041d467                                                 XREF[2]:     0041d431(j), 0041d436(j)
//                              basegame.cpp:1742 (21)
//         0041d467     LEA        EDX,[ESP + 0x110]
//         0041d46e     PUSH       EDX
//         0041d46f     CALL       atol                                             undefined atol()
//         0041d474     ADD        ESP,0x4
//         0041d477     MOV        [resend_adj2],EAX
//                               LAB_0041d47c                                                 XREF[1]:     0041d3f2(j)
//                              basegame.cpp:1747 (44)
//         0041d47c     LEA        EAX,[ESP + 0x10]
//         0041d480     PUSH       s_NOMOUSE                                        = "NOMOUSE"
//         0041d485     PUSH       EAX=>DAT_fffffff8
//         0041d486     CALL       strstr                                           undefined strstr()
//         0041d48b     ADD        ESP,0x8
//         0041d48e     TEST       EAX,EAX
//         0041d490     JNZ        LAB_0041d4a8
//         0041d492     LEA        this,[ESP + 0x10]
//         0041d496     PUSH       s_NO_MOUSE                                       = "NO MOUSE"
//         0041d49b     PUSH       this=>DAT_fffffff8
//         0041d49c     CALL       strstr                                           undefined strstr()
//         0041d4a1     ADD        ESP,0x8
//         0041d4a4     TEST       EAX,EAX
//         0041d4a6     JZ         LAB_0041d4ab
//                               LAB_0041d4a8                                                 XREF[1]:     0041d490(j)
//                              basegame.cpp:1748 (3)
//         0041d4a8     MOV        dword ptr [EBP + 0x54],EBX
//                               LAB_0041d4ab                                                 XREF[1]:     0041d4a6(j)
//                              basegame.cpp:1750 (22)
//         0041d4ab     LEA        EDX,[ESP + 0x10]
//         0041d4af     PUSH       s_WING                                           = "WING"
//         0041d4b4     PUSH       EDX=>DAT_fffffff8
//         0041d4b5     CALL       strstr                                           undefined strstr()
//         0041d4ba     ADD        ESP,0x8
//         0041d4bd     TEST       EAX,EAX
//         0041d4bf     JZ         LAB_0041d4d3
//                              basegame.cpp:1752 (9)
//         0041d4c1     MOV        EAX,dword ptr [EBP + 0xc]
//         0041d4c4     MOV        dword ptr [EAX + 0x894],EBX
//                              basegame.cpp:1753 (9)
//         0041d4ca     MOV        this,dword ptr [EBP + 0xc]
//         0041d4cd     MOV        dword ptr [ECX + this+0x89c],EBX
//                               LAB_0041d4d3                                                 XREF[1]:     0041d4bf(j)
//                              basegame.cpp:1756 (44)
//         0041d4d3     LEA        EDX,[ESP + 0x10]
//         0041d4d7     PUSH       s_DIRECTDRAW                                     = "DIRECTDRAW"
//         0041d4dc     PUSH       EDX=>DAT_fffffff8
//         0041d4dd     CALL       strstr                                           undefined strstr()
//         0041d4e2     ADD        ESP,0x8
//         0041d4e5     TEST       EAX,EAX
//         0041d4e7     JNZ        LAB_0041d4ff
//         0041d4e9     LEA        EAX,[ESP + 0x10]
//         0041d4ed     PUSH       s_DIRECT_DRAW                                    = "DIRECT DRAW"
//         0041d4f2     PUSH       EAX=>DAT_fffffff8
//         0041d4f3     CALL       strstr                                           undefined strstr()
//         0041d4f8     ADD        ESP,0x8
//         0041d4fb     TEST       EAX,EAX
//         0041d4fd     JZ         LAB_0041d508
//                               LAB_0041d4ff                                                 XREF[1]:     0041d4e7(j)
//                              basegame.cpp:1757 (9)
//         0041d4ff     MOV        this,dword ptr [EBP + 0xc]
//         0041d502     MOV        dword ptr [ECX + this+0x89c],EDI
//                               LAB_0041d508                                                 XREF[1]:     0041d4fd(j)
//                              basegame.cpp:1759 (66)
//         0041d508     LEA        EDX,[ESP + 0x10]
//         0041d50c     PUSH       s_FULLSCREEN                                     = "FULLSCREEN"
//         0041d511     PUSH       EDX=>DAT_fffffff8
//         0041d512     CALL       strstr                                           undefined strstr()
//         0041d517     ADD        ESP,0x8
//         0041d51a     TEST       EAX,EAX
//         0041d51c     JNZ        LAB_0041d54a
//         0041d51e     LEA        EAX,[ESP + 0x10]
//         0041d522     PUSH       s_FULL_SCREEN                                    = "FULL SCREEN"
//         0041d527     PUSH       EAX=>DAT_fffffff8
//         0041d528     CALL       strstr                                           undefined strstr()
//         0041d52d     ADD        ESP,0x8
//         0041d530     TEST       EAX,EAX
//         0041d532     JNZ        LAB_0041d54a
//         0041d534     LEA        this,[ESP + 0x10]
//         0041d538     PUSH       s_FULL_SCREEN                                    = "FULL_SCREEN"
//         0041d53d     PUSH       this=>DAT_fffffff8
//         0041d53e     CALL       strstr                                           undefined strstr()
//         0041d543     ADD        ESP,0x8
//         0041d546     TEST       EAX,EAX
//         0041d548     JZ         LAB_0041d55c
//                               LAB_0041d54a                                                 XREF[2]:     0041d51c(j), 0041d532(j)
//                              basegame.cpp:1761 (9)
//         0041d54a     MOV        EDX,dword ptr [EBP + 0xc]
//         0041d54d     MOV        dword ptr [EDX + 0x894],EDI
//                              basegame.cpp:1762 (9)
//         0041d553     MOV        EAX,dword ptr [EBP + 0xc]
//         0041d556     MOV        dword ptr [EAX + 0x89c],EDI
//                               LAB_0041d55c                                                 XREF[1]:     0041d548(j)
//                              basegame.cpp:1765 (66)
//         0041d55c     LEA        this,[ESP + 0x10]
//         0041d560     PUSH       s_VIDEOMEMORY                                    = "VIDEOMEMORY"
//         0041d565     PUSH       this=>DAT_fffffff8
//         0041d566     CALL       strstr                                           undefined strstr()
//         0041d56b     ADD        ESP,0x8
//         0041d56e     TEST       EAX,EAX
//         0041d570     JNZ        LAB_0041d59e
//         0041d572     LEA        EDX,[ESP + 0x10]
//         0041d576     PUSH       s_VIDEO_MEMORY                                   = "VIDEO MEMORY"
//         0041d57b     PUSH       EDX=>DAT_fffffff8
//         0041d57c     CALL       strstr                                           undefined strstr()
//         0041d581     ADD        ESP,0x8
//         0041d584     TEST       EAX,EAX
//         0041d586     JNZ        LAB_0041d59e
//         0041d588     LEA        EAX,[ESP + 0x10]
//         0041d58c     PUSH       s_VIDEO_MEMORY                                   = "VIDEO_MEMORY"
//         0041d591     PUSH       EAX=>DAT_fffffff8
//         0041d592     CALL       strstr                                           undefined strstr()
//         0041d597     ADD        ESP,0x8
//         0041d59a     TEST       EAX,EAX
//         0041d59c     JZ         LAB_0041d5a7
//                               LAB_0041d59e                                                 XREF[2]:     0041d570(j), 0041d586(j)
//                              basegame.cpp:1766 (9)
//         0041d59e     MOV        this,dword ptr [EBP + 0xc]
//         0041d5a1     MOV        dword ptr [ECX + this+0x8a0],EBX
//                               LAB_0041d5a7                                                 XREF[1]:     0041d59c(j)
//                              basegame.cpp:1768 (66)
//         0041d5a7     LEA        EDX,[ESP + 0x10]
//         0041d5ab     PUSH       s_STREAMMUSIC                                    = "STREAMMUSIC"
//         0041d5b0     PUSH       EDX=>DAT_fffffff8
//         0041d5b1     CALL       strstr                                           undefined strstr()
//         0041d5b6     ADD        ESP,0x8
//         0041d5b9     TEST       EAX,EAX
//         0041d5bb     JNZ        LAB_0041d5e9
//         0041d5bd     LEA        EAX,[ESP + 0x10]
//         0041d5c1     PUSH       s_STREAM_MUSIC                                   = "STREAM MUSIC"
//         0041d5c6     PUSH       EAX=>DAT_fffffff8
//         0041d5c7     CALL       strstr                                           undefined strstr()
//         0041d5cc     ADD        ESP,0x8
//         0041d5cf     TEST       EAX,EAX
//         0041d5d1     JNZ        LAB_0041d5e9
//         0041d5d3     LEA        this,[ESP + 0x10]
//         0041d5d7     PUSH       s_STREAM_MUSIC                                   = "STREAM_MUSIC"
//         0041d5dc     PUSH       this=>DAT_fffffff8
//         0041d5dd     CALL       strstr                                           undefined strstr()
//         0041d5e2     ADD        ESP,0x8
//         0041d5e5     TEST       EAX,EAX
//         0041d5e7     JZ         LAB_0041d616
//                               LAB_0041d5e9                                                 XREF[2]:     0041d5bb(j), 0041d5d1(j)
//                              basegame.cpp:1770 (9)
//         0041d5e9     MOV        EDX,dword ptr [EBP + 0xc]
//         0041d5ec     MOV        dword ptr [EDX + 0x8a4],EDI
//                              basegame.cpp:1771 (9)
//         0041d5f2     MOV        EAX,dword ptr [EBP + 0xc]
//         0041d5f5     MOV        dword ptr [EAX + 0x8ac],EBX
//                              basegame.cpp:1772 (9)
//         0041d5fb     MOV        this,dword ptr [EBP + 0xc]
//         0041d5fe     MOV        dword ptr [ECX + this+0x8b0],EBX
//                              basegame.cpp:1773 (9)
//         0041d604     MOV        EDX,dword ptr [EBP + 0xc]
//         0041d607     MOV        dword ptr [EDX + 0x8b4],EBX
//                              basegame.cpp:1774 (9)
//         0041d60d     MOV        EAX,dword ptr [EBP + 0xc]
//         0041d610     MOV        dword ptr [EAX + 0x8b8],EDI
//                               LAB_0041d616                                                 XREF[1]:     0041d5e7(j)
//                              basegame.cpp:1777 (66)
//         0041d616     LEA        this,[ESP + 0x10]
//         0041d61a     PUSH       s_IMAMUSIC                                       = "IMAMUSIC"
//         0041d61f     PUSH       this=>DAT_fffffff8
//         0041d620     CALL       strstr                                           undefined strstr()
//         0041d625     ADD        ESP,0x8
//         0041d628     TEST       EAX,EAX
//         0041d62a     JNZ        LAB_0041d658
//         0041d62c     LEA        EDX,[ESP + 0x10]
//         0041d630     PUSH       s_IMA_MUSIC                                      = "IMA MUSIC"
//         0041d635     PUSH       EDX=>DAT_fffffff8
//         0041d636     CALL       strstr                                           undefined strstr()
//         0041d63b     ADD        ESP,0x8
//         0041d63e     TEST       EAX,EAX
//         0041d640     JNZ        LAB_0041d658
//         0041d642     LEA        EAX,[ESP + 0x10]
//         0041d646     PUSH       s_IMA_MUSIC                                      = "IMA_MUSIC"
//         0041d64b     PUSH       EAX=>DAT_fffffff8
//         0041d64c     CALL       strstr                                           undefined strstr()
//         0041d651     ADD        ESP,0x8
//         0041d654     TEST       EAX,EAX
//         0041d656     JZ         LAB_0041d685
//                               LAB_0041d658                                                 XREF[2]:     0041d62a(j), 0041d640(j)
//                              basegame.cpp:1779 (9)
//         0041d658     MOV        this,dword ptr [EBP + 0xc]
//         0041d65b     MOV        dword ptr [ECX + this+0x8a4],EDI
//                              basegame.cpp:1780 (9)
//         0041d661     MOV        EDX,dword ptr [EBP + 0xc]
//         0041d664     MOV        dword ptr [EDX + 0x8ac],EBX
//                              basegame.cpp:1781 (9)
//         0041d66a     MOV        EAX,dword ptr [EBP + 0xc]
//         0041d66d     MOV        dword ptr [EAX + 0x8b0],EDI
//                              basegame.cpp:1782 (9)
//         0041d673     MOV        this,dword ptr [EBP + 0xc]
//         0041d676     MOV        dword ptr [ECX + this+0x8b4],EBX
//                              basegame.cpp:1783 (9)
//         0041d67c     MOV        EDX,dword ptr [EBP + 0xc]
//         0041d67f     MOV        dword ptr [EDX + 0x8b8],EBX
//                               LAB_0041d685                                                 XREF[1]:     0041d656(j)
//                              basegame.cpp:1786 (66)
//         0041d685     LEA        EAX,[ESP + 0x10]
//         0041d689     PUSH       s_FASTVIEW                                       = "FASTVIEW"
//         0041d68e     PUSH       EAX=>DAT_fffffff8
//         0041d68f     CALL       strstr                                           undefined strstr()
//         0041d694     ADD        ESP,0x8
//         0041d697     TEST       EAX,EAX
//         0041d699     JNZ        LAB_0041d6c7
//         0041d69b     LEA        this,[ESP + 0x10]
//         0041d69f     PUSH       s_FAST_VIEW                                      = "FAST VIEW"
//         0041d6a4     PUSH       this=>DAT_fffffff8
//         0041d6a5     CALL       strstr                                           undefined strstr()
//         0041d6aa     ADD        ESP,0x8
//         0041d6ad     TEST       EAX,EAX
//         0041d6af     JNZ        LAB_0041d6c7
//         0041d6b1     LEA        EDX,[ESP + 0x10]
//         0041d6b5     PUSH       s_FAST_VIEW                                      = "FAST_VIEW"
//         0041d6ba     PUSH       EDX=>DAT_fffffff8
//         0041d6bb     CALL       strstr                                           undefined strstr()
//         0041d6c0     ADD        ESP,0x8
//         0041d6c3     TEST       EAX,EAX
//         0041d6c5     JZ         LAB_0041d6d0
//                               LAB_0041d6c7                                                 XREF[2]:     0041d699(j), 0041d6af(j)
//                              basegame.cpp:1787 (9)
//         0041d6c7     MOV        EAX,dword ptr [EBP + 0xc]
//         0041d6ca     MOV        dword ptr [EAX + 0x8bc],EDI
//                               LAB_0041d6d0                                                 XREF[1]:     0041d6c5(j)
//                              basegame.cpp:1789 (66)
//         0041d6d0     LEA        this,[ESP + 0x10]
//         0041d6d4     PUSH       s_SLOWVIEW                                       = "SLOWVIEW"
//         0041d6d9     PUSH       this=>DAT_fffffff8
//         0041d6da     CALL       strstr                                           undefined strstr()
//         0041d6df     ADD        ESP,0x8
//         0041d6e2     TEST       EAX,EAX
//         0041d6e4     JNZ        LAB_0041d712
//         0041d6e6     LEA        EDX,[ESP + 0x10]
//         0041d6ea     PUSH       s_SLOW_VIEW                                      = "SLOW VIEW"
//         0041d6ef     PUSH       EDX=>DAT_fffffff8
//         0041d6f0     CALL       strstr                                           undefined strstr()
//         0041d6f5     ADD        ESP,0x8
//         0041d6f8     TEST       EAX,EAX
//         0041d6fa     JNZ        LAB_0041d712
//         0041d6fc     LEA        EAX,[ESP + 0x10]
//         0041d700     PUSH       s_SLOW_VIEW                                      = "SLOW_VIEW"
//         0041d705     PUSH       EAX=>DAT_fffffff8
//         0041d706     CALL       strstr                                           undefined strstr()
//         0041d70b     ADD        ESP,0x8
//         0041d70e     TEST       EAX,EAX
//         0041d710     JZ         LAB_0041d71b
//                               LAB_0041d712                                                 XREF[2]:     0041d6e4(j), 0041d6fa(j)
//                              basegame.cpp:1790 (9)
//         0041d712     MOV        this,dword ptr [EBP + 0xc]
//         0041d715     MOV        dword ptr [ECX + this+0x8bc],EBX
//                               LAB_0041d71b                                                 XREF[1]:     0041d710(j)
//                              basegame.cpp:1792 (66)
//         0041d71b     LEA        EDX,[ESP + 0x10]
//         0041d71f     PUSH       s_ONEBUTTON                                      = "ONEBUTTON"
//         0041d724     PUSH       EDX=>DAT_fffffff8
//         0041d725     CALL       strstr                                           undefined strstr()
//         0041d72a     ADD        ESP,0x8
//         0041d72d     TEST       EAX,EAX
//         0041d72f     JNZ        LAB_0041d75d
//         0041d731     LEA        EAX,[ESP + 0x10]
//         0041d735     PUSH       s_ONE_BUTTON                                     = "ONE BUTTON"
//         0041d73a     PUSH       EAX=>DAT_fffffff8
//         0041d73b     CALL       strstr                                           undefined strstr()
//         0041d740     ADD        ESP,0x8
//         0041d743     TEST       EAX,EAX
//         0041d745     JNZ        LAB_0041d75d
//         0041d747     LEA        this,[ESP + 0x10]
//         0041d74b     PUSH       s_ONE_BUTTON                                     = "ONE_BUTTON"
//         0041d750     PUSH       this=>DAT_fffffff8
//         0041d751     CALL       strstr                                           undefined strstr()
//         0041d756     ADD        ESP,0x8
//         0041d759     TEST       EAX,EAX
//         0041d75b     JZ         LAB_0041d767
//                               LAB_0041d75d                                                 XREF[2]:     0041d72f(j), 0041d745(j)
//                              basegame.cpp:1793 (10)
//         0041d75d     MOV        EDX,dword ptr [EBP + 0xc]
//         0041d760     MOV        word ptr [EDX + 0x8dc],DI
//                               LAB_0041d767                                                 XREF[1]:     0041d75b(j)
//                              basegame.cpp:1795 (71)
//         0041d767     LEA        EAX,[ESP + 0x10]
//         0041d76b     PUSH       s_TWOBUTTON                                      = "TWOBUTTON"
//         0041d770     PUSH       EAX=>DAT_fffffff8
//         0041d771     CALL       strstr                                           undefined strstr()
//         0041d776     ADD        ESP,0x8
//         0041d779     MOV        EBX,0x2
//         0041d77e     TEST       EAX,EAX
//         0041d780     JNZ        LAB_0041d7ae
//         0041d782     LEA        this,[ESP + 0x10]
//         0041d786     PUSH       s_TWO_BUTTON                                     = "TWO BUTTON"
//         0041d78b     PUSH       this=>DAT_fffffff8
//         0041d78c     CALL       strstr                                           undefined strstr()
//         0041d791     ADD        ESP,0x8
//         0041d794     TEST       EAX,EAX
//         0041d796     JNZ        LAB_0041d7ae
//         0041d798     LEA        EDX,[ESP + 0x10]
//         0041d79c     PUSH       s_TWO_BUTTON                                     = "TWO_BUTTON"
//         0041d7a1     PUSH       EDX=>DAT_fffffff8
//         0041d7a2     CALL       strstr                                           undefined strstr()
//         0041d7a7     ADD        ESP,0x8
//         0041d7aa     TEST       EAX,EAX
//         0041d7ac     JZ         LAB_0041d7b8
//                               LAB_0041d7ae                                                 XREF[2]:     0041d780(j), 0041d796(j)
//                              basegame.cpp:1796 (10)
//         0041d7ae     MOV        EAX,dword ptr [EBP + 0xc]
//         0041d7b1     MOV        word ptr [EAX + 0x8dc],BX
//                               LAB_0041d7b8                                                 XREF[1]:     0041d7ac(j)
//                              basegame.cpp:1799 (22)
//         0041d7b8     LEA        this,[ESP + 0x10]
//         0041d7bc     PUSH       s_RUNLOG                                         = "RUNLOG"
//         0041d7c1     PUSH       this=>DAT_fffffff8
//         0041d7c2     CALL       strstr                                           undefined strstr()
//         0041d7c7     ADD        ESP,0x8
//         0041d7ca     TEST       EAX,EAX
//         0041d7cc     JZ         LAB_0041d7d4
//                              basegame.cpp:1800 (6)
//         0041d7ce     MOV        dword ptr [do_run_log],EDI
//                               LAB_0041d7d4                                                 XREF[1]:     0041d7cc(j)
//                              basegame.cpp:1802 (22)
//         0041d7d4     LEA        EDX,[ESP + 0x10]
//         0041d7d8     PUSH       s_SYNCMSG                                        = "SYNCMSG"
//         0041d7dd     PUSH       EDX=>DAT_fffffff8
//         0041d7de     CALL       strstr                                           undefined strstr()
//         0041d7e3     ADD        ESP,0x8
//         0041d7e6     TEST       EAX,EAX
//         0041d7e8     JZ         LAB_0041d7f0
//                              basegame.cpp:1803 (6)
//         0041d7ea     MOV        dword ptr [EBP + 0x198],EDI
//                               LAB_0041d7f0                                                 XREF[1]:     0041d7e8(j)
//                              basegame.cpp:1805 (22)
//         0041d7f0     LEA        EAX,[ESP + 0x10]
//         0041d7f4     PUSH       s_DROPPACKETS                                    = "DROPPACKETS"
//         0041d7f9     PUSH       EAX=>DAT_fffffff8
//         0041d7fa     CALL       strstr                                           undefined strstr()
//         0041d7ff     ADD        ESP,0x8
//         0041d802     TEST       EAX,EAX
//         0041d804     JZ         LAB_0041d80c
//                              basegame.cpp:1806 (6)
//         0041d806     MOV        dword ptr [EBP + 0x194],EDI
//                               LAB_0041d80c                                                 XREF[1]:     0041d804(j)
//                              basegame.cpp:1808 (22)
//         0041d80c     LEA        this,[ESP + 0x10]
//         0041d810     PUSH       s_NOCOMMSPEED                                    = "NOCOMMSPEED"
//         0041d815     PUSH       this=>DAT_fffffff8
//         0041d816     CALL       strstr                                           undefined strstr()
//         0041d81b     ADD        ESP,0x8
//         0041d81e     TEST       EAX,EAX
//         0041d820     JZ         LAB_0041d82c
//                              basegame.cpp:1809 (12)
//         0041d822     XOR        ESI,ESI
//         0041d824     MOV        dword ptr [EBP + 0x1a0],ESI
//         0041d82a     JMP        LAB_0041d82e
//                               LAB_0041d82c                                                 XREF[1]:     0041d820(j)
//         0041d82c     XOR        ESI,ESI
//                               LAB_0041d82e                                                 XREF[1]:     0041d82a(j)
//                              basegame.cpp:1811 (22)
//         0041d82e     LEA        EDX,[ESP + 0x10]
//         0041d832     PUSH       s_SYNCSTOP                                       = "SYNCSTOP"
//         0041d837     PUSH       EDX=>DAT_fffffff8
//         0041d838     CALL       strstr                                           undefined strstr()
//         0041d83d     ADD        ESP,0x8
//         0041d840     TEST       EAX,EAX
//         0041d842     JZ         LAB_0041d84a
//                              basegame.cpp:1812 (6)
//         0041d844     MOV        dword ptr [EBP + 0x190],EDI
//                               LAB_0041d84a                                                 XREF[1]:     0041d842(j)
//                              basegame.cpp:1814 (22)
//         0041d84a     LEA        EAX,[ESP + 0x10]
//         0041d84e     PUSH       s_STEPMODE                                       = "STEPMODE"
//         0041d853     PUSH       EAX=>DAT_fffffff8
//         0041d854     CALL       strstr                                           undefined strstr()
//         0041d859     ADD        ESP,0x8
//         0041d85c     TEST       EAX,EAX
//         0041d85e     JZ         LAB_0041d866
//                              basegame.cpp:1815 (6)
//         0041d860     MOV        dword ptr [EBP + 0x19c],EDI
//                               LAB_0041d866                                                 XREF[1]:     0041d85e(j)
//                              basegame.cpp:1817 (66)
//         0041d866     LEA        this,[ESP + 0x10]
//         0041d86a     PUSH       s_SQUAREOUTLINE                                  = "SQUAREOUTLINE"
//         0041d86f     PUSH       this=>DAT_fffffff8
//         0041d870     CALL       strstr                                           undefined strstr()
//         0041d875     ADD        ESP,0x8
//         0041d878     TEST       EAX,EAX
//         0041d87a     JNZ        LAB_0041d8a8
//         0041d87c     LEA        EDX,[ESP + 0x10]
//         0041d880     PUSH       s_SQUARE_OUTLINE                                 = "SQUARE OUTLINE"
//         0041d885     PUSH       EDX=>DAT_fffffff8
//         0041d886     CALL       strstr                                           undefined strstr()
//         0041d88b     ADD        ESP,0x8
//         0041d88e     TEST       EAX,EAX
//         0041d890     JNZ        LAB_0041d8a8
//         0041d892     LEA        EAX,[ESP + 0x10]
//         0041d896     PUSH       s_SQUARE_OUTLINE                                 = "SQUARE_OUTLINE"
//         0041d89b     PUSH       EAX=>DAT_fffffff8
//         0041d89c     CALL       strstr                                           undefined strstr()
//         0041d8a1     ADD        ESP,0x8
//         0041d8a4     TEST       EAX,EAX
//         0041d8a6     JZ         LAB_0041d8ac
//                               LAB_0041d8a8                                                 XREF[2]:     0041d87a(j), 0041d890(j)
//                              basegame.cpp:1818 (4)
//         0041d8a8     MOV        byte ptr [EBP + 0x50],0x0
//                               LAB_0041d8ac                                                 XREF[1]:     0041d8a6(j)
//                              basegame.cpp:1820 (66)
//         0041d8ac     LEA        this,[ESP + 0x10]
//         0041d8b0     PUSH       s_CUBEOUTLINE                                    = "CUBEOUTLINE"
//         0041d8b5     PUSH       this=>DAT_fffffff8
//         0041d8b6     CALL       strstr                                           undefined strstr()
//         0041d8bb     ADD        ESP,0x8
//         0041d8be     TEST       EAX,EAX
//         0041d8c0     JNZ        LAB_0041d8ee
//         0041d8c2     LEA        EDX,[ESP + 0x10]
//         0041d8c6     PUSH       s_CUBE_OUTLINE                                   = "CUBE OUTLINE"
//         0041d8cb     PUSH       EDX=>DAT_fffffff8
//         0041d8cc     CALL       strstr                                           undefined strstr()
//         0041d8d1     ADD        ESP,0x8
//         0041d8d4     TEST       EAX,EAX
//         0041d8d6     JNZ        LAB_0041d8ee
//         0041d8d8     LEA        EAX,[ESP + 0x10]
//         0041d8dc     PUSH       s_CUBE_OUTLINE                                   = "CUBE_OUTLINE"
//         0041d8e1     PUSH       EAX=>DAT_fffffff8
//         0041d8e2     CALL       strstr                                           undefined strstr()
//         0041d8e7     ADD        ESP,0x8
//         0041d8ea     TEST       EAX,EAX
//         0041d8ec     JZ         LAB_0041d8f2
//                               LAB_0041d8ee                                                 XREF[2]:     0041d8c0(j), 0041d8d6(j)
//                              basegame.cpp:1821 (4)
//         0041d8ee     MOV        byte ptr [EBP + 0x50],0x1
//                               LAB_0041d8f2                                                 XREF[1]:     0041d8ec(j)
//                              basegame.cpp:1823 (66)
//         0041d8f2     LEA        this,[ESP + 0x10]
//         0041d8f6     PUSH       s_GROUNDOUTLINE                                  = "GROUNDOUTLINE"
//         0041d8fb     PUSH       this=>DAT_fffffff8
//         0041d8fc     CALL       strstr                                           undefined strstr()
//         0041d901     ADD        ESP,0x8
//         0041d904     TEST       EAX,EAX
//         0041d906     JNZ        LAB_0041d934
//         0041d908     LEA        EDX,[ESP + 0x10]
//         0041d90c     PUSH       s_GROUND_OUTLINE                                 = "GROUND OUTLINE"
//         0041d911     PUSH       EDX=>DAT_fffffff8
//         0041d912     CALL       strstr                                           undefined strstr()
//         0041d917     ADD        ESP,0x8
//         0041d91a     TEST       EAX,EAX
//         0041d91c     JNZ        LAB_0041d934
//         0041d91e     LEA        EAX,[ESP + 0x10]
//         0041d922     PUSH       s_GROUND_OUTLINE                                 = "GROUND_OUTLINE"
//         0041d927     PUSH       EAX=>DAT_fffffff8
//         0041d928     CALL       strstr                                           undefined strstr()
//         0041d92d     ADD        ESP,0x8
//         0041d930     TEST       EAX,EAX
//         0041d932     JZ         LAB_0041d937
//                               LAB_0041d934                                                 XREF[2]:     0041d906(j), 0041d91c(j)
//                              basegame.cpp:1824 (3)
//         0041d934     MOV        byte ptr [EBP + 0x50],BL
//                               LAB_0041d937                                                 XREF[1]:     0041d932(j)
//                              basegame.cpp:1826 (66)
//         0041d937     LEA        this,[ESP + 0x10]
//         0041d93b     PUSH       s_EDGEOUTLINE                                    = "EDGEOUTLINE"
//         0041d940     PUSH       this=>DAT_fffffff8
//         0041d941     CALL       strstr                                           undefined strstr()
//         0041d946     ADD        ESP,0x8
//         0041d949     TEST       EAX,EAX
//         0041d94b     JNZ        LAB_0041d979
//         0041d94d     LEA        EDX,[ESP + 0x10]
//         0041d951     PUSH       s_EDGE_OUTLINE                                   = "EDGE OUTLINE"
//         0041d956     PUSH       EDX=>DAT_fffffff8
//         0041d957     CALL       strstr                                           undefined strstr()
//         0041d95c     ADD        ESP,0x8
//         0041d95f     TEST       EAX,EAX
//         0041d961     JNZ        LAB_0041d979
//         0041d963     LEA        EAX,[ESP + 0x10]
//         0041d967     PUSH       s_EDGE_OUTLINE                                   = "EDGE_OUTLINE"
//         0041d96c     PUSH       EAX=>DAT_fffffff8
//         0041d96d     CALL       strstr                                           undefined strstr()
//         0041d972     ADD        ESP,0x8
//         0041d975     TEST       EAX,EAX
//         0041d977     JZ         LAB_0041d97d
//                               LAB_0041d979                                                 XREF[2]:     0041d94b(j), 0041d961(j)
//                              basegame.cpp:1827 (4)
//         0041d979     MOV        byte ptr [EBP + 0x50],0x3
//                               LAB_0041d97d                                                 XREF[1]:     0041d977(j)
//                              basegame.cpp:1829 (66)
//         0041d97d     LEA        this,[ESP + 0x10]
//         0041d981     PUSH       s_CUSTOMMOUSE                                    = "CUSTOMMOUSE"
//         0041d986     PUSH       this=>DAT_fffffff8
//         0041d987     CALL       strstr                                           undefined strstr()
//         0041d98c     ADD        ESP,0x8
//         0041d98f     TEST       EAX,EAX
//         0041d991     JNZ        LAB_0041d9bf
//         0041d993     LEA        EDX,[ESP + 0x10]
//         0041d997     PUSH       s_CUSTOM_MOUSE                                   = "CUSTOM MOUSE"
//         0041d99c     PUSH       EDX=>DAT_fffffff8
//         0041d99d     CALL       strstr                                           undefined strstr()
//         0041d9a2     ADD        ESP,0x8
//         0041d9a5     TEST       EAX,EAX
//         0041d9a7     JNZ        LAB_0041d9bf
//         0041d9a9     LEA        EAX,[ESP + 0x10]
//         0041d9ad     PUSH       s_CUSTOM_MOUSE                                   = "CUSTOM_MOUSE"
//         0041d9b2     PUSH       EAX=>DAT_fffffff8
//         0041d9b3     CALL       strstr                                           undefined strstr()
//         0041d9b8     ADD        ESP,0x8
//         0041d9bb     TEST       EAX,EAX
//         0041d9bd     JZ         LAB_0041d9c2
//                               LAB_0041d9bf                                                 XREF[2]:     0041d991(j), 0041d9a7(j)
//                              basegame.cpp:1830 (3)
//         0041d9bf     MOV        dword ptr [EBP + 0x54],EDI
//                               LAB_0041d9c2                                                 XREF[1]:     0041d9bd(j)
//                              basegame.cpp:1834 (22)
//         0041d9c2     LEA        this,[ESP + 0x10]
//         0041d9c6     PUSH       s_NOCP                                           = "NOCP"
//         0041d9cb     PUSH       this=>DAT_fffffff8
//         0041d9cc     CALL       strstr                                           undefined strstr()
//         0041d9d1     ADD        ESP,0x8
//         0041d9d4     TEST       EAX,EAX
//         0041d9d6     JZ         LAB_0041d9de
//                              basegame.cpp:1835 (6)
//         0041d9d8     MOV        dword ptr [useComputerPlayers],ESI               = 1h
//                               LAB_0041d9de                                                 XREF[1]:     0041d9d6(j)
//                              basegame.cpp:1837 (22)
//         0041d9de     LEA        EDX,[ESP + 0x10]
//         0041d9e2     PUSH       s_LOGAI                                          = "LOGAI"
//         0041d9e7     PUSH       EDX=>DAT_fffffff8
//         0041d9e8     CALL       strstr                                           undefined strstr()
//         0041d9ed     ADD        ESP,0x8
//         0041d9f0     TEST       EAX,EAX
//         0041d9f2     JZ         LAB_0041d9fa
//                              basegame.cpp:1838 (6)
//         0041d9f4     MOV        dword ptr [startLoggingAI],EDI
//                               LAB_0041d9fa                                                 XREF[1]:     0041d9f2(j)
//                              basegame.cpp:1840 (22)
//         0041d9fa     LEA        EAX,[ESP + 0x10]
//         0041d9fe     PUSH       s_NOLOGSTATUS                                    = "NOLOGSTATUS"
//         0041da03     PUSH       EAX=>DAT_fffffff8
//         0041da04     CALL       strstr                                           undefined strstr()
//         0041da09     ADD        ESP,0x8
//         0041da0c     TEST       EAX,EAX
//         0041da0e     JZ         LAB_0041da16
//                              basegame.cpp:1841 (6)
//         0041da10     MOV        dword ptr [logStatusOn],ESI
//                               LAB_0041da16                                                 XREF[1]:     0041da0e(j)
//                              basegame.cpp:1843 (22)
//         0041da16     LEA        this,[ESP + 0x10]
//         0041da1a     PUSH       s_DOLOGSTATUS                                    = "DOLOGSTATUS"
//         0041da1f     PUSH       this=>DAT_fffffff8
//         0041da20     CALL       strstr                                           undefined strstr()
//         0041da25     ADD        ESP,0x8
//         0041da28     TEST       EAX,EAX
//         0041da2a     JZ         LAB_0041da32
//                              basegame.cpp:1844 (6)
//         0041da2c     MOV        dword ptr [logStatusOn],EDI
//                               LAB_0041da32                                                 XREF[1]:     0041da2a(j)
//                              basegame.cpp:1846 (22)
//         0041da32     LEA        EDX,[ESP + 0x10]
//         0041da36     PUSH       s_NOAICHEAT                                      = "NOAICHEAT"
//         0041da3b     PUSH       EDX=>DAT_fffffff8
//         0041da3c     CALL       strstr                                           undefined strstr()
//         0041da41     ADD        ESP,0x8
//         0041da44     TEST       EAX,EAX
//         0041da46     JZ         LAB_0041da4e
//                              basegame.cpp:1847 (6)
//         0041da48     MOV        dword ptr [allowAIToCheat],ESI                   = 1h
//                               LAB_0041da4e                                                 XREF[1]:     0041da46(j)
//                              basegame.cpp:1849 (22)
//         0041da4e     LEA        EAX,[ESP + 0x10]
//         0041da52     PUSH       s_NOCHATCHEATCODES                               = "NOCHATCHEATCODES"
//         0041da57     PUSH       EAX=>DAT_fffffff8
//         0041da58     CALL       strstr                                           undefined strstr()
//         0041da5d     ADD        ESP,0x8
//         0041da60     TEST       EAX,EAX
//         0041da62     JZ         LAB_0041da6a
//                              basegame.cpp:1850 (6)
//         0041da64     MOV        dword ptr [chatCheatCodes],ESI                   = 1h
//                               LAB_0041da6a                                                 XREF[1]:     0041da62(j)
//                              basegame.cpp:1852 (22)
//         0041da6a     LEA        this,[ESP + 0x10]
//         0041da6e     PUSH       s_LOGUPDATECHANGES                               = "LOGUPDATECHANGES"
//         0041da73     PUSH       this=>DAT_fffffff8
//         0041da74     CALL       strstr                                           undefined strstr()
//         0041da79     ADD        ESP,0x8
//         0041da7c     TEST       EAX,EAX
//         0041da7e     JZ         LAB_0041da86
//                              basegame.cpp:1853 (6)
//         0041da80     MOV        dword ptr [logUpdateChanges],EDI
//                               LAB_0041da86                                                 XREF[1]:     0041da7e(j)
//                              basegame.cpp:1855 (22)
//         0041da86     LEA        EDX,[ESP + 0x10]
//         0041da8a     PUSH       s_UIP                                            = "UIP"
//         0041da8f     PUSH       EDX=>DAT_fffffff8
//         0041da90     CALL       strstr                                           undefined strstr()
//         0041da95     ADD        ESP,0x8
//         0041da98     TEST       EAX,EAX
//         0041da9a     JZ         LAB_0041daa2
//                              basegame.cpp:1856 (6)
//         0041da9c     MOV        dword ptr [useInfluencePlacement],EDI
//                               LAB_0041daa2                                                 XREF[1]:     0041da9a(j)
//                              basegame.cpp:1858 (22)
//         0041daa2     LEA        EAX,[ESP + 0x10]
//         0041daa6     PUSH       s_ALLGRASS                                       = "ALLGRASS"
//         0041daab     PUSH       EAX=>DAT_fffffff8
//         0041daac     CALL       strstr                                           undefined strstr()
//         0041dab1     ADD        ESP,0x8
//         0041dab4     TEST       EAX,EAX
//         0041dab6     JZ         LAB_0041dabe
//                              basegame.cpp:1859 (6)
//         0041dab8     MOV        dword ptr [all_grassland_on],EDI
//                               LAB_0041dabe                                                 XREF[1]:     0041dab6(j)
//                              basegame.cpp:1861 (22)
//         0041dabe     LEA        this,[ESP + 0x10]
//         0041dac2     PUSH       s_ALLCP                                          = "ALLCP"
//         0041dac7     PUSH       this=>DAT_fffffff8
//         0041dac8     CALL       strstr                                           undefined strstr()
//         0041dacd     ADD        ESP,0x8
//         0041dad0     TEST       EAX,EAX
//         0041dad2     JZ         LAB_0041dada
//                              basegame.cpp:1862 (6)
//         0041dad4     MOV        dword ptr [all_cp],EDI
//                               LAB_0041dada                                                 XREF[1]:     0041dad2(j)
//                              basegame.cpp:1864 (22)
//         0041dada     LEA        EDX,[ESP + 0x10]
//         0041dade     PUSH       s_ALLCP1                                         = "ALLCP1"
//         0041dae3     PUSH       EDX=>DAT_fffffff8
//         0041dae4     CALL       strstr                                           undefined strstr()
//         0041dae9     ADD        ESP,0x8
//         0041daec     TEST       EAX,EAX
//         0041daee     JZ         LAB_0041daf6
//                              basegame.cpp:1865 (6)
//         0041daf0     MOV        dword ptr [all_cp],EBX
//                               LAB_0041daf6                                                 XREF[1]:     0041daee(j)
//                              basegame.cpp:1867 (25)
//         0041daf6     LEA        EAX,[ESP + 0x10]
//         0041dafa     PUSH       s_NOPATHLIMIT                                    = "NOPATHLIMIT"
//         0041daff     PUSH       EAX=>DAT_fffffff8
//         0041db00     CALL       strstr                                           undefined strstr()
//         0041db05     ADD        ESP,0x8
//         0041db08     OR         EBX,0xffffffff
//         0041db0b     TEST       EAX,EAX
//         0041db0d     JZ         LAB_0041db15
//                              basegame.cpp:1868 (6)
//         0041db0f     MOV        dword ptr [numberPathingIterations],EBX          = 9C4h
//                               LAB_0041db15                                                 XREF[1]:     0041db0d(j)
//                              basegame.cpp:1870 (22)
//         0041db15     LEA        this,[ESP + 0x10]
//         0041db19     PUSH       s_UNP                                            = "UNP"
//         0041db1e     PUSH       this=>DAT_fffffff8
//         0041db1f     CALL       strstr                                           undefined strstr()
//         0041db24     ADD        ESP,0x8
//         0041db27     TEST       EAX,EAX
//         0041db29     JZ         LAB_0041db31
//                              basegame.cpp:1871 (6)
//         0041db2b     MOV        dword ptr [useNewPathing],EBX
//                               LAB_0041db31                                                 XREF[1]:     0041db29(j)
//                              basegame.cpp:1873 (22)
//         0041db31     LEA        EDX,[ESP + 0x10]
//         0041db35     PUSH       s_COLORLOG                                       = "COLORLOG"
//         0041db3a     PUSH       EDX=>DAT_fffffff8
//         0041db3b     CALL       strstr                                           undefined strstr()
//         0041db40     ADD        ESP,0x8
//         0041db43     TEST       EAX,EAX
//         0041db45     JZ         LAB_0041db4e
//                              basegame.cpp:1874 (7)
//         0041db47     MOV        byte ptr [do_color_log],0x1                      = 00h
//                               LAB_0041db4e                                                 XREF[1]:     0041db45(j)
//                              basegame.cpp:1877 (18)
//         0041db4e     LEA        EAX,[ESP + 0x10]
//         0041db52     PUSH       s_LOGAI=                                         = "LOGAI="
//         0041db57     PUSH       EAX=>DAT_fffffff8
//         0041db58     CALL       __mbsstr                                         undefined __mbsstr()
//         0041db5d     ADD        ESP,0x8
//                              basegame.cpp:1878 (8)
//         0041db60     CMP        EAX,ESI
//         0041db62     JZ         LAB_0041dbee
//                              basegame.cpp:1880 (5)
//         0041db68     CMP        byte ptr [EAX],0x3d
//         0041db6b     JZ         LAB_0041db7e
//                               LAB_0041db6d                                                 XREF[1]:     0041db7c(j)
//                              basegame.cpp:1881 (17)
//         0041db6d     PUSH       EDI
//         0041db6e     PUSH       EAX=>DAT_fffffff8
//         0041db6f     CALL       __mbsninc                                        undefined __mbsninc()
//         0041db74     MOV        this,byte ptr [EAX]
//         0041db76     ADD        ESP,0x8
//         0041db79     CMP        this,0x3d
//         0041db7c     JNZ        LAB_0041db6d
//                               LAB_0041db7e                                                 XREF[1]:     0041db6b(j)
//                              basegame.cpp:1882 (9)
//         0041db7e     PUSH       EDI
//         0041db7f     PUSH       EAX=>DAT_fffffff8
//         0041db80     CALL       __mbsninc                                        undefined __mbsninc()
//         0041db85     MOV        ESI,EAX
//                              basegame.cpp:1884 (33)
//         0041db87     XOR        this,this
//         0041db89     ADD        ESP,0x8
//         0041db8c     MOV        byte ptr [ESP + 0x110],0x0
//         0041db94     MOV        this,byte ptr [ESI]
//         0041db96     PUSH       this
//         0041db97     CALL       __ismbcspace                                     undefined __ismbcspace()
//         0041db9c     ADD        ESP,0x4
//         0041db9f     TEST       EAX,EAX
//         0041dba1     JNZ        LAB_0041dbd7
//                               LAB_0041dba3                                                 XREF[1]:     0041dbd5(j)
//         0041dba3     CMP        byte ptr [ESI],0x0
//         0041dba6     JZ         LAB_0041dbd7
//                              basegame.cpp:1886 (18)
//         0041dba8     PUSH       EDI
//         0041dba9     LEA        EDX,[ESP + 0x114]
//         0041dbb0     PUSH       ESI=>DAT_fffffff8
//         0041dbb1     PUSH       EDX=>DAT_fffffff4
//         0041dbb2     CALL       __mbsncat                                        undefined __mbsncat()
//         0041dbb7     ADD        ESP,0xc
//                              basegame.cpp:1887 (29)
//         0041dbba     PUSH       EDI
//         0041dbbb     PUSH       ESI=>DAT_fffffff8
//         0041dbbc     CALL       __mbsninc                                        undefined __mbsninc()
//         0041dbc1     MOV        ESI,EAX
//         0041dbc3     XOR        EAX,EAX
//         0041dbc5     ADD        ESP,0x8
//         0041dbc8     MOV        AL,byte ptr [ESI]
//         0041dbca     PUSH       EAX
//         0041dbcb     CALL       __ismbcspace                                     undefined __ismbcspace()
//         0041dbd0     ADD        ESP,0x4
//         0041dbd3     TEST       EAX,EAX
//         0041dbd5     JZ         LAB_0041dba3
//                               LAB_0041dbd7                                                 XREF[2]:     0041dba1(j), 0041dba6(j)
//                              basegame.cpp:1889 (23)
//         0041dbd7     LEA        this,[ESP + 0x110]
//         0041dbde     PUSH       this
//         0041dbdf     CALL       atol                                             undefined atol()
//         0041dbe4     ADD        ESP,0x4
//         0041dbe7     MOV        [specificAIPlayerToLog],EAX                      = FFFFFFFFh
//         0041dbec     XOR        ESI,ESI
//                               LAB_0041dbee                                                 XREF[1]:     0041db62(j)
//                              basegame.cpp:1893 (18)
//         0041dbee     LEA        EDX,[ESP + 0x10]
//         0041dbf2     PUSH       s_LOGDEBUG=                                      = "LOGDEBUG="
//         0041dbf7     PUSH       EDX=>DAT_fffffff8
//         0041dbf8     CALL       __mbsstr                                         undefined __mbsstr()
//         0041dbfd     ADD        ESP,0x8
//                              basegame.cpp:1894 (8)
//         0041dc00     CMP        EAX,ESI
//         0041dc02     JZ         LAB_0041dc8e
//                              basegame.cpp:1896 (5)
//         0041dc08     CMP        byte ptr [EAX],0x3d
//         0041dc0b     JZ         LAB_0041dc1e
//                               LAB_0041dc0d                                                 XREF[1]:     0041dc1c(j)
//                              basegame.cpp:1897 (17)
//         0041dc0d     PUSH       EDI
//         0041dc0e     PUSH       EAX=>DAT_fffffff8
//         0041dc0f     CALL       __mbsninc                                        undefined __mbsninc()
//         0041dc14     MOV        this,byte ptr [EAX]
//         0041dc16     ADD        ESP,0x8
//         0041dc19     CMP        this,0x3d
//         0041dc1c     JNZ        LAB_0041dc0d
//                               LAB_0041dc1e                                                 XREF[1]:     0041dc0b(j)
//                              basegame.cpp:1898 (9)
//         0041dc1e     PUSH       EDI
//         0041dc1f     PUSH       EAX=>DAT_fffffff8
//         0041dc20     CALL       __mbsninc                                        undefined __mbsninc()
//         0041dc25     MOV        ESI,EAX
//                              basegame.cpp:1900 (33)
//         0041dc27     XOR        EAX,EAX
//         0041dc29     ADD        ESP,0x8
//         0041dc2c     MOV        byte ptr [ESP + 0x110],0x0
//         0041dc34     MOV        AL,byte ptr [ESI]
//         0041dc36     PUSH       EAX
//         0041dc37     CALL       __ismbcspace                                     undefined __ismbcspace()
//         0041dc3c     ADD        ESP,0x4
//         0041dc3f     TEST       EAX,EAX
//         0041dc41     JNZ        LAB_0041dc77
//                               LAB_0041dc43                                                 XREF[1]:     0041dc75(j)
//         0041dc43     CMP        byte ptr [ESI],0x0
//         0041dc46     JZ         LAB_0041dc77
//                              basegame.cpp:1902 (18)
//         0041dc48     PUSH       EDI
//         0041dc49     LEA        this,[ESP + 0x114]
//         0041dc50     PUSH       ESI=>DAT_fffffff8
//         0041dc51     PUSH       this=>DAT_fffffff4
//         0041dc52     CALL       __mbsncat                                        undefined __mbsncat()
//         0041dc57     ADD        ESP,0xc
//                              basegame.cpp:1903 (29)
//         0041dc5a     PUSH       EDI
//         0041dc5b     PUSH       ESI=>DAT_fffffff8
//         0041dc5c     CALL       __mbsninc                                        undefined __mbsninc()
//         0041dc61     MOV        ESI,EAX
//         0041dc63     XOR        EDX,EDX
//         0041dc65     ADD        ESP,0x8
//         0041dc68     MOV        DL,byte ptr [ESI]
//         0041dc6a     PUSH       EDX
//         0041dc6b     CALL       __ismbcspace                                     undefined __ismbcspace()
//         0041dc70     ADD        ESP,0x4
//         0041dc73     TEST       EAX,EAX
//         0041dc75     JZ         LAB_0041dc43
//                               LAB_0041dc77                                                 XREF[2]:     0041dc41(j), 0041dc46(j)
//                              basegame.cpp:1905 (23)
//         0041dc77     LEA        EAX,[ESP + 0x110]
//         0041dc7e     PUSH       EAX
//         0041dc7f     CALL       atol                                             undefined atol()
//         0041dc84     ADD        ESP,0x4
//         0041dc87     MOV        [logDebugID],EAX                                 = FFFFFFFFh
//         0041dc8c     XOR        ESI,ESI
//                               LAB_0041dc8e                                                 XREF[1]:     0041dc02(j)
//                              basegame.cpp:1908 (22)
//         0041dc8e     LEA        this,[ESP + 0x10]
//         0041dc92     PUSH       s_NOPATHCAP                                      = "NOPATHCAP"
//         0041dc97     PUSH       this=>DAT_fffffff8
//         0041dc98     CALL       strstr                                           undefined strstr()
//         0041dc9d     ADD        ESP,0x8
//         0041dca0     TEST       EAX,EAX
//         0041dca2     JZ         LAB_0041dcaa
//                              basegame.cpp:1909 (6)
//         0041dca4     MOV        dword ptr [pathingCapValue],EBX                  = 2h
//                               LAB_0041dcaa                                                 XREF[1]:     0041dca2(j)
//                              basegame.cpp:1911 (22)
//         0041dcaa     LEA        EDX,[ESP + 0x10]
//         0041dcae     PUSH       s_GAMECD                                         = "GAMECD"
//         0041dcb3     PUSH       EDX=>DAT_fffffff8
//         0041dcb4     CALL       strstr                                           undefined strstr()
//         0041dcb9     ADD        ESP,0x8
//         0041dcbc     TEST       EAX,EAX
//         0041dcbe     JZ         LAB_0041dcc6
//                              basegame.cpp:1912 (6)
//         0041dcc0     MOV        dword ptr [force_cd],EDI
//                               LAB_0041dcc6                                                 XREF[1]:     0041dcbe(j)
//                              basegame.cpp:1914 (22)
//         0041dcc6     LEA        EAX,[ESP + 0x10]
//         0041dcca     PUSH       s_1280                                           = "1280"
//         0041dccf     PUSH       EAX=>DAT_fffffff8
//         0041dcd0     CALL       strstr                                           undefined strstr()
//         0041dcd5     ADD        ESP,0x8
//         0041dcd8     TEST       EAX,EAX
//         0041dcda     JZ         LAB_0041dcf6
//                              basegame.cpp:1916 (13)
//         0041dcdc     MOV        this,dword ptr [EBP + 0xc]
//         0041dcdf     MOV        dword ptr [ECX + this+0x8e0],0x500
//                              basegame.cpp:1917 (13)
//         0041dce9     MOV        EDX,dword ptr [EBP + 0xc]
//         0041dcec     MOV        dword ptr [EDX + 0x8e4],0x400
//                               LAB_0041dcf6                                                 XREF[1]:     0041dcda(j)
//                              basegame.cpp:1920 (66)
//         0041dcf6     LEA        EAX,[ESP + 0x10]
//         0041dcfa     PUSH       s_LOGFPS                                         = "LOGFPS"
//         0041dcff     PUSH       EAX=>DAT_fffffff8
//         0041dd00     CALL       strstr                                           undefined strstr()
//         0041dd05     ADD        ESP,0x8
//         0041dd08     TEST       EAX,EAX
//         0041dd0a     JNZ        LAB_0041dd38
//         0041dd0c     LEA        this,[ESP + 0x10]
//         0041dd10     PUSH       s_LOG_FPS                                        = "LOG FPS"
//         0041dd15     PUSH       this=>DAT_fffffff8
//         0041dd16     CALL       strstr                                           undefined strstr()
//         0041dd1b     ADD        ESP,0x8
//         0041dd1e     TEST       EAX,EAX
//         0041dd20     JNZ        LAB_0041dd38
//         0041dd22     LEA        EDX,[ESP + 0x10]
//         0041dd26     PUSH       s_LOG_FPS                                        = "LOG_FPS"
//         0041dd2b     PUSH       EDX=>DAT_fffffff8
//         0041dd2c     CALL       strstr                                           undefined strstr()
//         0041dd31     ADD        ESP,0x8
//         0041dd34     TEST       EAX,EAX
//         0041dd36     JZ         LAB_0041dd3e
//                               LAB_0041dd38                                                 XREF[2]:     0041dd0a(j), 0041dd20(j)
//                              basegame.cpp:1921 (6)
//         0041dd38     MOV        dword ptr [do_fps_log],EDI
//                               LAB_0041dd3e                                                 XREF[1]:     0041dd36(j)
//                              basegame.cpp:1923 (22)
//         0041dd3e     LEA        EAX,[ESP + 0x10]
//         0041dd42     PUSH       s_DDERRORLOG                                     = "DDERRORLOG"
//         0041dd47     PUSH       EAX=>DAT_fffffff8
//         0041dd48     CALL       strstr                                           undefined strstr()
//         0041dd4d     ADD        ESP,0x8
//         0041dd50     TEST       EAX,EAX
//         0041dd52     JZ         LAB_0041dd60
//                              basegame.cpp:1925 (6)
//         0041dd54     MOV        dword ptr [Sys_DDLOG_Enable],EDI
//                              basegame.cpp:1926 (6)
//         0041dd5a     MOV        dword ptr [Sys_DDLOG_ErrorOn],EDI
//                               LAB_0041dd60                                                 XREF[1]:     0041dd52(j)
//                              basegame.cpp:1929 (22)
//         0041dd60     LEA        this,[ESP + 0x10]
//         0041dd64     PUSH       s_DDLOG                                          = "DDLOG"
//         0041dd69     PUSH       this=>DAT_fffffff8
//         0041dd6a     CALL       strstr                                           undefined strstr()
//         0041dd6f     ADD        ESP,0x8
//         0041dd72     TEST       EAX,EAX
//         0041dd74     JZ         LAB_0041dd82
//                              basegame.cpp:1931 (6)
//         0041dd76     MOV        dword ptr [Sys_DDLOG_Enable],EDI
//                              basegame.cpp:1932 (6)
//         0041dd7c     MOV        dword ptr [Sys_DDLOG_ErrorOn],ESI
//                               LAB_0041dd82                                                 XREF[1]:     0041dd74(j)
//                              basegame.cpp:1935 (22)
//         0041dd82     LEA        EDX,[ESP + 0x10]
//         0041dd86     PUSH       s_DDFLUSHLOG                                     = "DDFLUSHLOG"
//         0041dd8b     PUSH       EDX=>DAT_fffffff8
//         0041dd8c     CALL       strstr                                           undefined strstr()
//         0041dd91     ADD        ESP,0x8
//         0041dd94     TEST       EAX,EAX
//         0041dd96     JZ         LAB_0041dd9e
//                              basegame.cpp:1936 (6)
//         0041dd98     MOV        dword ptr [DDlogAutoFlush],EDI                   = 1h
//                               LAB_0041dd9e                                                 XREF[1]:     0041dd96(j)
//                              basegame.cpp:1938 (22)
//         0041dd9e     LEA        EAX,[ESP + 0x10]
//         0041dda2     PUSH       s_DDNOFLUSHLOG                                   = "DDNOFLUSHLOG"
//         0041dda7     PUSH       EAX=>DAT_fffffff8
//         0041dda8     CALL       strstr                                           undefined strstr()
//         0041ddad     ADD        ESP,0x8
//         0041ddb0     TEST       EAX,EAX
//         0041ddb2     JZ         LAB_0041ddba
//                              basegame.cpp:1939 (6)
//         0041ddb4     MOV        dword ptr [DDlogAutoFlush],ESI                   = 1h
//                               LAB_0041ddba                                                 XREF[1]:     0041ddb2(j)
//                              basegame.cpp:1942 (22)
//         0041ddba     LEA        this,[ESP + 0x10]
//         0041ddbe     PUSH       s_DDLOCKLOG                                      = "DDLOCKLOG"
//         0041ddc3     PUSH       this=>DAT_fffffff8
//         0041ddc4     CALL       strstr                                           undefined strstr()
//         0041ddc9     ADD        ESP,0x8
//         0041ddcc     TEST       EAX,EAX
//         0041ddce     JZ         LAB_0041ddd6
//                              basegame.cpp:1943 (6)
//         0041ddd0     MOV        dword ptr [debug_log_lock],EDI
//                               LAB_0041ddd6                                                 XREF[1]:     0041ddce(j)
//                              basegame.cpp:1945 (22)
//         0041ddd6     LEA        EDX,[ESP + 0x10]
//         0041ddda     PUSH       s_LOGRANDOM                                      = "LOGRANDOM"
//         0041dddf     PUSH       EDX=>DAT_fffffff8
//         0041dde0     CALL       strstr                                           undefined strstr()
//         0041dde5     ADD        ESP,0x8
//         0041dde8     TEST       EAX,EAX
//         0041ddea     JZ         LAB_0041ddf2
//                              basegame.cpp:1946 (6)
//         0041ddec     MOV        dword ptr [do_debug_random],EDI
//                               LAB_0041ddf2                                                 XREF[1]:     0041ddea(j)
//                              basegame.cpp:1948 (22)
//         0041ddf2     LEA        EAX,[ESP + 0x10]
//         0041ddf6     PUSH       s_FIXEDUPDATE                                    = "FIXEDUPDATE"
//         0041ddfb     PUSH       EAX=>DAT_fffffff8
//         0041ddfc     CALL       strstr                                           undefined strstr()
//         0041de01     ADD        ESP,0x8
//         0041de04     TEST       EAX,EAX
//         0041de06     JZ         LAB_0041de14
//                              basegame.cpp:1950 (6)
//         0041de08     MOV        dword ptr [do_debug_timeGetTime],EDI
//                              basegame.cpp:1951 (6)
//         0041de0e     MOV        dword ptr [do_fixed_update],EDI
//                               LAB_0041de14                                                 XREF[1]:     0041de06(j)
//                              basegame.cpp:1954 (22)
//         0041de14     LEA        this,[ESP + 0x10]
//         0041de18     PUSH       s_LOGACTION                                      = "LOGACTION"
//         0041de1d     PUSH       this=>DAT_fffffff8
//         0041de1e     CALL       strstr                                           undefined strstr()
//         0041de23     ADD        ESP,0x8
//         0041de26     TEST       EAX,EAX
//         0041de28     JZ         LAB_0041de30
//                              basegame.cpp:1955 (6)
//         0041de2a     MOV        dword ptr [debugActions],EDI
//                               LAB_0041de30                                                 XREF[1]:     0041de28(j)
//                              basegame.cpp:1958 (22)
//         0041de30     LEA        EDX,[ESP + 0x10]
//         0041de34     PUSH       s_RES_WARN                                       = "RES_WARN"
//         0041de39     PUSH       EDX=>DAT_fffffff8
//         0041de3a     CALL       strstr                                           undefined strstr()
//         0041de3f     ADD        ESP,0x8
//         0041de42     TEST       EAX,EAX
//         0041de44     JZ         LAB_0041de4f
//                              basegame.cpp:1960 (9)
//         0041de46     PUSH       EDI
//         0041de47     CALL       RESFILE_Set_Missing_Flag                         void RESFILE_Set_Missing_Flag(int param_1)
//         0041de4c     ADD        ESP,0x4
//                               LAB_0041de4f                                                 XREF[1]:     0041de44(j)
//                              basegame.cpp:1965 (18)
//         0041de4f     LEA        EAX,[ESP + 0x10]
//         0041de53     PUSH       s_SCENARIOS=                                     = "SCENARIOS="
//         0041de58     PUSH       EAX=>DAT_fffffff8
//         0041de59     CALL       __mbsstr                                         undefined __mbsstr()
//         0041de5e     ADD        ESP,0x8
//                              basegame.cpp:1966 (8)
//         0041de61     CMP        EAX,ESI
//         0041de63     JZ         LAB_0041def5
//                              basegame.cpp:1968 (5)
//         0041de69     CMP        byte ptr [EAX],0x3d
//         0041de6c     JZ         LAB_0041de7f
//                               LAB_0041de6e                                                 XREF[1]:     0041de7d(j)
//                              basegame.cpp:1969 (17)
//         0041de6e     PUSH       EDI
//         0041de6f     PUSH       EAX=>DAT_fffffff8
//         0041de70     CALL       __mbsninc                                        undefined __mbsninc()
//         0041de75     MOV        this,byte ptr [EAX]
//         0041de77     ADD        ESP,0x8
//         0041de7a     CMP        this,0x3d
//         0041de7d     JNZ        LAB_0041de6e
//                               LAB_0041de7f                                                 XREF[1]:     0041de6c(j)
//                              basegame.cpp:1970 (7)
//         0041de7f     PUSH       EDI
//         0041de80     PUSH       EAX=>DAT_fffffff8
//         0041de81     CALL       __mbsninc                                        undefined __mbsninc()
//                              basegame.cpp:1971 (5)
//         0041de86     MOV        this,dword ptr [EBP + 0xc]
//         0041de89     MOV        ESI,EAX
//                              basegame.cpp:1972 (32)
//         0041de8b     XOR        EDX,EDX
//         0041de8d     ADD        ESP,0x8
//         0041de90     MOV        byte ptr [this->_padding_ + 0xc17],0x0
//         0041de97     MOV        DL,byte ptr [ESI]
//         0041de99     PUSH       EDX
//         0041de9a     CALL       __ismbcspace                                     undefined __ismbcspace()
//         0041de9f     ADD        ESP,0x4
//         0041dea2     TEST       EAX,EAX
//         0041dea4     JNZ        LAB_0041dedb
//                               LAB_0041dea6                                                 XREF[1]:     0041ded9(j)
//         0041dea6     CMP        byte ptr [ESI],0x0
//         0041dea9     JZ         LAB_0041dedb
//                              basegame.cpp:1974 (19)
//         0041deab     MOV        EAX,dword ptr [EBP + 0xc]
//         0041deae     PUSH       EDI
//         0041deaf     ADD        EAX,0xc17
//         0041deb4     PUSH       ESI=>DAT_fffffff8
//         0041deb5     PUSH       EAX=>DAT_fffffff4
//         0041deb6     CALL       __mbsncat                                        undefined __mbsncat()
//         0041debb     ADD        ESP,0xc
//                              basegame.cpp:1975 (29)
//         0041debe     PUSH       EDI
//         0041debf     PUSH       ESI=>DAT_fffffff8
//         0041dec0     CALL       __mbsninc                                        undefined __mbsninc()
//         0041dec5     MOV        ESI,EAX
//         0041dec7     XOR        this,this
//         0041dec9     ADD        ESP,0x8
//         0041decc     MOV        this,byte ptr [ESI]
//         0041dece     PUSH       this
//         0041decf     CALL       __ismbcspace                                     undefined __ismbcspace()
//         0041ded4     ADD        ESP,0x4
//         0041ded7     TEST       EAX,EAX
//         0041ded9     JZ         LAB_0041dea6
//                               LAB_0041dedb                                                 XREF[2]:     0041dea4(j), 0041dea9(j)
//                              basegame.cpp:1977 (26)
//         0041dedb     MOV        EDX,dword ptr [EBP + 0xc]
//         0041dede     PUSH       EDI
//         0041dedf     ADD        EDX,0xc17
//         0041dee5     PUSH       s_\                                              = "\\"
//         0041deea     PUSH       EDX=>DAT_fffffff4
//         0041deeb     CALL       __mbsncat                                        undefined __mbsncat()
//         0041def0     ADD        ESP,0xc
//         0041def3     XOR        ESI,ESI
//                               LAB_0041def5                                                 XREF[1]:     0041de63(j)
//                              basegame.cpp:1981 (18)
//         0041def5     LEA        EAX,[ESP + 0x10]
//         0041def9     PUSH       s_WORLD=                                         = "WORLD="
//         0041defe     PUSH       EAX=>DAT_fffffff8
//         0041deff     CALL       __mbsstr                                         undefined __mbsstr()
//         0041df04     ADD        ESP,0x8
//                              basegame.cpp:1982 (4)
//         0041df07     CMP        EAX,ESI
//         0041df09     JZ         LAB_0041df7d
//                              basegame.cpp:1984 (5)
//         0041df0b     CMP        byte ptr [EAX],0x3d
//         0041df0e     JZ         LAB_0041df21
//                               LAB_0041df10                                                 XREF[1]:     0041df1f(j)
//                              basegame.cpp:1985 (17)
//         0041df10     PUSH       EDI
//         0041df11     PUSH       EAX=>DAT_fffffff8
//         0041df12     CALL       __mbsninc                                        undefined __mbsninc()
//         0041df17     MOV        this,byte ptr [EAX]
//         0041df19     ADD        ESP,0x8
//         0041df1c     CMP        this,0x3d
//         0041df1f     JNZ        LAB_0041df10
//                               LAB_0041df21                                                 XREF[1]:     0041df0e(j)
//                              basegame.cpp:1986 (7)
//         0041df21     PUSH       EDI
//         0041df22     PUSH       EAX=>DAT_fffffff8
//         0041df23     CALL       __mbsninc                                        undefined __mbsninc()
//                              basegame.cpp:1987 (5)
//         0041df28     MOV        this,dword ptr [EBP + 0xc]
//         0041df2b     MOV        ESI,EAX
//                              basegame.cpp:1988 (32)
//         0041df2d     XOR        EDX,EDX
//         0041df2f     ADD        ESP,0x8
//         0041df32     MOV        byte ptr [ECX + this+0xf3],0x0
//         0041df39     MOV        DL,byte ptr [ESI]
//         0041df3b     PUSH       EDX
//         0041df3c     CALL       __ismbcspace                                     undefined __ismbcspace()
//         0041df41     ADD        ESP,0x4
//         0041df44     TEST       EAX,EAX
//         0041df46     JNZ        LAB_0041df7d
//                               LAB_0041df48                                                 XREF[1]:     0041df7b(j)
//         0041df48     CMP        byte ptr [ESI],0x0
//         0041df4b     JZ         LAB_0041df7d
//                              basegame.cpp:1990 (19)
//         0041df4d     MOV        EAX,dword ptr [EBP + 0xc]
//         0041df50     PUSH       EDI
//         0041df51     ADD        EAX,0xf3
//         0041df56     PUSH       ESI=>DAT_fffffff8
//         0041df57     PUSH       EAX=>DAT_fffffff4
//         0041df58     CALL       __mbsncat                                        undefined __mbsncat()
//         0041df5d     ADD        ESP,0xc
//                              basegame.cpp:1991 (29)
//         0041df60     PUSH       EDI
//         0041df61     PUSH       ESI=>DAT_fffffff8
//         0041df62     CALL       __mbsninc                                        undefined __mbsninc()
//         0041df67     MOV        ESI,EAX
//         0041df69     XOR        this,this
//         0041df6b     ADD        ESP,0x8
//         0041df6e     MOV        this,byte ptr [ESI]
//         0041df70     PUSH       this
//         0041df71     CALL       __ismbcspace                                     undefined __ismbcspace()
//         0041df76     ADD        ESP,0x4
//         0041df79     TEST       EAX,EAX
//         0041df7b     JZ         LAB_0041df48
//                               LAB_0041df7d                                                 XREF[3]:     0041df09(j), 0041df46(j),
//                                                                                                         0041df4b(j)
//                              basegame.cpp:1997 (15)
//         0041df7d     LEA        EDX,[ESP + 0x10]
//         0041df81     PUSH       s_FIXEDUPDATE=                                   = "FIXEDUPDATE="
//         0041df86     PUSH       EDX=>DAT_fffffff8
//         0041df87     CALL       __mbsstr                                         undefined __mbsstr()
//                              basegame.cpp:1998 (13)
//         0041df8c     XOR        EBX,EBX
//         0041df8e     ADD        ESP,0x8
//         0041df91     CMP        EAX,EBX
//         0041df93     JZ         LAB_0041e029
//                              basegame.cpp:2000 (6)
//         0041df99     MOV        dword ptr [do_debug_timeGetTime],EDI
//                              basegame.cpp:2001 (6)
//         0041df9f     MOV        dword ptr [do_fixed_update],EDI
//                              basegame.cpp:2002 (5)
//         0041dfa5     CMP        byte ptr [EAX],0x3d
//         0041dfa8     JZ         LAB_0041dfbb
//                               LAB_0041dfaa                                                 XREF[1]:     0041dfb9(j)
//                              basegame.cpp:2003 (17)
//         0041dfaa     PUSH       EDI
//         0041dfab     PUSH       EAX=>DAT_fffffff8
//         0041dfac     CALL       __mbsninc                                        undefined __mbsninc()
//         0041dfb1     MOV        this,byte ptr [EAX]
//         0041dfb3     ADD        ESP,0x8
//         0041dfb6     CMP        this,0x3d
//         0041dfb9     JNZ        LAB_0041dfaa
//                               LAB_0041dfbb                                                 XREF[1]:     0041dfa8(j)
//                              basegame.cpp:2004 (9)
//         0041dfbb     PUSH       EDI
//         0041dfbc     PUSH       EAX=>DAT_fffffff8
//         0041dfbd     CALL       __mbsninc                                        undefined __mbsninc()
//         0041dfc2     MOV        ESI,EAX
//                              basegame.cpp:2006 (33)
//         0041dfc4     XOR        EAX,EAX
//         0041dfc6     ADD        ESP,0x8
//         0041dfc9     MOV        byte ptr [ESP + 0x110],0x0
//         0041dfd1     MOV        AL,byte ptr [ESI]
//         0041dfd3     PUSH       EAX
//         0041dfd4     CALL       __ismbcspace                                     undefined __ismbcspace()
//         0041dfd9     ADD        ESP,0x4
//         0041dfdc     TEST       EAX,EAX
//         0041dfde     JNZ        LAB_0041e014
//                               LAB_0041dfe0                                                 XREF[1]:     0041e012(j)
//         0041dfe0     CMP        byte ptr [ESI],0x0
//         0041dfe3     JZ         LAB_0041e014
//                              basegame.cpp:2008 (18)
//         0041dfe5     PUSH       EDI
//         0041dfe6     LEA        this,[ESP + 0x114]
//         0041dfed     PUSH       ESI=>DAT_fffffff8
//         0041dfee     PUSH       this=>DAT_fffffff4
//         0041dfef     CALL       __mbsncat                                        undefined __mbsncat()
//         0041dff4     ADD        ESP,0xc
//                              basegame.cpp:2009 (29)
//         0041dff7     PUSH       EDI
//         0041dff8     PUSH       ESI=>DAT_fffffff8
//         0041dff9     CALL       __mbsninc                                        undefined __mbsninc()
//         0041dffe     MOV        ESI,EAX
//         0041e000     XOR        EDX,EDX
//         0041e002     ADD        ESP,0x8
//         0041e005     MOV        DL,byte ptr [ESI]
//         0041e007     PUSH       EDX
//         0041e008     CALL       __ismbcspace                                     undefined __ismbcspace()
//         0041e00d     ADD        ESP,0x4
//         0041e010     TEST       EAX,EAX
//         0041e012     JZ         LAB_0041dfe0
//                               LAB_0041e014                                                 XREF[2]:     0041dfde(j), 0041dfe3(j)
//                              basegame.cpp:2011 (21)
//         0041e014     LEA        EAX,[ESP + 0x110]
//         0041e01b     PUSH       EAX
//         0041e01c     CALL       atol                                             undefined atol()
//         0041e021     ADD        ESP,0x4
//         0041e024     MOV        [fixed_update_time],EAX                          = 64h
//                               LAB_0041e029                                                 XREF[1]:     0041df93(j)
//                              basegame.cpp:2015 (18)
//         0041e029     LEA        this,[ESP + 0x10]
//         0041e02d     PUSH       s_AISPEED=                                       = "AISPEED="
//         0041e032     PUSH       this=>DAT_fffffff8
//         0041e033     CALL       __mbsstr                                         undefined __mbsstr()
//         0041e038     ADD        ESP,0x8
//                              basegame.cpp:2016 (8)
//         0041e03b     CMP        EAX,EBX
//         0041e03d     JZ         LAB_0041e0d3
//                              basegame.cpp:2018 (6)
//         0041e043     MOV        dword ptr [do_debug_timeGetTime],EDI
//                              basegame.cpp:2019 (6)
//         0041e049     MOV        dword ptr [do_fixed_update],EDI
//                              basegame.cpp:2020 (5)
//         0041e04f     CMP        byte ptr [EAX],0x3d
//         0041e052     JZ         LAB_0041e065
//                               LAB_0041e054                                                 XREF[1]:     0041e063(j)
//                              basegame.cpp:2021 (17)
//         0041e054     PUSH       EDI
//         0041e055     PUSH       EAX=>DAT_fffffff8
//         0041e056     CALL       __mbsninc                                        undefined __mbsninc()
//         0041e05b     MOV        this,byte ptr [EAX]
//         0041e05d     ADD        ESP,0x8
//         0041e060     CMP        this,0x3d
//         0041e063     JNZ        LAB_0041e054
//                               LAB_0041e065                                                 XREF[1]:     0041e052(j)
//                              basegame.cpp:2022 (9)
//         0041e065     PUSH       EDI
//         0041e066     PUSH       EAX=>DAT_fffffff8
//         0041e067     CALL       __mbsninc                                        undefined __mbsninc()
//         0041e06c     MOV        ESI,EAX
//                              basegame.cpp:2024 (33)
//         0041e06e     XOR        EDX,EDX
//         0041e070     ADD        ESP,0x8
//         0041e073     MOV        byte ptr [ESP + 0x110],0x0
//         0041e07b     MOV        DL,byte ptr [ESI]
//         0041e07d     PUSH       EDX
//         0041e07e     CALL       __ismbcspace                                     undefined __ismbcspace()
//         0041e083     ADD        ESP,0x4
//         0041e086     TEST       EAX,EAX
//         0041e088     JNZ        LAB_0041e0be
//                               LAB_0041e08a                                                 XREF[1]:     0041e0bc(j)
//         0041e08a     CMP        byte ptr [ESI],0x0
//         0041e08d     JZ         LAB_0041e0be
//                              basegame.cpp:2026 (18)
//         0041e08f     PUSH       EDI
//         0041e090     LEA        EAX,[ESP + 0x114]
//         0041e097     PUSH       ESI=>DAT_fffffff8
//         0041e098     PUSH       EAX=>DAT_fffffff4
//         0041e099     CALL       __mbsncat                                        undefined __mbsncat()
//         0041e09e     ADD        ESP,0xc
//                              basegame.cpp:2027 (29)
//         0041e0a1     PUSH       EDI
//         0041e0a2     PUSH       ESI=>DAT_fffffff8
//         0041e0a3     CALL       __mbsninc                                        undefined __mbsninc()
//         0041e0a8     MOV        ESI,EAX
//         0041e0aa     XOR        this,this
//         0041e0ac     ADD        ESP,0x8
//         0041e0af     MOV        this,byte ptr [ESI]
//         0041e0b1     PUSH       this
//         0041e0b2     CALL       __ismbcspace                                     undefined __ismbcspace()
//         0041e0b7     ADD        ESP,0x4
//         0041e0ba     TEST       EAX,EAX
//         0041e0bc     JZ         LAB_0041e08a
//                               LAB_0041e0be                                                 XREF[2]:     0041e088(j), 0041e08d(j)
//                              basegame.cpp:2029 (21)
//         0041e0be     LEA        EDX,[ESP + 0x110]
//         0041e0c5     PUSH       EDX
//         0041e0c6     CALL       atol                                             undefined atol()
//         0041e0cb     ADD        ESP,0x4
//         0041e0ce     MOV        [debug_timeGetTime_interval],EAX                 = 5h
//                               LAB_0041e0d3                                                 XREF[1]:     0041e03d(j)
//                              basegame.cpp:2034 (18)
//         0041e0d3     LEA        EAX,[ESP + 0x10]
//         0041e0d7     PUSH       s_RANDOMGAME=                                    = "RANDOMGAME="
//         0041e0dc     PUSH       EAX=>DAT_fffffff8
//         0041e0dd     CALL       __mbsstr                                         undefined __mbsstr()
//         0041e0e2     ADD        ESP,0x8
//                              basegame.cpp:2035 (8)
//         0041e0e5     CMP        EAX,EBX
//         0041e0e7     JZ         LAB_0041e16f
//                              basegame.cpp:2037 (5)
//         0041e0ed     CMP        byte ptr [EAX],0x3d
//         0041e0f0     JZ         LAB_0041e103
//                               LAB_0041e0f2                                                 XREF[1]:     0041e101(j)
//                              basegame.cpp:2038 (17)
//         0041e0f2     PUSH       EDI
//         0041e0f3     PUSH       EAX=>DAT_fffffff8
//         0041e0f4     CALL       __mbsninc                                        undefined __mbsninc()
//         0041e0f9     MOV        this,byte ptr [EAX]
//         0041e0fb     ADD        ESP,0x8
//         0041e0fe     CMP        this,0x3d
//         0041e101     JNZ        LAB_0041e0f2
//                               LAB_0041e103                                                 XREF[1]:     0041e0f0(j)
//                              basegame.cpp:2039 (9)
//         0041e103     PUSH       EDI
//         0041e104     PUSH       EAX=>DAT_fffffff8
//         0041e105     CALL       __mbsninc                                        undefined __mbsninc()
//         0041e10a     MOV        ESI,EAX
//                              basegame.cpp:2041 (33)
//         0041e10c     XOR        this,this
//         0041e10e     ADD        ESP,0x8
//         0041e111     MOV        byte ptr [ESP + 0x110],0x0
//         0041e119     MOV        this,byte ptr [ESI]
//         0041e11b     PUSH       this
//         0041e11c     CALL       __ismbcspace                                     undefined __ismbcspace()
//         0041e121     ADD        ESP,0x4
//         0041e124     TEST       EAX,EAX
//         0041e126     JNZ        LAB_0041e15c
//                               LAB_0041e128                                                 XREF[1]:     0041e15a(j)
//         0041e128     CMP        byte ptr [ESI],0x0
//         0041e12b     JZ         LAB_0041e15c
//                              basegame.cpp:2043 (18)
//         0041e12d     PUSH       EDI
//         0041e12e     LEA        EDX,[ESP + 0x114]
//         0041e135     PUSH       ESI=>DAT_fffffff8
//         0041e136     PUSH       EDX=>DAT_fffffff4
//         0041e137     CALL       __mbsncat                                        undefined __mbsncat()
//         0041e13c     ADD        ESP,0xc
//                              basegame.cpp:2044 (29)
//         0041e13f     PUSH       EDI
//         0041e140     PUSH       ESI=>DAT_fffffff8
//         0041e141     CALL       __mbsninc                                        undefined __mbsninc()
//         0041e146     MOV        ESI,EAX
//         0041e148     XOR        EAX,EAX
//         0041e14a     ADD        ESP,0x8
//         0041e14d     MOV        AL,byte ptr [ESI]
//         0041e14f     PUSH       EAX
//         0041e150     CALL       __ismbcspace                                     undefined __ismbcspace()
//         0041e155     ADD        ESP,0x4
//         0041e158     TEST       EAX,EAX
//         0041e15a     JZ         LAB_0041e128
//                               LAB_0041e15c                                                 XREF[2]:     0041e126(j), 0041e12b(j)
//                              basegame.cpp:2046 (19)
//         0041e15c     LEA        this,[ESP + 0x110]
//         0041e163     PUSH       this
//         0041e164     CALL       atol                                             undefined atol()
//         0041e169     ADD        ESP,0x4
//         0041e16c     MOV        dword ptr [EBP + 0x28],EAX
//                               LAB_0041e16f                                                 XREF[1]:     0041e0e7(j)
//                              basegame.cpp:2050 (18)
//         0041e16f     LEA        EDX,[ESP + 0x10]
//         0041e173     PUSH       s_RANDOMMAP=                                     = "RANDOMMAP="
//         0041e178     PUSH       EDX=>DAT_fffffff8
//         0041e179     CALL       __mbsstr                                         undefined __mbsstr()
//         0041e17e     ADD        ESP,0x8
//                              basegame.cpp:2051 (8)
//         0041e181     CMP        EAX,EBX
//         0041e183     JZ         LAB_0041e20b
//                              basegame.cpp:2053 (5)
//         0041e189     CMP        byte ptr [EAX],0x3d
//         0041e18c     JZ         LAB_0041e19f
//                               LAB_0041e18e                                                 XREF[1]:     0041e19d(j)
//                              basegame.cpp:2054 (17)
//         0041e18e     PUSH       EDI
//         0041e18f     PUSH       EAX=>DAT_fffffff8
//         0041e190     CALL       __mbsninc                                        undefined __mbsninc()
//         0041e195     MOV        this,byte ptr [EAX]
//         0041e197     ADD        ESP,0x8
//         0041e19a     CMP        this,0x3d
//         0041e19d     JNZ        LAB_0041e18e
//                               LAB_0041e19f                                                 XREF[1]:     0041e18c(j)
//                              basegame.cpp:2055 (9)
//         0041e19f     PUSH       EDI
//         0041e1a0     PUSH       EAX=>DAT_fffffff8
//         0041e1a1     CALL       __mbsninc                                        undefined __mbsninc()
//         0041e1a6     MOV        ESI,EAX
//                              basegame.cpp:2057 (33)
//         0041e1a8     XOR        EAX,EAX
//         0041e1aa     ADD        ESP,0x8
//         0041e1ad     MOV        byte ptr [ESP + 0x110],0x0
//         0041e1b5     MOV        AL,byte ptr [ESI]
//         0041e1b7     PUSH       EAX
//         0041e1b8     CALL       __ismbcspace                                     undefined __ismbcspace()
//         0041e1bd     ADD        ESP,0x4
//         0041e1c0     TEST       EAX,EAX
//         0041e1c2     JNZ        LAB_0041e1f8
//                               LAB_0041e1c4                                                 XREF[1]:     0041e1f6(j)
//         0041e1c4     CMP        byte ptr [ESI],0x0
//         0041e1c7     JZ         LAB_0041e1f8
//                              basegame.cpp:2059 (18)
//         0041e1c9     PUSH       EDI
//         0041e1ca     LEA        this,[ESP + 0x114]
//         0041e1d1     PUSH       ESI=>DAT_fffffff8
//         0041e1d2     PUSH       this=>DAT_fffffff4
//         0041e1d3     CALL       __mbsncat                                        undefined __mbsncat()
//         0041e1d8     ADD        ESP,0xc
//                              basegame.cpp:2060 (29)
//         0041e1db     PUSH       EDI
//         0041e1dc     PUSH       ESI=>DAT_fffffff8
//         0041e1dd     CALL       __mbsninc                                        undefined __mbsninc()
//         0041e1e2     MOV        ESI,EAX
//         0041e1e4     XOR        EDX,EDX
//         0041e1e6     ADD        ESP,0x8
//         0041e1e9     MOV        DL,byte ptr [ESI]
//         0041e1eb     PUSH       EDX
//         0041e1ec     CALL       __ismbcspace                                     undefined __ismbcspace()
//         0041e1f1     ADD        ESP,0x4
//         0041e1f4     TEST       EAX,EAX
//         0041e1f6     JZ         LAB_0041e1c4
//                               LAB_0041e1f8                                                 XREF[2]:     0041e1c2(j), 0041e1c7(j)
//                              basegame.cpp:2062 (19)
//         0041e1f8     LEA        EAX,[ESP + 0x110]
//         0041e1ff     PUSH       EAX
//         0041e200     CALL       atol                                             undefined atol()
//         0041e205     ADD        ESP,0x4
//         0041e208     MOV        dword ptr [EBP + 0x2c],EAX
//                               LAB_0041e20b                                                 XREF[1]:     0041e183(j)
//                              basegame.cpp:2066 (18)
//         0041e20b     LEA        this,[ESP + 0x10]
//         0041e20f     PUSH       s_DRAWLOG=                                       = "DRAWLOG="
//         0041e214     PUSH       this=>DAT_fffffff8
//         0041e215     CALL       __mbsstr                                         undefined __mbsstr()
//         0041e21a     ADD        ESP,0x8
//                              basegame.cpp:2067 (4)
//         0041e21d     CMP        EAX,EBX
//         0041e21f     JZ         LAB_0041e28c
//                              basegame.cpp:2069 (5)
//         0041e221     CMP        byte ptr [EAX],0x3d
//         0041e224     JZ         LAB_0041e237
//                               LAB_0041e226                                                 XREF[1]:     0041e235(j)
//                              basegame.cpp:2070 (17)
//         0041e226     PUSH       EDI
//         0041e227     PUSH       EAX=>DAT_fffffff8
//         0041e228     CALL       __mbsninc                                        undefined __mbsninc()
//         0041e22d     MOV        this,byte ptr [EAX]
//         0041e22f     ADD        ESP,0x8
//         0041e232     CMP        this,0x3d
//         0041e235     JNZ        LAB_0041e226
//                               LAB_0041e237                                                 XREF[1]:     0041e224(j)
//                              basegame.cpp:2071 (9)
//         0041e237     PUSH       EDI
//         0041e238     PUSH       EAX=>DAT_fffffff8
//         0041e239     CALL       __mbsninc                                        undefined __mbsninc()
//         0041e23e     MOV        ESI,EAX
//                              basegame.cpp:2073 (32)
//         0041e240     XOR        EDX,EDX
//         0041e242     ADD        ESP,0x8
//         0041e245     MOV        byte ptr [draw_log_name],0x0                     = 00000000
//         0041e24c     MOV        DL,byte ptr [ESI]
//         0041e24e     PUSH       EDX
//         0041e24f     CALL       __ismbcspace                                     undefined __ismbcspace()
//         0041e254     ADD        ESP,0x4
//         0041e257     TEST       EAX,EAX
//         0041e259     JNZ        LAB_0041e28c
//                               LAB_0041e25b                                                 XREF[1]:     0041e28a(j)
//         0041e25b     CMP        byte ptr [ESI],0x0
//         0041e25e     JZ         LAB_0041e28c
//                              basegame.cpp:2075 (15)
//         0041e260     PUSH       EDI
//         0041e261     PUSH       ESI=>DAT_fffffff8
//         0041e262     PUSH       draw_log_name                                    = 00000000
//         0041e267     CALL       __mbsncat                                        undefined __mbsncat()
//         0041e26c     ADD        ESP,0xc
//                              basegame.cpp:2076 (29)
//         0041e26f     PUSH       EDI
//         0041e270     PUSH       ESI=>DAT_fffffff8
//         0041e271     CALL       __mbsninc                                        undefined __mbsninc()
//         0041e276     MOV        ESI,EAX
//         0041e278     XOR        EAX,EAX
//         0041e27a     ADD        ESP,0x8
//         0041e27d     MOV        AL,byte ptr [ESI]
//         0041e27f     PUSH       EAX
//         0041e280     CALL       __ismbcspace                                     undefined __ismbcspace()
//         0041e285     ADD        ESP,0x4
//         0041e288     TEST       EAX,EAX
//         0041e28a     JZ         LAB_0041e25b
//                               LAB_0041e28c                                                 XREF[3]:     0041e21f(j), 0041e259(j),
//                                                                                                         0041e25e(j)
//                              basegame.cpp:2080 (22)
//         0041e28c     LEA        this,[ESP + 0x10]
//         0041e290     PUSH       s_DRAWLOG                                        = "DRAWLOG"
//         0041e295     PUSH       this=>DAT_fffffff8
//         0041e296     CALL       strstr                                           undefined strstr()
//         0041e29b     ADD        ESP,0x8
//         0041e29e     TEST       EAX,EAX
//         0041e2a0     JZ         LAB_0041e2a8
//                              basegame.cpp:2081 (6)
//         0041e2a2     MOV        dword ptr [do_draw_log],EDI
//                               LAB_0041e2a8                                                 XREF[1]:     0041e2a0(j)
//                              basegame.cpp:2083 (22)
//         0041e2a8     LEA        EDX,[ESP + 0x10]
//         0041e2ac     PUSH       s_SAFEDRAWLOG                                    = "SAFEDRAWLOG"
//         0041e2b1     PUSH       EDX=>DAT_fffffff8
//         0041e2b2     CALL       strstr                                           undefined strstr()
//         0041e2b7     ADD        ESP,0x8
//         0041e2ba     TEST       EAX,EAX
//         0041e2bc     JZ         LAB_0041e2c4
//                              basegame.cpp:2084 (6)
//         0041e2be     MOV        dword ptr [safe_draw_log],EDI
//                               LAB_0041e2c4                                                 XREF[1]:     0041e2bc(j)
//                              basegame.cpp:2102 (18)
//         0041e2c4     LEA        EAX,[ESP + 0x10]
//         0041e2c8     PUSH       s_DATA=                                          = "DATA="
//         0041e2cd     PUSH       EAX=>DAT_fffffff8
//         0041e2ce     CALL       __mbsstr                                         undefined __mbsstr()
//         0041e2d3     ADD        ESP,0x8
//                              basegame.cpp:2103 (4)
//         0041e2d6     CMP        EAX,EBX
//         0041e2d8     JZ         LAB_0041e34c
//                              basegame.cpp:2105 (5)
//         0041e2da     CMP        byte ptr [EAX],0x3d
//         0041e2dd     JZ         LAB_0041e2f0
//                               LAB_0041e2df                                                 XREF[1]:     0041e2ee(j)
//                              basegame.cpp:2106 (17)
//         0041e2df     PUSH       EDI
//         0041e2e0     PUSH       EAX=>DAT_fffffff8
//         0041e2e1     CALL       __mbsninc                                        undefined __mbsninc()
//         0041e2e6     MOV        this,byte ptr [EAX]
//         0041e2e8     ADD        ESP,0x8
//         0041e2eb     CMP        this,0x3d
//         0041e2ee     JNZ        LAB_0041e2df
//                               LAB_0041e2f0                                                 XREF[1]:     0041e2dd(j)
//                              basegame.cpp:2107 (7)
//         0041e2f0     PUSH       EDI
//         0041e2f1     PUSH       EAX=>DAT_fffffff8
//         0041e2f2     CALL       __mbsninc                                        undefined __mbsninc()
//                              basegame.cpp:2108 (5)
//         0041e2f7     MOV        this,dword ptr [EBP + 0xc]
//         0041e2fa     MOV        ESI,EAX
//                              basegame.cpp:2109 (32)
//         0041e2fc     XOR        EDX,EDX
//         0041e2fe     ADD        ESP,0x8
//         0041e301     MOV        byte ptr [ECX + this+0x1f8],0x0
//         0041e308     MOV        DL,byte ptr [ESI]
//         0041e30a     PUSH       EDX
//         0041e30b     CALL       __ismbcspace                                     undefined __ismbcspace()
//         0041e310     ADD        ESP,0x4
//         0041e313     TEST       EAX,EAX
//         0041e315     JNZ        LAB_0041e34c
//                               LAB_0041e317                                                 XREF[1]:     0041e34a(j)
//         0041e317     CMP        byte ptr [ESI],0x0
//         0041e31a     JZ         LAB_0041e34c
//                              basegame.cpp:2111 (19)
//         0041e31c     MOV        EAX,dword ptr [EBP + 0xc]
//         0041e31f     PUSH       EDI
//         0041e320     ADD        EAX,0x1f8
//         0041e325     PUSH       ESI=>DAT_fffffff8
//         0041e326     PUSH       EAX=>DAT_fffffff4
//         0041e327     CALL       __mbsncat                                        undefined __mbsncat()
//         0041e32c     ADD        ESP,0xc
//                              basegame.cpp:2112 (29)
//         0041e32f     PUSH       EDI
//         0041e330     PUSH       ESI=>DAT_fffffff8
//         0041e331     CALL       __mbsninc                                        undefined __mbsninc()
//         0041e336     MOV        ESI,EAX
//         0041e338     XOR        this,this
//         0041e33a     ADD        ESP,0x8
//         0041e33d     MOV        this,byte ptr [ESI]
//         0041e33f     PUSH       this
//         0041e340     CALL       __ismbcspace                                     undefined __ismbcspace()
//         0041e345     ADD        ESP,0x4
//         0041e348     TEST       EAX,EAX
//         0041e34a     JZ         LAB_0041e317
//                               LAB_0041e34c                                                 XREF[3]:     0041e2d8(j), 0041e315(j),
//                                                                                                         0041e31a(j)
//                              basegame.cpp:2116 (66)
//         0041e34c     LEA        EDX,[ESP + 0x10]
//         0041e350     PUSH       s_CDAUDIO                                        = "CDAUDIO"
//         0041e355     PUSH       EDX=>DAT_fffffff8
//         0041e356     CALL       strstr                                           undefined strstr()
//         0041e35b     ADD        ESP,0x8
//         0041e35e     TEST       EAX,EAX
//         0041e360     JNZ        LAB_0041e38e
//         0041e362     LEA        EAX,[ESP + 0x10]
//         0041e366     PUSH       s_CD_AUDIO                                       = "CD AUDIO"
//         0041e36b     PUSH       EAX=>DAT_fffffff8
//         0041e36c     CALL       strstr                                           undefined strstr()
//         0041e371     ADD        ESP,0x8
//         0041e374     TEST       EAX,EAX
//         0041e376     JNZ        LAB_0041e38e
//         0041e378     LEA        this,[ESP + 0x10]
//         0041e37c     PUSH       s_CD_AUDIO                                       = "CD_AUDIO"
//         0041e381     PUSH       this=>DAT_fffffff8
//         0041e382     CALL       strstr                                           undefined strstr()
//         0041e387     ADD        ESP,0x8
//         0041e38a     TEST       EAX,EAX
//         0041e38c     JZ         LAB_0041e3bb
//                               LAB_0041e38e                                                 XREF[2]:     0041e360(j), 0041e376(j)
//                              basegame.cpp:2118 (9)
//         0041e38e     MOV        EDX,dword ptr [EBP + 0xc]
//         0041e391     MOV        dword ptr [EDX + 0x8a4],EDI
//                              basegame.cpp:2119 (9)
//         0041e397     MOV        EAX,dword ptr [EBP + 0xc]
//         0041e39a     MOV        dword ptr [EAX + 0x8ac],EDI
//                              basegame.cpp:2120 (9)
//         0041e3a0     MOV        this,dword ptr [EBP + 0xc]
//         0041e3a3     MOV        dword ptr [ECX + this+0x8b0],EBX
//                              basegame.cpp:2121 (9)
//         0041e3a9     MOV        EDX,dword ptr [EBP + 0xc]
//         0041e3ac     MOV        dword ptr [EDX + 0x8b4],EBX
//                              basegame.cpp:2122 (9)
//         0041e3b2     MOV        EAX,dword ptr [EBP + 0xc]
//         0041e3b5     MOV        dword ptr [EAX + 0x8b8],EBX
//                               LAB_0041e3bb                                                 XREF[1]:     0041e38c(j)
//                              basegame.cpp:2125 (22)
//         0041e3bb     LEA        this,[ESP + 0x10]
//         0041e3bf     PUSH       s_WINDOW                                         = "WINDOW"
//         0041e3c4     PUSH       this=>DAT_fffffff8
//         0041e3c5     CALL       strstr                                           undefined strstr()
//         0041e3ca     ADD        ESP,0x8
//         0041e3cd     TEST       EAX,EAX
//         0041e3cf     JZ         LAB_0041e3da
//                              basegame.cpp:2126 (9)
//         0041e3d1     MOV        EDX,dword ptr [EBP + 0xc]
//         0041e3d4     MOV        dword ptr [EDX + 0x894],EBX
//                               LAB_0041e3da                                                 XREF[1]:     0041e3cf(j)
//                              basegame.cpp:2128 (66)
//         0041e3da     LEA        EAX,[ESP + 0x10]
//         0041e3de     PUSH       s_FILEFIRST                                      = "FILEFIRST"
//         0041e3e3     PUSH       EAX=>DAT_fffffff8
//         0041e3e4     CALL       strstr                                           undefined strstr()
//         0041e3e9     ADD        ESP,0x8
//         0041e3ec     TEST       EAX,EAX
//         0041e3ee     JNZ        LAB_0041e41c
//         0041e3f0     LEA        this,[ESP + 0x10]
//         0041e3f4     PUSH       s_FILE_FIRST                                     = "FILE FIRST"
//         0041e3f9     PUSH       this=>DAT_fffffff8
//         0041e3fa     CALL       strstr                                           undefined strstr()
//         0041e3ff     ADD        ESP,0x8
//         0041e402     TEST       EAX,EAX
//         0041e404     JNZ        LAB_0041e41c
//         0041e406     LEA        EDX,[ESP + 0x10]
//         0041e40a     PUSH       s_FILE_FIRST                                     = "FILE_FIRST"
//         0041e40f     PUSH       EDX=>DAT_fffffff8
//         0041e410     CALL       strstr                                           undefined strstr()
//         0041e415     ADD        ESP,0x8
//         0041e418     TEST       EAX,EAX
//         0041e41a     JZ         LAB_0041e42a
//                               LAB_0041e41c                                                 XREF[2]:     0041e3ee(j), 0041e404(j)
//                              basegame.cpp:2130 (7)
//         0041e41c     MOV        byte ptr [shape_file_first],0x1                  = 00h
//                              basegame.cpp:2131 (7)
//         0041e423     MOV        byte ptr [sound_file_first],0x1                  = 00h
//                               LAB_0041e42a                                                 XREF[1]:     0041e41a(j)
//                              basegame.cpp:2134 (66)
//         0041e42a     LEA        EAX,[ESP + 0x10]
//         0041e42e     PUSH       s_LOGCOMM                                        = "LOGCOMM"
//         0041e433     PUSH       EAX=>DAT_fffffff8
//         0041e434     CALL       strstr                                           undefined strstr()
//         0041e439     ADD        ESP,0x8
//         0041e43c     TEST       EAX,EAX
//         0041e43e     JNZ        LAB_0041e46c
//         0041e440     LEA        this,[ESP + 0x10]
//         0041e444     PUSH       s_LOG_COMM                                       = "LOG COMM"
//         0041e449     PUSH       this=>DAT_fffffff8
//         0041e44a     CALL       strstr                                           undefined strstr()
//         0041e44f     ADD        ESP,0x8
//         0041e452     TEST       EAX,EAX
//         0041e454     JNZ        LAB_0041e46c
//         0041e456     LEA        EDX,[ESP + 0x10]
//         0041e45a     PUSH       s_LOG_COMM                                       = "LOG_COMM"
//         0041e45f     PUSH       EDX=>DAT_fffffff8
//         0041e460     CALL       strstr                                           undefined strstr()
//         0041e465     ADD        ESP,0x8
//         0041e468     TEST       EAX,EAX
//         0041e46a     JZ         LAB_0041e48e
//                               LAB_0041e46c                                                 XREF[2]:     0041e43e(j), 0041e454(j)
//                              basegame.cpp:2136 (6)
//         0041e46c     MOV        dword ptr [EBP + 0x1a8],EDI
//                              basegame.cpp:2137 (10)
//         0041e472     MOV        this,dword ptr [L]                               = 00000000
//         0041e478     CMP        this,EBX
//         0041e47a     JZ         LAB_0041e48e
//                              basegame.cpp:2139 (6)
//         0041e47c     PUSH       EDI
//         0041e47d     CALL       TDebuggingLog::LogFile                           void LogFile(TDebuggingLog * this, int param_1)
//                              basegame.cpp:2140 (12)
//         0041e482     MOV        this,dword ptr [L]                               = 00000000
//         0041e488     PUSH       EDI
//         0041e489     CALL       TDebuggingLog::LogTimestamp                      void LogTimestamp(TDebuggingLog * this, int p
//                               LAB_0041e48e                                                 XREF[2]:     0041e46a(j), 0041e47a(j)
//                              basegame.cpp:2146 (66)
//         0041e48e     LEA        EAX,[ESP + 0x10]
//         0041e492     PUSH       s_LOGOUTPUT                                      = "LOGOUTPUT"
//         0041e497     PUSH       EAX=>DAT_fffffff8
//         0041e498     CALL       strstr                                           undefined strstr()
//         0041e49d     ADD        ESP,0x8
//         0041e4a0     TEST       EAX,EAX
//         0041e4a2     JNZ        LAB_0041e4d0
//         0041e4a4     LEA        this,[ESP + 0x10]
//         0041e4a8     PUSH       s_LOG_OUTPUT                                     = "LOG OUTPUT"
//         0041e4ad     PUSH       this=>DAT_fffffff8
//         0041e4ae     CALL       strstr                                           undefined strstr()
//         0041e4b3     ADD        ESP,0x8
//         0041e4b6     TEST       EAX,EAX
//         0041e4b8     JNZ        LAB_0041e4d0
//         0041e4ba     LEA        EDX,[ESP + 0x10]
//         0041e4be     PUSH       s_LOG_OUTPUT                                     = "LOG_OUTPUT"
//         0041e4c3     PUSH       EDX=>DAT_fffffff8
//         0041e4c4     CALL       strstr                                           undefined strstr()
//         0041e4c9     ADD        ESP,0x8
//         0041e4cc     TEST       EAX,EAX
//         0041e4ce     JZ         LAB_0041e4e6
//                               LAB_0041e4d0                                                 XREF[2]:     0041e4a2(j), 0041e4b8(j)
//                              basegame.cpp:2149 (16)
//         0041e4d0     MOV        this,dword ptr [L]                               = 00000000
//         0041e4d6     MOV        dword ptr [log_output],EDI
//         0041e4dc     CMP        this,EBX
//         0041e4de     JZ         LAB_0041e4e6
//                              basegame.cpp:2150 (6)
//         0041e4e0     PUSH       EDI
//         0041e4e1     CALL       TDebuggingLog::LogOutput                         void LogOutput(TDebuggingLog * this, int para
//                               LAB_0041e4e6                                                 XREF[2]:     0041e4ce(j), 0041e4de(j)
//                              basegame.cpp:2153 (22)
//         0041e4e6     LEA        EAX,[ESP + 0x10]
//         0041e4ea     PUSH       s_DEVELOPER                                      = "DEVELOPER"
//         0041e4ef     PUSH       EAX=>DAT_fffffff8
//         0041e4f0     CALL       strstr                                           undefined strstr()
//         0041e4f5     ADD        ESP,0x8
//         0041e4f8     TEST       EAX,EAX
//         0041e4fa     JZ         LAB_0041e504
//                              basegame.cpp:2154 (8)
//         0041e4fc     PUSH       EDI
//         0041e4fd     MOV        this,EBP
//         0041e4ff     CALL       RGE_Base_Game::setGameDeveloperMode              void setGameDeveloperMode(RGE_Base_Game * thi
//                               LAB_0041e504                                                 XREF[1]:     0041e4fa(j)
//                              basegame.cpp:2157 (18)
//         0041e504     LEA        this,[ESP + 0x10]
//         0041e508     PUSH       s_SPEED1=                                        = "SPEED1="
//         0041e50d     PUSH       this=>DAT_fffffff8
//         0041e50e     CALL       __mbsstr                                         undefined __mbsstr()
//         0041e513     ADD        ESP,0x8
//                              basegame.cpp:2158 (8)
//         0041e516     CMP        EAX,EBX
//         0041e518     JZ         LAB_0041e5a2
//                              basegame.cpp:2160 (5)
//         0041e51e     CMP        byte ptr [EAX],0x3d
//         0041e521     JZ         LAB_0041e534
//                               LAB_0041e523                                                 XREF[1]:     0041e532(j)
//                              basegame.cpp:2161 (17)
//         0041e523     PUSH       EDI
//         0041e524     PUSH       EAX=>DAT_fffffff8
//         0041e525     CALL       __mbsninc                                        undefined __mbsninc()
//         0041e52a     MOV        this,byte ptr [EAX]
//         0041e52c     ADD        ESP,0x8
//         0041e52f     CMP        this,0x3d
//         0041e532     JNZ        LAB_0041e523
//                               LAB_0041e534                                                 XREF[1]:     0041e521(j)
//                              basegame.cpp:2162 (9)
//         0041e534     PUSH       EDI
//         0041e535     PUSH       EAX=>DAT_fffffff8
//         0041e536     CALL       __mbsninc                                        undefined __mbsninc()
//         0041e53b     MOV        ESI,EAX
//                              basegame.cpp:2164 (33)
//         0041e53d     XOR        EDX,EDX
//         0041e53f     ADD        ESP,0x8
//         0041e542     MOV        byte ptr [ESP + 0x110],0x0
//         0041e54a     MOV        DL,byte ptr [ESI]
//         0041e54c     PUSH       EDX
//         0041e54d     CALL       __ismbcspace                                     undefined __ismbcspace()
//         0041e552     ADD        ESP,0x4
//         0041e555     TEST       EAX,EAX
//         0041e557     JNZ        LAB_0041e58d
//                               LAB_0041e559                                                 XREF[1]:     0041e58b(j)
//         0041e559     CMP        byte ptr [ESI],0x0
//         0041e55c     JZ         LAB_0041e58d
//                              basegame.cpp:2166 (18)
//         0041e55e     PUSH       EDI
//         0041e55f     LEA        EAX,[ESP + 0x114]
//         0041e566     PUSH       ESI=>DAT_fffffff8
//         0041e567     PUSH       EAX=>DAT_fffffff4
//         0041e568     CALL       __mbsncat                                        undefined __mbsncat()
//         0041e56d     ADD        ESP,0xc
//                              basegame.cpp:2167 (29)
//         0041e570     PUSH       EDI
//         0041e571     PUSH       ESI=>DAT_fffffff8
//         0041e572     CALL       __mbsninc                                        undefined __mbsninc()
//         0041e577     MOV        ESI,EAX
//         0041e579     XOR        this,this
//         0041e57b     ADD        ESP,0x8
//         0041e57e     MOV        this,byte ptr [ESI]
//         0041e580     PUSH       this
//         0041e581     CALL       __ismbcspace                                     undefined __ismbcspace()
//         0041e586     ADD        ESP,0x4
//         0041e589     TEST       EAX,EAX
//         0041e58b     JZ         LAB_0041e559
//                               LAB_0041e58d                                                 XREF[2]:     0041e557(j), 0041e55c(j)
//                              basegame.cpp:2169 (21)
//         0041e58d     LEA        EDX,[ESP + 0x110]
//         0041e594     PUSH       EDX
//         0041e595     CALL       atol                                             undefined atol()
//         0041e59a     ADD        ESP,0x4
//         0041e59d     MOV        [speed_val1],EAX
//                               LAB_0041e5a2                                                 XREF[1]:     0041e518(j)
//                              basegame.cpp:2172 (18)
//         0041e5a2     LEA        EAX,[ESP + 0x10]
//         0041e5a6     PUSH       s_SPEED2=                                        = "SPEED2="
//         0041e5ab     PUSH       EAX=>DAT_fffffff8
//         0041e5ac     CALL       __mbsstr                                         undefined __mbsstr()
//         0041e5b1     ADD        ESP,0x8
//                              basegame.cpp:2173 (8)
//         0041e5b4     CMP        EAX,EBX
//         0041e5b6     JZ         LAB_0041e640
//                              basegame.cpp:2175 (5)
//         0041e5bc     CMP        byte ptr [EAX],0x3d
//         0041e5bf     JZ         LAB_0041e5d2
//                               LAB_0041e5c1                                                 XREF[1]:     0041e5d0(j)
//                              basegame.cpp:2176 (17)
//         0041e5c1     PUSH       EDI
//         0041e5c2     PUSH       EAX=>DAT_fffffff8
//         0041e5c3     CALL       __mbsninc                                        undefined __mbsninc()
//         0041e5c8     MOV        this,byte ptr [EAX]
//         0041e5ca     ADD        ESP,0x8
//         0041e5cd     CMP        this,0x3d
//         0041e5d0     JNZ        LAB_0041e5c1
//                               LAB_0041e5d2                                                 XREF[1]:     0041e5bf(j)
//                              basegame.cpp:2177 (9)
//         0041e5d2     PUSH       EDI
//         0041e5d3     PUSH       EAX=>DAT_fffffff8
//         0041e5d4     CALL       __mbsninc                                        undefined __mbsninc()
//         0041e5d9     MOV        ESI,EAX
//                              basegame.cpp:2179 (33)
//         0041e5db     XOR        this,this
//         0041e5dd     ADD        ESP,0x8
//         0041e5e0     MOV        byte ptr [ESP + 0x110],0x0
//         0041e5e8     MOV        this,byte ptr [ESI]
//         0041e5ea     PUSH       this
//         0041e5eb     CALL       __ismbcspace                                     undefined __ismbcspace()
//         0041e5f0     ADD        ESP,0x4
//         0041e5f3     TEST       EAX,EAX
//         0041e5f5     JNZ        LAB_0041e62b
//                               LAB_0041e5f7                                                 XREF[1]:     0041e629(j)
//         0041e5f7     CMP        byte ptr [ESI],0x0
//         0041e5fa     JZ         LAB_0041e62b
//                              basegame.cpp:2181 (18)
//         0041e5fc     PUSH       EDI
//         0041e5fd     LEA        EDX,[ESP + 0x114]
//         0041e604     PUSH       ESI=>DAT_fffffff8
//         0041e605     PUSH       EDX=>DAT_fffffff4
//         0041e606     CALL       __mbsncat                                        undefined __mbsncat()
//         0041e60b     ADD        ESP,0xc
//                              basegame.cpp:2182 (29)
//         0041e60e     PUSH       EDI
//         0041e60f     PUSH       ESI=>DAT_fffffff8
//         0041e610     CALL       __mbsninc                                        undefined __mbsninc()
//         0041e615     MOV        ESI,EAX
//         0041e617     XOR        EAX,EAX
//         0041e619     ADD        ESP,0x8
//         0041e61c     MOV        AL,byte ptr [ESI]
//         0041e61e     PUSH       EAX
//         0041e61f     CALL       __ismbcspace                                     undefined __ismbcspace()
//         0041e624     ADD        ESP,0x4
//         0041e627     TEST       EAX,EAX
//         0041e629     JZ         LAB_0041e5f7
//                               LAB_0041e62b                                                 XREF[2]:     0041e5f5(j), 0041e5fa(j)
//                              basegame.cpp:2184 (21)
//         0041e62b     LEA        this,[ESP + 0x110]
//         0041e632     PUSH       this
//         0041e633     CALL       atol                                             undefined atol()
//         0041e638     ADD        ESP,0x4
//         0041e63b     MOV        [speed_val2],EAX
//                               LAB_0041e640                                                 XREF[1]:     0041e5b6(j)
//                              basegame.cpp:2189 (77)
//         0041e640     MOV        EDX,dword ptr [EBP + 0xc]
//         0041e643     CMP        dword ptr [EDX + 0x8a8],EBX
//         0041e649     JZ         LAB_0041e68d
//         0041e64b     LEA        EAX,[ESP + 0x10]
//         0041e64f     PUSH       s_NOMUSIC                                        = "NOMUSIC"
//         0041e654     PUSH       EAX=>DAT_fffffff8
//         0041e655     CALL       strstr                                           undefined strstr()
//         0041e65a     ADD        ESP,0x8
//         0041e65d     TEST       EAX,EAX
//         0041e65f     JNZ        LAB_0041e68d
//         0041e661     LEA        this,[ESP + 0x10]
//         0041e665     PUSH       s_NO_MUSIC                                       = "NO MUSIC"
//         0041e66a     PUSH       this=>DAT_fffffff8
//         0041e66b     CALL       strstr                                           undefined strstr()
//         0041e670     ADD        ESP,0x8
//         0041e673     TEST       EAX,EAX
//         0041e675     JNZ        LAB_0041e68d
//         0041e677     LEA        EDX,[ESP + 0x10]
//         0041e67b     PUSH       s_NO_MUSIC                                       = "NO_MUSIC"
//         0041e680     PUSH       EDX=>DAT_fffffff8
//         0041e681     CALL       strstr                                           undefined strstr()
//         0041e686     ADD        ESP,0x8
//         0041e689     TEST       EAX,EAX
//         0041e68b     JZ         LAB_0041e696
//                               LAB_0041e68d                                                 XREF[3]:     0041e649(j), 0041e65f(j),
//                                                                                                         0041e675(j)
//                              basegame.cpp:2190 (9)
//         0041e68d     MOV        EAX,dword ptr [EBP + 0xc]
//         0041e690     MOV        dword ptr [EAX + 0x8a4],EBX
//                               LAB_0041e696                                                 XREF[1]:     0041e68b(j)
//                              basegame.cpp:2192 (19)
//         0041e696     MOV        EAX,dword ptr [EBP + 0xc]
//         0041e699     CMP        dword ptr [EAX + 0x89c],EDI
//         0041e69f     JNZ        LAB_0041e6ac
//         0041e6a1     CMP        dword ptr [EAX + 0x894],EDI
//         0041e6a7     JNZ        LAB_0041e6ac
//                              basegame.cpp:2193 (3)
//         0041e6a9     MOV        dword ptr [EBP + 0x54],EDI
//                               LAB_0041e6ac                                                 XREF[2]:     0041e69f(j), 0041e6a7(j)
//                              basegame.cpp:2195 (66)
//         0041e6ac     LEA        this,[ESP + 0x10]
//         0041e6b0     PUSH       s_NORMALMOUSE                                    = "NORMALMOUSE"
//         0041e6b5     PUSH       this=>DAT_fffffff8
//         0041e6b6     CALL       strstr                                           undefined strstr()
//         0041e6bb     ADD        ESP,0x8
//         0041e6be     TEST       EAX,EAX
//         0041e6c0     JNZ        LAB_0041e6ee
//         0041e6c2     LEA        EDX,[ESP + 0x10]
//         0041e6c6     PUSH       s_NORMAL_MOUSE                                   = "NORMAL MOUSE"
//         0041e6cb     PUSH       EDX=>DAT_fffffff8
//         0041e6cc     CALL       strstr                                           undefined strstr()
//         0041e6d1     ADD        ESP,0x8
//         0041e6d4     TEST       EAX,EAX
//         0041e6d6     JNZ        LAB_0041e6ee
//         0041e6d8     LEA        EAX,[ESP + 0x10]
//         0041e6dc     PUSH       s_NORMAL_MOUSE                                   = "NORMAL_MOUSE"
//         0041e6e1     PUSH       EAX=>DAT_fffffff8
//         0041e6e2     CALL       strstr                                           undefined strstr()
//         0041e6e7     ADD        ESP,0x8
//         0041e6ea     TEST       EAX,EAX
//         0041e6ec     JZ         LAB_0041e6f1
//                               LAB_0041e6ee                                                 XREF[2]:     0041e6c0(j), 0041e6d6(j)
//                              basegame.cpp:2196 (3)
//         0041e6ee     MOV        dword ptr [EBP + 0x54],EBX
//                               LAB_0041e6f1                                                 XREF[1]:     0041e6ec(j)
//                              basegame.cpp:2198 (2)
//         0041e6f1     MOV        EAX,EDI
//                              basegame.cpp:2199 (11)
//         0041e6f3     POP        EDI
//         0041e6f4     POP        ESI
//         0041e6f5     POP        EBP
//         0041e6f6     POP        EBX
//         0041e6f7     ADD        ESP,0x200
//         0041e6fd     RET
//         0041e6fe     ??         90h
//         0041e6ff     NOP
    return 0;
}

int RGE_Base_Game::setup_class() {
    /* TODO: Stub */
//                              int __thiscall setup_class(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              tagWNDCLASSA      Stack[-0x2c]   cls                       XREF[0,3]:   0041e725(W), 0041e72b(W), 0041e737(W)
//                               ?setup_class@RGE_Base_Game@@MAEHXZ                           XREF[2]:     0056ef38(*), 00577210(*)
//                               RGE_Base_Game::setup_class
//                              basegame.cpp:2205 (7)
//         0041e700     SUB        ESP,0x28
//         0041e703     PUSH       EBX
//         0041e704     PUSH       ESI
//         0041e705     MOV        ESI,this
//                              basegame.cpp:2208 (13)
//         0041e707     XOR        EBX,EBX
//         0041e709     MOV        EAX,dword ptr [ESI + 0xc]
//         0041e70c     CMP        dword ptr [EAX + 0x414],EBX
//         0041e712     JZ         LAB_0041e71f
//                              basegame.cpp:2209 (5)
//         0041e714     MOV        EAX,0x1
//                              basegame.cpp:2236 (6)
//         0041e719     POP        ESI
//         0041e71a     POP        EBX
//         0041e71b     ADD        ESP,0x28
//         0041e71e     RET
//                               LAB_0041e71f                                                 XREF[1]:     0041e712(j)
//                              basegame.cpp:2218 (12)
//         0041e71f     LEA        this,[EAX + 0x645]
//         0041e725     MOV        dword ptr [ESP + cls.hbrBackground],EBX
//         0041e729     MOV        DL,byte ptr [this->_padding_]
//                              basegame.cpp:2219 (12)
//         0041e72b     MOV        dword ptr [ESP + cls.lpszClassName],s_           = ""
//         0041e733     CMP        DL,BL
//         0041e735     JZ         LAB_0041e73b
//                              basegame.cpp:2221 (4)
//         0041e737     MOV        dword ptr [ESP + cls.lpszClassName],this
//                               LAB_0041e73b                                                 XREF[1]:     0041e735(j)
//                              basegame.cpp:2223 (24)
//         0041e73b     MOV        EDX,dword ptr [EAX + 0x410]
//         0041e741     LEA        this,[EAX + 0x61c]
//         0041e747     PUSH       this
//         0041e748     PUSH       EDX
//         0041e749     CALL       dword ptr [->USER32.DLL::LoadIconA]              = 0048adaa
//         0041e74f     MOV        dword ptr [ESP + 0x1c],EAX
//                              basegame.cpp:2224 (7)
//         0041e753     MOV        EAX,dword ptr [ESI + 0xc]
//         0041e756     MOV        dword ptr [ESP + 0x2c],EAX
//                              basegame.cpp:2225 (4)
//         0041e75a     MOV        dword ptr [ESP + 0x24],EBX
//                              basegame.cpp:2226 (6)
//         0041e75e     MOV        EAX,dword ptr [EAX + 0x410]
//                              basegame.cpp:2232 (44)
//         0041e764     LEA        this,[ESP + 0x8]
//         0041e768     PUSH       this
//         0041e769     MOV        dword ptr [ESP + 0x1c],EAX
//         0041e76d     MOV        dword ptr [ESP + 0xc],0xb
//         0041e775     MOV        dword ptr [ESP + 0x10],rge_base_game_wnd_proc
//         0041e77d     MOV        dword ptr [ESP + 0x18],EBX
//         0041e781     MOV        dword ptr [ESP + 0x14],EBX
//         0041e785     CALL       dword ptr [->USER32.DLL::RegisterClassA]         = 0048ad98
//         0041e78b     NEG        AX
//         0041e78e     SBB        EAX,EAX
//                              basegame.cpp:2236 (8)
//         0041e790     POP        ESI
//         0041e791     NEG        EAX
//         0041e793     POP        EBX
//         0041e794     ADD        ESP,0x28
//         0041e797     RET
//         0041e798     ??         90h
//         0041e799     NOP
//         0041e79a     NOP
//         0041e79b     NOP
//         0041e79c     NOP
//         0041e79d     NOP
//         0041e79e     NOP
//         0041e79f     NOP
    return 0;
}

int RGE_Base_Game::setup_main_window() {
    /* TODO: Stub */
//                              int __thiscall setup_main_window(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              tagRECT           Stack[-0x14]   client_rect
//              tagRECT           Stack[-0x24]   win_rect
//                               ?setup_main_window@RGE_Base_Game@@MAEHXZ                     XREF[2]:     0056ef3c(*), 00577214(*)
//                               RGE_Base_Game::setup_main_window
//                              basegame.cpp:2242 (6)
//         0041e7d0     SUB        ESP,0x20
//         0041e7d3     PUSH       EBX
//         0041e7d4     PUSH       ESI
//         0041e7d5     PUSH       EDI
//                              basegame.cpp:2251 (12)
//         0041e7d6     MOV        EDI,dword ptr [->USER32.DLL::GetSystemMetrics]   = 0048ae08
//         0041e7dc     MOV        ESI,this
//         0041e7de     PUSH       0x0
//         0041e7e0     CALL       EDI=>USER32.DLL::GetSystemMetrics
//                              basegame.cpp:2252 (6)
//         0041e7e2     PUSH       0x1
//         0041e7e4     MOV        EBX,EAX
//         0041e7e6     CALL       EDI=>USER32.DLL::GetSystemMetrics
//                              basegame.cpp:2255 (31)
//         0041e7e8     MOV        this,dword ptr [ESI + 0xc]
//         0041e7eb     MOV        EDX,dword ptr [ECX + this+0x894]
//         0041e7f1     TEST       EDX,EDX
//         0041e7f3     JNZ        LAB_0041e82b
//         0041e7f5     MOV        EDX,dword ptr [ECX + this+0x8e0]
//         0041e7fb     CMP        EBX,EDX
//         0041e7fd     JNZ        LAB_0041e807
//         0041e7ff     CMP        EAX,dword ptr [ECX + this+0x8e4]
//         0041e805     JZ         LAB_0041e82b
//                               LAB_0041e807                                                 XREF[1]:     0041e7fd(j)
//                              basegame.cpp:2267 (36)
//         0041e807     MOV        EAX,dword ptr [ECX + this+0x410]
//         0041e80d     PUSH       0x0
//         0041e80f     PUSH       EAX
//         0041e810     MOV        EAX,dword ptr [ECX + this+0x8e4]
//         0041e816     PUSH       0x0
//         0041e818     PUSH       0x0
//         0041e81a     PUSH       EAX
//         0041e81b     PUSH       EDX
//         0041e81c     PUSH       0x0
//         0041e81e     PUSH       0x0
//         0041e820     LEA        EDX,[ECX + this+0x7a]
//         0041e823     PUSH       0x2ca0000
//         0041e828     PUSH       EDX
//         0041e829     JMP        LAB_0041e847
//                               LAB_0041e82b                                                 XREF[2]:     0041e7f3(j), 0041e805(j)
//                              basegame.cpp:2260 (37)
//         0041e82b     MOV        EDX,dword ptr [ECX + this+0x410]
//         0041e831     PUSH       0x0
//         0041e833     PUSH       EDX
//         0041e834     PUSH       0x0
//         0041e836     PUSH       0x0
//         0041e838     PUSH       EAX
//         0041e839     PUSH       EBX
//         0041e83a     PUSH       0x0
//         0041e83c     PUSH       0x0
//         0041e83e     LEA        EAX,[ECX + this+0x7a]
//         0041e841     PUSH       0x82080000
//         0041e846     PUSH       EAX
//                               LAB_0041e847                                                 XREF[1]:     0041e829(j)
//         0041e847     PUSH       this
//         0041e848     PUSH       0x0
//         0041e84a     CALL       dword ptr [->USER32.DLL::CreateWindowExA]        = 0048adf6
//                              basegame.cpp:2269 (7)
//         0041e850     TEST       EAX,EAX
//         0041e852     MOV        dword ptr [ESI + 0x10],EAX
//         0041e855     JNZ        LAB_0041e85e
//                              basegame.cpp:2288 (7)
//         0041e857     POP        EDI
//         0041e858     POP        ESI
//         0041e859     POP        EBX
//         0041e85a     ADD        ESP,0x20
//         0041e85d     RET
//                               LAB_0041e85e                                                 XREF[1]:     0041e855(j)
//                              basegame.cpp:2272 (12)
//         0041e85e     LEA        this,[ESP + 0xc]
//         0041e862     PUSH       this
//         0041e863     PUSH       EAX
//         0041e864     CALL       dword ptr [->USER32.DLL::GetWindowRect]          = 0048ade6
//                              basegame.cpp:2273 (15)
//         0041e86a     MOV        EAX,dword ptr [ESI + 0x10]
//         0041e86d     LEA        EDX,[ESP + 0x1c]
//         0041e871     PUSH       EDX
//         0041e872     PUSH       EAX
//         0041e873     CALL       dword ptr [->USER32.DLL::GetClientRect]          = 0048add6
//                              basegame.cpp:2274 (29)
//         0041e879     MOV        EAX,dword ptr [ESI + 0xc]
//         0041e87c     MOV        EDI,dword ptr [ESP + 0x24]
//         0041e880     MOV        EDX,dword ptr [ESP + 0x28]
//         0041e884     MOV        this,dword ptr [EAX + 0x8e0]
//         0041e88a     CMP        EDI,this
//         0041e88c     JNZ        LAB_0041e896
//         0041e88e     CMP        EDX,dword ptr [EAX + 0x8e4]
//         0041e894     JZ         LAB_0041e8ca
//                               LAB_0041e896                                                 XREF[1]:     0041e88c(j)
//                              basegame.cpp:2275 (52)
//         0041e896     MOV        EBX,dword ptr [EAX + 0x8e4]
//         0041e89c     MOV        EAX,dword ptr [ESP + 0x10]
//         0041e8a0     SUB        EBX,EAX
//         0041e8a2     PUSH       0x0
//         0041e8a4     SUB        EBX,EDX
//         0041e8a6     MOV        EDX,dword ptr [ESP + 0x1c]
//         0041e8aa     ADD        EBX,EDX
//         0041e8ac     MOV        EDX,dword ptr [ESP + 0x10]
//         0041e8b0     PUSH       EBX
//         0041e8b1     MOV        EBX,dword ptr [ESP + 0x1c]
//         0041e8b5     SUB        EBX,EDX
//         0041e8b7     SUB        EBX,EDI
//         0041e8b9     ADD        EBX,this
//         0041e8bb     MOV        this,dword ptr [ESI + 0x10]
//         0041e8be     PUSH       EBX
//         0041e8bf     PUSH       EAX
//         0041e8c0     PUSH       EDX
//         0041e8c1     PUSH       0x0
//         0041e8c3     PUSH       this
//         0041e8c4     CALL       dword ptr [->USER32.DLL::SetWindowPos]           = 0048adc6
//                               LAB_0041e8ca                                                 XREF[1]:     0041e894(j)
//                              basegame.cpp:2277 (13)
//         0041e8ca     MOV        EAX,dword ptr [ESI + 0xc]
//         0041e8cd     MOV        this,dword ptr [EAX + 0x894]
//         0041e8d3     TEST       this,this
//         0041e8d5     JZ         LAB_0041e8fc
//                              basegame.cpp:2279 (17)
//         0041e8d7     MOV        EDX,dword ptr [EAX + 0x618]
//         0041e8dd     MOV        EAX,dword ptr [ESI + 0x10]
//         0041e8e0     PUSH       EDX
//         0041e8e1     PUSH       EAX=>DAT_fffffff8
//         0041e8e2     CALL       dword ptr [->USER32.DLL::ShowWindow]             = 0048ace2
//                              basegame.cpp:2280 (10)
//         0041e8e8     MOV        this,dword ptr [ESI + 0x10]
//         0041e8eb     PUSH       this
//         0041e8ec     CALL       dword ptr [->USER32.DLL::UpdateWindow]           = 0048adb6
//                              basegame.cpp:2281 (10)
//         0041e8f2     MOV        EDX,dword ptr [ESI + 0x10]
//         0041e8f5     PUSH       EDX
//         0041e8f6     CALL       dword ptr [->USER32.DLL::SetFocus]               = 0048acd6
//                               LAB_0041e8fc                                                 XREF[1]:     0041e8d5(j)
//                              basegame.cpp:2284 (3)
//         0041e8fc     MOV        EAX,dword ptr [ESI + 0x10]
//                              basegame.cpp:2285 (15)
//         0041e8ff     MOV        this,panel_system
//         0041e904     MOV        [AppWnd],EAX                                     = 00000000
//         0041e909     CALL       TPanelSystem::DisableIME                         void DisableIME(TPanelSystem * this)
//                              basegame.cpp:2288 (12)
//         0041e90e     POP        EDI
//         0041e90f     POP        ESI
//         0041e910     MOV        EAX,0x1
//         0041e915     POP        EBX
//         0041e916     ADD        ESP,0x20
//         0041e919     RET
//         0041e91a     ??         90h
//         0041e91b     NOP
//         0041e91c     NOP
//         0041e91d     NOP
//         0041e91e     NOP
//         0041e91f     NOP
    return 0;
}

int RGE_Base_Game::setup_graphics_system() {
    /* TODO: Stub */
//                              int __thiscall setup_graphics_system(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              undefined1        Stack[-0x14]:1 local_14                  XREF[1]:     0041e9a4(W)
//              uchar             Stack[-0x18]:1 draw_type                 XREF[1]:     0041e9bb(W)
//              uchar             Stack[-0x1c]:1 draw_mode
//                               ?setup_graphics_system@RGE_Base_Game@@MAEHXZ                 XREF[2]:     0056ef40(*), 00577218(*)
//                               RGE_Base_Game::setup_graphics_system
//                              basegame.cpp:2294 (30)
//         0041e920     MOV        EAX,FS:[0x0]
//         0041e926     PUSH       -0x1
//         0041e928     PUSH       FUN_0055ca7b
//         0041e92d     PUSH       EAX
//         0041e92e     MOV        dword ptr FS:[0x0],ESP
//         0041e935     SUB        ESP,0xc
//         0041e938     PUSH       EBX
//         0041e939     PUSH       EBP
//         0041e93a     PUSH       ESI
//         0041e93b     MOV        ESI,this
//         0041e93d     PUSH       EDI
//                              basegame.cpp:2300 (13)
//         0041e93e     MOV        EAX,dword ptr [ESI + 0xc]
//         0041e941     MOV        this,dword ptr [EAX + 0x89c]
//         0041e947     TEST       this,this
//         0041e949     JZ         LAB_0041e98a
//                              basegame.cpp:2302 (10)
//         0041e94b     PUSH       0x0
//         0041e94d     CALL       dword ptr [->USER32.DLL::GetDC]                  = 0048ae28
//         0041e953     MOV        EDI,EAX
//                              basegame.cpp:2303 (9)
//         0041e955     PUSH       0xc
//         0041e957     PUSH       EDI
//         0041e958     CALL       dword ptr [->GDI32.DLL::GetDeviceCaps]           = 0048b170
//                              basegame.cpp:2304 (11)
//         0041e95e     PUSH       EDI
//         0041e95f     PUSH       0x0
//         0041e961     MOV        EBX,EAX
//         0041e963     CALL       dword ptr [->USER32.DLL::ReleaseDC]              = 0048ae1c
//                              basegame.cpp:2305 (5)
//         0041e969     CMP        EBX,0x8
//         0041e96c     JGE        LAB_0041e98a
//                              basegame.cpp:2307 (7)
//         0041e96e     MOV        dword ptr [ESI + 0x40],0x13
//                              basegame.cpp:2308 (2)
//         0041e975     XOR        EAX,EAX
//                              basegame.cpp:2377 (19)
//         0041e977     MOV        this,dword ptr [ESP + 0x1c]
//         0041e97b     MOV        dword ptr FS:[0x0],this
//         0041e982     POP        EDI
//         0041e983     POP        ESI
//         0041e984     POP        EBP
//         0041e985     POP        EBX
//         0041e986     ADD        ESP,0x18
//         0041e989     RET
//                               LAB_0041e98a                                                 XREF[2]:     0041e949(j), 0041e96c(j)
//                              basegame.cpp:2313 (3)
//         0041e98a     MOV        EAX,dword ptr [ESI + 0xc]
//                              basegame.cpp:2328 (87)
//         0041e98d     PUSH       0x47c
//         0041e992     MOV        EDI,dword ptr [EAX + 0x89c]
//         0041e998     MOV        EBX,dword ptr [EAX + 0x8a0]
//         0041e99e     TEST       EDI,EDI
//         0041e9a0     SETNZ      this
//         0041e9a3     INC        this
//         0041e9a4     MOV        byte ptr [ESP + local_14],this
//         0041e9a8     MOV        this,dword ptr [EAX + 0x894]
//         0041e9ae     TEST       this,this
//         0041e9b0     SETNZ      DL
//         0041e9b3     INC        EDX
//         0041e9b4     XOR        this,this
//         0041e9b6     TEST       EBX,EBX
//         0041e9b8     SETNZ      this
//         0041e9bb     MOV        byte ptr [ESP + draw_type],DL
//         0041e9bf     MOV        EBP,this
//         0041e9c1     CALL       operator_new                                     void * operator_new(uint param_1)
//         0041e9c6     ADD        ESP,0x4
//         0041e9c9     MOV        dword ptr [ESP + 0x18],EAX
//         0041e9cd     TEST       EAX,EAX
//         0041e9cf     MOV        dword ptr [ESP + 0x24],0x0
//         0041e9d7     JZ         LAB_0041e9e2
//         0041e9d9     MOV        this,EAX
//         0041e9db     CALL       TDrawSystem::TDrawSystem                         undefined TDrawSystem(TDrawSystem * this)
//         0041e9e0     JMP        LAB_0041e9e4
//                               LAB_0041e9e2                                                 XREF[1]:     0041e9d7(j)
//         0041e9e2     XOR        EAX,EAX
//                               LAB_0041e9e4                                                 XREF[1]:     0041e9e0(j)
//                              basegame.cpp:2329 (15)
//         0041e9e4     TEST       EAX,EAX
//         0041e9e6     MOV        dword ptr [ESP + 0x24],0xffffffff
//         0041e9ee     MOV        dword ptr [ESI + 0x48],EAX
//         0041e9f1     JNZ        LAB_0041ea06
//                              basegame.cpp:2377 (19)
//         0041e9f3     MOV        this,dword ptr [ESP + 0x1c]
//         0041e9f7     MOV        dword ptr FS:[0x0],this
//         0041e9fe     POP        EDI
//         0041e9ff     POP        ESI
//         0041ea00     POP        EBP
//         0041ea01     POP        EBX
//         0041ea02     ADD        ESP,0x18
//         0041ea05     RET
//                               LAB_0041ea06                                                 XREF[1]:     0041e9f1(j)
//                              basegame.cpp:2333 (17)
//         0041ea06     MOV        EDX,dword ptr [ESI + 0xc]
//         0041ea09     MOV        this,dword ptr [EDX + 0x894]
//         0041ea0f     PUSH       this
//         0041ea10     MOV        this,EAX
//         0041ea12     CALL       TDrawSystem::CheckAvailModes                     void CheckAvailModes(TDrawSystem * this, int
//                              basegame.cpp:2334 (30)
//         0041ea17     MOV        EDX,dword ptr [ESI + 0xc]
//         0041ea1a     MOV        this,dword ptr [ESI + 0x48]
//         0041ea1d     PUSH       0x8
//         0041ea1f     PUSH       0x0
//         0041ea21     MOV        EAX,dword ptr [EDX + 0x8e0]
//         0041ea27     PUSH       EAX
//         0041ea28     CALL       TDrawSystem::IsModeAvail                         int IsModeAvail(TDrawSystem * this, long para
//         0041ea2d     TEST       EAX,EAX
//         0041ea2f     JNZ        LAB_0041eb16
//                              basegame.cpp:2337 (33)
//         0041ea35     MOV        this,dword ptr [ESI + 0xc]
//         0041ea38     MOV        EDI,0x280
//         0041ea3d     CMP        dword ptr [ECX + this+0x8e0],EDI
//         0041ea43     JZ         LAB_0041ea71
//         0041ea45     MOV        this,dword ptr [ESI + 0x48]
//         0041ea48     PUSH       0x8
//         0041ea4a     PUSH       0x0
//         0041ea4c     PUSH       EDI
//         0041ea4d     CALL       TDrawSystem::IsModeAvail                         int IsModeAvail(TDrawSystem * this, long para
//         0041ea52     TEST       EAX,EAX
//         0041ea54     JZ         LAB_0041ea71
//                              basegame.cpp:2339 (9)
//         0041ea56     MOV        EDX,dword ptr [ESI + 0xc]
//         0041ea59     MOV        dword ptr [EDX + 0x8e0],EDI
//                              basegame.cpp:2340 (13)
//         0041ea5f     MOV        EAX,dword ptr [ESI + 0xc]
//         0041ea62     MOV        dword ptr [EAX + 0x8e4],0x1e0
//                              basegame.cpp:2342 (38)
//         0041ea6c     JMP        LAB_0041eb16
//                               LAB_0041ea71                                                 XREF[2]:     0041ea43(j), 0041ea54(j)
//         0041ea71     MOV        this,dword ptr [ESI + 0xc]
//         0041ea74     MOV        EDI,0x320
//         0041ea79     CMP        dword ptr [ECX + this+0x8e0],EDI
//         0041ea7f     JZ         LAB_0041eaaa
//         0041ea81     MOV        this,dword ptr [ESI + 0x48]
//         0041ea84     PUSH       0x8
//         0041ea86     PUSH       0x0
//         0041ea88     PUSH       EDI
//         0041ea89     CALL       TDrawSystem::IsModeAvail                         int IsModeAvail(TDrawSystem * this, long para
//         0041ea8e     TEST       EAX,EAX
//         0041ea90     JZ         LAB_0041eaaa
//                              basegame.cpp:2344 (9)
//         0041ea92     MOV        EDX,dword ptr [ESI + 0xc]
//         0041ea95     MOV        dword ptr [EDX + 0x8e0],EDI
//                              basegame.cpp:2345 (13)
//         0041ea9b     MOV        EAX,dword ptr [ESI + 0xc]
//         0041ea9e     MOV        dword ptr [EAX + 0x8e4],0x258
//                              basegame.cpp:2347 (35)
//         0041eaa8     JMP        LAB_0041eb16
//                               LAB_0041eaaa                                                 XREF[2]:     0041ea7f(j), 0041ea90(j)
//         0041eaaa     MOV        this,dword ptr [ESI + 0xc]
//         0041eaad     MOV        EDI,0x400
//         0041eab2     CMP        dword ptr [ECX + this+0x8e0],EDI
//         0041eab8     JZ         LAB_0041eae3
//         0041eaba     MOV        this,dword ptr [ESI + 0x48]
//         0041eabd     PUSH       0x8
//         0041eabf     PUSH       0x0
//         0041eac1     PUSH       EDI
//         0041eac2     CALL       TDrawSystem::IsModeAvail                         int IsModeAvail(TDrawSystem * this, long para
//         0041eac7     TEST       EAX,EAX
//         0041eac9     JZ         LAB_0041eae3
//                              basegame.cpp:2349 (9)
//         0041eacb     MOV        EDX,dword ptr [ESI + 0xc]
//         0041eace     MOV        dword ptr [EDX + 0x8e0],EDI
//                              basegame.cpp:2350 (13)
//         0041ead4     MOV        EAX,dword ptr [ESI + 0xc]
//         0041ead7     MOV        dword ptr [EAX + 0x8e4],0x300
//                              basegame.cpp:2352 (35)
//         0041eae1     JMP        LAB_0041eb16
//                               LAB_0041eae3                                                 XREF[2]:     0041eab8(j), 0041eac9(j)
//         0041eae3     MOV        this,dword ptr [ESI + 0xc]
//         0041eae6     MOV        EBX,0x500
//         0041eaeb     CMP        dword ptr [ECX + this+0x8e0],EBX
//         0041eaf1     JZ         LAB_0041eb4d
//         0041eaf3     MOV        this,dword ptr [ESI + 0x48]
//         0041eaf6     PUSH       0x8
//         0041eaf8     PUSH       0x0
//         0041eafa     PUSH       EDI
//         0041eafb     CALL       TDrawSystem::IsModeAvail                         int IsModeAvail(TDrawSystem * this, long para
//         0041eb00     TEST       EAX,EAX
//         0041eb02     JZ         LAB_0041eb4d
//                              basegame.cpp:2354 (9)
//         0041eb04     MOV        EDX,dword ptr [ESI + 0xc]
//         0041eb07     MOV        dword ptr [EDX + 0x8e0],EBX
//                              basegame.cpp:2355 (9)
//         0041eb0d     MOV        EAX,dword ptr [ESI + 0xc]
//         0041eb10     MOV        dword ptr [EAX + 0x8e4],EDI
//                               LAB_0041eb16                                                 XREF[4]:     0041ea2f(j), 0041ea6c(j),
//                                                                                                         0041eaa8(j), 0041eae1(j)
//                              basegame.cpp:2364 (55)
//         0041eb16     MOV        EAX,dword ptr [ESI + 0xc]
//         0041eb19     PUSH       EBP
//         0041eb1a     MOV        this,dword ptr [EAX + 0x8e4]
//         0041eb20     MOV        EDX,dword ptr [EAX + 0x8e0]
//         0041eb26     MOV        EAX,dword ptr [EAX + 0x410]
//         0041eb2c     PUSH       this
//         0041eb2d     MOV        this,dword ptr [ESP + 0x18]
//         0041eb31     PUSH       EDX
//         0041eb32     MOV        EDX,dword ptr [ESP + 0x20]
//         0041eb36     PUSH       this
//         0041eb37     MOV        this,dword ptr [ESI + 0x1c]
//         0041eb3a     PUSH       EDX
//         0041eb3b     MOV        EDX,dword ptr [ESI + 0x10]
//         0041eb3e     PUSH       this
//         0041eb3f     MOV        this,dword ptr [ESI + 0x48]
//         0041eb42     PUSH       EDX
//         0041eb43     PUSH       EAX
//         0041eb44     CALL       TDrawSystem::Init                                int Init(TDrawSystem * this, void * param_1,
//         0041eb49     TEST       EAX,EAX
//         0041eb4b     JNZ        LAB_0041eb62
//                               LAB_0041eb4d                                                 XREF[2]:     0041eaf1(j), 0041eb02(j)
//                              basegame.cpp:2365 (2)
//         0041eb4d     XOR        EAX,EAX
//                              basegame.cpp:2377 (19)
//         0041eb4f     MOV        this,dword ptr [ESP + 0x1c]
//         0041eb53     MOV        dword ptr FS:[0x0],this
//         0041eb5a     POP        EDI
//         0041eb5b     POP        ESI
//         0041eb5c     POP        EBP
//         0041eb5d     POP        EBX
//         0041eb5e     ADD        ESP,0x18
//         0041eb61     RET
//                               LAB_0041eb62                                                 XREF[1]:     0041eb4b(j)
//                              basegame.cpp:2368 (14)
//         0041eb62     MOV        this,dword ptr [ESI + 0x1c]
//         0041eb65     PUSH       this
//         0041eb66     MOV        this,panel_system
//         0041eb6b     CALL       TPanelSystem::release_palette                    void release_palette(TPanelSystem * this, voi
//                              basegame.cpp:2369 (28)
//         0041eb70     MOV        EDX,dword ptr [ESI + 0xc]
//         0041eb73     PUSH       0xc544
//         0041eb78     ADD        EDX,0x66e
//         0041eb7e     MOV        this,panel_system
//         0041eb83     PUSH       EDX
//         0041eb84     CALL       TPanelSystem::get_palette                        void * get_palette(TPanelSystem * this, char
//         0041eb89     MOV        dword ptr [ESI + 0x1c],EAX
//                              basegame.cpp:2371 (3)
//         0041eb8c     MOV        EAX,dword ptr [ESI + 0x48]
//                              basegame.cpp:2373 (15)
//         0041eb8f     PUSH       0x0
//         0041eb91     PUSH       0x0
//         0041eb93     MOV        this,dword ptr [EAX + 0xc]
//         0041eb96     MOV        dword ptr [ESI + 0x4c],this
//         0041eb99     CALL       TDrawArea::Clear                                 void Clear(TDrawArea * this, tagRECT * param_
//                              basegame.cpp:2374 (10)
//         0041eb9e     MOV        this,dword ptr [ESI + 0x48]
//         0041eba1     PUSH       0x0
//         0041eba3     CALL       TDrawSystem::Paint                               void Paint(TDrawSystem * this, tagRECT * para
//                              basegame.cpp:2377 (24)
//         0041eba8     MOV        this,dword ptr [ESP + 0x1c]
//         0041ebac     POP        EDI
//         0041ebad     POP        ESI
//         0041ebae     POP        EBP
//         0041ebaf     MOV        EAX,0x1
//         0041ebb4     MOV        dword ptr FS:[0x0],this
//         0041ebbb     POP        EBX
//         0041ebbc     ADD        ESP,0x18
//         0041ebbf     RET
    return 0;
}

int RGE_Base_Game::setup_palette() {
    /* TODO: Stub */
//                              int __thiscall setup_palette(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?setup_palette@RGE_Base_Game@@MAEHXZ                         XREF[2]:     setup_palette:00522206(c),
//                               RGE_Base_Game::setup_palette                                              0056ef44(*)
//                              basegame.cpp:2383 (3)
//         0041ebc0     PUSH       ESI
//         0041ebc1     MOV        ESI,this
//                              basegame.cpp:2393 (24)
//         0041ebc3     PUSH       0xc544
//         0041ebc8     MOV        this,panel_system
//         0041ebcd     MOV        EAX,dword ptr [ESI + 0xc]
//         0041ebd0     ADD        EAX,0x66e
//         0041ebd5     PUSH       EAX
//         0041ebd6     CALL       TPanelSystem::get_palette                        void * get_palette(TPanelSystem * this, char
//                              basegame.cpp:2394 (12)
//         0041ebdb     XOR        this,this
//         0041ebdd     MOV        dword ptr [ESI + 0x1c],EAX
//         0041ebe0     TEST       EAX,EAX
//         0041ebe2     SETNZ      this
//         0041ebe5     MOV        EAX,this
//                              basegame.cpp:2398 (2)
//         0041ebe7     POP        ESI
//         0041ebe8     RET
//         0041ebe9     ??         90h
//         0041ebea     NOP
//         0041ebeb     NOP
//         0041ebec     NOP
//         0041ebed     NOP
//         0041ebee     NOP
//         0041ebef     NOP
    return 0;
}

int RGE_Base_Game::setup_mouse() {
    /* TODO: Stub */
//                              int __thiscall setup_mouse(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0041ec4e(W), 0041ec66(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     0041ec76(R), 0041ecab(R), 0041ecc3(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     0041ec48(W), 0041ecee(R)
//              int               Stack[-0x14]:4 custom_type
//                               ?setup_mouse@RGE_Base_Game@@MAEHXZ                           XREF[2]:     0056ef48(*), 00577220(*)
//                               RGE_Base_Game::setup_mouse
//                              basegame.cpp:2404 (26)
//         0041ebf0     PUSH       -0x1
//         0041ebf2     PUSH       FUN_0055ca9b
//         0041ebf7     MOV        EAX,FS:[0x0]
//         0041ebfd     PUSH       EAX
//         0041ebfe     MOV        dword ptr FS:[0x0],ESP
//         0041ec05     PUSH       this
//         0041ec06     PUSH       ESI
//         0041ec07     MOV        ESI,this
//         0041ec09     PUSH       EDI
//                              basegame.cpp:2407 (18)
//         0041ec0a     PUSH       s_Custom_Mouse                                   = "Custom Mouse"
//         0041ec0f     MOV        this,dword ptr [ESI + 0x1ac]
//         0041ec15     PUSH       0x0
//         0041ec17     CALL       TRegistry::RegGetInt                             int RegGetInt(TRegistry * this, int param_1,
//                              basegame.cpp:2409 (9)
//         0041ec1c     CMP        EAX,-0x1
//         0041ec1f     JNZ        LAB_0041ecd9
//                              basegame.cpp:2411 (20)
//         0041ec25     MOV        this,dword ptr [ESI + 0x1ac]
//         0041ec2b     PUSH       0x0
//         0041ec2d     PUSH       s_Custom_Mouse                                   = "Custom Mouse"
//         0041ec32     PUSH       0x0
//         0041ec34     CALL       TRegistry::RegSetInt                             int RegSetInt(TRegistry * this, int param_1,
//                               LAB_0041ec39                                                 XREF[1]:     0041ece8(j)
//                              basegame.cpp:2419 (2)
//         0041ec39     XOR        EDI,EDI
//                               LAB_0041ec3b                                                 XREF[2]:     0041ece0(j), 0041ecf9(j)
//                              basegame.cpp:2421 (41)
//         0041ec3b     PUSH       0x254
//         0041ec40     CALL       operator_new                                     void * operator_new(uint param_1)
//         0041ec45     ADD        ESP,0x4
//         0041ec48     MOV        dword ptr [ESP + local_10],EAX
//         0041ec4c     TEST       EAX,EAX
//         0041ec4e     MOV        dword ptr [ESP + local_4],0x0
//         0041ec56     JZ         LAB_0041ec62
//         0041ec58     PUSH       EDI
//         0041ec59     MOV        this,EAX
//         0041ec5b     CALL       TMousePointer::TMousePointer                     undefined TMousePointer(TMousePointer * this,
//         0041ec60     JMP        LAB_0041ec64
//                               LAB_0041ec62                                                 XREF[1]:     0041ec56(j)
//         0041ec62     XOR        EAX,EAX
//                               LAB_0041ec64                                                 XREF[1]:     0041ec60(j)
//                              basegame.cpp:2422 (18)
//         0041ec64     TEST       EAX,EAX
//         0041ec66     MOV        dword ptr [ESP + local_4],0xffffffff
//         0041ec6e     MOV        dword ptr [ESI + 0x1c0],EAX
//         0041ec74     JNZ        LAB_0041ec87
//                              basegame.cpp:2431 (17)
//         0041ec76     MOV        this,dword ptr [ESP + local_c]
//         0041ec7a     MOV        dword ptr FS:[0x0],this
//         0041ec81     POP        EDI
//         0041ec82     POP        ESI
//         0041ec83     ADD        ESP,0x10
//         0041ec86     RET
//                               LAB_0041ec87                                                 XREF[1]:     0041ec74(j)
//                              basegame.cpp:2425 (36)
//         0041ec87     MOV        this,dword ptr [ESI + 0xc]
//         0041ec8a     MOV        EDX,dword ptr [ESI + 0x4c]
//         0041ec8d     PUSH       0xa
//         0041ec8f     ADD        this,0x773
//         0041ec95     PUSH       0xc738
//         0041ec9a     PUSH       this
//         0041ec9b     MOV        this,dword ptr [ESI + 0x54]
//         0041ec9e     PUSH       EDX
//         0041ec9f     PUSH       this
//         0041eca0     MOV        this,EAX
//         0041eca2     CALL       TMousePointer::setup                             int setup(TMousePointer * this, int param_1,
//         0041eca7     TEST       EAX,EAX
//         0041eca9     JNZ        LAB_0041ecbc
//                              basegame.cpp:2431 (17)
//         0041ecab     MOV        this,dword ptr [ESP + local_c]
//         0041ecaf     MOV        dword ptr FS:[0x0],this
//         0041ecb6     POP        EDI
//         0041ecb7     POP        ESI
//         0041ecb8     ADD        ESP,0x10
//         0041ecbb     RET
//                               LAB_0041ecbc                                                 XREF[1]:     0041eca9(j)
//                              basegame.cpp:2428 (7)
//         0041ecbc     MOV        this,ESI
//         0041ecbe     CALL       RGE_Base_Game::mouse_off                         void mouse_off(RGE_Base_Game * this)
//                              basegame.cpp:2431 (22)
//         0041ecc3     MOV        this,dword ptr [ESP + local_c]
//         0041ecc7     POP        EDI
//         0041ecc8     MOV        EAX,0x1
//         0041eccd     MOV        dword ptr FS:[0x0],this
//         0041ecd4     POP        ESI
//         0041ecd5     ADD        ESP,0x10
//         0041ecd8     RET
//                               LAB_0041ecd9                                                 XREF[1]:     0041ec1f(j)
//                              basegame.cpp:2414 (5)
//         0041ecd9     CMP        EAX,0x1
//         0041ecdc     JNZ        LAB_0041ece5
//                              basegame.cpp:2415 (2)
//         0041ecde     MOV        EDI,EAX
//                              basegame.cpp:2416 (14)
//         0041ece0     JMP        LAB_0041ec3b
//                               LAB_0041ece5                                                 XREF[1]:     0041ecdc(j)
//         0041ece5     CMP        EAX,0x2
//         0041ece8     JNZ        LAB_0041ec39
//                              basegame.cpp:2418 (16)
//         0041ecee     MOV        EDI,dword ptr [ESP + local_10]
//         0041ecf2     MOV        dword ptr [ESI + 0x54],0x0
//         0041ecf9     JMP        LAB_0041ec3b
//         0041ecfe     ??         90h
//         0041ecff     NOP
    return 0;
}

int RGE_Base_Game::setup_chat() {
    /* TODO: Stub */
//                              int __thiscall setup_chat(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0041ed2c(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0041ed45(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0041ed26(W)
//                               ?setup_chat@RGE_Base_Game@@MAEHXZ                            XREF[2]:     0056ef54(*), 0057722c(*)
//                               RGE_Base_Game::setup_chat
//                              basegame.cpp:2437 (25)
//         0041ed00     PUSH       -0x1
//         0041ed02     PUSH       FUN_0055cabb
//         0041ed07     MOV        EAX,FS:[0x0]
//         0041ed0d     PUSH       EAX
//         0041ed0e     MOV        dword ptr FS:[0x0],ESP
//         0041ed15     PUSH       this
//         0041ed16     PUSH       ESI
//         0041ed17     MOV        ESI,this
//                              basegame.cpp:2439 (44)
//         0041ed19     PUSH       0x100
//         0041ed1e     CALL       operator_new                                     void * operator_new(uint param_1)
//         0041ed23     ADD        ESP,0x4
//         0041ed26     MOV        dword ptr [ESP + local_10],EAX
//         0041ed2a     TEST       EAX,EAX
//         0041ed2c     MOV        dword ptr [ESP + local_4],0x0
//         0041ed34     JZ         LAB_0041ed43
//         0041ed36     MOV        this,dword ptr [ESI + 0x10]
//         0041ed39     PUSH       this
//         0041ed3a     MOV        this,EAX
//         0041ed3c     CALL       TChat::TChat                                     undefined TChat(TChat * this, void * param_1)
//         0041ed41     JMP        LAB_0041ed45
//                               LAB_0041ed43                                                 XREF[1]:     0041ed34(j)
//         0041ed43     XOR        EAX,EAX
//                               LAB_0041ed45                                                 XREF[1]:     0041ed41(j)
//                              basegame.cpp:2444 (30)
//         0041ed45     MOV        this,dword ptr [ESP + local_c]
//         0041ed49     XOR        EDX,EDX
//         0041ed4b     TEST       EAX,EAX
//         0041ed4d     SETNZ      DL
//         0041ed50     MOV        [chat],EAX                                       = 00000000
//         0041ed55     MOV        EAX,EDX
//         0041ed57     MOV        dword ptr FS:[0x0],this
//         0041ed5e     POP        ESI
//         0041ed5f     ADD        ESP,0x10
//         0041ed62     RET
//         0041ed63     ??         90h
//         0041ed64     NOP
//         0041ed65     NOP
//         0041ed66     NOP
//         0041ed67     NOP
//         0041ed68     NOP
//         0041ed69     NOP
//         0041ed6a     NOP
//         0041ed6b     NOP
//         0041ed6c     NOP
//         0041ed6d     NOP
//         0041ed6e     NOP
//         0041ed6f     NOP
    return 0;
}

int RGE_Base_Game::setup_registry() {
    /* TODO: Stub */
//                              int __thiscall setup_registry(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0041ed9c(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0041edbb(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0041ed96(W)
//                               ?setup_registry@RGE_Base_Game@@MAEHXZ                        XREF[3]:     RGE_Base_Game:0041ba07(c),
//                               RGE_Base_Game::setup_registry                                             0056ef4c(*), 00577224(*)
//                              basegame.cpp:2451 (25)
//         0041ed70     PUSH       -0x1
//         0041ed72     PUSH       FUN_0055cadb
//         0041ed77     MOV        EAX,FS:[0x0]
//         0041ed7d     PUSH       EAX
//         0041ed7e     MOV        dword ptr FS:[0x0],ESP
//         0041ed85     PUSH       this
//         0041ed86     PUSH       ESI
//         0041ed87     MOV        ESI,this
//                              basegame.cpp:2453 (50)
//         0041ed89     PUSH       0x110
//         0041ed8e     CALL       operator_new                                     void * operator_new(uint param_1)
//         0041ed93     ADD        ESP,0x4
//         0041ed96     MOV        dword ptr [ESP + local_10],EAX
//         0041ed9a     TEST       EAX,EAX
//         0041ed9c     MOV        dword ptr [ESP + local_4],0x0
//         0041eda4     JZ         LAB_0041edb9
//         0041eda6     MOV        this,dword ptr [ESI + 0xc]
//         0041eda9     ADD        this,0x418
//         0041edaf     PUSH       this
//         0041edb0     MOV        this,EAX
//         0041edb2     CALL       TRegistry::TRegistry                             undefined TRegistry(TRegistry * this, char *
//         0041edb7     JMP        LAB_0041edbb
//                               LAB_0041edb9                                                 XREF[1]:     0041eda4(j)
//         0041edb9     XOR        EAX,EAX
//                               LAB_0041edbb                                                 XREF[1]:     0041edb7(j)
//                              basegame.cpp:2459 (31)
//         0041edbb     MOV        this,dword ptr [ESP + local_c]
//         0041edbf     XOR        EDX,EDX
//         0041edc1     TEST       EAX,EAX
//         0041edc3     SETNZ      DL
//         0041edc6     MOV        dword ptr [ESI + 0x1ac],EAX
//         0041edcc     MOV        EAX,EDX
//         0041edce     MOV        dword ptr FS:[0x0],this
//         0041edd5     POP        ESI
//         0041edd6     ADD        ESP,0x10
//         0041edd9     RET
//         0041edda     ??         90h
//         0041eddb     NOP
//         0041eddc     NOP
//         0041eddd     NOP
//         0041edde     NOP
//         0041eddf     NOP
    return 0;
}

int RGE_Base_Game::setup_debugging_log() {
    /* TODO: Stub */
//                              int __thiscall setup_debugging_log(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0041ee0c(W), 0041ee23(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0041ee33(R), 0041ee70(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0041ee06(W)
//                               ?setup_debugging_log@RGE_Base_Game@@MAEHXZ                   XREF[3]:     RGE_Base_Game:0041ba2d(c),
//                               RGE_Base_Game::setup_debugging_log                                        0056ef50(*), 00577228(*)
//                              basegame.cpp:2465 (25)
//         0041ede0     PUSH       -0x1
//         0041ede2     PUSH       FUN_0055cafb
//         0041ede7     MOV        EAX,FS:[0x0]
//         0041eded     PUSH       EAX
//         0041edee     MOV        dword ptr FS:[0x0],ESP
//         0041edf5     PUSH       this
//         0041edf6     PUSH       ESI
//         0041edf7     MOV        ESI,this
//                              basegame.cpp:2467 (40)
//         0041edf9     PUSH       0x7b0
//         0041edfe     CALL       operator_new                                     void * operator_new(uint param_1)
//         0041ee03     ADD        ESP,0x4
//         0041ee06     MOV        dword ptr [ESP + local_10],EAX
//         0041ee0a     TEST       EAX,EAX
//         0041ee0c     MOV        dword ptr [ESP + local_4],0x0
//         0041ee14     JZ         LAB_0041ee1f
//         0041ee16     MOV        this,EAX
//         0041ee18     CALL       TDebuggingLog::TDebuggingLog                     undefined TDebuggingLog(TDebuggingLog * this)
//         0041ee1d     JMP        LAB_0041ee21
//                               LAB_0041ee1f                                                 XREF[1]:     0041ee14(j)
//         0041ee1f     XOR        EAX,EAX
//                               LAB_0041ee21                                                 XREF[1]:     0041ee1d(j)
//                              basegame.cpp:2469 (18)
//         0041ee21     TEST       EAX,EAX
//         0041ee23     MOV        dword ptr [ESP + local_4],0xffffffff
//         0041ee2b     MOV        dword ptr [ESI + 0x1a4],EAX
//         0041ee31     JNZ        LAB_0041ee43
//                              basegame.cpp:2477 (16)
//         0041ee33     MOV        this,dword ptr [ESP + local_c]
//         0041ee37     MOV        dword ptr FS:[0x0],this
//         0041ee3e     POP        ESI
//         0041ee3f     ADD        ESP,0x10
//         0041ee42     RET
//                               LAB_0041ee43                                                 XREF[1]:     0041ee31(j)
//                              basegame.cpp:2472 (14)
//         0041ee43     MOV        this,dword ptr [ESI + 0x1a8]
//         0041ee49     PUSH       this
//         0041ee4a     MOV        this,EAX
//         0041ee4c     CALL       TDebuggingLog::LogFile                           void LogFile(TDebuggingLog * this, int param_1)
//                              basegame.cpp:2473 (18)
//         0041ee51     MOV        EDX,dword ptr [log_output]
//         0041ee57     MOV        this,dword ptr [ESI + 0x1a4]
//         0041ee5d     PUSH       EDX
//         0041ee5e     CALL       TDebuggingLog::LogOutput                         void LogOutput(TDebuggingLog * this, int para
//                              basegame.cpp:2474 (13)
//         0041ee63     MOV        this,dword ptr [ESI + 0x1a4]
//         0041ee69     PUSH       0x1
//         0041ee6b     CALL       TDebuggingLog::LogTimestamp                      void LogTimestamp(TDebuggingLog * this, int p
//                              basegame.cpp:2477 (21)
//         0041ee70     MOV        this,dword ptr [ESP + local_c]
//         0041ee74     MOV        EAX,0x1
//         0041ee79     MOV        dword ptr FS:[0x0],this
//         0041ee80     POP        ESI
//         0041ee81     ADD        ESP,0x10
//         0041ee84     RET
//         0041ee85     ??         90h
//         0041ee86     NOP
//         0041ee87     NOP
//         0041ee88     NOP
//         0041ee89     NOP
//         0041ee8a     NOP
//         0041ee8b     NOP
//         0041ee8c     NOP
//         0041ee8d     NOP
//         0041ee8e     NOP
//         0041ee8f     NOP
    return 0;
}

int RGE_Base_Game::setup_comm() {
    /* TODO: Stub */
//                              int __thiscall setup_comm(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0041eebe(W), 0041ef0b(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0041ef1b(R), 0041efcf(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0041eeb8(W)
//              undefined4        Stack[-0x20]:4 local_20                  XREF[1]:     0041eeef(W)
//              undefined4        Stack[-0x24]:4 local_24                  XREF[1]:     0041eee9(W)
//              undefined4        Stack[-0x28]:4 local_28                  XREF[1]:     0041eee3(W)
//              undefined4        Stack[-0x2c]:4 local_2c                  XREF[1]:     0041eede(*)
//                               ?setup_comm@RGE_Base_Game@@MAEHXZ                            XREF[2]:     0056ef58(*), 00577230(*)
//                               RGE_Base_Game::setup_comm
//                              basegame.cpp:2483 (27)
//         0041ee90     PUSH       -0x1
//         0041ee92     PUSH       FUN_0055cb1b
//         0041ee97     MOV        EAX,FS:[0x0]
//         0041ee9d     PUSH       EAX
//         0041ee9e     MOV        dword ptr FS:[0x0],ESP
//         0041eea5     PUSH       this
//         0041eea6     PUSH       EBX
//         0041eea7     PUSH       ESI
//         0041eea8     PUSH       EDI
//         0041eea9     MOV        ESI,this
//                              basegame.cpp:2485 (94)
//         0041eeab     PUSH       0x1774
//         0041eeb0     CALL       operator_new                                     void * operator_new(uint param_1)
//         0041eeb5     ADD        ESP,0x4
//         0041eeb8     MOV        dword ptr [ESP + local_10],EAX
//         0041eebc     TEST       EAX,EAX
//         0041eebe     MOV        dword ptr [ESP + local_4],0x0
//         0041eec6     JZ         LAB_0041ef07
//         0041eec8     MOV        EDX,dword ptr [ESI + 0xc]
//         0041eecb     SUB        ESP,0x10
//         0041eece     MOV        EDI,ESP
//         0041eed0     LEA        this,[EDX + 0x8e8]
//         0041eed6     MOV        DL,byte ptr [EDX + 0x878]
//         0041eedc     MOV        EBX,dword ptr [this->_padding_]
//         0041eede     MOV        dword ptr [EDI]=>local_2c,EBX
//         0041eee0     MOV        EBX,dword ptr [ECX + this->player_game_info]
//         0041eee3     MOV        dword ptr [EDI + local_28],EBX
//         0041eee6     MOV        EBX,dword ptr [ECX + this->scenario_info]
//         0041eee9     MOV        dword ptr [EDI + local_24],EBX
//         0041eeec     MOV        this,dword ptr [ECX + this->prog_info]
//         0041eeef     MOV        dword ptr [EDI + local_20],this
//         0041eef2     MOV        this,dword ptr [chat]                            = 00000000
//         0041eef8     PUSH       this
//         0041eef9     MOV        this,dword ptr [ESI + 0x10]
//         0041eefc     PUSH       EDX
//         0041eefd     PUSH       this
//         0041eefe     MOV        this,EAX
//         0041ef00     CALL       TCommunications_Handler::TCommunications_Handler undefined TCommunications_Handler(TCommunicat
//         0041ef05     JMP        LAB_0041ef09
//                               LAB_0041ef07                                                 XREF[1]:     0041eec6(j)
//         0041ef07     XOR        EAX,EAX
//                               LAB_0041ef09                                                 XREF[1]:     0041ef05(j)
//                              basegame.cpp:2486 (18)
//         0041ef09     TEST       EAX,EAX
//         0041ef0b     MOV        dword ptr [ESP + local_4],0xffffffff
//         0041ef13     MOV        dword ptr [ESI + 0x18c],EAX
//         0041ef19     JNZ        LAB_0041ef2d
//                              basegame.cpp:2506 (18)
//         0041ef1b     MOV        this,dword ptr [ESP + local_c]
//         0041ef1f     MOV        dword ptr FS:[0x0],this
//         0041ef26     POP        EDI
//         0041ef27     POP        ESI
//         0041ef28     POP        EBX
//         0041ef29     ADD        ESP,0x10
//         0041ef2c     RET
//                               LAB_0041ef2d                                                 XREF[1]:     0041ef19(j)
//                              basegame.cpp:2489 (14)
//         0041ef2d     MOV        EDX,dword ptr [ESI + 0x190]
//         0041ef33     MOV        this,EAX
//         0041ef35     PUSH       EDX
//         0041ef36     CALL       TCommunications_Handler::StopIfSyncFail          void StopIfSyncFail(TCommunications_Handler *
//                              basegame.cpp:2490 (18)
//         0041ef3b     MOV        EAX,dword ptr [ESI + 0x198]
//         0041ef41     MOV        this,dword ptr [ESI + 0x18c]
//         0041ef47     PUSH       EAX
//         0041ef48     CALL       TCommunications_Handler::ShowSyncChatMsgs        void ShowSyncChatMsgs(TCommunications_Handler
//                              basegame.cpp:2491 (18)
//         0041ef4d     MOV        this,dword ptr [ESI + 0x19c]
//         0041ef53     PUSH       this
//         0041ef54     MOV        this,dword ptr [ESI + 0x18c]
//         0041ef5a     CALL       TCommunications_Handler::SetStepMode             void SetStepMode(TCommunications_Handler * th
//                              basegame.cpp:2492 (18)
//         0041ef5f     MOV        EDX,dword ptr [ESI + 0x1a0]
//         0041ef65     MOV        this,dword ptr [ESI + 0x18c]
//         0041ef6b     PUSH       EDX
//         0041ef6c     CALL       TCommunications_Handler::SetSpeedControl         void SetSpeedControl(TCommunications_Handler
//                              basegame.cpp:2493 (18)
//         0041ef71     MOV        EAX,dword ptr [ESI + 0x194]
//         0041ef77     MOV        this,dword ptr [ESI + 0x18c]
//         0041ef7d     PUSH       EAX
//         0041ef7e     CALL       TCommunications_Handler::DropPacketsIntentiona   void DropPacketsIntentionally(TCommunications
//                              basegame.cpp:2494 (12)
//         0041ef83     MOV        this,dword ptr [ESI + 0x18c]
//         0041ef89     MOV        dword ptr [comm],this                            = 00000000
//                              basegame.cpp:2496 (10)
//         0041ef8f     MOV        this,dword ptr [ESI + 0x3f4]
//         0041ef95     TEST       this,this
//         0041ef97     JZ         LAB_0041efa5
//                              basegame.cpp:2497 (12)
//         0041ef99     MOV        EDX,dword ptr [ESI + 0x18c]
//         0041ef9f     PUSH       EDX
//         0041efa0     CALL       RGE_Game_World::reset_communications             void reset_communications(RGE_Game_World * th
//                               LAB_0041efa5                                                 XREF[1]:     0041ef97(j)
//                              basegame.cpp:2499 (9)
//         0041efa5     MOV        EAX,[speed_val1]
//         0041efaa     TEST       EAX,EAX
//         0041efac     JZ         LAB_0041efba
//                              basegame.cpp:2500 (12)
//         0041efae     MOV        this,dword ptr [ESI + 0x18c]
//         0041efb4     PUSH       EAX
//         0041efb5     CALL       TCommunications_Handler::SetSpeedV1              void SetSpeedV1(TCommunications_Handler * thi
//                               LAB_0041efba                                                 XREF[1]:     0041efac(j)
//                              basegame.cpp:2502 (9)
//         0041efba     MOV        EAX,[speed_val2]
//         0041efbf     TEST       EAX,EAX
//         0041efc1     JZ         LAB_0041efcf
//                              basegame.cpp:2503 (12)
//         0041efc3     MOV        this,dword ptr [ESI + 0x18c]
//         0041efc9     PUSH       EAX
//         0041efca     CALL       TCommunications_Handler::SetSpeedV1              void SetSpeedV1(TCommunications_Handler * thi
//                               LAB_0041efcf                                                 XREF[1]:     0041efc1(j)
//                              basegame.cpp:2506 (23)
//         0041efcf     MOV        this,dword ptr [ESP + local_c]
//         0041efd3     POP        EDI
//         0041efd4     POP        ESI
//         0041efd5     MOV        EAX,0x1
//         0041efda     MOV        dword ptr FS:[0x0],this
//         0041efe1     POP        EBX
//         0041efe2     ADD        ESP,0x10
//         0041efe5     RET
//         0041efe6     ??         90h
//         0041efe7     NOP
//         0041efe8     NOP
//         0041efe9     NOP
//         0041efea     NOP
//         0041efeb     NOP
//         0041efec     NOP
//         0041efed     NOP
//         0041efee     NOP
//         0041efef     NOP
    return 0;
}

int RGE_Base_Game::reset_comm() {
    /* TODO: Stub */
//                              int __thiscall reset_comm(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?reset_comm@RGE_Base_Game@@UAEHXZ                            XREF[2]:     0056ef14(*), 005771ec(*)
//                               RGE_Base_Game::reset_comm
//                              basegame.cpp:2512 (4)
//         0041eff0     PUSH       ESI
//         0041eff1     PUSH       EDI
//         0041eff2     MOV        EDI,this
//                              basegame.cpp:2513 (10)
//         0041eff4     MOV        ESI,dword ptr [EDI + 0x18c]
//         0041effa     TEST       ESI,ESI
//         0041effc     JZ         LAB_0041f022
//                              basegame.cpp:2515 (13)
//         0041effe     MOV        this,ESI
//         0041f000     CALL       TCommunications_Handler::~TCommunications_Hand   void ~TCommunications_Handler(TCommunications
//         0041f005     PUSH       ESI
//         0041f006     CALL       operator_delete                                  void operator_delete(void * param_1)
//                              basegame.cpp:2516 (13)
//         0041f00b     MOV        dword ptr [EDI + 0x18c],0x0
//         0041f015     ADD        ESP,0x4
//                              basegame.cpp:2517 (10)
//         0041f018     MOV        dword ptr [comm],0x0                             = 00000000
//                               LAB_0041f022                                                 XREF[1]:     0041effc(j)
//                              basegame.cpp:2520 (10)
//         0041f022     MOV        EAX,dword ptr [EDI]
//         0041f024     MOV        this,EDI
//         0041f026     CALL       dword ptr [EAX + 0x88]
//                              basegame.cpp:2521 (3)
//         0041f02c     POP        EDI
//         0041f02d     POP        ESI
//         0041f02e     RET
//         0041f02f     ??         90h
    return 0;
}

int RGE_Base_Game::setup_sound_system() {
    /* TODO: Stub */
//                              int __thiscall setup_sound_system(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0041f06f(W), 0041f090(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0041f0f9(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0041f069(W)
//                               ?setup_sound_system@RGE_Base_Game@@MAEHXZ                    XREF[2]:     0056ef5c(*), 00577234(*)
//                               RGE_Base_Game::setup_sound_system
//                              basegame.cpp:2527 (27)
//         0041f030     PUSH       -0x1
//         0041f032     PUSH       FUN_0055cb3b
//         0041f037     MOV        EAX,FS:[0x0]
//         0041f03d     PUSH       EAX
//         0041f03e     MOV        dword ptr FS:[0x0],ESP
//         0041f045     PUSH       this
//         0041f046     PUSH       EBX
//         0041f047     PUSH       ESI
//         0041f048     MOV        ESI,this
//         0041f04a     PUSH       EDI
//                              basegame.cpp:2529 (17)
//         0041f04b     XOR        EDI,EDI
//         0041f04d     MOV        EAX,dword ptr [ESI + 0xc]
//         0041f050     CMP        dword ptr [EAX + 0x8a8],EDI
//         0041f056     JZ         LAB_0041f0f2
//                              basegame.cpp:2531 (50)
//         0041f05c     PUSH       0x69c
//         0041f061     CALL       operator_new                                     void * operator_new(uint param_1)
//         0041f066     ADD        ESP,0x4
//         0041f069     MOV        dword ptr [ESP + local_10],EAX
//         0041f06d     CMP        EAX,EDI
//         0041f06f     MOV        dword ptr [ESP + local_4],EDI
//         0041f073     JZ         LAB_0041f08c
//         0041f075     MOV        this,dword ptr [ESI + 0xc]
//         0041f078     MOV        EDX,dword ptr [ESI + 0x10]
//         0041f07b     ADD        this,0xe21
//         0041f081     PUSH       this
//         0041f082     PUSH       EDX
//         0041f083     MOV        this,EAX
//         0041f085     CALL       TSound_Driver::TSound_Driver                     undefined TSound_Driver(TSound_Driver * this,
//         0041f08a     JMP        LAB_0041f08e
//                               LAB_0041f08c                                                 XREF[1]:     0041f073(j)
//         0041f08c     XOR        EAX,EAX
//                               LAB_0041f08e                                                 XREF[1]:     0041f08a(j)
//                              basegame.cpp:2532 (26)
//         0041f08e     CMP        EAX,EDI
//         0041f090     MOV        dword ptr [ESP + local_4],0xffffffff
//         0041f098     MOV        dword ptr [ESI + 0x60],EAX
//         0041f09b     JZ         LAB_0041f0c4
//         0041f09d     MOV        this,EAX
//         0041f09f     CALL       TSound_Driver::driver_active                     int driver_active(TSound_Driver * this)
//         0041f0a4     TEST       EAX,EAX
//         0041f0a6     JNZ        LAB_0041f0c4
//                              basegame.cpp:2534 (23)
//         0041f0a8     MOV        EBX,dword ptr [ESI + 0x60]
//         0041f0ab     CMP        EBX,EDI
//         0041f0ad     JZ         LAB_0041f0bf
//         0041f0af     MOV        this,EBX
//         0041f0b1     CALL       TSound_Driver::~TSound_Driver                    void ~TSound_Driver(TSound_Driver * this)
//         0041f0b6     PUSH       EBX
//         0041f0b7     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0041f0bc     ADD        ESP,0x4
//                               LAB_0041f0bf                                                 XREF[1]:     0041f0ad(j)
//                              basegame.cpp:2535 (3)
//         0041f0bf     MOV        dword ptr [ESI + 0x60],EDI
//                              basegame.cpp:2538 (2)
//         0041f0c2     JMP        LAB_0041f0f9
//                               LAB_0041f0c4                                                 XREF[2]:     0041f09b(j), 0041f0a6(j)
//                              basegame.cpp:2540 (3)
//         0041f0c4     MOV        EAX,dword ptr [ESI + 0x60]
//                              basegame.cpp:2543 (23)
//         0041f0c7     PUSH       s_Sound_Volume                                   = "Sound Volume"
//         0041f0cc     MOV        [sound_driver],EAX                               = 00000000
//         0041f0d1     MOV        this,dword ptr [ESI + 0x1ac]
//         0041f0d7     PUSH       0x1
//         0041f0d9     CALL       TRegistry::RegGetInt                             int RegGetInt(TRegistry * this, int param_1,
//                              basegame.cpp:2544 (5)
//         0041f0de     CMP        EAX,-0x1
//         0041f0e1     JZ         LAB_0041f0e7
//                              basegame.cpp:2545 (4)
//         0041f0e3     NEG        EAX
//         0041f0e5     MOV        EDI,EAX
//                               LAB_0041f0e7                                                 XREF[1]:     0041f0e1(j)
//                              basegame.cpp:2546 (11)
//         0041f0e7     MOV        this,dword ptr [ESI + 0x60]
//         0041f0ea     PUSH       0x1
//         0041f0ec     PUSH       EDI
//         0041f0ed     CALL       TSound_Driver::set_volume                        void set_volume(TSound_Driver * this, long pa
//                               LAB_0041f0f2                                                 XREF[1]:     0041f056(j)
//                              basegame.cpp:2549 (7)
//         0041f0f2     MOV        EDX,dword ptr [ESI]
//         0041f0f4     MOV        this,ESI
//         0041f0f6     CALL       dword ptr [EDX + 0x58]
//                               LAB_0041f0f9                                                 XREF[1]:     0041f0c2(j)
//                              basegame.cpp:2552 (23)
//         0041f0f9     MOV        this,dword ptr [ESP + local_c]
//         0041f0fd     POP        EDI
//         0041f0fe     POP        ESI
//         0041f0ff     MOV        EAX,0x1
//         0041f104     MOV        dword ptr FS:[0x0],this
//         0041f10b     POP        EBX
//         0041f10c     ADD        ESP,0x10
//         0041f10f     RET
    return 0;
}

int RGE_Base_Game::setup_music_system() {
    /* TODO: Stub */
//                              int __thiscall setup_music_system(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0041f21a(W), 0041f250(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0041f2ad(R)
//              char[260]         Stack[-0x114   music_path                XREF[1,2]:   0041f214(W), 0041f1f1(*), 0041f22a(*)
//              undefined4        Stack[-0x118   local_118                 XREF[2]:     0041f1fb(W), 0041f23d(R)
//              uchar             Stack[-0x11c   music_type
//                               ?setup_music_system@RGE_Base_Game@@UAEHXZ                    XREF[2]:     0056ef28(*), 00577200(*)
//                               RGE_Base_Game::setup_music_system
//                              basegame.cpp:2558 (32)
//         0041f110     MOV        EAX,FS:[0x0]
//         0041f116     PUSH       -0x1
//         0041f118     PUSH       FUN_0055cb5e
//         0041f11d     PUSH       EAX
//         0041f11e     MOV        dword ptr FS:[0x0],ESP
//         0041f125     SUB        ESP,0x10c
//         0041f12b     PUSH       EBX
//         0041f12c     PUSH       ESI
//         0041f12d     MOV        ESI,this
//         0041f12f     PUSH       EDI
//                              basegame.cpp:2562 (17)
//         0041f130     MOV        EAX,dword ptr [ESI + 0xc]
//         0041f133     MOV        this,dword ptr [EAX + 0x8a4]
//         0041f139     TEST       this,this
//         0041f13b     JZ         LAB_0041f2ad
//                              basegame.cpp:2565 (23)
//         0041f141     MOV        this,dword ptr [ESI + 0x1ac]
//         0041f147     PUSH       s_Music_Volume                                   = "Music Volume"
//         0041f14c     PUSH       0x1
//         0041f14e     MOV        EDI,0xffffec78
//         0041f153     CALL       TRegistry::RegGetInt                             int RegGetInt(TRegistry * this, int param_1,
//                              basegame.cpp:2566 (5)
//         0041f158     CMP        EAX,-0x1
//         0041f15b     JZ         LAB_0041f161
//                              basegame.cpp:2567 (4)
//         0041f15d     NEG        EAX
//         0041f15f     MOV        EDI,EAX
//                               LAB_0041f161                                                 XREF[1]:     0041f15b(j)
//                              basegame.cpp:2569 (8)
//         0041f161     CMP        EDI,0xffffd954
//         0041f167     JG         LAB_0041f19d
//                              basegame.cpp:2571 (13)
//         0041f169     MOV        this,dword ptr [ESI + 0xc]
//         0041f16c     MOV        dword ptr [ECX + this+0x8a4],0x0
//                              basegame.cpp:2573 (11)
//         0041f176     MOV        EDI,dword ptr [ESI + 0x64]
//         0041f179     TEST       EDI,EDI
//         0041f17b     JZ         LAB_0041f2ad
//                              basegame.cpp:2575 (16)
//         0041f181     MOV        this,EDI
//         0041f183     CALL       TMusic_System::~TMusic_System                    void ~TMusic_System(TMusic_System * this)
//         0041f188     PUSH       EDI
//         0041f189     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0041f18e     ADD        ESP,0x4
//                              basegame.cpp:2576 (7)
//         0041f191     MOV        dword ptr [ESI + 0x64],0x0
//                              basegame.cpp:2579 (5)
//         0041f198     JMP        LAB_0041f2ad
//                               LAB_0041f19d                                                 XREF[1]:     0041f167(j)
//                              basegame.cpp:2582 (5)
//         0041f19d     MOV        EAX,dword ptr [ESI + 0x64]
//         0041f1a0     TEST       EAX,EAX
//                              basegame.cpp:2583 (6)
//         0041f1a2     JNZ        LAB_0041f2ad
//                              basegame.cpp:2585 (13)
//         0041f1a8     MOV        EAX,dword ptr [ESI + 0xc]
//         0041f1ab     MOV        this,dword ptr [EAX + 0x8ac]
//         0041f1b1     TEST       this,this
//         0041f1b3     JZ         LAB_0041f1b9
//                              basegame.cpp:2586 (2)
//         0041f1b5     MOV        BL,0x1
//                              basegame.cpp:2587 (12)
//         0041f1b7     JMP        LAB_0041f1e4
//                               LAB_0041f1b9                                                 XREF[1]:     0041f1b3(j)
//         0041f1b9     MOV        this,dword ptr [EAX + 0x8b4]
//         0041f1bf     TEST       this,this
//         0041f1c1     JZ         LAB_0041f1c7
//                              basegame.cpp:2588 (2)
//         0041f1c3     MOV        BL,0x2
//                              basegame.cpp:2589 (12)
//         0041f1c5     JMP        LAB_0041f1e4
//                               LAB_0041f1c7                                                 XREF[1]:     0041f1c1(j)
//         0041f1c7     MOV        this,dword ptr [EAX + 0x8b0]
//         0041f1cd     TEST       this,this
//         0041f1cf     JZ         LAB_0041f1d5
//                              basegame.cpp:2590 (2)
//         0041f1d1     MOV        BL,0x4
//                              basegame.cpp:2591 (17)
//         0041f1d3     JMP        LAB_0041f1e4
//                               LAB_0041f1d5                                                 XREF[1]:     0041f1cf(j)
//         0041f1d5     MOV        EBX,dword ptr [EAX + 0x8b8]
//         0041f1db     NEG        EBX
//         0041f1dd     SBB        BL,BL
//         0041f1df     AND        BL,0x2
//         0041f1e2     INC        BL
//                               LAB_0041f1e4                                                 XREF[3]:     0041f1b7(j), 0041f1c5(j),
//                                                                                                         0041f1d3(j)
//                              basegame.cpp:2601 (35)
//         0041f1e4     ADD        EAX,0xe21
//         0041f1e9     LEA        EDX,[ESI + 0x1e8]
//         0041f1ef     PUSH       EAX
//         0041f1f0     PUSH       EDX
//         0041f1f1     LEA        EAX=>music_path[4],[ESP + 0x1c]
//         0041f1f5     PUSH       s_%s\%s                                          = "%s\\%s"
//         0041f1fa     PUSH       EAX
//         0041f1fb     MOV        byte ptr [ESP + local_118],BL
//         0041f1ff     CALL       sprintf                                          undefined sprintf()
//         0041f204     ADD        ESP,0x10
//                              basegame.cpp:2602 (71)
//         0041f207     PUSH       0x3f8
//         0041f20c     CALL       operator_new                                     void * operator_new(uint param_1)
//         0041f211     ADD        ESP,0x4
//         0041f214     MOV        dword ptr [ESP + music_path[0]],EAX
//         0041f218     TEST       EAX,EAX
//         0041f21a     MOV        dword ptr [ESP + local_4],0x0
//         0041f225     JZ         LAB_0041f24c
//         0041f227     MOV        EDX,dword ptr [ESI + 0x60]
//         0041f22a     LEA        this=>music_path[4],[ESP + 0x14]
//         0041f22e     PUSH       this
//         0041f22f     MOV        this,dword ptr [ESI + 0x10]
//         0041f232     PUSH       EDX
//         0041f233     MOV        EDX,dword ptr [ESI + 0xc]
//         0041f236     PUSH       this
//         0041f237     MOV        this,dword ptr [EDX + 0x410]
//         0041f23d     MOV        EDX,dword ptr [ESP + local_118]
//         0041f241     PUSH       this
//         0041f242     PUSH       EDX
//         0041f243     MOV        this,EAX
//         0041f245     CALL       TMusic_System::TMusic_System                     undefined TMusic_System(TMusic_System * this,
//         0041f24a     JMP        LAB_0041f24e
//                               LAB_0041f24c                                                 XREF[1]:     0041f225(j)
//         0041f24c     XOR        EAX,EAX
//                               LAB_0041f24e                                                 XREF[1]:     0041f24a(j)
//                              basegame.cpp:2607 (36)
//         0041f24e     TEST       EAX,EAX
//         0041f250     MOV        dword ptr [ESP + local_4],0xffffffff
//         0041f25b     MOV        dword ptr [ESI + 0x64],EAX
//         0041f25e     JZ         LAB_0041f29c
//         0041f260     CMP        BL,0x1
//         0041f263     JNZ        LAB_0041f29c
//         0041f265     MOV        this,dword ptr [ESI + 0xc]
//         0041f268     MOV        EDX,dword ptr [ECX + this+0x8ac]
//         0041f26e     TEST       EDX,EDX
//         0041f270     JNZ        LAB_0041f29c
//                              basegame.cpp:2609 (19)
//         0041f272     MOV        this,dword ptr [EAX + 0x114]
//         0041f278     TEST       this,this
//         0041f27a     JZ         LAB_0041f285
//         0041f27c     CMP        dword ptr [EAX + 0x248],0x2
//         0041f283     JGE        LAB_0041f29c
//                               LAB_0041f285                                                 XREF[1]:     0041f27a(j)
//                              basegame.cpp:2611 (13)
//         0041f285     PUSH       0x2
//         0041f287     MOV        this,EAX
//         0041f289     CALL       TMusic_System::set_music_type                    int set_music_type(TMusic_System * this, ucha
//         0041f28e     TEST       EAX,EAX
//         0041f290     JNZ        LAB_0041f29c
//                              basegame.cpp:2614 (10)
//         0041f292     MOV        this,dword ptr [ESI + 0x64]
//         0041f295     PUSH       0x3
//         0041f297     CALL       TMusic_System::set_music_type                    int set_music_type(TMusic_System * this, ucha
//                               LAB_0041f29c                                                 XREF[5]:     0041f25e(j), 0041f263(j),
//                                                                                                         0041f270(j), 0041f283(j),
//                                                                                                         0041f290(j)
//                              basegame.cpp:2619 (7)
//         0041f29c     MOV        ESI,dword ptr [ESI + 0x64]
//         0041f29f     TEST       ESI,ESI
//         0041f2a1     JZ         LAB_0041f2ad
//                              basegame.cpp:2620 (10)
//         0041f2a3     PUSH       0x1
//         0041f2a5     PUSH       EDI
//         0041f2a6     MOV        this,ESI
//         0041f2a8     CALL       TMusic_System::set_volume                        void set_volume(TMusic_System * this, long pa
//                               LAB_0041f2ad                                                 XREF[5]:     0041f13b(j), 0041f17b(j),
//                                                                                                         0041f198(j), 0041f1a2(j),
//                                                                                                         0041f2a1(j)
//                              basegame.cpp:2624 (29)
//         0041f2ad     MOV        this,dword ptr [ESP + local_c]
//         0041f2b4     POP        EDI
//         0041f2b5     POP        ESI
//         0041f2b6     MOV        EAX,0x1
//         0041f2bb     MOV        dword ptr FS:[0x0],this
//         0041f2c2     POP        EBX
//         0041f2c3     ADD        ESP,0x118
//         0041f2c9     RET
//         0041f2ca     ??         90h
//         0041f2cb     NOP
//         0041f2cc     NOP
//         0041f2cd     NOP
//         0041f2ce     NOP
//         0041f2cf     NOP
    return 0;
}

int RGE_Base_Game::setup_shapes() {
    /* TODO: Stub */
//                              int __thiscall setup_shapes(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[5]:     0041f33e(W), 0041f362(W), 0041f37a(W), 0041f39e(W),
//                                                                                     0041f3b7(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0041f302(R), 0041f3dd(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[3]:     0041f338(W), 0041f374(W), 0041f3b1(W)
//                               ?setup_shapes@RGE_Base_Game@@MAEHXZ                          XREF[2]:     0056ef68(*), 00577240(*)
//                               RGE_Base_Game::setup_shapes
//                              basegame.cpp:2630 (25)
//         0041f2d0     PUSH       -0x1
//         0041f2d2     PUSH       FUN_0055cb91
//         0041f2d7     MOV        EAX,FS:[0x0]
//         0041f2dd     PUSH       EAX
//         0041f2de     MOV        dword ptr FS:[0x0],ESP
//         0041f2e5     PUSH       this
//         0041f2e6     PUSH       ESI
//         0041f2e7     MOV        ESI,this
//                              basegame.cpp:2635 (21)
//         0041f2e9     PUSH       0x4
//         0041f2eb     PUSH       0x3
//         0041f2ed     MOV        word ptr [ESI + 0x58],0x3
//         0041f2f3     CALL       calloc                                           undefined calloc()
//         0041f2f8     ADD        ESP,0x8
//         0041f2fb     MOV        dword ptr [ESI + 0x5c],EAX
//                              basegame.cpp:2636 (4)
//         0041f2fe     TEST       EAX,EAX
//         0041f300     JNZ        LAB_0041f312
//                              basegame.cpp:2647 (16)
//         0041f302     MOV        this,dword ptr [ESP + local_c]
//         0041f306     MOV        dword ptr FS:[0x0],this
//         0041f30d     POP        ESI
//         0041f30e     ADD        ESP,0x10
//         0041f311     RET
//                               LAB_0041f312                                                 XREF[1]:     0041f300(j)
//                              basegame.cpp:2639 (8)
//         0041f312     XOR        EAX,EAX
//         0041f314     CMP        word ptr [ESI + 0x58],AX
//         0041f318     JLE        LAB_0041f32e
//                               LAB_0041f31a                                                 XREF[1]:     0041f32c(j)
//                              basegame.cpp:2640 (20)
//         0041f31a     MOV        this,dword ptr [ESI + 0x5c]
//         0041f31d     INC        EAX
//         0041f31e     MOV        dword ptr [this->_padding_ + EAX*0x4 + -0x4],0x0
//         0041f326     MOVSX      EDX,word ptr [ESI + 0x58]
//         0041f32a     CMP        EAX,EDX
//         0041f32c     JL         LAB_0041f31a
//                               LAB_0041f32e                                                 XREF[1]:     0041f318(j)
//                              basegame.cpp:2642 (50)
//         0041f32e     PUSH       0x20
//         0041f330     CALL       operator_new                                     void * operator_new(uint param_1)
//         0041f335     ADD        ESP,0x4
//         0041f338     MOV        dword ptr [ESP + local_10],EAX
//         0041f33c     TEST       EAX,EAX
//         0041f33e     MOV        dword ptr [ESP + local_4],0x0
//         0041f346     JZ         LAB_0041f35b
//         0041f348     PUSH       0xc4e3
//         0041f34d     PUSH       s_groupnum.shp                                   = "groupnum.shp"
//         0041f352     MOV        this,EAX
//         0041f354     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
//         0041f359     JMP        LAB_0041f35d
//                               LAB_0041f35b                                                 XREF[1]:     0041f346(j)
//         0041f35b     XOR        EAX,EAX
//                               LAB_0041f35d                                                 XREF[1]:     0041f359(j)
//         0041f35d     MOV        this,dword ptr [ESI + 0x5c]
//                              basegame.cpp:2643 (60)
//         0041f360     PUSH       0x20
//         0041f362     MOV        dword ptr [ESP + local_4],0xffffffff
//         0041f36a     MOV        dword ptr [this->_padding_],EAX
//         0041f36c     CALL       operator_new                                     void * operator_new(uint param_1)
//         0041f371     ADD        ESP,0x4
//         0041f374     MOV        dword ptr [ESP + local_10],EAX
//         0041f378     TEST       EAX,EAX
//         0041f37a     MOV        dword ptr [ESP + local_4],0x1
//         0041f382     JZ         LAB_0041f397
//         0041f384     PUSH       0xc4e4
//         0041f389     PUSH       s_waypoint.shp                                   = "waypoint.shp"
//         0041f38e     MOV        this,EAX
//         0041f390     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
//         0041f395     JMP        LAB_0041f399
//                               LAB_0041f397                                                 XREF[1]:     0041f382(j)
//         0041f397     XOR        EAX,EAX
//                               LAB_0041f399                                                 XREF[1]:     0041f395(j)
//         0041f399     MOV        EDX,dword ptr [ESI + 0x5c]
//                              basegame.cpp:2644 (61)
//         0041f39c     PUSH       0x20
//         0041f39e     MOV        dword ptr [ESP + local_4],0xffffffff
//         0041f3a6     MOV        dword ptr [EDX + 0x4],EAX
//         0041f3a9     CALL       operator_new                                     void * operator_new(uint param_1)
//         0041f3ae     ADD        ESP,0x4
//         0041f3b1     MOV        dword ptr [ESP + local_10],EAX
//         0041f3b5     TEST       EAX,EAX
//         0041f3b7     MOV        dword ptr [ESP + local_4],0x2
//         0041f3bf     JZ         LAB_0041f3d4
//         0041f3c1     PUSH       0xc4e5
//         0041f3c6     PUSH       s_moveto.shp                                     = "moveto.shp"
//         0041f3cb     MOV        this,EAX
//         0041f3cd     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
//         0041f3d2     JMP        LAB_0041f3d6
//                               LAB_0041f3d4                                                 XREF[1]:     0041f3bf(j)
//         0041f3d4     XOR        EAX,EAX
//                               LAB_0041f3d6                                                 XREF[1]:     0041f3d2(j)
//         0041f3d6     MOV        this,dword ptr [ESI + 0x5c]
//                              basegame.cpp:2647 (24)
//         0041f3d9     POP        ESI
//         0041f3da     MOV        dword ptr [ECX + this->scenario_info],EAX
//         0041f3dd     MOV        this,dword ptr [ESP + local_c]
//         0041f3e1     MOV        EAX,0x1
//         0041f3e6     MOV        dword ptr FS:[0x0],this
//         0041f3ed     ADD        ESP,0x10
//         0041f3f0     RET
//         0041f3f1     ??         90h
//         0041f3f2     NOP
//         0041f3f3     NOP
//         0041f3f4     NOP
//         0041f3f5     NOP
//         0041f3f6     NOP
//         0041f3f7     NOP
//         0041f3f8     NOP
//         0041f3f9     NOP
//         0041f3fa     NOP
//         0041f3fb     NOP
//         0041f3fc     NOP
//         0041f3fd     NOP
//         0041f3fe     NOP
//         0041f3ff     NOP
    return 0;
}

int RGE_Base_Game::setup_sounds() {
    /* TODO: Stub */
//                              int __thiscall setup_sounds(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[6]:     0041f46f(W), 0041f497(W), 0041f4af(W), 0041f4d7(W),
//                                                                                     0041f4f0(W), 0041f518(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0041f432(R), 0041f545(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[3]:     0041f469(W), 0041f4a9(W), 0041f4ea(W)
//                               ?setup_sounds@RGE_Base_Game@@MAEHXZ                          XREF[1]:     0056ef64(*)
//                               RGE_Base_Game::setup_sounds
//                              basegame.cpp:2653 (25)
//         0041f400     PUSH       -0x1
//         0041f402     PUSH       FUN_0055cbc1
//         0041f407     MOV        EAX,FS:[0x0]
//         0041f40d     PUSH       EAX
//         0041f40e     MOV        dword ptr FS:[0x0],ESP
//         0041f415     PUSH       this
//         0041f416     PUSH       ESI
//         0041f417     MOV        ESI,this
//                              basegame.cpp:2658 (21)
//         0041f419     PUSH       0x4
//         0041f41b     PUSH       0x3
//         0041f41d     MOV        word ptr [ESI + 0x68],0x3
//         0041f423     CALL       calloc                                           undefined calloc()
//         0041f428     ADD        ESP,0x8
//         0041f42b     MOV        dword ptr [ESI + 0x6c],EAX
//                              basegame.cpp:2659 (4)
//         0041f42e     TEST       EAX,EAX
//         0041f430     JNZ        LAB_0041f442
//                              basegame.cpp:2676 (16)
//         0041f432     MOV        this,dword ptr [ESP + local_c]
//         0041f436     MOV        dword ptr FS:[0x0],this
//         0041f43d     POP        ESI
//         0041f43e     ADD        ESP,0x10
//         0041f441     RET
//                               LAB_0041f442                                                 XREF[1]:     0041f430(j)
//                              basegame.cpp:2662 (9)
//         0041f442     XOR        EAX,EAX
//         0041f444     PUSH       EDI
//         0041f445     CMP        word ptr [ESI + 0x68],AX
//         0041f449     JLE        LAB_0041f45f
//                               LAB_0041f44b                                                 XREF[1]:     0041f45d(j)
//                              basegame.cpp:2663 (20)
//         0041f44b     MOV        this,dword ptr [ESI + 0x6c]
//         0041f44e     INC        EAX
//         0041f44f     MOV        dword ptr [this->_padding_ + EAX*0x4 + -0x4],0x0
//         0041f457     MOVSX      EDX,word ptr [ESI + 0x68]
//         0041f45b     CMP        EAX,EDX
//         0041f45d     JL         LAB_0041f44b
//                               LAB_0041f45f                                                 XREF[1]:     0041f449(j)
//                              basegame.cpp:2665 (54)
//         0041f45f     PUSH       0x3c
//         0041f461     CALL       operator_new                                     void * operator_new(uint param_1)
//         0041f466     ADD        ESP,0x4
//         0041f469     MOV        dword ptr [ESP + local_10],EAX
//         0041f46d     TEST       EAX,EAX
//         0041f46f     MOV        dword ptr [ESP + local_4],0x0
//         0041f477     JZ         LAB_0041f490
//         0041f479     MOV        this,dword ptr [ESI + 0x60]
//         0041f47c     PUSH       0xc47c
//         0041f481     PUSH       s_button1.wav                                    = "button1.wav"
//         0041f486     PUSH       this
//         0041f487     MOV        this,EAX
//         0041f489     CALL       TDigital::TDigital                               undefined TDigital(TDigital * this, TSound_Dr
//         0041f48e     JMP        LAB_0041f492
//                               LAB_0041f490                                                 XREF[1]:     0041f477(j)
//         0041f490     XOR        EAX,EAX
//                               LAB_0041f492                                                 XREF[1]:     0041f48e(j)
//         0041f492     MOV        EDX,dword ptr [ESI + 0x6c]
//                              basegame.cpp:2666 (64)
//         0041f495     PUSH       0x3c
//         0041f497     MOV        dword ptr [ESP + local_4],0xffffffff
//         0041f49f     MOV        dword ptr [EDX],EAX
//         0041f4a1     CALL       operator_new                                     void * operator_new(uint param_1)
//         0041f4a6     ADD        ESP,0x4
//         0041f4a9     MOV        dword ptr [ESP + local_10],EAX
//         0041f4ad     TEST       EAX,EAX
//         0041f4af     MOV        dword ptr [ESP + local_4],0x1
//         0041f4b7     JZ         LAB_0041f4d0
//         0041f4b9     MOV        this,dword ptr [ESI + 0x60]
//         0041f4bc     PUSH       0xc47d
//         0041f4c1     PUSH       s_button2.wav                                    = "button2.wav"
//         0041f4c6     PUSH       this
//         0041f4c7     MOV        this,EAX
//         0041f4c9     CALL       TDigital::TDigital                               undefined TDigital(TDigital * this, TSound_Dr
//         0041f4ce     JMP        LAB_0041f4d2
//                               LAB_0041f4d0                                                 XREF[1]:     0041f4b7(j)
//         0041f4d0     XOR        EAX,EAX
//                               LAB_0041f4d2                                                 XREF[1]:     0041f4ce(j)
//         0041f4d2     MOV        EDX,dword ptr [ESI + 0x6c]
//                              basegame.cpp:2667 (65)
//         0041f4d5     PUSH       0x3c
//         0041f4d7     MOV        dword ptr [ESP + local_4],0xffffffff
//         0041f4df     MOV        dword ptr [EDX + 0x4],EAX
//         0041f4e2     CALL       operator_new                                     void * operator_new(uint param_1)
//         0041f4e7     ADD        ESP,0x4
//         0041f4ea     MOV        dword ptr [ESP + local_10],EAX
//         0041f4ee     TEST       EAX,EAX
//         0041f4f0     MOV        dword ptr [ESP + local_4],0x2
//         0041f4f8     JZ         LAB_0041f511
//         0041f4fa     MOV        this,dword ptr [ESI + 0x60]
//         0041f4fd     PUSH       0xc47e
//         0041f502     PUSH       s_chatrcvd.wav                                   = "chatrcvd.wav"
//         0041f507     PUSH       this
//         0041f508     MOV        this,EAX
//         0041f50a     CALL       TDigital::TDigital                               undefined TDigital(TDigital * this, TSound_Dr
//         0041f50f     JMP        LAB_0041f513
//                               LAB_0041f511                                                 XREF[1]:     0041f4f8(j)
//         0041f511     XOR        EAX,EAX
//                               LAB_0041f513                                                 XREF[1]:     0041f50f(j)
//         0041f513     MOV        EDX,dword ptr [ESI + 0x6c]
//                              basegame.cpp:2669 (19)
//         0041f516     XOR        EDI,EDI
//         0041f518     MOV        dword ptr [ESP + local_4],0xffffffff
//         0041f520     MOV        dword ptr [EDX + 0x8],EAX
//         0041f523     CMP        word ptr [ESI + 0x68],DI
//         0041f527     JLE        LAB_0041f545
//                               LAB_0041f529                                                 XREF[1]:     0041f543(j)
//                              basegame.cpp:2671 (10)
//         0041f529     MOV        EAX,dword ptr [ESI + 0x6c]
//         0041f52c     MOV        this,dword ptr [EAX + EDI*0x4]
//         0041f52f     TEST       this,this
//         0041f531     JZ         LAB_0041f53c
//                              basegame.cpp:2672 (18)
//         0041f533     PUSH       -0x1
//         0041f535     PUSH       0x0
//         0041f537     CALL       TDigital::load                                   int load(TDigital * this, char * param_1, lon
//                               LAB_0041f53c                                                 XREF[1]:     0041f531(j)
//         0041f53c     MOVSX      this,word ptr [ESI + 0x68]
//         0041f540     INC        EDI
//         0041f541     CMP        EDI,this
//         0041f543     JL         LAB_0041f529
//                               LAB_0041f545                                                 XREF[1]:     0041f527(j)
//                              basegame.cpp:2676 (22)
//         0041f545     MOV        this,dword ptr [ESP + local_c]
//         0041f549     POP        EDI
//         0041f54a     MOV        EAX,0x1
//         0041f54f     MOV        dword ptr FS:[0x0],this
//         0041f556     POP        ESI
//         0041f557     ADD        ESP,0x10
//         0041f55a     RET
//         0041f55b     ??         90h
//         0041f55c     NOP
//         0041f55d     NOP
//         0041f55e     NOP
//         0041f55f     NOP
    return 0;
}

int RGE_Base_Game::setup_fonts() {
    /* TODO: Stub */
//                              int __thiscall setup_fonts(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              tagTEXTMETRICA    Stack[-0x3c]   tm                        XREF[1]:     0041f5c4(W)
//              undefined4        Stack[-0x40]:4 local_40                  XREF[1]:     0041f5b4(W)
//              short             Stack[-0x44]:2 i
//                               ?setup_fonts@RGE_Base_Game@@MAEHXZ                           XREF[2]:     0056ef60(*), 00577238(*)
//                               RGE_Base_Game::setup_fonts
//                              basegame.cpp:2682 (9)
//         0041f560     SUB        ESP,0x40
//         0041f563     PUSH       EBX
//         0041f564     PUSH       EBP
//         0041f565     PUSH       ESI
//         0041f566     PUSH       EDI
//         0041f567     MOV        EDI,this
//                              basegame.cpp:2691 (27)
//         0041f569     PUSH       0xc
//         0041f56b     PUSH       0xc
//         0041f56d     MOV        word ptr [EDI + 0x1e0],0xc
//         0041f576     CALL       calloc                                           undefined calloc()
//         0041f57b     ADD        ESP,0x8
//         0041f57e     MOV        dword ptr [EDI + 0x1e4],EAX
//                              basegame.cpp:2692 (4)
//         0041f584     TEST       EAX,EAX
//         0041f586     JNZ        LAB_0041f590
//                              basegame.cpp:2732 (8)
//         0041f588     POP        EDI
//         0041f589     POP        ESI
//         0041f58a     POP        EBP
//         0041f58b     POP        EBX
//         0041f58c     ADD        ESP,0x40
//         0041f58f     RET
//                               LAB_0041f590                                                 XREF[1]:     0041f586(j)
//                              basegame.cpp:2695 (15)
//         0041f590     MOV        this,dword ptr [EDI + 0x4c]
//         0041f593     PUSH       s_basegame::setup_fonts                          = "basegame::setup_fonts"
//         0041f598     CALL       TDrawArea::GetDc                                 void * GetDc(TDrawArea * this, char * param_1)
//         0041f59d     MOV        EBX,EAX
//                              basegame.cpp:2696 (4)
//         0041f59f     TEST       EBX,EBX
//         0041f5a1     JNZ        LAB_0041f5ab
//                              basegame.cpp:2732 (8)
//         0041f5a3     POP        EDI
//         0041f5a4     POP        ESI
//         0041f5a5     POP        EBP
//         0041f5a6     POP        EBX
//         0041f5a7     ADD        ESP,0x40
//         0041f5aa     RET
//                               LAB_0041f5ab                                                 XREF[1]:     0041f5a1(j)
//                              basegame.cpp:2699 (19)
//         0041f5ab     XOR        EBP,EBP
//         0041f5ad     CMP        word ptr [EDI + 0x1e0],BP
//         0041f5b4     MOV        dword ptr [ESP + local_40],EBP
//         0041f5b8     JLE        LAB_0041f6e0
//                               LAB_0041f5be                                                 XREF[1]:     0041f6da(j)
//                              basegame.cpp:2701 (23)
//         0041f5be     MOVSX      EAX,BP
//         0041f5c1     CMP        EAX,0xb
//         0041f5c4     MOV        dword ptr [ESP + tm.tmHeight],EAX
//         0041f5c8     JA         switchD_0041f5ce::caseD_2
//                               switchD_0041f5ce::switchD
//         0041f5ce     JMP        dword ptr [EAX*0x4 + ->switchD_0041f5ce::caseD   = 0041f5d5
//                               switchD_0041f5ce::caseD_0                                    XREF[2]:     0041f5ce(j), 0041f6fc(*)
//                              basegame.cpp:2703 (19)
//         0041f5d5     PUSH       0x0
//                              language.dll match for 0x6e: "Copperplate Gothic Light"
//         0041f5d7     PUSH       0x6e
//         0041f5d9     PUSH       EBX
//         0041f5da     MOV        this,EDI
//         0041f5dc     CALL       RGE_Base_Game::make_font                         void * make_font(RGE_Base_Game * this, void *
//         0041f5e1     MOV        ESI,EAX
//         0041f5e3     JMP        LAB_0041f673
//                               switchD_0041f5ce::caseD_1                                    XREF[2]:     0041f5ce(j), 0041f700(*)
//                              basegame.cpp:2704 (4)
//         0041f5e8     PUSH       0x0
//                              language.dll match for 0x71: "Copperplate Gothic Light"
//         0041f5ea     PUSH       0x71
//                              basegame.cpp:2714 (12)
//         0041f5ec     PUSH       EBX
//         0041f5ed     MOV        this,EDI
//         0041f5ef     CALL       RGE_Base_Game::make_font                         void * make_font(RGE_Base_Game * this, void *
//         0041f5f4     MOV        ESI,EAX
//         0041f5f6     JMP        LAB_0041f673
//                               switchD_0041f5ce::caseD_4                                    XREF[2]:     0041f5ce(j), 0041f70c(*)
//                              basegame.cpp:2707 (4)
//         0041f5f8     PUSH       0x0
//                              language.dll match for 0x74: "Copperplate Gothic Light"
//         0041f5fa     PUSH       0x74
//                              basegame.cpp:2714 (12)
//         0041f5fc     PUSH       EBX
//         0041f5fd     MOV        this,EDI
//         0041f5ff     CALL       RGE_Base_Game::make_font                         void * make_font(RGE_Base_Game * this, void *
//         0041f604     MOV        ESI,EAX
//         0041f606     JMP        LAB_0041f673
//                               switchD_0041f5ce::caseD_6                                    XREF[2]:     0041f5ce(j), 0041f714(*)
//                              basegame.cpp:2709 (19)
//         0041f608     PUSH       0x0
//                              language.dll match for 0x83: "Arial"
//         0041f60a     PUSH       0x83
//         0041f60f     PUSH       EBX
//         0041f610     MOV        this,EDI
//         0041f612     CALL       RGE_Base_Game::make_font                         void * make_font(RGE_Base_Game * this, void *
//         0041f617     MOV        ESI,EAX
//         0041f619     JMP        LAB_0041f673
//                               switchD_0041f5ce::caseD_7                                    XREF[2]:     0041f5ce(j), 0041f718(*)
//                              basegame.cpp:2710 (16)
//         0041f61b     PUSH       0x0
//                              language.dll match for 0x77: "Arial"
//         0041f61d     PUSH       0x77
//         0041f61f     PUSH       EBX
//         0041f620     MOV        this,EDI
//         0041f622     CALL       RGE_Base_Game::make_font                         void * make_font(RGE_Base_Game * this, void *
//         0041f627     MOV        ESI,EAX
//         0041f629     JMP        LAB_0041f673
//                               switchD_0041f5ce::caseD_8                                    XREF[2]:     0041f5ce(j), 0041f71c(*)
//                              basegame.cpp:2711 (19)
//         0041f62b     PUSH       0x1
//                              language.dll match for 0x80: "Arial"
//         0041f62d     PUSH       0x80
//         0041f632     PUSH       EBX
//         0041f633     MOV        this,EDI
//         0041f635     CALL       RGE_Base_Game::make_font                         void * make_font(RGE_Base_Game * this, void *
//         0041f63a     MOV        ESI,EAX
//         0041f63c     JMP        LAB_0041f673
//                               switchD_0041f5ce::caseD_9                                    XREF[2]:     0041f5ce(j), 0041f720(*)
//                              basegame.cpp:2712 (16)
//         0041f63e     PUSH       0x0
//                              language.dll match for 0x7a: "Arial"
//         0041f640     PUSH       0x7a
//         0041f642     PUSH       EBX
//         0041f643     MOV        this,EDI
//         0041f645     CALL       RGE_Base_Game::make_font                         void * make_font(RGE_Base_Game * this, void *
//         0041f64a     MOV        ESI,EAX
//         0041f64c     JMP        LAB_0041f673
//                               switchD_0041f5ce::caseD_a                                    XREF[2]:     0041f5ce(j), 0041f724(*)
//                              basegame.cpp:2713 (16)
//         0041f64e     PUSH       0x0
//                              language.dll match for 0x7d: "Arial"
//         0041f650     PUSH       0x7d
//         0041f652     PUSH       EBX
//         0041f653     MOV        this,EDI
//         0041f655     CALL       RGE_Base_Game::make_font                         void * make_font(RGE_Base_Game * this, void *
//         0041f65a     MOV        ESI,EAX
//         0041f65c     JMP        LAB_0041f673
//                               switchD_0041f5ce::caseD_b                                    XREF[2]:     0041f5ce(j), 0041f728(*)
//                              basegame.cpp:2714 (19)
//         0041f65e     PUSH       0x0
//                              language.dll match for 0x80: "Arial"
//         0041f660     PUSH       0x80
//         0041f665     PUSH       EBX
//         0041f666     MOV        this,EDI
//         0041f668     CALL       RGE_Base_Game::make_font                         void * make_font(RGE_Base_Game * this, void *
//         0041f66d     MOV        ESI,EAX
//         0041f66f     JMP        LAB_0041f673
//                               switchD_0041f5ce::caseD_3                                    XREF[5]:     0041f5c8(j), 0041f5ce(j),
//                               switchD_0041f5ce::caseD_5                                                 0041f704(*), 0041f708(*),
//                               switchD_0041f5ce::caseD_2                                                 0041f710(*)
//                              basegame.cpp:2715 (2)
//         0041f671     XOR        ESI,ESI
//                               LAB_0041f673                                                 XREF[9]:     0041f5e3(j), 0041f5f6(j),
//                                                                                                         0041f606(j), 0041f619(j),
//                                                                                                         0041f629(j), 0041f63c(j),
//                                                                                                         0041f64c(j), 0041f65c(j),
//                                                                                                         0041f66f(j)
//                              basegame.cpp:2718 (4)
//         0041f673     TEST       ESI,ESI
//         0041f675     JZ         LAB_0041f6ce
//                              basegame.cpp:2720 (10)
//         0041f677     PUSH       ESI
//         0041f678     PUSH       EBX
//         0041f679     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
//         0041f67f     MOV        EBP,EAX
//                              basegame.cpp:2721 (12)
//         0041f681     LEA        EAX,[ESP + 0x18]
//         0041f685     PUSH       EAX
//         0041f686     PUSH       EBX
//         0041f687     CALL       dword ptr [->GDI32.DLL::GetTextMetricsA]         = 0048b180
//                              basegame.cpp:2722 (10)
//         0041f68d     MOV        EAX,dword ptr [ESP + 0x14]
//         0041f691     MOV        this,dword ptr [EDI + 0x1e4]
//                              basegame.cpp:2725 (73)
//         0041f697     PUSH       EBP
//         0041f698     PUSH       EBX
//         0041f699     LEA        EAX,[EAX + EAX*0x2]
//         0041f69c     SHL        EAX,0x2
//         0041f69f     MOV        dword ptr [this->_padding_ + EAX*0x1],ESI
//         0041f6a2     MOV        EDX,dword ptr [EDI + 0x1e4]
//         0041f6a8     MOV        this,dword ptr [ESP + 0x34]
//         0041f6ac     MOV        dword ptr [EDX + EAX*0x1 + 0x4],this
//         0041f6b0     MOV        EDX,dword ptr [ESP + 0x20]
//         0041f6b4     MOV        this,dword ptr [ESP + 0x30]
//         0041f6b8     ADD        EDX,this
//         0041f6ba     MOV        this,dword ptr [EDI + 0x1e4]
//         0041f6c0     MOV        dword ptr [ECX + EAX*0x1 + this->scenario_info
//         0041f6c4     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
//         0041f6ca     MOV        EBP,dword ptr [ESP + 0x10]
//                               LAB_0041f6ce                                                 XREF[1]:     0041f675(j)
//         0041f6ce     INC        EBP
//         0041f6cf     CMP        BP,word ptr [EDI + 0x1e0]
//         0041f6d6     MOV        dword ptr [ESP + 0x10],EBP
//         0041f6da     JL         LAB_0041f5be
//                               LAB_0041f6e0                                                 XREF[1]:     0041f5b8(j)
//                              basegame.cpp:2729 (13)
//         0041f6e0     MOV        this,dword ptr [EDI + 0x4c]
//         0041f6e3     PUSH       s_basegame::setup_fonts                          = "basegame::setup_fonts"
//         0041f6e8     CALL       TDrawArea::ReleaseDc                             void ReleaseDc(TDrawArea * this, char * param
//                              basegame.cpp:2732 (63)
//         0041f6ed     POP        EDI
//         0041f6ee     POP        ESI
//         0041f6ef     POP        EBP
//         0041f6f0     MOV        EAX,0x1
//         0041f6f5     POP        EBX
//         0041f6f6     ADD        ESP,0x40
//         0041f6f9     RET
    return 0;
}

int RGE_Base_Game::setup_blank_screen() {
    /* TODO: Stub */
//                              int __thiscall setup_blank_screen(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0041f75c(W), 0041f778(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0041f782(R), 0041f7a7(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0041f756(W)
//                               ?setup_blank_screen@RGE_Base_Game@@MAEHXZ                    XREF[2]:     0056ef6c(*), 00577244(*)
//                               RGE_Base_Game::setup_blank_screen
//                              basegame.cpp:2737 (25)
//         0041f730     PUSH       -0x1
//         0041f732     PUSH       FUN_0055cbdb
//         0041f737     MOV        EAX,FS:[0x0]
//         0041f73d     PUSH       EAX
//         0041f73e     MOV        dword ptr FS:[0x0],ESP
//         0041f745     PUSH       this
//         0041f746     PUSH       ESI
//         0041f747     MOV        ESI,this
//                              basegame.cpp:2738 (45)
//         0041f749     PUSH       0x478
//         0041f74e     CALL       operator_new                                     void * operator_new(uint param_1)
//         0041f753     ADD        ESP,0x4
//         0041f756     MOV        dword ptr [ESP + local_10],EAX
//         0041f75a     TEST       EAX,EAX
//         0041f75c     MOV        dword ptr [ESP + local_4],0x0
//         0041f764     JZ         LAB_0041f774
//         0041f766     PUSH       s_Blank_Screen                                   = "Blank Screen"
//         0041f76b     MOV        this,EAX
//         0041f76d     CALL       TScreenPanel::TScreenPanel                       undefined TScreenPanel(TScreenPanel * this, c
//         0041f772     JMP        LAB_0041f776
//                               LAB_0041f774                                                 XREF[1]:     0041f764(j)
//         0041f774     XOR        EAX,EAX
//                               LAB_0041f776                                                 XREF[1]:     0041f772(j)
//                              basegame.cpp:2739 (12)
//         0041f776     TEST       EAX,EAX
//         0041f778     MOV        dword ptr [ESP + local_4],0xffffffff
//         0041f780     JNZ        LAB_0041f792
//                              basegame.cpp:2749 (16)
//         0041f782     MOV        this,dword ptr [ESP + local_c]
//         0041f786     MOV        dword ptr FS:[0x0],this
//         0041f78d     POP        ESI
//         0041f78e     ADD        ESP,0x10
//         0041f791     RET
//                               LAB_0041f792                                                 XREF[1]:     0041f780(j)
//                              basegame.cpp:2741 (21)
//         0041f792     MOV        this,dword ptr [ESI + 0x4c]
//         0041f795     PUSH       0x0
//         0041f797     PUSH       -0x1
//         0041f799     PUSH       0x0
//         0041f79b     PUSH       this
//         0041f79c     MOV        this,EAX
//         0041f79e     CALL       TScreenPanel::setup                              long setup(TScreenPanel * this, TDrawArea * p
//         0041f7a3     TEST       EAX,EAX
//         0041f7a5     JNZ        LAB_0041f7b7
//                              basegame.cpp:2749 (16)
//         0041f7a7     MOV        this,dword ptr [ESP + local_c]
//         0041f7ab     MOV        dword ptr FS:[0x0],this
//         0041f7b2     POP        ESI
//         0041f7b3     ADD        ESP,0x10
//         0041f7b6     RET
//                               LAB_0041f7b7                                                 XREF[1]:     0041f7a5(j)
//                              basegame.cpp:2745 (17)
//         0041f7b7     PUSH       0x0
//         0041f7b9     PUSH       s_Blank_Screen                                   = "Blank Screen"
//         0041f7be     MOV        this,panel_system
//         0041f7c3     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
//                              basegame.cpp:2746 (7)
//         0041f7c8     MOV        this,ESI
//         0041f7ca     CALL       RGE_Base_Game::set_render_all                    void set_render_all(RGE_Base_Game * this)
//                              basegame.cpp:2747 (16)
//         0041f7cf     MOV        EDX,dword ptr [ESI + 0x10]
//         0041f7d2     PUSH       0x0
//         0041f7d4     PUSH       0x0
//         0041f7d6     PUSH       0xf
//         0041f7d8     PUSH       EDX
//         0041f7d9     CALL       dword ptr [->USER32.DLL::SendMessageA]           = 0048ad08
//                              basegame.cpp:2749 (21)
//         0041f7df     MOV        this,dword ptr [ESP + 0x8]
//         0041f7e3     MOV        EAX,0x1
//         0041f7e8     MOV        dword ptr FS:[0x0],this
//         0041f7ef     POP        ESI
//         0041f7f0     ADD        ESP,0x10
//         0041f7f3     RET
//         0041f7f4     ??         90h
//         0041f7f5     NOP
//         0041f7f6     NOP
//         0041f7f7     NOP
//         0041f7f8     NOP
//         0041f7f9     NOP
//         0041f7fa     NOP
//         0041f7fb     NOP
//         0041f7fc     NOP
//         0041f7fd     NOP
//         0041f7fe     NOP
//         0041f7ff     NOP
    return 0;
}

void RGE_Base_Game::setup_timings() {
    /* TODO: Stub */
//                              void __thiscall setup_timings(RGE_Base_Game * this)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?setup_timings@RGE_Base_Game@@MAEXXZ                         XREF[2]:     0056ef70(*), 00577248(*)
//                               RGE_Base_Game::setup_timings
//                              basegame.cpp:2755 (11)
//         0041f800     MOV        EAX,0x1
//         0041f805     MOV        dword ptr [ECX + this+0x554],EAX
//                              basegame.cpp:2760 (6)
//         0041f80b     MOV        dword ptr [ECX + this+0x574],EAX
//                              basegame.cpp:2761 (6)
//         0041f811     MOV        dword ptr [ECX + this+0x594],EAX
//                              basegame.cpp:2762 (6)
//         0041f817     MOV        dword ptr [ECX + this+0x674],EAX
//                              basegame.cpp:2763 (6)
//         0041f81d     MOV        dword ptr [ECX + this+0x6d4],EAX
//                              basegame.cpp:2766 (6)
//         0041f823     MOV        dword ptr [ECX + this+0x538],EAX
//                              basegame.cpp:2767 (6)
//         0041f829     MOV        dword ptr [ECX + this+0x5b8],EAX
//                              basegame.cpp:2768 (1)
//         0041f82f     RET
    return;
}

void RGE_Base_Game::stop_sound_system() {
    /* TODO: Stub */
//                              void __thiscall stop_sound_system(RGE_Base_Game * this)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?stop_sound_system@RGE_Base_Game@@MAEXXZ                     XREF[3]:     ~RGE_Base_Game:0041c56c(c),
//                               RGE_Base_Game::stop_sound_system                                          0056ef74(*), 0057724c(*)
//                              basegame.cpp:2774 (5)
//         0041f830     PUSH       EBX
//         0041f831     PUSH       ESI
//         0041f832     MOV        ESI,this
//         0041f834     PUSH       EDI
//                              basegame.cpp:2777 (10)
//         0041f835     MOV        this,dword ptr [chat]                            = 00000000
//         0041f83b     TEST       this,this
//         0041f83d     JZ         LAB_0041f844
//                              basegame.cpp:2778 (5)
//         0041f83f     CALL       TChat::StopSoundSystem                           void StopSoundSystem(TChat * this)
//                               LAB_0041f844                                                 XREF[1]:     0041f83d(j)
//                              basegame.cpp:2780 (10)
//         0041f844     MOV        this,panel_system
//         0041f849     CALL       TPanelSystem::stop_sound_system                  void stop_sound_system(TPanelSystem * this)
//                              basegame.cpp:2782 (10)
//         0041f84e     MOV        EAX,dword ptr [ESI + 0x3f4]
//         0041f854     TEST       EAX,EAX
//         0041f856     JZ         LAB_0041f87c
//                              basegame.cpp:2784 (8)
//         0041f858     XOR        EDI,EDI
//         0041f85a     CMP        word ptr [EAX + 0x2c],DI
//         0041f85e     JLE        LAB_0041f87c
//                               LAB_0041f860                                                 XREF[1]:     0041f87a(j)
//                              basegame.cpp:2785 (28)
//         0041f860     MOV        EAX,dword ptr [EAX + 0x30]
//         0041f863     PUSH       0x0
//         0041f865     MOV        this,dword ptr [EAX + EDI*0x4]
//         0041f868     CALL       RGE_Sound::restart_sound                         void restart_sound(RGE_Sound * this, TSound_D
//         0041f86d     MOV        EAX,dword ptr [ESI + 0x3f4]
//         0041f873     INC        EDI
//         0041f874     MOVSX      this,word ptr [EAX + 0x2c]
//         0041f878     CMP        EDI,this
//         0041f87a     JL         LAB_0041f860
//                               LAB_0041f87c                                                 XREF[2]:     0041f856(j), 0041f85e(j)
//                              basegame.cpp:2788 (7)
//         0041f87c     MOV        EAX,dword ptr [ESI + 0x6c]
//         0041f87f     TEST       EAX,EAX
//         0041f881     JZ         LAB_0041f8c1
//                              basegame.cpp:2790 (8)
//         0041f883     XOR        EBX,EBX
//         0041f885     CMP        word ptr [ESI + 0x68],BX
//         0041f889     JLE        LAB_0041f8ae
//                               LAB_0041f88b                                                 XREF[1]:     0041f8ac(j)
//                              basegame.cpp:2792 (10)
//         0041f88b     MOV        EDX,dword ptr [ESI + 0x6c]
//         0041f88e     MOV        EDI,dword ptr [EDX + EBX*0x4]
//         0041f891     TEST       EDI,EDI
//         0041f893     JZ         LAB_0041f8a5
//                              basegame.cpp:2793 (25)
//         0041f895     MOV        this,EDI
//         0041f897     CALL       TDigital::~TDigital                              void ~TDigital(TDigital * this)
//         0041f89c     PUSH       EDI
//         0041f89d     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0041f8a2     ADD        ESP,0x4
//                               LAB_0041f8a5                                                 XREF[1]:     0041f893(j)
//         0041f8a5     MOVSX      EAX,word ptr [ESI + 0x68]
//         0041f8a9     INC        EBX
//         0041f8aa     CMP        EBX,EAX
//         0041f8ac     JL         LAB_0041f88b
//                               LAB_0041f8ae                                                 XREF[1]:     0041f889(j)
//                              basegame.cpp:2795 (12)
//         0041f8ae     MOV        this,dword ptr [ESI + 0x6c]
//         0041f8b1     PUSH       this
//         0041f8b2     CALL       free                                             undefined free()
//         0041f8b7     ADD        ESP,0x4
//                              basegame.cpp:2796 (7)
//         0041f8ba     MOV        dword ptr [ESI + 0x6c],0x0
//                               LAB_0041f8c1                                                 XREF[1]:     0041f881(j)
//                              basegame.cpp:2799 (7)
//         0041f8c1     MOV        EDX,dword ptr [ESI]
//         0041f8c3     MOV        this,ESI
//         0041f8c5     CALL       dword ptr [EDX + 0x5c]
//                              basegame.cpp:2801 (7)
//         0041f8c8     MOV        this,dword ptr [ESI + 0x60]
//         0041f8cb     TEST       this,this
//         0041f8cd     JZ         LAB_0041f911
//                              basegame.cpp:2803 (26)
//         0041f8cf     CALL       TSound_Driver::get_volume                        long get_volume(TSound_Driver * this)
//         0041f8d4     MOV        this,dword ptr [ESI + 0x1ac]
//         0041f8da     NEG        EAX
//         0041f8dc     PUSH       EAX
//         0041f8dd     PUSH       s_Sound_Volume                                   = "Sound Volume"
//         0041f8e2     PUSH       0x1
//         0041f8e4     CALL       TRegistry::RegSetInt                             int RegSetInt(TRegistry * this, int param_1,
//                              basegame.cpp:2805 (23)
//         0041f8e9     MOV        EDI,dword ptr [ESI + 0x60]
//         0041f8ec     TEST       EDI,EDI
//         0041f8ee     JZ         LAB_0041f900
//         0041f8f0     MOV        this,EDI
//         0041f8f2     CALL       TSound_Driver::~TSound_Driver                    void ~TSound_Driver(TSound_Driver * this)
//         0041f8f7     PUSH       EDI
//         0041f8f8     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0041f8fd     ADD        ESP,0x4
//                               LAB_0041f900                                                 XREF[1]:     0041f8ee(j)
//                              basegame.cpp:2806 (7)
//         0041f900     MOV        dword ptr [ESI + 0x60],0x0
//                              basegame.cpp:2807 (10)
//         0041f907     MOV        dword ptr [sound_driver],0x0                     = 00000000
//                               LAB_0041f911                                                 XREF[1]:     0041f8cd(j)
//                              basegame.cpp:2809 (4)
//         0041f911     POP        EDI
//         0041f912     POP        ESI
//         0041f913     POP        EBX
//         0041f914     RET
//         0041f915     ??         90h
//         0041f916     NOP
//         0041f917     NOP
//         0041f918     NOP
//         0041f919     NOP
//         0041f91a     NOP
//         0041f91b     NOP
//         0041f91c     NOP
//         0041f91d     NOP
//         0041f91e     NOP
//         0041f91f     NOP
    return;
}

int RGE_Base_Game::restart_sound_system() {
    /* TODO: Stub */
//                              int __thiscall restart_sound_system(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?restart_sound_system@RGE_Base_Game@@MAEHXZ                  XREF[2]:     0056ef78(*), 00577250(*)
//                               RGE_Base_Game::restart_sound_system
//                              basegame.cpp:2815 (5)
//         0041f920     PUSH       EBX
//         0041f921     PUSH       ESI
//         0041f922     PUSH       EDI
//         0041f923     MOV        EDI,this
//                              basegame.cpp:2820 (7)
//         0041f925     MOV        EAX,dword ptr [EDI + 0x60]
//         0041f928     TEST       EAX,EAX
//         0041f92a     JNZ        LAB_0041f9a1
//                              basegame.cpp:2824 (12)
//         0041f92c     MOV        EBX,dword ptr [EDI]
//         0041f92e     CALL       dword ptr [EBX + 0x8c]
//         0041f934     TEST       EAX,EAX
//         0041f936     JNZ        LAB_0041f93c
//                              basegame.cpp:2858 (4)
//         0041f938     POP        EDI
//         0041f939     POP        ESI
//         0041f93a     POP        EBX
//         0041f93b     RET
//                               LAB_0041f93c                                                 XREF[1]:     0041f936(j)
//                              basegame.cpp:2832 (12)
//         0041f93c     MOV        this,EDI
//         0041f93e     CALL       dword ptr [EBX + 0x94]
//         0041f944     TEST       EAX,EAX
//         0041f946     JNZ        LAB_0041f94c
//                              basegame.cpp:2858 (4)
//         0041f948     POP        EDI
//         0041f949     POP        ESI
//         0041f94a     POP        EBX
//         0041f94b     RET
//                               LAB_0041f94c                                                 XREF[1]:     0041f946(j)
//                              basegame.cpp:2839 (10)
//         0041f94c     MOV        EAX,dword ptr [EDI + 0x3f4]
//         0041f952     TEST       EAX,EAX
//         0041f954     JZ         LAB_0041f97c
//                              basegame.cpp:2842 (8)
//         0041f956     XOR        ESI,ESI
//         0041f958     CMP        word ptr [EAX + 0x2c],SI
//         0041f95c     JLE        LAB_0041f97c
//                               LAB_0041f95e                                                 XREF[1]:     0041f97a(j)
//                              basegame.cpp:2843 (30)
//         0041f95e     MOV        this,dword ptr [EDI + 0x60]
//         0041f961     MOV        EDX,dword ptr [EAX + 0x30]
//         0041f964     PUSH       this
//         0041f965     MOV        this,dword ptr [EDX + ESI*0x4]
//         0041f968     CALL       RGE_Sound::restart_sound                         void restart_sound(RGE_Sound * this, TSound_D
//         0041f96d     MOV        EAX,dword ptr [EDI + 0x3f4]
//         0041f973     INC        ESI
//         0041f974     MOVSX      this,word ptr [EAX + 0x2c]
//         0041f978     CMP        ESI,this
//         0041f97a     JL         LAB_0041f95e
//                               LAB_0041f97c                                                 XREF[2]:     0041f954(j), 0041f95c(j)
//                              basegame.cpp:2847 (10)
//         0041f97c     MOV        this,panel_system
//         0041f981     CALL       TPanelSystem::restart_sound_system               int restart_sound_system(TPanelSystem * this)
//                              basegame.cpp:2849 (10)
//         0041f986     MOV        this,dword ptr [chat]                            = 00000000
//         0041f98c     TEST       this,this
//         0041f98e     JZ         LAB_0041f999
//                              basegame.cpp:2850 (9)
//         0041f990     MOV        EDX,dword ptr [EDI + 0x60]
//         0041f993     PUSH       EDX
//         0041f994     CALL       TChat::RestartSoundSystem                        int RestartSoundSystem(TChat * this, TSound_D
//                               LAB_0041f999                                                 XREF[1]:     0041f98e(j)
//                              basegame.cpp:2852 (8)
//         0041f999     MOV        this,EDI
//         0041f99b     CALL       dword ptr [EBX + 0xb0]
//                               LAB_0041f9a1                                                 XREF[1]:     0041f92a(j)
//                              basegame.cpp:2858 (9)
//         0041f9a1     POP        EDI
//         0041f9a2     POP        ESI
//         0041f9a3     MOV        EAX,0x1
//         0041f9a8     POP        EBX
//         0041f9a9     RET
//         0041f9aa     ??         90h
//         0041f9ab     NOP
//         0041f9ac     NOP
//         0041f9ad     NOP
//         0041f9ae     NOP
//         0041f9af     NOP
    return 0;
}

void RGE_Base_Game::stop_music_system() {
    /* TODO: Stub */
//                              void __thiscall stop_music_system(RGE_Base_Game * this)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?stop_music_system@RGE_Base_Game@@MAEXXZ                     XREF[2]:     0056ef7c(*), 00577254(*)
//                               RGE_Base_Game::stop_music_system
//                              basegame.cpp:2864 (3)
//         0041f9b0     PUSH       ESI
//         0041f9b1     MOV        ESI,this
//                              basegame.cpp:2865 (7)
//         0041f9b3     MOV        this,dword ptr [ESI + 0x64]
//         0041f9b6     TEST       this,this
//         0041f9b8     JZ         LAB_0041f9ec
//                              basegame.cpp:2867 (42)
//         0041f9ba     LEA        EAX,[ESI + 0x188]
//         0041f9c0     LEA        EDX,[ESI + 0x184]
//         0041f9c6     PUSH       EAX
//         0041f9c7     LEA        EAX,[ESI + 0x80]
//         0041f9cd     PUSH       EDX
//         0041f9ce     PUSH       EAX
//         0041f9cf     LEA        EDX,[ESI + 0x7c]
//         0041f9d2     LEA        EAX,[ESI + 0x78]
//         0041f9d5     PUSH       EDX
//         0041f9d6     PUSH       EAX
//         0041f9d7     LEA        EDX,[ESI + 0x74]
//         0041f9da     LEA        EAX,[ESI + 0x70]
//         0041f9dd     PUSH       EDX
//         0041f9de     PUSH       EAX
//         0041f9df     CALL       TMusic_System::get_play_info                     int get_play_info(TMusic_System * this, uchar
//                              basegame.cpp:2868 (8)
//         0041f9e4     MOV        this,dword ptr [ESI + 0x64]
//         0041f9e7     CALL       TMusic_System::stop_track                        int stop_track(TMusic_System * this)
//                               LAB_0041f9ec                                                 XREF[1]:     0041f9b8(j)
//                              basegame.cpp:2870 (2)
//         0041f9ec     POP        ESI
//         0041f9ed     RET
//         0041f9ee     ??         90h
//         0041f9ef     NOP
    return;
}

int RGE_Base_Game::restart_music_system() {
    /* TODO: Stub */
//                              int __thiscall restart_music_system(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?restart_music_system@RGE_Base_Game@@MAEHXZ                  XREF[2]:     0056ef80(*), 00577258(*)
//                               RGE_Base_Game::restart_music_system
//                              basegame.cpp:2876 (2)
//         0041f9f0     MOV        EAX,this
//                              basegame.cpp:2877 (7)
//         0041f9f2     MOV        this,dword ptr [EAX + 0x64]
//         0041f9f5     TEST       this,this
//         0041f9f7     JNZ        LAB_0041f9ff
//                              basegame.cpp:2878 (5)
//         0041f9f9     MOV        EAX,0x1
//                              basegame.cpp:2888 (1)
//         0041f9fe     RET
//                               LAB_0041f9ff                                                 XREF[1]:     0041f9f7(j)
//                              basegame.cpp:2880 (15)
//         0041f9ff     MOV        EDX,dword ptr [EAX + 0x74]
//         0041fa02     PUSH       EDI
//         0041fa03     PUSH       ESI
//         0041fa04     PUSH       EBX
//         0041fa05     TEST       EDX,EDX
//         0041fa07     JZ         LAB_0041fa58
//         0041fa09     CMP        EDX,dword ptr [EAX + 0x78]
//         0041fa0c     JNZ        LAB_0041fa2b
//                              basegame.cpp:2881 (22)
//         0041fa0e     MOV        ESI,dword ptr [EAX + 0x188]
//         0041fa14     MOV        EAX,dword ptr [EAX + 0x184]
//         0041fa1a     PUSH       ESI
//         0041fa1b     PUSH       EAX
//         0041fa1c     PUSH       EDX
//         0041fa1d     CALL       TMusic_System::play_track                        int play_track(TMusic_System * this, int para
//         0041fa22     POP        EBX
//         0041fa23     POP        ESI
//                              basegame.cpp:2887 (6)
//         0041fa24     MOV        EAX,0x1
//         0041fa29     POP        EDI
//                              basegame.cpp:2888 (1)
//         0041fa2a     RET
//                               LAB_0041fa2b                                                 XREF[1]:     0041fa0c(j)
//                              basegame.cpp:2882 (11)
//         0041fa2b     TEST       EDX,EDX
//         0041fa2d     JZ         LAB_0041fa58
//         0041fa2f     MOV        ESI,dword ptr [EAX + 0x78]
//         0041fa32     TEST       ESI,ESI
//         0041fa34     JZ         LAB_0041fa58
//                              basegame.cpp:2883 (27)
//         0041fa36     MOV        EDI,dword ptr [EAX + 0x188]
//         0041fa3c     PUSH       EDI
//         0041fa3d     MOV        EDI,dword ptr [EAX + 0x7c]
//         0041fa40     MOV        EAX,dword ptr [EAX + 0x184]
//         0041fa46     PUSH       EDI
//         0041fa47     PUSH       EAX
//         0041fa48     PUSH       ESI
//         0041fa49     PUSH       EDX
//         0041fa4a     CALL       TMusic_System::play_tracks                       int play_tracks(TMusic_System * this, int par
//         0041fa4f     POP        EBX
//         0041fa50     POP        ESI
//                              basegame.cpp:2887 (6)
//         0041fa51     MOV        EAX,0x1
//         0041fa56     POP        EDI
//                              basegame.cpp:2888 (1)
//         0041fa57     RET
//                               LAB_0041fa58                                                 XREF[3]:     0041fa07(j), 0041fa2d(j),
//                                                                                                         0041fa34(j)
//                              basegame.cpp:2884 (16)
//         0041fa58     MOV        BL,byte ptr [EAX + 0x80]
//         0041fa5e     LEA        EDX,[EAX + 0x80]
//         0041fa64     TEST       BL,BL
//         0041fa66     JZ         LAB_0041fa7c
//                              basegame.cpp:2885 (22)
//         0041fa68     MOV        ESI,dword ptr [EAX + 0x188]
//         0041fa6e     MOV        EAX,dword ptr [EAX + 0x184]
//         0041fa74     PUSH       ESI
//         0041fa75     PUSH       EAX
//         0041fa76     PUSH       EDX
//         0041fa77     CALL       TMusic_System::play_file                         int play_file(TMusic_System * this, char * pa
//                               LAB_0041fa7c                                                 XREF[1]:     0041fa66(j)
//         0041fa7c     POP        EBX
//         0041fa7d     POP        ESI
//                              basegame.cpp:2887 (6)
//         0041fa7e     MOV        EAX,0x1
//         0041fa83     POP        EDI
//                              basegame.cpp:2888 (1)
//         0041fa84     RET
//         0041fa85     ??         90h
//         0041fa86     NOP
//         0041fa87     NOP
//         0041fa88     NOP
//         0041fa89     NOP
//         0041fa8a     NOP
//         0041fa8b     NOP
//         0041fa8c     NOP
//         0041fa8d     NOP
//         0041fa8e     NOP
//         0041fa8f     NOP
    return 0;
}

void RGE_Base_Game::shutdown_music_system() {
    /* TODO: Stub */
//                              void __thiscall shutdown_music_system(RGE_Base_Game * this)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?shutdown_music_system@RGE_Base_Game@@UAEXXZ                 XREF[2]:     0056ef2c(*), 00577204(*)
//                               RGE_Base_Game::shutdown_music_system
//                              basegame.cpp:2894 (3)
//         0041fa90     PUSH       ESI
//         0041fa91     MOV        ESI,this
//                              basegame.cpp:2895 (7)
//         0041fa93     MOV        EAX,dword ptr [ESI + 0x64]
//         0041fa96     TEST       EAX,EAX
//         0041fa98     JZ         LAB_0041fae0
//                              basegame.cpp:2898 (9)
//         0041fa9a     MOV        EAX,dword ptr [ESI]
//         0041fa9c     PUSH       EDI
//         0041fa9d     CALL       dword ptr [EAX + 0xac]
//                              basegame.cpp:2899 (30)
//         0041faa3     MOV        this,dword ptr [ESI + 0x64]
//         0041faa6     MOV        EDX,dword ptr [ECX + this+0x254]
//         0041faac     MOV        this,dword ptr [ESI + 0x1ac]
//         0041fab2     NEG        EDX
//         0041fab4     PUSH       EDX
//         0041fab5     PUSH       s_Music_Volume                                   = "Music Volume"
//         0041faba     PUSH       offset DAT_fffffff4
//         0041fabc     CALL       TRegistry::RegSetInt                             int RegSetInt(TRegistry * this, int param_1,
//                              basegame.cpp:2900 (23)
//         0041fac1     MOV        EDI,dword ptr [ESI + 0x64]
//         0041fac4     TEST       EDI,EDI
//         0041fac6     JZ         LAB_0041fad8
//         0041fac8     MOV        this,EDI
//         0041faca     CALL       TMusic_System::~TMusic_System                    void ~TMusic_System(TMusic_System * this)
//         0041facf     PUSH       EDI
//         0041fad0     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0041fad5     ADD        ESP,0x4
//                               LAB_0041fad8                                                 XREF[1]:     0041fac6(j)
//                              basegame.cpp:2901 (8)
//         0041fad8     MOV        dword ptr [ESI + 0x64],0x0
//         0041fadf     POP        EDI
//                               LAB_0041fae0                                                 XREF[1]:     0041fa98(j)
//                              basegame.cpp:2903 (2)
//         0041fae0     POP        ESI
//         0041fae1     RET
//         0041fae2     ??         90h
//         0041fae3     NOP
//         0041fae4     NOP
//         0041fae5     NOP
//         0041fae6     NOP
//         0041fae7     NOP
//         0041fae8     NOP
//         0041fae9     NOP
//         0041faea     NOP
//         0041faeb     NOP
//         0041faec     NOP
//         0041faed     NOP
//         0041faee     NOP
//         0041faef     NOP
    return;
}

void* RGE_Base_Game::make_font(void* param_1, long param_2, int param_3) {
    /* TODO: Stub */
//                              void * __thiscall make_font(RGE_Base_Game * this, void * param_1, lo
//              void *            EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              void *            Stack[0x4]:4   param_1
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0041faf7(R)
//              int               Stack[0xc]:4   param_3
//              char[256]         Stack[-0x104   face_name                 XREF[0,1]:   0041fb02(*)
//              char[10]          Stack[-0x110   point_size_str
//              char[10]          Stack[-0x11c   style
//                               ?make_font@RGE_Base_Game@@IAEPAXPAXJH@Z                      XREF[9]:     setup_fonts:0041f5dc(c),
//                               RGE_Base_Game::make_font                                                  setup_fonts:0041f5ef(c),
//                                                                                                         setup_fonts:0041f5ff(c),
//                                                                                                         setup_fonts:0041f612(c),
//                                                                                                         setup_fonts:0041f622(c),
//                                                                                                         setup_fonts:0041f635(c),
//                                                                                                         setup_fonts:0041f645(c),
//                                                                                                         setup_fonts:0041f655(c),
//                                                                                                         setup_fonts:0041f668(c)
//                              basegame.cpp:2909 (7)
//         0041faf0     SUB        ESP,0x118
//         0041faf6     PUSH       EBX
//                              basegame.cpp:2916 (31)
//         0041faf7     MOV        EBX,dword ptr [ESP + param_2]
//         0041fafe     PUSH       ESI
//         0041faff     MOV        ESI,this
//         0041fb01     PUSH       EDI
//         0041fb02     LEA        this=>face_name[4],[ESP + 0x24]
//         0041fb06     MOV        EAX,dword ptr [ESI]
//         0041fb08     PUSH       0x100
//         0041fb0d     PUSH       this
//         0041fb0e     PUSH       EBX
//         0041fb0f     MOV        EDI,dword ptr [EAX + 0x20]
//         0041fb12     MOV        this,ESI
//         0041fb14     CALL       EDI
//                              basegame.cpp:2917 (8)
//         0041fb16     MOV        AL,byte ptr [ESP + 0x24]
//         0041fb1a     TEST       AL,AL
//         0041fb1c     JNZ        LAB_0041fb2c
//                              basegame.cpp:2918 (2)
//         0041fb1e     XOR        EAX,EAX
//                              basegame.cpp:2930 (12)
//         0041fb20     POP        EDI
//         0041fb21     POP        ESI
//         0041fb22     POP        EBX
//         0041fb23     ADD        ESP,0x118
//         0041fb29     RET        0xc
//                               LAB_0041fb2c                                                 XREF[1]:     0041fb1c(j)
//                              basegame.cpp:2909 (1)
//         0041fb2c     PUSH       EBP
//                              basegame.cpp:2920 (15)
//         0041fb2d     LEA        EDX,[ESP + 0x1c]
//         0041fb31     PUSH       offset DAT_fffffff8
//         0041fb33     LEA        EAX,[EBX + 0x1]
//         0041fb36     PUSH       EDX=>DAT_fffffff4
//         0041fb37     PUSH       EAX=>DAT_fffffff0
//         0041fb38     MOV        this,ESI
//         0041fb3a     CALL       EDI
//                              basegame.cpp:2921 (13)
//         0041fb3c     LEA        this,[ESP + 0x1c]
//         0041fb40     PUSH       this
//         0041fb41     CALL       atoi                                             undefined atoi()
//         0041fb46     ADD        ESP,0x4
//                              basegame.cpp:2923 (17)
//         0041fb49     LEA        EDX,[ESP + 0x10]
//         0041fb4d     ADD        EBX,0x2
//         0041fb50     MOV        this,ESI
//         0041fb52     PUSH       0xa
//         0041fb54     PUSH       EDX=>DAT_fffffff8
//         0041fb55     PUSH       EBX=>DAT_fffffff4
//         0041fb56     MOV        EBP,EAX
//         0041fb58     CALL       EDI
//                              basegame.cpp:2924 (42)
//         0041fb5a     LEA        EAX,[ESP + 0x10]
//         0041fb5e     PUSH       s_B                                              = "B"
//         0041fb63     PUSH       EAX=>DAT_fffffff8
//         0041fb64     CALL       strstr                                           undefined strstr()
//         0041fb69     ADD        ESP,0x8
//         0041fb6c     TEST       EAX,EAX
//         0041fb6e     JNZ        LAB_0041fb8b
//         0041fb70     LEA        this,[ESP + 0x10]
//         0041fb74     PUSH       s_b                                              = "b"
//         0041fb79     PUSH       this=>DAT_fffffff8
//         0041fb7a     CALL       strstr                                           undefined strstr()
//         0041fb7f     ADD        ESP,0x8
//         0041fb82     TEST       EAX,EAX
//                              basegame.cpp:2927 (7)
//         0041fb84     MOV        EAX,0x190
//         0041fb89     JZ         LAB_0041fb90
//                               LAB_0041fb8b                                                 XREF[1]:     0041fb6e(j)
//                              basegame.cpp:2925 (5)
//         0041fb8b     MOV        EAX,0x2bc
//                               LAB_0041fb90                                                 XREF[1]:     0041fb89(j)
//                              basegame.cpp:2929 (31)
//         0041fb90     MOV        EDX,dword ptr [ESP + 0x134]
//         0041fb97     MOV        this,dword ptr [ESP + 0x12c]
//         0041fb9e     PUSH       EDX
//         0041fb9f     PUSH       EAX=>DAT_fffffff8
//         0041fba0     LEA        EAX,[ESP + 0x30]
//         0041fba4     PUSH       EBP=>DAT_fffffff4
//         0041fba5     PUSH       EAX=>DAT_fffffff0
//         0041fba6     PUSH       this
//         0041fba7     MOV        this,ESI
//         0041fba9     CALL       RGE_Base_Game::make_font                         void * make_font(RGE_Base_Game * this, void *
//         0041fbae     POP        EBP
//                              basegame.cpp:2930 (12)
//         0041fbaf     POP        EDI
//         0041fbb0     POP        ESI
//         0041fbb1     POP        EBX
//         0041fbb2     ADD        ESP,0x118
//         0041fbb8     RET        0xc
//         0041fbbb     ??         90h
//         0041fbbc     NOP
//         0041fbbd     NOP
//         0041fbbe     NOP
//         0041fbbf     NOP
    return 0;
}

void* RGE_Base_Game::make_font(void* param_1, char* param_2, int param_3, int param_4, int param_5) {
    /* TODO: Stub */
//                              void * __thiscall make_font(RGE_Base_Game * this, void * param_1, ch
//              void *            EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              void *            Stack[0x4]:4   param_1
//              char *            Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//              int               Stack[0x14]:4  param_5
//              char[256]         Stack[-0x104   str                       XREF[0,1]:   0041fbcb(*)
//              tagLOGFONTA       Stack[-0x140   logfont
//                               ?make_font@RGE_Base_Game@@IAEPAXPAXPADHHH@Z                  XREF[1]:     make_font:0041fba9(c)
//                               RGE_Base_Game::make_font
//                              basegame.cpp:2936 (6)
//         0041fbc0     SUB        ESP,0x13c
//                              basegame.cpp:2941 (20)
//         0041fbc6     MOV        EAX,dword ptr [this->_padding_]
//         0041fbc8     PUSH       EBX
//         0041fbc9     PUSH       ESI
//         0041fbca     PUSH       EDI
//         0041fbcb     LEA        EDX=>str[4],[ESP + 0x48]
//         0041fbcf     PUSH       0x100
//         0041fbd4     PUSH       EDX
//                              language.dll match for 0x65: "1"
//         0041fbd5     PUSH       0x65
//         0041fbd7     CALL       dword ptr [EAX + 0x20]
//                              basegame.cpp:2942 (12)
//         0041fbda     LEA        EAX,[ESP + 0x48]
//         0041fbde     PUSH       EAX
//         0041fbdf     CALL       atoi                                             undefined atoi()
//         0041fbe4     MOV        BL,AL
//                              basegame.cpp:2944 (16)
//         0041fbe6     MOV        this,0xf
//         0041fbeb     XOR        EAX,EAX
//         0041fbed     LEA        EDI,[ESP + 0x10]
//         0041fbf1     ADD        ESP,0x4
//         0041fbf4     STOSD.REP  ES:EDI
//                              basegame.cpp:2947 (18)
//         0041fbf6     MOV        this,dword ptr [ESP + 0x154]
//         0041fbfd     PUSH       0x48
//         0041fbff     PUSH       offset DAT_fffffff8
//         0041fc01     PUSH       this=>DAT_fffffff4
//         0041fc02     CALL       dword ptr [->KERNEL32.DLL::MulDiv]               = 0048aa34
//                              basegame.cpp:2954 (7)
//         0041fc08     MOV        this,byte ptr [ESP + 0x15c]
//                              basegame.cpp:2961 (105)
//         0041fc0f     MOV        EDI,dword ptr [ESP + 0x150]
//         0041fc16     NEG        EAX
//         0041fc18     MOV        dword ptr [ESP + 0xc],EAX
//         0041fc1c     XOR        EAX,EAX
//         0041fc1e     MOV        dword ptr [ESP + 0x10],EAX
//         0041fc22     MOV        dword ptr [ESP + 0x14],EAX
//         0041fc26     MOV        dword ptr [ESP + 0x18],EAX
//         0041fc2a     MOV        byte ptr [ESP + 0x20],AL
//         0041fc2e     MOV        byte ptr [ESP + 0x21],AL
//         0041fc32     MOV        byte ptr [ESP + 0x24],AL
//         0041fc36     MOV        byte ptr [ESP + 0x25],AL
//         0041fc3a     MOV        AL,0x2
//         0041fc3c     MOV        byte ptr [ESP + 0x22],this
//         0041fc40     MOV        byte ptr [ESP + 0x26],AL
//         0041fc44     MOV        byte ptr [ESP + 0x27],AL
//         0041fc48     OR         this,0xffffffff
//         0041fc4b     XOR        EAX,EAX
//         0041fc4d     MOV        EDX,dword ptr [ESP + 0x158]
//         0041fc54     SCASB.RE   ES:EDI
//         0041fc56     NOT        this
//         0041fc58     SUB        EDI,this
//         0041fc5a     MOV        dword ptr [ESP + 0x1c],EDX
//         0041fc5e     LEA        EDX,[ESP + 0x28]
//         0041fc62     MOV        EAX,this
//         0041fc64     MOV        ESI,EDI
//         0041fc66     MOV        EDI,EDX
//         0041fc68     SHR        this,0x2
//         0041fc6b     MOV        byte ptr [ESP + 0x23],BL
//         0041fc6f     MOVSD.REP  ES:EDI,ESI
//         0041fc71     MOV        this,EAX
//         0041fc73     AND        this,0x3
//         0041fc76     MOVSB.REP  ES:EDI,ESI
//                              basegame.cpp:2963 (11)
//         0041fc78     LEA        this,[ESP + 0xc]
//         0041fc7c     PUSH       this
//         0041fc7d     CALL       dword ptr [->GDI32.DLL::CreateFontIndirectA]     = 0048b1a2
//                              basegame.cpp:2964 (12)
//         0041fc83     POP        EDI
//         0041fc84     POP        ESI
//         0041fc85     POP        EBX
//         0041fc86     ADD        ESP,0x13c
//         0041fc8c     RET        0x14
//         0041fc8f     ??         90h
    return 0;
}

int RGE_Base_Game::check_for_cd(int param_1) {
    /* TODO: Stub */
//                              int __thiscall check_for_cd(RGE_Base_Game * this, int param_1)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[2]:     0041fcbb(R), 0041fcfd(R)
//              char[256]         Stack[-0x104   file_sys_name
//              char[256]         Stack[-0x204   vol_name
//              ulong             Stack[-0x208   max_comp_len
//              ulong             Stack[-0x20c   file_sys_flags
//              ulong             Stack[-0x210   vol_ser_num
//                               ?check_for_cd@RGE_Base_Game@@QAEHH@Z                         XREF[9]:     setup:0041be19(c),
//                               RGE_Base_Game::check_for_cd                                               action:0049eece(c),
//                                                                                                         action:0049f002(c),
//                                                                                                         action:004a1917(c),
//                                                                                                         action:004a198d(c),
//                                                                                                         startGame:004a2412(c),
//                                                                                                         startGame:004a2437(c),
//                                                                                                         handle_user_command:004a2edb(c),
//                                                                                                         handle_user_command:004a3433(c)
//                              basegame.cpp:2977 (11)
//         0041fc90     SUB        ESP,0x20c
//         0041fc96     PUSH       EBX
//         0041fc97     MOV        EBX,this
//         0041fc99     PUSH       EBP
//         0041fc9a     PUSH       ESI
//                              basegame.cpp:2985 (14)
//         0041fc9b     MOV        EAX,dword ptr [EBX + 0xc]
//         0041fc9e     PUSH       EDI
//         0041fc9f     MOV        this,dword ptr [EAX + 0x408]
//         0041fca5     TEST       this,this
//         0041fca7     JNZ        LAB_0041fcbb
//                              basegame.cpp:2986 (5)
//         0041fca9     MOV        EAX,0x1
//                              basegame.cpp:3028 (13)
//         0041fcae     POP        EDI
//         0041fcaf     POP        ESI
//         0041fcb0     POP        EBP
//         0041fcb1     POP        EBX
//         0041fcb2     ADD        ESP,0x20c
//         0041fcb8     RET        0x4
//                               LAB_0041fcbb                                                 XREF[1]:     0041fca7(j)
//                              basegame.cpp:2989 (11)
//         0041fcbb     MOV        EAX,dword ptr [ESP + param_1]
//         0041fcc2     TEST       EAX,EAX
//         0041fcc4     JLE        LAB_0041fd19
//                              basegame.cpp:2991 (2)
//         0041fcc6     XOR        EBP,EBP
//                              basegame.cpp:2993 (2)
//         0041fcc8     XOR        ESI,ESI
//                               LAB_0041fcca                                                 XREF[1]:     0041fcf0(j)
//                              basegame.cpp:2995 (20)
//         0041fcca     MOV        this,dword ptr [EBX + 0x18c]
//         0041fcd0     LEA        EDI,[ESI + 0x1]
//         0041fcd3     PUSH       EDI
//         0041fcd4     CALL       TCommunications_Handler::GetPlayerHumanity       int GetPlayerHumanity(TCommunications_Handler
//         0041fcd9     CMP        EAX,0x2
//         0041fcdc     JNZ        LAB_0041fceb
//                              basegame.cpp:2997 (12)
//         0041fcde     PUSH       ESI
//         0041fcdf     MOV        this,EBX
//         0041fce1     CALL       RGE_Base_Game::playerHasCD                       int playerHasCD(RGE_Base_Game * this, int par
//         0041fce6     TEST       EAX,EAX
//         0041fce8     JZ         LAB_0041fceb
//                              basegame.cpp:2998 (1)
//         0041fcea     INC        EBP
//                               LAB_0041fceb                                                 XREF[2]:     0041fcdc(j), 0041fce8(j)
//                              basegame.cpp:2993 (7)
//         0041fceb     MOV        ESI,EDI
//         0041fced     CMP        ESI,0x9
//         0041fcf0     JL         LAB_0041fcca
//                              basegame.cpp:3001 (26)
//         0041fcf2     MOV        this,dword ptr [EBX + 0xc]
//         0041fcf5     XOR        EAX,EAX
//         0041fcf7     MOV        EDX,dword ptr [ECX + this+0x40c]
//         0041fcfd     MOV        this,dword ptr [ESP + param_1]
//         0041fd04     IMUL       EDX,EBP
//         0041fd07     CMP        this,EDX
//         0041fd09     SETLE      AL
//                              basegame.cpp:3028 (13)
//         0041fd0c     POP        EDI
//         0041fd0d     POP        ESI
//         0041fd0e     POP        EBP
//         0041fd0f     POP        EBX
//         0041fd10     ADD        ESP,0x20c
//         0041fd16     RET        0x4
//                               LAB_0041fd19                                                 XREF[1]:     0041fcc4(j)
//                              basegame.cpp:3008 (9)
//         0041fd19     MOV        EAX,[force_cd]
//         0041fd1e     TEST       EAX,EAX
//         0041fd20     JZ         LAB_0041fd34
//                              basegame.cpp:3009 (5)
//         0041fd22     MOV        EAX,0x1
//                              basegame.cpp:3028 (13)
//         0041fd27     POP        EDI
//         0041fd28     POP        ESI
//         0041fd29     POP        EBP
//         0041fd2a     POP        EBX
//         0041fd2b     ADD        ESP,0x20c
//         0041fd31     RET        0x4
//                               LAB_0041fd34                                                 XREF[1]:     0041fd20(j)
//                              basegame.cpp:3011 (20)
//         0041fd34     MOV        this,dword ptr [EBX + 0x1ac]
//         0041fd3a     PUSH       s_CDPath                                         = "CDPath"
//         0041fd3f     PUSH       0x0
//         0041fd41     CALL       TRegistry::RegGetAscii                           char * RegGetAscii(TRegistry * this, int para
//         0041fd46     MOV        ESI,EAX
//                              basegame.cpp:3012 (4)
//         0041fd48     TEST       ESI,ESI
//         0041fd4a     JNZ        LAB_0041fd59
//                              basegame.cpp:3028 (13)
//         0041fd4c     POP        EDI
//         0041fd4d     POP        ESI
//         0041fd4e     POP        EBP
//         0041fd4f     POP        EBX
//         0041fd50     ADD        ESP,0x20c
//         0041fd56     RET        0x4
//                               LAB_0041fd59                                                 XREF[1]:     0041fd4a(j)
//                              basegame.cpp:3015 (12)
//         0041fd59     PUSH       ESI
//         0041fd5a     CALL       dword ptr [->KERNEL32.DLL::GetDriveTypeA]        = 0048aa56
//         0041fd60     CMP        EAX,0x5
//         0041fd63     JZ         LAB_0041fd74
//                              basegame.cpp:3016 (2)
//         0041fd65     XOR        EAX,EAX
//                              basegame.cpp:3028 (13)
//         0041fd67     POP        EDI
//         0041fd68     POP        ESI
//         0041fd69     POP        EBP
//         0041fd6a     POP        EBX
//         0041fd6b     ADD        ESP,0x20c
//         0041fd71     RET        0x4
//                               LAB_0041fd74                                                 XREF[1]:     0041fd63(j)
//                              basegame.cpp:3018 (49)
//         0041fd74     LEA        EAX,[ESP + 0x11c]
//         0041fd7b     PUSH       0x100
//         0041fd80     LEA        this,[ESP + 0x18]
//         0041fd84     PUSH       EAX=>DAT_fffffff8
//         0041fd85     LEA        EDX,[ESP + 0x20]
//         0041fd89     PUSH       this=>DAT_fffffff4
//         0041fd8a     LEA        EAX,[ESP + 0x1c]
//         0041fd8e     PUSH       EDX=>DAT_fffffff0
//         0041fd8f     PUSH       EAX
//         0041fd90     LEA        this,[ESP + 0x30]
//         0041fd94     PUSH       0x100
//         0041fd99     PUSH       this
//         0041fd9a     PUSH       ESI
//         0041fd9b     CALL       dword ptr [->KERNEL32.DLL::GetVolumeInformatio   = 0048aa3e
//         0041fda1     TEST       EAX,EAX
//         0041fda3     JNZ        LAB_0041fdb2
//                              basegame.cpp:3028 (13)
//         0041fda5     POP        EDI
//         0041fda6     POP        ESI
//         0041fda7     POP        EBP
//         0041fda8     POP        EBX
//         0041fda9     ADD        ESP,0x20c
//         0041fdaf     RET        0x4
//                               LAB_0041fdb2                                                 XREF[1]:     0041fda3(j)
//                              basegame.cpp:3021 (25)
//         0041fdb2     MOV        EDX,dword ptr [EBX + 0xc]
//         0041fdb5     LEA        EAX,[ESP + 0x1c]
//         0041fdb9     ADD        EDX,0x2fd
//         0041fdbf     PUSH       EDX
//         0041fdc0     PUSH       EAX=>DAT_fffffff8
//         0041fdc1     CALL       stricmp                                          undefined stricmp()
//         0041fdc6     ADD        ESP,0x8
//         0041fdc9     NEG        EAX
//                              basegame.cpp:3028 (16)
//         0041fdcb     POP        EDI
//         0041fdcc     POP        ESI
//         0041fdcd     SBB        EAX,EAX
//         0041fdcf     POP        EBP
//         0041fdd0     INC        EAX
//         0041fdd1     POP        EBX
//         0041fdd2     ADD        ESP,0x20c
//         0041fdd8     RET        0x4
//         0041fddb     ??         90h
//         0041fddc     NOP
//         0041fddd     NOP
//         0041fdde     NOP
//         0041fddf     NOP
    return 0;
}

int RGE_Base_Game::check_expiration() {
    /* TODO: Stub */
//                              int __thiscall check_expiration(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              tm                Stack[-0x28]   kill_def                  XREF[2,5]:   0041fe26(*), 0041fe32(R), 0041fdee(*), 0041fe03(*),
//                                                                                     0041fe0e(W), 0041fdff(W), 0041fe1a(W)
//              long              Stack[-0x2c]:4 cur_date
//                               ?check_expiration@RGE_Base_Game@@IAEHXZ                      XREF[1]:     setup:0041bd65(c)
//                               RGE_Base_Game::check_expiration
//                              basegame.cpp:3034 (7)
//         0041fde0     SUB        ESP,0x28
//         0041fde3     PUSH       ESI
//         0041fde4     MOV        EDX,this
//         0041fde6     PUSH       EDI
//                              basegame.cpp:3039 (13)
//         0041fde7     MOV        this,0x9
//         0041fdec     XOR        EAX,EAX
//         0041fdee     LEA        EDI=>kill_def.tm_min,[ESP + 0xc]
//         0041fdf2     STOSD.REP  ES:EDI
//                              basegame.cpp:3040 (15)
//         0041fdf4     MOV        EAX,dword ptr [EDX + 0xc]
//         0041fdf7     MOVSX      this,word ptr [EAX + 0x880]
//         0041fdfe     DEC        this
//         0041fdff     MOV        dword ptr [ESP + kill_def.tm_year],this
//                              basegame.cpp:3043 (35)
//         0041fe03     LEA        this=>kill_def.tm_min,[ESP + 0xc]
//         0041fe07     MOVSX      EDX,word ptr [EAX + 0x882]
//         0041fe0e     MOV        dword ptr [ESP + kill_def.tm_mon],EDX
//         0041fe12     PUSH       this
//         0041fe13     MOVSX      EAX,word ptr [EAX + 0x884]
//         0041fe1a     MOV        dword ptr [ESP + kill_def.tm_wday],EAX
//         0041fe1e     CALL       mktime                                           undefined mktime()
//         0041fe23     ADD        ESP,0x4
//                              basegame.cpp:3045 (12)
//         0041fe26     LEA        EDX=>kill_def,[ESP + 0x8]
//         0041fe2a     MOV        ESI,EAX
//         0041fe2c     PUSH       EDX
//         0041fe2d     CALL       time                                             undefined time()
//                              basegame.cpp:3047 (11)
//         0041fe32     MOV        this,dword ptr [ESP + kill_def.tm_sec]
//         0041fe36     ADD        ESP,0x4
//         0041fe39     XOR        EAX,EAX
//         0041fe3b     CMP        this,ESI
//                              basegame.cpp:3051 (9)
//         0041fe3d     POP        EDI
//         0041fe3e     POP        ESI
//         0041fe3f     SETLE      AL
//         0041fe42     ADD        ESP,0x28
//         0041fe45     RET
//         0041fe46     ??         90h
//         0041fe47     NOP
//         0041fe48     NOP
//         0041fe49     NOP
//         0041fe4a     NOP
//         0041fe4b     NOP
//         0041fe4c     NOP
//         0041fe4d     NOP
//         0041fe4e     NOP
//         0041fe4f     NOP
    return 0;
}

int RGE_Base_Game::check_multi_copies() {
    /* TODO: Stub */
//                              int __thiscall check_multi_copies(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?check_multi_copies@RGE_Base_Game@@IAEHXZ                    XREF[1]:     setup:0041bd89(c)
//                               RGE_Base_Game::check_multi_copies
//                              basegame.cpp:3057 (4)
//         0041fe50     PUSH       ESI
//         0041fe51     MOV        ESI,this
//         0041fe53     PUSH       EDI
//                              basegame.cpp:3060 (17)
//         0041fe54     MOV        EAX,dword ptr [ESI + 0xc]
//         0041fe57     PUSH       EAX
//         0041fe58     PUSH       0x1
//         0041fe5a     PUSH       0x0
//         0041fe5c     CALL       dword ptr [->KERNEL32.DLL::CreateMutexA]         = 0048aa86
//         0041fe62     MOV        dword ptr [ESI + 0x20],EAX
//                              basegame.cpp:3061 (17)
//         0041fe65     CALL       dword ptr [->KERNEL32.DLL::GetLastError]         = 0048aa76
//         0041fe6b     CMP        EAX,0xb7
//         0041fe70     JNZ        LAB_0041ff0a
//                              basegame.cpp:3063 (16)
//         0041fe76     MOV        EAX,dword ptr [ESI + 0xc]
//         0041fe79     LEA        this,[EAX + 0x7a]
//         0041fe7c     PUSH       this
//         0041fe7d     PUSH       EAX=>DAT_fffffff8
//         0041fe7e     CALL       dword ptr [->USER32.DLL::FindWindowA]            = 0048ad18
//         0041fe84     MOV        EDI,EAX
//                              basegame.cpp:3064 (4)
//         0041fe86     TEST       EDI,EDI
//         0041fe88     JZ         LAB_0041fee6
//                              basegame.cpp:3066 (16)
//         0041fe8a     PUSH       s_LOBBY                                          = "LOBBY"
//         0041fe8f     MOV        this,ESI
//         0041fe91     CALL       RGE_Base_Game::check_prog_argument               uchar check_prog_argument(RGE_Base_Game * thi
//         0041fe96     TEST       AL,AL
//         0041fe98     JZ         LAB_0041febd
//                              basegame.cpp:3068 (13)
//         0041fe9a     PUSH       0x0
//         0041fe9c     PUSH       0x0=>DAT_fffffff8
//         0041fe9e     PUSH       offset DAT_fffffff4
//         0041fea0     PUSH       EDI=>DAT_fffffff0
//         0041fea1     CALL       dword ptr [->USER32.DLL::SendMessageA]           = 0048ad08
//                              basegame.cpp:3069 (7)
//         0041fea7     MOV        ESI,dword ptr [ESI + 0x20]
//         0041feaa     TEST       ESI,ESI
//         0041feac     JZ         LAB_0041ff18
//                              basegame.cpp:3092 (7)
//         0041feae     PUSH       ESI
//         0041feaf     CALL       dword ptr [->KERNEL32.DLL::ReleaseMutex]         = 0048aa66
//                              basegame.cpp:3093 (5)
//         0041feb5     MOV        EAX,0x1
//                              basegame.cpp:3095 (3)
//         0041feba     POP        EDI
//         0041febb     POP        ESI
//         0041febc     RET
//                               LAB_0041febd                                                 XREF[1]:     0041fe98(j)
//                              basegame.cpp:3075 (11)
//         0041febd     PUSH       EDI
//         0041febe     CALL       dword ptr [->USER32.DLL::IsIconic]               = 0048ae70
//         0041fec4     TEST       EAX,EAX
//         0041fec6     JZ         LAB_0041fed1
//                              basegame.cpp:3076 (9)
//         0041fec8     PUSH       0x1
//         0041feca     PUSH       EDI=>DAT_fffffff8
//         0041fecb     CALL       dword ptr [->USER32.DLL::ShowWindow]             = 0048ace2
//                               LAB_0041fed1                                                 XREF[1]:     0041fec6(j)
//                              basegame.cpp:3077 (7)
//         0041fed1     PUSH       EDI
//         0041fed2     CALL       dword ptr [->USER32.DLL::SetForegroundWindow]    = 0048ae5a
//                              basegame.cpp:3078 (14)
//         0041fed8     PUSH       EDI
//         0041fed9     CALL       dword ptr [->USER32.DLL::GetLastActivePopup]     = 0048ae44
//         0041fedf     PUSH       EAX
//         0041fee0     CALL       dword ptr [->USER32.DLL::BringWindowToTop]       = 0048ae30
//                               LAB_0041fee6                                                 XREF[1]:     0041fe88(j)
//                              basegame.cpp:3081 (7)
//         0041fee6     MOV        EAX,dword ptr [ESI + 0x20]
//         0041fee9     TEST       EAX,EAX
//         0041feeb     JZ         LAB_0041ff05
//                              basegame.cpp:3083 (7)
//         0041feed     PUSH       EAX
//         0041feee     CALL       dword ptr [->KERNEL32.DLL::ReleaseMutex]         = 0048aa66
//                              basegame.cpp:3084 (10)
//         0041fef4     MOV        EDX,dword ptr [ESI + 0x20]
//         0041fef7     PUSH       EDX
//         0041fef8     CALL       dword ptr [->KERNEL32.DLL::CloseHandle]          = 0048aa26
//                              basegame.cpp:3085 (7)
//         0041fefe     MOV        dword ptr [ESI + 0x20],0x0
//                               LAB_0041ff05                                                 XREF[1]:     0041feeb(j)
//                              basegame.cpp:3087 (2)
//         0041ff05     XOR        EAX,EAX
//                              basegame.cpp:3095 (3)
//         0041ff07     POP        EDI
//         0041ff08     POP        ESI
//         0041ff09     RET
//                               LAB_0041ff0a                                                 XREF[1]:     0041fe70(j)
//                              basegame.cpp:3091 (7)
//         0041ff0a     MOV        ESI,dword ptr [ESI + 0x20]
//         0041ff0d     TEST       ESI,ESI
//         0041ff0f     JZ         LAB_0041ff18
//                              basegame.cpp:3092 (7)
//         0041ff11     PUSH       ESI
//         0041ff12     CALL       dword ptr [->KERNEL32.DLL::ReleaseMutex]         = 0048aa66
//                               LAB_0041ff18                                                 XREF[2]:     0041feac(j), 0041ff0f(j)
//                              basegame.cpp:3095 (8)
//         0041ff18     POP        EDI
//         0041ff19     MOV        EAX,0x1
//         0041ff1e     POP        ESI
//         0041ff1f     RET
    return 0;
}

int RGE_Base_Game::check_paint() {
    /* TODO: Stub */
//                              int __thiscall check_paint(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              tagRECT           Stack[-0x14]   update_rect
//              uchar             Stack[-0x18]:1 surface_status
//                               ?check_paint@RGE_Base_Game@@IAEHXZ                           XREF[2]:     handle_paint:0042140a(c),
//                               RGE_Base_Game::check_paint                                                shutdown_video_system:0052a497(c)
//                              basegame.cpp:3101 (6)
//         0041ff20     SUB        ESP,0x14
//         0041ff23     PUSH       ESI
//         0041ff24     MOV        ESI,this
//                              basegame.cpp:3106 (7)
//         0041ff26     MOV        EAX,dword ptr [ESI + 0x14]
//         0041ff29     TEST       EAX,EAX
//         0041ff2b     JNZ        LAB_0041ff45
//                              basegame.cpp:3108 (5)
//         0041ff2d     CALL       RGE_Base_Game::clear_window                      void clear_window(RGE_Base_Game * this)
//                              basegame.cpp:3109 (12)
//         0041ff32     MOV        EAX,dword ptr [ESI + 0x10]
//         0041ff35     PUSH       0x0
//         0041ff37     PUSH       EAX
//         0041ff38     CALL       dword ptr [->USER32.DLL::ValidateRect]           = 0048ae8c
//                              basegame.cpp:3140 (2)
//         0041ff3e     XOR        EAX,EAX
//                              basegame.cpp:3149 (5)
//         0041ff40     POP        ESI
//         0041ff41     ADD        ESP,0x14
//         0041ff44     RET
//                               LAB_0041ff45                                                 XREF[1]:     0041ff2b(j)
//                              basegame.cpp:3114 (14)
//         0041ff45     MOV        this,dword ptr [ESI + 0x10]
//         0041ff48     PUSH       this
//         0041ff49     CALL       dword ptr [->USER32.DLL::IsIconic]               = 0048ae70
//         0041ff4f     TEST       EAX,EAX
//         0041ff51     JZ         LAB_0041ff66
//                              basegame.cpp:3116 (12)
//         0041ff53     MOV        EDX,dword ptr [ESI + 0x10]
//         0041ff56     PUSH       0x0
//         0041ff58     PUSH       EDX
//         0041ff59     CALL       dword ptr [->USER32.DLL::ValidateRect]           = 0048ae8c
//                              basegame.cpp:3140 (2)
//         0041ff5f     XOR        EAX,EAX
//                              basegame.cpp:3149 (5)
//         0041ff61     POP        ESI
//         0041ff62     ADD        ESP,0x14
//         0041ff65     RET
//                               LAB_0041ff66                                                 XREF[1]:     0041ff51(j)
//                              basegame.cpp:3121 (7)
//         0041ff66     MOV        EAX,dword ptr [ESI + 0x18]
//         0041ff69     TEST       EAX,EAX
//         0041ff6b     JNZ        LAB_0041ffa2
//                              basegame.cpp:3123 (21)
//         0041ff6d     MOV        this,dword ptr [ESI + 0x10]
//         0041ff70     LEA        EAX,[ESP + 0x8]
//         0041ff74     PUSH       0x0
//         0041ff76     PUSH       EAX
//         0041ff77     PUSH       this
//         0041ff78     CALL       dword ptr [->USER32.DLL::GetUpdateRect]          = 0048ae7c
//         0041ff7e     TEST       EAX,EAX
//         0041ff80     JZ         LAB_0041ff8f
//                              basegame.cpp:3124 (13)
//         0041ff82     MOV        this,dword ptr [ESI + 0x48]
//         0041ff85     LEA        EDX,[ESP + 0x8]
//         0041ff89     PUSH       EDX
//         0041ff8a     CALL       TDrawSystem::Paint                               void Paint(TDrawSystem * this, tagRECT * para
//                               LAB_0041ff8f                                                 XREF[1]:     0041ff80(j)
//                              basegame.cpp:3125 (12)
//         0041ff8f     MOV        EAX,dword ptr [ESI + 0x10]
//         0041ff92     PUSH       0x0
//         0041ff94     PUSH       EAX
//         0041ff95     CALL       dword ptr [->USER32.DLL::ValidateRect]           = 0048ae8c
//                              basegame.cpp:3140 (2)
//         0041ff9b     XOR        EAX,EAX
//                              basegame.cpp:3149 (5)
//         0041ff9d     POP        ESI
//         0041ff9e     ADD        ESP,0x14
//         0041ffa1     RET
//                               LAB_0041ffa2                                                 XREF[1]:     0041ff6b(j)
//                              basegame.cpp:3130 (12)
//         0041ffa2     MOV        this,dword ptr [ESI + 0x48]
//         0041ffa5     CALL       TDrawSystem::CheckSurfaces                       uchar CheckSurfaces(TDrawSystem * this)
//         0041ffaa     MOV        byte ptr [ESP + 0x4],AL
//                              basegame.cpp:3132 (18)
//         0041ffae     MOV        EAX,dword ptr [ESP + 0x4]
//         0041ffb2     AND        EAX,0xff
//         0041ffb7     DEC        EAX
//         0041ffb8     JZ         LAB_0041fff6
//         0041ffba     DEC        EAX
//         0041ffbb     JZ         LAB_0041ffdd
//         0041ffbd     DEC        EAX
//         0041ffbe     JNZ        LAB_0041ffec
//                              basegame.cpp:3135 (12)
//         0041ffc0     MOV        this,dword ptr [ESI + 0x10]
//         0041ffc3     PUSH       0x0
//         0041ffc5     PUSH       this
//         0041ffc6     CALL       dword ptr [->USER32.DLL::ValidateRect]           = 0048ae8c
//                              basegame.cpp:3136 (10)
//         0041ffcc     MOV        EDX,dword ptr [ESI + 0x10]
//         0041ffcf     PUSH       EDX
//         0041ffd0     CALL       dword ptr [->USER32.DLL::DestroyWindow]          = 0048ad26
//                              basegame.cpp:3140 (2)
//         0041ffd6     XOR        EAX,EAX
//                              basegame.cpp:3149 (5)
//         0041ffd8     POP        ESI
//         0041ffd9     ADD        ESP,0x14
//         0041ffdc     RET
//                               LAB_0041ffdd                                                 XREF[1]:     0041ffbb(j)
//                              basegame.cpp:3143 (8)
//         0041ffdd     MOV        this,dword ptr [ESI + 0x48]
//         0041ffe0     CALL       TDrawSystem::ClearRestored                       void ClearRestored(TDrawSystem * this)
//                              basegame.cpp:3144 (7)
//         0041ffe5     MOV        this,ESI
//         0041ffe7     CALL       RGE_Base_Game::set_render_all                    void set_render_all(RGE_Base_Game * this)
//                               LAB_0041ffec                                                 XREF[1]:     0041ffbe(j)
//                              basegame.cpp:3148 (5)
//         0041ffec     MOV        EAX,0x1
//                              basegame.cpp:3149 (5)
//         0041fff1     POP        ESI
//         0041fff2     ADD        ESP,0x14
//         0041fff5     RET
//                               LAB_0041fff6                                                 XREF[1]:     0041ffb8(j)
//                              basegame.cpp:3140 (2)
//         0041fff6     XOR        EAX,EAX
//                              basegame.cpp:3149 (5)
//         0041fff8     POP        ESI
//         0041fff9     ADD        ESP,0x14
//         0041fffc     RET
//         0041fffd     ??         90h
//         0041fffe     NOP
//         0041ffff     NOP
    return 0;
}

void RGE_Base_Game::clear_window() {
    /* TODO: Stub */
//                              void __thiscall clear_window(RGE_Base_Game * this)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              tagRECT           Stack[-0x14]   rect
//                               ?clear_window@RGE_Base_Game@@IAEXXZ                          XREF[2]:     check_paint:0041ff2d(c),
//                               RGE_Base_Game::clear_window                                               handle_paint:0042161a(c)
//                              basegame.cpp:3155 (6)
//         00420000     SUB        ESP,0x10
//         00420003     PUSH       EDI
//         00420004     MOV        EDI,this
//                              basegame.cpp:3160 (8)
//         00420006     MOV        EAX,dword ptr [EDI + 0x10]
//         00420009     TEST       EAX,EAX
//         0042000b     JZ         LAB_00420047
//         0042000d     PUSH       ESI
//                              basegame.cpp:3162 (7)
//         0042000e     PUSH       EAX
//         0042000f     CALL       dword ptr [->USER32.DLL::GetDC]                  = 0048ae28
//                              basegame.cpp:3163 (17)
//         00420015     MOV        this,dword ptr [EDI + 0x10]
//         00420018     MOV        ESI,EAX
//         0042001a     LEA        EAX,[ESP + 0x8]
//         0042001e     PUSH       EAX
//         0042001f     PUSH       this
//         00420020     CALL       dword ptr [->USER32.DLL::GetClientRect]          = 0048add6
//                              basegame.cpp:3164 (8)
//         00420026     PUSH       0x4
//         00420028     CALL       dword ptr [->GDI32.DLL::GetStockObject]          = 0048b1b8
//                              basegame.cpp:3165 (13)
//         0042002e     LEA        EDX,[ESP + 0x8]
//         00420032     PUSH       EAX
//         00420033     PUSH       EDX
//         00420034     PUSH       ESI
//         00420035     CALL       dword ptr [->USER32.DLL::FillRect]               = 0048ae9c
//                              basegame.cpp:3166 (12)
//         0042003b     MOV        EAX,dword ptr [EDI + 0x10]
//         0042003e     PUSH       ESI
//         0042003f     PUSH       EAX
//         00420040     CALL       dword ptr [->USER32.DLL::ReleaseDC]              = 0048ae1c
//         00420046     POP        ESI
//                               LAB_00420047                                                 XREF[1]:     0042000b(j)
//                              basegame.cpp:3168 (5)
//         00420047     POP        EDI
//         00420048     ADD        ESP,0x10
//         0042004b     RET
//         0042004c     ??         90h
//         0042004d     NOP
//         0042004e     NOP
//         0042004f     NOP
    return;
}

RGE_Game_World* RGE_Base_Game::create_world() {
    /* TODO: Stub */
//                              RGE_Game_World * __thiscall create_world(RGE_Base_Game * this)
//              RGE_Game_World    EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00420079(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0042008a(R), 00420099(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00420073(*)
//                               ?create_world@RGE_Base_Game@@MAEPAVRGE_Game_World@@XZ        XREF[1]:     0056ef84(*)
//                               RGE_Base_Game::create_world
//                              basegame.cpp:3174 (22)
//         00420050     PUSH       -0x1
//         00420052     PUSH       FUN_0055cbfb
//         00420057     MOV        EAX,FS:[0x0]
//         0042005d     PUSH       EAX
//         0042005e     MOV        dword ptr FS:[0x0],ESP
//         00420065     PUSH       this
//                              basegame.cpp:3175 (36)
//         00420066     PUSH       0x104
//         0042006b     CALL       operator_new                                     void * operator_new(uint param_1)
//         00420070     ADD        ESP,0x4
//         00420073     MOV        dword ptr [ESP]=>local_10,EAX
//         00420077     TEST       EAX,EAX
//         00420079     MOV        dword ptr [ESP + local_4],0x0
//         00420081     JZ         LAB_00420099
//         00420083     MOV        this,EAX
//         00420085     CALL       RGE_Game_World::RGE_Game_World                   undefined RGE_Game_World(RGE_Game_World * this)
//                              basegame.cpp:3176 (32)
//         0042008a     MOV        this,dword ptr [ESP + local_c]
//         0042008e     MOV        dword ptr FS:[0x0],this
//         00420095     ADD        ESP,0x10
//         00420098     RET
//                               LAB_00420099                                                 XREF[1]:     00420081(j)
//         00420099     MOV        this,dword ptr [ESP + local_c]
//         0042009d     XOR        EAX,EAX
//         0042009f     MOV        dword ptr FS:[0x0],this
//         004200a6     ADD        ESP,0x10
//         004200a9     RET
//         004200aa     ??         90h
//         004200ab     NOP
//         004200ac     NOP
//         004200ad     NOP
//         004200ae     NOP
//         004200af     NOP
    return 0;
}

void RGE_Base_Game::close() {
    /* TODO: Stub */
//                              void __thiscall close(RGE_Base_Game * this)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?close@RGE_Base_Game@@QAEXXZ                                 XREF[29]:    action:0048f452(c),
//                               RGE_Base_Game::close                                                      action:0048f4bd(c),
//                                                                                                         action:004910e4(c),
//                                                                                                         handle_game_update:00497097(c),
//                                                                                                         action:0049852c(c),
//                                                                                                         close_screen:0049d91d(c),
//                                                                                                         action:0049f09a(c),
//                                                                                                         action:0049fe7b(c),
//                                                                                                         action:004a1b08(c),
//                                                                                                         cancelScreen:004a2cc2(c),
//                                                                                                         action:004a6140(c),
//                                                                                                         save_for_scenario_editor:004a8121(
//                                                                                                         command_quit:004ad6db(c),
//                                                                                                         command_save:004ad8c7(c),
//                                                                                                         action:004b3387(c),
//                                                                                                         setup:00521e76(c),
//                                                                                                         quit_game:0052423d(c),
//                                                                                                         quit_game:005242f5(c),
//                                                                                                         quit_game:0052430d(c),
//                                                                                                         restart_game:005244e4(c), [more]
//                              basegame.cpp:3182 (16)
//         004200b0     MOV        EAX,dword ptr [ECX + this->prog_window]
//         004200b3     PUSH       0x0
//         004200b5     PUSH       0x0
//         004200b7     PUSH       0x10
//         004200b9     PUSH       EAX
//         004200ba     CALL       dword ptr [->USER32.DLL::SendMessageA]           = 0048ad08
//                              basegame.cpp:3184 (1)
//         004200c0     RET
//         004200c1     ??         90h
//         004200c2     NOP
//         004200c3     NOP
//         004200c4     NOP
//         004200c5     NOP
//         004200c6     NOP
//         004200c7     NOP
//         004200c8     NOP
//         004200c9     NOP
//         004200ca     NOP
//         004200cb     NOP
//         004200cc     NOP
//         004200cd     NOP
//         004200ce     NOP
//         004200cf     NOP
    return;
}

int RGE_Base_Game::create_dialog(TPanel** param_1, TPanel* param_2) {
    /* TODO: Stub */
//                              int __thiscall create_dialog(RGE_Base_Game * this, TPanel * * param_
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              TPanel * *        Stack[0x4]:4   param_1                   XREF[1]:     004200d0(R)
//              TPanel *          Stack[0x8]:4   param_2                   XREF[1]:     004200d4(R)
//                               ?create_dialog@RGE_Base_Game@@QAEHPAPAVTPanel@@PAV2@@Z
//                               RGE_Base_Game::create_dialog
//                              basegame.cpp:3190 (4)
//         004200d0     MOV        EAX,dword ptr [ESP + param_1]
//                              basegame.cpp:3193 (14)
//         004200d4     MOV        this,dword ptr [ESP + param_2]
//         004200d8     TEST       this,this
//         004200da     MOV        dword ptr [EAX],0x0
//         004200e0     JNZ        LAB_004200e7
//                              basegame.cpp:3194 (2)
//         004200e2     XOR        EAX,EAX
//                              basegame.cpp:3205 (3)
//         004200e4     RET        0x8
//                               LAB_004200e7                                                 XREF[1]:     004200e0(j)
//                              basegame.cpp:3196 (10)
//         004200e7     MOV        EDX,dword ptr [ECX + this+0xd8]
//         004200ed     TEST       EDX,EDX
//         004200ef     JZ         LAB_004200fc
//                              basegame.cpp:3198 (6)
//         004200f1     MOV        EAX,dword ptr [this->_padding_]
//         004200f3     PUSH       0x1
//         004200f5     CALL       dword ptr [EAX]
//                              basegame.cpp:3199 (2)
//         004200f7     XOR        EAX,EAX
//                              basegame.cpp:3205 (3)
//         004200f9     RET        0x8
//                               LAB_004200fc                                                 XREF[1]:     004200ef(j)
//                              basegame.cpp:3202 (2)
//         004200fc     MOV        dword ptr [EAX],this
//                              basegame.cpp:3204 (5)
//         004200fe     MOV        EAX,0x1
//                              basegame.cpp:3205 (3)
//         00420103     RET        0x8
//         00420106     ??         90h
//         00420107     NOP
//         00420108     NOP
//         00420109     NOP
//         0042010a     NOP
//         0042010b     NOP
//         0042010c     NOP
//         0042010d     NOP
//         0042010e     NOP
//         0042010f     NOP
    return 0;
}

void RGE_Base_Game::delete_dialog(TPanel** param_1) {
    /* TODO: Stub */
//                              void __thiscall delete_dialog(RGE_Base_Game * this, TPanel * * param
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              TPanel * *        Stack[0x4]:4   param_1                   XREF[1]:     00420111(R)
//                               ?delete_dialog@RGE_Base_Game@@QAEXPAPAVTPanel@@@Z            XREF[3]:     action:0048a1fd(c),
//                               RGE_Base_Game::delete_dialog                                              action:0048a29c(c),
//                                                                                                         action:0048a2d5(c)
//                              basegame.cpp:3211 (1)
//         00420110     PUSH       ESI
//                              basegame.cpp:3212 (10)
//         00420111     MOV        ESI,dword ptr [ESP + param_1]
//         00420115     MOV        this,dword ptr [ESI]
//         00420117     TEST       this,this
//         00420119     JZ         LAB_00420127
//                              basegame.cpp:3214 (6)
//         0042011b     MOV        EAX,dword ptr [this->_padding_]
//         0042011d     PUSH       0x1
//         0042011f     CALL       dword ptr [EAX]
//                              basegame.cpp:3215 (6)
//         00420121     MOV        dword ptr [ESI],0x0
//                               LAB_00420127                                                 XREF[1]:     00420119(j)
//                              basegame.cpp:3217 (4)
//         00420127     POP        ESI
//         00420128     RET        0x4
//         0042012b     ??         90h
//         0042012c     NOP
//         0042012d     NOP
//         0042012e     NOP
//         0042012f     NOP
    return;
}

void RGE_Base_Game::set_game_mode(int param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall set_game_mode(RGE_Base_Game * this, int param_1, int
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00420130(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00420134(R)
//                               ?set_game_mode@RGE_Base_Game@@UAEXHH@Z                       XREF[2]:     set_game_mode:005227e6(c),
//                               RGE_Base_Game::set_game_mode                                              0056eee0(*)
//                              basegame.cpp:3223 (4)
//         00420130     MOV        EAX,dword ptr [ESP + param_1]
//                              basegame.cpp:3225 (16)
//         00420134     MOV        EDX,dword ptr [ESP + param_2]
//         00420138     MOV        dword ptr [ECX + this->game_mode],EAX
//         0042013e     MOV        dword ptr [ECX + this->sub_game_mode],EDX
//                              basegame.cpp:3226 (3)
//         00420144     RET        0x8
//         00420147     ??         90h
//         00420148     NOP
//         00420149     NOP
//         0042014a     NOP
//         0042014b     NOP
//         0042014c     NOP
//         0042014d     NOP
//         0042014e     NOP
//         0042014f     NOP
    return;
}

void RGE_Base_Game::set_player(short param_1) {
    /* TODO: Stub */
//                              void __thiscall set_player(RGE_Base_Game * this, short param_1)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     0042015a(R)
//                               ?set_player@RGE_Base_Game@@UAEXF@Z                           XREF[2]:     set_player:0052282d(c),
//                               RGE_Base_Game::set_player                                                 0056eee4(*)
//                              basegame.cpp:3232 (10)
//         00420150     MOV        EAX,dword ptr [ECX + this->world]
//         00420156     TEST       EAX,EAX
//         00420158     JZ         LAB_00420177
//                              basegame.cpp:3235 (11)
//         0042015a     MOV        DX,word ptr [ESP + param_1]
//         0042015f     CMP        DX,word ptr [EAX + 0x3c]
//         00420163     JGE        LAB_00420177
//                              basegame.cpp:3237 (4)
//         00420165     MOV        word ptr [EAX + 0x7c],DX
//                              basegame.cpp:3238 (14)
//         00420169     MOV        EAX,dword ptr [ECX + this->world]
//         0042016f     MOV        this,dword ptr [EAX + 0x28]
//         00420172     CALL       RGE_Map::clear_map_view_info                     void clear_map_view_info(RGE_Map * this)
//                               LAB_00420177                                                 XREF[2]:     00420158(j), 00420163(j)
//                              basegame.cpp:3241 (3)
//         00420177     RET        0x4
//         0042017a     ??         90h
//         0042017b     NOP
//         0042017c     NOP
//         0042017d     NOP
//         0042017e     NOP
//         0042017f     NOP
    return;
}

int RGE_Base_Game::get_paused() {
    /* TODO: Stub */
//                              int __thiscall get_paused(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?get_paused@RGE_Base_Game@@QAEHXZ                            XREF[52]:    set_paused:00420223(c),
//                               RGE_Base_Game::get_paused                                                 handle_activate:004218d7(c),
//                                                                                                         handle_game_update:00496dfb(c),
//                                                                                                         key_down_action:0049791d(c),
//                                                                                                         command_attack:0049bd29(c),
//                                                                                                         command_building:0049bdc0(c),
//                                                                                                         command_cancel:0049beba(c),
//                                                                                                         command_cancel_building:0049bf26(c
//                                                                                                         command_group_by_number:0049c576(c
//                                                                                                         command_heal:0049c5b9(c),
//                                                                                                         command_move:0049c89c(c),
//                                                                                                         command_research:0049cb00(c),
//                                                                                                         command_select_building:0049ccba(c
//                                                                                                         command_ungroup:0049cfb9(c),
//                                                                                                         command_unselect:0049d049(c),
//                                                                                                         command_view_selected:0049d097(c),
//                                                                                                         command_work:0049d20c(c),
//                                                                                                         mouse_left_down_action:0053d409(c)
//                                                                                                         handle_keys:0053dec2(c),
//                                                                                                         mouse_left_move_action:0053e81b(c)
//                                                                                                         [more]
//                              basegame.cpp:3247 (9)
//         00420180     CMP        dword ptr [ECX + this->prog_mode],0x7
//         00420187     JNZ        LAB_0042018c
//                              basegame.cpp:3249 (2)
//         00420189     XOR        EAX,EAX
//                              basegame.cpp:3252 (1)
//         0042018b     RET
//                               LAB_0042018c                                                 XREF[1]:     00420187(j)
//                              basegame.cpp:3251 (11)
//         0042018c     MOV        this,dword ptr [ECX + this->comm_handler]
//         00420192     JMP        TCommunications_Handler::IsPaused                int IsPaused(TCommunications_Handler * this)
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//         00420197     ??         90h
//         00420198     NOP
//         00420199     NOP
//         0042019a     NOP
//         0042019b     NOP
//         0042019c     NOP
//         0042019d     NOP
//         0042019e     NOP
//         0042019f     NOP
    return 0;
}

RGE_Font* RGE_Base_Game::get_font(int param_1) {
    /* TODO: Stub */
//                              RGE_Font * __thiscall get_font(RGE_Base_Game * this, int param_1)
//              RGE_Font *        EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004201af(R)
//                               ?get_font@RGE_Base_Game@@QAEPAURGE_Font@@H@Z                 XREF[37]:    create_button:0046864f(c),
//                               RGE_Base_Game::get_font                                                   create_check_box:004688b8(c),
//                                                                                                         create_radio_button:00468b18(c),
//                                                                                                         create_text:00468d71(c),
//                                                                                                         create_edit:0046926e(c),
//                                                                                                         create_drop_down:00469423(c),
//                                                                                                         create_drop_down:004694e8(c),
//                                                                                                         create_list:0046972b(c),
//                                                                                                         create_list:004697e8(c),
//                                                                                                         TRIBE_Screen_Game:004943fd(c),
//                                                                                                         TRIBE_Screen_Game:0049447a(c),
//                                                                                                         TRIBE_Screen_Game:0049450f(c),
//                                                                                                         TRIBE_Screen_Game:00494832(c),
//                                                                                                         TRIBE_Screen_Game:00494a94(c),
//                                                                                                         TRIBE_Screen_Game:00494d6b(c),
//                                                                                                         TRIBE_Screen_Game:00494e0b(c),
//                                                                                                         TRIBE_Screen_Game:00494ecb(c),
//                                                                                                         TRIBE_Screen_Sed:004a84ea(c),
//                                                                                                         create_all_buttons_etc:004b0240(c)
//                                                                                                         create_timeline:0051e931(c), [more]
//                              basegame.cpp:3258 (10)
//         004201a0     MOV        this,dword ptr [ECX + this->fonts]
//         004201a6     TEST       this,this
//         004201a8     JNZ        LAB_004201af
//                              basegame.cpp:3260 (2)
//         004201aa     XOR        EAX,EAX
//                              basegame.cpp:3262 (3)
//         004201ac     RET        0x4
//                               LAB_004201af                                                 XREF[1]:     004201a8(j)
//                              basegame.cpp:3261 (10)
//         004201af     MOV        EAX,dword ptr [ESP + param_1]
//         004201b3     LEA        EAX,[EAX + EAX*0x2]
//         004201b6     LEA        EAX,[this->_padding_ + EAX*0x4]
//                              basegame.cpp:3262 (3)
//         004201b9     RET        0x4
//         004201bc     ??         90h
//         004201bd     NOP
//         004201be     NOP
//         004201bf     NOP
    return 0;
}

TShape* RGE_Base_Game::get_shape(int param_1) {
    /* TODO: Stub */
//                              TShape * __thiscall get_shape(RGE_Base_Game * this, int param_1)
//              TShape *          EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004201ca(R)
//                               ?get_shape@RGE_Base_Game@@QAEPAVTShape@@H@Z                  XREF[3]:     capture_frame_3d_square:004c25f3(c
//                               RGE_Base_Game::get_shape                                                  capture_frame_3d_square:004c279f(c
//                                                                                                         draw_terrain_obstruction_map:00538
//                              basegame.cpp:3268 (7)
//         004201c0     MOV        EAX,dword ptr [ECX + this->shapes]
//         004201c3     TEST       EAX,EAX
//         004201c5     JNZ        LAB_004201ca
//                              basegame.cpp:3272 (3)
//         004201c7     RET        0x4
//                               LAB_004201ca                                                 XREF[1]:     004201c5(j)
//                              basegame.cpp:3271 (7)
//         004201ca     MOV        this,dword ptr [ESP + param_1]
//         004201ce     MOV        EAX,dword ptr [EAX + this->_padding_*0x4]
//                              basegame.cpp:3272 (3)
//         004201d1     RET        0x4
//         004201d4     ??         90h
//         004201d5     NOP
//         004201d6     NOP
//         004201d7     NOP
//         004201d8     NOP
//         004201d9     NOP
//         004201da     NOP
//         004201db     NOP
//         004201dc     NOP
//         004201dd     NOP
//         004201de     NOP
//         004201df     NOP
    return 0;
}

TDigital* RGE_Base_Game::get_sound(int param_1) {
    /* TODO: Stub */
//                              TDigital * __thiscall get_sound(RGE_Base_Game * this, int param_1)
//              TDigital *        EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004201ea(R)
//                               ?get_sound@RGE_Base_Game@@QAEPAVTDigital@@H@Z                XREF[10]:    create_button:004685f7(c),
//                               RGE_Base_Game::get_sound                                                  create_check_box:00468829(c),
//                                                                                                         create_radio_button:00468a89(c),
//                                                                                                         restart_sound_system:00473bf5(c),
//                                                                                                         TribeEndScreen:00493a85(c),
//                                                                                                         TRIBE_Screen_Game:00494520(c),
//                                                                                                         TRIBE_Screen_Game:00494a87(c),
//                                                                                                         TRIBE_Screen_Game:004951a8(c),
//                                                                                                         key_down_action:004979a9(c),
//                                                                                                         TribeSelectTribeScreen:004b785f(c)
//                              basegame.cpp:3278 (7)
//         004201e0     MOV        EAX,dword ptr [ECX + this->sounds]
//         004201e3     TEST       EAX,EAX
//         004201e5     JNZ        LAB_004201ea
//                              basegame.cpp:3282 (3)
//         004201e7     RET        0x4
//                               LAB_004201ea                                                 XREF[1]:     004201e5(j)
//                              basegame.cpp:3281 (7)
//         004201ea     MOV        this,dword ptr [ESP + param_1]
//         004201ee     MOV        EAX,dword ptr [EAX + this->_padding_*0x4]
//                              basegame.cpp:3282 (3)
//         004201f1     RET        0x4
//         004201f4     ??         90h
//         004201f5     NOP
//         004201f6     NOP
//         004201f7     NOP
//         004201f8     NOP
//         004201f9     NOP
//         004201fa     NOP
//         004201fb     NOP
//         004201fc     NOP
//         004201fd     NOP
//         004201fe     NOP
//         004201ff     NOP
    return 0;
}

void RGE_Base_Game::request_pause() {
    /* TODO: Stub */
//                              void __thiscall request_pause(RGE_Base_Game * this)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?request_pause@RGE_Base_Game@@QAEXXZ                         XREF[3]:     set_paused:00420246(c),
//                               RGE_Base_Game::request_pause                                              set_paused:0042025b(c),
//                                                                                                         command_pause:0049c9fa(c)
//                              basegame.cpp:3288 (3)
//         00420200     PUSH       ESI
//         00420201     MOV        ESI,this
//                              basegame.cpp:3289 (11)
//         00420203     MOV        this,dword ptr [ESI + 0x18c]
//         00420209     CALL       TCommunications_Handler::TogglePauseGame         int TogglePauseGame(TCommunications_Handler *
//                              basegame.cpp:3291 (10)
//         0042020e     MOV        ESI,dword ptr [ESI + 0x3f4]
//         00420214     TEST       ESI,ESI
//         00420216     JZ         LAB_0042021c
//                              basegame.cpp:3292 (4)
//         00420218     MOV        byte ptr [ESI + 0x1c],0x1
//                               LAB_0042021c                                                 XREF[1]:     00420216(j)
//                              basegame.cpp:3293 (2)
//         0042021c     POP        ESI
//         0042021d     RET
//         0042021e     ??         90h
//         0042021f     NOP
    return;
}

void RGE_Base_Game::set_paused(int param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall set_paused(RGE_Base_Game * this, int param_1, int pa
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00420228(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0042023a(R)
//                               ?set_paused@RGE_Base_Game@@QAEXHH@Z                          XREF[21]:    handle_activate:00421880(c),
//                               RGE_Base_Game::set_paused                                                 handle_activate:004218ef(c),
//                                                                                                         action:0043b470(c),
//                                                                                                         action:0043c31d(c),
//                                                                                                         action:0043c8d9(c),
//                                                                                                         action:0043db42(c),
//                                                                                                         action:0043dba5(c),
//                                                                                                         action:0043f8a5(c),
//                                                                                                         action:0043fbae(c),
//                                                                                                         action:0048f2d0(c),
//                                                                                                         close_screen:00492dfd(c),
//                                                                                                         action:00498580(c),
//                                                                                                         action:0049871f(c),
//                                                                                                         command_diplomacy:0049c1f0(c),
//                                                                                                         command_menu:0049c7bd(c),
//                                                                                                         action:0049e62d(c),
//                                                                                                         action:004a7d6d(c),
//                                                                                                         action:004b8a97(c),
//                                                                                                         save_game:00524740(c),
//                                                                                                         save_scenario:0052482f(c), [more]
//                              basegame.cpp:3299 (3)
//         00420220     PUSH       ESI
//         00420221     MOV        ESI,this
//                              basegame.cpp:3300 (5)
//         00420223     CALL       RGE_Base_Game::get_paused                        int get_paused(RGE_Base_Game * this)
//                              basegame.cpp:3302 (14)
//         00420228     MOV        this,dword ptr [ESP + param_1]
//         0042022c     MOV        dword ptr [ESI + 0xa00],EAX
//         00420232     CMP        this,EAX
//         00420234     JZ         LAB_00420260
//                              basegame.cpp:3304 (4)
//         00420236     TEST       this,this
//         00420238     JZ         LAB_0042024f
//                              basegame.cpp:3305 (4)
//         0042023a     MOV        EAX,dword ptr [ESP + param_2]
//                              basegame.cpp:3309 (13)
//         0042023e     MOV        this,ESI
//         00420240     MOV        dword ptr [ESI + 0xa04],EAX
//         00420246     CALL       RGE_Base_Game::request_pause                     void request_pause(RGE_Base_Game * this)
//                              basegame.cpp:3311 (4)
//         0042024b     POP        ESI
//         0042024c     RET        0x8
//                               LAB_0042024f                                                 XREF[1]:     00420238(j)
//                              basegame.cpp:3309 (17)
//         0042024f     MOV        this,ESI
//         00420251     MOV        dword ptr [ESI + 0xa04],0x0
//         0042025b     CALL       RGE_Base_Game::request_pause                     void request_pause(RGE_Base_Game * this)
//                               LAB_00420260                                                 XREF[1]:     00420234(j)
//                              basegame.cpp:3311 (4)
//         00420260     POP        ESI
//         00420261     RET        0x8
//         00420264     ??         90h
//         00420265     NOP
//         00420266     NOP
//         00420267     NOP
//         00420268     NOP
//         00420269     NOP
//         0042026a     NOP
//         0042026b     NOP
//         0042026c     NOP
//         0042026d     NOP
//         0042026e     NOP
//         0042026f     NOP
    return;
}

void RGE_Base_Game::get_mouse_info(uint param_1, long param_2, tagPOINT* param_3, int* param_4, int* param_5, int* param_6, int* param_7) {
    /* TODO: Stub */
//                              void __thiscall get_mouse_info(RGE_Base_Game * this, uint param_1, l
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              uint              Stack[0x4]:4   param_1                   XREF[1]:     004202a6(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     00420270(R)
//              tagPOINT *        Stack[0xc]:4   param_3                   XREF[1]:     00420274(R)
//              int *             Stack[0x10]:4  param_4                   XREF[1]:     004202aa(R)
//              int *             Stack[0x14]:4  param_5                   XREF[1]:     004202b5(R)
//              int *             Stack[0x18]:4  param_6                   XREF[1]:     004202c0(R)
//              int *             Stack[0x1c]:4  param_7                   XREF[1]:     004202ce(R)
//                               ?get_mouse_info@RGE_Base_Game@@QAEXIJAAUtagPOINT@@AAH111@Z   XREF[1]:     handle_mouse_move:00421189(c)
//                               RGE_Base_Game::get_mouse_info
//                              basegame.cpp:3317 (15)
//         00420270     MOV        this,dword ptr [ESP + param_2]
//         00420274     MOV        EDX,dword ptr [ESP + param_3]
//         00420278     MOV        EAX,this
//         0042027a     AND        EAX,0xffff
//                              basegame.cpp:3319 (3)
//         0042027f     SHR        this,0x10
//                              basegame.cpp:3321 (12)
//         00420282     CMP        EAX,0xea60
//         00420287     MOV        dword ptr [EDX],EAX
//         00420289     MOV        dword ptr [EDX + 0x4],this
//         0042028c     JLE        LAB_00420295
//                              basegame.cpp:3322 (7)
//         0042028e     ADD        EAX,0xffff0000
//         00420293     MOV        dword ptr [EDX],EAX
//                               LAB_00420295                                                 XREF[1]:     0042028c(j)
//                              basegame.cpp:3324 (8)
//         00420295     CMP        this,0xea60
//         0042029b     JLE        LAB_004202a6
//                              basegame.cpp:3325 (9)
//         0042029d     ADD        this,0xffff0000
//         004202a3     MOV        dword ptr [EDX + 0x4],this
//                               LAB_004202a6                                                 XREF[1]:     0042029b(j)
//                              basegame.cpp:3327 (15)
//         004202a6     MOV        EAX,dword ptr [ESP + param_1]
//         004202aa     MOV        EDX,dword ptr [ESP + param_4]
//         004202ae     MOV        this,EAX
//         004202b0     AND        this,0x1
//         004202b3     MOV        dword ptr [EDX],this
//                              basegame.cpp:3328 (11)
//         004202b5     MOV        EDX,dword ptr [ESP + param_5]
//         004202b9     MOV        this,EAX
//         004202bb     AND        this,0x2
//         004202be     MOV        dword ptr [EDX],this
//                              basegame.cpp:3329 (6)
//         004202c0     MOV        EDX,dword ptr [ESP + param_6]
//         004202c4     MOV        this,EAX
//                              basegame.cpp:3330 (14)
//         004202c6     AND        EAX,0x4
//         004202c9     AND        this,0x8
//         004202cc     MOV        dword ptr [EDX],this
//         004202ce     MOV        this,dword ptr [ESP + param_7]
//         004202d2     MOV        dword ptr [this->_padding_],EAX
//                              basegame.cpp:3331 (3)
//         004202d4     RET        0x1c
//         004202d7     ??         90h
//         004202d8     NOP
//         004202d9     NOP
//         004202da     NOP
//         004202db     NOP
//         004202dc     NOP
//         004202dd     NOP
//         004202de     NOP
//         004202df     NOP
    return;
}

void RGE_Base_Game::get_mouse_pos(tagPOINT* param_1) {
    /* TODO: Stub */
//                              void __thiscall get_mouse_pos(RGE_Base_Game * this, tagPOINT * param
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              tagPOINT *        Stack[0x4]:4   param_1                   XREF[1]:     004202e1(R)
//                               ?get_mouse_pos@RGE_Base_Game@@QAEXAAUtagPOINT@@@Z            XREF[4]:     handle_mouse_pointing_at:0049bb3f(
//                               RGE_Base_Game::get_mouse_pos                                              draw_multi_object_outline:0052cb66
//                                                                                                         draw_object_outline:00535651(c),
//                                                                                                         draw_paint_brush:005358ce(c)
//                              basegame.cpp:3337 (1)
//         004202e0     PUSH       ESI
//                              basegame.cpp:3338 (14)
//         004202e1     MOV        ESI,dword ptr [ESP + param_1]
//         004202e5     PUSH       EDI
//         004202e6     MOV        EDI,this
//         004202e8     PUSH       ESI
//         004202e9     CALL       dword ptr [->USER32.DLL::GetCursorPos]           = 0048aeba
//                              basegame.cpp:3339 (13)
//         004202ef     MOV        EAX,dword ptr [EDI + 0xc]
//         004202f2     MOV        this,dword ptr [EAX + 0x894]
//         004202f8     TEST       this,this
//         004202fa     JNZ        LAB_00420329
//                              basegame.cpp:3341 (11)
//         004202fc     MOV        this,dword ptr [EDI + 0x10]
//         004202ff     PUSH       ESI
//         00420300     PUSH       this
//         00420301     CALL       dword ptr [->USER32.DLL::ScreenToClient]         = 0048aea8
//                              basegame.cpp:3342 (9)
//         00420307     MOV        EAX,dword ptr [ESI]
//         00420309     CMP        EAX,0xea60
//         0042030e     JLE        LAB_00420317
//                              basegame.cpp:3343 (7)
//         00420310     ADD        EAX,0xffff0000
//         00420315     MOV        dword ptr [ESI],EAX
//                               LAB_00420317                                                 XREF[1]:     0042030e(j)
//                              basegame.cpp:3344 (10)
//         00420317     MOV        EAX,dword ptr [ESI + 0x4]
//         0042031a     CMP        EAX,0xea60
//         0042031f     JLE        LAB_00420329
//                              basegame.cpp:3345 (8)
//         00420321     ADD        EAX,0xffff0000
//         00420326     MOV        dword ptr [ESI + 0x4],EAX
//                               LAB_00420329                                                 XREF[2]:     004202fa(j), 0042031f(j)
//                              basegame.cpp:3347 (5)
//         00420329     POP        EDI
//         0042032a     POP        ESI
//         0042032b     RET        0x4
//         0042032e     ??         90h
//         0042032f     NOP
    return;
}

RGE_Player* RGE_Base_Game::get_player() {
    /* TODO: Stub */
//                              RGE_Player * __thiscall get_player(RGE_Base_Game * this)
//              RGE_Player *      EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?get_player@RGE_Base_Game@@QAEPAVRGE_Player@@XZ              XREF[186]:   check_gold:0043e545(c),
//                               RGE_Base_Game::get_player                                                 check_wood:0043e5d5(c),
//                                                                                                         check_food:0043e665(c),
//                                                                                                         TribeAchievementsScreen:0048d668(c
//                                                                                                         TribeAchievementsScreen:0048d877(c
//                                                                                                         TribeAchievementsScreen:0048e0a5(c
//                                                                                                         TRIBE_Screen_Game:00494312(c),
//                                                                                                         player_changed:00498a77(c),
//                                                                                                         object_changed:004992ea(c),
//                                                                                                         object_changed:0049930a(c),
//                                                                                                         object_changed:00499321(c),
//                                                                                                         age_changed:004993ce(c),
//                                                                                                         setup_buttons:00499718(c),
//                                                                                                         setup_buttons:0049a255(c),
//                                                                                                         setup_buttons:0049a274(c),
//                                                                                                         any_selected_have_action:0049d44a(
//                                                                                                         set_panel_info:004a878b(c),
//                                                                                                         set_panel_info:004a87b4(c),
//                                                                                                         set_player:004aae3a(c),
//                                                                                                         set_unit_player:004ab30f(c), [more]
//                              basegame.cpp:3353 (10)
//         00420330     MOV        EAX,dword ptr [ECX + this->world]
//         00420336     TEST       EAX,EAX
//         00420338     JNZ        LAB_0042033b
//                              basegame.cpp:3361 (1)
//         0042033a     RET
//                               LAB_0042033b                                                 XREF[1]:     00420338(j)
//                              basegame.cpp:3356 (9)
//         0042033b     MOV        this,word ptr [EAX + 0x3c]
//         0042033f     TEST       this,this
//         00420342     JNZ        LAB_00420347
//                              basegame.cpp:3357 (2)
//         00420344     XOR        EAX,EAX
//                              basegame.cpp:3361 (1)
//         00420346     RET
//                               LAB_00420347                                                 XREF[1]:     00420342(j)
//                              basegame.cpp:3358 (9)
//         00420347     MOV        DX,word ptr [EAX + 0x7c]
//         0042034b     CMP        DX,this
//         0042034e     JL         LAB_00420353
//                              basegame.cpp:3359 (2)
//         00420350     XOR        EAX,EAX
//                              basegame.cpp:3361 (1)
//         00420352     RET
//                               LAB_00420353                                                 XREF[1]:     0042034e(j)
//                              basegame.cpp:3360 (9)
//         00420353     MOVSX      this,DX
//         00420356     MOV        EDX,dword ptr [EAX + 0x40]
//         00420359     MOV        EAX,dword ptr [EDX + this->_padding_*0x4]
//                              basegame.cpp:3361 (1)
//         0042035c     RET
//         0042035d     ??         90h
//         0042035e     NOP
//         0042035f     NOP
    return 0;
}

void RGE_Base_Game::draw_window() {
    /* TODO: Stub */
//                              void __thiscall draw_window(RGE_Base_Game * this)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?draw_window@RGE_Base_Game@@QAEXXZ                           XREF[7]:     fillList:00491cc7(c),
//                               RGE_Base_Game::draw_window                                                action:004924bd(c),
//                                                                                                         action:00492524(c),
//                                                                                                         handle_game_update:00497033(c),
//                                                                                                         action:004ac539(c),
//                                                                                                         do_command_game:0050a3c4(c),
//                                                                                                         show_status_message:005236da(c)
//                              basegame.cpp:3367 (10)
//         00420360     MOV        EAX,dword ptr [ECX + this->prog_window]
//         00420363     PUSH       EAX
//         00420364     CALL       dword ptr [->USER32.DLL::UpdateWindow]           = 0048adb6
//                              basegame.cpp:3369 (1)
//         0042036a     RET
//         0042036b     ??         90h
//         0042036c     NOP
//         0042036d     NOP
//         0042036e     NOP
//         0042036f     NOP
    return;
}

void RGE_Base_Game::mouse_on() {
    /* TODO: Stub */
//                              void __thiscall mouse_on(RGE_Base_Game * this)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?mouse_on@RGE_Base_Game@@QAEXXZ                              XREF[4]:     setup:0041bfdb(c),
//                               RGE_Base_Game::mouse_on                                                   wnd_proc:00420c91(c),
//                                                                                                         shutdown_video_system:0052a4fa(c),
//                                                                                                         end_scroll_view:0053aaa6(c)
//                              basegame.cpp:3375 (3)
//         00420370     PUSH       ESI
//         00420371     MOV        ESI,this
//                              basegame.cpp:3376 (10)
//         00420373     MOV        EAX,dword ptr [ESI + 0x1cc]
//         00420379     TEST       EAX,EAX
//         0042037b     JNZ        LAB_004203cf
//                              basegame.cpp:3379 (17)
//         0042037d     MOV        EAX,dword ptr [ESI + 0x54]
//         00420380     TEST       EAX,EAX
//         00420382     JZ         LAB_004203a5
//         00420384     MOV        EAX,dword ptr [ESI + 0x1d0]
//         0042038a     TEST       EAX,EAX
//         0042038c     JNZ        LAB_004203a5
//                              basegame.cpp:3380 (11)
//         0042038e     MOV        this,dword ptr [ESI + 0x1c0]
//         00420394     CALL       TMousePointer::on                                void on(TMousePointer * this)
//                              basegame.cpp:3387 (10)
//         00420399     MOV        dword ptr [ESI + 0x1cc],0x1
//                              basegame.cpp:3388 (2)
//         004203a3     POP        ESI
//         004203a4     RET
//                               LAB_004203a5                                                 XREF[2]:     00420382(j), 0042038c(j)
//                              basegame.cpp:3383 (13)
//         004203a5     MOV        EAX,dword ptr [ESI + 0x1d4]
//         004203ab     PUSH       EAX
//         004203ac     CALL       dword ptr [->USER32.DLL::SetCursor]              = 0048aeda
//                              basegame.cpp:3384 (19)
//         004203b2     MOV        this,dword ptr [ESI + 0x1d4]
//         004203b8     MOV        EDX,dword ptr [ESI + 0x10]
//         004203bb     PUSH       this
//         004203bc     PUSH       offset DAT_fffffff8
//         004203be     PUSH       EDX=>DAT_fffffff4
//         004203bf     CALL       dword ptr [->USER32.DLL::SetClassLongA]          = 0048aeca
//                              basegame.cpp:3387 (10)
//         004203c5     MOV        dword ptr [ESI + 0x1cc],0x1
//                               LAB_004203cf                                                 XREF[1]:     0042037b(j)
//                              basegame.cpp:3388 (2)
//         004203cf     POP        ESI
//         004203d0     RET
//         004203d1     ??         90h
//         004203d2     NOP
//         004203d3     NOP
//         004203d4     NOP
//         004203d5     NOP
//         004203d6     NOP
//         004203d7     NOP
//         004203d8     NOP
//         004203d9     NOP
//         004203da     NOP
//         004203db     NOP
//         004203dc     NOP
//         004203dd     NOP
//         004203de     NOP
//         004203df     NOP
    return;
}

void RGE_Base_Game::mouse_off() {
    /* TODO: Stub */
//                              void __thiscall mouse_off(RGE_Base_Game * this)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?mouse_off@RGE_Base_Game@@QAEXXZ                             XREF[4]:     setup_mouse:0041ecbe(c),
//                               RGE_Base_Game::mouse_off                                                  sub_wnd_proc:004762d4(c),
//                                                                                                         setup_video_system:0052a289(c),
//                                                                                                         start_scroll_view:0053a1e0(c)
//                              basegame.cpp:3394 (3)
//         004203e0     PUSH       ESI
//         004203e1     MOV        ESI,this
//                              basegame.cpp:3395 (10)
//         004203e3     MOV        EAX,dword ptr [ESI + 0x1cc]
//         004203e9     TEST       EAX,EAX
//         004203eb     JZ         LAB_00420435
//                              basegame.cpp:3398 (17)
//         004203ed     MOV        EAX,dword ptr [ESI + 0x54]
//         004203f0     TEST       EAX,EAX
//         004203f2     JZ         LAB_00420415
//         004203f4     MOV        EAX,dword ptr [ESI + 0x1d0]
//         004203fa     TEST       EAX,EAX
//         004203fc     JNZ        LAB_00420415
//                              basegame.cpp:3399 (11)
//         004203fe     MOV        this,dword ptr [ESI + 0x1c0]
//         00420404     CALL       TMousePointer::off                               void off(TMousePointer * this)
//                              basegame.cpp:3406 (10)
//         00420409     MOV        dword ptr [ESI + 0x1cc],0x0
//                              basegame.cpp:3407 (2)
//         00420413     POP        ESI
//         00420414     RET
//                               LAB_00420415                                                 XREF[2]:     004203f2(j), 004203fc(j)
//                              basegame.cpp:3402 (8)
//         00420415     PUSH       0x0
//         00420417     CALL       dword ptr [->USER32.DLL::SetCursor]              = 0048aeda
//                              basegame.cpp:3403 (14)
//         0042041d     MOV        EAX,dword ptr [ESI + 0x10]
//         00420420     PUSH       0x0
//         00420422     PUSH       offset DAT_fffffff8
//         00420424     PUSH       EAX=>DAT_fffffff4
//         00420425     CALL       dword ptr [->USER32.DLL::SetClassLongA]          = 0048aeca
//                              basegame.cpp:3406 (10)
//         0042042b     MOV        dword ptr [ESI + 0x1cc],0x0
//                               LAB_00420435                                                 XREF[1]:     004203eb(j)
//                              basegame.cpp:3407 (2)
//         00420435     POP        ESI
//         00420436     RET
//         00420437     ??         90h
//         00420438     NOP
//         00420439     NOP
//         0042043a     NOP
//         0042043b     NOP
//         0042043c     NOP
//         0042043d     NOP
//         0042043e     NOP
//         0042043f     NOP
    return;
}

void RGE_Base_Game::set_windows_mouse(int param_1) {
    /* TODO: Stub */
//                              void __thiscall set_windows_mouse(RGE_Base_Game * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0042044a(R)
//                               ?set_windows_mouse@RGE_Base_Game@@QAEXH@Z                    XREF[4]:     set_focus:0049d4cc(c),
//                               RGE_Base_Game::set_windows_mouse                                          set_focus:0049d4dd(c),
//                                                                                                         set_focus:004adc5c(c),
//                                                                                                         set_focus:004adc6d(c)
//                              basegame.cpp:3413 (3)
//         00420440     PUSH       ESI
//         00420441     MOV        ESI,this
//                              basegame.cpp:3414 (7)
//         00420443     MOV        EAX,dword ptr [ESI + 0x54]
//         00420446     TEST       EAX,EAX
//         00420448     JZ         LAB_00420456
//                              basegame.cpp:3415 (10)
//         0042044a     MOV        this,dword ptr [ESP + param_1]
//         0042044e     MOV        dword ptr [ESI + 0x1d0],this
//                              basegame.cpp:3416 (2)
//         00420454     JMP        LAB_00420460
//                               LAB_00420456                                                 XREF[1]:     00420448(j)
//                              basegame.cpp:3417 (10)
//         00420456     MOV        dword ptr [ESI + 0x1d0],0x1
//                               LAB_00420460                                                 XREF[1]:     00420454(j)
//                              basegame.cpp:3419 (14)
//         00420460     TEST       EAX,EAX
//         00420462     JZ         LAB_004204a6
//         00420464     MOV        EAX,dword ptr [ESI + 0x1d0]
//         0042046a     TEST       EAX,EAX
//         0042046c     JNZ        LAB_004204a6
//                              basegame.cpp:3421 (8)
//         0042046e     PUSH       0x0
//         00420470     CALL       dword ptr [->USER32.DLL::SetCursor]              = 0048aeda
//                              basegame.cpp:3422 (14)
//         00420476     MOV        EDX,dword ptr [ESI + 0x10]
//         00420479     PUSH       0x0
//         0042047b     PUSH       offset DAT_fffffff8
//         0042047d     PUSH       EDX=>DAT_fffffff4
//         0042047e     CALL       dword ptr [->USER32.DLL::SetClassLongA]          = 0048aeca
//                              basegame.cpp:3423 (6)
//         00420484     MOV        EAX,dword ptr [ESI + 0x1cc]
//                              basegame.cpp:3424 (15)
//         0042048a     MOV        this,dword ptr [ESI + 0x1c0]
//         00420490     TEST       EAX,EAX
//         00420492     JZ         LAB_0042049d
//         00420494     CALL       TMousePointer::on                                void on(TMousePointer * this)
//                              basegame.cpp:3442 (4)
//         00420499     POP        ESI
//         0042049a     RET        0x4
//                               LAB_0042049d                                                 XREF[1]:     00420492(j)
//                              basegame.cpp:3426 (5)
//         0042049d     CALL       TMousePointer::off                               void off(TMousePointer * this)
//                              basegame.cpp:3442 (4)
//         004204a2     POP        ESI
//         004204a3     RET        0x4
//                               LAB_004204a6                                                 XREF[2]:     00420462(j), 0042046c(j)
//                              basegame.cpp:3430 (11)
//         004204a6     MOV        this,dword ptr [ESI + 0x1c0]
//         004204ac     CALL       TMousePointer::off                               void off(TMousePointer * this)
//                              basegame.cpp:3431 (10)
//         004204b1     MOV        EAX,dword ptr [ESI + 0x1cc]
//         004204b7     TEST       EAX,EAX
//         004204b9     JZ         LAB_004204df
//                              basegame.cpp:3433 (13)
//         004204bb     MOV        EAX,dword ptr [ESI + 0x1d4]
//         004204c1     PUSH       EAX
//         004204c2     CALL       dword ptr [->USER32.DLL::SetCursor]              = 0048aeda
//                              basegame.cpp:3434 (13)
//         004204c8     MOV        this,dword ptr [ESI + 0x1d4]
//         004204ce     MOV        EDX,dword ptr [ESI + 0x10]
//         004204d1     PUSH       this
//         004204d2     PUSH       offset DAT_fffffff8
//         004204d4     PUSH       EDX=>DAT_fffffff4
//                              basegame.cpp:3439 (6)
//         004204d5     CALL       dword ptr [->USER32.DLL::SetClassLongA]          = 0048aeca
//                              basegame.cpp:3442 (4)
//         004204db     POP        ESI
//         004204dc     RET        0x4
//                               LAB_004204df                                                 XREF[1]:     004204b9(j)
//                              basegame.cpp:3438 (8)
//         004204df     PUSH       0x0
//         004204e1     CALL       dword ptr [->USER32.DLL::SetCursor]              = 0048aeda
//                              basegame.cpp:3439 (14)
//         004204e7     MOV        EAX,dword ptr [ESI + 0x10]
//         004204ea     PUSH       0x0
//         004204ec     PUSH       offset DAT_fffffff8
//         004204ee     PUSH       EAX=>DAT_fffffff4
//         004204ef     CALL       dword ptr [->USER32.DLL::SetClassLongA]          = 0048aeca
//                              basegame.cpp:3442 (4)
//         004204f5     POP        ESI
//         004204f6     RET        0x4
//         004204f9     ??         90h
//         004204fa     NOP
//         004204fb     NOP
//         004204fc     NOP
//         004204fd     NOP
//         004204fe     NOP
//         004204ff     NOP
    return;
}

void RGE_Base_Game::set_mouse_cursor(void* param_1) {
    /* TODO: Stub */
//                              void __thiscall set_mouse_cursor(RGE_Base_Game * this, void * param_1)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              void *            Stack[0x4]:4   param_1                   XREF[1]:     00420500(R)
//                               ?set_mouse_cursor@RGE_Base_Game@@QAEXPAX@Z                   XREF[6]:     disable_input:00422a6d(c),
//                               RGE_Base_Game::set_mouse_cursor                                           enable_input:00422afb(c),
//                                                                                                         setup_popup_help:0046a37e(c),
//                                                                                                         clear_popup_help:0046a3de(c),
//                                                                                                         command_do_popup_help:0046a44c(c),
//                                                                                                         shutdown_video_system:0052a4f3(c)
//                              basegame.cpp:3448 (7)
//         00420500     MOV        EAX,dword ptr [ESP + param_1]
//         00420504     PUSH       ESI
//         00420505     MOV        ESI,this
//                              basegame.cpp:3450 (15)
//         00420507     TEST       EAX,EAX
//         00420509     MOV        dword ptr [ESI + 0x1d4],EAX
//         0042050f     JZ         LAB_00420516
//         00420511     MOV        [last_mouse_cursor],EAX                          = 00000000
//                               LAB_00420516                                                 XREF[1]:     0042050f(j)
//                              basegame.cpp:3452 (27)
//         00420516     MOV        EAX,dword ptr [ESI + 0x1cc]
//         0042051c     TEST       EAX,EAX
//         0042051e     JZ         LAB_00420551
//         00420520     MOV        EAX,dword ptr [ESI + 0x54]
//         00420523     TEST       EAX,EAX
//         00420525     JZ         LAB_00420531
//         00420527     MOV        EAX,dword ptr [ESI + 0x1d0]
//         0042052d     TEST       EAX,EAX
//         0042052f     JZ         LAB_00420551
//                               LAB_00420531                                                 XREF[1]:     00420525(j)
//                              basegame.cpp:3454 (13)
//         00420531     MOV        EAX,dword ptr [ESI + 0x1d4]
//         00420537     PUSH       EAX
//         00420538     CALL       dword ptr [->USER32.DLL::SetCursor]              = 0048aeda
//                              basegame.cpp:3455 (19)
//         0042053e     MOV        this,dword ptr [ESI + 0x1d4]
//         00420544     MOV        EDX,dword ptr [ESI + 0x10]
//         00420547     PUSH       this
//         00420548     PUSH       offset DAT_fffffff8
//         0042054a     PUSH       EDX=>DAT_fffffff4
//         0042054b     CALL       dword ptr [->USER32.DLL::SetClassLongA]          = 0048aeca
//                               LAB_00420551                                                 XREF[2]:     0042051e(j), 0042052f(j)
//                              basegame.cpp:3457 (4)
//         00420551     POP        ESI
//         00420552     RET        0x4
//         00420555     ??         90h
//         00420556     NOP
//         00420557     NOP
//         00420558     NOP
//         00420559     NOP
//         0042055a     NOP
//         0042055b     NOP
//         0042055c     NOP
//         0042055d     NOP
//         0042055e     NOP
//         0042055f     NOP
    return;
}

void RGE_Base_Game::set_mouse_facet(long param_1) {
    /* TODO: Stub */
//                              void __thiscall set_mouse_facet(RGE_Base_Game * this, long param_1)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00420560(R)
//                               ?set_mouse_facet@RGE_Base_Game@@QAEXJ@Z                      XREF[3]:     setup_popup_help:0046a38b(c),
//                               RGE_Base_Game::set_mouse_facet                                            clear_popup_help:0046a3eb(c),
//                                                                                                         command_do_popup_help:0046a459(c)
//                              basegame.cpp:3463 (16)
//         00420560     MOV        EAX,dword ptr [ESP + param_1]
//         00420564     MOV        this,dword ptr [ECX + this->mouse_pointer]
//         0042056a     PUSH       EAX
//         0042056b     CALL       TMousePointer::set_facet                         void set_facet(TMousePointer * this, int para
//                              basegame.cpp:3465 (3)
//         00420570     RET        0x4
//         00420573     ??         90h
//         00420574     NOP
//         00420575     NOP
//         00420576     NOP
//         00420577     NOP
//         00420578     NOP
//         00420579     NOP
//         0042057a     NOP
//         0042057b     NOP
//         0042057c     NOP
//         0042057d     NOP
//         0042057e     NOP
//         0042057f     NOP
    return;
}

int enum_wnd_proc(void* param_1, long param_2) {
    /* TODO: Stub */
//                              int __stdcall enum_wnd_proc(void * param_1, long param_2)
//              int               EAX:4          <RETURN>
//              void *            Stack[0x4]:4   param_1                   XREF[1]:     00420580(R)
//              long              Stack[0x8]:4   param_2
//              char[256]         Stack[-0x104   wnd_title                 XREF[0,1]:   0042058a(*)
//                               ?enum_wnd_proc@@YGHPAXJ@Z
//                               enum_wnd_proc
//                              basegame.cpp:3469 (27)
//         00420580     MOV        ECX,dword ptr [ESP + param_1]
//         00420584     SUB        ESP,0x100
//         0042058a     LEA        EAX=>wnd_title[4],[ESP]
//         0042058e     PUSH       0xff
//         00420593     PUSH       EAX
//         00420594     PUSH       ECX
//         00420595     CALL       dword ptr [->USER32.DLL::GetWindowTextA]         = 0048aee6
//                              basegame.cpp:3473 (5)
//         0042059b     MOV        EAX,0x1
//                              basegame.cpp:3474 (9)
//         004205a0     ADD        ESP,0x100
//         004205a6     RET        0x8
//         004205a9     ??         90h
//         004205aa     NOP
//         004205ab     NOP
//         004205ac     NOP
//         004205ad     NOP
//         004205ae     NOP
//         004205af     NOP
    return 0;
}

int enum_child_proc(void* param_1, long param_2) {
    /* TODO: Stub */
//                              int __stdcall enum_child_proc(void * param_1, long param_2)
//              int               EAX:4          <RETURN>
//              void *            Stack[0x4]:4   param_1                   XREF[1]:     004205b0(R)
//              long              Stack[0x8]:4   param_2
//              char[256]         Stack[-0x104   wnd_title                 XREF[0,1]:   004205ba(*)
//                               ?enum_child_proc@@YGHPAXJ@Z
//                               enum_child_proc
//                              basegame.cpp:3477 (27)
//         004205b0     MOV        ECX,dword ptr [ESP + param_1]
//         004205b4     SUB        ESP,0x100
//         004205ba     LEA        EAX=>wnd_title[4],[ESP]
//         004205be     PUSH       0xff
//         004205c3     PUSH       EAX
//         004205c4     PUSH       ECX
//         004205c5     CALL       dword ptr [->USER32.DLL::GetWindowTextA]         = 0048aee6
//                              basegame.cpp:3481 (5)
//         004205cb     MOV        EAX,0x1
//                              basegame.cpp:3482 (9)
//         004205d0     ADD        ESP,0x100
//         004205d6     RET        0x8
//         004205d9     ??         90h
//         004205da     NOP
//         004205db     NOP
//         004205dc     NOP
//         004205dd     NOP
//         004205de     NOP
//         004205df     NOP
    return 0;
}

int enum_thread_proc(void* param_1, long param_2) {
    /* TODO: Stub */
//                              int __stdcall enum_thread_proc(void * param_1, long param_2)
//              int               EAX:4          <RETURN>
//              void *            Stack[0x4]:4   param_1                   XREF[1]:     004205e0(R)
//              long              Stack[0x8]:4   param_2
//              char[256]         Stack[-0x104   wnd_title                 XREF[0,1]:   004205ea(*)
//                               ?enum_thread_proc@@YGHPAXJ@Z
//                               enum_thread_proc
//                              basegame.cpp:3485 (27)
//         004205e0     MOV        ECX,dword ptr [ESP + param_1]
//         004205e4     SUB        ESP,0x100
//         004205ea     LEA        EAX=>wnd_title[4],[ESP]
//         004205ee     PUSH       0xff
//         004205f3     PUSH       EAX
//         004205f4     PUSH       ECX
//         004205f5     CALL       dword ptr [->USER32.DLL::GetWindowTextA]         = 0048aee6
//                              basegame.cpp:3489 (5)
//         004205fb     MOV        EAX,0x1
//                              basegame.cpp:3490 (9)
//         00420600     ADD        ESP,0x100
//         00420606     RET        0x8
//         00420609     ??         90h
//         0042060a     NOP
//         0042060b     NOP
//         0042060c     NOP
//         0042060d     NOP
//         0042060e     NOP
//         0042060f     NOP
    return 0;
}

int close_thread_windows(void* param_1, long param_2) {
    /* TODO: Stub */
//                              int __stdcall close_thread_windows(void * param_1, long param_2)
//              int               EAX:4          <RETURN>
//              void *            Stack[0x4]:4   param_1                   XREF[1]:     00420616(R)
//              long              Stack[0x8]:4   param_2
//                               ?close_thread_windows@@YGHPAXJ@Z
//                               close_thread_windows
//                              basegame.cpp:3493 (29)
//         00420610     MOV        EAX,[AppWnd]                                     = 00000000
//         00420615     PUSH       ESI
//         00420616     MOV        ESI,dword ptr [ESP + param_1]
//         0042061a     CMP        ESI,EAX
//         0042061c     JZ         LAB_0042063a
//         0042061e     PUSH       ESI
//         0042061f     CALL       dword ptr [->USER32.DLL::GetParent]              = 0048aef8
//         00420625     CMP        EAX,dword ptr [AppWnd]                           = 00000000
//         0042062b     JZ         LAB_0042063a
//                              basegame.cpp:3495 (13)
//         0042062d     PUSH       0x0
//         0042062f     PUSH       0x0
//         00420631     PUSH       0x10
//         00420633     PUSH       ESI
//         00420634     CALL       dword ptr [->USER32.DLL::SendMessageA]           = 0048ad08
//                               LAB_0042063a                                                 XREF[2]:     0042061c(j), 0042062b(j)
//                              basegame.cpp:3496 (5)
//         0042063a     MOV        EAX,0x1
//                              basegame.cpp:3497 (4)
//         0042063f     POP        ESI
//         00420640     RET        0x8
//         00420643     ??         90h
//         00420644     NOP
//         00420645     NOP
//         00420646     NOP
//         00420647     NOP
//         00420648     NOP
//         00420649     NOP
//         0042064a     NOP
//         0042064b     NOP
//         0042064c     NOP
//         0042064d     NOP
//         0042064e     NOP
//         0042064f     NOP
    return 0;
}

int close_child_windows(void* param_1, long param_2) {
    /* TODO: Stub */
//                              int __stdcall close_child_windows(void * param_1, long param_2)
//              int               EAX:4          <RETURN>
//              void *            Stack[0x4]:4   param_1                   XREF[1]:     00420659(R)
//              long              Stack[0x8]:4   param_2
//              char[256]         Stack[-0x104   str                       XREF[0,2]:   00420660(*), 0042066b(W)
//                               ?close_child_windows@@YGHPAXJ@Z
//                               close_child_windows
//                              basegame.cpp:3500 (9)
//         00420650     SUB        ESP,0x100
//         00420656     PUSH       EBX
//         00420657     PUSH       ESI
//         00420658     PUSH       EDI
//                              basegame.cpp:3503 (29)
//         00420659     MOV        EDI,dword ptr [ESP + param_1]
//         00420660     LEA        EAX=>str[4],[ESP + 0xc]
//         00420664     PUSH       0xff
//         00420669     PUSH       EAX
//         0042066a     PUSH       EDI
//         0042066b     MOV        byte ptr [ESP + str[4]],0x0
//         00420670     CALL       dword ptr [->USER32.DLL::GetWindowTextA]         = 0048aee6
//                              basegame.cpp:3504 (58)
//         00420676     MOV        ESI,s_Locate_Session                             = 4Ch
//         0042067b     LEA        EAX,[ESP + 0xc]
//                               LAB_0042067f                                                 XREF[1]:     004206a1(j)
//         0042067f     MOV        DL,byte ptr [EAX]
//         00420681     MOV        BL,byte ptr [ESI]=>s_Locate_Session              = 4Ch
//                                                                                  = 63h
//         00420683     MOV        CL,DL
//         00420685     CMP        DL,BL
//         00420687     JNZ        LAB_004206a7
//         00420689     TEST       CL,CL
//         0042068b     JZ         LAB_004206a3
//         0042068d     MOV        DL,byte ptr [EAX + 0x1]
//         00420690     MOV        BL,byte ptr [ESI + 0x1]=>DAT_00580265            = 6Fh
//                                                                                  = "ate Session"
//         00420693     MOV        CL,DL
//         00420695     CMP        DL,BL
//         00420697     JNZ        LAB_004206a7
//         00420699     ADD        EAX,0x2
//         0042069c     ADD        ESI,0x2
//         0042069f     TEST       CL,CL
//         004206a1     JNZ        LAB_0042067f
//                               LAB_004206a3                                                 XREF[1]:     0042068b(j)
//         004206a3     XOR        EAX,EAX
//         004206a5     JMP        LAB_004206ac
//                               LAB_004206a7                                                 XREF[2]:     00420687(j), 00420697(j)
//         004206a7     SBB        EAX,EAX
//         004206a9     SBB        EAX,-0x1
//                               LAB_004206ac                                                 XREF[1]:     004206a5(j)
//         004206ac     TEST       EAX,EAX
//         004206ae     JZ         LAB_004206bd
//                              basegame.cpp:3505 (13)
//         004206b0     PUSH       0x0
//         004206b2     PUSH       0x0
//         004206b4     PUSH       0x10
//         004206b6     PUSH       EDI
//         004206b7     CALL       dword ptr [->USER32.DLL::SendMessageA]           = 0048ad08
//                               LAB_004206bd                                                 XREF[1]:     004206ae(j)
//                              basegame.cpp:3507 (17)
//         004206bd     POP        EDI
//         004206be     POP        ESI
//         004206bf     MOV        EAX,0x1
//         004206c4     POP        EBX
//         004206c5     ADD        ESP,0x100
//         004206cb     RET        0x8
//         004206ce     ??         90h
//         004206cf     NOP
    return 0;
}

long RGE_Base_Game::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) {
    /* TODO: Stub */
//                              long __stdcall wnd_proc(void * param_1, uint param_2, uint param_3,
//              long              EAX:4          <RETURN>
//              void *            Stack[0x4]:4   param_1                   XREF[2]:     00420713(R), 0042076c(W)
//              uint              Stack[0x8]:4   param_2                   XREF[1]:     0042071f(R)
//              uint              Stack[0xc]:4   param_3                   XREF[4]:     004206e0(R), 0042072a(R), 0042074c(R), 00420795(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     0042071b(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004206ec(W), 00420703(W)
//              int               Stack[-0x8]:4  mouse_down
//                               ?wnd_proc@RGE_Base_Game@@UAGJPAXIIJ@Z                        XREF[2]:     wnd_proc:005295c1(c), 0056eed8(*)
//                               RGE_Base_Game::wnd_proc
//                              basegame.cpp:3513 (5)
//         004206d0     PUSH       ECX
//         004206d1     PUSH       EBX
//         004206d2     PUSH       EBP
//         004206d3     PUSH       ESI
//         004206d4     PUSH       EDI
//                              basegame.cpp:3516 (11)
//         004206d5     PUSH       0x3
//         004206d7     PUSH       0x24
//         004206d9     PUSH       0x24
//         004206db     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:3519 (29)
//         004206e0     MOV        EAX,dword ptr [ESP + param_3]
//         004206e4     ADD        ESP,0xc
//         004206e7     CMP        EAX,0x201
//         004206ec     MOV        dword ptr [ESP + local_4],0x0
//         004206f4     JC         LAB_00420713
//         004206f6     CMP        EAX,0x206
//         004206fb     JA         LAB_00420713
//                              basegame.cpp:3528 (22)
//         004206fd     PUSH       0x4
//         004206ff     PUSH       0x4c
//         00420701     PUSH       0x4c
//         00420703     MOV        dword ptr [ESP + local_4],0x1
//         0042070b     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         00420710     ADD        ESP,0xc
//                               LAB_00420713                                                 XREF[2]:     004206f4(j), 004206fb(j)
//                              basegame.cpp:3534 (23)
//         00420713     MOV        ESI,dword ptr [ESP + param_1]
//         00420717     MOV        EBX,dword ptr [ESP + Stack[0x14]]
//         0042071b     MOV        EDI,dword ptr [ESP + param_4]
//         0042071f     MOV        EBP,dword ptr [ESP + param_2]
//         00420723     MOV        ECX,dword ptr [ESI + 0x60]
//         00420726     TEST       ECX,ECX
//         00420728     JZ         LAB_00420737
//                              basegame.cpp:3535 (13)
//         0042072a     MOV        EAX,dword ptr [ESP + param_3]
//         0042072e     PUSH       EBX
//         0042072f     PUSH       EDI
//         00420730     PUSH       EAX
//         00420731     PUSH       EBP
//         00420732     CALL       TSound_Driver::handle_messages                   uint handle_messages(TSound_Driver * this, vo
//                               LAB_00420737                                                 XREF[1]:     00420728(j)
//                              basegame.cpp:3537 (11)
//         00420737     PUSH       0x3
//         00420739     PUSH       0x16
//         0042073b     PUSH       0x24
//         0042073d     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:3540 (10)
//         00420742     MOV        ECX,dword ptr [ESI + 0x64]
//         00420745     ADD        ESP,0xc
//         00420748     TEST       ECX,ECX
//         0042074a     JZ         LAB_00420759
//                              basegame.cpp:3541 (13)
//         0042074c     MOV        EDX,dword ptr [ESP + param_3]
//         00420750     PUSH       EBX
//         00420751     PUSH       EDI
//         00420752     PUSH       EDX
//         00420753     PUSH       EBP
//         00420754     CALL       TMusic_System::handle_messages                   uint handle_messages(TMusic_System * this, vo
//                               LAB_00420759                                                 XREF[1]:     0042074a(j)
//                              basegame.cpp:3543 (14)
//         00420759     PUSH       0x3
//         0042075b     PUSH       0x4c
//         0042075d     PUSH       0x24
//         0042075f     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         00420764     ADD        ESP,0xc
//                              basegame.cpp:3549 (22)
//         00420767     MOV        ECX,panel_system
//         0042076c     MOV        dword ptr [ESP + param_1],0x0
//         00420774     CALL       TPanelSystem::currentPanel                       TPanel * currentPanel(TPanelSystem * this)
//         00420779     TEST       EAX,EAX
//         0042077b     JZ         LAB_004207c2
//                              basegame.cpp:3551 (14)
//         0042077d     PUSH       0x3
//         0042077f     PUSH       0x32
//         00420781     PUSH       0x24
//         00420783     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         00420788     ADD        ESP,0xc
//                              basegame.cpp:3552 (25)
//         0042078b     MOV        ECX,panel_system
//         00420790     CALL       TPanelSystem::currentPanel                       TPanel * currentPanel(TPanelSystem * this)
//         00420795     MOV        ECX,dword ptr [ESP + param_3]
//         00420799     MOV        EDX,dword ptr [EAX]
//         0042079b     PUSH       EBX
//         0042079c     PUSH       EDI
//         0042079d     PUSH       ECX
//         0042079e     PUSH       EBP
//         0042079f     MOV        ECX,EAX
//         004207a1     CALL       dword ptr [EDX + 0x48]
//                              basegame.cpp:3553 (8)
//         004207a4     TEST       EAX,EAX
//         004207a6     MOV        dword ptr [ESP + 0x18],EAX
//         004207aa     JZ         LAB_004207c2
//                              basegame.cpp:3555 (16)
//         004207ac     MOV        EAX,dword ptr [ESP + 0x20]
//         004207b0     CMP        EAX,0x200
//         004207b5     JZ         LAB_004207c2
//         004207b7     CMP        EAX,0x113
//                              basegame.cpp:3560 (6)
//         004207bc     JNZ        LAB_00420d04
//                               LAB_004207c2                                                 XREF[3]:     0042077b(j), 004207aa(j),
//                                                                                                         004207b5(j)
//                              basegame.cpp:3565 (11)
//         004207c2     PUSH       0x3
//         004207c4     PUSH       offset DAT_fffffff8
//         004207c6     PUSH       offset DAT_fffffff4
//         004207c8     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:3568 (30)
//         004207cd     MOV        EAX,dword ptr [ESP + 0x2c]
//         004207d1     ADD        ESP,0xc
//         004207d4     CMP        EAX,0x5
//         004207d7     JA         LAB_00420881
//         004207dd     CMP        EAX,0x5
//         004207e0     JZ         LAB_00420818
//         004207e2     SUB        EAX,0x2
//         004207e5     JNZ        LAB_00420f09
//                              basegame.cpp:3951 (14)
//         004207eb     PUSH       0x3
//         004207ed     PUSH       offset DAT_fffffff8
//         004207f2     PUSH       offset DAT_fffffff4
//         004207f4     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:3952 (26)
//         004207f9     MOV        EDX,dword ptr [ESI]
//         004207fb     ADD        ESP,0xc
//         004207fe     MOV        ECX,ESI
//         00420800     PUSH       EBX
//         00420801     PUSH       EDI=>DAT_fffffff8
//         00420802     PUSH       offset DAT_fffffff4
//         00420804     PUSH       EBP=>DAT_fffffff0
//         00420805     CALL       dword ptr [EDX + 0xf4]
//         0042080b     TEST       EAX,EAX
//         0042080d     JNZ        LAB_00420f09
//                              basegame.cpp:3957 (5)
//         00420813     JMP        LAB_00420e5e
//                               LAB_00420818                                                 XREF[1]:     004207e0(j)
//                              basegame.cpp:3906 (13)
//         00420818     MOV        EAX,[system_ignore_size_messages]
//         0042081d     TEST       EAX,EAX
//         0042081f     JNZ        LAB_00420f09
//                              basegame.cpp:3908 (14)
//         00420825     PUSH       0x3
//         00420827     PUSH       offset DAT_fffffff8
//         0042082c     PUSH       offset DAT_fffffff4
//         0042082e     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:3909 (26)
//         00420833     MOV        EAX,dword ptr [ESI]
//         00420835     ADD        ESP,0xc
//         00420838     MOV        ECX,ESI
//         0042083a     PUSH       EBX
//         0042083b     PUSH       EDI=>DAT_fffffff8
//         0042083c     PUSH       offset DAT_fffffff4
//         0042083e     PUSH       EBP=>DAT_fffffff0
//         0042083f     CALL       dword ptr [EAX + 0xe4]
//         00420845     TEST       EAX,EAX
//         00420847     JNZ        LAB_00420f09
//                              basegame.cpp:3911 (12)
//         0042084d     MOV        EAX,dword ptr [ESP + 0x10]
//         00420851     TEST       EAX,EAX
//         00420853     JZ         LAB_00420e74
//                              basegame.cpp:3912 (14)
//         00420859     PUSH       0x4
//         0042085b     PUSH       offset DAT_fffffff8
//         0042085d     PUSH       offset DAT_fffffff4
//         0042085f     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         00420864     ADD        ESP,0xc
//                              basegame.cpp:3913 (11)
//         00420867     PUSH       0x3
//         00420869     PUSH       offset DAT_fffffff8
//         0042086b     PUSH       offset DAT_fffffff4
//         0042086d     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:3914 (7)
//         00420872     MOV        EAX,dword ptr [ESP + 0x24]
//         00420876     ADD        ESP,0xc
//                              basegame.cpp:3975 (8)
//         00420879     POP        EDI
//         0042087a     POP        ESI
//         0042087b     POP        EBP
//         0042087c     POP        EBX
//         0042087d     POP        ECX
//         0042087e     RET        0x14
//                               LAB_00420881                                                 XREF[1]:     004207d7(j)
//                              basegame.cpp:3568 (26)
//         00420881     CMP        EAX,0xf
//         00420884     JA         LAB_0042094f
//         0042088a     JZ         LAB_00420925
//         00420890     SUB        EAX,0x6
//         00420893     JZ         LAB_0042089b
//         00420895     DEC        EAX
//         00420896     JMP        LAB_00420f09
//                               LAB_0042089b                                                 XREF[1]:     00420893(j)
//                              basegame.cpp:3792 (11)
//         0042089b     MOV        EAX,dword ptr [ESI + 0x14]
//         0042089e     TEST       EAX,EAX
//         004208a0     JZ         LAB_00420f09
//                              basegame.cpp:3794 (2)
//         004208a6     MOV        EAX,EDI
//                              basegame.cpp:3795 (10)
//         004208a8     MOV        ECX,EDI
//         004208aa     AND        EAX,0xffff
//         004208af     SHR        ECX,0x10
//                              basegame.cpp:3806 (12)
//         004208b2     TEST       EAX,EAX
//         004208b4     MOV        dword ptr [ESP + 0x18],EAX
//         004208b8     MOV        dword ptr [ESP + 0x28],ECX
//         004208bc     JNZ        LAB_004208f0
//                              basegame.cpp:3808 (32)
//         004208be     MOV        ECX,dword ptr [ESI + 0x10]
//         004208c1     MOV        EBP,dword ptr [->USER32.DLL::GetWindowThreadPr   = 0048af28
//         004208c7     PUSH       EAX
//         004208c8     PUSH       ECX=>DAT_fffffff8
//         004208c9     CALL       EBP=>USER32.DLL::GetWindowThreadProcessId
//         004208cb     MOV        EDX,EAX
//         004208cd     PUSH       0x0
//         004208cf     PUSH       EBX=>DAT_fffffff8
//         004208d0     MOV        dword ptr [ESP + 0x2c],EDX
//         004208d4     CALL       EBP=>USER32.DLL::GetWindowThreadProcessId
//         004208d6     MOV        EDX,dword ptr [ESP + 0x24]
//         004208da     CMP        EAX,EDX
//         004208dc     JNZ        LAB_004208e4
//                              basegame.cpp:3809 (18)
//         004208de     MOV        dword ptr [save_active_wnd],EBX                  = 00000000
//                               LAB_004208e4                                                 XREF[1]:     004208dc(j)
//         004208e4     MOV        EBP,dword ptr [ESP + 0x1c]
//         004208e8     MOV        EAX,dword ptr [ESP + 0x18]
//         004208ec     MOV        ECX,dword ptr [ESP + 0x28]
//                               LAB_004208f0                                                 XREF[1]:     004208bc(j)
//                              basegame.cpp:3812 (17)
//         004208f0     CMP        EBP,dword ptr [ESI + 0x10]
//         004208f3     JNZ        LAB_00420f09
//         004208f9     TEST       EAX,EAX
//         004208fb     JZ         LAB_00420f09
//                              basegame.cpp:3814 (8)
//         00420901     TEST       ECX,ECX
//         00420903     JZ         LAB_00420f09
//                              basegame.cpp:3818 (13)
//         00420909     MOV        EAX,[save_active_wnd]                            = 00000000
//         0042090e     TEST       EAX,EAX
//         00420910     JZ         LAB_00420f09
//                              basegame.cpp:3823 (10)
//         00420916     MOV        dword ptr [save_active_wnd],0x0                  = 00000000
//                              basegame.cpp:3828 (5)
//         00420920     JMP        LAB_00420f09
//                               LAB_00420925                                                 XREF[1]:     0042088a(j)
//                              basegame.cpp:3689 (11)
//         00420925     PUSH       0x3
//         00420927     PUSH       offset DAT_fffffff8
//         00420929     PUSH       offset DAT_fffffff4
//         0042092b     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:3690 (26)
//         00420930     MOV        EAX,dword ptr [ESI]
//         00420932     ADD        ESP,0xc
//         00420935     MOV        ECX,ESI
//         00420937     PUSH       EBX
//         00420938     PUSH       EDI=>DAT_fffffff8
//         00420939     PUSH       offset DAT_fffffff4
//         0042093b     PUSH       EBP=>DAT_fffffff0
//         0042093c     CALL       dword ptr [EAX + 0xd4]
//         00420942     TEST       EAX,EAX
//         00420944     JNZ        LAB_00420f09
//                              basegame.cpp:3695 (5)
//         0042094a     JMP        LAB_00420d04
//                               LAB_0042094f                                                 XREF[1]:     00420884(j)
//                              basegame.cpp:3568 (25)
//         0042094f     CMP        EAX,0x1c
//         00420952     JA         LAB_00420ab7
//         00420958     JZ         LAB_00420968
//         0042095a     CMP        EAX,0x10
//         0042095d     JZ         LAB_00420dc9
//         00420963     JMP        LAB_00420f09
//                               LAB_00420968                                                 XREF[1]:     00420958(j)
//                              basegame.cpp:3703 (11)
//         00420968     MOV        EAX,dword ptr [ESI + 0x14]
//         0042096b     TEST       EAX,EAX
//         0042096d     JZ         LAB_00420a8d
//                              basegame.cpp:3712 (22)
//         00420973     MOV        EAX,[DAT_0062c558]
//         00420978     CMP        EDI,0x1
//         0042097b     JNZ        LAB_00420a45
//         00420981     TEST       EAX,EAX
//         00420983     JZ         LAB_00420a8d
//                              basegame.cpp:3714 (8)
//         00420989     PUSH       0x0
//         0042098b     CALL       dword ptr [->USER32.DLL::SetCursor]              = 0048aeda
//                              basegame.cpp:3715 (14)
//         00420991     MOV        ECX,dword ptr [ESI + 0x10]
//         00420994     PUSH       0x0
//         00420996     PUSH       offset DAT_fffffff8
//         00420998     PUSH       ECX=>DAT_fffffff4
//         00420999     CALL       dword ptr [->USER32.DLL::SetClassLongA]          = 0048aeca
//                              basegame.cpp:3717 (9)
//         0042099f     CMP        dword ptr [ESI + 0x1b0],0x1
//         004209a6     JZ         LAB_004209b2
//                              basegame.cpp:3718 (10)
//         004209a8     MOV        EDX,dword ptr [ESI]
//         004209aa     MOV        ECX,ESI
//         004209ac     CALL       dword ptr [EDX + 0xa8]
//                               LAB_004209b2                                                 XREF[1]:     004209a6(j)
//                              basegame.cpp:3719 (10)
//         004209b2     MOV        dword ptr [DAT_0062c558],0x0
//                              basegame.cpp:3721 (7)
//         004209bc     MOV        ECX,dword ptr [ESI + 0x48]
//         004209bf     TEST       ECX,ECX
//         004209c1     JZ         LAB_004209d7
//                              basegame.cpp:3723 (5)
//         004209c3     CALL       TDrawSystem::CheckSurfaces                       uchar CheckSurfaces(TDrawSystem * this)
//                              basegame.cpp:3724 (8)
//         004209c8     MOV        ECX,dword ptr [ESI + 0x48]
//         004209cb     CALL       TDrawSystem::ClearRestored                       void ClearRestored(TDrawSystem * this)
//                              basegame.cpp:3725 (7)
//         004209d0     MOV        ECX,ESI
//         004209d2     CALL       RGE_Base_Game::set_render_all                    void set_render_all(RGE_Base_Game * this)
//                               LAB_004209d7                                                 XREF[1]:     004209c1(j)
//                              basegame.cpp:3728 (13)
//         004209d7     CMP        dword ptr [ESI + 0x1b0],0x1
//         004209de     JZ         LAB_00420a8d
//                              basegame.cpp:3730 (7)
//         004209e4     MOV        ECX,dword ptr [ESI + 0x48]
//         004209e7     TEST       ECX,ECX
//         004209e9     JZ         LAB_00420a03
//                              basegame.cpp:3732 (5)
//         004209eb     CALL       TDrawSystem::ClearPrimarySurface                 void ClearPrimarySurface(TDrawSystem * this)
//                              basegame.cpp:3733 (19)
//         004209f0     MOV        ECX,dword ptr [ESI + 0x48]
//         004209f3     LEA        EAX,[ECX + 0x78]
//         004209f6     PUSH       EAX
//         004209f7     PUSH       offset DAT_fffffff8
//         004209fc     PUSH       0x0=>DAT_fffffff4
//         004209fe     CALL       TDrawSystem::ModifyPalette                       void ModifyPalette(TDrawSystem * this, int pa
//                               LAB_00420a03                                                 XREF[1]:     004209e9(j)
//                              basegame.cpp:3735 (7)
//         00420a03     MOV        ECX,ESI
//         00420a05     CALL       RGE_Base_Game::set_render_all                    void set_render_all(RGE_Base_Game * this)
//                              basegame.cpp:3736 (14)
//         00420a0a     MOV        ECX,dword ptr [ESI + 0x10]
//         00420a0d     PUSH       0x1
//         00420a0f     PUSH       0x0=>DAT_fffffff8
//         00420a11     PUSH       ECX=>DAT_fffffff4
//         00420a12     CALL       dword ptr [->USER32.DLL::InvalidateRect]         = 0048af16
//                              basegame.cpp:3739 (33)
//         00420a18     PUSH       0xe9b
//         00420a1d     PUSH       s_C:\msdev\work\age1_x1\basegame.c               = "C:\\msdev\\work\\age1_x1\\basegame.cpp"
//         00420a22     MOV        dword ptr [do_restore_palette],0xa
//         00420a2c     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         00420a31     ADD        ESP,0x8
//         00420a34     MOV        [restore_palette_timer],EAX
//                              basegame.cpp:3746 (10)
//         00420a39     MOV        dword ptr [restore_mouse_after_paint],0x1
//                              basegame.cpp:3750 (2)
//         00420a43     JMP        LAB_00420a8d
//                               LAB_00420a45                                                 XREF[1]:     0042097b(j)
//                              basegame.cpp:3752 (4)
//         00420a45     TEST       EAX,EAX
//         00420a47     JNZ        LAB_00420a8d
//                              basegame.cpp:3763 (14)
//         00420a49     MOV        EDX,dword ptr [ESI + 0x10]
//         00420a4c     PUSH       0x0
//         00420a4e     PUSH       offset DAT_fffffff8
//         00420a50     PUSH       EDX=>DAT_fffffff4
//         00420a51     CALL       dword ptr [->USER32.DLL::SetClassLongA]          = 0048aeca
//                              basegame.cpp:3765 (9)
//         00420a57     CMP        dword ptr [ESI + 0x1b0],0x1
//         00420a5e     JZ         LAB_00420a6a
//                              basegame.cpp:3766 (10)
//         00420a60     MOV        EAX,dword ptr [ESI]
//         00420a62     MOV        ECX,ESI
//         00420a64     CALL       dword ptr [EAX + 0xa4]
//                               LAB_00420a6a                                                 XREF[1]:     00420a5e(j)
//                              basegame.cpp:3767 (10)
//         00420a6a     MOV        EAX,0x1
//         00420a6f     MOV        [DAT_0062c558],EAX
//                              basegame.cpp:3769 (10)
//         00420a74     MOV        ECX,dword ptr [ESI + 0x1b0]
//         00420a7a     CMP        ECX,EAX
//         00420a7c     JZ         LAB_00420a8d
//                              basegame.cpp:3771 (10)
//         00420a7e     MOV        ECX,dword ptr [ESI + 0x1c0]
//         00420a84     TEST       ECX,ECX
//         00420a86     JZ         LAB_00420a8d
//                              basegame.cpp:3773 (5)
//         00420a88     CALL       TMousePointer::Shutdown_Mouse                    int Shutdown_Mouse(TMousePointer * this)
//                               LAB_00420a8d                                                 XREF[7]:     0042096d(j), 00420983(j),
//                                                                                                         004209de(j), 00420a43(j),
//                                                                                                         00420a47(j), 00420a7c(j),
//                                                                                                         00420a86(j)
//                              basegame.cpp:3780 (11)
//         00420a8d     PUSH       0x3
//         00420a8f     PUSH       offset DAT_fffffff8
//         00420a91     PUSH       offset DAT_fffffff4
//         00420a93     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:3781 (26)
//         00420a98     MOV        EDX,dword ptr [ESI]
//         00420a9a     ADD        ESP,0xc
//         00420a9d     MOV        ECX,ESI
//         00420a9f     PUSH       EBX
//         00420aa0     PUSH       EDI=>DAT_fffffff8
//         00420aa1     PUSH       offset DAT_fffffff4
//         00420aa3     PUSH       EBP=>DAT_fffffff0
//         00420aa4     CALL       dword ptr [EDX + 0xd8]
//         00420aaa     TEST       EAX,EAX
//         00420aac     JNZ        LAB_00420f09
//                              basegame.cpp:3786 (5)
//         00420ab2     JMP        LAB_00420d04
//                               LAB_00420ab7                                                 XREF[1]:     00420952(j)
//                              basegame.cpp:3568 (20)
//         00420ab7     CMP        EAX,0x104
//         00420abc     JA         LAB_00420b2b
//         00420abe     JZ         LAB_00420afb
//         00420ac0     CMP        EAX,0x100
//         00420ac5     JNZ        LAB_00420f09
//                              basegame.cpp:3616 (14)
//         00420acb     PUSH       0x3
//         00420acd     PUSH       offset DAT_fffffff8
//         00420ad2     PUSH       offset DAT_fffffff4
//         00420ad4     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:3617 (29)
//         00420ad9     MOV        EAX,dword ptr [ESI]
//         00420adb     ADD        ESP,0xc
//         00420ade     MOV        ECX,ESI
//         00420ae0     PUSH       EBX
//         00420ae1     PUSH       EDI=>DAT_fffffff8
//         00420ae2     PUSH       offset DAT_fffffff4
//         00420ae7     PUSH       EBP=>DAT_fffffff0
//         00420ae8     CALL       dword ptr [EAX + 0xc4]
//         00420aee     TEST       EAX,EAX
//         00420af0     JNZ        LAB_00420f09
//                              basegame.cpp:3622 (5)
//         00420af6     JMP        LAB_00420d04
//                               LAB_00420afb                                                 XREF[1]:     00420abe(j)
//                              basegame.cpp:3604 (14)
//         00420afb     PUSH       0x3
//         00420afd     PUSH       offset DAT_fffffff8
//         00420b02     PUSH       offset DAT_fffffff4
//         00420b04     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:3606 (29)
//         00420b09     MOV        EDX,dword ptr [ESI]
//         00420b0b     ADD        ESP,0xc
//         00420b0e     MOV        ECX,ESI
//         00420b10     PUSH       EBX
//         00420b11     PUSH       EDI=>DAT_fffffff8
//         00420b12     PUSH       offset DAT_fffffff4
//         00420b17     PUSH       EBP=>DAT_fffffff0
//         00420b18     CALL       dword ptr [EDX + 0xc4]
//         00420b1e     TEST       EAX,EAX
//         00420b20     JNZ        LAB_00420f09
//                              basegame.cpp:3611 (5)
//         00420b26     JMP        LAB_00420d04
//                               LAB_00420b2b                                                 XREF[1]:     00420abc(j)
//                              basegame.cpp:3568 (20)
//         00420b2b     CMP        EAX,0x111
//         00420b30     JA         LAB_00420ba0
//         00420b32     JZ         LAB_00420b73
//         00420b34     CMP        EAX,0x105
//         00420b39     JNZ        LAB_00420f09
//                              basegame.cpp:3630 (9)
//         00420b3f     CMP        EDI,0x12
//         00420b42     JNZ        LAB_00420f09
//                              basegame.cpp:3632 (18)
//         00420b48     MOV        ECX,panel_system
//         00420b4d     CALL       TPanelSystem::currentPanel                       TPanel * currentPanel(TPanelSystem * this)
//         00420b52     TEST       EAX,EAX
//         00420b54     JZ         LAB_00420f09
//                              basegame.cpp:3633 (20)
//         00420b5a     MOV        ECX,panel_system
//         00420b5f     CALL       TPanelSystem::currentPanel                       TPanel * currentPanel(TPanelSystem * this)
//         00420b64     MOV        EDX,dword ptr [EAX]
//         00420b66     MOV        ECX,EAX
//         00420b68     CALL       dword ptr [EDX + 0xdc]
//                              basegame.cpp:3635 (5)
//         00420b6e     JMP        LAB_00420f09
//                               LAB_00420b73                                                 XREF[1]:     00420b32(j)
//                              basegame.cpp:3666 (11)
//         00420b73     PUSH       0x3
//         00420b75     PUSH       offset DAT_fffffff8
//         00420b77     PUSH       offset DAT_fffffff4
//         00420b79     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:3667 (29)
//         00420b7e     MOV        EAX,dword ptr [ESI]
//         00420b80     ADD        ESP,0xc
//         00420b83     MOV        ECX,ESI
//         00420b85     PUSH       EBX
//         00420b86     PUSH       EDI=>DAT_fffffff8
//         00420b87     PUSH       offset DAT_fffffff4
//         00420b8c     PUSH       EBP=>DAT_fffffff0
//         00420b8d     CALL       dword ptr [EAX + 0xcc]
//         00420b93     TEST       EAX,EAX
//         00420b95     JNZ        LAB_00420f09
//                              basegame.cpp:3672 (5)
//         00420b9b     JMP        LAB_00420d04
//                               LAB_00420ba0                                                 XREF[1]:     00420b30(j)
//                              basegame.cpp:3568 (36)
//         00420ba0     CMP        EAX,0x200
//         00420ba5     JA         LAB_00420cc1
//         00420bab     JZ         LAB_00420c3a
//         00420bb1     SUB        EAX,0x112
//         00420bb6     JZ         LAB_00420c03
//         00420bb8     DEC        EAX
//         00420bb9     JZ         LAB_00420bf4
//         00420bbb     SUB        EAX,0x3
//         00420bbe     JNZ        LAB_00420f09
//                              basegame.cpp:3884 (14)
//         00420bc4     PUSH       0x3
//         00420bc6     PUSH       offset DAT_fffffff8
//         00420bcb     PUSH       offset DAT_fffffff4
//         00420bcd     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:3885 (29)
//         00420bd2     MOV        EDX,dword ptr [ESI]
//         00420bd4     ADD        ESP,0xc
//         00420bd7     MOV        ECX,ESI
//         00420bd9     PUSH       EBX
//         00420bda     PUSH       EDI=>DAT_fffffff8
//         00420bdb     PUSH       offset DAT_fffffff4
//         00420be0     PUSH       EBP=>DAT_fffffff0
//         00420be1     CALL       dword ptr [EDX + 0xdc]
//         00420be7     TEST       EAX,EAX
//         00420be9     JNZ        LAB_00420f09
//                              basegame.cpp:3890 (5)
//         00420bef     JMP        LAB_00420d04
//                               LAB_00420bf4                                                 XREF[1]:     00420bb9(j)
//                              basegame.cpp:3571 (10)
//         00420bf4     MOV        EAX,dword ptr [ESI]
//         00420bf6     MOV        ECX,ESI
//         00420bf8     CALL       dword ptr [EAX + 0xbc]
//                              basegame.cpp:3572 (5)
//         00420bfe     JMP        LAB_00420f09
//                               LAB_00420c03                                                 XREF[1]:     00420bb6(j)
//                              basegame.cpp:3638 (47)
//         00420c03     CMP        EDI,0xf100
//         00420c09     JNZ        LAB_00420f09
//         00420c0f     MOV        ECX,dword ptr [ESI + 0xc]
//         00420c12     MOV        EAX,dword ptr [ECX + 0x894]
//         00420c18     TEST       EAX,EAX
//         00420c1a     JZ         LAB_00420f09
//         00420c20     MOV        EDX,dword ptr [ESI + 0x10]
//         00420c23     PUSH       EDX
//         00420c24     CALL       dword ptr [->USER32.DLL::IsIconic]               = 0048ae70
//         00420c2a     TEST       EAX,EAX
//         00420c2c     JNZ        LAB_00420f09
//                              basegame.cpp:3975 (8)
//         00420c32     POP        EDI
//         00420c33     POP        ESI
//         00420c34     POP        EBP
//         00420c35     POP        EBX
//         00420c36     POP        ECX
//         00420c37     RET        0x14
//                               LAB_00420c3a                                                 XREF[1]:     00420bab(j)
//                              basegame.cpp:3575 (11)
//         00420c3a     PUSH       0x3
//         00420c3c     PUSH       offset DAT_fffffff8
//         00420c3e     PUSH       offset DAT_fffffff4
//         00420c40     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:3577 (23)
//         00420c45     MOV        EAX,dword ptr [ESI]
//         00420c47     ADD        ESP,0xc
//         00420c4a     MOV        ECX,ESI
//         00420c4c     PUSH       EBX
//         00420c4d     PUSH       EDI=>DAT_fffffff8
//         00420c4e     PUSH       offset DAT_fffffff4
//         00420c53     PUSH       EBP=>DAT_fffffff0
//         00420c54     CALL       dword ptr [EAX + 0xc0]
//         00420c5a     TEST       EAX,EAX
//                              basegame.cpp:3582 (6)
//         00420c5c     JZ         LAB_00420d04
//                              basegame.cpp:3585 (13)
//         00420c62     MOV        EAX,[MouseCursorInChildContol]
//         00420c67     TEST       EAX,EAX
//         00420c69     JZ         LAB_00420f09
//                              basegame.cpp:3587 (10)
//         00420c6f     MOV        EAX,dword ptr [ESI + 0x1d0]
//         00420c75     TEST       EAX,EAX
//         00420c77     JNZ        LAB_00420ca5
//                              basegame.cpp:3589 (8)
//         00420c79     PUSH       0x0
//         00420c7b     CALL       dword ptr [->USER32.DLL::SetCursor]              = 0048aeda
//                              basegame.cpp:3590 (14)
//         00420c81     MOV        ECX,dword ptr [ESI + 0x10]
//         00420c84     PUSH       0x0
//         00420c86     PUSH       offset DAT_fffffff8
//         00420c88     PUSH       ECX=>DAT_fffffff4
//         00420c89     CALL       dword ptr [->USER32.DLL::SetClassLongA]          = 0048aeca
//                              basegame.cpp:3591 (7)
//         00420c8f     MOV        ECX,ESI
//         00420c91     CALL       RGE_Base_Game::mouse_on                          void mouse_on(RGE_Base_Game * this)
//                              basegame.cpp:3597 (10)
//         00420c96     MOV        dword ptr [MouseCursorInChildContol],0x0
//                              basegame.cpp:3601 (5)
//         00420ca0     JMP        LAB_00420f09
//                               LAB_00420ca5                                                 XREF[1]:     00420c77(j)
//                              basegame.cpp:3595 (13)
//         00420ca5     MOV        EDX,dword ptr [ESI + 0x1d4]
//         00420cab     PUSH       EDX
//         00420cac     CALL       dword ptr [->USER32.DLL::SetCursor]              = 0048aeda
//                              basegame.cpp:3597 (10)
//         00420cb2     MOV        dword ptr [MouseCursorInChildContol],0x0
//                              basegame.cpp:3601 (5)
//         00420cbc     JMP        LAB_00420f09
//                               LAB_00420cc1                                                 XREF[1]:     00420ba5(j)
//                              basegame.cpp:3568 (24)
//         00420cc1     CMP        EAX,0x218
//         00420cc6     JA         LAB_00420d4d
//         00420ccc     JZ         LAB_00420d38
//         00420cce     CMP        EAX,0x212
//         00420cd3     JNZ        LAB_00420f09
//                              basegame.cpp:3895 (14)
//         00420cd9     PUSH       0x3
//         00420cdb     PUSH       offset DAT_fffffff8
//         00420ce0     PUSH       offset DAT_fffffff4
//         00420ce2     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:3896 (29)
//         00420ce7     MOV        EAX,dword ptr [ESI]
//         00420ce9     ADD        ESP,0xc
//         00420cec     MOV        ECX,ESI
//         00420cee     PUSH       EBX
//         00420cef     PUSH       EDI=>DAT_fffffff8
//         00420cf0     PUSH       offset DAT_fffffff4
//         00420cf5     PUSH       EBP=>DAT_fffffff0
//         00420cf6     CALL       dword ptr [EAX + 0xe0]
//         00420cfc     TEST       EAX,EAX
//         00420cfe     JNZ        LAB_00420f09
//                               LAB_00420d04                                                 XREF[8]:     004207bc(j), 0042094a(j),
//                                                                                                         00420ab2(j), 00420af6(j),
//                                                                                                         00420b26(j), 00420b9b(j),
//                                                                                                         00420bef(j), 00420c5c(j)
//                              basegame.cpp:3898 (12)
//         00420d04     MOV        EAX,dword ptr [ESP + 0x10]
//         00420d08     TEST       EAX,EAX
//         00420d0a     JZ         LAB_00420e74
//                              basegame.cpp:3899 (14)
//         00420d10     PUSH       0x4
//         00420d12     PUSH       offset DAT_fffffff8
//         00420d14     PUSH       offset DAT_fffffff4
//         00420d16     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         00420d1b     ADD        ESP,0xc
//                              basegame.cpp:3900 (11)
//         00420d1e     PUSH       0x3
//         00420d20     PUSH       offset DAT_fffffff8
//         00420d22     PUSH       offset DAT_fffffff4
//         00420d24     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:3901 (7)
//         00420d29     MOV        EAX,dword ptr [ESP + 0x24]
//         00420d2d     ADD        ESP,0xc
//                              basegame.cpp:3975 (8)
//         00420d30     POP        EDI
//         00420d31     POP        ESI
//         00420d32     POP        EBP
//         00420d33     POP        EBX
//         00420d34     POP        ECX
//         00420d35     RET        0x14
//                               LAB_00420d38                                                 XREF[1]:     00420ccc(j)
//                              basegame.cpp:3962 (8)
//         00420d38     TEST       EDI,EDI
//         00420d3a     JNZ        LAB_00420f09
//                              basegame.cpp:3963 (5)
//         00420d40     MOV        EAX,0x424d5144
//                              basegame.cpp:3975 (8)
//         00420d45     POP        EDI
//         00420d46     POP        ESI
//         00420d47     POP        EBP
//         00420d48     POP        EBX
//         00420d49     POP        ECX
//         00420d4a     RET        0x14
//                               LAB_00420d4d                                                 XREF[1]:     00420cc6(j)
//                              basegame.cpp:3568 (33)
//         00420d4d     CMP        EAX,0x3b9
//         00420d52     JA         LAB_00420e24
//         00420d58     JZ         LAB_00420e36
//         00420d5e     SUB        EAX,0x30f
//         00420d63     JZ         LAB_00420d9e
//         00420d65     SUB        EAX,0x2
//         00420d68     JNZ        LAB_00420f09
//                              basegame.cpp:3919 (14)
//         00420d6e     PUSH       0x3
//         00420d70     PUSH       offset DAT_fffffff8
//         00420d75     PUSH       offset DAT_fffffff4
//         00420d77     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:3920 (29)
//         00420d7c     MOV        EDX,dword ptr [ESI]
//         00420d7e     ADD        ESP,0xc
//         00420d81     MOV        ECX,ESI
//         00420d83     PUSH       EBX
//         00420d84     PUSH       EDI=>DAT_fffffff8
//         00420d85     PUSH       offset DAT_fffffff4
//         00420d8a     PUSH       EBP=>DAT_fffffff0
//         00420d8b     CALL       dword ptr [EDX + 0xe8]
//         00420d91     TEST       EAX,EAX
//         00420d93     JNZ        LAB_00420f09
//                              basegame.cpp:3925 (5)
//         00420d99     JMP        LAB_00420e5e
//                               LAB_00420d9e                                                 XREF[1]:     00420d63(j)
//                              basegame.cpp:3930 (14)
//         00420d9e     PUSH       0x3
//         00420da0     PUSH       offset DAT_fffffff8
//         00420da5     PUSH       offset DAT_fffffff4
//         00420da7     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:3931 (23)
//         00420dac     MOV        EAX,dword ptr [ESI]
//         00420dae     ADD        ESP,0xc
//         00420db1     MOV        ECX,ESI
//         00420db3     PUSH       EBX
//         00420db4     PUSH       EDI=>DAT_fffffff8
//         00420db5     PUSH       offset DAT_fffffff4
//         00420dba     PUSH       EBP=>DAT_fffffff0
//         00420dbb     CALL       dword ptr [EAX + 0xec]
//         00420dc1     TEST       EAX,EAX
//                              basegame.cpp:3936 (6)
//         00420dc3     JZ         LAB_00420e5e
//                               LAB_00420dc9                                                 XREF[1]:     0042095d(j)
//                              basegame.cpp:3940 (14)
//         00420dc9     PUSH       0x3
//         00420dcb     PUSH       offset DAT_fffffff8
//         00420dd0     PUSH       offset DAT_fffffff4
//         00420dd2     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:3941 (29)
//         00420dd7     MOV        EAX,dword ptr [ESP + 0x2c]
//         00420ddb     MOV        EDX,dword ptr [ESI]
//         00420ddd     ADD        ESP,0xc
//         00420de0     MOV        ECX,ESI
//         00420de2     PUSH       EBX
//         00420de3     PUSH       EDI=>DAT_fffffff8
//         00420de4     PUSH       EAX=>DAT_fffffff4
//         00420de5     PUSH       EBP=>DAT_fffffff0
//         00420de6     CALL       dword ptr [EDX + 0xf0]
//         00420dec     TEST       EAX,EAX
//         00420dee     JNZ        LAB_00420f09
//                              basegame.cpp:3943 (8)
//         00420df4     MOV        EAX,dword ptr [ESP + 0x10]
//         00420df8     TEST       EAX,EAX
//         00420dfa     JZ         LAB_00420e74
//                              basegame.cpp:3944 (14)
//         00420dfc     PUSH       0x4
//         00420dfe     PUSH       offset DAT_fffffff8
//         00420e00     PUSH       offset DAT_fffffff4
//         00420e02     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         00420e07     ADD        ESP,0xc
//                              basegame.cpp:3945 (11)
//         00420e0a     PUSH       0x3
//         00420e0c     PUSH       offset DAT_fffffff8
//         00420e0e     PUSH       offset DAT_fffffff4
//         00420e10     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:3946 (7)
//         00420e15     MOV        EAX,dword ptr [ESP + 0x24]
//         00420e19     ADD        ESP,0xc
//                              basegame.cpp:3975 (8)
//         00420e1c     POP        EDI
//         00420e1d     POP        ESI
//         00420e1e     POP        EBP
//         00420e1f     POP        EBX
//         00420e20     POP        ECX
//         00420e21     RET        0x14
//                               LAB_00420e24                                                 XREF[1]:     00420d52(j)
//                              basegame.cpp:3568 (18)
//         00420e24     CMP        EAX,0x400
//         00420e29     JZ         LAB_00420e8e
//         00420e2b     CMP        EAX,0x500
//         00420e30     JNZ        LAB_00420f09
//                               LAB_00420e36                                                 XREF[1]:     00420d58(j)
//                              basegame.cpp:3678 (11)
//         00420e36     PUSH       0x3
//         00420e38     PUSH       offset DAT_fffffff8
//         00420e3a     PUSH       offset DAT_fffffff4
//         00420e3c     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:3679 (29)
//         00420e41     MOV        EAX,dword ptr [ESP + 0x2c]
//         00420e45     MOV        EDX,dword ptr [ESI]
//         00420e47     ADD        ESP,0xc
//         00420e4a     MOV        ECX,ESI
//         00420e4c     PUSH       EBX
//         00420e4d     PUSH       EDI=>DAT_fffffff8
//         00420e4e     PUSH       EAX=>DAT_fffffff4
//         00420e4f     PUSH       EBP=>DAT_fffffff0
//         00420e50     CALL       dword ptr [EDX + 0xd0]
//         00420e56     TEST       EAX,EAX
//         00420e58     JNZ        LAB_00420f09
//                               LAB_00420e5e                                                 XREF[3]:     00420813(j), 00420d99(j),
//                                                                                                         00420dc3(j)
//                              basegame.cpp:3681 (8)
//         00420e5e     MOV        EAX,dword ptr [ESP + 0x10]
//         00420e62     TEST       EAX,EAX
//         00420e64     JZ         LAB_00420e74
//                              basegame.cpp:3682 (14)
//         00420e66     PUSH       0x4
//         00420e68     PUSH       offset DAT_fffffff8
//         00420e6a     PUSH       offset DAT_fffffff4
//         00420e6c     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         00420e71     ADD        ESP,0xc
//                               LAB_00420e74                                                 XREF[4]:     00420853(j), 00420d0a(j),
//                                                                                                         00420dfa(j), 00420e64(j)
//                              basegame.cpp:3683 (11)
//         00420e74     PUSH       0x3
//         00420e76     PUSH       offset DAT_fffffff8
//         00420e78     PUSH       offset DAT_fffffff4
//         00420e7a     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:3684 (7)
//         00420e7f     MOV        EAX,dword ptr [ESP + 0x24]
//         00420e83     ADD        ESP,0xc
//                              basegame.cpp:3975 (8)
//         00420e86     POP        EDI
//         00420e87     POP        ESI
//         00420e88     POP        EBP
//         00420e89     POP        EBX
//         00420e8a     POP        ECX
//         00420e8b     RET        0x14
//                               LAB_00420e8e                                                 XREF[1]:     00420e29(j)
//                              basegame.cpp:3644 (11)
//         00420e8e     PUSH       0x3
//         00420e90     PUSH       offset DAT_fffffff8
//         00420e92     PUSH       offset DAT_fffffff4
//         00420e94     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:3646 (6)
//         00420e99     MOV        ECX,dword ptr [debug_timeGetTime_on]
//                              basegame.cpp:3649 (39)
//         00420e9f     MOV        EDX,dword ptr [ESI]
//         00420ea1     ADD        ESP,0xc
//         00420ea4     MOV        dword ptr [ESP + 0x1c],ECX
//         00420ea8     MOV        ECX,ESI
//         00420eaa     MOV        dword ptr [debug_timeGetTime_on],0x0
//         00420eb4     PUSH       EBX
//         00420eb5     PUSH       EDI=>DAT_fffffff8
//         00420eb6     PUSH       offset DAT_fffffff4
//         00420ebb     PUSH       EBP=>DAT_fffffff0
//         00420ebc     CALL       dword ptr [EDX + 0xc8]
//         00420ec2     TEST       EAX,EAX
//         00420ec4     JNZ        LAB_00420eff
//                              basegame.cpp:3651 (8)
//         00420ec6     MOV        EAX,dword ptr [ESP + 0x10]
//         00420eca     TEST       EAX,EAX
//         00420ecc     JZ         LAB_00420edc
//                              basegame.cpp:3652 (14)
//         00420ece     PUSH       0x4
//         00420ed0     PUSH       offset DAT_fffffff8
//         00420ed2     PUSH       offset DAT_fffffff4
//         00420ed4     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         00420ed9     ADD        ESP,0xc
//                               LAB_00420edc                                                 XREF[1]:     00420ecc(j)
//                              basegame.cpp:3653 (11)
//         00420edc     PUSH       0x3
//         00420ede     PUSH       offset DAT_fffffff8
//         00420ee0     PUSH       offset DAT_fffffff4
//         00420ee2     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:3655 (12)
//         00420ee7     MOV        EAX,dword ptr [ESP + 0x28]
//         00420eeb     ADD        ESP,0xc
//         00420eee     MOV        [debug_timeGetTime_on],EAX
//                              basegame.cpp:3657 (4)
//         00420ef3     MOV        EAX,dword ptr [ESP + 0x18]
//                              basegame.cpp:3975 (8)
//         00420ef7     POP        EDI
//         00420ef8     POP        ESI
//         00420ef9     POP        EBP
//         00420efa     POP        EBX
//         00420efb     POP        ECX
//         00420efc     RET        0x14
//                               LAB_00420eff                                                 XREF[1]:     00420ec4(j)
//                              basegame.cpp:3660 (10)
//         00420eff     MOV        ECX,dword ptr [ESP + 0x1c]
//         00420f03     MOV        dword ptr [debug_timeGetTime_on],ECX
//                               LAB_00420f09                                                 XREF[39]:    004207e5(j), 0042080d(j),
//                                                                                                         0042081f(j), 00420847(j),
//                                                                                                         00420896(j), 004208a0(j),
//                                                                                                         004208f3(j), 004208fb(j),
//                                                                                                         00420903(j), 00420910(j),
//                                                                                                         00420920(j), 00420944(j),
//                                                                                                         00420963(j), 00420aac(j),
//                                                                                                         00420ac5(j), 00420af0(j),
//                                                                                                         00420b20(j), 00420b39(j),
//                                                                                                         00420b42(j), 00420b54(j), [more]
//                              basegame.cpp:3968 (11)
//         00420f09     PUSH       0x3
//         00420f0b     PUSH       offset DAT_fffffff8
//         00420f0d     PUSH       offset DAT_fffffff4
//         00420f0f     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:3969 (19)
//         00420f14     MOV        EDX,dword ptr [ESP + 0x2c]
//         00420f18     ADD        ESP,0xc
//         00420f1b     PUSH       EBX
//         00420f1c     PUSH       EDI=>DAT_fffffff8
//         00420f1d     PUSH       EDX=>DAT_fffffff4
//         00420f1e     PUSH       EBP=>DAT_fffffff0
//         00420f1f     CALL       dword ptr [->USER32.DLL::DefWindowProcA]         = 0048af04
//         00420f25     MOV        ESI,EAX
//                              basegame.cpp:3971 (8)
//         00420f27     MOV        EAX,dword ptr [ESP + 0x10]
//         00420f2b     TEST       EAX,EAX
//         00420f2d     JZ         LAB_00420f3d
//                              basegame.cpp:3972 (14)
//         00420f2f     PUSH       0x4
//         00420f31     PUSH       offset DAT_fffffff8
//         00420f33     PUSH       offset DAT_fffffff4
//         00420f35     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         00420f3a     ADD        ESP,0xc
//                               LAB_00420f3d                                                 XREF[1]:     00420f2d(j)
//                              basegame.cpp:3973 (14)
//         00420f3d     PUSH       0x3
//         00420f3f     PUSH       offset DAT_fffffff8
//         00420f41     PUSH       offset DAT_fffffff4
//         00420f43     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         00420f48     ADD        ESP,0xc
//                              basegame.cpp:3974 (2)
//         00420f4b     MOV        EAX,ESI
//                              basegame.cpp:3975 (8)
//         00420f4d     POP        EDI
//         00420f4e     POP        ESI
//         00420f4f     POP        EBP
//         00420f50     POP        EBX
//         00420f51     POP        ECX
//         00420f52     RET        0x14
//         00420f55     ??         90h
//         00420f56     NOP
//         00420f57     NOP
//         00420f58     NOP
//         00420f59     NOP
//         00420f5a     NOP
//         00420f5b     NOP
//         00420f5c     NOP
//         00420f5d     NOP
//         00420f5e     NOP
//         00420f5f     NOP
    return 0;
}

int RGE_Base_Game::handle_idle() {
    /* TODO: Stub */
//                              int __thiscall handle_idle(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?handle_idle@RGE_Base_Game@@MAEHXZ                           XREF[2]:     handle_idle:0052961c(c),
//                               RGE_Base_Game::handle_idle                                                0056ef8c(*)
//                              basegame.cpp:3981 (4)
//         00420f60     PUSH       ESI
//         00420f61     MOV        ESI,this
//         00420f63     PUSH       EDI
//                              basegame.cpp:3982 (22)
//         00420f64     MOV        EAX,dword ptr [ESI + 0x14]
//         00420f67     TEST       EAX,EAX
//         00420f69     JZ         LAB_0042110a
//         00420f6f     MOV        EAX,dword ptr [ESI + 0x10]
//         00420f72     TEST       EAX,EAX
//         00420f74     JZ         LAB_0042110a
//                              basegame.cpp:3985 (11)
//         00420f7a     PUSH       0x2
//         00420f7c     PUSH       0x16
//         00420f7e     PUSH       0x16
//         00420f80     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:3989 (19)
//         00420f85     MOV        EAX,[do_restore_palette]
//         00420f8a     ADD        ESP,0xc
//         00420f8d     TEST       EAX,EAX
//         00420f8f     JZ         LAB_00420ffe
//         00420f91     MOV        this,dword ptr [ESI + 0x18]
//         00420f94     TEST       this,this
//         00420f96     JZ         LAB_00420ffe
//                              basegame.cpp:3992 (10)
//         00420f98     CMP        EAX,0x5
//         00420f9b     MOV        EDI,0xfa
//         00420fa0     JLE        LAB_00420fa7
//                              basegame.cpp:3993 (5)
//         00420fa2     MOV        EDI,0x1f4
//                               LAB_00420fa7                                                 XREF[1]:     00420fa0(j)
//                              basegame.cpp:3994 (30)
//         00420fa7     PUSH       0xf9a
//         00420fac     PUSH       s_C:\msdev\work\age1_x1\basegame.c               = "C:\\msdev\\work\\age1_x1\\basegame.cpp"
//         00420fb1     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         00420fb6     MOV        EDX,dword ptr [restore_palette_timer]
//         00420fbc     ADD        ESP,0x8
//         00420fbf     SUB        EAX,EDX
//         00420fc1     CMP        EAX,EDI
//         00420fc3     JC         LAB_00420ffe
//                              basegame.cpp:3996 (7)
//         00420fc5     MOV        this,dword ptr [ESI + 0x48]
//         00420fc8     TEST       this,this
//         00420fca     JZ         LAB_00420fdc
//                              basegame.cpp:3999 (16)
//         00420fcc     LEA        EAX,[ECX + this->save_music_track_to]
//         00420fcf     PUSH       EAX
//         00420fd0     PUSH       0x100
//         00420fd5     PUSH       0x0
//         00420fd7     CALL       TDrawSystem::ModifyPalette                       void ModifyPalette(TDrawSystem * this, int pa
//                               LAB_00420fdc                                                 XREF[1]:     00420fca(j)
//                              basegame.cpp:4003 (5)
//         00420fdc     MOV        EAX,[do_restore_palette]
//                              language.dll match for 0xfa4: "No"
//                              basegame.cpp:4004 (29)
//         00420fe1     PUSH       0xfa4
//         00420fe6     DEC        EAX
//         00420fe7     PUSH       s_C:\msdev\work\age1_x1\basegame.c               = "C:\\msdev\\work\\age1_x1\\basegame.cpp"
//         00420fec     MOV        [do_restore_palette],EAX
//         00420ff1     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         00420ff6     ADD        ESP,0x8
//         00420ff9     MOV        [restore_palette_timer],EAX
//                               LAB_00420ffe                                                 XREF[3]:     00420f8f(j), 00420f96(j),
//                                                                                                         00420fc3(j)
//                              basegame.cpp:4008 (11)
//         00420ffe     PUSH       0x5
//         00421000     PUSH       0x32
//         00421002     PUSH       0x32
//         00421004     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:4010 (10)
//         00421009     MOV        EAX,dword ptr [ESI + 0x60]
//         0042100c     ADD        ESP,0xc
//         0042100f     TEST       EAX,EAX
//         00421011     JZ         LAB_00421039
//                              basegame.cpp:4012 (14)
//         00421013     PUSH       0x2
//         00421015     PUSH       0xba
//         0042101a     PUSH       0x16
//         0042101c     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:4013 (24)
//         00421021     MOV        this,dword ptr [ESI + 0x10]
//         00421024     ADD        ESP,0xc
//         00421027     PUSH       0x0
//         00421029     PUSH       0x0
//         0042102b     PUSH       0x113
//         00421030     PUSH       this
//         00421031     MOV        this,dword ptr [ESI + 0x60]
//         00421034     CALL       TSound_Driver::handle_messages                   uint handle_messages(TSound_Driver * this, vo
//                               LAB_00421039                                                 XREF[1]:     00421011(j)
//                              basegame.cpp:4016 (14)
//         00421039     MOV        this,panel_system
//         0042103e     CALL       TPanelSystem::currentPanel                       TPanel * currentPanel(TPanelSystem * this)
//         00421043     TEST       EAX,EAX
//         00421045     JZ         LAB_00421066
//                              basegame.cpp:4018 (14)
//         00421047     PUSH       0x2
//         00421049     PUSH       0x45
//         0042104b     PUSH       0x16
//         0042104d     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         00421052     ADD        ESP,0xc
//                              basegame.cpp:4019 (17)
//         00421055     MOV        this,panel_system
//         0042105a     CALL       TPanelSystem::currentPanel                       TPanel * currentPanel(TPanelSystem * this)
//         0042105f     MOV        EDX,dword ptr [EAX]
//         00421061     MOV        this,EAX
//         00421063     CALL       dword ptr [EDX + 0x4c]
//                               LAB_00421066                                                 XREF[1]:     00421045(j)
//                              basegame.cpp:4025 (21)
//         00421066     MOV        EAX,dword ptr [ESI + 0x18c]
//         0042106c     TEST       EAX,EAX
//         0042106e     JZ         LAB_004210a2
//         00421070     MOV        this,ESI
//         00421072     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         00421077     TEST       EAX,EAX
//         00421079     JZ         LAB_004210a2
//                              basegame.cpp:4028 (11)
//         0042107b     PUSH       0x1
//         0042107d     PUSH       offset DAT_fffffff8
//         0042107f     PUSH       offset DAT_fffffff4
//         00421081     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:4029 (14)
//         00421086     MOV        this,dword ptr [ESI + 0x18c]
//         0042108c     ADD        ESP,0xc
//         0042108f     CALL       TCommunications_Handler::ReceiveGameMessages     void ReceiveGameMessages(TCommunications_Hand
//                              basegame.cpp:4030 (14)
//         00421094     PUSH       0x1
//         00421096     PUSH       offset DAT_fffffff8
//         00421098     PUSH       offset DAT_fffffff4
//         0042109a     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         0042109f     ADD        ESP,0xc
//                               LAB_004210a2                                                 XREF[2]:     0042106e(j), 00421079(j)
//                              basegame.cpp:4034 (10)
//         004210a2     MOV        EAX,dword ptr [ESI + 0x8ec]
//         004210a8     TEST       EAX,EAX
//         004210aa     JZ         LAB_004210c4
//                              basegame.cpp:4036 (11)
//         004210ac     PUSH       0x2
//         004210ae     PUSH       offset DAT_fffffff8
//         004210b0     PUSH       offset DAT_fffffff4
//         004210b2     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:4037 (13)
//         004210b7     MOV        EAX,dword ptr [ESI]
//         004210b9     ADD        ESP,0xc
//         004210bc     MOV        this,ESI
//         004210be     CALL       dword ptr [EAX + 0x134]
//                               LAB_004210c4                                                 XREF[1]:     004210aa(j)
//                              basegame.cpp:4040 (10)
//         004210c4     MOV        EAX,dword ptr [ESI + 0x8f0]
//         004210ca     TEST       EAX,EAX
//         004210cc     JZ         LAB_004210e6
//                              basegame.cpp:4042 (11)
//         004210ce     PUSH       0x2
//         004210d0     PUSH       offset DAT_fffffff8
//         004210d2     PUSH       offset DAT_fffffff4
//         004210d4     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:4043 (13)
//         004210d9     MOV        EDX,dword ptr [ESI]
//         004210db     ADD        ESP,0xc
//         004210de     MOV        this,ESI
//         004210e0     CALL       dword ptr [EDX + 0x138]
//                               LAB_004210e6                                                 XREF[1]:     004210cc(j)
//                              basegame.cpp:4094 (14)
//         004210e6     PUSH       0x5
//         004210e8     PUSH       offset DAT_fffffff8
//         004210ea     PUSH       offset DAT_fffffff4
//         004210ec     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         004210f1     ADD        ESP,0xc
//                              basegame.cpp:4095 (14)
//         004210f4     PUSH       0x2
//         004210f6     PUSH       offset DAT_fffffff8
//         004210f8     PUSH       offset DAT_fffffff4
//         004210fa     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         004210ff     ADD        ESP,0xc
//                              basegame.cpp:4097 (5)
//         00421102     MOV        EAX,0x1
//                              basegame.cpp:4098 (8)
//         00421107     POP        EDI
//         00421108     POP        ESI
//         00421109     RET
//                               LAB_0042110a                                                 XREF[2]:     00420f69(j), 00420f74(j)
//         0042110a     POP        EDI
//         0042110b     XOR        EAX,EAX
//         0042110d     POP        ESI
//         0042110e     RET
//         0042110f     ??         90h
    return 0;
}

int RGE_Base_Game::handle_mouse_move(void* param_1, uint param_2, uint param_3, long param_4) {
    /* TODO: Stub */
//                              int __thiscall handle_mouse_move(RGE_Base_Game * this, void * param_
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              void *            Stack[0x4]:4   param_1
//              uint              Stack[0x8]:4   param_2
//              uint              Stack[0xc]:4   param_3                   XREF[1]:     00421180(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     00421177(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004211a2(R)
//              tagPOINT          Stack[-0xc]:8  point                     XREF[2,2]:   00421172(*), 0042119d(R), 0042117b(*), 004211a7(R)
//              int               Stack[-0x10]:4 left_btn                  XREF[2]:     0042116d(*), 00421196(R)
//              int               Stack[-0x14]:4 right_btn                 XREF[2]:     00421168(*), 00421192(R)
//              int               Stack[-0x18]:4 ctrl_key                  XREF[2]:     00421164(*), 0042118e(R)
//              int               Stack[-0x1c]:4 shift_key
//                               ?handle_mouse_move@RGE_Base_Game@@MAEHPAXIIJ@Z               XREF[2]:     0056ef90(*), 00577268(*)
//                               RGE_Base_Game::handle_mouse_move
//                              basegame.cpp:4104 (6)
//         00421110     SUB        ESP,0x18
//         00421113     PUSH       ESI
//         00421114     MOV        ESI,this
//                              basegame.cpp:4111 (7)
//         00421116     MOV        EAX,dword ptr [ESI + 0x14]
//         00421119     TEST       EAX,EAX
//         0042111b     JNZ        LAB_00421129
//                              basegame.cpp:4112 (5)
//         0042111d     MOV        EAX,0x1
//                              basegame.cpp:4143 (7)
//         00421122     POP        ESI
//         00421123     ADD        ESP,0x18
//         00421126     RET        0x10
//                               LAB_00421129                                                 XREF[1]:     0042111b(j)
//                              basegame.cpp:4120 (18)
//         00421129     MOV        EAX,dword ptr [ESI + 0x54]
//         0042112c     PUSH       EDI
//         0042112d     TEST       EAX,EAX
//         0042112f     JZ         LAB_00421164
//         00421131     MOV        EAX,dword ptr [ESI + 0x1d0]
//         00421137     TEST       EAX,EAX
//         00421139     JNZ        LAB_00421164
//                              basegame.cpp:4124 (15)
//         0042113b     MOV        this,dword ptr [ESI + 0x1c0]
//         00421141     CALL       TMousePointer::in_game_mode                      int in_game_mode(TMousePointer * this)
//         00421146     TEST       EAX,EAX
//         00421148     JZ         LAB_00421157
//                              basegame.cpp:4126 (11)
//         0042114a     MOV        this,dword ptr [ESI + 0x1c0]
//         00421150     CALL       TMousePointer::Poll                              void Poll(TMousePointer * this)
//                              basegame.cpp:4128 (2)
//         00421155     JMP        LAB_00421164
//                               LAB_00421157                                                 XREF[1]:     00421148(j)
//                              basegame.cpp:4130 (13)
//         00421157     MOV        this,dword ptr [ESI + 0x1c0]
//         0042115d     PUSH       0x0
//         0042115f     CALL       TMousePointer::draw                              void draw(TMousePointer * this, int param_1)
//                               LAB_00421164                                                 XREF[3]:     0042112f(j), 00421139(j),
//                                                                                                         00421155(j)
//                              basegame.cpp:4137 (42)
//         00421164     LEA        EAX=>ctrl_key,[ESP + 0x8]
//         00421168     LEA        this=>right_btn,[ESP + 0xc]
//         0042116c     PUSH       EAX
//         0042116d     LEA        EDX=>left_btn,[ESP + 0x14]
//         00421171     PUSH       this
//         00421172     LEA        EAX=>point,[ESP + 0x1c]
//         00421176     PUSH       EDX
//         00421177     MOV        EDX,dword ptr [ESP + param_4]
//         0042117b     LEA        this=>point.y,[ESP + 0x24]
//         0042117f     PUSH       EAX
//         00421180     MOV        EAX,dword ptr [ESP + param_3]
//         00421184     PUSH       this
//         00421185     PUSH       EDX
//         00421186     PUSH       EAX
//         00421187     MOV        this,ESI
//         00421189     CALL       RGE_Base_Game::get_mouse_info                    void get_mouse_info(RGE_Base_Game * this, uin
//                              basegame.cpp:4138 (40)
//         0042118e     MOV        this,dword ptr [ESP + ctrl_key]
//         00421192     MOV        EDX,dword ptr [ESP + right_btn]
//         00421196     MOV        EAX,dword ptr [ESP + left_btn]
//         0042119a     MOV        EDI,dword ptr [ESI]
//         0042119c     PUSH       this
//         0042119d     MOV        this,dword ptr [ESP + point.x]
//         004211a1     PUSH       EDX
//         004211a2     MOV        EDX,dword ptr [ESP + local_4]
//         004211a6     PUSH       EAX
//         004211a7     MOV        EAX,dword ptr [ESP + point.y]
//         004211ab     PUSH       this
//         004211ac     PUSH       EDX
//         004211ad     PUSH       EAX
//         004211ae     MOV        this,ESI
//         004211b0     CALL       dword ptr [EDI + 0xfc]
//                              basegame.cpp:4140 (9)
//         004211b6     MOV        this,ESI
//         004211b8     CALL       dword ptr [EDI + 0xbc]
//         004211be     POP        EDI
//                              basegame.cpp:4142 (5)
//         004211bf     MOV        EAX,0x1
//                              basegame.cpp:4143 (7)
//         004211c4     POP        ESI
//         004211c5     ADD        ESP,0x18
//         004211c8     RET        0x10
//         004211cb     ??         90h
//         004211cc     NOP
//         004211cd     NOP
//         004211ce     NOP
//         004211cf     NOP
    return 0;
}

int RGE_Base_Game::handle_key_down(void* param_1, uint param_2, uint param_3, long param_4) {
    /* TODO: Stub */
//                              int __thiscall handle_key_down(RGE_Base_Game * this, void * param_1,
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              void *            Stack[0x4]:4   param_1                   XREF[1]:     0042122c(R)
//              uint              Stack[0x8]:4   param_2                   XREF[1]:     00421245(R)
//              uint              Stack[0xc]:4   param_3                   XREF[1]:     004211e9(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     004211e5(R)
//                               ?handle_key_down@RGE_Base_Game@@MAEHPAXIIJ@Z                 XREF[2]:     0056ef94(*), 0057726c(*)
//                               RGE_Base_Game::handle_key_down
//                              basegame.cpp:4154 (4)
//         004211d0     PUSH       ESI
//         004211d1     PUSH       EDI
//         004211d2     MOV        EDI,this
//                              basegame.cpp:4155 (7)
//         004211d4     MOV        EAX,dword ptr [EDI + 0x14]
//         004211d7     TEST       EAX,EAX
//         004211d9     JNZ        LAB_004211e5
//                              basegame.cpp:4156 (5)
//         004211db     MOV        EAX,0x1
//                              basegame.cpp:4219 (5)
//         004211e0     POP        EDI
//         004211e1     POP        ESI
//         004211e2     RET        0x10
//                               LAB_004211e5                                                 XREF[1]:     004211d9(j)
//                              basegame.cpp:4159 (8)
//         004211e5     MOV        this,dword ptr [ESP + param_4]
//         004211e9     MOV        EAX,dword ptr [ESP + param_3]
//                              basegame.cpp:4160 (29)
//         004211ed     MOV        ESI,dword ptr [->USER32.DLL::GetKeyState]        = 0048af44
//         004211f3     AND        this,0xffff
//         004211f9     PUSH       0x11
//         004211fb     MOV        [DAT_005b2368],EAX
//         00421200     MOV        dword ptr [DAT_005b2370],this
//         00421206     CALL       ESI=>USER32.DLL::GetKeyState
//         00421208     XOR        EDX,EDX
//                              basegame.cpp:4161 (18)
//         0042120a     PUSH       0x12
//         0042120c     TEST       AX,AX
//         0042120f     SETL       DL
//         00421212     MOV        dword ptr [DAT_0062c4bc],EDX
//         00421218     CALL       ESI=>USER32.DLL::GetKeyState
//         0042121a     XOR        this,this
//                              basegame.cpp:4162 (16)
//         0042121c     PUSH       0x10
//         0042121e     TEST       AX,AX
//         00421221     SETL       this
//         00421224     MOV        dword ptr [DAT_0062c4b4],this
//         0042122a     CALL       ESI=>USER32.DLL::GetKeyState
//                              basegame.cpp:4165 (80)
//         0042122c     MOV        this,dword ptr [ESP + param_1]
//         00421230     XOR        EDX,EDX
//         00421232     TEST       AX,AX
//         00421235     SETL       DL
//         00421238     MOV        dword ptr [DAT_005b2164],EDX
//         0042123e     MOV        EAX,dword ptr [EDI + 0x10]
//         00421241     CMP        this,EAX
//         00421243     JNZ        LAB_00421281
//         00421245     CMP        dword ptr [ESP + param_2],0x104
//         0042124d     JNZ        LAB_00421281
//         0042124f     MOV        this,dword ptr [DAT_005b2368]
//         00421255     CMP        this,0x12
//         00421258     JZ         LAB_00421264
//         0042125a     CMP        this,0x20
//         0042125d     JZ         LAB_00421264
//         0042125f     CMP        this,0x79
//         00421262     JNZ        LAB_00421287
//                               LAB_00421264                                                 XREF[2]:     00421258(j), 0042125d(j)
//         00421264     MOV        EDX,dword ptr [EDI + 0xc]
//         00421267     MOV        ESI,dword ptr [EDX + 0x894]
//         0042126d     TEST       ESI,ESI
//         0042126f     JZ         LAB_00421287
//         00421271     PUSH       EAX
//         00421272     CALL       dword ptr [->USER32.DLL::IsIconic]               = 0048ae70
//         00421278     TEST       EAX,EAX
//         0042127a     JNZ        LAB_00421281
//                              basegame.cpp:4219 (5)
//         0042127c     POP        EDI
//         0042127d     POP        ESI
//         0042127e     RET        0x10
//                               LAB_00421281                                                 XREF[3]:     00421243(j), 0042124d(j),
//                                                                                                         0042127a(j)
//                              basegame.cpp:4166 (6)
//         00421281     MOV        this,dword ptr [DAT_005b2368]
//                               LAB_00421287                                                 XREF[2]:     00421262(j), 0042126f(j)
//                              basegame.cpp:4201 (9)
//         00421287     MOV        EAX,[DAT_0062c4bc]
//         0042128c     TEST       EAX,EAX
//         0042128e     JZ         LAB_004212b1
//                              basegame.cpp:4203 (5)
//         00421290     CMP        this,0x7b
//         00421293     JNZ        LAB_004212b1
//                              basegame.cpp:4206 (21)
//         00421295     MOV        EAX,dword ptr [EDI + 0x48]
//         00421298     PUSH       snapshot_number                                  = 1h
//         0042129d     PUSH       s_.\AoE%04d.bmp                                  = ".\\AoE%04d.bmp"
//         004212a2     MOV        this,dword ptr [EAX + 0xc]
//         004212a5     CALL       TDrawArea::take_snapshot                         void take_snapshot(TDrawArea * this, char * p
//                              basegame.cpp:4207 (2)
//         004212aa     XOR        EAX,EAX
//                              basegame.cpp:4219 (5)
//         004212ac     POP        EDI
//         004212ad     POP        ESI
//         004212ae     RET        0x10
//                               LAB_004212b1                                                 XREF[2]:     0042128e(j), 00421293(j)
//                              basegame.cpp:4215 (36)
//         004212b1     MOV        ESI,dword ptr [DAT_005b2164]
//         004212b7     MOV        EDX,dword ptr [EDI]
//         004212b9     PUSH       ESI
//         004212ba     MOV        ESI,dword ptr [DAT_0062c4b4]
//         004212c0     PUSH       ESI
//         004212c1     PUSH       EAX
//         004212c2     MOV        EAX,[DAT_005b2370]
//         004212c7     PUSH       EAX
//         004212c8     PUSH       this
//         004212c9     MOV        this,EDI
//         004212cb     CALL       dword ptr [EDX + 0x100]
//         004212d1     NEG        EAX
//         004212d3     SBB        EAX,EAX
//                              basegame.cpp:4219 (7)
//         004212d5     POP        EDI
//         004212d6     NEG        EAX
//         004212d8     POP        ESI
//         004212d9     RET        0x10
//         004212dc     ??         90h
//         004212dd     NOP
//         004212de     NOP
//         004212df     NOP
    return 0;
}

int RGE_Base_Game::handle_user_command(void* param_1, uint param_2, uint param_3, long param_4) {
    /* TODO: Stub */
//                              int __thiscall handle_user_command(RGE_Base_Game * this, void * para
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              void *            Stack[0x4]:4   param_1
//              uint              Stack[0x8]:4   param_2
//              uint              Stack[0xc]:4   param_3                   XREF[1]:     004212f4(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     004212f0(R)
//                               ?handle_user_command@RGE_Base_Game@@MAEHPAXIIJ@Z             XREF[2]:     0056ef98(*), 00577270(*)
//                               RGE_Base_Game::handle_user_command
//                              basegame.cpp:4225 (5)
//         004212e0     PUSH       EBX
//         004212e1     PUSH       ESI
//         004212e2     MOV        ESI,this
//         004212e4     PUSH       EDI
//                              basegame.cpp:4227 (32)
//         004212e5     MOV        this,dword ptr [ESI + 0x18c]
//         004212eb     CALL       TCommunications_Handler::MultiplayerGameStart    int MultiplayerGameStart(TCommunications_Hand
//         004212f0     MOV        EDI,dword ptr [ESP + param_4]
//         004212f4     MOV        EBX,dword ptr [ESP + param_3]
//         004212f8     TEST       EAX,EAX
//         004212fa     JZ         LAB_00421350
//         004212fc     MOV        EAX,[out_of_sync]
//         00421301     TEST       EAX,EAX
//         00421303     JNZ        LAB_00421350
//                              basegame.cpp:4229 (8)
//         00421305     CMP        EBX,0x17b3
//         0042130b     JNZ        LAB_00421327
//                              basegame.cpp:4232 (24)
//         0042130d     PUSH       EDI
//         0042130e     MOV        this,ESI
//         00421310     CALL       RGE_Base_Game::playerID                          int playerID(RGE_Base_Game * this, int param_1)
//         00421315     MOV        this,dword ptr [ESI + 0x3f4]
//         0042131b     PUSH       0x1
//         0042131d     MOV        EDX,dword ptr [ECX + this->error_code]
//         00421320     MOV        EAX,dword ptr [EDX + EAX*0x4]
//         00421323     MOV        EDX,dword ptr [EAX]
//                              basegame.cpp:4234 (10)
//         00421325     JMP        LAB_00421347
//                               LAB_00421327                                                 XREF[1]:     0042130b(j)
//         00421327     CMP        EBX,0x17b4
//         0042132d     JNZ        LAB_00421350
//                              basegame.cpp:4237 (33)
//         0042132f     PUSH       EDI
//         00421330     MOV        this,ESI
//         00421332     CALL       RGE_Base_Game::playerID                          int playerID(RGE_Base_Game * this, int param_1)
//         00421337     MOV        this,dword ptr [ESI + 0x3f4]
//         0042133d     PUSH       0x0
//         0042133f     MOV        EDX,dword ptr [ECX + this->error_code]
//         00421342     MOV        EAX,dword ptr [EDX + EAX*0x4]
//         00421345     MOV        EDX,dword ptr [EAX]
//                               LAB_00421347                                                 XREF[1]:     00421325(j)
//         00421347     PUSH       EDI
//         00421348     MOV        this,EAX
//         0042134a     CALL       dword ptr [EDX + 0xd4]
//                               LAB_00421350                                                 XREF[3]:     004212fa(j), 00421303(j),
//                                                                                                         0042132d(j)
//                              basegame.cpp:4241 (12)
//         00421350     MOV        EAX,EBX
//         00421352     SUB        EAX,0x17a2
//         00421357     JZ         LAB_00421372
//         00421359     DEC        EAX
//         0042135a     JNZ        LAB_00421386
//                              basegame.cpp:4259 (10)
//         0042135c     MOV        this,dword ptr [ESI + 0x3f4]
//         00421362     TEST       this,this
//         00421364     JZ         LAB_00421386
//                              basegame.cpp:4260 (10)
//         00421366     MOV        EAX,dword ptr [this->_padding_]
//         00421368     PUSH       0x0
//         0042136a     CALL       dword ptr [EAX + 0xec]
//                              basegame.cpp:4262 (2)
//         00421370     JMP        LAB_00421386
//                               LAB_00421372                                                 XREF[1]:     00421357(j)
//                              basegame.cpp:4253 (10)
//         00421372     MOV        this,dword ptr [ESI + 0x3f4]
//         00421378     TEST       this,this
//         0042137a     JZ         LAB_00421386
//                              basegame.cpp:4254 (10)
//         0042137c     MOV        EDX,dword ptr [this->_padding_]
//         0042137e     PUSH       0x1
//         00421380     CALL       dword ptr [EDX + 0xec]
//                               LAB_00421386                                                 XREF[4]:     0042135a(j), 00421364(j),
//                                                                                                         00421370(j), 0042137a(j)
//                              basegame.cpp:4287 (16)
//         00421386     MOV        EAX,dword ptr [ESI]
//         00421388     PUSH       EDI
//         00421389     PUSH       EBX=>DAT_fffffff8
//         0042138a     MOV        this,ESI
//         0042138c     CALL       dword ptr [EAX + 0x104]
//         00421392     NEG        EAX
//         00421394     SBB        EAX,EAX
//                              basegame.cpp:4291 (8)
//         00421396     POP        EDI
//         00421397     POP        ESI
//         00421398     POP        EBX
//         00421399     NEG        EAX
//         0042139b     RET        0x10
//         0042139e     ??         90h
//         0042139f     NOP
    return 0;
}

int RGE_Base_Game::handle_command(void* param_1, uint param_2, uint param_3, long param_4) {
    /* TODO: Stub */
//                              int __thiscall handle_command(RGE_Base_Game * this, void * param_1,
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              void *            Stack[0x4]:4   param_1
//              uint              Stack[0x8]:4   param_2
//              uint              Stack[0xc]:4   param_3                   XREF[1]:     004213a7(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     004213a0(R)
//                               ?handle_command@RGE_Base_Game@@MAEHPAXIIJ@Z                  XREF[2]:     0056ef9c(*), 00577274(*)
//                               RGE_Base_Game::handle_command
//                              basegame.cpp:4297 (24)
//         004213a0     MOV        EDX,dword ptr [ESP + param_4]
//         004213a4     MOV        EAX,dword ptr [this->_padding_]
//         004213a6     PUSH       EDX
//         004213a7     MOV        EDX,dword ptr [ESP + param_3]
//         004213ab     PUSH       EDX
//         004213ac     CALL       dword ptr [EAX + 0x108]
//         004213b2     NEG        EAX
//         004213b4     SBB        EAX,EAX
//         004213b6     NEG        EAX
//                              basegame.cpp:4302 (3)
//         004213b8     RET        0x10
//         004213bb     ??         90h
//         004213bc     NOP
//         004213bd     NOP
//         004213be     NOP
//         004213bf     NOP
    return 0;
}

int RGE_Base_Game::handle_music_done(void* param_1, uint param_2, uint param_3, long param_4) {
    /* TODO: Stub */
//                              int __thiscall handle_music_done(RGE_Base_Game * this, void * param_
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              void *            Stack[0x4]:4   param_1
//              uint              Stack[0x8]:4   param_2
//              uint              Stack[0xc]:4   param_3
//              long              Stack[0x10]:4  param_4
//                               ?handle_music_done@RGE_Base_Game@@MAEHPAXIIJ@Z               XREF[2]:     0056efa0(*), 00577278(*)
//                               RGE_Base_Game::handle_music_done
//                              basegame.cpp:4308 (14)
//         004213c0     MOV        EAX,dword ptr [this->_padding_]
//         004213c2     CALL       dword ptr [EAX + 0x10c]
//         004213c8     NEG        EAX
//         004213ca     SBB        EAX,EAX
//         004213cc     NEG        EAX
//                              basegame.cpp:4313 (3)
//         004213ce     RET        0x10
//         004213d1     ??         90h
//         004213d2     NOP
//         004213d3     NOP
//         004213d4     NOP
//         004213d5     NOP
//         004213d6     NOP
//         004213d7     NOP
//         004213d8     NOP
//         004213d9     NOP
//         004213da     NOP
//         004213db     NOP
//         004213dc     NOP
//         004213dd     NOP
//         004213de     NOP
//         004213df     NOP
    return 0;
}

int RGE_Base_Game::handle_paint(void* param_1, uint param_2, uint param_3, long param_4) {
    /* TODO: Stub */
//                              int __thiscall handle_paint(RGE_Base_Game * this, void * param_1, ui
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              void *            Stack[0x4]:4   param_1
//              uint              Stack[0x8]:4   param_2
//              uint              Stack[0xc]:4   param_3
//              long              Stack[0x10]:4  param_4
//                               ?handle_paint@RGE_Base_Game@@MAEHPAXIIJ@Z                    XREF[2]:     0056efa4(*), 0057727c(*)
//                               RGE_Base_Game::handle_paint
//                              basegame.cpp:4319 (4)
//         004213e0     PUSH       EBX
//         004213e1     PUSH       EBP
//         004213e2     PUSH       ESI
//         004213e3     PUSH       EDI
//                              basegame.cpp:4327 (16)
//         004213e4     PUSH       0x4
//         004213e6     PUSH       0x32
//         004213e8     MOV        ESI,this
//         004213ea     PUSH       0x32
//         004213ec     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         004213f1     ADD        ESP,0xc
//                              language.dll match for 0x10ea: "Score"
//                              basegame.cpp:4330 (18)
//         004213f4     PUSH       0x10ea
//         004213f9     PUSH       s_C:\msdev\work\age1_x1\basegame.c               = "C:\\msdev\\work\\age1_x1\\basegame.cpp"
//         004213fe     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         00421403     ADD        ESP,0x8
//                              basegame.cpp:4332 (9)
//         00421406     MOV        this,ESI
//         00421408     MOV        EDI,EAX
//         0042140a     CALL       RGE_Base_Game::check_paint                       int check_paint(RGE_Base_Game * this)
//                              basegame.cpp:4334 (22)
//         0042140f     PUSH       0x10ee
//         00421414     PUSH       s_C:\msdev\work\age1_x1\basegame.c               = "C:\\msdev\\work\\age1_x1\\basegame.cpp"
//         00421419     MOV        EBP,EAX
//         0042141b     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         00421420     ADD        ESP,0x8
//         00421423     SUB        EAX,EDI
//                              basegame.cpp:4335 (10)
//         00421425     MOV        this,ESI
//         00421427     PUSH       EAX
//         00421428     PUSH       0x5
//         0042142a     CALL       RGE_Base_Game::add_to_timing                     void add_to_timing(RGE_Base_Game * this, int
//                              basegame.cpp:4337 (6)
//         0042142f     XOR        EBX,EBX
//         00421431     CMP        EBP,EBX
//         00421433     JNZ        LAB_0042144c
//                              basegame.cpp:4339 (14)
//         00421435     PUSH       0x4
//         00421437     PUSH       0x5f
//         00421439     PUSH       0x32
//         0042143b     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         00421440     ADD        ESP,0xc
//                              basegame.cpp:4340 (2)
//         00421443     XOR        EAX,EAX
//                              basegame.cpp:4531 (7)
//         00421445     POP        EDI
//         00421446     POP        ESI
//         00421447     POP        EBP
//         00421448     POP        EBX
//         00421449     RET        0x10
//                               LAB_0042144c                                                 XREF[1]:     00421433(j)
//                              basegame.cpp:4345 (46)
//         0042144c     MOV        EAX,dword ptr [ESI + 0x1b0]
//         00421452     CMP        EAX,0x4
//         00421455     JZ         LAB_00421461
//         00421457     CMP        EAX,0x6
//         0042145a     JZ         LAB_00421461
//         0042145c     CMP        EAX,0x7
//         0042145f     JNZ        LAB_004214dc
//                               LAB_00421461                                                 XREF[2]:     00421455(j), 0042145a(j)
//         00421461     MOV        EAX,dword ptr [ESI + 0x48]
//         00421464     CMP        byte ptr [EAX + 0x478],0x1
//         0042146b     JZ         LAB_004214dc
//         0042146d     CMP        dword ptr [ESI + 0x54],EBX
//         00421470     JZ         LAB_004214dc
//         00421472     CMP        dword ptr [ESI + 0x1c8],EBX
//         00421478     JZ         LAB_004214dc
//                              basegame.cpp:4347 (11)
//         0042147a     MOV        EAX,dword ptr [EAX + 0x1c]
//         0042147d     PUSH       0x1
//         0042147f     PUSH       EAX
//         00421480     MOV        this,dword ptr [EAX]
//         00421482     CALL       dword ptr [ECX + this->save_random_map_seed]
//                              basegame.cpp:4348 (25)
//         00421485     PUSH       0x10fc
//         0042148a     PUSH       s_C:\msdev\work\age1_x1\basegame.c               = "C:\\msdev\\work\\age1_x1\\basegame.cpp"
//         0042148f     MOV        EBP,EAX
//         00421491     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         00421496     MOV        EDI,EAX
//         00421498     ADD        ESP,0x8
//         0042149b     ADD        EDI,0x64
//                              basegame.cpp:4349 (8)
//         0042149e     CMP        EBP,0x8876021c
//         004214a4     JNZ        LAB_004214dc
//                               LAB_004214a6                                                 XREF[1]:     004214d2(j)
//                              basegame.cpp:4351 (14)
//         004214a6     MOV        EDX,dword ptr [ESI + 0x48]
//         004214a9     PUSH       0x1
//         004214ab     MOV        EAX,dword ptr [EDX + 0x1c]
//         004214ae     PUSH       EAX=>DAT_fffffff8
//         004214af     MOV        this,dword ptr [EAX]
//         004214b1     CALL       dword ptr [ECX + this->save_random_map_seed]
//                              basegame.cpp:4352 (24)
//         004214b4     PUSH       0x1100
//         004214b9     PUSH       s_C:\msdev\work\age1_x1\basegame.c               = "C:\\msdev\\work\\age1_x1\\basegame.cpp"
//         004214be     MOV        EBP,EAX
//         004214c0     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         004214c5     ADD        ESP,0x8
//         004214c8     CMP        EAX,EDI
//         004214ca     JA         LAB_004214d6
//                              basegame.cpp:4349 (10)
//         004214cc     CMP        EBP,0x8876021c
//         004214d2     JZ         LAB_004214a6
//         004214d4     JMP        LAB_004214dc
//                               LAB_004214d6                                                 XREF[1]:     004214ca(j)
//                              basegame.cpp:4354 (6)
//         004214d6     MOV        dword ptr [ESI + 0x1c8],EBX
//                               LAB_004214dc                                                 XREF[6]:     0042145f(j), 0042146b(j),
//                                                                                                         00421470(j), 00421478(j),
//                                                                                                         004214a4(j), 004214d4(j)
//                              basegame.cpp:4362 (17)
//         004214dc     PUSH       0x4
//         004214de     PUSH       offset DAT_fffffff8
//         004214e3     PUSH       offset DAT_fffffff4
//         004214e5     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         004214ea     ADD        ESP,0xc
//                              basegame.cpp:4364 (15)
//         004214ed     PUSH       0x110c
//         004214f2     PUSH       s_C:\msdev\work\age1_x1\basegame.c               = "C:\\msdev\\work\\age1_x1\\basegame.cpp"
//         004214f7     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//                              basegame.cpp:4365 (14)
//         004214fc     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         00421502     ADD        ESP,0x8
//         00421505     MOV        EBP,EAX
//         00421507     MOV        EDI,dword ptr [EDX + 0x60]
//                              basegame.cpp:4366 (4)
//         0042150a     CMP        EDI,EBX
//         0042150c     JZ         LAB_0042151c
//                              basegame.cpp:4369 (7)
//         0042150e     MOV        this,EDI
//         00421510     CALL       TSound_Driver::play_list                         void play_list(TSound_Driver * this)
//                              basegame.cpp:4371 (7)
//         00421515     MOV        this,EDI
//         00421517     CALL       TSound_Driver::reset_play_list                   void reset_play_list(TSound_Driver * this)
//                               LAB_0042151c                                                 XREF[1]:     0042150c(j)
//                              basegame.cpp:4373 (20)
//         0042151c     PUSH       0x1115
//         00421521     PUSH       s_C:\msdev\work\age1_x1\basegame.c               = "C:\\msdev\\work\\age1_x1\\basegame.cpp"
//         00421526     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         0042152b     ADD        ESP,0x8
//         0042152e     SUB        EAX,EBP
//                              basegame.cpp:4374 (10)
//         00421530     MOV        this,ESI
//         00421532     PUSH       EAX
//         00421533     PUSH       offset DAT_fffffff8
//         00421535     CALL       RGE_Base_Game::add_to_timing                     void add_to_timing(RGE_Base_Game * this, int
//                              basegame.cpp:4380 (17)
//         0042153a     PUSH       0x111c
//         0042153f     PUSH       s_C:\msdev\work\age1_x1\basegame.c               = "C:\\msdev\\work\\age1_x1\\basegame.cpp"
//         00421544     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         00421549     MOV        EBP,EAX
//                              basegame.cpp:4382 (13)
//         0042154b     MOV        EAX,dword ptr [ESI + 0x1c4]
//         00421551     ADD        ESP,0x8
//         00421554     CMP        EAX,EBX
//         00421556     JZ         LAB_00421586
//                              basegame.cpp:4384 (11)
//         00421558     PUSH       0x4
//         0042155a     PUSH       offset DAT_fffffff8
//         0042155c     PUSH       offset DAT_fffffff4
//         0042155e     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:4385 (18)
//         00421563     MOV        EAX,dword ptr [ESI + 0x3f8]
//         00421569     ADD        ESP,0xc
//         0042156c     CMP        EAX,EBX
//         0042156e     JNZ        LAB_00421580
//         00421570     CMP        dword ptr [ESI + 0x54],EBX
//         00421573     JZ         LAB_00421580
//                              basegame.cpp:4386 (11)
//         00421575     MOV        this,dword ptr [ESI + 0x1c0]
//         0042157b     CALL       TMousePointer::erase                             void erase(TMousePointer * this)
//                               LAB_00421580                                                 XREF[2]:     0042156e(j), 00421573(j)
//                              basegame.cpp:4387 (6)
//         00421580     MOV        dword ptr [ESI + 0x1c4],EBX
//                               LAB_00421586                                                 XREF[1]:     00421556(j)
//                              basegame.cpp:4391 (22)
//         00421586     PUSH       0x1127
//         0042158b     PUSH       s_C:\msdev\work\age1_x1\basegame.c               = "C:\\msdev\\work\\age1_x1\\basegame.cpp"
//         00421590     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         00421595     ADD        ESP,0x8
//         00421598     MOV        EDI,EAX
//         0042159a     SUB        EDI,EBP
//                              basegame.cpp:4394 (20)
//         0042159c     PUSH       0x112a
//         004215a1     PUSH       s_C:\msdev\work\age1_x1\basegame.c               = "C:\\msdev\\work\\age1_x1\\basegame.cpp"
//         004215a6     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         004215ab     ADD        ESP,0x8
//         004215ae     MOV        EBP,EAX
//                              basegame.cpp:4396 (14)
//         004215b0     PUSH       0x4
//         004215b2     PUSH       offset DAT_fffffff8
//         004215b4     PUSH       offset DAT_fffffff4
//         004215b6     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         004215bb     ADD        ESP,0xc
//                              basegame.cpp:4398 (14)
//         004215be     MOV        this,panel_system
//         004215c3     CALL       TPanelSystem::currentPanel                       TPanel * currentPanel(TPanelSystem * this)
//         004215c8     TEST       EAX,EAX
//         004215ca     JZ         LAB_00421618
//                              basegame.cpp:4400 (11)
//         004215cc     PUSH       0x1
//         004215ce     PUSH       offset DAT_fffffff8
//         004215d0     PUSH       offset DAT_fffffff4
//         004215d2     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:4401 (13)
//         004215d7     MOV        EAX,dword ptr [ESI + 0x3f8]
//         004215dd     ADD        ESP,0xc
//         004215e0     CMP        EAX,EBX
//         004215e2     JZ         LAB_004215f7
//                              basegame.cpp:4402 (19)
//         004215e4     MOV        this,panel_system
//         004215e9     CALL       TPanelSystem::currentPanel                       TPanel * currentPanel(TPanelSystem * this)
//         004215ee     MOV        EDX,dword ptr [EAX]
//         004215f0     PUSH       0x2
//         004215f2     MOV        this,EAX
//         004215f4     CALL       dword ptr [EDX + 0x20]
//                               LAB_004215f7                                                 XREF[1]:     004215e2(j)
//                              basegame.cpp:4403 (17)
//         004215f7     MOV        this,panel_system
//         004215fc     CALL       TPanelSystem::currentPanel                       TPanel * currentPanel(TPanelSystem * this)
//         00421601     MOV        EDX,dword ptr [EAX]
//         00421603     MOV        this,EAX
//         00421605     CALL       dword ptr [EDX + 0x54]
//                              basegame.cpp:4404 (14)
//         00421608     PUSH       0x1
//         0042160a     PUSH       offset DAT_fffffff8
//         0042160c     PUSH       offset DAT_fffffff4
//         0042160e     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         00421613     ADD        ESP,0xc
//                              basegame.cpp:4407 (2)
//         00421616     JMP        LAB_0042161f
//                               LAB_00421618                                                 XREF[1]:     004215ca(j)
//                              basegame.cpp:4408 (7)
//         00421618     MOV        this,ESI
//         0042161a     CALL       RGE_Base_Game::clear_window                      void clear_window(RGE_Base_Game * this)
//                               LAB_0042161f                                                 XREF[1]:     00421616(j)
//                              basegame.cpp:4410 (11)
//         0042161f     PUSH       0x4
//         00421621     PUSH       offset DAT_fffffff8
//         00421623     PUSH       offset DAT_fffffff4
//         00421625     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:4413 (12)
//         0042162a     MOV        EAX,[DAT_0062c57c]
//         0042162f     ADD        ESP,0xc
//         00421632     CMP        EAX,EBX
//         00421634     JZ         LAB_0042165e
//                              basegame.cpp:4415 (6)
//         00421636     MOV        dword ptr [DAT_0062c57c],EBX
//                              basegame.cpp:4416 (16)
//         0042163c     MOV        EAX,dword ptr [ESI + 0x1b0]
//         00421642     CMP        EAX,0x4
//         00421645     JZ         LAB_0042164c
//         00421647     CMP        EAX,0x5
//         0042164a     JNZ        LAB_0042165e
//                               LAB_0042164c                                                 XREF[1]:     00421645(j)
//                              basegame.cpp:4418 (8)
//         0042164c     CMP        dword ptr [ESI + 0x8e8],EBX
//         00421652     JZ         LAB_0042165e
//                              basegame.cpp:4419 (10)
//         00421654     MOV        EAX,dword ptr [ESI]
//         00421656     MOV        this,ESI
//         00421658     CALL       dword ptr [EAX + 0x130]
//                              language.dll match for 0x1147: "Nebuchad"
//                              language.dll match for 0x1147: "Hammurabi II"
//                               LAB_0042165e                                                 XREF[3]:     00421634(j), 0042164a(j),
//                                                                                                         00421652(j)
//                              basegame.cpp:4423 (20)
//         0042165e     PUSH       0x1147
//         00421663     PUSH       s_C:\msdev\work\age1_x1\basegame.c               = "C:\\msdev\\work\\age1_x1\\basegame.cpp"
//         00421668     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         0042166d     ADD        ESP,0x8
//         00421670     SUB        EAX,EBP
//                              basegame.cpp:4424 (10)
//         00421672     MOV        this,ESI
//         00421674     PUSH       EAX
//         00421675     PUSH       offset DAT_fffffff8
//         00421677     CALL       RGE_Base_Game::add_to_timing                     void add_to_timing(RGE_Base_Game * this, int
//                              language.dll match for 0x114b: "Croesus"
//                              language.dll match for 0x114b: "Hammurabi IV"
//                              basegame.cpp:4427 (20)
//         0042167c     PUSH       0x114b
//         00421681     PUSH       s_C:\msdev\work\age1_x1\basegame.c               = "C:\\msdev\\work\\age1_x1\\basegame.cpp"
//         00421686     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         0042168b     ADD        ESP,0x8
//         0042168e     MOV        EBP,EAX
//                              basegame.cpp:4429 (11)
//         00421690     PUSH       0x4
//         00421692     PUSH       offset DAT_fffffff8
//         00421694     PUSH       offset DAT_fffffff4
//         00421696     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:4433 (18)
//         0042169b     MOV        EAX,dword ptr [ESI + 0x54]
//         0042169e     ADD        ESP,0xc
//         004216a1     CMP        EAX,EBX
//         004216a3     JZ         LAB_004216c4
//         004216a5     CMP        dword ptr [ESI + 0x1d0],EBX
//         004216ab     JNZ        LAB_004216c4
//                              basegame.cpp:4435 (13)
//         004216ad     MOV        this,dword ptr [ESI + 0x1c0]
//         004216b3     PUSH       0x1
//         004216b5     CALL       TMousePointer::draw                              void draw(TMousePointer * this, int param_1)
//                              basegame.cpp:4436 (10)
//         004216ba     MOV        dword ptr [ESI + 0x1c4],0x1
//                              language.dll match for 0x115b: "Sarpedon"
//                              language.dll match for 0x115b: "Minos II"
//                               LAB_004216c4                                                 XREF[2]:     004216a3(j), 004216ab(j)
//                              basegame.cpp:4443 (20)
//         004216c4     PUSH       0x115b
//         004216c9     PUSH       s_C:\msdev\work\age1_x1\basegame.c               = "C:\\msdev\\work\\age1_x1\\basegame.cpp"
//         004216ce     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         004216d3     SUB        EAX,EBP
//         004216d5     ADD        ESP,0x8
//                              basegame.cpp:4444 (2)
//         004216d8     ADD        EDI,EAX
//                              basegame.cpp:4445 (10)
//         004216da     MOV        this,ESI
//         004216dc     PUSH       EDI
//         004216dd     PUSH       offset DAT_fffffff8
//         004216df     CALL       RGE_Base_Game::add_to_timing                     void add_to_timing(RGE_Base_Game * this, int
//                              language.dll match for 0x1160: "Pasiphae"
//                              basegame.cpp:4448 (20)
//         004216e4     PUSH       0x1160
//         004216e9     PUSH       s_C:\msdev\work\age1_x1\basegame.c               = "C:\\msdev\\work\\age1_x1\\basegame.cpp"
//         004216ee     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         004216f3     ADD        ESP,0x8
//         004216f6     MOV        EDI,EAX
//                              basegame.cpp:4450 (11)
//         004216f8     PUSH       0x4
//         004216fa     PUSH       offset DAT_fffffff8
//         004216fc     PUSH       offset DAT_fffffff4
//         004216fe     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:4454 (12)
//         00421703     MOV        this,dword ptr [ESI + 0x48]
//         00421706     ADD        ESP,0xc
//         00421709     PUSH       EBX
//         0042170a     CALL       TDrawSystem::Paint                               void Paint(TDrawSystem * this, tagRECT * para
//                              basegame.cpp:4455 (13)
//         0042170f     MOV        this,dword ptr [ESI + 0x10]
//         00421712     MOV        EBP,dword ptr [->USER32.DLL::ValidateRect]       = 0048ae8c
//         00421718     PUSH       EBX
//         00421719     PUSH       this=>DAT_fffffff8
//         0042171a     CALL       EBP=>USER32.DLL::ValidateRect
//                              basegame.cpp:4467 (7)
//         0042171c     MOV        EDX,dword ptr [ESI + 0x10]
//         0042171f     PUSH       EBX
//         00421720     PUSH       EDX=>DAT_fffffff8
//         00421721     CALL       EBP=>USER32.DLL::ValidateRect
//                              language.dll match for 0x1176: "9"
//                              language.dll match for 0x1176: "7"
//                              basegame.cpp:4470 (26)
//         00421723     PUSH       0x1176
//         00421728     PUSH       s_C:\msdev\work\age1_x1\basegame.c               = "C:\\msdev\\work\\age1_x1\\basegame.cpp"
//         0042172d     MOV        dword ptr [ESI + 0x3f8],EBX
//         00421733     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         00421738     ADD        ESP,0x8
//         0042173b     SUB        EAX,EDI
//                              basegame.cpp:4471 (10)
//         0042173d     MOV        this,ESI
//         0042173f     PUSH       EAX
//         00421740     PUSH       offset DAT_fffffff8
//         00421742     CALL       RGE_Base_Game::add_to_timing                     void add_to_timing(RGE_Base_Game * this, int
//                              basegame.cpp:4476 (11)
//         00421747     PUSH       0x4
//         00421749     PUSH       offset DAT_fffffff8
//         0042174b     PUSH       offset DAT_fffffff4
//         0042174d     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              basegame.cpp:4479 (10)
//         00421752     MOV        this,dword ptr [ESI + 0x504]
//         00421758     ADD        ESP,0xc
//         0042175b     INC        this
//                              language.dll match for 0x1182: "Darius"
//                              basegame.cpp:4482 (21)
//         0042175c     PUSH       0x1182
//         00421761     PUSH       s_C:\msdev\work\age1_x1\basegame.c               = "C:\\msdev\\work\\age1_x1\\basegame.cpp"
//         00421766     MOV        dword ptr [ESI + 0x504],this
//         0042176c     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//                              basegame.cpp:4483 (20)
//         00421771     MOV        EDX,dword ptr [DAT_0062c578]
//         00421777     MOV        EDI,EAX
//         00421779     SUB        EAX,EDX
//         0042177b     ADD        ESP,0x8
//         0042177e     CMP        EAX,0x3e8
//         00421783     JC         LAB_0042179f
//                              basegame.cpp:4485 (10)
//         00421785     MOV        EDX,dword ptr [ESI]
//         00421787     MOV        this,ESI
//         00421789     CALL       dword ptr [EDX + 0x128]
//                              basegame.cpp:4486 (6)
//         0042178f     MOV        dword ptr [DAT_0062c578],EDI
//                              basegame.cpp:4487 (10)
//         00421795     MOV        dword ptr [DAT_0062c57c],0x1
//                               LAB_0042179f                                                 XREF[1]:     00421783(j)
//                              basegame.cpp:4494 (8)
//         0042179f     CMP        dword ptr [restore_mouse_after_paint],EBX
//         004217a5     JZ         LAB_0042181c
//                              basegame.cpp:4496 (10)
//         004217a7     MOV        this,dword ptr [ESI + 0x1c0]
//         004217ad     CMP        this,EBX
//         004217af     JZ         LAB_00421816
//                              basegame.cpp:4498 (9)
//         004217b1     MOV        EAX,dword ptr [ESI + 0x4c]
//         004217b4     PUSH       EAX
//         004217b5     CALL       TMousePointer::Restore_Mouse                     int Restore_Mouse(TMousePointer * this, TDraw
//                              basegame.cpp:4499 (8)
//         004217ba     CMP        dword ptr [ESI + 0x1cc],EBX
//         004217c0     JZ         LAB_00421809
//                              basegame.cpp:4501 (13)
//         004217c2     CMP        dword ptr [ESI + 0x54],EBX
//         004217c5     JZ         LAB_004217e9
//         004217c7     CMP        dword ptr [ESI + 0x1d0],EBX
//         004217cd     JNZ        LAB_004217e9
//                              basegame.cpp:4503 (11)
//         004217cf     MOV        this,dword ptr [ESI + 0x1c0]
//         004217d5     CALL       TMousePointer::on                                void on(TMousePointer * this)
//                              basegame.cpp:4510 (13)
//         004217da     MOV        this,dword ptr [ESI + 0x1c0]
//         004217e0     PUSH       0x1
//         004217e2     CALL       TMousePointer::draw                              void draw(TMousePointer * this, int param_1)
//                              basegame.cpp:4519 (2)
//         004217e7     JMP        LAB_00421809
//                               LAB_004217e9                                                 XREF[2]:     004217c5(j), 004217cd(j)
//                              basegame.cpp:4521 (13)
//         004217e9     MOV        this,dword ptr [ESI + 0x1d4]
//         004217ef     PUSH       this
//         004217f0     CALL       dword ptr [->USER32.DLL::SetCursor]              = 0048aeda
//                              basegame.cpp:4522 (19)
//         004217f6     MOV        EDX,dword ptr [ESI + 0x1d4]
//         004217fc     MOV        EAX,dword ptr [ESI + 0x10]
//         004217ff     PUSH       EDX
//         00421800     PUSH       offset DAT_fffffff8
//         00421802     PUSH       EAX=>DAT_fffffff4
//         00421803     CALL       dword ptr [->USER32.DLL::SetClassLongA]          = 0048aeca
//                               LAB_00421809                                                 XREF[2]:     004217c0(j), 004217e7(j)
//                              basegame.cpp:4525 (13)
//         00421809     MOV        this,dword ptr [ESP + 0x14]
//         0042180d     PUSH       EBX
//         0042180e     PUSH       EBX=>DAT_fffffff8
//         0042180f     PUSH       this=>DAT_fffffff4
//         00421810     CALL       dword ptr [->USER32.DLL::InvalidateRect]         = 0048af16
//                               LAB_00421816                                                 XREF[1]:     004217af(j)
//                              basegame.cpp:4527 (6)
//         00421816     MOV        dword ptr [restore_mouse_after_paint],EBX
//                               LAB_0042181c                                                 XREF[1]:     004217a5(j)
//                              basegame.cpp:4531 (12)
//         0042181c     POP        EDI
//         0042181d     POP        ESI
//         0042181e     POP        EBP
//         0042181f     MOV        EAX,0x1
//         00421824     POP        EBX
//         00421825     RET        0x10
//         00421828     ??         90h
//         00421829     NOP
//         0042182a     NOP
//         0042182b     NOP
//         0042182c     NOP
//         0042182d     NOP
//         0042182e     NOP
//         0042182f     NOP
    return 0;
}

int RGE_Base_Game::handle_activate(void* param_1, uint param_2, uint param_3, long param_4) {
    /* TODO: Stub */
//                              int __thiscall handle_activate(RGE_Base_Game * this, void * param_1,
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              void *            Stack[0x4]:4   param_1
//              uint              Stack[0x8]:4   param_2
//              uint              Stack[0xc]:4   param_3                   XREF[1]:     00421830(R)
//              long              Stack[0x10]:4  param_4
//                               ?handle_activate@RGE_Base_Game@@MAEHPAXIIJ@Z                 XREF[2]:     handle_activate:005299fa(c),
//                               RGE_Base_Game::handle_activate                                            0056efa8(*)
//                              basegame.cpp:4537 (11)
//         00421830     MOV        EAX,dword ptr [ESP + param_3]
//         00421834     PUSH       ESI
//         00421835     TEST       EAX,EAX
//         00421837     MOV        ESI,this
//         00421839     JZ         LAB_00421844
//                              basegame.cpp:4551 (7)
//         0042183b     MOV        dword ptr [ESI + 0x18],0x1
//                              basegame.cpp:4552 (2)
//         00421842     JMP        LAB_0042184b
//                               LAB_00421844                                                 XREF[1]:     00421839(j)
//                              basegame.cpp:4553 (7)
//         00421844     MOV        dword ptr [ESI + 0x18],0x0
//                               LAB_0042184b                                                 XREF[1]:     00421842(j)
//                              basegame.cpp:4555 (5)
//         0042184b     MOV        EAX,dword ptr [ESI + 0x18]
//         0042184e     TEST       EAX,EAX
//                              basegame.cpp:4568 (32)
//         00421850     MOV        EAX,dword ptr [ESI + 0x1b0]
//         00421856     JZ         LAB_004218ba
//         00421858     CMP        EAX,0x4
//         0042185b     JZ         LAB_00421867
//         0042185d     CMP        EAX,0x6
//         00421860     JZ         LAB_00421867
//         00421862     CMP        EAX,0x7
//         00421865     JNZ        LAB_00421885
//                               LAB_00421867                                                 XREF[2]:     0042185b(j), 00421860(j)
//         00421867     CMP        dword ptr [ESI + 0x9fc],0x1
//         0042186e     JNZ        LAB_00421885
//                              basegame.cpp:4571 (21)
//         00421870     PUSH       0x0
//         00421872     PUSH       0x0
//         00421874     MOV        this,ESI
//         00421876     MOV        dword ptr [ESI + 0x9fc],0x0
//         00421880     CALL       RGE_Base_Game::set_paused                        void set_paused(RGE_Base_Game * this, int par
//                               LAB_00421885                                                 XREF[2]:     00421865(j), 0042186e(j)
//                              basegame.cpp:4574 (14)
//         00421885     MOV        this,panel_system
//         0042188a     CALL       TPanelSystem::currentPanel                       TPanel * currentPanel(TPanelSystem * this)
//         0042188f     TEST       EAX,EAX
//         00421891     JZ         LAB_004218a7
//                              basegame.cpp:4575 (20)
//         00421893     MOV        this,panel_system
//         00421898     CALL       TPanelSystem::currentPanel                       TPanel * currentPanel(TPanelSystem * this)
//         0042189d     MOV        EDX,dword ptr [EAX]
//         0042189f     MOV        this,EAX
//         004218a1     CALL       dword ptr [EDX + 0xdc]
//                               LAB_004218a7                                                 XREF[1]:     00421891(j)
//                              basegame.cpp:4577 (10)
//         004218a7     MOV        EAX,dword ptr [ESI]
//         004218a9     MOV        this,ESI
//         004218ab     CALL       dword ptr [EAX + 0x110]
//                              basegame.cpp:4597 (5)
//         004218b1     MOV        EAX,0x1
//                              basegame.cpp:4598 (4)
//         004218b6     POP        ESI
//         004218b7     RET        0x10
//                               LAB_004218ba                                                 XREF[1]:     00421856(j)
//                              basegame.cpp:4588 (38)
//         004218ba     CMP        EAX,0x4
//         004218bd     JZ         LAB_004218c9
//         004218bf     CMP        EAX,0x6
//         004218c2     JZ         LAB_004218c9
//         004218c4     CMP        EAX,0x7
//         004218c7     JNZ        LAB_004218f4
//                               LAB_004218c9                                                 XREF[2]:     004218bd(j), 004218c2(j)
//         004218c9     MOV        this,ESI
//         004218cb     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
//         004218d0     CMP        EAX,0x1
//         004218d3     JNZ        LAB_004218f4
//         004218d5     MOV        this,ESI
//         004218d7     CALL       RGE_Base_Game::get_paused                        int get_paused(RGE_Base_Game * this)
//         004218dc     TEST       EAX,EAX
//         004218de     JNZ        LAB_004218f4
//                              basegame.cpp:4591 (20)
//         004218e0     PUSH       EAX
//         004218e1     PUSH       0x1
//         004218e3     MOV        this,ESI
//         004218e5     MOV        dword ptr [ESI + 0x9fc],0x1
//         004218ef     CALL       RGE_Base_Game::set_paused                        void set_paused(RGE_Base_Game * this, int par
//                               LAB_004218f4                                                 XREF[3]:     004218c7(j), 004218d3(j),
//                                                                                                         004218de(j)
//                              basegame.cpp:4594 (10)
//         004218f4     MOV        EDX,dword ptr [ESI]
//         004218f6     MOV        this,ESI
//         004218f8     CALL       dword ptr [EDX + 0x114]
//                              basegame.cpp:4597 (5)
//         004218fe     MOV        EAX,0x1
//                              basegame.cpp:4598 (4)
//         00421903     POP        ESI
//         00421904     RET        0x10
//         00421907     ??         90h
//         00421908     NOP
//         00421909     NOP
//         0042190a     NOP
//         0042190b     NOP
//         0042190c     NOP
//         0042190d     NOP
//         0042190e     NOP
//         0042190f     NOP
    return 0;
}

int RGE_Base_Game::handle_init_menu(void* param_1, uint param_2, uint param_3, long param_4) {
    /* TODO: Stub */
//                              int __thiscall handle_init_menu(RGE_Base_Game * this, void * param_1
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              void *            Stack[0x4]:4   param_1
//              uint              Stack[0x8]:4   param_2
//              uint              Stack[0xc]:4   param_3
//              long              Stack[0x10]:4  param_4
//                               ?handle_init_menu@RGE_Base_Game@@MAEHPAXIIJ@Z                XREF[2]:     0056efac(*), 00577284(*)
//                               RGE_Base_Game::handle_init_menu
//                              basegame.cpp:4604 (14)
//         00421910     MOV        EAX,dword ptr [this->_padding_]
//         00421912     CALL       dword ptr [EAX + 0x118]
//         00421918     NEG        EAX
//         0042191a     SBB        EAX,EAX
//         0042191c     NEG        EAX
//                              basegame.cpp:4609 (3)
//         0042191e     RET        0x10
//         00421921     ??         90h
//         00421922     NOP
//         00421923     NOP
//         00421924     NOP
//         00421925     NOP
//         00421926     NOP
//         00421927     NOP
//         00421928     NOP
//         00421929     NOP
//         0042192a     NOP
//         0042192b     NOP
//         0042192c     NOP
//         0042192d     NOP
//         0042192e     NOP
//         0042192f     NOP
    return 0;
}

int RGE_Base_Game::handle_exit_menu(void* param_1, uint param_2, uint param_3, long param_4) {
    /* TODO: Stub */
//                              int __thiscall handle_exit_menu(RGE_Base_Game * this, void * param_1
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              void *            Stack[0x4]:4   param_1
//              uint              Stack[0x8]:4   param_2
//              uint              Stack[0xc]:4   param_3
//              long              Stack[0x10]:4  param_4
//                               ?handle_exit_menu@RGE_Base_Game@@MAEHPAXIIJ@Z                XREF[2]:     0056efb0(*), 00577288(*)
//                               RGE_Base_Game::handle_exit_menu
//                              basegame.cpp:4615 (14)
//         00421930     MOV        EAX,dword ptr [this->_padding_]
//         00421932     CALL       dword ptr [EAX + 0x11c]
//         00421938     NEG        EAX
//         0042193a     SBB        EAX,EAX
//         0042193c     NEG        EAX
//                              basegame.cpp:4620 (3)
//         0042193e     RET        0x10
//         00421941     ??         90h
//         00421942     NOP
//         00421943     NOP
//         00421944     NOP
//         00421945     NOP
//         00421946     NOP
//         00421947     NOP
//         00421948     NOP
//         00421949     NOP
//         0042194a     NOP
//         0042194b     NOP
//         0042194c     NOP
//         0042194d     NOP
//         0042194e     NOP
//         0042194f     NOP
    return 0;
}

int RGE_Base_Game::handle_size(void* param_1, uint param_2, uint param_3, long param_4) {
    /* TODO: Stub */
//                              int __thiscall handle_size(RGE_Base_Game * this, void * param_1, uin
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              void *            Stack[0x4]:4   param_1                   XREF[1]:     0042196d(R)
//              uint              Stack[0x8]:4   param_2                   XREF[1]:     00421972(R)
//              uint              Stack[0xc]:4   param_3                   XREF[1]:     00421950(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     00421968(R)
//                               ?handle_size@RGE_Base_Game@@MAEHPAXIIJ@Z                     XREF[2]:     0056efb4(*), 0057728c(*)
//                               RGE_Base_Game::handle_size
//                              basegame.cpp:4626 (12)
//         00421950     MOV        EAX,dword ptr [ESP + param_3]
//         00421954     PUSH       ESI
//         00421955     CMP        EAX,0x1
//         00421958     MOV        ESI,this
//         0042195a     JNZ        LAB_00421960
//                              basegame.cpp:4649 (4)
//         0042195c     POP        ESI
//         0042195d     RET        0x10
//                               LAB_00421960                                                 XREF[1]:     0042195a(j)
//                              basegame.cpp:4631 (8)
//         00421960     MOV        this,dword ptr [ESI + 0x48]
//         00421963     PUSH       EDI
//         00421964     TEST       this,this
//         00421966     JZ         LAB_004219d3
//                              basegame.cpp:4633 (21)
//         00421968     MOV        EDX,dword ptr [ESP + param_4]
//         0042196c     PUSH       EDX
//         0042196d     MOV        EDX,dword ptr [ESP + param_1]
//         00421971     PUSH       EAX
//         00421972     MOV        EAX,dword ptr [ESP + param_2]
//         00421976     PUSH       EAX
//         00421977     PUSH       EDX
//         00421978     CALL       TDrawSystem::HandleSize                          void HandleSize(TDrawSystem * this, void * pa
//                              basegame.cpp:4635 (14)
//         0042197d     MOV        EAX,dword ptr [ESI + 0x48]
//         00421980     TEST       EAX,EAX
//         00421982     JZ         LAB_004219a3
//         00421984     MOV        EAX,dword ptr [EAX + 0x2c]
//         00421987     TEST       EAX,EAX
//         00421989     JZ         LAB_004219a3
//                              basegame.cpp:4637 (9)
//         0042198b     MOV        this,dword ptr [ESI + 0xc]
//         0042198e     MOV        dword ptr [ECX + this+0x8e0],EAX
//                              basegame.cpp:4638 (15)
//         00421994     MOV        EDX,dword ptr [ESI + 0x48]
//         00421997     MOV        EAX,dword ptr [ESI + 0xc]
//         0042199a     MOV        this,dword ptr [EDX + 0x30]
//         0042199d     MOV        dword ptr [EAX + 0x8e4],this
//                               LAB_004219a3                                                 XREF[2]:     00421982(j), 00421989(j)
//                              basegame.cpp:4642 (14)
//         004219a3     MOV        this,panel_system
//         004219a8     CALL       TPanelSystem::currentPanel                       TPanel * currentPanel(TPanelSystem * this)
//         004219ad     TEST       EAX,EAX
//         004219af     JZ         LAB_004219d3
//                              basegame.cpp:4643 (34)
//         004219b1     MOV        this,panel_system
//         004219b6     CALL       TPanelSystem::currentPanel                       TPanel * currentPanel(TPanelSystem * this)
//         004219bb     MOV        this,dword ptr [ESI + 0xc]
//         004219be     MOV        EDX,dword ptr [EAX]
//         004219c0     MOV        EDI,dword ptr [ECX + this+0x8e4]
//         004219c6     MOV        this,dword ptr [ECX + this+0x8e0]
//         004219cc     PUSH       EDI
//         004219cd     PUSH       this
//         004219ce     MOV        this,EAX
//         004219d0     CALL       dword ptr [EDX + 0x50]
//                               LAB_004219d3                                                 XREF[2]:     00421966(j), 004219af(j)
//                              basegame.cpp:4646 (11)
//         004219d3     MOV        EDX,dword ptr [ESI]
//         004219d5     MOV        this,ESI
//         004219d7     CALL       dword ptr [EDX + 0x120]
//         004219dd     POP        EDI
//                              basegame.cpp:4648 (5)
//         004219de     MOV        EAX,0x1
//                              basegame.cpp:4649 (4)
//         004219e3     POP        ESI
//         004219e4     RET        0x10
//         004219e7     ??         90h
//         004219e8     NOP
//         004219e9     NOP
//         004219ea     NOP
//         004219eb     NOP
//         004219ec     NOP
//         004219ed     NOP
//         004219ee     NOP
//         004219ef     NOP
    return 0;
}

int RGE_Base_Game::handle_palette_changed(void* param_1, uint param_2, uint param_3, long param_4) {
    /* TODO: Stub */
//                              int __thiscall handle_palette_changed(RGE_Base_Game * this, void * p
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              void *            Stack[0x4]:4   param_1                   XREF[1]:     004219f6(R)
//              uint              Stack[0x8]:4   param_2                   XREF[2]:     00421a09(R), 00421a58(R)
//              uint              Stack[0xc]:4   param_3                   XREF[1]:     004219fe(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     004219f2(R)
//                               ?handle_palette_changed@RGE_Base_Game@@MAEHPAXIIJ@Z          XREF[2]:     0056efb8(*), 00577290(*)
//                               RGE_Base_Game::handle_palette_changed
//                              basegame.cpp:4655 (2)
//         004219f0     PUSH       EBX
//         004219f1     PUSH       EBP
//                              basegame.cpp:4660 (23)
//         004219f2     MOV        EBX,dword ptr [ESP + param_4]
//         004219f6     MOV        EBP,dword ptr [ESP + param_1]
//         004219fa     PUSH       ESI
//         004219fb     MOV        ESI,this
//         004219fd     PUSH       EDI
//         004219fe     MOV        EDI,dword ptr [ESP + param_3]
//         00421a02     MOV        this,dword ptr [ESI + 0x48]
//         00421a05     TEST       this,this
//         00421a07     JZ         LAB_00421a16
//                              basegame.cpp:4661 (13)
//         00421a09     MOV        EAX,dword ptr [ESP + param_2]
//         00421a0d     PUSH       EBX
//         00421a0e     PUSH       EDI
//         00421a0f     PUSH       EAX
//         00421a10     PUSH       EBP
//         00421a11     CALL       TDrawSystem::HandlePaletteChanged                void HandlePaletteChanged(TDrawSystem * this,
//                               LAB_00421a16                                                 XREF[1]:     00421a07(j)
//                              basegame.cpp:4663 (4)
//         00421a16     CMP        EDI,EBP
//         00421a18     JZ         LAB_00421a6a
//                              basegame.cpp:4666 (25)
//         00421a1a     MOV        this,dword ptr [ESI + 0x48]
//         00421a1d     CMP        byte ptr [ECX + this+0x478],0x1
//         00421a24     JZ         LAB_00421a58
//         00421a26     CMP        byte ptr [ECX + this+0x479],0x1
//         00421a2d     JZ         LAB_00421a58
//         00421a2f     TEST       this,this
//         00421a31     JZ         LAB_00421a58
//                              basegame.cpp:4672 (9)
//         00421a33     CMP        dword ptr [ESI + 0x1b0],0x1
//         00421a3a     JZ         LAB_00421a6a
//                              basegame.cpp:4673 (16)
//         00421a3c     LEA        EDX,[ECX + this->save_music_track_to]
//         00421a3f     PUSH       EDX
//         00421a40     PUSH       0x100
//         00421a45     PUSH       0x0
//         00421a47     CALL       TDrawSystem::ModifyPalette                       void ModifyPalette(TDrawSystem * this, int pa
//                              basegame.cpp:4677 (5)
//         00421a4c     MOV        EAX,0x1
//                              basegame.cpp:4678 (7)
//         00421a51     POP        EDI
//         00421a52     POP        ESI
//         00421a53     POP        EBP
//         00421a54     POP        EBX
//         00421a55     RET        0x10
//                               LAB_00421a58                                                 XREF[3]:     00421a24(j), 00421a2d(j),
//                                                                                                         00421a31(j)
//                              basegame.cpp:4668 (18)
//         00421a58     MOV        this,dword ptr [ESP + param_2]
//         00421a5c     MOV        EAX,dword ptr [ESI]
//         00421a5e     PUSH       EBX
//         00421a5f     PUSH       EDI
//         00421a60     PUSH       this
//         00421a61     PUSH       EBP
//         00421a62     MOV        this,ESI
//         00421a64     CALL       dword ptr [EAX + 0xec]
//                               LAB_00421a6a                                                 XREF[2]:     00421a18(j), 00421a3a(j)
//                              basegame.cpp:4678 (12)
//         00421a6a     POP        EDI
//         00421a6b     POP        ESI
//         00421a6c     POP        EBP
//         00421a6d     MOV        EAX,0x1
//         00421a72     POP        EBX
//         00421a73     RET        0x10
//         00421a76     ??         90h
//         00421a77     NOP
//         00421a78     NOP
//         00421a79     NOP
//         00421a7a     NOP
//         00421a7b     NOP
//         00421a7c     NOP
//         00421a7d     NOP
//         00421a7e     NOP
//         00421a7f     NOP
    return 0;
}

int RGE_Base_Game::handle_query_new_palette(void* param_1, uint param_2, uint param_3, long param_4) {
    /* TODO: Stub */
//                              int __thiscall handle_query_new_palette(RGE_Base_Game * this, void *
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              void *            Stack[0x4]:4   param_1                   XREF[2]:     00421a9f(R), 00421acd(R)
//              uint              Stack[0x8]:4   param_2
//              uint              Stack[0xc]:4   param_3
//              long              Stack[0x10]:4  param_4
//                               ?handle_query_new_palette@RGE_Base_Game@@MAEHPAXIIJ@Z        XREF[2]:     handle_query_new_palette:005299ce(
//                               RGE_Base_Game::handle_query_new_palette                                   0056efbc(*)
//                              basegame.cpp:4683 (6)
//         00421a80     PUSH       EBX
//         00421a81     PUSH       EBP
//         00421a82     MOV        EBP,this
//         00421a84     PUSH       ESI
//         00421a85     PUSH       EDI
//                              basegame.cpp:4692 (7)
//         00421a86     MOV        EAX,dword ptr [EBP + 0x48]
//         00421a89     TEST       EAX,EAX
//         00421a8b     JZ         LAB_00421acd
//                              basegame.cpp:4694 (18)
//         00421a8d     CMP        byte ptr [EAX + 0x478],0x1
//         00421a94     JZ         LAB_00421acd
//         00421a96     CMP        byte ptr [EAX + 0x479],0x1
//         00421a9d     JZ         LAB_00421acd
//                              basegame.cpp:4699 (15)
//         00421a9f     MOV        ESI,dword ptr [ESP + param_1]
//         00421aa3     PUSH       0x0
//         00421aa5     PUSH       0x0
//         00421aa7     PUSH       ESI
//         00421aa8     CALL       dword ptr [->USER32.DLL::InvalidateRect]         = 0048af16
//                              basegame.cpp:4700 (24)
//         00421aae     MOV        EAX,dword ptr [ESP + 0x20]
//         00421ab2     MOV        this,dword ptr [ESP + 0x1c]
//         00421ab6     MOV        EDX,dword ptr [ESP + 0x18]
//         00421aba     PUSH       EAX
//         00421abb     PUSH       this=>DAT_fffffff8
//         00421abc     MOV        this,dword ptr [EBP + 0x48]
//         00421abf     PUSH       EDX=>DAT_fffffff4
//         00421ac0     PUSH       ESI=>DAT_fffffff0
//         00421ac1     CALL       TDrawSystem::HandleQueryNewPalette               int HandleQueryNewPalette(TDrawSystem * this,
//                              basegame.cpp:4726 (7)
//         00421ac6     POP        EDI
//         00421ac7     POP        ESI
//         00421ac8     POP        EBP
//         00421ac9     POP        EBX
//         00421aca     RET        0x10
//                               LAB_00421acd                                                 XREF[3]:     00421a8b(j), 00421a94(j),
//                                                                                                         00421a9d(j)
//                              basegame.cpp:4704 (11)
//         00421acd     MOV        EBX,dword ptr [ESP + param_1]
//         00421ad1     PUSH       EBX
//         00421ad2     CALL       dword ptr [->USER32.DLL::GetDC]                  = 0048ae28
//                              basegame.cpp:4706 (16)
//         00421ad8     MOV        this,panel_system
//         00421add     MOV        ESI,EAX
//         00421adf     CALL       TPanelSystem::currentPanel                       TPanel * currentPanel(TPanelSystem * this)
//         00421ae4     TEST       EAX,EAX
//         00421ae6     JZ         LAB_00421b0a
//                              basegame.cpp:4707 (12)
//         00421ae8     MOV        this,panel_system
//         00421aed     CALL       TPanelSystem::currentPanel                       TPanel * currentPanel(TPanelSystem * this)
//         00421af2     MOV        EDI,EAX
//                              basegame.cpp:4708 (11)
//         00421af4     MOV        this,EDI
//         00421af6     CALL       TEasy_Panel::get_palette                         void * get_palette(TEasy_Panel * this)
//         00421afb     TEST       EAX,EAX
//         00421afd     JZ         LAB_00421b1b
//                              basegame.cpp:4709 (9)
//         00421aff     PUSH       0x0
//         00421b01     MOV        this,EDI
//         00421b03     CALL       TEasy_Panel::get_palette                         void * get_palette(TEasy_Panel * this)
//                              basegame.cpp:4711 (9)
//         00421b08     JMP        LAB_00421b13
//                               LAB_00421b0a                                                 XREF[1]:     00421ae6(j)
//         00421b0a     MOV        EAX,dword ptr [EBP + 0x1c]
//         00421b0d     TEST       EAX,EAX
//         00421b0f     JZ         LAB_00421b1b
//                              basegame.cpp:4712 (10)
//         00421b11     PUSH       0x0
//                               LAB_00421b13                                                 XREF[1]:     00421b08(j)
//         00421b13     PUSH       EAX
//         00421b14     PUSH       ESI
//         00421b15     CALL       dword ptr [->GDI32.DLL::SelectPalette]           = 0048b1dc
//                               LAB_00421b1b                                                 XREF[2]:     00421afd(j), 00421b0f(j)
//                              basegame.cpp:4715 (7)
//         00421b1b     PUSH       ESI
//         00421b1c     CALL       dword ptr [->GDI32.DLL::RealizePalette]          = 0048b1ca
//                              basegame.cpp:4717 (10)
//         00421b22     PUSH       ESI
//         00421b23     PUSH       EBX
//         00421b24     MOV        EDI,EAX
//         00421b26     CALL       dword ptr [->USER32.DLL::ReleaseDC]              = 0048ae1c
//                              basegame.cpp:4719 (4)
//         00421b2c     TEST       EDI,EDI
//         00421b2e     JZ         LAB_00421b3b
//                              basegame.cpp:4720 (11)
//         00421b30     PUSH       0x0
//         00421b32     PUSH       0x0
//         00421b34     PUSH       EBX
//         00421b35     CALL       dword ptr [->USER32.DLL::InvalidateRect]         = 0048af16
//                               LAB_00421b3b                                                 XREF[1]:     00421b2e(j)
//                              basegame.cpp:4722 (7)
//         00421b3b     MOV        this,dword ptr [EBP + 0x48]
//         00421b3e     TEST       this,this
//         00421b40     JZ         LAB_00421b5e
//                              basegame.cpp:4723 (21)
//         00421b42     MOV        EAX,dword ptr [ESP + 0x20]
//         00421b46     MOV        EDX,dword ptr [ESP + 0x1c]
//         00421b4a     PUSH       EAX
//         00421b4b     MOV        EAX,dword ptr [ESP + 0x1c]
//         00421b4f     PUSH       EDX=>DAT_fffffff8
//         00421b50     PUSH       EAX=>DAT_fffffff4
//         00421b51     PUSH       EBX=>DAT_fffffff0
//         00421b52     CALL       TDrawSystem::HandleQueryNewPalette               int HandleQueryNewPalette(TDrawSystem * this,
//                              basegame.cpp:4726 (19)
//         00421b57     POP        EDI
//         00421b58     POP        ESI
//         00421b59     POP        EBP
//         00421b5a     POP        EBX
//         00421b5b     RET        0x10
//                               LAB_00421b5e                                                 XREF[1]:     00421b40(j)
//         00421b5e     POP        EDI
//         00421b5f     POP        ESI
//         00421b60     POP        EBP
//         00421b61     MOV        EAX,0x1
//         00421b66     POP        EBX
//         00421b67     RET        0x10
//         00421b6a     ??         90h
//         00421b6b     NOP
//         00421b6c     NOP
//         00421b6d     NOP
//         00421b6e     NOP
//         00421b6f     NOP
    return 0;
}

int RGE_Base_Game::handle_close(void* param_1, uint param_2, uint param_3, long param_4) {
    /* TODO: Stub */
//                              int __thiscall handle_close(RGE_Base_Game * this, void * param_1, ui
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              void *            Stack[0x4]:4   param_1
//              uint              Stack[0x8]:4   param_2
//              uint              Stack[0xc]:4   param_3
//              long              Stack[0x10]:4  param_4
//                               ?handle_close@RGE_Base_Game@@MAEHPAXIIJ@Z                    XREF[2]:     0056efc0(*), 00577298(*)
//                               RGE_Base_Game::handle_close
//                              basegame.cpp:4732 (3)
//         00421b70     PUSH       ESI
//         00421b71     MOV        ESI,this
//                              basegame.cpp:4733 (12)
//         00421b73     MOV        EAX,dword ptr [ESI]
//         00421b75     CALL       dword ptr [EAX + 0x124]
//         00421b7b     TEST       EAX,EAX
//         00421b7d     JNZ        LAB_00421b83
//                              basegame.cpp:4744 (4)
//         00421b7f     POP        ESI
//         00421b80     RET        0x10
//                               LAB_00421b83                                                 XREF[1]:     00421b7d(j)
//                              basegame.cpp:4736 (14)
//         00421b83     MOV        this,dword ptr [ESI + 0x4c]
//         00421b86     TEST       this,this
//         00421b88     JZ         LAB_00421ba4
//         00421b8a     MOV        EAX,dword ptr [ESI + 0x48]
//         00421b8d     TEST       EAX,EAX
//         00421b8f     JZ         LAB_00421ba4
//                              basegame.cpp:4738 (9)
//         00421b91     PUSH       0x0
//         00421b93     PUSH       0x0=>DAT_fffffff8
//         00421b95     CALL       TDrawArea::Clear                                 void Clear(TDrawArea * this, tagRECT * param_
//                              basegame.cpp:4739 (10)
//         00421b9a     MOV        this,dword ptr [ESI + 0x48]
//         00421b9d     PUSH       0x0
//         00421b9f     CALL       TDrawSystem::Paint                               void Paint(TDrawSystem * this, tagRECT * para
//                               LAB_00421ba4                                                 XREF[2]:     00421b88(j), 00421b8f(j)
//                              basegame.cpp:4743 (5)
//         00421ba4     MOV        EAX,0x1
//                              basegame.cpp:4744 (4)
//         00421ba9     POP        ESI
//         00421baa     RET        0x10
//         00421bad     ??         90h
//         00421bae     NOP
//         00421baf     NOP
    return 0;
}

int RGE_Base_Game::handle_destroy(void* param_1, uint param_2, uint param_3, long param_4) {
    /* TODO: Stub */
//                              int __thiscall handle_destroy(RGE_Base_Game * this, void * param_1,
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              void *            Stack[0x4]:4   param_1
//              uint              Stack[0x8]:4   param_2
//              uint              Stack[0xc]:4   param_3
//              long              Stack[0x10]:4  param_4
//                               ?handle_destroy@RGE_Base_Game@@MAEHPAXIIJ@Z                  XREF[2]:     0056efc4(*), 0057729c(*)
//                               RGE_Base_Game::handle_destroy
//                              basegame.cpp:4750 (3)
//         00421bb0     PUSH       ESI
//         00421bb1     MOV        ESI,this
//                              basegame.cpp:4753 (14)
//         00421bb3     MOV        EAX,dword ptr [ESI + 0x44]
//         00421bb6     MOV        dword ptr [ESI + 0x14],0x0
//         00421bbd     TEST       EAX,EAX
//         00421bbf     JZ         LAB_00421bcd
//                              basegame.cpp:4754 (12)
//         00421bc1     MOV        EAX,dword ptr [ESI + 0x10]
//         00421bc4     PUSH       0x1
//         00421bc6     PUSH       EAX
//         00421bc7     CALL       dword ptr [->USER32.DLL::KillTimer]              = 0048af64
//                               LAB_00421bcd                                                 XREF[1]:     00421bbf(j)
//                              basegame.cpp:4758 (15)
//         00421bcd     PUSH       0x0
//         00421bcf     MOV        dword ptr [ESI + 0x10],0x0
//         00421bd6     CALL       dword ptr [->USER32.DLL::PostQuitMessage]        = 0048af52
//                              basegame.cpp:4760 (5)
//         00421bdc     MOV        EAX,0x1
//                              basegame.cpp:4761 (4)
//         00421be1     POP        ESI
//         00421be2     RET        0x10
//         00421be5     ??         90h
//         00421be6     NOP
//         00421be7     NOP
//         00421be8     NOP
//         00421be9     NOP
//         00421bea     NOP
//         00421beb     NOP
//         00421bec     NOP
//         00421bed     NOP
//         00421bee     NOP
//         00421bef     NOP
    return 0;
}

void RGE_Base_Game::calc_timings() {
    /* TODO: Stub */
//                              void __thiscall calc_timings(RGE_Base_Game * this)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?calc_timings@RGE_Base_Game@@MAEXXZ                          XREF[2]:     0056eff8(*), 005772d0(*)
//                               RGE_Base_Game::calc_timings
//                              basegame.cpp:4767 (9)
//         00421bf0     SUB        ESP,0x18
//         00421bf3     PUSH       EBX
//         00421bf4     PUSH       EBP
//         00421bf5     PUSH       ESI
//         00421bf6     MOV        ESI,this
//         00421bf8     PUSH       EDI
//                              basegame.cpp:4776 (13)
//         00421bf9     XOR        EBX,EBX
//         00421bfb     LEA        EDI,[ESI + 0x528]
//         00421c01     MOV        EBP,0x1e
//                               LAB_00421c06                                                 XREF[1]:     00421c48(j)
//                              basegame.cpp:4781 (7)
//         00421c06     MOV        EAX,dword ptr [EDI + 0x10]
//         00421c09     TEST       EAX,EAX
//         00421c0b     JNZ        LAB_00421c44
//                              basegame.cpp:4785 (2)
//         00421c0d     MOV        EAX,dword ptr [EDI]
//                              basegame.cpp:4789 (40)
//         00421c0f     PUSH       0x12b5
//         00421c14     MOV        dword ptr [EDI + 0x4],EAX
//         00421c17     MOV        this,dword ptr [EDI + 0x18]
//         00421c1a     MOV        dword ptr [EDI + 0x1c],this
//         00421c1d     MOV        dword ptr [EDI],0x0
//         00421c23     PUSH       s_C:\msdev\work\age1_x1\basegame.c               = "C:\\msdev\\work\\age1_x1\\basegame.cpp"
//         00421c28     MOV        dword ptr [EDI + 0x18],0x0
//         00421c2f     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         00421c34     MOV        dword ptr [EDI + 0x8],EAX
//                              basegame.cpp:4792 (10)
//         00421c37     MOV        EAX,dword ptr [EDI + 0xc]
//         00421c3a     ADD        ESP,0x8
//         00421c3d     TEST       EAX,EAX
//         00421c3f     JZ         LAB_00421c44
//                              basegame.cpp:4793 (9)
//         00421c41     ADD        EBX,dword ptr [EDI + 0x4]
//                               LAB_00421c44                                                 XREF[2]:     00421c0b(j), 00421c3f(j)
//         00421c44     ADD        EDI,0x20
//         00421c47     DEC        EBP
//         00421c48     JNZ        LAB_00421c06
//                              basegame.cpp:4797 (10)
//         00421c4a     MOV        EAX,dword ptr [ESI + 0x530]
//         00421c50     TEST       EAX,EAX
//         00421c52     JBE        LAB_00421c76
//                              basegame.cpp:4798 (32)
//         00421c54     PUSH       0x12be
//         00421c59     PUSH       s_C:\msdev\work\age1_x1\basegame.c               = "C:\\msdev\\work\\age1_x1\\basegame.cpp"
//         00421c5e     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         00421c63     MOV        this,dword ptr [ESI + 0x530]
//         00421c69     ADD        ESP,0x8
//         00421c6c     SUB        EAX,this
//         00421c6e     MOV        dword ptr [ESI + 0x52c],EAX
//                              basegame.cpp:4799 (2)
//         00421c74     JMP        LAB_00421c7c
//                               LAB_00421c76                                                 XREF[1]:     00421c52(j)
//                              basegame.cpp:4800 (6)
//         00421c76     MOV        dword ptr [ESI + 0x52c],EBX
//                               LAB_00421c7c                                                 XREF[1]:     00421c74(j)
//                              basegame.cpp:4801 (15)
//         00421c7c     PUSH       0x12c1
//         00421c81     PUSH       s_C:\msdev\work\age1_x1\basegame.c               = "C:\\msdev\\work\\age1_x1\\basegame.cpp"
//         00421c86     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//                              basegame.cpp:4804 (19)
//         00421c8b     MOV        this,dword ptr [ESI + 0x52c]
//         00421c91     ADD        ESP,0x8
//         00421c94     CMP        this,EBX
//         00421c96     MOV        dword ptr [ESI + 0x530],EAX
//         00421c9c     JBE        LAB_00421cac
//                              basegame.cpp:4805 (4)
//         00421c9e     MOV        EDX,this
//         00421ca0     SUB        EDX,EBX
//                              basegame.cpp:4806 (10)
//         00421ca2     XOR        EBP,EBP
//         00421ca4     MOV        dword ptr [ESI + 0x5ac],EDX
//         00421caa     JMP        LAB_00421cb4
//                               LAB_00421cac                                                 XREF[1]:     00421c9c(j)
//                              basegame.cpp:4807 (8)
//         00421cac     XOR        EBP,EBP
//         00421cae     MOV        dword ptr [ESI + 0x5ac],EBP
//                               LAB_00421cb4                                                 XREF[1]:     00421caa(j)
//                              basegame.cpp:4810 (25)
//         00421cb4     MOV        EDX,dword ptr [ESI + 0x5ec]
//         00421cba     MOV        EDI,dword ptr [ESI + 0x60c]
//         00421cc0     MOV        EAX,dword ptr [ESI + 0x56c]
//         00421cc6     LEA        EBX,[EDI + EDX*0x1]
//         00421cc9     CMP        EAX,EBX
//         00421ccb     JBE        LAB_00421cd9
//                              basegame.cpp:4811 (10)
//         00421ccd     SUB        EAX,EDX
//         00421ccf     SUB        EAX,EDI
//         00421cd1     MOV        dword ptr [ESI + 0x64c],EAX
//                              basegame.cpp:4812 (2)
//         00421cd7     JMP        LAB_00421cdf
//                               LAB_00421cd9                                                 XREF[1]:     00421ccb(j)
//                              basegame.cpp:4813 (6)
//         00421cd9     MOV        dword ptr [ESI + 0x64c],EBP
//                               LAB_00421cdf                                                 XREF[1]:     00421cd7(j)
//                              basegame.cpp:4816 (26)
//         00421cdf     CMP        this,EBP
//         00421ce1     JZ         LAB_00421d0a
//         00421ce3     MOV        EDI,dword ptr [ESI + 0x504]
//         00421ce9     CMP        EDI,EBP
//         00421ceb     JZ         LAB_00421d0a
//         00421ced     MOV        EAX,this
//         00421cef     XOR        EDX,EDX
//         00421cf1     DIV        EDI
//         00421cf3     MOV        EDI,EAX
//         00421cf5     CMP        EDI,EBP
//         00421cf7     JZ         LAB_00421d0a
//                              basegame.cpp:4819 (17)
//         00421cf9     MOV        EAX,0x3e8
//         00421cfe     XOR        EDX,EDX
//         00421d00     DIV        EDI
//         00421d02     MOV        dword ptr [ESI + 0x51c],EAX
//         00421d08     JMP        LAB_00421d14
//                               LAB_00421d0a                                                 XREF[3]:     00421ce1(j), 00421ceb(j),
//                                                                                                         00421cf7(j)
//                              basegame.cpp:4817 (10)
//         00421d0a     MOV        dword ptr [ESI + 0x51c],0x3e8
//                               LAB_00421d14                                                 XREF[1]:     00421d08(j)
//                              basegame.cpp:4821 (26)
//         00421d14     CMP        this,EBP
//         00421d16     JZ         LAB_00421d3f
//         00421d18     MOV        EDI,dword ptr [ESI + 0x50c]
//         00421d1e     CMP        EDI,EBP
//         00421d20     JZ         LAB_00421d3f
//         00421d22     MOV        EAX,this
//         00421d24     XOR        EDX,EDX
//         00421d26     DIV        EDI
//         00421d28     MOV        EDI,EAX
//         00421d2a     CMP        EDI,EBP
//         00421d2c     JZ         LAB_00421d3f
//                              basegame.cpp:4824 (17)
//         00421d2e     MOV        EAX,0x3e8
//         00421d33     XOR        EDX,EDX
//         00421d35     DIV        EDI
//         00421d37     MOV        dword ptr [ESI + 0x524],EAX
//         00421d3d     JMP        LAB_00421d45
//                               LAB_00421d3f                                                 XREF[3]:     00421d16(j), 00421d20(j),
//                                                                                                         00421d2c(j)
//                              basegame.cpp:4822 (6)
//         00421d3f     MOV        dword ptr [ESI + 0x524],EBP
//                               LAB_00421d45                                                 XREF[1]:     00421d3d(j)
//                              basegame.cpp:4826 (26)
//         00421d45     CMP        this,EBP
//         00421d47     JZ         LAB_00421d70
//         00421d49     MOV        EDI,dword ptr [ESI + 0x508]
//         00421d4f     CMP        EDI,EBP
//         00421d51     JZ         LAB_00421d70
//         00421d53     MOV        EAX,this
//         00421d55     XOR        EDX,EDX
//         00421d57     DIV        EDI
//         00421d59     MOV        this,EAX
//         00421d5b     CMP        this,EBP
//         00421d5d     JZ         LAB_00421d70
//                              basegame.cpp:4829 (17)
//         00421d5f     MOV        EAX,0x3e8
//         00421d64     XOR        EDX,EDX
//         00421d66     DIV        this
//         00421d68     MOV        dword ptr [ESI + 0x520],EAX
//         00421d6e     JMP        LAB_00421d76
//                               LAB_00421d70                                                 XREF[3]:     00421d47(j), 00421d51(j),
//                                                                                                         00421d5d(j)
//                              basegame.cpp:4827 (6)
//         00421d70     MOV        dword ptr [ESI + 0x520],EBP
//                               LAB_00421d76                                                 XREF[1]:     00421d6e(j)
//                              basegame.cpp:4831 (10)
//         00421d76     MOV        EAX,dword ptr [ESI]
//         00421d78     MOV        this,ESI
//         00421d7a     CALL       dword ptr [EAX + 0x12c]
//                              basegame.cpp:4834 (25)
//         00421d80     CMP        dword ptr [do_fps_log],EBP
//         00421d86     JZ         LAB_00421f58
//         00421d8c     CMP        dword ptr [ESI + 0x1b0],0x4
//         00421d93     JNZ        LAB_00421f58
//                              basegame.cpp:4838 (19)
//         00421d99     MOV        EAX,dword ptr [ESI + 0x3f4]
//         00421d9f     XOR        EDI,EDI
//         00421da1     XOR        EBX,EBX
//         00421da3     MOVSX      EDX,word ptr [EAX + 0x3c]
//         00421da7     CMP        EDX,0x1
//         00421daa     JLE        LAB_00421dcf
//                              basegame.cpp:4914 (33)
//         00421dac     MOV        this,dword ptr [EAX + 0x40]
//         00421daf     ADD        this,0x4
//         00421db2     DEC        EDX
//                               LAB_00421db3                                                 XREF[1]:     00421dcb(j)
//         00421db3     MOV        EAX,dword ptr [this->_padding_]
//         00421db5     ADD        this,0x4
//         00421db8     MOV        EBP,dword ptr [EAX + 0x28]
//         00421dbb     MOV        EAX,dword ptr [EAX + 0x2c]
//         00421dbe     MOVSX      EBP,word ptr [EBP + 0x8]
//         00421dc2     MOVSX      EAX,word ptr [EAX + 0x8]
//         00421dc6     ADD        EDI,EBP
//         00421dc8     ADD        EBX,EAX
//         00421dca     DEC        EDX
//         00421dcb     JNZ        LAB_00421db3
//                              basegame.cpp:4838 (2)
//         00421dcd     XOR        EBP,EBP
//                               LAB_00421dcf                                                 XREF[1]:     00421daa(j)
//                              basegame.cpp:4900 (371)
//         00421dcf     MOV        this,dword ptr [ESI + 0x508]
//         00421dd5     CMP        this,EBP
//         00421dd7     JNZ        LAB_00421ddf
//         00421dd9     MOV        dword ptr [ESP + 0x10],EBP
//         00421ddd     JMP        LAB_00421ded
//                               LAB_00421ddf                                                 XREF[1]:     00421dd7(j)
//         00421ddf     MOV        EAX,dword ptr [ESI + 0x5ac]
//         00421de5     XOR        EDX,EDX
//         00421de7     DIV        this
//         00421de9     MOV        dword ptr [ESP + 0x10],EAX
//                               LAB_00421ded                                                 XREF[1]:     00421ddd(j)
//         00421ded     CMP        this,EBP
//         00421def     JNZ        LAB_00421df7
//         00421df1     MOV        dword ptr [ESP + 0x14],EBP
//         00421df5     JMP        LAB_00421e05
//                               LAB_00421df7                                                 XREF[1]:     00421def(j)
//         00421df7     MOV        EAX,dword ptr [ESI + 0x6cc]
//         00421dfd     XOR        EDX,EDX
//         00421dff     DIV        this
//         00421e01     MOV        dword ptr [ESP + 0x14],EAX
//                               LAB_00421e05                                                 XREF[1]:     00421df5(j)
//         00421e05     CMP        this,EBP
//         00421e07     JNZ        LAB_00421e0f
//         00421e09     MOV        dword ptr [ESP + 0x18],EBP
//         00421e0d     JMP        LAB_00421e25
//                               LAB_00421e0f                                                 XREF[1]:     00421e07(j)
//         00421e0f     MOV        EAX,dword ptr [ESI + 0x66c]
//         00421e15     MOV        EDX,dword ptr [ESI + 0x6ac]
//         00421e1b     ADD        EAX,EDX
//         00421e1d     XOR        EDX,EDX
//         00421e1f     DIV        this
//         00421e21     MOV        dword ptr [ESP + 0x18],EAX
//                               LAB_00421e25                                                 XREF[1]:     00421e0d(j)
//         00421e25     CMP        this,EBP
//         00421e27     JNZ        LAB_00421e2f
//         00421e29     MOV        dword ptr [ESP + 0x1c],EBP
//         00421e2d     JMP        LAB_00421e3d
//                               LAB_00421e2f                                                 XREF[1]:     00421e27(j)
//         00421e2f     MOV        EAX,dword ptr [ESI + 0x54c]
//         00421e35     XOR        EDX,EDX
//         00421e37     DIV        this
//         00421e39     MOV        dword ptr [ESP + 0x1c],EAX
//                               LAB_00421e3d                                                 XREF[1]:     00421e2d(j)
//         00421e3d     CMP        this,EBP
//         00421e3f     JNZ        LAB_00421e47
//         00421e41     MOV        dword ptr [ESP + 0x20],EBP
//         00421e45     JMP        LAB_00421e55
//                               LAB_00421e47                                                 XREF[1]:     00421e3f(j)
//         00421e47     MOV        EAX,dword ptr [ESI + 0x58c]
//         00421e4d     XOR        EDX,EDX
//         00421e4f     DIV        this
//         00421e51     MOV        dword ptr [ESP + 0x20],EAX
//                               LAB_00421e55                                                 XREF[1]:     00421e45(j)
//         00421e55     CMP        this,EBP
//         00421e57     JNZ        LAB_00421e5f
//         00421e59     MOV        dword ptr [ESP + 0x24],EBP
//         00421e5d     JMP        LAB_00421e6d
//                               LAB_00421e5f                                                 XREF[1]:     00421e57(j)
//         00421e5f     MOV        EAX,dword ptr [ESI + 0x60c]
//         00421e65     XOR        EDX,EDX
//         00421e67     DIV        this
//         00421e69     MOV        dword ptr [ESP + 0x24],EAX
//                               LAB_00421e6d                                                 XREF[1]:     00421e5d(j)
//         00421e6d     CMP        this,EBP
//         00421e6f     JNZ        LAB_00421e75
//         00421e71     XOR        EAX,EAX
//         00421e73     JMP        LAB_00421e7f
//                               LAB_00421e75                                                 XREF[1]:     00421e6f(j)
//         00421e75     MOV        EAX,dword ptr [ESI + 0x5ec]
//         00421e7b     XOR        EDX,EDX
//         00421e7d     DIV        this
//                               LAB_00421e7f                                                 XREF[1]:     00421e73(j)
//         00421e7f     PUSH       -0x1
//         00421e81     PUSH       offset DAT_fffffff8
//         00421e83     PUSH       EBP=>DAT_fffffff4
//         00421e84     MOV        EBP,dword ptr [ESI + 0x5c4]
//         00421e8a     PUSH       EBP=>DAT_fffffff0
//         00421e8b     MOV        EBP,dword ptr [ESP + 0x20]
//         00421e8f     PUSH       EBP
//         00421e90     MOV        EBP,dword ptr [ESI + 0x6e4]
//         00421e96     PUSH       EBP
//         00421e97     MOV        EBP,dword ptr [ESP + 0x2c]
//         00421e9b     PUSH       EBP
//         00421e9c     MOV        EBP,dword ptr [ESI + 0x684]
//         00421ea2     ADD        EBP,dword ptr [ESI + 0x6c4]
//         00421ea8     MOV        EDX,dword ptr [ESI + 0x3f4]
//         00421eae     PUSH       EBP
//         00421eaf     MOV        EBP,dword ptr [ESP + 0x38]
//         00421eb3     PUSH       EBP
//         00421eb4     MOV        EBP,dword ptr [ESI + 0x564]
//         00421eba     PUSH       EBP
//         00421ebb     MOV        EBP,dword ptr [ESP + 0x44]
//         00421ebf     PUSH       EBP
//         00421ec0     MOV        EBP,dword ptr [ESI + 0x5a4]
//         00421ec6     PUSH       EBP
//         00421ec7     MOV        EBP,dword ptr [ESP + 0x50]
//         00421ecb     PUSH       EBP
//         00421ecc     MOV        EBP,dword ptr [ESI + 0x624]
//         00421ed2     PUSH       EBP
//         00421ed3     MOV        EBP,dword ptr [ESP + 0x5c]
//         00421ed7     PUSH       EBP
//         00421ed8     MOV        EBP,dword ptr [ESI + 0x604]
//         00421ede     MOV        EDX,dword ptr [EDX + 0x40]
//         00421ee1     PUSH       EBP
//         00421ee2     PUSH       EAX
//         00421ee3     MOV        EAX,dword ptr [ESI + 0x524]
//         00421ee9     MOV        EDX,dword ptr [EDX]
//         00421eeb     PUSH       EAX
//         00421eec     MOV        EAX,dword ptr [ESI + 0x520]
//         00421ef2     PUSH       EAX
//         00421ef3     MOV        EAX,dword ptr [ESI + 0x50c]
//         00421ef9     PUSH       EAX
//         00421efa     PUSH       this
//         00421efb     MOV        this,dword ptr [EDX + 0x2c]
//         00421efe     PUSH       EBX
//         00421eff     PUSH       EDI
//         00421f00     MOVSX      EAX,word ptr [ECX + this->scenario_info]
//         00421f04     MOV        this,dword ptr [EDX + 0x28]
//         00421f07     PUSH       EAX
//         00421f08     MOV        EAX,[cur_mem_high]
//         00421f0d     MOVSX      EDX,word ptr [ECX + this->scenario_info]
//         00421f11     MOV        this,dword ptr [cur_mem_total]
//         00421f17     PUSH       EDX
//         00421f18     MOV        EDX,dword ptr [start_mem_high]
//         00421f1e     PUSH       EAX
//         00421f1f     MOV        EAX,[start_mem_total]
//         00421f24     PUSH       this
//         00421f25     PUSH       EDX
//         00421f26     MOV        EDX,dword ptr [fps_log]                          = 00000000
//         00421f2c     PUSH       EAX
//         00421f2d     MOV        EAX,dword ptr [ESI + 0x3f4]
//         00421f33     MOV        this,dword ptr [EAX + 0x4]
//         00421f36     PUSH       this
//         00421f37     PUSH       s_%lu,_%ld,_%ld,_%ld,_%ld,_%d,_%d,               = "%lu, %ld, %ld, %ld, %ld, %d, %d, %d, %d, %
//         00421f3c     PUSH       EDX
//         00421f3d     CALL       fprintf                                          undefined fprintf()
//                              basegame.cpp:4903 (22)
//         00421f42     MOV        EAX,[fps_log]                                    = 00000000
//         00421f47     ADD        ESP,0x80
//         00421f4d     PUSH       EAX
//         00421f4e     CALL       fflush                                           undefined fflush()
//         00421f53     ADD        ESP,0x4
//         00421f56     XOR        EBP,EBP
//                               LAB_00421f58                                                 XREF[2]:     00421d86(j), 00421d93(j)
//                              basegame.cpp:4907 (6)
//         00421f58     MOV        this,dword ptr [ESI + 0x504]
//                              basegame.cpp:4908 (6)
//         00421f5e     MOV        EDX,dword ptr [ESI + 0x508]
//                              basegame.cpp:4909 (24)
//         00421f64     MOV        EAX,dword ptr [ESI + 0x50c]
//         00421f6a     MOV        dword ptr [ESI + 0x510],this
//         00421f70     MOV        dword ptr [ESI + 0x514],EDX
//         00421f76     MOV        dword ptr [ESI + 0x518],EAX
//                              basegame.cpp:4911 (6)
//         00421f7c     MOV        dword ptr [ESI + 0x504],EBP
//                              basegame.cpp:4912 (6)
//         00421f82     MOV        dword ptr [ESI + 0x508],EBP
//                              basegame.cpp:4913 (6)
//         00421f88     MOV        dword ptr [ESI + 0x50c],EBP
//                              basegame.cpp:4914 (8)
//         00421f8e     POP        EDI
//         00421f8f     POP        ESI
//         00421f90     POP        EBP
//         00421f91     POP        EBX
//         00421f92     ADD        ESP,0x18
//         00421f95     RET
//         00421f96     ??         90h
//         00421f97     NOP
//         00421f98     NOP
//         00421f99     NOP
//         00421f9a     NOP
//         00421f9b     NOP
//         00421f9c     NOP
//         00421f9d     NOP
//         00421f9e     NOP
//         00421f9f     NOP
    return;
}

void RGE_Base_Game::calc_timing_text() {
    /* TODO: Stub */
//                              void __thiscall calc_timing_text(RGE_Base_Game * this)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?calc_timing_text@RGE_Base_Game@@MAEXXZ                      XREF[1]:     0056effc(*)
//                               RGE_Base_Game::calc_timing_text
//                              basegame.cpp:4920 (1)
//         00421fa0     PUSH       ESI
//                              basegame.cpp:4923 (10)
//         00421fa1     MOV        ESI,dword ptr [ECX + this->frame_count]
//         00421fa7     TEST       ESI,ESI
//         00421fa9     JNZ        LAB_00421fb0
//                              basegame.cpp:4924 (5)
//         00421fab     MOV        ESI,0x1
//                               LAB_00421fb0                                                 XREF[1]:     00421fa9(j)
//                              basegame.cpp:4938 (126)
//         00421fb0     MOV        EAX,dword ptr [ECX + this+0x52c]
//         00421fb6     XOR        EDX,EDX
//         00421fb8     DIV        ESI
//         00421fba     XOR        EDX,EDX
//         00421fbc     ADD        this,0x404
//         00421fc2     PUSH       EAX
//         00421fc3     MOV        EAX,dword ptr [ECX + this->log_comm]
//         00421fc9     DIV        ESI
//         00421fcb     XOR        EDX,EDX
//         00421fcd     PUSH       EAX
//         00421fce     MOV        EAX,dword ptr [ECX + this+0x2c8]
//         00421fd4     DIV        ESI
//         00421fd6     XOR        EDX,EDX
//         00421fd8     PUSH       EAX
//         00421fd9     MOV        EAX,dword ptr [ECX + this+0x268]
//         00421fdf     DIV        ESI
//         00421fe1     XOR        EDX,EDX
//         00421fe3     PUSH       EAX
//         00421fe4     MOV        EAX,dword ptr [ECX + this+0x148]
//         00421fea     DIV        ESI
//         00421fec     XOR        EDX,EDX
//         00421fee     PUSH       EAX
//         00421fef     MOV        EAX,dword ptr [ECX + this->save_music_pos]
//         00421ff5     DIV        ESI
//         00421ff7     XOR        EDX,EDX
//         00421ff9     PUSH       EAX
//         00421ffa     MOV        EAX,dword ptr [ECX + this+0x208]
//         00422000     DIV        ESI
//         00422002     XOR        EDX,EDX
//         00422004     PUSH       EAX
//         00422005     MOV        EAX,dword ptr [ECX + this->work_dir[0]]
//         0042200b     DIV        ESI
//         0042200d     XOR        EDX,EDX
//         0042200f     PUSH       EAX
//         00422010     MOV        EAX,dword ptr [ECX + this+0x168]
//         00422016     DIV        ESI
//         00422018     PUSH       EAX
//         00422019     MOV        EAX,dword ptr [ECX + this+0x118]
//         0042201f     PUSH       EAX
//         00422020     PUSH       s_fps=%lu,_rend=%lu,_view=%lu,_map               = "fps=%lu, rend=%lu, view=%lu, map=%lu, scr=
//         00422025     PUSH       this
//         00422026     CALL       sprintf                                          undefined sprintf()
//         0042202b     ADD        ESP,0x30
//                              basegame.cpp:4939 (2)
//         0042202e     POP        ESI
//         0042202f     RET
    return;
}

void RGE_Base_Game::show_timings() {
    /* TODO: Stub */
//                              void __thiscall show_timings(RGE_Base_Game * this)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?show_timings@RGE_Base_Game@@MAEXXZ                          XREF[1]:     0056f000(*)
//                               RGE_Base_Game::show_timings
//                              basegame.cpp:4945 (17)
//         00422030     LEA        EAX,[ECX + this->timing_text[0]]
//         00422036     MOV        this,dword ptr [ECX + this->prog_window]
//         00422039     PUSH       EAX
//         0042203a     PUSH       this
//         0042203b     CALL       dword ptr [->USER32.DLL::SetWindowTextA]         = 0048af70
//                              basegame.cpp:4948 (1)
//         00422041     RET
//         00422042     ??         90h
//         00422043     NOP
//         00422044     NOP
//         00422045     NOP
//         00422046     NOP
//         00422047     NOP
//         00422048     NOP
//         00422049     NOP
//         0042204a     NOP
//         0042204b     NOP
//         0042204c     NOP
//         0042204d     NOP
//         0042204e     NOP
//         0042204f     NOP
    return;
}

void RGE_Base_Game::show_comm() {
    /* TODO: Stub */
//                              void __thiscall show_comm(RGE_Base_Game * this)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              char[256]         Stack[-0x104   str                       XREF[0,2]:   00422067(*), 0042207c(*)
//                               ?show_comm@RGE_Base_Game@@MAEXXZ                             XREF[1]:     0056f004(*)
//                               RGE_Base_Game::show_comm
//                              basegame.cpp:4954 (9)
//         00422050     SUB        ESP,0x100
//         00422056     PUSH       ESI
//         00422057     MOV        ESI,this
//                              basegame.cpp:4956 (29)
//         00422059     PUSH       0x1
//         0042205b     MOV        this,dword ptr [ESI + 0x18c]
//         00422061     CALL       TCommunications_Handler::GetCommInfo             char * GetCommInfo(TCommunications_Handler *
//         00422066     PUSH       EAX
//         00422067     LEA        EAX=>str[4],[ESP + 0x8]
//         0042206b     PUSH       s_%s                                             = "%s"
//         00422070     PUSH       EAX
//         00422071     CALL       sprintf                                          undefined sprintf()
//                              basegame.cpp:4959 (18)
//         00422076     MOV        EDX,dword ptr [ESI + 0x10]
//         00422079     ADD        ESP,0xc
//         0042207c     LEA        this=>str[4],[ESP + 0x4]
//         00422080     PUSH       this
//         00422081     PUSH       EDX
//         00422082     CALL       dword ptr [->USER32.DLL::SetWindowTextA]         = 0048af70
//                              basegame.cpp:4960 (8)
//         00422088     POP        ESI
//         00422089     ADD        ESP,0x100
//         0042208f     RET
    return;
}

void RGE_Base_Game::show_ai() {
    /* TODO: Stub */
//                              void __thiscall show_ai(RGE_Base_Game * this)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              char[256]         Stack[-0x104   str                       XREF[0,2]:   00422096(*), 004220b9(*)
//                               ?show_ai@RGE_Base_Game@@MAEXXZ                               XREF[1]:     0056f008(*)
//                               RGE_Base_Game::show_ai
//                              basegame.cpp:4965 (6)
//         00422090     SUB        ESP,0x100
//                              basegame.cpp:4967 (29)
//         00422096     LEA        EDX=>str[4],[ESP]
//         0042209a     PUSH       ESI
//         0042209b     MOV        ESI,this
//         0042209d     MOV        EAX,dword ptr [ESI + 0x3f4]
//         004220a3     MOVSX      this,word ptr [EAX + 0x7c]
//         004220a7     PUSH       this
//         004220a8     PUSH       s_No_AI_Information_for_Player_#%d               = "No AI Information for Player #%d."
//         004220ad     PUSH       EDX
//         004220ae     CALL       sprintf                                          undefined sprintf()
//                              basegame.cpp:4969 (18)
//         004220b3     MOV        this,dword ptr [ESI + 0x10]
//         004220b6     ADD        ESP,0xc
//         004220b9     LEA        EAX=>str[4],[ESP + 0x4]
//         004220bd     PUSH       EAX
//         004220be     PUSH       this
//         004220bf     CALL       dword ptr [->USER32.DLL::SetWindowTextA]         = 0048af70
//                              basegame.cpp:4970 (8)
//         004220c5     POP        ESI
//         004220c6     ADD        ESP,0x100
//         004220cc     RET
//         004220cd     ??         90h
//         004220ce     NOP
//         004220cf     NOP
    return;
}

void RGE_Base_Game::send_game_options() {
    /* TODO: Stub */
//                              void __thiscall send_game_options(RGE_Base_Game * this)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?send_game_options@RGE_Base_Game@@UAEXXZ                     XREF[1]:     0056ef18(*)
//                               RGE_Base_Game::send_game_options
//                              basegame.cpp:4976 (2)
//         004220d0     MOV        EAX,this
//                              basegame.cpp:4977 (10)
//         004220d2     MOV        this,dword ptr [EAX + 0x18c]
//         004220d8     TEST       this,this
//         004220da     JZ         LAB_004220ec
//                              basegame.cpp:4978 (16)
//         004220dc     ADD        EAX,0x8f8
//         004220e1     PUSH       0xa8
//         004220e6     PUSH       EAX
//         004220e7     CALL       TCommunications_Handler::SetMyGameOptions        int SetMyGameOptions(TCommunications_Handler
//                               LAB_004220ec                                                 XREF[1]:     004220da(j)
//                              basegame.cpp:4979 (1)
//         004220ec     RET
//         004220ed     ??         90h
//         004220ee     NOP
//         004220ef     NOP
    return;
}

void RGE_Base_Game::receive_game_options() {
    /* TODO: Stub */
//                              void __thiscall receive_game_options(RGE_Base_Game * this)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     004220fe(*), 00422102(W), 00422114(R)
//              ulong             Stack[-0x8]:4  size
//                               ?receive_game_options@RGE_Base_Game@@UAEXXZ                  XREF[1]:     0056ef1c(*)
//                               RGE_Base_Game::receive_game_options
//                              basegame.cpp:4985 (4)
//         004220f0     PUSH       this
//         004220f1     PUSH       ESI
//         004220f2     MOV        ESI,this
//                              basegame.cpp:4989 (10)
//         004220f4     MOV        this,dword ptr [ESI + 0x18c]
//         004220fa     TEST       this,this
//         004220fc     JZ         LAB_00422126
//                              basegame.cpp:4992 (18)
//         004220fe     LEA        EAX=>local_4,[ESP + 0x4]
//         00422102     MOV        dword ptr [ESP + local_4],0x0
//         0042210a     PUSH       EAX
//         0042210b     CALL       TCommunications_Handler::GetMyGameOptions        void * GetMyGameOptions(TCommunications_Handl
//                              basegame.cpp:4993 (14)
//         00422110     TEST       EAX,EAX
//         00422112     JZ         LAB_00422126
//         00422114     CMP        dword ptr [ESP + local_4],0xa8
//         0042211c     JNZ        LAB_00422126
//                              basegame.cpp:4994 (8)
//         0042211e     PUSH       EAX
//         0042211f     MOV        this,ESI
//         00422121     CALL       RGE_Base_Game::set_game_options                  void set_game_options(RGE_Base_Game * this, R
//                               LAB_00422126                                                 XREF[3]:     004220fc(j), 00422112(j),
//                                                                                                         0042211c(j)
//                              basegame.cpp:4996 (3)
//         00422126     POP        ESI
//         00422127     POP        this
//         00422128     RET
//         00422129     ??         90h
//         0042212a     NOP
//         0042212b     NOP
//         0042212c     NOP
//         0042212d     NOP
//         0042212e     NOP
//         0042212f     NOP
    return;
}

void RGE_Base_Game::set_game_options(RGE_Game_Options* param_1) {
    /* TODO: Stub */
//                              void __thiscall set_game_options(RGE_Base_Game * this, RGE_Game_Opti
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              RGE_Game_Optio    Stack[0x4]:4   param_1                   XREF[1]:     00422133(R)
//                               ?set_game_options@RGE_Base_Game@@QAEXPAURGE_Game_Options@1@@Z XREF[2]:     receive_game_options:00422121(c),
//                               RGE_Base_Game::set_game_options                                           receive_game_options:00528fe4(c)
//                              basegame.cpp:5002 (3)
//         00422130     PUSH       EBX
//         00422131     PUSH       ESI
//         00422132     PUSH       EDI
//                              basegame.cpp:5005 (14)
//         00422133     MOV        EDI,dword ptr [ESP + param_1]
//         00422137     MOV        EBX,this
//         00422139     MOV        EAX,dword ptr [EDI]
//         0042213b     PUSH       EAX
//         0042213c     CALL       RGE_Base_Game::setVersion                        void setVersion(RGE_Base_Game * this, float p
//                              basegame.cpp:5006 (13)
//         00422141     XOR        this,this
//         00422143     MOV        this,byte ptr [EDI + 0x4]
//         00422146     PUSH       this
//         00422147     MOV        this,EBX
//         00422149     CALL       RGE_Base_Game::setScenarioGame                   void setScenarioGame(RGE_Base_Game * this, in
//                              basegame.cpp:5007 (11)
//         0042214e     LEA        EDX,[EDI + 0x5]
//         00422151     MOV        this,EBX
//         00422153     PUSH       EDX
//         00422154     CALL       RGE_Base_Game::setScenarioName                   void setScenarioName(RGE_Base_Game * this, ch
//                              basegame.cpp:5008 (16)
//         00422159     XOR        EAX,EAX
//         0042215b     MOV        this,EBX
//         0042215d     MOV        AL,byte ptr [EDI + 0x85]
//         00422163     PUSH       EAX
//         00422164     CALL       RGE_Base_Game::setSinglePlayerGame               void setSinglePlayerGame(RGE_Base_Game * this
//                              basegame.cpp:5009 (16)
//         00422169     XOR        this,this
//         0042216b     MOV        this,byte ptr [EDI + 0x86]
//         00422171     PUSH       this
//         00422172     MOV        this,EBX
//         00422174     CALL       RGE_Base_Game::setMultiplayerGame                void setMultiplayerGame(RGE_Base_Game * this,
//                              basegame.cpp:5010 (34)
//         00422179     XOR        EDX,EDX
//         0042217b     XOR        EAX,EAX
//         0042217d     MOV        DL,byte ptr [EDI + 0x89]
//         00422183     MOV        AL,byte ptr [EDI + 0x88]
//         00422189     XOR        this,this
//         0042218b     PUSH       EDX
//         0042218c     MOV        this,byte ptr [EDI + 0x87]
//         00422192     PUSH       EAX
//         00422193     PUSH       this
//         00422194     MOV        this,EBX
//         00422196     CALL       RGE_Base_Game::setMapSize                        void setMapSize(RGE_Base_Game * this, int par
//                              basegame.cpp:5011 (16)
//         0042219b     XOR        EDX,EDX
//         0042219d     MOV        this,EBX
//         0042219f     MOV        DL,byte ptr [EDI + 0x8a]
//         004221a5     PUSH       EDX
//         004221a6     CALL       RGE_Base_Game::setAllowCheatCodes                void setAllowCheatCodes(RGE_Base_Game * this,
//                              basegame.cpp:5012 (16)
//         004221ab     XOR        EAX,EAX
//         004221ad     MOV        this,EBX
//         004221af     MOV        AL,byte ptr [EDI + 0x8c]
//         004221b5     PUSH       EAX
//         004221b6     CALL       RGE_Base_Game::setCheatNotification              void setCheatNotification(RGE_Base_Game * thi
//                              basegame.cpp:5013 (16)
//         004221bb     XOR        this,this
//         004221bd     MOV        this,byte ptr [EDI + 0x8d]
//         004221c3     PUSH       this
//         004221c4     MOV        this,EBX
//         004221c6     CALL       RGE_Base_Game::setFullVisibility                 void setFullVisibility(RGE_Base_Game * this,
//                              basegame.cpp:5014 (16)
//         004221cb     XOR        EDX,EDX
//         004221cd     MOV        this,EBX
//         004221cf     MOV        DL,byte ptr [EDI + 0x8e]
//         004221d5     PUSH       EDX
//         004221d6     CALL       RGE_Base_Game::setFogOfWar                       void setFogOfWar(RGE_Base_Game * this, int pa
//                              basegame.cpp:5015 (16)
//         004221db     XOR        EAX,EAX
//         004221dd     MOV        this,EBX
//         004221df     MOV        AL,byte ptr [EDI + 0x8f]
//         004221e5     PUSH       EAX
//         004221e6     CALL       RGE_Base_Game::setColoredChat                    void setColoredChat(RGE_Base_Game * this, int
//                              basegame.cpp:5016 (16)
//         004221eb     XOR        this,this
//         004221ed     MOV        this,byte ptr [EDI + 0x90]
//         004221f3     PUSH       this
//         004221f4     MOV        this,EBX
//         004221f6     CALL       RGE_Base_Game::setNumberPlayers                  void setNumberPlayers(RGE_Base_Game * this, i
//                              basegame.cpp:5017 (16)
//         004221fb     XOR        EDX,EDX
//         004221fd     MOV        this,EBX
//         004221ff     MOV        DL,byte ptr [EDI + 0x91]
//         00422205     PUSH       EDX
//         00422206     CALL       RGE_Base_Game::setGameDeveloperMode              void setGameDeveloperMode(RGE_Base_Game * thi
//                              basegame.cpp:5018 (16)
//         0042220b     XOR        EAX,EAX
//         0042220d     MOV        this,EBX
//         0042220f     MOV        AL,byte ptr [EDI + 0x9b]
//         00422215     PUSH       EAX
//         00422216     CALL       RGE_Base_Game::setDifficulty                     void setDifficulty(RGE_Base_Game * this, int
//                              basegame.cpp:5019 (14)
//         0042221b     MOV        this,byte ptr [EDI + 0x8b]
//         00422221     PUSH       this
//         00422222     MOV        this,EBX
//         00422224     CALL       RGE_Base_Game::setMpPathFinding                  void setMpPathFinding(RGE_Base_Game * this, u
//                              basegame.cpp:5021 (2)
//         00422229     XOR        ESI,ESI
//                               LAB_0042222b                                                 XREF[1]:     00422251(j)
//                              basegame.cpp:5023 (16)
//         0042222b     MOV        DL,byte ptr [ESI + EDI*0x1 + 0x92]
//         00422232     MOV        this,EBX
//         00422234     PUSH       EDX
//         00422235     PUSH       ESI
//         00422236     CALL       RGE_Base_Game::setPlayerCDAndVersion             void setPlayerCDAndVersion(RGE_Base_Game * th
//                              basegame.cpp:5024 (24)
//         0042223b     XOR        EAX,EAX
//         0042223d     MOV        this,EBX
//         0042223f     MOV        AL,byte ptr [ESI + EDI*0x1 + 0x9c]
//         00422246     PUSH       EAX
//         00422247     PUSH       ESI
//         00422248     CALL       RGE_Base_Game::setPlayerTeam                     void setPlayerTeam(RGE_Base_Game * this, int
//         0042224d     INC        ESI
//         0042224e     CMP        ESI,0x9
//         00422251     JL         LAB_0042222b
//                              basegame.cpp:5026 (6)
//         00422253     POP        EDI
//         00422254     POP        ESI
//         00422255     POP        EBX
//         00422256     RET        0x4
//         00422259     ??         90h
//         0042225a     NOP
//         0042225b     NOP
//         0042225c     NOP
//         0042225d     NOP
//         0042225e     NOP
//         0042225f     NOP
    return;
}

void RGE_Base_Game::get_game_options(RGE_Game_Options* param_1) {
    /* TODO: Stub */
//                              void __thiscall get_game_options(RGE_Base_Game * this, RGE_Game_Opti
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              RGE_Game_Optio    Stack[0x4]:4   param_1                   XREF[1]:     0042226b(R)
//                               ?get_game_options@RGE_Base_Game@@QAEXPAURGE_Game_Options@1@@Z XREF[1]:     send_game_options:00528f78(c)
//                               RGE_Base_Game::get_game_options
//                              basegame.cpp:5032 (6)
//         00422260     PUSH       EBX
//         00422261     PUSH       EBP
//         00422262     PUSH       ESI
//         00422263     PUSH       EDI
//         00422264     MOV        EBX,this
//                              basegame.cpp:5035 (9)
//         00422266     CALL       RGE_Base_Game::version                           float version(RGE_Base_Game * this)
//         0042226b     MOV        EBP,dword ptr [ESP + param_1]
//                              basegame.cpp:5036 (10)
//         0042226f     MOV        this,EBX
//         00422271     FSTP       float ptr [EBP]
//         00422274     CALL       RGE_Base_Game::scenarioGame                      int scenarioGame(RGE_Base_Game * this)
//                              basegame.cpp:5037 (44)
//         00422279     MOV        this,EBX
//         0042227b     MOV        byte ptr [EBP + 0x4],AL
//         0042227e     CALL       RGE_Base_Game::scenarioName                      char * scenarioName(RGE_Base_Game * this)
//         00422283     MOV        EDI,EAX
//         00422285     OR         this,0xffffffff
//         00422288     XOR        EAX,EAX
//         0042228a     LEA        EDX,[EBP + 0x5]
//         0042228d     SCASB.RE   ES:EDI
//         0042228f     NOT        this
//         00422291     SUB        EDI,this
//         00422293     MOV        EAX,this
//         00422295     MOV        ESI,EDI
//         00422297     MOV        EDI,EDX
//         00422299     SHR        this,0x2
//         0042229c     MOVSD.REP  ES:EDI,ESI
//         0042229e     MOV        this,EAX
//         004222a0     AND        this,0x3
//         004222a3     MOVSB.REP  ES:EDI,ESI
//                              basegame.cpp:5038 (7)
//         004222a5     MOV        this,EBX
//         004222a7     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
//                              basegame.cpp:5039 (13)
//         004222ac     MOV        this,EBX
//         004222ae     MOV        byte ptr [EBP + 0x85],AL
//         004222b4     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//                              basegame.cpp:5040 (13)
//         004222b9     MOV        this,EBX
//         004222bb     MOV        byte ptr [EBP + 0x86],AL
//         004222c1     CALL       RGE_Base_Game::mapXSize                          int mapXSize(RGE_Base_Game * this)
//                              basegame.cpp:5041 (13)
//         004222c6     MOV        this,EBX
//         004222c8     MOV        byte ptr [EBP + 0x87],AL
//         004222ce     CALL       RGE_Base_Game::mapYSize                          int mapYSize(RGE_Base_Game * this)
//                              basegame.cpp:5042 (13)
//         004222d3     MOV        this,EBX
//         004222d5     MOV        byte ptr [EBP + 0x88],AL
//         004222db     CALL       RGE_Base_Game::mapZSize                          int mapZSize(RGE_Base_Game * this)
//                              basegame.cpp:5043 (13)
//         004222e0     MOV        this,EBX
//         004222e2     MOV        byte ptr [EBP + 0x89],AL
//         004222e8     CALL       RGE_Base_Game::allowCheatCodes                   int allowCheatCodes(RGE_Base_Game * this)
//                              basegame.cpp:5044 (13)
//         004222ed     MOV        this,EBX
//         004222ef     MOV        byte ptr [EBP + 0x8a],AL
//         004222f5     CALL       RGE_Base_Game::cheatNotification                 int cheatNotification(RGE_Base_Game * this)
//                              basegame.cpp:5045 (13)
//         004222fa     MOV        this,EBX
//         004222fc     MOV        byte ptr [EBP + 0x8c],AL
//         00422302     CALL       RGE_Base_Game::fullVisibility                    int fullVisibility(RGE_Base_Game * this)
//                              basegame.cpp:5046 (13)
//         00422307     MOV        this,EBX
//         00422309     MOV        byte ptr [EBP + 0x8d],AL
//         0042230f     CALL       RGE_Base_Game::fogOfWar                          int fogOfWar(RGE_Base_Game * this)
//                              basegame.cpp:5047 (13)
//         00422314     MOV        this,EBX
//         00422316     MOV        byte ptr [EBP + 0x8e],AL
//         0042231c     CALL       RGE_Base_Game::coloredChat                       int coloredChat(RGE_Base_Game * this)
//                              basegame.cpp:5048 (13)
//         00422321     MOV        this,EBX
//         00422323     MOV        byte ptr [EBP + 0x8f],AL
//         00422329     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
//                              basegame.cpp:5049 (13)
//         0042232e     MOV        this,EBX
//         00422330     MOV        byte ptr [EBP + 0x90],AL
//         00422336     CALL       RGE_Base_Game::gameDeveloperMode                 int gameDeveloperMode(RGE_Base_Game * this)
//                              basegame.cpp:5050 (13)
//         0042233b     MOV        this,EBX
//         0042233d     MOV        byte ptr [EBP + 0x91],AL
//         00422343     CALL       RGE_Base_Game::difficulty                        int difficulty(RGE_Base_Game * this)
//                              basegame.cpp:5051 (19)
//         00422348     MOV        this,EBX
//         0042234a     MOV        byte ptr [EBP + 0x9b],AL
//         00422350     CALL       RGE_Base_Game::mpPathFinding                     uchar mpPathFinding(RGE_Base_Game * this)
//         00422355     MOV        byte ptr [EBP + 0x8b],AL
//                              basegame.cpp:5053 (2)
//         0042235b     XOR        ESI,ESI
//                               LAB_0042235d                                                 XREF[1]:     0042237f(j)
//                              basegame.cpp:5055 (8)
//         0042235d     PUSH       ESI
//         0042235e     MOV        this,EBX
//         00422360     CALL       RGE_Base_Game::playerCDAndVersion                uchar playerCDAndVersion(RGE_Base_Game * this
//                              basegame.cpp:5056 (28)
//         00422365     PUSH       ESI
//         00422366     MOV        this,EBX
//         00422368     MOV        byte ptr [ESI + EBP*0x1 + 0x92],AL
//         0042236f     CALL       RGE_Base_Game::playerTeam                        int playerTeam(RGE_Base_Game * this, int para
//         00422374     MOV        byte ptr [ESI + EBP*0x1 + 0x9c],AL
//         0042237b     INC        ESI
//         0042237c     CMP        ESI,0x9
//         0042237f     JL         LAB_0042235d
//                              basegame.cpp:5059 (7)
//         00422381     POP        EDI
//         00422382     POP        ESI
//         00422383     POP        EBP
//         00422384     POP        EBX
//         00422385     RET        0x4
//         00422388     ??         90h
//         00422389     NOP
//         0042238a     NOP
//         0042238b     NOP
//         0042238c     NOP
//         0042238d     NOP
//         0042238e     NOP
//         0042238f     NOP
    return;
}

float RGE_Base_Game::version() {
    /* TODO: Stub */
//                              float __thiscall version(RGE_Base_Game * this)
//              float             ST0:10         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?version@RGE_Base_Game@@QBEMXZ                               XREF[1]:     get_game_options:00422266(c)
//                               RGE_Base_Game::version
//                              basegame.cpp:5064 (6)
//         00422390     FLD        float ptr [ECX + this->rge_game_options.versio
//                              basegame.cpp:5066 (1)
//         00422396     RET
//         00422397     ??         90h
//         00422398     NOP
//         00422399     NOP
//         0042239a     NOP
//         0042239b     NOP
//         0042239c     NOP
//         0042239d     NOP
//         0042239e     NOP
//         0042239f     NOP
    return 0;
}

int RGE_Base_Game::scenarioGame() {
    /* TODO: Stub */
//                              int __thiscall scenarioGame(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?scenarioGame@RGE_Base_Game@@QBEHXZ                          XREF[33]:    init_vars:004a117a(c),
//                               RGE_Base_Game::scenarioGame                                               action:004a1857(c),
//                                                                                                         startGame:004a20db(c),
//                                                                                                         startGame:004a21bf(c),
//                                                                                                         startGame:004a2209(c),
//                                                                                                         startGame:004a2322(c),
//                                                                                                         startGame:004a237b(c),
//                                                                                                         startGame:004a2467(c),
//                                                                                                         cancelScreen:004a2bd9(c),
//                                                                                                         updateSummary:004a41a4(c),
//                                                                                                         updateSummary:004a4212(c),
//                                                                                                         updateSummary:004a4561(c),
//                                                                                                         updateSummary:004a4631(c),
//                                                                                                         updateSummary:004a4878(c),
//                                                                                                         updateSummary:004a4ef1(c),
//                                                                                                         setupSinglePlayerPlayers:004a521f(
//                                                                                                         fillPlayerColors:004a54e5(c),
//                                                                                                         TRIBE_Screen_Wait:004a57c3(c),
//                                                                                                         create_game:00527044(c),
//                                                                                                         create_game:005272a9(c), [more]
//                              basegame.cpp:5071 (8)
//         004223a0     XOR        EAX,EAX
//         004223a2     MOV        AL,byte ptr [ECX + this+0x8fc]
//                              basegame.cpp:5073 (1)
//         004223a8     RET
//         004223a9     ??         90h
//         004223aa     NOP
//         004223ab     NOP
//         004223ac     NOP
//         004223ad     NOP
//         004223ae     NOP
//         004223af     NOP
    return 0;
}

int RGE_Base_Game::randomGame() {
    /* TODO: Stub */
//                              int __thiscall randomGame(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?randomGame@RGE_Base_Game@@QBEHXZ                            XREF[21]:    init_vars:004a0eed(c),
//                               RGE_Base_Game::randomGame                                                 updateSummary:004a441d(c),
//                                                                                                         updateSummary:004a4504(c),
//                                                                                                         updateSummary:004a46ee(c),
//                                                                                                         updateSummary:004a49be(c),
//                                                                                                         TRIBE_Screen_Wait:004a5880(c),
//                                                                                                         TRIBE_Screen_Wait:004a5a93(c),
//                                                                                                         fillScenarios:004b60c2(c),
//                                                                                                         fillScenarios:004b6116(c),
//                                                                                                         sendSettings:004b65bb(c),
//                                                                                                         random_start:005143cb(c),
//                                                                                                         stop_video:00523ce5(c),
//                                                                                                         restart_game:00524491(c),
//                                                                                                         restart_game:005244bc(c),
//                                                                                                         create_game:00527557(c),
//                                                                                                         new_game:0052efb2(c),
//                                                                                                         new_game:0052efe3(c),
//                                                                                                         new_game:0052f16e(c),
//                                                                                                         new_game:0052f79b(c),
//                                                                                                         new_game:0052fb32(c), [more]
//                              basegame.cpp:5078 (13)
//         004223b0     MOV        DL,byte ptr [ECX + this+0x8fc]
//         004223b6     XOR        EAX,EAX
//         004223b8     TEST       DL,DL
//         004223ba     SETZ       AL
//                              basegame.cpp:5080 (1)
//         004223bd     RET
//         004223be     ??         90h
//         004223bf     NOP
    return 0;
}

int RGE_Base_Game::campaignGame() {
    /* TODO: Stub */
//                              int __thiscall campaignGame(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?campaignGame@RGE_Base_Game@@QBEHXZ                          XREF[17]:    draw:0051b430(c),
//                               RGE_Base_Game::campaignGame                                               stop_video:00523cf0(c),
//                                                                                                         restart_game:0052449d(c),
//                                                                                                         restart_game:005244c7(c),
//                                                                                                         create_game:0052702c(c),
//                                                                                                         create_game:00527299(c),
//                                                                                                         create_game:005274d9(c),
//                                                                                                         create_game:00527532(c),
//                                                                                                         create_game:0052754c(c),
//                                                                                                         create_game:00527579(c),
//                                                                                                         create_game:005275e0(c),
//                                                                                                         new_game:0052efa3(c),
//                                                                                                         new_game:0052efd4(c),
//                                                                                                         new_game:0052f78c(c),
//                                                                                                         new_game:0052f916(c),
//                                                                                                         new_game:0052fb1f(c),
//                                                                                                         new_game:005429ec(c)
//                              basegame.cpp:5085 (6)
//         004223c0     MOV        EAX,dword ptr [ECX + this->campaignGameValue]
//                              basegame.cpp:5087 (1)
//         004223c6     RET
//         004223c7     ??         90h
//         004223c8     NOP
//         004223c9     NOP
//         004223ca     NOP
//         004223cb     NOP
//         004223cc     NOP
//         004223cd     NOP
//         004223ce     NOP
//         004223cf     NOP
    return 0;
}

int RGE_Base_Game::savedGame() {
    /* TODO: Stub */
//                              int __thiscall savedGame(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?savedGame@RGE_Base_Game@@QBEHXZ                             XREF[1]:     restart_game:00524418(c)
//                               RGE_Base_Game::savedGame
//                              basegame.cpp:5092 (6)
//         004223d0     MOV        EAX,dword ptr [ECX + this->savedGameValue]
//                              basegame.cpp:5094 (1)
//         004223d6     RET
//         004223d7     ??         90h
//         004223d8     NOP
//         004223d9     NOP
//         004223da     NOP
//         004223db     NOP
//         004223dc     NOP
//         004223dd     NOP
//         004223de     NOP
//         004223df     NOP
    return 0;
}

char* RGE_Base_Game::scenarioName() {
    /* TODO: Stub */
//                              char * __thiscall scenarioName(RGE_Base_Game * this)
//              char *            EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?scenarioName@RGE_Base_Game@@QAEPADXZ                        XREF[22]:    get_game_options:0042227e(c),
//                               RGE_Base_Game::scenarioName                                               action:004a1873(c),
//                                                                                                         action:004a18ac(c),
//                                                                                                         action:004a18be(c),
//                                                                                                         updateSummary:004a41c3(c),
//                                                                                                         updateSummary:004a4247(c),
//                                                                                                         updateSummary:004a4280(c),
//                                                                                                         updateSummary:004a4292(c),
//                                                                                                         updateSummary:004a4522(c),
//                                                                                                         updateSummary:004a457d(c),
//                                                                                                         updateSummary:004a45bc(c),
//                                                                                                         updateSummary:004a45d1(c),
//                                                                                                         updateSummary:004a4640(c),
//                                                                                                         TRIBE_Screen_Wait:004a57d2(c),
//                                                                                                         getSettings:004b4784(c),
//                                                                                                         fillScenarios:004b5ebe(c),
//                                                                                                         getSettings:004b6283(c),
//                                                                                                         create_game:00527053(c),
//                                                                                                         create_game:00527074(c),
//                                                                                                         create_game:005270ae(c), [more]
//                              basegame.cpp:5099 (6)
//         004223e0     LEA        EAX,[ECX + this+0x8fd]
//                              basegame.cpp:5101 (1)
//         004223e6     RET
//         004223e7     ??         90h
//         004223e8     NOP
//         004223e9     NOP
//         004223ea     NOP
//         004223eb     NOP
//         004223ec     NOP
//         004223ed     NOP
//         004223ee     NOP
//         004223ef     NOP
    return 0;
}

int RGE_Base_Game::singlePlayerGame() {
    /* TODO: Stub */
//                              int __thiscall singlePlayerGame(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?singlePlayerGame@RGE_Base_Game@@QBEHXZ                      XREF[66]:    handle_activate:004218cb(c),
//                               RGE_Base_Game::singlePlayerGame                                           TribeAchievementsScreen:0048de80(c
//                                                                                                         TRIBE_Screen_Game:0049470e(c),
//                                                                                                         action:0049855a(c),
//                                                                                                         action:00498701(c),
//                                                                                                         TribeMPSetupScreen:004a024b(c),
//                                                                                                         TribeMPSetupScreen:004a076c(c),
//                                                                                                         TribeMPSetupScreen:004a0961(c),
//                                                                                                         TribeMPSetupScreen:004a09db(c),
//                                                                                                         TribeMPSetupScreen:004a0d12(c),
//                                                                                                         startGame:004a24ab(c),
//                                                                                                         fillPlayers:004a3bb8(c),
//                                                                                                         fillPlayers:004a3cea(c),
//                                                                                                         fillPlayers:004a3fd3(c),
//                                                                                                         updateSummary:004a4366(c),
//                                                                                                         updateSummary:004a44ee(c),
//                                                                                                         addObjectMemory:004da72c(c),
//                                                                                                         quit_game:005241b6(c),
//                                                                                                         quit_game:00524218(c),
//                                                                                                         start_game:00525d2b(c), [more]
//                              basegame.cpp:5106 (8)
//         004223f0     XOR        EAX,EAX
//         004223f2     MOV        AL,byte ptr [ECX + this+0x97d]
//                              basegame.cpp:5108 (1)
//         004223f8     RET
//         004223f9     ??         90h
//         004223fa     NOP
//         004223fb     NOP
//         004223fc     NOP
//         004223fd     NOP
//         004223fe     NOP
//         004223ff     NOP
    return 0;
}

int RGE_Base_Game::multiplayerGame() {
    /* TODO: Stub */
//                              int __thiscall multiplayerGame(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?multiplayerGame@RGE_Base_Game@@QBEHXZ                       XREF[90]:    TRIBE_Screen_Game:00494fe2(c),
//                               RGE_Base_Game::multiplayerGame                                            reset_score_display:0049b29c(c),
//                                                                                                         reset_score_display:0049b3fc(c),
//                                                                                                         reset_score_display:0049b44f(c),
//                                                                                                         TribeMPSetupScreen:004a0134(c),
//                                                                                                         startGame:004a207e(c),
//                                                                                                         startGame:004a21fa(c),
//                                                                                                         startGame:004a226d(c),
//                                                                                                         startGame:004a248c(c),
//                                                                                                         startGame:004a24e1(c),
//                                                                                                         startGame:004a25a7(c),
//                                                                                                         startGame:004a269c(c),
//                                                                                                         TRIBE_Screen_Wait:004a5e32(c),
//                                                                                                         TRIBE_Screen_Wait:004a5ed2(c),
//                                                                                                         TRIBE_Screen_Status_Message:004b72
//                                                                                                         create_game:0052712b(c),
//                                                                                                         create_game:005274ff(c),
//                                                                                                         create_game:005276bc(c),
//                                                                                                         create_game:005277b3(c),
//                                                                                                         popLimit:00529483(c), [more]
//                              basegame.cpp:5113 (8)
//         00422400     XOR        EAX,EAX
//         00422402     MOV        AL,byte ptr [ECX + this+0x97e]
//                              basegame.cpp:5115 (1)
//         00422408     RET
//         00422409     ??         90h
//         0042240a     NOP
//         0042240b     NOP
//         0042240c     NOP
//         0042240d     NOP
//         0042240e     NOP
//         0042240f     NOP
    return 0;
}

int RGE_Base_Game::mapXSize() {
    /* TODO: Stub */
//                              int __thiscall mapXSize(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?mapXSize@RGE_Base_Game@@QBEHXZ                              XREF[2]:     get_game_options:004222c1(c),
//                               RGE_Base_Game::mapXSize                                                   create_game:0052710d(c)
//                              basegame.cpp:5120 (8)
//         00422410     XOR        EAX,EAX
//         00422412     MOV        AL,byte ptr [ECX + this+0x97f]
//                              basegame.cpp:5122 (1)
//         00422418     RET
//         00422419     ??         90h
//         0042241a     NOP
//         0042241b     NOP
//         0042241c     NOP
//         0042241d     NOP
//         0042241e     NOP
//         0042241f     NOP
    return 0;
}

int RGE_Base_Game::mapYSize() {
    /* TODO: Stub */
//                              int __thiscall mapYSize(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?mapYSize@RGE_Base_Game@@QBEHXZ                              XREF[2]:     get_game_options:004222ce(c),
//                               RGE_Base_Game::mapYSize                                                   create_game:0052711c(c)
//                              basegame.cpp:5127 (8)
//         00422420     XOR        EAX,EAX
//         00422422     MOV        AL,byte ptr [ECX + this+0x980]
//                              basegame.cpp:5129 (1)
//         00422428     RET
//         00422429     ??         90h
//         0042242a     NOP
//         0042242b     NOP
//         0042242c     NOP
//         0042242d     NOP
//         0042242e     NOP
//         0042242f     NOP
    return 0;
}

int RGE_Base_Game::mapZSize() {
    /* TODO: Stub */
//                              int __thiscall mapZSize(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?mapZSize@RGE_Base_Game@@QBEHXZ                              XREF[1]:     get_game_options:004222db(c)
//                               RGE_Base_Game::mapZSize
//                              basegame.cpp:5134 (8)
//         00422430     XOR        EAX,EAX
//         00422432     MOV        AL,byte ptr [ECX + this+0x981]
//                              basegame.cpp:5136 (1)
//         00422438     RET
//         00422439     ??         90h
//         0042243a     NOP
//         0042243b     NOP
//         0042243c     NOP
//         0042243d     NOP
//         0042243e     NOP
//         0042243f     NOP
    return 0;
}

int RGE_Base_Game::allowCheatCodes() {
    /* TODO: Stub */
//                              int __thiscall allowCheatCodes(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?allowCheatCodes@RGE_Base_Game@@QBEHXZ                       XREF[13]:    get_game_options:004222e8(c),
//                               RGE_Base_Game::allowCheatCodes                                            command_add_attribute:0049bc75(c),
//                                                                                                         command_fog_of_war:0049c239(c),
//                                                                                                         command_player:0049ca19(c),
//                                                                                                         command_quick_build:0049ca89(c),
//                                                                                                         command_visibility:0049d1b9(c),
//                                                                                                         updateSummary:004a4d70(c),
//                                                                                                         TRIBE_Screen_Wait:004a5e45(c),
//                                                                                                         getSettings:004b633e(c),
//                                                                                                         processCheatCode:00527afe(c),
//                                                                                                         new_game:0052f5df(c),
//                                                                                                         cheat:00530aec(c),
//                                                                                                         send_zone_score_info:0053157a(c)
//                              basegame.cpp:5141 (8)
//         00422440     XOR        EAX,EAX
//         00422442     MOV        AL,byte ptr [ECX + this+0x982]
//                              basegame.cpp:5143 (1)
//         00422448     RET
//         00422449     ??         90h
//         0042244a     NOP
//         0042244b     NOP
//         0042244c     NOP
//         0042244d     NOP
//         0042244e     NOP
//         0042244f     NOP
    return 0;
}

int RGE_Base_Game::cheatNotification() {
    /* TODO: Stub */
//                              int __thiscall cheatNotification(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?cheatNotification@RGE_Base_Game@@QBEHXZ                     XREF[1]:     get_game_options:004222f5(c)
//                               RGE_Base_Game::cheatNotification
//                              basegame.cpp:5148 (8)
//         00422450     XOR        EAX,EAX
//         00422452     MOV        AL,byte ptr [ECX + this+0x984]
//                              basegame.cpp:5150 (1)
//         00422458     RET
//         00422459     ??         90h
//         0042245a     NOP
//         0042245b     NOP
//         0042245c     NOP
//         0042245d     NOP
//         0042245e     NOP
//         0042245f     NOP
    return 0;
}

int RGE_Base_Game::fullVisibility() {
    /* TODO: Stub */
//                              int __thiscall fullVisibility(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?fullVisibility@RGE_Base_Game@@QBEHXZ                        XREF[10]:    get_game_options:00422302(c),
//                               RGE_Base_Game::fullVisibility                                             updateSummary:004a4c57(c),
//                                                                                                         TRIBE_Screen_Wait:004a5d2c(c),
//                                                                                                         getSettings:004b635e(c),
//                                                                                                         update:00512448(c),
//                                                                                                         create_game:00527756(c),
//                                                                                                         let_game_begin:00528a4e(c),
//                                                                                                         new_game:0052f4bd(c),
//                                                                                                         new_game:00530151(c),
//                                                                                                         send_zone_score_info:0053165a(c)
//                              basegame.cpp:5155 (8)
//         00422460     XOR        EAX,EAX
//         00422462     MOV        AL,byte ptr [ECX + this+0x985]
//                              basegame.cpp:5157 (1)
//         00422468     RET
//         00422469     ??         90h
//         0042246a     NOP
//         0042246b     NOP
//         0042246c     NOP
//         0042246d     NOP
//         0042246e     NOP
//         0042246f     NOP
    return 0;
}

int RGE_Base_Game::fogOfWar() {
    /* TODO: Stub */
//                              int __thiscall fogOfWar(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?fogOfWar@RGE_Base_Game@@QBEHXZ                              XREF[2]:     get_game_options:0042230f(c),
//                               RGE_Base_Game::fogOfWar                                                   create_game:005277a4(c)
//                              basegame.cpp:5162 (8)
//         00422470     XOR        EAX,EAX
//         00422472     MOV        AL,byte ptr [ECX + this+0x986]
//                              basegame.cpp:5164 (1)
//         00422478     RET
//         00422479     ??         90h
//         0042247a     NOP
//         0042247b     NOP
//         0042247c     NOP
//         0042247d     NOP
//         0042247e     NOP
//         0042247f     NOP
    return 0;
}

int RGE_Base_Game::coloredChat() {
    /* TODO: Stub */
//                              int __thiscall coloredChat(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?coloredChat@RGE_Base_Game@@QBEHXZ                           XREF[1]:     get_game_options:0042231c(c)
//                               RGE_Base_Game::coloredChat
//                              basegame.cpp:5169 (8)
//         00422480     XOR        EAX,EAX
//         00422482     MOV        AL,byte ptr [ECX + this+0x987]
//                              basegame.cpp:5171 (1)
//         00422488     RET
//         00422489     ??         90h
//         0042248a     NOP
//         0042248b     NOP
//         0042248c     NOP
//         0042248d     NOP
//         0042248e     NOP
//         0042248f     NOP
    return 0;
}

int RGE_Base_Game::gameDeveloperMode() {
    /* TODO: Stub */
//                              int __thiscall gameDeveloperMode(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?gameDeveloperMode@RGE_Base_Game@@QBEHXZ                     XREF[19]:    get_game_options:00422336(c),
//                               RGE_Base_Game::gameDeveloperMode                                          key_down_action:004975ab(c),
//                                                                                                         key_down_action:004977c9(c),
//                                                                                                         key_down_action:004977fe(c),
//                                                                                                         key_down_action:0049782d(c),
//                                                                                                         key_down_action:0049785c(c),
//                                                                                                         key_down_action:00497883(c),
//                                                                                                         key_down_action:004978b2(c),
//                                                                                                         key_down_action:004978e1(c),
//                                                                                                         key_down_action:00497a27(c),
//                                                                                                         key_down_action:00497c65(c),
//                                                                                                         key_down_action:00497cc7(c),
//                                                                                                         key_down_action:00497f0e(c),
//                                                                                                         key_down_action:00497f27(c),
//                                                                                                         key_down_action:00497f40(c),
//                                                                                                         key_down_action:00497f59(c),
//                                                                                                         command_game_speed:0049c3cc(c),
//                                                                                                         key_down_action:0049ed3c(c),
//                                                                                                         key_down_action:004ab99a(c)
//                              basegame.cpp:5176 (8)
//         00422490     XOR        EAX,EAX
//         00422492     MOV        AL,byte ptr [ECX + this+0x989]
//                              basegame.cpp:5178 (1)
//         00422498     RET
//         00422499     ??         90h
//         0042249a     NOP
//         0042249b     NOP
//         0042249c     NOP
//         0042249d     NOP
//         0042249e     NOP
//         0042249f     NOP
    return 0;
}

int RGE_Base_Game::playerHasCD(int param_1) {
    /* TODO: Stub */
//                              int __thiscall playerHasCD(RGE_Base_Game * this, int param_1)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004224a0(R)
//                               ?playerHasCD@RGE_Base_Game@@QAEHH@Z                          XREF[5]:     check_for_cd:0041fce1(c),
//                               RGE_Base_Game::playerHasCD                                                handle_user_command:004a2ff1(c),
//                                                                                                         handle_user_command:004a300a(c),
//                                                                                                         handle_user_command:004a311e(c),
//                                                                                                         fillPlayers:004a39e2(c)
//                              basegame.cpp:5184 (14)
//         004224a0     MOV        EAX,dword ptr [ESP + param_1]
//         004224a4     MOV        AL,byte ptr [ECX + EAX*0x1 + this+0x98a]
//         004224ab     AND        EAX,0x1
//                              basegame.cpp:5186 (3)
//         004224ae     RET        0x4
//         004224b1     ??         90h
//         004224b2     NOP
//         004224b3     NOP
//         004224b4     NOP
//         004224b5     NOP
//         004224b6     NOP
//         004224b7     NOP
//         004224b8     NOP
//         004224b9     NOP
//         004224ba     NOP
//         004224bb     NOP
//         004224bc     NOP
//         004224bd     NOP
//         004224be     NOP
//         004224bf     NOP
    return 0;
}

uchar RGE_Base_Game::playerVersion(int param_1) {
    /* TODO: Stub */
//                              uchar __thiscall playerVersion(RGE_Base_Game * this, int param_1)
//              uchar             AL:1           <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004224c0(R)
//                               ?playerVersion@RGE_Base_Game@@QAEEH@Z                        XREF[5]:     playerVersionString:004224e5(c),
//                               RGE_Base_Game::playerVersion                                              action:004a17af(c),
//                                                                                                         startGame:004a2157(c),
//                                                                                                         handle_user_command:004a318b(c),
//                                                                                                         fillPlayers:004a3a0c(c)
//                              basegame.cpp:5192 (15)
//         004224c0     MOV        EDX,dword ptr [ESP + param_1]
//         004224c4     XOR        EAX,EAX
//         004224c6     MOV        AL,byte ptr [ECX + EDX*0x1 + this+0x98a]
//         004224cd     SHR        EAX,0x1
//                              basegame.cpp:5194 (3)
//         004224cf     RET        0x4
//         004224d2     ??         90h
//         004224d3     NOP
//         004224d4     NOP
//         004224d5     NOP
//         004224d6     NOP
//         004224d7     NOP
//         004224d8     NOP
//         004224d9     NOP
//         004224da     NOP
//         004224db     NOP
//         004224dc     NOP
//         004224dd     NOP
//         004224de     NOP
//         004224df     NOP
    return 0;
}

char* RGE_Base_Game::playerVersionString(int param_1) {
    /* TODO: Stub */
//                              char * __thiscall playerVersionString(RGE_Base_Game * this, int para
//              char *            EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[3]:     004224e0(R), 004224ea(W), 004224ee(R)
//                               ?playerVersionString@RGE_Base_Game@@QAEPADH@Z                XREF[3]:     fillPlayers:004a3a2c(c),
//                               RGE_Base_Game::playerVersionString                                        fillPlayers:004a3a6f(c),
//                                                                                                         fillPlayers:004a3aaf(c)
//                              basegame.cpp:5200 (14)
//         004224e0     MOV        EAX,dword ptr [ESP + param_1]
//         004224e4     PUSH       EAX
//         004224e5     CALL       RGE_Base_Game::playerVersion                     uchar playerVersion(RGE_Base_Game * this, int
//         004224ea     MOV        byte ptr [ESP + param_1],AL
//                              basegame.cpp:5203 (25)
//         004224ee     MOV        EAX,dword ptr [ESP + param_1]
//         004224f2     AND        EAX,0xff
//         004224f7     CMP        EAX,0x16
//         004224fa     JA         switchD_00422500::default
//                               switchD_00422500::switchD
//         00422500     JMP        dword ptr [EAX*0x4 + switchD_00422500::switchd   = 00422507
//                               switchD_00422500::caseD_0                                    XREF[2]:     00422500(j), 004225c8(*)
//                              basegame.cpp:5205 (5)
//         00422507     MOV        EAX,s_                                           = ""
//                              basegame.cpp:5230 (3)
//         0042250c     RET        0x4
//                               switchD_00422500::caseD_1                                    XREF[2]:     00422500(j), 004225cc(*)
//                              basegame.cpp:5206 (5)
//         0042250f     MOV        EAX,s_1.0                                        = "1.0"
//                              basegame.cpp:5230 (3)
//         00422514     RET        0x4
//                               switchD_00422500::caseD_2                                    XREF[2]:     00422500(j), 004225d0(*)
//                              basegame.cpp:5207 (5)
//         00422517     MOV        EAX,s_1.0a                                       = "1.0a"
//                              basegame.cpp:5230 (3)
//         0042251c     RET        0x4
//                               switchD_00422500::caseD_3                                    XREF[2]:     00422500(j), 004225d4(*)
//                              basegame.cpp:5208 (5)
//         0042251f     MOV        EAX,s_1.0b                                       = "1.0b"
//                              basegame.cpp:5230 (3)
//         00422524     RET        0x4
//                               switchD_00422500::caseD_4                                    XREF[2]:     00422500(j), 004225d8(*)
//                              basegame.cpp:5209 (5)
//         00422527     MOV        EAX,s_1.0c                                       = "1.0c"
//                              basegame.cpp:5230 (3)
//         0042252c     RET        0x4
//                               switchD_00422500::caseD_5                                    XREF[2]:     00422500(j), 004225dc(*)
//                              basegame.cpp:5210 (5)
//         0042252f     MOV        EAX,s_1.0d                                       = "1.0d"
//                              basegame.cpp:5230 (3)
//         00422534     RET        0x4
//                               switchD_00422500::caseD_6                                    XREF[2]:     00422500(j), 004225e0(*)
//                              basegame.cpp:5211 (5)
//         00422537     MOV        EAX,s_1.0e                                       = "1.0e"
//                              basegame.cpp:5230 (3)
//         0042253c     RET        0x4
//                               switchD_00422500::caseD_7                                    XREF[2]:     00422500(j), 004225e4(*)
//                              basegame.cpp:5212 (5)
//         0042253f     MOV        EAX,s_1.1                                        = "1.1"
//                              basegame.cpp:5230 (3)
//         00422544     RET        0x4
//                               switchD_00422500::caseD_8                                    XREF[2]:     00422500(j), 004225e8(*)
//                              basegame.cpp:5213 (5)
//         00422547     MOV        EAX,s_1.1a                                       = "1.1a"
//                              basegame.cpp:5230 (3)
//         0042254c     RET        0x4
//                               switchD_00422500::caseD_9                                    XREF[2]:     00422500(j), 004225ec(*)
//                              basegame.cpp:5214 (5)
//         0042254f     MOV        EAX,s_1.1b                                       = "1.1b"
//                              basegame.cpp:5230 (3)
//         00422554     RET        0x4
//                               switchD_00422500::caseD_a                                    XREF[2]:     00422500(j), 004225f0(*)
//                              basegame.cpp:5215 (5)
//         00422557     MOV        EAX,s_1.1c                                       = "1.1c"
//                              basegame.cpp:5230 (3)
//         0042255c     RET        0x4
//                               switchD_00422500::caseD_b                                    XREF[2]:     00422500(j), 004225f4(*)
//                              basegame.cpp:5216 (5)
//         0042255f     MOV        EAX,s_1.2                                        = "1.2"
//                              basegame.cpp:5230 (3)
//         00422564     RET        0x4
//                               switchD_00422500::caseD_c                                    XREF[2]:     00422500(j), 004225f8(*)
//                              basegame.cpp:5217 (5)
//         00422567     MOV        EAX,s_1.2a                                       = "1.2a"
//                              basegame.cpp:5230 (3)
//         0042256c     RET        0x4
//                               switchD_00422500::caseD_d                                    XREF[2]:     00422500(j), 004225fc(*)
//                              basegame.cpp:5218 (5)
//         0042256f     MOV        EAX,s_1.2b                                       = "1.2b"
//                              basegame.cpp:5230 (3)
//         00422574     RET        0x4
//                               switchD_00422500::caseD_e                                    XREF[2]:     00422500(j), 00422600(*)
//                              basegame.cpp:5219 (5)
//         00422577     MOV        EAX,s_1.2c                                       = "1.2c"
//                              basegame.cpp:5230 (3)
//         0042257c     RET        0x4
//                               switchD_00422500::caseD_f                                    XREF[2]:     00422500(j), 00422604(*)
//                              basegame.cpp:5220 (5)
//         0042257f     MOV        EAX,s_1.3                                        = "1.3"
//                              basegame.cpp:5230 (3)
//         00422584     RET        0x4
//                               switchD_00422500::caseD_10                                   XREF[2]:     00422500(j), 00422608(*)
//                              basegame.cpp:5221 (5)
//         00422587     MOV        EAX,s_1.3a                                       = "1.3a"
//                              basegame.cpp:5230 (3)
//         0042258c     RET        0x4
//                               switchD_00422500::caseD_11                                   XREF[2]:     00422500(j), 0042260c(*)
//                              basegame.cpp:5222 (5)
//         0042258f     MOV        EAX,s_1.3b                                       = "1.3b"
//                              basegame.cpp:5230 (3)
//         00422594     RET        0x4
//                               switchD_00422500::caseD_12                                   XREF[2]:     00422500(j), 00422610(*)
//                              basegame.cpp:5223 (5)
//         00422597     MOV        EAX,s_1.3c                                       = "1.3c"
//                              basegame.cpp:5230 (3)
//         0042259c     RET        0x4
//                               switchD_00422500::caseD_13                                   XREF[2]:     00422500(j), 00422614(*)
//                              basegame.cpp:5224 (5)
//         0042259f     MOV        EAX,s_1.4                                        = "1.4"
//                              basegame.cpp:5230 (3)
//         004225a4     RET        0x4
//                               switchD_00422500::caseD_14                                   XREF[2]:     00422500(j), 00422618(*)
//                              basegame.cpp:5225 (5)
//         004225a7     MOV        EAX,s_1.4a                                       = "1.4a"
//                              basegame.cpp:5230 (3)
//         004225ac     RET        0x4
//                               switchD_00422500::caseD_15                                   XREF[2]:     00422500(j), 0042261c(*)
//                              basegame.cpp:5226 (5)
//         004225af     MOV        EAX,s_1.4b                                       = "1.4b"
//                              basegame.cpp:5230 (3)
//         004225b4     RET        0x4
//                               switchD_00422500::caseD_16                                   XREF[2]:     00422500(j), 00422620(*)
//                              basegame.cpp:5227 (5)
//         004225b7     MOV        EAX,s_1.4c                                       = "1.4c"
//                              basegame.cpp:5230 (3)
//         004225bc     RET        0x4
//                               switchD_00422500::default                                    XREF[1]:     004224fa(j)
//                              basegame.cpp:5228 (5)
//         004225bf     MOV        EAX,s_1.X                                        = "1.X"
//                              basegame.cpp:5230 (96)
//         004225c4     RET        0x4
//         004225c7     ??         90h
//                              Symbol Ref: No symbol: NONAME
//                               switchD_00422500::switchdataD_004225c8                       XREF[1]:     playerVersionString:00422500(*)
//         004225c8     addr       switchD_00422500::caseD_0
//         004225cc     addr       switchD_00422500::caseD_1
//         004225d0     addr       switchD_00422500::caseD_2
//         004225d4     addr       switchD_00422500::caseD_3
//         004225d8     addr       switchD_00422500::caseD_4
//         004225dc     addr       switchD_00422500::caseD_5
//         004225e0     addr       switchD_00422500::caseD_6
//         004225e4     addr       switchD_00422500::caseD_7
//         004225e8     addr       switchD_00422500::caseD_8
//         004225ec     addr       switchD_00422500::caseD_9
//         004225f0     addr       switchD_00422500::caseD_a
//         004225f4     addr       switchD_00422500::caseD_b
//         004225f8     addr       switchD_00422500::caseD_c
//         004225fc     addr       switchD_00422500::caseD_d
//         00422600     addr       switchD_00422500::caseD_e
//         00422604     addr       switchD_00422500::caseD_f
//         00422608     addr       switchD_00422500::caseD_10
//         0042260c     addr       switchD_00422500::caseD_11
//         00422610     addr       switchD_00422500::caseD_12
//         00422614     addr       switchD_00422500::caseD_13
//         00422618     addr       switchD_00422500::caseD_14
//         0042261c     addr       switchD_00422500::caseD_15
//         00422620     addr       switchD_00422500::caseD_16
//         00422624     ??         90h
//         00422625     ??         90h
//         00422626     ??         90h
//         00422627     ??         90h
//         00422628     ??         90h
//         00422629     ??         90h
//         0042262a     ??         90h
//         0042262b     ??         90h
//         0042262c     ??         90h
//         0042262d     ??         90h
//         0042262e     ??         90h
//         0042262f     ??         90h
    return 0;
}

uchar RGE_Base_Game::playerCDAndVersion(int param_1) {
    /* TODO: Stub */
//                              uchar __thiscall playerCDAndVersion(RGE_Base_Game * this, int param_1)
//              uchar             AL:1           <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00422630(R)
//                               ?playerCDAndVersion@RGE_Base_Game@@QAEEH@Z                   XREF[1]:     get_game_options:00422360(c)
//                               RGE_Base_Game::playerCDAndVersion
//                              basegame.cpp:5236 (11)
//         00422630     MOV        EAX,dword ptr [ESP + param_1]
//         00422634     MOV        AL,byte ptr [ECX + EAX*0x1 + this+0x98a]
//                              basegame.cpp:5238 (3)
//         0042263b     RET        0x4
//         0042263e     ??         90h
//         0042263f     NOP
    return 0;
}

int RGE_Base_Game::difficulty() {
    /* TODO: Stub */
//                              int __thiscall difficulty(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?difficulty@RGE_Base_Game@@QAEHXZ                            XREF[22]:    get_game_options:00422343(c),
//                               RGE_Base_Game::difficulty                                                 TRIBE_Screen_Campaign_Selection:00
//                                                                                                         updateSummary:004a4b55(c),
//                                                                                                         updateSummary:004a4b6a(c),
//                                                                                                         TRIBE_Screen_Wait:004a5c2a(c),
//                                                                                                         TRIBE_Screen_Wait:004a5c3f(c),
//                                                                                                         getSettings:004b6401(c),
//                                                                                                         update:004e59af(c),
//                                                                                                         loadAIInformation:00515821(c),
//                                                                                                         intelligentBuildListAndRulesSelect
//                                                                                                         setupEgyptian:00517c29(c),
//                                                                                                         setupGreek:00517d69(c),
//                                                                                                         setupAssyrian:00517fc9(c),
//                                                                                                         setupMinoan:00518129(c),
//                                                                                                         setupSumerian:005184a2(c),
//                                                                                                         setupYamato:00518842(c),
//                                                                                                         let_game_begin:005289f9(c),
//                                                                                                         new_game:0052f3b2(c),
//                                                                                                         new_game:0052f3c9(c),
//                                                                                                         save:00543756(c), [more]
//                              basegame.cpp:5244 (8)
//         00422640     XOR        EAX,EAX
//         00422642     MOV        AL,byte ptr [ECX + this+0x993]
//                              basegame.cpp:5246 (1)
//         00422648     RET
//         00422649     ??         90h
//         0042264a     NOP
//         0042264b     NOP
//         0042264c     NOP
//         0042264d     NOP
//         0042264e     NOP
//         0042264f     NOP
    return 0;
}

int RGE_Base_Game::numberPlayers() {
    /* TODO: Stub */
//                              int __thiscall numberPlayers(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?numberPlayers@RGE_Base_Game@@QBEHXZ                         XREF[45]:    reset_score_display:0049b0c2(c),
//                               RGE_Base_Game::numberPlayers                                              reset_score_display:0049b15c(c),
//                                                                                                         reset_score_display:0049b235(c),
//                                                                                                         reset_score_display:0049b261(c),
//                                                                                                         startGame:004a2291(c),
//                                                                                                         startGame:004a22ec(c),
//                                                                                                         startGame:004a23df(c),
//                                                                                                         startGame:004a2401(c),
//                                                                                                         startGame:004a24ba(c),
//                                                                                                         startGame:004a24f6(c),
//                                                                                                         startGame:004a2594(c),
//                                                                                                         calcRandomPositions:004a27b5(c),
//                                                                                                         calcRandomPositions:004a27dc(c),
//                                                                                                         calcRandomPositions:004a282a(c),
//                                                                                                         calcRandomPositions:004a28f9(c),
//                                                                                                         create_game:00526fbf(c),
//                                                                                                         create_game:00527006(c),
//                                                                                                         create_game:00527254(c),
//                                                                                                         create_game:0052728e(c),
//                                                                                                         create_game:0052730b(c), [more]
//                              basegame.cpp:5251 (8)
//         00422650     XOR        EAX,EAX
//         00422652     MOV        AL,byte ptr [ECX + this+0x988]
//                              basegame.cpp:5253 (1)
//         00422658     RET
//         00422659     ??         90h
//         0042265a     NOP
//         0042265b     NOP
//         0042265c     NOP
//         0042265d     NOP
//         0042265e     NOP
//         0042265f     NOP
    return 0;
}

int RGE_Base_Game::playerTeam(int param_1) {
    /* TODO: Stub */
//                              int __thiscall playerTeam(RGE_Base_Game * this, int param_1)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00422660(R)
//                               ?playerTeam@RGE_Base_Game@@QAEHH@Z                           XREF[19]:    get_game_options:0042236f(c),
//                               RGE_Base_Game::playerTeam                                                 scenario_load:0046f53b(c),
//                                                                                                         scenario_postload:0046f8a4(c),
//                                                                                                         startGame:004a254f(c),
//                                                                                                         startGame:004a2574(c),
//                                                                                                         startGame:004a262a(c),
//                                                                                                         handle_user_command:004a2e2f(c),
//                                                                                                         handle_user_command:004a2e54(c),
//                                                                                                         handle_user_command:004a305c(c),
//                                                                                                         handle_user_command:004a316c(c),
//                                                                                                         handle_user_command:004a32ed(c),
//                                                                                                         handle_user_command:004a3312(c),
//                                                                                                         fillPlayers:004a38da(c),
//                                                                                                         fillPlayers:004a3c38(c),
//                                                                                                         let_game_begin:00528b8b(c),
//                                                                                                         send_zone_score_info:005314fb(c),
//                                                                                                         new_game:0054293c(c),
//                                                                                                         new_game:00542977(c),
//                                                                                                         new_game:00542a2d(c)
//                              basegame.cpp:5259 (13)
//         00422660     MOV        EDX,dword ptr [ESP + param_1]
//         00422664     XOR        EAX,EAX
//         00422666     MOV        AL,byte ptr [ECX + EDX*0x1 + this+0x994]
//                              basegame.cpp:5261 (3)
//         0042266d     RET        0x4
    return 0;
}

uchar RGE_Base_Game::pathFinding() {
    /* TODO: Stub */
//                              uchar __thiscall pathFinding(RGE_Base_Game * this)
//              uchar             AL:1           <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?pathFinding@RGE_Base_Game@@QAEEXZ                           XREF[8]:     ~RGE_Base_Game:0041c340(c),
//                               RGE_Base_Game::pathFinding                                                TribeConfigDialog:0043bfcd(c),
//                                                                                                         updateSummary:004a4e28(c),
//                                                                                                         TRIBE_Screen_Wait:004a5efd(c),
//                                                                                                         getSettings:004b643a(c),
//                                                                                                         load_game:00526375(c),
//                                                                                                         create_game:005277c5(c),
//                                                                                                         new_game:0052f69a(c)
//                              basegame.cpp:5267 (6)
//         00422670     MOV        AL,byte ptr [ECX + this->pathFindingValue]
//                              basegame.cpp:5269 (1)
//         00422676     RET
//         00422677     ??         90h
//         00422678     NOP
//         00422679     NOP
//         0042267a     NOP
//         0042267b     NOP
//         0042267c     NOP
//         0042267d     NOP
//         0042267e     NOP
//         0042267f     NOP
    return 0;
}

uchar RGE_Base_Game::mpPathFinding() {
    /* TODO: Stub */
//                              uchar __thiscall mpPathFinding(RGE_Base_Game * this)
//              uchar             AL:1           <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?mpPathFinding@RGE_Base_Game@@QAEEXZ                         XREF[8]:     ~RGE_Base_Game:0041c360(c),
//                               RGE_Base_Game::mpPathFinding                                              get_game_options:00422350(c),
//                                                                                                         TribeConfigDialog:0043bfc6(c),
//                                                                                                         updateSummary:004a4e16(c),
//                                                                                                         TRIBE_Screen_Wait:004a5eeb(c),
//                                                                                                         getSettings:004b6433(c),
//                                                                                                         create_game:005277be(c),
//                                                                                                         new_game:0052f68e(c)
//                              basegame.cpp:5275 (6)
//         00422680     MOV        AL,byte ptr [ECX + this+0x983]
//                              basegame.cpp:5277 (1)
//         00422686     RET
//         00422687     ??         90h
//         00422688     NOP
//         00422689     NOP
//         0042268a     NOP
//         0042268b     NOP
//         0042268c     NOP
//         0042268d     NOP
//         0042268e     NOP
//         0042268f     NOP
    return 0;
}

char* RGE_Base_Game::gameSummary() {
    /* TODO: Stub */
//                              char * __thiscall gameSummary(RGE_Base_Game * this)
//              char *            EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?gameSummary@RGE_Base_Game@@UAEPADXZ                         XREF[1]:     0056ef20(*)
//                               RGE_Base_Game::gameSummary
//                              basegame.cpp:5282 (7)
//         00422690     MOV        byte ptr [DAT_0062c49c],0x0                      = align(4)
//                              basegame.cpp:5285 (5)
//         00422697     MOV        EAX,DAT_0062c49c                                 = align(4)
//                              basegame.cpp:5338 (1)
//         0042269c     RET
//         0042269d     ??         90h
//         0042269e     NOP
//         0042269f     NOP
    return 0;
}

void RGE_Base_Game::find_campaigns() {
    /* TODO: Stub */
//                              void __thiscall find_campaigns(RGE_Base_Game * this)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?find_campaigns@RGE_Base_Game@@QAEXXZ                        XREF[1]:     make_campaign:00490345(c)
//                               RGE_Base_Game::find_campaigns
//                              basegame.cpp:5344 (8)
//         004226a0     MOV        this,dword ptr [ECX + this->player_game_info]
//         004226a3     JMP        RGE_Game_Info::find_campaigns                    void find_campaigns(RGE_Game_Info * this)
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//         004226a8     ??         90h
//         004226a9     NOP
//         004226aa     NOP
//         004226ab     NOP
//         004226ac     NOP
//         004226ad     NOP
//         004226ae     NOP
//         004226af     NOP
    return;
}

void RGE_Base_Game::setScenarioGame(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setScenarioGame(RGE_Base_Game * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004226b0(R)
//                               ?setScenarioGame@RGE_Base_Game@@QAEXH@Z                      XREF[12]:    RGE_Base_Game:0041b6ec(c),
//                               RGE_Base_Game::setScenarioGame                                            set_game_options:00422149(c),
//                                                                                                         startGame:00491394(c),
//                                                                                                         init_vars:004a0f72(c),
//                                                                                                         updateSummary:004a42d8(c),
//                                                                                                         sendSettings:004b47db(c),
//                                                                                                         sendSettings:004b651a(c),
//                                                                                                         sendSettings:004b6535(c),
//                                                                                                         action:004b6d1d(c),
//                                                                                                         action:004b6d90(c),
//                                                                                                         action:004b6e4d(c),
//                                                                                                         start_scenario:00525f10(c)
//                              basegame.cpp:5351 (10)
//         004226b0     MOV        AL,byte ptr [ESP + param_1]
//         004226b4     MOV        byte ptr [ECX + this+0x8fc],AL
//                              basegame.cpp:5353 (3)
//         004226ba     RET        0x4
//         004226bd     ??         90h
//         004226be     NOP
//         004226bf     NOP
    return;
}

void RGE_Base_Game::setVersion(float param_1) {
    /* TODO: Stub */
//                              void __thiscall setVersion(RGE_Base_Game * this, float param_1)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[1]:     004226c0(R)
//                               ?setVersion@RGE_Base_Game@@QAEXM@Z                           XREF[2]:     RGE_Base_Game:0041b6e4(c),
//                               RGE_Base_Game::setVersion                                                 set_game_options:0042213c(c)
//                              basegame.cpp:5358 (10)
//         004226c0     MOV        EAX,dword ptr [ESP + param_1]
//         004226c4     MOV        dword ptr [ECX + this->rge_game_options.versio
//                              basegame.cpp:5360 (3)
//         004226ca     RET        0x4
//         004226cd     ??         90h
//         004226ce     NOP
//         004226cf     NOP
    return;
}

void RGE_Base_Game::setScenarioName(char* param_1) {
    /* TODO: Stub */
//                              void __thiscall setScenarioName(RGE_Base_Game * this, char * param_1)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     004226d0(R)
//                               ?setScenarioName@RGE_Base_Game@@QAEXPAD@Z                    XREF[7]:     RGE_Base_Game:0041b7a7(c),
//                               RGE_Base_Game::setScenarioName                                            set_game_options:00422154(c),
//                                                                                                         init_vars:004a0f82(c),
//                                                                                                         sendSettings:004b47f2(c),
//                                                                                                         sendSettings:004b6545(c),
//                                                                                                         TribeSPMenuScreen:004b69f2(c),
//                                                                                                         start_scenario:00525f1f(c)
//                              basegame.cpp:5365 (28)
//         004226d0     MOV        EAX,dword ptr [ESP + param_1]
//         004226d4     PUSH       ESI
//         004226d5     MOV        ESI,this
//                              language.dll match for 0x80: "Arial"
//         004226d7     PUSH       0x80
//         004226dc     PUSH       EAX
//         004226dd     LEA        this,[ESI + 0x8fd]
//         004226e3     PUSH       this
//         004226e4     CALL       strncpy                                          undefined strncpy()
//         004226e9     ADD        ESP,0xc
//                              basegame.cpp:5367 (7)
//         004226ec     MOV        byte ptr [ESI + 0x97c],0x0
//                              basegame.cpp:5368 (4)
//         004226f3     POP        ESI
//         004226f4     RET        0x4
//         004226f7     ??         90h
//         004226f8     NOP
//         004226f9     NOP
//         004226fa     NOP
//         004226fb     NOP
//         004226fc     NOP
//         004226fd     NOP
//         004226fe     NOP
//         004226ff     NOP
    return;
}

void RGE_Base_Game::setCampaignGame(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setCampaignGame(RGE_Base_Game * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00422700(R)
//                               ?setCampaignGame@RGE_Base_Game@@QAEXH@Z                      XREF[8]:     RGE_Base_Game:0041b6f4(c),
//                               RGE_Base_Game::setCampaignGame                                            startGame:004913a1(c),
//                                                                                                         init_vars:004a0f5a(c),
//                                                                                                         init_vars:004a122d(c),
//                                                                                                         action:004b6d03(c),
//                                                                                                         action:004b6d76(c),
//                                                                                                         action:004b6e33(c),
//                                                                                                         start_scenario:00525efe(c)
//                              basegame.cpp:5373 (10)
//         00422700     MOV        EAX,dword ptr [ESP + param_1]
//         00422704     MOV        dword ptr [ECX + this->campaignGameValue],EAX
//                              basegame.cpp:5375 (3)
//         0042270a     RET        0x4
//         0042270d     ??         90h
//         0042270e     NOP
//         0042270f     NOP
    return;
}

void RGE_Base_Game::setSavedGame(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setSavedGame(RGE_Base_Game * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00422710(R)
//                               ?setSavedGame@RGE_Base_Game@@QAEXH@Z                         XREF[9]:     RGE_Base_Game:0041b6fc(c),
//                               RGE_Base_Game::setSavedGame                                               startGame:004913af(c),
//                                                                                                         init_vars:004a0f66(c),
//                                                                                                         init_vars:004a1239(c),
//                                                                                                         action:004b6d10(c),
//                                                                                                         action:004b6d83(c),
//                                                                                                         action:004b6e40(c),
//                                                                                                         start_scenario:00525f07(c),
//                                                                                                         load_game:0052635b(c)
//                              basegame.cpp:5380 (10)
//         00422710     MOV        EAX,dword ptr [ESP + param_1]
//         00422714     MOV        dword ptr [ECX + this->savedGameValue],EAX
//                              basegame.cpp:5382 (3)
//         0042271a     RET        0x4
//         0042271d     ??         90h
//         0042271e     NOP
//         0042271f     NOP
    return;
}

void RGE_Base_Game::setSinglePlayerGame(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setSinglePlayerGame(RGE_Base_Game * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00422720(R)
//                               ?setSinglePlayerGame@RGE_Base_Game@@QAEXH@Z                  XREF[5]:     RGE_Base_Game:0041b709(c),
//                               RGE_Base_Game::setSinglePlayerGame                                        set_game_options:00422164(c),
//                                                                                                         TribeSPMenuScreen:004b69e2(c),
//                                                                                                         start_scenario:00525ef5(c),
//                                                                                                         action_user_command:00529b09(c)
//                              basegame.cpp:5387 (4)
//         00422720     MOV        EAX,dword ptr [ESP + param_1]
//                              basegame.cpp:5389 (19)
//         00422724     XOR        EDX,EDX
//         00422726     TEST       EAX,EAX
//         00422728     SETZ       DL
//         0042272b     MOV        byte ptr [ECX + this+0x97d],AL
//         00422731     MOV        byte ptr [ECX + this+0x97e],DL
//                              basegame.cpp:5390 (3)
//         00422737     RET        0x4
//         0042273a     ??         90h
//         0042273b     NOP
//         0042273c     NOP
//         0042273d     NOP
//         0042273e     NOP
//         0042273f     NOP
    return;
}

void RGE_Base_Game::setMultiplayerGame(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setMultiplayerGame(RGE_Base_Game * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00422740(R)
//                               ?setMultiplayerGame@RGE_Base_Game@@QAEXH@Z                   XREF[6]:     RGE_Base_Game:0041b711(c),
//                               RGE_Base_Game::setMultiplayerGame                                         set_game_options:00422174(c),
//                                                                                                         TribeMPStartupScreen:0049f3d0(c),
//                                                                                                         action:0049fa68(c),
//                                                                                                         setup:00521bc0(c),
//                                                                                                         setup:00521e91(c)
//                              basegame.cpp:5395 (4)
//         00422740     MOV        EAX,dword ptr [ESP + param_1]
//                              basegame.cpp:5397 (19)
//         00422744     XOR        EDX,EDX
//         00422746     TEST       EAX,EAX
//         00422748     SETZ       DL
//         0042274b     MOV        byte ptr [ECX + this+0x97e],AL
//         00422751     MOV        byte ptr [ECX + this+0x97d],DL
//                              basegame.cpp:5398 (3)
//         00422757     RET        0x4
//         0042275a     ??         90h
//         0042275b     NOP
//         0042275c     NOP
//         0042275d     NOP
//         0042275e     NOP
//         0042275f     NOP
    return;
}

void RGE_Base_Game::setMapSize(int param_1, int param_2, int param_3) {
    /* TODO: Stub */
//                              void __thiscall setMapSize(RGE_Base_Game * this, int param_1, int pa
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00422760(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00422764(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0042276e(R)
//                               ?setMapSize@RGE_Base_Game@@QAEXHHH@Z                         XREF[8]:     RGE_Base_Game:0041b71e(c),
//                               RGE_Base_Game::setMapSize                                                 set_game_options:00422196(c),
//                                                                                                         setMapSize:0052921c(c),
//                                                                                                         setMapSize:0052922a(c),
//                                                                                                         setMapSize:00529238(c),
//                                                                                                         setMapSize:0052924c(c),
//                                                                                                         setMapSize:00529260(c),
//                                                                                                         setMapSize:00529274(c)
//                              basegame.cpp:5403 (4)
//         00422760     MOV        AL,byte ptr [ESP + param_1]
//                              basegame.cpp:5405 (10)
//         00422764     MOV        DL,byte ptr [ESP + param_2]
//         00422768     MOV        byte ptr [ECX + this+0x97f],AL
//                              basegame.cpp:5406 (16)
//         0042276e     MOV        AL,byte ptr [ESP + param_3]
//         00422772     MOV        byte ptr [ECX + this+0x980],DL
//         00422778     MOV        byte ptr [ECX + this+0x981],AL
//                              basegame.cpp:5407 (3)
//         0042277e     RET        0xc
//         00422781     ??         90h
//         00422782     NOP
//         00422783     NOP
//         00422784     NOP
//         00422785     NOP
//         00422786     NOP
//         00422787     NOP
//         00422788     NOP
//         00422789     NOP
//         0042278a     NOP
//         0042278b     NOP
//         0042278c     NOP
//         0042278d     NOP
//         0042278e     NOP
//         0042278f     NOP
    return;
}

void RGE_Base_Game::setAllowCheatCodes(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setAllowCheatCodes(RGE_Base_Game * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00422790(R)
//                               ?setAllowCheatCodes@RGE_Base_Game@@QAEXH@Z                   XREF[8]:     RGE_Base_Game:0041b726(c),
//                               RGE_Base_Game::setAllowCheatCodes                                         set_game_options:004221a6(c),
//                                                                                                         startGame:00491442(c),
//                                                                                                         init_vars:004a0ff4(c),
//                                                                                                         init_vars:004a1279(c),
//                                                                                                         sendSettings:004b6608(c),
//                                                                                                         start_scenario:00525f45(c),
//                                                                                                         load_game:00526352(c)
//                              basegame.cpp:5412 (10)
//         00422790     MOV        AL,byte ptr [ESP + param_1]
//         00422794     MOV        byte ptr [ECX + this+0x982],AL
//                              basegame.cpp:5415 (3)
//         0042279a     RET        0x4
//         0042279d     ??         90h
//         0042279e     NOP
//         0042279f     NOP
    return;
}

void RGE_Base_Game::setCheatNotification(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setCheatNotification(RGE_Base_Game * this, int param
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004227a0(R)
//                               ?setCheatNotification@RGE_Base_Game@@QAEXH@Z                 XREF[2]:     RGE_Base_Game:0041b72e(c),
//                               RGE_Base_Game::setCheatNotification                                       set_game_options:004221b6(c)
//                              basegame.cpp:5420 (10)
//         004227a0     MOV        AL,byte ptr [ESP + param_1]
//         004227a4     MOV        byte ptr [ECX + this+0x984],AL
//                              basegame.cpp:5422 (3)
//         004227aa     RET        0x4
//         004227ad     ??         90h
//         004227ae     NOP
//         004227af     NOP
    return;
}

void RGE_Base_Game::setFullVisibility(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setFullVisibility(RGE_Base_Game * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004227b0(R)
//                               ?setFullVisibility@RGE_Base_Game@@QAEXH@Z                    XREF[8]:     RGE_Base_Game:0041b736(c),
//                               RGE_Base_Game::setFullVisibility                                          set_game_options:004221c6(c),
//                                                                                                         startGame:00491428(c),
//                                                                                                         init_vars:004a0fdb(c),
//                                                                                                         init_vars:004a125f(c),
//                                                                                                         sendSettings:004b661f(c),
//                                                                                                         start_scenario:00525f33(c),
//                                                                                                         load_game:00526330(c)
//                              basegame.cpp:5427 (10)
//         004227b0     MOV        AL,byte ptr [ESP + param_1]
//         004227b4     MOV        byte ptr [ECX + this+0x985],AL
//                              basegame.cpp:5430 (3)
//         004227ba     RET        0x4
//         004227bd     ??         90h
//         004227be     NOP
//         004227bf     NOP
    return;
}

void RGE_Base_Game::setFogOfWar(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setFogOfWar(RGE_Base_Game * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004227c0(R)
//                               ?setFogOfWar@RGE_Base_Game@@QAEXH@Z                          XREF[7]:     RGE_Base_Game:0041b73e(c),
//                               RGE_Base_Game::setFogOfWar                                                set_game_options:004221d6(c),
//                                                                                                         startGame:00491435(c),
//                                                                                                         init_vars:004a0fe8(c),
//                                                                                                         init_vars:004a126c(c),
//                                                                                                         start_scenario:00525f3c(c),
//                                                                                                         load_game:00526349(c)
//                              basegame.cpp:5435 (10)
//         004227c0     MOV        AL,byte ptr [ESP + param_1]
//         004227c4     MOV        byte ptr [ECX + this+0x986],AL
//                              basegame.cpp:5438 (3)
//         004227ca     RET        0x4
//         004227cd     ??         90h
//         004227ce     NOP
//         004227cf     NOP
    return;
}

void RGE_Base_Game::setColoredChat(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setColoredChat(RGE_Base_Game * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004227d0(R)
//                               ?setColoredChat@RGE_Base_Game@@QAEXH@Z                       XREF[2]:     RGE_Base_Game:0041b746(c),
//                               RGE_Base_Game::setColoredChat                                             set_game_options:004221e6(c)
//                              basegame.cpp:5443 (10)
//         004227d0     MOV        AL,byte ptr [ESP + param_1]
//         004227d4     MOV        byte ptr [ECX + this+0x987],AL
//                              basegame.cpp:5445 (3)
//         004227da     RET        0x4
//         004227dd     ??         90h
//         004227de     NOP
//         004227df     NOP
    return;
}

void RGE_Base_Game::setNumberPlayers(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setNumberPlayers(RGE_Base_Game * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004227e0(R)
//                               ?setNumberPlayers@RGE_Base_Game@@QAEXH@Z                     XREF[10]:    RGE_Base_Game:0041b79b(c),
//                               RGE_Base_Game::setNumberPlayers                                           set_game_options:004221f6(c),
//                                                                                                         startGame:0049154f(c),
//                                                                                                         init_vars:004a0fcf(c),
//                                                                                                         init_vars:004a1221(c),
//                                                                                                         action:004a1c01(c),
//                                                                                                         setupSinglePlayerPlayers:004a52df(
//                                                                                                         TRIBE_Game:00521337(c),
//                                                                                                         start_scenario:005260cc(c),
//                                                                                                         load_game:0052636e(c)
//                              basegame.cpp:5450 (10)
//         004227e0     MOV        AL,byte ptr [ESP + param_1]
//         004227e4     MOV        byte ptr [ECX + this+0x988],AL
//                              basegame.cpp:5452 (3)
//         004227ea     RET        0x4
//         004227ed     ??         90h
//         004227ee     NOP
//         004227ef     NOP
    return;
}

void RGE_Base_Game::setGameDeveloperMode(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setGameDeveloperMode(RGE_Base_Game * this, int param
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004227f0(R)
//                               ?setGameDeveloperMode@RGE_Base_Game@@QAEXH@Z                 XREF[3]:     RGE_Base_Game:0041b74e(c),
//                               RGE_Base_Game::setGameDeveloperMode                                       setup_cmd_options:0041e4ff(c),
//                                                                                                         set_game_options:00422206(c)
//                              basegame.cpp:5457 (10)
//         004227f0     MOV        AL,byte ptr [ESP + param_1]
//         004227f4     MOV        byte ptr [ECX + this+0x989],AL
//                              basegame.cpp:5460 (3)
//         004227fa     RET        0x4
//         004227fd     ??         90h
//         004227fe     NOP
//         004227ff     NOP
    return;
}

void RGE_Base_Game::setPlayerHasCD(int param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall setPlayerHasCD(RGE_Base_Game * this, int param_1, in
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00422800(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00422805(R)
//                               ?setPlayerHasCD@RGE_Base_Game@@QAEXHH@Z                      XREF[6]:     RGE_Base_Game:0041b76a(c),
//                               RGE_Base_Game::setPlayerHasCD                                             init_vars:004a10f0(c),
//                                                                                                         startGame:004a242b(c),
//                                                                                                         handle_user_command:004a2efa(c),
//                                                                                                         handle_user_command:004a301b(c),
//                                                                                                         handle_user_command:004a3130(c)
//                              basegame.cpp:5466 (21)
//         00422800     MOV        EAX,dword ptr [ESP + param_1]
//         00422804     PUSH       EBX
//         00422805     MOV        BL,byte ptr [ESP + param_2]
//         00422809     MOV        DL,byte ptr [ECX + EAX*0x1 + this+0x98a]
//         00422810     AND        DL,0xfe
//         00422813     OR         DL,BL
//                              basegame.cpp:5469 (11)
//         00422815     POP        EBX
//         00422816     MOV        byte ptr [ECX + EAX*0x1 + this+0x98a],DL
//         0042281d     RET        0x8
    return;
}

void RGE_Base_Game::setPlayerVersion(int param_1, uchar param_2) {
    /* TODO: Stub */
//                              void __thiscall setPlayerVersion(RGE_Base_Game * this, int param_1,
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00422825(R)
//              uchar             Stack[0x8]:1   param_2                   XREF[1]:     00422820(R)
//                               ?setPlayerVersion@RGE_Base_Game@@QAEXHE@Z                    XREF[6]:     RGE_Base_Game:0041b773(c),
//                               RGE_Base_Game::setPlayerVersion                                           init_vars:004a10fd(c),
//                                                                                                         init_vars:004a1159(c),
//                                                                                                         handle_user_command:004a309a(c),
//                                                                                                         handle_user_command:004a319d(c),
//                                                                                                         fillPlayers:004a3a5a(c)
//                              basegame.cpp:5475 (30)
//         00422820     MOV        AL,byte ptr [ESP + param_2]
//         00422824     PUSH       ESI
//         00422825     MOV        ESI,dword ptr [ESP + param_1]
//         00422829     SHL        AL,0x1
//         0042282b     MOV        DL,byte ptr [ECX + ESI*0x1 + this+0x98a]
//         00422832     AND        DL,0x1
//         00422835     OR         AL,DL
//         00422837     MOV        byte ptr [ECX + ESI*0x1 + this+0x98a],AL
//                              basegame.cpp:5478 (4)
//         0042283e     POP        ESI
//         0042283f     RET        0x8
//         00422842     ??         90h
//         00422843     NOP
//         00422844     NOP
//         00422845     NOP
//         00422846     NOP
//         00422847     NOP
//         00422848     NOP
//         00422849     NOP
//         0042284a     NOP
//         0042284b     NOP
//         0042284c     NOP
//         0042284d     NOP
//         0042284e     NOP
//         0042284f     NOP
    return;
}

void RGE_Base_Game::setPlayerCDAndVersion(int param_1, uchar param_2) {
    /* TODO: Stub */
//                              void __thiscall setPlayerCDAndVersion(RGE_Base_Game * this, int para
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00422850(R)
//              uchar             Stack[0x8]:1   param_2                   XREF[1]:     00422854(R)
//                               ?setPlayerCDAndVersion@RGE_Base_Game@@QAEXHE@Z               XREF[2]:     RGE_Base_Game:0041b761(c),
//                               RGE_Base_Game::setPlayerCDAndVersion                                      set_game_options:00422236(c)
//                              basegame.cpp:5484 (15)
//         00422850     MOV        EDX,dword ptr [ESP + param_1]
//         00422854     MOV        AL,byte ptr [ESP + param_2]
//         00422858     MOV        byte ptr [ECX + EDX*0x1 + this+0x98a],AL
//                              basegame.cpp:5486 (3)
//         0042285f     RET        0x8
//         00422862     ??         90h
//         00422863     NOP
//         00422864     NOP
//         00422865     NOP
//         00422866     NOP
//         00422867     NOP
//         00422868     NOP
//         00422869     NOP
//         0042286a     NOP
//         0042286b     NOP
//         0042286c     NOP
//         0042286d     NOP
//         0042286e     NOP
//         0042286f     NOP
    return;
}

void RGE_Base_Game::setDifficulty(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setDifficulty(RGE_Base_Game * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00422870(R)
//                               ?setDifficulty@RGE_Base_Game@@QAEXH@Z                        XREF[8]:     RGE_Base_Game:0041b756(c),
//                               RGE_Base_Game::setDifficulty                                              set_game_options:00422216(c),
//                                                                                                         init_vars:00490e92(c),
//                                                                                                         startGame:004913d3(c),
//                                                                                                         init_vars:004a1060(c),
//                                                                                                         init_vars:004a12e5(c),
//                                                                                                         sendSettings:004b670a(c),
//                                                                                                         start_scenario:00525fa5(c)
//                              basegame.cpp:5492 (10)
//         00422870     MOV        AL,byte ptr [ESP + param_1]
//         00422874     MOV        byte ptr [ECX + this+0x993],AL
//                              basegame.cpp:5494 (3)
//         0042287a     RET        0x4
//         0042287d     ??         90h
//         0042287e     NOP
//         0042287f     NOP
    return;
}

void RGE_Base_Game::setPlayerTeam(int param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall setPlayerTeam(RGE_Base_Game * this, int param_1, int
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00422880(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00422884(R)
//                               ?setPlayerTeam@RGE_Base_Game@@QAEXHH@Z                       XREF[16]:    RGE_Base_Game:0041b77c(c),
//                               RGE_Base_Game::setPlayerTeam                                              set_game_options:00422248(c),
//                                                                                                         startGame:0049150f(c),
//                                                                                                         init_vars:004a1121(c),
//                                                                                                         action:004a2012(c),
//                                                                                                         startGame:004a2584(c),
//                                                                                                         startGame:004a2671(c),
//                                                                                                         handle_user_command:004a2e64(c),
//                                                                                                         handle_user_command:004a3071(c),
//                                                                                                         handle_user_command:004a317d(c),
//                                                                                                         handle_user_command:004a3322(c),
//                                                                                                         fillPlayers:004a38ea(c),
//                                                                                                         updateSummary:004a440c(c),
//                                                                                                         updateSummary:004a44a0(c),
//                                                                                                         setupSinglePlayerPlayers:004a53eb(
//                                                                                                         start_scenario:00526075(c)
//                              basegame.cpp:5500 (15)
//         00422880     MOV        EDX,dword ptr [ESP + param_1]
//         00422884     MOV        AL,byte ptr [ESP + param_2]
//         00422888     MOV        byte ptr [ECX + EDX*0x1 + this+0x994],AL
//                              basegame.cpp:5502 (3)
//         0042288f     RET        0x8
//         00422892     ??         90h
//         00422893     NOP
//         00422894     NOP
//         00422895     NOP
//         00422896     NOP
//         00422897     NOP
//         00422898     NOP
//         00422899     NOP
//         0042289a     NOP
//         0042289b     NOP
//         0042289c     NOP
//         0042289d     NOP
//         0042289e     NOP
//         0042289f     NOP
    return;
}

void RGE_Base_Game::setPathFinding(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall setPathFinding(RGE_Base_Game * this, uchar param_1)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004228a0(R)
//                               ?setPathFinding@RGE_Base_Game@@QAEXE@Z                       XREF[6]:     RGE_Base_Game:0041b78a(c),
//                               RGE_Base_Game::setPathFinding                                             setup:0041bc3e(c),
//                                                                                                         action:0043c3a8(c),
//                                                                                                         action:0043c3cf(c),
//                                                                                                         action:0043c3f7(c),
//                                                                                                         sendSettings:004b66b6(c)
//                              basegame.cpp:5508 (10)
//         004228a0     MOV        AL,byte ptr [ESP + param_1]
//         004228a4     MOV        byte ptr [ECX + this->pathFindingValue],AL
//                              basegame.cpp:5510 (3)
//         004228aa     RET        0x4
//         004228ad     ??         90h
//         004228ae     NOP
//         004228af     NOP
    return;
}

void RGE_Base_Game::setMpPathFinding(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall setMpPathFinding(RGE_Base_Game * this, uchar param_1)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004228b0(R)
//                               ?setMpPathFinding@RGE_Base_Game@@QAEXE@Z                     XREF[4]:     RGE_Base_Game:0041b792(c),
//                               RGE_Base_Game::setMpPathFinding                                           setup:0041bc62(c),
//                                                                                                         set_game_options:00422224(c),
//                                                                                                         sendSettings:004b66a3(c)
//                              basegame.cpp:5516 (10)
//         004228b0     MOV        AL,byte ptr [ESP + param_1]
//         004228b4     MOV        byte ptr [ECX + this+0x983],AL
//                              basegame.cpp:5518 (3)
//         004228ba     RET        0x4
//         004228bd     ??         90h
//         004228be     NOP
//         004228bf     NOP
    return;
}

void RGE_Base_Game::set_map_visible(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall set_map_visible(RGE_Base_Game * this, uchar param_1)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004228ca(R)
//                               ?set_map_visible@RGE_Base_Game@@QAEXE@Z                      XREF[5]:     handle_game_update:00496e18(c),
//                               RGE_Base_Game::set_map_visible                                            command_visibility:0049d1df(c),
//                                                                                                         create_game:00526ed1(c),
//                                                                                                         create_game:0052774f(c),
//                                                                                                         cheat:00531082(c)
//                              basegame.cpp:5524 (10)
//         004228c0     MOV        this,dword ptr [ECX + this->world]
//         004228c6     TEST       this,this
//         004228c8     JZ         LAB_004228d4
//                              basegame.cpp:5526 (10)
//         004228ca     MOV        EAX,dword ptr [ESP + param_1]
//         004228ce     PUSH       EAX
//         004228cf     CALL       RGE_Game_World::set_map_visible                  void set_map_visible(RGE_Game_World * this, u
//                               LAB_004228d4                                                 XREF[1]:     004228c8(j)
//                              basegame.cpp:5527 (3)
//         004228d4     RET        0x4
//         004228d7     ??         90h
//         004228d8     NOP
//         004228d9     NOP
//         004228da     NOP
//         004228db     NOP
//         004228dc     NOP
//         004228dd     NOP
//         004228de     NOP
//         004228df     NOP
    return;
}

void RGE_Base_Game::set_map_fog(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall set_map_fog(RGE_Base_Game * this, uchar param_1)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004228ea(R)
//                               ?set_map_fog@RGE_Base_Game@@QAEXE@Z                          XREF[5]:     handle_game_update:00496e24(c),
//                               RGE_Base_Game::set_map_fog                                                command_fog_of_war:0049c25f(c),
//                                                                                                         create_game:00526ed9(c),
//                                                                                                         create_game:005277ac(c),
//                                                                                                         cheat:005310be(c)
//                              basegame.cpp:5533 (10)
//         004228e0     MOV        this,dword ptr [ECX + this->world]
//         004228e6     TEST       this,this
//         004228e8     JZ         LAB_004228f4
//                              basegame.cpp:5535 (10)
//         004228ea     MOV        EAX,dword ptr [ESP + param_1]
//         004228ee     PUSH       EAX
//         004228ef     CALL       RGE_Game_World::set_map_fog                      void set_map_fog(RGE_Game_World * this, uchar
//                               LAB_004228f4                                                 XREF[1]:     004228e8(j)
//                              basegame.cpp:5536 (3)
//         004228f4     RET        0x4
//         004228f7     ??         90h
//         004228f8     NOP
//         004228f9     NOP
//         004228fa     NOP
//         004228fb     NOP
//         004228fc     NOP
//         004228fd     NOP
//         004228fe     NOP
//         004228ff     NOP
    return;
}

void RGE_Base_Game::turn_world_sound_off() {
    /* TODO: Stub */
//                              void __thiscall turn_world_sound_off(RGE_Base_Game * this)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?turn_world_sound_off@RGE_Base_Game@@QAEXXZ                  XREF[1]:     do_game_over:00526e0b(c)
//                               RGE_Base_Game::turn_world_sound_off
//                              basegame.cpp:5542 (14)
//         00422900     MOV        this,dword ptr [ECX + this->world]
//         00422906     MOV        EAX,dword ptr [this->_padding_]
//         00422908     JMP        dword ptr [EAX + 0xb4]
//         0042290e     ??         90h
//         0042290f     NOP
    return;
}

int RGE_Base_Game::campaign_open_scenario() {
    /* TODO: Stub */
//                              int __thiscall campaign_open_scenario(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?campaign_open_scenario@RGE_Base_Game@@QAEHXZ                XREF[1]:     load_scenario:005440a9(c)
//                               RGE_Base_Game::campaign_open_scenario
//                              basegame.cpp:5550 (8)
//         00422910     MOV        this,dword ptr [ECX + this->player_game_info]
//         00422913     JMP        RGE_Game_Info::open_scenario                     int open_scenario(RGE_Game_Info * this)
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//         00422918     ??         90h
//         00422919     NOP
//         0042291a     NOP
//         0042291b     NOP
//         0042291c     NOP
//         0042291d     NOP
//         0042291e     NOP
//         0042291f     NOP
    return 0;
}

long RGE_Base_Game::GetChecksum(long param_1) {
    /* TODO: Stub */
//                              long __thiscall GetChecksum(RGE_Base_Game * this, long param_1)
//              long              EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0042292a(R)
//                               ?GetChecksum@RGE_Base_Game@@QAEJJ@Z                          XREF[1]:     LogChecksums:0043396a(c)
//                               RGE_Base_Game::GetChecksum
//                              basegame.cpp:5559 (10)
//         00422920     MOV        EAX,dword ptr [ECX + this->world]
//         00422926     TEST       EAX,EAX
//         00422928     JZ         LAB_0042295a
//                              basegame.cpp:5562 (8)
//         0042292a     MOV        this,dword ptr [ESP + param_1]
//         0042292e     TEST       this,this
//         00422930     JGE        LAB_00422944
//                              basegame.cpp:5563 (15)
//         00422932     MOVSX      this,word ptr [EAX + 0x7c]
//         00422936     MOV        EDX,dword ptr [EAX + 0x40]
//         00422939     MOV        this,dword ptr [EDX + this->_padding_*0x4]
//         0042293c     CALL       RGE_Player::get_checksum                         long get_checksum(RGE_Player * this)
//                              basegame.cpp:5572 (3)
//         00422941     RET        0x4
//                               LAB_00422944                                                 XREF[1]:     00422930(j)
//                              basegame.cpp:5565 (8)
//         00422944     MOVSX      EDX,word ptr [EAX + 0x3c]
//         00422948     CMP        this,EDX
//         0042294a     JGE        LAB_0042295a
//                              basegame.cpp:5566 (11)
//         0042294c     MOV        EAX,dword ptr [EAX + 0x40]
//         0042294f     MOV        this,dword ptr [EAX + this->_padding_*0x4]
//         00422952     CALL       RGE_Player::get_checksum                         long get_checksum(RGE_Player * this)
//                              basegame.cpp:5572 (3)
//         00422957     RET        0x4
//                               LAB_0042295a                                                 XREF[2]:     00422928(j), 0042294a(j)
//                              basegame.cpp:5571 (2)
//         0042295a     XOR        EAX,EAX
//                              basegame.cpp:5572 (3)
//         0042295c     RET        0x4
//         0042295f     ??         90h
    return 0;
}

uchar RGE_Base_Game::GetWorldChecksums(long* param_1, long* param_2, long* param_3) {
    /* TODO: Stub */
//                              uchar __thiscall GetWorldChecksums(RGE_Base_Game * this, long * para
//              uchar             AL:1           <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              long *            Stack[0x4]:4   param_1                   XREF[1]:     0042296f(R)
//              long *            Stack[0x8]:4   param_2                   XREF[1]:     00422964(R)
//              long *            Stack[0xc]:4   param_3                   XREF[1]:     00422969(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00422975(W), 004229be(R)
//              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     00422990(W), 0042299c(*), 004229ce(R)
//              long              Stack[-0xc]:4  checksum3                 XREF[3]:     0042298c(W), 004229a0(*), 004229c4(R)
//              long              Stack[-0x10]:4 checksum2                 XREF[3]:     00422979(W), 004229a9(*), 004229b6(R)
//              long              Stack[-0x14]:4 checksum1
//                               ?GetWorldChecksums@RGE_Base_Game@@QAEEAAJ00@Z                XREF[1]:     DoChecksum:00433324(c)
//                               RGE_Base_Game::GetWorldChecksums
//                              basegame.cpp:5578 (4)
//         00422960     SUB        ESP,0x10
//         00422963     PUSH       EBX
//                              basegame.cpp:5585 (5)
//         00422964     MOV        EBX,dword ptr [ESP + param_2]
//         00422968     PUSH       EBP
//                              basegame.cpp:5586 (27)
//         00422969     MOV        EBP,dword ptr [ESP + param_3]
//         0042296d     PUSH       ESI
//         0042296e     PUSH       EDI
//         0042296f     MOV        EDI,dword ptr [ESP + param_1]
//         00422973     XOR        ESI,ESI
//         00422975     MOV        dword ptr [ESP + local_4],this
//         00422979     MOV        dword ptr [ESP + checksum2],ESI
//         0042297d     MOV        dword ptr [EDI],ESI
//         0042297f     MOV        dword ptr [EBX],ESI
//         00422981     MOV        dword ptr [EBP],ESI
//                              basegame.cpp:5587 (18)
//         00422984     MOV        EAX,dword ptr [ECX + this->world]
//         0042298a     CMP        EAX,ESI
//         0042298c     MOV        dword ptr [ESP + checksum3],ESI
//         00422990     MOV        dword ptr [ESP + local_8],ESI
//         00422994     JZ         LAB_004229f5
//                              basegame.cpp:5589 (6)
//         00422996     CMP        word ptr [EAX + 0x3c],SI
//         0042299a     JLE        LAB_004229e9
//                               LAB_0042299c                                                 XREF[1]:     004229e7(j)
//                              basegame.cpp:5591 (26)
//         0042299c     LEA        this=>local_8,[ESP + 0x18]
//         004229a0     LEA        EDX=>checksum3,[ESP + 0x14]
//         004229a4     PUSH       this
//         004229a5     PUSH       EDX
//         004229a6     MOV        EDX,dword ptr [EAX + 0x40]
//         004229a9     LEA        this=>checksum2,[ESP + 0x18]
//         004229ad     PUSH       this
//         004229ae     MOV        this,dword ptr [EDX + ESI*0x4]
//         004229b1     CALL       RGE_Player::get_checksums                        uchar get_checksums(RGE_Player * this, long *
//                              basegame.cpp:5592 (14)
//         004229b6     MOV        EAX,dword ptr [ESP + checksum2]
//         004229ba     MOV        this,dword ptr [EDI]
//         004229bc     ADD        this,EAX
//         004229be     MOV        EAX,dword ptr [ESP + local_4]
//         004229c2     MOV        dword ptr [EDI],this
//                              basegame.cpp:5593 (10)
//         004229c4     MOV        this,dword ptr [ESP + checksum3]
//         004229c8     MOV        EDX,dword ptr [EBX]
//         004229ca     ADD        EDX,this
//         004229cc     MOV        dword ptr [EBX],EDX
//                              basegame.cpp:5594 (27)
//         004229ce     MOV        EDX,dword ptr [ESP + local_8]
//         004229d2     MOV        this,dword ptr [EBP]
//         004229d5     ADD        this,EDX
//         004229d7     INC        ESI
//         004229d8     MOV        dword ptr [EBP],this
//         004229db     MOV        EAX,dword ptr [EAX + 0x3f4]
//         004229e1     MOVSX      this,word ptr [EAX + 0x3c]
//         004229e5     CMP        ESI,this
//         004229e7     JL         LAB_0042299c
//                               LAB_004229e9                                                 XREF[1]:     0042299a(j)
//                              basegame.cpp:5596 (2)
//         004229e9     MOV        AL,0x1
//                              basegame.cpp:5600 (22)
//         004229eb     POP        EDI
//         004229ec     POP        ESI
//         004229ed     POP        EBP
//         004229ee     POP        EBX
//         004229ef     ADD        ESP,0x10
//         004229f2     RET        0xc
//                               LAB_004229f5                                                 XREF[1]:     00422994(j)
//         004229f5     POP        EDI
//         004229f6     POP        ESI
//         004229f7     POP        EBP
//         004229f8     XOR        AL,AL
//         004229fa     POP        EBX
//         004229fb     ADD        ESP,0x10
//         004229fe     RET        0xc
//         00422a01     ??         90h
//         00422a02     NOP
//         00422a03     NOP
//         00422a04     NOP
//         00422a05     NOP
//         00422a06     NOP
//         00422a07     NOP
//         00422a08     NOP
//         00422a09     NOP
//         00422a0a     NOP
//         00422a0b     NOP
//         00422a0c     NOP
//         00422a0d     NOP
//         00422a0e     NOP
//         00422a0f     NOP
    return 0;
}

long RGE_Base_Game::GetWorldChecksum() {
    /* TODO: Stub */
//                              long __thiscall GetWorldChecksum(RGE_Base_Game * this)
//              long              EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?GetWorldChecksum@RGE_Base_Game@@QAEJXZ
//                               RGE_Base_Game::GetWorldChecksum
//                              basegame.cpp:5606 (4)
//         00422a10     PUSH       EBX
//         00422a11     PUSH       EDI
//         00422a12     MOV        EDI,this
//                              basegame.cpp:5608 (2)
//         00422a14     XOR        EBX,EBX
//                              basegame.cpp:5610 (11)
//         00422a16     MOV        EAX,dword ptr [EDI + 0x3f4]
//         00422a1c     TEST       EAX,EAX
//         00422a1e     JZ         LAB_00422a4b
//         00422a20     PUSH       ESI
//                              basegame.cpp:5612 (8)
//         00422a21     XOR        ESI,ESI
//         00422a23     CMP        word ptr [EAX + 0x3c],SI
//         00422a27     JLE        LAB_00422a45
//                               LAB_00422a29                                                 XREF[1]:     00422a43(j)
//                              basegame.cpp:5613 (28)
//         00422a29     MOV        EAX,dword ptr [EAX + 0x40]
//         00422a2c     MOV        this,dword ptr [EAX + ESI*0x4]
//         00422a2f     CALL       RGE_Player::get_checksum                         long get_checksum(RGE_Player * this)
//         00422a34     ADD        EBX,EAX
//         00422a36     MOV        EAX,dword ptr [EDI + 0x3f4]
//         00422a3c     INC        ESI
//         00422a3d     MOVSX      this,word ptr [EAX + 0x3c]
//         00422a41     CMP        ESI,this
//         00422a43     JL         LAB_00422a29
//                               LAB_00422a45                                                 XREF[1]:     00422a27(j)
//                              basegame.cpp:5614 (2)
//         00422a45     MOV        EAX,EBX
//                              basegame.cpp:5606 (1)
//         00422a47     POP        ESI
//                              basegame.cpp:5618 (8)
//         00422a48     POP        EDI
//         00422a49     POP        EBX
//         00422a4a     RET
//                               LAB_00422a4b                                                 XREF[1]:     00422a1e(j)
//         00422a4b     POP        EDI
//         00422a4c     XOR        EAX,EAX
//         00422a4e     POP        EBX
//         00422a4f     RET
    return 0;
}

void RGE_Base_Game::disable_input() {
    /* TODO: Stub */
//                              void __thiscall disable_input(RGE_Base_Game * this)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?disable_input@RGE_Base_Game@@QAEXXZ                         XREF[45]:    set_mode:0048e439(c),
//                               RGE_Base_Game::disable_input                                              close_screen:0049d73d(c),
//                                                                                                         close_screen:0049d7da(c),
//                                                                                                         close_screen:0049d972(c),
//                                                                                                         close_screen:0049da20(c),
//                                                                                                         close_screen:0049dace(c),
//                                                                                                         close_screen:0049db7c(c),
//                                                                                                         close_screen:0049dc19(c),
//                                                                                                         close_screen:0049dccb(c),
//                                                                                                         action:0049fb0f(c),
//                                                                                                         action:0049fc7e(c),
//                                                                                                         action:004a1a88(c),
//                                                                                                         cancelScreen:004a2bce(c),
//                                                                                                         cancelScreen:004a2cde(c),
//                                                                                                         load_db_files:00524535(c),
//                                                                                                         start_game:00525d8a(c),
//                                                                                                         start_scenario:00525eec(c),
//                                                                                                         load_game:0052619f(c),
//                                                                                                         create_game_screen:0052784a(c),
//                                                                                                         start_scenario_editor:00528df9(c),
//                                                                                                         [more]
//                              basegame.cpp:5624 (3)
//         00422a50     PUSH       ESI
//         00422a51     MOV        ESI,this
//                              basegame.cpp:5625 (10)
//         00422a53     MOV        EAX,dword ptr [ESI + 0x1cc]
//         00422a59     TEST       EAX,EAX
//         00422a5b     JZ         LAB_00422a72
//                              basegame.cpp:5626 (21)
//         00422a5d     PUSH       0x7f02
//         00422a62     PUSH       0x0
//         00422a64     CALL       dword ptr [->USER32.DLL::LoadCursorA]            = 0048acbc
//         00422a6a     PUSH       EAX
//         00422a6b     MOV        this,ESI
//         00422a6d     CALL       RGE_Base_Game::set_mouse_cursor                  void set_mouse_cursor(RGE_Base_Game * this, v
//                               LAB_00422a72                                                 XREF[1]:     00422a5b(j)
//                              basegame.cpp:5628 (10)
//         00422a72     MOV        this,panel_system
//         00422a77     CALL       TPanelSystem::DisableInput                       void DisableInput(TPanelSystem * this)
//                              basegame.cpp:5632 (20)
//         00422a7c     MOV        EAX,dword ptr [ESI + 0x1dc]
//         00422a82     MOV        dword ptr [ESI + 0x1d8],0x0
//         00422a8c     TEST       EAX,EAX
//         00422a8e     JZ         LAB_00422aad
//                              basegame.cpp:5634 (10)
//         00422a90     CALL       dword ptr [->USER32.DLL::GetCapture]             = 0048afa2
//         00422a96     TEST       EAX,EAX
//         00422a98     JZ         LAB_00422aa0
//                              basegame.cpp:5635 (6)
//         00422a9a     CALL       dword ptr [->USER32.DLL::ReleaseCapture]         = 0048af90
//                               LAB_00422aa0                                                 XREF[1]:     00422a98(j)
//                              basegame.cpp:5637 (13)
//         00422aa0     MOV        EAX,dword ptr [ESI + 0x1dc]
//         00422aa6     PUSH       EAX
//         00422aa7     CALL       dword ptr [->USER32.DLL::SetCapture]             = 0048af82
//                               LAB_00422aad                                                 XREF[1]:     00422a8e(j)
//                              basegame.cpp:5639 (2)
//         00422aad     POP        ESI
//         00422aae     RET
//         00422aaf     ??         90h
    return;
}

void RGE_Base_Game::enable_input() {
    /* TODO: Stub */
//                              void __thiscall enable_input(RGE_Base_Game * this)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?enable_input@RGE_Base_Game@@QAEXXZ                          XREF[36]:    handle_idle:00491aa7(c),
//                               RGE_Base_Game::enable_input                                               handle_idle:00491af4(c),
//                                                                                                         handle_idle:0049d623(c),
//                                                                                                         handle_idle:0049e2c3(c),
//                                                                                                         handle_idle:0049f353(c),
//                                                                                                         handle_idle:004a6183(c),
//                                                                                                         handle_idle:004b31b3(c),
//                                                                                                         handle_idle:004b88c3(c),
//                                                                                                         start_video:00523a91(c),
//                                                                                                         load_db_files:005245c5(c),
//                                                                                                         save_scenario:00524813(c),
//                                                                                                         save_scenario:00524865(c),
//                                                                                                         start_game:00525dde(c),
//                                                                                                         start_scenario:00526028(c),
//                                                                                                         start_scenario:005260b5(c),
//                                                                                                         load_game:005262f3(c),
//                                                                                                         load_game:0052630c(c),
//                                                                                                         create_game_screen:00527a58(c),
//                                                                                                         let_game_begin:00528d53(c),
//                                                                                                         start_scenario_editor:00528eba(c),
//                                                                                                         [more]
//                              basegame.cpp:5645 (3)
//         00422ab0     PUSH       ESI
//         00422ab1     MOV        ESI,this
//                              basegame.cpp:5646 (10)
//         00422ab3     MOV        EAX,dword ptr [ESI + 0x1dc]
//         00422ab9     TEST       EAX,EAX
//         00422abb     JZ         LAB_00422acd
//                              basegame.cpp:5648 (10)
//         00422abd     CALL       dword ptr [->USER32.DLL::GetCapture]             = 0048afa2
//         00422ac3     TEST       EAX,EAX
//         00422ac5     JZ         LAB_00422acd
//                              basegame.cpp:5649 (6)
//         00422ac7     CALL       dword ptr [->USER32.DLL::ReleaseCapture]         = 0048af90
//                               LAB_00422acd                                                 XREF[2]:     00422abb(j), 00422ac5(j)
//                              basegame.cpp:5652 (10)
//         00422acd     MOV        this,panel_system
//         00422ad2     CALL       TPanelSystem::EnableInput                        void EnableInput(TPanelSystem * this)
//                              basegame.cpp:5656 (20)
//         00422ad7     MOV        EAX,dword ptr [ESI + 0x1cc]
//         00422add     MOV        dword ptr [ESI + 0x1d8],0x1
//         00422ae7     TEST       EAX,EAX
//         00422ae9     JZ         LAB_00422b00
//                              basegame.cpp:5657 (21)
//         00422aeb     PUSH       0x7f00
//         00422af0     PUSH       0x0=>DAT_fffffff8
//         00422af2     CALL       dword ptr [->USER32.DLL::LoadCursorA]            = 0048acbc
//         00422af8     PUSH       EAX
//         00422af9     MOV        this,ESI
//         00422afb     CALL       RGE_Base_Game::set_mouse_cursor                  void set_mouse_cursor(RGE_Base_Game * this, v
//                               LAB_00422b00                                                 XREF[1]:     00422ae9(j)
//                              basegame.cpp:5658 (2)
//         00422b00     POP        ESI
//         00422b01     RET
//         00422b02     ??         90h
//         00422b03     NOP
//         00422b04     NOP
//         00422b05     NOP
//         00422b06     NOP
//         00422b07     NOP
//         00422b08     NOP
//         00422b09     NOP
//         00422b0a     NOP
//         00422b0b     NOP
//         00422b0c     NOP
//         00422b0d     NOP
//         00422b0e     NOP
//         00422b0f     NOP
    return;
}

void RGE_Base_Game::set_screen_size(long param_1, long param_2) {
    /* TODO: Stub */
//                              void __thiscall set_screen_size(RGE_Base_Game * this, long param_1,
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[2]:     00422b20(R), 00422ba9(W)
//              long              Stack[0x8]:4   param_2                   XREF[2]:     00422b18(R), 00422bad(W)
//              tagRECT           Stack[-0x14]   client_rect
//              tagRECT           Stack[-0x24]   win_rect
//                               ?set_screen_size@RGE_Base_Game@@QAEXJJ@Z                     XREF[1]:     action:0043c68b(c)
//                               RGE_Base_Game::set_screen_size
//                              basegame.cpp:5664 (8)
//         00422b10     SUB        ESP,0x20
//         00422b13     PUSH       EBX
//         00422b14     PUSH       EBP
//         00422b15     PUSH       ESI
//         00422b16     MOV        ESI,this
//                              basegame.cpp:5671 (26)
//         00422b18     MOV        EBP,dword ptr [ESP + param_2]
//         00422b1c     PUSH       EDI
//         00422b1d     MOV        EAX,dword ptr [ESI + 0x4c]
//         00422b20     MOV        EDI,dword ptr [ESP + param_1]
//         00422b24     CMP        dword ptr [EAX + 0x18],EDI
//         00422b27     JNZ        LAB_00422b32
//         00422b29     CMP        dword ptr [EAX + 0x1c],EBP
//         00422b2c     JZ         LAB_00422cb4
//                               LAB_00422b32                                                 XREF[1]:     00422b27(j)
//                              basegame.cpp:5675 (21)
//         00422b32     MOV        EAX,dword ptr [ESI + 0x48]
//         00422b35     MOV        this,0x2
//         00422b37     CMP        byte ptr [EAX + 0x478],this
//         00422b3d     JNZ        LAB_00422b9f
//         00422b3f     CMP        byte ptr [EAX + 0x479],this
//         00422b45     JNZ        LAB_00422b9f
//                              basegame.cpp:5679 (8)
//         00422b47     PUSH       0x0
//         00422b49     CALL       dword ptr [->USER32.DLL::SetCursor]              = 0048aeda
//                              basegame.cpp:5680 (14)
//         00422b4f     MOV        EAX,dword ptr [ESI + 0x10]
//         00422b52     PUSH       0x0
//         00422b54     PUSH       offset DAT_fffffff8
//         00422b56     PUSH       EAX=>DAT_fffffff4
//         00422b57     CALL       dword ptr [->USER32.DLL::SetClassLongA]          = 0048aeca
//                              basegame.cpp:5682 (11)
//         00422b5d     MOV        this,dword ptr [ESI + 0x1c0]
//         00422b63     CALL       TMousePointer::Shutdown_Mouse                    int Shutdown_Mouse(TMousePointer * this)
//                              basegame.cpp:5684 (12)
//         00422b68     MOV        this,dword ptr [ESI + 0x48]
//         00422b6b     PUSH       0x8
//         00422b6d     PUSH       EBP=>DAT_fffffff8
//         00422b6e     PUSH       EDI=>DAT_fffffff4
//         00422b6f     CALL       TDrawSystem::SetDisplaySize                      int SetDisplaySize(TDrawSystem * this, long p
//                              basegame.cpp:5686 (8)
//         00422b74     MOV        this,dword ptr [ESI + 0x48]
//         00422b77     CALL       TDrawSystem::CheckSurfaces                       uchar CheckSurfaces(TDrawSystem * this)
//                              basegame.cpp:5687 (8)
//         00422b7c     MOV        this,dword ptr [ESI + 0x48]
//         00422b7f     CALL       TDrawSystem::ClearRestored                       void ClearRestored(TDrawSystem * this)
//                              basegame.cpp:5688 (7)
//         00422b84     MOV        this,ESI
//         00422b86     CALL       RGE_Base_Game::set_render_all                    void set_render_all(RGE_Base_Game * this)
//                              basegame.cpp:5692 (10)
//         00422b8b     MOV        dword ptr [restore_mouse_after_paint],0x1
//                              basegame.cpp:5735 (10)
//         00422b95     POP        EDI
//         00422b96     POP        ESI
//         00422b97     POP        EBP
//         00422b98     POP        EBX
//         00422b99     ADD        ESP,0x20
//         00422b9c     RET        0x8
//                               LAB_00422b9f                                                 XREF[2]:     00422b3d(j), 00422b45(j)
//                              basegame.cpp:5701 (2)
//         00422b9f     XOR        EAX,EAX
//                              basegame.cpp:5704 (24)
//         00422ba1     PUSH       EAX
//         00422ba2     PUSH       EAX
//         00422ba3     PUSH       EAX
//         00422ba4     PUSH       s_DISPLAY                                        = "DISPLAY"
//         00422ba9     MOV        dword ptr [ESP + param_1],EAX
//         00422bad     MOV        dword ptr [ESP + param_2],EAX
//         00422bb1     CALL       dword ptr [->GDI32.DLL::CreateICA]               = 0048b1f8
//         00422bb7     MOV        EBX,EAX
//                              basegame.cpp:5705 (4)
//         00422bb9     TEST       EBX,EBX
//         00422bbb     JZ         LAB_00422bde
//                              basegame.cpp:5707 (9)
//         00422bbd     PUSH       0x8
//         00422bbf     PUSH       EBX=>DAT_fffffff8
//         00422bc0     CALL       dword ptr [->GDI32.DLL::GetDeviceCaps]           = 0048b170
//                              basegame.cpp:5708 (13)
//         00422bc6     PUSH       0xa
//         00422bc8     PUSH       EBX=>DAT_fffffff8
//         00422bc9     MOV        dword ptr [ESP + 0x3c],EAX
//         00422bcd     CALL       dword ptr [->GDI32.DLL::GetDeviceCaps]           = 0048b170
//                              basegame.cpp:5709 (11)
//         00422bd3     PUSH       EBX
//         00422bd4     MOV        dword ptr [ESP + 0x3c],EAX
//         00422bd8     CALL       dword ptr [->GDI32.DLL::DeleteDC]                = 0048b1ec
//                               LAB_00422bde                                                 XREF[1]:     00422bbb(j)
//                              basegame.cpp:5712 (24)
//         00422bde     MOV        EAX,dword ptr [ESP + 0x34]
//         00422be2     CMP        EDI,EAX
//         00422be4     JG         LAB_00422cb4
//         00422bea     MOV        this,dword ptr [ESP + 0x38]
//         00422bee     CMP        EBP,this
//         00422bf0     JG         LAB_00422cb4
//                              basegame.cpp:5715 (8)
//         00422bf6     CMP        EAX,EDI
//         00422bf8     JNZ        LAB_00422c20
//         00422bfa     CMP        this,EBP
//         00422bfc     JNZ        LAB_00422c20
//                              basegame.cpp:5718 (26)
//         00422bfe     MOV        this,dword ptr [ESI + 0x10]
//         00422c01     MOV        EBX,dword ptr [->USER32.DLL::SetWindowLongA]     = 0048afb0
//         00422c07     PUSH       0x92080000
//         00422c0c     PUSH       offset DAT_fffffff8
//         00422c0e     PUSH       this=>DAT_fffffff4
//         00422c0f     MOV        dword ptr [ESI + 0x24],0x92080000
//         00422c16     CALL       EBX=>USER32.DLL::SetWindowLongA
//                              basegame.cpp:5719 (6)
//         00422c18     MOV        EDX,dword ptr [ESI + 0x24]
//         00422c1b     PUSH       EDX
//         00422c1c     PUSH       offset DAT_fffffff8
//                              basegame.cpp:5721 (2)
//         00422c1e     JMP        LAB_00422c40
//                               LAB_00422c20                                                 XREF[2]:     00422bf8(j), 00422bfc(j)
//                              basegame.cpp:5724 (26)
//         00422c20     MOV        this,dword ptr [ESI + 0x10]
//         00422c23     MOV        EBX,dword ptr [->USER32.DLL::SetWindowLongA]     = 0048afb0
//         00422c29     PUSH       0x12ca0000
//         00422c2e     PUSH       offset DAT_fffffff8
//         00422c30     PUSH       this=>DAT_fffffff4
//         00422c31     MOV        dword ptr [ESI + 0x24],0x12ca0000
//         00422c38     CALL       EBX=>USER32.DLL::SetWindowLongA
//                              basegame.cpp:5725 (12)
//         00422c3a     MOV        EDX,dword ptr [ESI + 0x24]
//         00422c3d     PUSH       EDX
//         00422c3e     PUSH       offset DAT_fffffff8
//                               LAB_00422c40                                                 XREF[1]:     00422c1e(j)
//         00422c40     MOV        EAX,dword ptr [ESI + 0x10]
//         00422c43     PUSH       EAX=>DAT_fffffff4
//         00422c44     CALL       EBX=>USER32.DLL::SetWindowLongA
//                              basegame.cpp:5728 (22)
//         00422c46     MOV        this,dword ptr [ESI + 0x10]
//         00422c49     MOV        EBX,dword ptr [->USER32.DLL::SetWindowPos]       = 0048adc6
//         00422c4f     PUSH       0x0
//         00422c51     PUSH       EBP=>DAT_fffffff8
//         00422c52     PUSH       EDI=>DAT_fffffff4
//         00422c53     PUSH       0x0=>DAT_fffffff0
//         00422c55     PUSH       0x0
//         00422c57     PUSH       0x0
//         00422c59     PUSH       this
//         00422c5a     CALL       EBX=>USER32.DLL::SetWindowPos
//                              basegame.cpp:5729 (15)
//         00422c5c     MOV        EAX,dword ptr [ESI + 0x10]
//         00422c5f     LEA        EDX,[ESP + 0x10]
//         00422c63     PUSH       EDX
//         00422c64     PUSH       EAX=>DAT_fffffff8
//         00422c65     CALL       dword ptr [->USER32.DLL::GetWindowRect]          = 0048ade6
//                              basegame.cpp:5730 (15)
//         00422c6b     MOV        EDX,dword ptr [ESI + 0x10]
//         00422c6e     LEA        this,[ESP + 0x20]
//         00422c72     PUSH       this
//         00422c73     PUSH       EDX=>DAT_fffffff8
//         00422c74     CALL       dword ptr [->USER32.DLL::GetClientRect]          = 0048add6
//                              basegame.cpp:5731 (16)
//         00422c7a     MOV        EDX,dword ptr [ESP + 0x28]
//         00422c7e     MOV        this,dword ptr [ESP + 0x2c]
//         00422c82     CMP        EDX,EDI
//         00422c84     JNZ        LAB_00422c8a
//         00422c86     CMP        this,EBP
//         00422c88     JZ         LAB_00422cb4
//                               LAB_00422c8a                                                 XREF[1]:     00422c84(j)
//                              basegame.cpp:5732 (42)
//         00422c8a     MOV        EAX,dword ptr [ESP + 0x1c]
//         00422c8e     PUSH       0x0
//         00422c90     ADD        EBP,EAX
//         00422c92     MOV        EAX,dword ptr [ESP + 0x18]
//         00422c96     SUB        EBP,EAX
//         00422c98     SUB        EBP,this
//         00422c9a     MOV        this,dword ptr [ESP + 0x1c]
//         00422c9e     ADD        EDI,this
//         00422ca0     MOV        this,dword ptr [ESP + 0x14]
//         00422ca4     SUB        EDI,this
//         00422ca6     PUSH       EBP=>DAT_fffffff8
//         00422ca7     SUB        EDI,EDX
//         00422ca9     MOV        EDX,dword ptr [ESI + 0x10]
//         00422cac     PUSH       EDI=>DAT_fffffff4
//         00422cad     PUSH       EAX=>DAT_fffffff0
//         00422cae     PUSH       this
//         00422caf     PUSH       0x0
//         00422cb1     PUSH       EDX
//         00422cb2     CALL       EBX=>USER32.DLL::SetWindowPos
//                               LAB_00422cb4                                                 XREF[4]:     00422b2c(j), 00422be4(j),
//                                                                                                         00422bf0(j), 00422c88(j)
//                              basegame.cpp:5735 (10)
//         00422cb4     POP        EDI
//         00422cb5     POP        ESI
//         00422cb6     POP        EBP
//         00422cb7     POP        EBX
//         00422cb8     ADD        ESP,0x20
//         00422cbb     RET        0x8
//         00422cbe     ??         90h
//         00422cbf     NOP
    return;
}

uchar RGE_Base_Game::check_prog_argument(char* param_1) {
    /* TODO: Stub */
//                              uchar __thiscall check_prog_argument(RGE_Base_Game * this, char * pa
//              uchar             AL:1           <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1
//              undefined1        Stack[-0x1]:1  local_1                   XREF[1]:     00422ce5(W)
//              char[256]         Stack[-0x104   cmd_line                  XREF[0,2]:   00422cd3(*), 00422ce1(*)
//                               ?check_prog_argument@RGE_Base_Game@@QAEEPAD@Z                XREF[14]:    setup:0041bda5(c),
//                               RGE_Base_Game::check_prog_argument                                        check_multi_copies:0041fe91(c),
//                                                                                                         TRIBE_Screen_Game:004953dd(c),
//                                                                                                         key_down_action:00497cdf(c),
//                                                                                                         setup:00521b4b(c),
//                                                                                                         save_game:00524691(c),
//                                                                                                         load_game:0052624a(c),
//                                                                                                         load_game:00526471(c),
//                                                                                                         create_game:00526ea0(c),
//                                                                                                         action_user_command:00529c16(c),
//                                                                                                         setup_video_system:0052a2fb(c),
//                                                                                                         new_game:0052ff6c(c),
//                                                                                                         new_game:0052ffdb(c),
//                                                                                                         save_scenario:00543acd(c)
//                              basegame.cpp:5741 (6)
//         00422cc0     SUB        ESP,0x100
//                              basegame.cpp:5745 (27)
//         00422cc6     MOV        EAX,dword ptr [ECX + this->prog_info]
//         00422cc9     PUSH       0xff
//         00422cce     ADD        EAX,0x518
//         00422cd3     LEA        this=>cmd_line[4],[ESP + 0x4]
//         00422cd7     PUSH       EAX
//         00422cd8     PUSH       this
//         00422cd9     CALL       strncpy                                          undefined strncpy()
//         00422cde     ADD        ESP,0xc
//                              basegame.cpp:5747 (19)
//         00422ce1     LEA        EDX=>cmd_line[4],[ESP]
//         00422ce5     MOV        byte ptr [ESP + local_1],0x0
//         00422ced     PUSH       EDX
//         00422cee     CALL       dword ptr [->USER32.DLL::CharUpperA]             = 0048ad8a
//                              basegame.cpp:5749 (21)
//         00422cf4     MOV        EAX,dword ptr [ESP + 0x104]
//         00422cfb     LEA        this,[ESP]
//         00422cff     PUSH       EAX
//         00422d00     PUSH       this=>DAT_fffffff8
//         00422d01     CALL       strstr                                           undefined strstr()
//         00422d06     ADD        ESP,0x8
//                              basegame.cpp:5750 (5)
//         00422d09     TEST       EAX,EAX
//         00422d0b     SETNZ      AL
//                              basegame.cpp:5754 (9)
//         00422d0e     ADD        ESP,0x100
//         00422d14     RET        0x4
//         00422d17     ??         90h
//         00422d18     NOP
//         00422d19     NOP
//         00422d1a     NOP
//         00422d1b     NOP
//         00422d1c     NOP
//         00422d1d     NOP
//         00422d1e     NOP
//         00422d1f     NOP
    return 0;
}

long RGE_Base_Game::get_scenario_checksum(char* param_1) {
    /* TODO: Stub */
//                              long __thiscall get_scenario_checksum(RGE_Base_Game * this, char * p
//              long              EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     00422d20(R)
//                               ?get_scenario_checksum@RGE_Base_Game@@QAEJPAD@Z              XREF[3]:     check_scenario_checksum:00422d65(c
//                               RGE_Base_Game::get_scenario_checksum                                      action:004a18e1(c),
//                                                                                                         updateSummary:004a45fa(c)
//                              basegame.cpp:5760 (15)
//         00422d20     MOV        EAX,dword ptr [ESP + param_1]
//         00422d24     PUSH       ESI
//         00422d25     PUSH       0x0
//         00422d27     PUSH       EAX
//         00422d28     CALL       RGE_Base_Game::get_scenario_header               RGE_Scenario_Header * get_scenario_header(RGE
//         00422d2d     MOV        ESI,EAX
//                              basegame.cpp:5762 (4)
//         00422d2f     TEST       ESI,ESI
//         00422d31     JNZ        LAB_00422d37
//                              basegame.cpp:5811 (4)
//         00422d33     POP        ESI
//         00422d34     RET        0x4
//                               LAB_00422d37                                                 XREF[1]:     00422d31(j)
//                              basegame.cpp:5760 (1)
//         00422d37     PUSH       EDI
//                              basegame.cpp:5764 (3)
//         00422d38     MOV        EDI,dword ptr [ESI + 0xc]
//                              basegame.cpp:5765 (16)
//         00422d3b     MOV        this,ESI
//         00422d3d     CALL       RGE_Scenario_Header::~RGE_Scenario_Header        void ~RGE_Scenario_Header(RGE_Scenario_Header
//         00422d42     PUSH       ESI
//         00422d43     CALL       operator_delete                                  void operator_delete(void * param_1)
//         00422d48     ADD        ESP,0x4
//                              basegame.cpp:5766 (3)
//         00422d4b     MOV        EAX,EDI
//         00422d4d     POP        EDI
//                              basegame.cpp:5811 (4)
//         00422d4e     POP        ESI
//         00422d4f     RET        0x4
//         00422d52     ??         90h
//         00422d53     NOP
//         00422d54     NOP
//         00422d55     NOP
//         00422d56     NOP
//         00422d57     NOP
//         00422d58     NOP
//         00422d59     NOP
//         00422d5a     NOP
//         00422d5b     NOP
//         00422d5c     NOP
//         00422d5d     NOP
//         00422d5e     NOP
//         00422d5f     NOP
    return 0;
}

uchar RGE_Base_Game::check_scenario_checksum(char* param_1, long param_2) {
    /* TODO: Stub */
//                              uchar __thiscall check_scenario_checksum(RGE_Base_Game * this, char
//              uchar             AL:1           <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     00422d60(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     00422d6e(R)
//                               ?check_scenario_checksum@RGE_Base_Game@@QAEEPADJ@Z
//                               RGE_Base_Game::check_scenario_checksum
//                              basegame.cpp:5817 (10)
//         00422d60     MOV        EAX,dword ptr [ESP + param_1]
//         00422d64     PUSH       EAX
//         00422d65     CALL       RGE_Base_Game::get_scenario_checksum             long get_scenario_checksum(RGE_Base_Game * th
//                              basegame.cpp:5822 (10)
//         00422d6a     TEST       EAX,EAX
//         00422d6c     JZ         LAB_00422d79
//         00422d6e     CMP        EAX,dword ptr [ESP + param_2]
//         00422d72     JNZ        LAB_00422d79
//                              basegame.cpp:5825 (2)
//         00422d74     MOV        AL,0x1
//                              basegame.cpp:5826 (3)
//         00422d76     RET        0x8
//                               LAB_00422d79                                                 XREF[2]:     00422d6c(j), 00422d72(j)
//                              basegame.cpp:5823 (2)
//         00422d79     XOR        AL,AL
//                              basegame.cpp:5826 (3)
//         00422d7b     RET        0x8
//         00422d7e     ??         90h
//         00422d7f     NOP
    return 0;
}

void RGE_Base_Game::dump_memory_usage(char* param_1) {
    /* TODO: Stub */
//                              void __thiscall dump_memory_usage(RGE_Base_Game * this, char * param
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1
//                               ?dump_memory_usage@RGE_Base_Game@@QAEXPAD@Z                  XREF[1]:     key_down_action:00497be0(c)
//                               RGE_Base_Game::dump_memory_usage
//                              basegame.cpp:5833 (3)
//         00422d80     RET        0x4
//         00422d83     ??         90h
//         00422d84     NOP
//         00422d85     NOP
//         00422d86     NOP
//         00422d87     NOP
//         00422d88     NOP
//         00422d89     NOP
//         00422d8a     NOP
//         00422d8b     NOP
//         00422d8c     NOP
//         00422d8d     NOP
//         00422d8e     NOP
//         00422d8f     NOP
    return;
}

int RGE_Base_Game::playerID(int param_1) {
    /* TODO: Stub */
//                              int __thiscall playerID(RGE_Base_Game * this, int param_1)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00422d90(R)
//                               ?playerID@RGE_Base_Game@@QAEHH@Z                             XREF[32]:    do_command_resign:00434ef0(c),
//                               RGE_Base_Game::playerID                                                   TribeDiplomacyDialog:0043ce1a(c),
//                                                                                                         TribeSendMessageDialog:00440916(c)
//                                                                                                         TribeSendMessageDialog:00440971(c)
//                                                                                                         draw:004414a6(c),
//                                                                                                         sendChatMessage:0046f300(c),
//                                                                                                         sendChatMessage:0046f35f(c),
//                                                                                                         scenario_load:0046f4fc(c),
//                                                                                                         scenario_postload:0046f865(c),
//                                                                                                         reset_score_display:0049b0db(c),
//                                                                                                         reset_score_display:0049b180(c),
//                                                                                                         random_start:005144cc(c),
//                                                                                                         draw_score:0051c04c(c),
//                                                                                                         handle_idle:0051c462(c),
//                                                                                                         save_object_info:0051ca2e(c),
//                                                                                                         create_game:00527452(c),
//                                                                                                         create_game:005276d7(c),
//                                                                                                         new_game:00542987(c),
//                                                                                                         new_game:00542995(c),
//                                                                                                         new_game:00542a56(c), [more]
//                              basegame.cpp:5866 (11)
//         00422d90     MOV        EAX,dword ptr [ESP + param_1]
//         00422d94     MOV        EAX,dword ptr [ECX + EAX*0x4 + this->playerIDV
//                              basegame.cpp:5868 (3)
//         00422d9b     RET        0x4
//         00422d9e     ??         90h
//         00422d9f     NOP
    return 0;
}

void RGE_Base_Game::setPlayerID(int param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall setPlayerID(RGE_Base_Game * this, int param_1, int p
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00422da0(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00422da4(R)
//                               ?setPlayerID@RGE_Base_Game@@QAEXHH@Z                         XREF[5]:     load_game:005263bb(c),
//                               RGE_Base_Game::setPlayerID                                                load_game:005263f3(c),
//                                                                                                         create_game:005272f1(c),
//                                                                                                         create_game:00527354(c),
//                                                                                                         create_game:005273ff(c)
//                              basegame.cpp:5874 (15)
//         00422da0     MOV        EDX,dword ptr [ESP + param_1]
//         00422da4     MOV        EAX,dword ptr [ESP + param_2]
//         00422da8     MOV        dword ptr [ECX + EDX*0x4 + this->playerIDValue
//                              basegame.cpp:5876 (3)
//         00422daf     RET        0x8
//         00422db2     ??         90h
//         00422db3     NOP
//         00422db4     NOP
//         00422db5     NOP
//         00422db6     NOP
//         00422db7     NOP
//         00422db8     NOP
//         00422db9     NOP
//         00422dba     NOP
//         00422dbb     NOP
//         00422dbc     NOP
//         00422dbd     NOP
//         00422dbe     NOP
//         00422dbf     NOP
    return;
}

void RGE_Base_Game::reset_countdown_timer(long param_1) {
    /* TODO: Stub */
//                              void __thiscall reset_countdown_timer(RGE_Base_Game * this, long par
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00422dc0(R)
//                               ?reset_countdown_timer@RGE_Base_Game@@QAEXJ@Z                XREF[4]:     ~TRIBE_Action_Wonder:004d3610(c),
//                               RGE_Base_Game::reset_countdown_timer                                      load_game:00526283(c),
//                                                                                                         create_game:0052772c(c),
//                                                                                                         new_game:0052ef8f(c)
//                              basegame.cpp:5882 (15)
//         00422dc0     MOV        EAX,dword ptr [ESP + param_1]
//         00422dc4     MOV        dword ptr [ECX + EAX*0x4 + this->countdown_tim
//                              basegame.cpp:5884 (3)
//         00422dcf     RET        0x4
//         00422dd2     ??         90h
//         00422dd3     NOP
//         00422dd4     NOP
//         00422dd5     NOP
//         00422dd6     NOP
//         00422dd7     NOP
//         00422dd8     NOP
//         00422dd9     NOP
//         00422dda     NOP
//         00422ddb     NOP
//         00422ddc     NOP
//         00422ddd     NOP
//         00422dde     NOP
//         00422ddf     NOP
    return;
}

void RGE_Base_Game::set_countdown_timer(long param_1, long param_2) {
    /* TODO: Stub */
//                              void __thiscall set_countdown_timer(RGE_Base_Game * this, long param
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00422de0(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     00422de5(R)
//                               ?set_countdown_timer@RGE_Base_Game@@QAEXJJ@Z                 XREF[3]:     ~TRIBE_Action_Wonder:004d362f(c),
//                               RGE_Base_Game::set_countdown_timer                                        set_state:004d3750(c),
//                                                                                                         update:004d3887(c)
//                              basegame.cpp:5890 (24)
//         00422de0     MOV        EDX,dword ptr [ESP + param_1]
//         00422de4     PUSH       ESI
//         00422de5     MOV        ESI,dword ptr [ESP + param_2]
//         00422de9     MOV        EAX,dword ptr [ECX + EDX*0x4 + this->countdown
//         00422df0     CMP        EAX,ESI
//         00422df2     JG         LAB_00422df8
//         00422df4     TEST       EAX,EAX
//         00422df6     JGE        LAB_00422dff
//                               LAB_00422df8                                                 XREF[1]:     00422df2(j)
//                              basegame.cpp:5892 (7)
//         00422df8     MOV        dword ptr [ECX + EDX*0x4 + this->countdown_tim
//                               LAB_00422dff                                                 XREF[1]:     00422df6(j)
//                              basegame.cpp:5893 (4)
//         00422dff     POP        ESI
//         00422e00     RET        0x8
//         00422e03     ??         90h
//         00422e04     NOP
//         00422e05     NOP
//         00422e06     NOP
//         00422e07     NOP
//         00422e08     NOP
//         00422e09     NOP
//         00422e0a     NOP
//         00422e0b     NOP
//         00422e0c     NOP
//         00422e0d     NOP
//         00422e0e     NOP
//         00422e0f     NOP
    return;
}

void RGE_Base_Game::get_countdown_timer(long param_1, long* param_2) {
    /* TODO: Stub */
//                              void __thiscall get_countdown_timer(RGE_Base_Game * this, long param
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00422e10(R)
//              long *            Stack[0x8]:4   param_2                   XREF[1]:     00422e14(R)
//                               ?get_countdown_timer@RGE_Base_Game@@QAEXJAAJ@Z               XREF[3]:     draw:0048a94d(c),
//                               RGE_Base_Game::get_countdown_timer                                        reset_clocks:0049ae08(c),
//                                                                                                         handle_idle:0051e1f2(c)
//                              basegame.cpp:5899 (17)
//         00422e10     MOV        EAX,dword ptr [ESP + param_1]
//         00422e14     MOV        EDX,dword ptr [ESP + param_2]
//         00422e18     MOV        this,dword ptr [ECX + EAX*0x4 + this->countdow
//         00422e1f     MOV        dword ptr [EDX],this
//                              basegame.cpp:5901 (3)
//         00422e21     RET        0x8
//         00422e24     ??         90h
//         00422e25     NOP
//         00422e26     NOP
//         00422e27     NOP
//         00422e28     NOP
//         00422e29     NOP
//         00422e2a     NOP
//         00422e2b     NOP
//         00422e2c     NOP
//         00422e2d     NOP
//         00422e2e     NOP
//         00422e2f     NOP
    return;
}

int RGE_Base_Game::play_video(char* param_1) {
    /* TODO: Stub */
//                              int __thiscall play_video(RGE_Base_Game * this, char * param_1)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1
//                               ?play_video@RGE_Base_Game@@QAEHPAD@Z
//                               RGE_Base_Game::play_video
//                              basegame.cpp:5907 (2)
//         00422e30     XOR        EAX,EAX
//                              basegame.cpp:6005 (3)
//         00422e32     RET        0x4
//         00422e35     ??         90h
//         00422e36     NOP
//         00422e37     NOP
//         00422e38     NOP
//         00422e39     NOP
//         00422e3a     NOP
//         00422e3b     NOP
//         00422e3c     NOP
//         00422e3d     NOP
//         00422e3e     NOP
//         00422e3f     NOP
    return 0;
}

void RGE_Base_Game::close_video() {
    /* TODO: Stub */
//                              void __thiscall close_video(RGE_Base_Game * this)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?close_video@RGE_Base_Game@@QAEXXZ
//                               RGE_Base_Game::close_video
//                              basegame.cpp:6011 (1)
//         00422e40     RET
//         00422e41     ??         90h
//         00422e42     NOP
//         00422e43     NOP
//         00422e44     NOP
//         00422e45     NOP
//         00422e46     NOP
//         00422e47     NOP
//         00422e48     NOP
//         00422e49     NOP
//         00422e4a     NOP
//         00422e4b     NOP
//         00422e4c     NOP
//         00422e4d     NOP
//         00422e4e     NOP
//         00422e4f     NOP
    return;
}

void RGE_Base_Game::handle_video_notify() {
    /* TODO: Stub */
//                              void __thiscall handle_video_notify(RGE_Base_Game * this)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?handle_video_notify@RGE_Base_Game@@QAEXXZ
//                               RGE_Base_Game::handle_video_notify
//                              basegame.cpp:6055 (1)
//         00422e50     RET
//         00422e51     ??         90h
//         00422e52     NOP
//         00422e53     NOP
//         00422e54     NOP
//         00422e55     NOP
//         00422e56     NOP
//         00422e57     NOP
//         00422e58     NOP
//         00422e59     NOP
//         00422e5a     NOP
//         00422e5b     NOP
//         00422e5c     NOP
//         00422e5d     NOP
//         00422e5e     NOP
//         00422e5f     NOP
    return;
}

int RGE_Base_Game::play_sound(int param_1) {
    /* TODO: Stub */
//                              int __thiscall play_sound(RGE_Base_Game * this, int param_1)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00422e70(R)
//                               ?play_sound@RGE_Base_Game@@QAEHH@Z                           XREF[34]:    action:0044102c(c),
//                               RGE_Base_Game::play_sound                                                 action:00441192(c),
//                                                                                                         action:004417c7(c),
//                                                                                                         notification:00524dc3(c),
//                                                                                                         notification:00524ea6(c),
//                                                                                                         notification:00524f53(c),
//                                                                                                         notification:00524fc3(c),
//                                                                                                         notification:00525008(c),
//                                                                                                         notification:0052504d(c),
//                                                                                                         notification:0052508f(c),
//                                                                                                         notification:0052511a(c),
//                                                                                                         notification:005251c4(c),
//                                                                                                         notification:00525263(c),
//                                                                                                         notification:005252f5(c),
//                                                                                                         action_user_command:00529bfa(c),
//                                                                                                         action_user_command:00529dcb(c),
//                                                                                                         action_user_command:00529e3a(c),
//                                                                                                         mouse_left_up_action:0052d748(c),
//                                                                                                         mouse_left_up_action:0052d7c7(c),
//                                                                                                         mouse_right_up_action:0052dab8(c),
//                                                                                                         [more]
//                              basegame.cpp:6079 (4)
//         00422e60     PUSH       ESI
//         00422e61     PUSH       EDI
//         00422e62     MOV        EDI,this
//                              basegame.cpp:6080 (7)
//         00422e64     MOV        EAX,dword ptr [EDI + 0x6c]
//         00422e67     TEST       EAX,EAX
//         00422e69     JNZ        LAB_00422e70
//                              basegame.cpp:6090 (5)
//         00422e6b     POP        EDI
//         00422e6c     POP        ESI
//         00422e6d     RET        0x4
//                               LAB_00422e70                                                 XREF[1]:     00422e69(j)
//                              basegame.cpp:6083 (18)
//         00422e70     MOV        this,dword ptr [ESP + param_1]
//         00422e74     LEA        ESI,[this->_padding_*0x4 + 0x0]
//         00422e7b     MOV        this,dword ptr [ESI + EAX*0x1]
//         00422e7e     TEST       this,this
//         00422e80     JNZ        LAB_00422e89
//                              basegame.cpp:6084 (2)
//         00422e82     XOR        EAX,EAX
//                              basegame.cpp:6090 (5)
//         00422e84     POP        EDI
//         00422e85     POP        ESI
//         00422e86     RET        0x4
//                               LAB_00422e89                                                 XREF[1]:     00422e80(j)
//                              basegame.cpp:6086 (9)
//         00422e89     CALL       TDigital::is_playing                             int is_playing(TDigital * this)
//         00422e8e     TEST       EAX,EAX
//         00422e90     JZ         LAB_00422e9c
//                              basegame.cpp:6087 (5)
//         00422e92     MOV        EAX,0x1
//                              basegame.cpp:6090 (5)
//         00422e97     POP        EDI
//         00422e98     POP        ESI
//         00422e99     RET        0x4
//                               LAB_00422e9c                                                 XREF[1]:     00422e90(j)
//                              basegame.cpp:6089 (11)
//         00422e9c     MOV        EDX,dword ptr [EDI + 0x6c]
//         00422e9f     MOV        this,dword ptr [EDX + ESI*0x1]
//         00422ea2     CALL       TDigital::play                                   int play(TDigital * this)
//                              basegame.cpp:6090 (5)
//         00422ea7     POP        EDI
//         00422ea8     POP        ESI
//         00422ea9     RET        0x4
//         00422eac     ??         90h
//         00422ead     NOP
//         00422eae     NOP
//         00422eaf     NOP
    return 0;
}

float RGE_Base_Game::get_game_speed() {
    /* TODO: Stub */
//                              float __thiscall get_game_speed(RGE_Base_Game * this)
//              float             ST0:10         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?get_game_speed@RGE_Base_Game@@QAEMXZ                        XREF[2]:     load_world:0054233b(c),
//                               RGE_Base_Game::get_game_speed                                             new_game:00542ac5(c)
//                              basegame.cpp:6096 (6)
//         00422eb0     FLD        float ptr [ECX + this->game_speed]
//                              basegame.cpp:6098 (1)
//         00422eb6     RET
//         00422eb7     ??         90h
//         00422eb8     NOP
//         00422eb9     NOP
//         00422eba     NOP
//         00422ebb     NOP
//         00422ebc     NOP
//         00422ebd     NOP
//         00422ebe     NOP
//         00422ebf     NOP
    return 0;
}

void RGE_Base_Game::set_game_speed(float param_1) {
    /* TODO: Stub */
//                              void __thiscall set_game_speed(RGE_Base_Game * this, float param_1)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[1]:     00422ec0(R)
//                               ?set_game_speed@RGE_Base_Game@@QAEXM@Z                       XREF[2]:     action:0043c51f(c),
//                               RGE_Base_Game::set_game_speed                                             command_game_speed:0049c52b(c)
//                              basegame.cpp:6104 (10)
//         00422ec0     MOV        EAX,dword ptr [ESP + param_1]
//         00422ec4     MOV        dword ptr [ECX + this->game_speed],EAX
//                              basegame.cpp:6106 (3)
//         00422eca     RET        0x4
//         00422ecd     ??         90h
//         00422ece     NOP
//         00422ecf     NOP
    return;
}

int RGE_Base_Game::get_single_player_difficulty() {
    /* TODO: Stub */
//                              int __thiscall get_single_player_difficulty(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?get_single_player_difficulty@RGE_Base_Game@@QAEHXZ          XREF[4]:     init_vars:00490e86(c),
//                               RGE_Base_Game::get_single_player_difficulty                               init_vars:004a1054(c),
//                                                                                                         init_vars:004a12d9(c),
//                                                                                                         start_scenario:00525f9d(c)
//                              basegame.cpp:6112 (6)
//         00422ed0     MOV        EAX,dword ptr [ECX + this->single_player_diffi
//                              basegame.cpp:6114 (1)
//         00422ed6     RET
//         00422ed7     ??         90h
//         00422ed8     NOP
//         00422ed9     NOP
//         00422eda     NOP
//         00422edb     NOP
//         00422edc     NOP
//         00422edd     NOP
//         00422ede     NOP
//         00422edf     NOP
    return 0;
}

void RGE_Base_Game::set_single_player_difficulty(int param_1) {
    /* TODO: Stub */
//                              void __thiscall set_single_player_difficulty(RGE_Base_Game * this, i
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00422ee0(R)
//                               ?set_single_player_difficulty@RGE_Base_Game@@QAEXH@Z         XREF[2]:     startGame:004913ea(c),
//                               RGE_Base_Game::set_single_player_difficulty                               sendSettings:004b6730(c)
//                              basegame.cpp:6120 (10)
//         00422ee0     MOV        EAX,dword ptr [ESP + param_1]
//         00422ee4     MOV        dword ptr [ECX + this->single_player_difficult
//                              basegame.cpp:6122 (3)
//         00422eea     RET        0x4
//         00422eed     ??         90h
//         00422eee     NOP
//         00422eef     NOP
    return;
}

int RGE_Base_Game::setup_map_save_area() {
    /* TODO: Stub */
//                              int __thiscall setup_map_save_area(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00422f1d(W), 00422f3b(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     00422f4b(R), 00422f9f(R), 00422fb0(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00422f17(W)
//                               ?setup_map_save_area@RGE_Base_Game@@MAEHXZ                   XREF[2]:     0056f00c(*), 005772e4(*)
//                               RGE_Base_Game::setup_map_save_area
//                              basegame.cpp:6128 (26)
//         00422ef0     PUSH       -0x1
//         00422ef2     PUSH       FUN_0055cc1b
//         00422ef7     MOV        EAX,FS:[0x0]
//         00422efd     PUSH       EAX
//         00422efe     MOV        dword ptr FS:[0x0],ESP
//         00422f05     PUSH       this
//         00422f06     PUSH       ESI
//         00422f07     PUSH       EDI
//         00422f08     MOV        ESI,this
//                              basegame.cpp:6129 (47)
//         00422f0a     PUSH       0x100
//         00422f0f     CALL       operator_new                                     void * operator_new(uint param_1)
//         00422f14     ADD        ESP,0x4
//         00422f17     MOV        dword ptr [ESP + local_10],EAX
//         00422f1b     TEST       EAX,EAX
//         00422f1d     MOV        dword ptr [ESP + local_4],0x0
//         00422f25     JZ         LAB_00422f37
//         00422f27     PUSH       0x0
//         00422f29     PUSH       s_Diamond_Map_Save_Area                          = "Diamond Map Save Area"
//         00422f2e     MOV        this,EAX
//         00422f30     CALL       TDrawArea::TDrawArea                             undefined TDrawArea(TDrawArea * this, char *
//         00422f35     JMP        LAB_00422f39
//                               LAB_00422f37                                                 XREF[1]:     00422f25(j)
//         00422f37     XOR        EAX,EAX
//                               LAB_00422f39                                                 XREF[1]:     00422f35(j)
//                              basegame.cpp:6130 (18)
//         00422f39     TEST       EAX,EAX
//         00422f3b     MOV        dword ptr [ESP + local_4],0xffffffff
//         00422f43     MOV        dword ptr [ESI + 0xa20],EAX
//         00422f49     JNZ        LAB_00422f5c
//                              basegame.cpp:6139 (17)
//         00422f4b     MOV        this,dword ptr [ESP + local_c]
//         00422f4f     MOV        dword ptr FS:[0x0],this
//         00422f56     POP        EDI
//         00422f57     POP        ESI
//         00422f58     ADD        ESP,0x10
//         00422f5b     RET
//                               LAB_00422f5c                                                 XREF[1]:     00422f49(j)
//                              basegame.cpp:6132 (29)
//         00422f5c     MOV        this,dword ptr [ESI + 0x48]
//         00422f5f     PUSH       0x0
//         00422f61     PUSH       0x0
//         00422f63     PUSH       0x8c
//         00422f68     PUSH       0x118
//         00422f6d     PUSH       this
//         00422f6e     MOV        this,EAX
//         00422f70     CALL       TDrawArea::Init                                  int Init(TDrawArea * this, TDrawSystem * para
//         00422f75     TEST       EAX,EAX
//         00422f77     JNZ        LAB_00422fb0
//                              basegame.cpp:6134 (26)
//         00422f79     MOV        EDI,dword ptr [ESI + 0xa20]
//         00422f7f     TEST       EDI,EDI
//         00422f81     JZ         LAB_00422f93
//         00422f83     MOV        this,EDI
//         00422f85     CALL       TDrawArea::~TDrawArea                            void ~TDrawArea(TDrawArea * this)
//         00422f8a     PUSH       EDI
//         00422f8b     CALL       operator_delete                                  void operator_delete(void * param_1)
//         00422f90     ADD        ESP,0x4
//                               LAB_00422f93                                                 XREF[1]:     00422f81(j)
//                              basegame.cpp:6135 (10)
//         00422f93     MOV        dword ptr [ESI + 0xa20],0x0
//                              basegame.cpp:6136 (2)
//         00422f9d     XOR        EAX,EAX
//                              basegame.cpp:6139 (39)
//         00422f9f     MOV        this,dword ptr [ESP + local_c]
//         00422fa3     MOV        dword ptr FS:[0x0],this
//         00422faa     POP        EDI
//         00422fab     POP        ESI
//         00422fac     ADD        ESP,0x10
//         00422faf     RET
//                               LAB_00422fb0                                                 XREF[1]:     00422f77(j)
//         00422fb0     MOV        this,dword ptr [ESP + local_c]
//         00422fb4     POP        EDI
//         00422fb5     MOV        EAX,0x1
//         00422fba     MOV        dword ptr FS:[0x0],this
//         00422fc1     POP        ESI
//         00422fc2     ADD        ESP,0x10
//         00422fc5     RET
//         00422fc6     ??         90h
//         00422fc7     NOP
//         00422fc8     NOP
//         00422fc9     NOP
//         00422fca     NOP
//         00422fcb     NOP
//         00422fcc     NOP
//         00422fcd     NOP
//         00422fce     NOP
//         00422fcf     NOP
    return 0;
}

void RGE_Base_Game::reload_scenarios_info() {
    /* TODO: Stub */
//                              void __thiscall reload_scenarios_info(RGE_Base_Game * this)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?reload_scenarios_info@RGE_Base_Game@@QAEXXZ
//                               RGE_Base_Game::reload_scenarios_info
//                              basegame.cpp:6145 (8)
//         00422fd0     MOV        this,dword ptr [ECX + this->scenario_info]
//         00422fd3     JMP        RGE_Scenario_File_Info::reload_scenarios         void reload_scenarios(RGE_Scenario_File_Info
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//         00422fd8     ??         90h
//         00422fd9     NOP
//         00422fda     NOP
//         00422fdb     NOP
//         00422fdc     NOP
//         00422fdd     NOP
//         00422fde     NOP
//         00422fdf     NOP
    return;
}

void RGE_Base_Game::set_interface_messages() {
    /* TODO: Stub */
//                              void __thiscall set_interface_messages(RGE_Base_Game * this)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?set_interface_messages@RGE_Base_Game@@MAEXXZ                XREF[1]:     0056f010(*)
//                               RGE_Base_Game::set_interface_messages
//                              basegame.cpp:6154 (1)
//         00422fe0     RET
//         00422fe1     ??         90h
//         00422fe2     NOP
//         00422fe3     NOP
//         00422fe4     NOP
//         00422fe5     NOP
//         00422fe6     NOP
//         00422fe7     NOP
//         00422fe8     NOP
//         00422fe9     NOP
//         00422fea     NOP
//         00422feb     NOP
//         00422fec     NOP
//         00422fed     NOP
//         00422fee     NOP
//         00422fef     NOP
    return;
}

void RGE_Base_Game::set_render_all() {
    /* TODO: Stub */
//                              void __thiscall set_render_all(RGE_Base_Game * this)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?set_render_all@RGE_Base_Game@@QAEXXZ                        XREF[9]:     setup_blank_screen:0041f7ca(c),
//                               RGE_Base_Game::set_render_all                                             check_paint:0041ffe7(c),
//                                                                                                         wnd_proc:004209d2(c),
//                                                                                                         wnd_proc:00420a05(c),
//                                                                                                         set_screen_size:00422b86(c),
//                                                                                                         do_command_game:0050a3b9(c),
//                                                                                                         start_video:00523a2e(c),
//                                                                                                         stop_video:00523be3(c),
//                                                                                                         shutdown_video_system:0052a4bf(c)
//                              basegame.cpp:6162 (10)
//         00422ff0     MOV        dword ptr [ECX + this->render_all],0x1
//                              basegame.cpp:6164 (10)
//         00422ffa     MOV        this,panel_system
//         00422fff     JMP        TPanelSystem::set_restore                        void set_restore(TPanelSystem * this)
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//         00423004     ??         90h
//         00423005     NOP
//         00423006     NOP
//         00423007     NOP
//         00423008     NOP
//         00423009     NOP
//         0042300a     NOP
//         0042300b     NOP
//         0042300c     NOP
//         0042300d     NOP
//         0042300e     NOP
//         0042300f     NOP
    return;
}

void RGE_Base_Game::set_prog_mode(int param_1) {
    /* TODO: Stub */
//                              void __thiscall set_prog_mode(RGE_Base_Game * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0041c240(R)
//                               ?set_prog_mode@RGE_Base_Game@@UAEXH@Z                        XREF[2]:     0056eedc(*), 005771b4(*)
//                               RGE_Base_Game::set_prog_mode
//                              basegame.h:309 (13)
//         0041c240     MOV        EAX,dword ptr [ESP + param_1]
//         0041c244     MOV        dword ptr [ECX + this->prog_mode],EAX
//         0041c24a     RET        0x4
//         0041c24d     ??         90h
//         0041c24e     NOP
//         0041c24f     NOP
    return;
}

TPanel* RGE_Base_Game::get_view_panel() {
    /* TODO: Stub */
//                              TPanel * __thiscall get_view_panel(RGE_Base_Game * this)
//              TPanel *          EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?get_view_panel@RGE_Base_Game@@UAEPAVTPanel@@XZ              XREF[1]:     0056eefc(*)
//                               RGE_Base_Game::get_view_panel
//                              basegame.h:394 (3)
//         0041c250     XOR        EAX,EAX
//         0041c252     RET
//         0041c253     ??         90h
//         0041c254     NOP
//         0041c255     NOP
//         0041c256     NOP
//         0041c257     NOP
//         0041c258     NOP
//         0041c259     NOP
//         0041c25a     NOP
//         0041c25b     NOP
//         0041c25c     NOP
//         0041c25d     NOP
//         0041c25e     NOP
//         0041c25f     NOP
    return 0;
}

TPanel* RGE_Base_Game::get_map_panel() {
    /* TODO: Stub */
//                              TPanel * __thiscall get_map_panel(RGE_Base_Game * this)
//              TPanel *          EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?get_map_panel@RGE_Base_Game@@UAEPAVTPanel@@XZ               XREF[1]:     0056ef00(*)
//                               RGE_Base_Game::get_map_panel
//                              basegame.h:395 (3)
//         0041c260     XOR        EAX,EAX
//         0041c262     RET
//         0041c263     ??         90h
//         0041c264     NOP
//         0041c265     NOP
//         0041c266     NOP
//         0041c267     NOP
//         0041c268     NOP
//         0041c269     NOP
//         0041c26a     NOP
//         0041c26b     NOP
//         0041c26c     NOP
//         0041c26d     NOP
//         0041c26e     NOP
//         0041c26f     NOP
    return 0;
}

void RGE_Base_Game::notification(int param_1, long param_2, long param_3, long param_4, long param_5) {
    /* TODO: Stub */
//                              void __thiscall notification(RGE_Base_Game * this, int param_1, long
//              void              <VOID>         <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              long              Stack[0x8]:4   param_2
//              long              Stack[0xc]:4   param_3
//              long              Stack[0x10]:4  param_4
//              long              Stack[0x14]:4  param_5
//                               ?notification@RGE_Base_Game@@UAEXHJJJJ@Z                     XREF[1]:     0056ef10(*)
//                               RGE_Base_Game::notification
//                              basegame.h:457 (3)
//         0041c6e0     RET        0x14
//         0041c6e3     ??         90h
//         0041c6e4     NOP
//         0041c6e5     NOP
//         0041c6e6     NOP
//         0041c6e7     NOP
//         0041c6e8     NOP
//         0041c6e9     NOP
//         0041c6ea     NOP
//         0041c6eb     NOP
//         0041c6ec     NOP
//         0041c6ed     NOP
//         0041c6ee     NOP
//         0041c6ef     NOP
    return;
}

int RGE_Base_Game::processCheatCode(int param_1, char* param_2) {
    /* TODO: Stub */
//                              int __thiscall processCheatCode(RGE_Base_Game * this, int param_1, c
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              char *            Stack[0x8]:4   param_2
//                               ?processCheatCode@RGE_Base_Game@@UAEHHPAD@Z                  XREF[1]:     0056ef24(*)
//                               RGE_Base_Game::processCheatCode
//                              basegame.h:561 (5)
//         0041c6f0     XOR        EAX,EAX
//         0041c6f2     RET        0x8
//         0041c6f5     ??         90h
//         0041c6f6     NOP
//         0041c6f7     NOP
//         0041c6f8     NOP
//         0041c6f9     NOP
//         0041c6fa     NOP
//         0041c6fb     NOP
//         0041c6fc     NOP
//         0041c6fd     NOP
//         0041c6fe     NOP
//         0041c6ff     NOP
    return 0;
}

int RGE_Base_Game::handle_message(tagMSG* param_1) {
    /* TODO: Stub */
//                              int __thiscall handle_message(RGE_Base_Game * this, tagMSG * param_1)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              tagMSG *          Stack[0x4]:4   param_1
//                               ?handle_message@RGE_Base_Game@@MAEHPAUtagMSG@@@Z             XREF[2]:     0056ef88(*), 00577260(*)
//                               RGE_Base_Game::handle_message
//                              basegame.h:615 (8)
//         0041c700     MOV        EAX,0x1
//         0041c705     RET        0x4
//         0041c708     ??         90h
//         0041c709     NOP
//         0041c70a     NOP
//         0041c70b     NOP
//         0041c70c     NOP
//         0041c70d     NOP
//         0041c70e     NOP
//         0041c70f     NOP
    return 0;
}

int RGE_Base_Game::action_update() {
    /* TODO: Stub */
//                              int __thiscall action_update(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?action_update@RGE_Base_Game@@MAEHXZ                         XREF[2]:     0056efc8(*), 005772a0(*)
//                               RGE_Base_Game::action_update
//                              basegame.h:632 (6)
//         0041c710     MOV        EAX,0x1
//         0041c715     RET
//         0041c716     ??         90h
//         0041c717     NOP
//         0041c718     NOP
//         0041c719     NOP
//         0041c71a     NOP
//         0041c71b     NOP
//         0041c71c     NOP
//         0041c71d     NOP
//         0041c71e     NOP
//         0041c71f     NOP
    return 0;
}

int RGE_Base_Game::action_mouse_move(long param_1, long param_2, int param_3, int param_4, int param_5, int param_6) {
    /* TODO: Stub */
//                              int __thiscall action_mouse_move(RGE_Base_Game * this, long param_1,
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1
//              long              Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//              int               Stack[0x14]:4  param_5
//              int               Stack[0x18]:4  param_6
//                               ?action_mouse_move@RGE_Base_Game@@MAEHJJHHHH@Z               XREF[2]:     0056efcc(*), 005772a4(*)
//                               RGE_Base_Game::action_mouse_move
//                              basegame.h:633 (8)
//         0041c720     MOV        EAX,0x1
//         0041c725     RET        0x18
//         0041c728     ??         90h
//         0041c729     NOP
//         0041c72a     NOP
//         0041c72b     NOP
//         0041c72c     NOP
//         0041c72d     NOP
//         0041c72e     NOP
//         0041c72f     NOP
    return 0;
}

int RGE_Base_Game::action_key_down(ulong param_1, int param_2, int param_3, int param_4, int param_5) {
    /* TODO: Stub */
//                              int __thiscall action_key_down(RGE_Base_Game * this, ulong param_1,
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              ulong             Stack[0x4]:4   param_1
//              int               Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//              int               Stack[0x14]:4  param_5
//                               ?action_key_down@RGE_Base_Game@@MAEHKHHHH@Z                  XREF[1]:     0056efd0(*)
//                               RGE_Base_Game::action_key_down
//                              basegame.h:634 (8)
//         0041c730     MOV        EAX,0x1
//         0041c735     RET        0x14
//         0041c738     ??         90h
//         0041c739     NOP
//         0041c73a     NOP
//         0041c73b     NOP
//         0041c73c     NOP
//         0041c73d     NOP
//         0041c73e     NOP
//         0041c73f     NOP
    return 0;
}

int RGE_Base_Game::action_user_command(ulong param_1, ulong param_2) {
    /* TODO: Stub */
//                              int __thiscall action_user_command(RGE_Base_Game * this, ulong param
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              ulong             Stack[0x4]:4   param_1
//              ulong             Stack[0x8]:4   param_2
//                               ?action_user_command@RGE_Base_Game@@MAEHKK@Z                 XREF[1]:     0056efd4(*)
//                               RGE_Base_Game::action_user_command
//                              basegame.h:635 (8)
//         0041c740     MOV        EAX,0x1
//         0041c745     RET        0x8
//         0041c748     ??         90h
//         0041c749     NOP
//         0041c74a     NOP
//         0041c74b     NOP
//         0041c74c     NOP
//         0041c74d     NOP
//         0041c74e     NOP
//         0041c74f     NOP
    return 0;
}

int RGE_Base_Game::action_command(ulong param_1, ulong param_2) {
    /* TODO: Stub */
//                              int __thiscall action_command(RGE_Base_Game * this, ulong param_1, u
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//              ulong             Stack[0x4]:4   param_1
//              ulong             Stack[0x8]:4   param_2
//                               ?action_command@RGE_Base_Game@@MAEHKK@Z                      XREF[2]:     0056efd8(*), 005772b0(*)
//                               RGE_Base_Game::action_command
//                              basegame.h:636 (8)
//         0041c750     MOV        EAX,0x1
//         0041c755     RET        0x8
//         0041c758     ??         90h
//         0041c759     NOP
//         0041c75a     NOP
//         0041c75b     NOP
//         0041c75c     NOP
//         0041c75d     NOP
//         0041c75e     NOP
//         0041c75f     NOP
    return 0;
}

int RGE_Base_Game::action_music_done() {
    /* TODO: Stub */
//                              int __thiscall action_music_done(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?action_music_done@RGE_Base_Game@@MAEHXZ                     XREF[2]:     0056efdc(*), 005772b4(*)
//                               RGE_Base_Game::action_music_done
//                              basegame.h:637 (6)
//         0041c760     MOV        EAX,0x1
//         0041c765     RET
//         0041c766     ??         90h
//         0041c767     NOP
//         0041c768     NOP
//         0041c769     NOP
//         0041c76a     NOP
//         0041c76b     NOP
//         0041c76c     NOP
//         0041c76d     NOP
//         0041c76e     NOP
//         0041c76f     NOP
    return 0;
}

int RGE_Base_Game::action_activate() {
    /* TODO: Stub */
//                              int __thiscall action_activate(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?action_activate@RGE_Base_Game@@MAEHXZ                       XREF[2]:     0056efe0(*), 005772b8(*)
//                               RGE_Base_Game::action_activate
//                              basegame.h:638 (6)
//         0041c770     MOV        EAX,0x1
//         0041c775     RET
//         0041c776     ??         90h
//         0041c777     NOP
//         0041c778     NOP
//         0041c779     NOP
//         0041c77a     NOP
//         0041c77b     NOP
//         0041c77c     NOP
//         0041c77d     NOP
//         0041c77e     NOP
//         0041c77f     NOP
    return 0;
}

int RGE_Base_Game::action_deactivate() {
    /* TODO: Stub */
//                              int __thiscall action_deactivate(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?action_deactivate@RGE_Base_Game@@MAEHXZ                     XREF[2]:     0056efe4(*), 005772bc(*)
//                               RGE_Base_Game::action_deactivate
//                              basegame.h:639 (6)
//         0041c780     MOV        EAX,0x1
//         0041c785     RET
//         0041c786     ??         90h
//         0041c787     NOP
//         0041c788     NOP
//         0041c789     NOP
//         0041c78a     NOP
//         0041c78b     NOP
//         0041c78c     NOP
//         0041c78d     NOP
//         0041c78e     NOP
//         0041c78f     NOP
    return 0;
}

int RGE_Base_Game::action_init_menu() {
    /* TODO: Stub */
//                              int __thiscall action_init_menu(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?action_init_menu@RGE_Base_Game@@MAEHXZ                      XREF[2]:     0056efe8(*), 005772c0(*)
//                               RGE_Base_Game::action_init_menu
//                              basegame.h:640 (6)
//         0041c790     MOV        EAX,0x1
//         0041c795     RET
//         0041c796     ??         90h
//         0041c797     NOP
//         0041c798     NOP
//         0041c799     NOP
//         0041c79a     NOP
//         0041c79b     NOP
//         0041c79c     NOP
//         0041c79d     NOP
//         0041c79e     NOP
//         0041c79f     NOP
    return 0;
}

int RGE_Base_Game::action_exit_menu() {
    /* TODO: Stub */
//                              int __thiscall action_exit_menu(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?action_exit_menu@RGE_Base_Game@@MAEHXZ                      XREF[2]:     0056efec(*), 005772c4(*)
//                               RGE_Base_Game::action_exit_menu
//                              basegame.h:641 (6)
//         0041c7a0     MOV        EAX,0x1
//         0041c7a5     RET
//         0041c7a6     ??         90h
//         0041c7a7     NOP
//         0041c7a8     NOP
//         0041c7a9     NOP
//         0041c7aa     NOP
//         0041c7ab     NOP
//         0041c7ac     NOP
//         0041c7ad     NOP
//         0041c7ae     NOP
//         0041c7af     NOP
    return 0;
}

int RGE_Base_Game::action_size() {
    /* TODO: Stub */
//                              int __thiscall action_size(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?action_size@RGE_Base_Game@@MAEHXZ                           XREF[2]:     0056eff0(*), 005772c8(*)
//                               RGE_Base_Game::action_size
//                              basegame.h:642 (6)
//         0041c7b0     MOV        EAX,0x1
//         0041c7b5     RET
//         0041c7b6     ??         90h
//         0041c7b7     NOP
//         0041c7b8     NOP
//         0041c7b9     NOP
//         0041c7ba     NOP
//         0041c7bb     NOP
//         0041c7bc     NOP
//         0041c7bd     NOP
//         0041c7be     NOP
//         0041c7bf     NOP
    return 0;
}

int RGE_Base_Game::action_close() {
    /* TODO: Stub */
//                              int __thiscall action_close(RGE_Base_Game * this)
//              int               EAX:4          <RETURN>
//              RGE_Base_Game *   ECX:4 (auto)   this
//                               ?action_close@RGE_Base_Game@@MAEHXZ                          XREF[1]:     0056eff4(*)
//                               RGE_Base_Game::action_close
//                              basegame.h:643 (6)
//         0041c7c0     MOV        EAX,0x1
//         0041c7c5     RET
//         0041c7c6     ??         90h
//         0041c7c7     NOP
//         0041c7c8     NOP
//         0041c7c9     NOP
//         0041c7ca     NOP
//         0041c7cb     NOP
//         0041c7cc     NOP
//         0041c7cd     NOP
//         0041c7ce     NOP
//         0041c7cf     NOP
    return 0;
}