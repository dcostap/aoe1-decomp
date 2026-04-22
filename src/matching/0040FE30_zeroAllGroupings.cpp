struct GroupingStruct {
    int id;
    unsigned char group_type;
    unsigned char unit_type;
    char gap_06[0x02];
};

class AIPlayStatus {
public:
    GroupingStruct groupings[0x32];

    void zeroAllGroupings();
};

void AIPlayStatus::zeroAllGroupings() {
    int i;

    for (i = 0; i < 0x32; i++) {
        groupings[i].id = -1;
        groupings[i].group_type = 0xFF;
        groupings[i].unit_type = 0xFF;
    }
}
