class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[144];
    float currentTargetXPosition_;

    float currentTargetXPosition() const;
};

float BaseObject::currentTargetXPosition() const {
    return this->currentTargetXPosition_;
}
