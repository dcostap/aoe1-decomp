extern int rge_open(char* param_1, int param_2, int param_3);
extern int rge_close(int param_1);

class RGE_Game_World {
public:
    void* vtable_ptr;
    char gap_04[0xDC];

    virtual void base_save(char* param_1);
};

typedef void (RGE_Game_World::*BaseSaveFn)(int);

void RGE_Game_World::base_save(char* param_1) {
    int fileHandle = rge_open(param_1, 0x8309, 0x180);
    if (fileHandle != -1) {
        BaseSaveFn fn = *(BaseSaveFn*)((*(char**)this) + 0xE0);
        (this->*fn)(fileHandle);
        rge_close(fileHandle);
    }
}
