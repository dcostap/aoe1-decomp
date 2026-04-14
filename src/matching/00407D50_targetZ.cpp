class RGE_Action {
public:
    char gap_00[0x28];
    float target_z;

    float targetZ() const;
};

float RGE_Action::targetZ() const {
    return this->target_z;
}
