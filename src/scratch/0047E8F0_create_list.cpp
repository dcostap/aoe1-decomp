#ifndef RDLG_LST_TU_CONTEXT
class SomeClass {
public:
    int other_method();
    int create_list();
    char pad[0x4AC];
    int field_4AC;
};
#endif
#ifdef RDLG_LST_TU_CONTEXT
int RGE_Dialog_List::create_list() {
    if (this->list_type - 1)
        return 0;
    return this->create_object_list();
}
#else
int SomeClass::create_list() {
    if (this->field_4AC - 1) return 0;
    return this->other_method();
}
#endif
