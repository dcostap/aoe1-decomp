// tried while-loop, do-while, infinite-loop-with-return-node, and break-then-return-node forms; all stayed in the same close basin
// current source has the right loads/compare/return values; remaining mismatch is only the null-path / loop-back lexical shape around 00463301
// leaving this in scratch because the difference is localized to control-flow layout, not behavior or field offsets
struct GroupInfo {
    char gap_00[0x14];
    short group;
};

struct ObjectDetails {
    char gap_00[0x08];
    GroupInfo* info;
};

class RGE_Static_Object;

#ifndef OBJLIST_SHARED_CONTEXT
struct RGE_Object_Node {
    void* object;
    RGE_Object_Node* next;
    RGE_Object_Node* prev;
};

class RGE_Object_List {
public:
    char gap_00[4];
    RGE_Object_Node* list;

    void* find_by_group(long group);
};
#endif

RGE_Static_Object* RGE_Object_List::find_by_group(long group) {
    RGE_Object_Node* node = this->list;
    if (node == 0) return 0;
    
    while (node != 0) {
        if (node->object != 0) {
            if (((ObjectDetails*)node->object)->info->group == group) {
                return (RGE_Static_Object*)node->object;
            }
        }
        node = node->next;
    }
    return 0;
}
