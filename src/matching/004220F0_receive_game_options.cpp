// VA: 004220F0 RGE_Base_Game::receive_game_options (57 B)
// PDB source: basegame.cpp:4985-4996
// PDB owner: public virtual ?receive_game_options@RGE_Base_Game@@UAEXXZ
// The preceding late basegame owner ends at 004220ED.  This owner starts at
// 004220F0 and ends at 00422128; the bytes at 00422129-0042212F are padding.
// BINARY NOTE: The executable accepts only a non-null communications handler,
// a non-null options record, and an exact 0xA8-byte record size.  Keep the
// zeroed size home, call order, direct publication call, and fault order.
// Exact-finish: the byte-exact baseline used a raw vtable field and emitted
// the nonvirtual QAEXXZ owner.  A real public virtual owner emits the PDB
// UAEXXZ symbol with the same body.  The late owner context uses one narrow
// +0x18C overlay; its grouped body also remains 57 bytes with the canonical
// GetMyGameOptions and RGE_Game_Options setter targets.  The typed setter is
// required for the original direct-call relocation, even though a void* form
// keeps the same instruction bytes after relocation masking.
// Walkback: the virtual owner is required for the PDB ABI.  The overlay and
// context-only declarations are required only for the grouped late-TU audit;
// standalone exactness is unchanged.  No dummy owner, raw vtable, or assembly
// remains.

#ifndef BASEGAME_SEGMENT_CONTEXT
class TCommunications_Handler {
public:
    void* GetMyGameOptions(unsigned long* size);
};
#endif

#ifndef BASEGAME_SEGMENT_CONTEXT
class RGE_Base_Game {
public:
    struct RGE_Game_Options;
    virtual void receive_game_options(void);
    char gap_04[0x188];
    TCommunications_Handler* comm_handler;

    void set_game_options(RGE_Game_Options* options);
};
#else
// The preceding authenticated basegame owner supplies RGE_Base_Game and its
// public virtual receive_game_options slot.  This view names only the field
// proved by this method and keeps the canonical owner ABI for the setter.
struct RGE_Base_Game_Receive_Game_Options_Overlay {
    char gap_00[0x18C];
    TCommunications_Handler* comm_handler;
};
#endif

void RGE_Base_Game::receive_game_options(void) {
#ifdef BASEGAME_SEGMENT_CONTEXT
    RGE_Base_Game_Receive_Game_Options_Overlay* view =
        (RGE_Base_Game_Receive_Game_Options_Overlay*)this;
    if (view->comm_handler != 0) {
        unsigned long size = 0;
        void* options = view->comm_handler->GetMyGameOptions(&size);
        if (options != 0 && size == 0xA8) {
            this->set_game_options((RGE_Game_Options*)options);
        }
    }
#else
    if (this->comm_handler != 0) {
        unsigned long size = 0;
        void* options = this->comm_handler->GetMyGameOptions(&size);
        if (options != 0 && size == 0xA8) {
            this->set_game_options((RGE_Game_Options*)options);
        }
    }
#endif
}
