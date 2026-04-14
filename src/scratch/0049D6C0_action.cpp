class TRIBE_Screen_Info {
public:
    void target_method(int a, int b, int c, int d);

    void action(int a, int b, int c, int d);
};

void TRIBE_Screen_Info::action(int a, int b, int c, int d) {
    this->target_method(a, b, c, d);
}
