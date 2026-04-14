class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[124];
    int maxHitPoints_;

    int maxHitPoints() const;
};

int BaseObject::maxHitPoints() const {
    return this->maxHitPoints_;
}
