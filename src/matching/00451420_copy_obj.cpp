class RGE_Master_Doppleganger_Object {
public:
    void target_func(int p0);
    void copy_obj(int p);
};

void RGE_Master_Doppleganger_Object::copy_obj(int p) { this->target_func(p); }
