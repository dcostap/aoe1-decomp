class RGE_Action {
protected:
    virtual void set_state(unsigned char);
public:
    char gap_04[8];
    unsigned char state;
};

void RGE_Action::set_state(unsigned char param_1) {
    this->state = param_1;
}
