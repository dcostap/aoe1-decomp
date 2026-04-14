class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[136];
    int currentTarget_;

    void setCurrentTarget(int);
};

void BaseObject::setCurrentTarget(int val) {
    this->currentTarget_ = val;
}
