class TDrawSystem {
public:
    void ModifyPalette(int, int, void*);
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;

    void SetPalette(void* palette);
};

void TDrawArea::SetPalette(void* palette) {
    ((unsigned char*)palette)[0] = 0;
    ((unsigned char*)palette)[1] = 0;
    ((unsigned char*)palette)[2] = 0;
    ((unsigned char*)palette)[3] = 0;
    ((unsigned char*)palette)[0x3FC] = 0xFF;
    ((unsigned char*)palette)[0x3FD] = 0xFF;
    ((unsigned char*)palette)[0x3FE] = 0xFF;
    ((unsigned char*)palette)[0x3FF] = 0;
    this->DrawSystem->ModifyPalette(0, 0x100, palette);
}
