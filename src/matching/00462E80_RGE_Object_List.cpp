#ifndef OBJLIST_SHARED_CONTEXT
class RGE_Game_World;
class RGE_Object_Node;

class RGE_Object_List {
public:
    virtual void load(unsigned char, int, RGE_Game_World*);
    RGE_Object_Node* list;
    short number_of_objects;

    RGE_Object_List();
};
#endif

RGE_Object_List::RGE_Object_List() {
    list = 0;
    number_of_objects = 0;
}
