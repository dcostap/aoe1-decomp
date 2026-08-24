// 005123B0 TRIBE_Player::update
// Attempt log:
// 1: natural implementation from decompiler/asm with local class surfaces: broad mismatch; mistaken C++ vptr padding put fields 4 bytes early and world tick as byte not float, causing push-ecx local and fild at entry.
// 2: fix TRIBE_Player field padding for implicit vptr and model world delta_time as float at 0x84/currentUpdateComputerPlayer at 0xfc: prologue and first 42 bytes now match, but Stats/List offsets were low.
// 3: fix Stats offsets (add 0x28, visible 0x2c, explored 0x58, diff 0xb0) and List head at +4: edit diff improved to 25.1%, first 42 bytes exact; early loop still schedules fsub before update_history_count load.
// 4: move update_history_count increment source before update_time store to chase original loop scheduling: edit diff improved to 23.5%, but update_count compare scheduling still differs.
// 5: split Stats offset 0 cur from progress at 0x24; loop progress uses +0x24/+0x28 while final drain uses +0: edit diff improved to 8.5%, but history object was still modeled embedded (lea) instead of pointer load.
// 6: add history pointer field at 0x83c and call through it: call surface is correct but size/branch offsets changed slightly; edit diff 54 (8.7%).
// 7: closest build has first 42 bytes exact and same configured size 621; remaining drift starts as branch displacement due small loop scheduling differences.
// 8: main loop known drift: original uses EDX for update_history_count increment and compares after storing update_time; rebuilt uses EAX/C source-scheduled compare/store ordering. Same memory effects.
// 9: history negative path differs as push ebp in original vs zeroing/pushing eax in one variant; both pass zero. Kept pointer history surface because original loads [esi+83c].
// 10: potential accepted_drift candidate only if reviewer agrees all remaining hunks are register/scheduling/branch-distance equivalent; otherwise leave in scratch.
// 11: restored the tplayer.cpp donor ABI: the list-failure call is inherited set_game_status(unsigned char) at vtable slot +4, not a derived +0x0c reset_something slot.
// 12: replaced compiler-private literal-pool references with the donor TU's named shared constants at 00576824/28/2c/30/38/40; the original uses these relocations throughout the loop and final drain.
// 13: split the history add into direct negative/converted branches; this mirrors the PDB line split and allows the original push ebp versus __ftol result paths without a merged val local.
// 14: replaced the local n/count copy with a direct member increment and post-increment threshold test to try to recover the oracle's count store before compare and delayed FPU store.
// 15: cache the final MouseSystem global in a typed local so the original load/test leaves the receiver in ECX across stack cleanup instead of requiring a late mov ecx,eax.
// 16: removed the unused zero local as a plausibility audit; VC5's EBP zero register is compiler-derived from the natural null/zero stores.
// 17: restored the metadata-proven virtual update declarations on RGE_Player and TRIBE_Player; qualified base dispatch remains direct while the source surface reflects the original vtable ownership.

#define rge_base_game (*(RGE_Base_Game**)0x0062C574)
#define debug_random_on (*(int*)0x0062C4D4)
#define global_save_debug_random_on1 (*(int*)0x0086BC90)
#define comm (*(TCommunications_Handler**)0x0062C4C0)
#define MouseSystem (*(TMousePointer**)0x0062E660)

extern "C" int __cdecl debug_rand(char* file, int line);
extern "C" void __cdecl debug_srand(char* file, int line, int seed);
extern float DAT_00576824;
extern float DAT_00576828;
extern float DAT_0057682c;
extern double DAT_00576830;
extern double DAT_00576838;
extern float DAT_00576840;

#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class RGE_Base_Game { public: int fullVisibility(); };
class RGE_Visible_Map { public: float percentExplored(); };
class TCommunications_Handler { public: int ComputerPlayerGameStart(); };
class TMousePointer { public: void Poll(); };
class RGE_Game_World { public: char pad0[0x84]; float delta_time; char pad88[0xfc-0x88]; int currentUpdateComputerPlayer; void selectNextComputerPlayer(int); };
class TRIBE_History_Info { public: void add_history_entry(int, int); };
class AI { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void update(int); };
struct NodeObj2 { char pad[0x14]; short id; };
struct NodeObj { char pad0[8]; NodeObj2* type; char pad1[0x48-0xc]; char state; };
struct Node { NodeObj* obj; Node* next; };
struct List { int count; Node* head; };
struct Stats { float cur; char pad04[0x24-4]; float progress; float add; float visible; char pad30[0x4c-0x30]; float a4c; float a50; char pad54[0x58-0x54]; float explored; char pad5c[0x84-0x5c]; float mult; char pad88[0xb0-0x88]; float diff; float b4; };
class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char);
    virtual void update();
};
class TRIBE_Player : public RGE_Player {
public:
    char pad04[0x28-4]; List* list; char pad2c[0x38-0x2c]; RGE_Visible_Map* visibleMap; RGE_Game_World* world; char pad40[0x4a-0x40]; short count; char pad4c[0x50-0x4c]; Stats* stats;
    char pad54[0x228-0x54]; int update_count; int update_history_count; int updateCountNeedHelp; float update_time; AI* playerAI; char pad23c[0x83c-0x23c]; TRIBE_History_Info* history;
    virtual void update();
};
#endif

void TRIBE_Player::update()
{
    this->update_time = this->world->delta_time + this->update_time;
    while (this->update_time > DAT_00576824) {
        this->update_time = this->update_time - DAT_00576824;
        ++this->update_history_count;
        if (this->update_history_count >= 15) {
            this->update_history_count -= 15;
            if (this->stats->visible < DAT_00576828) {
                this->history->add_history_entry(0, 0);
            } else {
                this->history->add_history_entry(0, (int)this->stats->visible);
            }
        }
        if (rge_base_game->fullVisibility()) {
            this->stats->explored = 100.0f;
        } else {
            this->stats->explored = this->visibleMap->percentExplored() * DAT_0057682c;
        }
        this->stats->diff = this->stats->a50 - (this->stats->a4c - this->stats->visible);
        if (this->stats->diff < DAT_00576830) this->stats->diff = 0.0f;
        this->stats->progress += this->stats->add;
        if (this->stats->progress > DAT_00576838) this->stats->progress = 100.0f;
        if (this->update_count > 0) --this->update_count;
        if (this->updateCountNeedHelp > 0) --this->updateCountNeedHelp;
        if (this->count > 0) {
            Node* node = this->list->head;
            if (node) {
                while (node) {
                    NodeObj* obj = node->obj;
                    int id = obj->type->id;
                    if (id != 0xb && id != 0x1e && id != 0x1b && id != 1 && id != 0x15 && id != 0x14 && id != 2 && id != 0x25 && obj->state == 2) break;
                    node = node->next;
                }
                if (node) goto ok;
            }
            this->set_game_status(2);
            this->stats->b4 = 0.0f;
        }
ok:;
    }
    RGE_Player::update();
    this->stats->cur = this->stats->cur - this->world->delta_time * this->stats->mult * this->stats->visible * DAT_00576840;
    if (this->stats->cur < DAT_00576830) this->stats->cur = 0.0f;
    int seed = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0x25f);
    int old = debug_random_on;
    global_save_debug_random_on1 = old;
    debug_random_on = 0;
    if (this->playerAI && comm->ComputerPlayerGameStart() == 1) {
        if (this->world->currentUpdateComputerPlayer == -1) this->world->selectNextComputerPlayer(3);
        this->playerAI->update(0);
    }
    debug_random_on = old;
    debug_srand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0x277, seed);
    TMousePointer* mouse = MouseSystem;
    if (mouse) mouse->Poll();
}
