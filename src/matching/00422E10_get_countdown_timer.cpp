class RGE_Base_Game {
public:
    char gap_0[0x9D8];
    int timers[1]; // offset 0x9D8, variable-length array

    void get_countdown_timer(int index, int* output);
};

void RGE_Base_Game::get_countdown_timer(int index, int* output)
{
    *output = this->timers[index];
}
