#ifndef TACT_HNT_SHARED_CONTEXT
class TRIBE_Action_Hunt {
public:
    void parent_save(int outfile);
    void save(int outfile);
    char gap_00[0x40];
    int field_40;
};
void __cdecl rge_write(int outfile, void* data, int size);
#endif
void TRIBE_Action_Hunt::save(int outfile) {
#ifndef TACT_HNT_SHARED_CONTEXT
    this->parent_save(outfile);
#else
    this->RGE_Action::save(outfile);
#endif
#ifndef TACT_HNT_SHARED_CONTEXT
    rge_write(outfile, &this->field_40, 4);
#else
    rge_write(outfile, &this->targetType, 4);
#endif
}
