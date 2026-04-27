// VA: 0051CFD0
// TRIBE_Panel_Pop::startup()
// Source: tpnl_pop.cpp lines 135-142

// attempt 1: direct full-path access through casts, no local temp -> codegen diff (compare order + edi reg)
// attempt 2: local RGE_Player* p temp + 'this->max_pop > limit' compare -> EXACT MATCH (107/107, 0.0000%)
// default flags

class RGE_Base_Game;
extern RGE_Base_Game* rge_base_game;

class RGE_Base_Game {
public:
    char gap_000[0x3F4];
    void* world;          // +0x3F4

    void* get_player();
};

class RGE_Player {
public:
    char gap_000[0x50];
    float* attributes;    // +0x50
};

class TRIBE_Panel_Pop {
public:
    char gap_000[0x108];
    void* world;          // +0x108
    void* player;         // +0x10C
    int pop;              // +0x110
    int max_pop;          // +0x114

    void startup();
};

void TRIBE_Panel_Pop::startup() {
    this->world = rge_base_game->world;
    RGE_Player* p = (RGE_Player*)rge_base_game->get_player();
    this->player = p;

    this->pop = (int)(p->attributes[0x2C / 4]);
    this->max_pop = this->pop + (int)(p->attributes[0x10 / 4]);
    int limit = (int)(p->attributes[0x80 / 4]);
    if (this->max_pop > limit) {
        this->max_pop = limit;
    }
}
