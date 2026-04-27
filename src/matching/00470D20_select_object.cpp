// first pass: call select_one_object(obj,1), then optionally scan the player object list for same-type selections
// the current risk is only exact VC5 basin shape around the list walk and early returns
class RGE_Object_List;
class RGE_Object_Node;
class RGE_Static_Object;

class RGE_Player {
public:
    char pad_00[0x28];
    RGE_Object_List* objects;
    char pad_2C[0x104];
    RGE_Static_Object* selected_obj;

    int select_one_object(RGE_Static_Object* object, int select);
    int select_object(RGE_Static_Object* object);
};

class RGE_Object_Node {
public:
    RGE_Static_Object* node;
    RGE_Object_Node* next;
};

class RGE_Object_List {
public:
    void* vtable_ptr;
    RGE_Object_Node* list;
};

class RGE_Static_Object {
public:
    char pad_00[0x37];
    unsigned char selected_group;
};

int RGE_Player::select_object(RGE_Static_Object* object) {
    RGE_Player* player = this;
    RGE_Static_Object* selected = object;
    RGE_Object_Node* node;
    unsigned char group;

    if (player->select_one_object(selected, 1) == 0) {
        return 0;
    }

    group = selected->selected_group;
    if (group > 0x0A) {
        node = player->objects->list;
        while (node != 0) {
            if (node->node != selected && node->node->selected_group == group) {
                if (player->select_one_object(node->node, 0) == 0) {
                    break;
                }
            }
            node = node->next;
        }
    }

    player->selected_obj = selected;
    return 1;
}
