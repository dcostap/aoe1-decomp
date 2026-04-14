class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_0[0x314];
    int field_318;
    void set_background_pos(int v);
};

void TEasy_Panel::set_background_pos(int v) { this->field_318 = v; }
