class RGE_Master_Combat_Object;
class RGE_Player;

class RGE_Combat_Object {
public:
    virtual void vf00(void);
    int setup(RGE_Master_Combat_Object* master_obj, RGE_Player* player, float x, float y, float z);
};

class RGE_Missile_Object : public RGE_Combat_Object {
public:
    char gap_04[0x4A];
    unsigned char field_4E;

    int setup(RGE_Master_Combat_Object* master_obj, RGE_Player* player, float x, float y, float z);
};

int RGE_Missile_Object::setup(RGE_Master_Combat_Object* master_obj, RGE_Player* player, float x, float y, float z) {
    RGE_Combat_Object::setup(master_obj, player, x, y, z);
    this->field_4E = 0x3C;
    return 1;
}
