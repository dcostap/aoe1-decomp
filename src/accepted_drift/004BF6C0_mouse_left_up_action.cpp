// ACCEPTED_DRIFT: unused fault-preserving member load goes to eax in original and volatile ecx in rebuilt before eax is set to 1; same call, read address, return, and stack cleanup.
class TPanel {
public:
    void release_mouse(void);
};

class RGE_Base_Game {
public:
    char gap_00[0x1B0];
    volatile int field_1B0;
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Scenario_Editor_Panel_Object : public TPanel {
public:
    long mouse_left_up_action(long x, long y, int ctrl, int shift);
};

long TRIBE_Scenario_Editor_Panel_Object::mouse_left_up_action(long x, long y, int ctrl, int shift) {
    release_mouse();
    rge_base_game->field_1B0;
    return 1;
}
