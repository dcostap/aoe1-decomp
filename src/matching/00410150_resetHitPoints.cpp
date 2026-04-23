class RGE_Static_Object {
public:
    char gap_00[0x30];
    float hitPointsValue;
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

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
    void setOriginalHitPoints(int param_1, int param_2);
    void resetHitPoints(int param_1, RGE_Game_World* world);
};

void AIPlayStatus::resetHitPoints(int param_1, RGE_Game_World* world) {
    int total = 0;
    AIPlayStatus* p = this;
    int count = 50;

    do {
        int id = p->groupings[0].id;
        if (id != -1) {
            if (p->groupings[0].groupID == param_1) {
                RGE_Static_Object* obj = world->object(id);
                if (obj != 0) {
                    total += (int)obj->hitPointsValue;
                }
            }
        }
        p = (AIPlayStatus*)(p->groupings + 1);
        count--;
    } while (count != 0);

    setOriginalHitPoints(param_1, total);
}
