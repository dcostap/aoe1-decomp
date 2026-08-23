class SomeClass {
public:
    void setPriority(int val);
    void decrementPriority(int delta);
    char pad[0xE8];
    int priority;
};
void SomeClass::decrementPriority(int delta) {
    this->setPriority(this->priority - delta);
}
