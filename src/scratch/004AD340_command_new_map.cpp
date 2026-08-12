// VA: 004AD340 TRIBE_Screen_Sed::command_new_map | scr_sed.cpp:3308-3408
// Attempt log:
// baseline: natural status/world/map-generation reconstruction with named local
// records and the bounded active-player scan.
// probe: while-loop scan removed VC5's peeled duplicate get_player_active call;
// it matched the ten-call multiset and original effective size, but not CFG.
// probe: canonical RGE_Player_Info plus a separate name-base local recovered the
// proven name/type/color/hash and scenario/map-info stack ownership; the local
// map payload uses its binary-proven land anchor at offset zero.
// probes: captured-this alias, declaration-order swaps, result lifetime, and
// TScreenPanel base context were codegen-neutral; field-home padding was neutral.
// blocker: original begins `mov eax,ecx`, homes this at [esp+10h], and keeps
// show_status in ESI; VC5 retains this in ESI, zeroes EBX early, and emits a
// 570-byte/576-compared basin despite matching frame/saved-register set/calls.
// probe: a typed initial-world snapshot produced the original early load/test
// shape, but worsened the basin to 576 bytes and diff 559; it was rolled back.
// FLAGS: default config/flags/default.rsp (/nologo /c /O2 /Oy).

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

struct TPanel {
    virtual ~TPanel();
};

struct TScreenPanel : TPanel {
    char gap_04[0x478 - 0x04];
};

struct TRIBE_Screen_Sed : TScreenPanel {
    char gap_478[0x4C0 - 0x478];
    char need_to_save_flag;
    char gap_4C1[0x5B8 - 0x4C1];
    TDropDownPanel* player_number_list;
    char gap_5BC[0x928 - 0x5BC];
    RGE_Game_World* world;

    void set_string(char* dst, long string_id, int len);
    void SavePlayerActiveStatus();
    int command_new_map(char* scenario_name, int param_2, int param_3, int param_4, int param_5, int show_status);
};

struct RGE_Info_Line {
    char bytes[0x14];
};

struct RGE_Map_Gen_Info {
    RGE_Info_Line land;
    char rest[0x520 - 0x14];
};

struct RGE_Player_Info {
    char name[9][65];
    char type[9];
    char tribe[9];
    char gap_25B;
    short color[9];
    char gap_26E[2];
    long player_id_hash[9];
    short player_num;
    char gap_296[2];
    char* scenario;
    RGE_Map_Gen_Info* map_info;
    short map_type;
    short map_width;
    short map_height;
    short ai_info;
    unsigned char campaign;
    char gap_2A9[3];
};

int TRIBE_Screen_Sed::command_new_map(char* scenario_name, int param_2, int param_3, int param_4, int param_5, int show_status)
{
    int i;
    int current_tribe;
    TRIBE_Screen_Sed* tribe = this;
    int result;
    long name_base_delta;
    RGE_Player_Info player_info;
    RGE_Map_Gen_Info map_info;

    tribe->need_to_save_flag = 0;
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

    tribe->world = rge_base_game->world;
    if (show_status != 0) {
        rge_base_game->show_status_message(scenario_name != 0 ? 0x44f : 0x44e, 0, -1);
    }

    player_info.scenario = scenario_name;
    player_info.map_info = (RGE_Map_Gen_Info*)&map_info.land;
    player_info.map_width = (short)param_4;
    player_info.map_height = (short)param_5;
    player_info.ai_info = 0;
    current_tribe = 0;
    name_base_delta = 0x2865 - (long)player_info.type;

    for (i = 0; i < 8; i++) {
        current_tribe++;
        if (current_tribe >= tribe->world->player_count) {
            current_tribe = 1;
        }
        tribe->set_string(player_info.name[i], (long)(player_info.type + name_base_delta + i), 0x41);
        player_info.type[i] = 0;
        player_info.tribe[i] = (char)current_tribe;
        player_info.color[i] = -1;
        player_info.player_id_hash[i] = i;
    }
    player_info.player_num = (short)i;
    map_info.land.bytes[0] = 0;

    if (rge_base_game->sound_system != 0) {
        rge_base_game->sound_system->mute = 1;
    }
    result = tribe->world->create_new_map((void*)player_info.name, param_3) & 0xff;
    if (result != 0 && tribe->world->player_count < 8) {
        result = 0;
        tribe->world->vB8();
    }
    if (rge_base_game->sound_system != 0) {
        rge_base_game->sound_system->mute = 0;
    }

    if (result != 0 && tribe->player_number_list != 0) {
        i = 0;
        while (i < 8) {
            if (tribe->world->scenario->Get_player_Active(i) == 0) {
                break;
            }
            i++;
        }
        if (i < 8 && i > 0) {
            tribe->player_number_list->set_line(i - 1);
        }
        tribe->SavePlayerActiveStatus();
    }
    return result;
}
