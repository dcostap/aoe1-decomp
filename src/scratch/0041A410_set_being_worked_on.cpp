class TRIBE_Building_Object {
public:
    void target_method(int a, int b, int c);

    void set_being_worked_on(int a, int b, int c);
};

void TRIBE_Building_Object::set_being_worked_on(int a, int b, int c) {
    this->target_method(a, b, c);
}
