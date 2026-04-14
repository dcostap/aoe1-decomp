class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[8];
    int numberGroups_;

    int numberGroups() const;
};

int BaseObject::numberGroups() const {
    return this->numberGroups_;
}
