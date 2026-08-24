#ifndef T_B_OBJ_CONTEXT_H
class TRIBE_Building_Object {
public:
    void method_a();
    void method_b();
    void cancel_object();
    char pad[0x48];
    unsigned char field_48;
};
#endif
void TRIBE_Building_Object::cancel_object() {
    if (this->field_48 < 2) {
        this->method_a();
    } else {
        this->method_b();
    }
}
