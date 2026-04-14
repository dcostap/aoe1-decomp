class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_0[0x8DB4];
    unsigned char field_8DB8;
    void set_map_visible(unsigned char v);
};

void RGE_Map::set_map_visible(unsigned char v) { this->field_8DB8 = v; }
