class TechnologyItem {
public:
    ~TechnologyItem();
    void *scalar_deleting_destructor(unsigned int param_1);
};

void operator_delete(void *param_1);

void *TechnologyItem::scalar_deleting_destructor(unsigned int param_1) {
    this->~TechnologyItem();
    if ((param_1 & 1) != 0) {
        operator_delete(this);
    }
    return this;
}
