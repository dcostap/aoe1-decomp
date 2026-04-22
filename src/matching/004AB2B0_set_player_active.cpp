class RGE_Scenario {
public:
    void Set_player_Active(int player, int active);
};

class ScreenWorld {
public:
    char gap_00[0x5C];
    RGE_Scenario* scenario;
};

class TRIBE_Screen_Sed {
public:
    char gap_00[0x928];
    ScreenWorld* world;

    void set_player_active(short player, int active);
};

void TRIBE_Screen_Sed::set_player_active(short player, int active) {
    this->world->scenario->Set_player_Active((int)player, active);
}
