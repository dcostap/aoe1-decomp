class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[120];
    int minHitPoints_;

    void decrementMinHitPoints(int);
};

void BaseObject::decrementMinHitPoints(int val) {
    this->minHitPoints_ -= val;
}
