// VA: 0049D6E0 TRIBE_Screen_Info::close_screen
// scr_info.cpp lines 118-189

// attempt 1: minimal first pass — understood structure but too large for quick match
// 112/1628 bytes (6.8%) with minimal skeleton, /GX
// Would need all 8 strcmp branches with full ctor/registration calls
// Left in scratch: TU exhausted after meaningful first pass.

class TPanel {
public:
    virtual ~TPanel();
};

class TRIBE_Screen_Info : public TPanel {
public:
    void close_screen();
};

void TRIBE_Screen_Info::close_screen() {
    // Structure:
    // 1. Load [this+0x1C] → screen identifier string
    // 2. 8 inline byte-by-byte string comparisons against constants:
    //    "R", "q.", "g.", "f.", "t.", "s.", "n.", "m.", and more
    // 3. Each matching branch:
    //    a. rge_base_game->disable_input() (most branches)
    //    b. operator_new(size) — 0x49C, 0x484, or 0x4B0
    //    c. If non-null: call ctor (0x0049D550 or other)
    //    d. push_screen(0, string) on global at 0x62E870 (call 00463E60h)
    //    e. add_screen_name(string) on same global (call 00464060h)
    //    f. Return through EH cleanup
    // 4. Special branch "f.": checks is_network_game → shuffle_players
    // 5. Special branch "R": different ctor pattern
    // 
    // EH framed with handler at 0x55EFA3, 5 register saves (ebx,ebp,esi,edi)

    // clang-format off
    // String constants from the binary (at various 0x586xxx addresses):
    // "58664Ch" = "R" 
    // "58662Ch" = "q."
    // "586620h" = "g."
    // "586608h" = "f."
    // "5865F4h" = "t."
    // "5865DCh" = "s."
    // "5865C4h" = "n."
    // "5865ACh" = "m." or "A"
    // "58659Ch" = some other
    // clang-format on
}
