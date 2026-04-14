class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_0[0x94];
    int field_98;
    int get_help_message();
};

int RGE_Master_Static_Object::get_help_message() { return this->field_98; }
