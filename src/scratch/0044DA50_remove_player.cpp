// first pass: direct bounds check, delete-or-null guard, shift-down loop, and current-person cap
// tried delete vs explicit destructor+operator_delete and a tighter count variable; default /GX still lands at 96 bytes for a 97-byte target
// leaving this in scratch because the remaining blocker is a one-byte code-size basin mismatch, not a behavior question
#include "..\..\include\game_types.h"

class RGE_Campaign_Info;

class RGE_Person_Info {
public:
    char name[0x100];
    long current_campaign;
    long campaign_info_num;
    RGE_Campaign_Info** campaign_info;
    long campaign_num;
    void* campaigns;

    ~RGE_Person_Info();
};

class RGE_Game_Info {
public:
    long current_person;
    long people_num;
    RGE_Person_Info** people_info;
    long campaign_num;
    void* campaigns;

    void remove_player(long person_index);
};

extern void __cdecl operator_delete(void* block);

void RGE_Game_Info::remove_player(long person_index) {
    if (person_index < 0 || person_index >= this->people_num) {
        return;
    }

    RGE_Person_Info* person = this->people_info[person_index];
    if (person != 0) {
        delete person;
    }

    long count = this->people_num;
    if (person_index < count - 1) {
        do {
            this->people_info[person_index] = this->people_info[person_index + 1];
            ++person_index;
        } while (person_index < count - 1);
    }

    --count;
    this->people_num = count;
    if (this->current_person == count) {
        this->current_person = count - 1;
    }
}
