class RGE_Sound {
public:
    char gap_0[0x14];
    unsigned char field_14;
    char gap_15[7];
    int field_1C;
    void load_facets(int unused);
};

void RGE_Sound::load_facets(int unused) {
    this->field_1C = 0;
    this->field_14 = 1;
}
