// 00449E20 RGE_Flic_Player::start
// natural flic header offsets: buffer +0, type +0x0c, speed +0x18, oframe1 +0x5c, oframe2 +0x60.
// HollowSnowdrop pass: fixed layout and switch/sub gate; baseline exact size 88/88, 71.6% positional / 27.3% edit. Remaining drift was register/order in af12 and af11 blocks.
// 2026-05-09 GraniteCub: tried 20 focused source variants: direct/member/compound af12 sums, chained assignments,
// tmp/base/off local declaration orders, long/register/volatile temps, af11 store and speed-calc orderings, int-pointer tmp,
// direct expression stores, and if/else dispatch. Best edit basin is current source: af12 register order and af11 block match,
// but VC5 inserts `mov eax,edx` before the two af12 stores and stores oframe2 from eax, adding 2 bytes and shifting the rest.
// 2026-05-10 pass: retried char*/int/uint/long oframe fields, packed FlicHead surface, raw pointer stores,
// pointer aliases, duplicate expressions, compound assignment forms, local/self/volatile self shapes, if/else dispatch,
// switch default/tail variants, and narrow flags (/O1, /Og, /Ob0, /Ox, /Gf, /Gy, /Oy-). No exact; best remains
// default /O2 with only the af12 copy/scheduling drift (edit diff 7.9545%, positional 73.8636%).
// ACCEPTED_DRIFT review denied by Boss: although the AF12 register copy is equivalent in isolation, the extra 2 bytes
// push the final `mov [ecx+60],edx; ret` past the 88-byte function window, so the tail disassembles incomplete (`8951`)
// and original final `60 c3` bytes are missing inside the compared function. Leave in scratch.
// Blocker: need original af12 `mov eax,[ecx]; mov edx,[ecx+5c]; add edx,eax; mov [ecx+5c],edx; mov [ecx+60],edx`
// without the extra result copy; no inline asm/hacks used.

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
    case 0xAF12: {
        this->oframe1 = this->flic_buffer + (long)this->oframe1;
        this->oframe2 = this->oframe1;
        return;
    }
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
