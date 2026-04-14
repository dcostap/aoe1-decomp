class RGE_Scenario {
public:
    void target_func(int p0, int p1);
    void Set_description(int p);
};

void RGE_Scenario::Set_description(int p) { this->target_func(p, 0); }
