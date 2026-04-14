struct Inner_0052BA80 {
    void update();
};

class T_Scenario {
public:
    char gap_0[0x4];
    Inner_0052BA80 *ptr_;
    void update();
};

void T_Scenario::update() {
    this->ptr_->update();
}
