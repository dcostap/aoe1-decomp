#ifndef RGE_COM_OBJ_SHARED_CONTEXT
class RGE_Master_Combat_Object {
public:
    virtual ~RGE_Master_Combat_Object();
    char gap_004[0x134];
    float minimum_weapon_range;
};

class RGE_Combat_Object {
public:
    int id;
    RGE_Master_Combat_Object* master_obj;
    virtual float minimumWeaponRange();
};
#endif

float RGE_Combat_Object::minimumWeaponRange() {
    return this->master_obj->minimum_weapon_range;
}
