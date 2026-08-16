class RGE_Action_Move_To {
public:
    void parent_save(int outfile);
    void save(int outfile);
    char gap_00[0x40];
    int field_40;
};
void __cdecl rge_write(int outfile, void* data, int size);
void RGE_Action_Move_To::save(int outfile) {
    this->parent_save(outfile);
    rge_write(outfile, &this->field_40, 4);
}
