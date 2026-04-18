class TRIBE_Master_Player {
public:
    void destroy(void);
    void *scalar_deleting_destructor(unsigned int param_1);
};

void operator_delete(void *param_1);

void *TRIBE_Master_Player::scalar_deleting_destructor(unsigned int param_1) {
    this->destroy();
    if ((param_1 & 1) != 0) {
        operator_delete(this);
    }
    return this;
}
