#ifndef AIPBOOK_CANONICAL_TU
struct AIPlayGrouping {
    int id;
    int state;
};

class AIPlayStatus {
public:
    AIPlayGrouping groupings[0x32];
    void copyUnits(int* units, int& count);
};
#endif

void AIPlayStatus::copyUnits(int* units, int& count) {
    AIPlayStatus::GroupingStruct* grouping = this->groupings;
    int i = 0x32;

    count = 0;
    do {
        int id = grouping->id;
        if (id != -1) {
            units[count] = id;
            count = count + 1;
        }
        grouping = grouping + 1;
        i = i - 1;
    } while (i != 0);
}
