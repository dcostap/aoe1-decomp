// VA: 0046F420 scenario_load (653B)
// player.cpp

class RGE_Player {
public:
    int field_00;
    char gap4[0x80];
    int field_84;
    
    void scenario_load(int fd, int a2);
};

void __cdecl rge_read(int fd, void* buf, int size);
void* __cdecl malloc4(unsigned size);

void RGE_Player::scenario_load(int fd, int a2) {
    rge_read(fd, &a2, 2);
    
    if (a2 > 0) {
        int* arr = (int*)malloc4(4 * a2);
        rge_read(fd, arr, 4 * a2);
        // Use the array
        field_84 = (int)arr;
    }
}
