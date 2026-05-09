// 004319E0 RGE_Communications_Queue::ExpectedNextSequence
// Default flags.
// HollowSnowdrop pass: body through the loop matches exactly; remaining mismatch was localized to final byte-mask return tail.
// MidnightLily attempts:
// - Baseline confirmed loop body exact; original tail is `or cl,0xff; pop edi; cmp cl,bl; mov ecx,[global]; sbb al,al; pop esi; not al; pop ebp; and eax,ecx`.
// - Try 1: `unsigned char c=0xff; if (c >= seq) return global; return 0;` improved tail to edit diff 9 but VC5 loads global before `or al,0xff` and uses AL, not CL.
// - Try 2/3: derive `c`/temp from `this` to encourage CL (`(unsigned char)(unsigned int)this`, byte of int temp); optimized back to AL tail.
// - Try 4/5: mask local and `register unsigned char c`; same AL/register family.
// - Try 6/7: result/local and ok-before-global forms changed not width/order (`not eax`, ECX mask) but still not original CL tail.
// - Try 8: attempted `&this` byte expression; VC5 rejects `&` on `this`, rolled back.
// - Try 9: /O1 probe wrong size/family (84 bytes), flag removed.
// Left in scratch: best source below has exact loop/body and equivalent return logic; blocker is final tail register/order selection (CL vs AL and pop/global-load order). No inline asm/hacks.

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
        unsigned char c = 0xff;
        if (c >= seq) {
            return (unsigned char)DAT_0062cf40;
        }
        return 0;
    }
}
