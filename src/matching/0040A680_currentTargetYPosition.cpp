class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[148];
    float currentTargetYPosition_;

    float currentTargetYPosition() const;
};

float BaseObject::currentTargetYPosition() const {
    return this->currentTargetYPosition_;
}
