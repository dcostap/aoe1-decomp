// Initial heuristic C++ lift from Ghidra for TRIBE_World::new_game (0052EF30).
// This is intentionally broad and local-stub-heavy: first goal is to get the full
// behavioral surface compiling, then iterate call/layout/codegen toward parity.
// FLAGS: config/flags/0052EF30_new_game.rsp (/GX)
// Natural new/delete for RGE_RMM_Object_Generator plus /GX recovers the original
// EH prologue shape and 0x1308 frame; broad code-shape drift remains.
// Inlining description helpers and direct player/resource access brought the body
// above 5028 bytes so check_function now reports a real diff instead of size-stop.
// Remaining early mismatch: VC5 stores base new_game result from AL to [esp+17]
// and frees EBX for a hoisted strlen mask; original keeps AL in BL, stores BL,
// and later tests BL. Tried register/result-holder forms; they were unchanged.
// Attempt log:
// - Replaced the description-path goto with one negated guard; VC5 emitted the
//   same bytes, so the natural guard remains the source form.
// - Collapsed duplicate base-new-game result locals; VC5 emitted the same bytes.
// - Cached the post-save victory getter; this changed the call schedule and was
//   rolled back.
// - Modeled the generator's binary-proven 0x1920 object size with derived padding;
//   this fixed the allocation ABI and improved the structural call surface.
// - Restored explicit branches for the Yes/No description selectors; this fixed
//   the condition count and one exact description block.
// - Retained the binary-proven standalone difficulty getter despite local drift;
//   a register-qualified return local emitted duplicate code.
// - Buffered difficulty formatting matched the virtual call surface but exceeded
//   the original boundary by 164 bytes, so it was rolled back.

#include <stdio.h>
#include <string.h>

typedef unsigned char uchar;
#define S_EMPTY ((const char*)0x592A40)
#define S_NEWLINE_JOIN ((const char*)0x58C624)

extern void* __cdecl operator_new(unsigned int size);
extern void __cdecl operator_delete(void* ptr);
inline void* __cdecl operator new(unsigned int, void* place) { return place; }

class RGE_Player_Info;
class RGE_Map;
class RGE_Game_World;
class RGE_Random_Map_Module;
class RGE_RMM_Object_Generator;
class RGE_Victory_Conditions;
class RGE_Effects;
class T_Scenario;
class TRIBE_World;

class RGE_Base_Game {
public:
    virtual void vpad0();
    virtual void vpad1();
    virtual void vpad2();
    virtual void vpad3();
    virtual void vpad4();
    virtual void vpad5();
    virtual void vpad6();
    virtual void vpad7();
    virtual char* get_string(int id);
    virtual char* get_string(int id, char* dst, int len);

    int scenarioGame();
    int randomGame();
    int campaignGame();
    int multiplayerGame();
    int allowCheatCodes();
    int fullVisibility();
    int difficulty();
    uchar pathFinding();
    uchar mpPathFinding();
    uchar check_prog_argument(const char* arg);
    void reset_countdown_timer(int player);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    int mapSize();
    int mapType();
    int victoryType();
    int victoryAmount();
    int randomizePositions();
    int fullTechTree();
    int resourceLevel();
    int startingAge();
    uchar deathMatch();
    uchar popLimit();
    int allowTrading();
    int longCombat();
};

extern TRIBE_Game* rge_base_game;
extern int __cdecl debug_rand(const char* file, int line);

class RGE_Victory_Conditions {
public:
    void add_victory_points(int player, int amount, int flag);
    void add_points_attribute_amount(int a, int b, int attrib, int value, int flag);
    void add_points_attribute_first(int a, int b, int attrib, int value, int flag);
    void add_points_highest_attribute(int a, int b, int attrib, int value, int flag);
    void add_points_high_attribute_once(int a, int b, int attrib, int value, int flag);
    void add_points_high_attribute_amount(int a, int b, int attrib, int value, int flag);
};

struct RGE_Object_Type_Info {
    char pad_00[0x10];
    short id;
};

struct RGE_Object_Info_Holder {
    char pad_00[0x08];
    RGE_Object_Type_Info* type;
};

struct RGE_Object_List_Node {
    RGE_Object_Info_Holder* object;
    RGE_Object_List_Node* next;
};

struct RGE_Object_List_Head {
    char pad_00[0x04];
    RGE_Object_List_Node* head;
};

class TRIBE_Player {
public:
    char pad_00[0x28];
    RGE_Object_List_Head* objects;
    char pad_2C[0x08];
    RGE_Victory_Conditions* victory;
    char pad_38[0x18];
    float* resources;
    char pad_54[0xB8];
    short civilization;

    void rev_tech(short tech);
    void new_attribute_num(short attrib, float value);
    void add_population_entry();
};

class RGE_Effects {
public:
    virtual void v0();
    virtual void v1();
    virtual void do_effect(short effect, TRIBE_Player* player);
};

class RGE_Game_World {
public:
    void* vtable_ptr;
    char gap_04[0x24];
    RGE_Map* map;
    char gap_2C[0x10];
    short player_num;
    char gap_3E[0x02];
    TRIBE_Player** players;
    char gap_44[0x08];
    RGE_Effects* effects;
    char gap_50[0x0C];
    T_Scenario* scenario;
    char gap_60[0xA4];

    uchar new_game(RGE_Player_Info* param_1, int param_2);
};

class TRIBE_Tech;
class TRIBE_World : public RGE_Game_World {
public:
    TRIBE_Tech* tech;
    int victory_type;
    int artifact_count;
    int ruin_count;
    uchar countdown_victory;
    uchar pad_115[3];
    float countdown_clock;
    uchar score_displayed;
    uchar controllingComputerPlayer;
    uchar pad_11E[2];
    int sent_zone_score;

    uchar new_game(RGE_Player_Info* param_1, int param_2);
};

class T_Scenario {
public:
    void Set_scenario_name(const char* name);
    void add_description(char* text);
    void Set_victory_all_flag(int value);
    void Set_Multi_Conquest(int value);
    void Set_Multi_Ruins(int value);
    void Set_Multi_Artifacts(int value);
    void Set_Multi_Discoveries(int value);
    void Set_Multi_Exploration(int value);
    void Set_Multi_Gold(int value);
    void Save_victory_conditions_into_players(int value);
    int GetMPVictory();
    int GetVictoryTime();
    int GetVictoryScore();
    int Get_Multi_Ruins();
    int Get_Multi_Artifacts();
    int Get_Multi_Discoveries();
    int GetScenarioOption(int option);
};

class RGE_Random_Map_Module {
public:
    ~RGE_Random_Map_Module();
};

class RGE_RMM_Object_Generator : public RGE_Random_Map_Module {
public:
    char gap_04[0x191c];
    virtual void generate();
    RGE_RMM_Object_Generator(RGE_Map* map, void* module, RGE_Game_World* world, void* info, int flag);
    void add_quick_obj(short object_id, int count, int spacing);
};

static __inline int count_objects(TRIBE_World* world, short id) {
    int count = 0;
    int i;
    for (i = 0; i < world->player_num; ++i) {
        RGE_Object_List_Node* node = world->players[i]->objects->head;
        while (node != 0) {
            if (node->object->type->id == id) {
                ++count;
            }
            node = node->next;
        }
    }
    return count;
}

static __inline int count_ruins(TRIBE_World* world) {
    int count = 0;
    int i;
    for (i = 0; i < world->player_num; ++i) {
        RGE_Object_List_Node* node = world->players[i]->objects->head;
        while (node != 0) {
            short id = node->object->type->id;
            if (id == 0x9e || id == 0xa3) {
                ++count;
            }
            node = node->next;
        }
    }
    return count;
}

static __inline void append_line(char* description, char* temp, const char* fmt, int text_id, char* value) {
    sprintf(temp, rge_base_game->get_string(text_id), value);
    sprintf(description, S_NEWLINE_JOIN, description, temp);
}

uchar TRIBE_World::new_game(RGE_Player_Info* param_1, int param_2) {
    RGE_RMM_Object_Generator* generator;
    int victoryAmount;
    uchar ret_num;
    char str1[256];
    char str2[256];
    char str3[256];
    char description[4096];
    int i;
    int age;
    int res;
    int want;
    int missing;

    this->score_displayed = 0;
    this->controllingComputerPlayer = 0xff;
    ret_num = RGE_Game_World::new_game(param_1, param_2);

    for (i = 0; i < this->player_num; ++i) {
        rge_base_game->reset_countdown_timer(i);
    }

    if (!((rge_base_game->campaignGame() || !rge_base_game->randomGame()) && rge_base_game->victoryType() == 0)) {
        if (!rge_base_game->campaignGame() && rge_base_game->randomGame()) {
        this->scenario->Set_scenario_name(S_EMPTY);
        }

    switch (rge_base_game->victoryType()) {
    case 0:
    case 9:
        rge_base_game->get_string(0x265c, description, 0x1000);
        break;
    case 1:
        rge_base_game->get_string(0x265f, description, 0x1000);
        break;
    case 7:
        rge_base_game->get_string(0x265d, description, 0x1000);
        break;
    case 8:
        rge_base_game->get_string(0x265e, description, 0x1000);
        break;
    default:
        break;
    }

    switch (rge_base_game->mapSize()) {
    case 0: strcpy(str1, rge_base_game->get_string(0x2973)); break;
    case 1: strcpy(str1, rge_base_game->get_string(0x2974)); break;
    case 2: strcpy(str1, rge_base_game->get_string(0x2975)); break;
    case 3: strcpy(str1, rge_base_game->get_string(0x2976)); break;
    case 4: strcpy(str1, rge_base_game->get_string(0x2977)); break;
    case 5: strcpy(str1, rge_base_game->get_string(0x2978)); break;
    }
    append_line(description, str2, "%s", 0x25da, str1);

    if (rge_base_game->randomGame()) {
        switch (rge_base_game->mapType()) {
        case 0: strcpy(str1, rge_base_game->get_string(0x296a)); break;
        case 1: strcpy(str1, rge_base_game->get_string(0x296b)); break;
        case 2: strcpy(str1, rge_base_game->get_string(0x296c)); break;
        case 3: strcpy(str1, rge_base_game->get_string(0x296d)); break;
        case 4: strcpy(str1, rge_base_game->get_string(0x296e)); break;
        case 5: strcpy(str1, rge_base_game->get_string(0x296f)); break;
        case 6: strcpy(str1, rge_base_game->get_string(0x2970)); break;
        case 7: strcpy(str1, rge_base_game->get_string(0x2971)); break;
        case 8: strcpy(str1, rge_base_game->get_string(0x2972)); break;
        }
        append_line(description, str2, "%s", 0x25b6, str1);
    }

    age = rge_base_game->startingAge();
    if (age == 0) {
        rge_base_game->get_string(0x10e7, str1, 0x100);
    } else if (age == 1) {
        rge_base_game->get_string(0x106e, str1, 0x100);
    } else {
        rge_base_game->get_string(age + 0x1067, str1, 0x100);
    }
    append_line(description, str2, "%s", 0x25e4, str1);

    res = rge_base_game->resourceLevel();
    if (res == 0) {
        rge_base_game->get_string(0x10e7, str1, 0x100);
    } else {
        rge_base_game->get_string(res + 0x25e5, str1, 0x100);
    }
    append_line(description, str2, "%s", 0x25e5, str1);

    rge_base_game->difficulty();
    rge_base_game->get_string(rge_base_game->difficulty() + 0x2bd0, str1, 0x100);
    append_line(description, (char*)str3, "%s", 0x25e0, str1);

    if (rge_base_game->randomizePositions() == 0) {
        rge_base_game->get_string(0x0fa3, str1, 0x100);
    } else {
        rge_base_game->get_string(0x0fa4, str1, 0x100);
    }
    append_line(description, str2, "%s", 0x25e9, str1);
    if (rge_base_game->fullVisibility() == 0) {
        strcpy(str1, rge_base_game->get_string(0x0fa4));
    } else {
        strcpy(str1, rge_base_game->get_string(0x0fa3));
    }
    append_line(description, str2, "%s", 0x25b8, str1);
    if (rge_base_game->fullTechTree() == 0) {
        rge_base_game->get_string(0x0fa4, str1, 0x100);
    } else {
        rge_base_game->get_string(0x0fa3, str1, 0x100);
    }
    append_line(description, str2, "%s", 0x25ec, str1);

    if (rge_base_game->multiplayerGame()) {
        if (rge_base_game->allowCheatCodes() == 0) {
            strcpy(str1, rge_base_game->get_string(0x0fa4));
        } else {
            strcpy(str1, rge_base_game->get_string(0x0fa3));
        }
        append_line(description, str2, "%s", 0x25bb, str1);
    }

    rge_base_game->get_string((rge_base_game->multiplayerGame() ? rge_base_game->mpPathFinding() : rge_base_game->pathFinding()) + 0x260e, str1, 0x100);
    append_line(description, str2, "%s", 0x25f1, str1);

    sprintf(str2, rge_base_game->get_string(0x25f0), (int)rge_base_game->popLimit());
    sprintf(description, S_NEWLINE_JOIN, description, str2);
        this->scenario->add_description(description);
    }

    if (ret_num) {
        this->victory_type = 4;
        this->countdown_victory = 0;
        this->countdown_clock = 0.0f;

        if ((!rge_base_game->campaignGame() && rge_base_game->randomGame()) || rge_base_game->victoryType() != 0) {
            this->scenario->Set_victory_all_flag(0);
            this->scenario->Set_Multi_Conquest(0);
            this->scenario->Set_Multi_Ruins(0);
            this->scenario->Set_Multi_Artifacts(0);
            this->scenario->Set_Multi_Discoveries(0);
            this->scenario->Set_Multi_Exploration(0);
            this->scenario->Set_Multi_Gold(0);
            victoryAmount = rge_base_game->victoryAmount();
            switch (rge_base_game->victoryType()) {
            case 0:
                this->victory_type = 0;
                this->scenario->Set_Multi_Conquest(1);
                break;
            case 1:
                this->victory_type = 0;
                this->scenario->Set_Multi_Conquest(1);
                break;
            case 2:
                this->victory_type = 1;
                this->scenario->Set_Multi_Conquest(1);
                break;
            case 3:
                this->scenario->Set_Multi_Exploration(victoryAmount);
                break;
            case 4:
                this->scenario->Set_Multi_Ruins(victoryAmount);
                break;
            case 5:
                this->scenario->Set_Multi_Artifacts(victoryAmount);
                break;
            case 6:
                this->scenario->Set_Multi_Discoveries(victoryAmount);
                break;
            case 7:
                this->scenario->Set_Multi_Gold(victoryAmount);
                break;
            case 8:
                this->victory_type = 2;
                this->scenario->Set_Multi_Conquest(1);
                break;
            case 9:
                this->victory_type = 3;
                this->scenario->Set_Multi_Conquest(1);
                break;
            }
            this->scenario->Save_victory_conditions_into_players(0);
            if (rge_base_game->victoryType() == 8) {
                this->countdown_victory = 1;
                this->countdown_clock = (float)victoryAmount;
            } else if (rge_base_game->victoryType() == 9) {
                for (i = 1; i < this->player_num; ++i) {
                    this->players[i]->victory->add_victory_points(0, victoryAmount, 1);
                }
            }
        } else {
            if (rge_base_game->campaignGame() || rge_base_game->scenarioGame()) {
                switch (this->scenario->GetMPVictory()) {
                case 0:
                    this->victory_type = 0;
                    break;
                case 1:
                    this->victory_type = 1;
                    break;
                case 2: {
                    this->victory_type = 3;
                    victoryAmount = this->scenario->GetVictoryScore();
                    for (i = 1; i < this->player_num; ++i) {
                        this->players[i]->victory->add_victory_points(0, victoryAmount, 1);
                    }
                    break;
                }
                case 3:
                    this->victory_type = 2;
                    this->countdown_victory = 1;
                    this->countdown_clock = (float)this->scenario->GetVictoryTime();
                    break;
                }
            }
        }

        generator = new RGE_RMM_Object_Generator(this->map, 0, this, 0, 0);

        want = this->scenario->Get_Multi_Artifacts();
        if (want > 0) {
            missing = want - count_objects(this, 0x9f);
            if (missing > 0) generator->add_quick_obj(0x9f, missing, 0);
        }
        want = this->scenario->Get_Multi_Discoveries();
        if (want > 0) {
            missing = want - count_objects(this, 10);
            if (missing > 0) generator->add_quick_obj(10, missing, 0);
        }
        want = this->scenario->Get_Multi_Ruins();
        if (want > 0) {
            missing = want - count_ruins(this);
            if (missing > 0) generator->add_quick_obj(0x9e, missing, 0);
        }

        if (!rge_base_game->campaignGame() && rge_base_game->randomGame()) {
            if (this->victory_type == 3 || debug_rand((const char*)0x58c600, 0x38d) % 100 < 50) {
                generator->add_quick_obj(0x9f, 5, *((int*)this->map + 2) / 5);
                this->artifact_count = 5;
            }
            if (debug_rand((const char*)0x58c600, 0x394) % 100 < 50) {
                generator->add_quick_obj(0x9e, 5, *((int*)this->map + 2) / 5);
                this->ruin_count = 5;
            }
        } else {
            this->artifact_count = count_objects(this, 0x9f);
            this->ruin_count = count_ruins(this);
        }

        generator->generate();
        if (generator != 0) {
            delete generator;
        }
    }

    if (!rge_base_game->allowTrading()) {
        for (i = 1; i < this->player_num; ++i) {
            this->effects->do_effect(0x69, this->players[i]);
        }
    }
    if (rge_base_game->longCombat() == 1) {
        for (i = 1; i < this->player_num; ++i) {
            this->effects->do_effect(0x64, this->players[i]);
        }
    }

    if (!rge_base_game->fullTechTree() && !this->scenario->GetScenarioOption(2)) {
        for (i = 1; i < this->player_num; ++i) {
            this->effects->do_effect(this->players[i]->civilization, this->players[i]);
        }
    } else {
        for (i = 1; i < this->player_num; ++i) {
            this->effects->do_effect(0xd2, this->players[i]);
        }
    }

    switch (rge_base_game->resourceLevel()) {
    case 1:
        for (i = 1; i < this->player_num; ++i) {
            *(int*)&this->players[i]->resources[0] = 0x43480000;
            *(int*)&this->players[i]->resources[1] = 0x43480000;
            *(int*)&this->players[i]->resources[3] = 0;
            *(int*)&this->players[i]->resources[2] = 0x42c80000;
        }
        break;
    case 2:
        for (i = 1; i < this->player_num; ++i) {
            *(int*)&this->players[i]->resources[0] = 0x43fa0000;
            *(int*)&this->players[i]->resources[1] = 0x43fa0000;
            *(int*)&this->players[i]->resources[3] = 0;
            *(int*)&this->players[i]->resources[2] = 0x437a0000;
        }
        break;
    case 3:
        for (i = 1; i < this->player_num; ++i) {
            *(int*)&this->players[i]->resources[0] = 0x447a0000;
            *(int*)&this->players[i]->resources[1] = 0x447a0000;
            *(int*)&this->players[i]->resources[3] = 0;
            *(int*)&this->players[i]->resources[2] = 0x443b8000;
        }
        break;
    }

    if (rge_base_game->deathMatch()) {
        for (i = 1; i < this->player_num; ++i) {
            *(int*)&this->players[i]->resources[0] = 0x469c4000;
            *(int*)&this->players[i]->resources[1] = 0x469c4000;
            *(int*)&this->players[i]->resources[3] = 0x461c4000;
            *(int*)&this->players[i]->resources[2] = 0x459c4000;
        }
    }

    switch (rge_base_game->startingAge()) {
    case 3:
        for (i = 1; i < this->player_num; ++i) this->players[i]->rev_tech(0x19);
        break;
    case 4:
        for (i = 1; i < this->player_num; ++i) this->players[i]->rev_tech(0x17);
        break;
    case 5:
        for (i = 1; i < this->player_num; ++i) this->players[i]->rev_tech(0x18);
        break;
    }

    if (rge_base_game->check_prog_argument((const char*)0x58c5f4)) {
        for (i = 1; i < this->player_num; ++i) {
            this->players[i]->new_attribute_num(0x20, 50.0f);
            this->players[i]->new_attribute_num(0x21, 0.0f);
            this->players[i]->new_attribute_num(0x1e, 500.0f);
            this->players[i]->new_attribute_num(0x1f, 5000.0f);
        }
    } else if (rge_base_game->check_prog_argument((const char*)0x58c5ec)) {
        for (i = 1; i < this->player_num; ++i) {
            this->players[i]->new_attribute_num(0x20, 50.0f);
            this->players[i]->new_attribute_num(0x21, 0.0f);
        }
    } else {
        for (i = 1; i < this->player_num; ++i) {
            this->players[i]->new_attribute_num(0x20, (float)rge_base_game->popLimit());
            this->players[i]->new_attribute_num(0x21, 0.0f);
            this->players[i]->new_attribute_num(0x1e, 500.0f);
            this->players[i]->new_attribute_num(0x2d, 1.0f);
            this->players[i]->victory->add_points_attribute_amount(0, 0, 0x14, 2, 1);
            this->players[i]->victory->add_points_attribute_amount(0, 1, 0x2b, 1, 1);
            this->players[i]->victory->add_points_attribute_amount(0, 2, 0x2c, 1, 1);
            this->players[i]->victory->add_points_high_attribute_once(0, 3, 0x28, 1, 0x19);
            this->players[i]->victory->add_points_attribute_amount(1, 4, 0x31, 100, 1);
            this->players[i]->victory->add_points_attribute_amount(1, 9, 0x35, 0x3c, 1);
            this->players[i]->victory->add_points_high_attribute_amount(1, 5, 0x25, 1, 1);
            this->players[i]->victory->add_points_high_attribute_once(1, 6, 0x25, 1, 0x19);
            this->players[i]->victory->add_points_attribute_amount(1, 7, 0x16, 3, 1);
            if (!rge_base_game->fullVisibility()) {
                this->players[i]->victory->add_points_highest_attribute(1, 8, 0x16, 1, 0x19);
            }
            this->players[i]->victory->add_points_attribute_amount(2, 10, 0x29, 1, 2);
            this->players[i]->victory->add_points_highest_attribute(2, 11, 0x29, 1, 0x19);
            this->players[i]->victory->add_points_attribute_amount(2, 12, 0x0e, 1, 10);
            this->players[i]->victory->add_points_attribute_amount(2, 13, 7, 1, 10);
            this->players[i]->victory->add_points_attribute_amount(2, 14, 0x34, 1, 3);
            this->players[i]->victory->add_points_attribute_amount(2, 16, 0x37, 1, 0x32);
            this->players[i]->victory->add_points_attribute_amount(2, 15, 0x36, 1, 0x32);
            this->players[i]->victory->add_points_attribute_amount(3, 17, 0x15, 1, 2);
            this->players[i]->victory->add_points_highest_attribute(3, 18, 0x15, 1, 0x32);
            this->players[i]->victory->add_points_attribute_first(3, 19, 6, 3, 0x19);
            this->players[i]->victory->add_points_attribute_first(3, 20, 6, 4, 0x19);
            this->players[i]->victory->add_points_attribute_amount(4, 22, 0x2d, 1, 100);
            this->players[i]->victory->add_points_attribute_amount(4, 23, 0x2a, 1, 100);
            this->players[i]->add_population_entry();
        }    }

    return ret_num;
}
