// VA: 0041D0A0 RGE_Base_Game::setup_cmd_options (5726 B)
// PDB source: basegame.cpp lines 1646-2199
//
// attempt log:
// v3: full function with all extern game function calls, trying to close the size gap
// v2: Ghidra-like iVar2 pattern â€” 5568 bytes (too small)
// v1: first-pass full body â€” 5664-5680 bytes
// missing: game func calls 0047F580, 004362B0, 00436330, 004362F0, 004227F0
// v4: fixed VC5-incompatible __thiscall extern declarations by modeling member calls.
// v5: changed local buffers to 256+256; stack frame moved from 0x208 to target family.
// v6: identified _mbsninc(ptr,1) (two-arg) vs _mbsinc(ptr); restores full-size family with 42 calls.
// v7: changed MBCS helper surface to char* and removed unsigned casts; current build is 5712 bytes, 14 short, with compiler choosing edi=this/ebp=1 and 0x204 frame instead of original ebp=this/edi=1 and 0x200 frame.
// lab 20260429_114927: mbs_surface/local_shape/null_style axes collapsed to same 5712-byte asm; unsigned casts and local order are not the current lever.
// probe: replacing literal constants with broken uninitialized one/zero accidentally forced ebp=this but introduced 0x204 frame/stale local load, so useful clue only: register pressure around constant one/zero controls this-register choice.
// lab 20260429_120746: tried matched-function lesson from 0040D3B0 (early named zero/one temps, macro-assignment variants); all 36 compiled variants collapsed to same 5712-byte edi=this/ebp=1 group.
// probe: direct strstr() conditions changed early cmp eax,ebx to original-like test eax,eax, but did not move prologue/register assignment or size.
// lab 20260429_121211: header/import and useless declaration context axes (manual vs string/stdlib, mbstring, windows; extra CRT/WinAPI/game decls; extra class members/virtuals) produced 4 asm groups, all 5712 bytes and same first mismatch sub esp 204/edi=this. windows.h context had better edit diff (~7352 vs 9223) but did not fix prologue.
// probe: broken uninitialized register one/zero forced original-like ebp=this but kept sub esp,204; a valid initialized register self+one form rechecked later still compiled to edi=this with the 0x204 frame. Useful clue only: register pressure can move this, but the valid source surface has not.
// TU probe: target-first basegame.cpp reconstruction axes (#line 1646 donor path, windows/string/stdlib context via prior representative, and a real-vptr/full virtual RGE_Base_Game surface with gap_04[8]) all stayed in the same 5712-byte sub esp,204 / edi=this basin. Full TU declarations before the body are not the missing prologue lever so far.
// paste-test 20260429: inspected current stack refs; the extra 4-byte slot is [esp+14] holding spilled this (mov [esp+14],edi; later reload after pushes), not a pcVar3/iVar2 slot near [esp+210]. Tested no broad temporaries/direct strstr/scoped parse pointer/name p/result return/result-for-ones variants; all valid variants stayed 5712 bytes with sub esp,204 and edi=this. Pointer-first while condition shrank to 5552 and still kept sub esp,204, so rolled back.
// paste-test 2: valid game=this alias variants (before buffers, after buffers, register) did not change prologue. Prefix bisection: prefixes through SPEED2/NOMUSIC keep sub esp,200; adding auto custom_mouse flips to sub esp,204, but deleting the final three tail blocks together from full restores sub esp,200/ebp=this while deleting any one tail block does not. Rewriting NOMUSIC/auto/NORMALMOUSE as direct/nested/truthy/1-left did not alter the full prologue.
// next probes: changing long-lived 1 spelling (int one assigned separately, const int, enum, expression after CharUpper, 1U/(unsigned)1/sizeof(char)/true for MBCS counts, int count declarations) and final auto assignment variants (assign full_screen/use_dir_draw/inc) all stayed in the same sub esp,204 / edi=this / hidden-home basin. The flip appears to be whole-function register-pressure threshold, not a single literal spelling.
// natural tail-shape lab: 78 variants across NOMUSIC/auto/NORMALMOUSE direct/nested/empty-else/prog-local/order-preserving combined forms all stayed sub esp,204. Reordering late blocks so the SPEED1/SPEED2 parse blocks move after NOMUSIC/auto/NORMALMOUSE flips to good sub esp,200/ebp=this but changes source/call order and text size 5728, so it is only a clue: speed parse + final tail adjacency is the pressure trigger.
// speed/tail iteration: SPEED1/SPEED2 natural parse variants (scoped p, assignment-in-if, for/while/no-brace, pointer-first condition, char temp, value temp, &tempStr) and mixes all stayed sub esp,204. Combining direct/scoped cleanup with nested tail stayed bad. Caching tail predicate values before SPEED flips ebp=this but adds stack locals/frame 204, so not usable; ternary/flag final-tail forms stayed bad.
// focused late-region classifier lab: 120 combinations over speed scope/shape (current/braces/scoped p/assign-if/for), tail scope/shape (current/braces/direct/nested/prog-local), and one/zero spelling (none/result/enum/local zero-one) produced no target-basin hits; every order-preserving variant kept frame 204, this=edi, zero=ebx, one=ebp, hidden home. See build/temp/focused_late_region_lab_summary.txt.
// progress 20260429: cast all _ismbcspace inputs to (unsigned char)*pcVar3. This matches original zero-extend loop idiom family and brings object text size to exact 5726 bytes; remaining mismatch still starts at prologue (rebuilt frame 204/edi=this/ebp=1/hidden this home vs original frame 200/ebp=this/edi=1).
// tail-order clue rechecked after unsigned _ismbcspace casts: build/temp/0041D0A0_order_tail_before_speeds.cpp moves NOMUSIC/auto/NORMALMOUSE before SPEED1/SPEED2 and gets frame 200/ebp=this/no hidden home, with exact size 5726 and first mismatch at 0x2C. It still chooses xor edi,edi and materializes one in ebx later, and it changes option parse order, so it is a pressure clue only, not a keepable fix.
// probes after the cast: scoped SPEED1/SPEED2 local p, final-tail pcVar3 reuse, and local declaration order variants all stayed in the bad frame 204/edi=this basin. Re-running tailnatural_probe after casts found no order-preserving tail-shape hit; individual tail rewrites generally became 5728 bytes and still had hidden this home.
// deeper tail probe: deleting any one of SPEED1, SPEED2, NOMUSIC, auto-custom-mouse, or NORMALMOUSE is enough to restore the original prologue, so the current full tail is just over a global pressure cliff. A non-equivalent clue variant changing auto-custom-mouse to `(use_dir_draw + full_screen) == 2` also restores frame 200/ebp=this/ebx=0/edi=1 and exact size 5726; with first five early OR checks spelled direct it matches the early test-eax family too, but the auto expression is not binary-observed tail behavior and was not kept. See build/temp/0041D0A0_autosum_direct5.cpp.
// continued auto-tail search: faithful spellings `1 ==`, reversed compare order, nested ifs, `!(x != 1)`, bitwise `&` of comparisons, and empty-else forms all stayed in the bad 204-frame basin. A semantically guarded pressure form `((use_dir_draw + full_screen) == 2 && use_dir_draw == 1 && full_screen == 1)` restores the prologue/size, but adds extra tail reads/tests and still mismatches early at 0x53 (or 0x44 with broader direct-OR rewrites), so not kept.
// more non-kept probes: auto assignment RHS variants (`= use_dir_draw`, `= full_screen`, bool/product/sum-derived) did not move prologue. Boolean-sum auto conditions like `((use_dir_draw == 1) + (full_screen == 1)) == 2` restore prologue but generate non-original tail logic. Bracing/clearing state across the SPEED2->NOMUSIC boundary had no effect. Converting all/simple groups of triple OR checks to direct `strstr(...) || ...` improves local test-eax shape but alone does not fix the prologue.
// progress 20260429: corrected the visible command-option string spelling to match the original string triplets (compact, spaced, underscored) and rewrote '=' scans with an explicit cVar1 like Ghidra/source; codegen is unchanged (still exact size 5726, first mismatch prologue sub esp 204/edi=this hidden-home). Tested strstr-as-int surface and /G5 flag as probes; both were codegen-identical, so not kept as special context.

extern "C" {
char* __cdecl strstr(const char* str, const char* substr);
char* __cdecl strncpy(char* dest, const char* src, unsigned int count);
long __cdecl atol(const char* str);
char* __cdecl _mbsstr(const char* str, const char* substr);
char* __cdecl _mbsninc(const char* str, unsigned int count);
int __cdecl _ismbcspace(unsigned int c);
char* __cdecl _mbsncat(char* dst, const char* src, unsigned int count);
}

// Game function declarations matching original asm calls
void __cdecl RESFILE_Set_Missing_Flag(int flag);

extern "C" {
TDebuggingLog* g_L;                                       // 62C4FC â€” global debugLog pointer
}

// Module globals
extern "C" {
extern int all_cp;
extern int do_run_log;
extern int do_debug_timeGetTime;
extern int do_fixed_update;
extern int debug_timeGetTime_interval;
extern int fixed_update_time;
extern int useComputerPlayers;
extern int startLoggingAI;
extern int logStatusOn;
extern int allowAIToCheat;
extern int chatCheatCodes;
extern int logUpdateChanges;
extern int useInfluencePlacement;
extern int all_grassland_on;
extern int numberPathingIterations;
extern int useNewPathing;
extern int pathingCapValue;
extern int force_cd;
extern int do_fps_log;
extern int Sys_DDLOG_Enable;
extern int Sys_DDLOG_ErrorOn;
extern int DDlogAutoFlush;
extern int debug_log_lock;
extern int do_debug_random;
extern int debugActions;
extern int resend_adj1;
extern int resend_adj2;
extern int specificAIPlayerToLog;
extern int logDebugID;
extern int speed_val1;
extern int speed_val2;
extern int do_draw_log;
extern int safe_draw_log;
extern char draw_log_name[260];
extern unsigned char shape_file_first;
extern unsigned char sound_file_first;
extern int log_output;
extern int DDSys_CanColorFill;
extern unsigned char do_color_log;
}

int RGE_Base_Game::setup_cmd_options()
{
    char cmdLine[256];
    char tempStr[256];
    char cVar1;
    char* pcVar3;

    strncpy(cmdLine, this->prog_info->cmd_line, 0xFF);
    cmdLine[0xFF] = 0;
    CharUpperA(cmdLine);

    // NOSTARTUP
    if ((strstr(cmdLine, "NOSTARTUP") != 0) || (strstr(cmdLine, "NO STARTUP") != 0) || (strstr(cmdLine, "NO_STARTUP") != 0)) {
        this->prog_info->skip_startup = 1;
    }

    // SYSTEMMEMORY
    if ((strstr(cmdLine, "SYSTEMMEMORY") != 0) || (strstr(cmdLine, "SYSTEM MEMORY") != 0) || (strstr(cmdLine, "SYSTEM_MEMORY") != 0)) {
        this->prog_info->use_sys_mem = 1;
    }

    // MIDIMUSIC
    if ((strstr(cmdLine, "MIDIMUSIC") != 0) || (strstr(cmdLine, "MIDI MUSIC") != 0) || (strstr(cmdLine, "MIDI_MUSIC") != 0)) {
        this->prog_info->use_music = 1;
        this->prog_info->use_cd_audio = 0;
        this->prog_info->use_ima = 0;
        this->prog_info->use_midi = 1;
        this->prog_info->use_wave_music = 0;
    }

    // MSYNC
    if (strstr(cmdLine, "MSYNC") != 0) {
        this->mouse_blit_sync = 1;
    }

    // MFILL
    DDSys_CanColorFill = (strstr(cmdLine, "MFILL") == 0);

    // NOSOUND
    if ((strstr(cmdLine, "NOSOUND") != 0) || (strstr(cmdLine, "NO SOUND") != 0) || (strstr(cmdLine, "NO_SOUND") != 0)) {
        this->prog_info->use_sound = 0;
    }

    // 640
    if (strstr(cmdLine, "640") != 0) {
        this->prog_info->main_wid = 0x280;
        this->prog_info->main_hgt = 0x1E0;
    }

    // 800
    if (strstr(cmdLine, "800") != 0) {
        this->prog_info->main_wid = 800;
        this->prog_info->main_hgt = 600;
    }

    // 1024
    if (strstr(cmdLine, "1024") != 0) {
        this->prog_info->main_wid = 0x400;
        this->prog_info->main_hgt = 0x300;
    }

    // ALLCP
    if (strstr(cmdLine, "ALLCP") != 0) {
        all_cp = 1;
        do_run_log = 1;
        this->comm_speed = 0;
        do_debug_timeGetTime = 1;
        debug_timeGetTime_interval = 10;
        do_fixed_update = 1;
        fixed_update_time = 20;
    }

    // RESEND1=value
    pcVar3 = _mbsstr(cmdLine, "RESEND1");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        tempStr[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(tempStr, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        resend_adj1 = atol(tempStr);
    }

    // RESEND2=value
    pcVar3 = _mbsstr(cmdLine, "RESEND2");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        tempStr[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(tempStr, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        resend_adj2 = atol(tempStr);
    }

    // NOMOUSE
    if ((strstr(cmdLine, "NOMOUSE") != 0) || (strstr(cmdLine, "NO_MOUSE") != 0)) {
        this->custom_mouse = 0;
    }

    // WING
    if (strstr(cmdLine, "WING") != 0) {
        this->prog_info->full_screen = 0;
        this->prog_info->use_dir_draw = 0;
    }

    // DIRECTDRAW
    if ((strstr(cmdLine, "DIRECTDRAW") != 0) || (strstr(cmdLine, "DIRECT DRAW") != 0)) {
        this->prog_info->use_dir_draw = 1;
    }

    // FULLSCREEN
    if ((strstr(cmdLine, "FULLSCREEN") != 0) || (strstr(cmdLine, "FULL SCREEN") != 0) || (strstr(cmdLine, "FULL_SCREEN") != 0)) {
        this->prog_info->full_screen = 1;
        this->prog_info->use_dir_draw = 1;
    }

    // VIDEOMEMORY
    if ((strstr(cmdLine, "VIDEOMEMORY") != 0) || (strstr(cmdLine, "VIDEO MEMORY") != 0) || (strstr(cmdLine, "VIDEO_MEMORY") != 0)) {
        this->prog_info->use_sys_mem = 0;
    }

    // STREAMMUSIC
    if ((strstr(cmdLine, "STREAMMUSIC") != 0) || (strstr(cmdLine, "STREAM MUSIC") != 0) || (strstr(cmdLine, "STREAM_MUSIC") != 0)) {
        this->prog_info->use_music = 1;
        this->prog_info->use_cd_audio = 0;
        this->prog_info->use_ima = 0;
        this->prog_info->use_midi = 0;
        this->prog_info->use_wave_music = 1;
    }

    // IMAMUSIC
    if ((strstr(cmdLine, "IMAMUSIC") != 0) || (strstr(cmdLine, "IMA MUSIC") != 0) || (strstr(cmdLine, "IMA_MUSIC") != 0)) {
        this->prog_info->use_music = 1;
        this->prog_info->use_cd_audio = 0;
        this->prog_info->use_ima = 1;
        this->prog_info->use_midi = 0;
        this->prog_info->use_wave_music = 0;
    }

    // FASTVIEW
    if ((strstr(cmdLine, "FASTVIEW") != 0) || (strstr(cmdLine, "FAST VIEW") != 0) || (strstr(cmdLine, "FAST_VIEW") != 0)) {
        this->prog_info->fast_view = 1;
    }

    // SLOWVIEW
    if ((strstr(cmdLine, "SLOWVIEW") != 0) || (strstr(cmdLine, "SLOW VIEW") != 0) || (strstr(cmdLine, "SLOW_VIEW") != 0)) {
        this->prog_info->fast_view = 0;
    }

    // ONEBUTTON
    if ((strstr(cmdLine, "ONEBUTTON") != 0) || (strstr(cmdLine, "ONE BUTTON") != 0) || (strstr(cmdLine, "ONE_BUTTON") != 0)) {
        this->prog_info->interface_style = 1;
    }

    // TWOBUTTON
    if ((strstr(cmdLine, "TWOBUTTON") != 0) || (strstr(cmdLine, "TWO BUTTON") != 0) || (strstr(cmdLine, "TWO_BUTTON") != 0)) {
        this->prog_info->interface_style = 2;
    }

    // RUNLOG
    if (strstr(cmdLine, "RUNLOG")) {
        do_run_log = 1;
    }

    // SYNCMSG
    if (strstr(cmdLine, "SYNCMSG")) {
        this->comm_syncmsg = 1;
    }

    // DROPPACKETS
    if (strstr(cmdLine, "DROPPACKETS")) {
        this->comm_droppackets = 1;
    }

    // NOCOMMSPEED
    if (strstr(cmdLine, "NOCOMMSPEED")) {
        this->comm_speed = 0;
    }

    // SYNCSTOP
    if (strstr(cmdLine, "SYNCSTOP")) {
        this->comm_syncstop = 1;
    }

    // STEPMODE
    if (strstr(cmdLine, "STEPMODE")) {
        this->comm_stepmode = 1;
    }

    // SQUAREOUTLINE
    if ((strstr(cmdLine, "SQUAREOUTLINE") != 0) || (strstr(cmdLine, "SQUARE OUTLINE") != 0) || (strstr(cmdLine, "SQUARE_OUTLINE") != 0)) {
        this->outline_type = 0;
    }

    // CUBEOUTLINE
    if ((strstr(cmdLine, "CUBEOUTLINE") != 0) || (strstr(cmdLine, "CUBE OUTLINE") != 0) || (strstr(cmdLine, "CUBE_OUTLINE") != 0)) {
        this->outline_type = 1;
    }

    // GROUNDOUTLINE
    if ((strstr(cmdLine, "GROUNDOUTLINE") != 0) || (strstr(cmdLine, "GROUND OUTLINE") != 0) || (strstr(cmdLine, "GROUND_OUTLINE") != 0)) {
        this->outline_type = 2;
    }

    // EDGEOUTLINE
    if ((strstr(cmdLine, "EDGEOUTLINE") != 0) || (strstr(cmdLine, "EDGE OUTLINE") != 0) || (strstr(cmdLine, "EDGE_OUTLINE") != 0)) {
        this->outline_type = 3;
    }

    // CUSTOMMOUSE
    if ((strstr(cmdLine, "CUSTOMMOUSE") != 0) || (strstr(cmdLine, "CUSTOM MOUSE") != 0) || (strstr(cmdLine, "CUSTOM_MOUSE") != 0)) {
        this->custom_mouse = 1;
    }

    // NOCP
    if (strstr(cmdLine, "NOCP")) {
        useComputerPlayers = 0;
    }

    // LOGAI
    if (strstr(cmdLine, "LOGAI")) {
        startLoggingAI = 1;
    }

    // NOLOGSTATUS
    if (strstr(cmdLine, "NOLOGSTATUS")) {
        logStatusOn = 0;
    }

    // DOLOGSTATUS
    if (strstr(cmdLine, "DOLOGSTATUS")) {
        logStatusOn = 1;
    }

    // NOAICHEAT
    if (strstr(cmdLine, "NOAICHEAT")) {
        allowAIToCheat = 0;
    }

    // NOCHATCHEATCODES
    if (strstr(cmdLine, "NOCHATCHEATCODES")) {
        chatCheatCodes = 0;
    }

    // LOGUPDATECHANGES
    if (strstr(cmdLine, "LOGUPDATECHANGES")) {
        logUpdateChanges = 1;
    }

    // UIP
    if (strstr(cmdLine, "UIP")) {
        useInfluencePlacement = 1;
    }

    // ALLGRASS
    if (strstr(cmdLine, "ALLGRASS")) {
        all_grassland_on = 1;
    }

    // ALLCP
    if (strstr(cmdLine, "ALLCP")) {
        all_cp = 1;
    }

    // ALLCP1
    if (strstr(cmdLine, "ALLCP1")) {
        all_cp = 2;
    }

    // NOPATHLIMIT
    if (strstr(cmdLine, "NOPATHLIMIT")) {
        numberPathingIterations = -1;
    }

    // UNP
    if (strstr(cmdLine, "UNP")) {
        useNewPathing = -1;
    }

    // COLORLOG
    if (strstr(cmdLine, "COLORLOG")) {
        do_color_log = 1;
    }

    // LOGAI=value
    pcVar3 = _mbsstr(cmdLine, "LOGAI");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        tempStr[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(tempStr, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        specificAIPlayerToLog = atol(tempStr);
    }

    // LOGDEBUG=value
    pcVar3 = _mbsstr(cmdLine, "LOGDEBUG");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        tempStr[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(tempStr, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        logDebugID = atol(tempStr);
    }

    // NOPATHCAP
    if (strstr(cmdLine, "NOPATHCAP")) {
        pathingCapValue = -1;
    }

    // GAMECD
    if (strstr(cmdLine, "GAMECD")) {
        force_cd = 1;
    }

    // 1280
    if (strstr(cmdLine, "1280")) {
        this->prog_info->main_wid = 0x500;
        this->prog_info->main_hgt = 0x400;
    }

    // LOGFPS
    if ((strstr(cmdLine, "LOGFPS") != 0) || (strstr(cmdLine, "LOG FPS") != 0) || (strstr(cmdLine, "LOG_FPS") != 0)) {
        do_fps_log = 1;
    }

    // DDERRORLOG
    if (strstr(cmdLine, "DDERRORLOG")) {
        Sys_DDLOG_Enable = 1;
        Sys_DDLOG_ErrorOn = 1;
    }

    // DDLOG
    if (strstr(cmdLine, "DDLOG")) {
        Sys_DDLOG_Enable = 1;
        Sys_DDLOG_ErrorOn = 0;
    }

    // DDFLUSHLOG
    if (strstr(cmdLine, "DDFLUSHLOG")) {
        DDlogAutoFlush = 1;
    }

    // DDNOFLUSHLOG
    if (strstr(cmdLine, "DDNOFLUSHLOG")) {
        DDlogAutoFlush = 0;
    }

    // DDLOCKLOG
    if (strstr(cmdLine, "DDLOCKLOG")) {
        debug_log_lock = 1;
    }

    // LOGRANDOM
    if (strstr(cmdLine, "LOGRANDOM")) {
        do_debug_random = 1;
    }

    // FIXEDUPDATE
    if (strstr(cmdLine, "FIXEDUPDATE")) {
        do_debug_timeGetTime = 1;
        do_fixed_update = 1;
    }

    // LOGACTION
    if (strstr(cmdLine, "LOGACTION")) {
        debugActions = 1;
    }

    // RES_WARN
    if (strstr(cmdLine, "RES_WARN")) {
        RESFILE_Set_Missing_Flag(1);
    }

    // SCENARIOS=value
    pcVar3 = _mbsstr(cmdLine, "SCENARIOS");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        this->prog_info->scenario_dir[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(this->prog_info->scenario_dir, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        _mbsncat(this->prog_info->scenario_dir, "\\", 1);
    }

    // WORLD=value
    pcVar3 = _mbsstr(cmdLine, "WORLD");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        this->prog_info->world_db_file[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(this->prog_info->world_db_file, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
    }

    // FIXEDUPDATE=value
    pcVar3 = _mbsstr(cmdLine, "FIXEDUPDATE");
    if (pcVar3) {
        do_debug_timeGetTime = 1;
        do_fixed_update = 1;
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        tempStr[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(tempStr, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        fixed_update_time = atol(tempStr);
    }

    // AISPEED=value
    pcVar3 = _mbsstr(cmdLine, "AISPEED");
    if (pcVar3) {
        do_debug_timeGetTime = 1;
        do_fixed_update = 1;
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        tempStr[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(tempStr, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        debug_timeGetTime_interval = atol(tempStr);
    }

    // RANDOMGAME=value
    pcVar3 = _mbsstr(cmdLine, "RANDOMGAME");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        tempStr[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(tempStr, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        this->random_game_seed = atol(tempStr);
    }

    // RANDOMMAP=value
    pcVar3 = _mbsstr(cmdLine, "RANDOMMAP");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        tempStr[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(tempStr, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        this->random_map_seed = atol(tempStr);
    }

    // DRAWLOG=value
    pcVar3 = _mbsstr(cmdLine, "DRAWLOG");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        draw_log_name[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(draw_log_name, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
    }

    // DRAWLOG (boolean)
    if (strstr(cmdLine, "DRAWLOG")) {
        do_draw_log = 1;
    }

    // SAFEDRAWLOG
    if (strstr(cmdLine, "SAFEDRAWLOG")) {
        safe_draw_log = 1;
    }

    // DATA=value
    pcVar3 = _mbsstr(cmdLine, "DATA");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        this->prog_info->game_data_file[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(this->prog_info->game_data_file, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
    }

    // CDAUDIO
    if ((strstr(cmdLine, "CDAUDIO") != 0) || (strstr(cmdLine, "CD AUDIO") != 0) || (strstr(cmdLine, "CD_AUDIO") != 0)) {
        this->prog_info->use_music = 1;
        this->prog_info->use_cd_audio = 1;
        this->prog_info->use_ima = 0;
        this->prog_info->use_midi = 0;
        this->prog_info->use_wave_music = 0;
    }

    // WINDOW
    if (strstr(cmdLine, "WINDOW")) {
        this->prog_info->full_screen = 0;
    }

    // FILEFIRST
    if ((strstr(cmdLine, "FILEFIRST") != 0) || (strstr(cmdLine, "FILE FIRST") != 0) || (strstr(cmdLine, "FILE_FIRST") != 0)) {
        shape_file_first = 1;
        sound_file_first = 1;
    }

    // LOGCOMM
    if (((strstr(cmdLine, "LOGCOMM") != 0) || (strstr(cmdLine, "LOG COMM") != 0) || (strstr(cmdLine, "LOG_COMM") != 0)) &&
        (this->log_comm = 1, g_L != 0)) {
        g_L->LogFile(1);
        g_L->LogTimestamp(1);
    }

    // LOGOUTPUT
    if (((strstr(cmdLine, "LOGOUTPUT") != 0) || (strstr(cmdLine, "LOG OUTPUT") != 0) || (strstr(cmdLine, "LOG_OUTPUT") != 0)) &&
        (log_output = 1, g_L != 0)) {
        g_L->LogOutput(1);
    }

    // DEVELOPER
    if (strstr(cmdLine, "DEVELOPER")) {
        this->setGameDeveloperMode(1);
    }

    // SPEED1=value
    pcVar3 = _mbsstr(cmdLine, "SPEED1");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        tempStr[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(tempStr, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        speed_val1 = atol(tempStr);
    }

    // SPEED2=value
    pcVar3 = _mbsstr(cmdLine, "SPEED2");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        tempStr[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(tempStr, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        speed_val2 = atol(tempStr);
    }

    // NOMUSIC (conditional)
    if (this->prog_info->use_sound == 0 ||
        strstr(cmdLine, "NOMUSIC") != 0 ||
        strstr(cmdLine, "NO MUSIC") != 0 ||
        strstr(cmdLine, "NO_MUSIC") != 0) {
        this->prog_info->use_music = 0;
    }

    // Auto custom_mouse for fullscreen direct draw
    if (this->prog_info->use_dir_draw == 1 && this->prog_info->full_screen == 1) {
        this->custom_mouse = 1;
    }

    // NORMALMOUSE
    if ((strstr(cmdLine, "NORMALMOUSE") != 0) || (strstr(cmdLine, "NORMAL MOUSE") != 0) || (strstr(cmdLine, "NORMAL_MOUSE") != 0)) {
        this->custom_mouse = 0;
    }

    return 1;
}
