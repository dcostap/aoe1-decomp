class RGE_Static_Master_Object {
public:
    char gap_00[4];
    unsigned char master_type;
};

class RGE_Static_Object {
public:
    virtual RGE_Static_Object* spawn_death_obj(void);
    char gap_04[4];
    RGE_Static_Master_Object* master_obj;
};

class RGE_Moving_Object : public RGE_Static_Object {
public:
    char gap_0C[0x90];
    int angle;

    virtual RGE_Static_Object* spawn_death_obj(void);
};

class DeathObject : public RGE_Static_Object {
public:
    virtual int vf00(void);
    virtual int vf04(void);
    virtual int vf08(void);
    virtual int vf0C(void);
    virtual int vf10(void);
    virtual int vf14(void);
    virtual int vf18(void);
    virtual int vf1C(void);
    virtual int vf20(void);
    virtual int vf24(void);
    virtual int vf28(void);
    virtual int vf2C(void);
    virtual int vf30(void);
    virtual int vf34(void);
    virtual int vf38(void);
    virtual int vf3C(void);
    virtual int vf40(void);
    virtual int vf44(void);
    virtual int vf48(void);
    virtual int vf4C(void);
    virtual int vf50(void);
    virtual int vf54(void);
    virtual int vf58(void);
    virtual int vf5C(void);
    virtual int vf60(void);
    virtual int vf64(void);
    virtual int vf68(void);
    virtual int vf6C(void);
    virtual int vf70(void);
    virtual int vf74(void);
    virtual int vf78(void);
    virtual int vf7C(void);
    virtual int vf80(void);
    virtual int vf84(void);
    virtual int vf88(void);
    virtual int vf8C(void);
    virtual int vf90(void);
    virtual int vf94(void);
    virtual int vf98(void);
    virtual int vf9C(void);
    virtual int vfA0(void);
    virtual int vfA4(void);
    virtual int vfA8(void);
    virtual int vfAC(void);
    virtual void set_angle(int angle);
};

RGE_Static_Object* RGE_Moving_Object::spawn_death_obj(void) {
    RGE_Static_Object* obj = RGE_Static_Object::spawn_death_obj();
    if (obj != 0 && obj->master_obj->master_type >= 0x1E) {
        ((DeathObject*)obj)->set_angle(this->angle);
    }
    return obj;
}
