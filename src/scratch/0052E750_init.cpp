class TRIBE_World {
public:
    void target_method(int a, int b, int c);

    void init(int a, int b, int c);
};

void TRIBE_World::init(int a, int b, int c) {
    this->target_method(a, b, c);
}
