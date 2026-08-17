// 00544E70 RGE_Game_World::load_scenario5
// Attempt log:
// 1: reconstructed the compressed header skip, player remap, object records, two player passes, and cleanup.
// 2: confirmed the +0x3c/+0x40/+0x5c/+0x68/+0x70/+0x74 World fields and Player_Info ids at +0x270.
// 3: confirmed 4-byte master/state reads, 2-byte angle, 1-byte id, and 4-byte object fields.
// 4: typed the Player virtual calls at +0x68, +0x60, +0x70, and +0x2c. This removed caller stack cleanup and cut the candidate to 822 bytes.
// 5: separated scenario_player_num from player_id_hash[8] and object_count from the header count. Frame moved to 0x48 and shape reached 84.87%.
// 6: kept the natural player_id_hash + 1 ownership for both mapped-player passes; the old &obj_id form was a stack-slot alias.
// 7: tested long world_y for the direct next_object_id transfer; output was unchanged. The uninitialized transfer remains binary evidence.
// 8: tested volatile world_y; output was unchanged and the qualifier was removed as unsupported source steering.
// 9: tested one-argument GetPlayerPosture; it worsened the footer. Restored the donor-backed two-argument surface used by the current best candidate.
// 10: replaced raw coordinate/value bit-casts with their typed float locals and
// kept the separately read next-object ID. This restored the original 0x4c frame
// and improved shape to 92.43%, with all 28 ordered calls still aligned.
// Left in scratch: remaining drift is structural local coloring and the final setup loop.
// 11: spelled mapped-player invalid-index guards as <= -1; this recovered the original cmp/jle blocks in both load passes.
// 12: confirmed the one-argument GetPlayerPosture ABI from the class packet; the early -1 belongs to loadAIInformation.
// 13: removed the saved cleanup-player local and used a positive scenario bound guard; this recovered the original cleanup CFG and reduced the size gap to 2 bytes.
// 14: a pointer-first cleanup local regressed register lifetime; restored the direct player lookup, which remains the cleanest candidate.
// 15: object-loop slot-pointer and direct-map spellings were compiler duplicates; retained the named mapped index.
// 16: a typed player local removed the two-byte size gap but changed body scheduling and worsened resync; rolled back.
// 17: a players-array alias changed the frame to 0x50; rolled back. The donor-backed make_scenario_obj pointer return emits unchanged code.
// 18: the prior cleanup player local reached diff 341 but added two bytes and lost structural islands; restored the clean cleanup form.
// 19: an integer slot-value cast was compiler-equivalent. Final clean source remains 814 bytes versus the 812-byte target.
// 20: this claim tested 20 distinct source hypotheses across object-slot ownership,
// guard topology, declaration order, typed stream locals, ABI declarations,
// aggregate layout, and factor lifetime. The best natural variant precomputed
// `this->players + pid`, reached 812 bytes and 84 differing bytes, but changed
// the proven target object-guard lowering and lost exact blocks. It is not kept.
// 21: pointer-slot forms, direct pointer arithmetic, comma assignment, early
// continues, long versus int mapped ids, direct versus named factors, widened
// stream locals, complete World/Player_Info declaration surfaces, and canonical
// Player_Info extents either duplicated the baseline or moved farther.
// Final clean validation for this claim remains the 814-byte typed reconstruction;
// all 28 calls align, but the first structural mismatch is the object block at +0x11a.

typedef unsigned char uchar;
extern "C" void __cdecl rge_read_uncompressed(int file, void* dst, int size);
extern "C" void __cdecl rge_read(int file, void* dst, int size);
extern "C" int __cdecl rge_close(int file);
extern "C" void* __cdecl malloc(unsigned int size);
extern "C" void __cdecl free(void* ptr);
extern "C" int world_update_counter;
class RGE_Static_Object;
class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(uchar);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int);
    virtual int isEnemy(int);
    virtual int isAlly(int);
    virtual int isNeutral(int);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int, int);
    virtual void loadAIInformation(char*, char*, char*, int, int);
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    virtual void kickAI(int);
    virtual int strategicNumber(int);
    virtual void sendGameOrder(void*, void*, float, float);
    virtual void sendAddWaypointCommand(int, void*, int);
    virtual void processAddWaypointCommand(int, void*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int);
    virtual void trackUnitGather(int, int, int);
    virtual RGE_Static_Object* make_scenario_obj(float, float, float, short, uchar, float);
    virtual void scenario_save(int);
    virtual void scenario_load(int, long*, float);
    virtual void scenario_postsave(int);
    virtual void scenario_postload(int, long*, float);
    void remake_visible_map();
};
class RGE_Scenario { public: int GetPlayerPosture(int); char* Get_player_AI(int,int); char* Get_CityPlan(int,int); char* Get_BuildList(int,int); };
struct RGE_Player_Info { char gap[0x270]; int player_id[16]; };
#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
class RGE_Game_World { public:
    VPAD16(0) VPAD8(16) VPAD4(24) virtual void scenario_make_map(int file); VPAD16(29) VPAD16(45) virtual void scenario_init(int file, RGE_Game_World* self);
    char gap_04[0x38]; short player_num; char gap_3e[2]; RGE_Player** players; char gap_44[0x18]; RGE_Scenario* scenario; char gap_60[8]; int next_object_id; char gap_6c[4]; int scenario_object_id; uchar scenario_object_flag;
    void load_scenario5(int file, RGE_Player_Info& info);
};
void RGE_Game_World::load_scenario5(int file, RGE_Player_Info& info)
{
    long count; long object_count; long header_size; long id; short obj_angle;
    float world_z; float world_y; float world_x; float object_value;
    long next_object_id; long player_id_hash[9]; long scenario_player_num;
    int outer; float load_factor;
    world_update_counter = 0;
    rge_read_uncompressed(file, &count, 4);
    if (count > 0) { void* p = malloc(count); if (p == 0) { rge_close(file); return; } rge_read_uncompressed(file, p, count); free(p); }
    rge_read(file, &next_object_id, 4);
    this->scenario_init(file, this); this->scenario_make_map(file);
    int n = this->player_num;
    if (n > 0) { do { for (int k=0;k<9;k++) player_id_hash[k] = -1; } while (n > 10); }
    int i=0;
    if (n > 0) { int* ids = info.player_id; do { player_id_hash[*ids++] = i; i++; } while (i < n); }
    i=0;
    if (n > 0) { do { this->players[i]->remake_visible_map(); i++; } while (i < this->player_num); }
    rge_read(file, &scenario_player_num, 4);
    i = 1;
    if (scenario_player_num > 1) { long* map = player_id_hash + 1; do { RGE_Player* pl; if (i >= this->player_num || *map <= -1 || (pl=this->players[*map])==0) pl=this->players[0]; load_factor=1.06f; pl->scenario_load(file, player_id_hash, load_factor); i++; map++; } while (i < scenario_player_num); }
    outer = 0;
    if (scenario_player_num > 0) { long* map = player_id_hash; do { rge_read(file,&object_count,4); int j=0; if (object_count>0) { do { rge_read(file,&world_z,4); rge_read(file,&world_y,4); rge_read(file,&world_x,4); rge_read(file,&header_size,4); rge_read(file,&obj_angle,2); rge_read(file,&id,1); rge_read(file,&object_value,4); int pid=*map; if (pid>=0 && this->players[pid]!=0) { this->scenario_object_flag=1; this->scenario_object_id=header_size; this->players[pid]->make_scenario_obj(world_z, world_y, world_x, obj_angle, id, object_value); this->scenario_object_flag=0; } j++; } while (j<object_count); } outer++; map++; } while (outer < scenario_player_num); }
    this->next_object_id = next_object_id;
    rge_read(file, &scenario_player_num, 4);
    i = 1;
    if (scenario_player_num > 1) { long* map = player_id_hash + 1; do { RGE_Player* pl; if (i >= this->player_num || *map <= -1 || (pl=this->players[*map])==0) pl=this->players[0]; load_factor=1.06f; pl->scenario_postload(file, player_id_hash, load_factor); i++; map++; } while (i < scenario_player_num); }
    rge_close(file);
    i=1;
    if (this->player_num > 1) { do { if (i < scenario_player_num) { if (this->players[i]!=0 && player_id_hash[i] > -1) { int idx=i-1; this->players[player_id_hash[i]]->loadAIInformation(this->scenario->Get_BuildList(idx,1),this->scenario->Get_CityPlan(idx,1),this->scenario->Get_player_AI(idx,1),this->scenario->GetPlayerPosture(idx),-1); } } else return; i++; } while (i < this->player_num); }
}
