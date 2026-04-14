class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[112];
    float zSize_;

    void setZSize(float);
};

void BaseObject::setZSize(float val) {
    this->zSize_ = val;
}
