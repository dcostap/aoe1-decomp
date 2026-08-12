// 00545800 RGE_Game_World::load_scenario8
// Attempt log:
// 1: seeded from load_scenario2 reconstruction, adding v8 uncompressed header block and second pass load_scenario_info2 call.
// 2: ABI probe: Player has one unnamed virtual slot between the two scenario-info loaders; this gives the observed +0x68/+0x70 calls.
// 3: direct fields and serialization widths follow the sibling load_scenario5-7 family. Remaining drift is local frame/liveness shape.
// 4: restored the clean typed World/Player surface after raw cursor experiments; object records use 4,4,4,4,2,1,4 byte widths.
// 5: unresolved exactness is structural local coloring and source-line block layout; no call or cleanup mismatch remains.
// Source audit: named fields preserve the proven World offsets. The float angle and 32-bit object ids follow the scenario format.
// Main-agent audit removed stale raw-offset macros, stack-adjacent aliases, and
// the float-to-ID type pun. The separately read header owns next_object_id.

extern "C" void __cdecl rge_read(int, void*, int);
extern "C" void __cdecl rge_read_uncompressed(int, void*, int);
extern "C" int __cdecl rge_close(int);
extern "C" void* __cdecl malloc(unsigned int);
extern "C" void __cdecl free(void*);

extern int world_update_counter;

class RGE_Scenario { public: int GetPlayerPosture(int,int); char* Get_player_AI(int,int,int); char* Get_CityPlan(int,int,char*); char* Get_BuildList(int,int,char*); };
class RGE_Player {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void setup_ai(char*, char*, char*, int, int);
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void make_scenario_obj(float, float, float, short, unsigned char, float);
    virtual void v25();
    virtual void load_scenario_info(int, int*, float);
    virtual void v26();
    virtual void load_scenario_info2(int, int*, float);
    void remake_visible_map();
};
class RGE_Player_Info { public: char pad[0x270]; int player_id[9]; };
class RGE_Game_World {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void scenario_make_map(int);
    virtual void v29(); virtual void v30(); virtual void v31(); virtual void load_scenario2(int, RGE_Player_Info&);
    virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60();
    virtual void scenario_init(int, RGE_Game_World*);
    virtual void load_scenario8(int handle, RGE_Player_Info& info);
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

void RGE_Game_World::load_scenario8(int handle, RGE_Player_Info& info)
{
    long count;
    long header_size;
    float obj_angle;
    unsigned char obj_state;
    short master_id;
    float world_z;
    float world_y;
    float world_x;
    int obj_id;
    int player_id_hash[9];
    int outer;

    world_update_counter = 0;
    rge_read_uncompressed(handle, &count, 4);
    if (count > 0) {
        void* buf = malloc(count);
        if (buf == 0) { rge_close(handle); return; }
        rge_read_uncompressed(handle, buf, count);
        free(buf);
    }
    rge_read(handle, &header_size, 4);
    this->scenario_init(handle, this);
    this->scenario_make_map(handle);
    int n = this->player_num;
    if (n > 0) { do { for (int k = 0; k < 9; ++k) player_id_hash[k] = -1; } while (n > 10); }
    int i = 0;
    if (n > 0) { int* ids = info.player_id; do { player_id_hash[*ids++] = i; ++i; } while (i < n); }
    i = 0;
    if (n > 0) { do { this->players[i]->remake_visible_map(); ++i; } while (i < this->player_num); }
    rge_read(handle, player_id_hash + 8, 4);
    i = 1;
    if (player_id_hash[8] > 1) {
        int* map = player_id_hash + 1;
        do {
            RGE_Player* pl;
            if (i >= this->player_num || *map < 0 || (pl = this->players[*map]) == 0) pl = this->players[0];
            pl->load_scenario_info(handle, player_id_hash, 1.11f);
            ++i;
            ++map;
        } while (i < player_id_hash[8]);
    }
    outer = 0;
    if (player_id_hash[8] > 0) {
        int* map = player_id_hash;
        do {
            rge_read(handle, &count, 4);
            int j = 0;
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
                    ++j;
                } while (j < count);
            }
            ++outer;
            ++map;
        } while (outer < player_id_hash[8]);
    }
    this->next_object_id = header_size;
    rge_read(handle, player_id_hash + 8, 4);
    i = 1;
    if (player_id_hash[8] > 1) {
        int* map = player_id_hash + 1;
        do {
            RGE_Player* pl;
            if (i >= this->player_num || *map < 0 || (pl = this->players[*map]) == 0) pl = this->players[0];
            pl->load_scenario_info2(handle, player_id_hash, 1.11f);
            ++i;
            ++map;
        } while (i < player_id_hash[8]);
    }
    rge_close(handle);
    i = 1;
    if (this->player_num > 1) {
        do {
            if (i >= player_id_hash[8]) return;
            if (this->players[i] != 0 && player_id_hash[i] > -1) {
                int s = i - 1;
                RGE_Player* target = this->players[player_id_hash[i]];
                int posture = this->scenario->GetPlayerPosture(s, -1);
                char* ai = this->scenario->Get_player_AI(s, 1, posture);
                char* city = this->scenario->Get_CityPlan(s, 1, ai);
                char* build = this->scenario->Get_BuildList(s, 1, city);
                target->setup_ai(build, city, ai, posture, -1);
            }
            ++i;
        } while (i < this->player_num);
    }
}
