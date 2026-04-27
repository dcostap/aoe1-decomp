// VA: 00470940 modify_tobj_delta (243B)
// player.cpp

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap4[0x20];
    int array24_ptr;    // +24
    int array28_ptr;    // +28
    
    void modify_tobj_delta(short index, int a2, int delta);
};

void RGE_Player::modify_tobj_delta(short index, int a2, int delta) {
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
