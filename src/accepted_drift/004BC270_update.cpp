// VA: 004BC270 RGE_Sound::update
// 2026-05-09 GraniteCub: tried 14 focused variants. Best basin is a `while` loop with outer
// `push ebp/push esi`, body/call/store exact after resync, and only 10 edit bytes drift. Do-while
// and nested-positive source families regressed to missing early EBP save (90 positional/32 edit).
// Tried i/offset declaration order, block scoping, positive/nested cache guards, cache local,
// goto/return shape, volatile counter, and while vs do-while.
// LemonLily pass: tried 16 more source variants: cache_time <=0 spelling, nested positive guards,
// block-scoped/late/uninitialized/for-loop/do-while offset forms, now local, direct sound_num reload,
// offset initialized from i/count/cache/param/conditional/label/if, and volatile-zero offset. Also
// probed /O2 no-/Oy, /Ot, /Og, /Ox, /Oa, /Ow, /O1. Best source below improves to 9 edit bytes by
// recovering original `jbe` cache guard, but VC5 still saves/xors EDI before the initial guards;
// original delays `push edi`/`xor edi` until after the redundant second sound_num test. /Oa and /O1
// emit too-short text; /Ow regresses; other flags stay in the same basin. Possible accepted_drift
// candidate for review: the loop body/call/store and predicates are exact after resync; remaining
// ACCEPTED_DRIFT: reviewed by Boss. The meaningful loop body/call/store and predicates are exact
// after resync. Remaining drift is EDI save/zero initialization hoisted before early-exit guards,
// with corresponding branch-displacement and pop-placement shifts. Since EDI is callee-saved, the
// early push/pop preserves caller state on all exits; memory effects, calls, returns, and tail bytes match.

class TDigital {
public:
    void unload(void);
};

class RGE_Sound_Info {
public:
    char name[13];
    char pad_0[0x3];
    long resource_id;
    short percent;
    char pad_1[0x2];
    TDigital* digital_sound;
    unsigned char loaded;
    char pad_2[0x3];
    unsigned long time;
};

class RGE_Sound {
public:
    short play_at_update_count;
    short sound_num;
    RGE_Sound_Info* sounds;
    unsigned long cache_time;
    short id;

    void update(unsigned long now);
};

void RGE_Sound::update(unsigned long now) {
    short count = this->sound_num;
    if (count <= 0) return;
    if (this->cache_time <= 0) return;
    int i = 0;
    if (count <= 0) return;
    int offset = 0;
    while (i < this->sound_num) {
        RGE_Sound_Info* entry = (RGE_Sound_Info*)((char*)this->sounds + offset);
        if (entry->loaded == 1 && (now - entry->time) > this->cache_time) {
            entry->digital_sound->unload();
            ((RGE_Sound_Info*)((char*)this->sounds + offset))->loaded = 2;
        }
        ++i;
        offset += 0x24;
    }
}
