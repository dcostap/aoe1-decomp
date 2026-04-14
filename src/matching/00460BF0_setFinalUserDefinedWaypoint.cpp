class RGE_Moving_Object {
public:
    virtual ~RGE_Moving_Object();
    char gap_0[0x170];
    unsigned char field_174;
    void setFinalUserDefinedWaypoint();
};

void RGE_Moving_Object::setFinalUserDefinedWaypoint() { this->field_174 = 1; }
