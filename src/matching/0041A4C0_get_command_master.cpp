class RGE_Static_Object;
class RGE_Master_Static_Object;

class RGE_Static_Object {
public:
    virtual RGE_Master_Static_Object * get_command_master(RGE_Static_Object *, float, float, float);
    char gap_04[4];
    RGE_Master_Static_Object *master;
};

RGE_Master_Static_Object * RGE_Static_Object::get_command_master(RGE_Static_Object *a, float b, float c, float d) {
    return this->master;
}
