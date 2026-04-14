class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[20];
    int typeID_;

    int typeID() const;
};

int BaseObject::typeID() const {
    return this->typeID_;
}
