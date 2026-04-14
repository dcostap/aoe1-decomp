class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[100];
    float zPosition_;

    float zPosition() const;
};

float BaseObject::zPosition() const {
    return this->zPosition_;
}
