// 00502D50 TribeTacticalAIModule::checkForCoopAttack
// Attempt log:
// 1: Natural reconstruction from asm: timing gate, random coop-player choice, per-player attack-order checks; broad mismatch due extra locals and /100 divisor.
// 2: Modeled current object as RGE_Player with player_list at +3c and /1000 timing; optimized too small (416-byte .text), wrong prolog/register allocation.
// 3: Tried explicit self/ai locals: still optimized too small.
// 4: Tried /Ob0: still optimized too small; removed flag.
// 5: Tried /Od: 89.58% broad mismatch from first byte; removed flag.
// BLOCKER: behavior is mostly reconstructed, but VC5 source shape/local topology is wrong. Natural high-level version collapses to 416 bytes; extra-local version has correct size but wrong prolog/register allocation and broad cascade. Need recover original one-local topology: `push ecx`, save `this` in EBP, EDI as PlayerList, EBX as loop index/local slot, with `/1000` timing magic 0x10624DD3.

extern int debug_rand(const char* file, int line);
extern const char str_taitacmd_path[];

class RGE_Player {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18();
    virtual int acceptsCoop(short playerId);
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50();
    virtual void sendCoopAttack(short playerId, int action, int p1, int p2, int p3);
    char gap_04[0x46];
    short player_num;
    int computerPlayer();
};

class PlayerList {
public:
    char gap_00[4]; int current_time; char gap_08[0x34]; short player_count; char gap_3e[2];
    RGE_Player** players; char gap_44[0x11d - 0x44]; unsigned char coop_player;
};
class UnitObject { public: char gap_00[0x3c]; PlayerList* player_list; char gap_40[0x0a]; short player_num; };
class UnitAIModule { public: char gap_00[0xF0]; UnitObject* object; };
class TribeTacticalAIModule {
public:
    char gap_000[0x0F0]; UnitAIModule* unit_ai; char gap_0f4[0x4A4 - 0x0F4];
    int coopAttackEnabled; int coopAttackInterval; char gap_4ac[0x0FA0 - 0x4AC]; int lastCoopAttackTime;
    void checkForCoopAttack(int p1, int p2, int p3);
};

void TribeTacticalAIModule::checkForCoopAttack(int p1, int p2, int p3)
{
    if (this->coopAttackEnabled != 1) return;

    UnitAIModule* ai = this->unit_ai;
    PlayerList* list = ai->object->player_list;
    int now = list->current_time;
    if ((now - this->lastCoopAttackTime) / 1000 < this->coopAttackInterval) return;
    this->lastCoopAttackTime = now;

    list = ai->object->player_list;
    if (list->coop_player == 0xff) {
        int num_computer = 0;
        int i = 1;
        if (list->player_count > 1) {
            do {
                if (list->players[i]->computerPlayer() == 1) ++num_computer;
                ++i;
            } while (i < list->player_count);
        }
        if (num_computer == 1) {
            list->coop_player = ai->object->player_num;
        } else {
            int pick = debug_rand(str_taitacmd_path, 0x32f1) % num_computer + 1;
            i = 1;
            if (list->player_count > 1) {
                do {
                    RGE_Player* other = list->players[i];
                    if (other->computerPlayer() == 1) {
                        --pick;
                        if (pick == 0) list->coop_player = other->player_num;
                    }
                    ++i;
                } while (i < list->player_count);
            }
        }
    }

    int idx = 1;
    if (list->player_count <= 1) return;
    do {
        RGE_Player* other = list->players[idx];
        short other_id = other->player_num;
        short my_id = ai->object->player_num;
        if (other_id != my_id && other->computerPlayer() != 0 && ((RGE_Player*)ai->object)->acceptsCoop((short)idx) != 0 && other->acceptsCoop(my_id) != 0) {
            if ((my_id < other_id && other_id == list->coop_player) || my_id == list->coop_player) {
                other->sendCoopAttack(my_id, 2, p1, p2, p3);
            }
        }
        ++idx;
    } while (idx < list->player_count);
}
