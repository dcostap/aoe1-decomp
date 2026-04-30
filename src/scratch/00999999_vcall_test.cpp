struct Foo {
    virtual int bar(int x);
    int test() { return bar(42); }
};
int Foo::bar(int x) { return x + 1; }
int call_test() {
    Foo f;
    return f.test();
}
