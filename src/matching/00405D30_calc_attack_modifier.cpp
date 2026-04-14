extern float rge_default_float_00405D30;

class RGE_Static_Object {
public:
    virtual float calc_attack_modifier(RGE_Static_Object *);
};

float RGE_Static_Object::calc_attack_modifier(RGE_Static_Object *a) {
    return rge_default_float_00405D30;
}
