class TRIBE_Tree_Object {
public:
    void target_func(int p0);
    void set_object_state(int p);
};

void TRIBE_Tree_Object::set_object_state(int p) { this->target_func(p); }
