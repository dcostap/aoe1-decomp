// VA: 00502920 TribeTacticalAIModule::checkForCoopTributeGift
// Attempt log:
// initial rough reconstruction from packet: wonder gate, interval gate, choose coop player, scan resources, tribute best surplus.
// modeled initial interval != -1 gate, wonder/object find_by_master_id call, and elapsed-time /1000 check.
// modeled coop owner selection from computer players, including single-computer fast path and debug_rand random pick.
// modeled four-resource loop, threshold checks, allied/can-tribute-ish virtual tests, best-lowest resource selection, and final tribute-ish call.
// current rough source compiles but emits 656 bytes vs original 714; no positional diff and several type/call surfaces are still speculative.
// left in scratch: broad/short reconstruction, not accepted_drift-safe.

extern "C" int __cdecl debug_rand(char*, int);
class Player { public:
    char gap0[0x3c]; short count; Player** players; char id; char gap4b[5]; float* resources;
    int computerPlayer(); virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual int allied(int); virtual void v5(); virtual void v6(); virtual int canTribute(int); virtual int resourceValue(int);
};
class ObjList { public: void* find_by_master_id(int,float,float,int,int,int); };
class World { public: char gap0[0xf0]; Player* player; char gapf4[0x1256c-0xf4]; ObjList* objects; };
class ResAI { public: int resource(int); };
class TribeTacticalAIModule { public:
    char gap0[0xf0]; World* world; char gapf4[0x47c-0xf4]; int interval; int thresholds[4]; char gap49c[0xf9c-0x49c]; int last_time;
    void checkForCoopTributeGift();
};

void TribeTacticalAIModule::checkForCoopTributeGift()
{
    if (this->interval == -1) return;
    if (!this->world->objects->find_by_master_id(0x54, -1.0f, -1.0f, 0, 2, 0)) return;
    Player* me = this->world->player;
    int now = *(int*)((char*)me + 0x3c + 4);
    if ((now - this->last_time) / 1000 < this->interval) return;
    this->last_time = now;
    Player* game = *(Player**)((char*)me + 0x3c);
    if (*(unsigned char*)((char*)game + 0x11d) == 0xff) {
        int cnt = 0;
        int i;
        for (i=1; i<game->count; ++i) if (game->players[i]->computerPlayer() == 1) ++cnt;
        if (cnt == 1) *(unsigned char*)((char*)game+0x11d) = me->id;
        else {
            int pick = debug_rand((char*)0x005880c0, 0x3275) % cnt + 1;
            for (i=1; i<game->count; ++i) {
                Player* p = game->players[i];
                if (p->computerPlayer() == 1 && --pick == 0) { *(unsigned char*)((char*)game+0x11d) = p->id; break; }
            }
        }
    }
    for (int res=0; res<4; ++res) {
        if (((ResAI*)((char*)this->world + 0x10d7c))->resource(res) <= this->thresholds[res]) continue;
        int best = -1;
        float bestAmt = 0.0f;
        for (int j=1; j<game->count; ++j) {
            Player* p = game->players[j];
            if (p->id == me->id) continue;
            if (!p->computerPlayer()) continue;
            if (!me->allied(j)) continue;
            if (!p->allied(me->id)) continue;
            float amount = p->resources[res];
            int need = p->resourceValue(res + 0xbe);
            if ((float)need >= amount) {
                if (best == -1 || amount < bestAmt) { best = p->id; bestAmt = amount; }
            }
        }
        if (best != -1) {
            int avail = ((ResAI*)((char*)this->world + 0x10d7c))->resource(res) - this->thresholds[res];
            this->world->objects->find_by_master_id(best, *(float*)((char*)this->world->objects + 0x50 + 0xb8), *(float*)&avail, res, 0, 0);
        }
    }
}
