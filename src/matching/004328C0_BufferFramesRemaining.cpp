class RGE_Communications_Speed {
public:
    virtual ~RGE_Communications_Speed();
    char gap_0[0x120];
    int field_124;
    int BufferFramesRemaining();
};

int RGE_Communications_Speed::BufferFramesRemaining() { return this->field_124; }
