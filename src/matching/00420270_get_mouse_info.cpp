struct tagPOINT {
    int x;
    int y;
};

class RGE_Base_Game {
public:
    void get_mouse_info(unsigned int param_1, unsigned long param_2, tagPOINT* param_3, int* param_4, int* param_5, int* param_6, int* param_7);
};

void RGE_Base_Game::get_mouse_info(unsigned int flags, unsigned long lparam, tagPOINT* point, int* lbtn, int* rbtn, int* mbtn, int* wheel) {
    int x = lparam & 0xFFFF;
    int y = lparam >> 0x10;
    point->x = x;
    point->y = y;
    if (60000 < x) {
        point->x = x - 0x10000;
    }
    if (60000 < y) {
        point->y = y - 0x10000;
    }
    *lbtn = flags & 1;
    *rbtn = flags & 2;
    *mbtn = flags & 8;
    *wheel = flags & 4;
}
