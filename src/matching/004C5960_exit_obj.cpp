class RGE_Object_Node;

class RGE_Object_List {
public:
    void remove_node(void* object, RGE_Object_Node* node);
};

class RGE_Static_Object {
public:
    char gap_04[0x1C];
    RGE_Static_Object* inside_obj;
    RGE_Object_List* objects;

    virtual void exit_obj(void);
};

void RGE_Static_Object::exit_obj(void) {
    if (inside_obj != 0) {
        inside_obj->objects->remove_node(this, 0);
        inside_obj = 0;
    }
}
