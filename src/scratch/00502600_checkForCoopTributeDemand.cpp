// 00502600 TribeTacticalAIModule::checkForCoopTributeDemand
// scratch give-up: natural reconstruction from packet/decompiler. Tried direct md->world vs md->holder->world
// (holder is required for the original [md+f0]->[+3c] time/player access), dummy frame local, volatile
// frame local (regressed by adding a store), and preserving explicit gotos for resource gates. Best check:
// exact size 788 but broad mismatch 70.94% positional / 38.96% edit; frame remains 0x14 vs original 0x18
// and later drift is loop/block-shape plus temp-slot allocation around resource/tribute scans.

typedef unsigned char uchar;

struct RGE_Player {
    virtual void pad00(); virtual void pad04(); virtual void pad08(); virtual void pad0c();
    virtual void pad10(); virtual void pad14(); virtual void pad18();
    virtual int vf1c(int);
    char gap04[0x46];
    short id; // +4a
    char gap4c[4];
    float* resources; // +50
    int computerPlayer();
    void tribute(short player, int one, int resource, int amount, int zero);
};

struct World { int pad0; unsigned int time; char gap08[0x34]; short player_count; char gap3e[2]; RGE_Player** players; char gap44[6]; short my_id; char gap4c[0xd1]; uchar coop_tribute_player; };
struct WorldHolder { char gap0[0x3c]; World* world; };
struct ResourceAI { int resource(int); };
struct MainDecision { char gap0[0xf0]; WorldHolder* holder; char gapf4[0x10c88]; ResourceAI resourceAI; }; 
struct TribeTacticalAIModule {
    char gap000[0xf0];
    MainDecision* md;
    char gap0f4[0x388];
    int coopTributeInterval; // 47c
    int coopTributeAmount; // 480
    char gap484[8];
    int foodMin; int woodMin; int stoneMin; int goldMin; // 48c..
    char gap49c[0x8ec];
    int neededResourceValue[4]; // d88
    char gapd98[0x200];
    int lastCoopTributeDemandTime; // f98
    void checkForCoopTributeDemand();
};

extern "C" int __cdecl debug_rand(char*, int);

void TribeTacticalAIModule::checkForCoopTributeDemand()
{
    int tempRand;
    World* world;
    int i;
    int j;
    int amountDemandable;
    int dummy_frame;
    RGE_Player* player;
    int cur;
    int count;

    if (this->coopTributeInterval == -1) return;
    world = this->md->holder->world;
    cur = world->time;
    if ((cur - this->lastCoopTributeDemandTime) / 1000 < this->coopTributeInterval) return;
    this->lastCoopTributeDemandTime = cur;

    world = this->md->holder->world;
    if (world->coop_tribute_player == 0xff) {
        i = 1;
        count = 0;
        if (world->player_count > 1) {
            do {
                if (world->players[i]->computerPlayer() == 1) count++;
                i++;
            } while (i < world->player_count);
        }
        if (count == 1) {
            world->coop_tribute_player = (uchar)this->md->holder->world->my_id;
        } else {
            tempRand = debug_rand("C:\\msdev\\work\\age1_x1\\taitacmd.cpp", 0x31f0) % count + 1;
            j = 1;
            if (world->player_count > 1) {
                do {
                    player = world->players[j];
                    if (player->computerPlayer() == 1) {
                        tempRand--;
                        if (tempRand == 0) world->coop_tribute_player = (uchar)player->id;
                    }
                    j++;
                } while (j < world->player_count);
            }
        }
    }

    if (world->coop_tribute_player != (uchar)this->md->holder->world->my_id) return;

    tempRand = this->coopTributeAmount;
    int* need = this->neededResourceValue;
    i = 0;
    do {
        if (tempRand <= 0) return;
        if (*need == 0 && this->md->resourceAI.resource(0) >= this->foodMin) goto next;
        if (*need == 1 && this->md->resourceAI.resource(1) >= this->woodMin) goto next;
        if (*need == 3 && this->md->resourceAI.resource(3) >= this->goldMin) goto next;
        if (*need == 2 && this->md->resourceAI.resource(2) >= this->stoneMin) goto next;
        if (need[4] < 0) {
            j = 1;
            if (world->player_count > 1) {
                do {
                    if (tempRand <= 0) break;
                    player = world->players[j];
                    if (player->id != this->md->holder->world->my_id && player->computerPlayer() != 0) {
                        if (this->md->holder->world->players[0]->vf1c(j) != 0) {
                            if (player->vf1c((int)this->md->holder->world->my_id) != 0) {
                                short myid = this->md->holder->world->my_id;
                                if ((myid < player->id && player->id != (short)world->coop_tribute_player) || myid == (short)world->coop_tribute_player) {
                                    int res = *need;
                                    amountDemandable = (int)player->resources[res];
                                    if (amountDemandable > 50) {
                                        if (amountDemandable > tempRand) amountDemandable = tempRand;
                                        tempRand -= amountDemandable;
                                        player->tribute(myid, 1, res, amountDemandable, 0);
                                    }
                                }
                            }
                        }
                    }
                    j++;
                } while (j < world->player_count);
            }
        }
next:
        need++;
        i++;
    } while (i < 4);
}
