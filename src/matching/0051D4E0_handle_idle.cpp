class Pnl_Scenario {
public:
    void processIdle();
    int handle_idle();
};

int Pnl_Scenario::handle_idle() {
    this->processIdle();
    return 0;
}
