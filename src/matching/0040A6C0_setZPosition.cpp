class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[100];
    float zPosition_;

    void setZPosition(float);
};

void BaseObject::setZPosition(float val) {
    this->zPosition_ = val;
}
