class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2786];
    unsigned char popLimit_;

    void setPopLimit(unsigned char);
};
void TRIBE_Game::setPopLimit(unsigned char val) { this->popLimit_ = val; }
