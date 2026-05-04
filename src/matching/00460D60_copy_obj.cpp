// tried the direct nested-if shape; VC5 kept widening the prolog with an extra saved register
// tried collapsing the class to only obj/master pointers and then adding the 0x10 gap, but the entry load order still drifted
// tried the real inheritance/layout surface from the type dumps; this should drive sprite/master accesses from the correct base offsets

class RGE_Master_Static_Object;
class RGE_Sprite;

class RGE_Static_Object {
public:
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
    virtual float teleport(float, float, float);
    virtual void new_sprite(RGE_Sprite* sprite);
    virtual void add_overlay_sprite(RGE_Sprite*, unsigned char);
    virtual void remove_overlay_sprite(RGE_Sprite*);
    virtual void change_ownership(void*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void transform(RGE_Master_Static_Object*);
    virtual void copy_obj(RGE_Master_Static_Object* master_obj);

    int id;
    RGE_Master_Static_Object* master_obj;
    void* owner;
    RGE_Sprite* sprite;
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    float speed;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);

    char gap_04[0xB4];
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed;
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    RGE_Sprite* move_sprite;
    RGE_Sprite* run_sprite;
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    void copy_obj(RGE_Master_Static_Object* master_obj);
};

void RGE_Moving_Object::copy_obj(RGE_Master_Static_Object* master_obj) {
    RGE_Sprite* sprite = 0;
    RGE_Master_Moving_Object* old_master = (RGE_Master_Moving_Object*)this->master_obj;
    RGE_Master_Moving_Object* new_master = (RGE_Master_Moving_Object*)master_obj;

    if (this->sprite == old_master->move_sprite) {
        sprite = new_master->move_sprite;
    } else if (this->sprite == old_master->run_sprite) {
        sprite = new_master->run_sprite;
    }
    if (sprite != 0) {
        this->new_sprite(sprite);
    }
    RGE_Static_Object::copy_obj(master_obj);
}
