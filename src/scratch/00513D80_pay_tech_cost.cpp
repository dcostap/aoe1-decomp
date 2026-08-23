struct InnerObj { void method(int a, int b, int c); };
class SomeClass {
public:
    void pay_tech_cost(int tech);
    char pad[0x220];
    InnerObj* field_220;
};
void SomeClass::pay_tech_cost(int tech) {
    this->field_220->method(tech, 1, 0);
}
