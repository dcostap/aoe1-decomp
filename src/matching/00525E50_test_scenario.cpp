// 00525E50 test_scenario (134 bytes) — MATCHED
// PDB: tribegam.cpp (TRIBE_Game::test_scenario)
// First attempt.

#include <string.h>

#ifndef TRIBEGAM_TU_CONTEXT
class TPanelSystem {
public:
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

class TRIBE_Game {
public:
    virtual void _virt0();
    virtual void _virt1();
    virtual void _virt2();
    virtual void setup(int param_1);

    char pad_AE4[0xAE4];  // vtable(4) + pad(0xAE4) = 0xAE8
    char testing_scenario[256];  // at +0xAE8

    int start_scenario(char* scenario);
    int start_scenario_editor(char* scenario, int param_2);
    int start_menu();
    void close();

    int test_scenario(char* name);
};
#endif

int TRIBE_Game::test_scenario(char* name)
{
    strcpy(this->testing_scenario, name);
    panel_system.destroyPanel("Scenario Editor Screen");
    this->setup(0);

    if (this->start_scenario(this->testing_scenario))
        return 1;

    if (this->start_scenario_editor(this->testing_scenario, 0))
        return 0;

    if (this->start_menu())
        return 0;

    this->close();
    return 0;
}
