#ifndef AOE1_TPLAYER_H
#define AOE1_TPLAYER_H

#include "player.h"

class TRIBE_Player_Tech;

// This prefix ends at the first proved TRIBE_Player field.
// Add later fields only with their canonical owner evidence.
class TRIBE_Player : public RGE_Player {
public:
    TRIBE_Player_Tech* tech_tree; // +0x220

    void tech_abling(long, unsigned char);
    void rev_tech(long);
};

#endif
