#ifndef AOE1_TPNL_OBJ_CONTEXT_H
class TRIBE_Panel_Object {
public:
    virtual ~TRIBE_Panel_Object();
    char gap_0[0x11C];
    unsigned char field_120;
    unsigned char get_mode();
};
#endif

unsigned char TRIBE_Panel_Object::get_mode() {
#ifdef AOE1_TPNL_OBJ_CONTEXT_H
    return this->mode;
#else
    return this->field_120;
#endif
}
