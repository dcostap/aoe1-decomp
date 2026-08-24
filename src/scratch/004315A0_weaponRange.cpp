#ifndef RGE_COM_OBJ_SHARED_CONTEXT
class RGE_Master_Combat_Object {
public:
    virtual ~RGE_Master_Combat_Object();
    char gap_004[0x110];
    float weapon_range;
};

class RGE_Combat_Object {
public:
    int id;
    RGE_Master_Combat_Object* master_obj;
    virtual float weaponRange();
};
#endif

float RGE_Combat_Object::weaponRange() {
    return this->master_obj->weapon_range;
}
