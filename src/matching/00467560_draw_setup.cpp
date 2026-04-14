class TEasy_Panel {
public:
    void target_func(int p0);
    void draw_setup(int p);
};

void TEasy_Panel::draw_setup(int p) { this->target_func(p); }
