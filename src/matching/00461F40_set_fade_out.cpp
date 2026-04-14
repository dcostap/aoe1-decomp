class TMusic_System {
public:
    char gap_0[0x264];
    int field_264;
    int field_268;
    void set_fade_out(int a, int b);
};

void TMusic_System::set_fade_out(int a, int b) {
    this->field_264 = a;
    this->field_268 = b;
}
