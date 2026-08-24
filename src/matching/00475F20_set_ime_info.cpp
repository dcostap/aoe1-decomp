#ifndef PNL_EDIT_TU_CONTEXT
class TEditPanel {
public:
    char gap_0[0x164];
    int field_164;
    int field_168;
    void set_ime_info(int a, int b);
};
#endif

void TEditPanel::set_ime_info(int a, int b) {
#ifndef PNL_EDIT_TU_CONTEXT
    this->field_164 = a;
    this->field_168 = b;
#else
    this->enable_ime = a;
    this->turn_ime_on = b;
#endif
}
