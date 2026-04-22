class RGE_Static_Object;

class TRIBE_Panel_Object {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(int mode);
    char gap_04[0x110];
    RGE_Static_Object* game_obj;

    void save_object_info();
    void set_object(RGE_Static_Object* object);
};

void TRIBE_Panel_Object::set_object(RGE_Static_Object* object) {
    this->game_obj = object;
    save_object_info();
    vf20(1);
}
