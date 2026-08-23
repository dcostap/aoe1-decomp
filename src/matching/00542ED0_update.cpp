// VA: 00542ED0 RGE_Game_World::update
// PDB source: World.cpp
// Attempt log:
// - Baseline skeleton was 25 bytes short and had the wrong command/list/status
//   helper surfaces; it also used raw player offsets for the three update scans.
// - Reconstructed the binary-backed World, Command, Player, tile-list, object-
//   list, communications, and status-log ownership from the World.cpp packet,
//   generated layouts, and exact helper donors. The remaining probes will tune
//   ordinary source/control-flow shape only; no inline asm or raw vtable code.
// - Canonical candidate now has the original 31-call set, frame 0x108, and
//   typed player/list/status ownership. The best diagnostic 64-bit conversion
//   experiment reached 1167 bytes but was rolled back as compiler steering.
// - Tested the period-plausible unsigned-long elapsed guard. It restores the
//   original qword FPU conversion and exact cap blocks; 1183 bytes remain.
// - Paused in scratch: remaining drift starts with early register/coloring and
//   FPU operand order; later status-time block placement also remains broad.
//   Default flags only.
// - Structural follow-up: direct indexed player-time access and a cached local
//   status handle align the update loop and status-log entry blocks. Signed long
//   status counters reproduce the original signed divide-by-60 blocks.
// - Capturing lastStatusLogTime before the status gate reuses the original EAX
//   value and removes one redundant move. The best result is 678 differing bytes
//   and one byte past the original boundary.
// - A scoped players-array alias changed the frame to 0x10C and worsened the
//   result. Reusing dead timing locals emitted duplicate code. Both were rolled
//   back; keep the named status timestamp as the clean source model.
// - Exact finish: extern declarations for world_update_counter, MouseSystem,
//   lastStatusLogTime, and logStatusFile restored the original register and
//   relocation basin. The player-turn bound uses player_turn on the left.
//   First exact checkpoint: 20260817T121618.187976Z-ba70c0a914, MATCH at 0.0000%.
//   Independent walkback required all five changes. Reverting rge_base_game to
//   its macro and moving statusLogTime back to its old declaration location
//   stayed exact. The reviewed rge_base_game extern remains for source policy.
//   Grouped reversion of world_update_counter plus MouseSystem reached 668
//   differing bytes. Grouped status-global reversion reached 80 differing bytes.
// - Policy cleanup: replaced all VPAD surfaces with the named donor methods
//   and canonical destructor slots. Replaced WORLD_CPP with the natural string
//   literal. Replaced every raw data address with a supported extern, including
//   DAT_00577a14. Each global cleanup stayed exact. A natural 0.001f literal
//   alone changed the FPU load, so the repository-defined DAT_00577a14 extern
//   is required. Player and World name axes were tested alone and together.
// - Full World.cpp context made the explicit double cast load the scale first,
//   which added an x87 instruction and two bytes. The natural float expression
//   restores the original memory multiply. It matches under default and /GX.

#include <stdio.h>
#include "../../include/world_scenario_context.h"

unsigned char RGE_Game_World::update()
{
    char fileName[256];
    int cycle;
    int i;
    unsigned long start_time;
    unsigned long end_time;
    unsigned long now;
    long seconds;
    long minutes;
    long hours;
    unsigned long elapsed;
    unsigned long statusLogTime;
    unsigned char first_update = 0;

    this->availableComputerPlayerUpdateTime = this->maximumComputerPlayerUpdateTime;
    start_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\World.cpp", 0x68e);
    cycle = this->commands->com_hand->DoCycle(this->world_time);
    end_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\World.cpp", 0x690);
    rge_base_game->add_to_timing(0xe, (int)(end_time - start_time));
    if (cycle == 0) {
        this->world_time_delta = 0;
        return this->game_state;
    }

    visible_combats = 0;
    debug_random_on = 1;
    debug_timeGetTime_on = 1;
    if (do_fixed_update != 0) cycle = fixed_update_time;

    debug_srand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x6a2, this->random_seed);
    now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\World.cpp", 0x6a4);
    this->update_sounds(now);
    this->update_sprites(now);

    if (cycle == -1) {
        if (this->old_time == 0) {
            first_update = 1;
            elapsed = 0;
        } else {
            elapsed = now - this->old_time;
        }
        if (elapsed > 100) elapsed = 100;
    } else {
        elapsed = cycle;
    }

    this->old_time = now;
    this->old_world_time = this->world_time;
    if (this->temp_pause != 0) {
        if (cycle != -1) {
            this->world_time = this->old_world_time +
                (unsigned long)(elapsed * this->game_speed);
        }
        this->temp_pause = 0;
    } else {
        this->world_time = this->old_world_time +
            (unsigned long)(elapsed * this->game_speed);
    }
    this->world_time_delta = this->world_time - this->old_world_time;

    if (this->world_time_delta != 0 || first_update) {
        this->commands->do_commands();
        this->scenario->update();
        // BINARY NOTE: keep the pooled scale and natural float expression.
        // An explicit double cast changes x87 evaluation in the full context.
        this->world_time_delta_seconds = this->world_time_delta * DAT_00577a14;
        world_update_counter = world_update_counter + 1;
        for (i = 0; i < this->player_num; ++i) {
            if (this->players[i] != 0) {
                this->player_time_delta[i] =
                    this->player_time_delta[i] + this->world_time_delta;
                this->players[i]->update();
                this->players[i]->tile_list.del_list();
            }
        }
        if (MouseSystem != 0) MouseSystem->Poll();
        // LIKELY INTENT: preserve the random stream while maintenance work
        // updates duplicate-object lists for every player.
        now = debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x6e2);
        for (i = 0; i < this->player_num; ++i) {
            if (this->players[i] != 0) {
                this->players[i]->doppleganger_objects->update();
            }
        }
        for (i = 0; i < this->player_num; ++i) {
            if (this->players[i] != 0) {
                this->players[i]->doppleganger_creator->perform_doppleganger_checks();
            }
        }
        debug_srand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x6f6, now);
        this->player_time_delta[this->player_turn] = 0;
        this->player_turn = this->player_turn + 1;
        if (this->player_turn >= this->player_num) this->player_turn = 0;
        this->check_game_state();
    }

    now = debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x71a);
    this->random_seed = now;
    debug_random_on = 0;
    debug_timeGetTime_on = 0;
    this->commands->com_hand->LastWorldRandom(this->random_seed);

    if (logStatusOn == 1 && this->game_state != 1) {
        statusLogTime = lastStatusLogTime;
        if (30000 < this->world_time - statusLogTime ||
            statusLogTime == 0) {
            FILE* statusFile = logStatusFile;
            if (statusFile == 0) {
                sprintf(fileName, "AILog\\%s.log",
                        rge_base_game->player_game_info->get_current_player_name());
                statusFile = (FILE*)fopen(fileName, "a");
                logStatusFile = statusFile;
                if (statusFile == 0) return this->game_state;
            }
            seconds = this->world_time / 1000;
            minutes = 0;
            hours = 0;
            if (seconds > 59) {
                minutes = seconds / 60;
                seconds = seconds - minutes * 60;
                if (minutes > 59) {
                    hours = minutes / 60;
                    minutes = minutes - hours * 60;
                }
            }
            if (lastStatusLogTime == 0) {
                this->logStatus(statusFile, 1);
            } else {
                fprintf(statusFile,
                        "\nStatus Log at GameTime %02ld:%02ld:%02ld\n",
                        hours, minutes, seconds);
            }
            for (i = 1; i < this->player_num; ++i) {
                if (this->players[i] != 0) {
                    if (lastStatusLogTime == 0) {
                        this->players[i]->logStatus(logStatusFile, 1);
                    } else {
                        this->players[i]->logStatus(logStatusFile, 0);
                    }
                }
            }
            // BINARY NOTE: zero selects the full first status report. The +1
            // keeps a valid report time from reusing that sentinel value.
            lastStatusLogTime = this->world_time + 1;
        }
    }

    if (this->game_state == 1 && logStatusOn == 1 && logStatusFile != 0) {
        fprintf(logStatusFile, "\nGAME OVER!\n");
        for (i = 1; i < this->player_num; ++i) {
            if (this->players[i] != 0) {
                if (this->players[i]->game_status == 1) {
                    fprintf(logStatusFile, "\nPlayer %d Won!\n", i);
                } else {
                    fprintf(logStatusFile, "\nPlayer %d Lost!\n", i);
                }
            }
        }
        fclose(logStatusFile);
        logStatusFile = 0;
    }
    return this->game_state;
}
