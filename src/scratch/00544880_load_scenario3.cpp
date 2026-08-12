// 00544880 RGE_Game_World::load_scenario3
// Attempt log:
// 1: natural reconstruction from asm/decompiler with exact stack locals/order and raw virtual calls.
// 2: fixed compile type errors by using long* for player_id_hash walks and local load_factor for 1.04f.
// 3: raw cdecl virtual macros for RGE_Game_World load calls compiled but added explicit this pushes and stack cleanup.
// 4: replaced RGE_Game_World +0x70/+0xF4 raw macros with real virtual declarations/padding; recovered the thiscall virtual-call family and improved positional diff to 37.468%.
// 5: modeled player_num/player array/scenario/object flag/object id offsets from original asm (+0x3C/+0x40/+0x5C/+0x74/+0x70).
// 6: modeled player_id_hash[9] initialization; compiler emits rep stosd but stack frame still 0x5C vs original 0x64.
// 7: tried adding unused pad locals for the missing 8 bytes; VC5 optimized them away, no change.
// 8: modeled nested read loops and player create/load/setup virtual call slots +0x60/+0x68/+0x2C with raw helpers; behavior paths present but stack/call surface not exact.
// 9: no inline asm or custom flags tried.
// 10: left in scratch: frame/local placement and late player virtual call surfaces remain broad mismatch, not accepted_drift.
// 11: replaced cdecl vtable macros with the donor-backed Player virtual ABI;
//     slot +0x60 takes six typed object fields, +0x68 takes file/map/factor,
//     and +0x2c takes the five setup fields.  Scenario posture takes one arg.
// 12: corrected the fallback comparison to `*map <= -1`; this matched the
//     original jle form and restored all 25 direct-call relocation identities.
// 13: final validation retained the 0x64 stack frame and all 29 ordered calls.
// Main-agent audit removed compensating stack aliases. The first four-byte
// value owns next_object_id. Object records use x/y/z/id/master/state/angle.

typedef unsigned char uchar;
extern "C" void __cdecl rge_read_uncompressed(int file, void* dst, int size);
extern "C" void __cdecl rge_read(int file, void* dst, int size);
extern "C" int __cdecl rge_close(int file);
extern "C" void* __cdecl malloc(unsigned int size);
extern "C" void __cdecl free(void* ptr);
extern "C" int world_update_counter;

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(uchar);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int);
    virtual int isEnemy(int);
    virtual int isAlly(int);
    virtual int isNeutral(int);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int, int);
    virtual void loadAIInformation(char*, char*, char*, int, int);
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    virtual void kickAI(int);
    virtual int strategicNumber(int);
    virtual void sendGameOrder(void*, void*, float, float);
    virtual void sendAddWaypointCommand(int, void*, int);
    virtual void processAddWaypointCommand(int, void*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int);
    virtual void trackUnitGather(int, int, int);
    virtual void* make_scenario_obj(float, float, float, short, uchar, float);
    virtual void scenario_save(int);
    virtual void scenario_load(int, long*, float);
    virtual void scenario_postsave(int);
    virtual void scenario_postload(int, long*, float);
    void remake_visible_map();
};
class RGE_Scenario {
public:
    int GetPlayerPosture(int p);
    char* Get_player_AI(int p, int one);
    char* Get_CityPlan(int p, int one);
    char* Get_BuildList(int p, int one);
};
struct RGE_Player_Info { char gap[0x270]; int player_id[16]; };
#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)

class RGE_Game_World {
public:
    VPAD16(0) VPAD8(16) VPAD4(24)
    virtual void load2(int file);
    VPAD16(29) VPAD16(45)
    virtual void load1(int file, RGE_Game_World* self);
    char gap_04[0x38];
    short player_num;
    char gap_3e[2];
    RGE_Player** players;
    char gap_44[0x18];
    RGE_Scenario* scenario;
    char gap_60[8];
    int next_object_id;
    char gap_6c[4];
    int scenario_object_id;
    uchar scenario_object_flag;
    void load_scenario3(int file, RGE_Player_Info& info);
};

void RGE_Game_World::load_scenario3(int file, RGE_Player_Info& info)
{
    uchar master_player_id;
    long scenario_player_num;
    long next_object_id;
    long count;
    long id;
    float obj_angle;
    uchar obj_state;
    short master_id;
    float world_z;
    float world_y;
    float world_x;
    char rem[13];
    long player_id_hash[9];
    int outer;

    world_update_counter = 0;
    rge_read_uncompressed(file, &count, 4);
    if (count > 0) {
        void* p = malloc(count);
        if (p == 0) {
            rge_close(file);
            return;
        }
        rge_read_uncompressed(file, p, count);
        free(p);
    }
    rge_read(file, &next_object_id, 4);
    this->load1(file, this);
    this->load2(file);
    int n = this->player_num;
    if (n > 0) {
        do {
            for (int k = 0; k < 9; k++) player_id_hash[k] = -1;
        } while (n > 10);
    }
    int i = 0;
    if (n > 0) {
        int* ids = info.player_id;
        do {
            player_id_hash[*ids++] = i;
            i++;
        } while (i < n);
    }
    i = 0;
    if (n > 0) {
        do {
            this->players[i]->remake_visible_map();
            i++;
        } while (i < this->player_num);
    }
    rge_read(file, &scenario_player_num, 4);
    i = 0;
    if (scenario_player_num > 0) {
        do {
            rge_read(file, &master_player_id, 1);
            rge_read(file, &obj_state, 1);
            i++;
        } while (i < scenario_player_num);
    }
    outer = 0;
    if (scenario_player_num > 0) {
        long* map = player_id_hash;
        do {
            rge_read(file, &count, 4);
            int j = 0;
            if (count > 0) {
                do {
                    rge_read(file, &world_z, 4);
                    rge_read(file, &world_y, 4);
                    rge_read(file, &world_x, 4);
                    rge_read(file, &id, 4);
                    rge_read(file, &master_id, 2);
                    rge_read(file, &obj_state, 1);
                    rge_read(file, &obj_angle, 4);
                    int pid = *map;
                    if (pid >= 0 && this->players[pid] != 0) {
                        this->scenario_object_flag = 1;
                        this->scenario_object_id = id;
                        this->players[pid]->make_scenario_obj(
                            world_z, world_y, world_x, master_id, obj_state,
                            obj_angle);
                        this->scenario_object_flag = 0;
                    }
                    j++;
                } while (j < count);
            }
            outer++;
            map++;
        } while (outer < scenario_player_num);
    }
    this->next_object_id = next_object_id;
    rge_read(file, rem, 13);
    i = 1;
    if (scenario_player_num > 1) {
        long* map = player_id_hash + 1;
        do {
            RGE_Player* pl;
            if (i >= this->player_num || *map <= -1 || (pl = this->players[*map]) == 0) {
                pl = this->players[0];
            }
            pl->scenario_load(file, player_id_hash, 1.04f);
            i++;
            map++;
        } while (i < scenario_player_num);
    }
    rge_close(file);
    i = 1;
    if (this->player_num > 1) {
        do {
            if (i >= scenario_player_num) return;
            if (this->players[i] != 0 && player_id_hash[i] > -1) {
                int idx = i - 1;
                this->players[player_id_hash[i]]->loadAIInformation(this->scenario->Get_BuildList(idx,1), this->scenario->Get_CityPlan(idx,1), this->scenario->Get_player_AI(idx,1), this->scenario->GetPlayerPosture(idx), -1);
            }
            i++;
        } while (i < this->player_num && i < scenario_player_num);
    }
}
