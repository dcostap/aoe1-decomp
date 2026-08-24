// 00512EC0 TRIBE_Player::find_obj
// PDB source: tplayer.cpp lines 871-901

#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class RGE_Static_Object {
public:
    char gap_00[8];
    void* master_obj;       // +0x08, id at +0x10
    char gap_0C[0x48 - 0x0C];
    unsigned char object_state; // +0x48
};

struct ObjNode {
    RGE_Static_Object* obj;
    ObjNode* next;
};

struct ObjList {
    int unused;
    ObjNode* head;
};

class TRIBE_Player {
public:
    char gap_00[0x28];
    ObjList* objects;

    RGE_Static_Object* find_obj(short id, RGE_Static_Object* after);
};
#endif

RGE_Static_Object* TRIBE_Player::find_obj(short id, RGE_Static_Object* after)
{
    if (after != 0) {
        int found = 0;
        ObjNode* node = this->objects->head;
        while (node != 0) {
            RGE_Static_Object* obj = node->obj;
            if (obj != 0) {
                if (found) {
                    void* master = obj->master_obj;
                    if (*(short*)((char*)master + 0x10) == id && obj->object_state <= 2)
                        return node->obj;
                } else if (obj == after) {
                    found = 1;
                }
            }
            node = node->next;
        }
    }

    ObjNode* node = this->objects->head;
    while (node != 0) {
        RGE_Static_Object* obj = node->obj;
        if (obj != 0) {
            void* master = obj->master_obj;
            if (*(short*)((char*)master + 0x10) == id && *(unsigned char*)((char*)obj + 0x48) == 2)
                return node->obj;
        }
        node = node->next;
    }
    return 0;
}
