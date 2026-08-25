// VA: 0041C270 ~RGE_Base_Game (1136 B)
// PDB source: basegame.cpp:877-1083
// Attempt log:
// - Baseline packet scaffold used free-function shims and missed the original
//   member/destructor, CRT, Win32-import, and function-pointer call surfaces.
// - Reconstructing the typed RGE_Base_Game ownership and ordinary destructor
//   sequence is the current source-first candidate; exactness remains pending.
// - Typed member calls, CRT/Win32 imports, and the two natural cleanup loops now
//   reproduce all 56 ordered call sites and the 0x110 frame.
// - The rollover conditional, mouse-style if/else, and saved scenario pointer
//   progressively aligned the early body; the final remaining hunk begins at
//   the fonts loop and leaves 413 positional bytes with exact size.
// - A manual vptr restore was rejected by source policy; the natural virtual
//   destructor surface is retained while the remaining codegen drift is paused.
// - The original clears the +0x1B0 prog-mode slot before world cleanup; the
//   generated field map does not support clearing game_mode at +0x1B4 here.
// - Direct RegGetInt testing, nested player-info cleanup ownership, and local
//   destructor pointers reproduce the original block structure through fonts.
// - RGE_Font is a 0xC record with its DeleteObject handle at offset zero; the
//   remaining drift is the imported-call cache and loop register coloring.
// - A local cached DeleteObject pointer inside the positive-count guard added
//   8 bytes to the frame and worsened the match; restored the direct call.
// - An explicit positive font-count guard is a natural binary-supported source
//   shape and reduced the localized drift from 413 to 266 bytes.
// - The Windows header/HGDIOBJ surface and a const local API pointer were
//   codegen duplicates; the local pointer was removed from the final source.
// - Managed pass 2026-08-17: twenty focused probes kept this source as the
//   clean best. A pre-guard do-while recovered the initial xor/cmp block but
//   lost the natural loop basin. Typed counter/index locals, bound polarity,
//   handle locals, continue form, import-pointer declarations, and local
//   DeleteObject aliases were unchanged, worse, or added frame bytes.
// - Original evidence still requires one cached DeleteObject IAT load in EBX,
//   test EAX, and a post-call font_num reload. The clean source emits a direct
//   IAT call and cmp EAX,EBX. No policy-compliant source cause is proven.
// - Behavior audit fixed two source defects. SystemParametersInfoA uses the
//   executable's uiParam value 1 for actions 0x11 and 0x55. get_string uses
//   the binary-proven (string_id, buffer, size) parameter order.
// BLOCKER: the executable caches the DeleteObject import target once before
// the font loop. The rebuild reads the writable import slot for each call. A
// prior external call can therefore change a later call target only in the
// rebuild. Keep the corrected natural destructor in scratch.
// - Managed pass 2026-08-22: a separate count and byte-offset do-while matched
//   the original pre-loop guard and raised exact-block coverage to 95.34%.
//   It still emitted cmp EAX,EBX and a direct IAT call, added three
//   instructions, and caused call-map drift after the loop. Local mutable,
//   register, const, and file-scope DeleteObject aliases did not change it;
//   the file-scope alias also changed the extracted owner. Restored the
//   smallest typed for-loop source as the clean reconstruction.

#include <stdio.h>
#include <windows.h>

class RGE_Game_Info;
class RGE_Scenario_File_Info;


class TDrawSystem;
class TDrawArea;
class TShape;
class TSound_Driver;
class TMusic_System;
class TDigital;
class TCommunications_Handler;
class TDebuggingLog;
class TRegistry;
class TMousePointer;

class TChat;
class TPanelSystem;
class DriveInformation;

extern void __cdecl debug_random_write(void);
extern void __cdecl dump_vismap_log(void);
extern void __cdecl operator delete(void*);
extern "C" void __cdecl free(void*);

extern "C" __declspec(dllimport) int __stdcall SystemParametersInfoA(
    unsigned int action, unsigned int param, void* value, unsigned int flags);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* handle);
extern "C" __declspec(dllimport) int __stdcall DestroyWindow(void* window);
extern "C" __declspec(dllimport) void* __stdcall FindWindowA(
    const char* class_name, const char* window_name);
extern "C" __declspec(dllimport) long __stdcall SendMessageA(
    void* window, unsigned int message, unsigned int wparam, long lparam);
extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* module);
extern int do_debug_random;
extern int wrote_debug_random_log;
extern FILE* actionFile;
extern FILE* fps_log;
extern FILE* draw_log;
extern void* StringTable;
extern DriveInformation* driveInfo;
extern TChat* chat;
class RGE_Base_Game;
extern RGE_Base_Game* rge_base_game;
extern float DAT_0056f018;












extern TPanelSystem panel_system;
RGE_Base_Game::~RGE_Base_Game()
{
    int i;
    char filename[13];
    char str[256];

    if (do_debug_random && !wrote_debug_random_log) {
        debug_random_write();
        dump_vismap_log();
    }

    if (this->draw_system != 0) {
        this->registry->RegSetInt(1, "Screen Size", this->draw_system->screen_size);
    }

    this->registry->RegSetInt(1, "Rollover Text",
        2 + (this->rollover ? -1 : 0));

    if (this->prog_info->interface_style == 2)
        this->registry->RegSetInt(1, "Mouse Style", 2);
    else
        this->registry->RegSetInt(1, "Mouse Style", 1);

    this->registry->RegSetInt(1, "Game Speed",
        (int)(this->game_speed * DAT_0056f018));
    this->registry->RegSetInt(1, "Difficulty", this->single_player_difficulty);
    this->registry->RegSetInt(1, "Path Finding", this->pathFinding() + 1);
    this->registry->RegSetInt(1, "MP Path Finding", this->mpPathFinding() + 1);
    this->registry->RegSetInt(1, "Scroll Speed", this->prog_info->scroll_speed);

    if (actionFile != 0) {
        fclose(actionFile);
        actionFile = 0;
    }
    if (fps_log != 0) {
        fclose(fps_log);
        fps_log = 0;
    }
    if (draw_log != 0) {
        fclose(draw_log);
        draw_log = 0;
    }

    RGE_Scenario_File_Info* scenario_info = this->scenario_info;
    if (scenario_info != 0) {
        scenario_info->~RGE_Scenario_File_Info();
        operator delete(scenario_info);
        this->scenario_info = 0;
    }

    if (this->player_game_info != 0) {
        if (this->registry->RegGetInt(0, "Game File Number") >= 0) {
            int file_number = this->registry->RegGetInt(0, "Game File Number");
            sprintf(filename, "game%d.nfo", file_number);
            this->player_game_info->save(filename);
        }
        RGE_Game_Info* player_game_info = this->player_game_info;
        if (player_game_info != 0) {
            player_game_info->~RGE_Game_Info();
            operator delete(player_game_info);
        }
        this->player_game_info = 0;
    }

    this->prog_mode = 0;
    if (this->world != 0) {
        delete this->world;
        this->world = 0;
    }

    TDrawArea* map_save_area = this->map_save_area;
    if (map_save_area != 0) {
        map_save_area->~TDrawArea();
        operator delete(map_save_area);
        this->map_save_area = 0;
    }
    TMousePointer* mouse_pointer = this->mouse_pointer;
    if (mouse_pointer != 0) {
        mouse_pointer->~TMousePointer();
        operator delete(mouse_pointer);
        this->mouse_pointer = 0;
    }

    if (driveInfo != 0) {
        operator delete(driveInfo);
        driveInfo = 0;
    }

    TCommunications_Handler* comm_handler = this->comm_handler;
    if (comm_handler != 0) {
        comm_handler->~TCommunications_Handler();
        operator delete(comm_handler);
        this->comm_handler = 0;
    }
    TChat* chat_object = chat;
    if (chat_object != 0) {
        chat_object->~TChat();
        operator delete(chat_object);
        chat = 0;
    }

    if (this->fonts != 0) {
        if (this->font_num > 0) {
            for (i = 0; i < this->font_num; i++) {
                if (this->fonts[i].font)
                    DeleteObject(this->fonts[i].font);
            }
        }
        free(this->fonts);
        this->fonts = 0;
    }

    this->stop_sound_system();
    panel_system.destroyPanel("Blank Screen");

    TDrawSystem* draw_system = this->draw_system;
    if (draw_system != 0) {
        draw_system->~TDrawSystem();
        operator delete(draw_system);
        this->draw_system = 0;
        this->draw_area = 0;
    }

    if (this->screen_saver_enabled != 0)
        SystemParametersInfoA(0x11, 1, 0, 2);
    if (this->low_power_enabled != 0)
        SystemParametersInfoA(0x55, 1, 0, 2);

    if (this->prog_palette != 0) {
        panel_system.release_palette(this->prog_palette);
        this->prog_palette = 0;
    }

    TRegistry* registry = this->registry;
    if (registry != 0) {
        registry->~TRegistry();
        operator delete(registry);
        this->registry = 0;
    }

    if (this->prog_mutex != 0) {
        CloseHandle(this->prog_mutex);
        this->prog_mutex = 0;
    }

    rge_base_game = 0;

    if (this->prog_window != 0)
        DestroyWindow(this->prog_window);

    this->get_string(0x3EB, str, 0x100);
    if (str[0] != 0) {
        void* help_window = FindWindowA("MS_WINHELP", str);
        if (help_window != 0)
            SendMessageA(help_window, 0x10, 0, 0);
    }

    if (StringTable != 0 && StringTable != (void*)this->prog_info->instance) {
        FreeLibrary(StringTable);
        StringTable = 0;
    }

    TDebuggingLog* debug_log = this->debugLog;
    if (debug_log != 0) {
        debug_log->~TDebuggingLog();
        operator delete(debug_log);
        this->debugLog = 0;
    }

    if (this->shapes != 0) {
        for (i = 0; i < this->shape_num; ++i) {
            TShape* shape = this->shapes[i];
            if (shape != 0) {
                shape->~TShape();
                operator delete(shape);
            }
        }
        free(this->shapes);
    }
}
