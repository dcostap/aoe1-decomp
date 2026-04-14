class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[4496];
    int randomStartValue_;

    int randomStartValue() const;
};
int TRIBE_Game::randomStartValue() const { return this->randomStartValue_; }
