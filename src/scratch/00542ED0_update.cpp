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
// - Paused in scratch: remaining drift begins at elapsed-time cap/FPU lowering;
//   later status-time block placement also remains broad. Default flags only.

#include <stdio.h>

extern unsigned long debug_timeGetTime(const char* file, int line);
extern void debug_srand(const char* file, int line, int seed);
extern int debug_rand(const char* file, int line);
extern void free(void* p);
extern int __ftol(float);

class RGE_Base_Game;
class TMousePointer;

#define WORLD_CPP ((const char*)0x58ECD8)
#define rge_base_game (*(RGE_Base_Game**)0x62C574)
#define debug_random_on (*(int*)0x62C4D4)
#define debug_timeGetTime_on (*(int*)0x62C4E8)
#define do_fixed_update (*(int*)0x62C4E0)
#define fixed_update_time (*(int*)0x57F9E4)
#define visible_combats (*(short*)0x886C4C)
#define world_update_counter (*(int*)0x886C10)
#define MouseSystem (*(TMousePointer**)0x62E660)
#define logStatusOn (*(int*)0x62C524)
#define lastStatusLogTime (*(unsigned long*)0x886C54)
#define logStatusFile (*(FILE**)0x886C50)

class RGE_Game_Info {
public:
    char gap0[4];
    char* get_current_player_name();
};

class RGE_Base_Game {
public:
    char gap0[4];
    RGE_Game_Info* player_game_info;
    void add_to_timing(int, int);
};

class TCommunications_Handler {
public:
    int DoCycle(unsigned long);
    void LastWorldRandom(int);
};

class RGE_Command {
public:
    char gap0[0x14];
    TCommunications_Handler* com_hand;
    void do_commands();
};

class RGE_Scenario {
public:
    void update();
};

class RGE_Object_List {
public:
    char gap0[4];
    void* list;
    short number_of_objects;
    void update();
};

class RGE_Tile_List {
public:
    int list_size;
    int num_active;
    int new_count;
    int collapse_list;
    void* list;
    void del_list();
};

class RGE_Doppleganger_Creator {
public:
    void perform_doppleganger_checks();
};

class TMousePointer {
public:
    void Poll();
};

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)

class RGE_Player {
public:
    VPAD16(p0) VPAD8(p16) VPAD4(p24) VPAD1(p28) VPAD1(p29) VPAD1(p30)
    virtual unsigned char update();
    char gap04[0x2c];
    RGE_Object_List* doppleganger_objects;
    char gap34[0xc];
    RGE_Doppleganger_Creator* doppleganger_creator;
    char gap44[0x14];
    RGE_Tile_List tile_list;
    char gap6c[0x14];
    unsigned char game_status;
    char gap81[0x6b];
    VPAD16(p32) VPAD8(p48) VPAD1(p56) VPAD1(p57) VPAD1(p58)
    virtual void logStatus(FILE*, int);
};

class RGE_Game_World {
public:
    VPAD32(w0) VPAD4(w32) VPAD1(w36) VPAD1(w37) VPAD1(w38)
    virtual void logStatus(FILE*, int);
    VPAD4(w40) VPAD2(w44) VPAD1(w46)
    virtual unsigned char update();
    VPAD1(w48)
    virtual unsigned char check_game_state();

    unsigned long world_time;
    unsigned long old_world_time;
    unsigned long world_time_delta;
    float timer;
    unsigned long old_time;
    float game_speed;
    unsigned char temp_pause;
    unsigned char game_state;
    unsigned char game_end_condition;
    char gap1f;
    long sound_update_index;
    long sprite_update_index;
    void* map;
    short sound_num;
    char gap2e[2];
    void* sounds;
    short sprite_num;
    char gap36[2];
    void* sprites;
    short player_num;
    char gap3e[2];
    RGE_Player** players;
    char gap44[0x14];
    RGE_Command* commands;
    RGE_Scenario* scenario;
    char gap60[0x18];
    unsigned int random_seed;
    short curr_player;
    char gap7e[2];
    void* sound_driver;
    float world_time_delta_seconds;
    char gap88[0x28];
    int player_turn;
    unsigned long player_time_delta[9];
    char gapd8[0x1c];
    unsigned long maximumComputerPlayerUpdateTime;
    unsigned long availableComputerPlayerUpdateTime;
    int currentUpdateComputerPlayer;
    int difficultyLevelValue;

    void update_sounds(unsigned long);
    void update_sprites(unsigned long);
};

unsigned char RGE_Game_World::update()
{
    char fileName[256];
    int cycle;
    int i;
    unsigned long start_time;
    unsigned long end_time;
    unsigned long now;
    unsigned long old_world_time;
    unsigned long* player_time_delta;
    unsigned long seconds;
    unsigned long minutes;
    unsigned long hours;
    int elapsed;
    unsigned char first_update = 0;

    this->availableComputerPlayerUpdateTime = this->maximumComputerPlayerUpdateTime;
    start_time = debug_timeGetTime(WORLD_CPP, 0x68e);
    cycle = this->commands->com_hand->DoCycle(this->world_time);
    end_time = debug_timeGetTime(WORLD_CPP, 0x690);
    rge_base_game->add_to_timing(0xe, (int)(end_time - start_time));
    if (cycle == 0) {
        this->world_time_delta = 0;
        return this->game_state;
    }

    visible_combats = 0;
    debug_random_on = 1;
    debug_timeGetTime_on = 1;
    if (do_fixed_update != 0) cycle = fixed_update_time;

    debug_srand(WORLD_CPP, 0x6a2, this->random_seed);
    now = debug_timeGetTime(WORLD_CPP, 0x6a4);
    this->update_sounds(now);
    this->update_sprites(now);

    if (cycle == -1) {
        if (this->old_time == 0) {
            first_update = 1;
            elapsed = 0;
        } else {
            elapsed = now - this->old_time;
        }
        if ((unsigned int)elapsed > 100) elapsed = 100;
    } else {
        elapsed = cycle;
    }

    this->old_time = now;
    old_world_time = this->world_time;
    this->old_world_time = old_world_time;
    if (this->temp_pause != 0) {
        if (cycle != -1) {
            this->world_time = old_world_time +
                (unsigned long)((double)elapsed * this->game_speed);
        }
        this->temp_pause = 0;
    } else {
        this->world_time = old_world_time +
            (unsigned long)((double)elapsed * this->game_speed);
    }
    this->world_time_delta = this->world_time - this->old_world_time;

    if (this->world_time_delta != 0 || first_update) {
        this->commands->do_commands();
        this->scenario->update();
        this->world_time_delta_seconds =
            (float)((double)this->world_time_delta * *(float*)0x577A14);
        world_update_counter = world_update_counter + 1;
        player_time_delta = this->player_time_delta;
        for (i = 0; i < this->player_num; ++i, ++player_time_delta) {
            if (this->players[i] != 0) {
                *player_time_delta = *player_time_delta + this->world_time_delta;
                this->players[i]->update();
                this->players[i]->tile_list.del_list();
            }
        }
        if (MouseSystem != 0) MouseSystem->Poll();
        now = debug_rand(WORLD_CPP, 0x6e2);
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
        debug_srand(WORLD_CPP, 0x6f6, now);
        this->player_time_delta[this->player_turn] = 0;
        this->player_turn = this->player_turn + 1;
        if (this->player_num <= this->player_turn) this->player_turn = 0;
        this->check_game_state();
    }

    now = debug_rand(WORLD_CPP, 0x71a);
    this->random_seed = now;
    debug_random_on = 0;
    debug_timeGetTime_on = 0;
    this->commands->com_hand->LastWorldRandom(this->random_seed);

    if (logStatusOn == 1 && this->game_state != 1) {
        if ((unsigned int)(this->world_time - lastStatusLogTime) > 30000 ||
            lastStatusLogTime == 0) {
            if (logStatusFile == 0) {
                sprintf(fileName, "AILog\\%s.log",
                        rge_base_game->player_game_info->get_current_player_name());
                logStatusFile = (FILE*)fopen(fileName, "a");
                if (logStatusFile == 0) return this->game_state;
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
                this->logStatus(logStatusFile, 1);
            } else {
                fprintf(logStatusFile,
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
