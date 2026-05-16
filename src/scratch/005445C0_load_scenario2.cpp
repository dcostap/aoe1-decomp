// 005445C0 RGE_Game_World::load_scenario2
// Attempt log:
// 1: natural reconstruction from packet using byte-offset class surface; explicit __thiscall function-pointer casts are rejected by VC5 warning policy.
// 2: switched indirect calls to local virtual surfaces with dummy slots; compiles but broad mismatch, first diff stack frame 0x68 vs original 0x60.
// 3: remaining lead is local-slot coalescing/reuse: original reuses the same stack slots for object fields and loop/state values, and even reuses a dead incoming parameter slot for outer index.

extern "C" void __cdecl rge_read(int, void*, int);
extern "C" int __cdecl rge_close(int);

#define world_update_counter (*(int*)0x00886C10)
#define W_S(off) (*(short*)((char*)this + (off)))
#define W_B(off) (*(unsigned char*)((char*)this + (off)))
#define W_I(off) (*(int*)((char*)this + (off)))
#define W_P(off) (*(void**)((char*)this + (off)))

class RGE_Scenario {
public:
    int GetPlayerPosture(int, int);
    char* Get_player_AI(int, int, int);
    char* Get_CityPlan(int, int, int);
    char* Get_BuildList(int, int, int);
};
class RGE_Player {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void setup_ai(char*, char*, char*, int, int);
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void make_scenario_obj(float, float, float, short, unsigned char, int);
    virtual void v25();
    virtual void load_scenario_info(int, int*, int);
    void remake_visible_map();
};
class RGE_Player_Info { public: char pad[0x270]; int player_id[9]; };

class RGE_Game_World {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void scenario_make_map(int);
    virtual void v29(); virtual void v30(); virtual void v31(); virtual void load_scenario2(int handle, RGE_Player_Info& info);
    virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60();
    virtual void scenario_init(int, RGE_Game_World*);
};

void RGE_Game_World::load_scenario2(int handle, RGE_Player_Info& info)
{
    int player_id_hash[9];
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

    int player_num = W_S(0x3c);
    if (player_num > 0) {
        do { for (int k = 0; k < 9; k++) player_id_hash[k] = -1; } while (player_num > 10);
    }
    int i = 0;
    if (player_num > 0) {
        int* p = &info.player_id[0];
        do { int idx = *p++; player_id_hash[idx] = i; i++; } while (i < player_num);
    }
    int j = 0;
    if (player_num > 0) {
        do { ((RGE_Player**)W_P(0x40))[j]->remake_visible_map(); j++; } while (j < W_S(0x3c));
    }

    rge_read(handle, &scenario_player_num, 4);
    int spn = scenario_player_num;
    j = 0;
    if (spn > 0) { do { rge_read(handle, &master_player_id, 1); rge_read(handle, &obj_state, 1); j++; } while (j < spn); }

    int outer = 0;
    if (spn > 0) {
        int* map = player_id_hash;
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
                    rge_read(handle, &master_player_id, 1);
                    rge_read(handle, &id, 4);
                    int mapped = *map;
                    if (mapped >= 0) {
                        RGE_Player* pl = ((RGE_Player**)W_P(0x40))[mapped];
                        if (pl != 0) { W_B(0x74) = 1; W_I(0x70) = obj_id; pl->make_scenario_obj(world_z, world_y, world_x, master_id, master_player_id, id); W_B(0x74) = 0; }
                    }
                    j++;
                } while (j < count);
            }
            outer++; map++;
        } while (outer < spn);
    }

    W_I(0x68) = obj_id;
    rge_read(handle, rem, 13);
    j = 1;
    if (spn > 1) {
        int* map = &player_id_hash[1];
        do {
            RGE_Player* pl;
            if (j < W_S(0x3c) && *map > -1 && (pl = ((RGE_Player**)W_P(0x40))[*map]) != 0) { } else { pl = ((RGE_Player**)W_P(0x40))[0]; }
            pl->load_scenario_info(handle, player_id_hash, 0x3f83d70a);
            j++; map++;
        } while (j < spn);
    }

    rge_close(handle);
    j = 1;
    if (W_S(0x3c) > 1) {
        do {
            if (j >= spn) return;
            if (((RGE_Player**)W_P(0x40))[j] != 0 && player_id_hash[j] > -1) {
                int s = j - 1;
                RGE_Player* target = ((RGE_Player**)W_P(0x40))[player_id_hash[j]];
                RGE_Scenario* scen = (RGE_Scenario*)W_P(0x5c);
                int posture = scen->GetPlayerPosture(s, -1);
                char* ai = scen->Get_player_AI(s, 1, posture);
                char* city = scen->Get_CityPlan(s, 1, (int)ai);
                char* build = scen->Get_BuildList(s, 1, (int)city);
                target->setup_ai(build, city, ai, posture, -1);
            }
            j++;
        } while (j < W_S(0x3c));
    }
}
