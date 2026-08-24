#ifndef ACT_GATH_CONTEXT_H
class RGE_Action {
public:
    virtual void save(int outfile);
};

class RGE_Action_Gather : public RGE_Action {
public:
    void save(int outfile);

    char gap_04[0x3C];
    int field_40;
};

void __cdecl rge_write(int outfile, void* data, int size);
#endif

void RGE_Action_Gather::save(int outfile) {
    RGE_Action::save(outfile);
    rge_write(outfile, &this->field_40, 4);
}
