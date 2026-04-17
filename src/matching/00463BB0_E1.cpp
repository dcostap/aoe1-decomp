class TPanelSystem {
public:
    TPanelSystem(void);
};

extern TPanelSystem panel_system;

void __cdecl E1(void) {
    panel_system.TPanelSystem::TPanelSystem();
}
