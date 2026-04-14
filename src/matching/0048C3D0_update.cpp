struct Inner_C3D0 {
    void update();
};

class TComm_System {
public:
    char gap_0[4];
    Inner_C3D0 *ptr;
    void update();
};

void TComm_System::update() {
    if (this->ptr)
        this->ptr->update();
}
