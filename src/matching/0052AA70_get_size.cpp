class TRIBE_Game {
public:
    int baseGetSize();
    int get_size();
};

int TRIBE_Game::get_size() {
    return this->baseGetSize() + 8;
}
