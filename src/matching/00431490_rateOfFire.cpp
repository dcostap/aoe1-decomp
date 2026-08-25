#ifndef RGE_COM_OBJ_SHARED_CONTEXT
class RGE_Master_Combat_Object {
public:
    virtual ~RGE_Master_Combat_Object();
    char gap_004[0x11C];
    float speed_of_attack;
};

class RGE_Combat_Object {
public:
    int id;
    RGE_Master_Combat_Object* master_obj;
    virtual float rateOfFire();
};
#endif

float RGE_Combat_Object::rateOfFire() {
    return this->master_obj->speed_of_attack;
}
