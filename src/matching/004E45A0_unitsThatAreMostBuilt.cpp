// attempt 1: two-pass max scan over the 11-entry history table with -1 carriers and a skip of the first winner
// exact match landed with the two-pass -1-carrier scan over the 11-entry table at +0xFF64

class TribeInformationAIModule {
public:
    char gap_00[0xFF64];
    int unitHistory[11];

    void unitsThatAreMostBuilt(int& out1, int& out2);
};

void TribeInformationAIModule::unitsThatAreMostBuilt(int& out1, int& out2) {
    int* history;
    int i;
    int bestValue;

    history = this->unitHistory;
    out1 = -1;
    bestValue = -1;
    for (i = 0; i < 11; i++) {
        if (bestValue == -1 || bestValue < history[i]) {
            out1 = i;
            bestValue = history[i];
        }
    }

    out2 = -1;
    bestValue = -1;
    for (i = 0; i < 11; i++) {
        if (i != out1 && (bestValue == -1 || bestValue < history[i])) {
            out2 = i;
            bestValue = history[i];
        }
    }
}
