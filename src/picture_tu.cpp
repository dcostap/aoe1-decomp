// Authentic Picture.cpp owner wrapper.
//
// PDB source order is 11, 25, 79, 91, 112, 126, 200, 219, 224, 246,
// and 256.  The shared context supplies one canonical TPicture layout and
// the TDrawArea/bitmap types.  Each owner remains independently compilable
// when this wrapper is not used.
//
// Exact anchors in this wrapper: 0046DDE0, 0046DFA0, 0046DFC0, 0046E020,
// 0046E0B0, 0046E2D0, 0046E370, and 0046E3E0.
// 0046E2C0 is also grouped-exact. 0046E270 keeps its accepted six-byte drift.
// 0046DE30 is standalone-exact but differs by four bytes in the full class
// context. The latter is a VC5 context blocker.
// Do not add register steering, fake volatility, or a local ABI fork.
#include "../include/picture_context.h"

#include "matching/0046DDE0_TPicture.cpp"
#include "matching/0046DE30_TPicture.cpp"
#include "matching/0046DFA0_TPicture.cpp"
#include "matching/0046DFC0_TPicture.cpp"
#include "matching/0046E020_Save.cpp"
#include "matching/0046E0B0_Load.cpp"
#include "accepted_drift/0046E270_Init.cpp"
#include "matching/0046E2C0_AlignedWidth.cpp"
#include "matching/0046E2D0_Draw.cpp"
#include "matching/0046E370_Tile.cpp"
#include "matching/0046E3E0_GetPixel.cpp"
