// tried direct value+rhs, base-pointer alias, entry-pointer alias, an explicit running-sum local, and rewrite-through-value forms; all stayed in the mem-first fld/fadd basin
// explicit [(int)attrib] restored the original movsx eax,ax, but even value-first add order still kept the mem-first fld/fadd family; the remaining gap is now isolated to that FPU operand order
class RGE_Player_aan {
public:
    void add_attribute_num(short attrib, float value, unsigned char unused);
    char gap_00[0x4C];
    short num_attributes;
    char gap_4E[0x02];
    float* attributes;
};

void RGE_Player_aan::add_attribute_num(short attrib, float value, unsigned char unused) {
    if (attrib < 0) return;
    if (attrib >= this->num_attributes) return;
    float* attr = this->attributes;
    attr[(int)attrib] += value;
}
