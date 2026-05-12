// VA: 004C79D0 RGE_Static_Object::commanderAddToGroup
// Source: stat_obj.cpp lines 4885-4923 (399 bytes, 151 asm)
// Default flags. No inline asm/hacks.

void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* ptr);

class RGE_Game_World {
public:
    class RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class RGE_Static_Object {
public:
    void* vptr;
    int id;
    char gap_08[4];
    RGE_Player* owner;
    char gap_10[0x54];
    int* group_value;       // +0x64
    int group_count;        // +0x68
    char gap_6C[4];
    int group_capacity;     // +0x70

    int addToGroup(int id, float range);
    int createGroup(int* members, int count, int commanderId, float range);
    int commanderAddToGroup(int id, float range);
};

int RGE_Static_Object::commanderAddToGroup(int id, float range)
{
    int temp[28];

    temp[0] = (int)this->owner->world->object(id);
    if (temp[0] == 0)
        return 0;

    if (this->group_count >= 25)
        return 0;

    int i = 0;
    if (this->group_count > 0) {
        int byte_off = 4;
        int base = (int)&temp[1] - byte_off;

        do {
            if (i > this->group_capacity - 1) {
                int* nv = (int*)operator new(byte_off);
                if (nv != 0) {
                    int j = 0;
                    if (this->group_capacity > 0) {
                        do {
                            if (j >= i + 1) break;
                            nv[j] = this->group_value[j];
                            ++j;
                        } while (j < this->group_capacity);
                    }
                    operator delete(this->group_value);
                    this->group_value = nv;
                    this->group_capacity = i + 1;
                }
            }

            int m = this->group_value[i];
            *(int*)(base + byte_off) = m;
            if (m == this->id)
                goto next;

            if (i > this->group_capacity - 1) {
                int* nv = (int*)operator new(byte_off);
                if (nv != 0) {
                    int j = 0;
                    if (this->group_capacity > 0) {
                        do {
                            if (j >= i + 1) break;
                            nv[j] = this->group_value[j];
                            ++j;
                        } while (j < this->group_capacity);
                    }
                    operator delete(this->group_value);
                    this->group_value = nv;
                    this->group_capacity = i + 1;
                }
            }

            {
                int m2 = this->group_value[i];
                RGE_Static_Object* obj = this->owner->world->object(m2);
                if (obj != 0) {
                    obj->addToGroup(*(volatile int*)&id, range);
                }
            }

next:
            ++i;
            byte_off += 4;
        } while (i < this->group_count);
    }

    temp[i + 1] = *(volatile int*)&id;
    this->addToGroup(*(volatile int*)&id, range);
    ((RGE_Static_Object*)temp[0])->createGroup(&temp[1], i + 1, this->id, range);
    return 1;
}
