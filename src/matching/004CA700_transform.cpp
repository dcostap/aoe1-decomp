class RGE_Master_Static_Object;

class RGE_Action_Object {
public:
    virtual void transform(RGE_Master_Static_Object* master);
};

class OwnedMaster {
public:
    virtual void destroy(int value);
};

class TRIBE_Combat_Object : public RGE_Action_Object {
public:
    char gap_04[0x04];
    OwnedMaster* owned_master_ptr;
    char gap_0C[0x1B8];
    unsigned char own_master;

    void transform(RGE_Master_Static_Object* master);
};

void TRIBE_Combat_Object::transform(RGE_Master_Static_Object* master) {
    OwnedMaster* owned_master = this->owned_master_ptr;

    RGE_Action_Object::transform(master);
    if (this->own_master == 1) {
        if (owned_master != 0) {
            owned_master->destroy(1);
        }
        this->own_master = 0;
    }
}
