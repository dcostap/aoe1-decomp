// 0050D4D0 TRIBE_Effects::do_effect
// MATCHED: use the same simple TRIBE_Effects surface and raw-value switch shape as
// matched helper 0050D550_do_tech_effect. Avoid the richer RGE_Effects ctor/dtor
// declarations and decompiler-style byte/loop temps; they push VC5 into a different
// register/save-order basin. The simple inheritance surface plus base-qualified
// `RGE_Effects::do_effect` call emits the original saved-this stack slot, record
// pointer in ESI, and `sub ecx,65; je; dec ecx; jne; push 0` dispatch.
//
// Attempts before match: previous scratch had behavior right but 83% diff due to
// this saved too early, effect pointer in the wrong register, and different save
// order. Tried direct loop pointer / do_tech helper call shapes; exact came from
// adapting the already matched 0050D550 source shape and adding the base call.

class TRIBE_Player {
public:
    void tech_abling(long tech_value, int enable);
};

class RGE_Effects {
public:
    virtual void do_effect(short param_1, TRIBE_Player* param_2);
};

class TRIBE_Effects : public RGE_Effects {
public:
    unsigned char* records;
    int record_count;

    virtual void do_effect(short param_1, TRIBE_Player* player);
};

void TRIBE_Effects::do_effect(short param_1, TRIBE_Player* player) {
    int index = param_1;
    if (index >= this->record_count) {
        return;
    }

    unsigned char* base = this->records;
    int scaled = index + index * 4;
    int recIndex = index + scaled * 2;
    unsigned char* record = base + recIndex * 4;
    if (record == 0) {
        return;
    }

    int i = 0;
    if (*(short*)(record + 0x24) > 0) {
        int offset = 0;
        do {
            unsigned char* effect = *(unsigned char**)(record + 0x28) + offset;
            unsigned int kind = *effect;
            switch (kind) {
            case 0x65:
                break;
            case 0x66:
                player->tech_abling((long)*(float*)(effect + 8), 0);
                break;
            }
            i++;
            offset += 0x0C;
        } while (i < *(short*)(record + 0x24));
    }

    RGE_Effects::do_effect(param_1, player);
}
