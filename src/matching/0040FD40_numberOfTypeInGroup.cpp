#ifndef AIPBOOK_CANONICAL_TU
class AIPlayStatus {
public:
    class GroupingStruct {
    public:
        int id;
        unsigned char groupID;
        unsigned char type;
        unsigned char pad[2];
    };

    GroupingStruct groupings[50];
    unsigned char numberOfTypeInGroup(int param_1, int param_2);
};
#endif

unsigned char AIPlayStatus::numberOfTypeInGroup(int param_1, int param_2) {
    unsigned char count = 0;
    for (int i = 0; i < 50; i++) {
        const GroupingStruct& g = this->groupings[i];
        if ((g.id != -1) && (g.groupID == param_1) && (g.type == param_2)) {
            count++;
        }
    }
    return count;
}
