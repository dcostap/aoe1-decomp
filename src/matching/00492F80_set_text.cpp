class TTextPanel {
public:
    virtual void set_text(char* text);
};

class TScrollTextPanel : public TTextPanel {
public:
    char gap_04[0x184];
    int scroll;
    int last_time;
    char gap_190[0x04];
    int done;

    void set_text(char* text);
};

void TScrollTextPanel::set_text(char* text) {
    TTextPanel::set_text(text);
    this->last_time = 0;
    this->scroll = 0;
    this->done = 0;
}
