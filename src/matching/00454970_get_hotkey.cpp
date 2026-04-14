class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_0[0x9C];
    int field_A0;
    int get_hotkey();
};

int RGE_Master_Static_Object::get_hotkey() { return this->field_A0; }
