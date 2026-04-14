class RGE_Master_Doppleganger_Object {
public:
    void target_func(int p0);
    void save(int p);
};

void RGE_Master_Doppleganger_Object::save(int p) { this->target_func(p); }
