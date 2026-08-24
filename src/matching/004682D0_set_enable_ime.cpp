#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TPanelSystem {
public:
    void EnableIME(void);
    void DisableIME(void);
};

extern TPanelSystem panel_system;

class TEasy_Panel {
public:
    char gap_00[0x78];
    void* field_78;
    char gap_7C[0x3DC];
    int enable_ime;

    void set_enable_ime(int value);
};
#endif

void TEasy_Panel::set_enable_ime(int value) {
    this->enable_ime = value;
    if (this->field_78 != 0) {
        if (value != 0) {
            panel_system.EnableIME();
            return;
        }
        panel_system.DisableIME();
    }
}
