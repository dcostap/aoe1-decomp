#include "../../include/com_hand_context.h"

// BINARY NOTE: ShowReturn owns 00424EB0-00425737. Its 00425738 jump table and
// alignment bytes are data. The next normal PDB function is Com_hand.cpp
// TCommunications_Handler::GameOver at 00425750-0042577C.
//
// Exact-finish: the first natural source used synthetic `_go` and `Flush` names.
// Replacing them with the reviewed Com_hand owner and FlushAll surface changed
// only the owner and two direct call symbols. The result is an exact 45-byte
// boundary with the original field stores, null checks, call order, and cleanup.
// Removing the member declaration does not compile; it is required for the
// qualified PDB owner. No config or assembly steering is used.
void TCommunications_Handler::GameOver(void) {
    this->current_turn = 0;
    if (this->InQ)
        this->InQ->FlushAll();
    if (this->OutQ)
        this->OutQ->FlushAll();
}
