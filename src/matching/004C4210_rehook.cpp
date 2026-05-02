class RGE_Static_Object {
public:
    virtual void vf00() = 0;
    virtual void vf04() = 0;
    virtual void vf08() = 0;
    virtual void vf0C() = 0;
    virtual void vf10() = 0;
    virtual void vf14() = 0;
    virtual void vf18() = 0;
    virtual void vf1C() = 0;
    virtual void vf20() = 0;
    virtual void vf24() = 0;
    virtual void vf28() = 0;
    virtual void vf2C() = 0;
    virtual void vf30() = 0;
    virtual float vf34(int x, int y, int z) = 0;
    virtual void vf38() = 0;
    virtual void vf3C() = 0;
    virtual void vf40() = 0;
    char gap_04[0x1C];
    RGE_Static_Object* inside_obj;
    char gap_24[0x14];
    int world_x;
    int world_y;
    int world_z;

    virtual void vf44() = 0;  virtual void vf48() = 0;  virtual void vf4C() = 0;
    virtual void vf50() = 0;  virtual void vf54() = 0;  virtual void vf58() = 0;  virtual void vf5C() = 0;
    virtual void vf60() = 0;  virtual void vf64() = 0;  virtual void vf68() = 0;  virtual void vf6C() = 0;
    virtual void vf70() = 0;  virtual void vf74() = 0;  virtual void vf78() = 0;  virtual void vf7C() = 0;
    virtual void vf80() = 0;  virtual void vf84() = 0;  virtual void vf88() = 0;  virtual void vf8C() = 0;
    virtual void vf90() = 0;  virtual void vf94() = 0;  virtual void vf98() = 0;  virtual void vf9C() = 0;
    virtual void vfA0() = 0;  virtual void vfA4() = 0;  virtual void vfA8() = 0;  virtual void vfAC() = 0;
    virtual void vfB0() = 0;  virtual void vfB4() = 0;  virtual void vfB8() = 0;  virtual void vfBC() = 0;
    virtual void vfC0() = 0;  virtual void vfC4() = 0;  virtual void vfC8() = 0;  virtual void vfCC() = 0;
    virtual void vfD0(RGE_Static_Object* obj) = 0;

    void rehook(void);
    RGE_Static_Object* get_object_pointer(long id);
};

void RGE_Static_Object::rehook(void) {
    RGE_Static_Object* obj;

    this->vf34(this->world_x, this->world_y, this->world_z);
    obj = this->inside_obj;
    if (obj != 0) {
        this->inside_obj = 0;
        obj = this->get_object_pointer((long)obj);
        if (obj != 0) {
            this->vfD0(obj);
        }
    }
}
