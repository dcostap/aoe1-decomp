class TRIBE_Credits_Screen {
public:
    virtual void vf00();
    void close();
    int key_down_action(int, int, int, int, int);
};

int TRIBE_Credits_Screen::key_down_action(int key, int b, int c, int d, int e) {
    if (key == 0xD || key == 0x1B) {
        this->close();
        return 1;
    }
    return 0;
}
