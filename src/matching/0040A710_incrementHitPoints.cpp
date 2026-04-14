class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[116];
    int hitPoints_;

    void incrementHitPoints(int);
};

void BaseObject::incrementHitPoints(int val) {
    this->hitPoints_ += val;
}
