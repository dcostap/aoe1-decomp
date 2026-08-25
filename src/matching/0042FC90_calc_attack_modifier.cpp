extern "C" float g_attack_modifier;

#ifndef RGE_COM_OBJ_SHARED_CONTEXT
class RGE_Static_Object;
class RGE_Combat_Object {
public:
    virtual float calc_attack_modifier(RGE_Static_Object*);
};
#endif

float RGE_Combat_Object::calc_attack_modifier(RGE_Static_Object* unused) {
    return g_attack_modifier;
}
