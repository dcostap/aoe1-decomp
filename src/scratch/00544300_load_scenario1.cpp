// VA: 00544300 RGE_Game_World::load_scenario1
// Source: World.cpp lines 2489-2604
// Attempt log:
// 1: broad reconstruction from packet: read rem/player data, rebuild player mapping, load object records, attach/initialize objects; compiles too small (624 vs 691) and class gap initially needed fixing.
// 2: tried /O1 /Oy flag probe; object shrank to 591 and failed configured size, flag removed.
// 3: reviewed packet line map: original has two nested object loops plus later player AI setup; current source only approximates both.
// 4: local player remap table behavior modeled loosely but original has repeated 9-dword fills and info+0x270 player order table.
// 5: object record read order modeled from asm locals, but exact object creation/vtable +60/+68 surfaces missing.
// 6: final AI setup calls through player manager (+5C) are approximated with get1 placeholders.
// 7: current source lacks exact stack/local layout at +14/+18/+1c... and many rge_read temporaries.
// 8: no custom flags retained; default still too small.
// 9: not accepted_drift-safe because rebuilt stops at size 624 vs original 691.
// 10: left in scratch pending real RGE_Game_World/RGE_Player/object load surfaces and exact local topology.

extern "C" void __cdecl rge_read(int fd, void* dst, int size);
extern "C" void __cdecl read_string(int fd);

class RGE_Player { public: void remake_visible_map(); int get1(int,int); int get2(int,int,int); int get3(int,int,int); int get4(int,int,int); };
class RGE_Static_Object { public: virtual void v00(); char gap[0x28]; virtual void setup_ai(int,int,int,int); virtual void load_scn(int, void*, float); virtual void load_data(int,int,int,int,int,int); };
struct RGE_Player_Info { char gap[0x270]; int player_ids[16]; };

class RGE_Game_World {
public:
    virtual void v00(); char gap04[0x3C-4]; short player_count; RGE_Player** players;
    char gap44[0x5C-0x44]; void* ai_info; char gap60[8]; int rem;
    char loading_flag; char gap75[1]; int load_id;
    virtual void load_scenario0(int fd, RGE_Game_World* self); // approximate +70
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    virtual void vfDC();
    virtual void vfE0();
    virtual void vfE4();
    virtual void vfE8();
    virtual void vfEC();
    virtual void load_players(int fd, RGE_Game_World* self); // +f4 guess
    void load_scenario1(int fd, RGE_Player_Info& info);
};

void RGE_Game_World::load_scenario1(int fd, RGE_Player_Info& info)
{
    int map[10]; int count; int object_count; int id, owner, x, y, z, angle; short master; unsigned char state; float pos[3];
    rge_read(fd, &this->rem, 4);
    this->load_players(fd, this);
    this->load_scenario0(fd, this);
    int pc = this->player_count;
    if (pc > 0) {
        for (;;) { for (int k=0;k<9;k++) map[k] = -1; if (pc <= 10) break; }
        for (int i=0;i<pc;i++) map[info.player_ids[i]] = i;
        for (int j=0;j<pc;j++) this->players[j]->remake_visible_map();
    }
    rge_read(fd,&count,4);
    for (int a=0;a<count;a++) { rge_read(fd,&state,1); rge_read(fd,&state,1); }
    for (int p=0;p<count;p++) {
        rge_read(fd,&object_count,4);
        for (int n=0;n<object_count;n++) {
            rge_read(fd,&id,4); rge_read(fd,&owner,4); rge_read(fd,&x,4); rge_read(fd,&y,4); rge_read(fd,&master,2); rge_read(fd,&state,1); rge_read(fd,&angle,4);
            if (p < this->player_count && map[p] >= 0 && this->players[p]) { this->loading_flag=1; this->load_id=y; this->players[map[p]]->get1(id,owner); this->loading_flag=0; }
        }
    }
    this->rem = pos[0];
    rge_read(fd,pos,13);
    for (int q=1;q<count;q++) {
        RGE_Player* pl = (q < this->player_count && map[q] > -1 && this->players[map[q]]) ? this->players[map[q]] : this->players[0];
        pl->get1(fd, -1);
    }
    read_string(fd);
    for (int r=1;r<this->player_count && r<count;r++) {
        if (this->players[r]) { int idx=map[r]; RGE_Static_Object* obj=(RGE_Static_Object*)this->players[idx]->get1(r-1,-1); obj->setup_ai(0,0,0,0); }
    }
}
