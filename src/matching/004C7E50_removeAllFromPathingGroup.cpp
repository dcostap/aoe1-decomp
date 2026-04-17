class RGE_Player {
public:
    int computerPlayer(void);
};

class RGE_Static_Object {
public:
    char gap_00[0x0C];
    RGE_Player* owner;
    char gap_10[0x48];
    int pathingGroupMembers_numberValue;

    void removeAllFromPathingGroup(void);
};

void RGE_Static_Object::removeAllFromPathingGroup(void) {
    if (owner->computerPlayer() == 1) {
        pathingGroupMembers_numberValue = 0;
    }
}
