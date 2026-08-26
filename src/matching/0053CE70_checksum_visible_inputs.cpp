// The checksum state is the final RGE_Visible_Map member at +0x34.
#ifndef AOE1_VISIBLE_TU_CONTEXT_H
class RGE_Visible_Map {
public:
    virtual ~RGE_Visible_Map();
    char gap_0[0x30];
    unsigned long input_csum;
    unsigned long checksum_visible_inputs();
};
#endif

unsigned long RGE_Visible_Map::checksum_visible_inputs() {
    unsigned long v = this->input_csum;
    this->input_csum = 0;
    return v;
}
