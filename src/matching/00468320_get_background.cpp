class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_0[0x200];
    int field_204;
    int get_background();
};

int TEasy_Panel::get_background() { return this->field_204; }
