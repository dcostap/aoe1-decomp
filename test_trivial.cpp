struct Base {
    int x;
    Base(int a) { x = a; }
};
struct Derived : Base {
    Derived(int a) : Base(a) { }
};
Derived::Derived(int a) : Base(a) { }
