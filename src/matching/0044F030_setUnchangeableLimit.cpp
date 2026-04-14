class TShape_Header_Info {
public:
    char gap_0[0x24];
    unsigned char unchangeableLimit;
    void setUnchangeableLimit(unsigned char val);
};

void TShape_Header_Info::setUnchangeableLimit(unsigned char val) {
    if (val > 0)
        this->unchangeableLimit = val;
}
