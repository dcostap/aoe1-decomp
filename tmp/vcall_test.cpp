class Foo {
public:
    virtual int bar(int x);
    int test() { return bar(42); }
};
int Foo::bar(int x) { return x + 1; }
