class TRIBE_Action_Hunt {
public:
    void parent_save(int outfile);
    void save(int outfile);
    char gap_00[0x40];
    int field_40;
};
void __cdecl rge_write(int outfile, void* data, int size);
void TRIBE_Action_Hunt::save(int outfile) {
    this->parent_save(outfile);
    rge_write(outfile, &this->field_40, 4);
}
