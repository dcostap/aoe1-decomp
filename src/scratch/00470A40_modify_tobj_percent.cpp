// VA: 00470A40 modify_tobj_percent (243B)
// player.cpp

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap4[0x20];
    int array24_ptr;
    int array28_ptr;
    
    void modify_tobj_percent(short index, int a2, int pct);
};

void RGE_Player::modify_tobj_percent(short index, int a2, int pct) {
    if (index < 0) return;
    
    int** arr = (int**)array24_ptr;
    if (!arr[index]) return;
    
    int* list = (int*)array28_ptr;
    if (list) {
        int** cur = (int**)list[1];
        if (cur) {
            array24_ptr = (int)cur;
        }
    }
}
