class RGE_Action {
public:
    char gap_00[0x24];
    float target_y;

    float targetY() const;
};

float RGE_Action::targetY() const {
    return this->target_y;
}
