class Pnl_ScenarioCreate {
public:
    void mouseDownHelper();
    int handle_mouse_down(int a, int b, int c, int d, int e);
};

int Pnl_ScenarioCreate::handle_mouse_down(int a, int b, int c, int d, int e) {
    this->mouseDownHelper();
    return 1;
}
