class RGE_Scenario_Header {
public:
    virtual void save(int file);
};

void rge_write_uncompressed(int file, void* data, int size);

class TRIBE_Scenario_Header : public RGE_Scenario_Header {
public:
    char gap_4[0x14 - 4];
    int field_14;
    int field_18;

    void save(int file);
};

void TRIBE_Scenario_Header::save(int file) {
    RGE_Scenario_Header::save(file);
    rge_write_uncompressed(file, &this->field_14, 4);
    rge_write_uncompressed(file, &this->field_18, 4);
}
