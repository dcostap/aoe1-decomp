// 00514010 TRIBE_Player::random_start - rough direct reconstruction
// Attempts:
// - Packet/decompiler shows two major paths: no existing TC => random TC/three villager placements, otherwise use existing master-id 0x6d; then multiplayer/random-game diplomacy setup.
// - Modeled key offsets/calls: object list +0x24/+0x28, world +0x3c, player id +0x4a, town-center master +0x1b4, villager master +0x14c, map dimensions via world->map +8/+0xc, find_by_master_id master 0x6d, set_map_loc/set_view_loc, diplomacy chat loop.
// - VC5 function-pointer surface for the virtual placement calls is still too approximate; using raw cdecl vtable calls compiles but source is far too small (.text 832 vs original 1268).
// - A real match needs proper typed virtual/member surfaces and exact random-placement arithmetic/liveness. Not accepted-drift quality.
struct Map { int pad0; int pad4; int h; int w; };
struct World { char pad[0x28]; Map* map; char pad2[0x10]; short player_count; char gap[2]; void** players; char pad3[0x38]; short local_player; };
struct ObjList { void* vptr; void* list; };
struct Game { int multiplayerGame(); int randomGame(); int playerID(int); };
extern Game* rge_base_game; class TChat { public: void setInChatGroup(int,int); }; extern TChat* chat;
extern int __cdecl debug_rand(char*, int); extern char s_C__msdev_work_age1_x1_tplayer_cp[]; extern "C" int __cdecl _ftol(float);
extern "C" void* __cdecl find_by_master_id_004634C0(int,int,int,int,int,int);
class TRIBE_Player { public:
    void* vptr; char pad04[0x20]; void* object_list; ObjList* obj_list2; char pad2c[0x10]; World* world; char pad40[0x0a]; short player_id; char pad4c[0xc8]; int locx; int locy; char pad11c[0x30]; void* villager_master; char pad150[0x64]; void* tc_master;
    int random_start(); void set_map_loc(int,int); void set_view_loc(float,float); int ally(int);
};
static float rndpos(TRIBE_Player* p, int line, int off) { int r=debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,line); int dim = line==0x631 ? p->world->map->w : p->world->map->h; return (float)((r*(dim-30))/0x7fff + 15) + 0.5f; }
int TRIBE_Player::random_start() {
    unsigned char found_ally = 0;
    if (*(int*)((char*)this->object_list + 4) == 0) {
        float w1 = rndpos(this,0x631,0); float h = rndpos(this,0x632,0); int tries=1;
        void* master = *(void**)((char*)this->object_list + 0x1b4);
        while (((unsigned char(__cdecl*)(void*,TRIBE_Player*,float,float,int,int,int,int,int,int,int))(*(void***)master)[8])(master,this,h+0.5f,w1+0.5f,0,0,1,1,1,1,1)) {
            w1 = rndpos(this,0x631,0); h = rndpos(this,0x632,0); if (++tries >= 5000) break;
        }
        if (tries < 5000) {
            void* obj = ((void*(__cdecl*)(void*,TRIBE_Player*,float,float,int))(*(void***)master)[6])(master,this,h,w1,0);
            this->set_map_loc(_ftol(h), _ftol(w1)); this->set_view_loc(h,w1);
            ((void(__cdecl*)(void*,float))(*(void***)obj)[0x25])(obj,10000.0f);
            for (int n=3;n;n--) {
                int bad=1; while (bad) { float x=w1, y=h; void* vm=*(void**)((char*)this->object_list+0x14c); if (!((unsigned char(__cdecl*)(void*,TRIBE_Player*,float,float,int,int,int,int,int,int,int))(*(void***)vm)[8])(vm,this,y,x,0,0,1,1,1,1,1)) { ((void(__cdecl*)(void*,TRIBE_Player*,float,float,int))(*(void***)vm)[6])(vm,this,y,x,0); bad=0; } }
            }
        }
    } else {
        void* obj = find_by_master_id_004634C0(0x6d,0,0,0,0,0); if (!obj) obj=**(void***)((char*)this->object_list+4); this->set_map_loc(_ftol(*(float*)((char*)obj+0x3c)), _ftol(*(float*)((char*)obj+0x38))); this->set_view_loc(*(float*)((char*)obj+0x38),*(float*)((char*)obj+0x3c));
    }
    if ((rge_base_game->multiplayerGame() || rge_base_game->randomGame()) && this->world->player_count > 1) {
        for (int i=1;i<this->world->player_count;i++) if (this->ally(i) && i != this->player_id) found_ally=1;
    }
    if (this->world->local_player == this->player_id && found_ally) for (int i=1;i<this->world->player_count;i++) if (i != this->player_id) for (int j=1;j<9;j++) if (rge_base_game->playerID(j)==i) chat->setInChatGroup(j,this->ally(i));
    return 0;
}
