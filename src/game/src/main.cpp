#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <excpt.h>
#include "../include/TRIBE_Game.h"
#include "../include/RGE_Prog_Info.h"
#include "../include/custom_debug.h"

// ASSUMPTION: GUID values are reconstructed from assembly initialization logic at 0x00454c17.
// _TRIBE_GUID: F2E846A8-08F5-0797-11D1EBE2-60009B83
const _GUID AGE1_TRIBE_GUID = { 0xF2E846A8, 0x08F5, 0x0797, { 0x11, 0xD1, 0xEB, 0xE2, 0x60, 0x00, 0x9B, 0x83 } };
// _ZONE_GUID: F2E846AA-08F5-0797-11D1EBE2-60009B83
const _GUID AGE1_ZONE_GUID  = { 0xF2E846AA, 0x08F5, 0x0797, { 0x11, 0xD1, 0xEB, 0xE2, 0x60, 0x00, 0x9B, 0x83 } };

static int aoe_log_unhandled_exception(EXCEPTION_POINTERS* ep) {
CUSTOM_DEBUG_BEGIN
    if (!ep || !ep->ExceptionRecord) {
        CUSTOM_DEBUG_ERROR(-1, "Unhandled exception (missing exception record)");
        return EXCEPTION_EXECUTE_HANDLER;
    }

    const DWORD code = ep->ExceptionRecord->ExceptionCode;
    const void* addr = ep->ExceptionRecord->ExceptionAddress;
    CUSTOM_DEBUG_LOG_FMT("UNHANDLED_EXCEPTION code=0x%08lX address=%p flags=0x%08lX",
                         (unsigned long)code, addr, (unsigned long)ep->ExceptionRecord->ExceptionFlags);

    if (ep->ContextRecord) {
        CUSTOM_DEBUG_LOG_FMT("UNHANDLED_EXCEPTION regs: EIP=0x%08lX ESP=0x%08lX EBP=0x%08lX",
                             (unsigned long)ep->ContextRecord->Eip,
                             (unsigned long)ep->ContextRecord->Esp,
                             (unsigned long)ep->ContextRecord->Ebp);
    }
CUSTOM_DEBUG_END
    return EXCEPTION_EXECUTE_HANDLER;
}

static LONG WINAPI aoe_unhandled_exception_filter(EXCEPTION_POINTERS* ep) {
    aoe_log_unhandled_exception(ep);
    return EXCEPTION_EXECUTE_HANDLER;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_INIT();
    CUSTOM_DEBUG_CHECKPOINT("WinMain Entry");
    CUSTOM_DEBUG_LOG_FMT("CmdLine: %s", lpCmdLine ? lpCmdLine : "(null)");
CUSTOM_DEBUG_END

    // Non-original safety/debug hook:
    // ensure hard faults are recorded in `decomp_debug.log` before process exit.
    SetUnhandledExceptionFilter(aoe_unhandled_exception_filter);

    RGE_Prog_Info info;
    memset(&info, 0, sizeof(info));

    // main.cpp:74
    strcpy(info.prog_title, "Age of Empires, Roman Expansion");
    // main.cpp:75
    strcpy(info.prog_version, "00.03.01.0717");
    
    // main.cpp:76
    sprintf(info.prog_name, "%s", info.prog_title);
    
    // main.cpp:77
    strcpy(info.world_db_file, "tr_wrld.txt");
    // main.cpp:83
    strcpy(info.game_data_file, "data2\\empires.dat");

    // main.cpp:86
    strcpy(info.registry_key, "Software\\Microsoft\\Games\\Age of Empires\\1.0");

    info.instance = hInstance;
    info.prev_instance = hPrevInstance;
    
    // main.cpp:108
    if (lpCmdLine) {
        strncpy(info.cmd_line, lpCmdLine, sizeof(info.cmd_line) - 1);
    }
    
    info.show_wnd_flag = nShowCmd;
    
    // main.cpp:134
    strcpy(info.icon_name, "AppIcon");
    // main.cpp:153 (Offset 0x649)
    strcpy(info.menu_name, "AOE");
    // main.cpp:153 (Offset 0x672)
    strcpy(info.pal_file, "palette");
    // main.cpp:153 (Offset 0x777)
    strcpy(info.cursor_file, "mcursors");

    // main.cpp:153 (Scalar initializations)
    // NOTE: ASM stores integer 84 (0x54) into these float fields.
    info.mouse_scroll_max_dist = 84.0f; // TODO: verify if should be integer bit-pattern 0x54
    info.key_scroll_max_dist = 84.0f; 
    
    info.game_guid = AGE1_TRIBE_GUID;
    info.zone_guid = AGE1_ZONE_GUID;
    
    info.verify_cd = 0;
    info.max_players_per_cd = 1;
    info.check_expiration = 8;
    info.expire_month = 0;
    info.expire_year = 0;
    info.update_interval = 0;
    info.check_multi_copies = 1;
    info.skip_startup = 1;
    info.full_screen = 1;
    info.fixed_window_size = 1;
    info.use_dir_draw = 1;
    info.use_sys_mem = 1;
    info.use_music = 0;
    info.use_sound = 1;
    info.use_cd_audio = 1;
    info.auto_scroll = 1;
    info.mouse_scroll_edge = 1;
    info.mouse_scroll_interval = 3;
    info.key_scroll_interval = 4;
    info.key_scroll_object_move = 1.2f; // 0x3f99999a
    info.interface_style = 2;
    info.main_wid = 640;
    info.main_hgt = 480;

    // main.cpp:156 (Directories)
    strcpy(info.data_dir, "data2\\");
    // main.cpp:157
    strcpy(info.sounds_dir, "sound\\");
    // main.cpp:158 - ASM at 0x454ea2 shows resource_dir = "data2\\"
    strcpy(info.resource_dir, "data2\\");
    // main.cpp:159
    strcpy(info.save_dir, "savegame\\");
    // main.cpp:160
    strcpy(info.scenario_dir, "scenario\\");
    // main.cpp:161
    strcpy(info.campaign_dir, "campaign\\");
    // main.cpp:168
    strcpy(info.graphics_dir, "data2\\");
    strcpy(info.ai_dir, "data2\\");
    strcpy(info.avi_dir, "avi\\");

CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_CHECKPOINT("Creating TRIBE_Game");
CUSTOM_DEBUG_END

    int retval = 0;
    TRIBE_Game* game = new TRIBE_Game(&info, 1);
    if (game) {
CUSTOM_DEBUG_BEGIN
        int err = game->get_error_code();
        CUSTOM_DEBUG_LOG_FMT("TRIBE_Game created, error_code=%d", err);
CUSTOM_DEBUG_END
        if (game->get_error_code() == 0) {
CUSTOM_DEBUG_BEGIN
            CUSTOM_DEBUG_CHECKPOINT("Starting game->run()");
CUSTOM_DEBUG_END
            retval = game->run();
        } else {
            int err = game->get_error_code();
CUSTOM_DEBUG_BEGIN
            CUSTOM_DEBUG_ERROR(err, "Game initialization failed");
CUSTOM_DEBUG_END
            if (err != 4) {
                char msg[256];
                char title[256];
                game->get_string(2001, title, sizeof(title));
                game->get_string2(err, 0, err, msg, sizeof(msg));
                MessageBoxA(NULL, msg, title, MB_OK | MB_ICONERROR);
            }
            retval = err;
        }
        delete game;
    } else {
CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_ERROR(-1, "Failed to allocate TRIBE_Game");
CUSTOM_DEBUG_END
    }
    
CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG_FMT("WinMain returning %d", retval);
    CUSTOM_DEBUG_SHUTDOWN();
CUSTOM_DEBUG_END
    return retval;
}
