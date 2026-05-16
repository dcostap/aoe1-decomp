// 00544E70 RGE_Game_World::load_scenario5
// Attempt log:
// 1: adapted load_scenario3 scratch to load_scenario5 packet: smaller frame, no rem[13]/byte-pair skip, two player-load passes (+0x68 then +0x70).
// 2: modeled world_update_counter zero before pushes, rge_read_uncompressed count/malloc/read/free early block.
// 3: used real padded RGE_Game_World virtuals for +0xF4 and +0x70 load calls (same pattern as load_scenario3 scratch).
// 4: modeled player_id_hash[9] initialization and player-info id remap; compiler emits similar rep-stos family but stack base differs.
// 5: modeled first per-player load pass through vtable +0x68 with 1.06f constant (0x3F87AE14).
// 6: modeled object-read nested loops and object create virtual +0x60 with scenario_object_flag/id stores.
// 7: modeled second per-player load pass through vtable +0x70, then rge_close and scenario AI/city/build/posture setup call chain.
// 8: current local check builds same-size 812B but first mismatch is frame/local placement: original sub esp,4Ch / &count=[esp], rebuilt sub esp,40h / &count=[esp+44h].
// 9: warning remains for deliberate binary-observed uninitialized world_y/next_object_id transfer.
// 10: left in scratch; broad stack/local and raw player virtual surface drift, not accepted_drift.

typedef unsigned char uchar;
extern "C" void __cdecl rge_read_uncompressed(int file, void* dst, int size);
extern "C" void __cdecl rge_read(int file, void* dst, int size);
extern "C" int __cdecl rge_close(int file);
extern "C" void* __cdecl malloc(unsigned int size);
extern "C" void __cdecl free(void* ptr);
extern "C" int world_update_counter;
class RGE_Player { public: void remake_visible_map(); };
class RGE_Scenario { public: int GetPlayerPosture(int,int); char* Get_player_AI(int,int); char* Get_CityPlan(int,int); char* Get_BuildList(int,int); };
struct RGE_Player_Info { char gap[0x270]; int player_id[16]; };
#define VTBL(o) (*(void***)(o))
#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define PLAYER_CREATE(o,a,b,c,d,e,f) ((void (__cdecl*)(void*,int,int,int,int,int,int))VTBL(o)[0x18])((o),(a),(b),(c),(d),(e),(f))
#define PLAYER_LOAD68(o,f,map,flt) ((void (__cdecl*)(void*,int,int*,float))VTBL(o)[0x1a])((o),(f),(map),(flt))
#define PLAYER_LOAD70(o,f,map,flt) ((void (__cdecl*)(void*,int,int*,float))VTBL(o)[0x1c])((o),(f),(map),(flt))
#define PLAYER_SETUP(o,a,b,c,d,e) ((void (__cdecl*)(void*,char*,char*,char*,int,int))VTBL(o)[0x0b])((o),(a),(b),(c),(d),(e))
class RGE_Game_World { public:
    VPAD16(0) VPAD8(16) VPAD4(24) virtual void load2(int file); VPAD16(29) VPAD16(45) virtual void load1(int file, RGE_Game_World* self);
    char gap_04[0x38]; short player_num; char gap_3e[2]; RGE_Player** players; char gap_44[0x18]; RGE_Scenario* scenario; char gap_60[8]; int next_object_id; char gap_6c[4]; int scenario_object_id; uchar scenario_object_flag;
    void load_scenario5(int file, RGE_Player_Info& info);
};
void RGE_Game_World::load_scenario5(int file, RGE_Player_Info& info)
{
    long count; long header_size; long id; float obj_angle; uchar obj_state; short master_id; float world_z; float world_y; float world_x; long obj_id; long player_id_hash[9]; int outer; float load_factor;
    world_update_counter = 0;
    rge_read_uncompressed(file, &count, 4);
    if (count > 0) { void* p = malloc(count); if (p == 0) { rge_close(file); return; } rge_read_uncompressed(file, p, count); free(p); }
    rge_read(file, player_id_hash, 4);
    void** vt = VTBL(this);
    this->load1(file, this); this->load2(file);
    int n = this->player_num;
    if (n > 0) { do { for (int k=0;k<9;k++) player_id_hash[k] = -1; } while (n > 10); }
    int i=0;
    if (n > 0) { int* ids = info.player_id; do { player_id_hash[*ids++] = i; i++; } while (i < n); }
    i=0;
    if (n > 0) { do { this->players[i]->remake_visible_map(); i++; } while (i < this->player_num); }
    rge_read(file, player_id_hash + 8, 4);
    i = 1;
    if (player_id_hash[8] > 1) { long* map = &obj_id; do { RGE_Player* pl; if (i >= this->player_num || *map < 0 || (pl=this->players[*map])==0) pl=this->players[0]; load_factor=1.06f; PLAYER_LOAD68(pl,file,(int*)player_id_hash,load_factor); i++; map++; } while (i < player_id_hash[8]); }
    outer = 0;
    if (player_id_hash[8] > 0) { long* map = player_id_hash; do { rge_read(file,&count,4); int j=0; if (count>0) { do { rge_read(file,&world_z,4); rge_read(file,&master_id,4); rge_read(file,&obj_state,4); rge_read(file,&header_size,4); rge_read(file,&obj_angle,2); rge_read(file,&id,1); rge_read(file,&obj_id,4); int pid=*map; if (pid>=0 && this->players[pid]!=0) { this->scenario_object_flag=1; this->scenario_object_id=header_size; PLAYER_CREATE(this->players[pid],*(int*)&world_z,*(int*)&master_id,*(int*)&obj_state,*(int*)&obj_angle,id,obj_id); this->scenario_object_flag=0; } j++; } while (j<count); } outer++; map++; } while (outer < player_id_hash[8]); }
    this->next_object_id = *(long*)&world_y;
    rge_read(file, player_id_hash + 8, 4);
    i = 1;
    if (player_id_hash[8] > 1) { long* map = &obj_id; do { RGE_Player* pl; if (i >= this->player_num || *map < 0 || (pl=this->players[*map])==0) pl=this->players[0]; load_factor=1.06f; PLAYER_LOAD70(pl,file,(int*)player_id_hash,load_factor); i++; map++; } while (i < player_id_hash[8]); }
    rge_close(file);
    i=1;
    if (this->player_num > 1) { do { if (i >= player_id_hash[8]) return; if (this->players[i]!=0 && player_id_hash[i] > -1) { int idx=i-1; RGE_Player* pl=this->players[player_id_hash[i]]; PLAYER_SETUP(pl,this->scenario->Get_BuildList(idx,1),this->scenario->Get_CityPlan(idx,1),this->scenario->Get_player_AI(idx,1),this->scenario->GetPlayerPosture(idx,-1),-1); } i++; } while (i < this->player_num); }
}
