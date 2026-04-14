class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[152];
    float currentTargetZPosition_;

    float currentTargetZPosition() const;
};

float BaseObject::currentTargetZPosition() const {
    return this->currentTargetZPosition_;
}
