#ifndef AOE1_TPNL_OBJ_CONTEXT_H
class RGE_Static_Object;
struct tagRECT;

class TRIBE_Panel_Object {
public:
    virtual ~TRIBE_Panel_Object();
    virtual long setup(void*, TRIBE_Panel_Object*, long, long, long, long,
                       unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, TRIBE_Panel_Object*,
                                 TRIBE_Panel_Object*, TRIBE_Panel_Object*,
                                 TRIBE_Panel_Object*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int mode);
    char gap_04[0x110];
    RGE_Static_Object* game_obj;

    void save_object_info();
    void set_object(RGE_Static_Object* object);
};
#endif

void TRIBE_Panel_Object::set_object(RGE_Static_Object* object) {
#ifdef AOE1_TPNL_OBJ_CONTEXT_H
    this->game_obj = (TRIBE_Building_Object*)object;
#else
    this->game_obj = object;
#endif
    save_object_info();
#ifdef AOE1_TPNL_OBJ_CONTEXT_H
    this->set_redraw(1);
#else
    set_redraw(1);
#endif
}
