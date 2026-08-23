// ACCEPTED_DRIFT: unused fault-preserving member load goes to eax in original and volatile ecx in rebuilt before eax is set to 1; same call, read address, return, and stack cleanup.
// Attempt log:
// - Baseline is exact in size, call set, boundary, and cleanup. It differs only in the load destination byte.
// - Virtual TPanel/RGE context restored the PDB owner and field offset but kept the ECX load destination.
// - An exact probe used a volatile local object pointer with the complete class context. It was rejected as fake volatility.
// - Restored this clean source. Needed evidence: a policy-compliant source form that keeps the proven unused read in EAX.
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
