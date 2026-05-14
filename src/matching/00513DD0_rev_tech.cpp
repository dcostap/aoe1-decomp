// VA: 00513DD0, TRIBE_Player::rev_tech, 453 bytes
// Source: tplayer.cpp lines 1505-1549
// Attempt log:
// - v1: natural switch on long param with cases 1, 0x17, 0x18, 0x19 from packet/decompiler.
// - v2: local TRIBE_Player layout: object at +0x50 with float tech ids at +0x5c/+0x60/+0x64, tech_tree at +0x220.
// - v3: direct member calls to TRIBE_Player_Tech disable/rev_tech/enable/do_tech, using (short)(long)float casts for __ftol.

struct TechIdSource {
    char gap_00[0x5c];
    float tech_a; // +5c
    float tech_b; // +60
    float tech_c; // +64
};

class TRIBE_Player_Tech {
public:
    void do_tech(short tech_id);
    unsigned char rev_tech(short tech_id);
    void disable(short tech_id);
    void enable(short tech_id);
};

class TRIBE_Player {
public:
    char gap_00[0x50];
    TechIdSource* source;             // +50
    char gap_54[0x1cc];
    TRIBE_Player_Tech* tech_tree;     // +220

    void rev_tech(long param_1);
};

void TRIBE_Player::rev_tech(long param_1)
{
    switch (param_1) {
    case 0x19:
        this->tech_tree->do_tech((short)(long)this->source->tech_c);
        return;

    case 0x17:
        this->tech_tree->disable((short)(long)this->source->tech_a);
        this->tech_tree->rev_tech((short)(long)this->source->tech_c);
        this->tech_tree->enable((short)(long)this->source->tech_a);
        this->tech_tree->do_tech((short)(long)this->source->tech_a);
        return;

    case 0x18:
        this->tech_tree->disable((short)(long)this->source->tech_a);
        this->tech_tree->disable((short)(long)this->source->tech_b);
        this->tech_tree->rev_tech((short)(long)this->source->tech_c);
        this->tech_tree->enable((short)(long)this->source->tech_a);
        this->tech_tree->rev_tech((short)(long)this->source->tech_a);
        this->tech_tree->enable((short)(long)this->source->tech_b);
        this->tech_tree->do_tech((short)(long)this->source->tech_b);
        return;

    case 1:
        this->tech_tree->disable((short)(long)this->source->tech_a);
        this->tech_tree->disable((short)(long)this->source->tech_b);
        this->tech_tree->rev_tech((short)(long)this->source->tech_c);
        this->tech_tree->enable((short)(long)this->source->tech_a);
        this->tech_tree->rev_tech((short)(long)this->source->tech_a);
        this->tech_tree->enable((short)(long)this->source->tech_b);
        this->tech_tree->rev_tech((short)(long)this->source->tech_b);
        return;

    default:
        return;
    }
}
