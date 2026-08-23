class TPanelSystem {
public:
    ~TPanelSystem();
};

extern TPanelSystem panel_system;

void E2(void) {
    panel_system.~TPanelSystem();
}
