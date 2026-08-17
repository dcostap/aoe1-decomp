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
// probe: delaying the receiver alias until after the status gate, following the
// direct-this shape in same-TU command donors, was codegen-neutral.
// probe: an explicit unsigned-byte cast on the typed new-map dispatch preserved
// the source model but emitted the same code; rolled back.
// probe: direct scenario-status branch calls tail-merge to the original single
// call site with branch-specific 44e/44f pushes; retained as the best source.
// blocker: original begins `mov eax,ecx`, homes this at [esp+10h], and keeps
// show_status in ESI; VC5 retains this in ESI, zeroes EBX early, and emits a
// 570-byte/576-compared basin despite matching frame/saved-register set/calls.
// probe: a typed initial-world snapshot produced the original early load/test
// shape, but worsened the basin to 576 bytes and diff 559; it was rolled back.
// probe: modeling the map land header as short clump_num changed the byte store
// to the original word store and improved diff 505 to 503.
// probe: initializing player_num before the scan and writing hash[8] after it
// recovered the original stack order and improved diff 503 to 465; retained.
// probe: splitting new_scenario result assignment from byte narrowing produced
// the target EAX mask and improved diff 465 to 433; the one-statement uchar ABI
// form emits the same best bytes and is retained.
// probes: receiver pointer/reference aliases and a scoped game pointer were
// codegen duplicates or worsened structure; retained the simplest pointer form.
// blocker: target still homes receiver/current-tribe locals in opposite slots
// and differs in early register/global-load coloring despite matching calls,
// frame, size, and CFG signals.
// revisit: restore the reviewed TRIBE_Game global surface and remove the
// accessor/game aliases. The original homes this at [esp+10] and reloads the
// global for each game operation; a persistent game alias adds the wrong home.
// revisit result: direct global access restored the 0x7D8 frame, 159 emitted
// instructions, and the 10-call set; strict diff improved 489 to 433 bytes.
// revisit probes: a scoped game pointer worsened the result to 544 bytes;
// receiver pointer/reference aliases, declaration moves, canonical screen
// fields, and the RGE_Base_Game base surface were neutral or codegen-duplicate.
// final lead: keep the typed TRIBE_Game/RGE_Game_World scenario-editor flow;
// the remaining gap is the original register/home coloring and one-byte size.
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
    virtual void vB0(); virtual void vB4(); virtual void del_game_info();
    virtual void vBC(); virtual void vC0(); virtual void vC4(); virtual void vC8();
    virtual void vCC(); virtual void vD0();
    virtual unsigned char new_scenario(void* player_info, int param);
    char gap_04[0x3C - 4];
    short player_count;
    char gap_3E[0x5C - 0x3E];
    RGE_Scenario* scenario;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[0x5C];
    Sound_Driver* sound_system;
    char gap_64[0x3F4 - 0x64];
    RGE_Game_World* world;
};

class TRIBE_Game : public RGE_Base_Game {
public:
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
    virtual ~TScreenPanel();
};

struct TRIBE_Screen_Sed : TScreenPanel {
    int is_multi_player;
    char gap_47C[4];
    void* SelectedObject;
    void* DestinationObject;
    float px1, py1, px2, py2;
    int CurrentVictory;
    int CurrentPlayer;
    char gap_4A0[4];
    int scenario_mode;
    int map_type;
    int mp_victory_type;
    int brush_size;
    int paint_type;
    short player_num;
    char gap_4BA[2];
    int message_type;
    unsigned char need_to_save_flag;
    char gap_4C1[0x5B8 - 0x4C1];
    TDropDownPanel* player_number_list;
    char gap_5BC[0x928 - 0x5BC];
    RGE_Game_World* world;

    virtual ~TRIBE_Screen_Sed();
    void set_string(char* dst, long string_id, int len);
    void SavePlayerActiveStatus();
    int command_new_map(char* scenario_name, int param_2, int param_3, int param_4, int param_5, int show_status);
};

struct RGE_Info_Line {
    short clump_num;
    char rest[0x12];
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
    int result;
    long name_base_delta;
    RGE_Player_Info player_info;
    RGE_Map_Gen_Info map_info;

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
        if (scenario_name == 0) {
            rge_base_game->show_status_message(0x44e, 0, -1);
        } else {
            rge_base_game->show_status_message(0x44f, 0, -1);
        }
    }

    player_info.scenario = scenario_name;
    player_info.map_info = (RGE_Map_Gen_Info*)&map_info.land;
    player_info.map_width = (short)param_4;
    player_info.map_height = (short)param_5;
    player_info.ai_info = 0;
    player_info.player_num = 8;
    current_tribe = 0;
    name_base_delta = 0x2865 - (long)player_info.type;

    for (i = 0; i < 8; i++) {
        current_tribe++;
        if (current_tribe >= this->world->player_count) {
            current_tribe = 1;
        }
        this->set_string(player_info.name[i], (long)(player_info.type + name_base_delta + i), 0x41);
        player_info.type[i] = 0;
        player_info.tribe[i] = (char)current_tribe;
        player_info.color[i] = -1;
        player_info.player_id_hash[i] = i;
    }
    player_info.player_id_hash[i] = i;
    map_info.land.clump_num = 0;

    if (rge_base_game->sound_system != 0) {
        rge_base_game->sound_system->mute = 1;
    }
    result = this->world->new_scenario((void*)player_info.name, param_3) & 0xff;
    if (result != 0 && this->world->player_count < 8) {
        result = 0;
        this->world->del_game_info();
    }
    if (rge_base_game->sound_system != 0) {
        rge_base_game->sound_system->mute = 0;
    }

    if (result != 0 && this->player_number_list != 0) {
        i = 0;
        while (i < 8) {
            if (this->world->scenario->Get_player_Active(i) == 0) {
                break;
            }
            i++;
        }
        if (i < 8 && i > 0) {
            this->player_number_list->set_line(i - 1);
        }
        this->SavePlayerActiveStatus();
    }
    return result;
}
