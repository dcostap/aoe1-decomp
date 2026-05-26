// 005153D0 TRIBE_Player::loadAIInformation
// Attempt log:
// try 1: direct packet/Ghidra reconstruction: 3x 256-byte name buffers, debug-rand save/restore, AI file selection/loading, personality/rules/build-list setup, diplomacy loops; compile failed on VC5 __thiscall vtable typedefs.
// try 2: changed vtable typedefs to __stdcall; default /O2 too small (.text 1424 vs 1514).
// try 3: inlined empty-string strcpy calls and added the two original resource get_string calls; default /O2 improved to .text 1472 vs 1514 but still too small.
// try 4: diagnostic impossible saveRand/save_debug_random_on == -1 log branches only to force exact-size compare; exact-size 1514/1514 but broad mismatch 83.5535% positional / 94.8481% edit, first mismatch +27 around saveRand/save_debug_random_on stack scheduling; diagnostic branches rolled back.
// try 5: /GX on diagnostic source no change; rolled back.
// try 6: /Od diagnostic exact-size but worse debug-basin mismatch 86.3276% positional / 169.5509% edit; rolled back.
// left in scratch: no custom flags retained. Not accepted_drift quality; likely needs exact TRIBE_Player/AI loader class surfaces, original string/strcmp intrinsic context, and exact virtual/member prototypes/source spelling.

typedef unsigned int uint;
typedef int BOOL;

extern "C" int __cdecl debug_rand(const char* file, int line);
extern "C" void __cdecl debug_rand_restore(const char* file, int line, int value);
extern "C" void __cdecl log_printf(void* log, const char* fmt, ...);
extern "C" int __cdecl random_func();
extern "C" void* __cdecl strcpy(void*, const void*);
extern "C" int __cdecl strcmp(const char*, const char*);

#define debug_random_on (*(int*)0x0062C4D4)
#define saved_debug2 (*(int*)0x0086BC94)
#define base_game (*(TRIBE_Game**)0x0062C574)

struct FileReader;
struct FileReaderVtbl { char pad[0x20]; void (__stdcall *get_string)(FileReader*, int, char*, int); };
struct FileReader { FileReaderVtbl* vtbl; };

struct Loader;
struct LoaderVtbl { char pad[0x40]; int (__stdcall *load)(Loader*, char*, int, int, int, int, int); int (__stdcall *load2)(Loader*, char*, void*); };
struct Loader { LoaderVtbl* vtbl; };

class TRIBE_Game {
public:
    void* vtbl;
    int mapType();
    int randomMapScript();
    int terrainType();
};

class TRIBE_Scenario_Info { public: char gap[0x3C]; short player_count; char gap2[0x20]; void* victory; };
class TRIBE_Player;

class AIName { public: void load(const char*); void set(int); };
class Diplomacy { public: void set_stance(int player, int a, int b); void set_visible(int player, int v); };
class LearnInfo { public: void loadLearnInfo(char*); };
class Personality { public: void sub_4E6160(); };

class TRIBE_Player {
public:
    void* vtbl;
    char gap0[0x38];
    TRIBE_Scenario_Info* scenario;
    char gap1[0x0A];
    short player_num;
    char gap2[0x1EA];
    void* log;
    char gap3[0x7A0];
    Diplomacy diplomacy;
    char gap4[0xB2C-0x9DC-sizeof(Diplomacy)];
    AIName build_list;
    char gap5[0xCEC-0xB2C-sizeof(AIName)];
    LearnInfo learn_info;
    char gap6[0x10E74-0xCEC-sizeof(LearnInfo)];
    AIName rules;

    int is_ally(int player);
    int is_enemy(int player);
    void setup_ai_info(char* ruleSetName, char* buildListName, int map, int terrain, int script);
    virtual void loadAIInformation(char* aiFile, char* ruleFile, char* personalityFile, int buildId, int unused);
};

void TRIBE_Player::loadAIInformation(char* aiFile, char* ruleFile, char* personalityFile, int buildId, int unused)
{
    char noneString[256];
    char randomString[256];
    char ruleSetName[256];
    char buildListName[256];

    int save_debug_random_on;
    int saveRand = debug_rand((const char*)0x58AC44, 0x863);
    save_debug_random_on = debug_random_on;
    saved_debug2 = save_debug_random_on;
    debug_random_on = 0;

    if (this->log) {
        switch (base_game->mapType()) {
        case 0: log_printf(this->log, (const char*)0x58B114); break;
        case 1: log_printf(this->log, (const char*)0x58B0F8); break;
        case 2: log_printf(this->log, (const char*)0x58B0D8); break;
        case 3: log_printf(this->log, (const char*)0x58B0BC); break;
        case 4: log_printf(this->log, (const char*)0x58B0A0); break;
        default: log_printf(this->log, (const char*)0x58B060); break;
        }
        ((FileReader*)base_game)->vtbl->get_string((FileReader*)base_game, 0x2775, noneString, 0x100);
        ((FileReader*)base_game)->vtbl->get_string((FileReader*)base_game, 0x277B, randomString, 0x100);

        strcpy(buildListName, (const void*)0x592A40);
        strcpy(ruleSetName, (const void*)0x592A40);

        if (aiFile) {
            if (strcmp(aiFile, randomString) == 0) {
                do {
                    this->setup_ai_info(ruleSetName, buildListName, base_game->mapType(), base_game->terrainType(), base_game->randomMapScript());
                    log_printf(this->log, (const char*)0x58B034, buildListName);
                } while (((Loader*)((char*)this->log + 0x104))->vtbl->load2((Loader*)((char*)this->log + 0x104), buildListName, this) == 0);
            } else {
                log_printf(this->log, (const char*)0x58B01C, aiFile);
                ((Loader*)((char*)this->log + 0x104))->vtbl->load2((Loader*)((char*)this->log + 0x104), aiFile, this);
            }
        } else {
            do {
                this->setup_ai_info(ruleSetName, buildListName, base_game->mapType(), base_game->terrainType(), base_game->randomMapScript());
                log_printf(this->log, (const char*)0x58AFFC, buildListName);
            } while (((Loader*)((char*)this->log + 0x104))->vtbl->load2((Loader*)((char*)this->log + 0x104), buildListName, this) == 0);
        }

        if (ruleFile) {
            if (strcmp(ruleFile, randomString) == 0) log_printf(this->log, (const char*)0x58AFC0);
            else {
                log_printf(this->log, (const char*)0x58AFA8, ruleFile);
                Loader* l = (Loader*)((char*)this->log + 0x6C4);
                l->vtbl->load(l, ruleFile, ((int**)this->scenario)[0x0A][2], ((int**)this->scenario)[0x0A][3], 0, 0, 0);
            }
        } else {
            log_printf(this->log, (const char*)0x58AFC0);
            Loader* l = (Loader*)((char*)this->log + 0x6C4);
            l->vtbl->load(l, (char*)0x57F350, ((int**)this->scenario)[0x0A][2], ((int**)this->scenario)[0x0A][3], 0, 0, 0);
        }

        if (personalityFile && strcmp(personalityFile, randomString) != 0) {
            log_printf(this->log, (const char*)0x58AF90, personalityFile);
            this->rules.load(personalityFile);
        } else if (strcmp(ruleSetName, (const char*)0x58AF78) != 0) {
            log_printf(this->log, (const char*)0x58AF4C, ruleSetName);
            this->rules.load(ruleSetName);
        } else {
            log_printf(this->log, (const char*)0x58AF10);
        }

        int r = random_func();
        log_printf(this->log, (const char*)0x58AEF0, r);
        this->rules.set(r);
        ((Personality*)this->log)->sub_4E6160();

        for (int i = 1; i < this->scenario->player_count; ++i) {
            if (i == this->player_num) {
                this->diplomacy.set_stance(i, 0, 0);
                this->diplomacy.set_stance(i, 2, 100);
            } else if (this->is_ally(i)) {
                this->diplomacy.set_stance(i, 0, 0x4A);
                this->diplomacy.set_stance(i, 2, 0x18);
            } else if (this->is_enemy(i)) {
                this->diplomacy.set_stance(i, 0, 0x18);
                this->diplomacy.set_stance(i, 2, 0x4A);
            }
        }

        for (int j = 1; j < this->scenario->player_count; ++j) {
            if (!this->is_ally(j) && !this->is_enemy(j)) this->diplomacy.set_visible(j, 1);
            else this->diplomacy.set_visible(j, 0);
        }

        this->build_list.set(buildId);
        char* learn = *(char**)((char*)this->scenario->victory + 0x1010);
        if (learn && *learn) this->learn_info.loadLearnInfo(learn);
    }

    debug_random_on = save_debug_random_on;
    debug_rand_restore((const char*)0x58AC44, 0x8FD, saveRand);
}
