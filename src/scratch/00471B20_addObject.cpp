// tried the direct list-selection order from the asm; first mismatch moved to the world dispatch
// tried a world local and then a direct vtable-pointer call; mismatch stayed at the world load/register basin
class RGE_Static_Object;
class RGE_Object_Node;

class RGE_Object_List {
public:
    RGE_Object_Node* add_node(RGE_Static_Object* object);
};

typedef void (*RGE_Game_World_UpdateObject)(class RGE_Game_World* this_, RGE_Static_Object* object);

class RGE_Game_World {
public:
    void** vtable_ptr;
};

class RGE_Player {
public:
    char gap_00[0x28];
    RGE_Object_List* objects;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
    char gap_34[0x8];
    RGE_Game_World* world;

    RGE_Object_Node* addObject(RGE_Static_Object* object, int is_sleeping, int use_doppleganger);
};

RGE_Object_Node* RGE_Player::addObject(RGE_Static_Object* object, int is_sleeping, int use_doppleganger) {
    RGE_Object_Node* node;

    if (is_sleeping != 0) {
        node = this->sleeping_objects->add_node(object);
    } else {
        if (use_doppleganger != 0) {
            node = this->doppleganger_objects->add_node(object);
        } else {
            node = this->objects->add_node(object);
        }
    }

    RGE_Game_World* world = this->world;
    ((RGE_Game_World_UpdateObject)world->vtable_ptr[0x3E])(world, object);
    return node;
}
