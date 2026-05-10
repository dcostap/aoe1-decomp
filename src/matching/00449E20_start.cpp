// 00449E20 RGE_Flic_Player::start
// natural flic header offsets: buffer +0, type +0x0c, speed +0x18, oframe1 +0x5c, oframe2 +0x60.
// MATCHED: keep AF12 as a normal case that updates oframe1 and breaks/falls into the shared tail assignment
// `oframe2 = oframe1`, rather than returning immediately after an explicit second store. This lets VC5 store
// oframe1 from EDX and then naturally reuse EDX for the shared tail store, avoiding the extra `mov eax,edx`
// copy that previously shifted the function past the 88-byte window.
// Prior attempts: direct/member/compound AF12 sums, chained assignments, tmp/base/off local declaration orders,
// char*/int/uint/long oframe fields, packed FlicHead surface, raw pointer stores, pointer aliases, duplicate
// expressions, local/self/volatile self shapes, if/else dispatch, switch default/tail variants, and narrow flags.

class RGE_Flic_Player {
public:
    char* flic_buffer;
    char gap_04[0x0C - 0x04];
    unsigned short type;
    char gap_0E[0x18 - 0x0E];
    int speed;
    char gap_1C[0x5C - 0x1C];
    char* oframe1;
    char* oframe2;

    void start();
};

void RGE_Flic_Player::start() {
    switch (this->type) {
    case 0xAF12:
        this->oframe1 += (long)this->flic_buffer;
        break;
    case 0xAF11: {
        int s = this->speed;
        char* tmp = this->flic_buffer + 0x84;
        s = s * 5;
        this->oframe1 = tmp;
        s = s * 5;
        s = s * 5;
        this->speed = (s * 8) / 70;
        break;
    }
    }
    this->oframe2 = this->oframe1;
}
