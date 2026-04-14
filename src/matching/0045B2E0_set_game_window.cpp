class TMousePointer {
public:
    char gap_0[0x10C];
    int field_10C;
    int field_110;
    int field_114;
    int field_118;
    void set_game_window(int a, int b, int c, int d);
};

void TMousePointer::set_game_window(int a, int b, int c, int d) {
    this->field_10C = a;
    this->field_110 = b;
    this->field_114 = c;
    this->field_118 = d;
}
