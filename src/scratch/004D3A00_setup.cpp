class TRIBE_Action {
public:
    void target_func(int p0);
    void setup(int p);
};

void TRIBE_Action::setup(int p) { this->target_func(p); }
