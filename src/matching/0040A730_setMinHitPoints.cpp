class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[120];
    int minHitPoints_;

    void setMinHitPoints(int);
};

void BaseObject::setMinHitPoints(int val) {
    this->minHitPoints_ = val;
}
