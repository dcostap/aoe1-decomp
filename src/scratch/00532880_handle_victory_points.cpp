// RGE_Victory_Conditions::handle_victory_points
// VA: 00532880
// victory.cpp

extern "C" long get_victory_points(void* vc);

class RGE_Victory_Conditions {
public:
    char gap_00[0x0C];
    void* player;              // +0x0C
    char gap_10[0x0C];
    long tot_victory_points;   // +0x1C

    void handle_victory_points(void* entry);
};

void RGE_Victory_Conditions::handle_victory_points(void* entry) {
    long total = this->tot_victory_points;
    int count = 1;

    if (this->player) {
        if (*(unsigned char*)((char*)entry + 0x2D) && 
            *(unsigned char*)((char*)this->player + 0x104)) {
            short self_id = *(short*)((char*)this->player + 0x4A);
            void* w = *(void**)((char*)this->player + 0x3C);
            void** pl = *(void***)((char*)w + 0x40);
            int max_i = *(short*)((char*)w + 0x3C) - 1;
            int i = max_i;
            while (i >= 0) {
                if (*(unsigned char*)((char*)this->player + 0x84 + i) == 0) {
                    void* p = pl[i];
                    if (*(unsigned char*)((char*)p + 0x84 + self_id) == 0 && 
                        i != self_id && 
                        *(unsigned char*)((char*)p + 0x104)) {
                        total += get_victory_points(*(void**)((char*)p + 0x34));
                        count++;
                    }
                }
                i--;
            }
        }
    }

    if (total / count >= *(long*)((char*)entry + 0x20)) {
        *(unsigned char*)((char*)entry + 0x2E) = 2;
    }
}
