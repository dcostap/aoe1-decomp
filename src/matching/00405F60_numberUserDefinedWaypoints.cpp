class RGE_Moving_Object {
public:
    virtual ~RGE_Moving_Object();
    char gap_0[0x168];
    int field_16C;
    int numberUserDefinedWaypoints();
};

int RGE_Moving_Object::numberUserDefinedWaypoints() { return this->field_16C; }
