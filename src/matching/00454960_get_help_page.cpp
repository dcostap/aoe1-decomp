class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_0[0x98];
    int field_9C;
    int get_help_page();
};

int RGE_Master_Static_Object::get_help_page() { return this->field_9C; }
