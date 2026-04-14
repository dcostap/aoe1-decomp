class TMousePointer {
public:
    virtual ~TMousePointer();
    char gap_0[0x138];
    int field_13C;
    int get_game_enable();
};

int TMousePointer::get_game_enable() { return this->field_13C; }
