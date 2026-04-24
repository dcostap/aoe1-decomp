// attempt 1: class layout wrong (speed at +0x10, oframe1 at +0x50, oframe2 at +0x54)
// attempt 2: class layout wrong (oframe1 at +0x58, oframe2 at +0x5C)
// attempt 3: offsets correct now but code shape totally different
// Left in scratch after 3 attempts
// Remaining: VC5 generates imul for speed*1000/70, original uses lea eax,[eax+eax*4] x3 chain
// Also: VC5 uses cmp/sub differently, store order differs, compare gate uses cmp vs sub pattern
// Behavioral logic is correct but codegen basin not found

class RGE_Flic_Player {
public:
    char gap_00[0x4];
    void* flic_buffer;
    char gap_08[0x4];
    unsigned short flichead_type;
    char gap_0E[0x2];
    char gap_10[0x8];
    int flichead_speed;
    char gap_1C[0x40];
    void* oframe1;
    void* oframe2;

    void start();
};

void RGE_Flic_Player::start() {
    if (flichead_type == 0xAF11) {
        long speed = flichead_speed;
        long tmp = (long)flic_buffer + 0x84;
        speed *= 3;
        speed *= 3;
        long s3 = speed * 3;
        long s4 = s3 * 8;
        s4 *= 0xEA0EA0EB;
        s4 += (long)tmp;
        s4 >>= 6;
        s4 += s4 >> 31;
        flichead_speed = (int)s4;
        oframe1 = (void*)tmp;
    } else if (flichead_type == 0xAF12) {
        oframe1 = (void*)((long)oframe1 + (long)flic_buffer);
        oframe2 = oframe1;
        return;
    }
    oframe2 = oframe1;
}
