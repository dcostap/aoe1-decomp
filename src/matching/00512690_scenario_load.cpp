// 00512690 TRIBE_Player::scenario_load(int, long*, float)
// Source: tplayer.cpp lines 665-706
// FLAGS: config/flags/00512690_scenario_load.rsp
// Attempt log:
// - Initial natural implementation from packet/decompiler with local layouts.
// - Tried default flags first: compiled to only 432 bytes with no EH frame, while original has VC5 EH registration; kept /GX hypothesis.
// - Corrected virtual-base local layout by accounting for the hidden vptr: first gap is 0x1E so objectCount lands at +0x22, while later target offsets remain source offsets.
// - Normal `new TRIBE_Player_Tech(...)` was required for VC5 /GX EH state/unwind scaffolding; placement-new source was too small/no EH.
// - Exact match: duplicate the final do_tech_effect call in the if/else source instead of computing a `techID` temp. VC5 tail-merges the duplicate calls into the original shared call setup; the temp form generated a shorter, different branch family.

void* __cdecl operator new(unsigned int size);
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
void __cdecl operator delete(void* ptr);
extern "C" void __cdecl rge_read(int file, void* dst, int size);

class TRIBE_Player;
class TRIBE_Tech;

class RGE_Player {
public:
    char gap_000[0x1E];
    short objectCount;
    void** objects;
    char gap_028[0x3C - 0x28];
    void* world;
    char gap_040[0x50 - 0x40];
    char* playerData;
    char gap_054[0x10C - 0x54];
    int startTech;
    char gap_110[0x220 - 0x110];

    virtual void scenario_load(int file, long* pos, float version);
};

class RGE_Master_Static_Object {
public:
    void make_available(char flag);
};

class TRIBE_Player_Tech {
public:
    char gap_000[0x10];
    TRIBE_Player_Tech(int file, TRIBE_Tech* tech, TRIBE_Player* player, int flag);
    TRIBE_Player_Tech(TRIBE_Tech* tech, TRIBE_Player* player, int flag);
    ~TRIBE_Player_Tech();
    unsigned char check_for_new_tech();
};

class TRIBE_Effects {
public:
    void do_tech_effect(short tech, TRIBE_Player* player);
};

class T_Scenario {
public:
    int GetScenarioOption(int option);
    void set_player_tech(TRIBE_Player* player);
};

class TRIBE_World {
public:
    char gap_000[0x4C];
    TRIBE_Effects* effects;
    char gap_050[0x5C - 0x50];
    T_Scenario* scenario;
    char gap_060[0x104 - 0x60];
    TRIBE_Tech* tech;
};

class TRIBE_Game {
public:
    char gap_000[0x1B4];
    int game_mode;
    int fullTechTree();
};

extern TRIBE_Game* rge_base_game;

class TRIBE_Player : public RGE_Player {
public:
    TRIBE_Player_Tech* techTree;

    virtual void scenario_load(int file, long* pos, float version);
};

void TRIBE_Player::scenario_load(int file, long* pos, float version)
{
    TRIBE_Player_Tech* tech;
    int i;
    RGE_Master_Static_Object* obj;

    RGE_Player::scenario_load(file, pos, version);

    tech = this->techTree;
    if (tech != 0) {
        tech->~TRIBE_Player_Tech();
        operator delete(tech);
    }

    i = 0;
    if (this->objectCount > 0) {
        do {
            obj = (RGE_Master_Static_Object*)this->objects[i];
            if (obj != 0) {
                obj->make_available(0);
            }
            i++;
        } while (i < this->objectCount);
    }

    if (version > 1.06) {
        rge_read(file, this->playerData, 4);
        rge_read(file, this->playerData + 4, 4);
        rge_read(file, this->playerData + 12, 4);
        rge_read(file, this->playerData + 8, 4);
    }

    *(int*)(this->playerData + 0x78) = 0;
    *(int*)(this->playerData + 0x54) = 0;

    if (version <= 1.03) {
        this->techTree = new TRIBE_Player_Tech(file, ((TRIBE_World*)this->world)->tech, this, 1);
        return;
    }

    tech = new TRIBE_Player_Tech(((TRIBE_World*)this->world)->tech, this, 0);
    this->techTree = tech;

    if (this->startTech >= 0 && !rge_base_game->fullTechTree() && !((TRIBE_World*)this->world)->scenario->GetScenarioOption(2)) {
        ((TRIBE_World*)this->world)->effects->do_tech_effect((short)this->startTech, this);
    }
    else {
        ((TRIBE_World*)this->world)->effects->do_tech_effect(0xD2, this);
    }

    if (rge_base_game->game_mode != 7) {
        ((TRIBE_World*)this->world)->scenario->set_player_tech(this);
    }
    this->techTree->check_for_new_tech();
}
