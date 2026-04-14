class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[108];
    float ySize_;

    float ySize() const;
};

float BaseObject::ySize() const {
    return this->ySize_;
}
