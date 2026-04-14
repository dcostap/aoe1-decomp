class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[128];
    int busy_;

    void setBusy(int);
};

void BaseObject::setBusy(int val) {
    this->busy_ = val;
}
