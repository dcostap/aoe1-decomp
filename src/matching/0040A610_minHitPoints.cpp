class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[120];
    int minHitPoints_;

    int minHitPoints() const;
};

int BaseObject::minHitPoints() const {
    return this->minHitPoints_;
}
