class RGE_Moving_Object {
public:
    virtual ~RGE_Moving_Object();
    char gap_0[0x134];
    int field_138;
    void setTargetID(int v);
};

void RGE_Moving_Object::setTargetID(int v) { this->field_138 = v; }
