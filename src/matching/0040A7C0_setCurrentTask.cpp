class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[132];
    int currentTask_;

    void setCurrentTask(int);
};

void BaseObject::setCurrentTask(int val) {
    this->currentTask_ = val;
}
