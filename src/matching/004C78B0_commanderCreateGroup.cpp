// VA: 004C78B0 | RGE_Static_Object::commanderCreateGroup(int*,int,int,float) | stat_obj.cpp:4841-4863 | 111 bytes
//
// Attempt log:
// [1] First attempt.

#include "../../include/game_types.h"

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    char _gap_00[0x3C];
    RGE_Game_World* world; // +0x3C
};

class RGE_Static_Object {
public:
    char _gap_00[0x0C];
    RGE_Player* owner;           // +0x0C

    int commanderCreateGroup(int* list, int count, int param3, float param4);
    int createGroup(int* list, int count, int param3, float param4); // at 004C77B0
};

int RGE_Static_Object::commanderCreateGroup(int* list, int count, int param3, float param4) {
    if (list == 0 || count == 0) {
        return 0;
    }

    if (count > 0) {
        int* p = list;
        int r = count;
        do {
            int id = *p;
            RGE_Static_Object* obj = owner->world->object(id);
            if (obj != 0) {
                obj->createGroup(list, count, param3, param4);
            }
            p++;
            r--;
        } while (r != 0);
    }

    return 1;
}
