// VA: 004220D0 RGE_Base_Game::send_game_options (29 B)
// PDB source: basegame.cpp:4976-4979
// Exact-finish: the standalone source and the authentic late basegame owner
// both use the public virtual ABI.  The grouped owner supplies the full
// protected virtual surface before this public slot.
// BINARY NOTE: The executable reads comms_handler at +0x18C, then publishes
// the inline 0xA8-byte options record through the direct communications call.
// Keep the null guard, pointer width, size width, call order, and fault order.
#ifndef BASEGAME_SEGMENT_CONTEXT
struct TCommunications_Handler {
    void SetMyGameOptions(char* data, int size);
};
#endif

#ifndef BASEGAME_SEGMENT_CONTEXT
class RGE_Base_Game {
public:
    char gap_04[0x188];
    TCommunications_Handler* comms_handler; // offset 0x18C
    char gap_190[0x768];
    char options_data[0xA8]; // offset 0x8F8

    virtual void send_game_options();
};
#else
// The preceding authenticated basegame owner supplies RGE_Base_Game and its
// public send_game_options virtual slot.  This view names only fields proved
// by this owner and keeps their natural widths without a second class owner.
struct RGE_Base_Game_Send_Game_Options_Overlay {
    char gap_00[0x18C];
    TCommunications_Handler* comms_handler; // offset 0x18C
    char gap_190[0x768];
    char options_data[0xA8]; // offset 0x8F8
};
#endif

void RGE_Base_Game::send_game_options()
{
#ifdef BASEGAME_SEGMENT_CONTEXT
    RGE_Base_Game_Send_Game_Options_Overlay* view =
        (RGE_Base_Game_Send_Game_Options_Overlay*)this;
    if (view->comms_handler)
        view->comms_handler->SetMyGameOptions(view->options_data, 0xA8);
#else
    if (this->comms_handler)
        this->comms_handler->SetMyGameOptions(this->options_data, 0xA8);
#endif
}
