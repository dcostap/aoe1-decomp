void rge_write(int file, void* data, int size);

class RGE_Action {
public:
    virtual void vf00(void);
    void save(int file);
};

class TRIBE_Action_Trade : public RGE_Action {
public:
    char gap_04[0x3C];
    float pick_up_x;
    float pick_up_y;

    void save(int file);
};

void TRIBE_Action_Trade::save(int file) {
    RGE_Action::save(file);
    rge_write(file, &this->pick_up_x, 4);
    rge_write(file, &this->pick_up_y, 4);
}
