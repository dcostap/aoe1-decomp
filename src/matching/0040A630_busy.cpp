class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[128];
    int busy_;

    int busy() const;
};

int BaseObject::busy() const {
    return this->busy_;
}
