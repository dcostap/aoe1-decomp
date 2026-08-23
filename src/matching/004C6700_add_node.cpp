#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Static_Object;

struct RGE_Check_Node {
    RGE_Static_Object* node;
    float dx;
    float dy;
    unsigned char flag;
    char gap_0D[3];
    RGE_Check_Node* next;
};

class RGE_Check_List {
public:
    RGE_Check_Node* list;

    void add_node(RGE_Static_Object* object, float dx, float dy, unsigned char flag);
};

extern "C" void* __cdecl calloc(unsigned int num, unsigned int size);

#endif

void RGE_Check_List::add_node(RGE_Static_Object* object, float dx, float dy, unsigned char flag) {
    RGE_Check_Node* node = (RGE_Check_Node*)calloc(1, 0x14);
    node->next = this->list;
    node->node = object;
    node->dx = dx;
    node->dy = dy;
    node->flag = flag;
    this->list = node;
}
