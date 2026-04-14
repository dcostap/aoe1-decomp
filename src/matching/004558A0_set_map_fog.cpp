class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_0[0x8DB5];
    unsigned char field_8DB9;
    void set_map_fog(unsigned char v);
};

void RGE_Map::set_map_fog(unsigned char v) { this->field_8DB9 = v; }
