class TRIBE_Game {
public:
    char gap_0[0xA24];
    int field_A24;
    int field_A28;
    int field_A2C;
    int field_A30;
    void SetClickTables(int a, int b, int c, int d);
};

void TRIBE_Game::SetClickTables(int a, int b, int c, int d) {
    this->field_A24 = a;
    this->field_A28 = b;
    this->field_A2C = c;
    this->field_A30 = d;
}
