class RGE_Command {
public:
    virtual ~RGE_Command();
    char gap_0[0x10];
    int field_14;
    void reset_communications(int v);
};

void RGE_Command::reset_communications(int v) { this->field_14 = v; }
