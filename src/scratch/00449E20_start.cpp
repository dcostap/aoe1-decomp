// 00449E20 RGE_Flic_Player::start
// natural flic header offsets: buffer +0, type +0x0c, speed +0x18, oframe1 +0x5c, oframe2 +0x60.
// HollowSnowdrop pass: fixed layout and switch/sub gate; current exact size 88/88, 71.6% positional / 27.3% edit. Remaining drift is register/order: af12 block uses EAX for oframe1 and EDX for buffer instead of original EAX=buffer/EDX=oframe1; af11 block loads/stores buffer before speed while original loads speed, computes EDX=buffer+0x84, stores oframe1 after first lea. Tried source ordering/local splits; same basin.

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
        char* base;
        char* tmp;
        base = this->flic_buffer;
        tmp = this->oframe1;
        tmp = tmp + (long)base;
        this->oframe1 = tmp;
        this->oframe2 = tmp;
        return;
    }
    case 0xAF11: {
        int s;
        char* tmp;
        s = this->speed;
        s = s * 5;
        tmp = this->flic_buffer;
        tmp += 0x84;
        this->oframe1 = tmp;
        s = s * 5;
        s = s * 5;
        this->speed = (s * 8) / 70;
        break;
    }
    }
    this->oframe2 = this->oframe1;
}
