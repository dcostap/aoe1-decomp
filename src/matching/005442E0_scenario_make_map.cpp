struct InnerObj { void method(int param_1, int param_2); };
class SomeClass {
public:
    void scenario_make_map(int param_1);
    char pad[0x28];
    InnerObj* field_28;
};
void SomeClass::scenario_make_map(int param_1) {
    this->field_28->method(param_1, 0);
}
