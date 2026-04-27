// VA: 0041A350 RGE_Animated_Object::update
// ani_obj.cpp lines 79-125

// attempt 2: add dummy virtuals to match vtable slot positions

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual unsigned char update();
};

class RGE_Game_Area {
public:
    virtual ~RGE_Game_Area();
    virtual void vf01();
    virtual void update_pos(int a, int b);        // slot 2 (0x08)
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual unsigned char check_collision(void* arg);  // slot 6 (0x18)
};

// Fields at observed offsets:
// +0x08: RGE_Master_Static_Object*
// +0x0C: RGE_Game_World*
// +0x10: some arg/param
// +0x18: RGE_Game_Area*
// +0x48: byte state (3, 4, 5)
// +0x88: dword speed

// RGE_Static_Object has slots 0, 1 (~RGE_Static_Object, update)
// Need total 24 virtuals (0-23) for kill at slot 23
// Adding 22 dummy virtuals (slots 2-22) + kill at slot 23

class RGE_Animated_Object : public RGE_Static_Object {
public:
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void kill(int mode);  // slot 23 (0x5C)

    unsigned char update();
};

// 0041A350 - 119 bytes
unsigned char RGE_Animated_Object::update() {
    unsigned char result = RGE_Static_Object::update();

    unsigned char* state_ptr = (unsigned char*)this + 0x48;
    unsigned char state = *state_ptr;

    switch (state) {
    case 3: {
        void* master = *(void**)((char*)this + 8);
        if (*(void**)((char*)master + 0x1C) == 0) {
            this->kill(5);
        } else {
            this->kill(4);
        }
        break;
    }
    case 4: {
        RGE_Game_Area* area = *(RGE_Game_Area**)((char*)this + 0x18);
        void* field_10 = *(void**)((char*)this + 0x10);
        unsigned char ret = area->check_collision(field_10);
        if (ret == 0) {
            *state_ptr = 5;
            *(int*)((char*)this + 0x88) = 0;
        }
        break;
    }
    }

    int speed = *(int*)((char*)this + 0x88);
    RGE_Game_Area* area = *(RGE_Game_Area**)((char*)this + 0x18);
    void* obj0C = *(void**)((char*)this + 0x0C);
    void* field_3C = *(void**)((char*)obj0C + 0x3C);
    int param = *(int*)((char*)field_3C + 0x84);
    area->update_pos(param, speed);

    return result;
}
