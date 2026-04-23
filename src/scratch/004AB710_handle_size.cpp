class TPanel {
public:
    long handle_size(long width, long height);
};

class TRIBE_Screen_Sed : public TPanel {
public:
    void position_panels(void);
    virtual long handle_size(long width, long height);
};

long TRIBE_Screen_Sed::handle_size(long width, long height) {
    TPanel::handle_size(width, height);
    this->position_panels();
    TPanel::handle_size(width, height);
    return 0;
}
