#ifndef ACT_TRAN_SHARED_CONTEXT
class RGE_Static_Object {
public:
    unsigned char lookupZone(int x, int y);
};

class RGE_Action_Transport {
public:
    char gap_00[0x08];
    RGE_Static_Object* object;
    char gap_0C[0x14];
    float target_x;
    float target_y;

    int targetZone(void);
};
#endif

int RGE_Action_Transport::targetZone(void) {
    if (*(int*)&this->target_x != 0xBF800000) {
        return (int)this->object->lookupZone((int)this->target_x, (int)this->target_y) & 0xFF;
    }
    return -1;
}
