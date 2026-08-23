#ifndef ACT_MOVE_CANONICAL_TU
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
#endif
void __cdecl rge_write(int outfile, void* data, int size);
void RGE_Action_Move_To::save(int outfile) {
    RGE_Action::save(outfile);
#ifdef ACT_MOVE_CANONICAL_TU
    rge_write(outfile, &this->range, 4);
#else
    rge_write(outfile, &this->field_40, 4);
#endif
}
