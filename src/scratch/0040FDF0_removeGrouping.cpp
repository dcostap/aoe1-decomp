struct GroupingStruct {
    int id;
    unsigned char group_type;
    unsigned char unit_type;
    char gap_06[2];
};

class AIPlayStatus {
public:
    GroupingStruct groupings[0x32];

    int removeGrouping(int id);
};

int AIPlayStatus::removeGrouping(int id) {
    int i = 0;

    while (this->groupings[i].id != id) {
        i++;
        if (i >= 0x32) {
            return 0;
        }
    }
    this->groupings[i].id = -1;
    this->groupings[i].group_type = 0xFF;
    this->groupings[i].unit_type = 0xFF;
    return 1;
}
