class RGE_Sound {
public:
    virtual ~RGE_Sound();
    char gap_0[0x4];
    int field_8;
    void set_cache_time(int v);
};

void RGE_Sound::set_cache_time(int v) { this->field_8 = v; }
