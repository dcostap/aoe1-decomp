class TMousePointer {
public:
    virtual ~TMousePointer();
    char gap_0[0x134];
    int field_138;
    void set_game_mode(int v);
};

void TMousePointer::set_game_mode(int v) { this->field_138 = v; }
