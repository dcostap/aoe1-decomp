#ifndef PLAYER_GROUPED_TU
class RGE_Static_Object;
struct RGE_Object_Node;

class RGE_Object_List {
public:
    void remove_node(RGE_Static_Object* object, RGE_Object_Node* node);
};

class RGE_Game_World {
public:
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

    virtual void removeObject(RGE_Static_Object* object, int param_2, int param_3, RGE_Object_Node* node);
};

class RGE_Static_Object {
public:
    int id;
};

struct RGE_Object_Node {
public:
    RGE_Static_Object* node;
    RGE_Object_Node* next;
    RGE_Object_Node* prev;
    unsigned char centered;
    unsigned char gap_0D[3];
};
#endif

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
