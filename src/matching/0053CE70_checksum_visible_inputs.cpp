class RGE_Visible_Map {
public:
    virtual ~RGE_Visible_Map();
    char gap_0[0x30];
    int field_34;
    int checksum_visible_inputs();
};

int RGE_Visible_Map::checksum_visible_inputs() {
    int v = this->field_34;
    this->field_34 = 0;
    return v;
}
