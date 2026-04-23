extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);

class RGE_Master_Player {
public:
    char gap_00[0x14];
    short master_object_num;
    char gap_1A[0x02];
    void* master_objects;

    virtual void create_master_object_space(short count);
};

void RGE_Master_Player::create_master_object_space(short count) {
    this->master_object_num = count;
    if (count > 0) {
        this->master_objects = calloc((int)count, 4);
    }
}
