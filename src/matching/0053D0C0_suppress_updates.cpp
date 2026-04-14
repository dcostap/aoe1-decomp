extern int g_suppress_updates;

class SomeClass {
public:
    void suppress_updates(int val);
};

void SomeClass::suppress_updates(int val) {
    g_suppress_updates = val;
}
