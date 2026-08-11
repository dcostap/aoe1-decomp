// 005445C0 RGE_Game_World::load_scenario2
// Attempt log:
// 1: natural reconstruction from packet using byte-offset class surface; explicit __thiscall function-pointer casts are rejected by VC5 warning policy.
// 2: switched indirect calls to local virtual surfaces with dummy slots; compiles but broad mismatch, first diff stack frame 0x68 vs original 0x60.
// 3: remaining lead is local-slot coalescing/reuse: original reuses the same stack slots for object fields and loop/state values, and even reuses a dead incoming parameter slot for outer index.
// 4: restored the period ABI surfaces: scenario helpers take (player) or (player,mode),
//    Player scenario_load takes a float factor, and make_scenario_obj takes object state
//    plus float angle. Removed the decompiler's extra helper arguments/aliases and used
//    the initial 4-byte rem header for next_object_id.
// 5: nested loadAIInformation argument evaluation recovered the pre-pushed -1 and
//    reduced the candidate to 705 bytes; the final for-loop was closer at 702 bytes.
// 6: reading the first scenario-player byte through player_id_hash[8], keeping the
//    transient byte in master_player_id, and using direct players[mapped] access
//    recovered the exact object-record block and the 703-byte/148-byte-diff best.
// 7: exhausted source-shape probes; the remaining drift is structural local coloring:
//    frame 0x5c vs 0x60, first header-byte home, outer-index parameter-home reuse, the
//    final rem reread home, and the final short-player bound compare. Kept the typed,
//    period-plausible candidate in scratch rather than retaining compiler-only aliases.

extern "C" void __cdecl rge_read(int, void*, int);
extern "C" int __cdecl rge_close(int);

#define world_update_counter (*(int*)0x00886C10)
class RGE_Scenario {
public:
    int GetPlayerPosture(int);
    char* Get_player_AI(int, int);
    char* Get_CityPlan(int, int);
    char* Get_BuildList(int, int);
};
class RGE_Player {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void loadAIInformation(char*, char*, char*, int, int);
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void make_scenario_obj(float, float, float, short, unsigned char, float);
    virtual void v25();
    virtual void load_scenario_info(int, long*, float);
    void remake_visible_map();
};
class RGE_Player_Info {
public:
    char name[9][65];
    char type[9];
    char tribe[9];
    unsigned char gap_25b;
    short color[9];
    unsigned char gap_26e[2];
    long player_id[9];
};

class RGE_Game_World {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void scenario_make_map(int);
    virtual void v29(); virtual void v30(); virtual void v31(); virtual void load_scenario2(int handle, RGE_Player_Info& info);
    virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60();
    virtual void scenario_init(int, RGE_Game_World*);
    char gap_04[0x38];
    short player_num;
    char gap_3e[2];
    RGE_Player** players;
    char gap_44[0x18];
    RGE_Scenario* scenario;
    char gap_60[8];
    int next_object_id;
    char gap_6c[4];
    int scenario_object_id;
    unsigned char scenario_object_flag;
};

void RGE_Game_World::load_scenario2(int handle, RGE_Player_Info& info)
{
    long player_id_hash[9];
    char rem[13];
    int obj_id;
    float world_x;
    float world_y;
    float world_z;
    short master_id;
    unsigned char obj_state;
    float obj_angle;
    int id;
    int count;
    int scenario_player_num;
    unsigned char master_player_id;

    world_update_counter = 0;
    rge_read(handle, &rem[0], 4);
    this->scenario_init(handle, this);
    this->scenario_make_map(handle);

    int player_num = this->player_num;
    if (player_num > 0) {
        do { for (int k = 0; k < 9; k++) player_id_hash[k] = -1; } while (player_num > 10);
    }
    int i = 0;
    if (player_num > 0) {
        long* p = &info.player_id[0];
        do { int idx = *p++; player_id_hash[idx] = i; i++; } while (i < player_num);
    }
    int j = 0;
    if (player_num > 0) {
        do { this->players[j]->remake_visible_map(); j++; } while (j < this->player_num);
    }

    rge_read(handle, &scenario_player_num, 4);
    j = 0;
    if (scenario_player_num > 0) { do { rge_read(handle, &player_id_hash[8], 1); rge_read(handle, &master_player_id, 1); j++; } while (j < scenario_player_num); }

    int outer = 0;
    if (scenario_player_num > 0) {
        long* map = player_id_hash;
        do {
            rge_read(handle, &count, 4);
            j = 0;
            if (count > 0) {
                do {
                    rge_read(handle, &world_z, 4);
                    rge_read(handle, &world_y, 4);
                    rge_read(handle, &world_x, 4);
                    rge_read(handle, &obj_id, 4);
                    rge_read(handle, &master_id, 2);
                    rge_read(handle, &obj_state, 1);
                    rge_read(handle, &obj_angle, 4);
                    int mapped = *map;
                    if (mapped >= 0 && this->players[mapped] != 0) {
                        this->scenario_object_flag = 1;
                        this->scenario_object_id = obj_id;
                        this->players[mapped]->make_scenario_obj(world_z, world_y, world_x, master_id, obj_state, obj_angle);
                        this->scenario_object_flag = 0;
                    }
                    j++;
                } while (j < count);
            }
            outer++; map++;
        } while (outer < scenario_player_num);
    }

    this->next_object_id = *(int*)rem;
    rge_read(handle, rem, 13);
    j = 1;
    if (scenario_player_num > 1) {
        long* map = &player_id_hash[1];
        do {
            RGE_Player* pl;
            if (j < this->player_num && *map > -1 && (pl = this->players[*map]) != 0) { } else { pl = this->players[0]; }
            pl->load_scenario_info(handle, player_id_hash, 1.03f);
            j++; map++;
        } while (j < scenario_player_num);
    }

    rge_close(handle);
    j = 1;
    if (this->player_num > 1) {
        for (; j < this->player_num; ++j) {
            if (j >= scenario_player_num) return;
            if (this->players[j] != 0 && player_id_hash[j] > -1) {
                int s = j - 1;
                this->players[player_id_hash[j]]->loadAIInformation(
                    this->scenario->Get_BuildList(s, 1),
                    this->scenario->Get_CityPlan(s, 1),
                    this->scenario->Get_player_AI(s, 1),
                    this->scenario->GetPlayerPosture(s), -1);
            }
        }
    }
}
