#ifndef BASEGAME_GROUPED_TU
class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_0[0x1AC];
    int prog_mode;
    void set_prog_mode(int v);
};
#endif

void RGE_Base_Game::set_prog_mode(int v) { this->prog_mode = v; }
