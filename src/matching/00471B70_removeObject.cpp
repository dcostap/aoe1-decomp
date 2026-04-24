class RGE_Static_Object;
class RGE_Object_Node;

class RGE_Object_List {
public:
    void remove_node(RGE_Static_Object* object, RGE_Object_Node* node);
};

class RGE_Game_World {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    virtual void vfDC();
    virtual void vfE0();
    virtual void vfE4();
    virtual void vfE8();
    virtual void vfEC();
    virtual void vfF0();
    virtual void vfF4();
    virtual void vfF8();
    virtual int removeObject(int id);
};

class RGE_Player {
public:
    char pad_00[0x28];
    RGE_Object_List* objects;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
    char pad_34[0x8];
    RGE_Game_World* world;
    char pad_3C[0xF4];
    short id;

    void removeObject(RGE_Static_Object* object, int param_2, int param_3, RGE_Object_Node* node);
};

class RGE_Static_Object {
public:
    void* vtable_ptr;
    int id;
};

class RGE_Object_Node {
public:
    char pad_00[0x10];
};

void RGE_Player::removeObject(RGE_Static_Object* object, int param_2, int param_3, RGE_Object_Node* node) {
    if (param_2 != 0) {
        this->sleeping_objects->remove_node(object, node);
    } else if (param_3 != 0) {
        this->doppleganger_objects->remove_node(object, node);
    } else {
        this->objects->remove_node(object, node);
    }

    this->world->removeObject(object->id);
}
