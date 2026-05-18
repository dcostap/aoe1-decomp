// 00543A00 RGE_Game_World::save_scenario
// Attempt log:
// try 1: packet-grounded reconstruction of scenario save: derive .scn path, open, write version/header/player/world data, serialize per-player object lists excluding type 0x19, close, unlink on error. Helper-factored object serialization compiled too short (832B vs 1017B).
// try 2: expanded object serialization separately for both object lists to better match original repeated write blocks. Current source compiles too short (976B vs 1017B).
// try 3: temporary diagnostic extra writes reached byte compare, then removed. Diagnostic compare broad mismatch (81.1209% positional / 79.6460% edit); first mismatch at prologue/register allocation, rebuilt saves EBX and misses original EBP=this early pattern.
// try 4: modeled filename base copy up to '.', kill .scn via unlink, final open path via sprintf with base_game path +0xc17.
// try 5: modeled version write as TRIAL? 1.10 : 1.11 and base_game scenario header write.
// try 6: modeled scenario_data +0x68 write, info save at +0x5c, map save at +0x28, player count write.
// try 7: modeled pre-save loop over players 1..num_players-1 via virtual +0x64 and post-save loop via virtual +0x6c.
// try 8: modeled per-player count across two object lists +0x28/+0x2c excluding type 0x19, then write count.
// try 9: modeled repeated object serialization fields +0x38/+0x3c/+0x40/+0x04, type id +0x10, byte +0x48, and angle/sprite-direction fallback.
// GIVEUP blockers: exact RGE_Game_World/player/object/list layouts, vtable slot declarations, preserving original no-EBX prologue with EBP=this, and exact source shape for duplicated object-list loops/angle temporary. No inline asm used; no accepted_drift proposal.

typedef unsigned char byte;
extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" int __cdecl unlink(const char*);
extern "C" int __cdecl rge_open(const char*, int, int);
extern "C" void __cdecl rge_write_uncompressed(int, const void*, int);
extern "C" void __cdecl rge_write(int, const void*, int);
extern "C" void __cdecl rge_close(int);
extern int rge_write_error;
class RGE_Base_Game { public: char gap[0x0c]; char* path; byte check_prog_argument(char*); void write_scenario_header(int); };
extern RGE_Base_Game* rge_base_game;
struct ObjType { char gap[4]; byte type; char gap5[0x0b]; short id; };
struct GameObj { char gap00[4]; GameObj* next; ObjType* type; char gap0c[0x2c]; int x; int y; int z; int a4; char gap4c[0x50]; float angle; };
struct ObjList { char gap[4]; GameObj* first; };
struct PlayerData { char gap00[0x28]; ObjList* list1; ObjList* list2; char gap30[0x34]; virtual void v0(); virtual void v1(); virtual void v2(); virtual void save_pre(int); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void save_post(int); };
struct MapObj { virtual void v0(); virtual void v1(); virtual void v2(); virtual void save(int); };
struct InfoObj { virtual void v0(); virtual void v1(); virtual void v2(); virtual void save(int); };
class RGE_Game_World { public: char gap00[0x28]; MapObj* map; char gap2c[0x10]; short num_players; PlayerData** players; char gap44[0x18]; InfoObj* info; char gap60[8]; int scenario_data; byte save_scenario(char* name); };

byte RGE_Game_World::save_scenario(char* name)
{
    char scenario_name[300]; char kill_name[300];
    int scenario_player_num = (short)this->num_players;
    int i; float obj_angle; int count;
    char* p = name; int n = 0;
    while (*p != '.') { kill_name[n++] = *p++; }
    kill_name[n] = 0;
    sprintf(scenario_name, "%s%s.scn", rge_base_game->path + 0xc17, kill_name);
    unlink(scenario_name);
    sprintf(scenario_name, "%s%s", rge_base_game->path + 0xc17, name);
    int fd = rge_open(scenario_name, 0x8301, 0x180);
    if (fd == -1) return 0;
    rge_write_error = 0;
    if (rge_base_game->check_prog_argument("TRIAL") == 1) rge_write_uncompressed(fd, "1.10", 4);
    else rge_write_uncompressed(fd, "1.11", 4);
    rge_base_game->write_scenario_header(fd);
    rge_write(fd, &this->scenario_data, 4);
    this->info->save(fd);
    this->map->save(fd);
    rge_write(fd, &scenario_player_num, 4);
    for (i = 1; i < (short)this->num_players; ++i) this->players[i]->save_pre(fd);
    for (i = 0; i < (short)this->num_players; ++i) {
        PlayerData* pl = this->players[i];
        count = 0;
        GameObj* o = pl->list1->first;
        while (o) { if (o->type->type != 0x19) ++count; o = o->next; }
        o = pl->list2->first;
        while (o) { if (o->type->type != 0x19) ++count; o = o->next; }
        rge_write(fd, &count, 4);
        o = pl->list1->first;
        while (o) {
            if (o->type->type != 0x19) {
                rge_write(fd, &o->x, 4); rge_write(fd, &o->y, 4); rge_write(fd, &o->z, 4); rge_write(fd, &o->next, 4); rge_write(fd, &o->type->id, 2); rge_write(fd, (char*)o + 0x48, 1);
                if (o->type->type > 0x1e && o->type->type < 0x5a) obj_angle = o->angle; else obj_angle = (float)*(unsigned char*)((char*)o + 0x35);
                rge_write(fd, &obj_angle, 4);
            }
            o = o->next;
        }
        o = pl->list2->first;
        while (o) {
            if (o->type->type != 0x19) {
                rge_write(fd, &o->x, 4); rge_write(fd, &o->y, 4); rge_write(fd, &o->z, 4); rge_write(fd, &o->next, 4); rge_write(fd, &o->type->id, 2); rge_write(fd, (char*)o + 0x48, 1);
                if (o->type->type > 0x1e && o->type->type < 0x5a) obj_angle = o->angle; else obj_angle = (float)*(unsigned char*)((char*)o + 0x35);
                rge_write(fd, &obj_angle, 4);
            }
            o = o->next;
        }
    }
    rge_write(fd, &scenario_player_num, 4);
    for (i = 1; i < (short)this->num_players; ++i) this->players[i]->save_post(fd);
    rge_close(fd);
    if (rge_write_error) { unlink(scenario_name); return 0; }
    return 1;
}
