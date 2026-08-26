#include "../../include/com_spd_context.h"

// TU context gate (proved): PDB module com_spd.cpp, lines 151-154, owner
// RGE_Communications_Speed, body 004328D0-004328DD.
// The PDB symbol and original EAX result prove the unsigned-int return.
// The original SkipFrames field is at +0x210. DoCycle calls this symbol at
// 0042692A. No other context fact is needed here.

unsigned int RGE_Communications_Speed::WaitingOnAcknowledgement() {
    return ++this->SkipFrames;
}
