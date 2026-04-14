class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[96];
    float yPosition_;

    void setYPosition(float);
};

void BaseObject::setYPosition(float val) {
    this->yPosition_ = val;
}
