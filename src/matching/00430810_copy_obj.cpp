class RGE_Sound;

class RGE_Master_Combat_Object {
public:
    void* vtable_ptr;
    unsigned char gap_04[0xF8];
    RGE_Sound* fight_sprite;
};

class RGE_Action_Object {
public:
    virtual void copy_obj(RGE_Master_Combat_Object* master_obj);
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    int id;
    RGE_Master_Combat_Object* master_obj;
    void* owner;
    RGE_Sound* sprite;

    virtual void slot_04();
    virtual void slot_08();
    virtual void slot_0C();
    virtual void slot_10();
    virtual void slot_14();
    virtual void slot_18();
    virtual void slot_1C();
    virtual void slot_20();
    virtual void slot_24();
    virtual void slot_28();
    virtual void slot_2C();
    virtual void slot_30();
    virtual void slot_34();
    virtual void vf38(RGE_Sound* sound);
    virtual void copy_obj(RGE_Master_Combat_Object* master_obj);
};

void RGE_Combat_Object::copy_obj(RGE_Master_Combat_Object* master_obj) {
    RGE_Sound* sound;

    sound = 0;
    if (sprite == this->master_obj->fight_sprite) {
        sound = master_obj->fight_sprite;
    }
    if (sound != 0) {
        vf38(sound);
    }
    RGE_Action_Object::copy_obj(master_obj);
}
