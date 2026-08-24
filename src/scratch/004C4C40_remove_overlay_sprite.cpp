#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
struct Inner_004C4C40 {
    void target(int param);
};

class RGE_Static_Object {
public:
    char gap_0[0x18];
    Inner_004C4C40 *ptr_;
    void remove_overlay_sprite(int param);
};
#endif

void RGE_Static_Object::remove_overlay_sprite(int param) {
    this->ptr_->target(param);
}
