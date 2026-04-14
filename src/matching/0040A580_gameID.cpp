class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[0x18];
    int gameID_;

    const int & gameID() const;
};

const int & BaseObject::gameID() const {
    return this->gameID_;
}
