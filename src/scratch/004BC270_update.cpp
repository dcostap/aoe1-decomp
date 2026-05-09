// VA: 004BC270 RGE_Sound::update
// 2026-05-09 GraniteCub: tried 14 focused variants. Best basin is a `while` loop with outer
// `push ebp/push esi`, body/call/store exact after resync, and only 10 edit bytes drift. Do-while
// and nested-positive source families regressed to missing early EBP save (90 positional/32 edit).
// Tried i/offset declaration order, block scoping, positive/nested cache guards, cache local,
// goto/return shape, volatile counter, and while vs do-while. Remaining blocker in best while basin:
// VC5 saves EDI too early (before initial sound_num/cache guards) and uses `je` for cache_time==0,
// while original delays `push edi` until after the redundant second sound_num test and uses `jbe`.
// Left source in the best edit-diff basin; no inline asm/hacks.

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
    if (this->cache_time == 0) return;
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
