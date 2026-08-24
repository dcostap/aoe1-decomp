// attempt 3: natural destructor with helper on screen-panel base and exact field offsets
#ifndef SCR_MPS_TU_CONTEXT
class TScreenPanel { public: virtual ~TScreenPanel(); void delete_panel(void** p); };
class TRIBE_Screen_Wait : public TScreenPanel {
public:
    char gap_004[0x478-4];
    void* message;
    char gap_47C[4];
    void* close_button;
    void* scenarioName;
    void* settingText[20];
    virtual ~TRIBE_Screen_Wait();
};
#endif
TRIBE_Screen_Wait::~TRIBE_Screen_Wait() {
    this->delete_panel(&this->message);
    this->delete_panel(&this->close_button);
    this->delete_panel(&this->scenarioName);
    for (int i = 0; i < 20; ++i) {
        this->delete_panel(&this->settingText[i]);
    }
}
