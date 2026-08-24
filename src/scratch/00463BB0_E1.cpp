#ifndef AOE1_PANEL_CONTEXT_H
class TPanelSystem {
public:
    TPanelSystem(void);
};
#endif

extern TPanelSystem panel_system;

void __cdecl E1(void) {
    panel_system.TPanelSystem::TPanelSystem();
}
