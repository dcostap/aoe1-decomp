struct GroupingStruct {
    int id;
    unsigned char group_type;
    unsigned char unit_type;
    char gap_06[2];
};

class AIPlayStatus {
public:
    GroupingStruct groupings[0x32];

    int addGrouping(int id, unsigned char group_type, unsigned char unit_type);
};

int AIPlayStatus::addGrouping(int id, unsigned char group_type, unsigned char unit_type) {
    int i = 0;

    while (this->groupings[i].id != -1) {
        i++;
        if (i >= 0x32) {
            return 0;
        }
    }
    this->groupings[i].id = id;
    this->groupings[i].group_type = group_type;
    this->groupings[i].unit_type = unit_type;
    return 1;
}
