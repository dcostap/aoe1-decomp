class RGE_Action {
public:
    char gap_00[0x3C];
    unsigned char subActionValue;

    unsigned char subAction() const;
};

unsigned char RGE_Action::subAction() const {
    return this->subActionValue;
}
