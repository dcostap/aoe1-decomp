// VA: 004AD340 TRIBE_Screen_Sed::command_new_map | scr_sed.cpp:3308-3408
// First natural pass from Ghidra/asm.
// compiles at original size after padding map_info; current mismatch is broad early register/source-shape drift (this kept in ESI, show_status in EDI) versus original stack-homed this and ESI show_status.
// HollowSnowdrop pass: revalidated 590/590 bytes, 81.69% positional diff. Tried moving result declaration later to avoid early EBX zeroing; no change.
// Remaining blocker is early whole-function register allocation/prologue: original `mov eax,ecx` before saves and homes this at [esp+10h], while rebuilt saves this in ESI and zeroes EBX early.

struct RGE_Scenario { int Get_player_Active(int index); };
struct TDropDownPanel { void set_line(long line); };
struct Sound_Driver { char gap_00[1]; char mute; };

struct RGE_Game_World {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6C();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7C();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8C();
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9C();
    virtual void vA0(); virtual void vA4(); virtual void vA8(); virtual void vAC();
    virtual void vB0(); virtual void vB4(); virtual void vB8();
    virtual void vBC(); virtual void vC0(); virtual void vC4(); virtual void vC8();
    virtual void vCC(); virtual void vD0();
    virtual int create_new_map(void* player_info, int param);
    char gap_04[0x3C - 4];
    short player_count;
    char gap_3E[0x5C - 0x3E];
    RGE_Scenario* scenario;
};

struct TRIBE_Game {
    char gap_00[0x60];
    Sound_Driver* sound_system;
    char gap_64[0x3F4 - 0x64];
    RGE_Game_World* world;
    void show_status_message(int string_id, char* text, long param);
    int load_game_data();
    void close_status_message();
};
extern TRIBE_Game* rge_base_game;

struct TRIBE_Screen_Sed {
    char gap_00[0x4C0];
    char need_to_save_flag;
    char gap_4C1[0x5B8 - 0x4C1];
    TDropDownPanel* player_number_list;
    char gap_5BC[0x928 - 0x5BC];
    RGE_Game_World* world;

    void set_string(char* dst, long string_id, int len);
    void SavePlayerActiveStatus();
    int command_new_map(char* scenario_name, int param_2, int param_3, int param_4, int param_5, int show_status);
};

struct RGE_Player_Info_Local {
    long name_base_delta;
    char names[8][0x41];
    char gap_20C[0x24D - 0x20C];
    char type[9];
    char tribe[9];
    char gap_25F[0x260 - 0x25F];
    short color[8];
    char gap_270[0x274 - 0x270];
    long player_id_hash[9];
    char gap_298[0x29C - 0x298];
    void* map_info;
    void* map_type;
    short ai_info;
    short campaign;
    short zero;
};
struct RGE_Map_Gen_Info_Local { short clump_num; char rest[0x522]; };

int TRIBE_Screen_Sed::command_new_map(char* scenario_name, int param_2, int param_3, int param_4, int param_5, int show_status)
{
    int current_tribe;
    RGE_Player_Info_Local player_info;
    RGE_Map_Gen_Info_Local map_info;
    int i;

    this->need_to_save_flag = 0;
    if (rge_base_game->world == 0) {
        if (show_status != 0) {
            rge_base_game->show_status_message(0x44d, 0, -1);
        }
        if (rge_base_game->load_game_data() == 0) {
            if (show_status != 0) {
                rge_base_game->close_status_message();
            }
            return 0;
        }
    }

    this->world = rge_base_game->world;
    if (show_status != 0) {
        rge_base_game->show_status_message(scenario_name != 0 ? 0x44f : 0x44e, 0, -1);
    }

    player_info.map_type = &map_info.clump_num;
    player_info.ai_info = (short)param_4;
    player_info.campaign = (short)param_5;
    player_info.map_info = scenario_name;
    current_tribe = 0;
    player_info.zero = 0;
    *(short*)&player_info.gap_298[0] = 8;
    player_info.name_base_delta = 0x2865 - (long)player_info.type;

    for (i = 0; i < 8; i++) {
        current_tribe++;
        if (current_tribe >= this->world->player_count) {
            current_tribe = 1;
        }
        this->set_string(player_info.names[i], (long)(player_info.type + player_info.name_base_delta + i), 0x41);
        player_info.type[i] = 0;
        player_info.tribe[i] = (char)current_tribe;
        player_info.color[i] = -1;
        player_info.player_id_hash[i] = i;
    }
    player_info.player_id_hash[i] = i;
    map_info.clump_num = 0;

    if (rge_base_game->sound_system != 0) {
        rge_base_game->sound_system->mute = 1;
    }
    int result = this->world->create_new_map((void*)player_info.names, param_3) & 0xff;
    if (result != 0 && this->world->player_count < 8) {
        result = 0;
        this->world->vB8();
    }
    if (rge_base_game->sound_system != 0) {
        rge_base_game->sound_system->mute = 0;
    }

    if (result != 0 && this->player_number_list != 0) {
        i = 0;
        do {
            if (this->world->scenario->Get_player_Active(i) == 0) {
                break;
            }
            i++;
        } while (i < 8);
        if (i < 8 && i > 0) {
            this->player_number_list->set_line(i - 1);
        }
        this->SavePlayerActiveStatus();
    }
    return result;
}
