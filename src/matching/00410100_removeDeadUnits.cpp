#ifndef AIPBOOK_CANONICAL_TU
class RGE_Static_Object {
public:
    char gap_00[0x48];
    unsigned char object_state;
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
    void removeDeadUnits(int, RGE_Game_World* world);
};
#endif

void AIPlayStatus::removeDeadUnits(int, RGE_Game_World* world) {
    GroupingStruct* g = &this->groupings[0];
    for (int i = 0; i < 50; i++, g++) {
        if (g->id != -1) {
            RGE_Static_Object* obj = world->object(g->id);
            if (obj == 0 || obj->object_state > 2) {
                g->id = -1;
                g->groupID = 0xFF;
                g->type = 0xFF;
            }
        }
    }
}
