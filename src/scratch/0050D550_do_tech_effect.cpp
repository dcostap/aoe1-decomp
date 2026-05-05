// VA: 0050D550 TRIBE_Effects::do_tech_effect
// left in scratch: rebuilt now matches prolog/index/record setup and main loop topology much better,
// but remaining drift is small condition/codegen around effect kind and zero enable arg. Original uses
// 32-bit `sub ecx,65; je skip; dec ecx; jne skip; push 0`; VC5 either emits an extra `test ecx,ecx`
// after dec and reuses ECX for `push ecx`, or byte-register ops if kind is unsigned char.

class TRIBE_Player {
public:
    void tech_abling(long tech_value, int enable);
};

class TRIBE_Effects {
public:
    void* vtable;
    unsigned char* records;

    void do_tech_effect(short tech_id, TRIBE_Player* player);
};

void TRIBE_Effects::do_tech_effect(short tech_id, TRIBE_Player* player) {
    int index = tech_id;
    unsigned char* base = this->records;
    int scaled = index + index * 4;
    int recIndex = index + scaled * 2;
    unsigned char* record = base + recIndex * 4;
    int i = 0;

    if (*(short*)(record + 0x24) > 0) {
        int offset = 0;
        do {
            unsigned char* effect = *(unsigned char**)(record + 0x28) + offset;
            unsigned int kind = *effect;
            kind -= 0x65;
            if (kind == 0) {
            } else {
                kind--;
                if (kind == 0) {
                    player->tech_abling((long)*(float*)(effect + 8), 0);
                }
            }
            i++;
            offset += 0x0C;
        } while (i < *(short*)(record + 0x24));
    }
}
