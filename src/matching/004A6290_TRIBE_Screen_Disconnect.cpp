// attempt 8: natural member delete_panel call on derived screen panel
class TScreenPanel { public: virtual ~TScreenPanel(); virtual void update(); void delete_panel(void** p); };
class TRIBE_Screen_Disconnect : public TScreenPanel {
public:
    char gap_004[0x47C-4];
    void* message;
    virtual ~TRIBE_Screen_Disconnect();
    virtual void update();
};
TRIBE_Screen_Disconnect::~TRIBE_Screen_Disconnect() {
    this->delete_panel(&this->message);
}
