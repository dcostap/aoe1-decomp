class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[140];
    int currentTargetType_;

    int currentTargetType() const;
};

int BaseObject::currentTargetType() const {
    return this->currentTargetType_;
}
