// 0040D9D0 MainDecisionAIModule::object (aimdmod.cpp:219-235, 321B)
// Searches object list for a matching object by ID, master object properties,
// action state, and object state. Grows internal int array on demand.
// FLAGS: /nologo /c /O2 /Oy

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl operator_delete(void* ptr);

struct RGE_Master_Static_Object {
    char _pad_00[0x10];
    short id;                 // +0x10
    short copy_id;            // +0x12
    short object_group;       // +0x14
};

struct UnitAIModule {
    int currentAction();
};

struct RGE_Static_Object {
    char _pad_00[4];           // vtable
    int id;                    // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    char _pad_0C[0x3C];       // +0x0C to +0x47
    unsigned char object_state; // +0x48

    void* unitAI();
};

struct RGE_Game_World {
    RGE_Static_Object* object(int obj_id);
};

struct RGE_Player {
    char _pad_00[0x3C];
    RGE_Game_World* world;
};

struct MainDecisionAIModule {
    char _pad_00[0x0F0];
    RGE_Player* player;     // +0xF0
    int* objects;            // +0xF4
    int number;              // +0xF8
    char _pad_FC[4];        // +0xFC
    int maxSize;             // +0x100

    RGE_Static_Object* object(int p1, int p2, int p3, int p4, int p5, int p6);
};

RGE_Static_Object* MainDecisionAIModule::object(int p1, int p2, int p3, int p4, int p5, int p6)
{
    for (int i = 0; i < number; i++) {
        if (i > maxSize - 1) {
            int newCount = i + 1;
            int* newArray = (int*)operator_new(i * 4 + 4);
            if (newArray) {
                int j = 0;
                if (maxSize > 0) {
                    while (j < maxSize && j < newCount) {
                        newArray[j] = objects[j];
                        j++;
                    }
                }
                operator_delete(objects);
                objects = newArray;
                maxSize = newCount;
            }
        }

        RGE_Static_Object* obj = player->world->object(objects[i]);
        if (!obj) goto next;
        if (!obj->unitAI()) goto next;
        if (p1 != -1 && obj->id != p1) goto next;
        if (p2 != -1 && obj->master_obj->id != p2) goto next;
        if (p3 != -1 && obj->master_obj->object_group != p3) goto next;
        if (((UnitAIModule*)obj->unitAI())->currentAction() == p4) goto next;
        if (((UnitAIModule*)obj->unitAI())->currentAction() == p5) goto next;
        if (p6 != -1 && (int)obj->object_state != p6) goto next;
        return obj;
next:;
    }
    return 0;
}
