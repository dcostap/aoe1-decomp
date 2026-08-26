#ifndef AOE1_PANEL_CONTEXT_H
class TPanelSystem {
public:
    TPanelSystem(void);
};
#endif

extern TPanelSystem panel_system;

// PDB owner: Panel.cpp initializer named $E1.
void $E1(void) {
    panel_system.TPanelSystem::TPanelSystem();
}
