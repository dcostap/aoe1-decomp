// VA: 0040FDB0 addGrouping (54B)
// aipbook.cpp - AIPlayStatus::addGrouping

#ifndef AIPBOOK_CANONICAL_TU
struct Grouping {
    int id;
    unsigned char groupID;
    unsigned char type;
    char gap[2];
};

class AIPlayStatus {
public:
    Grouping groupings[50];  // starts at offset 0

    int addGrouping(int id, unsigned char GroupID, unsigned char type);
};
#endif

int AIPlayStatus::addGrouping(int id, unsigned char GroupID, unsigned char type) {
    for (int i = 0; i < 50; i++) {
        if (this->groupings[i].id == -1) {
            this->groupings[i].id = id;
            this->groupings[i].groupID = GroupID;
            this->groupings[i].type = type;
            return 1;
        }
    }
    return 0;
}
