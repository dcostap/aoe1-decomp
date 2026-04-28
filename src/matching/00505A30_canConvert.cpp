class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    short id;             // +0x10
    short copy_id;        // +0x12
    short object_group;   // +0x14
};

class RGE_Static_Object {
public:
    char gap_00[0x04];
    long id;              // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class UnitAIModule {
public:
    void* some_ptr;           // +0x04 (vtable at +0x00 is implicit)
    virtual int canConvert(int id);
};

class TribePriestUnitAIModule : public UnitAIModule {
public:
    int canConvert(int id);
};

int TribePriestUnitAIModule::canConvert(int id) {
    char* base = (char*)this->some_ptr;

    if (*(float*)(base + 0x44) >= 100.0f) {
        RGE_Static_Object* obj = (*(RGE_Game_World**)(*(char**)(base + 0x0C) + 0x3C))->object(id);
        if (obj) {
            int og = obj->master_obj->object_group;
            short sid = obj->master_obj->id;

            if (sid == 0x6D) return 0;
            if (og == 0x1B) return 0;
            if (sid == 0x9F) return 0;
            if (sid == 0x114) return 0;
            if (sid == 0x9E) return 0;
            if (sid == 0xA3) return 0;
            if (og == 0x1E) return 0;

            if (og == 0x12 && *(float*)(*(char**)(*(char**)((char*)this->some_ptr + 0x0C) + 0x50) + 0x6C) <= 0.0f) return 0;
            if (og == 3 && *(float*)(*(char**)(*(char**)((char*)this->some_ptr + 0x0C) + 0x50) + 0x70) <= 0.0f) return 0;

            return 1;
        }
    }
    return 0;
}

RGE_Static_Object* RGE_Game_World::object(int id) { return 0; }
