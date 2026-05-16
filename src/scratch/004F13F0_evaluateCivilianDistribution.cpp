// 004F13F0 TribeTacticalAIModule::evaluateCivilianDistribution()
// Source: taitacmd.cpp lines 3202-3308
// Attempt log:
// - Initial natural source from packet/decompiler; local layout only.
// - Fixed ManagedArray<int> local layout to value+0, number+4, max+0xC, sizeof 0x18; this aligned civilians/playersToAttack offsets.
// - Added real md->player->visibleMap chain (+0xF0 then +0x38) to match the percentExplored prelude.
// - Restructured civ-count branch as `if (number >= 3) ... else ...` so VC5 lays out the small-civilian case at the end like original.
// - Reused a ManagedArray_int* local for both playersToAttack and civilians; this gives the original EDI `lea`/resize/value access family.
// - Changed ceil expression to `(float)((double)sn0 * count) * 0.01f`, producing original fild/fimul/fmul dword/fstp/call sequence.
// - Introduced a `zero` local initialized near the fullyExplored test; this made VC5 keep EDI as zero and restored push ebp/EBP=percentExplored, EBX=numberItems.
// - Changed half-clamp to compare against zero (`desired <= zero`) so the divide block uses `cmp eax,edi` / `jg` / `xor eax,eax`.
// - Left in scratch: current build has exact prologue and first ~100 bytes; remaining diff is mostly branch-distance/layout drift. Main-path code is 4 bytes longer before the small-civilian tail (jl target 004F158A vs original 004F1586), and the gatherer cap uses a near JE because the shared tail is slightly farther. No inline asm used.

extern "C" double __cdecl ceil(double);

class RGE_Visible_Map {
public:
    float percentExplored();
};

class ManagedArray_int {
public:
    int* value;
    int numberValue;
    char gap_008[0x4];
    int maximumSizeValue;
    char gap_010[0x8];
    int resize(int size);
};

class TribeInformationAIModule {
public:
    int fullyExploredZone(int zone);
    int numberGameIDsOwnedBy(int player, int gameID);
};

class PlayerLike {
public:
    char gap_000[0x38];
    RGE_Visible_Map* visibleMap;
};

class TribeMainDecisionAIModule {
public:
    char gap_000[0xF0];
    PlayerLike* player;
    char gap_0F4[0xCEC - 0xF4];
    TribeInformationAIModule informationAI;
};

class TribeTacticalAIModule {
public:
    char gap_000[0xF0];
    TribeMainDecisionAIModule* md;
    ManagedArray_int civilians;
    int civilianExplorersDesired;     // 0x10c
    char gap_110[0x194 - 0x110];
    int sn0;
    char gap_198[0x1A0 - 0x198];
    int sn3;
    char gap_1A4[0x1A8 - 0x1A4];
    int sn5;
    char gap_1AC[0x1DC - 0x1AC];
    int sn18;
    char gap_1E0[0x214 - 0x1E0];
    int sn20;
    char gap_218[0x220 - 0x218];
    int sn23;
    char gap_224[0x3D8 - 0x224];
    int sn91;
    char gap_3DC[0x460 - 0x3DC];
    int snB3;
    char gap_464[0x9D0 - 0x464];
    int desiredNumberGatherers;
    char gap_9D4[0xD28 - 0x9D4];
    ManagedArray_int playersToAttack;
    char gap_D3C[0xFA4 - 0xD3C];
    int zoomingToNextAge;

    void evaluateCivilianDistribution();
    int numberSoldierExplorers();
    void displayCivilianDistribution();
    void updateGathererDistribution();
};

void TribeTacticalAIModule::evaluateCivilianDistribution()
{
    int percentExplored;
    int numberItems;
    int desired;
    int gatherers;
    ManagedArray_int* list;
    int zero;

    percentExplored = (int)(this->md->player->visibleMap->percentExplored() * 100.0f);

    list = &this->playersToAttack;
    if (list->maximumSizeValue - 1 < 0) {
        list->resize(1);
    }
    numberItems = this->md->informationAI.numberGameIDsOwnedBy(-1, *list->value);

    if (this->civilians.numberValue >= 3) {
    list = &this->civilians;
    if (list->maximumSizeValue - 1 < 0) {
        list->resize(1);
    }
    if (this->md->informationAI.fullyExploredZone(*list->value) == 1) {
        zero = 0;
        this->civilianExplorersDesired = (int)ceil((float)((double)this->sn0 * this->civilians.numberValue) * 0.01f);
        desired = this->numberSoldierExplorers();
        if (desired + this->civilianExplorersDesired > this->sn18) {
            this->civilianExplorersDesired = this->sn18 - desired;
        }
        if (this->sn3 != -1 && this->civilianExplorersDesired > this->sn3) {
            this->civilianExplorersDesired = this->sn3;
        }
    }
    else {
        zero = 0;
        this->civilianExplorersDesired = zero;
    }

    if (percentExplored >= this->sn20 && numberItems > this->sn91) {
        desired = this->sn23;
        if (this->civilianExplorersDesired > desired) {
            this->civilianExplorersDesired = desired;
        }
    }
    else if (percentExplored >= this->snB3) {
        desired = this->civilianExplorersDesired / 2;
        if (desired <= zero) {
            desired = zero;
        }
        this->civilianExplorersDesired = desired;
    }

    if (this->zoomingToNextAge == 1) {
        this->civilianExplorersDesired = zero;
    }

    gatherers = this->civilians.numberValue - this->civilianExplorersDesired;
    this->desiredNumberGatherers = gatherers;
    if (this->sn5 != -1 && gatherers > this->sn5) {
        this->desiredNumberGatherers = this->sn5;
    }
    }
    else {
        if (this->civilians.numberValue == 1) {
            this->desiredNumberGatherers = 0;
        }
        else {
            this->desiredNumberGatherers = 1;
            if (this->sn5 != -1 && this->sn5 < 1) {
                this->desiredNumberGatherers = this->sn5;
            }
            this->civilianExplorersDesired = this->civilians.numberValue - this->desiredNumberGatherers;
            if (this->sn3 != -1 && this->civilianExplorersDesired > this->sn3) {
                this->civilianExplorersDesired = this->sn3;
            }
        }
    }

    this->displayCivilianDistribution();
    this->updateGathererDistribution();
}
