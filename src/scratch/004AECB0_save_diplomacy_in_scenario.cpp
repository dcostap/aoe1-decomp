// 004AECB0 TRIBE_Screen_Sed::save_diplomacy_in_scenario (155B)
// scr_sed2.cpp:913-940
// Default flags

class TButtonPanel {
public:
    virtual ~TButtonPanel() {}
    int get_state();
};

class T_Scenario {
public:
    virtual ~T_Scenario() {}
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4();
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual unsigned char save(char*);
    void Set_player_attitude(int, int, int);
    void SetPlayerAlliedVictory(int, int);
};

struct WorldHolder {
    char gap_00[0x5C];
    T_Scenario* scenario;   // +0x5C
};

struct DiplomacyGroup {
    TButtonPanel* ally;     // +0
    TButtonPanel* neutral;  // +4
    TButtonPanel* enemy;    // +8
}; // size = 12

class TRIBE_Screen_Sed {
public:
    char gap_00[0x8A8];
    DiplomacyGroup diplomacy[8];       // +0x8A8 (96 bytes)
    TButtonPanel* allied_victory[8];   // +0x908 (32 bytes)
    WorldHolder* world;                // +0x928

    void save_diplomacy_in_scenario(int param_1);
};

void TRIBE_Screen_Sed::save_diplomacy_in_scenario(int param_1)
{
    if (param_1 < 0) return;

    for (int i = 0; i < 8; i++) {
        int st = diplomacy[i].ally->get_state();
        if (st == 1) {
            world->scenario->Set_player_attitude(param_1, i, 0);
        } else {
            st = diplomacy[i].neutral->get_state();
            if (st == 1) {
                world->scenario->Set_player_attitude(param_1, i, 1);
            } else {
                st = diplomacy[i].enemy->get_state();
                if (st == 1) {
                    world->scenario->Set_player_attitude(param_1, i, 3);
                }
            }
        }
    }

    int av = allied_victory[param_1]->get_state();
    world->scenario->SetPlayerAlliedVictory(param_1, av);
}
