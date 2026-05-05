// attempt 2: no intermediate TPanel base adjustment; helper on visible screen-panel base
class TScreenPanel { public: virtual ~TScreenPanel(); virtual void draw(); void delete_panel(void** p); };
class TRIBE_Screen_Status_Message : public TScreenPanel {
public:
    char gap_004[0x478-4];
    void* message;
    virtual ~TRIBE_Screen_Status_Message();
    virtual void draw();
};
TRIBE_Screen_Status_Message::~TRIBE_Screen_Status_Message() {
    this->delete_panel(&this->message);
}
