#ifndef PLAYER_GROUPED_TU
class RGE_Static_Object;
class RGE_Object_Node;
class RGE_Object_List {
public:
    RGE_Object_Node* add_node(RGE_Static_Object* object);
};
class RGE_Game_World {
public:
    char gap_00[0x58];
    void updateObject(RGE_Static_Object* object);
};
class RGE_Player {
public:
    char gap_00[0x28];
    RGE_Object_List* objects;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
    char gap_34[0x8];
    RGE_Game_World* world;
    RGE_Object_Node* addObject(RGE_Static_Object*, int, int);
};
#endif

RGE_Object_Node* RGE_Player::addObject(RGE_Static_Object* object, int is_sleeping, int use_doppleganger) {
    RGE_Object_Node* node;

    if (is_sleeping != 0) {
        node = this->sleeping_objects->add_node(object);
    } else if (use_doppleganger != 0) {
        node = this->doppleganger_objects->add_node(object);
    } else {
        node = this->objects->add_node(object);
    }

    this->world->updateObject(object);
    return node;
}
