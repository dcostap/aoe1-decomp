// attempt 2: correct RGE_Effect layout and the natural destructor loop over effect_list pointers
// blocker: logic is understood, but VC5 is still in the wrong prolog/live-range basin; exact vptr-store + loop register order remain the lead
#include "..\..\include\game_types.h"

extern "C" void free(void* p);

class RGE_Effect_Command;

class RGE_Effect {
public:
    short id;
    char name[31];
    unsigned char _pad_0[1];
    short string_table_id;
    short effect_list_num;
    unsigned char _pad_1[2];
    RGE_Effect_Command* effect_list;
};

class RGE_Effects {
public:
    void* vtable_ptr;
    RGE_Effect* effects;
    long effect_num;

    virtual ~RGE_Effects();
};

RGE_Effects::~RGE_Effects() {
    long i;

    this->vtable_ptr = (void*)0x570430;
    if (this->effect_num > 0) {
        for (i = 0; i < this->effect_num; i++) {
            if (this->effects[i].effect_list != 0) {
                free(this->effects[i].effect_list);
            }
            this->effects[i].effect_list = 0;
        }
    }
    if (this->effects != 0) {
        free(this->effects);
        this->effects = 0;
    }
    this->effect_num = 0;
}
