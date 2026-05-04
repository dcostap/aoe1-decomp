// test for SEH
class Foo {
public:
    void bar() {}
    virtual ~Foo() {}
};

void test_func() {
    Foo* f = new Foo();
    delete f;
}
