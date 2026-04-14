class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[132];
    int currentTask_;

    int currentTask() const;
};

int BaseObject::currentTask() const {
    return this->currentTask_;
}
