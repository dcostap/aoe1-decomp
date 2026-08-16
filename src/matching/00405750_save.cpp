class RGE_Action {
public:
    virtual void save(int outfile);
};

class RGE_Action_Move_To : public RGE_Action {
public:
    void save(int outfile);
    char gap_04[0x3C];
    int field_40;
};
void __cdecl rge_write(int outfile, void* data, int size);
void RGE_Action_Move_To::save(int outfile) {
    RGE_Action::save(outfile);
    rge_write(outfile, &this->field_40, 4);
}
