// VA: 0049CEC0 command_train (240B)
// scr_game.cpp
// Baseline reconstruction: the production-queue path uses the screen's world
// command and game object; the fallback checks the selected player's object
// cost and reports the same localized message as command_research.
// Attempt log (sa-e0728c32-command-train, budget 10):
// - Baseline reached the correct 8-call sequence, 0x204 frame, and 71-instruction shape;
//   the remaining drift is register coloring plus a one-byte fallback layout shift.
// - Self aliases, a paused local, an object-id copy, a register-qualified parameter,
//   the proven screen base/vptr, and queue if/else spelling were duplicate codegen.
// - A focused variant lab confirmed the direct queue expression and positive cost guard
//   as the closest natural basin; no size/frame/call-set-gated variant matched.
// - Left in scratch: rebuilt 241 vs original 240 bytes, 119 positional differing bytes;
//   calls and CFG are aligned, but VC5 keeps this in ESI/parameter in EDI instead of
//   original this in EDI/parameter in ESI. Next lead is likely the full same-TU
//   TRIBE_Screen_Game declaration/context or a narrower declaration-order donor.
// Follow-up session (sa-66340ab1-command_train):
// - baseline recheck reproduced the pinned 119-byte mismatch with exact frame,
//   71-instruction shape, calls, and CFG.
// - one consistent register self alias for queue and message-panel ownership
//   emitted identical code; restored the clean source.
// Left unresolved: the remaining difference is entry callee-save coloring
// (original EDI=this, ESI=player_id; VC5 ESI=this, EDI=player_id) plus the
// resulting one-byte boundary shift. Prior same-TU base/vptr/layout and
// declaration/liveness probes did not move this basin; no opaque register
// forcing is retained.
// Main-agent audit restored canonical polymorphic game/world/player/screen
// ownership and retained the natural queue/cost fallback.
// Current worker probes:
// - changed command_building_make_obj to the int spelling from its exact donor
//   and removed the narrowing cast; emitted bytes were unchanged, so restored.
// - reversed the local declaration order of msg and attr; emitted bytes were
//   unchanged, so restored.
// Remaining lead is the inherited entry callee-save coloring (VC5 keeps this
// in ESI and player_id in EDI; the oracle keeps this in EDI and player_id in
// ESI). No natural ABI/layout/source-context axis remains justified here.

struct RGE_Static_Object;
struct TRIBE_Player;
struct TMessagePanel;

extern unsigned char production_queues_is_use;
extern struct RGE_Base_Game* rge_base_game;

struct TRIBE_Command {
    void command_queue(RGE_Static_Object* building, short train_id, short count);
};

struct RGE_Game_World {
    virtual ~RGE_Game_World();
    char gap_04[0x54];
    TRIBE_Command* command;
};

struct RGE_Base_Game {
    virtual ~RGE_Base_Game();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void language(int id, int a, int attr, char* buf, int size);

    char gap_004[0x3F8];
    short master_obj_id;
    int get_paused();
    TRIBE_Player* get_player();
};

struct TRIBE_Player {
    virtual ~TRIBE_Player();
    unsigned char check_obj_cost(short obj_id, short* attr, float factor, int skip_farm);
    unsigned char command_building_make_obj(short obj_id);
};

struct TMessagePanel {
    void show_message(int type, char* msg, int code, int z1, int z2, int z3, int z4);
};

class TScreenPanel {
public:
    virtual ~TScreenPanel();
    char gap_004[0x540];
};

class TRIBE_Screen_Game : public TScreenPanel {
public:
    TMessagePanel* message_panel;
    char gap_548[0x6C];
    RGE_Game_World* world;
    char gap_5B8[0x10];
    RGE_Static_Object* game_obj;

    void command_train(int player_id, short train_id);
};

void TRIBE_Screen_Game::command_train(int player_id, short train_id) {
    short attr;
    char msg[512];

    if (rge_base_game->get_paused() == 0) {
        if (production_queues_is_use) {
            this->world->command->command_queue(this->game_obj, player_id, train_id);
            return;
        }
        if (rge_base_game->get_player()->check_obj_cost((short)player_id, &attr, 1.0f, 0)) {
            rge_base_game->master_obj_id = (short)player_id;
            rge_base_game->get_player()->command_building_make_obj((short)player_id);
            return;
        }
        rge_base_game->language(0x67, 1, (int)attr, msg, 0x200);
        this->message_panel->show_message(1, msg, 0x56, 0, 0, 0, 0);
    }
}
