// 0040D9D0 MainDecisionAIModule::object (aimdmod.cpp:219-235, 321B)
// Searches object list for a matching object by ID, master object properties,
// action state, and object state. Grows internal int array on demand.
// FLAGS: /nologo /c /O2 /Oy

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl operator_delete(void* ptr);

#ifndef AOE1_AIMDMOD_TU_CONTEXT_H
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

struct ManagedArray_D9D0 {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int& operator[](int index) { return this->value[index]; }
};

struct MainDecisionAIModule {
    char _pad_00[0x0F0];
    RGE_Player* player;     // +0xF0
    ManagedArray_D9D0 objects; // +0xF4

    RGE_Static_Object* object(int p1, int p2, int p3, int p4, int p5, int p6);
};
#endif

RGE_Static_Object* MainDecisionAIModule::object(int p1, int p2, int p3, int p4, int p5, int p6)
{
    for (int i = 0; i < this->objects.numberValue; i++) {
        if (i > this->objects.maximumSizeValue - 1) {
            int newCount = i + 1;
            int* newArray = (int*)operator_new(i * 4 + 4);
            if (newArray) {
                int j = 0;
                if (this->objects.maximumSizeValue > 0) {
                    while (j < this->objects.maximumSizeValue && j < newCount) {
                        newArray[j] = this->objects.value[j];
                        j++;
                    }
                }
                operator_delete(this->objects.value);
                this->objects.value = newArray;
                this->objects.maximumSizeValue = newCount;
            }
        }

        RGE_Static_Object* obj = this->player->world->object(this->objects.value[i]);
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
