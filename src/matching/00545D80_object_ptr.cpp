class RGE_Game_World {
public:
    void target_func(int p0);
    void object_ptr(int p);
};

void RGE_Game_World::object_ptr(int p) { this->target_func(p); }
