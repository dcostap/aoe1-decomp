void rge_write(int file, void* data, int size);

class RGE_Action {
public:
    virtual void vf00(void);
    void save(int file);
};

class TRIBE_Action_Convert : public RGE_Action {
public:
    char gap_04[0x3C];
    unsigned char was_same_owner;
    char gap_41[0x03];
    int requiredRange;

    void save(int file);
};

void TRIBE_Action_Convert::save(int file) {
    RGE_Action::save(file);
    rge_write(file, &this->was_same_owner, 1);
    rge_write(file, &this->requiredRange, 4);
}
