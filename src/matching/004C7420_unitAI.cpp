class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_0[0x70];
    int field_74;
    int unitAI();
};

int RGE_Static_Object::unitAI() { return this->field_74; }
