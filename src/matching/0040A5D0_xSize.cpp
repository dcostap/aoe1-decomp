class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[104];
    float xSize_;

    float xSize() const;
};

float BaseObject::xSize() const {
    return this->xSize_;
}
