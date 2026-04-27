// VA: 0044D300 ~RGE_Game_Info
// 165 bytes

void __cdecl free(void*);

struct RGE_Campaign {
    void dtor();
};

struct RGE_Person_Info {
    void dtor();
};

struct RGE_Game_Info {
    int current_person;
    int people_num;
    RGE_Person_Info** people_info;
    int campaign_num;
    RGE_Campaign** campaigns;
    char save_filename[256];

    void save(char* path);
    ~RGE_Game_Info();
};

RGE_Game_Info::~RGE_Game_Info() {
    if (save_filename[0]) {
        save(save_filename);
    }
    if (campaigns) {
        for (int i = 0; i < campaign_num; i++) {
            if (campaigns[i]) {
                delete campaigns[i];
            }
        }
        free(campaigns);
        campaigns = 0;
    }
    if (people_info) {
        for (int i = 0; i < people_num; i++) {
            if (people_info[i]) {
                delete people_info[i];
            }
        }
        free(people_info);
        people_info = 0;
    }
}
