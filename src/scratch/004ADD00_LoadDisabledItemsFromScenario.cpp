// 004ADD00 TRIBE_Screen_Sed::LoadDisabledItemsFromScenario
// STATUS: parked - 7 bytes remaining (8.97%)
//
// Remaining diff: all ESI↔EDI register swap between loop counter (i) and
// button pointer. Original: ESI=i, EDI=ptr. Rebuilt: ESI=ptr, EDI=i.
// Everything else is byte-identical.
//
// Tried: variable type (int/unsigned/short), declaration order,
// initialization order (comma operator, separate statements),
// loop structure (for/do-while), variable naming (i/idx/loop).
// All produce same ESI↔EDI swap — pure VC5 register allocation heuristic
// difference between original TU and isolated scratch TU.

class T_Scenario {
public:
    char gap_00[0x4BF4];
    int DisabledTechnology[16][20];

    int GetDisabledTechnology(int player, int index);
};

class TRIBE_World {
public:
    char gap_00[0x5C];
    T_Scenario* scenario;
};

class TPanel {
public:
};

class TButtonPanel {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual void vf4C(void);
    virtual void vf50(void);
    virtual void vf54(void);
    virtual void vf58(void);
    virtual void vf5C(void);
    virtual void vf60(void);
    virtual void vf64(void);
    virtual void vf68(void);
    virtual void vf6C(void);
    virtual void vf70(void);
    virtual void vf74(void);
    virtual void vf78(void);
    virtual void vf7C(void);
    virtual void vf80(void);
    virtual void vf84(void);
    virtual void vf88(void);
    virtual void vf8C(void);
    virtual void vf90(void);
    virtual void vf94(void);
    virtual void vf98(void);
    virtual void vf9C(void);
    virtual void vfA0(void);
    virtual void vfA4(void);
    virtual void vfA8(void);
    virtual void vfAC(void);
    virtual void vfB0(void);
    virtual void vfB4(void);
    virtual void vfB8(void);
    virtual void vfBC(void);
    virtual void vfC0(void);
    virtual void vfC4(void);
    virtual void vfC8(void);
    virtual void vfCC(void);
    virtual void vfD0(void);
    virtual void vfD4(void);
    virtual void vfD8(void);
    virtual void vfDC(void);
    virtual void set_disabled(int disabled);
};

class TScreenPanel {
public:
    char gap_00[0x478];
};

class TRIBE_Screen_Sed : public TScreenPanel {
public:
    char gap_478[0x40];
    short player_num;
    char gap_4BA[0x31A];
    TButtonPanel* options_disable_button[16];
    char gap_814[0x114];
    TRIBE_World* world;

    void LoadDisabledItemsFromScenario(void);
};

void TRIBE_Screen_Sed::LoadDisabledItemsFromScenario(void) {
    TButtonPanel** button;
    int i;

    for (i = 0, button = this->options_disable_button; i < 16; i++, button++) {
        if (this->world->scenario->GetDisabledTechnology(this->player_num - 1, i) != 0) {
            (*button)->set_disabled(0);
        }
        else {
            (*button)->set_disabled(1);
        }
    }
}
