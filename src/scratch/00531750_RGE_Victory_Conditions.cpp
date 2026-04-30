// RGE_Victory_Conditions::RGE_Victory_Conditions (full constructor)
// VA: 00531750
// victory.cpp

extern "C" void rge_read(int param_1, void* data, int size);
extern "C" void* calloc(unsigned int count, unsigned int size);
extern "C" void* find_by_id(void* list, long id);

class RGE_Victory_Conditions {
public:
    void* vftable;            // +0x00
    void* victory_list_ptr;   // +0x04
    long list_num;            // +0x08
    void* player;             // +0x0C
    unsigned char victory;    // +0x10
    char gap_11[3];
    void* victory_point_list; // +0x14
    long point_list_num;      // +0x18
    long tot_victory_points;  // +0x1C

    RGE_Victory_Conditions(void* player, int param_2, long* param_3, unsigned char param_4);
};

RGE_Victory_Conditions::RGE_Victory_Conditions(void* player, int param_2, long* param_3, unsigned char param_4) {
    this->vftable = (void*)0x00531f30;

    long temp_num;
    if (param_4 == 1) {
        rge_read(param_2, &temp_num, 4);
    } else {
        temp_num = 0;
    }

    rge_read(param_2, &this->list_num, 4);
    rge_read(param_2, &this->victory, 1);

    this->victory_list_ptr = 0;
    this->player = player;

    long count = this->list_num;
    long param_4_val = 0;

    while (param_4_val < count) {
        void* entry = calloc(1, 0x34);

        rge_read(param_2, entry, 1);
        rge_read(param_2, (char*)entry + 4, 4);
        float version;
        rge_read(param_2, &version, 4);
        rge_read(param_2, (char*)entry + 0x0C, 4);
        rge_read(param_2, (char*)entry + 0x10, 4);
        rge_read(param_2, (char*)entry + 0x14, 4);
        rge_read(param_2, (char*)entry + 0x18, 4);
        rge_read(param_2, (char*)entry + 0x1C, 4);
        rge_read(param_2, (char*)entry + 0x20, 4);
        long temp_player;
        rge_read(param_2, &temp_player, 4);
        long temp_obj;
        rge_read(param_2, &temp_obj, 4);
        rge_read(param_2, (char*)entry + 0x2C, 1);
        rge_read(param_2, (char*)entry + 0x2D, 1);
        rge_read(param_2, (char*)entry + 0x2E, 1);

        *(long*)((char*)entry + 0x28) = 0;
        *(long*)((char*)entry + 0x24) = 0;
        *(long*)((char*)entry + 0x08) = 0;

        *(void**)((char*)entry + 0x30) = this->victory_list_ptr;
        this->victory_list_ptr = entry;

        char* players;
        if (temp_player >= 0) {
            void* world = *(void**)((char*)this->player + 0x3C);
            int pnum = *(short*)((char*)world + 0x3C);
            players = *(char**)((char*)world + 0x40);
            for (int j = 0; j < pnum; j++) {
                void* p = *(void**)(players + j * 4);
                void* obj_list = *(void**)((char*)p + 0x28);
                *(void**)((char*)entry + 0x24) = find_by_id(obj_list, temp_player);
                if (*(void**)((char*)entry + 0x24) != 0) break;
                world = *(void**)((char*)this->player + 0x3C);
            }
            if (*(void**)((char*)entry + 0x24) == 0 && temp_player >= 0) {
                *(unsigned char*)((char*)entry + 0x2E) = 3;
            }
        }

        if (temp_obj >= 0) {
            void* obj_list = *(void**)((char*)this->player + 0x28);
            *(void**)((char*)entry + 0x28) = find_by_id(obj_list, temp_obj);
        }

        int version_int = (int)version;
        if (version_int >= 0) {
            if (param_3 != 0) {
                version = (float)param_3[version_int];
            }
            if ((int)version < 0) {
                *(unsigned char*)((char*)entry + 0x2E) = 3;
            } else {
                void* world = *(void**)((char*)this->player + 0x3C);
                char* players2 = *(char**)((char*)world + 0x40);
                void* ref_player = *(void**)(players2 + (int)version * 4);
                *(void**)((char*)entry + 0x08) = ref_player;
                if (ref_player != 0 && *(void**)((char*)entry + 0x28) == 0 && temp_obj >= 0) {
                    void* obj_list = *(void**)((char*)ref_player + 0x28);
                    *(void**)((char*)entry + 0x28) = find_by_id(obj_list, temp_obj);
                }
            }
        } else {
            *(void**)((char*)entry + 0x08) = 0;
        }

        if (temp_obj >= 0 && *(void**)((char*)entry + 0x28) == 0) {
            *(unsigned char*)((char*)entry + 0x2E) = 3;
        }

        param_4_val++;
    }

    this->victory_point_list = 0;
    this->point_list_num = 0;

    if ((float)temp_num < 1.0f) {
        this->tot_victory_points = 0;
    } else {
        rge_read(param_2, &this->tot_victory_points, 4);
        int point_count;
        rge_read(param_2, &point_count, 4);

        long param_4_val2 = 0;
        while (param_4_val2 < point_count) {
            void* point = calloc(1, 0x1c);
            *(unsigned char*)((char*)point + 1) = 0;
            *(long*)((char*)point + 4) = -1;
            *(long*)((char*)point + 8) = 0;
            *(unsigned char*)point = 0xFF;
            *(long*)((char*)point + 0x0C) = 0;
            *(long*)((char*)point + 0x10) = 0;
            *(void**)((char*)point + 0x18) = this->victory_point_list;
            *(unsigned char*)((char*)point + 2) = 0;
            *(unsigned char*)((char*)point + 3) = 0;
            this->victory_point_list = point;
            this->point_list_num++;

            rge_read(param_2, point, 1);
            rge_read(param_2, (char*)point + 1, 1);
            rge_read(param_2, (char*)point + 4, 4);
            rge_read(param_2, (char*)point + 8, 4);
            rge_read(param_2, (char*)point + 0x0C, 4);
            rge_read(param_2, (char*)point + 0x10, 4);
            rge_read(param_2, (char*)point + 2, 1);
            rge_read(param_2, (char*)point + 3, 1);
            rge_read(param_2, (char*)point + 0x14, 4);

            if (this->tot_victory_points < 0) {
                *(long*)((char*)point + 0x0C) = 0;
            }

            param_4_val2++;
        }

        if (this->tot_victory_points < 0) {
            this->tot_victory_points = 0;
        }
    }
}
