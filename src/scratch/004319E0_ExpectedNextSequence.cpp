// 004319E0 RGE_Communications_Queue::ExpectedNextSequence
// HollowSnowdrop pass: body through the loop now matches exactly; remaining mismatch is localized to the final byte-mask return tail. Best source below exact size 91/91, 15.38% positional / 14.29% edit. Tried ternary, explicit mask/g local, and inverted compare spellings; they change register/order but do not hit original `or cl,0xff; pop edi; cmp cl,bl; mov ecx,[global]; sbb al,al; pop esi; not al; pop ebp; and eax,ecx` tail.

extern int DAT_0062cf40;

class MsgQueueEntry {
public:
    unsigned long unk0;
    unsigned long ExecTurn;
    unsigned long unk8;
    unsigned long unkC;
    unsigned long From;
    unsigned long Size;
    unsigned long unk18;
};

class RGE_Communications_Queue {
public:
    unsigned int QueueDepth;
    unsigned int HighQueueDepth;
    char gap_08[0x114 - 0x08];
    MsgQueueEntry* Queue;

    unsigned char ExpectedNextSequence(unsigned long turn, unsigned int from);
};

unsigned char RGE_Communications_Queue::ExpectedNextSequence(unsigned long turn, unsigned int from) {
    unsigned char seq;
    unsigned int i;
    unsigned int off;

    seq = 1;
    i = 0;
    *(unsigned char*)&DAT_0062cf40 = seq;
    off = 0;
    do {
        MsgQueueEntry* e = (MsgQueueEntry*)((char*)this->Queue + off);
        if (e->ExecTurn == turn && e->From == from && e->Size != 0) {
            seq++;
            *(unsigned char*)&DAT_0062cf40 = seq;
        }
        i++;
        off += 0x1C;
    } while (i <= this->HighQueueDepth);

    {
        unsigned char c;
        c = 0xff;
        return (unsigned char)(DAT_0062cf40 & (unsigned char)-(c >= seq));
    }
}
