// attempt 1: base draft, size 80 (1 byte short of 81)
// attempt 2: manual vtable cast, compile error
// attempt 3: natural C++ vcall through owner->method(), still 80
// attempt 4: use this->pManager inside loop (no mgr local), still 80
// attempt 5: fix checks (>= 4, >= 0), still 80
// attempt 6: separate if/goto checks, still 80
// left in scratch: 1 byte size drift, behavior correct, source basin not found

class TRIBE_Resource_Manager {
public:
    char gap_00[0x88];

    void give_resources(short amount, int type, int unknown);
};

class TRIBE_Building_Object {
public:
    void* _vftable;
    char gap_04[0x4];
    TRIBE_Resource_Manager* pManager;
    TRIBE_Resource_Manager* owner;

    virtual void give_building_attribute_to_owner();
};

void TRIBE_Building_Object::give_building_attribute_to_owner() {
    int i = 0;
    int bp = 0x6A;
    int sp = 0x70;
    do {
        TRIBE_Resource_Manager* mgr = pManager;
        if (*(unsigned char*)(i + (int)mgr + 0x88) >= 4 && *(short*)(bp + (int)mgr) >= 0) {
            owner->give_resources(*(short*)(bp + (int)mgr), *(int*)(sp + (int)mgr), 0);
        }
        sp += 4;
        i++;
        bp += 2;
    } while (sp < 0x7C);
}
