#ifndef AOE1_TAIMDMD_CONTEXT_H
class RGE_Victory_Conditions {
public:
    int get_victory_points(void);
};

struct DecisionScoreEntry {
    char gap_00[0x34];
    RGE_Victory_Conditions* victory;
};

struct DecisionScoreTable {
    char gap_00[0x3C];
    short count;
    char gap_3E[0x02];
    DecisionScoreEntry** entries;
};

struct DecisionModuleInfo {
    char gap_00[0x3C];
    DecisionScoreTable* table;
};

class TribeMainDecisionAIModule {
public:
    char gap_00[0xF0];
    DecisionModuleInfo* info;

    int currentScore(int index);
};
#endif

int TribeMainDecisionAIModule::currentScore(int index) {
    if (index >= 1) {
        DecisionScoreTable* table = this->info->table;
        if (index <= table->count) {
            return table->entries[index]->victory->get_victory_points();
        }
    }
    return -1;
}
