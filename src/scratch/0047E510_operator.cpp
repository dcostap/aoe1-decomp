struct SomeStruct {
    int a, b, c;
};
class SomeClass {
public:
    SomeClass& operator_eq(const SomeClass& other);
    int a, b, c;
};
SomeClass& SomeClass::operator_eq(const SomeClass& other) {
    this->a = other.a;
    this->b = other.b;
    this->c = other.c;
    return *this;
}
