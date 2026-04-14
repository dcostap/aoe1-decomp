class RGE_Static_Object {
public:
    char gap_00[0x68];
    int groupMembersNumber;
    char gap_6C[0x0C];
    int groupCommanderValue;

    int destroyGroup();
};

int RGE_Static_Object::destroyGroup() {
    groupMembersNumber = 0;
    groupCommanderValue = -1;
    return 1;
}
