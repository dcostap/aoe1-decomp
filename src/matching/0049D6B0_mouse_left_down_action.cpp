class Pnl_ScenarioObjectives {
public:
    void leftDownHelper();
    int mouse_left_down_action(int a, int b, int c, int d);
};

int Pnl_ScenarioObjectives::mouse_left_down_action(int a, int b, int c, int d) {
    this->leftDownHelper();
    return 0;
}
