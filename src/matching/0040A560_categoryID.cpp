class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[16];
    int categoryID_;

    int categoryID() const;
};

int BaseObject::categoryID() const {
    return this->categoryID_;
}
