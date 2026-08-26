#ifndef AOE1_VISIBLE_TU_CONTEXT_H
class RGE_Visible_Map {
public:
    virtual ~RGE_Visible_Map();
    char gap_0[0x30];
    int field_34;
    unsigned long checksum_visible_inputs();
};
#endif

unsigned long RGE_Visible_Map::checksum_visible_inputs() {
    unsigned long v = this->field_34;
    this->field_34 = 0;
    return v;
}
