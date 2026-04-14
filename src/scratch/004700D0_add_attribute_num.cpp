class RGE_Player_aan {
public:
    void add_attribute_num(short attrib, float value, int unused);
    char gap_00[0x4C];
    short num_attributes;
    char gap_4E[0x02];
    float* attributes;
};

void RGE_Player_aan::add_attribute_num(short attrib, float value, int unused) {
    if (attrib < 0) return;
    if (attrib >= this->num_attributes) return;
    this->attributes[(int)attrib] += value;
}
