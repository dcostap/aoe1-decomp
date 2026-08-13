// 005451A0 RGE_Game_World::load_scenario6
// Attempt log:
// - Rebuilt the loader with typed World, Player, Scenario, and Player_Info surfaces.
// - Restored the six-argument make_scenario_obj ABI and the +0x6C World gap.
// - Modeled the stream as three coordinates, a short type, a byte state, and a float value.
// - Recovered the initial next-object dword and the +0x270 player-id remap array.
// - Changed the visible-map bound to this->player_num. This moved the first mismatch later.
// - Best check: 815 bytes versus 812, 487 differing bytes, 90.07% shape, 28 ordered calls.
// - Remaining drift starts at the scenario-player count home (+0x58 versus +0x60).
//   Later drift covers the object guard and the final player setup loop.
// - Spelled the binary-proven negative guards as <= -1. This produced 818 bytes,
//   351 differing bytes, and exact cmp/jle guard blocks.
// - Restored the one-argument GetPlayerPosture ABI from scenario.cpp. The best
//   typed candidate is 816 bytes with 344 differing bytes and 92.03% shape.
// - A direct final-loop receiver changed the frame to 0x48 and was rolled back.
//   A same-TU do-while footer also enlarged the body and was rolled back.
// - Separated the serialized scenario-player count from the nine-entry hash.
//   This moved its home from +0x58 to the binary-proven +0x60, reducing the
//   positional diff to 341 bytes and raising exact-block coverage to 66.89%.
// - Removed the final setup receiver temp. The natural direct mapped-player
//   call keeps the 0x4C frame and reduces the rebuilt size to 814 bytes.
//   Guard and slot-pointer spellings emitted duplicate code; the direct form
//   remains the clean source reconstruction.

typedef unsigned char uchar;
extern "C" void __cdecl rge_read_uncompressed(int, void*, int);
extern "C" void __cdecl rge_read(int, void*, int);
extern "C" int __cdecl rge_close(int);
extern "C" void* __cdecl malloc(unsigned int);
extern "C" void __cdecl free(void*);
extern "C" int world_update_counter;

struct RGE_Player_Info {
    char gap_00[0x270];
    int player_id[16];
};

struct RGE_Static_Object;
struct RGE_Scenario { int GetPlayerPosture(int); char* Get_player_AI(int,int); char* Get_CityPlan(int,int); char* Get_BuildList(int,int); };
struct RGE_Player {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void setup(char*,char*,char*,int,int); 
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c(); virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c(); virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c(); virtual RGE_Static_Object* make_scenario_obj(float,float,float,short,uchar,float); virtual void v64(); virtual void load1(int, int*, float); virtual void v6c(); virtual void load2(int, int*, float);
    void remake_visible_map();
};
struct RGE_Game_World {
    virtual void pad00(); virtual void pad04(); virtual void pad08(); virtual void pad0c(); virtual void pad10(); virtual void pad14(); virtual void pad18(); virtual void pad1c();
    virtual void pad20(); virtual void pad24(); virtual void pad28(); virtual void pad2c(); virtual void pad30(); virtual void pad34(); virtual void pad38(); virtual void pad3c();
    virtual void pad40(); virtual void pad44(); virtual void pad48(); virtual void pad4c(); virtual void pad50(); virtual void pad54(); virtual void pad58(); virtual void pad5c();
    virtual void pad60(); virtual void pad64(); virtual void pad68(); virtual void pad6c(); virtual void load_after(int); virtual void pad74();
    virtual void pad78(); virtual void pad7c(); virtual void pad80(); virtual void pad84(); virtual void pad88(); virtual void pad8c(); virtual void pad90(); virtual void pad94();
    virtual void pad98(); virtual void pad9c(); virtual void pada0(); virtual void pada4(); virtual void pada8(); virtual void padac(); virtual void padb0(); virtual void padb4();
    virtual void padb8(); virtual void padbc(); virtual void padc0(); virtual void padc4(); virtual void padc8(); virtual void padcc(); virtual void padd0(); virtual void padd4();
    virtual void padd8(); virtual void paddc(); virtual void pade0(); virtual void pade4(); virtual void pade8(); virtual void padec(); virtual void padf0(); virtual void load_before(int, RGE_Game_World*);
    char gap04[0x38]; short player_num; char gap3e[2]; RGE_Player** players; char gap44[0x18]; RGE_Scenario* scenario; char gap60[8]; int next_object_id; char gap6c[4]; int scenario_object_id; uchar scenario_object_flag;
    void load_scenario6(int file, RGE_Player_Info& info);
};

void RGE_Game_World::load_scenario6(int file, RGE_Player_Info& info)
{
    int count;
    int next_object_id;
    int header_size;
    uchar id;
    short obj_angle;
    float world_z;
    float world_y;
    float world_x;
    float object_value;
    int player_id_hash[9];
    int scenario_player_count;
    int obj_count;
    int i,j;
    void* buf;
    RGE_Player* p;
    world_update_counter = 0;
    rge_read_uncompressed(file, &count, 4);
    if (count > 0) {
        buf = malloc(count);
        if (buf == 0) { rge_close(file); return; }
        rge_read_uncompressed(file, buf, count);
        free(buf);
    }
    rge_read(file, &next_object_id, 4);
    this->load_before(file, this);
    this->load_after(file);
    int n = this->player_num;
    if (n > 0) {
        do { for (i=0;i<9;i++) player_id_hash[i] = -1; } while (n > 10);
    }
    for (i=0; i<n; i++) player_id_hash[info.player_id[i]] = i;
    for (i=0; i<this->player_num; i++) this->players[i]->remake_visible_map();
    rge_read(file, &scenario_player_count, 4);
    for (i=1; i<scenario_player_count; i++) {
        if (i >= this->player_num || player_id_hash[i] <= -1 || (p=this->players[player_id_hash[i]])==0) p=this->players[0];
        p->load1(file, player_id_hash, 1.07f);
    }
    for (i=0; i<scenario_player_count; i++) {
        rge_read(file, &obj_count, 4);
        for (j=0; j<obj_count; j++) {
            rge_read(file, &world_z, 4); rge_read(file, &world_y, 4); rge_read(file, &world_x, 4); rge_read(file, &header_size, 4); rge_read(file, &obj_angle, 2); rge_read(file, &id, 1); rge_read(file, &object_value, 4);
            if (player_id_hash[i] < 0) continue;
            if (0 == this->players[player_id_hash[i]]) continue;
            this->scenario_object_flag=1;
            this->scenario_object_id=header_size;
            this->players[player_id_hash[i]]->make_scenario_obj(world_z, world_y, world_x, obj_angle, id, object_value);
            this->scenario_object_flag=0;
        }
    }
    this->next_object_id = next_object_id;
    rge_read(file, &scenario_player_count, 4);
    for (i=1; i<scenario_player_count; i++) { if (i >= this->player_num || player_id_hash[i] <= -1 || (p=this->players[player_id_hash[i]])==0) p=this->players[0]; p->load2(file, player_id_hash, 1.07f); }
    rge_close(file);
    for (i=1; i<this->player_num && i<scenario_player_count; i++) if (this->players[i] && player_id_hash[i] > -1) { int k=i-1; this->players[player_id_hash[i]]->setup(this->scenario->Get_BuildList(k,1), this->scenario->Get_CityPlan(k,1), this->scenario->Get_player_AI(k,1), this->scenario->GetPlayerPosture(k), -1); }
}
