// VA: 0040FDF0 removeGrouping (54B)
// aipbook.cpp - AIPlayStatus::removeGrouping

struct Grouping3 {
    int id;
    unsigned char groupID;
    unsigned char type;
    char gap[2];
};

class AIPlayStatus3 {
public:
    Grouping3 groupings[50];

    int removeGrouping(int id);
};

int AIPlayStatus3::removeGrouping(int id) {
    for (int i = 0; i < 50; i++) {
        if (this->groupings[i].id == id) {
            this->groupings[i].id = -1;
            this->groupings[i].groupID = 0xFF;
            this->groupings[i].type = 0xFF;
            return 1;
        }
    }
    return 0;
}
