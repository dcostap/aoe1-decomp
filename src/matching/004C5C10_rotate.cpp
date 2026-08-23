#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Sprite {
public:
    char gap_00[0x60];
    short facet_num;
};

class RGE_Static_Object {
public:
    char gap_00[0x0C];
    RGE_Sprite* sprite;
    char gap_10[0x21];
    unsigned char facet;

    virtual void rotate(long amount);
};

#endif

void RGE_Static_Object::rotate(long amount) {
    int facet_num = (int)this->sprite->facet_num;
    int facet = amount + (unsigned int)this->facet;

    while (facet < 0) {
        facet += facet_num;
    }
    while (facet >= facet_num) {
        facet -= facet_num;
    }
    this->facet = (unsigned char)facet;
}
