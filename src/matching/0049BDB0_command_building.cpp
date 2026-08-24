// VA: 0049BDB0 command_building (225B)
// scr_game.cpp
// PDB line span 4903-4925.
//
// Canonical reconstruction (modeled on exact sibling command_research 0049CAF0):
//   paused = get_paused(); if (!paused) {
//     if (get_player()->check_obj_cost(obj_id, &attr, 1.0f, paused)) {
//       rge_base_game->master_obj_id = obj_id;
//       if (get_player()->master_objects[obj_id]->building_connect_flag)
//           set_game_mode(0x15, 0);   // vt+0x10 (donors also named it build_mode/set_font)
//       else set_game_mode(7, 0);
//     } else {
//       get_string2(0x67, 1, attr, msg, 0x200);   // vt+0x28
//       message_panel->show_message(1, msg, 0x56, 0, 0, 0, 0);
//     }
//   }
// Real get_player() is 0-arg (pops 0); the 4 pushed cost args are popped by the
// real check_obj_cost (ret 10h). Chaining get_player()->check_obj_cost(args) makes
// VC5 push the args before the get_player call (matching the binary), while a
// separate `player` local makes it push them after (mismatch).
//
// Attempt log (sa-d356673f, budget 10, all under /O2 /Oy):
// - baseline: args attached to get_player overload + 0-arg check_obj_cost: call
//   site matches exactly, but VC5 hoists the rge_base_game load (mov ecx,[g],
//   6B) above the cost test; original keeps it after the je in EAX (A1, 5B) and
//   reloads it on the error path. -5 size, 151 diff, 84.9% shape.
// - flags: /GX off -> byte-identical (stale /GX neutral; sibling uses default).
// - register self, if/else outer, paused-as-arg4 variants: byte-identical.
// - args on check_obj_cost + player local: load placement right but args pushed
//   AFTER get_player (order mismatch); 94.3% shape but 182 diff.
// - chained get_player()->check_obj_cost(...) + inline master_objects access +
//   paused arg4: best. Call site, branch vtable registers (edx/eax), get_string2
//   setup and show_message message_panel load all match; resync 83.6% (188/225
//   equal bytes), shape 90.4%, exact-block 40%. Only remaining drift is the
//   hoisted rge_base_game load (root cause of the -5 size, error-path reload
//   omission, and master_objects/index register coloring: edx/eax/cl vs
//   ecx/esi/al with load C before vs after the index).
// - variant lab (8 combos of check-affiliation x store spelling): confirms the
//   two basins; chained family is the closer one (edit-diff 46 vs 69).
// Left in scratch: chained+inline+paused form (best); the single remaining
// blocker is VC5's post-call load hoist, which no natural source spelling
// tried (store casts, if/else, local vs chained, paused vs literal) avoided.
//
// Follow-up session (sa-66340ab1-command_building, budget 10):
// - baseline: prior clean source remains 149 differing bytes, 220 rebuilt bytes,
//   100% ordered calls, and the same post-check global-load hoist.
// - removed the success-arm else; the cost block gained exact bytes but lost
//   the original success-tail topology and grew the size gap to -10, so restored.
// - materialized the unsigned cost result; VC5 emitted identical code, so no
//   source change retained.
// - restored the proven TScreenPanel inheritance boundary with message_panel at
//   +0x544; emitted code was unchanged, so the minimal local screen surface is
//   sufficient for this target.
// - cleared the stale per-function /GX response file; default /O2 /Oy emitted
//   identical bytes. Reversed cost-guard arms were worse (call order -2/+2),
//   so restored the clean positive guard.
// Left unresolved: natural typed source has the correct calls/frame/CFG and
//   188/225 resynchronized bytes, but VC5 hoists one rge_base_game load before
//   `test al`; forcing the six-load schedule would require fake volatility or
//   opaque compiler steering, which is not retained.
// Follow-up worker: direct absolute-global macro versus the validated extern
//   global was codegen-close but one byte worse; restored the extern canonical
//   source.  The remaining global-load hoist is therefore a documented
//   compiler-basin blocker, not an unresolved call/layout ABI fact.
// Main-agent audit restored canonical polymorphic game/player/master/screen
// ownership and removed the residual self register alias.
//
// Fresh bounded pass (orch-scrgame-01):
// - Tested the generated RGE_Player base ownership/get_player return surface
//   and the long/long get_string2 ABI; both emitted the prior 149-byte basin.
// - A branch-local RGE_Base_Game* used only for the success-arm master-id
//   store blocked the post-cost global-load CSE and reached a 225-byte,
//   29-byte-diff basin without changing calls, frame, or CFG.
// - Naming the fetched master object before testing building_connect_flag then
//   recovered the oracle's ESI object-pointer/vtable-register coloring exactly.
// - Removed the stale per-function /GX override; the exact source remains exact
//   under the pinned default /O2 /Oy flags.

#if !defined(SCR_GAME_TU_CONTEXT)
struct RGE_Base_Game;
struct TRIBE_Player;
struct TMessagePanel;
struct RGE_Master_Static_Object;

extern RGE_Base_Game* rge_base_game;

struct RGE_Base_Game {
    virtual ~RGE_Base_Game();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void set_game_mode(int mode, int value);            // vt[4] (0x10)
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual char* get_string2(int id, int a, int attr, char* buf, int size); // vt[10] (0x28)
    char gap_004[0x3F8];
    short master_obj_id;                                        // +0x3FC
    int get_paused();
    TRIBE_Player* get_player();
    TRIBE_Player* get_player(int id, short* attr, float factor, int x);
};

struct TRIBE_Player {
    virtual ~TRIBE_Player();
    char gap_004[0x20];
    RGE_Master_Static_Object** master_objects;   // +0x24
    unsigned char check_obj_cost(short obj_id, short* out, float factor, int skip_farm);
};

struct RGE_Master_Static_Object {
    virtual ~RGE_Master_Static_Object();
    char gap_004[0x168];
    unsigned char building_connect_flag;                        // +0x16C
};

struct TMessagePanel {
    void show_message(int a, char* msg, int code, int z1, int z2, int z3, int z4);
};

class TScreenPanel {
public:
    virtual ~TScreenPanel();
    char gap_004[0x540];
};

class TRIBE_Screen_Game : public TScreenPanel {
public:
    TMessagePanel* message_panel;                               // +0x544

    void command_building(int obj_id);
};
#endif

void TRIBE_Screen_Game::command_building(int obj_id) {
    short attr;
    char msg[512];

    int paused = rge_base_game->get_paused();
    if (paused == 0) {
        if (rge_base_game->get_player()->check_obj_cost(obj_id, &attr, 1.0f, paused)) {
            RGE_Base_Game* game = rge_base_game;
            game->master_obj_id = obj_id;
            RGE_Master_Static_Object* object =
                rge_base_game->get_player()->master_objects[obj_id];
            if (object->building_connect_flag) {
                rge_base_game->set_game_mode(0x15, 0);
                return;
            }
            rge_base_game->set_game_mode(7, 0);
            return;
        } else {
            rge_base_game->get_string2(0x67, 1, (int)attr, msg, 0x200);
            this->message_panel->show_message(1, msg, 0x56, 0, 0, 0, 0);
        }
    }
}
