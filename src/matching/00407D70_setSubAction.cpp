class RGE_Action {
public:
    virtual ~RGE_Action();
    char gap_04[0x38];
    unsigned char subActionValue;

    void setSubAction(unsigned char);
};

void RGE_Action::setSubAction(unsigned char param_1) {
    this->subActionValue = param_1;
}
