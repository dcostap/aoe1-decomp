// 005034B0 TribeTacticalAIModule::checkStaleAttackGroups
// Source: taitacmd.cpp lines 13274-13312
// Attempt log:
// - Baseline direct expression: 182 bytes; VC5 evaluated desiredUnits before
//   numberUnits, unlike the executable.
// - Function-scope number/desired locals: 184 bytes, all six direct calls in
//   order; retained as the clean period-plausible reconstruction.
// - Volatile stack-home diagnostics reached 192 bytes and restored push ecx,
//   but stored the first result before desiredUnits rather than at the observed
//   post-call site; rolled back. Named time/world and comparison variants did
//   not improve emitted code. A 24-variant lab found no exact source.
// - Paused: remaining drift is the VC5 local spill/liveness and time-expression
//   basin; no ABI/call-set or behavioral uncertainty is known.

class RGE_Game_World {
public:
    char gap_00[4];
    int world_time;
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class TribeMainDecisionAIModule {
public:
    char gap_00[0xF0];
    RGE_Player* player;
};

class TacticalAIGroup {
public:
    void* vtable_ptr;
    TacticalAIGroup* next;
    TacticalAIGroup* prev;
    char gap_0C[0x32C - 0x0C];
    unsigned long lastAddedUnitTimeValue;

    int type() const;
    int inUse() const;
    int numberUnits() const;
    int desiredNumberUnits() const;
    void setDesiredNumberUnits(int value);
};

class TribeTacticalAIModule {
public:
    char gap_000[0xF0];
    TribeMainDecisionAIModule* md;
    char gap_0F4[0x9D4 - 0x0F4];
    TacticalAIGroup groups;
    char gap_D04[0xE18 - 0xD04];
    int attackEnabledValue;

    void checkStaleAttackGroups();
};

void TribeTacticalAIModule::checkStaleAttackGroups()
{
    int number;
    int desired;

    if (this->attackEnabledValue != 0) {
        TacticalAIGroup* group = this->groups.next;
        TacticalAIGroup* sentinel = &this->groups;

        while (group != sentinel && group != 0) {
            if (group->type() == 100 && group->inUse() != 1) {
                number = group->numberUnits();
                desired = group->desiredNumberUnits();
                int difference = desired - number;
                if (difference > 0) {
                    if (difference > 5) {
                        difference = 5;
                    }
                    if (difference <=
                        (int)(this->md->player->world->world_time -
                              group->lastAddedUnitTimeValue) / 60000) {
                        group->setDesiredNumberUnits(group->numberUnits());
                    }
                }
            }
            group = group->next;
        }
    }
}
