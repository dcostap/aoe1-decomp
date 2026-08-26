// VA: 0044D300 ~RGE_Game_Info destructor
// 165 bytes
// BINARY NOTE: gameinfo.cpp lines 512-533 call the campaign and person
// destructors before operator_delete, with seven ordered direct calls.
// Attempt log: dtor calls preserved all bytes but changed two direct targets.
// Explicit destructor declarations and calls restore both targets and give
// MATCH, 0.0000%, with the original 165-byte boundary.  A delete expression
// and undeclared fallback destructors omitted both child calls and failed.

#ifndef GAMEINFO_SHARED_CONTEXT
void __cdecl free(void*);
void __cdecl operator_delete(void* p);

struct RGE_Campaign {
    ~RGE_Campaign();
};

struct RGE_Person_Info {
    ~RGE_Person_Info();
};

struct RGE_Game_Info {
    int current_person;       // +0x00
    int people_num;           // +0x04
    RGE_Person_Info** people_info;  // +0x08
    int campaign_num;         // +0x0C
    RGE_Campaign** campaigns; // +0x10
    char save_filename[256];  // +0x14

    void save(char* path);
    ~RGE_Game_Info();
};
#endif

RGE_Game_Info::~RGE_Game_Info() {
    if (save_filename[0]) {
        save(save_filename);
    }
    if (campaigns) {
        for (int i = 0; i < campaign_num; i++) {
            RGE_Campaign* cp = campaigns[i];
            if (cp) {
                cp->~RGE_Campaign();
                operator_delete(cp);
            }
        }
        free(campaigns);
        campaigns = 0;
    }
    if (people_info) {
        for (int i = 0; i < people_num; i++) {
            RGE_Person_Info* pi = people_info[i];
            if (pi) {
                pi->~RGE_Person_Info();
                operator_delete(pi);
            }
        }
        free(people_info);
        people_info = 0;
    }
}
