class TMousePointer {
public:
    char gap_00[0x138];
    int game_mode;
    int game_enabled;

    int in_game_mode();
};

int TMousePointer::in_game_mode() {
    if (this->game_mode && this->game_enabled) {
        return 1;
    }
    return 0;
}
