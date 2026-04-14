class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[112];
    float zSize_;

    float zSize() const;
};

float BaseObject::zSize() const {
    return this->zSize_;
}
