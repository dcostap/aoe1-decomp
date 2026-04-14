class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[124];
    int maxHitPoints_;

    void setMaxHitPoints(int);
};

void BaseObject::setMaxHitPoints(int val) {
    this->maxHitPoints_ = val;
}
