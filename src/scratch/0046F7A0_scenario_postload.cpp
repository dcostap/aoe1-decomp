// VA: 0046F7A0 scenario_postload (703B)
// player.cpp

class RGE_Player {
public:
    char gap4[0x40];
    int field_44;
    char gap48[0xBC];
    int field_104;
    
    void scenario_postload(int fd, int a2);
};

void __cdecl rge_read(int fd, void* buf, int size);
void* __cdecl malloc4(unsigned size);

void RGE_Player::scenario_postload(int fd, int a2) {
    rge_read(fd, &a2, 2);
    
    if (a2 > 0) {
        int* arr = (int*)malloc4(4 * a2);
        rge_read(fd, arr, 4 * a2);
        
        // Post-process objects
        field_44 = (int)arr;
    }
}
