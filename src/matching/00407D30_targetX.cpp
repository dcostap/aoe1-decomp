class RGE_Action {
public:
    char gap_00[0x20];
    float target_x;

    float targetX() const;
};

float RGE_Action::targetX() const {
    return this->target_x;
}
