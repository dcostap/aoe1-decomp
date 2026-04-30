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
    if (this->player == 0) return;

    long total = this->tot_victory_points;
    int count = 1;

    if (*(unsigned char*)((char*)entry + 0x2D) != 0 && 
        *(unsigned char*)((char*)this->player + 0x104) != 0) {
        short self_id = *(short*)((char*)this->player + 0x4A);
        void* world = *(void**)((char*)this->player + 0x3C);
        int num = *(short*)((char*)world + 0x3C);
        void** players = *(void***)((char*)world + 0x40);

        for (int i = num - 1; i >= 0; i--) {
            if (*(unsigned char*)((char*)this->player + 0x84 + i) == 0) {
                void* p = players[i];
                if (*(unsigned char*)((char*)p + 0x84 + self_id) == 0 && 
                    i != self_id && 
                    *(unsigned char*)((char*)p + 0x104) != 0) {
                    void* vc = *(void**)((char*)p + 0x34);
                    total += get_victory_points(vc);
                    count++;
                }
            }
        }
    }

    if (total / count >= *(long*)((char*)entry + 0x20)) {
        *(unsigned char*)((char*)entry + 0x2E) = 2;
    }
}
