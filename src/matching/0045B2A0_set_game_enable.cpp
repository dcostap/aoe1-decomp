class TMousePointer {
public:
    virtual ~TMousePointer();
    char gap_0[0x138];
    int field_13C;
    void set_game_enable(int v);
};

void TMousePointer::set_game_enable(int v) { this->field_13C = v; }
