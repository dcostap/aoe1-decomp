// RGE_Victory_Conditions::handle_create
// VA: 00532110
// victory.cpp

struct RGE_Master_Object {
    char gap_00[0x12];
    short copy_id;           // +0x12
};

struct RGE_Static_Object {
    char gap_00[8];
    RGE_Master_Object* master_obj; // +0x08
    char gap_0C[0x3C];
    unsigned char object_state; // +0x48
};

struct RGE_Object_Node {
    RGE_Static_Object* node; // +0x00
    RGE_Object_Node* next;   // +0x04
};

struct RGE_Object_List {
    char gap_00[4];
    RGE_Object_Node* list;   // +0x04
};

class RGE_Victory_Conditions {
public:
    char gap_00[0x0C];
    void* player;             // +0x0C

    void handle_create(void* entry);
};

void RGE_Victory_Conditions::handle_create(void* entry) {
    int count = 0;

    RGE_Object_List* obj_list = *(RGE_Object_List**)((char*)(this->player) + 0x28);
    RGE_Object_Node* node = obj_list->list;
    while (node != 0) {
        if (node->node->master_obj->copy_id == *(long*)((char*)entry + 4) && 
            node->node->object_state == 2) {
            count++;
        }
        node = node->next;
    }

    if (*(unsigned char*)((char*)entry + 0x2D) && 
        *(unsigned char*)((char*)(this->player) + 0x104)) {
        void* world = *(void**)((char*)(this->player) + 0x3C);
        int num = *(short*)((char*)world + 0x3C);
        void** players = *(void***)((char*)world + 0x40);
        int my_id = *(short*)((char*)(this->player) + 0x4A);
        int i = 1;
        while (i < num) {
            if (*(unsigned char*)((char*)(this->player) + 0x84 + i) == 0 &&
                *(unsigned char*)((char*)players[i] + 0x84 + my_id) == 0 &&
                i != my_id &&
                *(unsigned char*)((char*)players[i] + 0x104)) {
                RGE_Object_List* ol = *(RGE_Object_List**)((char*)players[i] + 0x28);
                RGE_Object_Node* n = ol->list;
                while (n != 0) {
                    if (n->node->master_obj->copy_id == *(long*)((char*)entry + 4) && 
                        n->node->object_state == 2) {
                        count++;
                    }
                    n = n->next;
                }
            }
            i++;
        }
    }

    if (count >= *(long*)((char*)entry + 0x1C)) {
        *(unsigned char*)((char*)entry + 0x2E) = 2;
    } else {
        *(unsigned char*)((char*)entry + 0x2E) = 0;
    }
}
