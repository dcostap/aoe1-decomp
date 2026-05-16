// VA: 00544B90 RGE_Game_World::load_scenario4
// Attempt log:
// initial rough reconstruction from packet: skip old header blob, load player mapping, remake visible maps, load per-player visibility/object data.
// modeled initial uncompressed count/blob skip with malloc failure closing file and returning.
// modeled player-id hash read, virtual pre-load calls, map array init to -1, player remap from player_info+0x270, and remake_visible_map pass.
// modeled per-player visibility load dispatch with fallback to player 0 and 1.04f argument.
// modeled nested object-count/object-record reads and guarded object load with temporary loading flag fields.
// modeled final close and post-remap player hook pass only roughly; UI/helper calls at tail remain speculative.
// current source compiles but emits 688 bytes vs original 721; no positional diff; not accepted_drift-safe.

extern "C" void __cdecl rge_read(int, void*, int);
extern "C" void __cdecl rge_read_uncompressed(int, void*, int);
extern "C" void* __cdecl malloc(unsigned int);
extern "C" void __cdecl free(void*);
extern "C" void __cdecl rge_close(int);
extern int world_update_counter;

class Player { public:
#define PPAD(n) virtual void p##n();
    PPAD(0) PPAD(1) PPAD(2) PPAD(3) PPAD(4) PPAD(5) PPAD(6) PPAD(7)
    PPAD(8) PPAD(9) PPAD(10) PPAD(11) PPAD(12) PPAD(13) PPAD(14) PPAD(15)
    PPAD(16) PPAD(17) PPAD(18) PPAD(19) PPAD(20) PPAD(21) PPAD(22) PPAD(23)
#undef PPAD
    virtual void loadVisibility(int,int*,float);
    virtual void loadObject(float,float,float,float,short,unsigned char,float);
};
class UI { public: int a(int,int); int b(int,int,int); int c(int,int,int); int d(int,int,int); };
class RGE_Game_World { public:
    char gap0[0x3c]; short player_count; Player** players; char gap44[0x5c-0x44]; UI* ui; char gap60[8]; int player_hash; int temp; unsigned char loading;
#define WPAD(n) virtual void w##n();
    WPAD(0) WPAD(1) WPAD(2) WPAD(3) WPAD(4) WPAD(5) WPAD(6) WPAD(7) WPAD(8) WPAD(9) WPAD(10) WPAD(11) WPAD(12) WPAD(13) WPAD(14) WPAD(15) WPAD(16) WPAD(17) WPAD(18) WPAD(19) WPAD(20) WPAD(21) WPAD(22) WPAD(23) WPAD(24) WPAD(25) WPAD(26) WPAD(27)
#undef WPAD
    virtual void load_players4(int, void*);
    virtual void load_something(int);
    virtual void load_pre(int, RGE_Game_World*);
    void load_scenario4(int, void*);
};

void RGE_Game_World::load_scenario4(int fd, void* info)
{
    int count, nvis, objcnt, i, j;
    int map[10];
    int id, owner, x, y, z, angle;
    short master;
    unsigned char state;
    world_update_counter = 0;
    rge_read_uncompressed(fd, &count, 4);
    if (count > 0) {
        void* p = malloc(count);
        if (!p) { rge_close(fd); return; }
        rge_read_uncompressed(fd, p, count);
        free(p);
    }
    rge_read(fd, &this->player_hash, 4);
    this->load_pre(fd, this);
    this->load_something(fd);
    if (this->player_count > 0) {
        do { for (i=0;i<9;i++) map[i] = -1; } while (this->player_count > 10);
    }
    for (i=0; i<this->player_count; ++i) map[((int*)info)[0x9c+i]] = i;
    for (i=0; i<this->player_count; ++i) this->players[i]->p0();
    rge_read(fd, &nvis, 4);
    for (i=1; i<nvis; ++i) {
        Player* p = (i < this->player_count && map[i] > -1 && this->players[map[i]]) ? this->players[map[i]] : this->players[0];
        p->loadVisibility(fd, map, 1.04f);
    }
    for (i=0; i<nvis; ++i) {
        rge_read(fd, &objcnt, 4);
        for (j=0; j<objcnt; ++j) {
            rge_read(fd, &id, 4); rge_read(fd, &x, 4); rge_read(fd, &y, 4); rge_read(fd, &z, 4);
            rge_read(fd, &master, 2); rge_read(fd, &state, 1); rge_read(fd, &angle, 4);
            if (map[i] >= 0 && this->players[map[i]]) {
                this->loading = 1; this->temp = z;
                this->players[map[i]]->loadObject(*(float*)&id, *(float*)&x, *(float*)&y, *(float*)&z, master, state, *(float*)&angle);
                this->loading = 0;
            }
        }
    }
    this->player_hash = nvis;
    rge_close(fd);
    for (i=1; i<this->player_count && i<nvis; ++i) {
        if (this->players[i] && map[i] > -1) {
            this->players[map[i]]->p1();
        }
    }
}
