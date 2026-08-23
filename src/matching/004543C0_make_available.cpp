#ifndef RGE_MS_OBJ_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_0[0x4E];
    unsigned char available;
    void make_available(unsigned char v);
};
#endif

void RGE_Master_Static_Object::make_available(unsigned char v) { this->available = v; }
