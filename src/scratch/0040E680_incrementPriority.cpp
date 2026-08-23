class SomeClass {
public:
    void setPriority(int val);
    void incrementPriority(int delta);
    char pad[0xE8];
    int priority;
};
void SomeClass::incrementPriority(int delta) {
    this->setPriority(this->priority + delta);
}
