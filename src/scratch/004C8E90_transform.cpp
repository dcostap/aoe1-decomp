class RGE_Sprite;
class RGE_Master_Static_Object;

class TRIBE_Combat_Object {
public:
    void transform(RGE_Master_Static_Object* master);
};

class TRIBE_Master_Building_Object {
public:
    char gap_000[0x15A];
    short building_facet;
    char gap_15C[0xA];
    RGE_Sprite* construction_sprite;
};

class TRIBE_Building_Object {
public:
    char gap_000[0x4];
    RGE_Master_Static_Object* master_obj;
    char gap_00C[0x3C];
    unsigned char built;
    char gap_049[0x193];
    float build_pts;

    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void setConstructionSprite(RGE_Sprite* sprite);

    void transform(TRIBE_Master_Building_Object* master);
};

void TRIBE_Building_Object::transform(TRIBE_Master_Building_Object* master) {
    RGE_Master_Static_Object* master_obj;

    ((TRIBE_Combat_Object*)this)->transform((RGE_Master_Static_Object*)master);
    this->built = 0;
    master_obj = this->master_obj;
    if (master_obj->building_facet > 0) {
        this->setConstructionSprite(master->construction_sprite);
    }
    this->build_pts = 0.0f;
}
