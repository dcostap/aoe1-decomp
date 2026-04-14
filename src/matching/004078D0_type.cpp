class RGE_Action {
public:
    short action_type;

    virtual short type();
};

short RGE_Action::type() {
    return this->action_type;
}
