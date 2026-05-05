// VA: 0044DA50 RGE_Game_Info::remove_player(long)
// PDB source: gameinfo.cpp lines 777-792 (97 bytes, 44 asm lines)
// Default flags

class RGE_Person_Info {
public:
    ~RGE_Person_Info();
};

class RGE_Game_Info {
public:
    long current_person;    // +0x00
    long people_num;        // +0x04
    RGE_Person_Info** people_info;  // +0x08

    void remove_player(long person_index);
};

extern void __cdecl operator_delete(void* p);

void RGE_Game_Info::remove_player(long person_index) {
    if (person_index < 0) return;
    if (person_index >= people_num) return;

    RGE_Person_Info* person = people_info[person_index];
    if (person != 0) {
        person->~RGE_Person_Info();
        operator_delete(person);
    }

    long idx = person_index;
    long bound = people_num;
    if (idx < bound - 1) {
        do {
            people_info[idx] = people_info[idx + 1];
            idx++;
        } while (idx < people_num - 1);
    }

    people_num--;
    if (current_person == people_num) {
        current_person = people_num - 1;
    }
}
