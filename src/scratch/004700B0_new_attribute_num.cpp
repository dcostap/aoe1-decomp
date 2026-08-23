class RGE_Player_nan {
public:
    void new_attribute_num(short attrib, float value);
    char gap_00[0x4C];
    short num_attributes;
    char gap_4E[0x02];
    float* attributes;
};

void RGE_Player_nan::new_attribute_num(short attrib, float value) {
    if (attrib < 0) return;
    if (attrib >= this->num_attributes) return;
    this->attributes[(int)attrib] = value;
}
