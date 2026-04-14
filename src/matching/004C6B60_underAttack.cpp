class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_0[0x82];
    unsigned char field_86;
    unsigned char underAttack();
};

unsigned char RGE_Static_Object::underAttack() { return this->field_86; }
