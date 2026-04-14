class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[104];
    float xSize_;

    void setXSize(float);
};

void BaseObject::setXSize(float val) {
    this->xSize_ = val;
}
