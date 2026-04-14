class RGE_Moving_Object {
public:
    virtual ~RGE_Moving_Object();
    char gap_0[0x151];
    unsigned char field_155;
    void setWaitingToMove(unsigned char v);
};

void RGE_Moving_Object::setWaitingToMove(unsigned char v) { this->field_155 = v; }
